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
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_peer_config\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_PEER_CONFIG_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_peer_config at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_PEER_CONFIG_ALIVE, self->object_tag);\
        amq_peer_config_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "smt_log.h"
#   include "icl_mem.h"
#   include "icl_system.h"
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
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"
//  Global variables

extern Bool
    amq_peer_config_animating;
extern amq_peer_config_t
    *amq_peer_config;                  //  Global properties object
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
    amq_peer_config_shadow (
amq_peer_config_t * self,               //  Reference to object
ipr_config_t * source                   //  Config data to shadow
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

char *
    amq_peer_config_filename (
amq_peer_config_t * self                //  Not documented
);

void
    amq_peer_config_set_filename (
amq_peer_config_t * self,               //  Not documented
char * filename                         //  Not documented
);

ipr_config_t *
    amq_peer_config_table (
amq_peer_config_t * self                //  Not documented
);

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
    amq_peer_config_show_animation (
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
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

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
