/*---------------------------------------------------------------------------
    icl_apr.cpp - icl_apr component wrapper implementation in C++

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

#include "icl_apr.hpp"


void
IclApr::AprAssert (
        icl_info <apr_status_t>::cpp_type_ref status)
{
    icl_apr_assert (status);
}

void
IclApr::AprErrorPrint (
        icl_info <apr_status_t>::cpp_type_ref status)
{
    icl_apr_error_print (status);
}

icl_info <qbyte>::cpp_type
IclApr::AtomicInc32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem)
{
    return icl_atomic_inc32 (mem);
}

icl_info <Bool>::cpp_type
IclApr::AtomicDec32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem)
{
    return icl_atomic_dec32 (mem);
}

icl_info <qbyte>::cpp_type
IclApr::AtomicGet32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem)
{
    return icl_atomic_get32 (mem);
}

void
IclApr::AtomicSet32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref val)
{
    icl_atomic_set32 (mem, val);
}

icl_info <qbyte>::cpp_type
IclApr::AtomicAdd32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref add_val)
{
    return icl_atomic_add32 (mem, add_val);
}

void
IclApr::AtomicSub32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref val)
{
    icl_atomic_sub32 (mem, val);
}

icl_info <qbyte>::cpp_type
IclApr::AtomicCas32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref new_val,
        icl_info <qbyte>::cpp_type_ref cmp_val)
{
    return icl_atomic_cas32 (mem, new_val, cmp_val);
}

icl_info <volatile void *>::cpp_type
IclApr::AtomicCasptr (
        icl_info <volatile void **>::cpp_type_ref mem,
        icl_info <void *>::cpp_type_ref new_val,
        icl_info <void *>::cpp_type_ref cmp_val)
{
    return icl_atomic_casptr (mem, new_val, cmp_val);
}

icl_info <qbyte>::cpp_type
IclApr::AtomicSwap (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref new_val)
{
    return icl_atomic_swap (mem, new_val);
}

void
IclApr::Selftest (
        void)
{
    icl_selftest ();
}

void
IclApr::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    icl_animate (enabled);
}
