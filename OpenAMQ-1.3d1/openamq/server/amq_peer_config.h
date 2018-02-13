/*---------------------------------------------------------------------------
    amq_peer_config.h - amq_peer_config component

    Generated from amq_peer_config.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_PEER_CONFIG_SAFE
#   define INCLUDE_AMQ_PEER_CONFIG_SAFE
#   define INCLUDE_AMQ_PEER_CONFIG_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_PEER_CONFIG_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_peer_config_t amq_peer_config_t;

#define AMQ_PEER_CONFIG_ALIVE           0xFABB
#define AMQ_PEER_CONFIG_DEAD            0xDEAD

#define AMQ_PEER_CONFIG_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_peer_config\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_PEER_CONFIG_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_peer_config at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_PEER_CONFIG_ALIVE, self->object_tag);\
        amq_peer_config_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "smt_log.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_PEER_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEER_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_PEER_CONFIG_UNSAFE
#   define INCLUDE_AMQ_PEER_CONFIG_UNSAFE
#   define INCLUDE_AMQ_PEER_CONFIG_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"
//  Global variables

extern Bool
    amq_peer_config_animating;
extern amq_peer_config_t
    *amq_peer_config;                  //  Global properties object

//  Structure of the amq_peer_config object

struct _amq_peer_config_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    dbyte
        object_tag;                     //  Object validity marker
ipr_config_t *
    config;                         //  Configuration table
icl_shortstr_t
    filename;                       //  Configuration file name
int
    packio;                         //  Pack network data before writing
Bool
    tcp_nodelay;                    //  TCP/IP NODELAY option
int
    tcp_rcvbuf;                     //  TCP/IP receive buffer, in bytes
int
    tcp_sndbuf;                     //  TCP/IP send buffer, in bytes
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_peer_config_new()           amq_peer_config_new_ (__FILE__, __LINE__)
amq_peer_config_t *
    amq_peer_config_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    amq_peer_config_load_xmlfile (
amq_peer_config_t * self,               //  Reference to object
char * filename,                        //  Config file to load
Bool required                           //  Config file is required?
);

int
    amq_peer_config_load_bucket (
amq_peer_config_t * self,               //  Reference to object
ipr_bucket_t * bucket                   //  Config data to load
);

int
    amq_peer_config_commit (
amq_peer_config_t * self,               //  Reference to object
char * filename                         //  Config file to save
);

int
    amq_peer_config_rollback (
amq_peer_config_t * self                //  Reference to object
);

void
    amq_peer_config_cmdline_help (
void);

int
    amq_peer_config_cmdline_parse (
amq_peer_config_t * self,               //  Reference to object
char * name,                            //  Name of application
int argc,                               //  Argument count
char ** argv                            //  Argument list
);

int
    amq_peer_config_options_help (
amq_peer_config_t * self,               //  Reference to object
char * name                             //  Name of application
);

int
    amq_peer_config_set_packio (
amq_peer_config_t * self,               //  Reference to object
int packio                              //  Not documented
);

int
    amq_peer_config_packio (
amq_peer_config_t * self                //  Reference to self
);

int
    amq_peer_config_set_tcp_nodelay (
amq_peer_config_t * self,               //  Reference to object
Bool tcp_nodelay                        //  Not documented
);

Bool
    amq_peer_config_tcp_nodelay (
amq_peer_config_t * self                //  Reference to self
);

int
    amq_peer_config_set_tcp_rcvbuf (
amq_peer_config_t * self,               //  Reference to object
int tcp_rcvbuf                          //  Not documented
);

int
    amq_peer_config_tcp_rcvbuf (
amq_peer_config_t * self                //  Reference to self
);

int
    amq_peer_config_set_tcp_sndbuf (
amq_peer_config_t * self,               //  Reference to object
int tcp_sndbuf                          //  Not documented
);

int
    amq_peer_config_tcp_sndbuf (
amq_peer_config_t * self                //  Reference to self
);

int
    amq_peer_config_dump_log (
amq_peer_config_t * self,               //  Reference to object
smt_log_t * logfile                     //  Log file to dump to
);

void
    amq_peer_config_selftest (
void);

void
    amq_peer_config_terminate (
void);

#define amq_peer_config_show(item,opcode,trace_file)  amq_peer_config_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_peer_config_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_peer_config_destroy(self)   amq_peer_config_destroy_ (self, __FILE__, __LINE__)
void
    amq_peer_config_destroy_ (
amq_peer_config_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    amq_peer_config_read_lock (
amq_peer_config_t * self                //  Reference to object
);

int
    amq_peer_config_write_lock (
amq_peer_config_t * self                //  Reference to object
);

int
    amq_peer_config_unlock (
amq_peer_config_t * self                //  Reference to object
);

void
    amq_peer_config_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_peer_config_new_in_scope(self_p,_scope)  amq_peer_config_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_peer_config_new_in_scope_ (
amq_peer_config_t * * self_p,           //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_PEER_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEER_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_PEER_CONFIG_INLINE)
#   define INCLUDE_AMQ_PEER_CONFIG_INLINE
#   define INCLUDE_AMQ_PEER_CONFIG_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_NEW)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DESTROY)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_LOAD_XMLFILE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_LOAD_BUCKET)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_COMMIT)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ROLLBACK)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CMDLINE_HELP)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CMDLINE_PARSE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_OPTIONS_HELP)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_PACKIO)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_PACKIO)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_NODELAY)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_NODELAY)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_RCVBUF)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_RCVBUF)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SET_TCP_SNDBUF)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TCP_SNDBUF)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DUMP_LOG)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SELFTEST)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_TERMINATE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_SHOW)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ALLOC)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_FREE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_READ_LOCK)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_UNLOCK)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_ANIMATE)   || defined (BASE_TRACE_AMQ_PEER_CONFIG_NEW_IN_SCOPE) )
void
    amq_peer_config_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "ipr.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_PEER_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEER_CONFIG_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_PEER_CONFIG_ROOT
#   endif
# endif
#endif
