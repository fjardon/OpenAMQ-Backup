/*---------------------------------------------------------------------------
    ipr_str.cpp - ipr_str component wrapper implementation in C++

    Provides various string manipulation functions.
    Generated from ipr_str.icl by icl_gen using GSL/4.
    
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

#include "ipr_str.hpp"


icl_info <char *>::cpp_type
IprStr::Skip (
        icl_info <char *>::cpp_type_ref string)
{
    return ipr_str_skip (string);
}

icl_info <char *>::cpp_type
IprStr::Wipe (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char>::cpp_type_ref ch)
{
    return ipr_str_wipe (string, ch);
}

icl_info <char *>::cpp_type
IprStr::Lower (
        icl_info <char *>::cpp_type_ref string)
{
    return ipr_str_lower (string);
}

icl_info <char *>::cpp_type
IprStr::Upper (
        icl_info <char *>::cpp_type_ref string)
{
    return ipr_str_upper (string);
}

icl_info <char *>::cpp_type
IprStr::Subch (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char>::cpp_type_ref from,
        icl_info <char>::cpp_type_ref to)
{
    return ipr_str_subch (string, from, to);
}

icl_info <char *>::cpp_type
IprStr::Crop (
        icl_info <char *>::cpp_type_ref string)
{
    return ipr_str_crop (string);
}

icl_info <char *>::cpp_type
IprStr::Filter (
        icl_info <char *>::cpp_type_ref string)
{
    return ipr_str_filter (string);
}

icl_info <int>::cpp_type
IprStr::Match (
        icl_info <char *>::cpp_type_ref string1,
        icl_info <char *>::cpp_type_ref string2)
{
    return ipr_str_match (string1, string2);
}

icl_info <Bool>::cpp_type
IprStr::Prefixed (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref prefix)
{
    return ipr_str_prefixed (string, prefix);
}

icl_info <char *>::cpp_type
IprStr::Defix (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref prefix)
{
    return ipr_str_defix (string, prefix);
}

icl_info <char *>::cpp_type
IprStr::Clean (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char>::cpp_type_ref from,
        icl_info <char>::cpp_type_ref to)
{
    return ipr_str_clean (string, from, to);
}

icl_info <Bool>::cpp_type
IprStr::Lexeq (
        icl_info <char *>::cpp_type_ref string1,
        icl_info <char *>::cpp_type_ref string2)
{
    return ipr_str_lexeq (string1, string2);
}

icl_info <int>::cpp_type
IprStr::Lexcmp (
        icl_info <char *>::cpp_type_ref string1,
        icl_info <char *>::cpp_type_ref string2)
{
    return ipr_str_lexcmp (string1, string2);
}

icl_info <char *>::cpp_type
IprStr::Soundex (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref encoding)
{
    return ipr_str_soundex (string, encoding);
}

icl_info <Bool>::cpp_type
IprStr::Matches (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref pattern)
{
    return ipr_str_matches (string, pattern);
}

icl_info <char *>::cpp_type
IprStr::Random (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref pattern)
{
    return ipr_str_random (string, pattern);
}

void
IprStr::Selftest (
        void)
{
    ipr_str_selftest ();
}

void
IprStr::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    ipr_str_animate (enabled);
}
