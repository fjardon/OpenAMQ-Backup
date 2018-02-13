/*---------------------------------------------------------------------------
    amq_exchange_system.h - amq_exchange_system component

This class implements these system services (specified by the routing key):

  - amq.console - AMQ Console service
    Generated from amq_exchange_system.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_EXCHANGE_SYSTEM_SAFE
#   define INCLUDE_AMQ_EXCHANGE_SYSTEM_SAFE
#   define INCLUDE_AMQ_EXCHANGE_SYSTEM_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_EXCHANGE_SYSTEM_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_exchange_system_t amq_exchange_system_t;

#define AMQ_EXCHANGE_SYSTEM_ALIVE       0xFABB
#define AMQ_EXCHANGE_SYSTEM_DEAD        0xDEAD

#define AMQ_EXCHANGE_SYSTEM_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_exchange_system\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_EXCHANGE_SYSTEM_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_exchange_system at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_EXCHANGE_SYSTEM_ALIVE, self->object_tag);\
        amq_exchange_system_show (self, ICL_CALLBACK_DUMP, stderr);\
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
#   undef INCLUDE_AMQ_EXCHANGE_SYSTEM_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_SYSTEM_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_EXCHANGE_SYSTEM_UNSAFE
#   define INCLUDE_AMQ_EXCHANGE_SYSTEM_UNSAFE
#   define INCLUDE_AMQ_EXCHANGE_SYSTEM_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_exchange_system_animating;

//  Structure of the amq_exchange_system object

struct _amq_exchange_system_t {
dbyte
    object_tag;                     //  Object validity marker
amq_exchange_t
    *exchange;                      //  Parent exchange
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
int
    amq_exchange_system_compile (
void * self_v,                          //  The exchange cast as a void *
amq_binding_t * binding,                //  Binding to compile
amq_server_channel_t * channel          //  Channel for errors
);

int
    amq_exchange_system_publish (
void * self_v,                          //  The exchange cast as a void *
amq_server_channel_t * channel,         //  Channel for reply
amq_content_basic_t * content,          //  Content to publish
int group,                              //  User group, from connection
Bool immediate                          //  Send immediately or return?
);

#define amq_exchange_system_new(exchange)  amq_exchange_system_new_ (__FILE__, __LINE__, exchange)
amq_exchange_system_t *
    amq_exchange_system_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_exchange_t * exchange               //  Parent exchange
);

int
    amq_exchange_system_unbind (
void * self_v,                          //  The exchange cast as a void *
amq_binding_t * binding                 //  Binding to unbind
);

void
    amq_exchange_system_selftest (
void);

void
    amq_exchange_system_terminate (
void);

#define amq_exchange_system_show(item,opcode,trace_file)  amq_exchange_system_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_exchange_system_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_exchange_system_destroy(self)  amq_exchange_system_destroy_ (self, __FILE__, __LINE__)
void
    amq_exchange_system_destroy_ (
amq_exchange_system_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_exchange_system_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_exchange_system_new_in_scope(self_p,_scope,exchange)  amq_exchange_system_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, exchange)
void
    amq_exchange_system_new_in_scope_ (
amq_exchange_system_t * * self_p,       //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_exchange_t * exchange               //  Parent exchange
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_EXCHANGE_SYSTEM_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_SYSTEM_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_EXCHANGE_SYSTEM_INLINE)
#   define INCLUDE_AMQ_EXCHANGE_SYSTEM_INLINE
#   define INCLUDE_AMQ_EXCHANGE_SYSTEM_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_COMPILE)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_PUBLISH)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_NEW)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_UNBIND)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_SELFTEST)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_TERMINATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_SHOW)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_DESTROY)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_ALLOC)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_FREE)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_ANIMATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_SYSTEM_NEW_IN_SCOPE) )
void
    amq_exchange_system_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_EXCHANGE_SYSTEM_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_SYSTEM_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_EXCHANGE_SYSTEM_ROOT
#   endif
# endif
#endif
