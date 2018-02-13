/*---------------------------------------------------------------------------
    amq_exchange.h - amq_exchange component

This class implements the server exchange, an asynchronous
object that acts as a envelope for the separate exchange managers
for each type of exchange. This is a lock-free asynchronous class.
    Generated from amq_exchange.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_EXCHANGE_SAFE
#   define INCLUDE_AMQ_EXCHANGE_SAFE
#   define INCLUDE_AMQ_EXCHANGE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_EXCHANGE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_exchange_t amq_exchange_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
#    define AMQ_EXCHANGE_HISTORY_LENGTH 32
#endif

#define AMQ_EXCHANGE_ALIVE              0xFABB
#define AMQ_EXCHANGE_DEAD               0xDEAD

#define AMQ_EXCHANGE_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_exchange\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_EXCHANGE_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_exchange at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_EXCHANGE_ALIVE, self->object_tag);\
        amq_exchange_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
extern qbyte
    gbl_amq_exchange_count;
//  Exchange types we implement
#define AMQ_EXCHANGE_SYSTEM         1
#define AMQ_EXCHANGE_FANOUT         2
#define AMQ_EXCHANGE_DIRECT         3
#define AMQ_EXCHANGE_TOPIC          4
#define AMQ_EXCHANGE_HEADERS        5
#define AMQ_EXCHANGE_REGEXP         6

//  Max number of queues we can publish one message to.
//  Used for static table of void * per exchange instance.
#define AMQ_QUEUE_SET_MAX           16000
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "amq_queue_bindings_list_table.h"
#   include "amq_exchange_table.h"
#   include "amq_exchange_list.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_exchange_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_EXCHANGE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_EXCHANGE_UNSAFE
#   define INCLUDE_AMQ_EXCHANGE_UNSAFE
#   define INCLUDE_AMQ_EXCHANGE_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_queue_bindings_list_table.h"
#   include "amq_exchange_table.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_exchange_agent.h"
//  Global variables

extern Bool
    amq_exchange_animating;

//  Structure of the amq_exchange object

struct _amq_exchange_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_EXCHANGE_HISTORY_LENGTH];
    int
        history_line  [AMQ_EXCHANGE_HISTORY_LENGTH];
    char
        *history_type [AMQ_EXCHANGE_HISTORY_LENGTH];
    int
        history_links [AMQ_EXCHANGE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
amq_exchange_table_t
    *table_head;                    //  Hash table container
amq_exchange_t
    *table_next;                    //  Next item in the hash slot
qbyte
    table_index;                    //  Index of item in table
icl_shortstr_t
    key;                            //  Item's original key
volatile amq_exchange_list_t *list_head;
volatile amq_exchange_t *list_prev;
volatile amq_exchange_t *list_next;
qbyte
    object_id;                      //  System-wide object id
amq_console_t
    *console;                       //  Reference to console
int
    type;                           //  Exchange type
icl_shortstr_t
    name;                           //  Exchange name
Bool
    internal;                       //  Internal exchange?
void
    *object;                        //  Exchange implementation
amq_binding_list_t
    *binding_list;                  //  Bindings as a list
amq_queue_bindings_list_table_t
    *queue_bindings;                //  Bindings sorted by queues
ipr_hash_table_t
    *binding_hash;                  //  Bindings hashed by routing_key
ipr_index_t
    *binding_index;                 //  Gives us binding indices
amq_queue_t
    **queue_set;                    //  Queue publish set
amq_federation_t
    *federation;                    //  Federation for this exchange, if any
int
    federation_type;                //  Federation type, or 0 means none

//  Exchange access functions
int
    (*publish) (
        void                 *self,
        amq_server_channel_t *channel,
        amq_content_basic_t  *content,
        int                   group,
        Bool                  immediate);
int
    (*compile) (
        void                 *self,
        amq_binding_t        *binding,
        amq_server_channel_t *channel);
int
    (*unbind) (
        void                 *self,
        amq_binding_t        *binding);

//  Statistics
int64_t
    traffic_in,                     //  Traffic in, in octets
    traffic_out,                    //  Traffic out, in octets
    contents_in,                    //  Contents in, in octets
    contents_out;                   //  Contents out, in octets
};

#   ifdef __cplusplus
}
#   endif
#   include "amq_exchange_list.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_exchange_new(type,name,internal,auto_federate)  amq_exchange_new_ (__FILE__, __LINE__, type, name, internal, auto_federate)
amq_exchange_t *
    amq_exchange_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
int type,                               //  Exchange type
char * name,                            //  Exchange name
Bool internal,                          //  Internal exchange?
Bool auto_federate                      //  Auto-federate exchange?
);

int
    amq_exchange_type_lookup (
char * type_name                        //  Type name to lookup
);

char *
    amq_exchange_type_name (
int type                                //  Type index to translate
);

int
    amq_exchange_bind_queue (
amq_exchange_t * self,                  //  Reference to object
amq_server_channel_t * channel,         //  Channel for reply
amq_queue_t * queue,                    //  The queue to bind
char * routing_key,                     //  Bind to routing key
icl_longstr_t * arguments               //  Bind arguments
);

int
    amq_exchange_unbind_queue (
amq_exchange_t * self,                  //  Reference to object
amq_server_channel_t * channel,         //  Channel for reply
amq_queue_t * queue,                    //  The queue to bind
char * routing_key,                     //  Bind to routing key
icl_longstr_t * arguments               //  Bind arguments
);

int
    amq_exchange_publish (
amq_exchange_t * self,                  //  Reference to object
amq_server_channel_t * channel,         //  Channel for reply
amq_content_basic_t * content,          //  Content to publish
Bool mandatory,                         //  Route to queue or return?
Bool immediate,                         //  Send immediately or return?
int group                               //  User group, from connection
);

int
    amq_exchange_broker_unbind_queue (
amq_exchange_t * self,                  //  Reference to object
amq_queue_t * queue                     //  The queue to unbind
);

void
    amq_exchange_selftest (
void);

qbyte
    amq_exchange_count (
void);

int
    amq_exchange_inspect_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request           //  The original request
);

int
    amq_exchange_inspect (
amq_exchange_t * self,                  //  Reference to object
amq_content_basic_t * request           //  The original request
);

int
    amq_exchange_modify_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_exchange_modify (
amq_exchange_t * self,                  //  Reference to object
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_exchange_method_shim (
void * self_v,                          //  Object cast as a void *
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_exchange_method (
amq_exchange_t * self,                  //  Reference to object
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Argument fields
);

void
    amq_exchange_unlink_shim (
void * object_p                         //  Reference pointer cast as a void *
);

void
    amq_exchange_terminate (
void);

void
    amq_exchange_remove_from_all_containers (
amq_exchange_t * self                   //  The itemThe item
);

#define amq_exchange_show(item,opcode,trace_file)  amq_exchange_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_exchange_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_exchange_destroy(self)      amq_exchange_destroy_ (self, __FILE__, __LINE__)
int
    amq_exchange_destroy_ (
amq_exchange_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_exchange_unlink(self)       amq_exchange_unlink_ (self, __FILE__, __LINE__)
void
    amq_exchange_unlink_ (
amq_exchange_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_exchange_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_exchange_free(self)         amq_exchange_free_ (self, __FILE__, __LINE__)
void
    amq_exchange_free_ (
amq_exchange_t * self,                  //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_exchange_link(self)         amq_exchange_link_ (self, __FILE__, __LINE__)
amq_exchange_t *
    amq_exchange_link_ (
amq_exchange_t * self,                  //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_exchange_new_in_scope(self_p,_scope,type,name,internal,auto_federate)  amq_exchange_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, type, name, internal, auto_federate)
void
    amq_exchange_new_in_scope_ (
amq_exchange_t * * self_p,              //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
int type,                               //  Exchange type
char * name,                            //  Exchange name
Bool internal,                          //  Internal exchange?
Bool auto_federate                      //  Auto-federate exchange?
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_EXCHANGE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_EXCHANGE_INLINE)
#   define INCLUDE_AMQ_EXCHANGE_INLINE
#   define INCLUDE_AMQ_EXCHANGE_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_queue_bindings_list_table.h"
#   include "amq_exchange_table.h"
#   include "amq_exchange_list.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_exchange_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_EXCHANGE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_EXCHANGE_ROOT
#   endif
# endif
#endif
