/*---------------------------------------------------------------------------
    icl_longstr.cpp - icl_longstr component wrapper implementation in C++

    We define the icl_longstr_t type in order to provide a secure way of
    storing and serialising long strings.  A "long string" is defined
    as one that can be serialised as a 32-bit length indicator
    plus 0-4Gb-1 octets of data. The icl_longstr_t type is held in memory
    as descriptor consisting of a size field and a data reference.
    Generated from icl_longstr.icl by icl_gen using GSL/4.
    
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

#include "icl_longstr.hpp"


IclLongstr::IclLongstr (
        icl_info <void *>::cpp_type_ref data,
        icl_info <size_t>::cpp_type_ref size)
{
    p = icl_longstr_new (data, size);
}

icl_info <int>::cpp_type
IclLongstr::Resize (
        icl_info <size_t>::cpp_type_ref size)
{
    return icl_longstr_resize (this->p, size);
}

icl_info <int>::cpp_type
IclLongstr::Eq (
        icl_info <icl_longstr_t *>::cpp_type_ref second)
{
    return icl_longstr_eq (this->p, second);
}

icl_info <int>::cpp_type
IclLongstr::Fmt (
        icl_info <char *>::cpp_type_ref format,
        ...)
{
    va_list
        args;
    va_start (args, format);
    return icl_longstr_fmt_v (this->p, format, args);
    va_end (args);
}

icl_info <int>::cpp_type
IclLongstr::FmtV (
        icl_info <char *>::cpp_type_ref format,
        va_list args)
{
    return icl_longstr_fmt_v (this->p, format, args);
}

void
IclLongstr::Selftest (
        void)
{
    icl_longstr_selftest ();
}

void
IclLongstr::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    icl_longstr_animate (enabled);
}
