<?xml?>
<!--
    *** GENERATED FROM amq_server_config.opf BY opf_gen USING GSL/4 ***

    
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
 -->
<class
    name      = "amq_server_config"
    comment   = "Server configuration properties"
    version   = "1.0"
    script    = "icl_gen"
    license   = "gpl"
    opaque    = "1"
    >

<inherit class = "icl_object">
    <option name = "alloc"  value = "cache" />
    <option name = "rwlock" value = "1" />
</inherit>

<import class = "smt_log" />

<public name = "include">
#include "ipr.h"
</public>

<public>
extern $(selftype)
    *amq_server_config;                 //  Global properties object
</public>

<private>
$(selftype)
    *amq_server_config = NULL;          //  Global properties
</private>

<context>
    char *
        port;                           //  Server port for clients
    char *
        listen;                         //  Address (local network interface) to listen on
    int
        queue_timeout;                  //  Timeout for auto-deleted queues
    char *
        vhost;                          //  Server vhost identifier
    char *
        user;                           //  User to run server as
    char *
        group;                          //  Group to run server as
    int
        monitor;                        //  Monitor interval, seconds
    int
        dump_state;                     //  Dump state interval, seconds
    Bool
        record_stats;                   //  Record performance statistics
    char *
        log_path;                       //  Active log file directory
    Bool
        keep_logs;                      //  Keep log files
    char *
        archive_cmd;                    //  Archive log file command
    char *
        alert_log;                      //  Error log file name
    char *
        daily_log;                      //  Daily log file name
    char *
        debug_log;                      //  Debug log file name
    Bool
        debug_route;                    //  Debug message routing?
    Bool
        debug_queue;                    //  Debug queue activity?
    Bool
        debug_peering;                  //  Debug peering messages?
    Bool
        debug_console;                  //  Debug console I/O?
    int
        trace;                          //  Protocol trace level
    int
        syslog;                         //  Use syslog logging protocol
    int
        coremark_cycles;                //  Duration of CoreMark test
    int
        heartbeat;                      //  Heartbeat timer, seconds
    int
        setup_timeout;                  //  Connection setup timeout, seconds
    int
        close_timeout;                  //  Connection close timeout, seconds
    int
        accept_retry_timeout;           //  Timeout before retrying accept calls, seconds
    int
        polling_threads;                //  Number of polling OS threads
    int
        working_threads;                //  Number of working OS threads
    Bool
        tcp_nodelay;                    //  TCP/IP NODELAY option
    int
        tcp_rcvbuf;                     //  TCP/IP receive buffer, in bytes
    int
        tcp_sndbuf;                     //  TCP/IP send buffer, in bytes
    int
        frame_max;                      //  Maximum size of AMQP content frames
    int
        direct;                         //  Enables Direct Mode for client connections
    int
        private_credit;                 //  Credit window for private queues
    int
        shared_credit;                  //  Credit window for shared queues
    char *
        backup;                         //  Failover backup host:port
    char *
        primary;                        //  Failover primary host:port
    int
        failover_timeout;               //  Failover timeout, in seconds
    char *
        attach;                         //  Enable auto-federation to specified host
    char *
        attach_vhost;                   //  Auto-federation virtual host name
    char *
        attach_login;                   //  Auto-federation login user name
    char *
        attach_all;                     //  Auto-federate exchanges by pattern
    int
        batching;                       //  Maximum size of Direct Mode batches
    int
        direct_heartbeat;               //  Heartbeat timer, seconds for Direct Mode
    Bool
        no_ack;                         //  Do not implement acknowledgments
    int
        auto_crash;                     //  Auto-crash test timer, seconds
    int
        auto_block;                     //  Auto-freeze test timer, seconds
    int
        kernel_limit;                   //  SMT kernel limit
    <property name = "filename" type = "char *" />
    <property name = "table" type = "ipr_config_t *" readonly = "1" />
</context>

<method name = "new">
    <doc>
    Creates an empty configuration set.  To fill this, use the load and
    load_bucket methods.
    </doc>
    //
    self->table = ipr_config_new (NULL, FALSE);
</method>

<method name = "destroy">
    ipr_config_destroy (&self->table);
</method>

<method name = "load xmlfile" template = "function">
    <doc>
    Loads a config file into the property set, merging the new loaded data
    with any previous data, as defined in ipr_config.icl.
    </doc>
    <argument name = "filename" type = "char *">Config file to load</argument>
    <argument name = "required" type = "Bool">Config file is required?</argument>
    //
    assert (filename);
    if (!ipr_config_load (self->table, filename, required)) {
        self_set_filename (self, filename);
        s_validate_items (self);
        s_get_properties (self);
    }
</method>

<method name = "load bucket" template = "function">
    <doc>
    Loads a config resource (as a bucket) into the property set, merging the
    new loaded data with any previous data, as defined in ipr_config.icl.
    </doc>
    <argument name = "bucket" type = "ipr_bucket_t *">Config data to load</argument>
    //
    assert (bucket);
    ipr_config_load_bucket (self->table, bucket);
    s_validate_items (self);
    s_get_properties (self);
</method>

<method name = "shadow" template = "function">
    <doc>
    Loads the data from a different property set, and updates all the properties.
    Use this when you want to provide your code with multiple property classes
    that actually contain an identical configuration set.  To use:
    my_config = my_config_new (NULL, NULL, FALSE);
    my_config_shadow (self, your_config->config);
    </doc>
    <argument name = "source" type = "ipr_config_t *">Config data to shadow</argument>
    //
    //  Get rid of our own config data
    ipr_config_destroy (&self->table);
    //  Grab a handle onto the source data
    self->table = ipr_config_dup (source);
    //  Update our properties, without validation
    s_get_properties (self);
</method>

<method name = "commit" template = "function">
    <doc>
    Saves the current configuration values to the specified file.  If the
    provided filename is null, uses the original config filename. If both
    filenames are null, does nothing.
    </doc>
    <argument name = "filename" type = "char *">Config file to save</argument>
    <inherit name = "wrlock" />
    //
    if (filename)
        ipr_config_save (self->table, filename);
    else
    if (strused (self->filename))
        ipr_config_save (self->table, self->filename);
</method>

<method name = "rollback" template = "function">
    <doc>
    Reloads the saved configuration from the saved file, if any.
    Any changes made to the current configuration are lost.
    </doc>
    <inherit name = "wrlock" />
    //
    ipr_config_destroy (&self->table);
    self->table = ipr_config_new (self->filename, TRUE);
    s_get_properties (self);
</method>

<method name = "cmdline help">
    <doc>
    Prints command-line help for setting options from the command
    line.
    </doc>
    printf ("Options that override config values; these take an argument:\\n");
    printf ("  --port           Server port for clients\\n");
    printf ("  --listen         Address (local network interface) to listen on\\n");
    printf ("  --queue_timeout  Timeout for auto-deleted queues\\n");
    printf ("  --vhost          Server vhost identifier\\n");
    printf ("  --user           User to run server as\\n");
    printf ("  --group          Group to run server as\\n");
    printf ("  --monitor        Monitor interval, seconds\\n");
    printf ("  --dump_state     Dump state interval, seconds\\n");
    printf ("  --record_stats   Record performance statistics\\n");
    printf ("  --log_path       Active log file directory\\n");
    printf ("  --keep_logs      Keep log files\\n");
    printf ("  --archive_cmd    Archive log file command\\n");
    printf ("  --alert_log      Error log file name\\n");
    printf ("  --daily_log      Daily log file name\\n");
    printf ("  --debug_log      Debug log file name\\n");
    printf ("  --debug_route    Debug message routing?\\n");
    printf ("  --debug_queue    Debug queue activity?\\n");
    printf ("  --debug_peering  Debug peering messages?\\n");
    printf ("  --debug_console  Debug console I/O?\\n");
    printf ("  --trace          Protocol trace level\\n");
    printf ("  --syslog         Use syslog logging protocol\\n");
    printf ("  --coremark_cycles  Duration of CoreMark test\\n");
    printf ("  --heartbeat      Heartbeat timer, seconds\\n");
    printf ("  --setup_timeout  Connection setup timeout, seconds\\n");
    printf ("  --close_timeout  Connection close timeout, seconds\\n");
    printf ("  --accept_retry_timeout  Timeout before retrying accept calls, seconds\\n");
    printf ("  --polling_threads  Number of polling OS threads\\n");
    printf ("  --working_threads  Number of working OS threads\\n");
    printf ("  --tcp_nodelay    TCP/IP NODELAY option\\n");
    printf ("  --tcp_rcvbuf     TCP/IP receive buffer, in bytes\\n");
    printf ("  --tcp_sndbuf     TCP/IP send buffer, in bytes\\n");
    printf ("  --frame_max      Maximum size of AMQP content frames\\n");
    printf ("  --direct         Enables Direct Mode for client connections\\n");
    printf ("  --private_credit  Credit window for private queues\\n");
    printf ("  --shared_credit  Credit window for shared queues\\n");
    printf ("  --backup         Failover backup host:port\\n");
    printf ("  --primary        Failover primary host:port\\n");
    printf ("  --failover_timeout  Failover timeout, in seconds\\n");
    printf ("  --attach         Enable auto-federation to specified host\\n");
    printf ("  --attach_vhost   Auto-federation virtual host name\\n");
    printf ("  --attach_login   Auto-federation login user name\\n");
    printf ("  --attach_all     Auto-federate exchanges by pattern\\n");
    printf ("  --batching       Maximum size of Direct Mode batches\\n");
    printf ("  --direct_heartbeat  Heartbeat timer, seconds for Direct Mode\\n");
    printf ("  --no_ack         Do not implement acknowledgments\\n");
    printf ("  --auto_crash     Auto-crash test timer, seconds\\n");
    printf ("  --auto_block     Auto-freeze test timer, seconds\\n");
    printf ("  --kernel_limit   SMT kernel limit\\n");
</method>

<method name = "cmdline parse" template = "function">
    <doc>
    Parses recognized command-line options starting with --.  Prints an error
    message and exits if the syntax is invalid.
    </doc>
    <argument name = "name" type = "char *">Name of application</argument>
    <argument name = "argc" type = "int">Argument count</argument>
    <argument name = "argv" type = "char **">Argument list</argument>
    <local>
    int
        argn;                           //  Argument number
    char
        *arg_name,
        *arg_value;
    </local>
    //
    argn = 1;
    while (argn < argc) {
        arg_name = argv [argn];
        if (streq (arg_name, "--help")) {
            self_options_help (self, name);
            exit (EXIT_SUCCESS);
        }
        else
        if (ipr_str_prefixed (argv [argn], "--")) {
            argn++;
            if (argn < argc && *argv [argn] != '-') {
                arg_value = argv [argn];
                argn++;

                //  Set property
                if (streq (arg_name, "--port"))
                    self_set_port (self, arg_value);
                else
                if (streq (arg_name, "--listen"))
                    self_set_listen (self, arg_value);
                else
                if (streq (arg_name, "--queue_timeout"))
                    self_set_queue_timeout (self, atoi (arg_value));
                else
                if (streq (arg_name, "--vhost"))
                    self_set_vhost (self, arg_value);
                else
                if (streq (arg_name, "--user"))
                    self_set_user (self, arg_value);
                else
                if (streq (arg_name, "--group"))
                    self_set_group (self, arg_value);
                else
                if (streq (arg_name, "--monitor"))
                    self_set_monitor (self, atoi (arg_value));
                else
                if (streq (arg_name, "--dump_state"))
                    self_set_dump_state (self, atoi (arg_value));
                else
                if (streq (arg_name, "--record_stats"))
                    self_set_record_stats (self, atoi (arg_value));
                else
                if (streq (arg_name, "--log_path"))
                    self_set_log_path (self, arg_value);
                else
                if (streq (arg_name, "--keep_logs"))
                    self_set_keep_logs (self, atoi (arg_value));
                else
                if (streq (arg_name, "--archive_cmd"))
                    self_set_archive_cmd (self, arg_value);
                else
                if (streq (arg_name, "--alert_log"))
                    self_set_alert_log (self, arg_value);
                else
                if (streq (arg_name, "--daily_log"))
                    self_set_daily_log (self, arg_value);
                else
                if (streq (arg_name, "--debug_log"))
                    self_set_debug_log (self, arg_value);
                else
                if (streq (arg_name, "--debug_route"))
                    self_set_debug_route (self, atoi (arg_value));
                else
                if (streq (arg_name, "--debug_queue"))
                    self_set_debug_queue (self, atoi (arg_value));
                else
                if (streq (arg_name, "--debug_peering"))
                    self_set_debug_peering (self, atoi (arg_value));
                else
                if (streq (arg_name, "--debug_console"))
                    self_set_debug_console (self, atoi (arg_value));
                else
                if (streq (arg_name, "--trace"))
                    self_set_trace (self, atoi (arg_value));
                else
                if (streq (arg_name, "--syslog"))
                    self_set_syslog (self, atoi (arg_value));
                else
                if (streq (arg_name, "--coremark_cycles"))
                    self_set_coremark_cycles (self, atoi (arg_value));
                else
                if (streq (arg_name, "--heartbeat"))
                    self_set_heartbeat (self, atoi (arg_value));
                else
                if (streq (arg_name, "--setup_timeout"))
                    self_set_setup_timeout (self, atoi (arg_value));
                else
                if (streq (arg_name, "--close_timeout"))
                    self_set_close_timeout (self, atoi (arg_value));
                else
                if (streq (arg_name, "--accept_retry_timeout"))
                    self_set_accept_retry_timeout (self, atoi (arg_value));
                else
                if (streq (arg_name, "--polling_threads"))
                    self_set_polling_threads (self, atoi (arg_value));
                else
                if (streq (arg_name, "--working_threads"))
                    self_set_working_threads (self, atoi (arg_value));
                else
                if (streq (arg_name, "--tcp_nodelay"))
                    self_set_tcp_nodelay (self, atoi (arg_value));
                else
                if (streq (arg_name, "--tcp_rcvbuf"))
                    self_set_tcp_rcvbuf (self, atoi (arg_value));
                else
                if (streq (arg_name, "--tcp_sndbuf"))
                    self_set_tcp_sndbuf (self, atoi (arg_value));
                else
                if (streq (arg_name, "--frame_max"))
                    self_set_frame_max (self, atoi (arg_value));
                else
                if (streq (arg_name, "--direct"))
                    self_set_direct (self, atoi (arg_value));
                else
                if (streq (arg_name, "--private_credit"))
                    self_set_private_credit (self, atoi (arg_value));
                else
                if (streq (arg_name, "--shared_credit"))
                    self_set_shared_credit (self, atoi (arg_value));
                else
                if (streq (arg_name, "--backup"))
                    self_set_backup (self, arg_value);
                else
                if (streq (arg_name, "--primary"))
                    self_set_primary (self, arg_value);
                else
                if (streq (arg_name, "--failover_timeout"))
                    self_set_failover_timeout (self, atoi (arg_value));
                else
                if (streq (arg_name, "--attach"))
                    self_set_attach (self, arg_value);
                else
                if (streq (arg_name, "--attach_vhost"))
                    self_set_attach_vhost (self, arg_value);
                else
                if (streq (arg_name, "--attach_login"))
                    self_set_attach_login (self, arg_value);
                else
                if (streq (arg_name, "--attach_all"))
                    self_set_attach_all (self, arg_value);
                else
                if (streq (arg_name, "--batching"))
                    self_set_batching (self, atoi (arg_value));
                else
                if (streq (arg_name, "--direct_heartbeat"))
                    self_set_direct_heartbeat (self, atoi (arg_value));
                else
                if (streq (arg_name, "--no_ack"))
                    self_set_no_ack (self, atoi (arg_value));
                else
                if (streq (arg_name, "--auto_crash"))
                    self_set_auto_crash (self, atoi (arg_value));
                else
                if (streq (arg_name, "--auto_block"))
                    self_set_auto_block (self, atoi (arg_value));
                else
                if (streq (arg_name, "--kernel_limit"))
                    self_set_kernel_limit (self, atoi (arg_value));
                else {
                    icl_console_print ("E: unrecognised option '%s'", arg_name);
                    exit (EXIT_FAILURE);
                }
            }
            else {
                icl_console_print ("E: %s option needs a parameter", arg_name);
                exit (EXIT_FAILURE);
            }
        }
        else
            argn++;
    }
    rc = argc;                          //  Return final arg count
</method>

<method name = "options help" template = "function">
    <doc>
    Prints full help for all configuration options.
    </doc>
    <argument name = "name" type = "char *">Name of application</argument>
    printf ("These are the configured options for %s\\n\\n", name);

    printf ("/config/server/port - Server port for clients\\n");
    printf ("    From command-line: --port newvalue\\n");
    printf ("    Specifies the port on which the server should open its connections.\\n");
    printf ("    Current value is '%s'. Default value is '5672'\\n", self->port);
    printf ("\\n");

    printf ("/config/server/listen - Address (local network interface) to listen on\\n");
    printf ("    From command-line: --listen newvalue\\n");
    printf ("    Specifies the network interface on which the server should listen for  \\n");
    printf ("    connections. By default this is *, meaning all interfaces. You would   \\n");
    printf ("    choose to set an address when you use OpenAMQ on a server with multiple\\n");
    printf ("    network interfaces, e.g. routing between two networks.                 \\n");
    printf ("    Current value is '%s'. Default value is '*'\\n", self->listen);
    printf ("\\n");

    printf ("/config/server/queue_timeout - Timeout for auto-deleted queues\\n");
    printf ("    From command-line: --queue_timeout newvalue\\n");
    printf ("    Specifies the delay, in seconds, after which auto-deleted queues are   \\n");
    printf ("    effectively deleted, following disconnection of their last consumer. If\\n");
    printf ("    zero, queues are deleted immediately.                                  \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->queue_timeout);
    printf ("\\n");

    printf ("/config/server/vhost - Server vhost identifier\\n");
    printf ("    From command-line: --vhost newvalue\\n");
    printf ("    Specifies the virtual host name, an arbitrary string. OpenAMQ does not  \\n");
    printf ("    implement virtual hosts but uses this string to identify servers to     \\n");
    printf ("    prevent client applications from mistakenly connecting to the wrong     \\n");
    printf ("    server. We recommend you set this on production servers and on all      \\n");
    printf ("    failover pairs. Note that the two servers in a failover pair must use an\\n");
    printf ("    identical vhost identifier.                                             \\n");
    printf ("    Current value is '%s'. Default value is '/'\\n", self->vhost);
    printf ("\\n");

    printf ("/config/server/user - User to run server as\\n");
    printf ("    From command-line: --user newvalue\\n");
    printf ("    If you specify a user and group, the server will switch to that user and\\n");
    printf ("    group after opening its port, thus dropping any privileges it previously\\n");
    printf ("    had.                                                                    \\n");
    printf ("    Current value is '%s'.\\n", self->user);
    printf ("\\n");

    printf ("/config/server/group - Group to run server as\\n");
    printf ("    From command-line: --group newvalue\\n");
    printf ("    If you specify a user and group, the server will switch to that user and\\n");
    printf ("    group after opening its port, thus dropping any privileges it previously\\n");
    printf ("    had.                                                                    \\n");
    printf ("    Current value is '%s'.\\n", self->group);
    printf ("\\n");

    printf ("/config/resources/monitor - Monitor interval, seconds\\n");
    printf ("    From command-line: --monitor newvalue\\n");
    printf ("    Specifies the interval in seconds at which the server will report its   \\n");
    printf ("    message rates. If zero, no monitoring is shown. The recommended value is\\n");
    printf ("    1, if monitoring is desired.                                            \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->monitor);
    printf ("\\n");

    printf ("/config/resources/dump_state - Dump state interval, seconds\\n");
    printf ("    From command-line: --dump_state newvalue\\n");
    printf ("    Specifies the interval at which the server will report its state. This\\n");
    printf ("    shows the number of messages, queues, consumers, etc. used by the     \\n");
    printf ("    server. If zero, no state is logged.                                  \\n");
    printf ("    Current value is %i. Default value is 60.\\n", self->dump_state);
    printf ("\\n");

    printf ("/config/resources/record_stats - Record performance statistics\\n");
    printf ("    From command-line: --record_stats newvalue\\n");
    printf ("    Specifies whether or not the server records performance statistics in a \\n");
    printf ("    format suitable for importing into a spreadsheet. If set, the server    \\n");
    printf ("    creates a file called 'amq_server_stats_(portnumber).del' which contains\\n");
    printf ("    performance statistics in a comma-delimited format. For this setting to \\n");
    printf ("    take effect, the monitor option must also be set.                       \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->record_stats);
    printf ("\\n");

    printf ("/config/logging/log_path - Active log file directory\\n");
    printf ("    From command-line: --log_path newvalue\\n");
    printf ("    Specifies the directory into which active log files are placed. To get\\n");
    printf ("    the old behaviour, set this option to 'logs'.                         \\n");
    printf ("    Current value is '%s'. Default value is '/var/log/openamq'\\n", self->log_path);
    printf ("\\n");

    printf ("/config/logging/keep_logs - Keep log files\\n");
    printf ("    From command-line: --keep_logs newvalue\\n");
    printf ("    Specifies whether or not the server should keep logs. If zero, the      \\n");
    printf ("    server will not keep logs. If 1, it will keep an alert log, a daily log,\\n");
    printf ("    and a debug log as specified.                                           \\n");
    printf ("    Current value is %i. Default value is 1.\\n", self->keep_logs);
    printf ("\\n");

    printf ("/config/logging/archive_cmd - Archive log file command\\n");
    printf ("    From command-line: --archive_cmd newvalue\\n");
    printf ("    If specified, this command is run on all archived log files. You can use\\n");
    printf ("    this option to compress archived log files, or clean up old and unwanted\\n");
    printf ("    files. When the command is run, the name of the archived log file is    \\n");
    printf ("    provided to it as a single argument.                                    \\n");
    printf ("    Current value is '%s'.\\n", self->archive_cmd);
    printf ("\\n");

    printf ("/config/logging/alert_log - Error log file name\\n");
    printf ("    From command-line: --alert_log newvalue\\n");
    printf ("    The name of the alert log file, which records all errors and warnings \\n");
    printf ("    issued by the server. Note that the server port number is always added\\n");
    printf ("    to the name of the log file.                                          \\n");
    printf ("    Current value is '%s'. Default value is 'alert.log'\\n", self->alert_log);
    printf ("\\n");

    printf ("/config/logging/daily_log - Daily log file name\\n");
    printf ("    From command-line: --daily_log newvalue\\n");
    printf ("    The name of the daily log file, which records all normal activity as   \\n");
    printf ("    well as errors. Note that the server port number is always added to the\\n");
    printf ("    name of the log file.                                                  \\n");
    printf ("    Current value is '%s'. Default value is 'daily.log'\\n", self->daily_log);
    printf ("\\n");

    printf ("/config/logging/debug_log - Debug log file name\\n");
    printf ("    From command-line: --debug_log newvalue\\n");
    printf ("    The name of the debug log file, which records all normal activity,      \\n");
    printf ("    errors, and debug trace information. Note that the server port number is\\n");
    printf ("    always added to the name of the log file.                               \\n");
    printf ("    Current value is '%s'. Default value is 'debug.log'\\n", self->debug_log);
    printf ("\\n");

    printf ("/config/logging/debug_route - Debug message routing?\\n");
    printf ("    From command-line: --debug_route newvalue\\n");
    printf ("    Specifies whether exchange routing is logged or not. Set this option   \\n");
    printf ("    when you are debugging a message routing design. For production use, we\\n");
    printf ("    recommend you do not set this option.                                  \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->debug_route);
    printf ("\\n");

    printf ("/config/logging/debug_queue - Debug queue activity?\\n");
    printf ("    From command-line: --debug_queue newvalue\\n");
    printf ("    Specifies whether queue dispatching is logged or not. Set this option  \\n");
    printf ("    when you are debugging message processing in the server. For production\\n");
    printf ("    use, we recommend you do not set this option.                          \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->debug_queue);
    printf ("\\n");

    printf ("/config/logging/debug_peering - Debug peering messages?\\n");
    printf ("    From command-line: --debug_peering newvalue\\n");
    printf ("    Specifies whether peering activity is logged or not. Set this option if\\n");
    printf ("    you need to debug exchange federation and failover. For production use,\\n");
    printf ("    we recommend you do not set this option.                               \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->debug_peering);
    printf ("\\n");

    printf ("/config/logging/debug_console - Debug console I/O?\\n");
    printf ("    From command-line: --debug_console newvalue\\n");
    printf ("    Specifies whether console activity is logged or not. Set this option  \\n");
    printf ("    when you are configuring or debugging the console. For production use,\\n");
    printf ("    we recommend you do not set this option.                              \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->debug_console);
    printf ("\\n");

    printf ("/config/logging/trace - Protocol trace level\\n");
    printf ("    From command-line: --trace newvalue\\n");
    printf ("    Specifies the protocol debug level, which can be 0 (no tracing), 1 (show\\n");
    printf ("    information and protocol methods), 2 (show protocol animation), 3 (show \\n");
    printf ("    wire-level data). You should not use any tracing on production servers  \\n");
    printf ("    except in low-volume scenarios.                                         \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->trace);
    printf ("\\n");

    printf ("/config/logging/syslog - Use syslog logging protocol\\n");
    printf ("    From command-line: --syslog newvalue\\n");
    printf ("    Specifies whether or not to use the syslog protocol for logging. By     \\n");
    printf ("    default log files are written directly to disk. If this option is set to\\n");
    printf ("    1, uses the syslog protocol for all log files. Uses a priority depending\\n");
    printf ("    on the type of log message (LOG_ERROR, LOG_INFO, LOG_DEBUG). Uses the   \\n");
    printf ("    LOG_DAEMON facility. Has no effect on Windows. Overrides the keep_logs  \\n");
    printf ("    option.                                                                 \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->syslog);
    printf ("\\n");

    printf ("/config/tuning/coremark_cycles - Duration of CoreMark test\\n");
    printf ("    From command-line: --coremark_cycles newvalue\\n");
    printf ("    Defines the duration of the automatic CoreMark performance test, in  \\n");
    printf ("    event cycles. If 0, no test will be done. Setting this too high will \\n");
    printf ("    cause the server to burn CPU at startup. A good value is between 100k\\n");
    printf ("    and 1M.                                                              \\n");
    printf ("    Current value is %i. Default value is 250000.\\n", self->coremark_cycles);
    printf ("\\n");

    printf ("/config/tuning/heartbeat - Heartbeat timer, seconds\\n");
    printf ("    From command-line: --heartbeat newvalue\\n");
    printf ("    Defines the timeout for connection heartbeating.\\n");
    printf ("    Current value is %i. Default value is 2.\\n", self->heartbeat);
    printf ("\\n");

    printf ("/config/tuning/setup_timeout - Connection setup timeout, seconds\\n");
    printf ("    From command-line: --setup_timeout newvalue\\n");
    printf ("    Defines the maximum amount of time connection negotiation may take,\\n");
    printf ("    before the connection is forcibly closed by the server.            \\n");
    printf ("    Current value is %i. Default value is 5.\\n", self->setup_timeout);
    printf ("\\n");

    printf ("/config/tuning/close_timeout - Connection close timeout, seconds\\n");
    printf ("    From command-line: --close_timeout newvalue\\n");
    printf ("    Defines the maximum amount of time the server will wait for a client to\\n");
    printf ("    send a connection.close-ok when closing the connection due to an       \\n");
    printf ("    exception.                                                             \\n");
    printf ("    Current value is %i. Default value is 5.\\n", self->close_timeout);
    printf ("\\n");

    printf ("/config/tuning/accept_retry_timeout - Timeout before retrying accept calls, seconds\\n");
    printf ("    From command-line: --accept_retry_timeout newvalue\\n");
    printf ("    Defines the amount of time the server will wait before retrying an    \\n");
    printf ("    accept call if the call failed due to running out of file descriptors.\\n");
    printf ("    Current value is %i. Default value is 60.\\n", self->accept_retry_timeout);
    printf ("\\n");

    printf ("/config/tuning/polling_threads - Number of polling OS threads\\n");
    printf ("    From command-line: --polling_threads newvalue\\n");
    printf ("    On multithreaded builds, defines the number of OS threads dedicated to\\n");
    printf ("    socket polling.                                                       \\n");
    printf ("    Current value is %i. Default value is 4.\\n", self->polling_threads);
    printf ("\\n");

    printf ("/config/tuning/working_threads - Number of working OS threads\\n");
    printf ("    From command-line: --working_threads newvalue\\n");
    printf ("    On multithreaded builds, defines the number of OS threads dedicated to\\n");
    printf ("    processing, that is, tasks other than socket polling.                 \\n");
    printf ("    Current value is %i. Default value is 4.\\n", self->working_threads);
    printf ("\\n");

    printf ("/config/tuning/tcp_nodelay - TCP/IP NODELAY option\\n");
    printf ("    From command-line: --tcp_nodelay newvalue\\n");
    printf ("    If this value is 1, socket data is written immediately, which is usually\\n");
    printf ("    good for latency. If this value is 0, data is buffered until there is a \\n");
    printf ("    full packet, which is usually good for throughput.                      \\n");
    printf ("    Current value is %i. Default value is 1.\\n", self->tcp_nodelay);
    printf ("\\n");

    printf ("/config/tuning/tcp_rcvbuf - TCP/IP receive buffer, in bytes\\n");
    printf ("    From command-line: --tcp_rcvbuf newvalue\\n");
    printf ("    If this value is greater than zero, all client connections will use the\\n");
    printf ("    specified value. Note: setting this value is delicate, do not use this \\n");
    printf ("    option unless you know what you are doing.                             \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->tcp_rcvbuf);
    printf ("\\n");

    printf ("/config/tuning/tcp_sndbuf - TCP/IP send buffer, in bytes\\n");
    printf ("    From command-line: --tcp_sndbuf newvalue\\n");
    printf ("    If this value is greater than zero, all client connections will use the\\n");
    printf ("    specified value. Note: setting this value is delicate, do not use this \\n");
    printf ("    option unless you know what you are doing.                             \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->tcp_sndbuf);
    printf ("\\n");

    printf ("/config/tuning/frame_max - Maximum size of AMQP content frames\\n");
    printf ("    From command-line: --frame_max newvalue\\n");
    printf ("    Defines the maximum frame size the server will accept. Larger frame     \\n");
    printf ("    sizes are useful for applications that create very large message headers\\n");
    printf ("    but will cause congestion on multi-channel connections.                 \\n");
    printf ("    Current value is %i. Default value is 32768.\\n", self->frame_max);
    printf ("\\n");

    printf ("/config/tuning/direct - Enables Direct Mode for client connections\\n");
    printf ("    From command-line: --direct newvalue\\n");
    printf ("    If set to 1, new connections will by default use Direct Mode.   \\n");
    printf ("    Applications can override this by setting the connection->direct\\n");
    printf ("    property on new connections.                                    \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->direct);
    printf ("\\n");

    printf ("/config/tuning/private_credit - Credit window for private queues\\n");
    printf ("    From command-line: --private_credit newvalue\\n");
    printf ("    Defines the credit window for private queues. The credit window        \\n");
    printf ("    regulates the flow of messages internally. A higher value will move    \\n");
    printf ("    messages faster off private message queues and into the protocol       \\n");
    printf ("    transport threads. This will increase server memory consumption (before\\n");
    printf ("    configured queue limits are applied) but can improve performance. For  \\n");
    printf ("    high performance applications we recommend using Direct Mode.          \\n");
    printf ("    Current value is %i. Default value is 1024.\\n", self->private_credit);
    printf ("\\n");

    printf ("/config/tuning/shared_credit - Credit window for shared queues\\n");
    printf ("    From command-line: --shared_credit newvalue\\n");
    printf ("    Defines the credit window for shared queues. The credit window regulates\\n");
    printf ("    the flow of messages internally. The default value of 1 will provide the\\n");
    printf ("    best response to blocked/slow clients working on shared queues.         \\n");
    printf ("    Current value is %i. Default value is 1.\\n", self->shared_credit);
    printf ("\\n");

    printf ("/config/failover/backup - Failover backup host:port\\n");
    printf ("    From command-line: --backup newvalue\\n");
    printf ("    Used when running the primary server, specifies the failover backup \\n");
    printf ("    server for the high-availability pair. Use the internet name of the \\n");
    printf ("    backup server as 'host' or 'host:port' if it is not running on port \\n");
    printf ("    5672. Do not specify this option together with the 'primary' option.\\n");
    printf ("    Current value is '%s'. Default value is ''\\n", self->backup);
    printf ("\\n");

    printf ("/config/failover/primary - Failover primary host:port\\n");
    printf ("    From command-line: --primary newvalue\\n");
    printf ("    Used when running the backup server, specifies the failover primary \\n");
    printf ("    server for the high-availability pair. Use the internet name of the \\n");
    printf ("    primary server as 'host' or 'host:port' if it is not running on port\\n");
    printf ("    5672. Do not specify this option together with the 'backup' option. \\n");
    printf ("    Current value is '%s'. Default value is ''\\n", self->primary);
    printf ("\\n");

    printf ("/config/failover/timeout - Failover timeout, in seconds\\n");
    printf ("    From command-line: --failover_timeout newvalue\\n");
    printf ("    Specifies the delay in seconds after which the backup peer will become \\n");
    printf ("    the primary peer. This switch over will happen only if and when an     \\n");
    printf ("    application connects to the backup peer after the failover timeout has \\n");
    printf ("    expired. Reducing this value will allow failover to happen faster but  \\n");
    printf ("    will increase the risk of unnecessary failover due to transient network\\n");
    printf ("    issues.                                                                \\n");
    printf ("    Current value is %i. Default value is 5.\\n", self->failover_timeout);
    printf ("\\n");

    printf ("/config/federation/attach - Enable auto-federation to specified host\\n");
    printf ("    From command-line: --attach newvalue\\n");
    printf ("    If specified, the server will auto-federate to the specified parent    \\n");
    printf ("    OpenAMQ server. This federates three exchanges: amq.service (a direct  \\n");
    printf ("    exchange) using a service federation; amq.data (a topic exchange) using\\n");
    printf ("    a fanout federation; and amq.dataex (a headers exchange) using a fanout\\n");
    printf ("    exchange. This gives you an instant enterprise service bus (ESB) based \\n");
    printf ("    on a spoke-and-hub model. You can fine-tune auto-federation using the  \\n");
    printf ("    --attach-login and --attach-vhost options.                             \\n");
    printf ("    Current value is '%s'. Default value is ''\\n", self->attach);
    printf ("\\n");

    printf ("/config/federation/attach_vhost - Auto-federation virtual host name\\n");
    printf ("    From command-line: --attach_vhost newvalue\\n");
    printf ("    Specifies the auto-federation vhost name, an arbitrary string that will\\n");
    printf ("    be used when connecting to the parent server. This must match the vhost\\n");
    printf ("    setting of the parent server.                                          \\n");
    printf ("    Current value is '%s'. Default value is '/'\\n", self->attach_vhost);
    printf ("\\n");

    printf ("/config/federation/attach_login - Auto-federation login user name\\n");
    printf ("    From command-line: --attach_login newvalue\\n");
    printf ("    Specifies the user name to be used when logging in. You do not need to\\n");
    printf ("    specify a password, it is taken from the security section.            \\n");
    printf ("    Current value is '%s'. Default value is 'peering'\\n", self->attach_login);
    printf ("\\n");

    printf ("/config/federation/attach_all - Auto-federate exchanges by pattern\\n");
    printf ("    From command-line: --attach_all newvalue\\n");
    printf ("    If set, the server will auto-federate all exchanges that match the      \\n");
    printf ("    specified pattern which can include * and ? to mean zero or more, or a  \\n");
    printf ("    single arbitrary character. You can use naming conventions to federate  \\n");
    printf ("    specific groups of exchanges. Put quotes around wildcards to avoid shell\\n");
    printf ("    expansion.                                                              \\n");
    printf ("    Current value is '%s'. Default value is ''\\n", self->attach_all);
    printf ("\\n");

    printf ("/config/direct/batching - Maximum size of Direct Mode batches\\n");
    printf ("    From command-line: --batching newvalue\\n");
    printf ("    Defines the maximum batch size for Direct Mode opportunistic batching on\\n");
    printf ("    message sends. Setting this higher will improve throughput, and usually \\n");
    printf ("    with lower latency, but will cause higher memory consumption. Setting   \\n");
    printf ("    this to zero will switch off batching. Any value less than 2048 is      \\n");
    printf ("    treated as zero.                                                        \\n");
    printf ("    Current value is %i. Default value is 32768.\\n", self->batching);
    printf ("\\n");

    printf ("/config/direct/heartbeat - Heartbeat timer, seconds for Direct Mode\\n");
    printf ("    From command-line: --direct_heartbeat newvalue\\n");
    printf ("    Defines the timeout for Direct Mode connection heartbeating.\\n");
    printf ("    Current value is %i. Default value is 2.\\n", self->direct_heartbeat);
    printf ("\\n");

    printf ("/config/compatibility/no_ack - Do not implement acknowledgments\\n");
    printf ("    From command-line: --no_ack newvalue\\n");
    printf ("    Provides backwards compatibility with earlier versions of OpenAMQ for  \\n");
    printf ("    use with shared queues. From 1.4b4 and 1.3d0 onwards OpenAMQ treats the\\n");
    printf ("    Basic.Consume no-ack flag as meaningful, whereas prior versions ignored\\n");
    printf ("    this flag. Applications that do not set this flag when consuming from  \\n");
    printf ("    shared queues must now issue Basic.Ack for each message they received. \\n");
    printf ("    The --no-ack option restores the prior way of working and allows old   \\n");
    printf ("    applications to work unchanged.                                        \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->no_ack);
    printf ("\\n");

    printf ("/config/internal/auto_crash - Auto-crash test timer, seconds\\n");
    printf ("    From command-line: --auto_crash newvalue\\n");
    printf ("    If set, the server will crash at irregular intervals, being some random\\n");
    printf ("    point within the number of seconds specified. This is used specifically\\n");
    printf ("    to test applications for failover and robustness. Set to zero for all  \\n");
    printf ("    real usage.                                                            \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->auto_crash);
    printf ("\\n");

    printf ("/config/internal/auto_block - Auto-freeze test timer, seconds\\n");
    printf ("    From command-line: --auto_block newvalue\\n");
    printf ("    If set, the server will block at irregular intervals, being some random\\n");
    printf ("    point within the number of seconds specified. This is used specifically\\n");
    printf ("    to test applications for failover and robustness. Set to zero for all  \\n");
    printf ("    real usage.                                                            \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->auto_block);
    printf ("\\n");

    printf ("/config/internal/kernel_limit - SMT kernel limit\\n");
    printf ("    From command-line: --kernel_limit newvalue\\n");
    printf ("    Sets an action limit for the SMT kernel: after this many steps it will \\n");
    printf ("    exit. Use this to break the server for failure testing. Set to zero for\\n");
    printf ("    all real usage.                                                        \\n");
    printf ("    Current value is %i. Default value is 0.\\n", self->kernel_limit);
    printf ("\\n");
</method>

<method name = "set port" template = "function">
    <argument name = "port" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/server", "port", port);
    port = ipr_config_getp (self->table, "/config/server", "port", NULL);
    assert (port);
    self->port = port;
</method>

<method name = "port" return = "port">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "port" type = "char *" />
    //
    if (self)
        port = self->port;
    else
        port = "5672";
</method>

<method name = "set listen" template = "function">
    <argument name = "listen" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/server", "listen", listen);
    listen = ipr_config_getp (self->table, "/config/server", "listen", NULL);
    assert (listen);
    self->listen = listen;
</method>

<method name = "listen" return = "listen">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "listen" type = "char *" />
    //
    if (self)
        listen = self->listen;
    else
        listen = "*";
</method>

<method name = "set queue_timeout" template = "function">
    <argument name = "queue_timeout" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", queue_timeout);
    ipr_config_putp (self->table, "/config/server", "queue_timeout", strvalue);
    self->queue_timeout = queue_timeout;
</method>

<method name = "queue_timeout" return = "queue_timeout">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "queue_timeout" type = "int" />
    //
    if (self)
        queue_timeout = self->queue_timeout;
    else
        queue_timeout = 0;
</method>

<method name = "set vhost" template = "function">
    <argument name = "vhost" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/server", "vhost", vhost);
    vhost = ipr_config_getp (self->table, "/config/server", "vhost", NULL);
    assert (vhost);
    self->vhost = vhost;
</method>

<method name = "vhost" return = "vhost">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "vhost" type = "char *" />
    //
    if (self)
        vhost = self->vhost;
    else
        vhost = "/";
</method>

<method name = "set user" template = "function">
    <argument name = "user" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/server", "user", user);
    user = ipr_config_getp (self->table, "/config/server", "user", NULL);
    assert (user);
    self->user = user;
</method>

<method name = "user" return = "user">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "user" type = "char *" />
    //
    if (self)
        user = self->user;
    else
        user = "";
</method>

<method name = "set group" template = "function">
    <argument name = "group" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/server", "group", group);
    group = ipr_config_getp (self->table, "/config/server", "group", NULL);
    assert (group);
    self->group = group;
</method>

<method name = "group" return = "group">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "group" type = "char *" />
    //
    if (self)
        group = self->group;
    else
        group = "";
</method>

<method name = "set monitor" template = "function">
    <argument name = "monitor" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", monitor);
    ipr_config_putp (self->table, "/config/resources", "monitor", strvalue);
    self->monitor = monitor;
</method>

<method name = "monitor" return = "monitor">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "monitor" type = "int" />
    //
    if (self)
        monitor = self->monitor;
    else
        monitor = 0;
</method>

<method name = "set dump_state" template = "function">
    <argument name = "dump_state" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", dump_state);
    ipr_config_putp (self->table, "/config/resources", "dump_state", strvalue);
    self->dump_state = dump_state;
</method>

<method name = "dump_state" return = "dump_state">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "dump_state" type = "int" />
    //
    if (self)
        dump_state = self->dump_state;
    else
        dump_state = 60;
</method>

<method name = "set record_stats" template = "function">
    <argument name = "record_stats" type = "Bool" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", record_stats);
    ipr_config_putp (self->table, "/config/resources", "record_stats", strvalue);
    self->record_stats = record_stats;
</method>

<method name = "record_stats" return = "record_stats">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "record_stats" type = "Bool" />
    //
    if (self)
        record_stats = self->record_stats;
    else
        record_stats = 0;
</method>

<method name = "set log_path" template = "function">
    <argument name = "log_path" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/logging", "log_path", log_path);
    log_path = ipr_config_getp (self->table, "/config/logging", "log_path", NULL);
    assert (log_path);
    self->log_path = log_path;
</method>

<method name = "log_path" return = "log_path">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "log_path" type = "char *" />
    //
    if (self)
        log_path = self->log_path;
    else
        log_path = "/var/log/openamq";
</method>

<method name = "set keep_logs" template = "function">
    <argument name = "keep_logs" type = "Bool" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", keep_logs);
    ipr_config_putp (self->table, "/config/logging", "keep_logs", strvalue);
    self->keep_logs = keep_logs;
</method>

<method name = "keep_logs" return = "keep_logs">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "keep_logs" type = "Bool" />
    //
    if (self)
        keep_logs = self->keep_logs;
    else
        keep_logs = 1;
</method>

<method name = "set archive_cmd" template = "function">
    <argument name = "archive_cmd" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/logging", "archive_cmd", archive_cmd);
    archive_cmd = ipr_config_getp (self->table, "/config/logging", "archive_cmd", NULL);
    assert (archive_cmd);
    self->archive_cmd = archive_cmd;
</method>

<method name = "archive_cmd" return = "archive_cmd">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "archive_cmd" type = "char *" />
    //
    if (self)
        archive_cmd = self->archive_cmd;
    else
        archive_cmd = "";
</method>

<method name = "set alert_log" template = "function">
    <argument name = "alert_log" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/logging", "alert_log", alert_log);
    alert_log = ipr_config_getp (self->table, "/config/logging", "alert_log", NULL);
    assert (alert_log);
    self->alert_log = alert_log;
</method>

<method name = "alert_log" return = "alert_log">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "alert_log" type = "char *" />
    //
    if (self)
        alert_log = self->alert_log;
    else
        alert_log = "alert.log";
</method>

<method name = "set daily_log" template = "function">
    <argument name = "daily_log" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/logging", "daily_log", daily_log);
    daily_log = ipr_config_getp (self->table, "/config/logging", "daily_log", NULL);
    assert (daily_log);
    self->daily_log = daily_log;
</method>

<method name = "daily_log" return = "daily_log">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "daily_log" type = "char *" />
    //
    if (self)
        daily_log = self->daily_log;
    else
        daily_log = "daily.log";
</method>

<method name = "set debug_log" template = "function">
    <argument name = "debug_log" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/logging", "debug_log", debug_log);
    debug_log = ipr_config_getp (self->table, "/config/logging", "debug_log", NULL);
    assert (debug_log);
    self->debug_log = debug_log;
</method>

<method name = "debug_log" return = "debug_log">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "debug_log" type = "char *" />
    //
    if (self)
        debug_log = self->debug_log;
    else
        debug_log = "debug.log";
</method>

<method name = "set debug_route" template = "function">
    <argument name = "debug_route" type = "Bool" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", debug_route);
    ipr_config_putp (self->table, "/config/logging", "debug_route", strvalue);
    self->debug_route = debug_route;
</method>

<method name = "debug_route" return = "debug_route">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "debug_route" type = "Bool" />
    //
    if (self)
        debug_route = self->debug_route;
    else
        debug_route = 0;
</method>

<method name = "set debug_queue" template = "function">
    <argument name = "debug_queue" type = "Bool" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", debug_queue);
    ipr_config_putp (self->table, "/config/logging", "debug_queue", strvalue);
    self->debug_queue = debug_queue;
</method>

<method name = "debug_queue" return = "debug_queue">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "debug_queue" type = "Bool" />
    //
    if (self)
        debug_queue = self->debug_queue;
    else
        debug_queue = 0;
</method>

<method name = "set debug_peering" template = "function">
    <argument name = "debug_peering" type = "Bool" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", debug_peering);
    ipr_config_putp (self->table, "/config/logging", "debug_peering", strvalue);
    self->debug_peering = debug_peering;
</method>

<method name = "debug_peering" return = "debug_peering">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "debug_peering" type = "Bool" />
    //
    if (self)
        debug_peering = self->debug_peering;
    else
        debug_peering = 0;
</method>

<method name = "set debug_console" template = "function">
    <argument name = "debug_console" type = "Bool" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", debug_console);
    ipr_config_putp (self->table, "/config/logging", "debug_console", strvalue);
    self->debug_console = debug_console;
</method>

<method name = "debug_console" return = "debug_console">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "debug_console" type = "Bool" />
    //
    if (self)
        debug_console = self->debug_console;
    else
        debug_console = 0;
</method>

<method name = "set trace" template = "function">
    <argument name = "trace" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", trace);
    ipr_config_putp (self->table, "/config/logging", "trace", strvalue);
    self->trace = trace;
</method>

<method name = "trace" return = "trace">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "trace" type = "int" />
    //
    if (self)
        trace = self->trace;
    else
        trace = 0;
</method>

<method name = "set syslog" template = "function">
    <argument name = "syslog" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", syslog);
    ipr_config_putp (self->table, "/config/logging", "syslog", strvalue);
    self->syslog = syslog;
</method>

<method name = "syslog" return = "syslog">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "syslog" type = "int" />
    //
    if (self)
        syslog = self->syslog;
    else
        syslog = 0;
</method>

<method name = "set coremark_cycles" template = "function">
    <argument name = "coremark_cycles" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", coremark_cycles);
    ipr_config_putp (self->table, "/config/tuning", "coremark_cycles", strvalue);
    self->coremark_cycles = coremark_cycles;
</method>

<method name = "coremark_cycles" return = "coremark_cycles">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "coremark_cycles" type = "int" />
    //
    if (self)
        coremark_cycles = self->coremark_cycles;
    else
        coremark_cycles = 250000;
</method>

<method name = "set heartbeat" template = "function">
    <argument name = "heartbeat" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", heartbeat);
    ipr_config_putp (self->table, "/config/tuning", "heartbeat", strvalue);
    self->heartbeat = heartbeat;
</method>

<method name = "heartbeat" return = "heartbeat">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "heartbeat" type = "int" />
    //
    if (self)
        heartbeat = self->heartbeat;
    else
        heartbeat = 2;
</method>

<method name = "set setup_timeout" template = "function">
    <argument name = "setup_timeout" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", setup_timeout);
    ipr_config_putp (self->table, "/config/tuning", "setup_timeout", strvalue);
    self->setup_timeout = setup_timeout;
</method>

<method name = "setup_timeout" return = "setup_timeout">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "setup_timeout" type = "int" />
    //
    if (self)
        setup_timeout = self->setup_timeout;
    else
        setup_timeout = 5;
</method>

<method name = "set close_timeout" template = "function">
    <argument name = "close_timeout" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", close_timeout);
    ipr_config_putp (self->table, "/config/tuning", "close_timeout", strvalue);
    self->close_timeout = close_timeout;
</method>

<method name = "close_timeout" return = "close_timeout">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "close_timeout" type = "int" />
    //
    if (self)
        close_timeout = self->close_timeout;
    else
        close_timeout = 5;
</method>

<method name = "set accept_retry_timeout" template = "function">
    <argument name = "accept_retry_timeout" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    if (accept_retry_timeout < 1) {
        icl_console_print ("W: &lt;command line&gt;: illegal value %d for accept_retry_timeout, using %d",
            accept_retry_timeout, 1);
        accept_retry_timeout = 1;
    }
    icl_shortstr_fmt (strvalue, "%i", accept_retry_timeout);
    ipr_config_putp (self->table, "/config/tuning", "accept_retry_timeout", strvalue);
    self->accept_retry_timeout = accept_retry_timeout;
</method>

<method name = "accept_retry_timeout" return = "accept_retry_timeout">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "accept_retry_timeout" type = "int" />
    //
    if (self)
        accept_retry_timeout = self->accept_retry_timeout;
    else
        accept_retry_timeout = 60;
</method>

<method name = "set polling_threads" template = "function">
    <argument name = "polling_threads" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", polling_threads);
    ipr_config_putp (self->table, "/config/tuning", "polling_threads", strvalue);
    self->polling_threads = polling_threads;
</method>

<method name = "polling_threads" return = "polling_threads">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "polling_threads" type = "int" />
    //
    if (self)
        polling_threads = self->polling_threads;
    else
        polling_threads = 4;
</method>

<method name = "set working_threads" template = "function">
    <argument name = "working_threads" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", working_threads);
    ipr_config_putp (self->table, "/config/tuning", "working_threads", strvalue);
    self->working_threads = working_threads;
</method>

<method name = "working_threads" return = "working_threads">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "working_threads" type = "int" />
    //
    if (self)
        working_threads = self->working_threads;
    else
        working_threads = 4;
</method>

<method name = "set tcp_nodelay" template = "function">
    <argument name = "tcp_nodelay" type = "Bool" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", tcp_nodelay);
    ipr_config_putp (self->table, "/config/tuning", "tcp_nodelay", strvalue);
    self->tcp_nodelay = tcp_nodelay;
</method>

<method name = "tcp_nodelay" return = "tcp_nodelay">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "tcp_nodelay" type = "Bool" />
    //
    if (self)
        tcp_nodelay = self->tcp_nodelay;
    else
        tcp_nodelay = 1;
</method>

<method name = "set tcp_rcvbuf" template = "function">
    <argument name = "tcp_rcvbuf" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", tcp_rcvbuf);
    ipr_config_putp (self->table, "/config/tuning", "tcp_rcvbuf", strvalue);
    self->tcp_rcvbuf = tcp_rcvbuf;
</method>

<method name = "tcp_rcvbuf" return = "tcp_rcvbuf">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "tcp_rcvbuf" type = "int" />
    //
    if (self)
        tcp_rcvbuf = self->tcp_rcvbuf;
    else
        tcp_rcvbuf = 0;
</method>

<method name = "set tcp_sndbuf" template = "function">
    <argument name = "tcp_sndbuf" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", tcp_sndbuf);
    ipr_config_putp (self->table, "/config/tuning", "tcp_sndbuf", strvalue);
    self->tcp_sndbuf = tcp_sndbuf;
</method>

<method name = "tcp_sndbuf" return = "tcp_sndbuf">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "tcp_sndbuf" type = "int" />
    //
    if (self)
        tcp_sndbuf = self->tcp_sndbuf;
    else
        tcp_sndbuf = 0;
</method>

<method name = "set frame_max" template = "function">
    <argument name = "frame_max" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    if (frame_max < 2048) {
        icl_console_print ("W: &lt;command line&gt;: illegal value %d for frame_max, using %d",
            frame_max, 2048);
        frame_max = 2048;
    }
    if (frame_max > 2097152) {
        icl_console_print ("W: &lt;command line&gt;: illegal value %d for frame_max, using %d",
            frame_max, 2097152);
        frame_max = 2097152;
    }
    icl_shortstr_fmt (strvalue, "%i", frame_max);
    ipr_config_putp (self->table, "/config/tuning", "frame_max", strvalue);
    self->frame_max = frame_max;
</method>

<method name = "frame_max" return = "frame_max">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "frame_max" type = "int" />
    //
    if (self)
        frame_max = self->frame_max;
    else
        frame_max = 32768;
</method>

<method name = "set direct" template = "function">
    <argument name = "direct" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", direct);
    ipr_config_putp (self->table, "/config/tuning", "direct", strvalue);
    self->direct = direct;
</method>

<method name = "direct" return = "direct">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "direct" type = "int" />
    //
    if (self)
        direct = self->direct;
    else
        direct = 0;
</method>

<method name = "set private_credit" template = "function">
    <argument name = "private_credit" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", private_credit);
    ipr_config_putp (self->table, "/config/tuning", "private_credit", strvalue);
    self->private_credit = private_credit;
</method>

<method name = "private_credit" return = "private_credit">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "private_credit" type = "int" />
    //
    if (self)
        private_credit = self->private_credit;
    else
        private_credit = 1024;
</method>

<method name = "set shared_credit" template = "function">
    <argument name = "shared_credit" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", shared_credit);
    ipr_config_putp (self->table, "/config/tuning", "shared_credit", strvalue);
    self->shared_credit = shared_credit;
</method>

<method name = "shared_credit" return = "shared_credit">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "shared_credit" type = "int" />
    //
    if (self)
        shared_credit = self->shared_credit;
    else
        shared_credit = 1;
</method>

<method name = "set backup" template = "function">
    <argument name = "backup" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/failover", "backup", backup);
    backup = ipr_config_getp (self->table, "/config/failover", "backup", NULL);
    assert (backup);
    self->backup = backup;
</method>

<method name = "backup" return = "backup">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "backup" type = "char *" />
    //
    if (self)
        backup = self->backup;
    else
        backup = "";
</method>

<method name = "set primary" template = "function">
    <argument name = "primary" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/failover", "primary", primary);
    primary = ipr_config_getp (self->table, "/config/failover", "primary", NULL);
    assert (primary);
    self->primary = primary;
</method>

<method name = "primary" return = "primary">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "primary" type = "char *" />
    //
    if (self)
        primary = self->primary;
    else
        primary = "";
</method>

<method name = "set failover_timeout" template = "function">
    <argument name = "failover_timeout" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    if (failover_timeout < 1) {
        icl_console_print ("W: &lt;command line&gt;: illegal value %d for failover_timeout, using %d",
            failover_timeout, 1);
        failover_timeout = 1;
    }
    if (failover_timeout > 60) {
        icl_console_print ("W: &lt;command line&gt;: illegal value %d for failover_timeout, using %d",
            failover_timeout, 60);
        failover_timeout = 60;
    }
    icl_shortstr_fmt (strvalue, "%i", failover_timeout);
    ipr_config_putp (self->table, "/config/failover", "timeout", strvalue);
    self->failover_timeout = failover_timeout;
</method>

<method name = "failover_timeout" return = "failover_timeout">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "failover_timeout" type = "int" />
    //
    if (self)
        failover_timeout = self->failover_timeout;
    else
        failover_timeout = 5;
</method>

<method name = "set attach" template = "function">
    <argument name = "attach" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/federation", "attach", attach);
    attach = ipr_config_getp (self->table, "/config/federation", "attach", NULL);
    assert (attach);
    self->attach = attach;
</method>

<method name = "attach" return = "attach">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "attach" type = "char *" />
    //
    if (self)
        attach = self->attach;
    else
        attach = "";
</method>

<method name = "set attach_vhost" template = "function">
    <argument name = "attach_vhost" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/federation", "attach_vhost", attach_vhost);
    attach_vhost = ipr_config_getp (self->table, "/config/federation", "attach_vhost", NULL);
    assert (attach_vhost);
    self->attach_vhost = attach_vhost;
</method>

<method name = "attach_vhost" return = "attach_vhost">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "attach_vhost" type = "char *" />
    //
    if (self)
        attach_vhost = self->attach_vhost;
    else
        attach_vhost = "/";
</method>

<method name = "set attach_login" template = "function">
    <argument name = "attach_login" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/federation", "attach_login", attach_login);
    attach_login = ipr_config_getp (self->table, "/config/federation", "attach_login", NULL);
    assert (attach_login);
    self->attach_login = attach_login;
</method>

<method name = "attach_login" return = "attach_login">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "attach_login" type = "char *" />
    //
    if (self)
        attach_login = self->attach_login;
    else
        attach_login = "peering";
</method>

<method name = "set attach_all" template = "function">
    <argument name = "attach_all" type = "char *" />
    <inherit name = "wrlock" />
    ipr_config_putp (self->table, "/config/federation", "attach_all", attach_all);
    attach_all = ipr_config_getp (self->table, "/config/federation", "attach_all", NULL);
    assert (attach_all);
    self->attach_all = attach_all;
</method>

<method name = "attach_all" return = "attach_all">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "attach_all" type = "char *" />
    //
    if (self)
        attach_all = self->attach_all;
    else
        attach_all = "";
</method>

<method name = "set batching" template = "function">
    <argument name = "batching" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    if (batching > 2097152) {
        icl_console_print ("W: &lt;command line&gt;: illegal value %d for batching, using %d",
            batching, 2097152);
        batching = 2097152;
    }
    icl_shortstr_fmt (strvalue, "%i", batching);
    ipr_config_putp (self->table, "/config/direct", "batching", strvalue);
    self->batching = batching;
</method>

<method name = "batching" return = "batching">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "batching" type = "int" />
    //
    if (self)
        batching = self->batching;
    else
        batching = 32768;
</method>

<method name = "set direct_heartbeat" template = "function">
    <argument name = "direct_heartbeat" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", direct_heartbeat);
    ipr_config_putp (self->table, "/config/direct", "heartbeat", strvalue);
    self->direct_heartbeat = direct_heartbeat;
</method>

<method name = "direct_heartbeat" return = "direct_heartbeat">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "direct_heartbeat" type = "int" />
    //
    if (self)
        direct_heartbeat = self->direct_heartbeat;
    else
        direct_heartbeat = 2;
</method>

<method name = "set no_ack" template = "function">
    <argument name = "no_ack" type = "Bool" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", no_ack);
    ipr_config_putp (self->table, "/config/compatibility", "no_ack", strvalue);
    self->no_ack = no_ack;
</method>

<method name = "no_ack" return = "no_ack">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "no_ack" type = "Bool" />
    //
    if (self)
        no_ack = self->no_ack;
    else
        no_ack = 0;
</method>

<method name = "set auto_crash" template = "function">
    <argument name = "auto_crash" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", auto_crash);
    ipr_config_putp (self->table, "/config/internal", "auto_crash", strvalue);
    self->auto_crash = auto_crash;
</method>

<method name = "auto_crash" return = "auto_crash">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "auto_crash" type = "int" />
    //
    if (self)
        auto_crash = self->auto_crash;
    else
        auto_crash = 0;
</method>

<method name = "set auto_block" template = "function">
    <argument name = "auto_block" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", auto_block);
    ipr_config_putp (self->table, "/config/internal", "auto_block", strvalue);
    self->auto_block = auto_block;
</method>

<method name = "auto_block" return = "auto_block">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "auto_block" type = "int" />
    //
    if (self)
        auto_block = self->auto_block;
    else
        auto_block = 0;
</method>

<method name = "set kernel_limit" template = "function">
    <argument name = "kernel_limit" type = "int" />
    <inherit name = "wrlock" />
    <local>
    icl_shortstr_t
        strvalue;
    </local>
    //
    icl_shortstr_fmt (strvalue, "%i", kernel_limit);
    ipr_config_putp (self->table, "/config/internal", "kernel_limit", strvalue);
    self->kernel_limit = kernel_limit;
</method>

<method name = "kernel_limit" return = "kernel_limit">
    <argument name = "self" type = "$(selftype) *">Reference to self</argument>
    <declare name = "kernel_limit" type = "int" />
    //
    if (self)
        kernel_limit = self->kernel_limit;
    else
        kernel_limit = 0;
</method>

<method name = "dump log" template = "function">
    <doc>
    Dump current option values to an smt_log file.
    </doc>
    <argument name = "logfile" type = "smt_log_t *">Log file to dump to</argument>
    smt_log_print (logfile, "*******************  Configuration Settings  ********************");
    smt_log_print (logfile, "port=%s", self->port);
    smt_log_print (logfile, "listen=%s", self->listen);
    smt_log_print (logfile, "queue_timeout=%i", self->queue_timeout);
    smt_log_print (logfile, "vhost=%s", self->vhost);
    smt_log_print (logfile, "user=%s", self->user);
    smt_log_print (logfile, "group=%s", self->group);
    smt_log_print (logfile, "monitor=%i", self->monitor);
    smt_log_print (logfile, "dump_state=%i", self->dump_state);
    smt_log_print (logfile, "record_stats=%i", self->record_stats);
    smt_log_print (logfile, "log_path=%s", self->log_path);
    smt_log_print (logfile, "keep_logs=%i", self->keep_logs);
    smt_log_print (logfile, "archive_cmd=%s", self->archive_cmd);
    smt_log_print (logfile, "alert_log=%s", self->alert_log);
    smt_log_print (logfile, "daily_log=%s", self->daily_log);
    smt_log_print (logfile, "debug_log=%s", self->debug_log);
    smt_log_print (logfile, "debug_route=%i", self->debug_route);
    smt_log_print (logfile, "debug_queue=%i", self->debug_queue);
    smt_log_print (logfile, "debug_peering=%i", self->debug_peering);
    smt_log_print (logfile, "debug_console=%i", self->debug_console);
    smt_log_print (logfile, "trace=%i", self->trace);
    smt_log_print (logfile, "syslog=%i", self->syslog);
    smt_log_print (logfile, "coremark_cycles=%i", self->coremark_cycles);
    smt_log_print (logfile, "heartbeat=%i", self->heartbeat);
    smt_log_print (logfile, "setup_timeout=%i", self->setup_timeout);
    smt_log_print (logfile, "close_timeout=%i", self->close_timeout);
    smt_log_print (logfile, "accept_retry_timeout=%i", self->accept_retry_timeout);
    smt_log_print (logfile, "polling_threads=%i", self->polling_threads);
    smt_log_print (logfile, "working_threads=%i", self->working_threads);
    smt_log_print (logfile, "tcp_nodelay=%i", self->tcp_nodelay);
    smt_log_print (logfile, "tcp_rcvbuf=%i", self->tcp_rcvbuf);
    smt_log_print (logfile, "tcp_sndbuf=%i", self->tcp_sndbuf);
    smt_log_print (logfile, "frame_max=%i", self->frame_max);
    smt_log_print (logfile, "direct=%i", self->direct);
    smt_log_print (logfile, "private_credit=%i", self->private_credit);
    smt_log_print (logfile, "shared_credit=%i", self->shared_credit);
    smt_log_print (logfile, "backup=%s", self->backup);
    smt_log_print (logfile, "primary=%s", self->primary);
    smt_log_print (logfile, "failover_timeout=%i", self->failover_timeout);
    smt_log_print (logfile, "attach=%s", self->attach);
    smt_log_print (logfile, "attach_vhost=%s", self->attach_vhost);
    smt_log_print (logfile, "attach_login=%s", self->attach_login);
    smt_log_print (logfile, "attach_all=%s", self->attach_all);
    smt_log_print (logfile, "batching=%i", self->batching);
    smt_log_print (logfile, "direct_heartbeat=%i", self->direct_heartbeat);
    smt_log_print (logfile, "no_ack=%i", self->no_ack);
    smt_log_print (logfile, "auto_crash=%i", self->auto_crash);
    smt_log_print (logfile, "auto_block=%i", self->auto_block);
    smt_log_print (logfile, "kernel_limit=%i", self->kernel_limit);
    smt_log_print (logfile, "");
</method>

<private name = "header">
static void s_validate_items ($(selftype) *self);
static void s_get_properties ($(selftype) *self);
</private>

<private name = "body">
static void s_validate_items ($(selftype) *self)
{
    char
        *item_name;

    //  Locate first child and check all items for validity
    ipr_config_locate (self->table, "/config/+", "");
    while (self->table->located) {
        item_name = ipr_config_item (self->table);
        if (streq (item_name, "echo"))
            icl_console_print ("I: %s: %s", self->filename, ipr_config_value (self->table));
        else
        if (strneq (item_name, "server")
        && strneq (item_name, "resources")
        && strneq (item_name, "logging")
        && strneq (item_name, "tuning")
        && strneq (item_name, "failover")
        && strneq (item_name, "federation")
        && strneq (item_name, "direct")
        && strneq (item_name, "compatibility")
        && strneq (item_name, "internal")
        && strneq (item_name, "queue_profile")
        && strneq (item_name, "security")
        && strneq (item_name, "federate"))
            icl_console_print ("W: %s: unknown item '%s', ignored",
                self->filename, item_name);
        ipr_config_next (self->table);
    }
}

static void s_get_properties ($(selftype) *self)
{
    char
        *value;                         //  Configured value

    //  All properties on server path
    ipr_config_locate (self->table, "/config/server", NULL);

    //  Get port property from config file or built-in defaults
    value = ipr_config_get (self->table, "port", NULL);
    if (value)
        self->port = value;
    else
        self->port = "5672";

    //  Get listen property from config file or built-in defaults
    value = ipr_config_get (self->table, "listen", NULL);
    if (value)
        self->listen = value;
    else
        self->listen = "*";

    //  Get queue_timeout property from config file or built-in defaults
    value = ipr_config_get (self->table, "queue_timeout", NULL);
    if (value)
        self->queue_timeout = (int) atol (value);
    else
        self->queue_timeout = 0;

    //  Get vhost property from config file or built-in defaults
    value = ipr_config_get (self->table, "vhost", NULL);
    if (value)
        self->vhost = value;
    else
        self->vhost = "/";

    //  Get user property from config file or built-in defaults
    value = ipr_config_get (self->table, "user", NULL);
    if (value)
        self->user = value;
    else
        self->user = "";

    //  Get group property from config file or built-in defaults
    value = ipr_config_get (self->table, "group", NULL);
    if (value)
        self->group = value;
    else
        self->group = "";

    //  All properties on resources path
    ipr_config_locate (self->table, "/config/resources", NULL);

    //  Get monitor property from config file or built-in defaults
    value = ipr_config_get (self->table, "monitor", NULL);
    if (value)
        self->monitor = (int) atol (value);
    else
        self->monitor = 0;

    //  Get dump_state property from config file or built-in defaults
    value = ipr_config_get (self->table, "dump_state", NULL);
    if (value)
        self->dump_state = (int) atol (value);
    else
        self->dump_state = 60;

    //  Get record_stats property from config file or built-in defaults
    value = ipr_config_get (self->table, "record_stats", NULL);
    if (value)
        self->record_stats = (Bool) atol (value);
    else
        self->record_stats = 0;

    //  All properties on logging path
    ipr_config_locate (self->table, "/config/logging", NULL);

    //  Get log_path property from config file or built-in defaults
    value = ipr_config_get (self->table, "log_path", NULL);
    if (value)
        self->log_path = value;
    else
        self->log_path = "/var/log/openamq";

    //  Get keep_logs property from config file or built-in defaults
    value = ipr_config_get (self->table, "keep_logs", NULL);
    if (value)
        self->keep_logs = (Bool) atol (value);
    else
        self->keep_logs = 1;

    //  Get archive_cmd property from config file or built-in defaults
    value = ipr_config_get (self->table, "archive_cmd", NULL);
    if (value)
        self->archive_cmd = value;
    else
        self->archive_cmd = "";

    //  Get alert_log property from config file or built-in defaults
    value = ipr_config_get (self->table, "alert_log", NULL);
    if (value)
        self->alert_log = value;
    else
        self->alert_log = "alert.log";

    //  Get daily_log property from config file or built-in defaults
    value = ipr_config_get (self->table, "daily_log", NULL);
    if (value)
        self->daily_log = value;
    else
        self->daily_log = "daily.log";

    //  Get debug_log property from config file or built-in defaults
    value = ipr_config_get (self->table, "debug_log", NULL);
    if (value)
        self->debug_log = value;
    else
        self->debug_log = "debug.log";

    //  Get debug_route property from config file or built-in defaults
    value = ipr_config_get (self->table, "debug_route", NULL);
    if (value)
        self->debug_route = (Bool) atol (value);
    else
        self->debug_route = 0;

    //  Get debug_queue property from config file or built-in defaults
    value = ipr_config_get (self->table, "debug_queue", NULL);
    if (value)
        self->debug_queue = (Bool) atol (value);
    else
        self->debug_queue = 0;

    //  Get debug_peering property from config file or built-in defaults
    value = ipr_config_get (self->table, "debug_peering", NULL);
    if (value)
        self->debug_peering = (Bool) atol (value);
    else
        self->debug_peering = 0;

    //  Get debug_console property from config file or built-in defaults
    value = ipr_config_get (self->table, "debug_console", NULL);
    if (value)
        self->debug_console = (Bool) atol (value);
    else
        self->debug_console = 0;

    //  Get trace property from config file or built-in defaults
    value = ipr_config_get (self->table, "trace", NULL);
    if (value)
        self->trace = (int) atol (value);
    else
        self->trace = 0;

    //  Get syslog property from config file or built-in defaults
    value = ipr_config_get (self->table, "syslog", NULL);
    if (value)
        self->syslog = (int) atol (value);
    else
        self->syslog = 0;

    //  All properties on tuning path
    ipr_config_locate (self->table, "/config/tuning", NULL);

    //  Get coremark_cycles property from config file or built-in defaults
    value = ipr_config_get (self->table, "coremark_cycles", NULL);
    if (value)
        self->coremark_cycles = (int) atol (value);
    else
        self->coremark_cycles = 250000;

    //  Get heartbeat property from config file or built-in defaults
    value = ipr_config_get (self->table, "heartbeat", NULL);
    if (value)
        self->heartbeat = (int) atol (value);
    else
        self->heartbeat = 2;

    //  Get setup_timeout property from config file or built-in defaults
    value = ipr_config_get (self->table, "setup_timeout", NULL);
    if (value)
        self->setup_timeout = (int) atol (value);
    else
        self->setup_timeout = 5;

    //  Get close_timeout property from config file or built-in defaults
    value = ipr_config_get (self->table, "close_timeout", NULL);
    if (value)
        self->close_timeout = (int) atol (value);
    else
        self->close_timeout = 5;

    //  Get accept_retry_timeout property from config file or built-in defaults
    value = ipr_config_get (self->table, "accept_retry_timeout", NULL);
    if (value)
        self->accept_retry_timeout = (int) atol (value);
    else
        self->accept_retry_timeout = 60;
    if (self->accept_retry_timeout < 1) {
        icl_console_print ("W: %s: illegal value %d for accept_retry_timeout, using %d",
            self->filename, self->accept_retry_timeout, 1);
        self->accept_retry_timeout = 1;
    }

    //  Get polling_threads property from config file or built-in defaults
    value = ipr_config_get (self->table, "polling_threads", NULL);
    if (value)
        self->polling_threads = (int) atol (value);
    else
        self->polling_threads = 4;

    //  Get working_threads property from config file or built-in defaults
    value = ipr_config_get (self->table, "working_threads", NULL);
    if (value)
        self->working_threads = (int) atol (value);
    else
        self->working_threads = 4;

    //  Get tcp_nodelay property from config file or built-in defaults
    value = ipr_config_get (self->table, "tcp_nodelay", NULL);
    if (value)
        self->tcp_nodelay = (Bool) atol (value);
    else
        self->tcp_nodelay = 1;

    //  Get tcp_rcvbuf property from config file or built-in defaults
    value = ipr_config_get (self->table, "tcp_rcvbuf", NULL);
    if (value)
        self->tcp_rcvbuf = (int) atol (value);
    else
        self->tcp_rcvbuf = 0;

    //  Get tcp_sndbuf property from config file or built-in defaults
    value = ipr_config_get (self->table, "tcp_sndbuf", NULL);
    if (value)
        self->tcp_sndbuf = (int) atol (value);
    else
        self->tcp_sndbuf = 0;

    //  Get frame_max property from config file or built-in defaults
    value = ipr_config_get (self->table, "frame_max", NULL);
    if (value)
        self->frame_max = (int) atol (value);
    else
        self->frame_max = 32768;
    if (self->frame_max < 2048) {
        icl_console_print ("W: %s: illegal value %d for frame_max, using %d",
            self->filename, self->frame_max, 2048);
        self->frame_max = 2048;
    }
    if (self->frame_max > 2097152) {
        icl_console_print ("W: %s: illegal value %d for frame_max, using %d",
            self->filename, self->frame_max, 2097152);
        self->frame_max = 2097152;
    }

    //  Get direct property from config file or built-in defaults
    value = ipr_config_get (self->table, "direct", NULL);
    if (value)
        self->direct = (int) atol (value);
    else
        self->direct = 0;

    //  Get private_credit property from config file or built-in defaults
    value = ipr_config_get (self->table, "private_credit", NULL);
    if (value)
        self->private_credit = (int) atol (value);
    else
        self->private_credit = 1024;

    //  Get shared_credit property from config file or built-in defaults
    value = ipr_config_get (self->table, "shared_credit", NULL);
    if (value)
        self->shared_credit = (int) atol (value);
    else
        self->shared_credit = 1;

    //  All properties on failover path
    ipr_config_locate (self->table, "/config/failover", NULL);

    //  Get backup property from config file or built-in defaults
    value = ipr_config_get (self->table, "backup", NULL);
    if (value)
        self->backup = value;
    else
        self->backup = "";

    //  Get primary property from config file or built-in defaults
    value = ipr_config_get (self->table, "primary", NULL);
    if (value)
        self->primary = value;
    else
        self->primary = "";

    //  Get failover_timeout property from config file or built-in defaults
    value = ipr_config_get (self->table, "timeout", NULL);
    if (value)
        self->failover_timeout = (int) atol (value);
    else
        self->failover_timeout = 5;
    if (self->failover_timeout < 1) {
        icl_console_print ("W: %s: illegal value %d for failover_timeout, using %d",
            self->filename, self->failover_timeout, 1);
        self->failover_timeout = 1;
    }
    if (self->failover_timeout > 60) {
        icl_console_print ("W: %s: illegal value %d for failover_timeout, using %d",
            self->filename, self->failover_timeout, 60);
        self->failover_timeout = 60;
    }

    //  All properties on federation path
    ipr_config_locate (self->table, "/config/federation", NULL);

    //  Get attach property from config file or built-in defaults
    value = ipr_config_get (self->table, "attach", NULL);
    if (value)
        self->attach = value;
    else
        self->attach = "";

    //  Get attach_vhost property from config file or built-in defaults
    value = ipr_config_get (self->table, "attach_vhost", NULL);
    if (value)
        self->attach_vhost = value;
    else
        self->attach_vhost = "/";

    //  Get attach_login property from config file or built-in defaults
    value = ipr_config_get (self->table, "attach_login", NULL);
    if (value)
        self->attach_login = value;
    else
        self->attach_login = "peering";

    //  Get attach_all property from config file or built-in defaults
    value = ipr_config_get (self->table, "attach_all", NULL);
    if (value)
        self->attach_all = value;
    else
        self->attach_all = "";

    //  All properties on direct path
    ipr_config_locate (self->table, "/config/direct", NULL);

    //  Get batching property from config file or built-in defaults
    value = ipr_config_get (self->table, "batching", NULL);
    if (value)
        self->batching = (int) atol (value);
    else
        self->batching = 32768;
    if (self->batching > 2097152) {
        icl_console_print ("W: %s: illegal value %d for batching, using %d",
            self->filename, self->batching, 2097152);
        self->batching = 2097152;
    }

    //  Get direct_heartbeat property from config file or built-in defaults
    value = ipr_config_get (self->table, "heartbeat", NULL);
    if (value)
        self->direct_heartbeat = (int) atol (value);
    else
        self->direct_heartbeat = 2;

    //  All properties on compatibility path
    ipr_config_locate (self->table, "/config/compatibility", NULL);

    //  Get no_ack property from config file or built-in defaults
    value = ipr_config_get (self->table, "no_ack", NULL);
    if (value)
        self->no_ack = (Bool) atol (value);
    else
        self->no_ack = 0;

    //  All properties on internal path
    ipr_config_locate (self->table, "/config/internal", NULL);

    //  Get auto_crash property from config file or built-in defaults
    value = ipr_config_get (self->table, "auto_crash", NULL);
    if (value)
        self->auto_crash = (int) atol (value);
    else
        self->auto_crash = 0;

    //  Get auto_block property from config file or built-in defaults
    value = ipr_config_get (self->table, "auto_block", NULL);
    if (value)
        self->auto_block = (int) atol (value);
    else
        self->auto_block = 0;

    //  Get kernel_limit property from config file or built-in defaults
    value = ipr_config_get (self->table, "kernel_limit", NULL);
    if (value)
        self->kernel_limit = (int) atol (value);
    else
        self->kernel_limit = 0;

    //  All properties on queue_profile path
    ipr_config_locate (self->table, "/config/queue_profile", NULL);

    //  All properties on security path
    ipr_config_locate (self->table, "/config/security", NULL);

    //  All properties on federate path
    ipr_config_locate (self->table, "/config/federate", NULL);
}
</private>

<method name = "selftest">
</method>

</class>

