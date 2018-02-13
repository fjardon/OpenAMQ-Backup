/*---------------------------------------------------------------------------
    amq_mgt_console.h - amq_mgt_console component

Implements the management console object, used by applications to
manage OpenAMQ servers.
    Generated from amq_mgt_console.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_MGT_CONSOLE_SAFE
#   define INCLUDE_AMQ_MGT_CONSOLE_SAFE
#   define INCLUDE_AMQ_MGT_CONSOLE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_MGT_CONSOLE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_mgt_console_t amq_mgt_console_t;

#define AMQ_MGT_CONSOLE_ALIVE           0xFABB
#define AMQ_MGT_CONSOLE_DEAD            0xDEAD

#define AMQ_MGT_CONSOLE_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_mgt_console\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_MGT_CONSOLE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_mgt_console at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_MGT_CONSOLE_ALIVE, self->object_tag);\
        amq_mgt_console_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "asl.h"
#   include "amq_cml.h"
#   include "amq_client_connection.h"
#   include "amq_client_session.h"
#   include "amq_mgt_broker.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_MGT_CONSOLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_MGT_CONSOLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_MGT_CONSOLE_UNSAFE
#   define INCLUDE_AMQ_MGT_CONSOLE_UNSAFE
#   define INCLUDE_AMQ_MGT_CONSOLE_ACTIVE

#   include "asl.h"
#   include "amq_cml.h"
#   include "amq_client_connection.h"
#   include "amq_client_session.h"
#   include "amq_mgt_broker.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_mgt_console_animating;
extern int
    g_opt_trace;                        //  Trace option
extern Bool
    g_opt_addr;                         //  Don't do RDNS lookups

//  Structure of the amq_mgt_console object

struct _amq_mgt_console_t {
dbyte
    object_tag;                     //  Object validity marker
amq_client_connection_t
    *connection;                    //  Current connection
amq_client_session_t
    *session;                       //  Current session
amq_mgt_broker_t
    *broker;                        //  Top-level object
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_mgt_console_new(host,vhost,user,password)  amq_mgt_console_new_ (__FILE__, __LINE__, host, vhost, user, password)
amq_mgt_console_t *
    amq_mgt_console_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
char * host,                            //  Server host name
char * vhost,                           //  Virtual host name
char * user,                            //  Login user name
char * password                         //  Login password
);

void
    amq_mgt_console_selftest (
void);

void
    amq_mgt_console_terminate (
void);

#define amq_mgt_console_show(item,opcode,trace_file)  amq_mgt_console_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_mgt_console_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_mgt_console_destroy(self)   amq_mgt_console_destroy_ (self, __FILE__, __LINE__)
void
    amq_mgt_console_destroy_ (
amq_mgt_console_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_mgt_console_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_mgt_console_new_in_scope(self_p,_scope,host,vhost,user,password)  amq_mgt_console_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, host, vhost, user, password)
void
    amq_mgt_console_new_in_scope_ (
amq_mgt_console_t * * self_p,           //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
char * host,                            //  Server host name
char * vhost,                           //  Virtual host name
char * user,                            //  Login user name
char * password                         //  Login password
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_MGT_CONSOLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_MGT_CONSOLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_MGT_CONSOLE_INLINE)
#   define INCLUDE_AMQ_MGT_CONSOLE_INLINE
#   define INCLUDE_AMQ_MGT_CONSOLE_ACTIVE

#   include "asl.h"
#   include "amq_cml.h"
#   include "amq_client_connection.h"
#   include "amq_client_session.h"
#   include "amq_mgt_broker.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_NEW)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_DESTROY)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_SELFTEST)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_TERMINATE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_SHOW)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_ALLOC)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_FREE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_ANIMATE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_NEW_IN_SCOPE) )
void
    amq_mgt_console_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_MGT_CONSOLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_MGT_CONSOLE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_MGT_CONSOLE_ROOT
#   endif
# endif
#endif
