/*---------------------------------------------------------------------------
    smt_demo_object_action.h - smt_demo_object_action component

This object is a demonstration of SMT objects.
    Generated from smt_demo_object_action.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_SMT_DEMO_OBJECT_ACTION_SAFE
#   define INCLUDE_SMT_DEMO_OBJECT_ACTION_SAFE
#   define INCLUDE_SMT_DEMO_OBJECT_ACTION_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_SMT_DEMO_OBJECT_ACTION_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _smt_demo_object_action_t smt_demo_object_action_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT_ACTION)
#    define SMT_DEMO_OBJECT_ACTION_HISTORY_LENGTH 32
#endif

#define SMT_DEMO_OBJECT_ACTION_ALIVE    0xFABB
#define SMT_DEMO_OBJECT_ACTION_DEAD     0xDEAD

#define SMT_DEMO_OBJECT_ACTION_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL smt_demo_object_action\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != SMT_DEMO_OBJECT_ACTION_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "smt_demo_object_action at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, SMT_DEMO_OBJECT_ACTION_ALIVE, self->object_tag);\
        smt_demo_object_action_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "smt_demo_object_action_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_DEMO_OBJECT_ACTION_ACTIVE
#   if defined (ICL_IMPORT_SMT_DEMO_OBJECT_ACTION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_SMT_DEMO_OBJECT_ACTION_UNSAFE
#   define INCLUDE_SMT_DEMO_OBJECT_ACTION_UNSAFE
#   define INCLUDE_SMT_DEMO_OBJECT_ACTION_ACTIVE

#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "smt_demo_object_action_agent.h"
//  Global variables

extern Bool
    smt_demo_object_action_animating;

//  Structure of the smt_demo_object_action object

struct _smt_demo_object_action_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT_ACTION)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [SMT_DEMO_OBJECT_ACTION_HISTORY_LENGTH];
    int
        history_line  [SMT_DEMO_OBJECT_ACTION_HISTORY_LENGTH];
    char
        *history_type [SMT_DEMO_OBJECT_ACTION_HISTORY_LENGTH];
    int
        history_links [SMT_DEMO_OBJECT_ACTION_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
char
    *string;
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define smt_demo_object_action_new(string)  smt_demo_object_action_new_ (__FILE__, __LINE__, string)
smt_demo_object_action_t *
    smt_demo_object_action_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
char * string                           //  Not documented
);

int
    smt_demo_object_action_request_expire (
smt_demo_object_action_t * self         //  Reference to object
);

int
    smt_demo_object_action_print (
smt_demo_object_action_t * self,        //  Reference to object
char * prefix                           //  Not documented
);

void
    smt_demo_object_action_selftest (
void);

#define smt_demo_object_action_destroy(self)  smt_demo_object_action_destroy_ (self, __FILE__, __LINE__)
int
    smt_demo_object_action_destroy_ (
smt_demo_object_action_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define smt_demo_object_action_unlink(self)  smt_demo_object_action_unlink_ (self, __FILE__, __LINE__)
void
    smt_demo_object_action_unlink_ (
smt_demo_object_action_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    smt_demo_object_action_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define smt_demo_object_action_free(self)  smt_demo_object_action_free_ (self, __FILE__, __LINE__)
void
    smt_demo_object_action_free_ (
smt_demo_object_action_t * self,        //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    smt_demo_object_action_terminate (
void);

#define smt_demo_object_action_show(item,opcode,trace_file)  smt_demo_object_action_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    smt_demo_object_action_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define smt_demo_object_action_link(self)  smt_demo_object_action_link_ (self, __FILE__, __LINE__)
smt_demo_object_action_t *
    smt_demo_object_action_link_ (
smt_demo_object_action_t * self,        //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_demo_object_action_new_in_scope(self_p,_scope,string)  smt_demo_object_action_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, string)
void
    smt_demo_object_action_new_in_scope_ (
smt_demo_object_action_t * * self_p,    //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
char * string                           //  Not documented
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_DEMO_OBJECT_ACTION_ACTIVE
#   if defined (ICL_IMPORT_SMT_DEMO_OBJECT_ACTION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_SMT_DEMO_OBJECT_ACTION_INLINE)
#   define INCLUDE_SMT_DEMO_OBJECT_ACTION_INLINE
#   define INCLUDE_SMT_DEMO_OBJECT_ACTION_ACTIVE

#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_NEW)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_REQUEST_EXPIRE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_PRINT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_DESTROY)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_SELFTEST)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_UNLINK)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_ANIMATE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_FREE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_INITIALISE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_TERMINATE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_SHOW)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_ALLOC)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_LINK)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_CACHE_PURGE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ACTION_NEW_IN_SCOPE) )
void
    smt_demo_object_action_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "smt_demo_object_action_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_SMT_DEMO_OBJECT_ACTION_ACTIVE
#   if defined (ICL_IMPORT_SMT_DEMO_OBJECT_ACTION_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_SMT_DEMO_OBJECT_ACTION_ROOT
#   endif
# endif
#endif
