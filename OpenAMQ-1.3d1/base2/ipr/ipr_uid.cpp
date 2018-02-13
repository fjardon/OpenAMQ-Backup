/*---------------------------------------------------------------------------
    ipr_uid.cpp - ipr_uid component wrapper implementation in C++

    Provides functions to access and maniuplate the current process
    user and group IDs.
    Generated from ipr_uid.icl by icl_gen using GSL/4.
    
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

#include "ipr_uid.hpp"


icl_info <int>::cpp_type
IprUid::UserName (
        icl_info <uid_t>::cpp_type_ref uid,
        icl_info <char *>::cpp_type_ref name)
{
    return ipr_uid_user_name (uid, name);
}

icl_info <int>::cpp_type
IprUid::GroupName (
        icl_info <uid_t>::cpp_type_ref gid,
        icl_info <char *>::cpp_type_ref name)
{
    return ipr_uid_group_name (gid, name);
}

icl_info <int>::cpp_type
IprUid::SetRealUser (
        void)
{
    return ipr_uid_set_real_user ();
}

icl_info <int>::cpp_type
IprUid::SetRootUser (
        void)
{
    return ipr_uid_set_root_user ();
}

icl_info <int>::cpp_type
IprUid::SetRealGroup (
        void)
{
    return ipr_uid_set_real_group ();
}

icl_info <int>::cpp_type
IprUid::SetRootGroup (
        void)
{
    return ipr_uid_set_root_group ();
}

icl_info <int>::cpp_type
IprUid::GetUid (
        void)
{
    return ipr_uid_get_uid ();
}

icl_info <int>::cpp_type
IprUid::GetGid (
        void)
{
    return ipr_uid_get_gid ();
}

icl_info <int>::cpp_type
IprUid::RunAs (
        icl_info <char *>::cpp_type_ref user,
        icl_info <char *>::cpp_type_ref group)
{
    return ipr_uid_run_as (user, group);
}

void
IprUid::Selftest (
        void)
{
    ipr_uid_selftest ();
}

void
IprUid::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    ipr_uid_animate (enabled);
}
