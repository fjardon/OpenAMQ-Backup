/*---------------------------------------------------------------------------
    amq_exchange_topic.h - amq_exchange_topic component

This class implements the topic exchange, which routes messages
based on the routing_key matched against a wild-card topic tree
specification.  Max. topics per exchange is limited by size of
amq_index_hash table.
    Generated from amq_exchange_topic.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_EXCHANGE_TOPIC_SAFE
#   define INCLUDE_AMQ_EXCHANGE_TOPIC_SAFE
#   define INCLUDE_AMQ_EXCHANGE_TOPIC_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_EXCHANGE_TOPIC_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_exchange_topic_t amq_exchange_topic_t;

#define AMQ_EXCHANGE_TOPIC_ALIVE        0xFABB
#define AMQ_EXCHANGE_TOPIC_DEAD         0xDEAD

#define AMQ_EXCHANGE_TOPIC_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_exchange_topic\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_EXCHANGE_TOPIC_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_exchange_topic at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_EXCHANGE_TOPIC_ALIVE, self->object_tag);\
        amq_exchange_topic_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_EXCHANGE_TOPIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_TOPIC_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_EXCHANGE_TOPIC_UNSAFE
#   define INCLUDE_AMQ_EXCHANGE_TOPIC_UNSAFE
#   define INCLUDE_AMQ_EXCHANGE_TOPIC_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_exchange_topic_animating;

//  Structure of the amq_exchange_topic object

struct _amq_exchange_topic_t {
dbyte
    object_tag;                     //  Object validity marker
amq_exchange_t
    *exchange;                      //  Parent exchange
amq_index_hash_t
    *index_hash;                    //  Access by text key
amq_index_array_t
    *index_array;                   //  Access by number 0..n-1
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_exchange_topic_new(exchange)  amq_exchange_topic_new_ (__FILE__, __LINE__, exchange)
amq_exchange_topic_t *
    amq_exchange_topic_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_exchange_t * exchange               //  Parent exchange
);

int
    amq_exchange_topic_compile (
void * self_v,                          //  The exchange cast as a void *
amq_binding_t * binding,                //  Binding to compile
amq_server_channel_t * channel          //  Channel for errors
);

int
    amq_exchange_topic_publish (
void * self_v,                          //  The exchange cast as a void *
amq_server_channel_t * channel,         //  Channel for reply
amq_content_basic_t * content,          //  Content to publish
int group,                              //  User group, from connection
Bool immediate                          //  Send immediately or return?
);

int
    amq_exchange_topic_unbind (
void * self_v,                          //  The exchange cast as a void *
amq_binding_t * binding                 //  Binding to unbind
);

void
    amq_exchange_topic_selftest (
void);

void
    amq_exchange_topic_terminate (
void);

#define amq_exchange_topic_show(item,opcode,trace_file)  amq_exchange_topic_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_exchange_topic_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_exchange_topic_destroy(self)  amq_exchange_topic_destroy_ (self, __FILE__, __LINE__)
void
    amq_exchange_topic_destroy_ (
amq_exchange_topic_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_exchange_topic_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_exchange_topic_new_in_scope(self_p,_scope,exchange)  amq_exchange_topic_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, exchange)
void
    amq_exchange_topic_new_in_scope_ (
amq_exchange_topic_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_exchange_t * exchange               //  Parent exchange
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_EXCHANGE_TOPIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_TOPIC_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_EXCHANGE_TOPIC_INLINE)
#   define INCLUDE_AMQ_EXCHANGE_TOPIC_INLINE
#   define INCLUDE_AMQ_EXCHANGE_TOPIC_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_EXCHANGE_TOPIC_ACTIVE
#   if defined (ICL_IMPORT_AMQ_EXCHANGE_TOPIC_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_EXCHANGE_TOPIC_ROOT
#   endif
# endif
#endif
