/*---------------------------------------------------------------------------
    amq_federation.cpp - amq_federation component wrapper implementation in C++

This agent implements a single federation, which is a relationship between
an exchange on this server and the same-named exchange on a parent server.
There are two families of federation, primitives that do one thing and 
compounds which combine the effects of multiple primitives.

The primitives are:

 - Subscriber federation: replicate bindings to the parent server, so that 
   messages are pulled down from it.  The subscriber federation does three
   things: send queue.bind and and queue.unbind commands to the parent 
   server (via a peering), and process messages delivered from the parent.
   Typically used on topic or header exchanges.
   
 - Publisher federation (aka 'forward all'): replicate published messages to
   the parent server.  The publisher federation does two things: forward all
   basic.publish commands to the parent server, and process undeliverable
   messages returned by the parent server. Typically used for topic or header 
   exchanges.
   
 - Locator federation (aka 'forward else'): replicate published messages to
   the parent server if they could not be delivered locally.  The locator
   federation does two things: forward basic.publish messages to the parent
   server if they could not be delivered locally, and process undeliverable
   messages returned by the parent server.  Typically used for direct 
   exchanges.
   
The compound federations are:

 - Fanout federation: combines subscriber and publisher.  Fanout federation
   does this: send queue.bind and unbind to parent server; when a local app
   publishes message, forward that to parent (and do not publish to local
   exchange); process messages delivered from the parent; process returns
   from the parent.  The result is that messages published to any server will
   be pushed up to the highest parent, and then propagated back down through
   all servers and out to applications.  This is the default federation for 
   topic and header exchanges.  The current implementation creates extra
   latency. 
 
 - Service federation: combines subscriber and locator.  Service federation
   does this: send queue.bind and unbind to parent server; when local app
   publishes message, try to deliver locally and if that fails, forward to
   parent server; process messages delivered from parent; process returns
   from the parent.  The result is that requests will go to the nearest
   consumer, and responses will come back down from parents.  This is the
   default federation for direct exchanges.
    Generated from amq_federation.icl by smt_object_gen using GSL/4.
    
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

#include "amq_federation.hpp"

