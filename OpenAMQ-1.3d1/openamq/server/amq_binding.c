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
#define self_animate        amq_binding_animate
#define self_new_in_scope   amq_binding_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_NEW))
static icl_stats_t *s_amq_binding_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_DESTROY))
static icl_stats_t *s_amq_binding_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_BIND_QUEUE))
static icl_stats_t *s_amq_binding_bind_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_UNBIND_QUEUE))
static icl_stats_t *s_amq_binding_unbind_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_COLLECT))
static icl_stats_t *s_amq_binding_collect_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_SELFTEST))
static icl_stats_t *s_amq_binding_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_COUNT))
static icl_stats_t *s_amq_binding_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_amq_binding_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_SHOW))
static icl_stats_t *s_amq_binding_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_TERMINATE))
static icl_stats_t *s_amq_binding_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_DESTROY_PUBLIC))
static icl_stats_t *s_amq_binding_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_ALLOC))
static icl_stats_t *s_amq_binding_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_FREE))
static icl_stats_t *s_amq_binding_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_LINK))
static icl_stats_t *s_amq_binding_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_UNLINK))
static icl_stats_t *s_amq_binding_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_CACHE_INITIALISE))
static icl_stats_t *s_amq_binding_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_CACHE_PURGE))
static icl_stats_t *s_amq_binding_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_CACHE_TERMINATE))
static icl_stats_t *s_amq_binding_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_ANIMATE))
static icl_stats_t *s_amq_binding_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_NEW_IN_SCOPE))
static icl_stats_t *s_amq_binding_new_in_scope_stats = NULL;
#endif
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_NEW))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" routing_key=\"%s\""
" arguments=\"%pp\""
" exclusive=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, exchange, routing_key, arguments, exclusive);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_NEW))
    icl_trace_record (NULL, amq_binding_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_NEW))
    icl_stats_inc ("amq_binding_new", &s_amq_binding_new_stats);
#endif

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
self->exchange   = exchange;
self->queue_list = amq_queue_list_new ();
self->index_list = ipr_looseref_list_new ();
self->binding_mgt = amq_binding_mgt_new (exchange, self);
self->exclusive  = exclusive;
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_NEW))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_NEW))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" routing_key=\"%s\""
" arguments=\"%pp\""
" exclusive=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, exchange, routing_key, arguments, exclusive, self);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_DESTROY))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_DESTROY))
    icl_trace_record (NULL, amq_binding_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_DESTROY))
    icl_stats_inc ("amq_binding_annihilate", &s_amq_binding_annihilate_stats);
#endif

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

amq_binding_mgt_destroy   (&self->binding_mgt);
amq_queue_list_destroy    (&self->queue_list);
ipr_looseref_list_destroy (&self->index_list);
icl_longstr_destroy       (&self->arguments);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_DESTROY))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_DESTROY))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_bind_queue

    Type: Component method
    Accepts a amq_binding_t reference and returns zero in case of success,
    1 in case of errors.
    Attach queue to queue_list.  Called by parent exchange during queue bind.
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_BIND_QUEUE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_bind_queue_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_BIND_QUEUE))
    icl_trace_record (NULL, amq_binding_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_BIND_QUEUE))
    icl_stats_inc ("amq_binding_bind_queue", &s_amq_binding_bind_queue_stats);
#endif

AMQ_BINDING_ASSERT_SANE (self);
if (!self->zombie) {

//
if (!amq_queue_list_find (self->queue_list, queue))
    amq_queue_list_queue (self->queue_list, queue);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_BIND_QUEUE))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_BIND_QUEUE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_bind_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_unbind_queue

    Type: Component method
    Accepts a amq_binding_t reference and returns zero in case of success,
    1 in case of errors.
    Remove queue from queue_list.  Returns -1 if the binding is empty (has no
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
amq_queue_list_iter_t *
    iterator;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_UNBIND_QUEUE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_unbind_queue_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_UNBIND_QUEUE))
    icl_trace_record (NULL, amq_binding_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_UNBIND_QUEUE))
    icl_stats_inc ("amq_binding_unbind_queue", &s_amq_binding_unbind_queue_stats);
#endif

AMQ_BINDING_ASSERT_SANE (self);
if (!self->zombie) {

//
if (!self->zombie) {
    iterator = amq_queue_list_find (self->queue_list, queue);
    if (iterator)
        amq_queue_list_iter_destroy (&iterator);

    //  Signal to caller if binding is now empty
    if (amq_queue_list_count (self->queue_list) == 0)
        rc = -1;
}
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_UNBIND_QUEUE))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_UNBIND_QUEUE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_unbind_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, rc);
#endif


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
amq_queue_list_iter_t *
    iterator;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_COLLECT))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_collect_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue_set=\"%pp\""
" set_size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue_set, set_size);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_COLLECT))
    icl_trace_record (NULL, amq_binding_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_COLLECT))
    icl_stats_inc ("amq_binding_collect", &s_amq_binding_collect_stats);
#endif

AMQ_BINDING_ASSERT_SANE (self);
if (!self->zombie) {

//
iterator = amq_queue_list_first (self->queue_list);
while (iterator) {
    if (set_size < AMQ_QUEUE_SET_MAX)
        queue_set [set_size++] = (amq_queue_t *) iterator->item;
    iterator = amq_queue_list_next (&iterator);
}
rc = set_size;
if (set_size > AMQ_QUEUE_SET_MAX * 75 / 100)
    smt_log_print (amq_broker->alert_log,
        "W: reaching AMQ_QUEUE_SET_MAX (at %d), please notify openamq-dev@imatix.com", 
        AMQ_QUEUE_SET_MAX);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_COLLECT))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_COLLECT))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_collect_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue_set=\"%pp\""
" set_size=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue_set, set_size, rc);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_SELFTEST))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_SELFTEST))
    icl_trace_record (NULL, amq_binding_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_SELFTEST))
    icl_stats_inc ("amq_binding_selftest", &s_amq_binding_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_SELFTEST))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_SELFTEST))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_selftest_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_COUNT))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_count_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_COUNT))
    icl_trace_record (NULL, amq_binding_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_COUNT))
    icl_stats_inc ("amq_binding_count", &s_amq_binding_count_stats);
#endif

count = (int) s_amq_binding_count;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_COUNT))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_COUNT))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_count_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" count=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, count);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_remove_from_all_containers_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_binding_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("amq_binding_remove_from_all_containers", &s_amq_binding_remove_from_all_containers_stats);
#endif

amq_binding_list_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_remove_from_all_containers_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

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


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_SHOW))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_show_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_SHOW))
    icl_trace_record (NULL, amq_binding_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_SHOW))
    icl_stats_inc ("amq_binding_show", &s_amq_binding_show_stats);
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_SHOW))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_SHOW))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_show_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_TERMINATE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_TERMINATE))
    icl_trace_record (NULL, amq_binding_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_TERMINATE))
    icl_stats_inc ("amq_binding_terminate", &s_amq_binding_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_TERMINATE))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_TERMINATE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_DESTROY_PUBLIC))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_binding_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_DESTROY_PUBLIC))
    icl_stats_inc ("amq_binding_destroy", &s_amq_binding_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_binding_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on amq_binding object");
        amq_binding_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_binding_free_ ((amq_binding_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_DESTROY_PUBLIC))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_ALLOC))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_ALLOC))
    icl_trace_record (NULL, amq_binding_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_ALLOC))
    icl_stats_inc ("amq_binding_alloc", &s_amq_binding_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_binding_cache_initialise ();

self = (amq_binding_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_binding_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_ALLOC))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_ALLOC))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, self);
#endif


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


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_FREE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_FREE))
    icl_trace_record (NULL, amq_binding_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_FREE))
    icl_stats_inc ("amq_binding_free", &s_amq_binding_free_stats);
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_FREE))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_FREE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_LINK))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_link_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_LINK))
    icl_trace_record (NULL, amq_binding_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_LINK))
    icl_stats_inc ("amq_binding_link", &s_amq_binding_link_stats);
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_LINK))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_LINK))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_link_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_UNLINK))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_unlink_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_UNLINK))
    icl_trace_record (NULL, amq_binding_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_UNLINK))
    icl_stats_inc ("amq_binding_unlink", &s_amq_binding_unlink_stats);
#endif

    if (self) {
        AMQ_BINDING_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_binding object");
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_UNLINK))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_UNLINK))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_unlink_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_CACHE_INITIALISE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_binding_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_CACHE_INITIALISE))
    icl_stats_inc ("amq_binding_cache_initialise", &s_amq_binding_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_binding_t));
icl_system_register (amq_binding_cache_purge, amq_binding_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_CACHE_INITIALISE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_cache_initialise_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_CACHE_PURGE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_PURGE))
    icl_trace_record (NULL, amq_binding_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_CACHE_PURGE))
    icl_stats_inc ("amq_binding_cache_purge", &s_amq_binding_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_PURGE))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_CACHE_PURGE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_cache_purge_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_CACHE_TERMINATE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_binding_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_CACHE_TERMINATE))
    icl_stats_inc ("amq_binding_cache_terminate", &s_amq_binding_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_CACHE_TERMINATE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_cache_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_binding_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_ANIMATE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_animate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_ANIMATE))
    icl_trace_record (NULL, amq_binding_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_ANIMATE))
    icl_stats_inc ("amq_binding_animate", &s_amq_binding_animate_stats);
#endif

amq_binding_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_ANIMATE))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_ANIMATE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_animate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING)  ||  defined (BASE_ANIMATE_AMQ_BINDING_NEW_IN_SCOPE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" routing_key=\"%s\""
" arguments=\"%pp\""
" exclusive=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, exchange, routing_key, arguments, exclusive);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_binding_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING)  ||  defined (BASE_STATS_AMQ_BINDING_NEW_IN_SCOPE))
    icl_stats_inc ("amq_binding_new_in_scope", &s_amq_binding_new_in_scope_stats);
#endif

*self_p = amq_binding_new_ (file,line,exchange,routing_key,arguments,exclusive);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_binding_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_binding_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING)   || defined (BASE_ANIMATE_AMQ_BINDING_NEW_IN_SCOPE))
    if (amq_binding_animating)
        icl_console_print ("<amq_binding_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" routing_key=\"%s\""
" arguments=\"%pp\""
" exclusive=\"%i\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, exchange, routing_key, arguments, exclusive, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_NEW)   || defined (BASE_TRACE_AMQ_BINDING_DESTROY)   || defined (BASE_TRACE_AMQ_BINDING_BIND_QUEUE)   || defined (BASE_TRACE_AMQ_BINDING_UNBIND_QUEUE)   || defined (BASE_TRACE_AMQ_BINDING_COLLECT)   || defined (BASE_TRACE_AMQ_BINDING_SELFTEST)   || defined (BASE_TRACE_AMQ_BINDING_COUNT)   || defined (BASE_TRACE_AMQ_BINDING_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_BINDING_SHOW)   || defined (BASE_TRACE_AMQ_BINDING_TERMINATE)   || defined (BASE_TRACE_AMQ_BINDING_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_BINDING_ALLOC)   || defined (BASE_TRACE_AMQ_BINDING_FREE)   || defined (BASE_TRACE_AMQ_BINDING_LINK)   || defined (BASE_TRACE_AMQ_BINDING_UNLINK)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_BINDING_ANIMATE)   || defined (BASE_TRACE_AMQ_BINDING_NEW_IN_SCOPE) )
void
amq_binding_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "bind queue"; break;
        case 4: method_name = "unbind queue"; break;
        case 5: method_name = "collect"; break;
        case 6: method_name = "selftest"; break;
        case 7: method_name = "count"; break;
        case 8: method_name = "remove from all containers"; break;
        case 9: method_name = "show"; break;
        case 10: method_name = "terminate"; break;
        case 11: method_name = "destroy public"; break;
        case 12: method_name = "alloc"; break;
        case 13: method_name = "free"; break;
        case 14: method_name = "link"; break;
        case 15: method_name = "unlink"; break;
        case 16: method_name = "cache initialise"; break;
        case 17: method_name = "cache purge"; break;
        case 18: method_name = "cache terminate"; break;
        case 19: method_name = "animate"; break;
        case 20: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_binding %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_binding_version_start    = "VeRsIoNsTaRt:ipc";
char *amq_binding_component        = "amq_binding ";
char *amq_binding_version          = "1.0 ";
char *amq_binding_copyright        = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_binding_filename         = "amq_binding.icl ";
char *amq_binding_builddate        = "2010/10/06 ";
char *amq_binding_version_end      = "VeRsIoNeNd:ipc";

