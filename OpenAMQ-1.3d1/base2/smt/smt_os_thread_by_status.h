/*---------------------------------------------------------------------------
    smt_os_thread_by_status.h - smt_os_thread_by_status component

    This class implements the list container for smt_os_thread
    Generated from smt_os_thread_by_status.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_SMT_OS_THREAD_BY_STATUS_SAFE
#   define INCLUDE_SMT_OS_THREAD_BY_STATUS_SAFE
#   define INCLUDE_SMT_OS_THREAD_BY_STATUS_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_SMT_OS_THREAD_BY_STATUS_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _smt_os_thread_by_status_t smt_os_thread_by_status_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_OS_THREAD_BY_STATUS)
#    define SMT_OS_THREAD_BY_STATUS_HISTORY_LENGTH 32
#endif

#define SMT_OS_THREAD_BY_STATUS_ALIVE   0xFABB
#define SMT_OS_THREAD_BY_STATUS_DEAD    0xDEAD

#define SMT_OS_THREAD_BY_STATUS_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL smt_os_thread_by_status\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != SMT_OS_THREAD_BY_STATUS_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "smt_os_thread_by_status at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, SMT_OS_THREAD_BY_STATUS_ALIVE, self->object_tag);\
        smt_os_thread_by_status_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "smt_os_thread.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_OS_THREAD_BY_STATUS_ACTIVE
#   if defined (ICL_IMPORT_SMT_OS_THREAD_BY_STATUS_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_SMT_OS_THREAD_BY_STATUS_UNSAFE
#   define INCLUDE_SMT_OS_THREAD_BY_STATUS_UNSAFE
#   define INCLUDE_SMT_OS_THREAD_BY_STATUS_ACTIVE

#   include "smt_os_thread.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    smt_os_thread_by_status_animating;

//  Structure of the smt_os_thread_by_status object

struct _smt_os_thread_by_status_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_OS_THREAD_BY_STATUS)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [SMT_OS_THREAD_BY_STATUS_HISTORY_LENGTH];
    int
        history_line  [SMT_OS_THREAD_BY_STATUS_HISTORY_LENGTH];
    char
        *history_type [SMT_OS_THREAD_BY_STATUS_HISTORY_LENGTH];
    int
        history_links [SMT_OS_THREAD_BY_STATUS_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_os_thread_t
    smt_os_thread;                  //  Self starts with child object

};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define smt_os_thread_by_status_new()   smt_os_thread_by_status_new_ (__FILE__, __LINE__)
smt_os_thread_by_status_t *
    smt_os_thread_by_status_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    smt_os_thread_by_status_selftest (
void);

int
    smt_os_thread_by_status_isempty (
smt_os_thread_by_status_t * self        //  Reference to object
);

int
    smt_os_thread_by_status_push (
smt_os_thread_by_status_t * self,       //  Reference to object
smt_os_thread_t * item                  //  Not documented
);

smt_os_thread_t *
    smt_os_thread_by_status_pop (
smt_os_thread_by_status_t * self        //  The list
);

int
    smt_os_thread_by_status_queue (
smt_os_thread_by_status_t * self,       //  Reference to object
smt_os_thread_t * item                  //  Not documented
);

int
    smt_os_thread_by_status_relink_before (
smt_os_thread_t * item,                 //  Not documented
smt_os_thread_t * where                 //  Not documented
);

int
    smt_os_thread_by_status_remove (
smt_os_thread_t * item                  //  Not documented
);

#define smt_os_thread_by_status_first(self)  smt_os_thread_by_status_first_ (self, __FILE__, __LINE__)
smt_os_thread_t *
    smt_os_thread_by_status_first_ (
smt_os_thread_by_status_t * self,       //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_os_thread_by_status_last(self)  smt_os_thread_by_status_last_ (self, __FILE__, __LINE__)
smt_os_thread_t *
    smt_os_thread_by_status_last_ (
smt_os_thread_by_status_t * self,       //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_os_thread_by_status_next(item)  smt_os_thread_by_status_next_ (item, __FILE__, __LINE__)
smt_os_thread_t *
    smt_os_thread_by_status_next_ (
smt_os_thread_t * ( * item_p ),         //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_os_thread_by_status_prev(item)  smt_os_thread_by_status_prev_ (item, __FILE__, __LINE__)
smt_os_thread_t *
    smt_os_thread_by_status_prev_ (
smt_os_thread_t * ( * item_p ),         //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    smt_os_thread_by_status_terminate (
void);

#define smt_os_thread_by_status_show(item,opcode,trace_file)  smt_os_thread_by_status_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    smt_os_thread_by_status_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define smt_os_thread_by_status_destroy(self)  smt_os_thread_by_status_destroy_ (self, __FILE__, __LINE__)
void
    smt_os_thread_by_status_destroy_ (
smt_os_thread_by_status_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    smt_os_thread_by_status_read_lock (
smt_os_thread_by_status_t * self        //  Reference to object
);

int
    smt_os_thread_by_status_write_lock (
smt_os_thread_by_status_t * self        //  Reference to object
);

int
    smt_os_thread_by_status_unlock (
smt_os_thread_by_status_t * self        //  Reference to object
);

#define smt_os_thread_by_status_link(self)  smt_os_thread_by_status_link_ (self, __FILE__, __LINE__)
smt_os_thread_by_status_t *
    smt_os_thread_by_status_link_ (
smt_os_thread_by_status_t * self,       //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_os_thread_by_status_unlink(self)  smt_os_thread_by_status_unlink_ (self, __FILE__, __LINE__)
void
    smt_os_thread_by_status_unlink_ (
smt_os_thread_by_status_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    smt_os_thread_by_status_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define smt_os_thread_by_status_new_in_scope(self_p,_scope)  smt_os_thread_by_status_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    smt_os_thread_by_status_new_in_scope_ (
smt_os_thread_by_status_t * * self_p,   //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_OS_THREAD_BY_STATUS_ACTIVE
#   if defined (ICL_IMPORT_SMT_OS_THREAD_BY_STATUS_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_SMT_OS_THREAD_BY_STATUS_INLINE)
#   define INCLUDE_SMT_OS_THREAD_BY_STATUS_INLINE
#   define INCLUDE_SMT_OS_THREAD_BY_STATUS_ACTIVE

#   include "smt_os_thread.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_NEW)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_DESTROY)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_SELFTEST)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_ISEMPTY)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_PUSH)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_POP)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_QUEUE)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_RELINK_BEFORE)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_REMOVE)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_FIRST)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_LAST)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_NEXT)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_PREV)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_REHOOK)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_UNHOOK)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_TERMINATE)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_SHOW)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_ALLOC)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_FREE)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_READ_LOCK)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_WRITE_LOCK)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_UNLOCK)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_LINK)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_UNLINK)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_CACHE_PURGE)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_ANIMATE)   || defined (BASE_TRACE_SMT_OS_THREAD_BY_STATUS_NEW_IN_SCOPE) )
void
    smt_os_thread_by_status_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_OS_THREAD_BY_STATUS_ACTIVE
#   if defined (ICL_IMPORT_SMT_OS_THREAD_BY_STATUS_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_SMT_OS_THREAD_BY_STATUS_ROOT
#   endif
# endif
#endif
