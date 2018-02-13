/*---------------------------------------------------------------------------
    zyre_resource.h - zyre_resource component

This class holds all RestMS resources in a generic form, with a pointer to
the real resource object.  Resources are stored in a hash table where the
key is the resource path.  Resources have a looseref list of all children.
This class is not threadsafe and may be used from one threadlet only.
    Generated from zyre_resource.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_ZYRE_RESOURCE_SAFE
#   define INCLUDE_ZYRE_RESOURCE_SAFE
#   define INCLUDE_ZYRE_RESOURCE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_RESOURCE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _zyre_resource_t zyre_resource_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
#    define ZYRE_RESOURCE_HISTORY_LENGTH 32
#endif

#define ZYRE_RESOURCE_ALIVE             0xFABB
#define ZYRE_RESOURCE_DEAD              0xDEAD

#define ZYRE_RESOURCE_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL zyre_resource\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != ZYRE_RESOURCE_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "zyre_resource at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ZYRE_RESOURCE_ALIVE, self->object_tag);\
        zyre_resource_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#ifndef IPR_UNTYPED_LINK
#define IPR_UNTYPED_LINK
    typedef void * (untyped_link_fn) (void *object);
    typedef void (untyped_unlink_fn) (void *object_p);
#endif
#define RESTMS_RESOURCE_INVALID     0
#define RESTMS_RESOURCE_DOMAIN      1
#define RESTMS_RESOURCE_FEED        2
#define RESTMS_RESOURCE_PIPE        3
#define RESTMS_RESOURCE_JOIN        4
#define RESTMS_RESOURCE_MESSAGE     5
#define RESTMS_RESOURCE_CONTENT     6
#define RESTMS_RESOURCE_TOP         7
#define RESTMS_RESOURCE_VALID(t)    ((t) > 0 && (t) < RESTMS_RESOURCE_TOP)
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
#   undef INCLUDE_ZYRE_RESOURCE_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_RESOURCE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_RESOURCE_UNSAFE
#   define INCLUDE_ZYRE_RESOURCE_UNSAFE
#   define INCLUDE_ZYRE_RESOURCE_ACTIVE

#   include "zyre_classes.h"
#   include "ipr_looseref.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    zyre_resource_animating;

//  Structure of the zyre_resource object

struct _zyre_resource_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [ZYRE_RESOURCE_HISTORY_LENGTH];
    int
        history_line  [ZYRE_RESOURCE_HISTORY_LENGTH];
    char
        *history_type [ZYRE_RESOURCE_HISTORY_LENGTH];
    int
        history_links [ZYRE_RESOURCE_HISTORY_LENGTH];
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
    (void *server, zyre_resource_t *portal);

//  Client-side state glue
void
    *client_object;                 //  Client object reference
ipr_looseref_t
    *client_looseref;               //  Where client holds portal reference
void (*client_unbind)
    (void *client, zyre_resource_t *portal);
zyre_resource_t
    *parent;                        //  Parent resource
uint
    type;                           //  Resource type
icl_shortstr_t
    name,                           //  Resource name or hash
    path;                           //  Resource path
Bool
    private;                        //  Not discoverable
ipr_hash_t
    *hash;                          //  Backlink to hash item
ipr_looseref_list_t
    *children;                      //  Looseref list of children
ipr_looseref_t
    *in_parent;                     //  Backlink to parent's list
apr_time_t
    modified;                       //  Date-Modified value
zyre_resource_t *(*server_new)
    (void *_server, zyre_resource_t * parent, ipr_hash_table_t * table, char * type, char * name);
int (*request_configure)
    (void *_server, zyre_resource_t *portal, http_driver_context_t * context, ipr_hash_table_t * table, zyre_backend_t * backend);
int (*request_get)
    (void *_server, zyre_resource_t *portal, http_driver_context_t * context);
int (*request_put)
    (void *_server, zyre_resource_t *portal, http_driver_context_t * context);
int (*request_delete)
    (void *_server, zyre_resource_t *portal, http_driver_context_t * context);
int (*request_post)
    (void *_server, zyre_resource_t *portal, http_driver_context_t * context, ipr_hash_table_t * table, zyre_backend_t * backend);
int (*request_report)
    (void *_server, zyre_resource_t *portal, http_driver_context_t * context, ipr_tree_t * tree);
int (*request_attach)
    (void *_server, zyre_resource_t *portal, zyre_resource_t * resource, void * argument);
int (*request_detach)
    (void *_server, zyre_resource_t *portal, zyre_resource_t * resource, void * argument);
int (*response_child_add)
    (void *_client, zyre_resource_t *portal, http_driver_context_t * context);
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define zyre_resource_new(server_object,server_link,server_unlink,parent,table,type,name)  zyre_resource_new_ (__FILE__, __LINE__, server_object, server_link, server_unlink, parent, table, type, name)
zyre_resource_t *
    zyre_resource_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
void * server_object,                   //  Not documented
untyped_link_fn * server_link,          //  Not documented
untyped_unlink_fn * server_unlink,      //  Not documented
zyre_resource_t * parent,               //  Parent resource, or NULL
ipr_hash_table_t * table,               //  Hash by path
char * type,                            //  Resource type name
char * name                             //  Resource name, or empty
);

ipr_looseref_t *
    zyre_resource_attach_to_parent (
zyre_resource_t * self,                 //  Not documented
zyre_resource_t * parent                //  Not documented
);

int
    zyre_resource_detach_from_parent (
zyre_resource_t * self                  //  Reference to object
);

char *
    zyre_resource_etag (
zyre_resource_t * self,                 //  Not documented
char * type                             //  Not documented
);

int
    zyre_resource_modified (
zyre_resource_t * self,                 //  Reference to object
http_request_t * request                //  Incoming HTTP request
);

int
    zyre_resource_unmodified (
zyre_resource_t * self,                 //  Reference to object
http_request_t * request                //  Incoming HTTP request
);

char *
    zyre_resource_type_name (
int type                                //  Not documented
);

int
    zyre_resource_type_value (
char * name                             //  Not documented
);

int
    zyre_resource_to_document (
zyre_resource_t * self,                 //  Reference to object
http_driver_context_t * context,        //  Not documented
ipr_tree_t ** p_tree                    //  Not documented
);

zyre_resource_t *
    zyre_resource_parse_uri (
http_driver_context_t * context,        //  Not documented
ipr_hash_table_t * table,               //  Not documented
char * uri                              //  Not documented
);

void
    zyre_resource_selftest (
void);

zyre_resource_t *
    zyre_resource_factory (
zyre_resource_t * self,                 //  Portal factory
zyre_resource_t * parent,               //  Not documented
ipr_hash_table_t * table,               //  Not documented
char * type,                            //  Not documented
char * name                             //  Not documented
);

int
    zyre_resource_request_configure (
zyre_resource_t * self,                 //  Not documented
http_driver_context_t * context,        //  Not documented
ipr_hash_table_t * table,               //  Not documented
zyre_backend_t * backend                //  Not documented
);

int
    zyre_resource_request_get (
zyre_resource_t * self,                 //  Not documented
http_driver_context_t * context         //  Not documented
);

int
    zyre_resource_request_put (
zyre_resource_t * self,                 //  Not documented
http_driver_context_t * context         //  Not documented
);

int
    zyre_resource_request_delete (
zyre_resource_t * self,                 //  Not documented
http_driver_context_t * context         //  Not documented
);

int
    zyre_resource_request_post (
zyre_resource_t * self,                 //  Not documented
http_driver_context_t * context,        //  Not documented
ipr_hash_table_t * table,               //  Not documented
zyre_backend_t * backend                //  Not documented
);

int
    zyre_resource_request_report (
zyre_resource_t * self,                 //  Not documented
http_driver_context_t * context,        //  Not documented
ipr_tree_t * tree                       //  Not documented
);

int
    zyre_resource_request_attach (
zyre_resource_t * self,                 //  Not documented
zyre_resource_t * resource,             //  Not documented
void * argument                         //  Not documented
);

int
    zyre_resource_request_detach (
zyre_resource_t * self,                 //  Not documented
zyre_resource_t * resource,             //  Not documented
void * argument                         //  Not documented
);

int
    zyre_resource_response_child_add (
zyre_resource_t * self,                 //  Not documented
http_driver_context_t * context         //  Not documented
);

int
    zyre_resource_ready (
zyre_resource_t * self                  //  Reference to object
);

#define zyre_resource_show(item,opcode,trace_file)  zyre_resource_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    zyre_resource_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_resource_destroy(self)     zyre_resource_destroy_ (self, __FILE__, __LINE__)
void
    zyre_resource_destroy_ (
zyre_resource_t * ( * self_p ),         //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    zyre_resource_read_lock (
zyre_resource_t * self                  //  Reference to object
);

int
    zyre_resource_write_lock (
zyre_resource_t * self                  //  Reference to object
);

int
    zyre_resource_unlock (
zyre_resource_t * self                  //  Reference to object
);

#define zyre_resource_link(self)        zyre_resource_link_ (self, __FILE__, __LINE__)
zyre_resource_t *
    zyre_resource_link_ (
zyre_resource_t * self,                 //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_resource_unlink(self)      zyre_resource_unlink_ (self, __FILE__, __LINE__)
void
    zyre_resource_unlink_ (
zyre_resource_t * ( * self_p ),         //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    zyre_resource_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define zyre_resource_new_in_scope(self_p,_scope,server_object,server_link,server_unlink,parent,table,type,name)  zyre_resource_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, server_object, server_link, server_unlink, parent, table, type, name)
void
    zyre_resource_new_in_scope_ (
zyre_resource_t * * self_p,             //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
void * server_object,                   //  Not documented
untyped_link_fn * server_link,          //  Not documented
untyped_unlink_fn * server_unlink,      //  Not documented
zyre_resource_t * parent,               //  Parent resource, or NULL
ipr_hash_table_t * table,               //  Hash by path
char * type,                            //  Resource type name
char * name                             //  Resource name, or empty
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_RESOURCE_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_RESOURCE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_RESOURCE_INLINE)
#   define INCLUDE_ZYRE_RESOURCE_INLINE
#   define INCLUDE_ZYRE_RESOURCE_ACTIVE

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
#   undef INCLUDE_ZYRE_RESOURCE_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_RESOURCE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_RESOURCE_ROOT
#   endif
# endif
#endif
