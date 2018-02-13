<?xml?>
<class
    name      = "amq_mgt_config"
    comment   = "Management console config class"
    version   = "1.0"
    script    = "icl_gen"
    >
<doc>
Implements the management console config object, used by applications
to manage OpenAMQ servers. Use in conjunction with the amq_mgt_console
class.
</doc>

<inherit class = "icl_object">
    <option name = "alloc" value = "cache" />
</inherit>

<import class = "amq_mgt_console" />

<context>
    amq_client_session_t
        *session;                       //  AMQP session
    int
        id;                             //  Object ID
    icl_shortstr_t
        notice;                         //  Message from server
    icl_shortstr_t
        name;                           //  Configuration name
    icl_shortstr_t
        port;                           //  Server port for clients
    icl_shortstr_t
        listen;                         //  Address (local network interface) to listen on
    qbyte
        queue_timeout;                  //  Timeout for auto-deleted queues
    icl_shortstr_t
        vhost;                          //  Server vhost identifier
    icl_shortstr_t
        user;                           //  User to run server as
    icl_shortstr_t
        group;                          //  Group to run server as
    qbyte
        monitor;                        //  Monitor interval, seconds
    qbyte
        dump_state;                     //  Dump state interval, seconds
    Bool
        record_stats;                   //  Record performance statistics
    icl_shortstr_t
        log_path;                       //  Active log file directory
    Bool
        keep_logs;                      //  Keep log files
    icl_shortstr_t
        archive_path;                   //  Archive log file directory
    icl_shortstr_t
        archive_cmd;                    //  Archive log file command
    icl_shortstr_t
        alert_log;                      //  Error log file name
    icl_shortstr_t
        daily_log;                      //  Daily log file name
    icl_shortstr_t
        debug_log;                      //  Debug log file name
    Bool
        debug_route;                    //  Debug message routing?
    Bool
        debug_queue;                    //  Debug queue activity?
    Bool
        debug_peering;                  //  Debug peering messages?
    Bool
        debug_console;                  //  Debug console I/O?
    qbyte
        trace;                          //  Protocol trace level
    qbyte
        heartbeat;                      //  Heartbeat timer, seconds
    qbyte
        setup_timeout;                  //  Connection setup timeout, seconds
    qbyte
        close_timeout;                  //  Connection close timeout, seconds
    qbyte
        accept_retry_timeout;           //  Timeout before retrying accept calls, seconds
    qbyte
        polling_threads;                //  Number of polling OS threads
    qbyte
        working_threads;                //  Number of working OS threads
    Bool
        tcp_nodelay;                    //  TCP/IP NODELAY option
    qbyte
        tcp_rcvbuf;                     //  TCP/IP receive buffer, in bytes
    qbyte
        tcp_sndbuf;                     //  TCP/IP send buffer, in bytes
    qbyte
        frame_max;                      //  Maximum size of AMQP content frames
    qbyte
        direct;                         //  Enables Direct Mode for client connections
    qbyte
        private_credit;                 //  Credit window for private queues
    qbyte
        shared_credit;                  //  Credit window for shared queues
    icl_shortstr_t
        backup;                         //  Failover backup host:port
    icl_shortstr_t
        primary;                        //  Failover primary host:port
    qbyte
        failover_timeout;               //  Failover timeout, in seconds
    icl_shortstr_t
        attach;                         //  Enable auto-federation to specified host
    icl_shortstr_t
        attach_vhost;                   //  Auto-federation virtual host name
    icl_shortstr_t
        attach_login;                   //  Auto-federation login user name
    icl_shortstr_t
        attach_all;                     //  Auto-federate exchanges by pattern
    qbyte
        batching;                       //  Maximum size of Direct Mode batches
    qbyte
        direct_heartbeat;               //  Heartbeat timer, seconds for Direct Mode
    Bool
        no_ack;                         //  Do not implement acknowledgments
    qbyte
        auto_crash;                     //  Auto-crash test timer, seconds
    qbyte
        auto_block;                     //  Auto-freeze test timer, seconds
    qbyte
        kernel_limit;                   //  SMT kernel limit
</context>

<method name = "new">
    <argument name = "session" type = "amq_client_session_t *">AMQP session</argument>
    <argument name = "id" type = "int">Object ID</argument>
    self->session = session;
    self->id = id;
</method>

<method name = "destroy">
    s_destroy_children (self);
</method>

<method name = "load" template = "function">
    <doc>
    Loads or refreshes the object from the server console. Returns 0
    if the object was refreshed, -1 if there was an error talking to
    the server.
    </doc>
    <local>
    ipr_xml_t
        *xml_root,                      //  Returned response tree
        *xml_cml,                       //  CML item
        *xml_command,                   //  CML command
        *xml_field;                     //  Field item in reply
    char
        *field_name,                    //  Name of returned field
        *field_value;                   //  Value of returned field
    </local>
    //
    //  Send inspect request to console
    assert (self->id);
    xml_root = s_request_response (self, "inspect", self->id, NULL, NULL);
    if (xml_root) {
        s_destroy_children (self);
        xml_cml     = ipr_xml_first_child (xml_root);
        xml_command = ipr_xml_first_child (xml_cml);
        xml_field   = ipr_xml_first_child (xml_command);
        ipr_xml_unlink (&xml_cml);
        ipr_xml_unlink (&xml_command);

        while (xml_field) {
            field_name  = ipr_xml_attr_get (xml_field, "name", "");
            field_value = ipr_xml_text (xml_field);
            if (field_value) {
                if (streq (field_name, "name")) {
                    icl_shortstr_cpy (self->name, field_value);
                }
                else
                if (streq (field_name, "port")) {
                    icl_shortstr_cpy (self->port, field_value);
                }
                else
                if (streq (field_name, "listen")) {
                    icl_shortstr_cpy (self->listen, field_value);
                }
                else
                if (streq (field_name, "queue_timeout")) {
                    self->queue_timeout = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "vhost")) {
                    icl_shortstr_cpy (self->vhost, field_value);
                }
                else
                if (streq (field_name, "user")) {
                    icl_shortstr_cpy (self->user, field_value);
                }
                else
                if (streq (field_name, "group")) {
                    icl_shortstr_cpy (self->group, field_value);
                }
                else
                if (streq (field_name, "monitor")) {
                    self->monitor = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "dump_state")) {
                    self->dump_state = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "record_stats")) {
                    self->record_stats = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "log_path")) {
                    icl_shortstr_cpy (self->log_path, field_value);
                }
                else
                if (streq (field_name, "keep_logs")) {
                    self->keep_logs = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "archive_path")) {
                    icl_shortstr_cpy (self->archive_path, field_value);
                }
                else
                if (streq (field_name, "archive_cmd")) {
                    icl_shortstr_cpy (self->archive_cmd, field_value);
                }
                else
                if (streq (field_name, "alert_log")) {
                    icl_shortstr_cpy (self->alert_log, field_value);
                }
                else
                if (streq (field_name, "daily_log")) {
                    icl_shortstr_cpy (self->daily_log, field_value);
                }
                else
                if (streq (field_name, "debug_log")) {
                    icl_shortstr_cpy (self->debug_log, field_value);
                }
                else
                if (streq (field_name, "debug_route")) {
                    self->debug_route = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "debug_queue")) {
                    self->debug_queue = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "debug_peering")) {
                    self->debug_peering = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "debug_console")) {
                    self->debug_console = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "trace")) {
                    self->trace = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "heartbeat")) {
                    self->heartbeat = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "setup_timeout")) {
                    self->setup_timeout = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "close_timeout")) {
                    self->close_timeout = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "accept_retry_timeout")) {
                    self->accept_retry_timeout = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "polling_threads")) {
                    self->polling_threads = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "working_threads")) {
                    self->working_threads = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "tcp_nodelay")) {
                    self->tcp_nodelay = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "tcp_rcvbuf")) {
                    self->tcp_rcvbuf = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "tcp_sndbuf")) {
                    self->tcp_sndbuf = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "frame_max")) {
                    self->frame_max = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "direct")) {
                    self->direct = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "private_credit")) {
                    self->private_credit = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "shared_credit")) {
                    self->shared_credit = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "backup")) {
                    icl_shortstr_cpy (self->backup, field_value);
                }
                else
                if (streq (field_name, "primary")) {
                    icl_shortstr_cpy (self->primary, field_value);
                }
                else
                if (streq (field_name, "failover_timeout")) {
                    self->failover_timeout = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "attach")) {
                    icl_shortstr_cpy (self->attach, field_value);
                }
                else
                if (streq (field_name, "attach_vhost")) {
                    icl_shortstr_cpy (self->attach_vhost, field_value);
                }
                else
                if (streq (field_name, "attach_login")) {
                    icl_shortstr_cpy (self->attach_login, field_value);
                }
                else
                if (streq (field_name, "attach_all")) {
                    icl_shortstr_cpy (self->attach_all, field_value);
                }
                else
                if (streq (field_name, "batching")) {
                    self->batching = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "direct_heartbeat")) {
                    self->direct_heartbeat = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "no_ack")) {
                    self->no_ack = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "auto_crash")) {
                    self->auto_crash = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "auto_block")) {
                    self->auto_block = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "kernel_limit")) {
                    self->kernel_limit = (qbyte) atoi (field_value);
                }
                icl_mem_free (field_value);
            }
            xml_field = ipr_xml_next_sibling (&xml_field);
        }
        ipr_xml_destroy (&xml_root);
    }
    else
        rc = -1;                        //  Object no longer available
</method>

<method name = "print children" template = "function">
    <doc>
    Prints the config's contents to the console.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    char
        command [] = "";
    </local>
    //
    if (self_load (self))
        return (0);
    s_list_children (self, command, xml_data);
</method>

<method name = "print properties" template = "function">
    <doc>
    Prints the config's values to the console in a two-column list.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    icl_shortstr_t
        field_value;
    </local>
    //
    if (self_load (self))
        return (0);

    icl_console_out (" config = \\"%s\\" ", self->name);
    s_print_property ("Server port for clients", *self->port? self->port: "(empty)", "port", NULL);
    s_print_property ("Address (local network interface) to listen on", *self->listen? self->listen: "(empty)", "listen", NULL);
    sprintf (field_value, "%d", self->queue_timeout);
    s_print_property ("Timeout for auto-deleted queues", field_value, "queue_timeout", NULL);
    s_print_property ("Server vhost identifier", *self->vhost? self->vhost: "(empty)", "vhost", NULL);
    s_print_property ("User to run server as", *self->user? self->user: "(empty)", "user", NULL);
    s_print_property ("Group to run server as", *self->group? self->group: "(empty)", "group", NULL);
    sprintf (field_value, "%d", self->monitor);
    s_print_property ("Monitor interval, seconds", field_value, "monitor", NULL);
    sprintf (field_value, "%d", self->dump_state);
    s_print_property ("Dump state interval, seconds", field_value, "dump_state", NULL);
    s_print_property ("Record performance statistics", self->record_stats? "yes": "no", "record_stats", NULL);
    s_print_property ("Active log file directory", *self->log_path? self->log_path: "(empty)", "log_path", NULL);
    s_print_property ("Keep log files", self->keep_logs? "yes": "no", "keep_logs", NULL);
    s_print_property ("Archive log file directory", *self->archive_path? self->archive_path: "(empty)", "archive_path", NULL);
    s_print_property ("Archive log file command", *self->archive_cmd? self->archive_cmd: "(empty)", "archive_cmd", NULL);
    s_print_property ("Error log file name", *self->alert_log? self->alert_log: "(empty)", "alert_log", NULL);
    s_print_property ("Daily log file name", *self->daily_log? self->daily_log: "(empty)", "daily_log", NULL);
    s_print_property ("Debug log file name", *self->debug_log? self->debug_log: "(empty)", "debug_log", NULL);
    s_print_property ("Debug message routing?", self->debug_route? "yes": "no", "debug_route", NULL);
    s_print_property ("Debug queue activity?", self->debug_queue? "yes": "no", "debug_queue", NULL);
    s_print_property ("Debug peering messages?", self->debug_peering? "yes": "no", "debug_peering", NULL);
    s_print_property ("Debug console I/O?", self->debug_console? "yes": "no", "debug_console", NULL);
    sprintf (field_value, "%d", self->trace);
    s_print_property ("Protocol trace level", field_value, "trace", NULL);
    sprintf (field_value, "%d", self->heartbeat);
    s_print_property ("Heartbeat timer, seconds", field_value, "heartbeat", NULL);
    sprintf (field_value, "%d", self->setup_timeout);
    s_print_property ("Connection setup timeout, seconds", field_value, "setup_timeout", NULL);
    sprintf (field_value, "%d", self->close_timeout);
    s_print_property ("Connection close timeout, seconds", field_value, "close_timeout", NULL);
    sprintf (field_value, "%d", self->accept_retry_timeout);
    s_print_property ("Timeout before retrying accept calls, seconds", field_value, "accept_retry_timeout", NULL);
    sprintf (field_value, "%d", self->polling_threads);
    s_print_property ("Number of polling OS threads", field_value, "polling_threads", NULL);
    sprintf (field_value, "%d", self->working_threads);
    s_print_property ("Number of working OS threads", field_value, "working_threads", NULL);
    s_print_property ("TCP/IP NODELAY option", self->tcp_nodelay? "yes": "no", "tcp_nodelay", NULL);
    sprintf (field_value, "%d", self->tcp_rcvbuf);
    s_print_property ("TCP/IP receive buffer, in bytes", field_value, "tcp_rcvbuf", NULL);
    sprintf (field_value, "%d", self->tcp_sndbuf);
    s_print_property ("TCP/IP send buffer, in bytes", field_value, "tcp_sndbuf", NULL);
    sprintf (field_value, "%d", self->frame_max);
    s_print_property ("Maximum size of AMQP content frames", field_value, "frame_max", NULL);
    sprintf (field_value, "%d", self->direct);
    s_print_property ("Enables Direct Mode for client connections", field_value, "direct", NULL);
    sprintf (field_value, "%d", self->private_credit);
    s_print_property ("Credit window for private queues", field_value, "private_credit", NULL);
    sprintf (field_value, "%d", self->shared_credit);
    s_print_property ("Credit window for shared queues", field_value, "shared_credit", NULL);
    s_print_property ("Failover backup host:port", *self->backup? self->backup: "(empty)", "backup", NULL);
    s_print_property ("Failover primary host:port", *self->primary? self->primary: "(empty)", "primary", NULL);
    sprintf (field_value, "%d", self->failover_timeout);
    s_print_property ("Failover timeout, in seconds", field_value, "failover_timeout", NULL);
    s_print_property ("Enable auto-federation to specified host", *self->attach? self->attach: "(empty)", "attach", NULL);
    s_print_property ("Auto-federation virtual host name", *self->attach_vhost? self->attach_vhost: "(empty)", "attach_vhost", NULL);
    s_print_property ("Auto-federation login user name", *self->attach_login? self->attach_login: "(empty)", "attach_login", NULL);
    s_print_property ("Auto-federate exchanges by pattern", *self->attach_all? self->attach_all: "(empty)", "attach_all", NULL);
    sprintf (field_value, "%d", self->batching);
    s_print_property ("Maximum size of Direct Mode batches", field_value, "batching", NULL);
    sprintf (field_value, "%d", self->direct_heartbeat);
    s_print_property ("Heartbeat timer, seconds for Direct Mode", field_value, "direct_heartbeat", NULL);
    s_print_property ("Do not implement acknowledgments", self->no_ack? "yes": "no", "no_ack", NULL);
    sprintf (field_value, "%d", self->auto_crash);
    s_print_property ("Auto-crash test timer, seconds", field_value, "auto_crash", NULL);
    sprintf (field_value, "%d", self->auto_block);
    s_print_property ("Auto-freeze test timer, seconds", field_value, "auto_block", NULL);
    sprintf (field_value, "%d", self->kernel_limit);
    s_print_property ("SMT kernel limit", field_value, "kernel_limit", NULL);
    icl_console_out (" [commit] [rollback]");
    //  Record data in XML form if wanted
    if (xml_data) {
        fprintf (xml_data, "&lt;config id = \\"%d\\""
            " name = \\"%s\\""
            " port = \\"%s\\""
            " listen = \\"%s\\""
            " queue_timeout = \\"%d\\""
            " vhost = \\"%s\\""
            " user = \\"%s\\""
            " group = \\"%s\\""
            " monitor = \\"%d\\""
            " dump_state = \\"%d\\""
            " record_stats = \\"%d\\""
            " log_path = \\"%s\\""
            " keep_logs = \\"%d\\""
            " archive_path = \\"%s\\""
            " archive_cmd = \\"%s\\""
            " alert_log = \\"%s\\""
            " daily_log = \\"%s\\""
            " debug_log = \\"%s\\""
            " debug_route = \\"%d\\""
            " debug_queue = \\"%d\\""
            " debug_peering = \\"%d\\""
            " debug_console = \\"%d\\""
            " trace = \\"%d\\""
            " heartbeat = \\"%d\\""
            " setup_timeout = \\"%d\\""
            " close_timeout = \\"%d\\""
            " accept_retry_timeout = \\"%d\\""
            " polling_threads = \\"%d\\""
            " working_threads = \\"%d\\""
            " tcp_nodelay = \\"%d\\""
            " tcp_rcvbuf = \\"%d\\""
            " tcp_sndbuf = \\"%d\\""
            " frame_max = \\"%d\\""
            " direct = \\"%d\\""
            " private_credit = \\"%d\\""
            " shared_credit = \\"%d\\""
            " backup = \\"%s\\""
            " primary = \\"%s\\""
            " failover_timeout = \\"%d\\""
            " attach = \\"%s\\""
            " attach_vhost = \\"%s\\""
            " attach_login = \\"%s\\""
            " attach_all = \\"%s\\""
            " batching = \\"%d\\""
            " direct_heartbeat = \\"%d\\""
            " no_ack = \\"%d\\""
            " auto_crash = \\"%d\\""
            " auto_block = \\"%d\\""
            " kernel_limit = \\"%d\\""
            "/&gt;\\n", self->id
            , self->name
            , self->port
            , self->listen
            , self->queue_timeout
            , self->vhost
            , self->user
            , self->group
            , self->monitor
            , self->dump_state
            , self->record_stats
            , self->log_path
            , self->keep_logs
            , self->archive_path
            , self->archive_cmd
            , self->alert_log
            , self->daily_log
            , self->debug_log
            , self->debug_route
            , self->debug_queue
            , self->debug_peering
            , self->debug_console
            , self->trace
            , self->heartbeat
            , self->setup_timeout
            , self->close_timeout
            , self->accept_retry_timeout
            , self->polling_threads
            , self->working_threads
            , self->tcp_nodelay
            , self->tcp_rcvbuf
            , self->tcp_sndbuf
            , self->frame_max
            , self->direct
            , self->private_credit
            , self->shared_credit
            , self->backup
            , self->primary
            , self->failover_timeout
            , self->attach
            , self->attach_vhost
            , self->attach_login
            , self->attach_all
            , self->batching
            , self->direct_heartbeat
            , self->no_ack
            , self->auto_crash
            , self->auto_block
            , self->kernel_limit
        );
    }
</method>

<method name = "print summary" template = "function">
    <doc>
    Prints the config to the console in a single row.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    </local>
    //
    icl_console_out (" %d) config = \\"%s\\"  ", self->id, self->name);
    //  Record data in XML form if wanted
    if (xml_data) {
        fprintf (xml_data, "&lt;config id = \\"%d\\""
            " name = \\"%s\\""
            " port = \\"%s\\""
            " listen = \\"%s\\""
            " queue_timeout = \\"%d\\""
            " vhost = \\"%s\\""
            " user = \\"%s\\""
            " group = \\"%s\\""
            " monitor = \\"%d\\""
            " dump_state = \\"%d\\""
            " record_stats = \\"%d\\""
            " log_path = \\"%s\\""
            " keep_logs = \\"%d\\""
            " archive_path = \\"%s\\""
            " archive_cmd = \\"%s\\""
            " alert_log = \\"%s\\""
            " daily_log = \\"%s\\""
            " debug_log = \\"%s\\""
            " debug_route = \\"%d\\""
            " debug_queue = \\"%d\\""
            " debug_peering = \\"%d\\""
            " debug_console = \\"%d\\""
            " trace = \\"%d\\""
            " heartbeat = \\"%d\\""
            " setup_timeout = \\"%d\\""
            " close_timeout = \\"%d\\""
            " accept_retry_timeout = \\"%d\\""
            " polling_threads = \\"%d\\""
            " working_threads = \\"%d\\""
            " tcp_nodelay = \\"%d\\""
            " tcp_rcvbuf = \\"%d\\""
            " tcp_sndbuf = \\"%d\\""
            " frame_max = \\"%d\\""
            " direct = \\"%d\\""
            " private_credit = \\"%d\\""
            " shared_credit = \\"%d\\""
            " backup = \\"%s\\""
            " primary = \\"%s\\""
            " failover_timeout = \\"%d\\""
            " attach = \\"%s\\""
            " attach_vhost = \\"%s\\""
            " attach_login = \\"%s\\""
            " attach_all = \\"%s\\""
            " batching = \\"%d\\""
            " direct_heartbeat = \\"%d\\""
            " no_ack = \\"%d\\""
            " auto_crash = \\"%d\\""
            " auto_block = \\"%d\\""
            " kernel_limit = \\"%d\\""
            "/&gt;\\n", self->id
            , self->name
            , self->port
            , self->listen
            , self->queue_timeout
            , self->vhost
            , self->user
            , self->group
            , self->monitor
            , self->dump_state
            , self->record_stats
            , self->log_path
            , self->keep_logs
            , self->archive_path
            , self->archive_cmd
            , self->alert_log
            , self->daily_log
            , self->debug_log
            , self->debug_route
            , self->debug_queue
            , self->debug_peering
            , self->debug_console
            , self->trace
            , self->heartbeat
            , self->setup_timeout
            , self->close_timeout
            , self->accept_retry_timeout
            , self->polling_threads
            , self->working_threads
            , self->tcp_nodelay
            , self->tcp_rcvbuf
            , self->tcp_sndbuf
            , self->frame_max
            , self->direct
            , self->private_credit
            , self->shared_credit
            , self->backup
            , self->primary
            , self->failover_timeout
            , self->attach
            , self->attach_vhost
            , self->attach_login
            , self->attach_all
            , self->batching
            , self->direct_heartbeat
            , self->no_ack
            , self->auto_crash
            , self->auto_block
            , self->kernel_limit
        );
    }
</method>

<method name = "cmdline" template = "function">
    <doc>
    Implements a command-line interface for the config object.
    </doc>
    <argument name = "path" type = "char *">Current path</argument>
    <argument name = "depth" type = "int">Current depth</argument>
    <argument name = "tokens" type = "ipr_token_list_t *">Automation, if any</argument>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    icl_shortstr_t
        command;
    </local>
    //
#   define CD_UP    1                   //  Child cmdline asks to move up
#   define CD_TOP   2                   //  Child cmdline asks to move to top
#   define CD_EXIT  3                   //  Child cmdline asks to exit

    if (self_load (self))
        return (CD_UP);
    self_print_properties (self, xml_data);
    
    while (TRUE) {
        amq_client_session_wait (self->session, 1);
        if (!self->session->alive) {
            icl_console_print ("E: Server disconnected - %s", self->session->error_text);
            exit (EXIT_FAILURE);
        }
        //  If we're in autopilot mode, take next command else wait for user
        if (tokens) {
            ipr_token_t
                *token = ipr_token_list_first (tokens);
            if (token) {
                icl_shortstr_cpy (command, token->value);
                ipr_token_destroy (&token);
            }
            else {
                rc = CD_EXIT;
                break;
            }
        }
        else {
            //  Read command from stdin
            printf ("/%s>", path);
            strclr (command);
            if (fgets (command, 255, stdin))
                command [strlen (command) - 1] = 0;
        }
        ipr_str_lower (command);
        ipr_str_crop  (command);

        if (streq (command, ""))
            ;   //  Do nothing
        else
        if (streq (command, ".")) {
            if (self_load (self))
                return (CD_UP);
            self_print_properties (self, xml_data);
        }
        else
        if (ipr_str_prefixed (command, "ls")) {
            if (self_load (self))
                return (CD_UP);
            s_list_children (self, command + 2, xml_data);
        }
        else
        if (ipr_str_prefixed (command, "top")) {
            if (self_load (self))
                return (CD_UP);
            s_top_children (self, command + 3, xml_data);
        }
        else
        if (ipr_str_prefixed (command, "cd ")) {
            if (self_load (self))
                return (CD_UP);
            rc = s_change_level (self, command + 3, path, depth, tokens, xml_data);
            if (rc == CD_UP && depth) {
                rc = 0;
                break;
            }
            else
            if ((rc == CD_TOP && depth) || rc == CD_EXIT)
                break;
        }
        else
        if (atoi (command)) {
            if (self_load (self))
                return (CD_UP);
            rc = s_change_level (self, command, path, depth, tokens, xml_data);
            if (rc == CD_UP && depth) {
                rc = 0;
                break;
            }
            else
            if ((rc == CD_TOP && depth) || rc == CD_EXIT)
                break;
        }
        else
        if (streq (command, "..")) {
            if (depth)
                break;
        }
        else
        if (streq (command, "/")) {
            if (depth) {
                rc = CD_TOP;
                break;
            }
        }
        else
        if (ipr_str_prefixed (command, "set"))
            s_set_property (self, command);
        else
        if (ipr_str_prefixed (command, "commit"))
            s_execute_commit (self, command);
        else
        if (ipr_str_prefixed (command, "rollback"))
            s_execute_rollback (self, command);
        else
        if (streq (command, "exit") || streq (command, "quit")) {
            rc = CD_EXIT;
            break;
        }
        else
        if (streq (command, "help"))
            s_show_help ();

        else {
            icl_console_out (" Not a valid command");
            s_show_help ();
        }
    }
</method>

<private name = "header">
static void
    s_destroy_children ($(selftype) *self);
static ipr_xml_t *
    s_request_response ($(selftype) *self, char *request, qbyte object_id,
        char *method, asl_field_list_t *fields);
static void
    s_print_property (char *label, char *value, char *name, char *command);
static void
    s_set_property ($(selftype) *self, char *command);
static int
    s_change_level ($(selftype) *self, char *command, char *path,
        int depth, ipr_token_list_t *tokens, FILE *xml_data);
static void
    s_list_children ($(selftype) *self, char *command, FILE *xml_data);
static void
    s_top_children ($(selftype) *self, char *command, FILE *xml_data);
static void
    s_execute_commit ($(selftype) *self, char *command);
static void
    s_execute_rollback ($(selftype) *self, char *command);
static void
    s_show_help (void);
</private>

<private name = "footer">
//  Resets / destroys child objects
static void
s_destroy_children ($(selftype) *self)
{
}

//  Sends a request, returns a response content
static ipr_xml_t *
s_request_response (
    $(selftype) *self,
    char *request,
    qbyte object_id,
    char *method,
    asl_field_list_t *fields)
{
    amq_content_basic_t
        *content;                       //  Last content sent/recieved
    ipr_bucket_t
        *bucket = NULL;                 //  Message comes here
    icl_shortstr_t
        command;                        //  CML request or reply name
    ipr_xml_t
        *xml_root = NULL,               //  Tree of file we've loaded
        *xml_cml,                       //  Top level cml item
        *xml_command;                   //  CML command
    char
        *reply_class,                   //  Returned class string
        *reply_status;                  //  Returned status value
    long
        reply_object;                   //  Returned object id

    icl_shortstr_fmt (command, "%s-request", request);
    content = amq_cml_encode (command, "config", object_id, NULL, method, fields);
    amq_content_basic_set_reply_to (content, self->session->queue);
    amq_client_session_basic_publish (
        self->session, content, 0, "amq.system", "amq.console", FALSE, FALSE);
    amq_content_basic_unlink (&content);

    //  Wait for response on our queue
    if (amq_client_session_wait (self->session, 10000) == 0)
        content = amq_client_session_basic_arrived (self->session);

    //  Process response, if any
    if (content) {
        //  TODO: amq_cml_decode
        //  Get content body into a bucket
        bucket = ipr_bucket_new (IPR_BUCKET_MAX_SIZE);
        bucket->cur_size = amq_content_basic_get_body (content, bucket->data, bucket->max_size);
        assert (bucket->cur_size < IPR_BUCKET_MAX_SIZE);
        bucket->data [bucket->cur_size] = 0;

        //  Parse as XML message
        ipr_xml_load_string (&xml_root, (char *) bucket->data, FALSE);
        ipr_bucket_unlink (&bucket);
        assert (xml_root);

        //  Check that the result is valid CML
        xml_cml = ipr_xml_first_child (xml_root);
        assert (xml_cml);
        assert (ipr_xml_name (xml_cml));
        assert (streq (ipr_xml_name (xml_cml), "cml"));
        
        //  Check that the response matches our request
        xml_command = ipr_xml_first_child (xml_cml);
        assert (xml_command);
        assert (ipr_xml_name (xml_command));

        reply_class  = ipr_xml_attr_get (xml_command, "class",  "");
        reply_status = ipr_xml_attr_get (xml_command, "status", "");
        reply_object = atol (ipr_xml_attr_get (xml_command, "object", ""));
        icl_shortstr_cpy (self->notice, ipr_xml_attr_get (xml_command, "notice", ""));

        if (streq (ipr_xml_name (xml_command), "invalid")) {
            icl_console_print ("E: invalid request sent to console");
            exit (EXIT_FAILURE);
        }
        else
        if (streq (ipr_xml_name (xml_command), "notify"))
            ;   //  Handle notification and loop for next content
        else {
            //  Check that the response is the reply for our object
            icl_shortstr_fmt (command, "%s-reply", request);
            assert (streq (ipr_xml_name (xml_command), command));
            if (streq (reply_status, "ok")) {
                if (strneq (reply_class, "config"))
                    icl_console_print ("E: received OK for '%s', expected 'config'", reply_class);
                assert (streq (reply_class, "config"));
                assert (reply_object == self->id);
            }
            else
            if (streq (reply_status, "notfound")) {
                icl_console_print ("E: object was not found");
                //  If command not valid, return NULL
                ipr_xml_destroy (&xml_root);
            }
            else
            if (streq (reply_status, "noaccess")) {
                icl_console_out (" Not allowed to execute requested operation");
                //  If command not valid, return NULL
                ipr_xml_destroy (&xml_root);
            }
            else
            if (streq (reply_status, "invalid")) {
                icl_console_print ("E: internal error in CML formatting");
                //  If command not valid, return NULL
                ipr_xml_destroy (&xml_root);
            }
        }
        amq_content_basic_unlink (&content);
        ipr_xml_unlink (&xml_command);
        ipr_xml_unlink (&xml_cml);
        return (xml_root);
    }
    else {
        icl_console_out (" No reply from server - %s", self->session->error_text);
        exit (EXIT_FAILURE);
    }
}

static void
s_print_property (char *label, char *value, char *name, char *command)
{
    icl_shortstr_t
        property;

    icl_shortstr_fmt (property, " %s ...", label);
    while (strlen (property) < 40)
        strcat (property, ".");
    strcat (property, " ");
    strcat (property, value);
    if (name) {
        while (strlen (property) < 60)
            strcat (property, " ");
        icl_shortstr_cat (property, "(set ");
        icl_shortstr_cat (property, name);
        icl_shortstr_cat (property, ")");
    }
    if (command) {
        icl_shortstr_cat (property, " ");
        icl_shortstr_cat (property, command);
    }
    icl_console_out (property);
}

static void
s_set_property ($(selftype) *self, char *command)
{
    ipr_token_list_t
        *tokens;
    ipr_token_t
        *token;
    char
        *name  = NULL,
        *value = NULL;
    ipr_xml_t
        *xml_root;                      //  Returned response tree
    asl_field_list_t
        *fields;                        //  Properties of object

    tokens = ipr_token_split (command);
    token = ipr_token_list_first (tokens);
    assert (token);
    if (streq (token->value, "set")) {
        token = ipr_token_list_next (&token);
        if (token) {
            name = token->value;
            token = ipr_token_list_next (&token);
            if (token) {
                value = token->value;
                token = ipr_token_list_next (&token);
                if (token) {
                    icl_console_out (" Data from %s onwards was ignored", token->value);
                    ipr_token_unlink (&token);
                }
            }
        }
    }
    if (name
    &&  strneq (name, "port")
    &&  strneq (name, "listen")
    &&  strneq (name, "queue_timeout")
    &&  strneq (name, "vhost")
    &&  strneq (name, "user")
    &&  strneq (name, "group")
    &&  strneq (name, "monitor")
    &&  strneq (name, "dump_state")
    &&  strneq (name, "record_stats")
    &&  strneq (name, "log_path")
    &&  strneq (name, "keep_logs")
    &&  strneq (name, "archive_path")
    &&  strneq (name, "archive_cmd")
    &&  strneq (name, "alert_log")
    &&  strneq (name, "daily_log")
    &&  strneq (name, "debug_log")
    &&  strneq (name, "debug_route")
    &&  strneq (name, "debug_queue")
    &&  strneq (name, "debug_peering")
    &&  strneq (name, "debug_console")
    &&  strneq (name, "trace")
    &&  strneq (name, "heartbeat")
    &&  strneq (name, "setup_timeout")
    &&  strneq (name, "close_timeout")
    &&  strneq (name, "accept_retry_timeout")
    &&  strneq (name, "polling_threads")
    &&  strneq (name, "working_threads")
    &&  strneq (name, "tcp_nodelay")
    &&  strneq (name, "tcp_rcvbuf")
    &&  strneq (name, "tcp_sndbuf")
    &&  strneq (name, "frame_max")
    &&  strneq (name, "direct")
    &&  strneq (name, "private_credit")
    &&  strneq (name, "shared_credit")
    &&  strneq (name, "backup")
    &&  strneq (name, "primary")
    &&  strneq (name, "failover_timeout")
    &&  strneq (name, "attach")
    &&  strneq (name, "attach_vhost")
    &&  strneq (name, "attach_login")
    &&  strneq (name, "attach_all")
    &&  strneq (name, "batching")
    &&  strneq (name, "direct_heartbeat")
    &&  strneq (name, "no_ack")
    &&  strneq (name, "auto_crash")
    &&  strneq (name, "auto_block")
    &&  strneq (name, "kernel_limit"))
        icl_console_out (" Not a valid property name, please check");
    else
    if (name && value) {
        fields = asl_field_list_new (NULL);
        asl_field_new_string (fields, name, value);
        xml_root = s_request_response (self, "modify", self->id, NULL, fields);
        if (xml_root) {
            icl_console_out (" OK - %s", *self->notice? self->notice: "done");
            ipr_xml_destroy (&xml_root);
        }
        asl_field_list_destroy (&fields);
    }
    else
        icl_console_out (" Usage: set propertyname newvalue");

    ipr_token_list_destroy (&tokens);
}


static int
s_change_level (
    $(selftype) *self,
    char *command,
    char *path,
    int depth,
    ipr_token_list_t *tokens,
    FILE *xml_data)
{
    int
        rc = 0,
        child_id;
    Bool
        id_found = FALSE;

    ipr_str_crop (ipr_str_skip (command));
    if (streq (command, ".."))
        rc = CD_UP;
    else
    if (streq (command, "/"))
        rc = CD_TOP;
    else
    if ((child_id = atoi (command))) {
        if (!id_found)
            icl_console_out (" No item number %d in scope", child_id);
    }
    else
        icl_console_out (" Invalid command, use 'cd [number]'");

    return (rc);
}

static void
s_list_children ($(selftype) *self, char *command, FILE *xml_data)
{
    ipr_token_list_t
        *tokens;
    ipr_token_t
        *token;
    char
        *childname = NULL,
        *pattern = NULL;

    //  Get child name if any
    tokens = ipr_token_split (command);
    token = ipr_token_list_first (tokens);
    if (token) {
        if (strchr (token->value, '?') || strchr (token->value, '*'))
            pattern = token->value;
        else {
            childname = token->value;
            token = ipr_token_list_next (&token);
            if (token)
                pattern = token->value;
        }
        ipr_token_unlink (&token);
    }
    ipr_token_list_destroy (&tokens);
}

static void
s_top_children ($(selftype) *self, char *command, FILE *xml_data)
{
    ipr_token_list_t
        *tokens;
    ipr_token_t
        *token;
    icl_shortstr_t
        childname,
        criterion;
    uint
        top_count;                      //  Number of tops requested by user

    //  Get child name if any
    tokens = ipr_token_split (command);
    if (ipr_token_list_count (tokens) != 3) {
        icl_console_out ("Syntax error (top object-type sort-criterion number-of-items)");
        ipr_token_list_destroy (&tokens);
        return;
    }

    token = ipr_token_list_first (tokens);
    icl_shortstr_cpy (childname, token->value);
    token = ipr_token_list_next (&token);
    icl_shortstr_cpy (criterion, token->value);
    token = ipr_token_list_next (&token);
    top_count = atoi (token->value);
    if (top_count < 1) {
        icl_console_out ("Syntax error (number of items in top list must be grater than zero)");
        ipr_token_list_destroy (&tokens);
        return;
    }
    ipr_token_unlink (&token);

    if (0) {}
    else {
        icl_console_out ("Top list of '%s' objects not supported", childname);
        ipr_token_list_destroy (&tokens);
        return;
    }
    ipr_token_list_destroy (&tokens);
}

//  Execute commit method
//
static void
s_execute_commit ($(selftype) *self, char *command)
{
    ipr_token_list_t
        *tokens;
    ipr_token_t
        *token;
    ipr_xml_t
        *xml_root;                      //  Returned response tree
    asl_field_list_t
        *fields;                        //  Properties of object
    Bool
        is_valid = TRUE;                //  Valid method syntax?

    tokens = ipr_token_split (command);
    fields = asl_field_list_new (NULL);

    //  Skip method name, first token in string
    token = ipr_token_list_first (tokens);
    assert (token);

    ipr_token_unlink (&token);
    if (is_valid) {
        xml_root = s_request_response (self, "method", self->id, "commit", fields);
        if (xml_root) {
            icl_console_out (" OK");
            ipr_xml_destroy (&xml_root);
            if (self_load (self))
                return;
        }
        else
            icl_console_out (" ERROR");
    }
    else
        icl_console_out (" Usage: commit arguments, use 'help commit' for details");

    asl_field_list_destroy (&fields);
    ipr_token_list_destroy (&tokens);
}

//  Execute rollback method
//
static void
s_execute_rollback ($(selftype) *self, char *command)
{
    ipr_token_list_t
        *tokens;
    ipr_token_t
        *token;
    ipr_xml_t
        *xml_root;                      //  Returned response tree
    asl_field_list_t
        *fields;                        //  Properties of object
    Bool
        is_valid = TRUE;                //  Valid method syntax?

    tokens = ipr_token_split (command);
    fields = asl_field_list_new (NULL);

    //  Skip method name, first token in string
    token = ipr_token_list_first (tokens);
    assert (token);

    ipr_token_unlink (&token);
    if (is_valid) {
        xml_root = s_request_response (self, "method", self->id, "rollback", fields);
        if (xml_root) {
            icl_console_out (" OK");
            ipr_xml_destroy (&xml_root);
            if (self_load (self))
                return;
        }
        else
            icl_console_out (" ERROR");
    }
    else
        icl_console_out (" Usage: rollback arguments, use 'help rollback' for details");

    asl_field_list_destroy (&fields);
    ipr_token_list_destroy (&tokens);
}

static void
s_show_help (void)
{
    icl_console_out ("");
    icl_console_out (" Command               Has this effect");
    icl_console_out (" -------               -------------------");
    icl_console_out (" ls [child] [pattern]  Show matching children");
    icl_console_out (" top [child]           Show most important children");
    icl_console_out (" cd [nnn]              Look at item [number nnn]");
    icl_console_out (" nnn                   Look at item number nnn");
    icl_console_out (" /                     Return to broker item");
    icl_console_out (" .                     Show current item");
    icl_console_out (" ..                    Move back to previous item");
    icl_console_out (" set name value        Set object property");
    icl_console_out (" help                  Show this text");
    icl_console_out (" exit | quit           Leave the OpenAMQ shell");
    icl_console_out ("");
    icl_console_out ("");
    icl_console_out (" commit");
    icl_console_out ("");
    icl_console_out (" rollback");
}
</private>

<method name = "selftest">
</method>

</class>
