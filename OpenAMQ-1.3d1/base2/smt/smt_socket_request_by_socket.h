/*---------------------------------------------------------------------------
    smt_socket_request_by_socket.h - smt_socket_request_by_socket component

    This class implements the list container for smt_socket_request
    Generated from smt_socket_request_by_socket.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_SAFE
#   define INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_SAFE
#   define INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_SMT_SOCKET_REQUEST_BY_SOCKET_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _smt_socket_request_by_socket_t smt_socket_request_by_socket_t;

#define SMT_SOCKET_REQUEST_BY_SOCKET_ALIVE  0xFABB
#define SMT_SOCKET_REQUEST_BY_SOCKET_DEAD  0xDEAD

#define SMT_SOCKET_REQUEST_BY_SOCKET_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL smt_socket_request_by_socket\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != SMT_SOCKET_REQUEST_BY_SOCKET_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "smt_socket_request_by_socket at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, SMT_SOCKET_REQUEST_BY_SOCKET_ALIVE, self->object_tag);\
        smt_socket_request_by_socket_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "smt_socket_request.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_ACTIVE
#   if defined (ICL_IMPORT_SMT_SOCKET_REQUEST_BY_SOCKET_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_UNSAFE
#   define INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_UNSAFE
#   define INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_ACTIVE

#   include "smt_socket_request.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    smt_socket_request_by_socket_animating;

//  Structure of the smt_socket_request_by_socket object

struct _smt_socket_request_by_socket_t {
dbyte
    object_tag;                     //  Object validity marker
smt_socket_request_t
    smt_socket_request;             //  Self starts with child object

};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define smt_socket_request_by_socket_new()  smt_socket_request_by_socket_new_ (__FILE__, __LINE__)
smt_socket_request_by_socket_t *
    smt_socket_request_by_socket_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    smt_socket_request_by_socket_selftest (
void);

int
    smt_socket_request_by_socket_isempty (
smt_socket_request_by_socket_t * self   //  Reference to object
);

int
    smt_socket_request_by_socket_push (
smt_socket_request_by_socket_t * self,   //  Reference to object
smt_socket_request_t * item             //  Not documented
);

smt_socket_request_t *
    smt_socket_request_by_socket_pop (
smt_socket_request_by_socket_t * self   //  The list
);

int
    smt_socket_request_by_socket_queue (
smt_socket_request_by_socket_t * self,   //  Reference to object
smt_socket_request_t * item             //  Not documented
);

int
    smt_socket_request_by_socket_relink_before (
smt_socket_request_t * item,            //  Not documented
smt_socket_request_t * where            //  Not documented
);

int
    smt_socket_request_by_socket_remove (
smt_socket_request_t * item             //  Not documented
);

#define smt_socket_request_by_socket_first(self)  smt_socket_request_by_socket_first_ (self, __FILE__, __LINE__)
smt_socket_request_t *
    smt_socket_request_by_socket_first_ (
smt_socket_request_by_socket_t * self,   //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_socket_request_by_socket_last(self)  smt_socket_request_by_socket_last_ (self, __FILE__, __LINE__)
smt_socket_request_t *
    smt_socket_request_by_socket_last_ (
smt_socket_request_by_socket_t * self,   //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_socket_request_by_socket_next(item)  smt_socket_request_by_socket_next_ (item, __FILE__, __LINE__)
smt_socket_request_t *
    smt_socket_request_by_socket_next_ (
smt_socket_request_t * ( * item_p ),    //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_socket_request_by_socket_prev(item)  smt_socket_request_by_socket_prev_ (item, __FILE__, __LINE__)
smt_socket_request_t *
    smt_socket_request_by_socket_prev_ (
smt_socket_request_t * ( * item_p ),    //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    smt_socket_request_by_socket_terminate (
void);

#define smt_socket_request_by_socket_show(item,opcode,trace_file)  smt_socket_request_by_socket_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    smt_socket_request_by_socket_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define smt_socket_request_by_socket_destroy(self)  smt_socket_request_by_socket_destroy_ (self, __FILE__, __LINE__)
void
    smt_socket_request_by_socket_destroy_ (
smt_socket_request_by_socket_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    smt_socket_request_by_socket_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define smt_socket_request_by_socket_new_in_scope(self_p,_scope)  smt_socket_request_by_socket_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    smt_socket_request_by_socket_new_in_scope_ (
smt_socket_request_by_socket_t * * self_p,   //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_ACTIVE
#   if defined (ICL_IMPORT_SMT_SOCKET_REQUEST_BY_SOCKET_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_INLINE)
#   define INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_INLINE
#   define INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_ACTIVE

#   include "smt_socket_request.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_NEW)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_DESTROY)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_SELFTEST)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_ISEMPTY)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_PUSH)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_POP)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_QUEUE)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_RELINK_BEFORE)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_REMOVE)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_FIRST)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_LAST)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_NEXT)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_PREV)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_REHOOK)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_UNHOOK)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_TERMINATE)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_SHOW)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_ALLOC)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_FREE)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_CACHE_PURGE)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_ANIMATE)   || defined (BASE_TRACE_SMT_SOCKET_REQUEST_BY_SOCKET_NEW_IN_SCOPE) )
void
    smt_socket_request_by_socket_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_SOCKET_REQUEST_BY_SOCKET_ACTIVE
#   if defined (ICL_IMPORT_SMT_SOCKET_REQUEST_BY_SOCKET_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_SMT_SOCKET_REQUEST_BY_SOCKET_ROOT
#   endif
# endif
#endif
