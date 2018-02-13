/*---------------------------------------------------------------------------
    amq_index.h - amq_index component

    Holds a match index, which is a text string on which AMQ will index and
    match messages.  Each index holds a bindset bitmap that represents all
    bindings that match that index.  Indices can be accessed via a hash
    lookup (by value) or array lookup (by number, for iterating through all
    indices).
    Generated from amq_index.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_INDEX_SAFE
#   define INCLUDE_AMQ_INDEX_SAFE
#   define INCLUDE_AMQ_INDEX_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_INDEX_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_index_t amq_index_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
#    define AMQ_INDEX_HISTORY_LENGTH 32
#endif

#define AMQ_INDEX_ALIVE                 0xFABB
#define AMQ_INDEX_DEAD                  0xDEAD

#define AMQ_INDEX_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_index\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_INDEX_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_index at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_INDEX_ALIVE, self->object_tag);\
        amq_index_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "amq_index_hash.h"
#   include "amq_index_array.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_INDEX_ACTIVE
#   if defined (ICL_IMPORT_AMQ_INDEX_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_INDEX_UNSAFE
#   define INCLUDE_AMQ_INDEX_UNSAFE
#   define INCLUDE_AMQ_INDEX_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_index_hash.h"
#   include "amq_index_array.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_index_animating;

//  Structure of the amq_index object

struct _amq_index_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_INDEX_HISTORY_LENGTH];
    int
        history_line  [AMQ_INDEX_HISTORY_LENGTH];
    char
        *history_type [AMQ_INDEX_HISTORY_LENGTH];
    int
        history_links [AMQ_INDEX_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
amq_index_hash_t
    *hash_head;                     //  Hash table container
amq_index_t
    *hash_next;                     //  Next item in the hash slot
qbyte
    hash_index;                     //  Index of item in table
icl_shortstr_t
    key;                            //  Item's original key
amq_index_array_t
    *array_head;                    //  Array container                    
qbyte
    array_index;                    //  Own index into array
ipr_bits_t
    *bindset;                       //  Bitmap of bindings that match
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_index_new(table,key,array)  amq_index_new_ (__FILE__, __LINE__, table, key, array)
amq_index_t *
    amq_index_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_index_hash_t * table,               //  Table to insert into
char * key,                             //  Hash key
amq_index_array_t * array               //  Array to insert into
);

void
    amq_index_selftest (
void);

qbyte
    amq_index_count (
void);

void
    amq_index_remove_from_all_containers (
amq_index_t * self                      //  The itemThe item
);

#define amq_index_show(item,opcode,trace_file)  amq_index_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_index_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    amq_index_terminate (
void);

#define amq_index_destroy(self)         amq_index_destroy_ (self, __FILE__, __LINE__)
void
    amq_index_destroy_ (
amq_index_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define amq_index_link(self)            amq_index_link_ (self, __FILE__, __LINE__)
amq_index_t *
    amq_index_link_ (
amq_index_t * self,                     //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_index_unlink(self)          amq_index_unlink_ (self, __FILE__, __LINE__)
void
    amq_index_unlink_ (
amq_index_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_index_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_index_new_in_scope(self_p,_scope,table,key,array)  amq_index_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, table, key, array)
void
    amq_index_new_in_scope_ (
amq_index_t * * self_p,                 //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_index_hash_t * table,               //  Table to insert into
char * key,                             //  Hash key
amq_index_array_t * array               //  Array to insert into
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_INDEX_ACTIVE
#   if defined (ICL_IMPORT_AMQ_INDEX_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_INDEX_INLINE)
#   define INCLUDE_AMQ_INDEX_INLINE
#   define INCLUDE_AMQ_INDEX_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_index_hash.h"
#   include "amq_index_array.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX)   || defined (BASE_TRACE_AMQ_INDEX_NEW)   || defined (BASE_TRACE_AMQ_INDEX_DESTROY)   || defined (BASE_TRACE_AMQ_INDEX_SELFTEST)   || defined (BASE_TRACE_AMQ_INDEX_COUNT)   || defined (BASE_TRACE_AMQ_INDEX_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_INDEX_SHOW)   || defined (BASE_TRACE_AMQ_INDEX_TERMINATE)   || defined (BASE_TRACE_AMQ_INDEX_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_INDEX_ALLOC)   || defined (BASE_TRACE_AMQ_INDEX_FREE)   || defined (BASE_TRACE_AMQ_INDEX_LINK)   || defined (BASE_TRACE_AMQ_INDEX_UNLINK)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_INDEX_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_INDEX_ANIMATE)   || defined (BASE_TRACE_AMQ_INDEX_NEW_IN_SCOPE) )
void
    amq_index_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_INDEX_ACTIVE
#   if defined (ICL_IMPORT_AMQ_INDEX_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_INDEX_ROOT
#   endif
# endif
#endif
