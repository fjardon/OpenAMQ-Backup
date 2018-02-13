/*---------------------------------------------------------------------------
    demo_queue_table.c - demo_queue_table component

    This class implements the hash table container for demo_queue
    Generated from demo_queue_table.icl by icl_gen using GSL/4.
    
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
#include "demo_queue_table.h"           //  Definitions for our class

//  Shorthand for class type

#define self_t              demo_queue_table_t

//  Shorthands for class methods

#define self_new            demo_queue_table_new
#define self_annihilate     demo_queue_table_annihilate
#define self_selftest       demo_queue_table_selftest
#define self_insert         demo_queue_table_insert
#define self_remove         demo_queue_table_remove
#define self_search         demo_queue_table_search
#define self_apply          demo_queue_table_apply
#define self_terminate      demo_queue_table_terminate
#define self_show           demo_queue_table_show
#define self_destroy        demo_queue_table_destroy
#define self_alloc          demo_queue_table_alloc
#define self_free           demo_queue_table_free
#define self_read_lock      demo_queue_table_read_lock
#define self_write_lock     demo_queue_table_write_lock
#define self_unlock         demo_queue_table_unlock
#define self_link           demo_queue_table_link
#define self_unlink         demo_queue_table_unlink
#define self_cache_initialise  demo_queue_table_cache_initialise
#define self_cache_purge    demo_queue_table_cache_purge
#define self_cache_terminate  demo_queue_table_cache_terminate
#define self_show_animation  demo_queue_table_show_animation
#define self_new_in_scope   demo_queue_table_new_in_scope

#define demo_queue_table_annihilate(self)  demo_queue_table_annihilate_ (self, __FILE__, __LINE__)
static void
    demo_queue_table_annihilate_ (
demo_queue_table_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define demo_queue_table_alloc()        demo_queue_table_alloc_ (__FILE__, __LINE__)
static demo_queue_table_t *
    demo_queue_table_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define demo_queue_table_free(self)     demo_queue_table_free_ (self, __FILE__, __LINE__)
static void
    demo_queue_table_free_ (
demo_queue_table_t * self,              //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    demo_queue_table_cache_initialise (
void);

static void
    demo_queue_table_cache_purge (
void);

static void
    demo_queue_table_cache_terminate (
void);

Bool
    demo_queue_table_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


//  Hash support functions
static inline unsigned int
    s_key_hash (char * key, size_t hash_size);
static inline Bool
    s_key_equal (char * key1, char * key2);

//  Table functions to be called once locks are in place
static int
    s_demo_queue_table_insert (demo_queue_table_t *self, demo_queue_t *item, char * key);
static demo_queue_t *
    s_demo_queue_table_lookup (demo_queue_table_t *self, char * key);
static void
    s_demo_queue_table_remove (demo_queue_t *item);
static void
    s_demo_queue_table_purge (demo_queue_table_t *self);
/*  -------------------------------------------------------------------------
    demo_queue_table_new

    Type: Component method
    Creates and initialises a new demo_queue_table_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

demo_queue_table_t *
    demo_queue_table_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    demo_queue_table_t *
        self = NULL;                    //  Object reference

    self = demo_queue_table_alloc_ (file, line);
    if (self) {
        self->object_tag   = DEMO_QUEUE_TABLE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_QUEUE_TABLE)
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
        icl_mem_set_callback (self, demo_queue_table_show_);
#endif

self->max_items = DEMO_QUEUE_TABLE_INITIAL_SIZE;
self->table_items = icl_mem_alloc (sizeof (demo_queue_t*) *
    DEMO_QUEUE_TABLE_INITIAL_SIZE);
assert (self->table_items);
memset (self->table_items, 0, sizeof (demo_queue_t*) *
    DEMO_QUEUE_TABLE_INITIAL_SIZE);
}

    return (self);
}
/*  -------------------------------------------------------------------------
    demo_queue_table_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_queue_table_annihilate_ (
    demo_queue_table_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_QUEUE_TABLE)
    int
        history_last;
#endif

    demo_queue_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_QUEUE_TABLE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = self->links;
#endif

    DEMO_QUEUE_TABLE_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

s_demo_queue_table_purge (self);
if (self->table_items)
    icl_mem_free (self->table_items);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

}
/*  -------------------------------------------------------------------------
    demo_queue_table_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_queue_table_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    demo_queue_table_insert

    Type: Component method
    Accepts a demo_queue_table_t reference and returns zero in case of success,
    1 in case of errors.
    Insert a new item into the hash table if possible. If successful,
    the number of links to the item is automatically incremented.
    Trying to insert a duplicate key will result in nothing being inserted.
    -------------------------------------------------------------------------
 */

int
    demo_queue_table_insert (
    demo_queue_table_t * self,          //  Reference to object
    char * key,                         //  Hash key
    demo_queue_t * item                 //  Item to insert
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

DEMO_QUEUE_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

//
if (item->table_head) {
    if (item->table_head != self) {
        icl_console_print ("E: demo_queue item inserted into multiple table containers");
        assert (item->table_head == self);
    }
    s_demo_queue_table_remove (item);
    demo_queue_unlink (&item);
}
rc = s_demo_queue_table_insert (self, item, key);
if (item->table_head)
    demo_queue_link (item);

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
    demo_queue_table_remove

    Type: Component method
    Remove an item from a hash table.  If the item was not in any hash
    table, this function does nothing.
    -------------------------------------------------------------------------
 */

int
    demo_queue_table_remove (
    demo_queue_t * item                 //  Item to remove
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    demo_queue_table_t *
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
    s_demo_queue_table_remove (item);
    demo_queue_unlink (&item);
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_queue_table_search

    Type: Component method
    Find object by key in the hash table. Returns reference to object
    if found, else null.
    -------------------------------------------------------------------------
 */

demo_queue_t *
    demo_queue_table_search (
    demo_queue_table_t * self,          //  Table to search
    char * key                          //  Hash key
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    demo_queue_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

//
DEMO_QUEUE_TABLE_ASSERT_SANE (self);
if (key)
    item = s_demo_queue_table_lookup (self, key);
if (item)
    demo_queue_link (item);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    demo_queue_table_apply

    Type: Component method
    This method iterates through all the items in the hash and calls the
    callback function for each of them.
    -------------------------------------------------------------------------
 */

void
    demo_queue_table_apply (
    demo_queue_table_t * self,          //  Table to iterate
    demo_queue_table_callback_fn * callback,   //  Not documented
    void * argument                     //  Arbitrary argument pointer
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

size_t
    pos;
demo_queue_t
    *item;

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

//
DEMO_QUEUE_TABLE_ASSERT_SANE (self);
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
    demo_queue_table_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_queue_table_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    demo_queue_table_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_queue_table_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    demo_queue_table_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_QUEUE_TABLE)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <demo_queue_table zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_QUEUE_TABLE)
    if (self->history_last > DEMO_QUEUE_TABLE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % DEMO_QUEUE_TABLE_HISTORY_LENGTH;
        self->history_last %= DEMO_QUEUE_TABLE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % DEMO_QUEUE_TABLE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </demo_queue_table>\n");
#endif

}
/*  -------------------------------------------------------------------------
    demo_queue_table_destroy

    Type: Component method
    Destroys a demo_queue_table_t object. Takes the address of a
    demo_queue_table_t reference (a pointer to a pointer) and nullifies the
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
    demo_queue_table_destroy_ (
    demo_queue_table_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    demo_queue_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        demo_queue_table_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("demo_queue_table", "E: missing link on demo_queue_table object");
        demo_queue_table_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        demo_queue_table_free_ ((demo_queue_table_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    demo_queue_table_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static demo_queue_table_t *
    demo_queue_table_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    demo_queue_table_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    demo_queue_table_cache_initialise ();

self = (demo_queue_table_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (demo_queue_table_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    demo_queue_table_free

    Type: Component method
    Freess a demo_queue_table_t object.
    -------------------------------------------------------------------------
 */

static void
    demo_queue_table_free_ (
    demo_queue_table_t * self,          //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_QUEUE_TABLE)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_QUEUE_TABLE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (demo_queue_table_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (demo_queue_table_t));
        self->object_tag = DEMO_QUEUE_TABLE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    demo_queue_table_read_lock

    Type: Component method
    Accepts a demo_queue_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_queue_table_read_lock (
    demo_queue_table_t * self           //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

DEMO_QUEUE_TABLE_ASSERT_SANE (self);
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
    demo_queue_table_write_lock

    Type: Component method
    Accepts a demo_queue_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_queue_table_write_lock (
    demo_queue_table_t * self           //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

DEMO_QUEUE_TABLE_ASSERT_SANE (self);
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
    demo_queue_table_unlock

    Type: Component method
    Accepts a demo_queue_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_queue_table_unlock (
    demo_queue_table_t * self           //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

DEMO_QUEUE_TABLE_ASSERT_SANE (self);
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
    demo_queue_table_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

demo_queue_table_t *
    demo_queue_table_link_ (
    demo_queue_table_t * self,          //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_QUEUE_TABLE)
    int
        history_last;
#endif

    if (self) {
        DEMO_QUEUE_TABLE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_QUEUE_TABLE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    demo_queue_table_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    demo_queue_table_unlink_ (
    demo_queue_table_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_QUEUE_TABLE)
    int
        history_last;
#endif

    demo_queue_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        DEMO_QUEUE_TABLE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("demo_queue_table", "E: missing link on demo_queue_table object");
            demo_queue_table_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_QUEUE_TABLE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % DEMO_QUEUE_TABLE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            demo_queue_table_annihilate_ (self_p, file, line);
        demo_queue_table_free_ ((demo_queue_table_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    demo_queue_table_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    demo_queue_table_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (demo_queue_table_t));
icl_system_register (demo_queue_table_cache_purge, demo_queue_table_cache_terminate);
}
/*  -------------------------------------------------------------------------
    demo_queue_table_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_queue_table_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    demo_queue_table_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_queue_table_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    demo_queue_table_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    demo_queue_table_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

demo_queue_table_animating = enabled;
}
/*  -------------------------------------------------------------------------
    demo_queue_table_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_queue_table_new_in_scope_ (
    demo_queue_table_t * * self_p,      //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = demo_queue_table_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) demo_queue_table_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
static inline unsigned int
s_key_hash (char * key, size_t hash_size)
{
    uint
        key_hash = 0;

    //  Torek hashing function
    while (*key) {
        key_hash *= 33;
        key_hash += *key;
        key++;
    }
    key_hash %= hash_size;
    return (key_hash);
}

static inline Bool
s_key_equal (char * key1, char * key2)
{
    return (streq (key1, key2));
}

static int
s_demo_queue_table_insert (demo_queue_table_t *self, demo_queue_t *item, char * key)
{
    qbyte
        index,
        new_index;
    demo_queue_t
        *current_item,
        *next_item;
    int
        rc = 0;

    if (self->nbr_items >= self->max_items * DEMO_QUEUE_TABLE_LOAD_FACTOR / 100) {

        //  Load factor of hash table was exceeded
        //  We need to increase its size by GROWTH_FACTOR and rebuild it
        demo_queue_t
            **new_items;
        size_t
            new_max_items;

        //  Create new hash table
        new_max_items = self->max_items * DEMO_QUEUE_TABLE_GROWTH_FACTOR / 100;
        new_items = icl_mem_alloc (sizeof (demo_queue_t*) * new_max_items);
        assert (new_items);
        memset (new_items, 0, sizeof (demo_queue_t*) * new_max_items);

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
        icl_shortstr_cpy (item->key, key);
        self->nbr_items++;
    }
    return rc;
}

static demo_queue_t *
s_demo_queue_table_lookup (demo_queue_table_t *self, char * key)
{
    qbyte
        index;
    demo_queue_t
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
s_demo_queue_table_remove (demo_queue_t *item)
{
    demo_queue_t
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
        icl_shortstr_cpy (item->key, "");
    }
}

static void
s_demo_queue_table_purge (demo_queue_table_t *self)
{
    uint
        table_idx;
    demo_queue_t
        *current_item,
        *next_item;

    for (table_idx = 0; table_idx < self->max_items; table_idx++) {
        current_item = self->table_items [table_idx];
        while (current_item) {
            next_item = current_item->table_next;
            s_demo_queue_table_remove (current_item);
            demo_queue_unlink (&current_item);
            current_item = next_item;
        }
    }
}

//  Embed the version information in the resulting binary

char *EMBED__demo_queue_table_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__demo_queue_table_component   = "demo_queue_table ";
char *EMBED__demo_queue_table_version     = "1.0 ";
char *EMBED__demo_queue_table_copyright   = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__demo_queue_table_filename    = "demo_queue_table.icl ";
char *EMBED__demo_queue_table_builddate   = "2010/10/06 ";
char *EMBED__demo_queue_table_version_end  = "VeRsIoNeNd:ipc";

