/*---------------------------------------------------------------------------
    amq_sequence.c - amq_sequence component

Tracks the timestamp for each of a set of senders.  Given a new timestamp and
a sender, verifies that the timestamp is equal to or more recent than the last
known timestamp for the sender.
    Generated from amq_sequence.icl by icl_gen using GSL/4.
    
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
#include "amq_sequence.h"               //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_sequence_t

//  Shorthands for class methods                                               

#define self_new            amq_sequence_new
#define self_check          amq_sequence_check
#define self_selftest       amq_sequence_selftest
#define self_remove_from_all_containers  amq_sequence_remove_from_all_containers
#define self_show           amq_sequence_show
#define self_terminate      amq_sequence_terminate
#define self_destroy        amq_sequence_destroy
#define self_annihilate     amq_sequence_annihilate
#define self_alloc          amq_sequence_alloc
#define self_free           amq_sequence_free
#define self_cache_initialise  amq_sequence_cache_initialise
#define self_cache_purge    amq_sequence_cache_purge
#define self_cache_terminate  amq_sequence_cache_terminate
#define self_animate        amq_sequence_animate
#define self_new_in_scope   amq_sequence_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_NEW))
static icl_stats_t *s_amq_sequence_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_CHECK))
static icl_stats_t *s_amq_sequence_check_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_SELFTEST))
static icl_stats_t *s_amq_sequence_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_amq_sequence_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_SHOW))
static icl_stats_t *s_amq_sequence_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_TERMINATE))
static icl_stats_t *s_amq_sequence_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_DESTROY_PUBLIC))
static icl_stats_t *s_amq_sequence_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_DESTROY))
static icl_stats_t *s_amq_sequence_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_ALLOC))
static icl_stats_t *s_amq_sequence_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_FREE))
static icl_stats_t *s_amq_sequence_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_CACHE_INITIALISE))
static icl_stats_t *s_amq_sequence_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_CACHE_PURGE))
static icl_stats_t *s_amq_sequence_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_CACHE_TERMINATE))
static icl_stats_t *s_amq_sequence_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_ANIMATE))
static icl_stats_t *s_amq_sequence_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_NEW_IN_SCOPE))
static icl_stats_t *s_amq_sequence_new_in_scope_stats = NULL;
#endif
static void
    amq_sequence_annihilate (
amq_sequence_t * ( * self_p )           //  Reference to object reference
);

#define amq_sequence_alloc()            amq_sequence_alloc_ (__FILE__, __LINE__)
static amq_sequence_t *
    amq_sequence_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_sequence_free (
amq_sequence_t * self                   //  Object reference
);

static void
    amq_sequence_cache_initialise (
void);

static void
    amq_sequence_cache_purge (
void);

static void
    amq_sequence_cache_terminate (
void);

Bool
    amq_sequence_animating = TRUE;      //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    amq_sequence_new

    Type: Component method
    Creates and initialises a new amq_sequence_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

amq_sequence_t *
    amq_sequence_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_sequence_table_t * table,       //  Table to insert into
    char * key,                         //  Hash key
    apr_time_t timestamp                //  Not documented
)
{
    amq_sequence_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_NEW))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_NEW))
    icl_trace_record (NULL, amq_sequence_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_NEW))
    icl_stats_inc ("amq_sequence_new", &s_amq_sequence_new_stats);
#endif

    self = amq_sequence_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_SEQUENCE_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_sequence_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
//
self->timestamp = timestamp;
if (table && self && amq_sequence_table_insert (table, key, self))
    amq_sequence_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_NEW))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_NEW))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_new_finish"
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
    amq_sequence_check

    Type: Component method
    Checks the provided sender id and timestamp, returns 0 if ok, and -1 if
    the timestamp is out of sequence.
    -------------------------------------------------------------------------
 */

int
    amq_sequence_check (
    amq_sequence_table_t * table,       //  Not documented
    char * sender_id,                   //  Not documented
    apr_time_t timestamp                //  Not documented
)
{
amq_sequence_t
    *entry;
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_CHECK))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_check_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" sender_id=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, sender_id);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CHECK))
    icl_trace_record (NULL, amq_sequence_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_CHECK))
    icl_stats_inc ("amq_sequence_check", &s_amq_sequence_check_stats);
#endif

//
entry = amq_sequence_table_search (table, sender_id);
if (entry) {
    if (timestamp < entry->timestamp)
        rc = -1;
}
else
    entry = amq_sequence_new (table, sender_id, timestamp);
entry->timestamp = timestamp;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CHECK))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_CHECK))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_check_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" sender_id=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, sender_id, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_sequence_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_sequence_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_SELFTEST))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_SELFTEST))
    icl_trace_record (NULL, amq_sequence_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_SELFTEST))
    icl_stats_inc ("amq_sequence_selftest", &s_amq_sequence_selftest_stats);
#endif

amq_sequence_table_t
    *sequences;

sequences = amq_sequence_table_new ();
assert (amq_sequence_check (sequences, "sender", 0) == 0);
assert (amq_sequence_check (sequences, "sender", 1) == 0);
assert (amq_sequence_check (sequences, "sender", 0) == -1);
assert (amq_sequence_check (sequences, "sender", 1) == 0);
assert (amq_sequence_check (sequences, "sender", 1) == 0);
amq_sequence_table_destroy (&sequences);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_SELFTEST))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_SELFTEST))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_selftest_finish"
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
    amq_sequence_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_sequence_remove_from_all_containers (
    amq_sequence_t * self               //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_sequence_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("amq_sequence_remove_from_all_containers", &s_amq_sequence_remove_from_all_containers_stats);
#endif

AMQ_SEQUENCE_ASSERT_SANE (self);
amq_sequence_table_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_remove_from_all_containers_finish"
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
    amq_sequence_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_sequence_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_sequence_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_SHOW))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_SHOW))
    icl_trace_record (NULL, amq_sequence_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_SHOW))
    icl_stats_inc ("amq_sequence_show", &s_amq_sequence_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_sequence file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_SHOW))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_SHOW))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_show_finish"
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
    amq_sequence_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_sequence_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_TERMINATE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_TERMINATE))
    icl_trace_record (NULL, amq_sequence_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_TERMINATE))
    icl_stats_inc ("amq_sequence_terminate", &s_amq_sequence_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_TERMINATE))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_TERMINATE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_terminate_finish"
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
    amq_sequence_destroy

    Type: Component method
    Destroys a amq_sequence_t object. Takes the address of a
    amq_sequence_t reference (a pointer to a pointer) and nullifies the
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
    amq_sequence_destroy_ (
    amq_sequence_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_sequence_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_DESTROY_PUBLIC))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_sequence_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_DESTROY_PUBLIC))
    icl_stats_inc ("amq_sequence_destroy", &s_amq_sequence_destroy_stats);
#endif

if (self) {
    amq_sequence_annihilate (self_p);
    amq_sequence_free ((amq_sequence_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_DESTROY_PUBLIC))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_destroy_public_finish"
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
    amq_sequence_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_sequence_annihilate (
    amq_sequence_t * ( * self_p )       //  Reference to object reference
)
{

    amq_sequence_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_DESTROY))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_DESTROY))
    icl_trace_record (NULL, amq_sequence_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_DESTROY))
    icl_stats_inc ("amq_sequence_annihilate", &s_amq_sequence_annihilate_stats);
#endif

AMQ_SEQUENCE_ASSERT_SANE (self);
amq_sequence_remove_from_all_containers (self);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_DESTROY))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_DESTROY))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_destroy_finish"
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
    amq_sequence_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_sequence_t *
    amq_sequence_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_sequence_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_ALLOC))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_ALLOC))
    icl_trace_record (NULL, amq_sequence_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_ALLOC))
    icl_stats_inc ("amq_sequence_alloc", &s_amq_sequence_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_sequence_cache_initialise ();

self = (amq_sequence_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_sequence_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_ALLOC))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_ALLOC))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_alloc_finish"
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
    amq_sequence_free

    Type: Component method
    Freess a amq_sequence_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_sequence_free (
    amq_sequence_t * self               //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_FREE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_FREE))
    icl_trace_record (NULL, amq_sequence_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_FREE))
    icl_stats_inc ("amq_sequence_free", &s_amq_sequence_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (amq_sequence_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_sequence_t));
        self->object_tag = AMQ_SEQUENCE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_FREE))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_FREE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_free_finish"
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
    amq_sequence_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_sequence_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_CACHE_INITIALISE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_sequence_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_CACHE_INITIALISE))
    icl_stats_inc ("amq_sequence_cache_initialise", &s_amq_sequence_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_sequence_t));
icl_system_register (amq_sequence_cache_purge, amq_sequence_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_CACHE_INITIALISE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_cache_initialise_finish"
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
    amq_sequence_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_sequence_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_CACHE_PURGE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_PURGE))
    icl_trace_record (NULL, amq_sequence_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_CACHE_PURGE))
    icl_stats_inc ("amq_sequence_cache_purge", &s_amq_sequence_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_PURGE))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_CACHE_PURGE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_cache_purge_finish"
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
    amq_sequence_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_sequence_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_CACHE_TERMINATE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_sequence_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_CACHE_TERMINATE))
    icl_stats_inc ("amq_sequence_cache_terminate", &s_amq_sequence_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_CACHE_TERMINATE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_cache_terminate_finish"
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
    amq_sequence_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_sequence_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_ANIMATE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_ANIMATE))
    icl_trace_record (NULL, amq_sequence_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_ANIMATE))
    icl_stats_inc ("amq_sequence_animate", &s_amq_sequence_animate_stats);
#endif

amq_sequence_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_ANIMATE))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_ANIMATE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_animate_finish"
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
    amq_sequence_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_sequence_new_in_scope_ (
    amq_sequence_t * * self_p,          //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_sequence_table_t * table,       //  Table to insert into
    char * key,                         //  Hash key
    apr_time_t timestamp                //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE)  ||  defined (BASE_ANIMATE_AMQ_SEQUENCE_NEW_IN_SCOPE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_sequence_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SEQUENCE)  ||  defined (BASE_STATS_AMQ_SEQUENCE_NEW_IN_SCOPE))
    icl_stats_inc ("amq_sequence_new_in_scope", &s_amq_sequence_new_in_scope_stats);
#endif

*self_p = amq_sequence_new_ (file,line,table,key,timestamp);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_sequence_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_sequence_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE)   || defined (BASE_ANIMATE_AMQ_SEQUENCE_NEW_IN_SCOPE))
    if (amq_sequence_animating)
        icl_console_print ("<amq_sequence_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_NEW)   || defined (BASE_TRACE_AMQ_SEQUENCE_CHECK)   || defined (BASE_TRACE_AMQ_SEQUENCE_SELFTEST)   || defined (BASE_TRACE_AMQ_SEQUENCE_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_SEQUENCE_SHOW)   || defined (BASE_TRACE_AMQ_SEQUENCE_TERMINATE)   || defined (BASE_TRACE_AMQ_SEQUENCE_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_SEQUENCE_DESTROY)   || defined (BASE_TRACE_AMQ_SEQUENCE_ALLOC)   || defined (BASE_TRACE_AMQ_SEQUENCE_FREE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_SEQUENCE_ANIMATE)   || defined (BASE_TRACE_AMQ_SEQUENCE_NEW_IN_SCOPE) )
void
amq_sequence_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "check"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "remove from all containers"; break;
        case 5: method_name = "show"; break;
        case 6: method_name = "terminate"; break;
        case 7: method_name = "destroy public"; break;
        case 8: method_name = "destroy"; break;
        case 9: method_name = "alloc"; break;
        case 10: method_name = "free"; break;
        case 11: method_name = "cache initialise"; break;
        case 12: method_name = "cache purge"; break;
        case 13: method_name = "cache terminate"; break;
        case 14: method_name = "animate"; break;
        case 15: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_sequence %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_sequence_version_start   = "VeRsIoNsTaRt:ipc";
char *amq_sequence_component       = "amq_sequence ";
char *amq_sequence_version         = "1.0 ";
char *amq_sequence_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_sequence_filename        = "amq_sequence.icl ";
char *amq_sequence_builddate       = "2010/10/06 ";
char *amq_sequence_version_end     = "VeRsIoNeNd:ipc";

