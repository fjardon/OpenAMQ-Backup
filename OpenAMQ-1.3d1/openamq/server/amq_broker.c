/*---------------------------------------------------------------------------
    amq_broker.c - amq_broker component

    Generated from amq_broker.icl by smt_object_gen using GSL/4.
    
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
#include "amq_broker.h"                 //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_broker_t

//  Shorthands for class methods                                               

#define self_new            amq_broker_new
#define self_annihilate     amq_broker_annihilate
#define self_unbind_queue   amq_broker_unbind_queue
#define self_selftest       amq_broker_selftest
#define self_inspect_shim   amq_broker_inspect_shim
#define self_inspect        amq_broker_inspect
#define self_modify_shim    amq_broker_modify_shim
#define self_modify         amq_broker_modify
#define self_method_shim    amq_broker_method_shim
#define self_method         amq_broker_method
#define self_unlink_shim    amq_broker_unlink_shim
#define self_initialise     amq_broker_initialise
#define self_terminate      amq_broker_terminate
#define self_free           amq_broker_free
#define self_start          amq_broker_start
#define self_shutdown       amq_broker_shutdown
#define self_destroy        amq_broker_destroy
#define self_unlink         amq_broker_unlink
#define self_animate        amq_broker_animate
#define self_show           amq_broker_show
#define self_alloc          amq_broker_alloc
#define self_link           amq_broker_link
#define self_cache_initialise  amq_broker_cache_initialise
#define self_cache_purge    amq_broker_cache_purge
#define self_cache_terminate  amq_broker_cache_terminate
#define self_new_in_scope   amq_broker_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_NEW))
static icl_stats_t *s_amq_broker_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_DESTROY))
static icl_stats_t *s_amq_broker_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_UNBIND_QUEUE))
static icl_stats_t *s_amq_broker_unbind_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_SELFTEST))
static icl_stats_t *s_amq_broker_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_INSPECT_SHIM))
static icl_stats_t *s_amq_broker_inspect_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_INSPECT))
static icl_stats_t *s_amq_broker_inspect_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_MODIFY_SHIM))
static icl_stats_t *s_amq_broker_modify_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_MODIFY))
static icl_stats_t *s_amq_broker_modify_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_METHOD_SHIM))
static icl_stats_t *s_amq_broker_method_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_METHOD))
static icl_stats_t *s_amq_broker_method_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_UNLINK_SHIM))
static icl_stats_t *s_amq_broker_unlink_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_INITIALISE))
static icl_stats_t *s_amq_broker_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_TERMINATE))
static icl_stats_t *s_amq_broker_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_FREE))
static icl_stats_t *s_amq_broker_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_START))
static icl_stats_t *s_amq_broker_start_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_SHUTDOWN))
static icl_stats_t *s_amq_broker_shutdown_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_DESTROY_PUBLIC))
static icl_stats_t *s_amq_broker_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_UNLINK))
static icl_stats_t *s_amq_broker_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_ANIMATE))
static icl_stats_t *s_amq_broker_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_SHOW))
static icl_stats_t *s_amq_broker_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_ALLOC))
static icl_stats_t *s_amq_broker_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_LINK))
static icl_stats_t *s_amq_broker_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_CACHE_INITIALISE))
static icl_stats_t *s_amq_broker_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_CACHE_PURGE))
static icl_stats_t *s_amq_broker_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_CACHE_TERMINATE))
static icl_stats_t *s_amq_broker_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_NEW_IN_SCOPE))
static icl_stats_t *s_amq_broker_new_in_scope_stats = NULL;
#endif
#define amq_broker_annihilate(self)     amq_broker_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_broker_annihilate_ (
amq_broker_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_broker_initialise (
void);

#define amq_broker_alloc()              amq_broker_alloc_ (__FILE__, __LINE__)
static amq_broker_t *
    amq_broker_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_broker_cache_initialise (
void);

static void
    amq_broker_cache_purge (
void);

static void
    amq_broker_cache_terminate (
void);

Bool
    amq_broker_animating = TRUE;        //  Animation enabled by default
static Bool
    s_amq_broker_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_broker_mutex       = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static void
    s_format_logfile (char *logfile, char *configured);
static amq_console_class_t
    *s_class;                           //  Class descriptor
amq_broker_t
    *amq_broker = NULL;
/*  -------------------------------------------------------------------------
    amq_broker_new

    Type: Component method
    Creates and initialises a new amq_broker_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_broker_t *
    amq_broker_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
char
    *log_path,                      //  Log directory
    *archive_path,                  //  Archive directory
    *archive_cmd;                   //  Archive command
icl_shortstr_t
    log_name,                       //  Full logfile name
    stats_file;                     //  Statistics file name
smt_thread_t
    *thread_p;                      //  Thread from amq_server_server_agent
    amq_broker_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_NEW))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_NEW))
    icl_trace_record (NULL, amq_broker_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_NEW))
    icl_stats_inc ("amq_broker_new", &s_amq_broker_new_stats);
#endif

if (!s_amq_broker_active)
    self_initialise ();
    self = amq_broker_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_BROKER_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_broker_show_);
#endif

self->console = amq_console_link (amq_console);
self->object_id = icl_atomic_inc32 ((volatile qbyte *) &amq_object_id);
amq_console_register (self->console, self->object_id, self_link (self), s_class, 0);
self->thread = amq_broker_agent_class_thread_new (self);
self->thread->animate = TRUE;

//
//  Set self so that we're immediately addressable in other threads
amq_broker = self;

self->started         = smt_time_now ();
self->connections     = amq_server_connection_table_new ();
self->connection_list = amq_server_connection_list_new ();
self->monitor_timer   = amq_server_config_monitor (amq_server_config);
self->imeter          = ipr_meter_new ();
self->ometer          = ipr_meter_new ();

//  Set up log files and log forwarding:
log_path     = amq_server_config_log_path      (amq_server_config);
archive_path = amq_server_config_archive_path (amq_server_config);
archive_cmd  = amq_server_config_archive_cmd   (amq_server_config);

self->debug_log = smt_log_new ();   //  Debug log for low-level trace
self->daily_log = smt_log_new ();   //  Daily log for normal activity
self->alert_log = smt_log_new ();   //  Alert log for exceptions

if (amq_server_config_keep_logs (amq_server_config)) {
    s_format_logfile (log_name, amq_server_config_debug_log (amq_server_config));
    smt_log_open (self->debug_log, log_name, log_path, archive_path, archive_cmd);
    s_format_logfile (log_name, amq_server_config_daily_log (amq_server_config));
    smt_log_open (self->daily_log, log_name, log_path, archive_path, archive_cmd);
    s_format_logfile (log_name, amq_server_config_alert_log (amq_server_config));
    smt_log_open (self->alert_log, log_name, log_path, archive_path, archive_cmd);
}
//  Dump environment and configuration to debug log, silently
smt_log_dump_env (self->debug_log);
amq_server_config_dump_log (amq_server_config, self->debug_log);

//  Set up log file associations and configuration
smt_log_pedantic (self->debug_log, TRUE);
smt_log_set_cc   (self->daily_log, self->debug_log);
smt_log_pedantic (self->alert_log, TRUE);
smt_log_set_cc   (self->alert_log, self->daily_log);

if (amq_server_config_record_stats (amq_server_config)) {
    icl_shortstr_fmt (stats_file, "amq_server_stats_%s.del",
        amq_server_config_port (amq_server_config));
    self->stats = fopen (stats_file, "w");
    //  We use a tab-delimited form that pastes easily into spreadsheets
    fprintf (self->stats, "Clients\tMsgMemK\tCurIn\tCurOut\tAvgIn\tAvgOut\n");
}
//  Start server agent and own async thread
if (amq_server_agent_init (&thread_p) == SMT_OK) {
    self->agent_thread = smt_thread_link (thread_p);
    self_start (self);
}

//  We use a single global vhost for now
self->vhost = amq_vhost_new (self, "/");
self->dump_state_timer = amq_server_config_dump_state (amq_server_config);
self->auto_crash_timer = amq_server_config_auto_crash (amq_server_config);
self->auto_block_timer = amq_server_config_auto_block (amq_server_config);
self->mgt_connection_list = amq_connection_by_broker_new ();
amq_console_config = amq_console_config_new (self);

randomize ();
if (self->auto_crash_timer)
    self->auto_crash_timer = randomof (self->auto_crash_timer) + 1;
if (self->auto_block_timer)
    self->auto_block_timer = randomof (self->auto_block_timer) + 1;

//  Initialise failover agent
self->failover = amq_failover_new (self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_NEW))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_NEW))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_new_finish"
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
    amq_broker_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_broker_annihilate_ (
    amq_broker_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    int
        history_last;
#endif

    amq_broker_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_DESTROY))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_DESTROY))
    icl_trace_record (NULL, amq_broker_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_DESTROY))
    icl_stats_inc ("amq_broker_annihilate", &s_amq_broker_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_BROKER_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_BROKER_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_BROKER_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_BROKER_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (amq_broker_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_DESTROY))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_DESTROY))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_destroy_finish"
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
    amq_broker_unbind_queue

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Unbind a queue from the broker.
    -------------------------------------------------------------------------
 */

int
    amq_broker_unbind_queue (
    amq_broker_t * self,                //  Reference to object
    amq_queue_t * queue                 //  The queue to unbind
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_UNBIND_QUEUE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_unbind_queue_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_UNBIND_QUEUE))
    icl_trace_record (NULL, amq_broker_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_UNBIND_QUEUE))
    icl_stats_inc ("amq_broker_unbind_queue", &s_amq_broker_unbind_queue_stats);
#endif

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_broker_agent_unbind_queue (self->thread,queue)) {
        //icl_console_print ("Error sending 'unbind queue' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_UNBIND_QUEUE))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_UNBIND_QUEUE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_unbind_queue_finish"
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
    amq_broker_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_broker_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_SELFTEST))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_SELFTEST))
    icl_trace_record (NULL, amq_broker_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_SELFTEST))
    icl_stats_inc ("amq_broker_selftest", &s_amq_broker_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_SELFTEST))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_SELFTEST))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_selftest_finish"
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
    amq_broker_inspect_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_broker_inspect_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_INSPECT_SHIM))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_inspect_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_INSPECT_SHIM))
    icl_trace_record (NULL, amq_broker_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_INSPECT_SHIM))
    icl_stats_inc ("amq_broker_inspect_shim", &s_amq_broker_inspect_shim_stats);
#endif

self_inspect ((amq_broker_t *) (self_v), request);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_INSPECT_SHIM))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_INSPECT_SHIM))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_inspect_shim_finish"
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
    amq_broker_inspect

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_broker_inspect (
    amq_broker_t * self,                //  Reference to object
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_INSPECT))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_inspect_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_INSPECT))
    icl_trace_record (NULL, amq_broker_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_INSPECT))
    icl_stats_inc ("amq_broker_inspect", &s_amq_broker_inspect_stats);
#endif

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_broker_agent_inspect (self->thread,request)) {
        //icl_console_print ("Error sending 'inspect' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_INSPECT))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_INSPECT))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_inspect_finish"
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
    amq_broker_modify_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_broker_modify_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_MODIFY_SHIM))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_modify_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_MODIFY_SHIM))
    icl_trace_record (NULL, amq_broker_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_MODIFY_SHIM))
    icl_stats_inc ("amq_broker_modify_shim", &s_amq_broker_modify_shim_stats);
#endif

self_modify ((amq_broker_t *) (self_v), request, fields);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_MODIFY_SHIM))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_MODIFY_SHIM))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_modify_shim_finish"
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
    amq_broker_modify

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_broker_modify (
    amq_broker_t * self,                //  Reference to object
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_MODIFY))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_modify_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_MODIFY))
    icl_trace_record (NULL, amq_broker_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_MODIFY))
    icl_stats_inc ("amq_broker_modify", &s_amq_broker_modify_stats);
#endif

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_broker_agent_modify (self->thread,request,fields)) {
        //icl_console_print ("Error sending 'modify' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_MODIFY))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_MODIFY))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_modify_finish"
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
    amq_broker_method_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_broker_method_shim (
    void * self_v,                      //  Object cast as a void *
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_METHOD_SHIM))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_method_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_METHOD_SHIM))
    icl_trace_record (NULL, amq_broker_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_METHOD_SHIM))
    icl_stats_inc ("amq_broker_method_shim", &s_amq_broker_method_shim_stats);
#endif

self_method ((amq_broker_t *) (self_v), method_name, request, fields);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_METHOD_SHIM))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_METHOD_SHIM))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_method_shim_finish"
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
    amq_broker_method

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_broker_method (
    amq_broker_t * self,                //  Reference to object
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Argument fields
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_METHOD))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_method_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_METHOD))
    icl_trace_record (NULL, amq_broker_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_METHOD))
    icl_stats_inc ("amq_broker_method", &s_amq_broker_method_stats);
#endif

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_broker_agent_method (self->thread,method_name,request,fields)) {
        //icl_console_print ("Error sending 'method' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_METHOD))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_METHOD))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_method_finish"
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
    amq_broker_unlink_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_broker_unlink_shim (
    void * object_p                     //  Reference pointer cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_UNLINK_SHIM))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_unlink_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_UNLINK_SHIM))
    icl_trace_record (NULL, amq_broker_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_UNLINK_SHIM))
    icl_stats_inc ("amq_broker_unlink_shim", &s_amq_broker_unlink_shim_stats);
#endif

//
amq_broker_unlink (((amq_broker_t **) object_p));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_UNLINK_SHIM))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_UNLINK_SHIM))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_unlink_shim_finish"
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
    amq_broker_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_broker_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_INITIALISE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_INITIALISE))
    icl_trace_record (NULL, amq_broker_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_INITIALISE))
    icl_stats_inc ("amq_broker_initialise", &s_amq_broker_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_broker_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_broker_mutex)
            s_amq_broker_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_broker_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_broker_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_broker_agent_init ();

s_class = amq_console_class_new ();
s_class->name    = "broker";
s_class->inspect = amq_broker_inspect_shim;
s_class->modify  = amq_broker_modify_shim;
s_class->method  = amq_broker_method_shim;
s_class->unlink  = amq_broker_unlink_shim;
            s_amq_broker_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_broker_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_INITIALISE))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_INITIALISE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_initialise_finish"
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
    amq_broker_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_broker_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_TERMINATE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_TERMINATE))
    icl_trace_record (NULL, amq_broker_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_TERMINATE))
    icl_stats_inc ("amq_broker_terminate", &s_amq_broker_terminate_stats);
#endif

if (s_amq_broker_active) {

amq_console_class_destroy (&s_class);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_broker_mutex);
#endif
        s_amq_broker_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_TERMINATE))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_TERMINATE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_terminate_finish"
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
    amq_broker_free

    Type: Component method
    Freess a amq_broker_t object.
    -------------------------------------------------------------------------
 */

void
    amq_broker_free_ (
    amq_broker_t * self,                //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_FREE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_FREE))
    icl_trace_record (NULL, amq_broker_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_FREE))
    icl_stats_inc ("amq_broker_free", &s_amq_broker_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BROKER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BROKER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BROKER_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_BROKER_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);

smt_log_destroy (&self->alert_log);
smt_log_destroy (&self->daily_log);
smt_log_destroy (&self->debug_log);
        memset (&self->object_tag, 0, sizeof (amq_broker_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_broker_t));
        self->object_tag = AMQ_BROKER_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_FREE))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_FREE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_free_finish"
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
    amq_broker_start

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_broker_start (
    amq_broker_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_START))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_start_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_START))
    icl_trace_record (NULL, amq_broker_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_START))
    icl_stats_inc ("amq_broker_start", &s_amq_broker_start_stats);
#endif

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_broker_agent_start (self->thread)) {
        //icl_console_print ("Error sending 'start' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_START))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_START))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_start_finish"
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
    amq_broker_shutdown

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_broker_shutdown (
    amq_broker_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_SHUTDOWN))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_shutdown_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_SHUTDOWN))
    icl_trace_record (NULL, amq_broker_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_SHUTDOWN))
    icl_stats_inc ("amq_broker_shutdown", &s_amq_broker_shutdown_stats);
#endif

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_broker_agent_shutdown (self->thread)) {
        //icl_console_print ("Error sending 'shutdown' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_SHUTDOWN))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_SHUTDOWN))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_shutdown_finish"
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
    amq_broker_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_broker_destroy_ (
    amq_broker_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_broker_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_DESTROY_PUBLIC))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_broker_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_DESTROY_PUBLIC))
    icl_stats_inc ("amq_broker_destroy", &s_amq_broker_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = amq_broker_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_broker_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_DESTROY_PUBLIC))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_destroy_public_finish"
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
    amq_broker_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_broker_unlink_ (
    amq_broker_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    int
        history_last;
#endif
    amq_broker_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_UNLINK))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_UNLINK))
    icl_trace_record (NULL, amq_broker_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_UNLINK))
    icl_stats_inc ("amq_broker_unlink", &s_amq_broker_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_broker object");
            amq_broker_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BROKER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BROKER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BROKER_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_BROKER_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_broker_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_broker_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_UNLINK))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_UNLINK))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_unlink_finish"
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
    amq_broker_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_broker_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_ANIMATE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_ANIMATE))
    icl_trace_record (NULL, amq_broker_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_ANIMATE))
    icl_stats_inc ("amq_broker_animate", &s_amq_broker_animate_stats);
#endif

amq_broker_animating = enabled;

amq_broker_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_ANIMATE))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_ANIMATE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_animate_finish"
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
    amq_broker_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_broker_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_broker_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_SHOW))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_SHOW))
    icl_trace_record (NULL, amq_broker_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_SHOW))
    icl_stats_inc ("amq_broker_show", &s_amq_broker_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_broker zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    if (self->history_last > AMQ_BROKER_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_BROKER_HISTORY_LENGTH;
        self->history_last %= AMQ_BROKER_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_BROKER_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_broker>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_SHOW))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_SHOW))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_show_finish"
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
    amq_broker_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_broker_t *
    amq_broker_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_broker_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_ALLOC))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_ALLOC))
    icl_trace_record (NULL, amq_broker_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_ALLOC))
    icl_stats_inc ("amq_broker_alloc", &s_amq_broker_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_broker_cache_initialise ();

self = (amq_broker_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_broker_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_ALLOC))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_ALLOC))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_alloc_finish"
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
    amq_broker_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_broker_t *
    amq_broker_link_ (
    amq_broker_t * self,                //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_LINK))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_LINK))
    icl_trace_record (NULL, amq_broker_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_LINK))
    icl_stats_inc ("amq_broker_link", &s_amq_broker_link_stats);
#endif

    if (self) {
        AMQ_BROKER_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BROKER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BROKER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BROKER_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_BROKER_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_LINK))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_LINK))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_link_finish"
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
    amq_broker_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_broker_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_CACHE_INITIALISE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_broker_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_CACHE_INITIALISE))
    icl_stats_inc ("amq_broker_cache_initialise", &s_amq_broker_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_broker_t));
icl_system_register (amq_broker_cache_purge, amq_broker_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_CACHE_INITIALISE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_cache_initialise_finish"
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
    amq_broker_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_broker_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_CACHE_PURGE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_PURGE))
    icl_trace_record (NULL, amq_broker_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_CACHE_PURGE))
    icl_stats_inc ("amq_broker_cache_purge", &s_amq_broker_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_PURGE))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_CACHE_PURGE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_cache_purge_finish"
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
    amq_broker_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_broker_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_CACHE_TERMINATE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_broker_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_CACHE_TERMINATE))
    icl_stats_inc ("amq_broker_cache_terminate", &s_amq_broker_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_CACHE_TERMINATE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_cache_terminate_finish"
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
    amq_broker_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_broker_new_in_scope_ (
    amq_broker_t * * self_p,            //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BROKER)  ||  defined (BASE_ANIMATE_AMQ_BROKER_NEW_IN_SCOPE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_broker_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER)  ||  defined (BASE_STATS_AMQ_BROKER_NEW_IN_SCOPE))
    icl_stats_inc ("amq_broker_new_in_scope", &s_amq_broker_new_in_scope_stats);
#endif

*self_p = amq_broker_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_broker_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_broker_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BROKER)   || defined (BASE_ANIMATE_AMQ_BROKER_NEW_IN_SCOPE))
    if (amq_broker_animating)
        icl_console_print ("<amq_broker_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_NEW)   || defined (BASE_TRACE_AMQ_BROKER_DESTROY)   || defined (BASE_TRACE_AMQ_BROKER_UNBIND_QUEUE)   || defined (BASE_TRACE_AMQ_BROKER_SELFTEST)   || defined (BASE_TRACE_AMQ_BROKER_INSPECT_SHIM)   || defined (BASE_TRACE_AMQ_BROKER_INSPECT)   || defined (BASE_TRACE_AMQ_BROKER_MODIFY_SHIM)   || defined (BASE_TRACE_AMQ_BROKER_MODIFY)   || defined (BASE_TRACE_AMQ_BROKER_METHOD_SHIM)   || defined (BASE_TRACE_AMQ_BROKER_METHOD)   || defined (BASE_TRACE_AMQ_BROKER_UNLINK_SHIM)   || defined (BASE_TRACE_AMQ_BROKER_INITIALISE)   || defined (BASE_TRACE_AMQ_BROKER_TERMINATE)   || defined (BASE_TRACE_AMQ_BROKER_FREE)   || defined (BASE_TRACE_AMQ_BROKER_START)   || defined (BASE_TRACE_AMQ_BROKER_SHUTDOWN)   || defined (BASE_TRACE_AMQ_BROKER_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_BROKER_UNLINK)   || defined (BASE_TRACE_AMQ_BROKER_ANIMATE)   || defined (BASE_TRACE_AMQ_BROKER_SHOW)   || defined (BASE_TRACE_AMQ_BROKER_ALLOC)   || defined (BASE_TRACE_AMQ_BROKER_LINK)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_BROKER_NEW_IN_SCOPE) )
void
amq_broker_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "unbind queue"; break;
        case 4: method_name = "selftest"; break;
        case 5: method_name = "inspect shim"; break;
        case 6: method_name = "inspect"; break;
        case 7: method_name = "modify shim"; break;
        case 8: method_name = "modify"; break;
        case 9: method_name = "method shim"; break;
        case 10: method_name = "method"; break;
        case 11: method_name = "unlink shim"; break;
        case 12: method_name = "initialise"; break;
        case 13: method_name = "terminate"; break;
        case 14: method_name = "free"; break;
        case 15: method_name = "start"; break;
        case 16: method_name = "shutdown"; break;
        case 17: method_name = "destroy public"; break;
        case 18: method_name = "unlink"; break;
        case 19: method_name = "animate"; break;
        case 20: method_name = "show"; break;
        case 21: method_name = "alloc"; break;
        case 22: method_name = "link"; break;
        case 23: method_name = "cache initialise"; break;
        case 24: method_name = "cache purge"; break;
        case 25: method_name = "cache terminate"; break;
        case 26: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_broker %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Format a logfile name including the port
static void
s_format_logfile (char *log_name, char *configured)
{
    char
        *point;

    point = strchr (configured, '.');
    if (point) {
        //  Insert port number before extension
        icl_shortstr_ncpy (log_name, configured, point - configured);
        icl_shortstr_cat  (log_name, "_");
        icl_shortstr_cat  (log_name, amq_server_config_port (amq_server_config));
        icl_shortstr_cat  (log_name, point);
    }
    else {
        //  Add port number at end
        icl_shortstr_cpy  (log_name, configured);
        icl_shortstr_cat  (log_name, "_");
        icl_shortstr_cat  (log_name, amq_server_config_port (amq_server_config));
        icl_shortstr_cat  (log_name, ".log");
    }
}

//  Embed the version information in the resulting binary                      

char *amq_broker_version_start     = "VeRsIoNsTaRt:ipc";
char *amq_broker_component         = "amq_broker ";
char *amq_broker_version           = "1.0 ";
char *amq_broker_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_broker_filename          = "amq_broker.icl ";
char *amq_broker_builddate         = "2010/10/06 ";
char *amq_broker_version_end       = "VeRsIoNeNd:ipc";

