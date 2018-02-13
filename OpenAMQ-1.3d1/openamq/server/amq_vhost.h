/*---------------------------------------------------------------------------
    amq_vhost.h - amq_vhost component

Defines a virtual host. This is a lock-free asynchronous class.
    Generated from amq_vhost.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_VHOST_SAFE
#   define INCLUDE_AMQ_VHOST_SAFE
#   define INCLUDE_AMQ_VHOST_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_VHOST_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_vhost_t amq_vhost_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
#    define AMQ_VHOST_HISTORY_LENGTH 32
#endif

#define AMQ_VHOST_ALIVE                 0xFABB
#define AMQ_VHOST_DEAD                  0xDEAD

#define AMQ_VHOST_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_vhost\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_VHOST_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_vhost at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_VHOST_ALIVE, self->object_tag);\
        amq_vhost_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_vhost_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_VHOST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_VHOST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_VHOST_UNSAFE
#   define INCLUDE_AMQ_VHOST_UNSAFE
#   define INCLUDE_AMQ_VHOST_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_vhost_agent.h"
//  Global variables

extern Bool
    amq_vhost_animating;

//  Structure of the amq_vhost object

struct _amq_vhost_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_VHOST_HISTORY_LENGTH];
    int
        history_line  [AMQ_VHOST_HISTORY_LENGTH];
    char
        *history_type [AMQ_VHOST_HISTORY_LENGTH];
    int
        history_links [AMQ_VHOST_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
amq_broker_t
    *broker;                        //  Parent broker
icl_shortstr_t
    name;                           //  Virtual host name
amq_vhost_config_t
    *config;                        //  Virtual host configuration
amq_exchange_table_t
    *exchange_table;                //  Exchanges for vhost, hash table
amq_exchange_by_vhost_t
    *exchange_list;                 //  List of exchanges
amq_queue_table_t
    *queue_table;                   //  Queues for vhost, hash table
amq_queue_by_vhost_t
    *queue_list;                    //  Queues for dispatching
amq_exchange_t
    *default_exchange;              //  Default exchange
ipr_symbol_table_t
    *shared_queues;                 //  Cluster shared queues
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_vhost_new(broker,name)      amq_vhost_new_ (__FILE__, __LINE__, broker, name)
amq_vhost_t *
    amq_vhost_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_broker_t * broker,                  //  Parent broker
char * name                             //  Virtual host name
);

int
    amq_vhost_unbind_queue (
amq_vhost_t * self,                     //  Reference to object
amq_queue_t * queue                     //  The queue to unbind
);

void
    amq_vhost_selftest (
void);

#define amq_vhost_destroy(self)         amq_vhost_destroy_ (self, __FILE__, __LINE__)
int
    amq_vhost_destroy_ (
amq_vhost_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_vhost_unlink(self)          amq_vhost_unlink_ (self, __FILE__, __LINE__)
void
    amq_vhost_unlink_ (
amq_vhost_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_vhost_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_vhost_free(self)            amq_vhost_free_ (self, __FILE__, __LINE__)
void
    amq_vhost_free_ (
amq_vhost_t * self,                     //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    amq_vhost_terminate (
void);

#define amq_vhost_show(item,opcode,trace_file)  amq_vhost_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_vhost_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_vhost_link(self)            amq_vhost_link_ (self, __FILE__, __LINE__)
amq_vhost_t *
    amq_vhost_link_ (
amq_vhost_t * self,                     //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_vhost_new_in_scope(self_p,_scope,broker,name)  amq_vhost_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, broker, name)
void
    amq_vhost_new_in_scope_ (
amq_vhost_t * * self_p,                 //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_broker_t * broker,                  //  Parent broker
char * name                             //  Virtual host name
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_VHOST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_VHOST_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_VHOST_INLINE)
#   define INCLUDE_AMQ_VHOST_INLINE
#   define INCLUDE_AMQ_VHOST_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_NEW)   || defined (BASE_TRACE_AMQ_VHOST_DESTROY)   || defined (BASE_TRACE_AMQ_VHOST_UNBIND_QUEUE)   || defined (BASE_TRACE_AMQ_VHOST_SELFTEST)   || defined (BASE_TRACE_AMQ_VHOST_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_VHOST_UNLINK)   || defined (BASE_TRACE_AMQ_VHOST_ANIMATE)   || defined (BASE_TRACE_AMQ_VHOST_FREE)   || defined (BASE_TRACE_AMQ_VHOST_INITIALISE)   || defined (BASE_TRACE_AMQ_VHOST_TERMINATE)   || defined (BASE_TRACE_AMQ_VHOST_SHOW)   || defined (BASE_TRACE_AMQ_VHOST_ALLOC)   || defined (BASE_TRACE_AMQ_VHOST_LINK)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_VHOST_NEW_IN_SCOPE) )
void
    amq_vhost_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_vhost_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_VHOST_ACTIVE
#   if defined (ICL_IMPORT_AMQ_VHOST_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_VHOST_ROOT
#   endif
# endif
#endif
