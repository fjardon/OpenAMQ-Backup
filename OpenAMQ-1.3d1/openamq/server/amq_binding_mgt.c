/*---------------------------------------------------------------------------
    amq_binding_mgt.c - amq_binding_mgt component

This class shows one binding.
    Generated from amq_binding_mgt.icl by smt_object_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    
    This file is licensed under the GPL as follows:
    
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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "amq_binding_mgt.h"            //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_binding_mgt_t

//  Shorthands for class methods                                               

#define self_new            amq_binding_mgt_new
#define self_selftest       amq_binding_mgt_selftest
#define self_annihilate     amq_binding_mgt_annihilate
#define self_count          amq_binding_mgt_count
#define self_inspect_shim   amq_binding_mgt_inspect_shim
#define self_inspect        amq_binding_mgt_inspect
#define self_modify_shim    amq_binding_mgt_modify_shim
#define self_modify         amq_binding_mgt_modify
#define self_method_shim    amq_binding_mgt_method_shim
#define self_method         amq_binding_mgt_method
#define self_unlink_shim    amq_binding_mgt_unlink_shim
#define self_initialise     amq_binding_mgt_initialise
#define self_terminate      amq_binding_mgt_terminate
#define self_destroy        amq_binding_mgt_destroy
#define self_unlink         amq_binding_mgt_unlink
#define self_animate        amq_binding_mgt_animate
#define self_free           amq_binding_mgt_free
#define self_show           amq_binding_mgt_show
#define self_alloc          amq_binding_mgt_alloc
#define self_link           amq_binding_mgt_link
#define self_cache_initialise  amq_binding_mgt_cache_initialise
#define self_cache_purge    amq_binding_mgt_cache_purge
#define self_cache_terminate  amq_binding_mgt_cache_terminate
#define self_new_in_scope   amq_binding_mgt_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_NEW))
static icl_stats_t *s_amq_binding_mgt_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_SELFTEST))
static icl_stats_t *s_amq_binding_mgt_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_DESTROY))
static icl_stats_t *s_amq_binding_mgt_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_COUNT))
static icl_stats_t *s_amq_binding_mgt_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_INSPECT_SHIM))
static icl_stats_t *s_amq_binding_mgt_inspect_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_INSPECT))
static icl_stats_t *s_amq_binding_mgt_inspect_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_MODIFY_SHIM))
static icl_stats_t *s_amq_binding_mgt_modify_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_MODIFY))
static icl_stats_t *s_amq_binding_mgt_modify_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_METHOD_SHIM))
static icl_stats_t *s_amq_binding_mgt_method_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_METHOD))
static icl_stats_t *s_amq_binding_mgt_method_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_UNLINK_SHIM))
static icl_stats_t *s_amq_binding_mgt_unlink_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_INITIALISE))
static icl_stats_t *s_amq_binding_mgt_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_TERMINATE))
static icl_stats_t *s_amq_binding_mgt_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_DESTROY_PUBLIC))
static icl_stats_t *s_amq_binding_mgt_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_UNLINK))
static icl_stats_t *s_amq_binding_mgt_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_ANIMATE))
static icl_stats_t *s_amq_binding_mgt_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_FREE))
static icl_stats_t *s_amq_binding_mgt_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_SHOW))
static icl_stats_t *s_amq_binding_mgt_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_ALLOC))
static icl_stats_t *s_amq_binding_mgt_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_LINK))
static icl_stats_t *s_amq_binding_mgt_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_CACHE_INITIALISE))
static icl_stats_t *s_amq_binding_mgt_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_CACHE_PURGE))
static icl_stats_t *s_amq_binding_mgt_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_CACHE_TERMINATE))
static icl_stats_t *s_amq_binding_mgt_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_NEW_IN_SCOPE))
static icl_stats_t *s_amq_binding_mgt_new_in_scope_stats = NULL;
#endif
#define amq_binding_mgt_annihilate(self)  amq_binding_mgt_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_binding_mgt_annihilate_ (
amq_binding_mgt_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_binding_mgt_initialise (
void);

#define amq_binding_mgt_alloc()         amq_binding_mgt_alloc_ (__FILE__, __LINE__)
static amq_binding_mgt_t *
    amq_binding_mgt_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_binding_mgt_cache_initialise (
void);

static void
    amq_binding_mgt_cache_purge (
void);

static void
    amq_binding_mgt_cache_terminate (
void);

Bool
    amq_binding_mgt_animating = TRUE;   //  Animation enabled by default
static Bool
    s_amq_binding_mgt_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_binding_mgt_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static amq_console_class_t
    *s_class;                           //  Class descriptor
qbyte
    gbl_amq_binding_mgt_count = 0;
/*  -------------------------------------------------------------------------
    amq_binding_mgt_new

    Type: Component method
    Creates and initialises a new amq_binding_mgt_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_binding_mgt_t *
    amq_binding_mgt_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_exchange_t * exchange,          //  Parent exchange
    amq_binding_t * binding             //  Parent binding
)
{
    amq_binding_mgt_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_NEW))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" binding=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, exchange, binding);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_NEW))
    icl_trace_record (NULL, amq_binding_mgt_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_NEW))
    icl_stats_inc ("amq_binding_mgt_new", &s_amq_binding_mgt_new_stats);
#endif

if (!s_amq_binding_mgt_active)
    self_initialise ();
    self = amq_binding_mgt_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_BINDING_MGT_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_binding_mgt_show_);
#endif

self->console = amq_console_link (amq_console);
self->object_id = icl_atomic_inc32 ((volatile qbyte *) &amq_object_id);
amq_console_register (self->console, self->object_id, self_link (self), s_class, exchange->object_id);
self->thread = amq_binding_mgt_agent_class_thread_new (self);
self->thread->animate = TRUE;

icl_atomic_inc32 ((volatile qbyte *) &gbl_amq_binding_mgt_count);

//
self->exchange = exchange;
self->binding = binding;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_NEW))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_NEW))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" binding=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, exchange, binding, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_binding_mgt_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_SELFTEST))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_SELFTEST))
    icl_trace_record (NULL, amq_binding_mgt_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_SELFTEST))
    icl_stats_inc ("amq_binding_mgt_selftest", &s_amq_binding_mgt_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_SELFTEST))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_SELFTEST))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_selftest_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_binding_mgt_annihilate_ (
    amq_binding_mgt_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
    int
        history_last;
#endif

    amq_binding_mgt_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_DESTROY))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_DESTROY))
    icl_trace_record (NULL, amq_binding_mgt_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_DESTROY))
    icl_stats_inc ("amq_binding_mgt_annihilate", &s_amq_binding_mgt_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (amq_binding_mgt_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_binding_mgt agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_DESTROY))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_DESTROY))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_binding_mgt_count (
void)
{
    qbyte
        count;                          //  Number of instances

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_COUNT))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_count_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_COUNT))
    icl_trace_record (NULL, amq_binding_mgt_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_COUNT))
    icl_stats_inc ("amq_binding_mgt_count", &s_amq_binding_mgt_count_stats);
#endif

count = (int) gbl_amq_binding_mgt_count;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_COUNT))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_COUNT))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_count_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" count=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_inspect_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_binding_mgt_inspect_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_INSPECT_SHIM))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_inspect_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" request=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, request);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_INSPECT_SHIM))
    icl_trace_record (NULL, amq_binding_mgt_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_INSPECT_SHIM))
    icl_stats_inc ("amq_binding_mgt_inspect_shim", &s_amq_binding_mgt_inspect_shim_stats);
#endif

self_inspect ((amq_binding_mgt_t *) (self_v), request);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_INSPECT_SHIM))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_INSPECT_SHIM))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_inspect_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" request=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, request, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_inspect

    Type: Component method
    Accepts a amq_binding_mgt_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_binding_mgt_inspect (
    amq_binding_mgt_t * self,           //  Reference to object
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_INSPECT))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_inspect_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" request=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, request);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_INSPECT))
    icl_trace_record (NULL, amq_binding_mgt_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_INSPECT))
    icl_stats_inc ("amq_binding_mgt_inspect", &s_amq_binding_mgt_inspect_stats);
#endif

AMQ_BINDING_MGT_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_binding_mgt_agent_inspect (self->thread,request)) {
        //icl_console_print ("Error sending 'inspect' method to amq_binding_mgt agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_INSPECT))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_INSPECT))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_inspect_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" request=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, request, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_modify_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_binding_mgt_modify_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_MODIFY_SHIM))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_modify_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" request=\"%pp\""
" fields=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, request, fields);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_MODIFY_SHIM))
    icl_trace_record (NULL, amq_binding_mgt_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_MODIFY_SHIM))
    icl_stats_inc ("amq_binding_mgt_modify_shim", &s_amq_binding_mgt_modify_shim_stats);
#endif

self_modify ((amq_binding_mgt_t *) (self_v), request, fields);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_MODIFY_SHIM))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_MODIFY_SHIM))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_modify_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" request=\"%pp\""
" fields=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, request, fields, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_modify

    Type: Component method
    Accepts a amq_binding_mgt_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_binding_mgt_modify (
    amq_binding_mgt_t * self,           //  Reference to object
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_MODIFY))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_modify_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" request=\"%pp\""
" fields=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, request, fields);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_MODIFY))
    icl_trace_record (NULL, amq_binding_mgt_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_MODIFY))
    icl_stats_inc ("amq_binding_mgt_modify", &s_amq_binding_mgt_modify_stats);
#endif

AMQ_BINDING_MGT_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_binding_mgt_agent_modify (self->thread,request,fields)) {
        //icl_console_print ("Error sending 'modify' method to amq_binding_mgt agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_MODIFY))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_MODIFY))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_modify_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" request=\"%pp\""
" fields=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, request, fields, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_method_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_binding_mgt_method_shim (
    void * self_v,                      //  Object cast as a void *
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_METHOD_SHIM))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_method_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" method_name=\"%s\""
" request=\"%pp\""
" fields=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, method_name, request, fields);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_METHOD_SHIM))
    icl_trace_record (NULL, amq_binding_mgt_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_METHOD_SHIM))
    icl_stats_inc ("amq_binding_mgt_method_shim", &s_amq_binding_mgt_method_shim_stats);
#endif

self_method ((amq_binding_mgt_t *) (self_v), method_name, request, fields);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_METHOD_SHIM))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_METHOD_SHIM))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_method_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" method_name=\"%s\""
" request=\"%pp\""
" fields=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, method_name, request, fields, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_method

    Type: Component method
    Accepts a amq_binding_mgt_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_binding_mgt_method (
    amq_binding_mgt_t * self,           //  Reference to object
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Argument fields
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_METHOD))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_method_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method_name=\"%s\""
" request=\"%pp\""
" fields=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method_name, request, fields);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_METHOD))
    icl_trace_record (NULL, amq_binding_mgt_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_METHOD))
    icl_stats_inc ("amq_binding_mgt_method", &s_amq_binding_mgt_method_stats);
#endif

AMQ_BINDING_MGT_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_binding_mgt_agent_method (self->thread,method_name,request,fields)) {
        //icl_console_print ("Error sending 'method' method to amq_binding_mgt agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_METHOD))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_METHOD))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_method_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method_name=\"%s\""
" request=\"%pp\""
" fields=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method_name, request, fields, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_unlink_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_binding_mgt_unlink_shim (
    void * object_p                     //  Reference pointer cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_UNLINK_SHIM))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_unlink_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" object_p=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, object_p);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_UNLINK_SHIM))
    icl_trace_record (NULL, amq_binding_mgt_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_UNLINK_SHIM))
    icl_stats_inc ("amq_binding_mgt_unlink_shim", &s_amq_binding_mgt_unlink_shim_stats);
#endif

//
amq_binding_mgt_unlink (((amq_binding_mgt_t **) object_p));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_UNLINK_SHIM))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_UNLINK_SHIM))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_unlink_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" object_p=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, object_p);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_binding_mgt_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_INITIALISE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_INITIALISE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_INITIALISE))
    icl_stats_inc ("amq_binding_mgt_initialise", &s_amq_binding_mgt_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_binding_mgt_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_binding_mgt_mutex)
            s_amq_binding_mgt_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_binding_mgt_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_binding_mgt_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_binding_mgt_agent_init ();

s_class = amq_console_class_new ();
s_class->name    = "binding";
s_class->inspect = amq_binding_mgt_inspect_shim;
s_class->modify  = amq_binding_mgt_modify_shim;
s_class->method  = amq_binding_mgt_method_shim;
s_class->unlink  = amq_binding_mgt_unlink_shim;
            s_amq_binding_mgt_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_binding_mgt_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_INITIALISE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_INITIALISE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_initialise_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_binding_mgt_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_TERMINATE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_TERMINATE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_TERMINATE))
    icl_stats_inc ("amq_binding_mgt_terminate", &s_amq_binding_mgt_terminate_stats);
#endif

if (s_amq_binding_mgt_active) {

amq_console_class_destroy (&s_class);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_binding_mgt_mutex);
#endif
        s_amq_binding_mgt_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_TERMINATE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_TERMINATE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_binding_mgt_destroy_ (
    amq_binding_mgt_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_binding_mgt_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_DESTROY_PUBLIC))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_binding_mgt_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_DESTROY_PUBLIC))
    icl_stats_inc ("amq_binding_mgt_destroy", &s_amq_binding_mgt_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = amq_binding_mgt_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_binding_mgt_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_DESTROY_PUBLIC))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" rc=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, rc, self?self->links:0, self?self->zombie:0);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_binding_mgt_unlink_ (
    amq_binding_mgt_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
    int
        history_last;
#endif
    amq_binding_mgt_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_UNLINK))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_unlink_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_UNLINK))
    icl_trace_record (NULL, amq_binding_mgt_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_UNLINK))
    icl_stats_inc ("amq_binding_mgt_unlink", &s_amq_binding_mgt_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_binding_mgt object");
            amq_binding_mgt_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_binding_mgt_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_binding_mgt_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_UNLINK))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_UNLINK))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_unlink_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_binding_mgt_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_ANIMATE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_animate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_ANIMATE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_ANIMATE))
    icl_stats_inc ("amq_binding_mgt_animate", &s_amq_binding_mgt_animate_stats);
#endif

amq_binding_mgt_animating = enabled;

amq_binding_mgt_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_ANIMATE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_ANIMATE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_animate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_free

    Type: Component method
    Freess a amq_binding_mgt_t object.
    -------------------------------------------------------------------------
 */

void
    amq_binding_mgt_free_ (
    amq_binding_mgt_t * self,           //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_FREE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_FREE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_FREE))
    icl_stats_inc ("amq_binding_mgt_free", &s_amq_binding_mgt_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (amq_binding_mgt_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_binding_mgt_t));
        self->object_tag = AMQ_BINDING_MGT_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_FREE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_FREE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_binding_mgt_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_binding_mgt_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_SHOW))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_show_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_SHOW))
    icl_trace_record (NULL, amq_binding_mgt_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_SHOW))
    icl_stats_inc ("amq_binding_mgt_show", &s_amq_binding_mgt_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_binding_mgt zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
    if (self->history_last > AMQ_BINDING_MGT_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_BINDING_MGT_HISTORY_LENGTH;
        self->history_last %= AMQ_BINDING_MGT_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_BINDING_MGT_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_binding_mgt>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_SHOW))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_SHOW))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_show_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_binding_mgt_t *
    amq_binding_mgt_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_binding_mgt_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_ALLOC))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_ALLOC))
    icl_trace_record (NULL, amq_binding_mgt_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_ALLOC))
    icl_stats_inc ("amq_binding_mgt_alloc", &s_amq_binding_mgt_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_binding_mgt_cache_initialise ();

self = (amq_binding_mgt_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_binding_mgt_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_ALLOC))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_ALLOC))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_binding_mgt_t *
    amq_binding_mgt_link_ (
    amq_binding_mgt_t * self,           //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_LINK))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_link_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_LINK))
    icl_trace_record (NULL, amq_binding_mgt_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_LINK))
    icl_stats_inc ("amq_binding_mgt_link", &s_amq_binding_mgt_link_stats);
#endif

    if (self) {
        AMQ_BINDING_MGT_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BINDING_MGT)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_BINDING_MGT_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_LINK))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_LINK))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_link_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_binding_mgt_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_CACHE_INITIALISE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_CACHE_INITIALISE))
    icl_stats_inc ("amq_binding_mgt_cache_initialise", &s_amq_binding_mgt_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_binding_mgt_t));
icl_system_register (amq_binding_mgt_cache_purge, amq_binding_mgt_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_CACHE_INITIALISE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_cache_initialise_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_binding_mgt_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_CACHE_PURGE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_CACHE_PURGE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_CACHE_PURGE))
    icl_stats_inc ("amq_binding_mgt_cache_purge", &s_amq_binding_mgt_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_CACHE_PURGE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_CACHE_PURGE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_cache_purge_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_binding_mgt_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_CACHE_TERMINATE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_CACHE_TERMINATE))
    icl_stats_inc ("amq_binding_mgt_cache_terminate", &s_amq_binding_mgt_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_CACHE_TERMINATE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_cache_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_binding_mgt_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_binding_mgt_new_in_scope_ (
    amq_binding_mgt_t * * self_p,       //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_exchange_t * exchange,          //  Parent exchange
    amq_binding_t * binding             //  Parent binding
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT)  ||  defined (BASE_ANIMATE_AMQ_BINDING_MGT_NEW_IN_SCOPE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" binding=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, exchange, binding);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_BINDING_MGT)  ||  defined (BASE_STATS_AMQ_BINDING_MGT_NEW_IN_SCOPE))
    icl_stats_inc ("amq_binding_mgt_new_in_scope", &s_amq_binding_mgt_new_in_scope_stats);
#endif

*self_p = amq_binding_mgt_new_ (file,line,exchange,binding);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_binding_mgt_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_binding_mgt_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT)   || defined (BASE_ANIMATE_AMQ_BINDING_MGT_NEW_IN_SCOPE))
    if (amq_binding_mgt_animating)
        icl_console_print ("<amq_binding_mgt_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" binding=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, exchange, binding, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_BINDING_MGT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_NEW)   || defined (BASE_TRACE_AMQ_BINDING_MGT_SELFTEST)   || defined (BASE_TRACE_AMQ_BINDING_MGT_DESTROY)   || defined (BASE_TRACE_AMQ_BINDING_MGT_COUNT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_INSPECT_SHIM)   || defined (BASE_TRACE_AMQ_BINDING_MGT_INSPECT)   || defined (BASE_TRACE_AMQ_BINDING_MGT_MODIFY_SHIM)   || defined (BASE_TRACE_AMQ_BINDING_MGT_MODIFY)   || defined (BASE_TRACE_AMQ_BINDING_MGT_METHOD_SHIM)   || defined (BASE_TRACE_AMQ_BINDING_MGT_METHOD)   || defined (BASE_TRACE_AMQ_BINDING_MGT_UNLINK_SHIM)   || defined (BASE_TRACE_AMQ_BINDING_MGT_INITIALISE)   || defined (BASE_TRACE_AMQ_BINDING_MGT_TERMINATE)   || defined (BASE_TRACE_AMQ_BINDING_MGT_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_BINDING_MGT_UNLINK)   || defined (BASE_TRACE_AMQ_BINDING_MGT_ANIMATE)   || defined (BASE_TRACE_AMQ_BINDING_MGT_FREE)   || defined (BASE_TRACE_AMQ_BINDING_MGT_SHOW)   || defined (BASE_TRACE_AMQ_BINDING_MGT_ALLOC)   || defined (BASE_TRACE_AMQ_BINDING_MGT_LINK)   || defined (BASE_TRACE_AMQ_BINDING_MGT_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_BINDING_MGT_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_BINDING_MGT_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_BINDING_MGT_NEW_IN_SCOPE) )
void
amq_binding_mgt_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "selftest"; break;
        case 3: method_name = "destroy"; break;
        case 4: method_name = "count"; break;
        case 5: method_name = "inspect shim"; break;
        case 6: method_name = "inspect"; break;
        case 7: method_name = "modify shim"; break;
        case 8: method_name = "modify"; break;
        case 9: method_name = "method shim"; break;
        case 10: method_name = "method"; break;
        case 11: method_name = "unlink shim"; break;
        case 12: method_name = "initialise"; break;
        case 13: method_name = "terminate"; break;
        case 14: method_name = "destroy public"; break;
        case 15: method_name = "unlink"; break;
        case 16: method_name = "animate"; break;
        case 17: method_name = "free"; break;
        case 18: method_name = "show"; break;
        case 19: method_name = "alloc"; break;
        case 20: method_name = "link"; break;
        case 21: method_name = "cache initialise"; break;
        case 22: method_name = "cache purge"; break;
        case 23: method_name = "cache terminate"; break;
        case 24: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_binding_mgt %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_binding_mgt_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_binding_mgt_component    = "amq_binding_mgt ";
char *amq_binding_mgt_version      = "1.0 ";
char *amq_binding_mgt_copyright    = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_binding_mgt_filename     = "amq_binding_mgt.icl ";
char *amq_binding_mgt_builddate    = "2010/10/06 ";
char *amq_binding_mgt_version_end  = "VeRsIoNeNd:ipc";

