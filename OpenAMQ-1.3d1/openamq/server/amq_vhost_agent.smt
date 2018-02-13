<?xml?>
<!---------------------------------------------------------------------------
    amq_vhost_agent.smt - amq_vhost component

Defines a virtual host. This is a lock-free asynchronous class.
    Generated from amq_vhost.icl by smt_object_gen using GSL/4.

    
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
    name = "amq_vhost_agent"
    script = "smt_gen.gsl"
    animate = "1"
    >
<import class = "amq_vhost" />

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
</method>

<method name = "unbind queue">
    <argument name = "queue" type = "amq_queue_t *" />
    <possess>

    queue = amq_queue_link (queue);
    
    </possess>
    <release>

    amq_queue_unlink (&queue);
    
    </release>
</method>

<thread name = "class">
    <context>
        amq_vhost_t
            *amq_vhost;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_vhost_t *">The iCL object</argument>
        tcb->amq_vhost = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_vhost
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_exchange_t
    *exchange;

amq_exchange_unlink            (&self->default_exchange);
amq_vhost_config_destroy       (&self->config);
amq_exchange_table_destroy     (&self->exchange_table);
exchange = amq_exchange_by_vhost_pop (self->exchange_list);
while (exchange) {
    amq_exchange_destroy (&exchange);
    exchange = amq_exchange_by_vhost_pop (self->exchange_list);
}
amq_exchange_by_vhost_destroy  (&self->exchange_list);
amq_queue_table_destroy        (&self->queue_table);
amq_queue_by_vhost_destroy     (&self->queue_list);
ipr_symbol_table_destroy       (&self->shared_queues);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_vhost
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_vhost object");
    amq_vhost_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_vhost_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "unbind queue"  >
            <action name = "unbind queue">

#define self tcb->amq_vhost
amq_queue_t *
    queue;

    queue = unbind_queue_m->queue;
        {
amq_exchange_t
    *exchange;

//  Go through all exchanges & bindings, remove link to queue
exchange = amq_exchange_by_vhost_first (self->exchange_list);
while (exchange) {
    amq_exchange_unbind_queue (exchange, queue);
    exchange = amq_exchange_by_vhost_next (&exchange);
}
//  Remove the queue from queue list and queue table
amq_queue_by_vhost_remove (queue);
amq_queue_table_remove (queue);
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

#define self tcb->amq_vhost
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_exchange_t
    *exchange;

amq_exchange_unlink            (&self->default_exchange);
amq_vhost_config_destroy       (&self->config);
amq_exchange_table_destroy     (&self->exchange_table);
exchange = amq_exchange_by_vhost_pop (self->exchange_list);
while (exchange) {
    amq_exchange_destroy (&exchange);
    exchange = amq_exchange_by_vhost_pop (self->exchange_list);
}
amq_exchange_by_vhost_destroy  (&self->exchange_list);
amq_queue_table_destroy        (&self->queue_table);
amq_queue_by_vhost_destroy     (&self->queue_list);
ipr_symbol_table_destroy       (&self->shared_queues);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_vhost
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_vhost object");
    amq_vhost_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_vhost_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "unbind queue" />
    </state>
</thread>

</agent>
