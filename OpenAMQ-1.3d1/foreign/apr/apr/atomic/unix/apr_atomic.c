/* Copyright 2000-2005 The Apache Software Foundation or its licensors, as
 * applicable.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "apr.h"
#include "apr_atomic.h"
#include "apr_thread_mutex.h"

#include "apr_private.h"

#include <stdlib.h>

#if defined(USE_SOLARIS_ATOMICS) && !defined (USE_GENERIC_ATOMICS)
#include <atomic.h>
#endif /* USE_SOLARIS_ATOMICS */

#if (defined(__i386__) || defined(__x86_64__)) \
    && defined(__GNUC__) && !defined(USE_GENERIC_ATOMICS) \
    && !defined(USE_SOLARIS_ATOMICS)

APR_DECLARE(apr_uint32_t) apr_atomic_cas32(volatile apr_uint32_t *mem, 
                                           apr_uint32_t with,
                                           apr_uint32_t cmp)
{
    apr_uint32_t prev;

    __asm__ volatile ("lock; cmpxchgl %1, %2"             
                      : "=a" (prev)               
                      : "r" (with), "m" (*(mem)), "0"(cmp) 
                      : "memory", "cc");
    return prev;
}
#define APR_OVERRIDE_ATOMIC_CAS32

static apr_uint32_t inline intel_atomic_add32(volatile apr_uint32_t *mem, 
                                              apr_uint32_t val)
{
    __asm__ volatile ("lock; xaddl %0,%1"
                      : "=r"(val), "=m"(*mem) /* outputs */
                      : "0"(val), "m"(*mem)   /* inputs */
                      : "memory", "cc");
    return val;
}

APR_DECLARE(apr_uint32_t) apr_atomic_add32(volatile apr_uint32_t *mem, 
                                           apr_uint32_t val)
{
    return intel_atomic_add32(mem, val);
}
#define APR_OVERRIDE_ATOMIC_ADD32

APR_DECLARE(void) apr_atomic_sub32(volatile apr_uint32_t *mem, apr_uint32_t val)
{
    __asm__ volatile ("lock; subl %1, %0"
                      :
                      : "m" (*(mem)), "r" (val)
                      : "memory", "cc");
}
#define APR_OVERRIDE_ATOMIC_SUB32

APR_DECLARE(int) apr_atomic_dec32(volatile apr_uint32_t *mem)
{
    unsigned char prev;

    __asm__ volatile ("lock; decl %1;\n\t"
                      "setnz %%al"
                      : "=a" (prev)
                      : "m" (*(mem))
                      : "memory", "cc");
    return prev;
}
#define APR_OVERRIDE_ATOMIC_DEC32

APR_DECLARE(apr_uint32_t) apr_atomic_inc32(volatile apr_uint32_t *mem)
{
    return intel_atomic_add32(mem, 1);
}
#define APR_OVERRIDE_ATOMIC_INC32

APR_DECLARE(void) apr_atomic_set32(volatile apr_uint32_t *mem, apr_uint32_t val)
{
    *mem = val;
}
#define APR_OVERRIDE_ATOMIC_SET32

APR_DECLARE(apr_uint32_t) apr_atomic_xchg32(volatile apr_uint32_t *mem, apr_uint32_t val)
{
    apr_uint32_t prev = val;

    __asm__ volatile ("lock; xchgl %0, %1"
                      : "=r" (prev)
                      : "m" (*(mem)), "0"(prev)
                      : "memory");
    return prev;
}
#define APR_OVERRIDE_ATOMIC_XCHG32

/*#define apr_atomic_init(pool)        APR_SUCCESS*/

#endif /* (__i386__ || __x86_64__ ) && __GNUC__ && !USE_SOLARIS_ATOMICS */

#if defined(__i386__) && defined(__GNUC__) && !defined(USE_GENERIC_ATOMICS) \
    && !defined(USE_SOLARIS_ATOMICS)

void *apr_atomic_casptr(volatile void **mem, void *with, const void *cmp)
{
    return (void *)apr_atomic_cas32 ((volatile apr_uint32_t *) mem, 
                                     (apr_uint32_t) with,
                                     (const apr_uint32_t) cmp);
}
#define APR_OVERRIDE_ATOMIC_CASPTR

#endif /* __i386__ && __GNUC__ && !USE_SOLARIS_ATOMICS */

#if defined(__x86_64__) && defined(__GNUC__) && !defined(USE_GENERIC_ATOMICS) \
    && !defined(USE_SOLARIS_ATOMICS)

void *apr_atomic_casptr(volatile void **mem, void *with, const void *cmp) 
{
    void *prev;

    __asm__ volatile ("lock; cmpxchgq %1, %2"             
                      : "=a" (prev)               
                      : "r" (with), "m" (*(mem)), "0"(cmp) 
                      : "memory", "cc");
    return prev;
}
#define APR_OVERRIDE_ATOMIC_CASPTR

#endif /* __x86_64__ && __GNUC__ && !USE_SOLARIS_ATOMICS */

#if (defined(__PPC__) || defined(__ppc__)) && defined(__GNUC__) \
    && !defined(USE_GENERIC_ATOMICS) \
    && !defined(USE_SOLARIS_ATOMICS)

APR_DECLARE(apr_uint32_t) apr_atomic_cas32(volatile apr_uint32_t *mem,
                                           apr_uint32_t swap,
                                           apr_uint32_t cmp)
{
    apr_uint32_t prev;
                                                                                
    __asm__ volatile ("0:\n\t"                   /* retry local label     */
                      "lwarx  %0,0,%1\n\t"       /* load prev and reserve */
                      "cmpw   %0,%3\n\t"         /* does it match cmp?    */
                      "bne-   1f\n\t"            /* ...no, bail out       */
                      "stwcx. %2,0,%1\n\t"       /* ...yes, conditionally
                                                    store swap            */
                      "bne-   0b\n\t"            /* start over if we lost
                                                    the reservation       */
                      "1:"                       /* exit local label      */

                      : "=&r"(prev)                        /* output      */
                      : "b" (mem), "r" (swap), "r"(cmp)    /* inputs      */
                      : "memory", "cc");                   /* clobbered   */
    return prev;
}
#define APR_OVERRIDE_ATOMIC_CAS32

APR_DECLARE(apr_uint32_t) apr_atomic_add32(volatile apr_uint32_t *mem,
                                           apr_uint32_t delta)
{
    apr_uint32_t prev, temp;
                                                                                
    __asm__ volatile ("0:\n\t"                   /* retry local label     */
                      "lwarx  %0,0,%2\n\t"       /* load prev and reserve */
                      "add    %1,%0,%3\n\t"      /* temp = prev + delta   */
                      "stwcx. %1,0,%2\n\t"       /* conditionally store   */
                      "bne-   0b"                /* start over if we lost
                                                the reservation       */

                      /*XXX find a cleaner way to define the temp         
                       *    it's not an output
                       */
                      : "=&r" (prev), "=&r" (temp)        /* output, temp */
                      : "b" (mem), "r" (delta)            /* inputs       */
                      : "memory", "cc");                  /* clobbered    */
    return prev;
}
#define APR_OVERRIDE_ATOMIC_ADD32

#endif /* __PPC__ && __GNUC__ && !USE_SOLARIS_ATOMICS */

#if defined(USE_SOLARIS_ATOMICS) && !defined(USE_GENERIC_ATOMICS)

APR_DECLARE(apr_status_t) apr_atomic_init(apr_pool_t *p)
{
    return APR_SUCCESS;
}
#define APR_OVERRIDE_ATOMIC_INIT

APR_DECLARE(apr_uint32_t) apr_atomic_read32(volatile apr_uint32_t *mem)
{
    return atomic_add_32_nv (mem, 0);
}
#define APR_OVERRIDE_ATOMIC_READ32

APR_DECLARE(void) apr_atomic_set32(volatile apr_uint32_t *mem, apr_uint32_t val)
{
    atomic_swap_32 (mem, val);
}
#define APR_OVERRIDE_ATOMIC_SET32

APR_DECLARE(apr_uint32_t) apr_atomic_add32(volatile apr_uint32_t *mem, 
                                           apr_uint32_t delta)
{
    return (atomic_add_32_nv (mem, (int32_t)delta) - delta);
}
#define APR_OVERRIDE_ATOMIC_ADD32

APR_DECLARE(void) apr_atomic_sub32(volatile apr_uint32_t *mem,
                                   apr_uint32_t delta)
{
    atomic_add_32 (mem, -(int32_t)delta);
}
#define APR_OVERRIDE_ATOMIC_SUB32

APR_DECLARE(apr_uint32_t) apr_atomic_inc32(volatile apr_uint32_t *mem)
{
    return (atomic_inc_32_nv (mem) - 1);
}
#define APR_OVERRIDE_ATOMIC_INC32

APR_DECLARE(int) apr_atomic_dec32(volatile apr_uint32_t *mem)
{
    return atomic_dec_32_nv (mem);
}
#define APR_OVERRIDE_ATOMIC_DEC32

APR_DECLARE(apr_uint32_t) apr_atomic_xchg32(volatile apr_uint32_t *mem,
                                            apr_uint32_t val)
{
    return atomic_swap_32 (mem, val);
}
#define APR_OVERRIDE_ATOMIC_XCHG32

APR_DECLARE(apr_uint32_t) apr_atomic_cas32(volatile apr_uint32_t *mem,
                                           apr_uint32_t with,
                                           apr_uint32_t cmp)
{
    return atomic_cas_32 (mem, cmp, with);
}
#define APR_OVERRIDE_ATOMIC_CAS32

APR_DECLARE(void *) apr_atomic_casptr(volatile void **mem,
                                      void *with,
                                      const void *cmp)
{
    return atomic_cas_ptr (mem, (void *)cmp, with);
}
#define APR_OVERRIDE_ATOMIC_CASPTR

#endif /* USE_SOLARIS_ATOMICS */

#if !defined(APR_OVERRIDE_ATOMIC_INIT)

#if APR_HAS_THREADS
#define NUM_ATOMIC_HASH 7
/* shift by 2 to get rid of alignment issues */
#define ATOMIC_HASH(x) (unsigned int)(((unsigned long)(x)>>2)%(unsigned int)NUM_ATOMIC_HASH)
static apr_thread_mutex_t **hash_mutex;
#endif /* APR_HAS_THREADS */

apr_status_t apr_atomic_init(apr_pool_t *p)
{
#if APR_HAS_THREADS
    int i;
    apr_status_t rv;
    hash_mutex = apr_palloc(p, sizeof(apr_thread_mutex_t*) * NUM_ATOMIC_HASH);

    for (i = 0; i < NUM_ATOMIC_HASH; i++) {
        rv = apr_thread_mutex_create(&(hash_mutex[i]),
                                     APR_THREAD_MUTEX_DEFAULT, p);
        if (rv != APR_SUCCESS) {
           return rv;
        }
    }
#endif /* APR_HAS_THREADS */
    return APR_SUCCESS;
}
#endif /* !defined(APR_OVERRIDE_ATOMIC_INIT) */

/* abort() if 'x' does not evaluate to APR_SUCCESS. */
#define CHECK(x) do { if ((x) != APR_SUCCESS) abort(); } while (0)

#if !defined(APR_OVERRIDE_ATOMIC_ADD32)
#if defined(APR_OVERRIDE_ATOMIC_CAS32)
apr_uint32_t apr_atomic_add32(volatile apr_uint32_t *mem, apr_uint32_t val)
{
    apr_uint32_t old_value, new_value;
    
    do {
        old_value = *mem;
        new_value = old_value + val;
    } while (apr_atomic_cas32(mem, new_value, old_value) != old_value);
    return old_value;
}
#else
apr_uint32_t apr_atomic_add32(volatile apr_uint32_t *mem, apr_uint32_t val)
{
    apr_uint32_t old_value;

#if APR_HAS_THREADS
    apr_thread_mutex_t *lock = hash_mutex[ATOMIC_HASH(mem)];
       
    CHECK(apr_thread_mutex_lock(lock));
    old_value = *mem;
    *mem += val;
    CHECK(apr_thread_mutex_unlock(lock));
#else
    old_value = *mem;
    *mem += val;
#endif /* APR_HAS_THREADS */
    return old_value;
}
#endif /* defined(APR_OVERRIDE_ATOMIC_CAS32) */
#endif /* !defined(APR_OVERRIDE_ATOMIC_ADD32) */

#if !defined(APR_OVERRIDE_ATOMIC_SUB32)
#if defined(APR_OVERRIDE_ATOMIC_CAS32)
void apr_atomic_sub32(volatile apr_uint32_t *mem, apr_uint32_t val)
{
    apr_uint32_t old_value, new_value;
    
    do {
        old_value = *mem;
        new_value = old_value - val;
    } while (apr_atomic_cas32(mem, new_value, old_value) != old_value);
}
#else
void apr_atomic_sub32(volatile apr_uint32_t *mem, apr_uint32_t val) 
{
#if APR_HAS_THREADS
    apr_thread_mutex_t *lock = hash_mutex[ATOMIC_HASH(mem)];
       
    CHECK(apr_thread_mutex_lock(lock));
    *mem -= val;
    CHECK(apr_thread_mutex_unlock(lock));
#else
    *mem -= val;
#endif /* APR_HAS_THREADS */
}
#endif /* defined(APR_OVERRIDE_ATOMIC_CAS32) */
#endif /* !defined(APR_OVERRIDE_ATOMIC_SUB32) */

#if !defined(APR_OVERRIDE_ATOMIC_SET32)
void apr_atomic_set32(volatile apr_uint32_t *mem, apr_uint32_t val) 
{
#if APR_HAS_THREADS
    apr_thread_mutex_t *lock = hash_mutex[ATOMIC_HASH(mem)];

    CHECK(apr_thread_mutex_lock(lock));
    *mem = val;
    CHECK(apr_thread_mutex_unlock(lock));
#else
    *mem = val;
#endif /* APR_HAS_THREADS */
}
#endif /* !defined(APR_OVERRIDE_ATOMIC_SET32) */

#if !defined(APR_OVERRIDE_ATOMIC_INC32)
apr_uint32_t apr_atomic_inc32(volatile apr_uint32_t *mem) 
{
    return apr_atomic_add32(mem, 1);
}
#endif /* !defined(APR_OVERRIDE_ATOMIC_INC32) */

#if !defined(APR_OVERRIDE_ATOMIC_DEC32)
#if defined(APR_OVERRIDE_ATOMIC_CAS32)
int apr_atomic_dec32(volatile apr_uint32_t *mem)
{
    apr_uint32_t old_value, new_value;
    
    do {
        old_value = *mem;
        new_value = old_value - 1;
    } while (apr_atomic_cas32(mem, new_value, old_value) != old_value);
    return old_value != 1;
}
#else
int apr_atomic_dec32(volatile apr_uint32_t *mem) 
{
#if APR_HAS_THREADS
    apr_thread_mutex_t *lock = hash_mutex[ATOMIC_HASH(mem)];
    apr_uint32_t new;

    CHECK(apr_thread_mutex_lock(lock));
    (*mem)--;
    new = *mem;
    CHECK(apr_thread_mutex_unlock(lock));
    return new;
#else
    (*mem)--;
    return *mem; 
#endif /* APR_HAS_THREADS */
}
#endif /* defined(APR_OVERRIDE_ATOMIC_CAS32) */
#endif /* !defined(APR_OVERRIDE_ATOMIC_DEC32) */

#if !defined(APR_OVERRIDE_ATOMIC_CAS32)
apr_uint32_t apr_atomic_cas32(volatile apr_uint32_t *mem, apr_uint32_t with,
			      apr_uint32_t cmp)
{
    apr_uint32_t prev;
#if APR_HAS_THREADS
    apr_thread_mutex_t *lock = hash_mutex[ATOMIC_HASH(mem)];

    CHECK(apr_thread_mutex_lock(lock));
    prev = *mem;
    if (prev == cmp) {
        *mem = with;
    }
    CHECK(apr_thread_mutex_unlock(lock));
#else
    prev = *mem;
    if (prev == cmp) {
        *mem = with;
    }
#endif /* APR_HAS_THREADS */
    return prev;
}
#endif /* !defined(APR_OVERRIDE_ATOMIC_CAS32) */

#if !defined(APR_OVERRIDE_ATOMIC_XCHG32)
#if defined(APR_OVERRIDE_ATOMIC_CAS32)
apr_uint32_t apr_atomic_xchg32(volatile apr_uint32_t *mem, apr_uint32_t val)
{
    apr_uint32_t prev;
    do {
        prev = *mem;
    } while (apr_atomic_cas32(mem, val, prev) != prev);
    return prev;
}
#else
apr_uint32_t apr_atomic_xchg32(volatile apr_uint32_t *mem, apr_uint32_t val)
{
    apr_uint32_t prev;
#if APR_HAS_THREADS
    apr_thread_mutex_t *lock = hash_mutex[ATOMIC_HASH(mem)];

    CHECK(apr_thread_mutex_lock(lock));
    prev = *mem;
    *mem = val;
    CHECK(apr_thread_mutex_unlock(lock));
#else
    prev = *mem;
    *mem = val;
#endif /* APR_HAS_THREADS */
    return prev;
}
#endif /* defined(APR_OVERRIDE_ATOMIC_CAS32) */
#endif /* !defined(APR_OVERRIDE_ATOMIC_XCHG32) */

#if !defined(APR_OVERRIDE_ATOMIC_CASPTR)
void *apr_atomic_casptr(volatile void **mem, void *with, const void *cmp)
{
    void *prev;
#if APR_HAS_THREADS
    apr_thread_mutex_t *lock = hash_mutex[ATOMIC_HASH(mem)];

    CHECK(apr_thread_mutex_lock(lock));
    prev = *(void **)mem;
    if (prev == cmp) {
        *mem = with;
    }
    CHECK(apr_thread_mutex_unlock(lock));
#else
    prev = *(void **)mem;
    if (prev == cmp) {
        *mem = with;
    }
#endif /* APR_HAS_THREADS */
    return prev;
}
#endif /* !defined(APR_OVERRIDE_ATOMIC_CASPTR) */

#if !defined(APR_OVERRIDE_ATOMIC_READ32)
APR_DECLARE(apr_uint32_t) apr_atomic_read32(volatile apr_uint32_t *mem)
{
    return *mem;
}
#endif

