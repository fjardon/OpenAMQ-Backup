/*---------------------------------------------------------------------------
    amq_queue_basic.c - amq_queue_basic component

This class implements the basic content queue manager. This class
runs lock-free as a child of the asynchronous queue class.
    Generated from amq_queue_basic.icl by icl_gen using GSL/4.
    
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
#include "amq_queue_basic.h"            //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_queue_basic_t

//  Shorthands for class methods

#define self_new            amq_queue_basic_new
#define self_annihilate     amq_queue_basic_annihilate
#define self_free           amq_queue_basic_free
#define self_stop           amq_queue_basic_stop
#define self_consume        amq_queue_basic_consume
#define self_cancel         amq_queue_basic_cancel
#define self_consumer_ack   amq_queue_basic_consumer_ack
#define self_publish        amq_queue_basic_publish
#define self_dispatch       amq_queue_basic_dispatch
#define self_get            amq_queue_basic_get
#define self_purge          amq_queue_basic_purge
#define self_consumer_count  amq_queue_basic_consumer_count
#define self_message_count  amq_queue_basic_message_count
#define self_selftest       amq_queue_basic_selftest
#define self_terminate      amq_queue_basic_terminate
#define self_show           amq_queue_basic_show
#define self_destroy        amq_queue_basic_destroy
#define self_alloc          amq_queue_basic_alloc
#define self_cache_initialise  amq_queue_basic_cache_initialise
#define self_cache_purge    amq_queue_basic_cache_purge
#define self_cache_terminate  amq_queue_basic_cache_terminate
#define self_show_animation  amq_queue_basic_show_animation
#define self_new_in_scope   amq_queue_basic_new_in_scope

static void
    amq_queue_basic_annihilate (
amq_queue_basic_t * ( * self_p )        //  Reference to object reference
);

static void
    amq_queue_basic_free (
amq_queue_basic_t * self                //  Object reference
);

#define amq_queue_basic_alloc()         amq_queue_basic_alloc_ (__FILE__, __LINE__)
static amq_queue_basic_t *
    amq_queue_basic_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_queue_basic_cache_initialise (
void);

static void
    amq_queue_basic_cache_purge (
void);

static void
    amq_queue_basic_cache_terminate (
void);

Bool
    amq_queue_basic_animating = TRUE;   //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


#define CONSUMER_FOUND  0
#define CONSUMER_NONE   1
#define CONSUMER_BUSY   2

static int
    s_get_next_consumer (amq_queue_basic_t *self, char *producer_id, amq_consumer_t **consumer_p);
static void
    s_free_consumer_queue (amq_consumer_by_queue_t *queue);
/*  -------------------------------------------------------------------------
    amq_queue_basic_new

    Type: Component method
    Creates and initialises a new amq_queue_basic_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_queue_basic_t *
    amq_queue_basic_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_queue_t * queue                 //  Parent queue
)
{
    amq_queue_basic_t *
        self = NULL;                    //  Object reference

    self = amq_queue_basic_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_QUEUE_BASIC_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_queue_basic_show_);
#endif

//
self->queue            = queue;
self->consumer_list    = amq_consumer_by_queue_new ();
self->content_list     = ipr_looseref_list_new ();
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_basic_annihilate (
    amq_queue_basic_t * ( * self_p )    //  Reference to object reference
)
{

amq_content_basic_t
    *content;                       //  Content object reference
    amq_queue_basic_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

AMQ_QUEUE_BASIC_ASSERT_SANE (self);

//
s_free_consumer_queue (self->consumer_list);
while ((content = (amq_content_basic_t *) ipr_looseref_pop (self->content_list)))
    amq_content_basic_unlink (&content);

}
/*  -------------------------------------------------------------------------
    amq_queue_basic_free

    Type: Component method
    Freess a amq_queue_basic_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_queue_basic_free (
    amq_queue_basic_t * self            //  Object reference
)
{


if (self) {

amq_consumer_by_queue_destroy (&self->consumer_list);
ipr_looseref_list_destroy (&self->content_list);
        memset (&self->object_tag, 0, sizeof (amq_queue_basic_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_queue_basic_t));
        self->object_tag = AMQ_QUEUE_BASIC_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_stop

    Type: Component method
    Accepts a amq_queue_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_queue_basic_stop (
    amq_queue_basic_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_BASIC_ASSERT_SANE (self);

s_free_consumer_queue (self->consumer_list);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_consume

    Type: Component method
    Accepts a amq_queue_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Attach consumer to appropriate queue consumer list.
    -------------------------------------------------------------------------
 */

int
    amq_queue_basic_consume (
    amq_queue_basic_t * self,           //  Reference to object
    amq_consumer_t * consumer           //  Consumer reference
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_BASIC_ASSERT_SANE (self);

//
amq_consumer_by_queue_queue (self->consumer_list, consumer);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_cancel

    Type: Component method
    Accepts a amq_queue_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Cancel consumer.  This method synchronises with the server_channel
    cancel method so each party handles their consumer lists separately.
    -------------------------------------------------------------------------
 */

int
    amq_queue_basic_cancel (
    amq_queue_basic_t * self,           //  Reference to object
    amq_consumer_t * consumer           //  Consumer reference
)
{
amq_content_basic_t
    *content;
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_BASIC_ASSERT_SANE (self);

//
//  Consumer must have been removed from its per-channel list
assert (consumer->by_channel_next == consumer);
if (consumer->pending_content) {
    content = amq_content_basic_link (consumer->pending_content);
    if (content) {
        if (amq_server_config_debug_queue (amq_server_config))
            smt_log_print (amq_broker->debug_log,
                "Q: requeue  queue=%s message=%s **for redelivery**", self->queue->name, content->message_id);
        ipr_looseref_push (self->content_list, content);
        self_dispatch (self);
        amq_consumer_content_release (consumer);
    }
}
amq_consumer_destroy (&consumer);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_consumer_ack

    Type: Component method
    Accepts a amq_queue_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Acknowledge messages on consumer, if any.
    -------------------------------------------------------------------------
 */

int
    amq_queue_basic_consumer_ack (
    amq_queue_basic_t * self,           //  Reference to object
    amq_consumer_t * consumer           //  Consumer to ack
)
{
amq_content_basic_t
    *content;
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_BASIC_ASSERT_SANE (self);

//
content = amq_content_basic_link (consumer->pending_content);
if (content) {
    if (amq_server_config_debug_queue (amq_server_config))
        smt_log_print (amq_broker->debug_log,
            "Q: ack mesg queue=%s message=%s", self->queue->name, content->message_id);
    amq_consumer_content_release (consumer);
    amq_content_basic_unlink (&content);
    self_dispatch (self);
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_publish

    Type: Component method
    Accepts a amq_queue_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Publish message content onto queue.  If the message was marked as
    "immediate" and could not be dispatched, returns it back to the
    producer.
    -------------------------------------------------------------------------
 */

int
    amq_queue_basic_publish (
    amq_queue_basic_t * self,           //  Reference to object
    amq_server_channel_t * channel,     //  Channel for reply
    amq_content_basic_t * content,      //  Message content
    Bool immediate                      //  Warn if no consumers?
)
{
qbyte
    queue_size;                     //  Current queue size
ipr_looseref_t
    *looseref;                      //  Queued message
amq_server_connection_t
    *connection;
icl_shortstr_t
    client_identifier;
amq_consumer_t
    *consumer;
Bool
    have_active_consumers,
    rejected;
amq_queue_t
    *queue;                         //  Parent queue object
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_BASIC_ASSERT_SANE (self);

//
queue = self->queue;
if (amq_server_config_debug_queue (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "Q: publish  queue=%s message=%s", queue->name, content->message_id);

queue->contents_in++;
queue->traffic_in += content->body_size;

//  Grab a link to the queue's parent connection (if any) and client
//  identification so that we can log it or kill the client if needed
icl_shortstr_cpy (client_identifier, "");
connection = amq_server_connection_link (queue->connection);
if (connection) {
    icl_shortstr_fmt (client_identifier, "(%s, %s, %s, %s)",
        connection->client_address,
        connection->client_product,
        connection->client_version,
        connection->client_instance);
    amq_server_connection_unlink (&connection);
}

//  Check warning limit
queue_size = ipr_looseref_list_count (self->content_list);
if (queue->warn_limit && queue_size >= queue->warn_limit && !queue->warned) {
    smt_log_print (amq_broker->alert_log,
        "W: queue=%s hit %d messages: no action %s",
        queue->name, queue_size, client_identifier);
    queue->warned = TRUE;
}
//  Check just one of drop/trim/kill
if (queue->drop_limit && queue_size >= queue->drop_limit) {
    if (!queue->dropped) {
        smt_log_print (amq_broker->alert_log,
            "W: queue=%s hit %d messages: dropping new messages %s",
            queue->name, queue_size, client_identifier);
        queue->dropped = TRUE;
    }
    queue->drop_count++;
    content = NULL;
}
else
if (queue->trim_limit && queue_size >= queue->trim_limit) {
    amq_content_basic_t
        *oldest;                    //  Oldest content to trim
    if (!queue->trimmed) {
        smt_log_print (amq_broker->alert_log,
            "W: queue=%s hit %d messages: trimming old messages %s",
            queue->name, queue_size, client_identifier);
        queue->trimmed = TRUE;
    }
    oldest = (amq_content_basic_t *) ipr_looseref_pop (self->content_list);
    amq_content_basic_unlink (&oldest);
    queue->drop_count++;
}
else
if (queue->kill_limit && queue_size >= queue->kill_limit) {
    smt_log_print (amq_broker->alert_log,
            "E: queue=%s hit %d messages: KILLING QUEUE %s",
            queue->name, queue_size, client_identifier);
    if (queue->exclusive && connection)
        amq_server_connection_error (connection,
            ASL_RESOURCE_ERROR, "Queue overflow, connection killed",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_PUBLISH);
    else
        amq_queue_self_destruct (queue);
}
else
if (queue_size == 0) {
    //  Reset warning flags if queue becomes empty
    queue->warned  = FALSE;
    queue->dropped = FALSE;
    queue->trimmed = FALSE;
}
amq_server_connection_unlink (&connection);

if (content) {
    //  If immediate, and no consumers, return the message
    rejected = FALSE;
    if (immediate) {
        //  Check if there are any active consumers
        have_active_consumers = FALSE;
        consumer = amq_consumer_by_queue_first (self->consumer_list);
        while (consumer) {
            if (!consumer->paused && !consumer->pending_content) {
                have_active_consumers = TRUE;
                amq_consumer_unlink (&consumer);
                break;
            }
            consumer = amq_consumer_by_queue_next (&consumer);
        }
        if (!have_active_consumers) {
            rejected = TRUE;

            if (amq_server_config_debug_queue (amq_server_config))
                smt_log_print (amq_broker->debug_log,
                    "Q: return   queue=%s message=%s",
                    queue->name, content->message_id);

            content->returned = TRUE;
            //  Connection and channel will be null for messages published
            //  by an internal agent rather than an external application.
            //  In that case we do not return undeliverable messages.
            connection = channel?
                amq_server_connection_link (channel->connection): NULL;
            if (connection) {
                amq_server_agent_basic_return (
                    connection->thread,
                    channel->number,
                    content,
                    ASL_NOT_DELIVERED,
                    "No immediate consumers for Basic message",
                    content->exchange,
                    content->routing_key,
                    NULL);
                amq_server_connection_unlink (&connection);
            }
        }
    }
    if (!rejected) {
        content->immediate = immediate;
        amq_content_basic_link (content);
        looseref = ipr_looseref_queue (self->content_list, content);
    }
}
self_dispatch (self);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_dispatch

    Type: Component method
    Accepts a amq_queue_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Dispatch message content to the active consumers, as far as possible.
    Will deliver messages in strict order to available consumers.  If
    there are no consumers at all, will hold messages on the queue unless
    they are marked 'immediate'.  If there are consumers, but a message
    cannot be delivered to any of them, the message will be discarded or
    returned (if 'immediate').
    -------------------------------------------------------------------------
 */

int
    amq_queue_basic_dispatch (
    amq_queue_basic_t * self            //  Reference to object
)
{
amq_consumer_t
    *consumer;                      //  Consumer reference
amq_content_basic_t
    *content;                       //  Content object reference
amq_server_connection_t
    *connection;
amq_server_channel_t
    *channel;
Bool
    have_active_consumers;
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_BASIC_ASSERT_SANE (self);

//
if (amq_server_config_debug_queue (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "Q: dispatch queue=%s nbr_messages=%d nbr_consumers=%d",
        self->queue->name,
        ipr_looseref_list_count (self->content_list),
        amq_consumer_by_queue_count (self->consumer_list));

//  This is an optimization to stop us looping over content below
//  if there are only passive consumers on the queue.
//  Get count of active consumers
have_active_consumers = FALSE;
consumer = amq_consumer_by_queue_first (self->consumer_list);
while (consumer) {
    //  Consumer is available if it's not paused, nor has pending content
    if (!consumer->paused && !consumer->pending_content) {
        have_active_consumers = TRUE;
        amq_consumer_unlink (&consumer);
        break;
    }
    consumer = amq_consumer_by_queue_next (&consumer);
}
if (amq_server_config_debug_queue (amq_server_config)
&& !have_active_consumers)
    smt_log_print (amq_broker->debug_log,
        "Q: paused   queue=%s nbr_messages=%d nbr_consumers=%d",
        self->queue->name,
        ipr_looseref_list_count (self->content_list),
        amq_consumer_by_queue_count (self->consumer_list));

while (have_active_consumers
&& ipr_looseref_list_count (self->content_list)) {
    //  Look for a valid consumer for this content
    content = (amq_content_basic_t *) ipr_looseref_pop (self->content_list);
    rc = s_get_next_consumer (self, content->producer_id, &consumer);

    if (rc == CONSUMER_FOUND) {
        if (amq_server_config_debug_queue (amq_server_config))
            smt_log_print (amq_broker->debug_log,
                "Q: deliver  queue=%s message=%s",
                self->queue->name, content->message_id);

        self->queue->contents_out++;
        self->queue->traffic_out += content->body_size;
        channel = amq_server_channel_link (consumer->channel);
        if (channel) {
            amq_server_channel_spend (channel);
            connection = amq_server_connection_link (channel->connection);
            if (connection) {
                //  Hold content if consumer is acknowledged
                //  Queue must be shared queue
                if (!self->queue->exclusive && !consumer->no_ack
                &&  !amq_server_config_no_ack (amq_server_config))
                    amq_consumer_content_hold (consumer, content);

                self->delivery_tag++;
                amq_server_agent_basic_deliver (
                    connection->thread,
                    channel->number,
                    content,
                    consumer->tag,
                    self->delivery_tag,
                    content->redelivered,
                    content->exchange,
                    content->routing_key,
                    consumer);

                amq_server_connection_unlink (&connection);
            }
            amq_server_channel_unlink (&channel);
        }
        //  Move consumer to end of queue to implement a round-robin
        amq_consumer_by_queue_queue (self->consumer_list, consumer);
        amq_content_basic_unlink (&content);
        amq_consumer_unlink (&consumer);
    }
    else
    if (rc == CONSUMER_BUSY) {
        if (amq_server_config_debug_queue (amq_server_config))
            smt_log_print (amq_broker->debug_log,
                "Q: busy     queue=%s message=%s",
                self->queue->name, content->message_id);

        //  No consumers right now, push content back onto list
        ipr_looseref_push (self->content_list, content);
        break;
    }
    else
    if (rc == CONSUMER_NONE) {
        //  No consumers at all for content, send back to originator
        //  if the immediate flag was set, else discard it.
        //  FIXME: This is old clustering code, what we should probably
        //  be doing here is returning the content to the originating
        //  connection, if possible?  Isn't the check in _publish
        //  sufficient?
        if (content->immediate && !content->returned) {
            if (amq_server_config_debug_queue (amq_server_config))
                smt_log_print (amq_broker->debug_log,
                    "Q: return   queue=%s message=%s",
                    self->queue->name, content->message_id);
        }
        else {
            if (amq_server_config_debug_queue (amq_server_config))
                smt_log_print (amq_broker->debug_log,
                    "Q: discard  queue=%s message=%s",
                    self->queue->name, content->message_id);
        }
        amq_content_basic_unlink (&content);
    }
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_get

    Type: Component method
    Accepts a amq_queue_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Returns next message off queue, if any.
    -------------------------------------------------------------------------
 */

int
    amq_queue_basic_get (
    amq_queue_basic_t * self,           //  Reference to object
    amq_server_channel_t * channel      //  Not documented
)
{
amq_content_basic_t
    *content;                       //  Content object reference
amq_server_connection_t
    *connection;
icl_shortstr_t
    sender_id;
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_BASIC_ASSERT_SANE (self);

//
//  Get next message off list, if any
content = (amq_content_basic_t *) ipr_looseref_pop (self->content_list);
connection = channel?
    amq_server_connection_link (channel->connection): NULL;

if (connection) {
    if (content) {
        amq_server_agent_basic_get_ok (
            connection->thread,
            channel->number,
            content,
            0,                      //  Delivery tag
            FALSE,                  //  Redelivered
            content->exchange,
            content->routing_key,
            ipr_looseref_list_count (self->content_list),
            NULL);

        amq_content_basic_unlink (&content);
    }
    else {
        icl_shortstr_fmt (sender_id, "%s|%d", connection->key, channel->number);
        amq_server_agent_basic_get_empty (
            connection->thread, channel->number, sender_id);
    }

    amq_server_connection_unlink (&connection);
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_purge

    Type: Component method
    Accepts a amq_queue_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Destroy all queue contents, return number of contents destroyed.
    -------------------------------------------------------------------------
 */

int
    amq_queue_basic_purge (
    amq_queue_basic_t * self            //  Reference to object
)
{
amq_content_basic_t
    *content;                       //  Content object reference
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_BASIC_ASSERT_SANE (self);

//
while ((content = (amq_content_basic_t *) ipr_looseref_pop (self->content_list))) {
    amq_content_basic_unlink (&content);
    rc++;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_consumer_count

    Type: Component method
    Accepts a amq_queue_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Return number of consumers for queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_basic_consumer_count (
    amq_queue_basic_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_BASIC_ASSERT_SANE (self);

//
rc = amq_consumer_by_queue_count (self->consumer_list);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_message_count

    Type: Component method
    Accepts a amq_queue_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Returns number of messages on queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_basic_message_count (
    amq_queue_basic_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_BASIC_ASSERT_SANE (self);

//
rc = ipr_looseref_list_count (self->content_list);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_basic_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_queue_basic_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_basic_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_queue_basic_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_basic_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_queue_basic_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_queue_basic file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_queue_basic_destroy

    Type: Component method
    Destroys a amq_queue_basic_t object. Takes the address of a
    amq_queue_basic_t reference (a pointer to a pointer) and nullifies the
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
    amq_queue_basic_destroy_ (
    amq_queue_basic_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_queue_basic_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_queue_basic_annihilate (self_p);
    amq_queue_basic_free ((amq_queue_basic_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_queue_basic_t *
    amq_queue_basic_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_queue_basic_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_queue_basic_cache_initialise ();

self = (amq_queue_basic_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_queue_basic_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_queue_basic_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_queue_basic_t));
icl_system_register (amq_queue_basic_cache_purge, amq_queue_basic_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_basic_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_queue_basic_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_basic_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_queue_basic_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_queue_basic_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_queue_basic_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_queue_basic_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_basic_new_in_scope_ (
    amq_queue_basic_t * * self_p,       //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_queue_t * queue                 //  Parent queue
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_queue_basic_new_ (file,line,queue);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_queue_basic_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Find next consumer for queue and message
//  - producer_id is used for local consumers,
//  Returns CONSUMER_FOUND if a valid consumer is found
//  Returns CONSUMER_NONE if no valid consumers are found
//  Returns CONSUMER_BUSY if there are busy/paused consumers

static int
s_get_next_consumer (
    amq_queue_basic_t *self,
    char *producer_id,
    amq_consumer_t **consumer_p)
{
    amq_consumer_t
        *consumer;
    int
        rc = CONSUMER_NONE;
    amq_server_connection_t
        *connection;
    amq_server_channel_t
        *channel;
    Bool
        channel_active;

    //  We expect to process the first consumer on the active list
    consumer = amq_consumer_by_queue_first (self->consumer_list);
    while (consumer) {
        channel_active = FALSE;
        channel = amq_server_channel_link (consumer->channel);
        if (channel) {
            connection = amq_server_connection_link (channel->connection);
            if (connection)
                channel_active = channel->active;
        }
        else
            connection = NULL;

        if (channel_active) {
            if (icl_atomic_get32 ((volatile qbyte *) &channel->credit) < 1)
                rc = CONSUMER_BUSY;     //  Skip this consumer if busy
            else
            if (consumer->no_local) {
                //  If the consumer is an application then we can compare the
                //  content producer_id with the connection id of the consumer.
                if (strneq (connection->id, producer_id))
                    rc = CONSUMER_FOUND; //  We have our consumer
            }
            else
                rc = CONSUMER_FOUND;    //  We have our consumer
        }
        else
            rc = CONSUMER_BUSY;         //  Skip this consumer

        amq_server_connection_unlink (&connection);
        amq_server_channel_unlink (&channel);
        if (rc == CONSUMER_FOUND)
            break;                      //  Return this consumer
        else
            consumer = amq_consumer_by_queue_next (&consumer);
    }
    *consumer_p = consumer;
    return (rc);
}

static void
s_free_consumer_queue (amq_consumer_by_queue_t *queue)
{
    amq_consumer_t
        *consumer;
    amq_server_channel_t
        *channel;

    if (queue) {
        while ((consumer = amq_consumer_by_queue_pop (queue))) {
            channel = amq_server_channel_link (consumer->channel);
            if (channel) {
                amq_server_channel_cancel (channel, consumer->tag, FALSE, TRUE);
                amq_server_channel_unlink (&channel);
            }
            amq_consumer_destroy (&consumer);
        }
    }
}

//  Embed the version information in the resulting binary

char *EMBED__amq_queue_basic_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_queue_basic_component    = "amq_queue_basic ";
char *EMBED__amq_queue_basic_version      = "1.0 ";
char *EMBED__amq_queue_basic_copyright    = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_queue_basic_filename     = "amq_queue_basic.icl ";
char *EMBED__amq_queue_basic_builddate    = "2010/10/06 ";
char *EMBED__amq_queue_basic_version_end  = "VeRsIoNeNd:ipc";

