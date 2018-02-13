/*---------------------------------------------------------------------------
    amq_exchange_by_vhost.c - amq_exchange_by_vhost component

    This class implements the list container for amq_exchange
    Generated from amq_exchange_by_vhost.icl by icl_gen using GSL/4.
    
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
#include "amq_exchange_by_vhost.h"      //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_exchange_by_vhost_t

//  Shorthands for class methods                                               

#define self_new            amq_exchange_by_vhost_new
#define self_annihilate     amq_exchange_by_vhost_annihilate
#define self_selftest       amq_exchange_by_vhost_selftest
#define self_isempty        amq_exchange_by_vhost_isempty
#define self_push           amq_exchange_by_vhost_push
#define self_pop            amq_exchange_by_vhost_pop
#define self_queue          amq_exchange_by_vhost_queue
#define self_relink_before  amq_exchange_by_vhost_relink_before
#define self_remove         amq_exchange_by_vhost_remove
#define self_first          amq_exchange_by_vhost_first
#define self_last           amq_exchange_by_vhost_last
#define self_next           amq_exchange_by_vhost_next
#define self_prev           amq_exchange_by_vhost_prev
#define self_rehook         amq_exchange_by_vhost_rehook
#define self_unhook         amq_exchange_by_vhost_unhook
#define self_terminate      amq_exchange_by_vhost_terminate
#define self_show           amq_exchange_by_vhost_show
#define self_destroy        amq_exchange_by_vhost_destroy
#define self_alloc          amq_exchange_by_vhost_alloc
#define self_free           amq_exchange_by_vhost_free
#define self_read_lock      amq_exchange_by_vhost_read_lock
#define self_write_lock     amq_exchange_by_vhost_write_lock
#define self_unlock         amq_exchange_by_vhost_unlock
#define self_link           amq_exchange_by_vhost_link
#define self_unlink         amq_exchange_by_vhost_unlink
#define self_cache_initialise  amq_exchange_by_vhost_cache_initialise
#define self_cache_purge    amq_exchange_by_vhost_cache_purge
#define self_cache_terminate  amq_exchange_by_vhost_cache_terminate
#define self_animate        amq_exchange_by_vhost_animate
#define self_new_in_scope   amq_exchange_by_vhost_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_NEW))
static icl_stats_t *s_amq_exchange_by_vhost_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_DESTROY))
static icl_stats_t *s_amq_exchange_by_vhost_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_SELFTEST))
static icl_stats_t *s_amq_exchange_by_vhost_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_ISEMPTY))
static icl_stats_t *s_amq_exchange_by_vhost_isempty_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_PUSH))
static icl_stats_t *s_amq_exchange_by_vhost_push_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_POP))
static icl_stats_t *s_amq_exchange_by_vhost_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_QUEUE))
static icl_stats_t *s_amq_exchange_by_vhost_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_RELINK_BEFORE))
static icl_stats_t *s_amq_exchange_by_vhost_relink_before_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_REMOVE))
static icl_stats_t *s_amq_exchange_by_vhost_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_FIRST))
static icl_stats_t *s_amq_exchange_by_vhost_first_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_LAST))
static icl_stats_t *s_amq_exchange_by_vhost_last_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_NEXT))
static icl_stats_t *s_amq_exchange_by_vhost_next_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_PREV))
static icl_stats_t *s_amq_exchange_by_vhost_prev_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_REHOOK))
static icl_stats_t *s_amq_exchange_by_vhost_rehook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_UNHOOK))
static icl_stats_t *s_amq_exchange_by_vhost_unhook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_TERMINATE))
static icl_stats_t *s_amq_exchange_by_vhost_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_SHOW))
static icl_stats_t *s_amq_exchange_by_vhost_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_DESTROY_PUBLIC))
static icl_stats_t *s_amq_exchange_by_vhost_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_ALLOC))
static icl_stats_t *s_amq_exchange_by_vhost_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_FREE))
static icl_stats_t *s_amq_exchange_by_vhost_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_READ_LOCK))
static icl_stats_t *s_amq_exchange_by_vhost_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_WRITE_LOCK))
static icl_stats_t *s_amq_exchange_by_vhost_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_UNLOCK))
static icl_stats_t *s_amq_exchange_by_vhost_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_LINK))
static icl_stats_t *s_amq_exchange_by_vhost_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_UNLINK))
static icl_stats_t *s_amq_exchange_by_vhost_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_CACHE_INITIALISE))
static icl_stats_t *s_amq_exchange_by_vhost_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_CACHE_PURGE))
static icl_stats_t *s_amq_exchange_by_vhost_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_CACHE_TERMINATE))
static icl_stats_t *s_amq_exchange_by_vhost_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_ANIMATE))
static icl_stats_t *s_amq_exchange_by_vhost_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_NEW_IN_SCOPE))
static icl_stats_t *s_amq_exchange_by_vhost_new_in_scope_stats = NULL;
#endif
#define amq_exchange_by_vhost_annihilate(self)  amq_exchange_by_vhost_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_exchange_by_vhost_annihilate_ (
amq_exchange_by_vhost_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static inline void
    amq_exchange_by_vhost_rehook (
amq_exchange_t * item,                  //  Not documented
amq_exchange_t * left,                  //  Not documented
amq_exchange_t * right                  //  Not documented
);

static inline amq_exchange_t *
    amq_exchange_by_vhost_unhook (
amq_exchange_t * item                   //  Not documented
);

#define amq_exchange_by_vhost_alloc()   amq_exchange_by_vhost_alloc_ (__FILE__, __LINE__)
static amq_exchange_by_vhost_t *
    amq_exchange_by_vhost_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_exchange_by_vhost_free(self)  amq_exchange_by_vhost_free_ (self, __FILE__, __LINE__)
static void
    amq_exchange_by_vhost_free_ (
amq_exchange_by_vhost_t * self,         //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_exchange_by_vhost_cache_initialise (
void);

static void
    amq_exchange_by_vhost_cache_purge (
void);

static void
    amq_exchange_by_vhost_cache_terminate (
void);

Bool
    amq_exchange_by_vhost_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_new

    Type: Component method
    Creates and initialises a new amq_exchange_by_vhost_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_exchange_by_vhost_t *
    amq_exchange_by_vhost_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_exchange_by_vhost_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_NEW))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_NEW))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_NEW))
    icl_stats_inc ("amq_exchange_by_vhost_new", &s_amq_exchange_by_vhost_new_stats);
#endif

    self = amq_exchange_by_vhost_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_EXCHANGE_BY_VHOST_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_BY_VHOST)
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
        icl_mem_set_callback (self, amq_exchange_by_vhost_show_);
#endif

self->amq_exchange.by_vhost_next = &self->amq_exchange;
self->amq_exchange.by_vhost_prev = &self->amq_exchange;
self->amq_exchange.by_vhost_head = self;

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_NEW))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_NEW))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_new_finish"
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
    amq_exchange_by_vhost_annihilate

    Type: Component method
    Destroys the list and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_by_vhost_annihilate_ (
    amq_exchange_by_vhost_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_BY_VHOST)
    int
        history_last;
#endif

amq_exchange_t
    *item;
    amq_exchange_by_vhost_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_DESTROY))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_DESTROY))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_DESTROY))
    icl_stats_inc ("amq_exchange_by_vhost_annihilate", &s_amq_exchange_by_vhost_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_BY_VHOST)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = self->links;
#endif

    AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

item = (amq_exchange_t *) self->amq_exchange.by_vhost_next;
while (item != &self->amq_exchange) {
    //  Unlink child without lock (we already have the lock)               
    amq_exchange_by_vhost_unhook (item);

    amq_exchange_unlink (&item);
    item = (amq_exchange_t *) self->amq_exchange.by_vhost_next;
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_DESTROY))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_DESTROY))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_destroy_finish"
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
    amq_exchange_by_vhost_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_by_vhost_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_SELFTEST))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_SELFTEST))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_SELFTEST))
    icl_stats_inc ("amq_exchange_by_vhost_selftest", &s_amq_exchange_by_vhost_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_SELFTEST))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_SELFTEST))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_selftest_finish"
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
    amq_exchange_by_vhost_isempty

    Type: Component method
    Accepts a amq_exchange_by_vhost_t reference and returns zero in case of success,
    1 in case of errors.
    Returns true if the list is empty, else returns false.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_by_vhost_isempty (
    amq_exchange_by_vhost_t * self      //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_ISEMPTY))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_isempty_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_ISEMPTY))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_ISEMPTY))
    icl_stats_inc ("amq_exchange_by_vhost_isempty", &s_amq_exchange_by_vhost_isempty_stats);
#endif

AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
if (!self->zombie) {

rc = (self->amq_exchange.by_vhost_next == &self->amq_exchange);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_ISEMPTY))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_ISEMPTY))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_isempty_finish"
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
    amq_exchange_by_vhost_push

    Type: Component method
    Accepts a amq_exchange_by_vhost_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the start of the specified list. If the item
    was on another list, it is first detached.  After this method,
    list->next points to the item.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_by_vhost_push (
    amq_exchange_by_vhost_t * self,     //  Reference to object
    amq_exchange_t * item               //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_PUSH))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_push_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_PUSH))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_PUSH))
    icl_stats_inc ("amq_exchange_by_vhost_push", &s_amq_exchange_by_vhost_push_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
if (!self->zombie) {

//  If by_vhost_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->by_vhost_head) {
    amq_exchange_link (item);
}
else
if (item->by_vhost_head != self) {
    icl_console_print ("E: amq_exchange item inserted into multiple by_vhost containers");
    assert (item->by_vhost_head == self);
}
amq_exchange_by_vhost_unhook (item);
amq_exchange_by_vhost_rehook (item, &self->amq_exchange, (amq_exchange_t *) self->amq_exchange.by_vhost_next);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_PUSH))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_PUSH))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_push_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_pop

    Type: Component method
    Removes the next item in the list, if any, and returns it.  If
    the list was empty, returns NULL.
    
    The number of links is unchanged; removing from the list and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

amq_exchange_t *
    amq_exchange_by_vhost_pop (
    amq_exchange_by_vhost_t * self      //  The list
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_exchange_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_POP))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_pop_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_POP))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_POP))
    icl_stats_inc ("amq_exchange_by_vhost_pop", &s_amq_exchange_by_vhost_pop_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
if (!self->zombie) {

if (self->amq_exchange.by_vhost_next == &self->amq_exchange)
    item = NULL;
else {
    item = amq_exchange_by_vhost_unhook ((amq_exchange_t *) self->amq_exchange.by_vhost_next);
}
}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_POP))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_POP))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_pop_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_queue

    Type: Component method
    Accepts a amq_exchange_by_vhost_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the end of the specified list.  The item may not
    be in another list of the same class.
    
    The number of links is automatically adjusted - if the item was already
    in the list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_by_vhost_queue (
    amq_exchange_by_vhost_t * self,     //  Reference to object
    amq_exchange_t * item               //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_QUEUE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_queue_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_QUEUE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_QUEUE))
    icl_stats_inc ("amq_exchange_by_vhost_queue", &s_amq_exchange_by_vhost_queue_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
if (!self->zombie) {

//  If by_vhost_head is non-null then we are moving within the         
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->by_vhost_head) {
    amq_exchange_link (item);
}
else
if (item->by_vhost_head != self) {
    icl_console_print ("E: amq_exchange item inserted into multiple by_vhost containers");
    assert (item->by_vhost_head == self);
}
amq_exchange_by_vhost_unhook (item);
amq_exchange_by_vhost_rehook (item, (amq_exchange_t *) self->amq_exchange.by_vhost_prev, &self->amq_exchange);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_QUEUE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_QUEUE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_relink_before

    Type: Component method
    Accepts a amq_exchange_by_vhost_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item before a specified item. If the item was on another list,
    it is first detached.
    
    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_by_vhost_relink_before (
    amq_exchange_t * item,              //  Not documented
    amq_exchange_t * where              //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code
    amq_exchange_by_vhost_t *
        self = (amq_exchange_by_vhost_t *) where->by_vhost_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_RELINK_BEFORE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_relink_before_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" where=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, where);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_RELINK_BEFORE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_RELINK_BEFORE))
    icl_stats_inc ("amq_exchange_by_vhost_relink_before", &s_amq_exchange_by_vhost_relink_before_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
if (!self->zombie) {

//  If by_vhost_head is non-null then we are moving within the         
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->by_vhost_head) {
    amq_exchange_link (item);
}
else
if (item->by_vhost_head != self) {
    icl_console_print ("E: amq_exchange item inserted into multiple by_vhost containers");
    assert (item->by_vhost_head == self);
}            
amq_exchange_by_vhost_unhook (item);
amq_exchange_by_vhost_rehook (item, (amq_exchange_t *) where->by_vhost_prev, where);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_RELINK_BEFORE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_RELINK_BEFORE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_relink_before_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" where=\"%pp\""
" rc=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, where, rc, self);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_remove

    Type: Component method
    Removes the item from any list it is in.
    
    If it was in a list, the number of links is decremented.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_by_vhost_remove (
    amq_exchange_t * item               //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_exchange_by_vhost_t *
        self = (amq_exchange_by_vhost_t *) item->by_vhost_head;  //  The list
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_REMOVE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_remove_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_REMOVE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_REMOVE))
    icl_stats_inc ("amq_exchange_by_vhost_remove", &s_amq_exchange_by_vhost_remove_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

if (self
&&  self == item->by_vhost_head) { //   Catch case where item moved
    amq_exchange_by_vhost_unhook (item);
    amq_exchange_unlink (&item);
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_REMOVE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_REMOVE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_remove_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_first

    Type: Component method
    Returns the first amq_exchange item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

amq_exchange_t *
    amq_exchange_by_vhost_first_ (
    amq_exchange_by_vhost_t * self,     //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_exchange_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_FIRST))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_first_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_FIRST))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_FIRST))
    icl_stats_inc ("amq_exchange_by_vhost_first", &s_amq_exchange_by_vhost_first_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
if (!self->zombie) {

item = (amq_exchange_t *) self->amq_exchange.by_vhost_next;
if (item == &self->amq_exchange)
    item = NULL;
else
    amq_exchange_link (item);

}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_FIRST))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_FIRST))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_first_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_last

    Type: Component method
    Returns the last amq_exchange item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

amq_exchange_t *
    amq_exchange_by_vhost_last_ (
    amq_exchange_by_vhost_t * self,     //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_exchange_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_LAST))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_last_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_LAST))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_LAST))
    icl_stats_inc ("amq_exchange_by_vhost_last", &s_amq_exchange_by_vhost_last_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
if (!self->zombie) {

item = (amq_exchange_t *) self->amq_exchange.by_vhost_prev;
if (item == &self->amq_exchange)
    item = NULL;
else
    amq_exchange_link (item);

}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_LAST))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_LAST))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_last_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_next

    Type: Component method
    Returns the following item on the amq_exchange list. If the provided item
    is null, returns the first item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

amq_exchange_t *
    amq_exchange_by_vhost_next_ (
    amq_exchange_t * ( * item_p ),      //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_exchange_t *
        item = *item_p;                 //  Dereferenced item
    amq_exchange_t *
        next = NULL;                    //  The item to return
    amq_exchange_by_vhost_t *
        self = (amq_exchange_by_vhost_t *) item->by_vhost_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_NEXT))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_next_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line, item);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_NEXT))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_NEXT))
    icl_stats_inc ("amq_exchange_by_vhost_next", &s_amq_exchange_by_vhost_next_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

if (self
&&  self == item->by_vhost_head) { //   Catch case where item moved
    next = (amq_exchange_t *) item->by_vhost_next;
    if (next == &self->amq_exchange)
        next = NULL;
    else
        amq_exchange_link (next);

}
amq_exchange_unlink (item_p);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_NEXT))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_NEXT))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_next_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
" next=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line, item, next, self);
#endif


    return (next);
}
/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_prev

    Type: Component method
    Returns the preceding item on the amq_exchange list. If the provided item
    is null, returns the last item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

amq_exchange_t *
    amq_exchange_by_vhost_prev_ (
    amq_exchange_t * ( * item_p ),      //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_exchange_t *
        item = *item_p;                 //  Dereferenced item
    amq_exchange_t *
        prev = NULL;                    //  The item to return
    amq_exchange_by_vhost_t *
        self = (amq_exchange_by_vhost_t *) item->by_vhost_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_PREV))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_prev_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line, item);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_PREV))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_PREV))
    icl_stats_inc ("amq_exchange_by_vhost_prev", &s_amq_exchange_by_vhost_prev_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

if (self
&&  self == item->by_vhost_head) { //   Catch case where item moved
    prev = (amq_exchange_t *) item->by_vhost_prev;
    if (prev == &self->amq_exchange)
        prev = NULL;
    else
        amq_exchange_link (prev);

}
amq_exchange_unlink (item_p);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_PREV))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_PREV))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_prev_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
" prev=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line, item, prev, self);
#endif


    return (prev);
}
/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_rehook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    amq_exchange_by_vhost_rehook (
    amq_exchange_t * item,              //  Not documented
    amq_exchange_t * left,              //  Not documented
    amq_exchange_t * right              //  Not documented
)
{
amq_exchange_t
    *swap;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_REHOOK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_rehook_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" left=\"%pp\""
" right=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, left, right);
#endif

#if (defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_REHOOK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_REHOOK))
    icl_stats_inc ("amq_exchange_by_vhost_rehook", &s_amq_exchange_by_vhost_rehook_stats);
#endif

swap = (amq_exchange_t *) left->by_vhost_next;
left->by_vhost_next = item->by_vhost_next;
item->by_vhost_next = swap;

swap = (amq_exchange_t *) item->by_vhost_prev;
item->by_vhost_prev = right->by_vhost_prev;
right->by_vhost_prev = swap;

item->by_vhost_head = left->by_vhost_head;
#if (defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_REHOOK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_REHOOK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_rehook_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" left=\"%pp\""
" right=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, left, right);
#endif

}
/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_unhook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline amq_exchange_t *
    amq_exchange_by_vhost_unhook (
    amq_exchange_t * item               //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_UNHOOK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_unhook_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item);
#endif

#if (defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_UNHOOK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_UNHOOK))
    icl_stats_inc ("amq_exchange_by_vhost_unhook", &s_amq_exchange_by_vhost_unhook_stats);
#endif

amq_exchange_by_vhost_rehook (item, (amq_exchange_t *) item->by_vhost_prev, (amq_exchange_t *) item->by_vhost_next);
item->by_vhost_head = NULL;
#if (defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_UNHOOK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_UNHOOK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_unhook_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    amq_exchange_by_vhost_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_by_vhost_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_TERMINATE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_TERMINATE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_TERMINATE))
    icl_stats_inc ("amq_exchange_by_vhost_terminate", &s_amq_exchange_by_vhost_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_TERMINATE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_TERMINATE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_terminate_finish"
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
    amq_exchange_by_vhost_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_by_vhost_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_exchange_by_vhost_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_BY_VHOST)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_SHOW))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_SHOW))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_SHOW))
    icl_stats_inc ("amq_exchange_by_vhost_show", &s_amq_exchange_by_vhost_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_exchange_by_vhost zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_BY_VHOST)
    if (self->history_last > AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH;
        self->history_last %= AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_exchange_by_vhost>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_SHOW))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_SHOW))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_show_finish"
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
    amq_exchange_by_vhost_destroy

    Type: Component method
    Destroys a amq_exchange_by_vhost_t object. Takes the address of a
    amq_exchange_by_vhost_t reference (a pointer to a pointer) and nullifies the
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
    amq_exchange_by_vhost_destroy_ (
    amq_exchange_by_vhost_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_exchange_by_vhost_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_DESTROY_PUBLIC))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_DESTROY_PUBLIC))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_DESTROY_PUBLIC))
    icl_stats_inc ("amq_exchange_by_vhost_destroy", &s_amq_exchange_by_vhost_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_exchange_by_vhost_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on amq_exchange_by_vhost object");
        amq_exchange_by_vhost_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_exchange_by_vhost_free_ ((amq_exchange_by_vhost_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_DESTROY_PUBLIC))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_DESTROY_PUBLIC))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_destroy_public_finish"
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
    amq_exchange_by_vhost_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_exchange_by_vhost_t *
    amq_exchange_by_vhost_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_exchange_by_vhost_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_ALLOC))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_ALLOC))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_ALLOC))
    icl_stats_inc ("amq_exchange_by_vhost_alloc", &s_amq_exchange_by_vhost_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_exchange_by_vhost_cache_initialise ();

self = (amq_exchange_by_vhost_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_exchange_by_vhost_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_ALLOC))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_ALLOC))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_alloc_finish"
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
    amq_exchange_by_vhost_free

    Type: Component method
    Freess a amq_exchange_by_vhost_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_by_vhost_free_ (
    amq_exchange_by_vhost_t * self,     //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_BY_VHOST)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_FREE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_FREE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_FREE))
    icl_stats_inc ("amq_exchange_by_vhost_free", &s_amq_exchange_by_vhost_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_BY_VHOST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (amq_exchange_by_vhost_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_exchange_by_vhost_t));
        self->object_tag = AMQ_EXCHANGE_BY_VHOST_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_FREE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_FREE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_free_finish"
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
    amq_exchange_by_vhost_read_lock

    Type: Component method
    Accepts a amq_exchange_by_vhost_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_by_vhost_read_lock (
    amq_exchange_by_vhost_t * self      //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_READ_LOCK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_READ_LOCK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_READ_LOCK))
    icl_stats_inc ("amq_exchange_by_vhost_read_lock", &s_amq_exchange_by_vhost_read_lock_stats);
#endif

AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_READ_LOCK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_READ_LOCK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_read_lock_finish"
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
    amq_exchange_by_vhost_write_lock

    Type: Component method
    Accepts a amq_exchange_by_vhost_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_by_vhost_write_lock (
    amq_exchange_by_vhost_t * self      //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_WRITE_LOCK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_WRITE_LOCK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_WRITE_LOCK))
    icl_stats_inc ("amq_exchange_by_vhost_write_lock", &s_amq_exchange_by_vhost_write_lock_stats);
#endif

AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_WRITE_LOCK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_WRITE_LOCK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_write_lock_finish"
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
    amq_exchange_by_vhost_unlock

    Type: Component method
    Accepts a amq_exchange_by_vhost_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_by_vhost_unlock (
    amq_exchange_by_vhost_t * self      //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_UNLOCK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_UNLOCK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_UNLOCK))
    icl_stats_inc ("amq_exchange_by_vhost_unlock", &s_amq_exchange_by_vhost_unlock_stats);
#endif

AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_UNLOCK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_UNLOCK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_unlock_finish"
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
    amq_exchange_by_vhost_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_exchange_by_vhost_t *
    amq_exchange_by_vhost_link_ (
    amq_exchange_by_vhost_t * self,     //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_BY_VHOST)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_LINK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_LINK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_LINK))
    icl_stats_inc ("amq_exchange_by_vhost_link", &s_amq_exchange_by_vhost_link_stats);
#endif

    if (self) {
        AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_BY_VHOST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_LINK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_LINK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_link_finish"
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
    amq_exchange_by_vhost_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_exchange_by_vhost_unlink_ (
    amq_exchange_by_vhost_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_BY_VHOST)
    int
        history_last;
#endif

    amq_exchange_by_vhost_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_UNLINK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_UNLINK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_UNLINK))
    icl_stats_inc ("amq_exchange_by_vhost_unlink", &s_amq_exchange_by_vhost_unlink_stats);
#endif

    if (self) {
        AMQ_EXCHANGE_BY_VHOST_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_exchange_by_vhost object");
            amq_exchange_by_vhost_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_BY_VHOST)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_EXCHANGE_BY_VHOST_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_exchange_by_vhost_annihilate_ (self_p, file, line);
        amq_exchange_by_vhost_free_ ((amq_exchange_by_vhost_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_UNLINK))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_UNLINK))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_unlink_finish"
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
    amq_exchange_by_vhost_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_by_vhost_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_CACHE_INITIALISE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_CACHE_INITIALISE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_CACHE_INITIALISE))
    icl_stats_inc ("amq_exchange_by_vhost_cache_initialise", &s_amq_exchange_by_vhost_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_exchange_by_vhost_t));
icl_system_register (amq_exchange_by_vhost_cache_purge, amq_exchange_by_vhost_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_CACHE_INITIALISE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_CACHE_INITIALISE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_cache_initialise_finish"
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
    amq_exchange_by_vhost_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_by_vhost_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_CACHE_PURGE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_CACHE_PURGE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_CACHE_PURGE))
    icl_stats_inc ("amq_exchange_by_vhost_cache_purge", &s_amq_exchange_by_vhost_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_CACHE_PURGE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_CACHE_PURGE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_cache_purge_finish"
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
    amq_exchange_by_vhost_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_by_vhost_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_CACHE_TERMINATE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_CACHE_TERMINATE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_CACHE_TERMINATE))
    icl_stats_inc ("amq_exchange_by_vhost_cache_terminate", &s_amq_exchange_by_vhost_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_CACHE_TERMINATE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_CACHE_TERMINATE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_cache_terminate_finish"
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
    amq_exchange_by_vhost_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_exchange_by_vhost_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_ANIMATE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_ANIMATE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_ANIMATE))
    icl_stats_inc ("amq_exchange_by_vhost_animate", &s_amq_exchange_by_vhost_animate_stats);
#endif

amq_exchange_by_vhost_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_ANIMATE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_ANIMATE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_animate_finish"
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
    amq_exchange_by_vhost_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_by_vhost_new_in_scope_ (
    amq_exchange_by_vhost_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_NEW_IN_SCOPE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_NEW_IN_SCOPE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST)  ||  defined (BASE_STATS_AMQ_EXCHANGE_BY_VHOST_NEW_IN_SCOPE))
    icl_stats_inc ("amq_exchange_by_vhost_new_in_scope", &s_amq_exchange_by_vhost_new_in_scope_stats);
#endif

*self_p = amq_exchange_by_vhost_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_exchange_by_vhost_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_NEW_IN_SCOPE))
    icl_trace_record (1, amq_exchange_by_vhost_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_BY_VHOST_NEW_IN_SCOPE))
    if (amq_exchange_by_vhost_animating)
        icl_console_print ("<amq_exchange_by_vhost_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_NEW)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_DESTROY)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_SELFTEST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_ISEMPTY)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_PUSH)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_POP)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_QUEUE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_RELINK_BEFORE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_REMOVE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_FIRST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_LAST)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_NEXT)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_PREV)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_REHOOK)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_UNHOOK)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_TERMINATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_SHOW)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_ALLOC)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_FREE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_READ_LOCK)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_UNLOCK)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_LINK)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_UNLINK)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_ANIMATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_BY_VHOST_NEW_IN_SCOPE) )
void
amq_exchange_by_vhost_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "isempty"; break;
        case 5: method_name = "push"; break;
        case 6: method_name = "pop"; break;
        case 7: method_name = "queue"; break;
        case 8: method_name = "relink before"; break;
        case 9: method_name = "remove"; break;
        case 10: method_name = "first"; break;
        case 11: method_name = "last"; break;
        case 12: method_name = "next"; break;
        case 13: method_name = "prev"; break;
        case 14: method_name = "rehook"; break;
        case 15: method_name = "unhook"; break;
        case 16: method_name = "terminate"; break;
        case 17: method_name = "show"; break;
        case 18: method_name = "destroy public"; break;
        case 19: method_name = "alloc"; break;
        case 20: method_name = "free"; break;
        case 21: method_name = "read lock"; break;
        case 22: method_name = "write lock"; break;
        case 23: method_name = "unlock"; break;
        case 24: method_name = "link"; break;
        case 25: method_name = "unlink"; break;
        case 26: method_name = "cache initialise"; break;
        case 27: method_name = "cache purge"; break;
        case 28: method_name = "cache terminate"; break;
        case 29: method_name = "animate"; break;
        case 30: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_exchange_by_vhost %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_exchange_by_vhost_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_exchange_by_vhost_component  = "amq_exchange_by_vhost ";
char *amq_exchange_by_vhost_version  = "1.0 ";
char *amq_exchange_by_vhost_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_exchange_by_vhost_filename  = "amq_exchange_by_vhost.icl ";
char *amq_exchange_by_vhost_builddate  = "2010/10/06 ";
char *amq_exchange_by_vhost_version_end  = "VeRsIoNeNd:ipc";

