/*---------------------------------------------------------------------------
    amq_server_agent.h - prototypes for amq_server_agent.

    Generated from amq_server_agent.smt by smt_gen.gsl using GSL/4.

    
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
# ifndef INCLUDE_AMQ_SERVER_AGENT_SAFE
#   define INCLUDE_AMQ_SERVER_AGENT_SAFE
#   define INCLUDE_AMQ_SERVER_AGENT_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_SERVER_AGENT_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "amq_broker.h"
#   include "amq_lease.h"
#   include "amq_server_method.h"

#   undef INCLUDE_AMQ_SERVER_AGENT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_AGENT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_SERVER_AGENT_UNSAFE
#   define INCLUDE_AMQ_SERVER_AGENT_UNSAFE
#   define INCLUDE_AMQ_SERVER_AGENT_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "amq_broker.h"
#   include "amq_lease.h"
#   include "amq_server_method.h"
#ifdef __cplusplus
extern "C" {
#endif

int
amq_server_agent_kill_connection (
    smt_thread_t * thread);

int
amq_server_agent_connection_start_ok (
    smt_thread_t * thread);

int
amq_server_agent_connection_tune_ok (
    smt_thread_t * thread);

int
amq_server_agent_connection_open (
    smt_thread_t * thread);

int
amq_server_agent_send_channel_open_ok (
    smt_thread_t * thread);

int
amq_server_agent_send_channel_close_ok (
    smt_thread_t * thread);

int
amq_server_agent_connection_close_ok (
    smt_thread_t * thread);

int
amq_server_agent_shutdown (
    smt_thread_t * thread);

int
amq_server_agent_set_trace (
    smt_thread_t * thread,
    int                   trace);

int
amq_server_agent_connection_error (
    smt_thread_t * thread,
    dbyte                 reply_code,
    char *                reply_text,
    dbyte                 faulting_method_id,
    dbyte                 faulting_class_id);

int
amq_server_agent_channel_error (
    smt_thread_t * thread,
    amq_server_channel_t * channel,
    dbyte                 reply_code,
    char *                reply_text,
    dbyte                 faulting_method_id,
    dbyte                 faulting_class_id);

int
amq_server_agent_channel_flow (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    Bool                  active);

int
amq_server_agent_channel_flow_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    Bool                  active);

int
amq_server_agent_exchange_declare_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr);

int
amq_server_agent_exchange_delete_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr);

int
amq_server_agent_queue_declare_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                queue,
    qbyte                 message_count,
    qbyte                 consumer_count);

int
amq_server_agent_queue_bind_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr);

int
amq_server_agent_queue_purge_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    qbyte                 message_count);

int
amq_server_agent_queue_delete_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    qbyte                 message_count);

int
amq_server_agent_queue_unbind_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr);

int
amq_server_agent_basic_qos_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr);

int
amq_server_agent_basic_consume_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                consumer_tag);

int
amq_server_agent_basic_cancel_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                consumer_tag);

int
amq_server_agent_basic_return (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    amq_content_basic_t * content,
    int                   reply_code,
    char *                reply_text,
    char *                exchange,
    char *                routing_key,
    void *                callback);

int
amq_server_agent_basic_deliver (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    amq_content_basic_t * content,
    char *                consumer_tag,
    int64_t               delivery_tag,
    Bool                  redelivered,
    char *                exchange,
    char *                routing_key,
    void *                callback);

int
amq_server_agent_basic_get_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    amq_content_basic_t * content,
    int64_t               delivery_tag,
    Bool                  redelivered,
    char *                exchange,
    char *                routing_key,
    qbyte                 message_count,
    void *                callback);

int
amq_server_agent_basic_get_empty (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                sender_id);

int
amq_server_agent_direct_put_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                lease);

int
amq_server_agent_direct_get_ok (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    char *                lease);

int
amq_server_agent_push (
    smt_thread_t * thread,
    dbyte                 channel_nbr,
    amq_server_method_t * method);

int
amq_server_agent_direct_out (
    smt_thread_t * thread,
    amq_content_basic_t * content,
    byte                  options);

int  amq_server_agent_init (
    smt_thread_t ** thread_p);
void amq_server_agent_term (void);
void amq_server_agent_animate (Bool animate);
smt_thread_t *amq_server_agent_master_thread_new (void);
smt_thread_t *amq_server_agent_connection_thread_new (void);
smt_thread_t *amq_server_agent_input_thread_new (
    smt_thread_t * share);
smt_thread_t *amq_server_agent_heartbeat_thread_new (
    smt_thread_t * share);

#ifdef __cplusplus
}
#endif


#   undef INCLUDE_AMQ_SERVER_AGENT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_AGENT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_SERVER_AGENT_INLINE)
#   define INCLUDE_AMQ_SERVER_AGENT_INLINE
#   define INCLUDE_AMQ_SERVER_AGENT_ACTIVE

#   include "asl.h"
#   include "asl_field.h"
#   include "amq_constants.h"
#   include "amq_broker.h"
#   include "amq_lease.h"
#   include "amq_server_method.h"

#   undef INCLUDE_AMQ_SERVER_AGENT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_AGENT_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_SERVER_AGENT_ROOT
#   endif
# endif
#endif
