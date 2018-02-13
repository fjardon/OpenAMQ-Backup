/*---------------------------------------------------------------------------
    icl_shortstr.cpp - icl_shortstr component wrapper implementation in C++

    We define the icl_shortstr_t type in order to provide a simple way of
    storing and serialising short strings.  A "short string" is defined
    as one that can be serialised as a single-octet length indicator
    plus 0-255 octets of data.  The icl_shortstr_t type is held in memory
    as C-compatible null-terminated char arrays of 255+1 bytes.  There
    are no constructor/destructor methods for icl_shortstr_t variables since
    this would create incompatabilities with normal C strings.  See the
    selftest method for examples of using icl_shortstr_t.  When writing a
    icl_shortstr_t you should always use the icl_shortstr_cpy method to
    avoid the risk of overflows.
    Generated from icl_shortstr.icl by icl_gen using GSL/4.
    
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

#include "icl_shortstr.hpp"


icl_info <size_t>::cpp_type
IclShortstr::Cpy (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src)
{
    return icl_shortstr_cpy (dest, src);
}

icl_info <size_t>::cpp_type
IclShortstr::Cat (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src)
{
    return icl_shortstr_cat (dest, src);
}

icl_info <size_t>::cpp_type
IclShortstr::Ncpy (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src,
        icl_info <size_t>::cpp_type_ref size)
{
    return icl_shortstr_ncpy (dest, src, size);
}

icl_info <size_t>::cpp_type
IclShortstr::Ncat (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src,
        icl_info <size_t>::cpp_type_ref size)
{
    return icl_shortstr_ncat (dest, src, size);
}

icl_info <char *>::cpp_type
IclShortstr::Fmt (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref format,
        ...)
{
    va_list
        args;
    va_start (args, format);
    return icl_shortstr_fmt_v (dest, format, args);
    va_end (args);
}

icl_info <char *>::cpp_type
IclShortstr::FmtV (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref format,
        va_list args)
{
    return icl_shortstr_fmt_v (dest, format, args);
}

icl_info <size_t>::cpp_type
IclShortstr::Read (
        icl_info <char *>::cpp_type_ref string,
        icl_info <FILE *>::cpp_type_ref file)
{
    return icl_shortstr_read (string, file);
}

void
IclShortstr::Selftest (
        void)
{
    icl_shortstr_selftest ();
}

void
IclShortstr::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    icl_shortstr_animate (enabled);
}
