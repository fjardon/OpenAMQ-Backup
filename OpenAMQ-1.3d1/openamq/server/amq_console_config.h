/*---------------------------------------------------------------------------
    amq_console_config.h - amq_console_config component

    Generated from amq_console_config.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_CONSOLE_CONFIG_SAFE
#   define INCLUDE_AMQ_CONSOLE_CONFIG_SAFE
#   define INCLUDE_AMQ_CONSOLE_CONFIG_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CONSOLE_CONFIG_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_console_config_t amq_console_config_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE_CONFIG)
#    define AMQ_CONSOLE_CONFIG_HISTORY_LENGTH 32
#endif

#define AMQ_CONSOLE_CONFIG_ALIVE        0xFABB
#define AMQ_CONSOLE_CONFIG_DEAD         0xDEAD

#define AMQ_CONSOLE_CONFIG_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_console_config\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_CONSOLE_CONFIG_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_console_config at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CONSOLE_CONFIG_ALIVE, self->object_tag);\
        amq_console_config_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_console_config_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSOLE_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSOLE_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CONSOLE_CONFIG_UNSAFE
#   define INCLUDE_AMQ_CONSOLE_CONFIG_UNSAFE
#   define INCLUDE_AMQ_CONSOLE_CONFIG_ACTIVE

#   include "amq_server_classes.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_console_config_agent.h"
//  Global variables

extern Bool
    amq_console_config_animating;
extern amq_console_config_t
    *amq_console_config;                 //  Global properties object

//  Structure of the amq_console_config object

struct _amq_console_config_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE_CONFIG)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_CONSOLE_CONFIG_HISTORY_LENGTH];
    int
        history_line  [AMQ_CONSOLE_CONFIG_HISTORY_LENGTH];
    char
        *history_type [AMQ_CONSOLE_CONFIG_HISTORY_LENGTH];
    int
        history_links [AMQ_CONSOLE_CONFIG_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
qbyte
    object_id;                      //  System-wide object id
amq_console_t
    *console;                       //  Reference to console
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_console_config_new(broker)  amq_console_config_new_ (__FILE__, __LINE__, broker)
amq_console_config_t *
    amq_console_config_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_broker_t * broker                   //  Parent broker
);

void
    amq_console_config_selftest (
void);

int
    amq_console_config_inspect_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request           //  The original request
);

int
    amq_console_config_inspect (
amq_console_config_t * self,            //  Reference to object
amq_content_basic_t * request           //  The original request
);

int
    amq_console_config_modify_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_console_config_modify (
amq_console_config_t * self,            //  Reference to object
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_console_config_method_shim (
void * self_v,                          //  Object cast as a void *
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_console_config_method (
amq_console_config_t * self,            //  Reference to object
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Argument fields
);

void
    amq_console_config_unlink_shim (
void * object_p                         //  Reference pointer cast as a void *
);

void
    amq_console_config_terminate (
void);

#define amq_console_config_destroy(self)  amq_console_config_destroy_ (self, __FILE__, __LINE__)
int
    amq_console_config_destroy_ (
amq_console_config_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_console_config_unlink(self)  amq_console_config_unlink_ (self, __FILE__, __LINE__)
void
    amq_console_config_unlink_ (
amq_console_config_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_console_config_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_console_config_free(self)   amq_console_config_free_ (self, __FILE__, __LINE__)
void
    amq_console_config_free_ (
amq_console_config_t * self,            //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_console_config_show(item,opcode,trace_file)  amq_console_config_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_console_config_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_console_config_link(self)   amq_console_config_link_ (self, __FILE__, __LINE__)
amq_console_config_t *
    amq_console_config_link_ (
amq_console_config_t * self,            //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_console_config_new_in_scope(self_p,_scope,broker)  amq_console_config_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, broker)
void
    amq_console_config_new_in_scope_ (
amq_console_config_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_broker_t * broker                   //  Parent broker
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSOLE_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSOLE_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CONSOLE_CONFIG_INLINE)
#   define INCLUDE_AMQ_CONSOLE_CONFIG_INLINE
#   define INCLUDE_AMQ_CONSOLE_CONFIG_ACTIVE

#   include "amq_server_classes.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_NEW)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_SELFTEST)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_DESTROY)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_INSPECT_SHIM)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_INSPECT)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_MODIFY_SHIM)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_MODIFY)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_METHOD_SHIM)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_METHOD)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_UNLINK_SHIM)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_INITIALISE)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_UNLINK)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_ANIMATE)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_FREE)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_SHOW)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_ALLOC)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_LINK)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSOLE_CONFIG_NEW_IN_SCOPE) )
void
    amq_console_config_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_console_config_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSOLE_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSOLE_CONFIG_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CONSOLE_CONFIG_ROOT
#   endif
# endif
#endif
