/*---------------------------------------------------------------------------
    smt_socket_request.cpp - smt_socket_request component wrapper implementation in C++

    The smt_socket_request class contains all the methods for doing activity
    on a connected socket.  The socket may be connected by smt_socket_connect
    or a slave socket created when by remote connection to a passively opened
    socket.

    You do not typically need to manipulate smt_socket_request objects; once
    created they do the work without further intervention by the application.
    Generated from smt_socket_request.icl by icl_gen using GSL/4.
    
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

#include "smt_socket_request.hpp"


SmtSocketRequest::SmtSocketRequest (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_request_type_t>::cpp_type_ref type,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <smt_event_t>::cpp_type_ref input_event,
        icl_info <smt_event_t>::cpp_type_ref output_event)
{
    p = new proxy_t;
    p->refcount = 1;
    p->p = smt_socket_request_new (thread, type, socket, msecs, input_event, output_event);
}

void
SmtSocketRequest::Initialise (
        void)
{
    smt_socket_request_initialise ();
}

void
SmtSocketRequest::Timer (
        void)
{
    smt_socket_request_timer (this->p->p);
}

icl_info <smt_socket_request_t *>::cpp_type
SmtSocketRequest::Accept (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <smt_event_t>::cpp_type_ref event,
        icl_info <smt_socket_t **>::cpp_type_ref connect)
{
    return smt_socket_request_accept (thread, socket, msecs, event, connect);
}

void
SmtSocketRequest::Return (
        icl_info <int>::cpp_type_ref result,
        icl_info <int>::cpp_type_ref error)
{
    smt_socket_request_return (this->p->p, result, error);
}

icl_info <smt_socket_request_t *>::cpp_type
SmtSocketRequest::Monitor (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <smt_event_t>::cpp_type_ref input_event,
        icl_info <smt_event_t>::cpp_type_ref output_event)
{
    return smt_socket_request_monitor (thread, socket, msecs, input_event, output_event);
}

icl_info <smt_socket_request_t *>::cpp_type
SmtSocketRequest::Read (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <size_t>::cpp_type_ref min_size,
        icl_info <size_t>::cpp_type_ref max_size,
        icl_info <byte *>::cpp_type_ref buffer,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_socket_request_read (thread, socket, msecs, min_size, max_size, buffer, event);
}

icl_info <smt_socket_request_t *>::cpp_type
SmtSocketRequest::ReadBucket (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <size_t>::cpp_type_ref min_size,
        icl_info <size_t>::cpp_type_ref max_size,
        icl_info <ipr_bucket_t **>::cpp_type_ref bucket_p,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_socket_request_read_bucket (thread, socket, msecs, min_size, max_size, bucket_p, event);
}

icl_info <smt_socket_request_t *>::cpp_type
SmtSocketRequest::ReadMother (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <size_t>::cpp_type_ref size,
        icl_info <ipr_mother_t *>::cpp_type_ref mother,
        icl_info <ipr_bucket_t **>::cpp_type_ref slave_p,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_socket_request_read_mother (thread, socket, msecs, size, mother, slave_p, event);
}

icl_info <smt_socket_request_t *>::cpp_type
SmtSocketRequest::Write (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <size_t>::cpp_type_ref size,
        icl_info <byte *>::cpp_type_ref buffer,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_socket_request_write (thread, socket, msecs, size, buffer, event);
}

icl_info <smt_socket_request_t *>::cpp_type
SmtSocketRequest::WriteBucket (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <ipr_bucket_t *>::cpp_type_ref bucket,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_socket_request_write_bucket (thread, socket, msecs, bucket, event);
}

icl_info <smt_socket_request_t *>::cpp_type
SmtSocketRequest::Close (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t **>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <smt_event_t>::cpp_type_ref event)
{
    return smt_socket_request_close (thread, socket, msecs, event);
}

icl_info <int>::cpp_type
SmtSocketRequest::Poll (
        icl_info <smt_os_thread_t *>::cpp_type_ref os_thread,
        icl_info <Bool>::cpp_type_ref force)
{
    return smt_socket_request_poll (os_thread, force);
}

icl_info <int>::cpp_type
SmtSocketRequest::Wait (
        icl_info <smt_os_thread_t *>::cpp_type_ref os_thread)
{
    return smt_socket_request_wait (os_thread);
}

void
SmtSocketRequest::Trace (
        icl_info <Bool>::cpp_type_ref enabled)
{
    smt_socket_request_trace (enabled);
}

void
SmtSocketRequest::Selftest (
        void)
{
    smt_socket_request_selftest ();
}

icl_info <smt_socket_request_t *>::cpp_type
SmtSocketRequest::WriteData (
        void)
{
    return smt_socket_request_write_data (this->p->p);
}

void
SmtSocketRequest::RemoveFromAllContainers (
        void)
{
    smt_socket_request_remove_from_all_containers (this->p->p);
}

void
SmtSocketRequest::Show (
        icl_info <void *>::cpp_type_ref item,
        icl_info <int>::cpp_type_ref opcode,
        icl_info <FILE *>::cpp_type_ref trace_file)
{
    smt_socket_request_show (item, opcode, trace_file);
}

void
SmtSocketRequest::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    smt_socket_request_animate (enabled);
}
