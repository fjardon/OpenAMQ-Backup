/*---------------------------------------------------------------------------
    amq_consumer_by_queue.h - amq_consumer_by_queue component

    This class implements the list container for amq_consumer
    Generated from amq_consumer_by_queue.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_CONSUMER_BY_QUEUE_SAFE
#   define INCLUDE_AMQ_CONSUMER_BY_QUEUE_SAFE
#   define INCLUDE_AMQ_CONSUMER_BY_QUEUE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CONSUMER_BY_QUEUE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_consumer_by_queue_t amq_consumer_by_queue_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_QUEUE)
#    define AMQ_CONSUMER_BY_QUEUE_HISTORY_LENGTH 32
#endif

#define AMQ_CONSUMER_BY_QUEUE_ALIVE     0xFABB
#define AMQ_CONSUMER_BY_QUEUE_DEAD      0xDEAD

#define AMQ_CONSUMER_BY_QUEUE_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_consumer_by_queue\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_CONSUMER_BY_QUEUE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_consumer_by_queue at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CONSUMER_BY_QUEUE_ALIVE, self->object_tag);\
        amq_consumer_by_queue_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_consumer.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSUMER_BY_QUEUE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSUMER_BY_QUEUE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CONSUMER_BY_QUEUE_UNSAFE
#   define INCLUDE_AMQ_CONSUMER_BY_QUEUE_UNSAFE
#   define INCLUDE_AMQ_CONSUMER_BY_QUEUE_ACTIVE

#   include "amq_consumer.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_consumer_by_queue_animating;

//  Structure of the amq_consumer_by_queue object

struct _amq_consumer_by_queue_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSUMER_BY_QUEUE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_CONSUMER_BY_QUEUE_HISTORY_LENGTH];
    int
        history_line  [AMQ_CONSUMER_BY_QUEUE_HISTORY_LENGTH];
    char
        *history_type [AMQ_CONSUMER_BY_QUEUE_HISTORY_LENGTH];
    int
        history_links [AMQ_CONSUMER_BY_QUEUE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
amq_consumer_t
    amq_consumer;                   //  Self starts with child object
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
#define amq_consumer_by_queue_new()     amq_consumer_by_queue_new_ (__FILE__, __LINE__)
amq_consumer_by_queue_t *
    amq_consumer_by_queue_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_consumer_by_queue_selftest (
void);

int
    amq_consumer_by_queue_isempty (
amq_consumer_by_queue_t * self          //  Reference to object
);

int
    amq_consumer_by_queue_push (
amq_consumer_by_queue_t * self,         //  Reference to object
amq_consumer_t * item                   //  Not documented
);

amq_consumer_t *
    amq_consumer_by_queue_pop (
amq_consumer_by_queue_t * self          //  The list
);

int
    amq_consumer_by_queue_queue (
amq_consumer_by_queue_t * self,         //  Reference to object
amq_consumer_t * item                   //  Not documented
);

int
    amq_consumer_by_queue_relink_before (
amq_consumer_t * item,                  //  Not documented
amq_consumer_t * where                  //  Not documented
);

int
    amq_consumer_by_queue_remove (
amq_consumer_t * item                   //  Not documented
);

#define amq_consumer_by_queue_first(self)  amq_consumer_by_queue_first_ (self, __FILE__, __LINE__)
amq_consumer_t *
    amq_consumer_by_queue_first_ (
amq_consumer_by_queue_t * self,         //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_consumer_by_queue_last(self)  amq_consumer_by_queue_last_ (self, __FILE__, __LINE__)
amq_consumer_t *
    amq_consumer_by_queue_last_ (
amq_consumer_by_queue_t * self,         //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_consumer_by_queue_next(item)  amq_consumer_by_queue_next_ (item, __FILE__, __LINE__)
amq_consumer_t *
    amq_consumer_by_queue_next_ (
amq_consumer_t * ( * item_p ),          //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_consumer_by_queue_prev(item)  amq_consumer_by_queue_prev_ (item, __FILE__, __LINE__)
amq_consumer_t *
    amq_consumer_by_queue_prev_ (
amq_consumer_t * ( * item_p ),          //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

qbyte
    amq_consumer_by_queue_count (
amq_consumer_by_queue_t * self          //  The list
);

void
    amq_consumer_by_queue_terminate (
void);

#define amq_consumer_by_queue_show(item,opcode,trace_file)  amq_consumer_by_queue_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_consumer_by_queue_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_consumer_by_queue_destroy(self)  amq_consumer_by_queue_destroy_ (self, __FILE__, __LINE__)
void
    amq_consumer_by_queue_destroy_ (
amq_consumer_by_queue_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    amq_consumer_by_queue_read_lock (
amq_consumer_by_queue_t * self          //  Reference to object
);

int
    amq_consumer_by_queue_write_lock (
amq_consumer_by_queue_t * self          //  Reference to object
);

int
    amq_consumer_by_queue_unlock (
amq_consumer_by_queue_t * self          //  Reference to object
);

#define amq_consumer_by_queue_link(self)  amq_consumer_by_queue_link_ (self, __FILE__, __LINE__)
amq_consumer_by_queue_t *
    amq_consumer_by_queue_link_ (
amq_consumer_by_queue_t * self,         //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_consumer_by_queue_unlink(self)  amq_consumer_by_queue_unlink_ (self, __FILE__, __LINE__)
void
    amq_consumer_by_queue_unlink_ (
amq_consumer_by_queue_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_consumer_by_queue_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_consumer_by_queue_new_in_scope(self_p,_scope)  amq_consumer_by_queue_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_consumer_by_queue_new_in_scope_ (
amq_consumer_by_queue_t * * self_p,     //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSUMER_BY_QUEUE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSUMER_BY_QUEUE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CONSUMER_BY_QUEUE_INLINE)
#   define INCLUDE_AMQ_CONSUMER_BY_QUEUE_INLINE
#   define INCLUDE_AMQ_CONSUMER_BY_QUEUE_ACTIVE

#   include "amq_consumer.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_NEW)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_DESTROY)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_SELFTEST)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_ISEMPTY)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_PUSH)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_POP)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_QUEUE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_RELINK_BEFORE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_REMOVE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_FIRST)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_LAST)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_NEXT)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_PREV)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_COUNT)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_REHOOK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_UNHOOK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_SHOW)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_ALLOC)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_FREE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_READ_LOCK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_UNLOCK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_LINK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_UNLINK)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_ANIMATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BY_QUEUE_NEW_IN_SCOPE) )
void
    amq_consumer_by_queue_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSUMER_BY_QUEUE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSUMER_BY_QUEUE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CONSUMER_BY_QUEUE_ROOT
#   endif
# endif
#endif
