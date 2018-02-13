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
    name      = "icl_queue_head"
    comment   = "Abstract base class for queue head container"
    version   = "1.0"
    script    = "icl_gen"
    abstract  = "1"
    >
<doc>
    Abstract base class for queue head container
</doc>

<inherit name = "icl_object"/>

<import class = "icl_lfcontext_list" condition = "boom_lockfree"/>

<context>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    apr_pool_t
        *pool;
    apr_threadkey_t
        *key;                           //  For thread-local data
    volatile llsc_t
        *head,
        *tail;
    icl_lfcontext_list_t
        *contexts;                      //  One context per OS thread
#else
    volatile $(childtype)
        *head,
        *tail;
#    if defined (BASE_THREADSAFE)
    icl_mutex_t *
        mutex;
#    endif
#endif
.if count ? 0
    volatile qbyte
        count;
.endif
</context>

<private>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
static icl_cache_t
    *s_node_cache = NULL,
    *s_llsc_cache = NULL;
#endif
</private>

<method name = "new">
    <local>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    icl_lfqueue_node_t
        *initial_node_0,
        *initial_node_1;
    exit_tag_t
        initial_exit_tag_0 = {0, 2, 0, -1, 0},
        initial_exit_tag_1 = {0, 0, 0, -1, 0};
    icl_lfcontext_t
        *context;
#endif
    </local>        
    <header export = "after">
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    initial_node_0 = icl_mem_cache_alloc (s_node_cache);
    initial_node_1 = icl_mem_cache_alloc (s_node_cache);
    
    initial_node_0->next     = NULL;
    initial_node_0->prev     = initial_node_1;
    initial_node_0->exit_tag = initial_exit_tag_0;
    initial_node_0->zombie   = FALSE;
    initial_node_0->item     = NULL;
    
    initial_node_1->next     = NULL;
    initial_node_1->prev     = NULL;
    initial_node_1->exit_tag = initial_exit_tag_1;
    initial_node_0->zombie   = FALSE;
    initial_node_1->item     = NULL;

    self->head              = icl_mem_cache_alloc (s_llsc_cache);
    self->head->ptr0        = initial_node_0;
    self->head->ptr1        = initial_node_1;
    self->head->entry.ver   = 0;
    self->head->entry.count = 0;

    self->tail              = icl_mem_cache_alloc (s_llsc_cache);
    self->tail->ptr0        = initial_node_0;
    self->tail->ptr1        = initial_node_1;
    self->tail->entry.ver   = 0;
    self->tail->entry.count = 0;

    self->contexts = icl_lfcontext_list_new ();
    
    icl_apr_assert (apr_pool_create (&self->pool, icl_global_pool));
    apr_pool_tag   (self->pool, "$(selfname)_$(method.name)");
    icl_apr_assert (apr_threadkey_private_create (&self->key, NULL, self->pool));
    
    context = icl_lfcontext_new ();
    context->my_node = NULL;
    context->my_ver  = 0;
    icl_apr_assert (apr_threadkey_private_set (context, self->key));
    context->cache   = NULL;
    icl_lfcontext_list_queue (self->contexts, context);
#else
#     if (defined (BASE_THREADSAFE))
    self->mutex = icl_mutex_new ();
#    endif

    self->head = NULL;
    self->tail = NULL;
#endif

.if count ? 0
    self->count = 0;
.endif
    </header>
</method>

<method name = "destroy">
    <doc>
    Destroys the queue and unlinks all attached items.
    </doc>
    <local>
    $(childtype)
        *item;
#if defined (BASE_THREADSAFE)
#    if defined (BASE_LOCKFREE)
    icl_lfqueue_node_t
        *node;
    icl_lfcontext_t
        *context;
    volatile icl_lfqueue_node_t
        *head;
#    else
    icl_mutex_t
        *mutex;
#    endif
#endif
    </local>
    <header>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    //  We copy the popping code because the zombie field is not set which
    //  makes the _pop method do nothing.
    do {
        icl_apr_assert (apr_threadkey_private_get ((void **) &context, self->key));
        if (!context) {
            context = icl_lfcontext_new ();
            context->my_node = NULL;
            context->my_ver  = 0;
            icl_apr_assert (apr_threadkey_private_set (context, self->key));
            icl_lfcontext_list_queue (self->contexts, context);
        }
        item = NULL;
        FOREVER {
            head = ll (context, self->head);
            node = (icl_lfqueue_node_t *) head->next;
            if (node == NULL) {
                un_link (context, self->head);
                break;
            }
            if (sc (context, self->head, (void *) node)) {
                item = node->item;
                set_to_be_freed (context, node);
                break;
            }
        }
        
        if (item)
.if ! (child_has_links ? 1)
            $(childname)_destroy (&item);
.elsif link_to_child ? 1
            $(childname)_unlink (&item);
.endif
    } while (item);

    icl_mem_free ((icl_lfqueue_node_t * ) self->head->ptr0);
    icl_mem_free ((icl_lfqueue_node_t * ) self->head->ptr1);
    
    icl_mem_free ((void *) self->head);
    icl_mem_free ((void *) self->tail);
    
    icl_lfcontext_list_destroy (&self->contexts);
    icl_apr_assert (apr_threadkey_private_delete (self->key));
    apr_pool_destroy (self->pool);
#else
#    if defined (BASE_THREADSAFE)
    mutex = self->mutex;
    if (mutex)
         icl_mutex_lock (mutex);
#   endif

    <!-- NB we can't call pop because this will create deadlock             -->
    item = ($(childtype) *) self->head;
    while (item != NULL) {
        //  Unlink child without lock (we already have the lock)               
        self->head = item->$(prefix)_next;
        
.if link_to_child ? child_has_links ? 1
        $(childname)_unlink (&item);
.else
        $(childname)_destroy (&item);
.endif
        item = ($(childtype) *) self->head;
    }
#endif
    </header>
    <footer>
#if defined (BASE_THREADSAFE) && ! defined (BASE_LOCKFREE)
    if (mutex)
        icl_mutex_unlock (mutex);
#endif
    </footer>
</method>

<method name = "free">
    <footer>
#if defined (BASE_THREADSAFE) && ! defined (BASE_LOCKFREE)
    if (self->mutex)
        icl_mutex_destroy (&self->mutex);
#endif
    </footer>
</method>

<method name = "pop" return = "item">
    <argument name = "self" type = "$(selftype) *">The queue</argument>
    <declare name = "item"  type = "$(childtype) *" default = "NULL"/>
    <doc>
    Removes the next item in the queue, if any, and returns it.  If
    the queue was empty, returns NULL.
    
    The number of links is unchanged; removing from the queue and returning
    the value cancel each other out.
    </doc>
    <local>
#if defined (BASE_THREADSAFE)
#    if defined (BASE_LOCKFREE)
    icl_lfqueue_node_t
        *node;
    icl_lfcontext_t
        *context;
    volatile icl_lfqueue_node_t
        *head;
#    else
    icl_mutex_t
        *mutex;
#    endif
#endif
    </local>
    <header>
    $(selfname:upper)_ASSERT_SANE (self);
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
.if links ? 0
    if (!self->zombie) {
.endif
        icl_apr_assert (apr_threadkey_private_get ((void **) &context, self->key));
        if (!context) {
            context = icl_lfcontext_new ();
            context->my_node = NULL;
            context->my_ver  = 0;
            icl_apr_assert (apr_threadkey_private_set (context, self->key));
            icl_lfcontext_list_queue (self->contexts, context);
        }
        
        FOREVER {
            head = ll (context, self->head);
            node = (icl_lfqueue_node_t *) head->next;
            if (node == NULL) {
                un_link (context, self->head);
                break;
            }
            if (sc (context, self->head, (void *) node)) {
                item = node->item;
                set_to_be_freed (context, node);
                break;
            }
        }
#else
#   if defined (BASE_THREADSAFE)
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#   endif

.if links ? 0
    if (!self->zombie) {
.endif
        item = ($(childtype) *) self->head;
        if (item) {
            self->head = item->$(prefix)_next;
            if (self->head == NULL)
                self->tail = NULL;
            item->$(prefix)_next = NULL;
            item->$(prefix)_head = NULL;
        }

#endif
.
        if (item) {
.
.#  If we are linking to the child then links are unchanged, but if we aren't
.#  then this method is creating a new link.
.if (child_has_links ? 1) & ! (link_to_child ? 1)
            $(childname)_link (item);
.endif
.
.if count ? 0
            icl_atomic_dec32 (&self->count);
.endif
        }
    </header>
    <footer>
.if links ? 0
    }
.endif

#if defined (BASE_THREADSAFE) && ! defined (BASE_LOCKFREE)
    if (mutex)
        icl_mutex_unlock (mutex);
#endif
    </footer>
</method>

<method name = "queue" return = "rc" >
    <doc>
    Attaches the item to the end of the specified queue.  The item may not
    be in a queue of the same class.
    
    The number of links is automatically adjusted - if the item was already
    in the queue, it remains unchanged; otherwise it is incremented.
    </doc>
    <argument name = "self" type = "$(selftype) *">Reference to object</argument>
    <argument name = "item" type = "$(childtype) *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    <local>
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    icl_lfqueue_node_t
        *node;
    icl_lfcontext_t
        *context;
    exit_tag_t
        init_exit_tag = INIT_EXIT;
    volatile icl_lfqueue_node_t
        *tail;
#else
#   if defined (BASE_THREADSAFE)
    icl_mutex_t
        *mutex;
#   endif
#endif
    </local>
    <header>
#if defined (BASE_THREADSAFE) && ! defined (BASE_LOCKFREE)
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

    $(selfname:upper)_ASSERT_SANE (self);
.if links ? 0
    if (!self->zombie) {
.endif

#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
.
.if link_to_child ? child_has_links ? 1
        $(childname)_link (item);
.endif

        icl_apr_assert (apr_threadkey_private_get ((void **) &context, self->key));
        if (!context) {
            context = icl_lfcontext_new ();
            context->my_node = NULL;
            context->my_ver  = 0;
            icl_apr_assert (apr_threadkey_private_set (context, self->key));
            context->cache   = NULL;
            icl_lfcontext_list_queue (self->contexts, context);
        }
        
        node = context->cache;
        if (node)
            context->cache = (icl_lfqueue_node_t *) node->next;
        else
            node = icl_mem_cache_alloc (s_node_cache);
            
        node->zombie   = FALSE;
        node->item     = item;
        node->next     = NULL;
        node->exit_tag = init_exit_tag;
        FOREVER {
            tail = ll (context, self->tail);
            node->prev = tail;
            if (cas_ptr ((volatile void **) &tail->next, NULL, (void *) node)) {
                sc (context, self->tail, (void *) node);
                break;
            }
            else
                sc (context, self->tail, (void *) tail->next);
        }
#else
        if (! item->$(prefix)_head) {
.if link_to_child ? child_has_links ? 1
            $(childname)_link (item);
.endif
            
            if (self->tail)
                self->tail->$(prefix)_next = item;
            else
                self->head = item;
            self->tail = item;
            item->$(prefix)_next = NULL;
            item->$(prefix)_head = self;
        }
        else {
            //  Requeuing into the same queue isn't allowed.
            icl_console_print ("E: $(childname) item inserted into multiple $(prefix) containers");
            assert (item->$(prefix)_head == NULL);
        }
        
#endif
.if count ? 0
        icl_atomic_inc32 (&self->count);
.endif
    </header>
    <footer>
.if links ? 0
    }
    else
        rc = -1;
.endif

#if defined (BASE_THREADSAFE) && ! defined (BASE_LOCKFREE)
    if (mutex)
        icl_mutex_unlock (mutex);
#endif
    </footer>
</method>

<method name = "cache initialise">
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    s_node_cache = icl_cache_get (sizeof (icl_lfqueue_node_t));
    s_llsc_cache = icl_cache_get (sizeof (llsc_t));
#endif
</method>

<method name = "cache purge">
#if defined (BASE_THREADSAFE) && defined (BASE_LOCKFREE)
    icl_mem_cache_purge (s_node_cache);
    icl_mem_cache_purge (s_llsc_cache);
#endif
</method>

</class>
