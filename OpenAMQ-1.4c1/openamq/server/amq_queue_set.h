/*---------------------------------------------------------------------------
    amq_queue_set.h - amq_queue_set component

    Generated from amq_queue_set.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_QUEUE_SET_SAFE
#   define INCLUDE_AMQ_QUEUE_SET_SAFE
#   define INCLUDE_AMQ_QUEUE_SET_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_QUEUE_SET_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_queue_set_t amq_queue_set_t;

#define AMQ_QUEUE_SET_ALIVE             0xFABB
#define AMQ_QUEUE_SET_DEAD              0xDEAD

#define AMQ_QUEUE_SET_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_queue_set\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_QUEUE_SET_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_queue_set at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_QUEUE_SET_ALIVE, self->object_tag);\
        amq_queue_set_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_queue.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_SET_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_SET_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_QUEUE_SET_UNSAFE
#   define INCLUDE_AMQ_QUEUE_SET_UNSAFE
#   define INCLUDE_AMQ_QUEUE_SET_ACTIVE

#   include "amq_queue.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_queue_set_animating;
//  The iterator type

typedef struct _amq_queue_set_iter_t amq_queue_set_iter_t;

struct _amq_queue_set_iter_t {
    volatile amq_queue_set_t *head;
    volatile amq_queue_set_iter_t *prev;
    volatile amq_queue_set_iter_t *next;
    amq_queue_t *item;
};

//  Structure of the amq_queue_set object

struct _amq_queue_set_t {
dbyte
    object_tag;                     //  Object validity marker
amq_queue_set_iter_t
    amq_queue_set_iter;                 //  Self starts with child object
volatile qbyte
    count;

};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
amq_queue_set_iter_t *
    amq_queue_set_find (
amq_queue_set_t * self,                 //  Reference to object
amq_queue_t * value                     //  Not documented
);

void
    amq_queue_set_selftest (
void);

amq_queue_set_iter_t *
    amq_queue_set_iter_new (
amq_queue_t * item                      //  Not documented
);

amq_queue_t *
    amq_queue_set_iter_object (
amq_queue_set_iter_t * iter             //  Not documented
);

void
    amq_queue_set_iter_destroy (
amq_queue_set_iter_t * ( * iter_p )     //  Not documented
);

#define amq_queue_set_new()             amq_queue_set_new_ (__FILE__, __LINE__)
amq_queue_set_t *
    amq_queue_set_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    amq_queue_set_isempty (
amq_queue_set_t * self                  //  Reference to object
);

int
    amq_queue_set_push (
amq_queue_set_t * self,                 //  Reference to object
amq_queue_t * item                      //  Not documented
);

amq_queue_t *
    amq_queue_set_pop (
amq_queue_set_t * self                  //  The list
);

int
    amq_queue_set_queue (
amq_queue_set_t * self,                 //  Reference to object
amq_queue_t * item                      //  Not documented
);

int
    amq_queue_set_relink_before (
amq_queue_set_iter_t * item,            //  Not documented
amq_queue_set_iter_t * where            //  Not documented
);

int
    amq_queue_set_remove (
amq_queue_set_iter_t * item             //  Not documented
);

#define amq_queue_set_first(self)       amq_queue_set_first_ (self, __FILE__, __LINE__)
amq_queue_set_iter_t *
    amq_queue_set_first_ (
amq_queue_set_t * self,                 //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_set_last(self)        amq_queue_set_last_ (self, __FILE__, __LINE__)
amq_queue_set_iter_t *
    amq_queue_set_last_ (
amq_queue_set_t * self,                 //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_set_next(item)        amq_queue_set_next_ (item, __FILE__, __LINE__)
amq_queue_set_iter_t *
    amq_queue_set_next_ (
amq_queue_set_iter_t * ( * item_p ),    //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_set_prev(item)        amq_queue_set_prev_ (item, __FILE__, __LINE__)
amq_queue_set_iter_t *
    amq_queue_set_prev_ (
amq_queue_set_iter_t * ( * item_p ),    //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

qbyte
    amq_queue_set_count (
amq_queue_set_t * self                  //  The list
);

void
    amq_queue_set_terminate (
void);

#define amq_queue_set_show(item,opcode,trace_file)  amq_queue_set_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_queue_set_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_queue_set_destroy(self)     amq_queue_set_destroy_ (self, __FILE__, __LINE__)
void
    amq_queue_set_destroy_ (
amq_queue_set_t * ( * self_p ),         //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_queue_set_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_queue_set_new_in_scope(self_p,_scope)  amq_queue_set_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_queue_set_new_in_scope_ (
amq_queue_set_t * * self_p,             //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_SET_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_SET_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_QUEUE_SET_INLINE)
#   define INCLUDE_AMQ_QUEUE_SET_INLINE
#   define INCLUDE_AMQ_QUEUE_SET_ACTIVE

#   include "amq_queue.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_SET_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_SET_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_QUEUE_SET_ROOT
#   endif
# endif
#endif
