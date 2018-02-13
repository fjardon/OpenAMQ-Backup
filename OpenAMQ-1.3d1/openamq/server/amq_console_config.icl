<?xml?>
<class
    name    = "amq_console_config"
    comment = "Wrapper for configuration under Console"
    version = "1.0"
    script  = "smt_object_gen"
    target  = "smt"
    >

<inherit class = "smt_object" />
<inherit class = "amq_console_object" />

<!-- Console definitions for this object -->
<data name = "cml">
    <class name = "config" parent = "broker" label = "Configuration">
        <field name = "name" label = "Configuration name">
          <get>icl_shortstr_cpy (field_value, amq_server_config->filename);</get>
        </field>
        <field name = "port" type = "string" label = "Server port for clients">
          <get>icl_shortstr_cpy (field_value, amq_server_config_port (amq_server_config));</get>
          <put>
          amq_server_config_set_port (amq_server_config, field_value);
          notice_text = "To activate the new port setting, restart the broker";
          </put>
        </field>
        <field name = "listen" type = "string" label = "Address (local network interface) to listen on">
          <get>icl_shortstr_cpy (field_value, amq_server_config_listen (amq_server_config));</get>
          <put>
          amq_server_config_set_listen (amq_server_config, field_value);
          notice_text = "To activate the new listen setting, restart the broker";
          </put>
        </field>
        <field name = "queue_timeout" type = "int" label = "Timeout for auto-deleted queues">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_queue_timeout (amq_server_config));</get>
          <put>
          amq_server_config_set_queue_timeout (amq_server_config, atol (field_value));
          </put>
        </field>
        <field name = "vhost" type = "string" label = "Server vhost identifier">
          <get>icl_shortstr_cpy (field_value, amq_server_config_vhost (amq_server_config));</get>
          <put>
          amq_server_config_set_vhost (amq_server_config, field_value);
          notice_text = "To activate the new vhost setting, restart the broker";
          </put>
        </field>
        <field name = "user" type = "string" label = "User to run server as">
          <get>icl_shortstr_cpy (field_value, amq_server_config_user (amq_server_config));</get>
          <put>
          amq_server_config_set_user (amq_server_config, field_value);
          notice_text = "To activate the new user setting, restart the broker";
          </put>
        </field>
        <field name = "group" type = "string" label = "Group to run server as">
          <get>icl_shortstr_cpy (field_value, amq_server_config_group (amq_server_config));</get>
          <put>
          amq_server_config_set_group (amq_server_config, field_value);
          notice_text = "To activate the new group setting, restart the broker";
          </put>
        </field>
        <field name = "monitor" type = "int" label = "Monitor interval, seconds">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_monitor (amq_server_config));</get>
          <put>
          amq_server_config_set_monitor (amq_server_config, atol (field_value));
          </put>
        </field>
        <field name = "dump_state" type = "int" label = "Dump state interval, seconds">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_dump_state (amq_server_config));</get>
          <put>
          amq_server_config_set_dump_state (amq_server_config, atol (field_value));
          </put>
        </field>
        <field name = "record_stats" type = "bool" label = "Record performance statistics">
          <get>icl_shortstr_fmt (field_value, "%d", amq_server_config_record_stats (amq_server_config));</get>
          <put>
          amq_server_config_set_record_stats (amq_server_config, atoi (field_value));
          </put>
        </field>
        <field name = "log_path" type = "string" label = "Active log file directory">
          <get>icl_shortstr_cpy (field_value, amq_server_config_log_path (amq_server_config));</get>
          <put>
          amq_server_config_set_log_path (amq_server_config, field_value);
          notice_text = "To activate the new log_path setting, restart the broker";
          </put>
        </field>
        <field name = "keep_logs" type = "bool" label = "Keep log files">
          <get>icl_shortstr_fmt (field_value, "%d", amq_server_config_keep_logs (amq_server_config));</get>
          <put>
          amq_server_config_set_keep_logs (amq_server_config, atoi (field_value));
          notice_text = "To activate the new keep_logs setting, restart the broker";
          </put>
        </field>
        <field name = "archive_path" type = "string" label = "Archive log file directory">
          <get>icl_shortstr_cpy (field_value, amq_server_config_archive_path (amq_server_config));</get>
          <put>
          amq_server_config_set_archive_path (amq_server_config, field_value);
          notice_text = "To activate the new archive_path setting, restart the broker";
          </put>
        </field>
        <field name = "archive_cmd" type = "string" label = "Archive log file command">
          <get>icl_shortstr_cpy (field_value, amq_server_config_archive_cmd (amq_server_config));</get>
          <put>
          amq_server_config_set_archive_cmd (amq_server_config, field_value);
          notice_text = "To activate the new archive_cmd setting, restart the broker";
          </put>
        </field>
        <field name = "alert_log" type = "string" label = "Error log file name">
          <get>icl_shortstr_cpy (field_value, amq_server_config_alert_log (amq_server_config));</get>
          <put>
          amq_server_config_set_alert_log (amq_server_config, field_value);
          notice_text = "To activate the new alert_log setting, restart the broker";
          </put>
        </field>
        <field name = "daily_log" type = "string" label = "Daily log file name">
          <get>icl_shortstr_cpy (field_value, amq_server_config_daily_log (amq_server_config));</get>
          <put>
          amq_server_config_set_daily_log (amq_server_config, field_value);
          notice_text = "To activate the new daily_log setting, restart the broker";
          </put>
        </field>
        <field name = "debug_log" type = "string" label = "Debug log file name">
          <get>icl_shortstr_cpy (field_value, amq_server_config_debug_log (amq_server_config));</get>
          <put>
          amq_server_config_set_debug_log (amq_server_config, field_value);
          notice_text = "To activate the new debug_log setting, restart the broker";
          </put>
        </field>
        <field name = "debug_route" type = "bool" label = "Debug message routing?">
          <get>icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_route (amq_server_config));</get>
          <put>
          amq_server_config_set_debug_route (amq_server_config, atoi (field_value));
          </put>
        </field>
        <field name = "debug_queue" type = "bool" label = "Debug queue activity?">
          <get>icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_queue (amq_server_config));</get>
          <put>
          amq_server_config_set_debug_queue (amq_server_config, atoi (field_value));
          </put>
        </field>
        <field name = "debug_peering" type = "bool" label = "Debug peering messages?">
          <get>icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_peering (amq_server_config));</get>
          <put>
          amq_server_config_set_debug_peering (amq_server_config, atoi (field_value));
          </put>
        </field>
        <field name = "debug_console" type = "bool" label = "Debug console I/O?">
          <get>icl_shortstr_fmt (field_value, "%d", amq_server_config_debug_console (amq_server_config));</get>
          <put>
          amq_server_config_set_debug_console (amq_server_config, atoi (field_value));
          </put>
        </field>
        <field name = "trace" type = "int" label = "Protocol trace level">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_trace (amq_server_config));</get>
          <put>
          amq_server_config_set_trace (amq_server_config, atol (field_value));
          </put>
        </field>
        <field name = "heartbeat" type = "int" label = "Heartbeat timer, seconds">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_heartbeat (amq_server_config));</get>
          <put>
          amq_server_config_set_heartbeat (amq_server_config, atol (field_value));
          </put>
        </field>
        <field name = "setup_timeout" type = "int" label = "Connection setup timeout, seconds">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_setup_timeout (amq_server_config));</get>
          <put>
          amq_server_config_set_setup_timeout (amq_server_config, atol (field_value));
          notice_text = "To activate the new setup_timeout setting, restart the broker";
          </put>
        </field>
        <field name = "close_timeout" type = "int" label = "Connection close timeout, seconds">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_close_timeout (amq_server_config));</get>
          <put>
          amq_server_config_set_close_timeout (amq_server_config, atol (field_value));
          notice_text = "To activate the new close_timeout setting, restart the broker";
          </put>
        </field>
        <field name = "accept_retry_timeout" type = "int" label = "Timeout before retrying accept calls, seconds">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_accept_retry_timeout (amq_server_config));</get>
          <put>
          amq_server_config_set_accept_retry_timeout (amq_server_config, atol (field_value));
          notice_text = "To activate the new accept_retry_timeout setting, restart the broker";
          </put>
        </field>
        <field name = "polling_threads" type = "int" label = "Number of polling OS threads">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_polling_threads (amq_server_config));</get>
          <put>
          amq_server_config_set_polling_threads (amq_server_config, atol (field_value));
          notice_text = "To activate the new polling_threads setting, restart the broker";
          </put>
        </field>
        <field name = "working_threads" type = "int" label = "Number of working OS threads">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_working_threads (amq_server_config));</get>
          <put>
          amq_server_config_set_working_threads (amq_server_config, atol (field_value));
          notice_text = "To activate the new working_threads setting, restart the broker";
          </put>
        </field>
        <field name = "tcp_nodelay" type = "bool" label = "TCP/IP NODELAY option">
          <get>icl_shortstr_fmt (field_value, "%d", amq_server_config_tcp_nodelay (amq_server_config));</get>
          <put>
          amq_server_config_set_tcp_nodelay (amq_server_config, atoi (field_value));
          </put>
        </field>
        <field name = "tcp_rcvbuf" type = "int" label = "TCP/IP receive buffer, in bytes">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_tcp_rcvbuf (amq_server_config));</get>
          <put>
          amq_server_config_set_tcp_rcvbuf (amq_server_config, atol (field_value));
          </put>
        </field>
        <field name = "tcp_sndbuf" type = "int" label = "TCP/IP send buffer, in bytes">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_tcp_sndbuf (amq_server_config));</get>
          <put>
          amq_server_config_set_tcp_sndbuf (amq_server_config, atol (field_value));
          </put>
        </field>
        <field name = "frame_max" type = "int" label = "Maximum size of AMQP content frames">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_frame_max (amq_server_config));</get>
          <put>
          amq_server_config_set_frame_max (amq_server_config, atol (field_value));
          notice_text = "To activate the new frame_max setting, restart the broker";
          </put>
        </field>
        <field name = "direct" type = "int" label = "Enables Direct Mode for client connections">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_direct (amq_server_config));</get>
          <put>
          amq_server_config_set_direct (amq_server_config, atol (field_value));
          notice_text = "To activate the new direct setting, restart the broker";
          </put>
        </field>
        <field name = "private_credit" type = "int" label = "Credit window for private queues">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_private_credit (amq_server_config));</get>
          <put>
          amq_server_config_set_private_credit (amq_server_config, atol (field_value));
          notice_text = "To activate the new private_credit setting, restart the broker";
          </put>
        </field>
        <field name = "shared_credit" type = "int" label = "Credit window for shared queues">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_shared_credit (amq_server_config));</get>
          <put>
          amq_server_config_set_shared_credit (amq_server_config, atol (field_value));
          notice_text = "To activate the new shared_credit setting, restart the broker";
          </put>
        </field>
        <field name = "backup" type = "string" label = "Failover backup host:port">
          <get>icl_shortstr_cpy (field_value, amq_server_config_backup (amq_server_config));</get>
          <put>
          amq_server_config_set_backup (amq_server_config, field_value);
          notice_text = "To activate the new backup setting, restart the broker";
          </put>
        </field>
        <field name = "primary" type = "string" label = "Failover primary host:port">
          <get>icl_shortstr_cpy (field_value, amq_server_config_primary (amq_server_config));</get>
          <put>
          amq_server_config_set_primary (amq_server_config, field_value);
          notice_text = "To activate the new primary setting, restart the broker";
          </put>
        </field>
        <field name = "failover_timeout" type = "int" label = "Failover timeout, in seconds">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_failover_timeout (amq_server_config));</get>
          <put>
          amq_server_config_set_failover_timeout (amq_server_config, atol (field_value));
          notice_text = "To activate the new failover_timeout setting, restart the broker";
          </put>
        </field>
        <field name = "attach" type = "string" label = "Enable auto-federation to specified host">
          <get>icl_shortstr_cpy (field_value, amq_server_config_attach (amq_server_config));</get>
          <put>
          amq_server_config_set_attach (amq_server_config, field_value);
          notice_text = "To activate the new attach setting, restart the broker";
          </put>
        </field>
        <field name = "attach_vhost" type = "string" label = "Auto-federation virtual host name">
          <get>icl_shortstr_cpy (field_value, amq_server_config_attach_vhost (amq_server_config));</get>
          <put>
          amq_server_config_set_attach_vhost (amq_server_config, field_value);
          notice_text = "To activate the new attach_vhost setting, restart the broker";
          </put>
        </field>
        <field name = "attach_login" type = "string" label = "Auto-federation login user name">
          <get>icl_shortstr_cpy (field_value, amq_server_config_attach_login (amq_server_config));</get>
          <put>
          amq_server_config_set_attach_login (amq_server_config, field_value);
          notice_text = "To activate the new attach_login setting, restart the broker";
          </put>
        </field>
        <field name = "attach_all" type = "string" label = "Auto-federate exchanges by pattern">
          <get>icl_shortstr_cpy (field_value, amq_server_config_attach_all (amq_server_config));</get>
          <put>
          amq_server_config_set_attach_all (amq_server_config, field_value);
          notice_text = "To activate the new attach_all setting, restart the broker";
          </put>
        </field>
        <field name = "batching" type = "int" label = "Maximum size of Direct Mode batches">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_batching (amq_server_config));</get>
          <put>
          amq_server_config_set_batching (amq_server_config, atol (field_value));
          notice_text = "To activate the new batching setting, restart the broker";
          </put>
        </field>
        <field name = "direct_heartbeat" type = "int" label = "Heartbeat timer, seconds for Direct Mode">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_direct_heartbeat (amq_server_config));</get>
          <put>
          amq_server_config_set_direct_heartbeat (amq_server_config, atol (field_value));
          notice_text = "To activate the new direct_heartbeat setting, restart the broker";
          </put>
        </field>
        <field name = "no_ack" type = "bool" label = "Do not implement acknowledgments">
          <get>icl_shortstr_fmt (field_value, "%d", amq_server_config_no_ack (amq_server_config));</get>
          <put>
          amq_server_config_set_no_ack (amq_server_config, atoi (field_value));
          notice_text = "To activate the new no_ack setting, restart the broker";
          </put>
        </field>
        <field name = "auto_crash" type = "int" label = "Auto-crash test timer, seconds">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_auto_crash (amq_server_config));</get>
          <put>
          amq_server_config_set_auto_crash (amq_server_config, atol (field_value));
          </put>
        </field>
        <field name = "auto_block" type = "int" label = "Auto-freeze test timer, seconds">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_auto_block (amq_server_config));</get>
          <put>
          amq_server_config_set_auto_block (amq_server_config, atol (field_value));
          </put>
        </field>
        <field name = "kernel_limit" type = "int" label = "SMT kernel limit">
          <get>icl_shortstr_fmt (field_value, "%ld", amq_server_config_kernel_limit (amq_server_config));</get>
          <put>
          amq_server_config_set_kernel_limit (amq_server_config, atol (field_value));
          </put>
        </field>
        <method name = "commit" label = "Save custom configuration file">
          <exec>amq_server_config_commit (amq_server_config, NULL);</exec>
        </method>
        <method name = "rollback" label = "Restore previous configuration">
          <exec>amq_server_config_rollback (amq_server_config);</exec>
        </method>
    </class>
</data>

<import class = "amq_server_classes" />

<public>
extern $(selftype)
    *amq_console_config;                 //  Global properties object
</public>

<private>
$(selftype)
    *amq_console_config = NULL;          //  Global properties
</private>

<method name = "new">
    <argument name = "broker" type = "amq_broker_t *">Parent broker</argument>
</method>

<method name = "selftest" />

</class>

