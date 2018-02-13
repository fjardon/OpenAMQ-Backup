/*---------------------------------------------------------------------------
    amq_index_hash.h - amq_index_hash component

    This class implements the hash table container for amq_index
    Generated from amq_index_hash.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_INDEX_HASH_SAFE
#   define INCLUDE_AMQ_INDEX_HASH_SAFE
#   define INCLUDE_AMQ_INDEX_HASH_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_INDEX_HASH_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_index_hash_t amq_index_hash_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX_HASH)
#    define AMQ_INDEX_HASH_HISTORY_LENGTH 32
#endif

#define AMQ_INDEX_HASH_ALIVE            0xFABB
#define AMQ_INDEX_HASH_DEAD             0xDEAD

#define AMQ_INDEX_HASH_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_index_hash\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_INDEX_HASH_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_index_hash at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_INDEX_HASH_ALIVE, self->object_tag);\
        amq_index_hash_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_index.h"
#   include "icl_shortstr.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_INDEX_HASH_ACTIVE
#   if defined (ICL_IMPORT_AMQ_INDEX_HASH_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_INDEX_HASH_UNSAFE
#   define INCLUDE_AMQ_INDEX_HASH_UNSAFE
#   define INCLUDE_AMQ_INDEX_HASH_ACTIVE

#   include "icl_shortstr.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_index_hash_animating;
#define AMQ_INDEX_HASH_INITIAL_SIZE     255
#define AMQ_INDEX_HASH_LOAD_FACTOR      75
#define AMQ_INDEX_HASH_GROWTH_FACTOR 200

typedef void (amq_index_hash_callback_fn) (amq_index_t *item, void *argument);

//  Structure of the amq_index_hash object

struct _amq_index_hash_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_INDEX_HASH)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_INDEX_HASH_HISTORY_LENGTH];
    int
        history_line  [AMQ_INDEX_HASH_HISTORY_LENGTH];
    char
        *history_type [AMQ_INDEX_HASH_HISTORY_LENGTH];
    int
        history_links [AMQ_INDEX_HASH_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
size_t
    nbr_items;
size_t
    max_items;
amq_index_t
    **hash_items;
};

#   ifdef __cplusplus
}
#   endif
#   include "amq_index.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_index_hash_new()            amq_index_hash_new_ (__FILE__, __LINE__)
amq_index_hash_t *
    amq_index_hash_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_index_hash_selftest (
void);

int
    amq_index_hash_insert (
amq_index_hash_t * self,                //  Reference to object
char * key,                             //  Hash key
amq_index_t * item                      //  Item to insert
);

int
    amq_index_hash_remove (
amq_index_t * item                      //  Item to remove
);

amq_index_t *
    amq_index_hash_search (
amq_index_hash_t * self,                //  Table to search
char * key                              //  Hash key
);

void
    amq_index_hash_apply (
amq_index_hash_t * self,                //  Table to iterate
amq_index_hash_callback_fn * callback,   //  Not documented
void * argument                         //  Arbitrary argument pointer
);

void
    amq_index_hash_terminate (
void);

#define amq_index_hash_show(item,opcode,trace_file)  amq_index_hash_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_index_hash_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_index_hash_destroy(self)    amq_index_hash_destroy_ (self, __FILE__, __LINE__)
void
    amq_index_hash_destroy_ (
amq_index_hash_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define amq_index_hash_link(self)       amq_index_hash_link_ (self, __FILE__, __LINE__)
amq_index_hash_t *
    amq_index_hash_link_ (
amq_index_hash_t * self,                //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_index_hash_unlink(self)     amq_index_hash_unlink_ (self, __FILE__, __LINE__)
void
    amq_index_hash_unlink_ (
amq_index_hash_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_index_hash_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_index_hash_new_in_scope(self_p,_scope)  amq_index_hash_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_index_hash_new_in_scope_ (
amq_index_hash_t * * self_p,            //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_INDEX_HASH_ACTIVE
#   if defined (ICL_IMPORT_AMQ_INDEX_HASH_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_INDEX_HASH_INLINE)
#   define INCLUDE_AMQ_INDEX_HASH_INLINE
#   define INCLUDE_AMQ_INDEX_HASH_ACTIVE

#   include "amq_index.h"
#   include "icl_shortstr.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_INDEX_HASH_ACTIVE
#   if defined (ICL_IMPORT_AMQ_INDEX_HASH_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_INDEX_HASH_ROOT
#   endif
# endif
#endif
