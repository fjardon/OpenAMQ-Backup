/*---------------------------------------------------------------------------
    ipr_file.cpp - ipr_file component wrapper implementation in C++

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

#include "ipr_file.hpp"


icl_info <Bool>::cpp_type
IprFile::Exists (
        icl_info <char *>::cpp_type_ref filename)
{
    return ipr_file_exists (filename);
}

icl_info <int64_t>::cpp_type
IprFile::Size (
        icl_info <char *>::cpp_type_ref filename)
{
    return ipr_file_size (filename);
}

icl_info <time_t>::cpp_type
IprFile::Time (
        icl_info <char *>::cpp_type_ref filename)
{
    return ipr_file_time (filename);
}

icl_info <size_t>::cpp_type
IprFile::Lines (
        icl_info <char *>::cpp_type_ref filename)
{
    return ipr_file_lines (filename);
}

icl_info <ipr_bucket_t *>::cpp_type
IprFile::Slurp (
        icl_info <char *>::cpp_type_ref filename)
{
    return ipr_file_slurp (filename);
}

icl_info <int>::cpp_type
IprFile::Where (
        icl_info <char *>::cpp_type_ref filename,
        icl_info <char *>::cpp_type_ref path,
        icl_info <char *>::cpp_type_ref fullname)
{
    return ipr_file_where (filename, path, fullname);
}

icl_info <int>::cpp_type
IprFile::Delete (
        icl_info <char *>::cpp_type_ref filename)
{
    return ipr_file_delete (filename);
}

icl_info <int>::cpp_type
IprFile::Rename (
        icl_info <char *>::cpp_type_ref newname,
        icl_info <char *>::cpp_type_ref oldname)
{
    return ipr_file_rename (newname, oldname);
}

void
IprFile::Truncate (
        icl_info <char *>::cpp_type_ref filename)
{
    ipr_file_truncate (filename);
}

icl_info <char *>::cpp_type
IprFile::StripPath (
        icl_info <char *>::cpp_type_ref filename)
{
    return ipr_file_strip_path (filename);
}

icl_info <char *>::cpp_type
IprFile::SetPath (
        icl_info <char *>::cpp_type_ref filename,
        icl_info <char *>::cpp_type_ref path)
{
    return ipr_file_set_path (filename, path);
}

icl_info <char *>::cpp_type
IprFile::SetExtension (
        icl_info <char *>::cpp_type_ref filename,
        icl_info <char *>::cpp_type_ref extension)
{
    return ipr_file_set_extension (filename, extension);
}

icl_info <char *>::cpp_type
IprFile::Move (
        icl_info <char *>::cpp_type_ref directory,
        icl_info <char *>::cpp_type_ref filename)
{
    return ipr_file_move (directory, filename);
}

icl_info <Bool>::cpp_type
IprFile::IsDirectory (
        icl_info <char *>::cpp_type_ref filename)
{
    return ipr_file_is_directory (filename);
}

icl_info <char *>::cpp_type
IprFile::Digest (
        icl_info <char *>::cpp_type_ref filename)
{
    return ipr_file_digest (filename);
}

void
IprFile::Selftest (
        void)
{
    ipr_file_selftest ();
}

void
IprFile::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    ipr_file_animate (enabled);
}
