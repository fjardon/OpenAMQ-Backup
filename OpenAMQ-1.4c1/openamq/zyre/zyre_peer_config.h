/*---------------------------------------------------------------------------
    zyre_peer_config.h - zyre_peer_config component

    Generated from zyre_peer_config.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_ZYRE_PEER_CONFIG_SAFE
#   define INCLUDE_ZYRE_PEER_CONFIG_SAFE
#   define INCLUDE_ZYRE_PEER_CONFIG_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_PEER_CONFIG_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _zyre_peer_config_t zyre_peer_config_t;

#define ZYRE_PEER_CONFIG_ALIVE          0xFABB
#define ZYRE_PEER_CONFIG_DEAD           0xDEAD

#define ZYRE_PEER_CONFIG_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL zyre_peer_config\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != ZYRE_PEER_CONFIG_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "zyre_peer_config at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ZYRE_PEER_CONFIG_ALIVE, self->object_tag);\
        zyre_peer_config_show (self, ICL_CALLBACK_DUMP, stderr);\
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
#   undef INCLUDE_ZYRE_PEER_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PEER_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_PEER_CONFIG_UNSAFE
#   define INCLUDE_ZYRE_PEER_CONFIG_UNSAFE
#   define INCLUDE_ZYRE_PEER_CONFIG_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"
//  Global variables

extern Bool
    zyre_peer_config_animating;
extern zyre_peer_config_t
    *zyre_peer_config;                 //  Global properties object
#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define zyre_peer_config_new()          zyre_peer_config_new_ (__FILE__, __LINE__)
zyre_peer_config_t *
    zyre_peer_config_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    zyre_peer_config_load_xmlfile (
zyre_peer_config_t * self,              //  Reference to object
char * filename,                        //  Config file to load
Bool required                           //  Config file is required?
);

int
    zyre_peer_config_load_bucket (
zyre_peer_config_t * self,              //  Reference to object
ipr_bucket_t * bucket                   //  Config data to load
);

int
    zyre_peer_config_shadow (
zyre_peer_config_t * self,              //  Reference to object
ipr_config_t * source                   //  Config data to shadow
);

int
    zyre_peer_config_commit (
zyre_peer_config_t * self,              //  Reference to object
char * filename                         //  Config file to save
);

int
    zyre_peer_config_rollback (
zyre_peer_config_t * self               //  Reference to object
);

void
    zyre_peer_config_cmdline_help (
void);

int
    zyre_peer_config_cmdline_parse (
zyre_peer_config_t * self,              //  Reference to object
char * name,                            //  Name of application
int argc,                               //  Argument count
char ** argv                            //  Argument list
);

int
    zyre_peer_config_options_help (
zyre_peer_config_t * self,              //  Reference to object
char * name                             //  Name of application
);

int
    zyre_peer_config_set_packio (
zyre_peer_config_t * self,              //  Reference to object
int packio                              //  Not documented
);

int
    zyre_peer_config_packio (
zyre_peer_config_t * self               //  Reference to self
);

int
    zyre_peer_config_set_tcp_nodelay (
zyre_peer_config_t * self,              //  Reference to object
Bool tcp_nodelay                        //  Not documented
);

Bool
    zyre_peer_config_tcp_nodelay (
zyre_peer_config_t * self               //  Reference to self
);

int
    zyre_peer_config_set_tcp_rcvbuf (
zyre_peer_config_t * self,              //  Reference to object
int tcp_rcvbuf                          //  Not documented
);

int
    zyre_peer_config_tcp_rcvbuf (
zyre_peer_config_t * self               //  Reference to self
);

int
    zyre_peer_config_set_tcp_sndbuf (
zyre_peer_config_t * self,              //  Reference to object
int tcp_sndbuf                          //  Not documented
);

int
    zyre_peer_config_tcp_sndbuf (
zyre_peer_config_t * self               //  Reference to self
);

int
    zyre_peer_config_dump_log (
zyre_peer_config_t * self,              //  Reference to object
smt_log_t * logfile                     //  Log file to dump to
);

void
    zyre_peer_config_selftest (
void);

char *
    zyre_peer_config_filename (
zyre_peer_config_t * self               //  Not documented
);

void
    zyre_peer_config_set_filename (
zyre_peer_config_t * self,              //  Not documented
char * filename                         //  Not documented
);

ipr_config_t *
    zyre_peer_config_table (
zyre_peer_config_t * self               //  Not documented
);

void
    zyre_peer_config_terminate (
void);

#define zyre_peer_config_show(item,opcode,trace_file)  zyre_peer_config_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    zyre_peer_config_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_peer_config_destroy(self)  zyre_peer_config_destroy_ (self, __FILE__, __LINE__)
void
    zyre_peer_config_destroy_ (
zyre_peer_config_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    zyre_peer_config_read_lock (
zyre_peer_config_t * self               //  Reference to object
);

int
    zyre_peer_config_write_lock (
zyre_peer_config_t * self               //  Reference to object
);

int
    zyre_peer_config_unlock (
zyre_peer_config_t * self               //  Reference to object
);

void
    zyre_peer_config_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define zyre_peer_config_new_in_scope(self_p,_scope)  zyre_peer_config_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    zyre_peer_config_new_in_scope_ (
zyre_peer_config_t * * self_p,          //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_PEER_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PEER_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_PEER_CONFIG_INLINE)
#   define INCLUDE_ZYRE_PEER_CONFIG_INLINE
#   define INCLUDE_ZYRE_PEER_CONFIG_ACTIVE

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
#   undef INCLUDE_ZYRE_PEER_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PEER_CONFIG_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_PEER_CONFIG_ROOT
#   endif
# endif
#endif
