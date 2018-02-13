/*---------------------------------------------------------------------------
    amq_consumer_basic.h - amq_consumer_basic component

This class implements a Basic consumer.  For now, an empty object.
    Generated from amq_consumer_basic.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_CONSUMER_BASIC_SAFE
#   define INCLUDE_AMQ_CONSUMER_BASIC_SAFE
#   define INCLUDE_AMQ_CONSUMER_BASIC_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CONSUMER_BASIC_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_consumer_basic_t amq_consumer_basic_t;

#define AMQ_CONSUMER_BASIC_ALIVE        0xFABB
#define AMQ_CONSUMER_BASIC_DEAD         0xDEAD

#define AMQ_CONSUMER_BASIC_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_consumer_basic\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_CONSUMER_BASIC_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_consumer_basic at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CONSUMER_BASIC_ALIVE, self->object_tag);\
        amq_consumer_basic_show (self, ICL_CALLBACK_DUMP, stderr);\
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
#   undef INCLUDE_AMQ_CONSUMER_BASIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSUMER_BASIC_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CONSUMER_BASIC_UNSAFE
#   define INCLUDE_AMQ_CONSUMER_BASIC_UNSAFE
#   define INCLUDE_AMQ_CONSUMER_BASIC_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_consumer_basic_animating;

//  Structure of the amq_consumer_basic object

struct _amq_consumer_basic_t {
dbyte
    object_tag;                     //  Object validity marker
amq_consumer_t
    *consumer;                      //  Parent consumer
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_consumer_basic_new(consumer)  amq_consumer_basic_new_ (__FILE__, __LINE__, consumer)
amq_consumer_basic_t *
    amq_consumer_basic_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_consumer_t * consumer               //  Parent consumer
);

void
    amq_consumer_basic_selftest (
void);

void
    amq_consumer_basic_terminate (
void);

#define amq_consumer_basic_show(item,opcode,trace_file)  amq_consumer_basic_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_consumer_basic_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_consumer_basic_destroy(self)  amq_consumer_basic_destroy_ (self, __FILE__, __LINE__)
void
    amq_consumer_basic_destroy_ (
amq_consumer_basic_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_consumer_basic_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_consumer_basic_new_in_scope(self_p,_scope,consumer)  amq_consumer_basic_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, consumer)
void
    amq_consumer_basic_new_in_scope_ (
amq_consumer_basic_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_consumer_t * consumer               //  Parent consumer
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSUMER_BASIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSUMER_BASIC_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CONSUMER_BASIC_INLINE)
#   define INCLUDE_AMQ_CONSUMER_BASIC_INLINE
#   define INCLUDE_AMQ_CONSUMER_BASIC_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_NEW)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_SELFTEST)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_SHOW)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_DESTROY)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_ALLOC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_FREE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_ANIMATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_NEW_IN_SCOPE) )
void
    amq_consumer_basic_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSUMER_BASIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSUMER_BASIC_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CONSUMER_BASIC_ROOT
#   endif
# endif
#endif
