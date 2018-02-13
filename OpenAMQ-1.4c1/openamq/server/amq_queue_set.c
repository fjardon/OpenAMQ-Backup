/*---------------------------------------------------------------------------
    amq_queue_set.c - amq_queue_set component

    Generated from amq_queue_set.icl by icl_gen using GSL/4.
    
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
#include "amq_queue_set.h"              //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_queue_set_t

//  Shorthands for class methods

#define self_find           amq_queue_set_find
#define self_selftest       amq_queue_set_selftest
#define self_iter_new       amq_queue_set_iter_new
#define self_iter_object    amq_queue_set_iter_object
#define self_iter_destroy   amq_queue_set_iter_destroy
#define self_new            amq_queue_set_new
#define self_annihilate     amq_queue_set_annihilate
#define self_isempty        amq_queue_set_isempty
#define self_push           amq_queue_set_push
#define self_pop            amq_queue_set_pop
#define self_queue          amq_queue_set_queue
#define self_relink_before  amq_queue_set_relink_before
#define self_remove         amq_queue_set_remove
#define self_first          amq_queue_set_first
#define self_last           amq_queue_set_last
#define self_next           amq_queue_set_next
#define self_prev           amq_queue_set_prev
#define self_count          amq_queue_set_count
#define self_rehook         amq_queue_set_rehook
#define self_unhook         amq_queue_set_unhook
#define self_cache_initialise  amq_queue_set_cache_initialise
#define self_cache_purge    amq_queue_set_cache_purge
#define self_terminate      amq_queue_set_terminate
#define self_show           amq_queue_set_show
#define self_destroy        amq_queue_set_destroy
#define self_alloc          amq_queue_set_alloc
#define self_free           amq_queue_set_free
#define self_cache_terminate  amq_queue_set_cache_terminate
#define self_show_animation  amq_queue_set_show_animation
#define self_new_in_scope   amq_queue_set_new_in_scope

static void
    amq_queue_set_annihilate (
amq_queue_set_t * ( * self_p )          //  Reference to object reference
);

static inline void
    amq_queue_set_rehook (
amq_queue_set_iter_t * item,            //  Not documented
amq_queue_set_iter_t * left,            //  Not documented
amq_queue_set_iter_t * right            //  Not documented
);

static inline amq_queue_set_iter_t *
    amq_queue_set_unhook (
amq_queue_set_iter_t * item             //  Not documented
);

static void
    amq_queue_set_cache_initialise (
void);

static void
    amq_queue_set_cache_purge (
void);

#define amq_queue_set_alloc()           amq_queue_set_alloc_ (__FILE__, __LINE__)
static amq_queue_set_t *
    amq_queue_set_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_queue_set_free (
amq_queue_set_t * self                  //  Object reference
);

static void
    amq_queue_set_cache_terminate (
void);

Bool
    amq_queue_set_animating = TRUE;     //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static icl_cache_t
    *s_iter_cache = NULL;
/*  -------------------------------------------------------------------------
    amq_queue_set_find

    Type: Component method
    Accepts a amq_queue_set_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

amq_queue_set_iter_t *
    amq_queue_set_find (
    amq_queue_set_t * self,             //  Reference to object
    amq_queue_t * value                 //  Not documented
)
{
    amq_queue_set_iter_t *
        rc = 0;                         //  Return code

AMQ_QUEUE_SET_ASSERT_SANE (self);

for (rc = self_first (self); rc; rc = self_next (&rc))
    if (rc->item == value)
        break;


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_set_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_queue_set_iter_new

    Type: Component method
    -------------------------------------------------------------------------
 */

amq_queue_set_iter_t *
    amq_queue_set_iter_new (
    amq_queue_t * item                  //  Not documented
)
{
    amq_queue_set_iter_t *
        iter;                           //  Not documented

iter = icl_mem_cache_alloc (s_iter_cache);
iter->next = iter;
iter->prev = iter;
iter->head = NULL;
iter->item = amq_queue_link (item);


    return (iter);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_iter_object

    Type: Component method
    -------------------------------------------------------------------------
 */

amq_queue_t *
    amq_queue_set_iter_object (
    amq_queue_set_iter_t * iter         //  Not documented
)
{
    amq_queue_t *
        item;                           //  Not documented

item = amq_queue_link (iter->item);


    return (item);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_iter_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_set_iter_destroy (
    amq_queue_set_iter_t * ( * iter_p )  //  Not documented
)
{
    amq_queue_set_iter_t *
        iter = *iter_p;                 //  Dereferenced iter

if (iter) {
    amq_queue_set_remove (iter);
    amq_queue_unlink (&iter->item);
    icl_mem_free (iter);
    *iter_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_queue_set_new

    Type: Component method
    Creates and initialises a new amq_queue_set_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_queue_set_t *
    amq_queue_set_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_queue_set_t *
        self = NULL;                    //  Object reference

    self = amq_queue_set_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_QUEUE_SET_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_queue_set_show_);
#endif

self->amq_queue_set_iter.next = &self->amq_queue_set_iter;
self->amq_queue_set_iter.prev = &self->amq_queue_set_iter;
self->amq_queue_set_iter.head = self;
self->amq_queue_set_iter.item = NULL;
self->count = 0;

}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_annihilate

    Type: Component method
    Destroys the list and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    amq_queue_set_annihilate (
    amq_queue_set_t * ( * self_p )      //  Reference to object reference
)
{

amq_queue_set_iter_t
    *item;
    amq_queue_set_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

AMQ_QUEUE_SET_ASSERT_SANE (self);

item = (amq_queue_set_iter_t *) self->amq_queue_set_iter.next;
while (item != &self->amq_queue_set_iter) {
    //  Unlink child without lock (we already have the lock)
    amq_queue_set_unhook (item);

    amq_queue_set_iter_destroy (&item);
    item = (amq_queue_set_iter_t *) self->amq_queue_set_iter.next;
}

}
/*  -------------------------------------------------------------------------
    amq_queue_set_isempty

    Type: Component method
    Accepts a amq_queue_set_t reference and returns zero in case of success,
    1 in case of errors.
    Returns true if the list is empty, else returns false.
    -------------------------------------------------------------------------
 */

int
    amq_queue_set_isempty (
    amq_queue_set_t * self              //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_SET_ASSERT_SANE (self);

rc = (self->amq_queue_set_iter.next == &self->amq_queue_set_iter);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_push

    Type: Component method
    Accepts a amq_queue_set_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the start of the specified list. If the item
    was on another list, it is first detached.  After this method,
    list->next points to the item.
    -------------------------------------------------------------------------
 */

int
    amq_queue_set_push (
    amq_queue_set_t * self,             //  Reference to object
    amq_queue_t * item                  //  Not documented
)
{


amq_queue_set_iter_t
    *iter;
    int
        rc = 0;                         //  Return code



AMQ_QUEUE_SET_ASSERT_SANE (self);

iter = amq_queue_set_iter_new (item);
icl_atomic_inc32 (&self->count);
amq_queue_set_rehook (iter, &self->amq_queue_set_iter, (amq_queue_set_iter_t *) self->amq_queue_set_iter.next);




    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_pop

    Type: Component method
    Removes the next item in the list, if any, and returns it.  If
    the list was empty, returns NULL.

    The number of links is unchanged; removing from the list and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

amq_queue_t *
    amq_queue_set_pop (
    amq_queue_set_t * self              //  The list
)
{


amq_queue_set_iter_t
    *iter = NULL;
    amq_queue_t *
        item = NULL;                    //  Not documented



AMQ_QUEUE_SET_ASSERT_SANE (self);

if (self->amq_queue_set_iter.next != &self->amq_queue_set_iter) {
    iter = amq_queue_set_unhook ((amq_queue_set_iter_t *) self->amq_queue_set_iter.next);
    icl_atomic_dec32 (&self->count);
    item = iter->item;
    iter->item = NULL;          //  So don't destroy item
    amq_queue_set_iter_destroy (&iter);
}




    return (item);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_queue

    Type: Component method
    Accepts a amq_queue_set_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the end of the specified list. If the item
    was on another list, it is first detached.

    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    amq_queue_set_queue (
    amq_queue_set_t * self,             //  Reference to object
    amq_queue_t * item                  //  Not documented
)
{


amq_queue_set_iter_t
    *iter;
    int
        rc = 0;                         //  Return code



AMQ_QUEUE_SET_ASSERT_SANE (self);

iter = amq_queue_set_iter_new (item);
icl_atomic_inc32 (&self->count);
amq_queue_set_rehook (iter, (amq_queue_set_iter_t *) self->amq_queue_set_iter.prev, &self->amq_queue_set_iter);




    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_relink_before

    Type: Component method
    Accepts a amq_queue_set_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item before a specified item. If the item was on another list,
    it is first detached.

    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    amq_queue_set_relink_before (
    amq_queue_set_iter_t * item,        //  Not documented
    amq_queue_set_iter_t * where        //  Not documented
)
{


    int
        rc = 0;                         //  Return code
    amq_queue_set_t *
        self = (amq_queue_set_t *) where->head;  //  The list



AMQ_QUEUE_SET_ASSERT_SANE (self);

//  If head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->head) {
    icl_atomic_inc32 (&self->count);
}
else
if (item->head != self) {
    icl_console_print ("E: amq_queue item inserted into multiple list containers");
    assert (item->head == self);
}
amq_queue_set_unhook (item);
amq_queue_set_rehook (item, (amq_queue_set_iter_t *) where->prev, where);




    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_remove

    Type: Component method
    Removes the amq_queue_set_iter item from any list it is in.

    If it was in a list, the number of links is decremented.
    -------------------------------------------------------------------------
 */

int
    amq_queue_set_remove (
    amq_queue_set_iter_t * item         //  Not documented
)
{


    amq_queue_set_t *
        self = (amq_queue_set_t *) item->head;  //  The list
    int
        rc = 0;                         //  Not documented



if (self
&&  self == item->head) { //  Catch case where item moved
    amq_queue_set_unhook (item);
    icl_atomic_dec32 (&self->count);
}



    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_first

    Type: Component method
    Returns the first amq_queue_set_iter item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

amq_queue_set_iter_t *
    amq_queue_set_first_ (
    amq_queue_set_t * self,             //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    amq_queue_set_iter_t *
        item = NULL;                    //  Not documented



AMQ_QUEUE_SET_ASSERT_SANE (self);

item = (amq_queue_set_iter_t *) self->amq_queue_set_iter.next;
if (item == &self->amq_queue_set_iter)
    item = NULL;




    return (item);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_last

    Type: Component method
    Returns the last amq_queue_set_iter item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

amq_queue_set_iter_t *
    amq_queue_set_last_ (
    amq_queue_set_t * self,             //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    amq_queue_set_iter_t *
        item = NULL;                    //  Not documented



AMQ_QUEUE_SET_ASSERT_SANE (self);

item = (amq_queue_set_iter_t *) self->amq_queue_set_iter.prev;
if (item == &self->amq_queue_set_iter)
    item = NULL;




    return (item);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_next

    Type: Component method
    Returns the following item on the amq_queue_set_iter list. If the provided item
    is null, returns the first item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

amq_queue_set_iter_t *
    amq_queue_set_next_ (
    amq_queue_set_iter_t * ( * item_p ),   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    amq_queue_set_iter_t *
        item = *item_p;                 //  Dereferenced item
    amq_queue_set_iter_t *
        next = NULL;                    //  The item to return
    amq_queue_set_t *
        self = (amq_queue_set_t *) item->head;  //  The list



if (self
&&  self == item->head) { //  Catch case where item moved
    next = (amq_queue_set_iter_t *) item->next;
    if (next == &self->amq_queue_set_iter)
        next = NULL;
}



    return (next);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_prev

    Type: Component method
    Returns the preceding item on the amq_queue_set_iter list. If the provided item
    is null, returns the last item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

amq_queue_set_iter_t *
    amq_queue_set_prev_ (
    amq_queue_set_iter_t * ( * item_p ),   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    amq_queue_set_iter_t *
        item = *item_p;                 //  Dereferenced item
    amq_queue_set_iter_t *
        prev = NULL;                    //  The item to return
    amq_queue_set_t *
        self = (amq_queue_set_t *) item->head;  //  The list



if (self
&&  self == item->head) { //  Catch case where item moved
    prev = (amq_queue_set_iter_t *) item->prev;
    if (prev == &self->amq_queue_set_iter)
        prev = NULL;
}



    return (prev);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_count

    Type: Component method
    Return the count of the number of objects in the list.
    -------------------------------------------------------------------------
 */

qbyte
    amq_queue_set_count (
    amq_queue_set_t * self              //  The list
)
{
    qbyte
        count;                          //  Not documented

//
AMQ_QUEUE_SET_ASSERT_SANE (self);
icl_atomic_set32 (&count, self->count);

    return (count);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_rehook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    amq_queue_set_rehook (
    amq_queue_set_iter_t * item,        //  Not documented
    amq_queue_set_iter_t * left,        //  Not documented
    amq_queue_set_iter_t * right        //  Not documented
)
{
amq_queue_set_iter_t
    *swap;

swap = (amq_queue_set_iter_t *) left->next;
left->next = item->next;
item->next = swap;

swap = (amq_queue_set_iter_t *) item->prev;
item->prev = right->prev;
right->prev = swap;

item->head = left->head;
}
/*  -------------------------------------------------------------------------
    amq_queue_set_unhook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline amq_queue_set_iter_t *
    amq_queue_set_unhook (
    amq_queue_set_iter_t * item         //  Not documented
)
{

amq_queue_set_rehook (item, (amq_queue_set_iter_t *) item->prev, (amq_queue_set_iter_t *) item->next);
item->head = NULL;

    return (item);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_queue_set_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_queue_set_t));
icl_system_register (amq_queue_set_cache_purge, amq_queue_set_cache_terminate);

s_iter_cache = icl_cache_get (sizeof (amq_queue_set_iter_t));
}
/*  -------------------------------------------------------------------------
    amq_queue_set_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_set_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

icl_mem_cache_purge (s_iter_cache);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_set_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_queue_set_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_set_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_queue_set_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_queue_set file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_queue_set_destroy

    Type: Component method
    Destroys a amq_queue_set_t object. Takes the address of a
    amq_queue_set_t reference (a pointer to a pointer) and nullifies the
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
    amq_queue_set_destroy_ (
    amq_queue_set_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_queue_set_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_queue_set_annihilate (self_p);
    amq_queue_set_free ((amq_queue_set_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_queue_set_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_queue_set_t *
    amq_queue_set_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_queue_set_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_queue_set_cache_initialise ();

self = (amq_queue_set_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_queue_set_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_queue_set_free

    Type: Component method
    Freess a amq_queue_set_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_queue_set_free (
    amq_queue_set_t * self              //  Object reference
)
{


if (self) {

        memset (&self->object_tag, 0, sizeof (amq_queue_set_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_queue_set_t));
        self->object_tag = AMQ_QUEUE_SET_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_queue_set_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_set_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_queue_set_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_queue_set_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_queue_set_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_queue_set_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_set_new_in_scope_ (
    amq_queue_set_t * * self_p,         //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_queue_set_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_queue_set_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_queue_set_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_queue_set_component      = "amq_queue_set ";
char *EMBED__amq_queue_set_version        = "1.0 ";
char *EMBED__amq_queue_set_copyright      = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_queue_set_filename       = "amq_queue_set.icl ";
char *EMBED__amq_queue_set_builddate      = "2010/10/06 ";
char *EMBED__amq_queue_set_version_end    = "VeRsIoNeNd:ipc";

