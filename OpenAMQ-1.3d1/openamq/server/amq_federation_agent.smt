<?xml?>
<!---------------------------------------------------------------------------
    amq_federation_agent.smt - amq_federation component

This agent implements a single federation, which is a relationship between
an exchange on this server and the same-named exchange on a parent server.
There are two families of federation, primitives that do one thing and 
compounds which combine the effects of multiple primitives.

The primitives are:

 - Subscriber federation: replicate bindings to the parent server, so that 
   messages are pulled down from it.  The subscriber federation does three
   things: send queue.bind and and queue.unbind commands to the parent 
   server (via a peering), and process messages delivered from the parent.
   Typically used on topic or header exchanges.
   
 - Publisher federation (aka 'forward all'): replicate published messages to
   the parent server.  The publisher federation does two things: forward all
   basic.publish commands to the parent server, and process undeliverable
   messages returned by the parent server. Typically used for topic or header 
   exchanges.
   
 - Locator federation (aka 'forward else'): replicate published messages to
   the parent server if they could not be delivered locally.  The locator
   federation does two things: forward basic.publish messages to the parent
   server if they could not be delivered locally, and process undeliverable
   messages returned by the parent server.  Typically used for direct 
   exchanges.
   
The compound federations are:

 - Fanout federation: combines subscriber and publisher.  Fanout federation
   does this: send queue.bind and unbind to parent server; when a local app
   publishes message, forward that to parent (and do not publish to local
   exchange); process messages delivered from the parent; process returns
   from the parent.  The result is that messages published to any server will
   be pushed up to the highest parent, and then propagated back down through
   all servers and out to applications.  This is the default federation for 
   topic and header exchanges.  The current implementation creates extra
   latency. 
 
 - Service federation: combines subscriber and locator.  Service federation
   does this: send queue.bind and unbind to parent server; when local app
   publishes message, try to deliver locally and if that fails, forward to
   parent server; process messages delivered from parent; process returns
   from the parent.  The result is that requests will go to the nearest
   consumer, and responses will come back down from parents.  This is the
   default federation for direct exchanges.
    Generated from amq_federation.icl by smt_object_gen using GSL/4.

    
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
    name = "amq_federation_agent"
    script = "smt_gen.gsl"
    animate = "1"
    >
<import class = "amq_federation" />

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
</method>

<method name = "binding created">
    <argument name = "routing_key" type = "char *" />
    <argument name = "arguments" type = "icl_longstr_t *" />
    <argument name = "exclusive" type = "Bool" />
    <possess>

    routing_key = icl_mem_strdup (routing_key);
    arguments = icl_longstr_dup (arguments);
    
    </possess>
    <release>

    icl_mem_free (routing_key);
    icl_longstr_destroy (&arguments);
    
    </release>
</method>

<method name = "binding destroyed">
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

<method name = "message published">
    <argument name = "content" type = "amq_content_basic_t *" />
    <argument name = "mandatory" type = "Bool" />
    <argument name = "immediate" type = "Bool" />
    <possess>

    content = amq_content_basic_link (content);
    
    </possess>
    <release>

    amq_content_basic_unlink (&content);
    
    </release>
</method>

<thread name = "class">
    <context>
        amq_federation_t
            *amq_federation;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_federation_t *">The iCL object</argument>
        tcb->amq_federation = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "free">

#define self tcb->amq_federation
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_federation object");
    amq_federation_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_federation_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "binding created"  >
            <action name = "binding created">

#define self tcb->amq_federation
char *
    routing_key;
icl_longstr_t *
    arguments;
Bool
    exclusive;

    routing_key = binding_created_m->routing_key;
    arguments = binding_created_m->arguments;
    exclusive = binding_created_m->exclusive;
        {
if ((self->type == AMQ_FEDERATION_SUBSCRIBER || self->type == AMQ_FEDERATION_FANOUT)
||  (self->type == AMQ_FEDERATION_SERVICE && exclusive)) {
    if (amq_server_config_debug_peering (amq_server_config))
        smt_log_print (amq_broker->debug_log,
            "P: bind     exchange=%s host=%s routing_key=%s", 
            self->exchange->name, self->peering->host, routing_key);

    amq_peering_bind (self->peering, routing_key, arguments);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "binding destroyed"  >
            <action name = "binding destroyed">

#define self tcb->amq_federation
char *
    routing_key;
icl_longstr_t *
    arguments;

    routing_key = binding_destroyed_m->routing_key;
    arguments = binding_destroyed_m->arguments;
        {
if (self->type == AMQ_FEDERATION_SUBSCRIBER 
||  self->type == AMQ_FEDERATION_FANOUT
||  self->type == AMQ_FEDERATION_SERVICE) {
    if (amq_server_config_debug_peering (amq_server_config))
        smt_log_print (amq_broker->debug_log,
            "P: unbind   exchange=%s host=%s routing_key=%s", 
            self->exchange->name, self->peering->host, routing_key);

    amq_peering_unbind (self->peering, routing_key, arguments);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "message published"  >
            <action name = "message published">

#define self tcb->amq_federation
amq_content_basic_t *
    content;
Bool
    mandatory;
Bool
    immediate;

    content = message_published_m->content;
    mandatory = message_published_m->mandatory;
    immediate = message_published_m->immediate;
        {
amq_peering_forward (
    self->peering,
    content->routing_key,
    content,
    mandatory,
    immediate);
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
            <action name = "free">

#define self tcb->amq_federation
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_federation object");
    amq_federation_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_federation_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "binding created" />
        <method name = "binding destroyed" />
        <method name = "message published" />
    </state>
</thread>

</agent>
