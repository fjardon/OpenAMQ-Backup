/*---------------------------------------------------------------------------
    amq_binding_mgt.h - amq_binding_mgt component

This class shows one binding.
    Generated from amq_binding_mgt.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_BINDING_MGT_SAFE
#   define INCLUDE_AMQ_BINDING_MGT_SAFE
#   define INCLUDE_AMQ_BINDING_MGT_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_BINDING_MGT_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_binding_mgt_t amq_binding_mgt_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
#    define AMQ_BINDING_MGT_HISTORY_LENGTH 32
#endif

#define AMQ_BINDING_MGT_ALIVE           0xFABB
#define AMQ_BINDING_MGT_DEAD            0xDEAD

#define AMQ_BINDING_MGT_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_binding_mgt\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_BINDING_MGT_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_binding_mgt at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_BINDING_MGT_ALIVE, self->object_tag);\
        amq_binding_mgt_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
extern qbyte
    gbl_amq_binding_mgt_count;
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
#include "amq_binding_mgt_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_BINDING_MGT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_BINDING_MGT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_BINDING_MGT_UNSAFE
#   define INCLUDE_AMQ_BINDING_MGT_UNSAFE
#   define INCLUDE_AMQ_BINDING_MGT_ACTIVE

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
#include "amq_binding_mgt_agent.h"
//  Global variables

extern Bool
    amq_binding_mgt_animating;

//  Structure of the amq_binding_mgt object

struct _amq_binding_mgt_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_BINDING_MGT_HISTORY_LENGTH];
    int
        history_line  [AMQ_BINDING_MGT_HISTORY_LENGTH];
    char
        *history_type [AMQ_BINDING_MGT_HISTORY_LENGTH];
    int
        history_links [AMQ_BINDING_MGT_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
qbyte
    object_id;                      //  System-wide object id
amq_console_t
    *console;                       //  Reference to console
amq_exchange_t
    *exchange;                          //  Parent exchange for CML hierarchy
amq_binding_t
    *binding;                           //  Binding we refer to
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_binding_mgt_new(exchange,binding)  amq_binding_mgt_new_ (__FILE__, __LINE__, exchange, binding)
amq_binding_mgt_t *
    amq_binding_mgt_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_exchange_t * exchange,              //  Parent exchange
amq_binding_t * binding                 //  Parent binding
);

void
    amq_binding_mgt_selftest (
void);

qbyte
    amq_binding_mgt_count (
void);

int
    amq_binding_mgt_inspect_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request           //  The original request
);

int
    amq_binding_mgt_inspect (
amq_binding_mgt_t * self,               //  Reference to object
amq_content_basic_t * request           //  The original request
);

int
    amq_binding_mgt_modify_shim (
void * self_v,                          //  Object cast as a void *
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_binding_mgt_modify (
amq_binding_mgt_t * self,               //  Reference to object
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_binding_mgt_method_shim (
void * self_v,                          //  Object cast as a void *
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Fields to modify
);

int
    amq_binding_mgt_method (
amq_binding_mgt_t * self,               //  Reference to object
char * method_name,                     //  Method name
amq_content_basic_t * request,          //  The original request
asl_field_list_t * fields               //  Argument fields
);

void
    amq_binding_mgt_unlink_shim (
void * object_p                         //  Reference pointer cast as a void *
);

void
    amq_binding_mgt_terminate (
void);

#define amq_binding_mgt_destroy(self)   amq_binding_mgt_destroy_ (self, __FILE__, __LINE__)
int
    amq_binding_mgt_destroy_ (
amq_binding_mgt_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_binding_mgt_unlink(self)    amq_binding_mgt_unlink_ (self, __FILE__, __LINE__)
void
    amq_binding_mgt_unlink_ (
amq_binding_mgt_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_binding_mgt_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_binding_mgt_free(self)      amq_binding_mgt_free_ (self, __FILE__, __LINE__)
void
    amq_binding_mgt_free_ (
amq_binding_mgt_t * self,               //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_binding_mgt_show(item,opcode,trace_file)  amq_binding_mgt_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_binding_mgt_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_binding_mgt_link(self)      amq_binding_mgt_link_ (self, __FILE__, __LINE__)
amq_binding_mgt_t *
    amq_binding_mgt_link_ (
amq_binding_mgt_t * self,               //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_binding_mgt_new_in_scope(self_p,_scope,exchange,binding)  amq_binding_mgt_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, exchange, binding)
void
    amq_binding_mgt_new_in_scope_ (
amq_binding_mgt_t * * self_p,           //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_exchange_t * exchange,              //  Parent exchange
amq_binding_t * binding                 //  Parent binding
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_BINDING_MGT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_BINDING_MGT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_BINDING_MGT_INLINE)
#   define INCLUDE_AMQ_BINDING_MGT_INLINE
#   define INCLUDE_AMQ_BINDING_MGT_ACTIVE

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
#include "amq_binding_mgt_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_BINDING_MGT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_BINDING_MGT_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_BINDING_MGT_ROOT
#   endif
# endif
#endif
