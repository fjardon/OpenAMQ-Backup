/*---------------------------------------------------------------------------
    amq_server_classes.h - amq_server_classes component

    Generated from amq_server_classes.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_SERVER_CLASSES_SAFE
#   define INCLUDE_AMQ_SERVER_CLASSES_SAFE
#   define INCLUDE_AMQ_SERVER_CLASSES_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_SERVER_CLASSES_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif

#   include "amq_binding.h"
#   include "amq_binding_mgt.h"
#   include "amq_broker.h"
#   include "amq_client_method.h"
#   include "amq_cml.h"
#   include "amq_console.h"
#   include "amq_console_class.h"
#   include "amq_console_config.h"
#   include "amq_consumer.h"
#   include "amq_consumer_basic.h"
#   include "amq_connection.h"
#   include "amq_connection_queue.h"
#   include "amq_content_basic.h"
#   include "amq_exchange.h"
#   include "amq_exchange_direct.h"
#   include "amq_exchange_headers.h"
#   include "amq_exchange_fanout.h"
#   include "amq_exchange_regexp.h"
#   include "amq_exchange_system.h"
#   include "amq_exchange_topic.h"
#   include "amq_failover.h"
#   include "amq_federation.h"
#   include "amq_hitset.h"
#   include "amq_index.h"
#   include "amq_lease.h"
#   include "amq_queue.h"
#   include "amq_queue_basic.h"
#   include "amq_queue_binding.h"
#   include "amq_queue_connection.h"
#   include "amq_queue_set.h"
#   include "amq_peer_agent.h"
#   include "amq_peer_config.h"
#   include "amq_peering.h"
#   include "amq_resource.h"
#   include "amq_server_channel.h"
#   include "amq_server_config.h"
#   include "amq_server_connection.h"
#   include "amq_server_resource.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CLASSES_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CLASSES_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_SERVER_CLASSES_UNSAFE
#   define INCLUDE_AMQ_SERVER_CLASSES_UNSAFE
#   define INCLUDE_AMQ_SERVER_CLASSES_ACTIVE

#   include "amq_binding.h"
#   include "amq_binding_mgt.h"
#   include "amq_broker.h"
#   include "amq_client_method.h"
#   include "amq_cml.h"
#   include "amq_console.h"
#   include "amq_console_class.h"
#   include "amq_console_config.h"
#   include "amq_consumer.h"
#   include "amq_consumer_basic.h"
#   include "amq_connection.h"
#   include "amq_connection_queue.h"
#   include "amq_content_basic.h"
#   include "amq_exchange.h"
#   include "amq_exchange_direct.h"
#   include "amq_exchange_headers.h"
#   include "amq_exchange_fanout.h"
#   include "amq_exchange_regexp.h"
#   include "amq_exchange_system.h"
#   include "amq_exchange_topic.h"
#   include "amq_failover.h"
#   include "amq_federation.h"
#   include "amq_hitset.h"
#   include "amq_index.h"
#   include "amq_lease.h"
#   include "amq_queue.h"
#   include "amq_queue_basic.h"
#   include "amq_queue_binding.h"
#   include "amq_queue_connection.h"
#   include "amq_queue_set.h"
#   include "amq_peer_agent.h"
#   include "amq_peer_config.h"
#   include "amq_peering.h"
#   include "amq_resource.h"
#   include "amq_server_channel.h"
#   include "amq_server_config.h"
#   include "amq_server_connection.h"
#   include "amq_server_resource.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CLASSES_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CLASSES_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_SERVER_CLASSES_INLINE)
#   define INCLUDE_AMQ_SERVER_CLASSES_INLINE
#   define INCLUDE_AMQ_SERVER_CLASSES_ACTIVE

#   include "amq_binding.h"
#   include "amq_binding_mgt.h"
#   include "amq_broker.h"
#   include "amq_client_method.h"
#   include "amq_cml.h"
#   include "amq_console.h"
#   include "amq_console_class.h"
#   include "amq_console_config.h"
#   include "amq_consumer.h"
#   include "amq_consumer_basic.h"
#   include "amq_connection.h"
#   include "amq_connection_queue.h"
#   include "amq_content_basic.h"
#   include "amq_exchange.h"
#   include "amq_exchange_direct.h"
#   include "amq_exchange_headers.h"
#   include "amq_exchange_fanout.h"
#   include "amq_exchange_regexp.h"
#   include "amq_exchange_system.h"
#   include "amq_exchange_topic.h"
#   include "amq_failover.h"
#   include "amq_federation.h"
#   include "amq_hitset.h"
#   include "amq_index.h"
#   include "amq_lease.h"
#   include "amq_queue.h"
#   include "amq_queue_basic.h"
#   include "amq_queue_binding.h"
#   include "amq_queue_connection.h"
#   include "amq_queue_set.h"
#   include "amq_peer_agent.h"
#   include "amq_peer_config.h"
#   include "amq_peering.h"
#   include "amq_resource.h"
#   include "amq_server_channel.h"
#   include "amq_server_config.h"
#   include "amq_server_connection.h"
#   include "amq_server_resource.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CLASSES_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CLASSES_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_SERVER_CLASSES_ROOT
#   endif
# endif
#endif
