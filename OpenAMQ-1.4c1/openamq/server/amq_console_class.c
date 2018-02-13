/*---------------------------------------------------------------------------
    amq_console_class.c - amq_console_class component

This class defines a class descriptor.
    Generated from amq_console_class.icl by icl_gen using GSL/4.
    
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
#include "amq_console_class.h"          //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_console_class_t

//  Shorthands for class methods

#define self_selftest       amq_console_class_selftest
#define self_terminate      amq_console_class_terminate
#define self_new            amq_console_class_new
#define self_show           amq_console_class_show
#define self_destroy        amq_console_class_destroy
#define self_annihilate     amq_console_class_annihilate
#define self_alloc          amq_console_class_alloc
#define self_free           amq_console_class_free
#define self_cache_initialise  amq_console_class_cache_initialise
#define self_cache_purge    amq_console_class_cache_purge
#define self_cache_terminate  amq_console_class_cache_terminate
#define self_show_animation  amq_console_class_show_animation
#define self_new_in_scope   amq_console_class_new_in_scope

static void
    amq_console_class_annihilate (
amq_console_class_t * ( * self_p )      //  Reference to object reference
);

#define amq_console_class_alloc()       amq_console_class_alloc_ (__FILE__, __LINE__)
static amq_console_class_t *
    amq_console_class_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_console_class_free (
amq_console_class_t * self              //  Object reference
);

static void
    amq_console_class_cache_initialise (
void);

static void
    amq_console_class_cache_purge (
void);

static void
    amq_console_class_cache_terminate (
void);

Bool
    amq_console_class_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    amq_console_class_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_console_class_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_console_class_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_console_class_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_console_class_new

    Type: Component method
    Creates and initialises a new amq_console_class_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_console_class_t *
    amq_console_class_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_console_class_t *
        self = NULL;                    //  Object reference

    self = amq_console_class_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CONSOLE_CLASS_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_console_class_show_);
#endif

}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_console_class_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_console_class_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_console_class_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_console_class file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_console_class_destroy

    Type: Component method
    Destroys a amq_console_class_t object. Takes the address of a
    amq_console_class_t reference (a pointer to a pointer) and nullifies the
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
    amq_console_class_destroy_ (
    amq_console_class_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_console_class_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_console_class_annihilate (self_p);
    amq_console_class_free ((amq_console_class_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_console_class_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_console_class_annihilate (
    amq_console_class_t * ( * self_p )  //  Reference to object reference
)
{

    amq_console_class_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

AMQ_CONSOLE_CLASS_ASSERT_SANE (self);


}
/*  -------------------------------------------------------------------------
    amq_console_class_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_console_class_t *
    amq_console_class_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_console_class_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_console_class_cache_initialise ();

self = (amq_console_class_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_console_class_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_console_class_free

    Type: Component method
    Freess a amq_console_class_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_console_class_free (
    amq_console_class_t * self          //  Object reference
)
{


if (self) {

        memset (&self->object_tag, 0, sizeof (amq_console_class_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_console_class_t));
        self->object_tag = AMQ_CONSOLE_CLASS_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_console_class_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_console_class_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_console_class_t));
icl_system_register (amq_console_class_cache_purge, amq_console_class_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_console_class_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_console_class_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_console_class_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_console_class_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_console_class_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_console_class_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_console_class_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_console_class_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_console_class_new_in_scope_ (
    amq_console_class_t * * self_p,     //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_console_class_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_console_class_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_console_class_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_console_class_component  = "amq_console_class ";
char *EMBED__amq_console_class_version    = "1.0 ";
char *EMBED__amq_console_class_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_console_class_filename   = "amq_console_class.icl ";
char *EMBED__amq_console_class_builddate  = "2010/10/06 ";
char *EMBED__amq_console_class_version_end  = "VeRsIoNeNd:ipc";

