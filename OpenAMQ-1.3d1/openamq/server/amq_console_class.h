/*---------------------------------------------------------------------------
    amq_console_class.h - amq_console_class component

This class defines a class descriptor.
    Generated from amq_console_class.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_CONSOLE_CLASS_SAFE
#   define INCLUDE_AMQ_CONSOLE_CLASS_SAFE
#   define INCLUDE_AMQ_CONSOLE_CLASS_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CONSOLE_CLASS_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_console_class_t amq_console_class_t;

#define AMQ_CONSOLE_CLASS_ALIVE         0xFABB
#define AMQ_CONSOLE_CLASS_DEAD          0xDEAD

#define AMQ_CONSOLE_CLASS_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_console_class\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_CONSOLE_CLASS_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_console_class at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CONSOLE_CLASS_ALIVE, self->object_tag);\
        amq_console_class_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#ifndef AMQ_CONSOLE_UNTYPED_UNLINK
#define AMQ_CONSOLE_UNTYPED_UNLINK
    typedef void (amq_console_unlink_fn) (void *object_p);
#endif
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
#   undef INCLUDE_AMQ_CONSOLE_CLASS_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSOLE_CLASS_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CONSOLE_CLASS_UNSAFE
#   define INCLUDE_AMQ_CONSOLE_CLASS_UNSAFE
#   define INCLUDE_AMQ_CONSOLE_CLASS_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_console_class_animating;

//  Structure of the amq_console_class object

struct _amq_console_class_t {
dbyte
    object_tag;                     //  Object validity marker
char
    *name;                          //  Name of class
int (*inspect) (
    void
        *self,                      //  Object reference
    amq_content_basic_t
        *request                    //  Original request
);
int (*modify) (
    void
        *self,                      //  Object reference
    amq_content_basic_t
        *request,                   //  Original request
    asl_field_list_t
        *fields                     //  Fields to modify
);
int (*method) (
    void
        *self,                      //  Object reference
    char
        *method_name,               //  Method to invoke
    amq_content_basic_t
        *request,                   //  Original request
    asl_field_list_t
        *fields                     //  Arguments to method
);
void (*unlink) (
    void *self
);
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
void
    amq_console_class_selftest (
void);

void
    amq_console_class_terminate (
void);

#define amq_console_class_new()         amq_console_class_new_ (__FILE__, __LINE__)
amq_console_class_t *
    amq_console_class_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_console_class_show(item,opcode,trace_file)  amq_console_class_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_console_class_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_console_class_destroy(self)  amq_console_class_destroy_ (self, __FILE__, __LINE__)
void
    amq_console_class_destroy_ (
amq_console_class_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_console_class_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_console_class_new_in_scope(self_p,_scope)  amq_console_class_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_console_class_new_in_scope_ (
amq_console_class_t * * self_p,         //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSOLE_CLASS_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSOLE_CLASS_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CONSOLE_CLASS_INLINE)
#   define INCLUDE_AMQ_CONSOLE_CLASS_INLINE
#   define INCLUDE_AMQ_CONSOLE_CLASS_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_SELFTEST)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_NEW)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_SHOW)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_DESTROY)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_ALLOC)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_FREE)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_ANIMATE)   || defined (BASE_TRACE_AMQ_CONSOLE_CLASS_NEW_IN_SCOPE) )
void
    amq_console_class_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CONSOLE_CLASS_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CONSOLE_CLASS_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CONSOLE_CLASS_ROOT
#   endif
# endif
#endif
