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
    name      = "icl_mem_lockfree"
    comment   = "iPR memory class including caching"
    version   = "1.1"
    script    = "icl_gen"
    >

<doc>
    A lightweight memory allocator using lock-free freelists.
</doc>

<inherit class = "icl_mem_lib" />

<import class = "icl_lfcontext"/>

<context>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    volatile icl_mem_lockfree_t
        *next,
        *prev;
    volatile freelist_exit_tag_t 
        exit_tag;
#endif
</context>

<public name = "types">
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
</public>

<public name = "inline">
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)

#if defined (__i386__)
static inline Bool cas_freelist_exit_tag_t (volatile freelist_exit_tag_t *mem, 
              freelist_exit_tag_t cmp,
              freelist_exit_tag_t with)
{
    unsigned char
        result;

    asm volatile ("mov 4(%3), %%edx;             \
                   mov (%3), %3;                 \
                   mov 4(%4), %%ecx;             \
                   mov (%4), %4;                 \
                   lock; cmpxchg8b %2; setz %1; sfence"             
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
    fprintf (stderr, "Lockfree is unavailable.\\n");
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
</public>

<option name = "trace" value = "0"/>

<import class = "icl_cache" />

<method name = "cache alloc"  inline = "1"/>
<method name = "alloc"        inline = "1"/>
<method name = "realloc"      inline = "1"/>
<method name = "free"         inline = "1"/>

<method name = "list new" return = "self">
    <declare name = "self" type = "icl_mem_lockfree_list_t *" default = "NULL"/>
    <local>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    icl_mem_lockfree_t
        *initial_node_0,
        *initial_node_1;
    freelist_exit_tag_t
        initial_exit_tag_0 = {0, 2, 0, 0, 0},
        initial_exit_tag_1 = {0, 0, 0, 0, 0};
#endif
    </local>        
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    initial_node_0 = malloc (sizeof (icl_mem_lockfree_t));
    initial_node_1 = malloc (sizeof (icl_mem_lockfree_t));
    
    initial_node_0->next     = NULL;
    initial_node_0->prev     = initial_node_1;
    initial_node_0->exit_tag = initial_exit_tag_0;
    
    initial_node_1->next     = NULL;
    initial_node_1->prev     = NULL;
    initial_node_1->exit_tag = initial_exit_tag_1;
    
    self = malloc (sizeof (icl_mem_lockfree_list_t));

    self->head                 = malloc (sizeof (freelist_llsc_t));
    self->head->ptr0           = initial_node_0;
    self->head->ptr1           = initial_node_1;
    self->head->entry.ver      = 0;
    self->head->entry.count    = 0;

    self->tail                  = malloc (sizeof (freelist_llsc_t));
    self->tail->ptr0            = initial_node_0;
    self->tail->ptr1            = initial_node_1;
    self->tail->entry.ver       = 0;
    self->tail->entry.count     = 0;

    icl_apr_assert (apr_threadkey_private_create (&self->key, NULL, icl_global_pool));
#endif
</method>

<method name = "list destroy">
    <argument name = "self" ref = "1" type = "icl_mem_lockfree_list_t *"/>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    free ((icl_mem_lockfree_t *) self->head);
    free ((icl_mem_lockfree_t *) self->tail);
    icl_apr_assert (apr_threadkey_private_delete (self->key));
    free (self);
#else
    self = NULL;                        //  To avoid compilation warning
#endif
    *self_p = NULL;
</method>

<method name = "cache insert" private = "0" inline = "1">
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    icl_atomic_inc32 (&cache->lockfree_used_count);
#endif
</method>

<method name = "cache reuse" private = "0" inline = "1">
    <local>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    void
        *context_as_void;
    icl_mem_lockfree_context_t
        *context;
#endif
    </local>
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
</method>

<method name = "new">
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    self->exit_tag.nl_p = TRUE;
#endif
</method>

<method name = "cache recycle" private = "0" inline = "1">
    <local>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    void
        *context_as_void;
    icl_mem_lockfree_context_t
        *context;
#endif
    </local>
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
</method>

<method name = "cache purge">
    <local>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    qbyte
        target_unused_count;
    $(selftype)
        *self;
#endif
    </local>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    target_unused_count = icl_atomic_get32 (&cache->lockfree_unused_count) / 2;
    while (cache->lockfree_unused_count > target_unused_count) {
        self = $(selfname)_cache_reuse (cache);
        if (self)
            $(selfname)_destroy (&self);
        else
            break;
    }
#endif
</method>

<method name = "cache reset" private = "0" inline = "1">
    <doc>
    Don't need to do anything.
    </doc>
</method>

<method name = "cache assert">
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    if (cache->lockfree_used_count) {
        rc = -1;
        icl_console_print ("E: %lu active cache allocations of size: %lu.",
                           (long) cache->lockfree_used_count, (long) cache->size);
        icl_console_print ("E: Rebuild with fat memory allocator for details");
    }
#endif
</method>

<method name = "show" inherit = "none" />

<method name = "possess" inline = "1">
    <doc>
    Does nothing but required to get function declared
    </doc>
</method>

<method name = "set callback" inline = "1">
    <doc>
    Does nothing but required to get function declared
    </doc>
</method>

<method name = "selftest" export = "none">
    <local>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)

#if defined (__i386__)
    icl_cache_t
        *cache;
    void
        *buffer;
#endif
#endif
    </local>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)

#if defined (__i386__)
    cache  = icl_cache_get (500);
    buffer = icl_mem_lockfree_cache_alloc (cache);
    icl_mem_lockfree_free (buffer);
#endif

#endif
</method>

</class>
