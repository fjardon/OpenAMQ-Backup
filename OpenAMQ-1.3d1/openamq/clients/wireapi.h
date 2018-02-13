/*---------------------------------------------------------------------------
    amq_client_connection.h - amq_client_connection component

A amq_client_connection object establishes and manages a single
connection to a amq server. The connection can hold
many sessions - each is a amq_client_session object. To use this
API, first create a connection to the server, then create one or
more sessions and do work on the sessions. Each session represents
a serial stream of work. In simple applications, a single session
is usually sufficient. In multithreaded applications, each thread
will want its own session.
    Generated from amq_client_connection.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_CLIENT_CONNECTION_SAFE
#   define INCLUDE_AMQ_CLIENT_CONNECTION_SAFE
#   define INCLUDE_AMQ_CLIENT_CONNECTION_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CLIENT_CONNECTION_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_client_connection_t amq_client_connection_t;

#define AMQ_CLIENT_CONNECTION_ALIVE     0xFABB
#define AMQ_CLIENT_CONNECTION_DEAD      0xDEAD

#define AMQ_CLIENT_CONNECTION_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_client_connection\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_CLIENT_CONNECTION_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_client_connection at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CLIENT_CONNECTION_ALIVE, self->object_tag);\
        amq_client_connection_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "asl.h"
#   include "amq_constants.h"
#   include "amq_client_session.h"
#   include "amq_content_basic.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CLIENT_CONNECTION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CLIENT_CONNECTION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CLIENT_CONNECTION_UNSAFE
#   define INCLUDE_AMQ_CLIENT_CONNECTION_UNSAFE
#   define INCLUDE_AMQ_CLIENT_CONNECTION_ACTIVE

#   include "asl.h"
#   include "amq_constants.h"
#   include "amq_client_session.h"
#   include "amq_content_basic.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_client_connection_animating;

//  Structure of the amq_client_connection object

struct _amq_client_connection_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;                        //  Thread for this connection
smt_method_queue_t
    *method_queue;                  //  Replies from protocol agent
dbyte
    channel_nbr;                    //  Top channel opened so far
Bool
    silent;                         //  Don't print errors
Bool
    alive;                          //  Connection is alive?
Bool
    interrupt;                      //  Application was interrupted?
Bool
    shutdown;                       //  We were shutdown
int
    trace,                          //  Trace level 0-3
    timeout;                        //  Connection timeout, msecs
char
    *error_text;                    //  Last error cause
Bool
    direct;                         //  Use Direct Protocol
icl_shortstr_t
    host;                           //  Host we connected to
byte
    version_major;                  //  protocol major version
byte
    version_minor;                  //  protocol major version
dbyte
    channel_max;                    //  proposed maximum channels
qbyte
    frame_max;                      //  proposed maximum frame size
dbyte
    heartbeat;                      //  desired heartbeat delay
icl_shortstr_t
    known_hosts;                    //  list of known hosts
dbyte
    reply_code;                     //  reply code from server
icl_shortstr_t
    reply_text;                     //  localised reply text
dbyte
    class_id;                       //  failing method class
dbyte
    method_id;                      //  failing method ID
icl_shortstr_t
    server_host;                    //  Reported by server
icl_shortstr_t
    server_port;                    //  Just the port number
icl_shortstr_t
    server_product;
icl_shortstr_t
    server_version;
icl_shortstr_t
    server_platform;
icl_shortstr_t
    server_copyright;
icl_shortstr_t
    server_information;
icl_shortstr_t
    server_instance;
icl_shortstr_t
    id;                             //  Server-assigned ID
Bool
    server_direct;                  //  Server proposes Direct Mode?
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_client_connection_new(host,virtual_host,auth_data,instance,trace,timeout)  amq_client_connection_new_ (__FILE__, __LINE__, host, virtual_host, auth_data, instance, trace, timeout)
amq_client_connection_t *
    amq_client_connection_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
char * host,                            //  Host to connect to
char * virtual_host,                    //  Virtual host
icl_longstr_t * auth_data,              //  Authentication data
char* instance,                         //  Client instance name
int trace,                              //  Trace level, 0 - 3
int timeout                             //  Connection timeout, msecs
);

icl_longstr_t *
    amq_client_connection_auth_plain (
char * login,                           //  User login name
char * password                         //  User password
);

int
    amq_client_connection_wait (
amq_client_connection_t * self,         //  Reference to object
int timeout                             //  Timeout, in milliseconds
);

int
    amq_client_connection_set_silent (
amq_client_connection_t * self,         //  Reference to object
Bool silent                             //  Not documented
);

int
    amq_client_connection_set_timeout (
amq_client_connection_t * self,         //  Reference to object
Bool timeout                            //  Not documented
);

Bool
    amq_client_connection_get_silent (
amq_client_connection_t * self          //  Object reference
);

Bool
    amq_client_connection_get_alive (
amq_client_connection_t * self          //  Object reference
);

char *
    amq_client_connection_get_error_text (
amq_client_connection_t * self          //  Object reference
);

int
    amq_client_connection_get_version_major (
amq_client_connection_t * self          //  Object reference
);

int
    amq_client_connection_get_version_minor (
amq_client_connection_t * self          //  Object reference
);

int
    amq_client_connection_get_channel_max (
amq_client_connection_t * self          //  Object reference
);

qbyte
    amq_client_connection_get_frame_max (
amq_client_connection_t * self          //  Object reference
);

int
    amq_client_connection_get_heartbeat (
amq_client_connection_t * self          //  Object reference
);

char *
    amq_client_connection_get_known_hosts (
amq_client_connection_t * self          //  Object reference
);

int
    amq_client_connection_get_reply_code (
amq_client_connection_t * self          //  Object reference
);

char *
    amq_client_connection_get_reply_text (
amq_client_connection_t * self          //  Object reference
);

int
    amq_client_connection_get_class_id (
amq_client_connection_t * self          //  Object reference
);

int
    amq_client_connection_get_method_id (
amq_client_connection_t * self          //  Object reference
);

void
    amq_client_connection_selftest (
void);

#define amq_client_connection_show(item,opcode,trace_file)  amq_client_connection_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_client_connection_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_client_connection_destroy(self)  amq_client_connection_destroy_ (self, __FILE__, __LINE__)
void
    amq_client_connection_destroy_ (
amq_client_connection_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    amq_client_connection_read_lock (
amq_client_connection_t * self          //  Reference to object
);

int
    amq_client_connection_write_lock (
amq_client_connection_t * self          //  Reference to object
);

int
    amq_client_connection_unlock (
amq_client_connection_t * self          //  Reference to object
);

void
    amq_client_connection_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_client_connection_new_in_scope(self_p,_scope,host,virtual_host,auth_data,instance,trace,timeout)  amq_client_connection_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, host, virtual_host, auth_data, instance, trace, timeout)
void
    amq_client_connection_new_in_scope_ (
amq_client_connection_t * * self_p,     //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
char * host,                            //  Host to connect to
char * virtual_host,                    //  Virtual host
icl_longstr_t * auth_data,              //  Authentication data
char* instance,                         //  Client instance name
int trace,                              //  Trace level, 0 - 3
int timeout                             //  Connection timeout, msecs
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CLIENT_CONNECTION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CLIENT_CONNECTION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CLIENT_CONNECTION_INLINE)
#   define INCLUDE_AMQ_CLIENT_CONNECTION_INLINE
#   define INCLUDE_AMQ_CLIENT_CONNECTION_ACTIVE

#   include "asl.h"
#   include "amq_constants.h"
#   include "amq_client_session.h"
#   include "amq_content_basic.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_NEW)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_DESTROY)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_AUTH_PLAIN)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_WAIT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SET_SILENT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SET_TIMEOUT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_SILENT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_ALIVE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_ERROR_TEXT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_VERSION_MAJOR)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_VERSION_MINOR)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_CHANNEL_MAX)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_FRAME_MAX)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_HEARTBEAT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_KNOWN_HOSTS)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_REPLY_CODE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_REPLY_TEXT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_CLASS_ID)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_METHOD_ID)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_INITIALISE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_TERMINATE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SELFTEST)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SHOW)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_ALLOC)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_FREE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_READ_LOCK)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_UNLOCK)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_ANIMATE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_NEW_IN_SCOPE) )
void
    amq_client_connection_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CLIENT_CONNECTION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CLIENT_CONNECTION_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CLIENT_CONNECTION_ROOT
#   endif
# endif
#endif
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
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_client_session\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_CLIENT_SESSION_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_client_session at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CLIENT_SESSION_ALIVE, self->object_tag);\
        amq_client_session_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
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
    amq_client_session_animate (
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

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_NEW)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_DESTROY)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_WAIT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_CHANNEL_FLOW)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_CHANNEL_FLOW_OK)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_EXCHANGE_DECLARE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_EXCHANGE_DECLARE_NOWAIT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_EXCHANGE_DELETE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_EXCHANGE_DELETE_NOWAIT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_QUEUE_DECLARE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_QUEUE_DECLARE_NOWAIT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_QUEUE_BIND)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_QUEUE_BIND_NOWAIT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_QUEUE_PURGE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_QUEUE_PURGE_NOWAIT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_QUEUE_DELETE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_QUEUE_DELETE_NOWAIT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_QUEUE_UNBIND)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_QUEUE_UNBIND_NOWAIT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_BASIC_QOS)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_BASIC_CONSUME)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_BASIC_CONSUME_NOWAIT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_BASIC_CANCEL)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_BASIC_CANCEL_NOWAIT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_BASIC_PUBLISH)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_BASIC_GET)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_BASIC_ACK)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_BASIC_REJECT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_PUSH_ARRIVED)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_PUSH_RETURNED)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_BASIC_ARRIVED_COUNT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_BASIC_ARRIVED)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_BASIC_RETURNED_COUNT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_BASIC_RETURNED)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_ALIVE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_ERROR_TEXT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_LEASE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_CHANNEL_ID)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_ACTIVE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_REPLY_CODE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_REPLY_TEXT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_CLASS_ID)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_METHOD_ID)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_CONSUMER_TAG)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_EXCHANGE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_ROUTING_KEY)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_DELIVERY_TAG)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_REDELIVERED)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_MESSAGE_COUNT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_SENDER_ID)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_QUEUE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_GET_CONSUMER_COUNT)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_DP_NEW)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_DP_LOOKUP)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_DP_DESTROY)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_INITIALISE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_SELFTEST)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_TERMINATE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_SHOW)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_ALLOC)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_FREE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_ANIMATE)   || defined (BASE_TRACE_AMQ_CLIENT_SESSION_NEW_IN_SCOPE) )
void
    amq_client_session_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

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
