/*---------------------------------------------------------------------------
    amq_queue_by_vhost.h - amq_queue_by_vhost component

    This class implements the list container for amq_queue
    Generated from amq_queue_by_vhost.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_QUEUE_BY_VHOST_SAFE
#   define INCLUDE_AMQ_QUEUE_BY_VHOST_SAFE
#   define INCLUDE_AMQ_QUEUE_BY_VHOST_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_QUEUE_BY_VHOST_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_queue_by_vhost_t amq_queue_by_vhost_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BY_VHOST)
#    define AMQ_QUEUE_BY_VHOST_HISTORY_LENGTH 32
#endif

#define AMQ_QUEUE_BY_VHOST_ALIVE        0xFABB
#define AMQ_QUEUE_BY_VHOST_DEAD         0xDEAD

#define AMQ_QUEUE_BY_VHOST_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_queue_by_vhost\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_QUEUE_BY_VHOST_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_queue_by_vhost at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_QUEUE_BY_VHOST_ALIVE, self->object_tag);\
        amq_queue_by_vhost_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_queue.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_BY_VHOST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_BY_VHOST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_QUEUE_BY_VHOST_UNSAFE
#   define INCLUDE_AMQ_QUEUE_BY_VHOST_UNSAFE
#   define INCLUDE_AMQ_QUEUE_BY_VHOST_ACTIVE

#   include "amq_queue.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_queue_by_vhost_animating;

//  Structure of the amq_queue_by_vhost object

struct _amq_queue_by_vhost_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE_BY_VHOST)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_QUEUE_BY_VHOST_HISTORY_LENGTH];
    int
        history_line  [AMQ_QUEUE_BY_VHOST_HISTORY_LENGTH];
    char
        *history_type [AMQ_QUEUE_BY_VHOST_HISTORY_LENGTH];
    int
        history_links [AMQ_QUEUE_BY_VHOST_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
amq_queue_t
    amq_queue;                      //  Self starts with child object

};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_queue_by_vhost_new()        amq_queue_by_vhost_new_ (__FILE__, __LINE__)
amq_queue_by_vhost_t *
    amq_queue_by_vhost_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_queue_by_vhost_selftest (
void);

int
    amq_queue_by_vhost_isempty (
amq_queue_by_vhost_t * self             //  Reference to object
);

int
    amq_queue_by_vhost_push (
amq_queue_by_vhost_t * self,            //  Reference to object
amq_queue_t * item                      //  Not documented
);

amq_queue_t *
    amq_queue_by_vhost_pop (
amq_queue_by_vhost_t * self             //  The list
);

int
    amq_queue_by_vhost_queue (
amq_queue_by_vhost_t * self,            //  Reference to object
amq_queue_t * item                      //  Not documented
);

int
    amq_queue_by_vhost_relink_before (
amq_queue_t * item,                     //  Not documented
amq_queue_t * where                     //  Not documented
);

int
    amq_queue_by_vhost_remove (
amq_queue_t * item                      //  Not documented
);

#define amq_queue_by_vhost_first(self)  amq_queue_by_vhost_first_ (self, __FILE__, __LINE__)
amq_queue_t *
    amq_queue_by_vhost_first_ (
amq_queue_by_vhost_t * self,            //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_by_vhost_last(self)   amq_queue_by_vhost_last_ (self, __FILE__, __LINE__)
amq_queue_t *
    amq_queue_by_vhost_last_ (
amq_queue_by_vhost_t * self,            //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_by_vhost_next(item)   amq_queue_by_vhost_next_ (item, __FILE__, __LINE__)
amq_queue_t *
    amq_queue_by_vhost_next_ (
amq_queue_t * ( * item_p ),             //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_by_vhost_prev(item)   amq_queue_by_vhost_prev_ (item, __FILE__, __LINE__)
amq_queue_t *
    amq_queue_by_vhost_prev_ (
amq_queue_t * ( * item_p ),             //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_queue_by_vhost_terminate (
void);

#define amq_queue_by_vhost_show(item,opcode,trace_file)  amq_queue_by_vhost_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_queue_by_vhost_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_queue_by_vhost_destroy(self)  amq_queue_by_vhost_destroy_ (self, __FILE__, __LINE__)
void
    amq_queue_by_vhost_destroy_ (
amq_queue_by_vhost_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    amq_queue_by_vhost_read_lock (
amq_queue_by_vhost_t * self             //  Reference to object
);

int
    amq_queue_by_vhost_write_lock (
amq_queue_by_vhost_t * self             //  Reference to object
);

int
    amq_queue_by_vhost_unlock (
amq_queue_by_vhost_t * self             //  Reference to object
);

#define amq_queue_by_vhost_link(self)   amq_queue_by_vhost_link_ (self, __FILE__, __LINE__)
amq_queue_by_vhost_t *
    amq_queue_by_vhost_link_ (
amq_queue_by_vhost_t * self,            //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_queue_by_vhost_unlink(self)  amq_queue_by_vhost_unlink_ (self, __FILE__, __LINE__)
void
    amq_queue_by_vhost_unlink_ (
amq_queue_by_vhost_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_queue_by_vhost_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_queue_by_vhost_new_in_scope(self_p,_scope)  amq_queue_by_vhost_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_queue_by_vhost_new_in_scope_ (
amq_queue_by_vhost_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_BY_VHOST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_BY_VHOST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_QUEUE_BY_VHOST_INLINE)
#   define INCLUDE_AMQ_QUEUE_BY_VHOST_INLINE
#   define INCLUDE_AMQ_QUEUE_BY_VHOST_ACTIVE

#   include "amq_queue.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_NEW)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_DESTROY)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_SELFTEST)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_ISEMPTY)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_PUSH)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_POP)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_QUEUE)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_RELINK_BEFORE)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_REMOVE)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_FIRST)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_LAST)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_NEXT)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_PREV)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_REHOOK)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_UNHOOK)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_TERMINATE)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_SHOW)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_ALLOC)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_FREE)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_READ_LOCK)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_UNLOCK)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_LINK)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_UNLINK)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_ANIMATE)   || defined (BASE_TRACE_AMQ_QUEUE_BY_VHOST_NEW_IN_SCOPE) )
void
    amq_queue_by_vhost_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_BY_VHOST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_BY_VHOST_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_QUEUE_BY_VHOST_ROOT
#   endif
# endif
#endif
