/*---------------------------------------------------------------------------
    icl_mem_lockfree.cpp - icl_mem_lockfree component wrapper implementation in C++

    A lightweight memory allocator using lock-free freelists.
    Generated from icl_mem_lockfree.icl by icl_gen using GSL/4.
    
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

#include "icl_mem_lockfree.hpp"


IclMemLockfree::IclMemLockfree (
        icl_info <size_t>::cpp_type_ref size)
{
    p = icl_mem_lockfree_new (size);
}

icl_info <void *>::cpp_type
IclMemLockfree::CacheAlloc (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    return icl_mem_lockfree_cache_alloc (cache);
}

icl_info <void *>::cpp_type
IclMemLockfree::Alloc (
        icl_info <size_t>::cpp_type_ref size)
{
    return icl_mem_lockfree_alloc (size);
}

icl_info <void *>::cpp_type
IclMemLockfree::Realloc (
        icl_info <void *>::cpp_type_ref item,
        icl_info <qbyte>::cpp_type_ref size)
{
    return icl_mem_lockfree_realloc (item, size);
}

void
IclMemLockfree::Free (
        icl_info <void *>::cpp_type_ref item)
{
    icl_mem_lockfree_free (item);
}

icl_info <icl_mem_lockfree_list_t *>::cpp_type
IclMemLockfree::ListNew (
        void)
{
    return icl_mem_lockfree_list_new ();
}

void
IclMemLockfree::ListDestroy (
        void)
{
    icl_mem_lockfree_list_destroy (this->p);
}

void
IclMemLockfree::CacheInsert (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    icl_mem_lockfree_cache_insert (cache, this->p);
}

icl_info <void *>::cpp_type
IclMemLockfree::CacheReuse (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    return icl_mem_lockfree_cache_reuse (cache);
}

void
IclMemLockfree::CacheRecycle (
        void)
{
    icl_mem_lockfree_cache_recycle (this->p);
}

void
IclMemLockfree::CachePurge (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    icl_mem_lockfree_cache_purge (cache);
}

void
IclMemLockfree::CacheReset (
        void)
{
    icl_mem_lockfree_cache_reset (this->p);
}

icl_info <int>::cpp_type
IclMemLockfree::CacheAssert (
        icl_info <icl_cache_t *>::cpp_type_ref cache,
        icl_info <FILE **>::cpp_type_ref trace_file)
{
    return icl_mem_lockfree_cache_assert (cache, trace_file);
}

void
IclMemLockfree::Show (
        void)
{
    icl_mem_lockfree_show ();
}

void
IclMemLockfree::SetCallback (
        icl_info <void *>::cpp_type_ref item,
        icl_info <icl_callback_fn *>::cpp_type_ref callback)
{
    icl_mem_lockfree_set_callback (item, callback);
}

void
IclMemLockfree::Selftest (
        void)
{
    icl_mem_lockfree_selftest ();
}

icl_info <void *>::cpp_type
IclMemLockfree::CachePop (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    return icl_mem_lockfree_cache_pop (cache);
}

icl_info <void *>::cpp_type
IclMemLockfree::CacheNew (
        icl_info <icl_cache_t *>::cpp_type_ref cache)
{
    return icl_mem_lockfree_cache_new (cache);
}

void
IclMemLockfree::Animate (
        icl_info <Bool>::cpp_type_ref enabled)
{
    icl_mem_lockfree_animate (enabled);
}
