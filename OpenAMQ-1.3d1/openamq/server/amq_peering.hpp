/*---------------------------------------------------------------------------
    amq_peering.hpp - amq_peering component wrapper in C++

This class defines a smart link to a remote server.  You tell the peering
what server to talk to and it will monitor the server and connect
automatically when the server comes online, and reconnect if the server
goes offline for a period.

A peering has two functions:

1. Binding propagation, in which messages published to an exchange on the
   remote server can be "pulled" to this server.  You tell the peering what
   bindings you are interested in, and it will deliver you all matching
   messages.

2. Message forwarding, in which messages originating locally are carried to
   the remote peer.  This class does not specify where those local messages
   come from.

The peer link may be arbitrarily active or inactive depending on the state
of the network and the remote server.

The peering will replay all bindings if when the peer link becomes active.
It will queue messages that are forwarded when the peer link is not active.

Lastly, the peering will invoke callback methods to tell you when the peer
link becomes active, and when a content arrives.  Currently this class
works only with Basic contents.

The selftest method demonstrates fairly sophisticated peering use.  To test
this, set the environment variable AMQ_PEERING_TEST=1 and run an amq_server.

Note that the current amq_peering implementation is limited to a signle
exchange per amq_peering instance.

This is a summary of the amq_peering API:

    peering = amq_peering_new (
        remote-host-name, virtual-host, trace-level, exchange-name)
        Create a new peering to the specified host, virtual host and
        remote exchange.

    amq_peering_set_login (peering, login-name)
        Tell the peering to login using the specified login-name, which
        must be defined in the local amq_server_base.cfg or amq_server.cfg.

    amq_peering_set_status_handler (peering, handler, calling-object)
        Set the callback handler for status updates.

    amq_peering_set_content_handler (peering, handler, calling-object)
        Set the callback handler for incoming messages.

    amq_peering_start (peering)
        Enable the peering, connect to remote server when possible.

    amq_peering_stop (peering)
        Disable the peering, disconnect from remote server if necessary.

    amq_peering_bind (peering, routing-key, arguments)
        Replicate a binding to the remote server.

    amq_peering_unbind (peering, routing-key, arguments)
        Replicate a queue.unbind to the remote server.  Also removes the
        binding from the list of bindings to replay.

    amq_peering_forward (peering, routing-key, content, madatory, immediate)
        Publish a message to the remote server.

    amq_peering_destroy (&peering)
        Destroy the peering.
    Generated from amq_peering.icl by smt_object_gen using GSL/4.
    
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

