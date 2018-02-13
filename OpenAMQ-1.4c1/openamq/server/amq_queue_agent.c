/*---------------------------------------------------------------------------
    amq_queue_agent.c - functions for amq_queue_agent.

    Generated from amq_queue_agent.smt by smt_gen.gsl using GSL/4.

    
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
#include "amq_queue_agent.h"

#define class_main_state                           1
#define class_shutting_down_state                  2

#define destroy_m ((amq_queue_agent_destroy_t *) thread->method->data)

#define publish_m ((amq_queue_agent_publish_t *) thread->method->data)

#define get_m ((amq_queue_agent_get_t *) thread->method->data)

#define consume_m ((amq_queue_agent_consume_t *) thread->method->data)

#define cancel_m ((amq_queue_agent_cancel_t *) thread->method->data)

#define consumer_ack_m ((amq_queue_agent_consumer_ack_t *) thread->method->data)

#define purge_m ((amq_queue_agent_purge_t *) thread->method->data)

#define binding_register_m ((amq_queue_agent_binding_register_t *) thread->method->data)

#define binding_cancel_m ((amq_queue_agent_binding_cancel_t *) thread->method->data)

#define inspect_m ((amq_queue_agent_inspect_t *) thread->method->data)

#define modify_m ((amq_queue_agent_modify_t *) thread->method->data)

#define method_m ((amq_queue_agent_method_t *) thread->method->data)

enum {
    auto_delete_event                              = 1,
    shutdown_event                                 = 2,
    destroy_m_event                                = 3,
    cancel_m_event                                 = 4,
    unbind_connection_m_event                      = 5,
    publish_m_event                                = 6,
    get_m_event                                    = 7,
    consume_m_event                                = 8,
    self_destruct_m_event                          = 9,
    consumer_ack_m_event                           = 10,
    purge_m_event                                  = 11,
    dispatch_m_event                               = 12,
    binding_register_m_event                       = 13,
    binding_cancel_m_event                         = 14,
    inspect_m_event                                = 15,
    modify_m_event                                 = 16,
    method_m_event                                 = 17,
};

#define laststate                                  2
#define lastevent                                  17
#define lastplace                                  37

#define amq_queue_agent_agent_name                 "Amq-Queue-Agent"

#define class_thread_name                          "Class"

#define main_state_name                            "Main"
#define shutting_down_state_name                   "Shutting-Down"

#define auto_delete_event_name                     "Auto-Delete"
#define shutdown_event_name                        "Shutdown"
#define destroy_m_event_name                       "Destroy-M"
#define cancel_m_event_name                        "Cancel-M"
#define unbind_connection_m_event_name             "Unbind-Connection-M"
#define publish_m_event_name                       "Publish-M"
#define get_m_event_name                           "Get-M"
#define consume_m_event_name                       "Consume-M"
#define self_destruct_m_event_name                 "Self-Destruct-M"
#define consumer_ack_m_event_name                  "Consumer-Ack-M"
#define purge_m_event_name                         "Purge-M"
#define dispatch_m_event_name                      "Dispatch-M"
#define binding_register_m_event_name              "Binding-Register-M"
#define binding_cancel_m_event_name                "Binding-Cancel-M"
#define inspect_m_event_name                       "Inspect-M"
#define modify_m_event_name                        "Modify-M"
#define method_m_event_name                        "Method-M"

#define auto_delete_action_name                    "Auto-Delete"
#define destroy_action_name                        "Destroy"
#define free_action_name                           "Free"
#define unnamed_4_action_name                      "Unnamed-4"
#define cancel_action_name                         "Cancel"
#define unnamed_6_action_name                      "Unnamed-6"
#define unnamed_7_action_name                      "Unnamed-7"
#define unbind_connection_action_name              "Unbind-Connection"
#define unnamed_9_action_name                      "Unnamed-9"
#define publish_action_name                        "Publish"
#define unnamed_11_action_name                     "Unnamed-11"
#define get_action_name                            "Get"
#define unnamed_13_action_name                     "Unnamed-13"
#define consume_action_name                        "Consume"
#define unnamed_15_action_name                     "Unnamed-15"
#define unnamed_16_action_name                     "Unnamed-16"
#define self_destruct_action_name                  "Self-Destruct"
#define unnamed_18_action_name                     "Unnamed-18"
#define consumer_ack_action_name                   "Consumer-Ack"
#define unnamed_20_action_name                     "Unnamed-20"
#define purge_action_name                          "Purge"
#define unnamed_22_action_name                     "Unnamed-22"
#define dispatch_action_name                       "Dispatch"
#define unnamed_24_action_name                     "Unnamed-24"
#define binding_register_action_name               "Binding-Register"
#define unnamed_26_action_name                     "Unnamed-26"
#define binding_cancel_action_name                 "Binding-Cancel"
#define unnamed_28_action_name                     "Unnamed-28"
#define inspect_action_name                        "Inspect"
#define unnamed_30_action_name                     "Unnamed-30"
#define modify_action_name                         "Modify"
#define unnamed_32_action_name                     "Unnamed-32"
#define method_action_name                         "Method"
#define unnamed_34_action_name                     "Unnamed-34"

#define the_next_event                             thread->_next_event
#define exception_raised                           thread->_exception_raised

typedef struct
  {
    char *         file;
    size_t         line;
  }
amq_queue_agent_destroy_t;

typedef struct
  {
    amq_server_channel_t *  channel;
    amq_content_basic_t *  content;
    Bool           immediate;
  }
amq_queue_agent_publish_t;

typedef struct
  {
    amq_server_channel_t *  channel;
    int            class_id;
  }
amq_queue_agent_get_t;

typedef struct
  {
    amq_consumer_t *  consumer;
    Bool           active;
    Bool           nowait;
  }
amq_queue_agent_consume_t;

typedef struct
  {
    amq_consumer_t *  consumer;
    Bool           notify;
    Bool           nowait;
  }
amq_queue_agent_cancel_t;

typedef struct
  {
    amq_consumer_t *  consumer;
  }
amq_queue_agent_consumer_ack_t;

typedef struct
  {
    amq_server_channel_t *  channel;
    Bool           nowait;
  }
amq_queue_agent_purge_t;

typedef struct
  {
    amq_exchange_t *  exchange;
    amq_binding_t *  binding;
  }
amq_queue_agent_binding_register_t;

typedef struct
  {
    amq_exchange_t *  exchange;
    amq_binding_t *  binding;
  }
amq_queue_agent_binding_cancel_t;

typedef struct
  {
    amq_content_basic_t *  request;
  }
amq_queue_agent_inspect_t;

typedef struct
  {
    amq_content_basic_t *  request;
    asl_field_list_t *  fields;
  }
amq_queue_agent_modify_t;

typedef struct
  {
    char *         method_name;
    amq_content_basic_t *  request;
    asl_field_list_t *  fields;
  }
amq_queue_agent_method_t;

static icl_cache_t
    *s_class_context_cache = NULL;

typedef struct {
    int
        links;

        amq_queue_t
            *amq_queue;
    
} amq_queue_agent_class_context_t;

static icl_cache_t
    *s_destroy_cache = NULL;
static icl_cache_t
    *s_publish_cache = NULL;
static icl_cache_t
    *s_get_cache = NULL;
static icl_cache_t
    *s_consume_cache = NULL;
static icl_cache_t
    *s_cancel_cache = NULL;
static icl_cache_t
    *s_consumer_ack_cache = NULL;
static icl_cache_t
    *s_purge_cache = NULL;
static icl_cache_t
    *s_binding_register_cache = NULL;
static icl_cache_t
    *s_binding_cancel_cache = NULL;
static icl_cache_t
    *s_inspect_cache = NULL;
static icl_cache_t
    *s_modify_cache = NULL;
static icl_cache_t
    *s_method_cache = NULL;

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
    auto_delete_event_name,
    shutdown_event_name,
    destroy_m_event_name,
    cancel_m_event_name,
    unbind_connection_m_event_name,
    publish_m_event_name,
    get_m_event_name,
    consume_m_event_name,
    self_destruct_m_event_name,
    consumer_ack_m_event_name,
    purge_m_event_name,
    dispatch_m_event_name,
    binding_register_m_event_name,
    binding_cancel_m_event_name,
    inspect_m_event_name,
    modify_m_event_name,
    method_m_event_name
};

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT)          ||  defined (BASE_TRACE)  || defined (BASE_TRACE_AMQ_QUEUE_AGENT)   ||  defined (AMQ_QUEUE_AGENT_TRACE))
static const char *action_name [] = {
    "<NULL>",
    auto_delete_action_name,
    destroy_action_name,
    free_action_name,
    unnamed_4_action_name,
    cancel_action_name,
    unnamed_6_action_name,
    unnamed_7_action_name,
    unbind_connection_action_name,
    unnamed_9_action_name,
    publish_action_name,
    unnamed_11_action_name,
    get_action_name,
    unnamed_13_action_name,
    consume_action_name,
    unnamed_15_action_name,
    unnamed_16_action_name,
    self_destruct_action_name,
    unnamed_18_action_name,
    consumer_ack_action_name,
    unnamed_20_action_name,
    purge_action_name,
    unnamed_22_action_name,
    dispatch_action_name,
    unnamed_24_action_name,
    binding_register_action_name,
    unnamed_26_action_name,
    binding_cancel_action_name,
    unnamed_28_action_name,
    inspect_action_name,
    unnamed_30_action_name,
    modify_action_name,
    unnamed_32_action_name,
    method_action_name,
    unnamed_34_action_name
};
#endif

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
static Bool
    s_animate = FALSE;
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_AUTO_DELETE))
static icl_stats_t *s_amq_queue_agent_auto_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_DESTROY))
static icl_stats_t *s_amq_queue_agent_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_FREE))
static icl_stats_t *s_amq_queue_agent_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_4))
static icl_stats_t *s_amq_queue_agent_unnamed_4_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_CANCEL))
static icl_stats_t *s_amq_queue_agent_cancel_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_6))
static icl_stats_t *s_amq_queue_agent_unnamed_6_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_7))
static icl_stats_t *s_amq_queue_agent_unnamed_7_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNBIND_CONNECTION))
static icl_stats_t *s_amq_queue_agent_unbind_connection_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_9))
static icl_stats_t *s_amq_queue_agent_unnamed_9_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_PUBLISH))
static icl_stats_t *s_amq_queue_agent_publish_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_11))
static icl_stats_t *s_amq_queue_agent_unnamed_11_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_GET))
static icl_stats_t *s_amq_queue_agent_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_13))
static icl_stats_t *s_amq_queue_agent_unnamed_13_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_CONSUME))
static icl_stats_t *s_amq_queue_agent_consume_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_15))
static icl_stats_t *s_amq_queue_agent_unnamed_15_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_16))
static icl_stats_t *s_amq_queue_agent_unnamed_16_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_SELF_DESTRUCT))
static icl_stats_t *s_amq_queue_agent_self_destruct_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_18))
static icl_stats_t *s_amq_queue_agent_unnamed_18_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_CONSUMER_ACK))
static icl_stats_t *s_amq_queue_agent_consumer_ack_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_20))
static icl_stats_t *s_amq_queue_agent_unnamed_20_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_PURGE))
static icl_stats_t *s_amq_queue_agent_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_22))
static icl_stats_t *s_amq_queue_agent_unnamed_22_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_DISPATCH))
static icl_stats_t *s_amq_queue_agent_dispatch_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_24))
static icl_stats_t *s_amq_queue_agent_unnamed_24_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_BINDING_REGISTER))
static icl_stats_t *s_amq_queue_agent_binding_register_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_26))
static icl_stats_t *s_amq_queue_agent_unnamed_26_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_BINDING_CANCEL))
static icl_stats_t *s_amq_queue_agent_binding_cancel_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_28))
static icl_stats_t *s_amq_queue_agent_unnamed_28_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_INSPECT))
static icl_stats_t *s_amq_queue_agent_inspect_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_30))
static icl_stats_t *s_amq_queue_agent_unnamed_30_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_MODIFY))
static icl_stats_t *s_amq_queue_agent_modify_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_32))
static icl_stats_t *s_amq_queue_agent_unnamed_32_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_METHOD))
static icl_stats_t *s_amq_queue_agent_method_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_34))
static icl_stats_t *s_amq_queue_agent_unnamed_34_stats = NULL;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//  Function prototypes                                                        

static int    amq_queue_agent_manager         (smt_thread_t **thread);
static int    amq_queue_agent_catcher         (smt_thread_t *thread);
static int    amq_queue_agent_class_destroy   (smt_thread_t *thread);
static void   find_thread_state_next_state    (int          *thread_type,
                                               smt_state_t  *state_id,
                                               smt_event_t  *event_id,
                                               smt_state_t  *nextstate_id,
                                               smt_thread_t *thread);
static void   report_unrecognised_event_error (smt_thread_t *thread);
static void   report_state_machine_error      (smt_thread_t *thread);

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
static void   animate_start_new_event         (smt_thread_t *thread,
                                               smt_event_t  saveevent_id);
static void   animate_action                  (smt_thread_t *thread_id,
                                               int          action_id);
static int    find_thread_type                (smt_place_t  place);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_AGENT)            ||  defined (AMQ_QUEUE_AGENT_TRACE))
static void   s_dump                          (icl_os_thread_t apr_os_thread,
                                               apr_time_t      time,
                                               qbyte           info);

#endif

static int    action_auto_delete              (smt_thread_t *thread);
static int    action_destroy                  (smt_thread_t *thread);
static int    action_free                     (smt_thread_t *thread);
static int    action_unnamed_4                (smt_thread_t *thread);
static int    action_cancel                   (smt_thread_t *thread);
static int    action_unnamed_6                (smt_thread_t *thread);
static int    action_unnamed_7                (smt_thread_t *thread);
static int    action_unbind_connection        (smt_thread_t *thread);
static int    action_unnamed_9                (smt_thread_t *thread);
static int    action_publish                  (smt_thread_t *thread);
static int    action_unnamed_11               (smt_thread_t *thread);
static int    action_get                      (smt_thread_t *thread);
static int    action_unnamed_13               (smt_thread_t *thread);
static int    action_consume                  (smt_thread_t *thread);
static int    action_unnamed_15               (smt_thread_t *thread);
static int    action_unnamed_16               (smt_thread_t *thread);
static int    action_self_destruct            (smt_thread_t *thread);
static int    action_unnamed_18               (smt_thread_t *thread);
static int    action_consumer_ack             (smt_thread_t *thread);
static int    action_unnamed_20               (smt_thread_t *thread);
static int    action_purge                    (smt_thread_t *thread);
static int    action_unnamed_22               (smt_thread_t *thread);
static int    action_dispatch                 (smt_thread_t *thread);
static int    action_unnamed_24               (smt_thread_t *thread);
static int    action_binding_register         (smt_thread_t *thread);
static int    action_unnamed_26               (smt_thread_t *thread);
static int    action_binding_cancel           (smt_thread_t *thread);
static int    action_unnamed_28               (smt_thread_t *thread);
static int    action_inspect                  (smt_thread_t *thread);
static int    action_unnamed_30               (smt_thread_t *thread);
static int    action_modify                   (smt_thread_t *thread);
static int    action_unnamed_32               (smt_thread_t *thread);
static int    action_method                   (smt_thread_t *thread);
static int    action_unnamed_34               (smt_thread_t *thread);
static int
amq_queue_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line);
int
amq_queue_agent_destroy_destructor (void *data);
static int
amq_queue_agent_publish_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    amq_content_basic_t *  content,
    Bool           immediate);
int
amq_queue_agent_publish_destructor (void *data);
static int
amq_queue_agent_get_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    int            class_id);
int
amq_queue_agent_get_destructor (void *data);
static int
amq_queue_agent_consume_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_consumer_t *  consumer,
    Bool           active,
    Bool           nowait);
int
amq_queue_agent_consume_destructor (void *data);
static int
amq_queue_agent_cancel_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_consumer_t *  consumer,
    Bool           notify,
    Bool           nowait);
int
amq_queue_agent_cancel_destructor (void *data);
static int
amq_queue_agent_consumer_ack_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_consumer_t *  consumer);
int
amq_queue_agent_consumer_ack_destructor (void *data);
static int
amq_queue_agent_purge_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    Bool           nowait);
int
amq_queue_agent_purge_destructor (void *data);
static int
amq_queue_agent_binding_register_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_exchange_t *  exchange,
    amq_binding_t *  binding);
int
amq_queue_agent_binding_register_destructor (void *data);
static int
amq_queue_agent_binding_cancel_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_exchange_t *  exchange,
    amq_binding_t *  binding);
int
amq_queue_agent_binding_cancel_destructor (void *data);
static int
amq_queue_agent_inspect_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request);
int
amq_queue_agent_inspect_destructor (void *data);
static int
amq_queue_agent_modify_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields);
int
amq_queue_agent_modify_destructor (void *data);
static int
amq_queue_agent_method_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         method_name,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields);
int
amq_queue_agent_method_destructor (void *data);
//  Function definitions                                                       

static int
amq_queue_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line)
{
    int
        rc = 0;
    amq_queue_agent_destroy_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_destroy_cache);
    _message->file                      = file;
    _message->line                      = line;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_destroy_destructor);
    
    return rc;
}

int
amq_queue_agent_destroy_destructor (void *data)
{
    int
        rc = 0;
char * file;
size_t line;

    file = ((amq_queue_agent_destroy_t *) data)-> file;
    line = ((amq_queue_agent_destroy_t *) data)-> line;


    icl_mem_free (data);
    return rc;
}


static int
amq_queue_agent_publish_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    amq_content_basic_t *  content,
    Bool           immediate)
{
    int
        rc = 0;
    amq_queue_agent_publish_t
        *_message;
        
    //  Possess code for publish
    

    channel = amq_server_channel_link (channel);
    content = amq_content_basic_link (content);
    
    

    _message = icl_mem_cache_alloc (s_publish_cache);
    _message->channel                   = channel;
    _message->content                   = content;
    _message->immediate                 = immediate;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_publish_destructor);
    
    return rc;
}

int
amq_queue_agent_publish_destructor (void *data)
{
    int
        rc = 0;
amq_server_channel_t * channel;
amq_content_basic_t * content;
Bool immediate;

    channel = ((amq_queue_agent_publish_t *) data)-> channel;
    content = ((amq_queue_agent_publish_t *) data)-> content;
    immediate = ((amq_queue_agent_publish_t *) data)-> immediate;



    amq_server_channel_unlink (&channel);
    amq_content_basic_unlink (&content);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_queue_agent_get_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    int            class_id)
{
    int
        rc = 0;
    amq_queue_agent_get_t
        *_message;
        
    //  Possess code for get
    

    channel = amq_server_channel_link (channel);
    
    

    _message = icl_mem_cache_alloc (s_get_cache);
    _message->channel                   = channel;
    _message->class_id                  = class_id;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_get_destructor);
    
    return rc;
}

int
amq_queue_agent_get_destructor (void *data)
{
    int
        rc = 0;
amq_server_channel_t * channel;
int class_id;

    channel = ((amq_queue_agent_get_t *) data)-> channel;
    class_id = ((amq_queue_agent_get_t *) data)-> class_id;



    amq_server_channel_unlink (&channel);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_queue_agent_consume_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_consumer_t *  consumer,
    Bool           active,
    Bool           nowait)
{
    int
        rc = 0;
    amq_queue_agent_consume_t
        *_message;
        
    //  Possess code for consume
    

    consumer = amq_consumer_link (consumer);
    
    

    _message = icl_mem_cache_alloc (s_consume_cache);
    _message->consumer                  = consumer;
    _message->active                    = active;
    _message->nowait                    = nowait;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_consume_destructor);
    
    return rc;
}

int
amq_queue_agent_consume_destructor (void *data)
{
    int
        rc = 0;
amq_consumer_t * consumer;
Bool active;
Bool nowait;

    consumer = ((amq_queue_agent_consume_t *) data)-> consumer;
    active = ((amq_queue_agent_consume_t *) data)-> active;
    nowait = ((amq_queue_agent_consume_t *) data)-> nowait;



    amq_consumer_unlink (&consumer);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_queue_agent_cancel_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_consumer_t *  consumer,
    Bool           notify,
    Bool           nowait)
{
    int
        rc = 0;
    amq_queue_agent_cancel_t
        *_message;
        
    //  Possess code for cancel
    

    consumer = amq_consumer_link (consumer);
    
    

    _message = icl_mem_cache_alloc (s_cancel_cache);
    _message->consumer                  = consumer;
    _message->notify                    = notify;
    _message->nowait                    = nowait;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_cancel_destructor);
    
    return rc;
}

int
amq_queue_agent_cancel_destructor (void *data)
{
    int
        rc = 0;
amq_consumer_t * consumer;
Bool notify;
Bool nowait;

    consumer = ((amq_queue_agent_cancel_t *) data)-> consumer;
    notify = ((amq_queue_agent_cancel_t *) data)-> notify;
    nowait = ((amq_queue_agent_cancel_t *) data)-> nowait;



    amq_consumer_unlink (&consumer);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_queue_agent_consumer_ack_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_consumer_t *  consumer)
{
    int
        rc = 0;
    amq_queue_agent_consumer_ack_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_consumer_ack_cache);
    _message->consumer                  = consumer;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_consumer_ack_destructor);
    
    return rc;
}

int
amq_queue_agent_consumer_ack_destructor (void *data)
{
    int
        rc = 0;
amq_consumer_t * consumer;

    consumer = ((amq_queue_agent_consumer_ack_t *) data)-> consumer;


    icl_mem_free (data);
    return rc;
}


static int
amq_queue_agent_purge_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    Bool           nowait)
{
    int
        rc = 0;
    amq_queue_agent_purge_t
        *_message;
        
    //  Possess code for purge
    

    channel = amq_server_channel_link (channel);
    
    

    _message = icl_mem_cache_alloc (s_purge_cache);
    _message->channel                   = channel;
    _message->nowait                    = nowait;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_purge_destructor);
    
    return rc;
}

int
amq_queue_agent_purge_destructor (void *data)
{
    int
        rc = 0;
amq_server_channel_t * channel;
Bool nowait;

    channel = ((amq_queue_agent_purge_t *) data)-> channel;
    nowait = ((amq_queue_agent_purge_t *) data)-> nowait;



    amq_server_channel_unlink (&channel);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_queue_agent_binding_register_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_exchange_t *  exchange,
    amq_binding_t *  binding)
{
    int
        rc = 0;
    amq_queue_agent_binding_register_t
        *_message;
        
    //  Possess code for binding register
    

    exchange = amq_exchange_link (exchange);
    binding = amq_binding_link (binding);
    
    

    _message = icl_mem_cache_alloc (s_binding_register_cache);
    _message->exchange                  = exchange;
    _message->binding                   = binding;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_binding_register_destructor);
    
    return rc;
}

int
amq_queue_agent_binding_register_destructor (void *data)
{
    int
        rc = 0;
amq_exchange_t * exchange;
amq_binding_t * binding;

    exchange = ((amq_queue_agent_binding_register_t *) data)-> exchange;
    binding = ((amq_queue_agent_binding_register_t *) data)-> binding;



    amq_exchange_unlink (&exchange);
    amq_binding_unlink (&binding);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_queue_agent_binding_cancel_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_exchange_t *  exchange,
    amq_binding_t *  binding)
{
    int
        rc = 0;
    amq_queue_agent_binding_cancel_t
        *_message;
        
    //  Possess code for binding cancel
    

    exchange = amq_exchange_link (exchange);
    binding = amq_binding_link (binding);
    
    

    _message = icl_mem_cache_alloc (s_binding_cancel_cache);
    _message->exchange                  = exchange;
    _message->binding                   = binding;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_binding_cancel_destructor);
    
    return rc;
}

int
amq_queue_agent_binding_cancel_destructor (void *data)
{
    int
        rc = 0;
amq_exchange_t * exchange;
amq_binding_t * binding;

    exchange = ((amq_queue_agent_binding_cancel_t *) data)-> exchange;
    binding = ((amq_queue_agent_binding_cancel_t *) data)-> binding;



    amq_exchange_unlink (&exchange);
    amq_binding_unlink (&binding);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_queue_agent_inspect_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request)
{
    int
        rc = 0;
    amq_queue_agent_inspect_t
        *_message;
        
    //  Possess code for inspect
    

    request = amq_content_basic_link (request);
    
    

    _message = icl_mem_cache_alloc (s_inspect_cache);
    _message->request                   = request;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_inspect_destructor);
    
    return rc;
}

int
amq_queue_agent_inspect_destructor (void *data)
{
    int
        rc = 0;
amq_content_basic_t * request;

    request = ((amq_queue_agent_inspect_t *) data)-> request;



    amq_content_basic_unlink (&request);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_queue_agent_modify_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields)
{
    int
        rc = 0;
    amq_queue_agent_modify_t
        *_message;
        
    //  Possess code for modify
    

    request = amq_content_basic_link (request);
    asl_field_list_link (fields);
    
    

    _message = icl_mem_cache_alloc (s_modify_cache);
    _message->request                   = request;
    _message->fields                    = fields;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_modify_destructor);
    
    return rc;
}

int
amq_queue_agent_modify_destructor (void *data)
{
    int
        rc = 0;
amq_content_basic_t * request;
asl_field_list_t * fields;

    request = ((amq_queue_agent_modify_t *) data)-> request;
    fields = ((amq_queue_agent_modify_t *) data)-> fields;



    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_queue_agent_method_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         method_name,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields)
{
    int
        rc = 0;
    amq_queue_agent_method_t
        *_message;
        
    //  Possess code for method
    

    method_name = icl_mem_strdup (method_name);
    request = amq_content_basic_link (request);
    fields  = asl_field_list_link (fields);
    
    

    _message = icl_mem_cache_alloc (s_method_cache);
    _message->method_name               = method_name;
    _message->request                   = request;
    _message->fields                    = fields;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_queue_agent_method_destructor);
    
    return rc;
}

int
amq_queue_agent_method_destructor (void *data)
{
    int
        rc = 0;
char * method_name;
amq_content_basic_t * request;
asl_field_list_t * fields;

    method_name = ((amq_queue_agent_method_t *) data)-> method_name;
    request = ((amq_queue_agent_method_t *) data)-> request;
    fields = ((amq_queue_agent_method_t *) data)-> fields;



    icl_mem_free (method_name);
    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    
    

    icl_mem_free (data);
    return rc;
}


int
amq_queue_agent_unbind_connection (
    smt_thread_t * thread)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = smt_method_send (
                thread->reply_queue,
                unbind_connection_m_event,
                SMT_PRIORITY_NORMAL,
                SMT_OK, NULL, NULL);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_self_destruct (
    smt_thread_t * thread)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = smt_method_send (
                thread->reply_queue,
                self_destruct_m_event,
                SMT_PRIORITY_NORMAL,
                SMT_OK, NULL, NULL);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_dispatch (
    smt_thread_t * thread)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = smt_method_send (
                thread->reply_queue,
                dispatch_m_event,
                SMT_PRIORITY_NORMAL,
                SMT_OK, NULL, NULL);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_destroy_send (
                thread->reply_queue, destroy_m_event,
                file,
                line);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_publish (
    smt_thread_t * thread,
    amq_server_channel_t * channel,
    amq_content_basic_t * content,
    Bool                  immediate)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_publish_send (
                thread->reply_queue, publish_m_event,
                channel,
                content,
                immediate);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_get (
    smt_thread_t * thread,
    amq_server_channel_t * channel,
    int                   class_id)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_get_send (
                thread->reply_queue, get_m_event,
                channel,
                class_id);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_consume (
    smt_thread_t * thread,
    amq_consumer_t *      consumer,
    Bool                  active,
    Bool                  nowait)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_consume_send (
                thread->reply_queue, consume_m_event,
                consumer,
                active,
                nowait);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_cancel (
    smt_thread_t * thread,
    amq_consumer_t *      consumer,
    Bool                  notify,
    Bool                  nowait)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_cancel_send (
                thread->reply_queue, cancel_m_event,
                consumer,
                notify,
                nowait);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_consumer_ack (
    smt_thread_t * thread,
    amq_consumer_t *      consumer)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_consumer_ack_send (
                thread->reply_queue, consumer_ack_m_event,
                consumer);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_purge (
    smt_thread_t * thread,
    amq_server_channel_t * channel,
    Bool                  nowait)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_purge_send (
                thread->reply_queue, purge_m_event,
                channel,
                nowait);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_binding_register (
    smt_thread_t * thread,
    amq_exchange_t *      exchange,
    amq_binding_t *       binding)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_binding_register_send (
                thread->reply_queue, binding_register_m_event,
                exchange,
                binding);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_binding_cancel (
    smt_thread_t * thread,
    amq_exchange_t *      exchange,
    amq_binding_t *       binding)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_binding_cancel_send (
                thread->reply_queue, binding_cancel_m_event,
                exchange,
                binding);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_inspect (
    smt_thread_t * thread,
    amq_content_basic_t * request)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_inspect_send (
                thread->reply_queue, inspect_m_event,
                request);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_modify (
    smt_thread_t * thread,
    amq_content_basic_t * request,
    asl_field_list_t *    fields)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_modify_send (
                thread->reply_queue, modify_m_event,
                request,
                fields);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_queue_agent_method (
    smt_thread_t * thread,
    char *                method_name,
    amq_content_basic_t * request,
    asl_field_list_t *    fields)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_queue_agent_manager);
        rc = amq_queue_agent_method_send (
                thread->reply_queue, method_m_event,
                method_name,
                request,
                fields);
    }
    else
        rc = -1;
        
    return rc;
}

void
amq_queue_agent_term (void)
{

}

int 
amq_queue_agent_init (void)
{
    int
        rc = SMT_OK;                    //  Return code

    s_class_context_cache = icl_cache_get (sizeof (amq_queue_agent_class_context_t));
    s_destroy_cache = icl_cache_get (sizeof (amq_queue_agent_destroy_t));
    s_publish_cache = icl_cache_get (sizeof (amq_queue_agent_publish_t));
    s_get_cache = icl_cache_get (sizeof (amq_queue_agent_get_t));
    s_consume_cache = icl_cache_get (sizeof (amq_queue_agent_consume_t));
    s_cancel_cache = icl_cache_get (sizeof (amq_queue_agent_cancel_t));
    s_consumer_ack_cache = icl_cache_get (sizeof (amq_queue_agent_consumer_ack_t));
    s_purge_cache = icl_cache_get (sizeof (amq_queue_agent_purge_t));
    s_binding_register_cache = icl_cache_get (sizeof (amq_queue_agent_binding_register_t));
    s_binding_cancel_cache = icl_cache_get (sizeof (amq_queue_agent_binding_cancel_t));
    s_inspect_cache = icl_cache_get (sizeof (amq_queue_agent_inspect_t));
    s_modify_cache = icl_cache_get (sizeof (amq_queue_agent_modify_t));
    s_method_cache = icl_cache_get (sizeof (amq_queue_agent_method_t));

    //  Initialise basic stuff.
    smt_initialise ();
    
    {

    }
    icl_system_register (NULL, amq_queue_agent_term);
    
    return rc;
}

void
amq_queue_agent_animate (Bool animate)
{
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
    s_animate = animate;
#endif
}

smt_thread_t *
amq_queue_agent_class_thread_new (
    amq_queue_t * self)
{
    smt_thread_t
        *thread;

    thread = smt_thread_new (amq_queue_agent_manager,
                             amq_queue_agent_catcher,
                             amq_queue_agent_class_destroy);
                             

#if (defined (AMQ_QUEUE_AGENT_TRACE))
    thread->trace = icl_trace_new (ICL_TRACE_SIZE);
#endif

    if (thread) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
        thread->animate = s_animate;
        if (s_animate)
            icl_console_print ("%4lu> %-15s/%-15s <Created>",
                thread->id,
                "amq_queue_agent",
                class_thread_name);
#endif

        thread->place   = 1;
        thread->context = icl_mem_cache_alloc (s_class_context_cache);
        memset (thread->context, 0, sizeof (amq_queue_agent_class_context_t));
        ((amq_queue_agent_class_context_t *) thread->context)->links = 1;
        thread->event_name = event_name;
{
#define tcb ((amq_queue_agent_class_context_t *) thread->context)

        tcb->amq_queue = self;
    
#undef  tcb
}
    }
    return thread;
}


static int
amq_queue_agent_manager (smt_thread_t **thread_p)
{
    smt_thread_t
        *thread = *thread_p;
        
    int
        rc;
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))

    smt_event_t
        saveevent_id = SMT_NULL_EVENT;
#endif
        
    assert (thread->manager == amq_queue_agent_manager);
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
            case 37:
            case 22:
                thread->place = SMT_TERM_PLACE;
                break;
            case 14:
            case 3:
            case 17:
            case 18:
            case 13:
            case 9:
            case 15:
            case 11:
            case 12:
            case 6:
            case 10:
            case 8:
            case 7:
            case 16:
            case 19:
                thread->place = 2;
                break;
            case 36:
            case 35:
            case 31:
            case 34:
            case 33:
            case 27:
            case 32:
            case 29:
            case 30:
            case 4:
            case 21:
            case 28:
            case 23:
            case 24:
            case 25:
            case 26:
                thread->place = 20;
                break;
        }    
    else
    if (thread->module == 0) {
        if (thread->place == 1) { //                Class thread
            if (!thread->shutting_down) {
{
#define tcb ((amq_queue_agent_class_context_t *) thread->context)

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
        if (thread->place < 20)                 //  Main state
            thread->place = 2;
        else
            thread->place = 20;
    }

    switch (thread->place) {
        case 2:                         //  main state                          
{
#define tcb ((amq_queue_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case auto_delete_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 3; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 4; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 5; break;
                case unbind_connection_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 6; break;
                case publish_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 7; break;
                case get_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 8; break;
                case consume_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 9; break;
                case cancel_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 10; break;
                case self_destruct_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 11; break;
                case consumer_ack_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 12; break;
                case purge_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 13; break;
                case dispatch_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 14; break;
                case binding_register_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
                    thread->place = 15; break;
                case binding_cancel_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
                    thread->place = 16; break;
                case inspect_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
                    thread->place = 17; break;
                case modify_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
                    thread->place = 18; break;
                case method_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 17);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 17);
#endif
                    thread->place = 19; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
        case 20:                        //  shutting down state                 
{
#define tcb ((amq_queue_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case auto_delete_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 21; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 22; break;
                case cancel_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 23; break;
                case unbind_connection_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 24; break;
                case publish_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 25; break;
                case get_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 26; break;
                case consume_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 27; break;
                case self_destruct_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 28; break;
                case consumer_ack_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 29; break;
                case purge_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 30; break;
                case dispatch_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 31; break;
                case binding_register_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
                    thread->place = 32; break;
                case binding_cancel_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
                    thread->place = 33; break;
                case inspect_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
                    thread->place = 34; break;
                case modify_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
                    thread->place = 35; break;
                case method_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 17);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 17);
#endif
                    thread->place = 36; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 37; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
    }
                                  
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
    if (thread->animate && thread->module == 1)
        animate_start_new_event (thread, saveevent_id);
#endif

    switch (thread->place) {
        case 3:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 1);
#endif
                    rc = action_auto_delete (thread);

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
        case 21:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
            switch (thread->module) {
                case 1:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    if (thread->place == 37)
                        thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 22:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
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
        case 23:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 5);
#endif
                    rc = action_cancel (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 6);
#endif
                    rc = action_unnamed_6 (thread);

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
        case 5:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 8);
#endif
                    rc = action_unbind_connection (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
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
        case 7:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 10);
#endif
                    rc = action_publish (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
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
        case 8:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 12);
#endif
                    rc = action_get (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
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
        case 9:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 14);
#endif
                    rc = action_consume (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
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
        case 10:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 5);
#endif
                    rc = action_cancel (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 16);
#endif
                    rc = action_unnamed_16 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 17);
#endif
                    rc = action_self_destruct (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 18);
#endif
                    rc = action_unnamed_18 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 19);
#endif
                    rc = action_consumer_ack (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 20);
#endif
                    rc = action_unnamed_20 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 21);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 21);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 21);
#endif
                    rc = action_purge (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 22);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 22);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 22);
#endif
                    rc = action_unnamed_22 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 23);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 23);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 23);
#endif
                    rc = action_dispatch (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 24);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 24);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 24);
#endif
                    rc = action_unnamed_24 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 25);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 25);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 25);
#endif
                    rc = action_binding_register (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 26);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 26);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 26);
#endif
                    rc = action_unnamed_26 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 27);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 27);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 27);
#endif
                    rc = action_binding_cancel (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 28);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 28);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 28);
#endif
                    rc = action_unnamed_28 (thread);

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
        case 17:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 29);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 29);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 29);
#endif
                    rc = action_inspect (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 30);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 30);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 30);
#endif
                    rc = action_unnamed_30 (thread);

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
        case 18:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 31);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 31);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 31);
#endif
                    rc = action_modify (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 32);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 32);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 32);
#endif
                    rc = action_unnamed_32 (thread);

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
        case 19:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 33);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 33);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 33);
#endif
                    rc = action_method (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 34);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 34);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 34);
#endif
                    rc = action_unnamed_34 (thread);

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
amq_queue_agent_catcher (smt_thread_t *thread)
{
    return SMT_OK;
}


static int    
amq_queue_agent_class_destroy (smt_thread_t *thread)
{
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (AMQ_QUEUE_AGENT_TRACE))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))
    if (thread->animate)
        icl_console_print ("%4lu> %-15s/%-15s <Destroyed>",
                  thread->id,
                  "amq_queue_agent",
                 class_thread_name);

#endif
    if (--((amq_queue_agent_class_context_t *) thread->context)->links == 0)
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
        if (thread->place < 20)
          {
            *state_id = 1;
            switch (thread->place) {
                case 3: *event_id = 1;   *nextstate_id = 1;   break;
                case 4: *event_id = 2;   *nextstate_id = 2;   break;
                case 5: *event_id = 3;   break;
                case 6: *event_id = 5;   *nextstate_id = 1;   break;
                case 7: *event_id = 6;   *nextstate_id = 1;   break;
                case 8: *event_id = 7;   *nextstate_id = 1;   break;
                case 9: *event_id = 8;   *nextstate_id = 1;   break;
                case 10: *event_id = 4;   *nextstate_id = 1;   break;
                case 11: *event_id = 9;   *nextstate_id = 1;   break;
                case 12: *event_id = 10;   *nextstate_id = 1;   break;
                case 13: *event_id = 11;   *nextstate_id = 1;   break;
                case 14: *event_id = 12;   *nextstate_id = 1;   break;
                case 15: *event_id = 13;   *nextstate_id = 1;   break;
                case 16: *event_id = 14;   *nextstate_id = 1;   break;
                case 17: *event_id = 15;   *nextstate_id = 1;   break;
                case 18: *event_id = 16;   *nextstate_id = 1;   break;
                case 19: *event_id = 17;   *nextstate_id = 1;   break;
            }
          }
        else
          {
            *state_id = 2;
            switch (thread->place) {
                case 21: *event_id = 1;   *nextstate_id = 2;   break;
                case 22: *event_id = 3;   break;
                case 23: *event_id = 4;   *nextstate_id = 2;   break;
                case 24: *event_id = 5;   *nextstate_id = 2;   break;
                case 25: *event_id = 6;   *nextstate_id = 2;   break;
                case 26: *event_id = 7;   *nextstate_id = 2;   break;
                case 27: *event_id = 8;   *nextstate_id = 2;   break;
                case 28: *event_id = 9;   *nextstate_id = 2;   break;
                case 29: *event_id = 10;   *nextstate_id = 2;   break;
                case 30: *event_id = 11;   *nextstate_id = 2;   break;
                case 31: *event_id = 12;   *nextstate_id = 2;   break;
                case 32: *event_id = 13;   *nextstate_id = 2;   break;
                case 33: *event_id = 14;   *nextstate_id = 2;   break;
                case 34: *event_id = 15;   *nextstate_id = 2;   break;
                case 35: *event_id = 16;   *nextstate_id = 2;   break;
                case 36: *event_id = 17;   *nextstate_id = 2;   break;
                case 37: *event_id = 2;   break;
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
    icl_console_print ("amq_queue_agent: Unrecognised event '%s' in '%s' thread number: %u, state: %s",
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

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_QUEUE_AGENT))

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
            "amq_queue_agent",
            thread_name [thread_type],
            state_name [state_id]);
  icl_console_print ("%4lu> %-15s/%-15s    (--) %-32s->%s",
            thread->id,
            "amq_queue_agent",
            thread_name [thread_type],
            event_name [event_id != SMT_NULL_EVENT ? event_id : saveevent_id],
            nextstate_id ? state_name [nextstate_id] : "");
}

static void
animate_action (smt_thread_t *thread, int action_id)
{
    icl_console_print ("%4lu> %-15s/%-15s           + %s",
              thread->id,
              "amq_queue_agent",
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_QUEUE_AGENT)              ||  defined (AMQ_QUEUE_AGENT_TRACE))
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
                                       "amq_queue_agent",
                                       action_name [action_id]);
    }
    else
    if (state_or_event_or_action > laststate) {
        event_id = state_or_event_or_action - laststate;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s    (--) %-32s",
                                       thread_id,
                                       "amq_queue_agent",
                                       event_name [event_id]);
    }
    else {
        state_id = state_or_event_or_action;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s %s:",
                                       thread_id,
                                       "amq_queue_agent",
                                       state_id ? state_name [state_id] : "<Destroyed>");
    }
}

#endif
static int
action_auto_delete (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_AUTO_DELETE))
    icl_stats_inc ("amq_queue_agent_auto_delete", &s_amq_queue_agent_auto_delete_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            
#define self tcb->amq_queue

        {
//  If we're still at zero consumers, self-destruct
if (amq_queue_basic_consumer_count (self->queue_basic) == 0) {
    if (amq_server_config_debug_queue (amq_server_config))
        smt_log_print (amq_broker->debug_log, "Q: auto-del queue=%s", self->name);

    amq_queue_self_destruct (self);
}
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_DESTROY))
    icl_stats_inc ("amq_queue_agent_destroy", &s_amq_queue_agent_destroy_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

icl_atomic_dec32 ((volatile qbyte *) &gbl_amq_queue_count);

    {
ipr_looseref_t
    *looseref;
amq_queue_binding_t
    *queue_binding;

amq_server_connection_unlink (&self->connection);
if (amq_server_config_debug_queue (amq_server_config))
    smt_log_print (amq_broker->debug_log, "Q: destroy  queue=%s", self->name);

amq_queue_basic_destroy (&self->queue_basic);

//  Destroy management list of bindings for queue
looseref = ipr_looseref_list_first (self->bindings);
while (looseref) {
    queue_binding = (amq_queue_binding_t *) (looseref->object);
    amq_queue_binding_destroy (&queue_binding);
    looseref = ipr_looseref_list_next (&looseref);
}
ipr_looseref_list_destroy (&self->bindings);
    }
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_FREE))
    icl_stats_inc ("amq_queue_agent_free", &s_amq_queue_agent_free_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_queue object");
    amq_queue_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_queue_free (self);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_4))
    icl_stats_inc ("amq_queue_agent_unnamed_4", &s_amq_queue_agent_unnamed_4_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_cancel (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_CANCEL))
    icl_stats_inc ("amq_queue_agent_cancel", &s_amq_queue_agent_cancel_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
amq_consumer_t *
    consumer;
Bool
    notify;
Bool
    nowait;

    consumer = cancel_m->consumer;
    notify = cancel_m->notify;
    nowait = cancel_m->nowait;
        {
amq_server_connection_t
    *connection;
amq_server_channel_t
    *channel;

if (notify && !nowait) {
    channel = amq_server_channel_link (consumer->channel);
    if (channel) {
        connection = amq_server_connection_link (channel->connection);
        if (connection) {
            amq_server_agent_basic_cancel_ok (
                connection->thread, channel->number, consumer->tag);
            amq_server_connection_unlink (&connection);
        }
        amq_server_channel_unlink (&channel);
    }
}
amq_queue_basic_cancel (self->queue_basic, consumer);

self->feed_on = FALSE;              //  Stop direct feed from queue, if any
self->locked = FALSE;
if (self->auto_delete && amq_queue_basic_consumer_count (self->queue_basic) == 0) {
    int
        timeout = amq_server_config_queue_timeout (amq_server_config);
    if (timeout)
        smt_timer_request_delay (self->thread, timeout * 1000 * 1000, auto_delete_event);
    else {
        if (amq_server_config_debug_queue (amq_server_config))
            smt_log_print (amq_broker->debug_log, "Q: auto-del queue=%s", self->name);
        amq_queue_self_destruct (self);
    }
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_6 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_6))
    icl_stats_inc ("amq_queue_agent_unnamed_6", &s_amq_queue_agent_unnamed_6_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_7 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_7))
    icl_stats_inc ("amq_queue_agent_unnamed_7", &s_amq_queue_agent_unnamed_7_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unbind_connection (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNBIND_CONNECTION))
    icl_stats_inc ("amq_queue_agent_unbind_connection", &s_amq_queue_agent_unbind_connection_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue

        {
amq_queue_t
    *queue_ref;                     //  Need a reference to call destroy

assert (self->connection);
assert (self->auto_delete);
if (amq_queue_basic_consumer_count (self->queue_basic) == 0) {
    if (amq_server_config_debug_queue (amq_server_config))
        smt_log_print (amq_broker->debug_log, "Q: auto-del queue=%s", self->name);

    queue_ref = amq_queue_link (self);
    amq_broker_delete_queue (amq_broker, queue_ref);
    //  Ask broker to ask connections to drop link to queue
    if (self->exclusive)
        amq_broker_unbind_queue (amq_broker, queue_ref);

    //  Tell console to drop link back to queue
    amq_console_cancel (self->console, self->object_id);
    amq_queue_unlink (&queue_ref);
}
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_9))
    icl_stats_inc ("amq_queue_agent_unnamed_9", &s_amq_queue_agent_unnamed_9_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_publish (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_PUBLISH))
    icl_stats_inc ("amq_queue_agent_publish", &s_amq_queue_agent_publish_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
amq_server_channel_t *
    channel;
amq_content_basic_t *
    content;
Bool
    immediate;

    channel = publish_m->channel;
    content = publish_m->content;
    immediate = publish_m->immediate;
        {
if (self->enabled)
    amq_queue_basic_publish (self->queue_basic, channel, content, immediate);
else
    amq_server_channel_error (channel, ASL_ACCESS_REFUSED, "Queue is disabled",
        AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_PUBLISH);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_11))
    icl_stats_inc ("amq_queue_agent_unnamed_11", &s_amq_queue_agent_unnamed_11_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_get (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_GET))
    icl_stats_inc ("amq_queue_agent_get", &s_amq_queue_agent_get_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
amq_server_channel_t *
    channel;
int
    class_id;

    channel = get_m->channel;
    class_id = get_m->class_id;
        {
amq_queue_basic_get (self->queue_basic, channel);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_13))
    icl_stats_inc ("amq_queue_agent_unnamed_13", &s_amq_queue_agent_unnamed_13_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_consume (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_CONSUME))
    icl_stats_inc ("amq_queue_agent_consume", &s_amq_queue_agent_consume_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
amq_consumer_t *
    consumer;
Bool
    active;
Bool
    nowait;

    consumer = consume_m->consumer;
    active = consume_m->active;
    nowait = consume_m->nowait;
        {
//
char
    *error = NULL;                  //  If not null, consumer is invalid
amq_server_connection_t
    *connection;
amq_server_channel_t
    *channel;

//  Validate consumer
channel = amq_server_channel_link (consumer->channel);
if (channel)
    connection = amq_server_connection_link (channel->connection);
else
    connection = NULL;

if (self->exclusive && self->connection != connection)
    error = "Queue is exclusive to another connection";
else
if (consumer->exclusive) {
    if (amq_queue_basic_consumer_count (self->queue_basic) == 0)
        self->locked = TRUE;        //  Grant exclusive access
    else
        error = "Exclusive access to queue not possible";
}
else
if (self->locked)
    error = "Queue is being used exclusively by another consumer";

if (error) {
    if (channel) {
        amq_server_channel_error (channel, ASL_ACCESS_REFUSED,
            error, AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_CONSUME);
        amq_server_channel_cancel (channel, consumer->tag, FALSE, TRUE);
    }
}
else {
    consumer->paused = !active;
    self->feed_on = active;
    self->feed_no_local = consumer->no_local;
    amq_queue_basic_consume (self->queue_basic, consumer);
    if (connection && !nowait)
        amq_server_agent_basic_consume_ok (
            connection->thread, channel->number, consumer->tag);
    amq_queue_dispatch (self);
}
amq_server_connection_unlink (&connection);
amq_server_channel_unlink (&channel);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_15))
    icl_stats_inc ("amq_queue_agent_unnamed_15", &s_amq_queue_agent_unnamed_15_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_16 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_16))
    icl_stats_inc ("amq_queue_agent_unnamed_16", &s_amq_queue_agent_unnamed_16_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_self_destruct (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_SELF_DESTRUCT))
    icl_stats_inc ("amq_queue_agent_self_destruct", &s_amq_queue_agent_self_destruct_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue

        {
amq_queue_t
    *queue_ref;                     //  Need a reference to call destroy

queue_ref = amq_queue_link (self);
amq_broker_delete_queue (amq_broker, queue_ref);
//  Ask broker to ask connections to drop link to queue
if (self->exclusive)
    amq_broker_unbind_queue (amq_broker, queue_ref);

//  Stop consumers because they link back to queue
amq_queue_basic_stop (self->queue_basic);
//  Tell console to drop link back to queue
amq_console_cancel (self->console, self->object_id);
amq_queue_unlink (&queue_ref);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_18 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_18))
    icl_stats_inc ("amq_queue_agent_unnamed_18", &s_amq_queue_agent_unnamed_18_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_consumer_ack (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_CONSUMER_ACK))
    icl_stats_inc ("amq_queue_agent_consumer_ack", &s_amq_queue_agent_consumer_ack_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
amq_consumer_t *
    consumer;

    consumer = consumer_ack_m->consumer;
        {
amq_queue_basic_consumer_ack (self->queue_basic, consumer);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_20 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_20))
    icl_stats_inc ("amq_queue_agent_unnamed_20", &s_amq_queue_agent_unnamed_20_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_purge (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_PURGE))
    icl_stats_inc ("amq_queue_agent_purge", &s_amq_queue_agent_purge_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
amq_server_channel_t *
    channel;
Bool
    nowait;

    channel = purge_m->channel;
    nowait = purge_m->nowait;
        {
long
    messages = 0;
amq_server_connection_t
    *connection;

messages += amq_queue_basic_purge (self->queue_basic);
if (!nowait) {
    connection = channel?
        amq_server_connection_link (channel->connection): NULL;
    if (connection) {
        amq_server_agent_queue_purge_ok (
            connection->thread, channel->number, messages);
        amq_server_connection_unlink (&connection);
    }
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_22 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_22))
    icl_stats_inc ("amq_queue_agent_unnamed_22", &s_amq_queue_agent_unnamed_22_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_dispatch (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_DISPATCH))
    icl_stats_inc ("amq_queue_agent_dispatch", &s_amq_queue_agent_dispatch_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue

        {
amq_queue_basic_dispatch (self->queue_basic);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_24 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_24))
    icl_stats_inc ("amq_queue_agent_unnamed_24", &s_amq_queue_agent_unnamed_24_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_binding_register (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_BINDING_REGISTER))
    icl_stats_inc ("amq_queue_agent_binding_register", &s_amq_queue_agent_binding_register_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
amq_exchange_t *
    exchange;
amq_binding_t *
    binding;

    exchange = binding_register_m->exchange;
    binding = binding_register_m->binding;
        {
ipr_looseref_queue (self->bindings, amq_queue_binding_new (self, exchange, binding));
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_26 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_26))
    icl_stats_inc ("amq_queue_agent_unnamed_26", &s_amq_queue_agent_unnamed_26_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_binding_cancel (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_BINDING_CANCEL))
    icl_stats_inc ("amq_queue_agent_binding_cancel", &s_amq_queue_agent_binding_cancel_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
amq_exchange_t *
    exchange;
amq_binding_t *
    binding;

    exchange = binding_cancel_m->exchange;
    binding = binding_cancel_m->binding;
        {
amq_queue_binding_t
    *queue_binding;
ipr_looseref_t
    *looseref;

looseref = ipr_looseref_list_first (self->bindings);
while (looseref) {
    queue_binding = (amq_queue_binding_t *) (looseref->object);
    if (queue_binding->exchange == exchange
    &&  queue_binding->binding == binding) {
        ipr_looseref_list_remove (looseref);
        amq_queue_binding_destroy (&queue_binding);
        break;
    }
    looseref = ipr_looseref_list_next (&looseref);
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_28 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_28))
    icl_stats_inc ("amq_queue_agent_unnamed_28", &s_amq_queue_agent_unnamed_28_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_inspect (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_INSPECT))
    icl_stats_inc ("amq_queue_agent_inspect", &s_amq_queue_agent_inspect_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
amq_content_basic_t *
    request;

    request = inspect_m->request;
        {
asl_field_list_t
    *fields;                        //  Properties of object
icl_shortstr_t
    field_value;
            amq_server_connection_t
            *connection;
            amq_consumer_t
            *consumer;              //  Consumer object reference
            amq_queue_binding_t
            *queue_binding;
        ipr_looseref_t
            *looseref;

fields = asl_field_list_new (NULL);
icl_shortstr_cpy (field_value, self->name);
asl_field_new_string (fields, "name", field_value);
icl_shortstr_fmt (field_value, "%d", amq_queue_message_count (self));
asl_field_new_string (fields, "pending", field_value);
icl_shortstr_fmt (field_value, "%d", self->exclusive);
asl_field_new_string (fields, "exclusive", field_value);
            connection = amq_server_connection_link (self->connection);
        if (connection) {
            icl_shortstr_cpy (field_value, connection->client_address);
            amq_server_connection_unlink (&connection);
        }
        else
            icl_shortstr_cpy (field_value, "");
asl_field_new_string (fields, "client", field_value);
icl_shortstr_cpy (field_value, self->last_exchange_name);
asl_field_new_string (fields, "exchange_name", field_value);
icl_shortstr_cpy (field_value, self->last_exchange_type);
asl_field_new_string (fields, "exchange_type", field_value);
icl_shortstr_cpy (field_value, self->last_routing_key);
asl_field_new_string (fields, "routing_key", field_value);
icl_shortstr_cpy (field_value, self->last_binding_args);
asl_field_new_string (fields, "binding_args", field_value);
icl_shortstr_fmt (field_value, "%d", self->auto_delete);
asl_field_new_string (fields, "auto_delete", field_value);
icl_shortstr_fmt (field_value, "%d", amq_queue_basic_consumer_count (self->queue_basic));
asl_field_new_string (fields, "consumers", field_value);
icl_shortstr_fmt (field_value, "%d", self->contents_in);
asl_field_new_string (fields, "messages_in", field_value);
icl_shortstr_fmt (field_value, "%d", self->contents_out);
asl_field_new_string (fields, "messages_out", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (self->traffic_in / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_in", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (self->traffic_out / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_out", field_value);
icl_shortstr_fmt (field_value, "%d", self->drop_count);
asl_field_new_string (fields, "drop_count", field_value);
strclr (field_value);
            consumer = amq_consumer_by_queue_first (self->queue_basic->consumer_list);
        if (consumer)
            icl_shortstr_fmt (field_value, "%d", consumer->mgt_queue_connection->object_id);
while (*field_value) {
    asl_field_new_string (fields, "queue_connection", field_value);
    strclr (field_value);
            consumer = amq_consumer_by_queue_next (&consumer);
        if (consumer)
            icl_shortstr_fmt (field_value, "%d", consumer->mgt_queue_connection->object_id);
}
strclr (field_value);
            looseref = ipr_looseref_list_first (self->bindings);
        if (looseref) {
            queue_binding = (amq_queue_binding_t *) (looseref->object);
            icl_shortstr_fmt (field_value, "%d", queue_binding->object_id);
        }
while (*field_value) {
    asl_field_new_string (fields, "queue_binding", field_value);
    strclr (field_value);
            looseref = ipr_looseref_list_next (&looseref);
        if (looseref) {
            queue_binding = (amq_queue_binding_t *) (looseref->object);
            icl_shortstr_fmt (field_value, "%d", queue_binding->object_id);
        }
}
amq_console_reply_ok (amq_console, "inspect-reply", request, self->object_id, fields, NULL);
asl_field_list_unlink (&fields);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_30 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_30))
    icl_stats_inc ("amq_queue_agent_unnamed_30", &s_amq_queue_agent_unnamed_30_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_modify (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_MODIFY))
    icl_stats_inc ("amq_queue_agent_modify", &s_amq_queue_agent_modify_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
amq_content_basic_t *
    request;
asl_field_list_t *
    fields;

    request = modify_m->request;
    fields = modify_m->fields;
        {
char
    *notice_text = NULL;            //  Notice to UI, if any

amq_console_reply_ok (
    amq_console, "modify-reply", request, self->object_id, NULL, notice_text);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_32 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_32))
    icl_stats_inc ("amq_queue_agent_unnamed_32", &s_amq_queue_agent_unnamed_32_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_method (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_METHOD))
    icl_stats_inc ("amq_queue_agent_method", &s_amq_queue_agent_method_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{


#define self tcb->amq_queue
char *
    method_name;
amq_content_basic_t *
    request;
asl_field_list_t *
    fields;

    method_name = method_m->method_name;
    request = method_m->request;
    fields = method_m->fields;
        {
int
    rc = 0;
char
    *notice_text = NULL;            //  Notice to UI, if any
if (streq (method_name, "purge")) {
    amq_queue_basic_purge (self->queue_basic);
}
if (rc == 0)
    amq_console_reply_ok (
        amq_console, "method-reply", request, self->object_id, NULL, notice_text);
else
    amq_console_reply_error (
        amq_console, "method-reply", "invalid", request, self->object_id);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_34 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT)  ||  defined (BASE_STATS_AMQ_QUEUE_AGENT_UNNAMED_34))
    icl_stats_inc ("amq_queue_agent_unnamed_34", &s_amq_queue_agent_unnamed_34_stats);
#endif        
#define tcb ((amq_queue_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

