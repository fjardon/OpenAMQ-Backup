/*---------------------------------------------------------------------------
    demo_srv_resource.hpp - demo_srv_resource component wrapper in C++

    Provides compiled resources, i.e. external files that are shipped with
    the application.
    Generated from demo_srv_resource.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/

#if !defined(DEMO_SRV_RESOURCE_PHASE) || DEMO_SRV_RESOURCE_PHASE==1
#ifndef DEMO_SRV_RESOURCE_PHASE_1_INCLUDED
#define DEMO_SRV_RESOURCE_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "demo_srv_resource.h"
#include "icl_info.hpp"


#ifndef   IPR_BUCKET_PHASE_1_INCLUDED
#define   IPR_BUCKET_PHASE 1
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif

#endif
#endif

#if !defined(DEMO_SRV_RESOURCE_PHASE) || DEMO_SRV_RESOURCE_PHASE==2
#ifndef DEMO_SRV_RESOURCE_PHASE_2_INCLUDED
#define DEMO_SRV_RESOURCE_PHASE_2_INCLUDED


#ifndef   IPR_BUCKET_PHASE_2_INCLUDED
#define   IPR_BUCKET_PHASE 2
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif

#endif
#endif

#if !defined(DEMO_SRV_RESOURCE_PHASE) || DEMO_SRV_RESOURCE_PHASE==3
#ifndef DEMO_SRV_RESOURCE_PHASE_3_INCLUDED
#define DEMO_SRV_RESOURCE_PHASE_3_INCLUDED

#ifndef   IPR_BUCKET_PHASE_3_INCLUDED
#define   IPR_BUCKET_PHASE 3
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif


class DemoSrvResource
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
    DemoSrvResource ();
    DemoSrvResource (const DemoSrvResource&);
    DemoSrvResource &operator = (const DemoSrvResource&);
};



#endif
#endif
