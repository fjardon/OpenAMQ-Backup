/*---------------------------------------------------------------------------
    zyre_peer_method.h - zyre_peer_method component

This class holds a method.  All protocol methods are held in a single
union that can be processed as a single entity.
    Generated from zyre_peer_method.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_ZYRE_PEER_METHOD_SAFE
#   define INCLUDE_ZYRE_PEER_METHOD_SAFE
#   define INCLUDE_ZYRE_PEER_METHOD_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_PEER_METHOD_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _zyre_peer_method_t zyre_peer_method_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PEER_METHOD)
#    define ZYRE_PEER_METHOD_HISTORY_LENGTH 32
#endif

#define ZYRE_PEER_METHOD_ALIVE          0xFABB
#define ZYRE_PEER_METHOD_DEAD           0xDEAD

#define ZYRE_PEER_METHOD_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL zyre_peer_method\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != ZYRE_PEER_METHOD_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "zyre_peer_method at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ZYRE_PEER_METHOD_ALIVE, self->object_tag);\
        zyre_peer_method_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#define ZYRE_PEER_CONNECTION                10
#define ZYRE_PEER_CONNECTION_START          10
#define ZYRE_PEER_CONNECTION_START_OK       11
#define ZYRE_PEER_CONNECTION_SECURE         20
#define ZYRE_PEER_CONNECTION_SECURE_OK      21
#define ZYRE_PEER_CONNECTION_TUNE           30
#define ZYRE_PEER_CONNECTION_TUNE_OK        31
#define ZYRE_PEER_CONNECTION_OPEN           40
#define ZYRE_PEER_CONNECTION_OPEN_OK        41
#define ZYRE_PEER_CONNECTION_CLOSE          50
#define ZYRE_PEER_CONNECTION_CLOSE_OK       51

#define ZYRE_PEER_CHANNEL                   20
#define ZYRE_PEER_CHANNEL_OPEN              10
#define ZYRE_PEER_CHANNEL_OPEN_OK           11
#define ZYRE_PEER_CHANNEL_FLOW              20
#define ZYRE_PEER_CHANNEL_FLOW_OK           21
#define ZYRE_PEER_CHANNEL_CLOSE             40
#define ZYRE_PEER_CHANNEL_CLOSE_OK          41

#define ZYRE_PEER_EXCHANGE                  40
#define ZYRE_PEER_EXCHANGE_DECLARE          10
#define ZYRE_PEER_EXCHANGE_DECLARE_OK       11
#define ZYRE_PEER_EXCHANGE_DELETE           20
#define ZYRE_PEER_EXCHANGE_DELETE_OK        21

#define ZYRE_PEER_QUEUE                     50
#define ZYRE_PEER_QUEUE_DECLARE             10
#define ZYRE_PEER_QUEUE_DECLARE_OK          11
#define ZYRE_PEER_QUEUE_BIND                20
#define ZYRE_PEER_QUEUE_BIND_OK             21
#define ZYRE_PEER_QUEUE_PURGE               30
#define ZYRE_PEER_QUEUE_PURGE_OK            31
#define ZYRE_PEER_QUEUE_DELETE              40
#define ZYRE_PEER_QUEUE_DELETE_OK           41
#define ZYRE_PEER_QUEUE_UNBIND              50
#define ZYRE_PEER_QUEUE_UNBIND_OK           51

#define ZYRE_PEER_BASIC                     60
#define ZYRE_PEER_BASIC_QOS                 10
#define ZYRE_PEER_BASIC_QOS_OK              11
#define ZYRE_PEER_BASIC_CONSUME             20
#define ZYRE_PEER_BASIC_CONSUME_OK          21
#define ZYRE_PEER_BASIC_CANCEL              30
#define ZYRE_PEER_BASIC_CANCEL_OK           31
#define ZYRE_PEER_BASIC_PUBLISH             40
#define ZYRE_PEER_BASIC_RETURN              50
#define ZYRE_PEER_BASIC_DELIVER             60
#define ZYRE_PEER_BASIC_GET                 70
#define ZYRE_PEER_BASIC_GET_OK              71
#define ZYRE_PEER_BASIC_GET_EMPTY           72
#define ZYRE_PEER_BASIC_ACK                 80
#define ZYRE_PEER_BASIC_REJECT              90

#define ZYRE_PEER_DIRECT                    61500
#define ZYRE_PEER_DIRECT_PUT                10
#define ZYRE_PEER_DIRECT_PUT_OK             11
#define ZYRE_PEER_DIRECT_GET                20
#define ZYRE_PEER_DIRECT_GET_OK             21

#define ZYRE_PEER_RESTMS                    61501
#define ZYRE_PEER_RESTMS_PIPE_CREATE        10
#define ZYRE_PEER_RESTMS_PIPE_DELETE        20
#define ZYRE_PEER_RESTMS_FEED_CREATE        30
#define ZYRE_PEER_RESTMS_FEED_DELETE        40
#define ZYRE_PEER_RESTMS_JOIN_CREATE        50
#define ZYRE_PEER_RESTMS_JOIN_DELETE        60

typedef struct _zyre_peer_connection_start_t zyre_peer_connection_start_t;
typedef struct _zyre_peer_connection_start_ok_t zyre_peer_connection_start_ok_t;
typedef struct _zyre_peer_connection_secure_t zyre_peer_connection_secure_t;
typedef struct _zyre_peer_connection_secure_ok_t zyre_peer_connection_secure_ok_t;
typedef struct _zyre_peer_connection_tune_t zyre_peer_connection_tune_t;
typedef struct _zyre_peer_connection_tune_ok_t zyre_peer_connection_tune_ok_t;
typedef struct _zyre_peer_connection_open_t zyre_peer_connection_open_t;
typedef struct _zyre_peer_connection_open_ok_t zyre_peer_connection_open_ok_t;
typedef struct _zyre_peer_connection_close_t zyre_peer_connection_close_t;
typedef struct _zyre_peer_connection_close_ok_t zyre_peer_connection_close_ok_t;
typedef struct _zyre_peer_channel_open_t zyre_peer_channel_open_t;
typedef struct _zyre_peer_channel_open_ok_t zyre_peer_channel_open_ok_t;
typedef struct _zyre_peer_channel_flow_t zyre_peer_channel_flow_t;
typedef struct _zyre_peer_channel_flow_ok_t zyre_peer_channel_flow_ok_t;
typedef struct _zyre_peer_channel_close_t zyre_peer_channel_close_t;
typedef struct _zyre_peer_channel_close_ok_t zyre_peer_channel_close_ok_t;
typedef struct _zyre_peer_exchange_declare_t zyre_peer_exchange_declare_t;
typedef struct _zyre_peer_exchange_declare_ok_t zyre_peer_exchange_declare_ok_t;
typedef struct _zyre_peer_exchange_delete_t zyre_peer_exchange_delete_t;
typedef struct _zyre_peer_exchange_delete_ok_t zyre_peer_exchange_delete_ok_t;
typedef struct _zyre_peer_queue_declare_t zyre_peer_queue_declare_t;
typedef struct _zyre_peer_queue_declare_ok_t zyre_peer_queue_declare_ok_t;
typedef struct _zyre_peer_queue_bind_t zyre_peer_queue_bind_t;
typedef struct _zyre_peer_queue_bind_ok_t zyre_peer_queue_bind_ok_t;
typedef struct _zyre_peer_queue_purge_t zyre_peer_queue_purge_t;
typedef struct _zyre_peer_queue_purge_ok_t zyre_peer_queue_purge_ok_t;
typedef struct _zyre_peer_queue_delete_t zyre_peer_queue_delete_t;
typedef struct _zyre_peer_queue_delete_ok_t zyre_peer_queue_delete_ok_t;
typedef struct _zyre_peer_queue_unbind_t zyre_peer_queue_unbind_t;
typedef struct _zyre_peer_queue_unbind_ok_t zyre_peer_queue_unbind_ok_t;
typedef struct _zyre_peer_basic_qos_t zyre_peer_basic_qos_t;
typedef struct _zyre_peer_basic_qos_ok_t zyre_peer_basic_qos_ok_t;
typedef struct _zyre_peer_basic_consume_t zyre_peer_basic_consume_t;
typedef struct _zyre_peer_basic_consume_ok_t zyre_peer_basic_consume_ok_t;
typedef struct _zyre_peer_basic_cancel_t zyre_peer_basic_cancel_t;
typedef struct _zyre_peer_basic_cancel_ok_t zyre_peer_basic_cancel_ok_t;
typedef struct _zyre_peer_basic_publish_t zyre_peer_basic_publish_t;
typedef struct _zyre_peer_basic_return_t zyre_peer_basic_return_t;
typedef struct _zyre_peer_basic_deliver_t zyre_peer_basic_deliver_t;
typedef struct _zyre_peer_basic_get_t zyre_peer_basic_get_t;
typedef struct _zyre_peer_basic_get_ok_t zyre_peer_basic_get_ok_t;
typedef struct _zyre_peer_basic_get_empty_t zyre_peer_basic_get_empty_t;
typedef struct _zyre_peer_basic_ack_t zyre_peer_basic_ack_t;
typedef struct _zyre_peer_basic_reject_t zyre_peer_basic_reject_t;
typedef struct _zyre_peer_direct_put_t zyre_peer_direct_put_t;
typedef struct _zyre_peer_direct_put_ok_t zyre_peer_direct_put_ok_t;
typedef struct _zyre_peer_direct_get_t zyre_peer_direct_get_t;
typedef struct _zyre_peer_direct_get_ok_t zyre_peer_direct_get_ok_t;
typedef struct _zyre_peer_restms_pipe_create_t zyre_peer_restms_pipe_create_t;
typedef struct _zyre_peer_restms_pipe_delete_t zyre_peer_restms_pipe_delete_t;
typedef struct _zyre_peer_restms_feed_create_t zyre_peer_restms_feed_create_t;
typedef struct _zyre_peer_restms_feed_delete_t zyre_peer_restms_feed_delete_t;
typedef struct _zyre_peer_restms_join_create_t zyre_peer_restms_join_create_t;
typedef struct _zyre_peer_restms_join_delete_t zyre_peer_restms_join_delete_t;
#   ifdef __cplusplus
}
#   endif

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "amq_constants.h"
#   include "zyre_peer_agent.h"
#   include "amq_content_basic.h"
#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_PEER_METHOD_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PEER_METHOD_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_PEER_METHOD_UNSAFE
#   define INCLUDE_ZYRE_PEER_METHOD_UNSAFE
#   define INCLUDE_ZYRE_PEER_METHOD_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "amq_constants.h"
#   include "zyre_peer_agent.h"
#   include "amq_content_basic.h"
#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    zyre_peer_method_animating;
//  Start Connection Negotiation

struct _zyre_peer_connection_start_t {
    byte
        version_major;                  //  protocol major version
    byte
        version_minor;                  //  protocol major version
    icl_longstr_t *
        server_properties;              //  server properties
    icl_longstr_t *
        mechanisms;                     //  available security mechanisms
    icl_longstr_t *
        locales;                        //  available message locales
};

//  Select Security Mechanism And Locale

struct _zyre_peer_connection_start_ok_t {
    icl_longstr_t *
        client_properties;              //  client properties
    icl_shortstr_t
        mechanism;                      //  selected security mechanism
    icl_longstr_t *
        response;                       //  security response data
    icl_shortstr_t
        locale;                         //  selected message locale
};

//  Security Mechanism Challenge

struct _zyre_peer_connection_secure_t {
    icl_longstr_t *
        challenge;                      //  security challenge data
};

//  Security Mechanism Response

struct _zyre_peer_connection_secure_ok_t {
    icl_longstr_t *
        response;                       //  security response data
};

//  Propose Connection Tuning Parameters

struct _zyre_peer_connection_tune_t {
    dbyte
        channel_max;                    //  proposed maximum channels
    qbyte
        frame_max;                      //  proposed maximum frame size
    dbyte
        heartbeat;                      //  desired heartbeat delay
};

//  Negotiate Connection Tuning Parameters

struct _zyre_peer_connection_tune_ok_t {
    dbyte
        channel_max;                    //  negotiated maximum channels
    qbyte
        frame_max;                      //  negotiated maximum frame size
    dbyte
        heartbeat;                      //  desired heartbeat delay
};

//  Open Connection To Virtual Host

struct _zyre_peer_connection_open_t {
    icl_shortstr_t
        virtual_host;                   //  virtual host name
    icl_shortstr_t
        capabilities;                   //  required capabilities
    Bool
        insist;                         //  insist on connecting to server
};

//  Signal That The Connection Is Ready

struct _zyre_peer_connection_open_ok_t {
    icl_shortstr_t
        known_hosts;                    //  list of known hosts
};

//  Request A Connection Close

struct _zyre_peer_connection_close_t {
    dbyte
        reply_code;                     //  reply code from server
    icl_shortstr_t
        reply_text;                     //  localised reply text
    dbyte
        class_id;                       //  failing method class
    dbyte
        method_id;                      //  failing method ID
};

//  Confirm A Connection Close

struct _zyre_peer_connection_close_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Open A Channel For Use

struct _zyre_peer_channel_open_t {
    icl_shortstr_t
        out_of_band;                    //  out-of-band settings
};

//  Signal That The Channel Is Ready

struct _zyre_peer_channel_open_ok_t {
    icl_longstr_t *
        channel_id;                     //  unique id of the channel
};

//  Enable/Disable Flow From Peer

struct _zyre_peer_channel_flow_t {
    Bool
        active;                         //  start/stop content frames
};

//  Confirm A Flow Method

struct _zyre_peer_channel_flow_ok_t {
    Bool
        active;                         //  current flow setting
};

//  Request A Channel Close

struct _zyre_peer_channel_close_t {
    dbyte
        reply_code;                     //  reply code from server
    icl_shortstr_t
        reply_text;                     //  localised reply text
    dbyte
        class_id;                       //  failing method class
    dbyte
        method_id;                      //  failing method ID
};

//  Confirm A Channel Close

struct _zyre_peer_channel_close_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Declare Exchange, Create If Needed

struct _zyre_peer_exchange_declare_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        type;                           //  exchange type
    Bool
        passive;                        //  do not create exchange
    Bool
        durable;                        //  request a durable exchange
    Bool
        auto_delete;                    //  auto-delete when unused
    Bool
        internal;                       //  create internal exchange
    Bool
        nowait;                         //  do not send a reply method
    icl_longstr_t *
        arguments;                      //  arguments for declaration
};

//  Confirms An Exchange Declaration

struct _zyre_peer_exchange_declare_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Delete An Exchange

struct _zyre_peer_exchange_delete_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        exchange;                       //  exchange name
    Bool
        if_unused;                      //  delete only if unused
    Bool
        nowait;                         //  do not send a reply method
};

//  Confirm Deletion Of An Exchange

struct _zyre_peer_exchange_delete_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Declare Queue, Create If Needed

struct _zyre_peer_queue_declare_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        queue;                          //  queue name
    Bool
        passive;                        //  do not create queue
    Bool
        durable;                        //  request a durable queue
    Bool
        exclusive;                      //  request an exclusive queue
    Bool
        auto_delete;                    //  auto-delete queue when unused
    Bool
        nowait;                         //  do not send a reply method
    icl_longstr_t *
        arguments;                      //  arguments for declaration
};

//  Confirms A Queue Definition

struct _zyre_peer_queue_declare_ok_t {
    icl_shortstr_t
        queue;                          //  queue name
    qbyte
        message_count;                  //  number of messages in queue
    qbyte
        consumer_count;                 //  number of consumers
};

//  Bind Queue To An Exchange

struct _zyre_peer_queue_bind_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        queue;                          //  queue name
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        routing_key;                    //  message routing key
    Bool
        nowait;                         //  do not send a reply method
    icl_longstr_t *
        arguments;                      //  arguments for binding
};

//  Confirm Bind Successful

struct _zyre_peer_queue_bind_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Purge A Queue

struct _zyre_peer_queue_purge_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        queue;                          //  queue name
    Bool
        nowait;                         //  do not send a reply method
};

//  Confirms A Queue Purge

struct _zyre_peer_queue_purge_ok_t {
    qbyte
        message_count;                  //  number of messages purged
};

//  Delete A Queue

struct _zyre_peer_queue_delete_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        queue;                          //  queue name
    Bool
        if_unused;                      //  delete only if unused
    Bool
        if_empty;                       //  delete only if empty
    Bool
        nowait;                         //  do not send a reply method
};

//  Confirm Deletion Of A Queue

struct _zyre_peer_queue_delete_ok_t {
    qbyte
        message_count;                  //  number of messages purged
};

//  Unbind Queue From An Exchange

struct _zyre_peer_queue_unbind_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        queue;                          //  queue name
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        routing_key;                    //  message routing key
    Bool
        nowait;                         //  do not send a reply method
    icl_longstr_t *
        arguments;                      //  arguments for binding
};

//  Confirm Unbind Successful

struct _zyre_peer_queue_unbind_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Specify Quality Of Service

struct _zyre_peer_basic_qos_t {
    qbyte
        prefetch_size;                  //  prefetch window in octets
    dbyte
        prefetch_count;                 //  prefetch window in messages
    Bool
        global;                         //  apply to entire connection
};

//  Confirm The Requested Qos

struct _zyre_peer_basic_qos_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Start A Queue Consumer

struct _zyre_peer_basic_consume_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        queue;                          //  queue name
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
    Bool
        no_local;                       //  do not deliver own messages
    Bool
        no_ack;                         //  no acknowledgement needed
    Bool
        exclusive;                      //  request exclusive access
    Bool
        nowait;                         //  do not send a reply method
    icl_longstr_t *
        arguments;                      //  arguments for consume
};

//  Confirm A New Consumer

struct _zyre_peer_basic_consume_ok_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
};

//  End A Queue Consumer

struct _zyre_peer_basic_cancel_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
    Bool
        nowait;                         //  do not send a reply method
};

//  Confirm A Cancelled Consumer

struct _zyre_peer_basic_cancel_ok_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
};

//  Publish A Message

struct _zyre_peer_basic_publish_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        routing_key;                    //  Message routing key
    Bool
        mandatory;                      //  indicate mandatory routing
    Bool
        immediate;                      //  request immediate delivery
};

//  Return A Failed Message

struct _zyre_peer_basic_return_t {
    dbyte
        reply_code;                     //  reply code from server
    icl_shortstr_t
        reply_text;                     //  localised reply text
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        routing_key;                    //  Message routing key
};

//  Notify The Client Of A Consumer Message

struct _zyre_peer_basic_deliver_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
    int64_t
        delivery_tag;                   //  server-assigned delivery tag
    Bool
        redelivered;                    //  message is being redelivered
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        routing_key;                    //  Message routing key
};

//  Direct Access To A Queue

struct _zyre_peer_basic_get_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        queue;                          //  queue name
    Bool
        no_ack;                         //  no acknowledgement needed
};

//  Provide Client With A Message

struct _zyre_peer_basic_get_ok_t {
    int64_t
        delivery_tag;                   //  server-assigned delivery tag
    Bool
        redelivered;                    //  message is being redelivered
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        routing_key;                    //  Message routing key
    qbyte
        message_count;                  //  number of messages pending
};

//  Indicate No Messages Available

struct _zyre_peer_basic_get_empty_t {
    icl_shortstr_t
        sender_id;                      //  Sender id
};

//  Acknowledge One Or More Messages

struct _zyre_peer_basic_ack_t {
    int64_t
        delivery_tag;                   //  server-assigned delivery tag
    Bool
        multiple;                       //  acknowledge multiple messages
};

//  Reject An Incoming Message

struct _zyre_peer_basic_reject_t {
    int64_t
        delivery_tag;                   //  server-assigned delivery tag
    Bool
        requeue;                        //  requeue the message
};

//  Request A Connection To A Sink

struct _zyre_peer_direct_put_t {
    icl_shortstr_t
        sink;                           //  Sink name
};

//  Grant Access To The Sink

struct _zyre_peer_direct_put_ok_t {
    icl_shortstr_t
        lease;                          //  Lease for connection
};

//  Request A Connection To A Feed

struct _zyre_peer_direct_get_t {
    icl_shortstr_t
        feed;                           //  Feed name
};

//  Grant Access To The Feed

struct _zyre_peer_direct_get_ok_t {
    icl_shortstr_t
        lease;                          //  Lease for connection
};

//  Create A Pipe

struct _zyre_peer_restms_pipe_create_t {
    icl_shortstr_t
        pipe_type;                      //  pipe type
    icl_shortstr_t
        pipe_name;                      //  Name of pipe
};

//  Delete A Pipe

struct _zyre_peer_restms_pipe_delete_t {
    icl_shortstr_t
        pipe_name;                      //  pipe name
};

//  Create A Feed

struct _zyre_peer_restms_feed_create_t {
    icl_shortstr_t
        feed_type;                      //  Feed type
    icl_shortstr_t
        feed_name;                      //  Name of feed
};

//  Delete A Feed

struct _zyre_peer_restms_feed_delete_t {
    icl_shortstr_t
        feed_name;                      //  feed name
};

//  Create A Join

struct _zyre_peer_restms_join_create_t {
    icl_shortstr_t
        pipe_name;                      //  Name of pipe
    icl_shortstr_t
        feed_name;                      //  Name of feed
    icl_shortstr_t
        address;                        //  Join address
};

//  Delete A Join

struct _zyre_peer_restms_join_delete_t {
    icl_shortstr_t
        pipe_name;                      //  Name of pipe
    icl_shortstr_t
        feed_name;                      //  Name of feed
    icl_shortstr_t
        address;                        //  Join address
};

//  Structure of the zyre_peer_method object

struct _zyre_peer_method_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PEER_METHOD)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [ZYRE_PEER_METHOD_HISTORY_LENGTH];
    int
        history_line  [ZYRE_PEER_METHOD_HISTORY_LENGTH];
    char
        *history_type [ZYRE_PEER_METHOD_HISTORY_LENGTH];
    int
        history_links [ZYRE_PEER_METHOD_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
dbyte
    class_id,                       //  ID of current class
    method_id;                      //  ID of current method
void
    *content;                       //  Content, if any
char
    *name;                          //  Name, for tracing
Bool
    sync;                           //  Method is synchronous?

//  Used internally by servers processing the content
qbyte
    sequence;                       //  Method sequence counter

union {
    zyre_peer_connection_start_t
        connection_start;
    zyre_peer_connection_start_ok_t
        connection_start_ok;
    zyre_peer_connection_secure_t
        connection_secure;
    zyre_peer_connection_secure_ok_t
        connection_secure_ok;
    zyre_peer_connection_tune_t
        connection_tune;
    zyre_peer_connection_tune_ok_t
        connection_tune_ok;
    zyre_peer_connection_open_t
        connection_open;
    zyre_peer_connection_open_ok_t
        connection_open_ok;
    zyre_peer_connection_close_t
        connection_close;
    zyre_peer_connection_close_ok_t
        connection_close_ok;
    zyre_peer_channel_open_t
        channel_open;
    zyre_peer_channel_open_ok_t
        channel_open_ok;
    zyre_peer_channel_flow_t
        channel_flow;
    zyre_peer_channel_flow_ok_t
        channel_flow_ok;
    zyre_peer_channel_close_t
        channel_close;
    zyre_peer_channel_close_ok_t
        channel_close_ok;
    zyre_peer_exchange_declare_t
        exchange_declare;
    zyre_peer_exchange_declare_ok_t
        exchange_declare_ok;
    zyre_peer_exchange_delete_t
        exchange_delete;
    zyre_peer_exchange_delete_ok_t
        exchange_delete_ok;
    zyre_peer_queue_declare_t
        queue_declare;
    zyre_peer_queue_declare_ok_t
        queue_declare_ok;
    zyre_peer_queue_bind_t
        queue_bind;
    zyre_peer_queue_bind_ok_t
        queue_bind_ok;
    zyre_peer_queue_purge_t
        queue_purge;
    zyre_peer_queue_purge_ok_t
        queue_purge_ok;
    zyre_peer_queue_delete_t
        queue_delete;
    zyre_peer_queue_delete_ok_t
        queue_delete_ok;
    zyre_peer_queue_unbind_t
        queue_unbind;
    zyre_peer_queue_unbind_ok_t
        queue_unbind_ok;
    zyre_peer_basic_qos_t
        basic_qos;
    zyre_peer_basic_qos_ok_t
        basic_qos_ok;
    zyre_peer_basic_consume_t
        basic_consume;
    zyre_peer_basic_consume_ok_t
        basic_consume_ok;
    zyre_peer_basic_cancel_t
        basic_cancel;
    zyre_peer_basic_cancel_ok_t
        basic_cancel_ok;
    zyre_peer_basic_publish_t
        basic_publish;
    zyre_peer_basic_return_t
        basic_return;
    zyre_peer_basic_deliver_t
        basic_deliver;
    zyre_peer_basic_get_t
        basic_get;
    zyre_peer_basic_get_ok_t
        basic_get_ok;
    zyre_peer_basic_get_empty_t
        basic_get_empty;
    zyre_peer_basic_ack_t
        basic_ack;
    zyre_peer_basic_reject_t
        basic_reject;
    zyre_peer_direct_put_t
        direct_put;
    zyre_peer_direct_put_ok_t
        direct_put_ok;
    zyre_peer_direct_get_t
        direct_get;
    zyre_peer_direct_get_ok_t
        direct_get_ok;
    zyre_peer_restms_pipe_create_t
        restms_pipe_create;
    zyre_peer_restms_pipe_delete_t
        restms_pipe_delete;
    zyre_peer_restms_feed_create_t
        restms_feed_create;
    zyre_peer_restms_feed_delete_t
        restms_feed_delete;
    zyre_peer_restms_join_create_t
        restms_join_create;
    zyre_peer_restms_join_delete_t
        restms_join_delete;
} payload;
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define zyre_peer_method_new()          zyre_peer_method_new_ (__FILE__, __LINE__)
zyre_peer_method_t *
    zyre_peer_method_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

zyre_peer_method_t *
    zyre_peer_method_new_connection_start_ok (
icl_longstr_t * client_properties,      //  client properties
char * mechanism,                       //  selected security mechanism
icl_longstr_t * response,               //  security response data
char * locale                           //  selected message locale
);

zyre_peer_method_t *
    zyre_peer_method_new_connection_secure_ok (
icl_longstr_t * response                //  security response data
);

zyre_peer_method_t *
    zyre_peer_method_new_connection_tune_ok (
int channel_max,                        //  negotiated maximum channels
qbyte frame_max,                        //  negotiated maximum frame size
int heartbeat                           //  desired heartbeat delay
);

zyre_peer_method_t *
    zyre_peer_method_new_connection_open (
char * virtual_host,                    //  virtual host name
char * capabilities,                    //  required capabilities
Bool insist                             //  insist on connecting to server
);

zyre_peer_method_t *
    zyre_peer_method_new_connection_close (
int reply_code,                         //  reply code from server
char * reply_text,                      //  localised reply text
int class_id,                           //  failing method class
int method_id                           //  failing method ID
);

zyre_peer_method_t *
    zyre_peer_method_new_connection_close_ok (
void);

zyre_peer_method_t *
    zyre_peer_method_new_channel_open (
char * out_of_band                      //  out-of-band settings
);

zyre_peer_method_t *
    zyre_peer_method_new_channel_flow (
Bool active                             //  start/stop content frames
);

zyre_peer_method_t *
    zyre_peer_method_new_channel_flow_ok (
Bool active                             //  current flow setting
);

zyre_peer_method_t *
    zyre_peer_method_new_channel_close (
int reply_code,                         //  reply code from server
char * reply_text,                      //  localised reply text
int class_id,                           //  failing method class
int method_id                           //  failing method ID
);

zyre_peer_method_t *
    zyre_peer_method_new_channel_close_ok (
void);

zyre_peer_method_t *
    zyre_peer_method_new_exchange_declare (
int ticket,                             //  access ticket granted by server
char * exchange,                        //  exchange name
char * type,                            //  exchange type
Bool passive,                           //  do not create exchange
Bool durable,                           //  request a durable exchange
Bool auto_delete,                       //  auto-delete when unused
Bool internal,                          //  create internal exchange
Bool nowait,                            //  do not send a reply method
icl_longstr_t * arguments               //  arguments for declaration
);

zyre_peer_method_t *
    zyre_peer_method_new_exchange_delete (
int ticket,                             //  access ticket granted by server
char * exchange,                        //  exchange name
Bool if_unused,                         //  delete only if unused
Bool nowait                             //  do not send a reply method
);

zyre_peer_method_t *
    zyre_peer_method_new_queue_declare (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool passive,                           //  do not create queue
Bool durable,                           //  request a durable queue
Bool exclusive,                         //  request an exclusive queue
Bool auto_delete,                       //  auto-delete queue when unused
Bool nowait,                            //  do not send a reply method
icl_longstr_t * arguments               //  arguments for declaration
);

zyre_peer_method_t *
    zyre_peer_method_new_queue_bind (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * exchange,                        //  exchange name
char * routing_key,                     //  message routing key
Bool nowait,                            //  do not send a reply method
icl_longstr_t * arguments               //  arguments for binding
);

zyre_peer_method_t *
    zyre_peer_method_new_queue_purge (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool nowait                             //  do not send a reply method
);

zyre_peer_method_t *
    zyre_peer_method_new_queue_delete (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool if_unused,                         //  delete only if unused
Bool if_empty,                          //  delete only if empty
Bool nowait                             //  do not send a reply method
);

zyre_peer_method_t *
    zyre_peer_method_new_queue_unbind (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * exchange,                        //  exchange name
char * routing_key,                     //  message routing key
Bool nowait,                            //  do not send a reply method
icl_longstr_t * arguments               //  arguments for binding
);

zyre_peer_method_t *
    zyre_peer_method_new_basic_qos (
qbyte prefetch_size,                    //  prefetch window in octets
int prefetch_count,                     //  prefetch window in messages
Bool global                             //  apply to entire connection
);

zyre_peer_method_t *
    zyre_peer_method_new_basic_consume (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * consumer_tag,                    //  consumer tag
Bool no_local,                          //  do not deliver own messages
Bool no_ack,                            //  no acknowledgement needed
Bool exclusive,                         //  request exclusive access
Bool nowait,                            //  do not send a reply method
icl_longstr_t * arguments               //  arguments for consume
);

zyre_peer_method_t *
    zyre_peer_method_new_basic_cancel (
char * consumer_tag,                    //  consumer tag
Bool nowait                             //  do not send a reply method
);

zyre_peer_method_t *
    zyre_peer_method_new_basic_publish (
int ticket,                             //  access ticket granted by server
char * exchange,                        //  exchange name
char * routing_key,                     //  Message routing key
Bool mandatory,                         //  indicate mandatory routing
Bool immediate                          //  request immediate delivery
);

zyre_peer_method_t *
    zyre_peer_method_new_basic_get (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool no_ack                             //  no acknowledgement needed
);

zyre_peer_method_t *
    zyre_peer_method_new_basic_ack (
int64_t delivery_tag,                   //  server-assigned delivery tag
Bool multiple                           //  acknowledge multiple messages
);

zyre_peer_method_t *
    zyre_peer_method_new_basic_reject (
int64_t delivery_tag,                   //  server-assigned delivery tag
Bool requeue                            //  requeue the message
);

zyre_peer_method_t *
    zyre_peer_method_new_direct_put (
char * sink                             //  Sink name
);

zyre_peer_method_t *
    zyre_peer_method_new_direct_get (
char * feed                             //  Feed name
);

zyre_peer_method_t *
    zyre_peer_method_new_restms_pipe_create (
char * pipe_type,                       //  pipe type
char * pipe_name                        //  Name of pipe
);

zyre_peer_method_t *
    zyre_peer_method_new_restms_pipe_delete (
char * pipe_name                        //  pipe name
);

zyre_peer_method_t *
    zyre_peer_method_new_restms_feed_create (
char * feed_type,                       //  Feed type
char * feed_name                        //  Name of feed
);

zyre_peer_method_t *
    zyre_peer_method_new_restms_feed_delete (
char * feed_name                        //  feed name
);

zyre_peer_method_t *
    zyre_peer_method_new_restms_join_create (
char * pipe_name,                       //  Name of pipe
char * feed_name,                       //  Name of feed
char * address                          //  Join address
);

zyre_peer_method_t *
    zyre_peer_method_new_restms_join_delete (
char * pipe_name,                       //  Name of pipe
char * feed_name,                       //  Name of feed
char * address                          //  Join address
);

ipr_bucket_t *
    zyre_peer_method_encode (
zyre_peer_method_t * self               //  Method reference
);

zyre_peer_method_t *
    zyre_peer_method_decode (
ipr_bucket_t * bucket,                  //  New bucket
char * strerror                         //  Error text, if any
);

int
    zyre_peer_method_dump (
zyre_peer_method_t * self,              //  Reference to object
smt_log_t * log,                        //  Log file, if any
char * prefix                           //  Prefix for line
);

int
    zyre_peer_method_execute (
zyre_peer_method_t * self,              //  Reference to object
zyre_backend_t * caller,                //  Caller object
smt_thread_t * thread                   //  Parent thread
);

void
    zyre_peer_method_selftest (
void);

#define zyre_peer_method_show(item,opcode,trace_file)  zyre_peer_method_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    zyre_peer_method_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_peer_method_destroy(self)  zyre_peer_method_destroy_ (self, __FILE__, __LINE__)
void
    zyre_peer_method_destroy_ (
zyre_peer_method_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define zyre_peer_method_link(self)     zyre_peer_method_link_ (self, __FILE__, __LINE__)
zyre_peer_method_t *
    zyre_peer_method_link_ (
zyre_peer_method_t * self,              //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_peer_method_unlink(self)   zyre_peer_method_unlink_ (self, __FILE__, __LINE__)
void
    zyre_peer_method_unlink_ (
zyre_peer_method_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    zyre_peer_method_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define zyre_peer_method_new_in_scope(self_p,_scope)  zyre_peer_method_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    zyre_peer_method_new_in_scope_ (
zyre_peer_method_t * * self_p,          //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_PEER_METHOD_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PEER_METHOD_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_PEER_METHOD_INLINE)
#   define INCLUDE_ZYRE_PEER_METHOD_INLINE
#   define INCLUDE_ZYRE_PEER_METHOD_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "amq_constants.h"
#   include "zyre_peer_agent.h"
#   include "amq_content_basic.h"
#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_PEER_METHOD_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PEER_METHOD_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_PEER_METHOD_ROOT
#   endif
# endif
#endif
