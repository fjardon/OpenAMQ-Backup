<?xml?>
<!---------------------------------------------------------------------------
    amq_queue_agent.smt - amq_queue component

This class implements the server queue class, an asynchronous object
that acts as a envelope for the separate queue managers for each
class.  This is a lock-free asynchronous class.
    Generated from amq_queue.icl by smt_object_gen using GSL/4.

    
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
    name = "amq_queue_agent"
    script = "smt_gen.gsl"
    animate = "0"
    >
<import class = "amq_queue" />

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
</method>

<method name = "unbind connection">
</method>

<method name = "publish">
    <argument name = "channel" type = "amq_server_channel_t *" />
    <argument name = "content" type = "amq_content_basic_t *" />
    <argument name = "immediate" type = "Bool" />
    <possess>

    channel = amq_server_channel_link (channel);
    content = amq_content_basic_link (content);
    
    </possess>
    <release>

    amq_server_channel_unlink (&channel);
    amq_content_basic_unlink (&content);
    
    </release>
</method>

<method name = "get">
    <argument name = "channel" type = "amq_server_channel_t *" />
    <argument name = "class_id" type = "int" />
    <possess>

    channel = amq_server_channel_link (channel);
    
    </possess>
    <release>

    amq_server_channel_unlink (&channel);
    
    </release>
</method>

<method name = "consume">
    <argument name = "consumer" type = "amq_consumer_t *" />
    <argument name = "active" type = "Bool" />
    <argument name = "nowait" type = "Bool" />
    <possess>

    consumer = amq_consumer_link (consumer);
    
    </possess>
    <release>

    amq_consumer_unlink (&consumer);
    
    </release>
</method>

<method name = "cancel">
    <argument name = "consumer" type = "amq_consumer_t *" />
    <argument name = "notify" type = "Bool" />
    <argument name = "nowait" type = "Bool" />
    <possess>

    consumer = amq_consumer_link (consumer);
    
    </possess>
    <release>

    amq_consumer_unlink (&consumer);
    
    </release>
</method>

<method name = "self destruct">
</method>

<method name = "consumer ack">
    <argument name = "consumer" type = "amq_consumer_t *" />
</method>

<method name = "purge">
    <argument name = "channel" type = "amq_server_channel_t *" />
    <argument name = "nowait" type = "Bool" />
    <possess>

    channel = amq_server_channel_link (channel);
    
    </possess>
    <release>

    amq_server_channel_unlink (&channel);
    
    </release>
</method>

<method name = "dispatch">
</method>

<method name = "binding register">
    <argument name = "exchange" type = "amq_exchange_t *" />
    <argument name = "binding" type = "amq_binding_t *" />
    <possess>

    exchange = amq_exchange_link (exchange);
    binding = amq_binding_link (binding);
    
    </possess>
    <release>

    amq_exchange_unlink (&exchange);
    amq_binding_unlink (&binding);
    
    </release>
</method>

<method name = "binding cancel">
    <argument name = "exchange" type = "amq_exchange_t *" />
    <argument name = "binding" type = "amq_binding_t *" />
    <possess>

    exchange = amq_exchange_link (exchange);
    binding = amq_binding_link (binding);
    
    </possess>
    <release>

    amq_exchange_unlink (&exchange);
    amq_binding_unlink (&binding);
    
    </release>
</method>

<method name = "inspect">
    <argument name = "request" type = "amq_content_basic_t *" />
    <possess>

    request = amq_content_basic_link (request);
    
    </possess>
    <release>

    amq_content_basic_unlink (&request);
    
    </release>
</method>

<method name = "modify">
    <argument name = "request" type = "amq_content_basic_t *" />
    <argument name = "fields" type = "asl_field_list_t *" />
    <possess>

    request = amq_content_basic_link (request);
    asl_field_list_link (fields);
    
    </possess>
    <release>

    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    
    </release>
</method>

<method name = "method">
    <argument name = "method_name" type = "char *" />
    <argument name = "request" type = "amq_content_basic_t *" />
    <argument name = "fields" type = "asl_field_list_t *" />
    <possess>

    method_name = icl_mem_strdup (method_name);
    request = amq_content_basic_link (request);
    fields  = asl_field_list_link (fields);
    
    </possess>
    <release>

    icl_mem_free (method_name);
    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    
    </release>
</method>

<thread name = "class">
    <context>
        amq_queue_t
            *amq_queue;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_queue_t *">The iCL object</argument>
        tcb->amq_queue = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_queue
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

icl_atomic_dec32 ((volatile qbyte *) &gbl_amq_queue_count);

    {
ipr_looseref_t
    *looseref;
amq_queue_binding_t
    *queue_binding;

amq_server_connection_unlink (&self->connection);
if (amq_server_config_debug_queue (amq_server_config))
    smt_log_print (amq_broker->debug_log, "Q: destroy  queue=%s", self->name);

amq_queue_basic_destroy (&self->queue_basic);

//  Destroy management list of bindings for queue
looseref = ipr_looseref_list_first (self->bindings);
while (looseref) {
    queue_binding = (amq_queue_binding_t *) (looseref->object);
    amq_queue_binding_destroy (&queue_binding);
    looseref = ipr_looseref_list_next (&looseref);
}
ipr_looseref_list_destroy (&self->bindings);
    }
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_queue
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_queue object");
    amq_queue_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_queue_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "unbind connection"  >
            <action name = "unbind connection">

#define self tcb->amq_queue

        {
amq_queue_t
    *queue_ref;                     //  Need a reference to call destroy

assert (self->connection);
assert (self->auto_delete);
if (amq_queue_basic_consumer_count (self->queue_basic) == 0) {
    if (amq_server_config_debug_queue (amq_server_config))
        smt_log_print (amq_broker->debug_log, "Q: auto-del queue=%s", self->name);

    queue_ref = amq_queue_link (self);
    amq_broker_delete_queue (amq_broker, queue_ref);
    //  Ask broker to ask connections to drop link to queue
    if (self->exclusive)
        amq_broker_unbind_queue (amq_broker, queue_ref);

    //  Tell console to drop link back to queue
    amq_console_cancel (self->console, self->object_id);
    amq_queue_unlink (&queue_ref);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "publish"  >
            <action name = "publish">

#define self tcb->amq_queue
amq_server_channel_t *
    channel;
amq_content_basic_t *
    content;
Bool
    immediate;

    channel = publish_m->channel;
    content = publish_m->content;
    immediate = publish_m->immediate;
        {
if (self->enabled)
    amq_queue_basic_publish (self->queue_basic, channel, content, immediate);
else
    amq_server_channel_error (channel, ASL_ACCESS_REFUSED, "Queue is disabled",
        AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_PUBLISH);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "get"  >
            <action name = "get">

#define self tcb->amq_queue
amq_server_channel_t *
    channel;
int
    class_id;

    channel = get_m->channel;
    class_id = get_m->class_id;
        {
amq_queue_basic_get (self->queue_basic, channel);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "consume"  >
            <action name = "consume">

#define self tcb->amq_queue
amq_consumer_t *
    consumer;
Bool
    active;
Bool
    nowait;

    consumer = consume_m->consumer;
    active = consume_m->active;
    nowait = consume_m->nowait;
        {
//
char
    *error = NULL;                  //  If not null, consumer is invalid
amq_server_connection_t
    *connection;
amq_server_channel_t
    *channel;

//  Validate consumer
channel = amq_server_channel_link (consumer->channel);
if (channel)
    connection = amq_server_connection_link (channel->connection);
else
    connection = NULL;

if (self->exclusive && self->connection != connection)
    error = "Queue is exclusive to another connection";
else
if (consumer->exclusive) {
    if (amq_queue_basic_consumer_count (self->queue_basic) == 0)
        self->locked = TRUE;        //  Grant exclusive access
    else
        error = "Exclusive access to queue not possible";
}
else
if (self->locked)
    error = "Queue is being used exclusively by another consumer";

if (error) {
    if (channel) {
        amq_server_channel_error (channel, ASL_ACCESS_REFUSED,
            error, AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_CONSUME);
        amq_server_channel_cancel (channel, consumer->tag, FALSE, TRUE);
    }
}
else {
    consumer->paused = !active;
    self->feed_on = active;
    self->feed_no_local = consumer->no_local;
    amq_queue_basic_consume (self->queue_basic, consumer);
    if (connection && !nowait)
        amq_server_agent_basic_consume_ok (
            connection->thread, channel->number, consumer->tag);
    amq_queue_dispatch (self);
}
amq_server_connection_unlink (&connection);
amq_server_channel_unlink (&channel);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "cancel"  >
            <action name = "cancel">

#define self tcb->amq_queue
amq_consumer_t *
    consumer;
Bool
    notify;
Bool
    nowait;

    consumer = cancel_m->consumer;
    notify = cancel_m->notify;
    nowait = cancel_m->nowait;
        {
amq_server_connection_t
    *connection;
amq_server_channel_t
    *channel;

if (notify && !nowait) {
    channel = amq_server_channel_link (consumer->channel);
    if (channel) {
        connection = amq_server_connection_link (channel->connection);
        if (connection) {
            amq_server_agent_basic_cancel_ok (
                connection->thread, channel->number, consumer->tag);
            amq_server_connection_unlink (&connection);
        }
        amq_server_channel_unlink (&channel);
    }
}
amq_queue_basic_cancel (self->queue_basic, consumer);

self->feed_on = FALSE;              //  Stop direct feed from queue, if any
self->locked = FALSE;
if (self->auto_delete && amq_queue_basic_consumer_count (self->queue_basic) == 0) {
    int
        timeout = amq_server_config_queue_timeout (amq_server_config);
    if (timeout)
        smt_timer_request_delay (self->thread, timeout * 1000 * 1000, auto_delete_event);
    else {
        if (amq_server_config_debug_queue (amq_server_config))
            smt_log_print (amq_broker->debug_log, "Q: auto-del queue=%s", self->name);
        amq_queue_self_destruct (self);
    }
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "self destruct"  >
            <action name = "self destruct">

#define self tcb->amq_queue

        {
amq_queue_t
    *queue_ref;                     //  Need a reference to call destroy

queue_ref = amq_queue_link (self);
amq_broker_delete_queue (amq_broker, queue_ref);
//  Ask broker to ask connections to drop link to queue
if (self->exclusive)
    amq_broker_unbind_queue (amq_broker, queue_ref);

//  Stop consumers because they link back to queue
amq_queue_basic_stop (self->queue_basic);
//  Tell console to drop link back to queue
amq_console_cancel (self->console, self->object_id);
amq_queue_unlink (&queue_ref);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "consumer ack"  >
            <action name = "consumer ack">

#define self tcb->amq_queue
amq_consumer_t *
    consumer;

    consumer = consumer_ack_m->consumer;
        {
amq_queue_basic_consumer_ack (self->queue_basic, consumer);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "purge"  >
            <action name = "purge">

#define self tcb->amq_queue
amq_server_channel_t *
    channel;
Bool
    nowait;

    channel = purge_m->channel;
    nowait = purge_m->nowait;
        {
long
    messages = 0;
amq_server_connection_t
    *connection;

messages += amq_queue_basic_purge (self->queue_basic);
if (!nowait) {
    connection = channel?
        amq_server_connection_link (channel->connection): NULL;
    if (connection) {
        amq_server_agent_queue_purge_ok (
            connection->thread, channel->number, messages);
        amq_server_connection_unlink (&connection);
    }
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "dispatch"  >
            <action name = "dispatch">

#define self tcb->amq_queue

        {
amq_queue_basic_dispatch (self->queue_basic);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "binding register"  >
            <action name = "binding register">

#define self tcb->amq_queue
amq_exchange_t *
    exchange;
amq_binding_t *
    binding;

    exchange = binding_register_m->exchange;
    binding = binding_register_m->binding;
        {
ipr_looseref_queue (self->bindings, amq_queue_binding_new (self, exchange, binding));
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "binding cancel"  >
            <action name = "binding cancel">

#define self tcb->amq_queue
amq_exchange_t *
    exchange;
amq_binding_t *
    binding;

    exchange = binding_cancel_m->exchange;
    binding = binding_cancel_m->binding;
        {
amq_queue_binding_t
    *queue_binding;
ipr_looseref_t
    *looseref;

looseref = ipr_looseref_list_first (self->bindings);
while (looseref) {
    queue_binding = (amq_queue_binding_t *) (looseref->object);
    if (queue_binding->exchange == exchange
    &&  queue_binding->binding == binding) {
        ipr_looseref_list_remove (looseref);
        amq_queue_binding_destroy (&queue_binding);
        break;
    }
    looseref = ipr_looseref_list_next (&looseref);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "inspect"  >
            <action name = "inspect">

#define self tcb->amq_queue
amq_content_basic_t *
    request;

    request = inspect_m->request;
        {
asl_field_list_t
    *fields;                        //  Properties of object
icl_shortstr_t
    field_value;
            amq_server_connection_t
            *connection;
            amq_consumer_t
            *consumer;              //  Consumer object reference
            amq_queue_binding_t
            *queue_binding;
        ipr_looseref_t
            *looseref;

fields = asl_field_list_new (NULL);
icl_shortstr_cpy (field_value, self->name);
asl_field_new_string (fields, "name", field_value);
icl_shortstr_fmt (field_value, "%d", amq_queue_message_count (self));
asl_field_new_string (fields, "pending", field_value);
icl_shortstr_fmt (field_value, "%d", self->exclusive);
asl_field_new_string (fields, "exclusive", field_value);
            connection = amq_server_connection_link (self->connection);
        if (connection) {
            icl_shortstr_cpy (field_value, connection->client_address);
            amq_server_connection_unlink (&connection);
        }
        else
            icl_shortstr_cpy (field_value, "");
asl_field_new_string (fields, "client", field_value);
icl_shortstr_cpy (field_value, self->last_exchange_name);
asl_field_new_string (fields, "exchange_name", field_value);
icl_shortstr_cpy (field_value, self->last_exchange_type);
asl_field_new_string (fields, "exchange_type", field_value);
icl_shortstr_cpy (field_value, self->last_routing_key);
asl_field_new_string (fields, "routing_key", field_value);
icl_shortstr_cpy (field_value, self->last_binding_args);
asl_field_new_string (fields, "binding_args", field_value);
icl_shortstr_fmt (field_value, "%d", self->auto_delete);
asl_field_new_string (fields, "auto_delete", field_value);
icl_shortstr_fmt (field_value, "%d", amq_queue_basic_consumer_count (self->queue_basic));
asl_field_new_string (fields, "consumers", field_value);
icl_shortstr_fmt (field_value, "%d", self->contents_in);
asl_field_new_string (fields, "messages_in", field_value);
icl_shortstr_fmt (field_value, "%d", self->contents_out);
asl_field_new_string (fields, "messages_out", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (self->traffic_in / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_in", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (self->traffic_out / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_out", field_value);
icl_shortstr_fmt (field_value, "%d", self->drop_count);
asl_field_new_string (fields, "drop_count", field_value);
strclr (field_value);
            consumer = amq_consumer_by_queue_first (self->queue_basic->consumer_list);
        if (consumer)
            icl_shortstr_fmt (field_value, "%d", consumer->mgt_queue_connection->object_id);
while (*field_value) {
    asl_field_new_string (fields, "queue_connection", field_value);
    strclr (field_value);
            consumer = amq_consumer_by_queue_next (&consumer);
        if (consumer)
            icl_shortstr_fmt (field_value, "%d", consumer->mgt_queue_connection->object_id);
}
strclr (field_value);
            looseref = ipr_looseref_list_first (self->bindings);
        if (looseref) {
            queue_binding = (amq_queue_binding_t *) (looseref->object);
            icl_shortstr_fmt (field_value, "%d", queue_binding->object_id);
        }
while (*field_value) {
    asl_field_new_string (fields, "queue_binding", field_value);
    strclr (field_value);
            looseref = ipr_looseref_list_next (&looseref);
        if (looseref) {
            queue_binding = (amq_queue_binding_t *) (looseref->object);
            icl_shortstr_fmt (field_value, "%d", queue_binding->object_id);
        }
}
amq_console_reply_ok (amq_console, "inspect-reply", request, self->object_id, fields, NULL);
asl_field_list_unlink (&fields);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "modify"  >
            <action name = "modify">

#define self tcb->amq_queue
amq_content_basic_t *
    request;
asl_field_list_t *
    fields;

    request = modify_m->request;
    fields = modify_m->fields;
        {
char
    *notice_text = NULL;            //  Notice to UI, if any

amq_console_reply_ok (
    amq_console, "modify-reply", request, self->object_id, NULL, notice_text);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "method"  >
            <action name = "method">

#define self tcb->amq_queue
char *
    method_name;
amq_content_basic_t *
    request;
asl_field_list_t *
    fields;

    method_name = method_m->method_name;
    request = method_m->request;
    fields = method_m->fields;
        {
int
    rc = 0;
char
    *notice_text = NULL;            //  Notice to UI, if any
if (streq (method_name, "purge")) {
    amq_queue_basic_purge (self->queue_basic);
}
if (rc == 0)
    amq_console_reply_ok (
        amq_console, "method-reply", request, self->object_id, NULL, notice_text);
else
    amq_console_reply_error (
        amq_console, "method-reply", "invalid", request, self->object_id);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <event name = "auto delete"  >
            <action name = "auto delete">
            
#define self tcb->amq_queue

        {
//  If we're still at zero consumers, self-destruct
if (amq_queue_basic_consumer_count (self->queue_basic) == 0) {
    if (amq_server_config_debug_queue (amq_server_config))
        smt_log_print (amq_broker->debug_log, "Q: auto-del queue=%s", self->name);

    amq_queue_self_destruct (self);
}
        }
        
#undef self
            </action>
        </event>
        <event name = "shutdown" nextstate = "shutting down" />
    </state>
    
    <state name = "shutting down">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_queue
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

icl_atomic_dec32 ((volatile qbyte *) &gbl_amq_queue_count);

    {
ipr_looseref_t
    *looseref;
amq_queue_binding_t
    *queue_binding;

amq_server_connection_unlink (&self->connection);
if (amq_server_config_debug_queue (amq_server_config))
    smt_log_print (amq_broker->debug_log, "Q: destroy  queue=%s", self->name);

amq_queue_basic_destroy (&self->queue_basic);

//  Destroy management list of bindings for queue
looseref = ipr_looseref_list_first (self->bindings);
while (looseref) {
    queue_binding = (amq_queue_binding_t *) (looseref->object);
    amq_queue_binding_destroy (&queue_binding);
    looseref = ipr_looseref_list_next (&looseref);
}
ipr_looseref_list_destroy (&self->bindings);
    }
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_queue
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_queue object");
    amq_queue_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_queue_free (self);
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

#define self tcb->amq_queue
amq_consumer_t *
    consumer;
Bool
    notify;
Bool
    nowait;

    consumer = cancel_m->consumer;
    notify = cancel_m->notify;
    nowait = cancel_m->nowait;
        {
amq_server_connection_t
    *connection;
amq_server_channel_t
    *channel;

if (notify && !nowait) {
    channel = amq_server_channel_link (consumer->channel);
    if (channel) {
        connection = amq_server_connection_link (channel->connection);
        if (connection) {
            amq_server_agent_basic_cancel_ok (
                connection->thread, channel->number, consumer->tag);
            amq_server_connection_unlink (&connection);
        }
        amq_server_channel_unlink (&channel);
    }
}
amq_queue_basic_cancel (self->queue_basic, consumer);

self->feed_on = FALSE;              //  Stop direct feed from queue, if any
self->locked = FALSE;
if (self->auto_delete && amq_queue_basic_consumer_count (self->queue_basic) == 0) {
    int
        timeout = amq_server_config_queue_timeout (amq_server_config);
    if (timeout)
        smt_timer_request_delay (self->thread, timeout * 1000 * 1000, auto_delete_event);
    else {
        if (amq_server_config_debug_queue (amq_server_config))
            smt_log_print (amq_broker->debug_log, "Q: auto-del queue=%s", self->name);
        amq_queue_self_destruct (self);
    }
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "unbind connection" />
        <method name = "publish" />
        <method name = "get" />
        <method name = "consume" />
        <method name = "self destruct" />
        <method name = "consumer ack" />
        <method name = "purge" />
        <method name = "dispatch" />
        <method name = "binding register" />
        <method name = "binding cancel" />
        <method name = "inspect" />
        <method name = "modify" />
        <method name = "method" />
        <event name = "auto delete" />
    </state>
</thread>

</agent>
