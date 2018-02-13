/*---------------------------------------------------------------------------
    smt_signal.hpp - smt_signal component wrapper in C++

    The smt_signal class is used to manage signal handlers in an SMT
    application.
    Generated from smt_signal.icl by icl_gen using GSL/4.
    
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

#if !defined(SMT_SIGNAL_PHASE) || SMT_SIGNAL_PHASE==1
#ifndef SMT_SIGNAL_PHASE_1_INCLUDED
#define SMT_SIGNAL_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "smt_signal.h"
#include "icl_info.hpp"


#ifndef   SMT_THREAD_PHASE_1_INCLUDED
#define   SMT_THREAD_PHASE 1
#include  "smt_thread.hpp"
#undef    SMT_THREAD_PHASE
#endif
#ifndef   SMT_SIGNAL_TABLE_PHASE_1_INCLUDED
#define   SMT_SIGNAL_TABLE_PHASE 1
#include  "smt_signal_table.hpp"
#undef    SMT_SIGNAL_TABLE_PHASE
#endif
#ifndef   SMT_SIGNAL_BY_THREAD_PHASE_1_INCLUDED
#define   SMT_SIGNAL_BY_THREAD_PHASE 1
#include  "smt_signal_by_thread.hpp"
#undef    SMT_SIGNAL_BY_THREAD_PHASE
#endif
#ifndef   ICL_MEM_PHASE_1_INCLUDED
#define   ICL_MEM_PHASE 1
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif

#endif
#endif

#if !defined(SMT_SIGNAL_PHASE) || SMT_SIGNAL_PHASE==2
#ifndef SMT_SIGNAL_PHASE_2_INCLUDED
#define SMT_SIGNAL_PHASE_2_INCLUDED


#ifndef   SMT_THREAD_PHASE_2_INCLUDED
#define   SMT_THREAD_PHASE 2
#include  "smt_thread.hpp"
#undef    SMT_THREAD_PHASE
#endif
#ifndef   SMT_SIGNAL_TABLE_PHASE_2_INCLUDED
#define   SMT_SIGNAL_TABLE_PHASE 2
#include  "smt_signal_table.hpp"
#undef    SMT_SIGNAL_TABLE_PHASE
#endif
#ifndef   SMT_SIGNAL_BY_THREAD_PHASE_2_INCLUDED
#define   SMT_SIGNAL_BY_THREAD_PHASE 2
#include  "smt_signal_by_thread.hpp"
#undef    SMT_SIGNAL_BY_THREAD_PHASE
#endif
#ifndef   ICL_MEM_PHASE_2_INCLUDED
#define   ICL_MEM_PHASE 2
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif

#endif
#endif

#if !defined(SMT_SIGNAL_PHASE) || SMT_SIGNAL_PHASE==3
#ifndef SMT_SIGNAL_PHASE_3_INCLUDED
#define SMT_SIGNAL_PHASE_3_INCLUDED

#ifndef   SMT_THREAD_PHASE_3_INCLUDED
#define   SMT_THREAD_PHASE 3
#include  "smt_thread.hpp"
#undef    SMT_THREAD_PHASE
#endif
#ifndef   SMT_SIGNAL_TABLE_PHASE_3_INCLUDED
#define   SMT_SIGNAL_TABLE_PHASE 3
#include  "smt_signal_table.hpp"
#undef    SMT_SIGNAL_TABLE_PHASE
#endif
#ifndef   SMT_SIGNAL_BY_THREAD_PHASE_3_INCLUDED
#define   SMT_SIGNAL_BY_THREAD_PHASE 3
#include  "smt_signal_by_thread.hpp"
#undef    SMT_SIGNAL_BY_THREAD_PHASE
#endif
#ifndef   ICL_MEM_PHASE_3_INCLUDED
#define   ICL_MEM_PHASE 3
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif


class SmtSignal
{
public:

    static void
    Initialise (
        void);

    static icl_info <int>::cpp_type
    Register (
        icl_info <int>::cpp_type_ref the_signal,
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_event_t>::cpp_type_ref event);

    static void
    RegisterShutDown (
        icl_info <int>::cpp_type_ref the_signal);

    static void
    Deregister (
        icl_info <int>::cpp_type_ref the_signal);

    static void
    Selftest (
        void);

    static void
    RemoveFromAllContainers (
        void);

    static void
    Show (
        icl_info <void *>::cpp_type_ref item,
        icl_info <int>::cpp_type_ref opcode,
        icl_info <FILE *>::cpp_type_ref trace_file);

    static void
    DestroyPublic (
        void);

    static icl_info <int>::cpp_type
    ReadLock (
        void);

    static icl_info <int>::cpp_type
    WriteLock (
        void);

    static icl_info <int>::cpp_type
    Unlock (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    SmtSignal ();
    SmtSignal (const SmtSignal&);
    SmtSignal &operator = (const SmtSignal&);
};



#endif
#endif
