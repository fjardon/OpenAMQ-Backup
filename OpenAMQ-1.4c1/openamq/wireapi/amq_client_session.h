/*---------------------------------------------------------------------------
    amq_client_session.h - amq_client_session component

This class provides the session serialisation API.
    Generated from amq_client_session.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_AMQ_CLIENT_SESSION_SAFE
#   define INCLUDE_AMQ_CLIENT_SESSION_SAFE
#   define INCLUDE_AMQ_CLIENT_SESSION_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CLIENT_SESSION_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_client_session_t amq_client_session_t;

#define AMQ_CLIENT_SESSION_ALIVE        0xFABB
#define AMQ_CLIENT_SESSION_DEAD         0xDEAD

#define AMQ_CLIENT_SESSION_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_client_session\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_CLIENT_SESSION_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_client_session at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CLIENT_SESSION_ALIVE, self->object_tag);\
        amq_client_session_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_client_classes.h"
#   include "amq_constants.h"
#   include "amq_client_connection.h"
#   include "amq_content_basic_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CLIENT_SESSION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CLIENT_SESSION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CLIENT_SESSION_UNSAFE
#   define INCLUDE_AMQ_CLIENT_SESSION_UNSAFE
#   define INCLUDE_AMQ_CLIENT_SESSION_ACTIVE

#   include "amq_client_classes.h"
#   include "amq_constants.h"
#   include "amq_client_connection.h"
#   include "amq_content_basic_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_client_session_animating;

//  Structure of the amq_client_session object

struct _amq_client_session_t {
dbyte
    object_tag;                     //  Object validity marker
amq_client_connection_t
    *connection;                    //  Parent connection object
smt_method_queue_t
    *method_queue;                  //  Replies from protocol agent
dbyte
    channel_nbr;                    //  Session channel number
Bool
    alive;                          //  Is the session alive?
apr_time_t
    timestamp;                      //  Time session was opened
volatile qbyte
    flow_stopped;                   //  Is flow of messages from server stopped?
char
    *error_text;                    //  Last error cause
char
    *chrono_block;                  //  Accumulated chrono deltas
ipr_hash_table_t
    *dp_sinks,                      //  DP sink threads
    *dp_feeds;                      //  DP feed threads
icl_shortstr_t
    lease;                          //  Lease for connection
icl_longstr_t *
    channel_id;                     //  unique id of the channel
Bool
    active;                         //  start/stop content frames
dbyte
    reply_code;                     //  reply code from server
icl_shortstr_t
    reply_text;                     //  localised reply text
dbyte
    class_id;                       //  failing method class
dbyte
    method_id;                      //  failing method ID
icl_shortstr_t
    consumer_tag;                   //  consumer tag
icl_shortstr_t
    exchange;                       //  exchange name
icl_shortstr_t
    routing_key;                    //  Message routing key
int64_t
    delivery_tag;                   //  server-assigned delivery tag
Bool
    redelivered;                    //  message is being redelivered
qbyte
    message_count;                  //  number of messages pending
icl_shortstr_t
    sender_id;                      //  Sender id
icl_shortstr_t
    queue;                          //  queue name
qbyte
    consumer_count;                 //  number of consumers
amq_sequence_table_t
    *sequences;                     //  Timestamp per connection id
//  Handling for basic messages
amq_content_basic_list_t
    *arrived_basic_list;            //  Basic messages
amq_content_basic_list_t
    *returned_basic_list;           //  Returned basic messages
amq_content_basic_list_t
    *chrono_list;                   //  Pending chrono messages
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_client_session_new(connection)  amq_client_session_new_ (__FILE__, __LINE__, connection)
amq_client_session_t *
    amq_client_session_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_client_connection_t * connection    //  Not documented
);

int
    amq_client_session_wait (
amq_client_session_t * self,            //  Reference to object
int timeout                             //  Timeout, in milliseconds
);

int
    amq_client_session_channel_flow (
amq_client_session_t * self,            //  Reference to object
Bool active                             //  start/stop content frames
);

int
    amq_client_session_channel_flow_ok (
amq_client_session_t * self,            //  Reference to object
Bool active                             //  current flow setting
);

int
    amq_client_session_exchange_declare (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * exchange,                        //  exchange name
char * type,                            //  exchange type
Bool passive,                           //  do not create exchange
Bool durable,                           //  request a durable exchange
Bool auto_delete,                       //  auto-delete when unused
Bool internal,                          //  create internal exchange
icl_longstr_t * arguments               //  arguments for declaration
);

int
    amq_client_session_exchange_declare_nowait (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * exchange,                        //  exchange name
char * type,                            //  exchange type
Bool passive,                           //  do not create exchange
Bool durable,                           //  request a durable exchange
Bool auto_delete,                       //  auto-delete when unused
Bool internal,                          //  create internal exchange
icl_longstr_t * arguments               //  arguments for declaration
);

int
    amq_client_session_exchange_delete (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * exchange,                        //  exchange name
Bool if_unused                          //  delete only if unused
);

int
    amq_client_session_exchange_delete_nowait (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * exchange,                        //  exchange name
Bool if_unused                          //  delete only if unused
);

int
    amq_client_session_queue_declare (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool passive,                           //  do not create queue
Bool durable,                           //  request a durable queue
Bool exclusive,                         //  request an exclusive queue
Bool auto_delete,                       //  auto-delete queue when unused
icl_longstr_t * arguments               //  arguments for declaration
);

int
    amq_client_session_queue_declare_nowait (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool passive,                           //  do not create queue
Bool durable,                           //  request a durable queue
Bool exclusive,                         //  request an exclusive queue
Bool auto_delete,                       //  auto-delete queue when unused
icl_longstr_t * arguments               //  arguments for declaration
);

int
    amq_client_session_queue_bind (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * exchange,                        //  exchange name
char * routing_key,                     //  message routing key
icl_longstr_t * arguments               //  arguments for binding
);

int
    amq_client_session_queue_bind_nowait (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * exchange,                        //  exchange name
char * routing_key,                     //  message routing key
icl_longstr_t * arguments               //  arguments for binding
);

int
    amq_client_session_queue_purge (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue                            //  queue name
);

int
    amq_client_session_queue_purge_nowait (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue                            //  queue name
);

int
    amq_client_session_queue_delete (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool if_unused,                         //  delete only if unused
Bool if_empty                           //  delete only if empty
);

int
    amq_client_session_queue_delete_nowait (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool if_unused,                         //  delete only if unused
Bool if_empty                           //  delete only if empty
);

int
    amq_client_session_queue_unbind (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * exchange,                        //  exchange name
char * routing_key,                     //  message routing key
icl_longstr_t * arguments               //  arguments for binding
);

int
    amq_client_session_queue_unbind_nowait (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * exchange,                        //  exchange name
char * routing_key,                     //  message routing key
icl_longstr_t * arguments               //  arguments for binding
);

int
    amq_client_session_basic_qos (
amq_client_session_t * self,            //  Reference to object
qbyte prefetch_size,                    //  prefetch window in octets
int prefetch_count,                     //  prefetch window in messages
Bool global                             //  apply to entire connection
);

int
    amq_client_session_basic_consume (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * consumer_tag,                    //  consumer tag
Bool no_local,                          //  do not deliver own messages
Bool no_ack,                            //  no acknowledgement needed
Bool exclusive,                         //  request exclusive access
icl_longstr_t * arguments               //  arguments for consume
);

int
    amq_client_session_basic_consume_nowait (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * consumer_tag,                    //  consumer tag
Bool no_local,                          //  do not deliver own messages
Bool no_ack,                            //  no acknowledgement needed
Bool exclusive,                         //  request exclusive access
icl_longstr_t * arguments               //  arguments for consume
);

int
    amq_client_session_basic_cancel (
amq_client_session_t * self,            //  Reference to object
char * consumer_tag                     //  consumer tag
);

int
    amq_client_session_basic_cancel_nowait (
amq_client_session_t * self,            //  Reference to object
char * consumer_tag                     //  consumer tag
);

int
    amq_client_session_basic_publish (
amq_client_session_t * self,            //  Reference to object
amq_content_basic_t * content,          //  Message content
int ticket,                             //  access ticket granted by server
char * exchange,                        //  exchange name
char * routing_key,                     //  Message routing key
Bool mandatory,                         //  indicate mandatory routing
Bool immediate                          //  request immediate delivery
);

int
    amq_client_session_basic_get (
amq_client_session_t * self,            //  Reference to object
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool no_ack                             //  no acknowledgement needed
);

int
    amq_client_session_basic_ack (
amq_client_session_t * self,            //  Reference to object
int64_t delivery_tag,                   //  server-assigned delivery tag
Bool multiple                           //  acknowledge multiple messages
);

int
    amq_client_session_basic_reject (
amq_client_session_t * self,            //  Reference to object
int64_t delivery_tag,                   //  server-assigned delivery tag
Bool requeue                            //  requeue the message
);

int
    amq_client_session_restms_pipe_create (
amq_client_session_t * self,            //  Reference to object
char * pipe_type,                       //  pipe type
char * pipe_name                        //  Name of pipe
);

int
    amq_client_session_restms_pipe_delete (
amq_client_session_t * self,            //  Reference to object
char * pipe_name                        //  pipe name
);

int
    amq_client_session_restms_feed_create (
amq_client_session_t * self,            //  Reference to object
char * feed_type,                       //  Feed type
char * feed_name                        //  Name of feed
);

int
    amq_client_session_restms_feed_delete (
amq_client_session_t * self,            //  Reference to object
char * feed_name                        //  feed name
);

int
    amq_client_session_restms_join_create (
amq_client_session_t * self,            //  Reference to object
char * pipe_name,                       //  Name of pipe
char * feed_name,                       //  Name of feed
char * address                          //  Join address
);

int
    amq_client_session_restms_join_delete (
amq_client_session_t * self,            //  Reference to object
char * pipe_name,                       //  Name of pipe
char * feed_name,                       //  Name of feed
char * address                          //  Join address
);

int
    amq_client_session_push_arrived (
amq_client_session_t * self,            //  Reference to object
amq_content_basic_t * content,          //  Message content
char * exchange,                        //  Value to stamp into content
char * routing_key,                     //  Value to stamp into content
char * consumer_tag,                    //  Value to stamp into content
int64_t delivery_tag                    //  Value to stamp into content
);

int
    amq_client_session_push_returned (
amq_client_session_t * self,            //  Reference to object
amq_content_basic_t * content,          //  Message content
char * exchange,                        //  Value to stamp into content
char * routing_key,                     //  Value to stamp into content
char * consumer_tag                     //  Value to stamp into content
);

int
    amq_client_session_get_basic_arrived_count (
amq_client_session_t * self             //  Reference to object
);

amq_content_basic_t *
    amq_client_session_basic_arrived (
amq_client_session_t * self             //  Session object
);

int
    amq_client_session_get_basic_returned_count (
amq_client_session_t * self             //  Reference to object
);

amq_content_basic_t *
    amq_client_session_basic_returned (
amq_client_session_t * self             //  Session object
);

Bool
    amq_client_session_get_alive (
amq_client_session_t * self             //  Object reference
);

char *
    amq_client_session_get_error_text (
amq_client_session_t * self             //  Object reference
);

char *
    amq_client_session_get_lease (
amq_client_session_t * self             //  Object reference
);

icl_longstr_t *
    amq_client_session_get_channel_id (
amq_client_session_t * self             //  Object reference
);

Bool
    amq_client_session_get_active (
amq_client_session_t * self             //  Object reference
);

int
    amq_client_session_get_reply_code (
amq_client_session_t * self             //  Object reference
);

char *
    amq_client_session_get_reply_text (
amq_client_session_t * self             //  Object reference
);

int
    amq_client_session_get_class_id (
amq_client_session_t * self             //  Object reference
);

int
    amq_client_session_get_method_id (
amq_client_session_t * self             //  Object reference
);

char *
    amq_client_session_get_consumer_tag (
amq_client_session_t * self             //  Object reference
);

char *
    amq_client_session_get_exchange (
amq_client_session_t * self             //  Object reference
);

char *
    amq_client_session_get_routing_key (
amq_client_session_t * self             //  Object reference
);

int64_t
    amq_client_session_get_delivery_tag (
amq_client_session_t * self             //  Object reference
);

Bool
    amq_client_session_get_redelivered (
amq_client_session_t * self             //  Object reference
);

qbyte
    amq_client_session_get_message_count (
amq_client_session_t * self             //  Object reference
);

char *
    amq_client_session_get_sender_id (
amq_client_session_t * self             //  Object reference
);

char *
    amq_client_session_get_queue (
amq_client_session_t * self             //  Object reference
);

qbyte
    amq_client_session_get_consumer_count (
amq_client_session_t * self             //  Object reference
);

smt_thread_t *
    amq_client_session_dp_new (
amq_client_session_t * self,            //  Session object
char * name,                            //  Resource name
int type                                //  Resource type
);

smt_thread_t *
    amq_client_session_dp_lookup (
amq_client_session_t * self,            //  Session object
char * name,                            //  Resource name
int type                                //  Resource type
);

int
    amq_client_session_dp_destroy (
amq_client_session_t * self,            //  Reference to object
char * name,                            //  Resource name
int type                                //  Resource type
);

void
    amq_client_session_selftest (
void);

#define amq_client_session_show(item,opcode,trace_file)  amq_client_session_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_client_session_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_client_session_destroy(self)  amq_client_session_destroy_ (self, __FILE__, __LINE__)
void
    amq_client_session_destroy_ (
amq_client_session_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_client_session_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_client_session_new_in_scope(self_p,_scope,connection)  amq_client_session_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, connection)
void
    amq_client_session_new_in_scope_ (
amq_client_session_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_client_connection_t * connection    //  Not documented
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CLIENT_SESSION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CLIENT_SESSION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CLIENT_SESSION_INLINE)
#   define INCLUDE_AMQ_CLIENT_SESSION_INLINE
#   define INCLUDE_AMQ_CLIENT_SESSION_ACTIVE

#   include "amq_client_classes.h"
#   include "amq_constants.h"
#   include "amq_client_connection.h"
#   include "amq_content_basic_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CLIENT_SESSION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CLIENT_SESSION_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CLIENT_SESSION_ROOT
#   endif
# endif
#endif
