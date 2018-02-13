<?xml?>
<!--
    Copyright (c) 1996-2009 iMatix Corporation

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at
    your option) any later version.

    This program is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    For information on alternative licensing for OEMs, please contact
    iMatix Corporation.
 -->
<class
    name      = "icl_lfcontext"
    comment   = "Class to hold lock-free context"
    version   = "1.1"
    script    = "icl_gen"
    >

<doc>
    This class holds the thread-local context for lock-free functions.
</doc>

<public>
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
</public>

<public name = "inline">
#if defined (__i386__)

static inline Bool cas_ptr (volatile void **mem, 
              void *cmp,
              void *with)
{
    unsigned char
        result;

    asm volatile ("lock; cmpxchgl %2, %3\\n\\t"
                  "setz %1\\n\\t"
                  "sfence\\n\\t"
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

    asm volatile ("mov 4(%3), %%edx\\n\\t"
                  "mov  (%3), %3\\n\\t"
                  "mov 4(%4), %%ecx\\n\\t"
                  "mov  (%4), %4\\n\\t"
                  "lock; cmpxchg8b %2\\n\\t"
                  "setz %1\\n\\t"
                  "sfence\\n\\t"
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

    asm volatile ("mov 4(%3), %%edx\\n\\t"
                  "mov  (%3), %3\\n\\t"
                  "mov 4(%4), %%ecx\\n\\t"
                  "mov  (%4), %4\\n\\t"
                  "lock; cmpxchg8b %2\\n\\t"
                  "setz %1\\n\\t"
                  "sfence\\n\\t"
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
    fprintf (stderr, "Lockfree is unavailable.\\n");
    abort ();
    return 0;
}

static inline Bool cas_entry_tag_t (volatile entry_tag_t *mem, 
                             entry_tag_t cmp,
                             entry_tag_t with)
{
    fprintf (stderr, "Lockfree is unavailable.\\n");
    abort ();
    return 0;
}

static inline Bool cas_exit_tag_t (volatile exit_tag_t *mem, 
                            exit_tag_t cmp,
                            exit_tag_t with)
{
    fprintf (stderr, "Lockfree is unavailable.\\n");
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
</public>

<inherit class = "icl_object">
    <option name = "mutex" value = "0"/>
    <option name = "links" value = "0"/>
    <option name = "alloc" value = "cache"/>
</inherit>

<inherit name = "icl_list_item">
    <option name = "mutex" value = "1"/>
</inherit>

<context>
    apr_uint32_t
        my_ver;
    volatile icl_lfqueue_node_t
        *my_node;
    icl_lfqueue_node_t
        *cache;
</context>

<method name = "destroy">
    <local>
    icl_lfqueue_node_t
        *node;
    </local>
    while (self->cache) {
        node = self->cache;
        self->cache = (icl_lfqueue_node_t *) self->cache->next;
        icl_mem_free (node);
    }
</method>

<method name = "selftest" export = "none"/>

</class>
