<?xml?>
<!---------------------------------------------------------------------------
    amq_broker_agent.smt - amq_broker component

    Generated from amq_broker.icl by smt_object_gen using GSL/4.

    
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
    name = "amq_broker_agent"
    script = "smt_gen.gsl"
    animate = "0"
    >
<import class = "amq_broker" />

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

<method name = "delete queue">
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

<method name = "start">
</method>

<method name = "shutdown">
</method>

<thread name = "class">
    <context>
        amq_broker_t
            *amq_broker;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_broker_t *">The iCL object</argument>
        tcb->amq_broker = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_broker
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
smt_signal_deregister (SIGINT);
smt_signal_deregister (SIGTERM);
ipr_meter_destroy (&self->imeter);
ipr_meter_destroy (&self->ometer);
amq_server_connection_table_destroy (&self->connections);
amq_server_connection_list_destroy (&self->connection_list);
smt_thread_unlink (&self->agent_thread);
amq_server_agent_term ();
if (self->stats)
    fclose (self->stats);

amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

{
amq_exchange_t
    *exchange;

amq_failover_destroy (&self->failover);
amq_console_config_destroy (&amq_console_config);
amq_connection_by_broker_destroy (&self->mgt_connection_list);

amq_exchange_unlink (&self->default_exchange);
amq_exchange_table_destroy (&self->exchange_table);
exchange = amq_exchange_list_pop (self->exchange_list);
while (exchange) {
    amq_exchange_destroy (&exchange);
    exchange = amq_exchange_list_pop (self->exchange_list);
}
amq_exchange_list_destroy (&self->exchange_list);
amq_queue_table_destroy (&self->queue_table);
amq_queue_list_destroy (&self->queue_list);
ipr_symbol_table_destroy (&self->shared_queues);
}
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_broker
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_broker object");
    amq_broker_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_broker_free (self);
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

#define self tcb->amq_broker
amq_queue_t *
    queue;

    queue = unbind_queue_m->queue;
        {
amq_server_connection_t
    *connection;

//  Go through all connections
connection = amq_server_connection_list_first (self->connection_list);
while (connection) {
    amq_server_connection_unbind_queue (connection, queue);
    connection = amq_server_connection_list_next (&connection);
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "delete queue"  >
            <action name = "delete queue">

#define self tcb->amq_broker
amq_queue_t *
    queue;

    queue = delete_queue_m->queue;
        {
amq_exchange_t
    *exchange;

//  Go through all exchanges & bindings, remove link to queue
exchange = amq_exchange_list_first (self->exchange_list);
while (exchange) {
    amq_exchange_broker_unbind_queue (exchange, queue);
    exchange = amq_exchange_list_next (&exchange);
}
//  Remove the queue from queue list and queue table
amq_queue_list_remove (queue);
amq_queue_table_remove (queue);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "inspect"  >
            <action name = "inspect">

#define self tcb->amq_broker
amq_content_basic_t *
    request;

    request = inspect_m->request;
        {
asl_field_list_t
    *fields;                        //  Properties of object
icl_shortstr_t
    field_value;
            amq_exchange_t
            *exchange;
            amq_queue_t
            *queue;
            amq_connection_t
            *connection;

fields = asl_field_list_new (NULL);
icl_shortstr_fmt (field_value, "OpenAMQ %s", VERSION);
asl_field_new_string (fields, "name", field_value);
ipr_time_iso8601 (self->started,
        ipr_date_format_minute, 0, FALSE, field_value);
asl_field_new_string (fields, "started", field_value);
icl_shortstr_fmt (field_value, "%d", self->locked);
asl_field_new_string (fields, "locked", field_value);
icl_shortstr_fmt (field_value, "%dK", (int) (icl_mem_used () / 1024));
asl_field_new_string (fields, "datamem", field_value);
icl_shortstr_fmt (field_value, "%dK", (int) (ipr_bucket_used () / 1024));
asl_field_new_string (fields, "bucketmem", field_value);
icl_shortstr_fmt (field_value, "%d", amq_content_basic_count ());
asl_field_new_string (fields, "messages", field_value);
icl_shortstr_fmt (field_value, "%d", amq_consumer_count ());
asl_field_new_string (fields, "consumers", field_value);
icl_shortstr_fmt (field_value, "%d", amq_binding_count ());
asl_field_new_string (fields, "bindings", field_value);
strclr (field_value);
            exchange = amq_exchange_list_first (self->exchange_list);
        icl_shortstr_fmt (field_value, "%d", exchange->object_id);
while (*field_value) {
    asl_field_new_string (fields, "exchange", field_value);
    strclr (field_value);
            exchange = amq_exchange_list_next (&exchange);
        if (exchange)
            icl_shortstr_fmt (field_value, "%d", exchange->object_id);
}
strclr (field_value);
            queue = amq_queue_list_first (self->queue_list);
        while (queue && !self->verbose && queue->exclusive)
            queue = amq_queue_list_next (&queue);
        if (queue)
            icl_shortstr_fmt (field_value, "%d", queue->object_id);
while (*field_value) {
    asl_field_new_string (fields, "queue", field_value);
    strclr (field_value);
            queue = amq_queue_list_next (&queue);
        while (queue && !self->verbose && queue->exclusive)
            queue = amq_queue_list_next (&queue);
        if (queue)
            icl_shortstr_fmt (field_value, "%d", queue->object_id);
}
strclr (field_value);
            connection = amq_connection_by_broker_first (self->mgt_connection_list);
        if (connection)
            icl_shortstr_fmt (field_value, "%d", connection->object_id);
while (*field_value) {
    asl_field_new_string (fields, "connection", field_value);
    strclr (field_value);
            connection = amq_connection_by_broker_next (&connection);
        if (connection)
            icl_shortstr_fmt (field_value, "%d", connection->object_id);
}
strclr (field_value);
            icl_shortstr_fmt (field_value, "%d", amq_console_config->object_id);
asl_field_new_string (fields, "config", field_value);
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

#define self tcb->amq_broker
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

#define self tcb->amq_broker
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
if (streq (method_name, "shutdown")) {
                smt_log_print (amq_broker->alert_log,
            "W: operator requested shutdown - closing all connections");
        amq_broker_shutdown (self);
}
if (streq (method_name, "lock")) {
    asl_field_t
        *field;
    Bool
        setting = FALSE;
    field = asl_field_list_search (fields, "setting");
    if (field) {
        setting = atoi (asl_field_string (field));
        asl_field_unlink (&field);
    }
    self->locked = setting;
}
if (streq (method_name, "verbose")) {
    asl_field_t
        *field;
    Bool
        setting = FALSE;
    field = asl_field_list_search (fields, "setting");
    if (field) {
        setting = atoi (asl_field_string (field));
        asl_field_unlink (&field);
    }
    self->verbose = setting;
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


        <method name = "start"  >
            <action name = "start">

#define self tcb->amq_broker

        {
//  We will run the broker monitor once per second, unconditionally
smt_timer_request_delay (self->thread, 1000 * 1000, monitor_event);
//  Register to receive interrupt event on SIGINT, SIGTERM
smt_signal_register (SIGINT, thread, interrupt_event);
smt_signal_register (SIGTERM, thread, interrupt_event);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "shutdown"  >
            <action name = "shutdown">

#define self tcb->amq_broker

        {
//  Tell amq_server_agent to close master socket
amq_server_agent_shutdown (self->agent_thread);
//  TODO: Shutdown any peerings or other objects that would malfunction
//  Start graceful shutdown sequence
smt_thread_set_next_event (thread, waiting_for_shutdown_event);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <event name = "waiting for shutdown"  >
            <action name = "shutdown active connections">
            
#define self tcb->amq_broker

        {
//  Spend a maximum of 30 seconds shutting down
s_shutdown_time_spent++;
if (s_shutdown_time_spent > 30)
    smt_thread_set_next_event (thread, finished_with_shutdown_event);
//  For each active connection, tell it's amq_server_agent instance
//  to shut it down.
s_active_connections = 0;
amq_server_connection_table_apply (
    self->connections, s_shutdown_connection, NULL);
if (s_active_connections) {
    if (s_shutdown_time_spent == 1)
        //  Only print message once
        smt_log_print (self->alert_log,
            "W: closing %d connection%s, please wait up to 30 seconds",
            s_active_connections,
            s_active_connections > 1? "s": "");
    //  Loop and try again in one second
    smt_timer_request_delay (thread, 1000000,
        waiting_for_shutdown_event);
}
else
    //  Finished, proceed with broker shutdown
    smt_thread_set_next_event (thread, finished_with_shutdown_event);
        }
        
#undef self
            </action>
        </event>
        <event name = "finished with shutdown"  >
            <action name = "shutdown broker">
            
#define self tcb->amq_broker

        {
smt_shut_down ();
        }
        
#undef self
            </action>
        </event>
        <event name = "interrupt"  >
            <action name = "report server interrupted">
            
#define self tcb->amq_broker

        {
s_interrupted++;
if (s_interrupted == 1) {
    smt_log_print (self->alert_log,
        "W: caught signal, shutting down");
    //  Start graceful shutdown
    amq_broker_shutdown (self);
}
else
if (s_interrupted > 1) {
    smt_log_print (self->alert_log,
        "W: caught another signal, shutting down immediately");
    smt_shut_down ();
}
        }
        
#undef self
            </action>
        </event>
        <event name = "monitor"  >
            <action name = "monitor">
            
#define self tcb->amq_broker

        {
//  Cycle log files at midnight
if (ipr_time_now () > 235900) {
    if (!self->cycled) {
        self->cycled = TRUE;        //  Don't cycle again today
        smt_log_cycle (self->debug_log);
        smt_log_cycle (self->daily_log);
        smt_log_cycle (self->alert_log);
    }
}
else
    self->cycled = FALSE;

if (self->monitor_timer) {
    self->monitor_timer--;
    if (self->monitor_timer == 0) {
        Bool
            new_stats = FALSE;      //  Do we have new stats to print?

        self->monitor_timer = amq_server_config_monitor (amq_server_config);
        if (ipr_meter_mark (self->imeter, amq_server_config_monitor (amq_server_config))) {
            smt_log_print (self->debug_log,
                "I: incoming rate=%d mean=%d peak=%d",
                self->imeter->current,
                self->imeter->average,
                self->imeter->maximum);
            new_stats = TRUE;
        }
        if (ipr_meter_mark (self->ometer, amq_server_config_monitor (amq_server_config))) {
            smt_log_print (self->debug_log,
                "I: outgoing rate=%d mean=%d peak=%d iomean=%d",
                self->ometer->current,
                self->ometer->average,
                self->ometer->maximum,
                self->ometer->average + self->imeter->average);
            new_stats = TRUE;
        }
        //  Record statistics if necessary
        if (self->stats && new_stats) {
            fprintf (self->stats, "%d\t%zu\t%d\t%d\t%d\t%d\n",
                amq_server_connection_count (),
                ipr_bucket_used () / 1024,
                self->imeter->current, self->ometer->current,
                self->imeter->average, self->ometer->average);
        }
    }
}
smt_timer_request_delay (self->thread, 1000 * 1000, monitor_event);

if (self->dump_state_timer) {
    self->dump_state_timer--;
    if (self->dump_state_timer == 0) {
        self->dump_state_timer = amq_server_config_dump_state (amq_server_config);
        smt_log_print (amq_broker->debug_log,
            "I: cnn=%d msg=%d mem=%uK/%uK exc=%d que=%d csm=%d bnd=%d adx=%d idx=%d map=%d",
            amq_server_connection_count (),
            amq_content_basic_count (),
            ipr_bucket_used () / 1024,
            icl_mem_used () / 1024,
            amq_exchange_count (),
            amq_queue_count (),
            amq_consumer_count (),
            amq_binding_count (),
            amq_index_count (),
            ipr_index_count (),
            ipr_bits_count ());

        smt_log_print (amq_broker->debug_log,
            "I: qcn=%d cnq=%d dsk=%d dfd=%d din=%d dot=%d dhi=%d",
            amq_queue_connection_count (),
            amq_connection_queue_count (),
            amq_broker->direct_sunk,
            amq_broker->direct_fed,
            amq_broker->direct_in,
            amq_broker->direct_out,
            amq_broker->direct_high);
    }
}
if (self->auto_crash_timer) {
    if (--self->auto_crash_timer == 0) {
        smt_log_print (amq_broker->alert_log,
            "W: ************************  AUTO-CRASH  ************************");
        smt_log_print (amq_broker->alert_log,
            "W: server is now emulating a system crash, and will exit brutally.");
        exit (EXIT_SUCCESS);
    }
}
if (self->auto_block_timer) {
    if (--self->auto_block_timer == 0) {
        smt_log_print (amq_broker->alert_log,
            "W: ************************  AUTO-BLOCK  ************************");
        smt_log_print (amq_broker->alert_log,
            "W: server is now emulating a blockage, and will freeze for 5 minutes.");
        sleep (300);
    }
}
        }
        
#undef self
            </action>
        </event>
        <event name = "shutdown" nextstate = "shutting down" />
    </state>
    
    <state name = "shutting down">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_broker
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
smt_signal_deregister (SIGINT);
smt_signal_deregister (SIGTERM);
ipr_meter_destroy (&self->imeter);
ipr_meter_destroy (&self->ometer);
amq_server_connection_table_destroy (&self->connections);
amq_server_connection_list_destroy (&self->connection_list);
smt_thread_unlink (&self->agent_thread);
amq_server_agent_term ();
if (self->stats)
    fclose (self->stats);

amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);

{
amq_exchange_t
    *exchange;

amq_failover_destroy (&self->failover);
amq_console_config_destroy (&amq_console_config);
amq_connection_by_broker_destroy (&self->mgt_connection_list);

amq_exchange_unlink (&self->default_exchange);
amq_exchange_table_destroy (&self->exchange_table);
exchange = amq_exchange_list_pop (self->exchange_list);
while (exchange) {
    amq_exchange_destroy (&exchange);
    exchange = amq_exchange_list_pop (self->exchange_list);
}
amq_exchange_list_destroy (&self->exchange_list);
amq_queue_table_destroy (&self->queue_table);
amq_queue_list_destroy (&self->queue_list);
ipr_symbol_table_destroy (&self->shared_queues);
}
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_broker
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_broker object");
    amq_broker_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_broker_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "unbind queue" />
        <method name = "delete queue" />
        <method name = "inspect" />
        <method name = "modify" />
        <method name = "method" />
        <method name = "start" />
        <method name = "shutdown" />
        <event name = "waiting for shutdown" />
        <event name = "finished with shutdown" />
        <event name = "interrupt" />
        <event name = "monitor" />
    </state>
</thread>

<private name = "types">
static void
    s_shutdown_connection (amq_server_connection_t *connection_p, void *argument);
static int
    s_interrupted = 0,                  //  Server interrupted?
    s_shutdown_time_spent = 0;          //  Time spent in graceful shutdown
static dbyte
    s_active_connections = 0;           //  Used during server shutdown
</private>

<private name = "types">
#include "version.h"
</private>

<private name = "functions">
//  Shutdown a single connection
static void
s_shutdown_connection (amq_server_connection_t *connection_p, void *argument)
{
    amq_server_connection_t
        *connection;

    connection = amq_server_connection_link (connection_p);
    if (connection) {
        if (amq_server_agent_shutdown (connection->thread) == 0)
            s_active_connections++;
        amq_server_connection_unlink (&connection);
    }
}
</private>

</agent>
