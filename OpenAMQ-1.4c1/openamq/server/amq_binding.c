/*---------------------------------------------------------------------------
    amq_binding.c - amq_binding component

This class implements an exchange binding, which is a collection of
queues and other exchanges that share the same binding arguments.
This class runs lock-free as a child of the asynchronous exchange
class.
    Generated from amq_binding.icl by icl_gen using GSL/4.
    
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
#include "amq_binding.h"                //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_binding_t

//  Shorthands for class methods

#define self_new            amq_binding_new
#define self_annihilate     amq_binding_annihilate
#define self_bind_queue     amq_binding_bind_queue
#define self_unbind_queue   amq_binding_unbind_queue
#define self_collect        amq_binding_collect
#define self_selftest       amq_binding_selftest
#define self_count          amq_binding_count
#define self_remove_from_all_containers  amq_binding_remove_from_all_containers
#define self_show           amq_binding_show
#define self_terminate      amq_binding_terminate
#define self_destroy        amq_binding_destroy
#define self_alloc          amq_binding_alloc
#define self_free           amq_binding_free
#define self_link           amq_binding_link
#define self_unlink         amq_binding_unlink
#define self_cache_initialise  amq_binding_cache_initialise
#define self_cache_purge    amq_binding_cache_purge
#define self_cache_terminate  amq_binding_cache_terminate
#define self_show_animation  amq_binding_show_animation
#define self_new_in_scope   amq_binding_new_in_scope

#define amq_binding_annihilate(self)    amq_binding_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_binding_annihilate_ (
amq_binding_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_binding_alloc()             amq_binding_alloc_ (__FILE__, __LINE__)
static amq_binding_t *
    amq_binding_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_binding_free(self)          amq_binding_free_ (self, __FILE__, __LINE__)
static void
    amq_binding_free_ (
amq_binding_t * self,                   //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_binding_cache_initialise (
void);

static void
    amq_binding_cache_purge (
void);

static void
    amq_binding_cache_terminate (
void);

Bool
    amq_binding_animating = TRUE;       //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static qbyte
    s_amq_binding_count = 0;
/*  -------------------------------------------------------------------------
    amq_binding_new

    Type: Component method
    Creates and initialises a new amq_binding_t object, returns a
    reference to the created object.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

amq_binding_t *
    amq_binding_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_exchange_t * exchange,          //  Parent exchange
    char * routing_key,                 //  Bind to routing key
    icl_longstr_t * arguments,          //  Additional arguments
    Bool exclusive                      //  Queue is exclusive?
)
{
amq_federation_t
    *federation;
asl_field_list_t
    *field_list;
    amq_binding_t *
        self = NULL;                    //  Object reference

    self = amq_binding_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_BINDING_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_binding_show_);
#endif

self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
icl_atomic_inc32 ((volatile qbyte *) &s_amq_binding_count);

//
self->exchange = exchange;
self->queue_set = amq_queue_set_new ();
self->index_list = ipr_looseref_list_new ();
self->binding_mgt = amq_binding_mgt_new (exchange, self);
self->exclusive = exclusive;
icl_shortstr_cpy (self->routing_key, routing_key);

//  Store empty arguments as null to simplify comparisons
if (arguments && arguments->cur_size)
    self->arguments = icl_longstr_dup (arguments);

//  Get an index for the binding and complain if the index is full
self->index = ipr_index_insert (self->exchange->binding_index, self);
if (!self->index) {
    smt_log_print (amq_broker->alert_log,
        "E: too many bindings in %s exchange", exchange->name);
    self_destroy (&self);
}
// Store binding arguments in human readable form
field_list = asl_field_list_new (self->arguments);
assert (field_list);
asl_field_list_dump (field_list, self->arguments_str);
asl_field_list_destroy (&field_list);

//  Notify federation, if any, about new binding
federation = amq_federation_link (self->exchange->federation);
if (federation) {
    amq_federation_binding_created (federation,
        self->routing_key, self->arguments, self->exclusive);
    amq_federation_unlink (&federation);
}
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_binding_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_binding_annihilate_ (
    amq_binding_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
    int
        history_last;
#endif

amq_federation_t
    *federation;
    amq_binding_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_BINDING_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_BINDING_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_BINDING_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_BINDING_HISTORY_LENGTH] = self->links;
#endif

    AMQ_BINDING_ASSERT_SANE (self);
    amq_binding_remove_from_all_containers (self);

icl_atomic_dec32 ((volatile qbyte *) &s_amq_binding_count);

//
//  Notify federation, if any, about binding being destroyed
federation = amq_federation_link (self->exchange->federation);
if (federation) {
    amq_federation_binding_destroyed (federation,
        self->routing_key, self->arguments);
    amq_federation_unlink (&federation);
}
if (self->exchange->binding_index)
    ipr_index_delete (self->exchange->binding_index, self->index);

amq_binding_mgt_destroy (&self->binding_mgt);
amq_queue_set_destroy (&self->queue_set);
ipr_looseref_list_destroy (&self->index_list);
icl_longstr_destroy (&self->arguments);

}
/*  -------------------------------------------------------------------------
    amq_binding_bind_queue

    Type: Component method
    Accepts a amq_binding_t reference and returns zero in case of success,
    1 in case of errors.
    Attach queue to queue_set.  Called by parent exchange during queue bind.
    -------------------------------------------------------------------------
 */

int
    amq_binding_bind_queue (
    amq_binding_t * self,               //  Reference to object
    amq_queue_t * queue                 //  Queue to bind
)
{
    int
        rc = 0;                         //  Return code

AMQ_BINDING_ASSERT_SANE (self);
if (!self->zombie) {

//
if (!amq_queue_set_find (self->queue_set, queue))
    amq_queue_set_queue (self->queue_set, queue);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_unbind_queue

    Type: Component method
    Accepts a amq_binding_t reference and returns zero in case of success,
    1 in case of errors.
    Remove queue from queue_set.  Returns -1 if the binding is empty (has no
    queues) after this operation.  Called by parent exchange during queue
    unbind.
    -------------------------------------------------------------------------
 */

int
    amq_binding_unbind_queue (
    amq_binding_t * self,               //  Reference to object
    amq_queue_t * queue                 //  Queue to unbind
)
{
amq_queue_set_iter_t *
    iterator;
    int
        rc = 0;                         //  Return code

AMQ_BINDING_ASSERT_SANE (self);
if (!self->zombie) {

//
if (!self->zombie) {
    iterator = amq_queue_set_find (self->queue_set, queue);
    if (iterator)
        amq_queue_set_iter_destroy (&iterator);

    //  Signal to caller if binding is now empty
    if (amq_queue_set_count (self->queue_set) == 0)
        rc = -1;
}
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_collect

    Type: Component method
    Accepts a amq_binding_t reference and returns zero in case of success,
    1 in case of errors.
    Collect all queues for the binding into the caller's publish set.
    To avoid the same message being published multiple times to the same
    queue via different bindings, the exchane collects all queues for a
    message, sorts, and eliminates duplicates.  Returns new queue set
    size.  If queue set size reaches 75% of limit, prints warning.
    -------------------------------------------------------------------------
 */

int
    amq_binding_collect (
    amq_binding_t * self,               //  Reference to object
    amq_queue_t ** queue_set,           //  Queue set
    size_t set_size                     //  Queue set size
)
{
amq_queue_set_iter_t *
    iterator;
    int
        rc = 0;                         //  Return code

AMQ_BINDING_ASSERT_SANE (self);
if (!self->zombie) {

//
iterator = amq_queue_set_first (self->queue_set);
while (iterator) {
    if (set_size < AMQ_QUEUE_SET_MAX)
        queue_set [set_size++] = (amq_queue_t *) iterator->item;
    iterator = amq_queue_set_next (&iterator);
}
rc = set_size;
if (set_size > AMQ_QUEUE_SET_MAX * 75 / 100)
    smt_log_print (amq_broker->alert_log,
        "W: reaching AMQ_QUEUE_SET_MAX (at %d), please notify openamq-dev@imatix.com",
        AMQ_QUEUE_SET_MAX);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_binding_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_binding_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_binding_count (
void)
{
    qbyte
        count;                          //  Number of instances

count = (int) s_amq_binding_count;

    return (count);
}
/*  -------------------------------------------------------------------------
    amq_binding_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_binding_remove_from_all_containers (
    amq_binding_t * self                //  The item
)
{

amq_binding_list_remove (self);
}
/*  -------------------------------------------------------------------------
    amq_binding_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_binding_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_binding_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
if (self->list_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_binding zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
    if (self->history_last > AMQ_BINDING_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_BINDING_HISTORY_LENGTH;
        self->history_last %= AMQ_BINDING_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_BINDING_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_binding>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_binding_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_binding_destroy

    Type: Component method
    Destroys a amq_binding_t object. Takes the address of a
    amq_binding_t reference (a pointer to a pointer) and nullifies the
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
    amq_binding_destroy_ (
    amq_binding_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_binding_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_binding_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("amq_binding", "E: missing link on amq_binding object");
        amq_binding_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_binding_free_ ((amq_binding_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_binding_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_binding_t *
    amq_binding_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_binding_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_binding_cache_initialise ();

self = (amq_binding_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_binding_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_binding_free

    Type: Component method
    Freess a amq_binding_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_binding_free_ (
    amq_binding_t * self,               //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BINDING_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BINDING_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BINDING_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_BINDING_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (amq_binding_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_binding_t));
        self->object_tag = AMQ_BINDING_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_binding_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_binding_t *
    amq_binding_link_ (
    amq_binding_t * self,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
    int
        history_last;
#endif

    if (self) {
        AMQ_BINDING_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BINDING_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BINDING_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BINDING_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_BINDING_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_binding_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_binding_unlink_ (
    amq_binding_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
    int
        history_last;
#endif

    amq_binding_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        AMQ_BINDING_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("amq_binding", "E: missing link on amq_binding object");
            amq_binding_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BINDING_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BINDING_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BINDING_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_BINDING_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_binding_annihilate_ (self_p, file, line);
        amq_binding_free_ ((amq_binding_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_binding_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_binding_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_binding_t));
icl_system_register (amq_binding_cache_purge, amq_binding_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_binding_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_binding_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_binding_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_binding_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_binding_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_binding_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_binding_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_binding_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_binding_new_in_scope_ (
    amq_binding_t * * self_p,           //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_exchange_t * exchange,          //  Parent exchange
    char * routing_key,                 //  Bind to routing key
    icl_longstr_t * arguments,          //  Additional arguments
    Bool exclusive                      //  Queue is exclusive?
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_binding_new_ (file,line,exchange,routing_key,arguments,exclusive);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_binding_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_binding_version_start    = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_binding_component        = "amq_binding ";
char *EMBED__amq_binding_version          = "1.0 ";
char *EMBED__amq_binding_copyright        = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_binding_filename         = "amq_binding.icl ";
char *EMBED__amq_binding_builddate        = "2010/10/06 ";
char *EMBED__amq_binding_version_end      = "VeRsIoNeNd:ipc";

