/*---------------------------------------------------------------------------
    amq_lease.h - amq_lease component

    Implements the Direct Protocol lease for the OpenAMQ server.
    Creates and resolves leases for sinks (exchanges) and feeds
    (queues).
    Generated from amq_lease.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_LEASE_SAFE
#   define INCLUDE_AMQ_LEASE_SAFE
#   define INCLUDE_AMQ_LEASE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_LEASE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_lease_t amq_lease_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
#    define AMQ_LEASE_HISTORY_LENGTH 32
#endif

#define AMQ_LEASE_ALIVE                 0xFABB
#define AMQ_LEASE_DEAD                  0xDEAD

#define AMQ_LEASE_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_lease\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_LEASE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_lease at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_LEASE_ALIVE, self->object_tag);\
        amq_lease_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "amq_lease_table.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_LEASE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_LEASE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_LEASE_UNSAFE
#   define INCLUDE_AMQ_LEASE_UNSAFE
#   define INCLUDE_AMQ_LEASE_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_lease_table.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_lease_animating;

//  Structure of the amq_lease object

struct _amq_lease_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_LEASE_HISTORY_LENGTH];
    int
        history_line  [AMQ_LEASE_HISTORY_LENGTH];
    char
        *history_type [AMQ_LEASE_HISTORY_LENGTH];
    int
        history_links [AMQ_LEASE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
amq_lease_table_t
    *table_head;                    //  Hash table container
amq_lease_t
    *table_next;                    //  Next item in the hash slot
qbyte
    table_index;                    //  Index of item in table
icl_shortstr_t
    key;                            //  Item's original key
amq_server_connection_t
    *connection;                    //  Parent connection
amq_server_channel_t
    *channel;                       //  Parent channel
smt_thread_t
    *thread;                        //  Connection thread, if lease used
icl_shortstr_t
    name;                           //  Field name
byte
    type;                           //  Field type
icl_shortstr_t
    connection_id;                  //  ID of main connection
amq_exchange_t
    *sink;                          //  Sink we are using
amq_queue_t
    *feed;                          //  Feed for the lease
volatile qbyte
    pending;                        //  Number of pending outgoing messages
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_lease_new(vhost,name,type,channel)  amq_lease_new_ (__FILE__, __LINE__, vhost, name, type, channel)
amq_lease_t *
    amq_lease_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_vhost_t * vhost,                    //  Parent vhost
char * name,                            //  Sink or feed name
int type,                               //  DP_SINK or DP_FEED
amq_server_channel_t * channel          //  Parent channel
);

amq_lease_t *
    amq_lease_search (
char * name                             //  Exchange name
);

int
    amq_lease_acquire (
amq_lease_t * self,                     //  Reference to object
smt_thread_t * thread,                  //  Not documented
smt_socket_t * socket                   //  Not documented
);

int
    amq_lease_sink (
amq_lease_t * self,                     //  Reference to object
amq_content_basic_t * content,          //  Not documented
byte options                            //  Publish options octet
);

void
    amq_lease_selftest (
void);

void
    amq_lease_remove_from_all_containers (
amq_lease_t * self                      //  The item
);

#define amq_lease_show(item,opcode,trace_file)  amq_lease_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_lease_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_lease_destroy(self)         amq_lease_destroy_ (self, __FILE__, __LINE__)
void
    amq_lease_destroy_ (
amq_lease_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define amq_lease_link(self)            amq_lease_link_ (self, __FILE__, __LINE__)
amq_lease_t *
    amq_lease_link_ (
amq_lease_t * self,                     //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_lease_unlink(self)          amq_lease_unlink_ (self, __FILE__, __LINE__)
void
    amq_lease_unlink_ (
amq_lease_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_lease_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_lease_new_in_scope(self_p,_scope,vhost,name,type,channel)  amq_lease_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, vhost, name, type, channel)
void
    amq_lease_new_in_scope_ (
amq_lease_t * * self_p,                 //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_vhost_t * vhost,                    //  Parent vhost
char * name,                            //  Sink or feed name
int type,                               //  DP_SINK or DP_FEED
amq_server_channel_t * channel          //  Parent channel
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_LEASE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_LEASE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_LEASE_INLINE)
#   define INCLUDE_AMQ_LEASE_INLINE
#   define INCLUDE_AMQ_LEASE_ACTIVE

#   include "amq_server_classes.h"
#   include "amq_lease_table.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_LEASE)   || defined (BASE_TRACE_AMQ_LEASE_NEW)   || defined (BASE_TRACE_AMQ_LEASE_DESTROY)   || defined (BASE_TRACE_AMQ_LEASE_SEARCH)   || defined (BASE_TRACE_AMQ_LEASE_ACQUIRE)   || defined (BASE_TRACE_AMQ_LEASE_SINK)   || defined (BASE_TRACE_AMQ_LEASE_INITIALISE)   || defined (BASE_TRACE_AMQ_LEASE_TERMINATE)   || defined (BASE_TRACE_AMQ_LEASE_SELFTEST)   || defined (BASE_TRACE_AMQ_LEASE_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_LEASE_SHOW)   || defined (BASE_TRACE_AMQ_LEASE_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_LEASE_ALLOC)   || defined (BASE_TRACE_AMQ_LEASE_FREE)   || defined (BASE_TRACE_AMQ_LEASE_LINK)   || defined (BASE_TRACE_AMQ_LEASE_UNLINK)   || defined (BASE_TRACE_AMQ_LEASE_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_LEASE_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_LEASE_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_LEASE_ANIMATE)   || defined (BASE_TRACE_AMQ_LEASE_NEW_IN_SCOPE) )
void
    amq_lease_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_LEASE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_LEASE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_LEASE_ROOT
#   endif
# endif
#endif
