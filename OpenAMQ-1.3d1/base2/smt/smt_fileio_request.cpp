/*---------------------------------------------------------------------------
    smt_fileio_request.cpp - smt_fileio_request component wrapper implementation in C++

    The smt_fileio_request class contains all the methods for doing activity
    on an open file.
    Generated from smt_fileio_request.icl by icl_gen using GSL/4.
    
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

#include "smt_fileio_request.hpp"


icl_info <int>::cpp_type
SmtFileioRequest::Read (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_fileio_t *>::cpp_type_ref file,
        icl_info <size_t>::cpp_type_ref min_size,
        icl_info <size_t>::cpp_type_ref max_size,
        icl_info <byte *>::cpp_type_ref buffer,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_fileio_request_read (thread, file, min_size, max_size, buffer, event);
}

icl_info <int>::cpp_type
SmtFileioRequest::Write (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_fileio_t *>::cpp_type_ref file,
        icl_info <size_t>::cpp_type_ref size,
        icl_info <byte *>::cpp_type_ref buffer,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_fileio_request_write (thread, file, size, buffer, event);
}

icl_info <int>::cpp_type
SmtFileioRequest::Close (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_fileio_t *>::cpp_type_ref file,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_fileio_request_close (thread, file, event);
}

icl_info <int>::cpp_type
SmtFileioRequest::Seek (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_fileio_t *>::cpp_type_ref file,
        icl_info <size_t>::cpp_type_ref offset,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_fileio_request_seek (thread, file, offset, event);
}

void
SmtFileioRequest::Selftest (
        void)
{
    smt_fileio_request_selftest ();
}

void
SmtFileioRequest::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    smt_fileio_request_animate (enabled);
}
