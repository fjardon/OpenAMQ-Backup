/*---------------------------------------------------------------------------
    amq_console_agent.c - functions for amq_console_agent.

    Generated from amq_console_agent.smt by smt_gen.gsl using GSL/4.

    
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
#include "amq_console_agent.h"

#define class_main_state                           1
#define class_shutting_down_state                  2

#define destroy_m ((amq_console_agent_destroy_t *) thread->method->data)

#define register_m ((amq_console_agent_register_t *) thread->method->data)

#define cancel_m ((amq_console_agent_cancel_t *) thread->method->data)

#define accept_m ((amq_console_agent_accept_t *) thread->method->data)

#define reply_ok_m ((amq_console_agent_reply_ok_t *) thread->method->data)

#define reply_error_m ((amq_console_agent_reply_error_t *) thread->method->data)

enum {
    shutdown_event                                 = 1,
    destroy_m_event                                = 2,
    register_m_event                               = 3,
    cancel_m_event                                 = 4,
    accept_m_event                                 = 5,
    reply_ok_m_event                               = 6,
    reply_error_m_event                            = 7,
};

#define laststate                                  2
#define lastevent                                  7
#define lastplace                                  17

#define amq_console_agent_agent_name               "Amq-Console-Agent"

#define class_thread_name                          "Class"

#define main_state_name                            "Main"
#define shutting_down_state_name                   "Shutting-Down"

#define shutdown_event_name                        "Shutdown"
#define destroy_m_event_name                       "Destroy-M"
#define register_m_event_name                      "Register-M"
#define cancel_m_event_name                        "Cancel-M"
#define accept_m_event_name                        "Accept-M"
#define reply_ok_m_event_name                      "Reply-Ok-M"
#define reply_error_m_event_name                   "Reply-Error-M"

#define destroy_action_name                        "Destroy"
#define free_action_name                           "Free"
#define unnamed_3_action_name                      "Unnamed-3"
#define unnamed_4_action_name                      "Unnamed-4"
#define register_action_name                       "Register"
#define unnamed_6_action_name                      "Unnamed-6"
#define cancel_action_name                         "Cancel"
#define unnamed_8_action_name                      "Unnamed-8"
#define accept_action_name                         "Accept"
#define unnamed_10_action_name                     "Unnamed-10"
#define reply_ok_action_name                       "Reply-Ok"
#define unnamed_12_action_name                     "Unnamed-12"
#define reply_error_action_name                    "Reply-Error"
#define unnamed_14_action_name                     "Unnamed-14"

#define the_next_event                             thread->_next_event
#define exception_raised                           thread->_exception_raised

typedef struct
  {
    char *         file;
    size_t         line;
  }
amq_console_agent_destroy_t;

typedef struct
  {
    qbyte          object_id;
    void *         object_ref;
    amq_console_class_t *  class_ref;
    qbyte          parent_id;
  }
amq_console_agent_register_t;

typedef struct
  {
    qbyte          object_id;
  }
amq_console_agent_cancel_t;

typedef struct
  {
    amq_content_basic_t *  content;
    int            group;
  }
amq_console_agent_accept_t;

typedef struct
  {
    char *         name;
    amq_content_basic_t *  request;
    qbyte          object_id;
    asl_field_list_t *  fields;
    char *         notice;
  }
amq_console_agent_reply_ok_t;

typedef struct
  {
    char *         name;
    char *         status;
    amq_content_basic_t *  request;
    qbyte          object_id;
  }
amq_console_agent_reply_error_t;


//  This file is generated when we build the project
#define AMQ_CONSOLE_SCHEMA      "amq_console_schema.cml"

static amq_console_entry_t *
    s_lookup_object   (amq_console_t *self, qbyte object_id);
static void
    s_execute_schema  (amq_content_basic_t *request);
static void
    s_execute_inspect (amq_console_t *self, amq_content_basic_t *request, ipr_xml_t *xml_item, int group);
static void
    s_execute_modify  (amq_console_t *self, amq_content_basic_t *request, ipr_xml_t *xml_item, int group);
static void
    s_execute_monitor (amq_console_t *self, amq_content_basic_t *request, ipr_xml_t *xml_item, int group);
static void
    s_execute_method  (amq_console_t *self, amq_content_basic_t *request, ipr_xml_t *xml_item, int group);
static asl_field_list_t *
    s_get_field_list  (ipr_xml_t *xml_item);
static void
    s_invalid_cml     (amq_content_basic_t *request, ipr_bucket_t *bucket, char *error);
static void
    s_reply_error     (amq_content_basic_t *request, char *top, char *status);
static void
    s_reply_xml       (amq_content_basic_t *request, ipr_xml_t *xml_item);
static void
    s_reply_bucket    (amq_content_basic_t *request, ipr_bucket_t *bucket);
static void
    s_destroy_item    (ipr_hash_t *item, void *argument);

static icl_cache_t
    *s_class_context_cache = NULL;

typedef struct {
    int
        links;

        amq_console_t
            *amq_console;
    
} amq_console_agent_class_context_t;

static icl_cache_t
    *s_destroy_cache = NULL;
static icl_cache_t
    *s_register_cache = NULL;
static icl_cache_t
    *s_cancel_cache = NULL;
static icl_cache_t
    *s_accept_cache = NULL;
static icl_cache_t
    *s_reply_ok_cache = NULL;
static icl_cache_t
    *s_reply_error_cache = NULL;

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
    register_m_event_name,
    cancel_m_event_name,
    accept_m_event_name,
    reply_ok_m_event_name,
    reply_error_m_event_name
};

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT)        ||  defined (BASE_TRACE)  || defined (BASE_TRACE_AMQ_CONSOLE_AGENT)   ||  defined (AMQ_CONSOLE_AGENT_TRACE))
static const char *action_name [] = {
    "<NULL>",
    destroy_action_name,
    free_action_name,
    unnamed_3_action_name,
    unnamed_4_action_name,
    register_action_name,
    unnamed_6_action_name,
    cancel_action_name,
    unnamed_8_action_name,
    accept_action_name,
    unnamed_10_action_name,
    reply_ok_action_name,
    unnamed_12_action_name,
    reply_error_action_name,
    unnamed_14_action_name
};
#endif

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
static Bool
    s_animate = FALSE;
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_DESTROY))
static icl_stats_t *s_amq_console_agent_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_FREE))
static icl_stats_t *s_amq_console_agent_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_3))
static icl_stats_t *s_amq_console_agent_unnamed_3_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_4))
static icl_stats_t *s_amq_console_agent_unnamed_4_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_REGISTER))
static icl_stats_t *s_amq_console_agent_register_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_6))
static icl_stats_t *s_amq_console_agent_unnamed_6_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_CANCEL))
static icl_stats_t *s_amq_console_agent_cancel_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_8))
static icl_stats_t *s_amq_console_agent_unnamed_8_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_ACCEPT))
static icl_stats_t *s_amq_console_agent_accept_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_10))
static icl_stats_t *s_amq_console_agent_unnamed_10_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_REPLY_OK))
static icl_stats_t *s_amq_console_agent_reply_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_12))
static icl_stats_t *s_amq_console_agent_unnamed_12_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_REPLY_ERROR))
static icl_stats_t *s_amq_console_agent_reply_error_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_14))
static icl_stats_t *s_amq_console_agent_unnamed_14_stats = NULL;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//  Function prototypes                                                        

static int    amq_console_agent_manager       (smt_thread_t **thread);
static int    amq_console_agent_catcher       (smt_thread_t *thread);
static int    amq_console_agent_class_destroy  (smt_thread_t *thread);
static void   find_thread_state_next_state    (int          *thread_type,
                                               smt_state_t  *state_id,
                                               smt_event_t  *event_id,
                                               smt_state_t  *nextstate_id,
                                               smt_thread_t *thread);
static void   report_unrecognised_event_error (smt_thread_t *thread);
static void   report_state_machine_error      (smt_thread_t *thread);

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
static void   animate_start_new_event         (smt_thread_t *thread,
                                               smt_event_t  saveevent_id);
static void   animate_action                  (smt_thread_t *thread_id,
                                               int          action_id);
static int    find_thread_type                (smt_place_t  place);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSOLE_AGENT)          ||  defined (AMQ_CONSOLE_AGENT_TRACE))
static void   s_dump                          (icl_os_thread_t apr_os_thread,
                                               apr_time_t      time,
                                               qbyte           info);

#endif

static int    action_destroy                  (smt_thread_t *thread);
static int    action_free                     (smt_thread_t *thread);
static int    action_unnamed_3                (smt_thread_t *thread);
static int    action_unnamed_4                (smt_thread_t *thread);
static int    action_register                 (smt_thread_t *thread);
static int    action_unnamed_6                (smt_thread_t *thread);
static int    action_cancel                   (smt_thread_t *thread);
static int    action_unnamed_8                (smt_thread_t *thread);
static int    action_accept                   (smt_thread_t *thread);
static int    action_unnamed_10               (smt_thread_t *thread);
static int    action_reply_ok                 (smt_thread_t *thread);
static int    action_unnamed_12               (smt_thread_t *thread);
static int    action_reply_error              (smt_thread_t *thread);
static int    action_unnamed_14               (smt_thread_t *thread);
static int
amq_console_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line);
int
amq_console_agent_destroy_destructor (void *data);
static int
amq_console_agent_register_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    qbyte          object_id,
    void *         object_ref,
    amq_console_class_t *  class_ref,
    qbyte          parent_id);
int
amq_console_agent_register_destructor (void *data);
static int
amq_console_agent_cancel_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    qbyte          object_id);
int
amq_console_agent_cancel_destructor (void *data);
static int
amq_console_agent_accept_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  content,
    int            group);
int
amq_console_agent_accept_destructor (void *data);
static int
amq_console_agent_reply_ok_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         name,
    amq_content_basic_t *  request,
    qbyte          object_id,
    asl_field_list_t *  fields,
    char *         notice);
int
amq_console_agent_reply_ok_destructor (void *data);
static int
amq_console_agent_reply_error_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         name,
    char *         status,
    amq_content_basic_t *  request,
    qbyte          object_id);
int
amq_console_agent_reply_error_destructor (void *data);
//  Function definitions                                                       

static int
amq_console_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line)
{
    int
        rc = 0;
    amq_console_agent_destroy_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_destroy_cache);
    _message->file                      = file;
    _message->line                      = line;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_console_agent_destroy_destructor);
    
    return rc;
}

int
amq_console_agent_destroy_destructor (void *data)
{
    int
        rc = 0;
char * file;
size_t line;

    file = ((amq_console_agent_destroy_t *) data)-> file;
    line = ((amq_console_agent_destroy_t *) data)-> line;


    icl_mem_free (data);
    return rc;
}


static int
amq_console_agent_register_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    qbyte          object_id,
    void *         object_ref,
    amq_console_class_t *  class_ref,
    qbyte          parent_id)
{
    int
        rc = 0;
    amq_console_agent_register_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_register_cache);
    _message->object_id                 = object_id;
    _message->object_ref                = object_ref;
    _message->class_ref                 = class_ref;
    _message->parent_id                 = parent_id;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_console_agent_register_destructor);
    
    return rc;
}

int
amq_console_agent_register_destructor (void *data)
{
    int
        rc = 0;
qbyte object_id;
void * object_ref;
amq_console_class_t * class_ref;
qbyte parent_id;

    object_id = ((amq_console_agent_register_t *) data)-> object_id;
    object_ref = ((amq_console_agent_register_t *) data)-> object_ref;
    class_ref = ((amq_console_agent_register_t *) data)-> class_ref;
    parent_id = ((amq_console_agent_register_t *) data)-> parent_id;


    icl_mem_free (data);
    return rc;
}


static int
amq_console_agent_cancel_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    qbyte          object_id)
{
    int
        rc = 0;
    amq_console_agent_cancel_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_cancel_cache);
    _message->object_id                 = object_id;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_console_agent_cancel_destructor);
    
    return rc;
}

int
amq_console_agent_cancel_destructor (void *data)
{
    int
        rc = 0;
qbyte object_id;

    object_id = ((amq_console_agent_cancel_t *) data)-> object_id;


    icl_mem_free (data);
    return rc;
}


static int
amq_console_agent_accept_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    amq_content_basic_t *  content,
    int            group)
{
    int
        rc = 0;
    amq_console_agent_accept_t
        *_message;
        
    //  Possess code for accept
    

    content = amq_content_basic_link (content);
    
    

    _message = icl_mem_cache_alloc (s_accept_cache);
    _message->content                   = content;
    _message->group                     = group;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_console_agent_accept_destructor);
    
    return rc;
}

int
amq_console_agent_accept_destructor (void *data)
{
    int
        rc = 0;
amq_content_basic_t * content;
int group;

    content = ((amq_console_agent_accept_t *) data)-> content;
    group = ((amq_console_agent_accept_t *) data)-> group;



    amq_content_basic_unlink (&content);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_console_agent_reply_ok_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         name,
    amq_content_basic_t *  request,
    qbyte          object_id,
    asl_field_list_t *  fields,
    char *         notice)
{
    int
        rc = 0;
    amq_console_agent_reply_ok_t
        *_message;
        
    //  Possess code for reply ok
    

    name = icl_mem_strdup (name);
    request = amq_content_basic_link (request);
    fields = asl_field_list_link (fields);
    notice = icl_mem_strdup (notice);
    
    

    _message = icl_mem_cache_alloc (s_reply_ok_cache);
    _message->name                      = name;
    _message->request                   = request;
    _message->object_id                 = object_id;
    _message->fields                    = fields;
    _message->notice                    = notice;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_console_agent_reply_ok_destructor);
    
    return rc;
}

int
amq_console_agent_reply_ok_destructor (void *data)
{
    int
        rc = 0;
char * name;
amq_content_basic_t * request;
qbyte object_id;
asl_field_list_t * fields;
char * notice;

    name = ((amq_console_agent_reply_ok_t *) data)-> name;
    request = ((amq_console_agent_reply_ok_t *) data)-> request;
    object_id = ((amq_console_agent_reply_ok_t *) data)-> object_id;
    fields = ((amq_console_agent_reply_ok_t *) data)-> fields;
    notice = ((amq_console_agent_reply_ok_t *) data)-> notice;



    icl_mem_free (name);
    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    icl_mem_free (notice);
    
    

    icl_mem_free (data);
    return rc;
}


static int
amq_console_agent_reply_error_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         name,
    char *         status,
    amq_content_basic_t *  request,
    qbyte          object_id)
{
    int
        rc = 0;
    amq_console_agent_reply_error_t
        *_message;
        
    //  Possess code for reply error
    

    name = icl_mem_strdup (name);
    status = icl_mem_strdup (status);
    request = amq_content_basic_link (request);
    
    

    _message = icl_mem_cache_alloc (s_reply_error_cache);
    _message->name                      = name;
    _message->status                    = status;
    _message->request                   = request;
    _message->object_id                 = object_id;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          amq_console_agent_reply_error_destructor);
    
    return rc;
}

int
amq_console_agent_reply_error_destructor (void *data)
{
    int
        rc = 0;
char * name;
char * status;
amq_content_basic_t * request;
qbyte object_id;

    name = ((amq_console_agent_reply_error_t *) data)-> name;
    status = ((amq_console_agent_reply_error_t *) data)-> status;
    request = ((amq_console_agent_reply_error_t *) data)-> request;
    object_id = ((amq_console_agent_reply_error_t *) data)-> object_id;



    icl_mem_free (name);
    icl_mem_free (status);
    amq_content_basic_unlink (&request);
    
    

    icl_mem_free (data);
    return rc;
}


int
amq_console_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_console_agent_manager);
        rc = amq_console_agent_destroy_send (
                thread->reply_queue, destroy_m_event,
                file,
                line);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_console_agent_register (
    smt_thread_t * thread,
    qbyte                 object_id,
    void *                object_ref,
    amq_console_class_t * class_ref,
    qbyte                 parent_id)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_console_agent_manager);
        rc = amq_console_agent_register_send (
                thread->reply_queue, register_m_event,
                object_id,
                object_ref,
                class_ref,
                parent_id);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_console_agent_cancel (
    smt_thread_t * thread,
    qbyte                 object_id)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_console_agent_manager);
        rc = amq_console_agent_cancel_send (
                thread->reply_queue, cancel_m_event,
                object_id);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_console_agent_accept (
    smt_thread_t * thread,
    amq_content_basic_t * content,
    int                   group)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_console_agent_manager);
        rc = amq_console_agent_accept_send (
                thread->reply_queue, accept_m_event,
                content,
                group);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_console_agent_reply_ok (
    smt_thread_t * thread,
    char *                name,
    amq_content_basic_t * request,
    qbyte                 object_id,
    asl_field_list_t *    fields,
    char *                notice)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_console_agent_manager);
        rc = amq_console_agent_reply_ok_send (
                thread->reply_queue, reply_ok_m_event,
                name,
                request,
                object_id,
                fields,
                notice);
    }
    else
        rc = -1;
        
    return rc;
}

int
amq_console_agent_reply_error (
    smt_thread_t * thread,
    char *                name,
    char *                status,
    amq_content_basic_t * request,
    qbyte                 object_id)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == amq_console_agent_manager);
        rc = amq_console_agent_reply_error_send (
                thread->reply_queue, reply_error_m_event,
                name,
                status,
                request,
                object_id);
    }
    else
        rc = -1;
        
    return rc;
}


static amq_console_entry_t *
s_lookup_object (amq_console_t *self, qbyte object_id)
{
    icl_shortstr_t
        object_key;                     //  Stringified object id
    amq_console_entry_t
        *entry = NULL;
    ipr_hash_t
        *hash;                          //  Entry into hash table

    sprintf (object_key, "%X", object_id);
    hash = ipr_hash_table_search (self->object_store, object_key);
    if (hash) {
        entry = hash->data;
        ipr_hash_unlink (&hash);
    }
    return (entry);
}

static void
s_execute_schema (amq_content_basic_t *request)
{
    ipr_bucket_t
        *bucket;                        //  Schema loaded from disk

    //  The console schema is packaged with the binary using the
    //  iPR Resource Compiler; we can load it into a bucket without
    //  doing any file system access.

    bucket = amq_server_resource_get (AMQ_CONSOLE_SCHEMA);
    assert (bucket);
    s_reply_bucket (request, bucket);
    ipr_bucket_unlink (&bucket);
}

static void
s_execute_inspect (
    amq_console_t *self,
    amq_content_basic_t *request,
    ipr_xml_t *xml_item,
    int group)
{
    char
        *object_str;
    amq_console_entry_t
        *entry;                         //  Object store entry

    object_str = ipr_xml_attr_get (xml_item, "object", NULL);
    if (object_str) {
        entry = s_lookup_object (self, atol (object_str));
        if (entry)
            entry->class_ref->inspect (entry->object_ref, request);
        else
            s_reply_error (request, "inspect-reply", "notfound");
    }
    else {
        smt_log_print (amq_broker->alert_log, "W: console - badly-formatted CML method, no object ID");
        s_reply_error (request, "inspect-reply", "invalid");
    }
}

static void
s_execute_modify (
    amq_console_t *self,
    amq_content_basic_t *request,
    ipr_xml_t *xml_item,
    int group)
{
    char
        *object_str;
    asl_field_list_t
        *fields;                        //  Properties to set
    amq_console_entry_t
        *entry;                         //  Object store entry

    object_str = ipr_xml_attr_get (xml_item, "object", NULL);
    if (object_str) {
        entry = s_lookup_object (self, atol (object_str));
        if (entry) {
            if (group == AMQ_CONNECTION_GROUP_NORMAL) {
                smt_log_print (amq_broker->alert_log,
                    "W: console - normal user attempted super-user function");
                s_reply_error (request, "modify-reply", "noaccess");
            }
            else {
                fields = s_get_field_list (xml_item);
                entry->class_ref->modify (entry->object_ref, request, fields);
                asl_field_list_unlink (&fields);
            }
        }
        else
            s_reply_error (request, "modify-reply", "notfound");
    }
    else {
        smt_log_print (amq_broker->alert_log, "W: console - badly-formatted CML method, no object ID");
        s_reply_error (request, "modify-reply", "invalid");
    }
}


static void
s_execute_monitor (
    amq_console_t *self,
    amq_content_basic_t *request,
    ipr_xml_t *xml_item,
    int group)
{
    smt_log_print (amq_broker->debug_log, "amq_console: monitor");
}


static void
s_execute_method (
    amq_console_t *self,
    amq_content_basic_t *request,
    ipr_xml_t *xml_item,
    int group)
{
    char
        *object_str,
        *method_name;                   //  Method to invoke
    asl_field_list_t
        *fields;                        //  Properties to pass
    amq_console_entry_t
        *entry;                         //  Object store entry

    object_str  = ipr_xml_attr_get (xml_item, "object", NULL);
    method_name = ipr_xml_attr_get (xml_item, "name", NULL);
    if (object_str && method_name) {
        entry = s_lookup_object (self, atol (object_str));
        if (entry) {
            if (group == AMQ_CONNECTION_GROUP_NORMAL) {
                smt_log_print (amq_broker->alert_log,
                    "W: console - normal user attempted super-user function");
                s_reply_error (request, "method-reply", "noaccess");
            }
            else {
                fields = s_get_field_list (xml_item);
                entry->class_ref->method (
                    entry->object_ref, method_name, request, fields);
                asl_field_list_unlink (&fields);
            }
        }
        else
            s_reply_error (request, "method-reply", "notfound");
    }
    else {
        smt_log_print (amq_broker->alert_log, "W: console - badly-formatted CML method, no object ID");
        s_reply_error (request, "method-reply", "invalid");
    }
}

//  Builds field list from body of XML command
//  Caller must destroy field list when finished

static asl_field_list_t *
s_get_field_list (ipr_xml_t *xml_item)
{
    asl_field_list_t
        *fields;
    char
        *field_name,
        *field_value;
    ipr_xml_t
        *xml_field;

    fields = asl_field_list_new (NULL);
    xml_field = ipr_xml_first_child (xml_item);
    while (xml_field) {
        field_name  = ipr_xml_attr_get (xml_field, "name", NULL);
        field_value = ipr_xml_text (xml_field);
        if (field_name)
            asl_field_new_string (fields, field_name, field_value);
        icl_mem_free (field_value);
        xml_field = ipr_xml_next_sibling (&xml_field);
    }
    return (fields);
}

static void
s_invalid_cml (amq_content_basic_t *request, ipr_bucket_t *bucket, char *error)
{
    smt_log_print (amq_broker->alert_log,
        "W: console - content body is not valid CML: %s", error);
    ipr_bucket_dump (bucket, "I: ");
    s_reply_error (request, "invalid", NULL);
}

static void
s_reply_error (amq_content_basic_t *request, char *top, char *status)
{
    ipr_xml_t
        *cml_item,
        *cur_item;

    cml_item = ipr_xml_new (NULL, "cml", NULL);
    ipr_xml_attr_set (cml_item, "version", "1.0");
    ipr_xml_attr_set (cml_item, "xmlns", "http://www.openamq.org/schema/cml");

    cur_item = ipr_xml_new (cml_item, top, NULL);
    if (status)
        ipr_xml_attr_set (cur_item, "status", status);

    s_reply_xml (request, cml_item);
    ipr_xml_unlink  (&cur_item);
    ipr_xml_destroy (&cml_item);
}


//  Send XML tree as reply back to original requestor, using same
//  message id and using original reply-to as routing key.
//
static void
s_reply_xml (amq_content_basic_t *request, ipr_xml_t *xml_item)
{
    char
        *xml_text;                      //  Serialised XML text
    ipr_bucket_t
        *bucket;

    xml_text = ipr_xml_save_string (xml_item);
    bucket = ipr_bucket_new (strlen (xml_text) + 1);
    ipr_bucket_fill (bucket, xml_text, strlen (xml_text) + 1);
    icl_mem_free (xml_text);
    s_reply_bucket (request, bucket);
    ipr_bucket_unlink (&bucket);
}


//  Send ipr bucket reply back to original requestor, using same
//  message id and using original reply-to as routing key.
//
static void
s_reply_bucket (amq_content_basic_t *request, ipr_bucket_t *bucket)
{
    amq_exchange_t
        *exchange;                      //  We send the reply to amq.direct
    amq_vhost_t
        *vhost;
    amq_content_basic_t
        *content;

    if (amq_server_config_debug_console (amq_server_config))
        smt_log_print (amq_broker->debug_log, "C: response xml=%s", bucket->data);

    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {
        if (*request->reply_to) {
            exchange = amq_exchange_table_search (vhost->exchange_table, "amq.direct");
            if (exchange) {
                //  Create a content with our desired reply data
                content = amq_content_basic_new ();
                amq_content_basic_set_message_id   (content, request->message_id);
                amq_content_basic_set_content_type (content, "text/xml");
                amq_content_basic_record_body      (content, bucket);
                amq_content_basic_set_routing_key  (content, "amq.direct", request->reply_to, 0);

                //  Publish the message
                amq_exchange_publish (exchange, NULL, content, FALSE, FALSE, 0);
                amq_content_basic_unlink (&content);

                amq_exchange_unlink (&exchange);
            }
        }
        else
            smt_log_print (amq_broker->alert_log,
                "W: console - client did not specify Reply-To queue");
    }
    amq_vhost_unlink (&vhost);
}

//  Callback for object store destruction

static void
s_destroy_item (ipr_hash_t *item, void *argument)
{
    amq_console_entry_t
        *entry;

    entry = item->data;
    entry->class_ref->unlink (&entry->object_ref);
    ipr_hash_destroy (&item);
    icl_mem_free (entry);
}

void
amq_console_agent_term (void)
{

}

int 
amq_console_agent_init (void)
{
    int
        rc = SMT_OK;                    //  Return code

    s_class_context_cache = icl_cache_get (sizeof (amq_console_agent_class_context_t));
    s_destroy_cache = icl_cache_get (sizeof (amq_console_agent_destroy_t));
    s_register_cache = icl_cache_get (sizeof (amq_console_agent_register_t));
    s_cancel_cache = icl_cache_get (sizeof (amq_console_agent_cancel_t));
    s_accept_cache = icl_cache_get (sizeof (amq_console_agent_accept_t));
    s_reply_ok_cache = icl_cache_get (sizeof (amq_console_agent_reply_ok_t));
    s_reply_error_cache = icl_cache_get (sizeof (amq_console_agent_reply_error_t));

    //  Initialise basic stuff.
    smt_initialise ();
    
    {

    }
    icl_system_register (NULL, amq_console_agent_term);
    
    return rc;
}

void
amq_console_agent_animate (Bool animate)
{
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
    s_animate = animate;
#endif
}

smt_thread_t *
amq_console_agent_class_thread_new (
    amq_console_t * self)
{
    smt_thread_t
        *thread;

    thread = smt_thread_new (amq_console_agent_manager,
                             amq_console_agent_catcher,
                             amq_console_agent_class_destroy);
                             

#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    thread->trace = icl_trace_new (ICL_TRACE_SIZE);
#endif

    if (thread) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
        thread->animate = s_animate;
        if (s_animate)
            icl_console_print ("%4lu> %-15s/%-15s <Created>",
                thread->id,
                "amq_console_agent",
                class_thread_name);
#endif

        thread->place   = 1;
        thread->context = icl_mem_cache_alloc (s_class_context_cache);
        memset (thread->context, 0, sizeof (amq_console_agent_class_context_t));
        ((amq_console_agent_class_context_t *) thread->context)->links = 1;
        thread->event_name = event_name;
{
#define tcb ((amq_console_agent_class_context_t *) thread->context)

        tcb->amq_console = self;
    
#undef  tcb
}
    }
    return thread;
}


static int
amq_console_agent_manager (smt_thread_t **thread_p)
{
    smt_thread_t
        *thread = *thread_p;
        
    int
        rc;
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))

    smt_event_t
        saveevent_id = SMT_NULL_EVENT;
#endif
        
    assert (thread->manager == amq_console_agent_manager);
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
            case 11:
            case 17:
                thread->place = SMT_TERM_PLACE;
                break;
            case 9:
            case 8:
            case 7:
            case 6:
            case 5:
                thread->place = 2;
                break;
            case 15:
            case 13:
            case 16:
            case 3:
            case 14:
            case 12:
                thread->place = 10;
                break;
        }    
    else
    if (thread->module == 0) {
        if (thread->place == 1) { //                Class thread
            if (!thread->shutting_down) {
{
#define tcb ((amq_console_agent_class_context_t *) thread->context)

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
        if (thread->place < 10)                 //  Main state
            thread->place = 2;
        else
            thread->place = 10;
    }

    switch (thread->place) {
        case 2:                         //  main state                          
{
#define tcb ((amq_console_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 3; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 4; break;
                case register_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 5; break;
                case cancel_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 6; break;
                case accept_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 7; break;
                case reply_ok_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 8; break;
                case reply_error_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 9; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
        case 10:                        //  shutting down state                 
{
#define tcb ((amq_console_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 11; break;
                case register_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 12; break;
                case cancel_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 13; break;
                case accept_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 14; break;
                case reply_ok_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 15; break;
                case reply_error_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 16; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 17; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
    }
                                  
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
    if (thread->animate && thread->module == 1)
        animate_start_new_event (thread, saveevent_id);
#endif

    switch (thread->place) {
        case 3:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            switch (thread->module) {
                case 1:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    if (thread->place == 17)
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 5);
#endif
                    rc = action_register (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 7);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 9);
#endif
                    rc = action_accept (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 11);
#endif
                    rc = action_reply_ok (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
                    if (thread->animate)
                        animate_action (thread, 13);
#endif
                    rc = action_reply_error (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
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
amq_console_agent_catcher (smt_thread_t *thread)
{
    return SMT_OK;
}


static int    
amq_console_agent_class_destroy (smt_thread_t *thread)
{
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (AMQ_CONSOLE_AGENT_TRACE))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))
    if (thread->animate)
        icl_console_print ("%4lu> %-15s/%-15s <Destroyed>",
                  thread->id,
                  "amq_console_agent",
                 class_thread_name);

#endif
    if (--((amq_console_agent_class_context_t *) thread->context)->links == 0)
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
        if (thread->place < 10)
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
            }
          }
        else
          {
            *state_id = 2;
            switch (thread->place) {
                case 11: *event_id = 2;   break;
                case 12: *event_id = 3;   *nextstate_id = 2;   break;
                case 13: *event_id = 4;   *nextstate_id = 2;   break;
                case 14: *event_id = 5;   *nextstate_id = 2;   break;
                case 15: *event_id = 6;   *nextstate_id = 2;   break;
                case 16: *event_id = 7;   *nextstate_id = 2;   break;
                case 17: *event_id = 1;   break;
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
    icl_console_print ("amq_console_agent: Unrecognised event '%s' in '%s' thread number: %u, state: %s",
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

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_AMQ_CONSOLE_AGENT))

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
            "amq_console_agent",
            thread_name [thread_type],
            state_name [state_id]);
  icl_console_print ("%4lu> %-15s/%-15s    (--) %-32s->%s",
            thread->id,
            "amq_console_agent",
            thread_name [thread_type],
            event_name [event_id != SMT_NULL_EVENT ? event_id : saveevent_id],
            nextstate_id ? state_name [nextstate_id] : "");
}

static void
animate_action (smt_thread_t *thread, int action_id)
{
    icl_console_print ("%4lu> %-15s/%-15s           + %s",
              thread->id,
              "amq_console_agent",
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_AMQ_CONSOLE_AGENT)            ||  defined (AMQ_CONSOLE_AGENT_TRACE))
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
                                       "amq_console_agent",
                                       action_name [action_id]);
    }
    else
    if (state_or_event_or_action > laststate) {
        event_id = state_or_event_or_action - laststate;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s    (--) %-32s",
                                       thread_id,
                                       "amq_console_agent",
                                       event_name [event_id]);
    }
    else {
        state_id = state_or_event_or_action;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s %s:",
                                       thread_id,
                                       "amq_console_agent",
                                       state_id ? state_name [state_id] : "<Destroyed>");
    }
}

#endif
static int
action_destroy (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_DESTROY))
    icl_stats_inc ("amq_console_agent_destroy", &s_amq_console_agent_destroy_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
ipr_hash_table_apply (self->object_store, s_destroy_item, NULL);
ipr_hash_table_destroy (&self->object_store);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_FREE))
    icl_stats_inc ("amq_console_agent_free", &s_amq_console_agent_free_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_console object");
    amq_console_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_console_free (self);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_3))
    icl_stats_inc ("amq_console_agent_unnamed_3", &s_amq_console_agent_unnamed_3_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_4))
    icl_stats_inc ("amq_console_agent_unnamed_4", &s_amq_console_agent_unnamed_4_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_register (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_REGISTER))
    icl_stats_inc ("amq_console_agent_register", &s_amq_console_agent_register_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console
qbyte
    object_id;
void *
    object_ref;
amq_console_class_t *
    class_ref;
qbyte
    parent_id;

    object_id = register_m->object_id;
    object_ref = register_m->object_ref;
    class_ref = register_m->class_ref;
    parent_id = register_m->parent_id;
        {
ipr_hash_t
    *hash;                          //  Entry into hash table
icl_shortstr_t
    object_key;                     //  Stringified object id
amq_console_entry_t
    *entry;

sprintf (object_key, "%X", object_id);
hash = ipr_hash_new (self->object_store, object_key, NULL);
assert (hash);

entry = icl_mem_alloc (sizeof (amq_console_entry_t));
entry->object_ref = object_ref;
entry->class_ref  = class_ref;
entry->hash       = hash;           //  Holds link to hash
hash->data        = entry;
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_6))
    icl_stats_inc ("amq_console_agent_unnamed_6", &s_amq_console_agent_unnamed_6_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_CANCEL))
    icl_stats_inc ("amq_console_agent_cancel", &s_amq_console_agent_cancel_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console
qbyte
    object_id;

    object_id = cancel_m->object_id;
        {
amq_console_entry_t
    *entry;

entry = s_lookup_object (self, object_id);
if (entry) {
    entry->class_ref->unlink (&entry->object_ref);
    ipr_hash_destroy (&entry->hash);
    icl_mem_free (entry);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_8))
    icl_stats_inc ("amq_console_agent_unnamed_8", &s_amq_console_agent_unnamed_8_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_accept (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_ACCEPT))
    icl_stats_inc ("amq_console_agent_accept", &s_amq_console_agent_accept_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console
amq_content_basic_t *
    content;
int
    group;

    content = accept_m->content;
    group = accept_m->group;
        {
//
ipr_bucket_t
    *bucket = NULL;                 //  Message comes here
ipr_xml_t
    *xml_root,
    *xml_cml,
    *xml_item;

//  Get content body into a bucket
bucket = ipr_bucket_new (IPR_BUCKET_MAX_SIZE);
bucket->cur_size = amq_content_basic_get_body (content, bucket->data, bucket->max_size);
assert (bucket->cur_size < IPR_BUCKET_MAX_SIZE);
bucket->data [bucket->cur_size] = 0;

if (amq_server_config_debug_console (amq_server_config))
    smt_log_print (amq_broker->debug_log, "C: console xml=%s", bucket->data);

//  Parse as XML message
xml_root = ipr_xml_parse_string ((char *) bucket->data);
xml_cml = ipr_xml_first_child (xml_root);
if (xml_cml && streq (ipr_xml_name (xml_cml), "cml")) {
    xml_item = ipr_xml_first_child (xml_cml);
    if (streq (ipr_xml_name (xml_item), "schema-request"))
        s_execute_schema (content);
    else
    if (streq (ipr_xml_name (xml_item), "inspect-request"))
        s_execute_inspect (self, content, xml_item, group);
    else
    if (streq (ipr_xml_name (xml_item), "modify-request"))
        s_execute_modify (self, content, xml_item, group);
    else
    if (streq (ipr_xml_name (xml_item), "monitor-request"))
        s_execute_monitor (self, content, xml_item, group);
    else
    if (streq (ipr_xml_name (xml_item), "method-request"))
        s_execute_method (self, content, xml_item, group);
    else
        s_invalid_cml (content, bucket, "unknown CML command");

    ipr_xml_unlink (&xml_item);
}
else
    s_invalid_cml (content, bucket, "Not a valid CML document");

ipr_bucket_unlink (&bucket);
ipr_xml_destroy (&xml_cml);
ipr_xml_destroy (&xml_root);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_10))
    icl_stats_inc ("amq_console_agent_unnamed_10", &s_amq_console_agent_unnamed_10_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_reply_ok (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_REPLY_OK))
    icl_stats_inc ("amq_console_agent_reply_ok", &s_amq_console_agent_reply_ok_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console
char *
    name;
amq_content_basic_t *
    request;
qbyte
    object_id;
asl_field_list_t *
    fields;
char *
    notice;

    name = reply_ok_m->name;
    request = reply_ok_m->request;
    object_id = reply_ok_m->object_id;
    fields = reply_ok_m->fields;
    notice = reply_ok_m->notice;
        {
asl_field_t
    *field;
ipr_xml_t
    *cml_item,                      //  CML item
    *cur_item,                      //  Top level object
    *sub_item,                      //  Field or class within object
    *val_item;                      //  Value of field
icl_shortstr_t
    strvalue;                       //  Stringified numeric value
amq_console_entry_t
    *entry;                         //  Object store entry

entry = s_lookup_object (self, object_id);

cml_item = ipr_xml_new (NULL, "cml", NULL);
ipr_xml_attr_set (cml_item, "version", "1.0");
ipr_xml_attr_set (cml_item, "xmlns", "http://www.openamq.org/schema/cml");

cur_item = ipr_xml_new (cml_item, name, NULL);
ipr_xml_attr_set (cur_item, "class",  entry->class_ref->name);
ipr_xml_attr_set (cur_item, "object", icl_shortstr_fmt (strvalue, "%d", object_id));
ipr_xml_attr_set (cur_item, "status", "ok");
if (notice)
    ipr_xml_attr_set (cur_item, "notice", notice);

if (fields) {
    field = asl_field_list_first (fields);
    while (field) {
        sub_item = ipr_xml_new (cur_item, "field", NULL);
        ipr_xml_attr_set (sub_item, "name", field->name);
        val_item = ipr_xml_new (sub_item, NULL, asl_field_string (field));
        ipr_xml_unlink (&val_item);
        ipr_xml_unlink (&sub_item);
        field = asl_field_list_next (&field);
    }
}
s_reply_xml (request, cml_item);
ipr_xml_unlink  (&cur_item);
ipr_xml_destroy (&cml_item);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_12))
    icl_stats_inc ("amq_console_agent_unnamed_12", &s_amq_console_agent_unnamed_12_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_reply_error (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_REPLY_ERROR))
    icl_stats_inc ("amq_console_agent_reply_error", &s_amq_console_agent_reply_error_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{


#define self tcb->amq_console
char *
    name;
char *
    status;
amq_content_basic_t *
    request;
qbyte
    object_id;

    name = reply_error_m->name;
    status = reply_error_m->status;
    request = reply_error_m->request;
    object_id = reply_error_m->object_id;
        {
ipr_xml_t
    *cml_item,                      //  CML item
    *cur_item;                      //  Top level object
icl_shortstr_t
    strvalue;                       //  Stringified numeric value
amq_console_entry_t
    *entry;                         //  Object store entry

entry = s_lookup_object (self, object_id);
cml_item = ipr_xml_new (NULL, "cml", NULL);
ipr_xml_attr_set (cml_item, "version", "1.0");
ipr_xml_attr_set (cml_item, "xmlns", "http://www.openamq.org/schema/cml");

cur_item = ipr_xml_new (cml_item, name, NULL);
ipr_xml_attr_set (cur_item, "class",  entry->class_ref->name);
ipr_xml_attr_set (cur_item, "object", icl_shortstr_fmt (strvalue, "%d", object_id));
ipr_xml_attr_set (cur_item, "status", status);

s_reply_xml (request, cml_item);
ipr_xml_unlink  (&cur_item);
ipr_xml_destroy (&cml_item);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT)  ||  defined (BASE_STATS_AMQ_CONSOLE_AGENT_UNNAMED_14))
    icl_stats_inc ("amq_console_agent_unnamed_14", &s_amq_console_agent_unnamed_14_stats);
#endif        
#define tcb ((amq_console_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

