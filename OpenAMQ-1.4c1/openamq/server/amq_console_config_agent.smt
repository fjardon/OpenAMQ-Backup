<?xml?>
<!---------------------------------------------------------------------------
    amq_console_config_agent.smt - amq_console_config component

    Generated from amq_console_config.icl by smt_object_gen using GSL/4.

    
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
    name = "amq_console_config_agent"
    script = "smt_gen.gsl"
    animate = "0"
    >
<import class = "amq_console_config" />

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
        amq_console_config_t
            *amq_console_config;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_console_config_t *">The iCL object</argument>
        tcb->amq_console_config = self;
    </handler>
        
    <state name = "main">

        <method name = "destroy"  nextstate = ""  >
            <action name = "destroy">

#define self tcb->amq_console_config
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_console_config
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_console_config object");
    amq_console_config_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_console_config_free (self);
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

#define self tcb->amq_console_config
amq_content_basic_t *
    request;

    request = inspect_m->request;
        {
asl_field_list_t
    *fields;                        //  Properties of object
icl_shortstr_t
    field_value;

fields = asl_field_list_new (NULL);
icl_shortstr_cpy (field_value, amq_server_config_filename (amq_server_config));
asl_field_new_string (fields, "name", field_value);
icl_shortstr_cpy (field_value, amq_server_config_port (amq_server_config));
asl_field_new_string (fields, "port", field_value);
icl_shortstr_cpy (field_value, amq_server_config_listen (amq_server_config));
asl_field_new_string (fields, "listen", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_queue_timeout (amq_server_config));
asl_field_new_string (fields, "queue_timeout", field_value);
icl_shortstr_cpy (field_value, amq_server_config_vhost (amq_server_config));
asl_field_new_string (fields, "vhost", field_value);
icl_shortstr_cpy (field_value, amq_server_config_user (amq_server_config));
asl_field_new_string (fields, "user", field_value);
icl_shortstr_cpy (field_value, amq_server_config_group (amq_server_config));
asl_field_new_string (fields, "group", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_monitor (amq_server_config));
asl_field_new_string (fields, "monitor", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_dump_state (amq_server_config));
asl_field_new_string (fields, "dump_state", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_record_stats (amq_server_config));
asl_field_new_string (fields, "record_stats", field_value);
icl_shortstr_cpy (field_value, amq_server_config_log_path (amq_server_config));
asl_field_new_string (fields, "log_path", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_keep_logs (amq_server_config));
asl_field_new_string (fields, "keep_logs", field_value);
icl_shortstr_cpy (field_value, amq_server_config_archive_cmd (amq_server_config));
asl_field_new_string (fields, "archive_cmd", field_value);
icl_shortstr_cpy (field_value, amq_server_config_alert_log (amq_server_config));
asl_field_new_string (fields, "alert_log", field_value);
icl_shortstr_cpy (field_value, amq_server_config_daily_log (amq_server_config));
asl_field_new_string (fields, "daily_log", field_value);
icl_shortstr_cpy (field_value, amq_server_config_debug_log (amq_server_config));
asl_field_new_string (fields, "debug_log", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_route (amq_server_config));
asl_field_new_string (fields, "debug_route", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_queue (amq_server_config));
asl_field_new_string (fields, "debug_queue", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_peering (amq_server_config));
asl_field_new_string (fields, "debug_peering", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_console (amq_server_config));
asl_field_new_string (fields, "debug_console", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_trace (amq_server_config));
asl_field_new_string (fields, "trace", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_syslog (amq_server_config));
asl_field_new_string (fields, "syslog", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_coremark_cycles (amq_server_config));
asl_field_new_string (fields, "coremark_cycles", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_heartbeat (amq_server_config));
asl_field_new_string (fields, "heartbeat", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_setup_timeout (amq_server_config));
asl_field_new_string (fields, "setup_timeout", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_close_timeout (amq_server_config));
asl_field_new_string (fields, "close_timeout", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_accept_retry_timeout (amq_server_config));
asl_field_new_string (fields, "accept_retry_timeout", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_polling_threads (amq_server_config));
asl_field_new_string (fields, "polling_threads", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_working_threads (amq_server_config));
asl_field_new_string (fields, "working_threads", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_tcp_nodelay (amq_server_config));
asl_field_new_string (fields, "tcp_nodelay", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_tcp_rcvbuf (amq_server_config));
asl_field_new_string (fields, "tcp_rcvbuf", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_tcp_sndbuf (amq_server_config));
asl_field_new_string (fields, "tcp_sndbuf", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_frame_max (amq_server_config));
asl_field_new_string (fields, "frame_max", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_direct (amq_server_config));
asl_field_new_string (fields, "direct", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_private_credit (amq_server_config));
asl_field_new_string (fields, "private_credit", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_shared_credit (amq_server_config));
asl_field_new_string (fields, "shared_credit", field_value);
icl_shortstr_cpy (field_value, amq_server_config_backup (amq_server_config));
asl_field_new_string (fields, "backup", field_value);
icl_shortstr_cpy (field_value, amq_server_config_primary (amq_server_config));
asl_field_new_string (fields, "primary", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_failover_timeout (amq_server_config));
asl_field_new_string (fields, "failover_timeout", field_value);
icl_shortstr_cpy (field_value, amq_server_config_attach (amq_server_config));
asl_field_new_string (fields, "attach", field_value);
icl_shortstr_cpy (field_value, amq_server_config_attach_vhost (amq_server_config));
asl_field_new_string (fields, "attach_vhost", field_value);
icl_shortstr_cpy (field_value, amq_server_config_attach_login (amq_server_config));
asl_field_new_string (fields, "attach_login", field_value);
icl_shortstr_cpy (field_value, amq_server_config_attach_all (amq_server_config));
asl_field_new_string (fields, "attach_all", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_batching (amq_server_config));
asl_field_new_string (fields, "batching", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_direct_heartbeat (amq_server_config));
asl_field_new_string (fields, "direct_heartbeat", field_value);
icl_shortstr_fmt (field_value, "%d", amq_server_config_no_ack (amq_server_config));
asl_field_new_string (fields, "no_ack", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_auto_crash (amq_server_config));
asl_field_new_string (fields, "auto_crash", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_auto_block (amq_server_config));
asl_field_new_string (fields, "auto_block", field_value);
icl_shortstr_fmt (field_value, "%ld", amq_server_config_kernel_limit (amq_server_config));
asl_field_new_string (fields, "kernel_limit", field_value);
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

#define self tcb->amq_console_config
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
char
    *notice_text = NULL;            //  Notice to UI, if any

field = asl_field_list_search (fields, "port");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_port (amq_server_config, field_value);
      notice_text = "To activate the new port setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "listen");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_listen (amq_server_config, field_value);
      notice_text = "To activate the new listen setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "queue_timeout");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_queue_timeout (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "vhost");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_vhost (amq_server_config, field_value);
      notice_text = "To activate the new vhost setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "user");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_user (amq_server_config, field_value);
      notice_text = "To activate the new user setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "group");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_group (amq_server_config, field_value);
      notice_text = "To activate the new group setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "monitor");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_monitor (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "dump_state");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_dump_state (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "record_stats");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_record_stats (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "log_path");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_log_path (amq_server_config, field_value);
      notice_text = "To activate the new log_path setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "keep_logs");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_keep_logs (amq_server_config, atoi (field_value));
      notice_text = "To activate the new keep_logs setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "archive_cmd");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_archive_cmd (amq_server_config, field_value);
      notice_text = "To activate the new archive_cmd setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "alert_log");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_alert_log (amq_server_config, field_value);
      notice_text = "To activate the new alert_log setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "daily_log");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_daily_log (amq_server_config, field_value);
      notice_text = "To activate the new daily_log setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "debug_log");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_debug_log (amq_server_config, field_value);
      notice_text = "To activate the new debug_log setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "debug_route");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_debug_route (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "debug_queue");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_debug_queue (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "debug_peering");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_debug_peering (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "debug_console");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_debug_console (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "trace");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_trace (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "syslog");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_syslog (amq_server_config, atol (field_value));
      notice_text = "To activate the new syslog setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "coremark_cycles");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_coremark_cycles (amq_server_config, atol (field_value));
      notice_text = "To activate the new coremark_cycles setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "heartbeat");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_heartbeat (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "setup_timeout");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_setup_timeout (amq_server_config, atol (field_value));
      notice_text = "To activate the new setup_timeout setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "close_timeout");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_close_timeout (amq_server_config, atol (field_value));
      notice_text = "To activate the new close_timeout setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "accept_retry_timeout");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_accept_retry_timeout (amq_server_config, atol (field_value));
      notice_text = "To activate the new accept_retry_timeout setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "polling_threads");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_polling_threads (amq_server_config, atol (field_value));
      notice_text = "To activate the new polling_threads setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "working_threads");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_working_threads (amq_server_config, atol (field_value));
      notice_text = "To activate the new working_threads setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "tcp_nodelay");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_tcp_nodelay (amq_server_config, atoi (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "tcp_rcvbuf");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_tcp_rcvbuf (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "tcp_sndbuf");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_tcp_sndbuf (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "frame_max");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_frame_max (amq_server_config, atol (field_value));
      notice_text = "To activate the new frame_max setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "direct");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_direct (amq_server_config, atol (field_value));
      notice_text = "To activate the new direct setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "private_credit");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_private_credit (amq_server_config, atol (field_value));
      notice_text = "To activate the new private_credit setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "shared_credit");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_shared_credit (amq_server_config, atol (field_value));
      notice_text = "To activate the new shared_credit setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "backup");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_backup (amq_server_config, field_value);
      notice_text = "To activate the new backup setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "primary");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_primary (amq_server_config, field_value);
      notice_text = "To activate the new primary setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "failover_timeout");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_failover_timeout (amq_server_config, atol (field_value));
      notice_text = "To activate the new failover_timeout setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "attach");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_attach (amq_server_config, field_value);
      notice_text = "To activate the new attach setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "attach_vhost");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_attach_vhost (amq_server_config, field_value);
      notice_text = "To activate the new attach_vhost setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "attach_login");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_attach_login (amq_server_config, field_value);
      notice_text = "To activate the new attach_login setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "attach_all");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_attach_all (amq_server_config, field_value);
      notice_text = "To activate the new attach_all setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "batching");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_batching (amq_server_config, atol (field_value));
      notice_text = "To activate the new batching setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "direct_heartbeat");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_direct_heartbeat (amq_server_config, atol (field_value));
      notice_text = "To activate the new direct_heartbeat setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "no_ack");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_no_ack (amq_server_config, atoi (field_value));
      notice_text = "To activate the new no_ack setting, restart the broker";
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "auto_crash");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_auto_crash (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "auto_block");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_auto_block (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
}
field = asl_field_list_search (fields, "kernel_limit");
if (field) {
    icl_shortstr_cpy (field_value, asl_field_string (field));
              amq_server_config_set_kernel_limit (amq_server_config, atol (field_value));
    asl_field_unlink (&field);
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

#define self tcb->amq_console_config
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
if (streq (method_name, "commit")) {
    amq_server_config_commit (amq_server_config, NULL);
}
if (streq (method_name, "rollback")) {
    amq_server_config_rollback (amq_server_config);
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

#define self tcb->amq_console_config
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
amq_console_cancel (self->console, self->object_id);
amq_console_unlink (&self->console);
        }
#undef self
            </action>
            <action name = "free">

#define self tcb->amq_console_config
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on amq_console_config object");
    amq_console_config_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_console_config_free (self);
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
