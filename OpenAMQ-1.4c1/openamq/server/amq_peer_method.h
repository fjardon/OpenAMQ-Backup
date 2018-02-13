/*---------------------------------------------------------------------------
    amq_peer_method.h - amq_peer_method component

This class holds a method.  All protocol methods are held in a single
union that can be processed as a single entity.
    Generated from amq_peer_method.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_PEER_METHOD_SAFE
#   define INCLUDE_AMQ_PEER_METHOD_SAFE
#   define INCLUDE_AMQ_PEER_METHOD_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_PEER_METHOD_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_peer_method_t amq_peer_method_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEER_METHOD)
#    define AMQ_PEER_METHOD_HISTORY_LENGTH 32
#endif

#define AMQ_PEER_METHOD_ALIVE           0xFABB
#define AMQ_PEER_METHOD_DEAD            0xDEAD

#define AMQ_PEER_METHOD_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_peer_method\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_PEER_METHOD_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_peer_method at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_PEER_METHOD_ALIVE, self->object_tag);\
        amq_peer_method_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#define AMQ_PEER_CONNECTION                 10
#define AMQ_PEER_CONNECTION_START           10
#define AMQ_PEER_CONNECTION_START_OK        11
#define AMQ_PEER_CONNECTION_SECURE          20
#define AMQ_PEER_CONNECTION_SECURE_OK       21
#define AMQ_PEER_CONNECTION_TUNE            30
#define AMQ_PEER_CONNECTION_TUNE_OK         31
#define AMQ_PEER_CONNECTION_OPEN            40
#define AMQ_PEER_CONNECTION_OPEN_OK         41
#define AMQ_PEER_CONNECTION_CLOSE           50
#define AMQ_PEER_CONNECTION_CLOSE_OK        51

#define AMQ_PEER_CHANNEL                    20
#define AMQ_PEER_CHANNEL_OPEN               10
#define AMQ_PEER_CHANNEL_OPEN_OK            11
#define AMQ_PEER_CHANNEL_FLOW               20
#define AMQ_PEER_CHANNEL_FLOW_OK            21
#define AMQ_PEER_CHANNEL_CLOSE              40
#define AMQ_PEER_CHANNEL_CLOSE_OK           41

#define AMQ_PEER_EXCHANGE                   40
#define AMQ_PEER_EXCHANGE_DECLARE           10
#define AMQ_PEER_EXCHANGE_DECLARE_OK        11
#define AMQ_PEER_EXCHANGE_DELETE            20
#define AMQ_PEER_EXCHANGE_DELETE_OK         21

#define AMQ_PEER_QUEUE                      50
#define AMQ_PEER_QUEUE_DECLARE              10
#define AMQ_PEER_QUEUE_DECLARE_OK           11
#define AMQ_PEER_QUEUE_BIND                 20
#define AMQ_PEER_QUEUE_BIND_OK              21
#define AMQ_PEER_QUEUE_PURGE                30
#define AMQ_PEER_QUEUE_PURGE_OK             31
#define AMQ_PEER_QUEUE_DELETE               40
#define AMQ_PEER_QUEUE_DELETE_OK            41
#define AMQ_PEER_QUEUE_UNBIND               50
#define AMQ_PEER_QUEUE_UNBIND_OK            51

#define AMQ_PEER_BASIC                      60
#define AMQ_PEER_BASIC_QOS                  10
#define AMQ_PEER_BASIC_QOS_OK               11
#define AMQ_PEER_BASIC_CONSUME              20
#define AMQ_PEER_BASIC_CONSUME_OK           21
#define AMQ_PEER_BASIC_CANCEL               30
#define AMQ_PEER_BASIC_CANCEL_OK            31
#define AMQ_PEER_BASIC_PUBLISH              40
#define AMQ_PEER_BASIC_RETURN               50
#define AMQ_PEER_BASIC_DELIVER              60
#define AMQ_PEER_BASIC_GET                  70
#define AMQ_PEER_BASIC_GET_OK               71
#define AMQ_PEER_BASIC_GET_EMPTY            72
#define AMQ_PEER_BASIC_ACK                  80
#define AMQ_PEER_BASIC_REJECT               90

#define AMQ_PEER_DIRECT                     61500
#define AMQ_PEER_DIRECT_PUT                 10
#define AMQ_PEER_DIRECT_PUT_OK              11
#define AMQ_PEER_DIRECT_GET                 20
#define AMQ_PEER_DIRECT_GET_OK              21

#define AMQ_PEER_RESTMS                     61501
#define AMQ_PEER_RESTMS_PIPE_CREATE         10
#define AMQ_PEER_RESTMS_PIPE_DELETE         20
#define AMQ_PEER_RESTMS_FEED_CREATE         30
#define AMQ_PEER_RESTMS_FEED_DELETE         40
#define AMQ_PEER_RESTMS_JOIN_CREATE         50
#define AMQ_PEER_RESTMS_JOIN_DELETE         60

typedef struct _amq_peer_connection_start_t amq_peer_connection_start_t;
typedef struct _amq_peer_connection_start_ok_t amq_peer_connection_start_ok_t;
typedef struct _amq_peer_connection_secure_t amq_peer_connection_secure_t;
typedef struct _amq_peer_connection_secure_ok_t amq_peer_connection_secure_ok_t;
typedef struct _amq_peer_connection_tune_t amq_peer_connection_tune_t;
typedef struct _amq_peer_connection_tune_ok_t amq_peer_connection_tune_ok_t;
typedef struct _amq_peer_connection_open_t amq_peer_connection_open_t;
typedef struct _amq_peer_connection_open_ok_t amq_peer_connection_open_ok_t;
typedef struct _amq_peer_connection_close_t amq_peer_connection_close_t;
typedef struct _amq_peer_connection_close_ok_t amq_peer_connection_close_ok_t;
typedef struct _amq_peer_channel_open_t amq_peer_channel_open_t;
typedef struct _amq_peer_channel_open_ok_t amq_peer_channel_open_ok_t;
typedef struct _amq_peer_channel_flow_t amq_peer_channel_flow_t;
typedef struct _amq_peer_channel_flow_ok_t amq_peer_channel_flow_ok_t;
typedef struct _amq_peer_channel_close_t amq_peer_channel_close_t;
typedef struct _amq_peer_channel_close_ok_t amq_peer_channel_close_ok_t;
typedef struct _amq_peer_exchange_declare_t amq_peer_exchange_declare_t;
typedef struct _amq_peer_exchange_declare_ok_t amq_peer_exchange_declare_ok_t;
typedef struct _amq_peer_exchange_delete_t amq_peer_exchange_delete_t;
typedef struct _amq_peer_exchange_delete_ok_t amq_peer_exchange_delete_ok_t;
typedef struct _amq_peer_queue_declare_t amq_peer_queue_declare_t;
typedef struct _amq_peer_queue_declare_ok_t amq_peer_queue_declare_ok_t;
typedef struct _amq_peer_queue_bind_t amq_peer_queue_bind_t;
typedef struct _amq_peer_queue_bind_ok_t amq_peer_queue_bind_ok_t;
typedef struct _amq_peer_queue_purge_t amq_peer_queue_purge_t;
typedef struct _amq_peer_queue_purge_ok_t amq_peer_queue_purge_ok_t;
typedef struct _amq_peer_queue_delete_t amq_peer_queue_delete_t;
typedef struct _amq_peer_queue_delete_ok_t amq_peer_queue_delete_ok_t;
typedef struct _amq_peer_queue_unbind_t amq_peer_queue_unbind_t;
typedef struct _amq_peer_queue_unbind_ok_t amq_peer_queue_unbind_ok_t;
typedef struct _amq_peer_basic_qos_t amq_peer_basic_qos_t;
typedef struct _amq_peer_basic_qos_ok_t amq_peer_basic_qos_ok_t;
typedef struct _amq_peer_basic_consume_t amq_peer_basic_consume_t;
typedef struct _amq_peer_basic_consume_ok_t amq_peer_basic_consume_ok_t;
typedef struct _amq_peer_basic_cancel_t amq_peer_basic_cancel_t;
typedef struct _amq_peer_basic_cancel_ok_t amq_peer_basic_cancel_ok_t;
typedef struct _amq_peer_basic_publish_t amq_peer_basic_publish_t;
typedef struct _amq_peer_basic_return_t amq_peer_basic_return_t;
typedef struct _amq_peer_basic_deliver_t amq_peer_basic_deliver_t;
typedef struct _amq_peer_basic_get_t amq_peer_basic_get_t;
typedef struct _amq_peer_basic_get_ok_t amq_peer_basic_get_ok_t;
typedef struct _amq_peer_basic_get_empty_t amq_peer_basic_get_empty_t;
typedef struct _amq_peer_basic_ack_t amq_peer_basic_ack_t;
typedef struct _amq_peer_basic_reject_t amq_peer_basic_reject_t;
typedef struct _amq_peer_direct_put_t amq_peer_direct_put_t;
typedef struct _amq_peer_direct_put_ok_t amq_peer_direct_put_ok_t;
typedef struct _amq_peer_direct_get_t amq_peer_direct_get_t;
typedef struct _amq_peer_direct_get_ok_t amq_peer_direct_get_ok_t;
typedef struct _amq_peer_restms_pipe_create_t amq_peer_restms_pipe_create_t;
typedef struct _amq_peer_restms_pipe_delete_t amq_peer_restms_pipe_delete_t;
typedef struct _amq_peer_restms_feed_create_t amq_peer_restms_feed_create_t;
typedef struct _amq_peer_restms_feed_delete_t amq_peer_restms_feed_delete_t;
typedef struct _amq_peer_restms_join_create_t amq_peer_restms_join_create_t;
typedef struct _amq_peer_restms_join_delete_t amq_peer_restms_join_delete_t;
#   ifdef __cplusplus
}
#   endif

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "amq_constants.h"
#   include "amq_peer_agent.h"
#   include "amq_content_basic.h"
#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_PEER_METHOD_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEER_METHOD_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_PEER_METHOD_UNSAFE
#   define INCLUDE_AMQ_PEER_METHOD_UNSAFE
#   define INCLUDE_AMQ_PEER_METHOD_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "amq_constants.h"
#   include "amq_peer_agent.h"
#   include "amq_content_basic.h"
#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_peer_method_animating;
//  Start Connection Negotiation

struct _amq_peer_connection_start_t {
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

struct _amq_peer_connection_start_ok_t {
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

struct _amq_peer_connection_secure_t {
    icl_longstr_t *
        challenge;                      //  security challenge data
};

//  Security Mechanism Response

struct _amq_peer_connection_secure_ok_t {
    icl_longstr_t *
        response;                       //  security response data
};

//  Propose Connection Tuning Parameters

struct _amq_peer_connection_tune_t {
    dbyte
        channel_max;                    //  proposed maximum channels
    qbyte
        frame_max;                      //  proposed maximum frame size
    dbyte
        heartbeat;                      //  desired heartbeat delay
};

//  Negotiate Connection Tuning Parameters

struct _amq_peer_connection_tune_ok_t {
    dbyte
        channel_max;                    //  negotiated maximum channels
    qbyte
        frame_max;                      //  negotiated maximum frame size
    dbyte
        heartbeat;                      //  desired heartbeat delay
};

//  Open Connection To Virtual Host

struct _amq_peer_connection_open_t {
    icl_shortstr_t
        virtual_host;                   //  virtual host name
    icl_shortstr_t
        capabilities;                   //  required capabilities
    Bool
        insist;                         //  insist on connecting to server
};

//  Signal That The Connection Is Ready

struct _amq_peer_connection_open_ok_t {
    icl_shortstr_t
        known_hosts;                    //  list of known hosts
};

//  Request A Connection Close

struct _amq_peer_connection_close_t {
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

struct _amq_peer_connection_close_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Open A Channel For Use

struct _amq_peer_channel_open_t {
    icl_shortstr_t
        out_of_band;                    //  out-of-band settings
};

//  Signal That The Channel Is Ready

struct _amq_peer_channel_open_ok_t {
    icl_longstr_t *
        channel_id;                     //  unique id of the channel
};

//  Enable/Disable Flow From Peer

struct _amq_peer_channel_flow_t {
    Bool
        active;                         //  start/stop content frames
};

//  Confirm A Flow Method

struct _amq_peer_channel_flow_ok_t {
    Bool
        active;                         //  current flow setting
};

//  Request A Channel Close

struct _amq_peer_channel_close_t {
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

struct _amq_peer_channel_close_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Declare Exchange, Create If Needed

struct _amq_peer_exchange_declare_t {
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

struct _amq_peer_exchange_declare_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Delete An Exchange

struct _amq_peer_exchange_delete_t {
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

struct _amq_peer_exchange_delete_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Declare Queue, Create If Needed

struct _amq_peer_queue_declare_t {
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

struct _amq_peer_queue_declare_ok_t {
    icl_shortstr_t
        queue;                          //  queue name
    qbyte
        message_count;                  //  number of messages in queue
    qbyte
        consumer_count;                 //  number of consumers
};

//  Bind Queue To An Exchange

struct _amq_peer_queue_bind_t {
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

struct _amq_peer_queue_bind_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Purge A Queue

struct _amq_peer_queue_purge_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        queue;                          //  queue name
    Bool
        nowait;                         //  do not send a reply method
};

//  Confirms A Queue Purge

struct _amq_peer_queue_purge_ok_t {
    qbyte
        message_count;                  //  number of messages purged
};

//  Delete A Queue

struct _amq_peer_queue_delete_t {
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

struct _amq_peer_queue_delete_ok_t {
    qbyte
        message_count;                  //  number of messages purged
};

//  Unbind Queue From An Exchange

struct _amq_peer_queue_unbind_t {
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

struct _amq_peer_queue_unbind_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Specify Quality Of Service

struct _amq_peer_basic_qos_t {
    qbyte
        prefetch_size;                  //  prefetch window in octets
    dbyte
        prefetch_count;                 //  prefetch window in messages
    Bool
        global;                         //  apply to entire connection
};

//  Confirm The Requested Qos

struct _amq_peer_basic_qos_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Start A Queue Consumer

struct _amq_peer_basic_consume_t {
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

struct _amq_peer_basic_consume_ok_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
};

//  End A Queue Consumer

struct _amq_peer_basic_cancel_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
    Bool
        nowait;                         //  do not send a reply method
};

//  Confirm A Cancelled Consumer

struct _amq_peer_basic_cancel_ok_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
};

//  Publish A Message

struct _amq_peer_basic_publish_t {
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

struct _amq_peer_basic_return_t {
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

struct _amq_peer_basic_deliver_t {
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

struct _amq_peer_basic_get_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        queue;                          //  queue name
    Bool
        no_ack;                         //  no acknowledgement needed
};

//  Provide Client With A Message

struct _amq_peer_basic_get_ok_t {
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

struct _amq_peer_basic_get_empty_t {
    icl_shortstr_t
        sender_id;                      //  Sender id
};

//  Acknowledge One Or More Messages

struct _amq_peer_basic_ack_t {
    int64_t
        delivery_tag;                   //  server-assigned delivery tag
    Bool
        multiple;                       //  acknowledge multiple messages
};

//  Reject An Incoming Message

struct _amq_peer_basic_reject_t {
    int64_t
        delivery_tag;                   //  server-assigned delivery tag
    Bool
        requeue;                        //  requeue the message
};

//  Request A Connection To A Sink

struct _amq_peer_direct_put_t {
    icl_shortstr_t
        sink;                           //  Sink name
};

//  Grant Access To The Sink

struct _amq_peer_direct_put_ok_t {
    icl_shortstr_t
        lease;                          //  Lease for connection
};

//  Request A Connection To A Feed

struct _amq_peer_direct_get_t {
    icl_shortstr_t
        feed;                           //  Feed name
};

//  Grant Access To The Feed

struct _amq_peer_direct_get_ok_t {
    icl_shortstr_t
        lease;                          //  Lease for connection
};

//  Create A Pipe

struct _amq_peer_restms_pipe_create_t {
    icl_shortstr_t
        pipe_type;                      //  pipe type
    icl_shortstr_t
        pipe_name;                      //  Name of pipe
};

//  Delete A Pipe

struct _amq_peer_restms_pipe_delete_t {
    icl_shortstr_t
        pipe_name;                      //  pipe name
};

//  Create A Feed

struct _amq_peer_restms_feed_create_t {
    icl_shortstr_t
        feed_type;                      //  Feed type
    icl_shortstr_t
        feed_name;                      //  Name of feed
};

//  Delete A Feed

struct _amq_peer_restms_feed_delete_t {
    icl_shortstr_t
        feed_name;                      //  feed name
};

//  Create A Join

struct _amq_peer_restms_join_create_t {
    icl_shortstr_t
        pipe_name;                      //  Name of pipe
    icl_shortstr_t
        feed_name;                      //  Name of feed
    icl_shortstr_t
        address;                        //  Join address
};

//  Delete A Join

struct _amq_peer_restms_join_delete_t {
    icl_shortstr_t
        pipe_name;                      //  Name of pipe
    icl_shortstr_t
        feed_name;                      //  Name of feed
    icl_shortstr_t
        address;                        //  Join address
};

//  Structure of the amq_peer_method object

struct _amq_peer_method_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEER_METHOD)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_PEER_METHOD_HISTORY_LENGTH];
    int
        history_line  [AMQ_PEER_METHOD_HISTORY_LENGTH];
    char
        *history_type [AMQ_PEER_METHOD_HISTORY_LENGTH];
    int
        history_links [AMQ_PEER_METHOD_HISTORY_LENGTH];
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
    amq_peer_connection_start_t
        connection_start;
    amq_peer_connection_start_ok_t
        connection_start_ok;
    amq_peer_connection_secure_t
        connection_secure;
    amq_peer_connection_secure_ok_t
        connection_secure_ok;
    amq_peer_connection_tune_t
        connection_tune;
    amq_peer_connection_tune_ok_t
        connection_tune_ok;
    amq_peer_connection_open_t
        connection_open;
    amq_peer_connection_open_ok_t
        connection_open_ok;
    amq_peer_connection_close_t
        connection_close;
    amq_peer_connection_close_ok_t
        connection_close_ok;
    amq_peer_channel_open_t
        channel_open;
    amq_peer_channel_open_ok_t
        channel_open_ok;
    amq_peer_channel_flow_t
        channel_flow;
    amq_peer_channel_flow_ok_t
        channel_flow_ok;
    amq_peer_channel_close_t
        channel_close;
    amq_peer_channel_close_ok_t
        channel_close_ok;
    amq_peer_exchange_declare_t
        exchange_declare;
    amq_peer_exchange_declare_ok_t
        exchange_declare_ok;
    amq_peer_exchange_delete_t
        exchange_delete;
    amq_peer_exchange_delete_ok_t
        exchange_delete_ok;
    amq_peer_queue_declare_t
        queue_declare;
    amq_peer_queue_declare_ok_t
        queue_declare_ok;
    amq_peer_queue_bind_t
        queue_bind;
    amq_peer_queue_bind_ok_t
        queue_bind_ok;
    amq_peer_queue_purge_t
        queue_purge;
    amq_peer_queue_purge_ok_t
        queue_purge_ok;
    amq_peer_queue_delete_t
        queue_delete;
    amq_peer_queue_delete_ok_t
        queue_delete_ok;
    amq_peer_queue_unbind_t
        queue_unbind;
    amq_peer_queue_unbind_ok_t
        queue_unbind_ok;
    amq_peer_basic_qos_t
        basic_qos;
    amq_peer_basic_qos_ok_t
        basic_qos_ok;
    amq_peer_basic_consume_t
        basic_consume;
    amq_peer_basic_consume_ok_t
        basic_consume_ok;
    amq_peer_basic_cancel_t
        basic_cancel;
    amq_peer_basic_cancel_ok_t
        basic_cancel_ok;
    amq_peer_basic_publish_t
        basic_publish;
    amq_peer_basic_return_t
        basic_return;
    amq_peer_basic_deliver_t
        basic_deliver;
    amq_peer_basic_get_t
        basic_get;
    amq_peer_basic_get_ok_t
        basic_get_ok;
    amq_peer_basic_get_empty_t
        basic_get_empty;
    amq_peer_basic_ack_t
        basic_ack;
    amq_peer_basic_reject_t
        basic_reject;
    amq_peer_direct_put_t
        direct_put;
    amq_peer_direct_put_ok_t
        direct_put_ok;
    amq_peer_direct_get_t
        direct_get;
    amq_peer_direct_get_ok_t
        direct_get_ok;
    amq_peer_restms_pipe_create_t
        restms_pipe_create;
    amq_peer_restms_pipe_delete_t
        restms_pipe_delete;
    amq_peer_restms_feed_create_t
        restms_feed_create;
    amq_peer_restms_feed_delete_t
        restms_feed_delete;
    amq_peer_restms_join_create_t
        restms_join_create;
    amq_peer_restms_join_delete_t
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
#define amq_peer_method_new()           amq_peer_method_new_ (__FILE__, __LINE__)
amq_peer_method_t *
    amq_peer_method_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

amq_peer_method_t *
    amq_peer_method_new_connection_start_ok (
icl_longstr_t * client_properties,      //  client properties
char * mechanism,                       //  selected security mechanism
icl_longstr_t * response,               //  security response data
char * locale                           //  selected message locale
);

amq_peer_method_t *
    amq_peer_method_new_connection_secure_ok (
icl_longstr_t * response                //  security response data
);

amq_peer_method_t *
    amq_peer_method_new_connection_tune_ok (
int channel_max,                        //  negotiated maximum channels
qbyte frame_max,                        //  negotiated maximum frame size
int heartbeat                           //  desired heartbeat delay
);

amq_peer_method_t *
    amq_peer_method_new_connection_open (
char * virtual_host,                    //  virtual host name
char * capabilities,                    //  required capabilities
Bool insist                             //  insist on connecting to server
);

amq_peer_method_t *
    amq_peer_method_new_connection_close (
int reply_code,                         //  reply code from server
char * reply_text,                      //  localised reply text
int class_id,                           //  failing method class
int method_id                           //  failing method ID
);

amq_peer_method_t *
    amq_peer_method_new_connection_close_ok (
void);

amq_peer_method_t *
    amq_peer_method_new_channel_open (
char * out_of_band                      //  out-of-band settings
);

amq_peer_method_t *
    amq_peer_method_new_channel_flow (
Bool active                             //  start/stop content frames
);

amq_peer_method_t *
    amq_peer_method_new_channel_flow_ok (
Bool active                             //  current flow setting
);

amq_peer_method_t *
    amq_peer_method_new_channel_close (
int reply_code,                         //  reply code from server
char * reply_text,                      //  localised reply text
int class_id,                           //  failing method class
int method_id                           //  failing method ID
);

amq_peer_method_t *
    amq_peer_method_new_channel_close_ok (
void);

amq_peer_method_t *
    amq_peer_method_new_exchange_declare (
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

amq_peer_method_t *
    amq_peer_method_new_exchange_delete (
int ticket,                             //  access ticket granted by server
char * exchange,                        //  exchange name
Bool if_unused,                         //  delete only if unused
Bool nowait                             //  do not send a reply method
);

amq_peer_method_t *
    amq_peer_method_new_queue_declare (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool passive,                           //  do not create queue
Bool durable,                           //  request a durable queue
Bool exclusive,                         //  request an exclusive queue
Bool auto_delete,                       //  auto-delete queue when unused
Bool nowait,                            //  do not send a reply method
icl_longstr_t * arguments               //  arguments for declaration
);

amq_peer_method_t *
    amq_peer_method_new_queue_bind (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * exchange,                        //  exchange name
char * routing_key,                     //  message routing key
Bool nowait,                            //  do not send a reply method
icl_longstr_t * arguments               //  arguments for binding
);

amq_peer_method_t *
    amq_peer_method_new_queue_purge (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool nowait                             //  do not send a reply method
);

amq_peer_method_t *
    amq_peer_method_new_queue_delete (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool if_unused,                         //  delete only if unused
Bool if_empty,                          //  delete only if empty
Bool nowait                             //  do not send a reply method
);

amq_peer_method_t *
    amq_peer_method_new_queue_unbind (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * exchange,                        //  exchange name
char * routing_key,                     //  message routing key
Bool nowait,                            //  do not send a reply method
icl_longstr_t * arguments               //  arguments for binding
);

amq_peer_method_t *
    amq_peer_method_new_basic_qos (
qbyte prefetch_size,                    //  prefetch window in octets
int prefetch_count,                     //  prefetch window in messages
Bool global                             //  apply to entire connection
);

amq_peer_method_t *
    amq_peer_method_new_basic_consume (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
char * consumer_tag,                    //  consumer tag
Bool no_local,                          //  do not deliver own messages
Bool no_ack,                            //  no acknowledgement needed
Bool exclusive,                         //  request exclusive access
Bool nowait,                            //  do not send a reply method
icl_longstr_t * arguments               //  arguments for consume
);

amq_peer_method_t *
    amq_peer_method_new_basic_cancel (
char * consumer_tag,                    //  consumer tag
Bool nowait                             //  do not send a reply method
);

amq_peer_method_t *
    amq_peer_method_new_basic_publish (
int ticket,                             //  access ticket granted by server
char * exchange,                        //  exchange name
char * routing_key,                     //  Message routing key
Bool mandatory,                         //  indicate mandatory routing
Bool immediate                          //  request immediate delivery
);

amq_peer_method_t *
    amq_peer_method_new_basic_get (
int ticket,                             //  access ticket granted by server
char * queue,                           //  queue name
Bool no_ack                             //  no acknowledgement needed
);

amq_peer_method_t *
    amq_peer_method_new_basic_ack (
int64_t delivery_tag,                   //  server-assigned delivery tag
Bool multiple                           //  acknowledge multiple messages
);

amq_peer_method_t *
    amq_peer_method_new_basic_reject (
int64_t delivery_tag,                   //  server-assigned delivery tag
Bool requeue                            //  requeue the message
);

amq_peer_method_t *
    amq_peer_method_new_direct_put (
char * sink                             //  Sink name
);

amq_peer_method_t *
    amq_peer_method_new_direct_get (
char * feed                             //  Feed name
);

amq_peer_method_t *
    amq_peer_method_new_restms_pipe_create (
char * pipe_type,                       //  pipe type
char * pipe_name                        //  Name of pipe
);

amq_peer_method_t *
    amq_peer_method_new_restms_pipe_delete (
char * pipe_name                        //  pipe name
);

amq_peer_method_t *
    amq_peer_method_new_restms_feed_create (
char * feed_type,                       //  Feed type
char * feed_name                        //  Name of feed
);

amq_peer_method_t *
    amq_peer_method_new_restms_feed_delete (
char * feed_name                        //  feed name
);

amq_peer_method_t *
    amq_peer_method_new_restms_join_create (
char * pipe_name,                       //  Name of pipe
char * feed_name,                       //  Name of feed
char * address                          //  Join address
);

amq_peer_method_t *
    amq_peer_method_new_restms_join_delete (
char * pipe_name,                       //  Name of pipe
char * feed_name,                       //  Name of feed
char * address                          //  Join address
);

ipr_bucket_t *
    amq_peer_method_encode (
amq_peer_method_t * self                //  Method reference
);

amq_peer_method_t *
    amq_peer_method_decode (
ipr_bucket_t * bucket,                  //  New bucket
char * strerror                         //  Error text, if any
);

int
    amq_peer_method_dump (
amq_peer_method_t * self,               //  Reference to object
smt_log_t * log,                        //  Log file, if any
char * prefix                           //  Prefix for line
);

int
    amq_peer_method_execute (
amq_peer_method_t * self,               //  Reference to object
amq_peering_t * caller,                 //  Caller object
smt_thread_t * thread                   //  Parent thread
);

void
    amq_peer_method_selftest (
void);

#define amq_peer_method_show(item,opcode,trace_file)  amq_peer_method_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_peer_method_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_peer_method_destroy(self)   amq_peer_method_destroy_ (self, __FILE__, __LINE__)
void
    amq_peer_method_destroy_ (
amq_peer_method_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define amq_peer_method_link(self)      amq_peer_method_link_ (self, __FILE__, __LINE__)
amq_peer_method_t *
    amq_peer_method_link_ (
amq_peer_method_t * self,               //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_peer_method_unlink(self)    amq_peer_method_unlink_ (self, __FILE__, __LINE__)
void
    amq_peer_method_unlink_ (
amq_peer_method_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_peer_method_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_peer_method_new_in_scope(self_p,_scope)  amq_peer_method_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_peer_method_new_in_scope_ (
amq_peer_method_t * * self_p,           //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_PEER_METHOD_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEER_METHOD_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_PEER_METHOD_INLINE)
#   define INCLUDE_AMQ_PEER_METHOD_INLINE
#   define INCLUDE_AMQ_PEER_METHOD_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "amq_constants.h"
#   include "amq_peer_agent.h"
#   include "amq_content_basic.h"
#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_PEER_METHOD_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEER_METHOD_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_PEER_METHOD_ROOT
#   endif
# endif
#endif
