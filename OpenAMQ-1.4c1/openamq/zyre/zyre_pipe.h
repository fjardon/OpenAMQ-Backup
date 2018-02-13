/*---------------------------------------------------------------------------
    zyre_pipe.h - zyre_pipe component

This class implements the RestMS pipe object.
    Generated from zyre_pipe.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_ZYRE_PIPE_SAFE
#   define INCLUDE_ZYRE_PIPE_SAFE
#   define INCLUDE_ZYRE_PIPE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_PIPE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _zyre_pipe_t zyre_pipe_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
#    define ZYRE_PIPE_HISTORY_LENGTH 32
#endif

#define ZYRE_PIPE_ALIVE                 0xFABB
#define ZYRE_PIPE_DEAD                  0xDEAD

#define ZYRE_PIPE_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL zyre_pipe\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != ZYRE_PIPE_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "zyre_pipe at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ZYRE_PIPE_ALIVE, self->object_tag);\
        zyre_pipe_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "zyre_resource.h"
#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_PIPE_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PIPE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_PIPE_UNSAFE
#   define INCLUDE_ZYRE_PIPE_UNSAFE
#   define INCLUDE_ZYRE_PIPE_ACTIVE

#   include "zyre_resource.h"
#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    zyre_pipe_animating;

//  Structure of the zyre_pipe object

struct _zyre_pipe_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [ZYRE_PIPE_HISTORY_LENGTH];
    int
        history_line  [ZYRE_PIPE_HISTORY_LENGTH];
    char
        *history_type [ZYRE_PIPE_HISTORY_LENGTH];
    int
        history_links [ZYRE_PIPE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
ipr_looseref_list_t
    *zyre_resource_list;            //  List of portals for object
Bool
    zyre_resource_stopped;          //  Is this portal stopped?
icl_shortstr_t
    type,                           //  Pipe type
    title;                          //  Title if any
zyre_backend_t
    *backend;                       //  Our protocol backend
ipr_looseref_list_t
    *joins;                         //  Joins for pipe
zyre_resource_t
    *asynclet;                      //  Asynclet message
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define zyre_pipe_new()                 zyre_pipe_new_ (__FILE__, __LINE__)
zyre_pipe_t *
    zyre_pipe_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    zyre_pipe_spec_valid (
http_driver_context_t * context         //  Not documented
);

void
    zyre_pipe_selftest (
void);

zyre_resource_t *
    zyre_pipe__zyre_resource_new (
void * self_v,                          //  Untyped server reference
zyre_resource_t * parent,               //  Not documented
ipr_hash_table_t * table,               //  Not documented
char * type,                            //  Not documented
char * name                             //  Not documented
);

zyre_resource_t *
    zyre_pipe__zyre_resource_factory (
zyre_resource_t * parent,               //  Not documented
ipr_hash_table_t * table,               //  Not documented
char * type,                            //  Not documented
char * name                             //  Not documented
);

#define zyre_pipe_show(item,opcode,trace_file)  zyre_pipe_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    zyre_pipe_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_pipe_destroy(self)         zyre_pipe_destroy_ (self, __FILE__, __LINE__)
void
    zyre_pipe_destroy_ (
zyre_pipe_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define zyre_pipe_link(self)            zyre_pipe_link_ (self, __FILE__, __LINE__)
zyre_pipe_t *
    zyre_pipe_link_ (
zyre_pipe_t * self,                     //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_pipe_unlink(self)          zyre_pipe_unlink_ (self, __FILE__, __LINE__)
void
    zyre_pipe_unlink_ (
zyre_pipe_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    zyre_pipe_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define zyre_pipe_new_in_scope(self_p,_scope)  zyre_pipe_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    zyre_pipe_new_in_scope_ (
zyre_pipe_t * * self_p,                 //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_PIPE_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PIPE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_PIPE_INLINE)
#   define INCLUDE_ZYRE_PIPE_INLINE
#   define INCLUDE_ZYRE_PIPE_ACTIVE

#   include "zyre_resource.h"
#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_PIPE_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PIPE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_PIPE_ROOT
#   endif
# endif
#endif
