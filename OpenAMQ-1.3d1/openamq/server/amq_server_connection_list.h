/*---------------------------------------------------------------------------
    amq_server_connection_list.h - amq_server_connection_list component

    This class implements the list container for amq_server_connection
    Generated from amq_server_connection_list.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_SERVER_CONNECTION_LIST_SAFE
#   define INCLUDE_AMQ_SERVER_CONNECTION_LIST_SAFE
#   define INCLUDE_AMQ_SERVER_CONNECTION_LIST_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_SERVER_CONNECTION_LIST_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_server_connection_list_t amq_server_connection_list_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION_LIST)
#    define AMQ_SERVER_CONNECTION_LIST_HISTORY_LENGTH 32
#endif

#define AMQ_SERVER_CONNECTION_LIST_ALIVE  0xFABB
#define AMQ_SERVER_CONNECTION_LIST_DEAD  0xDEAD

#define AMQ_SERVER_CONNECTION_LIST_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_server_connection_list\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_SERVER_CONNECTION_LIST_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_server_connection_list at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_SERVER_CONNECTION_LIST_ALIVE, self->object_tag);\
        amq_server_connection_list_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_connection.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CONNECTION_LIST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CONNECTION_LIST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_SERVER_CONNECTION_LIST_UNSAFE
#   define INCLUDE_AMQ_SERVER_CONNECTION_LIST_UNSAFE
#   define INCLUDE_AMQ_SERVER_CONNECTION_LIST_ACTIVE

#   include "amq_server_connection.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_server_connection_list_animating;

//  Structure of the amq_server_connection_list object

struct _amq_server_connection_list_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION_LIST)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_SERVER_CONNECTION_LIST_HISTORY_LENGTH];
    int
        history_line  [AMQ_SERVER_CONNECTION_LIST_HISTORY_LENGTH];
    char
        *history_type [AMQ_SERVER_CONNECTION_LIST_HISTORY_LENGTH];
    int
        history_links [AMQ_SERVER_CONNECTION_LIST_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
amq_server_connection_t
    amq_server_connection;          //  Self starts with child object

};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_server_connection_list_new()  amq_server_connection_list_new_ (__FILE__, __LINE__)
amq_server_connection_list_t *
    amq_server_connection_list_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_server_connection_list_selftest (
void);

int
    amq_server_connection_list_isempty (
amq_server_connection_list_t * self     //  Reference to object
);

int
    amq_server_connection_list_push (
amq_server_connection_list_t * self,    //  Reference to object
amq_server_connection_t * item          //  Not documented
);

amq_server_connection_t *
    amq_server_connection_list_pop (
amq_server_connection_list_t * self     //  The list
);

int
    amq_server_connection_list_queue (
amq_server_connection_list_t * self,    //  Reference to object
amq_server_connection_t * item          //  Not documented
);

int
    amq_server_connection_list_relink_before (
amq_server_connection_t * item,         //  Not documented
amq_server_connection_t * where         //  Not documented
);

int
    amq_server_connection_list_remove (
amq_server_connection_t * item          //  Not documented
);

#define amq_server_connection_list_first(self)  amq_server_connection_list_first_ (self, __FILE__, __LINE__)
amq_server_connection_t *
    amq_server_connection_list_first_ (
amq_server_connection_list_t * self,    //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_server_connection_list_last(self)  amq_server_connection_list_last_ (self, __FILE__, __LINE__)
amq_server_connection_t *
    amq_server_connection_list_last_ (
amq_server_connection_list_t * self,    //  The list
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_server_connection_list_next(item)  amq_server_connection_list_next_ (item, __FILE__, __LINE__)
amq_server_connection_t *
    amq_server_connection_list_next_ (
amq_server_connection_t * ( * item_p ),   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_server_connection_list_prev(item)  amq_server_connection_list_prev_ (item, __FILE__, __LINE__)
amq_server_connection_t *
    amq_server_connection_list_prev_ (
amq_server_connection_t * ( * item_p ),   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_server_connection_list_terminate (
void);

#define amq_server_connection_list_show(item,opcode,trace_file)  amq_server_connection_list_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_server_connection_list_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_server_connection_list_destroy(self)  amq_server_connection_list_destroy_ (self, __FILE__, __LINE__)
void
    amq_server_connection_list_destroy_ (
amq_server_connection_list_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    amq_server_connection_list_read_lock (
amq_server_connection_list_t * self     //  Reference to object
);

int
    amq_server_connection_list_write_lock (
amq_server_connection_list_t * self     //  Reference to object
);

int
    amq_server_connection_list_unlock (
amq_server_connection_list_t * self     //  Reference to object
);

#define amq_server_connection_list_link(self)  amq_server_connection_list_link_ (self, __FILE__, __LINE__)
amq_server_connection_list_t *
    amq_server_connection_list_link_ (
amq_server_connection_list_t * self,    //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_server_connection_list_unlink(self)  amq_server_connection_list_unlink_ (self, __FILE__, __LINE__)
void
    amq_server_connection_list_unlink_ (
amq_server_connection_list_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_server_connection_list_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_server_connection_list_new_in_scope(self_p,_scope)  amq_server_connection_list_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_server_connection_list_new_in_scope_ (
amq_server_connection_list_t * * self_p,   //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CONNECTION_LIST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CONNECTION_LIST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_SERVER_CONNECTION_LIST_INLINE)
#   define INCLUDE_AMQ_SERVER_CONNECTION_LIST_INLINE
#   define INCLUDE_AMQ_SERVER_CONNECTION_LIST_ACTIVE

#   include "amq_server_connection.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_NEW)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_DESTROY)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_SELFTEST)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_ISEMPTY)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_PUSH)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_POP)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_QUEUE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_RELINK_BEFORE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_REMOVE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_FIRST)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_LAST)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_NEXT)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_PREV)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_REHOOK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_UNHOOK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_SHOW)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_ALLOC)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_FREE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_READ_LOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_UNLOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_LINK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_UNLINK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_ANIMATE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LIST_NEW_IN_SCOPE) )
void
    amq_server_connection_list_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CONNECTION_LIST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CONNECTION_LIST_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_SERVER_CONNECTION_LIST_ROOT
#   endif
# endif
#endif
