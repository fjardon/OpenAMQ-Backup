/*---------------------------------------------------------------------------
    icl_apr.hpp - icl_apr component wrapper in C++

    Provides iCL wrappers for some APR functions.
    Generated from icl_apr.icl by icl_gen using GSL/4.
    
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

#if !defined(ICL_APR_PHASE) || ICL_APR_PHASE==1
#ifndef ICL_APR_PHASE_1_INCLUDED
#define ICL_APR_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "icl_apr.h"
#include "icl_info.hpp"



#endif
#endif

#if !defined(ICL_APR_PHASE) || ICL_APR_PHASE==2
#ifndef ICL_APR_PHASE_2_INCLUDED
#define ICL_APR_PHASE_2_INCLUDED



#endif
#endif

#if !defined(ICL_APR_PHASE) || ICL_APR_PHASE==3
#ifndef ICL_APR_PHASE_3_INCLUDED
#define ICL_APR_PHASE_3_INCLUDED



class IclApr
{
public:

    static void
    AprAssert (
        icl_info <apr_status_t>::cpp_type_ref status);

    static void
    AprErrorPrint (
        icl_info <apr_status_t>::cpp_type_ref status);

    static icl_info <qbyte>::cpp_type
    AtomicInc32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem);

    static icl_info <Bool>::cpp_type
    AtomicDec32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem);

    static icl_info <qbyte>::cpp_type
    AtomicGet32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem);

    static void
    AtomicSet32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref val);

    static icl_info <qbyte>::cpp_type
    AtomicAdd32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref add_val);

    static void
    AtomicSub32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref val);

    static icl_info <qbyte>::cpp_type
    AtomicCas32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref new_val,
        icl_info <qbyte>::cpp_type_ref cmp_val);

    static icl_info <volatile void *>::cpp_type
    AtomicCasptr (
        icl_info <volatile void **>::cpp_type_ref mem,
        icl_info <void *>::cpp_type_ref new_val,
        icl_info <void *>::cpp_type_ref cmp_val);

    static icl_info <qbyte>::cpp_type
    AtomicSwap (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref new_val);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IclApr ();
    IclApr (const IclApr&);
    IclApr &operator = (const IclApr&);
};



#endif
#endif
