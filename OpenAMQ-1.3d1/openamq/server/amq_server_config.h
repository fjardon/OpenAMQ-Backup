/*---------------------------------------------------------------------------
    amq_server_config.h - amq_server_config component

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

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_AMQ_SERVER_CONFIG_SAFE
#   define INCLUDE_AMQ_SERVER_CONFIG_SAFE
#   define INCLUDE_AMQ_SERVER_CONFIG_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_SERVER_CONFIG_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_server_config_t amq_server_config_t;

#define AMQ_SERVER_CONFIG_ALIVE         0xFABB
#define AMQ_SERVER_CONFIG_DEAD          0xDEAD

#define AMQ_SERVER_CONFIG_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_server_config\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_SERVER_CONFIG_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_server_config at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_SERVER_CONFIG_ALIVE, self->object_tag);\
        amq_server_config_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "smt_log.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_SERVER_CONFIG_UNSAFE
#   define INCLUDE_AMQ_SERVER_CONFIG_UNSAFE
#   define INCLUDE_AMQ_SERVER_CONFIG_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"
//  Global variables

extern Bool
    amq_server_config_animating;
extern amq_server_config_t
    *amq_server_config;                 //  Global properties object

//  Structure of the amq_server_config object

struct _amq_server_config_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    dbyte
        object_tag;                     //  Object validity marker
ipr_config_t *
    config;                         //  Configuration table
icl_shortstr_t
    filename;                       //  Configuration file name
icl_shortstr_t
    port;                           //  Server port for clients
icl_shortstr_t
    listen;                         //  Address (local network interface) to listen on
int
    queue_timeout;                  //  Timeout for auto-deleted queues
icl_shortstr_t
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
int
    trace;                          //  Protocol trace level
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
icl_shortstr_t
    backup;                         //  Failover backup host:port
icl_shortstr_t
    primary;                        //  Failover primary host:port
int
    failover_timeout;               //  Failover timeout, in seconds
icl_shortstr_t
    attach;                         //  Enable auto-federation to specified host
icl_shortstr_t
    attach_vhost;                   //  Auto-federation virtual host name
icl_shortstr_t
    attach_login;                   //  Auto-federation login user name
icl_shortstr_t
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
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_server_config_new()         amq_server_config_new_ (__FILE__, __LINE__)
amq_server_config_t *
    amq_server_config_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    amq_server_config_load_xmlfile (
amq_server_config_t * self,             //  Reference to object
char * filename,                        //  Config file to load
Bool required                           //  Config file is required?
);

int
    amq_server_config_load_bucket (
amq_server_config_t * self,             //  Reference to object
ipr_bucket_t * bucket                   //  Config data to load
);

int
    amq_server_config_commit (
amq_server_config_t * self,             //  Reference to object
char * filename                         //  Config file to save
);

int
    amq_server_config_rollback (
amq_server_config_t * self              //  Reference to object
);

void
    amq_server_config_cmdline_help (
void);

int
    amq_server_config_cmdline_parse (
amq_server_config_t * self,             //  Reference to object
char * name,                            //  Name of application
int argc,                               //  Argument count
char ** argv                            //  Argument list
);

int
    amq_server_config_options_help (
amq_server_config_t * self,             //  Reference to object
char * name                             //  Name of application
);

int
    amq_server_config_set_port (
amq_server_config_t * self,             //  Reference to object
char * port                             //  Not documented
);

char *
    amq_server_config_port (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_listen (
amq_server_config_t * self,             //  Reference to object
char * listen                           //  Not documented
);

char *
    amq_server_config_listen (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_queue_timeout (
amq_server_config_t * self,             //  Reference to object
int queue_timeout                       //  Not documented
);

int
    amq_server_config_queue_timeout (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_vhost (
amq_server_config_t * self,             //  Reference to object
char * vhost                            //  Not documented
);

char *
    amq_server_config_vhost (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_user (
amq_server_config_t * self,             //  Reference to object
char * user                             //  Not documented
);

char *
    amq_server_config_user (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_group (
amq_server_config_t * self,             //  Reference to object
char * group                            //  Not documented
);

char *
    amq_server_config_group (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_monitor (
amq_server_config_t * self,             //  Reference to object
int monitor                             //  Not documented
);

int
    amq_server_config_monitor (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_dump_state (
amq_server_config_t * self,             //  Reference to object
int dump_state                          //  Not documented
);

int
    amq_server_config_dump_state (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_record_stats (
amq_server_config_t * self,             //  Reference to object
Bool record_stats                       //  Not documented
);

Bool
    amq_server_config_record_stats (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_log_path (
amq_server_config_t * self,             //  Reference to object
char * log_path                         //  Not documented
);

char *
    amq_server_config_log_path (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_keep_logs (
amq_server_config_t * self,             //  Reference to object
Bool keep_logs                          //  Not documented
);

Bool
    amq_server_config_keep_logs (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_archive_path (
amq_server_config_t * self,             //  Reference to object
char * archive_path                     //  Not documented
);

char *
    amq_server_config_archive_path (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_archive_cmd (
amq_server_config_t * self,             //  Reference to object
char * archive_cmd                      //  Not documented
);

char *
    amq_server_config_archive_cmd (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_alert_log (
amq_server_config_t * self,             //  Reference to object
char * alert_log                        //  Not documented
);

char *
    amq_server_config_alert_log (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_daily_log (
amq_server_config_t * self,             //  Reference to object
char * daily_log                        //  Not documented
);

char *
    amq_server_config_daily_log (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_debug_log (
amq_server_config_t * self,             //  Reference to object
char * debug_log                        //  Not documented
);

char *
    amq_server_config_debug_log (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_debug_route (
amq_server_config_t * self,             //  Reference to object
Bool debug_route                        //  Not documented
);

Bool
    amq_server_config_debug_route (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_debug_queue (
amq_server_config_t * self,             //  Reference to object
Bool debug_queue                        //  Not documented
);

Bool
    amq_server_config_debug_queue (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_debug_peering (
amq_server_config_t * self,             //  Reference to object
Bool debug_peering                      //  Not documented
);

Bool
    amq_server_config_debug_peering (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_debug_console (
amq_server_config_t * self,             //  Reference to object
Bool debug_console                      //  Not documented
);

Bool
    amq_server_config_debug_console (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_trace (
amq_server_config_t * self,             //  Reference to object
int trace                               //  Not documented
);

int
    amq_server_config_trace (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_heartbeat (
amq_server_config_t * self,             //  Reference to object
int heartbeat                           //  Not documented
);

int
    amq_server_config_heartbeat (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_setup_timeout (
amq_server_config_t * self,             //  Reference to object
int setup_timeout                       //  Not documented
);

int
    amq_server_config_setup_timeout (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_close_timeout (
amq_server_config_t * self,             //  Reference to object
int close_timeout                       //  Not documented
);

int
    amq_server_config_close_timeout (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_accept_retry_timeout (
amq_server_config_t * self,             //  Reference to object
int accept_retry_timeout                //  Not documented
);

int
    amq_server_config_accept_retry_timeout (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_polling_threads (
amq_server_config_t * self,             //  Reference to object
int polling_threads                     //  Not documented
);

int
    amq_server_config_polling_threads (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_working_threads (
amq_server_config_t * self,             //  Reference to object
int working_threads                     //  Not documented
);

int
    amq_server_config_working_threads (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_tcp_nodelay (
amq_server_config_t * self,             //  Reference to object
Bool tcp_nodelay                        //  Not documented
);

Bool
    amq_server_config_tcp_nodelay (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_tcp_rcvbuf (
amq_server_config_t * self,             //  Reference to object
int tcp_rcvbuf                          //  Not documented
);

int
    amq_server_config_tcp_rcvbuf (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_tcp_sndbuf (
amq_server_config_t * self,             //  Reference to object
int tcp_sndbuf                          //  Not documented
);

int
    amq_server_config_tcp_sndbuf (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_frame_max (
amq_server_config_t * self,             //  Reference to object
int frame_max                           //  Not documented
);

int
    amq_server_config_frame_max (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_direct (
amq_server_config_t * self,             //  Reference to object
int direct                              //  Not documented
);

int
    amq_server_config_direct (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_private_credit (
amq_server_config_t * self,             //  Reference to object
int private_credit                      //  Not documented
);

int
    amq_server_config_private_credit (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_shared_credit (
amq_server_config_t * self,             //  Reference to object
int shared_credit                       //  Not documented
);

int
    amq_server_config_shared_credit (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_backup (
amq_server_config_t * self,             //  Reference to object
char * backup                           //  Not documented
);

char *
    amq_server_config_backup (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_primary (
amq_server_config_t * self,             //  Reference to object
char * primary                          //  Not documented
);

char *
    amq_server_config_primary (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_failover_timeout (
amq_server_config_t * self,             //  Reference to object
int failover_timeout                    //  Not documented
);

int
    amq_server_config_failover_timeout (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_attach (
amq_server_config_t * self,             //  Reference to object
char * attach                           //  Not documented
);

char *
    amq_server_config_attach (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_attach_vhost (
amq_server_config_t * self,             //  Reference to object
char * attach_vhost                     //  Not documented
);

char *
    amq_server_config_attach_vhost (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_attach_login (
amq_server_config_t * self,             //  Reference to object
char * attach_login                     //  Not documented
);

char *
    amq_server_config_attach_login (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_attach_all (
amq_server_config_t * self,             //  Reference to object
char * attach_all                       //  Not documented
);

char *
    amq_server_config_attach_all (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_batching (
amq_server_config_t * self,             //  Reference to object
int batching                            //  Not documented
);

int
    amq_server_config_batching (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_direct_heartbeat (
amq_server_config_t * self,             //  Reference to object
int direct_heartbeat                    //  Not documented
);

int
    amq_server_config_direct_heartbeat (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_no_ack (
amq_server_config_t * self,             //  Reference to object
Bool no_ack                             //  Not documented
);

Bool
    amq_server_config_no_ack (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_auto_crash (
amq_server_config_t * self,             //  Reference to object
int auto_crash                          //  Not documented
);

int
    amq_server_config_auto_crash (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_auto_block (
amq_server_config_t * self,             //  Reference to object
int auto_block                          //  Not documented
);

int
    amq_server_config_auto_block (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_kernel_limit (
amq_server_config_t * self,             //  Reference to object
int kernel_limit                        //  Not documented
);

int
    amq_server_config_kernel_limit (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_dump_log (
amq_server_config_t * self,             //  Reference to object
smt_log_t * logfile                     //  Log file to dump to
);

void
    amq_server_config_selftest (
void);

void
    amq_server_config_terminate (
void);

#define amq_server_config_show(item,opcode,trace_file)  amq_server_config_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_server_config_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_server_config_destroy(self)  amq_server_config_destroy_ (self, __FILE__, __LINE__)
void
    amq_server_config_destroy_ (
amq_server_config_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    amq_server_config_read_lock (
amq_server_config_t * self              //  Reference to object
);

int
    amq_server_config_write_lock (
amq_server_config_t * self              //  Reference to object
);

int
    amq_server_config_unlock (
amq_server_config_t * self              //  Reference to object
);

void
    amq_server_config_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_server_config_new_in_scope(self_p,_scope)  amq_server_config_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_server_config_new_in_scope_ (
amq_server_config_t * * self_p,         //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_SERVER_CONFIG_INLINE)
#   define INCLUDE_AMQ_SERVER_CONFIG_INLINE
#   define INCLUDE_AMQ_SERVER_CONFIG_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NEW)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DESTROY)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOAD_XMLFILE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOAD_BUCKET)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_COMMIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ROLLBACK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CMDLINE_HELP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CMDLINE_PARSE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_OPTIONS_HELP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PORT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PORT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_LISTEN)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LISTEN)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_QUEUE_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_QUEUE_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_VHOST)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_VHOST)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_USER)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_USER)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_GROUP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_GROUP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_MONITOR)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_MONITOR)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DUMP_STATE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DUMP_STATE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_RECORD_STATS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_RECORD_STATS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_LOG_PATH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_LOG_PATH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_KEEP_LOGS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_KEEP_LOGS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ARCHIVE_PATH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ARCHIVE_PATH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ARCHIVE_CMD)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ARCHIVE_CMD)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ALERT_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ALERT_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DAILY_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DAILY_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_ROUTE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_ROUTE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_QUEUE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_QUEUE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_PEERING)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_PEERING)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DEBUG_CONSOLE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DEBUG_CONSOLE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_HEARTBEAT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_HEARTBEAT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_SETUP_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SETUP_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_CLOSE_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CLOSE_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ACCEPT_RETRY_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ACCEPT_RETRY_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_POLLING_THREADS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_POLLING_THREADS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_WORKING_THREADS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_WORKING_THREADS)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_NODELAY)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_NODELAY)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_RCVBUF)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_RCVBUF)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_TCP_SNDBUF)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TCP_SNDBUF)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_FRAME_MAX)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FRAME_MAX)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DIRECT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DIRECT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PRIVATE_CREDIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PRIVATE_CREDIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_SHARED_CREDIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SHARED_CREDIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_BACKUP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_BACKUP)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_PRIMARY)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_PRIMARY)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_FAILOVER_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FAILOVER_TIMEOUT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_VHOST)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_VHOST)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_LOGIN)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_LOGIN)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_ATTACH_ALL)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ATTACH_ALL)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_BATCHING)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_BATCHING)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_DIRECT_HEARTBEAT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DIRECT_HEARTBEAT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_NO_ACK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NO_ACK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_AUTO_CRASH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_AUTO_CRASH)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_AUTO_BLOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_AUTO_BLOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SET_KERNEL_LIMIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_KERNEL_LIMIT)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DUMP_LOG)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SELFTEST)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_SHOW)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ALLOC)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_FREE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_READ_LOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_UNLOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_ANIMATE)   || defined (BASE_TRACE_AMQ_SERVER_CONFIG_NEW_IN_SCOPE) )
void
    amq_server_config_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "ipr.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CONFIG_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_SERVER_CONFIG_ROOT
#   endif
# endif
#endif
