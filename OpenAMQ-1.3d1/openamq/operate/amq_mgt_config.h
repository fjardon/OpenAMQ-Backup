/*---------------------------------------------------------------------------
    amq_mgt_config.h - amq_mgt_config component

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

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_AMQ_MGT_CONFIG_SAFE
#   define INCLUDE_AMQ_MGT_CONFIG_SAFE
#   define INCLUDE_AMQ_MGT_CONFIG_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_MGT_CONFIG_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_mgt_config_t amq_mgt_config_t;

#define AMQ_MGT_CONFIG_ALIVE            0xFABB
#define AMQ_MGT_CONFIG_DEAD             0xDEAD

#define AMQ_MGT_CONFIG_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_mgt_config\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_MGT_CONFIG_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_mgt_config at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_MGT_CONFIG_ALIVE, self->object_tag);\
        amq_mgt_config_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_mgt_console.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_MGT_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_MGT_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_MGT_CONFIG_UNSAFE
#   define INCLUDE_AMQ_MGT_CONFIG_UNSAFE
#   define INCLUDE_AMQ_MGT_CONFIG_ACTIVE

#   include "amq_mgt_console.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_mgt_config_animating;

//  Structure of the amq_mgt_config object

struct _amq_mgt_config_t {
dbyte
    object_tag;                     //  Object validity marker
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
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_mgt_config_new(session,id)  amq_mgt_config_new_ (__FILE__, __LINE__, session, id)
amq_mgt_config_t *
    amq_mgt_config_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_client_session_t * session,         //  AMQP session
int id                                  //  Object ID
);

int
    amq_mgt_config_load (
amq_mgt_config_t * self                 //  Reference to object
);

int
    amq_mgt_config_print_children (
amq_mgt_config_t * self,                //  Reference to object
FILE * xml_data                         //  XML data capture
);

int
    amq_mgt_config_print_properties (
amq_mgt_config_t * self,                //  Reference to object
FILE * xml_data                         //  XML data capture
);

int
    amq_mgt_config_print_summary (
amq_mgt_config_t * self,                //  Reference to object
FILE * xml_data                         //  XML data capture
);

int
    amq_mgt_config_cmdline (
amq_mgt_config_t * self,                //  Reference to object
char * path,                            //  Current path
int depth,                              //  Current depth
ipr_token_list_t * tokens,              //  Automation, if any
FILE * xml_data                         //  XML data capture
);

void
    amq_mgt_config_selftest (
void);

void
    amq_mgt_config_terminate (
void);

#define amq_mgt_config_show(item,opcode,trace_file)  amq_mgt_config_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_mgt_config_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_mgt_config_destroy(self)    amq_mgt_config_destroy_ (self, __FILE__, __LINE__)
void
    amq_mgt_config_destroy_ (
amq_mgt_config_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_mgt_config_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_mgt_config_new_in_scope(self_p,_scope,session,id)  amq_mgt_config_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, session, id)
void
    amq_mgt_config_new_in_scope_ (
amq_mgt_config_t * * self_p,            //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_client_session_t * session,         //  AMQP session
int id                                  //  Object ID
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_MGT_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_MGT_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_MGT_CONFIG_INLINE)
#   define INCLUDE_AMQ_MGT_CONFIG_INLINE
#   define INCLUDE_AMQ_MGT_CONFIG_ACTIVE

#   include "amq_mgt_console.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONFIG)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_NEW)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_DESTROY)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_LOAD)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_PRINT_CHILDREN)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_PRINT_PROPERTIES)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_PRINT_SUMMARY)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_CMDLINE)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_SELFTEST)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_TERMINATE)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_SHOW)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_ALLOC)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_FREE)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_ANIMATE)   || defined (BASE_TRACE_AMQ_MGT_CONFIG_NEW_IN_SCOPE) )
void
    amq_mgt_config_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_MGT_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_MGT_CONFIG_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_MGT_CONFIG_ROOT
#   endif
# endif
#endif
