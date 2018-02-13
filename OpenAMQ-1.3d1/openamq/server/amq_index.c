/*---------------------------------------------------------------------------
    amq_index.c - amq_index component

    Holds a match index, which is a text string on which AMQ will index and
    match messages.  Each index holds a bindset bitmap that represents all
    bindings that match that index.  Indices can be accessed via a hash
    lookup (by value) or array lookup (by number, for iterating through all
    indices).
    Generated from amq_index.icl by icl_gen using GSL/4.
    
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
#include "amq_index.h"                  //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_index_t

//  Shorthands for class methods                                               

#define self_new            amq_index_new
#define self_annihilate     amq_index_annihilate
#define self_selftest       amq_index_selftest
#define self_count          amq_index_count
#define self_remove_from_all_containers  amq_index_remove_from_all_containers
#define self_show           amq_index_show
#define self_terminate      amq_index_terminate
#define self_destroy        amq_index_destroy
#define self_alloc          amq_index_alloc
#define self_free           amq_index_free
#define self_link           amq_index_link
#define self_unlink         amq_index_unlink
#define self_cache_initialise  amq_index_cache_initialise
#define self_cache_purge    amq_index_cache_purge
#define self_cache_terminate  amq_index_cache_terminate
#define self_animate        amq_index_animate
#define self_new_in_scope   amq_index_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_NEW))
static icl_stats_t *s_amq_index_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_DESTROY))
static icl_stats_t *s_amq_index_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_SELFTEST))
static icl_stats_t *s_amq_index_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_COUNT))
static icl_stats_t *s_amq_index_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_amq_index_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_SHOW))
static icl_stats_t *s_amq_index_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_TERMINATE))
static icl_stats_t *s_amq_index_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_DESTROY_PUBLIC))
static icl_stats_t *s_amq_index_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_ALLOC))
static icl_stats_t *s_amq_index_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_FREE))
static icl_stats_t *s_amq_index_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_LINK))
static icl_stats_t *s_amq_index_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_UNLINK))
static icl_stats_t *s_amq_index_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_CACHE_INITIALISE))
static icl_stats_t *s_amq_index_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_CACHE_PURGE))
static icl_stats_t *s_amq_index_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_CACHE_TERMINATE))
static icl_stats_t *s_amq_index_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_ANIMATE))
static icl_stats_t *s_amq_index_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_NEW_IN_SCOPE))
static icl_stats_t *s_amq_index_new_in_scope_stats = NULL;
#endif
#define amq_index_annihilate(self)      amq_index_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_index_annihilate_ (
amq_index_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_index_alloc()               amq_index_alloc_ (__FILE__, __LINE__)
static amq_index_t *
    amq_index_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_index_free(self)            amq_index_free_ (self, __FILE__, __LINE__)
static void
    amq_index_free_ (
amq_index_t * self,                     //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_index_cache_initialise (
void);

static void
    amq_index_cache_purge (
void);

static void
    amq_index_cache_terminate (
void);

Bool
    amq_index_animating = TRUE;         //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static qbyte
    s_amq_index_count = 0;
/*  -------------------------------------------------------------------------
    amq_index_new

    Type: Component method
    Creates and initialises a new amq_index_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    Initialises a new array item without placing it into any array.
    -------------------------------------------------------------------------
 */

amq_index_t *
    amq_index_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_index_hash_t * table,           //  Table to insert into
    char * key,                         //  Hash key
    amq_index_array_t * array           //  Array to insert into
)
{
#define index array->bound
    amq_index_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_NEW))
    if (amq_index_animating)
        icl_console_print ("<amq_index_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" array=\"%pp\""
" index=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, array, index);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_NEW))
    icl_trace_record (NULL, amq_index_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_NEW))
    icl_stats_inc ("amq_index_new", &s_amq_index_new_stats);
#endif

    self = amq_index_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_INDEX_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_index_show_);
#endif

self->array_index = 0;
self->array_head = NULL;
self->hash_head = NULL;
self->hash_index = 0;               //  Will be set by container
icl_atomic_inc32 ((volatile qbyte *) &s_amq_index_count);

self->bindset = ipr_bits_new ();
if (table && self && amq_index_hash_insert (table, key, self))
    amq_index_destroy (&self);
amq_index_array_insert (array, index, self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_NEW))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_NEW))
    if (amq_index_animating)
        icl_console_print ("<amq_index_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" array=\"%pp\""
" index=\"%lu\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, array, index, self);
#endif


    return (self);
}
#undef index
/*  -------------------------------------------------------------------------
    amq_index_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_index_annihilate_ (
    amq_index_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
    int
        history_last;
#endif

    amq_index_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_DESTROY))
    if (amq_index_animating)
        icl_console_print ("<amq_index_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_DESTROY))
    icl_trace_record (NULL, amq_index_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_DESTROY))
    icl_stats_inc ("amq_index_annihilate", &s_amq_index_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_INDEX_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_INDEX_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_INDEX_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_INDEX_HISTORY_LENGTH] = self->links;
#endif

    AMQ_INDEX_ASSERT_SANE (self);
    amq_index_remove_from_all_containers (self);

icl_atomic_dec32 ((volatile qbyte *) &s_amq_index_count);

ipr_bits_destroy (&self->bindset);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_DESTROY))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_DESTROY))
    if (amq_index_animating)
        icl_console_print ("<amq_index_destroy_finish"
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
    amq_index_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_index_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_SELFTEST))
    if (amq_index_animating)
        icl_console_print ("<amq_index_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_SELFTEST))
    icl_trace_record (NULL, amq_index_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_SELFTEST))
    icl_stats_inc ("amq_index_selftest", &s_amq_index_selftest_stats);
#endif

amq_index_hash_t
    *index_hash;
amq_index_array_t
    *index_array;
amq_index_t
    *index;

index_hash  = amq_index_hash_new  ();
index_array = amq_index_array_new ();

index = amq_index_new (index_hash, "key1", index_array);
amq_index_unlink (&index);
index = amq_index_new (index_hash, "abc", index_array);
amq_index_unlink (&index);
index = amq_index_new (index_hash, "0x6262", index_array);
amq_index_unlink (&index);
index = amq_index_new (index_hash, "g00df00d", index_array);
amq_index_unlink (&index);

assert (index_array->bound == 4);
amq_index_hash_destroy  (&index_hash);
amq_index_array_destroy (&index_array);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_SELFTEST))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_SELFTEST))
    if (amq_index_animating)
        icl_console_print ("<amq_index_selftest_finish"
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
    amq_index_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_index_count (
void)
{
    qbyte
        count;                          //  Number of instances

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_COUNT))
    if (amq_index_animating)
        icl_console_print ("<amq_index_count_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_COUNT))
    icl_trace_record (NULL, amq_index_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_COUNT))
    icl_stats_inc ("amq_index_count", &s_amq_index_count_stats);
#endif

count = (int) s_amq_index_count;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_COUNT))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_COUNT))
    if (amq_index_animating)
        icl_console_print ("<amq_index_count_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" count=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    amq_index_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_index_remove_from_all_containers (
    amq_index_t * self                  //  The itemThe item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_index_animating)
        icl_console_print ("<amq_index_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_index_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("amq_index_remove_from_all_containers", &s_amq_index_remove_from_all_containers_stats);
#endif

AMQ_INDEX_ASSERT_SANE (self);
amq_index_hash_remove (self);
amq_index_array_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_index_animating)
        icl_console_print ("<amq_index_remove_from_all_containers_finish"
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
    amq_index_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_index_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_index_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_SHOW))
    if (amq_index_animating)
        icl_console_print ("<amq_index_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_SHOW))
    icl_trace_record (NULL, amq_index_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_SHOW))
    icl_stats_inc ("amq_index_show", &s_amq_index_show_stats);
#endif

self = item;
container_links = 0;
if (self->hash_head)
   container_links++;
if (self->array_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_index zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
    if (self->history_last > AMQ_INDEX_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_INDEX_HISTORY_LENGTH;
        self->history_last %= AMQ_INDEX_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_INDEX_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_index>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_SHOW))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_SHOW))
    if (amq_index_animating)
        icl_console_print ("<amq_index_show_finish"
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
    amq_index_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_index_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_TERMINATE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_TERMINATE))
    icl_trace_record (NULL, amq_index_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_TERMINATE))
    icl_stats_inc ("amq_index_terminate", &s_amq_index_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_TERMINATE))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_TERMINATE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_terminate_finish"
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
    amq_index_destroy

    Type: Component method
    Destroys a amq_index_t object. Takes the address of a
    amq_index_t reference (a pointer to a pointer) and nullifies the
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
    amq_index_destroy_ (
    amq_index_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_index_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_DESTROY_PUBLIC))
    if (amq_index_animating)
        icl_console_print ("<amq_index_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_index_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_DESTROY_PUBLIC))
    icl_stats_inc ("amq_index_destroy", &s_amq_index_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_index_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on amq_index object");
        amq_index_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_index_free_ ((amq_index_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_DESTROY_PUBLIC))
    if (amq_index_animating)
        icl_console_print ("<amq_index_destroy_public_finish"
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
    amq_index_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_index_t *
    amq_index_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_index_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_ALLOC))
    if (amq_index_animating)
        icl_console_print ("<amq_index_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_ALLOC))
    icl_trace_record (NULL, amq_index_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_ALLOC))
    icl_stats_inc ("amq_index_alloc", &s_amq_index_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_index_cache_initialise ();

self = (amq_index_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_index_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_ALLOC))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_ALLOC))
    if (amq_index_animating)
        icl_console_print ("<amq_index_alloc_finish"
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
    amq_index_free

    Type: Component method
    Freess a amq_index_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_index_free_ (
    amq_index_t * self,                 //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_FREE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_FREE))
    icl_trace_record (NULL, amq_index_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_FREE))
    icl_stats_inc ("amq_index_free", &s_amq_index_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_INDEX_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_INDEX_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_INDEX_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_INDEX_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (amq_index_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_index_t));
        self->object_tag = AMQ_INDEX_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_FREE))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_FREE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_free_finish"
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
    amq_index_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_index_t *
    amq_index_link_ (
    amq_index_t * self,                 //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_LINK))
    if (amq_index_animating)
        icl_console_print ("<amq_index_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_LINK))
    icl_trace_record (NULL, amq_index_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_LINK))
    icl_stats_inc ("amq_index_link", &s_amq_index_link_stats);
#endif

    if (self) {
        AMQ_INDEX_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_INDEX_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_INDEX_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_INDEX_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_INDEX_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_LINK))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_LINK))
    if (amq_index_animating)
        icl_console_print ("<amq_index_link_finish"
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
    amq_index_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_index_unlink_ (
    amq_index_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
    int
        history_last;
#endif

    amq_index_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_UNLINK))
    if (amq_index_animating)
        icl_console_print ("<amq_index_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_UNLINK))
    icl_trace_record (NULL, amq_index_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_UNLINK))
    icl_stats_inc ("amq_index_unlink", &s_amq_index_unlink_stats);
#endif

    if (self) {
        AMQ_INDEX_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_index object");
            amq_index_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_INDEX_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_INDEX_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_INDEX_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_INDEX_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_index_annihilate_ (self_p, file, line);
        amq_index_free_ ((amq_index_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_UNLINK))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_UNLINK))
    if (amq_index_animating)
        icl_console_print ("<amq_index_unlink_finish"
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
    amq_index_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_index_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_CACHE_INITIALISE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_index_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_CACHE_INITIALISE))
    icl_stats_inc ("amq_index_cache_initialise", &s_amq_index_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_index_t));
icl_system_register (amq_index_cache_purge, amq_index_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_CACHE_INITIALISE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_cache_initialise_finish"
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
    amq_index_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_index_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_CACHE_PURGE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_PURGE))
    icl_trace_record (NULL, amq_index_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_CACHE_PURGE))
    icl_stats_inc ("amq_index_cache_purge", &s_amq_index_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_PURGE))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_CACHE_PURGE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_cache_purge_finish"
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
    amq_index_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_index_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_CACHE_TERMINATE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_index_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_CACHE_TERMINATE))
    icl_stats_inc ("amq_index_cache_terminate", &s_amq_index_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_CACHE_TERMINATE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_cache_terminate_finish"
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
    amq_index_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_index_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_ANIMATE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_ANIMATE))
    icl_trace_record (NULL, amq_index_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_ANIMATE))
    icl_stats_inc ("amq_index_animate", &s_amq_index_animate_stats);
#endif

amq_index_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_ANIMATE))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_ANIMATE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_animate_finish"
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
    amq_index_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_index_new_in_scope_ (
    amq_index_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_index_hash_t * table,           //  Table to insert into
    char * key,                         //  Hash key
    amq_index_array_t * array           //  Array to insert into
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_INDEX)  ||  defined (BASE_ANIMATE_AMQ_INDEX_NEW_IN_SCOPE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" array=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, array);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_index_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_INDEX)  ||  defined (BASE_STATS_AMQ_INDEX_NEW_IN_SCOPE))
    icl_stats_inc ("amq_index_new_in_scope", &s_amq_index_new_in_scope_stats);
#endif

*self_p = amq_index_new_ (file,line,table,key,array);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_index_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_index_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_INDEX)   || defined (BASE_ANIMATE_AMQ_INDEX_NEW_IN_SCOPE))
    if (amq_index_animating)
        icl_console_print ("<amq_index_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" array=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, array, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_NEW)   || defined (BASE_TRACE_AMQ_INDEX_DESTROY)   || defined (BASE_TRACE_AMQ_INDEX_SELFTEST)   || defined (BASE_TRACE_AMQ_INDEX_COUNT)   || defined (BASE_TRACE_AMQ_INDEX_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_INDEX_SHOW)   || defined (BASE_TRACE_AMQ_INDEX_TERMINATE)   || defined (BASE_TRACE_AMQ_INDEX_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_INDEX_ALLOC)   || defined (BASE_TRACE_AMQ_INDEX_FREE)   || defined (BASE_TRACE_AMQ_INDEX_LINK)   || defined (BASE_TRACE_AMQ_INDEX_UNLINK)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_INDEX_ANIMATE)   || defined (BASE_TRACE_AMQ_INDEX_NEW_IN_SCOPE) )
void
amq_index_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "count"; break;
        case 5: method_name = "remove from all containers"; break;
        case 6: method_name = "show"; break;
        case 7: method_name = "terminate"; break;
        case 8: method_name = "destroy public"; break;
        case 9: method_name = "alloc"; break;
        case 10: method_name = "free"; break;
        case 11: method_name = "link"; break;
        case 12: method_name = "unlink"; break;
        case 13: method_name = "cache initialise"; break;
        case 14: method_name = "cache purge"; break;
        case 15: method_name = "cache terminate"; break;
        case 16: method_name = "animate"; break;
        case 17: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_index %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_index_version_start      = "VeRsIoNsTaRt:ipc";
char *amq_index_component          = "amq_index ";
char *amq_index_version            = "1.0 ";
char *amq_index_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_index_filename           = "amq_index.icl ";
char *amq_index_builddate          = "2010/10/06 ";
char *amq_index_version_end        = "VeRsIoNeNd:ipc";

