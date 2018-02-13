/*---------------------------------------------------------------------------
    amq_consumer_by_channel.c - amq_consumer_by_channel component

    This class implements the list container for amq_consumer
    Generated from amq_consumer_by_channel.icl by icl_gen using GSL/4.
    
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
#include "amq_consumer_by_channel.h"    //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_consumer_by_channel_t

//  Shorthands for class methods                                               

#define self_new            amq_consumer_by_channel_new
#define self_annihilate     amq_consumer_by_channel_annihilate
#define self_selftest       amq_consumer_by_channel_selftest
#define self_isempty        amq_consumer_by_channel_isempty
#define self_push           amq_consumer_by_channel_push
#define self_pop            amq_consumer_by_channel_pop
#define self_queue          amq_consumer_by_channel_queue
#define self_relink_before  amq_consumer_by_channel_relink_before
#define self_remove         amq_consumer_by_channel_remove
#define self_first          amq_consumer_by_channel_first
#define self_last           amq_consumer_by_channel_last
#define self_next           amq_consumer_by_channel_next
#define self_prev           amq_consumer_by_channel_prev
#define self_rehook         amq_consumer_by_channel_rehook
#define self_unhook         amq_consumer_by_channel_unhook
#define self_terminate      amq_consumer_by_channel_terminate
#define self_show           amq_consumer_by_channel_show
#define self_destroy        amq_consumer_by_channel_destroy
#define self_alloc          amq_consumer_by_channel_alloc
#define self_free           amq_consumer_by_channel_free
#define self_read_lock      amq_consumer_by_channel_read_lock
#define self_write_lock     amq_consumer_by_channel_write_lock
#define self_unlock         amq_consumer_by_channel_unlock
#define self_link           amq_consumer_by_channel_link
#define self_unlink         amq_consumer_by_channel_unlink
#define self_cache_initialise  amq_consumer_by_channel_cache_initialise
#define self_cache_purge    amq_consumer_by_channel_cache_purge
#define self_cache_terminate  amq_consumer_by_channel_cache_terminate
#define self_animate        amq_consumer_by_channel_animate
#define self_new_in_scope   amq_consumer_by_channel_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_NEW))
static icl_stats_t *s_amq_consumer_by_channel_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_DESTROY))
static icl_stats_t *s_amq_consumer_by_channel_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_SELFTEST))
static icl_stats_t *s_amq_consumer_by_channel_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_ISEMPTY))
static icl_stats_t *s_amq_consumer_by_channel_isempty_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_PUSH))
static icl_stats_t *s_amq_consumer_by_channel_push_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_POP))
static icl_stats_t *s_amq_consumer_by_channel_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_QUEUE))
static icl_stats_t *s_amq_consumer_by_channel_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_RELINK_BEFORE))
static icl_stats_t *s_amq_consumer_by_channel_relink_before_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_REMOVE))
static icl_stats_t *s_amq_consumer_by_channel_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_FIRST))
static icl_stats_t *s_amq_consumer_by_channel_first_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_LAST))
static icl_stats_t *s_amq_consumer_by_channel_last_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_NEXT))
static icl_stats_t *s_amq_consumer_by_channel_next_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_PREV))
static icl_stats_t *s_amq_consumer_by_channel_prev_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_REHOOK))
static icl_stats_t *s_amq_consumer_by_channel_rehook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_UNHOOK))
static icl_stats_t *s_amq_consumer_by_channel_unhook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_TERMINATE))
static icl_stats_t *s_amq_consumer_by_channel_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_SHOW))
static icl_stats_t *s_amq_consumer_by_channel_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_DESTROY_PUBLIC))
static icl_stats_t *s_amq_consumer_by_channel_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_ALLOC))
static icl_stats_t *s_amq_consumer_by_channel_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_FREE))
static icl_stats_t *s_amq_consumer_by_channel_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_READ_LOCK))
static icl_stats_t *s_amq_consumer_by_channel_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_WRITE_LOCK))
static icl_stats_t *s_amq_consumer_by_channel_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_UNLOCK))
static icl_stats_t *s_amq_consumer_by_channel_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_LINK))
static icl_stats_t *s_amq_consumer_by_channel_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_UNLINK))
static icl_stats_t *s_amq_consumer_by_channel_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_CACHE_INITIALISE))
static icl_stats_t *s_amq_consumer_by_channel_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_CACHE_PURGE))
static icl_stats_t *s_amq_consumer_by_channel_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_CACHE_TERMINATE))
static icl_stats_t *s_amq_consumer_by_channel_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_ANIMATE))
static icl_stats_t *s_amq_consumer_by_channel_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_NEW_IN_SCOPE))
static icl_stats_t *s_amq_consumer_by_channel_new_in_scope_stats = NULL;
#endif
#define amq_consumer_by_channel_annihilate(self)  amq_consumer_by_channel_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_consumer_by_channel_annihilate_ (
amq_consumer_by_channel_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static inline void
    amq_consumer_by_channel_rehook (
amq_consumer_t * item,                  //  Not documented
amq_consumer_t * left,                  //  Not documented
amq_consumer_t * right                  //  Not documented
);

static inline amq_consumer_t *
    amq_consumer_by_channel_unhook (
amq_consumer_t * item                   //  Not documented
);

#define amq_consumer_by_channel_alloc()  amq_consumer_by_channel_alloc_ (__FILE__, __LINE__)
static amq_consumer_by_channel_t *
    amq_consumer_by_channel_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_consumer_by_channel_free(self)  amq_consumer_by_channel_free_ (self, __FILE__, __LINE__)
static void
    amq_consumer_by_channel_free_ (
amq_consumer_by_channel_t * self,       //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_consumer_by_channel_cache_initialise (
void);

static void
    amq_consumer_by_channel_cache_purge (
void);

static void
    amq_consumer_by_channel_cache_terminate (
void);

Bool
    amq_consumer_by_channel_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_new

    Type: Component method
    Creates and initialises a new amq_consumer_by_channel_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_consumer_by_channel_t *
    amq_consumer_by_channel_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_consumer_by_channel_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_NEW))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_NEW))
    icl_trace_record (1, amq_consumer_by_channel_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_NEW))
    icl_stats_inc ("amq_consumer_by_channel_new", &s_amq_consumer_by_channel_new_stats);
#endif

    self = amq_consumer_by_channel_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CONSUMER_BY_CHANNEL_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
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
        icl_mem_set_callback (self, amq_consumer_by_channel_show_);
#endif

self->amq_consumer.by_channel_next = &self->amq_consumer;
self->amq_consumer.by_channel_prev = &self->amq_consumer;
self->amq_consumer.by_channel_head = self;

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_NEW))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_NEW))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_new_finish"
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
    amq_consumer_by_channel_annihilate

    Type: Component method
    Destroys the list and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_by_channel_annihilate_ (
    amq_consumer_by_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    int
        history_last;
#endif

amq_consumer_t
    *item;
    amq_consumer_by_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_DESTROY))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_DESTROY))
    icl_trace_record (1, amq_consumer_by_channel_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_DESTROY))
    icl_stats_inc ("amq_consumer_by_channel_annihilate", &s_amq_consumer_by_channel_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = self->links;
#endif

    AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

item = (amq_consumer_t *) self->amq_consumer.by_channel_next;
while (item != &self->amq_consumer) {
    //  Unlink child without lock (we already have the lock)               
    amq_consumer_by_channel_unhook (item);

    amq_consumer_unlink (&item);
    item = (amq_consumer_t *) self->amq_consumer.by_channel_next;
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_DESTROY))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_DESTROY))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_destroy_finish"
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
    amq_consumer_by_channel_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_SELFTEST))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_SELFTEST))
    icl_trace_record (1, amq_consumer_by_channel_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_SELFTEST))
    icl_stats_inc ("amq_consumer_by_channel_selftest", &s_amq_consumer_by_channel_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_SELFTEST))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_SELFTEST))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_selftest_finish"
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
    amq_consumer_by_channel_isempty

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Returns true if the list is empty, else returns false.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_isempty (
    amq_consumer_by_channel_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_ISEMPTY))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_isempty_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_ISEMPTY))
    icl_trace_record (1, amq_consumer_by_channel_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_ISEMPTY))
    icl_stats_inc ("amq_consumer_by_channel_isempty", &s_amq_consumer_by_channel_isempty_stats);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

rc = (self->amq_consumer.by_channel_next == &self->amq_consumer);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_ISEMPTY))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_ISEMPTY))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_isempty_finish"
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
    amq_consumer_by_channel_push

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the start of the specified list. If the item
    was on another list, it is first detached.  After this method,
    list->next points to the item.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_push (
    amq_consumer_by_channel_t * self,   //  Reference to object
    amq_consumer_t * item               //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_PUSH))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_push_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_PUSH))
    icl_trace_record (1, amq_consumer_by_channel_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_PUSH))
    icl_stats_inc ("amq_consumer_by_channel_push", &s_amq_consumer_by_channel_push_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

//  If by_channel_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->by_channel_head) {
    amq_consumer_link (item);
}
else
if (item->by_channel_head != self) {
    icl_console_print ("E: amq_consumer item inserted into multiple by_channel containers");
    assert (item->by_channel_head == self);
}
amq_consumer_by_channel_unhook (item);
amq_consumer_by_channel_rehook (item, &self->amq_consumer, (amq_consumer_t *) self->amq_consumer.by_channel_next);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_PUSH))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_PUSH))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_push_finish"
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
    amq_consumer_by_channel_pop

    Type: Component method
    Removes the next item in the list, if any, and returns it.  If
    the list was empty, returns NULL.
    
    The number of links is unchanged; removing from the list and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_by_channel_pop (
    amq_consumer_by_channel_t * self    //  The list
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_POP))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_pop_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_POP))
    icl_trace_record (1, amq_consumer_by_channel_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_POP))
    icl_stats_inc ("amq_consumer_by_channel_pop", &s_amq_consumer_by_channel_pop_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

if (self->amq_consumer.by_channel_next == &self->amq_consumer)
    item = NULL;
else {
    item = amq_consumer_by_channel_unhook ((amq_consumer_t *) self->amq_consumer.by_channel_next);
}
}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_POP))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_POP))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_pop_finish"
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
    amq_consumer_by_channel_queue

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the end of the specified list.  The item may not
    be in another list of the same class.
    
    The number of links is automatically adjusted - if the item was already
    in the list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_queue (
    amq_consumer_by_channel_t * self,   //  Reference to object
    amq_consumer_t * item               //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_QUEUE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_queue_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_QUEUE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_QUEUE))
    icl_stats_inc ("amq_consumer_by_channel_queue", &s_amq_consumer_by_channel_queue_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

//  If by_channel_head is non-null then we are moving within the       
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->by_channel_head) {
    amq_consumer_link (item);
}
else
if (item->by_channel_head != self) {
    icl_console_print ("E: amq_consumer item inserted into multiple by_channel containers");
    assert (item->by_channel_head == self);
}
amq_consumer_by_channel_unhook (item);
amq_consumer_by_channel_rehook (item, (amq_consumer_t *) self->amq_consumer.by_channel_prev, &self->amq_consumer);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_QUEUE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_QUEUE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_queue_finish"
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
    amq_consumer_by_channel_relink_before

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item before a specified item. If the item was on another list,
    it is first detached.
    
    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_relink_before (
    amq_consumer_t * item,              //  Not documented
    amq_consumer_t * where              //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code
    amq_consumer_by_channel_t *
        self = (amq_consumer_by_channel_t *) where->by_channel_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_RELINK_BEFORE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_relink_before_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_RELINK_BEFORE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_RELINK_BEFORE))
    icl_stats_inc ("amq_consumer_by_channel_relink_before", &s_amq_consumer_by_channel_relink_before_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

//  If by_channel_head is non-null then we are moving within the       
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->by_channel_head) {
    amq_consumer_link (item);
}
else
if (item->by_channel_head != self) {
    icl_console_print ("E: amq_consumer item inserted into multiple by_channel containers");
    assert (item->by_channel_head == self);
}            
amq_consumer_by_channel_unhook (item);
amq_consumer_by_channel_rehook (item, (amq_consumer_t *) where->by_channel_prev, where);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_RELINK_BEFORE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_RELINK_BEFORE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_relink_before_finish"
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
    amq_consumer_by_channel_remove

    Type: Component method
    Removes the item from any list it is in.
    
    If it was in a list, the number of links is decremented.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_remove (
    amq_consumer_t * item               //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_by_channel_t *
        self = (amq_consumer_by_channel_t *) item->by_channel_head;  //  The list
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_REMOVE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_remove_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_REMOVE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_REMOVE))
    icl_stats_inc ("amq_consumer_by_channel_remove", &s_amq_consumer_by_channel_remove_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

if (self
&&  self == item->by_channel_head) { //  Catch case where item moved
    amq_consumer_by_channel_unhook (item);
    amq_consumer_unlink (&item);
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_REMOVE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_REMOVE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_remove_finish"
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
    amq_consumer_by_channel_first

    Type: Component method
    Returns the first amq_consumer item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_by_channel_first_ (
    amq_consumer_by_channel_t * self,   //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_FIRST))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_first_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_FIRST))
    icl_trace_record (1, amq_consumer_by_channel_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_FIRST))
    icl_stats_inc ("amq_consumer_by_channel_first", &s_amq_consumer_by_channel_first_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

item = (amq_consumer_t *) self->amq_consumer.by_channel_next;
if (item == &self->amq_consumer)
    item = NULL;
else
    amq_consumer_link (item);

}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_FIRST))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_FIRST))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_first_finish"
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
    amq_consumer_by_channel_last

    Type: Component method
    Returns the last amq_consumer item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_by_channel_last_ (
    amq_consumer_by_channel_t * self,   //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_LAST))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_last_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_LAST))
    icl_trace_record (1, amq_consumer_by_channel_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_LAST))
    icl_stats_inc ("amq_consumer_by_channel_last", &s_amq_consumer_by_channel_last_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

item = (amq_consumer_t *) self->amq_consumer.by_channel_prev;
if (item == &self->amq_consumer)
    item = NULL;
else
    amq_consumer_link (item);

}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_LAST))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_LAST))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_last_finish"
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
    amq_consumer_by_channel_next

    Type: Component method
    Returns the following item on the amq_consumer list. If the provided item
    is null, returns the first item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_by_channel_next_ (
    amq_consumer_t * ( * item_p ),      //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_t *
        item = *item_p;                 //  Dereferenced item
    amq_consumer_t *
        next = NULL;                    //  The item to return
    amq_consumer_by_channel_t *
        self = (amq_consumer_by_channel_t *) item->by_channel_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_NEXT))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_next_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_NEXT))
    icl_trace_record (1, amq_consumer_by_channel_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_NEXT))
    icl_stats_inc ("amq_consumer_by_channel_next", &s_amq_consumer_by_channel_next_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

if (self
&&  self == item->by_channel_head) { //  Catch case where item moved
    next = (amq_consumer_t *) item->by_channel_next;
    if (next == &self->amq_consumer)
        next = NULL;
    else
        amq_consumer_link (next);

}
amq_consumer_unlink (item_p);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_NEXT))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_NEXT))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_next_finish"
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
    amq_consumer_by_channel_prev

    Type: Component method
    Returns the preceding item on the amq_consumer list. If the provided item
    is null, returns the last item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_by_channel_prev_ (
    amq_consumer_t * ( * item_p ),      //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_t *
        item = *item_p;                 //  Dereferenced item
    amq_consumer_t *
        prev = NULL;                    //  The item to return
    amq_consumer_by_channel_t *
        self = (amq_consumer_by_channel_t *) item->by_channel_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_PREV))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_prev_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_PREV))
    icl_trace_record (1, amq_consumer_by_channel_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_PREV))
    icl_stats_inc ("amq_consumer_by_channel_prev", &s_amq_consumer_by_channel_prev_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

if (self
&&  self == item->by_channel_head) { //  Catch case where item moved
    prev = (amq_consumer_t *) item->by_channel_prev;
    if (prev == &self->amq_consumer)
        prev = NULL;
    else
        amq_consumer_link (prev);

}
amq_consumer_unlink (item_p);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_PREV))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_PREV))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_prev_finish"
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
    amq_consumer_by_channel_rehook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    amq_consumer_by_channel_rehook (
    amq_consumer_t * item,              //  Not documented
    amq_consumer_t * left,              //  Not documented
    amq_consumer_t * right              //  Not documented
)
{
amq_consumer_t
    *swap;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_REHOOK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_rehook_start"
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

#if (defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_REHOOK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_REHOOK))
    icl_stats_inc ("amq_consumer_by_channel_rehook", &s_amq_consumer_by_channel_rehook_stats);
#endif

swap = (amq_consumer_t *) left->by_channel_next;
left->by_channel_next = item->by_channel_next;
item->by_channel_next = swap;

swap = (amq_consumer_t *) item->by_channel_prev;
item->by_channel_prev = right->by_channel_prev;
right->by_channel_prev = swap;

item->by_channel_head = left->by_channel_head;
#if (defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_REHOOK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_REHOOK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_rehook_finish"
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
    amq_consumer_by_channel_unhook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline amq_consumer_t *
    amq_consumer_by_channel_unhook (
    amq_consumer_t * item               //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_UNHOOK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_unhook_start"
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

#if (defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_UNHOOK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_UNHOOK))
    icl_stats_inc ("amq_consumer_by_channel_unhook", &s_amq_consumer_by_channel_unhook_stats);
#endif

amq_consumer_by_channel_rehook (item, (amq_consumer_t *) item->by_channel_prev, (amq_consumer_t *) item->by_channel_next);
item->by_channel_head = NULL;
#if (defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_UNHOOK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_UNHOOK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_unhook_finish"
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
    amq_consumer_by_channel_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_TERMINATE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_TERMINATE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_TERMINATE))
    icl_stats_inc ("amq_consumer_by_channel_terminate", &s_amq_consumer_by_channel_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_TERMINATE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_TERMINATE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_terminate_finish"
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
    amq_consumer_by_channel_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_consumer_by_channel_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_SHOW))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_SHOW))
    icl_trace_record (1, amq_consumer_by_channel_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_SHOW))
    icl_stats_inc ("amq_consumer_by_channel_show", &s_amq_consumer_by_channel_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_consumer_by_channel zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    if (self->history_last > AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH;
        self->history_last %= AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_consumer_by_channel>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_SHOW))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_SHOW))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_show_finish"
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
    amq_consumer_by_channel_destroy

    Type: Component method
    Destroys a amq_consumer_by_channel_t object. Takes the address of a
    amq_consumer_by_channel_t reference (a pointer to a pointer) and nullifies the
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
    amq_consumer_by_channel_destroy_ (
    amq_consumer_by_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_consumer_by_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_DESTROY_PUBLIC))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_DESTROY_PUBLIC))
    icl_trace_record (1, amq_consumer_by_channel_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_DESTROY_PUBLIC))
    icl_stats_inc ("amq_consumer_by_channel_destroy", &s_amq_consumer_by_channel_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_consumer_by_channel_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on amq_consumer_by_channel object");
        amq_consumer_by_channel_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_consumer_by_channel_free_ ((amq_consumer_by_channel_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_DESTROY_PUBLIC))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_DESTROY_PUBLIC))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_destroy_public_finish"
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
    amq_consumer_by_channel_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_consumer_by_channel_t *
    amq_consumer_by_channel_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_consumer_by_channel_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_ALLOC))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_ALLOC))
    icl_trace_record (1, amq_consumer_by_channel_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_ALLOC))
    icl_stats_inc ("amq_consumer_by_channel_alloc", &s_amq_consumer_by_channel_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_consumer_by_channel_cache_initialise ();

self = (amq_consumer_by_channel_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_consumer_by_channel_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_ALLOC))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_ALLOC))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_alloc_finish"
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
    amq_consumer_by_channel_free

    Type: Component method
    Freess a amq_consumer_by_channel_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_by_channel_free_ (
    amq_consumer_by_channel_t * self,   //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_FREE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_FREE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_FREE))
    icl_stats_inc ("amq_consumer_by_channel_free", &s_amq_consumer_by_channel_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (amq_consumer_by_channel_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_consumer_by_channel_t));
        self->object_tag = AMQ_CONSUMER_BY_CHANNEL_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_FREE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_FREE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_free_finish"
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
    amq_consumer_by_channel_read_lock

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_read_lock (
    amq_consumer_by_channel_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_READ_LOCK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_READ_LOCK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_READ_LOCK))
    icl_stats_inc ("amq_consumer_by_channel_read_lock", &s_amq_consumer_by_channel_read_lock_stats);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_READ_LOCK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_READ_LOCK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_read_lock_finish"
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
    amq_consumer_by_channel_write_lock

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_write_lock (
    amq_consumer_by_channel_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_WRITE_LOCK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_WRITE_LOCK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_WRITE_LOCK))
    icl_stats_inc ("amq_consumer_by_channel_write_lock", &s_amq_consumer_by_channel_write_lock_stats);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_WRITE_LOCK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_WRITE_LOCK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_write_lock_finish"
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
    amq_consumer_by_channel_unlock

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_unlock (
    amq_consumer_by_channel_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_UNLOCK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_UNLOCK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_UNLOCK))
    icl_stats_inc ("amq_consumer_by_channel_unlock", &s_amq_consumer_by_channel_unlock_stats);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_UNLOCK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_UNLOCK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_unlock_finish"
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
    amq_consumer_by_channel_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_consumer_by_channel_t *
    amq_consumer_by_channel_link_ (
    amq_consumer_by_channel_t * self,   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_LINK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_LINK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_LINK))
    icl_stats_inc ("amq_consumer_by_channel_link", &s_amq_consumer_by_channel_link_stats);
#endif

    if (self) {
        AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_LINK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_LINK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_link_finish"
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
    amq_consumer_by_channel_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_unlink_ (
    amq_consumer_by_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    int
        history_last;
#endif

    amq_consumer_by_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_UNLINK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_UNLINK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_UNLINK))
    icl_stats_inc ("amq_consumer_by_channel_unlink", &s_amq_consumer_by_channel_unlink_stats);
#endif

    if (self) {
        AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_consumer_by_channel object");
            amq_consumer_by_channel_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_consumer_by_channel_annihilate_ (self_p, file, line);
        amq_consumer_by_channel_free_ ((amq_consumer_by_channel_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_UNLINK))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_UNLINK))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_unlink_finish"
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
    amq_consumer_by_channel_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_by_channel_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_CACHE_INITIALISE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_CACHE_INITIALISE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_CACHE_INITIALISE))
    icl_stats_inc ("amq_consumer_by_channel_cache_initialise", &s_amq_consumer_by_channel_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_consumer_by_channel_t));
icl_system_register (amq_consumer_by_channel_cache_purge, amq_consumer_by_channel_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_CACHE_INITIALISE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_CACHE_INITIALISE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_cache_initialise_finish"
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
    amq_consumer_by_channel_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_by_channel_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_CACHE_PURGE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_CACHE_PURGE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_CACHE_PURGE))
    icl_stats_inc ("amq_consumer_by_channel_cache_purge", &s_amq_consumer_by_channel_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_CACHE_PURGE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_CACHE_PURGE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_cache_purge_finish"
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
    amq_consumer_by_channel_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_by_channel_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_CACHE_TERMINATE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_CACHE_TERMINATE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_CACHE_TERMINATE))
    icl_stats_inc ("amq_consumer_by_channel_cache_terminate", &s_amq_consumer_by_channel_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_CACHE_TERMINATE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_CACHE_TERMINATE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_cache_terminate_finish"
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
    amq_consumer_by_channel_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_ANIMATE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_ANIMATE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_ANIMATE))
    icl_stats_inc ("amq_consumer_by_channel_animate", &s_amq_consumer_by_channel_animate_stats);
#endif

amq_consumer_by_channel_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_ANIMATE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_ANIMATE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_animate_finish"
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
    amq_consumer_by_channel_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_new_in_scope_ (
    amq_consumer_by_channel_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_NEW_IN_SCOPE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_NEW_IN_SCOPE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL)  ||  defined (BASE_STATS_AMQ_CONSUMER_BY_CHANNEL_NEW_IN_SCOPE))
    icl_stats_inc ("amq_consumer_by_channel_new_in_scope", &s_amq_consumer_by_channel_new_in_scope_stats);
#endif

*self_p = amq_consumer_by_channel_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_consumer_by_channel_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_NEW_IN_SCOPE))
    icl_trace_record (1, amq_consumer_by_channel_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BY_CHANNEL_NEW_IN_SCOPE))
    if (amq_consumer_by_channel_animating)
        icl_console_print ("<amq_consumer_by_channel_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_NEW)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_DESTROY)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_SELFTEST)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_ISEMPTY)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_PUSH)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_POP)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_QUEUE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_RELINK_BEFORE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_REMOVE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_FIRST)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_LAST)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_NEXT)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_PREV)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_REHOOK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_UNHOOK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_SHOW)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_ALLOC)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_FREE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_READ_LOCK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_UNLOCK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_LINK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_UNLINK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_ANIMATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_CHANNEL_NEW_IN_SCOPE) )
void
amq_consumer_by_channel_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
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
                                   "amq_consumer_by_channel %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_consumer_by_channel_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_consumer_by_channel_component  = "amq_consumer_by_channel ";
char *amq_consumer_by_channel_version  = "1.0 ";
char *amq_consumer_by_channel_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_consumer_by_channel_filename  = "amq_consumer_by_channel.icl ";
char *amq_consumer_by_channel_builddate  = "2010/10/06 ";
char *amq_consumer_by_channel_version_end  = "VeRsIoNeNd:ipc";

