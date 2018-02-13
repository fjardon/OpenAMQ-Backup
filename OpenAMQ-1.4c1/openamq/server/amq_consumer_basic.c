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
#define self_show_animation  amq_consumer_basic_show_animation
#define self_new_in_scope   amq_consumer_basic_new_in_scope

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

    self = amq_consumer_basic_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CONSUMER_BASIC_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_consumer_basic_show_);
#endif

//
self->consumer = consumer;
}

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


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_consumer_basic file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

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

if (self) {
    amq_consumer_basic_annihilate (self_p);
    amq_consumer_basic_free ((amq_consumer_basic_t *) self);
    *self_p = NULL;
}
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

AMQ_CONSUMER_BASIC_ASSERT_SANE (self);


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

//  Initialise cache if necessary
if (!s_cache)
    amq_consumer_basic_cache_initialise ();

self = (amq_consumer_basic_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_consumer_basic_t));



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


if (self) {

        memset (&self->object_tag, 0, sizeof (amq_consumer_basic_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_consumer_basic_t));
        self->object_tag = AMQ_CONSUMER_BASIC_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
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

s_cache = icl_cache_get (sizeof (amq_consumer_basic_t));
icl_system_register (amq_consumer_basic_cache_purge, amq_consumer_basic_cache_terminate);
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

icl_mem_cache_purge (s_cache);

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

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_consumer_basic_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_consumer_basic_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_consumer_basic_animating = enabled;
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

*self_p = amq_consumer_basic_new_ (file,line,consumer);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_consumer_basic_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_consumer_basic_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_consumer_basic_component  = "amq_consumer_basic ";
char *EMBED__amq_consumer_basic_version   = "1.0 ";
char *EMBED__amq_consumer_basic_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_consumer_basic_filename  = "amq_consumer_basic.icl ";
char *EMBED__amq_consumer_basic_builddate  = "2010/10/06 ";
char *EMBED__amq_consumer_basic_version_end  = "VeRsIoNeNd:ipc";

