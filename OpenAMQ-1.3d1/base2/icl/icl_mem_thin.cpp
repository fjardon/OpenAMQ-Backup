/*---------------------------------------------------------------------------
    icl_mem_thin.cpp - icl_mem_thin component wrapper implementation in C++

    A lightwieght memory allocator using a lock-free singly-linked stack.
    Generated from icl_mem_thin.icl by icl_gen using GSL/4.
    
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

#include "icl_mem_thin.hpp"


IclMemThin::IclMemThin (
        icl_info <size_t>::cpp_type_ref size)
{
    p = icl_mem_thin_new (size);
}

icl_info <void *>::cpp_type
IclMemThin::CacheAlloc (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    return icl_mem_thin_cache_alloc (cache);
}

icl_info <void *>::cpp_type
IclMemThin::Alloc (
        icl_info <size_t>::cpp_type_ref size)
{
    return icl_mem_thin_alloc (size);
}

icl_info <void *>::cpp_type
IclMemThin::Realloc (
        icl_info <void *>::cpp_type_ref item,
        icl_info <qbyte>::cpp_type_ref size)
{
    return icl_mem_thin_realloc (item, size);
}

void
IclMemThin::Free (
        icl_info <void *>::cpp_type_ref item)
{
    icl_mem_thin_free (item);
}

void
IclMemThin::CacheInsert (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    icl_mem_thin_cache_insert (cache, this->p);
}

icl_info <void *>::cpp_type
IclMemThin::CacheReuse (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    return icl_mem_thin_cache_reuse (cache);
}

void
IclMemThin::CacheRecycle (
        void)
{
    icl_mem_thin_cache_recycle (this->p);
}

void
IclMemThin::CachePurge (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    icl_mem_thin_cache_purge (cache);
}

void
IclMemThin::CacheReset (
        void)
{
    icl_mem_thin_cache_reset (this->p);
}

icl_info <int>::cpp_type
IclMemThin::CacheAssert (
        icl_info <icl_cache_t *>::cpp_type_ref cache,
        icl_info <FILE **>::cpp_type_ref trace_file)
{
    return icl_mem_thin_cache_assert (cache, trace_file);
}

void
IclMemThin::Show (
        void)
{
    icl_mem_thin_show ();
}

void
IclMemThin::SetCallback (
        icl_info <void *>::cpp_type_ref item,
        icl_info <icl_callback_fn *>::cpp_type_ref callback)
{
    icl_mem_thin_set_callback (item, callback);
}

void
IclMemThin::Selftest (
        void)
{
    icl_mem_thin_selftest ();
}

void
IclMemThin::RemoveFromAllContainers (
        void)
{
    icl_mem_thin_remove_from_all_containers (this->p);
}

icl_info <void *>::cpp_type
IclMemThin::CachePop (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    return icl_mem_thin_cache_pop (cache);
}

icl_info <void *>::cpp_type
IclMemThin::CacheNew (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    return icl_mem_thin_cache_new (cache);
}

void
IclMemThin::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    icl_mem_thin_animate (enabled);
}
