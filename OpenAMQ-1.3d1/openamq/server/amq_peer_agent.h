/*---------------------------------------------------------------------------
    amq_peer_agent.h - prototypes for amq_peer_agent.

    Generated from amq_peer_agent.smt by smt_gen.gsl using GSL/4.

    
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
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_AMQ_PEER_AGENT_SAFE
#   define INCLUDE_AMQ_PEER_AGENT_SAFE
#   define INCLUDE_AMQ_PEER_AGENT_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_PEER_AGENT_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "amq_peer_method.h"
#   include "amq_content_basic.h"

//  See session layer for what these mean
#define AMQ_PEER_REPLY_ALMOST        1
#define AMQ_PEER_REPLY_INTERN        2
#define AMQ_PEER_REPLY_METHOD        3
#define AMQ_PEER_REPLY_CLOSED        4
#define AMQ_PEER_REPLY_DIRECT_OK     5
#define AMQ_PEER_REPLY_DIRECT_NG     6
#define AMQ_PEER_REPLY_DIRECT_MSG 7

#   undef INCLUDE_AMQ_PEER_AGENT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEER_AGENT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_PEER_AGENT_UNSAFE
#   define INCLUDE_AMQ_PEER_AGENT_UNSAFE
#   define INCLUDE_AMQ_PEER_AGENT_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "amq_peer_method.h"
#   include "amq_content_basic.h"
#ifdef __cplusplus
extern "C" {
#endif

int
amq_peer_agent_connection_close (
    smt_thread_t * thread);

int
amq_peer_agent_connection_tune (
    smt_thread_t * thread);

int
amq_peer_agent_connection_open_ok (
    smt_thread_t * thread);

int
amq_peer_agent_send_channel_close_ok (
    smt_thread_t * thread);

int
amq_peer_agent_connection_close_ok (
    smt_thread_t * thread);

int
amq_peer_agent_channel_open (
    smt_thread_t * thread,
    dbyte                 channel_nbr);

int
amq_peer_agent_channel_close (
    smt_thread_t * thread,
    dbyte                 channel_nbr);

int
amq_peer_agent_channel_flow (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    Bool                  active);

int
amq_peer_agent_channel_flow_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    Bool                  active);

int
amq_peer_agent_exchange_declare (
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
amq_peer_agent_exchange_delete (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                exchange,
    Bool                  if_unused,
    Bool                  nowait);

int
amq_peer_agent_queue_declare (
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
amq_peer_agent_queue_bind (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    char *                exchange,
    char *                routing_key,
    Bool                  nowait,
    icl_longstr_t *       arguments);

int
amq_peer_agent_queue_purge (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    Bool                  nowait);

int
amq_peer_agent_queue_delete (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    Bool                  if_unused,
    Bool                  if_empty,
    Bool                  nowait);

int
amq_peer_agent_queue_unbind (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    char *                exchange,
    char *                routing_key,
    Bool                  nowait,
    icl_longstr_t *       arguments);

int
amq_peer_agent_basic_qos (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    qbyte                 prefetch_size,
    int                   prefetch_count,
    Bool                  global);

int
amq_peer_agent_basic_consume (
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
amq_peer_agent_basic_cancel (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                consumer_tag,
    Bool                  nowait);

int
amq_peer_agent_basic_publish (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    amq_content_basic_t * content,
    int                   ticket,
    char *                exchange,
    char *                routing_key,
    Bool                  mandatory,
    Bool                  immediate);

int
amq_peer_agent_basic_get (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int                   ticket,
    char *                queue,
    Bool                  no_ack);

int
amq_peer_agent_basic_ack (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int64_t               delivery_tag,
    Bool                  multiple);

int
amq_peer_agent_basic_reject (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    int64_t               delivery_tag,
    Bool                  requeue);

int
amq_peer_agent_direct_put (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                sink);

int
amq_peer_agent_direct_get (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                feed);

int
amq_peer_agent_push (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    amq_peer_method_t *   method);

int  amq_peer_agent_init (void);
void amq_peer_agent_term (void);
void amq_peer_agent_animate (Bool animate);
smt_thread_t *amq_peer_agent_connection_thread_new (
    amq_peering_t * caller,
    char * host,
    char * virtual_host,
    icl_longstr_t * auth_data,
    char * instance,
    int trace,
    int timeout,
    Bool verbose);
smt_thread_t *amq_peer_agent_input_thread_new (
    smt_thread_t * share);
smt_thread_t *amq_peer_agent_heartbeat_thread_new (
    smt_thread_t * share);

#ifdef __cplusplus
}
#endif


#   undef INCLUDE_AMQ_PEER_AGENT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEER_AGENT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_PEER_AGENT_INLINE)
#   define INCLUDE_AMQ_PEER_AGENT_INLINE
#   define INCLUDE_AMQ_PEER_AGENT_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "amq_peer_method.h"
#   include "amq_content_basic.h"

#   undef INCLUDE_AMQ_PEER_AGENT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_PEER_AGENT_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_PEER_AGENT_ROOT
#   endif
# endif
#endif
