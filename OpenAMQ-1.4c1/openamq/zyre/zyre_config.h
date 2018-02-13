/*---------------------------------------------------------------------------
    zyre_config.h - zyre_config component

    Generated from zyre_config.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_ZYRE_CONFIG_SAFE
#   define INCLUDE_ZYRE_CONFIG_SAFE
#   define INCLUDE_ZYRE_CONFIG_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_CONFIG_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _zyre_config_t zyre_config_t;

#define ZYRE_CONFIG_ALIVE               0xFABB
#define ZYRE_CONFIG_DEAD                0xDEAD

#define ZYRE_CONFIG_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL zyre_config\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != ZYRE_CONFIG_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "zyre_config at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ZYRE_CONFIG_ALIVE, self->object_tag);\
        zyre_config_show (self, ICL_CALLBACK_DUMP, stderr);\
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
#   undef INCLUDE_ZYRE_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_CONFIG_UNSAFE
#   define INCLUDE_ZYRE_CONFIG_UNSAFE
#   define INCLUDE_ZYRE_CONFIG_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"
//  Global variables

extern Bool
    zyre_config_animating;
extern zyre_config_t
    *zyre_config;                     //  Zyre properties object
#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define zyre_config_new()               zyre_config_new_ (__FILE__, __LINE__)
zyre_config_t *
    zyre_config_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    zyre_config_load_xmlfile (
zyre_config_t * self,                   //  Reference to object
char * filename,                        //  Config file to load
Bool required                           //  Config file is required?
);

int
    zyre_config_load_bucket (
zyre_config_t * self,                   //  Reference to object
ipr_bucket_t * bucket                   //  Config data to load
);

int
    zyre_config_shadow (
zyre_config_t * self,                   //  Reference to object
ipr_config_t * source                   //  Config data to shadow
);

int
    zyre_config_commit (
zyre_config_t * self,                   //  Reference to object
char * filename                         //  Config file to save
);

int
    zyre_config_rollback (
zyre_config_t * self                    //  Reference to object
);

void
    zyre_config_cmdline_help (
void);

int
    zyre_config_cmdline_parse (
zyre_config_t * self,                   //  Reference to object
char * name,                            //  Name of application
int argc,                               //  Argument count
char ** argv                            //  Argument list
);

int
    zyre_config_options_help (
zyre_config_t * self,                   //  Reference to object
char * name                             //  Name of application
);

int
    zyre_config_set_server_name (
zyre_config_t * self,                   //  Reference to object
char * server_name                      //  Not documented
);

char *
    zyre_config_server_name (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_port (
zyre_config_t * self,                   //  Reference to object
char * port                             //  Not documented
);

char *
    zyre_config_port (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_public_port (
zyre_config_t * self,                   //  Reference to object
char * public_port                      //  Not documented
);

char *
    zyre_config_public_port (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_trace (
zyre_config_t * self,                   //  Reference to object
Bool trace                              //  Not documented
);

Bool
    zyre_config_trace (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_animate (
zyre_config_t * self,                   //  Reference to object
Bool animate                            //  Not documented
);

Bool
    zyre_config_animate (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_verbose (
zyre_config_t * self,                   //  Reference to object
Bool verbose                            //  Not documented
);

Bool
    zyre_config_verbose (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_listen (
zyre_config_t * self,                   //  Reference to object
char * listen                           //  Not documented
);

char *
    zyre_config_listen (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_restms_debug (
zyre_config_t * self,                   //  Reference to object
Bool restms_debug                       //  Not documented
);

Bool
    zyre_config_restms_debug (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_amqp_autorun (
zyre_config_t * self,                   //  Reference to object
char * amqp_autorun                     //  Not documented
);

char *
    zyre_config_amqp_autorun (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_amqp_hostname (
zyre_config_t * self,                   //  Reference to object
char * amqp_hostname                    //  Not documented
);

char *
    zyre_config_amqp_hostname (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_amqp_username (
zyre_config_t * self,                   //  Reference to object
char * amqp_username                    //  Not documented
);

char *
    zyre_config_amqp_username (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_amqp_password (
zyre_config_t * self,                   //  Reference to object
char * amqp_password                    //  Not documented
);

char *
    zyre_config_amqp_password (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_amqp_timeout (
zyre_config_t * self,                   //  Reference to object
int amqp_timeout                        //  Not documented
);

int
    zyre_config_amqp_timeout (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_amqp_trace (
zyre_config_t * self,                   //  Reference to object
int amqp_trace                          //  Not documented
);

int
    zyre_config_amqp_trace (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_amqp_debug (
zyre_config_t * self,                   //  Reference to object
Bool amqp_debug                         //  Not documented
);

Bool
    zyre_config_amqp_debug (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_user (
zyre_config_t * self,                   //  Reference to object
char * user                             //  Not documented
);

char *
    zyre_config_user (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_group (
zyre_config_t * self,                   //  Reference to object
char * group                            //  Not documented
);

char *
    zyre_config_group (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_blacklist (
zyre_config_t * self,                   //  Reference to object
char * blacklist                        //  Not documented
);

char *
    zyre_config_blacklist (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_basic_auth (
zyre_config_t * self,                   //  Reference to object
char * basic_auth                       //  Not documented
);

char *
    zyre_config_basic_auth (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_digest_auth (
zyre_config_t * self,                   //  Reference to object
char * digest_auth                      //  Not documented
);

char *
    zyre_config_digest_auth (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_password_ttl (
zyre_config_t * self,                   //  Reference to object
int password_ttl                        //  Not documented
);

int
    zyre_config_password_ttl (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_hit_quota (
zyre_config_t * self,                   //  Reference to object
int hit_quota                           //  Not documented
);

int
    zyre_config_hit_quota (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_miss_quota (
zyre_config_t * self,                   //  Reference to object
int miss_quota                          //  Not documented
);

int
    zyre_config_miss_quota (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_password_guard (
zyre_config_t * self,                   //  Reference to object
int password_guard                      //  Not documented
);

int
    zyre_config_password_guard (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_policy_trace (
zyre_config_t * self,                   //  Reference to object
Bool policy_trace                       //  Not documented
);

Bool
    zyre_config_policy_trace (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_nervosity (
zyre_config_t * self,                   //  Reference to object
int nervosity                           //  Not documented
);

int
    zyre_config_nervosity (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_nonce_ttl (
zyre_config_t * self,                   //  Reference to object
int nonce_ttl                           //  Not documented
);

int
    zyre_config_nonce_ttl (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_nonce_quota (
zyre_config_t * self,                   //  Reference to object
int nonce_quota                         //  Not documented
);

int
    zyre_config_nonce_quota (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_refresh_by (
zyre_config_t * self,                   //  Reference to object
char * refresh_by                       //  Not documented
);

char *
    zyre_config_refresh_by (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_refresh_log (
zyre_config_t * self,                   //  Reference to object
char * refresh_log                      //  Not documented
);

char *
    zyre_config_refresh_log (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_address_quota (
zyre_config_t * self,                   //  Reference to object
int address_quota                       //  Not documented
);

int
    zyre_config_address_quota (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_abort_delay (
zyre_config_t * self,                   //  Reference to object
int abort_delay                         //  Not documented
);

int
    zyre_config_abort_delay (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_webroot (
zyre_config_t * self,                   //  Reference to object
char * webroot                          //  Not documented
);

char *
    zyre_config_webroot (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_defaults (
zyre_config_t * self,                   //  Reference to object
char * defaults                         //  Not documented
);

char *
    zyre_config_defaults (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_default_types (
zyre_config_t * self,                   //  Reference to object
char * default_types                    //  Not documented
);

char *
    zyre_config_default_types (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_monitor (
zyre_config_t * self,                   //  Reference to object
int monitor                             //  Not documented
);

int
    zyre_config_monitor (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_record_stats (
zyre_config_t * self,                   //  Reference to object
Bool record_stats                       //  Not documented
);

Bool
    zyre_config_record_stats (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_log_path (
zyre_config_t * self,                   //  Reference to object
char * log_path                         //  Not documented
);

char *
    zyre_config_log_path (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_keep_logs (
zyre_config_t * self,                   //  Reference to object
Bool keep_logs                          //  Not documented
);

Bool
    zyre_config_keep_logs (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_archive_cmd (
zyre_config_t * self,                   //  Reference to object
char * archive_cmd                      //  Not documented
);

char *
    zyre_config_archive_cmd (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_alert_log (
zyre_config_t * self,                   //  Reference to object
char * alert_log                        //  Not documented
);

char *
    zyre_config_alert_log (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_access_log (
zyre_config_t * self,                   //  Reference to object
char * access_log                       //  Not documented
);

char *
    zyre_config_access_log (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_access_log_format (
zyre_config_t * self,                   //  Reference to object
char * access_log_format                //  Not documented
);

char *
    zyre_config_access_log_format (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_debug_log (
zyre_config_t * self,                   //  Reference to object
char * debug_log                        //  Not documented
);

char *
    zyre_config_debug_log (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_syslog (
zyre_config_t * self,                   //  Reference to object
int syslog                              //  Not documented
);

int
    zyre_config_syslog (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_coremark_cycles (
zyre_config_t * self,                   //  Reference to object
int coremark_cycles                     //  Not documented
);

int
    zyre_config_coremark_cycles (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_header_max (
zyre_config_t * self,                   //  Reference to object
int header_max                          //  Not documented
);

int
    zyre_config_header_max (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_bucket_max (
zyre_config_t * self,                   //  Reference to object
int bucket_max                          //  Not documented
);

int
    zyre_config_bucket_max (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_read_timeout (
zyre_config_t * self,                   //  Reference to object
int read_timeout                        //  Not documented
);

int
    zyre_config_read_timeout (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_write_timeout (
zyre_config_t * self,                   //  Reference to object
int write_timeout                       //  Not documented
);

int
    zyre_config_write_timeout (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_accept_retry_timeout (
zyre_config_t * self,                   //  Reference to object
int accept_retry_timeout                //  Not documented
);

int
    zyre_config_accept_retry_timeout (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_tcp_nodelay (
zyre_config_t * self,                   //  Reference to object
Bool tcp_nodelay                        //  Not documented
);

Bool
    zyre_config_tcp_nodelay (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_tcp_rcvbuf (
zyre_config_t * self,                   //  Reference to object
int tcp_rcvbuf                          //  Not documented
);

int
    zyre_config_tcp_rcvbuf (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_tcp_sndbuf (
zyre_config_t * self,                   //  Reference to object
int tcp_sndbuf                          //  Not documented
);

int
    zyre_config_tcp_sndbuf (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_polling_threads (
zyre_config_t * self,                   //  Reference to object
int polling_threads                     //  Not documented
);

int
    zyre_config_polling_threads (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_working_threads (
zyre_config_t * self,                   //  Reference to object
int working_threads                     //  Not documented
);

int
    zyre_config_working_threads (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_set_etag (
zyre_config_t * self,                   //  Reference to object
char * etag                             //  Not documented
);

char *
    zyre_config_etag (
zyre_config_t * self                    //  Reference to self
);

int
    zyre_config_dump_log (
zyre_config_t * self,                   //  Reference to object
smt_log_t * logfile                     //  Log file to dump to
);

void
    zyre_config_selftest (
void);

char *
    zyre_config_filename (
zyre_config_t * self                    //  Not documented
);

void
    zyre_config_set_filename (
zyre_config_t * self,                   //  Not documented
char * filename                         //  Not documented
);

ipr_config_t *
    zyre_config_table (
zyre_config_t * self                    //  Not documented
);

void
    zyre_config_terminate (
void);

#define zyre_config_show(item,opcode,trace_file)  zyre_config_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    zyre_config_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_config_destroy(self)       zyre_config_destroy_ (self, __FILE__, __LINE__)
void
    zyre_config_destroy_ (
zyre_config_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    zyre_config_read_lock (
zyre_config_t * self                    //  Reference to object
);

int
    zyre_config_write_lock (
zyre_config_t * self                    //  Reference to object
);

int
    zyre_config_unlock (
zyre_config_t * self                    //  Reference to object
);

void
    zyre_config_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define zyre_config_new_in_scope(self_p,_scope)  zyre_config_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    zyre_config_new_in_scope_ (
zyre_config_t * * self_p,               //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_CONFIG_INLINE)
#   define INCLUDE_ZYRE_CONFIG_INLINE
#   define INCLUDE_ZYRE_CONFIG_ACTIVE

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
#   undef INCLUDE_ZYRE_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_CONFIG_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_CONFIG_ROOT
#   endif
# endif
#endif
