/*---------------------------------------------------------------------------
    icl_lfcontext.h - icl_lfcontext component

    This class holds the thread-local context for lock-free functions.
    Generated from icl_lfcontext.icl by icl_gen using GSL/4.
    
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

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_ICL_LFCONTEXT_SAFE
#   define INCLUDE_ICL_LFCONTEXT_SAFE
#   define INCLUDE_ICL_LFCONTEXT_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ICL_LFCONTEXT_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _icl_lfcontext_t icl_lfcontext_t;

#define ICL_LFCONTEXT_ALIVE             0xFABB
#define ICL_LFCONTEXT_DEAD              0xDEAD

#define ICL_LFCONTEXT_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL icl_lfcontext\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != ICL_LFCONTEXT_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "icl_lfcontext at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ICL_LFCONTEXT_ALIVE, self->object_tag);\
        icl_lfcontext_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "icl_lfcontext_list.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_LFCONTEXT_ACTIVE
#   if defined (ICL_IMPORT_ICL_LFCONTEXT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ICL_LFCONTEXT_UNSAFE
#   define INCLUDE_ICL_LFCONTEXT_UNSAFE
#   define INCLUDE_ICL_LFCONTEXT_ACTIVE

#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    icl_lfcontext_animating;
//  Lock-free macros

#define CURRENT(loc,ver)    ((ver%2==0)? loc->ptr0 : loc->ptr1)
#define NONCURADDR(loc,ver) ((ver%2==0)? (volatile void **) & loc->ptr1 : (volatile void **) & loc->ptr0)
#define INIT_EXIT           {0,2,FALSE,FALSE}
#define CLEAN(exit)         (exit.count == 0 && exit.transfers_left == 0)
#define FREEABLE(exit)      (CLEAN(exit) && exit.nl_p && exit.to_be_freed)

typedef struct {
    volatile apr_uint32_t 
        ver                 __attribute__ ((packed));
    volatile apr_uint32_t 
        count               __attribute__ ((packed));
} entry_tag_t; 

typedef struct {
    volatile int 
        count:30            __attribute__ ((packed));
    volatile int
        transfers_left:30   __attribute__ ((packed));
    volatile int
        nl_p:1              __attribute__ ((packed));
    volatile int
        to_be_freed:1       __attribute__ ((packed));
    volatile int
        filler:2            __attribute__ ((packed));
} exit_tag_t;

typedef struct _icl_lfqueue_node_t icl_lfqueue_node_t;

struct _icl_lfqueue_node_t {
    volatile icl_lfqueue_node_t
        *next,
        *prev;
    volatile exit_tag_t 
        exit_tag;
    Bool
        zombie;
    void
        *item;
};

typedef struct {
    volatile icl_lfqueue_node_t 
        *ptr0, 
        *ptr1;
    volatile entry_tag_t 
        entry;
} llsc_t;

//  Structure of the icl_lfcontext object

struct _icl_lfcontext_t {
dbyte
    object_tag;                     //  Object validity marker
volatile icl_lfcontext_list_t *list_head;
volatile icl_lfcontext_t *list_prev;
volatile icl_lfcontext_t *list_next;
apr_uint32_t
    my_ver;
volatile icl_lfqueue_node_t
    *my_node;
icl_lfqueue_node_t
    *cache;
};

#   ifdef __cplusplus
}
#   endif
#   include "icl_lfcontext_list.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
void
    icl_lfcontext_selftest (
void);

#define icl_lfcontext_new()             icl_lfcontext_new_ (__FILE__, __LINE__)
icl_lfcontext_t *
    icl_lfcontext_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    icl_lfcontext_remove_from_all_containers (
icl_lfcontext_t * self                  //  The item
);

#define icl_lfcontext_show(item,opcode,trace_file)  icl_lfcontext_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    icl_lfcontext_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    icl_lfcontext_terminate (
void);

#define icl_lfcontext_destroy(self)     icl_lfcontext_destroy_ (self, __FILE__, __LINE__)
void
    icl_lfcontext_destroy_ (
icl_lfcontext_t * ( * self_p ),         //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    icl_lfcontext_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define icl_lfcontext_new_in_scope(self_p,_scope)  icl_lfcontext_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    icl_lfcontext_new_in_scope_ (
icl_lfcontext_t * * self_p,             //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_LFCONTEXT_ACTIVE
#   if defined (ICL_IMPORT_ICL_LFCONTEXT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ICL_LFCONTEXT_INLINE)
#   define INCLUDE_ICL_LFCONTEXT_INLINE
#   define INCLUDE_ICL_LFCONTEXT_ACTIVE

#   include "icl_lfcontext_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LFCONTEXT)   || defined (BASE_TRACE_ICL_LFCONTEXT_DESTROY)   || defined (BASE_TRACE_ICL_LFCONTEXT_SELFTEST)   || defined (BASE_TRACE_ICL_LFCONTEXT_NEW)   || defined (BASE_TRACE_ICL_LFCONTEXT_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_ICL_LFCONTEXT_SHOW)   || defined (BASE_TRACE_ICL_LFCONTEXT_TERMINATE)   || defined (BASE_TRACE_ICL_LFCONTEXT_DESTROY_PUBLIC)   || defined (BASE_TRACE_ICL_LFCONTEXT_ALLOC)   || defined (BASE_TRACE_ICL_LFCONTEXT_FREE)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_INITIALISE)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_PURGE)   || defined (BASE_TRACE_ICL_LFCONTEXT_CACHE_TERMINATE)   || defined (BASE_TRACE_ICL_LFCONTEXT_ANIMATE)   || defined (BASE_TRACE_ICL_LFCONTEXT_NEW_IN_SCOPE) )
void
    icl_lfcontext_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#if defined (__i386__)

static inline Bool cas_ptr (volatile void **mem, 
              void *cmp,
              void *with)
{
    unsigned char
        result;

    asm volatile ("lock; cmpxchgl %2, %3\n\t"
                  "setz %1\n\t"
                  "sfence\n\t"
                  : "=m" (*mem), 
                    "=a" (result)               
                  : "r"  (with), 
                    "m"  (*mem), 
                    "1"  (cmp) 
                  : "memory", "cc");
    return (Bool) result;
}

static inline Bool cas_entry_tag_t (volatile entry_tag_t *mem, 
                             entry_tag_t cmp,
                             entry_tag_t with)
{
    unsigned char
        result;

    asm volatile ("mov 4(%3), %%edx\n\t"
                  "mov  (%3), %3\n\t"
                  "mov 4(%4), %%ecx\n\t"
                  "mov  (%4), %4\n\t"
                  "lock; cmpxchg8b %2\n\t"
                  "setz %1\n\t"
                  "sfence\n\t"
                  : "=m" (*mem),
                    "=a" (result)
                  : "m"  (*mem),
                    "a"  (&cmp),
                    "b"  (&with)
                  : "memory", "cc", "edx", "ecx");
    return (Bool) result;
}

static inline Bool cas_exit_tag_t (volatile exit_tag_t *mem, 
                            exit_tag_t cmp,
                            exit_tag_t with)
{
    unsigned char
        result;

    asm volatile ("mov 4(%3), %%edx\n\t"
                  "mov  (%3), %3\n\t"
                  "mov 4(%4), %%ecx\n\t"
                  "mov  (%4), %4\n\t"
                  "lock; cmpxchg8b %2\n\t"
                  "setz %1\n\t"
                  "sfence\n\t"
                  : "=m" (*mem),
                    "=a" (result)
                  : "m"  (*mem),
                    "a"  (&cmp),
                    "b"  (&with)
                  : "memory", "cc", "edx", "ecx");
    return (Bool) result;
}

#else

//  No lockfree primitives so just output stubs that abort.

static inline Bool cas_ptr (volatile void **mem, 
              void *cmp,
              void *with)
{
    fprintf (stderr, "Lockfree is unavailable.\n");
    abort ();
    return 0;
}

static inline Bool cas_entry_tag_t (volatile entry_tag_t *mem, 
                             entry_tag_t cmp,
                             entry_tag_t with)
{
    fprintf (stderr, "Lockfree is unavailable.\n");
    abort ();
    return 0;
}

static inline Bool cas_exit_tag_t (volatile exit_tag_t *mem, 
                            exit_tag_t cmp,
                            exit_tag_t with)
{
    fprintf (stderr, "Lockfree is unavailable.\n");
    abort ();
    return 0;
}
#endif

static inline void transfer (volatile icl_lfqueue_node_t *node, apr_int32_t count) 
{
    exit_tag_t
        pre, 
        post;

    do {
        pre                  = node->exit_tag;
        post                 = node->exit_tag;
        post.count          += count;
        post.transfers_left -= 1;
    } while (!cas_exit_tag_t (&node->exit_tag, pre, post));
}

static inline volatile icl_lfqueue_node_t *ll (volatile icl_lfcontext_t *context, volatile llsc_t *loc) 
{
    entry_tag_t 
        pre,
        post;

    do {
        pre              = loc->entry;
        context->my_ver  = pre.ver;
        context->my_node = CURRENT(loc, pre.ver);
        post.ver         = pre.ver;
        post.count       = pre.count + 1;
    } while (!cas_entry_tag_t (&loc->entry, pre, post));

    return context->my_node;
}

static inline void set_nl_prev (volatile icl_lfcontext_t *context, volatile icl_lfqueue_node_t *prev_node) 
{
    exit_tag_t pre;
    exit_tag_t post;

    do {
        pre       = prev_node->exit_tag;
        post      = prev_node->exit_tag;
        post.nl_p = TRUE;
    } while (!cas_exit_tag_t (&prev_node->exit_tag, pre, post));
    if (FREEABLE (post)) {
        prev_node->zombie = TRUE;
        prev_node->next   = context->cache;
        context->cache    = (icl_lfqueue_node_t *) prev_node;
    }
}

static inline void set_to_be_freed (volatile icl_lfcontext_t *context, volatile icl_lfqueue_node_t *prev_node)
{
    exit_tag_t pre;
    exit_tag_t post;

    do {
        pre              = prev_node->exit_tag;
        post             = prev_node->exit_tag;
        post.to_be_freed = TRUE;
    } while (!cas_exit_tag_t (&prev_node->exit_tag, pre, post));
    if (FREEABLE (post)) {
        prev_node->zombie = TRUE;
        prev_node->next   = context->cache;
        context->cache    = (icl_lfqueue_node_t *) prev_node;
    }
}

static inline void release (volatile icl_lfcontext_t *context, volatile icl_lfqueue_node_t *node) 
{
    volatile icl_lfqueue_node_t 
        *prev_node = node->prev;
    exit_tag_t 
        pre,
        post; 

    do {
        pre         = node->exit_tag;
        post        = node->exit_tag;;
        post.count -= 1;
    } while (!cas_exit_tag_t (&node->exit_tag, pre, post));
    if (CLEAN (post)) 
        set_nl_prev (context, prev_node);
    if (FREEABLE (post)) {
        node->zombie   = TRUE;
        node->next     = context->cache;
        context->cache = (icl_lfqueue_node_t *) node;
    }
}


static inline Bool sc (volatile icl_lfcontext_t *context, volatile llsc_t *loc, icl_lfqueue_node_t *node)
{
    icl_lfqueue_node_t 
        *prev_node = (icl_lfqueue_node_t *) context->my_node->prev;
    entry_tag_t
        pre,
        post;
    Bool 
        success;

    success = cas_ptr (NONCURADDR (loc, context->my_ver), prev_node, node);
    pre = loc->entry;
    while (pre.ver == context->my_ver) {
        post.ver    = pre.ver + 1;
        post.count  = 0;
        if (cas_entry_tag_t (&loc->entry, pre, post))
            transfer (context->my_node, pre.count);
        pre = loc->entry;
    } 
    release (context, context->my_node);

    return success;
}


static inline void un_link (volatile icl_lfcontext_t *context, volatile llsc_t *loc)
{
    entry_tag_t 
        pre,
        post;

    pre = loc->entry;
    while (pre.ver == context->my_ver) {
        post.ver    = pre.ver;
        post.count  = pre.count - 1;
        if (cas_entry_tag_t (&loc->entry, pre, post))
            return;
        pre = loc->entry;
    }
    release (context, context->my_node);
}
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_LFCONTEXT_ACTIVE
#   if defined (ICL_IMPORT_ICL_LFCONTEXT_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ICL_LFCONTEXT_ROOT
#   endif
# endif
#endif
