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
#define self_show_animation  amq_queue_bindings_list_show_animation
#define self_new_in_scope   amq_queue_bindings_list_new_in_scope

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

AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
amq_queue_bindings_list_table_remove (self);
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

iter = icl_mem_cache_alloc (s_iter_cache);
iter->next = iter;
iter->prev = iter;
iter->head = NULL;
iter->item = amq_binding_link (item);


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

item = amq_binding_link (iter->item);


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

if (iter) {
    amq_queue_bindings_list_remove (iter);
    amq_binding_unlink (&iter->item);
    icl_mem_free (iter);
    *iter_p = NULL;
}
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

AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

rc = (self->amq_queue_bindings_list_iter.next == &self->amq_queue_bindings_list_iter);
}
else
    rc = -1;                        //  Return error on zombie object.


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



AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

iter = amq_queue_bindings_list_iter_new (item);
icl_atomic_inc32 (&self->count);
amq_queue_bindings_list_rehook (iter, &self->amq_queue_bindings_list_iter, (amq_queue_bindings_list_iter_t *) self->amq_queue_bindings_list_iter.next);
}
else
    rc = -1;                        //  Return error on zombie object.




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



AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

iter = amq_queue_bindings_list_iter_new (item);
icl_atomic_inc32 (&self->count);
amq_queue_bindings_list_rehook (iter, (amq_queue_bindings_list_iter_t *) self->amq_queue_bindings_list_iter.prev, &self->amq_queue_bindings_list_iter);
}
else
    rc = -1;                        //  Return error on zombie object.




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
    icl_console_print ("E: amq_binding item inserted into multiple list containers");
    assert (item->head == self);
}
amq_queue_bindings_list_unhook (item);
amq_queue_bindings_list_rehook (item, (amq_queue_bindings_list_iter_t *) where->prev, where);
}
else
    rc = -1;                        //  Return error on zombie object.




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



if (self
&&  self == item->head) { //  Catch case where item moved
    amq_queue_bindings_list_unhook (item);
    icl_atomic_dec32 (&self->count);
}



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



AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

item = (amq_queue_bindings_list_iter_t *) self->amq_queue_bindings_list_iter.next;
if (item == &self->amq_queue_bindings_list_iter)
    item = NULL;
}




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



AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
if (!self->zombie) {

item = (amq_queue_bindings_list_iter_t *) self->amq_queue_bindings_list_iter.prev;
if (item == &self->amq_queue_bindings_list_iter)
    item = NULL;
}




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



if (self
&&  self == item->head) { //  Catch case where item moved
    next = (amq_queue_bindings_list_iter_t *) item->next;
    if (next == &self->amq_queue_bindings_list_iter)
        next = NULL;
}



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



if (self
&&  self == item->head) { //  Catch case where item moved
    prev = (amq_queue_bindings_list_iter_t *) item->prev;
    if (prev == &self->amq_queue_bindings_list_iter)
        prev = NULL;
}



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

//
AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
icl_atomic_set32 (&count, self->count);

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

swap = (amq_queue_bindings_list_iter_t *) left->next;
left->next = item->next;
item->next = swap;

swap = (amq_queue_bindings_list_iter_t *) item->prev;
item->prev = right->prev;
right->prev = swap;

item->head = left->head;
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

amq_queue_bindings_list_rehook (item, (amq_queue_bindings_list_iter_t *) item->prev, (amq_queue_bindings_list_iter_t *) item->next);
item->head = NULL;

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

s_cache = icl_cache_get (sizeof (amq_queue_bindings_list_t));
icl_system_register (amq_queue_bindings_list_cache_purge, amq_queue_bindings_list_cache_terminate);

s_iter_cache = icl_cache_get (sizeof (amq_queue_bindings_list_iter_t));
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

icl_mem_cache_purge (s_cache);

icl_mem_cache_purge (s_iter_cache);
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

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_queue_bindings_list_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("amq_queue_bindings_list", "E: missing link on amq_queue_bindings_list object");
        amq_queue_bindings_list_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_queue_bindings_list_free_ ((amq_queue_bindings_list_t *) self, file, line);
    *self_p = NULL;
}
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

//  Initialise cache if necessary
if (!s_cache)
    amq_queue_bindings_list_cache_initialise ();

self = (amq_queue_bindings_list_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_queue_bindings_list_t));



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


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (amq_queue_bindings_list_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_queue_bindings_list_t));
        self->object_tag = AMQ_QUEUE_BINDINGS_LIST_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
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

    if (self) {
        AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("amq_queue_bindings_list", "E: missing link on amq_queue_bindings_list object");
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

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_queue_bindings_list_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_queue_bindings_list_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_queue_bindings_list_animating = enabled;
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

*self_p = amq_queue_bindings_list_new_ (file,line,table,key);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_queue_bindings_list_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_queue_bindings_list_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_queue_bindings_list_component  = "amq_queue_bindings_list ";
char *EMBED__amq_queue_bindings_list_version  = "1.0 ";
char *EMBED__amq_queue_bindings_list_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_queue_bindings_list_filename  = "amq_queue_bindings_list.icl ";
char *EMBED__amq_queue_bindings_list_builddate  = "2010/10/06 ";
char *EMBED__amq_queue_bindings_list_version_end  = "VeRsIoNeNd:ipc";

