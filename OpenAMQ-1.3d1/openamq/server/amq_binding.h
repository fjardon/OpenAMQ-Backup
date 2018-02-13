/*---------------------------------------------------------------------------
    amq_binding.h - amq_binding component

This class implements an exchange binding, which is a collection of
queues and other exchanges that share the same binding arguments.
This class runs lock-free as a child of the asynchronous exchange
class.
    Generated from amq_binding.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_BINDING_SAFE
#   define INCLUDE_AMQ_BINDING_SAFE
#   define INCLUDE_AMQ_BINDING_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_BINDING_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_binding_t amq_binding_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
#    define AMQ_BINDING_HISTORY_LENGTH 32
#endif

#define AMQ_BINDING_ALIVE               0xFABB
#define AMQ_BINDING_DEAD                0xDEAD

#define AMQ_BINDING_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_binding\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_BINDING_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_binding at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_BINDING_ALIVE, self->object_tag);\
        amq_binding_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "amq_binding_list.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_BINDING_ACTIVE
#   if defined (ICL_IMPORT_AMQ_BINDING_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_BINDING_UNSAFE
#   define INCLUDE_AMQ_BINDING_UNSAFE
#   define INCLUDE_AMQ_BINDING_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_binding_animating;

//  Structure of the amq_binding object

struct _amq_binding_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_BINDING_HISTORY_LENGTH];
    int
        history_line  [AMQ_BINDING_HISTORY_LENGTH];
    char
        *history_type [AMQ_BINDING_HISTORY_LENGTH];
    int
        history_links [AMQ_BINDING_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
volatile amq_binding_list_t *list_head;
volatile amq_binding_t *list_prev;
volatile amq_binding_t *list_next;
amq_exchange_t
    *exchange;                      //  Parent exchange
amq_queue_list_t
    *queue_list;                    //  List of queues for binding
amq_binding_mgt_t
    *binding_mgt;                   //  Interface to console
ipr_looseref_list_t
    *index_list;                    //  List of indices for binding
icl_shortstr_t
    routing_key;                    //  Binding routing key
icl_longstr_t
    *arguments;                     //  Additional binding arguments
icl_shortstr_t
    arguments_str;                  //  Arguments in string form
Bool
    is_wildcard,                    //  Matches multiple routing keys?
    exclusive;                      //  Has at least one exclusive queue
int
    index;                          //  Index in exchange->binding_index

//  Only used for topic exchange, might be moved elsewhere
icl_shortstr_t
    regexp;                         //  Binding routing key pattern

//  Only used for header exchange, might be moved elsewhere
int
    field_count;                    //  Number of fields indexed
Bool
    match_all;                      //  Match all fields?
};

#   ifdef __cplusplus
}
#   endif
#   include "amq_binding_list.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_binding_new(exchange,routing_key,arguments,exclusive)  amq_binding_new_ (__FILE__, __LINE__, exchange, routing_key, arguments, exclusive)
amq_binding_t *
    amq_binding_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_exchange_t * exchange,              //  Parent exchange
char * routing_key,                     //  Bind to routing key
icl_longstr_t * arguments,              //  Additional arguments
Bool exclusive                          //  Queue is exclusive?
);

int
    amq_binding_bind_queue (
amq_binding_t * self,                   //  Reference to object
amq_queue_t * queue                     //  Queue to bind
);

int
    amq_binding_unbind_queue (
amq_binding_t * self,                   //  Reference to object
amq_queue_t * queue                     //  Queue to unbind
);

int
    amq_binding_collect (
amq_binding_t * self,                   //  Reference to object
amq_queue_t ** queue_set,               //  Queue set
size_t set_size                         //  Queue set size
);

void
    amq_binding_selftest (
void);

qbyte
    amq_binding_count (
void);

void
    amq_binding_remove_from_all_containers (
amq_binding_t * self                    //  The item
);

#define amq_binding_show(item,opcode,trace_file)  amq_binding_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_binding_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    amq_binding_terminate (
void);

#define amq_binding_destroy(self)       amq_binding_destroy_ (self, __FILE__, __LINE__)
void
    amq_binding_destroy_ (
amq_binding_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define amq_binding_link(self)          amq_binding_link_ (self, __FILE__, __LINE__)
amq_binding_t *
    amq_binding_link_ (
amq_binding_t * self,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_binding_unlink(self)        amq_binding_unlink_ (self, __FILE__, __LINE__)
void
    amq_binding_unlink_ (
amq_binding_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_binding_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_binding_new_in_scope(self_p,_scope,exchange,routing_key,arguments,exclusive)  amq_binding_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, exchange, routing_key, arguments, exclusive)
void
    amq_binding_new_in_scope_ (
amq_binding_t * * self_p,               //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_exchange_t * exchange,              //  Parent exchange
char * routing_key,                     //  Bind to routing key
icl_longstr_t * arguments,              //  Additional arguments
Bool exclusive                          //  Queue is exclusive?
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_BINDING_ACTIVE
#   if defined (ICL_IMPORT_AMQ_BINDING_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_BINDING_INLINE)
#   define INCLUDE_AMQ_BINDING_INLINE
#   define INCLUDE_AMQ_BINDING_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_binding_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING)   || defined (BASE_TRACE_AMQ_BINDING_NEW)   || defined (BASE_TRACE_AMQ_BINDING_DESTROY)   || defined (BASE_TRACE_AMQ_BINDING_BIND_QUEUE)   || defined (BASE_TRACE_AMQ_BINDING_UNBIND_QUEUE)   || defined (BASE_TRACE_AMQ_BINDING_COLLECT)   || defined (BASE_TRACE_AMQ_BINDING_SELFTEST)   || defined (BASE_TRACE_AMQ_BINDING_COUNT)   || defined (BASE_TRACE_AMQ_BINDING_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_BINDING_SHOW)   || defined (BASE_TRACE_AMQ_BINDING_TERMINATE)   || defined (BASE_TRACE_AMQ_BINDING_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_BINDING_ALLOC)   || defined (BASE_TRACE_AMQ_BINDING_FREE)   || defined (BASE_TRACE_AMQ_BINDING_LINK)   || defined (BASE_TRACE_AMQ_BINDING_UNLINK)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_BINDING_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_BINDING_ANIMATE)   || defined (BASE_TRACE_AMQ_BINDING_NEW_IN_SCOPE) )
void
    amq_binding_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_BINDING_ACTIVE
#   if defined (ICL_IMPORT_AMQ_BINDING_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_BINDING_ROOT
#   endif
# endif
#endif
