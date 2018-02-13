/*---------------------------------------------------------------------------
    icl_longstr.hpp - icl_longstr component wrapper in C++

    We define the icl_longstr_t type in order to provide a secure way of
    storing and serialising long strings.  A "long string" is defined
    as one that can be serialised as a 32-bit length indicator
    plus 0-4Gb-1 octets of data. The icl_longstr_t type is held in memory
    as descriptor consisting of a size field and a data reference.
    Generated from icl_longstr.icl by icl_gen using GSL/4.
    
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

#if !defined(ICL_LONGSTR_PHASE) || ICL_LONGSTR_PHASE==1
#ifndef ICL_LONGSTR_PHASE_1_INCLUDED
#define ICL_LONGSTR_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "icl_longstr.h"
#include "icl_info.hpp"

class IclLongstr;
template <> struct icl_info <icl_longstr_t*>;

#ifndef   ICL_MEM_PHASE_1_INCLUDED
#define   ICL_MEM_PHASE 1
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif

#endif
#endif

#if !defined(ICL_LONGSTR_PHASE) || ICL_LONGSTR_PHASE==2
#ifndef ICL_LONGSTR_PHASE_2_INCLUDED
#define ICL_LONGSTR_PHASE_2_INCLUDED

template <> struct icl_info<icl_longstr_t*>
{
    typedef icl_longstr_t* c_type;
    typedef IclLongstr cpp_type;
    typedef IclLongstr& cpp_type_ref;
    typedef const IclLongstr cpp_const_type;
    typedef const IclLongstr cpp_const_type_ref;
    static inline cpp_type to_cpp_type (icl_longstr_t *t);
    static inline c_type underlying (cpp_type_ref t);
};

#ifndef   ICL_MEM_PHASE_2_INCLUDED
#define   ICL_MEM_PHASE 2
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif

#endif
#endif

#if !defined(ICL_LONGSTR_PHASE) || ICL_LONGSTR_PHASE==3
#ifndef ICL_LONGSTR_PHASE_3_INCLUDED
#define ICL_LONGSTR_PHASE_3_INCLUDED

#ifndef   ICL_MEM_PHASE_3_INCLUDED
#define   ICL_MEM_PHASE 3
#include  "icl_mem.hpp"
#undef    ICL_MEM_PHASE
#endif


class IclLongstr
{
    friend struct icl_info <icl_longstr_t*>;
public:

    inline
    IclLongstr (icl_longstr_t *raw)
    {
        p = raw;
    }

    IclLongstr &operator = (icl_longstr_t *raw)
    {
        icl_longstr_destroy (&p);
        p = raw;
        return *this;
    }

    IclLongstr (const IclLongstr &val)
    {
        p = icl_longstr_dup (val.p);
    }

    IclLongstr &operator = (const IclLongstr &val)
    {
        icl_longstr_destroy (&p);
        p = icl_longstr_dup (val.p);
        return *this;
    }

    inline
    ~IclLongstr ()
    {
        icl_longstr_destroy (&p);
    }

    IclLongstr (
        icl_info <void *>::cpp_type_ref data,
        icl_info <size_t>::cpp_type_ref size);

    inline icl_longstr_t *
    operator -> ()
    {
        return p;
    }

    inline
    operator icl_longstr_t* () const
    {
        return p;
    }

    icl_info <int>::cpp_type
    Resize (
        icl_info <size_t>::cpp_type_ref size);

    icl_info <int>::cpp_type
    Eq (
        icl_info <icl_longstr_t *>::cpp_type_ref second);

    icl_info <int>::cpp_type
    Fmt (
        icl_info <char *>::cpp_type_ref format,
        ...);

    icl_info <int>::cpp_type
    FmtV (
        icl_info <char *>::cpp_type_ref format,
        va_list args);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);

protected:
    icl_longstr_t *p;
private:
    IclLongstr ();
};

inline icl_info<icl_longstr_t*>::c_type
icl_info<icl_longstr_t*>::underlying (
    icl_info<icl_longstr_t*>::cpp_type_ref t)
{
    return t.p;
}



#endif
#endif
