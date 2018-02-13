/*---------------------------------------------------------------------------
    smt_signal.cpp - smt_signal component wrapper implementation in C++

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

#include "smt_signal.hpp"


void
SmtSignal::Initialise (
        void)
{
    smt_signal_initialise ();
}

icl_info <int>::cpp_type
SmtSignal::Register (
        icl_info <int>::cpp_type_ref the_signal,
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_signal_register (the_signal, thread, event);
}

void
SmtSignal::RegisterShutDown (
        icl_info <int>::cpp_type_ref the_signal)
{
    smt_signal_register_shut_down (the_signal);
}

void
SmtSignal::Deregister (
        icl_info <int>::cpp_type_ref the_signal)
{
    smt_signal_deregister (the_signal);
}

void
SmtSignal::Selftest (
        void)
{
    smt_signal_selftest ();
}

void
SmtSignal::RemoveFromAllContainers (
        void)
{
    smt_signal_remove_from_all_containers (this->p);
}

void
SmtSignal::Show (
        icl_info <void *>::cpp_type_ref item,
        icl_info <int>::cpp_type_ref opcode,
        icl_info <FILE *>::cpp_type_ref trace_file)
{
    smt_signal_show (item, opcode, trace_file);
}

void
SmtSignal::DestroyPublic (
        void)
{
    smt_signal_destroy_public (this->p);
}

icl_info <int>::cpp_type
SmtSignal::ReadLock (
        void)
{
    return smt_signal_read_lock (this->p);
}

icl_info <int>::cpp_type
SmtSignal::WriteLock (
        void)
{
    return smt_signal_write_lock (this->p);
}

icl_info <int>::cpp_type
SmtSignal::Unlock (
        void)
{
    return smt_signal_unlock (this->p);
}

void
SmtSignal::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    smt_signal_animate (enabled);
}
