/*---------------------------------------------------------------------------
    amq_client_method.c - amq_client_method component

This class holds a method.  All protocol methods are held in a single
union that can be processed as a single entity.
    Generated from amq_client_method.icl by icl_gen using GSL/4.
    
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
#include "amq_client_method.h"          //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_client_method_t

//  Shorthands for class methods                                               

#define self_new            amq_client_method_new
#define self_annihilate     amq_client_method_annihilate
#define self_initialise     amq_client_method_initialise
#define self_terminate      amq_client_method_terminate
#define self_new_connection_start_ok  amq_client_method_new_connection_start_ok
#define self_new_connection_secure_ok  amq_client_method_new_connection_secure_ok
#define self_new_connection_tune_ok  amq_client_method_new_connection_tune_ok
#define self_new_connection_open  amq_client_method_new_connection_open
#define self_new_connection_close  amq_client_method_new_connection_close
#define self_new_connection_close_ok  amq_client_method_new_connection_close_ok
#define self_new_channel_open  amq_client_method_new_channel_open
#define self_new_channel_flow  amq_client_method_new_channel_flow
#define self_new_channel_flow_ok  amq_client_method_new_channel_flow_ok
#define self_new_channel_close  amq_client_method_new_channel_close
#define self_new_channel_close_ok  amq_client_method_new_channel_close_ok
#define self_new_exchange_declare  amq_client_method_new_exchange_declare
#define self_new_exchange_delete  amq_client_method_new_exchange_delete
#define self_new_queue_declare  amq_client_method_new_queue_declare
#define self_new_queue_bind  amq_client_method_new_queue_bind
#define self_new_queue_purge  amq_client_method_new_queue_purge
#define self_new_queue_delete  amq_client_method_new_queue_delete
#define self_new_queue_unbind  amq_client_method_new_queue_unbind
#define self_new_basic_qos  amq_client_method_new_basic_qos
#define self_new_basic_consume  amq_client_method_new_basic_consume
#define self_new_basic_cancel  amq_client_method_new_basic_cancel
#define self_new_basic_publish  amq_client_method_new_basic_publish
#define self_new_basic_get  amq_client_method_new_basic_get
#define self_new_basic_ack  amq_client_method_new_basic_ack
#define self_new_basic_reject  amq_client_method_new_basic_reject
#define self_new_direct_put  amq_client_method_new_direct_put
#define self_new_direct_get  amq_client_method_new_direct_get
#define self_encode         amq_client_method_encode
#define self_decode         amq_client_method_decode
#define self_dump           amq_client_method_dump
#define self_execute        amq_client_method_execute
#define self_selftest       amq_client_method_selftest
#define self_show           amq_client_method_show
#define self_destroy        amq_client_method_destroy
#define self_alloc          amq_client_method_alloc
#define self_free           amq_client_method_free
#define self_link           amq_client_method_link
#define self_unlink         amq_client_method_unlink
#define self_cache_initialise  amq_client_method_cache_initialise
#define self_cache_purge    amq_client_method_cache_purge
#define self_cache_terminate  amq_client_method_cache_terminate
#define self_animate        amq_client_method_animate
#define self_new_in_scope   amq_client_method_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW))
static icl_stats_t *s_amq_client_method_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_DESTROY))
static icl_stats_t *s_amq_client_method_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_INITIALISE))
static icl_stats_t *s_amq_client_method_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_TERMINATE))
static icl_stats_t *s_amq_client_method_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_START_OK))
static icl_stats_t *s_amq_client_method_new_connection_start_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_SECURE_OK))
static icl_stats_t *s_amq_client_method_new_connection_secure_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_TUNE_OK))
static icl_stats_t *s_amq_client_method_new_connection_tune_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_OPEN))
static icl_stats_t *s_amq_client_method_new_connection_open_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE))
static icl_stats_t *s_amq_client_method_new_connection_close_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE_OK))
static icl_stats_t *s_amq_client_method_new_connection_close_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CHANNEL_OPEN))
static icl_stats_t *s_amq_client_method_new_channel_open_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW))
static icl_stats_t *s_amq_client_method_new_channel_flow_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW_OK))
static icl_stats_t *s_amq_client_method_new_channel_flow_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE))
static icl_stats_t *s_amq_client_method_new_channel_close_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE_OK))
static icl_stats_t *s_amq_client_method_new_channel_close_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DECLARE))
static icl_stats_t *s_amq_client_method_new_exchange_declare_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DELETE))
static icl_stats_t *s_amq_client_method_new_exchange_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_QUEUE_DECLARE))
static icl_stats_t *s_amq_client_method_new_queue_declare_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_QUEUE_BIND))
static icl_stats_t *s_amq_client_method_new_queue_bind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_QUEUE_PURGE))
static icl_stats_t *s_amq_client_method_new_queue_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_QUEUE_DELETE))
static icl_stats_t *s_amq_client_method_new_queue_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_QUEUE_UNBIND))
static icl_stats_t *s_amq_client_method_new_queue_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_QOS))
static icl_stats_t *s_amq_client_method_new_basic_qos_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_CONSUME))
static icl_stats_t *s_amq_client_method_new_basic_consume_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_CANCEL))
static icl_stats_t *s_amq_client_method_new_basic_cancel_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_PUBLISH))
static icl_stats_t *s_amq_client_method_new_basic_publish_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_GET))
static icl_stats_t *s_amq_client_method_new_basic_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_ACK))
static icl_stats_t *s_amq_client_method_new_basic_ack_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_REJECT))
static icl_stats_t *s_amq_client_method_new_basic_reject_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_DIRECT_PUT))
static icl_stats_t *s_amq_client_method_new_direct_put_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_DIRECT_GET))
static icl_stats_t *s_amq_client_method_new_direct_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_ENCODE))
static icl_stats_t *s_amq_client_method_encode_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_DECODE))
static icl_stats_t *s_amq_client_method_decode_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_DUMP))
static icl_stats_t *s_amq_client_method_dump_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_EXECUTE))
static icl_stats_t *s_amq_client_method_execute_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_SELFTEST))
static icl_stats_t *s_amq_client_method_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_SHOW))
static icl_stats_t *s_amq_client_method_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_DESTROY_PUBLIC))
static icl_stats_t *s_amq_client_method_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_ALLOC))
static icl_stats_t *s_amq_client_method_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_FREE))
static icl_stats_t *s_amq_client_method_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_LINK))
static icl_stats_t *s_amq_client_method_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_UNLINK))
static icl_stats_t *s_amq_client_method_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_CACHE_INITIALISE))
static icl_stats_t *s_amq_client_method_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_CACHE_PURGE))
static icl_stats_t *s_amq_client_method_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_CACHE_TERMINATE))
static icl_stats_t *s_amq_client_method_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_ANIMATE))
static icl_stats_t *s_amq_client_method_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_IN_SCOPE))
static icl_stats_t *s_amq_client_method_new_in_scope_stats = NULL;
#endif
#define amq_client_method_annihilate(self)  amq_client_method_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_client_method_annihilate_ (
amq_client_method_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_client_method_initialise (
void);

static void
    amq_client_method_terminate (
void);

#define amq_client_method_alloc()       amq_client_method_alloc_ (__FILE__, __LINE__)
static amq_client_method_t *
    amq_client_method_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_client_method_free(self)    amq_client_method_free_ (self, __FILE__, __LINE__)
static void
    amq_client_method_free_ (
amq_client_method_t * self,             //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_client_method_cache_initialise (
void);

static void
    amq_client_method_cache_purge (
void);

static void
    amq_client_method_cache_terminate (
void);

Bool
    amq_client_method_animating = TRUE;  //  Animation enabled by default
static Bool
    s_amq_client_method_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_client_method_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static ipr_regexp_t
    *s_regexp_connection_virtual_host = NULL;
static ipr_regexp_t
    *s_regexp_exchange_exchange = NULL;
static ipr_regexp_t
    *s_regexp_exchange_type = NULL;
static ipr_regexp_t
    *s_regexp_queue_queue = NULL;
/*  -------------------------------------------------------------------------
    amq_client_method_new

    Type: Component method
    Creates and initialises a new amq_client_method_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_client_method_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW))
    icl_trace_record (NULL, amq_client_method_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW))
    icl_stats_inc ("amq_client_method_new", &s_amq_client_method_new_stats);
#endif

if (!s_amq_client_method_active)
    self_initialise ();
    self = amq_client_method_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CLIENT_METHOD_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_METHOD)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_client_method_show_);
#endif

self->class_id  = 0;
self->method_id = 0;
self->name      = NULL;
self->sync      = FALSE;
self->content   = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_finish"
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
    amq_client_method_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_method_annihilate_ (
    amq_client_method_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_METHOD)
    int
        history_last;
#endif

    amq_client_method_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_DESTROY))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DESTROY))
    icl_trace_record (NULL, amq_client_method_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_DESTROY))
    icl_stats_inc ("amq_client_method_annihilate", &s_amq_client_method_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_METHOD)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = self->links;
#endif

    AMQ_CLIENT_METHOD_ASSERT_SANE (self);

if (self->class_id == AMQ_CLIENT_CONNECTION) {
    if (self->method_id == AMQ_CLIENT_CONNECTION_START) {
        icl_longstr_destroy (&self->payload.connection_start.server_properties);
        icl_longstr_destroy (&self->payload.connection_start.mechanisms);
        icl_longstr_destroy (&self->payload.connection_start.locales);
    }
    else
    if (self->method_id == AMQ_CLIENT_CONNECTION_START_OK) {
        icl_longstr_destroy (&self->payload.connection_start_ok.client_properties);
        icl_longstr_destroy (&self->payload.connection_start_ok.response);
    }
    else
    if (self->method_id == AMQ_CLIENT_CONNECTION_SECURE) {
        icl_longstr_destroy (&self->payload.connection_secure.challenge);
    }
    else
    if (self->method_id == AMQ_CLIENT_CONNECTION_SECURE_OK) {
        icl_longstr_destroy (&self->payload.connection_secure_ok.response);
    }
}
else
if (self->class_id == AMQ_CLIENT_CHANNEL) {
    if (self->method_id == AMQ_CLIENT_CHANNEL_OPEN_OK) {
        icl_longstr_destroy (&self->payload.channel_open_ok.channel_id);
    }
}
else
if (self->class_id == AMQ_CLIENT_EXCHANGE) {
    if (self->method_id == AMQ_CLIENT_EXCHANGE_DECLARE) {
        icl_longstr_destroy (&self->payload.exchange_declare.arguments);
    }
}
else
if (self->class_id == AMQ_CLIENT_QUEUE) {
    if (self->method_id == AMQ_CLIENT_QUEUE_DECLARE) {
        icl_longstr_destroy (&self->payload.queue_declare.arguments);
    }
    else
    if (self->method_id == AMQ_CLIENT_QUEUE_BIND) {
        icl_longstr_destroy (&self->payload.queue_bind.arguments);
    }
    else
    if (self->method_id == AMQ_CLIENT_QUEUE_UNBIND) {
        icl_longstr_destroy (&self->payload.queue_unbind.arguments);
    }
}
else
if (self->class_id == AMQ_CLIENT_BASIC) {
    amq_content_basic_unlink ((amq_content_basic_t **) &self->content);
    if (self->method_id == AMQ_CLIENT_BASIC_CONSUME) {
        icl_longstr_destroy (&self->payload.basic_consume.arguments);
    }
}
else
assert (!self->content);            //  Non-destroyed content = error

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DESTROY))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_DESTROY))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_method_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_method_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_INITIALISE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_INITIALISE))
    icl_trace_record (NULL, amq_client_method_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_INITIALISE))
    icl_stats_inc ("amq_client_method_initialise", &s_amq_client_method_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_client_method_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_client_method_mutex)
            s_amq_client_method_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_client_method_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_client_method_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

s_regexp_connection_virtual_host = ipr_regexp_new ("^[a-zA-Z0-9/-_]+$");
s_regexp_exchange_exchange = ipr_regexp_new ("^[a-zA-Z0-9-_.:/]+$");
s_regexp_exchange_type = ipr_regexp_new ("^[a-zA-Z0-9-_.:/]+$");
s_regexp_queue_queue = ipr_regexp_new ("^[a-zA-Z0-9-_.:/]*$");
            s_amq_client_method_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_client_method_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_INITIALISE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_INITIALISE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_initialise_finish"
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
    amq_client_method_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_method_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_TERMINATE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_TERMINATE))
    icl_trace_record (NULL, amq_client_method_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_TERMINATE))
    icl_stats_inc ("amq_client_method_terminate", &s_amq_client_method_terminate_stats);
#endif

if (s_amq_client_method_active) {

ipr_regexp_destroy (&s_regexp_connection_virtual_host);
ipr_regexp_destroy (&s_regexp_exchange_exchange);
ipr_regexp_destroy (&s_regexp_exchange_type);
ipr_regexp_destroy (&s_regexp_queue_queue);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_client_method_mutex);
#endif
        s_amq_client_method_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_TERMINATE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_TERMINATE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_terminate_finish"
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
    amq_client_method_new_connection_start_ok

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_connection_start_ok (
    icl_longstr_t * client_properties,   //  client properties
    char * mechanism,                   //  selected security mechanism
    icl_longstr_t * response,           //  security response data
    char * locale                       //  selected message locale
)
{
amq_client_connection_start_ok_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_START_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_start_ok_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" client_properties=\"%pp\""
" mechanism=\"%s\""
" response=\"%pp\""
" locale=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, client_properties, mechanism, response, locale);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_START_OK))
    icl_trace_record (NULL, amq_client_method_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_START_OK))
    icl_stats_inc ("amq_client_method_new_connection_start_ok", &s_amq_client_method_new_connection_start_ok_stats);
#endif

//
self   = self_new ();
method = &self->payload.connection_start_ok;
self->class_id  = AMQ_CLIENT_CONNECTION;
self->method_id = AMQ_CLIENT_CONNECTION_START_OK;
self->name      = "connection.start_ok";

//  Copy supplied values to method object
icl_shortstr_cpy (method->mechanism,     mechanism);
icl_shortstr_cpy (method->locale,        locale);
if (client_properties)
    method->client_properties  = icl_longstr_dup (client_properties);
else
    method->client_properties  = NULL;
if (response)
    method->response    = icl_longstr_dup (response);
else
    method->response    = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_START_OK))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_START_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_start_ok_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" client_properties=\"%pp\""
" mechanism=\"%s\""
" response=\"%pp\""
" locale=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, client_properties, mechanism, response, locale, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_connection_secure_ok

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_connection_secure_ok (
    icl_longstr_t * response            //  security response data
)
{
amq_client_connection_secure_ok_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_SECURE_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_secure_ok_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" response=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, response);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_SECURE_OK))
    icl_trace_record (NULL, amq_client_method_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_SECURE_OK))
    icl_stats_inc ("amq_client_method_new_connection_secure_ok", &s_amq_client_method_new_connection_secure_ok_stats);
#endif

//
self   = self_new ();
method = &self->payload.connection_secure_ok;
self->class_id  = AMQ_CLIENT_CONNECTION;
self->method_id = AMQ_CLIENT_CONNECTION_SECURE_OK;
self->name      = "connection.secure_ok";

//  Copy supplied values to method object
if (response)
    method->response    = icl_longstr_dup (response);
else
    method->response    = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_SECURE_OK))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_SECURE_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_secure_ok_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" response=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, response, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_connection_tune_ok

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_connection_tune_ok (
    int channel_max,                    //  negotiated maximum channels
    qbyte frame_max,                    //  negotiated maximum frame size
    int heartbeat                       //  desired heartbeat delay
)
{
amq_client_connection_tune_ok_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_TUNE_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_tune_ok_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" channel_max=\"%i\""
" frame_max=\"%lu\""
" heartbeat=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, channel_max, frame_max, heartbeat);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_TUNE_OK))
    icl_trace_record (NULL, amq_client_method_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_TUNE_OK))
    icl_stats_inc ("amq_client_method_new_connection_tune_ok", &s_amq_client_method_new_connection_tune_ok_stats);
#endif

//
self   = self_new ();
method = &self->payload.connection_tune_ok;
self->class_id  = AMQ_CLIENT_CONNECTION;
self->method_id = AMQ_CLIENT_CONNECTION_TUNE_OK;
self->name      = "connection.tune_ok";

//  Copy supplied values to method object
method->channel_max     = (dbyte) channel_max;
method->frame_max       = frame_max;
method->heartbeat       = (dbyte) heartbeat;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_TUNE_OK))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_TUNE_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_tune_ok_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" channel_max=\"%i\""
" frame_max=\"%lu\""
" heartbeat=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, channel_max, frame_max, heartbeat, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_connection_open

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_connection_open (
    char * virtual_host,                //  virtual host name
    char * capabilities,                //  required capabilities
    Bool insist                         //  insist on connecting to server
)
{
amq_client_connection_open_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_OPEN))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_open_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" virtual_host=\"%s\""
" capabilities=\"%s\""
" insist=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, virtual_host, capabilities, insist);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_OPEN))
    icl_trace_record (NULL, amq_client_method_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_OPEN))
    icl_stats_inc ("amq_client_method_new_connection_open", &s_amq_client_method_new_connection_open_stats);
#endif

//
self   = self_new ();
method = &self->payload.connection_open;
self->class_id  = AMQ_CLIENT_CONNECTION;
self->method_id = AMQ_CLIENT_CONNECTION_OPEN;
self->name      = "connection.open";

//  Copy supplied values to method object
method->insist          = insist;
icl_shortstr_cpy (method->virtual_host,  virtual_host);
icl_shortstr_cpy (method->capabilities,  capabilities);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_OPEN))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_OPEN))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_open_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" virtual_host=\"%s\""
" capabilities=\"%s\""
" insist=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, virtual_host, capabilities, insist, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_connection_close

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_connection_close (
    int reply_code,                     //  reply code from server
    char * reply_text,                  //  localised reply text
    int class_id,                       //  failing method class
    int method_id                       //  failing method ID
)
{
amq_client_connection_close_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_close_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" reply_code=\"%i\""
" reply_text=\"%s\""
" class_id=\"%i\""
" method_id=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, reply_code, reply_text, class_id, method_id);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE))
    icl_trace_record (NULL, amq_client_method_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE))
    icl_stats_inc ("amq_client_method_new_connection_close", &s_amq_client_method_new_connection_close_stats);
#endif

//
self   = self_new ();
method = &self->payload.connection_close;
self->class_id  = AMQ_CLIENT_CONNECTION;
self->method_id = AMQ_CLIENT_CONNECTION_CLOSE;
self->name      = "connection.close";

//  Copy supplied values to method object
method->reply_code      = (dbyte) reply_code;
method->class_id        = (dbyte) class_id;
method->method_id       = (dbyte) method_id;
icl_shortstr_cpy (method->reply_text,    reply_text);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_close_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" reply_code=\"%i\""
" reply_text=\"%s\""
" class_id=\"%i\""
" method_id=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, reply_code, reply_text, class_id, method_id, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_connection_close_ok

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_connection_close_ok (
void)
{
amq_client_connection_close_ok_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_close_ok_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE_OK))
    icl_trace_record (NULL, amq_client_method_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE_OK))
    icl_stats_inc ("amq_client_method_new_connection_close_ok", &s_amq_client_method_new_connection_close_ok_stats);
#endif

//
self   = self_new ();
method = &self->payload.connection_close_ok;
self->class_id  = AMQ_CLIENT_CONNECTION;
self->method_id = AMQ_CLIENT_CONNECTION_CLOSE_OK;
self->name      = "connection.close_ok";

//  Copy supplied values to method object
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE_OK))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_connection_close_ok_finish"
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


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_channel_open

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_channel_open (
    char * out_of_band                  //  out-of-band settings
)
{
amq_client_channel_open_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CHANNEL_OPEN))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_channel_open_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" out_of_band=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, out_of_band);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_OPEN))
    icl_trace_record (NULL, amq_client_method_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CHANNEL_OPEN))
    icl_stats_inc ("amq_client_method_new_channel_open", &s_amq_client_method_new_channel_open_stats);
#endif

//
self   = self_new ();
method = &self->payload.channel_open;
self->class_id  = AMQ_CLIENT_CHANNEL;
self->method_id = AMQ_CLIENT_CHANNEL_OPEN;
self->name      = "channel.open";

//  Copy supplied values to method object
icl_shortstr_cpy (method->out_of_band,   out_of_band);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_OPEN))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CHANNEL_OPEN))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_channel_open_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" out_of_band=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, out_of_band, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_channel_flow

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_channel_flow (
    Bool active                         //  start/stop content frames
)
{
amq_client_channel_flow_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_channel_flow_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" active=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, active);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW))
    icl_trace_record (NULL, amq_client_method_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW))
    icl_stats_inc ("amq_client_method_new_channel_flow", &s_amq_client_method_new_channel_flow_stats);
#endif

//
self   = self_new ();
method = &self->payload.channel_flow;
self->class_id  = AMQ_CLIENT_CHANNEL;
self->method_id = AMQ_CLIENT_CHANNEL_FLOW;
self->name      = "channel.flow";

//  Copy supplied values to method object
method->active          = active;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_channel_flow_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" active=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, active, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_channel_flow_ok

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_channel_flow_ok (
    Bool active                         //  current flow setting
)
{
amq_client_channel_flow_ok_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_channel_flow_ok_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" active=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, active);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW_OK))
    icl_trace_record (NULL, amq_client_method_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW_OK))
    icl_stats_inc ("amq_client_method_new_channel_flow_ok", &s_amq_client_method_new_channel_flow_ok_stats);
#endif

//
self   = self_new ();
method = &self->payload.channel_flow_ok;
self->class_id  = AMQ_CLIENT_CHANNEL;
self->method_id = AMQ_CLIENT_CHANNEL_FLOW_OK;
self->name      = "channel.flow_ok";

//  Copy supplied values to method object
method->active          = active;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW_OK))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_channel_flow_ok_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" active=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, active, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_channel_close

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_channel_close (
    int reply_code,                     //  reply code from server
    char * reply_text,                  //  localised reply text
    int class_id,                       //  failing method class
    int method_id                       //  failing method ID
)
{
amq_client_channel_close_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_channel_close_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" reply_code=\"%i\""
" reply_text=\"%s\""
" class_id=\"%i\""
" method_id=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, reply_code, reply_text, class_id, method_id);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE))
    icl_trace_record (NULL, amq_client_method_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE))
    icl_stats_inc ("amq_client_method_new_channel_close", &s_amq_client_method_new_channel_close_stats);
#endif

//
self   = self_new ();
method = &self->payload.channel_close;
self->class_id  = AMQ_CLIENT_CHANNEL;
self->method_id = AMQ_CLIENT_CHANNEL_CLOSE;
self->name      = "channel.close";

//  Copy supplied values to method object
method->reply_code      = (dbyte) reply_code;
method->class_id        = (dbyte) class_id;
method->method_id       = (dbyte) method_id;
icl_shortstr_cpy (method->reply_text,    reply_text);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_channel_close_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" reply_code=\"%i\""
" reply_text=\"%s\""
" class_id=\"%i\""
" method_id=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, reply_code, reply_text, class_id, method_id, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_channel_close_ok

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_channel_close_ok (
void)
{
amq_client_channel_close_ok_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_channel_close_ok_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE_OK))
    icl_trace_record (NULL, amq_client_method_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE_OK))
    icl_stats_inc ("amq_client_method_new_channel_close_ok", &s_amq_client_method_new_channel_close_ok_stats);
#endif

//
self   = self_new ();
method = &self->payload.channel_close_ok;
self->class_id  = AMQ_CLIENT_CHANNEL;
self->method_id = AMQ_CLIENT_CHANNEL_CLOSE_OK;
self->name      = "channel.close_ok";

//  Copy supplied values to method object
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE_OK))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE_OK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_channel_close_ok_finish"
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


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_exchange_declare

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_exchange_declare (
    int ticket,                         //  access ticket granted by server
    char * exchange,                    //  exchange name
    char * type,                        //  exchange type
    Bool passive,                       //  do not create exchange
    Bool durable,                       //  request a durable exchange
    Bool auto_delete,                   //  auto-delete when unused
    Bool internal,                      //  create internal exchange
    Bool nowait,                        //  do not send a reply method
    icl_longstr_t * arguments           //  arguments for declaration
)
{
amq_client_exchange_declare_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DECLARE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_exchange_declare_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" exchange=\"%s\""
" type=\"%s\""
" passive=\"%i\""
" durable=\"%i\""
" auto_delete=\"%i\""
" internal=\"%i\""
" nowait=\"%i\""
" arguments=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, exchange, type, passive, durable, auto_delete, internal, nowait, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DECLARE))
    icl_trace_record (NULL, amq_client_method_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DECLARE))
    icl_stats_inc ("amq_client_method_new_exchange_declare", &s_amq_client_method_new_exchange_declare_stats);
#endif

//
self   = self_new ();
method = &self->payload.exchange_declare;
self->class_id  = AMQ_CLIENT_EXCHANGE;
self->method_id = AMQ_CLIENT_EXCHANGE_DECLARE;
self->name      = "exchange.declare";

//  Copy supplied values to method object
method->ticket          = (dbyte) ticket;
method->passive         = passive;
method->durable         = durable;
method->auto_delete     = auto_delete;
method->internal        = internal;
method->nowait          = nowait;
icl_shortstr_cpy (method->exchange,      exchange);
icl_shortstr_cpy (method->type,          type);
if (arguments)
    method->arguments   = icl_longstr_dup (arguments);
else
    method->arguments   = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DECLARE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DECLARE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_exchange_declare_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" exchange=\"%s\""
" type=\"%s\""
" passive=\"%i\""
" durable=\"%i\""
" auto_delete=\"%i\""
" internal=\"%i\""
" nowait=\"%i\""
" arguments=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, exchange, type, passive, durable, auto_delete, internal, nowait, arguments, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_exchange_delete

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_exchange_delete (
    int ticket,                         //  access ticket granted by server
    char * exchange,                    //  exchange name
    Bool if_unused,                     //  delete only if unused
    Bool nowait                         //  do not send a reply method
)
{
amq_client_exchange_delete_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DELETE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_exchange_delete_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" exchange=\"%s\""
" if_unused=\"%i\""
" nowait=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, exchange, if_unused, nowait);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DELETE))
    icl_trace_record (NULL, amq_client_method_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DELETE))
    icl_stats_inc ("amq_client_method_new_exchange_delete", &s_amq_client_method_new_exchange_delete_stats);
#endif

//
self   = self_new ();
method = &self->payload.exchange_delete;
self->class_id  = AMQ_CLIENT_EXCHANGE;
self->method_id = AMQ_CLIENT_EXCHANGE_DELETE;
self->name      = "exchange.delete";

//  Copy supplied values to method object
method->ticket          = (dbyte) ticket;
method->if_unused       = if_unused;
method->nowait          = nowait;
icl_shortstr_cpy (method->exchange,      exchange);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DELETE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DELETE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_exchange_delete_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" exchange=\"%s\""
" if_unused=\"%i\""
" nowait=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, exchange, if_unused, nowait, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_queue_declare

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_queue_declare (
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    Bool passive,                       //  do not create queue
    Bool durable,                       //  request a durable queue
    Bool exclusive,                     //  request an exclusive queue
    Bool auto_delete,                   //  auto-delete queue when unused
    Bool nowait,                        //  do not send a reply method
    icl_longstr_t * arguments           //  arguments for declaration
)
{
amq_client_queue_declare_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_QUEUE_DECLARE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_queue_declare_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" passive=\"%i\""
" durable=\"%i\""
" exclusive=\"%i\""
" auto_delete=\"%i\""
" nowait=\"%i\""
" arguments=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, passive, durable, exclusive, auto_delete, nowait, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_DECLARE))
    icl_trace_record (NULL, amq_client_method_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_QUEUE_DECLARE))
    icl_stats_inc ("amq_client_method_new_queue_declare", &s_amq_client_method_new_queue_declare_stats);
#endif

//
self   = self_new ();
method = &self->payload.queue_declare;
self->class_id  = AMQ_CLIENT_QUEUE;
self->method_id = AMQ_CLIENT_QUEUE_DECLARE;
self->name      = "queue.declare";

//  Copy supplied values to method object
method->ticket          = (dbyte) ticket;
method->passive         = passive;
method->durable         = durable;
method->exclusive       = exclusive;
method->auto_delete     = auto_delete;
method->nowait          = nowait;
icl_shortstr_cpy (method->queue,         queue);
if (arguments)
    method->arguments   = icl_longstr_dup (arguments);
else
    method->arguments   = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_DECLARE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_QUEUE_DECLARE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_queue_declare_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" passive=\"%i\""
" durable=\"%i\""
" exclusive=\"%i\""
" auto_delete=\"%i\""
" nowait=\"%i\""
" arguments=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, passive, durable, exclusive, auto_delete, nowait, arguments, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_queue_bind

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_queue_bind (
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    char * exchange,                    //  exchange name
    char * routing_key,                 //  message routing key
    Bool nowait,                        //  do not send a reply method
    icl_longstr_t * arguments           //  arguments for binding
)
{
amq_client_queue_bind_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_QUEUE_BIND))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_queue_bind_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" exchange=\"%s\""
" routing_key=\"%s\""
" nowait=\"%i\""
" arguments=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, exchange, routing_key, nowait, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_BIND))
    icl_trace_record (NULL, amq_client_method_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_QUEUE_BIND))
    icl_stats_inc ("amq_client_method_new_queue_bind", &s_amq_client_method_new_queue_bind_stats);
#endif

//
self   = self_new ();
method = &self->payload.queue_bind;
self->class_id  = AMQ_CLIENT_QUEUE;
self->method_id = AMQ_CLIENT_QUEUE_BIND;
self->name      = "queue.bind";

//  Copy supplied values to method object
method->ticket          = (dbyte) ticket;
method->nowait          = nowait;
icl_shortstr_cpy (method->queue,         queue);
icl_shortstr_cpy (method->exchange,      exchange);
icl_shortstr_cpy (method->routing_key,   routing_key);
if (arguments)
    method->arguments   = icl_longstr_dup (arguments);
else
    method->arguments   = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_BIND))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_QUEUE_BIND))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_queue_bind_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" exchange=\"%s\""
" routing_key=\"%s\""
" nowait=\"%i\""
" arguments=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, exchange, routing_key, nowait, arguments, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_queue_purge

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_queue_purge (
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    Bool nowait                         //  do not send a reply method
)
{
amq_client_queue_purge_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_QUEUE_PURGE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_queue_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" nowait=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, nowait);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_PURGE))
    icl_trace_record (NULL, amq_client_method_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_QUEUE_PURGE))
    icl_stats_inc ("amq_client_method_new_queue_purge", &s_amq_client_method_new_queue_purge_stats);
#endif

//
self   = self_new ();
method = &self->payload.queue_purge;
self->class_id  = AMQ_CLIENT_QUEUE;
self->method_id = AMQ_CLIENT_QUEUE_PURGE;
self->name      = "queue.purge";

//  Copy supplied values to method object
method->ticket          = (dbyte) ticket;
method->nowait          = nowait;
icl_shortstr_cpy (method->queue,         queue);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_PURGE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_QUEUE_PURGE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_queue_purge_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" nowait=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, nowait, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_queue_delete

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_queue_delete (
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    Bool if_unused,                     //  delete only if unused
    Bool if_empty,                      //  delete only if empty
    Bool nowait                         //  do not send a reply method
)
{
amq_client_queue_delete_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_QUEUE_DELETE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_queue_delete_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" if_unused=\"%i\""
" if_empty=\"%i\""
" nowait=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, if_unused, if_empty, nowait);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_DELETE))
    icl_trace_record (NULL, amq_client_method_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_QUEUE_DELETE))
    icl_stats_inc ("amq_client_method_new_queue_delete", &s_amq_client_method_new_queue_delete_stats);
#endif

//
self   = self_new ();
method = &self->payload.queue_delete;
self->class_id  = AMQ_CLIENT_QUEUE;
self->method_id = AMQ_CLIENT_QUEUE_DELETE;
self->name      = "queue.delete";

//  Copy supplied values to method object
method->ticket          = (dbyte) ticket;
method->if_unused       = if_unused;
method->if_empty        = if_empty;
method->nowait          = nowait;
icl_shortstr_cpy (method->queue,         queue);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_DELETE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_QUEUE_DELETE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_queue_delete_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" if_unused=\"%i\""
" if_empty=\"%i\""
" nowait=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, if_unused, if_empty, nowait, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_queue_unbind

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_queue_unbind (
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    char * exchange,                    //  exchange name
    char * routing_key,                 //  message routing key
    Bool nowait,                        //  do not send a reply method
    icl_longstr_t * arguments           //  arguments for binding
)
{
amq_client_queue_unbind_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_QUEUE_UNBIND))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_queue_unbind_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" exchange=\"%s\""
" routing_key=\"%s\""
" nowait=\"%i\""
" arguments=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, exchange, routing_key, nowait, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_UNBIND))
    icl_trace_record (NULL, amq_client_method_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_QUEUE_UNBIND))
    icl_stats_inc ("amq_client_method_new_queue_unbind", &s_amq_client_method_new_queue_unbind_stats);
#endif

//
self   = self_new ();
method = &self->payload.queue_unbind;
self->class_id  = AMQ_CLIENT_QUEUE;
self->method_id = AMQ_CLIENT_QUEUE_UNBIND;
self->name      = "queue.unbind";

//  Copy supplied values to method object
method->ticket          = (dbyte) ticket;
method->nowait          = nowait;
icl_shortstr_cpy (method->queue,         queue);
icl_shortstr_cpy (method->exchange,      exchange);
icl_shortstr_cpy (method->routing_key,   routing_key);
if (arguments)
    method->arguments   = icl_longstr_dup (arguments);
else
    method->arguments   = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_UNBIND))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_QUEUE_UNBIND))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_queue_unbind_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" exchange=\"%s\""
" routing_key=\"%s\""
" nowait=\"%i\""
" arguments=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, exchange, routing_key, nowait, arguments, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_basic_qos

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_basic_qos (
    qbyte prefetch_size,                //  prefetch window in octets
    int prefetch_count,                 //  prefetch window in messages
    Bool global                         //  apply to entire connection
)
{
amq_client_basic_qos_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_QOS))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_qos_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" prefetch_size=\"%lu\""
" prefetch_count=\"%i\""
" global=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, prefetch_size, prefetch_count, global);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_QOS))
    icl_trace_record (NULL, amq_client_method_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_QOS))
    icl_stats_inc ("amq_client_method_new_basic_qos", &s_amq_client_method_new_basic_qos_stats);
#endif

//
self   = self_new ();
method = &self->payload.basic_qos;
self->class_id  = AMQ_CLIENT_BASIC;
self->method_id = AMQ_CLIENT_BASIC_QOS;
self->name      = "basic.qos";

//  Copy supplied values to method object
method->prefetch_size   = prefetch_size;
method->prefetch_count  = (dbyte) prefetch_count;
method->global          = global;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_QOS))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_QOS))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_qos_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" prefetch_size=\"%lu\""
" prefetch_count=\"%i\""
" global=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, prefetch_size, prefetch_count, global, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_basic_consume

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_basic_consume (
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    char * consumer_tag,                //  consumer tag
    Bool no_local,                      //  do not deliver own messages
    Bool no_ack,                        //  no acknowledgement needed
    Bool exclusive,                     //  request exclusive access
    Bool nowait,                        //  do not send a reply method
    icl_longstr_t * arguments           //  arguments for consume
)
{
amq_client_basic_consume_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_CONSUME))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_consume_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" consumer_tag=\"%s\""
" no_local=\"%i\""
" no_ack=\"%i\""
" exclusive=\"%i\""
" nowait=\"%i\""
" arguments=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, consumer_tag, no_local, no_ack, exclusive, nowait, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_CONSUME))
    icl_trace_record (NULL, amq_client_method_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_CONSUME))
    icl_stats_inc ("amq_client_method_new_basic_consume", &s_amq_client_method_new_basic_consume_stats);
#endif

//
self   = self_new ();
method = &self->payload.basic_consume;
self->class_id  = AMQ_CLIENT_BASIC;
self->method_id = AMQ_CLIENT_BASIC_CONSUME;
self->name      = "basic.consume";

//  Copy supplied values to method object
method->ticket          = (dbyte) ticket;
method->no_local        = no_local;
method->no_ack          = no_ack;
method->exclusive       = exclusive;
method->nowait          = nowait;
icl_shortstr_cpy (method->queue,         queue);
icl_shortstr_cpy (method->consumer_tag,  consumer_tag);
if (arguments)
    method->arguments   = icl_longstr_dup (arguments);
else
    method->arguments   = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_CONSUME))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_CONSUME))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_consume_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" consumer_tag=\"%s\""
" no_local=\"%i\""
" no_ack=\"%i\""
" exclusive=\"%i\""
" nowait=\"%i\""
" arguments=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, consumer_tag, no_local, no_ack, exclusive, nowait, arguments, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_basic_cancel

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_basic_cancel (
    char * consumer_tag,                //  consumer tag
    Bool nowait                         //  do not send a reply method
)
{
amq_client_basic_cancel_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_CANCEL))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_cancel_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" consumer_tag=\"%s\""
" nowait=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, consumer_tag, nowait);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_CANCEL))
    icl_trace_record (NULL, amq_client_method_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_CANCEL))
    icl_stats_inc ("amq_client_method_new_basic_cancel", &s_amq_client_method_new_basic_cancel_stats);
#endif

//
self   = self_new ();
method = &self->payload.basic_cancel;
self->class_id  = AMQ_CLIENT_BASIC;
self->method_id = AMQ_CLIENT_BASIC_CANCEL;
self->name      = "basic.cancel";

//  Copy supplied values to method object
method->nowait          = nowait;
icl_shortstr_cpy (method->consumer_tag,  consumer_tag);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_CANCEL))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_CANCEL))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_cancel_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" consumer_tag=\"%s\""
" nowait=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, consumer_tag, nowait, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_basic_publish

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_basic_publish (
    int ticket,                         //  access ticket granted by server
    char * exchange,                    //  exchange name
    char * routing_key,                 //  Message routing key
    Bool mandatory,                     //  indicate mandatory routing
    Bool immediate                      //  request immediate delivery
)
{
amq_client_basic_publish_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_PUBLISH))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_publish_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" exchange=\"%s\""
" routing_key=\"%s\""
" mandatory=\"%i\""
" immediate=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, exchange, routing_key, mandatory, immediate);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_PUBLISH))
    icl_trace_record (NULL, amq_client_method_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_PUBLISH))
    icl_stats_inc ("amq_client_method_new_basic_publish", &s_amq_client_method_new_basic_publish_stats);
#endif

//
self   = self_new ();
method = &self->payload.basic_publish;
self->class_id  = AMQ_CLIENT_BASIC;
self->method_id = AMQ_CLIENT_BASIC_PUBLISH;
self->name      = "basic.publish";

//  Copy supplied values to method object
method->ticket          = (dbyte) ticket;
method->mandatory       = mandatory;
method->immediate       = immediate;
icl_shortstr_cpy (method->exchange,      exchange);
icl_shortstr_cpy (method->routing_key,   routing_key);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_PUBLISH))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_PUBLISH))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_publish_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" exchange=\"%s\""
" routing_key=\"%s\""
" mandatory=\"%i\""
" immediate=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, exchange, routing_key, mandatory, immediate, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_basic_get

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_basic_get (
    int ticket,                         //  access ticket granted by server
    char * queue,                       //  queue name
    Bool no_ack                         //  no acknowledgement needed
)
{
amq_client_basic_get_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_GET))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_get_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" no_ack=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, no_ack);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_GET))
    icl_trace_record (NULL, amq_client_method_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_GET))
    icl_stats_inc ("amq_client_method_new_basic_get", &s_amq_client_method_new_basic_get_stats);
#endif

//
self   = self_new ();
method = &self->payload.basic_get;
self->class_id  = AMQ_CLIENT_BASIC;
self->method_id = AMQ_CLIENT_BASIC_GET;
self->name      = "basic.get";

//  Copy supplied values to method object
method->ticket          = (dbyte) ticket;
method->no_ack          = no_ack;
icl_shortstr_cpy (method->queue,         queue);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_GET))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_GET))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_get_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" ticket=\"%i\""
" queue=\"%s\""
" no_ack=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, ticket, queue, no_ack, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_basic_ack

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_basic_ack (
    int64_t delivery_tag,               //  server-assigned delivery tag
    Bool multiple                       //  acknowledge multiple messages
)
{
amq_client_basic_ack_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_ACK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_ack_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" delivery_tag=\"%lli\""
" multiple=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, delivery_tag, multiple);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_ACK))
    icl_trace_record (NULL, amq_client_method_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_ACK))
    icl_stats_inc ("amq_client_method_new_basic_ack", &s_amq_client_method_new_basic_ack_stats);
#endif

//
self   = self_new ();
method = &self->payload.basic_ack;
self->class_id  = AMQ_CLIENT_BASIC;
self->method_id = AMQ_CLIENT_BASIC_ACK;
self->name      = "basic.ack";

//  Copy supplied values to method object
method->delivery_tag    = delivery_tag;
method->multiple        = multiple;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_ACK))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_ACK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_ack_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" delivery_tag=\"%lli\""
" multiple=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, delivery_tag, multiple, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_basic_reject

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_basic_reject (
    int64_t delivery_tag,               //  server-assigned delivery tag
    Bool requeue                        //  requeue the message
)
{
amq_client_basic_reject_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_REJECT))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_reject_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" delivery_tag=\"%lli\""
" requeue=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, delivery_tag, requeue);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_REJECT))
    icl_trace_record (NULL, amq_client_method_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_BASIC_REJECT))
    icl_stats_inc ("amq_client_method_new_basic_reject", &s_amq_client_method_new_basic_reject_stats);
#endif

//
self   = self_new ();
method = &self->payload.basic_reject;
self->class_id  = AMQ_CLIENT_BASIC;
self->method_id = AMQ_CLIENT_BASIC_REJECT;
self->name      = "basic.reject";

//  Copy supplied values to method object
method->delivery_tag    = delivery_tag;
method->requeue         = requeue;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_REJECT))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_BASIC_REJECT))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_basic_reject_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" delivery_tag=\"%lli\""
" requeue=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, delivery_tag, requeue, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_direct_put

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_direct_put (
    char * sink                         //  Sink name
)
{
amq_client_direct_put_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_DIRECT_PUT))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_direct_put_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" sink=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, sink);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_DIRECT_PUT))
    icl_trace_record (NULL, amq_client_method_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_DIRECT_PUT))
    icl_stats_inc ("amq_client_method_new_direct_put", &s_amq_client_method_new_direct_put_stats);
#endif

//
self   = self_new ();
method = &self->payload.direct_put;
self->class_id  = AMQ_CLIENT_DIRECT;
self->method_id = AMQ_CLIENT_DIRECT_PUT;
self->name      = "direct.put";

//  Copy supplied values to method object
icl_shortstr_cpy (method->sink,          sink);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_DIRECT_PUT))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_DIRECT_PUT))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_direct_put_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" sink=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, sink, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_new_direct_get

    Type: Component method
    Creates a new amq_client_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_new_direct_get (
    char * feed                         //  Feed name
)
{
amq_client_direct_get_t
    *method;
    amq_client_method_t *
        self;                           //  New method

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_DIRECT_GET))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_direct_get_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" feed=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, feed);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_DIRECT_GET))
    icl_trace_record (NULL, amq_client_method_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_DIRECT_GET))
    icl_stats_inc ("amq_client_method_new_direct_get", &s_amq_client_method_new_direct_get_stats);
#endif

//
self   = self_new ();
method = &self->payload.direct_get;
self->class_id  = AMQ_CLIENT_DIRECT;
self->method_id = AMQ_CLIENT_DIRECT_GET;
self->name      = "direct.get";

//  Copy supplied values to method object
icl_shortstr_cpy (method->feed,          feed);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_DIRECT_GET))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_DIRECT_GET))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_direct_get_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" feed=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, feed, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_encode

    Type: Component method
    Encodes a amq_client_method_t object into a memory bucket.
    Allocates a fresh bucket and returns this.  Returns NULL if there
    was an error encoding the method object.  The supplied bucket ends
    in a frame-end octet, for symmetry with the decode method.
    -------------------------------------------------------------------------
 */

ipr_bucket_t *
    amq_client_method_encode (
    amq_client_method_t * self          //  Method reference
)
{
byte
    *data_target = NULL;
size_t
    string_size = 0;
byte
    bit_string = 0;
    ipr_bucket_t *
        bucket = NULL;                  //  New bucket

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_ENCODE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_encode_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_ENCODE))
    icl_trace_record (NULL, amq_client_method_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_ENCODE))
    icl_stats_inc ("amq_client_method_encode", &s_amq_client_method_encode_stats);
#endif

//
AMQ_CLIENT_METHOD_ASSERT_SANE (self);
assert (self->class_id);
assert (self->method_id);

switch (self->class_id) {
    case AMQ_CLIENT_CONNECTION:
        switch (self->method_id) {
            case AMQ_CLIENT_CONNECTION_START:
                bucket = ipr_bucket_new (12
                            + (self->payload.connection_start.server_properties?
                               self->payload.connection_start.server_properties->cur_size: 0)
                            + (self->payload.connection_start.mechanisms?
                               self->payload.connection_start.mechanisms->cur_size: 0)
                            + (self->payload.connection_start.locales?
                               self->payload.connection_start.locales->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_OCTET (data_target, self->payload.connection_start.version_major);
                PUT_OCTET (data_target, self->payload.connection_start.version_minor);
                PUT_TABLE (data_target, self->payload.connection_start.server_properties);
                PUT_LSTR  (data_target, self->payload.connection_start.mechanisms);
                PUT_LSTR  (data_target, self->payload.connection_start.locales);
                break;
            case AMQ_CLIENT_CONNECTION_START_OK:
                bucket = ipr_bucket_new (10
                            + (self->payload.connection_start_ok.client_properties?
                               self->payload.connection_start_ok.client_properties->cur_size: 0)
                            + strlen (self->payload.connection_start_ok.mechanism)
                            + (self->payload.connection_start_ok.response?
                               self->payload.connection_start_ok.response->cur_size: 0)
                            + strlen (self->payload.connection_start_ok.locale) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_TABLE (data_target, self->payload.connection_start_ok.client_properties);
                PUT_SSTR  (data_target, self->payload.connection_start_ok.mechanism);
                PUT_LSTR  (data_target, self->payload.connection_start_ok.response);
                PUT_SSTR  (data_target, self->payload.connection_start_ok.locale);
                break;
            case AMQ_CLIENT_CONNECTION_SECURE:
                bucket = ipr_bucket_new (6
                            + (self->payload.connection_secure.challenge?
                               self->payload.connection_secure.challenge->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LSTR  (data_target, self->payload.connection_secure.challenge);
                break;
            case AMQ_CLIENT_CONNECTION_SECURE_OK:
                bucket = ipr_bucket_new (6
                            + (self->payload.connection_secure_ok.response?
                               self->payload.connection_secure_ok.response->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LSTR  (data_target, self->payload.connection_secure_ok.response);
                break;
            case AMQ_CLIENT_CONNECTION_TUNE:
                bucket = ipr_bucket_new (12 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.connection_tune.channel_max);
                PUT_LONG  (data_target, self->payload.connection_tune.frame_max);
                PUT_SHORT (data_target, self->payload.connection_tune.heartbeat);
                break;
            case AMQ_CLIENT_CONNECTION_TUNE_OK:
                bucket = ipr_bucket_new (12 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.connection_tune_ok.channel_max);
                PUT_LONG  (data_target, self->payload.connection_tune_ok.frame_max);
                PUT_SHORT (data_target, self->payload.connection_tune_ok.heartbeat);
                break;
            case AMQ_CLIENT_CONNECTION_OPEN:
                bucket = ipr_bucket_new (7
                            + strlen (self->payload.connection_open.virtual_host)
                            + strlen (self->payload.connection_open.capabilities) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.connection_open.virtual_host);
                PUT_SSTR  (data_target, self->payload.connection_open.capabilities);
                bit_string |= (self->payload.connection_open.insist & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_CLIENT_CONNECTION_OPEN_OK:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.connection_open_ok.known_hosts) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.connection_open_ok.known_hosts);
                break;
            case AMQ_CLIENT_CONNECTION_CLOSE:
                bucket = ipr_bucket_new (11
                            + strlen (self->payload.connection_close.reply_text) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.connection_close.reply_code);
                PUT_SSTR  (data_target, self->payload.connection_close.reply_text);
                PUT_SHORT (data_target, self->payload.connection_close.class_id);
                PUT_SHORT (data_target, self->payload.connection_close.method_id);
                break;
            case AMQ_CLIENT_CONNECTION_CLOSE_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
        }
        break;
    case AMQ_CLIENT_CHANNEL:
        switch (self->method_id) {
            case AMQ_CLIENT_CHANNEL_OPEN:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.channel_open.out_of_band) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.channel_open.out_of_band);
                break;
            case AMQ_CLIENT_CHANNEL_OPEN_OK:
                bucket = ipr_bucket_new (6
                            + (self->payload.channel_open_ok.channel_id?
                               self->payload.channel_open_ok.channel_id->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LSTR  (data_target, self->payload.channel_open_ok.channel_id);
                break;
            case AMQ_CLIENT_CHANNEL_FLOW:
                bucket = ipr_bucket_new (5 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                bit_string |= (self->payload.channel_flow.active & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_CLIENT_CHANNEL_FLOW_OK:
                bucket = ipr_bucket_new (5 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                bit_string |= (self->payload.channel_flow_ok.active & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_CLIENT_CHANNEL_CLOSE:
                bucket = ipr_bucket_new (11
                            + strlen (self->payload.channel_close.reply_text) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.channel_close.reply_code);
                PUT_SSTR  (data_target, self->payload.channel_close.reply_text);
                PUT_SHORT (data_target, self->payload.channel_close.class_id);
                PUT_SHORT (data_target, self->payload.channel_close.method_id);
                break;
            case AMQ_CLIENT_CHANNEL_CLOSE_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
        }
        break;
    case AMQ_CLIENT_EXCHANGE:
        switch (self->method_id) {
            case AMQ_CLIENT_EXCHANGE_DECLARE:
                bucket = ipr_bucket_new (11
                            + strlen (self->payload.exchange_declare.exchange)
                            + strlen (self->payload.exchange_declare.type)
                            + (self->payload.exchange_declare.arguments?
                               self->payload.exchange_declare.arguments->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.exchange_declare.ticket);
                PUT_SSTR  (data_target, self->payload.exchange_declare.exchange);
                PUT_SSTR  (data_target, self->payload.exchange_declare.type);
                bit_string |= (self->payload.exchange_declare.passive & 1) << 0;
                bit_string |= (self->payload.exchange_declare.durable & 1) << 1;
                bit_string |= (self->payload.exchange_declare.auto_delete & 1) << 2;
                bit_string |= (self->payload.exchange_declare.internal & 1) << 3;
                bit_string |= (self->payload.exchange_declare.nowait & 1) << 4;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_TABLE (data_target, self->payload.exchange_declare.arguments);
                break;
            case AMQ_CLIENT_EXCHANGE_DECLARE_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
            case AMQ_CLIENT_EXCHANGE_DELETE:
                bucket = ipr_bucket_new (8
                            + strlen (self->payload.exchange_delete.exchange) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.exchange_delete.ticket);
                PUT_SSTR  (data_target, self->payload.exchange_delete.exchange);
                bit_string |= (self->payload.exchange_delete.if_unused & 1) << 0;
                bit_string |= (self->payload.exchange_delete.nowait & 1) << 1;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_CLIENT_EXCHANGE_DELETE_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
        }
        break;
    case AMQ_CLIENT_QUEUE:
        switch (self->method_id) {
            case AMQ_CLIENT_QUEUE_DECLARE:
                bucket = ipr_bucket_new (10
                            + strlen (self->payload.queue_declare.queue)
                            + (self->payload.queue_declare.arguments?
                               self->payload.queue_declare.arguments->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.queue_declare.ticket);
                PUT_SSTR  (data_target, self->payload.queue_declare.queue);
                bit_string |= (self->payload.queue_declare.passive & 1) << 0;
                bit_string |= (self->payload.queue_declare.durable & 1) << 1;
                bit_string |= (self->payload.queue_declare.exclusive & 1) << 2;
                bit_string |= (self->payload.queue_declare.auto_delete & 1) << 3;
                bit_string |= (self->payload.queue_declare.nowait & 1) << 4;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_TABLE (data_target, self->payload.queue_declare.arguments);
                break;
            case AMQ_CLIENT_QUEUE_DECLARE_OK:
                bucket = ipr_bucket_new (13
                            + strlen (self->payload.queue_declare_ok.queue) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.queue_declare_ok.queue);
                PUT_LONG  (data_target, self->payload.queue_declare_ok.message_count);
                PUT_LONG  (data_target, self->payload.queue_declare_ok.consumer_count);
                break;
            case AMQ_CLIENT_QUEUE_BIND:
                bucket = ipr_bucket_new (12
                            + strlen (self->payload.queue_bind.queue)
                            + strlen (self->payload.queue_bind.exchange)
                            + strlen (self->payload.queue_bind.routing_key)
                            + (self->payload.queue_bind.arguments?
                               self->payload.queue_bind.arguments->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.queue_bind.ticket);
                PUT_SSTR  (data_target, self->payload.queue_bind.queue);
                PUT_SSTR  (data_target, self->payload.queue_bind.exchange);
                PUT_SSTR  (data_target, self->payload.queue_bind.routing_key);
                bit_string |= (self->payload.queue_bind.nowait & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_TABLE (data_target, self->payload.queue_bind.arguments);
                break;
            case AMQ_CLIENT_QUEUE_BIND_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
            case AMQ_CLIENT_QUEUE_PURGE:
                bucket = ipr_bucket_new (8
                            + strlen (self->payload.queue_purge.queue) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.queue_purge.ticket);
                PUT_SSTR  (data_target, self->payload.queue_purge.queue);
                bit_string |= (self->payload.queue_purge.nowait & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_CLIENT_QUEUE_PURGE_OK:
                bucket = ipr_bucket_new (8 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LONG  (data_target, self->payload.queue_purge_ok.message_count);
                break;
            case AMQ_CLIENT_QUEUE_DELETE:
                bucket = ipr_bucket_new (8
                            + strlen (self->payload.queue_delete.queue) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.queue_delete.ticket);
                PUT_SSTR  (data_target, self->payload.queue_delete.queue);
                bit_string |= (self->payload.queue_delete.if_unused & 1) << 0;
                bit_string |= (self->payload.queue_delete.if_empty & 1) << 1;
                bit_string |= (self->payload.queue_delete.nowait & 1) << 2;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_CLIENT_QUEUE_DELETE_OK:
                bucket = ipr_bucket_new (8 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LONG  (data_target, self->payload.queue_delete_ok.message_count);
                break;
            case AMQ_CLIENT_QUEUE_UNBIND:
                bucket = ipr_bucket_new (12
                            + strlen (self->payload.queue_unbind.queue)
                            + strlen (self->payload.queue_unbind.exchange)
                            + strlen (self->payload.queue_unbind.routing_key)
                            + (self->payload.queue_unbind.arguments?
                               self->payload.queue_unbind.arguments->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.queue_unbind.ticket);
                PUT_SSTR  (data_target, self->payload.queue_unbind.queue);
                PUT_SSTR  (data_target, self->payload.queue_unbind.exchange);
                PUT_SSTR  (data_target, self->payload.queue_unbind.routing_key);
                bit_string |= (self->payload.queue_unbind.nowait & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_TABLE (data_target, self->payload.queue_unbind.arguments);
                break;
            case AMQ_CLIENT_QUEUE_UNBIND_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
        }
        break;
    case AMQ_CLIENT_BASIC:
        switch (self->method_id) {
            case AMQ_CLIENT_BASIC_QOS:
                bucket = ipr_bucket_new (11 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LONG  (data_target, self->payload.basic_qos.prefetch_size);
                PUT_SHORT (data_target, self->payload.basic_qos.prefetch_count);
                bit_string |= (self->payload.basic_qos.global & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_CLIENT_BASIC_QOS_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
            case AMQ_CLIENT_BASIC_CONSUME:
                bucket = ipr_bucket_new (11
                            + strlen (self->payload.basic_consume.queue)
                            + strlen (self->payload.basic_consume.consumer_tag)
                            + (self->payload.basic_consume.arguments?
                               self->payload.basic_consume.arguments->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.basic_consume.ticket);
                PUT_SSTR  (data_target, self->payload.basic_consume.queue);
                PUT_SSTR  (data_target, self->payload.basic_consume.consumer_tag);
                bit_string |= (self->payload.basic_consume.no_local & 1) << 0;
                bit_string |= (self->payload.basic_consume.no_ack & 1) << 1;
                bit_string |= (self->payload.basic_consume.exclusive & 1) << 2;
                bit_string |= (self->payload.basic_consume.nowait & 1) << 3;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_TABLE (data_target, self->payload.basic_consume.arguments);
                break;
            case AMQ_CLIENT_BASIC_CONSUME_OK:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.basic_consume_ok.consumer_tag) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.basic_consume_ok.consumer_tag);
                break;
            case AMQ_CLIENT_BASIC_CANCEL:
                bucket = ipr_bucket_new (6
                            + strlen (self->payload.basic_cancel.consumer_tag) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.basic_cancel.consumer_tag);
                bit_string |= (self->payload.basic_cancel.nowait & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_CLIENT_BASIC_CANCEL_OK:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.basic_cancel_ok.consumer_tag) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.basic_cancel_ok.consumer_tag);
                break;
            case AMQ_CLIENT_BASIC_PUBLISH:
                bucket = ipr_bucket_new (9
                            + strlen (self->payload.basic_publish.exchange)
                            + strlen (self->payload.basic_publish.routing_key) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.basic_publish.ticket);
                PUT_SSTR  (data_target, self->payload.basic_publish.exchange);
                PUT_SSTR  (data_target, self->payload.basic_publish.routing_key);
                bit_string |= (self->payload.basic_publish.mandatory & 1) << 0;
                bit_string |= (self->payload.basic_publish.immediate & 1) << 1;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_CLIENT_BASIC_RETURN:
                bucket = ipr_bucket_new (9
                            + strlen (self->payload.basic_return.reply_text)
                            + strlen (self->payload.basic_return.exchange)
                            + strlen (self->payload.basic_return.routing_key) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.basic_return.reply_code);
                PUT_SSTR  (data_target, self->payload.basic_return.reply_text);
                PUT_SSTR  (data_target, self->payload.basic_return.exchange);
                PUT_SSTR  (data_target, self->payload.basic_return.routing_key);
                break;
            case AMQ_CLIENT_BASIC_DELIVER:
                bucket = ipr_bucket_new (16
                            + strlen (self->payload.basic_deliver.consumer_tag)
                            + strlen (self->payload.basic_deliver.exchange)
                            + strlen (self->payload.basic_deliver.routing_key) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.basic_deliver.consumer_tag);
                PUT_LLONG (data_target, self->payload.basic_deliver.delivery_tag);
                bit_string |= (self->payload.basic_deliver.redelivered & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_SSTR  (data_target, self->payload.basic_deliver.exchange);
                PUT_SSTR  (data_target, self->payload.basic_deliver.routing_key);
                break;
            case AMQ_CLIENT_BASIC_GET:
                bucket = ipr_bucket_new (8
                            + strlen (self->payload.basic_get.queue) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.basic_get.ticket);
                PUT_SSTR  (data_target, self->payload.basic_get.queue);
                bit_string |= (self->payload.basic_get.no_ack & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_CLIENT_BASIC_GET_OK:
                bucket = ipr_bucket_new (19
                            + strlen (self->payload.basic_get_ok.exchange)
                            + strlen (self->payload.basic_get_ok.routing_key) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LLONG (data_target, self->payload.basic_get_ok.delivery_tag);
                bit_string |= (self->payload.basic_get_ok.redelivered & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_SSTR  (data_target, self->payload.basic_get_ok.exchange);
                PUT_SSTR  (data_target, self->payload.basic_get_ok.routing_key);
                PUT_LONG  (data_target, self->payload.basic_get_ok.message_count);
                break;
            case AMQ_CLIENT_BASIC_GET_EMPTY:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.basic_get_empty.sender_id) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.basic_get_empty.sender_id);
                break;
            case AMQ_CLIENT_BASIC_ACK:
                bucket = ipr_bucket_new (13 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LLONG (data_target, self->payload.basic_ack.delivery_tag);
                bit_string |= (self->payload.basic_ack.multiple & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_CLIENT_BASIC_REJECT:
                bucket = ipr_bucket_new (13 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LLONG (data_target, self->payload.basic_reject.delivery_tag);
                bit_string |= (self->payload.basic_reject.requeue & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
        }
        break;
    case AMQ_CLIENT_DIRECT:
        switch (self->method_id) {
            case AMQ_CLIENT_DIRECT_PUT:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.direct_put.sink) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.direct_put.sink);
                break;
            case AMQ_CLIENT_DIRECT_PUT_OK:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.direct_put_ok.lease) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.direct_put_ok.lease);
                break;
            case AMQ_CLIENT_DIRECT_GET:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.direct_get.feed) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.direct_get.feed);
                break;
            case AMQ_CLIENT_DIRECT_GET_OK:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.direct_get_ok.lease) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.direct_get_ok.lease);
                break;
        }
        break;
}
bucket->cur_size = data_target - bucket->data;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_ENCODE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_ENCODE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_encode_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket);
#endif


    return (bucket);
}
/*  -------------------------------------------------------------------------
    amq_client_method_decode

    Type: Component method
    Decodes a amq_client_method_t object from a memory bucket.
    Allocates a new amq_client_method_t structure and returns this. Returns
    NULL if there was an error decoding the method object.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_decode (
    ipr_bucket_t * bucket,              //  New bucket
    char * strerror                     //  Error text, if any
)
{
byte
    *data_source,                   //  Pointer into buffer data           
    *data_limit;                    //  Limit of buffer data               
size_t
    string_size;
byte
    bit_string = 0;
    amq_client_method_t *
        self;                           //  Method reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_DECODE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_decode_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" bucket=\"%pp\""
" strerror=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, bucket, strerror);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DECODE))
    icl_trace_record (NULL, amq_client_method_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_DECODE))
    icl_stats_inc ("amq_client_method_decode", &s_amq_client_method_decode_stats);
#endif

//
//  Check that frame is correctly terminated before decoding it            
assert (bucket);
self = NULL;
data_source = bucket->data;
data_limit  = data_source + bucket->cur_size;

self = self_new ();
GET_SHORT (self->class_id,  data_source);
GET_SHORT (self->method_id, data_source);
switch (self->class_id) {
    case AMQ_CLIENT_CONNECTION:
        switch (self->method_id) {
            case AMQ_CLIENT_CONNECTION_START:
                self->name = "connection.start";
                self->sync = TRUE;
                GET_OCTET (self->payload.connection_start.version_major, data_source);
                GET_OCTET (self->payload.connection_start.version_minor, data_source);
                GET_LSTR (self->payload.connection_start.server_properties, data_source);
                GET_LSTR (self->payload.connection_start.mechanisms, data_source);
                GET_LSTR (self->payload.connection_start.locales, data_source);
                if (self->payload.connection_start.mechanisms == NULL || self->payload.connection_start.mechanisms->cur_size == 0) {
                    strcpy (strerror, "connection.start: mechanisms field is empty");
                    goto exception;
                }
                if (self->payload.connection_start.locales == NULL || self->payload.connection_start.locales->cur_size == 0) {
                    strcpy (strerror, "connection.start: locales field is empty");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_CONNECTION_START_OK:
                self->name = "connection.start_ok";
                self->sync = TRUE;
                GET_LSTR (self->payload.connection_start_ok.client_properties, data_source);
                GET_SSTR (self->payload.connection_start_ok.mechanism, data_source);
                GET_LSTR (self->payload.connection_start_ok.response, data_source);
                GET_SSTR (self->payload.connection_start_ok.locale, data_source);
                if (*self->payload.connection_start_ok.mechanism == 0) {
                    strcpy (strerror, "connection.start_ok: mechanism field is empty");
                    goto exception;
                }
                if (self->payload.connection_start_ok.response == NULL || self->payload.connection_start_ok.response->cur_size == 0) {
                    strcpy (strerror, "connection.start_ok: response field is empty");
                    goto exception;
                }
                if (*self->payload.connection_start_ok.locale == 0) {
                    strcpy (strerror, "connection.start_ok: locale field is empty");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_CONNECTION_SECURE:
                self->name = "connection.secure";
                self->sync = TRUE;
                GET_LSTR (self->payload.connection_secure.challenge, data_source);
                break;
            case AMQ_CLIENT_CONNECTION_SECURE_OK:
                self->name = "connection.secure_ok";
                self->sync = TRUE;
                GET_LSTR (self->payload.connection_secure_ok.response, data_source);
                break;
            case AMQ_CLIENT_CONNECTION_TUNE:
                self->name = "connection.tune";
                self->sync = TRUE;
                GET_SHORT (self->payload.connection_tune.channel_max, data_source);
                GET_LONG  (self->payload.connection_tune.frame_max, data_source);
                GET_SHORT (self->payload.connection_tune.heartbeat, data_source);
                break;
            case AMQ_CLIENT_CONNECTION_TUNE_OK:
                self->name = "connection.tune_ok";
                self->sync = TRUE;
                GET_SHORT (self->payload.connection_tune_ok.channel_max, data_source);
                GET_LONG  (self->payload.connection_tune_ok.frame_max, data_source);
                GET_SHORT (self->payload.connection_tune_ok.heartbeat, data_source);
                if (self->payload.connection_tune_ok.channel_max == 0) {
                    strcpy (strerror, "connection.tune_ok: channel_max field is empty");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_CONNECTION_OPEN:
                self->name = "connection.open";
                self->sync = TRUE;
                GET_SSTR (self->payload.connection_open.virtual_host, data_source);
                GET_SSTR (self->payload.connection_open.capabilities, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.connection_open.insist = (bit_string >> 0) & 1;
                if (!ipr_regexp_match (s_regexp_connection_virtual_host, self->payload.connection_open.virtual_host)) {
                    strcpy (strerror, "connection.open: virtual_host field is invalid");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_CONNECTION_OPEN_OK:
                self->name = "connection.open_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.connection_open_ok.known_hosts, data_source);
                break;
            case AMQ_CLIENT_CONNECTION_CLOSE:
                self->name = "connection.close";
                self->sync = TRUE;
                GET_SHORT (self->payload.connection_close.reply_code, data_source);
                GET_SSTR (self->payload.connection_close.reply_text, data_source);
                GET_SHORT (self->payload.connection_close.class_id, data_source);
                GET_SHORT (self->payload.connection_close.method_id, data_source);
                if (self->payload.connection_close.reply_code == 0) {
                    strcpy (strerror, "connection.close: reply_code field is empty");
                    goto exception;
                }
                if (*self->payload.connection_close.reply_text == 0) {
                    strcpy (strerror, "connection.close: reply_text field is empty");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_CONNECTION_CLOSE_OK:
                self->name = "connection.close_ok";
                self->sync = TRUE;
                break;
        }
        break;
    case AMQ_CLIENT_CHANNEL:
        switch (self->method_id) {
            case AMQ_CLIENT_CHANNEL_OPEN:
                self->name = "channel.open";
                self->sync = TRUE;
                GET_SSTR (self->payload.channel_open.out_of_band, data_source);
                break;
            case AMQ_CLIENT_CHANNEL_OPEN_OK:
                self->name = "channel.open_ok";
                self->sync = TRUE;
                GET_LSTR (self->payload.channel_open_ok.channel_id, data_source);
                break;
            case AMQ_CLIENT_CHANNEL_FLOW:
                self->name = "channel.flow";
                self->sync = TRUE;
                GET_OCTET (bit_string, data_source);
                self->payload.channel_flow.active = (bit_string >> 0) & 1;
                break;
            case AMQ_CLIENT_CHANNEL_FLOW_OK:
                self->name = "channel.flow_ok";
                self->sync = FALSE;
                GET_OCTET (bit_string, data_source);
                self->payload.channel_flow_ok.active = (bit_string >> 0) & 1;
                break;
            case AMQ_CLIENT_CHANNEL_CLOSE:
                self->name = "channel.close";
                self->sync = TRUE;
                GET_SHORT (self->payload.channel_close.reply_code, data_source);
                GET_SSTR (self->payload.channel_close.reply_text, data_source);
                GET_SHORT (self->payload.channel_close.class_id, data_source);
                GET_SHORT (self->payload.channel_close.method_id, data_source);
                if (self->payload.channel_close.reply_code == 0) {
                    strcpy (strerror, "channel.close: reply_code field is empty");
                    goto exception;
                }
                if (*self->payload.channel_close.reply_text == 0) {
                    strcpy (strerror, "channel.close: reply_text field is empty");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_CHANNEL_CLOSE_OK:
                self->name = "channel.close_ok";
                self->sync = TRUE;
                break;
        }
        break;
    case AMQ_CLIENT_EXCHANGE:
        switch (self->method_id) {
            case AMQ_CLIENT_EXCHANGE_DECLARE:
                self->name = "exchange.declare";
                self->sync = TRUE;
                GET_SHORT (self->payload.exchange_declare.ticket, data_source);
                GET_SSTR (self->payload.exchange_declare.exchange, data_source);
                GET_SSTR (self->payload.exchange_declare.type, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.exchange_declare.passive = (bit_string >> 0) & 1;
                self->payload.exchange_declare.durable = (bit_string >> 1) & 1;
                self->payload.exchange_declare.auto_delete = (bit_string >> 2) & 1;
                self->payload.exchange_declare.internal = (bit_string >> 3) & 1;
                self->payload.exchange_declare.nowait = (bit_string >> 4) & 1;
                GET_LSTR (self->payload.exchange_declare.arguments, data_source);
                if (!ipr_regexp_match (s_regexp_exchange_exchange, self->payload.exchange_declare.exchange)) {
                    strcpy (strerror, "exchange.declare: exchange field is invalid");
                    goto exception;
                }
                if (!ipr_regexp_match (s_regexp_exchange_type, self->payload.exchange_declare.type)) {
                    strcpy (strerror, "exchange.declare: type field is invalid");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_EXCHANGE_DECLARE_OK:
                self->name = "exchange.declare_ok";
                self->sync = TRUE;
                break;
            case AMQ_CLIENT_EXCHANGE_DELETE:
                self->name = "exchange.delete";
                self->sync = TRUE;
                GET_SHORT (self->payload.exchange_delete.ticket, data_source);
                GET_SSTR (self->payload.exchange_delete.exchange, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.exchange_delete.if_unused = (bit_string >> 0) & 1;
                self->payload.exchange_delete.nowait = (bit_string >> 1) & 1;
                if (*self->payload.exchange_delete.exchange == 0) {
                    strcpy (strerror, "exchange.delete: exchange field is empty");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_EXCHANGE_DELETE_OK:
                self->name = "exchange.delete_ok";
                self->sync = TRUE;
                break;
        }
        break;
    case AMQ_CLIENT_QUEUE:
        switch (self->method_id) {
            case AMQ_CLIENT_QUEUE_DECLARE:
                self->name = "queue.declare";
                self->sync = TRUE;
                GET_SHORT (self->payload.queue_declare.ticket, data_source);
                GET_SSTR (self->payload.queue_declare.queue, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.queue_declare.passive = (bit_string >> 0) & 1;
                self->payload.queue_declare.durable = (bit_string >> 1) & 1;
                self->payload.queue_declare.exclusive = (bit_string >> 2) & 1;
                self->payload.queue_declare.auto_delete = (bit_string >> 3) & 1;
                self->payload.queue_declare.nowait = (bit_string >> 4) & 1;
                GET_LSTR (self->payload.queue_declare.arguments, data_source);
                if (!ipr_regexp_match (s_regexp_queue_queue, self->payload.queue_declare.queue)) {
                    strcpy (strerror, "queue.declare: queue field is invalid");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_QUEUE_DECLARE_OK:
                self->name = "queue.declare_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.queue_declare_ok.queue, data_source);
                GET_LONG  (self->payload.queue_declare_ok.message_count, data_source);
                GET_LONG  (self->payload.queue_declare_ok.consumer_count, data_source);
                if (*self->payload.queue_declare_ok.queue == 0) {
                    strcpy (strerror, "queue.declare_ok: queue field is empty");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_QUEUE_BIND:
                self->name = "queue.bind";
                self->sync = TRUE;
                GET_SHORT (self->payload.queue_bind.ticket, data_source);
                GET_SSTR (self->payload.queue_bind.queue, data_source);
                GET_SSTR (self->payload.queue_bind.exchange, data_source);
                GET_SSTR (self->payload.queue_bind.routing_key, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.queue_bind.nowait = (bit_string >> 0) & 1;
                GET_LSTR (self->payload.queue_bind.arguments, data_source);
                if (strlen (self->payload.queue_bind.queue) > 127) {
                    strcpy (strerror, "queue.bind: queue field exceeds >127 chars");
                    goto exception;
                }
                if (strlen (self->payload.queue_bind.exchange) > 127) {
                    strcpy (strerror, "queue.bind: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_QUEUE_BIND_OK:
                self->name = "queue.bind_ok";
                self->sync = TRUE;
                break;
            case AMQ_CLIENT_QUEUE_PURGE:
                self->name = "queue.purge";
                self->sync = TRUE;
                GET_SHORT (self->payload.queue_purge.ticket, data_source);
                GET_SSTR (self->payload.queue_purge.queue, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.queue_purge.nowait = (bit_string >> 0) & 1;
                if (strlen (self->payload.queue_purge.queue) > 127) {
                    strcpy (strerror, "queue.purge: queue field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_QUEUE_PURGE_OK:
                self->name = "queue.purge_ok";
                self->sync = TRUE;
                GET_LONG  (self->payload.queue_purge_ok.message_count, data_source);
                break;
            case AMQ_CLIENT_QUEUE_DELETE:
                self->name = "queue.delete";
                self->sync = TRUE;
                GET_SHORT (self->payload.queue_delete.ticket, data_source);
                GET_SSTR (self->payload.queue_delete.queue, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.queue_delete.if_unused = (bit_string >> 0) & 1;
                self->payload.queue_delete.if_empty = (bit_string >> 1) & 1;
                self->payload.queue_delete.nowait = (bit_string >> 2) & 1;
                if (strlen (self->payload.queue_delete.queue) > 127) {
                    strcpy (strerror, "queue.delete: queue field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_QUEUE_DELETE_OK:
                self->name = "queue.delete_ok";
                self->sync = TRUE;
                GET_LONG  (self->payload.queue_delete_ok.message_count, data_source);
                break;
            case AMQ_CLIENT_QUEUE_UNBIND:
                self->name = "queue.unbind";
                self->sync = TRUE;
                GET_SHORT (self->payload.queue_unbind.ticket, data_source);
                GET_SSTR (self->payload.queue_unbind.queue, data_source);
                GET_SSTR (self->payload.queue_unbind.exchange, data_source);
                GET_SSTR (self->payload.queue_unbind.routing_key, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.queue_unbind.nowait = (bit_string >> 0) & 1;
                GET_LSTR (self->payload.queue_unbind.arguments, data_source);
                if (strlen (self->payload.queue_unbind.queue) > 127) {
                    strcpy (strerror, "queue.unbind: queue field exceeds >127 chars");
                    goto exception;
                }
                if (strlen (self->payload.queue_unbind.exchange) > 127) {
                    strcpy (strerror, "queue.unbind: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_QUEUE_UNBIND_OK:
                self->name = "queue.unbind_ok";
                self->sync = TRUE;
                break;
        }
        break;
    case AMQ_CLIENT_BASIC:
        switch (self->method_id) {
            case AMQ_CLIENT_BASIC_QOS:
                self->name = "basic.qos";
                self->sync = TRUE;
                GET_LONG  (self->payload.basic_qos.prefetch_size, data_source);
                GET_SHORT (self->payload.basic_qos.prefetch_count, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_qos.global = (bit_string >> 0) & 1;
                break;
            case AMQ_CLIENT_BASIC_QOS_OK:
                self->name = "basic.qos_ok";
                self->sync = TRUE;
                break;
            case AMQ_CLIENT_BASIC_CONSUME:
                self->name = "basic.consume";
                self->sync = TRUE;
                GET_SHORT (self->payload.basic_consume.ticket, data_source);
                GET_SSTR (self->payload.basic_consume.queue, data_source);
                GET_SSTR (self->payload.basic_consume.consumer_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_consume.no_local = (bit_string >> 0) & 1;
                self->payload.basic_consume.no_ack = (bit_string >> 1) & 1;
                self->payload.basic_consume.exclusive = (bit_string >> 2) & 1;
                self->payload.basic_consume.nowait = (bit_string >> 3) & 1;
                GET_LSTR (self->payload.basic_consume.arguments, data_source);
                if (strlen (self->payload.basic_consume.queue) > 127) {
                    strcpy (strerror, "basic.consume: queue field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_BASIC_CONSUME_OK:
                self->name = "basic.consume_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.basic_consume_ok.consumer_tag, data_source);
                break;
            case AMQ_CLIENT_BASIC_CANCEL:
                self->name = "basic.cancel";
                self->sync = TRUE;
                GET_SSTR (self->payload.basic_cancel.consumer_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_cancel.nowait = (bit_string >> 0) & 1;
                break;
            case AMQ_CLIENT_BASIC_CANCEL_OK:
                self->name = "basic.cancel_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.basic_cancel_ok.consumer_tag, data_source);
                break;
            case AMQ_CLIENT_BASIC_PUBLISH:
                self->name = "basic.publish";
                self->sync = FALSE;
                GET_SHORT (self->payload.basic_publish.ticket, data_source);
                GET_SSTR (self->payload.basic_publish.exchange, data_source);
                GET_SSTR (self->payload.basic_publish.routing_key, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_publish.mandatory = (bit_string >> 0) & 1;
                self->payload.basic_publish.immediate = (bit_string >> 1) & 1;
                if (strlen (self->payload.basic_publish.exchange) > 127) {
                    strcpy (strerror, "basic.publish: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_BASIC_RETURN:
                self->name = "basic.return";
                self->sync = FALSE;
                GET_SHORT (self->payload.basic_return.reply_code, data_source);
                GET_SSTR (self->payload.basic_return.reply_text, data_source);
                GET_SSTR (self->payload.basic_return.exchange, data_source);
                GET_SSTR (self->payload.basic_return.routing_key, data_source);
                if (self->payload.basic_return.reply_code == 0) {
                    strcpy (strerror, "basic.return: reply_code field is empty");
                    goto exception;
                }
                if (*self->payload.basic_return.reply_text == 0) {
                    strcpy (strerror, "basic.return: reply_text field is empty");
                    goto exception;
                }
                if (strlen (self->payload.basic_return.exchange) > 127) {
                    strcpy (strerror, "basic.return: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_BASIC_DELIVER:
                self->name = "basic.deliver";
                self->sync = FALSE;
                GET_SSTR (self->payload.basic_deliver.consumer_tag, data_source);
                GET_LLONG (self->payload.basic_deliver.delivery_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_deliver.redelivered = (bit_string >> 0) & 1;
                GET_SSTR (self->payload.basic_deliver.exchange, data_source);
                GET_SSTR (self->payload.basic_deliver.routing_key, data_source);
                if (strlen (self->payload.basic_deliver.exchange) > 127) {
                    strcpy (strerror, "basic.deliver: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_BASIC_GET:
                self->name = "basic.get";
                self->sync = TRUE;
                GET_SHORT (self->payload.basic_get.ticket, data_source);
                GET_SSTR (self->payload.basic_get.queue, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_get.no_ack = (bit_string >> 0) & 1;
                if (strlen (self->payload.basic_get.queue) > 127) {
                    strcpy (strerror, "basic.get: queue field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_BASIC_GET_OK:
                self->name = "basic.get_ok";
                self->sync = TRUE;
                GET_LLONG (self->payload.basic_get_ok.delivery_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_get_ok.redelivered = (bit_string >> 0) & 1;
                GET_SSTR (self->payload.basic_get_ok.exchange, data_source);
                GET_SSTR (self->payload.basic_get_ok.routing_key, data_source);
                GET_LONG  (self->payload.basic_get_ok.message_count, data_source);
                if (strlen (self->payload.basic_get_ok.exchange) > 127) {
                    strcpy (strerror, "basic.get_ok: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_BASIC_GET_EMPTY:
                self->name = "basic.get_empty";
                self->sync = TRUE;
                GET_SSTR (self->payload.basic_get_empty.sender_id, data_source);
                break;
            case AMQ_CLIENT_BASIC_ACK:
                self->name = "basic.ack";
                self->sync = FALSE;
                GET_LLONG (self->payload.basic_ack.delivery_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_ack.multiple = (bit_string >> 0) & 1;
                break;
            case AMQ_CLIENT_BASIC_REJECT:
                self->name = "basic.reject";
                self->sync = FALSE;
                GET_LLONG (self->payload.basic_reject.delivery_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_reject.requeue = (bit_string >> 0) & 1;
                break;
        }
        break;
    case AMQ_CLIENT_DIRECT:
        switch (self->method_id) {
            case AMQ_CLIENT_DIRECT_PUT:
                self->name = "direct.put";
                self->sync = TRUE;
                GET_SSTR (self->payload.direct_put.sink, data_source);
                break;
            case AMQ_CLIENT_DIRECT_PUT_OK:
                self->name = "direct.put_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.direct_put_ok.lease, data_source);
                break;
            case AMQ_CLIENT_DIRECT_GET:
                self->name = "direct.get";
                self->sync = TRUE;
                GET_SSTR (self->payload.direct_get.feed, data_source);
                if (*self->payload.direct_get.feed == 0) {
                    strcpy (strerror, "direct.get: feed field is empty");
                    goto exception;
                }
                break;
            case AMQ_CLIENT_DIRECT_GET_OK:
                self->name = "direct.get_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.direct_get_ok.lease, data_source);
                break;
        }
        break;
}
goto finished;
underflow:
    icl_shortstr_fmt (strerror, "malformed frame for '%s' method", self->name);
exception:
    self_destroy (&self);
    return (NULL);
finished:
    //  Return via normal function exit
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DECODE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_DECODE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_decode_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" bucket=\"%pp\""
" strerror=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, bucket, strerror, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_dump

    Type: Component method
    Accepts a amq_client_method_t reference and returns zero in case of success,
    1 in case of errors.
    Dumps contents of serialised method for tracing.
    -------------------------------------------------------------------------
 */

int
    amq_client_method_dump (
    amq_client_method_t * self,         //  Reference to object
    smt_log_t * log,                    //  Log file, if any
    char * prefix                       //  Prefix for line
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_DUMP))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_dump_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" log=\"%pp\""
" prefix=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, log, prefix);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DUMP))
    icl_trace_record (NULL, amq_client_method_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_DUMP))
    icl_stats_inc ("amq_client_method_dump", &s_amq_client_method_dump_stats);
#endif

AMQ_CLIENT_METHOD_ASSERT_SANE (self);
if (!self->zombie) {

//
switch (self->class_id) {
    case AMQ_CLIENT_CONNECTION:
        switch (self->method_id) {
            case AMQ_CLIENT_CONNECTION_START:
                if (log) {
                    smt_log_print (log, "%sconnection.start:"\
                        " version_major=%d version_minor=%d server_properties=%uB mechanisms=%uB locales=%uB", prefix,
                        self->payload.connection_start.version_major,
                        self->payload.connection_start.version_minor,
                        self->payload.connection_start.server_properties?
                            self->payload.connection_start.server_properties->cur_size: 0,
                        self->payload.connection_start.mechanisms?
                            self->payload.connection_start.mechanisms->cur_size: 0,
                        self->payload.connection_start.locales?
                            self->payload.connection_start.locales->cur_size: 0);
                }
                else {
                    icl_console_print ("%sconnection.start:"\
                        " version_major=%d version_minor=%d server_properties=%uB mechanisms=%uB locales=%uB", prefix,
                        self->payload.connection_start.version_major,
                        self->payload.connection_start.version_minor,
                        self->payload.connection_start.server_properties?
                            self->payload.connection_start.server_properties->cur_size: 0,
                        self->payload.connection_start.mechanisms?
                            self->payload.connection_start.mechanisms->cur_size: 0,
                        self->payload.connection_start.locales?
                            self->payload.connection_start.locales->cur_size: 0);
                }
                break;
            case AMQ_CLIENT_CONNECTION_START_OK:
                if (log) {
                    smt_log_print (log, "%sconnection.start-ok:"\
                        " client_properties=%uB mechanism=\"%s\" response=%uB locale=\"%s\"", prefix,
                        self->payload.connection_start_ok.client_properties?
                            self->payload.connection_start_ok.client_properties->cur_size: 0,
                        self->payload.connection_start_ok.mechanism,
                        self->payload.connection_start_ok.response?
                            self->payload.connection_start_ok.response->cur_size: 0,
                        self->payload.connection_start_ok.locale);
                }
                else {
                    icl_console_print ("%sconnection.start-ok:"\
                        " client_properties=%uB mechanism=\"%s\" response=%uB locale=\"%s\"", prefix,
                        self->payload.connection_start_ok.client_properties?
                            self->payload.connection_start_ok.client_properties->cur_size: 0,
                        self->payload.connection_start_ok.mechanism,
                        self->payload.connection_start_ok.response?
                            self->payload.connection_start_ok.response->cur_size: 0,
                        self->payload.connection_start_ok.locale);
                }
                break;
            case AMQ_CLIENT_CONNECTION_SECURE:
                if (log) {
                    smt_log_print (log, "%sconnection.secure:"\
                        " challenge=%uB", prefix,
                        self->payload.connection_secure.challenge?
                            self->payload.connection_secure.challenge->cur_size: 0);
                }
                else {
                    icl_console_print ("%sconnection.secure:"\
                        " challenge=%uB", prefix,
                        self->payload.connection_secure.challenge?
                            self->payload.connection_secure.challenge->cur_size: 0);
                }
                break;
            case AMQ_CLIENT_CONNECTION_SECURE_OK:
                if (log) {
                    smt_log_print (log, "%sconnection.secure-ok:"\
                        " response=%uB", prefix,
                        self->payload.connection_secure_ok.response?
                            self->payload.connection_secure_ok.response->cur_size: 0);
                }
                else {
                    icl_console_print ("%sconnection.secure-ok:"\
                        " response=%uB", prefix,
                        self->payload.connection_secure_ok.response?
                            self->payload.connection_secure_ok.response->cur_size: 0);
                }
                break;
            case AMQ_CLIENT_CONNECTION_TUNE:
                if (log) {
                    smt_log_print (log, "%sconnection.tune:"\
                        " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                        self->payload.connection_tune.channel_max,
                        self->payload.connection_tune.frame_max,
                        self->payload.connection_tune.heartbeat);
                }
                else {
                    icl_console_print ("%sconnection.tune:"\
                        " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                        self->payload.connection_tune.channel_max,
                        self->payload.connection_tune.frame_max,
                        self->payload.connection_tune.heartbeat);
                }
                break;
            case AMQ_CLIENT_CONNECTION_TUNE_OK:
                if (log) {
                    smt_log_print (log, "%sconnection.tune-ok:"\
                        " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                        self->payload.connection_tune_ok.channel_max,
                        self->payload.connection_tune_ok.frame_max,
                        self->payload.connection_tune_ok.heartbeat);
                }
                else {
                    icl_console_print ("%sconnection.tune-ok:"\
                        " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                        self->payload.connection_tune_ok.channel_max,
                        self->payload.connection_tune_ok.frame_max,
                        self->payload.connection_tune_ok.heartbeat);
                }
                break;
            case AMQ_CLIENT_CONNECTION_OPEN:
                if (log) {
                    smt_log_print (log, "%sconnection.open:"\
                        " virtual_host=\"%s\" capabilities=\"%s\" insist=%d", prefix,
                        self->payload.connection_open.virtual_host,
                        self->payload.connection_open.capabilities,
                        self->payload.connection_open.insist);
                }
                else {
                    icl_console_print ("%sconnection.open:"\
                        " virtual_host=\"%s\" capabilities=\"%s\" insist=%d", prefix,
                        self->payload.connection_open.virtual_host,
                        self->payload.connection_open.capabilities,
                        self->payload.connection_open.insist);
                }
                break;
            case AMQ_CLIENT_CONNECTION_OPEN_OK:
                if (log) {
                    smt_log_print (log, "%sconnection.open-ok:"\
                        " known_hosts=\"%s\"", prefix,
                        self->payload.connection_open_ok.known_hosts);
                }
                else {
                    icl_console_print ("%sconnection.open-ok:"\
                        " known_hosts=\"%s\"", prefix,
                        self->payload.connection_open_ok.known_hosts);
                }
                break;
            case AMQ_CLIENT_CONNECTION_CLOSE:
                if (log) {
                    smt_log_print (log, "%sconnection.close:"\
                        " reply_code=%d reply_text=\"%s\" class_id=%d method_id=%d", prefix,
                        self->payload.connection_close.reply_code,
                        self->payload.connection_close.reply_text,
                        self->payload.connection_close.class_id,
                        self->payload.connection_close.method_id);
                }
                else {
                    icl_console_print ("%sconnection.close:"\
                        " reply_code=%d reply_text=\"%s\" class_id=%d method_id=%d", prefix,
                        self->payload.connection_close.reply_code,
                        self->payload.connection_close.reply_text,
                        self->payload.connection_close.class_id,
                        self->payload.connection_close.method_id);
                }
                break;
            case AMQ_CLIENT_CONNECTION_CLOSE_OK:
                if (log) {
                    smt_log_print (log, "%sconnection.close-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%sconnection.close-ok:"\
                        "", prefix);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    case AMQ_CLIENT_CHANNEL:
        switch (self->method_id) {
            case AMQ_CLIENT_CHANNEL_OPEN:
                if (log) {
                    smt_log_print (log, "%schannel.open:"\
                        " out_of_band=\"%s\"", prefix,
                        self->payload.channel_open.out_of_band);
                }
                else {
                    icl_console_print ("%schannel.open:"\
                        " out_of_band=\"%s\"", prefix,
                        self->payload.channel_open.out_of_band);
                }
                break;
            case AMQ_CLIENT_CHANNEL_OPEN_OK:
                if (log) {
                    smt_log_print (log, "%schannel.open-ok:"\
                        " channel_id=%uB", prefix,
                        self->payload.channel_open_ok.channel_id?
                            self->payload.channel_open_ok.channel_id->cur_size: 0);
                }
                else {
                    icl_console_print ("%schannel.open-ok:"\
                        " channel_id=%uB", prefix,
                        self->payload.channel_open_ok.channel_id?
                            self->payload.channel_open_ok.channel_id->cur_size: 0);
                }
                break;
            case AMQ_CLIENT_CHANNEL_FLOW:
                if (log) {
                    smt_log_print (log, "%schannel.flow:"\
                        " active=%d", prefix,
                        self->payload.channel_flow.active);
                }
                else {
                    icl_console_print ("%schannel.flow:"\
                        " active=%d", prefix,
                        self->payload.channel_flow.active);
                }
                break;
            case AMQ_CLIENT_CHANNEL_FLOW_OK:
                if (log) {
                    smt_log_print (log, "%schannel.flow-ok:"\
                        " active=%d", prefix,
                        self->payload.channel_flow_ok.active);
                }
                else {
                    icl_console_print ("%schannel.flow-ok:"\
                        " active=%d", prefix,
                        self->payload.channel_flow_ok.active);
                }
                break;
            case AMQ_CLIENT_CHANNEL_CLOSE:
                if (log) {
                    smt_log_print (log, "%schannel.close:"\
                        " reply_code=%d reply_text=\"%s\" class_id=%d method_id=%d", prefix,
                        self->payload.channel_close.reply_code,
                        self->payload.channel_close.reply_text,
                        self->payload.channel_close.class_id,
                        self->payload.channel_close.method_id);
                }
                else {
                    icl_console_print ("%schannel.close:"\
                        " reply_code=%d reply_text=\"%s\" class_id=%d method_id=%d", prefix,
                        self->payload.channel_close.reply_code,
                        self->payload.channel_close.reply_text,
                        self->payload.channel_close.class_id,
                        self->payload.channel_close.method_id);
                }
                break;
            case AMQ_CLIENT_CHANNEL_CLOSE_OK:
                if (log) {
                    smt_log_print (log, "%schannel.close-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%schannel.close-ok:"\
                        "", prefix);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    case AMQ_CLIENT_EXCHANGE:
        switch (self->method_id) {
            case AMQ_CLIENT_EXCHANGE_DECLARE:
                if (log) {
                    smt_log_print (log, "%sexchange.declare:"\
                        " ticket=%d exchange=\"%s\" type=\"%s\" passive=%d durable=%d auto_delete=%d internal=%d nowait=%d arguments=%uB", prefix,
                        self->payload.exchange_declare.ticket,
                        self->payload.exchange_declare.exchange,
                        self->payload.exchange_declare.type,
                        self->payload.exchange_declare.passive,
                        self->payload.exchange_declare.durable,
                        self->payload.exchange_declare.auto_delete,
                        self->payload.exchange_declare.internal,
                        self->payload.exchange_declare.nowait,
                        self->payload.exchange_declare.arguments?
                            self->payload.exchange_declare.arguments->cur_size: 0);
                }
                else {
                    icl_console_print ("%sexchange.declare:"\
                        " ticket=%d exchange=\"%s\" type=\"%s\" passive=%d durable=%d auto_delete=%d internal=%d nowait=%d arguments=%uB", prefix,
                        self->payload.exchange_declare.ticket,
                        self->payload.exchange_declare.exchange,
                        self->payload.exchange_declare.type,
                        self->payload.exchange_declare.passive,
                        self->payload.exchange_declare.durable,
                        self->payload.exchange_declare.auto_delete,
                        self->payload.exchange_declare.internal,
                        self->payload.exchange_declare.nowait,
                        self->payload.exchange_declare.arguments?
                            self->payload.exchange_declare.arguments->cur_size: 0);
                }
                break;
            case AMQ_CLIENT_EXCHANGE_DECLARE_OK:
                if (log) {
                    smt_log_print (log, "%sexchange.declare-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%sexchange.declare-ok:"\
                        "", prefix);
                }
                break;
            case AMQ_CLIENT_EXCHANGE_DELETE:
                if (log) {
                    smt_log_print (log, "%sexchange.delete:"\
                        " ticket=%d exchange=\"%s\" if_unused=%d nowait=%d", prefix,
                        self->payload.exchange_delete.ticket,
                        self->payload.exchange_delete.exchange,
                        self->payload.exchange_delete.if_unused,
                        self->payload.exchange_delete.nowait);
                }
                else {
                    icl_console_print ("%sexchange.delete:"\
                        " ticket=%d exchange=\"%s\" if_unused=%d nowait=%d", prefix,
                        self->payload.exchange_delete.ticket,
                        self->payload.exchange_delete.exchange,
                        self->payload.exchange_delete.if_unused,
                        self->payload.exchange_delete.nowait);
                }
                break;
            case AMQ_CLIENT_EXCHANGE_DELETE_OK:
                if (log) {
                    smt_log_print (log, "%sexchange.delete-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%sexchange.delete-ok:"\
                        "", prefix);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    case AMQ_CLIENT_QUEUE:
        switch (self->method_id) {
            case AMQ_CLIENT_QUEUE_DECLARE:
                if (log) {
                    smt_log_print (log, "%squeue.declare:"\
                        " ticket=%d queue=\"%s\" passive=%d durable=%d exclusive=%d auto_delete=%d nowait=%d arguments=%uB", prefix,
                        self->payload.queue_declare.ticket,
                        self->payload.queue_declare.queue,
                        self->payload.queue_declare.passive,
                        self->payload.queue_declare.durable,
                        self->payload.queue_declare.exclusive,
                        self->payload.queue_declare.auto_delete,
                        self->payload.queue_declare.nowait,
                        self->payload.queue_declare.arguments?
                            self->payload.queue_declare.arguments->cur_size: 0);
                }
                else {
                    icl_console_print ("%squeue.declare:"\
                        " ticket=%d queue=\"%s\" passive=%d durable=%d exclusive=%d auto_delete=%d nowait=%d arguments=%uB", prefix,
                        self->payload.queue_declare.ticket,
                        self->payload.queue_declare.queue,
                        self->payload.queue_declare.passive,
                        self->payload.queue_declare.durable,
                        self->payload.queue_declare.exclusive,
                        self->payload.queue_declare.auto_delete,
                        self->payload.queue_declare.nowait,
                        self->payload.queue_declare.arguments?
                            self->payload.queue_declare.arguments->cur_size: 0);
                }
                break;
            case AMQ_CLIENT_QUEUE_DECLARE_OK:
                if (log) {
                    smt_log_print (log, "%squeue.declare-ok:"\
                        " queue=\"%s\" message_count=%u consumer_count=%u", prefix,
                        self->payload.queue_declare_ok.queue,
                        self->payload.queue_declare_ok.message_count,
                        self->payload.queue_declare_ok.consumer_count);
                }
                else {
                    icl_console_print ("%squeue.declare-ok:"\
                        " queue=\"%s\" message_count=%u consumer_count=%u", prefix,
                        self->payload.queue_declare_ok.queue,
                        self->payload.queue_declare_ok.message_count,
                        self->payload.queue_declare_ok.consumer_count);
                }
                break;
            case AMQ_CLIENT_QUEUE_BIND:
                if (log) {
                    smt_log_print (log, "%squeue.bind:"\
                        " ticket=%d queue=\"%s\" exchange=\"%s\" routing_key=\"%s\" nowait=%d arguments=%uB", prefix,
                        self->payload.queue_bind.ticket,
                        self->payload.queue_bind.queue,
                        self->payload.queue_bind.exchange,
                        self->payload.queue_bind.routing_key,
                        self->payload.queue_bind.nowait,
                        self->payload.queue_bind.arguments?
                            self->payload.queue_bind.arguments->cur_size: 0);
                }
                else {
                    icl_console_print ("%squeue.bind:"\
                        " ticket=%d queue=\"%s\" exchange=\"%s\" routing_key=\"%s\" nowait=%d arguments=%uB", prefix,
                        self->payload.queue_bind.ticket,
                        self->payload.queue_bind.queue,
                        self->payload.queue_bind.exchange,
                        self->payload.queue_bind.routing_key,
                        self->payload.queue_bind.nowait,
                        self->payload.queue_bind.arguments?
                            self->payload.queue_bind.arguments->cur_size: 0);
                }
                break;
            case AMQ_CLIENT_QUEUE_BIND_OK:
                if (log) {
                    smt_log_print (log, "%squeue.bind-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%squeue.bind-ok:"\
                        "", prefix);
                }
                break;
            case AMQ_CLIENT_QUEUE_PURGE:
                if (log) {
                    smt_log_print (log, "%squeue.purge:"\
                        " ticket=%d queue=\"%s\" nowait=%d", prefix,
                        self->payload.queue_purge.ticket,
                        self->payload.queue_purge.queue,
                        self->payload.queue_purge.nowait);
                }
                else {
                    icl_console_print ("%squeue.purge:"\
                        " ticket=%d queue=\"%s\" nowait=%d", prefix,
                        self->payload.queue_purge.ticket,
                        self->payload.queue_purge.queue,
                        self->payload.queue_purge.nowait);
                }
                break;
            case AMQ_CLIENT_QUEUE_PURGE_OK:
                if (log) {
                    smt_log_print (log, "%squeue.purge-ok:"\
                        " message_count=%u", prefix,
                        self->payload.queue_purge_ok.message_count);
                }
                else {
                    icl_console_print ("%squeue.purge-ok:"\
                        " message_count=%u", prefix,
                        self->payload.queue_purge_ok.message_count);
                }
                break;
            case AMQ_CLIENT_QUEUE_DELETE:
                if (log) {
                    smt_log_print (log, "%squeue.delete:"\
                        " ticket=%d queue=\"%s\" if_unused=%d if_empty=%d nowait=%d", prefix,
                        self->payload.queue_delete.ticket,
                        self->payload.queue_delete.queue,
                        self->payload.queue_delete.if_unused,
                        self->payload.queue_delete.if_empty,
                        self->payload.queue_delete.nowait);
                }
                else {
                    icl_console_print ("%squeue.delete:"\
                        " ticket=%d queue=\"%s\" if_unused=%d if_empty=%d nowait=%d", prefix,
                        self->payload.queue_delete.ticket,
                        self->payload.queue_delete.queue,
                        self->payload.queue_delete.if_unused,
                        self->payload.queue_delete.if_empty,
                        self->payload.queue_delete.nowait);
                }
                break;
            case AMQ_CLIENT_QUEUE_DELETE_OK:
                if (log) {
                    smt_log_print (log, "%squeue.delete-ok:"\
                        " message_count=%u", prefix,
                        self->payload.queue_delete_ok.message_count);
                }
                else {
                    icl_console_print ("%squeue.delete-ok:"\
                        " message_count=%u", prefix,
                        self->payload.queue_delete_ok.message_count);
                }
                break;
            case AMQ_CLIENT_QUEUE_UNBIND:
                if (log) {
                    smt_log_print (log, "%squeue.unbind:"\
                        " ticket=%d queue=\"%s\" exchange=\"%s\" routing_key=\"%s\" nowait=%d arguments=%uB", prefix,
                        self->payload.queue_unbind.ticket,
                        self->payload.queue_unbind.queue,
                        self->payload.queue_unbind.exchange,
                        self->payload.queue_unbind.routing_key,
                        self->payload.queue_unbind.nowait,
                        self->payload.queue_unbind.arguments?
                            self->payload.queue_unbind.arguments->cur_size: 0);
                }
                else {
                    icl_console_print ("%squeue.unbind:"\
                        " ticket=%d queue=\"%s\" exchange=\"%s\" routing_key=\"%s\" nowait=%d arguments=%uB", prefix,
                        self->payload.queue_unbind.ticket,
                        self->payload.queue_unbind.queue,
                        self->payload.queue_unbind.exchange,
                        self->payload.queue_unbind.routing_key,
                        self->payload.queue_unbind.nowait,
                        self->payload.queue_unbind.arguments?
                            self->payload.queue_unbind.arguments->cur_size: 0);
                }
                break;
            case AMQ_CLIENT_QUEUE_UNBIND_OK:
                if (log) {
                    smt_log_print (log, "%squeue.unbind-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%squeue.unbind-ok:"\
                        "", prefix);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    case AMQ_CLIENT_BASIC:
        switch (self->method_id) {
            case AMQ_CLIENT_BASIC_QOS:
                if (log) {
                    smt_log_print (log, "%sbasic.qos:"\
                        " prefetch_size=%u prefetch_count=%d global=%d", prefix,
                        self->payload.basic_qos.prefetch_size,
                        self->payload.basic_qos.prefetch_count,
                        self->payload.basic_qos.global);
                }
                else {
                    icl_console_print ("%sbasic.qos:"\
                        " prefetch_size=%u prefetch_count=%d global=%d", prefix,
                        self->payload.basic_qos.prefetch_size,
                        self->payload.basic_qos.prefetch_count,
                        self->payload.basic_qos.global);
                }
                break;
            case AMQ_CLIENT_BASIC_QOS_OK:
                if (log) {
                    smt_log_print (log, "%sbasic.qos-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%sbasic.qos-ok:"\
                        "", prefix);
                }
                break;
            case AMQ_CLIENT_BASIC_CONSUME:
                if (log) {
                    smt_log_print (log, "%sbasic.consume:"\
                        " ticket=%d queue=\"%s\" consumer_tag=\"%s\" no_local=%d no_ack=%d exclusive=%d nowait=%d arguments=%uB", prefix,
                        self->payload.basic_consume.ticket,
                        self->payload.basic_consume.queue,
                        self->payload.basic_consume.consumer_tag,
                        self->payload.basic_consume.no_local,
                        self->payload.basic_consume.no_ack,
                        self->payload.basic_consume.exclusive,
                        self->payload.basic_consume.nowait,
                        self->payload.basic_consume.arguments?
                            self->payload.basic_consume.arguments->cur_size: 0);
                }
                else {
                    icl_console_print ("%sbasic.consume:"\
                        " ticket=%d queue=\"%s\" consumer_tag=\"%s\" no_local=%d no_ack=%d exclusive=%d nowait=%d arguments=%uB", prefix,
                        self->payload.basic_consume.ticket,
                        self->payload.basic_consume.queue,
                        self->payload.basic_consume.consumer_tag,
                        self->payload.basic_consume.no_local,
                        self->payload.basic_consume.no_ack,
                        self->payload.basic_consume.exclusive,
                        self->payload.basic_consume.nowait,
                        self->payload.basic_consume.arguments?
                            self->payload.basic_consume.arguments->cur_size: 0);
                }
                break;
            case AMQ_CLIENT_BASIC_CONSUME_OK:
                if (log) {
                    smt_log_print (log, "%sbasic.consume-ok:"\
                        " consumer_tag=\"%s\"", prefix,
                        self->payload.basic_consume_ok.consumer_tag);
                }
                else {
                    icl_console_print ("%sbasic.consume-ok:"\
                        " consumer_tag=\"%s\"", prefix,
                        self->payload.basic_consume_ok.consumer_tag);
                }
                break;
            case AMQ_CLIENT_BASIC_CANCEL:
                if (log) {
                    smt_log_print (log, "%sbasic.cancel:"\
                        " consumer_tag=\"%s\" nowait=%d", prefix,
                        self->payload.basic_cancel.consumer_tag,
                        self->payload.basic_cancel.nowait);
                }
                else {
                    icl_console_print ("%sbasic.cancel:"\
                        " consumer_tag=\"%s\" nowait=%d", prefix,
                        self->payload.basic_cancel.consumer_tag,
                        self->payload.basic_cancel.nowait);
                }
                break;
            case AMQ_CLIENT_BASIC_CANCEL_OK:
                if (log) {
                    smt_log_print (log, "%sbasic.cancel-ok:"\
                        " consumer_tag=\"%s\"", prefix,
                        self->payload.basic_cancel_ok.consumer_tag);
                }
                else {
                    icl_console_print ("%sbasic.cancel-ok:"\
                        " consumer_tag=\"%s\"", prefix,
                        self->payload.basic_cancel_ok.consumer_tag);
                }
                break;
            case AMQ_CLIENT_BASIC_PUBLISH:
                if (log) {
                    smt_log_print (log, "%sbasic.publish:"\
                        " ticket=%d exchange=\"%s\" routing_key=\"%s\" mandatory=%d immediate=%d", prefix,
                        self->payload.basic_publish.ticket,
                        self->payload.basic_publish.exchange,
                        self->payload.basic_publish.routing_key,
                        self->payload.basic_publish.mandatory,
                        self->payload.basic_publish.immediate);
                }
                else {
                    icl_console_print ("%sbasic.publish:"\
                        " ticket=%d exchange=\"%s\" routing_key=\"%s\" mandatory=%d immediate=%d", prefix,
                        self->payload.basic_publish.ticket,
                        self->payload.basic_publish.exchange,
                        self->payload.basic_publish.routing_key,
                        self->payload.basic_publish.mandatory,
                        self->payload.basic_publish.immediate);
                }
                break;
            case AMQ_CLIENT_BASIC_RETURN:
                if (log) {
                    smt_log_print (log, "%sbasic.return:"\
                        " reply_code=%d reply_text=\"%s\" exchange=\"%s\" routing_key=\"%s\"", prefix,
                        self->payload.basic_return.reply_code,
                        self->payload.basic_return.reply_text,
                        self->payload.basic_return.exchange,
                        self->payload.basic_return.routing_key);
                }
                else {
                    icl_console_print ("%sbasic.return:"\
                        " reply_code=%d reply_text=\"%s\" exchange=\"%s\" routing_key=\"%s\"", prefix,
                        self->payload.basic_return.reply_code,
                        self->payload.basic_return.reply_text,
                        self->payload.basic_return.exchange,
                        self->payload.basic_return.routing_key);
                }
                break;
            case AMQ_CLIENT_BASIC_DELIVER:
                if (log) {
                    smt_log_print (log, "%sbasic.deliver:"\
                        " consumer_tag=\"%s\" delivery_tag=%lu redelivered=%d exchange=\"%s\" routing_key=\"%s\"", prefix,
                        self->payload.basic_deliver.consumer_tag,
                        (long) self->payload.basic_deliver.delivery_tag,
                        self->payload.basic_deliver.redelivered,
                        self->payload.basic_deliver.exchange,
                        self->payload.basic_deliver.routing_key);
                }
                else {
                    icl_console_print ("%sbasic.deliver:"\
                        " consumer_tag=\"%s\" delivery_tag=%lu redelivered=%d exchange=\"%s\" routing_key=\"%s\"", prefix,
                        self->payload.basic_deliver.consumer_tag,
                        (long) self->payload.basic_deliver.delivery_tag,
                        self->payload.basic_deliver.redelivered,
                        self->payload.basic_deliver.exchange,
                        self->payload.basic_deliver.routing_key);
                }
                break;
            case AMQ_CLIENT_BASIC_GET:
                if (log) {
                    smt_log_print (log, "%sbasic.get:"\
                        " ticket=%d queue=\"%s\" no_ack=%d", prefix,
                        self->payload.basic_get.ticket,
                        self->payload.basic_get.queue,
                        self->payload.basic_get.no_ack);
                }
                else {
                    icl_console_print ("%sbasic.get:"\
                        " ticket=%d queue=\"%s\" no_ack=%d", prefix,
                        self->payload.basic_get.ticket,
                        self->payload.basic_get.queue,
                        self->payload.basic_get.no_ack);
                }
                break;
            case AMQ_CLIENT_BASIC_GET_OK:
                if (log) {
                    smt_log_print (log, "%sbasic.get-ok:"\
                        " delivery_tag=%lu redelivered=%d exchange=\"%s\" routing_key=\"%s\" message_count=%u", prefix,
                        (long) self->payload.basic_get_ok.delivery_tag,
                        self->payload.basic_get_ok.redelivered,
                        self->payload.basic_get_ok.exchange,
                        self->payload.basic_get_ok.routing_key,
                        self->payload.basic_get_ok.message_count);
                }
                else {
                    icl_console_print ("%sbasic.get-ok:"\
                        " delivery_tag=%lu redelivered=%d exchange=\"%s\" routing_key=\"%s\" message_count=%u", prefix,
                        (long) self->payload.basic_get_ok.delivery_tag,
                        self->payload.basic_get_ok.redelivered,
                        self->payload.basic_get_ok.exchange,
                        self->payload.basic_get_ok.routing_key,
                        self->payload.basic_get_ok.message_count);
                }
                break;
            case AMQ_CLIENT_BASIC_GET_EMPTY:
                if (log) {
                    smt_log_print (log, "%sbasic.get-empty:"\
                        " sender_id=\"%s\"", prefix,
                        self->payload.basic_get_empty.sender_id);
                }
                else {
                    icl_console_print ("%sbasic.get-empty:"\
                        " sender_id=\"%s\"", prefix,
                        self->payload.basic_get_empty.sender_id);
                }
                break;
            case AMQ_CLIENT_BASIC_ACK:
                if (log) {
                    smt_log_print (log, "%sbasic.ack:"\
                        " delivery_tag=%lu multiple=%d", prefix,
                        (long) self->payload.basic_ack.delivery_tag,
                        self->payload.basic_ack.multiple);
                }
                else {
                    icl_console_print ("%sbasic.ack:"\
                        " delivery_tag=%lu multiple=%d", prefix,
                        (long) self->payload.basic_ack.delivery_tag,
                        self->payload.basic_ack.multiple);
                }
                break;
            case AMQ_CLIENT_BASIC_REJECT:
                if (log) {
                    smt_log_print (log, "%sbasic.reject:"\
                        " delivery_tag=%lu requeue=%d", prefix,
                        (long) self->payload.basic_reject.delivery_tag,
                        self->payload.basic_reject.requeue);
                }
                else {
                    icl_console_print ("%sbasic.reject:"\
                        " delivery_tag=%lu requeue=%d", prefix,
                        (long) self->payload.basic_reject.delivery_tag,
                        self->payload.basic_reject.requeue);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    case AMQ_CLIENT_DIRECT:
        switch (self->method_id) {
            case AMQ_CLIENT_DIRECT_PUT:
                if (log) {
                    smt_log_print (log, "%sdirect.put:"\
                        " sink=\"%s\"", prefix,
                        self->payload.direct_put.sink);
                }
                else {
                    icl_console_print ("%sdirect.put:"\
                        " sink=\"%s\"", prefix,
                        self->payload.direct_put.sink);
                }
                break;
            case AMQ_CLIENT_DIRECT_PUT_OK:
                if (log) {
                    smt_log_print (log, "%sdirect.put-ok:"\
                        " lease=\"%s\"", prefix,
                        self->payload.direct_put_ok.lease);
                }
                else {
                    icl_console_print ("%sdirect.put-ok:"\
                        " lease=\"%s\"", prefix,
                        self->payload.direct_put_ok.lease);
                }
                break;
            case AMQ_CLIENT_DIRECT_GET:
                if (log) {
                    smt_log_print (log, "%sdirect.get:"\
                        " feed=\"%s\"", prefix,
                        self->payload.direct_get.feed);
                }
                else {
                    icl_console_print ("%sdirect.get:"\
                        " feed=\"%s\"", prefix,
                        self->payload.direct_get.feed);
                }
                break;
            case AMQ_CLIENT_DIRECT_GET_OK:
                if (log) {
                    smt_log_print (log, "%sdirect.get-ok:"\
                        " lease=\"%s\"", prefix,
                        self->payload.direct_get_ok.lease);
                }
                else {
                    icl_console_print ("%sdirect.get-ok:"\
                        " lease=\"%s\"", prefix,
                        self->payload.direct_get_ok.lease);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    default:
        if (log)
            smt_log_print (log, "E: illegal class=%d", self->class_id);
        else
            icl_console_print ("E: illegal class=%d", self->class_id);
}
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DUMP))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_DUMP))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_dump_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" log=\"%pp\""
" prefix=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, log, prefix, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_method_execute

    Type: Component method
    Accepts a amq_client_method_t reference and returns zero in case of success,
    1 in case of errors.
    Accepts a amq_client_method_t object and executes the method.
    Returns 0 if the method was executed successfully, non-zero if there
    was an error - e.g. if the method is not allowed for this chassis.
    -------------------------------------------------------------------------
 */

int
    amq_client_method_execute (
    amq_client_method_t * self,         //  Reference to object
    amq_client_connection_t * connection,   //  Current connection
    amq_client_session_t * session      //  Current session
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_EXECUTE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_execute_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" connection=\"%pp\""
" session=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, connection, session);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_EXECUTE))
    icl_trace_record (NULL, amq_client_method_dump, 35);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_EXECUTE))
    icl_stats_inc ("amq_client_method_execute", &s_amq_client_method_execute_stats);
#endif

AMQ_CLIENT_METHOD_ASSERT_SANE (self);
if (!self->zombie) {

//

if (self->class_id  == AMQ_CLIENT_CONNECTION
&&  self->method_id == AMQ_CLIENT_CONNECTION_START) {
    amq_client_connection_start_t
        *method;
    method = &self->payload.connection_start;
    {
        asl_field_list_t
    *fields;                        //  Decoded responses
char
    *port;                          //  Port number from host string
connection->version_major = method->version_major;
connection->version_minor = method->version_minor;
//
fields = asl_field_list_new (method->server_properties);
if (fields) {
    asl_field_list_cpy (fields, connection->server_host,        "host");
    asl_field_list_cpy (fields, connection->server_instance,    "instance");
    asl_field_list_cpy (fields, connection->server_product,     "product");
    asl_field_list_cpy (fields, connection->server_version,     "version");
    asl_field_list_cpy (fields, connection->server_platform,    "platform");
    asl_field_list_cpy (fields, connection->server_copyright,   "copyright");
    asl_field_list_cpy (fields, connection->server_information, "information");
    asl_field_list_cpy (fields, connection->id,                 "id");
    connection->server_direct = asl_field_list_integer (fields, "direct");

    port = strchr (connection->server_host, ':');
    if (port)
        icl_shortstr_cpy (connection->server_port, port + 1);

    asl_field_list_destroy (&fields);
}
    }
}
else
if (self->class_id  == AMQ_CLIENT_CONNECTION
&&  self->method_id == AMQ_CLIENT_CONNECTION_TUNE) {
    amq_client_connection_tune_t
        *method;
    method = &self->payload.connection_tune;
    {
        connection->channel_max = method->channel_max;
connection->frame_max = method->frame_max;
connection->heartbeat = method->heartbeat;

    }
}
else
if (self->class_id  == AMQ_CLIENT_CONNECTION
&&  self->method_id == AMQ_CLIENT_CONNECTION_OPEN_OK) {
    amq_client_connection_open_ok_t
        *method;
    method = &self->payload.connection_open_ok;
    {
        icl_shortstr_cpy (connection->known_hosts, method->known_hosts);

    }
}
else
if (self->class_id  == AMQ_CLIENT_CONNECTION
&&  self->method_id == AMQ_CLIENT_CONNECTION_CLOSE) {
    amq_client_connection_close_t
        *method;
    method = &self->payload.connection_close;
    {
        connection->reply_code = method->reply_code;
icl_shortstr_cpy (connection->reply_text, method->reply_text);
connection->class_id = method->class_id;
connection->method_id = method->method_id;

    }
}
else
if (self->class_id  == AMQ_CLIENT_CHANNEL
&&  self->method_id == AMQ_CLIENT_CHANNEL_FLOW) {
    amq_client_channel_flow_t
        *method;
    method = &self->payload.channel_flow;
    {
        session->active = method->active;

    }
}
else
if (self->class_id  == AMQ_CLIENT_CHANNEL
&&  self->method_id == AMQ_CLIENT_CHANNEL_FLOW_OK) {
    amq_client_channel_flow_ok_t
        *method;
    method = &self->payload.channel_flow_ok;
    {
        session->active = method->active;

    }
}
else
if (self->class_id  == AMQ_CLIENT_CHANNEL
&&  self->method_id == AMQ_CLIENT_CHANNEL_CLOSE) {
    amq_client_channel_close_t
        *method;
    method = &self->payload.channel_close;
    {
        session->reply_code = method->reply_code;
icl_shortstr_cpy (session->reply_text, method->reply_text);
session->class_id = method->class_id;
session->method_id = method->method_id;

    }
}
else
if (self->class_id  == AMQ_CLIENT_QUEUE
&&  self->method_id == AMQ_CLIENT_QUEUE_DECLARE_OK) {
    amq_client_queue_declare_ok_t
        *method;
    method = &self->payload.queue_declare_ok;
    {
        icl_shortstr_cpy (session->queue, method->queue);
session->message_count = method->message_count;
session->consumer_count = method->consumer_count;

    }
}
else
if (self->class_id  == AMQ_CLIENT_QUEUE
&&  self->method_id == AMQ_CLIENT_QUEUE_PURGE_OK) {
    amq_client_queue_purge_ok_t
        *method;
    method = &self->payload.queue_purge_ok;
    {
        session->message_count = method->message_count;

    }
}
else
if (self->class_id  == AMQ_CLIENT_QUEUE
&&  self->method_id == AMQ_CLIENT_QUEUE_DELETE_OK) {
    amq_client_queue_delete_ok_t
        *method;
    method = &self->payload.queue_delete_ok;
    {
        session->message_count = method->message_count;

    }
}
else
if (self->class_id  == AMQ_CLIENT_BASIC
&&  self->method_id == AMQ_CLIENT_BASIC_CONSUME_OK) {
    amq_client_basic_consume_ok_t
        *method;
    method = &self->payload.basic_consume_ok;
    {
        icl_shortstr_cpy (session->consumer_tag, method->consumer_tag);

    }
}
else
if (self->class_id  == AMQ_CLIENT_BASIC
&&  self->method_id == AMQ_CLIENT_BASIC_CANCEL_OK) {
    amq_client_basic_cancel_ok_t
        *method;
    method = &self->payload.basic_cancel_ok;
    {
        icl_shortstr_cpy (session->consumer_tag, method->consumer_tag);

    }
}
else
if (self->class_id  == AMQ_CLIENT_BASIC
&&  self->method_id == AMQ_CLIENT_BASIC_RETURN) {
    amq_client_basic_return_t
        *method;
    amq_content_basic_t
        *content;
    method = &self->payload.basic_return;
    content = (amq_content_basic_t *) self->content;
    {
        session->reply_code = method->reply_code;
icl_shortstr_cpy (session->reply_text, method->reply_text);
icl_shortstr_cpy (session->exchange, method->exchange);
icl_shortstr_cpy (session->routing_key, method->routing_key);
amq_client_session_push_returned (
    session, content, method->exchange, method->routing_key, NULL);
    }
}
else
if (self->class_id  == AMQ_CLIENT_BASIC
&&  self->method_id == AMQ_CLIENT_BASIC_DELIVER) {
    amq_client_basic_deliver_t
        *method;
    amq_content_basic_t
        *content;
    method = &self->payload.basic_deliver;
    content = (amq_content_basic_t *) self->content;
    {
        icl_shortstr_cpy (session->consumer_tag, method->consumer_tag);
session->delivery_tag = method->delivery_tag;
session->redelivered = method->redelivered;
icl_shortstr_cpy (session->exchange, method->exchange);
icl_shortstr_cpy (session->routing_key, method->routing_key);
if (amq_client_config_sequence_check (amq_client_config)) {
    if (amq_sequence_check (session->sequences, content->sender_id, content->timestamp))
        icl_console_print ("W: message out-of-sequence, routing-key='%s' exchange='%s'",
            content->routing_key, content->exchange);
}
amq_client_session_push_arrived (
    session,
    content,
    method->exchange,
    method->routing_key,
    method->consumer_tag,
    method->delivery_tag);
    }
}
else
if (self->class_id  == AMQ_CLIENT_BASIC
&&  self->method_id == AMQ_CLIENT_BASIC_GET_OK) {
    amq_client_basic_get_ok_t
        *method;
    amq_content_basic_t
        *content;
    method = &self->payload.basic_get_ok;
    content = (amq_content_basic_t *) self->content;
    {
        session->delivery_tag = method->delivery_tag;
session->redelivered = method->redelivered;
icl_shortstr_cpy (session->exchange, method->exchange);
icl_shortstr_cpy (session->routing_key, method->routing_key);
session->message_count = method->message_count;
if (amq_client_config_sequence_check (amq_client_config)) {
    if (amq_sequence_check (session->sequences, content->sender_id, content->timestamp))
        icl_console_print ("W: message out-of-sequence, routing-key='%s' exchange='%s'",
            content->routing_key, content->exchange);
}
amq_client_session_push_arrived (
    session,
    content,
    method->exchange,
    method->routing_key,
    NULL,                           //  No consumer tag for Get-Ok
    method->delivery_tag);
    }
}
else
if (self->class_id  == AMQ_CLIENT_BASIC
&&  self->method_id == AMQ_CLIENT_BASIC_GET_EMPTY) {
    amq_client_basic_get_empty_t
        *method;
    method = &self->payload.basic_get_empty;
    {
        icl_shortstr_cpy (session->sender_id, method->sender_id);

    }
}
else
if (self->class_id  == AMQ_CLIENT_DIRECT
&&  self->method_id == AMQ_CLIENT_DIRECT_PUT_OK) {
    amq_client_direct_put_ok_t
        *method;
    method = &self->payload.direct_put_ok;
    {
        icl_shortstr_cpy (session->lease, method->lease);

    }
}
else
if (self->class_id  == AMQ_CLIENT_DIRECT
&&  self->method_id == AMQ_CLIENT_DIRECT_GET_OK) {
    amq_client_direct_get_ok_t
        *method;
    method = &self->payload.direct_get_ok;
    {
        icl_shortstr_cpy (session->lease, method->lease);

    }
}
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_EXECUTE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 35);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_EXECUTE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_execute_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" connection=\"%pp\""
" session=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, connection, session, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_client_method_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_method_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_SELFTEST))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_SELFTEST))
    icl_trace_record (NULL, amq_client_method_dump, 36);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_SELFTEST))
    icl_stats_inc ("amq_client_method_selftest", &s_amq_client_method_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_SELFTEST))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 36);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_SELFTEST))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_selftest_finish"
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
    amq_client_method_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_method_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_client_method_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_METHOD)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_SHOW))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_SHOW))
    icl_trace_record (NULL, amq_client_method_dump, 37);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_SHOW))
    icl_stats_inc ("amq_client_method_show", &s_amq_client_method_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_client_method zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_METHOD)
    if (self->history_last > AMQ_CLIENT_METHOD_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_CLIENT_METHOD_HISTORY_LENGTH;
        self->history_last %= AMQ_CLIENT_METHOD_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_CLIENT_METHOD_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_client_method>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_SHOW))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 37);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_SHOW))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_show_finish"
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
    amq_client_method_destroy

    Type: Component method
    Destroys a amq_client_method_t object. Takes the address of a
    amq_client_method_t reference (a pointer to a pointer) and nullifies the
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
    amq_client_method_destroy_ (
    amq_client_method_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_client_method_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_DESTROY_PUBLIC))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_client_method_dump, 38);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_DESTROY_PUBLIC))
    icl_stats_inc ("amq_client_method_destroy", &s_amq_client_method_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_client_method_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on amq_client_method object");
        amq_client_method_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_client_method_free_ ((amq_client_method_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 38);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_DESTROY_PUBLIC))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_method_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_client_method_t *
    amq_client_method_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_client_method_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_ALLOC))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_ALLOC))
    icl_trace_record (NULL, amq_client_method_dump, 39);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_ALLOC))
    icl_stats_inc ("amq_client_method_alloc", &s_amq_client_method_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_client_method_cache_initialise ();

self = (amq_client_method_t *) icl_mem_cache_alloc_ (s_cache, file, line);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_ALLOC))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 39);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_ALLOC))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_alloc_finish"
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
    amq_client_method_free

    Type: Component method
    Freess a amq_client_method_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_client_method_free_ (
    amq_client_method_t * self,         //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_METHOD)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_FREE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_FREE))
    icl_trace_record (NULL, amq_client_method_dump, 40);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_FREE))
    icl_stats_inc ("amq_client_method_free", &s_amq_client_method_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_METHOD)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = self->links;
#endif

    self->object_tag = AMQ_CLIENT_METHOD_DEAD;
    icl_mem_free (self);
}
self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_FREE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 40);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_FREE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_method_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_client_method_t *
    amq_client_method_link_ (
    amq_client_method_t * self,         //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_METHOD)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_LINK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_link_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_LINK))
    icl_trace_record (NULL, amq_client_method_dump, 41);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_LINK))
    icl_stats_inc ("amq_client_method_link", &s_amq_client_method_link_stats);
#endif

    if (self) {
        AMQ_CLIENT_METHOD_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_METHOD)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_LINK))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 41);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_LINK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_link_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_method_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_client_method_unlink_ (
    amq_client_method_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_METHOD)
    int
        history_last;
#endif

    amq_client_method_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_UNLINK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_unlink_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_UNLINK))
    icl_trace_record (NULL, amq_client_method_dump, 42);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_UNLINK))
    icl_stats_inc ("amq_client_method_unlink", &s_amq_client_method_unlink_stats);
#endif

    if (self) {
        AMQ_CLIENT_METHOD_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_client_method object");
            amq_client_method_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_METHOD)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_CLIENT_METHOD_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_client_method_annihilate_ (self_p, file, line);
        amq_client_method_free_ ((amq_client_method_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_UNLINK))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 42);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_UNLINK))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_unlink_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_method_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_client_method_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_CACHE_INITIALISE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_client_method_dump, 43);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_CACHE_INITIALISE))
    icl_stats_inc ("amq_client_method_cache_initialise", &s_amq_client_method_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_client_method_t));
icl_system_register (amq_client_method_cache_purge, amq_client_method_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 43);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_CACHE_INITIALISE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_cache_initialise_finish"
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
    amq_client_method_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_method_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_CACHE_PURGE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_CACHE_PURGE))
    icl_trace_record (NULL, amq_client_method_dump, 44);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_CACHE_PURGE))
    icl_stats_inc ("amq_client_method_cache_purge", &s_amq_client_method_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_CACHE_PURGE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 44);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_CACHE_PURGE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_cache_purge_finish"
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
    amq_client_method_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_method_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_CACHE_TERMINATE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_client_method_dump, 45);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_CACHE_TERMINATE))
    icl_stats_inc ("amq_client_method_cache_terminate", &s_amq_client_method_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 45);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_CACHE_TERMINATE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_cache_terminate_finish"
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
    amq_client_method_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_client_method_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_ANIMATE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_ANIMATE))
    icl_trace_record (NULL, amq_client_method_dump, 46);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_ANIMATE))
    icl_stats_inc ("amq_client_method_animate", &s_amq_client_method_animate_stats);
#endif

amq_client_method_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_ANIMATE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 46);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_ANIMATE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_animate_finish"
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
    amq_client_method_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_method_new_in_scope_ (
    amq_client_method_t * * self_p,     //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_IN_SCOPE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_client_method_dump, 47);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD)  ||  defined (BASE_STATS_AMQ_CLIENT_METHOD_NEW_IN_SCOPE))
    icl_stats_inc ("amq_client_method_new_in_scope", &s_amq_client_method_new_in_scope_stats);
#endif

*self_p = amq_client_method_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_client_method_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_client_method_dump, 0x10000 + 47);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD)   || defined (BASE_ANIMATE_AMQ_CLIENT_METHOD_NEW_IN_SCOPE))
    if (amq_client_method_animating)
        icl_console_print ("<amq_client_method_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DESTROY)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_INITIALISE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_TERMINATE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_START_OK)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_SECURE_OK)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_TUNE_OK)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_OPEN)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CONNECTION_CLOSE_OK)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_OPEN)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_FLOW_OK)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_CHANNEL_CLOSE_OK)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DECLARE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_EXCHANGE_DELETE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_DECLARE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_BIND)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_PURGE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_DELETE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_QUEUE_UNBIND)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_QOS)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_CONSUME)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_CANCEL)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_PUBLISH)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_GET)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_ACK)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_BASIC_REJECT)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_DIRECT_PUT)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_DIRECT_GET)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_ENCODE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DECODE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DUMP)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_EXECUTE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_SELFTEST)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_SHOW)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_ALLOC)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_FREE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_LINK)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_UNLINK)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_ANIMATE)   || defined (BASE_TRACE_AMQ_CLIENT_METHOD_NEW_IN_SCOPE) )
void
amq_client_method_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "initialise"; break;
        case 4: method_name = "terminate"; break;
        case 5: method_name = "new connection start-ok"; break;
        case 6: method_name = "new connection secure-ok"; break;
        case 7: method_name = "new connection tune-ok"; break;
        case 8: method_name = "new connection open"; break;
        case 9: method_name = "new connection close"; break;
        case 10: method_name = "new connection close-ok"; break;
        case 11: method_name = "new channel open"; break;
        case 12: method_name = "new channel flow"; break;
        case 13: method_name = "new channel flow-ok"; break;
        case 14: method_name = "new channel close"; break;
        case 15: method_name = "new channel close-ok"; break;
        case 16: method_name = "new exchange declare"; break;
        case 17: method_name = "new exchange delete"; break;
        case 18: method_name = "new queue declare"; break;
        case 19: method_name = "new queue bind"; break;
        case 20: method_name = "new queue purge"; break;
        case 21: method_name = "new queue delete"; break;
        case 22: method_name = "new queue unbind"; break;
        case 23: method_name = "new basic qos"; break;
        case 24: method_name = "new basic consume"; break;
        case 25: method_name = "new basic cancel"; break;
        case 26: method_name = "new basic publish"; break;
        case 27: method_name = "new basic get"; break;
        case 28: method_name = "new basic ack"; break;
        case 29: method_name = "new basic reject"; break;
        case 30: method_name = "new direct put"; break;
        case 31: method_name = "new direct get"; break;
        case 32: method_name = "encode"; break;
        case 33: method_name = "decode"; break;
        case 34: method_name = "dump"; break;
        case 35: method_name = "execute"; break;
        case 36: method_name = "selftest"; break;
        case 37: method_name = "show"; break;
        case 38: method_name = "destroy public"; break;
        case 39: method_name = "alloc"; break;
        case 40: method_name = "free"; break;
        case 41: method_name = "link"; break;
        case 42: method_name = "unlink"; break;
        case 43: method_name = "cache initialise"; break;
        case 44: method_name = "cache purge"; break;
        case 45: method_name = "cache terminate"; break;
        case 46: method_name = "animate"; break;
        case 47: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_client_method %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_client_method_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_client_method_component  = "amq_client_method ";
char *amq_client_method_version    = "1.0 ";
char *amq_client_method_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_client_method_filename   = "amq_client_method.icl ";
char *amq_client_method_builddate  = "2010/10/06 ";
char *amq_client_method_version_end  = "VeRsIoNeNd:ipc";

