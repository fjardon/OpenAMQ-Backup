<?xml?>
<!---------------------------------------------------------------------------
    amq_peering_agent.smt - amq_peering component

This class defines a smart link to a remote server.  You tell the peering
what server to talk to and it will monitor the server and connect
automatically when the server comes online, and reconnect if the server
goes offline for a period.

A peering has two functions:

1. Binding propagation, in which messages published to an exchange on the
   remote server can be "pulled" to this server.  You tell the peering what
   bindings you are interested in, and it will deliver you all matching
   messages.

2. Message forwarding, in which messages originating locally are carried to
   the remote peer.  This class does not specify where those local messages
   come from.

The peer link may be arbitrarily active or inactive depending on the state
of the network and the remote server.

The peering will replay all bindings if when the peer link becomes active.
It will queue messages that are forwarded when the peer link is not active.

Lastly, the peering will invoke callback methods to tell you when the peer
link becomes active, and when a content arrives.  Currently this class
works only with Basic contents.

The selftest method demonstrates fairly sophisticated peering use.  To test
this, set the environment variable AMQ_PEERING_TEST=1 and run an amq_server.

Note that the current amq_peering implementation is limited to a signle
exchange per amq_peering instance.

This is a summary of the amq_peering API:

    peering = amq_peering_new (
        remote-host-name, virtual-host, trace-level, exchange-name)
        Create a new peering to the specified host, virtual host and
        remote exchange.

    amq_peering_set_login (peering, login-name)
        Tell the peering to login using the specified login-name, which
        must be defined in the local amq_server_base.cfg or amq_server.cfg.

    amq_peering_set_status_handler (peering, handler, calling-object)
        Set the callback handler for status updates.

    amq_peering_set_content_handler (peering, handler, calling-object)
        Set the callback handler for incoming messages.

    amq_peering_start (peering)
        Enable the peering, connect to remote server when possible.

    amq_peering_stop (peering)
        Disable the peering, disconnect from remote server if necessary.

    amq_peering_bind (peering, routing-key, arguments)
        Replicate a binding to the remote server.

    amq_peering_unbind (peering, routing-key, arguments)
        Replicate a queue.unbind to the remote server.  Also removes the
        binding from the list of bindings to replay.

    amq_peering_forward (peering, routing-key, content, madatory, immediate)
        Publish a message to the remote server.

    amq_peering_destroy (&peering)
        Destroy the peering.
    Generated from amq_peering.icl by smt_object_gen using GSL/4.

    
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
    name = "amq_peering_agent"
    script = "smt_gen.gsl"
    animate = "0"
    >
<import class = "amq_peering" />

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
</method>

<method name = "start">
</method>

<method name = "stop">
</method>

<method name = "bind">
    <argument name = "routing_key" type = "char *" />
    <argument name = "arguments" type = "icl_longstr_t *" />
    <possess>

    routing_key = icl_mem_strdup (routing_key);
    arguments = icl_longstr_dup (arguments);
    
    </possess>
    <release>

    icl_mem_free (routing_key);
    icl_longstr_destroy (&arguments);
    
    </release>
</method>

<method name = "unbind">
    <argument name = "routing_key" type = "char *" />
    <argument name = "arguments" type = "icl_longstr_t *" />
    <possess>

    routing_key = icl_mem_strdup (routing_key);
    arguments = icl_longstr_dup (arguments);
    
    </possess>
    <release>

    icl_mem_free (routing_key);
    icl_longstr_destroy (&arguments);
    
    </release>
</method>

<method name = "forward">
    <argument name = "routing_key" type = "char *" />
    <argument name = "content" type = "amq_content_basic_t *" />
    <argument name = "mandatory" type = "Bool" />
    <argument name = "immediate" type = "Bool" />
    <possess>

    routing_key = icl_mem_strdup (routing_key);
    content = amq_content_basic_link (content);
    
    </possess>
    <release>

    icl_mem_free (routing_key);
    amq_content_basic_unlink (&content);
    
    </release>
</method>

<method name = "peer connection start">
    <argument name = "method" type = "amq_peer_method_t *" />
    <possess>

    method = amq_peer_method_link (method);
    
    </possess>
    <release>

    amq_peer_method_unlink (&method);
    
    </release>
</method>

<method name = "peer connection open ok">
    <argument name = "method" type = "amq_peer_method_t *" />
    <possess>

    method = amq_peer_method_link (method);
    
    </possess>
    <release>

    amq_peer_method_unlink (&method);
    
    </release>
</method>

<method name = "peer connection close">
    <argument name = "method" type = "amq_peer_method_t *" />
    <possess>

    method = amq_peer_method_link (method);
    
    </possess>
    <release>

    amq_peer_method_unlink (&method);
    
    </release>
</method>

<method name = "peer channel open ok">
    <argument name = "method" type = "amq_peer_method_t *" />
    <possess>

    method = amq_peer_method_link (method);
    
    </possess>
    <release>

    amq_peer_method_unlink (&method);
    
    </release>
</method>

<method name = "peer basic deliver">
    <argument name = "method" type = "amq_peer_method_t *" />
    <possess>

    method = amq_peer_method_link (method);
    
    </possess>
    <release>

    amq_peer_method_unlink (&method);
    
    </release>
</method>

<method name = "peer basic return">
    <argument name = "method" type = "amq_peer_method_t *" />
    <possess>

    method = amq_peer_method_link (method);
    
    </possess>
    <release>

    amq_peer_method_unlink (&method);
    
    </release>
</method>

<thread name = "class">
    <context>
        amq_peering_t
            *amq_peering;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_peering_t *">The iCL object</argument>
        tcb->amq_peering = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_peering
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_peer_method_t
    *method;                        //  Queue.Bind method

s_terminate_peering (self);
icl_longstr_destroy (&self->auth_data);

while ((method = (amq_peer_method_t *) ipr_looseref_pop (self->bindings)))
    amq_peer_method_unlink (&method);
ipr_looseref_list_destroy (&self->bindings);

while ((method = (amq_peer_method_t *) ipr_looseref_pop (self->messages)))
    amq_peer_method_unlink (&method);
ipr_looseref_list_destroy (&self->messages);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_peering
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_peering object");
    amq_peering_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_peering_free (self);
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

#define self tcb->amq_peering

        {
self->enabled = TRUE;
smt_timer_request_delay (self->thread, 100 * 1000, monitor_event);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "stop"  >
            <action name = "stop">

#define self tcb->amq_peering

        {
self->enabled = FALSE;
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "bind"  >
            <action name = "bind">

#define self tcb->amq_peering
char *
    routing_key;
icl_longstr_t *
    arguments;

    routing_key = bind_m->routing_key;
    arguments = bind_m->arguments;
        {
int
    ticket = 0;
char
    *queue = NULL;
Bool
    nowait = TRUE;
amq_peer_method_t
    *bind_method;

//  Treat empty arguments as null
if (arguments && arguments->cur_size == 0)
    arguments = NULL;
//  If this is a new binding (routing_key and arguments are unique),
//  create a Queue.Bind method and propagate it to the remote server
//  if connected.
if (s_binding_exists (self->bindings, routing_key, arguments) == NULL) {
    //  Queue is NULL as the only queue used by this connection is the
    //  peering's private queue
    bind_method = amq_peer_method_new_queue_bind (
        ticket, queue, self->exchange, routing_key, nowait, arguments);
    if (self->connected)
        amq_peer_agent_push (self->peer_agent_thread, self->channel_nbr, bind_method);
    //  We hold onto all outgoing bindings so we can replay them
    ipr_looseref_queue (self->bindings, bind_method);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "unbind"  >
            <action name = "unbind">

#define self tcb->amq_peering
char *
    routing_key;
icl_longstr_t *
    arguments;

    routing_key = unbind_m->routing_key;
    arguments = unbind_m->arguments;
        {
int
    ticket = 0;
char
    *queue = NULL;
Bool
    nowait = TRUE;
amq_peer_method_t
    *unbind_method,
    *bind_method;
ipr_looseref_t
    *looseref;

//  Treat empty arguments as null
if (arguments && arguments->cur_size == 0)
    arguments = NULL;
//  If connected, propagate Queue.Unbind to remote server
if (self->connected) {
    unbind_method = amq_peer_method_new_queue_unbind (
        ticket, queue, self->exchange, routing_key, nowait, arguments);
    amq_peer_agent_push (self->peer_agent_thread, self->channel_nbr, unbind_method);
    amq_peer_method_unlink (&unbind_method);
}
//  Search list of bindings for the matching Queue.Bind and remove it
looseref = s_binding_exists (self->bindings, routing_key, arguments);
assert (looseref);
bind_method = (amq_peer_method_t *) (looseref->object);
ipr_looseref_list_remove (looseref);
amq_peer_method_unlink (&bind_method);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "forward"  >
            <action name = "forward">

#define self tcb->amq_peering
char *
    routing_key;
amq_content_basic_t *
    content;
Bool
    mandatory;
Bool
    immediate;

    routing_key = forward_m->routing_key;
    content = forward_m->content;
    mandatory = forward_m->mandatory;
    immediate = forward_m->immediate;
        {
int
    ticket = 0;
amq_peer_method_t
    *method;

if (amq_server_config_debug_peering (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "P: forward  peer exchange=%s routing_key=%s",
        self->exchange, routing_key);

//  Create a Basic.Publish method
method = amq_peer_method_new_basic_publish (
    ticket, self->exchange, routing_key, mandatory, immediate);
method->content = amq_content_basic_link (content);

//  We only hold messages if the connection is currently down
if (self->connected) {
    amq_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
    amq_peer_method_unlink (&method);
}
else
    ipr_looseref_queue (self->messages, method);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "peer connection start"  >
            <action name = "peer connection start">

#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_connection_start_m->method;
        {
asl_field_list_t
    *fields;                        //  Decoded responses
icl_shortstr_t
    peer_identifier;                //  Unique id of peer

fields = asl_field_list_new (method->payload.connection_start.server_properties);
assert (fields);
asl_field_list_cpy (fields, peer_identifier, "identifier");
asl_field_list_destroy (&fields);

if (amq_server_config_debug_peering (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "P: connected peer=%s self=%s",
        peer_identifier, amq_broker->identifier);

//  If peer and us have same identifier, jump overboard
if (streq (amq_broker->identifier, peer_identifier)) {
    icl_system_panic ("amq_peering", "E: attempted to peer to self - aborting");
    smt_shut_down ();
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "peer connection open ok"  >
            <action name = "peer connection open ok">

#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_connection_open_ok_m->method;
        {
self->channel_nbr = 1;              //  Single channel per connection
amq_peer_agent_channel_open (self->peer_agent_thread, self->channel_nbr);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "peer connection close"  >
            <action name = "peer connection close">

#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_connection_close_m->method;
        {
//  If the connection failed due to a hard error, complain loudly and
//  shut down the broker.  We really don't want people using servers
//  with badly defined peerings.
if (ASL_HARD_ERROR (method->payload.connection_close.reply_code)) {
    smt_log_print (amq_broker->alert_log,
        "E: hard error on peering - please correct and restart server");
    icl_system_panic ("amq_peering", "E: hard error on peering");
    smt_shut_down ();
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "peer channel open ok"  >
            <action name = "peer channel open ok">

#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_channel_open_ok_m->method;
        {
s_initialise_peering (self);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "peer basic deliver"  >
            <action name = "peer basic deliver">

#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_basic_deliver_m->method;
        {
if (self->content_fn)
    (self->content_fn) (self->content_caller, self, method);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "peer basic return"  >
            <action name = "peer basic return">

#define self tcb->amq_peering
amq_peer_method_t *
    method;

    method = peer_basic_return_m->method;
        {
if (self->return_fn)
    (self->return_fn) (self->return_caller, self, method);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <event name = "monitor"  >
            <action name = "monitor">
            
#define self tcb->amq_peering

        {
//  Terminate the peering if the application asked for it, or the
//  peer agent thread was closed from the network side.
if (self->peer_agent_thread && (!self->enabled || self->peer_agent_thread->zombie))
    s_terminate_peering (self);
else
//  Connect the peering if we're not already connected but the app
//  has for the peering to become active.
if (!self->peer_agent_thread && self->enabled)
    self->peer_agent_thread = amq_peer_agent_connection_thread_new (
        self,                       //  Callback for incoming methods
        self->host,
        self->virtual_host,
        self->auth_data,
        "Peering connection",       //  Instance name
        self->trace,
        amq_server_config_setup_timeout (amq_server_config),
        amq_server_config_debug_peering (amq_server_config));

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

#define self tcb->amq_peering
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_peer_method_t
    *method;                        //  Queue.Bind method

s_terminate_peering (self);
icl_longstr_destroy (&self->auth_data);

while ((method = (amq_peer_method_t *) ipr_looseref_pop (self->bindings)))
    amq_peer_method_unlink (&method);
ipr_looseref_list_destroy (&self->bindings);

while ((method = (amq_peer_method_t *) ipr_looseref_pop (self->messages)))
    amq_peer_method_unlink (&method);
ipr_looseref_list_destroy (&self->messages);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_peering
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_peering object");
    amq_peering_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_peering_free (self);
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
        <method name = "bind" />
        <method name = "unbind" />
        <method name = "forward" />
        <method name = "peer connection start" />
        <method name = "peer connection open ok" />
        <method name = "peer connection close" />
        <method name = "peer channel open ok" />
        <method name = "peer basic deliver" />
        <method name = "peer basic return" />
        <event name = "monitor" />
    </state>
</thread>

<private name = "types">
static void s_initialise_peering (amq_peering_t *self);
static void s_terminate_peering  (amq_peering_t *self);
static ipr_looseref_t *s_binding_exists (ipr_looseref_list_t *bindings,
    char *routing_key, icl_longstr_t *arguments);
</private>

<private name = "functions">
static void
s_initialise_peering (amq_peering_t *self)
{
    int
        ticket = 0;
    char
        *queue = NULL,
        *consumer_tag = NULL;
    Bool
        passive = FALSE,
        durable = FALSE,
        exclusive = TRUE,
        auto_delete = TRUE,
        nowait = TRUE,
        no_local = FALSE,
        no_ack = FALSE;
    icl_longstr_t
        *arguments = NULL;
    ipr_looseref_t
        *looseref;                      //  Binding method
    amq_peer_method_t
        *method;                        //  Method to send to peer server
    //
    if (!self->connected) {
        self->connected = TRUE;
        self->offlined = FALSE;
        smt_log_print (amq_broker->alert_log,
            "I: exchange %s now peered to %s", self->exchange, self->host);

        //  Create private queue on peer and consume off queue
        amq_peer_agent_queue_declare (
            self->peer_agent_thread, self->channel_nbr,
            ticket, queue, passive, durable, exclusive, auto_delete, nowait, arguments);

        amq_peer_agent_basic_consume (
            self->peer_agent_thread, self->channel_nbr,
            ticket, queue, consumer_tag, no_local, no_ack, exclusive, nowait, NULL);

        //  Declare remote exchange on peer
        amq_peer_agent_exchange_declare (
            self->peer_agent_thread, self->channel_nbr,
            ticket, self->exchange, self->exchange_type, FALSE, FALSE,
            FALSE, FALSE, nowait, NULL);

        //  Replicate all bindings to remote peer
        looseref = ipr_looseref_list_first (self->bindings);
        while (looseref) {
            method = (amq_peer_method_t *) (looseref->object);
            amq_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
            looseref = ipr_looseref_list_next (&looseref);
        }
        //  Forward all pending messages to remote peer
        while ((method = (amq_peer_method_t *) ipr_looseref_pop (self->messages))) {
            amq_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
            amq_peer_method_unlink (&method);
        }
        if (self->status_fn)
            (self->status_fn) (self->status_caller, self, TRUE);
    }
}

static void
s_terminate_peering (amq_peering_t *self)
{
    amq_broker_t
        *broker_ref;

    //  Stop peer agent thread if it's still alive
    if (self->peer_agent_thread) {
        if (!self->peer_agent_thread->zombie)
            amq_peer_agent_connection_close (self->peer_agent_thread);
        smt_thread_unlink (&self->peer_agent_thread);
    }
    if (self->connected) {
        self->connected = FALSE;
        self->offlined  = TRUE;

        if (self->status_fn)
            (self->status_fn) (self->status_caller, self, FALSE);

        //  Use broker with caution because it can be destroyed now
        broker_ref = amq_broker_link (amq_broker);
        if (broker_ref) {
            smt_log_print (broker_ref->alert_log,
                "I: exchange %s unpeered from %s", self->exchange, self->host);
            amq_broker_unlink (&broker_ref);
        }
    }
}

//  Used by peering_bind and peering_unbind to determine if binding is unique.
//  Searches provided looseref list for a queue.bind method matching the
//  provided routing_key and arguments.  Returns looseref if found, NULL if
//  no match found.
static ipr_looseref_t *
s_binding_exists (
    ipr_looseref_list_t *bindings,
    char *routing_key,
    icl_longstr_t *arguments)
{
    ipr_looseref_t
        *looseref;
    amq_peer_method_t
        *method;

    looseref = ipr_looseref_list_first (bindings);
    while (looseref) {
        method = (amq_peer_method_t *) (looseref->object);
        assert (method->class_id  == AMQ_PEER_QUEUE);
        assert (method->method_id == AMQ_PEER_QUEUE_BIND);
        //  If routing_key and arguments are equal, we have a match
        if (streq (method->payload.queue_bind.routing_key, routing_key) &&
            icl_longstr_eq (method->payload.queue_bind.arguments, arguments))
            break;
        looseref = ipr_looseref_list_next (&looseref);
    }
    return looseref;
}
</private>

</agent>
