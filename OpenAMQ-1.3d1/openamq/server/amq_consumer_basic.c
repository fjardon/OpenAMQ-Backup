/*---------------------------------------------------------------------------
    amq_consumer_basic.c - amq_consumer_basic component

This class implements a Basic consumer.  For now, an empty object.
    Generated from amq_consumer_basic.icl by icl_gen using GSL/4.
    
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
#include "amq_consumer_basic.h"         //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_consumer_basic_t

//  Shorthands for class methods                                               

#define self_new            amq_consumer_basic_new
#define self_selftest       amq_consumer_basic_selftest
#define self_terminate      amq_consumer_basic_terminate
#define self_show           amq_consumer_basic_show
#define self_destroy        amq_consumer_basic_destroy
#define self_annihilate     amq_consumer_basic_annihilate
#define self_alloc          amq_consumer_basic_alloc
#define self_free           amq_consumer_basic_free
#define self_cache_initialise  amq_consumer_basic_cache_initialise
#define self_cache_purge    amq_consumer_basic_cache_purge
#define self_cache_terminate  amq_consumer_basic_cache_terminate
#define self_animate        amq_consumer_basic_animate
#define self_new_in_scope   amq_consumer_basic_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_NEW))
static icl_stats_t *s_amq_consumer_basic_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_SELFTEST))
static icl_stats_t *s_amq_consumer_basic_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_TERMINATE))
static icl_stats_t *s_amq_consumer_basic_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_SHOW))
static icl_stats_t *s_amq_consumer_basic_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_DESTROY_PUBLIC))
static icl_stats_t *s_amq_consumer_basic_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_DESTROY))
static icl_stats_t *s_amq_consumer_basic_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_ALLOC))
static icl_stats_t *s_amq_consumer_basic_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_FREE))
static icl_stats_t *s_amq_consumer_basic_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_CACHE_INITIALISE))
static icl_stats_t *s_amq_consumer_basic_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_CACHE_PURGE))
static icl_stats_t *s_amq_consumer_basic_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_CACHE_TERMINATE))
static icl_stats_t *s_amq_consumer_basic_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_ANIMATE))
static icl_stats_t *s_amq_consumer_basic_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_NEW_IN_SCOPE))
static icl_stats_t *s_amq_consumer_basic_new_in_scope_stats = NULL;
#endif
static void
    amq_consumer_basic_annihilate (
amq_consumer_basic_t * ( * self_p )     //  Reference to object reference
);

#define amq_consumer_basic_alloc()      amq_consumer_basic_alloc_ (__FILE__, __LINE__)
static amq_consumer_basic_t *
    amq_consumer_basic_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_consumer_basic_free (
amq_consumer_basic_t * self             //  Object reference
);

static void
    amq_consumer_basic_cache_initialise (
void);

static void
    amq_consumer_basic_cache_purge (
void);

static void
    amq_consumer_basic_cache_terminate (
void);

Bool
    amq_consumer_basic_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    amq_consumer_basic_new

    Type: Component method
    Creates and initialises a new amq_consumer_basic_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_consumer_basic_t *
    amq_consumer_basic_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_consumer_t * consumer           //  Parent consumer
)
{
    amq_consumer_basic_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_NEW))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" consumer=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, consumer);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_NEW))
    icl_trace_record (NULL, amq_consumer_basic_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_NEW))
    icl_stats_inc ("amq_consumer_basic_new", &s_amq_consumer_basic_new_stats);
#endif

    self = amq_consumer_basic_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CONSUMER_BASIC_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_consumer_basic_show_);
#endif

//
self->consumer = consumer;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_NEW))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_NEW))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" consumer=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, consumer, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_consumer_basic_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_basic_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_SELFTEST))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_SELFTEST))
    icl_trace_record (NULL, amq_consumer_basic_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_SELFTEST))
    icl_stats_inc ("amq_consumer_basic_selftest", &s_amq_consumer_basic_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_SELFTEST))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_SELFTEST))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_selftest_finish"
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
    amq_consumer_basic_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_basic_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_TERMINATE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_TERMINATE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_TERMINATE))
    icl_stats_inc ("amq_consumer_basic_terminate", &s_amq_consumer_basic_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_TERMINATE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_TERMINATE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_terminate_finish"
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
    amq_consumer_basic_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_basic_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_consumer_basic_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_SHOW))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_SHOW))
    icl_trace_record (NULL, amq_consumer_basic_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_SHOW))
    icl_stats_inc ("amq_consumer_basic_show", &s_amq_consumer_basic_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_consumer_basic file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_SHOW))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_SHOW))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_show_finish"
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
    amq_consumer_basic_destroy

    Type: Component method
    Destroys a amq_consumer_basic_t object. Takes the address of a
    amq_consumer_basic_t reference (a pointer to a pointer) and nullifies the
    reference after use.  Does nothing if the reference is already
    null.
    Performs an agressive destroy of an object.  This involves:
    1. Removing the object from any containers it is in.
    2. Making the object an zombie
    3. Decrementing the object's link count
    4. If the link count is zero then freeing the object.
    -------------------------------------------------------------------------
 */

void
    amq_consumer_basic_destroy_ (
    amq_consumer_basic_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_consumer_basic_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_DESTROY_PUBLIC))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_consumer_basic_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_DESTROY_PUBLIC))
    icl_stats_inc ("amq_consumer_basic_destroy", &s_amq_consumer_basic_destroy_stats);
#endif

if (self) {
    amq_consumer_basic_annihilate (self_p);
    amq_consumer_basic_free ((amq_consumer_basic_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_DESTROY_PUBLIC))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_consumer_basic_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_basic_annihilate (
    amq_consumer_basic_t * ( * self_p )  //  Reference to object reference
)
{

    amq_consumer_basic_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_DESTROY))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_DESTROY))
    icl_trace_record (NULL, amq_consumer_basic_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_DESTROY))
    icl_stats_inc ("amq_consumer_basic_annihilate", &s_amq_consumer_basic_annihilate_stats);
#endif

AMQ_CONSUMER_BASIC_ASSERT_SANE (self);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_DESTROY))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_DESTROY))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_destroy_finish"
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

}
/*  -------------------------------------------------------------------------
    amq_consumer_basic_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_consumer_basic_t *
    amq_consumer_basic_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_consumer_basic_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_ALLOC))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_ALLOC))
    icl_trace_record (NULL, amq_consumer_basic_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_ALLOC))
    icl_stats_inc ("amq_consumer_basic_alloc", &s_amq_consumer_basic_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_consumer_basic_cache_initialise ();

self = (amq_consumer_basic_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_consumer_basic_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_ALLOC))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_ALLOC))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_alloc_finish"
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
    amq_consumer_basic_free

    Type: Component method
    Freess a amq_consumer_basic_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_basic_free (
    amq_consumer_basic_t * self         //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_FREE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_FREE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_FREE))
    icl_stats_inc ("amq_consumer_basic_free", &s_amq_consumer_basic_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (amq_consumer_basic_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_consumer_basic_t));
        self->object_tag = AMQ_CONSUMER_BASIC_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_FREE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_FREE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_free_finish"
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
    amq_consumer_basic_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_basic_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_CACHE_INITIALISE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_CACHE_INITIALISE))
    icl_stats_inc ("amq_consumer_basic_cache_initialise", &s_amq_consumer_basic_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_consumer_basic_t));
icl_system_register (amq_consumer_basic_cache_purge, amq_consumer_basic_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_CACHE_INITIALISE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_cache_initialise_finish"
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
    amq_consumer_basic_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_basic_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_CACHE_PURGE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_PURGE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_CACHE_PURGE))
    icl_stats_inc ("amq_consumer_basic_cache_purge", &s_amq_consumer_basic_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_PURGE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_CACHE_PURGE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_cache_purge_finish"
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
    amq_consumer_basic_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_consumer_basic_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_CACHE_TERMINATE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_CACHE_TERMINATE))
    icl_stats_inc ("amq_consumer_basic_cache_terminate", &s_amq_consumer_basic_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_CACHE_TERMINATE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_cache_terminate_finish"
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
    amq_consumer_basic_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_consumer_basic_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_ANIMATE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_ANIMATE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_ANIMATE))
    icl_stats_inc ("amq_consumer_basic_animate", &s_amq_consumer_basic_animate_stats);
#endif

amq_consumer_basic_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_ANIMATE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_ANIMATE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_animate_finish"
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
    amq_consumer_basic_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_consumer_basic_new_in_scope_ (
    amq_consumer_basic_t * * self_p,    //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_consumer_t * consumer           //  Parent consumer
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)  ||  defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_NEW_IN_SCOPE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" consumer=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, consumer);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC)  ||  defined (BASE_STATS_AMQ_CONSUMER_BASIC_NEW_IN_SCOPE))
    icl_stats_inc ("amq_consumer_basic_new_in_scope", &s_amq_consumer_basic_new_in_scope_stats);
#endif

*self_p = amq_consumer_basic_new_ (file,line,consumer);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_consumer_basic_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_consumer_basic_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC)   || defined (BASE_ANIMATE_AMQ_CONSUMER_BASIC_NEW_IN_SCOPE))
    if (amq_consumer_basic_animating)
        icl_console_print ("<amq_consumer_basic_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" consumer=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, consumer, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_NEW)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_SELFTEST)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_SHOW)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_DESTROY)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_ALLOC)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_FREE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_ANIMATE)   || defined (BASE_TRACE_AMQ_CONSUMER_BASIC_NEW_IN_SCOPE) )
void
amq_consumer_basic_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "selftest"; break;
        case 3: method_name = "terminate"; break;
        case 4: method_name = "show"; break;
        case 5: method_name = "destroy public"; break;
        case 6: method_name = "destroy"; break;
        case 7: method_name = "alloc"; break;
        case 8: method_name = "free"; break;
        case 9: method_name = "cache initialise"; break;
        case 10: method_name = "cache purge"; break;
        case 11: method_name = "cache terminate"; break;
        case 12: method_name = "animate"; break;
        case 13: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_consumer_basic %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_consumer_basic_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_consumer_basic_component  = "amq_consumer_basic ";
char *amq_consumer_basic_version   = "1.0 ";
char *amq_consumer_basic_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_consumer_basic_filename  = "amq_consumer_basic.icl ";
char *amq_consumer_basic_builddate  = "2010/10/06 ";
char *amq_consumer_basic_version_end  = "VeRsIoNeNd:ipc";

