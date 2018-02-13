<?xml?>
<!--
    *** GENERATED FROM amq_peer_config.opf BY opf_gen USING GSL/4 ***

    
    Copyright (c) 1996-2009 iMatix Corporation
    
    This file is licensed under the GPL as follows:
    
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
    name      = "amq_peer_config"
    comment   = "Peer client configuration properties"
    version   = "1.0"
    script    = "icl_gen"
    license   = "gpl"
    opaque    = "1"
    >

<inherit class = "icl_object">
    <option name = "alloc"  value = "cache" />
    <option name = "rwlock" value = "1" />
</inherit>

<import class = "smt_log" />

<public name = "include">
#include "ipr.h"
</public>

<public>
extern $(selftype)
    *amq_peer_config;                  //  Global properties object
</public>

<private>
$(selftype)
    *amq_peer_config = NULL;           //  Global properties
</private>

<context>
    int
        packio;                         //  Pack network data before writing
    Bool
        tcp_nodelay;                    //  TCP/IP NODELAY option
    int
        tcp_rcvbuf;                     //  TCP/IP receive buffer, in bytes
    int
        tcp_sndbuf;                     //  TCP/IP send buffer, in bytes
    <property name = "filename" type = "char *" />
    <property name = "table" type = "ipr_config_t *" readonly = "1" />
</context>

<method name = "new">
    <doc>
    Creates an empty configuration set.  To fill this, use the load and
    load_bucket methods.
    </doc>
    //
    self->table = ipr_config_new (NULL, FALSE);
</method>

<method name = "destroy">
    ipr_config_destroy (&self->table);
</method>

<method name = "load xmlfile" template = "function">
    <doc>
    Loads a config file into the property set, merging the new loaded data
    with any previous data, as defined in ipr_config.icl.
    </doc>
    <argument name = "filename" type = "char *">Config file to load</argument>
    <argument name = "required" type = "Bool">Config file is required?</argument>
    //
    assert (filename);
    if (!ipr_config_load (self->table, filename, required)) {
        self_set_filename (self, filename);
        s_validate_items (self);
        s_get_properties (self);
    }
</method>

<method name = "load bucket" template = "function">
    <doc>
    Loads a config resource (as a bucket) into the property set, merging the
    new loaded data with any previous data, as defined in ipr_config.icl.
    </doc>
    <argument name = "bucket" type = "ipr_bucket_t *">Config data to load</argument>
    //
    assert (bucket);
    ipr_config_load_bucket (self->table, bucket);
    s_validate_items (self);
    s_get_properties (self);
</method>

<method name = "shadow" template = "function">
    <doc>
    Loads the data from a different property set, and updates all the properties.
    Use this when you want to provide your code with multiple property classes
    that actually contain an identical configuration set.  To use:
    my_config = my_config_new (NULL, NULL, FALSE);
    my_config_shadow (self, your_config->config);
    </doc>
    <argument name = "source" type = "ipr_config_t *">Config data to shadow</argument>
    //
    //  Get rid of our own config data
    ipr_config_destroy (&self->table);
    //  Grab a handle onto the source data
    self->table = ipr_config_dup (source);
    //  Update our properties, without validation
    s_get_properties (self);
</method>

<method name = "commit" template = "function">
    <doc>
    Saves the current configuration values to the specified file.  If the
    provided filename is null, uses the original config filename. If both
    filenames are null, does nothing.
    </doc>
    <argument name = "filename" type = "char *">Config file to save</argument>
    <inherit name = "wrlock" />
    //
    if (filename)
        ipr_config_save (self->table, filename);
    else
    if (strused (self->filename))
        ipr_config_save (self->table, self->filename);
</method>

<method name = "rollback" template = "function">
    <doc>
    Reloads the saved configuration from the saved file, if any.
    Any changes made to the current configuration are lost.
    </doc>
    <inherit name = "wrlock" />
    //
    ipr_config_destroy (&self->table);
    self->table = ipr_config_new (self->filename, TRUE);
    s_get_properties (self);
</method>

<method name = "cmdline help">
    <doc>
    Prints command-line help for setting options from the command
    line.
    </doc>
    printf ("Options that override config values; these take an argument:\\n");
    printf ("  --packio         Pack network data before writing\\n");
    printf ("  --tcp_nodelay    TCP/IP NODELAY option\\n");
    printf ("  --tcp_rcvbuf     TCP/IP receive buffer, in bytes\\n");
    printf ("  --tcp_sndbuf     TCP/IP send buffer, in bytes\\n");
</method>

<method name = "cmdline parse" template = "function">
    <doc>
    Parses recognized command-line options starting with --.  Prints an error
    message and exits if the syntax is invalid.
    </doc>
    <argument name = "name" type = "char *">Name of application</argument>
    <argument name = "argc" type = "int">Argument count</argument>
    <argument name = "argv" type = "char **">Argument list</argument>
    <local>
    int
        argn;                           //  Argument number
    char
        *arg_name,
        *arg_value;
    </local>
    //
    argn = 1;
    while (argn < argc) {
        arg_name = argv [argn];
        if (streq (arg_name, "--help")) {
            self_options_help (self, name);
            exit (EXIT_SUCCESS);
        }
        else
        if (ipr_str_prefixed (argv [argn], "--")) {
            argn++;
            if (argn < argc && *argv [argn] != '-') {
                arg_value = argv [argn];
                argn++;

                //  Set property
                if (streq (arg_name, "--packio"))
                    self_set_packio (self, atoi (arg_value));
                else
                if (streq (arg_name, "--tcp_nodelay"))
                    self_set_tcp_nodelay (self, atoi (arg_value));
                else
                if (streq (arg_name, "--tcp_rcvbuf"))
                    self_set_tcp_rcvbuf (self, atoi (arg_value));
                else
                if (streq (arg_name, "--tcp_sndbuf"))
                    self_set_tcp_sndbuf (self, atoi (arg_value));
                else {
                    icl_console_print ("E: unrecognised option '%s'", arg_name);
                    exit (EXIT_FAILURE);
                }
            }
            else {
                icl_console_print ("E: %s option needs a parameter", arg_name);
                exit (EXIT_FAILURE);
            }
        }
        else
            argn++;
    }
    rc = argc;                          //  Return final arg count
</method>

<method name = "options help" template = "function">
    <doc>
    Prints full help for all configuration options.
    </doc>
    <argument name = "name" type = "char *">Name of application</argument>
    printf ("These are the configured options for %s\\n\\n", name);

    printf ("/config/tuning/packio - Pack network data before writing\\n");
    printf ("    From command-line: --packio newvalue\\n");
    printf ("    If set, data is packed into larger buffers before writing. This can    \\n");
    printf ("    improve performance significantly on some systems, especially Windows  \\n");
    printf ("    and Linux with 2.4 kernels. If you enable this setting, you should test\\n");
    printf ("    the performance using a bulk message transfer test. The packio option  \\n");
    printf ("    may cause unexpected behaviour when used with very large messages.     \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->packio);
    printf ("\\n");

    printf ("/config/tuning/tcp_nodelay - TCP/IP NODELAY option\\n");
    printf ("    From command-line: --tcp_nodelay newvalue\\n");
    printf ("    If this value is 1, socket data is written immediately, which is usually\\n");
    printf ("    good for latency. If this value is 0, data is buffered until there is a \\n");
    printf ("    full packet, which is usually good for throughput.                      \\n");
    printf ("    Current value is %i. Default value is 1.\\n", self->tcp_nodelay);
    printf ("\\n");

    printf ("/config/tuning/tcp_rcvbuf - TCP/IP receive buffer, in bytes\\n");
    printf ("    From command-line: --tcp_rcvbuf newvalue\\n");
    printf ("    If this value is greater than zero, the connection to the server will\\n");
    printf ("    use the specified value. Note: setting this value is delicate, do not\\n");
    printf ("    use this option unless you know what you are doing.                  \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->tcp_rcvbuf);
    printf ("\\n");

    printf ("/config/tuning/tcp_sndbuf - TCP/IP send buffer, in bytes\\n");
    printf ("    From command-line: --tcp_sndbuf newvalue\\n");
    printf ("    If this value is greater than zero, the connection to the server will\\n");
    printf ("    use the specified value. Note: setting this value is delicate, do not\\n");
    printf ("    use this option unless you know what you are doing.                  \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->tcp_sndbuf);
    printf ("\\n");
</method>

<method name = "set packio" template = "function">
    <argument name = "packio" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", packio);
    ipr_config_putp (self->table, "/config/tuning", "packio", strvalue);
    self->packio = packio;
</method>

<method name = "packio" return = "packio">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "packio" type = "int" />
    //
    if (self)
        packio = self->packio;
    else
        packio = 0;
</method>

<method name = "set tcp_nodelay" template = "function">
    <argument name = "tcp_nodelay" type = "Bool" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", tcp_nodelay);
    ipr_config_putp (self->table, "/config/tuning", "tcp_nodelay", strvalue);
    self->tcp_nodelay = tcp_nodelay;
</method>

<method name = "tcp_nodelay" return = "tcp_nodelay">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "tcp_nodelay" type = "Bool" />
    //
    if (self)
        tcp_nodelay = self->tcp_nodelay;
    else
        tcp_nodelay = 1;
</method>

<method name = "set tcp_rcvbuf" template = "function">
    <argument name = "tcp_rcvbuf" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", tcp_rcvbuf);
    ipr_config_putp (self->table, "/config/tuning", "tcp_rcvbuf", strvalue);
    self->tcp_rcvbuf = tcp_rcvbuf;
</method>

<method name = "tcp_rcvbuf" return = "tcp_rcvbuf">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "tcp_rcvbuf" type = "int" />
    //
    if (self)
        tcp_rcvbuf = self->tcp_rcvbuf;
    else
        tcp_rcvbuf = 0;
</method>

<method name = "set tcp_sndbuf" template = "function">
    <argument name = "tcp_sndbuf" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", tcp_sndbuf);
    ipr_config_putp (self->table, "/config/tuning", "tcp_sndbuf", strvalue);
    self->tcp_sndbuf = tcp_sndbuf;
</method>

<method name = "tcp_sndbuf" return = "tcp_sndbuf">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "tcp_sndbuf" type = "int" />
    //
    if (self)
        tcp_sndbuf = self->tcp_sndbuf;
    else
        tcp_sndbuf = 0;
</method>

<method name = "dump log" template = "function">
    <doc>
    Dump current option values to an smt_log file.
    </doc>
    <argument name = "logfile" type = "smt_log_t *">Log file to dump to</argument>
    smt_log_print (logfile, "*******************  Configuration Settings  ********************");
    smt_log_print (logfile, "packio=%i", self->packio);
    smt_log_print (logfile, "tcp_nodelay=%i", self->tcp_nodelay);
    smt_log_print (logfile, "tcp_rcvbuf=%i", self->tcp_rcvbuf);
    smt_log_print (logfile, "tcp_sndbuf=%i", self->tcp_sndbuf);
    smt_log_print (logfile, "");
</method>

<private name = "header">
static void s_validate_items ($(selftype) *self);
static void s_get_properties ($(selftype) *self);
</private>

<private name = "body">
static void s_validate_items ($(selftype) *self)
{
    char
        *item_name;

    //  Locate first child and check all items for validity
    ipr_config_locate (self->table, "/config/+", "");
    while (self->table->located) {
        item_name = ipr_config_item (self->table);
        if (streq (item_name, "echo"))
            icl_console_print ("I: %s: %s", self->filename, ipr_config_value (self->table));
        else
        if (strneq (item_name, "tuning")
        && strneq (item_name, "server")
        && strneq (item_name, "resources")
        && strneq (item_name, "logging")
        && strneq (item_name, "internal")
        && strneq (item_name, "queue_profile")
        && strneq (item_name, "security")
        && strneq (item_name, "federation")
        && strneq (item_name, "failover")
        && strneq (item_name, "federate"))
            icl_console_print ("W: %s: unknown item '%s', ignored",
                self->filename, item_name);
        ipr_config_next (self->table);
    }
}

static void s_get_properties ($(selftype) *self)
{
    char
        *value;                         //  Configured value

    //  All properties on tuning path
    ipr_config_locate (self->table, "/config/tuning", NULL);

    //  Get packio property from config file or built-in defaults
    value = ipr_config_get (self->table, "packio", NULL);
    if (value)
        self->packio = (int) atol (value);
    else
        self->packio = 0;

    //  Get tcp_nodelay property from config file or built-in defaults
    value = ipr_config_get (self->table, "tcp_nodelay", NULL);
    if (value)
        self->tcp_nodelay = (Bool) atol (value);
    else
        self->tcp_nodelay = 1;

    //  Get tcp_rcvbuf property from config file or built-in defaults
    value = ipr_config_get (self->table, "tcp_rcvbuf", NULL);
    if (value)
        self->tcp_rcvbuf = (int) atol (value);
    else
        self->tcp_rcvbuf = 0;

    //  Get tcp_sndbuf property from config file or built-in defaults
    value = ipr_config_get (self->table, "tcp_sndbuf", NULL);
    if (value)
        self->tcp_sndbuf = (int) atol (value);
    else
        self->tcp_sndbuf = 0;

    //  All properties on server path
    ipr_config_locate (self->table, "/config/server", NULL);

    //  All properties on resources path
    ipr_config_locate (self->table, "/config/resources", NULL);

    //  All properties on logging path
    ipr_config_locate (self->table, "/config/logging", NULL);

    //  All properties on internal path
    ipr_config_locate (self->table, "/config/internal", NULL);

    //  All properties on queue_profile path
    ipr_config_locate (self->table, "/config/queue_profile", NULL);

    //  All properties on security path
    ipr_config_locate (self->table, "/config/security", NULL);

    //  All properties on federation path
    ipr_config_locate (self->table, "/config/federation", NULL);

    //  All properties on failover path
    ipr_config_locate (self->table, "/config/failover", NULL);

    //  All properties on federate path
    ipr_config_locate (self->table, "/config/federate", NULL);
}
</private>

<method name = "selftest">
</method>

</class>

