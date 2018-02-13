/*---------------------------------------------------------------------------
    ipr_symbol.c - ipr_symbol component

Implements a symbol table that holds arbitrary data, keyed by name.
Can be used directly, or inherited to create specific symbol table
structures.
    Generated from ipr_symbol.icl by icl_gen using GSL/4.
    
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
#include "ipr_symbol.h"                 //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_symbol_t

//  Shorthands for class methods                                               

#define self_new            ipr_symbol_new
#define self_annihilate     ipr_symbol_annihilate
#define self_assume         ipr_symbol_assume
#define self_selftest       ipr_symbol_selftest
#define self_remove_from_all_containers  ipr_symbol_remove_from_all_containers
#define self_show           ipr_symbol_show
#define self_terminate      ipr_symbol_terminate
#define self_destroy        ipr_symbol_destroy
#define self_alloc          ipr_symbol_alloc
#define self_free           ipr_symbol_free
#define self_read_lock      ipr_symbol_read_lock
#define self_write_lock     ipr_symbol_write_lock
#define self_unlock         ipr_symbol_unlock
#define self_link           ipr_symbol_link
#define self_unlink         ipr_symbol_unlink
#define self_cache_initialise  ipr_symbol_cache_initialise
#define self_cache_purge    ipr_symbol_cache_purge
#define self_cache_terminate  ipr_symbol_cache_terminate
#define self_animate        ipr_symbol_animate
#define self_new_in_scope   ipr_symbol_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_NEW))
static icl_stats_t *s_ipr_symbol_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_DESTROY))
static icl_stats_t *s_ipr_symbol_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_ASSUME))
static icl_stats_t *s_ipr_symbol_assume_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_SELFTEST))
static icl_stats_t *s_ipr_symbol_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_ipr_symbol_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_SHOW))
static icl_stats_t *s_ipr_symbol_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_TERMINATE))
static icl_stats_t *s_ipr_symbol_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_symbol_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_ALLOC))
static icl_stats_t *s_ipr_symbol_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_FREE))
static icl_stats_t *s_ipr_symbol_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_READ_LOCK))
static icl_stats_t *s_ipr_symbol_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_WRITE_LOCK))
static icl_stats_t *s_ipr_symbol_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_UNLOCK))
static icl_stats_t *s_ipr_symbol_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_LINK))
static icl_stats_t *s_ipr_symbol_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_UNLINK))
static icl_stats_t *s_ipr_symbol_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_CACHE_INITIALISE))
static icl_stats_t *s_ipr_symbol_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_CACHE_PURGE))
static icl_stats_t *s_ipr_symbol_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_CACHE_TERMINATE))
static icl_stats_t *s_ipr_symbol_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_ANIMATE))
static icl_stats_t *s_ipr_symbol_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_symbol_new_in_scope_stats = NULL;
#endif
#define ipr_symbol_annihilate(self)     ipr_symbol_annihilate_ (self, __FILE__, __LINE__)
static void
    ipr_symbol_annihilate_ (
ipr_symbol_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define ipr_symbol_alloc()              ipr_symbol_alloc_ (__FILE__, __LINE__)
static ipr_symbol_t *
    ipr_symbol_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_symbol_free(self)           ipr_symbol_free_ (self, __FILE__, __LINE__)
static void
    ipr_symbol_free_ (
ipr_symbol_t * self,                    //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    ipr_symbol_cache_initialise (
void);

static void
    ipr_symbol_cache_purge (
void);

static void
    ipr_symbol_cache_terminate (
void);

Bool
    ipr_symbol_animating = TRUE;        //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    ipr_symbol_new

    Type: Component method
    Creates and initialises a new ipr_symbol_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

ipr_symbol_t *
    ipr_symbol_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_symbol_table_t * table,         //  Table to insert into
    char * key,                         //  Hash key
    void * data                         //  Data for symbol
)
{
    ipr_symbol_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_NEW))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, data);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_NEW))
    icl_trace_record (NULL, ipr_symbol_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_NEW))
    icl_stats_inc ("ipr_symbol_new", &s_ipr_symbol_new_stats);
#endif

    self = ipr_symbol_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_SYMBOL_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
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
        icl_mem_set_callback (self, ipr_symbol_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->data = data;
if (table && self && ipr_symbol_table_insert (table, key, self))
    ipr_symbol_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_NEW))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_NEW))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" data=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, data, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_symbol_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_symbol_annihilate_ (
    ipr_symbol_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
    int
        history_last;
#endif

    ipr_symbol_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_DESTROY))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_DESTROY))
    icl_trace_record (NULL, ipr_symbol_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_DESTROY))
    icl_stats_inc ("ipr_symbol_annihilate", &s_ipr_symbol_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = file;
    self->history_line  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = line;
    self->history_type  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % IPR_SYMBOL_HISTORY_LENGTH] = self->links;
#endif

    IPR_SYMBOL_ASSERT_SANE (self);
    ipr_symbol_remove_from_all_containers (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_DESTROY))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_DESTROY))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_destroy_finish"
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
    ipr_symbol_assume

    Type: Component method
    Create or update symbol with specified value.
    -------------------------------------------------------------------------
 */

void
    ipr_symbol_assume (
    ipr_symbol_table_t * table,         //  Symbol table
    char * name,                        //  Symbol name
    void * data                         //  Data for symbol
)
{
ipr_symbol_t
    *item;                          //  Inserted item

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_ASSUME))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_assume_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" name=\"%s\""
" data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, name, data);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_ASSUME))
    icl_trace_record (NULL, ipr_symbol_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_ASSUME))
    icl_stats_inc ("ipr_symbol_assume", &s_ipr_symbol_assume_stats);
#endif

item = ipr_symbol_table_search (table, name);
if (item)
    item->data = data;
else
    item = ipr_symbol_new (table, name, data);

ipr_symbol_unlink (&item);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_ASSUME))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_ASSUME))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_assume_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" name=\"%s\""
" data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, name, data);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_symbol_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_symbol_selftest (
void)
{
ipr_symbol_table_t *
    table;
ipr_symbol_t *
    item;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_SELFTEST))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_SELFTEST))
    icl_trace_record (NULL, ipr_symbol_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_SELFTEST))
    icl_stats_inc ("ipr_symbol_selftest", &s_ipr_symbol_selftest_stats);
#endif

table = ipr_symbol_table_new ();

//  Insert some items                                                      
item = ipr_symbol_new (table, "0xdeadbeef", "deadbeef");
ipr_symbol_unlink (&item);
item = ipr_symbol_new (table, "0xabadcafe", "abadcafe");
ipr_symbol_unlink (&item);

//  Retrieve items                                                         
item = ipr_symbol_table_search (table, "0xdeadbeef");
assert (item && streq (item->data, "deadbeef"));
ipr_symbol_unlink (&item);
item = ipr_symbol_table_search (table, "0xabadcafe");
assert (item && streq (item->data, "abadcafe"));
ipr_symbol_unlink (&item);

//  Get a non existent item                                                
item = ipr_symbol_table_search (table, "0xf0000000");
assert (item == NULL);

//  Delete an item                                                         
item = ipr_symbol_table_search (table, "0xdeadbeef");
ipr_symbol_destroy (&item);
item = ipr_symbol_table_search (table, "0xdeadbeef");
assert (item == NULL);

ipr_symbol_table_destroy (&table);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_SELFTEST))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_SELFTEST))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_selftest_finish"
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
    ipr_symbol_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    ipr_symbol_remove_from_all_containers (
    ipr_symbol_t * self                 //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_symbol_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("ipr_symbol_remove_from_all_containers", &s_ipr_symbol_remove_from_all_containers_stats);
#endif

IPR_SYMBOL_ASSERT_SANE (self);
ipr_symbol_table_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_remove_from_all_containers_finish"
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
    ipr_symbol_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_symbol_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    ipr_symbol_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_SHOW))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_SHOW))
    icl_trace_record (NULL, ipr_symbol_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_SHOW))
    icl_stats_inc ("ipr_symbol_show", &s_ipr_symbol_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <ipr_symbol zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
    if (self->history_last > IPR_SYMBOL_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % IPR_SYMBOL_HISTORY_LENGTH;
        self->history_last %= IPR_SYMBOL_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % IPR_SYMBOL_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </ipr_symbol>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_SHOW))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_SHOW))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_show_finish"
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
    ipr_symbol_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_symbol_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_TERMINATE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_TERMINATE))
    icl_trace_record (NULL, ipr_symbol_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_TERMINATE))
    icl_stats_inc ("ipr_symbol_terminate", &s_ipr_symbol_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_TERMINATE))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_TERMINATE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_terminate_finish"
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
    ipr_symbol_destroy

    Type: Component method
    Destroys a ipr_symbol_t object. Takes the address of a
    ipr_symbol_t reference (a pointer to a pointer) and nullifies the
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
    ipr_symbol_destroy_ (
    ipr_symbol_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_symbol_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_DESTROY_PUBLIC))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_symbol_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_symbol_destroy", &s_ipr_symbol_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        ipr_symbol_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on ipr_symbol object");
        ipr_symbol_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        ipr_symbol_free_ ((ipr_symbol_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_DESTROY_PUBLIC))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_destroy_public_finish"
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
    ipr_symbol_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_symbol_t *
    ipr_symbol_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_symbol_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_ALLOC))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_ALLOC))
    icl_trace_record (NULL, ipr_symbol_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_ALLOC))
    icl_stats_inc ("ipr_symbol_alloc", &s_ipr_symbol_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_symbol_cache_initialise ();

self = (ipr_symbol_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_symbol_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_ALLOC))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_ALLOC))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_alloc_finish"
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
    ipr_symbol_free

    Type: Component method
    Freess a ipr_symbol_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_symbol_free_ (
    ipr_symbol_t * self,                //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_FREE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_FREE))
    icl_trace_record (NULL, ipr_symbol_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_FREE))
    icl_stats_inc ("ipr_symbol_free", &s_ipr_symbol_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = "free";
        self->history_links [history_last % IPR_SYMBOL_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (ipr_symbol_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_symbol_t));
        self->object_tag = IPR_SYMBOL_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_FREE))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_FREE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_free_finish"
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
    ipr_symbol_read_lock

    Type: Component method
    Accepts a ipr_symbol_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_symbol_read_lock (
    ipr_symbol_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_READ_LOCK))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_READ_LOCK))
    icl_trace_record (NULL, ipr_symbol_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_READ_LOCK))
    icl_stats_inc ("ipr_symbol_read_lock", &s_ipr_symbol_read_lock_stats);
#endif

IPR_SYMBOL_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_READ_LOCK))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_READ_LOCK))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_read_lock_finish"
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
    ipr_symbol_write_lock

    Type: Component method
    Accepts a ipr_symbol_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_symbol_write_lock (
    ipr_symbol_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_WRITE_LOCK))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_WRITE_LOCK))
    icl_trace_record (NULL, ipr_symbol_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_WRITE_LOCK))
    icl_stats_inc ("ipr_symbol_write_lock", &s_ipr_symbol_write_lock_stats);
#endif

IPR_SYMBOL_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_WRITE_LOCK))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_WRITE_LOCK))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_write_lock_finish"
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
    ipr_symbol_unlock

    Type: Component method
    Accepts a ipr_symbol_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_symbol_unlock (
    ipr_symbol_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_UNLOCK))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_UNLOCK))
    icl_trace_record (NULL, ipr_symbol_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_UNLOCK))
    icl_stats_inc ("ipr_symbol_unlock", &s_ipr_symbol_unlock_stats);
#endif

IPR_SYMBOL_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_UNLOCK))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_UNLOCK))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_unlock_finish"
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
    ipr_symbol_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

ipr_symbol_t *
    ipr_symbol_link_ (
    ipr_symbol_t * self,                //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_LINK))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_LINK))
    icl_trace_record (NULL, ipr_symbol_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_LINK))
    icl_stats_inc ("ipr_symbol_link", &s_ipr_symbol_link_stats);
#endif

    if (self) {
        IPR_SYMBOL_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = "link";
        self->history_links [history_last % IPR_SYMBOL_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_LINK))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_LINK))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_link_finish"
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
    ipr_symbol_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    ipr_symbol_unlink_ (
    ipr_symbol_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
    int
        history_last;
#endif

    ipr_symbol_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_UNLINK))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_UNLINK))
    icl_trace_record (NULL, ipr_symbol_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_UNLINK))
    icl_stats_inc ("ipr_symbol_unlink", &s_ipr_symbol_unlink_stats);
#endif

    if (self) {
        IPR_SYMBOL_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on ipr_symbol object");
            ipr_symbol_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_SYMBOL_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % IPR_SYMBOL_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            ipr_symbol_annihilate_ (self_p, file, line);
        ipr_symbol_free_ ((ipr_symbol_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_UNLINK))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_UNLINK))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_unlink_finish"
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
    ipr_symbol_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_symbol_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_CACHE_INITIALISE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_symbol_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_CACHE_INITIALISE))
    icl_stats_inc ("ipr_symbol_cache_initialise", &s_ipr_symbol_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_symbol_t));
icl_system_register (ipr_symbol_cache_purge, ipr_symbol_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_CACHE_INITIALISE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_cache_initialise_finish"
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
    ipr_symbol_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_symbol_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_CACHE_PURGE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_PURGE))
    icl_trace_record (NULL, ipr_symbol_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_CACHE_PURGE))
    icl_stats_inc ("ipr_symbol_cache_purge", &s_ipr_symbol_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_PURGE))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_CACHE_PURGE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_cache_purge_finish"
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
    ipr_symbol_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_symbol_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_CACHE_TERMINATE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_symbol_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_CACHE_TERMINATE))
    icl_stats_inc ("ipr_symbol_cache_terminate", &s_ipr_symbol_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_CACHE_TERMINATE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_cache_terminate_finish"
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
    ipr_symbol_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_symbol_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_ANIMATE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_ANIMATE))
    icl_trace_record (NULL, ipr_symbol_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_ANIMATE))
    icl_stats_inc ("ipr_symbol_animate", &s_ipr_symbol_animate_stats);
#endif

ipr_symbol_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_ANIMATE))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_ANIMATE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_animate_finish"
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
    ipr_symbol_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_symbol_new_in_scope_ (
    ipr_symbol_t * * self_p,            //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_symbol_table_t * table,         //  Table to insert into
    char * key,                         //  Hash key
    void * data                         //  Data for symbol
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SYMBOL)  ||  defined (BASE_ANIMATE_IPR_SYMBOL_NEW_IN_SCOPE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, data);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_symbol_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SYMBOL)  ||  defined (BASE_STATS_IPR_SYMBOL_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_symbol_new_in_scope", &s_ipr_symbol_new_in_scope_stats);
#endif

*self_p = ipr_symbol_new_ (file,line,table,key,data);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_symbol_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_symbol_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SYMBOL)   || defined (BASE_ANIMATE_IPR_SYMBOL_NEW_IN_SCOPE))
    if (ipr_symbol_animating)
        icl_console_print ("<ipr_symbol_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" data=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, data, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_NEW)   || defined (BASE_TRACE_IPR_SYMBOL_DESTROY)   || defined (BASE_TRACE_IPR_SYMBOL_ASSUME)   || defined (BASE_TRACE_IPR_SYMBOL_SELFTEST)   || defined (BASE_TRACE_IPR_SYMBOL_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_IPR_SYMBOL_SHOW)   || defined (BASE_TRACE_IPR_SYMBOL_TERMINATE)   || defined (BASE_TRACE_IPR_SYMBOL_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_SYMBOL_ALLOC)   || defined (BASE_TRACE_IPR_SYMBOL_FREE)   || defined (BASE_TRACE_IPR_SYMBOL_READ_LOCK)   || defined (BASE_TRACE_IPR_SYMBOL_WRITE_LOCK)   || defined (BASE_TRACE_IPR_SYMBOL_UNLOCK)   || defined (BASE_TRACE_IPR_SYMBOL_LINK)   || defined (BASE_TRACE_IPR_SYMBOL_UNLINK)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_PURGE)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_SYMBOL_ANIMATE)   || defined (BASE_TRACE_IPR_SYMBOL_NEW_IN_SCOPE) )
void
ipr_symbol_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "assume"; break;
        case 4: method_name = "selftest"; break;
        case 5: method_name = "remove from all containers"; break;
        case 6: method_name = "show"; break;
        case 7: method_name = "terminate"; break;
        case 8: method_name = "destroy public"; break;
        case 9: method_name = "alloc"; break;
        case 10: method_name = "free"; break;
        case 11: method_name = "read lock"; break;
        case 12: method_name = "write lock"; break;
        case 13: method_name = "unlock"; break;
        case 14: method_name = "link"; break;
        case 15: method_name = "unlink"; break;
        case 16: method_name = "cache initialise"; break;
        case 17: method_name = "cache purge"; break;
        case 18: method_name = "cache terminate"; break;
        case 19: method_name = "animate"; break;
        case 20: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_symbol %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_symbol_version_start     = "VeRsIoNsTaRt:ipc";
char *ipr_symbol_component         = "ipr_symbol ";
char *ipr_symbol_version           = "1.0 ";
char *ipr_symbol_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_symbol_filename          = "ipr_symbol.icl ";
char *ipr_symbol_builddate         = "2010/10/06 ";
char *ipr_symbol_version_end       = "VeRsIoNeNd:ipc";

