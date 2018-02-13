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
    name      = "icl_longstr"
    comment   = "iPR long string class"
    version   = "1.0a1"
    script    = "icl_gen"
    >
<doc>
    We define the icl_longstr_t type in order to provide a secure way of
    storing and serialising long strings.  A "long string" is defined
    as one that can be serialised as a 32-bit length indicator
    plus 0-4Gb-1 octets of data. The icl_longstr_t type is held in memory
    as descriptor consisting of a size field and a data reference.
</doc>

<inherit class = "icl_base" />

<import class = "icl_mem" />

<public name = "header">
#define IPR_LONGSTR(s)     { sizeof(s), (s) }
#define $(selfname:upper)_ALIVE         0xFABB
#define $(selfname:upper)_DEAD          0xDEAD
#define $(selfname:upper)_ASSERT_SANE(self)\\
{\\
    if (!self) {\\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\\
        fprintf (stderr, "Attempting to work with a NULL $(class.name:)\\n");\\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\\n");\\
        fflush (stderr);\\
        abort ();\\
    }\\
    if (self->object_tag != $(selfname:UPPER)_ALIVE) {\\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\\
        fprintf (stderr, "$(class.name:) at %p expected object_tag=0x%x, actual object_tag=0x%x\\n", self, $(selfname:UPPER)_ALIVE, self->object_tag);\\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\\n");\\
        fflush (stderr);\\
        abort ();\\
    }\\
}
</public>

<context>
    qbyte
        object_tag;                     //  Object validity marker

    size_t cur_size;                    //  Current size of data part
    size_t max_size;                    //  Maximum allocated size
    byte  *data;                        //  Data part follows here
</context>

<method name = "new" template = "constructor">
    <doc>
    Allocates an $(selftype) block for a specified block of data.  Returns
    a pointer to an allocated $(selftype), or NULL if there was not enough
    memory. If the data_block argument is not null, its contents are copied
    into the newly allocated memory area.
    </doc>
    <argument name = "data" type = "void *">Data to copy</argument>
    <argument name = "size" type = "size_t">Length of data</argument>
    <header>
    self = ($(selftype) *) icl_mem_alloc_ (sizeof ($(selftype)) + size, file, line);
    if (self) {
        self->object_tag = $(selfname:UPPER)_ALIVE;
        self->max_size = size;
        self->data = (byte *) self + sizeof ($(selftype));
        if (data) {
            self->cur_size = size;
            memcpy (self->data, data, size);
        }
        else
            self->cur_size = 0;
    }
    </header>
</method>

<method name = "destroy" template = "destructor" >
    if (self) {
        //  If data was reallocated independently, free it independently       
        self->object_tag = $(selfname:UPPER)_DEAD;
        if (self->data != (byte *) self + sizeof ($(selftype)))
            icl_mem_free (self->data);
        icl_mem_free (self);
        *self_p = NULL;
    }
</method>

<method name = "resize" template = "function">
    <doc>
    Increases or decreases the allocated size of the string as requested
    by the size argument.  Sets the max_size property to size, and the
    cur_size property to zero.
    </doc>
    <argument name = "size" type = "size_t">New length of data</argument>
    <argument name = "file" type = "char *" precalc = "__FILE__">Source file for call</argument>
    <argument name = "line" type = "size_t" precalc = "__LINE__">Line number for call</argument>
    //  If data was reallocated independently, free it independently           
    if (self->data != (byte *) self + sizeof ($(selftype)))
        icl_mem_free (self->data);

    self->data = icl_mem_alloc_ (size, file, line);
    self->max_size = size;
    self->cur_size = 0;
</method>

<method name = "eq" return = "rc">
    <doc>
    Returns TRUE if the two specified longstrings are equal.  Either
    of the strings may be null references.
    </doc>
    <argument name = "self"   type = "$(selftype) *">First string</argument>
    <argument name = "second" type = "$(selftype) *">String to compare with</argument>
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    //
    if (self == NULL || second == NULL)
        rc = (self == second);
    else {
        $(selfname:upper)_ASSERT_SANE (self);
        $(selfname:upper)_ASSERT_SANE (second);
        if (self->cur_size == second->cur_size
        &&  memcmp (self->data, second->data, self->cur_size) == 0)
            rc = TRUE;
    }
</method>

<method name = "dup" return = "self">
    <doc>
    Returns a new $(selfname) duplicating the supplied string.
    </doc>
    <argument name = "self" type = "$(selftype) *">Source string</argument>
    //
    if (self) {
        $(selfname:upper)_ASSERT_SANE (self);
        self = self_new (self->data, self->cur_size);
    }
    else
        self = NULL;
</method>

<method name = "fmt" template = "function">
    <doc>
    Formats an icl_longstr_t with the specified format and arguments.  If
    the string was too short for the requested output, it is reallocated
    with some elasticity.  Always terminates the longstr data with a null.
    </doc>
    <argument name = "format" type = "char *" >Format specifier</argument>
    <argument name = "args"    type = "..."   >Variable arguments</argument>
    //
    self->cur_size = apr_vsnprintf ((char *) self->data, self->max_size, format, args);
    if (self->cur_size >= self->max_size) {
        self_resize (self, self->cur_size + 128);
        self->cur_size = apr_vsnprintf ((char *) self->data, self->max_size, format, args);
    }
</method>

<method name = "selftest" export = "none">
    icl_longstr_t
        *longstr;

    longstr = icl_longstr_new ("....:....:....:....:", 20);
    icl_longstr_destroy (&longstr);
</method>

</class>
