/*---------------------------------------------------------------------------
    ipr_net.hpp - ipr_net component wrapper in C++

    The network module provides various higher-level network access
    functions built on the APR socket layer.
    Generated from ipr_net.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_NET_PHASE) || IPR_NET_PHASE==1
#ifndef IPR_NET_PHASE_1_INCLUDED
#define IPR_NET_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_net.h"
#include "icl_info.hpp"


#ifndef   IPR_TOKEN_PHASE_1_INCLUDED
#define   IPR_TOKEN_PHASE 1
#include  "ipr_token.hpp"
#undef    IPR_TOKEN_PHASE
#endif

#endif
#endif

#if !defined(IPR_NET_PHASE) || IPR_NET_PHASE==2
#ifndef IPR_NET_PHASE_2_INCLUDED
#define IPR_NET_PHASE_2_INCLUDED


#ifndef   IPR_TOKEN_PHASE_2_INCLUDED
#define   IPR_TOKEN_PHASE 2
#include  "ipr_token.hpp"
#undef    IPR_TOKEN_PHASE
#endif

#endif
#endif

#if !defined(IPR_NET_PHASE) || IPR_NET_PHASE==3
#ifndef IPR_NET_PHASE_3_INCLUDED
#define IPR_NET_PHASE_3_INCLUDED

#ifndef   IPR_TOKEN_PHASE_3_INCLUDED
#define   IPR_TOKEN_PHASE 3
#include  "ipr_token.hpp"
#undef    IPR_TOKEN_PHASE
#endif


class IprNet
{
public:

    static void
    GetAddr (
        icl_info <char *>::cpp_type_ref dest);

    static void
    GetHostname (
        icl_info <char *>::cpp_type_ref dest);

    static icl_info <Bool>::cpp_type
    ValidateAddr (
        icl_info <char *>::cpp_type_ref netaddr);

    static icl_info <Bool>::cpp_type
    Ping (
        icl_info <char *>::cpp_type_ref hostname,
        icl_info <char *>::cpp_type_ref defport);

    static icl_info <ipr_token_t *>::cpp_type
    PingList (
        icl_info <ipr_token_list_t *>::cpp_type_ref servers,
        icl_info <char *>::cpp_type_ref defport,
        icl_info <Bool>::cpp_type_ref cleanup);

    static icl_info <char *>::cpp_type
    LookupHost (
        icl_info <char *>::cpp_type_ref hostname,
        icl_info <char *>::cpp_type_ref address);

    static icl_info <char *>::cpp_type
    FmtDisplay (
        icl_info <char *>::cpp_type_ref external,
        icl_info <char *>::cpp_type_ref internal,
        icl_info <Bool>::cpp_type_ref opt_xlat);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprNet ();
    IprNet (const IprNet&);
    IprNet &operator = (const IprNet&);
};



#endif
#endif
