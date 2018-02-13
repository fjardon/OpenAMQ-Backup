/*---------------------------------------------------------------------------
    icl_lfcontext.c - icl_lfcontext component

    This class holds the thread-local context for lock-free functions.
    Generated from icl_lfcontext.icl by icl_gen using GSL/4.
    
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
#include "icl_lfcontext.h"              //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_lfcontext_t

//  Shorthands for class methods                                               

#define self_annihilate     icl_lfcontext_annihilate
#define self_selftest       icl_lfcontext_selftest
#define self_new            icl_lfcontext_new
#define self_remove_from_all_containers  icl_lfcontext_remove_from_all_containers
#define self_show           icl_lfcontext_show
#define self_terminate      icl_lfcontext_terminate
#define self_destroy        icl_lfcontext_destroy
#define self_alloc          icl_lfcontext_alloc
#define self_free           icl_lfcontext_free
#define self_cache_initialise  icl_lfcontext_cache_initialise
#define self_cache_purge    icl_lfcontext_cache_purge
#define self_cache_terminate  icl_lfcontext_cache_terminate
#define self_animate        icl_lfcontext_animate
#define self_new_in_scope   icl_lfcontext_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_DESTROY))
static icl_stats_t *s_icl_lfcontext_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_SELFTEST))
static icl_stats_t *s_icl_lfcontext_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_NEW))
static icl_stats_t *s_icl_lfcontext_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_icl_lfcontext_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_SHOW))
static icl_stats_t *s_icl_lfcontext_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_TERMINATE))
static icl_stats_t *s_icl_lfcontext_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_DESTROY_PUBLIC))
static icl_stats_t *s_icl_lfcontext_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_ALLOC))
static icl_stats_t *s_icl_lfcontext_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_FREE))
static icl_stats_t *s_icl_lfcontext_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_CACHE_INITIALISE))
static icl_stats_t *s_icl_lfcontext_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_CACHE_PURGE))
static icl_stats_t *s_icl_lfcontext_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_CACHE_TERMINATE))
static icl_stats_t *s_icl_lfcontext_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_ANIMATE))
static icl_stats_t *s_icl_lfcontext_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_NEW_IN_SCOPE))
static icl_stats_t *s_icl_lfcontext_new_in_scope_stats = NULL;
#endif
static void
    icl_lfcontext_annihilate (
icl_lfcontext_t * ( * self_p )          //  Reference to object reference
);

#define icl_lfcontext_alloc()           icl_lfcontext_alloc_ (__FILE__, __LINE__)
static icl_lfcontext_t *
    icl_lfcontext_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    icl_lfcontext_free (
icl_lfcontext_t * self                  //  Object reference
);

static void
    icl_lfcontext_cache_initialise (
void);

static void
    icl_lfcontext_cache_purge (
void);

static void
    icl_lfcontext_cache_terminate (
void);

Bool
    icl_lfcontext_animating = TRUE;     //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    icl_lfcontext_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_lfcontext_annihilate (
    icl_lfcontext_t * ( * self_p )      //  Reference to object reference
)
{

icl_lfqueue_node_t
    *node;
    icl_lfcontext_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_DESTROY))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_DESTROY))
    icl_trace_record (NULL, icl_lfcontext_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_DESTROY))
    icl_stats_inc ("icl_lfcontext_annihilate", &s_icl_lfcontext_annihilate_stats);
#endif

ICL_LFCONTEXT_ASSERT_SANE (self);
icl_lfcontext_remove_from_all_containers (self);

while (self->cache) {
    node = self->cache;
    self->cache = (icl_lfqueue_node_t *) self->cache->next;
    icl_mem_free (node);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_DESTROY))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_DESTROY))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_destroy_finish"
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
    icl_lfcontext_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_lfcontext_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_SELFTEST))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_SELFTEST))
    icl_trace_record (NULL, icl_lfcontext_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_SELFTEST))
    icl_stats_inc ("icl_lfcontext_selftest", &s_icl_lfcontext_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_SELFTEST))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_SELFTEST))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_selftest_finish"
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
    icl_lfcontext_new

    Type: Component method
    Creates and initialises a new icl_lfcontext_t object, returns a
    reference to the created object.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

icl_lfcontext_t *
    icl_lfcontext_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_lfcontext_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_NEW))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_NEW))
    icl_trace_record (NULL, icl_lfcontext_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_NEW))
    icl_stats_inc ("icl_lfcontext_new", &s_icl_lfcontext_new_stats);
#endif

    self = icl_lfcontext_alloc_ (file, line);
    if (self) {
        self->object_tag   = ICL_LFCONTEXT_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, icl_lfcontext_show_);
#endif

self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_NEW))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_NEW))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_new_finish"
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
    icl_lfcontext_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    icl_lfcontext_remove_from_all_containers (
    icl_lfcontext_t * self              //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_REMOVE_FROM_ALL_CONTAINERS))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, icl_lfcontext_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("icl_lfcontext_remove_from_all_containers", &s_icl_lfcontext_remove_from_all_containers_stats);
#endif

icl_lfcontext_list_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_REMOVE_FROM_ALL_CONTAINERS))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_remove_from_all_containers_finish"
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
    icl_lfcontext_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_lfcontext_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
icl_lfcontext_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_SHOW))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_SHOW))
    icl_trace_record (NULL, icl_lfcontext_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_SHOW))
    icl_stats_inc ("icl_lfcontext_show", &s_icl_lfcontext_show_stats);
#endif

self = item;
container_links = 0;
if (self->list_head)
   container_links++;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <icl_lfcontext file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_SHOW))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_SHOW))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_show_finish"
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
    icl_lfcontext_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_lfcontext_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_TERMINATE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_TERMINATE))
    icl_trace_record (NULL, icl_lfcontext_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_TERMINATE))
    icl_stats_inc ("icl_lfcontext_terminate", &s_icl_lfcontext_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_TERMINATE))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_TERMINATE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_terminate_finish"
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
    icl_lfcontext_destroy

    Type: Component method
    Destroys a icl_lfcontext_t object. Takes the address of a
    icl_lfcontext_t reference (a pointer to a pointer) and nullifies the
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
    icl_lfcontext_destroy_ (
    icl_lfcontext_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_lfcontext_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_DESTROY_PUBLIC))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_lfcontext_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_DESTROY_PUBLIC))
    icl_stats_inc ("icl_lfcontext_destroy", &s_icl_lfcontext_destroy_stats);
#endif

if (self) {
    icl_lfcontext_annihilate (self_p);
    icl_lfcontext_free ((icl_lfcontext_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_DESTROY_PUBLIC))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_destroy_public_finish"
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
    icl_lfcontext_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_lfcontext_t *
    icl_lfcontext_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    icl_lfcontext_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_ALLOC))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_ALLOC))
    icl_trace_record (NULL, icl_lfcontext_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_ALLOC))
    icl_stats_inc ("icl_lfcontext_alloc", &s_icl_lfcontext_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    icl_lfcontext_cache_initialise ();

self = (icl_lfcontext_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (icl_lfcontext_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_ALLOC))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_ALLOC))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_alloc_finish"
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
    icl_lfcontext_free

    Type: Component method
    Freess a icl_lfcontext_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_lfcontext_free (
    icl_lfcontext_t * self              //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_FREE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_FREE))
    icl_trace_record (NULL, icl_lfcontext_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_FREE))
    icl_stats_inc ("icl_lfcontext_free", &s_icl_lfcontext_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (icl_lfcontext_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (icl_lfcontext_t));
        self->object_tag = ICL_LFCONTEXT_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_FREE))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_FREE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_free_finish"
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
    icl_lfcontext_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    icl_lfcontext_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_CACHE_INITIALISE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_INITIALISE))
    icl_trace_record (NULL, icl_lfcontext_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_CACHE_INITIALISE))
    icl_stats_inc ("icl_lfcontext_cache_initialise", &s_icl_lfcontext_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (icl_lfcontext_t));
icl_system_register (icl_lfcontext_cache_purge, icl_lfcontext_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_INITIALISE))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_CACHE_INITIALISE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_cache_initialise_finish"
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
    icl_lfcontext_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_lfcontext_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_CACHE_PURGE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_PURGE))
    icl_trace_record (NULL, icl_lfcontext_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_CACHE_PURGE))
    icl_stats_inc ("icl_lfcontext_cache_purge", &s_icl_lfcontext_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_PURGE))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_CACHE_PURGE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_cache_purge_finish"
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
    icl_lfcontext_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_lfcontext_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_CACHE_TERMINATE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_TERMINATE))
    icl_trace_record (NULL, icl_lfcontext_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_CACHE_TERMINATE))
    icl_stats_inc ("icl_lfcontext_cache_terminate", &s_icl_lfcontext_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_TERMINATE))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_CACHE_TERMINATE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_cache_terminate_finish"
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
    icl_lfcontext_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_lfcontext_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_ANIMATE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_ANIMATE))
    icl_trace_record (NULL, icl_lfcontext_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_ANIMATE))
    icl_stats_inc ("icl_lfcontext_animate", &s_icl_lfcontext_animate_stats);
#endif

icl_lfcontext_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_ANIMATE))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_ANIMATE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_animate_finish"
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
    icl_lfcontext_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_lfcontext_new_in_scope_ (
    icl_lfcontext_t * * self_p,         //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT)  ||  defined (BASE_ANIMATE_ICL_LFCONTEXT_NEW_IN_SCOPE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_lfcontext_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LFCONTEXT)  ||  defined (BASE_STATS_ICL_LFCONTEXT_NEW_IN_SCOPE))
    icl_stats_inc ("icl_lfcontext_new_in_scope", &s_icl_lfcontext_new_in_scope_stats);
#endif

*self_p = icl_lfcontext_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_lfcontext_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_lfcontext_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LFCONTEXT)   || defined (BASE_ANIMATE_ICL_LFCONTEXT_NEW_IN_SCOPE))
    if (icl_lfcontext_animating)
        icl_console_print ("<icl_lfcontext_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_DESTROY)   || defined (BASE_TRACE_ICL_LFCONTEXT_SELFTEST)   || defined (BASE_TRACE_ICL_LFCONTEXT_NEW)   || defined (BASE_TRACE_ICL_LFCONTEXT_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_ICL_LFCONTEXT_SHOW)   || defined (BASE_TRACE_ICL_LFCONTEXT_TERMINATE)   || defined (BASE_TRACE_ICL_LFCONTEXT_DESTROY_PUBLIC)   || defined (BASE_TRACE_ICL_LFCONTEXT_ALLOC)   || defined (BASE_TRACE_ICL_LFCONTEXT_FREE)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_INITIALISE)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_PURGE)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_TERMINATE)   || defined (BASE_TRACE_ICL_LFCONTEXT_ANIMATE)   || defined (BASE_TRACE_ICL_LFCONTEXT_NEW_IN_SCOPE) )
void
icl_lfcontext_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "destroy"; break;
        case 2: method_name = "selftest"; break;
        case 3: method_name = "new"; break;
        case 4: method_name = "remove from all containers"; break;
        case 5: method_name = "show"; break;
        case 6: method_name = "terminate"; break;
        case 7: method_name = "destroy public"; break;
        case 8: method_name = "alloc"; break;
        case 9: method_name = "free"; break;
        case 10: method_name = "cache initialise"; break;
        case 11: method_name = "cache purge"; break;
        case 12: method_name = "cache terminate"; break;
        case 13: method_name = "animate"; break;
        case 14: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "icl_lfcontext %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *icl_lfcontext_version_start  = "VeRsIoNsTaRt:ipc";
char *icl_lfcontext_component      = "icl_lfcontext ";
char *icl_lfcontext_version        = "1.1 ";
char *icl_lfcontext_copyright      = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_lfcontext_filename       = "icl_lfcontext.icl ";
char *icl_lfcontext_builddate      = "2010/10/06 ";
char *icl_lfcontext_version_end    = "VeRsIoNeNd:ipc";

