/*---------------------------------------------------------------------------
    ipr_symbol.h - ipr_symbol component

Implements a symbol table that holds arbitrary data, keyed by name.
Can be used directly, or inherited to create specific symbol table
structures.
    Generated from ipr_symbol.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_IPR_SYMBOL_SAFE
#   define INCLUDE_IPR_SYMBOL_SAFE
#   define INCLUDE_IPR_SYMBOL_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_IPR_SYMBOL_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _ipr_symbol_t ipr_symbol_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
#    define IPR_SYMBOL_HISTORY_LENGTH 32
#endif

#define IPR_SYMBOL_ALIVE                0xFABB
#define IPR_SYMBOL_DEAD                 0xDEAD

#define IPR_SYMBOL_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL ipr_symbol\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != IPR_SYMBOL_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "ipr_symbol at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, IPR_SYMBOL_ALIVE, self->object_tag);\
        ipr_symbol_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "ipr_regexp.h"
#   include "ipr_symbol_table.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_SYMBOL_ACTIVE
#   if defined (ICL_IMPORT_IPR_SYMBOL_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_IPR_SYMBOL_UNSAFE
#   define INCLUDE_IPR_SYMBOL_UNSAFE
#   define INCLUDE_IPR_SYMBOL_ACTIVE

#   include "ipr_regexp.h"
#   include "ipr_symbol_table.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    ipr_symbol_animating;

//  Structure of the ipr_symbol object

struct _ipr_symbol_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_SYMBOL)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [IPR_SYMBOL_HISTORY_LENGTH];
    int
        history_line  [IPR_SYMBOL_HISTORY_LENGTH];
    char
        *history_type [IPR_SYMBOL_HISTORY_LENGTH];
    int
        history_links [IPR_SYMBOL_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
ipr_symbol_table_t
    *table_head;                    //  Hash table container
ipr_symbol_t
    *table_next;                    //  Next item in the hash slot
qbyte
    table_index;                    //  Index of item in table
icl_shortstr_t
    key;                            //  Item's original key
void
    *data;                          //  Data value for item
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define ipr_symbol_new(table,key,data)  ipr_symbol_new_ (__FILE__, __LINE__, table, key, data)
ipr_symbol_t *
    ipr_symbol_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
ipr_symbol_table_t * table,             //  Table to insert into
char * key,                             //  Hash key
void * data                             //  Data for symbol
);

void
    ipr_symbol_assume (
ipr_symbol_table_t * table,             //  Symbol table
char * name,                            //  Symbol name
void * data                             //  Data for symbol
);

void
    ipr_symbol_selftest (
void);

void
    ipr_symbol_remove_from_all_containers (
ipr_symbol_t * self                     //  The item
);

#define ipr_symbol_show(item,opcode,trace_file)  ipr_symbol_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    ipr_symbol_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    ipr_symbol_terminate (
void);

#define ipr_symbol_destroy(self)        ipr_symbol_destroy_ (self, __FILE__, __LINE__)
void
    ipr_symbol_destroy_ (
ipr_symbol_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    ipr_symbol_read_lock (
ipr_symbol_t * self                     //  Reference to object
);

int
    ipr_symbol_write_lock (
ipr_symbol_t * self                     //  Reference to object
);

int
    ipr_symbol_unlock (
ipr_symbol_t * self                     //  Reference to object
);

#define ipr_symbol_link(self)           ipr_symbol_link_ (self, __FILE__, __LINE__)
ipr_symbol_t *
    ipr_symbol_link_ (
ipr_symbol_t * self,                    //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_symbol_unlink(self)         ipr_symbol_unlink_ (self, __FILE__, __LINE__)
void
    ipr_symbol_unlink_ (
ipr_symbol_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    ipr_symbol_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define ipr_symbol_new_in_scope(self_p,_scope,table,key,data)  ipr_symbol_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, table, key, data)
void
    ipr_symbol_new_in_scope_ (
ipr_symbol_t * * self_p,                //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
ipr_symbol_table_t * table,             //  Table to insert into
char * key,                             //  Hash key
void * data                             //  Data for symbol
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_SYMBOL_ACTIVE
#   if defined (ICL_IMPORT_IPR_SYMBOL_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_IPR_SYMBOL_INLINE)
#   define INCLUDE_IPR_SYMBOL_INLINE
#   define INCLUDE_IPR_SYMBOL_ACTIVE

#   include "ipr_regexp.h"
#   include "ipr_symbol_table.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SYMBOL)   || defined (BASE_TRACE_IPR_SYMBOL_NEW)   || defined (BASE_TRACE_IPR_SYMBOL_DESTROY)   || defined (BASE_TRACE_IPR_SYMBOL_ASSUME)   || defined (BASE_TRACE_IPR_SYMBOL_SELFTEST)   || defined (BASE_TRACE_IPR_SYMBOL_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_IPR_SYMBOL_SHOW)   || defined (BASE_TRACE_IPR_SYMBOL_TERMINATE)   || defined (BASE_TRACE_IPR_SYMBOL_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_SYMBOL_ALLOC)   || defined (BASE_TRACE_IPR_SYMBOL_FREE)   || defined (BASE_TRACE_IPR_SYMBOL_READ_LOCK)   || defined (BASE_TRACE_IPR_SYMBOL_WRITE_LOCK)   || defined (BASE_TRACE_IPR_SYMBOL_UNLOCK)   || defined (BASE_TRACE_IPR_SYMBOL_LINK)   || defined (BASE_TRACE_IPR_SYMBOL_UNLINK)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_PURGE)   || defined (BASE_TRACE_IPR_SYMBOL_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_SYMBOL_ANIMATE)   || defined (BASE_TRACE_IPR_SYMBOL_NEW_IN_SCOPE) )
void
    ipr_symbol_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_SYMBOL_ACTIVE
#   if defined (ICL_IMPORT_IPR_SYMBOL_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_IPR_SYMBOL_ROOT
#   endif
# endif
#endif
