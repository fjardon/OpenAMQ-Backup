/*---------------------------------------------------------------------------
    amq_server_resource.hpp - amq_server_resource component wrapper in C++

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

#if !defined(AMQ_SERVER_RESOURCE_PHASE) || AMQ_SERVER_RESOURCE_PHASE==1
#ifndef AMQ_SERVER_RESOURCE_PHASE_1_INCLUDED
#define AMQ_SERVER_RESOURCE_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "amq_server_resource.h"
#include "icl_info.hpp"


#ifndef   IPR_BUCKET_PHASE_1_INCLUDED
#define   IPR_BUCKET_PHASE 1
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif

#endif
#endif

#if !defined(AMQ_SERVER_RESOURCE_PHASE) || AMQ_SERVER_RESOURCE_PHASE==2
#ifndef AMQ_SERVER_RESOURCE_PHASE_2_INCLUDED
#define AMQ_SERVER_RESOURCE_PHASE_2_INCLUDED


#ifndef   IPR_BUCKET_PHASE_2_INCLUDED
#define   IPR_BUCKET_PHASE 2
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif

#endif
#endif

#if !defined(AMQ_SERVER_RESOURCE_PHASE) || AMQ_SERVER_RESOURCE_PHASE==3
#ifndef AMQ_SERVER_RESOURCE_PHASE_3_INCLUDED
#define AMQ_SERVER_RESOURCE_PHASE_3_INCLUDED

#ifndef   IPR_BUCKET_PHASE_3_INCLUDED
#define   IPR_BUCKET_PHASE 3
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif


class AmqServerResource
{
public:

    static icl_info <ipr_bucket_t *>::cpp_type
    Get (
        icl_info <char *>::cpp_type_ref filename);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    AmqServerResource ();
    AmqServerResource (const AmqServerResource&);
    AmqServerResource &operator = (const AmqServerResource&);
};



#endif
#endif
