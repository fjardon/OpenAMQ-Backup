/*---------------------------------------------------------------------------
    amq_mgt_binding.h - amq_mgt_binding component

Implements the management console binding object, used by applications
to manage OpenAMQ servers. Use in conjunction with the amq_mgt_console
class.
    Generated from amq_mgt_binding.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_MGT_BINDING_SAFE
#   define INCLUDE_AMQ_MGT_BINDING_SAFE
#   define INCLUDE_AMQ_MGT_BINDING_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_MGT_BINDING_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_mgt_binding_t amq_mgt_binding_t;

#define AMQ_MGT_BINDING_ALIVE           0xFABB
#define AMQ_MGT_BINDING_DEAD            0xDEAD

#define AMQ_MGT_BINDING_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_mgt_binding\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_MGT_BINDING_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_mgt_binding at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_MGT_BINDING_ALIVE, self->object_tag);\
        amq_mgt_binding_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_mgt_console.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_MGT_BINDING_ACTIVE
#   if defined (ICL_IMPORT_AMQ_MGT_BINDING_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_MGT_BINDING_UNSAFE
#   define INCLUDE_AMQ_MGT_BINDING_UNSAFE
#   define INCLUDE_AMQ_MGT_BINDING_ACTIVE

#   include "amq_mgt_console.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_mgt_binding_animating;

//  Structure of the amq_mgt_binding object

struct _amq_mgt_binding_t {
dbyte
    object_tag;                     //  Object validity marker
amq_client_session_t
    *session;                       //  AMQP session
int
    id;                             //  Object ID
icl_shortstr_t
    notice;                         //  Message from server
icl_shortstr_t
    name;                           //  Routing key
icl_shortstr_t
    arguments;                      //  Binding arguments
qbyte
    queues;                         //  Number of queues
Bool
    exclusive;                      //  Exclusive binding?
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_mgt_binding_new(session,id)  amq_mgt_binding_new_ (__FILE__, __LINE__, session, id)
amq_mgt_binding_t *
    amq_mgt_binding_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_client_session_t * session,         //  AMQP session
int id                                  //  Object ID
);

int
    amq_mgt_binding_load (
amq_mgt_binding_t * self                //  Reference to object
);

int
    amq_mgt_binding_print_children (
amq_mgt_binding_t * self,               //  Reference to object
FILE * xml_data                         //  XML data capture
);

int
    amq_mgt_binding_print_properties (
amq_mgt_binding_t * self,               //  Reference to object
FILE * xml_data                         //  XML data capture
);

int
    amq_mgt_binding_print_summary (
amq_mgt_binding_t * self,               //  Reference to object
FILE * xml_data                         //  XML data capture
);

int
    amq_mgt_binding_cmdline (
amq_mgt_binding_t * self,               //  Reference to object
char * path,                            //  Current path
int depth,                              //  Current depth
ipr_token_list_t * tokens,              //  Automation, if any
FILE * xml_data                         //  XML data capture
);

void
    amq_mgt_binding_selftest (
void);

void
    amq_mgt_binding_terminate (
void);

#define amq_mgt_binding_show(item,opcode,trace_file)  amq_mgt_binding_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_mgt_binding_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_mgt_binding_destroy(self)   amq_mgt_binding_destroy_ (self, __FILE__, __LINE__)
void
    amq_mgt_binding_destroy_ (
amq_mgt_binding_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_mgt_binding_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_mgt_binding_new_in_scope(self_p,_scope,session,id)  amq_mgt_binding_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, session, id)
void
    amq_mgt_binding_new_in_scope_ (
amq_mgt_binding_t * * self_p,           //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_client_session_t * session,         //  AMQP session
int id                                  //  Object ID
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_MGT_BINDING_ACTIVE
#   if defined (ICL_IMPORT_AMQ_MGT_BINDING_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_MGT_BINDING_INLINE)
#   define INCLUDE_AMQ_MGT_BINDING_INLINE
#   define INCLUDE_AMQ_MGT_BINDING_ACTIVE

#   include "amq_mgt_console.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_MGT_BINDING_ACTIVE
#   if defined (ICL_IMPORT_AMQ_MGT_BINDING_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_MGT_BINDING_ROOT
#   endif
# endif
#endif
