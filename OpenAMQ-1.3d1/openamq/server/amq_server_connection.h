/*---------------------------------------------------------------------------
    amq_server_connection.h - amq_server_connection component

This class implements the connection class for the AMQ server.
    Generated from amq_server_connection.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_SERVER_CONNECTION_SAFE
#   define INCLUDE_AMQ_SERVER_CONNECTION_SAFE
#   define INCLUDE_AMQ_SERVER_CONNECTION_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_SERVER_CONNECTION_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_server_connection_t amq_server_connection_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
#    define AMQ_SERVER_CONNECTION_HISTORY_LENGTH 32
#endif

#define AMQ_SERVER_CONNECTION_ALIVE     0xFABB
#define AMQ_SERVER_CONNECTION_DEAD      0xDEAD

#define AMQ_SERVER_CONNECTION_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_server_connection\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_SERVER_CONNECTION_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_server_connection at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_SERVER_CONNECTION_ALIVE, self->object_tag);\
        amq_server_connection_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
//  These are the connection groups we allow
#define AMQ_CONNECTION_GROUP_NORMAL    1
#define AMQ_CONNECTION_GROUP_SUPER     2
#   ifdef __cplusplus
}
#   endif

#   include "amq_queue_list.h"
#   include "amq_server_connection_table.h"
#   include "amq_server_connection_list.h"
#   include "asl.h"
#   include "amq_server_channel.h"
#   include "amq_server_method.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CONNECTION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CONNECTION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_SERVER_CONNECTION_UNSAFE
#   define INCLUDE_AMQ_SERVER_CONNECTION_UNSAFE
#   define INCLUDE_AMQ_SERVER_CONNECTION_ACTIVE

#   include "amq_queue_list.h"
#   include "amq_server_connection_table.h"
#   include "asl.h"
#   include "amq_server_channel.h"
#   include "amq_server_method.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_server_connection_animating;

//  Structure of the amq_server_connection object

struct _amq_server_connection_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CONNECTION)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_SERVER_CONNECTION_HISTORY_LENGTH];
    int
        history_line  [AMQ_SERVER_CONNECTION_HISTORY_LENGTH];
    char
        *history_type [AMQ_SERVER_CONNECTION_HISTORY_LENGTH];
    int
        history_links [AMQ_SERVER_CONNECTION_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
amq_server_connection_table_t
    *table_head;                    //  Hash table container
amq_server_connection_t
    *table_next;                    //  Next item in the hash slot
qbyte
    table_index;                    //  Index of item in table
icl_shortstr_t
    key;                            //  Item's original key
volatile amq_server_connection_list_t *list_head;
volatile amq_server_connection_t *list_prev;
volatile amq_server_connection_t *list_next;
//  References to parent objects
smt_thread_t
    *thread;                        //  Parent thread

//  Object properties
apr_time_t
    started;                        //  Time started
icl_shortstr_t
    id;                             //  Connection identifier
amq_server_channel_table_t
    *channels;                      //  Active channels
dbyte
    channel_max,                    //  Negotiated channel limit
    heartbeat;                      //  Connection heartbeat
qbyte
    frame_max;                      //  Negotiated maximum frame size
Bool
    exception_raised;               //  Indicates exception raised
dbyte
    reply_code;                     //  Exception error code
icl_shortstr_t
    reply_text;                     //  Exception error text
dbyte
    faulting_method_id,             //  Class id of faulting method
    faulting_class_id;              //  Method id of faulting method
Bool
    nowarning,                      //  Suppress disconnect warnings
    exception,                      //  Indicates connection exception
    authorised;                     //  Connection authorised?
int
    trace;                          //  Last known trace value

icl_shortstr_t
    client_address;                 //  IP address:port of client
icl_shortstr_t
    client_product;                 //  Reported by client
icl_shortstr_t
    client_version;                 //  Client version
icl_shortstr_t  
    client_platform;                //  Client OS/language
icl_shortstr_t
    client_copyright;               //  Client copyright
icl_shortstr_t
    client_information;             //  Client information
icl_shortstr_t
    client_instance;                //  Client instance name

//  If the client connection comes from a server, it will also supply
//  us with information that lets make a call-back connection to it
icl_shortstr_t
    client_proxy_name;              //  Server name
icl_shortstr_t
    client_proxy_host;              //  Server address and port

//  Statistics
int64_t
    traffic_in,                     //  Traffic in, in octets
    traffic_out,                    //  Traffic out, in octets
    contents_in,                    //  Contents in, in octets
    contents_out;                   //  Contents out, in octets
amq_vhost_t
    *vhost;                         //  Parent virtual host
amq_queue_list_t
    *own_queue_list;                //  List of exclusive queues
amq_consumer_table_t
    *consumer_table;                //  Consumers for connection
qbyte
    consumer_tag;                   //  Last consumer tag
icl_shortstr_t
    user_name;                      //  User login name
int
    group;                          //  User connection group
};

#   ifdef __cplusplus
}
#   endif
#   include "amq_server_connection_list.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_server_connection_new(table,thread)  amq_server_connection_new_ (__FILE__, __LINE__, table, thread)
amq_server_connection_t *
    amq_server_connection_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_server_connection_table_t * table,   //  Table to insert into
smt_thread_t * thread                   //  Parent thread
);

int
    amq_server_connection_own_queue (
amq_server_connection_t * self,         //  Reference to object
amq_queue_t * queue                     //  Queue reference
);

int
    amq_server_connection_unbind_queue (
amq_server_connection_t * self,         //  Reference to object
amq_queue_t * queue                     //  The queue to unbind
);

int
    amq_server_connection_ready (
amq_server_connection_t * self          //  Reference to object
);

int
    amq_server_connection_start_ok (
amq_server_connection_t * self,         //  Reference to object
amq_server_connection_start_ok_t * method  //  Not documented
);

int
    amq_server_connection_open (
amq_server_connection_t * self,         //  Reference to object
amq_server_connection_open_t * method   //  Not documented
);

int
    amq_server_connection_set_address (
amq_server_connection_t * self,         //  Reference to object
char * address                          //  Client address
);

int
    amq_server_connection_set_trace (
amq_server_connection_t * self,         //  Reference to object
int trace                               //  Desired trace level
);

int
    amq_server_connection_kill (
amq_server_connection_t * self          //  Reference to object
);

int
    amq_server_connection_raise_exception (
amq_server_connection_t * self,         //  Reference to object
dbyte reply_code,                       //  Error code
char * reply_text,                      //  Error text
dbyte faulting_method_id,               //  Faulting method id
dbyte faulting_class_id                 //  Faulting class id
);

int
    amq_server_connection_error (
amq_server_connection_t * self,         //  Reference to object
dbyte reply_code,                       //  Error code
char * reply_text,                      //  Error text
dbyte faulting_method_id,               //  Faulting method id
dbyte faulting_class_id                 //  Faulting class id
);

int
    amq_server_connection_exception_raised (
amq_server_connection_t * self          //  Reference to object
);

int
    amq_server_connection_tune_ok (
amq_server_connection_t * self,         //  Reference to object
amq_server_connection_tune_ok_t * method  //  Not documented
);

void
    amq_server_connection_selftest (
void);

qbyte
    amq_server_connection_count (
void);

void
    amq_server_connection_remove_from_all_containers (
amq_server_connection_t * self          //  The itemThe item
);

#define amq_server_connection_show(item,opcode,trace_file)  amq_server_connection_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_server_connection_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_server_connection_destroy(self)  amq_server_connection_destroy_ (self, __FILE__, __LINE__)
void
    amq_server_connection_destroy_ (
amq_server_connection_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    amq_server_connection_read_lock (
amq_server_connection_t * self          //  Reference to object
);

int
    amq_server_connection_write_lock (
amq_server_connection_t * self          //  Reference to object
);

int
    amq_server_connection_unlock (
amq_server_connection_t * self          //  Reference to object
);

#define amq_server_connection_link(self)  amq_server_connection_link_ (self, __FILE__, __LINE__)
amq_server_connection_t *
    amq_server_connection_link_ (
amq_server_connection_t * self,         //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_server_connection_unlink(self)  amq_server_connection_unlink_ (self, __FILE__, __LINE__)
void
    amq_server_connection_unlink_ (
amq_server_connection_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_server_connection_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_server_connection_new_in_scope(self_p,_scope,table,thread)  amq_server_connection_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, table, thread)
void
    amq_server_connection_new_in_scope_ (
amq_server_connection_t * * self_p,     //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_server_connection_table_t * table,   //  Table to insert into
smt_thread_t * thread                   //  Parent thread
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CONNECTION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CONNECTION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_SERVER_CONNECTION_INLINE)
#   define INCLUDE_AMQ_SERVER_CONNECTION_INLINE
#   define INCLUDE_AMQ_SERVER_CONNECTION_ACTIVE

#   include "amq_queue_list.h"
#   include "amq_server_connection_table.h"
#   include "amq_server_connection_list.h"
#   include "asl.h"
#   include "amq_server_channel.h"
#   include "amq_server_method.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_NEW)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_DESTROY)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_FREE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_OWN_QUEUE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNBIND_QUEUE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_READY)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_START_OK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_OPEN)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_INITIALISE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SET_ADDRESS)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SET_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_KILL)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_RAISE_EXCEPTION)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ERROR)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_EXCEPTION_RAISED)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_TUNE_OK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SELFTEST)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_COUNT)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_SHOW)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ALLOC)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_READ_LOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNLOCK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_LINK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_UNLINK)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_ANIMATE)   || defined (BASE_TRACE_AMQ_SERVER_CONNECTION_NEW_IN_SCOPE) )
void
    amq_server_connection_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CONNECTION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CONNECTION_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_SERVER_CONNECTION_ROOT
#   endif
# endif
#endif
