<?xml?>
<!---------------------------------------------------------------------------
    zyre_backend_amqp_agent.smt - zyre_backend_amqp component

Backend module that talks to an OpenAMQ server, originally based on
the amq_peering class, but modified to work with IPR portals and to
implement the RestMS data model.

This module implementation replicates the state used by the Zyre RestMS
server.  Namely:

  * A set of feeds, pipes, and joins, implemented on the AMQP server as
    exchanges, queues, bindings, and consumers.  This peering class is the
    place where the mapping from RestMS to AMQP is defined in detail.

  * A queue of messages waiting to be published to the AMQP server.

The peering isolates the application from the AMQP server, allowing the
state to be updated asynchronously from any connection.  That is, before
a connection is made, while a connection is active, or when a connection
has died and is being brought back.

Lastly, the peering will invoke callback methods to tell you when the peer
link becomes active, and when a message content arrives.
    Generated from zyre_backend_amqp.icl by smt_object_gen using GSL/4.

    
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
    name = "zyre_backend_amqp_agent"
    script = "smt_gen.gsl"
    animate = "0"
    >
<import class = "zyre_backend_amqp" />

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
</method>

<method name = "start">
    <argument name = "portal" type = "zyre_backend_t *" />
</method>

<method name = "stop">
    <argument name = "portal" type = "zyre_backend_t *" />
</method>

<method name = "pipe create">
    <argument name = "portal" type = "zyre_backend_t *" />
    <argument name = "pipe_type" type = "char *" />
    <argument name = "pipe_name" type = "char *" />
    <possess>

    
        pipe_type = icl_mem_strdup (pipe_type);
        pipe_name = icl_mem_strdup (pipe_name);
      
    
    </possess>
    <release>

    
        icl_mem_free (pipe_type);
        icl_mem_free (pipe_name);
      
    
    </release>
</method>

<method name = "pipe delete">
    <argument name = "portal" type = "zyre_backend_t *" />
    <argument name = "pipe_name" type = "char *" />
    <possess>

    
        pipe_name = icl_mem_strdup (pipe_name);
      
    
    </possess>
    <release>

    
        icl_mem_free (pipe_name);
      
    
    </release>
</method>

<method name = "feed create">
    <argument name = "portal" type = "zyre_backend_t *" />
    <argument name = "feed_type" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <possess>

    
        feed_type = icl_mem_strdup (feed_type);
        feed_name = icl_mem_strdup (feed_name);
      
    
    </possess>
    <release>

    
        icl_mem_free (feed_type);
        icl_mem_free (feed_name);
      
    
    </release>
</method>

<method name = "feed delete">
    <argument name = "portal" type = "zyre_backend_t *" />
    <argument name = "feed_name" type = "char *" />
    <possess>

    
        feed_name = icl_mem_strdup (feed_name);
      
    
    </possess>
    <release>

    
        icl_mem_free (feed_name);
      
    
    </release>
</method>

<method name = "join create">
    <argument name = "portal" type = "zyre_backend_t *" />
    <argument name = "pipe_name" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <argument name = "address" type = "char *" />
    <possess>

    
        pipe_name = icl_mem_strdup (pipe_name);
        feed_name = icl_mem_strdup (feed_name);
        address = icl_mem_strdup (address);
      
    
    </possess>
    <release>

    
        icl_mem_free (pipe_name);
        icl_mem_free (feed_name);
        icl_mem_free (address);
      
    
    </release>
</method>

<method name = "join delete">
    <argument name = "portal" type = "zyre_backend_t *" />
    <argument name = "pipe_name" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <argument name = "address" type = "char *" />
    <possess>

    
        pipe_name = icl_mem_strdup (pipe_name);
        feed_name = icl_mem_strdup (feed_name);
        address = icl_mem_strdup (address);
      
    
    </possess>
    <release>

    
        icl_mem_free (pipe_name);
        icl_mem_free (feed_name);
        icl_mem_free (address);
      
    
    </release>
</method>

<method name = "address post">
    <argument name = "portal" type = "zyre_backend_t *" />
    <argument name = "address" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <argument name = "content" type = "amq_content_basic_t *" />
    <possess>

    
        address = icl_mem_strdup (address);
        feed_name = icl_mem_strdup (feed_name);
        content = amq_content_basic_link (content);
      
    
    </possess>
    <release>

    
        icl_mem_free (address);
        icl_mem_free (feed_name);
        amq_content_basic_unlink (&content);
      
    
    </release>
</method>

<method name = "forward">
    <argument name = "portal" type = "zyre_backend_t *" />
    <argument name = "exchange" type = "char *" />
    <argument name = "routing_key" type = "char *" />
    <argument name = "content" type = "amq_content_basic_t *" />
    <argument name = "mandatory" type = "Bool" />
    <argument name = "immediate" type = "Bool" />
    <possess>

    
        exchange = icl_mem_strdup (exchange);
        routing_key = icl_mem_strdup (routing_key);
        content = amq_content_basic_link (content);
      
    
    </possess>
    <release>

    
        icl_mem_free (exchange);
        icl_mem_free (routing_key);
        amq_content_basic_unlink (&content);
      
    
    </release>
</method>

<method name = "online partial">
    <argument name = "portal" type = "zyre_backend_t *" />
</method>

<method name = "online final">
    <argument name = "portal" type = "zyre_backend_t *" />
</method>

<method name = "_zyre_backend unbind">
    <argument name = "portal" type = "zyre_backend_t *" />
</method>

<thread name = "class">
    <context>
        zyre_backend_amqp_t
            *zyre_backend_amqp;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "zyre_backend_amqp_t *">The iCL object</argument>
        tcb->zyre_backend_amqp = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->zyre_backend_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
{
zyre_backend_t
    *zyre_backend;                  //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_backend_stopped, TRUE, FALSE) == FALSE) {
    while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_list))) {
        zyre_backend->server_looseref = NULL;
        zyre_backend_destroy (&zyre_backend);
    }
}
ipr_looseref_list_destroy (&self->zyre_backend_list);
}

{
zyre_peer_method_t
    *method;                        //  Queue.Bind method

self->portal = NULL;
s_terminate_peering (self);
icl_longstr_destroy (&self->auth_data);

while ((method = (zyre_peer_method_t *) ipr_looseref_pop (self->messages)))
    zyre_peer_method_unlink (&method);
ipr_looseref_list_destroy (&self->messages);
ipr_hash_table_apply   (self->feed_table, s_destroy_feed, NULL);
ipr_hash_table_apply   (self->pipe_table, s_destroy_pipe, NULL);
ipr_hash_table_destroy (&self->pipe_table);
ipr_hash_table_destroy (&self->feed_table);
}
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->zyre_backend_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on zyre_backend_amqp object");
    zyre_backend_amqp_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    zyre_backend_amqp_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "start"  >
            <action name = "start">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;

    portal = start_m->portal;
        {
ipr_config_t
    *config;                        //  Current server config file
char
    *login = "peering";             //  Local user name for credentials

config = ipr_config_dup (zyre_peer_config_table (zyre_peer_config));
ipr_config_locate (config, "/config/security", "plain");
if (config->located)
    ipr_config_locate (config, "user", login);
if (config->located) {
    icl_longstr_destroy (&self->auth_data);
    self->auth_data = ipr_sasl_plain_encode (login, ipr_config_get (config, "password", ""));
}
else {
    smt_log_print (http_server->alert_log,
        "E: login credentials for '%s' not defined - cannot connect", login);
    smt_log_print (http_server->alert_log,
        "E: please check security section in configuration, and restart");
    exit (EXIT_FAILURE);
}
ipr_config_destroy (&config);

//  We  don't link to the portal since the portal wraps this object and
//  destroys it.  The portal receives responses back from the smt thread
//  in zyre_peer_agent.
self->portal = portal;
self->enabled = TRUE;

//  Launch monitor to do actual connection
smt_timer_request_delay (self->thread, 100 * 1000, monitor_event);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "stop"  >
            <action name = "stop">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;

    portal = stop_m->portal;
        {
//  Tell monitor to disconnect, if connected
self->enabled = FALSE;
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "pipe create"  >
            <action name = "pipe create">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    pipe_type;
char *
    pipe_name;

    portal = pipe_create_m->portal;
    pipe_type = pipe_create_m->pipe_type;
    pipe_name = pipe_create_m->pipe_name;
        {
zyre_amqp_pipe_t
    *pipe;

assert (ipr_hash_lookup (self->pipe_table, pipe_name) == NULL);
pipe = zyre_amqp_pipe_new (pipe_type, pipe_name);
ipr_hash_insert (self->pipe_table, pipe_name, pipe);
if (self->connected)
    zyre_peer_agent_restms_pipe_create (
        self->peer_agent_thread,
        self->channel_nbr,
        pipe_type, pipe_name);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "pipe delete"  >
            <action name = "pipe delete">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    pipe_name;

    portal = pipe_delete_m->portal;
    pipe_name = pipe_delete_m->pipe_name;
        {
zyre_amqp_pipe_t
    *pipe;

pipe = ipr_hash_lookup (self->pipe_table, pipe_name);
assert (pipe);
if (self->connected)
    zyre_peer_agent_restms_pipe_delete (
        self->peer_agent_thread,
        self->channel_nbr,
        pipe_name);
ipr_hash_delete (self->pipe_table, pipe_name);
zyre_amqp_pipe_destroy (&pipe);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "feed create"  >
            <action name = "feed create">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    feed_type;
char *
    feed_name;

    portal = feed_create_m->portal;
    feed_type = feed_create_m->feed_type;
    feed_name = feed_create_m->feed_name;
        {
zyre_amqp_feed_t
    *feed;

assert (ipr_hash_lookup (self->feed_table, feed_name) == NULL);
feed = zyre_amqp_feed_new (feed_type, feed_name);
ipr_hash_insert (self->feed_table, feed_name, feed);
if (self->connected)
    zyre_peer_agent_restms_feed_create (
        self->peer_agent_thread,
        self->channel_nbr,
        feed_type, feed_name);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "feed delete"  >
            <action name = "feed delete">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    feed_name;

    portal = feed_delete_m->portal;
    feed_name = feed_delete_m->feed_name;
        {
zyre_amqp_feed_t
    *feed;

feed = ipr_hash_lookup (self->feed_table, feed_name);
assert (feed);
if (self->connected)
    zyre_peer_agent_restms_feed_delete (
        self->peer_agent_thread,
        self->channel_nbr,
        feed_name);
ipr_hash_delete (self->feed_table, feed_name);
zyre_amqp_feed_destroy (&feed);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "join create"  >
            <action name = "join create">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    pipe_name;
char *
    feed_name;
char *
    address;

    portal = join_create_m->portal;
    pipe_name = join_create_m->pipe_name;
    feed_name = join_create_m->feed_name;
    address = join_create_m->address;
        {
zyre_amqp_pipe_t
    *pipe;
zyre_amqp_join_t
    *join;

pipe = ipr_hash_lookup (self->pipe_table, pipe_name);
assert (pipe);
assert (zyre_amqp_pipe_join_lookup (pipe, feed_name, address) == NULL);
join = zyre_amqp_join_new (pipe_name, feed_name, address);
join->pipe_ref = ipr_looseref_queue (pipe->joins, join);
if (self->connected)
    zyre_peer_agent_restms_join_create (
        self->peer_agent_thread,
        self->channel_nbr,
        pipe_name, feed_name, address);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "join delete"  >
            <action name = "join delete">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    pipe_name;
char *
    feed_name;
char *
    address;

    portal = join_delete_m->portal;
    pipe_name = join_delete_m->pipe_name;
    feed_name = join_delete_m->feed_name;
    address = join_delete_m->address;
        {
zyre_amqp_pipe_t
    *pipe;
zyre_amqp_join_t
    *join;

pipe = ipr_hash_lookup (self->pipe_table, pipe_name);
assert (pipe);
join = zyre_amqp_pipe_join_lookup (pipe, feed_name, address);
assert (join);
if (self->connected)
    zyre_peer_agent_restms_join_delete (
        self->peer_agent_thread,
        self->channel_nbr,
        pipe_name, feed_name, address);

//  Pipe must still exist
ipr_looseref_destroy (&join->pipe_ref);
zyre_amqp_join_destroy (&join);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "address post"  >
            <action name = "address post">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    address;
char *
    feed_name;
amq_content_basic_t *
    content;

    portal = address_post_m->portal;
    address = address_post_m->address;
    feed_name = address_post_m->feed_name;
    content = address_post_m->content;
        {
zyre_peer_method_t
    *method;
zyre_amqp_feed_t
    *feed;

feed = ipr_hash_lookup (self->feed_table, feed_name);
if (*feed_name)
    assert (feed);                  //  Default feed is not defined

if (*feed_name && feed->as_queue) {
    method = zyre_peer_method_new_basic_publish (
        0,                          //  Ticket
        NULL,                       //  Default exchange
        feed_name,                  //  Routing key is queue name
        FALSE,                      //  Not mandatory
        FALSE);                     //  Not immediate
}
else
    method = zyre_peer_method_new_basic_publish (
        0,                          //  Ticket
        feed_name,                  //  Feed exchange
        address,                    //  Routing key is address
        FALSE,                      //  Not mandatory
        FALSE);                     //  Not immediate

method->content = amq_content_basic_link (content);

//  We send the message if we can, else we queue it for later
if (self->connected) {
    zyre_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
    zyre_peer_method_unlink (&method);
}
else
    ipr_looseref_queue (self->messages, method);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "forward"  >
            <action name = "forward">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    exchange;
char *
    routing_key;
amq_content_basic_t *
    content;
Bool
    mandatory;
Bool
    immediate;

    portal = forward_m->portal;
    exchange = forward_m->exchange;
    routing_key = forward_m->routing_key;
    content = forward_m->content;
    mandatory = forward_m->mandatory;
    immediate = forward_m->immediate;
        {
zyre_peer_method_t
    *method;

//  Create a Basic.Publish method
method = zyre_peer_method_new_basic_publish (
    0, exchange, routing_key, mandatory, immediate);
method->content = amq_content_basic_link (content);

//  We only hold forwards if the connection is currently down
if (self->connected) {
    zyre_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
    zyre_peer_method_unlink (&method);
}
else
    ipr_looseref_queue (self->messages, method);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "online partial"  >
            <action name = "online partial">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;

    portal = online_partial_m->portal;
        {
self->channel_nbr = 1;
zyre_peer_agent_channel_open (self->peer_agent_thread, self->channel_nbr);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "online final"  >
            <action name = "online final">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;

    portal = online_final_m->portal;
        {
zyre_peer_method_t
    *method;                        //  Method to send to peer server

if (!self->connected) {
    self->connected = TRUE;
    self->offlined = FALSE;

    //  Create first feeds, then pipes, then joins on AMQP server
    ipr_hash_table_apply (self->feed_table, s_synchronize_feed, self);
    ipr_hash_table_apply (self->pipe_table, s_synchronize_pipe, self);

    //  Forward all pending messages to AMQP server
    while ((method = (zyre_peer_method_t *) ipr_looseref_pop (self->messages))) {
        zyre_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
        zyre_peer_method_unlink (&method);
    }
    //  Create private queue for internal request-response
    zyre_peer_agent_queue_declare (
        self->peer_agent_thread, self->channel_nbr, 0, self->queue,
        FALSE, FALSE, TRUE, TRUE, TRUE, NULL);
    zyre_peer_agent_basic_consume (
        self->peer_agent_thread, self->channel_nbr, 0, self->queue,
        NULL, TRUE, TRUE, TRUE, TRUE, NULL);
}
zyre_backend_response_online (self->portal, self->queue);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "_zyre_backend unbind"  >
            <action name = "_zyre_backend unbind">

#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;

    portal = _zyre_backend_unbind_m->portal;
        {
if (portal->server_looseref) {
    ipr_looseref_destroy (&portal->server_looseref);
    zyre_backend_unlink (&portal);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <event name = "monitor"  >
            <action name = "monitor">
            
#define self tcb->zyre_backend_amqp

        {
//  Terminate the peering if the application asked for it, or the
//  peer agent thread was closed from the network side.
if (self->peer_agent_thread && (!self->enabled || self->peer_agent_thread->zombie))
    s_terminate_peering (self);
else
//  Connect the peering if we're not already connected but the app
//  has for the peering to become active.
if (!self->peer_agent_thread && self->enabled)
    self->peer_agent_thread = zyre_peer_agent_connection_thread_new (
        self->portal,               //  Callback for incoming methods
        zyre_config_amqp_hostname (zyre_config),
        "/",                        //  Virtual host
        self->auth_data,
        "Zyre peering",             //  Instance name
        zyre_config_amqp_trace   (zyre_config),
        zyre_config_amqp_timeout (zyre_config),
        zyre_config_amqp_debug   (zyre_config));

//  Peering monitor runs once per second
smt_timer_request_delay (self->thread, 1000 * 1000, monitor_event);
        }
        
#undef self
            </action>
        </event>
        <event name = "shutdown" nextstate = "shutting down" />
    </state>
    
    <state name = "shutting down">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->zyre_backend_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
{
zyre_backend_t
    *zyre_backend;                  //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_backend_stopped, TRUE, FALSE) == FALSE) {
    while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_list))) {
        zyre_backend->server_looseref = NULL;
        zyre_backend_destroy (&zyre_backend);
    }
}
ipr_looseref_list_destroy (&self->zyre_backend_list);
}

{
zyre_peer_method_t
    *method;                        //  Queue.Bind method

self->portal = NULL;
s_terminate_peering (self);
icl_longstr_destroy (&self->auth_data);

while ((method = (zyre_peer_method_t *) ipr_looseref_pop (self->messages)))
    zyre_peer_method_unlink (&method);
ipr_looseref_list_destroy (&self->messages);
ipr_hash_table_apply   (self->feed_table, s_destroy_feed, NULL);
ipr_hash_table_apply   (self->pipe_table, s_destroy_pipe, NULL);
ipr_hash_table_destroy (&self->pipe_table);
ipr_hash_table_destroy (&self->feed_table);
}
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->zyre_backend_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on zyre_backend_amqp object");
    zyre_backend_amqp_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    zyre_backend_amqp_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "start" />
        <method name = "stop" />
        <method name = "pipe create" />
        <method name = "pipe delete" />
        <method name = "feed create" />
        <method name = "feed delete" />
        <method name = "join create" />
        <method name = "join delete" />
        <method name = "address post" />
        <method name = "forward" />
        <method name = "online partial" />
        <method name = "online final" />
        <method name = "_zyre_backend unbind" />
        <event name = "monitor" />
    </state>
</thread>

<private name = "types">
static void s_terminate_peering (zyre_backend_amqp_t *self);
static void s_synchronize_pipe  (ipr_hash_t *hash, void *argument);
static void s_synchronize_feed  (ipr_hash_t *hash, void *argument);
static void s_destroy_pipe      (ipr_hash_t *hash, void *argument);
static void s_destroy_feed      (ipr_hash_t *hash, void *argument);
</private>

<private name = "functions">
static void
s_terminate_peering (zyre_backend_amqp_t *self)
{
    //  Stop peer agent thread if it's still alive
    if (self->peer_agent_thread) {
        if (!self->peer_agent_thread->zombie)
            zyre_peer_agent_connection_close (self->peer_agent_thread);
        smt_thread_unlink (&self->peer_agent_thread);
    }
    if (self->connected) {
        self->connected = FALSE;
        self->offlined  = TRUE;
        if (self->portal)
            zyre_backend_response_offline (self->portal);
    }
}

static void s_synchronize_pipe (ipr_hash_t *hash, void *argument)
{
    ipr_looseref_t
        *looseref;
    zyre_amqp_join_t
        *join;                          //  Each join for pipe
    zyre_backend_amqp_t
        *self = (zyre_backend_amqp_t *) argument;
    zyre_amqp_pipe_t
        *pipe = (zyre_amqp_pipe_t *) hash->data;

    zyre_peer_agent_restms_pipe_create (
        self->peer_agent_thread,
        self->channel_nbr,
        pipe->type, pipe->name);

    //  Synchronize all joins for this pipe
    looseref = ipr_looseref_list_first (pipe->joins);
    while (looseref) {
        join = ((zyre_amqp_join_t *) looseref->object);
        zyre_peer_agent_restms_join_create (
            self->peer_agent_thread,
            self->channel_nbr,
            join->pipe_name, join->feed_name, join->address);
        looseref = ipr_looseref_list_next (&looseref);
    }
}

static void s_synchronize_feed (ipr_hash_t *hash, void *argument)
{
    zyre_backend_amqp_t
        *self = (zyre_backend_amqp_t *) argument;
    zyre_amqp_feed_t
        *feed = (zyre_amqp_feed_t *) hash->data;

    zyre_peer_agent_restms_feed_create (
        self->peer_agent_thread,
        self->channel_nbr,
        feed->type, feed->name);
}

static void s_destroy_pipe (ipr_hash_t *hash, void *argument)
{
    zyre_amqp_pipe_t
        *pipe = (zyre_amqp_pipe_t *) hash->data;
    zyre_amqp_join_t
        *join;                          //  Each join for pipe

    //  Destroy all joins for this pipe
    while ((join = (zyre_amqp_join_t *) ipr_looseref_pop (pipe->joins)))
        zyre_amqp_join_destroy (&join);

    zyre_amqp_pipe_destroy (&pipe);
}

static void s_destroy_feed (ipr_hash_t *hash, void *argument)
{
    zyre_amqp_feed_t
        *feed = (zyre_amqp_feed_t *) hash->data;
    zyre_amqp_feed_destroy (&feed);
}
</private>

</agent>
