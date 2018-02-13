/*---------------------------------------------------------------------------
    icl_apr.hpp - icl_apr component wrapper in C++

    Provides iCL wrappers for some APR functions.
    Generated from icl_apr.icl by icl_gen using GSL/4.
    
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

#if !defined(ICL_APR_PHASE) || ICL_APR_PHASE==1
#ifndef ICL_APR_PHASE_1_INCLUDED
#define ICL_APR_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "icl_apr.h"
#include "icl_info.hpp"



#endif
#endif

#if !defined(ICL_APR_PHASE) || ICL_APR_PHASE==2
#ifndef ICL_APR_PHASE_2_INCLUDED
#define ICL_APR_PHASE_2_INCLUDED



#endif
#endif

#if !defined(ICL_APR_PHASE) || ICL_APR_PHASE==3
#ifndef ICL_APR_PHASE_3_INCLUDED
#define ICL_APR_PHASE_3_INCLUDED



class IclApr
{
public:

    static void
    AprAssert (
        icl_info <apr_status_t>::cpp_type_ref status);

    static void
    AprErrorPrint (
        icl_info <apr_status_t>::cpp_type_ref status);

    static icl_info <qbyte>::cpp_type
    AtomicInc32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem);

    static icl_info <Bool>::cpp_type
    AtomicDec32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem);

    static icl_info <qbyte>::cpp_type
    AtomicGet32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem);

    static void
    AtomicSet32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref val);

    static icl_info <qbyte>::cpp_type
    AtomicAdd32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref add_val);

    static void
    AtomicSub32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref val);

    static icl_info <qbyte>::cpp_type
    AtomicCas32 (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref new_val,
        icl_info <qbyte>::cpp_type_ref cmp_val);

    static icl_info <volatile void *>::cpp_type
    AtomicCasptr (
        icl_info <volatile void **>::cpp_type_ref mem,
        icl_info <void *>::cpp_type_ref new_val,
        icl_info <void *>::cpp_type_ref cmp_val);

    static icl_info <qbyte>::cpp_type
    AtomicSwap (
        icl_info <volatile qbyte *>::cpp_type_ref mem,
        icl_info <qbyte>::cpp_type_ref new_val);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IclApr ();
    IclApr (const IclApr&);
    IclApr &operator = (const IclApr&);
};



#endif
#endif
/*---------------------------------------------------------------------------
    icl_mutex.hpp - icl_mutex component wrapper in C++

    Defines wrappers to manage mutex objects.
    Generated from icl_mutex.icl by icl_gen using GSL/4.
    
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
    icl_cond.hpp - icl_cond component wrapper in C++

    Defines wrappers to manage condition variable objects.
    Generated from icl_cond.icl by icl_gen using GSL/4.
    
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
    icl_rwlock.hpp - icl_rwlock component wrapper in C++

    Defines wrappers to managed read-write lock objects.
    Generated from icl_rwlock.icl by icl_gen using GSL/4.
    
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
    icl_console.hpp - icl_console component wrapper in C++

    Defines the console interface for iCL.
    Generated from icl_console.icl by icl_gen using GSL/4.
    
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

#if !defined(ICL_CONSOLE_PHASE) || ICL_CONSOLE_PHASE==1
#ifndef ICL_CONSOLE_PHASE_1_INCLUDED
#define ICL_CONSOLE_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "icl_console.h"
#include "icl_info.hpp"



#endif
#endif

#if !defined(ICL_CONSOLE_PHASE) || ICL_CONSOLE_PHASE==2
#ifndef ICL_CONSOLE_PHASE_2_INCLUDED
#define ICL_CONSOLE_PHASE_2_INCLUDED



#endif
#endif

#if !defined(ICL_CONSOLE_PHASE) || ICL_CONSOLE_PHASE==3
#ifndef ICL_CONSOLE_PHASE_3_INCLUDED
#define ICL_CONSOLE_PHASE_3_INCLUDED



class IclConsole
{
public:

    static void
    Mode (
        icl_info <icl_console_option_t>::cpp_type_ref attr,
        icl_info <Bool>::cpp_type_ref value);

    static void
    Redirect (
        icl_info <FILE *>::cpp_type_ref file);

    static void
    Print (
        icl_info <char *>::cpp_type_ref format,
        ...);

    static void
    PrintV (
        icl_info <char *>::cpp_type_ref format,
        va_list argptr);

    static void
    Out (
        icl_info <char *>::cpp_type_ref format,
        ...);

    static void
    OutV (
        icl_info <char *>::cpp_type_ref format,
        va_list argptr);

    static void
    PrintThreadTime (
        icl_info <icl_os_thread_t>::cpp_type_ref os_thread,
        icl_info <apr_time_t>::cpp_type_ref time,
        icl_info <char *>::cpp_type_ref format,
        ...);

    static void
    PrintThreadTimeV (
        icl_info <icl_os_thread_t>::cpp_type_ref os_thread,
        icl_info <apr_time_t>::cpp_type_ref time,
        icl_info <char *>::cpp_type_ref format,
        va_list argptr);

    static void
    Selftest (
        void);
private:
    IclConsole ();
    IclConsole (const IclConsole&);
    IclConsole &operator = (const IclConsole&);
};



#endif
#endif
/*---------------------------------------------------------------------------
    icl_stats.hpp - icl_stats component wrapper in C++

    Provides statistical reporting for other classes.
    
    Statistics are held in a shared memory block so they can easily be
    examined from another process, even if the running process is blocked.
    Generated from icl_stats.icl by icl_gen using GSL/4.
    
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
    icl_trace.hpp - icl_trace component wrapper in C++

    Class to enable trace of program behaviour.
    To trace any program operation, call the trace method during operation.
    The trace is replayed via the dump method.
    Generated from icl_trace.icl by icl_gen using GSL/4.
    
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
    icl_mem.hpp - icl_mem component wrapper in C++

    Provides API for memory allocator.  Methods are implemented in icl_mem_fat
    and icl_mem_thin.
    Generated from icl_mem.icl by icl_gen using GSL/4.
    
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
    icl_system.hpp - icl_system component wrapper in C++

    Implements the metacache manager.  Provides two functions for
    application developers: icl_system_purge(), which does garbage
    collection, and icl_system_terminate(), which does final destruction
    of all active and cached objects. Provides one function for iCL
    developers: icl_system_register(), which registers a class for
    purging and destroying.

    Also responsible for system-wide initialisation, comprising
    icl_global_pool and icl_global_mutex.  Note that to avoid circular
    dependencies, these two are declared in icl_apr.
    Generated from icl_system.icl by icl_gen using GSL/4.
    
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
    icl_shortstr.hpp - icl_shortstr component wrapper in C++

    We define the icl_shortstr_t type in order to provide a simple way of
    storing and serialising short strings.  A "short string" is defined
    as one that can be serialised as a single-octet length indicator
    plus 0-255 octets of data.  The icl_shortstr_t type is held in memory
    as C-compatible null-terminated char arrays of 255+1 bytes.  There
    are no constructor/destructor methods for icl_shortstr_t variables since
    this would create incompatabilities with normal C strings.  See the
    selftest method for examples of using icl_shortstr_t.  When writing a
    icl_shortstr_t you should always use the icl_shortstr_cpy method to
    avoid the risk of overflows.
    Generated from icl_shortstr.icl by icl_gen using GSL/4.
    
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

#if !defined(ICL_SHORTSTR_PHASE) || ICL_SHORTSTR_PHASE==1
#ifndef ICL_SHORTSTR_PHASE_1_INCLUDED
#define ICL_SHORTSTR_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "icl_shortstr.h"
#include "icl_info.hpp"



#endif
#endif

#if !defined(ICL_SHORTSTR_PHASE) || ICL_SHORTSTR_PHASE==2
#ifndef ICL_SHORTSTR_PHASE_2_INCLUDED
#define ICL_SHORTSTR_PHASE_2_INCLUDED



#endif
#endif

#if !defined(ICL_SHORTSTR_PHASE) || ICL_SHORTSTR_PHASE==3
#ifndef ICL_SHORTSTR_PHASE_3_INCLUDED
#define ICL_SHORTSTR_PHASE_3_INCLUDED



class IclShortstr
{
public:

    static icl_info <size_t>::cpp_type
    Cpy (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src);

    static icl_info <size_t>::cpp_type
    Cat (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src);

    static icl_info <size_t>::cpp_type
    Ncpy (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src,
        icl_info <size_t>::cpp_type_ref size);

    static icl_info <size_t>::cpp_type
    Ncat (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref src,
        icl_info <size_t>::cpp_type_ref size);

    static icl_info <char *>::cpp_type
    Fmt (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref format,
        ...);

    static icl_info <char *>::cpp_type
    FmtV (
        icl_info <char *>::cpp_type_ref dest,
        icl_info <char *>::cpp_type_ref format,
        va_list args);

    static icl_info <size_t>::cpp_type
    Read (
        icl_info <char *>::cpp_type_ref string,
        icl_info <FILE *>::cpp_type_ref file);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IclShortstr ();
    IclShortstr (const IclShortstr&);
    IclShortstr &operator = (const IclShortstr&);
};



#endif
#endif
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
