/*---------------------------------------------------------------------------
    smt_fileio.cpp - smt_fileio component wrapper implementation in C++

    The smt_fileio class is used to create socket objects for use with the
    smt_fileio_request class.
    Generated from smt_fileio.icl by icl_gen using GSL/4.
    
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

#include "smt_fileio.hpp"


icl_info <smt_fileio_t *>::cpp_type
SmtFileio::Open (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <const char *>::cpp_type_ref path,
        icl_info <const char *>::cpp_type_ref name,
        icl_info <smt_file_mode_e>::cpp_type_ref mode,
        icl_info <Bool>::cpp_type_ref binary,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_fileio_open (thread, path, name, mode, binary, event);
}

icl_info <smt_fileio_t *>::cpp_type
SmtFileio::Temp (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <const char *>::cpp_type_ref path,
        icl_info <Bool>::cpp_type_ref binary,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_fileio_temp (thread, path, binary, event);
}

icl_info <Bool>::cpp_type
SmtFileio::Eof (
        void)
{
    return smt_fileio_eof (this->p);
}

void
SmtFileio::Selftest (
        void)
{
    smt_fileio_selftest ();
}

void
SmtFileio::Terminate (
        void)
{
    smt_fileio_terminate ();
}

void
SmtFileio::Show (
        icl_info <void *>::cpp_type_ref item,
        icl_info <int>::cpp_type_ref opcode,
        icl_info <FILE *>::cpp_type_ref trace_file)
{
    smt_fileio_show (item, opcode, trace_file);
}

void
SmtFileio::DestroyPublic (
        void)
{
    smt_fileio_destroy_public (this->p);
}

void
SmtFileio::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    smt_fileio_animate (enabled);
}
