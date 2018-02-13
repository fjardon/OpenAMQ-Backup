/*---------------------------------------------------------------------------
    zyre_restms.h - zyre_restms component

    This class implements a HTTP plugin that maps RestMS requests to AMQP.
    The plugin acts as a portal backend for the Base2/HTTP server.  This
    is an async class that manages a data tree of feeds, pipes, and joins.
    It communicates changes to this tree to the AMQP backend agent, which
    handles all communications with the AMQP server.  Incoming AMQP messages
    arrive via the backend portal.  All RestMS work is done by a single
    object in this class, so a single thread.  This limits the workload to
    around 300,000 transactions per second, which is the speedlimit of one
    threadlet (SMT thread queue limitation).
    Generated from zyre_restms.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_ZYRE_RESTMS_SAFE
#   define INCLUDE_ZYRE_RESTMS_SAFE
#   define INCLUDE_ZYRE_RESTMS_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_RESTMS_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _zyre_restms_t zyre_restms_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
#    define ZYRE_RESTMS_HISTORY_LENGTH 32
#endif

#define ZYRE_RESTMS_ALIVE               0xFABB
#define ZYRE_RESTMS_DEAD                0xDEAD

#define ZYRE_RESTMS_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL zyre_restms\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != ZYRE_RESTMS_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "zyre_restms at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ZYRE_RESTMS_ALIVE, self->object_tag);\
        zyre_restms_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#define RESTMS_ROOT         "restms"
#   ifdef __cplusplus
}
#   endif

#   include "zyre_resource.h"
#   include "ipr_looseref.h"
#   include "zyre_classes.h"
#   include "zyre_backend.h"
#   include "http_driver_module.h"
#   include "http.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "zyre_restms_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_RESTMS_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_RESTMS_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_RESTMS_UNSAFE
#   define INCLUDE_ZYRE_RESTMS_UNSAFE
#   define INCLUDE_ZYRE_RESTMS_ACTIVE

#   include "zyre_resource.h"
#   include "ipr_looseref.h"
#   include "zyre_classes.h"
#   include "zyre_backend.h"
#   include "http_driver_module.h"
#   include "http.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "zyre_restms_agent.h"
//  Global variables

extern Bool
    zyre_restms_animating;

//  Structure of the zyre_restms object

struct _zyre_restms_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [ZYRE_RESTMS_HISTORY_LENGTH];
    int
        history_line  [ZYRE_RESTMS_HISTORY_LENGTH];
    char
        *history_type [ZYRE_RESTMS_HISTORY_LENGTH];
    int
        history_links [ZYRE_RESTMS_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
ipr_looseref_list_t
    *http_driver_module_list;       //  List of portals
Bool
    http_driver_module_stopped;     //  Is this portal stopped?
ipr_looseref_list_t
    *zyre_backend_list,             //  List of all own portals
    *zyre_backend_factory_list;     //  List of all own portal factories
Bool
    zyre_backend_stopped;           //  Is this portal stopped?
ipr_looseref_list_t
    *zyre_resource_list,            //  List of all own portals
    *zyre_resource_factory_list;    //  List of all own portal factories
Bool
    zyre_resource_stopped;          //  Is this portal stopped?
zyre_backend_t
    *backend;                       //  Backend peering to AMQP
Bool
    connected;                      //  Back-end connection alive?
smt_log_t
    *log;                           //  Log file for warnings
ipr_hash_table_t
    *resources;                     //  Table of resource URIs
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define zyre_restms_new()               zyre_restms_new_ (__FILE__, __LINE__)
zyre_restms_t *
    zyre_restms_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    zyre_restms_announce (
zyre_restms_t * self,                   //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
smt_log_t * log                         //  Not documented
);

int
    zyre_restms_get (
zyre_restms_t * self,                   //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    zyre_restms_put (
zyre_restms_t * self,                   //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    zyre_restms_delete (
zyre_restms_t * self,                   //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    zyre_restms_post (
zyre_restms_t * self,                   //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    zyre_restms_head (
zyre_restms_t * self,                   //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    zyre_restms_move (
zyre_restms_t * self,                   //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    zyre_restms_copy (
zyre_restms_t * self,                   //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    zyre_restms_online (
zyre_restms_t * self,                   //  Reference to object
zyre_backend_t * portal,                //  Portal back to server
char * reply_queue                      //  Not documented
);

int
    zyre_restms_offline (
zyre_restms_t * self,                   //  Reference to object
zyre_backend_t * portal                 //  Portal back to server
);

int
    zyre_restms_arrived (
zyre_restms_t * self,                   //  Reference to object
zyre_backend_t * portal,                //  Portal back to server
zyre_peer_method_t * method             //  Not documented
);

int
    zyre_restms_returned (
zyre_restms_t * self,                   //  Reference to object
zyre_backend_t * portal,                //  Portal back to server
zyre_peer_method_t * method             //  Not documented
);

int
    zyre_restms_check_path (
http_driver_context_t * context         //  Not documented
);

int
    zyre_restms_parse_document (
http_driver_context_t * context,        //  Not documented
char * required                         //  Required resource type
);

void
    zyre_restms_selftest (
void);

int
    zyre_restms__zyre_resource_bind (
zyre_restms_t * self,                   //  Reference to object
zyre_resource_t * zyre_resource         //  Portal reference
);

int
    zyre_restms__zyre_backend_bind (
zyre_restms_t * self,                   //  Reference to object
zyre_backend_t * zyre_backend           //  Portal reference
);

int
    zyre_restms__zyre_backend_unbind (
zyre_restms_t * self,                   //  Reference to object
zyre_backend_t * portal                 //  Portal reference
);

void
    zyre_restms_terminate (
void);

http_driver_module_t *
    zyre_restms__http_driver_module_new (
void * self_v,                          //  Untyped server reference
char * path                             //  Not documented
);

http_driver_module_t *
    zyre_restms__http_driver_module_factory (
char * path                             //  Not documented
);

int
    zyre_restms__http_driver_module_unbind (
zyre_restms_t * self,                   //  Reference to object
http_driver_module_t * portal           //  Portal reference
);

#define zyre_restms_destroy(self)       zyre_restms_destroy_ (self, __FILE__, __LINE__)
int
    zyre_restms_destroy_ (
zyre_restms_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_restms_unlink(self)        zyre_restms_unlink_ (self, __FILE__, __LINE__)
void
    zyre_restms_unlink_ (
zyre_restms_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    zyre_restms_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define zyre_restms_free(self)          zyre_restms_free_ (self, __FILE__, __LINE__)
void
    zyre_restms_free_ (
zyre_restms_t * self,                   //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_restms_show(item,opcode,trace_file)  zyre_restms_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    zyre_restms_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_restms_link(self)          zyre_restms_link_ (self, __FILE__, __LINE__)
zyre_restms_t *
    zyre_restms_link_ (
zyre_restms_t * self,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_restms_new_in_scope(self_p,_scope)  zyre_restms_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    zyre_restms_new_in_scope_ (
zyre_restms_t * * self_p,               //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_RESTMS_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_RESTMS_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_RESTMS_INLINE)
#   define INCLUDE_ZYRE_RESTMS_INLINE
#   define INCLUDE_ZYRE_RESTMS_ACTIVE

#   include "zyre_resource.h"
#   include "ipr_looseref.h"
#   include "zyre_classes.h"
#   include "zyre_backend.h"
#   include "http_driver_module.h"
#   include "http.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "zyre_restms_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_RESTMS_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_RESTMS_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_RESTMS_ROOT
#   endif
# endif
#endif
