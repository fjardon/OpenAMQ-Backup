/*---------------------------------------------------------------------------
    amq_consumer.h - amq_consumer component

This class implements a polymorphic consumer. This is an object that
ties the channel to the queue, and envelopes class-specific consumers
for Basic, File, and Stream content classes.
    Generated from amq_consumer.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_CONSUMER_SAFE
#   define INCLUDE_AMQ_CONSUMER_SAFE
#   define INCLUDE_AMQ_CONSUMER_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CONSUMER_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_consumer_t amq_consumer_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
#    define AMQ_CONSUMER_HISTORY_LENGTH 32
#endif

#define AMQ_CONSUMER_ALIVE              0xFABB
#define AMQ_CONSUMER_DEAD               0xDEAD

#define AMQ_CONSUMER_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_consumer\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_CONSUMER_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_consumer at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CONSUMER_ALIVE, self->object_tag);\
        amq_consumer_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "amq_consumer_table.h"
#   include "amq_consumer_by_queue.h"
#   include "amq_consumer_by_channel.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSUMER_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSUMER_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CONSUMER_UNSAFE
#   define INCLUDE_AMQ_CONSUMER_UNSAFE
#   define INCLUDE_AMQ_CONSUMER_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_consumer_table.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_consumer_animating;

//  Structure of the amq_consumer object

struct _amq_consumer_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_CONSUMER_HISTORY_LENGTH];
    int
        history_line  [AMQ_CONSUMER_HISTORY_LENGTH];
    char
        *history_type [AMQ_CONSUMER_HISTORY_LENGTH];
    int
        history_links [AMQ_CONSUMER_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
amq_consumer_table_t
    *table_head;                    //  Hash table container
amq_consumer_t
    *table_next;                    //  Next item in the hash slot
qbyte
    table_index;                    //  Index of item in table
icl_shortstr_t
    key;                            //  Item's original key
volatile amq_consumer_by_queue_t *by_queue_head;
volatile amq_consumer_t *by_queue_prev;
volatile amq_consumer_t *by_queue_next;
volatile amq_consumer_by_channel_t *by_channel_head;
volatile amq_consumer_t *by_channel_prev;
volatile amq_consumer_t *by_channel_next;
amq_server_channel_t
    *channel;                       //  Parent channel
amq_queue_t
    *queue;                         //  Parent queue
amq_connection_queue_t
    *mgt_connection_queue;          //  Connection-queue management object
amq_queue_connection_t
    *mgt_queue_connection;          //  Queue-connection management object
icl_shortstr_t
    tag;                            //  Consumer tag
amq_consumer_basic_t
    *consumer_basic;                //  Basic consumer
Bool
    no_local,                       //  Don't want own messages
    no_ack,                         //  Auto acknowledge messages
    exclusive;                      //  Exclusive access?
volatile Bool
    paused;                         //  Is consumer paused (flow off) ?
amq_content_basic_t
    *pending_content;               //  Up to one unack'd content
};

#   ifdef __cplusplus
}
#   endif
#   include "amq_consumer_by_queue.h"
#   include "amq_consumer_by_channel.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_consumer_new(connection,channel,queue,method)  amq_consumer_new_ (__FILE__, __LINE__, connection, channel, queue, method)
amq_consumer_t *
    amq_consumer_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_server_connection_t * connection,   //  Parent connection
amq_server_channel_t * channel,         //  Channel for reply
amq_queue_t * queue,                    //  Parent queue
amq_server_method_t * method            //  Consume method
);

int
    amq_consumer_content_hold (
amq_consumer_t * self,                  //  Reference to object
amq_content_basic_t * content           //  Not documented
);

int
    amq_consumer_content_release (
amq_consumer_t * self                   //  Reference to object
);

void
    amq_consumer_selftest (
void);

qbyte
    amq_consumer_count (
void);

void
    amq_consumer_remove_from_all_containers (
amq_consumer_t * self                   //  The itemThe itemThe item
);

#define amq_consumer_show(item,opcode,trace_file)  amq_consumer_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_consumer_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    amq_consumer_terminate (
void);

#define amq_consumer_destroy(self)      amq_consumer_destroy_ (self, __FILE__, __LINE__)
void
    amq_consumer_destroy_ (
amq_consumer_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define amq_consumer_link(self)         amq_consumer_link_ (self, __FILE__, __LINE__)
amq_consumer_t *
    amq_consumer_link_ (
amq_consumer_t * self,                  //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_consumer_unlink(self)       amq_consumer_unlink_ (self, __FILE__, __LINE__)
void
    amq_consumer_unlink_ (
amq_consumer_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_consumer_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_consumer_new_in_scope(self_p,_scope,connection,channel,queue,method)  amq_consumer_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, connection, channel, queue, method)
void
    amq_consumer_new_in_scope_ (
amq_consumer_t * * self_p,              //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_server_connection_t * connection,   //  Parent connection
amq_server_channel_t * channel,         //  Channel for reply
amq_queue_t * queue,                    //  Parent queue
amq_server_method_t * method            //  Consume method
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSUMER_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSUMER_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CONSUMER_INLINE)
#   define INCLUDE_AMQ_CONSUMER_INLINE
#   define INCLUDE_AMQ_CONSUMER_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_consumer_table.h"
#   include "amq_consumer_by_queue.h"
#   include "amq_consumer_by_channel.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSUMER_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSUMER_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CONSUMER_ROOT
#   endif
# endif
#endif
