/*---------------------------------------------------------------------------
    smt_os_thread.cpp - smt_os_thread component wrapper implementation in C++

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

#include "smt_os_thread.hpp"


void
SmtOsThread::RemoveThread (
        icl_info <smt_thread_t *>::cpp_type_ref thread)
{
    smt_os_thread_remove_thread (thread);
}

void
SmtOsThread::RequestBreak (
        void)
{
    smt_request_break ();
}

void
SmtOsThread::ShutDown (
        void)
{
    smt_shut_down ();
}

icl_info <int>::cpp_type
SmtOsThread::Wait (
        icl_info <qbyte>::cpp_type_ref msecs)
{
    return smt_wait (msecs);
}

icl_info <int>::cpp_type
SmtOsThread::Wake (
        void)
{
    return smt_os_thread_wake (this->p);
}

icl_info <smt_os_thread_t *>::cpp_type
SmtOsThread::Assign (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <uint>::cpp_type_ref schedule)
{
    return smt_os_thread_assign (thread, this->p, schedule);
}

void
SmtOsThread::Selftest (
        void)
{
    smt_os_thread_selftest ();
}

void
SmtOsThread::SetPollingThreads (
        icl_info <int>::cpp_type_ref number)
{
    smt_set_polling_threads (number);
}

void
SmtOsThread::SetWorkingThreads (
        icl_info <int>::cpp_type_ref number)
{
    smt_set_working_threads (number);
}

void
SmtOsThread::SetActionLimit (
        icl_info <int>::cpp_type_ref action_limit)
{
    smt_set_action_limit (action_limit);
}

icl_info <apr_time_t>::cpp_type
SmtOsThread::TimeNow (
        void)
{
    return smt_time_now ();
}

void
SmtOsThread::Initialise (
        void)
{
    smt_initialise ();
}

void
SmtOsThread::Terminate (
        void)
{
    smt_terminate ();
}

void
SmtOsThread::RemoveFromAllContainers (
        void)
{
    smt_os_thread_remove_from_all_containers (this->p);
}

void
SmtOsThread::Show (
        icl_info <void *>::cpp_type_ref item,
        icl_info <int>::cpp_type_ref opcode,
        icl_info <FILE *>::cpp_type_ref trace_file)
{
    smt_os_thread_show (item, opcode, trace_file);
}

icl_info <int>::cpp_type
SmtOsThread::Join (
        void)
{
    return smt_os_thread_join (this->p);
}

void
SmtOsThread::DestroyPublic (
        void)
{
    smt_os_thread_destroy_public (this->p);
}

void
SmtOsThread::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    smt_os_thread_animate (enabled);
}
