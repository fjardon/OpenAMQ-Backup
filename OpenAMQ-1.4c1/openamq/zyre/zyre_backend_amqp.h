/*---------------------------------------------------------------------------
    zyre_backend_amqp.h - zyre_backend_amqp component

Backend module that talks to an OpenAMQ server, originally based on
the amq_peering class, but modified to work with IPR portals and to
implement the RestMS data model.

This module implementation replicates the state used by the Zyre RestMS
server.  Namely:

  * A set of feeds, pipes, and joins, implemented on the AMQP server as
    exchanges, queues, bindings, and consumers.  This peering class is the
    place where the mapping from RestMS to AMQP is defined in detail.

  * A queue of messages waiting to be published to the AMQP server.

The peering isolates the application from the AMQP server, allowing the
state to be updated asynchronously from any connection.  That is, before
a connection is made, while a connection is active, or when a connection
has died and is being brought back.

Lastly, the peering will invoke callback methods to tell you when the peer
link becomes active, and when a message content arrives.
    Generated from zyre_backend_amqp.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_ZYRE_BACKEND_AMQP_SAFE
#   define INCLUDE_ZYRE_BACKEND_AMQP_SAFE
#   define INCLUDE_ZYRE_BACKEND_AMQP_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_BACKEND_AMQP_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _zyre_backend_amqp_t zyre_backend_amqp_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
#    define ZYRE_BACKEND_AMQP_HISTORY_LENGTH 32
#endif

#define ZYRE_BACKEND_AMQP_ALIVE         0xFABB
#define ZYRE_BACKEND_AMQP_DEAD          0xDEAD

#define ZYRE_BACKEND_AMQP_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL zyre_backend_amqp\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != ZYRE_BACKEND_AMQP_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "zyre_backend_amqp at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ZYRE_BACKEND_AMQP_ALIVE, self->object_tag);\
        zyre_backend_amqp_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "zyre_backend.h"
#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "zyre_backend_amqp_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_BACKEND_AMQP_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_BACKEND_AMQP_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_BACKEND_AMQP_UNSAFE
#   define INCLUDE_ZYRE_BACKEND_AMQP_UNSAFE
#   define INCLUDE_ZYRE_BACKEND_AMQP_ACTIVE

#   include "zyre_backend.h"
#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "zyre_backend_amqp_agent.h"
//  Global variables

extern Bool
    zyre_backend_amqp_animating;

//  Structure of the zyre_backend_amqp object

struct _zyre_backend_amqp_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [ZYRE_BACKEND_AMQP_HISTORY_LENGTH];
    int
        history_line  [ZYRE_BACKEND_AMQP_HISTORY_LENGTH];
    char
        *history_type [ZYRE_BACKEND_AMQP_HISTORY_LENGTH];
    int
        history_links [ZYRE_BACKEND_AMQP_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
ipr_looseref_list_t
    *zyre_backend_list;             //  List of portals
Bool
    zyre_backend_stopped;           //  Is this portal stopped?
zyre_backend_t
    *portal;                        //  Portal back to client
Bool
    enabled,                        //  We're active
    connected,                      //  We're connected
    offlined;                       //  Peer has gone offline
icl_shortstr_t
    host,                           //  Peer host name
    queue;                          //  For replies from services
icl_longstr_t
    *auth_data;                     //  Authentication data
int
    trace;                          //  Trace level
smt_thread_t
    *peer_agent_thread;             //  Active agent thread if any
dbyte
    channel_nbr;                    //  Active channel number
ipr_hash_table_t
    *pipe_table,                    //  Known pipes
    *feed_table;                    //  Known feeds
ipr_looseref_list_t
    *messages;                      //  Messages pending
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define zyre_backend_amqp_new()         zyre_backend_amqp_new_ (__FILE__, __LINE__)
zyre_backend_amqp_t *
    zyre_backend_amqp_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    zyre_backend_amqp_start (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal                 //  Portal back to client
);

int
    zyre_backend_amqp_stop (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal                 //  Portal back to client
);

int
    zyre_backend_amqp_pipe_create (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal,                //  Portal back to client
char * pipe_type,                       //  Not documented
char * pipe_name                        //  Not documented
);

int
    zyre_backend_amqp_pipe_delete (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal,                //  Portal back to client
char * pipe_name                        //  Not documented
);

int
    zyre_backend_amqp_feed_create (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal,                //  Portal back to client
char * feed_type,                       //  Not documented
char * feed_name                        //  Not documented
);

int
    zyre_backend_amqp_feed_delete (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal,                //  Portal back to client
char * feed_name                        //  Not documented
);

int
    zyre_backend_amqp_join_create (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal,                //  Portal back to client
char * pipe_name,                       //  Not documented
char * feed_name,                       //  Not documented
char * address                          //  Not documented
);

int
    zyre_backend_amqp_join_delete (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal,                //  Portal back to client
char * pipe_name,                       //  Not documented
char * feed_name,                       //  Not documented
char * address                          //  Not documented
);

int
    zyre_backend_amqp_address_post (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal,                //  Portal back to client
char * address,                         //  Not documented
char * feed_name,                       //  Not documented
amq_content_basic_t * content           //  Not documented
);

int
    zyre_backend_amqp_forward (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal,                //  Portal back to client
char * exchange,                        //  Not documented
char * routing_key,                     //  Not documented
amq_content_basic_t * content,          //  Not documented
Bool mandatory,                         //  Not documented
Bool immediate                          //  Not documented
);

int
    zyre_backend_amqp_online_partial (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal                 //  Portal back to client
);

int
    zyre_backend_amqp_online_final (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal                 //  Portal back to client
);

void
    zyre_backend_amqp_terminate (
void);

void
    zyre_backend_amqp_selftest (
void);

zyre_backend_t *
    zyre_backend_amqp__zyre_backend_new (
void * self_v                           //  Untyped server reference
);

zyre_backend_t *
    zyre_backend_amqp__zyre_backend_factory (
void);

int
    zyre_backend_amqp__zyre_backend_unbind (
zyre_backend_amqp_t * self,             //  Reference to object
zyre_backend_t * portal                 //  Portal reference
);

#define zyre_backend_amqp_destroy(self)  zyre_backend_amqp_destroy_ (self, __FILE__, __LINE__)
int
    zyre_backend_amqp_destroy_ (
zyre_backend_amqp_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_backend_amqp_unlink(self)  zyre_backend_amqp_unlink_ (self, __FILE__, __LINE__)
void
    zyre_backend_amqp_unlink_ (
zyre_backend_amqp_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    zyre_backend_amqp_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define zyre_backend_amqp_free(self)    zyre_backend_amqp_free_ (self, __FILE__, __LINE__)
void
    zyre_backend_amqp_free_ (
zyre_backend_amqp_t * self,             //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_backend_amqp_show(item,opcode,trace_file)  zyre_backend_amqp_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    zyre_backend_amqp_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_backend_amqp_link(self)    zyre_backend_amqp_link_ (self, __FILE__, __LINE__)
zyre_backend_amqp_t *
    zyre_backend_amqp_link_ (
zyre_backend_amqp_t * self,             //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_backend_amqp_new_in_scope(self_p,_scope)  zyre_backend_amqp_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    zyre_backend_amqp_new_in_scope_ (
zyre_backend_amqp_t * * self_p,         //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_BACKEND_AMQP_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_BACKEND_AMQP_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_BACKEND_AMQP_INLINE)
#   define INCLUDE_ZYRE_BACKEND_AMQP_INLINE
#   define INCLUDE_ZYRE_BACKEND_AMQP_ACTIVE

#   include "zyre_backend.h"
#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "zyre_backend_amqp_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_BACKEND_AMQP_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_BACKEND_AMQP_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_BACKEND_AMQP_ROOT
#   endif
# endif
#endif
