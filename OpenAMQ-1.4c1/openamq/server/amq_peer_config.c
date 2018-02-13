/*---------------------------------------------------------------------------
    amq_peer_config.c - amq_peer_config component

    Generated from amq_peer_config.icl by icl_gen using GSL/4.
    
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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "amq_peer_config.h"            //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_peer_config_t

//  Structure of the amq_peer_config object

struct _amq_peer_config_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    dbyte
        object_tag;                     //  Object validity marker
int
    packio;                         //  Pack network data before writing
Bool
    tcp_nodelay;                    //  TCP/IP NODELAY option
int
    tcp_rcvbuf;                     //  TCP/IP receive buffer, in bytes
int
    tcp_sndbuf;                     //  TCP/IP send buffer, in bytes
    char * filename;                    //  
    ipr_config_t * table;               //  
};

//  Shorthands for class methods

#define self_new            amq_peer_config_new
#define self_annihilate     amq_peer_config_annihilate
#define self_load_xmlfile   amq_peer_config_load_xmlfile
#define self_load_bucket    amq_peer_config_load_bucket
#define self_shadow         amq_peer_config_shadow
#define self_commit         amq_peer_config_commit
#define self_rollback       amq_peer_config_rollback
#define self_cmdline_help   amq_peer_config_cmdline_help
#define self_cmdline_parse  amq_peer_config_cmdline_parse
#define self_options_help   amq_peer_config_options_help
#define self_set_packio     amq_peer_config_set_packio
#define self_packio         amq_peer_config_packio
#define self_set_tcp_nodelay  amq_peer_config_set_tcp_nodelay
#define self_tcp_nodelay    amq_peer_config_tcp_nodelay
#define self_set_tcp_rcvbuf  amq_peer_config_set_tcp_rcvbuf
#define self_tcp_rcvbuf     amq_peer_config_tcp_rcvbuf
#define self_set_tcp_sndbuf  amq_peer_config_set_tcp_sndbuf
#define self_tcp_sndbuf     amq_peer_config_tcp_sndbuf
#define self_dump_log       amq_peer_config_dump_log
#define self_selftest       amq_peer_config_selftest
#define self_filename       amq_peer_config_filename
#define self_set_filename   amq_peer_config_set_filename
#define self_table          amq_peer_config_table
#define self_terminate      amq_peer_config_terminate
#define self_show           amq_peer_config_show
#define self_destroy        amq_peer_config_destroy
#define self_alloc          amq_peer_config_alloc
#define self_free           amq_peer_config_free
#define self_read_lock      amq_peer_config_read_lock
#define self_write_lock     amq_peer_config_write_lock
#define self_unlock         amq_peer_config_unlock
#define self_cache_initialise  amq_peer_config_cache_initialise
#define self_cache_purge    amq_peer_config_cache_purge
#define self_cache_terminate  amq_peer_config_cache_terminate
#define self_show_animation  amq_peer_config_show_animation
#define self_new_in_scope   amq_peer_config_new_in_scope

static void
    amq_peer_config_annihilate (
amq_peer_config_t * ( * self_p )        //  Reference to object reference
);

#define amq_peer_config_alloc()         amq_peer_config_alloc_ (__FILE__, __LINE__)
static amq_peer_config_t *
    amq_peer_config_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_peer_config_free (
amq_peer_config_t * self                //  Object reference
);

static void
    amq_peer_config_cache_initialise (
void);

static void
    amq_peer_config_cache_purge (
void);

static void
    amq_peer_config_cache_terminate (
void);

Bool
    amq_peer_config_animating = TRUE;   //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static void s_validate_items (amq_peer_config_t *self);
static void s_get_properties (amq_peer_config_t *self);
amq_peer_config_t
    *amq_peer_config = NULL;           //  Global properties
static void s_validate_items (amq_peer_config_t *self)
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

static void s_get_properties (amq_peer_config_t *self)
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
/*  -------------------------------------------------------------------------
    amq_peer_config_new

    Type: Component method
    Creates and initialises a new amq_peer_config_t object, returns a
    reference to the created object.
    Creates an empty configuration set.  To fill this, use the load and
    load_bucket methods.
    -------------------------------------------------------------------------
 */

amq_peer_config_t *
    amq_peer_config_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_peer_config_t *
        self = NULL;                    //  Object reference

    self = amq_peer_config_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_PEER_CONFIG_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_peer_config_show_);
#endif

//
self->table = ipr_config_new (NULL, FALSE);
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_peer_config_annihilate (
    amq_peer_config_t * ( * self_p )    //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_peer_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    AMQ_PEER_CONFIG_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

ipr_config_destroy (&self->table);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

}
/*  -------------------------------------------------------------------------
    amq_peer_config_load_xmlfile

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config file into the property set, merging the new loaded data
    with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_load_xmlfile (
    amq_peer_config_t * self,           //  Reference to object
    char * filename,                    //  Config file to load
    Bool required                       //  Config file is required?
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
assert (filename);
if (!ipr_config_load (self->table, filename, required)) {
    self_set_filename (self, filename);
    s_validate_items (self);
    s_get_properties (self);
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_load_bucket

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config resource (as a bucket) into the property set, merging the
    new loaded data with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_load_bucket (
    amq_peer_config_t * self,           //  Reference to object
    ipr_bucket_t * bucket               //  Config data to load
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
assert (bucket);
ipr_config_load_bucket (self->table, bucket);
s_validate_items (self);
s_get_properties (self);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_shadow

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads the data from a different property set, and updates all the properties.
    Use this when you want to provide your code with multiple property classes
    that actually contain an identical configuration set.  To use:
    my_config = my_config_new (NULL, NULL, FALSE);
    my_config_shadow (self, your_config->config);
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_shadow (
    amq_peer_config_t * self,           //  Reference to object
    ipr_config_t * source               //  Config data to shadow
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
//  Get rid of our own config data
ipr_config_destroy (&self->table);
//  Grab a handle onto the source data
self->table = ipr_config_dup (source);
//  Update our properties, without validation
s_get_properties (self);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_commit

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    Saves the current configuration values to the specified file.  If the
    provided filename is null, uses the original config filename. If both
    filenames are null, does nothing.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_commit (
    amq_peer_config_t * self,           //  Reference to object
    char * filename                     //  Config file to save
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
if (filename)
    ipr_config_save (self->table, filename);
else
if (strused (self->filename))
    ipr_config_save (self->table, self->filename);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_rollback

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    Reloads the saved configuration from the saved file, if any.
    Any changes made to the current configuration are lost.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_rollback (
    amq_peer_config_t * self            //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
ipr_config_destroy (&self->table);
self->table = ipr_config_new (self->filename, TRUE);
s_get_properties (self);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_cmdline_help

    Type: Component method
    Prints command-line help for setting options from the command
    line.
    -------------------------------------------------------------------------
 */

void
    amq_peer_config_cmdline_help (
void)
{

printf ("Options that override config values; these take an argument:\n");
printf ("  --packio         Pack network data before writing\n");
printf ("  --tcp_nodelay    TCP/IP NODELAY option\n");
printf ("  --tcp_rcvbuf     TCP/IP receive buffer, in bytes\n");
printf ("  --tcp_sndbuf     TCP/IP send buffer, in bytes\n");
}
/*  -------------------------------------------------------------------------
    amq_peer_config_cmdline_parse

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    Parses recognized command-line options starting with --.  Prints an error
    message and exits if the syntax is invalid.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_cmdline_parse (
    amq_peer_config_t * self,           //  Reference to object
    char * name,                        //  Name of application
    int argc,                           //  Argument count
    char ** argv                        //  Argument list
)
{
int
    argn;                           //  Argument number
char
    *arg_name,
    *arg_value;
    int
        rc = 0;                         //  Return code

AMQ_PEER_CONFIG_ASSERT_SANE (self);

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


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_options_help

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    Prints full help for all configuration options.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_options_help (
    amq_peer_config_t * self,           //  Reference to object
    char * name                         //  Name of application
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEER_CONFIG_ASSERT_SANE (self);

printf ("These are the configured options for %s\n\n", name);

printf ("/config/tuning/packio - Pack network data before writing\n");
printf ("    From command-line: --packio newvalue\n");
printf ("    If set, data is packed into larger buffers before writing. This can    \n");
printf ("    improve performance significantly on some systems, especially Windows  \n");
printf ("    and Linux with 2.4 kernels. If you enable this setting, you should test\n");
printf ("    the performance using a bulk message transfer test. The packio option  \n");
printf ("    may cause unexpected behaviour when used with very large messages.     \n");
printf ("    Current value is %i. Default value is 0.\n", self->packio);
printf ("\n");

printf ("/config/tuning/tcp_nodelay - TCP/IP NODELAY option\n");
printf ("    From command-line: --tcp_nodelay newvalue\n");
printf ("    If this value is 1, socket data is written immediately, which is usually\n");
printf ("    good for latency. If this value is 0, data is buffered until there is a \n");
printf ("    full packet, which is usually good for throughput.                      \n");
printf ("    Current value is %i. Default value is 1.\n", self->tcp_nodelay);
printf ("\n");

printf ("/config/tuning/tcp_rcvbuf - TCP/IP receive buffer, in bytes\n");
printf ("    From command-line: --tcp_rcvbuf newvalue\n");
printf ("    If this value is greater than zero, the connection to the server will\n");
printf ("    use the specified value. Note: setting this value is delicate, do not\n");
printf ("    use this option unless you know what you are doing.                  \n");
printf ("    Current value is %i. Default value is 0.\n", self->tcp_rcvbuf);
printf ("\n");

printf ("/config/tuning/tcp_sndbuf - TCP/IP send buffer, in bytes\n");
printf ("    From command-line: --tcp_sndbuf newvalue\n");
printf ("    If this value is greater than zero, the connection to the server will\n");
printf ("    use the specified value. Note: setting this value is delicate, do not\n");
printf ("    use this option unless you know what you are doing.                  \n");
printf ("    Current value is %i. Default value is 0.\n", self->tcp_sndbuf);
printf ("\n");


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_set_packio

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_set_packio (
    amq_peer_config_t * self,           //  Reference to object
    int packio                          //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", packio);
ipr_config_putp (self->table, "/config/tuning", "packio", strvalue);
self->packio = packio;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_packio

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_packio (
    amq_peer_config_t * self            //  Reference to self
)
{
    int
        packio;                         //  Not documented

//
if (self)
    packio = self->packio;
else
    packio = 0;

    return (packio);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_set_tcp_nodelay

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_set_tcp_nodelay (
    amq_peer_config_t * self,           //  Reference to object
    Bool tcp_nodelay                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_nodelay);
ipr_config_putp (self->table, "/config/tuning", "tcp_nodelay", strvalue);
self->tcp_nodelay = tcp_nodelay;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_tcp_nodelay

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_peer_config_tcp_nodelay (
    amq_peer_config_t * self            //  Reference to self
)
{
    Bool
        tcp_nodelay;                    //  Not documented

//
if (self)
    tcp_nodelay = self->tcp_nodelay;
else
    tcp_nodelay = 1;

    return (tcp_nodelay);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_set_tcp_rcvbuf

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_set_tcp_rcvbuf (
    amq_peer_config_t * self,           //  Reference to object
    int tcp_rcvbuf                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_rcvbuf);
ipr_config_putp (self->table, "/config/tuning", "tcp_rcvbuf", strvalue);
self->tcp_rcvbuf = tcp_rcvbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_tcp_rcvbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_tcp_rcvbuf (
    amq_peer_config_t * self            //  Reference to self
)
{
    int
        tcp_rcvbuf;                     //  Not documented

//
if (self)
    tcp_rcvbuf = self->tcp_rcvbuf;
else
    tcp_rcvbuf = 0;

    return (tcp_rcvbuf);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_set_tcp_sndbuf

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_set_tcp_sndbuf (
    amq_peer_config_t * self,           //  Reference to object
    int tcp_sndbuf                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_sndbuf);
ipr_config_putp (self->table, "/config/tuning", "tcp_sndbuf", strvalue);
self->tcp_sndbuf = tcp_sndbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_tcp_sndbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_tcp_sndbuf (
    amq_peer_config_t * self            //  Reference to self
)
{
    int
        tcp_sndbuf;                     //  Not documented

//
if (self)
    tcp_sndbuf = self->tcp_sndbuf;
else
    tcp_sndbuf = 0;

    return (tcp_sndbuf);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_dump_log

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    Dump current option values to an smt_log file.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_dump_log (
    amq_peer_config_t * self,           //  Reference to object
    smt_log_t * logfile                 //  Log file to dump to
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEER_CONFIG_ASSERT_SANE (self);

smt_log_print (logfile, "*******************  Configuration Settings  ********************");
smt_log_print (logfile, "packio=%i", self->packio);
smt_log_print (logfile, "tcp_nodelay=%i", self->tcp_nodelay);
smt_log_print (logfile, "tcp_rcvbuf=%i", self->tcp_rcvbuf);
smt_log_print (logfile, "tcp_sndbuf=%i", self->tcp_sndbuf);
smt_log_print (logfile, "");


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_peer_config_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_peer_config_filename

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_peer_config_filename (
    amq_peer_config_t * self            //  Not documented
)
{
    char *
        filename;                       //  Not documented

filename = self->filename;

    return (filename);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_set_filename

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_peer_config_set_filename (
    amq_peer_config_t * self,           //  Not documented
    char * filename                     //  Not documented
)
{

icl_mem_free (self->filename);
self->filename = icl_mem_strdup (filename);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_table

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_config_t *
    amq_peer_config_table (
    amq_peer_config_t * self            //  Not documented
)
{
    ipr_config_t *
        table;                          //  Not documented

table = self->table;

    return (table);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_peer_config_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_peer_config_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_peer_config_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_peer_config_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_peer_config file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_peer_config_destroy

    Type: Component method
    Destroys a amq_peer_config_t object. Takes the address of a
    amq_peer_config_t reference (a pointer to a pointer) and nullifies the
    reference after use.  Does nothing if the reference is already
    null.
    Performs an agressive destroy of an object.  This involves:
    1. Removing the object from any containers it is in.
    2. Making the object an zombie
    3. Decrementing the object's link count
    4. If the link count is zero then freeing the object.
    -------------------------------------------------------------------------
 */

void
    amq_peer_config_destroy_ (
    amq_peer_config_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_peer_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_peer_config_annihilate (self_p);
    amq_peer_config_free ((amq_peer_config_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_peer_config_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_peer_config_t *
    amq_peer_config_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_peer_config_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_peer_config_cache_initialise ();

self = (amq_peer_config_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_peer_config_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_free

    Type: Component method
    Freess a amq_peer_config_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_peer_config_free (
    amq_peer_config_t * self            //  Object reference
)
{


if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (amq_peer_config_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_peer_config_t));
        self->object_tag = AMQ_PEER_CONFIG_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_peer_config_read_lock

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_read_lock (
    amq_peer_config_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEER_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_write_lock

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_write_lock (
    amq_peer_config_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEER_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_unlock

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_peer_config_unlock (
    amq_peer_config_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEER_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif



    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_peer_config_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_peer_config_t));
icl_system_register (amq_peer_config_cache_purge, amq_peer_config_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_peer_config_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_peer_config_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_peer_config_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_peer_config_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_peer_config_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_peer_config_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_peer_config_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_peer_config_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_peer_config_new_in_scope_ (
    amq_peer_config_t * * self_p,       //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_peer_config_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_peer_config_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_peer_config_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_peer_config_component    = "amq_peer_config ";
char *EMBED__amq_peer_config_version      = "1.0 ";
char *EMBED__amq_peer_config_copyright    = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_peer_config_filename     = "amq_peer_config.icl ";
char *EMBED__amq_peer_config_builddate    = "2010/10/06 ";
char *EMBED__amq_peer_config_version_end  = "VeRsIoNeNd:ipc";

