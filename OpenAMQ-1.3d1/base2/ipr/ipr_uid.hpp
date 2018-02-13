/*---------------------------------------------------------------------------
    ipr_uid.hpp - ipr_uid component wrapper in C++

    Provides functions to access and maniuplate the current process
    user and group IDs.
    Generated from ipr_uid.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_UID_PHASE) || IPR_UID_PHASE==1
#ifndef IPR_UID_PHASE_1_INCLUDED
#define IPR_UID_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_uid.h"
#include "icl_info.hpp"


#ifndef   ICL_SHORTSTR_PHASE_1_INCLUDED
#define   ICL_SHORTSTR_PHASE 1
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif

#endif
#endif

#if !defined(IPR_UID_PHASE) || IPR_UID_PHASE==2
#ifndef IPR_UID_PHASE_2_INCLUDED
#define IPR_UID_PHASE_2_INCLUDED


#ifndef   ICL_SHORTSTR_PHASE_2_INCLUDED
#define   ICL_SHORTSTR_PHASE 2
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif

#endif
#endif

#if !defined(IPR_UID_PHASE) || IPR_UID_PHASE==3
#ifndef IPR_UID_PHASE_3_INCLUDED
#define IPR_UID_PHASE_3_INCLUDED

#ifndef   ICL_SHORTSTR_PHASE_3_INCLUDED
#define   ICL_SHORTSTR_PHASE 3
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif


class IprUid
{
public:

    static icl_info <int>::cpp_type
    UserName (
        icl_info <uid_t>::cpp_type_ref uid,
        icl_info <char *>::cpp_type_ref name);

    static icl_info <int>::cpp_type
    GroupName (
        icl_info <uid_t>::cpp_type_ref gid,
        icl_info <char *>::cpp_type_ref name);

    static icl_info <int>::cpp_type
    SetRealUser (
        void);

    static icl_info <int>::cpp_type
    SetRootUser (
        void);

    static icl_info <int>::cpp_type
    SetRealGroup (
        void);

    static icl_info <int>::cpp_type
    SetRootGroup (
        void);

    static icl_info <int>::cpp_type
    GetUid (
        void);

    static icl_info <int>::cpp_type
    GetGid (
        void);

    static icl_info <int>::cpp_type
    RunAs (
        icl_info <char *>::cpp_type_ref user,
        icl_info <char *>::cpp_type_ref group);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprUid ();
    IprUid (const IprUid&);
    IprUid &operator = (const IprUid&);
};



#endif
#endif
