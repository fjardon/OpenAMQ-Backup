/*---------------------------------------------------------------------------
    amq_exchange_table.h - amq_exchange_table component

    This class implements the hash table container for amq_exchange
    Generated from amq_exchange_table.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    
    This file is licensed under the GPL as follows:
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at
    your option) any later version.
    
    This program is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.
    
    For information on alternative licensing for OEMs, please contact
    iMatix Corporation.

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_AMQ_EXCHANGE_TABLE_SAFE
#   define INCLUDE_AMQ_EXCHANGE_TABLE_SAFE
#   define INCLUDE_AMQ_EXCHANGE_TABLE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_EXCHANGE_TABLE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_exchange_table_t amq_exchange_table_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_TABLE)
#    define AMQ_EXCHANGE_TABLE_HISTORY_LENGTH 32
#endif

#define AMQ_EXCHANGE_TABLE_ALIVE        0xFABB
#define AMQ_EXCHANGE_TABLE_DEAD         0xDEAD

#define AMQ_EXCHANGE_TABLE_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_exchange_table\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_EXCHANGE_TABLE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_exchange_table at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_EXCHANGE_TABLE_ALIVE, self->object_tag);\
        amq_exchange_table_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_exchange.h"
#   include "icl_shortstr.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_EXCHANGE_TABLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_TABLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_EXCHANGE_TABLE_UNSAFE
#   define INCLUDE_AMQ_EXCHANGE_TABLE_UNSAFE
#   define INCLUDE_AMQ_EXCHANGE_TABLE_ACTIVE

#   include "icl_shortstr.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_exchange_table_animating;
#define AMQ_EXCHANGE_TABLE_INITIAL_SIZE  255
#define AMQ_EXCHANGE_TABLE_LOAD_FACTOR  75
#define AMQ_EXCHANGE_TABLE_GROWTH_FACTOR 200

typedef void (amq_exchange_table_callback_fn) (amq_exchange_t *item, void *argument);

//  Structure of the amq_exchange_table object

struct _amq_exchange_table_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE_TABLE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_EXCHANGE_TABLE_HISTORY_LENGTH];
    int
        history_line  [AMQ_EXCHANGE_TABLE_HISTORY_LENGTH];
    char
        *history_type [AMQ_EXCHANGE_TABLE_HISTORY_LENGTH];
    int
        history_links [AMQ_EXCHANGE_TABLE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
size_t
    nbr_items;
size_t
    max_items;
amq_exchange_t
    **table_items;
};

#   ifdef __cplusplus
}
#   endif
#   include "amq_exchange.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_exchange_table_new()        amq_exchange_table_new_ (__FILE__, __LINE__)
amq_exchange_table_t *
    amq_exchange_table_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_exchange_table_selftest (
void);

int
    amq_exchange_table_insert (
amq_exchange_table_t * self,            //  Reference to object
char * key,                             //  Hash key
amq_exchange_t * item                   //  Item to insert
);

int
    amq_exchange_table_remove (
amq_exchange_t * item                   //  Item to remove
);

amq_exchange_t *
    amq_exchange_table_search (
amq_exchange_table_t * self,            //  Table to search
char * key                              //  Hash key
);

void
    amq_exchange_table_apply (
amq_exchange_table_t * self,            //  Table to iterate
amq_exchange_table_callback_fn * callback,   //  Not documented
void * argument                         //  Arbitrary argument pointer
);

void
    amq_exchange_table_terminate (
void);

#define amq_exchange_table_show(item,opcode,trace_file)  amq_exchange_table_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_exchange_table_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_exchange_table_destroy(self)  amq_exchange_table_destroy_ (self, __FILE__, __LINE__)
void
    amq_exchange_table_destroy_ (
amq_exchange_table_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    amq_exchange_table_read_lock (
amq_exchange_table_t * self             //  Reference to object
);

int
    amq_exchange_table_write_lock (
amq_exchange_table_t * self             //  Reference to object
);

int
    amq_exchange_table_unlock (
amq_exchange_table_t * self             //  Reference to object
);

#define amq_exchange_table_link(self)   amq_exchange_table_link_ (self, __FILE__, __LINE__)
amq_exchange_table_t *
    amq_exchange_table_link_ (
amq_exchange_table_t * self,            //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_exchange_table_unlink(self)  amq_exchange_table_unlink_ (self, __FILE__, __LINE__)
void
    amq_exchange_table_unlink_ (
amq_exchange_table_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_exchange_table_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_exchange_table_new_in_scope(self_p,_scope)  amq_exchange_table_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_exchange_table_new_in_scope_ (
amq_exchange_table_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_EXCHANGE_TABLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_TABLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_EXCHANGE_TABLE_INLINE)
#   define INCLUDE_AMQ_EXCHANGE_TABLE_INLINE
#   define INCLUDE_AMQ_EXCHANGE_TABLE_ACTIVE

#   include "amq_exchange.h"
#   include "icl_shortstr.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_NEW)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_DESTROY)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_SELFTEST)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_INSERT)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_REMOVE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_SEARCH)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_APPLY)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_TERMINATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_SHOW)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_ALLOC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_FREE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_READ_LOCK)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_UNLOCK)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_LINK)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_UNLINK)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_ANIMATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TABLE_NEW_IN_SCOPE) )
void
    amq_exchange_table_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_EXCHANGE_TABLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_TABLE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_EXCHANGE_TABLE_ROOT
#   endif
# endif
#endif
