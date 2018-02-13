/*---------------------------------------------------------------------------
    demo_server_connection_list.h - demo_server_connection_list component

    This class implements the list container for demo_server_connection
    Generated from demo_server_connection_list.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_DEMO_SERVER_CONNECTION_LIST_SAFE
#   define INCLUDE_DEMO_SERVER_CONNECTION_LIST_SAFE
#   define INCLUDE_DEMO_SERVER_CONNECTION_LIST_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_DEMO_SERVER_CONNECTION_LIST_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _demo_server_connection_list_t demo_server_connection_list_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
#    define DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH 32
#endif

#define DEMO_SERVER_CONNECTION_LIST_ALIVE  0xFABB
#define DEMO_SERVER_CONNECTION_LIST_DEAD  0xDEAD

#define DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL demo_server_connection_list\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != DEMO_SERVER_CONNECTION_LIST_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "demo_server_connection_list at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, DEMO_SERVER_CONNECTION_LIST_ALIVE, self->object_tag);\
        demo_server_connection_list_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "demo_server_connection.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_SERVER_CONNECTION_LIST_ACTIVE
#   if defined (ICL_IMPORT_DEMO_SERVER_CONNECTION_LIST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_DEMO_SERVER_CONNECTION_LIST_UNSAFE
#   define INCLUDE_DEMO_SERVER_CONNECTION_LIST_UNSAFE
#   define INCLUDE_DEMO_SERVER_CONNECTION_LIST_ACTIVE

#   include "demo_server_connection.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    demo_server_connection_list_animating;

//  Structure of the demo_server_connection_list object

struct _demo_server_connection_list_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH];
    int
        history_line  [DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH];
    char
        *history_type [DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH];
    int
        history_links [DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
demo_server_connection_t
    demo_server_connection;         //  Self starts with child object

};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define demo_server_connection_list_new()  demo_server_connection_list_new_ (__FILE__, __LINE__)
demo_server_connection_list_t *
    demo_server_connection_list_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    demo_server_connection_list_selftest (
void);

int
    demo_server_connection_list_isempty (
demo_server_connection_list_t * self    //  Reference to object
);

int
    demo_server_connection_list_push (
demo_server_connection_list_t * self,   //  Reference to object
demo_server_connection_t * item         //  Not documented
);

demo_server_connection_t *
    demo_server_connection_list_pop (
demo_server_connection_list_t * self    //  The list
);

int
    demo_server_connection_list_queue (
demo_server_connection_list_t * self,   //  Reference to object
demo_server_connection_t * item         //  Not documented
);

int
    demo_server_connection_list_relink_before (
demo_server_connection_t * item,        //  Not documented
demo_server_connection_t * where        //  Not documented
);

int
    demo_server_connection_list_remove (
demo_server_connection_t * item         //  Not documented
);

#define demo_server_connection_list_first(self)  demo_server_connection_list_first_ (self, __FILE__, __LINE__)
demo_server_connection_t *
    demo_server_connection_list_first_ (
demo_server_connection_list_t * self,   //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define demo_server_connection_list_last(self)  demo_server_connection_list_last_ (self, __FILE__, __LINE__)
demo_server_connection_t *
    demo_server_connection_list_last_ (
demo_server_connection_list_t * self,   //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define demo_server_connection_list_next(item)  demo_server_connection_list_next_ (item, __FILE__, __LINE__)
demo_server_connection_t *
    demo_server_connection_list_next_ (
demo_server_connection_t * ( * item_p ),   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define demo_server_connection_list_prev(item)  demo_server_connection_list_prev_ (item, __FILE__, __LINE__)
demo_server_connection_t *
    demo_server_connection_list_prev_ (
demo_server_connection_t * ( * item_p ),   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    demo_server_connection_list_terminate (
void);

#define demo_server_connection_list_show(item,opcode,trace_file)  demo_server_connection_list_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    demo_server_connection_list_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define demo_server_connection_list_destroy(self)  demo_server_connection_list_destroy_ (self, __FILE__, __LINE__)
void
    demo_server_connection_list_destroy_ (
demo_server_connection_list_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    demo_server_connection_list_read_lock (
demo_server_connection_list_t * self    //  Reference to object
);

int
    demo_server_connection_list_write_lock (
demo_server_connection_list_t * self    //  Reference to object
);

int
    demo_server_connection_list_unlock (
demo_server_connection_list_t * self    //  Reference to object
);

#define demo_server_connection_list_link(self)  demo_server_connection_list_link_ (self, __FILE__, __LINE__)
demo_server_connection_list_t *
    demo_server_connection_list_link_ (
demo_server_connection_list_t * self,   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define demo_server_connection_list_unlink(self)  demo_server_connection_list_unlink_ (self, __FILE__, __LINE__)
void
    demo_server_connection_list_unlink_ (
demo_server_connection_list_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    demo_server_connection_list_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define demo_server_connection_list_new_in_scope(self_p,_scope)  demo_server_connection_list_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    demo_server_connection_list_new_in_scope_ (
demo_server_connection_list_t * * self_p,   //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_SERVER_CONNECTION_LIST_ACTIVE
#   if defined (ICL_IMPORT_DEMO_SERVER_CONNECTION_LIST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_DEMO_SERVER_CONNECTION_LIST_INLINE)
#   define INCLUDE_DEMO_SERVER_CONNECTION_LIST_INLINE
#   define INCLUDE_DEMO_SERVER_CONNECTION_LIST_ACTIVE

#   include "demo_server_connection.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEW)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_DESTROY)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_SELFTEST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_ISEMPTY)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_PUSH)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_POP)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_QUEUE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_RELINK_BEFORE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_REMOVE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_FIRST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_LAST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEXT)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_PREV)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_REHOOK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNHOOK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_TERMINATE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_SHOW)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_ALLOC)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_FREE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_READ_LOCK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_WRITE_LOCK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNLOCK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_LINK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNLINK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_ANIMATE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEW_IN_SCOPE) )
void
    demo_server_connection_list_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_SERVER_CONNECTION_LIST_ACTIVE
#   if defined (ICL_IMPORT_DEMO_SERVER_CONNECTION_LIST_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_DEMO_SERVER_CONNECTION_LIST_ROOT
#   endif
# endif
#endif
