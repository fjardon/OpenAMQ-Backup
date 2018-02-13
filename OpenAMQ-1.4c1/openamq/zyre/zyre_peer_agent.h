/*---------------------------------------------------------------------------
    zyre_peer_agent.h - prototypes for zyre_peer_agent.

    Generated from zyre_peer_agent.smt by smt_gen.gsl using GSL/4.

    
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

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_ZYRE_PEER_AGENT_SAFE
#   define INCLUDE_ZYRE_PEER_AGENT_SAFE
#   define INCLUDE_ZYRE_PEER_AGENT_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_PEER_AGENT_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "zyre_peer_method.h"
#   include "amq_content_basic.h"

//  See session layer for what these mean
#define ZYRE_PEER_REPLY_ALMOST       1
#define ZYRE_PEER_REPLY_INTERN       2
#define ZYRE_PEER_REPLY_METHOD       3
#define ZYRE_PEER_REPLY_CLOSED       4
#define ZYRE_PEER_REPLY_DIRECT_OK    5
#define ZYRE_PEER_REPLY_DIRECT_NG    6
#define ZYRE_PEER_REPLY_DIRECT_MSG 7

#   undef INCLUDE_ZYRE_PEER_AGENT_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PEER_AGENT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_PEER_AGENT_UNSAFE
#   define INCLUDE_ZYRE_PEER_AGENT_UNSAFE
#   define INCLUDE_ZYRE_PEER_AGENT_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "zyre_peer_method.h"
#   include "amq_content_basic.h"
#ifdef __cplusplus
extern "C" {
#endif

int
zyre_peer_agent_connection_close (
    smt_thread_t * thread);

int
zyre_peer_agent_connection_tune (
    smt_thread_t * thread);

int
zyre_peer_agent_connection_open_ok (
    smt_thread_t * thread);

int
zyre_peer_agent_send_channel_close_ok (
    smt_thread_t * thread);

int
zyre_peer_agent_connection_close_ok (
    smt_thread_t * thread);

int
zyre_peer_agent_channel_open (
    smt_thread_t * thread,
    dbyte                 channel_nbr);

int
zyre_peer_agent_channel_close (
    smt_thread_t * thread,
    dbyte                 channel_nbr);

int
zyre_peer_agent_channel_flow (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    Bool                  active);

int
zyre_peer_agent_channel_flow_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    Bool                  active);

int
zyre_peer_agent_exchange_declare (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                exchange,
    char *                type,
    Bool                  passive,
    Bool                  durable,
    Bool                  auto_delete,
    Bool                  internal,
    Bool                  nowait,
    icl_longstr_t *       arguments);

int
zyre_peer_agent_exchange_delete (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                exchange,
    Bool                  if_unused,
    Bool                  nowait);

int
zyre_peer_agent_queue_declare (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    Bool                  passive,
    Bool                  durable,
    Bool                  exclusive,
    Bool                  auto_delete,
    Bool                  nowait,
    icl_longstr_t *       arguments);

int
zyre_peer_agent_queue_bind (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    char *                exchange,
    char *                routing_key,
    Bool                  nowait,
    icl_longstr_t *       arguments);

int
zyre_peer_agent_queue_purge (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    Bool                  nowait);

int
zyre_peer_agent_queue_delete (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    Bool                  if_unused,
    Bool                  if_empty,
    Bool                  nowait);

int
zyre_peer_agent_queue_unbind (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    char *                exchange,
    char *                routing_key,
    Bool                  nowait,
    icl_longstr_t *       arguments);

int
zyre_peer_agent_basic_qos (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    qbyte                 prefetch_size,
    int                   prefetch_count,
    Bool                  global);

int
zyre_peer_agent_basic_consume (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    char *                consumer_tag,
    Bool                  no_local,
    Bool                  no_ack,
    Bool                  exclusive,
    Bool                  nowait,
    icl_longstr_t *       arguments);

int
zyre_peer_agent_basic_cancel (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                consumer_tag,
    Bool                  nowait);

int
zyre_peer_agent_basic_publish (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    amq_content_basic_t * content,
    int                   ticket,
    char *                exchange,
    char *                routing_key,
    Bool                  mandatory,
    Bool                  immediate);

int
zyre_peer_agent_basic_get (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    Bool                  no_ack);

int
zyre_peer_agent_basic_ack (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int64_t               delivery_tag,
    Bool                  multiple);

int
zyre_peer_agent_basic_reject (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int64_t               delivery_tag,
    Bool                  requeue);

int
zyre_peer_agent_direct_put (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                sink);

int
zyre_peer_agent_direct_get (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                feed);

int
zyre_peer_agent_restms_pipe_create (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                pipe_type,
    char *                pipe_name);

int
zyre_peer_agent_restms_pipe_delete (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                pipe_name);

int
zyre_peer_agent_restms_feed_create (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                feed_type,
    char *                feed_name);

int
zyre_peer_agent_restms_feed_delete (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                feed_name);

int
zyre_peer_agent_restms_join_create (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                pipe_name,
    char *                feed_name,
    char *                address);

int
zyre_peer_agent_restms_join_delete (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                pipe_name,
    char *                feed_name,
    char *                address);

int
zyre_peer_agent_push (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    zyre_peer_method_t *  method);

int  zyre_peer_agent_init (void);
void zyre_peer_agent_term (void);
void zyre_peer_agent_animate (Bool animate);
smt_thread_t *zyre_peer_agent_connection_thread_new (
    zyre_backend_t * caller,
    char * host,
    char * virtual_host,
    icl_longstr_t * auth_data,
    char * instance,
    int trace,
    int timeout,
    Bool verbose);
smt_thread_t *zyre_peer_agent_input_thread_new (
    smt_thread_t * share);
smt_thread_t *zyre_peer_agent_heartbeat_thread_new (
    smt_thread_t * share);

#ifdef __cplusplus
}
#endif


#   undef INCLUDE_ZYRE_PEER_AGENT_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PEER_AGENT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_PEER_AGENT_INLINE)
#   define INCLUDE_ZYRE_PEER_AGENT_INLINE
#   define INCLUDE_ZYRE_PEER_AGENT_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "zyre_peer_method.h"
#   include "amq_content_basic.h"

#   undef INCLUDE_ZYRE_PEER_AGENT_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_PEER_AGENT_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_PEER_AGENT_ROOT
#   endif
# endif
#endif
