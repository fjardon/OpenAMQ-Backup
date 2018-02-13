/*---------------------------------------------------------------------------
    amq_console_config_agent.c - functions for amq_console_config_agent.

    Generated from amq_console_config_agent.smt by smt_gen.gsl using GSL/4.

    
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
#include "amq_console_config_agent.h"

#define class_main_state                           1
#define class_shutting_down_state                  2

#define destroy_m ((amq_console_config_agent_destroy_t *) thread->method->data)

#define inspect_m ((amq_console_config_agent_inspect_t *) thread->method->data)

#define modify_m ((amq_console_config_agent_modify_t *) thread->method->data)

#define method_m ((amq_console_config_agent_method_t *) thread->method->data)

enum {
    shutdown_event                                 = 1,
    destroy_m_event                                = 2,
    inspect_m_event                                = 3,
    modify_m_event                                 = 4,
    method_m_event                                 = 5,
};

#define laststate                                  2
#define lastevent                                  5
#define lastplace                                  13

#define amq_console_config_agent_agent_name        "Amq-Console-Config-Agent"

#define class_thread_name                          "Class"

#define main_state_name                            "Main"
#define shutting_down_state_name                   "Shutting-Down"

#define shutdown_event_name                        "Shutdown"
#define destroy_m_event_name                       "Destroy-M"
#define inspect_m_event_name                       "Inspect-M"
#define modify_m_event_name                        "Modify-M"
#define method_m_event_name                        "Method-M"

#define destroy_action_name                        "Destroy"
#define free_action_name                           "Free"
#define unnamed_3_action_name                      "Unnamed-3"
#define unnamed_4_action_name                      "Unnamed-4"
#define inspect_action_name                        "Inspect"
#define unnamed_6_action_name                      "Unnamed-6"
#define modify_action_name                         "Modify"
#define unnamed_8_action_name                      "Unnamed-8"
#define method_action_name                         "Method"
#define unnamed_10_action_name                     "Unnamed-10"

#define the_next_event                             thread->_next_event
#define exception_raised                           thread->_exception_raised

typedef struct
  {
    char *         file;
    size_t         line;
  }
amq_console_config_agent_destroy_t;

typedef struct
  {
    amq_content_basic_t *  request;
  }
amq_console_config_agent_inspect_t;

typedef struct
  {
    amq_content_basic_t *  request;
    asl_field_list_t *  fields;
  }
amq_console_config_agent_modify_t;

typedef struct
  {
    char *         method_name;
    amq_content_basic_t *  request;
    asl_field_list_t *  fields;
  }
amq_console_config_agent_method_t;

static icl_cache_t
    *s_class_context_cache = NULL;

typedef struct {
    int
        links;

        amq_console_config_t
            *amq_console_config;
    
} amq_console_config_agent_class_context_t;

static icl_cache_t
    *s_destroy_cache = NULL;
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
    inspect_m_event_name,
    modify_m_event_name,
    method_m_event_name
};

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT)   ||  defined (BASE_TRACE)  || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT)   ||  defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
static const char *action_name [] = {
    "<NULL>",
    destroy_action_name,
    free_action_name,
    unnamed_3_action_name,
    unnamed_4_action_name,
    inspect_action_name,
    unnamed_6_action_name,
    modify_action_name,
    unnamed_8_action_name,
    method_action_name,
    unnamed_10_action_name
};
#endif

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
static Bool
    s_animate = FALSE;
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_DESTROY))
static icl_stats_t *s_amq_console_config_agent_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_FREE))
static icl_stats_t *s_amq_console_config_agent_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_UNNAMED_3))
static icl_stats_t *s_amq_console_config_agent_unnamed_3_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_UNNAMED_4))
static icl_stats_t *s_amq_console_config_agent_unnamed_4_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_INSPECT))
static icl_stats_t *s_amq_console_config_agent_inspect_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_UNNAMED_6))
static icl_stats_t *s_amq_console_config_agent_unnamed_6_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_MODIFY))
static icl_stats_t *s_amq_console_config_agent_modify_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_UNNAMED_8))
static icl_stats_t *s_amq_console_config_agent_unnamed_8_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_METHOD))
static icl_stats_t *s_amq_console_config_agent_method_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_UNNAMED_10))
static icl_stats_t *s_amq_console_config_agent_unnamed_10_stats = NULL;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//  Function prototypes                                                        

static int    amq_console_config_agent_manager  (smt_thread_t **thread);
static int    amq_console_config_agent_catcher  (smt_thread_t *thread);
static int    amq_console_config_agent_class_destroy  (smt_thread_t *thread);
static void   find_thread_state_next_state    (int          *thread_type,
                                               smt_state_t  *state_id,
                                               smt_event_t  *event_id,
                                               smt_state_t  *nextstate_id,
                                               smt_thread_t *thread);
static void   report_unrecognised_event_error (smt_thread_t *thread);
static void   report_state_machine_error      (smt_thread_t *thread);

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
static void   animate_start_new_event         (smt_thread_t *thread,
                                               smt_event_t  saveevent_id);
static void   animate_action                  (smt_thread_t *thread_id,
                                               int          action_id);
static int    find_thread_type                (smt_place_t  place);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT)   ||  defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
static void   s_dump                          (icl_os_thread_t apr_os_thread,
                                               apr_time_t      time,
                                               qbyte           info);

#endif

static int    action_destroy                  (smt_thread_t *thread);
static int    action_free                     (smt_thread_t *thread);
static int    action_unnamed_3                (smt_thread_t *thread);
static int    action_unnamed_4                (smt_thread_t *thread);
static int    action_inspect                  (smt_thread_t *thread);
static int    action_unnamed_6                (smt_thread_t *thread);
static int    action_modify                   (smt_thread_t *thread);
static int    action_unnamed_8                (smt_thread_t *thread);
static int    action_method                   (smt_thread_t *thread);
static int    action_unnamed_10               (smt_thread_t *thread);
static int
amq_console_config_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line);
int
amq_console_config_agent_destroy_destructor (void *data);
static int
amq_console_config_agent_inspect_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request);
int
amq_console_config_agent_inspect_destructor (void *data);
static int
amq_console_config_agent_modify_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields);
int
amq_console_config_agent_modify_destructor (void *data);
static int
amq_console_config_agent_method_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         method_name,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields);
int
amq_console_config_agent_method_destructor (void *data);
//  Function definitions                                                       

static int
amq_console_config_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line)
{
    int
        rc = 0;
    amq_console_config_agent_destroy_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_destroy_cache);
    _message->file                      = file;
    _message->line                      = line;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_console_config_agent_destroy_destructor);
    
    return rc;
}

int
amq_console_config_agent_destroy_destructor (void *data)
{
    int
        rc = 0;
char * file;
size_t line;

    file = ((amq_console_config_agent_destroy_t *) data)-> file;
    line = ((amq_console_config_agent_destroy_t *) data)-> line;


    icl_mem_free (data);
    return rc;
}


static int
amq_console_config_agent_inspect_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request)
{
    int
        rc = 0;
    amq_console_config_agent_inspect_t
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
                          amq_console_config_agent_inspect_destructor);
    
    return rc;
}

int
amq_console_config_agent_inspect_destructor (void *data)
{
    int
        rc = 0;
amq_content_basic_t * request;

    request = ((amq_console_config_agent_inspect_t *) data)-> request;



    amq_content_basic_unlink (&request);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_console_config_agent_modify_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields)
{
    int
        rc = 0;
    amq_console_config_agent_modify_t
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
                          amq_console_config_agent_modify_destructor);
    
    return rc;
}

int
amq_console_config_agent_modify_destructor (void *data)
{
    int
        rc = 0;
amq_content_basic_t * request;
asl_field_list_t * fields;

    request = ((amq_console_config_agent_modify_t *) data)-> request;
    fields = ((amq_console_config_agent_modify_t *) data)-> fields;



    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_console_config_agent_method_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         method_name,
    amq_content_basic_t *  request,
    asl_field_list_t *  fields)
{
    int
        rc = 0;
    amq_console_config_agent_method_t
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
                          amq_console_config_agent_method_destructor);
    
    return rc;
}

int
amq_console_config_agent_method_destructor (void *data)
{
    int
        rc = 0;
char * method_name;
amq_content_basic_t * request;
asl_field_list_t * fields;

    method_name = ((amq_console_config_agent_method_t *) data)-> method_name;
    request = ((amq_console_config_agent_method_t *) data)-> request;
    fields = ((amq_console_config_agent_method_t *) data)-> fields;



    icl_mem_free (method_name);
    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    
    

    icl_mem_free (data);
    return rc;
}


int
amq_console_config_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_console_config_agent_manager);
        rc = amq_console_config_agent_destroy_send (
                thread->reply_queue, destroy_m_event,
                file,
                line);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_console_config_agent_inspect (
    smt_thread_t * thread,
    amq_content_basic_t * request)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_console_config_agent_manager);
        rc = amq_console_config_agent_inspect_send (
                thread->reply_queue, inspect_m_event,
                request);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_console_config_agent_modify (
    smt_thread_t * thread,
    amq_content_basic_t * request,
    asl_field_list_t *    fields)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_console_config_agent_manager);
        rc = amq_console_config_agent_modify_send (
                thread->reply_queue, modify_m_event,
                request,
                fields);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_console_config_agent_method (
    smt_thread_t * thread,
    char *                method_name,
    amq_content_basic_t * request,
    asl_field_list_t *    fields)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_console_config_agent_manager);
        rc = amq_console_config_agent_method_send (
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
amq_console_config_agent_term (void)
{

}

int 
amq_console_config_agent_init (void)
{
    int
        rc = SMT_OK;                    //  Return code

    s_class_context_cache = icl_cache_get (sizeof (amq_console_config_agent_class_context_t));
    s_destroy_cache = icl_cache_get (sizeof (amq_console_config_agent_destroy_t));
    s_inspect_cache = icl_cache_get (sizeof (amq_console_config_agent_inspect_t));
    s_modify_cache = icl_cache_get (sizeof (amq_console_config_agent_modify_t));
    s_method_cache = icl_cache_get (sizeof (amq_console_config_agent_method_t));

    //  Initialise basic stuff.
    smt_initialise ();
    
    {

    }
    icl_system_register (NULL, amq_console_config_agent_term);
    
    return rc;
}

void
amq_console_config_agent_animate (Bool animate)
{
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
    s_animate = animate;
#endif
}

smt_thread_t *
amq_console_config_agent_class_thread_new (
    amq_console_config_t * self)
{
    smt_thread_t
        *thread;

    thread = smt_thread_new (amq_console_config_agent_manager,
                             amq_console_config_agent_catcher,
                             amq_console_config_agent_class_destroy);
                             

#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    thread->trace = icl_trace_new (ICL_TRACE_SIZE);
#endif

    if (thread) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
        thread->animate = s_animate;
        if (s_animate)
            icl_console_print ("%4lu> %-15s/%-15s <Created>",
                thread->id,
                "amq_console_config_agent",
                class_thread_name);
#endif

        thread->place   = 1;
        thread->context = icl_mem_cache_alloc (s_class_context_cache);
        memset (thread->context, 0, sizeof (amq_console_config_agent_class_context_t));
        ((amq_console_config_agent_class_context_t *) thread->context)->links = 1;
        thread->event_name = event_name;
{
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)

        tcb->amq_console_config = self;
    
#undef  tcb
}
    }
    return thread;
}


static int
amq_console_config_agent_manager (smt_thread_t **thread_p)
{
    smt_thread_t
        *thread = *thread_p;
        
    int
        rc;
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))

    smt_event_t
        saveevent_id = SMT_NULL_EVENT;
#endif
        
    assert (thread->manager == amq_console_config_agent_manager);
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
            case 13:
            case 9:
            case 4:
                thread->place = SMT_TERM_PLACE;
                break;
            case 6:
            case 7:
            case 5:
                thread->place = 2;
                break;
            case 12:
            case 3:
            case 11:
            case 10:
                thread->place = 8;
                break;
        }    
    else
    if (thread->module == 0) {
        if (thread->place == 1) { //                Class thread
            if (!thread->shutting_down) {
{
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)

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
        if (thread->place < 8)                  //  Main state
            thread->place = 2;
        else
            thread->place = 8;
    }

    switch (thread->place) {
        case 2:                         //  main state                          
{
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 3; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 4; break;
                case inspect_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 5; break;
                case modify_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 6; break;
                case method_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 7; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
        case 8:                         //  shutting down state                 
{
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 9; break;
                case inspect_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 10; break;
                case modify_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 11; break;
                case method_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 12; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 13; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
    }
                                  
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
    if (thread->animate && thread->module == 1)
        animate_start_new_event (thread, saveevent_id);
#endif

    switch (thread->place) {
        case 3:
        case 10:
        case 11:
        case 12:
        case 13:
            switch (thread->module) {
                case 1:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    if (thread->place == 13)
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
                    if (thread->animate)
                        animate_action (thread, 5);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
                    if (thread->animate)
                        animate_action (thread, 7);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
                    if (thread->animate)
                        animate_action (thread, 9);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
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
amq_console_config_agent_catcher (smt_thread_t *thread)
{
    return SMT_OK;
}


static int    
amq_console_config_agent_class_destroy (smt_thread_t *thread)
{
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))
    if (thread->animate)
        icl_console_print ("%4lu> %-15s/%-15s <Destroyed>",
                  thread->id,
                  "amq_console_config_agent",
                 class_thread_name);

#endif
    if (--((amq_console_config_agent_class_context_t *) thread->context)->links == 0)
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
        if (thread->place < 8)
          {
            *state_id = 1;
            switch (thread->place) {
                case 3: *event_id = 1;   *nextstate_id = 2;   break;
                case 4: *event_id = 2;   break;
                case 5: *event_id = 3;   *nextstate_id = 1;   break;
                case 6: *event_id = 4;   *nextstate_id = 1;   break;
                case 7: *event_id = 5;   *nextstate_id = 1;   break;
            }
          }
        else
          {
            *state_id = 2;
            switch (thread->place) {
                case 9: *event_id = 2;   break;
                case 10: *event_id = 3;   *nextstate_id = 2;   break;
                case 11: *event_id = 4;   *nextstate_id = 2;   break;
                case 12: *event_id = 5;   *nextstate_id = 2;   break;
                case 13: *event_id = 1;   break;
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
    icl_console_print ("amq_console_config_agent: Unrecognised event '%s' in '%s' thread number: %u, state: %s",
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

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_CONFIG_AGENT))

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
            "amq_console_config_agent",
            thread_name [thread_type],
            state_name [state_id]);
  icl_console_print ("%4lu> %-15s/%-15s    (--) %-32s->%s",
            thread->id,
            "amq_console_config_agent",
            thread_name [thread_type],
            event_name [event_id != SMT_NULL_EVENT ? event_id : saveevent_id],
            nextstate_id ? state_name [nextstate_id] : "");
}

static void
animate_action (smt_thread_t *thread, int action_id)
{
    icl_console_print ("%4lu> %-15s/%-15s           + %s",
              thread->id,
              "amq_console_config_agent",
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_AGENT)     ||  defined (AMQ_CONSOLE_CONFIG_AGENT_TRACE))
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
                                       "amq_console_config_agent",
                                       action_name [action_id]);
    }
    else
    if (state_or_event_or_action > laststate) {
        event_id = state_or_event_or_action - laststate;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s    (--) %-32s",
                                       thread_id,
                                       "amq_console_config_agent",
                                       event_name [event_id]);
    }
    else {
        state_id = state_or_event_or_action;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s %s:",
                                       thread_id,
                                       "amq_console_config_agent",
                                       state_id ? state_name [state_id] : "<Destroyed>");
    }
}

#endif
static int
action_destroy (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_DESTROY))
    icl_stats_inc ("amq_console_config_agent_destroy", &s_amq_console_config_agent_destroy_stats);
#endif        
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console_config
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_FREE))
    icl_stats_inc ("amq_console_config_agent_free", &s_amq_console_config_agent_free_stats);
#endif        
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console_config
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_console_config object");
    amq_console_config_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_console_config_free (self);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_UNNAMED_3))
    icl_stats_inc ("amq_console_config_agent_unnamed_3", &s_amq_console_config_agent_unnamed_3_stats);
#endif        
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_UNNAMED_4))
    icl_stats_inc ("amq_console_config_agent_unnamed_4", &s_amq_console_config_agent_unnamed_4_stats);
#endif        
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_INSPECT))
    icl_stats_inc ("amq_console_config_agent_inspect", &s_amq_console_config_agent_inspect_stats);
#endif        
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console_config
amq_content_basic_t *
    request;

    request = inspect_m->request;
        {
asl_field_list_t
    *fields;                        //  Properties of object
icl_shortstr_t
    field_value;

fields = asl_field_list_new (NULL);
icl_shortstr_cpy (field_value, amq_server_config->filename);
asl_field_new_string (fields, "name", field_value);
icl_shortstr_cpy (field_value, amq_server_config_port (amq_server_config));
asl_field_new_string (fields, "port", field_value);
icl_shortstr_cpy (field_value, amq_server_config_listen (amq_server_config));
asl_field_new_string (fields, "listen", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_queue_timeout (amq_server_config));
asl_field_new_string (fields, "queue_timeout", field_value);
icl_shortstr_cpy (field_value, amq_server_config_vhost (amq_server_config));
asl_field_new_string (fields, "vhost", field_value);
icl_shortstr_cpy (field_value, amq_server_config_user (amq_server_config));
asl_field_new_string (fields, "user", field_value);
icl_shortstr_cpy (field_value, amq_server_config_group (amq_server_config));
asl_field_new_string (fields, "group", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_monitor (amq_server_config));
asl_field_new_string (fields, "monitor", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_dump_state (amq_server_config));
asl_field_new_string (fields, "dump_state", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_record_stats (amq_server_config));
asl_field_new_string (fields, "record_stats", field_value);
icl_shortstr_cpy (field_value, amq_server_config_log_path (amq_server_config));
asl_field_new_string (fields, "log_path", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_keep_logs (amq_server_config));
asl_field_new_string (fields, "keep_logs", field_value);
icl_shortstr_cpy (field_value, amq_server_config_archive_path (amq_server_config));
asl_field_new_string (fields, "archive_path", field_value);
icl_shortstr_cpy (field_value, amq_server_config_archive_cmd (amq_server_config));
asl_field_new_string (fields, "archive_cmd", field_value);
icl_shortstr_cpy (field_value, amq_server_config_alert_log (amq_server_config));
asl_field_new_string (fields, "alert_log", field_value);
icl_shortstr_cpy (field_value, amq_server_config_daily_log (amq_server_config));
asl_field_new_string (fields, "daily_log", field_value);
icl_shortstr_cpy (field_value, amq_server_config_debug_log (amq_server_config));
asl_field_new_string (fields, "debug_log", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_route (amq_server_config));
asl_field_new_string (fields, "debug_route", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_queue (amq_server_config));
asl_field_new_string (fields, "debug_queue", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_peering (amq_server_config));
asl_field_new_string (fields, "debug_peering", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_console (amq_server_config));
asl_field_new_string (fields, "debug_console", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_trace (amq_server_config));
asl_field_new_string (fields, "trace", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_heartbeat (amq_server_config));
asl_field_new_string (fields, "heartbeat", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_setup_timeout (amq_server_config));
asl_field_new_string (fields, "setup_timeout", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_close_timeout (amq_server_config));
asl_field_new_string (fields, "close_timeout", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_accept_retry_timeout (amq_server_config));
asl_field_new_string (fields, "accept_retry_timeout", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_polling_threads (amq_server_config));
asl_field_new_string (fields, "polling_threads", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_working_threads (amq_server_config));
asl_field_new_string (fields, "working_threads", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_tcp_nodelay (amq_server_config));
asl_field_new_string (fields, "tcp_nodelay", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_tcp_rcvbuf (amq_server_config));
asl_field_new_string (fields, "tcp_rcvbuf", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_tcp_sndbuf (amq_server_config));
asl_field_new_string (fields, "tcp_sndbuf", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_frame_max (amq_server_config));
asl_field_new_string (fields, "frame_max", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_direct (amq_server_config));
asl_field_new_string (fields, "direct", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_private_credit (amq_server_config));
asl_field_new_string (fields, "private_credit", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_shared_credit (amq_server_config));
asl_field_new_string (fields, "shared_credit", field_value);
icl_shortstr_cpy (field_value, amq_server_config_backup (amq_server_config));
asl_field_new_string (fields, "backup", field_value);
icl_shortstr_cpy (field_value, amq_server_config_primary (amq_server_config));
asl_field_new_string (fields, "primary", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_failover_timeout (amq_server_config));
asl_field_new_string (fields, "failover_timeout", field_value);
icl_shortstr_cpy (field_value, amq_server_config_attach (amq_server_config));
asl_field_new_string (fields, "attach", field_value);
icl_shortstr_cpy (field_value, amq_server_config_attach_vhost (amq_server_config));
asl_field_new_string (fields, "attach_vhost", field_value);
icl_shortstr_cpy (field_value, amq_server_config_attach_login (amq_server_config));
asl_field_new_string (fields, "attach_login", field_value);
icl_shortstr_cpy (field_value, amq_server_config_attach_all (amq_server_config));
asl_field_new_string (fields, "attach_all", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_batching (amq_server_config));
asl_field_new_string (fields, "batching", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_direct_heartbeat (amq_server_config));
asl_field_new_string (fields, "direct_heartbeat", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_no_ack (amq_server_config));
asl_field_new_string (fields, "no_ack", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_auto_crash (amq_server_config));
asl_field_new_string (fields, "auto_crash", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_auto_block (amq_server_config));
asl_field_new_string (fields, "auto_block", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_kernel_limit (amq_server_config));
asl_field_new_string (fields, "kernel_limit", field_value);
amq_console_reply_ok (amq_console, "inspect-reply", request, self->object_id, fields, NULL);
asl_field_list_unlink (&fields);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_UNNAMED_6))
    icl_stats_inc ("amq_console_config_agent_unnamed_6", &s_amq_console_config_agent_unnamed_6_stats);
#endif        
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_MODIFY))
    icl_stats_inc ("amq_console_config_agent_modify", &s_amq_console_config_agent_modify_stats);
#endif        
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console_config
amq_content_basic_t *
    request;
asl_field_list_t *
    fields;

    request = modify_m->request;
    fields = modify_m->fields;
        {
asl_field_t
    *field;
icl_shortstr_t
    field_value;
char
    *notice_text = NULL;            //  Notice to UI, if any

field = asl_field_list_search (fields, "port");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_port (amq_server_config, field_value);
      notice_text = "To activate the new port setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "listen");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_listen (amq_server_config, field_value);
      notice_text = "To activate the new listen setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "queue_timeout");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_queue_timeout (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "vhost");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_vhost (amq_server_config, field_value);
      notice_text = "To activate the new vhost setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "user");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_user (amq_server_config, field_value);
      notice_text = "To activate the new user setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "group");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_group (amq_server_config, field_value);
      notice_text = "To activate the new group setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "monitor");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_monitor (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "dump_state");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_dump_state (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "record_stats");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_record_stats (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "log_path");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_log_path (amq_server_config, field_value);
      notice_text = "To activate the new log_path setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "keep_logs");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_keep_logs (amq_server_config, atoi (field_value));
      notice_text = "To activate the new keep_logs setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "archive_path");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_archive_path (amq_server_config, field_value);
      notice_text = "To activate the new archive_path setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "archive_cmd");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_archive_cmd (amq_server_config, field_value);
      notice_text = "To activate the new archive_cmd setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "alert_log");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_alert_log (amq_server_config, field_value);
      notice_text = "To activate the new alert_log setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "daily_log");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_daily_log (amq_server_config, field_value);
      notice_text = "To activate the new daily_log setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "debug_log");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_debug_log (amq_server_config, field_value);
      notice_text = "To activate the new debug_log setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "debug_route");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_debug_route (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "debug_queue");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_debug_queue (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "debug_peering");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_debug_peering (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "debug_console");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_debug_console (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "trace");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_trace (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "heartbeat");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_heartbeat (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "setup_timeout");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_setup_timeout (amq_server_config, atol (field_value));
      notice_text = "To activate the new setup_timeout setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "close_timeout");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_close_timeout (amq_server_config, atol (field_value));
      notice_text = "To activate the new close_timeout setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "accept_retry_timeout");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_accept_retry_timeout (amq_server_config, atol (field_value));
      notice_text = "To activate the new accept_retry_timeout setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "polling_threads");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_polling_threads (amq_server_config, atol (field_value));
      notice_text = "To activate the new polling_threads setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "working_threads");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_working_threads (amq_server_config, atol (field_value));
      notice_text = "To activate the new working_threads setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "tcp_nodelay");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_tcp_nodelay (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "tcp_rcvbuf");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_tcp_rcvbuf (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "tcp_sndbuf");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_tcp_sndbuf (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "frame_max");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_frame_max (amq_server_config, atol (field_value));
      notice_text = "To activate the new frame_max setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "direct");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_direct (amq_server_config, atol (field_value));
      notice_text = "To activate the new direct setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "private_credit");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_private_credit (amq_server_config, atol (field_value));
      notice_text = "To activate the new private_credit setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "shared_credit");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_shared_credit (amq_server_config, atol (field_value));
      notice_text = "To activate the new shared_credit setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "backup");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_backup (amq_server_config, field_value);
      notice_text = "To activate the new backup setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "primary");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_primary (amq_server_config, field_value);
      notice_text = "To activate the new primary setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "failover_timeout");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_failover_timeout (amq_server_config, atol (field_value));
      notice_text = "To activate the new failover_timeout setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "attach");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_attach (amq_server_config, field_value);
      notice_text = "To activate the new attach setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "attach_vhost");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_attach_vhost (amq_server_config, field_value);
      notice_text = "To activate the new attach_vhost setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "attach_login");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_attach_login (amq_server_config, field_value);
      notice_text = "To activate the new attach_login setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "attach_all");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_attach_all (amq_server_config, field_value);
      notice_text = "To activate the new attach_all setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "batching");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_batching (amq_server_config, atol (field_value));
      notice_text = "To activate the new batching setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "direct_heartbeat");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_direct_heartbeat (amq_server_config, atol (field_value));
      notice_text = "To activate the new direct_heartbeat setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "no_ack");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_no_ack (amq_server_config, atoi (field_value));
      notice_text = "To activate the new no_ack setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "auto_crash");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_auto_crash (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "auto_block");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_auto_block (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "kernel_limit");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_kernel_limit (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
amq_console_reply_ok (
    amq_console, "modify-reply", request, self->object_id, NULL, notice_text);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_UNNAMED_8))
    icl_stats_inc ("amq_console_config_agent_unnamed_8", &s_amq_console_config_agent_unnamed_8_stats);
#endif        
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_METHOD))
    icl_stats_inc ("amq_console_config_agent_method", &s_amq_console_config_agent_method_stats);
#endif        
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console_config
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
if (streq (method_name, "commit")) {
    amq_server_config_commit (amq_server_config, NULL);
}
if (streq (method_name, "rollback")) {
    amq_server_config_rollback (amq_server_config);
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
action_unnamed_10 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_CONFIG_AGENT_UNNAMED_10))
    icl_stats_inc ("amq_console_config_agent_unnamed_10", &s_amq_console_config_agent_unnamed_10_stats);
#endif        
#define tcb ((amq_console_config_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

