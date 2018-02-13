/*---------------------------------------------------------------------------
    amq_consumer_by_channel.c - amq_consumer_by_channel component

    This class implements the list container for amq_consumer
    Generated from amq_consumer_by_channel.icl by icl_gen using GSL/4.
    
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
#include "amq_consumer_by_channel.h"    //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_consumer_by_channel_t

//  Shorthands for class methods

#define self_new            amq_consumer_by_channel_new
#define self_annihilate     amq_consumer_by_channel_annihilate
#define self_selftest       amq_consumer_by_channel_selftest
#define self_isempty        amq_consumer_by_channel_isempty
#define self_push           amq_consumer_by_channel_push
#define self_pop            amq_consumer_by_channel_pop
#define self_queue          amq_consumer_by_channel_queue
#define self_relink_before  amq_consumer_by_channel_relink_before
#define self_remove         amq_consumer_by_channel_remove
#define self_first          amq_consumer_by_channel_first
#define self_last           amq_consumer_by_channel_last
#define self_next           amq_consumer_by_channel_next
#define self_prev           amq_consumer_by_channel_prev
#define self_rehook         amq_consumer_by_channel_rehook
#define self_unhook         amq_consumer_by_channel_unhook
#define self_terminate      amq_consumer_by_channel_terminate
#define self_show           amq_consumer_by_channel_show
#define self_destroy        amq_consumer_by_channel_destroy
#define self_alloc          amq_consumer_by_channel_alloc
#define self_free           amq_consumer_by_channel_free
#define self_read_lock      amq_consumer_by_channel_read_lock
#define self_write_lock     amq_consumer_by_channel_write_lock
#define self_unlock         amq_consumer_by_channel_unlock
#define self_link           amq_consumer_by_channel_link
#define self_unlink         amq_consumer_by_channel_unlink
#define self_cache_initialise  amq_consumer_by_channel_cache_initialise
#define self_cache_purge    amq_consumer_by_channel_cache_purge
#define self_cache_terminate  amq_consumer_by_channel_cache_terminate
#define self_show_animation  amq_consumer_by_channel_show_animation
#define self_new_in_scope   amq_consumer_by_channel_new_in_scope

#define amq_consumer_by_channel_annihilate(self)  amq_consumer_by_channel_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_consumer_by_channel_annihilate_ (
amq_consumer_by_channel_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static inline void
    amq_consumer_by_channel_rehook (
amq_consumer_t * item,                  //  Not documented
amq_consumer_t * left,                  //  Not documented
amq_consumer_t * right                  //  Not documented
);

static inline amq_consumer_t *
    amq_consumer_by_channel_unhook (
amq_consumer_t * item                   //  Not documented
);

#define amq_consumer_by_channel_alloc()  amq_consumer_by_channel_alloc_ (__FILE__, __LINE__)
static amq_consumer_by_channel_t *
    amq_consumer_by_channel_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_consumer_by_channel_free(self)  amq_consumer_by_channel_free_ (self, __FILE__, __LINE__)
static void
    amq_consumer_by_channel_free_ (
amq_consumer_by_channel_t * self,       //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_consumer_by_channel_cache_initialise (
void);

static void
    amq_consumer_by_channel_cache_purge (
void);

static void
    amq_consumer_by_channel_cache_terminate (
void);

Bool
    amq_consumer_by_channel_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_new

    Type: Component method
    Creates and initialises a new amq_consumer_by_channel_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_consumer_by_channel_t *
    amq_consumer_by_channel_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_consumer_by_channel_t *
        self = NULL;                    //  Object reference

    self = amq_consumer_by_channel_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CONSUMER_BY_CHANNEL_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
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
        icl_mem_set_callback (self, amq_consumer_by_channel_show_);
#endif

self->amq_consumer.by_channel_next = &self->amq_consumer;
self->amq_consumer.by_channel_prev = &self->amq_consumer;
self->amq_consumer.by_channel_head = self;

}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_annihilate

    Type: Component method
    Destroys the list and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_by_channel_annihilate_ (
    amq_consumer_by_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    int
        history_last;
#endif

amq_consumer_t
    *item;
    amq_consumer_by_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = self->links;
#endif

    AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

item = (amq_consumer_t *) self->amq_consumer.by_channel_next;
while (item != &self->amq_consumer) {
    //  Unlink child without lock (we already have the lock)
    amq_consumer_by_channel_unhook (item);

    amq_consumer_unlink (&item);
    item = (amq_consumer_t *) self->amq_consumer.by_channel_next;
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_isempty

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Returns true if the list is empty, else returns false.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_isempty (
    amq_consumer_by_channel_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

rc = (self->amq_consumer.by_channel_next == &self->amq_consumer);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_push

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the start of the specified list. If the item
    was on another list, it is first detached.  After this method,
    list->next points to the item.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_push (
    amq_consumer_by_channel_t * self,   //  Reference to object
    amq_consumer_t * item               //  Not documented
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

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

//  If by_channel_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->by_channel_head) {
    amq_consumer_link (item);
}
else
if (item->by_channel_head != self) {
    icl_console_print ("E: amq_consumer item inserted into multiple by_channel containers");
    assert (item->by_channel_head == self);
}
amq_consumer_by_channel_unhook (item);
amq_consumer_by_channel_rehook (item, &self->amq_consumer, (amq_consumer_t *) self->amq_consumer.by_channel_next);
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
    amq_consumer_by_channel_pop

    Type: Component method
    Removes the next item in the list, if any, and returns it.  If
    the list was empty, returns NULL.

    The number of links is unchanged; removing from the list and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_by_channel_pop (
    amq_consumer_by_channel_t * self    //  The list
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_t *
        item = NULL;                    //  Not documented


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

if (self->amq_consumer.by_channel_next == &self->amq_consumer)
    item = NULL;
else {
    item = amq_consumer_by_channel_unhook ((amq_consumer_t *) self->amq_consumer.by_channel_next);
}
}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif



    return (item);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_queue

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the end of the specified list.  The item may not
    be in another list of the same class.

    The number of links is automatically adjusted - if the item was already
    in the list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_queue (
    amq_consumer_by_channel_t * self,   //  Reference to object
    amq_consumer_t * item               //  Not documented
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

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

//  If by_channel_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->by_channel_head) {
    amq_consumer_link (item);
}
else
if (item->by_channel_head != self) {
    icl_console_print ("E: amq_consumer item inserted into multiple by_channel containers");
    assert (item->by_channel_head == self);
}
amq_consumer_by_channel_unhook (item);
amq_consumer_by_channel_rehook (item, (amq_consumer_t *) self->amq_consumer.by_channel_prev, &self->amq_consumer);
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
    amq_consumer_by_channel_relink_before

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item before a specified item. If the item was on another list,
    it is first detached.

    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_relink_before (
    amq_consumer_t * item,              //  Not documented
    amq_consumer_t * where              //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code
    amq_consumer_by_channel_t *
        self = (amq_consumer_by_channel_t *) where->by_channel_head;  //  The list


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

//  If by_channel_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->by_channel_head) {
    amq_consumer_link (item);
}
else
if (item->by_channel_head != self) {
    icl_console_print ("E: amq_consumer item inserted into multiple by_channel containers");
    assert (item->by_channel_head == self);
}
amq_consumer_by_channel_unhook (item);
amq_consumer_by_channel_rehook (item, (amq_consumer_t *) where->by_channel_prev, where);
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
    amq_consumer_by_channel_remove

    Type: Component method
    Removes the item from any list it is in.

    If it was in a list, the number of links is decremented.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_remove (
    amq_consumer_t * item               //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_by_channel_t *
        self = (amq_consumer_by_channel_t *) item->by_channel_head;  //  The list
    int
        rc = 0;                         //  Not documented


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

if (self
&&  self == item->by_channel_head) { //  Catch case where item moved
    amq_consumer_by_channel_unhook (item);
    amq_consumer_unlink (&item);
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif



    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_first

    Type: Component method
    Returns the first amq_consumer item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_by_channel_first_ (
    amq_consumer_by_channel_t * self,   //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_t *
        item = NULL;                    //  Not documented


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

item = (amq_consumer_t *) self->amq_consumer.by_channel_next;
if (item == &self->amq_consumer)
    item = NULL;
else
    amq_consumer_link (item);

}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif



    return (item);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_last

    Type: Component method
    Returns the last amq_consumer item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_by_channel_last_ (
    amq_consumer_by_channel_t * self,   //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_t *
        item = NULL;                    //  Not documented


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

item = (amq_consumer_t *) self->amq_consumer.by_channel_prev;
if (item == &self->amq_consumer)
    item = NULL;
else
    amq_consumer_link (item);

}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif



    return (item);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_next

    Type: Component method
    Returns the following item on the amq_consumer list. If the provided item
    is null, returns the first item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_by_channel_next_ (
    amq_consumer_t * ( * item_p ),      //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_t *
        item = *item_p;                 //  Dereferenced item
    amq_consumer_t *
        next = NULL;                    //  The item to return
    amq_consumer_by_channel_t *
        self = (amq_consumer_by_channel_t *) item->by_channel_head;  //  The list


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

if (self
&&  self == item->by_channel_head) { //  Catch case where item moved
    next = (amq_consumer_t *) item->by_channel_next;
    if (next == &self->amq_consumer)
        next = NULL;
    else
        amq_consumer_link (next);

}
amq_consumer_unlink (item_p);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif



    return (next);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_prev

    Type: Component method
    Returns the preceding item on the amq_consumer list. If the provided item
    is null, returns the last item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_by_channel_prev_ (
    amq_consumer_t * ( * item_p ),      //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_consumer_t *
        item = *item_p;                 //  Dereferenced item
    amq_consumer_t *
        prev = NULL;                    //  The item to return
    amq_consumer_by_channel_t *
        self = (amq_consumer_by_channel_t *) item->by_channel_head;  //  The list


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

if (self
&&  self == item->by_channel_head) { //  Catch case where item moved
    prev = (amq_consumer_t *) item->by_channel_prev;
    if (prev == &self->amq_consumer)
        prev = NULL;
    else
        amq_consumer_link (prev);

}
amq_consumer_unlink (item_p);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif



    return (prev);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_rehook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    amq_consumer_by_channel_rehook (
    amq_consumer_t * item,              //  Not documented
    amq_consumer_t * left,              //  Not documented
    amq_consumer_t * right              //  Not documented
)
{
amq_consumer_t
    *swap;

swap = (amq_consumer_t *) left->by_channel_next;
left->by_channel_next = item->by_channel_next;
item->by_channel_next = swap;

swap = (amq_consumer_t *) item->by_channel_prev;
item->by_channel_prev = right->by_channel_prev;
right->by_channel_prev = swap;

item->by_channel_head = left->by_channel_head;
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_unhook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline amq_consumer_t *
    amq_consumer_by_channel_unhook (
    amq_consumer_t * item               //  Not documented
)
{

amq_consumer_by_channel_rehook (item, (amq_consumer_t *) item->by_channel_prev, (amq_consumer_t *) item->by_channel_next);
item->by_channel_head = NULL;

    return (item);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_consumer_by_channel_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_consumer_by_channel zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    if (self->history_last > AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH;
        self->history_last %= AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_consumer_by_channel>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_destroy

    Type: Component method
    Destroys a amq_consumer_by_channel_t object. Takes the address of a
    amq_consumer_by_channel_t reference (a pointer to a pointer) and nullifies the
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
    amq_consumer_by_channel_destroy_ (
    amq_consumer_by_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_consumer_by_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_consumer_by_channel_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("amq_consumer_by_channel", "E: missing link on amq_consumer_by_channel object");
        amq_consumer_by_channel_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_consumer_by_channel_free_ ((amq_consumer_by_channel_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_consumer_by_channel_t *
    amq_consumer_by_channel_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_consumer_by_channel_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_consumer_by_channel_cache_initialise ();

self = (amq_consumer_by_channel_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_consumer_by_channel_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_free

    Type: Component method
    Freess a amq_consumer_by_channel_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_by_channel_free_ (
    amq_consumer_by_channel_t * self,   //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (amq_consumer_by_channel_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_consumer_by_channel_t));
        self->object_tag = AMQ_CONSUMER_BY_CHANNEL_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_read_lock

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_read_lock (
    amq_consumer_by_channel_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
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
    amq_consumer_by_channel_write_lock

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_write_lock (
    amq_consumer_by_channel_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
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
    amq_consumer_by_channel_unlock

    Type: Component method
    Accepts a amq_consumer_by_channel_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_by_channel_unlock (
    amq_consumer_by_channel_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
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
    amq_consumer_by_channel_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_consumer_by_channel_t *
    amq_consumer_by_channel_link_ (
    amq_consumer_by_channel_t * self,   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    int
        history_last;
#endif

    if (self) {
        AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_unlink_ (
    amq_consumer_by_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
    int
        history_last;
#endif

    amq_consumer_by_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        AMQ_CONSUMER_BY_CHANNEL_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("amq_consumer_by_channel", "E: missing link on amq_consumer_by_channel object");
            amq_consumer_by_channel_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_CHANNEL)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_CONSUMER_BY_CHANNEL_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_consumer_by_channel_annihilate_ (self_p, file, line);
        amq_consumer_by_channel_free_ ((amq_consumer_by_channel_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_by_channel_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_consumer_by_channel_t));
icl_system_register (amq_consumer_by_channel_cache_purge, amq_consumer_by_channel_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_by_channel_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_by_channel_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_consumer_by_channel_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_consumer_by_channel_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_by_channel_new_in_scope_ (
    amq_consumer_by_channel_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_consumer_by_channel_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_consumer_by_channel_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_consumer_by_channel_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_consumer_by_channel_component  = "amq_consumer_by_channel ";
char *EMBED__amq_consumer_by_channel_version  = "1.0 ";
char *EMBED__amq_consumer_by_channel_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_consumer_by_channel_filename  = "amq_consumer_by_channel.icl ";
char *EMBED__amq_consumer_by_channel_builddate  = "2010/10/06 ";
char *EMBED__amq_consumer_by_channel_version_end  = "VeRsIoNeNd:ipc";

