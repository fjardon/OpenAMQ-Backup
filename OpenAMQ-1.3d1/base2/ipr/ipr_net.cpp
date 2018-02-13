/*---------------------------------------------------------------------------
    ipr_net.cpp - ipr_net component wrapper implementation in C++

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

#include "ipr_net.hpp"


void
IprNet::GetAddr (
        icl_info <char *>::cpp_type_ref dest)
{
    ipr_net_get_addr (dest);
}

void
IprNet::GetHostname (
        icl_info <char *>::cpp_type_ref dest)
{
    ipr_net_get_hostname (dest);
}

icl_info <Bool>::cpp_type
IprNet::ValidateAddr (
        icl_info <char *>::cpp_type_ref netaddr)
{
    return ipr_net_validate_addr (netaddr);
}

icl_info <Bool>::cpp_type
IprNet::Ping (
        icl_info <char *>::cpp_type_ref hostname,
        icl_info <char *>::cpp_type_ref defport)
{
    return ipr_net_ping (hostname, defport);
}

icl_info <ipr_token_t *>::cpp_type
IprNet::PingList (
        icl_info <ipr_token_list_t *>::cpp_type_ref servers,
        icl_info <char *>::cpp_type_ref defport,
        icl_info <Bool>::cpp_type_ref cleanup)
{
    return ipr_net_ping_list (servers, defport, cleanup);
}

icl_info <char *>::cpp_type
IprNet::LookupHost (
        icl_info <char *>::cpp_type_ref hostname,
        icl_info <char *>::cpp_type_ref address)
{
    return ipr_net_lookup_host (hostname, address);
}

icl_info <char *>::cpp_type
IprNet::FmtDisplay (
        icl_info <char *>::cpp_type_ref external,
        icl_info <char *>::cpp_type_ref internal,
        icl_info <Bool>::cpp_type_ref opt_xlat)
{
    return ipr_net_fmt_display (external, internal, opt_xlat);
}

void
IprNet::Selftest (
        void)
{
    ipr_net_selftest ();
}

void
IprNet::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    ipr_net_animate (enabled);
}
