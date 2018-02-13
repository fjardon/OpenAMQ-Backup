/*---------------------------------------------------------------------------
    zyre_backend.h - zyre_backend component

    This class enables the creation of backend modules that implement RestMS
    on a messaging server.  Modules are portal servers that inherit the
    zyre_backend_back class and implement the requests defined here.
    The client for a backend module implements the response methods, and must
    be an async class.
    Generated from zyre_backend.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_ZYRE_BACKEND_SAFE
#   define INCLUDE_ZYRE_BACKEND_SAFE
#   define INCLUDE_ZYRE_BACKEND_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_BACKEND_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _zyre_backend_t zyre_backend_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
#    define ZYRE_BACKEND_HISTORY_LENGTH 32
#endif

#define ZYRE_BACKEND_ALIVE              0xFABB
#define ZYRE_BACKEND_DEAD               0xDEAD

#define ZYRE_BACKEND_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL zyre_backend\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != ZYRE_BACKEND_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "zyre_backend at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ZYRE_BACKEND_ALIVE, self->object_tag);\
        zyre_backend_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#ifndef IPR_UNTYPED_LINK
#define IPR_UNTYPED_LINK
    typedef void * (untyped_link_fn) (void *object);
    typedef void (untyped_unlink_fn) (void *object_p);
#endif
#   ifdef __cplusplus
}
#   endif

#   include "zyre_classes.h"
#   include "ipr_looseref.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_BACKEND_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_BACKEND_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_BACKEND_UNSAFE
#   define INCLUDE_ZYRE_BACKEND_UNSAFE
#   define INCLUDE_ZYRE_BACKEND_ACTIVE

#   include "zyre_classes.h"
#   include "ipr_looseref.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    zyre_backend_animating;

//  Structure of the zyre_backend object

struct _zyre_backend_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [ZYRE_BACKEND_HISTORY_LENGTH];
    int
        history_line  [ZYRE_BACKEND_HISTORY_LENGTH];
    char
        *history_type [ZYRE_BACKEND_HISTORY_LENGTH];
    int
        history_links [ZYRE_BACKEND_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
Bool
    bound,                          //  Has portal been bound?
    stopped;                        //  Has portal been stopped?

//  Server-side state glue
void
    *server_object;                 //  If null, is a factory
ipr_looseref_t
    *server_looseref;               //  Where server holds portal reference
//  Server virtual methods
void (*server_unlink)
    (void *server);
void (*server_unbind)
    (void *server, zyre_backend_t *portal);

//  Client-side state glue
void
    *client_object;                 //  Client object reference
ipr_looseref_t
    *client_looseref;               //  Where client holds portal reference
void (*client_unbind)
    (void *client, zyre_backend_t *portal);
zyre_backend_t *(*server_new)
    (void *_server);
int (*request_start)
    (void *_server, zyre_backend_t *portal);
int (*request_stop)
    (void *_server, zyre_backend_t *portal);
int (*request_pipe_create)
    (void *_server, zyre_backend_t *portal, char * pipe_type, char * pipe_name);
int (*request_pipe_delete)
    (void *_server, zyre_backend_t *portal, char * pipe_name);
int (*request_feed_create)
    (void *_server, zyre_backend_t *portal, char * feed_type, char * feed_name);
int (*request_feed_delete)
    (void *_server, zyre_backend_t *portal, char * feed_name);
int (*request_join_create)
    (void *_server, zyre_backend_t *portal, char * pipe_name, char * feed_name, char * address);
int (*request_join_delete)
    (void *_server, zyre_backend_t *portal, char * pipe_name, char * feed_name, char * address);
int (*request_address_post)
    (void *_server, zyre_backend_t *portal, char * address, char * feed_name, amq_content_basic_t * content);
int (*request_forward)
    (void *_server, zyre_backend_t *portal, char * exchange, char * routing_key, amq_content_basic_t * content, Bool mandatory, Bool immediate);
int (*request_online_partial)
    (void *_server, zyre_backend_t *portal);
int (*request_online_final)
    (void *_server, zyre_backend_t *portal);
int (*response_online)
    (void *_client, zyre_backend_t *portal, char * reply_queue);
int (*response_offline)
    (void *_client, zyre_backend_t *portal);
int (*response_arrived)
    (void *_client, zyre_backend_t *portal, zyre_peer_method_t * method);
int (*response_returned)
    (void *_client, zyre_backend_t *portal, zyre_peer_method_t * method);
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
zyre_backend_t *
    zyre_backend_factory (
zyre_backend_t * self                   //  Portal factory
);

int
    zyre_backend_request_start (
zyre_backend_t * self                   //  Not documented
);

int
    zyre_backend_request_stop (
zyre_backend_t * self                   //  Not documented
);

int
    zyre_backend_request_pipe_create (
zyre_backend_t * self,                  //  Not documented
char * pipe_type,                       //  Not documented
char * pipe_name                        //  Not documented
);

int
    zyre_backend_request_pipe_delete (
zyre_backend_t * self,                  //  Not documented
char * pipe_name                        //  Not documented
);

int
    zyre_backend_request_feed_create (
zyre_backend_t * self,                  //  Not documented
char * feed_type,                       //  Not documented
char * feed_name                        //  Not documented
);

int
    zyre_backend_request_feed_delete (
zyre_backend_t * self,                  //  Not documented
char * feed_name                        //  Not documented
);

int
    zyre_backend_request_join_create (
zyre_backend_t * self,                  //  Not documented
char * pipe_name,                       //  Not documented
char * feed_name,                       //  Not documented
char * address                          //  Not documented
);

int
    zyre_backend_request_join_delete (
zyre_backend_t * self,                  //  Not documented
char * pipe_name,                       //  Not documented
char * feed_name,                       //  Not documented
char * address                          //  Not documented
);

int
    zyre_backend_request_address_post (
zyre_backend_t * self,                  //  Not documented
char * address,                         //  Not documented
char * feed_name,                       //  Not documented
amq_content_basic_t * content           //  Not documented
);

int
    zyre_backend_request_forward (
zyre_backend_t * self,                  //  Not documented
char * exchange,                        //  Not documented
char * routing_key,                     //  Not documented
amq_content_basic_t * content,          //  Not documented
Bool mandatory,                         //  Not documented
Bool immediate                          //  Not documented
);

int
    zyre_backend_request_online_partial (
zyre_backend_t * self                   //  Not documented
);

int
    zyre_backend_request_online_final (
zyre_backend_t * self                   //  Not documented
);

int
    zyre_backend_response_online (
zyre_backend_t * self,                  //  Not documented
char * reply_queue                      //  Not documented
);

int
    zyre_backend_response_offline (
zyre_backend_t * self                   //  Not documented
);

int
    zyre_backend_response_arrived (
zyre_backend_t * self,                  //  Not documented
zyre_peer_method_t * method             //  Not documented
);

int
    zyre_backend_response_returned (
zyre_backend_t * self,                  //  Not documented
zyre_peer_method_t * method             //  Not documented
);

#define zyre_backend_new(server_object,server_link,server_unlink)  zyre_backend_new_ (__FILE__, __LINE__, server_object, server_link, server_unlink)
zyre_backend_t *
    zyre_backend_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
void * server_object,                   //  Not documented
untyped_link_fn * server_link,          //  Not documented
untyped_unlink_fn * server_unlink       //  Not documented
);

int
    zyre_backend_ready (
zyre_backend_t * self                   //  Reference to object
);

void
    zyre_backend_selftest (
void);

void
    zyre_backend_terminate (
void);

#define zyre_backend_show(item,opcode,trace_file)  zyre_backend_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    zyre_backend_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_backend_destroy(self)      zyre_backend_destroy_ (self, __FILE__, __LINE__)
void
    zyre_backend_destroy_ (
zyre_backend_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    zyre_backend_read_lock (
zyre_backend_t * self                   //  Reference to object
);

int
    zyre_backend_write_lock (
zyre_backend_t * self                   //  Reference to object
);

int
    zyre_backend_unlock (
zyre_backend_t * self                   //  Reference to object
);

#define zyre_backend_link(self)         zyre_backend_link_ (self, __FILE__, __LINE__)
zyre_backend_t *
    zyre_backend_link_ (
zyre_backend_t * self,                  //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_backend_unlink(self)       zyre_backend_unlink_ (self, __FILE__, __LINE__)
void
    zyre_backend_unlink_ (
zyre_backend_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    zyre_backend_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define zyre_backend_new_in_scope(self_p,_scope,server_object,server_link,server_unlink)  zyre_backend_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, server_object, server_link, server_unlink)
void
    zyre_backend_new_in_scope_ (
zyre_backend_t * * self_p,              //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
void * server_object,                   //  Not documented
untyped_link_fn * server_link,          //  Not documented
untyped_unlink_fn * server_unlink       //  Not documented
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_BACKEND_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_BACKEND_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_BACKEND_INLINE)
#   define INCLUDE_ZYRE_BACKEND_INLINE
#   define INCLUDE_ZYRE_BACKEND_ACTIVE

#   include "zyre_classes.h"
#   include "ipr_looseref.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_BACKEND_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_BACKEND_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_BACKEND_ROOT
#   endif
# endif
#endif
