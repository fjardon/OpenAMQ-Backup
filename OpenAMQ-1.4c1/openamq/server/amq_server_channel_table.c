/*---------------------------------------------------------------------------
    amq_server_channel_table.c - amq_server_channel_table component

    This class implements the hash table container for amq_server_channel
    Generated from amq_server_channel_table.icl by icl_gen using GSL/4.
    
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
#include "amq_server_channel_table.h"   //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_server_channel_table_t

//  Shorthands for class methods

#define self_new            amq_server_channel_table_new
#define self_annihilate     amq_server_channel_table_annihilate
#define self_selftest       amq_server_channel_table_selftest
#define self_insert         amq_server_channel_table_insert
#define self_remove         amq_server_channel_table_remove
#define self_search         amq_server_channel_table_search
#define self_apply          amq_server_channel_table_apply
#define self_terminate      amq_server_channel_table_terminate
#define self_show           amq_server_channel_table_show
#define self_destroy        amq_server_channel_table_destroy
#define self_alloc          amq_server_channel_table_alloc
#define self_free           amq_server_channel_table_free
#define self_read_lock      amq_server_channel_table_read_lock
#define self_write_lock     amq_server_channel_table_write_lock
#define self_unlock         amq_server_channel_table_unlock
#define self_link           amq_server_channel_table_link
#define self_unlink         amq_server_channel_table_unlink
#define self_cache_initialise  amq_server_channel_table_cache_initialise
#define self_cache_purge    amq_server_channel_table_cache_purge
#define self_cache_terminate  amq_server_channel_table_cache_terminate
#define self_show_animation  amq_server_channel_table_show_animation
#define self_new_in_scope   amq_server_channel_table_new_in_scope

#define amq_server_channel_table_annihilate(self)  amq_server_channel_table_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_server_channel_table_annihilate_ (
amq_server_channel_table_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_server_channel_table_alloc()  amq_server_channel_table_alloc_ (__FILE__, __LINE__)
static amq_server_channel_table_t *
    amq_server_channel_table_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_server_channel_table_free(self)  amq_server_channel_table_free_ (self, __FILE__, __LINE__)
static void
    amq_server_channel_table_free_ (
amq_server_channel_table_t * self,      //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_server_channel_table_cache_initialise (
void);

static void
    amq_server_channel_table_cache_purge (
void);

static void
    amq_server_channel_table_cache_terminate (
void);

Bool
    amq_server_channel_table_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


//  Hash support functions
static inline unsigned int
    s_key_hash (int key, size_t hash_size);
static inline Bool
    s_key_equal (int key1, int key2);

//  Table functions to be called once locks are in place
static int
    s_amq_server_channel_table_insert (amq_server_channel_table_t *self, amq_server_channel_t *item, int key);
static amq_server_channel_t *
    s_amq_server_channel_table_lookup (amq_server_channel_table_t *self, int key);
static void
    s_amq_server_channel_table_remove (amq_server_channel_t *item);
static void
    s_amq_server_channel_table_purge (amq_server_channel_table_t *self);
/*  -------------------------------------------------------------------------
    amq_server_channel_table_new

    Type: Component method
    Creates and initialises a new amq_server_channel_table_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_server_channel_table_t *
    amq_server_channel_table_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_server_channel_table_t *
        self = NULL;                    //  Object reference

    self = amq_server_channel_table_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_SERVER_CHANNEL_TABLE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
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
        icl_mem_set_callback (self, amq_server_channel_table_show_);
#endif

self->max_items = AMQ_SERVER_CHANNEL_TABLE_INITIAL_SIZE;
self->table_items = icl_mem_alloc (sizeof (amq_server_channel_t*) *
    AMQ_SERVER_CHANNEL_TABLE_INITIAL_SIZE);
assert (self->table_items);
memset (self->table_items, 0, sizeof (amq_server_channel_t*) *
    AMQ_SERVER_CHANNEL_TABLE_INITIAL_SIZE);
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_channel_table_annihilate_ (
    amq_server_channel_table_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
    int
        history_last;
#endif

    amq_server_channel_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = self->links;
#endif

    AMQ_SERVER_CHANNEL_TABLE_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

s_amq_server_channel_table_purge (self);
if (self->table_items)
    icl_mem_free (self->table_items);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_table_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_insert

    Type: Component method
    Accepts a amq_server_channel_table_t reference and returns zero in case of success,
    1 in case of errors.
    Insert a new item into the hash table if possible. If successful,
    the number of links to the item is automatically incremented.
    Trying to insert a duplicate key will result in nothing being inserted.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_table_insert (
    amq_server_channel_table_t * self,   //  Reference to object
    int key,                            //  Hash key
    amq_server_channel_t * item         //  Item to insert
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CHANNEL_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

//
if (item->table_head) {
    if (item->table_head != self) {
        icl_console_print ("E: amq_server_channel item inserted into multiple table containers");
        assert (item->table_head == self);
    }
    s_amq_server_channel_table_remove (item);
    amq_server_channel_unlink (&item);
}
rc = s_amq_server_channel_table_insert (self, item, key);
if (item->table_head)
    amq_server_channel_link (item);

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_remove

    Type: Component method
    Remove an item from a hash table.  If the item was not in any hash
    table, this function does nothing.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_table_remove (
    amq_server_channel_t * item         //  Item to remove
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_server_channel_table_t *
        self = item->table_head;        //  The list
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

if (self
&&  self == item->table_head) { //      Catch case where item moved
    s_amq_server_channel_table_remove (item);
    amq_server_channel_unlink (&item);
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_search

    Type: Component method
    Find object by key in the hash table. Returns reference to object
    if found, else null.
    -------------------------------------------------------------------------
 */

amq_server_channel_t *
    amq_server_channel_table_search (
    amq_server_channel_table_t * self,   //  Table to search
    int key                             //  Hash key
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_server_channel_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

//
AMQ_SERVER_CHANNEL_TABLE_ASSERT_SANE (self);
if (key)
    item = s_amq_server_channel_table_lookup (self, key);
if (item)
    amq_server_channel_link (item);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_apply

    Type: Component method
    This method iterates through all the items in the hash and calls the
    callback function for each of them.
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_table_apply (
    amq_server_channel_table_t * self,   //  Table to iterate
    amq_server_channel_table_callback_fn * callback,   //  Not documented
    void * argument                     //  Arbitrary argument pointer
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

size_t
    pos;
amq_server_channel_t
    *item;

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

//
AMQ_SERVER_CHANNEL_TABLE_ASSERT_SANE (self);
for (pos = 0; pos != self->max_items; pos ++) {
    item = self->table_items [pos];
    while (item) {
        callback (item, argument);
        item = item->table_next;
    }
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_table_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_table_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_server_channel_table_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_server_channel_table zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
    if (self->history_last > AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH;
        self->history_last %= AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_server_channel_table>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_destroy

    Type: Component method
    Destroys a amq_server_channel_table_t object. Takes the address of a
    amq_server_channel_table_t reference (a pointer to a pointer) and nullifies the
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
    amq_server_channel_table_destroy_ (
    amq_server_channel_table_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_server_channel_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_server_channel_table_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("amq_server_channel_table", "E: missing link on amq_server_channel_table object");
        amq_server_channel_table_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_server_channel_table_free_ ((amq_server_channel_table_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_server_channel_table_t *
    amq_server_channel_table_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_server_channel_table_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_server_channel_table_cache_initialise ();

self = (amq_server_channel_table_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_server_channel_table_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_free

    Type: Component method
    Freess a amq_server_channel_table_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_server_channel_table_free_ (
    amq_server_channel_table_t * self,   //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (amq_server_channel_table_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_server_channel_table_t));
        self->object_tag = AMQ_SERVER_CHANNEL_TABLE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_read_lock

    Type: Component method
    Accepts a amq_server_channel_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_table_read_lock (
    amq_server_channel_table_t * self   //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_SERVER_CHANNEL_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_write_lock

    Type: Component method
    Accepts a amq_server_channel_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_table_write_lock (
    amq_server_channel_table_t * self   //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_SERVER_CHANNEL_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_unlock

    Type: Component method
    Accepts a amq_server_channel_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_table_unlock (
    amq_server_channel_table_t * self   //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_SERVER_CHANNEL_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_server_channel_table_t *
    amq_server_channel_table_link_ (
    amq_server_channel_table_t * self,   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
    int
        history_last;
#endif

    if (self) {
        AMQ_SERVER_CHANNEL_TABLE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_table_unlink_ (
    amq_server_channel_table_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
    int
        history_last;
#endif

    amq_server_channel_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        AMQ_SERVER_CHANNEL_TABLE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("amq_server_channel_table", "E: missing link on amq_server_channel_table object");
            amq_server_channel_table_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_server_channel_table_annihilate_ (self_p, file, line);
        amq_server_channel_table_free_ ((amq_server_channel_table_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_server_channel_table_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_server_channel_table_t));
icl_system_register (amq_server_channel_table_cache_purge, amq_server_channel_table_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_channel_table_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_channel_table_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_table_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_server_channel_table_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_server_channel_table_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_table_new_in_scope_ (
    amq_server_channel_table_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_server_channel_table_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_server_channel_table_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
static inline unsigned int
s_key_hash (int key, size_t hash_size)
{
    return ((uint) (((size_t) key) % hash_size));
}

static inline Bool
s_key_equal (int key1, int key2)
{
    return (key1 == key2);
}

static int
s_amq_server_channel_table_insert (amq_server_channel_table_t *self, amq_server_channel_t *item, int key)
{
    qbyte
        index,
        new_index;
    amq_server_channel_t
        *current_item,
        *next_item;
    int
        rc = 0;

    if (self->nbr_items >= self->max_items * AMQ_SERVER_CHANNEL_TABLE_LOAD_FACTOR / 100) {

        //  Load factor of hash table was exceeded
        //  We need to increase its size by GROWTH_FACTOR and rebuild it
        amq_server_channel_t
            **new_items;
        size_t
            new_max_items;

        //  Create new hash table
        new_max_items = self->max_items * AMQ_SERVER_CHANNEL_TABLE_GROWTH_FACTOR / 100;
        new_items = icl_mem_alloc (sizeof (amq_server_channel_t*) * new_max_items);
        assert (new_items);
        memset (new_items, 0, sizeof (amq_server_channel_t*) * new_max_items);

        //  Move all items to the new hash table
        for (index = 0; index != self->max_items; index++) {
            current_item = self->table_items [index];
            while (current_item) {
                next_item = current_item->table_next;
                new_index = s_key_hash (current_item->key, new_max_items);
                current_item->table_index = new_index;
                current_item->table_next = new_items [new_index];
                new_items [new_index] = current_item;
                current_item = next_item;
            }
        }

        //  Destroy old hash table
        icl_mem_free (self->table_items);
        self->table_items = new_items;
        self->max_items = new_max_items;
    }

    //  Insert new item itself
    index = s_key_hash (key, self->max_items);
    current_item = self->table_items [index];
    while (current_item) {
        if (s_key_equal (current_item->key, key)) {
            //  Attempted duplicate insertion
            rc = -1;
            break;
        }
        current_item = current_item->table_next;
    }
    if (!current_item) {
        item->table_head = self;
        item->table_index = index;
        item->table_next = self->table_items [index];
        self->table_items [index] = item;
        item->key = key;
        self->nbr_items++;
    }
    return rc;
}

static amq_server_channel_t *
s_amq_server_channel_table_lookup (amq_server_channel_table_t *self, int key)
{
    qbyte
        index;
    amq_server_channel_t
        *item;

    index = s_key_hash (key, self->max_items);
    item = self->table_items [index];

    while (item) {
        if (s_key_equal (item->key, key))
            break;
        item = item->table_next;
    }
    return item;
}

static void
s_amq_server_channel_table_remove (amq_server_channel_t *item)
{
    amq_server_channel_t
        *current_item,
        **prev_item;

    prev_item = &(item->table_head->table_items [item->table_index]);
    current_item = item->table_head->table_items [item->table_index];

    while (current_item) {
        if (current_item == item)
            break;
        prev_item = &(current_item->table_next);
        current_item = current_item->table_next;
    }
    assert (current_item == item);

    if (item) {
        item->table_head->nbr_items--;
        *prev_item = item->table_next;
        item->table_head = NULL;
        item->table_index = 0;
        item->table_next = NULL;
        item->key = 0;
    }
}

static void
s_amq_server_channel_table_purge (amq_server_channel_table_t *self)
{
    uint
        table_idx;
    amq_server_channel_t
        *current_item,
        *next_item;

    for (table_idx = 0; table_idx < self->max_items; table_idx++) {
        current_item = self->table_items [table_idx];
        while (current_item) {
            next_item = current_item->table_next;
            s_amq_server_channel_table_remove (current_item);
            amq_server_channel_unlink (&current_item);
            current_item = next_item;
        }
    }
}

//  Embed the version information in the resulting binary

char *EMBED__amq_server_channel_table_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_server_channel_table_component  = "amq_server_channel_table ";
char *EMBED__amq_server_channel_table_version  = "1.0 ";
char *EMBED__amq_server_channel_table_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_server_channel_table_filename  = "amq_server_channel_table.icl ";
char *EMBED__amq_server_channel_table_builddate  = "2010/10/06 ";
char *EMBED__amq_server_channel_table_version_end  = "VeRsIoNeNd:ipc";

