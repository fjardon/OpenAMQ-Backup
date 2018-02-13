<?xml?>
<!---------------------------------------------------------------------------
    amq_connection_agent.smt - amq_connection component

This class acts as a management layer for the amq_server_connection
class.  Ideally, that would be an async class but for now, it implies
too large changes to the architecture.  At some future stage we will
merge these two classes into one.
    Generated from amq_connection.icl by smt_object_gen using GSL/4.

    
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
    name = "amq_connection_agent"
    script = "smt_gen.gsl"
    animate = "1"
    >
<import class = "amq_connection" />

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
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
        amq_connection_t
            *amq_connection;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_connection_t *">The iCL object</argument>
        tcb->amq_connection = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_connection
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

icl_atomic_dec32 ((volatile qbyte *) &gbl_amq_connection_count);

amq_server_channel_unlink (&self->channel);
amq_server_connection_unlink (&self->connection);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_connection
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_connection object");
    amq_connection_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_connection_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "inspect"  >
            <action name = "inspect">

#define self tcb->amq_connection
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
            size_t
            pending = 0;
        amq_consumer_t
            *consumer;              //  Consumer object reference
        amq_server_channel_t
            *channel;
        amq_queue_t
            *queue;

fields = asl_field_list_new (NULL);
            connection = amq_server_connection_link (self->connection);
        if (connection) {
icl_shortstr_cpy (field_value, connection->id);
asl_field_new_string (fields, "name", field_value);
            //  Count total pending messages in all private (exclusive) queues
        channel = amq_server_channel_link (self->channel);
        if (channel) {
            consumer = amq_consumer_by_channel_first (channel->consumer_list);
            while (consumer) {
                queue = amq_queue_link (consumer->queue);
                if (queue) {
                    if (queue->exclusive)
                        pending += amq_queue_message_count (queue);
                    amq_queue_unlink (&queue);
                }
                consumer = amq_consumer_by_channel_next (&consumer);
            }
            amq_server_channel_unlink (&channel);
        }
        icl_shortstr_fmt (field_value, "%d", pending);
asl_field_new_string (fields, "pending", field_value);
icl_shortstr_cpy (field_value, connection->client_address);
asl_field_new_string (fields, "address", field_value);
icl_shortstr_cpy (field_value, connection->user_name);
asl_field_new_string (fields, "user_name", field_value);
icl_shortstr_cpy (field_value, connection->client_instance);
asl_field_new_string (fields, "instance", field_value);
ipr_time_iso8601 (connection->started,
        ipr_date_format_minute, 0, FALSE, field_value);
asl_field_new_string (fields, "started", field_value);
icl_shortstr_fmt (field_value, "%d", connection->contents_in);
asl_field_new_string (fields, "messages_in", field_value);
icl_shortstr_fmt (field_value, "%d", connection->contents_out);
asl_field_new_string (fields, "messages_out", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (connection->traffic_in / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_in", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (connection->traffic_out / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_out", field_value);
icl_shortstr_cpy (field_value, connection->client_product);
asl_field_new_string (fields, "product", field_value);
icl_shortstr_cpy (field_value, connection->client_version);
asl_field_new_string (fields, "version", field_value);
icl_shortstr_cpy (field_value, connection->client_platform);
asl_field_new_string (fields, "platform", field_value);
icl_shortstr_cpy (field_value, connection->client_information);
asl_field_new_string (fields, "information", field_value);
            icl_shortstr_fmt (field_value, "%d", connection->trace);
asl_field_new_string (fields, "trace", field_value);
strclr (field_value);
            channel = amq_server_channel_link (self->channel);
        if (channel) {
            consumer = amq_consumer_by_channel_first (channel->consumer_list);
            if (consumer)
                icl_shortstr_fmt (field_value, "%d", consumer->mgt_connection_queue->object_id);
            amq_server_channel_unlink (&channel);
        }
while (*field_value) {
    asl_field_new_string (fields, "connection_queue", field_value);
    strclr (field_value);
            consumer = amq_consumer_by_channel_next (&consumer);
        if (consumer)
            icl_shortstr_fmt (field_value, "%d", consumer->mgt_connection_queue->object_id);
}
                amq_server_connection_unlink (&connection);
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

#define self tcb->amq_connection
amq_content_basic_t *
    request;
asl_field_list_t *
    fields;

    request = modify_m->request;
    fields = modify_m->fields;
        {
asl_field_t
    *field;
icl_shortstr_t
    field_value;
            amq_server_connection_t
            *connection;
char
    *notice_text = NULL;            //  Notice to UI, if any

            connection = amq_server_connection_link (self->connection);
        if (connection) {
field = asl_field_list_search (fields, "trace");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
                amq_server_connection_set_trace (connection, atoi (field_value));
    asl_field_unlink (&field);
}
                amq_server_connection_unlink (&connection);
        }
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

#define self tcb->amq_connection
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
            amq_server_connection_t
            *connection;
if (streq (method_name, "kill")) {
                connection = amq_server_connection_link (self->connection);
        if (connection) {
            smt_log_print (amq_broker->alert_log,
                "W: operator killed connection to %s", connection->client_address);
            amq_server_connection_kill (connection);
            amq_server_connection_unlink (&connection);
        }
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

        <event name = "shutdown" nextstate = "shutting down" />
    </state>
    
    <state name = "shutting down">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_connection
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

icl_atomic_dec32 ((volatile qbyte *) &gbl_amq_connection_count);

amq_server_channel_unlink (&self->channel);
amq_server_connection_unlink (&self->connection);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_connection
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_connection object");
    amq_connection_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_connection_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "inspect" />
        <method name = "modify" />
        <method name = "method" />
    </state>
</thread>

</agent>
