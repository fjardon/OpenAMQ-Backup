/*---------------------------------------------------------------------------
    ipr_bucket_list.h - ipr_bucket_list component

    Generated from ipr_bucket_list.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_IPR_BUCKET_LIST_SAFE
#   define INCLUDE_IPR_BUCKET_LIST_SAFE
#   define INCLUDE_IPR_BUCKET_LIST_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_IPR_BUCKET_LIST_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _ipr_bucket_list_t ipr_bucket_list_t;

#define IPR_BUCKET_LIST_ALIVE           0xFABB
#define IPR_BUCKET_LIST_DEAD            0xDEAD

#define IPR_BUCKET_LIST_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL ipr_bucket_list\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != IPR_BUCKET_LIST_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "ipr_bucket_list at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, IPR_BUCKET_LIST_ALIVE, self->object_tag);\
        ipr_bucket_list_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "ipr_bucket.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_BUCKET_LIST_ACTIVE
#   if defined (ICL_IMPORT_IPR_BUCKET_LIST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_IPR_BUCKET_LIST_UNSAFE
#   define INCLUDE_IPR_BUCKET_LIST_UNSAFE
#   define INCLUDE_IPR_BUCKET_LIST_ACTIVE

#   include "ipr_bucket.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    ipr_bucket_list_animating;
//  The iterator type

typedef struct _ipr_bucket_list_iter_t ipr_bucket_list_iter_t;

struct _ipr_bucket_list_iter_t {
    volatile ipr_bucket_list_t *head;
    volatile ipr_bucket_list_iter_t *prev;
    volatile ipr_bucket_list_iter_t *next;
    ipr_bucket_t *item;
};

//  Structure of the ipr_bucket_list object

struct _ipr_bucket_list_t {
dbyte
    object_tag;                     //  Object validity marker
ipr_bucket_list_iter_t
    ipr_bucket_list_iter;               //  Self starts with child object

};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
int
    ipr_bucket_list_clear (
ipr_bucket_list_t * self                //  Reference to object
);

void
    ipr_bucket_list_selftest (
void);

ipr_bucket_list_iter_t *
    ipr_bucket_list_iter_new (
ipr_bucket_t * item                     //  Not documented
);

ipr_bucket_t *
    ipr_bucket_list_iter_object (
ipr_bucket_list_iter_t * iter           //  Not documented
);

void
    ipr_bucket_list_iter_destroy (
ipr_bucket_list_iter_t * ( * iter_p )   //  Not documented
);

#define ipr_bucket_list_new()           ipr_bucket_list_new_ (__FILE__, __LINE__)
ipr_bucket_list_t *
    ipr_bucket_list_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    ipr_bucket_list_isempty (
ipr_bucket_list_t * self                //  Reference to object
);

int
    ipr_bucket_list_push (
ipr_bucket_list_t * self,               //  Reference to object
ipr_bucket_t * item                     //  Not documented
);

ipr_bucket_t *
    ipr_bucket_list_pop (
ipr_bucket_list_t * self                //  The list
);

int
    ipr_bucket_list_queue (
ipr_bucket_list_t * self,               //  Reference to object
ipr_bucket_t * item                     //  Not documented
);

int
    ipr_bucket_list_relink_before (
ipr_bucket_list_iter_t * item,          //  Not documented
ipr_bucket_list_iter_t * where          //  Not documented
);

int
    ipr_bucket_list_remove (
ipr_bucket_list_iter_t * item           //  Not documented
);

#define ipr_bucket_list_first(self)     ipr_bucket_list_first_ (self, __FILE__, __LINE__)
ipr_bucket_list_iter_t *
    ipr_bucket_list_first_ (
ipr_bucket_list_t * self,               //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_bucket_list_last(self)      ipr_bucket_list_last_ (self, __FILE__, __LINE__)
ipr_bucket_list_iter_t *
    ipr_bucket_list_last_ (
ipr_bucket_list_t * self,               //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_bucket_list_next(item)      ipr_bucket_list_next_ (item, __FILE__, __LINE__)
ipr_bucket_list_iter_t *
    ipr_bucket_list_next_ (
ipr_bucket_list_iter_t * ( * item_p ),   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_bucket_list_prev(item)      ipr_bucket_list_prev_ (item, __FILE__, __LINE__)
ipr_bucket_list_iter_t *
    ipr_bucket_list_prev_ (
ipr_bucket_list_iter_t * ( * item_p ),   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    ipr_bucket_list_terminate (
void);

#define ipr_bucket_list_show(item,opcode,trace_file)  ipr_bucket_list_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    ipr_bucket_list_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define ipr_bucket_list_destroy(self)   ipr_bucket_list_destroy_ (self, __FILE__, __LINE__)
void
    ipr_bucket_list_destroy_ (
ipr_bucket_list_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    ipr_bucket_list_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define ipr_bucket_list_new_in_scope(self_p,_scope)  ipr_bucket_list_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    ipr_bucket_list_new_in_scope_ (
ipr_bucket_list_t * * self_p,           //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_BUCKET_LIST_ACTIVE
#   if defined (ICL_IMPORT_IPR_BUCKET_LIST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_IPR_BUCKET_LIST_INLINE)
#   define INCLUDE_IPR_BUCKET_LIST_INLINE
#   define INCLUDE_IPR_BUCKET_LIST_ACTIVE

#   include "ipr_bucket.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BUCKET_LIST)   || defined (BASE_TRACE_IPR_BUCKET_LIST_CLEAR)   || defined (BASE_TRACE_IPR_BUCKET_LIST_SELFTEST)   || defined (BASE_TRACE_IPR_BUCKET_LIST_ITER_NEW)   || defined (BASE_TRACE_IPR_BUCKET_LIST_ITER_OBJECT)   || defined (BASE_TRACE_IPR_BUCKET_LIST_ITER_DESTROY)   || defined (BASE_TRACE_IPR_BUCKET_LIST_NEW)   || defined (BASE_TRACE_IPR_BUCKET_LIST_DESTROY)   || defined (BASE_TRACE_IPR_BUCKET_LIST_ISEMPTY)   || defined (BASE_TRACE_IPR_BUCKET_LIST_PUSH)   || defined (BASE_TRACE_IPR_BUCKET_LIST_POP)   || defined (BASE_TRACE_IPR_BUCKET_LIST_QUEUE)   || defined (BASE_TRACE_IPR_BUCKET_LIST_RELINK_BEFORE)   || defined (BASE_TRACE_IPR_BUCKET_LIST_REMOVE)   || defined (BASE_TRACE_IPR_BUCKET_LIST_FIRST)   || defined (BASE_TRACE_IPR_BUCKET_LIST_LAST)   || defined (BASE_TRACE_IPR_BUCKET_LIST_NEXT)   || defined (BASE_TRACE_IPR_BUCKET_LIST_PREV)   || defined (BASE_TRACE_IPR_BUCKET_LIST_REHOOK)   || defined (BASE_TRACE_IPR_BUCKET_LIST_UNHOOK)   || defined (BASE_TRACE_IPR_BUCKET_LIST_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_BUCKET_LIST_CACHE_PURGE)   || defined (BASE_TRACE_IPR_BUCKET_LIST_TERMINATE)   || defined (BASE_TRACE_IPR_BUCKET_LIST_SHOW)   || defined (BASE_TRACE_IPR_BUCKET_LIST_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_BUCKET_LIST_ALLOC)   || defined (BASE_TRACE_IPR_BUCKET_LIST_FREE)   || defined (BASE_TRACE_IPR_BUCKET_LIST_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_BUCKET_LIST_ANIMATE)   || defined (BASE_TRACE_IPR_BUCKET_LIST_NEW_IN_SCOPE) )
void
    ipr_bucket_list_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_BUCKET_LIST_ACTIVE
#   if defined (ICL_IMPORT_IPR_BUCKET_LIST_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_IPR_BUCKET_LIST_ROOT
#   endif
# endif
#endif
