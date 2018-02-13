/*---------------------------------------------------------------------------
    smt_timer_request_by_thread.c - smt_timer_request_by_thread component

    This class implements the list container for smt_timer_request
    Generated from smt_timer_request_by_thread.icl by icl_gen using GSL/4.
    
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
#include "smt_timer_request_by_thread.h"  //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_timer_request_by_thread_t

//  Shorthands for class methods                                               

#define self_new            smt_timer_request_by_thread_new
#define self_annihilate     smt_timer_request_by_thread_annihilate
#define self_selftest       smt_timer_request_by_thread_selftest
#define self_isempty        smt_timer_request_by_thread_isempty
#define self_push           smt_timer_request_by_thread_push
#define self_pop            smt_timer_request_by_thread_pop
#define self_queue          smt_timer_request_by_thread_queue
#define self_relink_before  smt_timer_request_by_thread_relink_before
#define self_remove         smt_timer_request_by_thread_remove
#define self_first          smt_timer_request_by_thread_first
#define self_last           smt_timer_request_by_thread_last
#define self_next           smt_timer_request_by_thread_next
#define self_prev           smt_timer_request_by_thread_prev
#define self_rehook         smt_timer_request_by_thread_rehook
#define self_unhook         smt_timer_request_by_thread_unhook
#define self_terminate      smt_timer_request_by_thread_terminate
#define self_show           smt_timer_request_by_thread_show
#define self_destroy        smt_timer_request_by_thread_destroy
#define self_alloc          smt_timer_request_by_thread_alloc
#define self_free           smt_timer_request_by_thread_free
#define self_cache_initialise  smt_timer_request_by_thread_cache_initialise
#define self_cache_purge    smt_timer_request_by_thread_cache_purge
#define self_cache_terminate  smt_timer_request_by_thread_cache_terminate
#define self_animate        smt_timer_request_by_thread_animate
#define self_new_in_scope   smt_timer_request_by_thread_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_NEW))
static icl_stats_t *s_smt_timer_request_by_thread_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_DESTROY))
static icl_stats_t *s_smt_timer_request_by_thread_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_SELFTEST))
static icl_stats_t *s_smt_timer_request_by_thread_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_ISEMPTY))
static icl_stats_t *s_smt_timer_request_by_thread_isempty_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_PUSH))
static icl_stats_t *s_smt_timer_request_by_thread_push_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_POP))
static icl_stats_t *s_smt_timer_request_by_thread_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_QUEUE))
static icl_stats_t *s_smt_timer_request_by_thread_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_RELINK_BEFORE))
static icl_stats_t *s_smt_timer_request_by_thread_relink_before_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_REMOVE))
static icl_stats_t *s_smt_timer_request_by_thread_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_FIRST))
static icl_stats_t *s_smt_timer_request_by_thread_first_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_LAST))
static icl_stats_t *s_smt_timer_request_by_thread_last_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_NEXT))
static icl_stats_t *s_smt_timer_request_by_thread_next_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_PREV))
static icl_stats_t *s_smt_timer_request_by_thread_prev_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_REHOOK))
static icl_stats_t *s_smt_timer_request_by_thread_rehook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_UNHOOK))
static icl_stats_t *s_smt_timer_request_by_thread_unhook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_TERMINATE))
static icl_stats_t *s_smt_timer_request_by_thread_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_SHOW))
static icl_stats_t *s_smt_timer_request_by_thread_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_DESTROY_PUBLIC))
static icl_stats_t *s_smt_timer_request_by_thread_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_ALLOC))
static icl_stats_t *s_smt_timer_request_by_thread_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_FREE))
static icl_stats_t *s_smt_timer_request_by_thread_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_CACHE_INITIALISE))
static icl_stats_t *s_smt_timer_request_by_thread_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_CACHE_PURGE))
static icl_stats_t *s_smt_timer_request_by_thread_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_CACHE_TERMINATE))
static icl_stats_t *s_smt_timer_request_by_thread_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_ANIMATE))
static icl_stats_t *s_smt_timer_request_by_thread_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_NEW_IN_SCOPE))
static icl_stats_t *s_smt_timer_request_by_thread_new_in_scope_stats = NULL;
#endif
static void
    smt_timer_request_by_thread_annihilate (
smt_timer_request_by_thread_t * ( * self_p )  //  Reference to object reference
);

static inline void
    smt_timer_request_by_thread_rehook (
smt_timer_request_t * item,             //  Not documented
smt_timer_request_t * left,             //  Not documented
smt_timer_request_t * right             //  Not documented
);

static inline smt_timer_request_t *
    smt_timer_request_by_thread_unhook (
smt_timer_request_t * item              //  Not documented
);

#define smt_timer_request_by_thread_alloc()  smt_timer_request_by_thread_alloc_ (__FILE__, __LINE__)
static smt_timer_request_by_thread_t *
    smt_timer_request_by_thread_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_timer_request_by_thread_free (
smt_timer_request_by_thread_t * self    //  Object reference
);

static void
    smt_timer_request_by_thread_cache_initialise (
void);

static void
    smt_timer_request_by_thread_cache_purge (
void);

static void
    smt_timer_request_by_thread_cache_terminate (
void);

Bool
    smt_timer_request_by_thread_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    smt_timer_request_by_thread_new

    Type: Component method
    Creates and initialises a new smt_timer_request_by_thread_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

smt_timer_request_by_thread_t *
    smt_timer_request_by_thread_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    smt_timer_request_by_thread_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_NEW))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_NEW))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_NEW))
    icl_stats_inc ("smt_timer_request_by_thread_new", &s_smt_timer_request_by_thread_new_stats);
#endif

    self = smt_timer_request_by_thread_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_TIMER_REQUEST_BY_THREAD_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_timer_request_by_thread_show_);
#endif

self->smt_timer_request.by_thread_next = &self->smt_timer_request;
self->smt_timer_request.by_thread_prev = &self->smt_timer_request;
self->smt_timer_request.by_thread_head = self;

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_NEW))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_NEW))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_new_finish"
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
    smt_timer_request_by_thread_annihilate

    Type: Component method
    Destroys the list and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    smt_timer_request_by_thread_annihilate (
    smt_timer_request_by_thread_t * ( * self_p )  //  Reference to object reference
)
{

smt_timer_request_t
    *item;
    smt_timer_request_by_thread_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_DESTROY))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_DESTROY))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_DESTROY))
    icl_stats_inc ("smt_timer_request_by_thread_annihilate", &s_smt_timer_request_by_thread_annihilate_stats);
#endif

SMT_TIMER_REQUEST_BY_THREAD_ASSERT_SANE (self);

item = (smt_timer_request_t *) self->smt_timer_request.by_thread_next;
while (item != &self->smt_timer_request) {
    //  Unlink child without lock (we already have the lock)               
    smt_timer_request_by_thread_unhook (item);

    smt_timer_request_destroy (&item);
    item = (smt_timer_request_t *) self->smt_timer_request.by_thread_next;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_DESTROY))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_DESTROY))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

}
/*  -------------------------------------------------------------------------
    smt_timer_request_by_thread_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_timer_request_by_thread_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_SELFTEST))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_SELFTEST))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_SELFTEST))
    icl_stats_inc ("smt_timer_request_by_thread_selftest", &s_smt_timer_request_by_thread_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_SELFTEST))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_SELFTEST))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_selftest_finish"
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
    smt_timer_request_by_thread_isempty

    Type: Component method
    Accepts a smt_timer_request_by_thread_t reference and returns zero in case of success,
    1 in case of errors.
    Returns true if the list is empty, else returns false.
    -------------------------------------------------------------------------
 */

int
    smt_timer_request_by_thread_isempty (
    smt_timer_request_by_thread_t * self  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_ISEMPTY))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_isempty_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_ISEMPTY))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_ISEMPTY))
    icl_stats_inc ("smt_timer_request_by_thread_isempty", &s_smt_timer_request_by_thread_isempty_stats);
#endif

SMT_TIMER_REQUEST_BY_THREAD_ASSERT_SANE (self);

rc = (self->smt_timer_request.by_thread_next == &self->smt_timer_request);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_ISEMPTY))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_ISEMPTY))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_isempty_finish"
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
    smt_timer_request_by_thread_push

    Type: Component method
    Accepts a smt_timer_request_by_thread_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the start of the specified list. If the item
    was on another list, it is first detached.  After this method,
    list->next points to the item.
    -------------------------------------------------------------------------
 */

int
    smt_timer_request_by_thread_push (
    smt_timer_request_by_thread_t * self,   //  Reference to object
    smt_timer_request_t * item          //  Not documented
)
{


    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_PUSH))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_push_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_PUSH))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_PUSH))
    icl_stats_inc ("smt_timer_request_by_thread_push", &s_smt_timer_request_by_thread_push_stats);
#endif



SMT_TIMER_REQUEST_BY_THREAD_ASSERT_SANE (self);

//  If by_thread_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->by_thread_head) {
}
else
if (item->by_thread_head != self) {
    icl_console_print ("E: smt_timer_request item inserted into multiple by_thread containers");
    assert (item->by_thread_head == self);
}
smt_timer_request_by_thread_unhook (item);
smt_timer_request_by_thread_rehook (item, &self->smt_timer_request, (smt_timer_request_t *) self->smt_timer_request.by_thread_next);



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_PUSH))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_PUSH))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_push_finish"
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
    smt_timer_request_by_thread_pop

    Type: Component method
    Removes the next item in the list, if any, and returns it.  If
    the list was empty, returns NULL.
    
    The number of links is unchanged; removing from the list and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

smt_timer_request_t *
    smt_timer_request_by_thread_pop (
    smt_timer_request_by_thread_t * self  //  The list
)
{


    smt_timer_request_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_POP))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_pop_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_POP))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_POP))
    icl_stats_inc ("smt_timer_request_by_thread_pop", &s_smt_timer_request_by_thread_pop_stats);
#endif



SMT_TIMER_REQUEST_BY_THREAD_ASSERT_SANE (self);

if (self->smt_timer_request.by_thread_next == &self->smt_timer_request)
    item = NULL;
else {
    item = smt_timer_request_by_thread_unhook ((smt_timer_request_t *) self->smt_timer_request.by_thread_next);
}



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_POP))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_POP))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_pop_finish"
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
    smt_timer_request_by_thread_queue

    Type: Component method
    Accepts a smt_timer_request_by_thread_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the end of the specified list.  The item may not
    be in another list of the same class.
    
    The number of links is automatically adjusted - if the item was already
    in the list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    smt_timer_request_by_thread_queue (
    smt_timer_request_by_thread_t * self,   //  Reference to object
    smt_timer_request_t * item          //  Not documented
)
{


    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_QUEUE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_queue_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_QUEUE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_QUEUE))
    icl_stats_inc ("smt_timer_request_by_thread_queue", &s_smt_timer_request_by_thread_queue_stats);
#endif



SMT_TIMER_REQUEST_BY_THREAD_ASSERT_SANE (self);

//  If by_thread_head is non-null then we are moving within the        
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->by_thread_head) {
}
else
if (item->by_thread_head != self) {
    icl_console_print ("E: smt_timer_request item inserted into multiple by_thread containers");
    assert (item->by_thread_head == self);
}
smt_timer_request_by_thread_unhook (item);
smt_timer_request_by_thread_rehook (item, (smt_timer_request_t *) self->smt_timer_request.by_thread_prev, &self->smt_timer_request);



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_QUEUE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_QUEUE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_queue_finish"
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
    smt_timer_request_by_thread_relink_before

    Type: Component method
    Accepts a smt_timer_request_by_thread_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item before a specified item. If the item was on another list,
    it is first detached.
    
    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    smt_timer_request_by_thread_relink_before (
    smt_timer_request_t * item,         //  Not documented
    smt_timer_request_t * where         //  Not documented
)
{


    int
        rc = 0;                         //  Return code
    smt_timer_request_by_thread_t *
        self = (smt_timer_request_by_thread_t *) where->by_thread_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_RELINK_BEFORE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_relink_before_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_RELINK_BEFORE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_RELINK_BEFORE))
    icl_stats_inc ("smt_timer_request_by_thread_relink_before", &s_smt_timer_request_by_thread_relink_before_stats);
#endif



SMT_TIMER_REQUEST_BY_THREAD_ASSERT_SANE (self);

//  If by_thread_head is non-null then we are moving within the        
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->by_thread_head) {
}
else
if (item->by_thread_head != self) {
    icl_console_print ("E: smt_timer_request item inserted into multiple by_thread containers");
    assert (item->by_thread_head == self);
}            
smt_timer_request_by_thread_unhook (item);
smt_timer_request_by_thread_rehook (item, (smt_timer_request_t *) where->by_thread_prev, where);



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_RELINK_BEFORE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_RELINK_BEFORE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_relink_before_finish"
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
    smt_timer_request_by_thread_remove

    Type: Component method
    Removes the item from any list it is in.
    
    If it was in a list, the number of links is decremented.
    -------------------------------------------------------------------------
 */

int
    smt_timer_request_by_thread_remove (
    smt_timer_request_t * item          //  Not documented
)
{


    smt_timer_request_by_thread_t *
        self = (smt_timer_request_by_thread_t *) item->by_thread_head;  //  The list
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_REMOVE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_remove_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_REMOVE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_REMOVE))
    icl_stats_inc ("smt_timer_request_by_thread_remove", &s_smt_timer_request_by_thread_remove_stats);
#endif



if (self
&&  self == item->by_thread_head) { //  Catch case where item moved
    smt_timer_request_by_thread_unhook (item);
}


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_REMOVE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_REMOVE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_remove_finish"
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
    smt_timer_request_by_thread_first

    Type: Component method
    Returns the first smt_timer_request item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

smt_timer_request_t *
    smt_timer_request_by_thread_first_ (
    smt_timer_request_by_thread_t * self,   //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    smt_timer_request_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_FIRST))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_first_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_FIRST))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_FIRST))
    icl_stats_inc ("smt_timer_request_by_thread_first", &s_smt_timer_request_by_thread_first_stats);
#endif



SMT_TIMER_REQUEST_BY_THREAD_ASSERT_SANE (self);

item = (smt_timer_request_t *) self->smt_timer_request.by_thread_next;
if (item == &self->smt_timer_request)
    item = NULL;




#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_FIRST))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_FIRST))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_first_finish"
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
    smt_timer_request_by_thread_last

    Type: Component method
    Returns the last smt_timer_request item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

smt_timer_request_t *
    smt_timer_request_by_thread_last_ (
    smt_timer_request_by_thread_t * self,   //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    smt_timer_request_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_LAST))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_last_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_LAST))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_LAST))
    icl_stats_inc ("smt_timer_request_by_thread_last", &s_smt_timer_request_by_thread_last_stats);
#endif



SMT_TIMER_REQUEST_BY_THREAD_ASSERT_SANE (self);

item = (smt_timer_request_t *) self->smt_timer_request.by_thread_prev;
if (item == &self->smt_timer_request)
    item = NULL;




#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_LAST))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_LAST))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_last_finish"
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
    smt_timer_request_by_thread_next

    Type: Component method
    Returns the following item on the smt_timer_request list. If the provided item
    is null, returns the first item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

smt_timer_request_t *
    smt_timer_request_by_thread_next_ (
    smt_timer_request_t * ( * item_p ),   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    smt_timer_request_t *
        item = *item_p;                 //  Dereferenced item
    smt_timer_request_t *
        next = NULL;                    //  The item to return
    smt_timer_request_by_thread_t *
        self = (smt_timer_request_by_thread_t *) item->by_thread_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_NEXT))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_next_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_NEXT))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_NEXT))
    icl_stats_inc ("smt_timer_request_by_thread_next", &s_smt_timer_request_by_thread_next_stats);
#endif



if (self
&&  self == item->by_thread_head) { //  Catch case where item moved
    next = (smt_timer_request_t *) item->by_thread_next;
    if (next == &self->smt_timer_request)
        next = NULL;

}



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_NEXT))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_NEXT))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_next_finish"
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
    smt_timer_request_by_thread_prev

    Type: Component method
    Returns the preceding item on the smt_timer_request list. If the provided item
    is null, returns the last item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

smt_timer_request_t *
    smt_timer_request_by_thread_prev_ (
    smt_timer_request_t * ( * item_p ),   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    smt_timer_request_t *
        item = *item_p;                 //  Dereferenced item
    smt_timer_request_t *
        prev = NULL;                    //  The item to return
    smt_timer_request_by_thread_t *
        self = (smt_timer_request_by_thread_t *) item->by_thread_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_PREV))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_prev_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_PREV))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_PREV))
    icl_stats_inc ("smt_timer_request_by_thread_prev", &s_smt_timer_request_by_thread_prev_stats);
#endif



if (self
&&  self == item->by_thread_head) { //  Catch case where item moved
    prev = (smt_timer_request_t *) item->by_thread_prev;
    if (prev == &self->smt_timer_request)
        prev = NULL;

}



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_PREV))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_PREV))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_prev_finish"
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
    smt_timer_request_by_thread_rehook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    smt_timer_request_by_thread_rehook (
    smt_timer_request_t * item,         //  Not documented
    smt_timer_request_t * left,         //  Not documented
    smt_timer_request_t * right         //  Not documented
)
{
smt_timer_request_t
    *swap;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_REHOOK))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_rehook_start"
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

#if (defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_REHOOK))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_REHOOK))
    icl_stats_inc ("smt_timer_request_by_thread_rehook", &s_smt_timer_request_by_thread_rehook_stats);
#endif

swap = (smt_timer_request_t *) left->by_thread_next;
left->by_thread_next = item->by_thread_next;
item->by_thread_next = swap;

swap = (smt_timer_request_t *) item->by_thread_prev;
item->by_thread_prev = right->by_thread_prev;
right->by_thread_prev = swap;

item->by_thread_head = left->by_thread_head;
#if (defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_REHOOK))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_REHOOK))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_rehook_finish"
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
    smt_timer_request_by_thread_unhook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline smt_timer_request_t *
    smt_timer_request_by_thread_unhook (
    smt_timer_request_t * item          //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_UNHOOK))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_unhook_start"
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

#if (defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_UNHOOK))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_UNHOOK))
    icl_stats_inc ("smt_timer_request_by_thread_unhook", &s_smt_timer_request_by_thread_unhook_stats);
#endif

smt_timer_request_by_thread_rehook (item, (smt_timer_request_t *) item->by_thread_prev, (smt_timer_request_t *) item->by_thread_next);
item->by_thread_head = NULL;
#if (defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_UNHOOK))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_UNHOOK))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_unhook_finish"
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
    smt_timer_request_by_thread_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_timer_request_by_thread_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_TERMINATE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_TERMINATE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_TERMINATE))
    icl_stats_inc ("smt_timer_request_by_thread_terminate", &s_smt_timer_request_by_thread_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_TERMINATE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_TERMINATE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_terminate_finish"
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
    smt_timer_request_by_thread_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_timer_request_by_thread_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
smt_timer_request_by_thread_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_SHOW))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_SHOW))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_SHOW))
    icl_stats_inc ("smt_timer_request_by_thread_show", &s_smt_timer_request_by_thread_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <smt_timer_request_by_thread file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_SHOW))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_SHOW))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_show_finish"
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
    smt_timer_request_by_thread_destroy

    Type: Component method
    Destroys a smt_timer_request_by_thread_t object. Takes the address of a
    smt_timer_request_by_thread_t reference (a pointer to a pointer) and nullifies the
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
    smt_timer_request_by_thread_destroy_ (
    smt_timer_request_by_thread_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    smt_timer_request_by_thread_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_DESTROY_PUBLIC))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_DESTROY_PUBLIC))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_DESTROY_PUBLIC))
    icl_stats_inc ("smt_timer_request_by_thread_destroy", &s_smt_timer_request_by_thread_destroy_stats);
#endif

if (self) {
    smt_timer_request_by_thread_annihilate (self_p);
    smt_timer_request_by_thread_free ((smt_timer_request_by_thread_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_DESTROY_PUBLIC))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_DESTROY_PUBLIC))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    smt_timer_request_by_thread_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_timer_request_by_thread_t *
    smt_timer_request_by_thread_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_timer_request_by_thread_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_ALLOC))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_ALLOC))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_ALLOC))
    icl_stats_inc ("smt_timer_request_by_thread_alloc", &s_smt_timer_request_by_thread_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_timer_request_by_thread_cache_initialise ();

self = (smt_timer_request_by_thread_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (smt_timer_request_by_thread_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_ALLOC))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_ALLOC))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_alloc_finish"
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
    smt_timer_request_by_thread_free

    Type: Component method
    Freess a smt_timer_request_by_thread_t object.
    -------------------------------------------------------------------------
 */

static void
    smt_timer_request_by_thread_free (
    smt_timer_request_by_thread_t * self  //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_FREE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_FREE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_FREE))
    icl_stats_inc ("smt_timer_request_by_thread_free", &s_smt_timer_request_by_thread_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (smt_timer_request_by_thread_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (smt_timer_request_by_thread_t));
        self->object_tag = SMT_TIMER_REQUEST_BY_THREAD_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_FREE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_FREE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_free_finish"
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
    smt_timer_request_by_thread_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_timer_request_by_thread_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_INITIALISE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_INITIALISE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_CACHE_INITIALISE))
    icl_stats_inc ("smt_timer_request_by_thread_cache_initialise", &s_smt_timer_request_by_thread_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_timer_request_by_thread_t));
icl_system_register (smt_timer_request_by_thread_cache_purge, smt_timer_request_by_thread_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_INITIALISE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_INITIALISE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_cache_initialise_finish"
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
    smt_timer_request_by_thread_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_timer_request_by_thread_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_PURGE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_PURGE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_CACHE_PURGE))
    icl_stats_inc ("smt_timer_request_by_thread_cache_purge", &s_smt_timer_request_by_thread_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_PURGE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_PURGE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_cache_purge_finish"
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
    smt_timer_request_by_thread_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_timer_request_by_thread_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_TERMINATE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_TERMINATE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_CACHE_TERMINATE))
    icl_stats_inc ("smt_timer_request_by_thread_cache_terminate", &s_smt_timer_request_by_thread_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_TERMINATE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_TERMINATE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_cache_terminate_finish"
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
    smt_timer_request_by_thread_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_timer_request_by_thread_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_ANIMATE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_ANIMATE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_ANIMATE))
    icl_stats_inc ("smt_timer_request_by_thread_animate", &s_smt_timer_request_by_thread_animate_stats);
#endif

smt_timer_request_by_thread_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_ANIMATE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_ANIMATE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_animate_finish"
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
    smt_timer_request_by_thread_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_timer_request_by_thread_new_in_scope_ (
    smt_timer_request_by_thread_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_NEW_IN_SCOPE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_NEW_IN_SCOPE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_BY_THREAD_NEW_IN_SCOPE))
    icl_stats_inc ("smt_timer_request_by_thread_new_in_scope", &s_smt_timer_request_by_thread_new_in_scope_stats);
#endif

*self_p = smt_timer_request_by_thread_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_timer_request_by_thread_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_NEW_IN_SCOPE))
    icl_trace_record (1, smt_timer_request_by_thread_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_BY_THREAD_NEW_IN_SCOPE))
    if (smt_timer_request_by_thread_animating)
        icl_console_print ("<smt_timer_request_by_thread_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_NEW)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_DESTROY)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_SELFTEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_ISEMPTY)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_PUSH)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_POP)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_QUEUE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_RELINK_BEFORE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_REMOVE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_FIRST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_LAST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_NEXT)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_PREV)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_REHOOK)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_UNHOOK)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_TERMINATE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_SHOW)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_ALLOC)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_FREE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_PURGE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_ANIMATE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_BY_THREAD_NEW_IN_SCOPE) )
void
smt_timer_request_by_thread_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
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
        case 21: method_name = "cache initialise"; break;
        case 22: method_name = "cache purge"; break;
        case 23: method_name = "cache terminate"; break;
        case 24: method_name = "animate"; break;
        case 25: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_timer_request_by_thread %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_timer_request_by_thread_version_start  = "VeRsIoNsTaRt:ipc";
char *smt_timer_request_by_thread_component  = "smt_timer_request_by_thread ";
char *smt_timer_request_by_thread_version  = "1.0 ";
char *smt_timer_request_by_thread_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_timer_request_by_thread_filename  = "smt_timer_request_by_thread.icl ";
char *smt_timer_request_by_thread_builddate  = "2010/10/06 ";
char *smt_timer_request_by_thread_version_end  = "VeRsIoNeNd:ipc";

