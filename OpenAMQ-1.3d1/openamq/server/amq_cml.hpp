/*---------------------------------------------------------------------------
    amq_cml.hpp - amq_cml component wrapper in C++

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

#if !defined(AMQ_CML_PHASE) || AMQ_CML_PHASE==1
#ifndef AMQ_CML_PHASE_1_INCLUDED
#define AMQ_CML_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "amq_cml.h"
#include "icl_info.hpp"


#ifndef   AMQ_SERVER_CLASSES_PHASE_1_INCLUDED
#define   AMQ_SERVER_CLASSES_PHASE 1
#include  "amq_server_classes.hpp"
#undef    AMQ_SERVER_CLASSES_PHASE
#endif

#endif
#endif

#if !defined(AMQ_CML_PHASE) || AMQ_CML_PHASE==2
#ifndef AMQ_CML_PHASE_2_INCLUDED
#define AMQ_CML_PHASE_2_INCLUDED


#ifndef   AMQ_SERVER_CLASSES_PHASE_2_INCLUDED
#define   AMQ_SERVER_CLASSES_PHASE 2
#include  "amq_server_classes.hpp"
#undef    AMQ_SERVER_CLASSES_PHASE
#endif

#endif
#endif

#if !defined(AMQ_CML_PHASE) || AMQ_CML_PHASE==3
#ifndef AMQ_CML_PHASE_3_INCLUDED
#define AMQ_CML_PHASE_3_INCLUDED

#ifndef   AMQ_SERVER_CLASSES_PHASE_3_INCLUDED
#define   AMQ_SERVER_CLASSES_PHASE 3
#include  "amq_server_classes.hpp"
#undef    AMQ_SERVER_CLASSES_PHASE
#endif


class AmqCml
{
public:

    static icl_info <amq_content_basic_t *>::cpp_type
    Encode (
        icl_info <char *>::cpp_type_ref name,
        icl_info <char *>::cpp_type_ref object_class,
        icl_info <qbyte>::cpp_type_ref object_id,
        icl_info <char *>::cpp_type_ref status,
        icl_info <char *>::cpp_type_ref method,
        icl_info <asl_field_list_t *>::cpp_type_ref fields);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    AmqCml ();
    AmqCml (const AmqCml&);
    AmqCml &operator = (const AmqCml&);
};



#endif
#endif
