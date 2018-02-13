/*---------------------------------------------------------------------------
    ipr_sasl.hpp - ipr_sasl component wrapper in C++

    Provides functions for working with SASL (simple authentication and
    security layer).
    Generated from ipr_sasl.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_SASL_PHASE) || IPR_SASL_PHASE==1
#ifndef IPR_SASL_PHASE_1_INCLUDED
#define IPR_SASL_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_sasl.h"
#include "icl_info.hpp"



#endif
#endif

#if !defined(IPR_SASL_PHASE) || IPR_SASL_PHASE==2
#ifndef IPR_SASL_PHASE_2_INCLUDED
#define IPR_SASL_PHASE_2_INCLUDED



#endif
#endif

#if !defined(IPR_SASL_PHASE) || IPR_SASL_PHASE==3
#ifndef IPR_SASL_PHASE_3_INCLUDED
#define IPR_SASL_PHASE_3_INCLUDED



class IprSasl
{
public:

    static icl_info <icl_longstr_t *>::cpp_type
    PlainEncode (
        icl_info <char *>::cpp_const_type_ref login,
        icl_info <char *>::cpp_const_type_ref password);

    static icl_info <int>::cpp_type
    PlainDecode (
        icl_info <icl_longstr_t *>::cpp_type_ref auth_data,
        icl_info <char *>::cpp_type_ref login,
        icl_info <char *>::cpp_type_ref password);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprSasl ();
    IprSasl (const IprSasl&);
    IprSasl &operator = (const IprSasl&);
};



#endif
#endif
