<?xml?>
<!---------------------------------------------------------------------------
    amq_console_agent.smt - amq_console component

This implements the AMQ Console object, which is a system-wide object
responsible for implementing the AMQ Console service.

The console works as follows:

 - AMQ Console is instantiated as a global object of this class, which
   has its own context.

 - All operable objects register with the console class, using a console
   class object as a holder for the methods the object class implements.

 - The amq.system exchange sends it messages using the publish method.
   For now, it is hard-coded in amq.system that any messages with the
   "amq.console" will get sent to amq_console.

 - The amq_console decodes the messages and routes it to an object (if
   found), via the amq_console_class definition for that object.

 - The operable objects implement a register, cancel, inspect, and modify
   methods, and return their replies to amq_console asynchrously via
   inspect_ok, modify_ok.

 - All interfaces between amq_console and operable classes is done using
   asl_field lists.
    Generated from amq_console.icl by smt_object_gen using GSL/4.

    
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
    name = "amq_console_agent"
    script = "smt_gen.gsl"
    animate = "1"
    >
<import class = "amq_console" />

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
</method>

<method name = "register">
    <argument name = "object_id" type = "qbyte" />
    <argument name = "object_ref" type = "void *" />
    <argument name = "class_ref" type = "amq_console_class_t *" />
    <argument name = "parent_id" type = "qbyte" />
</method>

<method name = "cancel">
    <argument name = "object_id" type = "qbyte" />
</method>

<method name = "accept">
    <argument name = "content" type = "amq_content_basic_t *" />
    <argument name = "group" type = "int" />
    <possess>

    content = amq_content_basic_link (content);
    
    </possess>
    <release>

    amq_content_basic_unlink (&content);
    
    </release>
</method>

<method name = "reply ok">
    <argument name = "name" type = "char *" />
    <argument name = "request" type = "amq_content_basic_t *" />
    <argument name = "object_id" type = "qbyte" />
    <argument name = "fields" type = "asl_field_list_t *" />
    <argument name = "notice" type = "char *" />
    <possess>

    name = icl_mem_strdup (name);
    request = amq_content_basic_link (request);
    fields = asl_field_list_link (fields);
    notice = icl_mem_strdup (notice);
    
    </possess>
    <release>

    icl_mem_free (name);
    amq_content_basic_unlink (&request);
    asl_field_list_unlink (&fields);
    icl_mem_free (notice);
    
    </release>
</method>

<method name = "reply error">
    <argument name = "name" type = "char *" />
    <argument name = "status" type = "char *" />
    <argument name = "request" type = "amq_content_basic_t *" />
    <argument name = "object_id" type = "qbyte" />
    <possess>

    name = icl_mem_strdup (name);
    status = icl_mem_strdup (status);
    request = amq_content_basic_link (request);
    
    </possess>
    <release>

    icl_mem_free (name);
    icl_mem_free (status);
    amq_content_basic_unlink (&request);
    
    </release>
</method>

<thread name = "class">
    <context>
        amq_console_t
            *amq_console;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_console_t *">The iCL object</argument>
        tcb->amq_console = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_console
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
ipr_hash_table_apply (self->object_store, s_destroy_item, NULL);
ipr_hash_table_destroy (&self->object_store);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_console
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_console object");
    amq_console_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_console_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "register"  >
            <action name = "register">

#define self tcb->amq_console
qbyte
    object_id;
void *
    object_ref;
amq_console_class_t *
    class_ref;
qbyte
    parent_id;

    object_id = register_m->object_id;
    object_ref = register_m->object_ref;
    class_ref = register_m->class_ref;
    parent_id = register_m->parent_id;
        {
ipr_hash_t
    *hash;                          //  Entry into hash table
icl_shortstr_t
    object_key;                     //  Stringified object id
amq_console_entry_t
    *entry;

sprintf (object_key, "%X", object_id);
hash = ipr_hash_new (self->object_store, object_key, NULL);
assert (hash);

entry = icl_mem_alloc (sizeof (amq_console_entry_t));
entry->object_ref = object_ref;
entry->class_ref  = class_ref;
entry->hash       = hash;           //  Holds link to hash
hash->data        = entry;
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "cancel"  >
            <action name = "cancel">

#define self tcb->amq_console
qbyte
    object_id;

    object_id = cancel_m->object_id;
        {
amq_console_entry_t
    *entry;

entry = s_lookup_object (self, object_id);
if (entry) {
    entry->class_ref->unlink (&entry->object_ref);
    ipr_hash_destroy (&entry->hash);
    icl_mem_free (entry);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "accept"  >
            <action name = "accept">

#define self tcb->amq_console
amq_content_basic_t *
    content;
int
    group;

    content = accept_m->content;
    group = accept_m->group;
        {
//
ipr_bucket_t
    *bucket = NULL;                 //  Message comes here
ipr_xml_t
    *xml_root,
    *xml_cml,
    *xml_item;

//  Get content body into a bucket
bucket = ipr_bucket_new (IPR_BUCKET_MAX_SIZE);
bucket->cur_size = amq_content_basic_get_body (content, bucket->data, bucket->max_size);
assert (bucket->cur_size < IPR_BUCKET_MAX_SIZE);
bucket->data [bucket->cur_size] = 0;

if (amq_server_config_debug_console (amq_server_config))
    smt_log_print (amq_broker->debug_log, "C: console xml=%s", bucket->data);

//  Parse as XML message
xml_root = ipr_xml_parse_string ((char *) bucket->data);
xml_cml = ipr_xml_first_child (xml_root);
if (xml_cml && streq (ipr_xml_name (xml_cml), "cml")) {
    xml_item = ipr_xml_first_child (xml_cml);
    if (streq (ipr_xml_name (xml_item), "schema-request"))
        s_execute_schema (content);
    else
    if (streq (ipr_xml_name (xml_item), "inspect-request"))
        s_execute_inspect (self, content, xml_item, group);
    else
    if (streq (ipr_xml_name (xml_item), "modify-request"))
        s_execute_modify (self, content, xml_item, group);
    else
    if (streq (ipr_xml_name (xml_item), "monitor-request"))
        s_execute_monitor (self, content, xml_item, group);
    else
    if (streq (ipr_xml_name (xml_item), "method-request"))
        s_execute_method (self, content, xml_item, group);
    else
        s_invalid_cml (content, bucket, "unknown CML command");

    ipr_xml_unlink (&xml_item);
}
else
    s_invalid_cml (content, bucket, "Not a valid CML document");

ipr_bucket_unlink (&bucket);
ipr_xml_destroy (&xml_cml);
ipr_xml_destroy (&xml_root);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "reply ok"  >
            <action name = "reply ok">

#define self tcb->amq_console
char *
    name;
amq_content_basic_t *
    request;
qbyte
    object_id;
asl_field_list_t *
    fields;
char *
    notice;

    name = reply_ok_m->name;
    request = reply_ok_m->request;
    object_id = reply_ok_m->object_id;
    fields = reply_ok_m->fields;
    notice = reply_ok_m->notice;
        {
asl_field_t
    *field;
ipr_xml_t
    *cml_item,                      //  CML item
    *cur_item,                      //  Top level object
    *sub_item,                      //  Field or class within object
    *val_item;                      //  Value of field
icl_shortstr_t
    strvalue;                       //  Stringified numeric value
amq_console_entry_t
    *entry;                         //  Object store entry

entry = s_lookup_object (self, object_id);

cml_item = ipr_xml_new (NULL, "cml", NULL);
ipr_xml_attr_set (cml_item, "version", "1.0");
ipr_xml_attr_set (cml_item, "xmlns", "http://www.openamq.org/schema/cml");

cur_item = ipr_xml_new (cml_item, name, NULL);
ipr_xml_attr_set (cur_item, "class",  entry->class_ref->name);
ipr_xml_attr_set (cur_item, "object", icl_shortstr_fmt (strvalue, "%d", object_id));
ipr_xml_attr_set (cur_item, "status", "ok");
if (notice)
    ipr_xml_attr_set (cur_item, "notice", notice);

if (fields) {
    field = asl_field_list_first (fields);
    while (field) {
        sub_item = ipr_xml_new (cur_item, "field", NULL);
        ipr_xml_attr_set (sub_item, "name", field->name);
        val_item = ipr_xml_new (sub_item, NULL, asl_field_string (field));
        ipr_xml_unlink (&val_item);
        ipr_xml_unlink (&sub_item);
        field = asl_field_list_next (&field);
    }
}
s_reply_xml (request, cml_item);
ipr_xml_unlink  (&cur_item);
ipr_xml_destroy (&cml_item);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "reply error"  >
            <action name = "reply error">

#define self tcb->amq_console
char *
    name;
char *
    status;
amq_content_basic_t *
    request;
qbyte
    object_id;

    name = reply_error_m->name;
    status = reply_error_m->status;
    request = reply_error_m->request;
    object_id = reply_error_m->object_id;
        {
ipr_xml_t
    *cml_item,                      //  CML item
    *cur_item;                      //  Top level object
icl_shortstr_t
    strvalue;                       //  Stringified numeric value
amq_console_entry_t
    *entry;                         //  Object store entry

entry = s_lookup_object (self, object_id);
cml_item = ipr_xml_new (NULL, "cml", NULL);
ipr_xml_attr_set (cml_item, "version", "1.0");
ipr_xml_attr_set (cml_item, "xmlns", "http://www.openamq.org/schema/cml");

cur_item = ipr_xml_new (cml_item, name, NULL);
ipr_xml_attr_set (cur_item, "class",  entry->class_ref->name);
ipr_xml_attr_set (cur_item, "object", icl_shortstr_fmt (strvalue, "%d", object_id));
ipr_xml_attr_set (cur_item, "status", status);

s_reply_xml (request, cml_item);
ipr_xml_unlink  (&cur_item);
ipr_xml_destroy (&cml_item);
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

#define self tcb->amq_console
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
ipr_hash_table_apply (self->object_store, s_destroy_item, NULL);
ipr_hash_table_destroy (&self->object_store);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_console
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_console object");
    amq_console_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_console_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "register" />
        <method name = "cancel" />
        <method name = "accept" />
        <method name = "reply ok" />
        <method name = "reply error" />
    </state>
</thread>

<private name = "types">
//  This file is generated when we build the project
#define AMQ_CONSOLE_SCHEMA      "amq_console_schema.cml"

static amq_console_entry_t *
    s_lookup_object   (amq_console_t *self, qbyte object_id);
static void
    s_execute_schema  (amq_content_basic_t *request);
static void
    s_execute_inspect (amq_console_t *self, amq_content_basic_t *request, ipr_xml_t *xml_item, int group);
static void
    s_execute_modify  (amq_console_t *self, amq_content_basic_t *request, ipr_xml_t *xml_item, int group);
static void
    s_execute_monitor (amq_console_t *self, amq_content_basic_t *request, ipr_xml_t *xml_item, int group);
static void
    s_execute_method  (amq_console_t *self, amq_content_basic_t *request, ipr_xml_t *xml_item, int group);
static asl_field_list_t *
    s_get_field_list  (ipr_xml_t *xml_item);
static void
    s_invalid_cml     (amq_content_basic_t *request, ipr_bucket_t *bucket, char *error);
static void
    s_reply_error     (amq_content_basic_t *request, char *top, char *status);
static void
    s_reply_xml       (amq_content_basic_t *request, ipr_xml_t *xml_item);
static void
    s_reply_bucket    (amq_content_basic_t *request, ipr_bucket_t *bucket);
static void
    s_destroy_item    (ipr_hash_t *item, void *argument);
</private>

<private name = "functions">
static amq_console_entry_t *
s_lookup_object (amq_console_t *self, qbyte object_id)
{
    icl_shortstr_t
        object_key;                     //  Stringified object id
    amq_console_entry_t
        *entry = NULL;
    ipr_hash_t
        *hash;                          //  Entry into hash table

    sprintf (object_key, "%X", object_id);
    hash = ipr_hash_table_search (self->object_store, object_key);
    if (hash) {
        entry = hash->data;
        ipr_hash_unlink (&hash);
    }
    return (entry);
}

static void
s_execute_schema (amq_content_basic_t *request)
{
    ipr_bucket_t
        *bucket;                        //  Schema loaded from disk

    //  The console schema is packaged with the binary using the
    //  iPR Resource Compiler; we can load it into a bucket without
    //  doing any file system access.

    bucket = amq_server_resource_get (AMQ_CONSOLE_SCHEMA);
    assert (bucket);
    s_reply_bucket (request, bucket);
    ipr_bucket_unlink (&bucket);
}

static void
s_execute_inspect (
    amq_console_t *self,
    amq_content_basic_t *request,
    ipr_xml_t *xml_item,
    int group)
{
    char
        *object_str;
    amq_console_entry_t
        *entry;                         //  Object store entry

    object_str = ipr_xml_attr_get (xml_item, "object", NULL);
    if (object_str) {
        entry = s_lookup_object (self, atol (object_str));
        if (entry)
            entry->class_ref->inspect (entry->object_ref, request);
        else
            s_reply_error (request, "inspect-reply", "notfound");
    }
    else {
        smt_log_print (amq_broker->alert_log, "W: console - badly-formatted CML method, no object ID");
        s_reply_error (request, "inspect-reply", "invalid");
    }
}

static void
s_execute_modify (
    amq_console_t *self,
    amq_content_basic_t *request,
    ipr_xml_t *xml_item,
    int group)
{
    char
        *object_str;
    asl_field_list_t
        *fields;                        //  Properties to set
    amq_console_entry_t
        *entry;                         //  Object store entry

    object_str = ipr_xml_attr_get (xml_item, "object", NULL);
    if (object_str) {
        entry = s_lookup_object (self, atol (object_str));
        if (entry) {
            if (group == AMQ_CONNECTION_GROUP_NORMAL) {
                smt_log_print (amq_broker->alert_log,
                    "W: console - normal user attempted super-user function");
                s_reply_error (request, "modify-reply", "noaccess");
            }
            else {
                fields = s_get_field_list (xml_item);
                entry->class_ref->modify (entry->object_ref, request, fields);
                asl_field_list_unlink (&fields);
            }
        }
        else
            s_reply_error (request, "modify-reply", "notfound");
    }
    else {
        smt_log_print (amq_broker->alert_log, "W: console - badly-formatted CML method, no object ID");
        s_reply_error (request, "modify-reply", "invalid");
    }
}


static void
s_execute_monitor (
    amq_console_t *self,
    amq_content_basic_t *request,
    ipr_xml_t *xml_item,
    int group)
{
    smt_log_print (amq_broker->debug_log, "amq_console: monitor");
}


static void
s_execute_method (
    amq_console_t *self,
    amq_content_basic_t *request,
    ipr_xml_t *xml_item,
    int group)
{
    char
        *object_str,
        *method_name;                   //  Method to invoke
    asl_field_list_t
        *fields;                        //  Properties to pass
    amq_console_entry_t
        *entry;                         //  Object store entry

    object_str  = ipr_xml_attr_get (xml_item, "object", NULL);
    method_name = ipr_xml_attr_get (xml_item, "name", NULL);
    if (object_str && method_name) {
        entry = s_lookup_object (self, atol (object_str));
        if (entry) {
            if (group == AMQ_CONNECTION_GROUP_NORMAL) {
                smt_log_print (amq_broker->alert_log,
                    "W: console - normal user attempted super-user function");
                s_reply_error (request, "method-reply", "noaccess");
            }
            else {
                fields = s_get_field_list (xml_item);
                entry->class_ref->method (
                    entry->object_ref, method_name, request, fields);
                asl_field_list_unlink (&fields);
            }
        }
        else
            s_reply_error (request, "method-reply", "notfound");
    }
    else {
        smt_log_print (amq_broker->alert_log, "W: console - badly-formatted CML method, no object ID");
        s_reply_error (request, "method-reply", "invalid");
    }
}

//  Builds field list from body of XML command
//  Caller must destroy field list when finished

static asl_field_list_t *
s_get_field_list (ipr_xml_t *xml_item)
{
    asl_field_list_t
        *fields;
    char
        *field_name,
        *field_value;
    ipr_xml_t
        *xml_field;

    fields = asl_field_list_new (NULL);
    xml_field = ipr_xml_first_child (xml_item);
    while (xml_field) {
        field_name  = ipr_xml_attr_get (xml_field, "name", NULL);
        field_value = ipr_xml_text (xml_field);
        if (field_name)
            asl_field_new_string (fields, field_name, field_value);
        icl_mem_free (field_value);
        xml_field = ipr_xml_next_sibling (&xml_field);
    }
    return (fields);
}

static void
s_invalid_cml (amq_content_basic_t *request, ipr_bucket_t *bucket, char *error)
{
    smt_log_print (amq_broker->alert_log,
        "W: console - content body is not valid CML: %s", error);
    ipr_bucket_dump (bucket, "I: ");
    s_reply_error (request, "invalid", NULL);
}

static void
s_reply_error (amq_content_basic_t *request, char *top, char *status)
{
    ipr_xml_t
        *cml_item,
        *cur_item;

    cml_item = ipr_xml_new (NULL, "cml", NULL);
    ipr_xml_attr_set (cml_item, "version", "1.0");
    ipr_xml_attr_set (cml_item, "xmlns", "http://www.openamq.org/schema/cml");

    cur_item = ipr_xml_new (cml_item, top, NULL);
    if (status)
        ipr_xml_attr_set (cur_item, "status", status);

    s_reply_xml (request, cml_item);
    ipr_xml_unlink  (&cur_item);
    ipr_xml_destroy (&cml_item);
}


//  Send XML tree as reply back to original requestor, using same
//  message id and using original reply-to as routing key.
//
static void
s_reply_xml (amq_content_basic_t *request, ipr_xml_t *xml_item)
{
    char
        *xml_text;                      //  Serialised XML text
    ipr_bucket_t
        *bucket;

    xml_text = ipr_xml_save_string (xml_item);
    bucket = ipr_bucket_new (strlen (xml_text) + 1);
    ipr_bucket_fill (bucket, xml_text, strlen (xml_text) + 1);
    icl_mem_free (xml_text);
    s_reply_bucket (request, bucket);
    ipr_bucket_unlink (&bucket);
}


//  Send ipr bucket reply back to original requestor, using same
//  message id and using original reply-to as routing key.
//
static void
s_reply_bucket (amq_content_basic_t *request, ipr_bucket_t *bucket)
{
    amq_exchange_t
        *exchange;                      //  We send the reply to amq.direct
    amq_vhost_t
        *vhost;
    amq_content_basic_t
        *content;

    if (amq_server_config_debug_console (amq_server_config))
        smt_log_print (amq_broker->debug_log, "C: response xml=%s", bucket->data);

    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {
        if (*request->reply_to) {
            exchange = amq_exchange_table_search (vhost->exchange_table, "amq.direct");
            if (exchange) {
                //  Create a content with our desired reply data
                content = amq_content_basic_new ();
                amq_content_basic_set_message_id   (content, request->message_id);
                amq_content_basic_set_content_type (content, "text/xml");
                amq_content_basic_record_body      (content, bucket);
                amq_content_basic_set_routing_key  (content, "amq.direct", request->reply_to, 0);

                //  Publish the message
                amq_exchange_publish (exchange, NULL, content, FALSE, FALSE, 0);
                amq_content_basic_unlink (&content);

                amq_exchange_unlink (&exchange);
            }
        }
        else
            smt_log_print (amq_broker->alert_log,
                "W: console - client did not specify Reply-To queue");
    }
    amq_vhost_unlink (&vhost);
}

//  Callback for object store destruction

static void
s_destroy_item (ipr_hash_t *item, void *argument)
{
    amq_console_entry_t
        *entry;

    entry = item->data;
    entry->class_ref->unlink (&entry->object_ref);
    ipr_hash_destroy (&item);
    icl_mem_free (entry);
}
</private>

</agent>
