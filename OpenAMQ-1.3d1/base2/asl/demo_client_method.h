/*---------------------------------------------------------------------------
    demo_client_method.h - demo_client_method component

This class holds a method.  All protocol methods are held in a single
union that can be processed as a single entity.
    Generated from demo_client_method.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_DEMO_CLIENT_METHOD_SAFE
#   define INCLUDE_DEMO_CLIENT_METHOD_SAFE
#   define INCLUDE_DEMO_CLIENT_METHOD_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_DEMO_CLIENT_METHOD_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _demo_client_method_t demo_client_method_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_CLIENT_METHOD)
#    define DEMO_CLIENT_METHOD_HISTORY_LENGTH 32
#endif

#define DEMO_CLIENT_METHOD_ALIVE        0xFABB
#define DEMO_CLIENT_METHOD_DEAD         0xDEAD

#define DEMO_CLIENT_METHOD_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL demo_client_method\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != DEMO_CLIENT_METHOD_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "demo_client_method at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, DEMO_CLIENT_METHOD_ALIVE, self->object_tag);\
        demo_client_method_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#define DEMO_CLIENT_CONNECTION              10
#define DEMO_CLIENT_CONNECTION_START        10
#define DEMO_CLIENT_CONNECTION_START_OK     11
#define DEMO_CLIENT_CONNECTION_SECURE       20
#define DEMO_CLIENT_CONNECTION_SECURE_OK    21
#define DEMO_CLIENT_CONNECTION_TUNE         30
#define DEMO_CLIENT_CONNECTION_TUNE_OK      31
#define DEMO_CLIENT_CONNECTION_OPEN         40
#define DEMO_CLIENT_CONNECTION_OPEN_OK      41
#define DEMO_CLIENT_CONNECTION_CLOSE        50
#define DEMO_CLIENT_CONNECTION_CLOSE_OK     51

#define DEMO_CLIENT_CHANNEL                 20
#define DEMO_CLIENT_CHANNEL_OPEN            10
#define DEMO_CLIENT_CHANNEL_OPEN_OK         11
#define DEMO_CLIENT_CHANNEL_FLOW            20
#define DEMO_CLIENT_CHANNEL_FLOW_OK         21
#define DEMO_CLIENT_CHANNEL_CLOSE           40
#define DEMO_CLIENT_CHANNEL_CLOSE_OK        41

#define DEMO_CLIENT_EXCHANGE                40
#define DEMO_CLIENT_EXCHANGE_DECLARE        10
#define DEMO_CLIENT_EXCHANGE_DECLARE_OK     11
#define DEMO_CLIENT_EXCHANGE_DELETE         20
#define DEMO_CLIENT_EXCHANGE_DELETE_OK      21

#define DEMO_CLIENT_QUEUE                   50
#define DEMO_CLIENT_QUEUE_DECLARE           10
#define DEMO_CLIENT_QUEUE_DECLARE_OK        11
#define DEMO_CLIENT_QUEUE_BIND              20
#define DEMO_CLIENT_QUEUE_BIND_OK           21
#define DEMO_CLIENT_QUEUE_PURGE             30
#define DEMO_CLIENT_QUEUE_PURGE_OK          31
#define DEMO_CLIENT_QUEUE_DELETE            40
#define DEMO_CLIENT_QUEUE_DELETE_OK         41

#define DEMO_CLIENT_BASIC                   60
#define DEMO_CLIENT_BASIC_CONSUME           10
#define DEMO_CLIENT_BASIC_CONSUME_OK        11
#define DEMO_CLIENT_BASIC_CANCEL            20
#define DEMO_CLIENT_BASIC_CANCEL_OK         21
#define DEMO_CLIENT_BASIC_PUBLISH           30
#define DEMO_CLIENT_BASIC_DELIVER           40
#define DEMO_CLIENT_BASIC_GET               50
#define DEMO_CLIENT_BASIC_GET_OK            51
#define DEMO_CLIENT_BASIC_GET_EMPTY         52

#define DEMO_CLIENT_DIRECT                  61500
#define DEMO_CLIENT_DIRECT_PUT              10
#define DEMO_CLIENT_DIRECT_PUT_OK           11
#define DEMO_CLIENT_DIRECT_GET              20
#define DEMO_CLIENT_DIRECT_GET_OK           21

typedef struct _demo_client_connection_start_t demo_client_connection_start_t;
typedef struct _demo_client_connection_start_ok_t demo_client_connection_start_ok_t;
typedef struct _demo_client_connection_secure_t demo_client_connection_secure_t;
typedef struct _demo_client_connection_secure_ok_t demo_client_connection_secure_ok_t;
typedef struct _demo_client_connection_tune_t demo_client_connection_tune_t;
typedef struct _demo_client_connection_tune_ok_t demo_client_connection_tune_ok_t;
typedef struct _demo_client_connection_open_t demo_client_connection_open_t;
typedef struct _demo_client_connection_open_ok_t demo_client_connection_open_ok_t;
typedef struct _demo_client_connection_close_t demo_client_connection_close_t;
typedef struct _demo_client_connection_close_ok_t demo_client_connection_close_ok_t;
typedef struct _demo_client_channel_open_t demo_client_channel_open_t;
typedef struct _demo_client_channel_open_ok_t demo_client_channel_open_ok_t;
typedef struct _demo_client_channel_flow_t demo_client_channel_flow_t;
typedef struct _demo_client_channel_flow_ok_t demo_client_channel_flow_ok_t;
typedef struct _demo_client_channel_close_t demo_client_channel_close_t;
typedef struct _demo_client_channel_close_ok_t demo_client_channel_close_ok_t;
typedef struct _demo_client_exchange_declare_t demo_client_exchange_declare_t;
typedef struct _demo_client_exchange_declare_ok_t demo_client_exchange_declare_ok_t;
typedef struct _demo_client_exchange_delete_t demo_client_exchange_delete_t;
typedef struct _demo_client_exchange_delete_ok_t demo_client_exchange_delete_ok_t;
typedef struct _demo_client_queue_declare_t demo_client_queue_declare_t;
typedef struct _demo_client_queue_declare_ok_t demo_client_queue_declare_ok_t;
typedef struct _demo_client_queue_bind_t demo_client_queue_bind_t;
typedef struct _demo_client_queue_bind_ok_t demo_client_queue_bind_ok_t;
typedef struct _demo_client_queue_purge_t demo_client_queue_purge_t;
typedef struct _demo_client_queue_purge_ok_t demo_client_queue_purge_ok_t;
typedef struct _demo_client_queue_delete_t demo_client_queue_delete_t;
typedef struct _demo_client_queue_delete_ok_t demo_client_queue_delete_ok_t;
typedef struct _demo_client_basic_consume_t demo_client_basic_consume_t;
typedef struct _demo_client_basic_consume_ok_t demo_client_basic_consume_ok_t;
typedef struct _demo_client_basic_cancel_t demo_client_basic_cancel_t;
typedef struct _demo_client_basic_cancel_ok_t demo_client_basic_cancel_ok_t;
typedef struct _demo_client_basic_publish_t demo_client_basic_publish_t;
typedef struct _demo_client_basic_deliver_t demo_client_basic_deliver_t;
typedef struct _demo_client_basic_get_t demo_client_basic_get_t;
typedef struct _demo_client_basic_get_ok_t demo_client_basic_get_ok_t;
typedef struct _demo_client_basic_get_empty_t demo_client_basic_get_empty_t;
typedef struct _demo_client_direct_put_t demo_client_direct_put_t;
typedef struct _demo_client_direct_put_ok_t demo_client_direct_put_ok_t;
typedef struct _demo_client_direct_get_t demo_client_direct_get_t;
typedef struct _demo_client_direct_get_ok_t demo_client_direct_get_ok_t;
#   ifdef __cplusplus
}
#   endif

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "demo_constants.h"
#   include "demo_client_agent.h"
#   include "demo_content_basic.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_CLIENT_METHOD_ACTIVE
#   if defined (ICL_IMPORT_DEMO_CLIENT_METHOD_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_DEMO_CLIENT_METHOD_UNSAFE
#   define INCLUDE_DEMO_CLIENT_METHOD_UNSAFE
#   define INCLUDE_DEMO_CLIENT_METHOD_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "demo_constants.h"
#   include "demo_client_agent.h"
#   include "demo_content_basic.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    demo_client_method_animating;
//  Start Connection Negotiation

struct _demo_client_connection_start_t {
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

struct _demo_client_connection_start_ok_t {
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

struct _demo_client_connection_secure_t {
    icl_longstr_t *
        challenge;                      //  security challenge data
};

//  Security Mechanism Response

struct _demo_client_connection_secure_ok_t {
    icl_longstr_t *
        response;                       //  security response data
};

//  Propose Connection Tuning Parameters

struct _demo_client_connection_tune_t {
    dbyte
        channel_max;                    //  proposed maximum channels
    qbyte
        frame_max;                      //  proposed maximum frame size
    dbyte
        heartbeat;                      //  desired heartbeat delay
};

//  Negotiate Connection Tuning Parameters

struct _demo_client_connection_tune_ok_t {
    dbyte
        channel_max;                    //  negotiated maximum channels
    qbyte
        frame_max;                      //  negotiated maximum frame size
    dbyte
        heartbeat;                      //  desired heartbeat delay
};

//  Open Connection To Virtual Host

struct _demo_client_connection_open_t {
    icl_shortstr_t
        virtual_host;                   //  virtual host name
    icl_shortstr_t
        capabilities;                   //  required capabilities
    Bool
        insist;                         //  insist on connecting to server
};

//  Signal That The Connection Is Ready

struct _demo_client_connection_open_ok_t {
    icl_shortstr_t
        known_hosts;                    //  list of known hosts
};

//  Request A Connection Close

struct _demo_client_connection_close_t {
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

struct _demo_client_connection_close_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Open A Channel For Use

struct _demo_client_channel_open_t {
    icl_shortstr_t
        out_of_band;                    //  out-of-band settings
};

//  Signal That The Channel Is Ready

struct _demo_client_channel_open_ok_t {
    icl_longstr_t *
        channel_id;                     //  unique id of the channel
};

//  Enable/Disable Flow From Peer

struct _demo_client_channel_flow_t {
    Bool
        active;                         //  start/stop content frames
};

//  Confirm A Flow Method

struct _demo_client_channel_flow_ok_t {
    Bool
        active;                         //  current flow setting
};

//  Request A Channel Close

struct _demo_client_channel_close_t {
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

struct _demo_client_channel_close_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Declare Exchange, Create If Needed

struct _demo_client_exchange_declare_t {
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        type;                           //  exchange class
    Bool
        passive;                        //  do not create exchange
    Bool
        durable;                        //  request a durable exchange
    Bool
        auto_delete;                    //  auto-delete when unused
};

//  Confirms An Exchange Declaration

struct _demo_client_exchange_declare_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Delete An Exchange

struct _demo_client_exchange_delete_t {
    icl_shortstr_t
        exchange;                       //  exchange name
    Bool
        if_unused;                      //  delete only if unused
};

//  Confirm Deletion Of An Exchange

struct _demo_client_exchange_delete_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Declare Queue, Create If Needed

struct _demo_client_queue_declare_t {
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
};

//  Confirms A Queue Definition

struct _demo_client_queue_declare_ok_t {
    icl_shortstr_t
        queue;                          //  queue name
    icl_longstr_t *
        properties;                     //  queue properties
};

//  Bind Queue To An Exchange

struct _demo_client_queue_bind_t {
    icl_shortstr_t
        queue;                          //  queue name
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_longstr_t *
        arguments;                      //  arguments for binding
};

//  Confirm Bind Successful

struct _demo_client_queue_bind_ok_t {
    int
        filler;                         //  No method-specific fields          
};

//  Purge A Queue

struct _demo_client_queue_purge_t {
    icl_shortstr_t
        queue;                          //  queue name
};

//  Confirms A Queue Purge

struct _demo_client_queue_purge_ok_t {
    qbyte
        message_count;                  //  number of messages purged
};

//  Delete A Queue

struct _demo_client_queue_delete_t {
    icl_shortstr_t
        queue;                          //  queue name
    Bool
        if_unused;                      //  delete only if unused
    Bool
        if_empty;                       //  delete only if empty
};

//  Confirm Deletion Of A Queue

struct _demo_client_queue_delete_ok_t {
    qbyte
        message_count;                  //  number of messages purged
};

//  Start A Queue Consumer

struct _demo_client_basic_consume_t {
    icl_shortstr_t
        queue;                          //  queue name
};

//  Confirm A New Consumer

struct _demo_client_basic_consume_ok_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
};

//  End A Queue Consumer

struct _demo_client_basic_cancel_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
};

//  Confirm A Cancelled Consumer

struct _demo_client_basic_cancel_ok_t {
    icl_shortstr_t
        consumer_tag;                   //  consumer tag
};

//  Publish A Message

struct _demo_client_basic_publish_t {
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        routing_key;                    //  Message routing key
};

//  Notify The Client Of A Consumer Message

struct _demo_client_basic_deliver_t {
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        routing_key;                    //  Message routing key
    int64_t
        delivery_tag;                   //  server-assigned delivery tag
};

//  Direct Access To A Queue

struct _demo_client_basic_get_t {
    icl_shortstr_t
        queue;                          //  queue name
};

//  Provide Client With A Message

struct _demo_client_basic_get_ok_t {
    icl_shortstr_t
        exchange;                       //  exchange name
    icl_shortstr_t
        routing_key;                    //  Message routing key
    qbyte
        message_count;                  //  number of messages pending
};

//  Indicate No Messages Available

struct _demo_client_basic_get_empty_t {
    int
        filler;                         //  No method-specific fields          
};

//  Request A Connection To A Sink

struct _demo_client_direct_put_t {
    icl_shortstr_t
        sink;                           //  Sink name
};

//  Grant Access To The Sink

struct _demo_client_direct_put_ok_t {
    icl_shortstr_t
        lease;                          //  Lease for connection
};

//  Request A Connection To A Feed

struct _demo_client_direct_get_t {
    icl_shortstr_t
        feed;                           //  Feed name
};

//  Grant Access To The Feed

struct _demo_client_direct_get_ok_t {
    icl_shortstr_t
        lease;                          //  Lease for connection
};

//  Structure of the demo_client_method object

struct _demo_client_method_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_CLIENT_METHOD)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [DEMO_CLIENT_METHOD_HISTORY_LENGTH];
    int
        history_line  [DEMO_CLIENT_METHOD_HISTORY_LENGTH];
    char
        *history_type [DEMO_CLIENT_METHOD_HISTORY_LENGTH];
    int
        history_links [DEMO_CLIENT_METHOD_HISTORY_LENGTH];
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
    demo_client_connection_start_t
        connection_start;
    demo_client_connection_start_ok_t
        connection_start_ok;
    demo_client_connection_secure_t
        connection_secure;
    demo_client_connection_secure_ok_t
        connection_secure_ok;
    demo_client_connection_tune_t
        connection_tune;
    demo_client_connection_tune_ok_t
        connection_tune_ok;
    demo_client_connection_open_t
        connection_open;
    demo_client_connection_open_ok_t
        connection_open_ok;
    demo_client_connection_close_t
        connection_close;
    demo_client_connection_close_ok_t
        connection_close_ok;
    demo_client_channel_open_t
        channel_open;
    demo_client_channel_open_ok_t
        channel_open_ok;
    demo_client_channel_flow_t
        channel_flow;
    demo_client_channel_flow_ok_t
        channel_flow_ok;
    demo_client_channel_close_t
        channel_close;
    demo_client_channel_close_ok_t
        channel_close_ok;
    demo_client_exchange_declare_t
        exchange_declare;
    demo_client_exchange_declare_ok_t
        exchange_declare_ok;
    demo_client_exchange_delete_t
        exchange_delete;
    demo_client_exchange_delete_ok_t
        exchange_delete_ok;
    demo_client_queue_declare_t
        queue_declare;
    demo_client_queue_declare_ok_t
        queue_declare_ok;
    demo_client_queue_bind_t
        queue_bind;
    demo_client_queue_bind_ok_t
        queue_bind_ok;
    demo_client_queue_purge_t
        queue_purge;
    demo_client_queue_purge_ok_t
        queue_purge_ok;
    demo_client_queue_delete_t
        queue_delete;
    demo_client_queue_delete_ok_t
        queue_delete_ok;
    demo_client_basic_consume_t
        basic_consume;
    demo_client_basic_consume_ok_t
        basic_consume_ok;
    demo_client_basic_cancel_t
        basic_cancel;
    demo_client_basic_cancel_ok_t
        basic_cancel_ok;
    demo_client_basic_publish_t
        basic_publish;
    demo_client_basic_deliver_t
        basic_deliver;
    demo_client_basic_get_t
        basic_get;
    demo_client_basic_get_ok_t
        basic_get_ok;
    demo_client_basic_get_empty_t
        basic_get_empty;
    demo_client_direct_put_t
        direct_put;
    demo_client_direct_put_ok_t
        direct_put_ok;
    demo_client_direct_get_t
        direct_get;
    demo_client_direct_get_ok_t
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
#define demo_client_method_new()        demo_client_method_new_ (__FILE__, __LINE__)
demo_client_method_t *
    demo_client_method_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

demo_client_method_t *
    demo_client_method_new_connection_start_ok (
icl_longstr_t * client_properties,      //  client properties
char * mechanism,                       //  selected security mechanism
icl_longstr_t * response,               //  security response data
char * locale                           //  selected message locale
);

demo_client_method_t *
    demo_client_method_new_connection_secure_ok (
icl_longstr_t * response                //  security response data
);

demo_client_method_t *
    demo_client_method_new_connection_tune_ok (
int channel_max,                        //  negotiated maximum channels
qbyte frame_max,                        //  negotiated maximum frame size
int heartbeat                           //  desired heartbeat delay
);

demo_client_method_t *
    demo_client_method_new_connection_open (
char * virtual_host,                    //  virtual host name
char * capabilities,                    //  required capabilities
Bool insist                             //  insist on connecting to server
);

demo_client_method_t *
    demo_client_method_new_connection_close (
int reply_code,                         //  reply code from server
char * reply_text,                      //  localised reply text
int class_id,                           //  failing method class
int method_id                           //  failing method ID
);

demo_client_method_t *
    demo_client_method_new_connection_close_ok (
void);

demo_client_method_t *
    demo_client_method_new_channel_open (
char * out_of_band                      //  out-of-band settings
);

demo_client_method_t *
    demo_client_method_new_channel_flow (
Bool active                             //  start/stop content frames
);

demo_client_method_t *
    demo_client_method_new_channel_flow_ok (
Bool active                             //  current flow setting
);

demo_client_method_t *
    demo_client_method_new_channel_close (
int reply_code,                         //  reply code from server
char * reply_text,                      //  localised reply text
int class_id,                           //  failing method class
int method_id                           //  failing method ID
);

demo_client_method_t *
    demo_client_method_new_channel_close_ok (
void);

demo_client_method_t *
    demo_client_method_new_exchange_declare (
char * exchange,                        //  exchange name
char * type,                            //  exchange class
Bool passive,                           //  do not create exchange
Bool durable,                           //  request a durable exchange
Bool auto_delete                        //  auto-delete when unused
);

demo_client_method_t *
    demo_client_method_new_exchange_delete (
char * exchange,                        //  exchange name
Bool if_unused                          //  delete only if unused
);

demo_client_method_t *
    demo_client_method_new_queue_declare (
char * queue,                           //  queue name
Bool passive,                           //  do not create queue
Bool durable,                           //  request a durable queue
Bool exclusive,                         //  request an exclusive queue
Bool auto_delete                        //  auto-delete queue when unused
);

demo_client_method_t *
    demo_client_method_new_queue_bind (
char * queue,                           //  queue name
char * exchange,                        //  exchange name
icl_longstr_t * arguments               //  arguments for binding
);

demo_client_method_t *
    demo_client_method_new_queue_purge (
char * queue                            //  queue name
);

demo_client_method_t *
    demo_client_method_new_queue_delete (
char * queue,                           //  queue name
Bool if_unused,                         //  delete only if unused
Bool if_empty                           //  delete only if empty
);

demo_client_method_t *
    demo_client_method_new_basic_consume (
char * queue                            //  queue name
);

demo_client_method_t *
    demo_client_method_new_basic_cancel (
char * consumer_tag                     //  consumer tag
);

demo_client_method_t *
    demo_client_method_new_basic_publish (
char * exchange,                        //  exchange name
char * routing_key                      //  Message routing key
);

demo_client_method_t *
    demo_client_method_new_basic_get (
char * queue                            //  queue name
);

demo_client_method_t *
    demo_client_method_new_direct_put (
char * sink                             //  Sink name
);

demo_client_method_t *
    demo_client_method_new_direct_get (
char * feed                             //  Feed name
);

ipr_bucket_t *
    demo_client_method_encode (
demo_client_method_t * self             //  Method reference
);

demo_client_method_t *
    demo_client_method_decode (
ipr_bucket_t * bucket,                  //  New bucket
char * strerror                         //  Error text, if any
);

int
    demo_client_method_dump (
demo_client_method_t * self,            //  Reference to object
smt_log_t * log,                        //  Log file, if any
char * prefix                           //  Prefix for line
);

int
    demo_client_method_execute (
demo_client_method_t * self,            //  Reference to object
demo_client_connection_t * connection,   //  Current connection
demo_client_session_t * session         //  Current session
);

void
    demo_client_method_selftest (
void);

#define demo_client_method_show(item,opcode,trace_file)  demo_client_method_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    demo_client_method_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define demo_client_method_destroy(self)  demo_client_method_destroy_ (self, __FILE__, __LINE__)
void
    demo_client_method_destroy_ (
demo_client_method_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define demo_client_method_link(self)   demo_client_method_link_ (self, __FILE__, __LINE__)
demo_client_method_t *
    demo_client_method_link_ (
demo_client_method_t * self,            //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define demo_client_method_unlink(self)  demo_client_method_unlink_ (self, __FILE__, __LINE__)
void
    demo_client_method_unlink_ (
demo_client_method_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    demo_client_method_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define demo_client_method_new_in_scope(self_p,_scope)  demo_client_method_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    demo_client_method_new_in_scope_ (
demo_client_method_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_CLIENT_METHOD_ACTIVE
#   if defined (ICL_IMPORT_DEMO_CLIENT_METHOD_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_DEMO_CLIENT_METHOD_INLINE)
#   define INCLUDE_DEMO_CLIENT_METHOD_INLINE
#   define INCLUDE_DEMO_CLIENT_METHOD_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "smt_log.h"
#   include "demo_constants.h"
#   include "demo_client_agent.h"
#   include "demo_content_basic.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_DESTROY)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_INITIALISE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_TERMINATE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_CONNECTION_START_OK)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_CONNECTION_SECURE_OK)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_CONNECTION_TUNE_OK)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_CONNECTION_OPEN)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_CONNECTION_CLOSE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_CONNECTION_CLOSE_OK)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_CHANNEL_OPEN)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_CHANNEL_FLOW)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_CHANNEL_FLOW_OK)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_CHANNEL_CLOSE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_CHANNEL_CLOSE_OK)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_EXCHANGE_DECLARE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_EXCHANGE_DELETE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_QUEUE_DECLARE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_QUEUE_BIND)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_QUEUE_PURGE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_QUEUE_DELETE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_BASIC_CONSUME)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_BASIC_CANCEL)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_BASIC_PUBLISH)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_BASIC_GET)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_DIRECT_PUT)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_DIRECT_GET)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_ENCODE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_DECODE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_DUMP)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_EXECUTE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_SELFTEST)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_SHOW)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_ALLOC)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_FREE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_LINK)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_UNLINK)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_ANIMATE)   || defined (BASE_TRACE_DEMO_CLIENT_METHOD_NEW_IN_SCOPE) )
void
    demo_client_method_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_CLIENT_METHOD_ACTIVE
#   if defined (ICL_IMPORT_DEMO_CLIENT_METHOD_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_DEMO_CLIENT_METHOD_ROOT
#   endif
# endif
#endif
