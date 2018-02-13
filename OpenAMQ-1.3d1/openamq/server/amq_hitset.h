/*---------------------------------------------------------------------------
    amq_hitset.h - amq_hitset component

    Holds a hitset, which is the result of a match field name and value.  
    The hitset is an array of all matching indices plus upper/lower 
    limits on this array.
    Generated from amq_hitset.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_HITSET_SAFE
#   define INCLUDE_AMQ_HITSET_SAFE
#   define INCLUDE_AMQ_HITSET_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_HITSET_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_hitset_t amq_hitset_t;

#define AMQ_HITSET_ALIVE                0xFABB
#define AMQ_HITSET_DEAD                 0xDEAD

#define AMQ_HITSET_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_hitset\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_HITSET_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_hitset at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_HITSET_ALIVE, self->object_tag);\
        amq_hitset_show (self, ICL_CALLBACK_DUMP, stderr);\
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
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_HITSET_ACTIVE
#   if defined (ICL_IMPORT_AMQ_HITSET_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_HITSET_UNSAFE
#   define INCLUDE_AMQ_HITSET_UNSAFE
#   define INCLUDE_AMQ_HITSET_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_index_hash.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_hitset_animating;

//  Structure of the amq_hitset object

struct _amq_hitset_t {
dbyte
    object_tag;                     //  Object validity marker
int
    lowest,                         //  Lowest found item
    highest;                        //  Highest found item
int
    hit_count [IPR_INDEX_MAX];      //  Hit count per item
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_hitset_new()                amq_hitset_new_ (__FILE__, __LINE__)
amq_hitset_t *
    amq_hitset_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    amq_hitset_collect (
amq_hitset_t * self,                    //  Reference to object
amq_index_hash_t * index_hash,          //  Search this hash
char * index_key                        //  For this term
);

void
    amq_hitset_selftest (
void);

void
    amq_hitset_terminate (
void);

#define amq_hitset_show(item,opcode,trace_file)  amq_hitset_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_hitset_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_hitset_destroy(self)        amq_hitset_destroy_ (self, __FILE__, __LINE__)
void
    amq_hitset_destroy_ (
amq_hitset_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_hitset_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_hitset_new_in_scope(self_p,_scope)  amq_hitset_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_hitset_new_in_scope_ (
amq_hitset_t * * self_p,                //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_HITSET_ACTIVE
#   if defined (ICL_IMPORT_AMQ_HITSET_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_HITSET_INLINE)
#   define INCLUDE_AMQ_HITSET_INLINE
#   define INCLUDE_AMQ_HITSET_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_index_hash.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_HITSET)   || defined (BASE_TRACE_AMQ_HITSET_NEW)   || defined (BASE_TRACE_AMQ_HITSET_COLLECT)   || defined (BASE_TRACE_AMQ_HITSET_SELFTEST)   || defined (BASE_TRACE_AMQ_HITSET_TERMINATE)   || defined (BASE_TRACE_AMQ_HITSET_SHOW)   || defined (BASE_TRACE_AMQ_HITSET_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_HITSET_DESTROY)   || defined (BASE_TRACE_AMQ_HITSET_ALLOC)   || defined (BASE_TRACE_AMQ_HITSET_FREE)   || defined (BASE_TRACE_AMQ_HITSET_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_HITSET_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_HITSET_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_HITSET_ANIMATE)   || defined (BASE_TRACE_AMQ_HITSET_NEW_IN_SCOPE) )
void
    amq_hitset_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_HITSET_ACTIVE
#   if defined (ICL_IMPORT_AMQ_HITSET_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_HITSET_ROOT
#   endif
# endif
#endif
