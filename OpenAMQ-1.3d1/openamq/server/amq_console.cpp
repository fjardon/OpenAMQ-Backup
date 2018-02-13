/*---------------------------------------------------------------------------
    amq_console.cpp - amq_console component wrapper implementation in C++

This implements the AMQ Console object, which is a system-wide object
responsible for implementing the AMQ Console service.

The console works as follows:

 - AMQ Console is instantiated as a global object of this class, which
   has its own context.

 - All operable objects register with the console class, using a console
   class object as a holder for the methods the object class implements.

 - The amq.system exchange sends it messages using the publish method.
   For now, it is hard-coded in amq.system that any messages with the
   "amq.console" will get sent to amq_console.

 - The amq_console decodes the messages and routes it to an object (if
   found), via the amq_console_class definition for that object.

 - The operable objects implement a register, cancel, inspect, and modify
   methods, and return their replies to amq_console asynchrously via
   inspect_ok, modify_ok.

 - All interfaces between amq_console and operable classes is done using
   asl_field lists.
    Generated from amq_console.icl by smt_object_gen using GSL/4.
    
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

#include "amq_console.hpp"

