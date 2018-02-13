/*---------------------------------------------------------------------------
    amq_failover.h - amq_failover component

    Generated from amq_failover.icl by smt_object_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_FAILOVER_SAFE
#   define INCLUDE_AMQ_FAILOVER_SAFE
#   define INCLUDE_AMQ_FAILOVER_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_FAILOVER_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_failover_t amq_failover_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
#    define AMQ_FAILOVER_HISTORY_LENGTH 32
#endif

#define AMQ_FAILOVER_ALIVE              0xFABB
#define AMQ_FAILOVER_DEAD               0xDEAD

#define AMQ_FAILOVER_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_failover\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_FAILOVER_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_failover at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_FAILOVER_ALIVE, self->object_tag);\
        amq_failover_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_failover_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_FAILOVER_ACTIVE
#   if defined (ICL_IMPORT_AMQ_FAILOVER_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_FAILOVER_UNSAFE
#   define INCLUDE_AMQ_FAILOVER_UNSAFE
#   define INCLUDE_AMQ_FAILOVER_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_failover_agent.h"
//  Global variables

extern Bool
    amq_failover_animating;
typedef enum
{
    amq_ha_state_pending = 1,   //  Waiting for peer to connect
    amq_ha_state_active  = 2,   //  Active - accepting connections
    amq_ha_state_passive = 3    //  Passive - not accepting connections
} amq_ha_state;

typedef enum
{
    amq_ha_event_peer_pending   = 1,  //  HA peer became pending
    amq_ha_event_peer_active    = 2,  //  HA peer became active
    amq_ha_event_peer_passive   = 3,  //  HA peer became passive
    amq_ha_event_new_connection = 4   //  Attempt to create a new connection
} amq_ha_event;

//  Structure of the amq_failover object

struct _amq_failover_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FAILOVER)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_FAILOVER_HISTORY_LENGTH];
    int
        history_line  [AMQ_FAILOVER_HISTORY_LENGTH];
    char
        *history_type [AMQ_FAILOVER_HISTORY_LENGTH];
    int
        history_links [AMQ_FAILOVER_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
amq_peering_t
    *peering;                       //  The peering to the other HA peer
Bool
    enabled,                        //  If FALSE, broker is standalone
    primary;                        //  TRUE = primary, FALSE = backup
long
    timeout;                        //  Failover timeout in usec
amq_ha_state
    state;                          //  State of failover FSM
apr_time_t
    last_peer_time;                 //  Time when peer state arrived lately
                                    //  If this time is older than the failover
                                    //  timeout, the peer is considered dead
amq_exchange_t
    *status_exchange;               //  amq.status exchange
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_failover_new()              amq_failover_new_ (__FILE__, __LINE__)
amq_failover_t *
    amq_failover_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    amq_failover_start_monitoring (
amq_failover_t * self                   //  Reference to object
);

int
    amq_failover_send_state (
amq_failover_t * self                   //  Reference to object
);

int
    amq_failover_execute (
amq_failover_t * self,                  //  Reference to object
int event                               //  Not documented
);

void
    amq_failover_selftest (
void);

#define amq_failover_destroy(self)      amq_failover_destroy_ (self, __FILE__, __LINE__)
int
    amq_failover_destroy_ (
amq_failover_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_failover_unlink(self)       amq_failover_unlink_ (self, __FILE__, __LINE__)
void
    amq_failover_unlink_ (
amq_failover_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_failover_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_failover_free(self)         amq_failover_free_ (self, __FILE__, __LINE__)
void
    amq_failover_free_ (
amq_failover_t * self,                  //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    amq_failover_terminate (
void);

#define amq_failover_show(item,opcode,trace_file)  amq_failover_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_failover_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_failover_link(self)         amq_failover_link_ (self, __FILE__, __LINE__)
amq_failover_t *
    amq_failover_link_ (
amq_failover_t * self,                  //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_failover_new_in_scope(self_p,_scope)  amq_failover_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_failover_new_in_scope_ (
amq_failover_t * * self_p,              //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_FAILOVER_ACTIVE
#   if defined (ICL_IMPORT_AMQ_FAILOVER_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_FAILOVER_INLINE)
#   define INCLUDE_AMQ_FAILOVER_INLINE
#   define INCLUDE_AMQ_FAILOVER_ACTIVE

#   include "amq_server_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "amq_failover_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_FAILOVER_ACTIVE
#   if defined (ICL_IMPORT_AMQ_FAILOVER_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_FAILOVER_ROOT
#   endif
# endif
#endif
