/*---------------------------------------------------------------------------
    ipr_str.hpp - ipr_str component wrapper in C++

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

#if !defined(IPR_STR_PHASE) || IPR_STR_PHASE==1
#ifndef IPR_STR_PHASE_1_INCLUDED
#define IPR_STR_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_str.h"
#include "icl_info.hpp"


#ifndef   ICL_SHORTSTR_PHASE_1_INCLUDED
#define   ICL_SHORTSTR_PHASE 1
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_REGEXP_PHASE_1_INCLUDED
#define   IPR_REGEXP_PHASE 1
#include  "ipr_regexp.hpp"
#undef    IPR_REGEXP_PHASE
#endif

#endif
#endif

#if !defined(IPR_STR_PHASE) || IPR_STR_PHASE==2
#ifndef IPR_STR_PHASE_2_INCLUDED
#define IPR_STR_PHASE_2_INCLUDED


#ifndef   ICL_SHORTSTR_PHASE_2_INCLUDED
#define   ICL_SHORTSTR_PHASE 2
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_REGEXP_PHASE_2_INCLUDED
#define   IPR_REGEXP_PHASE 2
#include  "ipr_regexp.hpp"
#undef    IPR_REGEXP_PHASE
#endif

#endif
#endif

#if !defined(IPR_STR_PHASE) || IPR_STR_PHASE==3
#ifndef IPR_STR_PHASE_3_INCLUDED
#define IPR_STR_PHASE_3_INCLUDED

#ifndef   ICL_SHORTSTR_PHASE_3_INCLUDED
#define   ICL_SHORTSTR_PHASE 3
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_REGEXP_PHASE_3_INCLUDED
#define   IPR_REGEXP_PHASE 3
#include  "ipr_regexp.hpp"
#undef    IPR_REGEXP_PHASE
#endif


class IprStr
{
public:

    static icl_info <char *>::cpp_type
    Skip (
        icl_info <char *>::cpp_type_ref string);

    static icl_info <char *>::cpp_type
    Wipe (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char>::cpp_type_ref ch);

    static icl_info <char *>::cpp_type
    Lower (
        icl_info <char *>::cpp_type_ref string);

    static icl_info <char *>::cpp_type
    Upper (
        icl_info <char *>::cpp_type_ref string);

    static icl_info <char *>::cpp_type
    Subch (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char>::cpp_type_ref from,
        icl_info <char>::cpp_type_ref to);

    static icl_info <char *>::cpp_type
    Crop (
        icl_info <char *>::cpp_type_ref string);

    static icl_info <char *>::cpp_type
    Filter (
        icl_info <char *>::cpp_type_ref string);

    static icl_info <int>::cpp_type
    Match (
        icl_info <char *>::cpp_type_ref string1,
        icl_info <char *>::cpp_type_ref string2);

    static icl_info <Bool>::cpp_type
    Prefixed (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref prefix);

    static icl_info <char *>::cpp_type
    Defix (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref prefix);

    static icl_info <char *>::cpp_type
    Clean (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char>::cpp_type_ref from,
        icl_info <char>::cpp_type_ref to);

    static icl_info <Bool>::cpp_type
    Lexeq (
        icl_info <char *>::cpp_type_ref string1,
        icl_info <char *>::cpp_type_ref string2);

    static icl_info <int>::cpp_type
    Lexcmp (
        icl_info <char *>::cpp_type_ref string1,
        icl_info <char *>::cpp_type_ref string2);

    static icl_info <char *>::cpp_type
    Soundex (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref encoding);

    static icl_info <Bool>::cpp_type
    Matches (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref pattern);

    static icl_info <char *>::cpp_type
    Random (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref pattern);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprStr ();
    IprStr (const IprStr&);
    IprStr &operator = (const IprStr&);
};



#endif
#endif
