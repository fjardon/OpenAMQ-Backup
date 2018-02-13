<?xml?>
<!--
    *** GENERATED FROM amq_server.asl BY ASL_GEN USING GSL/4 ***

    
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
 -->
<class
    name      = "amq_server_method"
    comment   = "Protocol method for server chassis"
    version   = "1.0"
    script    = "icl_gen"
    license   = "gpl"
    >
<doc>
This class holds a method.  All protocol methods are held in a single
union that can be processed as a single entity.
</doc>

<inherit class = "icl_object">
    <option name = "alloc"   value = "cache" />
    <option name = "nullify" value = "0" />
    <option name = "links"   value = "1" />
</inherit>
<inherit class = "icl_init" />

<import class = "asl" />
<import class = "asl_field" />
<import class = "smt_log" />
<import class = "amq_constants" />
<import class = "amq_server_agent" />
<import class = "amq_content_basic"/>
<import class = "amq_server_classes" />

<context>
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
</context>

<public name = "header">
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
</public>

<public>
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

</public>

<private>
static ipr_regexp_t
    *s_regexp_connection_virtual_host = NULL;
static ipr_regexp_t
    *s_regexp_exchange_exchange = NULL;
static ipr_regexp_t
    *s_regexp_exchange_type = NULL;
static ipr_regexp_t
    *s_regexp_queue_queue = NULL;
</private>

<method name = "new">
    self->class_id  = 0;
    self->method_id = 0;
    self->name      = NULL;
    self->sync      = FALSE;
    self->content   = NULL;
</method>

<method name = "destroy">
    if (self->class_id == AMQ_SERVER_CONNECTION) {
        if (self->method_id == AMQ_SERVER_CONNECTION_START) {
            icl_longstr_destroy (&self->payload.connection_start.server_properties);
            icl_longstr_destroy (&self->payload.connection_start.mechanisms);
            icl_longstr_destroy (&self->payload.connection_start.locales);
        }
        else
        if (self->method_id == AMQ_SERVER_CONNECTION_START_OK) {
            icl_longstr_destroy (&self->payload.connection_start_ok.client_properties);
            icl_longstr_destroy (&self->payload.connection_start_ok.response);
        }
        else
        if (self->method_id == AMQ_SERVER_CONNECTION_SECURE) {
            icl_longstr_destroy (&self->payload.connection_secure.challenge);
        }
        else
        if (self->method_id == AMQ_SERVER_CONNECTION_SECURE_OK) {
            icl_longstr_destroy (&self->payload.connection_secure_ok.response);
        }
    }
    else
    if (self->class_id == AMQ_SERVER_CHANNEL) {
        if (self->method_id == AMQ_SERVER_CHANNEL_OPEN_OK) {
            icl_longstr_destroy (&self->payload.channel_open_ok.channel_id);
        }
    }
    else
    if (self->class_id == AMQ_SERVER_EXCHANGE) {
        if (self->method_id == AMQ_SERVER_EXCHANGE_DECLARE) {
            icl_longstr_destroy (&self->payload.exchange_declare.arguments);
        }
    }
    else
    if (self->class_id == AMQ_SERVER_QUEUE) {
        if (self->method_id == AMQ_SERVER_QUEUE_DECLARE) {
            icl_longstr_destroy (&self->payload.queue_declare.arguments);
        }
        else
        if (self->method_id == AMQ_SERVER_QUEUE_BIND) {
            icl_longstr_destroy (&self->payload.queue_bind.arguments);
        }
        else
        if (self->method_id == AMQ_SERVER_QUEUE_UNBIND) {
            icl_longstr_destroy (&self->payload.queue_unbind.arguments);
        }
    }
    else
    if (self->class_id == AMQ_SERVER_BASIC) {
        amq_content_basic_unlink ((amq_content_basic_t **) &self->content);
        if (self->method_id == AMQ_SERVER_BASIC_CONSUME) {
            icl_longstr_destroy (&self->payload.basic_consume.arguments);
        }
    }
    else
    assert (!self->content);            //  Non-destroyed content = error
</method>

<method name = "initialise">
    s_regexp_connection_virtual_host = ipr_regexp_new ("^[a-zA-Z0-9/-_]+$");
    s_regexp_exchange_exchange = ipr_regexp_new ("^[a-zA-Z0-9-_.:/]+$");
    s_regexp_exchange_type = ipr_regexp_new ("^[a-zA-Z0-9-_.:/]+$");
    s_regexp_queue_queue = ipr_regexp_new ("^[a-zA-Z0-9-_.:/]*$");
</method>

<method name = "terminate">
    ipr_regexp_destroy (&s_regexp_connection_virtual_host);
    ipr_regexp_destroy (&s_regexp_exchange_exchange);
    ipr_regexp_destroy (&s_regexp_exchange_type);
    ipr_regexp_destroy (&s_regexp_queue_queue);
</method>

<method name = "new connection start" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "version_major"  type = "int">protocol major version</argument>
    <argument name = "version_minor"  type = "int">protocol major version</argument>
    <argument name = "server_properties"  type = "icl_longstr_t *">server properties</argument>
    <argument name = "mechanisms"    type = "icl_longstr_t *">available security mechanisms</argument>
    <argument name = "locales"       type = "icl_longstr_t *">available message locales</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_connection_start_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.connection_start;
    self->class_id  = AMQ_SERVER_CONNECTION;
    self->method_id = AMQ_SERVER_CONNECTION_START;
    self->name      = "connection.start";

    //  Copy supplied values to method object
    method->version_major   = (byte) version_major;
    method->version_minor   = (byte) version_minor;
    if (server_properties)
        method->server_properties  = icl_longstr_dup (server_properties);
    else
        method->server_properties  = NULL;
    if (mechanisms)
        method->mechanisms  = icl_longstr_dup (mechanisms);
    else
        method->mechanisms  = NULL;
    if (locales)
        method->locales     = icl_longstr_dup (locales);
    else
        method->locales     = NULL;
</method>

<method name = "new connection secure" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "challenge"     type = "icl_longstr_t *">security challenge data</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_connection_secure_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.connection_secure;
    self->class_id  = AMQ_SERVER_CONNECTION;
    self->method_id = AMQ_SERVER_CONNECTION_SECURE;
    self->name      = "connection.secure";

    //  Copy supplied values to method object
    if (challenge)
        method->challenge   = icl_longstr_dup (challenge);
    else
        method->challenge   = NULL;
</method>

<method name = "new connection tune" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "channel_max"   type = "int">proposed maximum channels</argument>
    <argument name = "frame_max"     type = "qbyte">proposed maximum frame size</argument>
    <argument name = "heartbeat"     type = "int">desired heartbeat delay</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_connection_tune_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.connection_tune;
    self->class_id  = AMQ_SERVER_CONNECTION;
    self->method_id = AMQ_SERVER_CONNECTION_TUNE;
    self->name      = "connection.tune";

    //  Copy supplied values to method object
    method->channel_max     = (dbyte) channel_max;
    method->frame_max       = frame_max;
    method->heartbeat       = (dbyte) heartbeat;
</method>

<method name = "new connection open-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "known_hosts"   type = "char *">list of known hosts</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_connection_open_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.connection_open_ok;
    self->class_id  = AMQ_SERVER_CONNECTION;
    self->method_id = AMQ_SERVER_CONNECTION_OPEN_OK;
    self->name      = "connection.open_ok";

    //  Copy supplied values to method object
    icl_shortstr_cpy (method->known_hosts,   known_hosts);
</method>

<method name = "new connection close" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "reply_code"    type = "int">reply code from server</argument>
    <argument name = "reply_text"    type = "char *">localised reply text</argument>
    <argument name = "class_id"      type = "int">failing method class</argument>
    <argument name = "method_id"     type = "int">failing method ID</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_connection_close_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.connection_close;
    self->class_id  = AMQ_SERVER_CONNECTION;
    self->method_id = AMQ_SERVER_CONNECTION_CLOSE;
    self->name      = "connection.close";

    //  Copy supplied values to method object
    method->reply_code      = (dbyte) reply_code;
    method->class_id        = (dbyte) class_id;
    method->method_id       = (dbyte) method_id;
    icl_shortstr_cpy (method->reply_text,    reply_text);
</method>

<method name = "new connection close-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_connection_close_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.connection_close_ok;
    self->class_id  = AMQ_SERVER_CONNECTION;
    self->method_id = AMQ_SERVER_CONNECTION_CLOSE_OK;
    self->name      = "connection.close_ok";

    //  Copy supplied values to method object
</method>

<method name = "new channel open-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "channel_id"    type = "icl_longstr_t *">unique id of the channel</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_channel_open_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.channel_open_ok;
    self->class_id  = AMQ_SERVER_CHANNEL;
    self->method_id = AMQ_SERVER_CHANNEL_OPEN_OK;
    self->name      = "channel.open_ok";

    //  Copy supplied values to method object
    if (channel_id)
        method->channel_id  = icl_longstr_dup (channel_id);
    else
        method->channel_id  = NULL;
</method>

<method name = "new channel flow" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "active"        type = "Bool">start/stop content frames</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_channel_flow_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.channel_flow;
    self->class_id  = AMQ_SERVER_CHANNEL;
    self->method_id = AMQ_SERVER_CHANNEL_FLOW;
    self->name      = "channel.flow";

    //  Copy supplied values to method object
    method->active          = active;
</method>

<method name = "new channel flow-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "active"        type = "Bool">current flow setting</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_channel_flow_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.channel_flow_ok;
    self->class_id  = AMQ_SERVER_CHANNEL;
    self->method_id = AMQ_SERVER_CHANNEL_FLOW_OK;
    self->name      = "channel.flow_ok";

    //  Copy supplied values to method object
    method->active          = active;
</method>

<method name = "new channel close" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "reply_code"    type = "int">reply code from server</argument>
    <argument name = "reply_text"    type = "char *">localised reply text</argument>
    <argument name = "class_id"      type = "int">failing method class</argument>
    <argument name = "method_id"     type = "int">failing method ID</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_channel_close_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.channel_close;
    self->class_id  = AMQ_SERVER_CHANNEL;
    self->method_id = AMQ_SERVER_CHANNEL_CLOSE;
    self->name      = "channel.close";

    //  Copy supplied values to method object
    method->reply_code      = (dbyte) reply_code;
    method->class_id        = (dbyte) class_id;
    method->method_id       = (dbyte) method_id;
    icl_shortstr_cpy (method->reply_text,    reply_text);
</method>

<method name = "new channel close-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_channel_close_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.channel_close_ok;
    self->class_id  = AMQ_SERVER_CHANNEL;
    self->method_id = AMQ_SERVER_CHANNEL_CLOSE_OK;
    self->name      = "channel.close_ok";

    //  Copy supplied values to method object
</method>

<method name = "new exchange declare-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_exchange_declare_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.exchange_declare_ok;
    self->class_id  = AMQ_SERVER_EXCHANGE;
    self->method_id = AMQ_SERVER_EXCHANGE_DECLARE_OK;
    self->name      = "exchange.declare_ok";

    //  Copy supplied values to method object
</method>

<method name = "new exchange delete-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_exchange_delete_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.exchange_delete_ok;
    self->class_id  = AMQ_SERVER_EXCHANGE;
    self->method_id = AMQ_SERVER_EXCHANGE_DELETE_OK;
    self->name      = "exchange.delete_ok";

    //  Copy supplied values to method object
</method>

<method name = "new queue declare-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "queue"         type = "char *">queue name</argument>
    <argument name = "message_count"  type = "qbyte">number of messages in queue</argument>
    <argument name = "consumer_count"  type = "qbyte">number of consumers</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_queue_declare_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.queue_declare_ok;
    self->class_id  = AMQ_SERVER_QUEUE;
    self->method_id = AMQ_SERVER_QUEUE_DECLARE_OK;
    self->name      = "queue.declare_ok";

    //  Copy supplied values to method object
    method->message_count   = message_count;
    method->consumer_count  = consumer_count;
    icl_shortstr_cpy (method->queue,         queue);
</method>

<method name = "new queue bind-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_queue_bind_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.queue_bind_ok;
    self->class_id  = AMQ_SERVER_QUEUE;
    self->method_id = AMQ_SERVER_QUEUE_BIND_OK;
    self->name      = "queue.bind_ok";

    //  Copy supplied values to method object
</method>

<method name = "new queue purge-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "message_count"  type = "qbyte">number of messages purged</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_queue_purge_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.queue_purge_ok;
    self->class_id  = AMQ_SERVER_QUEUE;
    self->method_id = AMQ_SERVER_QUEUE_PURGE_OK;
    self->name      = "queue.purge_ok";

    //  Copy supplied values to method object
    method->message_count   = message_count;
</method>

<method name = "new queue delete-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "message_count"  type = "qbyte">number of messages purged</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_queue_delete_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.queue_delete_ok;
    self->class_id  = AMQ_SERVER_QUEUE;
    self->method_id = AMQ_SERVER_QUEUE_DELETE_OK;
    self->name      = "queue.delete_ok";

    //  Copy supplied values to method object
    method->message_count   = message_count;
</method>

<method name = "new queue unbind-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_queue_unbind_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.queue_unbind_ok;
    self->class_id  = AMQ_SERVER_QUEUE;
    self->method_id = AMQ_SERVER_QUEUE_UNBIND_OK;
    self->name      = "queue.unbind_ok";

    //  Copy supplied values to method object
</method>

<method name = "new basic qos-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_basic_qos_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.basic_qos_ok;
    self->class_id  = AMQ_SERVER_BASIC;
    self->method_id = AMQ_SERVER_BASIC_QOS_OK;
    self->name      = "basic.qos_ok";

    //  Copy supplied values to method object
</method>

<method name = "new basic consume-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "consumer_tag"  type = "char *">consumer tag</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_basic_consume_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.basic_consume_ok;
    self->class_id  = AMQ_SERVER_BASIC;
    self->method_id = AMQ_SERVER_BASIC_CONSUME_OK;
    self->name      = "basic.consume_ok";

    //  Copy supplied values to method object
    icl_shortstr_cpy (method->consumer_tag,  consumer_tag);
</method>

<method name = "new basic cancel-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "consumer_tag"  type = "char *">consumer tag</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_basic_cancel_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.basic_cancel_ok;
    self->class_id  = AMQ_SERVER_BASIC;
    self->method_id = AMQ_SERVER_BASIC_CANCEL_OK;
    self->name      = "basic.cancel_ok";

    //  Copy supplied values to method object
    icl_shortstr_cpy (method->consumer_tag,  consumer_tag);
</method>

<method name = "new basic return" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "reply_code"    type = "int">reply code from server</argument>
    <argument name = "reply_text"    type = "char *">localised reply text</argument>
    <argument name = "exchange"      type = "char *">exchange name</argument>
    <argument name = "routing_key"   type = "char *">Message routing key</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_basic_return_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.basic_return;
    self->class_id  = AMQ_SERVER_BASIC;
    self->method_id = AMQ_SERVER_BASIC_RETURN;
    self->name      = "basic.return";

    //  Copy supplied values to method object
    method->reply_code      = (dbyte) reply_code;
    icl_shortstr_cpy (method->reply_text,    reply_text);
    icl_shortstr_cpy (method->exchange,      exchange);
    icl_shortstr_cpy (method->routing_key,   routing_key);
</method>

<method name = "new basic deliver" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "consumer_tag"  type = "char *">consumer tag</argument>
    <argument name = "delivery_tag"  type = "int64_t">server-assigned delivery tag</argument>
    <argument name = "redelivered"   type = "Bool">message is being redelivered</argument>
    <argument name = "exchange"      type = "char *">exchange name</argument>
    <argument name = "routing_key"   type = "char *">Message routing key</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_basic_deliver_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.basic_deliver;
    self->class_id  = AMQ_SERVER_BASIC;
    self->method_id = AMQ_SERVER_BASIC_DELIVER;
    self->name      = "basic.deliver";

    //  Copy supplied values to method object
    method->delivery_tag    = delivery_tag;
    method->redelivered     = redelivered;
    icl_shortstr_cpy (method->consumer_tag,  consumer_tag);
    icl_shortstr_cpy (method->exchange,      exchange);
    icl_shortstr_cpy (method->routing_key,   routing_key);
</method>

<method name = "new basic get-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "delivery_tag"  type = "int64_t">server-assigned delivery tag</argument>
    <argument name = "redelivered"   type = "Bool">message is being redelivered</argument>
    <argument name = "exchange"      type = "char *">exchange name</argument>
    <argument name = "routing_key"   type = "char *">Message routing key</argument>
    <argument name = "message_count"  type = "qbyte">number of messages pending</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_basic_get_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.basic_get_ok;
    self->class_id  = AMQ_SERVER_BASIC;
    self->method_id = AMQ_SERVER_BASIC_GET_OK;
    self->name      = "basic.get_ok";

    //  Copy supplied values to method object
    method->delivery_tag    = delivery_tag;
    method->redelivered     = redelivered;
    method->message_count   = message_count;
    icl_shortstr_cpy (method->exchange,      exchange);
    icl_shortstr_cpy (method->routing_key,   routing_key);
</method>

<method name = "new basic get-empty" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "sender_id"     type = "char *">Sender id</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_basic_get_empty_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.basic_get_empty;
    self->class_id  = AMQ_SERVER_BASIC;
    self->method_id = AMQ_SERVER_BASIC_GET_EMPTY;
    self->name      = "basic.get_empty";

    //  Copy supplied values to method object
    icl_shortstr_cpy (method->sender_id,     sender_id);
</method>

<method name = "new direct put-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "lease"         type = "char *">Lease for connection</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_direct_put_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.direct_put_ok;
    self->class_id  = AMQ_SERVER_DIRECT;
    self->method_id = AMQ_SERVER_DIRECT_PUT_OK;
    self->name      = "direct.put_ok";

    //  Copy supplied values to method object
    icl_shortstr_cpy (method->lease,         lease);
</method>

<method name = "new direct get-ok" return = "self">
    <doc>
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    </doc>
    <argument name = "lease"         type = "char *">Lease for connection</argument>
    <declare name = "self" type = "$(selftype) *">New method</declare>
    <local>
    amq_server_direct_get_ok_t
        *method;
    </local>
    //
    self   = self_new ();
    method = &self->payload.direct_get_ok;
    self->class_id  = AMQ_SERVER_DIRECT;
    self->method_id = AMQ_SERVER_DIRECT_GET_OK;
    self->name      = "direct.get_ok";

    //  Copy supplied values to method object
    icl_shortstr_cpy (method->lease,         lease);
</method>

<method name = "encode" return = "bucket">
    <doc>
    Encodes a amq_server_method_t object into a memory bucket.
    Allocates a fresh bucket and returns this.  Returns NULL if there
    was an error encoding the method object.  The supplied bucket ends
    in a frame-end octet, for symmetry with the decode method.
    </doc>
    <argument name = "self" type = "$(selftype) *">Method reference</argument>
    <declare name = "bucket" type = "ipr_bucket_t *" default = "NULL">New bucket</declare>
    <local>
    byte
        *data_target = NULL;
    size_t
        string_size = 0;
    byte
        bit_string = 0;
    </local>
    //
    $(selfname:upper)_ASSERT_SANE (self);
    assert (self->class_id);
    assert (self->method_id);

    switch (self->class_id) {
        case AMQ_SERVER_CONNECTION:
            switch (self->method_id) {
                case AMQ_SERVER_CONNECTION_START:
                    bucket = ipr_bucket_new (12
                                + (self->payload.connection_start.server_properties?
                                   self->payload.connection_start.server_properties->cur_size: 0)
                                + (self->payload.connection_start.mechanisms?
                                   self->payload.connection_start.mechanisms->cur_size: 0)
                                + (self->payload.connection_start.locales?
                                   self->payload.connection_start.locales->cur_size: 0) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_OCTET (data_target, self->payload.connection_start.version_major);
                    PUT_OCTET (data_target, self->payload.connection_start.version_minor);
                    PUT_TABLE (data_target, self->payload.connection_start.server_properties);
                    PUT_LSTR  (data_target, self->payload.connection_start.mechanisms);
                    PUT_LSTR  (data_target, self->payload.connection_start.locales);
                    break;
                case AMQ_SERVER_CONNECTION_START_OK:
                    bucket = ipr_bucket_new (10
                                + (self->payload.connection_start_ok.client_properties?
                                   self->payload.connection_start_ok.client_properties->cur_size: 0)
                                + strlen (self->payload.connection_start_ok.mechanism)
                                + (self->payload.connection_start_ok.response?
                                   self->payload.connection_start_ok.response->cur_size: 0)
                                + strlen (self->payload.connection_start_ok.locale) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_TABLE (data_target, self->payload.connection_start_ok.client_properties);
                    PUT_SSTR  (data_target, self->payload.connection_start_ok.mechanism);
                    PUT_LSTR  (data_target, self->payload.connection_start_ok.response);
                    PUT_SSTR  (data_target, self->payload.connection_start_ok.locale);
                    break;
                case AMQ_SERVER_CONNECTION_SECURE:
                    bucket = ipr_bucket_new (6
                                + (self->payload.connection_secure.challenge?
                                   self->payload.connection_secure.challenge->cur_size: 0) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_LSTR  (data_target, self->payload.connection_secure.challenge);
                    break;
                case AMQ_SERVER_CONNECTION_SECURE_OK:
                    bucket = ipr_bucket_new (6
                                + (self->payload.connection_secure_ok.response?
                                   self->payload.connection_secure_ok.response->cur_size: 0) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_LSTR  (data_target, self->payload.connection_secure_ok.response);
                    break;
                case AMQ_SERVER_CONNECTION_TUNE:
                    bucket = ipr_bucket_new (12 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.connection_tune.channel_max);
                    PUT_LONG  (data_target, self->payload.connection_tune.frame_max);
                    PUT_SHORT (data_target, self->payload.connection_tune.heartbeat);
                    break;
                case AMQ_SERVER_CONNECTION_TUNE_OK:
                    bucket = ipr_bucket_new (12 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.connection_tune_ok.channel_max);
                    PUT_LONG  (data_target, self->payload.connection_tune_ok.frame_max);
                    PUT_SHORT (data_target, self->payload.connection_tune_ok.heartbeat);
                    break;
                case AMQ_SERVER_CONNECTION_OPEN:
                    bucket = ipr_bucket_new (7
                                + strlen (self->payload.connection_open.virtual_host)
                                + strlen (self->payload.connection_open.capabilities) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.connection_open.virtual_host);
                    PUT_SSTR  (data_target, self->payload.connection_open.capabilities);
                    bit_string |= (self->payload.connection_open.insist & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
                case AMQ_SERVER_CONNECTION_OPEN_OK:
                    bucket = ipr_bucket_new (5
                                + strlen (self->payload.connection_open_ok.known_hosts) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.connection_open_ok.known_hosts);
                    break;
                case AMQ_SERVER_CONNECTION_CLOSE:
                    bucket = ipr_bucket_new (11
                                + strlen (self->payload.connection_close.reply_text) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.connection_close.reply_code);
                    PUT_SSTR  (data_target, self->payload.connection_close.reply_text);
                    PUT_SHORT (data_target, self->payload.connection_close.class_id);
                    PUT_SHORT (data_target, self->payload.connection_close.method_id);
                    break;
                case AMQ_SERVER_CONNECTION_CLOSE_OK:
                    bucket = ipr_bucket_new (4 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    break;
            }
            break;
        case AMQ_SERVER_CHANNEL:
            switch (self->method_id) {
                case AMQ_SERVER_CHANNEL_OPEN:
                    bucket = ipr_bucket_new (5
                                + strlen (self->payload.channel_open.out_of_band) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.channel_open.out_of_band);
                    break;
                case AMQ_SERVER_CHANNEL_OPEN_OK:
                    bucket = ipr_bucket_new (6
                                + (self->payload.channel_open_ok.channel_id?
                                   self->payload.channel_open_ok.channel_id->cur_size: 0) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_LSTR  (data_target, self->payload.channel_open_ok.channel_id);
                    break;
                case AMQ_SERVER_CHANNEL_FLOW:
                    bucket = ipr_bucket_new (5 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    bit_string |= (self->payload.channel_flow.active & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
                case AMQ_SERVER_CHANNEL_FLOW_OK:
                    bucket = ipr_bucket_new (5 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    bit_string |= (self->payload.channel_flow_ok.active & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
                case AMQ_SERVER_CHANNEL_CLOSE:
                    bucket = ipr_bucket_new (11
                                + strlen (self->payload.channel_close.reply_text) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.channel_close.reply_code);
                    PUT_SSTR  (data_target, self->payload.channel_close.reply_text);
                    PUT_SHORT (data_target, self->payload.channel_close.class_id);
                    PUT_SHORT (data_target, self->payload.channel_close.method_id);
                    break;
                case AMQ_SERVER_CHANNEL_CLOSE_OK:
                    bucket = ipr_bucket_new (4 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    break;
            }
            break;
        case AMQ_SERVER_EXCHANGE:
            switch (self->method_id) {
                case AMQ_SERVER_EXCHANGE_DECLARE:
                    bucket = ipr_bucket_new (11
                                + strlen (self->payload.exchange_declare.exchange)
                                + strlen (self->payload.exchange_declare.type)
                                + (self->payload.exchange_declare.arguments?
                                   self->payload.exchange_declare.arguments->cur_size: 0) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.exchange_declare.ticket);
                    PUT_SSTR  (data_target, self->payload.exchange_declare.exchange);
                    PUT_SSTR  (data_target, self->payload.exchange_declare.type);
                    bit_string |= (self->payload.exchange_declare.passive & 1) &lt;&lt; 0;
                    bit_string |= (self->payload.exchange_declare.durable & 1) &lt;&lt; 1;
                    bit_string |= (self->payload.exchange_declare.auto_delete & 1) &lt;&lt; 2;
                    bit_string |= (self->payload.exchange_declare.internal & 1) &lt;&lt; 3;
                    bit_string |= (self->payload.exchange_declare.nowait & 1) &lt;&lt; 4;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    PUT_TABLE (data_target, self->payload.exchange_declare.arguments);
                    break;
                case AMQ_SERVER_EXCHANGE_DECLARE_OK:
                    bucket = ipr_bucket_new (4 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    break;
                case AMQ_SERVER_EXCHANGE_DELETE:
                    bucket = ipr_bucket_new (8
                                + strlen (self->payload.exchange_delete.exchange) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.exchange_delete.ticket);
                    PUT_SSTR  (data_target, self->payload.exchange_delete.exchange);
                    bit_string |= (self->payload.exchange_delete.if_unused & 1) &lt;&lt; 0;
                    bit_string |= (self->payload.exchange_delete.nowait & 1) &lt;&lt; 1;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
                case AMQ_SERVER_EXCHANGE_DELETE_OK:
                    bucket = ipr_bucket_new (4 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    break;
            }
            break;
        case AMQ_SERVER_QUEUE:
            switch (self->method_id) {
                case AMQ_SERVER_QUEUE_DECLARE:
                    bucket = ipr_bucket_new (10
                                + strlen (self->payload.queue_declare.queue)
                                + (self->payload.queue_declare.arguments?
                                   self->payload.queue_declare.arguments->cur_size: 0) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.queue_declare.ticket);
                    PUT_SSTR  (data_target, self->payload.queue_declare.queue);
                    bit_string |= (self->payload.queue_declare.passive & 1) &lt;&lt; 0;
                    bit_string |= (self->payload.queue_declare.durable & 1) &lt;&lt; 1;
                    bit_string |= (self->payload.queue_declare.exclusive & 1) &lt;&lt; 2;
                    bit_string |= (self->payload.queue_declare.auto_delete & 1) &lt;&lt; 3;
                    bit_string |= (self->payload.queue_declare.nowait & 1) &lt;&lt; 4;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    PUT_TABLE (data_target, self->payload.queue_declare.arguments);
                    break;
                case AMQ_SERVER_QUEUE_DECLARE_OK:
                    bucket = ipr_bucket_new (13
                                + strlen (self->payload.queue_declare_ok.queue) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.queue_declare_ok.queue);
                    PUT_LONG  (data_target, self->payload.queue_declare_ok.message_count);
                    PUT_LONG  (data_target, self->payload.queue_declare_ok.consumer_count);
                    break;
                case AMQ_SERVER_QUEUE_BIND:
                    bucket = ipr_bucket_new (12
                                + strlen (self->payload.queue_bind.queue)
                                + strlen (self->payload.queue_bind.exchange)
                                + strlen (self->payload.queue_bind.routing_key)
                                + (self->payload.queue_bind.arguments?
                                   self->payload.queue_bind.arguments->cur_size: 0) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.queue_bind.ticket);
                    PUT_SSTR  (data_target, self->payload.queue_bind.queue);
                    PUT_SSTR  (data_target, self->payload.queue_bind.exchange);
                    PUT_SSTR  (data_target, self->payload.queue_bind.routing_key);
                    bit_string |= (self->payload.queue_bind.nowait & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    PUT_TABLE (data_target, self->payload.queue_bind.arguments);
                    break;
                case AMQ_SERVER_QUEUE_BIND_OK:
                    bucket = ipr_bucket_new (4 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    break;
                case AMQ_SERVER_QUEUE_PURGE:
                    bucket = ipr_bucket_new (8
                                + strlen (self->payload.queue_purge.queue) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.queue_purge.ticket);
                    PUT_SSTR  (data_target, self->payload.queue_purge.queue);
                    bit_string |= (self->payload.queue_purge.nowait & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
                case AMQ_SERVER_QUEUE_PURGE_OK:
                    bucket = ipr_bucket_new (8 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_LONG  (data_target, self->payload.queue_purge_ok.message_count);
                    break;
                case AMQ_SERVER_QUEUE_DELETE:
                    bucket = ipr_bucket_new (8
                                + strlen (self->payload.queue_delete.queue) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.queue_delete.ticket);
                    PUT_SSTR  (data_target, self->payload.queue_delete.queue);
                    bit_string |= (self->payload.queue_delete.if_unused & 1) &lt;&lt; 0;
                    bit_string |= (self->payload.queue_delete.if_empty & 1) &lt;&lt; 1;
                    bit_string |= (self->payload.queue_delete.nowait & 1) &lt;&lt; 2;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
                case AMQ_SERVER_QUEUE_DELETE_OK:
                    bucket = ipr_bucket_new (8 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_LONG  (data_target, self->payload.queue_delete_ok.message_count);
                    break;
                case AMQ_SERVER_QUEUE_UNBIND:
                    bucket = ipr_bucket_new (12
                                + strlen (self->payload.queue_unbind.queue)
                                + strlen (self->payload.queue_unbind.exchange)
                                + strlen (self->payload.queue_unbind.routing_key)
                                + (self->payload.queue_unbind.arguments?
                                   self->payload.queue_unbind.arguments->cur_size: 0) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.queue_unbind.ticket);
                    PUT_SSTR  (data_target, self->payload.queue_unbind.queue);
                    PUT_SSTR  (data_target, self->payload.queue_unbind.exchange);
                    PUT_SSTR  (data_target, self->payload.queue_unbind.routing_key);
                    bit_string |= (self->payload.queue_unbind.nowait & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    PUT_TABLE (data_target, self->payload.queue_unbind.arguments);
                    break;
                case AMQ_SERVER_QUEUE_UNBIND_OK:
                    bucket = ipr_bucket_new (4 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    break;
            }
            break;
        case AMQ_SERVER_BASIC:
            switch (self->method_id) {
                case AMQ_SERVER_BASIC_QOS:
                    bucket = ipr_bucket_new (11 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_LONG  (data_target, self->payload.basic_qos.prefetch_size);
                    PUT_SHORT (data_target, self->payload.basic_qos.prefetch_count);
                    bit_string |= (self->payload.basic_qos.global & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
                case AMQ_SERVER_BASIC_QOS_OK:
                    bucket = ipr_bucket_new (4 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    break;
                case AMQ_SERVER_BASIC_CONSUME:
                    bucket = ipr_bucket_new (11
                                + strlen (self->payload.basic_consume.queue)
                                + strlen (self->payload.basic_consume.consumer_tag)
                                + (self->payload.basic_consume.arguments?
                                   self->payload.basic_consume.arguments->cur_size: 0) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.basic_consume.ticket);
                    PUT_SSTR  (data_target, self->payload.basic_consume.queue);
                    PUT_SSTR  (data_target, self->payload.basic_consume.consumer_tag);
                    bit_string |= (self->payload.basic_consume.no_local & 1) &lt;&lt; 0;
                    bit_string |= (self->payload.basic_consume.no_ack & 1) &lt;&lt; 1;
                    bit_string |= (self->payload.basic_consume.exclusive & 1) &lt;&lt; 2;
                    bit_string |= (self->payload.basic_consume.nowait & 1) &lt;&lt; 3;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    PUT_TABLE (data_target, self->payload.basic_consume.arguments);
                    break;
                case AMQ_SERVER_BASIC_CONSUME_OK:
                    bucket = ipr_bucket_new (5
                                + strlen (self->payload.basic_consume_ok.consumer_tag) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.basic_consume_ok.consumer_tag);
                    break;
                case AMQ_SERVER_BASIC_CANCEL:
                    bucket = ipr_bucket_new (6
                                + strlen (self->payload.basic_cancel.consumer_tag) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.basic_cancel.consumer_tag);
                    bit_string |= (self->payload.basic_cancel.nowait & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
                case AMQ_SERVER_BASIC_CANCEL_OK:
                    bucket = ipr_bucket_new (5
                                + strlen (self->payload.basic_cancel_ok.consumer_tag) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.basic_cancel_ok.consumer_tag);
                    break;
                case AMQ_SERVER_BASIC_PUBLISH:
                    bucket = ipr_bucket_new (9
                                + strlen (self->payload.basic_publish.exchange)
                                + strlen (self->payload.basic_publish.routing_key) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.basic_publish.ticket);
                    PUT_SSTR  (data_target, self->payload.basic_publish.exchange);
                    PUT_SSTR  (data_target, self->payload.basic_publish.routing_key);
                    bit_string |= (self->payload.basic_publish.mandatory & 1) &lt;&lt; 0;
                    bit_string |= (self->payload.basic_publish.immediate & 1) &lt;&lt; 1;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
                case AMQ_SERVER_BASIC_RETURN:
                    bucket = ipr_bucket_new (9
                                + strlen (self->payload.basic_return.reply_text)
                                + strlen (self->payload.basic_return.exchange)
                                + strlen (self->payload.basic_return.routing_key) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.basic_return.reply_code);
                    PUT_SSTR  (data_target, self->payload.basic_return.reply_text);
                    PUT_SSTR  (data_target, self->payload.basic_return.exchange);
                    PUT_SSTR  (data_target, self->payload.basic_return.routing_key);
                    break;
                case AMQ_SERVER_BASIC_DELIVER:
                    bucket = ipr_bucket_new (16
                                + strlen (self->payload.basic_deliver.consumer_tag)
                                + strlen (self->payload.basic_deliver.exchange)
                                + strlen (self->payload.basic_deliver.routing_key) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.basic_deliver.consumer_tag);
                    PUT_LLONG (data_target, self->payload.basic_deliver.delivery_tag);
                    bit_string |= (self->payload.basic_deliver.redelivered & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    PUT_SSTR  (data_target, self->payload.basic_deliver.exchange);
                    PUT_SSTR  (data_target, self->payload.basic_deliver.routing_key);
                    break;
                case AMQ_SERVER_BASIC_GET:
                    bucket = ipr_bucket_new (8
                                + strlen (self->payload.basic_get.queue) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SHORT (data_target, self->payload.basic_get.ticket);
                    PUT_SSTR  (data_target, self->payload.basic_get.queue);
                    bit_string |= (self->payload.basic_get.no_ack & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
                case AMQ_SERVER_BASIC_GET_OK:
                    bucket = ipr_bucket_new (19
                                + strlen (self->payload.basic_get_ok.exchange)
                                + strlen (self->payload.basic_get_ok.routing_key) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_LLONG (data_target, self->payload.basic_get_ok.delivery_tag);
                    bit_string |= (self->payload.basic_get_ok.redelivered & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    PUT_SSTR  (data_target, self->payload.basic_get_ok.exchange);
                    PUT_SSTR  (data_target, self->payload.basic_get_ok.routing_key);
                    PUT_LONG  (data_target, self->payload.basic_get_ok.message_count);
                    break;
                case AMQ_SERVER_BASIC_GET_EMPTY:
                    bucket = ipr_bucket_new (5
                                + strlen (self->payload.basic_get_empty.sender_id) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.basic_get_empty.sender_id);
                    break;
                case AMQ_SERVER_BASIC_ACK:
                    bucket = ipr_bucket_new (13 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_LLONG (data_target, self->payload.basic_ack.delivery_tag);
                    bit_string |= (self->payload.basic_ack.multiple & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
                case AMQ_SERVER_BASIC_REJECT:
                    bucket = ipr_bucket_new (13 + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_LLONG (data_target, self->payload.basic_reject.delivery_tag);
                    bit_string |= (self->payload.basic_reject.requeue & 1) &lt;&lt; 0;
                    PUT_OCTET (data_target, bit_string);
                    bit_string = 0;
                    break;
            }
            break;
        case AMQ_SERVER_DIRECT:
            switch (self->method_id) {
                case AMQ_SERVER_DIRECT_PUT:
                    bucket = ipr_bucket_new (5
                                + strlen (self->payload.direct_put.sink) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.direct_put.sink);
                    break;
                case AMQ_SERVER_DIRECT_PUT_OK:
                    bucket = ipr_bucket_new (5
                                + strlen (self->payload.direct_put_ok.lease) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.direct_put_ok.lease);
                    break;
                case AMQ_SERVER_DIRECT_GET:
                    bucket = ipr_bucket_new (5
                                + strlen (self->payload.direct_get.feed) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.direct_get.feed);
                    break;
                case AMQ_SERVER_DIRECT_GET_OK:
                    bucket = ipr_bucket_new (5
                                + strlen (self->payload.direct_get_ok.lease) + 1);
                    data_target = bucket->data;
                    PUT_SHORT (data_target, self->class_id);
                    PUT_SHORT (data_target, self->method_id);
                    PUT_SSTR  (data_target, self->payload.direct_get_ok.lease);
                    break;
            }
            break;
    }
    bucket->cur_size = data_target - bucket->data;
</method>

<method name = "decode" return = "self">
    <doc>
    Decodes a amq_server_method_t object from a memory bucket.
    Allocates a new $(selfname)_t structure and returns this. Returns
    NULL if there was an error decoding the method object.
    </doc>
    <argument name = "bucket"   type = "ipr_bucket_t *">New bucket</argument>
    <argument name = "strerror" type = "char *">Error text, if any</argument>
    <declare name = "self" type = "$(selftype) *">Method reference</declare>
    <local>
    byte
        *data_source,                   //  Pointer into buffer data           
        *data_limit;                    //  Limit of buffer data               
    size_t
        string_size;
    byte
        bit_string = 0;
    </local>
    //
    //  Check that frame is correctly terminated before decoding it            
    assert (bucket);
    self = NULL;
    data_source = bucket->data;
    data_limit  = data_source + bucket->cur_size;

    self = self_new ();
    GET_SHORT (self->class_id,  data_source);
    GET_SHORT (self->method_id, data_source);
    switch (self->class_id) {
        case AMQ_SERVER_CONNECTION:
            switch (self->method_id) {
                case AMQ_SERVER_CONNECTION_START:
                    self->name = "connection.start";
                    self->sync = TRUE;
                    GET_OCTET (self->payload.connection_start.version_major, data_source);
                    GET_OCTET (self->payload.connection_start.version_minor, data_source);
                    GET_LSTR (self->payload.connection_start.server_properties, data_source);
                    GET_LSTR (self->payload.connection_start.mechanisms, data_source);
                    GET_LSTR (self->payload.connection_start.locales, data_source);
                    if (self->payload.connection_start.mechanisms == NULL || self->payload.connection_start.mechanisms->cur_size == 0) {
                        strcpy (strerror, "connection.start: mechanisms field is empty");
                        goto exception;
                    }
                    if (self->payload.connection_start.locales == NULL || self->payload.connection_start.locales->cur_size == 0) {
                        strcpy (strerror, "connection.start: locales field is empty");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_CONNECTION_START_OK:
                    self->name = "connection.start_ok";
                    self->sync = TRUE;
                    GET_LSTR (self->payload.connection_start_ok.client_properties, data_source);
                    GET_SSTR (self->payload.connection_start_ok.mechanism, data_source);
                    GET_LSTR (self->payload.connection_start_ok.response, data_source);
                    GET_SSTR (self->payload.connection_start_ok.locale, data_source);
                    if (*self->payload.connection_start_ok.mechanism == 0) {
                        strcpy (strerror, "connection.start_ok: mechanism field is empty");
                        goto exception;
                    }
                    if (self->payload.connection_start_ok.response == NULL || self->payload.connection_start_ok.response->cur_size == 0) {
                        strcpy (strerror, "connection.start_ok: response field is empty");
                        goto exception;
                    }
                    if (*self->payload.connection_start_ok.locale == 0) {
                        strcpy (strerror, "connection.start_ok: locale field is empty");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_CONNECTION_SECURE:
                    self->name = "connection.secure";
                    self->sync = TRUE;
                    GET_LSTR (self->payload.connection_secure.challenge, data_source);
                    break;
                case AMQ_SERVER_CONNECTION_SECURE_OK:
                    self->name = "connection.secure_ok";
                    self->sync = TRUE;
                    GET_LSTR (self->payload.connection_secure_ok.response, data_source);
                    break;
                case AMQ_SERVER_CONNECTION_TUNE:
                    self->name = "connection.tune";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.connection_tune.channel_max, data_source);
                    GET_LONG  (self->payload.connection_tune.frame_max, data_source);
                    GET_SHORT (self->payload.connection_tune.heartbeat, data_source);
                    break;
                case AMQ_SERVER_CONNECTION_TUNE_OK:
                    self->name = "connection.tune_ok";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.connection_tune_ok.channel_max, data_source);
                    GET_LONG  (self->payload.connection_tune_ok.frame_max, data_source);
                    GET_SHORT (self->payload.connection_tune_ok.heartbeat, data_source);
                    if (self->payload.connection_tune_ok.channel_max == 0) {
                        strcpy (strerror, "connection.tune_ok: channel_max field is empty");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_CONNECTION_OPEN:
                    self->name = "connection.open";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.connection_open.virtual_host, data_source);
                    GET_SSTR (self->payload.connection_open.capabilities, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.connection_open.insist = (bit_string >> 0) & 1;
                    if (!ipr_regexp_match (s_regexp_connection_virtual_host, self->payload.connection_open.virtual_host)) {
                        strcpy (strerror, "connection.open: virtual_host field is invalid");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_CONNECTION_OPEN_OK:
                    self->name = "connection.open_ok";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.connection_open_ok.known_hosts, data_source);
                    break;
                case AMQ_SERVER_CONNECTION_CLOSE:
                    self->name = "connection.close";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.connection_close.reply_code, data_source);
                    GET_SSTR (self->payload.connection_close.reply_text, data_source);
                    GET_SHORT (self->payload.connection_close.class_id, data_source);
                    GET_SHORT (self->payload.connection_close.method_id, data_source);
                    if (self->payload.connection_close.reply_code == 0) {
                        strcpy (strerror, "connection.close: reply_code field is empty");
                        goto exception;
                    }
                    if (*self->payload.connection_close.reply_text == 0) {
                        strcpy (strerror, "connection.close: reply_text field is empty");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_CONNECTION_CLOSE_OK:
                    self->name = "connection.close_ok";
                    self->sync = TRUE;
                    break;
            }
            break;
        case AMQ_SERVER_CHANNEL:
            switch (self->method_id) {
                case AMQ_SERVER_CHANNEL_OPEN:
                    self->name = "channel.open";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.channel_open.out_of_band, data_source);
                    break;
                case AMQ_SERVER_CHANNEL_OPEN_OK:
                    self->name = "channel.open_ok";
                    self->sync = TRUE;
                    GET_LSTR (self->payload.channel_open_ok.channel_id, data_source);
                    break;
                case AMQ_SERVER_CHANNEL_FLOW:
                    self->name = "channel.flow";
                    self->sync = TRUE;
                    GET_OCTET (bit_string, data_source);
                    self->payload.channel_flow.active = (bit_string >> 0) & 1;
                    break;
                case AMQ_SERVER_CHANNEL_FLOW_OK:
                    self->name = "channel.flow_ok";
                    self->sync = FALSE;
                    GET_OCTET (bit_string, data_source);
                    self->payload.channel_flow_ok.active = (bit_string >> 0) & 1;
                    break;
                case AMQ_SERVER_CHANNEL_CLOSE:
                    self->name = "channel.close";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.channel_close.reply_code, data_source);
                    GET_SSTR (self->payload.channel_close.reply_text, data_source);
                    GET_SHORT (self->payload.channel_close.class_id, data_source);
                    GET_SHORT (self->payload.channel_close.method_id, data_source);
                    if (self->payload.channel_close.reply_code == 0) {
                        strcpy (strerror, "channel.close: reply_code field is empty");
                        goto exception;
                    }
                    if (*self->payload.channel_close.reply_text == 0) {
                        strcpy (strerror, "channel.close: reply_text field is empty");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_CHANNEL_CLOSE_OK:
                    self->name = "channel.close_ok";
                    self->sync = TRUE;
                    break;
            }
            break;
        case AMQ_SERVER_EXCHANGE:
            switch (self->method_id) {
                case AMQ_SERVER_EXCHANGE_DECLARE:
                    self->name = "exchange.declare";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.exchange_declare.ticket, data_source);
                    GET_SSTR (self->payload.exchange_declare.exchange, data_source);
                    GET_SSTR (self->payload.exchange_declare.type, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.exchange_declare.passive = (bit_string >> 0) & 1;
                    self->payload.exchange_declare.durable = (bit_string >> 1) & 1;
                    self->payload.exchange_declare.auto_delete = (bit_string >> 2) & 1;
                    self->payload.exchange_declare.internal = (bit_string >> 3) & 1;
                    self->payload.exchange_declare.nowait = (bit_string >> 4) & 1;
                    GET_LSTR (self->payload.exchange_declare.arguments, data_source);
                    if (!ipr_regexp_match (s_regexp_exchange_exchange, self->payload.exchange_declare.exchange)) {
                        strcpy (strerror, "exchange.declare: exchange field is invalid");
                        goto exception;
                    }
                    if (!ipr_regexp_match (s_regexp_exchange_type, self->payload.exchange_declare.type)) {
                        strcpy (strerror, "exchange.declare: type field is invalid");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_EXCHANGE_DECLARE_OK:
                    self->name = "exchange.declare_ok";
                    self->sync = TRUE;
                    break;
                case AMQ_SERVER_EXCHANGE_DELETE:
                    self->name = "exchange.delete";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.exchange_delete.ticket, data_source);
                    GET_SSTR (self->payload.exchange_delete.exchange, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.exchange_delete.if_unused = (bit_string >> 0) & 1;
                    self->payload.exchange_delete.nowait = (bit_string >> 1) & 1;
                    if (*self->payload.exchange_delete.exchange == 0) {
                        strcpy (strerror, "exchange.delete: exchange field is empty");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_EXCHANGE_DELETE_OK:
                    self->name = "exchange.delete_ok";
                    self->sync = TRUE;
                    break;
            }
            break;
        case AMQ_SERVER_QUEUE:
            switch (self->method_id) {
                case AMQ_SERVER_QUEUE_DECLARE:
                    self->name = "queue.declare";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.queue_declare.ticket, data_source);
                    GET_SSTR (self->payload.queue_declare.queue, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.queue_declare.passive = (bit_string >> 0) & 1;
                    self->payload.queue_declare.durable = (bit_string >> 1) & 1;
                    self->payload.queue_declare.exclusive = (bit_string >> 2) & 1;
                    self->payload.queue_declare.auto_delete = (bit_string >> 3) & 1;
                    self->payload.queue_declare.nowait = (bit_string >> 4) & 1;
                    GET_LSTR (self->payload.queue_declare.arguments, data_source);
                    if (!ipr_regexp_match (s_regexp_queue_queue, self->payload.queue_declare.queue)) {
                        strcpy (strerror, "queue.declare: queue field is invalid");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_QUEUE_DECLARE_OK:
                    self->name = "queue.declare_ok";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.queue_declare_ok.queue, data_source);
                    GET_LONG  (self->payload.queue_declare_ok.message_count, data_source);
                    GET_LONG  (self->payload.queue_declare_ok.consumer_count, data_source);
                    if (*self->payload.queue_declare_ok.queue == 0) {
                        strcpy (strerror, "queue.declare_ok: queue field is empty");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_QUEUE_BIND:
                    self->name = "queue.bind";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.queue_bind.ticket, data_source);
                    GET_SSTR (self->payload.queue_bind.queue, data_source);
                    GET_SSTR (self->payload.queue_bind.exchange, data_source);
                    GET_SSTR (self->payload.queue_bind.routing_key, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.queue_bind.nowait = (bit_string >> 0) & 1;
                    GET_LSTR (self->payload.queue_bind.arguments, data_source);
                    if (strlen (self->payload.queue_bind.queue) > 127) {
                        strcpy (strerror, "queue.bind: queue field exceeds >127 chars");
                        goto exception;
                    }
                    if (strlen (self->payload.queue_bind.exchange) > 127) {
                        strcpy (strerror, "queue.bind: exchange field exceeds >127 chars");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_QUEUE_BIND_OK:
                    self->name = "queue.bind_ok";
                    self->sync = TRUE;
                    break;
                case AMQ_SERVER_QUEUE_PURGE:
                    self->name = "queue.purge";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.queue_purge.ticket, data_source);
                    GET_SSTR (self->payload.queue_purge.queue, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.queue_purge.nowait = (bit_string >> 0) & 1;
                    if (strlen (self->payload.queue_purge.queue) > 127) {
                        strcpy (strerror, "queue.purge: queue field exceeds >127 chars");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_QUEUE_PURGE_OK:
                    self->name = "queue.purge_ok";
                    self->sync = TRUE;
                    GET_LONG  (self->payload.queue_purge_ok.message_count, data_source);
                    break;
                case AMQ_SERVER_QUEUE_DELETE:
                    self->name = "queue.delete";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.queue_delete.ticket, data_source);
                    GET_SSTR (self->payload.queue_delete.queue, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.queue_delete.if_unused = (bit_string >> 0) & 1;
                    self->payload.queue_delete.if_empty = (bit_string >> 1) & 1;
                    self->payload.queue_delete.nowait = (bit_string >> 2) & 1;
                    if (strlen (self->payload.queue_delete.queue) > 127) {
                        strcpy (strerror, "queue.delete: queue field exceeds >127 chars");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_QUEUE_DELETE_OK:
                    self->name = "queue.delete_ok";
                    self->sync = TRUE;
                    GET_LONG  (self->payload.queue_delete_ok.message_count, data_source);
                    break;
                case AMQ_SERVER_QUEUE_UNBIND:
                    self->name = "queue.unbind";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.queue_unbind.ticket, data_source);
                    GET_SSTR (self->payload.queue_unbind.queue, data_source);
                    GET_SSTR (self->payload.queue_unbind.exchange, data_source);
                    GET_SSTR (self->payload.queue_unbind.routing_key, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.queue_unbind.nowait = (bit_string >> 0) & 1;
                    GET_LSTR (self->payload.queue_unbind.arguments, data_source);
                    if (strlen (self->payload.queue_unbind.queue) > 127) {
                        strcpy (strerror, "queue.unbind: queue field exceeds >127 chars");
                        goto exception;
                    }
                    if (strlen (self->payload.queue_unbind.exchange) > 127) {
                        strcpy (strerror, "queue.unbind: exchange field exceeds >127 chars");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_QUEUE_UNBIND_OK:
                    self->name = "queue.unbind_ok";
                    self->sync = TRUE;
                    break;
            }
            break;
        case AMQ_SERVER_BASIC:
            switch (self->method_id) {
                case AMQ_SERVER_BASIC_QOS:
                    self->name = "basic.qos";
                    self->sync = TRUE;
                    GET_LONG  (self->payload.basic_qos.prefetch_size, data_source);
                    GET_SHORT (self->payload.basic_qos.prefetch_count, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.basic_qos.global = (bit_string >> 0) & 1;
                    break;
                case AMQ_SERVER_BASIC_QOS_OK:
                    self->name = "basic.qos_ok";
                    self->sync = TRUE;
                    break;
                case AMQ_SERVER_BASIC_CONSUME:
                    self->name = "basic.consume";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.basic_consume.ticket, data_source);
                    GET_SSTR (self->payload.basic_consume.queue, data_source);
                    GET_SSTR (self->payload.basic_consume.consumer_tag, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.basic_consume.no_local = (bit_string >> 0) & 1;
                    self->payload.basic_consume.no_ack = (bit_string >> 1) & 1;
                    self->payload.basic_consume.exclusive = (bit_string >> 2) & 1;
                    self->payload.basic_consume.nowait = (bit_string >> 3) & 1;
                    GET_LSTR (self->payload.basic_consume.arguments, data_source);
                    if (strlen (self->payload.basic_consume.queue) > 127) {
                        strcpy (strerror, "basic.consume: queue field exceeds >127 chars");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_BASIC_CONSUME_OK:
                    self->name = "basic.consume_ok";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.basic_consume_ok.consumer_tag, data_source);
                    break;
                case AMQ_SERVER_BASIC_CANCEL:
                    self->name = "basic.cancel";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.basic_cancel.consumer_tag, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.basic_cancel.nowait = (bit_string >> 0) & 1;
                    break;
                case AMQ_SERVER_BASIC_CANCEL_OK:
                    self->name = "basic.cancel_ok";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.basic_cancel_ok.consumer_tag, data_source);
                    break;
                case AMQ_SERVER_BASIC_PUBLISH:
                    self->name = "basic.publish";
                    self->sync = FALSE;
                    GET_SHORT (self->payload.basic_publish.ticket, data_source);
                    GET_SSTR (self->payload.basic_publish.exchange, data_source);
                    GET_SSTR (self->payload.basic_publish.routing_key, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.basic_publish.mandatory = (bit_string >> 0) & 1;
                    self->payload.basic_publish.immediate = (bit_string >> 1) & 1;
                    if (strlen (self->payload.basic_publish.exchange) > 127) {
                        strcpy (strerror, "basic.publish: exchange field exceeds >127 chars");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_BASIC_RETURN:
                    self->name = "basic.return";
                    self->sync = FALSE;
                    GET_SHORT (self->payload.basic_return.reply_code, data_source);
                    GET_SSTR (self->payload.basic_return.reply_text, data_source);
                    GET_SSTR (self->payload.basic_return.exchange, data_source);
                    GET_SSTR (self->payload.basic_return.routing_key, data_source);
                    if (self->payload.basic_return.reply_code == 0) {
                        strcpy (strerror, "basic.return: reply_code field is empty");
                        goto exception;
                    }
                    if (*self->payload.basic_return.reply_text == 0) {
                        strcpy (strerror, "basic.return: reply_text field is empty");
                        goto exception;
                    }
                    if (strlen (self->payload.basic_return.exchange) > 127) {
                        strcpy (strerror, "basic.return: exchange field exceeds >127 chars");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_BASIC_DELIVER:
                    self->name = "basic.deliver";
                    self->sync = FALSE;
                    GET_SSTR (self->payload.basic_deliver.consumer_tag, data_source);
                    GET_LLONG (self->payload.basic_deliver.delivery_tag, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.basic_deliver.redelivered = (bit_string >> 0) & 1;
                    GET_SSTR (self->payload.basic_deliver.exchange, data_source);
                    GET_SSTR (self->payload.basic_deliver.routing_key, data_source);
                    if (strlen (self->payload.basic_deliver.exchange) > 127) {
                        strcpy (strerror, "basic.deliver: exchange field exceeds >127 chars");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_BASIC_GET:
                    self->name = "basic.get";
                    self->sync = TRUE;
                    GET_SHORT (self->payload.basic_get.ticket, data_source);
                    GET_SSTR (self->payload.basic_get.queue, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.basic_get.no_ack = (bit_string >> 0) & 1;
                    if (strlen (self->payload.basic_get.queue) > 127) {
                        strcpy (strerror, "basic.get: queue field exceeds >127 chars");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_BASIC_GET_OK:
                    self->name = "basic.get_ok";
                    self->sync = TRUE;
                    GET_LLONG (self->payload.basic_get_ok.delivery_tag, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.basic_get_ok.redelivered = (bit_string >> 0) & 1;
                    GET_SSTR (self->payload.basic_get_ok.exchange, data_source);
                    GET_SSTR (self->payload.basic_get_ok.routing_key, data_source);
                    GET_LONG  (self->payload.basic_get_ok.message_count, data_source);
                    if (strlen (self->payload.basic_get_ok.exchange) > 127) {
                        strcpy (strerror, "basic.get_ok: exchange field exceeds >127 chars");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_BASIC_GET_EMPTY:
                    self->name = "basic.get_empty";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.basic_get_empty.sender_id, data_source);
                    break;
                case AMQ_SERVER_BASIC_ACK:
                    self->name = "basic.ack";
                    self->sync = FALSE;
                    GET_LLONG (self->payload.basic_ack.delivery_tag, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.basic_ack.multiple = (bit_string >> 0) & 1;
                    break;
                case AMQ_SERVER_BASIC_REJECT:
                    self->name = "basic.reject";
                    self->sync = FALSE;
                    GET_LLONG (self->payload.basic_reject.delivery_tag, data_source);
                    GET_OCTET (bit_string, data_source);
                    self->payload.basic_reject.requeue = (bit_string >> 0) & 1;
                    break;
            }
            break;
        case AMQ_SERVER_DIRECT:
            switch (self->method_id) {
                case AMQ_SERVER_DIRECT_PUT:
                    self->name = "direct.put";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.direct_put.sink, data_source);
                    break;
                case AMQ_SERVER_DIRECT_PUT_OK:
                    self->name = "direct.put_ok";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.direct_put_ok.lease, data_source);
                    break;
                case AMQ_SERVER_DIRECT_GET:
                    self->name = "direct.get";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.direct_get.feed, data_source);
                    if (*self->payload.direct_get.feed == 0) {
                        strcpy (strerror, "direct.get: feed field is empty");
                        goto exception;
                    }
                    break;
                case AMQ_SERVER_DIRECT_GET_OK:
                    self->name = "direct.get_ok";
                    self->sync = TRUE;
                    GET_SSTR (self->payload.direct_get_ok.lease, data_source);
                    break;
            }
            break;
    }
    goto finished;
    underflow:
        icl_shortstr_fmt (strerror, "malformed frame for '%s' method", self->name);
    exception:
        self_destroy (&self);
        return (NULL);
    finished:
        //  Return via normal function exit
</method>

<method name = "dump" template = "function">
    <doc>
    Dumps contents of serialised method for tracing.
    </doc>
    <argument name = "log" type = "smt_log_t *">Log file, if any</argument>
    <argument name = "prefix" type = "char *">Prefix for line</argument>
    //
    switch (self->class_id) {
        case AMQ_SERVER_CONNECTION:
            switch (self->method_id) {
                case AMQ_SERVER_CONNECTION_START:
                    if (log) {
                        smt_log_print (log, "%sconnection.start:"\\
                            " version_major=%d version_minor=%d server_properties=%uB mechanisms=%uB locales=%uB", prefix,
                            self->payload.connection_start.version_major,
                            self->payload.connection_start.version_minor,
                            self->payload.connection_start.server_properties?
                                self->payload.connection_start.server_properties->cur_size: 0,
                            self->payload.connection_start.mechanisms?
                                self->payload.connection_start.mechanisms->cur_size: 0,
                            self->payload.connection_start.locales?
                                self->payload.connection_start.locales->cur_size: 0);
                    }
                    else {
                        icl_console_print ("%sconnection.start:"\\
                            " version_major=%d version_minor=%d server_properties=%uB mechanisms=%uB locales=%uB", prefix,
                            self->payload.connection_start.version_major,
                            self->payload.connection_start.version_minor,
                            self->payload.connection_start.server_properties?
                                self->payload.connection_start.server_properties->cur_size: 0,
                            self->payload.connection_start.mechanisms?
                                self->payload.connection_start.mechanisms->cur_size: 0,
                            self->payload.connection_start.locales?
                                self->payload.connection_start.locales->cur_size: 0);
                    }
                    break;
                case AMQ_SERVER_CONNECTION_START_OK:
                    if (log) {
                        smt_log_print (log, "%sconnection.start-ok:"\\
                            " client_properties=%uB mechanism=\\"%s\\" response=%uB locale=\\"%s\\"", prefix,
                            self->payload.connection_start_ok.client_properties?
                                self->payload.connection_start_ok.client_properties->cur_size: 0,
                            self->payload.connection_start_ok.mechanism,
                            self->payload.connection_start_ok.response?
                                self->payload.connection_start_ok.response->cur_size: 0,
                            self->payload.connection_start_ok.locale);
                    }
                    else {
                        icl_console_print ("%sconnection.start-ok:"\\
                            " client_properties=%uB mechanism=\\"%s\\" response=%uB locale=\\"%s\\"", prefix,
                            self->payload.connection_start_ok.client_properties?
                                self->payload.connection_start_ok.client_properties->cur_size: 0,
                            self->payload.connection_start_ok.mechanism,
                            self->payload.connection_start_ok.response?
                                self->payload.connection_start_ok.response->cur_size: 0,
                            self->payload.connection_start_ok.locale);
                    }
                    break;
                case AMQ_SERVER_CONNECTION_SECURE:
                    if (log) {
                        smt_log_print (log, "%sconnection.secure:"\\
                            " challenge=%uB", prefix,
                            self->payload.connection_secure.challenge?
                                self->payload.connection_secure.challenge->cur_size: 0);
                    }
                    else {
                        icl_console_print ("%sconnection.secure:"\\
                            " challenge=%uB", prefix,
                            self->payload.connection_secure.challenge?
                                self->payload.connection_secure.challenge->cur_size: 0);
                    }
                    break;
                case AMQ_SERVER_CONNECTION_SECURE_OK:
                    if (log) {
                        smt_log_print (log, "%sconnection.secure-ok:"\\
                            " response=%uB", prefix,
                            self->payload.connection_secure_ok.response?
                                self->payload.connection_secure_ok.response->cur_size: 0);
                    }
                    else {
                        icl_console_print ("%sconnection.secure-ok:"\\
                            " response=%uB", prefix,
                            self->payload.connection_secure_ok.response?
                                self->payload.connection_secure_ok.response->cur_size: 0);
                    }
                    break;
                case AMQ_SERVER_CONNECTION_TUNE:
                    if (log) {
                        smt_log_print (log, "%sconnection.tune:"\\
                            " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                            self->payload.connection_tune.channel_max,
                            self->payload.connection_tune.frame_max,
                            self->payload.connection_tune.heartbeat);
                    }
                    else {
                        icl_console_print ("%sconnection.tune:"\\
                            " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                            self->payload.connection_tune.channel_max,
                            self->payload.connection_tune.frame_max,
                            self->payload.connection_tune.heartbeat);
                    }
                    break;
                case AMQ_SERVER_CONNECTION_TUNE_OK:
                    if (log) {
                        smt_log_print (log, "%sconnection.tune-ok:"\\
                            " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                            self->payload.connection_tune_ok.channel_max,
                            self->payload.connection_tune_ok.frame_max,
                            self->payload.connection_tune_ok.heartbeat);
                    }
                    else {
                        icl_console_print ("%sconnection.tune-ok:"\\
                            " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                            self->payload.connection_tune_ok.channel_max,
                            self->payload.connection_tune_ok.frame_max,
                            self->payload.connection_tune_ok.heartbeat);
                    }
                    break;
                case AMQ_SERVER_CONNECTION_OPEN:
                    if (log) {
                        smt_log_print (log, "%sconnection.open:"\\
                            " virtual_host=\\"%s\\" capabilities=\\"%s\\" insist=%d", prefix,
                            self->payload.connection_open.virtual_host,
                            self->payload.connection_open.capabilities,
                            self->payload.connection_open.insist);
                    }
                    else {
                        icl_console_print ("%sconnection.open:"\\
                            " virtual_host=\\"%s\\" capabilities=\\"%s\\" insist=%d", prefix,
                            self->payload.connection_open.virtual_host,
                            self->payload.connection_open.capabilities,
                            self->payload.connection_open.insist);
                    }
                    break;
                case AMQ_SERVER_CONNECTION_OPEN_OK:
                    if (log) {
                        smt_log_print (log, "%sconnection.open-ok:"\\
                            " known_hosts=\\"%s\\"", prefix,
                            self->payload.connection_open_ok.known_hosts);
                    }
                    else {
                        icl_console_print ("%sconnection.open-ok:"\\
                            " known_hosts=\\"%s\\"", prefix,
                            self->payload.connection_open_ok.known_hosts);
                    }
                    break;
                case AMQ_SERVER_CONNECTION_CLOSE:
                    if (log) {
                        smt_log_print (log, "%sconnection.close:"\\
                            " reply_code=%d reply_text=\\"%s\\" class_id=%d method_id=%d", prefix,
                            self->payload.connection_close.reply_code,
                            self->payload.connection_close.reply_text,
                            self->payload.connection_close.class_id,
                            self->payload.connection_close.method_id);
                    }
                    else {
                        icl_console_print ("%sconnection.close:"\\
                            " reply_code=%d reply_text=\\"%s\\" class_id=%d method_id=%d", prefix,
                            self->payload.connection_close.reply_code,
                            self->payload.connection_close.reply_text,
                            self->payload.connection_close.class_id,
                            self->payload.connection_close.method_id);
                    }
                    break;
                case AMQ_SERVER_CONNECTION_CLOSE_OK:
                    if (log) {
                        smt_log_print (log, "%sconnection.close-ok:"\\
                            "", prefix);
                    }
                    else {
                        icl_console_print ("%sconnection.close-ok:"\\
                            "", prefix);
                    }
                    break;
                default:
                    if (log)
                        smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
                    else
                        icl_console_print ("E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
            }
            break;
        case AMQ_SERVER_CHANNEL:
            switch (self->method_id) {
                case AMQ_SERVER_CHANNEL_OPEN:
                    if (log) {
                        smt_log_print (log, "%schannel.open:"\\
                            " out_of_band=\\"%s\\"", prefix,
                            self->payload.channel_open.out_of_band);
                    }
                    else {
                        icl_console_print ("%schannel.open:"\\
                            " out_of_band=\\"%s\\"", prefix,
                            self->payload.channel_open.out_of_band);
                    }
                    break;
                case AMQ_SERVER_CHANNEL_OPEN_OK:
                    if (log) {
                        smt_log_print (log, "%schannel.open-ok:"\\
                            " channel_id=%uB", prefix,
                            self->payload.channel_open_ok.channel_id?
                                self->payload.channel_open_ok.channel_id->cur_size: 0);
                    }
                    else {
                        icl_console_print ("%schannel.open-ok:"\\
                            " channel_id=%uB", prefix,
                            self->payload.channel_open_ok.channel_id?
                                self->payload.channel_open_ok.channel_id->cur_size: 0);
                    }
                    break;
                case AMQ_SERVER_CHANNEL_FLOW:
                    if (log) {
                        smt_log_print (log, "%schannel.flow:"\\
                            " active=%d", prefix,
                            self->payload.channel_flow.active);
                    }
                    else {
                        icl_console_print ("%schannel.flow:"\\
                            " active=%d", prefix,
                            self->payload.channel_flow.active);
                    }
                    break;
                case AMQ_SERVER_CHANNEL_FLOW_OK:
                    if (log) {
                        smt_log_print (log, "%schannel.flow-ok:"\\
                            " active=%d", prefix,
                            self->payload.channel_flow_ok.active);
                    }
                    else {
                        icl_console_print ("%schannel.flow-ok:"\\
                            " active=%d", prefix,
                            self->payload.channel_flow_ok.active);
                    }
                    break;
                case AMQ_SERVER_CHANNEL_CLOSE:
                    if (log) {
                        smt_log_print (log, "%schannel.close:"\\
                            " reply_code=%d reply_text=\\"%s\\" class_id=%d method_id=%d", prefix,
                            self->payload.channel_close.reply_code,
                            self->payload.channel_close.reply_text,
                            self->payload.channel_close.class_id,
                            self->payload.channel_close.method_id);
                    }
                    else {
                        icl_console_print ("%schannel.close:"\\
                            " reply_code=%d reply_text=\\"%s\\" class_id=%d method_id=%d", prefix,
                            self->payload.channel_close.reply_code,
                            self->payload.channel_close.reply_text,
                            self->payload.channel_close.class_id,
                            self->payload.channel_close.method_id);
                    }
                    break;
                case AMQ_SERVER_CHANNEL_CLOSE_OK:
                    if (log) {
                        smt_log_print (log, "%schannel.close-ok:"\\
                            "", prefix);
                    }
                    else {
                        icl_console_print ("%schannel.close-ok:"\\
                            "", prefix);
                    }
                    break;
                default:
                    if (log)
                        smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
                    else
                        icl_console_print ("E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
            }
            break;
        case AMQ_SERVER_EXCHANGE:
            switch (self->method_id) {
                case AMQ_SERVER_EXCHANGE_DECLARE:
                    if (log) {
                        smt_log_print (log, "%sexchange.declare:"\\
                            " ticket=%d exchange=\\"%s\\" type=\\"%s\\" passive=%d durable=%d auto_delete=%d internal=%d nowait=%d arguments=%uB", prefix,
                            self->payload.exchange_declare.ticket,
                            self->payload.exchange_declare.exchange,
                            self->payload.exchange_declare.type,
                            self->payload.exchange_declare.passive,
                            self->payload.exchange_declare.durable,
                            self->payload.exchange_declare.auto_delete,
                            self->payload.exchange_declare.internal,
                            self->payload.exchange_declare.nowait,
                            self->payload.exchange_declare.arguments?
                                self->payload.exchange_declare.arguments->cur_size: 0);
                    }
                    else {
                        icl_console_print ("%sexchange.declare:"\\
                            " ticket=%d exchange=\\"%s\\" type=\\"%s\\" passive=%d durable=%d auto_delete=%d internal=%d nowait=%d arguments=%uB", prefix,
                            self->payload.exchange_declare.ticket,
                            self->payload.exchange_declare.exchange,
                            self->payload.exchange_declare.type,
                            self->payload.exchange_declare.passive,
                            self->payload.exchange_declare.durable,
                            self->payload.exchange_declare.auto_delete,
                            self->payload.exchange_declare.internal,
                            self->payload.exchange_declare.nowait,
                            self->payload.exchange_declare.arguments?
                                self->payload.exchange_declare.arguments->cur_size: 0);
                    }
                    break;
                case AMQ_SERVER_EXCHANGE_DECLARE_OK:
                    if (log) {
                        smt_log_print (log, "%sexchange.declare-ok:"\\
                            "", prefix);
                    }
                    else {
                        icl_console_print ("%sexchange.declare-ok:"\\
                            "", prefix);
                    }
                    break;
                case AMQ_SERVER_EXCHANGE_DELETE:
                    if (log) {
                        smt_log_print (log, "%sexchange.delete:"\\
                            " ticket=%d exchange=\\"%s\\" if_unused=%d nowait=%d", prefix,
                            self->payload.exchange_delete.ticket,
                            self->payload.exchange_delete.exchange,
                            self->payload.exchange_delete.if_unused,
                            self->payload.exchange_delete.nowait);
                    }
                    else {
                        icl_console_print ("%sexchange.delete:"\\
                            " ticket=%d exchange=\\"%s\\" if_unused=%d nowait=%d", prefix,
                            self->payload.exchange_delete.ticket,
                            self->payload.exchange_delete.exchange,
                            self->payload.exchange_delete.if_unused,
                            self->payload.exchange_delete.nowait);
                    }
                    break;
                case AMQ_SERVER_EXCHANGE_DELETE_OK:
                    if (log) {
                        smt_log_print (log, "%sexchange.delete-ok:"\\
                            "", prefix);
                    }
                    else {
                        icl_console_print ("%sexchange.delete-ok:"\\
                            "", prefix);
                    }
                    break;
                default:
                    if (log)
                        smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
                    else
                        icl_console_print ("E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
            }
            break;
        case AMQ_SERVER_QUEUE:
            switch (self->method_id) {
                case AMQ_SERVER_QUEUE_DECLARE:
                    if (log) {
                        smt_log_print (log, "%squeue.declare:"\\
                            " ticket=%d queue=\\"%s\\" passive=%d durable=%d exclusive=%d auto_delete=%d nowait=%d arguments=%uB", prefix,
                            self->payload.queue_declare.ticket,
                            self->payload.queue_declare.queue,
                            self->payload.queue_declare.passive,
                            self->payload.queue_declare.durable,
                            self->payload.queue_declare.exclusive,
                            self->payload.queue_declare.auto_delete,
                            self->payload.queue_declare.nowait,
                            self->payload.queue_declare.arguments?
                                self->payload.queue_declare.arguments->cur_size: 0);
                    }
                    else {
                        icl_console_print ("%squeue.declare:"\\
                            " ticket=%d queue=\\"%s\\" passive=%d durable=%d exclusive=%d auto_delete=%d nowait=%d arguments=%uB", prefix,
                            self->payload.queue_declare.ticket,
                            self->payload.queue_declare.queue,
                            self->payload.queue_declare.passive,
                            self->payload.queue_declare.durable,
                            self->payload.queue_declare.exclusive,
                            self->payload.queue_declare.auto_delete,
                            self->payload.queue_declare.nowait,
                            self->payload.queue_declare.arguments?
                                self->payload.queue_declare.arguments->cur_size: 0);
                    }
                    break;
                case AMQ_SERVER_QUEUE_DECLARE_OK:
                    if (log) {
                        smt_log_print (log, "%squeue.declare-ok:"\\
                            " queue=\\"%s\\" message_count=%u consumer_count=%u", prefix,
                            self->payload.queue_declare_ok.queue,
                            self->payload.queue_declare_ok.message_count,
                            self->payload.queue_declare_ok.consumer_count);
                    }
                    else {
                        icl_console_print ("%squeue.declare-ok:"\\
                            " queue=\\"%s\\" message_count=%u consumer_count=%u", prefix,
                            self->payload.queue_declare_ok.queue,
                            self->payload.queue_declare_ok.message_count,
                            self->payload.queue_declare_ok.consumer_count);
                    }
                    break;
                case AMQ_SERVER_QUEUE_BIND:
                    if (log) {
                        smt_log_print (log, "%squeue.bind:"\\
                            " ticket=%d queue=\\"%s\\" exchange=\\"%s\\" routing_key=\\"%s\\" nowait=%d arguments=%uB", prefix,
                            self->payload.queue_bind.ticket,
                            self->payload.queue_bind.queue,
                            self->payload.queue_bind.exchange,
                            self->payload.queue_bind.routing_key,
                            self->payload.queue_bind.nowait,
                            self->payload.queue_bind.arguments?
                                self->payload.queue_bind.arguments->cur_size: 0);
                    }
                    else {
                        icl_console_print ("%squeue.bind:"\\
                            " ticket=%d queue=\\"%s\\" exchange=\\"%s\\" routing_key=\\"%s\\" nowait=%d arguments=%uB", prefix,
                            self->payload.queue_bind.ticket,
                            self->payload.queue_bind.queue,
                            self->payload.queue_bind.exchange,
                            self->payload.queue_bind.routing_key,
                            self->payload.queue_bind.nowait,
                            self->payload.queue_bind.arguments?
                                self->payload.queue_bind.arguments->cur_size: 0);
                    }
                    break;
                case AMQ_SERVER_QUEUE_BIND_OK:
                    if (log) {
                        smt_log_print (log, "%squeue.bind-ok:"\\
                            "", prefix);
                    }
                    else {
                        icl_console_print ("%squeue.bind-ok:"\\
                            "", prefix);
                    }
                    break;
                case AMQ_SERVER_QUEUE_PURGE:
                    if (log) {
                        smt_log_print (log, "%squeue.purge:"\\
                            " ticket=%d queue=\\"%s\\" nowait=%d", prefix,
                            self->payload.queue_purge.ticket,
                            self->payload.queue_purge.queue,
                            self->payload.queue_purge.nowait);
                    }
                    else {
                        icl_console_print ("%squeue.purge:"\\
                            " ticket=%d queue=\\"%s\\" nowait=%d", prefix,
                            self->payload.queue_purge.ticket,
                            self->payload.queue_purge.queue,
                            self->payload.queue_purge.nowait);
                    }
                    break;
                case AMQ_SERVER_QUEUE_PURGE_OK:
                    if (log) {
                        smt_log_print (log, "%squeue.purge-ok:"\\
                            " message_count=%u", prefix,
                            self->payload.queue_purge_ok.message_count);
                    }
                    else {
                        icl_console_print ("%squeue.purge-ok:"\\
                            " message_count=%u", prefix,
                            self->payload.queue_purge_ok.message_count);
                    }
                    break;
                case AMQ_SERVER_QUEUE_DELETE:
                    if (log) {
                        smt_log_print (log, "%squeue.delete:"\\
                            " ticket=%d queue=\\"%s\\" if_unused=%d if_empty=%d nowait=%d", prefix,
                            self->payload.queue_delete.ticket,
                            self->payload.queue_delete.queue,
                            self->payload.queue_delete.if_unused,
                            self->payload.queue_delete.if_empty,
                            self->payload.queue_delete.nowait);
                    }
                    else {
                        icl_console_print ("%squeue.delete:"\\
                            " ticket=%d queue=\\"%s\\" if_unused=%d if_empty=%d nowait=%d", prefix,
                            self->payload.queue_delete.ticket,
                            self->payload.queue_delete.queue,
                            self->payload.queue_delete.if_unused,
                            self->payload.queue_delete.if_empty,
                            self->payload.queue_delete.nowait);
                    }
                    break;
                case AMQ_SERVER_QUEUE_DELETE_OK:
                    if (log) {
                        smt_log_print (log, "%squeue.delete-ok:"\\
                            " message_count=%u", prefix,
                            self->payload.queue_delete_ok.message_count);
                    }
                    else {
                        icl_console_print ("%squeue.delete-ok:"\\
                            " message_count=%u", prefix,
                            self->payload.queue_delete_ok.message_count);
                    }
                    break;
                case AMQ_SERVER_QUEUE_UNBIND:
                    if (log) {
                        smt_log_print (log, "%squeue.unbind:"\\
                            " ticket=%d queue=\\"%s\\" exchange=\\"%s\\" routing_key=\\"%s\\" nowait=%d arguments=%uB", prefix,
                            self->payload.queue_unbind.ticket,
                            self->payload.queue_unbind.queue,
                            self->payload.queue_unbind.exchange,
                            self->payload.queue_unbind.routing_key,
                            self->payload.queue_unbind.nowait,
                            self->payload.queue_unbind.arguments?
                                self->payload.queue_unbind.arguments->cur_size: 0);
                    }
                    else {
                        icl_console_print ("%squeue.unbind:"\\
                            " ticket=%d queue=\\"%s\\" exchange=\\"%s\\" routing_key=\\"%s\\" nowait=%d arguments=%uB", prefix,
                            self->payload.queue_unbind.ticket,
                            self->payload.queue_unbind.queue,
                            self->payload.queue_unbind.exchange,
                            self->payload.queue_unbind.routing_key,
                            self->payload.queue_unbind.nowait,
                            self->payload.queue_unbind.arguments?
                                self->payload.queue_unbind.arguments->cur_size: 0);
                    }
                    break;
                case AMQ_SERVER_QUEUE_UNBIND_OK:
                    if (log) {
                        smt_log_print (log, "%squeue.unbind-ok:"\\
                            "", prefix);
                    }
                    else {
                        icl_console_print ("%squeue.unbind-ok:"\\
                            "", prefix);
                    }
                    break;
                default:
                    if (log)
                        smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
                    else
                        icl_console_print ("E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
            }
            break;
        case AMQ_SERVER_BASIC:
            switch (self->method_id) {
                case AMQ_SERVER_BASIC_QOS:
                    if (log) {
                        smt_log_print (log, "%sbasic.qos:"\\
                            " prefetch_size=%u prefetch_count=%d global=%d", prefix,
                            self->payload.basic_qos.prefetch_size,
                            self->payload.basic_qos.prefetch_count,
                            self->payload.basic_qos.global);
                    }
                    else {
                        icl_console_print ("%sbasic.qos:"\\
                            " prefetch_size=%u prefetch_count=%d global=%d", prefix,
                            self->payload.basic_qos.prefetch_size,
                            self->payload.basic_qos.prefetch_count,
                            self->payload.basic_qos.global);
                    }
                    break;
                case AMQ_SERVER_BASIC_QOS_OK:
                    if (log) {
                        smt_log_print (log, "%sbasic.qos-ok:"\\
                            "", prefix);
                    }
                    else {
                        icl_console_print ("%sbasic.qos-ok:"\\
                            "", prefix);
                    }
                    break;
                case AMQ_SERVER_BASIC_CONSUME:
                    if (log) {
                        smt_log_print (log, "%sbasic.consume:"\\
                            " ticket=%d queue=\\"%s\\" consumer_tag=\\"%s\\" no_local=%d no_ack=%d exclusive=%d nowait=%d arguments=%uB", prefix,
                            self->payload.basic_consume.ticket,
                            self->payload.basic_consume.queue,
                            self->payload.basic_consume.consumer_tag,
                            self->payload.basic_consume.no_local,
                            self->payload.basic_consume.no_ack,
                            self->payload.basic_consume.exclusive,
                            self->payload.basic_consume.nowait,
                            self->payload.basic_consume.arguments?
                                self->payload.basic_consume.arguments->cur_size: 0);
                    }
                    else {
                        icl_console_print ("%sbasic.consume:"\\
                            " ticket=%d queue=\\"%s\\" consumer_tag=\\"%s\\" no_local=%d no_ack=%d exclusive=%d nowait=%d arguments=%uB", prefix,
                            self->payload.basic_consume.ticket,
                            self->payload.basic_consume.queue,
                            self->payload.basic_consume.consumer_tag,
                            self->payload.basic_consume.no_local,
                            self->payload.basic_consume.no_ack,
                            self->payload.basic_consume.exclusive,
                            self->payload.basic_consume.nowait,
                            self->payload.basic_consume.arguments?
                                self->payload.basic_consume.arguments->cur_size: 0);
                    }
                    break;
                case AMQ_SERVER_BASIC_CONSUME_OK:
                    if (log) {
                        smt_log_print (log, "%sbasic.consume-ok:"\\
                            " consumer_tag=\\"%s\\"", prefix,
                            self->payload.basic_consume_ok.consumer_tag);
                    }
                    else {
                        icl_console_print ("%sbasic.consume-ok:"\\
                            " consumer_tag=\\"%s\\"", prefix,
                            self->payload.basic_consume_ok.consumer_tag);
                    }
                    break;
                case AMQ_SERVER_BASIC_CANCEL:
                    if (log) {
                        smt_log_print (log, "%sbasic.cancel:"\\
                            " consumer_tag=\\"%s\\" nowait=%d", prefix,
                            self->payload.basic_cancel.consumer_tag,
                            self->payload.basic_cancel.nowait);
                    }
                    else {
                        icl_console_print ("%sbasic.cancel:"\\
                            " consumer_tag=\\"%s\\" nowait=%d", prefix,
                            self->payload.basic_cancel.consumer_tag,
                            self->payload.basic_cancel.nowait);
                    }
                    break;
                case AMQ_SERVER_BASIC_CANCEL_OK:
                    if (log) {
                        smt_log_print (log, "%sbasic.cancel-ok:"\\
                            " consumer_tag=\\"%s\\"", prefix,
                            self->payload.basic_cancel_ok.consumer_tag);
                    }
                    else {
                        icl_console_print ("%sbasic.cancel-ok:"\\
                            " consumer_tag=\\"%s\\"", prefix,
                            self->payload.basic_cancel_ok.consumer_tag);
                    }
                    break;
                case AMQ_SERVER_BASIC_PUBLISH:
                    if (log) {
                        smt_log_print (log, "%sbasic.publish:"\\
                            " ticket=%d exchange=\\"%s\\" routing_key=\\"%s\\" mandatory=%d immediate=%d", prefix,
                            self->payload.basic_publish.ticket,
                            self->payload.basic_publish.exchange,
                            self->payload.basic_publish.routing_key,
                            self->payload.basic_publish.mandatory,
                            self->payload.basic_publish.immediate);
                    }
                    else {
                        icl_console_print ("%sbasic.publish:"\\
                            " ticket=%d exchange=\\"%s\\" routing_key=\\"%s\\" mandatory=%d immediate=%d", prefix,
                            self->payload.basic_publish.ticket,
                            self->payload.basic_publish.exchange,
                            self->payload.basic_publish.routing_key,
                            self->payload.basic_publish.mandatory,
                            self->payload.basic_publish.immediate);
                    }
                    break;
                case AMQ_SERVER_BASIC_RETURN:
                    if (log) {
                        smt_log_print (log, "%sbasic.return:"\\
                            " reply_code=%d reply_text=\\"%s\\" exchange=\\"%s\\" routing_key=\\"%s\\"", prefix,
                            self->payload.basic_return.reply_code,
                            self->payload.basic_return.reply_text,
                            self->payload.basic_return.exchange,
                            self->payload.basic_return.routing_key);
                    }
                    else {
                        icl_console_print ("%sbasic.return:"\\
                            " reply_code=%d reply_text=\\"%s\\" exchange=\\"%s\\" routing_key=\\"%s\\"", prefix,
                            self->payload.basic_return.reply_code,
                            self->payload.basic_return.reply_text,
                            self->payload.basic_return.exchange,
                            self->payload.basic_return.routing_key);
                    }
                    break;
                case AMQ_SERVER_BASIC_DELIVER:
                    if (log) {
                        smt_log_print (log, "%sbasic.deliver:"\\
                            " consumer_tag=\\"%s\\" delivery_tag=%lu redelivered=%d exchange=\\"%s\\" routing_key=\\"%s\\"", prefix,
                            self->payload.basic_deliver.consumer_tag,
                            (long) self->payload.basic_deliver.delivery_tag,
                            self->payload.basic_deliver.redelivered,
                            self->payload.basic_deliver.exchange,
                            self->payload.basic_deliver.routing_key);
                    }
                    else {
                        icl_console_print ("%sbasic.deliver:"\\
                            " consumer_tag=\\"%s\\" delivery_tag=%lu redelivered=%d exchange=\\"%s\\" routing_key=\\"%s\\"", prefix,
                            self->payload.basic_deliver.consumer_tag,
                            (long) self->payload.basic_deliver.delivery_tag,
                            self->payload.basic_deliver.redelivered,
                            self->payload.basic_deliver.exchange,
                            self->payload.basic_deliver.routing_key);
                    }
                    break;
                case AMQ_SERVER_BASIC_GET:
                    if (log) {
                        smt_log_print (log, "%sbasic.get:"\\
                            " ticket=%d queue=\\"%s\\" no_ack=%d", prefix,
                            self->payload.basic_get.ticket,
                            self->payload.basic_get.queue,
                            self->payload.basic_get.no_ack);
                    }
                    else {
                        icl_console_print ("%sbasic.get:"\\
                            " ticket=%d queue=\\"%s\\" no_ack=%d", prefix,
                            self->payload.basic_get.ticket,
                            self->payload.basic_get.queue,
                            self->payload.basic_get.no_ack);
                    }
                    break;
                case AMQ_SERVER_BASIC_GET_OK:
                    if (log) {
                        smt_log_print (log, "%sbasic.get-ok:"\\
                            " delivery_tag=%lu redelivered=%d exchange=\\"%s\\" routing_key=\\"%s\\" message_count=%u", prefix,
                            (long) self->payload.basic_get_ok.delivery_tag,
                            self->payload.basic_get_ok.redelivered,
                            self->payload.basic_get_ok.exchange,
                            self->payload.basic_get_ok.routing_key,
                            self->payload.basic_get_ok.message_count);
                    }
                    else {
                        icl_console_print ("%sbasic.get-ok:"\\
                            " delivery_tag=%lu redelivered=%d exchange=\\"%s\\" routing_key=\\"%s\\" message_count=%u", prefix,
                            (long) self->payload.basic_get_ok.delivery_tag,
                            self->payload.basic_get_ok.redelivered,
                            self->payload.basic_get_ok.exchange,
                            self->payload.basic_get_ok.routing_key,
                            self->payload.basic_get_ok.message_count);
                    }
                    break;
                case AMQ_SERVER_BASIC_GET_EMPTY:
                    if (log) {
                        smt_log_print (log, "%sbasic.get-empty:"\\
                            " sender_id=\\"%s\\"", prefix,
                            self->payload.basic_get_empty.sender_id);
                    }
                    else {
                        icl_console_print ("%sbasic.get-empty:"\\
                            " sender_id=\\"%s\\"", prefix,
                            self->payload.basic_get_empty.sender_id);
                    }
                    break;
                case AMQ_SERVER_BASIC_ACK:
                    if (log) {
                        smt_log_print (log, "%sbasic.ack:"\\
                            " delivery_tag=%lu multiple=%d", prefix,
                            (long) self->payload.basic_ack.delivery_tag,
                            self->payload.basic_ack.multiple);
                    }
                    else {
                        icl_console_print ("%sbasic.ack:"\\
                            " delivery_tag=%lu multiple=%d", prefix,
                            (long) self->payload.basic_ack.delivery_tag,
                            self->payload.basic_ack.multiple);
                    }
                    break;
                case AMQ_SERVER_BASIC_REJECT:
                    if (log) {
                        smt_log_print (log, "%sbasic.reject:"\\
                            " delivery_tag=%lu requeue=%d", prefix,
                            (long) self->payload.basic_reject.delivery_tag,
                            self->payload.basic_reject.requeue);
                    }
                    else {
                        icl_console_print ("%sbasic.reject:"\\
                            " delivery_tag=%lu requeue=%d", prefix,
                            (long) self->payload.basic_reject.delivery_tag,
                            self->payload.basic_reject.requeue);
                    }
                    break;
                default:
                    if (log)
                        smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
                    else
                        icl_console_print ("E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
            }
            break;
        case AMQ_SERVER_DIRECT:
            switch (self->method_id) {
                case AMQ_SERVER_DIRECT_PUT:
                    if (log) {
                        smt_log_print (log, "%sdirect.put:"\\
                            " sink=\\"%s\\"", prefix,
                            self->payload.direct_put.sink);
                    }
                    else {
                        icl_console_print ("%sdirect.put:"\\
                            " sink=\\"%s\\"", prefix,
                            self->payload.direct_put.sink);
                    }
                    break;
                case AMQ_SERVER_DIRECT_PUT_OK:
                    if (log) {
                        smt_log_print (log, "%sdirect.put-ok:"\\
                            " lease=\\"%s\\"", prefix,
                            self->payload.direct_put_ok.lease);
                    }
                    else {
                        icl_console_print ("%sdirect.put-ok:"\\
                            " lease=\\"%s\\"", prefix,
                            self->payload.direct_put_ok.lease);
                    }
                    break;
                case AMQ_SERVER_DIRECT_GET:
                    if (log) {
                        smt_log_print (log, "%sdirect.get:"\\
                            " feed=\\"%s\\"", prefix,
                            self->payload.direct_get.feed);
                    }
                    else {
                        icl_console_print ("%sdirect.get:"\\
                            " feed=\\"%s\\"", prefix,
                            self->payload.direct_get.feed);
                    }
                    break;
                case AMQ_SERVER_DIRECT_GET_OK:
                    if (log) {
                        smt_log_print (log, "%sdirect.get-ok:"\\
                            " lease=\\"%s\\"", prefix,
                            self->payload.direct_get_ok.lease);
                    }
                    else {
                        icl_console_print ("%sdirect.get-ok:"\\
                            " lease=\\"%s\\"", prefix,
                            self->payload.direct_get_ok.lease);
                    }
                    break;
                default:
                    if (log)
                        smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
                    else
                        icl_console_print ("E: illegal method (class=%d, method=%d)",
                            self->class_id, self->method_id);
            }
            break;
        default:
            if (log)
                smt_log_print (log, "E: illegal class=%d", self->class_id);
            else
                icl_console_print ("E: illegal class=%d", self->class_id);
    }
</method>

<method name = "execute" template = "function">
    <doc>
    Accepts a amq_server_method_t object and executes the method.
    Returns 0 if the method was executed successfully, non-zero if there
    was an error - e.g. if the method is not allowed for this chassis.
    </doc>
    //
    <argument name = "connection" type = "amq_server_connection_t *">
    Current connection object, or null (if internal execution)
    </argument>
    <argument name = "channel" type = "amq_server_channel_t *">
    Current channel object, or null (if no channel opened)
    </argument>
    if (self->class_id  == AMQ_SERVER_CONNECTION
    &&  self->method_id == AMQ_SERVER_CONNECTION_START_OK) {
        amq_server_connection_start_ok_t
            *method;
        method = &self->payload.connection_start_ok;
        {
            amq_server_connection_start_ok (connection, method);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_CONNECTION
    &&  self->method_id == AMQ_SERVER_CONNECTION_TUNE_OK) {
        amq_server_connection_tune_ok_t
            *method;
        method = &self->payload.connection_tune_ok;
        {
            amq_server_connection_tune_ok (connection, method);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_CONNECTION
    &&  self->method_id == AMQ_SERVER_CONNECTION_OPEN) {
        amq_server_connection_open_t
            *method;
        method = &self->payload.connection_open;
        {
            amq_server_connection_open (connection, method);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_CHANNEL
    &&  self->method_id == AMQ_SERVER_CHANNEL_FLOW) {
        amq_server_channel_flow_t
            *method;
        method = &self->payload.channel_flow;
        {
            amq_server_channel_flow (channel, method->active);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_EXCHANGE
    &&  self->method_id == AMQ_SERVER_EXCHANGE_DECLARE) {
        amq_server_exchange_declare_t
            *method;
        method = &self->payload.exchange_declare;
        {
            amq_exchange_t
        *exchange;
    int
        exchange_type;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    exchange_type = amq_exchange_type_lookup (method->type);
    if (exchange_type != -1) {
        //  Find exchange and create if necessary
        exchange = amq_exchange_table_search (vhost->exchange_table, method->exchange);
        if (!exchange) {
            if (method->passive)
                amq_server_channel_error (channel, ASL_NOT_FOUND, "No such exchange defined",
                    AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DECLARE);
            else {
                if (ipr_str_prefixed (method->exchange, "amq."))
                    amq_server_channel_error (channel,
                        ASL_ACCESS_REFUSED, "Exchange name not allowed",
                        AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DECLARE);
                else {
                    exchange = amq_exchange_new (
                        vhost->exchange_table,
                        vhost,
                        exchange_type,
                        method->exchange,
                        method->internal,
                        FALSE);         //  Do not federate automatically

                    //  This can fail if two threads create the same exchange at the
                    //  same time... so let's go find the actual exchange object
                    if (!exchange)
                        exchange = amq_exchange_table_search (vhost->exchange_table, method->exchange);
                }
            }
        }
        if (exchange) {
            if (exchange->type == exchange_type) {
                icl_shortstr_cpy (channel->current_exchange, exchange->name);
                if (!method->nowait)
                    amq_server_agent_exchange_declare_ok (connection->thread, channel->number);
            }
            else
                amq_server_connection_error (connection,
                    ASL_NOT_ALLOWED, "Exchange exists with different type",
                    AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DECLARE);

            amq_exchange_unlink (&exchange);
        }
    }
    else
        amq_server_connection_error (connection, ASL_COMMAND_INVALID, "Unknown exchange type",
            AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DECLARE);        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DECLARE);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_EXCHANGE
    &&  self->method_id == AMQ_SERVER_EXCHANGE_DELETE) {
        amq_server_exchange_delete_t
            *method;
        method = &self->payload.exchange_delete;
        {
            amq_exchange_t
        *exchange;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    //  Use current channel exchange if method has a blank name
    if (strnull (method->exchange))
        icl_shortstr_cpy (method->exchange, channel->current_exchange);

    if (ipr_str_prefixed (method->exchange, "amq."))
       amq_server_channel_error (channel,
            ASL_ACCESS_REFUSED, "Exchange name not allowed",
            AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DECLARE);
    else {
        exchange = amq_exchange_table_search (vhost->exchange_table, method->exchange);
        if (exchange) {
            //  Tell client delete was successful
            if (!method->nowait)
                amq_server_agent_exchange_delete_ok (connection->thread, channel->number);

            //  Destroy the exchange on this peer
            amq_exchange_destroy (&exchange);
        }
        else
            amq_server_channel_error (channel, ASL_NOT_FOUND, "No such exchange defined",
                AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DELETE);
    }        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DELETE);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_QUEUE
    &&  self->method_id == AMQ_SERVER_QUEUE_DECLARE) {
        amq_server_queue_declare_t
            *method;
        method = &self->payload.queue_declare;
        {
            amq_queue_t
        *queue;
    static qbyte
        queue_index = 0;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    //  Find queue and create if necessary
    if (strnull (method->queue))
        icl_shortstr_fmt (method->queue, "#%d", icl_atomic_inc32 (&queue_index));
    queue = amq_queue_table_search (vhost->queue_table, method->queue);
    if (!queue) {
        if (method->passive)
            amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
                AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
        else
        if (method->durable)
            amq_server_channel_error (channel, ASL_NOT_IMPLEMENTED, "Durable queues not supported",
                AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
        else {
            //  The queue->connection specifies owner connection, for exclusive queues
            queue = amq_queue_new (
                vhost,
                method->exclusive? connection: NULL,
                method->queue,
                method->durable,
                method->exclusive,
                //  Setting the 'exclusive' flag always implies 'auto-delete'
                method->exclusive? TRUE: method->auto_delete,
                method->arguments);

            //  This can fail if two threads create the same queue at the
            //  same time... so let's go find the actual queue object
            if (!queue)
                queue = amq_queue_table_search (vhost->queue_table, method->queue);

            if (queue) {
                //  Make default binding, if wanted
                if (vhost->default_exchange)
                    amq_exchange_bind_queue (
                        vhost->default_exchange, NULL, queue, queue->name, NULL);

                //  Add to connection's exclusive queue list
                if (method->exclusive)
                    amq_server_connection_own_queue (connection, queue);
            }
            else
                amq_server_connection_error (connection,
                    ASL_RESOURCE_ERROR, "Unable to declare queue",
                    AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
        }
    }
    if (queue) {
        if (method->exclusive && queue->connection == NULL)
            icl_console_print ("W: queue.declare aborted by connection close");
        else
        if (method->exclusive && queue->connection != connection)
            amq_server_channel_error (
                channel,
                ASL_ACCESS_REFUSED,
                "Queue cannot be made exclusive to this connection",
                AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
        else {
            //  AMQP requires us to hold a current queue per channel
            icl_shortstr_cpy (channel->current_queue, queue->name);
            if (!method->nowait)
                amq_server_agent_queue_declare_ok (
                    connection->thread,
                    channel->number,
                    queue->name,
                    amq_queue_message_count (queue),
                    amq_queue_consumer_count (queue));
        }
        amq_queue_unlink (&queue);
    }        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_QUEUE
    &&  self->method_id == AMQ_SERVER_QUEUE_BIND) {
        amq_server_queue_bind_t
            *method;
        method = &self->payload.queue_bind;
        {
            amq_exchange_t
        *exchange;                      //  Exchange to bind to
    amq_queue_t
        *queue;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    //  Use current channel queue if method uses a blank queue
    if (strnull (method->queue)) {
        icl_shortstr_cpy (method->queue, channel->current_queue);
        if (strnull (method->routing_key))
            icl_shortstr_cpy (method->routing_key, channel->current_queue);
    }
    exchange = amq_exchange_table_search (vhost->exchange_table, method->exchange);
    if (exchange) {
        queue = amq_queue_table_search (vhost->queue_table, method->queue);
        if (queue) {
            amq_exchange_bind_queue (
                exchange, channel, queue, method->routing_key, method->arguments);
            if (!method->nowait)
                amq_server_agent_queue_bind_ok (connection->thread, channel->number);
            amq_queue_unlink (&queue);
        }
        else
            amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
                AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_BIND);
        amq_exchange_unlink (&exchange);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND, "No such exchange defined",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_BIND);        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_BIND);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_QUEUE
    &&  self->method_id == AMQ_SERVER_QUEUE_PURGE) {
        amq_server_queue_purge_t
            *method;
        method = &self->payload.queue_purge;
        {
            amq_queue_t
        *queue;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    //  Use current channel queue if method uses a blank queue
    if (strnull (method->queue))
        icl_shortstr_cpy (method->queue, channel->current_queue);

    queue = amq_queue_table_search (vhost->queue_table, method->queue);
    if (queue) {
        amq_queue_purge (queue, channel, method->nowait);
        amq_queue_unlink (&queue);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_PURGE);        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_PURGE);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_QUEUE
    &&  self->method_id == AMQ_SERVER_QUEUE_DELETE) {
        amq_server_queue_delete_t
            *method;
        method = &self->payload.queue_delete;
        {
            amq_queue_t
        *queue;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    //  Use current channel queue if method uses a blank queue
    if (strnull (method->queue))
        icl_shortstr_cpy (method->queue, channel->current_queue);

    queue = amq_queue_table_search (vhost->queue_table, method->queue);
    if (queue) {
        //  Tell client we deleted the queue ok
        if (!method->nowait)
            amq_server_agent_queue_delete_ok (
                connection->thread, channel->number, amq_queue_message_count (queue));

        //  Destroy the queue on this peer
        amq_vhost_unbind_queue (vhost, queue);
        amq_queue_destroy (&queue);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DELETE);        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DELETE);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_QUEUE
    &&  self->method_id == AMQ_SERVER_QUEUE_UNBIND) {
        amq_server_queue_unbind_t
            *method;
        method = &self->payload.queue_unbind;
        {
            amq_exchange_t
        *exchange;                      //  Exchange to unbind from
    amq_queue_t
        *queue;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    //  Use current channel queue if method uses a blank queue
    if (strnull (method->queue)) {
        icl_shortstr_cpy (method->queue, channel->current_queue);
        if (strnull (method->routing_key))
            icl_shortstr_cpy (method->routing_key, channel->current_queue);
    }
    exchange = amq_exchange_table_search (vhost->exchange_table, method->exchange);
    if (exchange) {
        queue = amq_queue_table_search (vhost->queue_table, method->queue);
        if (queue) {
            amq_exchange_protocol_unbind_queue (
                exchange, channel, queue, method->routing_key, method->arguments);
            if (!method->nowait)
                amq_server_agent_queue_unbind_ok (connection->thread, channel->number);
            amq_queue_unlink (&queue);
        }
        else
            amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
                AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_UNBIND);
        amq_exchange_unlink (&exchange);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND, "No such exchange defined",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_UNBIND);        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_UNBIND);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_BASIC
    &&  self->method_id == AMQ_SERVER_BASIC_QOS) {
        amq_server_basic_qos_t
            *method;
        method = &self->payload.basic_qos;
        {
            //  Does not do anything except respond Qos-Ok
    amq_server_agent_basic_qos_ok (channel->connection->thread, channel->number);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_BASIC
    &&  self->method_id == AMQ_SERVER_BASIC_CONSUME) {
        amq_server_basic_consume_t
            *method;
        method = &self->payload.basic_consume;
        {
            amq_queue_t
        *queue;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    //  Use current channel queue if method uses a blank queue
    if (strnull (method->queue))
        icl_shortstr_cpy (method->queue, channel->current_queue);

    queue = amq_queue_table_search (vhost->queue_table, method->queue);
    if (queue) {
        //  The channel is responsible for creating/cancelling consumers
        amq_server_channel_consume (channel, queue, self);
        amq_queue_unlink (&queue);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_CONSUME);        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_CONSUME);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_BASIC
    &&  self->method_id == AMQ_SERVER_BASIC_CANCEL) {
        amq_server_basic_cancel_t
            *method;
        method = &self->payload.basic_cancel;
        {
            amq_server_channel_cancel (channel, method->consumer_tag, TRUE, method->nowait);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_BASIC
    &&  self->method_id == AMQ_SERVER_BASIC_PUBLISH) {
        amq_server_basic_publish_t
            *method;
        amq_content_basic_t
            *content;
        method = &self->payload.basic_publish;
        content = (amq_content_basic_t *) self->content;
        {
            amq_exchange_t
        *exchange;
    icl_shortstr_t
        sender_id;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    if (*method->exchange)
        //  Lookup exchange specified in method
        exchange = amq_exchange_table_search (vhost->exchange_table, method->exchange);
    else
        //  Get default exchange for virtual host
        exchange = amq_exchange_link (vhost->default_exchange);

    if (exchange) {
        if (!exchange->internal || strnull (method->exchange)) {
            //  This method may only come from an external application
            assert (connection);
            amq_content_basic_set_routing_key (
                content,
                method->exchange,
                method->routing_key,
                connection->id);
            if (exchange->federation) {
                icl_shortstr_fmt (sender_id, "%s|%d", connection->key,
                    channel->number);
                amq_content_basic_set_sender_id (content, sender_id);
            }
            amq_exchange_publish (
                exchange,
                channel,
                content,
                method->mandatory,
                method->immediate,
                connection->group);
        }
        else
            amq_server_channel_error (channel,
                ASL_ACCESS_REFUSED, "Exchange is for internal use only",
                AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_PUBLISH);

        amq_exchange_unlink (&exchange);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND, "No such exchange defined",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_PUBLISH);        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_PUBLISH);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_BASIC
    &&  self->method_id == AMQ_SERVER_BASIC_GET) {
        amq_server_basic_get_t
            *method;
        method = &self->payload.basic_get;
        {
            amq_queue_t
        *queue;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    //  Use current channel queue if method uses a blank queue
    if (strnull (method->queue))
        icl_shortstr_cpy (method->queue, channel->current_queue);

    queue = amq_queue_table_search (vhost->queue_table, method->queue);
    if (queue) {
        amq_queue_get (queue, channel, self->class_id);
        amq_queue_unlink (&queue);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_GET);        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_GET);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_BASIC
    &&  self->method_id == AMQ_SERVER_BASIC_ACK) {
        amq_server_basic_ack_t
            *method;
        method = &self->payload.basic_ack;
        {
            amq_server_channel_ack (channel, method->delivery_tag, method->multiple);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_DIRECT
    &&  self->method_id == AMQ_SERVER_DIRECT_PUT) {
        amq_server_direct_put_t
            *method;
        method = &self->payload.direct_put;
        {
            amq_lease_t
        *lease;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    lease = amq_lease_new (vhost, method->sink, DP_SINK, channel);
    if (lease) {
        amq_server_agent_direct_put_ok (channel->connection->thread, channel->number, lease->name);
        amq_lease_unlink (&lease);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND,
            "No such sink",
            AMQ_SERVER_DIRECT, AMQ_SERVER_DIRECT_PUT);        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_DIRECT, AMQ_SERVER_DIRECT_PUT);
        }
    }
    else
    if (self->class_id  == AMQ_SERVER_DIRECT
    &&  self->method_id == AMQ_SERVER_DIRECT_GET) {
        amq_server_direct_get_t
            *method;
        method = &self->payload.direct_get;
        {
            amq_lease_t
        *lease;
    amq_vhost_t
        *vhost;
    vhost = amq_vhost_link (amq_broker->vhost);
    if (vhost) {    //
    lease = amq_lease_new (vhost, method->feed, DP_FEED, channel);
    if (lease) {
        amq_server_agent_direct_get_ok (channel->connection->thread, channel->number, lease->name);
        amq_lease_unlink (&lease);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND,
            "No such feed",
            AMQ_SERVER_DIRECT, AMQ_SERVER_DIRECT_GET);        amq_vhost_unlink (&vhost);
    }
    else
        amq_server_connection_error (connection, ASL_CONNECTION_FORCED, "Server not ready",
            AMQ_SERVER_DIRECT, AMQ_SERVER_DIRECT_GET);
        }
    }
</method>

<method name = "selftest" />

</class>
