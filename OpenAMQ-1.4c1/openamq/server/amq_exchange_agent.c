/*---------------------------------------------------------------------------
    amq_exchange_agent.c - functions for amq_exchange_agent.

    Generated from amq_exchange_agent.smt by smt_gen.gsl using GSL/4.

    
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
#include "amq_exchange_agent.h"

#define class_main_state                           1
#define class_shutting_down_state                  2

#define destroy_m ((amq_exchange_agent_destroy_t *) thread->method->data)

#define bind_queue_m ((amq_exchange_agent_bind_queue_t *) thread->method->data)

#define unbind_queue_m ((amq_exchange_agent_unbind_queue_t *) thread->method->data)

#define publish_m ((amq_exchange_agent_publish_t *) thread->method->data)

#define broker_unbind_queue_m ((amq_exchange_agent_broker_unbind_queue_t *) thread->method->data)

#define inspect_m ((amq_exchange_agent_inspect_t *) thread->method->data)

#define modify_m ((amq_exchange_agent_modify_t *) thread->method->data)

#define method_m ((amq_exchange_agent_method_t *) thread->method->data)

enum {
    shutdown_event                                 = 1,
    destroy_m_event                                = 2,
    bind_queue_m_event                             = 3,
    unbind_queue_m_event                           = 4,
    publish_m_event                                = 5,
    broker_unbind_queue_m_event                    = 6,
    inspect_m_event                                = 7,
    modify_m_event                                 = 8,
    method_m_event                                 = 9,
};

#define laststate                                  2
#define lastevent                                  9
#define lastplace                                  21

#define amq_exchange_agent_agent_name              "Amq-Exchange-Agent"

#define class_thread_name                          "Class"

#define main_state_name                            "Main"
#define shutting_down_state_name                   "Shutting-Down"

#define shutdown_event_name                        "Shutdown"
#define destroy_m_event_name                       "Destroy-M"
#define bind_queue_m_event_name                    "Bind-Queue-M"
#define unbind_queue_m_event_name                  "Unbind-Queue-M"
#define publish_m_event_name                       "Publish-M"
#define broker_unbind_queue_m_event_name           "Broker-Unbind-Queue-M"
#define inspect_m_event_name                       "Inspect-M"
#define modify_m_event_name                        "Modify-M"
#define method_m_event_name                        "Method-M"

#define destroy_action_name                        "Destroy"
#define free_action_name                           "Free"
#define unnamed_3_action_name                      "Unnamed-3"
#define unnamed_4_action_name                      "Unnamed-4"
#define bind_queue_action_name                     "Bind-Queue"
#define unnamed_6_action_name                      "Unnamed-6"
#define unbind_queue_action_name                   "Unbind-Queue"
#define unnamed_8_action_name                      "Unnamed-8"
#define publish_action_name                        "Publish"
#define unnamed_10_action_name                     "Unnamed-10"
#define broker_unbind_queue_action_name            "Broker-Unbind-Queue"
#define unnamed_12_action_name                     "Unnamed-12"
#define inspect_action_name                        "Inspect"
#define unnamed_14_action_name                     "Unnamed-14"
#define modify_action_name                         "Modify"
#define unnamed_16_action_name                     "Unnamed-16"
#define method_action_name                         "Method"
#define unnamed_18_action_name                     "Unnamed-18"

#define the_next_event                             thread->_next_event
#define exception_raised                           thread->_exception_raised

typedef struct
  {
    char *         file;
    size_t         line;
  }
amq_exchange_agent_destroy_t;

typedef struct
  {
    amq_server_channel_t *  channel;
    amq_queue_t *  queue;
    char *         routing_key;
    icl_longstr_t *  arguments;
  }
amq_exchange_agent_bind_queue_t;

typedef struct
  {
    amq_server_channel_t *  channel;
    amq_queue_t *  queue;
    char *         routing_key;
    icl_longstr_t *  arguments;
  }
amq_exchange_agent_unbind_queue_t;

typedef struct
  {
    amq_server_channel_t *  channel;
    amq_content_basic_t *  content;
    Bool           mandatory;
    Bool           immediate;
    int            group;
  }
amq_exchange_agent_publish_t;

typedef struct
  {
    amq_queue_t *  queue;
  }
amq_exchange_agent_broker_unbind_queue_t;

typedef struct
  {
    amq_content_basic_t *  request;
  }
amq_exchange_agent_inspect_t;

typedef struct
  {
    amq_content_basic_t *  request;
    asl_field_list_t *  fields;
  }
amq_exchange_agent_modify_t;

typedef struct
  {
    char *         method_name;
    amq_content_basic_t *  request;
    asl_field_list_t *  fields;
  }
amq_exchange_agent_method_t;

static icl_cache_t
    *s_class_context_cache = NULL;

typedef struct {
    int
        links;

        amq_exchange_t
            *amq_exchange;
    
} amq_exchange_agent_class_context_t;

static icl_cache_t
    *s_destroy_cache = NULL;
static icl_cache_t
    *s_bind_queue_cache = NULL;
static icl_cache_t
    *s_unbind_queue_cache = NULL;
static icl_cache_t
    *s_publish_cache = NULL;
static icl_cache_t
    *s_broker_unbind_queue_cache = NULL;
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
    shutdown_event_name,
    destroy_m_event_name,
    bind_queue_m_event_name,
    unbind_queue_m_event_name,
    publish_m_event_name,
    broker_unbind_queue_m_event_name,
    inspect_m_event_name,
    modify_m_event_name,
    method_m_event_name
};

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT)       ||  defined (BASE_TRACE)  || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT)   ||  defined (AMQ_EXCHANGE_AGENT_TRACE))
static const char *action_name [] = {
    "<NULL>",
    destroy_action_name,
    free_action_name,
    unnamed_3_action_name,
    unnamed_4_action_name,
    bind_queue_action_name,
    unnamed_6_action_name,
    unbind_queue_action_name,
    unnamed_8_action_name,
    publish_action_name,
    unnamed_10_action_name,
    broker_unbind_queue_action_name,
    unnamed_12_action_name,
    inspect_action_name,
    unnamed_14_action_name,
    modify_action_name,
    unnamed_16_action_name,
    method_action_name,
    unnamed_18_action_name
};
#endif

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
static Bool
    s_animate = FALSE;
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_DESTROY))
static icl_stats_t *s_amq_exchange_agent_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_FREE))
static icl_stats_t *s_amq_exchange_agent_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_3))
static icl_stats_t *s_amq_exchange_agent_unnamed_3_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_4))
static icl_stats_t *s_amq_exchange_agent_unnamed_4_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_BIND_QUEUE))
static icl_stats_t *s_amq_exchange_agent_bind_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_6))
static icl_stats_t *s_amq_exchange_agent_unnamed_6_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNBIND_QUEUE))
static icl_stats_t *s_amq_exchange_agent_unbind_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_8))
static icl_stats_t *s_amq_exchange_agent_unnamed_8_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_PUBLISH))
static icl_stats_t *s_amq_exchange_agent_publish_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_10))
static icl_stats_t *s_amq_exchange_agent_unnamed_10_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_BROKER_UNBIND_QUEUE))
static icl_stats_t *s_amq_exchange_agent_broker_unbind_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_12))
static icl_stats_t *s_amq_exchange_agent_unnamed_12_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_INSPECT))
static icl_stats_t *s_amq_exchange_agent_inspect_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_14))
static icl_stats_t *s_amq_exchange_agent_unnamed_14_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_MODIFY))
static icl_stats_t *s_amq_exchange_agent_modify_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_16))
static icl_stats_t *s_amq_exchange_agent_unnamed_16_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_METHOD))
static icl_stats_t *s_amq_exchange_agent_method_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_18))
static icl_stats_t *s_amq_exchange_agent_unnamed_18_stats = NULL;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//  Function prototypes                                                        

static int    amq_exchange_agent_manager      (smt_thread_t **thread);
static int    amq_exchange_agent_catcher      (smt_thread_t *thread);
static int    amq_exchange_agent_class_destroy  (smt_thread_t *thread);
static void   find_thread_state_next_state    (int          *thread_type,
                                               smt_state_t  *state_id,
                                               smt_event_t  *event_id,
                                               smt_state_t  *nextstate_id,
                                               smt_thread_t *thread);
static void   report_unrecognised_event_error (smt_thread_t *thread);
static void   report_state_machine_error      (smt_thread_t *thread);

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
static void   animate_start_new_event         (smt_thread_t *thread,
                                               smt_event_t  saveevent_id);
static void   animate_action                  (smt_thread_t *thread_id,
                                               int          action_id);
static int    find_thread_type                (smt_place_t  place);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT)         ||  defined (AMQ_EXCHANGE_AGENT_TRACE))
static void   s_dump                          (icl_os_thread_t apr_os_thread,
                                               apr_time_t      time,
                                               qbyte           info);

#endif

static int    action_destroy                  (smt_thread_t *thread);
static int    action_free                     (smt_thread_t *thread);
static int    action_unnamed_3                (smt_thread_t *thread);
static int    action_unnamed_4                (smt_thread_t *thread);
static int    action_bind_queue               (smt_thread_t *thread);
static int    action_unnamed_6                (smt_thread_t *thread);
static int    action_unbind_queue             (smt_thread_t *thread);
static int    action_unnamed_8                (smt_thread_t *thread);
static int    action_publish                  (smt_thread_t *thread);
static int    action_unnamed_10               (smt_thread_t *thread);
static int    action_broker_unbind_queue      (smt_thread_t *thread);
static int    action_unnamed_12               (smt_thread_t *thread);
static int    action_inspect                  (smt_thread_t *thread);
static int    action_unnamed_14               (smt_thread_t *thread);
static int    action_modify                   (smt_thread_t *thread);
static int    action_unnamed_16               (smt_thread_t *thread);
static int    action_method                   (smt_thread_t *thread);
static int    action_unnamed_18               (smt_thread_t *thread);
static int
amq_exchange_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line);
int
amq_exchange_agent_destroy_destructor (void *data);
static int
amq_exchange_agent_bind_queue_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    amq_queue_t *  queue,
    char *         routing_key,
    icl_longstr_t *  arguments);
int
amq_exchange_agent_bind_queue_destructor (void *data);
static int
amq_exchange_agent_unbind_queue_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    amq_queue_t *  queue,
    char *         routing_key,
    icl_longstr_t *  arguments);
int
amq_exchange_agent_unbind_queue_destructor (void *data);
static int
amq_exchange_agent_publish_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    amq_content_basic_t *  content,
    Bool           mandatory,
    Bool           immediate,
    int            group);
int
amq_exchange_agent_publish_destructor (void *data);
static int
amq_exchange_agent_broker_unbind_queue_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_queue_t *  queue);
int
amq_exchange_agent_broker_unbind_queue_destructor (void *data);
static int
amq_exchange_agent_inspect_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request);
int
amq_exchange_agent_inspect_destructor (void *data);
static int
amq_exchange_agent_modify_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields);
int
amq_exchange_agent_modify_destructor (void *data);
static int
amq_exchange_agent_method_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         method_name,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields);
int
amq_exchange_agent_method_destructor (void *data);
//  Function definitions                                                       

static int
amq_exchange_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line)
{
    int
        rc = 0;
    amq_exchange_agent_destroy_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_destroy_cache);
    _message->file                      = file;
    _message->line                      = line;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_exchange_agent_destroy_destructor);
    
    return rc;
}

int
amq_exchange_agent_destroy_destructor (void *data)
{
    int
        rc = 0;
char * file;
size_t line;

    file = ((amq_exchange_agent_destroy_t *) data)-> file;
    line = ((amq_exchange_agent_destroy_t *) data)-> line;


    icl_mem_free (data);
    return rc;
}


static int
amq_exchange_agent_bind_queue_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    amq_queue_t *  queue,
    char *         routing_key,
    icl_longstr_t *  arguments)
{
    int
        rc = 0;
    amq_exchange_agent_bind_queue_t
        *_message;
        
    //  Possess code for bind queue
    

    channel = amq_server_channel_link (channel);
    queue = amq_queue_link (queue);
    arguments = icl_longstr_dup (arguments);
    routing_key = icl_mem_strdup (routing_key);
    
    

    _message = icl_mem_cache_alloc (s_bind_queue_cache);
    _message->channel                   = channel;
    _message->queue                     = queue;
    _message->routing_key               = routing_key;
    _message->arguments                 = arguments;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_exchange_agent_bind_queue_destructor);
    
    return rc;
}

int
amq_exchange_agent_bind_queue_destructor (void *data)
{
    int
        rc = 0;
amq_server_channel_t * channel;
amq_queue_t * queue;
char * routing_key;
icl_longstr_t * arguments;

    channel = ((amq_exchange_agent_bind_queue_t *) data)-> channel;
    queue = ((amq_exchange_agent_bind_queue_t *) data)-> queue;
    routing_key = ((amq_exchange_agent_bind_queue_t *) data)-> routing_key;
    arguments = ((amq_exchange_agent_bind_queue_t *) data)-> arguments;



    amq_server_channel_unlink (&channel);
    amq_queue_unlink (&queue);
    icl_longstr_destroy (&arguments);
    icl_mem_free (routing_key);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_exchange_agent_unbind_queue_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    amq_queue_t *  queue,
    char *         routing_key,
    icl_longstr_t *  arguments)
{
    int
        rc = 0;
    amq_exchange_agent_unbind_queue_t
        *_message;
        
    //  Possess code for unbind queue
    

    channel = amq_server_channel_link (channel);
    queue = amq_queue_link (queue);
    arguments = icl_longstr_dup (arguments);
    routing_key = icl_mem_strdup (routing_key);
    
    

    _message = icl_mem_cache_alloc (s_unbind_queue_cache);
    _message->channel                   = channel;
    _message->queue                     = queue;
    _message->routing_key               = routing_key;
    _message->arguments                 = arguments;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_exchange_agent_unbind_queue_destructor);
    
    return rc;
}

int
amq_exchange_agent_unbind_queue_destructor (void *data)
{
    int
        rc = 0;
amq_server_channel_t * channel;
amq_queue_t * queue;
char * routing_key;
icl_longstr_t * arguments;

    channel = ((amq_exchange_agent_unbind_queue_t *) data)-> channel;
    queue = ((amq_exchange_agent_unbind_queue_t *) data)-> queue;
    routing_key = ((amq_exchange_agent_unbind_queue_t *) data)-> routing_key;
    arguments = ((amq_exchange_agent_unbind_queue_t *) data)-> arguments;



    amq_server_channel_unlink (&channel);
    amq_queue_unlink (&queue);
    icl_longstr_destroy (&arguments);
    icl_mem_free (routing_key);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_exchange_agent_publish_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_server_channel_t *  channel,
    amq_content_basic_t *  content,
    Bool           mandatory,
    Bool           immediate,
    int            group)
{
    int
        rc = 0;
    amq_exchange_agent_publish_t
        *_message;
        
    //  Possess code for publish
    

    channel = amq_server_channel_link (channel);
    content = amq_content_basic_link (content);
    
    

    _message = icl_mem_cache_alloc (s_publish_cache);
    _message->channel                   = channel;
    _message->content                   = content;
    _message->mandatory                 = mandatory;
    _message->immediate                 = immediate;
    _message->group                     = group;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_exchange_agent_publish_destructor);
    
    return rc;
}

int
amq_exchange_agent_publish_destructor (void *data)
{
    int
        rc = 0;
amq_server_channel_t * channel;
amq_content_basic_t * content;
Bool mandatory;
Bool immediate;
int group;

    channel = ((amq_exchange_agent_publish_t *) data)-> channel;
    content = ((amq_exchange_agent_publish_t *) data)-> content;
    mandatory = ((amq_exchange_agent_publish_t *) data)-> mandatory;
    immediate = ((amq_exchange_agent_publish_t *) data)-> immediate;
    group = ((amq_exchange_agent_publish_t *) data)-> group;



    amq_server_channel_unlink (&channel);
    amq_content_basic_unlink (&content);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_exchange_agent_broker_unbind_queue_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_queue_t *  queue)
{
    int
        rc = 0;
    amq_exchange_agent_broker_unbind_queue_t
        *_message;
        
    //  Possess code for broker unbind queue
    

    queue = amq_queue_link (queue);
    
    

    _message = icl_mem_cache_alloc (s_broker_unbind_queue_cache);
    _message->queue                     = queue;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_exchange_agent_broker_unbind_queue_destructor);
    
    return rc;
}

int
amq_exchange_agent_broker_unbind_queue_destructor (void *data)
{
    int
        rc = 0;
amq_queue_t * queue;

    queue = ((amq_exchange_agent_broker_unbind_queue_t *) data)-> queue;



    amq_queue_unlink (&queue);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_exchange_agent_inspect_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request)
{
    int
        rc = 0;
    amq_exchange_agent_inspect_t
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
                          amq_exchange_agent_inspect_destructor);
    
    return rc;
}

int
amq_exchange_agent_inspect_destructor (void *data)
{
    int
        rc = 0;
amq_content_basic_t * request;

    request = ((amq_exchange_agent_inspect_t *) data)-> request;



    amq_content_basic_unlink (&request);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_exchange_agent_modify_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields)
{
    int
        rc = 0;
    amq_exchange_agent_modify_t
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
                          amq_exchange_agent_modify_destructor);
    
    return rc;
}

int
amq_exchange_agent_modify_destructor (void *data)
{
    int
        rc = 0;
amq_content_basic_t * request;
asl_field_list_t * fields;

    request = ((amq_exchange_agent_modify_t *) data)-> request;
    fields = ((amq_exchange_agent_modify_t *) data)-> fields;



    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_exchange_agent_method_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         method_name,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields)
{
    int
        rc = 0;
    amq_exchange_agent_method_t
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
                          amq_exchange_agent_method_destructor);
    
    return rc;
}

int
amq_exchange_agent_method_destructor (void *data)
{
    int
        rc = 0;
char * method_name;
amq_content_basic_t * request;
asl_field_list_t * fields;

    method_name = ((amq_exchange_agent_method_t *) data)-> method_name;
    request = ((amq_exchange_agent_method_t *) data)-> request;
    fields = ((amq_exchange_agent_method_t *) data)-> fields;



    icl_mem_free (method_name);
    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    
    

    icl_mem_free (data);
    return rc;
}


int
amq_exchange_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_exchange_agent_manager);
        rc = amq_exchange_agent_destroy_send (
                thread->reply_queue, destroy_m_event,
                file,
                line);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_exchange_agent_bind_queue (
    smt_thread_t * thread,
    amq_server_channel_t * channel,
    amq_queue_t *         queue,
    char *                routing_key,
    icl_longstr_t *       arguments)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_exchange_agent_manager);
        rc = amq_exchange_agent_bind_queue_send (
                thread->reply_queue, bind_queue_m_event,
                channel,
                queue,
                routing_key,
                arguments);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_exchange_agent_unbind_queue (
    smt_thread_t * thread,
    amq_server_channel_t * channel,
    amq_queue_t *         queue,
    char *                routing_key,
    icl_longstr_t *       arguments)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_exchange_agent_manager);
        rc = amq_exchange_agent_unbind_queue_send (
                thread->reply_queue, unbind_queue_m_event,
                channel,
                queue,
                routing_key,
                arguments);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_exchange_agent_publish (
    smt_thread_t * thread,
    amq_server_channel_t * channel,
    amq_content_basic_t * content,
    Bool                  mandatory,
    Bool                  immediate,
    int                   group)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_exchange_agent_manager);
        rc = amq_exchange_agent_publish_send (
                thread->reply_queue, publish_m_event,
                channel,
                content,
                mandatory,
                immediate,
                group);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_exchange_agent_broker_unbind_queue (
    smt_thread_t * thread,
    amq_queue_t *         queue)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_exchange_agent_manager);
        rc = amq_exchange_agent_broker_unbind_queue_send (
                thread->reply_queue, broker_unbind_queue_m_event,
                queue);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_exchange_agent_inspect (
    smt_thread_t * thread,
    amq_content_basic_t * request)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_exchange_agent_manager);
        rc = amq_exchange_agent_inspect_send (
                thread->reply_queue, inspect_m_event,
                request);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_exchange_agent_modify (
    smt_thread_t * thread,
    amq_content_basic_t * request,
    asl_field_list_t *    fields)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_exchange_agent_manager);
        rc = amq_exchange_agent_modify_send (
                thread->reply_queue, modify_m_event,
                request,
                fields);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_exchange_agent_method (
    smt_thread_t * thread,
    char *                method_name,
    amq_content_basic_t * request,
    asl_field_list_t *    fields)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_exchange_agent_manager);
        rc = amq_exchange_agent_method_send (
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
amq_exchange_agent_term (void)
{

}

int 
amq_exchange_agent_init (void)
{
    int
        rc = SMT_OK;                    //  Return code

    s_class_context_cache = icl_cache_get (sizeof (amq_exchange_agent_class_context_t));
    s_destroy_cache = icl_cache_get (sizeof (amq_exchange_agent_destroy_t));
    s_bind_queue_cache = icl_cache_get (sizeof (amq_exchange_agent_bind_queue_t));
    s_unbind_queue_cache = icl_cache_get (sizeof (amq_exchange_agent_unbind_queue_t));
    s_publish_cache = icl_cache_get (sizeof (amq_exchange_agent_publish_t));
    s_broker_unbind_queue_cache = icl_cache_get (sizeof (amq_exchange_agent_broker_unbind_queue_t));
    s_inspect_cache = icl_cache_get (sizeof (amq_exchange_agent_inspect_t));
    s_modify_cache = icl_cache_get (sizeof (amq_exchange_agent_modify_t));
    s_method_cache = icl_cache_get (sizeof (amq_exchange_agent_method_t));

    //  Initialise basic stuff.
    smt_initialise ();
    
    {

    }
    icl_system_register (NULL, amq_exchange_agent_term);
    
    return rc;
}

void
amq_exchange_agent_animate (Bool animate)
{
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
    s_animate = animate;
#endif
}

smt_thread_t *
amq_exchange_agent_class_thread_new (
    amq_exchange_t * self)
{
    smt_thread_t
        *thread;

    thread = smt_thread_new (amq_exchange_agent_manager,
                             amq_exchange_agent_catcher,
                             amq_exchange_agent_class_destroy);
                             

#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    thread->trace = icl_trace_new (ICL_TRACE_SIZE);
#endif

    if (thread) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
        thread->animate = s_animate;
        if (s_animate)
            icl_console_print ("%4lu> %-15s/%-15s <Created>",
                thread->id,
                "amq_exchange_agent",
                class_thread_name);
#endif

        thread->place   = 1;
        thread->context = icl_mem_cache_alloc (s_class_context_cache);
        memset (thread->context, 0, sizeof (amq_exchange_agent_class_context_t));
        ((amq_exchange_agent_class_context_t *) thread->context)->links = 1;
        thread->event_name = event_name;
{
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)

        tcb->amq_exchange = self;
    
#undef  tcb
}
    }
    return thread;
}


static int
amq_exchange_agent_manager (smt_thread_t **thread_p)
{
    smt_thread_t
        *thread = *thread_p;
        
    int
        rc;
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))

    smt_event_t
        saveevent_id = SMT_NULL_EVENT;
#endif
        
    assert (thread->manager == amq_exchange_agent_manager);
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
            case 21:
            case 13:
            case 4:
                thread->place = SMT_TERM_PLACE;
                break;
            case 8:
            case 9:
            case 7:
            case 6:
            case 5:
            case 10:
            case 11:
                thread->place = 2;
                break;
            case 20:
            case 19:
            case 18:
            case 17:
            case 3:
            case 16:
            case 14:
            case 15:
                thread->place = 12;
                break;
        }    
    else
    if (thread->module == 0) {
        if (thread->place == 1) { //                Class thread
            if (!thread->shutting_down) {
{
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)

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
        if (thread->place < 12)                 //  Main state
            thread->place = 2;
        else
            thread->place = 12;
    }

    switch (thread->place) {
        case 2:                         //  main state                          
{
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 3; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 4; break;
                case bind_queue_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 5; break;
                case unbind_queue_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 6; break;
                case publish_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 7; break;
                case broker_unbind_queue_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 8; break;
                case inspect_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 9; break;
                case modify_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 10; break;
                case method_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 11; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
        case 12:                        //  shutting down state                 
{
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 13; break;
                case bind_queue_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 14; break;
                case unbind_queue_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 15; break;
                case publish_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 16; break;
                case broker_unbind_queue_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 17; break;
                case inspect_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 18; break;
                case modify_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 19; break;
                case method_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 20; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 21; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
    }
                                  
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
    if (thread->animate && thread->module == 1)
        animate_start_new_event (thread, saveevent_id);
#endif

    switch (thread->place) {
        case 3:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
            switch (thread->module) {
                case 1:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    if (thread->place == 21)
                        thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 13:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 1);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 2);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 3);
#endif
                    rc = action_unnamed_3 (thread);

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
        case 4:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 1);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 2);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 5);
#endif
                    rc = action_bind_queue (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
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
        case 6:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 7);
#endif
                    rc = action_unbind_queue (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 8);
#endif
                    rc = action_unnamed_8 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 9);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 10);
#endif
                    rc = action_unnamed_10 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 11);
#endif
                    rc = action_broker_unbind_queue (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 12);
#endif
                    rc = action_unnamed_12 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 13);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 14);
#endif
                    rc = action_unnamed_14 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 15);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 17);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
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
amq_exchange_agent_catcher (smt_thread_t *thread)
{
    return SMT_OK;
}


static int    
amq_exchange_agent_class_destroy (smt_thread_t *thread)
{
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (AMQ_EXCHANGE_AGENT_TRACE))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))
    if (thread->animate)
        icl_console_print ("%4lu> %-15s/%-15s <Destroyed>",
                  thread->id,
                  "amq_exchange_agent",
                 class_thread_name);

#endif
    if (--((amq_exchange_agent_class_context_t *) thread->context)->links == 0)
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
        if (thread->place < 12)
          {
            *state_id = 1;
            switch (thread->place) {
                case 3: *event_id = 1;   *nextstate_id = 2;   break;
                case 4: *event_id = 2;   break;
                case 5: *event_id = 3;   *nextstate_id = 1;   break;
                case 6: *event_id = 4;   *nextstate_id = 1;   break;
                case 7: *event_id = 5;   *nextstate_id = 1;   break;
                case 8: *event_id = 6;   *nextstate_id = 1;   break;
                case 9: *event_id = 7;   *nextstate_id = 1;   break;
                case 10: *event_id = 8;   *nextstate_id = 1;   break;
                case 11: *event_id = 9;   *nextstate_id = 1;   break;
            }
          }
        else
          {
            *state_id = 2;
            switch (thread->place) {
                case 13: *event_id = 2;   break;
                case 14: *event_id = 3;   *nextstate_id = 2;   break;
                case 15: *event_id = 4;   *nextstate_id = 2;   break;
                case 16: *event_id = 5;   *nextstate_id = 2;   break;
                case 17: *event_id = 6;   *nextstate_id = 2;   break;
                case 18: *event_id = 7;   *nextstate_id = 2;   break;
                case 19: *event_id = 8;   *nextstate_id = 2;   break;
                case 20: *event_id = 9;   *nextstate_id = 2;   break;
                case 21: *event_id = 1;   break;
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
    icl_console_print ("amq_exchange_agent: Unrecognised event '%s' in '%s' thread number: %u, state: %s",
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

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_EXCHANGE_AGENT))

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
            "amq_exchange_agent",
            thread_name [thread_type],
            state_name [state_id]);
  icl_console_print ("%4lu> %-15s/%-15s    (--) %-32s->%s",
            thread->id,
            "amq_exchange_agent",
            thread_name [thread_type],
            event_name [event_id != SMT_NULL_EVENT ? event_id : saveevent_id],
            nextstate_id ? state_name [nextstate_id] : "");
}

static void
animate_action (smt_thread_t *thread, int action_id)
{
    icl_console_print ("%4lu> %-15s/%-15s           + %s",
              thread->id,
              "amq_exchange_agent",
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_EXCHANGE_AGENT)           ||  defined (AMQ_EXCHANGE_AGENT_TRACE))
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
                                       "amq_exchange_agent",
                                       action_name [action_id]);
    }
    else
    if (state_or_event_or_action > laststate) {
        event_id = state_or_event_or_action - laststate;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s    (--) %-32s",
                                       thread_id,
                                       "amq_exchange_agent",
                                       event_name [event_id]);
    }
    else {
        state_id = state_or_event_or_action;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s %s:",
                                       thread_id,
                                       "amq_exchange_agent",
                                       state_id ? state_name [state_id] : "<Destroyed>");
    }
}

#endif
static int
action_destroy (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_DESTROY))
    icl_stats_inc ("amq_exchange_agent_destroy", &s_amq_exchange_agent_destroy_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{


#define self tcb->amq_exchange
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

icl_atomic_dec32 ((volatile qbyte *) &gbl_amq_exchange_count);

ipr_hash_table_destroy (&self->binding_hash);
amq_binding_list_destroy (&self->binding_list);
ipr_index_destroy (&self->binding_index);
amq_queue_bindings_list_table_destroy (&self->queue_bindings);
icl_mem_free (self->queue_set);
amq_federation_destroy (&self->federation);

if (!self->internal && amq_server_config_debug_route (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "X: destroy  exchange=%s type=%s", self->name, amq_exchange_type_name (self->type));

if (self->type == AMQ_EXCHANGE_SYSTEM) {
    amq_exchange_system_t
        *exchange = (amq_exchange_system_t *) self->object;
    amq_exchange_system_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_FANOUT) {
    amq_exchange_fanout_t
        *exchange = (amq_exchange_fanout_t *) self->object;
    amq_exchange_fanout_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_DIRECT) {
    amq_exchange_direct_t
        *exchange = (amq_exchange_direct_t *) self->object;
    amq_exchange_direct_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_TOPIC) {
    amq_exchange_topic_t
        *exchange = (amq_exchange_topic_t *) self->object;
    amq_exchange_topic_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_HEADERS) {
    amq_exchange_headers_t
        *exchange = (amq_exchange_headers_t *) self->object;
    amq_exchange_headers_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_REGEXP) {
    amq_exchange_regexp_t
        *exchange = (amq_exchange_regexp_t *) self->object;
    amq_exchange_regexp_destroy (&exchange);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_FREE))
    icl_stats_inc ("amq_exchange_agent_free", &s_amq_exchange_agent_free_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{


#define self tcb->amq_exchange
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_exchange object");
    amq_exchange_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_exchange_free (self);
    self = NULL;
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_3 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_3))
    icl_stats_inc ("amq_exchange_agent_unnamed_3", &s_amq_exchange_agent_unnamed_3_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_4 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_4))
    icl_stats_inc ("amq_exchange_agent_unnamed_4", &s_amq_exchange_agent_unnamed_4_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_bind_queue (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_BIND_QUEUE))
    icl_stats_inc ("amq_exchange_agent_bind_queue", &s_amq_exchange_agent_bind_queue_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{


#define self tcb->amq_exchange
amq_server_channel_t *
    channel;
amq_queue_t *
    queue;
char *
    routing_key;
icl_longstr_t *
    arguments;

    channel = bind_queue_m->channel;
    queue = bind_queue_m->queue;
    routing_key = bind_queue_m->routing_key;
    arguments = bind_queue_m->arguments;
        {
amq_binding_t
    *binding = NULL;                //  New binding created
ipr_hash_t
    *hash;                          //  Entry into hash table
amq_queue_bindings_list_t
    *bindings_list;                 //  List of bindings for the queue
amq_queue_bindings_list_iter_t *
    iterator;

if (amq_server_config_debug_route (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "X: bind     %s: queue=%s", self->name, queue->name);

//  Treat empty arguments as null to simplify comparisons
if (arguments && arguments->cur_size == 0)
    arguments = NULL;

//  Force all fanout bindings to a single instance
if (self->type == AMQ_EXCHANGE_FANOUT)
    routing_key = "";

//  We need to know if this is a new binding or not
//  First, we`ll check on the routing key
hash = ipr_hash_table_search (self->binding_hash, routing_key);
if (hash) {
    //  We found the same routing key, now we need to check
    //  all bindings to check for an exact match
    binding = amq_binding_list_first (self->binding_list);
    while (binding) {
        if (streq (binding->routing_key, routing_key)
        && icl_longstr_eq (binding->arguments, arguments))
            break;
        binding = amq_binding_list_next (&binding);
    }
}
if (!binding) {
    //  If no binding matched, create a new one and compile it
    binding = amq_binding_new (self, routing_key, arguments, queue->exclusive);
    assert (binding);               //  If that failed, don't continue
    if (!hash)                      //  Hash routing key if needed
        hash = ipr_hash_new (self->binding_hash, routing_key, binding);

    //  Compile binding and put all 'wildcard' bindings at the front
    //  of the list. The meaning of this flag depends on the exchange.
    if (self->compile (self->object, binding, channel) == 0) {
        if (binding->is_wildcard)
            amq_binding_list_push (self->binding_list, binding);
        else
            amq_binding_list_queue (self->binding_list, binding);
    }
}
//  In a service federation we forward exclusive bindings only and we
//  prohibit a mix of exclusive/non-exclusive queues on the same binding.
else
if (self->federation_type == AMQ_FEDERATION_SERVICE) {
    if (channel && (binding->exclusive != queue->exclusive))
        amq_server_channel_error (channel, ASL_NOT_ALLOWED,
            "Invalid bind mix for service federation",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_BIND);
}
//  Add queue to binding structures if not already present
if (queue) {
    bindings_list = amq_queue_bindings_list_table_search (
        self->queue_bindings, queue->name);
    if (!bindings_list)
        bindings_list = amq_queue_bindings_list_new (
            self->queue_bindings, queue->name);
    //  Search per-queue bindings_list for a matching binding
    for (iterator = amq_queue_bindings_list_first (bindings_list);
         iterator != NULL;
         iterator = amq_queue_bindings_list_next (&iterator)) {
        if (iterator->item == binding)
            break;
    }
    //  And only add binding to per-queue bindings_list once
    if (!iterator)
        amq_queue_bindings_list_queue (bindings_list, binding);
    amq_queue_bindings_list_unlink (&bindings_list);
}
amq_queue_binding_register (queue, self, binding);
amq_binding_bind_queue (binding, queue);
amq_binding_unlink (&binding);
ipr_hash_unlink (&hash);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_6))
    icl_stats_inc ("amq_exchange_agent_unnamed_6", &s_amq_exchange_agent_unnamed_6_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unbind_queue (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNBIND_QUEUE))
    icl_stats_inc ("amq_exchange_agent_unbind_queue", &s_amq_exchange_agent_unbind_queue_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{


#define self tcb->amq_exchange
amq_server_channel_t *
    channel;
amq_queue_t *
    queue;
char *
    routing_key;
icl_longstr_t *
    arguments;

    channel = unbind_queue_m->channel;
    queue = unbind_queue_m->queue;
    routing_key = unbind_queue_m->routing_key;
    arguments = unbind_queue_m->arguments;
        {
amq_queue_bindings_list_t
    *queue_bindings;                //  List of bindings for queue
amq_queue_bindings_list_iter_t
    *iterator;

if (amq_server_config_debug_route (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "X: unbind     %s: queue=%s", self->name, queue->name);

//  Treat empty arguments as null, to simplify comparisons
if (arguments && arguments->cur_size == 0)
    arguments = NULL;
queue_bindings =
    amq_queue_bindings_list_table_search (self->queue_bindings, queue->name);
if (queue_bindings) {
    //  Search queue_bindings list for the matching binding
    for (iterator = amq_queue_bindings_list_first (queue_bindings);
          iterator != NULL;
          iterator = amq_queue_bindings_list_next (&iterator)) {
        if (streq (iterator->item->routing_key, routing_key) &&
            icl_longstr_eq (iterator->item->arguments, arguments)) {
            amq_queue_binding_cancel (queue, self, iterator->item);
            if (amq_binding_unbind_queue (iterator->item, queue))
                //  If binding is now empty, destroy it
                self->unbind (self->object, iterator->item);
            amq_queue_bindings_list_iter_destroy (&iterator);
            break;
        }
    }
    //  If per-queue binding list is now empty, destroy it
    if (amq_queue_bindings_list_count (queue_bindings) == 0)
        amq_queue_bindings_list_destroy (&queue_bindings);
    else
        amq_queue_bindings_list_unlink (&queue_bindings);
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_8 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_8))
    icl_stats_inc ("amq_exchange_agent_unnamed_8", &s_amq_exchange_agent_unnamed_8_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_PUBLISH))
    icl_stats_inc ("amq_exchange_agent_publish", &s_amq_exchange_agent_publish_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{


#define self tcb->amq_exchange
amq_server_channel_t *
    channel;
amq_content_basic_t *
    content;
Bool
    mandatory;
Bool
    immediate;
int
    group;

    channel = publish_m->channel;
    content = publish_m->content;
    mandatory = publish_m->mandatory;
    immediate = publish_m->immediate;
    group = publish_m->group;
        {
int
    delivered = 0;                      //  Number of message deliveries
amq_server_connection_t
    *connection;
Bool
    returned = FALSE;

//  If channel is set, we got message from local application; if we have
//  fanout federation, send to parent broker but don't publish locally.
//  This stops message being delivered twice to local apps (once now and
//  once when received back from parent).
//
if (self->federation_type == AMQ_FEDERATION_FANOUT && channel)
    delivered = 1;                  //  Just fake it
else
    //  Publish message locally
    delivered = self->publish (self->object, channel, content, group, immediate);

//  Publish message to federation if necessary. We don't have the problem
//  of message loops with fanout federations because we only push back to
//  the parent messages that came from a client app (channel != 0).
//
if (self->federation_type == AMQ_FEDERATION_PUBLISHER ||
   (self->federation_type == AMQ_FEDERATION_FANOUT && channel) ||
   (self->federation_type == AMQ_FEDERATION_LOCATOR && !delivered) ||
   (self->federation_type == AMQ_FEDERATION_SERVICE && !delivered)) {
    amq_federation_message_published (self->federation, content, mandatory, immediate);
    delivered++;
}
if (!delivered && mandatory) {
    if (!content->returned) {
        connection = channel?
            amq_server_connection_link (channel->connection): NULL;
        if (connection) {
            amq_server_agent_basic_return (
                connection->thread,
                channel->number,
                content,
                ASL_NOT_DELIVERED,
                "Message cannot be processed - no route is defined",
                self->name,
                content->routing_key,
                NULL);
            content->returned = TRUE;
        }
        returned = TRUE;
        amq_server_connection_unlink (&connection);
    }
}
if (amq_server_config_debug_route (amq_server_config)) {
    if (returned)
        smt_log_print (amq_broker->debug_log,
            "X: return   %s: message=%s reason=unroutable_mandatory",
                self->name, content->message_id);
    else
    if (!delivered)
        smt_log_print (amq_broker->debug_log,
            "X: discard  %s: message=%s reason=unroutable_optional",
                self->name, content->message_id);
}
//  Track exchange statistics
self->contents_in  += 1;
self->contents_out += delivered;
self->traffic_in   += content->body_size;
self->traffic_out  += delivered * content->body_size;
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_10 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_10))
    icl_stats_inc ("amq_exchange_agent_unnamed_10", &s_amq_exchange_agent_unnamed_10_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_broker_unbind_queue (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_BROKER_UNBIND_QUEUE))
    icl_stats_inc ("amq_exchange_agent_broker_unbind_queue", &s_amq_exchange_agent_broker_unbind_queue_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{


#define self tcb->amq_exchange
amq_queue_t *
    queue;

    queue = broker_unbind_queue_m->queue;
        {
amq_queue_bindings_list_t
    *queue_bindings;                //  List of bindings for queue
amq_binding_t
    *binding;

queue_bindings =
    amq_queue_bindings_list_table_search (self->queue_bindings, queue->name);
if (queue_bindings) {
    //  Iterate over queue_bindings list, removing each binding
    while (1) {
        binding = amq_queue_bindings_list_pop (queue_bindings);
        if (!binding)
            break;
        if (amq_binding_unbind_queue (binding, queue))
            //  If binding is now empty, destroy it
            self->unbind (self->object, binding);
        amq_binding_unlink (&binding);
    }
    //  Per-queue bindings list is now empty, destroy it
    amq_queue_bindings_list_destroy (&queue_bindings);
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_12 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_12))
    icl_stats_inc ("amq_exchange_agent_unnamed_12", &s_amq_exchange_agent_unnamed_12_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_INSPECT))
    icl_stats_inc ("amq_exchange_agent_inspect", &s_amq_exchange_agent_inspect_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{


#define self tcb->amq_exchange
amq_content_basic_t *
    request;

    request = inspect_m->request;
        {
asl_field_list_t
    *fields;                        //  Properties of object
icl_shortstr_t
    field_value;
            amq_binding_t
            *binding;

fields = asl_field_list_new (NULL);
icl_shortstr_cpy (field_value, self->name);
asl_field_new_string (fields, "name", field_value);
icl_shortstr_cpy (field_value, amq_exchange_type_name (self->type));
asl_field_new_string (fields, "type", field_value);
icl_shortstr_fmt (field_value, "%d", amq_binding_list_count (self->binding_list));
asl_field_new_string (fields, "bindings", field_value);
icl_shortstr_fmt (field_value, "%d", self->contents_in);
asl_field_new_string (fields, "messages_in", field_value);
icl_shortstr_fmt (field_value, "%d", self->contents_out);
asl_field_new_string (fields, "messages_out", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (self->traffic_in / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_in", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (self->traffic_out / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_out", field_value);
strclr (field_value);
            binding = amq_binding_list_first (self->binding_list);
        if (binding)
            icl_shortstr_fmt (field_value, "%d", binding->binding_mgt->object_id);
while (*field_value) {
    asl_field_new_string (fields, "binding", field_value);
    strclr (field_value);
            binding = amq_binding_list_next (&binding);
        if (binding)
            icl_shortstr_fmt (field_value, "%d", binding->binding_mgt->object_id);
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
action_unnamed_14 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_14))
    icl_stats_inc ("amq_exchange_agent_unnamed_14", &s_amq_exchange_agent_unnamed_14_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_MODIFY))
    icl_stats_inc ("amq_exchange_agent_modify", &s_amq_exchange_agent_modify_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{


#define self tcb->amq_exchange
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
action_unnamed_16 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_16))
    icl_stats_inc ("amq_exchange_agent_unnamed_16", &s_amq_exchange_agent_unnamed_16_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_METHOD))
    icl_stats_inc ("amq_exchange_agent_method", &s_amq_exchange_agent_method_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{


#define self tcb->amq_exchange
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
action_unnamed_18 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT)  ||  defined (BASE_STATS_AMQ_EXCHANGE_AGENT_UNNAMED_18))
    icl_stats_inc ("amq_exchange_agent_unnamed_18", &s_amq_exchange_agent_unnamed_18_stats);
#endif        
#define tcb ((amq_exchange_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

