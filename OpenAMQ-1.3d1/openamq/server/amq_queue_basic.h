/*---------------------------------------------------------------------------
    amq_queue_basic.h - amq_queue_basic component

This class implements the basic content queue manager. This class
runs lock-free as a child of the asynchronous queue class.
    Generated from amq_queue_basic.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_QUEUE_BASIC_SAFE
#   define INCLUDE_AMQ_QUEUE_BASIC_SAFE
#   define INCLUDE_AMQ_QUEUE_BASIC_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_QUEUE_BASIC_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_queue_basic_t amq_queue_basic_t;

#define AMQ_QUEUE_BASIC_ALIVE           0xFABB
#define AMQ_QUEUE_BASIC_DEAD            0xDEAD

#define AMQ_QUEUE_BASIC_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_queue_basic\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_QUEUE_BASIC_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_queue_basic at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_QUEUE_BASIC_ALIVE, self->object_tag);\
        amq_queue_basic_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_BASIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_BASIC_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_QUEUE_BASIC_UNSAFE
#   define INCLUDE_AMQ_QUEUE_BASIC_UNSAFE
#   define INCLUDE_AMQ_QUEUE_BASIC_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_queue_basic_animating;

//  Structure of the amq_queue_basic object

struct _amq_queue_basic_t {
dbyte
    object_tag;                     //  Object validity marker
amq_queue_t
    *queue;                         //  Parent queue
amq_consumer_by_queue_t
    *consumer_list;                 //  List of consumers from the queue
ipr_looseref_list_t
    *content_list;                  //  List of message contents

//  Statistics
size_t
    accept_count,                   //  Number of messages accepted
    dispatch_count;                 //  Number of messages dispatched
int64_t
    delivery_tag;                   //  Message delivery tag
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_queue_basic_new(queue)      amq_queue_basic_new_ (__FILE__, __LINE__, queue)
amq_queue_basic_t *
    amq_queue_basic_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_queue_t * queue                     //  Parent queue
);

int
    amq_queue_basic_stop (
amq_queue_basic_t * self                //  Reference to object
);

int
    amq_queue_basic_consume (
amq_queue_basic_t * self,               //  Reference to object
amq_consumer_t * consumer               //  Consumer reference
);

int
    amq_queue_basic_cancel (
amq_queue_basic_t * self,               //  Reference to object
amq_consumer_t * consumer               //  Consumer reference
);

int
    amq_queue_basic_consumer_ack (
amq_queue_basic_t * self,               //  Reference to object
amq_consumer_t * consumer               //  Consumer to ack
);

int
    amq_queue_basic_publish (
amq_queue_basic_t * self,               //  Reference to object
amq_server_channel_t * channel,         //  Channel for reply
amq_content_basic_t * content,          //  Message content
Bool immediate                          //  Warn if no consumers?
);

int
    amq_queue_basic_dispatch (
amq_queue_basic_t * self                //  Reference to object
);

int
    amq_queue_basic_get (
amq_queue_basic_t * self,               //  Reference to object
amq_server_channel_t * channel          //  Not documented
);

int
    amq_queue_basic_purge (
amq_queue_basic_t * self                //  Reference to object
);

int
    amq_queue_basic_consumer_count (
amq_queue_basic_t * self                //  Reference to object
);

int
    amq_queue_basic_message_count (
amq_queue_basic_t * self                //  Reference to object
);

void
    amq_queue_basic_selftest (
void);

void
    amq_queue_basic_terminate (
void);

#define amq_queue_basic_show(item,opcode,trace_file)  amq_queue_basic_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_queue_basic_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_queue_basic_destroy(self)   amq_queue_basic_destroy_ (self, __FILE__, __LINE__)
void
    amq_queue_basic_destroy_ (
amq_queue_basic_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_queue_basic_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_queue_basic_new_in_scope(self_p,_scope,queue)  amq_queue_basic_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, queue)
void
    amq_queue_basic_new_in_scope_ (
amq_queue_basic_t * * self_p,           //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_queue_t * queue                     //  Parent queue
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_BASIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_BASIC_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_QUEUE_BASIC_INLINE)
#   define INCLUDE_AMQ_QUEUE_BASIC_INLINE
#   define INCLUDE_AMQ_QUEUE_BASIC_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_NEW)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_DESTROY)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_FREE)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_STOP)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_CONSUME)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_CANCEL)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_CONSUMER_ACK)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_PUBLISH)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_DISPATCH)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_GET)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_PURGE)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_CONSUMER_COUNT)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_MESSAGE_COUNT)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_SELFTEST)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_TERMINATE)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_SHOW)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_ALLOC)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_ANIMATE)   || defined (BASE_TRACE_AMQ_QUEUE_BASIC_NEW_IN_SCOPE) )
void
    amq_queue_basic_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_QUEUE_BASIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_QUEUE_BASIC_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_QUEUE_BASIC_ROOT
#   endif
# endif
#endif
