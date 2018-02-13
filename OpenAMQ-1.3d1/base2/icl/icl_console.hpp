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
