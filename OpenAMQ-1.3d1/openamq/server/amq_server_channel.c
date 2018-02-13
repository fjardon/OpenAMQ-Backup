/*---------------------------------------------------------------------------
    amq_server_channel.c - amq_server_channel component

This class implements the AMQ server channel class.  The channel holds
a set of consumers managed both as a list and as a lookup table.  The
maximum number of consumers per channel is set at compile time.

Channel flow control: each channel gets a credit window when it gets a
consumer.  This window defines the maximum size of its flow queue, the
number of contents it has received from a queue but not yet handed to
SMT.  When the channel receives a content from a queue, it spends a
credit.  When it passes a content to SMT it earns a credit.  Queues
check the credit to decide whether or not to use the channel's consumers.
    Generated from amq_server_channel.icl by smt_object_gen using GSL/4.
    
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
#include "amq_server_channel.h"         //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_server_channel_t

//  Shorthands for class methods                                               

#define self_new            amq_server_channel_new
#define self_annihilate     amq_server_channel_annihilate
#define self_free           amq_server_channel_free
#define self_flow           amq_server_channel_flow
#define self_consume        amq_server_channel_consume
#define self_ack            amq_server_channel_ack
#define self_earn           amq_server_channel_earn
#define self_cancel         amq_server_channel_cancel
#define self_selftest       amq_server_channel_selftest
#define self_initialise     amq_server_channel_initialise
#define self_spend          amq_server_channel_spend
#define self_error          amq_server_channel_error
#define self_remove_from_all_containers  amq_server_channel_remove_from_all_containers
#define self_show           amq_server_channel_show
#define self_destroy        amq_server_channel_destroy
#define self_unlink         amq_server_channel_unlink
#define self_animate        amq_server_channel_animate
#define self_terminate      amq_server_channel_terminate
#define self_alloc          amq_server_channel_alloc
#define self_link           amq_server_channel_link
#define self_cache_initialise  amq_server_channel_cache_initialise
#define self_cache_purge    amq_server_channel_cache_purge
#define self_cache_terminate  amq_server_channel_cache_terminate
#define self_new_in_scope   amq_server_channel_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_NEW))
static icl_stats_t *s_amq_server_channel_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_DESTROY))
static icl_stats_t *s_amq_server_channel_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_FREE))
static icl_stats_t *s_amq_server_channel_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_FLOW))
static icl_stats_t *s_amq_server_channel_flow_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_CONSUME))
static icl_stats_t *s_amq_server_channel_consume_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_ACK))
static icl_stats_t *s_amq_server_channel_ack_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_EARN))
static icl_stats_t *s_amq_server_channel_earn_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_CANCEL))
static icl_stats_t *s_amq_server_channel_cancel_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_SELFTEST))
static icl_stats_t *s_amq_server_channel_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_INITIALISE))
static icl_stats_t *s_amq_server_channel_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_SPEND))
static icl_stats_t *s_amq_server_channel_spend_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_ERROR))
static icl_stats_t *s_amq_server_channel_error_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_amq_server_channel_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_SHOW))
static icl_stats_t *s_amq_server_channel_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_DESTROY_PUBLIC))
static icl_stats_t *s_amq_server_channel_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_UNLINK))
static icl_stats_t *s_amq_server_channel_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_ANIMATE))
static icl_stats_t *s_amq_server_channel_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_TERMINATE))
static icl_stats_t *s_amq_server_channel_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_ALLOC))
static icl_stats_t *s_amq_server_channel_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_LINK))
static icl_stats_t *s_amq_server_channel_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_CACHE_INITIALISE))
static icl_stats_t *s_amq_server_channel_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_CACHE_PURGE))
static icl_stats_t *s_amq_server_channel_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_CACHE_TERMINATE))
static icl_stats_t *s_amq_server_channel_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_NEW_IN_SCOPE))
static icl_stats_t *s_amq_server_channel_new_in_scope_stats = NULL;
#endif
#define amq_server_channel_annihilate(self)  amq_server_channel_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_server_channel_annihilate_ (
amq_server_channel_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_server_channel_initialise (
void);

#define amq_server_channel_alloc()      amq_server_channel_alloc_ (__FILE__, __LINE__)
static amq_server_channel_t *
    amq_server_channel_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_server_channel_cache_initialise (
void);

static void
    amq_server_channel_cache_purge (
void);

static void
    amq_server_channel_cache_terminate (
void);

Bool
    amq_server_channel_animating = TRUE;  //  Animation enabled by default
static Bool
    s_amq_server_channel_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_server_channel_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static volatile qbyte
    s_channel_id_seq_lo,                //  Next channel id
    s_channel_id_seq_hi;                //  High part (64-bits)
/*  -------------------------------------------------------------------------
    amq_server_channel_new

    Type: Component method
    Creates and initialises a new amq_server_channel_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

amq_server_channel_t *
    amq_server_channel_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_server_channel_table_t * table,   //  Table to insert into
    amq_server_connection_t * connection,   //  Parent connection
    dbyte number                        //  Channel number
)
{
#define key number
qbyte
    seq_lo,
    seq_hi;
    amq_server_channel_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_NEW))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" connection=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, connection);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_NEW))
    icl_trace_record (NULL, amq_server_channel_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_NEW))
    icl_stats_inc ("amq_server_channel_new", &s_amq_server_channel_new_stats);
#endif

if (!s_amq_server_channel_active)
    self_initialise ();
    self = amq_server_channel_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_SERVER_CHANNEL_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_server_channel_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->thread = amq_server_channel_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->active = TRUE;

//
self->connection = amq_server_connection_link (connection);
self->number = number;

//  Get 64-bit channel id, no wraparound handling
seq_lo = icl_atomic_inc32 (&s_channel_id_seq_lo);
if (seq_lo == 0)
    seq_hi = icl_atomic_inc32 (&s_channel_id_seq_hi);
else
    seq_hi = s_channel_id_seq_hi;
icl_shortstr_fmt (self->id, "%x-%x", seq_hi, seq_lo);

self->consumer_list = amq_consumer_by_channel_new ();
if (amq_broker)                     //  Null during self-testing
    self->mgt_connection = amq_connection_new (amq_broker, self);
if (table && self && amq_server_channel_table_insert (table, key, self))
    amq_server_channel_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_NEW))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_NEW))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" connection=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, connection, self);
#endif


    return (self);
}
#undef key
/*  -------------------------------------------------------------------------
    amq_server_channel_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_server_channel_annihilate_ (
    amq_server_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
    int
        history_last;
#endif

    amq_server_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_DESTROY))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_DESTROY))
    icl_trace_record (NULL, amq_server_channel_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_DESTROY))
    icl_stats_inc ("amq_server_channel_annihilate", &s_amq_server_channel_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (amq_server_channel_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_server_channel agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_DESTROY))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_DESTROY))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_free

    Type: Component method
    Freess a amq_server_channel_t object.
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_free_ (
    amq_server_channel_t * self,        //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_FREE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_FREE))
    icl_trace_record (NULL, amq_server_channel_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_FREE))
    icl_stats_inc ("amq_server_channel_free", &s_amq_server_channel_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);

amq_consumer_by_channel_destroy (&self->consumer_list);
        memset (&self->object_tag, 0, sizeof (amq_server_channel_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_server_channel_t));
        self->object_tag = AMQ_SERVER_CHANNEL_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_FREE))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_FREE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_free_finish"
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
    amq_server_channel_flow

    Type: Component method
    Accepts a amq_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Implements the channel.flow method.  When a channel is restarted,
    we dispatch the channel's virtual host.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_flow (
    amq_server_channel_t * self,        //  Reference to object
    Bool active                         //  Active consumer?
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_FLOW))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_flow_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" active=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, active);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_FLOW))
    icl_trace_record (NULL, amq_server_channel_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_FLOW))
    icl_stats_inc ("amq_server_channel_flow", &s_amq_server_channel_flow_stats);
#endif

AMQ_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_server_channel_agent_flow (self->thread,active)) {
        //icl_console_print ("Error sending 'flow' method to amq_server_channel agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_FLOW))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_FLOW))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_flow_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" active=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, active, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_consume

    Type: Component method
    Accepts a amq_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Creates a new channel consumer as specified.  Mechanism is as follows:
    server_channel creates consumer, then attaches it to own consumer list
    and sends to queue so that queue can add consumer to its consumer list.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_consume (
    amq_server_channel_t * self,        //  Reference to object
    amq_queue_t * queue,                //  Queue to consume from
    amq_server_method_t * method        //  Consume method
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_CONSUME))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_consume_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
" method=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, method);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CONSUME))
    icl_trace_record (NULL, amq_server_channel_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_CONSUME))
    icl_stats_inc ("amq_server_channel_consume", &s_amq_server_channel_consume_stats);
#endif

AMQ_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_server_channel_agent_consume (self->thread,queue,method)) {
        //icl_console_print ("Error sending 'consume' method to amq_server_channel agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CONSUME))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_CONSUME))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_consume_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
" method=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, method, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_ack

    Type: Component method
    Accepts a amq_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Implements the Basic.Ack method on all consumers in the channel.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_ack (
    amq_server_channel_t * self,        //  Reference to object
    int64_t delivery_tag,               //  Delivery tag to ack
    Bool multiple                       //  Ack multiple messages?
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_ACK))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_ack_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" delivery_tag=\"%lli\""
" multiple=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, delivery_tag, multiple);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ACK))
    icl_trace_record (NULL, amq_server_channel_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_ACK))
    icl_stats_inc ("amq_server_channel_ack", &s_amq_server_channel_ack_stats);
#endif

AMQ_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_server_channel_agent_ack (self->thread,delivery_tag,multiple)) {
        //icl_console_print ("Error sending 'ack' method to amq_server_channel agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ACK))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_ACK))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_ack_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" delivery_tag=\"%lli\""
" multiple=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, delivery_tag, multiple, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_earn

    Type: Component method
    Accepts a amq_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_earn (
    amq_server_channel_t * self         //  Reference to object
)
{
amq_consumer_t
    *consumer;                      //  Consumer object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_EARN))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_earn_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_EARN))
    icl_trace_record (NULL, amq_server_channel_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_EARN))
    icl_stats_inc ("amq_server_channel_earn", &s_amq_server_channel_earn_stats);
#endif

AMQ_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

icl_atomic_inc32 ((volatile qbyte *) &self->credit);

//
if (icl_atomic_get32 ((volatile qbyte *) &self->credit) == 1) {
    //  Dispatch all queues for the channel
    consumer = amq_consumer_by_channel_first (self->consumer_list);
    while (consumer) {
        amq_queue_dispatch (consumer->queue);
        consumer = amq_consumer_by_channel_next (&consumer);
    }
}
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_EARN))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_EARN))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_earn_finish"
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
    amq_server_channel_cancel

    Type: Component method
    Accepts a amq_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Cancels channel consumer specified by tag.  May be called either
    from method handler - sync true - or from queue agent - sync false.
    Mechanism is as follows: removes consumer from index table and from
    own consumer list.  If sync, then sends to queue so that queue can
    remove from own consumer list.  If not sync, destroys consumer.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_cancel (
    amq_server_channel_t * self,        //  Reference to object
    char * tag,                         //  Consumer tag
    Bool sync,                          //  Are we talking to a client?
    Bool nowait                         //  No reply method wanted
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_CANCEL))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_cancel_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tag=\"%s\""
" sync=\"%i\""
" nowait=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tag, sync, nowait);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CANCEL))
    icl_trace_record (NULL, amq_server_channel_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_CANCEL))
    icl_stats_inc ("amq_server_channel_cancel", &s_amq_server_channel_cancel_stats);
#endif

AMQ_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_server_channel_agent_cancel (self->thread,tag,sync,nowait)) {
        //icl_console_print ("Error sending 'cancel' method to amq_server_channel agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CANCEL))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_CANCEL))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_cancel_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tag=\"%s\""
" sync=\"%i\""
" nowait=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tag, sync, nowait, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_selftest (
void)
{
amq_server_channel_table_t
    *table;
amq_server_channel_t
    *channel;
int
    count;
dbyte
    channel_nbr;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_SELFTEST))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_SELFTEST))
    icl_trace_record (NULL, amq_server_channel_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_SELFTEST))
    icl_stats_inc ("amq_server_channel_selftest", &s_amq_server_channel_selftest_stats);
#endif

smt_initialise ();
table = amq_server_channel_table_new ();

//  Let's try some edge cases
channel = amq_server_channel_new (table, NULL, AMQ_SERVER_CHANNEL_TABLE_INITIAL_SIZE - 1);
amq_server_channel_destroy (&channel);
smt_wait (0);

channel = amq_server_channel_new (table, NULL, AMQ_SERVER_CHANNEL_TABLE_INITIAL_SIZE);
amq_server_channel_destroy (&channel);
smt_wait (0);

channel = amq_server_channel_new (table, NULL, AMQ_SERVER_CHANNEL_TABLE_INITIAL_SIZE + 1);
amq_server_channel_destroy (&channel);

//  Now some random table bashing
for (count = 0; count < 2000; count++) {
    channel_nbr = randomof (0xffff);
    channel = amq_server_channel_new (table, NULL, channel_nbr);
    amq_server_channel_destroy (&channel);
    smt_wait (0);
}
amq_server_channel_table_destroy (&table);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_SELFTEST))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_SELFTEST))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_selftest_finish"
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
    amq_server_channel_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_channel_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_INITIALISE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_INITIALISE))
    icl_trace_record (NULL, amq_server_channel_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_INITIALISE))
    icl_stats_inc ("amq_server_channel_initialise", &s_amq_server_channel_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_server_channel_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_server_channel_mutex)
            s_amq_server_channel_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_server_channel_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_server_channel_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_server_channel_agent_init ();

s_channel_id_seq_hi = 0;
s_channel_id_seq_lo = 1;
            s_amq_server_channel_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_server_channel_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_INITIALISE))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_INITIALISE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_initialise_finish"
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
    amq_server_channel_spend

    Type: Component method
    Accepts a amq_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_spend (
    amq_server_channel_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_SPEND))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_spend_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_SPEND))
    icl_trace_record (NULL, amq_server_channel_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_SPEND))
    icl_stats_inc ("amq_server_channel_spend", &s_amq_server_channel_spend_stats);
#endif

AMQ_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

icl_atomic_dec32 ((volatile qbyte *) &self->credit);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_SPEND))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_SPEND))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_spend_finish"
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
    amq_server_channel_error

    Type: Component method
    Accepts a amq_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Raises a channel exception.
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_error (
    amq_server_channel_t * self,        //  Reference to object
    dbyte reply_code,                   //  Error code
    char * reply_text,                  //  Error text
    dbyte faulting_class_id,            //  Faulting class id
    dbyte faulting_method_id            //  Faulting method id
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_ERROR))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_error_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_text);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ERROR))
    icl_trace_record (NULL, amq_server_channel_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_ERROR))
    icl_stats_inc ("amq_server_channel_error", &s_amq_server_channel_error_stats);
#endif

AMQ_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

//
amq_server_agent_channel_error (
    self->connection->thread, self, reply_code, reply_text,
    faulting_class_id, faulting_method_id);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ERROR))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_ERROR))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_error_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_text=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_text, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_remove_from_all_containers (
    amq_server_channel_t * self         //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_server_channel_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("amq_server_channel_remove_from_all_containers", &s_amq_server_channel_remove_from_all_containers_stats);
#endif

AMQ_SERVER_CHANNEL_ASSERT_SANE (self);
amq_server_channel_table_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_remove_from_all_containers_finish"
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
    amq_server_channel_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_server_channel_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_SHOW))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_SHOW))
    icl_trace_record (NULL, amq_server_channel_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_SHOW))
    icl_stats_inc ("amq_server_channel_show", &s_amq_server_channel_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_server_channel zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
    if (self->history_last > AMQ_SERVER_CHANNEL_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_SERVER_CHANNEL_HISTORY_LENGTH;
        self->history_last %= AMQ_SERVER_CHANNEL_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_SERVER_CHANNEL_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_server_channel>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_SHOW))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_SHOW))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_show_finish"
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
    amq_server_channel_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_channel_destroy_ (
    amq_server_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_server_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_DESTROY_PUBLIC))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_server_channel_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_DESTROY_PUBLIC))
    icl_stats_inc ("amq_server_channel_destroy", &s_amq_server_channel_destroy_stats);
#endif

    if (self) {
amq_server_channel_remove_from_all_containers (self);
        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            rc = amq_server_channel_annihilate_ (self_p, file, line);
        else
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
            amq_server_channel_free (self);
        *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_DESTROY_PUBLIC))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" rc=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, rc, self?self->links:0, self?self->zombie:0);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_channel_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_unlink_ (
    amq_server_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
    int
        history_last;
#endif
    amq_server_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_UNLINK))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_UNLINK))
    icl_trace_record (NULL, amq_server_channel_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_UNLINK))
    icl_stats_inc ("amq_server_channel_unlink", &s_amq_server_channel_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_server_channel object");
            amq_server_channel_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_server_channel_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_server_channel_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_UNLINK))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_UNLINK))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_unlink_finish"
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
    amq_server_channel_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_ANIMATE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ANIMATE))
    icl_trace_record (NULL, amq_server_channel_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_ANIMATE))
    icl_stats_inc ("amq_server_channel_animate", &s_amq_server_channel_animate_stats);
#endif

amq_server_channel_animating = enabled;

amq_server_channel_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ANIMATE))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_ANIMATE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_animate_finish"
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
    amq_server_channel_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_TERMINATE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_TERMINATE))
    icl_trace_record (NULL, amq_server_channel_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_TERMINATE))
    icl_stats_inc ("amq_server_channel_terminate", &s_amq_server_channel_terminate_stats);
#endif

if (s_amq_server_channel_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_server_channel_mutex);
#endif
        s_amq_server_channel_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_TERMINATE))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_TERMINATE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_terminate_finish"
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
    amq_server_channel_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_server_channel_t *
    amq_server_channel_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_server_channel_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_ALLOC))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ALLOC))
    icl_trace_record (NULL, amq_server_channel_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_ALLOC))
    icl_stats_inc ("amq_server_channel_alloc", &s_amq_server_channel_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_server_channel_cache_initialise ();

self = (amq_server_channel_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_server_channel_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ALLOC))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_ALLOC))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_alloc_finish"
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
    amq_server_channel_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_server_channel_t *
    amq_server_channel_link_ (
    amq_server_channel_t * self,        //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_LINK))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_LINK))
    icl_trace_record (NULL, amq_server_channel_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_LINK))
    icl_stats_inc ("amq_server_channel_link", &s_amq_server_channel_link_stats);
#endif

    if (self) {
        AMQ_SERVER_CHANNEL_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_SERVER_CHANNEL_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_LINK))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_LINK))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_link_finish"
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
    amq_server_channel_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_server_channel_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_CACHE_INITIALISE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_server_channel_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_CACHE_INITIALISE))
    icl_stats_inc ("amq_server_channel_cache_initialise", &s_amq_server_channel_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_server_channel_t));
icl_system_register (amq_server_channel_cache_purge, amq_server_channel_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_CACHE_INITIALISE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_cache_initialise_finish"
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
    amq_server_channel_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_channel_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_CACHE_PURGE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CACHE_PURGE))
    icl_trace_record (NULL, amq_server_channel_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_CACHE_PURGE))
    icl_stats_inc ("amq_server_channel_cache_purge", &s_amq_server_channel_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CACHE_PURGE))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_CACHE_PURGE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_cache_purge_finish"
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
    amq_server_channel_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_channel_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_CACHE_TERMINATE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_server_channel_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_CACHE_TERMINATE))
    icl_stats_inc ("amq_server_channel_cache_terminate", &s_amq_server_channel_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_CACHE_TERMINATE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_cache_terminate_finish"
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
    amq_server_channel_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_channel_new_in_scope_ (
    amq_server_channel_t * * self_p,    //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_server_channel_table_t * table,   //  Table to insert into
    amq_server_connection_t * connection,   //  Parent connection
    dbyte number                        //  Channel number
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_NEW_IN_SCOPE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" connection=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, connection);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_server_channel_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL)  ||  defined (BASE_STATS_AMQ_SERVER_CHANNEL_NEW_IN_SCOPE))
    icl_stats_inc ("amq_server_channel_new_in_scope", &s_amq_server_channel_new_in_scope_stats);
#endif

*self_p = amq_server_channel_new_ (file,line,table,connection,number);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_server_channel_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_server_channel_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL)   || defined (BASE_ANIMATE_AMQ_SERVER_CHANNEL_NEW_IN_SCOPE))
    if (amq_server_channel_animating)
        icl_console_print ("<amq_server_channel_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" connection=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, connection, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_NEW)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_DESTROY)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_FREE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_FLOW)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CONSUME)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ACK)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_EARN)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CANCEL)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_SELFTEST)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_INITIALISE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_SPEND)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ERROR)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_SHOW)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_UNLINK)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ANIMATE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_ALLOC)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_LINK)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CHANNEL_NEW_IN_SCOPE) )
void
amq_server_channel_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "free"; break;
        case 4: method_name = "flow"; break;
        case 5: method_name = "consume"; break;
        case 6: method_name = "ack"; break;
        case 7: method_name = "earn"; break;
        case 8: method_name = "cancel"; break;
        case 9: method_name = "selftest"; break;
        case 10: method_name = "initialise"; break;
        case 11: method_name = "spend"; break;
        case 12: method_name = "error"; break;
        case 13: method_name = "remove from all containers"; break;
        case 14: method_name = "show"; break;
        case 15: method_name = "destroy public"; break;
        case 16: method_name = "unlink"; break;
        case 17: method_name = "animate"; break;
        case 18: method_name = "terminate"; break;
        case 19: method_name = "alloc"; break;
        case 20: method_name = "link"; break;
        case 21: method_name = "cache initialise"; break;
        case 22: method_name = "cache purge"; break;
        case 23: method_name = "cache terminate"; break;
        case 24: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_server_channel %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_server_channel_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_server_channel_component  = "amq_server_channel ";
char *amq_server_channel_version   = "1.0 ";
char *amq_server_channel_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_server_channel_filename  = "amq_server_channel.icl ";
char *amq_server_channel_builddate  = "2010/10/06 ";
char *amq_server_channel_version_end  = "VeRsIoNeNd:ipc";

