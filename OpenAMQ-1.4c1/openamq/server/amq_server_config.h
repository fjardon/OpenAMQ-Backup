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
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_server_config\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_SERVER_CONFIG_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_server_config at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_SERVER_CONFIG_ALIVE, self->object_tag);\
        amq_server_config_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "smt_log.h"
#   include "icl_mem.h"
#   include "icl_system.h"
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
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"
//  Global variables

extern Bool
    amq_server_config_animating;
extern amq_server_config_t
    *amq_server_config;                 //  Global properties object
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
    amq_server_config_shadow (
amq_server_config_t * self,             //  Reference to object
ipr_config_t * source                   //  Config data to shadow
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
    amq_server_config_set_syslog (
amq_server_config_t * self,             //  Reference to object
int syslog                              //  Not documented
);

int
    amq_server_config_syslog (
amq_server_config_t * self              //  Reference to self
);

int
    amq_server_config_set_coremark_cycles (
amq_server_config_t * self,             //  Reference to object
int coremark_cycles                     //  Not documented
);

int
    amq_server_config_coremark_cycles (
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

char *
    amq_server_config_filename (
amq_server_config_t * self              //  Not documented
);

void
    amq_server_config_set_filename (
amq_server_config_t * self,             //  Not documented
char * filename                         //  Not documented
);

ipr_config_t *
    amq_server_config_table (
amq_server_config_t * self              //  Not documented
);

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
    amq_server_config_show_animation (
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
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

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
