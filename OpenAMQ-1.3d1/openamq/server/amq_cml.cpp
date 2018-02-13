/*---------------------------------------------------------------------------
    amq_cml.cpp - amq_cml component wrapper implementation in C++

    The CML module provides functions to read and write CML commands.
    Generated from amq_cml.icl by icl_gen using GSL/4.
    
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

#include "amq_cml.hpp"


icl_info <amq_content_basic_t *>::cpp_type
AmqCml::Encode (
        icl_info <char *>::cpp_type_ref name,
        icl_info <char *>::cpp_type_ref object_class,
        icl_info <qbyte>::cpp_type_ref object_id,
        icl_info <char *>::cpp_type_ref status,
        icl_info <char *>::cpp_type_ref method,
        icl_info <asl_field_list_t *>::cpp_type_ref fields)
{
    return amq_cml_encode (name, object_class, object_id, status, method, fields);
}

void
AmqCml::Selftest (
        void)
{
    amq_cml_selftest ();
}

void
AmqCml::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    amq_cml_animate (enabled);
}
