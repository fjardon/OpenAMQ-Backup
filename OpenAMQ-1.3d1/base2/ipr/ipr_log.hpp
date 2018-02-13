/*---------------------------------------------------------------------------
    ipr_log.hpp - ipr_log component wrapper in C++

    Generated from ipr_log.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_LOG_PHASE) || IPR_LOG_PHASE==1
#ifndef IPR_LOG_PHASE_1_INCLUDED
#define IPR_LOG_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_log.h"
#include "icl_info.hpp"


#ifndef   ICL_SHORTSTR_PHASE_1_INCLUDED
#define   ICL_SHORTSTR_PHASE 1
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_FILE_PHASE_1_INCLUDED
#define   IPR_FILE_PHASE 1
#include  "ipr_file.hpp"
#undef    IPR_FILE_PHASE
#endif
#ifndef   IPR_PROCESS_PHASE_1_INCLUDED
#define   IPR_PROCESS_PHASE 1
#include  "ipr_process.hpp"
#undef    IPR_PROCESS_PHASE
#endif

#endif
#endif

#if !defined(IPR_LOG_PHASE) || IPR_LOG_PHASE==2
#ifndef IPR_LOG_PHASE_2_INCLUDED
#define IPR_LOG_PHASE_2_INCLUDED


#ifndef   ICL_SHORTSTR_PHASE_2_INCLUDED
#define   ICL_SHORTSTR_PHASE 2
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_FILE_PHASE_2_INCLUDED
#define   IPR_FILE_PHASE 2
#include  "ipr_file.hpp"
#undef    IPR_FILE_PHASE
#endif
#ifndef   IPR_PROCESS_PHASE_2_INCLUDED
#define   IPR_PROCESS_PHASE 2
#include  "ipr_process.hpp"
#undef    IPR_PROCESS_PHASE
#endif

#endif
#endif

#if !defined(IPR_LOG_PHASE) || IPR_LOG_PHASE==3
#ifndef IPR_LOG_PHASE_3_INCLUDED
#define IPR_LOG_PHASE_3_INCLUDED

#ifndef   ICL_SHORTSTR_PHASE_3_INCLUDED
#define   ICL_SHORTSTR_PHASE 3
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_FILE_PHASE_3_INCLUDED
#define   IPR_FILE_PHASE 3
#include  "ipr_file.hpp"
#undef    IPR_FILE_PHASE
#endif
#ifndef   IPR_PROCESS_PHASE_3_INCLUDED
#define   IPR_PROCESS_PHASE 3
#include  "ipr_process.hpp"
#undef    IPR_PROCESS_PHASE
#endif


class IprLog
{
public:

    static icl_info <int>::cpp_type
    Cycle (
        icl_info <char *>::cpp_type_ref filename,
        icl_info <char *>::cpp_type_ref directory,
        icl_info <char *>::cpp_type_ref command);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprLog ();
    IprLog (const IprLog&);
    IprLog &operator = (const IprLog&);
};



#endif
#endif
