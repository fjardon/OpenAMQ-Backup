<?xml?>
<!---------------------------------------------------------------------------
    amq_exchange_agent.smt - amq_exchange component

This class implements the server exchange, an asynchronous
object that acts as a envelope for the separate exchange managers
for each type of exchange. This is a lock-free asynchronous class.
    Generated from amq_exchange.icl by smt_object_gen using GSL/4.

    
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
    name = "amq_exchange_agent"
    script = "smt_gen.gsl"
    animate = "0"
    >
<import class = "amq_exchange" />

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
</method>

<method name = "bind queue">
    <argument name = "channel" type = "amq_server_channel_t *" />
    <argument name = "queue" type = "amq_queue_t *" />
    <argument name = "routing_key" type = "char *" />
    <argument name = "arguments" type = "icl_longstr_t *" />
    <possess>

    channel = amq_server_channel_link (channel);
    queue = amq_queue_link (queue);
    arguments = icl_longstr_dup (arguments);
    routing_key = icl_mem_strdup (routing_key);
    
    </possess>
    <release>

    amq_server_channel_unlink (&channel);
    amq_queue_unlink (&queue);
    icl_longstr_destroy (&arguments);
    icl_mem_free (routing_key);
    
    </release>
</method>

<method name = "unbind queue">
    <argument name = "channel" type = "amq_server_channel_t *" />
    <argument name = "queue" type = "amq_queue_t *" />
    <argument name = "routing_key" type = "char *" />
    <argument name = "arguments" type = "icl_longstr_t *" />
    <possess>

    channel = amq_server_channel_link (channel);
    queue = amq_queue_link (queue);
    arguments = icl_longstr_dup (arguments);
    routing_key = icl_mem_strdup (routing_key);
    
    </possess>
    <release>

    amq_server_channel_unlink (&channel);
    amq_queue_unlink (&queue);
    icl_longstr_destroy (&arguments);
    icl_mem_free (routing_key);
    
    </release>
</method>

<method name = "publish">
    <argument name = "channel" type = "amq_server_channel_t *" />
    <argument name = "content" type = "amq_content_basic_t *" />
    <argument name = "mandatory" type = "Bool" />
    <argument name = "immediate" type = "Bool" />
    <argument name = "group" type = "int" />
    <possess>

    channel = amq_server_channel_link (channel);
    content = amq_content_basic_link (content);
    
    </possess>
    <release>

    amq_server_channel_unlink (&channel);
    amq_content_basic_unlink (&content);
    
    </release>
</method>

<method name = "broker unbind queue">
    <argument name = "queue" type = "amq_queue_t *" />
    <possess>

    queue = amq_queue_link (queue);
    
    </possess>
    <release>

    amq_queue_unlink (&queue);
    
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
        amq_exchange_t
            *amq_exchange;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_exchange_t *">The iCL object</argument>
        tcb->amq_exchange = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_exchange
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

icl_atomic_dec32 ((volatile qbyte *) &gbl_amq_exchange_count);

ipr_hash_table_destroy (&self->binding_hash);
amq_binding_list_destroy (&self->binding_list);
ipr_index_destroy (&self->binding_index);
amq_queue_bindings_list_table_destroy (&self->queue_bindings);
icl_mem_free (self->queue_set);
amq_federation_destroy (&self->federation);

if (!self->internal && amq_server_config_debug_route (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "X: destroy  exchange=%s type=%s", self->name, amq_exchange_type_name (self->type));

if (self->type == AMQ_EXCHANGE_SYSTEM) {
    amq_exchange_system_t
        *exchange = (amq_exchange_system_t *) self->object;
    amq_exchange_system_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_FANOUT) {
    amq_exchange_fanout_t
        *exchange = (amq_exchange_fanout_t *) self->object;
    amq_exchange_fanout_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_DIRECT) {
    amq_exchange_direct_t
        *exchange = (amq_exchange_direct_t *) self->object;
    amq_exchange_direct_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_TOPIC) {
    amq_exchange_topic_t
        *exchange = (amq_exchange_topic_t *) self->object;
    amq_exchange_topic_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_HEADERS) {
    amq_exchange_headers_t
        *exchange = (amq_exchange_headers_t *) self->object;
    amq_exchange_headers_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_REGEXP) {
    amq_exchange_regexp_t
        *exchange = (amq_exchange_regexp_t *) self->object;
    amq_exchange_regexp_destroy (&exchange);
}
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_exchange
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_exchange object");
    amq_exchange_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_exchange_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "bind queue"  >
            <action name = "bind queue">

#define self tcb->amq_exchange
amq_server_channel_t *
    channel;
amq_queue_t *
    queue;
char *
    routing_key;
icl_longstr_t *
    arguments;

    channel = bind_queue_m->channel;
    queue = bind_queue_m->queue;
    routing_key = bind_queue_m->routing_key;
    arguments = bind_queue_m->arguments;
        {
amq_binding_t
    *binding = NULL;                //  New binding created
ipr_hash_t
    *hash;                          //  Entry into hash table
amq_queue_bindings_list_t
    *bindings_list;                 //  List of bindings for the queue
amq_queue_bindings_list_iter_t *
    iterator;

if (amq_server_config_debug_route (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "X: bind     %s: queue=%s", self->name, queue->name);

//  Treat empty arguments as null to simplify comparisons
if (arguments && arguments->cur_size == 0)
    arguments = NULL;

//  Force all fanout bindings to a single instance
if (self->type == AMQ_EXCHANGE_FANOUT)
    routing_key = "";

//  We need to know if this is a new binding or not
//  First, we`ll check on the routing key
hash = ipr_hash_table_search (self->binding_hash, routing_key);
if (hash) {
    //  We found the same routing key, now we need to check
    //  all bindings to check for an exact match
    binding = amq_binding_list_first (self->binding_list);
    while (binding) {
        if (streq (binding->routing_key, routing_key)
        && icl_longstr_eq (binding->arguments, arguments))
            break;
        binding = amq_binding_list_next (&binding);
    }
}
if (!binding) {
    //  If no binding matched, create a new one and compile it
    binding = amq_binding_new (self, routing_key, arguments, queue->exclusive);
    assert (binding);               //  If that failed, don't continue
    if (!hash)                      //  Hash routing key if needed
        hash = ipr_hash_new (self->binding_hash, routing_key, binding);

    //  Compile binding and put all 'wildcard' bindings at the front
    //  of the list. The meaning of this flag depends on the exchange.
    if (self->compile (self->object, binding, channel) == 0) {
        if (binding->is_wildcard)
            amq_binding_list_push (self->binding_list, binding);
        else
            amq_binding_list_queue (self->binding_list, binding);
    }
}
//  In a service federation we forward exclusive bindings only and we
//  prohibit a mix of exclusive/non-exclusive queues on the same binding.
else
if (self->federation_type == AMQ_FEDERATION_SERVICE) {
    if (channel && (binding->exclusive != queue->exclusive))
        amq_server_channel_error (channel, ASL_NOT_ALLOWED,
            "Invalid bind mix for service federation",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_BIND);
}
//  Add queue to binding structures if not already present
if (queue) {
    bindings_list = amq_queue_bindings_list_table_search (
        self->queue_bindings, queue->name);
    if (!bindings_list)
        bindings_list = amq_queue_bindings_list_new (
            self->queue_bindings, queue->name);
    //  Search per-queue bindings_list for a matching binding
    for (iterator = amq_queue_bindings_list_first (bindings_list);
         iterator != NULL;
         iterator = amq_queue_bindings_list_next (&iterator)) {
        if (iterator->item == binding)
            break;
    }
    //  And only add binding to per-queue bindings_list once
    if (!iterator)
        amq_queue_bindings_list_queue (bindings_list, binding);
    amq_queue_bindings_list_unlink (&bindings_list);
}
amq_queue_binding_register (queue, self, binding);
amq_binding_bind_queue (binding, queue);
amq_binding_unlink (&binding);
ipr_hash_unlink (&hash);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "unbind queue"  >
            <action name = "unbind queue">

#define self tcb->amq_exchange
amq_server_channel_t *
    channel;
amq_queue_t *
    queue;
char *
    routing_key;
icl_longstr_t *
    arguments;

    channel = unbind_queue_m->channel;
    queue = unbind_queue_m->queue;
    routing_key = unbind_queue_m->routing_key;
    arguments = unbind_queue_m->arguments;
        {
amq_queue_bindings_list_t
    *queue_bindings;                //  List of bindings for queue
amq_queue_bindings_list_iter_t
    *iterator;

if (amq_server_config_debug_route (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "X: unbind     %s: queue=%s", self->name, queue->name);

//  Treat empty arguments as null, to simplify comparisons
if (arguments && arguments->cur_size == 0)
    arguments = NULL;
queue_bindings =
    amq_queue_bindings_list_table_search (self->queue_bindings, queue->name);
if (queue_bindings) {
    //  Search queue_bindings list for the matching binding
    for (iterator = amq_queue_bindings_list_first (queue_bindings);
          iterator != NULL;
          iterator = amq_queue_bindings_list_next (&iterator)) {
        if (streq (iterator->item->routing_key, routing_key) &&
            icl_longstr_eq (iterator->item->arguments, arguments)) {
            amq_queue_binding_cancel (queue, self, iterator->item);
            if (amq_binding_unbind_queue (iterator->item, queue))
                //  If binding is now empty, destroy it
                self->unbind (self->object, iterator->item);
            amq_queue_bindings_list_iter_destroy (&iterator);
            break;
        }
    }
    //  If per-queue binding list is now empty, destroy it
    if (amq_queue_bindings_list_count (queue_bindings) == 0)
        amq_queue_bindings_list_destroy (&queue_bindings);
    else
        amq_queue_bindings_list_unlink (&queue_bindings);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "publish"  >
            <action name = "publish">

#define self tcb->amq_exchange
amq_server_channel_t *
    channel;
amq_content_basic_t *
    content;
Bool
    mandatory;
Bool
    immediate;
int
    group;

    channel = publish_m->channel;
    content = publish_m->content;
    mandatory = publish_m->mandatory;
    immediate = publish_m->immediate;
    group = publish_m->group;
        {
int
    delivered = 0;                      //  Number of message deliveries
amq_server_connection_t
    *connection;
Bool
    returned = FALSE;

//  If channel is set, we got message from local application; if we have
//  fanout federation, send to parent broker but don't publish locally.
//  This stops message being delivered twice to local apps (once now and
//  once when received back from parent).
//
if (self->federation_type == AMQ_FEDERATION_FANOUT && channel)
    delivered = 1;                  //  Just fake it
else
    //  Publish message locally
    delivered = self->publish (self->object, channel, content, group, immediate);

//  Publish message to federation if necessary. We don't have the problem
//  of message loops with fanout federations because we only push back to
//  the parent messages that came from a client app (channel != 0).
//
if (self->federation_type == AMQ_FEDERATION_PUBLISHER ||
   (self->federation_type == AMQ_FEDERATION_FANOUT && channel) ||
   (self->federation_type == AMQ_FEDERATION_LOCATOR && !delivered) ||
   (self->federation_type == AMQ_FEDERATION_SERVICE && !delivered)) {
    amq_federation_message_published (self->federation, content, mandatory, immediate);
    delivered++;
}
if (!delivered && mandatory) {
    if (!content->returned) {
        connection = channel?
            amq_server_connection_link (channel->connection): NULL;
        if (connection) {
            amq_server_agent_basic_return (
                connection->thread,
                channel->number,
                content,
                ASL_NOT_DELIVERED,
                "Message cannot be processed - no route is defined",
                self->name,
                content->routing_key,
                NULL);
            content->returned = TRUE;
        }
        returned = TRUE;
        amq_server_connection_unlink (&connection);
    }
}
if (amq_server_config_debug_route (amq_server_config)) {
    if (returned)
        smt_log_print (amq_broker->debug_log,
            "X: return   %s: message=%s reason=unroutable_mandatory",
                self->name, content->message_id);
    else
    if (!delivered)
        smt_log_print (amq_broker->debug_log,
            "X: discard  %s: message=%s reason=unroutable_optional",
                self->name, content->message_id);
}
//  Track exchange statistics
self->contents_in  += 1;
self->contents_out += delivered;
self->traffic_in   += content->body_size;
self->traffic_out  += delivered * content->body_size;
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "broker unbind queue"  >
            <action name = "broker unbind queue">

#define self tcb->amq_exchange
amq_queue_t *
    queue;

    queue = broker_unbind_queue_m->queue;
        {
amq_queue_bindings_list_t
    *queue_bindings;                //  List of bindings for queue
amq_binding_t
    *binding;

queue_bindings =
    amq_queue_bindings_list_table_search (self->queue_bindings, queue->name);
if (queue_bindings) {
    //  Iterate over queue_bindings list, removing each binding
    while (1) {
        binding = amq_queue_bindings_list_pop (queue_bindings);
        if (!binding)
            break;
        if (amq_binding_unbind_queue (binding, queue))
            //  If binding is now empty, destroy it
            self->unbind (self->object, binding);
        amq_binding_unlink (&binding);
    }
    //  Per-queue bindings list is now empty, destroy it
    amq_queue_bindings_list_destroy (&queue_bindings);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "inspect"  >
            <action name = "inspect">

#define self tcb->amq_exchange
amq_content_basic_t *
    request;

    request = inspect_m->request;
        {
asl_field_list_t
    *fields;                        //  Properties of object
icl_shortstr_t
    field_value;
            amq_binding_t
            *binding;

fields = asl_field_list_new (NULL);
icl_shortstr_cpy (field_value, self->name);
asl_field_new_string (fields, "name", field_value);
icl_shortstr_cpy (field_value, amq_exchange_type_name (self->type));
asl_field_new_string (fields, "type", field_value);
icl_shortstr_fmt (field_value, "%d", amq_binding_list_count (self->binding_list));
asl_field_new_string (fields, "bindings", field_value);
icl_shortstr_fmt (field_value, "%d", self->contents_in);
asl_field_new_string (fields, "messages_in", field_value);
icl_shortstr_fmt (field_value, "%d", self->contents_out);
asl_field_new_string (fields, "messages_out", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (self->traffic_in / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_in", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (self->traffic_out / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_out", field_value);
strclr (field_value);
            binding = amq_binding_list_first (self->binding_list);
        if (binding)
            icl_shortstr_fmt (field_value, "%d", binding->binding_mgt->object_id);
while (*field_value) {
    asl_field_new_string (fields, "binding", field_value);
    strclr (field_value);
            binding = amq_binding_list_next (&binding);
        if (binding)
            icl_shortstr_fmt (field_value, "%d", binding->binding_mgt->object_id);
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

#define self tcb->amq_exchange
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

#define self tcb->amq_exchange
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

        <event name = "shutdown" nextstate = "shutting down" />
    </state>
    
    <state name = "shutting down">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_exchange
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

icl_atomic_dec32 ((volatile qbyte *) &gbl_amq_exchange_count);

ipr_hash_table_destroy (&self->binding_hash);
amq_binding_list_destroy (&self->binding_list);
ipr_index_destroy (&self->binding_index);
amq_queue_bindings_list_table_destroy (&self->queue_bindings);
icl_mem_free (self->queue_set);
amq_federation_destroy (&self->federation);

if (!self->internal && amq_server_config_debug_route (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "X: destroy  exchange=%s type=%s", self->name, amq_exchange_type_name (self->type));

if (self->type == AMQ_EXCHANGE_SYSTEM) {
    amq_exchange_system_t
        *exchange = (amq_exchange_system_t *) self->object;
    amq_exchange_system_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_FANOUT) {
    amq_exchange_fanout_t
        *exchange = (amq_exchange_fanout_t *) self->object;
    amq_exchange_fanout_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_DIRECT) {
    amq_exchange_direct_t
        *exchange = (amq_exchange_direct_t *) self->object;
    amq_exchange_direct_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_TOPIC) {
    amq_exchange_topic_t
        *exchange = (amq_exchange_topic_t *) self->object;
    amq_exchange_topic_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_HEADERS) {
    amq_exchange_headers_t
        *exchange = (amq_exchange_headers_t *) self->object;
    amq_exchange_headers_destroy (&exchange);
}
else
if (self->type == AMQ_EXCHANGE_REGEXP) {
    amq_exchange_regexp_t
        *exchange = (amq_exchange_regexp_t *) self->object;
    amq_exchange_regexp_destroy (&exchange);
}
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_exchange
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_exchange object");
    amq_exchange_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_exchange_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "bind queue" />
        <method name = "unbind queue" />
        <method name = "publish" />
        <method name = "broker unbind queue" />
        <method name = "inspect" />
        <method name = "modify" />
        <method name = "method" />
    </state>
</thread>

</agent>
