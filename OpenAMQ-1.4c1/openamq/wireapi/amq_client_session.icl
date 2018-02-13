<?xml?>
<!--
    *** GENERATED FROM amq_client.asl BY ASL_GEN USING GSL/4 ***

    
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
 -->
<class
    name      = "amq_client_session"
    comment   = "amq_client connection session class"
    version   = "1.0"
    script    = "icl_gen"
    license   = "gpl"
    >
<doc>
This class provides the session serialisation API.
</doc>

<inherit class = "icl_object">
    <option name = "alloc" value = "cache" />
</inherit>
<inherit class = "icl_init" />

<import class = "amq_client_classes" />
<import class = "amq_constants" />
<import class = "amq_client_connection" />
<import class = "amq_content_basic_list" />

<context>
    amq_client_connection_t
        *connection;                    //  Parent connection object
    smt_method_queue_t
        *method_queue;                  //  Replies from protocol agent
    dbyte
        channel_nbr;                    //  Session channel number
    Bool
        alive;                          //  Is the session alive?
    apr_time_t
        timestamp;                      //  Time session was opened
    volatile qbyte
        flow_stopped;                   //  Is flow of messages from server stopped?
    char
        *error_text;                    //  Last error cause
    char
        *chrono_block;                  //  Accumulated chrono deltas
    ipr_hash_table_t
        *dp_sinks,                      //  DP sink threads
        *dp_feeds;                      //  DP feed threads
    icl_shortstr_t
        lease;                          //  Lease for connection
    icl_longstr_t *
        channel_id;                     //  unique id of the channel
    Bool
        active;                         //  start/stop content frames
    dbyte
        reply_code;                     //  reply code from server
    icl_shortstr_t
        reply_text;                     //  localised reply text
    dbyte
        class_id;                       //  failing method class
    dbyte
        method_id;                      //  failing method ID
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        routing_key;                    //  Message routing key
    int64_t
        delivery_tag;                   //  server-assigned delivery tag
    Bool
        redelivered;                    //  message is being redelivered
    qbyte
        message_count;                  //  number of messages pending
    icl_shortstr_t
        sender_id;                      //  Sender id
    icl_shortstr_t
        queue;                          //  queue name
    qbyte
        consumer_count;                 //  number of consumers
    amq_sequence_table_t
        *sequences;                     //  Timestamp per connection id
    //  Handling for basic messages
    amq_content_basic_list_t
        *arrived_basic_list;            //  Basic messages
    amq_content_basic_list_t
        *returned_basic_list;           //  Returned basic messages
    amq_content_basic_list_t
        *chrono_list;                   //  Pending chrono messages
</context>

<method name = "new">
    <doc>
    Create new session on an established connection.

    The connection argument refers to a previously-created connection
    object.
    </doc>
    <argument name = "connection" type = "amq_client_connection_t *" />
    <local>
    int
        rc;
    </local>
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
</method>

<method name = "destroy">
    <doc>
    Close the session.
    </doc>
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
</method>

<method name = "wait" template = "function">
    <doc>
    Waits for any activity on the session.  Returns 0 if content arrived
    or the timeout expired, -1 if the session ended abnormally.  If the timeout
    is zero, waits forever.  If the timeout is -1, does not wait at all, but
    processes pending methods and then returns.
    </doc>
    <argument name = "timeout" type = "int">Timeout, in milliseconds</argument>
    <local>
    amq_content_basic_t
        *content;
    </local>
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
</method>

<method name = "channel flow" template = "function">
    <doc>
    Enable/Disable Flow From Peer.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "active" type = "Bool">start/stop content frames</argument>
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
</method>

<method name = "channel flow-ok" template = "function">
    <doc>
    Confirm A Flow Method.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "active" type = "Bool">current flow setting</argument>
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
</method>

<method name = "exchange declare" template = "function">
    <doc>
    Declare Exchange, Create If Needed.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "exchange" type = "char *">exchange name</argument>
    <argument name = "type" type = "char *">exchange type</argument>
    <argument name = "passive" type = "Bool">do not create exchange</argument>
    <argument name = "durable" type = "Bool">request a durable exchange</argument>
    <argument name = "auto_delete" type = "Bool">auto-delete when unused</argument>
    <argument name = "internal" type = "Bool">create internal exchange</argument>
    <argument name = "arguments" type = "icl_longstr_t *">arguments for declaration</argument>
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
</method>

<method name = "exchange declare nowait" template = "function">
    <doc>
    Declare Exchange, Create If Needed.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "exchange" type = "char *">exchange name</argument>
    <argument name = "type" type = "char *">exchange type</argument>
    <argument name = "passive" type = "Bool">do not create exchange</argument>
    <argument name = "durable" type = "Bool">request a durable exchange</argument>
    <argument name = "auto_delete" type = "Bool">auto-delete when unused</argument>
    <argument name = "internal" type = "Bool">create internal exchange</argument>
    <argument name = "arguments" type = "icl_longstr_t *">arguments for declaration</argument>
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
</method>

<method name = "exchange delete" template = "function">
    <doc>
    Delete An Exchange.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "exchange" type = "char *">exchange name</argument>
    <argument name = "if_unused" type = "Bool">delete only if unused</argument>
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
</method>

<method name = "exchange delete nowait" template = "function">
    <doc>
    Delete An Exchange.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "exchange" type = "char *">exchange name</argument>
    <argument name = "if_unused" type = "Bool">delete only if unused</argument>
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
</method>

<method name = "queue declare" template = "function">
    <doc>
    Declare Queue, Create If Needed.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
    <argument name = "passive" type = "Bool">do not create queue</argument>
    <argument name = "durable" type = "Bool">request a durable queue</argument>
    <argument name = "exclusive" type = "Bool">request an exclusive queue</argument>
    <argument name = "auto_delete" type = "Bool">auto-delete queue when unused</argument>
    <argument name = "arguments" type = "icl_longstr_t *">arguments for declaration</argument>
    <local>
        smt_thread_t
        *thread;
    </local>
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
</method>

<method name = "queue declare nowait" template = "function">
    <doc>
    Declare Queue, Create If Needed.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
    <argument name = "passive" type = "Bool">do not create queue</argument>
    <argument name = "durable" type = "Bool">request a durable queue</argument>
    <argument name = "exclusive" type = "Bool">request an exclusive queue</argument>
    <argument name = "auto_delete" type = "Bool">auto-delete queue when unused</argument>
    <argument name = "arguments" type = "icl_longstr_t *">arguments for declaration</argument>
    <local>
        smt_thread_t
        *thread;
    </local>
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
</method>

<method name = "queue bind" template = "function">
    <doc>
    Bind Queue To An Exchange.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
    <argument name = "exchange" type = "char *">exchange name</argument>
    <argument name = "routing_key" type = "char *">message routing key</argument>
    <argument name = "arguments" type = "icl_longstr_t *">arguments for binding</argument>
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
</method>

<method name = "queue bind nowait" template = "function">
    <doc>
    Bind Queue To An Exchange.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
    <argument name = "exchange" type = "char *">exchange name</argument>
    <argument name = "routing_key" type = "char *">message routing key</argument>
    <argument name = "arguments" type = "icl_longstr_t *">arguments for binding</argument>
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
</method>

<method name = "queue purge" template = "function">
    <doc>
    Purge A Queue.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
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
</method>

<method name = "queue purge nowait" template = "function">
    <doc>
    Purge A Queue.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
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
</method>

<method name = "queue delete" template = "function">
    <doc>
    Delete A Queue.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
    <argument name = "if_unused" type = "Bool">delete only if unused</argument>
    <argument name = "if_empty" type = "Bool">delete only if empty</argument>
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
</method>

<method name = "queue delete nowait" template = "function">
    <doc>
    Delete A Queue.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
    <argument name = "if_unused" type = "Bool">delete only if unused</argument>
    <argument name = "if_empty" type = "Bool">delete only if empty</argument>
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
</method>

<method name = "queue unbind" template = "function">
    <doc>
    Unbind Queue From An Exchange.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
    <argument name = "exchange" type = "char *">exchange name</argument>
    <argument name = "routing_key" type = "char *">message routing key</argument>
    <argument name = "arguments" type = "icl_longstr_t *">arguments for binding</argument>
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
</method>

<method name = "queue unbind nowait" template = "function">
    <doc>
    Unbind Queue From An Exchange.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
    <argument name = "exchange" type = "char *">exchange name</argument>
    <argument name = "routing_key" type = "char *">message routing key</argument>
    <argument name = "arguments" type = "icl_longstr_t *">arguments for binding</argument>
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
</method>

<method name = "basic qos" template = "function">
    <doc>
    Specify Quality Of Service.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "prefetch_size" type = "qbyte">prefetch window in octets</argument>
    <argument name = "prefetch_count" type = "int">prefetch window in messages</argument>
    <argument name = "global" type = "Bool">apply to entire connection</argument>
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
</method>

<method name = "basic consume" template = "function">
    <doc>
    Start A Queue Consumer.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
    <argument name = "consumer_tag" type = "char *">consumer tag</argument>
    <argument name = "no_local" type = "Bool">do not deliver own messages</argument>
    <argument name = "no_ack" type = "Bool">no acknowledgement needed</argument>
    <argument name = "exclusive" type = "Bool">request exclusive access</argument>
    <argument name = "arguments" type = "icl_longstr_t *">arguments for consume</argument>
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
</method>

<method name = "basic consume nowait" template = "function">
    <doc>
    Start A Queue Consumer.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
    <argument name = "consumer_tag" type = "char *">consumer tag</argument>
    <argument name = "no_local" type = "Bool">do not deliver own messages</argument>
    <argument name = "no_ack" type = "Bool">no acknowledgement needed</argument>
    <argument name = "exclusive" type = "Bool">request exclusive access</argument>
    <argument name = "arguments" type = "icl_longstr_t *">arguments for consume</argument>
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
</method>

<method name = "basic cancel" template = "function">
    <doc>
    End A Queue Consumer.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "consumer_tag" type = "char *">consumer tag</argument>
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
</method>

<method name = "basic cancel nowait" template = "function">
    <doc>
    End A Queue Consumer.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "consumer_tag" type = "char *">consumer tag</argument>
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
</method>

<method name = "basic publish" template = "function">
    <doc>
    Publish A Message.
    The caller must create a new amq_content_basic object
    for this call; the object is destroyed after being sent.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "content" type = "amq_content_basic_t *">Message content</argument>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "exchange" type = "char *">exchange name</argument>
    <argument name = "routing_key" type = "char *">Message routing key</argument>
    <argument name = "mandatory" type = "Bool">indicate mandatory routing</argument>
    <argument name = "immediate" type = "Bool">request immediate delivery</argument>
    <local>
        smt_thread_t
        *thread;
    byte
        options;                        //  Encoded Direct Mode options
    </local>
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
</method>

<method name = "basic get" template = "function">
    <doc>
    Direct Access To A Queue.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "ticket" type = "int">access ticket granted by server</argument>
    <argument name = "queue" type = "char *">queue name</argument>
    <argument name = "no_ack" type = "Bool">no acknowledgement needed</argument>
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
</method>

<method name = "basic ack" template = "function">
    <doc>
    Acknowledge One Or More Messages.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "delivery_tag" type = "int64_t">server-assigned delivery tag</argument>
    <argument name = "multiple" type = "Bool">acknowledge multiple messages</argument>
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
</method>

<method name = "basic reject" template = "function">
    <doc>
    Reject An Incoming Message.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "delivery_tag" type = "int64_t">server-assigned delivery tag</argument>
    <argument name = "requeue" type = "Bool">requeue the message</argument>
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
</method>

<method name = "restms pipe-create" template = "function">
    <doc>
    Create A Pipe.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "pipe_type" type = "char *">pipe type</argument>
    <argument name = "pipe_name" type = "char *">Name of pipe</argument>
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
</method>

<method name = "restms pipe-delete" template = "function">
    <doc>
    Delete A Pipe.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "pipe_name" type = "char *">pipe name</argument>
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
</method>

<method name = "restms feed-create" template = "function">
    <doc>
    Create A Feed.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "feed_type" type = "char *">Feed type</argument>
    <argument name = "feed_name" type = "char *">Name of feed</argument>
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
</method>

<method name = "restms feed-delete" template = "function">
    <doc>
    Delete A Feed.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "feed_name" type = "char *">feed name</argument>
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
</method>

<method name = "restms join-create" template = "function">
    <doc>
    Create A Join.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "pipe_name" type = "char *">Name of pipe</argument>
    <argument name = "feed_name" type = "char *">Name of feed</argument>
    <argument name = "address" type = "char *">Join address</argument>
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
</method>

<method name = "restms join-delete" template = "function">
    <doc>
    Delete A Join.
    Returns 0 on success, 1 on failure.
    </doc>
    <argument name = "pipe_name" type = "char *">Name of pipe</argument>
    <argument name = "feed_name" type = "char *">Name of feed</argument>
    <argument name = "address" type = "char *">Join address</argument>
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
</method>

<method name = "push arrived" template = "function">
    <doc>
    Stores an arrived content, and takes appropriate action if the arrived
    queue hits the high water mark.
    </doc>
    <argument name = "content" type = "amq_content_basic_t *">Message content</argument>
    <argument name = "exchange" type = "char *">Value to stamp into content</argument>
    <argument name = "routing key" type = "char *">Value to stamp into content</argument>
    <argument name = "consumer tag" type = "char *">Value to stamp into content</argument>
    <argument name = "delivery tag" type = "int64_t">Value to stamp into content</argument>
    <local>
    size_t
        high_water,                     //  Value of high water setting
        queue_size;                     //  Queue size before we push our content
    char
        *on_overflow;                   //  on_overflow action for direct connections
    </local>
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
</method>

<method name = "push returned" template = "function">
    <doc>
    Stores a returned content.  Currently not guarded by any high water marks.
    </doc>
    <argument name = "content" type = "amq_content_basic_t *">Message content</argument>
    <argument name = "exchange" type = "char *">Value to stamp into content</argument>
    <argument name = "routing key" type = "char *">Value to stamp into content</argument>
    <argument name = "consumer tag" type = "char *">Value to stamp into content</argument>
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
</method>

<method name = "get basic arrived count" template = "function">
    rc = amq_content_basic_list_count (self->arrived_basic_list);
</method>

<method name = "basic arrived" return = "content">
    <argument name = "self"  type = "$(selftype) *">Session object</argument>
    <declare name = "content" type = "amq_content_basic_t *" default = "NULL">Message content</declare>
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
</method>

<method name = "get basic returned count" template = "function">
    rc = amq_content_basic_list_count (self->returned_basic_list);
</method>

<method name = "basic returned" return = "content">
    <argument name = "self"  type = "$(selftype) *">Session object</argument>
    <declare name = "content" type = "amq_content_basic_t *" default = "NULL">Message content</declare>
    //
    //  Get next message off list, if any
    content = amq_content_basic_list_pop (self->returned_basic_list);
</method>

<method name = "get alive" return = "alive">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "alive" type = "Bool" />
    //
    alive = self->alive;
</method>

<method name = "get error text" return = "error text">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "error text" type = "char *" />
    //
    error_text = self->error_text;
</method>

<method name = "get lease" return = "lease">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "lease" type = "char *" />
    //
    lease = self->lease;
</method>

<method name = "get channel_id" return = "channel_id">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "channel_id" type = "icl_longstr_t *" />
    //
    channel_id = self->channel_id;
</method>

<method name = "get active" return = "active">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "active" type = "Bool" />
    //
    active = self->active;
</method>

<method name = "get reply_code" return = "reply_code">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "reply_code" type = "int" />
    //
    reply_code = self->reply_code;
</method>

<method name = "get reply_text" return = "reply_text">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "reply_text" type = "char *" />
    //
    reply_text = self->reply_text;
</method>

<method name = "get class_id" return = "class_id">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "class_id" type = "int" />
    //
    class_id = self->class_id;
</method>

<method name = "get method_id" return = "method_id">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "method_id" type = "int" />
    //
    method_id = self->method_id;
</method>

<method name = "get consumer_tag" return = "consumer_tag">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "consumer_tag" type = "char *" />
    //
    consumer_tag = self->consumer_tag;
</method>

<method name = "get exchange" return = "exchange">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "exchange" type = "char *" />
    //
    exchange = self->exchange;
</method>

<method name = "get routing_key" return = "routing_key">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "routing_key" type = "char *" />
    //
    routing_key = self->routing_key;
</method>

<method name = "get delivery_tag" return = "delivery_tag">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "delivery_tag" type = "int64_t" />
    //
    delivery_tag = self->delivery_tag;
</method>

<method name = "get redelivered" return = "redelivered">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "redelivered" type = "Bool" />
    //
    redelivered = self->redelivered;
</method>

<method name = "get message_count" return = "message_count">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "message_count" type = "qbyte" />
    //
    message_count = self->message_count;
</method>

<method name = "get sender_id" return = "sender_id">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "sender_id" type = "char *" />
    //
    sender_id = self->sender_id;
</method>

<method name = "get queue" return = "queue">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "queue" type = "char *" />
    //
    queue = self->queue;
</method>

<method name = "get consumer_count" return = "consumer_count">
    <argument name = "self" type = "$(selftype) *">Object reference</argument>
    <declare name = "consumer_count" type = "qbyte" />
    //
    consumer_count = self->consumer_count;
</method>

<method name = "dp new" return = "thread">
    <argument name = "self"  type = "$(selftype) *">Session object</argument>
    <argument name = "name"  type = "char *">Resource name</argument>
    <argument name = "type"  type = "int">Resource type</argument>
    <declare name = "thread" type = "smt_thread_t *" default = "NULL" />
    <local>
    int
        rc = 0;
    ipr_hash_t
        *hash;
    </local>
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
</method>

<method name = "dp lookup" return = "thread">
    <argument name = "self"  type = "$(selftype) *">Session object</argument>
    <argument name = "name"  type = "char *">Resource name</argument>
    <argument name = "type"  type = "int">Resource type</argument>
    <declare name = "thread" type = "smt_thread_t *" default = "NULL" />
    //
    <local>
    ipr_hash_t
        *hash;
    </local>
    assert (type == DP_SINK || type == DP_FEED);
    if (type == DP_SINK)
        hash = ipr_hash_table_search (self->dp_sinks, name);
    else
        hash = ipr_hash_table_search (self->dp_feeds, name);

    if (hash) {
        thread = smt_thread_link ((smt_thread_t *) hash->data);
        ipr_hash_unlink (&hash);
    }
</method>

<method name = "dp destroy" template = "function">
    <argument name = "name"  type = "char *">Resource name</argument>
    <argument name = "type"  type = "int">Resource type</argument>
    <local>
    ipr_hash_t
        *hash;
    </local>
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
</method>

<private name = "header">
static int
    s_wait_for_methods ($(selftype) *self, int timeout, Bool blocking, Bool on_content);
static void
    s_process_chrono ($(selftype) *self, amq_content_basic_t *content);
static void
    s_close_dp_connection (ipr_hash_t *hash, void *argument);
</private>

<private name = "footer">
/*  Waits for methods from the protocol agent.  If the blocking argument
    is true, returns only when receiving a synchronous reply method.  If not,
    returns when any incoming method is received.  Returns 0 if ok, -1 if
    the connection is closed or a blocking wait timed-out.
 */
static int
s_wait_for_methods (
    $(selftype) *self,
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
    $(selftype) *self,
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
    $(selftype)
        *self = argument;
    smt_thread_t
        *thread = (smt_thread_t *) hash->data;

    //  Ensure connection is really closed before returning to caller
    //  This call will also flush any data pending to be written
    amq_client_agent_direct_close (thread);
    s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE);
    smt_thread_unlink (&thread);
}
</private>

<method name = "initialise">
    amq_client_agent_init ();
</method>

<method name = "selftest" />

</class>
