/*---------------------------------------------------------------------------
    amq_server_config.c - amq_server_config component

    Generated from amq_server_config.icl by icl_gen using GSL/4.
    
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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "amq_server_config.h"          //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_server_config_t

//  Shorthands for class methods                                               

#define self_new            amq_server_config_new
#define self_annihilate     amq_server_config_annihilate
#define self_load_xmlfile   amq_server_config_load_xmlfile
#define self_load_bucket    amq_server_config_load_bucket
#define self_commit         amq_server_config_commit
#define self_rollback       amq_server_config_rollback
#define self_cmdline_help   amq_server_config_cmdline_help
#define self_cmdline_parse  amq_server_config_cmdline_parse
#define self_options_help   amq_server_config_options_help
#define self_set_port       amq_server_config_set_port
#define self_port           amq_server_config_port
#define self_set_listen     amq_server_config_set_listen
#define self_listen         amq_server_config_listen
#define self_set_queue_timeout  amq_server_config_set_queue_timeout
#define self_queue_timeout  amq_server_config_queue_timeout
#define self_set_vhost      amq_server_config_set_vhost
#define self_vhost          amq_server_config_vhost
#define self_set_user       amq_server_config_set_user
#define self_user           amq_server_config_user
#define self_set_group      amq_server_config_set_group
#define self_group          amq_server_config_group
#define self_set_monitor    amq_server_config_set_monitor
#define self_monitor        amq_server_config_monitor
#define self_set_dump_state  amq_server_config_set_dump_state
#define self_dump_state     amq_server_config_dump_state
#define self_set_record_stats  amq_server_config_set_record_stats
#define self_record_stats   amq_server_config_record_stats
#define self_set_log_path   amq_server_config_set_log_path
#define self_log_path       amq_server_config_log_path
#define self_set_keep_logs  amq_server_config_set_keep_logs
#define self_keep_logs      amq_server_config_keep_logs
#define self_set_archive_path  amq_server_config_set_archive_path
#define self_archive_path   amq_server_config_archive_path
#define self_set_archive_cmd  amq_server_config_set_archive_cmd
#define self_archive_cmd    amq_server_config_archive_cmd
#define self_set_alert_log  amq_server_config_set_alert_log
#define self_alert_log      amq_server_config_alert_log
#define self_set_daily_log  amq_server_config_set_daily_log
#define self_daily_log      amq_server_config_daily_log
#define self_set_debug_log  amq_server_config_set_debug_log
#define self_debug_log      amq_server_config_debug_log
#define self_set_debug_route  amq_server_config_set_debug_route
#define self_debug_route    amq_server_config_debug_route
#define self_set_debug_queue  amq_server_config_set_debug_queue
#define self_debug_queue    amq_server_config_debug_queue
#define self_set_debug_peering  amq_server_config_set_debug_peering
#define self_debug_peering  amq_server_config_debug_peering
#define self_set_debug_console  amq_server_config_set_debug_console
#define self_debug_console  amq_server_config_debug_console
#define self_set_trace      amq_server_config_set_trace
#define self_trace          amq_server_config_trace
#define self_set_heartbeat  amq_server_config_set_heartbeat
#define self_heartbeat      amq_server_config_heartbeat
#define self_set_setup_timeout  amq_server_config_set_setup_timeout
#define self_setup_timeout  amq_server_config_setup_timeout
#define self_set_close_timeout  amq_server_config_set_close_timeout
#define self_close_timeout  amq_server_config_close_timeout
#define self_set_accept_retry_timeout  amq_server_config_set_accept_retry_timeout
#define self_accept_retry_timeout  amq_server_config_accept_retry_timeout
#define self_set_polling_threads  amq_server_config_set_polling_threads
#define self_polling_threads  amq_server_config_polling_threads
#define self_set_working_threads  amq_server_config_set_working_threads
#define self_working_threads  amq_server_config_working_threads
#define self_set_tcp_nodelay  amq_server_config_set_tcp_nodelay
#define self_tcp_nodelay    amq_server_config_tcp_nodelay
#define self_set_tcp_rcvbuf  amq_server_config_set_tcp_rcvbuf
#define self_tcp_rcvbuf     amq_server_config_tcp_rcvbuf
#define self_set_tcp_sndbuf  amq_server_config_set_tcp_sndbuf
#define self_tcp_sndbuf     amq_server_config_tcp_sndbuf
#define self_set_frame_max  amq_server_config_set_frame_max
#define self_frame_max      amq_server_config_frame_max
#define self_set_direct     amq_server_config_set_direct
#define self_direct         amq_server_config_direct
#define self_set_private_credit  amq_server_config_set_private_credit
#define self_private_credit  amq_server_config_private_credit
#define self_set_shared_credit  amq_server_config_set_shared_credit
#define self_shared_credit  amq_server_config_shared_credit
#define self_set_backup     amq_server_config_set_backup
#define self_backup         amq_server_config_backup
#define self_set_primary    amq_server_config_set_primary
#define self_primary        amq_server_config_primary
#define self_set_failover_timeout  amq_server_config_set_failover_timeout
#define self_failover_timeout  amq_server_config_failover_timeout
#define self_set_attach     amq_server_config_set_attach
#define self_attach         amq_server_config_attach
#define self_set_attach_vhost  amq_server_config_set_attach_vhost
#define self_attach_vhost   amq_server_config_attach_vhost
#define self_set_attach_login  amq_server_config_set_attach_login
#define self_attach_login   amq_server_config_attach_login
#define self_set_attach_all  amq_server_config_set_attach_all
#define self_attach_all     amq_server_config_attach_all
#define self_set_batching   amq_server_config_set_batching
#define self_batching       amq_server_config_batching
#define self_set_direct_heartbeat  amq_server_config_set_direct_heartbeat
#define self_direct_heartbeat  amq_server_config_direct_heartbeat
#define self_set_no_ack     amq_server_config_set_no_ack
#define self_no_ack         amq_server_config_no_ack
#define self_set_auto_crash  amq_server_config_set_auto_crash
#define self_auto_crash     amq_server_config_auto_crash
#define self_set_auto_block  amq_server_config_set_auto_block
#define self_auto_block     amq_server_config_auto_block
#define self_set_kernel_limit  amq_server_config_set_kernel_limit
#define self_kernel_limit   amq_server_config_kernel_limit
#define self_dump_log       amq_server_config_dump_log
#define self_selftest       amq_server_config_selftest
#define self_terminate      amq_server_config_terminate
#define self_show           amq_server_config_show
#define self_destroy        amq_server_config_destroy
#define self_alloc          amq_server_config_alloc
#define self_free           amq_server_config_free
#define self_read_lock      amq_server_config_read_lock
#define self_write_lock     amq_server_config_write_lock
#define self_unlock         amq_server_config_unlock
#define self_cache_initialise  amq_server_config_cache_initialise
#define self_cache_purge    amq_server_config_cache_purge
#define self_cache_terminate  amq_server_config_cache_terminate
#define self_animate        amq_server_config_animate
#define self_new_in_scope   amq_server_config_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_NEW))
static icl_stats_t *s_amq_server_config_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DESTROY))
static icl_stats_t *s_amq_server_config_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_LOAD_XMLFILE))
static icl_stats_t *s_amq_server_config_load_xmlfile_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_LOAD_BUCKET))
static icl_stats_t *s_amq_server_config_load_bucket_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_COMMIT))
static icl_stats_t *s_amq_server_config_commit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ROLLBACK))
static icl_stats_t *s_amq_server_config_rollback_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CMDLINE_HELP))
static icl_stats_t *s_amq_server_config_cmdline_help_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CMDLINE_PARSE))
static icl_stats_t *s_amq_server_config_cmdline_parse_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_OPTIONS_HELP))
static icl_stats_t *s_amq_server_config_options_help_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_PORT))
static icl_stats_t *s_amq_server_config_set_port_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_PORT))
static icl_stats_t *s_amq_server_config_port_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_LISTEN))
static icl_stats_t *s_amq_server_config_set_listen_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_LISTEN))
static icl_stats_t *s_amq_server_config_listen_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_QUEUE_TIMEOUT))
static icl_stats_t *s_amq_server_config_set_queue_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_QUEUE_TIMEOUT))
static icl_stats_t *s_amq_server_config_queue_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_VHOST))
static icl_stats_t *s_amq_server_config_set_vhost_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_VHOST))
static icl_stats_t *s_amq_server_config_vhost_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_USER))
static icl_stats_t *s_amq_server_config_set_user_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_USER))
static icl_stats_t *s_amq_server_config_user_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_GROUP))
static icl_stats_t *s_amq_server_config_set_group_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_GROUP))
static icl_stats_t *s_amq_server_config_group_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_MONITOR))
static icl_stats_t *s_amq_server_config_set_monitor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_MONITOR))
static icl_stats_t *s_amq_server_config_monitor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DUMP_STATE))
static icl_stats_t *s_amq_server_config_set_dump_state_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DUMP_STATE))
static icl_stats_t *s_amq_server_config_dump_state_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_RECORD_STATS))
static icl_stats_t *s_amq_server_config_set_record_stats_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_RECORD_STATS))
static icl_stats_t *s_amq_server_config_record_stats_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_LOG_PATH))
static icl_stats_t *s_amq_server_config_set_log_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_LOG_PATH))
static icl_stats_t *s_amq_server_config_log_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_KEEP_LOGS))
static icl_stats_t *s_amq_server_config_set_keep_logs_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_KEEP_LOGS))
static icl_stats_t *s_amq_server_config_keep_logs_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ARCHIVE_PATH))
static icl_stats_t *s_amq_server_config_set_archive_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ARCHIVE_PATH))
static icl_stats_t *s_amq_server_config_archive_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ARCHIVE_CMD))
static icl_stats_t *s_amq_server_config_set_archive_cmd_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ARCHIVE_CMD))
static icl_stats_t *s_amq_server_config_archive_cmd_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ALERT_LOG))
static icl_stats_t *s_amq_server_config_set_alert_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ALERT_LOG))
static icl_stats_t *s_amq_server_config_alert_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DAILY_LOG))
static icl_stats_t *s_amq_server_config_set_daily_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DAILY_LOG))
static icl_stats_t *s_amq_server_config_daily_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DEBUG_LOG))
static icl_stats_t *s_amq_server_config_set_debug_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DEBUG_LOG))
static icl_stats_t *s_amq_server_config_debug_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DEBUG_ROUTE))
static icl_stats_t *s_amq_server_config_set_debug_route_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DEBUG_ROUTE))
static icl_stats_t *s_amq_server_config_debug_route_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DEBUG_QUEUE))
static icl_stats_t *s_amq_server_config_set_debug_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DEBUG_QUEUE))
static icl_stats_t *s_amq_server_config_debug_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DEBUG_PEERING))
static icl_stats_t *s_amq_server_config_set_debug_peering_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DEBUG_PEERING))
static icl_stats_t *s_amq_server_config_debug_peering_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DEBUG_CONSOLE))
static icl_stats_t *s_amq_server_config_set_debug_console_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DEBUG_CONSOLE))
static icl_stats_t *s_amq_server_config_debug_console_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_TRACE))
static icl_stats_t *s_amq_server_config_set_trace_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_TRACE))
static icl_stats_t *s_amq_server_config_trace_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_HEARTBEAT))
static icl_stats_t *s_amq_server_config_set_heartbeat_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_HEARTBEAT))
static icl_stats_t *s_amq_server_config_heartbeat_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_SETUP_TIMEOUT))
static icl_stats_t *s_amq_server_config_set_setup_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SETUP_TIMEOUT))
static icl_stats_t *s_amq_server_config_setup_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_CLOSE_TIMEOUT))
static icl_stats_t *s_amq_server_config_set_close_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CLOSE_TIMEOUT))
static icl_stats_t *s_amq_server_config_close_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ACCEPT_RETRY_TIMEOUT))
static icl_stats_t *s_amq_server_config_set_accept_retry_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ACCEPT_RETRY_TIMEOUT))
static icl_stats_t *s_amq_server_config_accept_retry_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_POLLING_THREADS))
static icl_stats_t *s_amq_server_config_set_polling_threads_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_POLLING_THREADS))
static icl_stats_t *s_amq_server_config_polling_threads_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_WORKING_THREADS))
static icl_stats_t *s_amq_server_config_set_working_threads_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_WORKING_THREADS))
static icl_stats_t *s_amq_server_config_working_threads_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_TCP_NODELAY))
static icl_stats_t *s_amq_server_config_set_tcp_nodelay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_TCP_NODELAY))
static icl_stats_t *s_amq_server_config_tcp_nodelay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_TCP_RCVBUF))
static icl_stats_t *s_amq_server_config_set_tcp_rcvbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_TCP_RCVBUF))
static icl_stats_t *s_amq_server_config_tcp_rcvbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_TCP_SNDBUF))
static icl_stats_t *s_amq_server_config_set_tcp_sndbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_TCP_SNDBUF))
static icl_stats_t *s_amq_server_config_tcp_sndbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_FRAME_MAX))
static icl_stats_t *s_amq_server_config_set_frame_max_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_FRAME_MAX))
static icl_stats_t *s_amq_server_config_frame_max_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DIRECT))
static icl_stats_t *s_amq_server_config_set_direct_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DIRECT))
static icl_stats_t *s_amq_server_config_direct_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_PRIVATE_CREDIT))
static icl_stats_t *s_amq_server_config_set_private_credit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_PRIVATE_CREDIT))
static icl_stats_t *s_amq_server_config_private_credit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_SHARED_CREDIT))
static icl_stats_t *s_amq_server_config_set_shared_credit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SHARED_CREDIT))
static icl_stats_t *s_amq_server_config_shared_credit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_BACKUP))
static icl_stats_t *s_amq_server_config_set_backup_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_BACKUP))
static icl_stats_t *s_amq_server_config_backup_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_PRIMARY))
static icl_stats_t *s_amq_server_config_set_primary_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_PRIMARY))
static icl_stats_t *s_amq_server_config_primary_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_FAILOVER_TIMEOUT))
static icl_stats_t *s_amq_server_config_set_failover_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_FAILOVER_TIMEOUT))
static icl_stats_t *s_amq_server_config_failover_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ATTACH))
static icl_stats_t *s_amq_server_config_set_attach_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ATTACH))
static icl_stats_t *s_amq_server_config_attach_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ATTACH_VHOST))
static icl_stats_t *s_amq_server_config_set_attach_vhost_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ATTACH_VHOST))
static icl_stats_t *s_amq_server_config_attach_vhost_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ATTACH_LOGIN))
static icl_stats_t *s_amq_server_config_set_attach_login_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ATTACH_LOGIN))
static icl_stats_t *s_amq_server_config_attach_login_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ATTACH_ALL))
static icl_stats_t *s_amq_server_config_set_attach_all_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ATTACH_ALL))
static icl_stats_t *s_amq_server_config_attach_all_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_BATCHING))
static icl_stats_t *s_amq_server_config_set_batching_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_BATCHING))
static icl_stats_t *s_amq_server_config_batching_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DIRECT_HEARTBEAT))
static icl_stats_t *s_amq_server_config_set_direct_heartbeat_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DIRECT_HEARTBEAT))
static icl_stats_t *s_amq_server_config_direct_heartbeat_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_NO_ACK))
static icl_stats_t *s_amq_server_config_set_no_ack_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_NO_ACK))
static icl_stats_t *s_amq_server_config_no_ack_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_AUTO_CRASH))
static icl_stats_t *s_amq_server_config_set_auto_crash_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_AUTO_CRASH))
static icl_stats_t *s_amq_server_config_auto_crash_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_AUTO_BLOCK))
static icl_stats_t *s_amq_server_config_set_auto_block_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_AUTO_BLOCK))
static icl_stats_t *s_amq_server_config_auto_block_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_KERNEL_LIMIT))
static icl_stats_t *s_amq_server_config_set_kernel_limit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_KERNEL_LIMIT))
static icl_stats_t *s_amq_server_config_kernel_limit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DUMP_LOG))
static icl_stats_t *s_amq_server_config_dump_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SELFTEST))
static icl_stats_t *s_amq_server_config_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_TERMINATE))
static icl_stats_t *s_amq_server_config_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SHOW))
static icl_stats_t *s_amq_server_config_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DESTROY_PUBLIC))
static icl_stats_t *s_amq_server_config_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ALLOC))
static icl_stats_t *s_amq_server_config_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_FREE))
static icl_stats_t *s_amq_server_config_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_READ_LOCK))
static icl_stats_t *s_amq_server_config_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_WRITE_LOCK))
static icl_stats_t *s_amq_server_config_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_UNLOCK))
static icl_stats_t *s_amq_server_config_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CACHE_INITIALISE))
static icl_stats_t *s_amq_server_config_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CACHE_PURGE))
static icl_stats_t *s_amq_server_config_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CACHE_TERMINATE))
static icl_stats_t *s_amq_server_config_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ANIMATE))
static icl_stats_t *s_amq_server_config_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_NEW_IN_SCOPE))
static icl_stats_t *s_amq_server_config_new_in_scope_stats = NULL;
#endif
static void
    amq_server_config_annihilate (
amq_server_config_t * ( * self_p )      //  Reference to object reference
);

#define amq_server_config_alloc()       amq_server_config_alloc_ (__FILE__, __LINE__)
static amq_server_config_t *
    amq_server_config_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_server_config_free (
amq_server_config_t * self              //  Object reference
);

static void
    amq_server_config_cache_initialise (
void);

static void
    amq_server_config_cache_purge (
void);

static void
    amq_server_config_cache_terminate (
void);

Bool
    amq_server_config_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static void s_validate_items (amq_server_config_t *self);
static void s_get_properties (amq_server_config_t *self);
amq_server_config_t
    *amq_server_config = NULL;          //  Global properties
static void s_validate_items (amq_server_config_t *self)
{
    char
        *item_name;

    //  Locate first child and check all items for validity
    ipr_config_locate (self->config, "/config/+", "");
    while (self->config->located) {
        item_name = ipr_config_item (self->config);
        if (streq (item_name, "echo"))
            icl_console_print ("I: %s: %s", self->filename, ipr_config_value (self->config));
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
        ipr_config_next (self->config);
    }
}

static void s_get_properties (amq_server_config_t *self)
{
    char
        *value;                         //  Configured value

    //  All properties on server path
    ipr_config_locate (self->config, "/config/server", NULL);

    //  Get port property from config file or built-in defaults
    value = ipr_config_get (self->config, "port", NULL);
    if (value)
        icl_shortstr_cpy (self->port, value);
    else
        icl_shortstr_cpy (self->port, "5672");

    //  Get listen property from config file or built-in defaults
    value = ipr_config_get (self->config, "listen", NULL);
    if (value)
        icl_shortstr_cpy (self->listen, value);
    else
        icl_shortstr_cpy (self->listen, "*");

    //  Get queue_timeout property from config file or built-in defaults
    value = ipr_config_get (self->config, "queue_timeout", NULL);
    if (value)
        self->queue_timeout = (int) atol (value);
    else
        self->queue_timeout = 0;

    //  Get vhost property from config file or built-in defaults
    value = ipr_config_get (self->config, "vhost", NULL);
    if (value)
        icl_shortstr_cpy (self->vhost, value);
    else
        icl_shortstr_cpy (self->vhost, "/");

    //  Get user property from config file or built-in defaults
    value = ipr_config_get (self->config, "user", NULL);
    if (value)
        self->user = value;
    else
        self->user = "";

    //  Get group property from config file or built-in defaults
    value = ipr_config_get (self->config, "group", NULL);
    if (value)
        self->group = value;
    else
        self->group = "";

    //  All properties on resources path
    ipr_config_locate (self->config, "/config/resources", NULL);

    //  Get monitor property from config file or built-in defaults
    value = ipr_config_get (self->config, "monitor", NULL);
    if (value)
        self->monitor = (int) atol (value);
    else
        self->monitor = 0;

    //  Get dump_state property from config file or built-in defaults
    value = ipr_config_get (self->config, "dump_state", NULL);
    if (value)
        self->dump_state = (int) atol (value);
    else
        self->dump_state = 60;

    //  Get record_stats property from config file or built-in defaults
    value = ipr_config_get (self->config, "record_stats", NULL);
    if (value)
        self->record_stats = (Bool) atol (value);
    else
        self->record_stats = 0;

    //  All properties on logging path
    ipr_config_locate (self->config, "/config/logging", NULL);

    //  Get log_path property from config file or built-in defaults
    value = ipr_config_get (self->config, "log_path", NULL);
    if (value)
        icl_shortstr_cpy (self->log_path, value);
    else
        icl_shortstr_cpy (self->log_path, "logs");

    //  Get keep_logs property from config file or built-in defaults
    value = ipr_config_get (self->config, "keep_logs", NULL);
    if (value)
        self->keep_logs = (Bool) atol (value);
    else
        self->keep_logs = 1;

    //  Get archive_path property from config file or built-in defaults
    value = ipr_config_get (self->config, "archive_path", NULL);
    if (value)
        icl_shortstr_cpy (self->archive_path, value);
    else
        icl_shortstr_cpy (self->archive_path, "archive");

    //  Get archive_cmd property from config file or built-in defaults
    value = ipr_config_get (self->config, "archive_cmd", NULL);
    if (value)
        icl_shortstr_cpy (self->archive_cmd, value);
    else
        icl_shortstr_cpy (self->archive_cmd, "");

    //  Get alert_log property from config file or built-in defaults
    value = ipr_config_get (self->config, "alert_log", NULL);
    if (value)
        icl_shortstr_cpy (self->alert_log, value);
    else
        icl_shortstr_cpy (self->alert_log, "alert.log");

    //  Get daily_log property from config file or built-in defaults
    value = ipr_config_get (self->config, "daily_log", NULL);
    if (value)
        icl_shortstr_cpy (self->daily_log, value);
    else
        icl_shortstr_cpy (self->daily_log, "daily.log");

    //  Get debug_log property from config file or built-in defaults
    value = ipr_config_get (self->config, "debug_log", NULL);
    if (value)
        icl_shortstr_cpy (self->debug_log, value);
    else
        icl_shortstr_cpy (self->debug_log, "debug.log");

    //  Get debug_route property from config file or built-in defaults
    value = ipr_config_get (self->config, "debug_route", NULL);
    if (value)
        self->debug_route = (Bool) atol (value);
    else
        self->debug_route = 0;

    //  Get debug_queue property from config file or built-in defaults
    value = ipr_config_get (self->config, "debug_queue", NULL);
    if (value)
        self->debug_queue = (Bool) atol (value);
    else
        self->debug_queue = 0;

    //  Get debug_peering property from config file or built-in defaults
    value = ipr_config_get (self->config, "debug_peering", NULL);
    if (value)
        self->debug_peering = (Bool) atol (value);
    else
        self->debug_peering = 0;

    //  Get debug_console property from config file or built-in defaults
    value = ipr_config_get (self->config, "debug_console", NULL);
    if (value)
        self->debug_console = (Bool) atol (value);
    else
        self->debug_console = 0;

    //  Get trace property from config file or built-in defaults
    value = ipr_config_get (self->config, "trace", NULL);
    if (value)
        self->trace = (int) atol (value);
    else
        self->trace = 0;

    //  All properties on tuning path
    ipr_config_locate (self->config, "/config/tuning", NULL);

    //  Get heartbeat property from config file or built-in defaults
    value = ipr_config_get (self->config, "heartbeat", NULL);
    if (value)
        self->heartbeat = (int) atol (value);
    else
        self->heartbeat = 2;

    //  Get setup_timeout property from config file or built-in defaults
    value = ipr_config_get (self->config, "setup_timeout", NULL);
    if (value)
        self->setup_timeout = (int) atol (value);
    else
        self->setup_timeout = 5;

    //  Get close_timeout property from config file or built-in defaults
    value = ipr_config_get (self->config, "close_timeout", NULL);
    if (value)
        self->close_timeout = (int) atol (value);
    else
        self->close_timeout = 5;

    //  Get accept_retry_timeout property from config file or built-in defaults
    value = ipr_config_get (self->config, "accept_retry_timeout", NULL);
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
    value = ipr_config_get (self->config, "polling_threads", NULL);
    if (value)
        self->polling_threads = (int) atol (value);
    else
        self->polling_threads = 4;

    //  Get working_threads property from config file or built-in defaults
    value = ipr_config_get (self->config, "working_threads", NULL);
    if (value)
        self->working_threads = (int) atol (value);
    else
        self->working_threads = 4;

    //  Get tcp_nodelay property from config file or built-in defaults
    value = ipr_config_get (self->config, "tcp_nodelay", NULL);
    if (value)
        self->tcp_nodelay = (Bool) atol (value);
    else
        self->tcp_nodelay = 1;

    //  Get tcp_rcvbuf property from config file or built-in defaults
    value = ipr_config_get (self->config, "tcp_rcvbuf", NULL);
    if (value)
        self->tcp_rcvbuf = (int) atol (value);
    else
        self->tcp_rcvbuf = 0;

    //  Get tcp_sndbuf property from config file or built-in defaults
    value = ipr_config_get (self->config, "tcp_sndbuf", NULL);
    if (value)
        self->tcp_sndbuf = (int) atol (value);
    else
        self->tcp_sndbuf = 0;

    //  Get frame_max property from config file or built-in defaults
    value = ipr_config_get (self->config, "frame_max", NULL);
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
    value = ipr_config_get (self->config, "direct", NULL);
    if (value)
        self->direct = (int) atol (value);
    else
        self->direct = 0;

    //  Get private_credit property from config file or built-in defaults
    value = ipr_config_get (self->config, "private_credit", NULL);
    if (value)
        self->private_credit = (int) atol (value);
    else
        self->private_credit = 1024;

    //  Get shared_credit property from config file or built-in defaults
    value = ipr_config_get (self->config, "shared_credit", NULL);
    if (value)
        self->shared_credit = (int) atol (value);
    else
        self->shared_credit = 1;

    //  All properties on failover path
    ipr_config_locate (self->config, "/config/failover", NULL);

    //  Get backup property from config file or built-in defaults
    value = ipr_config_get (self->config, "backup", NULL);
    if (value)
        icl_shortstr_cpy (self->backup, value);
    else
        icl_shortstr_cpy (self->backup, "");

    //  Get primary property from config file or built-in defaults
    value = ipr_config_get (self->config, "primary", NULL);
    if (value)
        icl_shortstr_cpy (self->primary, value);
    else
        icl_shortstr_cpy (self->primary, "");

    //  Get failover_timeout property from config file or built-in defaults
    value = ipr_config_get (self->config, "timeout", NULL);
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
    ipr_config_locate (self->config, "/config/federation", NULL);

    //  Get attach property from config file or built-in defaults
    value = ipr_config_get (self->config, "attach", NULL);
    if (value)
        icl_shortstr_cpy (self->attach, value);
    else
        icl_shortstr_cpy (self->attach, "");

    //  Get attach_vhost property from config file or built-in defaults
    value = ipr_config_get (self->config, "attach_vhost", NULL);
    if (value)
        icl_shortstr_cpy (self->attach_vhost, value);
    else
        icl_shortstr_cpy (self->attach_vhost, "/");

    //  Get attach_login property from config file or built-in defaults
    value = ipr_config_get (self->config, "attach_login", NULL);
    if (value)
        icl_shortstr_cpy (self->attach_login, value);
    else
        icl_shortstr_cpy (self->attach_login, "peering");

    //  Get attach_all property from config file or built-in defaults
    value = ipr_config_get (self->config, "attach_all", NULL);
    if (value)
        icl_shortstr_cpy (self->attach_all, value);
    else
        icl_shortstr_cpy (self->attach_all, "");

    //  All properties on direct path
    ipr_config_locate (self->config, "/config/direct", NULL);

    //  Get batching property from config file or built-in defaults
    value = ipr_config_get (self->config, "batching", NULL);
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
    value = ipr_config_get (self->config, "heartbeat", NULL);
    if (value)
        self->direct_heartbeat = (int) atol (value);
    else
        self->direct_heartbeat = 2;

    //  All properties on compatibility path
    ipr_config_locate (self->config, "/config/compatibility", NULL);

    //  Get no_ack property from config file or built-in defaults
    value = ipr_config_get (self->config, "no_ack", NULL);
    if (value)
        self->no_ack = (Bool) atol (value);
    else
        self->no_ack = 0;

    //  All properties on internal path
    ipr_config_locate (self->config, "/config/internal", NULL);

    //  Get auto_crash property from config file or built-in defaults
    value = ipr_config_get (self->config, "auto_crash", NULL);
    if (value)
        self->auto_crash = (int) atol (value);
    else
        self->auto_crash = 0;

    //  Get auto_block property from config file or built-in defaults
    value = ipr_config_get (self->config, "auto_block", NULL);
    if (value)
        self->auto_block = (int) atol (value);
    else
        self->auto_block = 0;

    //  Get kernel_limit property from config file or built-in defaults
    value = ipr_config_get (self->config, "kernel_limit", NULL);
    if (value)
        self->kernel_limit = (int) atol (value);
    else
        self->kernel_limit = 0;

    //  All properties on queue_profile path
    ipr_config_locate (self->config, "/config/queue_profile", NULL);

    //  All properties on security path
    ipr_config_locate (self->config, "/config/security", NULL);

    //  All properties on federate path
    ipr_config_locate (self->config, "/config/federate", NULL);
}
/*  -------------------------------------------------------------------------
    amq_server_config_new

    Type: Component method
    Creates and initialises a new amq_server_config_t object, returns a
    reference to the created object.
    Creates an empty configuration set.  To fill this, use the load and
    load_bucket methods.
    -------------------------------------------------------------------------
 */

amq_server_config_t *
    amq_server_config_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_server_config_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_NEW))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NEW))
    icl_trace_record (NULL, amq_server_config_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_NEW))
    icl_stats_inc ("amq_server_config_new", &s_amq_server_config_new_stats);
#endif

    self = amq_server_config_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_SERVER_CONFIG_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_server_config_show_);
#endif

//
self->config = ipr_config_new (NULL, FALSE);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NEW))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_NEW))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_config_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_config_annihilate (
    amq_server_config_t * ( * self_p )  //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_server_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DESTROY))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DESTROY))
    icl_trace_record (NULL, amq_server_config_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DESTROY))
    icl_stats_inc ("amq_server_config_annihilate", &s_amq_server_config_annihilate_stats);
#endif

    AMQ_SERVER_CONFIG_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

ipr_config_destroy (&self->config);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DESTROY))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DESTROY))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_config_load_xmlfile

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config file into the property set, merging the new loaded data
    with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_load_xmlfile (
    amq_server_config_t * self,         //  Reference to object
    char * filename,                    //  Config file to load
    Bool required                       //  Config file is required?
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_LOAD_XMLFILE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_load_xmlfile_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" required=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, required);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOAD_XMLFILE))
    icl_trace_record (NULL, amq_server_config_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_LOAD_XMLFILE))
    icl_stats_inc ("amq_server_config_load_xmlfile", &s_amq_server_config_load_xmlfile_stats);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
assert (filename);
if (!ipr_config_load (self->config, filename, required)) {
    icl_shortstr_cpy (self->filename, filename);
    s_validate_items (self);
    s_get_properties (self);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOAD_XMLFILE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_LOAD_XMLFILE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_load_xmlfile_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" required=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, required, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_load_bucket

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config resource (as a bucket) into the property set, merging the
    new loaded data with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_load_bucket (
    amq_server_config_t * self,         //  Reference to object
    ipr_bucket_t * bucket               //  Config data to load
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_LOAD_BUCKET))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_load_bucket_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOAD_BUCKET))
    icl_trace_record (NULL, amq_server_config_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_LOAD_BUCKET))
    icl_stats_inc ("amq_server_config_load_bucket", &s_amq_server_config_load_bucket_stats);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
assert (bucket);
ipr_config_load_bucket (self->config, bucket);
s_validate_items (self);
s_get_properties (self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOAD_BUCKET))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_LOAD_BUCKET))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_load_bucket_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_commit

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    Saves the current configuration values to the specified file.  If the
    provided filename is null, uses the original config filename. If both
    filenames are null, does nothing.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_commit (
    amq_server_config_t * self,         //  Reference to object
    char * filename                     //  Config file to save
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_COMMIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_commit_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_COMMIT))
    icl_trace_record (NULL, amq_server_config_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_COMMIT))
    icl_stats_inc ("amq_server_config_commit", &s_amq_server_config_commit_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
if (filename)
    ipr_config_save (self->config, filename);
else
if (strused (self->filename))
    ipr_config_save (self->config, self->filename);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_COMMIT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_COMMIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_commit_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_rollback

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    Reloads the saved configuration from the saved file, if any.
    Any changes made to the current configuration are lost.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_rollback (
    amq_server_config_t * self          //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ROLLBACK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_rollback_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ROLLBACK))
    icl_trace_record (NULL, amq_server_config_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ROLLBACK))
    icl_stats_inc ("amq_server_config_rollback", &s_amq_server_config_rollback_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
ipr_config_destroy (&self->config);
self->config = ipr_config_new (self->filename, TRUE);
s_get_properties (self);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ROLLBACK))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ROLLBACK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_rollback_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_cmdline_help

    Type: Component method
    Prints command-line help for setting options from the command
    line.
    -------------------------------------------------------------------------
 */

void
    amq_server_config_cmdline_help (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CMDLINE_HELP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_cmdline_help_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CMDLINE_HELP))
    icl_trace_record (NULL, amq_server_config_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CMDLINE_HELP))
    icl_stats_inc ("amq_server_config_cmdline_help", &s_amq_server_config_cmdline_help_stats);
#endif

printf ("Options that override config values; these take an argument:\n");
printf ("  --port           Server port for clients\n");
printf ("  --listen         Address (local network interface) to listen on\n");
printf ("  --queue_timeout  Timeout for auto-deleted queues\n");
printf ("  --vhost          Server vhost identifier\n");
printf ("  --user           User to run server as\n");
printf ("  --group          Group to run server as\n");
printf ("  --monitor        Monitor interval, seconds\n");
printf ("  --dump_state     Dump state interval, seconds\n");
printf ("  --record_stats   Record performance statistics\n");
printf ("  --log_path       Active log file directory\n");
printf ("  --keep_logs      Keep log files\n");
printf ("  --archive_path   Archive log file directory\n");
printf ("  --archive_cmd    Archive log file command\n");
printf ("  --alert_log      Error log file name\n");
printf ("  --daily_log      Daily log file name\n");
printf ("  --debug_log      Debug log file name\n");
printf ("  --debug_route    Debug message routing?\n");
printf ("  --debug_queue    Debug queue activity?\n");
printf ("  --debug_peering  Debug peering messages?\n");
printf ("  --debug_console  Debug console I/O?\n");
printf ("  --trace          Protocol trace level\n");
printf ("  --heartbeat      Heartbeat timer, seconds\n");
printf ("  --setup_timeout  Connection setup timeout, seconds\n");
printf ("  --close_timeout  Connection close timeout, seconds\n");
printf ("  --accept_retry_timeout  Timeout before retrying accept calls, seconds\n");
printf ("  --polling_threads  Number of polling OS threads\n");
printf ("  --working_threads  Number of working OS threads\n");
printf ("  --tcp_nodelay    TCP/IP NODELAY option\n");
printf ("  --tcp_rcvbuf     TCP/IP receive buffer, in bytes\n");
printf ("  --tcp_sndbuf     TCP/IP send buffer, in bytes\n");
printf ("  --frame_max      Maximum size of AMQP content frames\n");
printf ("  --direct         Enables Direct Mode for client connections\n");
printf ("  --private_credit  Credit window for private queues\n");
printf ("  --shared_credit  Credit window for shared queues\n");
printf ("  --backup         Failover backup host:port\n");
printf ("  --primary        Failover primary host:port\n");
printf ("  --failover_timeout  Failover timeout, in seconds\n");
printf ("  --attach         Enable auto-federation to specified host\n");
printf ("  --attach_vhost   Auto-federation virtual host name\n");
printf ("  --attach_login   Auto-federation login user name\n");
printf ("  --attach_all     Auto-federate exchanges by pattern\n");
printf ("  --batching       Maximum size of Direct Mode batches\n");
printf ("  --direct_heartbeat  Heartbeat timer, seconds for Direct Mode\n");
printf ("  --no_ack         Do not implement acknowledgments\n");
printf ("  --auto_crash     Auto-crash test timer, seconds\n");
printf ("  --auto_block     Auto-freeze test timer, seconds\n");
printf ("  --kernel_limit   SMT kernel limit\n");
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CMDLINE_HELP))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CMDLINE_HELP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_cmdline_help_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_config_cmdline_parse

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    Parses recognized command-line options and processes, starting
    with --, prints an error message and exits if the syntax is invalid.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_cmdline_parse (
    amq_server_config_t * self,         //  Reference to object
    char * name,                        //  Name of application
    int argc,                           //  Argument count
    char ** argv                        //  Argument list
)
{
int
    argn;                           //  Argument number
char
    *arg_name,
    *arg_value;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CMDLINE_PARSE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_cmdline_parse_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" argc=\"%i\""
" argv=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, argc, argv);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CMDLINE_PARSE))
    icl_trace_record (NULL, amq_server_config_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CMDLINE_PARSE))
    icl_stats_inc ("amq_server_config_cmdline_parse", &s_amq_server_config_cmdline_parse_stats);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

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
            if (streq (arg_name, "--archive_path"))
                self_set_archive_path (self, arg_value);
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CMDLINE_PARSE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CMDLINE_PARSE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_cmdline_parse_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" argc=\"%i\""
" argv=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, argc, argv, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_options_help

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    Prints full help for all configuration options.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_options_help (
    amq_server_config_t * self,         //  Reference to object
    char * name                         //  Name of application
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_OPTIONS_HELP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_options_help_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_OPTIONS_HELP))
    icl_trace_record (NULL, amq_server_config_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_OPTIONS_HELP))
    icl_stats_inc ("amq_server_config_options_help", &s_amq_server_config_options_help_stats);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

printf ("\nThese are the configured options for %s\n\n", name);

printf ("/config/server/port - Server port for clients\n");
printf ("    From command-line: --port newvalue\n");
printf ("    Specifies the port on which the server should open its connections.\n");
printf ("    Current value is '%s'. Default value is '5672'\n", self->port);
printf ("\n");

printf ("/config/server/listen - Address (local network interface) to listen on\n");
printf ("    From command-line: --listen newvalue\n");
printf ("    Specifies the network interface on which the server should listen for  \n");
printf ("    connections. By default this is *, meaning all interfaces. You would   \n");
printf ("    choose to set an address when you use OpenAMQ on a server with multiple\n");
printf ("    network interfaces, e.g. routing between two networks.                 \n");
printf ("    Current value is '%s'. Default value is '*'\n", self->listen);
printf ("\n");

printf ("/config/server/queue_timeout - Timeout for auto-deleted queues\n");
printf ("    From command-line: --queue_timeout newvalue\n");
printf ("    Specifies the delay, in seconds, after which auto-deleted queues are   \n");
printf ("    effectively deleted, following disconnection of their last consumer. If\n");
printf ("    zero, queues are deleted immediately.                                  \n");
printf ("    Current value is %i. Default value is 0.\n", self->queue_timeout);
printf ("\n");

printf ("/config/server/vhost - Server vhost identifier\n");
printf ("    From command-line: --vhost newvalue\n");
printf ("    Specifies the virtual host name, an arbitrary string. OpenAMQ does not  \n");
printf ("    implement virtual hosts but uses this string to identify servers to     \n");
printf ("    prevent client applications from mistakenly connecting to the wrong     \n");
printf ("    server. We recommend you set this on production servers and on all      \n");
printf ("    failover pairs. Note that the two servers in a failover pair must use an\n");
printf ("    identical vhost identifier.                                             \n");
printf ("    Current value is '%s'. Default value is '/'\n", self->vhost);
printf ("\n");

printf ("/config/server/user - User to run server as\n");
printf ("    From command-line: --user newvalue\n");
printf ("    If you specify a user and group, the server will switch to that user and\n");
printf ("    group after opening its port, thus dropping any privileges it previously\n");
printf ("    had.                                                                    \n");
printf ("    Current value is '%s'.\n", self->user);
printf ("\n");

printf ("/config/server/group - Group to run server as\n");
printf ("    From command-line: --group newvalue\n");
printf ("    If you specify a user and group, the server will switch to that user and\n");
printf ("    group after opening its port, thus dropping any privileges it previously\n");
printf ("    had.                                                                    \n");
printf ("    Current value is '%s'.\n", self->group);
printf ("\n");

printf ("/config/resources/monitor - Monitor interval, seconds\n");
printf ("    From command-line: --monitor newvalue\n");
printf ("    Specifies the interval in seconds at which the server will report its   \n");
printf ("    message rates. If zero, no monitoring is shown. The recommended value is\n");
printf ("    1, if monitoring is desired.                                            \n");
printf ("    Current value is %i. Default value is 0.\n", self->monitor);
printf ("\n");

printf ("/config/resources/dump_state - Dump state interval, seconds\n");
printf ("    From command-line: --dump_state newvalue\n");
printf ("    Specifies the interval at which the server will report its state. This\n");
printf ("    shows the number of messages, queues, consumers, etc. used by the     \n");
printf ("    server. If zero, no state is logged.                                  \n");
printf ("    Current value is %i. Default value is 60.\n", self->dump_state);
printf ("\n");

printf ("/config/resources/record_stats - Record performance statistics\n");
printf ("    From command-line: --record_stats newvalue\n");
printf ("    Specifies whether or not the server records performance statistics in a \n");
printf ("    format suitable for importing into a spreadsheet. If set, the server    \n");
printf ("    creates a file called 'amq_server_stats_(portnumber).del' which contains\n");
printf ("    performance statistics in a comma-delimited format. For this setting to \n");
printf ("    take effect, the monitor option must also be set.                       \n");
printf ("    Current value is %i. Default value is 0.\n", self->record_stats);
printf ("\n");

printf ("/config/logging/log_path - Active log file directory\n");
printf ("    From command-line: --log_path newvalue\n");
printf ("    Specifies the directory path into which active log files are placed.\n");
printf ("    Current value is '%s'. Default value is 'logs'\n", self->log_path);
printf ("\n");

printf ("/config/logging/keep_logs - Keep log files\n");
printf ("    From command-line: --keep_logs newvalue\n");
printf ("    Specifies whether or not the server should keep logs. If zero, the      \n");
printf ("    server will not keep logs. If 1, it will keep an alert log, a daily log,\n");
printf ("    and a debug log as specified.                                           \n");
printf ("    Current value is %i. Default value is 1.\n", self->keep_logs);
printf ("\n");

printf ("/config/logging/archive_path - Archive log file directory\n");
printf ("    From command-line: --archive_path newvalue\n");
printf ("    Specifies the directory path into which archived log files are placed. \n");
printf ("    This can be the same as the active path; archived log files are renamed\n");
printf ("    to avoid conflict with active log files.                               \n");
printf ("    Current value is '%s'. Default value is 'archive'\n", self->archive_path);
printf ("\n");

printf ("/config/logging/archive_cmd - Archive log file command\n");
printf ("    From command-line: --archive_cmd newvalue\n");
printf ("    If specified, this command is run on all archived log files. You can use\n");
printf ("    this option to compress archived log files, or clean up old and unwanted\n");
printf ("    files. When the command is run, the name of the archived log file is    \n");
printf ("    provided to it as a single argument.                                    \n");
printf ("    Current value is '%s'.\n", self->archive_cmd);
printf ("\n");

printf ("/config/logging/alert_log - Error log file name\n");
printf ("    From command-line: --alert_log newvalue\n");
printf ("    The name of the alert log file, which records all errors and warnings \n");
printf ("    issued by the server. Note that the server port number is always added\n");
printf ("    to the name of the log file.                                          \n");
printf ("    Current value is '%s'. Default value is 'alert.log'\n", self->alert_log);
printf ("\n");

printf ("/config/logging/daily_log - Daily log file name\n");
printf ("    From command-line: --daily_log newvalue\n");
printf ("    The name of the daily log file, which records all normal activity as   \n");
printf ("    well as errors. Note that the server port number is always added to the\n");
printf ("    name of the log file.                                                  \n");
printf ("    Current value is '%s'. Default value is 'daily.log'\n", self->daily_log);
printf ("\n");

printf ("/config/logging/debug_log - Debug log file name\n");
printf ("    From command-line: --debug_log newvalue\n");
printf ("    The name of the debug log file, which records all normal activity,      \n");
printf ("    errors, and debug trace information. Note that the server port number is\n");
printf ("    always added to the name of the log file.                               \n");
printf ("    Current value is '%s'. Default value is 'debug.log'\n", self->debug_log);
printf ("\n");

printf ("/config/logging/debug_route - Debug message routing?\n");
printf ("    From command-line: --debug_route newvalue\n");
printf ("    Specifies whether exchange routing is logged or not. Set this option   \n");
printf ("    when you are debugging a message routing design. For production use, we\n");
printf ("    recommend you do not set this option.                                  \n");
printf ("    Current value is %i. Default value is 0.\n", self->debug_route);
printf ("\n");

printf ("/config/logging/debug_queue - Debug queue activity?\n");
printf ("    From command-line: --debug_queue newvalue\n");
printf ("    Specifies whether queue dispatching is logged or not. Set this option  \n");
printf ("    when you are debugging message processing in the server. For production\n");
printf ("    use, we recommend you do not set this option.                          \n");
printf ("    Current value is %i. Default value is 0.\n", self->debug_queue);
printf ("\n");

printf ("/config/logging/debug_peering - Debug peering messages?\n");
printf ("    From command-line: --debug_peering newvalue\n");
printf ("    Specifies whether peering activity is logged or not. Set this option if\n");
printf ("    you need to debug exchange federation and failover. For production use,\n");
printf ("    we recommend you do not set this option.                               \n");
printf ("    Current value is %i. Default value is 0.\n", self->debug_peering);
printf ("\n");

printf ("/config/logging/debug_console - Debug console I/O?\n");
printf ("    From command-line: --debug_console newvalue\n");
printf ("    Specifies whether console activity is logged or not. Set this option  \n");
printf ("    when you are configuring or debugging the console. For production use,\n");
printf ("    we recommend you do not set this option.                              \n");
printf ("    Current value is %i. Default value is 0.\n", self->debug_console);
printf ("\n");

printf ("/config/logging/trace - Protocol trace level\n");
printf ("    From command-line: --trace newvalue\n");
printf ("    Specifies the protocol debug level, which can be 0 (no tracing), 1 (show\n");
printf ("    information and protocol methods), 2 (show protocol animation), 3 (show \n");
printf ("    wire-level data). You should not use any tracing on production servers  \n");
printf ("    except in low-volume scenarios.                                         \n");
printf ("    Current value is %i. Default value is 0.\n", self->trace);
printf ("\n");

printf ("/config/tuning/heartbeat - Heartbeat timer, seconds\n");
printf ("    From command-line: --heartbeat newvalue\n");
printf ("    Defines the timeout for connection heartbeating.\n");
printf ("    Current value is %i. Default value is 2.\n", self->heartbeat);
printf ("\n");

printf ("/config/tuning/setup_timeout - Connection setup timeout, seconds\n");
printf ("    From command-line: --setup_timeout newvalue\n");
printf ("    Defines the maximum amount of time connection negotiation may take,\n");
printf ("    before the connection is forcibly closed by the server.            \n");
printf ("    Current value is %i. Default value is 5.\n", self->setup_timeout);
printf ("\n");

printf ("/config/tuning/close_timeout - Connection close timeout, seconds\n");
printf ("    From command-line: --close_timeout newvalue\n");
printf ("    Defines the maximum amount of time the server will wait for a client to\n");
printf ("    send a connection.close-ok when closing the connection due to an       \n");
printf ("    exception.                                                             \n");
printf ("    Current value is %i. Default value is 5.\n", self->close_timeout);
printf ("\n");

printf ("/config/tuning/accept_retry_timeout - Timeout before retrying accept calls, seconds\n");
printf ("    From command-line: --accept_retry_timeout newvalue\n");
printf ("    Defines the amount of time the server will wait before retrying an    \n");
printf ("    accept call if the call failed due to running out of file descriptors.\n");
printf ("    Current value is %i. Default value is 60.\n", self->accept_retry_timeout);
printf ("\n");

printf ("/config/tuning/polling_threads - Number of polling OS threads\n");
printf ("    From command-line: --polling_threads newvalue\n");
printf ("    On multithreaded builds, defines the number of OS threads dedicated to\n");
printf ("    socket polling.                                                       \n");
printf ("    Current value is %i. Default value is 4.\n", self->polling_threads);
printf ("\n");

printf ("/config/tuning/working_threads - Number of working OS threads\n");
printf ("    From command-line: --working_threads newvalue\n");
printf ("    On multithreaded builds, defines the number of OS threads dedicated to\n");
printf ("    processing, that is, tasks other than socket polling.                 \n");
printf ("    Current value is %i. Default value is 4.\n", self->working_threads);
printf ("\n");

printf ("/config/tuning/tcp_nodelay - TCP/IP NODELAY option\n");
printf ("    From command-line: --tcp_nodelay newvalue\n");
printf ("    If this value is 1, socket data is written immediately, which is usually\n");
printf ("    good for latency. If this value is 0, data is buffered until there is a \n");
printf ("    full packet, which is usually good for throughput.                      \n");
printf ("    Current value is %i. Default value is 1.\n", self->tcp_nodelay);
printf ("\n");

printf ("/config/tuning/tcp_rcvbuf - TCP/IP receive buffer, in bytes\n");
printf ("    From command-line: --tcp_rcvbuf newvalue\n");
printf ("    If this value is greater than zero, all client connections will use the\n");
printf ("    specified value. Note: setting this value is delicate, do not use this \n");
printf ("    option unless you know what you are doing.                             \n");
printf ("    Current value is %i. Default value is 0.\n", self->tcp_rcvbuf);
printf ("\n");

printf ("/config/tuning/tcp_sndbuf - TCP/IP send buffer, in bytes\n");
printf ("    From command-line: --tcp_sndbuf newvalue\n");
printf ("    If this value is greater than zero, all client connections will use the\n");
printf ("    specified value. Note: setting this value is delicate, do not use this \n");
printf ("    option unless you know what you are doing.                             \n");
printf ("    Current value is %i. Default value is 0.\n", self->tcp_sndbuf);
printf ("\n");

printf ("/config/tuning/frame_max - Maximum size of AMQP content frames\n");
printf ("    From command-line: --frame_max newvalue\n");
printf ("    Defines the maximum frame size the server will accept. Larger frame     \n");
printf ("    sizes are useful for applications that create very large message headers\n");
printf ("    but will cause congestion on multi-channel connections.                 \n");
printf ("    Current value is %i. Default value is 32768.\n", self->frame_max);
printf ("\n");

printf ("/config/tuning/direct - Enables Direct Mode for client connections\n");
printf ("    From command-line: --direct newvalue\n");
printf ("    If set to 1, new connections will by default use Direct Mode.   \n");
printf ("    Applications can override this by setting the connection->direct\n");
printf ("    property on new connections.                                    \n");
printf ("    Current value is %i. Default value is 0.\n", self->direct);
printf ("\n");

printf ("/config/tuning/private_credit - Credit window for private queues\n");
printf ("    From command-line: --private_credit newvalue\n");
printf ("    Defines the credit window for private queues. The credit window         \n");
printf ("    regulates the flow of messages internally. A higher value will move     \n");
printf ("    messages faster off private message queues and into the protocol        \n");
printf ("    transport threads. This will increase server memory consumption (before \n");
printf ("    configured queue limits are applied) but can improve performance. For   \n");
printf ("    high performance applications we recommend using Direct Mode. To disable\n");
printf ("    credit based flow control on private queues, set to zero.               \n");
printf ("    Current value is %i. Default value is 1024.\n", self->private_credit);
printf ("\n");

printf ("/config/tuning/shared_credit - Credit window for shared queues\n");
printf ("    From command-line: --shared_credit newvalue\n");
printf ("    Defines the credit window for shared queues. The credit window regulates\n");
printf ("    the flow of messages internally. The default value of 1 will provide the\n");
printf ("    best response to blocked/slow clients working on shared queues. Set to  \n");
printf ("    zero to disable credit based flow control on shared queues.             \n");
printf ("    Current value is %i. Default value is 1.\n", self->shared_credit);
printf ("\n");

printf ("/config/failover/backup - Failover backup host:port\n");
printf ("    From command-line: --backup newvalue\n");
printf ("    Used when running the primary server, specifies the failover backup \n");
printf ("    server for the high-availability pair. Use the internet name of the \n");
printf ("    backup server as 'host' or 'host:port' if it is not running on port \n");
printf ("    5672. Do not specify this option together with the 'primary' option.\n");
printf ("    Current value is '%s'. Default value is ''\n", self->backup);
printf ("\n");

printf ("/config/failover/primary - Failover primary host:port\n");
printf ("    From command-line: --primary newvalue\n");
printf ("    Used when running the backup server, specifies the failover primary \n");
printf ("    server for the high-availability pair. Use the internet name of the \n");
printf ("    primary server as 'host' or 'host:port' if it is not running on port\n");
printf ("    5672. Do not specify this option together with the 'backup' option. \n");
printf ("    Current value is '%s'. Default value is ''\n", self->primary);
printf ("\n");

printf ("/config/failover/timeout - Failover timeout, in seconds\n");
printf ("    From command-line: --failover_timeout newvalue\n");
printf ("    Specifies the delay in seconds after which the backup peer will become \n");
printf ("    the primary peer. This switch over will happen only if and when an     \n");
printf ("    application connects to the backup peer after the failover timeout has \n");
printf ("    expired. Reducing this value will allow failover to happen faster but  \n");
printf ("    will increase the risk of unnecessary failover due to transient network\n");
printf ("    issues.                                                                \n");
printf ("    Current value is %i. Default value is 5.\n", self->failover_timeout);
printf ("\n");

printf ("/config/federation/attach - Enable auto-federation to specified host\n");
printf ("    From command-line: --attach newvalue\n");
printf ("    If specified, the server will auto-federate to the specified parent    \n");
printf ("    OpenAMQ server. This federates three exchanges: amq.service (a direct  \n");
printf ("    exchange) using a service federation; amq.data (a topic exchange) using\n");
printf ("    a fanout federation; and amq.dataex (a headers exchange) using a fanout\n");
printf ("    exchange. This gives you an instant enterprise service bus (ESB) based \n");
printf ("    on a spoke-and-hub model. You can fine-tune auto-federation using the  \n");
printf ("    --attach-login and --attach-vhost options.                             \n");
printf ("    Current value is '%s'. Default value is ''\n", self->attach);
printf ("\n");

printf ("/config/federation/attach_vhost - Auto-federation virtual host name\n");
printf ("    From command-line: --attach_vhost newvalue\n");
printf ("    Specifies the auto-federation vhost name, an arbitrary string that will\n");
printf ("    be used when connecting to the parent server. This must match the vhost\n");
printf ("    setting of the parent server.                                          \n");
printf ("    Current value is '%s'. Default value is '/'\n", self->attach_vhost);
printf ("\n");

printf ("/config/federation/attach_login - Auto-federation login user name\n");
printf ("    From command-line: --attach_login newvalue\n");
printf ("    Specifies the user name to be used when logging in. You do not need to\n");
printf ("    specify a password, it is taken from the security section.            \n");
printf ("    Current value is '%s'. Default value is 'peering'\n", self->attach_login);
printf ("\n");

printf ("/config/federation/attach_all - Auto-federate exchanges by pattern\n");
printf ("    From command-line: --attach_all newvalue\n");
printf ("    If set, the server will auto-federate all exchanges that match the      \n");
printf ("    specified pattern which can include * and ? to mean zero or more, or a  \n");
printf ("    single arbitrary character. You can use naming conventions to federate  \n");
printf ("    specific groups of exchanges. Put quotes around wildcards to avoid shell\n");
printf ("    expansion.                                                              \n");
printf ("    Current value is '%s'. Default value is ''\n", self->attach_all);
printf ("\n");

printf ("/config/direct/batching - Maximum size of Direct Mode batches\n");
printf ("    From command-line: --batching newvalue\n");
printf ("    Defines the maximum batch size for Direct Mode opportunistic batching on\n");
printf ("    message sends. Setting this higher will improve throughput, and usually \n");
printf ("    with lower latency, but will cause higher memory consumption. Setting   \n");
printf ("    this to zero will switch off batching. Any value less than 2048 is      \n");
printf ("    treated as zero.                                                        \n");
printf ("    Current value is %i. Default value is 32768.\n", self->batching);
printf ("\n");

printf ("/config/direct/heartbeat - Heartbeat timer, seconds for Direct Mode\n");
printf ("    From command-line: --direct_heartbeat newvalue\n");
printf ("    Defines the timeout for Direct Mode connection heartbeating.\n");
printf ("    Current value is %i. Default value is 2.\n", self->direct_heartbeat);
printf ("\n");

printf ("/config/compatibility/no_ack - Do not implement acknowledgments\n");
printf ("    From command-line: --no_ack newvalue\n");
printf ("    Provides backwards compatibility with earlier versions of OpenAMQ for  \n");
printf ("    use with shared queues. From 1.4b4 and 1.3d0 onwards OpenAMQ treats the\n");
printf ("    Basic.Consume no-ack flag as meaningful, whereas prior versions ignored\n");
printf ("    this flag. Applications that do not set this flag when consuming from  \n");
printf ("    shared queues must now issue Basic.Ack for each message they received. \n");
printf ("    The --no-ack option restores the prior way of working and allows old   \n");
printf ("    applications to work unchanged.                                        \n");
printf ("    Current value is %i. Default value is 0.\n", self->no_ack);
printf ("\n");

printf ("/config/internal/auto_crash - Auto-crash test timer, seconds\n");
printf ("    From command-line: --auto_crash newvalue\n");
printf ("    If set, the server will crash at irregular intervals, being some random\n");
printf ("    point within the number of seconds specified. This is used specifically\n");
printf ("    to test applications for failover and robustness. Set to zero for all  \n");
printf ("    real usage.                                                            \n");
printf ("    Current value is %i. Default value is 0.\n", self->auto_crash);
printf ("\n");

printf ("/config/internal/auto_block - Auto-freeze test timer, seconds\n");
printf ("    From command-line: --auto_block newvalue\n");
printf ("    If set, the server will block at irregular intervals, being some random\n");
printf ("    point within the number of seconds specified. This is used specifically\n");
printf ("    to test applications for failover and robustness. Set to zero for all  \n");
printf ("    real usage.                                                            \n");
printf ("    Current value is %i. Default value is 0.\n", self->auto_block);
printf ("\n");

printf ("/config/internal/kernel_limit - SMT kernel limit\n");
printf ("    From command-line: --kernel_limit newvalue\n");
printf ("    Sets an action limit for the SMT kernel: after this many steps it will \n");
printf ("    exit. Use this to break the server for failure testing. Set to zero for\n");
printf ("    all real usage.                                                        \n");
printf ("    Current value is %i. Default value is 0.\n", self->kernel_limit);
printf ("\n");

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_OPTIONS_HELP))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_OPTIONS_HELP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_options_help_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_port

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_port (
    amq_server_config_t * self,         //  Reference to object
    char * port                         //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_PORT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_port_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" port=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, port);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PORT))
    icl_trace_record (NULL, amq_server_config_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_PORT))
    icl_stats_inc ("amq_server_config_set_port", &s_amq_server_config_set_port_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/server", "port", port);
port = ipr_config_getp (self->config, "/config/server", "port", NULL);
assert (port);
icl_shortstr_cpy (self->port, port);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PORT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_PORT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_port_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" port=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, port, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_port

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_port (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        port;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_PORT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_port_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PORT))
    icl_trace_record (NULL, amq_server_config_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_PORT))
    icl_stats_inc ("amq_server_config_port", &s_amq_server_config_port_stats);
#endif

//
if (self)
    port = self->port;
else
    port = "5672";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PORT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_PORT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_port_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" port=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, port);
#endif


    return (port);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_listen

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_listen (
    amq_server_config_t * self,         //  Reference to object
    char * listen                       //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_LISTEN))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_listen_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" listen=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, listen);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_LISTEN))
    icl_trace_record (NULL, amq_server_config_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_LISTEN))
    icl_stats_inc ("amq_server_config_set_listen", &s_amq_server_config_set_listen_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/server", "listen", listen);
listen = ipr_config_getp (self->config, "/config/server", "listen", NULL);
assert (listen);
icl_shortstr_cpy (self->listen, listen);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_LISTEN))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_LISTEN))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_listen_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" listen=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, listen, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_listen

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_listen (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        listen;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_LISTEN))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_listen_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LISTEN))
    icl_trace_record (NULL, amq_server_config_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_LISTEN))
    icl_stats_inc ("amq_server_config_listen", &s_amq_server_config_listen_stats);
#endif

//
if (self)
    listen = self->listen;
else
    listen = "*";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LISTEN))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_LISTEN))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_listen_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" listen=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, listen);
#endif


    return (listen);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_queue_timeout

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_queue_timeout (
    amq_server_config_t * self,         //  Reference to object
    int queue_timeout                   //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_QUEUE_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_queue_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue_timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_QUEUE_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_QUEUE_TIMEOUT))
    icl_stats_inc ("amq_server_config_set_queue_timeout", &s_amq_server_config_set_queue_timeout_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", queue_timeout);
ipr_config_putp (self->config, "/config/server", "queue_timeout", strvalue);
self->queue_timeout = queue_timeout;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_QUEUE_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_QUEUE_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_queue_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue_timeout=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue_timeout, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_queue_timeout

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_queue_timeout (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        queue_timeout;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_QUEUE_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_queue_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_QUEUE_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_QUEUE_TIMEOUT))
    icl_stats_inc ("amq_server_config_queue_timeout", &s_amq_server_config_queue_timeout_stats);
#endif

//
if (self)
    queue_timeout = self->queue_timeout;
else
    queue_timeout = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_QUEUE_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_QUEUE_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_queue_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue_timeout);
#endif


    return (queue_timeout);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_vhost

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_vhost (
    amq_server_config_t * self,         //  Reference to object
    char * vhost                        //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_VHOST))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_vhost_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" vhost=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, vhost);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_VHOST))
    icl_trace_record (NULL, amq_server_config_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_VHOST))
    icl_stats_inc ("amq_server_config_set_vhost", &s_amq_server_config_set_vhost_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/server", "vhost", vhost);
vhost = ipr_config_getp (self->config, "/config/server", "vhost", NULL);
assert (vhost);
icl_shortstr_cpy (self->vhost, vhost);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_VHOST))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_VHOST))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_vhost_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" vhost=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, vhost, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_vhost

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_vhost (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        vhost;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_VHOST))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_vhost_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_VHOST))
    icl_trace_record (NULL, amq_server_config_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_VHOST))
    icl_stats_inc ("amq_server_config_vhost", &s_amq_server_config_vhost_stats);
#endif

//
if (self)
    vhost = self->vhost;
else
    vhost = "/";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_VHOST))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_VHOST))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_vhost_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" vhost=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, vhost);
#endif


    return (vhost);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_user

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_user (
    amq_server_config_t * self,         //  Reference to object
    char * user                         //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_USER))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_user_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" user=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, user);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_USER))
    icl_trace_record (NULL, amq_server_config_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_USER))
    icl_stats_inc ("amq_server_config_set_user", &s_amq_server_config_set_user_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/server", "user", user);
user = ipr_config_getp (self->config, "/config/server", "user", NULL);
assert (user);
self->user = user;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_USER))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_USER))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_user_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" user=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, user, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_user

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_user (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        user;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_USER))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_user_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_USER))
    icl_trace_record (NULL, amq_server_config_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_USER))
    icl_stats_inc ("amq_server_config_user", &s_amq_server_config_user_stats);
#endif

//
if (self)
    user = self->user;
else
    user = "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_USER))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_USER))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_user_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" user=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, user);
#endif


    return (user);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_group

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_group (
    amq_server_config_t * self,         //  Reference to object
    char * group                        //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_GROUP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_group_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" group=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, group);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_GROUP))
    icl_trace_record (NULL, amq_server_config_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_GROUP))
    icl_stats_inc ("amq_server_config_set_group", &s_amq_server_config_set_group_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/server", "group", group);
group = ipr_config_getp (self->config, "/config/server", "group", NULL);
assert (group);
self->group = group;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_GROUP))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_GROUP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_group_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" group=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, group, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_group

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_group (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        group;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_GROUP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_group_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_GROUP))
    icl_trace_record (NULL, amq_server_config_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_GROUP))
    icl_stats_inc ("amq_server_config_group", &s_amq_server_config_group_stats);
#endif

//
if (self)
    group = self->group;
else
    group = "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_GROUP))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_GROUP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_group_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" group=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, group);
#endif


    return (group);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_monitor

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_monitor (
    amq_server_config_t * self,         //  Reference to object
    int monitor                         //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_MONITOR))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_monitor_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" monitor=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, monitor);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_MONITOR))
    icl_trace_record (NULL, amq_server_config_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_MONITOR))
    icl_stats_inc ("amq_server_config_set_monitor", &s_amq_server_config_set_monitor_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", monitor);
ipr_config_putp (self->config, "/config/resources", "monitor", strvalue);
self->monitor = monitor;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_MONITOR))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_MONITOR))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_monitor_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" monitor=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, monitor, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_monitor

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_monitor (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        monitor;                        //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_MONITOR))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_monitor_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_MONITOR))
    icl_trace_record (NULL, amq_server_config_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_MONITOR))
    icl_stats_inc ("amq_server_config_monitor", &s_amq_server_config_monitor_stats);
#endif

//
if (self)
    monitor = self->monitor;
else
    monitor = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_MONITOR))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_MONITOR))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_monitor_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" monitor=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, monitor);
#endif


    return (monitor);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_dump_state

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_dump_state (
    amq_server_config_t * self,         //  Reference to object
    int dump_state                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DUMP_STATE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_dump_state_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" dump_state=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, dump_state);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DUMP_STATE))
    icl_trace_record (NULL, amq_server_config_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DUMP_STATE))
    icl_stats_inc ("amq_server_config_set_dump_state", &s_amq_server_config_set_dump_state_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", dump_state);
ipr_config_putp (self->config, "/config/resources", "dump_state", strvalue);
self->dump_state = dump_state;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DUMP_STATE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DUMP_STATE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_dump_state_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" dump_state=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, dump_state, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_dump_state

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_dump_state (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        dump_state;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DUMP_STATE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_dump_state_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DUMP_STATE))
    icl_trace_record (NULL, amq_server_config_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DUMP_STATE))
    icl_stats_inc ("amq_server_config_dump_state", &s_amq_server_config_dump_state_stats);
#endif

//
if (self)
    dump_state = self->dump_state;
else
    dump_state = 60;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DUMP_STATE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DUMP_STATE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_dump_state_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" dump_state=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, dump_state);
#endif


    return (dump_state);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_record_stats

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_record_stats (
    amq_server_config_t * self,         //  Reference to object
    Bool record_stats                   //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_RECORD_STATS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_record_stats_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" record_stats=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, record_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_RECORD_STATS))
    icl_trace_record (NULL, amq_server_config_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_RECORD_STATS))
    icl_stats_inc ("amq_server_config_set_record_stats", &s_amq_server_config_set_record_stats_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", record_stats);
ipr_config_putp (self->config, "/config/resources", "record_stats", strvalue);
self->record_stats = record_stats;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_RECORD_STATS))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_RECORD_STATS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_record_stats_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" record_stats=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, record_stats, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_record_stats

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_server_config_record_stats (
    amq_server_config_t * self          //  Reference to self
)
{
    Bool
        record_stats;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_RECORD_STATS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_record_stats_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_RECORD_STATS))
    icl_trace_record (NULL, amq_server_config_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_RECORD_STATS))
    icl_stats_inc ("amq_server_config_record_stats", &s_amq_server_config_record_stats_stats);
#endif

//
if (self)
    record_stats = self->record_stats;
else
    record_stats = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_RECORD_STATS))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_RECORD_STATS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_record_stats_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" record_stats=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, record_stats);
#endif


    return (record_stats);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_log_path

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_log_path (
    amq_server_config_t * self,         //  Reference to object
    char * log_path                     //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_LOG_PATH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_log_path_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" log_path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, log_path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_LOG_PATH))
    icl_trace_record (NULL, amq_server_config_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_LOG_PATH))
    icl_stats_inc ("amq_server_config_set_log_path", &s_amq_server_config_set_log_path_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "log_path", log_path);
log_path = ipr_config_getp (self->config, "/config/logging", "log_path", NULL);
assert (log_path);
icl_shortstr_cpy (self->log_path, log_path);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_LOG_PATH))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_LOG_PATH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_log_path_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" log_path=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, log_path, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_log_path

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_log_path (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        log_path;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_LOG_PATH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_log_path_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOG_PATH))
    icl_trace_record (NULL, amq_server_config_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_LOG_PATH))
    icl_stats_inc ("amq_server_config_log_path", &s_amq_server_config_log_path_stats);
#endif

//
if (self)
    log_path = self->log_path;
else
    log_path = "logs";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOG_PATH))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_LOG_PATH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_log_path_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" log_path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, log_path);
#endif


    return (log_path);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_keep_logs

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_keep_logs (
    amq_server_config_t * self,         //  Reference to object
    Bool keep_logs                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_KEEP_LOGS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_keep_logs_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" keep_logs=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, keep_logs);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_KEEP_LOGS))
    icl_trace_record (NULL, amq_server_config_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_KEEP_LOGS))
    icl_stats_inc ("amq_server_config_set_keep_logs", &s_amq_server_config_set_keep_logs_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", keep_logs);
ipr_config_putp (self->config, "/config/logging", "keep_logs", strvalue);
self->keep_logs = keep_logs;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_KEEP_LOGS))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_KEEP_LOGS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_keep_logs_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" keep_logs=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, keep_logs, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_keep_logs

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_server_config_keep_logs (
    amq_server_config_t * self          //  Reference to self
)
{
    Bool
        keep_logs;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_KEEP_LOGS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_keep_logs_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_KEEP_LOGS))
    icl_trace_record (NULL, amq_server_config_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_KEEP_LOGS))
    icl_stats_inc ("amq_server_config_keep_logs", &s_amq_server_config_keep_logs_stats);
#endif

//
if (self)
    keep_logs = self->keep_logs;
else
    keep_logs = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_KEEP_LOGS))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_KEEP_LOGS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_keep_logs_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" keep_logs=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, keep_logs);
#endif


    return (keep_logs);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_archive_path

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_archive_path (
    amq_server_config_t * self,         //  Reference to object
    char * archive_path                 //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ARCHIVE_PATH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_archive_path_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ARCHIVE_PATH))
    icl_trace_record (NULL, amq_server_config_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ARCHIVE_PATH))
    icl_stats_inc ("amq_server_config_set_archive_path", &s_amq_server_config_set_archive_path_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "archive_path", archive_path);
archive_path = ipr_config_getp (self->config, "/config/logging", "archive_path", NULL);
assert (archive_path);
icl_shortstr_cpy (self->archive_path, archive_path);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ARCHIVE_PATH))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ARCHIVE_PATH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_archive_path_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_path=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_path, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_archive_path

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_archive_path (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        archive_path;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ARCHIVE_PATH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_archive_path_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ARCHIVE_PATH))
    icl_trace_record (NULL, amq_server_config_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ARCHIVE_PATH))
    icl_stats_inc ("amq_server_config_archive_path", &s_amq_server_config_archive_path_stats);
#endif

//
if (self)
    archive_path = self->archive_path;
else
    archive_path = "archive";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ARCHIVE_PATH))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ARCHIVE_PATH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_archive_path_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_path);
#endif


    return (archive_path);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_archive_cmd

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_archive_cmd (
    amq_server_config_t * self,         //  Reference to object
    char * archive_cmd                  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ARCHIVE_CMD))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_archive_cmd_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_cmd=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_cmd);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ARCHIVE_CMD))
    icl_trace_record (NULL, amq_server_config_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ARCHIVE_CMD))
    icl_stats_inc ("amq_server_config_set_archive_cmd", &s_amq_server_config_set_archive_cmd_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "archive_cmd", archive_cmd);
archive_cmd = ipr_config_getp (self->config, "/config/logging", "archive_cmd", NULL);
assert (archive_cmd);
icl_shortstr_cpy (self->archive_cmd, archive_cmd);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ARCHIVE_CMD))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ARCHIVE_CMD))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_archive_cmd_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_cmd=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_cmd, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_archive_cmd

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_archive_cmd (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        archive_cmd;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ARCHIVE_CMD))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_archive_cmd_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ARCHIVE_CMD))
    icl_trace_record (NULL, amq_server_config_dump, 35);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ARCHIVE_CMD))
    icl_stats_inc ("amq_server_config_archive_cmd", &s_amq_server_config_archive_cmd_stats);
#endif

//
if (self)
    archive_cmd = self->archive_cmd;
else
    archive_cmd = "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ARCHIVE_CMD))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 35);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ARCHIVE_CMD))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_archive_cmd_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_cmd=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_cmd);
#endif


    return (archive_cmd);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_alert_log

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_alert_log (
    amq_server_config_t * self,         //  Reference to object
    char * alert_log                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ALERT_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_alert_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" alert_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, alert_log);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ALERT_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 36);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ALERT_LOG))
    icl_stats_inc ("amq_server_config_set_alert_log", &s_amq_server_config_set_alert_log_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "alert_log", alert_log);
alert_log = ipr_config_getp (self->config, "/config/logging", "alert_log", NULL);
assert (alert_log);
icl_shortstr_cpy (self->alert_log, alert_log);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ALERT_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 36);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ALERT_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_alert_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" alert_log=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, alert_log, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_alert_log

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_alert_log (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        alert_log;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ALERT_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_alert_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ALERT_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 37);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ALERT_LOG))
    icl_stats_inc ("amq_server_config_alert_log", &s_amq_server_config_alert_log_stats);
#endif

//
if (self)
    alert_log = self->alert_log;
else
    alert_log = "alert.log";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ALERT_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 37);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ALERT_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_alert_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" alert_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, alert_log);
#endif


    return (alert_log);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_daily_log

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_daily_log (
    amq_server_config_t * self,         //  Reference to object
    char * daily_log                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DAILY_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_daily_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" daily_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, daily_log);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DAILY_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 38);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DAILY_LOG))
    icl_stats_inc ("amq_server_config_set_daily_log", &s_amq_server_config_set_daily_log_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "daily_log", daily_log);
daily_log = ipr_config_getp (self->config, "/config/logging", "daily_log", NULL);
assert (daily_log);
icl_shortstr_cpy (self->daily_log, daily_log);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DAILY_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 38);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DAILY_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_daily_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" daily_log=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, daily_log, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_daily_log

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_daily_log (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        daily_log;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DAILY_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_daily_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DAILY_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 39);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DAILY_LOG))
    icl_stats_inc ("amq_server_config_daily_log", &s_amq_server_config_daily_log_stats);
#endif

//
if (self)
    daily_log = self->daily_log;
else
    daily_log = "daily.log";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DAILY_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 39);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DAILY_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_daily_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" daily_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, daily_log);
#endif


    return (daily_log);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_debug_log

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_debug_log (
    amq_server_config_t * self,         //  Reference to object
    char * debug_log                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DEBUG_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_debug_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_log);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 40);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DEBUG_LOG))
    icl_stats_inc ("amq_server_config_set_debug_log", &s_amq_server_config_set_debug_log_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "debug_log", debug_log);
debug_log = ipr_config_getp (self->config, "/config/logging", "debug_log", NULL);
assert (debug_log);
icl_shortstr_cpy (self->debug_log, debug_log);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 40);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DEBUG_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_debug_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_log=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_log, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_debug_log

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_debug_log (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        debug_log;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DEBUG_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_debug_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 41);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DEBUG_LOG))
    icl_stats_inc ("amq_server_config_debug_log", &s_amq_server_config_debug_log_stats);
#endif

//
if (self)
    debug_log = self->debug_log;
else
    debug_log = "debug.log";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 41);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DEBUG_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_debug_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_log);
#endif


    return (debug_log);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_debug_route

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_debug_route (
    amq_server_config_t * self,         //  Reference to object
    Bool debug_route                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DEBUG_ROUTE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_debug_route_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_route=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_route);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_ROUTE))
    icl_trace_record (NULL, amq_server_config_dump, 42);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DEBUG_ROUTE))
    icl_stats_inc ("amq_server_config_set_debug_route", &s_amq_server_config_set_debug_route_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", debug_route);
ipr_config_putp (self->config, "/config/logging", "debug_route", strvalue);
self->debug_route = debug_route;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_ROUTE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 42);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DEBUG_ROUTE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_debug_route_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_route=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_route, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_debug_route

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_server_config_debug_route (
    amq_server_config_t * self          //  Reference to self
)
{
    Bool
        debug_route;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DEBUG_ROUTE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_debug_route_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_ROUTE))
    icl_trace_record (NULL, amq_server_config_dump, 43);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DEBUG_ROUTE))
    icl_stats_inc ("amq_server_config_debug_route", &s_amq_server_config_debug_route_stats);
#endif

//
if (self)
    debug_route = self->debug_route;
else
    debug_route = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_ROUTE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 43);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DEBUG_ROUTE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_debug_route_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_route=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_route);
#endif


    return (debug_route);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_debug_queue

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_debug_queue (
    amq_server_config_t * self,         //  Reference to object
    Bool debug_queue                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DEBUG_QUEUE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_debug_queue_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_queue=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_queue);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_QUEUE))
    icl_trace_record (NULL, amq_server_config_dump, 44);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DEBUG_QUEUE))
    icl_stats_inc ("amq_server_config_set_debug_queue", &s_amq_server_config_set_debug_queue_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", debug_queue);
ipr_config_putp (self->config, "/config/logging", "debug_queue", strvalue);
self->debug_queue = debug_queue;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_QUEUE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 44);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DEBUG_QUEUE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_debug_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_queue=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_queue, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_debug_queue

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_server_config_debug_queue (
    amq_server_config_t * self          //  Reference to self
)
{
    Bool
        debug_queue;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DEBUG_QUEUE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_debug_queue_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_QUEUE))
    icl_trace_record (NULL, amq_server_config_dump, 45);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DEBUG_QUEUE))
    icl_stats_inc ("amq_server_config_debug_queue", &s_amq_server_config_debug_queue_stats);
#endif

//
if (self)
    debug_queue = self->debug_queue;
else
    debug_queue = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_QUEUE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 45);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DEBUG_QUEUE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_debug_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_queue=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_queue);
#endif


    return (debug_queue);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_debug_peering

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_debug_peering (
    amq_server_config_t * self,         //  Reference to object
    Bool debug_peering                  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DEBUG_PEERING))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_debug_peering_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_peering=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_peering);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_PEERING))
    icl_trace_record (NULL, amq_server_config_dump, 46);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DEBUG_PEERING))
    icl_stats_inc ("amq_server_config_set_debug_peering", &s_amq_server_config_set_debug_peering_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", debug_peering);
ipr_config_putp (self->config, "/config/logging", "debug_peering", strvalue);
self->debug_peering = debug_peering;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_PEERING))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 46);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DEBUG_PEERING))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_debug_peering_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_peering=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_peering, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_debug_peering

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_server_config_debug_peering (
    amq_server_config_t * self          //  Reference to self
)
{
    Bool
        debug_peering;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DEBUG_PEERING))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_debug_peering_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_PEERING))
    icl_trace_record (NULL, amq_server_config_dump, 47);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DEBUG_PEERING))
    icl_stats_inc ("amq_server_config_debug_peering", &s_amq_server_config_debug_peering_stats);
#endif

//
if (self)
    debug_peering = self->debug_peering;
else
    debug_peering = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_PEERING))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 47);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DEBUG_PEERING))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_debug_peering_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_peering=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_peering);
#endif


    return (debug_peering);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_debug_console

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_debug_console (
    amq_server_config_t * self,         //  Reference to object
    Bool debug_console                  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DEBUG_CONSOLE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_debug_console_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_console=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_console);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_CONSOLE))
    icl_trace_record (NULL, amq_server_config_dump, 48);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DEBUG_CONSOLE))
    icl_stats_inc ("amq_server_config_set_debug_console", &s_amq_server_config_set_debug_console_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", debug_console);
ipr_config_putp (self->config, "/config/logging", "debug_console", strvalue);
self->debug_console = debug_console;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_CONSOLE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 48);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DEBUG_CONSOLE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_debug_console_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_console=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_console, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_debug_console

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_server_config_debug_console (
    amq_server_config_t * self          //  Reference to self
)
{
    Bool
        debug_console;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DEBUG_CONSOLE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_debug_console_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_CONSOLE))
    icl_trace_record (NULL, amq_server_config_dump, 49);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DEBUG_CONSOLE))
    icl_stats_inc ("amq_server_config_debug_console", &s_amq_server_config_debug_console_stats);
#endif

//
if (self)
    debug_console = self->debug_console;
else
    debug_console = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_CONSOLE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 49);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DEBUG_CONSOLE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_debug_console_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_console=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_console);
#endif


    return (debug_console);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_trace

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_trace (
    amq_server_config_t * self,         //  Reference to object
    int trace                           //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_TRACE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_trace_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" trace=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, trace);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TRACE))
    icl_trace_record (NULL, amq_server_config_dump, 50);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_TRACE))
    icl_stats_inc ("amq_server_config_set_trace", &s_amq_server_config_set_trace_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", trace);
ipr_config_putp (self->config, "/config/logging", "trace", strvalue);
self->trace = trace;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TRACE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 50);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_TRACE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_trace_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" trace=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, trace, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_trace

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_trace (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        trace;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_TRACE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_trace_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TRACE))
    icl_trace_record (NULL, amq_server_config_dump, 51);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_TRACE))
    icl_stats_inc ("amq_server_config_trace", &s_amq_server_config_trace_stats);
#endif

//
if (self)
    trace = self->trace;
else
    trace = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TRACE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 51);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_TRACE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_trace_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" trace=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, trace);
#endif


    return (trace);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_heartbeat

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_heartbeat (
    amq_server_config_t * self,         //  Reference to object
    int heartbeat                       //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_HEARTBEAT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_heartbeat_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" heartbeat=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, heartbeat);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_HEARTBEAT))
    icl_trace_record (NULL, amq_server_config_dump, 52);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_HEARTBEAT))
    icl_stats_inc ("amq_server_config_set_heartbeat", &s_amq_server_config_set_heartbeat_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", heartbeat);
ipr_config_putp (self->config, "/config/tuning", "heartbeat", strvalue);
self->heartbeat = heartbeat;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_HEARTBEAT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 52);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_HEARTBEAT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_heartbeat_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" heartbeat=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, heartbeat, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_heartbeat

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_heartbeat (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        heartbeat;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_HEARTBEAT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_heartbeat_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_HEARTBEAT))
    icl_trace_record (NULL, amq_server_config_dump, 53);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_HEARTBEAT))
    icl_stats_inc ("amq_server_config_heartbeat", &s_amq_server_config_heartbeat_stats);
#endif

//
if (self)
    heartbeat = self->heartbeat;
else
    heartbeat = 2;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_HEARTBEAT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 53);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_HEARTBEAT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_heartbeat_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" heartbeat=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, heartbeat);
#endif


    return (heartbeat);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_setup_timeout

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_setup_timeout (
    amq_server_config_t * self,         //  Reference to object
    int setup_timeout                   //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_SETUP_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_setup_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" setup_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, setup_timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_SETUP_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 54);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_SETUP_TIMEOUT))
    icl_stats_inc ("amq_server_config_set_setup_timeout", &s_amq_server_config_set_setup_timeout_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", setup_timeout);
ipr_config_putp (self->config, "/config/tuning", "setup_timeout", strvalue);
self->setup_timeout = setup_timeout;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_SETUP_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 54);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_SETUP_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_setup_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" setup_timeout=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, setup_timeout, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_setup_timeout

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_setup_timeout (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        setup_timeout;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SETUP_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_setup_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SETUP_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 55);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SETUP_TIMEOUT))
    icl_stats_inc ("amq_server_config_setup_timeout", &s_amq_server_config_setup_timeout_stats);
#endif

//
if (self)
    setup_timeout = self->setup_timeout;
else
    setup_timeout = 5;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SETUP_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 55);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SETUP_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_setup_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" setup_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, setup_timeout);
#endif


    return (setup_timeout);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_close_timeout

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_close_timeout (
    amq_server_config_t * self,         //  Reference to object
    int close_timeout                   //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_CLOSE_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_close_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" close_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, close_timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_CLOSE_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 56);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_CLOSE_TIMEOUT))
    icl_stats_inc ("amq_server_config_set_close_timeout", &s_amq_server_config_set_close_timeout_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", close_timeout);
ipr_config_putp (self->config, "/config/tuning", "close_timeout", strvalue);
self->close_timeout = close_timeout;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_CLOSE_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 56);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_CLOSE_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_close_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" close_timeout=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, close_timeout, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_close_timeout

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_close_timeout (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        close_timeout;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CLOSE_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_close_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CLOSE_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 57);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CLOSE_TIMEOUT))
    icl_stats_inc ("amq_server_config_close_timeout", &s_amq_server_config_close_timeout_stats);
#endif

//
if (self)
    close_timeout = self->close_timeout;
else
    close_timeout = 5;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CLOSE_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 57);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CLOSE_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_close_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" close_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, close_timeout);
#endif


    return (close_timeout);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_accept_retry_timeout

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_accept_retry_timeout (
    amq_server_config_t * self,         //  Reference to object
    int accept_retry_timeout            //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ACCEPT_RETRY_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_accept_retry_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" accept_retry_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, accept_retry_timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ACCEPT_RETRY_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 58);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ACCEPT_RETRY_TIMEOUT))
    icl_stats_inc ("amq_server_config_set_accept_retry_timeout", &s_amq_server_config_set_accept_retry_timeout_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
if (accept_retry_timeout < 1) {
    icl_console_print ("W: <command line>: illegal value %d for accept_retry_timeout, using %d",
        accept_retry_timeout, 1);
    accept_retry_timeout = 1;
}
icl_shortstr_fmt (strvalue, "%i", accept_retry_timeout);
ipr_config_putp (self->config, "/config/tuning", "accept_retry_timeout", strvalue);
self->accept_retry_timeout = accept_retry_timeout;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ACCEPT_RETRY_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 58);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ACCEPT_RETRY_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_accept_retry_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" accept_retry_timeout=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, accept_retry_timeout, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_accept_retry_timeout

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_accept_retry_timeout (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        accept_retry_timeout;           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ACCEPT_RETRY_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_accept_retry_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ACCEPT_RETRY_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 59);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ACCEPT_RETRY_TIMEOUT))
    icl_stats_inc ("amq_server_config_accept_retry_timeout", &s_amq_server_config_accept_retry_timeout_stats);
#endif

//
if (self)
    accept_retry_timeout = self->accept_retry_timeout;
else
    accept_retry_timeout = 60;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ACCEPT_RETRY_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 59);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ACCEPT_RETRY_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_accept_retry_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" accept_retry_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, accept_retry_timeout);
#endif


    return (accept_retry_timeout);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_polling_threads

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_polling_threads (
    amq_server_config_t * self,         //  Reference to object
    int polling_threads                 //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_POLLING_THREADS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_polling_threads_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" polling_threads=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, polling_threads);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_POLLING_THREADS))
    icl_trace_record (NULL, amq_server_config_dump, 60);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_POLLING_THREADS))
    icl_stats_inc ("amq_server_config_set_polling_threads", &s_amq_server_config_set_polling_threads_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", polling_threads);
ipr_config_putp (self->config, "/config/tuning", "polling_threads", strvalue);
self->polling_threads = polling_threads;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_POLLING_THREADS))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 60);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_POLLING_THREADS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_polling_threads_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" polling_threads=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, polling_threads, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_polling_threads

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_polling_threads (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        polling_threads;                //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_POLLING_THREADS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_polling_threads_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_POLLING_THREADS))
    icl_trace_record (NULL, amq_server_config_dump, 61);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_POLLING_THREADS))
    icl_stats_inc ("amq_server_config_polling_threads", &s_amq_server_config_polling_threads_stats);
#endif

//
if (self)
    polling_threads = self->polling_threads;
else
    polling_threads = 4;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_POLLING_THREADS))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 61);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_POLLING_THREADS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_polling_threads_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" polling_threads=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, polling_threads);
#endif


    return (polling_threads);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_working_threads

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_working_threads (
    amq_server_config_t * self,         //  Reference to object
    int working_threads                 //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_WORKING_THREADS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_working_threads_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" working_threads=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, working_threads);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_WORKING_THREADS))
    icl_trace_record (NULL, amq_server_config_dump, 62);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_WORKING_THREADS))
    icl_stats_inc ("amq_server_config_set_working_threads", &s_amq_server_config_set_working_threads_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", working_threads);
ipr_config_putp (self->config, "/config/tuning", "working_threads", strvalue);
self->working_threads = working_threads;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_WORKING_THREADS))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 62);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_WORKING_THREADS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_working_threads_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" working_threads=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, working_threads, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_working_threads

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_working_threads (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        working_threads;                //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_WORKING_THREADS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_working_threads_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_WORKING_THREADS))
    icl_trace_record (NULL, amq_server_config_dump, 63);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_WORKING_THREADS))
    icl_stats_inc ("amq_server_config_working_threads", &s_amq_server_config_working_threads_stats);
#endif

//
if (self)
    working_threads = self->working_threads;
else
    working_threads = 4;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_WORKING_THREADS))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 63);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_WORKING_THREADS))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_working_threads_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" working_threads=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, working_threads);
#endif


    return (working_threads);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_tcp_nodelay

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_tcp_nodelay (
    amq_server_config_t * self,         //  Reference to object
    Bool tcp_nodelay                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_TCP_NODELAY))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_tcp_nodelay_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_nodelay=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_nodelay);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_NODELAY))
    icl_trace_record (NULL, amq_server_config_dump, 64);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_TCP_NODELAY))
    icl_stats_inc ("amq_server_config_set_tcp_nodelay", &s_amq_server_config_set_tcp_nodelay_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_nodelay);
ipr_config_putp (self->config, "/config/tuning", "tcp_nodelay", strvalue);
self->tcp_nodelay = tcp_nodelay;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_NODELAY))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 64);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_TCP_NODELAY))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_tcp_nodelay_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_nodelay=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_nodelay, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_tcp_nodelay

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_server_config_tcp_nodelay (
    amq_server_config_t * self          //  Reference to self
)
{
    Bool
        tcp_nodelay;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_TCP_NODELAY))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_tcp_nodelay_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_NODELAY))
    icl_trace_record (NULL, amq_server_config_dump, 65);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_TCP_NODELAY))
    icl_stats_inc ("amq_server_config_tcp_nodelay", &s_amq_server_config_tcp_nodelay_stats);
#endif

//
if (self)
    tcp_nodelay = self->tcp_nodelay;
else
    tcp_nodelay = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_NODELAY))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 65);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_TCP_NODELAY))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_tcp_nodelay_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_nodelay=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_nodelay);
#endif


    return (tcp_nodelay);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_tcp_rcvbuf

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_tcp_rcvbuf (
    amq_server_config_t * self,         //  Reference to object
    int tcp_rcvbuf                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_TCP_RCVBUF))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_tcp_rcvbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_rcvbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_rcvbuf);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_RCVBUF))
    icl_trace_record (NULL, amq_server_config_dump, 66);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_TCP_RCVBUF))
    icl_stats_inc ("amq_server_config_set_tcp_rcvbuf", &s_amq_server_config_set_tcp_rcvbuf_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_rcvbuf);
ipr_config_putp (self->config, "/config/tuning", "tcp_rcvbuf", strvalue);
self->tcp_rcvbuf = tcp_rcvbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_RCVBUF))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 66);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_TCP_RCVBUF))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_tcp_rcvbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_rcvbuf=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_rcvbuf, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_tcp_rcvbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_tcp_rcvbuf (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        tcp_rcvbuf;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_TCP_RCVBUF))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_tcp_rcvbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_RCVBUF))
    icl_trace_record (NULL, amq_server_config_dump, 67);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_TCP_RCVBUF))
    icl_stats_inc ("amq_server_config_tcp_rcvbuf", &s_amq_server_config_tcp_rcvbuf_stats);
#endif

//
if (self)
    tcp_rcvbuf = self->tcp_rcvbuf;
else
    tcp_rcvbuf = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_RCVBUF))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 67);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_TCP_RCVBUF))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_tcp_rcvbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_rcvbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_rcvbuf);
#endif


    return (tcp_rcvbuf);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_tcp_sndbuf

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_tcp_sndbuf (
    amq_server_config_t * self,         //  Reference to object
    int tcp_sndbuf                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_TCP_SNDBUF))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_tcp_sndbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_sndbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_sndbuf);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_SNDBUF))
    icl_trace_record (NULL, amq_server_config_dump, 68);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_TCP_SNDBUF))
    icl_stats_inc ("amq_server_config_set_tcp_sndbuf", &s_amq_server_config_set_tcp_sndbuf_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_sndbuf);
ipr_config_putp (self->config, "/config/tuning", "tcp_sndbuf", strvalue);
self->tcp_sndbuf = tcp_sndbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_SNDBUF))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 68);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_TCP_SNDBUF))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_tcp_sndbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_sndbuf=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_sndbuf, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_tcp_sndbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_tcp_sndbuf (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        tcp_sndbuf;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_TCP_SNDBUF))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_tcp_sndbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_SNDBUF))
    icl_trace_record (NULL, amq_server_config_dump, 69);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_TCP_SNDBUF))
    icl_stats_inc ("amq_server_config_tcp_sndbuf", &s_amq_server_config_tcp_sndbuf_stats);
#endif

//
if (self)
    tcp_sndbuf = self->tcp_sndbuf;
else
    tcp_sndbuf = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_SNDBUF))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 69);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_TCP_SNDBUF))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_tcp_sndbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_sndbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_sndbuf);
#endif


    return (tcp_sndbuf);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_frame_max

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_frame_max (
    amq_server_config_t * self,         //  Reference to object
    int frame_max                       //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_FRAME_MAX))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_frame_max_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" frame_max=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, frame_max);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_FRAME_MAX))
    icl_trace_record (NULL, amq_server_config_dump, 70);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_FRAME_MAX))
    icl_stats_inc ("amq_server_config_set_frame_max", &s_amq_server_config_set_frame_max_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
if (frame_max < 2048) {
    icl_console_print ("W: <command line>: illegal value %d for frame_max, using %d",
        frame_max, 2048);
    frame_max = 2048;
}
if (frame_max > 2097152) {
    icl_console_print ("W: <command line>: illegal value %d for frame_max, using %d",
        frame_max, 2097152);
    frame_max = 2097152;
}
icl_shortstr_fmt (strvalue, "%i", frame_max);
ipr_config_putp (self->config, "/config/tuning", "frame_max", strvalue);
self->frame_max = frame_max;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_FRAME_MAX))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 70);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_FRAME_MAX))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_frame_max_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" frame_max=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, frame_max, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_frame_max

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_frame_max (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        frame_max;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_FRAME_MAX))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_frame_max_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FRAME_MAX))
    icl_trace_record (NULL, amq_server_config_dump, 71);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_FRAME_MAX))
    icl_stats_inc ("amq_server_config_frame_max", &s_amq_server_config_frame_max_stats);
#endif

//
if (self)
    frame_max = self->frame_max;
else
    frame_max = 32768;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FRAME_MAX))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 71);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_FRAME_MAX))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_frame_max_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" frame_max=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, frame_max);
#endif


    return (frame_max);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_direct

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_direct (
    amq_server_config_t * self,         //  Reference to object
    int direct                          //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DIRECT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_direct_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" direct=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, direct);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DIRECT))
    icl_trace_record (NULL, amq_server_config_dump, 72);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DIRECT))
    icl_stats_inc ("amq_server_config_set_direct", &s_amq_server_config_set_direct_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", direct);
ipr_config_putp (self->config, "/config/tuning", "direct", strvalue);
self->direct = direct;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DIRECT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 72);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DIRECT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_direct_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" direct=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, direct, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_direct

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_direct (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        direct;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DIRECT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_direct_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DIRECT))
    icl_trace_record (NULL, amq_server_config_dump, 73);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DIRECT))
    icl_stats_inc ("amq_server_config_direct", &s_amq_server_config_direct_stats);
#endif

//
if (self)
    direct = self->direct;
else
    direct = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DIRECT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 73);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DIRECT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_direct_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" direct=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, direct);
#endif


    return (direct);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_private_credit

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_private_credit (
    amq_server_config_t * self,         //  Reference to object
    int private_credit                  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_PRIVATE_CREDIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_private_credit_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" private_credit=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, private_credit);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PRIVATE_CREDIT))
    icl_trace_record (NULL, amq_server_config_dump, 74);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_PRIVATE_CREDIT))
    icl_stats_inc ("amq_server_config_set_private_credit", &s_amq_server_config_set_private_credit_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", private_credit);
ipr_config_putp (self->config, "/config/tuning", "private_credit", strvalue);
self->private_credit = private_credit;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PRIVATE_CREDIT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 74);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_PRIVATE_CREDIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_private_credit_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" private_credit=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, private_credit, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_private_credit

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_private_credit (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        private_credit;                 //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_PRIVATE_CREDIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_private_credit_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PRIVATE_CREDIT))
    icl_trace_record (NULL, amq_server_config_dump, 75);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_PRIVATE_CREDIT))
    icl_stats_inc ("amq_server_config_private_credit", &s_amq_server_config_private_credit_stats);
#endif

//
if (self)
    private_credit = self->private_credit;
else
    private_credit = 1024;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PRIVATE_CREDIT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 75);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_PRIVATE_CREDIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_private_credit_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" private_credit=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, private_credit);
#endif


    return (private_credit);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_shared_credit

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_shared_credit (
    amq_server_config_t * self,         //  Reference to object
    int shared_credit                   //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_SHARED_CREDIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_shared_credit_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" shared_credit=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, shared_credit);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_SHARED_CREDIT))
    icl_trace_record (NULL, amq_server_config_dump, 76);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_SHARED_CREDIT))
    icl_stats_inc ("amq_server_config_set_shared_credit", &s_amq_server_config_set_shared_credit_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", shared_credit);
ipr_config_putp (self->config, "/config/tuning", "shared_credit", strvalue);
self->shared_credit = shared_credit;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_SHARED_CREDIT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 76);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_SHARED_CREDIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_shared_credit_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" shared_credit=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, shared_credit, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_shared_credit

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_shared_credit (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        shared_credit;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SHARED_CREDIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_shared_credit_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SHARED_CREDIT))
    icl_trace_record (NULL, amq_server_config_dump, 77);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SHARED_CREDIT))
    icl_stats_inc ("amq_server_config_shared_credit", &s_amq_server_config_shared_credit_stats);
#endif

//
if (self)
    shared_credit = self->shared_credit;
else
    shared_credit = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SHARED_CREDIT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 77);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SHARED_CREDIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_shared_credit_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" shared_credit=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, shared_credit);
#endif


    return (shared_credit);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_backup

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_backup (
    amq_server_config_t * self,         //  Reference to object
    char * backup                       //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_BACKUP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_backup_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" backup=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, backup);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_BACKUP))
    icl_trace_record (NULL, amq_server_config_dump, 78);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_BACKUP))
    icl_stats_inc ("amq_server_config_set_backup", &s_amq_server_config_set_backup_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/failover", "backup", backup);
backup = ipr_config_getp (self->config, "/config/failover", "backup", NULL);
assert (backup);
icl_shortstr_cpy (self->backup, backup);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_BACKUP))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 78);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_BACKUP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_backup_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" backup=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, backup, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_backup

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_backup (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        backup;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_BACKUP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_backup_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_BACKUP))
    icl_trace_record (NULL, amq_server_config_dump, 79);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_BACKUP))
    icl_stats_inc ("amq_server_config_backup", &s_amq_server_config_backup_stats);
#endif

//
if (self)
    backup = self->backup;
else
    backup = "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_BACKUP))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 79);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_BACKUP))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_backup_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" backup=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, backup);
#endif


    return (backup);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_primary

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_primary (
    amq_server_config_t * self,         //  Reference to object
    char * primary                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_PRIMARY))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_primary_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" primary=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, primary);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PRIMARY))
    icl_trace_record (NULL, amq_server_config_dump, 80);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_PRIMARY))
    icl_stats_inc ("amq_server_config_set_primary", &s_amq_server_config_set_primary_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/failover", "primary", primary);
primary = ipr_config_getp (self->config, "/config/failover", "primary", NULL);
assert (primary);
icl_shortstr_cpy (self->primary, primary);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PRIMARY))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 80);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_PRIMARY))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_primary_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" primary=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, primary, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_primary

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_primary (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        primary;                        //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_PRIMARY))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_primary_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PRIMARY))
    icl_trace_record (NULL, amq_server_config_dump, 81);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_PRIMARY))
    icl_stats_inc ("amq_server_config_primary", &s_amq_server_config_primary_stats);
#endif

//
if (self)
    primary = self->primary;
else
    primary = "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PRIMARY))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 81);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_PRIMARY))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_primary_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" primary=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, primary);
#endif


    return (primary);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_failover_timeout

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_failover_timeout (
    amq_server_config_t * self,         //  Reference to object
    int failover_timeout                //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_FAILOVER_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_failover_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" failover_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, failover_timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_FAILOVER_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 82);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_FAILOVER_TIMEOUT))
    icl_stats_inc ("amq_server_config_set_failover_timeout", &s_amq_server_config_set_failover_timeout_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
if (failover_timeout < 1) {
    icl_console_print ("W: <command line>: illegal value %d for failover_timeout, using %d",
        failover_timeout, 1);
    failover_timeout = 1;
}
if (failover_timeout > 60) {
    icl_console_print ("W: <command line>: illegal value %d for failover_timeout, using %d",
        failover_timeout, 60);
    failover_timeout = 60;
}
icl_shortstr_fmt (strvalue, "%i", failover_timeout);
ipr_config_putp (self->config, "/config/failover", "timeout", strvalue);
self->failover_timeout = failover_timeout;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_FAILOVER_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 82);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_FAILOVER_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_failover_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" failover_timeout=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, failover_timeout, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_failover_timeout

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_failover_timeout (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        failover_timeout;               //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_FAILOVER_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_failover_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FAILOVER_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 83);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_FAILOVER_TIMEOUT))
    icl_stats_inc ("amq_server_config_failover_timeout", &s_amq_server_config_failover_timeout_stats);
#endif

//
if (self)
    failover_timeout = self->failover_timeout;
else
    failover_timeout = 5;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FAILOVER_TIMEOUT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 83);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_FAILOVER_TIMEOUT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_failover_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" failover_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, failover_timeout);
#endif


    return (failover_timeout);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_attach

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_attach (
    amq_server_config_t * self,         //  Reference to object
    char * attach                       //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ATTACH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_attach_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH))
    icl_trace_record (NULL, amq_server_config_dump, 84);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ATTACH))
    icl_stats_inc ("amq_server_config_set_attach", &s_amq_server_config_set_attach_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/federation", "attach", attach);
attach = ipr_config_getp (self->config, "/config/federation", "attach", NULL);
assert (attach);
icl_shortstr_cpy (self->attach, attach);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 84);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ATTACH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_attach_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_attach

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_attach (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        attach;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ATTACH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_attach_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH))
    icl_trace_record (NULL, amq_server_config_dump, 85);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ATTACH))
    icl_stats_inc ("amq_server_config_attach", &s_amq_server_config_attach_stats);
#endif

//
if (self)
    attach = self->attach;
else
    attach = "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 85);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ATTACH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_attach_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach);
#endif


    return (attach);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_attach_vhost

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_attach_vhost (
    amq_server_config_t * self,         //  Reference to object
    char * attach_vhost                 //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ATTACH_VHOST))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_attach_vhost_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach_vhost=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach_vhost);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_VHOST))
    icl_trace_record (NULL, amq_server_config_dump, 86);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ATTACH_VHOST))
    icl_stats_inc ("amq_server_config_set_attach_vhost", &s_amq_server_config_set_attach_vhost_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/federation", "attach_vhost", attach_vhost);
attach_vhost = ipr_config_getp (self->config, "/config/federation", "attach_vhost", NULL);
assert (attach_vhost);
icl_shortstr_cpy (self->attach_vhost, attach_vhost);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_VHOST))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 86);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ATTACH_VHOST))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_attach_vhost_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach_vhost=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach_vhost, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_attach_vhost

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_attach_vhost (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        attach_vhost;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ATTACH_VHOST))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_attach_vhost_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_VHOST))
    icl_trace_record (NULL, amq_server_config_dump, 87);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ATTACH_VHOST))
    icl_stats_inc ("amq_server_config_attach_vhost", &s_amq_server_config_attach_vhost_stats);
#endif

//
if (self)
    attach_vhost = self->attach_vhost;
else
    attach_vhost = "/";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_VHOST))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 87);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ATTACH_VHOST))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_attach_vhost_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach_vhost=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach_vhost);
#endif


    return (attach_vhost);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_attach_login

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_attach_login (
    amq_server_config_t * self,         //  Reference to object
    char * attach_login                 //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ATTACH_LOGIN))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_attach_login_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach_login=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach_login);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_LOGIN))
    icl_trace_record (NULL, amq_server_config_dump, 88);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ATTACH_LOGIN))
    icl_stats_inc ("amq_server_config_set_attach_login", &s_amq_server_config_set_attach_login_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/federation", "attach_login", attach_login);
attach_login = ipr_config_getp (self->config, "/config/federation", "attach_login", NULL);
assert (attach_login);
icl_shortstr_cpy (self->attach_login, attach_login);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_LOGIN))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 88);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ATTACH_LOGIN))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_attach_login_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach_login=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach_login, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_attach_login

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_attach_login (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        attach_login;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ATTACH_LOGIN))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_attach_login_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_LOGIN))
    icl_trace_record (NULL, amq_server_config_dump, 89);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ATTACH_LOGIN))
    icl_stats_inc ("amq_server_config_attach_login", &s_amq_server_config_attach_login_stats);
#endif

//
if (self)
    attach_login = self->attach_login;
else
    attach_login = "peering";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_LOGIN))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 89);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ATTACH_LOGIN))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_attach_login_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach_login=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach_login);
#endif


    return (attach_login);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_attach_all

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_attach_all (
    amq_server_config_t * self,         //  Reference to object
    char * attach_all                   //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ATTACH_ALL))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_attach_all_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach_all=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach_all);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_ALL))
    icl_trace_record (NULL, amq_server_config_dump, 90);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_ATTACH_ALL))
    icl_stats_inc ("amq_server_config_set_attach_all", &s_amq_server_config_set_attach_all_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/federation", "attach_all", attach_all);
attach_all = ipr_config_getp (self->config, "/config/federation", "attach_all", NULL);
assert (attach_all);
icl_shortstr_cpy (self->attach_all, attach_all);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_ALL))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 90);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_ATTACH_ALL))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_attach_all_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach_all=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach_all, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_attach_all

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_server_config_attach_all (
    amq_server_config_t * self          //  Reference to self
)
{
    char *
        attach_all;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ATTACH_ALL))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_attach_all_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_ALL))
    icl_trace_record (NULL, amq_server_config_dump, 91);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ATTACH_ALL))
    icl_stats_inc ("amq_server_config_attach_all", &s_amq_server_config_attach_all_stats);
#endif

//
if (self)
    attach_all = self->attach_all;
else
    attach_all = "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_ALL))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 91);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ATTACH_ALL))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_attach_all_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" attach_all=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, attach_all);
#endif


    return (attach_all);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_batching

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_batching (
    amq_server_config_t * self,         //  Reference to object
    int batching                        //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_BATCHING))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_batching_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" batching=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, batching);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_BATCHING))
    icl_trace_record (NULL, amq_server_config_dump, 92);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_BATCHING))
    icl_stats_inc ("amq_server_config_set_batching", &s_amq_server_config_set_batching_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
if (batching > 2097152) {
    icl_console_print ("W: <command line>: illegal value %d for batching, using %d",
        batching, 2097152);
    batching = 2097152;
}
icl_shortstr_fmt (strvalue, "%i", batching);
ipr_config_putp (self->config, "/config/direct", "batching", strvalue);
self->batching = batching;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_BATCHING))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 92);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_BATCHING))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_batching_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" batching=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, batching, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_batching

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_batching (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        batching;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_BATCHING))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_batching_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_BATCHING))
    icl_trace_record (NULL, amq_server_config_dump, 93);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_BATCHING))
    icl_stats_inc ("amq_server_config_batching", &s_amq_server_config_batching_stats);
#endif

//
if (self)
    batching = self->batching;
else
    batching = 32768;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_BATCHING))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 93);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_BATCHING))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_batching_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" batching=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, batching);
#endif


    return (batching);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_direct_heartbeat

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_direct_heartbeat (
    amq_server_config_t * self,         //  Reference to object
    int direct_heartbeat                //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DIRECT_HEARTBEAT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_direct_heartbeat_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" direct_heartbeat=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, direct_heartbeat);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DIRECT_HEARTBEAT))
    icl_trace_record (NULL, amq_server_config_dump, 94);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_DIRECT_HEARTBEAT))
    icl_stats_inc ("amq_server_config_set_direct_heartbeat", &s_amq_server_config_set_direct_heartbeat_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", direct_heartbeat);
ipr_config_putp (self->config, "/config/direct", "heartbeat", strvalue);
self->direct_heartbeat = direct_heartbeat;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DIRECT_HEARTBEAT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 94);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_DIRECT_HEARTBEAT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_direct_heartbeat_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" direct_heartbeat=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, direct_heartbeat, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_direct_heartbeat

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_direct_heartbeat (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        direct_heartbeat;               //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DIRECT_HEARTBEAT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_direct_heartbeat_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DIRECT_HEARTBEAT))
    icl_trace_record (NULL, amq_server_config_dump, 95);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DIRECT_HEARTBEAT))
    icl_stats_inc ("amq_server_config_direct_heartbeat", &s_amq_server_config_direct_heartbeat_stats);
#endif

//
if (self)
    direct_heartbeat = self->direct_heartbeat;
else
    direct_heartbeat = 2;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DIRECT_HEARTBEAT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 95);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DIRECT_HEARTBEAT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_direct_heartbeat_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" direct_heartbeat=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, direct_heartbeat);
#endif


    return (direct_heartbeat);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_no_ack

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_no_ack (
    amq_server_config_t * self,         //  Reference to object
    Bool no_ack                         //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_NO_ACK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_no_ack_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" no_ack=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, no_ack);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_NO_ACK))
    icl_trace_record (NULL, amq_server_config_dump, 96);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_NO_ACK))
    icl_stats_inc ("amq_server_config_set_no_ack", &s_amq_server_config_set_no_ack_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", no_ack);
ipr_config_putp (self->config, "/config/compatibility", "no_ack", strvalue);
self->no_ack = no_ack;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_NO_ACK))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 96);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_NO_ACK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_no_ack_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" no_ack=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, no_ack, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_no_ack

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_server_config_no_ack (
    amq_server_config_t * self          //  Reference to self
)
{
    Bool
        no_ack;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_NO_ACK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_no_ack_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NO_ACK))
    icl_trace_record (NULL, amq_server_config_dump, 97);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_NO_ACK))
    icl_stats_inc ("amq_server_config_no_ack", &s_amq_server_config_no_ack_stats);
#endif

//
if (self)
    no_ack = self->no_ack;
else
    no_ack = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NO_ACK))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 97);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_NO_ACK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_no_ack_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" no_ack=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, no_ack);
#endif


    return (no_ack);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_auto_crash

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_auto_crash (
    amq_server_config_t * self,         //  Reference to object
    int auto_crash                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_AUTO_CRASH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_auto_crash_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" auto_crash=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, auto_crash);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_AUTO_CRASH))
    icl_trace_record (NULL, amq_server_config_dump, 98);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_AUTO_CRASH))
    icl_stats_inc ("amq_server_config_set_auto_crash", &s_amq_server_config_set_auto_crash_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", auto_crash);
ipr_config_putp (self->config, "/config/internal", "auto_crash", strvalue);
self->auto_crash = auto_crash;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_AUTO_CRASH))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 98);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_AUTO_CRASH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_auto_crash_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" auto_crash=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, auto_crash, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_auto_crash

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_auto_crash (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        auto_crash;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_AUTO_CRASH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_auto_crash_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_AUTO_CRASH))
    icl_trace_record (NULL, amq_server_config_dump, 99);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_AUTO_CRASH))
    icl_stats_inc ("amq_server_config_auto_crash", &s_amq_server_config_auto_crash_stats);
#endif

//
if (self)
    auto_crash = self->auto_crash;
else
    auto_crash = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_AUTO_CRASH))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 99);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_AUTO_CRASH))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_auto_crash_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" auto_crash=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, auto_crash);
#endif


    return (auto_crash);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_auto_block

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_auto_block (
    amq_server_config_t * self,         //  Reference to object
    int auto_block                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_AUTO_BLOCK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_auto_block_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" auto_block=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, auto_block);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_AUTO_BLOCK))
    icl_trace_record (NULL, amq_server_config_dump, 100);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_AUTO_BLOCK))
    icl_stats_inc ("amq_server_config_set_auto_block", &s_amq_server_config_set_auto_block_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", auto_block);
ipr_config_putp (self->config, "/config/internal", "auto_block", strvalue);
self->auto_block = auto_block;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_AUTO_BLOCK))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 100);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_AUTO_BLOCK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_auto_block_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" auto_block=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, auto_block, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_auto_block

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_auto_block (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        auto_block;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_AUTO_BLOCK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_auto_block_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_AUTO_BLOCK))
    icl_trace_record (NULL, amq_server_config_dump, 101);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_AUTO_BLOCK))
    icl_stats_inc ("amq_server_config_auto_block", &s_amq_server_config_auto_block_stats);
#endif

//
if (self)
    auto_block = self->auto_block;
else
    auto_block = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_AUTO_BLOCK))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 101);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_AUTO_BLOCK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_auto_block_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" auto_block=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, auto_block);
#endif


    return (auto_block);
}
/*  -------------------------------------------------------------------------
    amq_server_config_set_kernel_limit

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_set_kernel_limit (
    amq_server_config_t * self,         //  Reference to object
    int kernel_limit                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_KERNEL_LIMIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_kernel_limit_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" kernel_limit=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, kernel_limit);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_KERNEL_LIMIT))
    icl_trace_record (NULL, amq_server_config_dump, 102);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SET_KERNEL_LIMIT))
    icl_stats_inc ("amq_server_config_set_kernel_limit", &s_amq_server_config_set_kernel_limit_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", kernel_limit);
ipr_config_putp (self->config, "/config/internal", "kernel_limit", strvalue);
self->kernel_limit = kernel_limit;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_KERNEL_LIMIT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 102);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SET_KERNEL_LIMIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_set_kernel_limit_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" kernel_limit=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, kernel_limit, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_kernel_limit

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_server_config_kernel_limit (
    amq_server_config_t * self          //  Reference to self
)
{
    int
        kernel_limit;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_KERNEL_LIMIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_kernel_limit_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_KERNEL_LIMIT))
    icl_trace_record (NULL, amq_server_config_dump, 103);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_KERNEL_LIMIT))
    icl_stats_inc ("amq_server_config_kernel_limit", &s_amq_server_config_kernel_limit_stats);
#endif

//
if (self)
    kernel_limit = self->kernel_limit;
else
    kernel_limit = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_KERNEL_LIMIT))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 103);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_KERNEL_LIMIT))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_kernel_limit_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" kernel_limit=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, kernel_limit);
#endif


    return (kernel_limit);
}
/*  -------------------------------------------------------------------------
    amq_server_config_dump_log

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    Dump current option values to an smt_log file.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_dump_log (
    amq_server_config_t * self,         //  Reference to object
    smt_log_t * logfile                 //  Log file to dump to
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DUMP_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_dump_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" logfile=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, logfile);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DUMP_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 104);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DUMP_LOG))
    icl_stats_inc ("amq_server_config_dump_log", &s_amq_server_config_dump_log_stats);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

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
smt_log_print (logfile, "archive_path=%s", self->archive_path);
smt_log_print (logfile, "archive_cmd=%s", self->archive_cmd);
smt_log_print (logfile, "alert_log=%s", self->alert_log);
smt_log_print (logfile, "daily_log=%s", self->daily_log);
smt_log_print (logfile, "debug_log=%s", self->debug_log);
smt_log_print (logfile, "debug_route=%i", self->debug_route);
smt_log_print (logfile, "debug_queue=%i", self->debug_queue);
smt_log_print (logfile, "debug_peering=%i", self->debug_peering);
smt_log_print (logfile, "debug_console=%i", self->debug_console);
smt_log_print (logfile, "trace=%i", self->trace);
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DUMP_LOG))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 104);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DUMP_LOG))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_dump_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" logfile=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, logfile, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_config_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SELFTEST))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SELFTEST))
    icl_trace_record (NULL, amq_server_config_dump, 105);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SELFTEST))
    icl_stats_inc ("amq_server_config_selftest", &s_amq_server_config_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SELFTEST))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 105);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SELFTEST))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_selftest_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_config_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_config_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_TERMINATE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TERMINATE))
    icl_trace_record (NULL, amq_server_config_dump, 106);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_TERMINATE))
    icl_stats_inc ("amq_server_config_terminate", &s_amq_server_config_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TERMINATE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 106);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_TERMINATE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_config_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_config_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_server_config_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SHOW))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_show_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SHOW))
    icl_trace_record (NULL, amq_server_config_dump, 107);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_SHOW))
    icl_stats_inc ("amq_server_config_show", &s_amq_server_config_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_server_config file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SHOW))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 107);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_SHOW))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_show_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_config_destroy

    Type: Component method
    Destroys a amq_server_config_t object. Takes the address of a
    amq_server_config_t reference (a pointer to a pointer) and nullifies the
    reference after use.  Does nothing if the reference is already
    null.
    Performs an agressive destroy of an object.  This involves:
    1. Removing the object from any containers it is in.
    2. Making the object an zombie
    3. Decrementing the object's link count
    4. If the link count is zero then freeing the object.
    -------------------------------------------------------------------------
 */

void
    amq_server_config_destroy_ (
    amq_server_config_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_server_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DESTROY_PUBLIC))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_server_config_dump, 108);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_DESTROY_PUBLIC))
    icl_stats_inc ("amq_server_config_destroy", &s_amq_server_config_destroy_stats);
#endif

if (self) {
    amq_server_config_annihilate (self_p);
    amq_server_config_free ((amq_server_config_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 108);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_DESTROY_PUBLIC))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_config_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_server_config_t *
    amq_server_config_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_server_config_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ALLOC))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ALLOC))
    icl_trace_record (NULL, amq_server_config_dump, 109);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ALLOC))
    icl_stats_inc ("amq_server_config_alloc", &s_amq_server_config_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_server_config_cache_initialise ();

self = (amq_server_config_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_server_config_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ALLOC))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 109);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ALLOC))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_config_free

    Type: Component method
    Freess a amq_server_config_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_server_config_free (
    amq_server_config_t * self          //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_FREE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FREE))
    icl_trace_record (NULL, amq_server_config_dump, 110);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_FREE))
    icl_stats_inc ("amq_server_config_free", &s_amq_server_config_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (amq_server_config_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_server_config_t));
        self->object_tag = AMQ_SERVER_CONFIG_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FREE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 110);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_FREE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_config_read_lock

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_read_lock (
    amq_server_config_t * self          //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_READ_LOCK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_read_lock_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_READ_LOCK))
    icl_trace_record (NULL, amq_server_config_dump, 111);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_READ_LOCK))
    icl_stats_inc ("amq_server_config_read_lock", &s_amq_server_config_read_lock_stats);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_READ_LOCK))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 111);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_READ_LOCK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_read_lock_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_write_lock

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_write_lock (
    amq_server_config_t * self          //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_WRITE_LOCK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_write_lock_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_WRITE_LOCK))
    icl_trace_record (NULL, amq_server_config_dump, 112);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_WRITE_LOCK))
    icl_stats_inc ("amq_server_config_write_lock", &s_amq_server_config_write_lock_stats);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_WRITE_LOCK))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 112);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_WRITE_LOCK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_write_lock_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_unlock

    Type: Component method
    Accepts a amq_server_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_server_config_unlock (
    amq_server_config_t * self          //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_UNLOCK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_unlock_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_UNLOCK))
    icl_trace_record (NULL, amq_server_config_dump, 113);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_UNLOCK))
    icl_stats_inc ("amq_server_config_unlock", &s_amq_server_config_unlock_stats);
#endif

AMQ_SERVER_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_UNLOCK))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 113);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_UNLOCK))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_unlock_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_config_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_server_config_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CACHE_INITIALISE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_server_config_dump, 114);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CACHE_INITIALISE))
    icl_stats_inc ("amq_server_config_cache_initialise", &s_amq_server_config_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_server_config_t));
icl_system_register (amq_server_config_cache_purge, amq_server_config_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 114);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CACHE_INITIALISE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_cache_initialise_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_config_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_config_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CACHE_PURGE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_PURGE))
    icl_trace_record (NULL, amq_server_config_dump, 115);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CACHE_PURGE))
    icl_stats_inc ("amq_server_config_cache_purge", &s_amq_server_config_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_PURGE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 115);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CACHE_PURGE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_cache_purge_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_config_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_config_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CACHE_TERMINATE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_server_config_dump, 116);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_CACHE_TERMINATE))
    icl_stats_inc ("amq_server_config_cache_terminate", &s_amq_server_config_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 116);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_CACHE_TERMINATE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_cache_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_config_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_server_config_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ANIMATE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_animate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ANIMATE))
    icl_trace_record (NULL, amq_server_config_dump, 117);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_ANIMATE))
    icl_stats_inc ("amq_server_config_animate", &s_amq_server_config_animate_stats);
#endif

amq_server_config_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ANIMATE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 117);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_ANIMATE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_animate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_config_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_config_new_in_scope_ (
    amq_server_config_t * * self_p,     //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)  ||  defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_NEW_IN_SCOPE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_server_config_dump, 118);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG)  ||  defined (BASE_STATS_AMQ_SERVER_CONFIG_NEW_IN_SCOPE))
    icl_stats_inc ("amq_server_config_new_in_scope", &s_amq_server_config_new_in_scope_stats);
#endif

*self_p = amq_server_config_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_server_config_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_server_config_dump, 0x10000 + 118);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG)   || defined (BASE_ANIMATE_AMQ_SERVER_CONFIG_NEW_IN_SCOPE))
    if (amq_server_config_animating)
        icl_console_print ("<amq_server_config_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NEW)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DESTROY)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOAD_XMLFILE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOAD_BUCKET)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_COMMIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ROLLBACK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CMDLINE_HELP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CMDLINE_PARSE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_OPTIONS_HELP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PORT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PORT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_LISTEN)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LISTEN)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_QUEUE_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_QUEUE_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_VHOST)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_VHOST)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_USER)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_USER)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_GROUP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_GROUP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_MONITOR)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_MONITOR)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DUMP_STATE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DUMP_STATE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_RECORD_STATS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_RECORD_STATS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_LOG_PATH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOG_PATH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_KEEP_LOGS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_KEEP_LOGS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ARCHIVE_PATH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ARCHIVE_PATH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ARCHIVE_CMD)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ARCHIVE_CMD)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ALERT_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ALERT_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DAILY_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DAILY_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_ROUTE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_ROUTE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_QUEUE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_QUEUE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_PEERING)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_PEERING)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_CONSOLE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_CONSOLE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_HEARTBEAT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_HEARTBEAT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_SETUP_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SETUP_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_CLOSE_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CLOSE_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ACCEPT_RETRY_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ACCEPT_RETRY_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_POLLING_THREADS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_POLLING_THREADS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_WORKING_THREADS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_WORKING_THREADS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_NODELAY)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_NODELAY)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_RCVBUF)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_RCVBUF)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_SNDBUF)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_SNDBUF)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_FRAME_MAX)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FRAME_MAX)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DIRECT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DIRECT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PRIVATE_CREDIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PRIVATE_CREDIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_SHARED_CREDIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SHARED_CREDIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_BACKUP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_BACKUP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PRIMARY)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PRIMARY)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_FAILOVER_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FAILOVER_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_VHOST)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_VHOST)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_LOGIN)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_LOGIN)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_ALL)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_ALL)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_BATCHING)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_BATCHING)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DIRECT_HEARTBEAT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DIRECT_HEARTBEAT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_NO_ACK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NO_ACK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_AUTO_CRASH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_AUTO_CRASH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_AUTO_BLOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_AUTO_BLOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_KERNEL_LIMIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_KERNEL_LIMIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DUMP_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SELFTEST)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SHOW)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ALLOC)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FREE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_READ_LOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_UNLOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ANIMATE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NEW_IN_SCOPE) )
void
amq_server_config_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "load xmlfile"; break;
        case 4: method_name = "load bucket"; break;
        case 5: method_name = "commit"; break;
        case 6: method_name = "rollback"; break;
        case 7: method_name = "cmdline help"; break;
        case 8: method_name = "cmdline parse"; break;
        case 9: method_name = "options help"; break;
        case 10: method_name = "set port"; break;
        case 11: method_name = "port"; break;
        case 12: method_name = "set listen"; break;
        case 13: method_name = "listen"; break;
        case 14: method_name = "set queue_timeout"; break;
        case 15: method_name = "queue_timeout"; break;
        case 16: method_name = "set vhost"; break;
        case 17: method_name = "vhost"; break;
        case 18: method_name = "set user"; break;
        case 19: method_name = "user"; break;
        case 20: method_name = "set group"; break;
        case 21: method_name = "group"; break;
        case 22: method_name = "set monitor"; break;
        case 23: method_name = "monitor"; break;
        case 24: method_name = "set dump_state"; break;
        case 25: method_name = "dump_state"; break;
        case 26: method_name = "set record_stats"; break;
        case 27: method_name = "record_stats"; break;
        case 28: method_name = "set log_path"; break;
        case 29: method_name = "log_path"; break;
        case 30: method_name = "set keep_logs"; break;
        case 31: method_name = "keep_logs"; break;
        case 32: method_name = "set archive_path"; break;
        case 33: method_name = "archive_path"; break;
        case 34: method_name = "set archive_cmd"; break;
        case 35: method_name = "archive_cmd"; break;
        case 36: method_name = "set alert_log"; break;
        case 37: method_name = "alert_log"; break;
        case 38: method_name = "set daily_log"; break;
        case 39: method_name = "daily_log"; break;
        case 40: method_name = "set debug_log"; break;
        case 41: method_name = "debug_log"; break;
        case 42: method_name = "set debug_route"; break;
        case 43: method_name = "debug_route"; break;
        case 44: method_name = "set debug_queue"; break;
        case 45: method_name = "debug_queue"; break;
        case 46: method_name = "set debug_peering"; break;
        case 47: method_name = "debug_peering"; break;
        case 48: method_name = "set debug_console"; break;
        case 49: method_name = "debug_console"; break;
        case 50: method_name = "set trace"; break;
        case 51: method_name = "trace"; break;
        case 52: method_name = "set heartbeat"; break;
        case 53: method_name = "heartbeat"; break;
        case 54: method_name = "set setup_timeout"; break;
        case 55: method_name = "setup_timeout"; break;
        case 56: method_name = "set close_timeout"; break;
        case 57: method_name = "close_timeout"; break;
        case 58: method_name = "set accept_retry_timeout"; break;
        case 59: method_name = "accept_retry_timeout"; break;
        case 60: method_name = "set polling_threads"; break;
        case 61: method_name = "polling_threads"; break;
        case 62: method_name = "set working_threads"; break;
        case 63: method_name = "working_threads"; break;
        case 64: method_name = "set tcp_nodelay"; break;
        case 65: method_name = "tcp_nodelay"; break;
        case 66: method_name = "set tcp_rcvbuf"; break;
        case 67: method_name = "tcp_rcvbuf"; break;
        case 68: method_name = "set tcp_sndbuf"; break;
        case 69: method_name = "tcp_sndbuf"; break;
        case 70: method_name = "set frame_max"; break;
        case 71: method_name = "frame_max"; break;
        case 72: method_name = "set direct"; break;
        case 73: method_name = "direct"; break;
        case 74: method_name = "set private_credit"; break;
        case 75: method_name = "private_credit"; break;
        case 76: method_name = "set shared_credit"; break;
        case 77: method_name = "shared_credit"; break;
        case 78: method_name = "set backup"; break;
        case 79: method_name = "backup"; break;
        case 80: method_name = "set primary"; break;
        case 81: method_name = "primary"; break;
        case 82: method_name = "set failover_timeout"; break;
        case 83: method_name = "failover_timeout"; break;
        case 84: method_name = "set attach"; break;
        case 85: method_name = "attach"; break;
        case 86: method_name = "set attach_vhost"; break;
        case 87: method_name = "attach_vhost"; break;
        case 88: method_name = "set attach_login"; break;
        case 89: method_name = "attach_login"; break;
        case 90: method_name = "set attach_all"; break;
        case 91: method_name = "attach_all"; break;
        case 92: method_name = "set batching"; break;
        case 93: method_name = "batching"; break;
        case 94: method_name = "set direct_heartbeat"; break;
        case 95: method_name = "direct_heartbeat"; break;
        case 96: method_name = "set no_ack"; break;
        case 97: method_name = "no_ack"; break;
        case 98: method_name = "set auto_crash"; break;
        case 99: method_name = "auto_crash"; break;
        case 100: method_name = "set auto_block"; break;
        case 101: method_name = "auto_block"; break;
        case 102: method_name = "set kernel_limit"; break;
        case 103: method_name = "kernel_limit"; break;
        case 104: method_name = "dump log"; break;
        case 105: method_name = "selftest"; break;
        case 106: method_name = "terminate"; break;
        case 107: method_name = "show"; break;
        case 108: method_name = "destroy public"; break;
        case 109: method_name = "alloc"; break;
        case 110: method_name = "free"; break;
        case 111: method_name = "read lock"; break;
        case 112: method_name = "write lock"; break;
        case 113: method_name = "unlock"; break;
        case 114: method_name = "cache initialise"; break;
        case 115: method_name = "cache purge"; break;
        case 116: method_name = "cache terminate"; break;
        case 117: method_name = "animate"; break;
        case 118: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_server_config %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_server_config_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_server_config_component  = "amq_server_config ";
char *amq_server_config_version    = "1.0 ";
char *amq_server_config_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_server_config_filename   = "amq_server_config.icl ";
char *amq_server_config_builddate  = "2010/10/06 ";
char *amq_server_config_version_end  = "VeRsIoNeNd:ipc";

