/*---------------------------------------------------------------------------
    amq_federation.h - amq_federation component

This agent implements a single federation, which is a relationship between
an exchange on this server and the same-named exchange on a parent server.
There are two families of federation, primitives that do one thing and 
compounds which combine the effects of multiple primitives.

The primitives are:

 - Subscriber federation: replicate bindings to the parent server, so that 
   messages are pulled down from it.  The subscriber federation does three
   things: send queue.bind and and queue.unbind commands to the parent 
   server (via a peering), and process messages delivered from the parent.
   Typically used on topic or header exchanges.
   
 - Publisher federation (aka 'forward all'): replicate published messages to
   the parent server.  The publisher federation does two things: forward all
   basic.publish commands to the parent server, and process undeliverable
   messages returned by the parent server. Typically used for topic or header 
   exchanges.
   
 - Locator federation (aka 'forward else'): replicate published messages to
   the parent server if they could not be delivered locally.  The locator
   federation does two things: forward basic.publish messages to the parent
   server if they could not be delivered locally, and process undeliverable
   messages returned by the parent server.  Typically used for direct 
   exchanges.
   
The compound federations are:

 - Fanout federation: combines subscriber and publisher.  Fanout federation
   does this: send queue.bind and unbind to parent server; when a local app
   publishes message, forward that to parent (and do not publish to local
   exchange); process messages delivered from the parent; process returns
   from the parent.  The result is that messages published to any server will
   be pushed up to the highest parent, and then propagated back down through
   all servers and out to applications.  This is the default federation for 
   topic and header exchanges.  The current implementation creates extra
   latency. 
 
 - Service federation: combines subscriber and locator.  Service federation
   does this: send queue.bind and unbind to parent server; when local app
   publishes message, try to deliver locally and if that fails, forward to
   parent server; process messages delivered from parent; process returns
   from the parent.  The result is that requests will go to the nearest
   consumer, and responses will come back down from parents.  This is the
   default federation for direct exchanges.
    Generated from amq_federation.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_FEDERATION_SAFE
#   define INCLUDE_AMQ_FEDERATION_SAFE
#   define INCLUDE_AMQ_FEDERATION_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_FEDERATION_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_federation_t amq_federation_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
#    define AMQ_FEDERATION_HISTORY_LENGTH 32
#endif

#define AMQ_FEDERATION_ALIVE            0xFABB
#define AMQ_FEDERATION_DEAD             0xDEAD

#define AMQ_FEDERATION_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_federation\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_FEDERATION_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_federation at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_FEDERATION_ALIVE, self->object_tag);\
        amq_federation_show (self, ICL_CALLBACK_DUMP, stderr);\
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
#include "amq_federation_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_FEDERATION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_FEDERATION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_FEDERATION_UNSAFE
#   define INCLUDE_AMQ_FEDERATION_UNSAFE
#   define INCLUDE_AMQ_FEDERATION_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_federation_agent.h"
//  Global variables

extern Bool
    amq_federation_animating;
//  Federation types
#define AMQ_FEDERATION_NONE               0
#define AMQ_FEDERATION_SUBSCRIBER         1
#define AMQ_FEDERATION_PUBLISHER          2
#define AMQ_FEDERATION_LOCATOR            3
#define AMQ_FEDERATION_FANOUT             4
#define AMQ_FEDERATION_SERVICE            5
#define AMQ_FEDERATION_VALID(t)           (t > 0 && t < 6)

//  Structure of the amq_federation object

struct _amq_federation_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_FEDERATION_HISTORY_LENGTH];
    int
        history_line  [AMQ_FEDERATION_HISTORY_LENGTH];
    char
        *history_type [AMQ_FEDERATION_HISTORY_LENGTH];
    int
        history_links [AMQ_FEDERATION_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
amq_peering_t
    *peering;                       //  The peering we work with
amq_exchange_t
    *exchange;                      //  The exchange we work with
int
    type;                           //  Federation type
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_federation_new(exchange,type,host,vhost,login)  amq_federation_new_ (__FILE__, __LINE__, exchange, type, host, vhost, login)
amq_federation_t *
    amq_federation_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_exchange_t * exchange,              //  Parent exchange
unsigned int type,                      //  Federation type
char * host,                            //  Host to connect to
char * vhost,                           //  Virtual host identifier
char * login                            //  Peering login to use
);

int
    amq_federation_binding_created (
amq_federation_t * self,                //  Reference to object
char * routing_key,                     //  Not documented
icl_longstr_t * arguments,              //  Not documented
Bool exclusive                          //  Not documented
);

int
    amq_federation_binding_destroyed (
amq_federation_t * self,                //  Reference to object
char * routing_key,                     //  Not documented
icl_longstr_t * arguments               //  Not documented
);

int
    amq_federation_message_published (
amq_federation_t * self,                //  Reference to object
amq_content_basic_t * content,          //  Not documented
Bool mandatory,                         //  Not documented
Bool immediate                          //  Not documented
);

int
    amq_federation_type_lookup (
char * type_name                        //  Type name to lookup
);

char *
    amq_federation_type_name (
int type                                //  Type index to translate
);

void
    amq_federation_selftest (
void);

#define amq_federation_destroy(self)    amq_federation_destroy_ (self, __FILE__, __LINE__)
int
    amq_federation_destroy_ (
amq_federation_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_federation_unlink(self)     amq_federation_unlink_ (self, __FILE__, __LINE__)
void
    amq_federation_unlink_ (
amq_federation_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_federation_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_federation_free(self)       amq_federation_free_ (self, __FILE__, __LINE__)
void
    amq_federation_free_ (
amq_federation_t * self,                //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    amq_federation_terminate (
void);

#define amq_federation_show(item,opcode,trace_file)  amq_federation_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_federation_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_federation_link(self)       amq_federation_link_ (self, __FILE__, __LINE__)
amq_federation_t *
    amq_federation_link_ (
amq_federation_t * self,                //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_federation_new_in_scope(self_p,_scope,exchange,type,host,vhost,login)  amq_federation_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, exchange, type, host, vhost, login)
void
    amq_federation_new_in_scope_ (
amq_federation_t * * self_p,            //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_exchange_t * exchange,              //  Parent exchange
unsigned int type,                      //  Federation type
char * host,                            //  Host to connect to
char * vhost,                           //  Virtual host identifier
char * login                            //  Peering login to use
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_FEDERATION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_FEDERATION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_FEDERATION_INLINE)
#   define INCLUDE_AMQ_FEDERATION_INLINE
#   define INCLUDE_AMQ_FEDERATION_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_NEW)   || defined (BASE_TRACE_AMQ_FEDERATION_DESTROY)   || defined (BASE_TRACE_AMQ_FEDERATION_BINDING_CREATED)   || defined (BASE_TRACE_AMQ_FEDERATION_BINDING_DESTROYED)   || defined (BASE_TRACE_AMQ_FEDERATION_MESSAGE_PUBLISHED)   || defined (BASE_TRACE_AMQ_FEDERATION_TYPE_LOOKUP)   || defined (BASE_TRACE_AMQ_FEDERATION_TYPE_NAME)   || defined (BASE_TRACE_AMQ_FEDERATION_SELFTEST)   || defined (BASE_TRACE_AMQ_FEDERATION_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_FEDERATION_UNLINK)   || defined (BASE_TRACE_AMQ_FEDERATION_ANIMATE)   || defined (BASE_TRACE_AMQ_FEDERATION_FREE)   || defined (BASE_TRACE_AMQ_FEDERATION_INITIALISE)   || defined (BASE_TRACE_AMQ_FEDERATION_TERMINATE)   || defined (BASE_TRACE_AMQ_FEDERATION_SHOW)   || defined (BASE_TRACE_AMQ_FEDERATION_ALLOC)   || defined (BASE_TRACE_AMQ_FEDERATION_LINK)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_FEDERATION_NEW_IN_SCOPE) )
void
    amq_federation_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_federation_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_FEDERATION_ACTIVE
#   if defined (ICL_IMPORT_AMQ_FEDERATION_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_FEDERATION_ROOT
#   endif
# endif
#endif
