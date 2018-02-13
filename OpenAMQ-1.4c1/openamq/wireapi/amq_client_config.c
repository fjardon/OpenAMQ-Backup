/*---------------------------------------------------------------------------
    amq_client_config.c - amq_client_config component

    Generated from amq_client_config.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "amq_client_config.h"          //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_client_config_t

//  Structure of the amq_client_config object

struct _amq_client_config_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    dbyte
        object_tag;                     //  Object validity marker
Bool
    tcp_nodelay;                    //  TCP/IP NODELAY option
int
    tcp_rcvbuf;                     //  TCP/IP receive buffer, in bytes
int
    tcp_sndbuf;                     //  TCP/IP send buffer, in bytes
int
    high_water;                     //  High water mark for message flow control
int
    low_water;                      //  Low water mark for message flow control
int
    direct;                         //  Enables Direct Mode for connections
int
    batching;                       //  Maximum size of Direct Mode batches
char *
    on_overflow;                    //  Sets action for high-water overflow
int
    sequence_set;                   //  Sequence messages?
int
    sequence_check;                 //  Check message sequencing?
int
    chrono_enabled;                 //  Enable chrono pingbacks?
int
    chrono_floor;                   //  Floor for chrono pingbacks
int
    chrono_density;                 //  Sample density as permille
int
    chrono_batch;                   //  Batch size for chrono pingbacks
    char * filename;                    //  
    ipr_config_t * table;               //  
};

//  Shorthands for class methods

#define self_new            amq_client_config_new
#define self_annihilate     amq_client_config_annihilate
#define self_load_xmlfile   amq_client_config_load_xmlfile
#define self_load_bucket    amq_client_config_load_bucket
#define self_shadow         amq_client_config_shadow
#define self_commit         amq_client_config_commit
#define self_rollback       amq_client_config_rollback
#define self_cmdline_help   amq_client_config_cmdline_help
#define self_cmdline_parse  amq_client_config_cmdline_parse
#define self_options_help   amq_client_config_options_help
#define self_set_tcp_nodelay  amq_client_config_set_tcp_nodelay
#define self_tcp_nodelay    amq_client_config_tcp_nodelay
#define self_set_tcp_rcvbuf  amq_client_config_set_tcp_rcvbuf
#define self_tcp_rcvbuf     amq_client_config_tcp_rcvbuf
#define self_set_tcp_sndbuf  amq_client_config_set_tcp_sndbuf
#define self_tcp_sndbuf     amq_client_config_tcp_sndbuf
#define self_set_high_water  amq_client_config_set_high_water
#define self_high_water     amq_client_config_high_water
#define self_set_low_water  amq_client_config_set_low_water
#define self_low_water      amq_client_config_low_water
#define self_set_direct     amq_client_config_set_direct
#define self_direct         amq_client_config_direct
#define self_set_batching   amq_client_config_set_batching
#define self_batching       amq_client_config_batching
#define self_set_on_overflow  amq_client_config_set_on_overflow
#define self_on_overflow    amq_client_config_on_overflow
#define self_set_sequence_set  amq_client_config_set_sequence_set
#define self_sequence_set   amq_client_config_sequence_set
#define self_set_sequence_check  amq_client_config_set_sequence_check
#define self_sequence_check  amq_client_config_sequence_check
#define self_set_chrono_enabled  amq_client_config_set_chrono_enabled
#define self_chrono_enabled  amq_client_config_chrono_enabled
#define self_set_chrono_floor  amq_client_config_set_chrono_floor
#define self_chrono_floor   amq_client_config_chrono_floor
#define self_set_chrono_density  amq_client_config_set_chrono_density
#define self_chrono_density  amq_client_config_chrono_density
#define self_set_chrono_batch  amq_client_config_set_chrono_batch
#define self_chrono_batch   amq_client_config_chrono_batch
#define self_dump_log       amq_client_config_dump_log
#define self_selftest       amq_client_config_selftest
#define self_filename       amq_client_config_filename
#define self_set_filename   amq_client_config_set_filename
#define self_table          amq_client_config_table
#define self_terminate      amq_client_config_terminate
#define self_show           amq_client_config_show
#define self_destroy        amq_client_config_destroy
#define self_alloc          amq_client_config_alloc
#define self_free           amq_client_config_free
#define self_read_lock      amq_client_config_read_lock
#define self_write_lock     amq_client_config_write_lock
#define self_unlock         amq_client_config_unlock
#define self_cache_initialise  amq_client_config_cache_initialise
#define self_cache_purge    amq_client_config_cache_purge
#define self_cache_terminate  amq_client_config_cache_terminate
#define self_show_animation  amq_client_config_show_animation
#define self_new_in_scope   amq_client_config_new_in_scope

static void
    amq_client_config_annihilate (
amq_client_config_t * ( * self_p )      //  Reference to object reference
);

#define amq_client_config_alloc()       amq_client_config_alloc_ (__FILE__, __LINE__)
static amq_client_config_t *
    amq_client_config_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_client_config_free (
amq_client_config_t * self              //  Object reference
);

static void
    amq_client_config_cache_initialise (
void);

static void
    amq_client_config_cache_purge (
void);

static void
    amq_client_config_cache_terminate (
void);

Bool
    amq_client_config_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static void s_validate_items (amq_client_config_t *self);
static void s_get_properties (amq_client_config_t *self);
amq_client_config_t
    *amq_client_config = NULL;          //  Global properties
static void s_validate_items (amq_client_config_t *self)
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
        && strneq (item_name, "direct")
        && strneq (item_name, "sequence")
        && strneq (item_name, "chrono")
        && strneq (item_name, "server")
        && strneq (item_name, "resources")
        && strneq (item_name, "logging")
        && strneq (item_name, "internal")
        && strneq (item_name, "queue_profile")
        && strneq (item_name, "security"))
            icl_console_print ("W: %s: unknown item '%s', ignored",
                self->filename, item_name);
        ipr_config_next (self->table);
    }
}

static void s_get_properties (amq_client_config_t *self)
{
    char
        *value;                         //  Configured value

    //  All properties on tuning path
    ipr_config_locate (self->table, "/config/tuning", NULL);

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

    //  Get high_water property from config file or built-in defaults
    value = ipr_config_get (self->table, "high_water", NULL);
    if (value)
        self->high_water = (int) atol (value);
    else
        self->high_water = 0;

    //  Get low_water property from config file or built-in defaults
    value = ipr_config_get (self->table, "low_water", NULL);
    if (value)
        self->low_water = (int) atol (value);
    else
        self->low_water = 0;

    //  Get direct property from config file or built-in defaults
    value = ipr_config_get (self->table, "direct", NULL);
    if (value)
        self->direct = (int) atol (value);
    else
        self->direct = 0;

    //  All properties on direct path
    ipr_config_locate (self->table, "/config/direct", NULL);

    //  Get batching property from config file or built-in defaults
    value = ipr_config_get (self->table, "batching", NULL);
    if (value)
        self->batching = (int) atol (value);
    else
        self->batching = 32768;
    if (self->batching > 2097152) {
        icl_console_print ("W: %s: illegal value %d for batching, using %d",
            self->filename, self->batching, 2097152);
        self->batching = 2097152;
    }

    //  Get on_overflow property from config file or built-in defaults
    value = ipr_config_get (self->table, "on_overflow", NULL);
    if (value)
        self->on_overflow = value;
    else
        self->on_overflow = "trim";

    //  All properties on sequence path
    ipr_config_locate (self->table, "/config/sequence", NULL);

    //  Get sequence_set property from config file or built-in defaults
    value = ipr_config_get (self->table, "set", NULL);
    if (value)
        self->sequence_set = (int) atol (value);
    else
        self->sequence_set = 0;

    //  Get sequence_check property from config file or built-in defaults
    value = ipr_config_get (self->table, "check", NULL);
    if (value)
        self->sequence_check = (int) atol (value);
    else
        self->sequence_check = 0;

    //  All properties on chrono path
    ipr_config_locate (self->table, "/config/chrono", NULL);

    //  Get chrono_enabled property from config file or built-in defaults
    value = ipr_config_get (self->table, "enabled", NULL);
    if (value)
        self->chrono_enabled = (int) atol (value);
    else
        self->chrono_enabled = 0;

    //  Get chrono_floor property from config file or built-in defaults
    value = ipr_config_get (self->table, "floor", NULL);
    if (value)
        self->chrono_floor = (int) atol (value);
    else
        self->chrono_floor = 1;

    //  Get chrono_density property from config file or built-in defaults
    value = ipr_config_get (self->table, "density", NULL);
    if (value)
        self->chrono_density = (int) atol (value);
    else
        self->chrono_density = 1;

    //  Get chrono_batch property from config file or built-in defaults
    value = ipr_config_get (self->table, "batch", NULL);
    if (value)
        self->chrono_batch = (int) atol (value);
    else
        self->chrono_batch = 150;

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
}
/*  -------------------------------------------------------------------------
    amq_client_config_new

    Type: Component method
    Creates and initialises a new amq_client_config_t object, returns a
    reference to the created object.
    Creates an empty configuration set.  To fill this, use the load and
    load_bucket methods.
    -------------------------------------------------------------------------
 */

amq_client_config_t *
    amq_client_config_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_client_config_t *
        self = NULL;                    //  Object reference

    self = amq_client_config_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CLIENT_CONFIG_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_client_config_show_);
#endif

//
self->table = ipr_config_new (NULL, FALSE);
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_config_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_config_annihilate (
    amq_client_config_t * ( * self_p )  //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_client_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    AMQ_CLIENT_CONFIG_ASSERT_SANE (self);
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
    amq_client_config_load_xmlfile

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config file into the property set, merging the new loaded data
    with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_load_xmlfile (
    amq_client_config_t * self,         //  Reference to object
    char * filename,                    //  Config file to load
    Bool required                       //  Config file is required?
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

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
    amq_client_config_load_bucket

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config resource (as a bucket) into the property set, merging the
    new loaded data with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_load_bucket (
    amq_client_config_t * self,         //  Reference to object
    ipr_bucket_t * bucket               //  Config data to load
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

//
assert (bucket);
ipr_config_load_bucket (self->table, bucket);
s_validate_items (self);
s_get_properties (self);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_shadow

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads the data from a different property set, and updates all the properties.
    Use this when you want to provide your code with multiple property classes
    that actually contain an identical configuration set.  To use:
    my_config = my_config_new (NULL, NULL, FALSE);
    my_config_shadow (self, your_config->config);
    -------------------------------------------------------------------------
 */

int
    amq_client_config_shadow (
    amq_client_config_t * self,         //  Reference to object
    ipr_config_t * source               //  Config data to shadow
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

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
    amq_client_config_commit

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Saves the current configuration values to the specified file.  If the
    provided filename is null, uses the original config filename. If both
    filenames are null, does nothing.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_commit (
    amq_client_config_t * self,         //  Reference to object
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

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
    amq_client_config_rollback

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Reloads the saved configuration from the saved file, if any.
    Any changes made to the current configuration are lost.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_rollback (
    amq_client_config_t * self          //  Reference to object
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

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
    amq_client_config_cmdline_help

    Type: Component method
    Prints command-line help for setting options from the command
    line.
    -------------------------------------------------------------------------
 */

void
    amq_client_config_cmdline_help (
void)
{

printf ("Options that override config values; these take an argument:\n");
printf ("  --tcp_nodelay    TCP/IP NODELAY option\n");
printf ("  --tcp_rcvbuf     TCP/IP receive buffer, in bytes\n");
printf ("  --tcp_sndbuf     TCP/IP send buffer, in bytes\n");
printf ("  --high_water     High water mark for message flow control\n");
printf ("  --low_water      Low water mark for message flow control\n");
printf ("  --direct         Enables Direct Mode for connections\n");
printf ("  --batching       Maximum size of Direct Mode batches\n");
printf ("  --on_overflow    Sets action for high-water overflow\n");
printf ("  --sequence_set   Sequence messages?\n");
printf ("  --sequence_check  Check message sequencing?\n");
printf ("  --chrono_enabled  Enable chrono pingbacks?\n");
printf ("  --chrono_floor   Floor for chrono pingbacks\n");
printf ("  --chrono_density  Sample density as permille\n");
printf ("  --chrono_batch   Batch size for chrono pingbacks\n");
}
/*  -------------------------------------------------------------------------
    amq_client_config_cmdline_parse

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Parses recognized command-line options starting with --.  Prints an error
    message and exits if the syntax is invalid.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_cmdline_parse (
    amq_client_config_t * self,         //  Reference to object
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

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
            if (streq (arg_name, "--tcp_nodelay"))
                self_set_tcp_nodelay (self, atoi (arg_value));
            else
            if (streq (arg_name, "--tcp_rcvbuf"))
                self_set_tcp_rcvbuf (self, atoi (arg_value));
            else
            if (streq (arg_name, "--tcp_sndbuf"))
                self_set_tcp_sndbuf (self, atoi (arg_value));
            else
            if (streq (arg_name, "--high_water"))
                self_set_high_water (self, atoi (arg_value));
            else
            if (streq (arg_name, "--low_water"))
                self_set_low_water (self, atoi (arg_value));
            else
            if (streq (arg_name, "--direct"))
                self_set_direct (self, atoi (arg_value));
            else
            if (streq (arg_name, "--batching"))
                self_set_batching (self, atoi (arg_value));
            else
            if (streq (arg_name, "--on_overflow"))
                self_set_on_overflow (self, arg_value);
            else
            if (streq (arg_name, "--sequence_set"))
                self_set_sequence_set (self, atoi (arg_value));
            else
            if (streq (arg_name, "--sequence_check"))
                self_set_sequence_check (self, atoi (arg_value));
            else
            if (streq (arg_name, "--chrono_enabled"))
                self_set_chrono_enabled (self, atoi (arg_value));
            else
            if (streq (arg_name, "--chrono_floor"))
                self_set_chrono_floor (self, atoi (arg_value));
            else
            if (streq (arg_name, "--chrono_density"))
                self_set_chrono_density (self, atoi (arg_value));
            else
            if (streq (arg_name, "--chrono_batch"))
                self_set_chrono_batch (self, atoi (arg_value));
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
    amq_client_config_options_help

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Prints full help for all configuration options.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_options_help (
    amq_client_config_t * self,         //  Reference to object
    char * name                         //  Name of application
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

printf ("These are the configured options for %s\n\n", name);

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

printf ("/config/tuning/high_water - High water mark for message flow control\n");
printf ("    From command-line: --high_water newvalue\n");
printf ("    Number of messages in arrived queue when message flow from server is\n");
printf ("    stopped. If this property is 0, message flow is never switched off. \n");
printf ("    Current value is %i. Default value is 0.\n", self->high_water);
printf ("\n");

printf ("/config/tuning/low_water - Low water mark for message flow control\n");
printf ("    From command-line: --low_water newvalue\n");
printf ("    Number of messages in arrived queue when message flow from server is\n");
printf ("    started again after it had been switched off on high water mark.    \n");
printf ("    Current value is %i. Default value is 0.\n", self->low_water);
printf ("\n");

printf ("/config/tuning/direct - Enables Direct Mode for connections\n");
printf ("    From command-line: --direct newvalue\n");
printf ("    If set to 1, new connections will by default use Direct Mode.   \n");
printf ("    Applications can override this by setting the connection->direct\n");
printf ("    property on new connections.                                    \n");
printf ("    Current value is %i. Default value is 0.\n", self->direct);
printf ("\n");

printf ("/config/direct/batching - Maximum size of Direct Mode batches\n");
printf ("    From command-line: --batching newvalue\n");
printf ("    Defines the maximum batch size for Direct Mode opportunistic batching on\n");
printf ("    message sends. Setting this higher will improve throughput, and usually \n");
printf ("    with lower latency, but will cause higher memory consumption. Setting   \n");
printf ("    this to zero will switch off batching. Any value less than 2048 is      \n");
printf ("    treated as zero.                                                        \n");
printf ("    Current value is %i. Default value is 32768.\n", self->batching);
printf ("\n");

printf ("/config/direct/on_overflow - Sets action for high-water overflow\n");
printf ("    From command-line: --on_overflow newvalue\n");
printf ("    Specifies how the WireAPI stack should handle an overflow condition, as\n");
printf ("    defined by the arrived message queue reaching the high-water mark. The \n");
printf ("    allowed actions are: 'warn' - issue a message to the console, 'trim' - \n");
printf ("    discard old messages to make space for new ones, 'drop' - drop new     \n");
printf ("    incoming messages, and 'kill' - assert an error and kill the           \n");
printf ("    application.                                                           \n");
printf ("    Current value is '%s'. Default value is 'trim'\n", self->on_overflow);
printf ("\n");

printf ("/config/sequence/set - Sequence messages?\n");
printf ("    From command-line: --sequence_set newvalue\n");
printf ("    Specifies whether messages are automatically sequenced or not. If set,\n");
printf ("    all published messages are stamped with Sender-Id equal to the        \n");
printf ("    connection Id, and Timestamp equal to the current date and time in the\n");
printf ("    Unix 64-bit time format (microseconds since epoch).                   \n");
printf ("    Current value is %i. Default value is 0.\n", self->sequence_set);
printf ("\n");

printf ("/config/sequence/check - Check message sequencing?\n");
printf ("    From command-line: --sequence_check newvalue\n");
printf ("    Specifies whether message sequencing is checked or not. If set, all    \n");
printf ("    received messages are checked with respect to the sending connection in\n");
printf ("    Sender-Id and Timestamp. Out-of-sequence messages are reported to the  \n");
printf ("    console output.                                                        \n");
printf ("    Current value is %i. Default value is 0.\n", self->sequence_check);
printf ("\n");

printf ("/config/chrono/enabled - Enable chrono pingbacks?\n");
printf ("    From command-line: --chrono_enabled newvalue\n");
printf ("    Specifies whether chrono pingbacks are enabled or not. If not, then any\n");
printf ("    any chrono information in contents will be ignored. By default chrono  \n");
printf ("    pingbacks are not enabled.                                             \n");
printf ("    Current value is %i. Default value is 0.\n", self->chrono_enabled);
printf ("\n");

printf ("/config/chrono/floor - Floor for chrono pingbacks\n");
printf ("    From command-line: --chrono_floor newvalue\n");
printf ("    Specifies the floor for pingbacks, in milliseconds. Only pingbacks that\n");
printf ("    show an end-to-end latency greater or equal to the floor will be       \n");
printf ("    reported. If you set this to zero, all pingbacks will be reported.     \n");
printf ("    Current value is %i. Default value is 1.\n", self->chrono_floor);
printf ("\n");

printf ("/config/chrono/density - Sample density as permille\n");
printf ("    From command-line: --chrono_density newvalue\n");
printf ("    Specifies the sampling density, as a permille. Valid values are 1 to  \n");
printf ("    1000. By default 1/1000th of messages will be sampled. The sampling is\n");
printf ("    randomized if the density is less than 1000 permille.                 \n");
printf ("    Current value is %i. Default value is 1.\n", self->chrono_density);
printf ("\n");

printf ("/config/chrono/batch - Batch size for chrono pingbacks\n");
printf ("    From command-line: --chrono_batch newvalue\n");
printf ("    Specifies the batching size for chrono pingback messages. If you change\n");
printf ("    the floor, density, or batch size, test carefully to ensure you do not \n");
printf ("    create too much chatter due to many small pingbacks. A single pingback \n");
printf ("    is about 15 bytes.                                                     \n");
printf ("    Current value is %i. Default value is 150.\n", self->chrono_batch);
printf ("\n");


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_tcp_nodelay

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_tcp_nodelay (
    amq_client_config_t * self,         //  Reference to object
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

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
    amq_client_config_tcp_nodelay

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_client_config_tcp_nodelay (
    amq_client_config_t * self          //  Reference to self
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
    amq_client_config_set_tcp_rcvbuf

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_tcp_rcvbuf (
    amq_client_config_t * self,         //  Reference to object
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

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
    amq_client_config_tcp_rcvbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_tcp_rcvbuf (
    amq_client_config_t * self          //  Reference to self
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
    amq_client_config_set_tcp_sndbuf

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_tcp_sndbuf (
    amq_client_config_t * self,         //  Reference to object
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

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
    amq_client_config_tcp_sndbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_tcp_sndbuf (
    amq_client_config_t * self          //  Reference to self
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
    amq_client_config_set_high_water

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_high_water (
    amq_client_config_t * self,         //  Reference to object
    int high_water                      //  Not documented
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", high_water);
ipr_config_putp (self->table, "/config/tuning", "high_water", strvalue);
self->high_water = high_water;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_high_water

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_high_water (
    amq_client_config_t * self          //  Reference to self
)
{
    int
        high_water;                     //  Not documented

//
if (self)
    high_water = self->high_water;
else
    high_water = 0;

    return (high_water);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_low_water

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_low_water (
    amq_client_config_t * self,         //  Reference to object
    int low_water                       //  Not documented
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", low_water);
ipr_config_putp (self->table, "/config/tuning", "low_water", strvalue);
self->low_water = low_water;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_low_water

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_low_water (
    amq_client_config_t * self          //  Reference to self
)
{
    int
        low_water;                      //  Not documented

//
if (self)
    low_water = self->low_water;
else
    low_water = 0;

    return (low_water);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_direct

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_direct (
    amq_client_config_t * self,         //  Reference to object
    int direct                          //  Not documented
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", direct);
ipr_config_putp (self->table, "/config/tuning", "direct", strvalue);
self->direct = direct;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_direct

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_direct (
    amq_client_config_t * self          //  Reference to self
)
{
    int
        direct;                         //  Not documented

//
if (self)
    direct = self->direct;
else
    direct = 0;

    return (direct);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_batching

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_batching (
    amq_client_config_t * self,         //  Reference to object
    int batching                        //  Not documented
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

//
if (batching > 2097152) {
    icl_console_print ("W: <command line>: illegal value %d for batching, using %d",
        batching, 2097152);
    batching = 2097152;
}
icl_shortstr_fmt (strvalue, "%i", batching);
ipr_config_putp (self->table, "/config/direct", "batching", strvalue);
self->batching = batching;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_batching

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_batching (
    amq_client_config_t * self          //  Reference to self
)
{
    int
        batching;                       //  Not documented

//
if (self)
    batching = self->batching;
else
    batching = 32768;

    return (batching);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_on_overflow

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_on_overflow (
    amq_client_config_t * self,         //  Reference to object
    char * on_overflow                  //  Not documented
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->table, "/config/direct", "on_overflow", on_overflow);
on_overflow = ipr_config_getp (self->table, "/config/direct", "on_overflow", NULL);
assert (on_overflow);
self->on_overflow = on_overflow;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_on_overflow

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_config_on_overflow (
    amq_client_config_t * self          //  Reference to self
)
{
    char *
        on_overflow;                    //  Not documented

//
if (self)
    on_overflow = self->on_overflow;
else
    on_overflow = "trim";

    return (on_overflow);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_sequence_set

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_sequence_set (
    amq_client_config_t * self,         //  Reference to object
    int sequence_set                    //  Not documented
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", sequence_set);
ipr_config_putp (self->table, "/config/sequence", "set", strvalue);
self->sequence_set = sequence_set;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_sequence_set

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_sequence_set (
    amq_client_config_t * self          //  Reference to self
)
{
    int
        sequence_set;                   //  Not documented

//
if (self)
    sequence_set = self->sequence_set;
else
    sequence_set = 0;

    return (sequence_set);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_sequence_check

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_sequence_check (
    amq_client_config_t * self,         //  Reference to object
    int sequence_check                  //  Not documented
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", sequence_check);
ipr_config_putp (self->table, "/config/sequence", "check", strvalue);
self->sequence_check = sequence_check;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_sequence_check

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_sequence_check (
    amq_client_config_t * self          //  Reference to self
)
{
    int
        sequence_check;                 //  Not documented

//
if (self)
    sequence_check = self->sequence_check;
else
    sequence_check = 0;

    return (sequence_check);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_chrono_enabled

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_chrono_enabled (
    amq_client_config_t * self,         //  Reference to object
    int chrono_enabled                  //  Not documented
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", chrono_enabled);
ipr_config_putp (self->table, "/config/chrono", "enabled", strvalue);
self->chrono_enabled = chrono_enabled;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_chrono_enabled

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_chrono_enabled (
    amq_client_config_t * self          //  Reference to self
)
{
    int
        chrono_enabled;                 //  Not documented

//
if (self)
    chrono_enabled = self->chrono_enabled;
else
    chrono_enabled = 0;

    return (chrono_enabled);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_chrono_floor

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_chrono_floor (
    amq_client_config_t * self,         //  Reference to object
    int chrono_floor                    //  Not documented
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", chrono_floor);
ipr_config_putp (self->table, "/config/chrono", "floor", strvalue);
self->chrono_floor = chrono_floor;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_chrono_floor

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_chrono_floor (
    amq_client_config_t * self          //  Reference to self
)
{
    int
        chrono_floor;                   //  Not documented

//
if (self)
    chrono_floor = self->chrono_floor;
else
    chrono_floor = 1;

    return (chrono_floor);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_chrono_density

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_chrono_density (
    amq_client_config_t * self,         //  Reference to object
    int chrono_density                  //  Not documented
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", chrono_density);
ipr_config_putp (self->table, "/config/chrono", "density", strvalue);
self->chrono_density = chrono_density;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_chrono_density

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_chrono_density (
    amq_client_config_t * self          //  Reference to self
)
{
    int
        chrono_density;                 //  Not documented

//
if (self)
    chrono_density = self->chrono_density;
else
    chrono_density = 1;

    return (chrono_density);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_chrono_batch

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_set_chrono_batch (
    amq_client_config_t * self,         //  Reference to object
    int chrono_batch                    //  Not documented
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

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", chrono_batch);
ipr_config_putp (self->table, "/config/chrono", "batch", strvalue);
self->chrono_batch = chrono_batch;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_chrono_batch

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_config_chrono_batch (
    amq_client_config_t * self          //  Reference to self
)
{
    int
        chrono_batch;                   //  Not documented

//
if (self)
    chrono_batch = self->chrono_batch;
else
    chrono_batch = 150;

    return (chrono_batch);
}
/*  -------------------------------------------------------------------------
    amq_client_config_dump_log

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Dump current option values to an smt_log file.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_dump_log (
    amq_client_config_t * self,         //  Reference to object
    smt_log_t * logfile                 //  Log file to dump to
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

smt_log_print (logfile, "*******************  Configuration Settings  ********************");
smt_log_print (logfile, "tcp_nodelay=%i", self->tcp_nodelay);
smt_log_print (logfile, "tcp_rcvbuf=%i", self->tcp_rcvbuf);
smt_log_print (logfile, "tcp_sndbuf=%i", self->tcp_sndbuf);
smt_log_print (logfile, "high_water=%i", self->high_water);
smt_log_print (logfile, "low_water=%i", self->low_water);
smt_log_print (logfile, "direct=%i", self->direct);
smt_log_print (logfile, "batching=%i", self->batching);
smt_log_print (logfile, "on_overflow=%s", self->on_overflow);
smt_log_print (logfile, "sequence_set=%i", self->sequence_set);
smt_log_print (logfile, "sequence_check=%i", self->sequence_check);
smt_log_print (logfile, "chrono_enabled=%i", self->chrono_enabled);
smt_log_print (logfile, "chrono_floor=%i", self->chrono_floor);
smt_log_print (logfile, "chrono_density=%i", self->chrono_density);
smt_log_print (logfile, "chrono_batch=%i", self->chrono_batch);
smt_log_print (logfile, "");


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_config_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_client_config_filename

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_config_filename (
    amq_client_config_t * self          //  Not documented
)
{
    char *
        filename;                       //  Not documented

filename = self->filename;

    return (filename);
}
/*  -------------------------------------------------------------------------
    amq_client_config_set_filename

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_config_set_filename (
    amq_client_config_t * self,         //  Not documented
    char * filename                     //  Not documented
)
{

icl_mem_free (self->filename);
self->filename = icl_mem_strdup (filename);
}
/*  -------------------------------------------------------------------------
    amq_client_config_table

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_config_t *
    amq_client_config_table (
    amq_client_config_t * self          //  Not documented
)
{
    ipr_config_t *
        table;                          //  Not documented

table = self->table;

    return (table);
}
/*  -------------------------------------------------------------------------
    amq_client_config_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_config_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_client_config_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_config_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_client_config_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_client_config file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_client_config_destroy

    Type: Component method
    Destroys a amq_client_config_t object. Takes the address of a
    amq_client_config_t reference (a pointer to a pointer) and nullifies the
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
    amq_client_config_destroy_ (
    amq_client_config_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_client_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_client_config_annihilate (self_p);
    amq_client_config_free ((amq_client_config_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_client_config_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_client_config_t *
    amq_client_config_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_client_config_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_client_config_cache_initialise ();

self = (amq_client_config_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_client_config_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_config_free

    Type: Component method
    Freess a amq_client_config_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_client_config_free (
    amq_client_config_t * self          //  Object reference
)
{


if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (amq_client_config_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_client_config_t));
        self->object_tag = AMQ_CLIENT_CONFIG_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_client_config_read_lock

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_read_lock (
    amq_client_config_t * self          //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_write_lock

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_write_lock (
    amq_client_config_t * self          //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_unlock

    Type: Component method
    Accepts a amq_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_config_unlock (
    amq_client_config_t * self          //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif



    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_config_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_client_config_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_client_config_t));
icl_system_register (amq_client_config_cache_purge, amq_client_config_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_client_config_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_config_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_client_config_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_config_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_client_config_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_client_config_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_client_config_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_client_config_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_config_new_in_scope_ (
    amq_client_config_t * * self_p,     //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_client_config_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_client_config_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_client_config_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_client_config_component  = "amq_client_config ";
char *EMBED__amq_client_config_version    = "1.0 ";
char *EMBED__amq_client_config_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_client_config_filename   = "amq_client_config.icl ";
char *EMBED__amq_client_config_builddate  = "2010/10/06 ";
char *EMBED__amq_client_config_version_end  = "VeRsIoNeNd:ipc";

