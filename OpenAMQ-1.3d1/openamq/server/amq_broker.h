/*---------------------------------------------------------------------------
    amq_broker.h - amq_broker component

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

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_AMQ_BROKER_SAFE
#   define INCLUDE_AMQ_BROKER_SAFE
#   define INCLUDE_AMQ_BROKER_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_BROKER_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_broker_t amq_broker_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
#    define AMQ_BROKER_HISTORY_LENGTH 32
#endif

#define AMQ_BROKER_ALIVE                0xFABB
#define AMQ_BROKER_DEAD                 0xDEAD

#define AMQ_BROKER_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_broker\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_BROKER_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_broker at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_BROKER_ALIVE, self->object_tag);\
        amq_broker_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "asl_field_list.h"
#   include "amq_server_agent.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_broker_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_BROKER_ACTIVE
#   if defined (ICL_IMPORT_AMQ_BROKER_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_BROKER_UNSAFE
#   define INCLUDE_AMQ_BROKER_UNSAFE
#   define INCLUDE_AMQ_BROKER_ACTIVE

#   include "asl_field_list.h"
#   include "amq_server_agent.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_broker_agent.h"
//  Global variables

extern Bool
    amq_broker_animating;
extern amq_broker_t
    *amq_broker;                        //  Single broker, self

//  Structure of the amq_broker object

struct _amq_broker_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_BROKER_HISTORY_LENGTH];
    int
        history_line  [AMQ_BROKER_HISTORY_LENGTH];
    char
        *history_type [AMQ_BROKER_HISTORY_LENGTH];
    int
        history_links [AMQ_BROKER_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
amq_server_connection_table_t
    *connections;                   //  Connection table
amq_server_connection_list_t
    *connection_list;               //  Connection list
smt_thread_t
    *agent_thread;                  //  amq_server_server_agent thread
apr_time_t
    started;                        //  Time started
icl_shortstr_t
    host;                           //  Server network address
icl_shortstr_t
    name;                           //  Server name
icl_shortstr_t
    known_hosts;                    //  Known hosts list
ipr_meter_t
    *imeter,                        //  Incoming messages meter
    *ometer;                        //  Outgoing messages meter
int
    monitor_timer;                  //  Monitor timer
FILE
    *stats;                         //  Statistics output
smt_log_t
    *alert_log,                     //  Alert log file
    *daily_log,                     //  Daily log file
    *debug_log;                     //  Debug log file
Bool
    cycled;                         //  Log files just cycled?
qbyte
    direct_in,                      //  Direct messages received
    direct_out;                     //  Direct messages sent out
qbyte
    object_id;                      //  System-wide object id
amq_console_t
    *console;                       //  Reference to console
Bool
    locked,                         //  Is broker locked?
    restart;                        //  Restart broker after exit?
int
    dump_state_timer,               //  Dump state timer
    auto_crash_timer,               //  Automatic failure
    auto_block_timer;               //  Automatic blockage
amq_vhost_t
    *vhost;                         //  Single vhost (for now)
amq_connection_by_broker_t
    *mgt_connection_list;           //  Connection mgt objects list
amq_failover_t
    *failover;                      //  Failover controller
qbyte
    direct_sunk,                    //  Direct messages sunk
    direct_fed;                     //  Direct messages fed
qbyte
    direct_high;                    //  High water mark for direct feeds
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_broker_new()                amq_broker_new_ (__FILE__, __LINE__)
amq_broker_t *
    amq_broker_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    amq_broker_unbind_queue (
amq_broker_t * self,                    //  Reference to object
amq_queue_t * queue                     //  The queue to unbind
);

void
    amq_broker_selftest (
void);

int
    amq_broker_inspect_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request           //  The original request
);

int
    amq_broker_inspect (
amq_broker_t * self,                    //  Reference to object
amq_content_basic_t * request           //  The original request
);

int
    amq_broker_modify_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_broker_modify (
amq_broker_t * self,                    //  Reference to object
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_broker_method_shim (
void * self_v,                          //  Object cast as a void *
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_broker_method (
amq_broker_t * self,                    //  Reference to object
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Argument fields
);

void
    amq_broker_unlink_shim (
void * object_p                         //  Reference pointer cast as a void *
);

void
    amq_broker_terminate (
void);

#define amq_broker_free(self)           amq_broker_free_ (self, __FILE__, __LINE__)
void
    amq_broker_free_ (
amq_broker_t * self,                    //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

int
    amq_broker_start (
amq_broker_t * self                     //  Reference to object
);

int
    amq_broker_shutdown (
amq_broker_t * self                     //  Reference to object
);

#define amq_broker_destroy(self)        amq_broker_destroy_ (self, __FILE__, __LINE__)
int
    amq_broker_destroy_ (
amq_broker_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_broker_unlink(self)         amq_broker_unlink_ (self, __FILE__, __LINE__)
void
    amq_broker_unlink_ (
amq_broker_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_broker_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_broker_show(item,opcode,trace_file)  amq_broker_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_broker_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_broker_link(self)           amq_broker_link_ (self, __FILE__, __LINE__)
amq_broker_t *
    amq_broker_link_ (
amq_broker_t * self,                    //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_broker_new_in_scope(self_p,_scope)  amq_broker_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_broker_new_in_scope_ (
amq_broker_t * * self_p,                //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_BROKER_ACTIVE
#   if defined (ICL_IMPORT_AMQ_BROKER_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_BROKER_INLINE)
#   define INCLUDE_AMQ_BROKER_INLINE
#   define INCLUDE_AMQ_BROKER_ACTIVE

#   include "asl_field_list.h"
#   include "amq_server_agent.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BROKER)   || defined (BASE_TRACE_AMQ_BROKER_NEW)   || defined (BASE_TRACE_AMQ_BROKER_DESTROY)   || defined (BASE_TRACE_AMQ_BROKER_UNBIND_QUEUE)   || defined (BASE_TRACE_AMQ_BROKER_SELFTEST)   || defined (BASE_TRACE_AMQ_BROKER_INSPECT_SHIM)   || defined (BASE_TRACE_AMQ_BROKER_INSPECT)   || defined (BASE_TRACE_AMQ_BROKER_MODIFY_SHIM)   || defined (BASE_TRACE_AMQ_BROKER_MODIFY)   || defined (BASE_TRACE_AMQ_BROKER_METHOD_SHIM)   || defined (BASE_TRACE_AMQ_BROKER_METHOD)   || defined (BASE_TRACE_AMQ_BROKER_UNLINK_SHIM)   || defined (BASE_TRACE_AMQ_BROKER_INITIALISE)   || defined (BASE_TRACE_AMQ_BROKER_TERMINATE)   || defined (BASE_TRACE_AMQ_BROKER_FREE)   || defined (BASE_TRACE_AMQ_BROKER_START)   || defined (BASE_TRACE_AMQ_BROKER_SHUTDOWN)   || defined (BASE_TRACE_AMQ_BROKER_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_BROKER_UNLINK)   || defined (BASE_TRACE_AMQ_BROKER_ANIMATE)   || defined (BASE_TRACE_AMQ_BROKER_SHOW)   || defined (BASE_TRACE_AMQ_BROKER_ALLOC)   || defined (BASE_TRACE_AMQ_BROKER_LINK)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_BROKER_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_BROKER_NEW_IN_SCOPE) )
void
    amq_broker_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_broker_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_BROKER_ACTIVE
#   if defined (ICL_IMPORT_AMQ_BROKER_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_BROKER_ROOT
#   endif
# endif
#endif
