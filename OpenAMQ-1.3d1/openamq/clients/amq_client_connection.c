/*---------------------------------------------------------------------------
    amq_client_connection.c - amq_client_connection component

A amq_client_connection object establishes and manages a single
connection to a amq server. The connection can hold
many sessions - each is a amq_client_session object. To use this
API, first create a connection to the server, then create one or
more sessions and do work on the sessions. Each session represents
a serial stream of work. In simple applications, a single session
is usually sufficient. In multithreaded applications, each thread
will want its own session.
    Generated from amq_client_connection.icl by icl_gen using GSL/4.
    
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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "amq_client_connection.h"      //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_client_connection_t

//  Shorthands for class methods                                               

#define self_new            amq_client_connection_new
#define self_annihilate     amq_client_connection_annihilate
#define self_auth_plain     amq_client_connection_auth_plain
#define self_wait           amq_client_connection_wait
#define self_set_silent     amq_client_connection_set_silent
#define self_set_timeout    amq_client_connection_set_timeout
#define self_get_silent     amq_client_connection_get_silent
#define self_get_alive      amq_client_connection_get_alive
#define self_get_error_text  amq_client_connection_get_error_text
#define self_get_version_major  amq_client_connection_get_version_major
#define self_get_version_minor  amq_client_connection_get_version_minor
#define self_get_channel_max  amq_client_connection_get_channel_max
#define self_get_frame_max  amq_client_connection_get_frame_max
#define self_get_heartbeat  amq_client_connection_get_heartbeat
#define self_get_known_hosts  amq_client_connection_get_known_hosts
#define self_get_reply_code  amq_client_connection_get_reply_code
#define self_get_reply_text  amq_client_connection_get_reply_text
#define self_get_class_id   amq_client_connection_get_class_id
#define self_get_method_id  amq_client_connection_get_method_id
#define self_initialise     amq_client_connection_initialise
#define self_terminate      amq_client_connection_terminate
#define self_selftest       amq_client_connection_selftest
#define self_show           amq_client_connection_show
#define self_destroy        amq_client_connection_destroy
#define self_alloc          amq_client_connection_alloc
#define self_free           amq_client_connection_free
#define self_read_lock      amq_client_connection_read_lock
#define self_write_lock     amq_client_connection_write_lock
#define self_unlock         amq_client_connection_unlock
#define self_cache_initialise  amq_client_connection_cache_initialise
#define self_cache_purge    amq_client_connection_cache_purge
#define self_cache_terminate  amq_client_connection_cache_terminate
#define self_animate        amq_client_connection_animate
#define self_new_in_scope   amq_client_connection_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_NEW))
static icl_stats_t *s_amq_client_connection_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_DESTROY))
static icl_stats_t *s_amq_client_connection_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_AUTH_PLAIN))
static icl_stats_t *s_amq_client_connection_auth_plain_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_WAIT))
static icl_stats_t *s_amq_client_connection_wait_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_SET_SILENT))
static icl_stats_t *s_amq_client_connection_set_silent_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_SET_TIMEOUT))
static icl_stats_t *s_amq_client_connection_set_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_SILENT))
static icl_stats_t *s_amq_client_connection_get_silent_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_ALIVE))
static icl_stats_t *s_amq_client_connection_get_alive_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_ERROR_TEXT))
static icl_stats_t *s_amq_client_connection_get_error_text_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_VERSION_MAJOR))
static icl_stats_t *s_amq_client_connection_get_version_major_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_VERSION_MINOR))
static icl_stats_t *s_amq_client_connection_get_version_minor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_CHANNEL_MAX))
static icl_stats_t *s_amq_client_connection_get_channel_max_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_FRAME_MAX))
static icl_stats_t *s_amq_client_connection_get_frame_max_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_HEARTBEAT))
static icl_stats_t *s_amq_client_connection_get_heartbeat_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_KNOWN_HOSTS))
static icl_stats_t *s_amq_client_connection_get_known_hosts_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_REPLY_CODE))
static icl_stats_t *s_amq_client_connection_get_reply_code_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_REPLY_TEXT))
static icl_stats_t *s_amq_client_connection_get_reply_text_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_CLASS_ID))
static icl_stats_t *s_amq_client_connection_get_class_id_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_METHOD_ID))
static icl_stats_t *s_amq_client_connection_get_method_id_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_INITIALISE))
static icl_stats_t *s_amq_client_connection_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_TERMINATE))
static icl_stats_t *s_amq_client_connection_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_SELFTEST))
static icl_stats_t *s_amq_client_connection_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_SHOW))
static icl_stats_t *s_amq_client_connection_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_DESTROY_PUBLIC))
static icl_stats_t *s_amq_client_connection_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_ALLOC))
static icl_stats_t *s_amq_client_connection_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_FREE))
static icl_stats_t *s_amq_client_connection_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_READ_LOCK))
static icl_stats_t *s_amq_client_connection_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_WRITE_LOCK))
static icl_stats_t *s_amq_client_connection_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_UNLOCK))
static icl_stats_t *s_amq_client_connection_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_CACHE_INITIALISE))
static icl_stats_t *s_amq_client_connection_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_CACHE_PURGE))
static icl_stats_t *s_amq_client_connection_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_CACHE_TERMINATE))
static icl_stats_t *s_amq_client_connection_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_ANIMATE))
static icl_stats_t *s_amq_client_connection_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_NEW_IN_SCOPE))
static icl_stats_t *s_amq_client_connection_new_in_scope_stats = NULL;
#endif
static void
    amq_client_connection_annihilate (
amq_client_connection_t * ( * self_p )  //  Reference to object reference
);

static void
    amq_client_connection_initialise (
void);

static void
    amq_client_connection_terminate (
void);

#define amq_client_connection_alloc()   amq_client_connection_alloc_ (__FILE__, __LINE__)
static amq_client_connection_t *
    amq_client_connection_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_client_connection_free (
amq_client_connection_t * self          //  Object reference
);

static void
    amq_client_connection_cache_initialise (
void);

static void
    amq_client_connection_cache_purge (
void);

static void
    amq_client_connection_cache_terminate (
void);

Bool
    amq_client_connection_animating = TRUE;  //  Animation enabled by default
static Bool
    s_amq_client_connection_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_client_connection_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static int
    s_wait_for_methods (amq_client_connection_t *self, int timeout, Bool blocking);
/*  -------------------------------------------------------------------------
    amq_client_connection_new

    Type: Component method
    Creates and initialises a new amq_client_connection_t object, returns a
    reference to the created object.
    Create new connection to server.

    The host argument specifies a server name or IP address, optionally
    ending in ':' plus a port number.

    The virtual_host name specifies the virtual host to which the connection
    will connect.  The default virtual host is "/".

    The auth_data provides an authentication block, used to login to the
    server.  To create a plain-text authentication block, use the auth_plain
    method.

    The trace argument sets the trace level for the client API.

    The timeout argument governs all synchronous exchanges with the server
    - if the server does not respond within this time, the connection treats
    it as a fatal error.  A timeout of zero means "infinite".  A good value
    for fast networks is five to ten seconds; for a slower network, a value
    of 30 seconds or more is reasonable.
    -------------------------------------------------------------------------
 */

amq_client_connection_t *
    amq_client_connection_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * host,                        //  Host to connect to
    char * virtual_host,                //  Virtual host
    icl_longstr_t * auth_data,          //  Authentication data
    char* instance,                     //  Client instance name
    int trace,                          //  Trace level, 0 - 3
    int timeout                         //  Connection timeout, msecs
)
{
char
    *env_value;                 //  Get environment setting
    amq_client_connection_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_NEW))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" host=\"%s\""
" virtual_host=\"%s\""
" auth_data=\"%pp\""
" instance=\"%pp\""
" trace=\"%i\""
" timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, host, virtual_host, auth_data, instance, trace, timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_NEW))
    icl_trace_record (NULL, amq_client_connection_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_NEW))
    icl_stats_inc ("amq_client_connection_new", &s_amq_client_connection_new_stats);
#endif

if (!s_amq_client_connection_active)
    self_initialise ();
    self = amq_client_connection_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CLIENT_CONNECTION_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_client_connection_show_);
#endif

//
self->method_queue = smt_method_queue_sync_new ();
self->timeout = timeout;
self->trace = trace;
self->error_text = "no error";
icl_shortstr_cpy (self->host, host);

env_value = getenv ("WIREAPI_SILENT");
if (env_value && streq (env_value, "1"))
    self->silent = TRUE;

self->thread = amq_client_agent_connection_thread_new (
    self->method_queue,
    &self->alive,
    &self->interrupt,
    &self->reply_code,
    self->reply_text,
    host,
    virtual_host,
    auth_data,
    instance,
    trace,
    timeout);

//  Let the SMT engine take over until we get a reply on our queue
if (self->thread) {
    if (s_wait_for_methods (self, self->timeout, TRUE) == 0) {
        self->alive = TRUE;         //  Connection is ready for use
        //  Decide whether to use Direct Mode or not
        if (amq_client_config_direct (amq_client_config) || self->server_direct)
            self->direct = TRUE;
    }
    else
        self_destroy (&self);
}
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_NEW))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_NEW))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" host=\"%s\""
" virtual_host=\"%s\""
" auth_data=\"%pp\""
" instance=\"%pp\""
" trace=\"%i\""
" timeout=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, host, virtual_host, auth_data, instance, trace, timeout, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_annihilate

    Type: Component method
    Close the connection and all sessions on it.  Call this when your
    application ends, or if you want to break the connection to the
    server.  This performs a clean shut-down of the connection, so any
    server-side resources are freed.
    -------------------------------------------------------------------------
 */

static void
    amq_client_connection_annihilate (
    amq_client_connection_t * ( * self_p )  //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    amq_client_connection_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_DESTROY))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_DESTROY))
    icl_trace_record (NULL, amq_client_connection_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_DESTROY))
    icl_stats_inc ("amq_client_connection_annihilate", &s_amq_client_connection_annihilate_stats);
#endif

    AMQ_CLIENT_CONNECTION_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

//
if (self->alive) {
    amq_client_agent_connection_close (self->thread);
    while (self->alive) {
        //  Wait until we get back an CLOSED method, or timeout
        s_wait_for_methods (self, self->timeout, FALSE);
    }
}
smt_method_queue_destroy (&self->method_queue);
smt_thread_unlink (&self->thread);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_DESTROY))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_DESTROY))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_connection_auth_plain

    Type: Component method
    Formats a new authentication data block for a plain login.
    -------------------------------------------------------------------------
 */

icl_longstr_t *
    amq_client_connection_auth_plain (
    char * login,                       //  User login name
    char * password                     //  User password
)
{
    icl_longstr_t *
        auth_data;                      //  Authentication data

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_AUTH_PLAIN))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_auth_plain_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" login=\"%s\""
" password=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, login, password);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_AUTH_PLAIN))
    icl_trace_record (NULL, amq_client_connection_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_AUTH_PLAIN))
    icl_stats_inc ("amq_client_connection_auth_plain", &s_amq_client_connection_auth_plain_stats);
#endif

//
auth_data = ipr_sasl_plain_encode (login, password);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_AUTH_PLAIN))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_AUTH_PLAIN))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_auth_plain_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" login=\"%s\""
" password=\"%s\""
" auth_data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, login, password, auth_data);
#endif


    return (auth_data);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_wait

    Type: Component method
    Accepts a amq_client_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Waits for any activity on the connection. Returns -1 if the connection
    ended abnormally. If the timeout is zero, waits forever.
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_wait (
    amq_client_connection_t * self,     //  Reference to object
    int timeout                         //  Timeout, in milliseconds
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_WAIT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_wait_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_WAIT))
    icl_trace_record (NULL, amq_client_connection_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_WAIT))
    icl_stats_inc ("amq_client_connection_wait", &s_amq_client_connection_wait_stats);
#endif

AMQ_CLIENT_CONNECTION_ASSERT_SANE (self);

//
if (self->alive) {
    if (s_wait_for_methods (self, timeout, FALSE))
        rc = -1;
}
else
    rc = -1;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_WAIT))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_WAIT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_wait_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" timeout=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, timeout, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_set_silent

    Type: Component method
    Accepts a amq_client_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_set_silent (
    amq_client_connection_t * self,     //  Reference to object
    Bool silent                         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_SET_SILENT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_set_silent_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" silent=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, silent);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SET_SILENT))
    icl_trace_record (NULL, amq_client_connection_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_SET_SILENT))
    icl_stats_inc ("amq_client_connection_set_silent", &s_amq_client_connection_set_silent_stats);
#endif

AMQ_CLIENT_CONNECTION_ASSERT_SANE (self);

//
self->silent = silent;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SET_SILENT))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_SET_SILENT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_set_silent_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" silent=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, silent, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_set_timeout

    Type: Component method
    Accepts a amq_client_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_set_timeout (
    amq_client_connection_t * self,     //  Reference to object
    Bool timeout                        //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_SET_TIMEOUT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_set_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SET_TIMEOUT))
    icl_trace_record (NULL, amq_client_connection_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_SET_TIMEOUT))
    icl_stats_inc ("amq_client_connection_set_timeout", &s_amq_client_connection_set_timeout_stats);
#endif

AMQ_CLIENT_CONNECTION_ASSERT_SANE (self);

//
self->timeout = timeout;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SET_TIMEOUT))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_SET_TIMEOUT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_set_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" timeout=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, timeout, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_silent

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_client_connection_get_silent (
    amq_client_connection_t * self      //  Object reference
)
{
    Bool
        silent;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_SILENT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_silent_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_SILENT))
    icl_trace_record (NULL, amq_client_connection_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_SILENT))
    icl_stats_inc ("amq_client_connection_get_silent", &s_amq_client_connection_get_silent_stats);
#endif

//
silent = self->silent;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_SILENT))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_SILENT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_silent_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" silent=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, silent);
#endif


    return (silent);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_alive

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    amq_client_connection_get_alive (
    amq_client_connection_t * self      //  Object reference
)
{
    Bool
        alive;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_ALIVE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_alive_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_ALIVE))
    icl_trace_record (NULL, amq_client_connection_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_ALIVE))
    icl_stats_inc ("amq_client_connection_get_alive", &s_amq_client_connection_get_alive_stats);
#endif

//
alive = self->alive;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_ALIVE))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_ALIVE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_alive_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" alive=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, alive);
#endif


    return (alive);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_error_text

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_connection_get_error_text (
    amq_client_connection_t * self      //  Object reference
)
{
    char *
        error_text;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_ERROR_TEXT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_error_text_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_ERROR_TEXT))
    icl_trace_record (NULL, amq_client_connection_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_ERROR_TEXT))
    icl_stats_inc ("amq_client_connection_get_error_text", &s_amq_client_connection_get_error_text_stats);
#endif

//
error_text = self->error_text;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_ERROR_TEXT))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_ERROR_TEXT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_error_text_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" error_text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, error_text);
#endif


    return (error_text);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_version_major

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_get_version_major (
    amq_client_connection_t * self      //  Object reference
)
{
    int
        version_major;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_VERSION_MAJOR))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_version_major_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_VERSION_MAJOR))
    icl_trace_record (NULL, amq_client_connection_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_VERSION_MAJOR))
    icl_stats_inc ("amq_client_connection_get_version_major", &s_amq_client_connection_get_version_major_stats);
#endif

//
version_major = self->version_major;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_VERSION_MAJOR))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_VERSION_MAJOR))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_version_major_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" version_major=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, version_major);
#endif


    return (version_major);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_version_minor

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_get_version_minor (
    amq_client_connection_t * self      //  Object reference
)
{
    int
        version_minor;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_VERSION_MINOR))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_version_minor_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_VERSION_MINOR))
    icl_trace_record (NULL, amq_client_connection_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_VERSION_MINOR))
    icl_stats_inc ("amq_client_connection_get_version_minor", &s_amq_client_connection_get_version_minor_stats);
#endif

//
version_minor = self->version_minor;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_VERSION_MINOR))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_VERSION_MINOR))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_version_minor_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" version_minor=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, version_minor);
#endif


    return (version_minor);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_channel_max

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_get_channel_max (
    amq_client_connection_t * self      //  Object reference
)
{
    int
        channel_max;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_CHANNEL_MAX))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_channel_max_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_CHANNEL_MAX))
    icl_trace_record (NULL, amq_client_connection_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_CHANNEL_MAX))
    icl_stats_inc ("amq_client_connection_get_channel_max", &s_amq_client_connection_get_channel_max_stats);
#endif

//
channel_max = self->channel_max;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_CHANNEL_MAX))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_CHANNEL_MAX))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_channel_max_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel_max=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel_max);
#endif


    return (channel_max);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_frame_max

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_client_connection_get_frame_max (
    amq_client_connection_t * self      //  Object reference
)
{
    qbyte
        frame_max;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_FRAME_MAX))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_frame_max_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_FRAME_MAX))
    icl_trace_record (NULL, amq_client_connection_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_FRAME_MAX))
    icl_stats_inc ("amq_client_connection_get_frame_max", &s_amq_client_connection_get_frame_max_stats);
#endif

//
frame_max = self->frame_max;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_FRAME_MAX))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_FRAME_MAX))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_frame_max_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" frame_max=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, frame_max);
#endif


    return (frame_max);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_heartbeat

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_get_heartbeat (
    amq_client_connection_t * self      //  Object reference
)
{
    int
        heartbeat;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_HEARTBEAT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_heartbeat_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_HEARTBEAT))
    icl_trace_record (NULL, amq_client_connection_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_HEARTBEAT))
    icl_stats_inc ("amq_client_connection_get_heartbeat", &s_amq_client_connection_get_heartbeat_stats);
#endif

//
heartbeat = self->heartbeat;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_HEARTBEAT))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_HEARTBEAT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_heartbeat_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" heartbeat=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, heartbeat);
#endif


    return (heartbeat);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_known_hosts

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_connection_get_known_hosts (
    amq_client_connection_t * self      //  Object reference
)
{
    char *
        known_hosts;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_KNOWN_HOSTS))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_known_hosts_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_KNOWN_HOSTS))
    icl_trace_record (NULL, amq_client_connection_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_KNOWN_HOSTS))
    icl_stats_inc ("amq_client_connection_get_known_hosts", &s_amq_client_connection_get_known_hosts_stats);
#endif

//
known_hosts = self->known_hosts;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_KNOWN_HOSTS))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_KNOWN_HOSTS))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_known_hosts_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" known_hosts=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, known_hosts);
#endif


    return (known_hosts);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_reply_code

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_get_reply_code (
    amq_client_connection_t * self      //  Object reference
)
{
    int
        reply_code;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_REPLY_CODE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_reply_code_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_REPLY_CODE))
    icl_trace_record (NULL, amq_client_connection_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_REPLY_CODE))
    icl_stats_inc ("amq_client_connection_get_reply_code", &s_amq_client_connection_get_reply_code_stats);
#endif

//
reply_code = self->reply_code;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_REPLY_CODE))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_REPLY_CODE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_reply_code_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_code=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_code);
#endif


    return (reply_code);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_reply_text

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_client_connection_get_reply_text (
    amq_client_connection_t * self      //  Object reference
)
{
    char *
        reply_text;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_REPLY_TEXT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_reply_text_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_REPLY_TEXT))
    icl_trace_record (NULL, amq_client_connection_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_REPLY_TEXT))
    icl_stats_inc ("amq_client_connection_get_reply_text", &s_amq_client_connection_get_reply_text_stats);
#endif

//
reply_text = self->reply_text;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_REPLY_TEXT))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_REPLY_TEXT))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_reply_text_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_text);
#endif


    return (reply_text);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_class_id

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_get_class_id (
    amq_client_connection_t * self      //  Object reference
)
{
    int
        class_id;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_CLASS_ID))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_class_id_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_CLASS_ID))
    icl_trace_record (NULL, amq_client_connection_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_CLASS_ID))
    icl_stats_inc ("amq_client_connection_get_class_id", &s_amq_client_connection_get_class_id_stats);
#endif

//
class_id = self->class_id;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_CLASS_ID))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_CLASS_ID))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_class_id_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" class_id=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, class_id);
#endif


    return (class_id);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_get_method_id

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_get_method_id (
    amq_client_connection_t * self      //  Object reference
)
{
    int
        method_id;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_METHOD_ID))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_method_id_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_METHOD_ID))
    icl_trace_record (NULL, amq_client_connection_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_GET_METHOD_ID))
    icl_stats_inc ("amq_client_connection_get_method_id", &s_amq_client_connection_get_method_id_stats);
#endif

//
method_id = self->method_id;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_METHOD_ID))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_GET_METHOD_ID))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_get_method_id_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method_id=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method_id);
#endif


    return (method_id);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_initialise

    Type: Component method
    Initialise the connection class.  If the application has not already loaded config data,
    loads this from with wireapi.cfg.
    -------------------------------------------------------------------------
 */

static void
    amq_client_connection_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_INITIALISE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_INITIALISE))
    icl_trace_record (NULL, amq_client_connection_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_INITIALISE))
    icl_stats_inc ("amq_client_connection_initialise", &s_amq_client_connection_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_client_connection_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_client_connection_mutex)
            s_amq_client_connection_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_client_connection_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_client_connection_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

 if (!amq_client_config) {
     amq_client_config = amq_client_config_new ();
     amq_client_config_load_xmlfile (amq_client_config, "wireapi.cfg", FALSE);
 }
smt_initialise ();
amq_client_agent_init ();
            s_amq_client_connection_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_client_connection_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_INITIALISE))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_INITIALISE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_initialise_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_connection_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_connection_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_TERMINATE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_TERMINATE))
    icl_trace_record (NULL, amq_client_connection_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_TERMINATE))
    icl_stats_inc ("amq_client_connection_terminate", &s_amq_client_connection_terminate_stats);
#endif

if (s_amq_client_connection_active) {

amq_client_config_destroy (&amq_client_config);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_client_connection_mutex);
#endif
        s_amq_client_connection_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_TERMINATE))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_TERMINATE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_connection_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_connection_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_SELFTEST))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SELFTEST))
    icl_trace_record (NULL, amq_client_connection_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_SELFTEST))
    icl_stats_inc ("amq_client_connection_selftest", &s_amq_client_connection_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SELFTEST))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_SELFTEST))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_selftest_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_connection_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_connection_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_client_connection_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_SHOW))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_show_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SHOW))
    icl_trace_record (NULL, amq_client_connection_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_SHOW))
    icl_stats_inc ("amq_client_connection_show", &s_amq_client_connection_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_client_connection file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SHOW))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_SHOW))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_show_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_connection_destroy

    Type: Component method
    Destroys a amq_client_connection_t object. Takes the address of a
    amq_client_connection_t reference (a pointer to a pointer) and nullifies the
    reference after use.  Does nothing if the reference is already
    null.
    Performs an agressive destroy of an object.  This involves:
    1. Removing the object from any containers it is in.
    2. Making the object an zombie
    3. Decrementing the object's link count
    4. If the link count is zero then freeing the object.
    -------------------------------------------------------------------------
 */

void
    amq_client_connection_destroy_ (
    amq_client_connection_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_client_connection_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_DESTROY_PUBLIC))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_client_connection_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_DESTROY_PUBLIC))
    icl_stats_inc ("amq_client_connection_destroy", &s_amq_client_connection_destroy_stats);
#endif

if (self) {
    amq_client_connection_annihilate (self_p);
    amq_client_connection_free ((amq_client_connection_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_DESTROY_PUBLIC))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_connection_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_client_connection_t *
    amq_client_connection_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_client_connection_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_ALLOC))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_ALLOC))
    icl_trace_record (NULL, amq_client_connection_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_ALLOC))
    icl_stats_inc ("amq_client_connection_alloc", &s_amq_client_connection_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_client_connection_cache_initialise ();

self = (amq_client_connection_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_client_connection_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_ALLOC))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_ALLOC))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_free

    Type: Component method
    Freess a amq_client_connection_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_client_connection_free (
    amq_client_connection_t * self      //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_FREE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_FREE))
    icl_trace_record (NULL, amq_client_connection_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_FREE))
    icl_stats_inc ("amq_client_connection_free", &s_amq_client_connection_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (amq_client_connection_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_client_connection_t));
        self->object_tag = AMQ_CLIENT_CONNECTION_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_FREE))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_FREE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_connection_read_lock

    Type: Component method
    Accepts a amq_client_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_read_lock (
    amq_client_connection_t * self      //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_READ_LOCK))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_read_lock_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_READ_LOCK))
    icl_trace_record (NULL, amq_client_connection_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_READ_LOCK))
    icl_stats_inc ("amq_client_connection_read_lock", &s_amq_client_connection_read_lock_stats);
#endif

AMQ_CLIENT_CONNECTION_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_READ_LOCK))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_READ_LOCK))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_read_lock_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_write_lock

    Type: Component method
    Accepts a amq_client_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_write_lock (
    amq_client_connection_t * self      //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_WRITE_LOCK))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_write_lock_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_WRITE_LOCK))
    icl_trace_record (NULL, amq_client_connection_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_WRITE_LOCK))
    icl_stats_inc ("amq_client_connection_write_lock", &s_amq_client_connection_write_lock_stats);
#endif

AMQ_CLIENT_CONNECTION_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_WRITE_LOCK))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_WRITE_LOCK))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_write_lock_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_unlock

    Type: Component method
    Accepts a amq_client_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_client_connection_unlock (
    amq_client_connection_t * self      //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_UNLOCK))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_unlock_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_UNLOCK))
    icl_trace_record (NULL, amq_client_connection_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_UNLOCK))
    icl_stats_inc ("amq_client_connection_unlock", &s_amq_client_connection_unlock_stats);
#endif

AMQ_CLIENT_CONNECTION_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_UNLOCK))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_UNLOCK))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_unlock_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_connection_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_client_connection_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_CACHE_INITIALISE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_client_connection_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_CACHE_INITIALISE))
    icl_stats_inc ("amq_client_connection_cache_initialise", &s_amq_client_connection_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_client_connection_t));
icl_system_register (amq_client_connection_cache_purge, amq_client_connection_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_CACHE_INITIALISE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_cache_initialise_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_connection_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_connection_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_CACHE_PURGE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_PURGE))
    icl_trace_record (NULL, amq_client_connection_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_CACHE_PURGE))
    icl_stats_inc ("amq_client_connection_cache_purge", &s_amq_client_connection_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_PURGE))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_CACHE_PURGE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_cache_purge_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_connection_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_connection_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_CACHE_TERMINATE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_client_connection_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_CACHE_TERMINATE))
    icl_stats_inc ("amq_client_connection_cache_terminate", &s_amq_client_connection_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_CACHE_TERMINATE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_cache_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_connection_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_client_connection_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_ANIMATE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_animate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_ANIMATE))
    icl_trace_record (NULL, amq_client_connection_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_ANIMATE))
    icl_stats_inc ("amq_client_connection_animate", &s_amq_client_connection_animate_stats);
#endif

amq_client_connection_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_ANIMATE))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_ANIMATE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_animate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_connection_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_connection_new_in_scope_ (
    amq_client_connection_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * host,                        //  Host to connect to
    char * virtual_host,                //  Virtual host
    icl_longstr_t * auth_data,          //  Authentication data
    char* instance,                     //  Client instance name
    int trace,                          //  Trace level, 0 - 3
    int timeout                         //  Connection timeout, msecs
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_NEW_IN_SCOPE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" host=\"%s\""
" virtual_host=\"%s\""
" auth_data=\"%pp\""
" instance=\"%pp\""
" trace=\"%i\""
" timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, host, virtual_host, auth_data, instance, trace, timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_client_connection_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION)  ||  defined (BASE_STATS_AMQ_CLIENT_CONNECTION_NEW_IN_SCOPE))
    icl_stats_inc ("amq_client_connection_new_in_scope", &s_amq_client_connection_new_in_scope_stats);
#endif

*self_p = amq_client_connection_new_ (file,line,host,virtual_host,auth_data,instance,trace,timeout);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_client_connection_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_client_connection_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION)   || defined (BASE_ANIMATE_AMQ_CLIENT_CONNECTION_NEW_IN_SCOPE))
    if (amq_client_connection_animating)
        icl_console_print ("<amq_client_connection_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" host=\"%s\""
" virtual_host=\"%s\""
" auth_data=\"%pp\""
" instance=\"%pp\""
" trace=\"%i\""
" timeout=\"%i\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, host, virtual_host, auth_data, instance, trace, timeout, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_NEW)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_DESTROY)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_AUTH_PLAIN)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_WAIT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SET_SILENT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SET_TIMEOUT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_SILENT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_ALIVE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_ERROR_TEXT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_VERSION_MAJOR)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_VERSION_MINOR)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_CHANNEL_MAX)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_FRAME_MAX)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_HEARTBEAT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_KNOWN_HOSTS)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_REPLY_CODE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_REPLY_TEXT)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_CLASS_ID)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_GET_METHOD_ID)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_INITIALISE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_TERMINATE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SELFTEST)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_SHOW)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_ALLOC)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_FREE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_READ_LOCK)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_WRITE_LOCK)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_UNLOCK)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_ANIMATE)   || defined (BASE_TRACE_AMQ_CLIENT_CONNECTION_NEW_IN_SCOPE) )
void
amq_client_connection_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "auth plain"; break;
        case 4: method_name = "wait"; break;
        case 5: method_name = "set silent"; break;
        case 6: method_name = "set timeout"; break;
        case 7: method_name = "get silent"; break;
        case 8: method_name = "get alive"; break;
        case 9: method_name = "get error text"; break;
        case 10: method_name = "get version_major"; break;
        case 11: method_name = "get version_minor"; break;
        case 12: method_name = "get channel_max"; break;
        case 13: method_name = "get frame_max"; break;
        case 14: method_name = "get heartbeat"; break;
        case 15: method_name = "get known_hosts"; break;
        case 16: method_name = "get reply_code"; break;
        case 17: method_name = "get reply_text"; break;
        case 18: method_name = "get class_id"; break;
        case 19: method_name = "get method_id"; break;
        case 20: method_name = "initialise"; break;
        case 21: method_name = "terminate"; break;
        case 22: method_name = "selftest"; break;
        case 23: method_name = "show"; break;
        case 24: method_name = "destroy public"; break;
        case 25: method_name = "alloc"; break;
        case 26: method_name = "free"; break;
        case 27: method_name = "read lock"; break;
        case 28: method_name = "write lock"; break;
        case 29: method_name = "unlock"; break;
        case 30: method_name = "cache initialise"; break;
        case 31: method_name = "cache purge"; break;
        case 32: method_name = "cache terminate"; break;
        case 33: method_name = "animate"; break;
        case 34: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_client_connection %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

/*  Waits for methods from the protocol agent.  If the blocking argument
    is true, returns only when receiving a synchronous reply method.  If not,
    returns when any incoming method is received.  Returns 0 if ok, -1 if
    the connection is closed or a blocking wait timed-out.
 */
static int
s_wait_for_methods (
    amq_client_connection_t *self,
    int timeout,
    Bool blocking)
{
    smt_method_t
        *smt_method = NULL;
    amq_client_method_t
        *proto_method;
    int
        rc = 0;                         //  OK by default

    FOREVER {
        smt_method_destroy (&smt_method);
        smt_method_queue_wait (self->method_queue, timeout);
        smt_method = smt_method_queue_pop (self->method_queue);
        //  If we don't have a method, we timed-out
        if (!smt_method) {
            if (blocking) {
                self->error_text = "No reply received - timeout";
                rc = -1;
            }
            break;
        }
        else
        //  ALMOST means we should wait for the next method...
        if (smt_method->result == AMQ_CLIENT_REPLY_ALMOST) {
            proto_method = (amq_client_method_t *) smt_method->data;
            if (proto_method)
                amq_client_method_execute (proto_method, self, NULL);
        }
        else
        //  INTERN is an internal synchronisation from the agent
        if (smt_method->result == AMQ_CLIENT_REPLY_INTERN)
            break;                      //  We can return to caller
        else
        //  METHOD means the agent is sending us either:
        //    - a sync method, which is a reply to a sync request
        //    - an async method, which we want to process and then continue
        //
        //  We always stop when we get a sync method. If we have an async
        //  method, we stop only if the queue is empty and we're not blocking.
        //  Blocking means we want a sync method within the timeout.
        //
        if (smt_method->result == AMQ_CLIENT_REPLY_METHOD) {
            proto_method = (amq_client_method_t *) smt_method->data;
            if (proto_method) {
                amq_client_method_execute (proto_method, self, NULL);
                if (proto_method->sync)
                    break;              //  Got synchronous method, end
                else
                if (smt_method_queue_isempty (self->method_queue) && !blocking)
                    break;              //  Got final async method but not blocking
            }
            else
                break;                  //  Synchronisation from agent
        }
        else
        if (smt_method->result == AMQ_CLIENT_REPLY_CLOSED) {
            self->alive = FALSE;        //  Connection is closed
            rc = -1;                    //  Signal connection is closed
            break;
        }
        else {
            self->error_text = "Internal error - invalid reply method from protocol agent";
            icl_console_print ("E: invalid reply result %d", smt_method->result);
        }
    }
    smt_method_destroy (&smt_method);
    return (rc);
}

//  Embed the version information in the resulting binary                      

char *amq_client_connection_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_client_connection_component  = "amq_client_connection ";
char *amq_client_connection_version  = "1.0 ";
char *amq_client_connection_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_client_connection_filename  = "amq_client_connection.icl ";
char *amq_client_connection_builddate  = "2010/10/06 ";
char *amq_client_connection_version_end  = "VeRsIoNeNd:ipc";

