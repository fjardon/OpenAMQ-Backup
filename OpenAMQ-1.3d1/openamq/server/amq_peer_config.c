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

//  Shorthands for class methods                                               

#define self_new            amq_peer_config_new
#define self_annihilate     amq_peer_config_annihilate
#define self_load_xmlfile   amq_peer_config_load_xmlfile
#define self_load_bucket    amq_peer_config_load_bucket
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
#define self_animate        amq_peer_config_animate
#define self_new_in_scope   amq_peer_config_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_NEW))
static icl_stats_t *s_amq_peer_config_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_DESTROY))
static icl_stats_t *s_amq_peer_config_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_LOAD_XMLFILE))
static icl_stats_t *s_amq_peer_config_load_xmlfile_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_LOAD_BUCKET))
static icl_stats_t *s_amq_peer_config_load_bucket_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_COMMIT))
static icl_stats_t *s_amq_peer_config_commit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_ROLLBACK))
static icl_stats_t *s_amq_peer_config_rollback_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_CMDLINE_HELP))
static icl_stats_t *s_amq_peer_config_cmdline_help_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_CMDLINE_PARSE))
static icl_stats_t *s_amq_peer_config_cmdline_parse_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_OPTIONS_HELP))
static icl_stats_t *s_amq_peer_config_options_help_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SET_PACKIO))
static icl_stats_t *s_amq_peer_config_set_packio_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_PACKIO))
static icl_stats_t *s_amq_peer_config_packio_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SET_TCP_NODELAY))
static icl_stats_t *s_amq_peer_config_set_tcp_nodelay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_TCP_NODELAY))
static icl_stats_t *s_amq_peer_config_tcp_nodelay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SET_TCP_RCVBUF))
static icl_stats_t *s_amq_peer_config_set_tcp_rcvbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_TCP_RCVBUF))
static icl_stats_t *s_amq_peer_config_tcp_rcvbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SET_TCP_SNDBUF))
static icl_stats_t *s_amq_peer_config_set_tcp_sndbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_TCP_SNDBUF))
static icl_stats_t *s_amq_peer_config_tcp_sndbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_DUMP_LOG))
static icl_stats_t *s_amq_peer_config_dump_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SELFTEST))
static icl_stats_t *s_amq_peer_config_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_TERMINATE))
static icl_stats_t *s_amq_peer_config_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SHOW))
static icl_stats_t *s_amq_peer_config_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_DESTROY_PUBLIC))
static icl_stats_t *s_amq_peer_config_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_ALLOC))
static icl_stats_t *s_amq_peer_config_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_FREE))
static icl_stats_t *s_amq_peer_config_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_READ_LOCK))
static icl_stats_t *s_amq_peer_config_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_WRITE_LOCK))
static icl_stats_t *s_amq_peer_config_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_UNLOCK))
static icl_stats_t *s_amq_peer_config_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_CACHE_INITIALISE))
static icl_stats_t *s_amq_peer_config_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_CACHE_PURGE))
static icl_stats_t *s_amq_peer_config_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_CACHE_TERMINATE))
static icl_stats_t *s_amq_peer_config_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_ANIMATE))
static icl_stats_t *s_amq_peer_config_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_NEW_IN_SCOPE))
static icl_stats_t *s_amq_peer_config_new_in_scope_stats = NULL;
#endif
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
    ipr_config_locate (self->config, "/config/+", "");
    while (self->config->located) {
        item_name = ipr_config_item (self->config);
        if (streq (item_name, "echo"))
            icl_console_print ("I: %s: %s", self->filename, ipr_config_value (self->config));
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
        ipr_config_next (self->config);
    }
}

static void s_get_properties (amq_peer_config_t *self)
{
    char
        *value;                         //  Configured value

    //  All properties on tuning path
    ipr_config_locate (self->config, "/config/tuning", NULL);

    //  Get packio property from config file or built-in defaults
    value = ipr_config_get (self->config, "packio", NULL);
    if (value)
        self->packio = (int) atol (value);
    else
        self->packio = 0;

    //  Get tcp_nodelay property from config file or built-in defaults
    value = ipr_config_get (self->config, "tcp_nodelay", NULL);
    if (value)
        self->tcp_nodelay = (Bool) atol (value);
    else
        self->tcp_nodelay = 1;

    //  Get tcp_rcvbuf property from config file or built-in defaults
    value = ipr_config_get (self->config, "tcp_rcvbuf", NULL);
    if (value)
        self->tcp_rcvbuf = (int) atol (value);
    else
        self->tcp_rcvbuf = 0;

    //  Get tcp_sndbuf property from config file or built-in defaults
    value = ipr_config_get (self->config, "tcp_sndbuf", NULL);
    if (value)
        self->tcp_sndbuf = (int) atol (value);
    else
        self->tcp_sndbuf = 0;

    //  All properties on server path
    ipr_config_locate (self->config, "/config/server", NULL);

    //  All properties on resources path
    ipr_config_locate (self->config, "/config/resources", NULL);

    //  All properties on logging path
    ipr_config_locate (self->config, "/config/logging", NULL);

    //  All properties on internal path
    ipr_config_locate (self->config, "/config/internal", NULL);

    //  All properties on queue_profile path
    ipr_config_locate (self->config, "/config/queue_profile", NULL);

    //  All properties on security path
    ipr_config_locate (self->config, "/config/security", NULL);

    //  All properties on federation path
    ipr_config_locate (self->config, "/config/federation", NULL);

    //  All properties on failover path
    ipr_config_locate (self->config, "/config/failover", NULL);

    //  All properties on federate path
    ipr_config_locate (self->config, "/config/federate", NULL);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_NEW))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_NEW))
    icl_trace_record (NULL, amq_peer_config_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_NEW))
    icl_stats_inc ("amq_peer_config_new", &s_amq_peer_config_new_stats);
#endif

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
self->config = ipr_config_new (NULL, FALSE);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_NEW))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_NEW))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, self);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_DESTROY))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DESTROY))
    icl_trace_record (NULL, amq_peer_config_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_DESTROY))
    icl_stats_inc ("amq_peer_config_annihilate", &s_amq_peer_config_annihilate_stats);
#endif

    AMQ_PEER_CONFIG_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

ipr_config_destroy (&self->config);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DESTROY))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_DESTROY))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_LOAD_XMLFILE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_load_xmlfile_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" required=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, required);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_LOAD_XMLFILE))
    icl_trace_record (NULL, amq_peer_config_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_LOAD_XMLFILE))
    icl_stats_inc ("amq_peer_config_load_xmlfile", &s_amq_peer_config_load_xmlfile_stats);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
assert (filename);
if (!ipr_config_load (self->config, filename, required)) {
    icl_shortstr_cpy (self->filename, filename);
    s_validate_items (self);
    s_get_properties (self);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_LOAD_XMLFILE))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_LOAD_XMLFILE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_load_xmlfile_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" required=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, required, rc);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_LOAD_BUCKET))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_load_bucket_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_LOAD_BUCKET))
    icl_trace_record (NULL, amq_peer_config_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_LOAD_BUCKET))
    icl_stats_inc ("amq_peer_config_load_bucket", &s_amq_peer_config_load_bucket_stats);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
assert (bucket);
ipr_config_load_bucket (self->config, bucket);
s_validate_items (self);
s_get_properties (self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_LOAD_BUCKET))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_LOAD_BUCKET))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_load_bucket_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket, rc);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_COMMIT))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_commit_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_COMMIT))
    icl_trace_record (NULL, amq_peer_config_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_COMMIT))
    icl_stats_inc ("amq_peer_config_commit", &s_amq_peer_config_commit_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
if (filename)
    ipr_config_save (self->config, filename);
else
if (strused (self->filename))
    ipr_config_save (self->config, self->filename);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_COMMIT))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_COMMIT))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_commit_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, rc);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_ROLLBACK))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_rollback_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ROLLBACK))
    icl_trace_record (NULL, amq_peer_config_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_ROLLBACK))
    icl_stats_inc ("amq_peer_config_rollback", &s_amq_peer_config_rollback_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
ipr_config_destroy (&self->config);
self->config = ipr_config_new (self->filename, TRUE);
s_get_properties (self);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ROLLBACK))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_ROLLBACK))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_rollback_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_CMDLINE_HELP))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_cmdline_help_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CMDLINE_HELP))
    icl_trace_record (NULL, amq_peer_config_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_CMDLINE_HELP))
    icl_stats_inc ("amq_peer_config_cmdline_help", &s_amq_peer_config_cmdline_help_stats);
#endif

printf ("Options that override config values; these take an argument:\n");
printf ("  --packio         Pack network data before writing\n");
printf ("  --tcp_nodelay    TCP/IP NODELAY option\n");
printf ("  --tcp_rcvbuf     TCP/IP receive buffer, in bytes\n");
printf ("  --tcp_sndbuf     TCP/IP send buffer, in bytes\n");
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CMDLINE_HELP))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_CMDLINE_HELP))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_cmdline_help_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_peer_config_cmdline_parse

    Type: Component method
    Accepts a amq_peer_config_t reference and returns zero in case of success,
    1 in case of errors.
    Parses recognized command-line options and processes, starting
    with --, prints an error message and exits if the syntax is invalid.
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_CMDLINE_PARSE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_cmdline_parse_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" argc=\"%i\""
" argv=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, argc, argv);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CMDLINE_PARSE))
    icl_trace_record (NULL, amq_peer_config_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_CMDLINE_PARSE))
    icl_stats_inc ("amq_peer_config_cmdline_parse", &s_amq_peer_config_cmdline_parse_stats);
#endif

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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CMDLINE_PARSE))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_CMDLINE_PARSE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_cmdline_parse_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" argc=\"%i\""
" argv=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, argc, argv, rc);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_OPTIONS_HELP))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_options_help_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_OPTIONS_HELP))
    icl_trace_record (NULL, amq_peer_config_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_OPTIONS_HELP))
    icl_stats_inc ("amq_peer_config_options_help", &s_amq_peer_config_options_help_stats);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

printf ("\nThese are the configured options for %s\n\n", name);

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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_OPTIONS_HELP))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_OPTIONS_HELP))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_options_help_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, rc);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SET_PACKIO))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_set_packio_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" packio=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, packio);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_PACKIO))
    icl_trace_record (NULL, amq_peer_config_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SET_PACKIO))
    icl_stats_inc ("amq_peer_config_set_packio", &s_amq_peer_config_set_packio_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", packio);
ipr_config_putp (self->config, "/config/tuning", "packio", strvalue);
self->packio = packio;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_PACKIO))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SET_PACKIO))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_set_packio_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" packio=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, packio, rc);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_PACKIO))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_packio_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_PACKIO))
    icl_trace_record (NULL, amq_peer_config_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_PACKIO))
    icl_stats_inc ("amq_peer_config_packio", &s_amq_peer_config_packio_stats);
#endif

//
if (self)
    packio = self->packio;
else
    packio = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_PACKIO))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_PACKIO))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_packio_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" packio=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, packio);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SET_TCP_NODELAY))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_set_tcp_nodelay_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_nodelay=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_nodelay);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_NODELAY))
    icl_trace_record (NULL, amq_peer_config_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SET_TCP_NODELAY))
    icl_stats_inc ("amq_peer_config_set_tcp_nodelay", &s_amq_peer_config_set_tcp_nodelay_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_nodelay);
ipr_config_putp (self->config, "/config/tuning", "tcp_nodelay", strvalue);
self->tcp_nodelay = tcp_nodelay;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_NODELAY))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SET_TCP_NODELAY))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_set_tcp_nodelay_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_nodelay=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_nodelay, rc);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_TCP_NODELAY))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_tcp_nodelay_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_NODELAY))
    icl_trace_record (NULL, amq_peer_config_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_TCP_NODELAY))
    icl_stats_inc ("amq_peer_config_tcp_nodelay", &s_amq_peer_config_tcp_nodelay_stats);
#endif

//
if (self)
    tcp_nodelay = self->tcp_nodelay;
else
    tcp_nodelay = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_NODELAY))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_TCP_NODELAY))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_tcp_nodelay_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_nodelay=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_nodelay);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SET_TCP_RCVBUF))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_set_tcp_rcvbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_rcvbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_rcvbuf);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_RCVBUF))
    icl_trace_record (NULL, amq_peer_config_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SET_TCP_RCVBUF))
    icl_stats_inc ("amq_peer_config_set_tcp_rcvbuf", &s_amq_peer_config_set_tcp_rcvbuf_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_rcvbuf);
ipr_config_putp (self->config, "/config/tuning", "tcp_rcvbuf", strvalue);
self->tcp_rcvbuf = tcp_rcvbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_RCVBUF))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SET_TCP_RCVBUF))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_set_tcp_rcvbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_rcvbuf=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_rcvbuf, rc);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_TCP_RCVBUF))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_tcp_rcvbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_RCVBUF))
    icl_trace_record (NULL, amq_peer_config_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_TCP_RCVBUF))
    icl_stats_inc ("amq_peer_config_tcp_rcvbuf", &s_amq_peer_config_tcp_rcvbuf_stats);
#endif

//
if (self)
    tcp_rcvbuf = self->tcp_rcvbuf;
else
    tcp_rcvbuf = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_RCVBUF))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_TCP_RCVBUF))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_tcp_rcvbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_rcvbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_rcvbuf);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SET_TCP_SNDBUF))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_set_tcp_sndbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_sndbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_sndbuf);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_SNDBUF))
    icl_trace_record (NULL, amq_peer_config_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SET_TCP_SNDBUF))
    icl_stats_inc ("amq_peer_config_set_tcp_sndbuf", &s_amq_peer_config_set_tcp_sndbuf_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_sndbuf);
ipr_config_putp (self->config, "/config/tuning", "tcp_sndbuf", strvalue);
self->tcp_sndbuf = tcp_sndbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_SNDBUF))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SET_TCP_SNDBUF))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_set_tcp_sndbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_sndbuf=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_sndbuf, rc);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_TCP_SNDBUF))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_tcp_sndbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_SNDBUF))
    icl_trace_record (NULL, amq_peer_config_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_TCP_SNDBUF))
    icl_stats_inc ("amq_peer_config_tcp_sndbuf", &s_amq_peer_config_tcp_sndbuf_stats);
#endif

//
if (self)
    tcp_sndbuf = self->tcp_sndbuf;
else
    tcp_sndbuf = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_SNDBUF))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_TCP_SNDBUF))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_tcp_sndbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_sndbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_sndbuf);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_DUMP_LOG))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_dump_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" logfile=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, logfile);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DUMP_LOG))
    icl_trace_record (NULL, amq_peer_config_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_DUMP_LOG))
    icl_stats_inc ("amq_peer_config_dump_log", &s_amq_peer_config_dump_log_stats);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

smt_log_print (logfile, "*******************  Configuration Settings  ********************");
smt_log_print (logfile, "packio=%i", self->packio);
smt_log_print (logfile, "tcp_nodelay=%i", self->tcp_nodelay);
smt_log_print (logfile, "tcp_rcvbuf=%i", self->tcp_rcvbuf);
smt_log_print (logfile, "tcp_sndbuf=%i", self->tcp_sndbuf);
smt_log_print (logfile, "");

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DUMP_LOG))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_DUMP_LOG))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_dump_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" logfile=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, logfile, rc);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SELFTEST))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SELFTEST))
    icl_trace_record (NULL, amq_peer_config_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SELFTEST))
    icl_stats_inc ("amq_peer_config_selftest", &s_amq_peer_config_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SELFTEST))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SELFTEST))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_selftest_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_TERMINATE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TERMINATE))
    icl_trace_record (NULL, amq_peer_config_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_TERMINATE))
    icl_stats_inc ("amq_peer_config_terminate", &s_amq_peer_config_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TERMINATE))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_TERMINATE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

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


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SHOW))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_show_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SHOW))
    icl_trace_record (NULL, amq_peer_config_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_SHOW))
    icl_stats_inc ("amq_peer_config_show", &s_amq_peer_config_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_peer_config file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SHOW))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_SHOW))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_show_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_DESTROY_PUBLIC))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_peer_config_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_DESTROY_PUBLIC))
    icl_stats_inc ("amq_peer_config_destroy", &s_amq_peer_config_destroy_stats);
#endif

if (self) {
    amq_peer_config_annihilate (self_p);
    amq_peer_config_free ((amq_peer_config_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_DESTROY_PUBLIC))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_ALLOC))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ALLOC))
    icl_trace_record (NULL, amq_peer_config_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_ALLOC))
    icl_stats_inc ("amq_peer_config_alloc", &s_amq_peer_config_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_peer_config_cache_initialise ();

self = (amq_peer_config_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_peer_config_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ALLOC))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_ALLOC))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, self);
#endif


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


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_FREE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_FREE))
    icl_trace_record (NULL, amq_peer_config_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_FREE))
    icl_stats_inc ("amq_peer_config_free", &s_amq_peer_config_free_stats);
#endif

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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_FREE))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_FREE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_READ_LOCK))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_read_lock_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_READ_LOCK))
    icl_trace_record (NULL, amq_peer_config_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_READ_LOCK))
    icl_stats_inc ("amq_peer_config_read_lock", &s_amq_peer_config_read_lock_stats);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_READ_LOCK))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_READ_LOCK))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_read_lock_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_WRITE_LOCK))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_write_lock_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_WRITE_LOCK))
    icl_trace_record (NULL, amq_peer_config_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_WRITE_LOCK))
    icl_stats_inc ("amq_peer_config_write_lock", &s_amq_peer_config_write_lock_stats);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_WRITE_LOCK))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_WRITE_LOCK))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_write_lock_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_UNLOCK))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_unlock_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_UNLOCK))
    icl_trace_record (NULL, amq_peer_config_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_UNLOCK))
    icl_stats_inc ("amq_peer_config_unlock", &s_amq_peer_config_unlock_stats);
#endif

AMQ_PEER_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_UNLOCK))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_UNLOCK))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_unlock_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_CACHE_INITIALISE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_peer_config_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_CACHE_INITIALISE))
    icl_stats_inc ("amq_peer_config_cache_initialise", &s_amq_peer_config_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_peer_config_t));
icl_system_register (amq_peer_config_cache_purge, amq_peer_config_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_CACHE_INITIALISE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_cache_initialise_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_CACHE_PURGE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_PURGE))
    icl_trace_record (NULL, amq_peer_config_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_CACHE_PURGE))
    icl_stats_inc ("amq_peer_config_cache_purge", &s_amq_peer_config_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_PURGE))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_CACHE_PURGE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_cache_purge_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_CACHE_TERMINATE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_peer_config_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_CACHE_TERMINATE))
    icl_stats_inc ("amq_peer_config_cache_terminate", &s_amq_peer_config_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_CACHE_TERMINATE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_cache_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_peer_config_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_peer_config_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_ANIMATE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_animate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ANIMATE))
    icl_trace_record (NULL, amq_peer_config_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_ANIMATE))
    icl_stats_inc ("amq_peer_config_animate", &s_amq_peer_config_animate_stats);
#endif

amq_peer_config_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ANIMATE))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_ANIMATE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_animate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_PEER_CONFIG_NEW_IN_SCOPE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_peer_config_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG)  ||  defined (BASE_STATS_AMQ_PEER_CONFIG_NEW_IN_SCOPE))
    icl_stats_inc ("amq_peer_config_new_in_scope", &s_amq_peer_config_new_in_scope_stats);
#endif

*self_p = amq_peer_config_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_peer_config_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_peer_config_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG)   || defined (BASE_ANIMATE_AMQ_PEER_CONFIG_NEW_IN_SCOPE))
    if (amq_peer_config_animating)
        icl_console_print ("<amq_peer_config_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_NEW)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DESTROY)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_LOAD_XMLFILE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_LOAD_BUCKET)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_COMMIT)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ROLLBACK)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CMDLINE_HELP)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CMDLINE_PARSE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_OPTIONS_HELP)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_PACKIO)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_PACKIO)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_NODELAY)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_NODELAY)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_RCVBUF)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_RCVBUF)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_SNDBUF)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_SNDBUF)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DUMP_LOG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SELFTEST)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TERMINATE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SHOW)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ALLOC)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_FREE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_READ_LOCK)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_UNLOCK)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ANIMATE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_NEW_IN_SCOPE) )
void
amq_peer_config_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "load xmlfile"; break;
        case 4: method_name = "load bucket"; break;
        case 5: method_name = "commit"; break;
        case 6: method_name = "rollback"; break;
        case 7: method_name = "cmdline help"; break;
        case 8: method_name = "cmdline parse"; break;
        case 9: method_name = "options help"; break;
        case 10: method_name = "set packio"; break;
        case 11: method_name = "packio"; break;
        case 12: method_name = "set tcp_nodelay"; break;
        case 13: method_name = "tcp_nodelay"; break;
        case 14: method_name = "set tcp_rcvbuf"; break;
        case 15: method_name = "tcp_rcvbuf"; break;
        case 16: method_name = "set tcp_sndbuf"; break;
        case 17: method_name = "tcp_sndbuf"; break;
        case 18: method_name = "dump log"; break;
        case 19: method_name = "selftest"; break;
        case 20: method_name = "terminate"; break;
        case 21: method_name = "show"; break;
        case 22: method_name = "destroy public"; break;
        case 23: method_name = "alloc"; break;
        case 24: method_name = "free"; break;
        case 25: method_name = "read lock"; break;
        case 26: method_name = "write lock"; break;
        case 27: method_name = "unlock"; break;
        case 28: method_name = "cache initialise"; break;
        case 29: method_name = "cache purge"; break;
        case 30: method_name = "cache terminate"; break;
        case 31: method_name = "animate"; break;
        case 32: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_peer_config %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_peer_config_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_peer_config_component    = "amq_peer_config ";
char *amq_peer_config_version      = "1.0 ";
char *amq_peer_config_copyright    = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_peer_config_filename     = "amq_peer_config.icl ";
char *amq_peer_config_builddate    = "2010/10/06 ";
char *amq_peer_config_version_end  = "VeRsIoNeNd:ipc";

