/*---------------------------------------------------------------------------
    amq_peering.h - amq_peering component

This class defines a smart link to a remote server.  You tell the peering
what server to talk to and it will monitor the server and connect
automatically when the server comes online, and reconnect if the server
goes offline for a period.

A peering has two functions:

1. Binding propagation, in which messages published to an exchange on the
   remote server can be "pulled" to this server.  You tell the peering what
   bindings you are interested in, and it will deliver you all matching
   messages.

2. Message forwarding, in which messages originating locally are carried to
   the remote peer.  This class does not specify where those local messages
   come from.

The peer link may be arbitrarily active or inactive depending on the state
of the network and the remote server.

The peering will replay all bindings if when the peer link becomes active.
It will queue messages that are forwarded when the peer link is not active.

Lastly, the peering will invoke callback methods to tell you when the peer
link becomes active, and when a content arrives.  Currently this class
works only with Basic contents.

The selftest method demonstrates fairly sophisticated peering use.  To test
this, set the environment variable AMQ_PEERING_TEST=1 and run an amq_server.

Note that the current amq_peering implementation is limited to a signle
exchange per amq_peering instance.

This is a summary of the amq_peering API:

    peering = amq_peering_new (
        remote-host-name, virtual-host, trace-level, exchange-name)
        Create a new peering to the specified host, virtual host and
        remote exchange.

    amq_peering_set_login (peering, login-name)
        Tell the peering to login using the specified login-name, which
        must be defined in the local amq_server_base.cfg or amq_server.cfg.

    amq_peering_set_status_handler (peering, handler, calling-object)
        Set the callback handler for status updates.

    amq_peering_set_content_handler (peering, handler, calling-object)
        Set the callback handler for incoming messages.

    amq_peering_start (peering)
        Enable the peering, connect to remote server when possible.

    amq_peering_stop (peering)
        Disable the peering, disconnect from remote server if necessary.

    amq_peering_bind (peering, routing-key, arguments)
        Replicate a binding to the remote server.

    amq_peering_unbind (peering, routing-key, arguments)
        Replicate a queue.unbind to the remote server.  Also removes the
        binding from the list of bindings to replay.

    amq_peering_forward (peering, routing-key, content, madatory, immediate)
        Publish a message to the remote server.

    amq_peering_destroy (&peering)
        Destroy the peering.
    Generated from amq_peering.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_PEERING_SAFE
#   define INCLUDE_AMQ_PEERING_SAFE
#   define INCLUDE_AMQ_PEERING_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_PEERING_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_peering_t amq_peering_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
#    define AMQ_PEERING_HISTORY_LENGTH 32
#endif

#define AMQ_PEERING_ALIVE               0xFABB
#define AMQ_PEERING_DEAD                0xDEAD

#define AMQ_PEERING_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_peering\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_PEERING_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_peering at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_PEERING_ALIVE, self->object_tag);\
        amq_peering_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
//  Make a forward reference to resolve the circular dependency between the
//  function typedef and the method structure.
typedef struct _amq_peer_method_t __amq_peer_method_t;
typedef int (amq_peering_status_fn) (
    void *caller, amq_peering_t *peering, Bool connected);
typedef int (amq_peering_content_fn) (
    void *caller, amq_peering_t *peering, __amq_peer_method_t *method);
typedef int (amq_peering_return_fn) (
    void *caller, amq_peering_t *peering, __amq_peer_method_t *method);
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_peering_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_PEERING_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEERING_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_PEERING_UNSAFE
#   define INCLUDE_AMQ_PEERING_UNSAFE
#   define INCLUDE_AMQ_PEERING_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_peering_agent.h"
//  Global variables

extern Bool
    amq_peering_animating;

//  Structure of the amq_peering object

struct _amq_peering_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_PEERING_HISTORY_LENGTH];
    int
        history_line  [AMQ_PEERING_HISTORY_LENGTH];
    char
        *history_type [AMQ_PEERING_HISTORY_LENGTH];
    int
        history_links [AMQ_PEERING_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
Bool
    enabled,                        //  We're active
    connected,                      //  We're connected
    offlined;                       //  Peer has gone offline
icl_shortstr_t
    host,                           //  Peer host name
    virtual_host,                   //  Virtual host name
    exchange,                       //  Remote exchange name
    exchange_type;                  //  Remote exchange type
icl_longstr_t
    *auth_data;                     //  Authentication data
int
    trace;                          //  Trace level
smt_thread_t
    *peer_agent_thread;             //  Active agent thread if any
dbyte
    channel_nbr;                    //  Active channel number
ipr_looseref_list_t
    *bindings,                      //  Bindings sent/pending
    *forwards;                      //  Forwards pending

//  Callbacks into caller object
amq_peering_status_fn
    *status_fn;                     //  Status change callback
void
    *status_caller;                 //  Object to invoke
amq_peering_content_fn
    *content_fn;                    //  Content delivery callback
void
    *content_caller;                //  Object to invoke
amq_peering_return_fn
    *return_fn;                     //  Returned message delivery callback
void
    *return_caller;                 //  Object to invoke
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_peering_new(host,virtual_host,trace,exchange,exchange_type)  amq_peering_new_ (__FILE__, __LINE__, host, virtual_host, trace, exchange, exchange_type)
amq_peering_t *
    amq_peering_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
char * host,                            //  Host to connect to
char * virtual_host,                    //  Virtual host
int trace,                              //  Trace level, 0 - 3
char * exchange,                        //  Remote exchange name
char* exchange_type                     //  Remote exchange type
);

int
    amq_peering_set_login (
amq_peering_t * self,                   //  Reference to object
char * login                            //  Login name to use
);

int
    amq_peering_set_status_handler (
amq_peering_t * self,                   //  Reference to object
amq_peering_status_fn * status_fn,      //  Callback
void * caller                           //  Reference of caller object
);

int
    amq_peering_cancel_status_handler (
amq_peering_t * self,                   //  Reference to object
void * caller                           //  Reference of caller object
);

int
    amq_peering_set_content_handler (
amq_peering_t * self,                   //  Reference to object
amq_peering_content_fn * content_fn,    //  Callback
void * caller                           //  Reference of caller object
);

int
    amq_peering_cancel_content_handler (
amq_peering_t * self,                   //  Reference to object
void * caller                           //  Reference of caller object
);

int
    amq_peering_set_return_handler (
amq_peering_t * self,                   //  Reference to object
amq_peering_return_fn * return_fn,      //  Callback
void * caller                           //  Reference of caller object
);

int
    amq_peering_cancel_return_handler (
amq_peering_t * self,                   //  Reference to object
void * caller                           //  Reference of caller object
);

int
    amq_peering_bind (
amq_peering_t * self,                   //  Reference to object
char * routing_key,                     //  Bind to routing key
icl_longstr_t * arguments               //  Bind arguments
);

int
    amq_peering_unbind (
amq_peering_t * self,                   //  Reference to object
char * routing_key,                     //  Bind to routing key
icl_longstr_t * arguments               //  Bind arguments
);

int
    amq_peering_forward (
amq_peering_t * self,                   //  Reference to object
char * routing_key,                     //  Routing key for publish
amq_content_basic_t * content,          //  Content to publish
Bool mandatory,                         //  Mandatory routing
Bool immediate                          //  Immediate delivery
);

int
    amq_peering_start (
amq_peering_t * self                    //  Reference to object
);

int
    amq_peering_stop (
amq_peering_t * self                    //  Reference to object
);

int
    amq_peering_peer_connection_open_ok (
amq_peering_t * self,                   //  Reference to object
amq_peer_method_t * method              //  Not documented
);

int
    amq_peering_peer_connection_close (
amq_peering_t * self,                   //  Reference to object
amq_peer_method_t * method              //  Not documented
);

int
    amq_peering_peer_channel_open_ok (
amq_peering_t * self,                   //  Reference to object
amq_peer_method_t * method              //  Not documented
);

int
    amq_peering_peer_basic_deliver (
amq_peering_t * self,                   //  Reference to object
amq_peer_method_t * method              //  Not documented
);

int
    amq_peering_peer_basic_return (
amq_peering_t * self,                   //  Reference to object
amq_peer_method_t * method              //  Not documented
);

void
    amq_peering_terminate (
void);

void
    amq_peering_selftest (
void);

#define amq_peering_destroy(self)       amq_peering_destroy_ (self, __FILE__, __LINE__)
int
    amq_peering_destroy_ (
amq_peering_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_peering_unlink(self)        amq_peering_unlink_ (self, __FILE__, __LINE__)
void
    amq_peering_unlink_ (
amq_peering_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_peering_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_peering_free(self)          amq_peering_free_ (self, __FILE__, __LINE__)
void
    amq_peering_free_ (
amq_peering_t * self,                   //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_peering_show(item,opcode,trace_file)  amq_peering_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_peering_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_peering_link(self)          amq_peering_link_ (self, __FILE__, __LINE__)
amq_peering_t *
    amq_peering_link_ (
amq_peering_t * self,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_peering_new_in_scope(self_p,_scope,host,virtual_host,trace,exchange,exchange_type)  amq_peering_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, host, virtual_host, trace, exchange, exchange_type)
void
    amq_peering_new_in_scope_ (
amq_peering_t * * self_p,               //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
char * host,                            //  Host to connect to
char * virtual_host,                    //  Virtual host
int trace,                              //  Trace level, 0 - 3
char * exchange,                        //  Remote exchange name
char* exchange_type                     //  Remote exchange type
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_PEERING_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEERING_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_PEERING_INLINE)
#   define INCLUDE_AMQ_PEERING_INLINE
#   define INCLUDE_AMQ_PEERING_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEERING)   || defined (BASE_TRACE_AMQ_PEERING_NEW)   || defined (BASE_TRACE_AMQ_PEERING_DESTROY)   || defined (BASE_TRACE_AMQ_PEERING_SET_LOGIN)   || defined (BASE_TRACE_AMQ_PEERING_SET_STATUS_HANDLER)   || defined (BASE_TRACE_AMQ_PEERING_CANCEL_STATUS_HANDLER)   || defined (BASE_TRACE_AMQ_PEERING_SET_CONTENT_HANDLER)   || defined (BASE_TRACE_AMQ_PEERING_CANCEL_CONTENT_HANDLER)   || defined (BASE_TRACE_AMQ_PEERING_SET_RETURN_HANDLER)   || defined (BASE_TRACE_AMQ_PEERING_CANCEL_RETURN_HANDLER)   || defined (BASE_TRACE_AMQ_PEERING_BIND)   || defined (BASE_TRACE_AMQ_PEERING_UNBIND)   || defined (BASE_TRACE_AMQ_PEERING_FORWARD)   || defined (BASE_TRACE_AMQ_PEERING_START)   || defined (BASE_TRACE_AMQ_PEERING_STOP)   || defined (BASE_TRACE_AMQ_PEERING_PEER_CONNECTION_OPEN_OK)   || defined (BASE_TRACE_AMQ_PEERING_PEER_CONNECTION_CLOSE)   || defined (BASE_TRACE_AMQ_PEERING_PEER_CHANNEL_OPEN_OK)   || defined (BASE_TRACE_AMQ_PEERING_PEER_BASIC_DELIVER)   || defined (BASE_TRACE_AMQ_PEERING_PEER_BASIC_RETURN)   || defined (BASE_TRACE_AMQ_PEERING_INITIALISE)   || defined (BASE_TRACE_AMQ_PEERING_TERMINATE)   || defined (BASE_TRACE_AMQ_PEERING_SELFTEST)   || defined (BASE_TRACE_AMQ_PEERING_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_PEERING_UNLINK)   || defined (BASE_TRACE_AMQ_PEERING_ANIMATE)   || defined (BASE_TRACE_AMQ_PEERING_FREE)   || defined (BASE_TRACE_AMQ_PEERING_SHOW)   || defined (BASE_TRACE_AMQ_PEERING_ALLOC)   || defined (BASE_TRACE_AMQ_PEERING_LINK)   || defined (BASE_TRACE_AMQ_PEERING_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_PEERING_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_PEERING_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_PEERING_NEW_IN_SCOPE) )
void
    amq_peering_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_peering_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_PEERING_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEERING_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_PEERING_ROOT
#   endif
# endif
#endif
