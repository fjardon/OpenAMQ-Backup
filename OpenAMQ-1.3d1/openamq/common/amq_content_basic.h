/*---------------------------------------------------------------------------
    amq_content_basic.h - amq_content_basic component

    Generated from amq_content_basic.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_CONTENT_BASIC_SAFE
#   define INCLUDE_AMQ_CONTENT_BASIC_SAFE
#   define INCLUDE_AMQ_CONTENT_BASIC_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CONTENT_BASIC_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_content_basic_t amq_content_basic_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
#    define AMQ_CONTENT_BASIC_HISTORY_LENGTH 32
#endif

#define AMQ_CONTENT_BASIC_ALIVE         0xFABB
#define AMQ_CONTENT_BASIC_DEAD          0xDEAD

#define AMQ_CONTENT_BASIC_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_content_basic\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_CONTENT_BASIC_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_content_basic at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CONTENT_BASIC_ALIVE, self->object_tag);\
        amq_content_basic_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONTENT_BASIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONTENT_BASIC_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CONTENT_BASIC_UNSAFE
#   define INCLUDE_AMQ_CONTENT_BASIC_UNSAFE
#   define INCLUDE_AMQ_CONTENT_BASIC_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_content_basic_animating;

//  Structure of the amq_content_basic object

struct _amq_content_basic_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_CONTENT_BASIC_HISTORY_LENGTH];
    int
        history_line  [AMQ_CONTENT_BASIC_HISTORY_LENGTH];
    char
        *history_type [AMQ_CONTENT_BASIC_HISTORY_LENGTH];
    int
        history_links [AMQ_CONTENT_BASIC_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
dbyte
    class_id,                       //  Content class
    weight;                         //  Content weight
ipr_bucket_list_t
    *bucket_list;                   //  List of message buckets
int64_t
    body_size,                      //  Size of content body data
    body_expect;                    //  Expected size of body data
byte
    *body_data;                     //  Body set by application
icl_mem_free_fn
    *free_fn;                       //  Function to free appl_body
icl_shortstr_t
    exchange,                       //  Exchange specified by publish
    routing_key,                    //  Routing key specified by publish
    consumer_tag,                   //  Consumer tag specified by consume
    producer_id;                    //  Connection identifier of producer
int64_t
    delivery_tag;                   //  Delivery tag from queue

//  Used internally by servers processing the content
Bool
    immediate,                      //  Immediate delivery wanted
    redelivered,                    //  Content has been redelivered
    returned;                       //  Content was returned

//  Content properties
icl_shortstr_t
    content_type;                   //  MIME content type
icl_shortstr_t
    content_encoding;               //  MIME content encoding
icl_longstr_t *
    headers;                        //  Message header field table
byte
    delivery_mode;                  //  Non-persistent (1) or persistent (2)
byte
    priority;                       //  The message priority, 0 to 9
icl_shortstr_t
    correlation_id;                 //  The application correlation identifier
icl_shortstr_t
    reply_to;                       //  The destination to reply to
icl_shortstr_t
    expiration;                     //  Message expiration specification
icl_shortstr_t
    message_id;                     //  The application message identifier
int64_t
    timestamp;                      //  The message timestamp
icl_shortstr_t
    type;                           //  The message type name
icl_shortstr_t
    user_id;                        //  The creating user id
icl_shortstr_t
    app_id;                         //  The creating application id
icl_shortstr_t
    sender_id;                      //  Identifier of connection sending the message
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_content_basic_new()         amq_content_basic_new_ (__FILE__, __LINE__)
amq_content_basic_t *
    amq_content_basic_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    amq_content_basic_record_header (
amq_content_basic_t * self,             //  Not documented
ipr_bucket_t * bucket                   //  Bucket containing header
);

ipr_bucket_t *
    amq_content_basic_replay_header (
amq_content_basic_t * self              //  Reference to content
);

int
    amq_content_basic_record_body (
amq_content_basic_t * self,             //  Reference to object
ipr_bucket_t * bucket                   //  Bucket of raw data
);

int
    amq_content_basic_set_reader (
amq_content_basic_t * self,             //  Reference to object
asl_reader_t * reader,                  //  Reader to initialise
size_t frame_max                        //  Maximum frame size
);

ipr_bucket_t *
    amq_content_basic_replay_body (
amq_content_basic_t * self,             //  Reference to content
asl_reader_t * reader                   //  Reader to use
);

int
    amq_content_basic_set_body (
amq_content_basic_t * self,             //  Reference to object
void * data,                            //  Data for message content
size_t size,                            //  Length of message content
icl_mem_free_fn * free_fn               //  Function to free the memory
);

int
    amq_content_basic_get_body (
amq_content_basic_t * self,             //  Reference to object
byte * buffer,                          //  Buffer for message content
size_t maxsize                          //  Maximum size of buffer
);

int
    amq_content_basic_save_body (
amq_content_basic_t * self,             //  Reference to object
char * filename                         //  File to save to
);

int
    amq_content_basic_set_routing_key (
amq_content_basic_t * self,             //  Reference to object
char * exchange,                        //  Root exchange
char * routing_key,                     //  Routing key
char * producer_id                      //  Producer connection id
);

dbyte
    amq_content_basic_get_class_id (
amq_content_basic_t * self              //  Object reference
);

dbyte
    amq_content_basic_get_weight (
amq_content_basic_t * self              //  Object reference
);

int64_t
    amq_content_basic_get_body_size (
amq_content_basic_t * self              //  Object reference
);

char *
    amq_content_basic_get_exchange (
amq_content_basic_t * self              //  Object reference
);

char *
    amq_content_basic_get_routing_key (
amq_content_basic_t * self              //  Object reference
);

char *
    amq_content_basic_get_producer_id (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_content_type (
amq_content_basic_t * self,             //  Reference to object
char * content_type,                    //  MIME content type
...                                     //  Variable arguments
);

int
    amq_content_basic_set_content_type_v (
amq_content_basic_t * self,             //  Reference to object
char * content_type,                    //  MIME content type
va_list args                            //  Variable arguments
);

char *
    amq_content_basic_get_content_type (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_content_encoding (
amq_content_basic_t * self,             //  Reference to object
char * content_encoding,                //  MIME content encoding
...                                     //  Variable arguments
);

int
    amq_content_basic_set_content_encoding_v (
amq_content_basic_t * self,             //  Reference to object
char * content_encoding,                //  MIME content encoding
va_list args                            //  Variable arguments
);

char *
    amq_content_basic_get_content_encoding (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_headers (
amq_content_basic_t * self,             //  Reference to object
icl_longstr_t * headers                 //  Message header field table
);

icl_longstr_t *
    amq_content_basic_get_headers (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_delivery_mode (
amq_content_basic_t * self,             //  Reference to object
int delivery_mode                       //  Non-persistent (1) or persistent (2)
);

int
    amq_content_basic_get_delivery_mode (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_priority (
amq_content_basic_t * self,             //  Reference to object
int priority                            //  The message priority, 0 to 9
);

int
    amq_content_basic_get_priority (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_correlation_id (
amq_content_basic_t * self,             //  Reference to object
char * correlation_id,                  //  The application correlation identifier
...                                     //  Variable arguments
);

int
    amq_content_basic_set_correlation_id_v (
amq_content_basic_t * self,             //  Reference to object
char * correlation_id,                  //  The application correlation identifier
va_list args                            //  Variable arguments
);

char *
    amq_content_basic_get_correlation_id (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_reply_to (
amq_content_basic_t * self,             //  Reference to object
char * reply_to,                        //  The destination to reply to
...                                     //  Variable arguments
);

int
    amq_content_basic_set_reply_to_v (
amq_content_basic_t * self,             //  Reference to object
char * reply_to,                        //  The destination to reply to
va_list args                            //  Variable arguments
);

char *
    amq_content_basic_get_reply_to (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_expiration (
amq_content_basic_t * self,             //  Reference to object
char * expiration,                      //  Message expiration specification
...                                     //  Variable arguments
);

int
    amq_content_basic_set_expiration_v (
amq_content_basic_t * self,             //  Reference to object
char * expiration,                      //  Message expiration specification
va_list args                            //  Variable arguments
);

char *
    amq_content_basic_get_expiration (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_message_id (
amq_content_basic_t * self,             //  Reference to object
char * message_id,                      //  The application message identifier
...                                     //  Variable arguments
);

int
    amq_content_basic_set_message_id_v (
amq_content_basic_t * self,             //  Reference to object
char * message_id,                      //  The application message identifier
va_list args                            //  Variable arguments
);

char *
    amq_content_basic_get_message_id (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_timestamp (
amq_content_basic_t * self,             //  Reference to object
int64_t timestamp                       //  The message timestamp
);

int64_t
    amq_content_basic_get_timestamp (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_type (
amq_content_basic_t * self,             //  Reference to object
char * type,                            //  The message type name
...                                     //  Variable arguments
);

int
    amq_content_basic_set_type_v (
amq_content_basic_t * self,             //  Reference to object
char * type,                            //  The message type name
va_list args                            //  Variable arguments
);

char *
    amq_content_basic_get_type (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_user_id (
amq_content_basic_t * self,             //  Reference to object
char * user_id,                         //  The creating user id
...                                     //  Variable arguments
);

int
    amq_content_basic_set_user_id_v (
amq_content_basic_t * self,             //  Reference to object
char * user_id,                         //  The creating user id
va_list args                            //  Variable arguments
);

char *
    amq_content_basic_get_user_id (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_app_id (
amq_content_basic_t * self,             //  Reference to object
char * app_id,                          //  The creating application id
...                                     //  Variable arguments
);

int
    amq_content_basic_set_app_id_v (
amq_content_basic_t * self,             //  Reference to object
char * app_id,                          //  The creating application id
va_list args                            //  Variable arguments
);

char *
    amq_content_basic_get_app_id (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_sender_id (
amq_content_basic_t * self,             //  Reference to object
char * sender_id,                       //  Identifier of connection sending the message
...                                     //  Variable arguments
);

int
    amq_content_basic_set_sender_id_v (
amq_content_basic_t * self,             //  Reference to object
char * sender_id,                       //  Identifier of connection sending the message
va_list args                            //  Variable arguments
);

char *
    amq_content_basic_get_sender_id (
amq_content_basic_t * self              //  Object reference
);

int
    amq_content_basic_set_headers_field (
amq_content_basic_t * self,             //  Reference to object
char * name,                            //  Field name
char * value,                           //  Field value
...                                     //  Variable arguments
);

int
    amq_content_basic_set_headers_field_v (
amq_content_basic_t * self,             //  Reference to object
char * name,                            //  Field name
char * value,                           //  Field value
va_list args                            //  Variable arguments
);

int
    amq_content_basic_wire_put (
amq_content_basic_t * self,             //  Reference to object
ipr_bucket_t * bucket,                  //  Bucket to fill
byte options                            //  Options octet
);

size_t
    amq_content_basic_wire_size (
amq_content_basic_t * self              //  Not documented
);

amq_content_basic_t *
    amq_content_basic_wire_get (
ipr_bucket_t * bucket,                  //  Not documented
size_t * offset,                        //  Starting, ending offset in bucket
byte * options_p                        //  Options octet address
);

int
    amq_content_basic_wire_pending (
ipr_bucket_t * bucket                   //  Not documented
);

int
    amq_content_basic_chrono_set (
amq_content_basic_t * self              //  Reference to object
);

int
    amq_content_basic_chrono_add (
amq_content_basic_t * self              //  Reference to object
);

int
    amq_content_basic_chrono_get (
amq_content_basic_t * self,             //  Reference to object
char * deltas,                          //  Holds deltas
int floor                               //  Only if final delta GE this
);

void
    amq_content_basic_selftest (
void);

qbyte
    amq_content_basic_count (
void);

void
    amq_content_basic_terminate (
void);

#define amq_content_basic_show(item,opcode,trace_file)  amq_content_basic_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_content_basic_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_content_basic_destroy(self)  amq_content_basic_destroy_ (self, __FILE__, __LINE__)
void
    amq_content_basic_destroy_ (
amq_content_basic_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define amq_content_basic_link(self)    amq_content_basic_link_ (self, __FILE__, __LINE__)
amq_content_basic_t *
    amq_content_basic_link_ (
amq_content_basic_t * self,             //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_content_basic_unlink(self)  amq_content_basic_unlink_ (self, __FILE__, __LINE__)
void
    amq_content_basic_unlink_ (
amq_content_basic_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_content_basic_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_content_basic_new_in_scope(self_p,_scope)  amq_content_basic_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_content_basic_new_in_scope_ (
amq_content_basic_t * * self_p,         //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONTENT_BASIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONTENT_BASIC_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CONTENT_BASIC_INLINE)
#   define INCLUDE_AMQ_CONTENT_BASIC_INLINE
#   define INCLUDE_AMQ_CONTENT_BASIC_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_NEW)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_DESTROY)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_RECORD_HEADER)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_REPLAY_HEADER)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_RECORD_BODY)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_READER)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_REPLAY_BODY)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_BODY)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_BODY)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SAVE_BODY)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_ROUTING_KEY)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_CLASS_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_WEIGHT)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_BODY_SIZE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_EXCHANGE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_ROUTING_KEY)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_PRODUCER_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_CONTENT_TYPE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_CONTENT_TYPE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_CONTENT_ENCODING)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_CONTENT_ENCODING)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_HEADERS)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_HEADERS)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_DELIVERY_MODE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_DELIVERY_MODE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_PRIORITY)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_PRIORITY)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_CORRELATION_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_CORRELATION_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_REPLY_TO)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_REPLY_TO)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_EXPIRATION)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_EXPIRATION)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_MESSAGE_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_MESSAGE_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_TIMESTAMP)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_TIMESTAMP)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_TYPE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_TYPE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_USER_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_USER_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_APP_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_APP_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_SENDER_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_GET_SENDER_ID)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SET_HEADERS_FIELD)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_WIRE_PUT)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_WIRE_SIZE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_WIRE_GET)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_WIRE_PENDING)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_CHRONO_SET)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_CHRONO_ADD)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_CHRONO_GET)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SELFTEST)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_COUNT)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_TERMINATE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_SHOW)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_ALLOC)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_FREE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_LINK)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_UNLINK)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_ANIMATE)   || defined (BASE_TRACE_AMQ_CONTENT_BASIC_NEW_IN_SCOPE) )
void
    amq_content_basic_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONTENT_BASIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONTENT_BASIC_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CONTENT_BASIC_ROOT
#   endif
# endif
#endif
