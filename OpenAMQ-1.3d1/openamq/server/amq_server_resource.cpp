/*---------------------------------------------------------------------------
    amq_server_resource.cpp - amq_server_resource component wrapper implementation in C++

    Provides compiled resources, i.e. external files that are shipped with
    the application.
    Generated from amq_server_resource.icl by icl_gen using GSL/4.
    
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

#include "amq_server_resource.hpp"


icl_info <ipr_bucket_t *>::cpp_type
AmqServerResource::Get (
        icl_info <char *>::cpp_type_ref filename)
{
    return amq_server_resource_get (filename);
}

void
AmqServerResource::Selftest (
        void)
{
    amq_server_resource_selftest ();
}

void
AmqServerResource::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    amq_server_resource_animate (enabled);
}
