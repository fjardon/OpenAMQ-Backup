/*---------------------------------------------------------------------------
    amq_index_array.h - amq_index_array component

    This class implements the array container for amq_index
    Generated from amq_index_array.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_INDEX_ARRAY_SAFE
#   define INCLUDE_AMQ_INDEX_ARRAY_SAFE
#   define INCLUDE_AMQ_INDEX_ARRAY_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_INDEX_ARRAY_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_index_array_t amq_index_array_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX_ARRAY)
#    define AMQ_INDEX_ARRAY_HISTORY_LENGTH 32
#endif

#define AMQ_INDEX_ARRAY_ALIVE           0xFABB
#define AMQ_INDEX_ARRAY_DEAD            0xDEAD

#define AMQ_INDEX_ARRAY_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_index_array\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_INDEX_ARRAY_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_index_array at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_INDEX_ARRAY_ALIVE, self->object_tag);\
        amq_index_array_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_index.h"
#   include "icl_longstr.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_INDEX_ARRAY_ACTIVE
#   if defined (ICL_IMPORT_AMQ_INDEX_ARRAY_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_INDEX_ARRAY_UNSAFE
#   define INCLUDE_AMQ_INDEX_ARRAY_UNSAFE
#   define INCLUDE_AMQ_INDEX_ARRAY_ACTIVE

#   include "amq_index.h"
#   include "icl_longstr.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_index_array_animating;

//  Structure of the amq_index_array object

struct _amq_index_array_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX_ARRAY)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_INDEX_ARRAY_HISTORY_LENGTH];
    int
        history_line  [AMQ_INDEX_ARRAY_HISTORY_LENGTH];
    char
        *history_type [AMQ_INDEX_ARRAY_HISTORY_LENGTH];
    int
        history_links [AMQ_INDEX_ARRAY_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
qbyte
    bound;                          //  Top bound, last + 1                
qbyte
    size;                           //  Size of array, nbr entries         
amq_index_t   
    **data;                         //  Array data block
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_index_array_new()           amq_index_array_new_ (__FILE__, __LINE__)
amq_index_array_t *
    amq_index_array_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_index_array_selftest (
void);

int
    amq_index_array_reset (
amq_index_array_t * self                //  Reference to object
);

int
    amq_index_array_insert (
amq_index_array_t * self,               //  Reference to object
qbyte index,                            //  Array index
amq_index_t * item                      //  Item to insert
);

int
    amq_index_array_remove (
amq_index_t * item                      //  Item to remove
);

amq_index_t *
    amq_index_array_fetch (
amq_index_array_t * self,               //  The array
qbyte index                             //  Array index
);

qbyte
    amq_index_array_ubound (
amq_index_array_t * self                //  The array
);

void
    amq_index_array_terminate (
void);

#define amq_index_array_show(item,opcode,trace_file)  amq_index_array_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_index_array_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_index_array_destroy(self)   amq_index_array_destroy_ (self, __FILE__, __LINE__)
void
    amq_index_array_destroy_ (
amq_index_array_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define amq_index_array_link(self)      amq_index_array_link_ (self, __FILE__, __LINE__)
amq_index_array_t *
    amq_index_array_link_ (
amq_index_array_t * self,               //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_index_array_unlink(self)    amq_index_array_unlink_ (self, __FILE__, __LINE__)
void
    amq_index_array_unlink_ (
amq_index_array_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_index_array_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_index_array_new_in_scope(self_p,_scope)  amq_index_array_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_index_array_new_in_scope_ (
amq_index_array_t * * self_p,           //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_INDEX_ARRAY_ACTIVE
#   if defined (ICL_IMPORT_AMQ_INDEX_ARRAY_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_INDEX_ARRAY_INLINE)
#   define INCLUDE_AMQ_INDEX_ARRAY_INLINE
#   define INCLUDE_AMQ_INDEX_ARRAY_ACTIVE

#   include "amq_index.h"
#   include "icl_longstr.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_NEW)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_DESTROY)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_SELFTEST)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_RESET)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_INSERT)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_REMOVE)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_FETCH)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_UBOUND)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_TERMINATE)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_SHOW)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_ALLOC)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_FREE)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_LINK)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_UNLINK)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_ANIMATE)   || defined (BASE_TRACE_AMQ_INDEX_ARRAY_NEW_IN_SCOPE) )
void
    amq_index_array_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_INDEX_ARRAY_ACTIVE
#   if defined (ICL_IMPORT_AMQ_INDEX_ARRAY_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_INDEX_ARRAY_ROOT
#   endif
# endif
#endif
