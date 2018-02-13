/*---------------------------------------------------------------------------
    amq_broker_agent.c - functions for amq_broker_agent.

    Generated from amq_broker_agent.smt by smt_gen.gsl using GSL/4.

    
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
#include "amq_broker_agent.h"

#define class_main_state                           1
#define class_shutting_down_state                  2

#define destroy_m ((amq_broker_agent_destroy_t *) thread->method->data)

#define unbind_queue_m ((amq_broker_agent_unbind_queue_t *) thread->method->data)

#define inspect_m ((amq_broker_agent_inspect_t *) thread->method->data)

#define modify_m ((amq_broker_agent_modify_t *) thread->method->data)

#define method_m ((amq_broker_agent_method_t *) thread->method->data)

enum {
    waiting_for_shutdown_event                     = 1,
    finished_with_shutdown_event                   = 2,
    interrupt_event                                = 3,
    monitor_event                                  = 4,
    shutdown_event                                 = 5,
    destroy_m_event                                = 6,
    unbind_queue_m_event                           = 7,
    inspect_m_event                                = 8,
    modify_m_event                                 = 9,
    method_m_event                                 = 10,
    start_m_event                                  = 11,
    shutdown_m_event                               = 12,
};

#define laststate                                  2
#define lastevent                                  12
#define lastplace                                  27

#define amq_broker_agent_agent_name                "Amq-Broker-Agent"

#define class_thread_name                          "Class"

#define main_state_name                            "Main"
#define shutting_down_state_name                   "Shutting-Down"

#define waiting_for_shutdown_event_name            "Waiting-For-Shutdown"
#define finished_with_shutdown_event_name          "Finished-With-Shutdown"
#define interrupt_event_name                       "Interrupt"
#define monitor_event_name                         "Monitor"
#define shutdown_event_name                        "Shutdown"
#define destroy_m_event_name                       "Destroy-M"
#define unbind_queue_m_event_name                  "Unbind-Queue-M"
#define inspect_m_event_name                       "Inspect-M"
#define modify_m_event_name                        "Modify-M"
#define method_m_event_name                        "Method-M"
#define start_m_event_name                         "Start-M"
#define shutdown_m_event_name                      "Shutdown-M"

#define shutdown_active_connections_action_name    "Shutdown-Active-Connections"
#define shutdown_broker_action_name                "Shutdown-Broker"
#define report_server_interrupted_action_name      "Report-Server-Interrupted"
#define monitor_action_name                        "Monitor"
#define destroy_action_name                        "Destroy"
#define free_action_name                           "Free"
#define unnamed_7_action_name                      "Unnamed-7"
#define unnamed_8_action_name                      "Unnamed-8"
#define unbind_queue_action_name                   "Unbind-Queue"
#define unnamed_10_action_name                     "Unnamed-10"
#define inspect_action_name                        "Inspect"
#define unnamed_12_action_name                     "Unnamed-12"
#define modify_action_name                         "Modify"
#define unnamed_14_action_name                     "Unnamed-14"
#define method_action_name                         "Method"
#define unnamed_16_action_name                     "Unnamed-16"
#define start_action_name                          "Start"
#define unnamed_18_action_name                     "Unnamed-18"
#define shutdown_action_name                       "Shutdown"
#define unnamed_20_action_name                     "Unnamed-20"

#define the_next_event                             thread->_next_event
#define exception_raised                           thread->_exception_raised

typedef struct
  {
    char *         file;
    size_t         line;
  }
amq_broker_agent_destroy_t;

typedef struct
  {
    amq_queue_t *  queue;
  }
amq_broker_agent_unbind_queue_t;

typedef struct
  {
    amq_content_basic_t *  request;
  }
amq_broker_agent_inspect_t;

typedef struct
  {
    amq_content_basic_t *  request;
    asl_field_list_t *  fields;
  }
amq_broker_agent_modify_t;

typedef struct
  {
    char *         method_name;
    amq_content_basic_t *  request;
    asl_field_list_t *  fields;
  }
amq_broker_agent_method_t;


static void
    s_shutdown_connection (amq_server_connection_t *connection_p, void *argument);
static int
    s_interrupted = 0,                  //  Server interrupted?
    s_shutdown_time_spent = 0;          //  Time spent in graceful shutdown
static dbyte
    s_active_connections = 0;           //  Used during server shutdown


#include "version.h"

static icl_cache_t
    *s_class_context_cache = NULL;

typedef struct {
    int
        links;

        amq_broker_t
            *amq_broker;
    
} amq_broker_agent_class_context_t;

static icl_cache_t
    *s_destroy_cache = NULL;
static icl_cache_t
    *s_unbind_queue_cache = NULL;
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
    waiting_for_shutdown_event_name,
    finished_with_shutdown_event_name,
    interrupt_event_name,
    monitor_event_name,
    shutdown_event_name,
    destroy_m_event_name,
    unbind_queue_m_event_name,
    inspect_m_event_name,
    modify_m_event_name,
    method_m_event_name,
    start_m_event_name,
    shutdown_m_event_name
};

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT)         ||  defined (BASE_TRACE)  || defined (BASE_TRACE_AMQ_BROKER_AGENT)   ||  defined (AMQ_BROKER_AGENT_TRACE))
static const char *action_name [] = {
    "<NULL>",
    shutdown_active_connections_action_name,
    shutdown_broker_action_name,
    report_server_interrupted_action_name,
    monitor_action_name,
    destroy_action_name,
    free_action_name,
    unnamed_7_action_name,
    unnamed_8_action_name,
    unbind_queue_action_name,
    unnamed_10_action_name,
    inspect_action_name,
    unnamed_12_action_name,
    modify_action_name,
    unnamed_14_action_name,
    method_action_name,
    unnamed_16_action_name,
    start_action_name,
    unnamed_18_action_name,
    shutdown_action_name,
    unnamed_20_action_name
};
#endif

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
static Bool
    s_animate = FALSE;
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_SHUTDOWN_ACTIVE_CONNECTIONS))
static icl_stats_t *s_amq_broker_agent_shutdown_active_connections_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_SHUTDOWN_BROKER))
static icl_stats_t *s_amq_broker_agent_shutdown_broker_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_REPORT_SERVER_INTERRUPTED))
static icl_stats_t *s_amq_broker_agent_report_server_interrupted_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_MONITOR))
static icl_stats_t *s_amq_broker_agent_monitor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_DESTROY))
static icl_stats_t *s_amq_broker_agent_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_FREE))
static icl_stats_t *s_amq_broker_agent_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_7))
static icl_stats_t *s_amq_broker_agent_unnamed_7_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_8))
static icl_stats_t *s_amq_broker_agent_unnamed_8_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNBIND_QUEUE))
static icl_stats_t *s_amq_broker_agent_unbind_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_10))
static icl_stats_t *s_amq_broker_agent_unnamed_10_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_INSPECT))
static icl_stats_t *s_amq_broker_agent_inspect_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_12))
static icl_stats_t *s_amq_broker_agent_unnamed_12_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_MODIFY))
static icl_stats_t *s_amq_broker_agent_modify_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_14))
static icl_stats_t *s_amq_broker_agent_unnamed_14_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_METHOD))
static icl_stats_t *s_amq_broker_agent_method_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_16))
static icl_stats_t *s_amq_broker_agent_unnamed_16_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_START))
static icl_stats_t *s_amq_broker_agent_start_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_18))
static icl_stats_t *s_amq_broker_agent_unnamed_18_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_SHUTDOWN))
static icl_stats_t *s_amq_broker_agent_shutdown_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_20))
static icl_stats_t *s_amq_broker_agent_unnamed_20_stats = NULL;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//  Function prototypes                                                        

static int    amq_broker_agent_manager        (smt_thread_t **thread);
static int    amq_broker_agent_catcher        (smt_thread_t *thread);
static int    amq_broker_agent_class_destroy  (smt_thread_t *thread);
static void   find_thread_state_next_state    (int          *thread_type,
                                               smt_state_t  *state_id,
                                               smt_event_t  *event_id,
                                               smt_state_t  *nextstate_id,
                                               smt_thread_t *thread);
static void   report_unrecognised_event_error (smt_thread_t *thread);
static void   report_state_machine_error      (smt_thread_t *thread);

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
static void   animate_start_new_event         (smt_thread_t *thread,
                                               smt_event_t  saveevent_id);
static void   animate_action                  (smt_thread_t *thread_id,
                                               int          action_id);
static int    find_thread_type                (smt_place_t  place);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER_AGENT)           ||  defined (AMQ_BROKER_AGENT_TRACE))
static void   s_dump                          (icl_os_thread_t apr_os_thread,
                                               apr_time_t      time,
                                               qbyte           info);

#endif

static int    action_shutdown_active_connections  (smt_thread_t *thread);
static int    action_shutdown_broker          (smt_thread_t *thread);
static int    action_report_server_interrupted  (smt_thread_t *thread);
static int    action_monitor                  (smt_thread_t *thread);
static int    action_destroy                  (smt_thread_t *thread);
static int    action_free                     (smt_thread_t *thread);
static int    action_unnamed_7                (smt_thread_t *thread);
static int    action_unnamed_8                (smt_thread_t *thread);
static int    action_unbind_queue             (smt_thread_t *thread);
static int    action_unnamed_10               (smt_thread_t *thread);
static int    action_inspect                  (smt_thread_t *thread);
static int    action_unnamed_12               (smt_thread_t *thread);
static int    action_modify                   (smt_thread_t *thread);
static int    action_unnamed_14               (smt_thread_t *thread);
static int    action_method                   (smt_thread_t *thread);
static int    action_unnamed_16               (smt_thread_t *thread);
static int    action_start                    (smt_thread_t *thread);
static int    action_unnamed_18               (smt_thread_t *thread);
static int    action_shutdown                 (smt_thread_t *thread);
static int    action_unnamed_20               (smt_thread_t *thread);
static int
amq_broker_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line);
int
amq_broker_agent_destroy_destructor (void *data);
static int
amq_broker_agent_unbind_queue_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_queue_t *  queue);
int
amq_broker_agent_unbind_queue_destructor (void *data);
static int
amq_broker_agent_inspect_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request);
int
amq_broker_agent_inspect_destructor (void *data);
static int
amq_broker_agent_modify_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields);
int
amq_broker_agent_modify_destructor (void *data);
static int
amq_broker_agent_method_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         method_name,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields);
int
amq_broker_agent_method_destructor (void *data);
//  Function definitions                                                       

static int
amq_broker_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line)
{
    int
        rc = 0;
    amq_broker_agent_destroy_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_destroy_cache);
    _message->file                      = file;
    _message->line                      = line;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_broker_agent_destroy_destructor);
    
    return rc;
}

int
amq_broker_agent_destroy_destructor (void *data)
{
    int
        rc = 0;
char * file;
size_t line;

    file = ((amq_broker_agent_destroy_t *) data)-> file;
    line = ((amq_broker_agent_destroy_t *) data)-> line;


    icl_mem_free (data);
    return rc;
}


static int
amq_broker_agent_unbind_queue_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_queue_t *  queue)
{
    int
        rc = 0;
    amq_broker_agent_unbind_queue_t
        *_message;
        
    //  Possess code for unbind queue
    

    queue = amq_queue_link (queue);
    
    

    _message = icl_mem_cache_alloc (s_unbind_queue_cache);
    _message->queue                     = queue;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_broker_agent_unbind_queue_destructor);
    
    return rc;
}

int
amq_broker_agent_unbind_queue_destructor (void *data)
{
    int
        rc = 0;
amq_queue_t * queue;

    queue = ((amq_broker_agent_unbind_queue_t *) data)-> queue;



    amq_queue_unlink (&queue);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_broker_agent_inspect_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request)
{
    int
        rc = 0;
    amq_broker_agent_inspect_t
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
                          amq_broker_agent_inspect_destructor);
    
    return rc;
}

int
amq_broker_agent_inspect_destructor (void *data)
{
    int
        rc = 0;
amq_content_basic_t * request;

    request = ((amq_broker_agent_inspect_t *) data)-> request;



    amq_content_basic_unlink (&request);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_broker_agent_modify_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields)
{
    int
        rc = 0;
    amq_broker_agent_modify_t
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
                          amq_broker_agent_modify_destructor);
    
    return rc;
}

int
amq_broker_agent_modify_destructor (void *data)
{
    int
        rc = 0;
amq_content_basic_t * request;
asl_field_list_t * fields;

    request = ((amq_broker_agent_modify_t *) data)-> request;
    fields = ((amq_broker_agent_modify_t *) data)-> fields;



    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_broker_agent_method_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         method_name,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields)
{
    int
        rc = 0;
    amq_broker_agent_method_t
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
                          amq_broker_agent_method_destructor);
    
    return rc;
}

int
amq_broker_agent_method_destructor (void *data)
{
    int
        rc = 0;
char * method_name;
amq_content_basic_t * request;
asl_field_list_t * fields;

    method_name = ((amq_broker_agent_method_t *) data)-> method_name;
    request = ((amq_broker_agent_method_t *) data)-> request;
    fields = ((amq_broker_agent_method_t *) data)-> fields;



    icl_mem_free (method_name);
    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    
    

    icl_mem_free (data);
    return rc;
}


int
amq_broker_agent_start (
    smt_thread_t * thread)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_broker_agent_manager);
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
amq_broker_agent_shutdown (
    smt_thread_t * thread)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_broker_agent_manager);
        rc = smt_method_send (
                thread->reply_queue,
                shutdown_m_event,
                SMT_PRIORITY_NORMAL,
                SMT_OK, NULL, NULL);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_broker_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_broker_agent_manager);
        rc = amq_broker_agent_destroy_send (
                thread->reply_queue, destroy_m_event,
                file,
                line);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_broker_agent_unbind_queue (
    smt_thread_t * thread,
    amq_queue_t *         queue)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_broker_agent_manager);
        rc = amq_broker_agent_unbind_queue_send (
                thread->reply_queue, unbind_queue_m_event,
                queue);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_broker_agent_inspect (
    smt_thread_t * thread,
    amq_content_basic_t * request)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_broker_agent_manager);
        rc = amq_broker_agent_inspect_send (
                thread->reply_queue, inspect_m_event,
                request);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_broker_agent_modify (
    smt_thread_t * thread,
    amq_content_basic_t * request,
    asl_field_list_t *    fields)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_broker_agent_manager);
        rc = amq_broker_agent_modify_send (
                thread->reply_queue, modify_m_event,
                request,
                fields);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_broker_agent_method (
    smt_thread_t * thread,
    char *                method_name,
    amq_content_basic_t * request,
    asl_field_list_t *    fields)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_broker_agent_manager);
        rc = amq_broker_agent_method_send (
                thread->reply_queue, method_m_event,
                method_name,
                request,
                fields);
    }
    else
        rc = -1;
        
    return rc;
}


//  Shutdown a single connection
static void
s_shutdown_connection (amq_server_connection_t *connection_p, void *argument)
{
    amq_server_connection_t
        *connection;

    connection = amq_server_connection_link (connection_p);
    if (connection) {
        if (amq_server_agent_shutdown (connection->thread) == 0)
            s_active_connections++;
        amq_server_connection_unlink (&connection);
    }
}

void
amq_broker_agent_term (void)
{

}

int 
amq_broker_agent_init (void)
{
    int
        rc = SMT_OK;                    //  Return code

    s_class_context_cache = icl_cache_get (sizeof (amq_broker_agent_class_context_t));
    s_destroy_cache = icl_cache_get (sizeof (amq_broker_agent_destroy_t));
    s_unbind_queue_cache = icl_cache_get (sizeof (amq_broker_agent_unbind_queue_t));
    s_inspect_cache = icl_cache_get (sizeof (amq_broker_agent_inspect_t));
    s_modify_cache = icl_cache_get (sizeof (amq_broker_agent_modify_t));
    s_method_cache = icl_cache_get (sizeof (amq_broker_agent_method_t));

    //  Initialise basic stuff.
    smt_initialise ();
    
    {

    }
    icl_system_register (NULL, amq_broker_agent_term);
    
    return rc;
}

void
amq_broker_agent_animate (Bool animate)
{
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
    s_animate = animate;
#endif
}

smt_thread_t *
amq_broker_agent_class_thread_new (
    amq_broker_t * self)
{
    smt_thread_t
        *thread;

    thread = smt_thread_new (amq_broker_agent_manager,
                             amq_broker_agent_catcher,
                             amq_broker_agent_class_destroy);
                             

#if (defined (AMQ_BROKER_AGENT_TRACE))
    thread->trace = icl_trace_new (ICL_TRACE_SIZE);
#endif

    if (thread) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
        thread->animate = s_animate;
        if (s_animate)
            icl_console_print ("%4lu> %-15s/%-15s <Created>",
                thread->id,
                "amq_broker_agent",
                class_thread_name);
#endif

        thread->place   = 1;
        thread->context = icl_mem_cache_alloc (s_class_context_cache);
        memset (thread->context, 0, sizeof (amq_broker_agent_class_context_t));
        ((amq_broker_agent_class_context_t *) thread->context)->links = 1;
        thread->event_name = event_name;
{
#define tcb ((amq_broker_agent_class_context_t *) thread->context)

        tcb->amq_broker = self;
    
#undef  tcb
}
    }
    return thread;
}


static int
amq_broker_agent_manager (smt_thread_t **thread_p)
{
    smt_thread_t
        *thread = *thread_p;
        
    int
        rc;
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))

    smt_event_t
        saveevent_id = SMT_NULL_EVENT;
#endif
        
    assert (thread->manager == amq_broker_agent_manager);
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
            case 8:
            case 20:
            case 27:
                thread->place = SMT_TERM_PLACE;
                break;
            case 3:
            case 13:
            case 14:
            case 11:
            case 12:
            case 10:
            case 4:
            case 9:
            case 6:
            case 5:
                thread->place = 2;
                break;
            case 24:
            case 25:
            case 26:
            case 23:
            case 22:
            case 21:
            case 19:
            case 17:
            case 18:
            case 7:
            case 16:
                thread->place = 15;
                break;
        }    
    else
    if (thread->module == 0) {
        if (thread->place == 1) { //                Class thread
            if (!thread->shutting_down) {
{
#define tcb ((amq_broker_agent_class_context_t *) thread->context)

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
        if (thread->place < 15)                 //  Main state
            thread->place = 2;
        else
            thread->place = 15;
    }

    switch (thread->place) {
        case 2:                         //  main state                          
{
#define tcb ((amq_broker_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case waiting_for_shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 3; break;
                case finished_with_shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 4; break;
                case interrupt_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 5; break;
                case monitor_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 6; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 7; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 8; break;
                case unbind_queue_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 9; break;
                case inspect_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 10; break;
                case modify_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 11; break;
                case method_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 12; break;
                case start_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 13; break;
                case shutdown_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 14; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
        case 15:                        //  shutting down state                 
{
#define tcb ((amq_broker_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case waiting_for_shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 16; break;
                case finished_with_shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 17; break;
                case interrupt_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 18; break;
                case monitor_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 19; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 20; break;
                case unbind_queue_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 21; break;
                case inspect_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 22; break;
                case modify_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 23; break;
                case method_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 24; break;
                case start_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 25; break;
                case shutdown_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 26; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 27; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
    }
                                  
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
    if (thread->animate && thread->module == 1)
        animate_start_new_event (thread, saveevent_id);
#endif

    switch (thread->place) {
        case 3:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 1);
#endif
                    rc = action_shutdown_active_connections (thread);

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
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 2);
#endif
                    rc = action_shutdown_broker (thread);

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
        case 5:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 3);
#endif
                    rc = action_report_server_interrupted (thread);

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
        case 6:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 4);
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
        case 7:
        case 16:
        case 17:
        case 18:
        case 19:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
            switch (thread->module) {
                case 1:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    if (thread->place == 27)
                        thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 20:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 5);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 6);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
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
        case 8:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 5);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 6);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
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

                case 4:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 9:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 9);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
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
        case 10:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 11);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
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
        case 11:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 13);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
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
        case 12:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 15);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
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
        case 13:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 17);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
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
        case 14:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
                    if (thread->animate)
                        animate_action (thread, 19);
#endif
                    rc = action_shutdown (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
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
amq_broker_agent_catcher (smt_thread_t *thread)
{
    return SMT_OK;
}


static int    
amq_broker_agent_class_destroy (smt_thread_t *thread)
{
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (AMQ_BROKER_AGENT_TRACE))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))
    if (thread->animate)
        icl_console_print ("%4lu> %-15s/%-15s <Destroyed>",
                  thread->id,
                  "amq_broker_agent",
                 class_thread_name);

#endif
    if (--((amq_broker_agent_class_context_t *) thread->context)->links == 0)
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
        if (thread->place < 15)
          {
            *state_id = 1;
            switch (thread->place) {
                case 3: *event_id = 1;   *nextstate_id = 1;   break;
                case 4: *event_id = 2;   *nextstate_id = 1;   break;
                case 5: *event_id = 3;   *nextstate_id = 1;   break;
                case 6: *event_id = 4;   *nextstate_id = 1;   break;
                case 7: *event_id = 5;   *nextstate_id = 2;   break;
                case 8: *event_id = 6;   break;
                case 9: *event_id = 7;   *nextstate_id = 1;   break;
                case 10: *event_id = 8;   *nextstate_id = 1;   break;
                case 11: *event_id = 9;   *nextstate_id = 1;   break;
                case 12: *event_id = 10;   *nextstate_id = 1;   break;
                case 13: *event_id = 11;   *nextstate_id = 1;   break;
                case 14: *event_id = 12;   *nextstate_id = 1;   break;
            }
          }
        else
          {
            *state_id = 2;
            switch (thread->place) {
                case 16: *event_id = 1;   *nextstate_id = 2;   break;
                case 17: *event_id = 2;   *nextstate_id = 2;   break;
                case 18: *event_id = 3;   *nextstate_id = 2;   break;
                case 19: *event_id = 4;   *nextstate_id = 2;   break;
                case 20: *event_id = 6;   break;
                case 21: *event_id = 7;   *nextstate_id = 2;   break;
                case 22: *event_id = 8;   *nextstate_id = 2;   break;
                case 23: *event_id = 9;   *nextstate_id = 2;   break;
                case 24: *event_id = 10;   *nextstate_id = 2;   break;
                case 25: *event_id = 11;   *nextstate_id = 2;   break;
                case 26: *event_id = 12;   *nextstate_id = 2;   break;
                case 27: *event_id = 5;   break;
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
    icl_console_print ("amq_broker_agent: Unrecognised event '%s' in '%s' thread number: %u, state: %s",
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

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_BROKER_AGENT))

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
            "amq_broker_agent",
            thread_name [thread_type],
            state_name [state_id]);
  icl_console_print ("%4lu> %-15s/%-15s    (--) %-32s->%s",
            thread->id,
            "amq_broker_agent",
            thread_name [thread_type],
            event_name [event_id != SMT_NULL_EVENT ? event_id : saveevent_id],
            nextstate_id ? state_name [nextstate_id] : "");
}

static void
animate_action (smt_thread_t *thread, int action_id)
{
    icl_console_print ("%4lu> %-15s/%-15s           + %s",
              thread->id,
              "amq_broker_agent",
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_BROKER_AGENT)             ||  defined (AMQ_BROKER_AGENT_TRACE))
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
                                       "amq_broker_agent",
                                       action_name [action_id]);
    }
    else
    if (state_or_event_or_action > laststate) {
        event_id = state_or_event_or_action - laststate;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s    (--) %-32s",
                                       thread_id,
                                       "amq_broker_agent",
                                       event_name [event_id]);
    }
    else {
        state_id = state_or_event_or_action;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s %s:",
                                       thread_id,
                                       "amq_broker_agent",
                                       state_id ? state_name [state_id] : "<Destroyed>");
    }
}

#endif
static int
action_shutdown_active_connections (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_SHUTDOWN_ACTIVE_CONNECTIONS))
    icl_stats_inc ("amq_broker_agent_shutdown_active_connections", &s_amq_broker_agent_shutdown_active_connections_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{

            
#define self tcb->amq_broker

        {
//  Spend a maximum of 30 seconds shutting down
s_shutdown_time_spent++;
if (s_shutdown_time_spent > 30)
    smt_thread_set_next_event (thread, finished_with_shutdown_event);
//  For each active connection, tell it's amq_server_agent instance
//  to shut it down.
s_active_connections = 0;
amq_server_connection_table_apply (
    self->connections, s_shutdown_connection, NULL);
if (s_active_connections) {
    if (s_shutdown_time_spent == 1)
        //  Only print message once
        smt_log_print (self->alert_log,
            "I: closing %d connection%s, please wait up to 30 seconds",
            s_active_connections,
            s_active_connections > 1? "s": "");
    //  Loop and try again in one second
    smt_timer_request_delay (thread, 1000000,
        waiting_for_shutdown_event);
} 
else
    //  Finished, proceed with broker shutdown
    smt_thread_set_next_event (thread, finished_with_shutdown_event);
        }
        
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_shutdown_broker (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_SHUTDOWN_BROKER))
    icl_stats_inc ("amq_broker_agent_shutdown_broker", &s_amq_broker_agent_shutdown_broker_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{

            
#define self tcb->amq_broker

        {
smt_shut_down ();
        }
        
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_report_server_interrupted (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_REPORT_SERVER_INTERRUPTED))
    icl_stats_inc ("amq_broker_agent_report_server_interrupted", &s_amq_broker_agent_report_server_interrupted_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{

            
#define self tcb->amq_broker

        {
s_interrupted++;
if (s_interrupted == 1) {
    smt_log_print (self->alert_log,
        "I: caught signal, shutting down");
    //  Start graceful shutdown
    amq_broker_shutdown (self);
}
else
if (s_interrupted > 1) {
    smt_log_print (self->alert_log,
        "I: caught another signal, shutting down immediately");
    smt_shut_down ();
}
        }
        
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_monitor (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_MONITOR))
    icl_stats_inc ("amq_broker_agent_monitor", &s_amq_broker_agent_monitor_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{

            
#define self tcb->amq_broker

        {
//  Cycle log files at midnight
if (ipr_time_now () > 235900) {
    if (!self->cycled) {
        self->cycled = TRUE;        //  Don't cycle again today
        smt_log_cycle (self->debug_log);
        smt_log_cycle (self->daily_log);
        smt_log_cycle (self->alert_log);
    }
}
else
    self->cycled = FALSE;

if (self->monitor_timer) {
    self->monitor_timer--;
    if (self->monitor_timer == 0) {
        Bool
            new_stats = FALSE;      //  Do we have new stats to print?

        self->monitor_timer = amq_server_config_monitor (amq_server_config);
        if (ipr_meter_mark (self->imeter, amq_server_config_monitor (amq_server_config))) {
            smt_log_print (self->debug_log,
                "I: incoming rate=%d mean=%d peak=%d",
                self->imeter->current,
                self->imeter->average,
                self->imeter->maximum);
            new_stats = TRUE;
        }
        if (ipr_meter_mark (self->ometer, amq_server_config_monitor (amq_server_config))) {
            smt_log_print (self->debug_log,
                "I: outgoing rate=%d mean=%d peak=%d iomean=%d",
                self->ometer->current,
                self->ometer->average,
                self->ometer->maximum,
                self->ometer->average + self->imeter->average);
            new_stats = TRUE;
        }
        //  Record statistics if necessary
        if (self->stats && new_stats) {
            fprintf (self->stats, "%d\t%zu\t%d\t%d\t%d\t%d\n",
                amq_server_connection_count (),
                ipr_bucket_used () / 1024,
                self->imeter->current, self->ometer->current,
                self->imeter->average, self->ometer->average);
        }
    }
}
smt_timer_request_delay (self->thread, 1000 * 1000, monitor_event);

if (self->dump_state_timer) {
    self->dump_state_timer--;
    if (self->dump_state_timer == 0) {
        self->dump_state_timer = amq_server_config_dump_state (amq_server_config);
        smt_log_print (amq_broker->alert_log,
            "I: cnn=%d msg=%d mem=%uK/%uK exc=%d que=%d csm=%d bnd=%d adx=%d idx=%d map=%d",
            amq_server_connection_count (),
            amq_content_basic_count (),
            ipr_bucket_used () / 1024,
            icl_mem_used () / 1024,
            amq_exchange_count (),
            amq_queue_count (),
            amq_consumer_count (),
            amq_binding_count (),
            amq_index_count (),
            ipr_index_count (),
            ipr_bits_count ());

        smt_log_print (amq_broker->alert_log,
            "I: qcn=%d cnq=%d dsk=%d dfd=%d din=%d dot=%d dhi=%d",
            amq_queue_connection_count (),
            amq_connection_queue_count (),
            amq_broker->direct_sunk,
            amq_broker->direct_fed,
            amq_broker->direct_in,
            amq_broker->direct_out,
            amq_broker->direct_high);
    }
}
if (self->auto_crash_timer) {
    if (--self->auto_crash_timer == 0) {
        smt_log_print (amq_broker->alert_log,
            "W: ************************  AUTO-CRASH  ************************");
        smt_log_print (amq_broker->alert_log,
            "W: server is now emulating a system crash, and will exit brutally.");
        exit (0);
    }
}
if (self->auto_block_timer) {
    if (--self->auto_block_timer == 0) {
        smt_log_print (amq_broker->alert_log,
            "W: ************************  AUTO-BLOCK  ************************");
        smt_log_print (amq_broker->alert_log,
            "W: server is now emulating a blockage, and will freeze for 5 minutes.");
        sleep (300);
    }
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_DESTROY))
    icl_stats_inc ("amq_broker_agent_destroy", &s_amq_broker_agent_destroy_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{


#define self tcb->amq_broker
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
smt_signal_deregister (SIGINT);
smt_signal_deregister (SIGTERM);
ipr_meter_destroy (&self->imeter);
ipr_meter_destroy (&self->ometer);
amq_server_connection_table_destroy (&self->connections);
amq_server_connection_list_destroy (&self->connection_list);
smt_thread_unlink (&self->agent_thread);
amq_server_agent_term ();
if (self->stats)
    fclose (self->stats);

amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

amq_failover_destroy (&self->failover);
amq_console_config_destroy (&amq_console_config);
amq_vhost_destroy (&self->vhost);
amq_connection_by_broker_destroy (&self->mgt_connection_list);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_FREE))
    icl_stats_inc ("amq_broker_agent_free", &s_amq_broker_agent_free_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{


#define self tcb->amq_broker
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_broker object");
    amq_broker_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_broker_free (self);
    self = NULL;
}
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_7))
    icl_stats_inc ("amq_broker_agent_unnamed_7", &s_amq_broker_agent_unnamed_7_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_8 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_8))
    icl_stats_inc ("amq_broker_agent_unnamed_8", &s_amq_broker_agent_unnamed_8_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNBIND_QUEUE))
    icl_stats_inc ("amq_broker_agent_unbind_queue", &s_amq_broker_agent_unbind_queue_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{


#define self tcb->amq_broker
amq_queue_t *
    queue;

    queue = unbind_queue_m->queue;
        {
amq_server_connection_t
    *connection;

//  Go through all connections
connection = amq_server_connection_list_first (self->connection_list);
while (connection) {
    amq_server_connection_unbind_queue (connection, queue);
    connection = amq_server_connection_list_next (&connection);
}
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_10))
    icl_stats_inc ("amq_broker_agent_unnamed_10", &s_amq_broker_agent_unnamed_10_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_INSPECT))
    icl_stats_inc ("amq_broker_agent_inspect", &s_amq_broker_agent_inspect_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{


#define self tcb->amq_broker
amq_content_basic_t *
    request;

    request = inspect_m->request;
        {
asl_field_list_t
    *fields;                        //  Properties of object
icl_shortstr_t
    field_value;
            amq_exchange_t
            *exchange;
            amq_queue_t
            *queue;
            amq_connection_t
            *connection;

fields = asl_field_list_new (NULL);
icl_shortstr_fmt (field_value, "OpenAMQ %s", VERSION);
asl_field_new_string (fields, "name", field_value);
ipr_time_iso8601 (self->started,
        ipr_date_format_minute, 0, FALSE, field_value);
asl_field_new_string (fields, "started", field_value);
icl_shortstr_fmt (field_value, "%d", self->locked);
asl_field_new_string (fields, "locked", field_value);
icl_shortstr_fmt (field_value, "%dK", (int) (icl_mem_used () / 1024));
asl_field_new_string (fields, "datamem", field_value);
icl_shortstr_fmt (field_value, "%dK", (int) (ipr_bucket_used () / 1024));
asl_field_new_string (fields, "bucketmem", field_value);
icl_shortstr_fmt (field_value, "%d", amq_content_basic_count ());
asl_field_new_string (fields, "messages", field_value);
icl_shortstr_fmt (field_value, "%d", amq_consumer_count ());
asl_field_new_string (fields, "consumers", field_value);
icl_shortstr_fmt (field_value, "%d", amq_binding_count ());
asl_field_new_string (fields, "bindings", field_value);
strclr (field_value);
            exchange = amq_exchange_by_vhost_first (self->vhost->exchange_list);
        icl_shortstr_fmt (field_value, "%d", exchange->object_id);
while (*field_value) {
    asl_field_new_string (fields, "exchange", field_value);
    strclr (field_value);
            exchange = amq_exchange_by_vhost_next (&exchange);
        if (exchange)
            icl_shortstr_fmt (field_value, "%d", exchange->object_id);
}
strclr (field_value);
            //  Get first queue and then skip private queues
        queue = amq_queue_by_vhost_first (self->vhost->queue_list);
        while (queue && queue->exclusive)
            queue = amq_queue_by_vhost_next (&queue);
        if (queue)
            icl_shortstr_fmt (field_value, "%d", queue->object_id);
while (*field_value) {
    asl_field_new_string (fields, "queue", field_value);
    strclr (field_value);
            //  Get next queue and then skip private queues
        queue = amq_queue_by_vhost_next (&queue);
        while (queue && queue->exclusive)
            queue = amq_queue_by_vhost_next (&queue);
        if (queue)
            icl_shortstr_fmt (field_value, "%d", queue->object_id);
}
strclr (field_value);
            connection = amq_connection_by_broker_first (self->mgt_connection_list);
        if (connection)
            icl_shortstr_fmt (field_value, "%d", connection->object_id);
while (*field_value) {
    asl_field_new_string (fields, "connection", field_value);
    strclr (field_value);
            connection = amq_connection_by_broker_next (&connection);
        if (connection)
            icl_shortstr_fmt (field_value, "%d", connection->object_id);
}
strclr (field_value);
            icl_shortstr_fmt (field_value, "%d", amq_console_config->object_id);
asl_field_new_string (fields, "config", field_value);
amq_console_reply_ok (amq_console, "inspect-reply", request, self->object_id, fields, NULL);
asl_field_list_unlink (&fields);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_12))
    icl_stats_inc ("amq_broker_agent_unnamed_12", &s_amq_broker_agent_unnamed_12_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_MODIFY))
    icl_stats_inc ("amq_broker_agent_modify", &s_amq_broker_agent_modify_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{


#define self tcb->amq_broker
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
action_unnamed_14 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_14))
    icl_stats_inc ("amq_broker_agent_unnamed_14", &s_amq_broker_agent_unnamed_14_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_METHOD))
    icl_stats_inc ("amq_broker_agent_method", &s_amq_broker_agent_method_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{


#define self tcb->amq_broker
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
if (streq (method_name, "shutdown")) {
                smt_log_print (amq_broker->alert_log,
            "W: operator requested shutdown - closing all connections");
        amq_broker_shutdown (self);
}
if (streq (method_name, "lock")) {
    asl_field_t
        *field;
    Bool
        setting = FALSE;
    field = asl_field_list_search (fields, "setting");
    if (field) {
        setting = atoi (asl_field_string (field));
        asl_field_unlink (&field);
    }
    self->locked = setting;
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
action_unnamed_16 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_16))
    icl_stats_inc ("amq_broker_agent_unnamed_16", &s_amq_broker_agent_unnamed_16_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_START))
    icl_stats_inc ("amq_broker_agent_start", &s_amq_broker_agent_start_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{


#define self tcb->amq_broker

        {
//  We will run the broker monitor once per second, unconditionally
smt_timer_request_delay (self->thread, 1000 * 1000, monitor_event);
//  Register to receive interrupt event on SIGINT, SIGTERM
smt_signal_register (SIGINT, thread, interrupt_event);
smt_signal_register (SIGTERM, thread, interrupt_event);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_18))
    icl_stats_inc ("amq_broker_agent_unnamed_18", &s_amq_broker_agent_unnamed_18_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_shutdown (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_SHUTDOWN))
    icl_stats_inc ("amq_broker_agent_shutdown", &s_amq_broker_agent_shutdown_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{


#define self tcb->amq_broker

        {
//  Tell amq_server_agent to close master socket
amq_server_agent_shutdown (self->agent_thread);
//  TODO: Shutdown any peerings or other objects that would malfunction
//  Start graceful shutdown sequence
smt_thread_set_next_event (thread, waiting_for_shutdown_event);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT)  ||  defined (BASE_STATS_AMQ_BROKER_AGENT_UNNAMED_20))
    icl_stats_inc ("amq_broker_agent_unnamed_20", &s_amq_broker_agent_unnamed_20_stats);
#endif        
#define tcb ((amq_broker_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

