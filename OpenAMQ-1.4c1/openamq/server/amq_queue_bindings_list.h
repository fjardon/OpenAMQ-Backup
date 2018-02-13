/*---------------------------------------------------------------------------
    amq_queue_bindings_list.h - amq_queue_bindings_list component

    Generated from amq_queue_bindings_list.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_QUEUE_BINDINGS_LIST_SAFE
#   define INCLUDE_AMQ_QUEUE_BINDINGS_LIST_SAFE
#   define INCLUDE_AMQ_QUEUE_BINDINGS_LIST_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_QUEUE_BINDINGS_LIST_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_queue_bindings_list_t amq_queue_bindings_list_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
#    define AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH 32
#endif

#define AMQ_QUEUE_BINDINGS_LIST_ALIVE   0xFABB
#define AMQ_QUEUE_BINDINGS_LIST_DEAD    0xDEAD

#define AMQ_QUEUE_BINDINGS_LIST_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_queue_bindings_list\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_QUEUE_BINDINGS_LIST_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_queue_bindings_list at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_QUEUE_BINDINGS_LIST_ALIVE, self->object_tag);\
        amq_queue_bindings_list_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_binding.h"
#   include "amq_queue_bindings_list_table.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_BINDINGS_LIST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_BINDINGS_LIST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_QUEUE_BINDINGS_LIST_UNSAFE
#   define INCLUDE_AMQ_QUEUE_BINDINGS_LIST_UNSAFE
#   define INCLUDE_AMQ_QUEUE_BINDINGS_LIST_ACTIVE

#   include "amq_binding.h"
#   include "amq_queue_bindings_list_table.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_queue_bindings_list_animating;
//  The iterator type

typedef struct _amq_queue_bindings_list_iter_t amq_queue_bindings_list_iter_t;

struct _amq_queue_bindings_list_iter_t {
    volatile amq_queue_bindings_list_t *head;
    volatile amq_queue_bindings_list_iter_t *prev;
    volatile amq_queue_bindings_list_iter_t *next;
    amq_binding_t *item;
};

//  Structure of the amq_queue_bindings_list object

struct _amq_queue_bindings_list_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BINDINGS_LIST)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH];
    int
        history_line  [AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH];
    char
        *history_type [AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH];
    int
        history_links [AMQ_QUEUE_BINDINGS_LIST_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
amq_queue_bindings_list_iter_t
    amq_queue_bindings_list_iter;       //  Self starts with child object
volatile qbyte
    count;

amq_queue_bindings_list_table_t
    *table_head;                    //  Hash table container
amq_queue_bindings_list_t
    *table_next;                    //  Next item in the hash slot
qbyte
    table_index;                    //  Index of item in table
icl_shortstr_t
    key;                            //  Item's original key
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
void
    amq_queue_bindings_list_selftest (
void);

#define amq_queue_bindings_list_new(table,key)  amq_queue_bindings_list_new_ (__FILE__, __LINE__, table, key)
amq_queue_bindings_list_t *
    amq_queue_bindings_list_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_queue_bindings_list_table_t * table,   //  Table to insert into
char * key                              //  Hash key
);

void
    amq_queue_bindings_list_remove_from_all_containers (
amq_queue_bindings_list_t * self        //  The item
);

#define amq_queue_bindings_list_show(item,opcode,trace_file)  amq_queue_bindings_list_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_queue_bindings_list_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_iter_new (
amq_binding_t * item                    //  Not documented
);

amq_binding_t *
    amq_queue_bindings_list_iter_object (
amq_queue_bindings_list_iter_t * iter   //  Not documented
);

void
    amq_queue_bindings_list_iter_destroy (
amq_queue_bindings_list_iter_t * ( * iter_p )  //  Not documented
);

int
    amq_queue_bindings_list_isempty (
amq_queue_bindings_list_t * self        //  Reference to object
);

int
    amq_queue_bindings_list_push (
amq_queue_bindings_list_t * self,       //  Reference to object
amq_binding_t * item                    //  Not documented
);

amq_binding_t *
    amq_queue_bindings_list_pop (
amq_queue_bindings_list_t * self        //  The list
);

int
    amq_queue_bindings_list_queue (
amq_queue_bindings_list_t * self,       //  Reference to object
amq_binding_t * item                    //  Not documented
);

int
    amq_queue_bindings_list_relink_before (
amq_queue_bindings_list_iter_t * item,   //  Not documented
amq_queue_bindings_list_iter_t * where  //  Not documented
);

int
    amq_queue_bindings_list_remove (
amq_queue_bindings_list_iter_t * item   //  Not documented
);

#define amq_queue_bindings_list_first(self)  amq_queue_bindings_list_first_ (self, __FILE__, __LINE__)
amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_first_ (
amq_queue_bindings_list_t * self,       //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_bindings_list_last(self)  amq_queue_bindings_list_last_ (self, __FILE__, __LINE__)
amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_last_ (
amq_queue_bindings_list_t * self,       //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_bindings_list_next(item)  amq_queue_bindings_list_next_ (item, __FILE__, __LINE__)
amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_next_ (
amq_queue_bindings_list_iter_t * ( * item_p ),   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_bindings_list_prev(item)  amq_queue_bindings_list_prev_ (item, __FILE__, __LINE__)
amq_queue_bindings_list_iter_t *
    amq_queue_bindings_list_prev_ (
amq_queue_bindings_list_iter_t * ( * item_p ),   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

qbyte
    amq_queue_bindings_list_count (
amq_queue_bindings_list_t * self        //  The list
);

void
    amq_queue_bindings_list_terminate (
void);

#define amq_queue_bindings_list_destroy(self)  amq_queue_bindings_list_destroy_ (self, __FILE__, __LINE__)
void
    amq_queue_bindings_list_destroy_ (
amq_queue_bindings_list_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define amq_queue_bindings_list_link(self)  amq_queue_bindings_list_link_ (self, __FILE__, __LINE__)
amq_queue_bindings_list_t *
    amq_queue_bindings_list_link_ (
amq_queue_bindings_list_t * self,       //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_bindings_list_unlink(self)  amq_queue_bindings_list_unlink_ (self, __FILE__, __LINE__)
void
    amq_queue_bindings_list_unlink_ (
amq_queue_bindings_list_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_queue_bindings_list_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_queue_bindings_list_new_in_scope(self_p,_scope,table,key)  amq_queue_bindings_list_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, table, key)
void
    amq_queue_bindings_list_new_in_scope_ (
amq_queue_bindings_list_t * * self_p,   //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_queue_bindings_list_table_t * table,   //  Table to insert into
char * key                              //  Hash key
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_BINDINGS_LIST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_BINDINGS_LIST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_QUEUE_BINDINGS_LIST_INLINE)
#   define INCLUDE_AMQ_QUEUE_BINDINGS_LIST_INLINE
#   define INCLUDE_AMQ_QUEUE_BINDINGS_LIST_ACTIVE

#   include "amq_binding.h"
#   include "amq_queue_bindings_list_table.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_BINDINGS_LIST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_BINDINGS_LIST_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_QUEUE_BINDINGS_LIST_ROOT
#   endif
# endif
#endif
