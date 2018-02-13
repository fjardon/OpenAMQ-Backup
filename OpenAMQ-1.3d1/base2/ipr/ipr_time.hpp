/*---------------------------------------------------------------------------
    ipr_time.hpp - ipr_time component wrapper in C++

    Provides various date & time manipulation functions.
    Generated from ipr_time.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_TIME_PHASE) || IPR_TIME_PHASE==1
#ifndef IPR_TIME_PHASE_1_INCLUDED
#define IPR_TIME_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_time.h"
#include "icl_info.hpp"



#endif
#endif

#if !defined(IPR_TIME_PHASE) || IPR_TIME_PHASE==2
#ifndef IPR_TIME_PHASE_2_INCLUDED
#define IPR_TIME_PHASE_2_INCLUDED



#endif
#endif

#if !defined(IPR_TIME_PHASE) || IPR_TIME_PHASE==3
#ifndef IPR_TIME_PHASE_3_INCLUDED
#define IPR_TIME_PHASE_3_INCLUDED



class IprTime
{
public:

    static void
    Iso8601 (
        icl_info <ipr_time_t>::cpp_const_type_ref time,
        icl_info <ipr_date_format_t>::cpp_const_type_ref format,
        icl_info <byte>::cpp_const_type_ref precision,
        icl_info <Bool>::cpp_const_type_ref utc,
        icl_info <char*>::cpp_type_ref buffer);

    static icl_info <long>::cpp_type
    Now (
        void);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprTime ();
    IprTime (const IprTime&);
    IprTime &operator = (const IprTime&);
};



#endif
#endif
