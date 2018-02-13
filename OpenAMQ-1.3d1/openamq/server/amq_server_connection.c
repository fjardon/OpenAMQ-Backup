/*---------------------------------------------------------------------------
    amq_server_connection.c - amq_server_connection component

This class implements the connection class for the AMQ server.
    Generated from amq_server_connection.icl by icl_gen using GSL/4.
    
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
#include "amq_server_connection.h"      //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_server_connection_t

//  Shorthands for class methods                                               

#define self_new            amq_server_connection_new
#define self_annihilate     amq_server_connection_annihilate
#define self_free           amq_server_connection_free
#define self_own_queue      amq_server_connection_own_queue
#define self_unbind_queue   amq_server_connection_unbind_queue
#define self_ready          amq_server_connection_ready
#define self_start_ok       amq_server_connection_start_ok
#define self_open           amq_server_connection_open
#define self_initialise     amq_server_connection_initialise
#define self_set_address    amq_server_connection_set_address
#define self_set_trace      amq_server_connection_set_trace
#define self_kill           amq_server_connection_kill
#define self_raise_exception  amq_server_connection_raise_exception
#define self_error          amq_server_connection_error
#define self_exception_raised  amq_server_connection_exception_raised
#define self_tune_ok        amq_server_connection_tune_ok
#define self_selftest       amq_server_connection_selftest
#define self_count          amq_server_connection_count
#define self_remove_from_all_containers  amq_server_connection_remove_from_all_containers
#define self_show           amq_server_connection_show
#define self_terminate      amq_server_connection_terminate
#define self_destroy        amq_server_connection_destroy
#define self_alloc          amq_server_connection_alloc
#define self_read_lock      amq_server_connection_read_lock
#define self_write_lock     amq_server_connection_write_lock
#define self_unlock         amq_server_connection_unlock
#define self_link           amq_server_connection_link
#define self_unlink         amq_server_connection_unlink
#define self_cache_initialise  amq_server_connection_cache_initialise
#define self_cache_purge    amq_server_connection_cache_purge
#define self_cache_terminate  amq_server_connection_cache_terminate
#define self_animate        amq_server_connection_animate
#define self_new_in_scope   amq_server_connection_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_NEW))
static icl_stats_t *s_amq_server_connection_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_DESTROY))
static icl_stats_t *s_amq_server_connection_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_FREE))
static icl_stats_t *s_amq_server_connection_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_OWN_QUEUE))
static icl_stats_t *s_amq_server_connection_own_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_UNBIND_QUEUE))
static icl_stats_t *s_amq_server_connection_unbind_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_READY))
static icl_stats_t *s_amq_server_connection_ready_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_START_OK))
static icl_stats_t *s_amq_server_connection_start_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_OPEN))
static icl_stats_t *s_amq_server_connection_open_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_INITIALISE))
static icl_stats_t *s_amq_server_connection_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_SET_ADDRESS))
static icl_stats_t *s_amq_server_connection_set_address_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_SET_TRACE))
static icl_stats_t *s_amq_server_connection_set_trace_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_KILL))
static icl_stats_t *s_amq_server_connection_kill_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_RAISE_EXCEPTION))
static icl_stats_t *s_amq_server_connection_raise_exception_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_ERROR))
static icl_stats_t *s_amq_server_connection_error_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_EXCEPTION_RAISED))
static icl_stats_t *s_amq_server_connection_exception_raised_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_TUNE_OK))
static icl_stats_t *s_amq_server_connection_tune_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_SELFTEST))
static icl_stats_t *s_amq_server_connection_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_COUNT))
static icl_stats_t *s_amq_server_connection_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_amq_server_connection_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_SHOW))
static icl_stats_t *s_amq_server_connection_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_TERMINATE))
static icl_stats_t *s_amq_server_connection_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_DESTROY_PUBLIC))
static icl_stats_t *s_amq_server_connection_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_ALLOC))
static icl_stats_t *s_amq_server_connection_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_READ_LOCK))
static icl_stats_t *s_amq_server_connection_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_WRITE_LOCK))
static icl_stats_t *s_amq_server_connection_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_UNLOCK))
static icl_stats_t *s_amq_server_connection_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_LINK))
static icl_stats_t *s_amq_server_connection_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_UNLINK))
static icl_stats_t *s_amq_server_connection_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_CACHE_INITIALISE))
static icl_stats_t *s_amq_server_connection_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_CACHE_PURGE))
static icl_stats_t *s_amq_server_connection_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_CACHE_TERMINATE))
static icl_stats_t *s_amq_server_connection_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_ANIMATE))
static icl_stats_t *s_amq_server_connection_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_NEW_IN_SCOPE))
static icl_stats_t *s_amq_server_connection_new_in_scope_stats = NULL;
#endif
#define amq_server_connection_annihilate(self)  amq_server_connection_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_server_connection_annihilate_ (
amq_server_connection_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_server_connection_free(self)  amq_server_connection_free_ (self, __FILE__, __LINE__)
static void
    amq_server_connection_free_ (
amq_server_connection_t * self,         //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_server_connection_initialise (
void);

static void
    amq_server_connection_terminate (
void);

#define amq_server_connection_alloc()   amq_server_connection_alloc_ (__FILE__, __LINE__)
static amq_server_connection_t *
    amq_server_connection_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_server_connection_cache_initialise (
void);

static void
    amq_server_connection_cache_purge (
void);

static void
    amq_server_connection_cache_terminate (
void);

Bool
    amq_server_connection_animating = TRUE;  //  Animation enabled by default
static Bool
    s_amq_server_connection_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_server_connection_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static qbyte
    s_amq_server_connection_count = 0;
static int
    s_auth_plain (amq_server_connection_t *self, amq_server_connection_start_ok_t *method);
static uint
    s_collect_plain_token (byte *data, char *token, uint token_end);
static volatile qbyte
    s_context_seq_lo,                   //  Next context sequence id
    s_context_seq_hi;                   //  High part (64-bits)
//  Sets and returns connection group, zero indicating an error

static int s_auth_plain (
    amq_server_connection_t *self,
    amq_server_connection_start_ok_t *method)
{
    icl_shortstr_t
        login,
        password;
    uint
        token_null;
    char
        *group;                         //  Group name from config
    ipr_config_t
        *config;                        //  Current server config file

    //  method->response holds PLAIN data in format "[NULL]login[NULL]password"
    token_null = s_collect_plain_token (
        method->response->data, password, method->response->cur_size);
    if (token_null)
        s_collect_plain_token (method->response->data, login, token_null);

    if (strnull (login) || strnull (password)) {
        self_raise_exception (self, ASL_SYNTAX_ERROR, 
            "Missing authentication data",
            AMQ_SERVER_CONNECTION, AMQ_SERVER_CONNECTION_START_OK);
        return (0);
    }
    config = ipr_config_dup (amq_server_config->config);
    ipr_config_locate (config, "/config/security", "plain");
    if (!config->located) {
        smt_log_print (amq_broker->alert_log,
            "E: no 'plain' security defined in server config");
        self_raise_exception (self, ASL_INTERNAL_ERROR, 
            "Bad server configuration", 0, 0);
        return (0);
    }
    //  Now check user login and password and set group if found
    ipr_config_locate (config, "user", NULL);
    while (config->located) {
        if (streq (login,    ipr_config_get (config, "name", ""))
        &&  streq (password, ipr_config_get (config, "password", ""))) {
            icl_shortstr_cpy (self->user_name, login);
            group = ipr_config_get (config, "group", "");
            if (streq (group, "normal"))
                self->group = AMQ_CONNECTION_GROUP_NORMAL;
            else
            if (streq (group, "super"))
                self->group = AMQ_CONNECTION_GROUP_SUPER;
            else {
                smt_log_print (amq_broker->alert_log,
                    "E: invalid user group '%s' in config", group);
                self_raise_exception (self, ASL_INTERNAL_ERROR, 
                    "Bad server configuration", 0, 0);
            }
            smt_log_print (amq_broker->daily_log,
                "I: valid login from=%s user=%s group=%s", self->client_address, login, group);
            break;
        }
        ipr_config_next (config);
    }
    ipr_config_destroy (&config);
    return (self->group);
}

//  Collects a token, returns offset of null octet at start
static uint
s_collect_plain_token (byte *data, char *token, uint token_end)
{
    uint
        token_null,
        token_size;

    //  Find start of token, scanning back from known end
    token_null = --token_end;
    while (token_null && data [token_null])
        token_null--;

    strclr (token);
    //  Token start must point to a null octet before the string
    token_size = token_end - token_null;
    if (token_size > ICL_SHORTSTR_MAX)
        smt_log_print (amq_broker->alert_log,
            "W: client used over-long authentication value - rejected");
    else {
        memcpy (token, data + token_null + 1, token_size);
        token [token_size] = 0;
    }
    return (token_null);
}
/*  -------------------------------------------------------------------------
    amq_server_connection_new

    Type: Component method
    Creates and initialises a new amq_server_connection_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

amq_server_connection_t *
    amq_server_connection_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_server_connection_table_t * table,   //  Table to insert into
    smt_thread_t * thread               //  Parent thread
)
{
#define key self->id
qbyte
    seq_lo,
    seq_hi;
    amq_server_connection_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_NEW))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_NEW))
    icl_trace_record (NULL, amq_server_connection_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_NEW))
    icl_stats_inc ("amq_server_connection_new", &s_amq_server_connection_new_stats);
#endif

if (!s_amq_server_connection_active)
    self_initialise ();
    self = amq_server_connection_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_SERVER_CONNECTION_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_server_connection_show_);
#endif

self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
icl_atomic_inc32 ((volatile qbyte *) &s_amq_server_connection_count);

//
if (thread)
    self->thread  = smt_thread_link (thread);
self->started     = smt_time_now ();
self->channel_max = 1;              //  We only support one channel 
self->frame_max   = amq_server_config_frame_max (amq_server_config);
self->heartbeat   = amq_server_config_heartbeat (amq_server_config);
self->trace       = amq_server_config_trace (amq_server_config);
self->channels    = amq_server_channel_table_new ();

//  Get 64-bit connection id, no wraparound handling
seq_lo = icl_atomic_inc32 (&s_context_seq_lo);
if (seq_lo == 0)
    seq_hi = icl_atomic_inc32 (&s_context_seq_hi);
else
    seq_hi = s_context_seq_hi;
icl_shortstr_fmt (self->id, "%x-%x", seq_hi, seq_lo);

self->own_queue_list = amq_queue_list_new ();
self->consumer_table = amq_consumer_table_new ();
if (table && self && amq_server_connection_table_insert (table, key, self))
    amq_server_connection_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_NEW))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_NEW))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" thread=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, thread, self);
#endif


    return (self);
}
#undef key
/*  -------------------------------------------------------------------------
    amq_server_connection_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_connection_annihilate_ (
    amq_server_connection_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
    int
        history_last;
#endif

amq_queue_list_iter_t *
   iterator;
    amq_server_connection_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_DESTROY))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_DESTROY))
    icl_trace_record (NULL, amq_server_connection_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_DESTROY))
    icl_stats_inc ("amq_server_connection_annihilate", &s_amq_server_connection_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = self->links;
#endif

    AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
    amq_server_connection_remove_from_all_containers (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

icl_atomic_dec32 ((volatile qbyte *) &s_amq_server_connection_count);

//  This closes all channels when we call destroy on the connection
amq_server_channel_table_destroy (&self->channels);

//
//  Firstly, send notification of connection termination to all
//  exclusive queues created by the connection, so that they can be
//  destroyed even if there is no consumer on the queue.
for (iterator = amq_queue_list_first (self->own_queue_list);
      iterator != NULL;
      iterator = amq_queue_list_next (&iterator))
    amq_queue_unbind_connection (iterator->item);

amq_vhost_unlink       (&self->vhost);
amq_queue_list_destroy (&self->own_queue_list);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_DESTROY))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_DESTROY))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_destroy_finish"
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

}
/*  -------------------------------------------------------------------------
    amq_server_connection_free

    Type: Component method
    Freess a amq_server_connection_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_server_connection_free_ (
    amq_server_connection_t * self,     //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_FREE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_FREE))
    icl_trace_record (NULL, amq_server_connection_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_FREE))
    icl_stats_inc ("amq_server_connection_free", &s_amq_server_connection_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = self->links;
#endif

//  This ensures the thread is valid until the connection is no longer used
smt_thread_unlink (&self->thread);

amq_consumer_table_destroy (&self->consumer_table);
#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (amq_server_connection_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_server_connection_t));
        self->object_tag = AMQ_SERVER_CONNECTION_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_FREE))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_FREE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_free_finish"
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
    amq_server_connection_own_queue

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_own_queue (
    amq_server_connection_t * self,     //  Reference to object
    amq_queue_t * queue                 //  Queue reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_OWN_QUEUE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_own_queue_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_OWN_QUEUE))
    icl_trace_record (NULL, amq_server_connection_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_OWN_QUEUE))
    icl_stats_inc ("amq_server_connection_own_queue", &s_amq_server_connection_own_queue_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

assert (queue->exclusive);
amq_queue_list_queue (self->own_queue_list, queue);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_OWN_QUEUE))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_OWN_QUEUE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_own_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_connection_unbind_queue

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Unbind a queue from the connection.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_unbind_queue (
    amq_server_connection_t * self,     //  Reference to object
    amq_queue_t * queue                 //  The queue to unbind
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

amq_queue_list_iter_t *
    iterator;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_UNBIND_QUEUE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_unbind_queue_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNBIND_QUEUE))
    icl_trace_record (NULL, amq_server_connection_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_UNBIND_QUEUE))
    icl_stats_inc ("amq_server_connection_unbind_queue", &s_amq_server_connection_unbind_queue_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
//  Remove the queue from the list of exclusive connections
iterator = amq_queue_list_find (self->own_queue_list, queue);
if (iterator)
    amq_queue_list_iter_destroy (&iterator);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNBIND_QUEUE))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_UNBIND_QUEUE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_unbind_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_connection_ready

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_ready (
    amq_server_connection_t * self      //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_READY))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_ready_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_READY))
    icl_trace_record (NULL, amq_server_connection_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_READY))
    icl_stats_inc ("amq_server_connection_ready", &s_amq_server_connection_ready_stats);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

rc = TRUE;

rc = TRUE;
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_READY))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_READY))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_ready_finish"
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
    amq_server_connection_start_ok

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Implements the ASL Connection.Start-Ok protocol method.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_start_ok (
    amq_server_connection_t * self,     //  Reference to object
    amq_server_connection_start_ok_t * method  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

asl_field_list_t
    *fields;                        //  Decoded responses
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_START_OK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_start_ok_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_START_OK))
    icl_trace_record (NULL, amq_server_connection_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_START_OK))
    icl_stats_inc ("amq_server_connection_start_ok", &s_amq_server_connection_start_ok_stats);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

//
self->authorised = FALSE;
fields = asl_field_list_new (method->client_properties);
if (fields) {
    asl_field_list_cpy (fields, self->client_product,     "product");
    asl_field_list_cpy (fields, self->client_version,     "version");
    asl_field_list_cpy (fields, self->client_platform,    "platform");
    asl_field_list_cpy (fields, self->client_copyright,   "copyright");
    asl_field_list_cpy (fields, self->client_information, "information");
    //  Optionally, we could handle the following cases:
    //  1. duplicate connection instance name
    //  2. empty connection instance name
    asl_field_list_cpy (fields, self->client_instance,    "instance");
    asl_field_list_cpy (fields, self->client_proxy_name,  "proxy name");
    asl_field_list_cpy (fields, self->client_proxy_host,  "proxy host");
    asl_field_list_destroy (&fields);
}

//
//  Server only supports plain authentication for now
//
smt_log_print (amq_broker->daily_log,
    "I: start login from=%s product=%s version=%s",
    self->client_address, self->client_product, self->client_version);

if (s_auth_plain (self, method))
    self->authorised = TRUE;
else
    self_raise_exception (self, ASL_ACCESS_REFUSED, 
        "Invalid authentication data",
        AMQ_SERVER_CONNECTION, AMQ_SERVER_CONNECTION_START_OK);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_START_OK))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_START_OK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_start_ok_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_connection_open

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Implements the ASL Connection.Open protocol method.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_open (
    amq_server_connection_t * self,     //  Reference to object
    amq_server_connection_open_t * method  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_OPEN))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_open_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_OPEN))
    icl_trace_record (NULL, amq_server_connection_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_OPEN))
    icl_stats_inc ("amq_server_connection_open", &s_amq_server_connection_open_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//  For now, link to single global vhost object
self->vhost = amq_vhost_link (amq_broker->vhost);

if (!self->vhost)
    self_raise_exception (self, ASL_ACCESS_REFUSED, 
        "Server is not ready",
        AMQ_SERVER_CONNECTION, AMQ_SERVER_CONNECTION_OPEN);
else
//  If locked, allow only super user access
if (amq_broker->locked && self->group == AMQ_CONNECTION_GROUP_NORMAL)
    self_raise_exception (self, ASL_ACCESS_REFUSED, 
        "Connections not allowed at present",
        AMQ_SERVER_CONNECTION, AMQ_SERVER_CONNECTION_OPEN);
else
if (strneq (method->virtual_host, amq_server_config_vhost (amq_server_config))) {
    smt_log_print (amq_broker->alert_log,
        "E: client at %s tried to connect to invalid vhost '%s'",
        self->client_address, method->virtual_host);
    self_raise_exception (self, ASL_INVALID_PATH, "vhost is incorrect",
        AMQ_SERVER_CONNECTION, AMQ_SERVER_CONNECTION_OPEN);
}
else
if (amq_broker->failover->enabled) {
    //  Application connections send an event to the failover FSM.
    //  Failover state machine determines whether connection should 
    //  be accepted or rejected
    if (self->group == AMQ_CONNECTION_GROUP_NORMAL) {
        if (!amq_failover_execute (amq_broker->failover, amq_ha_event_new_connection))
            self_raise_exception (self, ASL_ACCESS_REFUSED,
                "Connections not allowed at present",
                AMQ_SERVER_CONNECTION, AMQ_SERVER_CONNECTION_OPEN);
    }
}
else
    rc = TRUE;                      //  Proceed
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_OPEN))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_OPEN))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_open_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_connection_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_connection_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_INITIALISE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_INITIALISE))
    icl_trace_record (NULL, amq_server_connection_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_INITIALISE))
    icl_stats_inc ("amq_server_connection_initialise", &s_amq_server_connection_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_server_connection_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_server_connection_mutex)
            s_amq_server_connection_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_server_connection_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_server_connection_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

s_context_seq_hi = 0;
s_context_seq_lo = 1;
            s_amq_server_connection_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_server_connection_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_INITIALISE))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_INITIALISE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_initialise_finish"
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
    amq_server_connection_set_address

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the connection's address string, which can be used for logging
    and reporting.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_set_address (
    amq_server_connection_t * self,     //  Reference to object
    char * address                      //  Client address
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_SET_ADDRESS))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_set_address_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" address=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, address);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SET_ADDRESS))
    icl_trace_record (NULL, amq_server_connection_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_SET_ADDRESS))
    icl_stats_inc ("amq_server_connection_set_address", &s_amq_server_connection_set_address_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
icl_shortstr_cpy (self->client_address, address);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SET_ADDRESS))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_SET_ADDRESS))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_set_address_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" address=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, address, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_connection_set_trace

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the connection's trace level, used to determine the logging done
    at the connection thread level (in the server agent).
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_set_trace (
    amq_server_connection_t * self,     //  Reference to object
    int trace                           //  Desired trace level
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_SET_TRACE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_set_trace_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" trace=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, trace);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SET_TRACE))
    icl_trace_record (NULL, amq_server_connection_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_SET_TRACE))
    icl_stats_inc ("amq_server_connection_set_trace", &s_amq_server_connection_set_trace_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
amq_server_agent_set_trace (self->thread, trace);
self->trace = trace;                //  Last known value
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SET_TRACE))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_SET_TRACE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_set_trace_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" trace=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, trace, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_connection_kill

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Kills the connection by sending a connection-kill method to the
    agent.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_kill (
    amq_server_connection_t * self      //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_KILL))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_kill_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_KILL))
    icl_trace_record (NULL, amq_server_connection_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_KILL))
    icl_stats_inc ("amq_server_connection_kill", &s_amq_server_connection_kill_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
amq_server_agent_kill_connection (self->thread);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_KILL))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_KILL))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_kill_finish"
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
    amq_server_connection_raise_exception

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Raise a connection exception.  This method is for internal use by 
    the connection class or server agent only.  External callers should 
    call the "error" method instead.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_raise_exception (
    amq_server_connection_t * self,     //  Reference to object
    dbyte reply_code,                   //  Error code
    char * reply_text,                  //  Error text
    dbyte faulting_method_id,           //  Faulting method id
    dbyte faulting_class_id             //  Faulting class id
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_RAISE_EXCEPTION))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_raise_exception_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_text);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_RAISE_EXCEPTION))
    icl_trace_record (NULL, amq_server_connection_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_RAISE_EXCEPTION))
    icl_stats_inc ("amq_server_connection_raise_exception", &s_amq_server_connection_raise_exception_stats);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
//  TODO Find a way to assert this is not being called from the wrong place
self->exception_raised  = TRUE;
self->reply_code = reply_code;
icl_shortstr_cpy (self->reply_text, reply_text);
self->faulting_class_id = faulting_class_id;
self->faulting_method_id = faulting_method_id;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_RAISE_EXCEPTION))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_RAISE_EXCEPTION))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_raise_exception_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_text=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_text, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_connection_error

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Raise a connection exception.  This method is for external use only,
    internal callers should call the "raise exception" method instead.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_error (
    amq_server_connection_t * self,     //  Reference to object
    dbyte reply_code,                   //  Error code
    char * reply_text,                  //  Error text
    dbyte faulting_method_id,           //  Faulting method id
    dbyte faulting_class_id             //  Faulting class id
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_ERROR))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_error_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_text);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ERROR))
    icl_trace_record (NULL, amq_server_connection_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_ERROR))
    icl_stats_inc ("amq_server_connection_error", &s_amq_server_connection_error_stats);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
amq_server_agent_connection_error (self->thread, reply_code, reply_text,
    faulting_method_id, faulting_class_id);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ERROR))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_ERROR))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_error_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_text=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_text, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_connection_exception_raised

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Returns TRUE if a connection exception has been raised.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_exception_raised (
    amq_server_connection_t * self      //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_EXCEPTION_RAISED))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_exception_raised_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_EXCEPTION_RAISED))
    icl_trace_record (NULL, amq_server_connection_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_EXCEPTION_RAISED))
    icl_stats_inc ("amq_server_connection_exception_raised", &s_amq_server_connection_exception_raised_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

rc = self->exception_raised;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_EXCEPTION_RAISED))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_EXCEPTION_RAISED))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_exception_raised_finish"
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
    amq_server_connection_tune_ok

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Implements the ASL Connection.Tune-Ok protocol method.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_tune_ok (
    amq_server_connection_t * self,     //  Reference to object
    amq_server_connection_tune_ok_t * method  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_TUNE_OK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_tune_ok_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_TUNE_OK))
    icl_trace_record (NULL, amq_server_connection_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_TUNE_OK))
    icl_stats_inc ("amq_server_connection_tune_ok", &s_amq_server_connection_tune_ok_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
self->heartbeat = method->heartbeat;
self->frame_max = method->frame_max;
if (self->frame_max < ASL_FRAME_MIN_SIZE
&&  self->frame_max > 0)
    self->frame_max = ASL_FRAME_MIN_SIZE;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_TUNE_OK))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_TUNE_OK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_tune_ok_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_connection_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_connection_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_SELFTEST))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SELFTEST))
    icl_trace_record (NULL, amq_server_connection_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_SELFTEST))
    icl_stats_inc ("amq_server_connection_selftest", &s_amq_server_connection_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SELFTEST))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_SELFTEST))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_selftest_finish"
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
    amq_server_connection_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_server_connection_count (
void)
{
    qbyte
        count;                          //  Number of instances

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_COUNT))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_count_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_COUNT))
    icl_trace_record (NULL, amq_server_connection_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_COUNT))
    icl_stats_inc ("amq_server_connection_count", &s_amq_server_connection_count_stats);
#endif

count = (int) s_amq_server_connection_count;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_COUNT))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_COUNT))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_count_finish"
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
    amq_server_connection_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_server_connection_remove_from_all_containers (
    amq_server_connection_t * self      //  The itemThe item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_server_connection_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("amq_server_connection_remove_from_all_containers", &s_amq_server_connection_remove_from_all_containers_stats);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
amq_server_connection_table_remove (self);
amq_server_connection_list_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_remove_from_all_containers_finish"
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
    amq_server_connection_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_connection_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_server_connection_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_SHOW))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SHOW))
    icl_trace_record (NULL, amq_server_connection_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_SHOW))
    icl_stats_inc ("amq_server_connection_show", &s_amq_server_connection_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
if (self->list_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_server_connection zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
    if (self->history_last > AMQ_SERVER_CONNECTION_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_SERVER_CONNECTION_HISTORY_LENGTH;
        self->history_last %= AMQ_SERVER_CONNECTION_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_SERVER_CONNECTION_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_server_connection>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SHOW))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_SHOW))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_show_finish"
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
    amq_server_connection_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_connection_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_TERMINATE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_TERMINATE))
    icl_trace_record (NULL, amq_server_connection_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_TERMINATE))
    icl_stats_inc ("amq_server_connection_terminate", &s_amq_server_connection_terminate_stats);
#endif

if (s_amq_server_connection_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_server_connection_mutex);
#endif
        s_amq_server_connection_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_TERMINATE))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_TERMINATE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_terminate_finish"
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
    amq_server_connection_destroy

    Type: Component method
    Destroys a amq_server_connection_t object. Takes the address of a
    amq_server_connection_t reference (a pointer to a pointer) and nullifies the
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
    amq_server_connection_destroy_ (
    amq_server_connection_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_server_connection_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_DESTROY_PUBLIC))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_server_connection_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_DESTROY_PUBLIC))
    icl_stats_inc ("amq_server_connection_destroy", &s_amq_server_connection_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_server_connection_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on amq_server_connection object");
        amq_server_connection_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_server_connection_free_ ((amq_server_connection_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_DESTROY_PUBLIC))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_connection_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_server_connection_t *
    amq_server_connection_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_server_connection_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_ALLOC))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ALLOC))
    icl_trace_record (NULL, amq_server_connection_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_ALLOC))
    icl_stats_inc ("amq_server_connection_alloc", &s_amq_server_connection_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_server_connection_cache_initialise ();

self = (amq_server_connection_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_server_connection_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ALLOC))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_ALLOC))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_alloc_finish"
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
    amq_server_connection_read_lock

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_read_lock (
    amq_server_connection_t * self      //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_READ_LOCK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_READ_LOCK))
    icl_trace_record (NULL, amq_server_connection_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_READ_LOCK))
    icl_stats_inc ("amq_server_connection_read_lock", &s_amq_server_connection_read_lock_stats);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_READ_LOCK))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_READ_LOCK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_read_lock_finish"
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
    amq_server_connection_write_lock

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_write_lock (
    amq_server_connection_t * self      //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_WRITE_LOCK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_WRITE_LOCK))
    icl_trace_record (NULL, amq_server_connection_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_WRITE_LOCK))
    icl_stats_inc ("amq_server_connection_write_lock", &s_amq_server_connection_write_lock_stats);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_WRITE_LOCK))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_WRITE_LOCK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_write_lock_finish"
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
    amq_server_connection_unlock

    Type: Component method
    Accepts a amq_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_connection_unlock (
    amq_server_connection_t * self      //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_UNLOCK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNLOCK))
    icl_trace_record (NULL, amq_server_connection_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_UNLOCK))
    icl_stats_inc ("amq_server_connection_unlock", &s_amq_server_connection_unlock_stats);
#endif

AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNLOCK))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_UNLOCK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_unlock_finish"
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
    amq_server_connection_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_server_connection_t *
    amq_server_connection_link_ (
    amq_server_connection_t * self,     //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_LINK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LINK))
    icl_trace_record (NULL, amq_server_connection_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_LINK))
    icl_stats_inc ("amq_server_connection_link", &s_amq_server_connection_link_stats);
#endif

    if (self) {
        AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LINK))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_LINK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_link_finish"
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
    amq_server_connection_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_server_connection_unlink_ (
    amq_server_connection_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
    int
        history_last;
#endif

    amq_server_connection_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_UNLINK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNLINK))
    icl_trace_record (NULL, amq_server_connection_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_UNLINK))
    icl_stats_inc ("amq_server_connection_unlink", &s_amq_server_connection_unlink_stats);
#endif

    if (self) {
        AMQ_SERVER_CONNECTION_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_server_connection object");
            amq_server_connection_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_SERVER_CONNECTION_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_server_connection_annihilate_ (self_p, file, line);
        amq_server_connection_free_ ((amq_server_connection_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNLINK))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_UNLINK))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_unlink_finish"
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
    amq_server_connection_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_server_connection_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_CACHE_INITIALISE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_server_connection_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_CACHE_INITIALISE))
    icl_stats_inc ("amq_server_connection_cache_initialise", &s_amq_server_connection_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_server_connection_t));
icl_system_register (amq_server_connection_cache_purge, amq_server_connection_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_CACHE_INITIALISE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_cache_initialise_finish"
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
    amq_server_connection_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_connection_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_CACHE_PURGE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_PURGE))
    icl_trace_record (NULL, amq_server_connection_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_CACHE_PURGE))
    icl_stats_inc ("amq_server_connection_cache_purge", &s_amq_server_connection_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_PURGE))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_CACHE_PURGE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_cache_purge_finish"
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
    amq_server_connection_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_connection_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_CACHE_TERMINATE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_server_connection_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_CACHE_TERMINATE))
    icl_stats_inc ("amq_server_connection_cache_terminate", &s_amq_server_connection_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_CACHE_TERMINATE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_cache_terminate_finish"
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
    amq_server_connection_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_server_connection_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_ANIMATE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ANIMATE))
    icl_trace_record (NULL, amq_server_connection_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_ANIMATE))
    icl_stats_inc ("amq_server_connection_animate", &s_amq_server_connection_animate_stats);
#endif

amq_server_connection_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ANIMATE))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_ANIMATE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_animate_finish"
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
    amq_server_connection_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_connection_new_in_scope_ (
    amq_server_connection_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_server_connection_table_t * table,   //  Table to insert into
    smt_thread_t * thread               //  Parent thread
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_NEW_IN_SCOPE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_server_connection_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION)  ||  defined (BASE_STATS_AMQ_SERVER_CONNECTION_NEW_IN_SCOPE))
    icl_stats_inc ("amq_server_connection_new_in_scope", &s_amq_server_connection_new_in_scope_stats);
#endif

*self_p = amq_server_connection_new_ (file,line,table,thread);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_server_connection_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_server_connection_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION)   || defined (BASE_ANIMATE_AMQ_SERVER_CONNECTION_NEW_IN_SCOPE))
    if (amq_server_connection_animating)
        icl_console_print ("<amq_server_connection_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" thread=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, thread, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_NEW)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_DESTROY)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_FREE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_OWN_QUEUE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNBIND_QUEUE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_READY)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_START_OK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_OPEN)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_INITIALISE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SET_ADDRESS)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SET_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_KILL)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_RAISE_EXCEPTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ERROR)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_EXCEPTION_RAISED)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_TUNE_OK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SELFTEST)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_COUNT)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SHOW)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ALLOC)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_READ_LOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNLOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LINK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNLINK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ANIMATE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_NEW_IN_SCOPE) )
void
amq_server_connection_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "free"; break;
        case 4: method_name = "own queue"; break;
        case 5: method_name = "unbind queue"; break;
        case 6: method_name = "ready"; break;
        case 7: method_name = "start ok"; break;
        case 8: method_name = "open"; break;
        case 9: method_name = "initialise"; break;
        case 10: method_name = "set address"; break;
        case 11: method_name = "set trace"; break;
        case 12: method_name = "kill"; break;
        case 13: method_name = "raise exception"; break;
        case 14: method_name = "error"; break;
        case 15: method_name = "exception raised"; break;
        case 16: method_name = "tune ok"; break;
        case 17: method_name = "selftest"; break;
        case 18: method_name = "count"; break;
        case 19: method_name = "remove from all containers"; break;
        case 20: method_name = "show"; break;
        case 21: method_name = "terminate"; break;
        case 22: method_name = "destroy public"; break;
        case 23: method_name = "alloc"; break;
        case 24: method_name = "read lock"; break;
        case 25: method_name = "write lock"; break;
        case 26: method_name = "unlock"; break;
        case 27: method_name = "link"; break;
        case 28: method_name = "unlink"; break;
        case 29: method_name = "cache initialise"; break;
        case 30: method_name = "cache purge"; break;
        case 31: method_name = "cache terminate"; break;
        case 32: method_name = "animate"; break;
        case 33: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_server_connection %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_server_connection_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_server_connection_component  = "amq_server_connection ";
char *amq_server_connection_version  = "1.0 ";
char *amq_server_connection_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_server_connection_filename  = "amq_server_connection.icl ";
char *amq_server_connection_builddate  = "2010/10/06 ";
char *amq_server_connection_version_end  = "VeRsIoNeNd:ipc";

