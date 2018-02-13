<?xml?>
<!---------------------------------------------------------------------------
    amq_server_channel_agent.smt - amq_server_channel component

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
 ----------------------------------------------------------------------------->

<agent
    name = "amq_server_channel_agent"
    script = "smt_gen.gsl"
    animate = "1"
    >
<import class = "amq_server_channel" />

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
</method>

<method name = "flow">
    <argument name = "active" type = "Bool" />
</method>

<method name = "consume">
    <argument name = "queue" type = "amq_queue_t *" />
    <argument name = "method" type = "amq_server_method_t *" />
    <possess>

    queue  = amq_queue_link (queue);
    method = amq_server_method_link (method);
    
    </possess>
    <release>

    amq_queue_unlink (&queue);
    amq_server_method_unlink (&method);
    
    </release>
</method>

<method name = "ack">
    <argument name = "delivery_tag" type = "int64_t" />
    <argument name = "multiple" type = "Bool" />
</method>

<method name = "cancel">
    <argument name = "tag" type = "char *" />
    <argument name = "sync" type = "Bool" />
    <argument name = "nowait" type = "Bool" />
    <possess>

    tag = icl_mem_strdup (tag);
    
    </possess>
    <release>

    icl_mem_free (tag);
    
    </release>
</method>

<thread name = "class">
    <context>
        amq_server_channel_t
            *amq_server_channel;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_server_channel_t *">The iCL object</argument>
        tcb->amq_server_channel = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_server_channel
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_server_connection_unlink (&self->connection);

{
amq_consumer_t
    *consumer;                      //  Consumer in index table

//  We destroy consumers by asking the respective queues
while ((consumer = amq_consumer_by_channel_pop (self->consumer_list))) {
    if (amq_queue_cancel (consumer->queue, consumer, FALSE, TRUE))
        //  If the async cancel failed, destroy the consumer ourselves
        amq_consumer_destroy (&consumer);
}
amq_connection_destroy (&self->mgt_connection);
}
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_server_channel
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_server_channel object");
    amq_server_channel_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_server_channel_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "flow"  >
            <action name = "flow">

#define self tcb->amq_server_channel
Bool
    active;

    active = flow_m->active;
        {
amq_consumer_t
    *consumer;                      //  Consumer object reference

self->active = active;
consumer = amq_consumer_by_channel_first (self->consumer_list);
while (consumer) {
    consumer->paused = !active;
    consumer->queue->feed_on = active;
    if (active)
        amq_queue_dispatch (consumer->queue);
    consumer = amq_consumer_by_channel_next (&consumer);
}
amq_server_agent_channel_flow_ok (self->connection->thread, self->number, self->active);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "consume"  >
            <action name = "consume">

#define self tcb->amq_server_channel
amq_queue_t *
    queue;
amq_server_method_t *
    method;

    queue = consume_m->queue;
    method = consume_m->method;
        {
amq_consumer_t
    *consumer = NULL;
Bool
    nowait = method->payload.basic_consume.nowait;

if (strused (method->payload.basic_consume.consumer_tag))
    consumer = amq_consumer_table_search (
        self->connection->consumer_table, method->payload.basic_consume.consumer_tag);

//  If consumer tag specified, ignore re-consume of same tag on same queue
if (consumer) {
    if (consumer->queue == queue) {
        if (!nowait)
            amq_server_agent_basic_consume_ok (
                self->connection->thread, self->number, consumer->tag);
    }
    else
        amq_server_channel_error (self, ASL_NOT_ALLOWED, "Consumer tag used on other queue",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_CONSUME);
}
else {
    consumer = amq_consumer_new (self->connection, self, queue, method);
    if (consumer) {
        amq_consumer_by_channel_queue (self->consumer_list, consumer);
        if (queue->exclusive)
            self->credit = amq_server_config_private_credit (amq_server_config);
        else
            self->credit = amq_server_config_shared_credit (amq_server_config);
        if (self->credit == 0)
            self->credit = 1;
        amq_queue_consume (queue, consumer, self->active, nowait);
    }
    else {
        amq_server_channel_error (self, ASL_RESOURCE_ERROR, "Unable to create consumer",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_CONSUME);
        smt_log_print (amq_broker->alert_log, "W: cannot create consumer - too many consumers?");
    }
}
amq_consumer_unlink (&consumer);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "ack"  >
            <action name = "ack">

#define self tcb->amq_server_channel
int64_t
    delivery_tag;
Bool
    multiple;

    delivery_tag = ack_m->delivery_tag;
    multiple = ack_m->multiple;
        {
amq_consumer_t
    *consumer;                      //  Consumer object reference

consumer = amq_consumer_by_channel_first (self->consumer_list);
while (consumer) {
    //  Get queue to do work on consumer so it's synchronized
    amq_queue_consumer_ack (consumer->queue, consumer);
    consumer = amq_consumer_by_channel_next (&consumer);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "cancel"  >
            <action name = "cancel">

#define self tcb->amq_server_channel
char *
    tag;
Bool
    sync;
Bool
    nowait;

    tag = cancel_m->tag;
    sync = cancel_m->sync;
    nowait = cancel_m->nowait;
        {
amq_consumer_t
    *consumer = NULL;               //  Consumer reference
amq_queue_t
    *queue;

consumer = amq_consumer_table_search (self->connection->consumer_table, tag);
if (consumer) {
    amq_consumer_by_channel_remove (consumer);
    if (sync) {
        //  Pass to queue to do the final honours
        queue = amq_queue_link (consumer->queue);
        if (queue) {
            //  Send request to queue, but if queue is just dying, this
            //  can fail, and leave a dangling consumer.
            if (amq_queue_cancel (queue, consumer, TRUE, nowait))
                amq_consumer_unlink (&consumer);
            amq_queue_unlink (&queue);
        }
        else
            amq_consumer_unlink (&consumer);
    }
    else {
        //  Consumer must have been removed from its per-queue list
        assert (consumer->by_queue_next == consumer);
        amq_consumer_destroy (&consumer);
    }
}
else
if (sync)
    amq_server_agent_basic_cancel_ok (self->connection->thread, self->number, tag);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <event name = "shutdown" nextstate = "shutting down" />
    </state>
    
    <state name = "shutting down">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_server_channel
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_server_connection_unlink (&self->connection);

{
amq_consumer_t
    *consumer;                      //  Consumer in index table

//  We destroy consumers by asking the respective queues
while ((consumer = amq_consumer_by_channel_pop (self->consumer_list))) {
    if (amq_queue_cancel (consumer->queue, consumer, FALSE, TRUE))
        //  If the async cancel failed, destroy the consumer ourselves
        amq_consumer_destroy (&consumer);
}
amq_connection_destroy (&self->mgt_connection);
}
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_server_channel
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_server_channel object");
    amq_server_channel_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_server_channel_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "cancel"  >
            <action name = "cancel">

#define self tcb->amq_server_channel
char *
    tag;
Bool
    sync;
Bool
    nowait;

    tag = cancel_m->tag;
    sync = cancel_m->sync;
    nowait = cancel_m->nowait;
        {
amq_consumer_t
    *consumer = NULL;               //  Consumer reference
amq_queue_t
    *queue;

consumer = amq_consumer_table_search (self->connection->consumer_table, tag);
if (consumer) {
    amq_consumer_by_channel_remove (consumer);
    if (sync) {
        //  Pass to queue to do the final honours
        queue = amq_queue_link (consumer->queue);
        if (queue) {
            //  Send request to queue, but if queue is just dying, this
            //  can fail, and leave a dangling consumer.
            if (amq_queue_cancel (queue, consumer, TRUE, nowait))
                amq_consumer_unlink (&consumer);
            amq_queue_unlink (&queue);
        }
        else
            amq_consumer_unlink (&consumer);
    }
    else {
        //  Consumer must have been removed from its per-queue list
        assert (consumer->by_queue_next == consumer);
        amq_consumer_destroy (&consumer);
    }
}
else
if (sync)
    amq_server_agent_basic_cancel_ok (self->connection->thread, self->number, tag);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "flow" />
        <method name = "consume" />
        <method name = "ack" />
    </state>
</thread>

</agent>
