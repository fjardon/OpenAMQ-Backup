/*---------------------------------------------------------------------------
    amq_server_channel_agent.c - functions for amq_server_channel_agent.

    Generated from amq_server_channel_agent.smt by smt_gen.gsl using GSL/4.

    
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
#include "amq_server_channel_agent.h"

#define class_main_state                           1
#define class_shutting_down_state                  2

#define destroy_m ((amq_server_channel_agent_destroy_t *) thread->method->data)

#define flow_m ((amq_server_channel_agent_flow_t *) thread->method->data)

#define consume_m ((amq_server_channel_agent_consume_t *) thread->method->data)

#define ack_m ((amq_server_channel_agent_ack_t *) thread->method->data)

#define cancel_m ((amq_server_channel_agent_cancel_t *) thread->method->data)

enum {
    shutdown_event                                 = 1,
    destroy_m_event                                = 2,
    cancel_m_event                                 = 3,
    flow_m_event                                   = 4,
    consume_m_event                                = 5,
    ack_m_event                                    = 6,
};

#define laststate                                  2
#define lastevent                                  6
#define lastplace                                  15

#define amq_server_channel_agent_agent_name        "Amq-Server-Channel-Agent"

#define class_thread_name                          "Class"

#define main_state_name                            "Main"
#define shutting_down_state_name                   "Shutting-Down"

#define shutdown_event_name                        "Shutdown"
#define destroy_m_event_name                       "Destroy-M"
#define cancel_m_event_name                        "Cancel-M"
#define flow_m_event_name                          "Flow-M"
#define consume_m_event_name                       "Consume-M"
#define ack_m_event_name                           "Ack-M"

#define destroy_action_name                        "Destroy"
#define free_action_name                           "Free"
#define unnamed_3_action_name                      "Unnamed-3"
#define cancel_action_name                         "Cancel"
#define unnamed_5_action_name                      "Unnamed-5"
#define unnamed_6_action_name                      "Unnamed-6"
#define flow_action_name                           "Flow"
#define unnamed_8_action_name                      "Unnamed-8"
#define consume_action_name                        "Consume"
#define unnamed_10_action_name                     "Unnamed-10"
#define ack_action_name                            "Ack"
#define unnamed_12_action_name                     "Unnamed-12"
#define unnamed_13_action_name                     "Unnamed-13"

#define the_next_event                             thread->_next_event
#define exception_raised                           thread->_exception_raised

typedef struct
  {
    char *         file;
    size_t         line;
  }
amq_server_channel_agent_destroy_t;

typedef struct
  {
    Bool           active;
  }
amq_server_channel_agent_flow_t;

typedef struct
  {
    amq_queue_t *  queue;
    amq_server_method_t *  method;
  }
amq_server_channel_agent_consume_t;

typedef struct
  {
    int64_t        delivery_tag;
    Bool           multiple;
  }
amq_server_channel_agent_ack_t;

typedef struct
  {
    char *         tag;
    Bool           sync;
    Bool           nowait;
  }
amq_server_channel_agent_cancel_t;

static icl_cache_t
    *s_class_context_cache = NULL;

typedef struct {
    int
        links;

        amq_server_channel_t
            *amq_server_channel;
    
} amq_server_channel_agent_class_context_t;

static icl_cache_t
    *s_destroy_cache = NULL;
static icl_cache_t
    *s_flow_cache = NULL;
static icl_cache_t
    *s_consume_cache = NULL;
static icl_cache_t
    *s_ack_cache = NULL;
static icl_cache_t
    *s_cancel_cache = NULL;

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
    cancel_m_event_name,
    flow_m_event_name,
    consume_m_event_name,
    ack_m_event_name
};

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT)   ||  defined (BASE_TRACE)  || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT)   ||  defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
static const char *action_name [] = {
    "<NULL>",
    destroy_action_name,
    free_action_name,
    unnamed_3_action_name,
    cancel_action_name,
    unnamed_5_action_name,
    unnamed_6_action_name,
    flow_action_name,
    unnamed_8_action_name,
    consume_action_name,
    unnamed_10_action_name,
    ack_action_name,
    unnamed_12_action_name,
    unnamed_13_action_name
};
#endif

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
static Bool
    s_animate = FALSE;
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_DESTROY))
static icl_stats_t *s_amq_server_channel_agent_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_FREE))
static icl_stats_t *s_amq_server_channel_agent_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_3))
static icl_stats_t *s_amq_server_channel_agent_unnamed_3_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_CANCEL))
static icl_stats_t *s_amq_server_channel_agent_cancel_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_5))
static icl_stats_t *s_amq_server_channel_agent_unnamed_5_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_6))
static icl_stats_t *s_amq_server_channel_agent_unnamed_6_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_FLOW))
static icl_stats_t *s_amq_server_channel_agent_flow_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_8))
static icl_stats_t *s_amq_server_channel_agent_unnamed_8_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_CONSUME))
static icl_stats_t *s_amq_server_channel_agent_consume_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_10))
static icl_stats_t *s_amq_server_channel_agent_unnamed_10_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_ACK))
static icl_stats_t *s_amq_server_channel_agent_ack_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_12))
static icl_stats_t *s_amq_server_channel_agent_unnamed_12_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_13))
static icl_stats_t *s_amq_server_channel_agent_unnamed_13_stats = NULL;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//  Function prototypes                                                        

static int    amq_server_channel_agent_manager  (smt_thread_t **thread);
static int    amq_server_channel_agent_catcher  (smt_thread_t *thread);
static int    amq_server_channel_agent_class_destroy  (smt_thread_t *thread);
static void   find_thread_state_next_state    (int          *thread_type,
                                               smt_state_t  *state_id,
                                               smt_event_t  *event_id,
                                               smt_state_t  *nextstate_id,
                                               smt_thread_t *thread);
static void   report_unrecognised_event_error (smt_thread_t *thread);
static void   report_state_machine_error      (smt_thread_t *thread);

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
static void   animate_start_new_event         (smt_thread_t *thread,
                                               smt_event_t  saveevent_id);
static void   animate_action                  (smt_thread_t *thread_id,
                                               int          action_id);
static int    find_thread_type                (smt_place_t  place);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT)   ||  defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
static void   s_dump                          (icl_os_thread_t apr_os_thread,
                                               apr_time_t      time,
                                               qbyte           info);

#endif

static int    action_destroy                  (smt_thread_t *thread);
static int    action_free                     (smt_thread_t *thread);
static int    action_unnamed_3                (smt_thread_t *thread);
static int    action_cancel                   (smt_thread_t *thread);
static int    action_unnamed_5                (smt_thread_t *thread);
static int    action_unnamed_6                (smt_thread_t *thread);
static int    action_flow                     (smt_thread_t *thread);
static int    action_unnamed_8                (smt_thread_t *thread);
static int    action_consume                  (smt_thread_t *thread);
static int    action_unnamed_10               (smt_thread_t *thread);
static int    action_ack                      (smt_thread_t *thread);
static int    action_unnamed_12               (smt_thread_t *thread);
static int    action_unnamed_13               (smt_thread_t *thread);
static int
amq_server_channel_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line);
int
amq_server_channel_agent_destroy_destructor (void *data);
static int
amq_server_channel_agent_flow_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    Bool           active);
int
amq_server_channel_agent_flow_destructor (void *data);
static int
amq_server_channel_agent_consume_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_queue_t *  queue,
    amq_server_method_t *  method);
int
amq_server_channel_agent_consume_destructor (void *data);
static int
amq_server_channel_agent_ack_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    int64_t        delivery_tag,
    Bool           multiple);
int
amq_server_channel_agent_ack_destructor (void *data);
static int
amq_server_channel_agent_cancel_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         tag,
    Bool           sync,
    Bool           nowait);
int
amq_server_channel_agent_cancel_destructor (void *data);
//  Function definitions                                                       

static int
amq_server_channel_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line)
{
    int
        rc = 0;
    amq_server_channel_agent_destroy_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_destroy_cache);
    _message->file                      = file;
    _message->line                      = line;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_server_channel_agent_destroy_destructor);
    
    return rc;
}

int
amq_server_channel_agent_destroy_destructor (void *data)
{
    int
        rc = 0;
char * file;
size_t line;

    file = ((amq_server_channel_agent_destroy_t *) data)-> file;
    line = ((amq_server_channel_agent_destroy_t *) data)-> line;


    icl_mem_free (data);
    return rc;
}


static int
amq_server_channel_agent_flow_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    Bool           active)
{
    int
        rc = 0;
    amq_server_channel_agent_flow_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_flow_cache);
    _message->active                    = active;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_server_channel_agent_flow_destructor);
    
    return rc;
}

int
amq_server_channel_agent_flow_destructor (void *data)
{
    int
        rc = 0;
Bool active;

    active = ((amq_server_channel_agent_flow_t *) data)-> active;


    icl_mem_free (data);
    return rc;
}


static int
amq_server_channel_agent_consume_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_queue_t *  queue,
    amq_server_method_t *  method)
{
    int
        rc = 0;
    amq_server_channel_agent_consume_t
        *_message;
        
    //  Possess code for consume
    

    queue  = amq_queue_link (queue);
    method = amq_server_method_link (method);
    
    

    _message = icl_mem_cache_alloc (s_consume_cache);
    _message->queue                     = queue;
    _message->method                    = method;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_server_channel_agent_consume_destructor);
    
    return rc;
}

int
amq_server_channel_agent_consume_destructor (void *data)
{
    int
        rc = 0;
amq_queue_t * queue;
amq_server_method_t * method;

    queue = ((amq_server_channel_agent_consume_t *) data)-> queue;
    method = ((amq_server_channel_agent_consume_t *) data)-> method;



    amq_queue_unlink (&queue);
    amq_server_method_unlink (&method);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_server_channel_agent_ack_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    int64_t        delivery_tag,
    Bool           multiple)
{
    int
        rc = 0;
    amq_server_channel_agent_ack_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_ack_cache);
    _message->delivery_tag              = delivery_tag;
    _message->multiple                  = multiple;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_server_channel_agent_ack_destructor);
    
    return rc;
}

int
amq_server_channel_agent_ack_destructor (void *data)
{
    int
        rc = 0;
int64_t delivery_tag;
Bool multiple;

    delivery_tag = ((amq_server_channel_agent_ack_t *) data)-> delivery_tag;
    multiple = ((amq_server_channel_agent_ack_t *) data)-> multiple;


    icl_mem_free (data);
    return rc;
}


static int
amq_server_channel_agent_cancel_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         tag,
    Bool           sync,
    Bool           nowait)
{
    int
        rc = 0;
    amq_server_channel_agent_cancel_t
        *_message;
        
    //  Possess code for cancel
    

    tag = icl_mem_strdup (tag);
    
    

    _message = icl_mem_cache_alloc (s_cancel_cache);
    _message->tag                       = tag;
    _message->sync                      = sync;
    _message->nowait                    = nowait;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_server_channel_agent_cancel_destructor);
    
    return rc;
}

int
amq_server_channel_agent_cancel_destructor (void *data)
{
    int
        rc = 0;
char * tag;
Bool sync;
Bool nowait;

    tag = ((amq_server_channel_agent_cancel_t *) data)-> tag;
    sync = ((amq_server_channel_agent_cancel_t *) data)-> sync;
    nowait = ((amq_server_channel_agent_cancel_t *) data)-> nowait;



    icl_mem_free (tag);
    
    

    icl_mem_free (data);
    return rc;
}


int
amq_server_channel_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_server_channel_agent_manager);
        rc = amq_server_channel_agent_destroy_send (
                thread->reply_queue, destroy_m_event,
                file,
                line);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_server_channel_agent_flow (
    smt_thread_t * thread,
    Bool                  active)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_server_channel_agent_manager);
        rc = amq_server_channel_agent_flow_send (
                thread->reply_queue, flow_m_event,
                active);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_server_channel_agent_consume (
    smt_thread_t * thread,
    amq_queue_t *         queue,
    amq_server_method_t * method)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_server_channel_agent_manager);
        rc = amq_server_channel_agent_consume_send (
                thread->reply_queue, consume_m_event,
                queue,
                method);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_server_channel_agent_ack (
    smt_thread_t * thread,
    int64_t               delivery_tag,
    Bool                  multiple)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_server_channel_agent_manager);
        rc = amq_server_channel_agent_ack_send (
                thread->reply_queue, ack_m_event,
                delivery_tag,
                multiple);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_server_channel_agent_cancel (
    smt_thread_t * thread,
    char *                tag,
    Bool                  sync,
    Bool                  nowait)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_server_channel_agent_manager);
        rc = amq_server_channel_agent_cancel_send (
                thread->reply_queue, cancel_m_event,
                tag,
                sync,
                nowait);
    }
    else
        rc = -1;
        
    return rc;
}

void
amq_server_channel_agent_term (void)
{

}

int 
amq_server_channel_agent_init (void)
{
    int
        rc = SMT_OK;                    //  Return code

    s_class_context_cache = icl_cache_get (sizeof (amq_server_channel_agent_class_context_t));
    s_destroy_cache = icl_cache_get (sizeof (amq_server_channel_agent_destroy_t));
    s_flow_cache = icl_cache_get (sizeof (amq_server_channel_agent_flow_t));
    s_consume_cache = icl_cache_get (sizeof (amq_server_channel_agent_consume_t));
    s_ack_cache = icl_cache_get (sizeof (amq_server_channel_agent_ack_t));
    s_cancel_cache = icl_cache_get (sizeof (amq_server_channel_agent_cancel_t));

    //  Initialise basic stuff.
    smt_initialise ();
    
    {

    }
    icl_system_register (NULL, amq_server_channel_agent_term);
    
    return rc;
}

void
amq_server_channel_agent_animate (Bool animate)
{
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
    s_animate = animate;
#endif
}

smt_thread_t *
amq_server_channel_agent_class_thread_new (
    amq_server_channel_t * self)
{
    smt_thread_t
        *thread;

    thread = smt_thread_new (amq_server_channel_agent_manager,
                             amq_server_channel_agent_catcher,
                             amq_server_channel_agent_class_destroy);
                             

#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    thread->trace = icl_trace_new (ICL_TRACE_SIZE);
#endif

    if (thread) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
        thread->animate = s_animate;
        if (s_animate)
            icl_console_print ("%4lu> %-15s/%-15s <Created>",
                thread->id,
                "amq_server_channel_agent",
                class_thread_name);
#endif

        thread->place   = 1;
        thread->context = icl_mem_cache_alloc (s_class_context_cache);
        memset (thread->context, 0, sizeof (amq_server_channel_agent_class_context_t));
        ((amq_server_channel_agent_class_context_t *) thread->context)->links = 1;
        thread->event_name = event_name;
{
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)

        tcb->amq_server_channel = self;
    
#undef  tcb
}
    }
    return thread;
}


static int
amq_server_channel_agent_manager (smt_thread_t **thread_p)
{
    smt_thread_t
        *thread = *thread_p;
        
    int
        rc;
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))

    smt_event_t
        saveevent_id = SMT_NULL_EVENT;
#endif
        
    assert (thread->manager == amq_server_channel_agent_manager);
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
            case 4:
            case 10:
            case 15:
                thread->place = SMT_TERM_PLACE;
                break;
            case 7:
            case 5:
            case 6:
            case 8:
                thread->place = 2;
                break;
            case 14:
            case 13:
            case 3:
            case 12:
            case 11:
                thread->place = 9;
                break;
        }    
    else
    if (thread->module == 0) {
        if (thread->place == 1) { //                Class thread
            if (!thread->shutting_down) {
{
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)

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
        if (thread->place < 9)                  //  Main state
            thread->place = 2;
        else
            thread->place = 9;
    }

    switch (thread->place) {
        case 2:                         //  main state                          
{
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 3; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 4; break;
                case flow_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 5; break;
                case consume_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 6; break;
                case ack_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 7; break;
                case cancel_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 8; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
        case 9:                         //  shutting down state                 
{
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 10; break;
                case cancel_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 11; break;
                case flow_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 12; break;
                case consume_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 13; break;
                case ack_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 14; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 15; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
    }
                                  
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
    if (thread->animate && thread->module == 1)
        animate_start_new_event (thread, saveevent_id);
#endif

    switch (thread->place) {
        case 3:
        case 12:
        case 13:
        case 14:
        case 15:
            switch (thread->module) {
                case 1:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    if (thread->place == 15)
                        thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 10:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
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
        case 11:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
                    if (thread->animate)
                        animate_action (thread, 4);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
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

                case 3:                         //  After actions              
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
                    if (thread->animate)
                        animate_action (thread, 7);
#endif
                    rc = action_flow (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
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
        case 6:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
                    if (thread->animate)
                        animate_action (thread, 9);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
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
        case 7:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
                    if (thread->animate)
                        animate_action (thread, 11);
#endif
                    rc = action_ack (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
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
        case 8:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
                    if (thread->animate)
                        animate_action (thread, 4);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
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
amq_server_channel_agent_catcher (smt_thread_t *thread)
{
    return SMT_OK;
}


static int    
amq_server_channel_agent_class_destroy (smt_thread_t *thread)
{
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))
    if (thread->animate)
        icl_console_print ("%4lu> %-15s/%-15s <Destroyed>",
                  thread->id,
                  "amq_server_channel_agent",
                 class_thread_name);

#endif
    if (--((amq_server_channel_agent_class_context_t *) thread->context)->links == 0)
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
        if (thread->place < 9)
          {
            *state_id = 1;
            switch (thread->place) {
                case 3: *event_id = 1;   *nextstate_id = 2;   break;
                case 4: *event_id = 2;   break;
                case 5: *event_id = 4;   *nextstate_id = 1;   break;
                case 6: *event_id = 5;   *nextstate_id = 1;   break;
                case 7: *event_id = 6;   *nextstate_id = 1;   break;
                case 8: *event_id = 3;   *nextstate_id = 1;   break;
            }
          }
        else
          {
            *state_id = 2;
            switch (thread->place) {
                case 10: *event_id = 2;   break;
                case 11: *event_id = 3;   *nextstate_id = 2;   break;
                case 12: *event_id = 4;   *nextstate_id = 2;   break;
                case 13: *event_id = 5;   *nextstate_id = 2;   break;
                case 14: *event_id = 6;   *nextstate_id = 2;   break;
                case 15: *event_id = 1;   break;
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
    icl_console_print ("amq_server_channel_agent: Unrecognised event '%s' in '%s' thread number: %u, state: %s",
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

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_AGENT))

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
            "amq_server_channel_agent",
            thread_name [thread_type],
            state_name [state_id]);
  icl_console_print ("%4lu> %-15s/%-15s    (--) %-32s->%s",
            thread->id,
            "amq_server_channel_agent",
            thread_name [thread_type],
            event_name [event_id != SMT_NULL_EVENT ? event_id : saveevent_id],
            nextstate_id ? state_name [nextstate_id] : "");
}

static void
animate_action (smt_thread_t *thread, int action_id)
{
    icl_console_print ("%4lu> %-15s/%-15s           + %s",
              thread->id,
              "amq_server_channel_agent",
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_AGENT)     ||  defined (AMQ_SERVER_CHANNEL_AGENT_TRACE))
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
                                       "amq_server_channel_agent",
                                       action_name [action_id]);
    }
    else
    if (state_or_event_or_action > laststate) {
        event_id = state_or_event_or_action - laststate;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s    (--) %-32s",
                                       thread_id,
                                       "amq_server_channel_agent",
                                       event_name [event_id]);
    }
    else {
        state_id = state_or_event_or_action;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s %s:",
                                       thread_id,
                                       "amq_server_channel_agent",
                                       state_id ? state_name [state_id] : "<Destroyed>");
    }
}

#endif
static int
action_destroy (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_DESTROY))
    icl_stats_inc ("amq_server_channel_agent_destroy", &s_amq_server_channel_agent_destroy_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
{


#define self tcb->amq_server_channel
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_server_connection_unlink (&self->connection);

{
amq_consumer_t
    *consumer;                      //  Consumer in index table

//  We destroy consumers by asking the respective queues
while ((consumer = amq_consumer_by_channel_pop (self->consumer_list))) {
    if (amq_queue_cancel (consumer->queue, consumer, FALSE, TRUE))
        //  If the async cancel failed, destroy the consumer ourselves
        amq_consumer_destroy (&consumer);
}
amq_connection_destroy (&self->mgt_connection);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_FREE))
    icl_stats_inc ("amq_server_channel_agent_free", &s_amq_server_channel_agent_free_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
{


#define self tcb->amq_server_channel
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_server_channel object");
    amq_server_channel_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_server_channel_free (self);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_3))
    icl_stats_inc ("amq_server_channel_agent_unnamed_3", &s_amq_server_channel_agent_unnamed_3_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_CANCEL))
    icl_stats_inc ("amq_server_channel_agent_cancel", &s_amq_server_channel_agent_cancel_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
{


#define self tcb->amq_server_channel
char *
    tag;
Bool
    sync;
Bool
    nowait;

    tag = cancel_m->tag;
    sync = cancel_m->sync;
    nowait = cancel_m->nowait;
        {
amq_consumer_t
    *consumer = NULL;               //  Consumer reference
amq_queue_t
    *queue;

consumer = amq_consumer_table_search (self->connection->consumer_table, tag);
if (consumer) {
    amq_consumer_by_channel_remove (consumer);
    if (sync) {
        //  Pass to queue to do the final honours
        queue = amq_queue_link (consumer->queue);
        if (queue) {
            //  Send request to queue, but if queue is just dying, this
            //  can fail, and leave a dangling consumer.
            if (amq_queue_cancel (queue, consumer, TRUE, nowait))
                amq_consumer_unlink (&consumer);
            amq_queue_unlink (&queue);
        }
        else
            amq_consumer_unlink (&consumer);
    }
    else {
        //  Consumer must have been removed from its per-queue list
        assert (consumer->by_queue_next == consumer);
        amq_consumer_destroy (&consumer);
    }
}
else
if (sync)
    amq_server_agent_basic_cancel_ok (self->connection->thread, self->number, tag);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_5 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_5))
    icl_stats_inc ("amq_server_channel_agent_unnamed_5", &s_amq_server_channel_agent_unnamed_5_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_6 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_6))
    icl_stats_inc ("amq_server_channel_agent_unnamed_6", &s_amq_server_channel_agent_unnamed_6_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_flow (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_FLOW))
    icl_stats_inc ("amq_server_channel_agent_flow", &s_amq_server_channel_agent_flow_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
{


#define self tcb->amq_server_channel
Bool
    active;

    active = flow_m->active;
        {
amq_consumer_t
    *consumer;                      //  Consumer object reference

self->active = active;
consumer = amq_consumer_by_channel_first (self->consumer_list);
while (consumer) {
    consumer->paused = !active;
    consumer->queue->feed_on = active;
    if (active)
        amq_queue_dispatch (consumer->queue);
    consumer = amq_consumer_by_channel_next (&consumer);
}
amq_server_agent_channel_flow_ok (self->connection->thread, self->number, self->active);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_8))
    icl_stats_inc ("amq_server_channel_agent_unnamed_8", &s_amq_server_channel_agent_unnamed_8_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_CONSUME))
    icl_stats_inc ("amq_server_channel_agent_consume", &s_amq_server_channel_agent_consume_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
{


#define self tcb->amq_server_channel
amq_queue_t *
    queue;
amq_server_method_t *
    method;

    queue = consume_m->queue;
    method = consume_m->method;
        {
amq_consumer_t
    *consumer = NULL;
Bool
    nowait = method->payload.basic_consume.nowait;

if (strused (method->payload.basic_consume.consumer_tag))
    consumer = amq_consumer_table_search (
        self->connection->consumer_table, method->payload.basic_consume.consumer_tag);

//  If consumer tag specified, ignore re-consume of same tag on same queue
if (consumer) {
    if (consumer->queue == queue) {
        if (!nowait)
            amq_server_agent_basic_consume_ok (
                self->connection->thread, self->number, consumer->tag);
    }
    else
        amq_server_channel_error (self, ASL_NOT_ALLOWED, "Consumer tag used on other queue",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_CONSUME);
}
else {
    consumer = amq_consumer_new (self->connection, self, queue, method);
    if (consumer) {
        amq_consumer_by_channel_queue (self->consumer_list, consumer);
        if (queue->exclusive)
            self->credit = amq_server_config_private_credit (amq_server_config);
        else
            self->credit = amq_server_config_shared_credit (amq_server_config);
        if (self->credit == 0)
            self->credit = 1;
        amq_queue_consume (queue, consumer, self->active, nowait);
    }
    else {
        amq_server_channel_error (self, ASL_RESOURCE_ERROR, "Unable to create consumer",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_CONSUME);
        smt_log_print (amq_broker->alert_log, "W: cannot create consumer - too many consumers?");
    }
}
amq_consumer_unlink (&consumer);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_10))
    icl_stats_inc ("amq_server_channel_agent_unnamed_10", &s_amq_server_channel_agent_unnamed_10_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_ack (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_ACK))
    icl_stats_inc ("amq_server_channel_agent_ack", &s_amq_server_channel_agent_ack_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
{


#define self tcb->amq_server_channel
int64_t
    delivery_tag;
Bool
    multiple;

    delivery_tag = ack_m->delivery_tag;
    multiple = ack_m->multiple;
        {
amq_consumer_t
    *consumer;                      //  Consumer object reference

consumer = amq_consumer_by_channel_first (self->consumer_list);
while (consumer) {
    //  Get queue to do work on consumer so it's synchronized
    amq_queue_consumer_ack (consumer->queue, consumer);
    consumer = amq_consumer_by_channel_next (&consumer);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_12))
    icl_stats_inc ("amq_server_channel_agent_unnamed_12", &s_amq_server_channel_agent_unnamed_12_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_13 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_AGENT_UNNAMED_13))
    icl_stats_inc ("amq_server_channel_agent_unnamed_13", &s_amq_server_channel_agent_unnamed_13_stats);
#endif        
#define tcb ((amq_server_channel_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

