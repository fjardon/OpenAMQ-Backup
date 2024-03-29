/*---------------------------------------------------------------------------
    amq_client_session.c - amq_client_session component

This class provides the session serialisation API.
    Generated from amq_client_session.icl by icl_gen using GSL/4.
    
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
#include "amq_client_session.h"         //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_client_session_t

//  Shorthands for class methods

#define self_new            amq_client_session_new
#define self_annihilate     amq_client_session_annihilate
#define self_wait           amq_client_session_wait
#define self_channel_flow   amq_client_session_channel_flow
#define self_channel_flow_ok  amq_client_session_channel_flow_ok
#define self_exchange_declare  amq_client_session_exchange_declare
#define self_exchange_declare_nowait  amq_client_session_exchange_declare_nowait
#define self_exchange_delete  amq_client_session_exchange_delete
#define self_exchange_delete_nowait  amq_client_session_exchange_delete_nowait
#define self_queue_declare  amq_client_session_queue_declare
#define self_queue_declare_nowait  amq_client_session_queue_declare_nowait
#define self_queue_bind     amq_client_session_queue_bind
#define self_queue_bind_nowait  amq_client_session_queue_bind_nowait
#define self_queue_purge    amq_client_session_queue_purge
#define self_queue_purge_nowait  amq_client_session_queue_purge_nowait
#define self_queue_delete   amq_client_session_queue_delete
#define self_queue_delete_nowait  amq_client_session_queue_delete_nowait
#define self_queue_unbind   amq_client_session_queue_unbind
#define self_queue_unbind_nowait  amq_client_session_queue_unbind_nowait
#define self_basic_qos      amq_client_session_basic_qos
#define self_basic_consume  amq_client_session_basic_consume
#define self_basic_consume_nowait  amq_client_session_basic_consume_nowait
#define self_basic_cancel   amq_client_session_basic_cancel
#define self_basic_cancel_nowait  amq_client_session_basic_cancel_nowait
#define self_basic_publish  amq_client_session_basic_publish
#define self_basic_get      amq_client_session_basic_get
#define self_basic_ack      amq_client_session_basic_ack
#define self_basic_reject   amq_client_session_basic_reject
#define self_restms_pipe_create  amq_client_session_restms_pipe_create
#define self_restms_pipe_delete  amq_client_session_restms_pipe_delete
#define self_restms_feed_create  amq_client_session_restms_feed_create
#define self_restms_feed_delete  amq_client_session_restms_feed_delete
#define self_restms_join_create  amq_client_session_restms_join_create
#define self_restms_join_delete  amq_client_session_restms_join_delete
#define self_push_arrived   amq_client_session_push_arrived
#define self_push_returned  amq_client_session_push_returned
#define self_get_basic_arrived_count  amq_client_session_get_basic_arrived_count
#define self_basic_arrived  amq_client_session_basic_arrived
#define self_get_basic_returned_count  amq_client_session_get_basic_returned_count
#define self_basic_returned  amq_client_session_basic_returned
#define self_get_alive      amq_client_session_get_alive
#define self_get_error_text  amq_client_session_get_error_text
#define self_get_lease      amq_client_session_get_lease
#define self_get_channel_id  amq_client_session_get_channel_id
#define self_get_active     amq_client_session_get_active
#define self_get_reply_code  amq_client_session_get_reply_code
#define self_get_reply_text  amq_client_session_get_reply_text
#define self_get_class_id   amq_client_session_get_class_id
#define self_get_method_id  amq_client_session_get_method_id
#define self_get_consumer_tag  amq_client_session_get_consumer_tag
#define self_get_exchange   amq_client_session_get_exchange
#define self_get_routing_key  amq_client_session_get_routing_key
#define self_get_delivery_tag  amq_client_session_get_delivery_tag
#define self_get_redelivered  amq_client_session_get_redelivered
#define self_get_message_count  amq_client_session_get_message_count
#define self_get_sender_id  amq_client_session_get_sender_id
#define self_get_queue      amq_client_session_get_queue
#define self_get_consumer_count  amq_client_session_get_consumer_count
#define self_dp_new         amq_client_session_dp_new
#define self_dp_lookup      amq_client_session_dp_lookup
#define self_dp_destroy     amq_client_session_dp_destroy
#define self_initialise     amq_client_session_initialise
#define self_selftest       amq_client_session_selftest
#define self_terminate      amq_client_session_terminate
#define self_show           amq_client_session_show
#define self_destroy        amq_client_session_destroy
#define self_alloc          amq_client_session_alloc
#define self_free           amq_client_session_free
#define self_cache_initialise  amq_client_session_cache_initialise
#define self_cache_purge    amq_client_session_cache_purge
#define self_cache_terminate  amq_client_session_cache_terminate
#define self_show_animation  amq_client_session_show_animation
#define self_new_in_scope   amq_client_session_new_in_scope

static void
    amq_client_session_annihilate (
amq_client_session_t * ( * self_p )     //  Reference to object reference
);

static void
    amq_client_session_initialise (
void);

static void
    amq_client_session_terminate (
void);

#define amq_client_session_alloc()      amq_client_session_alloc_ (__FILE__, __LINE__)
static amq_client_session_t *
    amq_client_session_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_client_session_free (
amq_client_session_t * self             //  Object reference
);

static void
    amq_client_session_cache_initialise (
void);

static void
    amq_client_session_cache_purge (
void);

static void
    amq_client_session_cache_terminate (
void);

Bool
    amq_client_session_animating = TRUE;  //  Animation enabled by default
static Bool
    s_amq_client_session_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_client_session_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static int
    s_wait_for_methods (amq_client_session_t *self, int timeout, Bool blocking, Bool on_content);
static void
    s_process_chrono (amq_client_session_t *self, amq_content_basic_t *content);
static void
    s_close_dp_connection (ipr_hash_t *hash, void *argument);
/*  -------------------------------------------------------------------------
    amq_client_session_new

    Type: Component method
    Creates and initialises a new amq_client_session_t object, returns a
    reference to the created object.
    Create new session on an established connection.

    The connection argument refers to a previously-created connection
    object.
    -------------------------------------------------------------------------
 */

amq_client_session_t *
    amq_client_session_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_connection_t * connection  //  Not documented
)
{
int
    rc;
    amq_client_session_t *
        self = NULL;                    //  Object reference

if (!s_amq_client_session_active)
    self_initialise ();
    self = amq_client_session_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CLIENT_SESSION_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_client_session_show_);
#endif

//
assert (connection);

self->connection   = connection;
self->channel_nbr  = ++connection->channel_nbr;
self->method_queue = smt_method_queue_sync_new ();
self->error_text   = "no error";
self->arrived_basic_list = amq_content_basic_list_new ();
self->returned_basic_list = amq_content_basic_list_new ();
self->chrono_list = amq_content_basic_list_new ();
self->dp_sinks = ipr_hash_table_new ();
self->dp_feeds = ipr_hash_table_new ();

//  Chrono block is the batch size plus enough for one delta
//  Thus we dispatch the chrono block when it's GE the batch size
self->chrono_block = icl_mem_alloc (
    amq_client_config_chrono_batch (amq_client_config)
    + ICL_SHORTSTR_MAX);
strclr (self->chrono_block);

self->sequences = amq_sequence_table_new ();
if (connection->alive) {
    rc = amq_client_agent_channel_open (
        self->connection->thread,
        self->method_queue,
        &self->alive,
        &self->reply_code,
        self->reply_text,
        self->channel_nbr);

    //  If no immediate error, wait for confirmation that session was OK
    if (!rc) {
        if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE) == 0) {
            self->alive = TRUE;     //  Session is ready for use
            self->timestamp = apr_time_now ();
        }
    }
}
else {
    self->error_text = "connection is closed";
    rc = -1;
}
if (!self->alive)
    self_destroy (&self);
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_session_annihilate

    Type: Component method
    Close the session.
    -------------------------------------------------------------------------
 */

static void
    amq_client_session_annihilate (
    amq_client_session_t * ( * self_p )  //  Reference to object reference
)
{

    amq_client_session_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

//  Close and flush any Direct Mode connections
ipr_hash_table_apply (self->dp_sinks, s_close_dp_connection, self);
ipr_hash_table_destroy (&self->dp_sinks);
ipr_hash_table_apply (self->dp_feeds, s_close_dp_connection, self);
ipr_hash_table_destroy (&self->dp_feeds);

amq_sequence_table_destroy (&self->sequences);
//  Close main connection
if (self->alive) {
    amq_client_agent_channel_close (self->connection->thread, self->channel_nbr);
    while (self->alive) {
        //  Wait until we get back an CLOSED method, or timeout
        s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE);
    }
}
icl_longstr_destroy (&self->channel_id);
icl_mem_free (self->chrono_block);
smt_method_queue_destroy (&self->method_queue);
amq_content_basic_list_destroy (&self->arrived_basic_list);
amq_content_basic_list_destroy (&self->returned_basic_list);
amq_content_basic_list_destroy (&self->chrono_list);

}
/*  -------------------------------------------------------------------------
    amq_client_session_wait

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Waits for any activity on the session.  Returns 0 if content arrived
    or the timeout expired, -1 if the session ended abnormally.  If the timeout
    is zero, waits forever.  If the timeout is -1, does not wait at all, but
    processes pending methods and then returns.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_wait (
    amq_client_session_t * self,        //  Reference to object
    int timeout                         //  Timeout, in milliseconds
)
{
amq_content_basic_t
    *content;
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

//
//  This would be a good time to publish any pending chrono contents
content = amq_content_basic_list_pop (self->chrono_list);
if (content) {
    amq_client_session_basic_publish (self,
        content, 0, "amq.status", "chrono", FALSE, FALSE);
    amq_content_basic_unlink (&content);
}
if (!amq_content_basic_list_isempty (self->arrived_basic_list)
||  !amq_content_basic_list_isempty (self->returned_basic_list))
    return (0);                    //  Return if there is content to process
if (self->alive) {
    if (s_wait_for_methods (self, timeout, FALSE, TRUE))
        rc = -1;
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_channel_flow

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Enable/Disable Flow From Peer.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_channel_flow (
    amq_client_session_t * self,        //  Reference to object
    Bool active                         //  start/stop content frames
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_channel_flow (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        active);                     //  start/stop content frames

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_channel_flow_ok

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Confirm A Flow Method.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_channel_flow_ok (
    amq_client_session_t * self,        //  Reference to object
    Bool active                         //  current flow setting
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_channel_flow_ok (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        active);                     //  current flow setting

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_exchange_declare

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Declare Exchange, Create If Needed.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_exchange_declare (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * exchange,                    //  exchange name
    char * type,                        //  exchange type
    Bool passive,                       //  do not create exchange
    Bool durable,                       //  request a durable exchange
    Bool auto_delete,                   //  auto-delete when unused
    Bool internal,                      //  create internal exchange
    icl_longstr_t * arguments           //  arguments for declaration
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_exchange_declare (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        exchange,                    //  exchange name
        type,                        //  exchange type
        passive,                     //  do not create exchange
        durable,                     //  request a durable exchange
        auto_delete,                 //  auto-delete when unused
        internal,                    //  create internal exchange
        FALSE,                       //  do not send a reply method
        arguments);                  //  arguments for declaration

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_exchange_declare_nowait

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Declare Exchange, Create If Needed.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_exchange_declare_nowait (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * exchange,                    //  exchange name
    char * type,                        //  exchange type
    Bool passive,                       //  do not create exchange
    Bool durable,                       //  request a durable exchange
    Bool auto_delete,                   //  auto-delete when unused
    Bool internal,                      //  create internal exchange
    icl_longstr_t * arguments           //  arguments for declaration
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_exchange_declare (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        exchange,                    //  exchange name
        type,                        //  exchange type
        passive,                     //  do not create exchange
        durable,                     //  request a durable exchange
        auto_delete,                 //  auto-delete when unused
        internal,                    //  create internal exchange
        TRUE,                        //  do not send a reply method
        arguments);                  //  arguments for declaration

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_exchange_delete

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Delete An Exchange.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_exchange_delete (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * exchange,                    //  exchange name
    Bool if_unused                      //  delete only if unused
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_exchange_delete (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        exchange,                    //  exchange name
        if_unused,                   //  delete only if unused
        FALSE);                      //  do not send a reply method

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_exchange_delete_nowait

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Delete An Exchange.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_exchange_delete_nowait (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * exchange,                    //  exchange name
    Bool if_unused                      //  delete only if unused
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_exchange_delete (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        exchange,                    //  exchange name
        if_unused,                   //  delete only if unused
        TRUE);                       //  do not send a reply method

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_queue_declare

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Declare Queue, Create If Needed.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_queue_declare (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    Bool passive,                       //  do not create queue
    Bool durable,                       //  request a durable queue
    Bool exclusive,                     //  request an exclusive queue
    Bool auto_delete,                   //  auto-delete queue when unused
    icl_longstr_t * arguments           //  arguments for declaration
)
{
smt_thread_t
*thread;
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_queue_declare (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        passive,                     //  do not create queue
        durable,                     //  request a durable queue
        exclusive,                   //  request an exclusive queue
        auto_delete,                 //  auto-delete queue when unused
        FALSE,                       //  do not send a reply method
        arguments);                  //  arguments for declaration

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}
//  Action handler after calling method
if (rc == 0) {
if (self->connection->direct && exclusive) {
    thread = amq_client_session_dp_lookup (self, self->queue, DP_FEED);
    if (!thread) {
        thread = amq_client_session_dp_new (self, self->queue, DP_FEED);
        assert (thread);
    }
    smt_thread_unlink (&thread);
}
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_queue_declare_nowait

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Declare Queue, Create If Needed.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_queue_declare_nowait (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    Bool passive,                       //  do not create queue
    Bool durable,                       //  request a durable queue
    Bool exclusive,                     //  request an exclusive queue
    Bool auto_delete,                   //  auto-delete queue when unused
    icl_longstr_t * arguments           //  arguments for declaration
)
{
smt_thread_t
*thread;
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_queue_declare (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        passive,                     //  do not create queue
        durable,                     //  request a durable queue
        exclusive,                   //  request an exclusive queue
        auto_delete,                 //  auto-delete queue when unused
        TRUE,                        //  do not send a reply method
        arguments);                  //  arguments for declaration

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}
//  Action handler after calling method
if (rc == 0) {
if (self->connection->direct && exclusive) {
    thread = amq_client_session_dp_lookup (self, self->queue, DP_FEED);
    if (!thread) {
        thread = amq_client_session_dp_new (self, self->queue, DP_FEED);
        assert (thread);
    }
    smt_thread_unlink (&thread);
}
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_queue_bind

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Bind Queue To An Exchange.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_queue_bind (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    char * exchange,                    //  exchange name
    char * routing_key,                 //  message routing key
    icl_longstr_t * arguments           //  arguments for binding
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_queue_bind (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        exchange,                    //  exchange name
        routing_key,                 //  message routing key
        FALSE,                       //  do not send a reply method
        arguments);                  //  arguments for binding

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_queue_bind_nowait

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Bind Queue To An Exchange.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_queue_bind_nowait (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    char * exchange,                    //  exchange name
    char * routing_key,                 //  message routing key
    icl_longstr_t * arguments           //  arguments for binding
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_queue_bind (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        exchange,                    //  exchange name
        routing_key,                 //  message routing key
        TRUE,                        //  do not send a reply method
        arguments);                  //  arguments for binding

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_queue_purge

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Purge A Queue.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_queue_purge (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue                        //  queue name
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_queue_purge (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        FALSE);                      //  do not send a reply method

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_queue_purge_nowait

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Purge A Queue.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_queue_purge_nowait (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue                        //  queue name
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_queue_purge (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        TRUE);                       //  do not send a reply method

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_queue_delete

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Delete A Queue.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_queue_delete (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    Bool if_unused,                     //  delete only if unused
    Bool if_empty                       //  delete only if empty
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_queue_delete (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        if_unused,                   //  delete only if unused
        if_empty,                    //  delete only if empty
        FALSE);                      //  do not send a reply method

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}
//  Action handler after calling method
if (rc == 0) {
if (self->connection->direct)
    amq_client_session_dp_destroy (self, queue, DP_FEED);
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_queue_delete_nowait

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Delete A Queue.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_queue_delete_nowait (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    Bool if_unused,                     //  delete only if unused
    Bool if_empty                       //  delete only if empty
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_queue_delete (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        if_unused,                   //  delete only if unused
        if_empty,                    //  delete only if empty
        TRUE);                       //  do not send a reply method

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}
//  Action handler after calling method
if (rc == 0) {
if (self->connection->direct)
    amq_client_session_dp_destroy (self, queue, DP_FEED);
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_queue_unbind

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Unbind Queue From An Exchange.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_queue_unbind (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    char * exchange,                    //  exchange name
    char * routing_key,                 //  message routing key
    icl_longstr_t * arguments           //  arguments for binding
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_queue_unbind (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        exchange,                    //  exchange name
        routing_key,                 //  message routing key
        FALSE,                       //  do not send a reply method
        arguments);                  //  arguments for binding

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_queue_unbind_nowait

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Unbind Queue From An Exchange.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_queue_unbind_nowait (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    char * exchange,                    //  exchange name
    char * routing_key,                 //  message routing key
    icl_longstr_t * arguments           //  arguments for binding
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_queue_unbind (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        exchange,                    //  exchange name
        routing_key,                 //  message routing key
        TRUE,                        //  do not send a reply method
        arguments);                  //  arguments for binding

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_basic_qos

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Specify Quality Of Service.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_basic_qos (
    amq_client_session_t * self,        //  Reference to object
    qbyte prefetch_size,                //  prefetch window in octets
    int prefetch_count,                 //  prefetch window in messages
    Bool global                         //  apply to entire connection
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_basic_qos (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        prefetch_size,               //  prefetch window in octets
        prefetch_count,              //  prefetch window in messages
        global);                     //  apply to entire connection

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_basic_consume

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Start A Queue Consumer.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_basic_consume (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    char * consumer_tag,                //  consumer tag
    Bool no_local,                      //  do not deliver own messages
    Bool no_ack,                        //  no acknowledgement needed
    Bool exclusive,                     //  request exclusive access
    icl_longstr_t * arguments           //  arguments for consume
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_basic_consume (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        consumer_tag,                //  consumer tag
        no_local,                    //  do not deliver own messages
        no_ack,                      //  no acknowledgement needed
        exclusive,                   //  request exclusive access
        FALSE,                       //  do not send a reply method
        arguments);                  //  arguments for consume

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_basic_consume_nowait

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Start A Queue Consumer.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_basic_consume_nowait (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    char * consumer_tag,                //  consumer tag
    Bool no_local,                      //  do not deliver own messages
    Bool no_ack,                        //  no acknowledgement needed
    Bool exclusive,                     //  request exclusive access
    icl_longstr_t * arguments           //  arguments for consume
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_basic_consume (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        consumer_tag,                //  consumer tag
        no_local,                    //  do not deliver own messages
        no_ack,                      //  no acknowledgement needed
        exclusive,                   //  request exclusive access
        TRUE,                        //  do not send a reply method
        arguments);                  //  arguments for consume

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_basic_cancel

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    End A Queue Consumer.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_basic_cancel (
    amq_client_session_t * self,        //  Reference to object
    char * consumer_tag                 //  consumer tag
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_basic_cancel (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        consumer_tag,                //  consumer tag
        FALSE);                      //  do not send a reply method

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_basic_cancel_nowait

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    End A Queue Consumer.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_basic_cancel_nowait (
    amq_client_session_t * self,        //  Reference to object
    char * consumer_tag                 //  consumer tag
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_basic_cancel (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        consumer_tag,                //  consumer tag
        TRUE);                       //  do not send a reply method

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_basic_publish

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Publish A Message.
    The caller must create a new amq_content_basic object
    for this call; the object is destroyed after being sent.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_basic_publish (
    amq_client_session_t * self,        //  Reference to object
    amq_content_basic_t * content,      //  Message content
    int ticket,                         //  access ticket granted by server
    char * exchange,                    //  exchange name
    char * routing_key,                 //  Message routing key
    Bool mandatory,                     //  indicate mandatory routing
    Bool immediate                      //  request immediate delivery
)
{
    smt_thread_t
    *thread;
byte
    options;                        //  Encoded Direct Mode options
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

assert (content);                   //  Content must be supplied
//  Action handler before calling method
//
if (amq_client_config_sequence_set (amq_client_config)) {
    amq_content_basic_set_timestamp (content, apr_time_now ());
    amq_content_basic_set_sender_id (content, self->connection->id);
}
if (amq_client_config_chrono_enabled (amq_client_config)
&&  amq_client_config_chrono_density (amq_client_config) > randomof (1000))
    amq_content_basic_chrono_set (content);

if (self->connection->direct) {
    if (exchange == NULL)
        exchange = "";                     //  Default exchange
    thread = amq_client_session_dp_lookup (self, exchange, DP_SINK);
    if (!thread) {
        thread = amq_client_session_dp_new (self, exchange, DP_SINK);
        assert (thread);
    }
    //  Options octet is [0][0][0][0][0][0][mandatory][immediate]
    options = ((mandatory & 1) << 1) | (immediate & 1);
    amq_content_basic_set_routing_key (content, exchange, routing_key, NULL);
    amq_client_agent_direct_out (thread, content, options);
    smt_thread_unlink (&thread);
}
else
if (self->alive) {
    rc = amq_client_agent_basic_publish (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        content,                     //  message content
        ticket,                      //  access ticket granted by server
        exchange,                    //  exchange name
        routing_key,                 //  message routing key
        mandatory,                   //  indicate mandatory routing
        immediate);                  //  request immediate delivery

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
    else
        self->error_text = "unable to send method to protocol agent";
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_basic_get

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Direct Access To A Queue.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_basic_get (
    amq_client_session_t * self,        //  Reference to object
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    Bool no_ack                         //  no acknowledgement needed
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_basic_get (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        ticket,                      //  access ticket granted by server
        queue,                       //  queue name
        no_ack);                     //  no acknowledgement needed

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_basic_ack

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Acknowledge One Or More Messages.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_basic_ack (
    amq_client_session_t * self,        //  Reference to object
    int64_t delivery_tag,               //  server-assigned delivery tag
    Bool multiple                       //  acknowledge multiple messages
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_basic_ack (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        delivery_tag,                //  server-assigned delivery tag
        multiple);                   //  acknowledge multiple messages

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_basic_reject

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Reject An Incoming Message.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_basic_reject (
    amq_client_session_t * self,        //  Reference to object
    int64_t delivery_tag,               //  server-assigned delivery tag
    Bool requeue                        //  requeue the message
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_basic_reject (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        delivery_tag,                //  server-assigned delivery tag
        requeue);                    //  requeue the message

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_restms_pipe_create

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Create A Pipe.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_restms_pipe_create (
    amq_client_session_t * self,        //  Reference to object
    char * pipe_type,                   //  pipe type
    char * pipe_name                    //  Name of pipe
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_restms_pipe_create (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        pipe_type,                   //  pipe type
        pipe_name);                  //  name of pipe

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_restms_pipe_delete

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Delete A Pipe.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_restms_pipe_delete (
    amq_client_session_t * self,        //  Reference to object
    char * pipe_name                    //  pipe name
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_restms_pipe_delete (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        pipe_name);                  //  pipe name

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_restms_feed_create

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Create A Feed.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_restms_feed_create (
    amq_client_session_t * self,        //  Reference to object
    char * feed_type,                   //  Feed type
    char * feed_name                    //  Name of feed
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_restms_feed_create (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        feed_type,                   //  feed type
        feed_name);                  //  name of feed

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_restms_feed_delete

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Delete A Feed.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_restms_feed_delete (
    amq_client_session_t * self,        //  Reference to object
    char * feed_name                    //  feed name
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_restms_feed_delete (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        feed_name);                  //  feed name

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_restms_join_create

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Create A Join.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_restms_join_create (
    amq_client_session_t * self,        //  Reference to object
    char * pipe_name,                   //  Name of pipe
    char * feed_name,                   //  Name of feed
    char * address                      //  Join address
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_restms_join_create (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        pipe_name,                   //  name of pipe
        feed_name,                   //  name of feed
        address);                    //  join address

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_restms_join_delete

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Delete A Join.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_restms_join_delete (
    amq_client_session_t * self,        //  Reference to object
    char * pipe_name,                   //  Name of pipe
    char * feed_name,                   //  Name of feed
    char * address                      //  Join address
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = amq_client_agent_restms_join_delete (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        pipe_name,                   //  name of pipe
        feed_name,                   //  name of feed
        address);                    //  join address

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_push_arrived

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Stores an arrived content, and takes appropriate action if the arrived
    queue hits the high water mark.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_push_arrived (
    amq_client_session_t * self,        //  Reference to object
    amq_content_basic_t * content,      //  Message content
    char * exchange,                    //  Value to stamp into content
    char * routing_key,                 //  Value to stamp into content
    char * consumer_tag,                //  Value to stamp into content
    int64_t delivery_tag                //  Value to stamp into content
)
{
size_t
    high_water,                     //  Value of high water setting
    queue_size;                     //  Queue size before we push our content
char
    *on_overflow;                   //  on_overflow action for direct connections
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

//
//  Stamp content with values from method, if any
if (exchange && *exchange)
    icl_shortstr_cpy (content->exchange, exchange);
if (routing_key && routing_key)
    icl_shortstr_cpy (content->routing_key, routing_key);
if (consumer_tag && *consumer_tag)
    icl_shortstr_cpy (content->consumer_tag, consumer_tag);
content->delivery_tag = delivery_tag;

//  Send chronometer deltas, if any, to chrono@amq.status exchange
if (amq_client_config_chrono_enabled (amq_client_config))
    s_process_chrono (self, content);

//  Check if queue would overflow, take appropriate action
high_water = amq_client_config_high_water (amq_client_config);
if (high_water) {                   //  If it's zero, we don't interfere
    queue_size = self_get_basic_arrived_count (self);
    if (queue_size == high_water) {
        if (self->connection->direct) {
            on_overflow = amq_client_config_on_overflow (amq_client_config);
            if (streq (on_overflow, "warn")) {
                //  Warn that we hit high-water, but only once per tide
                if (icl_atomic_cas32 (&self->flow_stopped, TRUE, FALSE) == FALSE) {
                    icl_console_print ("W: high-water mark reached, application is too slow");
                    icl_console_print ("I: contact iMatix for help on tuning your application");
                }
            }
            else
            if (streq (on_overflow, "trim")) {
                //  Chuck away oldest content on arrived list
                amq_content_basic_t
                    *trimmed;
                trimmed = amq_content_basic_list_pop (self->arrived_basic_list);
                amq_content_basic_unlink (&trimmed);
            }
            else
            if (streq (on_overflow, "drop")) {
                //  Chuck away new incoming content
                content = NULL;     //  Just don't store the content
            }
            else
            if (streq (on_overflow, "kill")) {
                //  To die. In the rain. Alone.
                icl_system_panic ("amq_client_session",
                    "E: high water reached (%d): on_overflow requested fatal stop", high_water);
                icl_system_panic ("amq_client_session",
                    "I: contact iMatix for help on tuning your application");
                exit (1);
            }
        }
        else
        //  If we're in normal AMQP mode, send Channel.Flow Off if needed
        if (icl_atomic_cas32 (&self->flow_stopped, TRUE, FALSE) == FALSE)
            amq_client_session_channel_flow (self, FALSE);
    }
}
//  Queue content if we did not discard it
if (content)
    amq_content_basic_list_queue (self->arrived_basic_list, content);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_push_returned

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Stores a returned content.  Currently not guarded by any high water marks.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_push_returned (
    amq_client_session_t * self,        //  Reference to object
    amq_content_basic_t * content,      //  Message content
    char * exchange,                    //  Value to stamp into content
    char * routing_key,                 //  Value to stamp into content
    char * consumer_tag                 //  Value to stamp into content
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

//
//  Stamp content with values from method, if any
if (exchange && *exchange)
    icl_shortstr_cpy (content->exchange, exchange);
if (routing_key && routing_key)
    icl_shortstr_cpy (content->routing_key, routing_key);
if (consumer_tag && *consumer_tag)
    icl_shortstr_cpy (content->consumer_tag, consumer_tag);
content->delivery_tag = 0;

//  Set the returned flag - is this actually useful?
content->returned = TRUE;

//  Queue content
amq_content_basic_list_queue (self->returned_basic_list, content);
if (!self->connection->silent)
    icl_console_print ("W: basic message was returned: %d - %s",
        self->reply_code, self->reply_text);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_basic_arrived_count

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_get_basic_arrived_count (
    amq_client_session_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

rc = amq_content_basic_list_count (self->arrived_basic_list);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_basic_arrived

    Type: Component method
    -------------------------------------------------------------------------
 */

amq_content_basic_t *
    amq_client_session_basic_arrived (
    amq_client_session_t * self         //  Session object
)
{
    amq_content_basic_t *
        content = NULL;                 //  Message content

//
//  Get next message off list, if any
content = amq_content_basic_list_pop (self->arrived_basic_list);

//  Patch session to properly reflect this content's properties
if (content) {
    icl_shortstr_cpy (self->exchange, content->exchange);
    icl_shortstr_cpy (self->routing_key, content->routing_key);
    if (*content->consumer_tag)
        icl_shortstr_cpy (self->consumer_tag, content->consumer_tag);
    self->delivery_tag = content->delivery_tag;
}
if (amq_client_config_high_water (amq_client_config)
&& self_get_basic_arrived_count (self) == amq_client_config_low_water (amq_client_config)
&& icl_atomic_cas32 (&self->flow_stopped, FALSE, TRUE) == TRUE)
    self_channel_flow (self, TRUE);

    return (content);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_basic_returned_count

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_get_basic_returned_count (
    amq_client_session_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

rc = amq_content_basic_list_count (self->returned_basic_list);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_basic_returned

    Type: Component method
    -------------------------------------------------------------------------
 */

amq_content_basic_t *
    amq_client_session_basic_returned (
    amq_client_session_t * self         //  Session object
)
{
    amq_content_basic_t *
        content = NULL;                 //  Message content

//
//  Get next message off list, if any
content = amq_content_basic_list_pop (self->returned_basic_list);

    return (content);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_alive

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_client_session_get_alive (
    amq_client_session_t * self         //  Object reference
)
{
    Bool
        alive;                          //  Not documented

//
alive = self->alive;

    return (alive);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_error_text

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_session_get_error_text (
    amq_client_session_t * self         //  Object reference
)
{
    char *
        error_text;                     //  Not documented

//
error_text = self->error_text;

    return (error_text);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_lease

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_session_get_lease (
    amq_client_session_t * self         //  Object reference
)
{
    char *
        lease;                          //  Not documented

//
lease = self->lease;

    return (lease);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_channel_id

    Type: Component method
    -------------------------------------------------------------------------
 */

icl_longstr_t *
    amq_client_session_get_channel_id (
    amq_client_session_t * self         //  Object reference
)
{
    icl_longstr_t *
        channel_id;                     //  Not documented

//
channel_id = self->channel_id;

    return (channel_id);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_active

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_client_session_get_active (
    amq_client_session_t * self         //  Object reference
)
{
    Bool
        active;                         //  Not documented

//
active = self->active;

    return (active);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_reply_code

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_session_get_reply_code (
    amq_client_session_t * self         //  Object reference
)
{
    int
        reply_code;                     //  Not documented

//
reply_code = self->reply_code;

    return (reply_code);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_reply_text

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_session_get_reply_text (
    amq_client_session_t * self         //  Object reference
)
{
    char *
        reply_text;                     //  Not documented

//
reply_text = self->reply_text;

    return (reply_text);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_class_id

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_session_get_class_id (
    amq_client_session_t * self         //  Object reference
)
{
    int
        class_id;                       //  Not documented

//
class_id = self->class_id;

    return (class_id);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_method_id

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_session_get_method_id (
    amq_client_session_t * self         //  Object reference
)
{
    int
        method_id;                      //  Not documented

//
method_id = self->method_id;

    return (method_id);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_consumer_tag

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_session_get_consumer_tag (
    amq_client_session_t * self         //  Object reference
)
{
    char *
        consumer_tag;                   //  Not documented

//
consumer_tag = self->consumer_tag;

    return (consumer_tag);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_exchange

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_session_get_exchange (
    amq_client_session_t * self         //  Object reference
)
{
    char *
        exchange;                       //  Not documented

//
exchange = self->exchange;

    return (exchange);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_routing_key

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_session_get_routing_key (
    amq_client_session_t * self         //  Object reference
)
{
    char *
        routing_key;                    //  Not documented

//
routing_key = self->routing_key;

    return (routing_key);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_delivery_tag

    Type: Component method
    -------------------------------------------------------------------------
 */

int64_t
    amq_client_session_get_delivery_tag (
    amq_client_session_t * self         //  Object reference
)
{
    int64_t
        delivery_tag;                   //  Not documented

//
delivery_tag = self->delivery_tag;

    return (delivery_tag);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_redelivered

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_client_session_get_redelivered (
    amq_client_session_t * self         //  Object reference
)
{
    Bool
        redelivered;                    //  Not documented

//
redelivered = self->redelivered;

    return (redelivered);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_message_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_client_session_get_message_count (
    amq_client_session_t * self         //  Object reference
)
{
    qbyte
        message_count;                  //  Not documented

//
message_count = self->message_count;

    return (message_count);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_sender_id

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_session_get_sender_id (
    amq_client_session_t * self         //  Object reference
)
{
    char *
        sender_id;                      //  Not documented

//
sender_id = self->sender_id;

    return (sender_id);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_queue

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_session_get_queue (
    amq_client_session_t * self         //  Object reference
)
{
    char *
        queue;                          //  Not documented

//
queue = self->queue;

    return (queue);
}
/*  -------------------------------------------------------------------------
    amq_client_session_get_consumer_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_client_session_get_consumer_count (
    amq_client_session_t * self         //  Object reference
)
{
    qbyte
        consumer_count;                 //  Not documented

//
consumer_count = self->consumer_count;

    return (consumer_count);
}
/*  -------------------------------------------------------------------------
    amq_client_session_dp_new

    Type: Component method
    -------------------------------------------------------------------------
 */

smt_thread_t *
    amq_client_session_dp_new (
    amq_client_session_t * self,        //  Session object
    char * name,                        //  Resource name
    int type                            //  Resource type
)
{
int
    rc = 0;
ipr_hash_t
    *hash;
    smt_thread_t *
        thread = NULL;                  //  Not documented

//
//  Start a new direct connection
//  - send Direct.Put or Direct.Get via main connection
//  - server provides lease via Put-Ok or Get-Ok
//  - create new direct thread and give it the lease
//
assert (type == DP_SINK || type == DP_FEED);
if (name == NULL)
    name = "";                            //  Blank name is valid

//  Request lease and wait for response
if (type == DP_SINK)
    amq_client_agent_direct_put (self->connection->thread, self->channel_nbr, name);
else
    amq_client_agent_direct_get (self->connection->thread, self->channel_nbr, name);
rc = s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE);
assert (!rc);

//  Create direct connection thread and wait for it to signal ready
thread = amq_client_agent_direct_thread_new (
    type,
    self->method_queue,
    self->connection->host,
    self->lease,
    self->connection->trace,
    self->connection->timeout);
assert (thread);
smt_thread_wake (thread);
rc = s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE);
assert (!rc);

//  Store thread in hash table with extra link, so that caller can
//  unlink thread properly.
if (type == DP_SINK)
    hash = ipr_hash_new (self->dp_sinks, name, smt_thread_link (thread));
else
    hash = ipr_hash_new (self->dp_feeds, name, smt_thread_link (thread));
ipr_hash_unlink (&hash);

    return (thread);
}
/*  -------------------------------------------------------------------------
    amq_client_session_dp_lookup

    Type: Component method
    -------------------------------------------------------------------------
 */

smt_thread_t *
    amq_client_session_dp_lookup (
    amq_client_session_t * self,        //  Session object
    char * name,                        //  Resource name
    int type                            //  Resource type
)
{
ipr_hash_t
    *hash;
    smt_thread_t *
        thread = NULL;                  //  Not documented

//

assert (type == DP_SINK || type == DP_FEED);
if (type == DP_SINK)
    hash = ipr_hash_table_search (self->dp_sinks, name);
else
    hash = ipr_hash_table_search (self->dp_feeds, name);

if (hash) {
    thread = smt_thread_link ((smt_thread_t *) hash->data);
    ipr_hash_unlink (&hash);
}

    return (thread);
}
/*  -------------------------------------------------------------------------
    amq_client_session_dp_destroy

    Type: Component method
    Accepts a amq_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_session_dp_destroy (
    amq_client_session_t * self,        //  Reference to object
    char * name,                        //  Resource name
    int type                            //  Resource type
)
{
ipr_hash_t
    *hash;
    int
        rc = 0;                         //  Return code

AMQ_CLIENT_SESSION_ASSERT_SANE (self);

//
assert (type == DP_SINK || type == DP_FEED);
if (type == DP_SINK) {
    hash = ipr_hash_table_search (self->dp_sinks, name);
    if (hash) {
        s_close_dp_connection (hash, self);
        ipr_hash_destroy (&hash);
    }
}
else {
    hash = ipr_hash_table_search (self->dp_feeds, name);
    if (hash) {
        s_close_dp_connection (hash, self);
        ipr_hash_destroy (&hash);
    }
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_session_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_session_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_client_session_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_client_session_mutex)
            s_amq_client_session_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_client_session_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_client_session_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_client_agent_init ();
            s_amq_client_session_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_client_session_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    amq_client_session_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_session_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_client_session_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_session_terminate (
void)
{

if (s_amq_client_session_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_client_session_mutex);
#endif
        s_amq_client_session_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    amq_client_session_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_session_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_client_session_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_client_session file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_client_session_destroy

    Type: Component method
    Destroys a amq_client_session_t object. Takes the address of a
    amq_client_session_t reference (a pointer to a pointer) and nullifies the
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
    amq_client_session_destroy_ (
    amq_client_session_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_client_session_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_client_session_annihilate (self_p);
    amq_client_session_free ((amq_client_session_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_client_session_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_client_session_t *
    amq_client_session_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_client_session_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_client_session_cache_initialise ();

self = (amq_client_session_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_client_session_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_session_free

    Type: Component method
    Freess a amq_client_session_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_client_session_free (
    amq_client_session_t * self         //  Object reference
)
{


if (self) {

        memset (&self->object_tag, 0, sizeof (amq_client_session_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_client_session_t));
        self->object_tag = AMQ_CLIENT_SESSION_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_client_session_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_client_session_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_client_session_t));
icl_system_register (amq_client_session_cache_purge, amq_client_session_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_client_session_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_session_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_client_session_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_session_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_client_session_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_client_session_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_client_session_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_client_session_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_session_new_in_scope_ (
    amq_client_session_t * * self_p,    //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_connection_t * connection  //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_client_session_new_ (file,line,connection);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_client_session_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
/*  Waits for methods from the protocol agent.  If the blocking argument
    is true, returns only when receiving a synchronous reply method.  If not,
    returns when any incoming method is received.  Returns 0 if ok, -1 if
    the connection is closed or a blocking wait timed-out.
 */
static int
s_wait_for_methods (
    amq_client_session_t *self,
    int timeout,
    Bool blocking,
    Bool on_content)
{
    smt_method_t
        *smt_method = NULL;
    amq_client_method_t
        *proto_method;
    int
        rc = 0;                         //  OK by default

    assert (!self->method_queue->zombie);
    FOREVER {
        smt_method_unlink (&smt_method);
        if (timeout >= 0)
            smt_method_queue_wait (self->method_queue, timeout);
        smt_method = smt_method_queue_pop (self->method_queue);
        //  If we don't have a method, we timed-out
        if (!smt_method) {
            if (blocking) {
                if (self->method_queue->zombie)
                    self->error_text = "No reply - method queue destroyed";
                else
                    self->error_text = "No reply received - timeout";
                rc = -1;
            }
            break;
        }
        //  ALMOST means we should wait for the next method...
        if (smt_method->result == AMQ_CLIENT_REPLY_ALMOST) {
            proto_method = (amq_client_method_t *) smt_method->data;
            if (proto_method)
                amq_client_method_execute (proto_method, self->connection, self);
        }
        else
        //  INTERN is an internal synchronisation from the agent
        if (smt_method->result == AMQ_CLIENT_REPLY_INTERN)
            break;                      //  We can return to caller
        else
        //  METHOD means the agent is sending us either:
        //    - a sync method, which is a reply to a sync request
        //    - an async method, which we want to process and then continue
        //
        //  We always stop when we get a sync method. If we have an async
        //  method, we stop only if the queue is empty and we're not blocking.
        //  Blocking means we want a sync method within the timeout.
        //
        if (smt_method->result == AMQ_CLIENT_REPLY_METHOD) {
            proto_method = (amq_client_method_t *) smt_method->data;
            if (proto_method) {
                amq_client_method_execute (proto_method, self->connection, self);
                if (proto_method->sync
                || (proto_method->content && on_content))
                    break;              //  Got synchronous method, end
            }
            else
                break;                  //  Synchronisation from agent
        }
        else
        if (smt_method->result == AMQ_CLIENT_REPLY_CLOSED) {
            self->error_text = "session is closed";
            self->alive = FALSE;        //  Session is closed
            rc = -1;                    //  Signal session is closed
            break;                      //  We can return to caller
        }
        else
        //  DIRECT_OK means the direct thread started ok
        if (smt_method->result == AMQ_CLIENT_REPLY_DIRECT_OK)
            break;                      //  We can return to caller
        else
        //  DIRECT_NG means the direct thread did not start
        if (smt_method->result == AMQ_CLIENT_REPLY_DIRECT_NG) {
            self->error_text = "direct connection failed";
            rc = -1;                    //  Signal session is closed
            break;                      //  We can return to caller
        }
        else
        //  DIRECT_MSG means we have a message, process & continue
        if (smt_method->result == AMQ_CLIENT_REPLY_DIRECT_MSG) {
            self_push_arrived (
                self, (amq_content_basic_t *) smt_method->data, NULL, NULL, NULL, 0);
            if (on_content)
                break;                  //  We were waiting for content
        }
        else {
            self->error_text = "Internal error - invalid reply method from protocol agent";
            icl_console_print ("E: invalid reply result %d", smt_method->result);
        }
    }
    smt_method_unlink (&smt_method);
    return (rc);
}

static void
s_process_chrono (
    amq_client_session_t *self,
    amq_content_basic_t *content)
{
    icl_shortstr_t
        deltas;                         //  Chronometer deltas
    int
        floor = amq_client_config_chrono_floor (amq_client_config);

    amq_content_basic_chrono_add (content);
    amq_content_basic_chrono_get (content, deltas, floor);
    if (*deltas) {
        size_t
            size = strlen (self->chrono_block);
        if (size > (uint) amq_client_config_chrono_batch (amq_client_config)) {
            amq_content_basic_t
                *content;

            //  We can't publish the chrono block here since we're in the
            //  middle of handling events from the client agent; if we try
            //  a publish we will open a new instance of this event handler
            //  which gets us into unpleasant territory.  So we queue the
            //  content for later dispatching.
            //
            content = amq_content_basic_new ();
            amq_content_basic_set_body (content, self->chrono_block, size, icl_mem_free);
            amq_content_basic_list_queue (self->chrono_list, content);
            amq_content_basic_unlink (&content);

            //  Allocate a new chrono block
            self->chrono_block = icl_mem_alloc (
                amq_client_config_chrono_batch (amq_client_config)
                + ICL_SHORTSTR_MAX);
            strclr (self->chrono_block);
        }
        //  It is impossible to append a literal newline due to GSL's
        //  pleasure in unescaping backslashes, sorry for this nasty
        //  hack.  10 is of course a newline character.
        if (*self->chrono_block) {
            strcat (self->chrono_block, " ");
            strlast (self->chrono_block) = 10;
        }
        strcat (self->chrono_block, deltas);
    }
}

static void
s_close_dp_connection (ipr_hash_t *hash, void *argument)
{
    amq_client_session_t
        *self = argument;
    smt_thread_t
        *thread = (smt_thread_t *) hash->data;

    //  Ensure connection is really closed before returning to caller
    //  This call will also flush any data pending to be written
    amq_client_agent_direct_close (thread);
    s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE);
    smt_thread_unlink (&thread);
}

//  Embed the version information in the resulting binary

char *EMBED__amq_client_session_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_client_session_component  = "amq_client_session ";
char *EMBED__amq_client_session_version   = "1.0 ";
char *EMBED__amq_client_session_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_client_session_filename  = "amq_client_session.icl ";
char *EMBED__amq_client_session_builddate  = "2010/10/06 ";
char *EMBED__amq_client_session_version_end  = "VeRsIoNeNd:ipc";

