/*---------------------------------------------------------------------------
    icl_mem_lockfree.h - icl_mem_lockfree component

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

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_ICL_MEM_LOCKFREE_SAFE
#   define INCLUDE_ICL_MEM_LOCKFREE_SAFE
#   define INCLUDE_ICL_MEM_LOCKFREE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ICL_MEM_LOCKFREE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _icl_mem_lockfree_t icl_mem_lockfree_t;
#   ifdef __cplusplus
}
#   endif

#   include "icl_lfcontext.h"
#   include "icl_cache.h"
#   include "icl_system.h"
#   include "icl_stats.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_MEM_LOCKFREE_ACTIVE
#   if defined (ICL_IMPORT_ICL_MEM_LOCKFREE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ICL_MEM_LOCKFREE_UNSAFE
#   define INCLUDE_ICL_MEM_LOCKFREE_UNSAFE
#   define INCLUDE_ICL_MEM_LOCKFREE_ACTIVE

#   include "icl_lfcontext.h"
#   include "icl_cache.h"
#   include "icl_system.h"
#   include "icl_stats.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    icl_mem_lockfree_animating;
//  Macros                                                                     

#define ICL_MEM_LOCKFREE_SIZE (((sizeof (icl_mem_lockfree_t) + 7) / 8) * 8)

#define ICL_MEM_LOCKFREE_ASSERT_SANE(self, item)\
{\
    if (self->tag != ICL_CACHE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Allocated item at %p expected tag=0x%x, actual tag=0x%x\n", item, ICL_CACHE_ALIVE, self->tag);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}

//  Global variables

extern Bool
    s_icl_mem_lockfree_active;
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)

typedef struct {
    apr_uint32_t
        my_ver;
    icl_mem_lockfree_t
        *my_node;
} icl_mem_lockfree_context_t;

//  Lock-free voodoo

typedef struct {
    int 
        count:30
        __attribute__ ((packed));
    int
        transfers_left:30
        __attribute__ ((packed));
    int
        nl_p:1
        __attribute__ ((packed));
    int
        to_be_freed:1
        __attribute__ ((packed));
    int
        to_be_enqueued:1
        __attribute__ ((packed));
} freelist_exit_tag_t;

typedef struct {
    icl_mem_lockfree_t 
        *ptr0, 
        *ptr1;
    entry_tag_t 
        entry;
} freelist_llsc_t;

typedef struct {
    apr_threadkey_t
        *key;                           //  For thread-local data
    freelist_llsc_t
        *head,
        *tail;
} icl_mem_lockfree_list_t;

#else

//  Dummy type

typedef void
    icl_mem_lockfree_list_t;

#endif

//  Structure of the icl_mem_lockfree object

struct _icl_mem_lockfree_t {
qbyte
    tag;                            //  To detect corruption               
icl_cache_t
    *cache;                         //  The cache for this object          
qbyte
    size;                           //  The size of this object
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    volatile icl_mem_lockfree_t
        *next,
        *prev;
    volatile freelist_exit_tag_t 
        exit_tag;
#endif
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define icl_mem_lockfree_cache_alloc(cache)  icl_mem_lockfree_cache_alloc_ (cache, __FILE__, __LINE__)
static inline void *
    icl_mem_lockfree_cache_alloc_ (
icl_cache_t * cache,                    //  The cache for the allocation
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_mem_lockfree_alloc(size)    icl_mem_lockfree_alloc_ (size, __FILE__, __LINE__)
static inline void *
    icl_mem_lockfree_alloc_ (
size_t size,                            //  How much memory to allocate
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_mem_lockfree_realloc(item,size)  icl_mem_lockfree_realloc_ (item, size, __FILE__, __LINE__)
static inline void *
    icl_mem_lockfree_realloc_ (
void * item,                            //  Cient buffer to reallocate
qbyte size,                             //  How much memory to allocate
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static inline void
    icl_mem_lockfree_free (
void * item                             //  Client buffer to free
);

icl_mem_lockfree_list_t *
    icl_mem_lockfree_list_new (
void);

void
    icl_mem_lockfree_list_destroy (
icl_mem_lockfree_list_t * ( * self_p )  //  Not documented
);

static inline void
    icl_mem_lockfree_cache_insert (
icl_cache_t * cache,                    //  The cache for the allocation
icl_mem_lockfree_t * self               //  The allocation block
);

#define icl_mem_lockfree_cache_reuse(cache)  icl_mem_lockfree_cache_reuse_ (cache, __FILE__, __LINE__)
static inline void *
    icl_mem_lockfree_cache_reuse_ (
icl_cache_t * cache,                    //  The cache for the allocation
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

icl_mem_lockfree_t *
    icl_mem_lockfree_new (
size_t size                             //  How much memory to allocate
);

static inline void
    icl_mem_lockfree_cache_recycle (
icl_mem_lockfree_t * ( * self_p )       //  The allocation block
);

void
    icl_mem_lockfree_cache_purge (
icl_cache_t * cache                     //  The cache to purge
);

static inline void
    icl_mem_lockfree_cache_reset (
icl_mem_lockfree_t * self               //  The allocation block
);

int
    icl_mem_lockfree_cache_assert (
icl_cache_t * cache,                    //  The cache for the allocation
FILE ** trace_file                      //  File to print to, opened on error
);

void
    icl_mem_lockfree_show (
void);

#define icl_mem_lockfree_possess(item)  icl_mem_lockfree_possess_ (item, __FILE__, __LINE__)
static inline void
    icl_mem_lockfree_possess_ (
void * item,                            //  Client buffer to free
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static inline void
    icl_mem_lockfree_set_callback (
void * item,                            //  Client buffer to free
icl_callback_fn * callback              //  Callback function to set
);

void
    icl_mem_lockfree_selftest (
void);

#define icl_mem_lockfree_cache_pop(cache)  icl_mem_lockfree_cache_pop_ (cache, __FILE__, __LINE__)
void *
    icl_mem_lockfree_cache_pop_ (
icl_cache_t * cache,                    //  The cache for the allocation
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_mem_lockfree_cache_new(cache)  icl_mem_lockfree_cache_new_ (cache, __FILE__, __LINE__)
void *
    icl_mem_lockfree_cache_new_ (
icl_cache_t * cache,                    //  The cache for the allocation
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    icl_mem_lockfree_destroy (
icl_mem_lockfree_t * ( * self_p )       //  The allocation block
);

void
    icl_mem_lockfree_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_MEM_LOCKFREE_ACTIVE
#   if defined (ICL_IMPORT_ICL_MEM_LOCKFREE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ICL_MEM_LOCKFREE_INLINE)
#   define INCLUDE_ICL_MEM_LOCKFREE_INLINE
#   define INCLUDE_ICL_MEM_LOCKFREE_ACTIVE

#   include "icl_lfcontext.h"
#   include "icl_cache.h"
#   include "icl_system.h"
#   include "icl_stats.h"

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_ALLOC))
extern icl_stats_t *s_icl_mem_lockfree_cache_alloc_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_ALLOC))
extern icl_stats_t *s_icl_mem_lockfree_alloc_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_REALLOC))
extern icl_stats_t *s_icl_mem_lockfree_realloc_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_FREE))
extern icl_stats_t *s_icl_mem_lockfree_free_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_INSERT))
extern icl_stats_t *s_icl_mem_lockfree_cache_insert_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_REUSE))
extern icl_stats_t *s_icl_mem_lockfree_cache_reuse_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_RECYCLE))
extern icl_stats_t *s_icl_mem_lockfree_cache_recycle_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_RESET))
extern icl_stats_t *s_icl_mem_lockfree_cache_reset_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_POSSESS))
extern icl_stats_t *s_icl_mem_lockfree_possess_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_SET_CALLBACK))
extern icl_stats_t *s_icl_mem_lockfree_set_callback_stats;
#endif
#   ifdef __cplusplus
extern "C" {
#   endif

#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)

#if defined (__i386__)
static inline Bool cas_freelist_exit_tag_t (volatile freelist_exit_tag_t *mem, 
              freelist_exit_tag_t cmp,
              freelist_exit_tag_t with)
{
    unsigned char
        result;

    asm volatile ("mov 4(%3), %%edx;               mov (%3), %3;    mov 4(%4), %%ecx;    mov (%4), %4;    lock; cmpxchg8b %2; setz %1; sfence"  
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

static inline Bool cas_freelist_exit_tag_t (volatile freelist_exit_tag_t *mem, 
                            freelist_exit_tag_t cmp,
                            freelist_exit_tag_t with)
{
    fprintf (stderr, "Lockfree is unavailable.\n");
    abort ();
    return 0;
}

#endif // __i386__

//  Lock-free macros

#define CURRENT(loc,ver)     ((ver%2==0)? loc->ptr0 : loc->ptr1)
#define NONCURADDR(loc,ver)  ((ver%2==0)? (volatile void **) & loc->ptr1 : (volatile void **) & loc->ptr0)
#define INIT_EXIT            {0,2,FALSE,FALSE}
#define FREELIST_CLEAN(exit) (exit.count == 0 && exit.transfers_left == 0)
#define QUEUEABLE(exit)      (FREELIST_CLEAN(exit) && exit.nl_p && exit.to_be_enqueued)

//  Prototypes

static inline void enqueue (volatile icl_mem_lockfree_context_t *context, volatile icl_mem_lockfree_t *node);


//  Lock-free free-list management

static inline void freelist_transfer (volatile icl_mem_lockfree_t *node, apr_int32_t count) 
{
    freelist_exit_tag_t
        pre, 
        post;

    do {
        pre                  = node->exit_tag;
        post                 = node->exit_tag;
        post.count          += count;
        post.transfers_left -= 1;
    } while (!cas_freelist_exit_tag_t (&node->exit_tag, pre, post));
}

static inline volatile icl_mem_lockfree_t *freelist_ll (volatile icl_mem_lockfree_context_t *context, volatile freelist_llsc_t *loc) 
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

static inline void freelist_set_nl_prev (volatile icl_mem_lockfree_context_t *context, volatile icl_mem_lockfree_t *prev_node) 
{
    freelist_exit_tag_t pre;
    freelist_exit_tag_t post;

    do {
        pre       = prev_node->exit_tag;
        post      = prev_node->exit_tag;
        post.nl_p = TRUE;
    } while (!cas_freelist_exit_tag_t (&prev_node->exit_tag, pre, post));
    if (QUEUEABLE (post))
        enqueue (context, prev_node);
}

static inline void freelist_release (volatile icl_mem_lockfree_context_t *context, volatile icl_mem_lockfree_t *node) 
{
    volatile icl_mem_lockfree_t 
        *prev_node = node->prev;
    freelist_exit_tag_t 
        pre,
        post; 

    do {
        pre         = node->exit_tag;
        post        = node->exit_tag;;
        post.count -= 1;
    } while (!cas_freelist_exit_tag_t (&node->exit_tag, pre, post));
    if (FREELIST_CLEAN (post)) 
        freelist_set_nl_prev (context, prev_node);
    if (QUEUEABLE (post))
        enqueue (context, node);
}


static inline Bool freelist_sc (volatile icl_mem_lockfree_context_t *context, volatile freelist_llsc_t *loc, icl_mem_lockfree_t *node)
{
    icl_mem_lockfree_t 
        *prev_node = (icl_mem_lockfree_t *) context->my_node->prev;
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
            freelist_transfer (context->my_node, pre.count);
        pre = loc->entry;
    } 
    freelist_release (context, context->my_node);

    return success;
}


static inline void enqueue (volatile icl_mem_lockfree_context_t *context, volatile icl_mem_lockfree_t *node)
{
    freelist_exit_tag_t
        init_exit_tag = INIT_EXIT;
    volatile icl_mem_lockfree_t
        *tail;

    node->next = NULL;
    node->exit_tag = init_exit_tag;
    FOREVER {
        tail = freelist_ll (context, node->cache->lockfree_unused_list->tail);
        node->prev = tail;
        if (cas_ptr ((volatile void **) &tail->next, NULL, (void *) node)) {
            freelist_sc (context, node->cache->lockfree_unused_list->tail, (void *) node);
            return;
        }
        else
            freelist_sc (context, node->cache->lockfree_unused_list->tail, (void *) tail->next);
    }
}

static inline void freelist_un_link (volatile icl_mem_lockfree_context_t *context, volatile freelist_llsc_t *loc)
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
    freelist_release (context, context->my_node);
}

static inline icl_mem_lockfree_t *dequeue (volatile icl_mem_lockfree_context_t *context, volatile icl_mem_lockfree_list_t *queue)
{
    volatile icl_mem_lockfree_t
        *head,
        *next;

    FOREVER {
        head = freelist_ll (context, queue->head);
        next = head->next;
        if (next == NULL) {
            freelist_un_link (context, queue->head);
            return NULL;
        }
        if (freelist_sc (context, queue->head, (void *) next))
            return (icl_mem_lockfree_t *) next;
    }
}

static inline void set_to_be_enqueued (volatile icl_mem_lockfree_context_t *context, volatile icl_mem_lockfree_t *prev_node) 
{
    freelist_exit_tag_t pre;
    freelist_exit_tag_t post;

    do {
        pre                 = prev_node->exit_tag;
        post                = prev_node->exit_tag;
        post.to_be_enqueued = TRUE;
    } while (!cas_freelist_exit_tag_t (&prev_node->exit_tag, pre, post));
    if (QUEUEABLE (post))
        enqueue (context, prev_node);
}

#endif
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_cache_alloc

    Type: Component method
    Reuses or allocates a block in a cache.  The size of the block is the size 
    of the cache.
    -------------------------------------------------------------------------
 */

static inline void *
    icl_mem_lockfree_cache_alloc_ (
    icl_cache_t * cache,                //  The cache for the allocation
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    void *
        item = NULL;                    //  The returned client pointer

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_ALLOC))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_ALLOC))
    icl_stats_inc ("icl_mem_lockfree_cache_alloc", &s_icl_mem_lockfree_cache_alloc_stats);
#endif

item = icl_mem_lockfree_cache_pop_ (cache, file, line);
if (!item)
    item = icl_mem_lockfree_cache_new_ (cache, file, line);
#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_ALLOC))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_alloc

    Type: Component method
    Allocate a block of a given size in the direct cache.  This isn't really
    a cache at all and just serves to track allocated blocks.
    cache.
    -------------------------------------------------------------------------
 */

static inline void *
    icl_mem_lockfree_alloc_ (
    size_t size,                        //  How much memory to allocate
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
icl_mem_lockfree_t
    *self;
    void *
        item = NULL;                    //  The returned client pointer

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_ALLOC))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%u\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_ALLOC))
    icl_stats_inc ("icl_mem_lockfree_alloc", &s_icl_mem_lockfree_alloc_stats);
#endif

    if (!s_direct_cache)
        icl_cache_initialise ();

    self = icl_mem_lockfree_new (size);
    if (self) {
        self->cache = s_direct_cache;
        self->size  = size;
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_LOCKFREE))
        icl_stats_inc (NULL, &s_direct_cache->allocs_stat);
#endif
        self->tag = ICL_CACHE_ALIVE;
        icl_mem_lockfree_cache_insert (s_direct_cache, self);
        item = (byte *) self + ICL_MEM_LOCKFREE_SIZE;
        icl_mem_lockfree_possess_ (item, file, line);
    }
#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_ALLOC))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%u\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size, file, line, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_realloc

    Type: Component method
    Adjust the size of the pointed to 'buffer' to the new 'size'.
    If 'buffer' is NULL, self call behaves as a regular alloc().
    -------------------------------------------------------------------------
 */

static inline void *
    icl_mem_lockfree_realloc_ (
    void * item,                        //  Cient buffer to reallocate
    qbyte size,                         //  How much memory to allocate
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
icl_mem_lockfree_t
    *self;

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_REALLOC))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_realloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" size=\"%lu\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, size, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_REALLOC))
    icl_stats_inc ("icl_mem_lockfree_realloc", &s_icl_mem_lockfree_realloc_stats);
#endif

if (item == NULL)
    item = icl_mem_lockfree_alloc_ (size, file, line);
else {
    self = (icl_mem_lockfree_t *) (((byte *) item) - ICL_MEM_LOCKFREE_SIZE);
    ICL_MEM_LOCKFREE_ASSERT_SANE (self, item);

    item = NULL;
    if (!self->cache->size) {       //  ie direct cache
        icl_mem_lockfree_cache_recycle (&self);
        self = (icl_mem_lockfree_t*) realloc (self, ICL_MEM_LOCKFREE_SIZE + size);
        if (self) {
            //  Need to reset the cache pointer(s) following realloc.
            icl_mem_lockfree_cache_reset (self);

            self->size  = size;
            self->tag = ICL_CACHE_ALIVE;
            icl_mem_lockfree_cache_insert (s_direct_cache, self);

            item = (byte *) self + ICL_MEM_LOCKFREE_SIZE;
        }
    }
}
#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_REALLOC))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_realloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" size=\"%lu\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, size, file, line);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_free

    Type: Component method
    Destroys an allocation block.
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_lockfree_free (
    void * item                         //  Client buffer to free
)
{
icl_mem_lockfree_t
    *self;

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_FREE))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_FREE))
    icl_stats_inc ("icl_mem_lockfree_free", &s_icl_mem_lockfree_free_stats);
#endif

    if (item) {
        self = (icl_mem_lockfree_t *) (((byte *) item) - ICL_MEM_LOCKFREE_SIZE);
        ICL_MEM_LOCKFREE_ASSERT_SANE (self, item);
        self->tag = ICL_CACHE_DEAD;

        icl_mem_lockfree_cache_recycle (&self);
        if (!self->cache->size) {       //  ie direct cache
            icl_mem_lockfree_destroy (&self);
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_LOCKFREE))
            icl_stats_inc (NULL, &s_direct_cache->frees_stat);
#endif
        }
    }
#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_FREE))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item);
#endif

}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_cache_insert

    Type: Component method
    This is a private method used by icl_mem_lockfree_cache_alloc.
    
    Its purpose is to record an allocator block in use.
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_lockfree_cache_insert (
    icl_cache_t * cache,                //  The cache for the allocation
    icl_mem_lockfree_t * self           //  The allocation block
)
{

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_INSERT))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_insert_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, self);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_INSERT))
    icl_stats_inc ("icl_mem_lockfree_cache_insert", &s_icl_mem_lockfree_cache_insert_stats);
#endif

#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_LOCKFREE))
    icl_stats_inc (NULL, &cache->used_stat);
#endif

#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    icl_atomic_inc32 (&cache->lockfree_used_count);
#endif
#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_INSERT))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_insert_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, self);
#endif

}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_cache_reuse

    Type: Component method
    This is a private method used by icl_mem_lockfree_cache_alloc.
    
    Its purpose is to find an allocator block from the cache for reuse.
    -------------------------------------------------------------------------
 */

static inline void *
    icl_mem_lockfree_cache_reuse_ (
    icl_cache_t * cache,                //  The cache for the allocation
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    void
        *context_as_void;
    icl_mem_lockfree_context_t
        *context;
#endif
    void *
        self = NULL;                    //  The returned client pointer

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_REUSE))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_reuse_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_REUSE))
    icl_stats_inc ("icl_mem_lockfree_cache_reuse", &s_icl_mem_lockfree_cache_reuse_stats);
#endif

#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    icl_apr_assert (apr_threadkey_private_get (&context_as_void, cache->lockfree_unused_list->key));
    context = context_as_void;
    if (!context) {
        context = malloc (sizeof (icl_mem_lockfree_context_t));
        context->my_node = NULL;
        context->my_ver  = 0;
        icl_apr_assert (apr_threadkey_private_set (context, cache->lockfree_unused_list->key));
    }

    self = dequeue (context, cache->lockfree_unused_list);
    if (self)
        icl_atomic_dec32 (&cache->lockfree_unused_count);
#endif
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_LOCKFREE))
    if (self)
        icl_stats_dec (NULL, &cache->unused_stat);
#endif
#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_REUSE))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_reuse_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_cache_recycle

    Type: Component method
    This is a private method used by icl_mem_lockfree_cache_alloc.
    
    Its purpose is put an allocated block in the unused list of the cache.
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_lockfree_cache_recycle (
    icl_mem_lockfree_t * ( * self_p )   //  The allocation block
)
{
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    void
        *context_as_void;
    icl_mem_lockfree_context_t
        *context;
#endif
    icl_mem_lockfree_t *
        self = *self_p;                 //  Dereferenced The allocation block
    icl_cache_t *
        cache = self->cache;            //  The cache for the allocation

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_RECYCLE))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_recycle_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_RECYCLE))
    icl_stats_inc ("icl_mem_lockfree_cache_recycle", &s_icl_mem_lockfree_cache_recycle_stats);
#endif

#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_LOCKFREE))
    icl_stats_dec (NULL, &cache->used_stat);
#endif
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    icl_apr_assert (apr_threadkey_private_get (&context_as_void, cache->lockfree_unused_list->key));
    context = context_as_void;
    if (!context) {
        context = malloc (sizeof (icl_mem_lockfree_context_t));
        context->my_node = NULL;
        context->my_ver  = 0;
        icl_apr_assert (apr_threadkey_private_set (context, cache->lockfree_unused_list->key));
    }

    icl_atomic_dec32 (&cache->lockfree_used_count);
    if (cache->size) {                  //  ie not direct cache
        set_to_be_enqueued (context, self);
        icl_atomic_inc32 (&cache->lockfree_unused_count);
    }
#else
    cache = cache;                      //  Avoid compilation warning
#endif
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_LOCKFREE))
    if (cache->size)                    //  ie not direct cache
        icl_stats_inc (NULL, &cache->unused_stat);
#endif
#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_RECYCLE))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_recycle_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" cache=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, cache);
#endif

}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_cache_reset

    Type: Component method
    This is a private method used by icl_mem_lockfree_cache_realloc.
    
    Its purpose is to reset the block's cache pointers following a realloc.
    Don't need to do anything.
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_lockfree_cache_reset (
    icl_mem_lockfree_t * self           //  The allocation block
)
{

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_RESET))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_reset_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_CACHE_RESET))
    icl_stats_inc ("icl_mem_lockfree_cache_reset", &s_icl_mem_lockfree_cache_reset_stats);
#endif

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_CACHE_RESET))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_cache_reset_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_possess

    Type: Component method
    Sets file and line number of memory allocation.
    Does nothing but required to get function declared
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_lockfree_possess_ (
    void * item,                        //  Client buffer to free
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_POSSESS))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_possess_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_POSSESS))
    icl_stats_inc ("icl_mem_lockfree_possess", &s_icl_mem_lockfree_possess_stats);
#endif

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_POSSESS))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_possess_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    icl_mem_lockfree_set_callback

    Type: Component method
    Sets callback of memory allocation.
    Does nothing but required to get function declared
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_lockfree_set_callback (
    void * item,                        //  Client buffer to free
    icl_callback_fn * callback          //  Callback function to set
)
{

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)  ||  defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_SET_CALLBACK))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_set_callback_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" callback=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, callback);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE)  ||  defined (BASE_STATS_ICL_MEM_LOCKFREE_SET_CALLBACK))
    icl_stats_inc ("icl_mem_lockfree_set_callback", &s_icl_mem_lockfree_set_callback_stats);
#endif

#if (defined (BASE_ANIMATE_ICL_MEM_LOCKFREE)   || defined (BASE_ANIMATE_ICL_MEM_LOCKFREE_SET_CALLBACK))
    if (icl_mem_lockfree_animating)
        icl_console_print ("<icl_mem_lockfree_set_callback_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" callback=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, callback);
#endif

}
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_MEM_LOCKFREE_ACTIVE
#   if defined (ICL_IMPORT_ICL_MEM_LOCKFREE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ICL_MEM_LOCKFREE_ROOT
#   endif
# endif
#endif
