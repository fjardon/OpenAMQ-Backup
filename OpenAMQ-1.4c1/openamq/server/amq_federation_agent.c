/*---------------------------------------------------------------------------
    amq_federation_agent.c - functions for amq_federation_agent.

    Generated from amq_federation_agent.smt by smt_gen.gsl using GSL/4.

    
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
#include "amq_federation_agent.h"

#define class_main_state                           1
#define class_shutting_down_state                  2

#define destroy_m ((amq_federation_agent_destroy_t *) thread->method->data)

#define binding_created_m ((amq_federation_agent_binding_created_t *) thread->method->data)

#define binding_destroyed_m ((amq_federation_agent_binding_destroyed_t *) thread->method->data)

#define message_published_m ((amq_federation_agent_message_published_t *) thread->method->data)

enum {
    shutdown_event                                 = 1,
    destroy_m_event                                = 2,
    binding_created_m_event                        = 3,
    binding_destroyed_m_event                      = 4,
    message_published_m_event                      = 5,
};

#define laststate                                  2
#define lastevent                                  5
#define lastplace                                  13

#define amq_federation_agent_agent_name            "Amq-Federation-Agent"

#define class_thread_name                          "Class"

#define main_state_name                            "Main"
#define shutting_down_state_name                   "Shutting-Down"

#define shutdown_event_name                        "Shutdown"
#define destroy_m_event_name                       "Destroy-M"
#define binding_created_m_event_name               "Binding-Created-M"
#define binding_destroyed_m_event_name             "Binding-Destroyed-M"
#define message_published_m_event_name             "Message-Published-M"

#define free_action_name                           "Free"
#define unnamed_2_action_name                      "Unnamed-2"
#define unnamed_3_action_name                      "Unnamed-3"
#define binding_created_action_name                "Binding-Created"
#define unnamed_5_action_name                      "Unnamed-5"
#define binding_destroyed_action_name              "Binding-Destroyed"
#define unnamed_7_action_name                      "Unnamed-7"
#define message_published_action_name              "Message-Published"
#define unnamed_9_action_name                      "Unnamed-9"

#define the_next_event                             thread->_next_event
#define exception_raised                           thread->_exception_raised

typedef struct
  {
    char *         file;
    size_t         line;
  }
amq_federation_agent_destroy_t;

typedef struct
  {
    char *         routing_key;
    icl_longstr_t *  arguments;
    Bool           exclusive;
  }
amq_federation_agent_binding_created_t;

typedef struct
  {
    char *         routing_key;
    icl_longstr_t *  arguments;
  }
amq_federation_agent_binding_destroyed_t;

typedef struct
  {
    amq_content_basic_t *  content;
    Bool           mandatory;
    Bool           immediate;
  }
amq_federation_agent_message_published_t;

static icl_cache_t
    *s_class_context_cache = NULL;

typedef struct {
    int
        links;

        amq_federation_t
            *amq_federation;
    
} amq_federation_agent_class_context_t;

static icl_cache_t
    *s_destroy_cache = NULL;
static icl_cache_t
    *s_binding_created_cache = NULL;
static icl_cache_t
    *s_binding_destroyed_cache = NULL;
static icl_cache_t
    *s_message_published_cache = NULL;

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
    binding_created_m_event_name,
    binding_destroyed_m_event_name,
    message_published_m_event_name
};

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT)     ||  defined (BASE_TRACE)  || defined (BASE_TRACE_AMQ_FEDERATION_AGENT)   ||  defined (AMQ_FEDERATION_AGENT_TRACE))
static const char *action_name [] = {
    "<NULL>",
    free_action_name,
    unnamed_2_action_name,
    unnamed_3_action_name,
    binding_created_action_name,
    unnamed_5_action_name,
    binding_destroyed_action_name,
    unnamed_7_action_name,
    message_published_action_name,
    unnamed_9_action_name
};
#endif

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
static Bool
    s_animate = FALSE;
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_FREE))
static icl_stats_t *s_amq_federation_agent_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_UNNAMED_2))
static icl_stats_t *s_amq_federation_agent_unnamed_2_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_UNNAMED_3))
static icl_stats_t *s_amq_federation_agent_unnamed_3_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_BINDING_CREATED))
static icl_stats_t *s_amq_federation_agent_binding_created_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_UNNAMED_5))
static icl_stats_t *s_amq_federation_agent_unnamed_5_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_BINDING_DESTROYED))
static icl_stats_t *s_amq_federation_agent_binding_destroyed_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_UNNAMED_7))
static icl_stats_t *s_amq_federation_agent_unnamed_7_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_MESSAGE_PUBLISHED))
static icl_stats_t *s_amq_federation_agent_message_published_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_UNNAMED_9))
static icl_stats_t *s_amq_federation_agent_unnamed_9_stats = NULL;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//  Function prototypes                                                        

static int    amq_federation_agent_manager    (smt_thread_t **thread);
static int    amq_federation_agent_catcher    (smt_thread_t *thread);
static int    amq_federation_agent_class_destroy  (smt_thread_t *thread);
static void   find_thread_state_next_state    (int          *thread_type,
                                               smt_state_t  *state_id,
                                               smt_event_t  *event_id,
                                               smt_state_t  *nextstate_id,
                                               smt_thread_t *thread);
static void   report_unrecognised_event_error (smt_thread_t *thread);
static void   report_state_machine_error      (smt_thread_t *thread);

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
static void   animate_start_new_event         (smt_thread_t *thread,
                                               smt_event_t  saveevent_id);
static void   animate_action                  (smt_thread_t *thread_id,
                                               int          action_id);
static int    find_thread_type                (smt_place_t  place);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION_AGENT)       ||  defined (AMQ_FEDERATION_AGENT_TRACE))
static void   s_dump                          (icl_os_thread_t apr_os_thread,
                                               apr_time_t      time,
                                               qbyte           info);

#endif

static int    action_free                     (smt_thread_t *thread);
static int    action_unnamed_2                (smt_thread_t *thread);
static int    action_unnamed_3                (smt_thread_t *thread);
static int    action_binding_created          (smt_thread_t *thread);
static int    action_unnamed_5                (smt_thread_t *thread);
static int    action_binding_destroyed        (smt_thread_t *thread);
static int    action_unnamed_7                (smt_thread_t *thread);
static int    action_message_published        (smt_thread_t *thread);
static int    action_unnamed_9                (smt_thread_t *thread);
static int
amq_federation_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line);
int
amq_federation_agent_destroy_destructor (void *data);
static int
amq_federation_agent_binding_created_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         routing_key,
    icl_longstr_t *  arguments,
    Bool           exclusive);
int
amq_federation_agent_binding_created_destructor (void *data);
static int
amq_federation_agent_binding_destroyed_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         routing_key,
    icl_longstr_t *  arguments);
int
amq_federation_agent_binding_destroyed_destructor (void *data);
static int
amq_federation_agent_message_published_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  content,
    Bool           mandatory,
    Bool           immediate);
int
amq_federation_agent_message_published_destructor (void *data);
//  Function definitions                                                       

static int
amq_federation_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line)
{
    int
        rc = 0;
    amq_federation_agent_destroy_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_destroy_cache);
    _message->file                      = file;
    _message->line                      = line;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_federation_agent_destroy_destructor);
    
    return rc;
}

int
amq_federation_agent_destroy_destructor (void *data)
{
    int
        rc = 0;
char * file;
size_t line;

    file = ((amq_federation_agent_destroy_t *) data)-> file;
    line = ((amq_federation_agent_destroy_t *) data)-> line;


    icl_mem_free (data);
    return rc;
}


static int
amq_federation_agent_binding_created_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         routing_key,
    icl_longstr_t *  arguments,
    Bool           exclusive)
{
    int
        rc = 0;
    amq_federation_agent_binding_created_t
        *_message;
        
    //  Possess code for binding created
    

    routing_key = icl_mem_strdup (routing_key);
    arguments = icl_longstr_dup (arguments);
    
    

    _message = icl_mem_cache_alloc (s_binding_created_cache);
    _message->routing_key               = routing_key;
    _message->arguments                 = arguments;
    _message->exclusive                 = exclusive;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_federation_agent_binding_created_destructor);
    
    return rc;
}

int
amq_federation_agent_binding_created_destructor (void *data)
{
    int
        rc = 0;
char * routing_key;
icl_longstr_t * arguments;
Bool exclusive;

    routing_key = ((amq_federation_agent_binding_created_t *) data)-> routing_key;
    arguments = ((amq_federation_agent_binding_created_t *) data)-> arguments;
    exclusive = ((amq_federation_agent_binding_created_t *) data)-> exclusive;



    icl_mem_free (routing_key);
    icl_longstr_destroy (&arguments);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_federation_agent_binding_destroyed_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         routing_key,
    icl_longstr_t *  arguments)
{
    int
        rc = 0;
    amq_federation_agent_binding_destroyed_t
        *_message;
        
    //  Possess code for binding destroyed
    

    routing_key = icl_mem_strdup (routing_key);
    arguments = icl_longstr_dup (arguments);
    
    

    _message = icl_mem_cache_alloc (s_binding_destroyed_cache);
    _message->routing_key               = routing_key;
    _message->arguments                 = arguments;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_federation_agent_binding_destroyed_destructor);
    
    return rc;
}

int
amq_federation_agent_binding_destroyed_destructor (void *data)
{
    int
        rc = 0;
char * routing_key;
icl_longstr_t * arguments;

    routing_key = ((amq_federation_agent_binding_destroyed_t *) data)-> routing_key;
    arguments = ((amq_federation_agent_binding_destroyed_t *) data)-> arguments;



    icl_mem_free (routing_key);
    icl_longstr_destroy (&arguments);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_federation_agent_message_published_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  content,
    Bool           mandatory,
    Bool           immediate)
{
    int
        rc = 0;
    amq_federation_agent_message_published_t
        *_message;
        
    //  Possess code for message published
    

    content = amq_content_basic_link (content);
    
    

    _message = icl_mem_cache_alloc (s_message_published_cache);
    _message->content                   = content;
    _message->mandatory                 = mandatory;
    _message->immediate                 = immediate;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_federation_agent_message_published_destructor);
    
    return rc;
}

int
amq_federation_agent_message_published_destructor (void *data)
{
    int
        rc = 0;
amq_content_basic_t * content;
Bool mandatory;
Bool immediate;

    content = ((amq_federation_agent_message_published_t *) data)-> content;
    mandatory = ((amq_federation_agent_message_published_t *) data)-> mandatory;
    immediate = ((amq_federation_agent_message_published_t *) data)-> immediate;



    amq_content_basic_unlink (&content);
    
    

    icl_mem_free (data);
    return rc;
}


int
amq_federation_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_federation_agent_manager);
        rc = amq_federation_agent_destroy_send (
                thread->reply_queue, destroy_m_event,
                file,
                line);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_federation_agent_binding_created (
    smt_thread_t * thread,
    char *                routing_key,
    icl_longstr_t *       arguments,
    Bool                  exclusive)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_federation_agent_manager);
        rc = amq_federation_agent_binding_created_send (
                thread->reply_queue, binding_created_m_event,
                routing_key,
                arguments,
                exclusive);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_federation_agent_binding_destroyed (
    smt_thread_t * thread,
    char *                routing_key,
    icl_longstr_t *       arguments)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_federation_agent_manager);
        rc = amq_federation_agent_binding_destroyed_send (
                thread->reply_queue, binding_destroyed_m_event,
                routing_key,
                arguments);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_federation_agent_message_published (
    smt_thread_t * thread,
    amq_content_basic_t * content,
    Bool                  mandatory,
    Bool                  immediate)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_federation_agent_manager);
        rc = amq_federation_agent_message_published_send (
                thread->reply_queue, message_published_m_event,
                content,
                mandatory,
                immediate);
    }
    else
        rc = -1;
        
    return rc;
}

void
amq_federation_agent_term (void)
{

}

int 
amq_federation_agent_init (void)
{
    int
        rc = SMT_OK;                    //  Return code

    s_class_context_cache = icl_cache_get (sizeof (amq_federation_agent_class_context_t));
    s_destroy_cache = icl_cache_get (sizeof (amq_federation_agent_destroy_t));
    s_binding_created_cache = icl_cache_get (sizeof (amq_federation_agent_binding_created_t));
    s_binding_destroyed_cache = icl_cache_get (sizeof (amq_federation_agent_binding_destroyed_t));
    s_message_published_cache = icl_cache_get (sizeof (amq_federation_agent_message_published_t));

    //  Initialise basic stuff.
    smt_initialise ();
    
    {

    }
    icl_system_register (NULL, amq_federation_agent_term);
    
    return rc;
}

void
amq_federation_agent_animate (Bool animate)
{
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
    s_animate = animate;
#endif
}

smt_thread_t *
amq_federation_agent_class_thread_new (
    amq_federation_t * self)
{
    smt_thread_t
        *thread;

    thread = smt_thread_new (amq_federation_agent_manager,
                             amq_federation_agent_catcher,
                             amq_federation_agent_class_destroy);
                             

#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    thread->trace = icl_trace_new (ICL_TRACE_SIZE);
#endif

    if (thread) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
        thread->animate = s_animate;
        if (s_animate)
            icl_console_print ("%4lu> %-15s/%-15s <Created>",
                thread->id,
                "amq_federation_agent",
                class_thread_name);
#endif

        thread->place   = 1;
        thread->context = icl_mem_cache_alloc (s_class_context_cache);
        memset (thread->context, 0, sizeof (amq_federation_agent_class_context_t));
        ((amq_federation_agent_class_context_t *) thread->context)->links = 1;
        thread->event_name = event_name;
{
#define tcb ((amq_federation_agent_class_context_t *) thread->context)

        tcb->amq_federation = self;
    
#undef  tcb
}
    }
    return thread;
}


static int
amq_federation_agent_manager (smt_thread_t **thread_p)
{
    smt_thread_t
        *thread = *thread_p;
        
    int
        rc;
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))

    smt_event_t
        saveevent_id = SMT_NULL_EVENT;
#endif
        
    assert (thread->manager == amq_federation_agent_manager);
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
#define tcb ((amq_federation_agent_class_context_t *) thread->context)

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
#define tcb ((amq_federation_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 3; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 4; break;
                case binding_created_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 5; break;
                case binding_destroyed_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 6; break;
                case message_published_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 7; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
        case 8:                         //  shutting down state                 
{
#define tcb ((amq_federation_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 9; break;
                case binding_created_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 10; break;
                case binding_destroyed_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 11; break;
                case message_published_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 12; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 13; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
    }
                                  
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
                    if (thread->animate)
                        animate_action (thread, 1);
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

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
                    if (thread->animate)
                        animate_action (thread, 2);
#endif
                    rc = action_unnamed_2 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
                    if (thread->animate)
                        animate_action (thread, 1);
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

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
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

                case 3:                         //  After actions              
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
                    if (thread->animate)
                        animate_action (thread, 4);
#endif
                    rc = action_binding_created (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
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
        case 6:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
                    if (thread->animate)
                        animate_action (thread, 6);
#endif
                    rc = action_binding_destroyed (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
                    if (thread->animate)
                        animate_action (thread, 8);
#endif
                    rc = action_message_published (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
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
amq_federation_agent_catcher (smt_thread_t *thread)
{
    return SMT_OK;
}


static int    
amq_federation_agent_class_destroy (smt_thread_t *thread)
{
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (AMQ_FEDERATION_AGENT_TRACE))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))
    if (thread->animate)
        icl_console_print ("%4lu> %-15s/%-15s <Destroyed>",
                  thread->id,
                  "amq_federation_agent",
                 class_thread_name);

#endif
    if (--((amq_federation_agent_class_context_t *) thread->context)->links == 0)
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
    icl_console_print ("amq_federation_agent: Unrecognised event '%s' in '%s' thread number: %u, state: %s",
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

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_FEDERATION_AGENT))

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
            "amq_federation_agent",
            thread_name [thread_type],
            state_name [state_id]);
  icl_console_print ("%4lu> %-15s/%-15s    (--) %-32s->%s",
            thread->id,
            "amq_federation_agent",
            thread_name [thread_type],
            event_name [event_id != SMT_NULL_EVENT ? event_id : saveevent_id],
            nextstate_id ? state_name [nextstate_id] : "");
}

static void
animate_action (smt_thread_t *thread, int action_id)
{
    icl_console_print ("%4lu> %-15s/%-15s           + %s",
              thread->id,
              "amq_federation_agent",
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_FEDERATION_AGENT)         ||  defined (AMQ_FEDERATION_AGENT_TRACE))
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
                                       "amq_federation_agent",
                                       action_name [action_id]);
    }
    else
    if (state_or_event_or_action > laststate) {
        event_id = state_or_event_or_action - laststate;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s    (--) %-32s",
                                       thread_id,
                                       "amq_federation_agent",
                                       event_name [event_id]);
    }
    else {
        state_id = state_or_event_or_action;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s %s:",
                                       thread_id,
                                       "amq_federation_agent",
                                       state_id ? state_name [state_id] : "<Destroyed>");
    }
}

#endif
static int
action_free (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_FREE))
    icl_stats_inc ("amq_federation_agent_free", &s_amq_federation_agent_free_stats);
#endif        
#define tcb ((amq_federation_agent_class_context_t *) thread->context)
{


#define self tcb->amq_federation
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_federation object");
    amq_federation_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_federation_free (self);
    self = NULL;
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_2 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_UNNAMED_2))
    icl_stats_inc ("amq_federation_agent_unnamed_2", &s_amq_federation_agent_unnamed_2_stats);
#endif        
#define tcb ((amq_federation_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_3 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_UNNAMED_3))
    icl_stats_inc ("amq_federation_agent_unnamed_3", &s_amq_federation_agent_unnamed_3_stats);
#endif        
#define tcb ((amq_federation_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_binding_created (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_BINDING_CREATED))
    icl_stats_inc ("amq_federation_agent_binding_created", &s_amq_federation_agent_binding_created_stats);
#endif        
#define tcb ((amq_federation_agent_class_context_t *) thread->context)
{


#define self tcb->amq_federation
char *
    routing_key;
icl_longstr_t *
    arguments;
Bool
    exclusive;

    routing_key = binding_created_m->routing_key;
    arguments = binding_created_m->arguments;
    exclusive = binding_created_m->exclusive;
        {
if ((self->type == AMQ_FEDERATION_SUBSCRIBER || self->type == AMQ_FEDERATION_FANOUT)
||  (self->type == AMQ_FEDERATION_SERVICE && exclusive)) {
    if (amq_server_config_debug_peering (amq_server_config))
        smt_log_print (amq_broker->debug_log,
            "P: bind     exchange=%s host=%s routing_key=%s", 
            self->exchange->name, self->peering->host, routing_key);

    amq_peering_bind (self->peering, routing_key, arguments);
}
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_UNNAMED_5))
    icl_stats_inc ("amq_federation_agent_unnamed_5", &s_amq_federation_agent_unnamed_5_stats);
#endif        
#define tcb ((amq_federation_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_binding_destroyed (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_BINDING_DESTROYED))
    icl_stats_inc ("amq_federation_agent_binding_destroyed", &s_amq_federation_agent_binding_destroyed_stats);
#endif        
#define tcb ((amq_federation_agent_class_context_t *) thread->context)
{


#define self tcb->amq_federation
char *
    routing_key;
icl_longstr_t *
    arguments;

    routing_key = binding_destroyed_m->routing_key;
    arguments = binding_destroyed_m->arguments;
        {
if (self->type == AMQ_FEDERATION_SUBSCRIBER 
||  self->type == AMQ_FEDERATION_FANOUT
||  self->type == AMQ_FEDERATION_SERVICE) {
    if (amq_server_config_debug_peering (amq_server_config))
        smt_log_print (amq_broker->debug_log,
            "P: unbind   exchange=%s host=%s routing_key=%s", 
            self->exchange->name, self->peering->host, routing_key);

    amq_peering_unbind (self->peering, routing_key, arguments);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_UNNAMED_7))
    icl_stats_inc ("amq_federation_agent_unnamed_7", &s_amq_federation_agent_unnamed_7_stats);
#endif        
#define tcb ((amq_federation_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_message_published (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_MESSAGE_PUBLISHED))
    icl_stats_inc ("amq_federation_agent_message_published", &s_amq_federation_agent_message_published_stats);
#endif        
#define tcb ((amq_federation_agent_class_context_t *) thread->context)
{


#define self tcb->amq_federation
amq_content_basic_t *
    content;
Bool
    mandatory;
Bool
    immediate;

    content = message_published_m->content;
    mandatory = message_published_m->mandatory;
    immediate = message_published_m->immediate;
        {
amq_peering_forward (
    self->peering,
    content->routing_key,
    content,
    mandatory,
    immediate);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT)  ||  defined (BASE_STATS_AMQ_FEDERATION_AGENT_UNNAMED_9))
    icl_stats_inc ("amq_federation_agent_unnamed_9", &s_amq_federation_agent_unnamed_9_stats);
#endif        
#define tcb ((amq_federation_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

