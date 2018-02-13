/*---------------------------------------------------------------------------
    amq_peering_agent.c - functions for amq_peering_agent.

    Generated from amq_peering_agent.smt by smt_gen.gsl using GSL/4.

    
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
#include "ipr.h"                        //  For iPR classes
#include "smt.h"                        //  For SMT classes
#include "amq_peering_agent.h"

#define class_main_state                           1
#define class_shutting_down_state                  2

#define destroy_m ((amq_peering_agent_destroy_t *) thread->method->data)

#define bind_m ((amq_peering_agent_bind_t *) thread->method->data)

#define unbind_m ((amq_peering_agent_unbind_t *) thread->method->data)

#define forward_m ((amq_peering_agent_forward_t *) thread->method->data)

#define peer_connection_start_m ((amq_peering_agent_peer_connection_start_t *) thread->method->data)

#define peer_connection_open_ok_m ((amq_peering_agent_peer_connection_open_ok_t *) thread->method->data)

#define peer_connection_close_m ((amq_peering_agent_peer_connection_close_t *) thread->method->data)

#define peer_channel_open_ok_m ((amq_peering_agent_peer_channel_open_ok_t *) thread->method->data)

#define peer_basic_deliver_m ((amq_peering_agent_peer_basic_deliver_t *) thread->method->data)

#define peer_basic_return_m ((amq_peering_agent_peer_basic_return_t *) thread->method->data)

enum {
    monitor_event                                  = 1,
    shutdown_event                                 = 2,
    destroy_m_event                                = 3,
    start_m_event                                  = 4,
    stop_m_event                                   = 5,
    bind_m_event                                   = 6,
    unbind_m_event                                 = 7,
    forward_m_event                                = 8,
    peer_connection_start_m_event                  = 9,
    peer_connection_open_ok_m_event                = 10,
    peer_connection_close_m_event                  = 11,
    peer_channel_open_ok_m_event                   = 12,
    peer_basic_deliver_m_event                     = 13,
    peer_basic_return_m_event                      = 14,
};

#define laststate                                  2
#define lastevent                                  14
#define lastplace                                  31

#define amq_peering_agent_agent_name               "Amq-Peering-Agent"

#define class_thread_name                          "Class"

#define main_state_name                            "Main"
#define shutting_down_state_name                   "Shutting-Down"

#define monitor_event_name                         "Monitor"
#define shutdown_event_name                        "Shutdown"
#define destroy_m_event_name                       "Destroy-M"
#define start_m_event_name                         "Start-M"
#define stop_m_event_name                          "Stop-M"
#define bind_m_event_name                          "Bind-M"
#define unbind_m_event_name                        "Unbind-M"
#define forward_m_event_name                       "Forward-M"
#define peer_connection_start_m_event_name         "Peer-Connection-Start-M"
#define peer_connection_open_ok_m_event_name       "Peer-Connection-Open-Ok-M"
#define peer_connection_close_m_event_name         "Peer-Connection-Close-M"
#define peer_channel_open_ok_m_event_name          "Peer-Channel-Open-Ok-M"
#define peer_basic_deliver_m_event_name            "Peer-Basic-Deliver-M"
#define peer_basic_return_m_event_name             "Peer-Basic-Return-M"

#define monitor_action_name                        "Monitor"
#define destroy_action_name                        "Destroy"
#define free_action_name                           "Free"
#define unnamed_4_action_name                      "Unnamed-4"
#define unnamed_5_action_name                      "Unnamed-5"
#define start_action_name                          "Start"
#define unnamed_7_action_name                      "Unnamed-7"
#define stop_action_name                           "Stop"
#define unnamed_9_action_name                      "Unnamed-9"
#define bind_action_name                           "Bind"
#define unnamed_11_action_name                     "Unnamed-11"
#define unbind_action_name                         "Unbind"
#define unnamed_13_action_name                     "Unnamed-13"
#define forward_action_name                        "Forward"
#define unnamed_15_action_name                     "Unnamed-15"
#define peer_connection_start_action_name          "Peer-Connection-Start"
#define unnamed_17_action_name                     "Unnamed-17"
#define peer_connection_open_ok_action_name        "Peer-Connection-Open-Ok"
#define unnamed_19_action_name                     "Unnamed-19"
#define peer_connection_close_action_name          "Peer-Connection-Close"
#define unnamed_21_action_name                     "Unnamed-21"
#define peer_channel_open_ok_action_name           "Peer-Channel-Open-Ok"
#define unnamed_23_action_name                     "Unnamed-23"
#define peer_basic_deliver_action_name             "Peer-Basic-Deliver"
#define unnamed_25_action_name                     "Unnamed-25"
#define peer_basic_return_action_name              "Peer-Basic-Return"
#define unnamed_27_action_name                     "Unnamed-27"

#define the_next_event                             thread->_next_event
#define exception_raised                           thread->_exception_raised

typedef struct
  {
    char *         file;
    size_t         line;
  }
amq_peering_agent_destroy_t;

typedef struct
  {
    char *         routing_key;
    icl_longstr_t *  arguments;
  }
amq_peering_agent_bind_t;

typedef struct
  {
    char *         routing_key;
    icl_longstr_t *  arguments;
  }
amq_peering_agent_unbind_t;

typedef struct
  {
    char *         routing_key;
    amq_content_basic_t *  content;
    Bool           mandatory;
    Bool           immediate;
  }
amq_peering_agent_forward_t;

typedef struct
  {
    amq_peer_method_t *  method;
  }
amq_peering_agent_peer_connection_start_t;

typedef struct
  {
    amq_peer_method_t *  method;
  }
amq_peering_agent_peer_connection_open_ok_t;

typedef struct
  {
    amq_peer_method_t *  method;
  }
amq_peering_agent_peer_connection_close_t;

typedef struct
  {
    amq_peer_method_t *  method;
  }
amq_peering_agent_peer_channel_open_ok_t;

typedef struct
  {
    amq_peer_method_t *  method;
  }
amq_peering_agent_peer_basic_deliver_t;

typedef struct
  {
    amq_peer_method_t *  method;
  }
amq_peering_agent_peer_basic_return_t;


static void s_initialise_peering (amq_peering_t *self);
static void s_terminate_peering  (amq_peering_t *self);
static ipr_looseref_t *s_binding_exists (ipr_looseref_list_t *bindings,
    char *routing_key, icl_longstr_t *arguments);

static icl_cache_t
    *s_class_context_cache = NULL;

typedef struct {
    int
        links;

        amq_peering_t
            *amq_peering;
    
} amq_peering_agent_class_context_t;

static icl_cache_t
    *s_destroy_cache = NULL;
static icl_cache_t
    *s_bind_cache = NULL;
static icl_cache_t
    *s_unbind_cache = NULL;
static icl_cache_t
    *s_forward_cache = NULL;
static icl_cache_t
    *s_peer_connection_start_cache = NULL;
static icl_cache_t
    *s_peer_connection_open_ok_cache = NULL;
static icl_cache_t
    *s_peer_connection_close_cache = NULL;
static icl_cache_t
    *s_peer_channel_open_ok_cache = NULL;
static icl_cache_t
    *s_peer_basic_deliver_cache = NULL;
static icl_cache_t
    *s_peer_basic_return_cache = NULL;

static const char *thread_name [] = {
    "<NULL>",
    class_thread_name
};

static const char *state_name [] = {
    "<NULL>",
    main_state_name,
    shutting_down_state_name
};

static const char *event_name [] = {
    "<NULL>",
    monitor_event_name,
    shutdown_event_name,
    destroy_m_event_name,
    start_m_event_name,
    stop_m_event_name,
    bind_m_event_name,
    unbind_m_event_name,
    forward_m_event_name,
    peer_connection_start_m_event_name,
    peer_connection_open_ok_m_event_name,
    peer_connection_close_m_event_name,
    peer_channel_open_ok_m_event_name,
    peer_basic_deliver_m_event_name,
    peer_basic_return_m_event_name
};

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT)        ||  defined (BASE_TRACE)  || defined (BASE_TRACE_AMQ_PEERING_AGENT)   ||  defined (AMQ_PEERING_AGENT_TRACE))
static const char *action_name [] = {
    "<NULL>",
    monitor_action_name,
    destroy_action_name,
    free_action_name,
    unnamed_4_action_name,
    unnamed_5_action_name,
    start_action_name,
    unnamed_7_action_name,
    stop_action_name,
    unnamed_9_action_name,
    bind_action_name,
    unnamed_11_action_name,
    unbind_action_name,
    unnamed_13_action_name,
    forward_action_name,
    unnamed_15_action_name,
    peer_connection_start_action_name,
    unnamed_17_action_name,
    peer_connection_open_ok_action_name,
    unnamed_19_action_name,
    peer_connection_close_action_name,
    unnamed_21_action_name,
    peer_channel_open_ok_action_name,
    unnamed_23_action_name,
    peer_basic_deliver_action_name,
    unnamed_25_action_name,
    peer_basic_return_action_name,
    unnamed_27_action_name
};
#endif

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
static Bool
    s_animate = FALSE;
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_MONITOR))
static icl_stats_t *s_amq_peering_agent_monitor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_DESTROY))
static icl_stats_t *s_amq_peering_agent_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_FREE))
static icl_stats_t *s_amq_peering_agent_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_4))
static icl_stats_t *s_amq_peering_agent_unnamed_4_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_5))
static icl_stats_t *s_amq_peering_agent_unnamed_5_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_START))
static icl_stats_t *s_amq_peering_agent_start_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_7))
static icl_stats_t *s_amq_peering_agent_unnamed_7_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_STOP))
static icl_stats_t *s_amq_peering_agent_stop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_9))
static icl_stats_t *s_amq_peering_agent_unnamed_9_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_BIND))
static icl_stats_t *s_amq_peering_agent_bind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_11))
static icl_stats_t *s_amq_peering_agent_unnamed_11_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNBIND))
static icl_stats_t *s_amq_peering_agent_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_13))
static icl_stats_t *s_amq_peering_agent_unnamed_13_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_FORWARD))
static icl_stats_t *s_amq_peering_agent_forward_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_15))
static icl_stats_t *s_amq_peering_agent_unnamed_15_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_CONNECTION_START))
static icl_stats_t *s_amq_peering_agent_peer_connection_start_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_17))
static icl_stats_t *s_amq_peering_agent_unnamed_17_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_CONNECTION_OPEN_OK))
static icl_stats_t *s_amq_peering_agent_peer_connection_open_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_19))
static icl_stats_t *s_amq_peering_agent_unnamed_19_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_CONNECTION_CLOSE))
static icl_stats_t *s_amq_peering_agent_peer_connection_close_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_21))
static icl_stats_t *s_amq_peering_agent_unnamed_21_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_CHANNEL_OPEN_OK))
static icl_stats_t *s_amq_peering_agent_peer_channel_open_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_23))
static icl_stats_t *s_amq_peering_agent_unnamed_23_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_BASIC_DELIVER))
static icl_stats_t *s_amq_peering_agent_peer_basic_deliver_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_25))
static icl_stats_t *s_amq_peering_agent_unnamed_25_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_BASIC_RETURN))
static icl_stats_t *s_amq_peering_agent_peer_basic_return_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_27))
static icl_stats_t *s_amq_peering_agent_unnamed_27_stats = NULL;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//  Function prototypes                                                        

static int    amq_peering_agent_manager       (smt_thread_t **thread);
static int    amq_peering_agent_catcher       (smt_thread_t *thread);
static int    amq_peering_agent_class_destroy  (smt_thread_t *thread);
static void   find_thread_state_next_state    (int          *thread_type,
                                               smt_state_t  *state_id,
                                               smt_event_t  *event_id,
                                               smt_state_t  *nextstate_id,
                                               smt_thread_t *thread);
static void   report_unrecognised_event_error (smt_thread_t *thread);
static void   report_state_machine_error      (smt_thread_t *thread);

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
static void   animate_start_new_event         (smt_thread_t *thread,
                                               smt_event_t  saveevent_id);
static void   animate_action                  (smt_thread_t *thread_id,
                                               int          action_id);
static int    find_thread_type                (smt_place_t  place);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEERING_AGENT)          ||  defined (AMQ_PEERING_AGENT_TRACE))
static void   s_dump                          (icl_os_thread_t apr_os_thread,
                                               apr_time_t      time,
                                               qbyte           info);

#endif

static int    action_monitor                  (smt_thread_t *thread);
static int    action_destroy                  (smt_thread_t *thread);
static int    action_free                     (smt_thread_t *thread);
static int    action_unnamed_4                (smt_thread_t *thread);
static int    action_unnamed_5                (smt_thread_t *thread);
static int    action_start                    (smt_thread_t *thread);
static int    action_unnamed_7                (smt_thread_t *thread);
static int    action_stop                     (smt_thread_t *thread);
static int    action_unnamed_9                (smt_thread_t *thread);
static int    action_bind                     (smt_thread_t *thread);
static int    action_unnamed_11               (smt_thread_t *thread);
static int    action_unbind                   (smt_thread_t *thread);
static int    action_unnamed_13               (smt_thread_t *thread);
static int    action_forward                  (smt_thread_t *thread);
static int    action_unnamed_15               (smt_thread_t *thread);
static int    action_peer_connection_start    (smt_thread_t *thread);
static int    action_unnamed_17               (smt_thread_t *thread);
static int    action_peer_connection_open_ok  (smt_thread_t *thread);
static int    action_unnamed_19               (smt_thread_t *thread);
static int    action_peer_connection_close    (smt_thread_t *thread);
static int    action_unnamed_21               (smt_thread_t *thread);
static int    action_peer_channel_open_ok     (smt_thread_t *thread);
static int    action_unnamed_23               (smt_thread_t *thread);
static int    action_peer_basic_deliver       (smt_thread_t *thread);
static int    action_unnamed_25               (smt_thread_t *thread);
static int    action_peer_basic_return        (smt_thread_t *thread);
static int    action_unnamed_27               (smt_thread_t *thread);
static int
amq_peering_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line);
int
amq_peering_agent_destroy_destructor (void *data);
static int
amq_peering_agent_bind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         routing_key,
    icl_longstr_t *  arguments);
int
amq_peering_agent_bind_destructor (void *data);
static int
amq_peering_agent_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         routing_key,
    icl_longstr_t *  arguments);
int
amq_peering_agent_unbind_destructor (void *data);
static int
amq_peering_agent_forward_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         routing_key,
    amq_content_basic_t *  content,
    Bool           mandatory,
    Bool           immediate);
int
amq_peering_agent_forward_destructor (void *data);
static int
amq_peering_agent_peer_connection_start_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method);
int
amq_peering_agent_peer_connection_start_destructor (void *data);
static int
amq_peering_agent_peer_connection_open_ok_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method);
int
amq_peering_agent_peer_connection_open_ok_destructor (void *data);
static int
amq_peering_agent_peer_connection_close_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method);
int
amq_peering_agent_peer_connection_close_destructor (void *data);
static int
amq_peering_agent_peer_channel_open_ok_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method);
int
amq_peering_agent_peer_channel_open_ok_destructor (void *data);
static int
amq_peering_agent_peer_basic_deliver_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method);
int
amq_peering_agent_peer_basic_deliver_destructor (void *data);
static int
amq_peering_agent_peer_basic_return_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method);
int
amq_peering_agent_peer_basic_return_destructor (void *data);
//  Function definitions                                                       

static int
amq_peering_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line)
{
    int
        rc = 0;
    amq_peering_agent_destroy_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_destroy_cache);
    _message->file                      = file;
    _message->line                      = line;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_peering_agent_destroy_destructor);
    
    return rc;
}

int
amq_peering_agent_destroy_destructor (void *data)
{
    int
        rc = 0;
char * file;
size_t line;

    file = ((amq_peering_agent_destroy_t *) data)-> file;
    line = ((amq_peering_agent_destroy_t *) data)-> line;


    icl_mem_free (data);
    return rc;
}


static int
amq_peering_agent_bind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         routing_key,
    icl_longstr_t *  arguments)
{
    int
        rc = 0;
    amq_peering_agent_bind_t
        *_message;
        
    //  Possess code for bind
    

    routing_key = icl_mem_strdup (routing_key);
    arguments = icl_longstr_dup (arguments);
    
    

    _message = icl_mem_cache_alloc (s_bind_cache);
    _message->routing_key               = routing_key;
    _message->arguments                 = arguments;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_peering_agent_bind_destructor);
    
    return rc;
}

int
amq_peering_agent_bind_destructor (void *data)
{
    int
        rc = 0;
char * routing_key;
icl_longstr_t * arguments;

    routing_key = ((amq_peering_agent_bind_t *) data)-> routing_key;
    arguments = ((amq_peering_agent_bind_t *) data)-> arguments;



    icl_mem_free (routing_key);
    icl_longstr_destroy (&arguments);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_peering_agent_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         routing_key,
    icl_longstr_t *  arguments)
{
    int
        rc = 0;
    amq_peering_agent_unbind_t
        *_message;
        
    //  Possess code for unbind
    

    routing_key = icl_mem_strdup (routing_key);
    arguments = icl_longstr_dup (arguments);
    
    

    _message = icl_mem_cache_alloc (s_unbind_cache);
    _message->routing_key               = routing_key;
    _message->arguments                 = arguments;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_peering_agent_unbind_destructor);
    
    return rc;
}

int
amq_peering_agent_unbind_destructor (void *data)
{
    int
        rc = 0;
char * routing_key;
icl_longstr_t * arguments;

    routing_key = ((amq_peering_agent_unbind_t *) data)-> routing_key;
    arguments = ((amq_peering_agent_unbind_t *) data)-> arguments;



    icl_mem_free (routing_key);
    icl_longstr_destroy (&arguments);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_peering_agent_forward_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         routing_key,
    amq_content_basic_t *  content,
    Bool           mandatory,
    Bool           immediate)
{
    int
        rc = 0;
    amq_peering_agent_forward_t
        *_message;
        
    //  Possess code for forward
    

    routing_key = icl_mem_strdup (routing_key);
    content = amq_content_basic_link (content);
    
    

    _message = icl_mem_cache_alloc (s_forward_cache);
    _message->routing_key               = routing_key;
    _message->content                   = content;
    _message->mandatory                 = mandatory;
    _message->immediate                 = immediate;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_peering_agent_forward_destructor);
    
    return rc;
}

int
amq_peering_agent_forward_destructor (void *data)
{
    int
        rc = 0;
char * routing_key;
amq_content_basic_t * content;
Bool mandatory;
Bool immediate;

    routing_key = ((amq_peering_agent_forward_t *) data)-> routing_key;
    content = ((amq_peering_agent_forward_t *) data)-> content;
    mandatory = ((amq_peering_agent_forward_t *) data)-> mandatory;
    immediate = ((amq_peering_agent_forward_t *) data)-> immediate;



    icl_mem_free (routing_key);
    amq_content_basic_unlink (&content);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_peering_agent_peer_connection_start_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method)
{
    int
        rc = 0;
    amq_peering_agent_peer_connection_start_t
        *_message;
        
    //  Possess code for peer connection start
    

    method = amq_peer_method_link (method);
    
    

    _message = icl_mem_cache_alloc (s_peer_connection_start_cache);
    _message->method                    = method;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_peering_agent_peer_connection_start_destructor);
    
    return rc;
}

int
amq_peering_agent_peer_connection_start_destructor (void *data)
{
    int
        rc = 0;
amq_peer_method_t * method;

    method = ((amq_peering_agent_peer_connection_start_t *) data)-> method;



    amq_peer_method_unlink (&method);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_peering_agent_peer_connection_open_ok_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method)
{
    int
        rc = 0;
    amq_peering_agent_peer_connection_open_ok_t
        *_message;
        
    //  Possess code for peer connection open ok
    

    method = amq_peer_method_link (method);
    
    

    _message = icl_mem_cache_alloc (s_peer_connection_open_ok_cache);
    _message->method                    = method;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_peering_agent_peer_connection_open_ok_destructor);
    
    return rc;
}

int
amq_peering_agent_peer_connection_open_ok_destructor (void *data)
{
    int
        rc = 0;
amq_peer_method_t * method;

    method = ((amq_peering_agent_peer_connection_open_ok_t *) data)-> method;



    amq_peer_method_unlink (&method);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_peering_agent_peer_connection_close_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method)
{
    int
        rc = 0;
    amq_peering_agent_peer_connection_close_t
        *_message;
        
    //  Possess code for peer connection close
    

    method = amq_peer_method_link (method);
    
    

    _message = icl_mem_cache_alloc (s_peer_connection_close_cache);
    _message->method                    = method;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_peering_agent_peer_connection_close_destructor);
    
    return rc;
}

int
amq_peering_agent_peer_connection_close_destructor (void *data)
{
    int
        rc = 0;
amq_peer_method_t * method;

    method = ((amq_peering_agent_peer_connection_close_t *) data)-> method;



    amq_peer_method_unlink (&method);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_peering_agent_peer_channel_open_ok_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method)
{
    int
        rc = 0;
    amq_peering_agent_peer_channel_open_ok_t
        *_message;
        
    //  Possess code for peer channel open ok
    

    method = amq_peer_method_link (method);
    
    

    _message = icl_mem_cache_alloc (s_peer_channel_open_ok_cache);
    _message->method                    = method;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_peering_agent_peer_channel_open_ok_destructor);
    
    return rc;
}

int
amq_peering_agent_peer_channel_open_ok_destructor (void *data)
{
    int
        rc = 0;
amq_peer_method_t * method;

    method = ((amq_peering_agent_peer_channel_open_ok_t *) data)-> method;



    amq_peer_method_unlink (&method);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_peering_agent_peer_basic_deliver_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method)
{
    int
        rc = 0;
    amq_peering_agent_peer_basic_deliver_t
        *_message;
        
    //  Possess code for peer basic deliver
    

    method = amq_peer_method_link (method);
    
    

    _message = icl_mem_cache_alloc (s_peer_basic_deliver_cache);
    _message->method                    = method;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_peering_agent_peer_basic_deliver_destructor);
    
    return rc;
}

int
amq_peering_agent_peer_basic_deliver_destructor (void *data)
{
    int
        rc = 0;
amq_peer_method_t * method;

    method = ((amq_peering_agent_peer_basic_deliver_t *) data)-> method;



    amq_peer_method_unlink (&method);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_peering_agent_peer_basic_return_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_peer_method_t *  method)
{
    int
        rc = 0;
    amq_peering_agent_peer_basic_return_t
        *_message;
        
    //  Possess code for peer basic return
    

    method = amq_peer_method_link (method);
    
    

    _message = icl_mem_cache_alloc (s_peer_basic_return_cache);
    _message->method                    = method;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_peering_agent_peer_basic_return_destructor);
    
    return rc;
}

int
amq_peering_agent_peer_basic_return_destructor (void *data)
{
    int
        rc = 0;
amq_peer_method_t * method;

    method = ((amq_peering_agent_peer_basic_return_t *) data)-> method;



    amq_peer_method_unlink (&method);
    
    

    icl_mem_free (data);
    return rc;
}


int
amq_peering_agent_start (
    smt_thread_t * thread)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = smt_method_send (
                thread->reply_queue,
                start_m_event,
                SMT_PRIORITY_NORMAL,
                SMT_OK, NULL, NULL);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_peering_agent_stop (
    smt_thread_t * thread)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = smt_method_send (
                thread->reply_queue,
                stop_m_event,
                SMT_PRIORITY_NORMAL,
                SMT_OK, NULL, NULL);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_peering_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = amq_peering_agent_destroy_send (
                thread->reply_queue, destroy_m_event,
                file,
                line);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_peering_agent_bind (
    smt_thread_t * thread,
    char *                routing_key,
    icl_longstr_t *       arguments)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = amq_peering_agent_bind_send (
                thread->reply_queue, bind_m_event,
                routing_key,
                arguments);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_peering_agent_unbind (
    smt_thread_t * thread,
    char *                routing_key,
    icl_longstr_t *       arguments)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = amq_peering_agent_unbind_send (
                thread->reply_queue, unbind_m_event,
                routing_key,
                arguments);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_peering_agent_forward (
    smt_thread_t * thread,
    char *                routing_key,
    amq_content_basic_t * content,
    Bool                  mandatory,
    Bool                  immediate)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = amq_peering_agent_forward_send (
                thread->reply_queue, forward_m_event,
                routing_key,
                content,
                mandatory,
                immediate);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_peering_agent_peer_connection_start (
    smt_thread_t * thread,
    amq_peer_method_t *   method)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = amq_peering_agent_peer_connection_start_send (
                thread->reply_queue, peer_connection_start_m_event,
                method);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_peering_agent_peer_connection_open_ok (
    smt_thread_t * thread,
    amq_peer_method_t *   method)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = amq_peering_agent_peer_connection_open_ok_send (
                thread->reply_queue, peer_connection_open_ok_m_event,
                method);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_peering_agent_peer_connection_close (
    smt_thread_t * thread,
    amq_peer_method_t *   method)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = amq_peering_agent_peer_connection_close_send (
                thread->reply_queue, peer_connection_close_m_event,
                method);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_peering_agent_peer_channel_open_ok (
    smt_thread_t * thread,
    amq_peer_method_t *   method)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = amq_peering_agent_peer_channel_open_ok_send (
                thread->reply_queue, peer_channel_open_ok_m_event,
                method);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_peering_agent_peer_basic_deliver (
    smt_thread_t * thread,
    amq_peer_method_t *   method)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = amq_peering_agent_peer_basic_deliver_send (
                thread->reply_queue, peer_basic_deliver_m_event,
                method);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_peering_agent_peer_basic_return (
    smt_thread_t * thread,
    amq_peer_method_t *   method)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_peering_agent_manager);
        rc = amq_peering_agent_peer_basic_return_send (
                thread->reply_queue, peer_basic_return_m_event,
                method);
    }
    else
        rc = -1;
        
    return rc;
}


static void
s_initialise_peering (amq_peering_t *self)
{
    int
        ticket = 0;
    char
        *queue = NULL,
        *consumer_tag = NULL;
    Bool
        passive = FALSE,
        durable = FALSE,
        exclusive = TRUE,
        auto_delete = TRUE,
        nowait = TRUE,
        no_local = FALSE,
        no_ack = FALSE;
    icl_longstr_t
        *arguments = NULL;
    ipr_looseref_t
        *looseref;                      //  Binding method
    amq_peer_method_t
        *method;                        //  Method to send to peer server
    //
    if (!self->connected) {
        self->connected = TRUE;
        self->offlined = FALSE;
        smt_log_print (amq_broker->alert_log,
            "I: exchange %s now peered to %s", self->exchange, self->host);

        //  Create private queue on peer and consume off queue
        amq_peer_agent_queue_declare (
            self->peer_agent_thread, self->channel_nbr,
            ticket, queue, passive, durable, exclusive, auto_delete, nowait, arguments);

        amq_peer_agent_basic_consume (
            self->peer_agent_thread, self->channel_nbr,
            ticket, queue, consumer_tag, no_local, no_ack, exclusive, nowait, NULL);

        //  Declare remote exchange on peer
        amq_peer_agent_exchange_declare (
            self->peer_agent_thread, self->channel_nbr,
            ticket, self->exchange, self->exchange_type, FALSE, FALSE,
            FALSE, FALSE, nowait, NULL);

        //  Replicate all bindings to remote peer
        looseref = ipr_looseref_list_first (self->bindings);
        while (looseref) {
            method = (amq_peer_method_t *) (looseref->object);
            amq_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
            looseref = ipr_looseref_list_next (&looseref);
        }
        //  Forward all pending messages to remote peer
        while ((method = (amq_peer_method_t *) ipr_looseref_pop (self->messages))) {
            amq_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
            amq_peer_method_unlink (&method);
        }
        if (self->status_fn)
            (self->status_fn) (self->status_caller, self, TRUE);
    }
}

static void
s_terminate_peering (amq_peering_t *self)
{
    amq_broker_t
        *broker_ref;

    //  Stop peer agent thread if it's still alive
    if (self->peer_agent_thread) {
        if (!self->peer_agent_thread->zombie)
            amq_peer_agent_connection_close (self->peer_agent_thread);
        smt_thread_unlink (&self->peer_agent_thread);
    }
    if (self->connected) {
        self->connected = FALSE;
        self->offlined  = TRUE;

        if (self->status_fn)
            (self->status_fn) (self->status_caller, self, FALSE);

        //  Use broker with caution because it can be destroyed now
        broker_ref = amq_broker_link (amq_broker);
        if (broker_ref) {
            smt_log_print (broker_ref->alert_log,
                "I: exchange %s unpeered from %s", self->exchange, self->host);
            amq_broker_unlink (&broker_ref);
        }
    }
}

//  Used by peering_bind and peering_unbind to determine if binding is unique.
//  Searches provided looseref list for a queue.bind method matching the
//  provided routing_key and arguments.  Returns looseref if found, NULL if
//  no match found.
static ipr_looseref_t *
s_binding_exists (
    ipr_looseref_list_t *bindings,
    char *routing_key,
    icl_longstr_t *arguments)
{
    ipr_looseref_t
        *looseref;
    amq_peer_method_t
        *method;

    looseref = ipr_looseref_list_first (bindings);
    while (looseref) {
        method = (amq_peer_method_t *) (looseref->object);
        assert (method->class_id  == AMQ_PEER_QUEUE);
        assert (method->method_id == AMQ_PEER_QUEUE_BIND);
        //  If routing_key and arguments are equal, we have a match
        if (streq (method->payload.queue_bind.routing_key, routing_key) &&
            icl_longstr_eq (method->payload.queue_bind.arguments, arguments))
            break;
        looseref = ipr_looseref_list_next (&looseref);
    }
    return looseref;
}

void
amq_peering_agent_term (void)
{

}

int 
amq_peering_agent_init (void)
{
    int
        rc = SMT_OK;                    //  Return code

    s_class_context_cache = icl_cache_get (sizeof (amq_peering_agent_class_context_t));
    s_destroy_cache = icl_cache_get (sizeof (amq_peering_agent_destroy_t));
    s_bind_cache = icl_cache_get (sizeof (amq_peering_agent_bind_t));
    s_unbind_cache = icl_cache_get (sizeof (amq_peering_agent_unbind_t));
    s_forward_cache = icl_cache_get (sizeof (amq_peering_agent_forward_t));
    s_peer_connection_start_cache = icl_cache_get (sizeof (amq_peering_agent_peer_connection_start_t));
    s_peer_connection_open_ok_cache = icl_cache_get (sizeof (amq_peering_agent_peer_connection_open_ok_t));
    s_peer_connection_close_cache = icl_cache_get (sizeof (amq_peering_agent_peer_connection_close_t));
    s_peer_channel_open_ok_cache = icl_cache_get (sizeof (amq_peering_agent_peer_channel_open_ok_t));
    s_peer_basic_deliver_cache = icl_cache_get (sizeof (amq_peering_agent_peer_basic_deliver_t));
    s_peer_basic_return_cache = icl_cache_get (sizeof (amq_peering_agent_peer_basic_return_t));

    //  Initialise basic stuff.
    smt_initialise ();
    
    {

    }
    icl_system_register (NULL, amq_peering_agent_term);
    
    return rc;
}

void
amq_peering_agent_animate (Bool animate)
{
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
    s_animate = animate;
#endif
}

smt_thread_t *
amq_peering_agent_class_thread_new (
    amq_peering_t * self)
{
    smt_thread_t
        *thread;

    thread = smt_thread_new (amq_peering_agent_manager,
                             amq_peering_agent_catcher,
                             amq_peering_agent_class_destroy);
                             

#if (defined (AMQ_PEERING_AGENT_TRACE))
    thread->trace = icl_trace_new (ICL_TRACE_SIZE);
#endif

    if (thread) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
        thread->animate = s_animate;
        if (s_animate)
            icl_console_print ("%4lu> %-15s/%-15s <Created>",
                thread->id,
                "amq_peering_agent",
                class_thread_name);
#endif

        thread->place   = 1;
        thread->context = icl_mem_cache_alloc (s_class_context_cache);
        memset (thread->context, 0, sizeof (amq_peering_agent_class_context_t));
        ((amq_peering_agent_class_context_t *) thread->context)->links = 1;
        thread->event_name = event_name;
{
#define tcb ((amq_peering_agent_class_context_t *) thread->context)

        tcb->amq_peering = self;
    
#undef  tcb
}
    }
    return thread;
}


static int
amq_peering_agent_manager (smt_thread_t **thread_p)
{
    smt_thread_t
        *thread = *thread_p;
        
    int
        rc;
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))

    smt_event_t
        saveevent_id = SMT_NULL_EVENT;
#endif
        
    assert (thread->manager == amq_peering_agent_manager);
                                                 //  Ensure correct manager    

    //  First deal with shutdown request.  These are asynchronous.             
    if (thread->shutdown_request) {
        //  Cancel any outstanding requests
        smt_thread_purge (thread);
        
        thread->shutdown_request = FALSE;
        if (! thread->shutting_down) {
            thread->shutting_down     = TRUE;
            thread->signal_raised     = FALSE;
            thread->_exception_raised = FALSE;
            thread->_next_event       = shutdown_event;
            thread->module            = 0;
        }
    }
    
    //  Convert signal to exception
    if (thread->signal_raised) {
        //  Cancel any outstanding requests
        smt_thread_purge (thread);
        
        thread->signal_raised = FALSE;
        thread->_exception_raised = TRUE;
        thread->_exception_event  = thread->signal_event;
    }

    //  Return straight away if there are pending operations.  This can happen
    //  if a thread gets woken at just the wrong moment.
    if (thread->monitor
    ||  thread->pending_count)
        return SMT_SLEEPING;

    //  Collect method before testing for exception because method may
    //  provoke an exception.
    if ((!thread->_exception_raised)
    &&    thread->module == SMT_TERM_MODULE
    &&    thread->_next_event == SMT_NULL_EVENT
    &&    smt_thread_method_accept (thread) == SMT_EMPTY)
        return SMT_SLEEPING;
        
    //  Finally trap exception and convert to a normal event.                  
    if (thread->_exception_raised) {
        thread->_exception_raised = FALSE;
        thread->_next_event       = thread->_exception_event;
        thread->_exception_event  = SMT_NULL_EVENT;
        thread->module            = 0;
    }

    if (thread->module == SMT_TERM_MODULE)
        switch (thread->place) {
            case 5:
            case 31:
            case 19:
                thread->place = SMT_TERM_PLACE;
                break;
            case 12:
            case 14:
            case 15:
            case 11:
            case 8:
            case 13:
            case 10:
            case 6:
            case 9:
            case 3:
            case 7:
            case 16:
                thread->place = 2;
                break;
            case 30:
            case 28:
            case 26:
            case 29:
            case 23:
            case 27:
            case 25:
            case 4:
            case 18:
            case 24:
            case 20:
            case 21:
            case 22:
                thread->place = 17;
                break;
        }    
    else
    if (thread->module == 0) {
        if (thread->place == 1) { //                Class thread
            if (!thread->shutting_down) {
{
#define tcb ((amq_peering_agent_class_context_t *) thread->context)

#undef  tcb
}
            }
            thread->place = 2;
            if (thread->_next_event == SMT_NULL_EVENT
            &&  smt_thread_method_accept (thread) == SMT_EMPTY) {
                thread->module = SMT_TERM_MODULE;
                return SMT_SLEEPING;
            }
        }
        else
        if (thread->place < 17)                 //  Main state
            thread->place = 2;
        else
            thread->place = 17;
    }

    switch (thread->place) {
        case 2:                         //  main state                          
{
#define tcb ((amq_peering_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case monitor_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 3; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 4; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 5; break;
                case start_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 6; break;
                case stop_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 7; break;
                case bind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 8; break;
                case unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 9; break;
                case forward_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 10; break;
                case peer_connection_start_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 11; break;
                case peer_connection_open_ok_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 12; break;
                case peer_connection_close_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 13; break;
                case peer_channel_open_ok_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 14; break;
                case peer_basic_deliver_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
                    thread->place = 15; break;
                case peer_basic_return_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
                    thread->place = 16; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
        case 17:                        //  shutting down state                 
{
#define tcb ((amq_peering_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case monitor_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 18; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 19; break;
                case start_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 20; break;
                case stop_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 21; break;
                case bind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 22; break;
                case unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 23; break;
                case forward_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 24; break;
                case peer_connection_start_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 25; break;
                case peer_connection_open_ok_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 26; break;
                case peer_connection_close_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 27; break;
                case peer_channel_open_ok_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 28; break;
                case peer_basic_deliver_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
                    thread->place = 29; break;
                case peer_basic_return_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
                    thread->place = 30; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 31; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
    }
                                  
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
    if (thread->animate && thread->module == 1)
        animate_start_new_event (thread, saveevent_id);
#endif

    switch (thread->place) {
        case 3:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 1);
#endif
                    rc = action_monitor (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 4:
        case 18:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
            switch (thread->module) {
                case 1:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    if (thread->place == 31)
                        thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 19:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 2);
#endif
                    rc = action_destroy (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 3);
#endif
                    rc = action_free (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 4);
#endif
                    rc = action_unnamed_4 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 4:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 5:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 2);
#endif
                    rc = action_destroy (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 3);
#endif
                    rc = action_free (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 5);
#endif
                    rc = action_unnamed_5 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 4:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 6:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 6);
#endif
                    rc = action_start (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 7);
#endif
                    rc = action_unnamed_7 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 7:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 8);
#endif
                    rc = action_stop (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 9);
#endif
                    rc = action_unnamed_9 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 8:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 10);
#endif
                    rc = action_bind (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 11);
#endif
                    rc = action_unnamed_11 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 9:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 12);
#endif
                    rc = action_unbind (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 13);
#endif
                    rc = action_unnamed_13 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 10:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 14);
#endif
                    rc = action_forward (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 15);
#endif
                    rc = action_unnamed_15 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 11:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 16);
#endif
                    rc = action_peer_connection_start (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 17);
#endif
                    rc = action_unnamed_17 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 12:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 18);
#endif
                    rc = action_peer_connection_open_ok (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 19);
#endif
                    rc = action_unnamed_19 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 13:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 20);
#endif
                    rc = action_peer_connection_close (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 21);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 21);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 21);
#endif
                    rc = action_unnamed_21 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 14:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 22);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 22);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 22);
#endif
                    rc = action_peer_channel_open_ok (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 23);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 23);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 23);
#endif
                    rc = action_unnamed_23 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 15:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 24);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 24);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 24);
#endif
                    rc = action_peer_basic_deliver (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 25);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 25);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 25);
#endif
                    rc = action_unnamed_25 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 16:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 26);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 26);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 26);
#endif
                    rc = action_peer_basic_return (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 27);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 27);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
                    if (thread->animate)
                        animate_action (thread, 27);
#endif
                    rc = action_unnamed_27 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
    }

    if (thread->_next_event == SMT_TERM_EVENT) {
        //  Because we optimise links, we need to grab ourselves one now.
        thread = smt_thread_link (thread);
        smt_thread_destroy (thread_p);
        return SMT_FINISHED;
    }
    
    return SMT_OK;
}

static int
amq_peering_agent_catcher (smt_thread_t *thread)
{
    return SMT_OK;
}


static int    
amq_peering_agent_class_destroy (smt_thread_t *thread)
{
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (AMQ_PEERING_AGENT_TRACE))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))
    if (thread->animate)
        icl_console_print ("%4lu> %-15s/%-15s <Destroyed>",
                  thread->id,
                  "amq_peering_agent",
                 class_thread_name);

#endif
    if (--((amq_peering_agent_class_context_t *) thread->context)->links == 0)
        icl_mem_free (thread->context);
    return 0;
}


static void
find_thread_state_next_state (
    int             *thread_type,
    smt_state_t     *state_id,
    smt_event_t     *event_id,
    smt_state_t     *nextstate_id,
    smt_thread_t    *thread)
{
    *thread_type  = 0;
    *state_id     = 0;
    *event_id     = 0;
    *nextstate_id = 0;
    
      {
        *thread_type = 1;
        if (thread->place < 17)
          {
            *state_id = 1;
            switch (thread->place) {
                case 3: *event_id = 1;   *nextstate_id = 1;   break;
                case 4: *event_id = 2;   *nextstate_id = 2;   break;
                case 5: *event_id = 3;   break;
                case 6: *event_id = 4;   *nextstate_id = 1;   break;
                case 7: *event_id = 5;   *nextstate_id = 1;   break;
                case 8: *event_id = 6;   *nextstate_id = 1;   break;
                case 9: *event_id = 7;   *nextstate_id = 1;   break;
                case 10: *event_id = 8;   *nextstate_id = 1;   break;
                case 11: *event_id = 9;   *nextstate_id = 1;   break;
                case 12: *event_id = 10;   *nextstate_id = 1;   break;
                case 13: *event_id = 11;   *nextstate_id = 1;   break;
                case 14: *event_id = 12;   *nextstate_id = 1;   break;
                case 15: *event_id = 13;   *nextstate_id = 1;   break;
                case 16: *event_id = 14;   *nextstate_id = 1;   break;
            }
          }
        else
          {
            *state_id = 2;
            switch (thread->place) {
                case 18: *event_id = 1;   *nextstate_id = 2;   break;
                case 19: *event_id = 3;   break;
                case 20: *event_id = 4;   *nextstate_id = 2;   break;
                case 21: *event_id = 5;   *nextstate_id = 2;   break;
                case 22: *event_id = 6;   *nextstate_id = 2;   break;
                case 23: *event_id = 7;   *nextstate_id = 2;   break;
                case 24: *event_id = 8;   *nextstate_id = 2;   break;
                case 25: *event_id = 9;   *nextstate_id = 2;   break;
                case 26: *event_id = 10;   *nextstate_id = 2;   break;
                case 27: *event_id = 11;   *nextstate_id = 2;   break;
                case 28: *event_id = 12;   *nextstate_id = 2;   break;
                case 29: *event_id = 13;   *nextstate_id = 2;   break;
                case 30: *event_id = 14;   *nextstate_id = 2;   break;
                case 31: *event_id = 2;   break;
            }
          }
      }
}

//  Action functions                                                           


static void
report_unrecognised_event_error (smt_thread_t *thread)
{
    int
        thread_type;
    smt_state_t
        state_id;
    smt_event_t
        event_id;
    smt_state_t
        nextstate_id;
    char
        num_buffer[8],
        *event_name_or_number;
        
    find_thread_state_next_state (&thread_type,
                                  &state_id,
                                  &event_id,
                                  &nextstate_id,
                                  thread);
    if (thread->_next_event >= 0
    &&  thread->_next_event <  tblsize (event_name))
        event_name_or_number = (char *) event_name[thread->_next_event];
    else {
        apr_snprintf (num_buffer, sizeof (num_buffer), "%u", (unsigned) thread->_next_event);
        event_name_or_number = num_buffer;
    }
    icl_console_print ("amq_peering_agent: Unrecognised event '%s' in '%s' thread number: %u, state: %s",
                       event_name_or_number,
                       thread_name [thread_type],
                       thread->id,
                       state_name  [state_id]);
    abort ();
}

static void
report_state_machine_error (smt_thread_t *thread)
{
    int
        thread_type;
    smt_state_t
        state_id;
    smt_event_t
        event_id;
    smt_state_t
        nextstate_id;
        
    find_thread_state_next_state (&thread_type,
                                  &state_id,
                                  &event_id,
                                  &nextstate_id,
                                  thread);
    icl_console_print ("State machine error: Event: %s Thread: %s, state: %s",
              event_name  [event_id],
              thread_name [thread_type],
              state_name  [state_id]);
}

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_PEERING_AGENT))

static void
animate_start_new_event (smt_thread_t *thread, smt_event_t saveevent_id)
{
    int
        thread_type;
    smt_state_t
        state_id;
    smt_event_t
        event_id;
    smt_state_t
        nextstate_id;
        
    find_thread_state_next_state (&thread_type,
                                  &state_id,
                                  &event_id,
                                  &nextstate_id,
                                  thread);
                                  
  icl_console_print ("%4lu> %-15s/%-15s %s:",
            thread->id,
            "amq_peering_agent",
            thread_name [thread_type],
            state_name [state_id]);
  icl_console_print ("%4lu> %-15s/%-15s    (--) %-32s->%s",
            thread->id,
            "amq_peering_agent",
            thread_name [thread_type],
            event_name [event_id != SMT_NULL_EVENT ? event_id : saveevent_id],
            nextstate_id ? state_name [nextstate_id] : "");
}

static void
animate_action (smt_thread_t *thread, int action_id)
{
    icl_console_print ("%4lu> %-15s/%-15s           + %s",
              thread->id,
              "amq_peering_agent",
              thread_name [find_thread_type (thread->place)],
              action_name [action_id]);
}

static int
find_thread_type (smt_place_t place)
{
    int
        thread_type = 0;
        
        thread_type = 1;
    return thread_type;
}

#endif
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_PEERING_AGENT)            ||  defined (AMQ_PEERING_AGENT_TRACE))
static void s_dump (
    icl_os_thread_t thread,
    apr_time_t      time,
    qbyte           info)
{
    smt_thread_id_t
        thread_id = info / 0x10000;
    smt_place_t
        state_or_event_or_action = info % 0x10000;
    int
        action_id;
    smt_event_t
        event_id;
    smt_state_t
        state_id;
        
    if (state_or_event_or_action > laststate + lastevent) {
        action_id = state_or_event_or_action - laststate - lastevent;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s           + %s",
                                       thread_id,
                                       "amq_peering_agent",
                                       action_name [action_id]);
    }
    else
    if (state_or_event_or_action > laststate) {
        event_id = state_or_event_or_action - laststate;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s    (--) %-32s",
                                       thread_id,
                                       "amq_peering_agent",
                                       event_name [event_id]);
    }
    else {
        state_id = state_or_event_or_action;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s %s:",
                                       thread_id,
                                       "amq_peering_agent",
                                       state_id ? state_name [state_id] : "<Destroyed>");
    }
}

#endif
static int
action_monitor (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_MONITOR))
    icl_stats_inc ("amq_peering_agent_monitor", &s_amq_peering_agent_monitor_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            
#define self tcb->amq_peering

        {
//  Terminate the peering if the application asked for it, or the
//  peer agent thread was closed from the network side.
if (self->peer_agent_thread && (!self->enabled || self->peer_agent_thread->zombie))
    s_terminate_peering (self);
else
//  Connect the peering if we're not already connected but the app
//  has for the peering to become active.
if (!self->peer_agent_thread && self->enabled)
    self->peer_agent_thread = amq_peer_agent_connection_thread_new (
        self,                       //  Callback for incoming methods
        self->host,
        self->virtual_host,
        self->auth_data,
        "Peering connection",       //  Instance name
        self->trace,
        amq_server_config_setup_timeout (amq_server_config),
        amq_server_config_debug_peering (amq_server_config));

//  Peering monitor runs once per second
smt_timer_request_delay (self->thread, 1000 * 1000, monitor_event);
        }
        
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_destroy (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_DESTROY))
    icl_stats_inc ("amq_peering_agent_destroy", &s_amq_peering_agent_destroy_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_peer_method_t
    *method;                        //  Queue.Bind method

s_terminate_peering (self);
icl_longstr_destroy (&self->auth_data);

while ((method = (amq_peer_method_t *) ipr_looseref_pop (self->bindings)))
    amq_peer_method_unlink (&method);
ipr_looseref_list_destroy (&self->bindings);

while ((method = (amq_peer_method_t *) ipr_looseref_pop (self->messages)))
    amq_peer_method_unlink (&method);
ipr_looseref_list_destroy (&self->messages);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_free (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_FREE))
    icl_stats_inc ("amq_peering_agent_free", &s_amq_peering_agent_free_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_peering object");
    amq_peering_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_peering_free (self);
    self = NULL;
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_4 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_4))
    icl_stats_inc ("amq_peering_agent_unnamed_4", &s_amq_peering_agent_unnamed_4_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_5 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_5))
    icl_stats_inc ("amq_peering_agent_unnamed_5", &s_amq_peering_agent_unnamed_5_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_start (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_START))
    icl_stats_inc ("amq_peering_agent_start", &s_amq_peering_agent_start_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering

        {
self->enabled = TRUE;
smt_timer_request_delay (self->thread, 100 * 1000, monitor_event);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_7 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_7))
    icl_stats_inc ("amq_peering_agent_unnamed_7", &s_amq_peering_agent_unnamed_7_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_stop (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_STOP))
    icl_stats_inc ("amq_peering_agent_stop", &s_amq_peering_agent_stop_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering

        {
self->enabled = FALSE;
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_9 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_9))
    icl_stats_inc ("amq_peering_agent_unnamed_9", &s_amq_peering_agent_unnamed_9_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_bind (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_BIND))
    icl_stats_inc ("amq_peering_agent_bind", &s_amq_peering_agent_bind_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering
char *
    routing_key;
icl_longstr_t *
    arguments;

    routing_key = bind_m->routing_key;
    arguments = bind_m->arguments;
        {
int
    ticket = 0;
char
    *queue = NULL;
Bool
    nowait = TRUE;
amq_peer_method_t
    *bind_method;

//  Treat empty arguments as null
if (arguments && arguments->cur_size == 0)
    arguments = NULL;
//  If this is a new binding (routing_key and arguments are unique),
//  create a Queue.Bind method and propagate it to the remote server
//  if connected.
if (s_binding_exists (self->bindings, routing_key, arguments) == NULL) {
    //  Queue is NULL as the only queue used by this connection is the
    //  peering's private queue
    bind_method = amq_peer_method_new_queue_bind (
        ticket, queue, self->exchange, routing_key, nowait, arguments);
    if (self->connected)
        amq_peer_agent_push (self->peer_agent_thread, self->channel_nbr, bind_method);
    //  We hold onto all outgoing bindings so we can replay them
    ipr_looseref_queue (self->bindings, bind_method);
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_11 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_11))
    icl_stats_inc ("amq_peering_agent_unnamed_11", &s_amq_peering_agent_unnamed_11_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unbind (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNBIND))
    icl_stats_inc ("amq_peering_agent_unbind", &s_amq_peering_agent_unbind_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering
char *
    routing_key;
icl_longstr_t *
    arguments;

    routing_key = unbind_m->routing_key;
    arguments = unbind_m->arguments;
        {
int
    ticket = 0;
char
    *queue = NULL;
Bool
    nowait = TRUE;
amq_peer_method_t
    *unbind_method,
    *bind_method;
ipr_looseref_t
    *looseref;

//  Treat empty arguments as null
if (arguments && arguments->cur_size == 0)
    arguments = NULL;
//  If connected, propagate Queue.Unbind to remote server
if (self->connected) {
    unbind_method = amq_peer_method_new_queue_unbind (
        ticket, queue, self->exchange, routing_key, nowait, arguments);
    amq_peer_agent_push (self->peer_agent_thread, self->channel_nbr, unbind_method);
    amq_peer_method_unlink (&unbind_method);
}
//  Search list of bindings for the matching Queue.Bind and remove it
looseref = s_binding_exists (self->bindings, routing_key, arguments);
assert (looseref);
bind_method = (amq_peer_method_t *) (looseref->object);
ipr_looseref_list_remove (looseref);
amq_peer_method_unlink (&bind_method);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_13 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_13))
    icl_stats_inc ("amq_peering_agent_unnamed_13", &s_amq_peering_agent_unnamed_13_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_forward (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_FORWARD))
    icl_stats_inc ("amq_peering_agent_forward", &s_amq_peering_agent_forward_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering
char *
    routing_key;
amq_content_basic_t *
    content;
Bool
    mandatory;
Bool
    immediate;

    routing_key = forward_m->routing_key;
    content = forward_m->content;
    mandatory = forward_m->mandatory;
    immediate = forward_m->immediate;
        {
int
    ticket = 0;
amq_peer_method_t
    *method;

if (amq_server_config_debug_peering (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "P: forward  peer exchange=%s routing_key=%s",
        self->exchange, routing_key);

//  Create a Basic.Publish method
method = amq_peer_method_new_basic_publish (
    ticket, self->exchange, routing_key, mandatory, immediate);
method->content = amq_content_basic_link (content);

//  We only hold messages if the connection is currently down
if (self->connected) {
    amq_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
    amq_peer_method_unlink (&method);
}
else
    ipr_looseref_queue (self->messages, method);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_15 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_15))
    icl_stats_inc ("amq_peering_agent_unnamed_15", &s_amq_peering_agent_unnamed_15_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_peer_connection_start (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_CONNECTION_START))
    icl_stats_inc ("amq_peering_agent_peer_connection_start", &s_amq_peering_agent_peer_connection_start_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_connection_start_m->method;
        {
asl_field_list_t
    *fields;                        //  Decoded responses
icl_shortstr_t
    peer_identifier;                //  Unique id of peer

fields = asl_field_list_new (method->payload.connection_start.server_properties);
assert (fields);
asl_field_list_cpy (fields, peer_identifier, "identifier");
asl_field_list_destroy (&fields);

if (amq_server_config_debug_peering (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "P: connected peer=%s self=%s",
        peer_identifier, amq_broker->identifier);

//  If peer and us have same identifier, jump overboard
if (streq (amq_broker->identifier, peer_identifier)) {
    icl_system_panic ("amq_peering", "E: attempted to peer to self - aborting");
    smt_shut_down ();
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_17 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_17))
    icl_stats_inc ("amq_peering_agent_unnamed_17", &s_amq_peering_agent_unnamed_17_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_peer_connection_open_ok (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_CONNECTION_OPEN_OK))
    icl_stats_inc ("amq_peering_agent_peer_connection_open_ok", &s_amq_peering_agent_peer_connection_open_ok_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_connection_open_ok_m->method;
        {
self->channel_nbr = 1;              //  Single channel per connection
amq_peer_agent_channel_open (self->peer_agent_thread, self->channel_nbr);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_19 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_19))
    icl_stats_inc ("amq_peering_agent_unnamed_19", &s_amq_peering_agent_unnamed_19_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_peer_connection_close (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_CONNECTION_CLOSE))
    icl_stats_inc ("amq_peering_agent_peer_connection_close", &s_amq_peering_agent_peer_connection_close_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_connection_close_m->method;
        {
//  If the connection failed due to a hard error, complain loudly and
//  shut down the broker.  We really don't want people using servers
//  with badly defined peerings.
if (ASL_HARD_ERROR (method->payload.connection_close.reply_code)) {
    smt_log_print (amq_broker->alert_log,
        "E: hard error on peering - please correct and restart server");
    icl_system_panic ("amq_peering", "E: hard error on peering");
    smt_shut_down ();
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_21 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_21))
    icl_stats_inc ("amq_peering_agent_unnamed_21", &s_amq_peering_agent_unnamed_21_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_peer_channel_open_ok (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_CHANNEL_OPEN_OK))
    icl_stats_inc ("amq_peering_agent_peer_channel_open_ok", &s_amq_peering_agent_peer_channel_open_ok_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_channel_open_ok_m->method;
        {
s_initialise_peering (self);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_23 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_23))
    icl_stats_inc ("amq_peering_agent_unnamed_23", &s_amq_peering_agent_unnamed_23_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_peer_basic_deliver (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_BASIC_DELIVER))
    icl_stats_inc ("amq_peering_agent_peer_basic_deliver", &s_amq_peering_agent_peer_basic_deliver_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_basic_deliver_m->method;
        {
if (self->content_fn)
    (self->content_fn) (self->content_caller, self, method);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_25 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_25))
    icl_stats_inc ("amq_peering_agent_unnamed_25", &s_amq_peering_agent_unnamed_25_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_peer_basic_return (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_PEER_BASIC_RETURN))
    icl_stats_inc ("amq_peering_agent_peer_basic_return", &s_amq_peering_agent_peer_basic_return_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{


#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_basic_return_m->method;
        {
if (self->return_fn)
    (self->return_fn) (self->return_caller, self, method);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_27 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT)  ||  defined (BASE_STATS_AMQ_PEERING_AGENT_UNNAMED_27))
    icl_stats_inc ("amq_peering_agent_unnamed_27", &s_amq_peering_agent_unnamed_27_stats);
#endif        
#define tcb ((amq_peering_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

