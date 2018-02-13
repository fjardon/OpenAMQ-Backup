/*---------------------------------------------------------------------------
    amq_federation_agent.h - prototypes for amq_federation_agent.

    Generated from amq_federation_agent.smt by smt_gen.gsl using GSL/4.

    
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
# ifndef INCLUDE_AMQ_FEDERATION_AGENT_SAFE
#   define INCLUDE_AMQ_FEDERATION_AGENT_SAFE
#   define INCLUDE_AMQ_FEDERATION_AGENT_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_FEDERATION_AGENT_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif

#   include "amq_federation.h"

#   undef INCLUDE_AMQ_FEDERATION_AGENT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_FEDERATION_AGENT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_FEDERATION_AGENT_UNSAFE
#   define INCLUDE_AMQ_FEDERATION_AGENT_UNSAFE
#   define INCLUDE_AMQ_FEDERATION_AGENT_ACTIVE

#   include "amq_federation.h"
#ifdef __cplusplus
extern "C" {
#endif

int
amq_federation_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line);

int
amq_federation_agent_binding_created (
    smt_thread_t * thread,
    char *                routing_key,
    icl_longstr_t *       arguments,
    Bool                  exclusive);

int
amq_federation_agent_binding_destroyed (
    smt_thread_t * thread,
    char *                routing_key,
    icl_longstr_t *       arguments);

int
amq_federation_agent_message_published (
    smt_thread_t * thread,
    amq_content_basic_t * content,
    Bool                  mandatory,
    Bool                  immediate);

int  amq_federation_agent_init (void);
void amq_federation_agent_term (void);
void amq_federation_agent_animate (Bool animate);
smt_thread_t *amq_federation_agent_class_thread_new (
    amq_federation_t * self);

#ifdef __cplusplus
}
#endif


#   undef INCLUDE_AMQ_FEDERATION_AGENT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_FEDERATION_AGENT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_FEDERATION_AGENT_INLINE)
#   define INCLUDE_AMQ_FEDERATION_AGENT_INLINE
#   define INCLUDE_AMQ_FEDERATION_AGENT_ACTIVE

#   include "amq_federation.h"

#   undef INCLUDE_AMQ_FEDERATION_AGENT_ACTIVE
#   if defined (ICL_IMPORT_AMQ_FEDERATION_AGENT_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_FEDERATION_AGENT_ROOT
#   endif
# endif
#endif
