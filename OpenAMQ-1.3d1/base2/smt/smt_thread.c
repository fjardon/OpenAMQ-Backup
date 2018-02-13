/*---------------------------------------------------------------------------
    smt_thread.c - smt_thread component

    The smt_thread class manipulates SMT threads.
    For SMT internal use only.
    Generated from smt_thread.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "smt_thread.h"                 //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_thread_t

//  Shorthands for class methods                                               

#define self_new            smt_thread_new
#define self_annihilate     smt_thread_annihilate
#define self_free           smt_thread_free
#define self_share          smt_thread_share
#define self_watch          smt_thread_watch
#define self_show           smt_thread_show
#define self_clear_method_queue  smt_thread_clear_method_queue
#define self_method_accept  smt_thread_method_accept
#define self_reply_backlog  smt_thread_reply_backlog
#define self_insert_into_waiting_list  smt_thread_insert_into_waiting_list
#define self_waiting_list_pop  smt_thread_waiting_list_pop
#define self_wake           smt_thread_wake
#define self_activate       smt_thread_activate
#define self_activity       smt_thread_activity
#define self_continue       smt_thread_continue
#define self_purge          smt_thread_purge
#define self_shut_down      smt_thread_shut_down
#define self_shut_down_all_newborn  smt_thread_shut_down_all_newborn
#define self_position_push  smt_thread_position_push
#define self_position_pop   smt_thread_position_pop
#define self_set_next_event  smt_thread_set_next_event
#define self_raise_exception  smt_thread_raise_exception
#define self_exception_raised  smt_thread_exception_raised
#define self_error          smt_thread_error
#define self_selftest       smt_thread_selftest
#define self_initialise     smt_thread_initialise
#define self_terminate      smt_thread_terminate
#define self_remove_from_all_containers  smt_thread_remove_from_all_containers
#define self_destroy        smt_thread_destroy
#define self_alloc          smt_thread_alloc
#define self_read_lock      smt_thread_read_lock
#define self_write_lock     smt_thread_write_lock
#define self_unlock         smt_thread_unlock
#define self_link           smt_thread_link
#define self_unlink         smt_thread_unlink
#define self_cache_initialise  smt_thread_cache_initialise
#define self_cache_purge    smt_thread_cache_purge
#define self_cache_terminate  smt_thread_cache_terminate
#define self_animate        smt_thread_animate
#define self_new_in_scope   smt_thread_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_NEW))
static icl_stats_t *s_smt_thread_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_DESTROY))
static icl_stats_t *s_smt_thread_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_FREE))
static icl_stats_t *s_smt_thread_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SHARE))
static icl_stats_t *s_smt_thread_share_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_WATCH))
static icl_stats_t *s_smt_thread_watch_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SHOW))
static icl_stats_t *s_smt_thread_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_CLEAR_METHOD_QUEUE))
static icl_stats_t *s_smt_thread_clear_method_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_METHOD_ACCEPT))
static icl_stats_t *s_smt_thread_method_accept_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_REPLY_BACKLOG))
static icl_stats_t *s_smt_thread_reply_backlog_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_INSERT_INTO_WAITING_LIST))
static icl_stats_t *s_smt_thread_insert_into_waiting_list_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_WAITING_LIST_POP))
static icl_stats_t *s_smt_thread_waiting_list_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_WAKE))
static icl_stats_t *s_smt_thread_wake_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_ACTIVATE))
static icl_stats_t *s_smt_thread_activate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_ACTIVITY))
       icl_stats_t *s_smt_thread_activity_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_CONTINUE))
static icl_stats_t *s_smt_thread_continue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_PURGE))
static icl_stats_t *s_smt_thread_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SHUT_DOWN))
static icl_stats_t *s_smt_thread_shut_down_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SHUT_DOWN_ALL_NEWBORN))
static icl_stats_t *s_smt_thread_shut_down_all_newborn_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_POSITION_PUSH))
static icl_stats_t *s_smt_thread_position_push_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_POSITION_POP))
static icl_stats_t *s_smt_thread_position_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SET_NEXT_EVENT))
static icl_stats_t *s_smt_thread_set_next_event_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_RAISE_EXCEPTION))
static icl_stats_t *s_smt_thread_raise_exception_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_EXCEPTION_RAISED))
static icl_stats_t *s_smt_thread_exception_raised_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_ERROR))
static icl_stats_t *s_smt_thread_error_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SELFTEST))
static icl_stats_t *s_smt_thread_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_INITIALISE))
static icl_stats_t *s_smt_thread_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_TERMINATE))
static icl_stats_t *s_smt_thread_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_smt_thread_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_DESTROY_PUBLIC))
static icl_stats_t *s_smt_thread_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_ALLOC))
static icl_stats_t *s_smt_thread_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_READ_LOCK))
static icl_stats_t *s_smt_thread_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_WRITE_LOCK))
static icl_stats_t *s_smt_thread_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_UNLOCK))
static icl_stats_t *s_smt_thread_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_LINK))
static icl_stats_t *s_smt_thread_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_UNLINK))
static icl_stats_t *s_smt_thread_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_CACHE_INITIALISE))
static icl_stats_t *s_smt_thread_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_CACHE_PURGE))
static icl_stats_t *s_smt_thread_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_CACHE_TERMINATE))
static icl_stats_t *s_smt_thread_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_ANIMATE))
static icl_stats_t *s_smt_thread_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_NEW_IN_SCOPE))
static icl_stats_t *s_smt_thread_new_in_scope_stats = NULL;
#endif
#define smt_thread_annihilate(self)     smt_thread_annihilate_ (self, __FILE__, __LINE__)
static void
    smt_thread_annihilate_ (
smt_thread_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define smt_thread_free(self)           smt_thread_free_ (self, __FILE__, __LINE__)
static void
    smt_thread_free_ (
smt_thread_t * self,                    //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    smt_thread_terminate (
void);

#define smt_thread_alloc()              smt_thread_alloc_ (__FILE__, __LINE__)
static smt_thread_t *
    smt_thread_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_thread_cache_initialise (
void);

static void
    smt_thread_cache_purge (
void);

static void
    smt_thread_cache_terminate (
void);

Bool
    smt_thread_animating = TRUE;        //  Animation enabled by default
static Bool
    s_smt_thread_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_smt_thread_mutex       = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


//  Global variables local to this source file.                                

static volatile smt_thread_id_t
    s_last_thread_id   = 0;             //  Incrementing number of last id     
static smt_thread_list_t
    *s_thread_newborn_list;             //  List of newborn threads

//  Function prototypes                                                        

static int 
    s_method_queue_trigger (void *data, smt_method_queue_notify_t event);
/*  -------------------------------------------------------------------------
    smt_thread_new

    Type: Component method
    Creates and initialises a new smt_thread_t object, returns a
    reference to the created object.
    Initialises the new item to be a valid list item.
    Initialises the new item to be a valid list item.
    Initialises the new item to be a valid list item.
    This method is for internal use only.
    -------------------------------------------------------------------------
 */

smt_thread_t *
    smt_thread_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    smt_thread_p_fn * manager,          //  The thread's manager function
    smt_thread_fn * catcher,            //  The thread's catcher function
    smt_thread_fn * destructor          //  The thread's destructor function
)
{
#if (defined (BASE_STATS) || defined (BASE_STATS_SMT_THREAD))
#   define BUFFER_LENGTH 64
    char
        buffer[BUFFER_LENGTH];;
    uint
        length = 0;
#endif
    smt_thread_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_NEW))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" manager=\"%pp\""
" catcher=\"%pp\""
" destructor=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, manager, catcher, destructor);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_NEW))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_NEW))
    icl_stats_inc ("smt_thread_new", &s_smt_thread_new_stats);
#endif

if (!s_smt_thread_active)
    self_initialise ();
    self = smt_thread_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_THREAD_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_THREAD)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_thread_show_);
#endif

self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
self->queue_next = self;
self->queue_prev = self;
self->queue_head = NULL;
self->by_status_next = self;
self->by_status_prev = self;
self->by_status_head = NULL;
    self->id = icl_atomic_inc32 (&s_last_thread_id) + 1;
    if (self->id == 0)
        self->id = icl_atomic_inc32 (&s_last_thread_id) + 1;

#if defined (BASE_THREADSAFE)
    self->os_thread           = NULL;
    self->poll_tag            = 0;
#else
    self->os_thread           = smt_os_thread;
    self->poll_tag            = smt_os_thread->last_poll_tag;
#endif
    self->manager             = manager;
    self->catcher             = catcher;
    self->destructor          = destructor;
    self->priority            = SMT_PRIORITY_NORMAL;
    self->place               = 0;
    self->module              = 0;
    self->method              = NULL;
    self->_next_event         = SMT_NULL_EVENT;
    self->_exception_event    = SMT_NULL_EVENT;
    self->_exception_raised   = FALSE;
    self->animate             = TRUE;
    self->shutting_down       = FALSE;
    self->shutdown_request    = FALSE;
    self->signal_list         = NULL;
    self->signal_raised       = FALSE;
    self->signal_event        = SMT_NULL_EVENT;
    self->status              = SMT_THREAD_NEWBORN;
    self->schedule            = SMT_SCHEDULE_NORMAL;
    self->context             = NULL;
    self->result              = 0;
    self->error               = 0;
    self->monitor             = NULL;
    self->pending_count       = 0;
    self->reply_queue         = smt_method_queue_new  ();
    self->reply_list          = smt_method_list_new   ();
    self->reply_backlog       = 0;
    self->position_stack      = smt_position_list_new ();
    self->watched_thread      = NULL;
    self->watching_thread     = NULL;
    self->timer_request_list  = smt_timer_request_by_thread_new  ();
    self->socket_request_list = smt_socket_request_by_thread_new ();
    self->write_request       = NULL;
    self->event_name          = NULL;
    self->trace               = NULL;

#   if (defined (BASE_STATS) || defined (BASE_STATS_SMT_THREAD))
    length = apr_snprintf (buffer, BUFFER_LENGTH, "smt_thread %s", file);

    apr_snprintf (buffer + length, BUFFER_LENGTH - length, " method_same_os_thread");
    self->method_same_os_thread_stat = icl_stats_new (buffer);

    apr_snprintf (buffer + length, BUFFER_LENGTH - length, " method_other_os_thread");
    self->method_other_os_thread_stat = icl_stats_new (buffer);
#   endif

    smt_thread_list_queue  (s_thread_newborn_list, self);

    //  Set trigger last so that thread doesn't start before we're ready    
    smt_method_queue_register  (self->reply_queue, s_method_queue_trigger, self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_NEW))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_NEW))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" manager=\"%pp\""
" catcher=\"%pp\""
" destructor=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, manager, catcher, destructor, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    smt_thread_annihilate

    Type: Component method
    This method is for internal use only.
    -------------------------------------------------------------------------
 */

static void
    smt_thread_annihilate_ (
    smt_thread_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_THREAD)
    int
        history_last;
#endif

smt_method_queue_t
    *reply_queue_link;
    smt_thread_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_DESTROY))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_DESTROY))
    icl_trace_record (*self_p?(*self_p)->trace:NULL, smt_thread_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_DESTROY))
    icl_stats_inc ("smt_thread_annihilate", &s_smt_thread_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_THREAD)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % SMT_THREAD_HISTORY_LENGTH] = file;
    self->history_line  [history_last % SMT_THREAD_HISTORY_LENGTH] = line;
    self->history_type  [history_last % SMT_THREAD_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % SMT_THREAD_HISTORY_LENGTH] = self->links;
#endif

    SMT_THREAD_ASSERT_SANE (self);
    smt_thread_remove_from_all_containers (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

//  Dump trace if there is one
if (self->trace)
    icl_trace_dump (self->trace);

if (self->destructor)
    (self->destructor) (self);

icl_atomic_set32 (&self->status, SMT_THREAD_ZOMBIE);

//  Stop watching them
if (self->watched_thread) {
    self->watched_thread->watching_thread = NULL;
    self->watched_thread = NULL;
}
//  Stop watching us
if (self->watching_thread) {
    self->watching_thread->watched_thread = NULL;
    self->watching_thread = NULL;
}

//  Get rid of method
smt_method_destroy (&self->method);

//  If any signals are registered with us, deregister them.
smt_signal_by_thread_destroy (&self->signal_list);

smt_position_list_destroy (&self->position_stack);

//  Just destroying the timer request list isn't enough because the
//  requests will remain in the per-os thread list and still be 
//  triggered.
smt_thread_purge (self);

smt_timer_request_by_thread_destroy  (&self->timer_request_list);
smt_socket_request_by_thread_destroy (&self->socket_request_list);

//  Force reply queue to be destroyed in two stages so that other          
//  other threads don't try to access a NULL pointer.                      

//  We won't be requiring notification.                                    
smt_method_queue_register (self->reply_queue, NULL, NULL);

//  Keep a link to the zombified queue so that other threads can
//  detect that we're gone.    
reply_queue_link = smt_method_queue_link (self->reply_queue);
smt_method_queue_destroy (&reply_queue_link);

smt_method_list_destroy (&self->reply_list);

smt_os_thread_remove_thread (self);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_DESTROY))
    icl_trace_record (*self_p?(*self_p)->trace:NULL, smt_thread_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_DESTROY))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_destroy_finish"
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

}
/*  -------------------------------------------------------------------------
    smt_thread_free

    Type: Component method
    Freess a smt_thread_t object.
    -------------------------------------------------------------------------
 */

static void
    smt_thread_free_ (
    smt_thread_t * self,                //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_THREAD)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_FREE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_FREE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_FREE))
    icl_stats_inc ("smt_thread_free", &s_smt_thread_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_THREAD)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_THREAD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_THREAD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_THREAD_HISTORY_LENGTH] = "free";
        self->history_links [history_last % SMT_THREAD_HISTORY_LENGTH] = self->links;
#endif

//  finally allow the reply queue to be freed.                             
smt_method_queue_unlink (&self->reply_queue);

//  Save trace destruction until free so it is still available on leak.
icl_trace_destroy (&self->trace);
#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        self->object_tag = SMT_THREAD_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_FREE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_FREE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_free_finish"
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
    smt_thread_share

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    Implement thread sharing by setting the OS thread of the new thread to
    that of the share thread, assigning its context block, and incrementing
    the context block link count.
    -------------------------------------------------------------------------
 */

int
    smt_thread_share (
    smt_thread_t * self,                //  Reference to object
    smt_thread_t * share                //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_SHARE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_share_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" share=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, share);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SHARE))
    icl_trace_record (NULL, smt_thread_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SHARE))
    icl_stats_inc ("smt_thread_share", &s_smt_thread_share_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

self->os_thread = share->os_thread;
self->poll_tag  = share->poll_tag;
self->context   = share->context;
(* (int *) self->context)++;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SHARE))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_SHARE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_share_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" share=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, share, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_thread_watch

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    A simple form of load-balancing is performed by allowing a thread to
    "watch" another thread (which must be in the same OS thread).  If the
    watched thread has outstanding socket requests then the sockets will be
    polled regularly when the watching thread received incoming methods.
    
    Note that a thread is always "watching" itself, but that this can be
    insufficient if a different thread is processing incoming socket data.
    
    Note that a thread can only watch one other thread, and can only be watched
    by one other thread.
    -------------------------------------------------------------------------
 */

int
    smt_thread_watch (
    smt_thread_t * self,                //  Reference to object
    smt_thread_t * watch                //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_WATCH))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_watch_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" watch=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, watch);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_WATCH))
    icl_trace_record (NULL, smt_thread_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_WATCH))
    icl_stats_inc ("smt_thread_watch", &s_smt_thread_watch_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

//  If we are watching another thread then stop watching it.
if (self->watched_thread)
    self->watched_thread->watching_thread = NULL;

self->watched_thread = watch;
watch->watching_thread = self;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_WATCH))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_WATCH))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_watch_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" watch=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, watch, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_thread_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_thread_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_thread_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_THREAD)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_SHOW))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SHOW))
    icl_trace_record (NULL, smt_thread_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SHOW))
    icl_stats_inc ("smt_thread_show", &s_smt_thread_show_stats);
#endif

self = item;
container_links = 0;
if (self->by_status_head)
   container_links++;
if (self->queue_head)
   container_links++;
if (self->list_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <smt_thread zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_THREAD)
    if (self->history_last > SMT_THREAD_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % SMT_THREAD_HISTORY_LENGTH;
        self->history_last %= SMT_THREAD_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % SMT_THREAD_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </smt_thread>\n");
#endif

    if (self->trace) {
        icl_console_redirect (trace_file);
        icl_trace_dump (self->trace);
        icl_console_redirect (NULL);
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SHOW))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_SHOW))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_show_finish"
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
    smt_thread_clear_method_queue

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    This method takes incoming methods from the reply queue, sorts them by
    priority and inserts them into the reply list.
    
    It may only be called from the thread's OS thread.
    -------------------------------------------------------------------------
 */

int
    smt_thread_clear_method_queue (
    smt_thread_t * self                 //  Reference to object
)
{
smt_method_t
    *method,
    *search,
    *after;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_CLEAR_METHOD_QUEUE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_clear_method_queue_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_CLEAR_METHOD_QUEUE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_CLEAR_METHOD_QUEUE))
    icl_stats_inc ("smt_thread_clear_method_queue", &s_smt_thread_clear_method_queue_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    assert (apr_os_thread_current () == self->os_thread->apr_os_thread);
#endif
    //  JS: We could improve this in a number of ways...
    //      It isn't even required for a ST build.
    method = smt_method_queue_pop (self->reply_queue);

    //  Perform a crude load-balance by polling if there are any incoming
    //  methods.
    //  JS: zombie test could be eliminated by splitting purge from destroy
    //      of thread's socket request list.
    if (method
    &&  self->poll_tag == self->os_thread->last_poll_tag
    && (! smt_socket_request_by_thread_isempty (self->socket_request_list)
    || (  self->watched_thread
    &&  ! self->watched_thread->zombie
    &&  ! smt_socket_request_by_thread_isempty (self->watched_thread->socket_request_list)))) {
        self->os_thread->last_poll_tag++;
        rc = smt_socket_request_poll (self->os_thread, TRUE);
    }

    while (method) {
        after = NULL;
        search = smt_method_list_last (self->reply_list);
        //  NB priority order is reversed...
        while (search && method->priority < search->priority) {
            after = search;
            search = smt_method_list_prev (&search);
        }
        if (after)
            smt_method_list_relink_before (method, after);
        else
            smt_method_list_queue (self->reply_list, method);
        self->reply_backlog++;

        smt_method_unlink (&search);
        smt_method_unlink (&method);    

        method = smt_method_queue_pop (self->reply_queue);
    }
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_CLEAR_METHOD_QUEUE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_CLEAR_METHOD_QUEUE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_clear_method_queue_finish"
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
    smt_thread_method_accept

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    Accepts an method from a thread's method queue, if there are any.
    The method event is delivered along with its result code (to 
    thread->result).
    
    If there was no method, the thread is sent to sleep.
    
    The method returns SMT_OK or SMT_EMPTY.
    
    This method is called by the dialog manager.  It should not
    be called by application code.
    -------------------------------------------------------------------------
 */

int
    smt_thread_method_accept (
    smt_thread_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_METHOD_ACCEPT))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_method_accept_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_METHOD_ACCEPT))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_METHOD_ACCEPT))
    icl_stats_inc ("smt_thread_method_accept", &s_smt_thread_method_accept_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

//  Should never be called if there are pending socket/timer requests  
assert (self->pending_count == 0);

smt_thread_clear_method_queue (self);

//  Now actually grab the method
smt_method_destroy (&self->method);
self->method = smt_method_list_pop (self->reply_list);
if (self->method) {
    //  Get everything ready to go    
    self->reply_backlog--;
    smt_thread_set_next_event (self, self->method->event);
    self->result = self->method->result;
    if (self->result != SMT_OK)
        self->catcher (self);
}
else
    rc = SMT_EMPTY;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_METHOD_ACCEPT))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_METHOD_ACCEPT))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_method_accept_finish"
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
    smt_thread_reply_backlog

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    This method returns the amount of methods left to process in the threadlet's
    reply list.
    -------------------------------------------------------------------------
 */

qbyte
    smt_thread_reply_backlog (
    smt_thread_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code
    qbyte
        backlog = 0;                    //  The backlog

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_REPLY_BACKLOG))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_reply_backlog_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_REPLY_BACKLOG))
    icl_trace_record (NULL, smt_thread_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_REPLY_BACKLOG))
    icl_stats_inc ("smt_thread_reply_backlog", &s_smt_thread_reply_backlog_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

rc = 0;
backlog = icl_atomic_get32 (&self->reply_backlog);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_REPLY_BACKLOG))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_REPLY_BACKLOG))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_reply_backlog_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
" backlog=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc, backlog);
#endif


    return (backlog);
}
/*  -------------------------------------------------------------------------
    smt_thread_insert_into_waiting_list

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    This method insert a threadlet into its OS thread's waiting list according
    to the thread's priority.
    -------------------------------------------------------------------------
 */

int
    smt_thread_insert_into_waiting_list (
    smt_thread_t * self                 //  Reference to object
)
{
smt_os_thread_t *
    os_thread = self->os_thread;
smt_thread_t *
    insert_point = NULL;
smt_priority_t
    priority_index;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_INSERT_INTO_WAITING_LIST))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_insert_into_waiting_list_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_INSERT_INTO_WAITING_LIST))
    icl_trace_record (NULL, smt_thread_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_INSERT_INTO_WAITING_LIST))
    icl_stats_inc ("smt_thread_insert_into_waiting_list", &s_smt_thread_insert_into_waiting_list_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    assert (apr_os_thread_current () == os_thread->apr_os_thread);
#endif
    //  Test first that the thread isn't already in the waiting list.
    if (self->by_status_head == NULL) {
        if (self->priority < SMT_PRIORITY_LAST)
            insert_point = os_thread->waiting_list_entry [self->priority];

        if (insert_point)
            smt_thread_by_status_relink_before (self, insert_point);
        else
            smt_thread_by_status_queue (os_thread->waiting_list, self);

        //  Adjust insertion points for higher priority
        if (self->priority > 0) {
            priority_index = self->priority - 1;
            while (os_thread->waiting_list_entry [priority_index] == NULL
               ||  os_thread->waiting_list_entry [priority_index]->priority > self->priority) {
                os_thread->waiting_list_entry [priority_index] = self;
                if (priority_index > 0)
                    priority_index--;
                else
                    break;
            }
        }
    }
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_INSERT_INTO_WAITING_LIST))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_INSERT_INTO_WAITING_LIST))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_insert_into_waiting_list_finish"
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
    smt_thread_waiting_list_pop

    Type: Component method
    Pops a thread from a waiting list, maintaining the after pointers for rapid
    insertion by priority.
    
    NB: For optimisation reasons, this function returns a thread pointer, but
        NO LINK to the thread object.
    -------------------------------------------------------------------------
 */

smt_thread_t *
    smt_thread_waiting_list_pop (
    smt_os_thread_t * os_thread         //  The OS thread
)
{
smt_thread_t
    *next_thread;
smt_priority_t
    priority_index;
    smt_thread_t *
        self;                           //  The threadlet

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_WAITING_LIST_POP))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_waiting_list_pop_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" os_thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, os_thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_WAITING_LIST_POP))
    icl_trace_record (NULL, smt_thread_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_WAITING_LIST_POP))
    icl_stats_inc ("smt_thread_waiting_list_pop", &s_smt_thread_waiting_list_pop_stats);
#endif

#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    assert (apr_os_thread_current () == os_thread->apr_os_thread);
#endif
    self = smt_thread_by_status_pop (os_thread->waiting_list);
    if (self) {
        next_thread = smt_thread_by_status_first (os_thread->waiting_list);

        //  Adjust insertion points for higher priority
        priority_index = self->priority;
        while (priority_index > 0) {
            priority_index--;
            os_thread->waiting_list_entry [priority_index] = next_thread;
        }
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_WAITING_LIST_POP))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_WAITING_LIST_POP))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_waiting_list_pop_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" os_thread=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, os_thread, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    smt_thread_wake

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    This method is used to force a thread to wake.  It can be used to
    interrupt monitor requests and to force a thread to shut down.
    
    The method may be called from an OS thread other than the one in which
    the thread is being processed.
    -------------------------------------------------------------------------
 */

int
    smt_thread_wake (
    smt_thread_t * self                 //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    smt_os_thread_t
        *os_thread;
#endif
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_WAKE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_wake_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_WAKE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_WAKE))
    icl_stats_inc ("smt_thread_wake", &s_smt_thread_wake_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    if (icl_atomic_cas32 (
            &self->status, SMT_THREAD_WAITING, SMT_THREAD_SLEEPING) == SMT_THREAD_SLEEPING
    ||  icl_atomic_cas32 (
            &self->status, SMT_THREAD_WAKING,  SMT_THREAD_POLLING)  == SMT_THREAD_POLLING
    ||  icl_atomic_cas32 (
            &self->status, SMT_THREAD_WAITING, SMT_THREAD_PENDING)  == SMT_THREAD_PENDING) {
        os_thread = self->os_thread;

        smt_thread_queue_queue (os_thread->thread_queue, self);
        smt_os_thread_wake (os_thread);     //  Wake the OS thread
    }
    else
    if (icl_atomic_cas32 (
            &self->status, SMT_THREAD_WAITING, SMT_THREAD_NEWBORN) == SMT_THREAD_NEWBORN) {
        os_thread = self->os_thread;
        if (!os_thread)
            os_thread = smt_os_thread_assign (self, NULL, self->schedule);
        smt_thread_queue_queue (os_thread->thread_queue, self);
        smt_os_thread_wake (os_thread);     //  Wake the OS thread
    }
    else
        rc = -1;
#else        
    if (self->status == SMT_THREAD_NEWBORN
    ||  self->status == SMT_THREAD_SLEEPING) {
        self->status = SMT_THREAD_WAITING;

        smt_thread_insert_into_waiting_list (self);
        smt_os_thread_wake (smt_os_thread);     //  Wake the OS thread
    }
    else
    if (self->status == SMT_THREAD_POLLING) {
        self->status = SMT_THREAD_WAKING;

        icl_apr_assert (apr_pollset_add (smt_os_thread->waking_pollset, &self->monitor->socket->pollfd));

        //  Threadlet can go straight to waking list
        smt_thread_by_status_queue (smt_os_thread->waking_list, self);
        smt_os_thread_wake (smt_os_thread);     //  Wake the OS thread
    }
    else
    if (self->status == SMT_THREAD_PENDING) {
        self->status = SMT_THREAD_WAITING;

        if (self->monitor) {
            icl_apr_assert (apr_pollset_add (smt_os_thread->waking_pollset, &self->monitor->socket->pollfd));

            //  Threadlet can go straight to waking list
            smt_thread_by_status_queue (smt_os_thread->waking_list, self);
        }
        else
            smt_thread_insert_into_waiting_list (self);

        smt_os_thread_wake (smt_os_thread);     //  Wake the OS thread
    }
    else
        rc = -1;
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_WAKE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_WAKE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_wake_finish"
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
    smt_thread_activate

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    This method is used by smt_socket_request and smt_timer_request to
    immediately activate a thread.  In other words the thread is made
    active regardless of its prior status (except SMT_THREAD_ZOMBIE).

    This method assumes that the thread has already been given work to do.
    
    This method may only be called from the thread's OS thread.
    -------------------------------------------------------------------------
 */

int
    smt_thread_activate (
    smt_thread_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_ACTIVATE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_activate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_ACTIVATE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_ACTIVATE))
    icl_stats_inc ("smt_thread_activate", &s_smt_thread_activate_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

    assert (self->os_thread);
    assert (!self->monitor);
#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    assert (apr_os_thread_current () == self->os_thread->apr_os_thread);
#endif
    //  Test that thread isn't already active; no race condition possible.
    if (self->status != SMT_THREAD_ACTIVE) {
        icl_atomic_set32 (&self->status, SMT_THREAD_WAITING);

        smt_thread_by_status_remove (self);             //  From waking list
        smt_thread_insert_into_waiting_list (self);
    }
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_ACTIVATE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_ACTIVATE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_activate_finish"
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
    smt_thread_continue

    Type: Component method
    This method works out what to do with a thread after it has been active.
    
    It may only be called from the thread's OS thread.
    -------------------------------------------------------------------------
 */

void
    smt_thread_continue (
    smt_thread_t * self                 //  Not documented
)
{
smt_method_t
    *method;
smt_priority_t
    priority;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_CONTINUE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_continue_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_CONTINUE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_CONTINUE))
    icl_stats_inc ("smt_thread_continue", &s_smt_thread_continue_stats);
#endif

    assert (self->os_thread);
#if (defined (BASE_THREADSAFE))
#   if (defined (DEBUG))
    assert (apr_os_thread_current () == self->os_thread->apr_os_thread);
#   endif
    //  If thread is already queued, leave it be.
    if (!self->by_status_head) {
        //  If thread is pending then let it go
        if (self->pending_count
        && !self->shutdown_request          //  Shutdown overrides pending
        && !self->signal_raised)            //  Signal overrides pending
            //  Pending can only be resolved from same OS thread, so no race here
            icl_atomic_cas32 (&self->status, SMT_THREAD_PENDING, SMT_THREAD_ACTIVE);
        else
        if (smt_thread_activity (self)) {
            if (self->module == SMT_TERM_MODULE
            &&  self->monitor) {
                //  Monitor can only be resolved from same OS thread, so no race

                //  Check for priority on incoming method
                smt_thread_clear_method_queue (self);
                method = smt_method_list_first (self->reply_list);
                priority = method ? method->priority : SMT_PRIORITY_NORMAL;
                smt_method_unlink (&method);

                //  Note that priority order is reversed...
                if (priority < SMT_PRIORITY_NORMAL) {
                    if (icl_atomic_cas32 (
                        &self->status, SMT_THREAD_WAITING, SMT_THREAD_ACTIVE) == SMT_THREAD_ACTIVE) {
                        smt_socket_request_destroy (&self->monitor);
                        smt_thread_insert_into_waiting_list (self);
                    }
                }
                else {
                    if (icl_atomic_cas32 (
                        &self->status, SMT_THREAD_WAKING, SMT_THREAD_ACTIVE) == SMT_THREAD_ACTIVE) {
                        smt_thread_by_status_queue (self->os_thread->waking_list, self);
                        icl_apr_assert (apr_pollset_add (self->os_thread->waking_pollset, &self->monitor->socket->pollfd));
                    }
                }
            }
            else {
                if (icl_atomic_cas32 (
                    &self->status, SMT_THREAD_WAITING, SMT_THREAD_ACTIVE) == SMT_THREAD_ACTIVE)
                    smt_thread_insert_into_waiting_list (self);
            }
        }
        else {
            if (self->module == SMT_TERM_MODULE 
            &&  self->monitor) {
                //  Race condition can occur if an incoming event arrives now
                if (icl_atomic_cas32 (
                    &self->status, SMT_THREAD_POLLING, SMT_THREAD_ACTIVE) == SMT_THREAD_ACTIVE) {
                    if (smt_thread_activity (self))
                        //  Catch race condition here
                        if (icl_atomic_cas32 (&self->status, SMT_THREAD_WAKING, SMT_THREAD_POLLING) == SMT_THREAD_POLLING) {
                            smt_thread_by_status_queue (self->os_thread->waking_list, self);
                            icl_apr_assert (apr_pollset_add (self->os_thread->waking_pollset, &self->monitor->socket->pollfd));
                        }
                }
            }
            else {
                //  Race condition can occur if an incoming event arrives now
                if (icl_atomic_cas32 (
                    &self->status, SMT_THREAD_SLEEPING, SMT_THREAD_ACTIVE) == SMT_THREAD_ACTIVE) {
                    if (smt_thread_activity (self))
                        //  Catch race condition here
                        if (icl_atomic_cas32 (&self->status, SMT_THREAD_WAITING, SMT_THREAD_SLEEPING) == SMT_THREAD_SLEEPING)
                            smt_thread_insert_into_waiting_list (self);
                }
            }
        }
    }
#else
    if (self->pending_count
    && !self->shutdown_request          //  Shutdown overrides pending
    && !self->signal_raised) {          //  Signal overrides pending
        icl_atomic_set32 (&self->status, SMT_THREAD_PENDING);
        smt_thread_by_status_remove (self);
    }
    else
    if (smt_thread_activity (self)) {
        if (self->module == SMT_TERM_MODULE
        &&  self->monitor) {
            //  Check for priority on incoming method
            smt_thread_clear_method_queue (self);
            method = smt_method_list_first (self->reply_list);
            priority = method ? method->priority : SMT_PRIORITY_NORMAL;
            smt_method_unlink (&method);

            //  Note that priority order is reversed...
            if (priority < SMT_PRIORITY_NORMAL) {
                smt_socket_request_destroy (&self->monitor);
                if (self->status == SMT_THREAD_ACTIVE) {
                    self->status = SMT_THREAD_WAITING;
                    smt_thread_insert_into_waiting_list (self);
                }
            }
            else {
                if (self->status == SMT_THREAD_ACTIVE) {
                    self->status = SMT_THREAD_WAKING;
                    smt_thread_by_status_queue (smt_os_thread->waking_list, self);
                    icl_apr_assert (apr_pollset_add (self->os_thread->waking_pollset, &self->monitor->socket->pollfd));
                }
            }
        }
        else {
            if (self->status == SMT_THREAD_ACTIVE) {
                self->status = SMT_THREAD_WAITING;
                smt_thread_insert_into_waiting_list (self);
            }
        }
    }
    else {
        if (self->module == SMT_TERM_MODULE
        &&  self->monitor) {
            if (self->status == SMT_THREAD_ACTIVE)
                self->status = SMT_THREAD_POLLING;
        }
        else
            if (self->status == SMT_THREAD_ACTIVE)
                self->status = SMT_THREAD_SLEEPING;
    }
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_CONTINUE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_CONTINUE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_continue_finish"
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

}
/*  -------------------------------------------------------------------------
    smt_thread_purge

    Type: Component method
    Purges all socket and timer requests for a given thread.
    
    Don't use 'function' template since it needs to be called with a zombie
    object.
    
    This method may only be called from the thread's OS thread and is for
    internal use only.
    -------------------------------------------------------------------------
 */

int
    smt_thread_purge (
    smt_thread_t * self                 //  Reference to object
)
{
smt_socket_request_t
    *socket_request;
//  We increment pending count so that purging socket and timer
smt_timer_request_t
    *timer_request;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_PURGE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_purge_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_PURGE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_PURGE))
    icl_stats_inc ("smt_thread_purge", &s_smt_thread_purge_stats);
#endif

    SMT_THREAD_ASSERT_SANE (self);

    //  Possible that thread is purged before it has even started.
    if (self->os_thread) {

#if (defined (BASE_THREADSAFE) && defined (DEBUG))
        assert (apr_os_thread_current () == self->os_thread->apr_os_thread);
#endif

        self->monitor = NULL;

        //  Purge socket requests
        socket_request = smt_socket_request_by_thread_first (self->socket_request_list);
        while (socket_request) {
            smt_socket_request_destroy (&socket_request);
            socket_request = smt_socket_request_by_thread_first (self->socket_request_list);
        }

        //  Purge timer requests
        timer_request = smt_timer_request_by_thread_first (self->timer_request_list);
        while (timer_request) {
            smt_timer_request_destroy (&timer_request);
            timer_request = smt_timer_request_by_thread_first (self->timer_request_list);
        }
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_PURGE))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_PURGE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_purge_finish"
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
    smt_thread_shut_down

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    Requests thread to shut down.
    -------------------------------------------------------------------------
 */

int
    smt_thread_shut_down (
    smt_thread_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_SHUT_DOWN))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_shut_down_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" id=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self->id);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SHUT_DOWN))
    icl_trace_record (NULL, smt_thread_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SHUT_DOWN))
    icl_stats_inc ("smt_thread_shut_down", &s_smt_thread_shut_down_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

self->shutdown_request = TRUE;
smt_thread_wake (self);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SHUT_DOWN))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_SHUT_DOWN))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_shut_down_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
" id=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc, self->id);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_thread_shut_down_all_newborn

    Type: Component method
    Requests all threads to shut down.
    -------------------------------------------------------------------------
 */

void
    smt_thread_shut_down_all_newborn (
void)
{
#if (defined (BASE_THREADSAFE))
    smt_thread_t
        *thread,
        *next_thread;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_SHUT_DOWN_ALL_NEWBORN))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_shut_down_all_newborn_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SHUT_DOWN_ALL_NEWBORN))
    icl_trace_record (NULL, smt_thread_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SHUT_DOWN_ALL_NEWBORN))
    icl_stats_inc ("smt_thread_shut_down_all_newborn", &s_smt_thread_shut_down_all_newborn_stats);
#endif

    //  Request shut-down all the sleeping threads that haven't been 
    //  assigned an OS thread, ie the newborn threads.  Need to grab next
    //  thread from list before starting the thread because the thread will
    //  become volatile once it has started.
#if (defined (BASE_THREADSAFE))
    thread = smt_thread_list_first (s_thread_newborn_list);
    while (thread) {
        next_thread = smt_thread_link (thread);
        next_thread = smt_thread_list_next (&next_thread);
        if (!thread->os_thread
        ||  thread->list_head != thread->os_thread->thread_list) {
            smt_thread_shut_down (thread);
            smt_thread_wake (thread);       //  To start the thread
        }
        smt_thread_unlink (&thread);
        thread = next_thread;
    }
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SHUT_DOWN_ALL_NEWBORN))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_SHUT_DOWN_ALL_NEWBORN))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_shut_down_all_newborn_finish"
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
    smt_thread_position_push

    Type: Component method
    This method pushes the current position in the dialog of a thread.
    
    This method is for internal use only.
    -------------------------------------------------------------------------
 */

void
    smt_thread_position_push (
    smt_thread_t * self                 //  Not documented
)
{
smt_position_t *position;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_POSITION_PUSH))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_position_push_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_POSITION_PUSH))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_POSITION_PUSH))
    icl_stats_inc ("smt_thread_position_push", &s_smt_thread_position_push_stats);
#endif

position = smt_position_new ();
position->place  = self->place;
position->module = self->module;
smt_position_list_push (self->position_stack, position);
smt_position_unlink (&position);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_POSITION_PUSH))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_POSITION_PUSH))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_position_push_finish"
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

}
/*  -------------------------------------------------------------------------
    smt_thread_position_pop

    Type: Component method
    This method pops the current position in the dialog of a thread.
    
    Returns SMT_OK or SMT_EMPTY.
    
    This method is for internal use only.
    -------------------------------------------------------------------------
 */

int
    smt_thread_position_pop (
    smt_thread_t * self                 //  Not documented
)
{
smt_position_t *position;
    int
        rc = SMT_OK;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_POSITION_POP))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_position_pop_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_POSITION_POP))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_POSITION_POP))
    icl_stats_inc ("smt_thread_position_pop", &s_smt_thread_position_pop_stats);
#endif

position = smt_position_list_pop (self->position_stack);
if (position == NULL)
    rc = SMT_EMPTY;
else {
    self->place  = position->place;
    self->module = position->module;
    smt_position_destroy (&position);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_POSITION_POP))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_POSITION_POP))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_position_pop_finish"
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
    smt_thread_set_next_event

    Type: Component method
    This method sets the next event for a given thread.  Note that it does
    not queue the event, but simply copies the value.
    
    This method may only be called from the thread's OS thread, unless the
    thread has yet to start.
    -------------------------------------------------------------------------
 */

void
    smt_thread_set_next_event (
    smt_thread_t * self,                //  Not documented
    smt_event_t event                   //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_SET_NEXT_EVENT))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_set_next_event_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SET_NEXT_EVENT))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SET_NEXT_EVENT))
    icl_stats_inc ("smt_thread_set_next_event", &s_smt_thread_set_next_event_stats);
#endif

#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    assert (!self->os_thread || apr_os_thread_current () == self->os_thread->apr_os_thread);
#endif
    self->_next_event = event;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SET_NEXT_EVENT))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_SET_NEXT_EVENT))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_set_next_event_finish"
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

}
/*  -------------------------------------------------------------------------
    smt_thread_raise_exception

    Type: Component method
    This method raises an exception for a given thread.
    -------------------------------------------------------------------------
 */

void
    smt_thread_raise_exception (
    smt_thread_t * self,                //  Not documented
    smt_event_t event                   //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_RAISE_EXCEPTION))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_raise_exception_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_RAISE_EXCEPTION))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_RAISE_EXCEPTION))
    icl_stats_inc ("smt_thread_raise_exception", &s_smt_thread_raise_exception_stats);
#endif

#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    assert (!self->os_thread || apr_os_thread_current () == self->os_thread->apr_os_thread);
#endif
    self->_exception_raised = TRUE;
    self->_exception_event = event;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_RAISE_EXCEPTION))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_RAISE_EXCEPTION))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_raise_exception_finish"
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

}
/*  -------------------------------------------------------------------------
    smt_thread_exception_raised

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    This method returns TRUE if the thread had an exception raised; FALSE
    otherwise.
    -------------------------------------------------------------------------
 */

int
    smt_thread_exception_raised (
    smt_thread_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_EXCEPTION_RAISED))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_exception_raised_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_EXCEPTION_RAISED))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_EXCEPTION_RAISED))
    icl_stats_inc ("smt_thread_exception_raised", &s_smt_thread_exception_raised_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

rc = self->_exception_raised;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_EXCEPTION_RAISED))
    icl_trace_record (self?self->trace:NULL, smt_thread_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_EXCEPTION_RAISED))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_exception_raised_finish"
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
    smt_thread_error

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    smt_thread_error (
    smt_thread_t * self                 //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

static icl_shortstr_t
    buffer;
icl_shortstr_t
    remote_buffer;
    char *
        text = buffer;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_ERROR))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_error_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_ERROR))
    icl_trace_record (NULL, smt_thread_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_ERROR))
    icl_stats_inc ("smt_thread_error", &s_smt_thread_error_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

switch (self->result) {
    case SMT_OK:               
        icl_shortstr_cpy (buffer, "Success");                break;
    case SMT_THREAD_ERROR:
        icl_shortstr_cpy (buffer, "Thread error (SYSTEM)");  break;
    case SMT_SLEEPING:
        icl_shortstr_cpy (buffer, "Thread sleeping (INTERNAL)"); break;
    case SMT_FINISHED:
        icl_shortstr_cpy (buffer, "Thread finished (INTERNAL)"); break;
    case SMT_BREAK:
        icl_shortstr_cpy (buffer, "Break (INTERNAL)");           break;
    case SMT_EMPTY:
        icl_shortstr_cpy (buffer, "Empty stack (INTERNAL)");     break;
    case SMT_ILLEGAL_ARGUMENT:
        icl_shortstr_cpy (buffer, "Illegal Argument");           break;
    case SMT_SELECT_ERROR:
        icl_shortstr_cpy (buffer, "Select error (INTERNAL");     break;
    case SMT_SOCKET_ERROR:
        apr_strerror (self->error, remote_buffer, ICL_SHORTSTR_MAX);
        icl_shortstr_cpy (buffer, "Socket error: ");
        icl_shortstr_cat (buffer, remote_buffer);                break;
    case SMT_SOCKET_CLOSING:
        icl_shortstr_cpy (buffer, "Socket closing");
        if (self->error != APR_SUCCESS) {
            apr_strerror (self->error, remote_buffer, ICL_SHORTSTR_MAX);
            icl_shortstr_cat (buffer, ": ");
            icl_shortstr_cat (buffer, remote_buffer);
        }
        break;
    case SMT_TIMEOUT:
        icl_shortstr_cpy (buffer, "Timeout");                    break;
    case SMT_THREAD_INVALID:
        icl_shortstr_cpy (buffer, "Invalid thread");             break;
    case SMT_FILEIO_ERROR:
        apr_strerror (self->error, remote_buffer, ICL_SHORTSTR_MAX);
        icl_shortstr_cpy (buffer, "File i/o error: ");
        icl_shortstr_cat (buffer, remote_buffer);                break;
    default:
        icl_shortstr_cpy (buffer, "Unknown error");              break;
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_ERROR))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_ERROR))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_error_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, text);
#endif


    return (text);
}
/*  -------------------------------------------------------------------------
    smt_thread_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_thread_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_SELFTEST))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SELFTEST))
    icl_trace_record (NULL, smt_thread_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_SELFTEST))
    icl_stats_inc ("smt_thread_selftest", &s_smt_thread_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_SELFTEST))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_SELFTEST))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_selftest_finish"
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
    smt_thread_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_thread_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_INITIALISE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_INITIALISE))
    icl_trace_record (NULL, smt_thread_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_INITIALISE))
    icl_stats_inc ("smt_thread_initialise", &s_smt_thread_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_smt_thread_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_smt_thread_mutex)
            s_smt_thread_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_smt_thread_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_smt_thread_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

    s_last_thread_id = 0;

    //  Newborn thread list needs to be rwlock-protected, but other thread
    //  lists are thread-local, so thread lists are defined with 
    //  dont_create_rwlock.  Here we create newborn thread list and its rwlock.
    s_thread_newborn_list         = smt_thread_list_new ();
#if (defined (BASE_THREADSAFE))
    s_thread_newborn_list->rwlock = icl_rwlock_new ();
#endif
            s_smt_thread_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_smt_thread_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_INITIALISE))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_INITIALISE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_initialise_finish"
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
    smt_thread_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_thread_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_TERMINATE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_TERMINATE))
    icl_trace_record (NULL, smt_thread_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_TERMINATE))
    icl_stats_inc ("smt_thread_terminate", &s_smt_thread_terminate_stats);
#endif

if (s_smt_thread_active) {

smt_shut_down ();                   //  So OS threads terminate
smt_wait (0);                       //  Wait for SMT to shut down

smt_thread_list_destroy (&s_thread_newborn_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_smt_thread_mutex);
#endif
        s_smt_thread_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_TERMINATE))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_TERMINATE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_terminate_finish"
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
    smt_thread_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    smt_thread_remove_from_all_containers (
    smt_thread_t * self                 //  The itemThe itemThe item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_REMOVE_FROM_ALL_CONTAINERS))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, smt_thread_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("smt_thread_remove_from_all_containers", &s_smt_thread_remove_from_all_containers_stats);
#endif

smt_thread_by_status_remove (self);
smt_thread_queue_remove (self);
smt_thread_list_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_REMOVE_FROM_ALL_CONTAINERS))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_remove_from_all_containers_finish"
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

}
/*  -------------------------------------------------------------------------
    smt_thread_destroy

    Type: Component method
    Destroys a smt_thread_t object. Takes the address of a
    smt_thread_t reference (a pointer to a pointer) and nullifies the
    reference after use.  Does nothing if the reference is already
    null.
    Performs an agressive destroy of an object.  This involves:
    1. Removing the object from any containers it is in.
    2. Making the object an zombie
    3. Decrementing the object's link count
    4. If the link count is zero then freeing the object.
    -------------------------------------------------------------------------
 */

void
    smt_thread_destroy_ (
    smt_thread_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    smt_thread_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_DESTROY_PUBLIC))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_thread_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_DESTROY_PUBLIC))
    icl_stats_inc ("smt_thread_destroy", &s_smt_thread_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        smt_thread_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on smt_thread object");
        smt_thread_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        smt_thread_free_ ((smt_thread_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_DESTROY_PUBLIC))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    smt_thread_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_thread_t *
    smt_thread_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_thread_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_ALLOC))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_ALLOC))
    icl_trace_record (NULL, smt_thread_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_ALLOC))
    icl_stats_inc ("smt_thread_alloc", &s_smt_thread_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_thread_cache_initialise ();

self = (smt_thread_t *) icl_mem_cache_alloc_ (s_cache, file, line);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_ALLOC))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_ALLOC))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_alloc_finish"
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
    smt_thread_read_lock

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_thread_read_lock (
    smt_thread_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_READ_LOCK))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_READ_LOCK))
    icl_trace_record (NULL, smt_thread_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_READ_LOCK))
    icl_stats_inc ("smt_thread_read_lock", &s_smt_thread_read_lock_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_READ_LOCK))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_READ_LOCK))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_read_lock_finish"
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
    smt_thread_write_lock

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_thread_write_lock (
    smt_thread_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_WRITE_LOCK))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_WRITE_LOCK))
    icl_trace_record (NULL, smt_thread_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_WRITE_LOCK))
    icl_stats_inc ("smt_thread_write_lock", &s_smt_thread_write_lock_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_WRITE_LOCK))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_WRITE_LOCK))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_write_lock_finish"
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
    smt_thread_unlock

    Type: Component method
    Accepts a smt_thread_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_thread_unlock (
    smt_thread_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_UNLOCK))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_UNLOCK))
    icl_trace_record (NULL, smt_thread_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_UNLOCK))
    icl_stats_inc ("smt_thread_unlock", &s_smt_thread_unlock_stats);
#endif

SMT_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_UNLOCK))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_UNLOCK))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_unlock_finish"
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
    smt_thread_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

smt_thread_t *
    smt_thread_link_ (
    smt_thread_t * self,                //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_THREAD)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_LINK))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_LINK))
    icl_trace_record (NULL, smt_thread_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_LINK))
    icl_stats_inc ("smt_thread_link", &s_smt_thread_link_stats);
#endif

    if (self) {
        SMT_THREAD_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_THREAD)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_THREAD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_THREAD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_THREAD_HISTORY_LENGTH] = "link";
        self->history_links [history_last % SMT_THREAD_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_LINK))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_LINK))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_link_finish"
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
    smt_thread_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    smt_thread_unlink_ (
    smt_thread_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_THREAD)
    int
        history_last;
#endif

    smt_thread_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_UNLINK))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_UNLINK))
    icl_trace_record (NULL, smt_thread_dump, 35);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_UNLINK))
    icl_stats_inc ("smt_thread_unlink", &s_smt_thread_unlink_stats);
#endif

    if (self) {
        SMT_THREAD_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on smt_thread object");
            smt_thread_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_THREAD)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_THREAD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_THREAD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_THREAD_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % SMT_THREAD_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            smt_thread_annihilate_ (self_p, file, line);
        smt_thread_free_ ((smt_thread_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_UNLINK))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 35);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_UNLINK))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_unlink_finish"
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
    smt_thread_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_thread_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_CACHE_INITIALISE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_thread_dump, 36);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_CACHE_INITIALISE))
    icl_stats_inc ("smt_thread_cache_initialise", &s_smt_thread_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_thread_t));
icl_system_register (smt_thread_cache_purge, smt_thread_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 36);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_CACHE_INITIALISE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_cache_initialise_finish"
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
    smt_thread_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_thread_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_CACHE_PURGE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_CACHE_PURGE))
    icl_trace_record (NULL, smt_thread_dump, 37);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_CACHE_PURGE))
    icl_stats_inc ("smt_thread_cache_purge", &s_smt_thread_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_CACHE_PURGE))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 37);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_CACHE_PURGE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_cache_purge_finish"
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
    smt_thread_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_thread_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_CACHE_TERMINATE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_thread_dump, 38);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_CACHE_TERMINATE))
    icl_stats_inc ("smt_thread_cache_terminate", &s_smt_thread_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 38);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_CACHE_TERMINATE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_cache_terminate_finish"
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
    smt_thread_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_thread_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_ANIMATE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_ANIMATE))
    icl_trace_record (NULL, smt_thread_dump, 39);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_ANIMATE))
    icl_stats_inc ("smt_thread_animate", &s_smt_thread_animate_stats);
#endif

smt_thread_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_ANIMATE))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 39);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_ANIMATE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_animate_finish"
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
    smt_thread_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_thread_new_in_scope_ (
    smt_thread_t * * self_p,            //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    smt_thread_p_fn * manager,          //  The thread's manager function
    smt_thread_fn * catcher,            //  The thread's catcher function
    smt_thread_fn * destructor          //  The thread's destructor function
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_THREAD)  ||  defined (BASE_ANIMATE_SMT_THREAD_NEW_IN_SCOPE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" manager=\"%pp\""
" catcher=\"%pp\""
" destructor=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, manager, catcher, destructor);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_thread_dump, 40);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_THREAD)  ||  defined (BASE_STATS_SMT_THREAD_NEW_IN_SCOPE))
    icl_stats_inc ("smt_thread_new_in_scope", &s_smt_thread_new_in_scope_stats);
#endif

*self_p = smt_thread_new_ (file,line,manager,catcher,destructor);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_thread_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_thread_dump, 0x10000 + 40);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_THREAD)   || defined (BASE_ANIMATE_SMT_THREAD_NEW_IN_SCOPE))
    if (smt_thread_animating)
        icl_console_print ("<smt_thread_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" manager=\"%pp\""
" catcher=\"%pp\""
" destructor=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, manager, catcher, destructor, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_THREAD)   || defined (BASE_TRACE_SMT_THREAD_NEW)   || defined (BASE_TRACE_SMT_THREAD_DESTROY)   || defined (BASE_TRACE_SMT_THREAD_FREE)   || defined (BASE_TRACE_SMT_THREAD_SHARE)   || defined (BASE_TRACE_SMT_THREAD_WATCH)   || defined (BASE_TRACE_SMT_THREAD_SHOW)   || defined (BASE_TRACE_SMT_THREAD_CLEAR_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_THREAD_METHOD_ACCEPT)   || defined (BASE_TRACE_SMT_THREAD_REPLY_BACKLOG)   || defined (BASE_TRACE_SMT_THREAD_INSERT_INTO_WAITING_LIST)   || defined (BASE_TRACE_SMT_THREAD_WAITING_LIST_POP)   || defined (BASE_TRACE_SMT_THREAD_WAKE)   || defined (BASE_TRACE_SMT_THREAD_ACTIVATE)   || defined (BASE_TRACE_SMT_THREAD_ACTIVITY)   || defined (BASE_TRACE_SMT_THREAD_CONTINUE)   || defined (BASE_TRACE_SMT_THREAD_PURGE)   || defined (BASE_TRACE_SMT_THREAD_SHUT_DOWN)   || defined (BASE_TRACE_SMT_THREAD_SHUT_DOWN_ALL_NEWBORN)   || defined (BASE_TRACE_SMT_THREAD_POSITION_PUSH)   || defined (BASE_TRACE_SMT_THREAD_POSITION_POP)   || defined (BASE_TRACE_SMT_THREAD_SET_NEXT_EVENT)   || defined (BASE_TRACE_SMT_THREAD_RAISE_EXCEPTION)   || defined (BASE_TRACE_SMT_THREAD_EXCEPTION_RAISED)   || defined (BASE_TRACE_SMT_THREAD_ERROR)   || defined (BASE_TRACE_SMT_THREAD_SELFTEST)   || defined (BASE_TRACE_SMT_THREAD_INITIALISE)   || defined (BASE_TRACE_SMT_THREAD_TERMINATE)   || defined (BASE_TRACE_SMT_THREAD_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_SMT_THREAD_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_THREAD_ALLOC)   || defined (BASE_TRACE_SMT_THREAD_READ_LOCK)   || defined (BASE_TRACE_SMT_THREAD_WRITE_LOCK)   || defined (BASE_TRACE_SMT_THREAD_UNLOCK)   || defined (BASE_TRACE_SMT_THREAD_LINK)   || defined (BASE_TRACE_SMT_THREAD_UNLINK)   || defined (BASE_TRACE_SMT_THREAD_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_THREAD_CACHE_PURGE)   || defined (BASE_TRACE_SMT_THREAD_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_THREAD_ANIMATE)   || defined (BASE_TRACE_SMT_THREAD_NEW_IN_SCOPE) )
void
smt_thread_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "free"; break;
        case 4: method_name = "share"; break;
        case 5: method_name = "watch"; break;
        case 6: method_name = "show"; break;
        case 7: method_name = "clear method queue"; break;
        case 8: method_name = "method accept"; break;
        case 9: method_name = "reply backlog"; break;
        case 10: method_name = "insert into waiting list"; break;
        case 11: method_name = "waiting list pop"; break;
        case 12: method_name = "wake"; break;
        case 13: method_name = "activate"; break;
        case 14: method_name = "activity"; break;
        case 15: method_name = "continue"; break;
        case 16: method_name = "purge"; break;
        case 17: method_name = "shut down"; break;
        case 18: method_name = "shut down all newborn"; break;
        case 19: method_name = "position push"; break;
        case 20: method_name = "position pop"; break;
        case 21: method_name = "set next event"; break;
        case 22: method_name = "raise exception"; break;
        case 23: method_name = "exception raised"; break;
        case 24: method_name = "error"; break;
        case 25: method_name = "selftest"; break;
        case 26: method_name = "initialise"; break;
        case 27: method_name = "terminate"; break;
        case 28: method_name = "remove from all containers"; break;
        case 29: method_name = "destroy public"; break;
        case 30: method_name = "alloc"; break;
        case 31: method_name = "read lock"; break;
        case 32: method_name = "write lock"; break;
        case 33: method_name = "unlock"; break;
        case 34: method_name = "link"; break;
        case 35: method_name = "unlink"; break;
        case 36: method_name = "cache initialise"; break;
        case 37: method_name = "cache purge"; break;
        case 38: method_name = "cache terminate"; break;
        case 39: method_name = "animate"; break;
        case 40: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_thread %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Functions                                                                  

static int
s_method_queue_trigger (void *data, smt_method_queue_notify_t event)
{
    smt_thread_t
        *self = data;

    //  Only wake thread if event is insertion.  Other possibility is
    //  destruction which means thread is being destroyed.
    if (event == SMT_METHOD_QUEUE_INSERT)
        return smt_thread_wake (self);
    else
        return 0;
}

//  Embed the version information in the resulting binary                      

char *smt_thread_version_start     = "VeRsIoNsTaRt:ipc";
char *smt_thread_component         = "smt_thread ";
char *smt_thread_version           = "1.0 ";
char *smt_thread_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_thread_filename          = "smt_thread.icl ";
char *smt_thread_builddate         = "2010/10/06 ";
char *smt_thread_version_end       = "VeRsIoNeNd:ipc";

