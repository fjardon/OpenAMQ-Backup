/*---------------------------------------------------------------------------
    amq_queue.c - amq_queue component

This class implements the server queue class, an asynchronous object
that acts as a envelope for the separate queue managers for each
class.  This is a lock-free asynchronous class.
    Generated from amq_queue.icl by smt_object_gen using GSL/4.
    
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
#include "amq_queue.h"                  //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_queue_t

//  Shorthands for class methods                                               

#define self_new            amq_queue_new
#define self_annihilate     amq_queue_annihilate
#define self_unbind_connection  amq_queue_unbind_connection
#define self_publish        amq_queue_publish
#define self_get            amq_queue_get
#define self_consume        amq_queue_consume
#define self_cancel         amq_queue_cancel
#define self_self_destruct  amq_queue_self_destruct
#define self_consumer_ack   amq_queue_consumer_ack
#define self_purge          amq_queue_purge
#define self_dispatch       amq_queue_dispatch
#define self_message_count  amq_queue_message_count
#define self_consumer_count  amq_queue_consumer_count
#define self_set_last_binding  amq_queue_set_last_binding
#define self_selftest       amq_queue_selftest
#define self_count          amq_queue_count
#define self_inspect_shim   amq_queue_inspect_shim
#define self_inspect        amq_queue_inspect
#define self_modify_shim    amq_queue_modify_shim
#define self_modify         amq_queue_modify
#define self_method_shim    amq_queue_method_shim
#define self_method         amq_queue_method
#define self_unlink_shim    amq_queue_unlink_shim
#define self_initialise     amq_queue_initialise
#define self_terminate      amq_queue_terminate
#define self_remove_from_all_containers  amq_queue_remove_from_all_containers
#define self_show           amq_queue_show
#define self_destroy        amq_queue_destroy
#define self_unlink         amq_queue_unlink
#define self_animate        amq_queue_animate
#define self_free           amq_queue_free
#define self_alloc          amq_queue_alloc
#define self_link           amq_queue_link
#define self_cache_initialise  amq_queue_cache_initialise
#define self_cache_purge    amq_queue_cache_purge
#define self_cache_terminate  amq_queue_cache_terminate
#define self_new_in_scope   amq_queue_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_NEW))
static icl_stats_t *s_amq_queue_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_DESTROY))
static icl_stats_t *s_amq_queue_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_UNBIND_CONNECTION))
static icl_stats_t *s_amq_queue_unbind_connection_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_PUBLISH))
static icl_stats_t *s_amq_queue_publish_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_GET))
static icl_stats_t *s_amq_queue_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CONSUME))
static icl_stats_t *s_amq_queue_consume_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CANCEL))
static icl_stats_t *s_amq_queue_cancel_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_SELF_DESTRUCT))
static icl_stats_t *s_amq_queue_self_destruct_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CONSUMER_ACK))
static icl_stats_t *s_amq_queue_consumer_ack_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_PURGE))
static icl_stats_t *s_amq_queue_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_DISPATCH))
static icl_stats_t *s_amq_queue_dispatch_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_MESSAGE_COUNT))
static icl_stats_t *s_amq_queue_message_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CONSUMER_COUNT))
static icl_stats_t *s_amq_queue_consumer_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_SET_LAST_BINDING))
static icl_stats_t *s_amq_queue_set_last_binding_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_SELFTEST))
static icl_stats_t *s_amq_queue_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_COUNT))
static icl_stats_t *s_amq_queue_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_INSPECT_SHIM))
static icl_stats_t *s_amq_queue_inspect_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_INSPECT))
static icl_stats_t *s_amq_queue_inspect_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_MODIFY_SHIM))
static icl_stats_t *s_amq_queue_modify_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_MODIFY))
static icl_stats_t *s_amq_queue_modify_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_METHOD_SHIM))
static icl_stats_t *s_amq_queue_method_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_METHOD))
static icl_stats_t *s_amq_queue_method_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_UNLINK_SHIM))
static icl_stats_t *s_amq_queue_unlink_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_INITIALISE))
static icl_stats_t *s_amq_queue_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_TERMINATE))
static icl_stats_t *s_amq_queue_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_amq_queue_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_SHOW))
static icl_stats_t *s_amq_queue_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_DESTROY_PUBLIC))
static icl_stats_t *s_amq_queue_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_UNLINK))
static icl_stats_t *s_amq_queue_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_ANIMATE))
static icl_stats_t *s_amq_queue_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_FREE))
static icl_stats_t *s_amq_queue_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_ALLOC))
static icl_stats_t *s_amq_queue_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_LINK))
static icl_stats_t *s_amq_queue_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CACHE_INITIALISE))
static icl_stats_t *s_amq_queue_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CACHE_PURGE))
static icl_stats_t *s_amq_queue_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CACHE_TERMINATE))
static icl_stats_t *s_amq_queue_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_NEW_IN_SCOPE))
static icl_stats_t *s_amq_queue_new_in_scope_stats = NULL;
#endif
#define amq_queue_annihilate(self)      amq_queue_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_queue_annihilate_ (
amq_queue_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_queue_initialise (
void);

#define amq_queue_alloc()               amq_queue_alloc_ (__FILE__, __LINE__)
static amq_queue_t *
    amq_queue_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_queue_cache_initialise (
void);

static void
    amq_queue_cache_purge (
void);

static void
    amq_queue_cache_terminate (
void);

Bool
    amq_queue_animating = TRUE;         //  Animation enabled by default
static Bool
    s_amq_queue_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_queue_mutex        = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static amq_console_class_t
    *s_class;                           //  Class descriptor
qbyte
    gbl_amq_queue_count = 0;
static int
    s_set_queue_limits (amq_queue_t *self, char *profile);
/*  -------------------------------------------------------------------------
    amq_queue_new

    Type: Component method
    Creates and initialises a new amq_queue_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

amq_queue_t *
    amq_queue_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_vhost_t * vhost,                //  Parent vhost
    amq_server_connection_t * connection,   //  Owner connection
    char * name,                        //  Queue name
    Bool durable,                       //  Is queue durable?
    Bool exclusive,                     //  Is queue exclusive?
    Bool auto_delete,                   //  Auto-delete unused queue?
    icl_longstr_t* arguments            //  Queue arguments
)
{
#define table vhost->queue_table
#define key name
amq_broker_t
    *broker = amq_broker;
asl_field_list_t
    *arg_list;
asl_field_t
    *profile_field;
char
    *profile;
    amq_queue_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_NEW))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" vhost=\"%pp\""
" connection=\"%pp\""
" name=\"%s\""
" durable=\"%i\""
" exclusive=\"%i\""
" auto_delete=\"%i\""
" arguments=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, vhost, connection, name, durable, exclusive, auto_delete, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_NEW))
    icl_trace_record (NULL, amq_queue_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_NEW))
    icl_stats_inc ("amq_queue_new", &s_amq_queue_new_stats);
#endif

if (!s_amq_queue_active)
    self_initialise ();
    self = amq_queue_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_QUEUE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_queue_show_);
#endif

self->console = amq_console_link (amq_console);
self->object_id = icl_atomic_inc32 ((volatile qbyte *) &amq_object_id);
amq_console_register (self->console, self->object_id, self_link (self), s_class, broker->object_id);
self->by_vhost_next = self;
self->by_vhost_prev = self;
self->by_vhost_head = NULL;
self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->thread = amq_queue_agent_class_thread_new (self);
self->thread->animate = TRUE;

icl_atomic_inc32 ((volatile qbyte *) &gbl_amq_queue_count);

//
self->broker      = broker;
self->vhost       = vhost;
self->connection  = amq_server_connection_link (connection);
self->enabled     = TRUE;
self->durable     = durable;
self->exclusive   = exclusive;
self->auto_delete = auto_delete;
self->queue_basic = amq_queue_basic_new (self);
icl_shortstr_cpy (self->name, name);
amq_queue_by_vhost_queue (self->vhost->queue_list, self);
if (amq_server_config_debug_queue (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "Q: create   queue=%s auto_delete=%d", self->name, self->auto_delete);
//  Process arguments
arg_list = asl_field_list_new (arguments);
if (!arg_list) {
    //  Catch case where field list is malformed
    amq_server_connection_error (NULL, ASL_SYNTAX_ERROR,
        "Malformed 'arguments' field in queue.declare",
        AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
    self_destroy (&self);
}
else {
    //  If unspecified, queue profile defaults to 'private' for exclusive
    //  queues, 'shared' for shared queues
    profile_field = asl_field_list_search (arg_list, "profile");
    if (!profile_field)
        profile = self->exclusive? "private": "shared";
    else
        profile = asl_field_string (profile_field);
    //  Reject unknown queue profiles
    if (s_set_queue_limits (self, profile)) {
        smt_log_print (amq_broker->alert_log,
            "E: client requested unknown queue profile '%s' (%s, %s, %s, %s)",
            profile,
            self->connection->client_address,
            self->connection->client_product,
            self->connection->client_version,
            self->connection->client_instance);
        amq_server_connection_error (connection, ASL_SYNTAX_ERROR,
            "Unknown queue profile requested",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
        if (profile_field)
            asl_field_destroy (&profile_field);
        asl_field_list_destroy (&arg_list);
        self_destroy (&self);
    }
    if (profile_field)
        asl_field_destroy (&profile_field);
    asl_field_list_destroy (&arg_list);
}
if (table && self && amq_queue_table_insert (table, key, self))
    amq_queue_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_NEW))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_NEW))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" vhost=\"%pp\""
" connection=\"%pp\""
" name=\"%s\""
" durable=\"%i\""
" exclusive=\"%i\""
" auto_delete=\"%i\""
" arguments=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, vhost, connection, name, durable, exclusive, auto_delete, arguments, self);
#endif


    return (self);
}
#undef table
#undef key
/*  -------------------------------------------------------------------------
    amq_queue_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_queue_annihilate_ (
    amq_queue_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    int
        history_last;
#endif

    amq_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_DESTROY))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_DESTROY))
    icl_trace_record (NULL, amq_queue_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_DESTROY))
    icl_stats_inc ("amq_queue_annihilate", &s_amq_queue_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_QUEUE_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (amq_queue_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_DESTROY))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_DESTROY))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_unbind_connection

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_queue_unbind_connection (
    amq_queue_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_UNBIND_CONNECTION))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_unbind_connection_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_UNBIND_CONNECTION))
    icl_trace_record (NULL, amq_queue_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_UNBIND_CONNECTION))
    icl_stats_inc ("amq_queue_unbind_connection", &s_amq_queue_unbind_connection_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_queue_agent_unbind_connection (self->thread)) {
        //icl_console_print ("Error sending 'unbind connection' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_UNBIND_CONNECTION))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_UNBIND_CONNECTION))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_unbind_connection_finish"
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
    amq_queue_publish

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Publish message content onto queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_publish (
    amq_queue_t * self,                 //  Reference to object
    amq_server_channel_t * channel,     //  Channel for reply
    amq_content_basic_t * content,      //  Content to publish
    Bool immediate                      //  Send immediately or return?
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_PUBLISH))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_publish_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel=\"%pp\""
" content=\"%pp\""
" immediate=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel, content, immediate);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_PUBLISH))
    icl_trace_record (NULL, amq_queue_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_PUBLISH))
    icl_stats_inc ("amq_queue_publish", &s_amq_queue_publish_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_publish (self->thread,channel,content,immediate)) {
        //icl_console_print ("Error sending 'publish' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_PUBLISH))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_PUBLISH))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_publish_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel=\"%pp\""
" content=\"%pp\""
" immediate=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel, content, immediate, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_get

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Returns next message off queue, if any.
    -------------------------------------------------------------------------
 */

int
    amq_queue_get (
    amq_queue_t * self,                 //  Reference to object
    amq_server_channel_t * channel,     //  Channel for reply
    int class_id                        //  The content class
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_GET))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_get_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel=\"%pp\""
" class_id=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel, class_id);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_GET))
    icl_trace_record (NULL, amq_queue_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_GET))
    icl_stats_inc ("amq_queue_get", &s_amq_queue_get_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_get (self->thread,channel,class_id)) {
        //icl_console_print ("Error sending 'get' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_GET))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_GET))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_get_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel=\"%pp\""
" class_id=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel, class_id, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_consume

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Attach consumer to appropriate queue consumer list.
    -------------------------------------------------------------------------
 */

int
    amq_queue_consume (
    amq_queue_t * self,                 //  Reference to object
    amq_consumer_t * consumer,          //  Consumer reference
    Bool active,                        //  Create active consumer?
    Bool nowait                         //  No reply method wanted
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_CONSUME))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_consume_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" consumer=\"%pp\""
" active=\"%i\""
" nowait=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, consumer, active, nowait);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CONSUME))
    icl_trace_record (NULL, amq_queue_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CONSUME))
    icl_stats_inc ("amq_queue_consume", &s_amq_queue_consume_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_consume (self->thread,consumer,active,nowait)) {
        //icl_console_print ("Error sending 'consume' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CONSUME))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_CONSUME))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_consume_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" consumer=\"%pp\""
" active=\"%i\""
" nowait=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, consumer, active, nowait, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_cancel

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Cancel consumer, by reference, and alert client application if
    we're doing this in a synchronous exchange of methods.  If the
    cancel is being done at channel close, no notify will be sent
    back to the client.
    -------------------------------------------------------------------------
 */

int
    amq_queue_cancel (
    amq_queue_t * self,                 //  Reference to object
    amq_consumer_t * consumer,          //  Consumer reference
    Bool notify,                        //  Notify client application?
    Bool nowait                         //  No reply method wanted
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_CANCEL))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_cancel_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" consumer=\"%pp\""
" notify=\"%i\""
" nowait=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, consumer, notify, nowait);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CANCEL))
    icl_trace_record (NULL, amq_queue_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CANCEL))
    icl_stats_inc ("amq_queue_cancel", &s_amq_queue_cancel_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_cancel (self->thread,consumer,notify,nowait)) {
        //icl_console_print ("Error sending 'cancel' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CANCEL))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_CANCEL))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_cancel_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" consumer=\"%pp\""
" notify=\"%i\""
" nowait=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, consumer, notify, nowait, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_self_destruct

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Self-destruct the queue.  This is somewhat delicate because it's
    an async object, and because it's linked to by exchanges/bindings
    and by connections.
    -------------------------------------------------------------------------
 */

int
    amq_queue_self_destruct (
    amq_queue_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_SELF_DESTRUCT))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_self_destruct_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_SELF_DESTRUCT))
    icl_trace_record (NULL, amq_queue_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_SELF_DESTRUCT))
    icl_stats_inc ("amq_queue_self_destruct", &s_amq_queue_self_destruct_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_self_destruct (self->thread)) {
        //icl_console_print ("Error sending 'self destruct' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_SELF_DESTRUCT))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_SELF_DESTRUCT))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_self_destruct_finish"
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
    amq_queue_consumer_ack

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Acknowledge messages on consumer, if any.
    -------------------------------------------------------------------------
 */

int
    amq_queue_consumer_ack (
    amq_queue_t * self,                 //  Reference to object
    amq_consumer_t * consumer           //  Consumer to ack
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_CONSUMER_ACK))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_consumer_ack_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" consumer=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, consumer);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CONSUMER_ACK))
    icl_trace_record (NULL, amq_queue_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CONSUMER_ACK))
    icl_stats_inc ("amq_queue_consumer_ack", &s_amq_queue_consumer_ack_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_consumer_ack (self->thread,consumer)) {
        //icl_console_print ("Error sending 'consumer ack' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CONSUMER_ACK))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_CONSUMER_ACK))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_consumer_ack_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" consumer=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, consumer, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_purge

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Purge all content on a queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_purge (
    amq_queue_t * self,                 //  Reference to object
    amq_server_channel_t * channel,     //  Channel for reply
    Bool nowait                         //  No reply method wanted
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_PURGE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel=\"%pp\""
" nowait=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel, nowait);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_PURGE))
    icl_trace_record (NULL, amq_queue_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_PURGE))
    icl_stats_inc ("amq_queue_purge", &s_amq_queue_purge_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_purge (self->thread,channel,nowait)) {
        //icl_console_print ("Error sending 'purge' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_PURGE))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_PURGE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_purge_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel=\"%pp\""
" nowait=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel, nowait, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_dispatch

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Dispatches all pending messages waiting on the specified message queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_dispatch (
    amq_queue_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_DISPATCH))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_dispatch_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_DISPATCH))
    icl_trace_record (NULL, amq_queue_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_DISPATCH))
    icl_stats_inc ("amq_queue_dispatch", &s_amq_queue_dispatch_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_dispatch (self->thread)) {
        //icl_console_print ("Error sending 'dispatch' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_DISPATCH))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_DISPATCH))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_dispatch_finish"
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
    amq_queue_message_count

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Return number of messages on queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_message_count (
    amq_queue_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_MESSAGE_COUNT))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_message_count_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_MESSAGE_COUNT))
    icl_trace_record (NULL, amq_queue_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_MESSAGE_COUNT))
    icl_stats_inc ("amq_queue_message_count", &s_amq_queue_message_count_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

//
rc = amq_queue_basic_message_count (self->queue_basic) +
     (self->connection ?
     smt_thread_reply_backlog (self->connection->thread) :
     0);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_MESSAGE_COUNT))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_MESSAGE_COUNT))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_message_count_finish"
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
    amq_queue_consumer_count

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Return number of consumers on queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_consumer_count (
    amq_queue_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_CONSUMER_COUNT))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_consumer_count_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CONSUMER_COUNT))
    icl_trace_record (NULL, amq_queue_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CONSUMER_COUNT))
    icl_stats_inc ("amq_queue_consumer_count", &s_amq_queue_consumer_count_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

//
rc = amq_queue_basic_consumer_count (self->queue_basic);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CONSUMER_COUNT))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_CONSUMER_COUNT))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_consumer_count_finish"
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
    amq_queue_set_last_binding

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Sets the last binding information for the queue. We do this via an
    async method to avoid two threads squashing the queue's context at the
    same time. The last binding information is used only by the console.
    -------------------------------------------------------------------------
 */

int
    amq_queue_set_last_binding (
    amq_queue_t * self,                 //  Reference to object
    int exchange_type,                  //  Not documented
    char * routing_key,                 //  Not documented
    icl_longstr_t* arguments            //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_SET_LAST_BINDING))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_set_last_binding_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" exchange_type=\"%i\""
" routing_key=\"%s\""
" arguments=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, exchange_type, routing_key, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_SET_LAST_BINDING))
    icl_trace_record (NULL, amq_queue_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_SET_LAST_BINDING))
    icl_stats_inc ("amq_queue_set_last_binding", &s_amq_queue_set_last_binding_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_set_last_binding (self->thread,exchange_type,routing_key,arguments)) {
        //icl_console_print ("Error sending 'set last binding' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_SET_LAST_BINDING))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_SET_LAST_BINDING))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_set_last_binding_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" exchange_type=\"%i\""
" routing_key=\"%s\""
" arguments=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, exchange_type, routing_key, arguments, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_SELFTEST))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_SELFTEST))
    icl_trace_record (NULL, amq_queue_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_SELFTEST))
    icl_stats_inc ("amq_queue_selftest", &s_amq_queue_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_SELFTEST))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_SELFTEST))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_selftest_finish"
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
    amq_queue_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_queue_count (
void)
{
    qbyte
        count;                          //  Number of instances

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_COUNT))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_count_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_COUNT))
    icl_trace_record (NULL, amq_queue_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_COUNT))
    icl_stats_inc ("amq_queue_count", &s_amq_queue_count_stats);
#endif

count = (int) gbl_amq_queue_count;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_COUNT))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_COUNT))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_count_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" count=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    amq_queue_inspect_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_queue_inspect_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_INSPECT_SHIM))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_inspect_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" request=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, request);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_INSPECT_SHIM))
    icl_trace_record (NULL, amq_queue_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_INSPECT_SHIM))
    icl_stats_inc ("amq_queue_inspect_shim", &s_amq_queue_inspect_shim_stats);
#endif

self_inspect ((amq_queue_t *) (self_v), request);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_INSPECT_SHIM))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_INSPECT_SHIM))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_inspect_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" request=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, request, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_inspect

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_queue_inspect (
    amq_queue_t * self,                 //  Reference to object
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_INSPECT))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_inspect_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" request=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, request);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_INSPECT))
    icl_trace_record (NULL, amq_queue_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_INSPECT))
    icl_stats_inc ("amq_queue_inspect", &s_amq_queue_inspect_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_queue_agent_inspect (self->thread,request)) {
        //icl_console_print ("Error sending 'inspect' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_INSPECT))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_INSPECT))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_inspect_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" request=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, request, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_modify_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_queue_modify_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_MODIFY_SHIM))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_modify_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" request=\"%pp\""
" fields=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, request, fields);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_MODIFY_SHIM))
    icl_trace_record (NULL, amq_queue_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_MODIFY_SHIM))
    icl_stats_inc ("amq_queue_modify_shim", &s_amq_queue_modify_shim_stats);
#endif

self_modify ((amq_queue_t *) (self_v), request, fields);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_MODIFY_SHIM))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_MODIFY_SHIM))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_modify_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" request=\"%pp\""
" fields=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, request, fields, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_modify

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_queue_modify (
    amq_queue_t * self,                 //  Reference to object
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_MODIFY))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_modify_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" request=\"%pp\""
" fields=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, request, fields);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_MODIFY))
    icl_trace_record (NULL, amq_queue_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_MODIFY))
    icl_stats_inc ("amq_queue_modify", &s_amq_queue_modify_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_queue_agent_modify (self->thread,request,fields)) {
        //icl_console_print ("Error sending 'modify' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_MODIFY))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_MODIFY))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_modify_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" request=\"%pp\""
" fields=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, request, fields, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_method_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_queue_method_shim (
    void * self_v,                      //  Object cast as a void *
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_METHOD_SHIM))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_method_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" method_name=\"%s\""
" request=\"%pp\""
" fields=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, method_name, request, fields);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_METHOD_SHIM))
    icl_trace_record (NULL, amq_queue_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_METHOD_SHIM))
    icl_stats_inc ("amq_queue_method_shim", &s_amq_queue_method_shim_stats);
#endif

self_method ((amq_queue_t *) (self_v), method_name, request, fields);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_METHOD_SHIM))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_METHOD_SHIM))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_method_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" method_name=\"%s\""
" request=\"%pp\""
" fields=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, method_name, request, fields, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_method

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_queue_method (
    amq_queue_t * self,                 //  Reference to object
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Argument fields
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_METHOD))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_method_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method_name=\"%s\""
" request=\"%pp\""
" fields=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method_name, request, fields);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_METHOD))
    icl_trace_record (NULL, amq_queue_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_METHOD))
    icl_stats_inc ("amq_queue_method", &s_amq_queue_method_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_queue_agent_method (self->thread,method_name,request,fields)) {
        //icl_console_print ("Error sending 'method' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_METHOD))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_METHOD))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_method_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method_name=\"%s\""
" request=\"%pp\""
" fields=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method_name, request, fields, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_unlink_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_unlink_shim (
    void * object_p                     //  Reference pointer cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_UNLINK_SHIM))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_unlink_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" object_p=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, object_p);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_UNLINK_SHIM))
    icl_trace_record (NULL, amq_queue_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_UNLINK_SHIM))
    icl_stats_inc ("amq_queue_unlink_shim", &s_amq_queue_unlink_shim_stats);
#endif

//
amq_queue_unlink (((amq_queue_t **) object_p));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_UNLINK_SHIM))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_UNLINK_SHIM))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_unlink_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" object_p=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, object_p);
#endif

}
/*  -------------------------------------------------------------------------
    amq_queue_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_INITIALISE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_INITIALISE))
    icl_trace_record (NULL, amq_queue_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_INITIALISE))
    icl_stats_inc ("amq_queue_initialise", &s_amq_queue_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_queue_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_queue_mutex)
            s_amq_queue_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_queue_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_queue_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_queue_agent_init ();

s_class = amq_console_class_new ();
s_class->name    = "queue";
s_class->inspect = amq_queue_inspect_shim;
s_class->modify  = amq_queue_modify_shim;
s_class->method  = amq_queue_method_shim;
s_class->unlink  = amq_queue_unlink_shim;
            s_amq_queue_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_queue_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_INITIALISE))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_INITIALISE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_initialise_finish"
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
    amq_queue_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_TERMINATE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_TERMINATE))
    icl_trace_record (NULL, amq_queue_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_TERMINATE))
    icl_stats_inc ("amq_queue_terminate", &s_amq_queue_terminate_stats);
#endif

if (s_amq_queue_active) {

amq_console_class_destroy (&s_class);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_queue_mutex);
#endif
        s_amq_queue_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_TERMINATE))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_TERMINATE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_terminate_finish"
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
    amq_queue_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_queue_remove_from_all_containers (
    amq_queue_t * self                  //  The itemThe item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_queue_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("amq_queue_remove_from_all_containers", &s_amq_queue_remove_from_all_containers_stats);
#endif

AMQ_QUEUE_ASSERT_SANE (self);
amq_queue_table_remove (self);
amq_queue_by_vhost_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_remove_from_all_containers_finish"
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
    amq_queue_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_queue_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_SHOW))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_SHOW))
    icl_trace_record (NULL, amq_queue_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_SHOW))
    icl_stats_inc ("amq_queue_show", &s_amq_queue_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
if (self->by_vhost_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_queue zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    if (self->history_last > AMQ_QUEUE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_QUEUE_HISTORY_LENGTH;
        self->history_last %= AMQ_QUEUE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_QUEUE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_queue>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_SHOW))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_SHOW))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_show_finish"
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
    amq_queue_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_queue_destroy_ (
    amq_queue_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_DESTROY_PUBLIC))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_queue_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_DESTROY_PUBLIC))
    icl_stats_inc ("amq_queue_destroy", &s_amq_queue_destroy_stats);
#endif

    if (self) {
amq_queue_remove_from_all_containers (self);
        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            rc = amq_queue_annihilate_ (self_p, file, line);
        else
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
            amq_queue_free (self);
        *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_DESTROY_PUBLIC))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" rc=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, rc, self?self->links:0, self?self->zombie:0);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_queue_unlink_ (
    amq_queue_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    int
        history_last;
#endif
    amq_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_UNLINK))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_unlink_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_UNLINK))
    icl_trace_record (NULL, amq_queue_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_UNLINK))
    icl_stats_inc ("amq_queue_unlink", &s_amq_queue_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_queue object");
            amq_queue_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_QUEUE_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_queue_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_queue_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_UNLINK))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_UNLINK))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_unlink_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    amq_queue_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_queue_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_ANIMATE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_ANIMATE))
    icl_trace_record (NULL, amq_queue_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_ANIMATE))
    icl_stats_inc ("amq_queue_animate", &s_amq_queue_animate_stats);
#endif

amq_queue_animating = enabled;

amq_queue_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_ANIMATE))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_ANIMATE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_animate_finish"
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
    amq_queue_free

    Type: Component method
    Freess a amq_queue_t object.
    -------------------------------------------------------------------------
 */

void
    amq_queue_free_ (
    amq_queue_t * self,                 //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_FREE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_FREE))
    icl_trace_record (NULL, amq_queue_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_FREE))
    icl_stats_inc ("amq_queue_free", &s_amq_queue_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_QUEUE_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (amq_queue_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_queue_t));
        self->object_tag = AMQ_QUEUE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_FREE))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_FREE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_queue_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_queue_t *
    amq_queue_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_queue_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_ALLOC))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_ALLOC))
    icl_trace_record (NULL, amq_queue_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_ALLOC))
    icl_stats_inc ("amq_queue_alloc", &s_amq_queue_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_queue_cache_initialise ();

self = (amq_queue_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_queue_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_ALLOC))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_ALLOC))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_alloc_finish"
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
    amq_queue_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_queue_t *
    amq_queue_link_ (
    amq_queue_t * self,                 //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_LINK))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_link_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_LINK))
    icl_trace_record (NULL, amq_queue_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_LINK))
    icl_stats_inc ("amq_queue_link", &s_amq_queue_link_stats);
#endif

    if (self) {
        AMQ_QUEUE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_QUEUE_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_LINK))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_LINK))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_link_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_queue_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_queue_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_CACHE_INITIALISE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_queue_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CACHE_INITIALISE))
    icl_stats_inc ("amq_queue_cache_initialise", &s_amq_queue_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_queue_t));
icl_system_register (amq_queue_cache_purge, amq_queue_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_CACHE_INITIALISE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_cache_initialise_finish"
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
    amq_queue_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_CACHE_PURGE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CACHE_PURGE))
    icl_trace_record (NULL, amq_queue_dump, 35);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CACHE_PURGE))
    icl_stats_inc ("amq_queue_cache_purge", &s_amq_queue_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CACHE_PURGE))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 35);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_CACHE_PURGE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_cache_purge_finish"
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
    amq_queue_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_CACHE_TERMINATE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_queue_dump, 36);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_CACHE_TERMINATE))
    icl_stats_inc ("amq_queue_cache_terminate", &s_amq_queue_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 36);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_CACHE_TERMINATE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_cache_terminate_finish"
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
    amq_queue_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_new_in_scope_ (
    amq_queue_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_vhost_t * vhost,                //  Parent vhost
    amq_server_connection_t * connection,   //  Owner connection
    char * name,                        //  Queue name
    Bool durable,                       //  Is queue durable?
    Bool exclusive,                     //  Is queue exclusive?
    Bool auto_delete,                   //  Auto-delete unused queue?
    icl_longstr_t* arguments            //  Queue arguments
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_NEW_IN_SCOPE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" vhost=\"%pp\""
" connection=\"%pp\""
" name=\"%s\""
" durable=\"%i\""
" exclusive=\"%i\""
" auto_delete=\"%i\""
" arguments=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, vhost, connection, name, durable, exclusive, auto_delete, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_queue_dump, 37);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE)  ||  defined (BASE_STATS_AMQ_QUEUE_NEW_IN_SCOPE))
    icl_stats_inc ("amq_queue_new_in_scope", &s_amq_queue_new_in_scope_stats);
#endif

*self_p = amq_queue_new_ (file,line,vhost,connection,name,durable,exclusive,auto_delete,arguments);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_queue_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_queue_dump, 0x10000 + 37);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE)   || defined (BASE_ANIMATE_AMQ_QUEUE_NEW_IN_SCOPE))
    if (amq_queue_animating)
        icl_console_print ("<amq_queue_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" vhost=\"%pp\""
" connection=\"%pp\""
" name=\"%s\""
" durable=\"%i\""
" exclusive=\"%i\""
" auto_delete=\"%i\""
" arguments=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, vhost, connection, name, durable, exclusive, auto_delete, arguments, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_NEW)   || defined (BASE_TRACE_AMQ_QUEUE_DESTROY)   || defined (BASE_TRACE_AMQ_QUEUE_UNBIND_CONNECTION)   || defined (BASE_TRACE_AMQ_QUEUE_PUBLISH)   || defined (BASE_TRACE_AMQ_QUEUE_GET)   || defined (BASE_TRACE_AMQ_QUEUE_CONSUME)   || defined (BASE_TRACE_AMQ_QUEUE_CANCEL)   || defined (BASE_TRACE_AMQ_QUEUE_SELF_DESTRUCT)   || defined (BASE_TRACE_AMQ_QUEUE_CONSUMER_ACK)   || defined (BASE_TRACE_AMQ_QUEUE_PURGE)   || defined (BASE_TRACE_AMQ_QUEUE_DISPATCH)   || defined (BASE_TRACE_AMQ_QUEUE_MESSAGE_COUNT)   || defined (BASE_TRACE_AMQ_QUEUE_CONSUMER_COUNT)   || defined (BASE_TRACE_AMQ_QUEUE_SET_LAST_BINDING)   || defined (BASE_TRACE_AMQ_QUEUE_SELFTEST)   || defined (BASE_TRACE_AMQ_QUEUE_COUNT)   || defined (BASE_TRACE_AMQ_QUEUE_INSPECT_SHIM)   || defined (BASE_TRACE_AMQ_QUEUE_INSPECT)   || defined (BASE_TRACE_AMQ_QUEUE_MODIFY_SHIM)   || defined (BASE_TRACE_AMQ_QUEUE_MODIFY)   || defined (BASE_TRACE_AMQ_QUEUE_METHOD_SHIM)   || defined (BASE_TRACE_AMQ_QUEUE_METHOD)   || defined (BASE_TRACE_AMQ_QUEUE_UNLINK_SHIM)   || defined (BASE_TRACE_AMQ_QUEUE_INITIALISE)   || defined (BASE_TRACE_AMQ_QUEUE_TERMINATE)   || defined (BASE_TRACE_AMQ_QUEUE_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_QUEUE_SHOW)   || defined (BASE_TRACE_AMQ_QUEUE_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_QUEUE_UNLINK)   || defined (BASE_TRACE_AMQ_QUEUE_ANIMATE)   || defined (BASE_TRACE_AMQ_QUEUE_FREE)   || defined (BASE_TRACE_AMQ_QUEUE_ALLOC)   || defined (BASE_TRACE_AMQ_QUEUE_LINK)   || defined (BASE_TRACE_AMQ_QUEUE_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_QUEUE_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_QUEUE_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_QUEUE_NEW_IN_SCOPE) )
void
amq_queue_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "unbind connection"; break;
        case 4: method_name = "publish"; break;
        case 5: method_name = "get"; break;
        case 6: method_name = "consume"; break;
        case 7: method_name = "cancel"; break;
        case 8: method_name = "self destruct"; break;
        case 9: method_name = "consumer ack"; break;
        case 10: method_name = "purge"; break;
        case 11: method_name = "dispatch"; break;
        case 12: method_name = "message count"; break;
        case 13: method_name = "consumer count"; break;
        case 14: method_name = "set last binding"; break;
        case 15: method_name = "selftest"; break;
        case 16: method_name = "count"; break;
        case 17: method_name = "inspect shim"; break;
        case 18: method_name = "inspect"; break;
        case 19: method_name = "modify shim"; break;
        case 20: method_name = "modify"; break;
        case 21: method_name = "method shim"; break;
        case 22: method_name = "method"; break;
        case 23: method_name = "unlink shim"; break;
        case 24: method_name = "initialise"; break;
        case 25: method_name = "terminate"; break;
        case 26: method_name = "remove from all containers"; break;
        case 27: method_name = "show"; break;
        case 28: method_name = "destroy public"; break;
        case 29: method_name = "unlink"; break;
        case 30: method_name = "animate"; break;
        case 31: method_name = "free"; break;
        case 32: method_name = "alloc"; break;
        case 33: method_name = "link"; break;
        case 34: method_name = "cache initialise"; break;
        case 35: method_name = "cache purge"; break;
        case 36: method_name = "cache terminate"; break;
        case 37: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_queue %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

static int
s_set_queue_limits (amq_queue_t *self, char *profile)
{
    ipr_config_t
        *config;                        //  Current server config file
    qbyte
        limit_value;                    //  Specified limit value
    char
        *action_text;                   //  Limit action as string

    config = ipr_config_dup (amq_server_config->config);
    ipr_config_locate (config, "/config/queue_profile", profile);

    if (!config->located) {
        ipr_config_destroy (&config);
        return 1;
    }
    if (config->located)
        ipr_config_locate (config, "limit", NULL);

    while (config->located) {
        action_text = ipr_config_get (config, "name", "(empty)");
        limit_value = atol (ipr_config_get (config, "value",  "0"));
        if (streq (action_text, "warn"))
            self->warn_limit = limit_value;
        else
        if (streq (action_text, "drop"))
            self->drop_limit = limit_value;
        else
        if (streq (action_text, "trim"))
            self->trim_limit = limit_value;
        else
        if (streq (action_text, "kill"))
            self->kill_limit = limit_value;
        else
            smt_log_print (amq_broker->alert_log,
                "E: invalid configured limit action '%s'", action_text);

        if (amq_server_config_debug_queue (amq_server_config))
            smt_log_print (amq_broker->debug_log,
                "Q: setlimit queue=%s limit=%d action=%s",
                self->name, limit_value, action_text);

        ipr_config_next (config);
    }
    ipr_config_destroy (&config);
    return (0);
}

//  Embed the version information in the resulting binary                      

char *amq_queue_version_start      = "VeRsIoNsTaRt:ipc";
char *amq_queue_component          = "amq_queue ";
char *amq_queue_version            = "1.0 ";
char *amq_queue_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_queue_filename           = "amq_queue.icl ";
char *amq_queue_builddate          = "2010/10/06 ";
char *amq_queue_version_end        = "VeRsIoNeNd:ipc";

