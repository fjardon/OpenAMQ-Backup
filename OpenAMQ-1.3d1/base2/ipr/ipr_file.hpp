/*---------------------------------------------------------------------------
    ipr_file.hpp - ipr_file component wrapper in C++

Provides a general set of file and filename manipulation functions.
The maximum length of a filename is set at 255 characters, to fit in
an icl_shortstr_t.  All filenames should be defined using this type.
    Generated from ipr_file.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_FILE_PHASE) || IPR_FILE_PHASE==1
#ifndef IPR_FILE_PHASE_1_INCLUDED
#define IPR_FILE_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_file.h"
#include "icl_info.hpp"


#ifndef   ICL_SHORTSTR_PHASE_1_INCLUDED
#define   ICL_SHORTSTR_PHASE 1
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_BUCKET_PHASE_1_INCLUDED
#define   IPR_BUCKET_PHASE 1
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif
#ifndef   IPR_STR_PHASE_1_INCLUDED
#define   IPR_STR_PHASE 1
#include  "ipr_str.hpp"
#undef    IPR_STR_PHASE
#endif

#endif
#endif

#if !defined(IPR_FILE_PHASE) || IPR_FILE_PHASE==2
#ifndef IPR_FILE_PHASE_2_INCLUDED
#define IPR_FILE_PHASE_2_INCLUDED


#ifndef   ICL_SHORTSTR_PHASE_2_INCLUDED
#define   ICL_SHORTSTR_PHASE 2
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_BUCKET_PHASE_2_INCLUDED
#define   IPR_BUCKET_PHASE 2
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif
#ifndef   IPR_STR_PHASE_2_INCLUDED
#define   IPR_STR_PHASE 2
#include  "ipr_str.hpp"
#undef    IPR_STR_PHASE
#endif

#endif
#endif

#if !defined(IPR_FILE_PHASE) || IPR_FILE_PHASE==3
#ifndef IPR_FILE_PHASE_3_INCLUDED
#define IPR_FILE_PHASE_3_INCLUDED

#ifndef   ICL_SHORTSTR_PHASE_3_INCLUDED
#define   ICL_SHORTSTR_PHASE 3
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_BUCKET_PHASE_3_INCLUDED
#define   IPR_BUCKET_PHASE 3
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif
#ifndef   IPR_STR_PHASE_3_INCLUDED
#define   IPR_STR_PHASE 3
#include  "ipr_str.hpp"
#undef    IPR_STR_PHASE
#endif


class IprFile
{
public:

    static icl_info <Bool>::cpp_type
    Exists (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <int64_t>::cpp_type
    Size (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <time_t>::cpp_type
    Time (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <size_t>::cpp_type
    Lines (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <ipr_bucket_t *>::cpp_type
    Slurp (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <int>::cpp_type
    Where (
        icl_info <char *>::cpp_type_ref filename,
        icl_info <char *>::cpp_type_ref path,
        icl_info <char *>::cpp_type_ref fullname);

    static icl_info <int>::cpp_type
    Delete (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <int>::cpp_type
    Rename (
        icl_info <char *>::cpp_type_ref newname,
        icl_info <char *>::cpp_type_ref oldname);

    static void
    Truncate (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <char *>::cpp_type
    StripPath (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <char *>::cpp_type
    SetPath (
        icl_info <char *>::cpp_type_ref filename,
        icl_info <char *>::cpp_type_ref path);

    static icl_info <char *>::cpp_type
    SetExtension (
        icl_info <char *>::cpp_type_ref filename,
        icl_info <char *>::cpp_type_ref extension);

    static icl_info <char *>::cpp_type
    Move (
        icl_info <char *>::cpp_type_ref directory,
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <Bool>::cpp_type
    IsDirectory (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <char *>::cpp_type
    Digest (
        icl_info <char *>::cpp_type_ref filename);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprFile ();
    IprFile (const IprFile&);
    IprFile &operator = (const IprFile&);
};



#endif
#endif
