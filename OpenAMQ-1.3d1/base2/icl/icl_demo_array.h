/*---------------------------------------------------------------------------
    icl_demo_array.h - icl_demo_array component

    Generated from icl_demo_array.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_ICL_DEMO_ARRAY_SAFE
#   define INCLUDE_ICL_DEMO_ARRAY_SAFE
#   define INCLUDE_ICL_DEMO_ARRAY_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ICL_DEMO_ARRAY_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _icl_demo_array_t icl_demo_array_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
#    define ICL_DEMO_ARRAY_HISTORY_LENGTH 32
#endif

#define ICL_DEMO_ARRAY_ALIVE            0xFABB
#define ICL_DEMO_ARRAY_DEAD             0xDEAD

#define ICL_DEMO_ARRAY_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL icl_demo_array\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != ICL_DEMO_ARRAY_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "icl_demo_array at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ICL_DEMO_ARRAY_ALIVE, self->object_tag);\
        icl_demo_array_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "icl_demo_array_array.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_DEMO_ARRAY_ACTIVE
#   if defined (ICL_IMPORT_ICL_DEMO_ARRAY_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ICL_DEMO_ARRAY_UNSAFE
#   define INCLUDE_ICL_DEMO_ARRAY_UNSAFE
#   define INCLUDE_ICL_DEMO_ARRAY_ACTIVE

#   include "icl_demo_array_array.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    icl_demo_array_animating;

//  Structure of the icl_demo_array object

struct _icl_demo_array_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_ARRAY)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [ICL_DEMO_ARRAY_HISTORY_LENGTH];
    int
        history_line  [ICL_DEMO_ARRAY_HISTORY_LENGTH];
    char
        *history_type [ICL_DEMO_ARRAY_HISTORY_LENGTH];
    int
        history_links [ICL_DEMO_ARRAY_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
icl_demo_array_array_t
    *array_head;                    //  Array container                    
qbyte
    array_index;                    //  Own index into array
char *name;
char *address;
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define icl_demo_array_new(array,index,name,address)  icl_demo_array_new_ (__FILE__, __LINE__, array, index, name, address)
icl_demo_array_t *
    icl_demo_array_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
icl_demo_array_array_t * array,         //  Array to insert into
qbyte index,                            //  Index for new item
char * name,                            //  Not documented
char * address                          //  Not documented
);

void
    icl_demo_array_selftest (
void);

void
    icl_demo_array_remove_from_all_containers (
icl_demo_array_t * self                 //  The item
);

#define icl_demo_array_show(item,opcode,trace_file)  icl_demo_array_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    icl_demo_array_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    icl_demo_array_terminate (
void);

#define icl_demo_array_destroy(self)    icl_demo_array_destroy_ (self, __FILE__, __LINE__)
void
    icl_demo_array_destroy_ (
icl_demo_array_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    icl_demo_array_read_lock (
icl_demo_array_t * self                 //  Reference to object
);

int
    icl_demo_array_write_lock (
icl_demo_array_t * self                 //  Reference to object
);

int
    icl_demo_array_unlock (
icl_demo_array_t * self                 //  Reference to object
);

#define icl_demo_array_link(self)       icl_demo_array_link_ (self, __FILE__, __LINE__)
icl_demo_array_t *
    icl_demo_array_link_ (
icl_demo_array_t * self,                //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_demo_array_unlink(self)     icl_demo_array_unlink_ (self, __FILE__, __LINE__)
void
    icl_demo_array_unlink_ (
icl_demo_array_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    icl_demo_array_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define icl_demo_array_new_in_scope(self_p,_scope,array,index,name,address)  icl_demo_array_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, array, index, name, address)
void
    icl_demo_array_new_in_scope_ (
icl_demo_array_t * * self_p,            //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
icl_demo_array_array_t * array,         //  Array to insert into
qbyte index,                            //  Index for new item
char * name,                            //  Not documented
char * address                          //  Not documented
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_DEMO_ARRAY_ACTIVE
#   if defined (ICL_IMPORT_ICL_DEMO_ARRAY_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ICL_DEMO_ARRAY_INLINE)
#   define INCLUDE_ICL_DEMO_ARRAY_INLINE
#   define INCLUDE_ICL_DEMO_ARRAY_ACTIVE

#   include "icl_demo_array_array.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_NEW)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_DESTROY)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_SELFTEST)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_SHOW)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_DESTROY_PUBLIC)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_ALLOC)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_FREE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_READ_LOCK)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_WRITE_LOCK)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_UNLOCK)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_LINK)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_UNLINK)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_INITIALISE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_PURGE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_CACHE_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_ANIMATE)   || defined (BASE_TRACE_ICL_DEMO_ARRAY_NEW_IN_SCOPE) )
void
    icl_demo_array_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_DEMO_ARRAY_ACTIVE
#   if defined (ICL_IMPORT_ICL_DEMO_ARRAY_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ICL_DEMO_ARRAY_ROOT
#   endif
# endif
#endif