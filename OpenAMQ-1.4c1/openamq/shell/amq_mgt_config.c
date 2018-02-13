/*---------------------------------------------------------------------------
    amq_mgt_config.c - amq_mgt_config component

Implements the management console config object, used by applications
to manage OpenAMQ servers. Use in conjunction with the amq_mgt_console
class.
    Generated from amq_mgt_config.icl by icl_gen using GSL/4.
    
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
#include "amq_mgt_config.h"             //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_mgt_config_t

//  Shorthands for class methods

#define self_new            amq_mgt_config_new
#define self_annihilate     amq_mgt_config_annihilate
#define self_load           amq_mgt_config_load
#define self_print_children  amq_mgt_config_print_children
#define self_print_properties  amq_mgt_config_print_properties
#define self_print_summary  amq_mgt_config_print_summary
#define self_cmdline        amq_mgt_config_cmdline
#define self_selftest       amq_mgt_config_selftest
#define self_terminate      amq_mgt_config_terminate
#define self_show           amq_mgt_config_show
#define self_destroy        amq_mgt_config_destroy
#define self_alloc          amq_mgt_config_alloc
#define self_free           amq_mgt_config_free
#define self_cache_initialise  amq_mgt_config_cache_initialise
#define self_cache_purge    amq_mgt_config_cache_purge
#define self_cache_terminate  amq_mgt_config_cache_terminate
#define self_show_animation  amq_mgt_config_show_animation
#define self_new_in_scope   amq_mgt_config_new_in_scope

static void
    amq_mgt_config_annihilate (
amq_mgt_config_t * ( * self_p )         //  Reference to object reference
);

#define amq_mgt_config_alloc()          amq_mgt_config_alloc_ (__FILE__, __LINE__)
static amq_mgt_config_t *
    amq_mgt_config_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_mgt_config_free (
amq_mgt_config_t * self                 //  Object reference
);

static void
    amq_mgt_config_cache_initialise (
void);

static void
    amq_mgt_config_cache_purge (
void);

static void
    amq_mgt_config_cache_terminate (
void);

Bool
    amq_mgt_config_animating = TRUE;    //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static void
    s_destroy_children (amq_mgt_config_t *self);
static ipr_xml_t *
    s_request_response (amq_mgt_config_t *self, char *request, qbyte object_id,
        char *method, asl_field_list_t *fields);
static void
    s_print_property (char *label, char *value, char *name, char *command);
static void
    s_set_property (amq_mgt_config_t *self, char *command);
static int
    s_change_level (amq_mgt_config_t *self, char *command, char *path,
        int depth, ipr_token_list_t *tokens, FILE *xml_data);
static void
    s_list_children (amq_mgt_config_t *self, char *command, FILE *xml_data);
static void
    s_top_children (amq_mgt_config_t *self, char *command, FILE *xml_data);
static void
    s_execute_commit (amq_mgt_config_t *self, char *command);
static void
    s_execute_rollback (amq_mgt_config_t *self, char *command);
static void
    s_show_help (void);
/*  -------------------------------------------------------------------------
    amq_mgt_config_new

    Type: Component method
    Creates and initialises a new amq_mgt_config_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_mgt_config_t *
    amq_mgt_config_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_session_t * session,     //  AMQP session
    int id                              //  Object ID
)
{
    amq_mgt_config_t *
        self = NULL;                    //  Object reference

    self = amq_mgt_config_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_MGT_CONFIG_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_mgt_config_show_);
#endif

self->session = session;
self->id = id;
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_mgt_config_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_config_annihilate (
    amq_mgt_config_t * ( * self_p )     //  Reference to object reference
)
{

    amq_mgt_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

AMQ_MGT_CONFIG_ASSERT_SANE (self);

s_destroy_children (self);

}
/*  -------------------------------------------------------------------------
    amq_mgt_config_load

    Type: Component method
    Accepts a amq_mgt_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads or refreshes the object from the server console. Returns 0
    if the object was refreshed, -1 if there was an error talking to
    the server.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_config_load (
    amq_mgt_config_t * self             //  Reference to object
)
{
ipr_xml_t
    *xml_root,                      //  Returned response tree
    *xml_cml,                       //  CML item
    *xml_command,                   //  CML command
    *xml_field;                     //  Field item in reply
char
    *field_name,                    //  Name of returned field
    *field_value;                   //  Value of returned field
    int
        rc = 0;                         //  Return code

AMQ_MGT_CONFIG_ASSERT_SANE (self);

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
            if (streq (field_name, "syslog")) {
                self->syslog = (qbyte) atoi (field_value);
            }
            else
            if (streq (field_name, "coremark_cycles")) {
                self->coremark_cycles = (qbyte) atoi (field_value);
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_config_print_children

    Type: Component method
    Accepts a amq_mgt_config_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the config's contents to the console.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_config_print_children (
    amq_mgt_config_t * self,            //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
char
    command [] = "";
    int
        rc = 0;                         //  Return code

AMQ_MGT_CONFIG_ASSERT_SANE (self);

//
if (self_load (self))
    return (0);
s_list_children (self, command, xml_data);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_config_print_properties

    Type: Component method
    Accepts a amq_mgt_config_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the config's values to the console in a two-column list.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_config_print_properties (
    amq_mgt_config_t * self,            //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
icl_shortstr_t
    field_value;
    int
        rc = 0;                         //  Return code

AMQ_MGT_CONFIG_ASSERT_SANE (self);

//
if (self_load (self))
    return (0);

icl_console_out (" config = \"%s\" ", self->name);
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
sprintf (field_value, "%d", self->syslog);
s_print_property ("Use syslog logging protocol", field_value, "syslog", NULL);
sprintf (field_value, "%d", self->coremark_cycles);
s_print_property ("Duration of CoreMark test", field_value, "coremark_cycles", NULL);
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
    fprintf (xml_data, "<config id = \"%d\""
        " name = \"%s\""
        " port = \"%s\""
        " listen = \"%s\""
        " queue_timeout = \"%d\""
        " vhost = \"%s\""
        " user = \"%s\""
        " group = \"%s\""
        " monitor = \"%d\""
        " dump_state = \"%d\""
        " record_stats = \"%d\""
        " log_path = \"%s\""
        " keep_logs = \"%d\""
        " archive_cmd = \"%s\""
        " alert_log = \"%s\""
        " daily_log = \"%s\""
        " debug_log = \"%s\""
        " debug_route = \"%d\""
        " debug_queue = \"%d\""
        " debug_peering = \"%d\""
        " debug_console = \"%d\""
        " trace = \"%d\""
        " syslog = \"%d\""
        " coremark_cycles = \"%d\""
        " heartbeat = \"%d\""
        " setup_timeout = \"%d\""
        " close_timeout = \"%d\""
        " accept_retry_timeout = \"%d\""
        " polling_threads = \"%d\""
        " working_threads = \"%d\""
        " tcp_nodelay = \"%d\""
        " tcp_rcvbuf = \"%d\""
        " tcp_sndbuf = \"%d\""
        " frame_max = \"%d\""
        " direct = \"%d\""
        " private_credit = \"%d\""
        " shared_credit = \"%d\""
        " backup = \"%s\""
        " primary = \"%s\""
        " failover_timeout = \"%d\""
        " attach = \"%s\""
        " attach_vhost = \"%s\""
        " attach_login = \"%s\""
        " attach_all = \"%s\""
        " batching = \"%d\""
        " direct_heartbeat = \"%d\""
        " no_ack = \"%d\""
        " auto_crash = \"%d\""
        " auto_block = \"%d\""
        " kernel_limit = \"%d\""
        "/>\n", self->id
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
        , self->archive_cmd
        , self->alert_log
        , self->daily_log
        , self->debug_log
        , self->debug_route
        , self->debug_queue
        , self->debug_peering
        , self->debug_console
        , self->trace
        , self->syslog
        , self->coremark_cycles
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_config_print_summary

    Type: Component method
    Accepts a amq_mgt_config_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the config to the console in a single row.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_config_print_summary (
    amq_mgt_config_t * self,            //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
    int
        rc = 0;                         //  Return code

AMQ_MGT_CONFIG_ASSERT_SANE (self);

//
icl_console_out (" %d) config = \"%s\"    ", self->id, self->name);
//  Record data in XML form if wanted
if (xml_data) {
    fprintf (xml_data, "<config id = \"%d\""
        " name = \"%s\""
        " port = \"%s\""
        " listen = \"%s\""
        " queue_timeout = \"%d\""
        " vhost = \"%s\""
        " user = \"%s\""
        " group = \"%s\""
        " monitor = \"%d\""
        " dump_state = \"%d\""
        " record_stats = \"%d\""
        " log_path = \"%s\""
        " keep_logs = \"%d\""
        " archive_cmd = \"%s\""
        " alert_log = \"%s\""
        " daily_log = \"%s\""
        " debug_log = \"%s\""
        " debug_route = \"%d\""
        " debug_queue = \"%d\""
        " debug_peering = \"%d\""
        " debug_console = \"%d\""
        " trace = \"%d\""
        " syslog = \"%d\""
        " coremark_cycles = \"%d\""
        " heartbeat = \"%d\""
        " setup_timeout = \"%d\""
        " close_timeout = \"%d\""
        " accept_retry_timeout = \"%d\""
        " polling_threads = \"%d\""
        " working_threads = \"%d\""
        " tcp_nodelay = \"%d\""
        " tcp_rcvbuf = \"%d\""
        " tcp_sndbuf = \"%d\""
        " frame_max = \"%d\""
        " direct = \"%d\""
        " private_credit = \"%d\""
        " shared_credit = \"%d\""
        " backup = \"%s\""
        " primary = \"%s\""
        " failover_timeout = \"%d\""
        " attach = \"%s\""
        " attach_vhost = \"%s\""
        " attach_login = \"%s\""
        " attach_all = \"%s\""
        " batching = \"%d\""
        " direct_heartbeat = \"%d\""
        " no_ack = \"%d\""
        " auto_crash = \"%d\""
        " auto_block = \"%d\""
        " kernel_limit = \"%d\""
        "/>\n", self->id
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
        , self->archive_cmd
        , self->alert_log
        , self->daily_log
        , self->debug_log
        , self->debug_route
        , self->debug_queue
        , self->debug_peering
        , self->debug_console
        , self->trace
        , self->syslog
        , self->coremark_cycles
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_config_cmdline

    Type: Component method
    Accepts a amq_mgt_config_t reference and returns zero in case of success,
    1 in case of errors.
    Implements a command-line interface for the config object.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_config_cmdline (
    amq_mgt_config_t * self,            //  Reference to object
    char * path,                        //  Current path
    int depth,                          //  Current depth
    ipr_token_list_t * tokens,          //  Automation, if any
    FILE * xml_data                     //  XML data capture
)
{
icl_shortstr_t
    command;
    int
        rc = 0;                         //  Return code

AMQ_MGT_CONFIG_ASSERT_SANE (self);

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


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_config_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_config_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_mgt_config_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_config_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_mgt_config_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_config_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_mgt_config_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_mgt_config file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_mgt_config_destroy

    Type: Component method
    Destroys a amq_mgt_config_t object. Takes the address of a
    amq_mgt_config_t reference (a pointer to a pointer) and nullifies the
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
    amq_mgt_config_destroy_ (
    amq_mgt_config_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_mgt_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_mgt_config_annihilate (self_p);
    amq_mgt_config_free ((amq_mgt_config_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_mgt_config_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_mgt_config_t *
    amq_mgt_config_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_mgt_config_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_mgt_config_cache_initialise ();

self = (amq_mgt_config_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_mgt_config_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_mgt_config_free

    Type: Component method
    Freess a amq_mgt_config_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_config_free (
    amq_mgt_config_t * self             //  Object reference
)
{


if (self) {

        memset (&self->object_tag, 0, sizeof (amq_mgt_config_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_mgt_config_t));
        self->object_tag = AMQ_MGT_CONFIG_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_mgt_config_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_config_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_mgt_config_t));
icl_system_register (amq_mgt_config_cache_purge, amq_mgt_config_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_mgt_config_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_config_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_mgt_config_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_config_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_mgt_config_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_mgt_config_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_mgt_config_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_mgt_config_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_config_new_in_scope_ (
    amq_mgt_config_t * * self_p,        //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_session_t * session,     //  AMQP session
    int id                              //  Object ID
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_mgt_config_new_ (file,line,session,id);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_mgt_config_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Resets / destroys child objects
static void
s_destroy_children (amq_mgt_config_t *self)
{
}

//  Sends a request, returns a response content
static ipr_xml_t *
s_request_response (
    amq_mgt_config_t *self,
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
s_set_property (amq_mgt_config_t *self, char *command)
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
    &&  strneq (name, "archive_cmd")
    &&  strneq (name, "alert_log")
    &&  strneq (name, "daily_log")
    &&  strneq (name, "debug_log")
    &&  strneq (name, "debug_route")
    &&  strneq (name, "debug_queue")
    &&  strneq (name, "debug_peering")
    &&  strneq (name, "debug_console")
    &&  strneq (name, "trace")
    &&  strneq (name, "syslog")
    &&  strneq (name, "coremark_cycles")
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
    amq_mgt_config_t *self,
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
s_list_children (amq_mgt_config_t *self, char *command, FILE *xml_data)
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
s_top_children (amq_mgt_config_t *self, char *command, FILE *xml_data)
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
s_execute_commit (amq_mgt_config_t *self, char *command)
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
s_execute_rollback (amq_mgt_config_t *self, char *command)
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

//  Embed the version information in the resulting binary

char *EMBED__amq_mgt_config_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_mgt_config_component     = "amq_mgt_config ";
char *EMBED__amq_mgt_config_version       = "1.0 ";
char *EMBED__amq_mgt_config_copyright     = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_mgt_config_filename      = "amq_mgt_config.icl ";
char *EMBED__amq_mgt_config_builddate     = "2010/10/06 ";
char *EMBED__amq_mgt_config_version_end   = "VeRsIoNeNd:ipc";

