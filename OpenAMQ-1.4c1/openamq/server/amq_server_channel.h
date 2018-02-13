/*---------------------------------------------------------------------------
    amq_server_channel.h - amq_server_channel component

This class implements the AMQ server channel class.  The channel holds
a set of consumers managed both as a list and as a lookup table.  The
maximum number of consumers per channel is set at compile time.

Channel flow control: each channel gets a credit window when it gets a
consumer.  This window defines the maximum size of its flow queue, the
number of contents it has received from a queue but not yet handed to
SMT.  When the channel receives a content from a queue, it spends a
credit.  When it passes a content to SMT it earns a credit.  Queues
check the credit to decide whether or not to use the channel's consumers.
    Generated from amq_server_channel.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_SERVER_CHANNEL_SAFE
#   define INCLUDE_AMQ_SERVER_CHANNEL_SAFE
#   define INCLUDE_AMQ_SERVER_CHANNEL_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_SERVER_CHANNEL_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_server_channel_t amq_server_channel_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
#    define AMQ_SERVER_CHANNEL_HISTORY_LENGTH 32
#endif

#define AMQ_SERVER_CHANNEL_ALIVE        0xFABB
#define AMQ_SERVER_CHANNEL_DEAD         0xDEAD

#define AMQ_SERVER_CHANNEL_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_server_channel\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_SERVER_CHANNEL_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_server_channel at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_SERVER_CHANNEL_ALIVE, self->object_tag);\
        amq_server_channel_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_channel_table.h"
#   include "asl.h"
#   include "amq_server_method.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_server_channel_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CHANNEL_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CHANNEL_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_SERVER_CHANNEL_UNSAFE
#   define INCLUDE_AMQ_SERVER_CHANNEL_UNSAFE
#   define INCLUDE_AMQ_SERVER_CHANNEL_ACTIVE

#   include "amq_server_channel_table.h"
#   include "asl.h"
#   include "amq_server_method.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_server_channel_agent.h"
//  Global variables

extern Bool
    amq_server_channel_animating;

//  Structure of the amq_server_channel object

struct _amq_server_channel_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_SERVER_CHANNEL_HISTORY_LENGTH];
    int
        history_line  [AMQ_SERVER_CHANNEL_HISTORY_LENGTH];
    char
        *history_type [AMQ_SERVER_CHANNEL_HISTORY_LENGTH];
    int
        history_links [AMQ_SERVER_CHANNEL_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
amq_server_channel_table_t
    *table_head;                    //  Hash table container
amq_server_channel_t
    *table_next;                    //  Next item in the hash slot
qbyte
    table_index;                    //  Index of item in table
int
    key;                            //  Item's original key
Bool
    active;                         //  If TRUE, channel is active
amq_server_connection_t
    *connection;                    //  Parent connection
dbyte
    number;                         //  Channel number
icl_shortstr_t
    id;                             //  Unique channel id (per broker)
volatile qbyte
    credit;                         //  Current channel credit
amq_connection_t
    *mgt_connection;                //  Connection management object
amq_consumer_by_channel_t
    *consumer_list;                 //  List of consumers for channel
icl_shortstr_t
    current_exchange,               //  Last exchange declared on channel
    current_queue;                  //  Last queue declared on channel
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_server_channel_new(table,connection,number)  amq_server_channel_new_ (__FILE__, __LINE__, table, connection, number)
amq_server_channel_t *
    amq_server_channel_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_server_channel_table_t * table,     //  Table to insert into
amq_server_connection_t * connection,   //  Parent connection
dbyte number                            //  Channel number
);

#define amq_server_channel_free(self)   amq_server_channel_free_ (self, __FILE__, __LINE__)
void
    amq_server_channel_free_ (
amq_server_channel_t * self,            //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

int
    amq_server_channel_flow (
amq_server_channel_t * self,            //  Reference to object
Bool active                             //  Active consumer?
);

int
    amq_server_channel_consume (
amq_server_channel_t * self,            //  Reference to object
amq_queue_t * queue,                    //  Queue to consume from
amq_server_method_t * method            //  Consume method
);

int
    amq_server_channel_ack (
amq_server_channel_t * self,            //  Reference to object
int64_t delivery_tag,                   //  Delivery tag to ack
Bool multiple                           //  Ack multiple messages?
);

int
    amq_server_channel_earn (
amq_server_channel_t * self             //  Reference to object
);

int
    amq_server_channel_cancel (
amq_server_channel_t * self,            //  Reference to object
char * tag,                             //  Consumer tag
Bool sync,                              //  Are we talking to a client?
Bool nowait                             //  No reply method wanted
);

void
    amq_server_channel_selftest (
void);

int
    amq_server_channel_spend (
amq_server_channel_t * self             //  Reference to object
);

int
    amq_server_channel_error (
amq_server_channel_t * self,            //  Reference to object
dbyte reply_code,                       //  Error code
char * reply_text,                      //  Error text
dbyte faulting_class_id,                //  Faulting class id
dbyte faulting_method_id                //  Faulting method id
);

void
    amq_server_channel_remove_from_all_containers (
amq_server_channel_t * self             //  The item
);

#define amq_server_channel_show(item,opcode,trace_file)  amq_server_channel_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_server_channel_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_server_channel_destroy(self)  amq_server_channel_destroy_ (self, __FILE__, __LINE__)
int
    amq_server_channel_destroy_ (
amq_server_channel_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_server_channel_unlink(self)  amq_server_channel_unlink_ (self, __FILE__, __LINE__)
void
    amq_server_channel_unlink_ (
amq_server_channel_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_server_channel_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

void
    amq_server_channel_terminate (
void);

#define amq_server_channel_link(self)   amq_server_channel_link_ (self, __FILE__, __LINE__)
amq_server_channel_t *
    amq_server_channel_link_ (
amq_server_channel_t * self,            //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_server_channel_new_in_scope(self_p,_scope,table,connection,number)  amq_server_channel_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, table, connection, number)
void
    amq_server_channel_new_in_scope_ (
amq_server_channel_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_server_channel_table_t * table,     //  Table to insert into
amq_server_connection_t * connection,   //  Parent connection
dbyte number                            //  Channel number
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CHANNEL_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CHANNEL_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_SERVER_CHANNEL_INLINE)
#   define INCLUDE_AMQ_SERVER_CHANNEL_INLINE
#   define INCLUDE_AMQ_SERVER_CHANNEL_ACTIVE

#   include "amq_server_channel_table.h"
#   include "asl.h"
#   include "amq_server_method.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_server_channel_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CHANNEL_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CHANNEL_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_SERVER_CHANNEL_ROOT
#   endif
# endif
#endif
