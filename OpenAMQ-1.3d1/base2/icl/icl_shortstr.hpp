/*---------------------------------------------------------------------------
    icl_shortstr.hpp - icl_shortstr component wrapper in C++

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

#if !defined(ICL_SHORTSTR_PHASE) || ICL_SHORTSTR_PHASE==1
#ifndef ICL_SHORTSTR_PHASE_1_INCLUDED
#define ICL_SHORTSTR_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "icl_shortstr.h"
#include "icl_info.hpp"



#endif
#endif

#if !defined(ICL_SHORTSTR_PHASE) || ICL_SHORTSTR_PHASE==2
#ifndef ICL_SHORTSTR_PHASE_2_INCLUDED
#define ICL_SHORTSTR_PHASE_2_INCLUDED



#endif
#endif

#if !defined(ICL_SHORTSTR_PHASE) || ICL_SHORTSTR_PHASE==3
#ifndef ICL_SHORTSTR_PHASE_3_INCLUDED
#define ICL_SHORTSTR_PHASE_3_INCLUDED



class IclShortstr
{
public:

    static icl_info <size_t>::cpp_type
    Cpy (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src);

    static icl_info <size_t>::cpp_type
    Cat (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src);

    static icl_info <size_t>::cpp_type
    Ncpy (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src,
        icl_info <size_t>::cpp_type_ref size);

    static icl_info <size_t>::cpp_type
    Ncat (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src,
        icl_info <size_t>::cpp_type_ref size);

    static icl_info <char *>::cpp_type
    Fmt (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref format,
        ...);

    static icl_info <char *>::cpp_type
    FmtV (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref format,
        va_list args);

    static icl_info <size_t>::cpp_type
    Read (
        icl_info <char *>::cpp_type_ref string,
        icl_info <FILE *>::cpp_type_ref file);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IclShortstr ();
    IclShortstr (const IclShortstr&);
    IclShortstr &operator = (const IclShortstr&);
};



#endif
#endif
