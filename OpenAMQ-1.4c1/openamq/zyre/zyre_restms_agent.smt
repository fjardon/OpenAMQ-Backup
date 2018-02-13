<?xml?>
<!---------------------------------------------------------------------------
    zyre_restms_agent.smt - zyre_restms component

    This class implements a HTTP plugin that maps RestMS requests to AMQP.
    The plugin acts as a portal backend for the Base2/HTTP server.  This
    is an async class that manages a data tree of feeds, pipes, and joins.
    It communicates changes to this tree to the AMQP backend agent, which
    handles all communications with the AMQP server.  Incoming AMQP messages
    arrive via the backend portal.  All RestMS work is done by a single
    object in this class, so a single thread.  This limits the workload to
    around 300,000 transactions per second, which is the speedlimit of one
    threadlet (SMT thread queue limitation).
    Generated from zyre_restms.icl by smt_object_gen using GSL/4.

    
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
    name = "zyre_restms_agent"
    script = "smt_gen.gsl"
    animate = "0"
    >
<import class = "zyre_restms" />

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
</method>

<method name = "announce">
    <argument name = "portal" type = "http_driver_module_t *" />
    <argument name = "log" type = "smt_log_t *" />
</method>

<method name = "get">
    <argument name = "portal" type = "http_driver_module_t *" />
    <argument name = "context" type = "http_driver_context_t *" />
    <possess>

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    </possess>
    <release>

    
        http_driver_context_unlink (&context);
        
    
    </release>
</method>

<method name = "put">
    <argument name = "portal" type = "http_driver_module_t *" />
    <argument name = "context" type = "http_driver_context_t *" />
    <possess>

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    </possess>
    <release>

    
        http_driver_context_unlink (&context);
        
    
    </release>
</method>

<method name = "delete">
    <argument name = "portal" type = "http_driver_module_t *" />
    <argument name = "context" type = "http_driver_context_t *" />
    <possess>

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    </possess>
    <release>

    
        http_driver_context_unlink (&context);
        
    
    </release>
</method>

<method name = "post">
    <argument name = "portal" type = "http_driver_module_t *" />
    <argument name = "context" type = "http_driver_context_t *" />
    <possess>

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    </possess>
    <release>

    
        http_driver_context_unlink (&context);
        
    
    </release>
</method>

<method name = "head">
    <argument name = "portal" type = "http_driver_module_t *" />
    <argument name = "context" type = "http_driver_context_t *" />
    <possess>

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    </possess>
    <release>

    
        http_driver_context_unlink (&context);
        
    
    </release>
</method>

<method name = "move">
    <argument name = "portal" type = "http_driver_module_t *" />
    <argument name = "context" type = "http_driver_context_t *" />
    <possess>

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    </possess>
    <release>

    
        http_driver_context_unlink (&context);
        
    
    </release>
</method>

<method name = "copy">
    <argument name = "portal" type = "http_driver_module_t *" />
    <argument name = "context" type = "http_driver_context_t *" />
    <possess>

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    </possess>
    <release>

    
        http_driver_context_unlink (&context);
        
    
    </release>
</method>

<method name = "online">
    <argument name = "portal" type = "zyre_backend_t *" />
    <argument name = "reply_queue" type = "char *" />
    <possess>

    
        reply_queue = icl_mem_strdup (reply_queue);
      
    
    </possess>
    <release>

    
        icl_mem_strfree (&reply_queue);
      
    
    </release>
</method>

<method name = "offline">
    <argument name = "portal" type = "zyre_backend_t *" />
</method>

<method name = "arrived">
    <argument name = "portal" type = "zyre_backend_t *" />
    <argument name = "method" type = "zyre_peer_method_t *" />
    <possess>

    
        method = zyre_peer_method_link (method);
      
    
    </possess>
    <release>

    
        zyre_peer_method_unlink (&method);
      
    
    </release>
</method>

<method name = "returned">
    <argument name = "portal" type = "zyre_backend_t *" />
    <argument name = "method" type = "zyre_peer_method_t *" />
    <possess>

    
        method = zyre_peer_method_link (method);
      
    
    </possess>
    <release>

    
        zyre_peer_method_unlink (&method);
      
    
    </release>
</method>

<method name = "_zyre_backend unbind">
    <argument name = "portal" type = "zyre_backend_t *" />
</method>

<method name = "_http_driver_module unbind">
    <argument name = "portal" type = "http_driver_module_t *" />
</method>

<thread name = "class">
    <context>
        zyre_restms_t
            *zyre_restms;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "zyre_restms_t *">The iCL object</argument>
        tcb->zyre_restms = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->zyre_restms
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
{
http_driver_module_t
    *http_driver_module;            //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->http_driver_module_stopped, TRUE, FALSE) == FALSE) {
    while ((http_driver_module = (http_driver_module_t *) ipr_looseref_pop (self->http_driver_module_list))) {
        http_driver_module->server_looseref = NULL;
        http_driver_module_destroy (&http_driver_module);
    }
}
ipr_looseref_list_destroy (&self->http_driver_module_list);
}

{
zyre_backend_t
    *zyre_backend;                  //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_backend_stopped, TRUE, FALSE) == FALSE) {
    //  Destroy own portals
    while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_list))) {
        zyre_backend->client_looseref = NULL;
        zyre_backend_destroy (&zyre_backend);
    }
    ipr_looseref_list_destroy (&self->zyre_backend_list);
    //  Destroy own portal factories
    while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_factory_list))) {
        zyre_backend->client_looseref = NULL;
        zyre_backend_destroy (&zyre_backend);
    }
    ipr_looseref_list_destroy (&self->zyre_backend_factory_list);
}
}

ipr_hash_table_destroy (&self->resources);
zyre_backend_unlink (&self->backend);
smt_log_unlink (&self->log);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->zyre_restms
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on zyre_restms object");
    zyre_restms_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    zyre_restms_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "announce"  >
            <action name = "announce">

#define self tcb->zyre_restms
http_driver_module_t *
    portal;
smt_log_t *
    log;

    portal = announce_m->portal;
    log = announce_m->log;
        {
self->log = smt_log_link (log);
smt_log_print (log, "I: Zyre RestMS driver loaded at '%s'", portal->path);
smt_log_print (log, "I: - peering with AMQP server at '%s'",
    zyre_config_amqp_hostname (zyre_config));
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "get"  >
            <action name = "get">

#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = get_m->portal;
    context = get_m->context;
        {
zyre_resource_t
    *resource;

if (zyre_config_restms_debug (zyre_config))
    icl_console_print ("R: GET resource '%s'", context->request->pathinfo);

if (zyre_restms_check_path (context) == 0) {
    //  Pathinfo is URI key into resource table
    resource = ipr_hash_lookup (self->resources, context->request->pathinfo);
    if (resource) {
        if (zyre_config_restms_debug (zyre_config))
            icl_console_print ("R: - resource is a %s",
                zyre_resource_type_name (resource->type));
        if (zyre_resource_modified (resource, context->request)) {
            //  Use the Accept content type for our response
            http_response_set_content_type (context->response,
                http_request_get_header (context->request, "accept"));
            zyre_resource_request_get (resource, context);
            if (!context->replied)
                http_driver_context_reply_success (context, HTTP_REPLY_OK);
        }
        else
            http_driver_context_reply_error (context, HTTP_REPLY_NOTMODIFIED, NULL);
    }
    else
        http_driver_context_reply_error (context, HTTP_REPLY_NOTFOUND,
            "URI does not match a known resource");
}
if (zyre_config_restms_debug (zyre_config) && !context->pending) {
    if (context && context->response)
        icl_console_print ("R: - reply %d %s",
            context->response->reply_code, context->response->reply_text);
    else
        icl_console_print ("R: - ERROR: context=%pp c->response=%pp",
            context, context->response);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "put"  >
            <action name = "put">

#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = put_m->portal;
    context = put_m->context;
        {
zyre_resource_t
    *resource;

if (zyre_config_restms_debug (zyre_config))
    icl_console_print ("R: UPDATE resource '%s'", context->request->pathinfo);

if (zyre_restms_check_path (context) == 0) {
    //  Pathinfo is URI key into resource table
    resource = ipr_hash_lookup (self->resources, context->request->pathinfo);
    if (resource) {
        if (zyre_config_restms_debug (zyre_config))
            icl_console_print ("R: - resource is a %s",
                zyre_resource_type_name (resource->type));
        if (zyre_resource_unmodified (resource, context->request))
            http_driver_context_reply_error (context, HTTP_REPLY_PRECONDITION,
                "resource was modified by another application");
        else {
            zyre_resource_request_put (resource, context);
            if (!context->replied)
                http_driver_context_reply_success (context, HTTP_REPLY_OK);
        }
    }
    else
        http_driver_context_reply_error (context, HTTP_REPLY_NOTFOUND,
            "URI does not match a known resource");
}
if (zyre_config_restms_debug (zyre_config)) {
    if (context && context->response)
        icl_console_print ("R: - reply %d %s",
            context->response->reply_code, context->response->reply_text);
    else
        icl_console_print ("R: - ERROR: context=%pp c->response=%pp",
            context, context->response);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "delete"  >
            <action name = "delete">

#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = delete_m->portal;
    context = delete_m->context;
        {
zyre_resource_t
    *resource;

if (zyre_config_restms_debug (zyre_config))
    icl_console_print ("R: DELETE resource '%s'", context->request->pathinfo);

if (zyre_restms_check_path (context) == 0) {
    //  Pathinfo is URI key into resource table
    resource = ipr_hash_lookup (self->resources, context->request->pathinfo);
    if (resource) {
        if (zyre_config_restms_debug (zyre_config))
            icl_console_print ("R: - resource is a %s",
                zyre_resource_type_name (resource->type));
        if (zyre_resource_unmodified (resource, context->request))
            http_driver_context_reply_error (context, HTTP_REPLY_PRECONDITION,
                "resource was modified by another application");
        else {
            //  The resource is the portal so we can't destroy it from
            //  within a request, or the request ends up trying to use a
            //  dead portal.  So we do it here, and the DELETE method
            //  just needs to verify the legitimacy of the request.
            zyre_resource_request_delete (resource, context);
            if (!context->failed) {
                //  Since we don't have a link to the resource, grab one
                //  Otherwise the destructor gets very unhappy
                resource = zyre_resource_link (resource);
                zyre_resource_detach_from_parent (resource);
                zyre_resource_destroy (&resource);
                http_driver_context_reply_success (context, HTTP_REPLY_OK);
            }
        }
    }
    else                            //  Idempotent delete -> OK
        http_driver_context_reply_success (context, HTTP_REPLY_OK);
}
if (zyre_config_restms_debug (zyre_config)) {
    if (context && context->response)
        icl_console_print ("R: - reply %d %s",
            context->response->reply_code, context->response->reply_text);
    else
        icl_console_print ("R: - ERROR: context=%pp c->response=%pp",
            context, context->response);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "post"  >
            <action name = "post">

#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = post_m->portal;
    context = post_m->context;
        {
zyre_resource_t
    *resource;

if (zyre_config_restms_debug (zyre_config))
    icl_console_print ("R: POST to '%s'", context->request->pathinfo);

if (zyre_restms_check_path (context) == 0) {
    //  Pathinfo is URI key into resource table
    resource = ipr_hash_lookup (self->resources, context->request->pathinfo);
    if (resource) {
        if (zyre_config_restms_debug (zyre_config))
            icl_console_print ("R: - resource is a %s",
                zyre_resource_type_name (resource->type));
        zyre_resource_request_post (resource, context, self->resources, self->backend);
        if (!context->replied)
            http_driver_context_reply_success (context, HTTP_REPLY_OK);
    }
    else
        http_driver_context_reply_error (context, HTTP_REPLY_NOTFOUND,
            "URI does not match a known resource");
}
if (zyre_config_restms_debug (zyre_config)) {
    if (context && context->response)
        icl_console_print ("R: - reply %d %s",
            context->response->reply_code, context->response->reply_text);
    else
        icl_console_print ("R: - ERROR: context=%pp c->response=%pp",
            context, context->response);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "head"  >
            <action name = "head">

#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = head_m->portal;
    context = head_m->context;
        {
http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
    "HEAD method is not allowed on this resource");
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "move"  >
            <action name = "move">

#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = move_m->portal;
    context = move_m->context;
        {
http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
    "MOVE method is not allowed on this resource");
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "copy"  >
            <action name = "copy">

#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = copy_m->portal;
    context = copy_m->context;
        {
http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
    "COPY method is not allowed on this resource");
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "online"  >
            <action name = "online">

#define self tcb->zyre_restms
zyre_backend_t *
    portal;
char *
    reply_queue;

    portal = online_m->portal;
    reply_queue = online_m->reply_queue;
        {
smt_log_print (self->log,
    "I: RestMS handler now peered to OpenAMQ server on %s",
    zyre_config_amqp_hostname (zyre_config));
self->connected = TRUE;
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "offline"  >
            <action name = "offline">

#define self tcb->zyre_restms
zyre_backend_t *
    portal;

    portal = offline_m->portal;
        {
smt_log_print (self->log,
    "I: RestMS handler unpeered from OpenAMQ server at %s",
    zyre_config_amqp_hostname (zyre_config));
self->connected = FALSE;
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "arrived"  >
            <action name = "arrived">

#define self tcb->zyre_restms
zyre_backend_t *
    portal;
zyre_peer_method_t *
    method;

    portal = arrived_m->portal;
    method = arrived_m->method;
        {
zyre_resource_t
    *pipe_res = NULL;
icl_shortstr_t
    pipe_path;
char
    *pipe_name;
//
//  The consumer tag should be in the form prefix:pipe-name
pipe_name = strchr (method->payload.basic_deliver.consumer_tag, ':');
if (pipe_name) {
    pipe_name++;                    //  Point to start of pipe name
    icl_shortstr_fmt (pipe_path, "/resource/%s", pipe_name);
    pipe_res = ipr_hash_lookup (self->resources, pipe_path);
}
if (zyre_config_restms_debug (zyre_config))
    icl_console_print ("R: - deliver message to pipe '%s' (%d bytes)",
        pipe_path, (int) ((amq_content_basic_t *) method->content)->body_size);

if (pipe_res) {
    zyre_resource_t
        *message_res,
        *content_res;

    //  Reach through to pipe object to grab message asynclet
    message_res = ((zyre_pipe_t *) (pipe_res->server_object))->asynclet;

    //  Create new content resource as child of message
    content_res = zyre_content__zyre_resource_new (NULL,
        message_res, self->resources, "content", "");
    zyre_restms__zyre_resource_bind (self, content_res);

    //  We provide the new resources with the AMQP method so they can
    //  process & store the AMQP content.  Not really what attach() was
    //  meant for but it's nicer than making a new portal method.
    zyre_resource_request_attach (message_res, NULL, method);
    zyre_resource_request_attach (content_res, NULL, method);
    zyre_resource_unlink (&content_res);

    //  Re-configure the pipe, which creates a new asynclet
    zyre_resource_request_configure (pipe_res, NULL, self->resources, self->backend);

    //  And now re-send the message if the clients is waiting
    zyre_resource_request_get (message_res, NULL);
}
else
    smt_log_print (self->log, "W: undeliverable message (tag='%s')",
        method->payload.basic_deliver.consumer_tag);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "returned"  >
            <action name = "returned">

#define self tcb->zyre_restms
zyre_backend_t *
    portal;
zyre_peer_method_t *
    method;

    portal = returned_m->portal;
    method = returned_m->method;
        {
icl_console_print ("E: RestMS content not routable - abonormal");
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "_zyre_backend unbind"  >
            <action name = "_zyre_backend unbind">

#define self tcb->zyre_restms
zyre_backend_t *
    portal;

    portal = _zyre_backend_unbind_m->portal;
        {
if (portal->client_looseref) {
    ipr_looseref_destroy (&portal->client_looseref);
    zyre_backend_unlink (&portal);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "_http_driver_module unbind"  >
            <action name = "_http_driver_module unbind">

#define self tcb->zyre_restms
http_driver_module_t *
    portal;

    portal = _http_driver_module_unbind_m->portal;
        {
if (portal->server_looseref) {
    ipr_looseref_destroy (&portal->server_looseref);
    http_driver_module_unlink (&portal);
}
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

#define self tcb->zyre_restms
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
{
http_driver_module_t
    *http_driver_module;            //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->http_driver_module_stopped, TRUE, FALSE) == FALSE) {
    while ((http_driver_module = (http_driver_module_t *) ipr_looseref_pop (self->http_driver_module_list))) {
        http_driver_module->server_looseref = NULL;
        http_driver_module_destroy (&http_driver_module);
    }
}
ipr_looseref_list_destroy (&self->http_driver_module_list);
}

{
zyre_backend_t
    *zyre_backend;                  //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_backend_stopped, TRUE, FALSE) == FALSE) {
    //  Destroy own portals
    while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_list))) {
        zyre_backend->client_looseref = NULL;
        zyre_backend_destroy (&zyre_backend);
    }
    ipr_looseref_list_destroy (&self->zyre_backend_list);
    //  Destroy own portal factories
    while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_factory_list))) {
        zyre_backend->client_looseref = NULL;
        zyre_backend_destroy (&zyre_backend);
    }
    ipr_looseref_list_destroy (&self->zyre_backend_factory_list);
}
}

ipr_hash_table_destroy (&self->resources);
zyre_backend_unlink (&self->backend);
smt_log_unlink (&self->log);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->zyre_restms
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on zyre_restms object");
    zyre_restms_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    zyre_restms_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "announce" />
        <method name = "get" />
        <method name = "put" />
        <method name = "delete" />
        <method name = "post" />
        <method name = "head" />
        <method name = "move" />
        <method name = "copy" />
        <method name = "online" />
        <method name = "offline" />
        <method name = "arrived" />
        <method name = "returned" />
        <method name = "_zyre_backend unbind" />
        <method name = "_http_driver_module unbind" />
    </state>
</thread>

</agent>
