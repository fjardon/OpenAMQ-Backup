/*---------------------------------------------------------------------------
    amq_consumer.c - amq_consumer component

This class implements a polymorphic consumer. This is an object that
ties the channel to the queue, and envelopes class-specific consumers
for Basic, File, and Stream content classes.
    Generated from amq_consumer.icl by icl_gen using GSL/4.
    
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
#include "amq_consumer.h"               //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_consumer_t

//  Shorthands for class methods                                               

#define self_new            amq_consumer_new
#define self_annihilate     amq_consumer_annihilate
#define self_content_hold   amq_consumer_content_hold
#define self_content_release  amq_consumer_content_release
#define self_selftest       amq_consumer_selftest
#define self_count          amq_consumer_count
#define self_remove_from_all_containers  amq_consumer_remove_from_all_containers
#define self_show           amq_consumer_show
#define self_terminate      amq_consumer_terminate
#define self_destroy        amq_consumer_destroy
#define self_alloc          amq_consumer_alloc
#define self_free           amq_consumer_free
#define self_link           amq_consumer_link
#define self_unlink         amq_consumer_unlink
#define self_cache_initialise  amq_consumer_cache_initialise
#define self_cache_purge    amq_consumer_cache_purge
#define self_cache_terminate  amq_consumer_cache_terminate
#define self_animate        amq_consumer_animate
#define self_new_in_scope   amq_consumer_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_NEW))
static icl_stats_t *s_amq_consumer_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_DESTROY))
static icl_stats_t *s_amq_consumer_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_CONTENT_HOLD))
static icl_stats_t *s_amq_consumer_content_hold_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_CONTENT_RELEASE))
static icl_stats_t *s_amq_consumer_content_release_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_SELFTEST))
static icl_stats_t *s_amq_consumer_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_COUNT))
static icl_stats_t *s_amq_consumer_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_amq_consumer_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_SHOW))
static icl_stats_t *s_amq_consumer_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_TERMINATE))
static icl_stats_t *s_amq_consumer_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_DESTROY_PUBLIC))
static icl_stats_t *s_amq_consumer_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_ALLOC))
static icl_stats_t *s_amq_consumer_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_FREE))
static icl_stats_t *s_amq_consumer_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_LINK))
static icl_stats_t *s_amq_consumer_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_UNLINK))
static icl_stats_t *s_amq_consumer_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_CACHE_INITIALISE))
static icl_stats_t *s_amq_consumer_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_CACHE_PURGE))
static icl_stats_t *s_amq_consumer_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_CACHE_TERMINATE))
static icl_stats_t *s_amq_consumer_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_ANIMATE))
static icl_stats_t *s_amq_consumer_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_NEW_IN_SCOPE))
static icl_stats_t *s_amq_consumer_new_in_scope_stats = NULL;
#endif
#define amq_consumer_annihilate(self)   amq_consumer_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_consumer_annihilate_ (
amq_consumer_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_consumer_alloc()            amq_consumer_alloc_ (__FILE__, __LINE__)
static amq_consumer_t *
    amq_consumer_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_consumer_free(self)         amq_consumer_free_ (self, __FILE__, __LINE__)
static void
    amq_consumer_free_ (
amq_consumer_t * self,                  //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_consumer_cache_initialise (
void);

static void
    amq_consumer_cache_purge (
void);

static void
    amq_consumer_cache_terminate (
void);

Bool
    amq_consumer_animating = TRUE;      //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static qbyte
    s_amq_consumer_count = 0;
/*  -------------------------------------------------------------------------
    amq_consumer_new

    Type: Component method
    Creates and initialises a new amq_consumer_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    Initialises the new item to be a valid list item.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_server_connection_t * connection,   //  Parent connection
    amq_server_channel_t * channel,     //  Channel for reply
    amq_queue_t * queue,                //  Parent queue
    amq_server_method_t * method        //  Consume method
)
{
#define table connection->consumer_table
#define key self->tag
amq_server_basic_consume_t
    *basic_consume;
    amq_consumer_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_NEW))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" connection=\"%pp\""
" channel=\"%pp\""
" queue=\"%pp\""
" method=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, connection, channel, queue, method);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_NEW))
    icl_trace_record (NULL, amq_consumer_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_NEW))
    icl_stats_inc ("amq_consumer_new", &s_amq_consumer_new_stats);
#endif

    self = amq_consumer_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CONSUMER_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_consumer_show_);
#endif

self->by_channel_next = self;
self->by_channel_prev = self;
self->by_channel_head = NULL;
self->by_queue_next = self;
self->by_queue_prev = self;
self->by_queue_head = NULL;
self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
icl_atomic_inc32 ((volatile qbyte *) &s_amq_consumer_count);

//

//
self->channel = amq_server_channel_link (channel);
self->queue   = amq_queue_link (queue);

//  Interface to console
self->mgt_connection_queue = amq_connection_queue_new (channel->mgt_connection, self);
self->mgt_queue_connection = amq_queue_connection_new (queue, self);

basic_consume = &method->payload.basic_consume;
self->no_local       = basic_consume->no_local;
self->no_ack         = basic_consume->no_ack;
self->exclusive      = basic_consume->exclusive;
self->consumer_basic = amq_consumer_basic_new (self);

icl_shortstr_cpy (self->tag, basic_consume->consumer_tag);
if (strnull (self->tag))
    icl_shortstr_fmt (self->tag, "%d",
        icl_atomic_inc32 ((volatile qbyte *) &(connection->consumer_tag)));
if (table && self && amq_consumer_table_insert (table, key, self))
    amq_consumer_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_NEW))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_NEW))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" connection=\"%pp\""
" channel=\"%pp\""
" queue=\"%pp\""
" method=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, connection, channel, queue, method, self);
#endif


    return (self);
}
#undef table
#undef key
/*  -------------------------------------------------------------------------
    amq_consumer_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_annihilate_ (
    amq_consumer_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
    int
        history_last;
#endif

    amq_consumer_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_DESTROY))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_DESTROY))
    icl_trace_record (NULL, amq_consumer_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_DESTROY))
    icl_stats_inc ("amq_consumer_annihilate", &s_amq_consumer_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = self->links;
#endif

    AMQ_CONSUMER_ASSERT_SANE (self);
    amq_consumer_remove_from_all_containers (self);

icl_atomic_dec32 ((volatile qbyte *) &s_amq_consumer_count);

amq_server_channel_unlink    (&self->channel);
amq_queue_unlink             (&self->queue);

amq_content_basic_unlink     (&self->pending_content);
amq_connection_queue_destroy (&self->mgt_connection_queue);
amq_queue_connection_destroy (&self->mgt_queue_connection);
amq_consumer_basic_destroy   (&self->consumer_basic);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_DESTROY))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_DESTROY))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_destroy_finish"
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
    amq_consumer_content_hold

    Type: Component method
    Accepts a amq_consumer_t reference and returns zero in case of success,
    1 in case of errors.
    Holds onto a content.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_content_hold (
    amq_consumer_t * self,              //  Reference to object
    amq_content_basic_t * content       //  Not documented
)
{

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_CONTENT_HOLD))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_content_hold_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_CONTENT_HOLD))
    icl_trace_record (NULL, amq_consumer_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_CONTENT_HOLD))
    icl_stats_inc ("amq_consumer_content_hold", &s_amq_consumer_content_hold_stats);
#endif


AMQ_CONSUMER_ASSERT_SANE (self);
if (!self->zombie) {

//
assert (!self->pending_content);
self->pending_content = amq_content_basic_link (content);
}
else
    rc = -1;                        //  Return error on zombie object.


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_CONTENT_HOLD))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_CONTENT_HOLD))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_content_hold_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_consumer_content_release

    Type: Component method
    Accepts a amq_consumer_t reference and returns zero in case of success,
    1 in case of errors.
    Releases its pending content, if any.  Returns TRUE if a content was
    released, else FALSE.
    -------------------------------------------------------------------------
 */

int
    amq_consumer_content_release (
    amq_consumer_t * self               //  Reference to object
)
{

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_CONTENT_RELEASE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_content_release_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_CONTENT_RELEASE))
    icl_trace_record (NULL, amq_consumer_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_CONTENT_RELEASE))
    icl_stats_inc ("amq_consumer_content_release", &s_amq_consumer_content_release_stats);
#endif


AMQ_CONSUMER_ASSERT_SANE (self);
if (!self->zombie) {

//
if (self->pending_content) {
    amq_content_basic_unlink (&self->pending_content);
    rc = TRUE;
}
else
    rc = FALSE;
}
else
    rc = -1;                        //  Return error on zombie object.


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_CONTENT_RELEASE))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_CONTENT_RELEASE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_content_release_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_consumer_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_SELFTEST))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_SELFTEST))
    icl_trace_record (NULL, amq_consumer_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_SELFTEST))
    icl_stats_inc ("amq_consumer_selftest", &s_amq_consumer_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_SELFTEST))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_SELFTEST))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_selftest_finish"
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
    amq_consumer_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_consumer_count (
void)
{
    qbyte
        count;                          //  Number of instances

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_COUNT))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_count_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_COUNT))
    icl_trace_record (NULL, amq_consumer_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_COUNT))
    icl_stats_inc ("amq_consumer_count", &s_amq_consumer_count_stats);
#endif

count = (int) s_amq_consumer_count;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_COUNT))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_COUNT))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_count_finish"
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
    amq_consumer_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_consumer_remove_from_all_containers (
    amq_consumer_t * self               //  The itemThe itemThe item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_consumer_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("amq_consumer_remove_from_all_containers", &s_amq_consumer_remove_from_all_containers_stats);
#endif

AMQ_CONSUMER_ASSERT_SANE (self);
amq_consumer_table_remove (self);
amq_consumer_by_queue_remove (self);
amq_consumer_by_channel_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_remove_from_all_containers_finish"
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
    amq_consumer_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_consumer_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_SHOW))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_SHOW))
    icl_trace_record (NULL, amq_consumer_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_SHOW))
    icl_stats_inc ("amq_consumer_show", &s_amq_consumer_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
if (self->by_queue_head)
   container_links++;
if (self->by_channel_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_consumer zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
    if (self->history_last > AMQ_CONSUMER_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_CONSUMER_HISTORY_LENGTH;
        self->history_last %= AMQ_CONSUMER_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_CONSUMER_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_consumer>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_SHOW))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_SHOW))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_show_finish"
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
    amq_consumer_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_TERMINATE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_TERMINATE))
    icl_trace_record (NULL, amq_consumer_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_TERMINATE))
    icl_stats_inc ("amq_consumer_terminate", &s_amq_consumer_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_TERMINATE))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_TERMINATE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_terminate_finish"
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
    amq_consumer_destroy

    Type: Component method
    Destroys a amq_consumer_t object. Takes the address of a
    amq_consumer_t reference (a pointer to a pointer) and nullifies the
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
    amq_consumer_destroy_ (
    amq_consumer_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_consumer_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_DESTROY_PUBLIC))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_consumer_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_DESTROY_PUBLIC))
    icl_stats_inc ("amq_consumer_destroy", &s_amq_consumer_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_consumer_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on amq_consumer object");
        amq_consumer_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_consumer_free_ ((amq_consumer_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_DESTROY_PUBLIC))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_destroy_public_finish"
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
    amq_consumer_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_consumer_t *
    amq_consumer_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_consumer_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_ALLOC))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_ALLOC))
    icl_trace_record (NULL, amq_consumer_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_ALLOC))
    icl_stats_inc ("amq_consumer_alloc", &s_amq_consumer_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_consumer_cache_initialise ();

self = (amq_consumer_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_consumer_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_ALLOC))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_ALLOC))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_alloc_finish"
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
    amq_consumer_free

    Type: Component method
    Freess a amq_consumer_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_free_ (
    amq_consumer_t * self,              //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_FREE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_FREE))
    icl_trace_record (NULL, amq_consumer_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_FREE))
    icl_stats_inc ("amq_consumer_free", &s_amq_consumer_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (amq_consumer_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_consumer_t));
        self->object_tag = AMQ_CONSUMER_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_FREE))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_FREE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_free_finish"
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
    amq_consumer_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_consumer_t *
    amq_consumer_link_ (
    amq_consumer_t * self,              //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_LINK))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_LINK))
    icl_trace_record (NULL, amq_consumer_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_LINK))
    icl_stats_inc ("amq_consumer_link", &s_amq_consumer_link_stats);
#endif

    if (self) {
        AMQ_CONSUMER_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_LINK))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_LINK))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_link_finish"
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
    amq_consumer_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_consumer_unlink_ (
    amq_consumer_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
    int
        history_last;
#endif

    amq_consumer_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_UNLINK))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_UNLINK))
    icl_trace_record (NULL, amq_consumer_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_UNLINK))
    icl_stats_inc ("amq_consumer_unlink", &s_amq_consumer_unlink_stats);
#endif

    if (self) {
        AMQ_CONSUMER_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_consumer object");
            amq_consumer_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_CONSUMER_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_consumer_annihilate_ (self_p, file, line);
        amq_consumer_free_ ((amq_consumer_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_UNLINK))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_UNLINK))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_unlink_finish"
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
    amq_consumer_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_CACHE_INITIALISE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_consumer_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_CACHE_INITIALISE))
    icl_stats_inc ("amq_consumer_cache_initialise", &s_amq_consumer_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_consumer_t));
icl_system_register (amq_consumer_cache_purge, amq_consumer_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_CACHE_INITIALISE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_cache_initialise_finish"
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
    amq_consumer_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_CACHE_PURGE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_CACHE_PURGE))
    icl_trace_record (NULL, amq_consumer_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_CACHE_PURGE))
    icl_stats_inc ("amq_consumer_cache_purge", &s_amq_consumer_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_CACHE_PURGE))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_CACHE_PURGE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_cache_purge_finish"
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
    amq_consumer_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_CACHE_TERMINATE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_consumer_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_CACHE_TERMINATE))
    icl_stats_inc ("amq_consumer_cache_terminate", &s_amq_consumer_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_CACHE_TERMINATE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_cache_terminate_finish"
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
    amq_consumer_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_consumer_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_ANIMATE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_ANIMATE))
    icl_trace_record (NULL, amq_consumer_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_ANIMATE))
    icl_stats_inc ("amq_consumer_animate", &s_amq_consumer_animate_stats);
#endif

amq_consumer_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_ANIMATE))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_ANIMATE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_animate_finish"
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
    amq_consumer_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_new_in_scope_ (
    amq_consumer_t * * self_p,          //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_server_connection_t * connection,   //  Parent connection
    amq_server_channel_t * channel,     //  Channel for reply
    amq_queue_t * queue,                //  Parent queue
    amq_server_method_t * method        //  Consume method
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_NEW_IN_SCOPE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" connection=\"%pp\""
" channel=\"%pp\""
" queue=\"%pp\""
" method=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, connection, channel, queue, method);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_consumer_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER)  ||  defined (BASE_STATS_AMQ_CONSUMER_NEW_IN_SCOPE))
    icl_stats_inc ("amq_consumer_new_in_scope", &s_amq_consumer_new_in_scope_stats);
#endif

*self_p = amq_consumer_new_ (file,line,connection,channel,queue,method);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_consumer_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_consumer_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER)   || defined (BASE_ANIMATE_AMQ_CONSUMER_NEW_IN_SCOPE))
    if (amq_consumer_animating)
        icl_console_print ("<amq_consumer_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" connection=\"%pp\""
" channel=\"%pp\""
" queue=\"%pp\""
" method=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, connection, channel, queue, method, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER)   || defined (BASE_TRACE_AMQ_CONSUMER_NEW)   || defined (BASE_TRACE_AMQ_CONSUMER_DESTROY)   || defined (BASE_TRACE_AMQ_CONSUMER_CONTENT_HOLD)   || defined (BASE_TRACE_AMQ_CONSUMER_CONTENT_RELEASE)   || defined (BASE_TRACE_AMQ_CONSUMER_SELFTEST)   || defined (BASE_TRACE_AMQ_CONSUMER_COUNT)   || defined (BASE_TRACE_AMQ_CONSUMER_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_CONSUMER_SHOW)   || defined (BASE_TRACE_AMQ_CONSUMER_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSUMER_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CONSUMER_ALLOC)   || defined (BASE_TRACE_AMQ_CONSUMER_FREE)   || defined (BASE_TRACE_AMQ_CONSUMER_LINK)   || defined (BASE_TRACE_AMQ_CONSUMER_UNLINK)   || defined (BASE_TRACE_AMQ_CONSUMER_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CONSUMER_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CONSUMER_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSUMER_ANIMATE)   || defined (BASE_TRACE_AMQ_CONSUMER_NEW_IN_SCOPE) )
void
amq_consumer_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "content hold"; break;
        case 4: method_name = "content release"; break;
        case 5: method_name = "selftest"; break;
        case 6: method_name = "count"; break;
        case 7: method_name = "remove from all containers"; break;
        case 8: method_name = "show"; break;
        case 9: method_name = "terminate"; break;
        case 10: method_name = "destroy public"; break;
        case 11: method_name = "alloc"; break;
        case 12: method_name = "free"; break;
        case 13: method_name = "link"; break;
        case 14: method_name = "unlink"; break;
        case 15: method_name = "cache initialise"; break;
        case 16: method_name = "cache purge"; break;
        case 17: method_name = "cache terminate"; break;
        case 18: method_name = "animate"; break;
        case 19: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_consumer %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_consumer_version_start   = "VeRsIoNsTaRt:ipc";
char *amq_consumer_component       = "amq_consumer ";
char *amq_consumer_version         = "1.0 ";
char *amq_consumer_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_consumer_filename        = "amq_consumer.icl ";
char *amq_consumer_builddate       = "2010/10/06 ";
char *amq_consumer_version_end     = "VeRsIoNeNd:ipc";

