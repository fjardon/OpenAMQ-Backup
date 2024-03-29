/*---------------------------------------------------------------------------
    demo_exchange_table.h - demo_exchange_table component

    This class implements the hash table container for demo_exchange
    Generated from demo_exchange_table.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_DEMO_EXCHANGE_TABLE_SAFE
#   define INCLUDE_DEMO_EXCHANGE_TABLE_SAFE
#   define INCLUDE_DEMO_EXCHANGE_TABLE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_DEMO_EXCHANGE_TABLE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _demo_exchange_table_t demo_exchange_table_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE_TABLE)
#    define DEMO_EXCHANGE_TABLE_HISTORY_LENGTH 32
#endif

#define DEMO_EXCHANGE_TABLE_ALIVE       0xFABB
#define DEMO_EXCHANGE_TABLE_DEAD        0xDEAD

#define DEMO_EXCHANGE_TABLE_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL demo_exchange_table\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != DEMO_EXCHANGE_TABLE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "demo_exchange_table at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, DEMO_EXCHANGE_TABLE_ALIVE, self->object_tag);\
        demo_exchange_table_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "demo_exchange.h"
#   include "icl_shortstr.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_EXCHANGE_TABLE_ACTIVE
#   if defined (ICL_IMPORT_DEMO_EXCHANGE_TABLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_DEMO_EXCHANGE_TABLE_UNSAFE
#   define INCLUDE_DEMO_EXCHANGE_TABLE_UNSAFE
#   define INCLUDE_DEMO_EXCHANGE_TABLE_ACTIVE

#   include "icl_shortstr.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    demo_exchange_table_animating;
#define DEMO_EXCHANGE_TABLE_INITIAL_SIZE  255
#define DEMO_EXCHANGE_TABLE_LOAD_FACTOR  75
#define DEMO_EXCHANGE_TABLE_GROWTH_FACTOR 200

typedef void (demo_exchange_table_callback_fn) (demo_exchange_t *item, void *argument);

//  Structure of the demo_exchange_table object

struct _demo_exchange_table_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE_TABLE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [DEMO_EXCHANGE_TABLE_HISTORY_LENGTH];
    int
        history_line  [DEMO_EXCHANGE_TABLE_HISTORY_LENGTH];
    char
        *history_type [DEMO_EXCHANGE_TABLE_HISTORY_LENGTH];
    int
        history_links [DEMO_EXCHANGE_TABLE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
size_t
    nbr_items;
size_t
    max_items;
demo_exchange_t
    **table_items;
};

#   ifdef __cplusplus
}
#   endif
#   include "demo_exchange.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define demo_exchange_table_new()       demo_exchange_table_new_ (__FILE__, __LINE__)
demo_exchange_table_t *
    demo_exchange_table_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    demo_exchange_table_selftest (
void);

int
    demo_exchange_table_insert (
demo_exchange_table_t * self,           //  Reference to object
char * key,                             //  Hash key
demo_exchange_t * item                  //  Item to insert
);

int
    demo_exchange_table_remove (
demo_exchange_t * item                  //  Item to remove
);

demo_exchange_t *
    demo_exchange_table_search (
demo_exchange_table_t * self,           //  Table to search
char * key                              //  Hash key
);

void
    demo_exchange_table_apply (
demo_exchange_table_t * self,           //  Table to iterate
demo_exchange_table_callback_fn * callback,   //  Not documented
void * argument                         //  Arbitrary argument pointer
);

void
    demo_exchange_table_terminate (
void);

#define demo_exchange_table_show(item,opcode,trace_file)  demo_exchange_table_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    demo_exchange_table_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define demo_exchange_table_destroy(self)  demo_exchange_table_destroy_ (self, __FILE__, __LINE__)
void
    demo_exchange_table_destroy_ (
demo_exchange_table_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    demo_exchange_table_read_lock (
demo_exchange_table_t * self            //  Reference to object
);

int
    demo_exchange_table_write_lock (
demo_exchange_table_t * self            //  Reference to object
);

int
    demo_exchange_table_unlock (
demo_exchange_table_t * self            //  Reference to object
);

#define demo_exchange_table_link(self)  demo_exchange_table_link_ (self, __FILE__, __LINE__)
demo_exchange_table_t *
    demo_exchange_table_link_ (
demo_exchange_table_t * self,           //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define demo_exchange_table_unlink(self)  demo_exchange_table_unlink_ (self, __FILE__, __LINE__)
void
    demo_exchange_table_unlink_ (
demo_exchange_table_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    demo_exchange_table_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define demo_exchange_table_new_in_scope(self_p,_scope)  demo_exchange_table_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    demo_exchange_table_new_in_scope_ (
demo_exchange_table_t * * self_p,       //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_EXCHANGE_TABLE_ACTIVE
#   if defined (ICL_IMPORT_DEMO_EXCHANGE_TABLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_DEMO_EXCHANGE_TABLE_INLINE)
#   define INCLUDE_DEMO_EXCHANGE_TABLE_INLINE
#   define INCLUDE_DEMO_EXCHANGE_TABLE_ACTIVE

#   include "demo_exchange.h"
#   include "icl_shortstr.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_NEW)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_DESTROY)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_SELFTEST)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_INSERT)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_REMOVE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_SEARCH)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_APPLY)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_TERMINATE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_SHOW)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_ALLOC)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_FREE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_READ_LOCK)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_WRITE_LOCK)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_UNLOCK)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_LINK)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_UNLINK)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_ANIMATE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TABLE_NEW_IN_SCOPE) )
void
    demo_exchange_table_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_EXCHANGE_TABLE_ACTIVE
#   if defined (ICL_IMPORT_DEMO_EXCHANGE_TABLE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_DEMO_EXCHANGE_TABLE_ROOT
#   endif
# endif
#endif
