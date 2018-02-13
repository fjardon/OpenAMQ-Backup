/*---------------------------------------------------------------------------
    amq_failover.c - amq_failover component

    Generated from amq_failover.icl by smt_object_gen using GSL/4.
    
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
#include "amq_failover.h"               //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_failover_t

//  Shorthands for class methods                                               

#define self_new            amq_failover_new
#define self_start_monitoring  amq_failover_start_monitoring
#define self_annihilate     amq_failover_annihilate
#define self_send_state     amq_failover_send_state
#define self_execute        amq_failover_execute
#define self_selftest       amq_failover_selftest
#define self_destroy        amq_failover_destroy
#define self_unlink         amq_failover_unlink
#define self_animate        amq_failover_animate
#define self_free           amq_failover_free
#define self_initialise     amq_failover_initialise
#define self_terminate      amq_failover_terminate
#define self_show           amq_failover_show
#define self_alloc          amq_failover_alloc
#define self_link           amq_failover_link
#define self_cache_initialise  amq_failover_cache_initialise
#define self_cache_purge    amq_failover_cache_purge
#define self_cache_terminate  amq_failover_cache_terminate
#define self_new_in_scope   amq_failover_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_NEW))
static icl_stats_t *s_amq_failover_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_START_MONITORING))
static icl_stats_t *s_amq_failover_start_monitoring_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_DESTROY))
static icl_stats_t *s_amq_failover_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_SEND_STATE))
static icl_stats_t *s_amq_failover_send_state_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_EXECUTE))
static icl_stats_t *s_amq_failover_execute_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_SELFTEST))
static icl_stats_t *s_amq_failover_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_DESTROY_PUBLIC))
static icl_stats_t *s_amq_failover_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_UNLINK))
static icl_stats_t *s_amq_failover_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_ANIMATE))
static icl_stats_t *s_amq_failover_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_FREE))
static icl_stats_t *s_amq_failover_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_INITIALISE))
static icl_stats_t *s_amq_failover_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_TERMINATE))
static icl_stats_t *s_amq_failover_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_SHOW))
static icl_stats_t *s_amq_failover_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_ALLOC))
static icl_stats_t *s_amq_failover_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_LINK))
static icl_stats_t *s_amq_failover_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_CACHE_INITIALISE))
static icl_stats_t *s_amq_failover_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_CACHE_PURGE))
static icl_stats_t *s_amq_failover_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_CACHE_TERMINATE))
static icl_stats_t *s_amq_failover_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_NEW_IN_SCOPE))
static icl_stats_t *s_amq_failover_new_in_scope_stats = NULL;
#endif
#define amq_failover_annihilate(self)   amq_failover_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_failover_annihilate_ (
amq_failover_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_failover_initialise (
void);

#define amq_failover_alloc()            amq_failover_alloc_ (__FILE__, __LINE__)
static amq_failover_t *
    amq_failover_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_failover_cache_initialise (
void);

static void
    amq_failover_cache_purge (
void);

static void
    amq_failover_cache_terminate (
void);

Bool
    amq_failover_animating = TRUE;      //  Animation enabled by default
static Bool
    s_amq_failover_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_failover_mutex     = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static int
    s_content_handler (void *vself, amq_peering_t *peering, amq_peer_method_t *peer_method);
/*  -------------------------------------------------------------------------
    amq_failover_new

    Type: Component method
    Creates and initialises a new amq_failover_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_failover_t *
    amq_failover_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_broker_t * broker               //  Parent broker
)
{
char
    *backup,                        //  Backup to connect to
    *primary;                       //  Primary to connect to
    amq_failover_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_NEW))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" broker=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, broker);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_NEW))
    icl_trace_record (NULL, amq_failover_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_NEW))
    icl_stats_inc ("amq_failover_new", &s_amq_failover_new_stats);
#endif

if (!s_amq_failover_active)
    self_initialise ();
    self = amq_failover_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_FAILOVER_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_failover_show_);
#endif

self->thread = amq_failover_agent_class_thread_new (self);
self->thread->animate = TRUE;

//
self->broker = amq_broker_link (broker);
self->status_exchange = amq_exchange_table_search (
    broker->vhost->exchange_table, "amq.status");
assert (self->status_exchange);
backup  = amq_server_config_backup  (amq_server_config);
primary = amq_server_config_primary (amq_server_config);

//  All timeouts are represented internally as usec for SMT
self->timeout = amq_server_config_failover_timeout (amq_server_config)
              * 1000000;

//  Check configuration is sane
if (*backup && *primary)
    icl_console_print ("E: don't set both --backup and --primary");
else
if (*backup) {
    self->enabled = TRUE;
    self->primary = TRUE;
}
else
if (*primary)
    self->enabled = TRUE;
//  Enable failover if requested
if (self->enabled) {
    smt_log_print (amq_broker->alert_log, "I: failover enabled, acting as %s",
        self->primary? "master": "slave");
    smt_log_print (amq_broker->alert_log, "I: failover: waiting for %s...",
        self->primary? "backup (slave)": "primary (master)");

    self->state = amq_ha_state_pending;
    self->last_peer_time = 0;

    //  Start peering
    self->peering = amq_peering_new (
        *primary? primary: backup,
        amq_server_config_vhost (amq_server_config),
        amq_server_config_trace (amq_server_config),
        "amq.status",               //  Exchange name to peer with
        "direct");                  //  Exchange type to create

    amq_peering_set_login (self->peering, "peering");
    amq_peering_set_content_handler (self->peering, s_content_handler, self);
    amq_peering_start (self->peering);

    //  Subscribe for failover peer's state notifications
    amq_peering_bind (self->peering,
        self->primary? "failover.backup": "failover.primary", NULL);

    //  Start monitoring failover peer state
    amq_failover_start_monitoring (self);
}
//  Else, configuration not OK, or failover disabled
else
    smt_log_print (amq_broker->alert_log, "I: no failover defined, READY as stand-alone");
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_NEW))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_NEW))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" broker=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, broker, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_failover_start_monitoring

    Type: Component method
    Accepts a amq_failover_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_failover_start_monitoring (
    amq_failover_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_START_MONITORING))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_start_monitoring_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_START_MONITORING))
    icl_trace_record (NULL, amq_failover_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_START_MONITORING))
    icl_stats_inc ("amq_failover_start_monitoring", &s_amq_failover_start_monitoring_stats);
#endif

AMQ_FAILOVER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_failover_agent_start_monitoring (self->thread)) {
        //icl_console_print ("Error sending 'start_monitoring' method to amq_failover agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_START_MONITORING))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_START_MONITORING))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_start_monitoring_finish"
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
    amq_failover_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_failover_annihilate_ (
    amq_failover_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
    int
        history_last;
#endif

    amq_failover_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_DESTROY))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_DESTROY))
    icl_trace_record (NULL, amq_failover_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_DESTROY))
    icl_stats_inc ("amq_failover_annihilate", &s_amq_failover_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = self->links;
#endif


    if (self->peering) {
        amq_peering_stop (self->peering);
        amq_peering_unlink (&self->peering);
    }
    amq_exchange_unlink (&self->status_exchange);
    amq_broker_unlink (&self->broker);

if (self) {
    assert (self->thread);
    if (amq_failover_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_failover agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_DESTROY))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_DESTROY))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_destroy_finish"
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
    amq_failover_send_state

    Type: Component method
    Accepts a amq_failover_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_failover_send_state (
    amq_failover_t * self               //  Reference to object
)
{
icl_shortstr_t
    state;
amq_content_basic_t
    *content;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_SEND_STATE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_send_state_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_SEND_STATE))
    icl_trace_record (NULL, amq_failover_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_SEND_STATE))
    icl_stats_inc ("amq_failover_send_state", &s_amq_failover_send_state_stats);
#endif

AMQ_FAILOVER_ASSERT_SANE (self);
if (!self->zombie) {

//
content = amq_content_basic_new ();
amq_content_basic_set_routing_key (content, "amq.status",
    self->primary? "failover.primary" : "failover.backup", 0);
icl_shortstr_fmt (state, "%d", self->state);
amq_content_basic_set_body (content,
    icl_mem_strdup (state), strlen (state) + 1, icl_mem_free);
amq_exchange_publish (self->status_exchange,
    NULL, content, FALSE, FALSE, AMQ_CONNECTION_GROUP_SUPER);
amq_content_basic_unlink (&content);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_SEND_STATE))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_SEND_STATE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_send_state_finish"
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
    amq_failover_execute

    Type: Component method
    Accepts a amq_failover_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_failover_execute (
    amq_failover_t * self,              //  Reference to object
    int event                           //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_EXECUTE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_execute_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" event=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, event);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_EXECUTE))
    icl_trace_record (NULL, amq_failover_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_EXECUTE))
    icl_stats_inc ("amq_failover_execute", &s_amq_failover_execute_stats);
#endif

AMQ_FAILOVER_ASSERT_SANE (self);
if (!self->zombie) {

//
switch (self->state) {
  case amq_ha_state_pending:
    switch (event) {
      case amq_ha_event_peer_pending:
        if (self->primary) {
            self->state = amq_ha_state_active;
            smt_log_print (amq_broker->alert_log,
                "I: failover: connected to backup (slave), READY as master");
        }
        break;
      case amq_ha_event_peer_active:
        self->state = amq_ha_state_passive;
        smt_log_print (amq_broker->alert_log,
            "I: failover: connected to %s (master), READY as slave",
            self->primary? "backup": "primary");
        break;
      case amq_ha_event_peer_passive:
        //  Do nothing; wait while peer switches to active
        break;
      case amq_ha_event_new_connection:
        //  If pending, accept connection only if primary peer
        rc = (self->primary);
        break;
      default:
        assert (0);
    }
    break;

  case amq_ha_state_active:
    switch (event) {
      case amq_ha_event_peer_pending:
        //  Do nothing; slave is starting
        break;
      case amq_ha_event_peer_active:
        //  No way to have two masters - that would mean split-brain
        smt_log_print (amq_broker->alert_log,
            "E: failover: fatal error - dual masters detected, aborting");
        assert (0);
        break;
      case amq_ha_event_peer_passive:
        //  Do nothing; everything is OK
        break;
      case amq_ha_event_new_connection:
        //  Active state, we do accept new connections
        rc = 1;
        break;
      default:
        assert (0);
    }
    break;

  case amq_ha_state_passive:
    switch (event) {
      case amq_ha_event_peer_pending:
        //  The peer is restarting; become active (peer will become passive)
        self->state = amq_ha_state_active;
        smt_log_print (amq_broker->alert_log,
            "I: failover: %s (slave) is restarting, READY as master",
            self->primary? "backup": "primary");
        break;
      case amq_ha_event_peer_active:
        //  Do nothing; everything is OK
        break;
      case amq_ha_event_peer_passive:
        //  No way to have two passives - cluster would be non-responsive
        smt_log_print (amq_broker->alert_log,
            "E: failover: fatal error - dual slaves, aborting");
        assert (0);
        break;
      case amq_ha_event_new_connection:
        //  Peer becomes master if timeout has passed
        //  It's the connection request that triggers the failover
        if (smt_time_now () - self->last_peer_time > self->timeout) {
            //  If peer is dead, switch to the active state
            self->state = amq_ha_state_active;
            smt_log_print (amq_broker->alert_log,
                "I: failover: failover successful, READY as master");
            rc = 1;                 //  Accept the request, then
        }
        else
            //  If peer is alive, reject connections
            rc = 0;
        break;
      default:
        assert (0);
    }
    break;

  default:
    assert (0);
}
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_EXECUTE))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_EXECUTE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_execute_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" event=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, event, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_failover_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_failover_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_SELFTEST))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_SELFTEST))
    icl_trace_record (NULL, amq_failover_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_SELFTEST))
    icl_stats_inc ("amq_failover_selftest", &s_amq_failover_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_SELFTEST))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_SELFTEST))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_selftest_finish"
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
    amq_failover_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_failover_destroy_ (
    amq_failover_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_failover_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_DESTROY_PUBLIC))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_failover_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_DESTROY_PUBLIC))
    icl_stats_inc ("amq_failover_destroy", &s_amq_failover_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = amq_failover_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_failover_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_DESTROY_PUBLIC))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_destroy_public_finish"
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
    amq_failover_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_failover_unlink_ (
    amq_failover_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
    int
        history_last;
#endif
    amq_failover_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_UNLINK))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_UNLINK))
    icl_trace_record (NULL, amq_failover_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_UNLINK))
    icl_stats_inc ("amq_failover_unlink", &s_amq_failover_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_failover object");
            amq_failover_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_failover_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_failover_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_UNLINK))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_UNLINK))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_unlink_finish"
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
    amq_failover_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_failover_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_ANIMATE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_ANIMATE))
    icl_trace_record (NULL, amq_failover_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_ANIMATE))
    icl_stats_inc ("amq_failover_animate", &s_amq_failover_animate_stats);
#endif

amq_failover_animating = enabled;

amq_failover_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_ANIMATE))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_ANIMATE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_animate_finish"
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
    amq_failover_free

    Type: Component method
    Freess a amq_failover_t object.
    -------------------------------------------------------------------------
 */

void
    amq_failover_free_ (
    amq_failover_t * self,              //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_FREE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_FREE))
    icl_trace_record (NULL, amq_failover_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_FREE))
    icl_stats_inc ("amq_failover_free", &s_amq_failover_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (amq_failover_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_failover_t));
        self->object_tag = AMQ_FAILOVER_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_FREE))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_FREE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_free_finish"
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
    amq_failover_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_failover_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_INITIALISE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_INITIALISE))
    icl_trace_record (NULL, amq_failover_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_INITIALISE))
    icl_stats_inc ("amq_failover_initialise", &s_amq_failover_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_failover_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_failover_mutex)
            s_amq_failover_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_failover_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_failover_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_failover_agent_init ();
            s_amq_failover_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_failover_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_INITIALISE))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_INITIALISE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_initialise_finish"
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
    amq_failover_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_failover_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_TERMINATE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_TERMINATE))
    icl_trace_record (NULL, amq_failover_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_TERMINATE))
    icl_stats_inc ("amq_failover_terminate", &s_amq_failover_terminate_stats);
#endif

if (s_amq_failover_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_failover_mutex);
#endif
        s_amq_failover_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_TERMINATE))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_TERMINATE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_terminate_finish"
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
    amq_failover_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_failover_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_failover_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_SHOW))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_SHOW))
    icl_trace_record (NULL, amq_failover_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_SHOW))
    icl_stats_inc ("amq_failover_show", &s_amq_failover_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_failover zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
    if (self->history_last > AMQ_FAILOVER_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_FAILOVER_HISTORY_LENGTH;
        self->history_last %= AMQ_FAILOVER_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_FAILOVER_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_failover>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_SHOW))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_SHOW))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_show_finish"
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
    amq_failover_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_failover_t *
    amq_failover_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_failover_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_ALLOC))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_ALLOC))
    icl_trace_record (NULL, amq_failover_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_ALLOC))
    icl_stats_inc ("amq_failover_alloc", &s_amq_failover_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_failover_cache_initialise ();

self = (amq_failover_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_failover_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_ALLOC))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_ALLOC))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_alloc_finish"
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
    amq_failover_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_failover_t *
    amq_failover_link_ (
    amq_failover_t * self,              //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_LINK))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_LINK))
    icl_trace_record (NULL, amq_failover_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_LINK))
    icl_stats_inc ("amq_failover_link", &s_amq_failover_link_stats);
#endif

    if (self) {
        AMQ_FAILOVER_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_FAILOVER_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_LINK))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_LINK))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_link_finish"
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
    amq_failover_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_failover_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_CACHE_INITIALISE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_failover_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_CACHE_INITIALISE))
    icl_stats_inc ("amq_failover_cache_initialise", &s_amq_failover_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_failover_t));
icl_system_register (amq_failover_cache_purge, amq_failover_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_CACHE_INITIALISE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_cache_initialise_finish"
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
    amq_failover_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_failover_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_CACHE_PURGE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_CACHE_PURGE))
    icl_trace_record (NULL, amq_failover_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_CACHE_PURGE))
    icl_stats_inc ("amq_failover_cache_purge", &s_amq_failover_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_CACHE_PURGE))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_CACHE_PURGE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_cache_purge_finish"
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
    amq_failover_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_failover_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_CACHE_TERMINATE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_failover_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_CACHE_TERMINATE))
    icl_stats_inc ("amq_failover_cache_terminate", &s_amq_failover_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_CACHE_TERMINATE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_cache_terminate_finish"
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
    amq_failover_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_failover_new_in_scope_ (
    amq_failover_t * * self_p,          //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_broker_t * broker               //  Parent broker
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER)  ||  defined (BASE_ANIMATE_AMQ_FAILOVER_NEW_IN_SCOPE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" broker=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, broker);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_failover_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FAILOVER)  ||  defined (BASE_STATS_AMQ_FAILOVER_NEW_IN_SCOPE))
    icl_stats_inc ("amq_failover_new_in_scope", &s_amq_failover_new_in_scope_stats);
#endif

*self_p = amq_failover_new_ (file,line,broker);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_failover_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_failover_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FAILOVER)   || defined (BASE_ANIMATE_AMQ_FAILOVER_NEW_IN_SCOPE))
    if (amq_failover_animating)
        icl_console_print ("<amq_failover_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" broker=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, broker, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FAILOVER)   || defined (BASE_TRACE_AMQ_FAILOVER_NEW)   || defined (BASE_TRACE_AMQ_FAILOVER_START_MONITORING)   || defined (BASE_TRACE_AMQ_FAILOVER_DESTROY)   || defined (BASE_TRACE_AMQ_FAILOVER_SEND_STATE)   || defined (BASE_TRACE_AMQ_FAILOVER_EXECUTE)   || defined (BASE_TRACE_AMQ_FAILOVER_SELFTEST)   || defined (BASE_TRACE_AMQ_FAILOVER_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_FAILOVER_UNLINK)   || defined (BASE_TRACE_AMQ_FAILOVER_ANIMATE)   || defined (BASE_TRACE_AMQ_FAILOVER_FREE)   || defined (BASE_TRACE_AMQ_FAILOVER_INITIALISE)   || defined (BASE_TRACE_AMQ_FAILOVER_TERMINATE)   || defined (BASE_TRACE_AMQ_FAILOVER_SHOW)   || defined (BASE_TRACE_AMQ_FAILOVER_ALLOC)   || defined (BASE_TRACE_AMQ_FAILOVER_LINK)   || defined (BASE_TRACE_AMQ_FAILOVER_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_FAILOVER_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_FAILOVER_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_FAILOVER_NEW_IN_SCOPE) )
void
amq_failover_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "start_monitoring"; break;
        case 3: method_name = "destroy"; break;
        case 4: method_name = "send state"; break;
        case 5: method_name = "execute"; break;
        case 6: method_name = "selftest"; break;
        case 7: method_name = "destroy public"; break;
        case 8: method_name = "unlink"; break;
        case 9: method_name = "animate"; break;
        case 10: method_name = "free"; break;
        case 11: method_name = "initialise"; break;
        case 12: method_name = "terminate"; break;
        case 13: method_name = "show"; break;
        case 14: method_name = "alloc"; break;
        case 15: method_name = "link"; break;
        case 16: method_name = "cache initialise"; break;
        case 17: method_name = "cache purge"; break;
        case 18: method_name = "cache terminate"; break;
        case 19: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_failover %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

static int
s_content_handler (
    void *vself,
    amq_peering_t *peering,
    amq_peer_method_t *peer_method)
{
    amq_failover_t
        *self = (amq_failover_t *) vself;
    asl_reader_t
        reader;
    ipr_bucket_t
        *body;
    amq_ha_state
        state;
    amq_ha_event
        event;

    assert (peer_method->class_id == AMQ_PEER_BASIC);
    assert (peer_method->method_id == AMQ_PEER_BASIC_DELIVER);

    //  Status from other HAC party received
    self->last_peer_time = smt_time_now ();

    //  Parse content
    amq_content_basic_set_reader (peer_method->content, &reader, 4096);
    body = amq_content_basic_replay_body (peer_method->content, &reader);
    assert (body);
    state = atoi ((char *) body->data);
    assert (state != 0);
    ipr_bucket_destroy (&body);

    //  Convert peer's state to FSM event
    switch (state) {
    case amq_ha_state_pending:
        event = amq_ha_event_peer_pending;
        break;
    case amq_ha_state_active:
        event = amq_ha_event_peer_active;
        break;
    case amq_ha_state_passive:
        event = amq_ha_event_peer_passive;
        break;
    default:
        assert (0);
    }
    //  Run the FSM
    self_execute (self, event);

    return 0;
}

//  Embed the version information in the resulting binary                      

char *amq_failover_version_start   = "VeRsIoNsTaRt:ipc";
char *amq_failover_component       = "amq_failover ";
char *amq_failover_version         = "1.0 ";
char *amq_failover_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_failover_filename        = "amq_failover.icl ";
char *amq_failover_builddate       = "2010/10/06 ";
char *amq_failover_version_end     = "VeRsIoNeNd:ipc";

