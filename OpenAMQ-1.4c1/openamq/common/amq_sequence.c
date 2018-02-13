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
#define self_show_animation  amq_sequence_show_animation
#define self_new_in_scope   amq_sequence_new_in_scope

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

//
entry = amq_sequence_table_search (table, sender_id);
if (entry) {
    if (timestamp < entry->timestamp)
        rc = -1;
}
else
    entry = amq_sequence_new (table, sender_id, timestamp);
entry->timestamp = timestamp;

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

amq_sequence_table_t
    *sequences;

sequences = amq_sequence_table_new ();
assert (amq_sequence_check (sequences, "sender", 0) == 0);
assert (amq_sequence_check (sequences, "sender", 1) == 0);
assert (amq_sequence_check (sequences, "sender", 0) == -1);
assert (amq_sequence_check (sequences, "sender", 1) == 0);
assert (amq_sequence_check (sequences, "sender", 1) == 0);
amq_sequence_table_destroy (&sequences);
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

AMQ_SEQUENCE_ASSERT_SANE (self);
amq_sequence_table_remove (self);
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


self = item;
container_links = 0;
if (self->table_head)
   container_links++;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_sequence file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

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

if (self) {
    amq_sequence_annihilate (self_p);
    amq_sequence_free ((amq_sequence_t *) self);
    *self_p = NULL;
}
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

AMQ_SEQUENCE_ASSERT_SANE (self);
amq_sequence_remove_from_all_containers (self);


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

//  Initialise cache if necessary
if (!s_cache)
    amq_sequence_cache_initialise ();

self = (amq_sequence_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_sequence_t));



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


if (self) {

        memset (&self->object_tag, 0, sizeof (amq_sequence_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_sequence_t));
        self->object_tag = AMQ_SEQUENCE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
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

s_cache = icl_cache_get (sizeof (amq_sequence_t));
icl_system_register (amq_sequence_cache_purge, amq_sequence_cache_terminate);
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

icl_mem_cache_purge (s_cache);

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

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_sequence_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_sequence_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_sequence_animating = enabled;
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

*self_p = amq_sequence_new_ (file,line,table,key,timestamp);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_sequence_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_sequence_version_start   = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_sequence_component       = "amq_sequence ";
char *EMBED__amq_sequence_version         = "1.0 ";
char *EMBED__amq_sequence_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_sequence_filename        = "amq_sequence.icl ";
char *EMBED__amq_sequence_builddate       = "2010/10/06 ";
char *EMBED__amq_sequence_version_end     = "VeRsIoNeNd:ipc";

