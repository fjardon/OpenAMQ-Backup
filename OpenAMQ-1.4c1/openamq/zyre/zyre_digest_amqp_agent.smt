<?xml?>
<!---------------------------------------------------------------------------
    zyre_digest_amqp_agent.smt - zyre_digest_amqp component

    Refreshes expired or missing passwords using the protocol specified by
    the 8-Digest-AMQP@wiki.amqp.org specification.
    Generated from zyre_digest_amqp.icl by smt_object_gen using GSL/4.

    
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
    name = "zyre_digest_amqp_agent"
    script = "smt_gen.gsl"
    animate = "0"
    >
<import class = "zyre_digest_amqp" />

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
</method>

<method name = "announce">
    <argument name = "portal" type = "http_access_module_t *" />
    <argument name = "log" type = "smt_log_t *" />
</method>

<method name = "before">
    <argument name = "portal" type = "http_access_module_t *" />
    <argument name = "context" type = "http_access_context_t *" />
</method>

<method name = "send request">
    <argument name = "user" type = "char * " />
    <argument name = "realm" type = "char * " />
    <possess>

    user = icl_mem_strdup (user);
    realm = icl_mem_strdup (realm);
    
    </possess>
    <release>

    icl_mem_strfree (&user);
    icl_mem_strfree (&realm);
    
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

<method name = "_http_access_module unbind">
    <argument name = "portal" type = "http_access_module_t *" />
</method>

<method name = "open">
    <argument name = "portal" type = "http_access_module_t *" />
    <argument name = "context" type = "http_access_context_t *" />
</method>

<method name = "after">
    <argument name = "portal" type = "http_access_module_t *" />
    <argument name = "context" type = "http_access_context_t *" />
</method>

<method name = "close">
    <argument name = "portal" type = "http_access_module_t *" />
    <argument name = "context" type = "http_access_context_t *" />
</method>

<thread name = "class">
    <context>
        zyre_digest_amqp_t
            *zyre_digest_amqp;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "zyre_digest_amqp_t *">The iCL object</argument>
        tcb->zyre_digest_amqp = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->zyre_digest_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
{
http_access_module_t
    *http_access_module;            //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->http_access_module_stopped, TRUE, FALSE) == FALSE) {
    while ((http_access_module = (http_access_module_t *) ipr_looseref_pop (self->http_access_module_list))) {
        http_access_module->server_looseref = NULL;
        http_access_module_destroy (&http_access_module);
    }
}
ipr_looseref_list_destroy (&self->http_access_module_list);
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

self->portal = NULL;
zyre_backend_unlink (&self->backend);
smt_log_unlink (&self->log);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->zyre_digest_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on zyre_digest_amqp object");
    zyre_digest_amqp_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    zyre_digest_amqp_free (self);
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

#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;
smt_log_t *
    log;

    portal = announce_m->portal;
    log = announce_m->log;
        {
//  We  don't link to the portal since the portal wraps this object and
//  destroys it.  The portal receives responses back from us when we're
//  invoked asynchronously.  Sorry this is kind of complex... in a portal
//  request handler, 'portal' is the portal that sent us the request.
//  In the 'arrived' method we get a request from one portal and send a
//  response to a different one, namely this one back to http_server:
self->portal = portal;

self->log = smt_log_link (log);
smt_log_print (log, "I: Zyre Digest-AMQP access module loaded");
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "before"  >
            <action name = "before">

#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;
http_access_context_t *
    context;

    portal = before_m->portal;
    context = before_m->context;
        {
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "send request"  >
            <action name = "send request">

#define self tcb->zyre_digest_amqp
char * 
    user;
char * 
    realm;

    user = send_request_m->user;
    realm = send_request_m->realm;
        {
amq_content_basic_t
    *content;                       //  Content to post
char
    *body;                          //  Formatted message body

if (self->connected) {
    //  we need a private queue for responses back from server...
    body = ipr_str_format (
        "&lt;digest-amqp version=\"1.0\"&gt;"
            "&lt;request"
            " user=\"%s\""
            " realm=\"%s\""
            " algorithm=\"MD5\""
            " reply_to=\"%s\""
            " /&gt;"
        "&lt;/digest-amqp&gt;", user, realm, self->reply_queue);

    content = amq_content_basic_new ();
    amq_content_basic_set_body (content, body, strlen (body), icl_mem_free);
    //  Send to default exchange, with service name as routing key
    zyre_backend_request_forward (self->backend,
        NULL, "Digest-AMQP", content, TRUE, TRUE);
    amq_content_basic_unlink (&content);
    smt_log_print (self->log, "I: sent Digest-AMQP request for '%s:%s'", user, realm);
}
else
    smt_log_print (self->log, "W: could not send Digest-AMQP request for '%s:%s', not connected",
        user, realm);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "online"  >
            <action name = "online">

#define self tcb->zyre_digest_amqp
zyre_backend_t *
    portal;
char *
    reply_queue;

    portal = online_m->portal;
    reply_queue = online_m->reply_queue;
        {
smt_log_print (self->log,
    "I: Digest-AMQP now peered to OpenAMQ server on %s",
    zyre_config_amqp_hostname (zyre_config));
self->connected = TRUE;
icl_shortstr_cpy (self->reply_queue, reply_queue);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "offline"  >
            <action name = "offline">

#define self tcb->zyre_digest_amqp
zyre_backend_t *
    portal;

    portal = offline_m->portal;
        {
smt_log_print (self->log,
    "I: Digest-AMQP unpeered from OpenAMQ server at %s",
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

#define self tcb->zyre_digest_amqp
zyre_backend_t *
    portal;
zyre_peer_method_t *
    method;

    portal = arrived_m->portal;
    method = arrived_m->method;
        {
//  We got a response back from the Digest-AMQP service.  Parse it for
//  a username, realm, and digest and ok, send those credentials to the
//  http_server.
//
asl_reader_t
    reader;                         //  Body reader
ipr_bucket_t
    *bucket;                        //  Body bucket
ipr_xml_t
    *xml_root = NULL,
    *response;
char
    *user,
    *realm,
    *digest;

amq_content_basic_set_reader (method->content, &reader, 4096);
bucket = amq_content_basic_replay_body (method->content, &reader);
xml_root = ipr_xml_parse_bucket (bucket);
response = ipr_xml_find_item (xml_root, "/digest-amqp/response");
if (response) {
    user   = ipr_xml_attr_get (response, "user", NULL);
    realm  = ipr_xml_attr_get (response, "realm", NULL);
    digest = ipr_xml_attr_get (response, "digest", NULL);
    if (user && realm && digest) {
        icl_shortstr_t
            key;
        icl_shortstr_fmt (key, "%s:%s", user, realm);
        http_access_module_response_new_password (self->portal, key, digest, TRUE);
    }
    ipr_xml_unlink (&response);
}
ipr_bucket_unlink (&bucket);
ipr_xml_destroy (&xml_root);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "returned"  >
            <action name = "returned">

#define self tcb->zyre_digest_amqp
zyre_backend_t *
    portal;
zyre_peer_method_t *
    method;

    portal = returned_m->portal;
    method = returned_m->method;
        {
icl_console_print ("I: Digest-AMQP service is not running");
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "_zyre_backend unbind"  >
            <action name = "_zyre_backend unbind">

#define self tcb->zyre_digest_amqp
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


        <method name = "_http_access_module unbind"  >
            <action name = "_http_access_module unbind">

#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;

    portal = _http_access_module_unbind_m->portal;
        {
if (portal->server_looseref) {
    ipr_looseref_destroy (&portal->server_looseref);
    http_access_module_unlink (&portal);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "open"  >
            <action name = "open">

#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;
http_access_context_t *
    context;

    portal = open_m->portal;
    context = open_m->context;
        {
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "after"  >
            <action name = "after">

#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;
http_access_context_t *
    context;

    portal = after_m->portal;
    context = after_m->context;
        {
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "close"  >
            <action name = "close">

#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;
http_access_context_t *
    context;

    portal = close_m->portal;
    context = close_m->context;
        {
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

#define self tcb->zyre_digest_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
{
http_access_module_t
    *http_access_module;            //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->http_access_module_stopped, TRUE, FALSE) == FALSE) {
    while ((http_access_module = (http_access_module_t *) ipr_looseref_pop (self->http_access_module_list))) {
        http_access_module->server_looseref = NULL;
        http_access_module_destroy (&http_access_module);
    }
}
ipr_looseref_list_destroy (&self->http_access_module_list);
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

self->portal = NULL;
zyre_backend_unlink (&self->backend);
smt_log_unlink (&self->log);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->zyre_digest_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on zyre_digest_amqp object");
    zyre_digest_amqp_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    zyre_digest_amqp_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "announce" />
        <method name = "before" />
        <method name = "send request" />
        <method name = "online" />
        <method name = "offline" />
        <method name = "arrived" />
        <method name = "returned" />
        <method name = "_zyre_backend unbind" />
        <method name = "_http_access_module unbind" />
        <method name = "open" />
        <method name = "after" />
        <method name = "close" />
    </state>
</thread>

</agent>
