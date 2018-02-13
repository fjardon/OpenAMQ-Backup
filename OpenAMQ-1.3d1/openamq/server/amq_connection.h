/*---------------------------------------------------------------------------
    amq_connection.h - amq_connection component

This class acts as a management layer for the amq_server_connection
class.  Ideally, that would be an async class but for now, it implies
too large changes to the architecture.  At some future stage we will
merge these two classes into one.
    Generated from amq_connection.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_CONNECTION_SAFE
#   define INCLUDE_AMQ_CONNECTION_SAFE
#   define INCLUDE_AMQ_CONNECTION_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CONNECTION_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_connection_t amq_connection_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION)
#    define AMQ_CONNECTION_HISTORY_LENGTH 32
#endif

#define AMQ_CONNECTION_ALIVE            0xFABB
#define AMQ_CONNECTION_DEAD             0xDEAD

#define AMQ_CONNECTION_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_connection\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_CONNECTION_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_connection at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CONNECTION_ALIVE, self->object_tag);\
        amq_connection_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
extern qbyte
    gbl_amq_connection_count;
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "amq_connection_by_broker.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_connection_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONNECTION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONNECTION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CONNECTION_UNSAFE
#   define INCLUDE_AMQ_CONNECTION_UNSAFE
#   define INCLUDE_AMQ_CONNECTION_ACTIVE

#   include "amq_server_classes.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_connection_agent.h"
//  Global variables

extern Bool
    amq_connection_animating;

//  Structure of the amq_connection object

struct _amq_connection_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_CONNECTION_HISTORY_LENGTH];
    int
        history_line  [AMQ_CONNECTION_HISTORY_LENGTH];
    char
        *history_type [AMQ_CONNECTION_HISTORY_LENGTH];
    int
        history_links [AMQ_CONNECTION_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
volatile amq_connection_by_broker_t *by_broker_head;
volatile amq_connection_t *by_broker_prev;
volatile amq_connection_t *by_broker_next;
qbyte
    object_id;                      //  System-wide object id
amq_console_t
    *console;                       //  Reference to console
amq_server_connection_t
    *connection;                    //  Parent connection
amq_server_channel_t
    *channel;                       //  Parent channel
};

#   ifdef __cplusplus
}
#   endif
#   include "amq_connection_by_broker.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_connection_new(broker,channel)  amq_connection_new_ (__FILE__, __LINE__, broker, channel)
amq_connection_t *
    amq_connection_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_broker_t * broker,                  //  Parent broker
amq_server_channel_t * channel          //  Parent server channel
);

void
    amq_connection_selftest (
void);

qbyte
    amq_connection_count (
void);

int
    amq_connection_inspect_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request           //  The original request
);

int
    amq_connection_inspect (
amq_connection_t * self,                //  Reference to object
amq_content_basic_t * request           //  The original request
);

int
    amq_connection_modify_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_connection_modify (
amq_connection_t * self,                //  Reference to object
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_connection_method_shim (
void * self_v,                          //  Object cast as a void *
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_connection_method (
amq_connection_t * self,                //  Reference to object
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Argument fields
);

void
    amq_connection_unlink_shim (
void * object_p                         //  Reference pointer cast as a void *
);

void
    amq_connection_terminate (
void);

void
    amq_connection_remove_from_all_containers (
amq_connection_t * self                 //  The item
);

#define amq_connection_show(item,opcode,trace_file)  amq_connection_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_connection_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_connection_destroy(self)    amq_connection_destroy_ (self, __FILE__, __LINE__)
int
    amq_connection_destroy_ (
amq_connection_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_connection_unlink(self)     amq_connection_unlink_ (self, __FILE__, __LINE__)
void
    amq_connection_unlink_ (
amq_connection_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_connection_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_connection_free(self)       amq_connection_free_ (self, __FILE__, __LINE__)
void
    amq_connection_free_ (
amq_connection_t * self,                //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_connection_link(self)       amq_connection_link_ (self, __FILE__, __LINE__)
amq_connection_t *
    amq_connection_link_ (
amq_connection_t * self,                //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_connection_new_in_scope(self_p,_scope,broker,channel)  amq_connection_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, broker, channel)
void
    amq_connection_new_in_scope_ (
amq_connection_t * * self_p,            //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_broker_t * broker,                  //  Parent broker
amq_server_channel_t * channel          //  Parent server channel
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONNECTION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONNECTION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CONNECTION_INLINE)
#   define INCLUDE_AMQ_CONNECTION_INLINE
#   define INCLUDE_AMQ_CONNECTION_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_connection_by_broker.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONNECTION)   || defined (BASE_TRACE_AMQ_CONNECTION_NEW)   || defined (BASE_TRACE_AMQ_CONNECTION_DESTROY)   || defined (BASE_TRACE_AMQ_CONNECTION_SELFTEST)   || defined (BASE_TRACE_AMQ_CONNECTION_COUNT)   || defined (BASE_TRACE_AMQ_CONNECTION_INSPECT_SHIM)   || defined (BASE_TRACE_AMQ_CONNECTION_INSPECT)   || defined (BASE_TRACE_AMQ_CONNECTION_MODIFY_SHIM)   || defined (BASE_TRACE_AMQ_CONNECTION_MODIFY)   || defined (BASE_TRACE_AMQ_CONNECTION_METHOD_SHIM)   || defined (BASE_TRACE_AMQ_CONNECTION_METHOD)   || defined (BASE_TRACE_AMQ_CONNECTION_UNLINK_SHIM)   || defined (BASE_TRACE_AMQ_CONNECTION_INITIALISE)   || defined (BASE_TRACE_AMQ_CONNECTION_TERMINATE)   || defined (BASE_TRACE_AMQ_CONNECTION_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_CONNECTION_SHOW)   || defined (BASE_TRACE_AMQ_CONNECTION_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CONNECTION_UNLINK)   || defined (BASE_TRACE_AMQ_CONNECTION_ANIMATE)   || defined (BASE_TRACE_AMQ_CONNECTION_FREE)   || defined (BASE_TRACE_AMQ_CONNECTION_ALLOC)   || defined (BASE_TRACE_AMQ_CONNECTION_LINK)   || defined (BASE_TRACE_AMQ_CONNECTION_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CONNECTION_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CONNECTION_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONNECTION_NEW_IN_SCOPE) )
void
    amq_connection_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_connection_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONNECTION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONNECTION_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CONNECTION_ROOT
#   endif
# endif
#endif
