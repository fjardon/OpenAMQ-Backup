/*---------------------------------------------------------------------------
    smt_thread.hpp - smt_thread component wrapper in C++

    The smt_thread class manipulates SMT threads.
    For SMT internal use only.
    Generated from smt_thread.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    smt_os_thread.hpp - smt_os_thread component wrapper in C++

    The smt_os_thread class manipulates OS threads for SMT.

    It is for SMT internal use only.
    Generated from smt_os_thread.icl by icl_gen using GSL/4.
    
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

#if !defined(SMT_OS_THREAD_PHASE) || SMT_OS_THREAD_PHASE==1
#ifndef SMT_OS_THREAD_PHASE_1_INCLUDED
#define SMT_OS_THREAD_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "smt_os_thread.h"
#include "icl_info.hpp"


#ifndef   SMT_THREAD_PHASE_1_INCLUDED
#define   SMT_THREAD_PHASE 1
#include  "smt_thread.hpp"
#undef    SMT_THREAD_PHASE
#endif
#ifndef   SMT_OS_THREAD_BY_STATUS_PHASE_1_INCLUDED
#define   SMT_OS_THREAD_BY_STATUS_PHASE 1
#include  "smt_os_thread_by_status.hpp"
#undef    SMT_OS_THREAD_BY_STATUS_PHASE
#endif
#ifndef   SMT_OS_THREAD_LIST_PHASE_1_INCLUDED
#define   SMT_OS_THREAD_LIST_PHASE 1
#include  "smt_os_thread_list.hpp"
#undef    SMT_OS_THREAD_LIST_PHASE
#endif
#ifndef   ICL_SYSTEM_PHASE_1_INCLUDED
#define   ICL_SYSTEM_PHASE 1
#include  "icl_system.hpp"
#undef    ICL_SYSTEM_PHASE
#endif
#ifndef   ICL_MEM_PHASE_1_INCLUDED
#define   ICL_MEM_PHASE 1
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif

#endif
#endif

#if !defined(SMT_OS_THREAD_PHASE) || SMT_OS_THREAD_PHASE==2
#ifndef SMT_OS_THREAD_PHASE_2_INCLUDED
#define SMT_OS_THREAD_PHASE_2_INCLUDED


#ifndef   SMT_THREAD_PHASE_2_INCLUDED
#define   SMT_THREAD_PHASE 2
#include  "smt_thread.hpp"
#undef    SMT_THREAD_PHASE
#endif
#ifndef   SMT_OS_THREAD_BY_STATUS_PHASE_2_INCLUDED
#define   SMT_OS_THREAD_BY_STATUS_PHASE 2
#include  "smt_os_thread_by_status.hpp"
#undef    SMT_OS_THREAD_BY_STATUS_PHASE
#endif
#ifndef   SMT_OS_THREAD_LIST_PHASE_2_INCLUDED
#define   SMT_OS_THREAD_LIST_PHASE 2
#include  "smt_os_thread_list.hpp"
#undef    SMT_OS_THREAD_LIST_PHASE
#endif
#ifndef   ICL_SYSTEM_PHASE_2_INCLUDED
#define   ICL_SYSTEM_PHASE 2
#include  "icl_system.hpp"
#undef    ICL_SYSTEM_PHASE
#endif
#ifndef   ICL_MEM_PHASE_2_INCLUDED
#define   ICL_MEM_PHASE 2
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif

#endif
#endif

#if !defined(SMT_OS_THREAD_PHASE) || SMT_OS_THREAD_PHASE==3
#ifndef SMT_OS_THREAD_PHASE_3_INCLUDED
#define SMT_OS_THREAD_PHASE_3_INCLUDED

#ifndef   SMT_THREAD_PHASE_3_INCLUDED
#define   SMT_THREAD_PHASE 3
#include  "smt_thread.hpp"
#undef    SMT_THREAD_PHASE
#endif
#ifndef   SMT_OS_THREAD_BY_STATUS_PHASE_3_INCLUDED
#define   SMT_OS_THREAD_BY_STATUS_PHASE 3
#include  "smt_os_thread_by_status.hpp"
#undef    SMT_OS_THREAD_BY_STATUS_PHASE
#endif
#ifndef   SMT_OS_THREAD_LIST_PHASE_3_INCLUDED
#define   SMT_OS_THREAD_LIST_PHASE 3
#include  "smt_os_thread_list.hpp"
#undef    SMT_OS_THREAD_LIST_PHASE
#endif
#ifndef   ICL_SYSTEM_PHASE_3_INCLUDED
#define   ICL_SYSTEM_PHASE 3
#include  "icl_system.hpp"
#undef    ICL_SYSTEM_PHASE
#endif
#ifndef   ICL_MEM_PHASE_3_INCLUDED
#define   ICL_MEM_PHASE 3
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif


class SmtOsThread
{
public:

    static void
    RemoveThread (
        icl_info <smt_thread_t *>::cpp_type_ref thread);

    static void
    RequestBreak (
        void);

    static void
    ShutDown (
        void);

    static icl_info <int>::cpp_type
    Wait (
        icl_info <qbyte>::cpp_type_ref msecs);

    static icl_info <int>::cpp_type
    Wake (
        void);

    static icl_info <smt_os_thread_t *>::cpp_type
    Assign (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <uint>::cpp_type_ref schedule);

    static void
    Selftest (
        void);

    static void
    SetPollingThreads (
        icl_info <int>::cpp_type_ref number);

    static void
    SetWorkingThreads (
        icl_info <int>::cpp_type_ref number);

    static void
    SetActionLimit (
        icl_info <int>::cpp_type_ref action_limit);

    static icl_info <apr_time_t>::cpp_type
    TimeNow (
        void);

    static void
    Initialise (
        void);

    static void
    Terminate (
        void);

    static void
    RemoveFromAllContainers (
        void);

    static void
    Show (
        icl_info <void *>::cpp_type_ref item,
        icl_info <int>::cpp_type_ref opcode,
        icl_info <FILE *>::cpp_type_ref trace_file);

    static icl_info <int>::cpp_type
    Join (
        void);

    static void
    DestroyPublic (
        void);

    static icl_info <smt_os_thread_t *>::cpp_type
    Link (
        void);

    static void
    Unlink (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    SmtOsThread ();
    SmtOsThread (const SmtOsThread&);
    SmtOsThread &operator = (const SmtOsThread&);
};



#endif
#endif
