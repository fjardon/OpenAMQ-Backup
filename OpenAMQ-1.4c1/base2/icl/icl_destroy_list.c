/*---------------------------------------------------------------------------
    icl_destroy_list.c - icl_destroy_list component

    This class implements the list container for icl_destroy

    As a destroy list is, from the application point of view, a scope, we
    define macros icl_scope_xxx to allow such an object to be referred to 
    as a scope.
    Generated from icl_destroy_list.icl by icl_gen using GSL/4.
    
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
#include "icl_destroy_list.h"           //  Definitions for our class

//  Shorthand for class type

#define self_t              icl_destroy_list_t

//  Shorthands for class methods

#define self_new            icl_destroy_list_new
#define self_annihilate     icl_destroy_list_annihilate
#define self_selftest       icl_destroy_list_selftest
#define self_isempty        icl_destroy_list_isempty
#define self_push           icl_destroy_list_push
#define self_pop            icl_destroy_list_pop
#define self_queue          icl_destroy_list_queue
#define self_relink_before  icl_destroy_list_relink_before
#define self_remove         icl_destroy_list_remove
#define self_first          icl_destroy_list_first
#define self_last           icl_destroy_list_last
#define self_next           icl_destroy_list_next
#define self_prev           icl_destroy_list_prev
#define self_count          icl_destroy_list_count
#define self_rehook         icl_destroy_list_rehook
#define self_unhook         icl_destroy_list_unhook
#define self_terminate      icl_destroy_list_terminate
#define self_show           icl_destroy_list_show
#define self_destroy        icl_destroy_list_destroy
#define self_alloc          icl_destroy_list_alloc
#define self_free           icl_destroy_list_free
#define self_link           icl_destroy_list_link
#define self_unlink         icl_destroy_list_unlink
#define self_cache_initialise  icl_destroy_list_cache_initialise
#define self_cache_purge    icl_destroy_list_cache_purge
#define self_cache_terminate  icl_destroy_list_cache_terminate
#define self_show_animation  icl_destroy_list_show_animation
#define self_new_in_scope   icl_destroy_list_new_in_scope

#define icl_destroy_list_annihilate(self)  icl_destroy_list_annihilate_ (self, __FILE__, __LINE__)
static void
    icl_destroy_list_annihilate_ (
icl_destroy_list_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static inline void
    icl_destroy_list_rehook (
icl_destroy_t * item,                   //  Not documented
icl_destroy_t * left,                   //  Not documented
icl_destroy_t * right                   //  Not documented
);

static inline icl_destroy_t *
    icl_destroy_list_unhook (
icl_destroy_t * item                    //  Not documented
);

#define icl_destroy_list_alloc()        icl_destroy_list_alloc_ (__FILE__, __LINE__)
static icl_destroy_list_t *
    icl_destroy_list_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_destroy_list_free(self)     icl_destroy_list_free_ (self, __FILE__, __LINE__)
static void
    icl_destroy_list_free_ (
icl_destroy_list_t * self,              //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    icl_destroy_list_cache_initialise (
void);

static void
    icl_destroy_list_cache_purge (
void);

static void
    icl_destroy_list_cache_terminate (
void);

Bool
    icl_destroy_list_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    icl_destroy_list_new

    Type: Component method
    Creates and initialises a new icl_destroy_list_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

icl_destroy_list_t *
    icl_destroy_list_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_list_t *
        self = NULL;                    //  Object reference

    self = icl_destroy_list_alloc_ (file, line);
    if (self) {
        self->object_tag   = ICL_DESTROY_LIST_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DESTROY_LIST)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, icl_destroy_list_show_);
#endif

self->icl_destroy.list_next = &self->icl_destroy;
self->icl_destroy.list_prev = &self->icl_destroy;
self->icl_destroy.list_head = self;
self->count = 0;

}

    return (self);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_annihilate

    Type: Component method
    Destroys the list and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    icl_destroy_list_annihilate_ (
    icl_destroy_list_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DESTROY_LIST)
    int
        history_last;
#endif

icl_destroy_t
    *item;
    icl_destroy_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DESTROY_LIST)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = self->links;
#endif

    ICL_DESTROY_LIST_ASSERT_SANE (self);

item = (icl_destroy_t *) self->icl_destroy.list_next;
while (item != &self->icl_destroy) {
    //  Unlink child without lock (we already have the lock)
    icl_destroy_list_unhook (item);

    icl_destroy_unlink (&item);
    item = (icl_destroy_t *) self->icl_destroy.list_next;
}

}
/*  -------------------------------------------------------------------------
    icl_destroy_list_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_destroy_list_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    icl_destroy_list_isempty

    Type: Component method
    Accepts a icl_destroy_list_t reference and returns zero in case of success,
    1 in case of errors.
    Returns true if the list is empty, else returns false.
    -------------------------------------------------------------------------
 */

int
    icl_destroy_list_isempty (
    icl_destroy_list_t * self           //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ICL_DESTROY_LIST_ASSERT_SANE (self);
if (!self->zombie) {

rc = (self->icl_destroy.list_next == &self->icl_destroy);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_push

    Type: Component method
    Accepts a icl_destroy_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the start of the specified list. If the item
    was on another list, it is first detached.  After this method,
    list->next points to the item.
    -------------------------------------------------------------------------
 */

int
    icl_destroy_list_push (
    icl_destroy_list_t * self,          //  Reference to object
    icl_destroy_t * item                //  Not documented
)
{


    int
        rc = 0;                         //  Return code



ICL_DESTROY_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//  If list_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->list_head) {
    icl_destroy_link (item);
    icl_atomic_inc32 (&self->count);
}
else
if (item->list_head != self) {
    icl_console_print ("E: icl_destroy item inserted into multiple list containers");
    assert (item->list_head == self);
}
icl_destroy_list_unhook (item);
icl_destroy_list_rehook (item, &self->icl_destroy, (icl_destroy_t *) self->icl_destroy.list_next);
}
else
    rc = -1;                        //  Return error on zombie object.




    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_pop

    Type: Component method
    Removes the next item in the list, if any, and returns it.  If
    the list was empty, returns NULL.

    The number of links is unchanged; removing from the list and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

icl_destroy_t *
    icl_destroy_list_pop (
    icl_destroy_list_t * self           //  The list
)
{


    icl_destroy_t *
        item = NULL;                    //  Not documented



ICL_DESTROY_LIST_ASSERT_SANE (self);
if (!self->zombie) {

if (self->icl_destroy.list_next == &self->icl_destroy)
    item = NULL;
else {
    item = icl_destroy_list_unhook ((icl_destroy_t *) self->icl_destroy.list_next);
    icl_atomic_dec32 (&self->count);
}
}




    return (item);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_queue

    Type: Component method
    Accepts a icl_destroy_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the end of the specified list.  The item may not
    be in another list of the same class.

    The number of links is automatically adjusted - if the item was already
    in the list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    icl_destroy_list_queue (
    icl_destroy_list_t * self,          //  Reference to object
    icl_destroy_t * item                //  Not documented
)
{


    int
        rc = 0;                         //  Return code



ICL_DESTROY_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//  If list_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->list_head) {
    icl_destroy_link (item);
    icl_atomic_inc32 (&self->count);
}
else
if (item->list_head != self) {
    icl_console_print ("E: icl_destroy item inserted into multiple list containers");
    assert (item->list_head == self);
}
icl_destroy_list_unhook (item);
icl_destroy_list_rehook (item, (icl_destroy_t *) self->icl_destroy.list_prev, &self->icl_destroy);
}
else
    rc = -1;                        //  Return error on zombie object.




    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_relink_before

    Type: Component method
    Accepts a icl_destroy_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item before a specified item. If the item was on another list,
    it is first detached.

    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    icl_destroy_list_relink_before (
    icl_destroy_t * item,               //  Not documented
    icl_destroy_t * where               //  Not documented
)
{


    int
        rc = 0;                         //  Return code
    icl_destroy_list_t *
        self = (icl_destroy_list_t *) where->list_head;  //  The list



ICL_DESTROY_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//  If list_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->list_head) {
    icl_destroy_link (item);
    icl_atomic_inc32 (&self->count);
}
else
if (item->list_head != self) {
    icl_console_print ("E: icl_destroy item inserted into multiple list containers");
    assert (item->list_head == self);
}
icl_destroy_list_unhook (item);
icl_destroy_list_rehook (item, (icl_destroy_t *) where->list_prev, where);
}
else
    rc = -1;                        //  Return error on zombie object.




    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_remove

    Type: Component method
    Removes the item from any list it is in.

    If it was in a list, the number of links is decremented.
    -------------------------------------------------------------------------
 */

int
    icl_destroy_list_remove (
    icl_destroy_t * item                //  Not documented
)
{


    icl_destroy_list_t *
        self = (icl_destroy_list_t *) item->list_head;  //  The list
    int
        rc = 0;                         //  Not documented



if (self
&&  self == item->list_head) { //       Catch case where item moved
    icl_destroy_list_unhook (item);
    icl_destroy_unlink (&item);
    icl_atomic_dec32 (&self->count);
}



    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_first

    Type: Component method
    Returns the first icl_destroy item on the list.   If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

icl_destroy_t *
    icl_destroy_list_first_ (
    icl_destroy_list_t * self,          //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    icl_destroy_t *
        item = NULL;                    //  Not documented



ICL_DESTROY_LIST_ASSERT_SANE (self);
if (!self->zombie) {

item = (icl_destroy_t *) self->icl_destroy.list_next;
if (item == &self->icl_destroy)
    item = NULL;
else
    icl_destroy_link (item);

}




    return (item);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_last

    Type: Component method
    Returns the last icl_destroy item on the list.   If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

icl_destroy_t *
    icl_destroy_list_last_ (
    icl_destroy_list_t * self,          //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    icl_destroy_t *
        item = NULL;                    //  Not documented



ICL_DESTROY_LIST_ASSERT_SANE (self);
if (!self->zombie) {

item = (icl_destroy_t *) self->icl_destroy.list_prev;
if (item == &self->icl_destroy)
    item = NULL;
else
    icl_destroy_link (item);

}




    return (item);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_next

    Type: Component method
    Returns the following item on the icl_destroy list. If the provided item
    is null, returns the first item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

icl_destroy_t *
    icl_destroy_list_next_ (
    icl_destroy_t * ( * item_p ),       //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    icl_destroy_t *
        item = *item_p;                 //  Dereferenced item
    icl_destroy_t *
        next = NULL;                    //  The item to return
    icl_destroy_list_t *
        self = (icl_destroy_list_t *) item->list_head;  //  The list



if (self
&&  self == item->list_head) { //       Catch case where item moved
    next = (icl_destroy_t *) item->list_next;
    if (next == &self->icl_destroy)
        next = NULL;
    else
        icl_destroy_link (next);

}
icl_destroy_unlink (item_p);




    return (next);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_prev

    Type: Component method
    Returns the preceding item on the icl_destroy list. If the provided item
    is null, returns the last item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

icl_destroy_t *
    icl_destroy_list_prev_ (
    icl_destroy_t * ( * item_p ),       //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    icl_destroy_t *
        item = *item_p;                 //  Dereferenced item
    icl_destroy_t *
        prev = NULL;                    //  The item to return
    icl_destroy_list_t *
        self = (icl_destroy_list_t *) item->list_head;  //  The list



if (self
&&  self == item->list_head) { //       Catch case where item moved
    prev = (icl_destroy_t *) item->list_prev;
    if (prev == &self->icl_destroy)
        prev = NULL;
    else
        icl_destroy_link (prev);

}
icl_destroy_unlink (item_p);




    return (prev);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_count

    Type: Component method
    Return the count of the number of objects in the list.
    -------------------------------------------------------------------------
 */

qbyte
    icl_destroy_list_count (
    icl_destroy_list_t * self           //  The list
)
{
    qbyte
        count;                          //  Not documented

ICL_DESTROY_LIST_ASSERT_SANE (self);
count = icl_atomic_get32 (&self->count);


    return (count);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_rehook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    icl_destroy_list_rehook (
    icl_destroy_t * item,               //  Not documented
    icl_destroy_t * left,               //  Not documented
    icl_destroy_t * right               //  Not documented
)
{
icl_destroy_t
    *swap;

swap = (icl_destroy_t *) left->list_next;
left->list_next = item->list_next;
item->list_next = swap;

swap = (icl_destroy_t *) item->list_prev;
item->list_prev = right->list_prev;
right->list_prev = swap;

item->list_head = left->list_head;
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_unhook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline icl_destroy_t *
    icl_destroy_list_unhook (
    icl_destroy_t * item                //  Not documented
)
{

icl_destroy_list_rehook (item, (icl_destroy_t *) item->list_prev, (icl_destroy_t *) item->list_next);
item->list_head = NULL;

    return (item);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_destroy_list_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    icl_destroy_list_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_destroy_list_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    icl_destroy_list_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DESTROY_LIST)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <icl_destroy_list zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DESTROY_LIST)
    if (self->history_last > ICL_DESTROY_LIST_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ICL_DESTROY_LIST_HISTORY_LENGTH;
        self->history_last %= ICL_DESTROY_LIST_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ICL_DESTROY_LIST_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </icl_destroy_list>\n");
#endif

}
/*  -------------------------------------------------------------------------
    icl_destroy_list_destroy

    Type: Component method
    Destroys a icl_destroy_list_t object. Takes the address of a
    icl_destroy_list_t reference (a pointer to a pointer) and nullifies the
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
    icl_destroy_list_destroy_ (
    icl_destroy_list_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_destroy_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        icl_destroy_list_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("icl_destroy_list", "E: missing link on icl_destroy_list object");
        icl_destroy_list_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        icl_destroy_list_free_ ((icl_destroy_list_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_destroy_list_t *
    icl_destroy_list_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    icl_destroy_list_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    icl_destroy_list_cache_initialise ();

self = (icl_destroy_list_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (icl_destroy_list_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_free

    Type: Component method
    Freess a icl_destroy_list_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_destroy_list_free_ (
    icl_destroy_list_t * self,          //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DESTROY_LIST)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DESTROY_LIST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (icl_destroy_list_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (icl_destroy_list_t));
        self->object_tag = ICL_DESTROY_LIST_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

icl_destroy_list_t *
    icl_destroy_list_link_ (
    icl_destroy_list_t * self,          //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DESTROY_LIST)
    int
        history_last;
#endif

    if (self) {
        ICL_DESTROY_LIST_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DESTROY_LIST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    icl_destroy_list_unlink_ (
    icl_destroy_list_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DESTROY_LIST)
    int
        history_last;
#endif

    icl_destroy_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        ICL_DESTROY_LIST_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("icl_destroy_list", "E: missing link on icl_destroy_list object");
            icl_destroy_list_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DESTROY_LIST)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ICL_DESTROY_LIST_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            icl_destroy_list_annihilate_ (self_p, file, line);
        icl_destroy_list_free_ ((icl_destroy_list_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    icl_destroy_list_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (icl_destroy_list_t));
icl_system_register (icl_destroy_list_cache_purge, icl_destroy_list_cache_terminate);
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_destroy_list_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    icl_destroy_list_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_destroy_list_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    icl_destroy_list_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_destroy_list_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

icl_destroy_list_animating = enabled;
}
/*  -------------------------------------------------------------------------
    icl_destroy_list_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_destroy_list_new_in_scope_ (
    icl_destroy_list_t * * self_p,      //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = icl_destroy_list_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_destroy_list_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__icl_destroy_list_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__icl_destroy_list_component   = "icl_destroy_list ";
char *EMBED__icl_destroy_list_version     = "1.0 ";
char *EMBED__icl_destroy_list_copyright   = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__icl_destroy_list_filename    = "icl_destroy_list.icl ";
char *EMBED__icl_destroy_list_builddate   = "2010/10/06 ";
char *EMBED__icl_destroy_list_version_end  = "VeRsIoNeNd:ipc";

