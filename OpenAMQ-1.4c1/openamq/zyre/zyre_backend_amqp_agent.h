/*---------------------------------------------------------------------------
    zyre_backend_amqp_agent.h - prototypes for zyre_backend_amqp_agent.

    Generated from zyre_backend_amqp_agent.smt by smt_gen.gsl using GSL/4.

    
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
# ifndef INCLUDE_ZYRE_BACKEND_AMQP_AGENT_SAFE
#   define INCLUDE_ZYRE_BACKEND_AMQP_AGENT_SAFE
#   define INCLUDE_ZYRE_BACKEND_AMQP_AGENT_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_BACKEND_AMQP_AGENT_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif

#   include "zyre_backend_amqp.h"

#   undef INCLUDE_ZYRE_BACKEND_AMQP_AGENT_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_BACKEND_AMQP_AGENT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_BACKEND_AMQP_AGENT_UNSAFE
#   define INCLUDE_ZYRE_BACKEND_AMQP_AGENT_UNSAFE
#   define INCLUDE_ZYRE_BACKEND_AMQP_AGENT_ACTIVE

#   include "zyre_backend_amqp.h"
#ifdef __cplusplus
extern "C" {
#endif

int
zyre_backend_amqp_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line);

int
zyre_backend_amqp_agent_start (
    smt_thread_t * thread,
    zyre_backend_t *      portal);

int
zyre_backend_amqp_agent_stop (
    smt_thread_t * thread,
    zyre_backend_t *      portal);

int
zyre_backend_amqp_agent_pipe_create (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                pipe_type,
    char *                pipe_name);

int
zyre_backend_amqp_agent_pipe_delete (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                pipe_name);

int
zyre_backend_amqp_agent_feed_create (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                feed_type,
    char *                feed_name);

int
zyre_backend_amqp_agent_feed_delete (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                feed_name);

int
zyre_backend_amqp_agent_join_create (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                pipe_name,
    char *                feed_name,
    char *                address);

int
zyre_backend_amqp_agent_join_delete (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                pipe_name,
    char *                feed_name,
    char *                address);

int
zyre_backend_amqp_agent_address_post (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                address,
    char *                feed_name,
    amq_content_basic_t * content);

int
zyre_backend_amqp_agent_forward (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                exchange,
    char *                routing_key,
    amq_content_basic_t * content,
    Bool                  mandatory,
    Bool                  immediate);

int
zyre_backend_amqp_agent_online_partial (
    smt_thread_t * thread,
    zyre_backend_t *      portal);

int
zyre_backend_amqp_agent_online_final (
    smt_thread_t * thread,
    zyre_backend_t *      portal);

int
zyre_backend_amqp_agent__zyre_backend_unbind (
    smt_thread_t * thread,
    zyre_backend_t *      portal);

int  zyre_backend_amqp_agent_init (void);
void zyre_backend_amqp_agent_term (void);
void zyre_backend_amqp_agent_animate (Bool animate);
smt_thread_t *zyre_backend_amqp_agent_class_thread_new (
    zyre_backend_amqp_t * self);

#ifdef __cplusplus
}
#endif


#   undef INCLUDE_ZYRE_BACKEND_AMQP_AGENT_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_BACKEND_AMQP_AGENT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_BACKEND_AMQP_AGENT_INLINE)
#   define INCLUDE_ZYRE_BACKEND_AMQP_AGENT_INLINE
#   define INCLUDE_ZYRE_BACKEND_AMQP_AGENT_ACTIVE

#   include "zyre_backend_amqp.h"

#   undef INCLUDE_ZYRE_BACKEND_AMQP_AGENT_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_BACKEND_AMQP_AGENT_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_BACKEND_AMQP_AGENT_ROOT
#   endif
# endif
#endif
