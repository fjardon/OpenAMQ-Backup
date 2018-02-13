/*---------------------------------------------------------------------------
    icl_mem_lockfree.c - icl_mem_lockfree component

    A lightweight memory allocator using lock-free freelists.
    Generated from icl_mem_lockfree.icl by icl_gen using GSL/4.
    
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
#include "icl_mem_lockfree.h"           //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_mem_lockfree_t

//  Shorthands for class methods                                               

#define self_cache_alloc    icl_mem_lockfree_cache_alloc
#define self_alloc          icl_mem_lockfree_alloc
#define self_realloc        icl_mem_lockfree_realloc
#define self_free           icl_mem_lockfree_free
#define self_list_new       icl_mem_lockfree_list_new
#define self_list_destroy   icl_mem_lockfree_list_destroy
#define self_cache_insert   icl_mem_lockfree_cache_insert
#define self_cache_reuse    icl_mem_lockfree_cache_reuse
#define self_new            icl_mem_lockfree_new
#define self_cache_recycle  icl_mem_lockfree_cache_recycle
#define self_cache_purge    icl_mem_lockfree_cache_purge
#define self_cache_reset    icl_mem_lockfree_cache_reset
#define self_cache_assert   icl_mem_lockfree_cache_assert
#define self_show           icl_mem_lockfree_show
#define self_possess        icl_mem_lockfree_possess
#define self_set_callback   icl_mem_lockfree_set_callback
#define self_selftest       icl_mem_lockfree_selftest
#define self_cache_pop      icl_mem_lockfree_cache_pop
#define self_cache_new      icl_mem_lockfree_cache_new
#define self_destroy        icl_mem_lockfree_destroy
#define self_animate        icl_mem_lockfree_animate

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_ALLOC))
       icl_stats_t *s_icl_mem_lockfree_cache_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_ALLOC))
       icl_stats_t *s_icl_mem_lockfree_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_REALLOC))
       icl_stats_t *s_icl_mem_lockfree_realloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_FREE))
       icl_stats_t *s_icl_mem_lockfree_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_LIST_NEW))
static icl_stats_t *s_icl_mem_lockfree_list_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_LIST_DESTROY))
static icl_stats_t *s_icl_mem_lockfree_list_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_INSERT))
       icl_stats_t *s_icl_mem_lockfree_cache_insert_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_REUSE))
       icl_stats_t *s_icl_mem_lockfree_cache_reuse_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_NEW))
static icl_stats_t *s_icl_mem_lockfree_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_RECYCLE))
       icl_stats_t *s_icl_mem_lockfree_cache_recycle_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_PURGE))
static icl_stats_t *s_icl_mem_lockfree_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_RESET))
       icl_stats_t *s_icl_mem_lockfree_cache_reset_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_ASSERT))
static icl_stats_t *s_icl_mem_lockfree_cache_assert_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_SHOW))
static icl_stats_t *s_icl_mem_lockfree_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_POSSESS))
       icl_stats_t *s_icl_mem_lockfree_possess_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_SET_CALLBACK))
       icl_stats_t *s_icl_mem_lockfree_set_callback_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_SELFTEST))
static icl_stats_t *s_icl_mem_lockfree_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_POP))
static icl_stats_t *s_icl_mem_lockfree_cache_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_NEW))
static icl_stats_t *s_icl_mem_lockfree_cache_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_DESTROY))
static icl_stats_t *s_icl_mem_lockfree_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_ANIMATE))
static icl_stats_t *s_icl_mem_lockfree_animate_stats = NULL;
#endif
Bool
    icl_mem_lockfree_animating = TRUE;  //  Animation enabled by default
//  Global variables                                                           

Bool
    s_icl_mem_lockfree_active = FALSE;
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_list_new

    Type: Component method
    -------------------------------------------------------------------------
 */

icl_mem_lockfree_list_t *
    icl_mem_lockfree_list_new (
void)
{
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    icl_mem_lockfree_t
        *initial_node_0,
        *initial_node_1;
    freelist_exit_tag_t
        initial_exit_tag_0 = {0, 2, 0, 0, 0},
        initial_exit_tag_1 = {0, 0, 0, 0, 0};
#endif
    icl_mem_lockfree_list_t *
        self = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_LIST_NEW))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_list_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_LIST_NEW))
    icl_stats_inc ("icl_mem_lockfree_list_new", &s_icl_mem_lockfree_list_new_stats);
#endif


#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    initial_node_0 = malloc (sizeof (icl_mem_lockfree_t));
    initial_node_1 = malloc (sizeof (icl_mem_lockfree_t));

    initial_node_0->next     = NULL;
    initial_node_0->prev     = initial_node_1;
    initial_node_0->exit_tag = initial_exit_tag_0;

    initial_node_1->next     = NULL;
    initial_node_1->prev     = NULL;
    initial_node_1->exit_tag = initial_exit_tag_1;

    self = malloc (sizeof (icl_mem_lockfree_list_t));

    self->head                 = malloc (sizeof (freelist_llsc_t));
    self->head->ptr0           = initial_node_0;
    self->head->ptr1           = initial_node_1;
    self->head->entry.ver      = 0;
    self->head->entry.count    = 0;

    self->tail                  = malloc (sizeof (freelist_llsc_t));
    self->tail->ptr0            = initial_node_0;
    self->tail->ptr1            = initial_node_1;
    self->tail->entry.ver       = 0;
    self->tail->entry.count     = 0;

    icl_apr_assert (apr_threadkey_private_create (&self->key, NULL, icl_global_pool));
#endif
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_LIST_NEW))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_list_new_finish"
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


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_list_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_mem_lockfree_list_destroy (
    icl_mem_lockfree_list_t * ( * self_p )  //  Not documented
)
{
    icl_mem_lockfree_list_t *
        self = *self_p;                 //  Dereferenced self

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_LIST_DESTROY))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_list_destroy_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_LIST_DESTROY))
    icl_stats_inc ("icl_mem_lockfree_list_destroy", &s_icl_mem_lockfree_list_destroy_stats);
#endif

#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    free ((icl_mem_lockfree_t *) self->head);
    free ((icl_mem_lockfree_t *) self->tail);
    icl_apr_assert (apr_threadkey_private_delete (self->key));
    free (self);
#else
    self = NULL;                        //  To avoid compilation warning
#endif
    *self_p = NULL;
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_LIST_DESTROY))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_list_destroy_finish"
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
    icl_mem_lockfree_new

    Type: Component method
    Allocate a block.
    -------------------------------------------------------------------------
 */

icl_mem_lockfree_t *
    icl_mem_lockfree_new (
    size_t size                         //  How much memory to allocate
)
{
    icl_mem_lockfree_t *
        self;                           //  The allocation block

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_NEW))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_NEW))
    icl_stats_inc ("icl_mem_lockfree_new", &s_icl_mem_lockfree_new_stats);
#endif

self = malloc (ICL_MEM_LOCKFREE_SIZE + size);

//  Increment the record of total memory allocations
icl_mem_increment_used (ICL_MEM_LOCKFREE_SIZE + size);

if (self) {
    self->cache = NULL;
    self->size  = size;
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    self->exit_tag.nl_p = TRUE;
#endif
}
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_NEW))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_cache_purge

    Type: Component method
    The 'purge' method frees half of the unused blocks.
    -------------------------------------------------------------------------
 */

void
    icl_mem_lockfree_cache_purge (
    icl_cache_t * cache                 //  The cache to purge
)
{
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    qbyte
        target_unused_count;
    icl_mem_lockfree_t
        *self;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_PURGE))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_PURGE))
    icl_stats_inc ("icl_mem_lockfree_cache_purge", &s_icl_mem_lockfree_cache_purge_stats);
#endif

#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    target_unused_count = icl_atomic_get32 (&cache->lockfree_unused_count) / 2;
    while (cache->lockfree_unused_count > target_unused_count) {
        self = icl_mem_lockfree_cache_reuse (cache);
        if (self)
            icl_mem_lockfree_destroy (&self);
        else
            break;
    }
#endif
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_PURGE))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_purge_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache);
#endif

}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_cache_assert

    Type: Component method
    This is a private method used by icl_mem_lockfree_cache_alloc.
    
    Its purpose is report on leaked allocations in the cache.
    -------------------------------------------------------------------------
 */

int
    icl_mem_lockfree_cache_assert (
    icl_cache_t * cache,                //  The cache for the allocation
    FILE ** trace_file                  //  File to print to, opened on error
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_ASSERT))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_assert_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" trace_file=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, trace_file);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_ASSERT))
    icl_stats_inc ("icl_mem_lockfree_cache_assert", &s_icl_mem_lockfree_cache_assert_stats);
#endif

#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    if (cache->lockfree_used_count) {
        rc = -1;
        icl_console_print ("E: %lu active cache allocations of size: %lu.",
                           (long) cache->lockfree_used_count, (long) cache->size);
        icl_console_print ("E: Rebuild with fat memory allocator for details");
    }
#endif
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_ASSERT))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_assert_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" trace_file=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, trace_file, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_mem_lockfree_show (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_SHOW))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_show_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_SHOW))
    icl_stats_inc ("icl_mem_lockfree_show", &s_icl_mem_lockfree_show_stats);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_SHOW))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_show_finish"
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
    icl_mem_lockfree_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_mem_lockfree_selftest (
void)
{
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)

#if defined (__i386__)
    icl_cache_t
        *cache;
    void
        *buffer;
#endif
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_SELFTEST))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_SELFTEST))
    icl_stats_inc ("icl_mem_lockfree_selftest", &s_icl_mem_lockfree_selftest_stats);
#endif

#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)

#if defined (__i386__)
    cache  = icl_cache_get (500);
    buffer = icl_mem_lockfree_cache_alloc (cache);
    icl_mem_lockfree_free (buffer);
#endif

#endif
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_SELFTEST))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_selftest_finish"
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
    icl_mem_lockfree_cache_pop

    Type: Component method
    Pops a block from a cache.
    cache.
    -------------------------------------------------------------------------
 */

void *
    icl_mem_lockfree_cache_pop_ (
    icl_cache_t * cache,                //  The cache for the allocation
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
icl_mem_lockfree_t
    *self;
    void *
        item = NULL;                    //  The returned client pointer

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_POP))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_pop_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_POP))
    icl_stats_inc ("icl_mem_lockfree_cache_pop", &s_icl_mem_lockfree_cache_pop_stats);
#endif

    self = icl_mem_lockfree_cache_reuse_ (cache, file, line);
    if (self) {
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_LOCKFREE))
        icl_stats_inc (NULL, &cache->allocs_stat);
#endif
        self->tag = ICL_CACHE_ALIVE;
        icl_mem_lockfree_cache_insert (cache, self);
        item = (byte *) self + ICL_MEM_LOCKFREE_SIZE;
        icl_mem_lockfree_possess_ (item, file, line);
    }
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_POP))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_pop_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_cache_new

    Type: Component method
    Allocates a block in a cache.  The size of the block is the size of the 
    cache.
    -------------------------------------------------------------------------
 */

void *
    icl_mem_lockfree_cache_new_ (
    icl_cache_t * cache,                //  The cache for the allocation
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
icl_mem_lockfree_t
    *self;
    void *
        item = NULL;                    //  The returned client pointer

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_NEW))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_NEW))
    icl_stats_inc ("icl_mem_lockfree_cache_new", &s_icl_mem_lockfree_cache_new_stats);
#endif

    self = icl_mem_lockfree_new (cache->size);
    if (self) {
        self->cache = cache;
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_LOCKFREE))
        icl_stats_inc (NULL, &cache->allocs_stat);
#endif
        self->tag = ICL_CACHE_ALIVE;
        icl_mem_lockfree_cache_insert (cache, self);
        item = (byte *) self + ICL_MEM_LOCKFREE_SIZE;
        icl_mem_lockfree_possess_ (item, file, line);
    }
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_NEW))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_destroy

    Type: Component method
    Destroy an allocated block.
    -------------------------------------------------------------------------
 */

void
    icl_mem_lockfree_destroy (
    icl_mem_lockfree_t * ( * self_p )   //  The allocation block
)
{
    icl_mem_lockfree_t *
        self = *self_p;                 //  Dereferenced The allocation block

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_DESTROY))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_destroy_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_DESTROY))
    icl_stats_inc ("icl_mem_lockfree_destroy", &s_icl_mem_lockfree_destroy_stats);
#endif

if (self) {
    //  Decrement the record of total memory allocations
    icl_mem_decrement_used (ICL_MEM_LOCKFREE_SIZE + self->size);

    free (self);
    *self_p = NULL;
}
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_DESTROY))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_destroy_finish"
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
    icl_mem_lockfree_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_mem_lockfree_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_ANIMATE))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_animate_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_ANIMATE))
    icl_stats_inc ("icl_mem_lockfree_animate", &s_icl_mem_lockfree_animate_stats);
#endif

icl_mem_lockfree_animating = enabled;
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_ANIMATE))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_animate_finish"
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
//  Embed the version information in the resulting binary                      

char *icl_mem_lockfree_version_start  = "VeRsIoNsTaRt:ipc";
char *icl_mem_lockfree_component   = "icl_mem_lockfree ";
char *icl_mem_lockfree_version     = "1.1 ";
char *icl_mem_lockfree_copyright   = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_mem_lockfree_filename    = "icl_mem_lockfree.icl ";
char *icl_mem_lockfree_builddate   = "2010/10/06 ";
char *icl_mem_lockfree_version_end  = "VeRsIoNeNd:ipc";

