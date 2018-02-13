/*---------------------------------------------------------------------------
    amq_queue.h - amq_queue component

This class implements the server queue class, an asynchronous object
that acts as a envelope for the separate queue managers for each
class.  This is a lock-free asynchronous class.
    Generated from amq_queue.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_QUEUE_SAFE
#   define INCLUDE_AMQ_QUEUE_SAFE
#   define INCLUDE_AMQ_QUEUE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_QUEUE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_queue_t amq_queue_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
#    define AMQ_QUEUE_HISTORY_LENGTH 32
#endif

#define AMQ_QUEUE_ALIVE                 0xFABB
#define AMQ_QUEUE_DEAD                  0xDEAD

#define AMQ_QUEUE_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_queue\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_QUEUE_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_queue at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_QUEUE_ALIVE, self->object_tag);\
        amq_queue_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
extern qbyte
    gbl_amq_queue_count;
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "amq_queue_table.h"
#   include "amq_queue_list.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_queue_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_QUEUE_UNSAFE
#   define INCLUDE_AMQ_QUEUE_UNSAFE
#   define INCLUDE_AMQ_QUEUE_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_queue_table.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_queue_agent.h"
//  Global variables

extern Bool
    amq_queue_animating;

//  Structure of the amq_queue object

struct _amq_queue_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_QUEUE_HISTORY_LENGTH];
    int
        history_line  [AMQ_QUEUE_HISTORY_LENGTH];
    char
        *history_type [AMQ_QUEUE_HISTORY_LENGTH];
    int
        history_links [AMQ_QUEUE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
amq_queue_table_t
    *table_head;                    //  Hash table container
amq_queue_t
    *table_next;                    //  Next item in the hash slot
qbyte
    table_index;                    //  Index of item in table
icl_shortstr_t
    key;                            //  Item's original key
volatile amq_queue_list_t *list_head;
volatile amq_queue_t *list_prev;
volatile amq_queue_t *list_next;
qbyte
    object_id;                      //  System-wide object id
amq_console_t
    *console;                       //  Reference to console
amq_server_connection_t
    *connection;                    //  Parent connection, if any
icl_shortstr_t
    name;                           //  Queue name
Bool
    enabled,                        //  Queue is enabled?
    exclusive,                      //  Is queue exclusive?
    auto_delete,                    //  Auto-delete unused queue?
    locked;                         //  Queue for exclusive consumer?
amq_queue_basic_t
    *queue_basic;                   //  Basic content queue
icl_shortstr_t
    last_exchange_name,             //  Last exchange bound to
    last_exchange_type,             //  Last exchange type bound to
    last_routing_key;               //  Last routing key
icl_shortstr_t
    last_binding_args;              //  Last binding arguments
ipr_looseref_list_t
    *bindings;                      //  List of bindings for queue
qbyte
    warn_limit,                     //  Warn user that we're in trouble
    drop_limit,                     //  Drop new incoming messages
    trim_limit,                     //  Trim old stored messages
    kill_limit;                     //  Kill the connection, it's dead Jim
amq_lease_t
    *lease;                         //  Feed lease, if any
Bool
    feed_on,                        //  Feed lease enabled/disabled
    feed_no_local;                  //  No-local applied to feed

//  Statistics
int64_t
    traffic_in,                     //  Traffic in, in octets
    traffic_out,                    //  Traffic out, in octets
    contents_in,                    //  Contents in, in octets
    contents_out,                   //  Contents out, in octets
    drop_count;                     //  Dropped messages
Bool
    warned,                         //  Have we already warned?
    dropped,                        //  Are we already dropping?
    trimmed;                        //  Are we already trimming?
};

#   ifdef __cplusplus
}
#   endif
#   include "amq_queue_list.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_queue_new(connection,name,exclusive,auto_delete,arguments)  amq_queue_new_ (__FILE__, __LINE__, connection, name, exclusive, auto_delete, arguments)
amq_queue_t *
    amq_queue_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_server_connection_t * connection,   //  Owner connection
char * name,                            //  Queue name
Bool exclusive,                         //  Is queue exclusive?
Bool auto_delete,                       //  Auto-delete unused queue?
icl_longstr_t* arguments                //  Queue arguments
);

int
    amq_queue_unbind_connection (
amq_queue_t * self                      //  Reference to object
);

int
    amq_queue_publish (
amq_queue_t * self,                     //  Reference to object
amq_server_channel_t * channel,         //  Channel for reply
amq_content_basic_t * content,          //  Content to publish
Bool immediate                          //  Send immediately or return?
);

int
    amq_queue_get (
amq_queue_t * self,                     //  Reference to object
amq_server_channel_t * channel,         //  Channel for reply
int class_id                            //  The content class
);

int
    amq_queue_consume (
amq_queue_t * self,                     //  Reference to object
amq_consumer_t * consumer,              //  Consumer reference
Bool active,                            //  Create active consumer?
Bool nowait                             //  No reply method wanted
);

int
    amq_queue_cancel (
amq_queue_t * self,                     //  Reference to object
amq_consumer_t * consumer,              //  Consumer reference
Bool notify,                            //  Notify client application?
Bool nowait                             //  No reply method wanted
);

int
    amq_queue_self_destruct (
amq_queue_t * self                      //  Reference to object
);

int
    amq_queue_consumer_ack (
amq_queue_t * self,                     //  Reference to object
amq_consumer_t * consumer               //  Consumer to ack
);

int
    amq_queue_purge (
amq_queue_t * self,                     //  Reference to object
amq_server_channel_t * channel,         //  Channel for reply
Bool nowait                             //  No reply method wanted
);

int
    amq_queue_dispatch (
amq_queue_t * self                      //  Reference to object
);

int
    amq_queue_message_count (
amq_queue_t * self                      //  Reference to object
);

int
    amq_queue_consumer_count (
amq_queue_t * self                      //  Reference to object
);

int
    amq_queue_binding_register (
amq_queue_t * self,                     //  Reference to object
amq_exchange_t * exchange,              //  Not documented
amq_binding_t * binding                 //  Not documented
);

int
    amq_queue_binding_cancel (
amq_queue_t * self,                     //  Reference to object
amq_exchange_t * exchange,              //  Not documented
amq_binding_t * binding                 //  Not documented
);

void
    amq_queue_selftest (
void);

qbyte
    amq_queue_count (
void);

int
    amq_queue_inspect_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request           //  The original request
);

int
    amq_queue_inspect (
amq_queue_t * self,                     //  Reference to object
amq_content_basic_t * request           //  The original request
);

int
    amq_queue_modify_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_queue_modify (
amq_queue_t * self,                     //  Reference to object
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_queue_method_shim (
void * self_v,                          //  Object cast as a void *
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_queue_method (
amq_queue_t * self,                     //  Reference to object
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Argument fields
);

void
    amq_queue_unlink_shim (
void * object_p                         //  Reference pointer cast as a void *
);

void
    amq_queue_terminate (
void);

void
    amq_queue_remove_from_all_containers (
amq_queue_t * self                      //  The itemThe item
);

#define amq_queue_show(item,opcode,trace_file)  amq_queue_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_queue_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_queue_destroy(self)         amq_queue_destroy_ (self, __FILE__, __LINE__)
int
    amq_queue_destroy_ (
amq_queue_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_queue_unlink(self)          amq_queue_unlink_ (self, __FILE__, __LINE__)
void
    amq_queue_unlink_ (
amq_queue_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_queue_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_queue_free(self)            amq_queue_free_ (self, __FILE__, __LINE__)
void
    amq_queue_free_ (
amq_queue_t * self,                     //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_queue_link(self)            amq_queue_link_ (self, __FILE__, __LINE__)
amq_queue_t *
    amq_queue_link_ (
amq_queue_t * self,                     //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_new_in_scope(self_p,_scope,connection,name,exclusive,auto_delete,arguments)  amq_queue_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, connection, name, exclusive, auto_delete, arguments)
void
    amq_queue_new_in_scope_ (
amq_queue_t * * self_p,                 //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_server_connection_t * connection,   //  Owner connection
char * name,                            //  Queue name
Bool exclusive,                         //  Is queue exclusive?
Bool auto_delete,                       //  Auto-delete unused queue?
icl_longstr_t* arguments                //  Queue arguments
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_QUEUE_INLINE)
#   define INCLUDE_AMQ_QUEUE_INLINE
#   define INCLUDE_AMQ_QUEUE_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_queue_table.h"
#   include "amq_queue_list.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_queue_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_QUEUE_ROOT
#   endif
# endif
#endif
