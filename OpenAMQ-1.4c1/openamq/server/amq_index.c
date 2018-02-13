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
#define self_show_animation  amq_index_show_animation
#define self_new_in_scope   amq_index_new_in_scope

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

count = (int) s_amq_index_count;

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

AMQ_INDEX_ASSERT_SANE (self);
amq_index_hash_remove (self);
amq_index_array_remove (self);
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

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_index_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("amq_index", "E: missing link on amq_index object");
        amq_index_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_index_free_ ((amq_index_t *) self, file, line);
    *self_p = NULL;
}
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

//  Initialise cache if necessary
if (!s_cache)
    amq_index_cache_initialise ();

self = (amq_index_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_index_t));



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

    if (self) {
        AMQ_INDEX_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("amq_index", "E: missing link on amq_index object");
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

s_cache = icl_cache_get (sizeof (amq_index_t));
icl_system_register (amq_index_cache_purge, amq_index_cache_terminate);
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

icl_mem_cache_purge (s_cache);

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

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_index_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_index_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_index_animating = enabled;
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

*self_p = amq_index_new_ (file,line,table,key,array);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_index_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_index_version_start      = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_index_component          = "amq_index ";
char *EMBED__amq_index_version            = "1.0 ";
char *EMBED__amq_index_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_index_filename           = "amq_index.icl ";
char *EMBED__amq_index_builddate          = "2010/10/06 ";
char *EMBED__amq_index_version_end        = "VeRsIoNeNd:ipc";

