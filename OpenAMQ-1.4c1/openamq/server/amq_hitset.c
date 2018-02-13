/*---------------------------------------------------------------------------
    amq_hitset.c - amq_hitset component

    Holds a hitset, which is the result of a match field name and value.  
    The hitset is an array of all matching indices plus upper/lower 
    limits on this array.
    Generated from amq_hitset.icl by icl_gen using GSL/4.
    
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
#include "amq_hitset.h"                 //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_hitset_t

//  Shorthands for class methods

#define self_new            amq_hitset_new
#define self_collect        amq_hitset_collect
#define self_selftest       amq_hitset_selftest
#define self_terminate      amq_hitset_terminate
#define self_show           amq_hitset_show
#define self_destroy        amq_hitset_destroy
#define self_annihilate     amq_hitset_annihilate
#define self_alloc          amq_hitset_alloc
#define self_free           amq_hitset_free
#define self_cache_initialise  amq_hitset_cache_initialise
#define self_cache_purge    amq_hitset_cache_purge
#define self_cache_terminate  amq_hitset_cache_terminate
#define self_show_animation  amq_hitset_show_animation
#define self_new_in_scope   amq_hitset_new_in_scope

static void
    amq_hitset_annihilate (
amq_hitset_t * ( * self_p )             //  Reference to object reference
);

#define amq_hitset_alloc()              amq_hitset_alloc_ (__FILE__, __LINE__)
static amq_hitset_t *
    amq_hitset_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_hitset_free (
amq_hitset_t * self                     //  Object reference
);

static void
    amq_hitset_cache_initialise (
void);

static void
    amq_hitset_cache_purge (
void);

static void
    amq_hitset_cache_terminate (
void);

Bool
    amq_hitset_animating = TRUE;        //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    amq_hitset_new

    Type: Component method
    Creates and initialises a new amq_hitset_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_hitset_t *
    amq_hitset_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_hitset_t *
        self = NULL;                    //  Object reference

    self = amq_hitset_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_HITSET_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_hitset_show_);
#endif

self->lowest  = IPR_INDEX_MAX;
self->highest = -1;
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_hitset_collect

    Type: Component method
    Accepts a amq_hitset_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_hitset_collect (
    amq_hitset_t * self,                //  Reference to object
    amq_index_hash_t * index_hash,      //  Search this hash
    char * index_key                    //  For this term
)
{
amq_index_t
    *index;                         //  Index item                       
int
    item_nbr;
    int
        rc = 0;                         //  Return code

AMQ_HITSET_ASSERT_SANE (self);

index = amq_index_hash_search (index_hash, index_key);
if (index) {
    item_nbr = ipr_bits_first (index->bindset);
    while (item_nbr >= 0) {
        if (amq_server_config_debug_route (amq_server_config))
            smt_log_print (amq_broker->debug_log,
                "X: route    header=%s binding=%d", index_key, item_nbr);
        if (item_nbr < self->lowest)
            self->lowest = item_nbr;
        //  We don't nullify this object so initialise new hit counts
        while (self->highest < item_nbr)
            self->hit_count [++self->highest] = 0;

        self->hit_count [item_nbr]++;
        item_nbr = ipr_bits_next (index->bindset, item_nbr);
    }
    amq_index_unlink (&index);
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_hitset_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_hitset_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_hitset_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_hitset_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_hitset_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_hitset_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_hitset_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_hitset file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_hitset_destroy

    Type: Component method
    Destroys a amq_hitset_t object. Takes the address of a
    amq_hitset_t reference (a pointer to a pointer) and nullifies the
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
    amq_hitset_destroy_ (
    amq_hitset_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_hitset_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_hitset_annihilate (self_p);
    amq_hitset_free ((amq_hitset_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_hitset_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_hitset_annihilate (
    amq_hitset_t * ( * self_p )         //  Reference to object reference
)
{

    amq_hitset_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

AMQ_HITSET_ASSERT_SANE (self);


}
/*  -------------------------------------------------------------------------
    amq_hitset_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_hitset_t *
    amq_hitset_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_hitset_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_hitset_cache_initialise ();

self = (amq_hitset_t *) icl_mem_cache_alloc_ (s_cache, file, line);



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_hitset_free

    Type: Component method
    Freess a amq_hitset_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_hitset_free (
    amq_hitset_t * self                 //  Object reference
)
{


if (self) {

    self->object_tag = AMQ_HITSET_DEAD;
    icl_mem_free (self);
}
self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_hitset_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_hitset_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_hitset_t));
icl_system_register (amq_hitset_cache_purge, amq_hitset_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_hitset_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_hitset_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_hitset_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_hitset_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_hitset_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_hitset_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_hitset_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_hitset_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_hitset_new_in_scope_ (
    amq_hitset_t * * self_p,            //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_hitset_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_hitset_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_hitset_version_start     = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_hitset_component         = "amq_hitset ";
char *EMBED__amq_hitset_version           = "1.1 ";
char *EMBED__amq_hitset_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_hitset_filename          = "amq_hitset.icl ";
char *EMBED__amq_hitset_builddate         = "2010/10/06 ";
char *EMBED__amq_hitset_version_end       = "VeRsIoNeNd:ipc";

