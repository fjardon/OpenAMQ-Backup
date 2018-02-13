/*---------------------------------------------------------------------------
    amq_server_classes.hpp - amq_server_classes component wrapper in C++

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
 *---------------------------------------------------------------------------*/

#if !defined(AMQ_SERVER_CLASSES_PHASE) || AMQ_SERVER_CLASSES_PHASE==1
#ifndef AMQ_SERVER_CLASSES_PHASE_1_INCLUDED
#define AMQ_SERVER_CLASSES_PHASE_1_INCLUDED



#ifndef   AMQ_BINDING_PHASE_1_INCLUDED
#define   AMQ_BINDING_PHASE 1
#include  "amq_binding.hpp"
#undef    AMQ_BINDING_PHASE
#endif
#ifndef   AMQ_BINDING_MGT_PHASE_1_INCLUDED
#define   AMQ_BINDING_MGT_PHASE 1
#include  "amq_binding_mgt.hpp"
#undef    AMQ_BINDING_MGT_PHASE
#endif
#ifndef   AMQ_BROKER_PHASE_1_INCLUDED
#define   AMQ_BROKER_PHASE 1
#include  "amq_broker.hpp"
#undef    AMQ_BROKER_PHASE
#endif
#ifndef   AMQ_CLIENT_METHOD_PHASE_1_INCLUDED
#define   AMQ_CLIENT_METHOD_PHASE 1
#include  "amq_client_method.hpp"
#undef    AMQ_CLIENT_METHOD_PHASE
#endif
#ifndef   AMQ_CML_PHASE_1_INCLUDED
#define   AMQ_CML_PHASE 1
#include  "amq_cml.hpp"
#undef    AMQ_CML_PHASE
#endif
#ifndef   AMQ_CONSOLE_PHASE_1_INCLUDED
#define   AMQ_CONSOLE_PHASE 1
#include  "amq_console.hpp"
#undef    AMQ_CONSOLE_PHASE
#endif
#ifndef   AMQ_CONSOLE_CLASS_PHASE_1_INCLUDED
#define   AMQ_CONSOLE_CLASS_PHASE 1
#include  "amq_console_class.hpp"
#undef    AMQ_CONSOLE_CLASS_PHASE
#endif
#ifndef   AMQ_CONSOLE_CONFIG_PHASE_1_INCLUDED
#define   AMQ_CONSOLE_CONFIG_PHASE 1
#include  "amq_console_config.hpp"
#undef    AMQ_CONSOLE_CONFIG_PHASE
#endif
#ifndef   AMQ_CONSUMER_PHASE_1_INCLUDED
#define   AMQ_CONSUMER_PHASE 1
#include  "amq_consumer.hpp"
#undef    AMQ_CONSUMER_PHASE
#endif
#ifndef   AMQ_CONSUMER_BASIC_PHASE_1_INCLUDED
#define   AMQ_CONSUMER_BASIC_PHASE 1
#include  "amq_consumer_basic.hpp"
#undef    AMQ_CONSUMER_BASIC_PHASE
#endif
#ifndef   AMQ_CONNECTION_PHASE_1_INCLUDED
#define   AMQ_CONNECTION_PHASE 1
#include  "amq_connection.hpp"
#undef    AMQ_CONNECTION_PHASE
#endif
#ifndef   AMQ_CONNECTION_QUEUE_PHASE_1_INCLUDED
#define   AMQ_CONNECTION_QUEUE_PHASE 1
#include  "amq_connection_queue.hpp"
#undef    AMQ_CONNECTION_QUEUE_PHASE
#endif
#ifndef   AMQ_CONTENT_BASIC_PHASE_1_INCLUDED
#define   AMQ_CONTENT_BASIC_PHASE 1
#include  "amq_content_basic.hpp"
#undef    AMQ_CONTENT_BASIC_PHASE
#endif
#ifndef   AMQ_EXCHANGE_PHASE_1_INCLUDED
#define   AMQ_EXCHANGE_PHASE 1
#include  "amq_exchange.hpp"
#undef    AMQ_EXCHANGE_PHASE
#endif
#ifndef   AMQ_EXCHANGE_DIRECT_PHASE_1_INCLUDED
#define   AMQ_EXCHANGE_DIRECT_PHASE 1
#include  "amq_exchange_direct.hpp"
#undef    AMQ_EXCHANGE_DIRECT_PHASE
#endif
#ifndef   AMQ_EXCHANGE_TOPIC_PHASE_1_INCLUDED
#define   AMQ_EXCHANGE_TOPIC_PHASE 1
#include  "amq_exchange_topic.hpp"
#undef    AMQ_EXCHANGE_TOPIC_PHASE
#endif
#ifndef   AMQ_EXCHANGE_HEADERS_PHASE_1_INCLUDED
#define   AMQ_EXCHANGE_HEADERS_PHASE 1
#include  "amq_exchange_headers.hpp"
#undef    AMQ_EXCHANGE_HEADERS_PHASE
#endif
#ifndef   AMQ_EXCHANGE_FANOUT_PHASE_1_INCLUDED
#define   AMQ_EXCHANGE_FANOUT_PHASE 1
#include  "amq_exchange_fanout.hpp"
#undef    AMQ_EXCHANGE_FANOUT_PHASE
#endif
#ifndef   AMQ_EXCHANGE_SYSTEM_PHASE_1_INCLUDED
#define   AMQ_EXCHANGE_SYSTEM_PHASE 1
#include  "amq_exchange_system.hpp"
#undef    AMQ_EXCHANGE_SYSTEM_PHASE
#endif
#ifndef   AMQ_FAILOVER_PHASE_1_INCLUDED
#define   AMQ_FAILOVER_PHASE 1
#include  "amq_failover.hpp"
#undef    AMQ_FAILOVER_PHASE
#endif
#ifndef   AMQ_FEDERATION_PHASE_1_INCLUDED
#define   AMQ_FEDERATION_PHASE 1
#include  "amq_federation.hpp"
#undef    AMQ_FEDERATION_PHASE
#endif
#ifndef   AMQ_HITSET_PHASE_1_INCLUDED
#define   AMQ_HITSET_PHASE 1
#include  "amq_hitset.hpp"
#undef    AMQ_HITSET_PHASE
#endif
#ifndef   AMQ_INDEX_PHASE_1_INCLUDED
#define   AMQ_INDEX_PHASE 1
#include  "amq_index.hpp"
#undef    AMQ_INDEX_PHASE
#endif
#ifndef   AMQ_LEASE_PHASE_1_INCLUDED
#define   AMQ_LEASE_PHASE 1
#include  "amq_lease.hpp"
#undef    AMQ_LEASE_PHASE
#endif
#ifndef   AMQ_QUEUE_PHASE_1_INCLUDED
#define   AMQ_QUEUE_PHASE 1
#include  "amq_queue.hpp"
#undef    AMQ_QUEUE_PHASE
#endif
#ifndef   AMQ_QUEUE_BASIC_PHASE_1_INCLUDED
#define   AMQ_QUEUE_BASIC_PHASE 1
#include  "amq_queue_basic.hpp"
#undef    AMQ_QUEUE_BASIC_PHASE
#endif
#ifndef   AMQ_QUEUE_LIST_PHASE_1_INCLUDED
#define   AMQ_QUEUE_LIST_PHASE 1
#include  "amq_queue_list.hpp"
#undef    AMQ_QUEUE_LIST_PHASE
#endif
#ifndef   AMQ_QUEUE_CONNECTION_PHASE_1_INCLUDED
#define   AMQ_QUEUE_CONNECTION_PHASE 1
#include  "amq_queue_connection.hpp"
#undef    AMQ_QUEUE_CONNECTION_PHASE
#endif
#ifndef   AMQ_PEER_AGENT_PHASE_1_INCLUDED
#define   AMQ_PEER_AGENT_PHASE 1
#include  "amq_peer_agent.hpp"
#undef    AMQ_PEER_AGENT_PHASE
#endif
#ifndef   AMQ_PEER_CONFIG_PHASE_1_INCLUDED
#define   AMQ_PEER_CONFIG_PHASE 1
#include  "amq_peer_config.hpp"
#undef    AMQ_PEER_CONFIG_PHASE
#endif
#ifndef   AMQ_PEERING_PHASE_1_INCLUDED
#define   AMQ_PEERING_PHASE 1
#include  "amq_peering.hpp"
#undef    AMQ_PEERING_PHASE
#endif
#ifndef   AMQ_SERVER_CHANNEL_PHASE_1_INCLUDED
#define   AMQ_SERVER_CHANNEL_PHASE 1
#include  "amq_server_channel.hpp"
#undef    AMQ_SERVER_CHANNEL_PHASE
#endif
#ifndef   AMQ_SERVER_CONFIG_PHASE_1_INCLUDED
#define   AMQ_SERVER_CONFIG_PHASE 1
#include  "amq_server_config.hpp"
#undef    AMQ_SERVER_CONFIG_PHASE
#endif
#ifndef   AMQ_SERVER_CONNECTION_PHASE_1_INCLUDED
#define   AMQ_SERVER_CONNECTION_PHASE 1
#include  "amq_server_connection.hpp"
#undef    AMQ_SERVER_CONNECTION_PHASE
#endif
#ifndef   AMQ_SERVER_RESOURCE_PHASE_1_INCLUDED
#define   AMQ_SERVER_RESOURCE_PHASE 1
#include  "amq_server_resource.hpp"
#undef    AMQ_SERVER_RESOURCE_PHASE
#endif
#ifndef   AMQ_VHOST_PHASE_1_INCLUDED
#define   AMQ_VHOST_PHASE 1
#include  "amq_vhost.hpp"
#undef    AMQ_VHOST_PHASE
#endif
#ifndef   AMQ_VHOST_CONFIG_PHASE_1_INCLUDED
#define   AMQ_VHOST_CONFIG_PHASE 1
#include  "amq_vhost_config.hpp"
#undef    AMQ_VHOST_CONFIG_PHASE
#endif

#endif
#endif

#if !defined(AMQ_SERVER_CLASSES_PHASE) || AMQ_SERVER_CLASSES_PHASE==2
#ifndef AMQ_SERVER_CLASSES_PHASE_2_INCLUDED
#define AMQ_SERVER_CLASSES_PHASE_2_INCLUDED


#ifndef   AMQ_BINDING_PHASE_2_INCLUDED
#define   AMQ_BINDING_PHASE 2
#include  "amq_binding.hpp"
#undef    AMQ_BINDING_PHASE
#endif
#ifndef   AMQ_BINDING_MGT_PHASE_2_INCLUDED
#define   AMQ_BINDING_MGT_PHASE 2
#include  "amq_binding_mgt.hpp"
#undef    AMQ_BINDING_MGT_PHASE
#endif
#ifndef   AMQ_BROKER_PHASE_2_INCLUDED
#define   AMQ_BROKER_PHASE 2
#include  "amq_broker.hpp"
#undef    AMQ_BROKER_PHASE
#endif
#ifndef   AMQ_CLIENT_METHOD_PHASE_2_INCLUDED
#define   AMQ_CLIENT_METHOD_PHASE 2
#include  "amq_client_method.hpp"
#undef    AMQ_CLIENT_METHOD_PHASE
#endif
#ifndef   AMQ_CML_PHASE_2_INCLUDED
#define   AMQ_CML_PHASE 2
#include  "amq_cml.hpp"
#undef    AMQ_CML_PHASE
#endif
#ifndef   AMQ_CONSOLE_PHASE_2_INCLUDED
#define   AMQ_CONSOLE_PHASE 2
#include  "amq_console.hpp"
#undef    AMQ_CONSOLE_PHASE
#endif
#ifndef   AMQ_CONSOLE_CLASS_PHASE_2_INCLUDED
#define   AMQ_CONSOLE_CLASS_PHASE 2
#include  "amq_console_class.hpp"
#undef    AMQ_CONSOLE_CLASS_PHASE
#endif
#ifndef   AMQ_CONSOLE_CONFIG_PHASE_2_INCLUDED
#define   AMQ_CONSOLE_CONFIG_PHASE 2
#include  "amq_console_config.hpp"
#undef    AMQ_CONSOLE_CONFIG_PHASE
#endif
#ifndef   AMQ_CONSUMER_PHASE_2_INCLUDED
#define   AMQ_CONSUMER_PHASE 2
#include  "amq_consumer.hpp"
#undef    AMQ_CONSUMER_PHASE
#endif
#ifndef   AMQ_CONSUMER_BASIC_PHASE_2_INCLUDED
#define   AMQ_CONSUMER_BASIC_PHASE 2
#include  "amq_consumer_basic.hpp"
#undef    AMQ_CONSUMER_BASIC_PHASE
#endif
#ifndef   AMQ_CONNECTION_PHASE_2_INCLUDED
#define   AMQ_CONNECTION_PHASE 2
#include  "amq_connection.hpp"
#undef    AMQ_CONNECTION_PHASE
#endif
#ifndef   AMQ_CONNECTION_QUEUE_PHASE_2_INCLUDED
#define   AMQ_CONNECTION_QUEUE_PHASE 2
#include  "amq_connection_queue.hpp"
#undef    AMQ_CONNECTION_QUEUE_PHASE
#endif
#ifndef   AMQ_CONTENT_BASIC_PHASE_2_INCLUDED
#define   AMQ_CONTENT_BASIC_PHASE 2
#include  "amq_content_basic.hpp"
#undef    AMQ_CONTENT_BASIC_PHASE
#endif
#ifndef   AMQ_EXCHANGE_PHASE_2_INCLUDED
#define   AMQ_EXCHANGE_PHASE 2
#include  "amq_exchange.hpp"
#undef    AMQ_EXCHANGE_PHASE
#endif
#ifndef   AMQ_EXCHANGE_DIRECT_PHASE_2_INCLUDED
#define   AMQ_EXCHANGE_DIRECT_PHASE 2
#include  "amq_exchange_direct.hpp"
#undef    AMQ_EXCHANGE_DIRECT_PHASE
#endif
#ifndef   AMQ_EXCHANGE_TOPIC_PHASE_2_INCLUDED
#define   AMQ_EXCHANGE_TOPIC_PHASE 2
#include  "amq_exchange_topic.hpp"
#undef    AMQ_EXCHANGE_TOPIC_PHASE
#endif
#ifndef   AMQ_EXCHANGE_HEADERS_PHASE_2_INCLUDED
#define   AMQ_EXCHANGE_HEADERS_PHASE 2
#include  "amq_exchange_headers.hpp"
#undef    AMQ_EXCHANGE_HEADERS_PHASE
#endif
#ifndef   AMQ_EXCHANGE_FANOUT_PHASE_2_INCLUDED
#define   AMQ_EXCHANGE_FANOUT_PHASE 2
#include  "amq_exchange_fanout.hpp"
#undef    AMQ_EXCHANGE_FANOUT_PHASE
#endif
#ifndef   AMQ_EXCHANGE_SYSTEM_PHASE_2_INCLUDED
#define   AMQ_EXCHANGE_SYSTEM_PHASE 2
#include  "amq_exchange_system.hpp"
#undef    AMQ_EXCHANGE_SYSTEM_PHASE
#endif
#ifndef   AMQ_FAILOVER_PHASE_2_INCLUDED
#define   AMQ_FAILOVER_PHASE 2
#include  "amq_failover.hpp"
#undef    AMQ_FAILOVER_PHASE
#endif
#ifndef   AMQ_FEDERATION_PHASE_2_INCLUDED
#define   AMQ_FEDERATION_PHASE 2
#include  "amq_federation.hpp"
#undef    AMQ_FEDERATION_PHASE
#endif
#ifndef   AMQ_HITSET_PHASE_2_INCLUDED
#define   AMQ_HITSET_PHASE 2
#include  "amq_hitset.hpp"
#undef    AMQ_HITSET_PHASE
#endif
#ifndef   AMQ_INDEX_PHASE_2_INCLUDED
#define   AMQ_INDEX_PHASE 2
#include  "amq_index.hpp"
#undef    AMQ_INDEX_PHASE
#endif
#ifndef   AMQ_LEASE_PHASE_2_INCLUDED
#define   AMQ_LEASE_PHASE 2
#include  "amq_lease.hpp"
#undef    AMQ_LEASE_PHASE
#endif
#ifndef   AMQ_QUEUE_PHASE_2_INCLUDED
#define   AMQ_QUEUE_PHASE 2
#include  "amq_queue.hpp"
#undef    AMQ_QUEUE_PHASE
#endif
#ifndef   AMQ_QUEUE_BASIC_PHASE_2_INCLUDED
#define   AMQ_QUEUE_BASIC_PHASE 2
#include  "amq_queue_basic.hpp"
#undef    AMQ_QUEUE_BASIC_PHASE
#endif
#ifndef   AMQ_QUEUE_LIST_PHASE_2_INCLUDED
#define   AMQ_QUEUE_LIST_PHASE 2
#include  "amq_queue_list.hpp"
#undef    AMQ_QUEUE_LIST_PHASE
#endif
#ifndef   AMQ_QUEUE_CONNECTION_PHASE_2_INCLUDED
#define   AMQ_QUEUE_CONNECTION_PHASE 2
#include  "amq_queue_connection.hpp"
#undef    AMQ_QUEUE_CONNECTION_PHASE
#endif
#ifndef   AMQ_PEER_AGENT_PHASE_2_INCLUDED
#define   AMQ_PEER_AGENT_PHASE 2
#include  "amq_peer_agent.hpp"
#undef    AMQ_PEER_AGENT_PHASE
#endif
#ifndef   AMQ_PEER_CONFIG_PHASE_2_INCLUDED
#define   AMQ_PEER_CONFIG_PHASE 2
#include  "amq_peer_config.hpp"
#undef    AMQ_PEER_CONFIG_PHASE
#endif
#ifndef   AMQ_PEERING_PHASE_2_INCLUDED
#define   AMQ_PEERING_PHASE 2
#include  "amq_peering.hpp"
#undef    AMQ_PEERING_PHASE
#endif
#ifndef   AMQ_SERVER_CHANNEL_PHASE_2_INCLUDED
#define   AMQ_SERVER_CHANNEL_PHASE 2
#include  "amq_server_channel.hpp"
#undef    AMQ_SERVER_CHANNEL_PHASE
#endif
#ifndef   AMQ_SERVER_CONFIG_PHASE_2_INCLUDED
#define   AMQ_SERVER_CONFIG_PHASE 2
#include  "amq_server_config.hpp"
#undef    AMQ_SERVER_CONFIG_PHASE
#endif
#ifndef   AMQ_SERVER_CONNECTION_PHASE_2_INCLUDED
#define   AMQ_SERVER_CONNECTION_PHASE 2
#include  "amq_server_connection.hpp"
#undef    AMQ_SERVER_CONNECTION_PHASE
#endif
#ifndef   AMQ_SERVER_RESOURCE_PHASE_2_INCLUDED
#define   AMQ_SERVER_RESOURCE_PHASE 2
#include  "amq_server_resource.hpp"
#undef    AMQ_SERVER_RESOURCE_PHASE
#endif
#ifndef   AMQ_VHOST_PHASE_2_INCLUDED
#define   AMQ_VHOST_PHASE 2
#include  "amq_vhost.hpp"
#undef    AMQ_VHOST_PHASE
#endif
#ifndef   AMQ_VHOST_CONFIG_PHASE_2_INCLUDED
#define   AMQ_VHOST_CONFIG_PHASE 2
#include  "amq_vhost_config.hpp"
#undef    AMQ_VHOST_CONFIG_PHASE
#endif

#endif
#endif

#if !defined(AMQ_SERVER_CLASSES_PHASE) || AMQ_SERVER_CLASSES_PHASE==3
#ifndef AMQ_SERVER_CLASSES_PHASE_3_INCLUDED
#define AMQ_SERVER_CLASSES_PHASE_3_INCLUDED

#ifndef   AMQ_BINDING_PHASE_3_INCLUDED
#define   AMQ_BINDING_PHASE 3
#include  "amq_binding.hpp"
#undef    AMQ_BINDING_PHASE
#endif
#ifndef   AMQ_BINDING_MGT_PHASE_3_INCLUDED
#define   AMQ_BINDING_MGT_PHASE 3
#include  "amq_binding_mgt.hpp"
#undef    AMQ_BINDING_MGT_PHASE
#endif
#ifndef   AMQ_BROKER_PHASE_3_INCLUDED
#define   AMQ_BROKER_PHASE 3
#include  "amq_broker.hpp"
#undef    AMQ_BROKER_PHASE
#endif
#ifndef   AMQ_CLIENT_METHOD_PHASE_3_INCLUDED
#define   AMQ_CLIENT_METHOD_PHASE 3
#include  "amq_client_method.hpp"
#undef    AMQ_CLIENT_METHOD_PHASE
#endif
#ifndef   AMQ_CML_PHASE_3_INCLUDED
#define   AMQ_CML_PHASE 3
#include  "amq_cml.hpp"
#undef    AMQ_CML_PHASE
#endif
#ifndef   AMQ_CONSOLE_PHASE_3_INCLUDED
#define   AMQ_CONSOLE_PHASE 3
#include  "amq_console.hpp"
#undef    AMQ_CONSOLE_PHASE
#endif
#ifndef   AMQ_CONSOLE_CLASS_PHASE_3_INCLUDED
#define   AMQ_CONSOLE_CLASS_PHASE 3
#include  "amq_console_class.hpp"
#undef    AMQ_CONSOLE_CLASS_PHASE
#endif
#ifndef   AMQ_CONSOLE_CONFIG_PHASE_3_INCLUDED
#define   AMQ_CONSOLE_CONFIG_PHASE 3
#include  "amq_console_config.hpp"
#undef    AMQ_CONSOLE_CONFIG_PHASE
#endif
#ifndef   AMQ_CONSUMER_PHASE_3_INCLUDED
#define   AMQ_CONSUMER_PHASE 3
#include  "amq_consumer.hpp"
#undef    AMQ_CONSUMER_PHASE
#endif
#ifndef   AMQ_CONSUMER_BASIC_PHASE_3_INCLUDED
#define   AMQ_CONSUMER_BASIC_PHASE 3
#include  "amq_consumer_basic.hpp"
#undef    AMQ_CONSUMER_BASIC_PHASE
#endif
#ifndef   AMQ_CONNECTION_PHASE_3_INCLUDED
#define   AMQ_CONNECTION_PHASE 3
#include  "amq_connection.hpp"
#undef    AMQ_CONNECTION_PHASE
#endif
#ifndef   AMQ_CONNECTION_QUEUE_PHASE_3_INCLUDED
#define   AMQ_CONNECTION_QUEUE_PHASE 3
#include  "amq_connection_queue.hpp"
#undef    AMQ_CONNECTION_QUEUE_PHASE
#endif
#ifndef   AMQ_CONTENT_BASIC_PHASE_3_INCLUDED
#define   AMQ_CONTENT_BASIC_PHASE 3
#include  "amq_content_basic.hpp"
#undef    AMQ_CONTENT_BASIC_PHASE
#endif
#ifndef   AMQ_EXCHANGE_PHASE_3_INCLUDED
#define   AMQ_EXCHANGE_PHASE 3
#include  "amq_exchange.hpp"
#undef    AMQ_EXCHANGE_PHASE
#endif
#ifndef   AMQ_EXCHANGE_DIRECT_PHASE_3_INCLUDED
#define   AMQ_EXCHANGE_DIRECT_PHASE 3
#include  "amq_exchange_direct.hpp"
#undef    AMQ_EXCHANGE_DIRECT_PHASE
#endif
#ifndef   AMQ_EXCHANGE_TOPIC_PHASE_3_INCLUDED
#define   AMQ_EXCHANGE_TOPIC_PHASE 3
#include  "amq_exchange_topic.hpp"
#undef    AMQ_EXCHANGE_TOPIC_PHASE
#endif
#ifndef   AMQ_EXCHANGE_HEADERS_PHASE_3_INCLUDED
#define   AMQ_EXCHANGE_HEADERS_PHASE 3
#include  "amq_exchange_headers.hpp"
#undef    AMQ_EXCHANGE_HEADERS_PHASE
#endif
#ifndef   AMQ_EXCHANGE_FANOUT_PHASE_3_INCLUDED
#define   AMQ_EXCHANGE_FANOUT_PHASE 3
#include  "amq_exchange_fanout.hpp"
#undef    AMQ_EXCHANGE_FANOUT_PHASE
#endif
#ifndef   AMQ_EXCHANGE_SYSTEM_PHASE_3_INCLUDED
#define   AMQ_EXCHANGE_SYSTEM_PHASE 3
#include  "amq_exchange_system.hpp"
#undef    AMQ_EXCHANGE_SYSTEM_PHASE
#endif
#ifndef   AMQ_FAILOVER_PHASE_3_INCLUDED
#define   AMQ_FAILOVER_PHASE 3
#include  "amq_failover.hpp"
#undef    AMQ_FAILOVER_PHASE
#endif
#ifndef   AMQ_FEDERATION_PHASE_3_INCLUDED
#define   AMQ_FEDERATION_PHASE 3
#include  "amq_federation.hpp"
#undef    AMQ_FEDERATION_PHASE
#endif
#ifndef   AMQ_HITSET_PHASE_3_INCLUDED
#define   AMQ_HITSET_PHASE 3
#include  "amq_hitset.hpp"
#undef    AMQ_HITSET_PHASE
#endif
#ifndef   AMQ_INDEX_PHASE_3_INCLUDED
#define   AMQ_INDEX_PHASE 3
#include  "amq_index.hpp"
#undef    AMQ_INDEX_PHASE
#endif
#ifndef   AMQ_LEASE_PHASE_3_INCLUDED
#define   AMQ_LEASE_PHASE 3
#include  "amq_lease.hpp"
#undef    AMQ_LEASE_PHASE
#endif
#ifndef   AMQ_QUEUE_PHASE_3_INCLUDED
#define   AMQ_QUEUE_PHASE 3
#include  "amq_queue.hpp"
#undef    AMQ_QUEUE_PHASE
#endif
#ifndef   AMQ_QUEUE_BASIC_PHASE_3_INCLUDED
#define   AMQ_QUEUE_BASIC_PHASE 3
#include  "amq_queue_basic.hpp"
#undef    AMQ_QUEUE_BASIC_PHASE
#endif
#ifndef   AMQ_QUEUE_LIST_PHASE_3_INCLUDED
#define   AMQ_QUEUE_LIST_PHASE 3
#include  "amq_queue_list.hpp"
#undef    AMQ_QUEUE_LIST_PHASE
#endif
#ifndef   AMQ_QUEUE_CONNECTION_PHASE_3_INCLUDED
#define   AMQ_QUEUE_CONNECTION_PHASE 3
#include  "amq_queue_connection.hpp"
#undef    AMQ_QUEUE_CONNECTION_PHASE
#endif
#ifndef   AMQ_PEER_AGENT_PHASE_3_INCLUDED
#define   AMQ_PEER_AGENT_PHASE 3
#include  "amq_peer_agent.hpp"
#undef    AMQ_PEER_AGENT_PHASE
#endif
#ifndef   AMQ_PEER_CONFIG_PHASE_3_INCLUDED
#define   AMQ_PEER_CONFIG_PHASE 3
#include  "amq_peer_config.hpp"
#undef    AMQ_PEER_CONFIG_PHASE
#endif
#ifndef   AMQ_PEERING_PHASE_3_INCLUDED
#define   AMQ_PEERING_PHASE 3
#include  "amq_peering.hpp"
#undef    AMQ_PEERING_PHASE
#endif
#ifndef   AMQ_SERVER_CHANNEL_PHASE_3_INCLUDED
#define   AMQ_SERVER_CHANNEL_PHASE 3
#include  "amq_server_channel.hpp"
#undef    AMQ_SERVER_CHANNEL_PHASE
#endif
#ifndef   AMQ_SERVER_CONFIG_PHASE_3_INCLUDED
#define   AMQ_SERVER_CONFIG_PHASE 3
#include  "amq_server_config.hpp"
#undef    AMQ_SERVER_CONFIG_PHASE
#endif
#ifndef   AMQ_SERVER_CONNECTION_PHASE_3_INCLUDED
#define   AMQ_SERVER_CONNECTION_PHASE 3
#include  "amq_server_connection.hpp"
#undef    AMQ_SERVER_CONNECTION_PHASE
#endif
#ifndef   AMQ_SERVER_RESOURCE_PHASE_3_INCLUDED
#define   AMQ_SERVER_RESOURCE_PHASE 3
#include  "amq_server_resource.hpp"
#undef    AMQ_SERVER_RESOURCE_PHASE
#endif
#ifndef   AMQ_VHOST_PHASE_3_INCLUDED
#define   AMQ_VHOST_PHASE 3
#include  "amq_vhost.hpp"
#undef    AMQ_VHOST_PHASE
#endif
#ifndef   AMQ_VHOST_CONFIG_PHASE_3_INCLUDED
#define   AMQ_VHOST_CONFIG_PHASE 3
#include  "amq_vhost_config.hpp"
#undef    AMQ_VHOST_CONFIG_PHASE
#endif



#endif
#endif
