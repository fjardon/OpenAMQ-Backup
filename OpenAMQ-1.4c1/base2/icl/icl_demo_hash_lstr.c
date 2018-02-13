/*---------------------------------------------------------------------------
    icl_demo_hash_lstr.c - icl_demo_hash_lstr component

    Generated from icl_demo_hash_lstr.icl by icl_gen using GSL/4.
    
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
#include "icl_demo_hash_lstr.h"         //  Definitions for our class

//  Shorthand for class type

#define self_t              icl_demo_hash_lstr_t

//  Shorthands for class methods

#define self_new            icl_demo_hash_lstr_new
#define self_annihilate     icl_demo_hash_lstr_annihilate
#define self_selftest       icl_demo_hash_lstr_selftest
#define self_remove_from_all_containers  icl_demo_hash_lstr_remove_from_all_containers
#define self_show           icl_demo_hash_lstr_show
#define self_terminate      icl_demo_hash_lstr_terminate
#define self_destroy        icl_demo_hash_lstr_destroy
#define self_alloc          icl_demo_hash_lstr_alloc
#define self_free           icl_demo_hash_lstr_free
#define self_read_lock      icl_demo_hash_lstr_read_lock
#define self_write_lock     icl_demo_hash_lstr_write_lock
#define self_unlock         icl_demo_hash_lstr_unlock
#define self_link           icl_demo_hash_lstr_link
#define self_unlink         icl_demo_hash_lstr_unlink
#define self_cache_initialise  icl_demo_hash_lstr_cache_initialise
#define self_cache_purge    icl_demo_hash_lstr_cache_purge
#define self_cache_terminate  icl_demo_hash_lstr_cache_terminate
#define self_show_animation  icl_demo_hash_lstr_show_animation
#define self_new_in_scope   icl_demo_hash_lstr_new_in_scope

#define icl_demo_hash_lstr_annihilate(self)  icl_demo_hash_lstr_annihilate_ (self, __FILE__, __LINE__)
static void
    icl_demo_hash_lstr_annihilate_ (
icl_demo_hash_lstr_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define icl_demo_hash_lstr_alloc()      icl_demo_hash_lstr_alloc_ (__FILE__, __LINE__)
static icl_demo_hash_lstr_t *
    icl_demo_hash_lstr_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_demo_hash_lstr_free(self)   icl_demo_hash_lstr_free_ (self, __FILE__, __LINE__)
static void
    icl_demo_hash_lstr_free_ (
icl_demo_hash_lstr_t * self,            //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    icl_demo_hash_lstr_cache_initialise (
void);

static void
    icl_demo_hash_lstr_cache_purge (
void);

static void
    icl_demo_hash_lstr_cache_terminate (
void);

Bool
    icl_demo_hash_lstr_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_new

    Type: Component method
    Creates and initialises a new icl_demo_hash_lstr_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

icl_demo_hash_lstr_t *
    icl_demo_hash_lstr_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    icl_demo_hash_lstr_table_t * table,   //  Table to insert into
    char * key,                         //  Hash key
    char * name,                        //  Not documented
    char * address                      //  Not documented
)
{
    icl_demo_hash_lstr_t *
        self = NULL;                    //  Object reference

    self = icl_demo_hash_lstr_alloc_ (file, line);
    if (self) {
        self->object_tag   = ICL_DEMO_HASH_LSTR_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_LSTR)
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
        icl_mem_set_callback (self, icl_demo_hash_lstr_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->name    = icl_mem_strdup (name);
self->address = icl_mem_strdup (address);
if (table && self && icl_demo_hash_lstr_table_insert (table, key, self))
    icl_demo_hash_lstr_destroy (&self);
}

    return (self);
}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_hash_lstr_annihilate_ (
    icl_demo_hash_lstr_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_LSTR)
    int
        history_last;
#endif

    icl_demo_hash_lstr_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_LSTR)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = self->links;
#endif

    ICL_DEMO_HASH_LSTR_ASSERT_SANE (self);
    icl_demo_hash_lstr_remove_from_all_containers (self);
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

}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_lstr_selftest (
void)
{
icl_demo_hash_lstr_table_t *
    table;
icl_demo_hash_lstr_t *
    item;

table = icl_demo_hash_lstr_table_new ();

//  Insert some items                                                      
item = icl_demo_hash_lstr_new (table, "0xdeadbeef", "deadbeef", "deadbeef street");
icl_demo_hash_lstr_unlink (&item);
item = icl_demo_hash_lstr_new (table, "0xabadcafe", "abadcafe", "deadbeef cafe");
icl_demo_hash_lstr_unlink (&item);

//  Retrieve items                                                         
item = icl_demo_hash_lstr_table_search (table, "0xdeadbeef");
assert (item && streq (item->name, "deadbeef"));
icl_demo_hash_lstr_unlink (&item);
item = icl_demo_hash_lstr_table_search (table, "0xabadcafe");
assert (item && streq (item->name, "abadcafe"));
icl_demo_hash_lstr_unlink (&item);

//  Get a non existent item                                                
item = icl_demo_hash_lstr_table_search (table, "0xf0000000");
assert (item == NULL);

//  Delete an item                                                         
item = icl_demo_hash_lstr_table_search (table, "0xdeadbeef");
icl_demo_hash_lstr_destroy (&item);
item = icl_demo_hash_lstr_table_search (table, "0xdeadbeef");
assert (item == NULL);

icl_demo_hash_lstr_table_destroy (&table);
}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_lstr_remove_from_all_containers (
    icl_demo_hash_lstr_t * self         //  The item
)
{

ICL_DEMO_HASH_LSTR_ASSERT_SANE (self);
icl_demo_hash_lstr_table_remove (self);
}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_lstr_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    icl_demo_hash_lstr_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_LSTR)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
if (self->table_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <icl_demo_hash_lstr zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_LSTR)
    if (self->history_last > ICL_DEMO_HASH_LSTR_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH;
        self->history_last %= ICL_DEMO_HASH_LSTR_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </icl_demo_hash_lstr>\n");
#endif

}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_lstr_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_destroy

    Type: Component method
    Destroys a icl_demo_hash_lstr_t object. Takes the address of a
    icl_demo_hash_lstr_t reference (a pointer to a pointer) and nullifies the
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
    icl_demo_hash_lstr_destroy_ (
    icl_demo_hash_lstr_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_demo_hash_lstr_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        icl_demo_hash_lstr_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("icl_demo_hash_lstr", "E: missing link on icl_demo_hash_lstr object");
        icl_demo_hash_lstr_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        icl_demo_hash_lstr_free_ ((icl_demo_hash_lstr_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_demo_hash_lstr_t *
    icl_demo_hash_lstr_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    icl_demo_hash_lstr_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    icl_demo_hash_lstr_cache_initialise ();

self = (icl_demo_hash_lstr_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (icl_demo_hash_lstr_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_free

    Type: Component method
    Freess a icl_demo_hash_lstr_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_hash_lstr_free_ (
    icl_demo_hash_lstr_t * self,        //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_LSTR)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_LSTR)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (icl_demo_hash_lstr_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (icl_demo_hash_lstr_t));
        self->object_tag = ICL_DEMO_HASH_LSTR_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_read_lock

    Type: Component method
    Accepts a icl_demo_hash_lstr_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_hash_lstr_read_lock (
    icl_demo_hash_lstr_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ICL_DEMO_HASH_LSTR_ASSERT_SANE (self);
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
    icl_demo_hash_lstr_write_lock

    Type: Component method
    Accepts a icl_demo_hash_lstr_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_hash_lstr_write_lock (
    icl_demo_hash_lstr_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ICL_DEMO_HASH_LSTR_ASSERT_SANE (self);
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
    icl_demo_hash_lstr_unlock

    Type: Component method
    Accepts a icl_demo_hash_lstr_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_hash_lstr_unlock (
    icl_demo_hash_lstr_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ICL_DEMO_HASH_LSTR_ASSERT_SANE (self);
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
    icl_demo_hash_lstr_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

icl_demo_hash_lstr_t *
    icl_demo_hash_lstr_link_ (
    icl_demo_hash_lstr_t * self,        //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_LSTR)
    int
        history_last;
#endif

    if (self) {
        ICL_DEMO_HASH_LSTR_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_LSTR)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_lstr_unlink_ (
    icl_demo_hash_lstr_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_LSTR)
    int
        history_last;
#endif

    icl_demo_hash_lstr_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        ICL_DEMO_HASH_LSTR_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("icl_demo_hash_lstr", "E: missing link on icl_demo_hash_lstr object");
            icl_demo_hash_lstr_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_LSTR)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ICL_DEMO_HASH_LSTR_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            icl_demo_hash_lstr_annihilate_ (self_p, file, line);
        icl_demo_hash_lstr_free_ ((icl_demo_hash_lstr_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_hash_lstr_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (icl_demo_hash_lstr_t));
icl_system_register (icl_demo_hash_lstr_cache_purge, icl_demo_hash_lstr_cache_terminate);
}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_hash_lstr_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_hash_lstr_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_lstr_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

icl_demo_hash_lstr_animating = enabled;
}
/*  -------------------------------------------------------------------------
    icl_demo_hash_lstr_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_lstr_new_in_scope_ (
    icl_demo_hash_lstr_t * * self_p,    //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    icl_demo_hash_lstr_table_t * table,   //  Table to insert into
    char * key,                         //  Hash key
    char * name,                        //  Not documented
    char * address                      //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = icl_demo_hash_lstr_new_ (file,line,table,key,name,address);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_demo_hash_lstr_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__icl_demo_hash_lstr_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__icl_demo_hash_lstr_component  = "icl_demo_hash_lstr ";
char *EMBED__icl_demo_hash_lstr_version   = "1.0b0 ";
char *EMBED__icl_demo_hash_lstr_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__icl_demo_hash_lstr_filename  = "icl_demo_hash_lstr.icl ";
char *EMBED__icl_demo_hash_lstr_builddate  = "2010/10/06 ";
char *EMBED__icl_demo_hash_lstr_version_end  = "VeRsIoNeNd:ipc";

