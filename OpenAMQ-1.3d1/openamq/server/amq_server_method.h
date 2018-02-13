/*---------------------------------------------------------------------------
    amq_server_method.h - amq_server_method component

This class holds a method.  All protocol methods are held in a single
union that can be processed as a single entity.
    Generated from amq_server_method.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_SERVER_METHOD_SAFE
#   define INCLUDE_AMQ_SERVER_METHOD_SAFE
#   define INCLUDE_AMQ_SERVER_METHOD_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_SERVER_METHOD_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_server_method_t amq_server_method_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
#    define AMQ_SERVER_METHOD_HISTORY_LENGTH 32
#endif

#define AMQ_SERVER_METHOD_ALIVE         0xFABB
#define AMQ_SERVER_METHOD_DEAD          0xDEAD

#define AMQ_SERVER_METHOD_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_server_method\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_SERVER_METHOD_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_server_method at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_SERVER_METHOD_ALIVE, self->object_tag);\
        amq_server_method_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#define AMQ_SERVER_CONNECTION               10
#define AMQ_SERVER_CONNECTION_START         10
#define AMQ_SERVER_CONNECTION_START_OK      11
#define AMQ_SERVER_CONNECTION_SECURE        20
#define AMQ_SERVER_CONNECTION_SECURE_OK     21
#define AMQ_SERVER_CONNECTION_TUNE          30
#define AMQ_SERVER_CONNECTION_TUNE_OK       31
#define AMQ_SERVER_CONNECTION_OPEN          40
#define AMQ_SERVER_CONNECTION_OPEN_OK       41
#define AMQ_SERVER_CONNECTION_CLOSE         50
#define AMQ_SERVER_CONNECTION_CLOSE_OK      51

#define AMQ_SERVER_CHANNEL                  20
#define AMQ_SERVER_CHANNEL_OPEN             10
#define AMQ_SERVER_CHANNEL_OPEN_OK          11
#define AMQ_SERVER_CHANNEL_FLOW             20
#define AMQ_SERVER_CHANNEL_FLOW_OK          21
#define AMQ_SERVER_CHANNEL_CLOSE            40
#define AMQ_SERVER_CHANNEL_CLOSE_OK         41

#define AMQ_SERVER_EXCHANGE                 40
#define AMQ_SERVER_EXCHANGE_DECLARE         10
#define AMQ_SERVER_EXCHANGE_DECLARE_OK      11
#define AMQ_SERVER_EXCHANGE_DELETE          20
#define AMQ_SERVER_EXCHANGE_DELETE_OK       21

#define AMQ_SERVER_QUEUE                    50
#define AMQ_SERVER_QUEUE_DECLARE            10
#define AMQ_SERVER_QUEUE_DECLARE_OK         11
#define AMQ_SERVER_QUEUE_BIND               20
#define AMQ_SERVER_QUEUE_BIND_OK            21
#define AMQ_SERVER_QUEUE_PURGE              30
#define AMQ_SERVER_QUEUE_PURGE_OK           31
#define AMQ_SERVER_QUEUE_DELETE             40
#define AMQ_SERVER_QUEUE_DELETE_OK          41
#define AMQ_SERVER_QUEUE_UNBIND             50
#define AMQ_SERVER_QUEUE_UNBIND_OK          51

#define AMQ_SERVER_BASIC                    60
#define AMQ_SERVER_BASIC_QOS                10
#define AMQ_SERVER_BASIC_QOS_OK             11
#define AMQ_SERVER_BASIC_CONSUME            20
#define AMQ_SERVER_BASIC_CONSUME_OK         21
#define AMQ_SERVER_BASIC_CANCEL             30
#define AMQ_SERVER_BASIC_CANCEL_OK          31
#define AMQ_SERVER_BASIC_PUBLISH            40
#define AMQ_SERVER_BASIC_RETURN             50
#define AMQ_SERVER_BASIC_DELIVER            60
#define AMQ_SERVER_BASIC_GET                70
#define AMQ_SERVER_BASIC_GET_OK             71
#define AMQ_SERVER_BASIC_GET_EMPTY          72
#define AMQ_SERVER_BASIC_ACK                80
#define AMQ_SERVER_BASIC_REJECT             90

#define AMQ_SERVER_DIRECT                   61500
#define AMQ_SERVER_DIRECT_PUT               10
#define AMQ_SERVER_DIRECT_PUT_OK            11
#define AMQ_SERVER_DIRECT_GET               20
#define AMQ_SERVER_DIRECT_GET_OK            21

typedef struct _amq_server_connection_start_t amq_server_connection_start_t;
typedef struct _amq_server_connection_start_ok_t amq_server_connection_start_ok_t;
typedef struct _amq_server_connection_secure_t amq_server_connection_secure_t;
typedef struct _amq_server_connection_secure_ok_t amq_server_connection_secure_ok_t;
typedef struct _amq_server_connection_tune_t amq_server_connection_tune_t;
typedef struct _amq_server_connection_tune_ok_t amq_server_connection_tune_ok_t;
typedef struct _amq_server_connection_open_t amq_server_connection_open_t;
typedef struct _amq_server_connection_open_ok_t amq_server_connection_open_ok_t;
typedef struct _amq_server_connection_close_t amq_server_connection_close_t;
typedef struct _amq_server_connection_close_ok_t amq_server_connection_close_ok_t;
typedef struct _amq_server_channel_open_t amq_server_channel_open_t;
typedef struct _amq_server_channel_open_ok_t amq_server_channel_open_ok_t;
typedef struct _amq_server_channel_flow_t amq_server_channel_flow_t;
typedef struct _amq_server_channel_flow_ok_t amq_server_channel_flow_ok_t;
typedef struct _amq_server_channel_close_t amq_server_channel_close_t;
typedef struct _amq_server_channel_close_ok_t amq_server_channel_close_ok_t;
typedef struct _amq_server_exchange_declare_t amq_server_exchange_declare_t;
typedef struct _amq_server_exchange_declare_ok_t amq_server_exchange_declare_ok_t;
typedef struct _amq_server_exchange_delete_t amq_server_exchange_delete_t;
typedef struct _amq_server_exchange_delete_ok_t amq_server_exchange_delete_ok_t;
typedef struct _amq_server_queue_declare_t amq_server_queue_declare_t;
typedef struct _amq_server_queue_declare_ok_t amq_server_queue_declare_ok_t;
typedef struct _amq_server_queue_bind_t amq_server_queue_bind_t;
typedef struct _amq_server_queue_bind_ok_t amq_server_queue_bind_ok_t;
typedef struct _amq_server_queue_purge_t amq_server_queue_purge_t;
typedef struct _amq_server_queue_purge_ok_t amq_server_queue_purge_ok_t;
typedef struct _amq_server_queue_delete_t amq_server_queue_delete_t;
typedef struct _amq_server_queue_delete_ok_t amq_server_queue_delete_ok_t;
typedef struct _amq_server_queue_unbind_t amq_server_queue_unbind_t;
typedef struct _amq_server_queue_unbind_ok_t amq_server_queue_unbind_ok_t;
typedef struct _amq_server_basic_qos_t amq_server_basic_qos_t;
typedef struct _amq_server_basic_qos_ok_t amq_server_basic_qos_ok_t;
typedef struct _amq_server_basic_consume_t amq_server_basic_consume_t;
typedef struct _amq_server_basic_consume_ok_t amq_server_basic_consume_ok_t;
typedef struct _amq_server_basic_cancel_t amq_server_basic_cancel_t;
typedef struct _amq_server_basic_cancel_ok_t amq_server_basic_cancel_ok_t;
typedef struct _amq_server_basic_publish_t amq_server_basic_publish_t;
typedef struct _amq_server_basic_return_t amq_server_basic_return_t;
typedef struct _amq_server_basic_deliver_t amq_server_basic_deliver_t;
typedef struct _amq_server_basic_get_t amq_server_basic_get_t;
typedef struct _amq_server_basic_get_ok_t amq_server_basic_get_ok_t;
typedef struct _amq_server_basic_get_empty_t amq_server_basic_get_empty_t;
typedef struct _amq_server_basic_ack_t amq_server_basic_ack_t;
typedef struct _amq_server_basic_reject_t amq_server_basic_reject_t;
typedef struct _amq_server_direct_put_t amq_server_direct_put_t;
typedef struct _amq_server_direct_put_ok_t amq_server_direct_put_ok_t;
typedef struct _amq_server_direct_get_t amq_server_direct_get_t;
typedef struct _amq_server_direct_get_ok_t amq_server_direct_get_ok_t;
#   ifdef __cplusplus
}
#   endif

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "amq_constants.h"
#   include "amq_server_agent.h"
#   include "amq_content_basic.h"
#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_METHOD_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_METHOD_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_SERVER_METHOD_UNSAFE
#   define INCLUDE_AMQ_SERVER_METHOD_UNSAFE
#   define INCLUDE_AMQ_SERVER_METHOD_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "amq_constants.h"
#   include "amq_server_agent.h"
#   include "amq_content_basic.h"
#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_server_method_animating;
//  Start Connection Negotiation

struct _amq_server_connection_start_t {
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

struct _amq_server_connection_start_ok_t {
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

struct _amq_server_connection_secure_t {
    icl_longstr_t *
        challenge;                      //  security challenge data
};

//  Security Mechanism Response

struct _amq_server_connection_secure_ok_t {
    icl_longstr_t *
        response;                       //  security response data
};

//  Propose Connection Tuning Parameters

struct _amq_server_connection_tune_t {
    dbyte
        channel_max;                    //  proposed maximum channels
    qbyte
        frame_max;                      //  proposed maximum frame size
    dbyte
        heartbeat;                      //  desired heartbeat delay
};

//  Negotiate Connection Tuning Parameters

struct _amq_server_connection_tune_ok_t {
    dbyte
        channel_max;                    //  negotiated maximum channels
    qbyte
        frame_max;                      //  negotiated maximum frame size
    dbyte
        heartbeat;                      //  desired heartbeat delay
};

//  Open Connection To Virtual Host

struct _amq_server_connection_open_t {
    icl_shortstr_t
        virtual_host;                   //  virtual host name
    icl_shortstr_t
        capabilities;                   //  required capabilities
    Bool
        insist;                         //  insist on connecting to server
};

//  Signal That The Connection Is Ready

struct _amq_server_connection_open_ok_t {
    icl_shortstr_t
        known_hosts;                    //  list of known hosts
};

//  Request A Connection Close

struct _amq_server_connection_close_t {
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

struct _amq_server_connection_close_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Open A Channel For Use

struct _amq_server_channel_open_t {
    icl_shortstr_t
        out_of_band;                    //  out-of-band settings
};

//  Signal That The Channel Is Ready

struct _amq_server_channel_open_ok_t {
    icl_longstr_t *
        channel_id;                     //  unique id of the channel
};

//  Enable/Disable Flow From Peer

struct _amq_server_channel_flow_t {
    Bool
        active;                         //  start/stop content frames
};

//  Confirm A Flow Method

struct _amq_server_channel_flow_ok_t {
    Bool
        active;                         //  current flow setting
};

//  Request A Channel Close

struct _amq_server_channel_close_t {
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

struct _amq_server_channel_close_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Declare Exchange, Create If Needed

struct _amq_server_exchange_declare_t {
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

struct _amq_server_exchange_declare_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Delete An Exchange

struct _amq_server_exchange_delete_t {
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

struct _amq_server_exchange_delete_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Declare Queue, Create If Needed

struct _amq_server_queue_declare_t {
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

struct _amq_server_queue_declare_ok_t {
    icl_shortstr_t
        queue;                          //  queue name
    qbyte
        message_count;                  //  number of messages in queue
    qbyte
        consumer_count;                 //  number of consumers
};

//  Bind Queue To An Exchange

struct _amq_server_queue_bind_t {
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

struct _amq_server_queue_bind_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Purge A Queue

struct _amq_server_queue_purge_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        queue;                          //  queue name
    Bool
        nowait;                         //  do not send a reply method
};

//  Confirms A Queue Purge

struct _amq_server_queue_purge_ok_t {
    qbyte
        message_count;                  //  number of messages purged
};

//  Delete A Queue

struct _amq_server_queue_delete_t {
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

struct _amq_server_queue_delete_ok_t {
    qbyte
        message_count;                  //  number of messages purged
};

//  Unbind Queue From An Exchange

struct _amq_server_queue_unbind_t {
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

struct _amq_server_queue_unbind_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Specify Quality Of Service

struct _amq_server_basic_qos_t {
    qbyte
        prefetch_size;                  //  prefetch window in octets
    dbyte
        prefetch_count;                 //  prefetch window in messages
    Bool
        global;                         //  apply to entire connection
};

//  Confirm The Requested Qos

struct _amq_server_basic_qos_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Start A Queue Consumer

struct _amq_server_basic_consume_t {
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

struct _amq_server_basic_consume_ok_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
};

//  End A Queue Consumer

struct _amq_server_basic_cancel_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
    Bool
        nowait;                         //  do not send a reply method
};

//  Confirm A Cancelled Consumer

struct _amq_server_basic_cancel_ok_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
};

//  Publish A Message

struct _amq_server_basic_publish_t {
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

struct _amq_server_basic_return_t {
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

struct _amq_server_basic_deliver_t {
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

struct _amq_server_basic_get_t {
    dbyte
        ticket;                         //  access ticket granted by server
    icl_shortstr_t
        queue;                          //  queue name
    Bool
        no_ack;                         //  no acknowledgement needed
};

//  Provide Client With A Message

struct _amq_server_basic_get_ok_t {
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

struct _amq_server_basic_get_empty_t {
    icl_shortstr_t
        sender_id;                      //  Sender id
};

//  Acknowledge One Or More Messages

struct _amq_server_basic_ack_t {
    int64_t
        delivery_tag;                   //  server-assigned delivery tag
    Bool
        multiple;                       //  acknowledge multiple messages
};

//  Reject An Incoming Message

struct _amq_server_basic_reject_t {
    int64_t
        delivery_tag;                   //  server-assigned delivery tag
    Bool
        requeue;                        //  requeue the message
};

//  Request A Connection To A Sink

struct _amq_server_direct_put_t {
    icl_shortstr_t
        sink;                           //  Sink name
};

//  Grant Access To The Sink

struct _amq_server_direct_put_ok_t {
    icl_shortstr_t
        lease;                          //  Lease for connection
};

//  Request A Connection To A Feed

struct _amq_server_direct_get_t {
    icl_shortstr_t
        feed;                           //  Feed name
};

//  Grant Access To The Feed

struct _amq_server_direct_get_ok_t {
    icl_shortstr_t
        lease;                          //  Lease for connection
};

//  Structure of the amq_server_method object

struct _amq_server_method_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_SERVER_METHOD_HISTORY_LENGTH];
    int
        history_line  [AMQ_SERVER_METHOD_HISTORY_LENGTH];
    char
        *history_type [AMQ_SERVER_METHOD_HISTORY_LENGTH];
    int
        history_links [AMQ_SERVER_METHOD_HISTORY_LENGTH];
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
    amq_server_connection_start_t
        connection_start;
    amq_server_connection_start_ok_t
        connection_start_ok;
    amq_server_connection_secure_t
        connection_secure;
    amq_server_connection_secure_ok_t
        connection_secure_ok;
    amq_server_connection_tune_t
        connection_tune;
    amq_server_connection_tune_ok_t
        connection_tune_ok;
    amq_server_connection_open_t
        connection_open;
    amq_server_connection_open_ok_t
        connection_open_ok;
    amq_server_connection_close_t
        connection_close;
    amq_server_connection_close_ok_t
        connection_close_ok;
    amq_server_channel_open_t
        channel_open;
    amq_server_channel_open_ok_t
        channel_open_ok;
    amq_server_channel_flow_t
        channel_flow;
    amq_server_channel_flow_ok_t
        channel_flow_ok;
    amq_server_channel_close_t
        channel_close;
    amq_server_channel_close_ok_t
        channel_close_ok;
    amq_server_exchange_declare_t
        exchange_declare;
    amq_server_exchange_declare_ok_t
        exchange_declare_ok;
    amq_server_exchange_delete_t
        exchange_delete;
    amq_server_exchange_delete_ok_t
        exchange_delete_ok;
    amq_server_queue_declare_t
        queue_declare;
    amq_server_queue_declare_ok_t
        queue_declare_ok;
    amq_server_queue_bind_t
        queue_bind;
    amq_server_queue_bind_ok_t
        queue_bind_ok;
    amq_server_queue_purge_t
        queue_purge;
    amq_server_queue_purge_ok_t
        queue_purge_ok;
    amq_server_queue_delete_t
        queue_delete;
    amq_server_queue_delete_ok_t
        queue_delete_ok;
    amq_server_queue_unbind_t
        queue_unbind;
    amq_server_queue_unbind_ok_t
        queue_unbind_ok;
    amq_server_basic_qos_t
        basic_qos;
    amq_server_basic_qos_ok_t
        basic_qos_ok;
    amq_server_basic_consume_t
        basic_consume;
    amq_server_basic_consume_ok_t
        basic_consume_ok;
    amq_server_basic_cancel_t
        basic_cancel;
    amq_server_basic_cancel_ok_t
        basic_cancel_ok;
    amq_server_basic_publish_t
        basic_publish;
    amq_server_basic_return_t
        basic_return;
    amq_server_basic_deliver_t
        basic_deliver;
    amq_server_basic_get_t
        basic_get;
    amq_server_basic_get_ok_t
        basic_get_ok;
    amq_server_basic_get_empty_t
        basic_get_empty;
    amq_server_basic_ack_t
        basic_ack;
    amq_server_basic_reject_t
        basic_reject;
    amq_server_direct_put_t
        direct_put;
    amq_server_direct_put_ok_t
        direct_put_ok;
    amq_server_direct_get_t
        direct_get;
    amq_server_direct_get_ok_t
        direct_get_ok;
} payload;
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_server_method_new()         amq_server_method_new_ (__FILE__, __LINE__)
amq_server_method_t *
    amq_server_method_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

amq_server_method_t *
    amq_server_method_new_connection_start (
int version_major,                      //  protocol major version
int version_minor,                      //  protocol major version
icl_longstr_t * server_properties,      //  server properties
icl_longstr_t * mechanisms,             //  available security mechanisms
icl_longstr_t * locales                 //  available message locales
);

amq_server_method_t *
    amq_server_method_new_connection_secure (
icl_longstr_t * challenge               //  security challenge data
);

amq_server_method_t *
    amq_server_method_new_connection_tune (
int channel_max,                        //  proposed maximum channels
qbyte frame_max,                        //  proposed maximum frame size
int heartbeat                           //  desired heartbeat delay
);

amq_server_method_t *
    amq_server_method_new_connection_open_ok (
char * known_hosts                      //  list of known hosts
);

amq_server_method_t *
    amq_server_method_new_connection_close (
int reply_code,                         //  reply code from server
char * reply_text,                      //  localised reply text
int class_id,                           //  failing method class
int method_id                           //  failing method ID
);

amq_server_method_t *
    amq_server_method_new_connection_close_ok (
void);

amq_server_method_t *
    amq_server_method_new_channel_open_ok (
icl_longstr_t * channel_id              //  unique id of the channel
);

amq_server_method_t *
    amq_server_method_new_channel_flow (
Bool active                             //  start/stop content frames
);

amq_server_method_t *
    amq_server_method_new_channel_flow_ok (
Bool active                             //  current flow setting
);

amq_server_method_t *
    amq_server_method_new_channel_close (
int reply_code,                         //  reply code from server
char * reply_text,                      //  localised reply text
int class_id,                           //  failing method class
int method_id                           //  failing method ID
);

amq_server_method_t *
    amq_server_method_new_channel_close_ok (
void);

amq_server_method_t *
    amq_server_method_new_exchange_declare_ok (
void);

amq_server_method_t *
    amq_server_method_new_exchange_delete_ok (
void);

amq_server_method_t *
    amq_server_method_new_queue_declare_ok (
char * queue,                           //  queue name
qbyte message_count,                    //  number of messages in queue
qbyte consumer_count                    //  number of consumers
);

amq_server_method_t *
    amq_server_method_new_queue_bind_ok (
void);

amq_server_method_t *
    amq_server_method_new_queue_purge_ok (
qbyte message_count                     //  number of messages purged
);

amq_server_method_t *
    amq_server_method_new_queue_delete_ok (
qbyte message_count                     //  number of messages purged
);

amq_server_method_t *
    amq_server_method_new_queue_unbind_ok (
void);

amq_server_method_t *
    amq_server_method_new_basic_qos_ok (
void);

amq_server_method_t *
    amq_server_method_new_basic_consume_ok (
char * consumer_tag                     //  consumer tag
);

amq_server_method_t *
    amq_server_method_new_basic_cancel_ok (
char * consumer_tag                     //  consumer tag
);

amq_server_method_t *
    amq_server_method_new_basic_return (
int reply_code,                         //  reply code from server
char * reply_text,                      //  localised reply text
char * exchange,                        //  exchange name
char * routing_key                      //  Message routing key
);

amq_server_method_t *
    amq_server_method_new_basic_deliver (
char * consumer_tag,                    //  consumer tag
int64_t delivery_tag,                   //  server-assigned delivery tag
Bool redelivered,                       //  message is being redelivered
char * exchange,                        //  exchange name
char * routing_key                      //  Message routing key
);

amq_server_method_t *
    amq_server_method_new_basic_get_ok (
int64_t delivery_tag,                   //  server-assigned delivery tag
Bool redelivered,                       //  message is being redelivered
char * exchange,                        //  exchange name
char * routing_key,                     //  Message routing key
qbyte message_count                     //  number of messages pending
);

amq_server_method_t *
    amq_server_method_new_basic_get_empty (
char * sender_id                        //  Sender id
);

amq_server_method_t *
    amq_server_method_new_direct_put_ok (
char * lease                            //  Lease for connection
);

amq_server_method_t *
    amq_server_method_new_direct_get_ok (
char * lease                            //  Lease for connection
);

ipr_bucket_t *
    amq_server_method_encode (
amq_server_method_t * self              //  Method reference
);

amq_server_method_t *
    amq_server_method_decode (
ipr_bucket_t * bucket,                  //  New bucket
char * strerror                         //  Error text, if any
);

int
    amq_server_method_dump (
amq_server_method_t * self,             //  Reference to object
smt_log_t * log,                        //  Log file, if any
char * prefix                           //  Prefix for line
);

int
    amq_server_method_execute (
amq_server_method_t * self,             //  Reference to object
amq_server_connection_t * connection,   //  Current connection object, or null (if internal execution)
amq_server_channel_t * channel          //  Current channel object, or null (if no channel opened)
);

void
    amq_server_method_selftest (
void);

#define amq_server_method_show(item,opcode,trace_file)  amq_server_method_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_server_method_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_server_method_destroy(self)  amq_server_method_destroy_ (self, __FILE__, __LINE__)
void
    amq_server_method_destroy_ (
amq_server_method_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define amq_server_method_link(self)    amq_server_method_link_ (self, __FILE__, __LINE__)
amq_server_method_t *
    amq_server_method_link_ (
amq_server_method_t * self,             //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_server_method_unlink(self)  amq_server_method_unlink_ (self, __FILE__, __LINE__)
void
    amq_server_method_unlink_ (
amq_server_method_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_server_method_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_server_method_new_in_scope(self_p,_scope)  amq_server_method_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_server_method_new_in_scope_ (
amq_server_method_t * * self_p,         //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_METHOD_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_METHOD_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_SERVER_METHOD_INLINE)
#   define INCLUDE_AMQ_SERVER_METHOD_INLINE
#   define INCLUDE_AMQ_SERVER_METHOD_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "amq_constants.h"
#   include "amq_server_agent.h"
#   include "amq_content_basic.h"
#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_DESTROY)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_INITIALISE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_CONNECTION_START)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_CONNECTION_SECURE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_CONNECTION_TUNE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_CONNECTION_OPEN_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_CONNECTION_CLOSE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_CONNECTION_CLOSE_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_CHANNEL_OPEN_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_CHANNEL_FLOW)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_CHANNEL_FLOW_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_CHANNEL_CLOSE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_CHANNEL_CLOSE_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_EXCHANGE_DECLARE_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_EXCHANGE_DELETE_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_QUEUE_DECLARE_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_QUEUE_BIND_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_QUEUE_PURGE_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_QUEUE_DELETE_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_QUEUE_UNBIND_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_BASIC_QOS_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_BASIC_CONSUME_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_BASIC_CANCEL_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_BASIC_RETURN)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_BASIC_DELIVER)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_BASIC_GET_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_BASIC_GET_EMPTY)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_DIRECT_PUT_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_DIRECT_GET_OK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_ENCODE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_DECODE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_DUMP)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_EXECUTE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_SELFTEST)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_SHOW)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_ALLOC)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_FREE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_LINK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_UNLINK)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_ANIMATE)   || defined (BASE_TRACE_AMQ_SERVER_METHOD_NEW_IN_SCOPE) )
void
    amq_server_method_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_METHOD_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_METHOD_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_SERVER_METHOD_ROOT
#   endif
# endif
#endif
