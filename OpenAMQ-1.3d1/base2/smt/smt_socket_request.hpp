/*---------------------------------------------------------------------------
    smt_socket_request.hpp - smt_socket_request component wrapper in C++

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

#if !defined(SMT_SOCKET_REQUEST_PHASE) || SMT_SOCKET_REQUEST_PHASE==1
#ifndef SMT_SOCKET_REQUEST_PHASE_1_INCLUDED
#define SMT_SOCKET_REQUEST_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "smt_socket_request.h"
#include "icl_info.hpp"

class SmtSocketRequest;
template <> struct icl_info <smt_socket_request_t*>;

#ifndef   IPR_BUCKET_PHASE_1_INCLUDED
#define   IPR_BUCKET_PHASE 1
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif
#ifndef   ICL_SHORTSTR_PHASE_1_INCLUDED
#define   ICL_SHORTSTR_PHASE 1
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   SMT_OS_THREAD_PHASE_1_INCLUDED
#define   SMT_OS_THREAD_PHASE 1
#include  "smt_os_thread.hpp"
#undef    SMT_OS_THREAD_PHASE
#endif
#ifndef   SMT_THREAD_PHASE_1_INCLUDED
#define   SMT_THREAD_PHASE 1
#include  "smt_thread.hpp"
#undef    SMT_THREAD_PHASE
#endif
#ifndef   SMT_SOCKET_PHASE_1_INCLUDED
#define   SMT_SOCKET_PHASE 1
#include  "smt_socket.hpp"
#undef    SMT_SOCKET_PHASE
#endif
#ifndef   SMT_TIMER_REQUEST_PHASE_1_INCLUDED
#define   SMT_TIMER_REQUEST_PHASE 1
#include  "smt_timer_request.hpp"
#undef    SMT_TIMER_REQUEST_PHASE
#endif
#ifndef   SMT_SOCKET_REQUEST_BY_THREAD_PHASE_1_INCLUDED
#define   SMT_SOCKET_REQUEST_BY_THREAD_PHASE 1
#include  "smt_socket_request_by_thread.hpp"
#undef    SMT_SOCKET_REQUEST_BY_THREAD_PHASE
#endif
#ifndef   SMT_SOCKET_REQUEST_BY_SOCKET_PHASE_1_INCLUDED
#define   SMT_SOCKET_REQUEST_BY_SOCKET_PHASE 1
#include  "smt_socket_request_by_socket.hpp"
#undef    SMT_SOCKET_REQUEST_BY_SOCKET_PHASE
#endif
#ifndef   ICL_MEM_PHASE_1_INCLUDED
#define   ICL_MEM_PHASE 1
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif

#endif
#endif

#if !defined(SMT_SOCKET_REQUEST_PHASE) || SMT_SOCKET_REQUEST_PHASE==2
#ifndef SMT_SOCKET_REQUEST_PHASE_2_INCLUDED
#define SMT_SOCKET_REQUEST_PHASE_2_INCLUDED

template <> struct icl_info<smt_socket_request_t*>
{
    typedef smt_socket_request_t* c_type;
    typedef SmtSocketRequest cpp_type;
    typedef SmtSocketRequest& cpp_type_ref;
    typedef const SmtSocketRequest cpp_const_type;
    typedef const SmtSocketRequest cpp_const_type_ref;
    static inline cpp_type to_cpp_type (smt_socket_request_t *t);
    static inline c_type underlying (cpp_type_ref t);
};

#ifndef   IPR_BUCKET_PHASE_2_INCLUDED
#define   IPR_BUCKET_PHASE 2
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif
#ifndef   ICL_SHORTSTR_PHASE_2_INCLUDED
#define   ICL_SHORTSTR_PHASE 2
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   SMT_OS_THREAD_PHASE_2_INCLUDED
#define   SMT_OS_THREAD_PHASE 2
#include  "smt_os_thread.hpp"
#undef    SMT_OS_THREAD_PHASE
#endif
#ifndef   SMT_THREAD_PHASE_2_INCLUDED
#define   SMT_THREAD_PHASE 2
#include  "smt_thread.hpp"
#undef    SMT_THREAD_PHASE
#endif
#ifndef   SMT_SOCKET_PHASE_2_INCLUDED
#define   SMT_SOCKET_PHASE 2
#include  "smt_socket.hpp"
#undef    SMT_SOCKET_PHASE
#endif
#ifndef   SMT_TIMER_REQUEST_PHASE_2_INCLUDED
#define   SMT_TIMER_REQUEST_PHASE 2
#include  "smt_timer_request.hpp"
#undef    SMT_TIMER_REQUEST_PHASE
#endif
#ifndef   SMT_SOCKET_REQUEST_BY_THREAD_PHASE_2_INCLUDED
#define   SMT_SOCKET_REQUEST_BY_THREAD_PHASE 2
#include  "smt_socket_request_by_thread.hpp"
#undef    SMT_SOCKET_REQUEST_BY_THREAD_PHASE
#endif
#ifndef   SMT_SOCKET_REQUEST_BY_SOCKET_PHASE_2_INCLUDED
#define   SMT_SOCKET_REQUEST_BY_SOCKET_PHASE 2
#include  "smt_socket_request_by_socket.hpp"
#undef    SMT_SOCKET_REQUEST_BY_SOCKET_PHASE
#endif
#ifndef   ICL_MEM_PHASE_2_INCLUDED
#define   ICL_MEM_PHASE 2
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif

#endif
#endif

#if !defined(SMT_SOCKET_REQUEST_PHASE) || SMT_SOCKET_REQUEST_PHASE==3
#ifndef SMT_SOCKET_REQUEST_PHASE_3_INCLUDED
#define SMT_SOCKET_REQUEST_PHASE_3_INCLUDED

#ifndef   IPR_BUCKET_PHASE_3_INCLUDED
#define   IPR_BUCKET_PHASE 3
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif
#ifndef   ICL_SHORTSTR_PHASE_3_INCLUDED
#define   ICL_SHORTSTR_PHASE 3
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   SMT_OS_THREAD_PHASE_3_INCLUDED
#define   SMT_OS_THREAD_PHASE 3
#include  "smt_os_thread.hpp"
#undef    SMT_OS_THREAD_PHASE
#endif
#ifndef   SMT_THREAD_PHASE_3_INCLUDED
#define   SMT_THREAD_PHASE 3
#include  "smt_thread.hpp"
#undef    SMT_THREAD_PHASE
#endif
#ifndef   SMT_SOCKET_PHASE_3_INCLUDED
#define   SMT_SOCKET_PHASE 3
#include  "smt_socket.hpp"
#undef    SMT_SOCKET_PHASE
#endif
#ifndef   SMT_TIMER_REQUEST_PHASE_3_INCLUDED
#define   SMT_TIMER_REQUEST_PHASE 3
#include  "smt_timer_request.hpp"
#undef    SMT_TIMER_REQUEST_PHASE
#endif
#ifndef   SMT_SOCKET_REQUEST_BY_THREAD_PHASE_3_INCLUDED
#define   SMT_SOCKET_REQUEST_BY_THREAD_PHASE 3
#include  "smt_socket_request_by_thread.hpp"
#undef    SMT_SOCKET_REQUEST_BY_THREAD_PHASE
#endif
#ifndef   SMT_SOCKET_REQUEST_BY_SOCKET_PHASE_3_INCLUDED
#define   SMT_SOCKET_REQUEST_BY_SOCKET_PHASE 3
#include  "smt_socket_request_by_socket.hpp"
#undef    SMT_SOCKET_REQUEST_BY_SOCKET_PHASE
#endif
#ifndef   ICL_MEM_PHASE_3_INCLUDED
#define   ICL_MEM_PHASE 3
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif


class SmtSocketRequest
{
    friend struct icl_info <smt_socket_request_t*>;
public:

    inline
    SmtSocketRequest (smt_socket_request_t *raw)
    {
        p = new proxy_t;
        p->refcount = 1;
        p->p = raw;
    }

    SmtSocketRequest &operator = (smt_socket_request_t *raw)
    {
        if (!icl_atomic_dec32 (&(p->refcount))) {
            smt_socket_request_destroy (&(p->p));
            delete (p);
        }
        p = new proxy_t;
        p->refcount = 1;
        p->p = raw;
        return *this;
    }

    SmtSocketRequest (const SmtSocketRequest &val)
    {
        p = val.p;
        icl_atomic_inc32 (&(p->refcount));
    }

    SmtSocketRequest &operator = (const SmtSocketRequest &val)
    {
        if (!icl_atomic_dec32 (&(p->refcount))) {
            smt_socket_request_destroy (&(p->p));
            delete (p);
        }
        p = val.p;
        icl_atomic_inc32 (&(p->refcount));
        return *this;
    }

    inline
    ~SmtSocketRequest ()
    {
        if (!icl_atomic_dec32 (&(p->refcount))) {
            smt_socket_request_destroy (&(p->p));
            delete (p);
        }        
    }

    SmtSocketRequest (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_request_type_t>::cpp_type_ref type,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <smt_event_t>::cpp_type_ref input_event,
        icl_info <smt_event_t>::cpp_type_ref output_event);

    inline smt_socket_request_t *
    operator -> ()
    {
        return p->p;
    }

    inline
    operator smt_socket_request_t* () const
    {
        return p->p;
    }

    static void
    Initialise (
        void);

    void
    Timer (
        void);

    static icl_info <smt_socket_request_t *>::cpp_type
    Accept (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <smt_event_t>::cpp_type_ref event,
        icl_info <smt_socket_t **>::cpp_type_ref connect);

    void
    Return (
        icl_info <int>::cpp_type_ref result,
        icl_info <int>::cpp_type_ref error);

    static icl_info <smt_socket_request_t *>::cpp_type
    Monitor (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <smt_event_t>::cpp_type_ref input_event,
        icl_info <smt_event_t>::cpp_type_ref output_event);

    static icl_info <smt_socket_request_t *>::cpp_type
    Read (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <size_t>::cpp_type_ref min_size,
        icl_info <size_t>::cpp_type_ref max_size,
        icl_info <byte *>::cpp_type_ref buffer,
        icl_info <smt_event_t>::cpp_type_ref event);

    static icl_info <smt_socket_request_t *>::cpp_type
    ReadBucket (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <size_t>::cpp_type_ref min_size,
        icl_info <size_t>::cpp_type_ref max_size,
        icl_info <ipr_bucket_t **>::cpp_type_ref bucket_p,
        icl_info <smt_event_t>::cpp_type_ref event);

    static icl_info <smt_socket_request_t *>::cpp_type
    ReadMother (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <size_t>::cpp_type_ref size,
        icl_info <ipr_mother_t *>::cpp_type_ref mother,
        icl_info <ipr_bucket_t **>::cpp_type_ref slave_p,
        icl_info <smt_event_t>::cpp_type_ref event);

    static icl_info <smt_socket_request_t *>::cpp_type
    Write (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <size_t>::cpp_type_ref size,
        icl_info <byte *>::cpp_type_ref buffer,
        icl_info <smt_event_t>::cpp_type_ref event);

    static icl_info <smt_socket_request_t *>::cpp_type
    WriteBucket (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t *>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <ipr_bucket_t *>::cpp_type_ref bucket,
        icl_info <smt_event_t>::cpp_type_ref event);

    static icl_info <smt_socket_request_t *>::cpp_type
    Close (
        icl_info <smt_thread_t *>::cpp_type_ref thread,
        icl_info <smt_socket_t **>::cpp_type_ref socket,
        icl_info <qbyte>::cpp_type_ref msecs,
        icl_info <smt_event_t>::cpp_type_ref event);

    static icl_info <int>::cpp_type
    Poll (
        icl_info <smt_os_thread_t *>::cpp_type_ref os_thread,
        icl_info <Bool>::cpp_type_ref force);

    static icl_info <int>::cpp_type
    Wait (
        icl_info <smt_os_thread_t *>::cpp_type_ref os_thread);

    static void
    Trace (
        icl_info <Bool>::cpp_type_ref enabled);

    static void
    Selftest (
        void);

    icl_info <smt_socket_request_t *>::cpp_type
    WriteData (
        void);

    void
    RemoveFromAllContainers (
        void);

    static void
    Show (
        icl_info <void *>::cpp_type_ref item,
        icl_info <int>::cpp_type_ref opcode,
        icl_info <FILE *>::cpp_type_ref trace_file);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);

protected:
    struct proxy_t
    {
        qbyte refcount;
        smt_socket_request_t *p;
    };
    proxy_t *p;
private:
    SmtSocketRequest ();
};

inline icl_info<smt_socket_request_t*>::c_type
icl_info<smt_socket_request_t*>::underlying (
    icl_info<smt_socket_request_t*>::cpp_type_ref t)
{
    return t.p->p;
}



#endif
#endif
