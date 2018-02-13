/*---------------------------------------------------------------------------
    amq_connection_queue.h - amq_connection_queue component

This class shows the relationship from connection to queue, via the
consumer object.
    Generated from amq_connection_queue.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_CONNECTION_QUEUE_SAFE
#   define INCLUDE_AMQ_CONNECTION_QUEUE_SAFE
#   define INCLUDE_AMQ_CONNECTION_QUEUE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CONNECTION_QUEUE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_connection_queue_t amq_connection_queue_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
#    define AMQ_CONNECTION_QUEUE_HISTORY_LENGTH 32
#endif

#define AMQ_CONNECTION_QUEUE_ALIVE      0xFABB
#define AMQ_CONNECTION_QUEUE_DEAD       0xDEAD

#define AMQ_CONNECTION_QUEUE_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_connection_queue\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_CONNECTION_QUEUE_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_connection_queue at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CONNECTION_QUEUE_ALIVE, self->object_tag);\
        amq_connection_queue_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
extern qbyte
    gbl_amq_connection_queue_count;
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_connection_queue_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONNECTION_QUEUE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONNECTION_QUEUE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CONNECTION_QUEUE_UNSAFE
#   define INCLUDE_AMQ_CONNECTION_QUEUE_UNSAFE
#   define INCLUDE_AMQ_CONNECTION_QUEUE_ACTIVE

#   include "amq_server_classes.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_connection_queue_agent.h"
//  Global variables

extern Bool
    amq_connection_queue_animating;

//  Structure of the amq_connection_queue object

struct _amq_connection_queue_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_CONNECTION_QUEUE_HISTORY_LENGTH];
    int
        history_line  [AMQ_CONNECTION_QUEUE_HISTORY_LENGTH];
    char
        *history_type [AMQ_CONNECTION_QUEUE_HISTORY_LENGTH];
    int
        history_links [AMQ_CONNECTION_QUEUE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
qbyte
    object_id;                      //  System-wide object id
amq_console_t
    *console;                       //  Reference to console
amq_consumer_t
    *consumer;                          //  Consumer for this relationship
amq_queue_t
    *queue;                             //  Link to queue
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_connection_queue_new(connection,consumer)  amq_connection_queue_new_ (__FILE__, __LINE__, connection, consumer)
amq_connection_queue_t *
    amq_connection_queue_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_connection_t * connection,          //  Parent connection
amq_consumer_t * consumer               //  Consumer
);

void
    amq_connection_queue_selftest (
void);

qbyte
    amq_connection_queue_count (
void);

int
    amq_connection_queue_inspect_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request           //  The original request
);

int
    amq_connection_queue_inspect (
amq_connection_queue_t * self,          //  Reference to object
amq_content_basic_t * request           //  The original request
);

int
    amq_connection_queue_modify_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_connection_queue_modify (
amq_connection_queue_t * self,          //  Reference to object
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_connection_queue_method_shim (
void * self_v,                          //  Object cast as a void *
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_connection_queue_method (
amq_connection_queue_t * self,          //  Reference to object
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Argument fields
);

void
    amq_connection_queue_unlink_shim (
void * object_p                         //  Reference pointer cast as a void *
);

void
    amq_connection_queue_terminate (
void);

#define amq_connection_queue_destroy(self)  amq_connection_queue_destroy_ (self, __FILE__, __LINE__)
int
    amq_connection_queue_destroy_ (
amq_connection_queue_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_connection_queue_unlink(self)  amq_connection_queue_unlink_ (self, __FILE__, __LINE__)
void
    amq_connection_queue_unlink_ (
amq_connection_queue_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_connection_queue_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_connection_queue_free(self)  amq_connection_queue_free_ (self, __FILE__, __LINE__)
void
    amq_connection_queue_free_ (
amq_connection_queue_t * self,          //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_connection_queue_show(item,opcode,trace_file)  amq_connection_queue_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_connection_queue_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_connection_queue_link(self)  amq_connection_queue_link_ (self, __FILE__, __LINE__)
amq_connection_queue_t *
    amq_connection_queue_link_ (
amq_connection_queue_t * self,          //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_connection_queue_new_in_scope(self_p,_scope,connection,consumer)  amq_connection_queue_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, connection, consumer)
void
    amq_connection_queue_new_in_scope_ (
amq_connection_queue_t * * self_p,      //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_connection_t * connection,          //  Parent connection
amq_consumer_t * consumer               //  Consumer
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONNECTION_QUEUE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONNECTION_QUEUE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CONNECTION_QUEUE_INLINE)
#   define INCLUDE_AMQ_CONNECTION_QUEUE_INLINE
#   define INCLUDE_AMQ_CONNECTION_QUEUE_ACTIVE

#   include "amq_server_classes.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_connection_queue_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONNECTION_QUEUE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONNECTION_QUEUE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CONNECTION_QUEUE_ROOT
#   endif
# endif
#endif
