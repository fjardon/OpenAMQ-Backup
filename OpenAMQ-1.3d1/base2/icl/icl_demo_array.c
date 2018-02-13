/*---------------------------------------------------------------------------
    icl_demo_array.c - icl_demo_array component

    Generated from icl_demo_array.icl by icl_gen using GSL/4.
    
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
#include "icl_demo_array.h"             //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_demo_array_t

//  Shorthands for class methods                                               

#define self_new            icl_demo_array_new
#define self_annihilate     icl_demo_array_annihilate
#define self_selftest       icl_demo_array_selftest
#define self_remove_from_all_containers  icl_demo_array_remove_from_all_containers
#define self_show           icl_demo_array_show
#define self_terminate      icl_demo_array_terminate
#define self_destroy        icl_demo_array_destroy
#define self_alloc          icl_demo_array_alloc
#define self_free           icl_demo_array_free
#define self_read_lock      icl_demo_array_read_lock
#define self_write_lock     icl_demo_array_write_lock
#define self_unlock         icl_demo_array_unlock
#define self_link           icl_demo_array_link
#define self_unlink         icl_demo_array_unlink
#define self_cache_initialise  icl_demo_array_cache_initialise
#define self_cache_purge    icl_demo_array_cache_purge
#define self_cache_terminate  icl_demo_array_cache_terminate
#define self_animate        icl_demo_array_animate
#define self_new_in_scope   icl_demo_array_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_NEW))
static icl_stats_t *s_icl_demo_array_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_DESTROY))
static icl_stats_t *s_icl_demo_array_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_SELFTEST))
static icl_stats_t *s_icl_demo_array_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_icl_demo_array_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_SHOW))
static icl_stats_t *s_icl_demo_array_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_TERMINATE))
static icl_stats_t *s_icl_demo_array_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_DESTROY_PUBLIC))
static icl_stats_t *s_icl_demo_array_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_ALLOC))
static icl_stats_t *s_icl_demo_array_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_FREE))
static icl_stats_t *s_icl_demo_array_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_READ_LOCK))
static icl_stats_t *s_icl_demo_array_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_WRITE_LOCK))
static icl_stats_t *s_icl_demo_array_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_UNLOCK))
static icl_stats_t *s_icl_demo_array_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_LINK))
static icl_stats_t *s_icl_demo_array_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_UNLINK))
static icl_stats_t *s_icl_demo_array_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_CACHE_INITIALISE))
static icl_stats_t *s_icl_demo_array_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_CACHE_PURGE))
static icl_stats_t *s_icl_demo_array_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_CACHE_TERMINATE))
static icl_stats_t *s_icl_demo_array_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_ANIMATE))
static icl_stats_t *s_icl_demo_array_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_NEW_IN_SCOPE))
static icl_stats_t *s_icl_demo_array_new_in_scope_stats = NULL;
#endif
#define icl_demo_array_annihilate(self)  icl_demo_array_annihilate_ (self, __FILE__, __LINE__)
static void
    icl_demo_array_annihilate_ (
icl_demo_array_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define icl_demo_array_alloc()          icl_demo_array_alloc_ (__FILE__, __LINE__)
static icl_demo_array_t *
    icl_demo_array_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_demo_array_free(self)       icl_demo_array_free_ (self, __FILE__, __LINE__)
static void
    icl_demo_array_free_ (
icl_demo_array_t * self,                //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    icl_demo_array_cache_initialise (
void);

static void
    icl_demo_array_cache_purge (
void);

static void
    icl_demo_array_cache_terminate (
void);

Bool
    icl_demo_array_animating = TRUE;    //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    icl_demo_array_new

    Type: Component method
    Creates and initialises a new icl_demo_array_t object, returns a
    reference to the created object.
    Initialises a new array item without placing it into any array.
    -------------------------------------------------------------------------
 */

icl_demo_array_t *
    icl_demo_array_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    icl_demo_array_array_t * array,     //  Array to insert into
    qbyte index,                        //  Index for new item
    char * name,                        //  Not documented
    char * address                      //  Not documented
)
{
    icl_demo_array_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_NEW))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" array=\"%pp\""
" index=\"%lu\""
" name=\"%s\""
" address=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, array, index, name, address);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_NEW))
    icl_trace_record (NULL, icl_demo_array_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_NEW))
    icl_stats_inc ("icl_demo_array_new", &s_icl_demo_array_new_stats);
#endif

    self = icl_demo_array_alloc_ (file, line);
    if (self) {
        self->object_tag   = ICL_DEMO_ARRAY_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
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
        icl_mem_set_callback (self, icl_demo_array_show_);
#endif

self->array_index = 0;
self->array_head = NULL;
self->name    = icl_mem_strdup (name);
self->address = icl_mem_strdup (address);
icl_demo_array_array_insert (array, index, self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_NEW))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_NEW))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" array=\"%pp\""
" index=\"%lu\""
" name=\"%s\""
" address=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, array, index, name, address, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_demo_array_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_array_annihilate_ (
    icl_demo_array_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
    int
        history_last;
#endif

    icl_demo_array_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_DESTROY))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_DESTROY))
    icl_trace_record (NULL, icl_demo_array_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_DESTROY))
    icl_stats_inc ("icl_demo_array_annihilate", &s_icl_demo_array_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = self->links;
#endif

    ICL_DEMO_ARRAY_ASSERT_SANE (self);
    icl_demo_array_remove_from_all_containers (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

icl_mem_free (self->name);
icl_mem_free (self->address);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_DESTROY))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_DESTROY))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_destroy_finish"
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
    icl_demo_array_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_array_selftest (
void)
{
icl_demo_array_array_t *
    array;
icl_demo_array_t *
    item;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_SELFTEST))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_SELFTEST))
    icl_trace_record (NULL, icl_demo_array_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_SELFTEST))
    icl_stats_inc ("icl_demo_array_selftest", &s_icl_demo_array_selftest_stats);
#endif

array = icl_demo_array_array_new ();

item = icl_demo_array_new (array, 10, "Santorini", "0x012201");
icl_demo_array_unlink (&item);
item = icl_demo_array_new (array, 20, "Imafufou", "0x006552A");
icl_demo_array_unlink (&item);
item = icl_demo_array_new (array, 30, "DosLagos", "0x8272210");
icl_demo_array_unlink (&item);
assert ((long) icl_demo_array_array_ubound (array) == 31);

item = icl_demo_array_array_fetch (array, 30);
icl_demo_array_destroy (&item);
assert ((long) icl_demo_array_array_ubound (array) == 21);

item = icl_demo_array_array_fetch (array, 20);
icl_demo_array_destroy (&item);
assert ((long) icl_demo_array_array_ubound (array) == 11);

item = icl_demo_array_array_fetch (array, 10);
icl_demo_array_destroy (&item);
assert ((long) icl_demo_array_array_ubound (array) == 0);

icl_demo_array_array_reset  (array);
icl_demo_array_array_reset  (array);
icl_demo_array_array_destroy (&array);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_SELFTEST))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_SELFTEST))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_selftest_finish"
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
    icl_demo_array_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    icl_demo_array_remove_from_all_containers (
    icl_demo_array_t * self             //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_REMOVE_FROM_ALL_CONTAINERS))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, icl_demo_array_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("icl_demo_array_remove_from_all_containers", &s_icl_demo_array_remove_from_all_containers_stats);
#endif

icl_demo_array_array_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_REMOVE_FROM_ALL_CONTAINERS))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_remove_from_all_containers_finish"
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
    icl_demo_array_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_array_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    icl_demo_array_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_SHOW))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_SHOW))
    icl_trace_record (NULL, icl_demo_array_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_SHOW))
    icl_stats_inc ("icl_demo_array_show", &s_icl_demo_array_show_stats);
#endif

self = item;
container_links = 0;
if (self->array_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <icl_demo_array zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
    if (self->history_last > ICL_DEMO_ARRAY_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ICL_DEMO_ARRAY_HISTORY_LENGTH;
        self->history_last %= ICL_DEMO_ARRAY_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ICL_DEMO_ARRAY_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </icl_demo_array>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_SHOW))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_SHOW))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_show_finish"
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
    icl_demo_array_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_array_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_TERMINATE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_TERMINATE))
    icl_trace_record (NULL, icl_demo_array_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_TERMINATE))
    icl_stats_inc ("icl_demo_array_terminate", &s_icl_demo_array_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_TERMINATE))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_TERMINATE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_terminate_finish"
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
    icl_demo_array_destroy

    Type: Component method
    Destroys a icl_demo_array_t object. Takes the address of a
    icl_demo_array_t reference (a pointer to a pointer) and nullifies the
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
    icl_demo_array_destroy_ (
    icl_demo_array_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_demo_array_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_DESTROY_PUBLIC))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_demo_array_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_DESTROY_PUBLIC))
    icl_stats_inc ("icl_demo_array_destroy", &s_icl_demo_array_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        icl_demo_array_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on icl_demo_array object");
        icl_demo_array_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        icl_demo_array_free_ ((icl_demo_array_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_DESTROY_PUBLIC))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_destroy_public_finish"
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
    icl_demo_array_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_demo_array_t *
    icl_demo_array_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    icl_demo_array_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_ALLOC))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_ALLOC))
    icl_trace_record (NULL, icl_demo_array_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_ALLOC))
    icl_stats_inc ("icl_demo_array_alloc", &s_icl_demo_array_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    icl_demo_array_cache_initialise ();

self = (icl_demo_array_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (icl_demo_array_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_ALLOC))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_ALLOC))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_alloc_finish"
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
    icl_demo_array_free

    Type: Component method
    Freess a icl_demo_array_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_array_free_ (
    icl_demo_array_t * self,            //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_FREE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_FREE))
    icl_trace_record (NULL, icl_demo_array_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_FREE))
    icl_stats_inc ("icl_demo_array_free", &s_icl_demo_array_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (icl_demo_array_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (icl_demo_array_t));
        self->object_tag = ICL_DEMO_ARRAY_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_FREE))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_FREE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_free_finish"
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
    icl_demo_array_read_lock

    Type: Component method
    Accepts a icl_demo_array_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_array_read_lock (
    icl_demo_array_t * self             //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_READ_LOCK))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_READ_LOCK))
    icl_trace_record (NULL, icl_demo_array_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_READ_LOCK))
    icl_stats_inc ("icl_demo_array_read_lock", &s_icl_demo_array_read_lock_stats);
#endif

ICL_DEMO_ARRAY_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_READ_LOCK))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_READ_LOCK))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_read_lock_finish"
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
    icl_demo_array_write_lock

    Type: Component method
    Accepts a icl_demo_array_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_array_write_lock (
    icl_demo_array_t * self             //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_WRITE_LOCK))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_WRITE_LOCK))
    icl_trace_record (NULL, icl_demo_array_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_WRITE_LOCK))
    icl_stats_inc ("icl_demo_array_write_lock", &s_icl_demo_array_write_lock_stats);
#endif

ICL_DEMO_ARRAY_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_WRITE_LOCK))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_WRITE_LOCK))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_write_lock_finish"
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
    icl_demo_array_unlock

    Type: Component method
    Accepts a icl_demo_array_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_array_unlock (
    icl_demo_array_t * self             //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_UNLOCK))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_UNLOCK))
    icl_trace_record (NULL, icl_demo_array_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_UNLOCK))
    icl_stats_inc ("icl_demo_array_unlock", &s_icl_demo_array_unlock_stats);
#endif

ICL_DEMO_ARRAY_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_UNLOCK))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_UNLOCK))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_unlock_finish"
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
    icl_demo_array_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

icl_demo_array_t *
    icl_demo_array_link_ (
    icl_demo_array_t * self,            //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_LINK))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_LINK))
    icl_trace_record (NULL, icl_demo_array_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_LINK))
    icl_stats_inc ("icl_demo_array_link", &s_icl_demo_array_link_stats);
#endif

    if (self) {
        ICL_DEMO_ARRAY_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_LINK))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_LINK))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_link_finish"
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
    icl_demo_array_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    icl_demo_array_unlink_ (
    icl_demo_array_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
    int
        history_last;
#endif

    icl_demo_array_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_UNLINK))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_UNLINK))
    icl_trace_record (NULL, icl_demo_array_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_UNLINK))
    icl_stats_inc ("icl_demo_array_unlink", &s_icl_demo_array_unlink_stats);
#endif

    if (self) {
        ICL_DEMO_ARRAY_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on icl_demo_array object");
            icl_demo_array_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ICL_DEMO_ARRAY_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            icl_demo_array_annihilate_ (self_p, file, line);
        icl_demo_array_free_ ((icl_demo_array_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_UNLINK))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_UNLINK))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_unlink_finish"
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
    icl_demo_array_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_array_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_CACHE_INITIALISE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_INITIALISE))
    icl_trace_record (NULL, icl_demo_array_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_CACHE_INITIALISE))
    icl_stats_inc ("icl_demo_array_cache_initialise", &s_icl_demo_array_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (icl_demo_array_t));
icl_system_register (icl_demo_array_cache_purge, icl_demo_array_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_INITIALISE))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_CACHE_INITIALISE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_cache_initialise_finish"
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
    icl_demo_array_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_array_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_CACHE_PURGE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_PURGE))
    icl_trace_record (NULL, icl_demo_array_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_CACHE_PURGE))
    icl_stats_inc ("icl_demo_array_cache_purge", &s_icl_demo_array_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_PURGE))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_CACHE_PURGE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_cache_purge_finish"
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
    icl_demo_array_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_array_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_CACHE_TERMINATE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_TERMINATE))
    icl_trace_record (NULL, icl_demo_array_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_CACHE_TERMINATE))
    icl_stats_inc ("icl_demo_array_cache_terminate", &s_icl_demo_array_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_TERMINATE))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_CACHE_TERMINATE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_cache_terminate_finish"
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
    icl_demo_array_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_demo_array_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_ANIMATE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_ANIMATE))
    icl_trace_record (NULL, icl_demo_array_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_ANIMATE))
    icl_stats_inc ("icl_demo_array_animate", &s_icl_demo_array_animate_stats);
#endif

icl_demo_array_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_ANIMATE))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_ANIMATE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_animate_finish"
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
    icl_demo_array_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_array_new_in_scope_ (
    icl_demo_array_t * * self_p,        //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    icl_demo_array_array_t * array,     //  Array to insert into
    qbyte index,                        //  Index for new item
    char * name,                        //  Not documented
    char * address                      //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY)  ||  defined (BASE_ANIMATE_ICL_DEMO_ARRAY_NEW_IN_SCOPE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" array=\"%pp\""
" index=\"%lu\""
" name=\"%s\""
" address=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, array, index, name, address);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_demo_array_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY)  ||  defined (BASE_STATS_ICL_DEMO_ARRAY_NEW_IN_SCOPE))
    icl_stats_inc ("icl_demo_array_new_in_scope", &s_icl_demo_array_new_in_scope_stats);
#endif

*self_p = icl_demo_array_new_ (file,line,array,index,name,address);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_demo_array_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_demo_array_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY)   || defined (BASE_ANIMATE_ICL_DEMO_ARRAY_NEW_IN_SCOPE))
    if (icl_demo_array_animating)
        icl_console_print ("<icl_demo_array_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" array=\"%pp\""
" index=\"%lu\""
" name=\"%s\""
" address=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, array, index, name, address, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_NEW)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_DESTROY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_SELFTEST)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_SHOW)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_DESTROY_PUBLIC)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_ALLOC)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_FREE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_READ_LOCK)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_WRITE_LOCK)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_UNLOCK)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_LINK)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_UNLINK)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_INITIALISE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_PURGE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_ANIMATE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_NEW_IN_SCOPE) )
void
icl_demo_array_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "remove from all containers"; break;
        case 5: method_name = "show"; break;
        case 6: method_name = "terminate"; break;
        case 7: method_name = "destroy public"; break;
        case 8: method_name = "alloc"; break;
        case 9: method_name = "free"; break;
        case 10: method_name = "read lock"; break;
        case 11: method_name = "write lock"; break;
        case 12: method_name = "unlock"; break;
        case 13: method_name = "link"; break;
        case 14: method_name = "unlink"; break;
        case 15: method_name = "cache initialise"; break;
        case 16: method_name = "cache purge"; break;
        case 17: method_name = "cache terminate"; break;
        case 18: method_name = "animate"; break;
        case 19: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "icl_demo_array %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *icl_demo_array_version_start  = "VeRsIoNsTaRt:ipc";
char *icl_demo_array_component     = "icl_demo_array ";
char *icl_demo_array_version       = "1.0 ";
char *icl_demo_array_copyright     = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_demo_array_filename      = "icl_demo_array.icl ";
char *icl_demo_array_builddate     = "2010/10/06 ";
char *icl_demo_array_version_end   = "VeRsIoNeNd:ipc";

