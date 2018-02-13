/*---------------------------------------------------------------------------
    amq_queue_bindings_list.c - amq_queue_bindings_list component

    Generated from amq_queue_bindings_list.icl by icl_gen using GSL/4.
    
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
#include "amq_queue_bindings_list.h"    //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_queue_bindings_list_t

//  Shorthands for class methods                                               

#define self_selftest       amq_queue_bindings_list_selftest
#define self_new            amq_queue_bindings_list_new
#define self_remove_from_all_containers  amq_queue_bindings_list_remove_from_all_containers
#define self_show           amq_queue_bindings_list_show
#define self_iter_new       amq_queue_bindings_list_iter_new
#define self_iter_object    amq_queue_bindings_list_iter_object
#define self_iter_destroy   amq_queue_bindings_list_iter_destroy
#define self_annihilate     amq_queue_bindings_list_annihilate
#define self_isempty        amq_queue_bindings_list_isempty
#define self_push           amq_queue_bindings_list_push
#define self_pop            amq_queue_bindings_list_pop
#define self_queue          amq_queue_bindings_list_queue
#define self_relink_before  amq_queue_bindings_list_relink_before
#define self_remove         amq_queue_bindings_list_remove
#define self_first          amq_queue_bindings_list_first
#define self_last           amq_queue_bindings_list_last
#define self_next           amq_queue_bindings_list_next
#define self_prev           amq_queue_bindings_list_prev
#define self_count          amq_queue_bindings_list_count
#define self_rehook         amq_queue_bindings_list_rehook
#define self_unhook         amq_queue_bindings_list_unhook
#define self_cache_initialise  amq_queue_bindings_list_cache_initialise
#define self_cache_purge    amq_queue_bindings_list_cache_purge
#define self_terminate      amq_queue_bindings_list_terminate
#define self_destroy        amq_queue_bindings_list_destroy
#define self_alloc          amq_queue_bindings_list_alloc
#define self_free           amq_queue_bindings_list_free
#define self_link           amq_queue_bindings_list_link
#define self_unlink         amq_queue_bindings_list_unlink
#define self_cache_terminate  amq_queue_bindings_list_cache_terminate
#define self_animate        amq_queue_bindings_list_animate
#define self_new_in_scope   amq_queue_bindings_list_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_SELFTEST))
static icl_stats_t *s_amq_queue_bindings_list_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_NEW))
static icl_stats_t *s_amq_queue_bindings_list_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_amq_queue_bindings_list_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_SHOW))
static icl_stats_t *s_amq_queue_bindings_list_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ITER_NEW))
static icl_stats_t *s_amq_queue_bindings_list_iter_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ITER_OBJECT))
static icl_stats_t *s_amq_queue_bindings_list_iter_object_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ITER_DESTROY))
static icl_stats_t *s_amq_queue_bindings_list_iter_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_DESTROY))
static icl_stats_t *s_amq_queue_bindings_list_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ISEMPTY))
static icl_stats_t *s_amq_queue_bindings_list_isempty_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_PUSH))
static icl_stats_t *s_amq_queue_bindings_list_push_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_POP))
static icl_stats_t *s_amq_queue_bindings_list_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_QUEUE))
static icl_stats_t *s_amq_queue_bindings_list_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_RELINK_BEFORE))
static icl_stats_t *s_amq_queue_bindings_list_relink_before_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_REMOVE))
static icl_stats_t *s_amq_queue_bindings_list_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_FIRST))
static icl_stats_t *s_amq_queue_bindings_list_first_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_LAST))
static icl_stats_t *s_amq_queue_bindings_list_last_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_NEXT))
static icl_stats_t *s_amq_queue_bindings_list_next_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_PREV))
static icl_stats_t *s_amq_queue_bindings_list_prev_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_COUNT))
static icl_stats_t *s_amq_queue_bindings_list_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_REHOOK))
static icl_stats_t *s_amq_queue_bindings_list_rehook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_UNHOOK))
static icl_stats_t *s_amq_queue_bindings_list_unhook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_CACHE_INITIALISE))
static icl_stats_t *s_amq_queue_bindings_list_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_CACHE_PURGE))
static icl_stats_t *s_amq_queue_bindings_list_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_TERMINATE))
static icl_stats_t *s_amq_queue_bindings_list_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_DESTROY_PUBLIC))
static icl_stats_t *s_amq_queue_bindings_list_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ALLOC))
static icl_stats_t *s_amq_queue_bindings_list_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_FREE))
static icl_stats_t *s_amq_queue_bindings_list_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_LINK))
static icl_stats_t *s_amq_queue_bindings_list_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_UNLINK))
static icl_stats_t *s_amq_queue_bindings_list_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_CACHE_TERMINATE))
static icl_stats_t *s_amq_queue_bindings_list_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ANIMATE))
static icl_stats_t *s_amq_queue_bindings_list_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_NEW_IN_SCOPE))
static icl_stats_t *s_amq_queue_bindings_list_new_in_scope_stats = NULL;
#endif
#define amq_queue_bindings_list_annihilate(self)  amq_queue_bindings_list_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_queue_bindings_list_annihilate_ (
amq_queue_bindings_list_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static inline void
    amq_queue_bindings_list_rehook (
amq_queue_bindings_list_iter_t * item,   //  Not documented
amq_queue_bindings_list_iter_t * left,   //  Not documented
amq_queue_bindings_list_iter_t * right  //  Not documented
);

static inline amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_unhook (
amq_queue_bindings_list_iter_t * item   //  Not documented
);

static void
    amq_queue_bindings_list_cache_initialise (
void);

static void
    amq_queue_bindings_list_cache_purge (
void);

#define amq_queue_bindings_list_alloc()  amq_queue_bindings_list_alloc_ (__FILE__, __LINE__)
static amq_queue_bindings_list_t *
    amq_queue_bindings_list_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_bindings_list_free(self)  amq_queue_bindings_list_free_ (self, __FILE__, __LINE__)
static void
    amq_queue_bindings_list_free_ (
amq_queue_bindings_list_t * self,       //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_queue_bindings_list_cache_terminate (
void);

Bool
    amq_queue_bindings_list_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static icl_cache_t
    *s_iter_cache = NULL;
/*  -------------------------------------------------------------------------
    amq_queue_bindings_list_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_bindings_list_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_SELFTEST))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_SELFTEST))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_SELFTEST))
    icl_stats_inc ("amq_queue_bindings_list_selftest", &s_amq_queue_bindings_list_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_SELFTEST))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_SELFTEST))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_selftest_finish"
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
    amq_queue_bindings_list_new

    Type: Component method
    Creates and initialises a new amq_queue_bindings_list_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

amq_queue_bindings_list_t *
    amq_queue_bindings_list_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_queue_bindings_list_table_t * table,   //  Table to insert into
    char * key                          //  Hash key
)
{
    amq_queue_bindings_list_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_NEW))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_NEW))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_NEW))
    icl_stats_inc ("amq_queue_bindings_list_new", &s_amq_queue_bindings_list_new_stats);
#endif

    self = amq_queue_bindings_list_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_QUEUE_BINDINGS_LIST_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_queue_bindings_list_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->amq_queue_bindings_list_iter.next = &self->amq_queue_bindings_list_iter;
self->amq_queue_bindings_list_iter.prev = &self->amq_queue_bindings_list_iter;
self->amq_queue_bindings_list_iter.head = self;
self->amq_queue_bindings_list_iter.item = NULL;
self->count = 0;

if (table && self && amq_queue_bindings_list_table_insert (table, key, self))
    amq_queue_bindings_list_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_NEW))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_NEW))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_queue_bindings_list_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_queue_bindings_list_remove_from_all_containers (
    amq_queue_bindings_list_t * self    //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("amq_queue_bindings_list_remove_from_all_containers", &s_amq_queue_bindings_list_remove_from_all_containers_stats);
#endif

AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
amq_queue_bindings_list_table_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_remove_from_all_containers_finish"
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
    amq_queue_bindings_list_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_bindings_list_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_queue_bindings_list_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_SHOW))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_SHOW))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_SHOW))
    icl_stats_inc ("amq_queue_bindings_list_show", &s_amq_queue_bindings_list_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_queue_bindings_list zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
    if (self->history_last > AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH;
        self->history_last %= AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_queue_bindings_list>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_SHOW))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_SHOW))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_show_finish"
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
    amq_queue_bindings_list_iter_new

    Type: Component method
    -------------------------------------------------------------------------
 */

amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_iter_new (
    amq_binding_t * item                //  Not documented
)
{
    amq_queue_bindings_list_iter_t *
        iter;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ITER_NEW))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_iter_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ITER_NEW))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ITER_NEW))
    icl_stats_inc ("amq_queue_bindings_list_iter_new", &s_amq_queue_bindings_list_iter_new_stats);
#endif

iter = icl_mem_cache_alloc (s_iter_cache);
iter->next = iter;
iter->prev = iter;
iter->head = NULL;
iter->item = amq_binding_link (item);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ITER_NEW))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ITER_NEW))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_iter_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" iter=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, iter);
#endif


    return (iter);
}
/*  -------------------------------------------------------------------------
    amq_queue_bindings_list_iter_object

    Type: Component method
    -------------------------------------------------------------------------
 */

amq_binding_t *
    amq_queue_bindings_list_iter_object (
    amq_queue_bindings_list_iter_t * iter  //  Not documented
)
{
    amq_binding_t *
        item;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ITER_OBJECT))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_iter_object_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" iter=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, iter);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ITER_OBJECT))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ITER_OBJECT))
    icl_stats_inc ("amq_queue_bindings_list_iter_object", &s_amq_queue_bindings_list_iter_object_stats);
#endif

item = amq_binding_link (iter->item);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ITER_OBJECT))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ITER_OBJECT))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_iter_object_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" iter=\"%pp\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, iter, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    amq_queue_bindings_list_iter_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_bindings_list_iter_destroy (
    amq_queue_bindings_list_iter_t * ( * iter_p )  //  Not documented
)
{
    amq_queue_bindings_list_iter_t *
        iter = *iter_p;                 //  Dereferenced iter

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ITER_DESTROY))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_iter_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" iter=\"%pp\""
" iter=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, iter, iter);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ITER_DESTROY))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ITER_DESTROY))
    icl_stats_inc ("amq_queue_bindings_list_iter_destroy", &s_amq_queue_bindings_list_iter_destroy_stats);
#endif

if (iter) {
    amq_queue_bindings_list_remove (iter);
    amq_binding_unlink (&iter->item);
    icl_mem_free (iter);
    *iter_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ITER_DESTROY))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ITER_DESTROY))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_iter_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" iter=\"%pp\""
" iter=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, iter, iter);
#endif

}
/*  -------------------------------------------------------------------------
    amq_queue_bindings_list_annihilate

    Type: Component method
    Destroys the list and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    amq_queue_bindings_list_annihilate_ (
    amq_queue_bindings_list_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
    int
        history_last;
#endif

amq_queue_bindings_list_iter_t
    *item;
    amq_queue_bindings_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_DESTROY))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_DESTROY))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_DESTROY))
    icl_stats_inc ("amq_queue_bindings_list_annihilate", &s_amq_queue_bindings_list_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = self->links;
#endif

    AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
    amq_queue_bindings_list_remove_from_all_containers (self);

item = (amq_queue_bindings_list_iter_t *) self->amq_queue_bindings_list_iter.next;
while (item != &self->amq_queue_bindings_list_iter) {
    //  Unlink child without lock (we already have the lock)               
    amq_queue_bindings_list_unhook (item);

    amq_queue_bindings_list_iter_destroy (&item);
    item = (amq_queue_bindings_list_iter_t *) self->amq_queue_bindings_list_iter.next;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_DESTROY))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_DESTROY))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_destroy_finish"
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
    amq_queue_bindings_list_isempty

    Type: Component method
    Accepts a amq_queue_bindings_list_t reference and returns zero in case of success,
    1 in case of errors.
    Returns true if the list is empty, else returns false.
    -------------------------------------------------------------------------
 */

int
    amq_queue_bindings_list_isempty (
    amq_queue_bindings_list_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ISEMPTY))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_isempty_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ISEMPTY))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ISEMPTY))
    icl_stats_inc ("amq_queue_bindings_list_isempty", &s_amq_queue_bindings_list_isempty_stats);
#endif

AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

rc = (self->amq_queue_bindings_list_iter.next == &self->amq_queue_bindings_list_iter);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ISEMPTY))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ISEMPTY))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_isempty_finish"
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
    amq_queue_bindings_list_push

    Type: Component method
    Accepts a amq_queue_bindings_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the start of the specified list. If the item
    was on another list, it is first detached.  After this method,
    list->next points to the item.
    -------------------------------------------------------------------------
 */

int
    amq_queue_bindings_list_push (
    amq_queue_bindings_list_t * self,   //  Reference to object
    amq_binding_t * item                //  Not documented
)
{


amq_queue_bindings_list_iter_t
    *iter;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_PUSH))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_push_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_PUSH))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_PUSH))
    icl_stats_inc ("amq_queue_bindings_list_push", &s_amq_queue_bindings_list_push_stats);
#endif



AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

iter = amq_queue_bindings_list_iter_new (item);
icl_atomic_inc32 (&self->count);
amq_queue_bindings_list_rehook (iter, &self->amq_queue_bindings_list_iter, (amq_queue_bindings_list_iter_t *) self->amq_queue_bindings_list_iter.next);
}
else
    rc = -1;                        //  Return error on zombie object.



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_PUSH))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_PUSH))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_push_finish"
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
    amq_queue_bindings_list_pop

    Type: Component method
    Removes the next item in the list, if any, and returns it.  If
    the list was empty, returns NULL.
    
    The number of links is unchanged; removing from the list and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

amq_binding_t *
    amq_queue_bindings_list_pop (
    amq_queue_bindings_list_t * self    //  The list
)
{


amq_queue_bindings_list_iter_t
    *iter = NULL;
    amq_binding_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_POP))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_pop_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_POP))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_POP))
    icl_stats_inc ("amq_queue_bindings_list_pop", &s_amq_queue_bindings_list_pop_stats);
#endif



AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

if (self->amq_queue_bindings_list_iter.next != &self->amq_queue_bindings_list_iter) {
    iter = amq_queue_bindings_list_unhook ((amq_queue_bindings_list_iter_t *) self->amq_queue_bindings_list_iter.next);
    icl_atomic_dec32 (&self->count);
    item = iter->item;
    iter->item = NULL;          //  So don't destroy item
    amq_queue_bindings_list_iter_destroy (&iter);
}
}



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_POP))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_POP))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_pop_finish"
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
    amq_queue_bindings_list_queue

    Type: Component method
    Accepts a amq_queue_bindings_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the end of the specified list. If the item
    was on another list, it is first detached.
    
    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    amq_queue_bindings_list_queue (
    amq_queue_bindings_list_t * self,   //  Reference to object
    amq_binding_t * item                //  Not documented
)
{


amq_queue_bindings_list_iter_t
    *iter;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_QUEUE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_queue_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_QUEUE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_QUEUE))
    icl_stats_inc ("amq_queue_bindings_list_queue", &s_amq_queue_bindings_list_queue_stats);
#endif



AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

iter = amq_queue_bindings_list_iter_new (item);
icl_atomic_inc32 (&self->count);
amq_queue_bindings_list_rehook (iter, (amq_queue_bindings_list_iter_t *) self->amq_queue_bindings_list_iter.prev, &self->amq_queue_bindings_list_iter);
}
else
    rc = -1;                        //  Return error on zombie object.



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_QUEUE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_QUEUE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_queue_finish"
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
    amq_queue_bindings_list_relink_before

    Type: Component method
    Accepts a amq_queue_bindings_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item before a specified item. If the item was on another list,
    it is first detached.
    
    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    amq_queue_bindings_list_relink_before (
    amq_queue_bindings_list_iter_t * item,   //  Not documented
    amq_queue_bindings_list_iter_t * where  //  Not documented
)
{


    int
        rc = 0;                         //  Return code
    amq_queue_bindings_list_t *
        self = (amq_queue_bindings_list_t *) where->head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_RELINK_BEFORE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_relink_before_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_RELINK_BEFORE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_RELINK_BEFORE))
    icl_stats_inc ("amq_queue_bindings_list_relink_before", &s_amq_queue_bindings_list_relink_before_stats);
#endif



AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//  If head is non-null then we are moving within the        
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->head) {
    icl_atomic_inc32 (&self->count);
}
else
if (item->head != self) {
    icl_console_print ("E: amq_queue_bindings_list_iter item inserted into multiple list containers");
    assert (item->head == self);
}            
amq_queue_bindings_list_unhook (item);
amq_queue_bindings_list_rehook (item, (amq_queue_bindings_list_iter_t *) where->prev, where);
}
else
    rc = -1;                        //  Return error on zombie object.



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_RELINK_BEFORE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_RELINK_BEFORE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_relink_before_finish"
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
    amq_queue_bindings_list_remove

    Type: Component method
    Removes the amq_queue_bindings_list_iter item from any list it is in.
    
    If it was in a list, the number of links is decremented.
    -------------------------------------------------------------------------
 */

int
    amq_queue_bindings_list_remove (
    amq_queue_bindings_list_iter_t * item  //  Not documented
)
{


    amq_queue_bindings_list_t *
        self = (amq_queue_bindings_list_t *) item->head;  //  The list
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_REMOVE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_remove_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_REMOVE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_REMOVE))
    icl_stats_inc ("amq_queue_bindings_list_remove", &s_amq_queue_bindings_list_remove_stats);
#endif



if (self
&&  self == item->head) { //  Catch case where item moved
    amq_queue_bindings_list_unhook (item);
    icl_atomic_dec32 (&self->count);
}


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_REMOVE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_REMOVE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_remove_finish"
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
    amq_queue_bindings_list_first

    Type: Component method
    Returns the first amq_queue_bindings_list_iter item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_first_ (
    amq_queue_bindings_list_t * self,   //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    amq_queue_bindings_list_iter_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_FIRST))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_first_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_FIRST))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_FIRST))
    icl_stats_inc ("amq_queue_bindings_list_first", &s_amq_queue_bindings_list_first_stats);
#endif



AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

item = (amq_queue_bindings_list_iter_t *) self->amq_queue_bindings_list_iter.next;
if (item == &self->amq_queue_bindings_list_iter)
    item = NULL;
}



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_FIRST))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_FIRST))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_first_finish"
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
    amq_queue_bindings_list_last

    Type: Component method
    Returns the last amq_queue_bindings_list_iter item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_last_ (
    amq_queue_bindings_list_t * self,   //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    amq_queue_bindings_list_iter_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_LAST))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_last_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_LAST))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_LAST))
    icl_stats_inc ("amq_queue_bindings_list_last", &s_amq_queue_bindings_list_last_stats);
#endif



AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

item = (amq_queue_bindings_list_iter_t *) self->amq_queue_bindings_list_iter.prev;
if (item == &self->amq_queue_bindings_list_iter)
    item = NULL;
}



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_LAST))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_LAST))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_last_finish"
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
    amq_queue_bindings_list_next

    Type: Component method
    Returns the following item on the amq_queue_bindings_list_iter list. If the provided item
    is null, returns the first item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_next_ (
    amq_queue_bindings_list_iter_t * ( * item_p ),   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    amq_queue_bindings_list_iter_t *
        item = *item_p;                 //  Dereferenced item
    amq_queue_bindings_list_iter_t *
        next = NULL;                    //  The item to return
    amq_queue_bindings_list_t *
        self = (amq_queue_bindings_list_t *) item->head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_NEXT))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_next_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_NEXT))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_NEXT))
    icl_stats_inc ("amq_queue_bindings_list_next", &s_amq_queue_bindings_list_next_stats);
#endif



if (self
&&  self == item->head) { //  Catch case where item moved
    next = (amq_queue_bindings_list_iter_t *) item->next;
    if (next == &self->amq_queue_bindings_list_iter)
        next = NULL;
}


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_NEXT))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_NEXT))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_next_finish"
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
    amq_queue_bindings_list_prev

    Type: Component method
    Returns the preceding item on the amq_queue_bindings_list_iter list. If the provided item
    is null, returns the last item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_prev_ (
    amq_queue_bindings_list_iter_t * ( * item_p ),   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    amq_queue_bindings_list_iter_t *
        item = *item_p;                 //  Dereferenced item
    amq_queue_bindings_list_iter_t *
        prev = NULL;                    //  The item to return
    amq_queue_bindings_list_t *
        self = (amq_queue_bindings_list_t *) item->head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_PREV))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_prev_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_PREV))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_PREV))
    icl_stats_inc ("amq_queue_bindings_list_prev", &s_amq_queue_bindings_list_prev_stats);
#endif



if (self
&&  self == item->head) { //  Catch case where item moved
    prev = (amq_queue_bindings_list_iter_t *) item->prev;
    if (prev == &self->amq_queue_bindings_list_iter)
        prev = NULL;
}


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_PREV))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_PREV))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_prev_finish"
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
    amq_queue_bindings_list_count

    Type: Component method
    Return the count of the number of objects in the list.
    -------------------------------------------------------------------------
 */

qbyte
    amq_queue_bindings_list_count (
    amq_queue_bindings_list_t * self    //  The list
)
{
    qbyte
        count;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_COUNT))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_count_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_COUNT))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_COUNT))
    icl_stats_inc ("amq_queue_bindings_list_count", &s_amq_queue_bindings_list_count_stats);
#endif

//
AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
icl_atomic_set32 (&count, self->count);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_COUNT))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_COUNT))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_count_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" count=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    amq_queue_bindings_list_rehook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    amq_queue_bindings_list_rehook (
    amq_queue_bindings_list_iter_t * item,   //  Not documented
    amq_queue_bindings_list_iter_t * left,   //  Not documented
    amq_queue_bindings_list_iter_t * right  //  Not documented
)
{
amq_queue_bindings_list_iter_t
    *swap;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_REHOOK))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_rehook_start"
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

#if (defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_REHOOK))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_REHOOK))
    icl_stats_inc ("amq_queue_bindings_list_rehook", &s_amq_queue_bindings_list_rehook_stats);
#endif

swap = (amq_queue_bindings_list_iter_t *) left->next;
left->next = item->next;
item->next = swap;

swap = (amq_queue_bindings_list_iter_t *) item->prev;
item->prev = right->prev;
right->prev = swap;

item->head = left->head;
#if (defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_REHOOK))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_REHOOK))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_rehook_finish"
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
    amq_queue_bindings_list_unhook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_unhook (
    amq_queue_bindings_list_iter_t * item  //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_UNHOOK))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_unhook_start"
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

#if (defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_UNHOOK))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_UNHOOK))
    icl_stats_inc ("amq_queue_bindings_list_unhook", &s_amq_queue_bindings_list_unhook_stats);
#endif

amq_queue_bindings_list_rehook (item, (amq_queue_bindings_list_iter_t *) item->prev, (amq_queue_bindings_list_iter_t *) item->next);
item->head = NULL;
#if (defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_UNHOOK))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_UNHOOK))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_unhook_finish"
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
    amq_queue_bindings_list_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_queue_bindings_list_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_CACHE_INITIALISE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_CACHE_INITIALISE))
    icl_stats_inc ("amq_queue_bindings_list_cache_initialise", &s_amq_queue_bindings_list_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_queue_bindings_list_t));
icl_system_register (amq_queue_bindings_list_cache_purge, amq_queue_bindings_list_cache_terminate);

s_iter_cache = icl_cache_get (sizeof (amq_queue_bindings_list_iter_t));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_CACHE_INITIALISE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_cache_initialise_finish"
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
    amq_queue_bindings_list_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_bindings_list_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_CACHE_PURGE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_CACHE_PURGE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_CACHE_PURGE))
    icl_stats_inc ("amq_queue_bindings_list_cache_purge", &s_amq_queue_bindings_list_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

icl_mem_cache_purge (s_iter_cache);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_CACHE_PURGE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_CACHE_PURGE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_cache_purge_finish"
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
    amq_queue_bindings_list_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_bindings_list_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_TERMINATE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_TERMINATE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_TERMINATE))
    icl_stats_inc ("amq_queue_bindings_list_terminate", &s_amq_queue_bindings_list_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_TERMINATE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_TERMINATE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_terminate_finish"
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
    amq_queue_bindings_list_destroy

    Type: Component method
    Destroys a amq_queue_bindings_list_t object. Takes the address of a
    amq_queue_bindings_list_t reference (a pointer to a pointer) and nullifies the
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
    amq_queue_bindings_list_destroy_ (
    amq_queue_bindings_list_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_queue_bindings_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_DESTROY_PUBLIC))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_DESTROY_PUBLIC))
    icl_stats_inc ("amq_queue_bindings_list_destroy", &s_amq_queue_bindings_list_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_queue_bindings_list_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on amq_queue_bindings_list object");
        amq_queue_bindings_list_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_queue_bindings_list_free_ ((amq_queue_bindings_list_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_DESTROY_PUBLIC))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_destroy_public_finish"
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
    amq_queue_bindings_list_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_queue_bindings_list_t *
    amq_queue_bindings_list_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_queue_bindings_list_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ALLOC))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ALLOC))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ALLOC))
    icl_stats_inc ("amq_queue_bindings_list_alloc", &s_amq_queue_bindings_list_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_queue_bindings_list_cache_initialise ();

self = (amq_queue_bindings_list_t *) icl_mem_cache_alloc_ (s_cache, file, line);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ALLOC))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ALLOC))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_alloc_finish"
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
    amq_queue_bindings_list_free

    Type: Component method
    Freess a amq_queue_bindings_list_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_queue_bindings_list_free_ (
    amq_queue_bindings_list_t * self,   //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_FREE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_FREE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_FREE))
    icl_stats_inc ("amq_queue_bindings_list_free", &s_amq_queue_bindings_list_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = self->links;
#endif

    self->object_tag = AMQ_QUEUE_BINDINGS_LIST_DEAD;
    icl_mem_free (self);
}
self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_FREE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_FREE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_free_finish"
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
    amq_queue_bindings_list_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_queue_bindings_list_t *
    amq_queue_bindings_list_link_ (
    amq_queue_bindings_list_t * self,   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_LINK))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_LINK))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_LINK))
    icl_stats_inc ("amq_queue_bindings_list_link", &s_amq_queue_bindings_list_link_stats);
#endif

    if (self) {
        AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_LINK))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_LINK))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_link_finish"
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
    amq_queue_bindings_list_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_queue_bindings_list_unlink_ (
    amq_queue_bindings_list_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
    int
        history_last;
#endif

    amq_queue_bindings_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_UNLINK))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_UNLINK))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_UNLINK))
    icl_stats_inc ("amq_queue_bindings_list_unlink", &s_amq_queue_bindings_list_unlink_stats);
#endif

    if (self) {
        AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_queue_bindings_list object");
            amq_queue_bindings_list_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_queue_bindings_list_annihilate_ (self_p, file, line);
        amq_queue_bindings_list_free_ ((amq_queue_bindings_list_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_UNLINK))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_UNLINK))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_unlink_finish"
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
    amq_queue_bindings_list_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_bindings_list_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_CACHE_TERMINATE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_CACHE_TERMINATE))
    icl_stats_inc ("amq_queue_bindings_list_cache_terminate", &s_amq_queue_bindings_list_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_CACHE_TERMINATE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_cache_terminate_finish"
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
    amq_queue_bindings_list_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_queue_bindings_list_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ANIMATE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ANIMATE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_ANIMATE))
    icl_stats_inc ("amq_queue_bindings_list_animate", &s_amq_queue_bindings_list_animate_stats);
#endif

amq_queue_bindings_list_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ANIMATE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_ANIMATE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_animate_finish"
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
    amq_queue_bindings_list_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_bindings_list_new_in_scope_ (
    amq_queue_bindings_list_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_queue_bindings_list_table_t * table,   //  Table to insert into
    char * key                          //  Hash key
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_NEW_IN_SCOPE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST)  ||  defined (BASE_STATS_AMQ_QUEUE_BINDINGS_LIST_NEW_IN_SCOPE))
    icl_stats_inc ("amq_queue_bindings_list_new_in_scope", &s_amq_queue_bindings_list_new_in_scope_stats);
#endif

*self_p = amq_queue_bindings_list_new_ (file,line,table,key);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_queue_bindings_list_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_queue_bindings_list_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_ANIMATE_AMQ_QUEUE_BINDINGS_LIST_NEW_IN_SCOPE))
    if (amq_queue_bindings_list_animating)
        icl_console_print ("<amq_queue_bindings_list_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_SELFTEST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_NEW)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_SHOW)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ITER_NEW)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ITER_OBJECT)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ITER_DESTROY)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_DESTROY)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ISEMPTY)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_PUSH)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_POP)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_RELINK_BEFORE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_REMOVE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_FIRST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_LAST)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_NEXT)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_PREV)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_COUNT)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_REHOOK)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_UNHOOK)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_TERMINATE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ALLOC)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_FREE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_LINK)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_UNLINK)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_ANIMATE)   || defined (BASE_TRACE_AMQ_QUEUE_BINDINGS_LIST_NEW_IN_SCOPE) )
void
amq_queue_bindings_list_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "selftest"; break;
        case 2: method_name = "new"; break;
        case 3: method_name = "remove from all containers"; break;
        case 4: method_name = "show"; break;
        case 5: method_name = "iter new"; break;
        case 6: method_name = "iter object"; break;
        case 7: method_name = "iter destroy"; break;
        case 8: method_name = "destroy"; break;
        case 9: method_name = "isempty"; break;
        case 10: method_name = "push"; break;
        case 11: method_name = "pop"; break;
        case 12: method_name = "queue"; break;
        case 13: method_name = "relink before"; break;
        case 14: method_name = "remove"; break;
        case 15: method_name = "first"; break;
        case 16: method_name = "last"; break;
        case 17: method_name = "next"; break;
        case 18: method_name = "prev"; break;
        case 19: method_name = "count"; break;
        case 20: method_name = "rehook"; break;
        case 21: method_name = "unhook"; break;
        case 22: method_name = "cache initialise"; break;
        case 23: method_name = "cache purge"; break;
        case 24: method_name = "terminate"; break;
        case 25: method_name = "destroy public"; break;
        case 26: method_name = "alloc"; break;
        case 27: method_name = "free"; break;
        case 28: method_name = "link"; break;
        case 29: method_name = "unlink"; break;
        case 30: method_name = "cache terminate"; break;
        case 31: method_name = "animate"; break;
        case 32: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_queue_bindings_list %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_queue_bindings_list_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_queue_bindings_list_component  = "amq_queue_bindings_list ";
char *amq_queue_bindings_list_version  = "1.0 ";
char *amq_queue_bindings_list_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_queue_bindings_list_filename  = "amq_queue_bindings_list.icl ";
char *amq_queue_bindings_list_builddate  = "2010/10/06 ";
char *amq_queue_bindings_list_version_end  = "VeRsIoNeNd:ipc";

