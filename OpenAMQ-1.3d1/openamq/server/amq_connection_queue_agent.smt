<?xml?>
<!---------------------------------------------------------------------------
    amq_connection_queue_agent.smt - amq_connection_queue component

This class shows the relationship from connection to queue, via the
consumer object.
    Generated from amq_connection_queue.icl by smt_object_gen using GSL/4.

    
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
    name = "amq_connection_queue_agent"
    script = "smt_gen.gsl"
    animate = "1"
    >
<import class = "amq_connection_queue" />

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
        amq_connection_queue_t
            *amq_connection_queue;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_connection_queue_t *">The iCL object</argument>
        tcb->amq_connection_queue = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_connection_queue
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

icl_atomic_dec32 ((volatile qbyte *) &gbl_amq_connection_queue_count);

amq_consumer_unlink (&self->consumer);
amq_queue_unlink (&self->queue);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_connection_queue
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_connection_queue object");
    amq_connection_queue_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_connection_queue_free (self);
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

#define self tcb->amq_connection_queue
amq_content_basic_t *
    request;

    request = inspect_m->request;
        {
asl_field_list_t
    *fields;                        //  Properties of object
icl_shortstr_t
    field_value;
            amq_queue_t
            *queue;

fields = asl_field_list_new (NULL);
            queue = amq_queue_link (self->queue);
        if (queue) {
icl_shortstr_cpy (field_value, queue->name);
asl_field_new_string (fields, "name", field_value);
icl_shortstr_fmt (field_value, "%d", queue->enabled);
asl_field_new_string (fields, "enabled", field_value);
icl_shortstr_fmt (field_value, "%d", queue->durable);
asl_field_new_string (fields, "durable", field_value);
icl_shortstr_fmt (field_value, "%d", queue->exclusive);
asl_field_new_string (fields, "exclusive", field_value);
icl_shortstr_cpy (field_value, amq_exchange_type_name (queue->last_exchange_type));
asl_field_new_string (fields, "exchange_type", field_value);
icl_shortstr_cpy (field_value, queue->last_routing_key);
asl_field_new_string (fields, "routing_key", field_value);
icl_shortstr_cpy (field_value, queue->last_binding_args);
asl_field_new_string (fields, "binding_args", field_value);
icl_shortstr_fmt (field_value, "%d", queue->auto_delete);
asl_field_new_string (fields, "auto_delete", field_value);
icl_shortstr_fmt (field_value, "%d", amq_queue_basic_consumer_count (queue->queue_basic));
asl_field_new_string (fields, "consumers", field_value);
icl_shortstr_fmt (field_value, "%d", amq_queue_message_count (queue));
asl_field_new_string (fields, "pending", field_value);
icl_shortstr_fmt (field_value, "%d", queue->contents_in);
asl_field_new_string (fields, "messages_in", field_value);
icl_shortstr_fmt (field_value, "%d", queue->contents_out);
asl_field_new_string (fields, "messages_out", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (queue->traffic_in / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_in", field_value);
icl_shortstr_fmt (field_value, "%d", (int) (queue->traffic_out / (1024 * 1024)));
asl_field_new_string (fields, "megabytes_out", field_value);
icl_shortstr_fmt (field_value, "%d", queue->dropped);
asl_field_new_string (fields, "dropped", field_value);
                amq_queue_unlink (&queue);
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

#define self tcb->amq_connection_queue
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
            amq_queue_t
            *queue;
char
    *notice_text = NULL;            //  Notice to UI, if any

            queue = amq_queue_link (self->queue);
        if (queue) {
field = asl_field_list_search (fields, "enabled");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
    queue->enabled = atoi (field_value);
    asl_field_unlink (&field);
}
                amq_queue_unlink (&queue);
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

#define self tcb->amq_connection_queue
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
            amq_queue_t
            *queue;
if (streq (method_name, "purge")) {
                queue = amq_queue_link (self->queue);
        if (queue) {
            amq_queue_basic_purge (queue->queue_basic);
            amq_queue_unlink (&queue);
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

#define self tcb->amq_connection_queue
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

icl_atomic_dec32 ((volatile qbyte *) &gbl_amq_connection_queue_count);

amq_consumer_unlink (&self->consumer);
amq_queue_unlink (&self->queue);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_connection_queue
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_connection_queue object");
    amq_connection_queue_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_connection_queue_free (self);
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
