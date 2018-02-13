/*---------------------------------------------------------------------------
    zyre_digest_amqp.h - zyre_digest_amqp component

    Refreshes expired or missing passwords using the protocol specified by
    the 8-Digest-AMQP@wiki.amqp.org specification.
    Generated from zyre_digest_amqp.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_ZYRE_DIGEST_AMQP_SAFE
#   define INCLUDE_ZYRE_DIGEST_AMQP_SAFE
#   define INCLUDE_ZYRE_DIGEST_AMQP_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_DIGEST_AMQP_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _zyre_digest_amqp_t zyre_digest_amqp_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
#    define ZYRE_DIGEST_AMQP_HISTORY_LENGTH 32
#endif

#define ZYRE_DIGEST_AMQP_ALIVE          0xFABB
#define ZYRE_DIGEST_AMQP_DEAD           0xDEAD

#define ZYRE_DIGEST_AMQP_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL zyre_digest_amqp\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != ZYRE_DIGEST_AMQP_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "zyre_digest_amqp at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ZYRE_DIGEST_AMQP_ALIVE, self->object_tag);\
        zyre_digest_amqp_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "wireapi.h"
#   include "zyre_classes.h"
#   include "zyre_backend.h"
#   include "ipr_looseref.h"
#   include "http_access_module.h"
#   include "http.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "zyre_digest_amqp_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_DIGEST_AMQP_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_DIGEST_AMQP_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_DIGEST_AMQP_UNSAFE
#   define INCLUDE_ZYRE_DIGEST_AMQP_UNSAFE
#   define INCLUDE_ZYRE_DIGEST_AMQP_ACTIVE

#   include "wireapi.h"
#   include "zyre_classes.h"
#   include "zyre_backend.h"
#   include "ipr_looseref.h"
#   include "http_access_module.h"
#   include "http.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "zyre_digest_amqp_agent.h"
//  Global variables

extern Bool
    zyre_digest_amqp_animating;

//  Structure of the zyre_digest_amqp object

struct _zyre_digest_amqp_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [ZYRE_DIGEST_AMQP_HISTORY_LENGTH];
    int
        history_line  [ZYRE_DIGEST_AMQP_HISTORY_LENGTH];
    char
        *history_type [ZYRE_DIGEST_AMQP_HISTORY_LENGTH];
    int
        history_links [ZYRE_DIGEST_AMQP_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
ipr_looseref_list_t
    *http_access_module_list;       //  List of portals
Bool
    http_access_module_stopped;     //  Is this portal stopped?
ipr_looseref_list_t
    *zyre_backend_list,             //  List of all own portals
    *zyre_backend_factory_list;     //  List of all own portal factories
Bool
    zyre_backend_stopped;           //  Is this portal stopped?
http_access_module_t
    *portal;                        //  Portal back to http_server
zyre_backend_t
    *backend;                       //  Backend peering to AMQP
Bool
    connected;                      //  AMQP connection alive?
icl_shortstr_t
    reply_queue;                    //  Queue name for replies
smt_log_t
    *log;                           //  Log file for warnings
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define zyre_digest_amqp_new()          zyre_digest_amqp_new_ (__FILE__, __LINE__)
zyre_digest_amqp_t *
    zyre_digest_amqp_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    zyre_digest_amqp_announce (
zyre_digest_amqp_t * self,              //  Reference to object
http_access_module_t * portal,          //  Portal back to client
smt_log_t * log                         //  Not documented
);

int
    zyre_digest_amqp_before (
zyre_digest_amqp_t * self,              //  Reference to object
http_access_module_t * portal,          //  Portal back to client
http_access_context_t * context         //  Not documented
);

int
    zyre_digest_amqp_send_request (
zyre_digest_amqp_t * self,              //  Reference to object
char *  user,                           //  Not documented
char *  realm                           //  Not documented
);

int
    zyre_digest_amqp_online (
zyre_digest_amqp_t * self,              //  Reference to object
zyre_backend_t * portal,                //  Portal back to server
char * reply_queue                      //  Not documented
);

int
    zyre_digest_amqp_offline (
zyre_digest_amqp_t * self,              //  Reference to object
zyre_backend_t * portal                 //  Portal back to server
);

int
    zyre_digest_amqp_arrived (
zyre_digest_amqp_t * self,              //  Reference to object
zyre_backend_t * portal,                //  Portal back to server
zyre_peer_method_t * method             //  Not documented
);

int
    zyre_digest_amqp_returned (
zyre_digest_amqp_t * self,              //  Reference to object
zyre_backend_t * portal,                //  Portal back to server
zyre_peer_method_t * method             //  Not documented
);

int
    zyre_digest_amqp__zyre_backend_bind (
zyre_digest_amqp_t * self,              //  Reference to object
zyre_backend_t * zyre_backend           //  Portal reference
);

int
    zyre_digest_amqp__zyre_backend_unbind (
zyre_digest_amqp_t * self,              //  Reference to object
zyre_backend_t * portal                 //  Portal reference
);

void
    zyre_digest_amqp_selftest (
void);

void
    zyre_digest_amqp_terminate (
void);

http_access_module_t *
    zyre_digest_amqp__http_access_module_new (
void * self_v                           //  Untyped server reference
);

http_access_module_t *
    zyre_digest_amqp__http_access_module_factory (
void);

int
    zyre_digest_amqp__http_access_module_unbind (
zyre_digest_amqp_t * self,              //  Reference to object
http_access_module_t * portal           //  Portal reference
);

int
    zyre_digest_amqp_open (
zyre_digest_amqp_t * self,              //  Reference to object
http_access_module_t * portal,          //  Portal back to client
http_access_context_t * context         //  Not documented
);

int
    zyre_digest_amqp_after (
zyre_digest_amqp_t * self,              //  Reference to object
http_access_module_t * portal,          //  Portal back to client
http_access_context_t * context         //  Not documented
);

int
    zyre_digest_amqp_close (
zyre_digest_amqp_t * self,              //  Reference to object
http_access_module_t * portal,          //  Portal back to client
http_access_context_t * context         //  Not documented
);

#define zyre_digest_amqp_destroy(self)  zyre_digest_amqp_destroy_ (self, __FILE__, __LINE__)
int
    zyre_digest_amqp_destroy_ (
zyre_digest_amqp_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_digest_amqp_unlink(self)   zyre_digest_amqp_unlink_ (self, __FILE__, __LINE__)
void
    zyre_digest_amqp_unlink_ (
zyre_digest_amqp_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    zyre_digest_amqp_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define zyre_digest_amqp_free(self)     zyre_digest_amqp_free_ (self, __FILE__, __LINE__)
void
    zyre_digest_amqp_free_ (
zyre_digest_amqp_t * self,              //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_digest_amqp_show(item,opcode,trace_file)  zyre_digest_amqp_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    zyre_digest_amqp_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_digest_amqp_link(self)     zyre_digest_amqp_link_ (self, __FILE__, __LINE__)
zyre_digest_amqp_t *
    zyre_digest_amqp_link_ (
zyre_digest_amqp_t * self,              //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_digest_amqp_new_in_scope(self_p,_scope)  zyre_digest_amqp_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    zyre_digest_amqp_new_in_scope_ (
zyre_digest_amqp_t * * self_p,          //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_DIGEST_AMQP_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_DIGEST_AMQP_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_DIGEST_AMQP_INLINE)
#   define INCLUDE_ZYRE_DIGEST_AMQP_INLINE
#   define INCLUDE_ZYRE_DIGEST_AMQP_ACTIVE

#   include "wireapi.h"
#   include "zyre_classes.h"
#   include "zyre_backend.h"
#   include "ipr_looseref.h"
#   include "http_access_module.h"
#   include "http.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "zyre_digest_amqp_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_DIGEST_AMQP_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_DIGEST_AMQP_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_DIGEST_AMQP_ROOT
#   endif
# endif
#endif
