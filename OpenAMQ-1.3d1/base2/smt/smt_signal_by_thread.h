/*---------------------------------------------------------------------------
    smt_signal_by_thread.h - smt_signal_by_thread component

    This class implements the list container for smt_signal
    Generated from smt_signal_by_thread.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_SMT_SIGNAL_BY_THREAD_SAFE
#   define INCLUDE_SMT_SIGNAL_BY_THREAD_SAFE
#   define INCLUDE_SMT_SIGNAL_BY_THREAD_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_SMT_SIGNAL_BY_THREAD_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _smt_signal_by_thread_t smt_signal_by_thread_t;

#define SMT_SIGNAL_BY_THREAD_ALIVE      0xFABB
#define SMT_SIGNAL_BY_THREAD_DEAD       0xDEAD

#define SMT_SIGNAL_BY_THREAD_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL smt_signal_by_thread\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != SMT_SIGNAL_BY_THREAD_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "smt_signal_by_thread at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, SMT_SIGNAL_BY_THREAD_ALIVE, self->object_tag);\
        smt_signal_by_thread_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "smt_signal.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_SIGNAL_BY_THREAD_ACTIVE
#   if defined (ICL_IMPORT_SMT_SIGNAL_BY_THREAD_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_SMT_SIGNAL_BY_THREAD_UNSAFE
#   define INCLUDE_SMT_SIGNAL_BY_THREAD_UNSAFE
#   define INCLUDE_SMT_SIGNAL_BY_THREAD_ACTIVE

#   include "smt_signal.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    smt_signal_by_thread_animating;

//  Structure of the smt_signal_by_thread object

struct _smt_signal_by_thread_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_signal_t
    smt_signal;                     //  Self starts with child object

};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define smt_signal_by_thread_new()      smt_signal_by_thread_new_ (__FILE__, __LINE__)
smt_signal_by_thread_t *
    smt_signal_by_thread_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    smt_signal_by_thread_selftest (
void);

int
    smt_signal_by_thread_isempty (
smt_signal_by_thread_t * self           //  Reference to object
);

int
    smt_signal_by_thread_push (
smt_signal_by_thread_t * self,          //  Reference to object
smt_signal_t * item                     //  Not documented
);

smt_signal_t *
    smt_signal_by_thread_pop (
smt_signal_by_thread_t * self           //  The list
);

int
    smt_signal_by_thread_queue (
smt_signal_by_thread_t * self,          //  Reference to object
smt_signal_t * item                     //  Not documented
);

int
    smt_signal_by_thread_relink_before (
smt_signal_t * item,                    //  Not documented
smt_signal_t * where                    //  Not documented
);

int
    smt_signal_by_thread_remove (
smt_signal_t * item                     //  Not documented
);

#define smt_signal_by_thread_first(self)  smt_signal_by_thread_first_ (self, __FILE__, __LINE__)
smt_signal_t *
    smt_signal_by_thread_first_ (
smt_signal_by_thread_t * self,          //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_signal_by_thread_last(self)  smt_signal_by_thread_last_ (self, __FILE__, __LINE__)
smt_signal_t *
    smt_signal_by_thread_last_ (
smt_signal_by_thread_t * self,          //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_signal_by_thread_next(item)  smt_signal_by_thread_next_ (item, __FILE__, __LINE__)
smt_signal_t *
    smt_signal_by_thread_next_ (
smt_signal_t * ( * item_p ),            //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_signal_by_thread_prev(item)  smt_signal_by_thread_prev_ (item, __FILE__, __LINE__)
smt_signal_t *
    smt_signal_by_thread_prev_ (
smt_signal_t * ( * item_p ),            //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    smt_signal_by_thread_terminate (
void);

#define smt_signal_by_thread_show(item,opcode,trace_file)  smt_signal_by_thread_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    smt_signal_by_thread_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define smt_signal_by_thread_destroy(self)  smt_signal_by_thread_destroy_ (self, __FILE__, __LINE__)
void
    smt_signal_by_thread_destroy_ (
smt_signal_by_thread_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    smt_signal_by_thread_read_lock (
smt_signal_by_thread_t * self           //  Reference to object
);

int
    smt_signal_by_thread_write_lock (
smt_signal_by_thread_t * self           //  Reference to object
);

int
    smt_signal_by_thread_unlock (
smt_signal_by_thread_t * self           //  Reference to object
);

void
    smt_signal_by_thread_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define smt_signal_by_thread_new_in_scope(self_p,_scope)  smt_signal_by_thread_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    smt_signal_by_thread_new_in_scope_ (
smt_signal_by_thread_t * * self_p,      //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_SIGNAL_BY_THREAD_ACTIVE
#   if defined (ICL_IMPORT_SMT_SIGNAL_BY_THREAD_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_SMT_SIGNAL_BY_THREAD_INLINE)
#   define INCLUDE_SMT_SIGNAL_BY_THREAD_INLINE
#   define INCLUDE_SMT_SIGNAL_BY_THREAD_ACTIVE

#   include "smt_signal.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_NEW)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_DESTROY)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_SELFTEST)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_ISEMPTY)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_PUSH)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_POP)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_QUEUE)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_RELINK_BEFORE)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_REMOVE)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_FIRST)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_LAST)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_NEXT)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_PREV)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_REHOOK)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_UNHOOK)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_TERMINATE)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_SHOW)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_ALLOC)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_FREE)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_READ_LOCK)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_WRITE_LOCK)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_UNLOCK)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_CACHE_PURGE)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_ANIMATE)   || defined (BASE_TRACE_SMT_SIGNAL_BY_THREAD_NEW_IN_SCOPE) )
void
    smt_signal_by_thread_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_SIGNAL_BY_THREAD_ACTIVE
#   if defined (ICL_IMPORT_SMT_SIGNAL_BY_THREAD_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_SMT_SIGNAL_BY_THREAD_ROOT
#   endif
# endif
#endif
