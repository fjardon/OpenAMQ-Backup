/*---------------------------------------------------------------------------
    icl_mem_fat.hpp - icl_mem_fat component wrapper in C++

    A memory allocator using fully linked lists and providing debug features.
    Generated from icl_mem_fat.icl by icl_gen using GSL/4.
    
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

#if !defined(ICL_MEM_FAT_PHASE) || ICL_MEM_FAT_PHASE==1
#ifndef ICL_MEM_FAT_PHASE_1_INCLUDED
#define ICL_MEM_FAT_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "icl_mem_fat.h"
#include "icl_info.hpp"

class IclMemFat;
template <> struct icl_info <icl_mem_fat_t*>;

#ifndef   ICL_CACHE_PHASE_1_INCLUDED
#define   ICL_CACHE_PHASE 1
#include  "icl_cache.hpp"
#undef    ICL_CACHE_PHASE
#endif
#ifndef   ICL_MEM_FAT_LIST_PHASE_1_INCLUDED
#define   ICL_MEM_FAT_LIST_PHASE 1
#include  "icl_mem_fat_list.hpp"
#undef    ICL_MEM_FAT_LIST_PHASE
#endif
#ifndef   ICL_SYSTEM_PHASE_1_INCLUDED
#define   ICL_SYSTEM_PHASE 1
#include  "icl_system.hpp"
#undef    ICL_SYSTEM_PHASE
#endif
#ifndef   ICL_STATS_PHASE_1_INCLUDED
#define   ICL_STATS_PHASE 1
#include  "icl_stats.hpp"
#undef    ICL_STATS_PHASE
#endif

#endif
#endif

#if !defined(ICL_MEM_FAT_PHASE) || ICL_MEM_FAT_PHASE==2
#ifndef ICL_MEM_FAT_PHASE_2_INCLUDED
#define ICL_MEM_FAT_PHASE_2_INCLUDED

template <> struct icl_info<icl_mem_fat_t*>
{
    typedef icl_mem_fat_t* c_type;
    typedef IclMemFat cpp_type;
    typedef IclMemFat& cpp_type_ref;
    typedef const IclMemFat cpp_const_type;
    typedef const IclMemFat cpp_const_type_ref;
    static inline cpp_type to_cpp_type (icl_mem_fat_t *t);
    static inline c_type underlying (cpp_type_ref t);
};

#ifndef   ICL_CACHE_PHASE_2_INCLUDED
#define   ICL_CACHE_PHASE 2
#include  "icl_cache.hpp"
#undef    ICL_CACHE_PHASE
#endif
#ifndef   ICL_MEM_FAT_LIST_PHASE_2_INCLUDED
#define   ICL_MEM_FAT_LIST_PHASE 2
#include  "icl_mem_fat_list.hpp"
#undef    ICL_MEM_FAT_LIST_PHASE
#endif
#ifndef   ICL_SYSTEM_PHASE_2_INCLUDED
#define   ICL_SYSTEM_PHASE 2
#include  "icl_system.hpp"
#undef    ICL_SYSTEM_PHASE
#endif
#ifndef   ICL_STATS_PHASE_2_INCLUDED
#define   ICL_STATS_PHASE 2
#include  "icl_stats.hpp"
#undef    ICL_STATS_PHASE
#endif

#endif
#endif

#if !defined(ICL_MEM_FAT_PHASE) || ICL_MEM_FAT_PHASE==3
#ifndef ICL_MEM_FAT_PHASE_3_INCLUDED
#define ICL_MEM_FAT_PHASE_3_INCLUDED

#ifndef   ICL_CACHE_PHASE_3_INCLUDED
#define   ICL_CACHE_PHASE 3
#include  "icl_cache.hpp"
#undef    ICL_CACHE_PHASE
#endif
#ifndef   ICL_MEM_FAT_LIST_PHASE_3_INCLUDED
#define   ICL_MEM_FAT_LIST_PHASE 3
#include  "icl_mem_fat_list.hpp"
#undef    ICL_MEM_FAT_LIST_PHASE
#endif
#ifndef   ICL_SYSTEM_PHASE_3_INCLUDED
#define   ICL_SYSTEM_PHASE 3
#include  "icl_system.hpp"
#undef    ICL_SYSTEM_PHASE
#endif
#ifndef   ICL_STATS_PHASE_3_INCLUDED
#define   ICL_STATS_PHASE 3
#include  "icl_stats.hpp"
#undef    ICL_STATS_PHASE
#endif


class IclMemFat
{
    friend struct icl_info <icl_mem_fat_t*>;
public:

    inline
    IclMemFat (icl_mem_fat_t *raw)
    {
        p = raw;
    }

    IclMemFat &operator = (icl_mem_fat_t *raw)
    {
        icl_mem_fat_destroy (&p);
        p = raw;
        return *this;
    }

    IclMemFat (const IclMemFat &val)
    {
        p = val.p;
        icl_mem_fat_possess (p);
    }

    IclMemFat &operator = (const IclMemFat &val)
    {
        icl_mem_fat_destroy (&p);
        p = val.p;
        icl_mem_fat_possess (p);
        return *this;
    }

    inline
    ~IclMemFat ()
    {
        icl_mem_fat_destroy (&p);
    }

    IclMemFat (
        icl_info <size_t>::cpp_type_ref size);

    inline icl_mem_fat_t *
    operator -> ()
    {
        return p;
    }

    inline
    operator icl_mem_fat_t* () const
    {
        return p;
    }

    static icl_info <void *>::cpp_type
    CacheReuse (
        icl_info <icl_cache_t *>::cpp_type_ref cache);

    static void
    CachePurge (
        icl_info <icl_cache_t *>::cpp_type_ref cache);

    static icl_info <int>::cpp_type
    CacheAssert (
        icl_info <icl_cache_t *>::cpp_type_ref cache,
        icl_info <FILE **>::cpp_type_ref trace_file);

    static void
    SetCallback (
        icl_info <void *>::cpp_type_ref item,
        icl_info <icl_callback_fn *>::cpp_type_ref callback);

    static void
    Selftest (
        void);

    void
    RemoveFromAllContainers (
        void);

    static icl_info <void *>::cpp_type
    CacheAlloc (
        icl_info <icl_cache_t *>::cpp_type_ref cache);

    static icl_info <void *>::cpp_type
    CachePop (
        icl_info <icl_cache_t *>::cpp_type_ref cache);

    static icl_info <void *>::cpp_type
    CacheNew (
        icl_info <icl_cache_t *>::cpp_type_ref cache);

    static icl_info <void *>::cpp_type
    Alloc (
        icl_info <size_t>::cpp_type_ref size);

    static icl_info <void *>::cpp_type
    Realloc (
        icl_info <void *>::cpp_type_ref item,
        icl_info <qbyte>::cpp_type_ref size);

    static void
    Free (
        icl_info <void *>::cpp_type_ref item);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);

protected:
    icl_mem_fat_t *p;
private:
    IclMemFat ();
};

inline icl_info<icl_mem_fat_t*>::c_type
icl_info<icl_mem_fat_t*>::underlying (
    icl_info<icl_mem_fat_t*>::cpp_type_ref t)
{
    return t.p;
}



#endif
#endif
