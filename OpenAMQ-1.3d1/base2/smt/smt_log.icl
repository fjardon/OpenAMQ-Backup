<?xml?>
<!--
    Copyright (c) 1996-2009 iMatix Corporation

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at
    your option) any later version.

    This program is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    For information on alternative licensing for OEMs, please contact
    iMatix Corporation.
 -->
<class
    name      = "smt_log"
    comment   = "Log file management class"
    version   = "1.0"
    script    = "smt_object_gen"
    target    = "smt"
    >
<doc>
    Defines a log. This is a lock-free asynchronous class.
</doc>

<inherit class = "smt_object" />

<import class = "smt" />

<public name = "header">
#define SMT_LOG_LINEMAX  2047
</public>

<context>
    icl_shortstr_t
        filename,                       //  Full filename
        log_path,                       //  Log path
        archive_path,                   //  Archive path
        cycle_cmd;                      //  Cycle command
    FILE
        *output;                        //  Output file stream
    Bool
        pedantic;                       //  Copy & flush to stderr?
    $(selftype)
        *copy_to;                       //  CC log file
</context>

<method name = "new">
</method>

<method name = "destroy">
    <action>
    if (self->output) {
        fflush (self->output);
        fclose (self->output);
    }
    </action>
</method>

<method name = "open" template = "async function" async = "1">
    <doc>
    Opens the log file output stream, so that data is written to disk.
    If you do not open the log file, data sent to it will be thrown
    away.
    </doc>
    <argument name = "filename"     type = "char *">Log filename</argument>
    <argument name = "log path"     type = "char *">Log path name</argument>
    <argument name = "archive path" type = "char *">Archive path name</argument>
    <argument name = "cycle cmd"    type = "char *">Cycle command</argument>
    //
    <possess>
    filename = icl_mem_strdup (filename);
    log_path = icl_mem_strdup (log_path);
    archive_path = icl_mem_strdup (archive_path);
    cycle_cmd = icl_mem_strdup (cycle_cmd);
    </possess>
    <release>
    icl_mem_free (filename);
    icl_mem_free (log_path);
    icl_mem_free (archive_path);
    icl_mem_free (cycle_cmd);
    </release>
    //
    <action>
    icl_shortstr_cpy (self->filename,     filename);
    icl_shortstr_cpy (self->log_path,     log_path);
    icl_shortstr_cpy (self->archive_path, archive_path);
    icl_shortstr_cpy (self->cycle_cmd,    cycle_cmd);

    //  Ensure that logging directories exist
    if (*self->log_path && !ipr_file_is_directory (self->log_path))
        ipr_dir_create (self->log_path);
        
    if (*self->archive_path && !ipr_file_is_directory (self->archive_path))
        ipr_dir_create (self->archive_path);

    ipr_file_set_path (self->filename, self->log_path);

    //  Archive the previous log file if exists
    ipr_log_cycle (self->filename, self->archive_path, self->cycle_cmd);
    self->output = fopen (self->filename, "w");
    if (!self->output)
        icl_console_print ("E: can't open %s: %s", self->filename, strerror (errno));
    </action>
</method>

<method name = "close" template = "async function" async = "1">
    <doc>
    Closes the log file output, if any.
    </doc>
    //
    <action>
    if (self->output) {
        fflush (self->output);
        fclose (self->output);
        self->output = NULL;
    }
    </action>
</method>

<method name = "set cc" template = "function">
    <doc>
    Set a copy-to log file.  All data printed to the current log file
    will also be sent to the cc log file, in an identical format.  If
    null, the copy-to functionality for this log file is disabled.  Not
    threadsafe; this method should not be called from multiple threads
    at once. It is implemented as a synchronous method so that it takes
    effect immediately.
    </doc>
    <argument name = "copy to" type = "$(selftype) *">Copy to logfile</argument>
    //
    self->copy_to = copy_to;
</method>

<method name = "pedantic" template = "function">
    <doc>
    Set the pedantic option, in which all data sent to the log file
    will also be copied to the standard error stream, and flushed. This
    is most useful for errors and traces, where you don't want to lose
    cached output if the application ends unexpectedly.  Not threadsafe;
    this method should not be called from multiple threads at once. It
    is implemented as a synchronous method so that it takes effect
    immediately.
    </doc>
    <argument name = "option" type = "Bool">Pedantic option</argument>
    //
    self->pedantic = option;
</method>

<method name = "print">
    <doc>
    Writes a line of text to the log file, formatting the string
    using the provided format and arguments. The string is prefixed
    by the current date and time.  The log file object can be null,
    in which case this method does nothing.
    </doc>
    <argument name = "self" type = "$(selftype) *">Log file object</argument>
    <argument name = "format" type = "char *">Format specifier</argument>
    <argument name = "args" type = "...">Variable arguments</argument>
    <local>
    apr_time_exp_t
        time_exp;
    apr_size_t
        fmtsize;                        //  Size of formatted string
    ipr_bucket_t
        *bucket;                        //  Bucket to write
    </local>
    //
    if (self) {
        bucket = ipr_bucket_new (SMT_LOG_LINEMAX + 1);
        apr_time_exp_lt (&time_exp, apr_time_now ());
        apr_strftime ((char *) (bucket->data), &fmtsize, SMT_LOG_LINEMAX, "%Y-%m-%d %T: ", &time_exp);
        apr_vsnprintf ((char *) (bucket->data) + strlen ((char *) (bucket->data)),
            SMT_LOG_LINEMAX - strlen ((char *) (bucket->data)), format, args);
        if (self->pedantic) {
            //  Always printf into %s to guard against %'s in data
            fprintf (stderr, "%s", (char *) (bucket->data));
            fprintf (stderr, "\\n");
            fflush  (stderr);
        }
        smt_log_write_bucket (self, bucket);
        if (self->copy_to)
            smt_log_write_bucket (self->copy_to, bucket);
        ipr_bucket_unlink (&bucket);
    }
</method>

<method name = "write bucket" template = "async function" async = "1">
    <doc>
    Writes a bucket of text to the log file.  The text is not modified or
    prefixed in any way.  Does not flush the log file, so if the server
    is halted abruptly, logging data may be lost.  The bucket text must
    be null-terminated correctly.
    </doc>
    <argument name = "bucket" type = "ipr_bucket_t *">Bucket data to print</argument>
    <possess>
    bucket = ipr_bucket_link (bucket);
    </possess>
    <release>
    ipr_bucket_unlink (&bucket);
    </release>
    //
    <action>
    if (self->output) {
        //  Always printf into %s to guard against %'s in data
        fprintf (self->output, "%s", (char *) (bucket->data));
        fprintf (self->output, "\\n");
    }
    </action>
</method>

<method name = "cycle" template = "async function" async = "1">
    <doc>
    Archives the log file explicitly.
    </doc>
    <action>
    if (self->output) {
        fflush (self->output);
        fclose (self->output);
    }
    //  Archive the previous log file if exists
    ipr_log_cycle (self->filename, self->archive_path, self->cycle_cmd);
    self->output = fopen (self->filename, "w");
    if (!self->output)
        icl_console_print ("E: can't open %s: %s", self->filename, strerror (errno));
    </action>
</method>

<method name = "dump" template = "function">
    <doc>
    Prints the contents of a bucket to the specified log file.  Filters
    unprintable characters.  Does not apply any specific formatting.
    </doc>
    <argument name = "bucket" type = "ipr_bucket_t *">Bucket to dump</argument>
    <argument name = "prefix" type = "char *">Prefix for each line</argument>
    <local>
#   define BYTES_PER_LINE   (16)
    static const char
        *hex_digit = "0123456789abcdef";
    size_t
        size = bucket->cur_size,
        count,
        repeat_count = 0;
    byte
        *ucbuffer = bucket->data,
        cur_byte;
    char
        last_buffer [(BYTES_PER_LINE * 2) + 1],
        hex_buffer  [(BYTES_PER_LINE * 2) + 1],
        text_buffer [ BYTES_PER_LINE + 1],
        *hex,
        *text;
    int
        remainder;
    </local>
    //
    memset (last_buffer, 0, sizeof (last_buffer));
    while (size > 0) {
        hex       = hex_buffer;
        text      = text_buffer;
        count     = BYTES_PER_LINE;
        remainder = BYTES_PER_LINE - size;
        while (size > 0 && count > 0) {
            size--;
            count--;
            cur_byte = *ucbuffer;

            //  Is current byte a printable character?
            *text++ = (cur_byte < 32 || cur_byte > 127) ? '.' : cur_byte;
            *hex++  = hex_digit [cur_byte >> 4];
            *hex++  = hex_digit [cur_byte & 0x0f];
            ucbuffer++;
        }
        while (remainder > 0) {
            *hex++ = ' ';
            *hex++ = ' ';
            remainder--;
        }
        *hex = '\\0';
        *text = '\\0';
        if (memcmp (last_buffer, hex_buffer, sizeof (last_buffer)) == 0)
            repeat_count++;
        else {
            if (repeat_count) {
                self_print (self, "%s[repeated %d times]", prefix, repeat_count);
                repeat_count = 0;
            }
            self_print (self, "%s%s | %s", prefix, hex_buffer, text_buffer);
            memcpy (last_buffer, hex_buffer, sizeof (last_buffer));
        }
    }
    if (repeat_count)
        self_print (self, "%s[repeated %d times]", prefix, repeat_count);
</method>

<method name = "dump env" template = "function">
    <doc>
    Prints the current environment to the log file.
    </doc>
    <local>
    int
        string_nbr;                     //  Index into string table
    </local>
    //
    self_print (self, "****************  Process Environment Variables  ****************");
    for (string_nbr = 0; environ [string_nbr]; string_nbr++)
        self_print (self, "%s", environ [string_nbr]);
    self_print (self, "");
</method>

<method name = "selftest" />

</class>

