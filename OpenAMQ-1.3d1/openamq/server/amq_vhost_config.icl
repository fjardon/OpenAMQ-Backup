<?xml?>
<!--
    *** GENERATED FROM amq_vhost_config.opf BY opf_gen USING GSL/4 ***

    
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
    name      = "amq_vhost_config"
    comment   = "Virtual host configuration properties"
    version   = "1.0"
    script    = "icl_gen"
    license   = "gpl"
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
</public>

<private>
</private>

<context>
    ipr_config_t *
        config;                         //  Configuration table
    icl_shortstr_t
        filename;                       //  Configuration file name
    char *
        name;                           //  Virtual host name
</context>

<method name = "new">
    <doc>
    Creates an empty configuration set.  To fill this, use the load and
    load_bucket methods.
    </doc>
    //
    self->config = ipr_config_new (NULL, FALSE);
</method>

<method name = "destroy">
    ipr_config_destroy (&self->config);
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
    if (!ipr_config_load (self->config, filename, required)) {
        icl_shortstr_cpy (self->filename, filename);
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
    ipr_config_load_bucket (self->config, bucket);
    s_validate_items (self);
    s_get_properties (self);
</method>

<method name = "commit" template = "function">
    <argument name = "filename" type = "char *">Config file to save</argument>
    <doc>
    Saves the current configuration values to the specified file.  If the
    provided filename is null, uses the original config filename. If both
    filenames are null, does nothing.
    </doc>
    <inherit name = "wrlock" />
    //
    if (filename)
        ipr_config_save (self->config, filename);
    else
    if (strused (self->filename))
        ipr_config_save (self->config, self->filename);
</method>

<method name = "rollback" template = "function">
    <doc>
    Reloads the saved configuration from the saved file, if any.
    Any changes made to the current configuration are lost.
    </doc>
    <inherit name = "wrlock" />
    //
    ipr_config_destroy (&self->config);
    self->config = ipr_config_new (self->filename, TRUE);
    s_get_properties (self);
</method>

<method name = "cmdline help">
    <doc>
    Prints command-line help for setting options from the command
    line.
    </doc>
    printf ("Options that override config values; these take an argument:\\n");
    printf ("  --name           Virtual host name\\n");
</method>

<method name = "cmdline parse" template = "function">
    <doc>
    Parses recognized command-line options and processes, starting
    with --, prints an error message and exits if the syntax is invalid.
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
                if (streq (arg_name, "--name"))
                    self_set_name (self, arg_value);
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
    printf ("\\nThese are the configured options for %s\\n\\n", name);

    printf ("/config/vhost/name - Virtual host name\\n");
    printf ("    From command-line: --name newvalue\\n");
    printf ("    \\n");
    printf ("    Current value is '%s'.\\n", self->name);
    printf ("\\n");
</method>

<method name = "set name" template = "function">
    <argument name = "name" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->config, "/config/vhost", "name", name);
    name = ipr_config_getp (self->config, "/config/vhost", "name", NULL);
    assert (name);
    self->name = name;
</method>

<method name = "name" return = "name">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "name" type = "char *" />
    //
    if (self)
        name = self->name;
    else
        name = "";
</method>

<method name = "dump log" template = "function">
    <doc>
    Dump current option values to an smt_log file.
    </doc>
    <argument name = "logfile" type = "smt_log_t *">Log file to dump to</argument>
    smt_log_print (logfile, "*******************  Configuration Settings  ********************");
    smt_log_print (logfile, "name=%s", self->name);
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
    ipr_config_locate (self->config, "/config/+", "");
    while (self->config->located) {
        item_name = ipr_config_item (self->config);
        if (streq (item_name, "echo"))
            icl_console_print ("I: %s: %s", self->filename, ipr_config_value (self->config));
        else
        if (strneq (item_name, "vhost"))
            icl_console_print ("W: %s: unknown item '%s', ignored",
                self->filename, item_name);
        ipr_config_next (self->config);
    }
}

static void s_get_properties ($(selftype) *self)
{
    char
        *value;                         //  Configured value

    //  All properties on vhost path
    ipr_config_locate (self->config, "/config/vhost", NULL);

    //  Get name property from config file or built-in defaults
    value = ipr_config_get (self->config, "name", NULL);
    if (value)
        self->name = value;
    else
        self->name = "";
}
</private>

<method name = "selftest">
</method>

</class>

