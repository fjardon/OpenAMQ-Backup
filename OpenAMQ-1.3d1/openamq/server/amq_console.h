/*---------------------------------------------------------------------------
    amq_console.h - amq_console component

This implements the AMQ Console object, which is a system-wide object
responsible for implementing the AMQ Console service.

The console works as follows:

 - AMQ Console is instantiated as a global object of this class, which
   has its own context.

 - All operable objects register with the console class, using a console
   class object as a holder for the methods the object class implements.

 - The amq.system exchange sends it messages using the publish method.
   For now, it is hard-coded in amq.system that any messages with the
   "amq.console" will get sent to amq_console.

 - The amq_console decodes the messages and routes it to an object (if
   found), via the amq_console_class definition for that object.

 - The operable objects implement a register, cancel, inspect, and modify
   methods, and return their replies to amq_console asynchrously via
   inspect_ok, modify_ok.

 - All interfaces between amq_console and operable classes is done using
   asl_field lists.
    Generated from amq_console.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_CONSOLE_SAFE
#   define INCLUDE_AMQ_CONSOLE_SAFE
#   define INCLUDE_AMQ_CONSOLE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CONSOLE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_console_t amq_console_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
#    define AMQ_CONSOLE_HISTORY_LENGTH 32
#endif

#define AMQ_CONSOLE_ALIVE               0xFABB
#define AMQ_CONSOLE_DEAD                0xDEAD

#define AMQ_CONSOLE_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_console\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_CONSOLE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_console at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CONSOLE_ALIVE, self->object_tag);\
        amq_console_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
extern amq_console_t
    *amq_console;                       //  Single system-wide console
extern qbyte
    amq_object_id;                      //  Global object ID
typedef struct _amq_console_entry_t amq_console_entry_t;
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
#include "amq_console_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSOLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSOLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CONSOLE_UNSAFE
#   define INCLUDE_AMQ_CONSOLE_UNSAFE
#   define INCLUDE_AMQ_CONSOLE_ACTIVE

#   include "amq_server_classes.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_console_agent.h"
//  Global variables

extern Bool
    amq_console_animating;
struct _amq_console_entry_t {
    amq_console_class_t
        *class_ref;                     //  Reference to object class
    void
        *object_ref;                    //  Reference to object
    ipr_hash_t
        *hash;                          //  Pointer back to own hash
};

//  Structure of the amq_console object

struct _amq_console_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_CONSOLE_HISTORY_LENGTH];
    int
        history_line  [AMQ_CONSOLE_HISTORY_LENGTH];
    char
        *history_type [AMQ_CONSOLE_HISTORY_LENGTH];
    int
        history_links [AMQ_CONSOLE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
ipr_hash_table_t
    *object_store;                  //  Object store is a hash table
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_console_new()               amq_console_new_ (__FILE__, __LINE__)
amq_console_t *
    amq_console_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    amq_console_register (
amq_console_t * self,                   //  Reference to object
qbyte object_id,                        //  Object id
void * object_ref,                      //  Object reference
amq_console_class_t * class_ref,        //  Not documented
qbyte parent_id                         //  Parent object id
);

int
    amq_console_cancel (
amq_console_t * self,                   //  Reference to object
qbyte object_id                         //  Object ID
);

int
    amq_console_accept (
amq_console_t * self,                   //  Reference to object
amq_content_basic_t * content,          //  The message content
int group                               //  User group
);

int
    amq_console_reply_ok (
amq_console_t * self,                   //  Reference to object
char * name,                            //  Reply name
amq_content_basic_t * request,          //  Original request
qbyte object_id,                        //  Object id
asl_field_list_t * fields,              //  Object fields
char * notice                           //  Reply notice, if any
);

int
    amq_console_reply_error (
amq_console_t * self,                   //  Reference to object
char * name,                            //  Reply name
char * status,                          //  Object id
amq_content_basic_t * request,          //  Original request
qbyte object_id                         //  Object id
);

void
    amq_console_selftest (
void);

#define amq_console_destroy(self)       amq_console_destroy_ (self, __FILE__, __LINE__)
int
    amq_console_destroy_ (
amq_console_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_console_unlink(self)        amq_console_unlink_ (self, __FILE__, __LINE__)
void
    amq_console_unlink_ (
amq_console_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_console_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_console_free(self)          amq_console_free_ (self, __FILE__, __LINE__)
void
    amq_console_free_ (
amq_console_t * self,                   //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    amq_console_terminate (
void);

#define amq_console_show(item,opcode,trace_file)  amq_console_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_console_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_console_link(self)          amq_console_link_ (self, __FILE__, __LINE__)
amq_console_t *
    amq_console_link_ (
amq_console_t * self,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_console_new_in_scope(self_p,_scope)  amq_console_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_console_new_in_scope_ (
amq_console_t * * self_p,               //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSOLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSOLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CONSOLE_INLINE)
#   define INCLUDE_AMQ_CONSOLE_INLINE
#   define INCLUDE_AMQ_CONSOLE_ACTIVE

#   include "amq_server_classes.h"
#   include "asl_field_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSOLE)   || defined (BASE_TRACE_AMQ_CONSOLE_NEW)   || defined (BASE_TRACE_AMQ_CONSOLE_DESTROY)   || defined (BASE_TRACE_AMQ_CONSOLE_REGISTER)   || defined (BASE_TRACE_AMQ_CONSOLE_CANCEL)   || defined (BASE_TRACE_AMQ_CONSOLE_ACCEPT)   || defined (BASE_TRACE_AMQ_CONSOLE_REPLY_OK)   || defined (BASE_TRACE_AMQ_CONSOLE_REPLY_ERROR)   || defined (BASE_TRACE_AMQ_CONSOLE_SELFTEST)   || defined (BASE_TRACE_AMQ_CONSOLE_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CONSOLE_UNLINK)   || defined (BASE_TRACE_AMQ_CONSOLE_ANIMATE)   || defined (BASE_TRACE_AMQ_CONSOLE_FREE)   || defined (BASE_TRACE_AMQ_CONSOLE_INITIALISE)   || defined (BASE_TRACE_AMQ_CONSOLE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSOLE_SHOW)   || defined (BASE_TRACE_AMQ_CONSOLE_ALLOC)   || defined (BASE_TRACE_AMQ_CONSOLE_LINK)   || defined (BASE_TRACE_AMQ_CONSOLE_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CONSOLE_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CONSOLE_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSOLE_NEW_IN_SCOPE) )
void
    amq_console_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_console_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSOLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSOLE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CONSOLE_ROOT
#   endif
# endif
#endif
