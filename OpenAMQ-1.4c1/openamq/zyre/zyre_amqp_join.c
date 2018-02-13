/*---------------------------------------------------------------------------
    zyre_amqp_join.c - zyre_amqp_join component

  Implements the bare join object for use in the AMQP backend cache.
    Generated from zyre_amqp_join.icl by icl_gen using GSL/4.
    
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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "zyre_amqp_join.h"             //  Definitions for our class

//  Shorthand for class type

#define self_t              zyre_amqp_join_t

//  Shorthands for class methods

#define self_new            zyre_amqp_join_new
#define self_selftest       zyre_amqp_join_selftest
#define self_terminate      zyre_amqp_join_terminate
#define self_show           zyre_amqp_join_show
#define self_destroy        zyre_amqp_join_destroy
#define self_annihilate     zyre_amqp_join_annihilate
#define self_alloc          zyre_amqp_join_alloc
#define self_free           zyre_amqp_join_free
#define self_cache_initialise  zyre_amqp_join_cache_initialise
#define self_cache_purge    zyre_amqp_join_cache_purge
#define self_cache_terminate  zyre_amqp_join_cache_terminate
#define self_show_animation  zyre_amqp_join_show_animation
#define self_new_in_scope   zyre_amqp_join_new_in_scope

static void
    zyre_amqp_join_annihilate (
zyre_amqp_join_t * ( * self_p )         //  Reference to object reference
);

#define zyre_amqp_join_alloc()          zyre_amqp_join_alloc_ (__FILE__, __LINE__)
static zyre_amqp_join_t *
    zyre_amqp_join_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    zyre_amqp_join_free (
zyre_amqp_join_t * self                 //  Object reference
);

static void
    zyre_amqp_join_cache_initialise (
void);

static void
    zyre_amqp_join_cache_purge (
void);

static void
    zyre_amqp_join_cache_terminate (
void);

Bool
    zyre_amqp_join_animating = TRUE;    //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    zyre_amqp_join_new

    Type: Component method
    Creates and initialises a new zyre_amqp_join_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

zyre_amqp_join_t *
    zyre_amqp_join_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * pipe_name,                   //  Pipe name
    char * feed_name,                   //  Feed name
    char * address                      //  Join address
)
{
    zyre_amqp_join_t *
        self = NULL;                    //  Object reference

    self = zyre_amqp_join_alloc_ (file, line);
    if (self) {
        self->object_tag   = ZYRE_AMQP_JOIN_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, zyre_amqp_join_show_);
#endif

//
icl_shortstr_cpy (self->pipe_name, pipe_name);
icl_shortstr_cpy (self->feed_name, feed_name);
icl_shortstr_cpy (self->address, address);
}

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_amqp_join_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_amqp_join_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_amqp_join_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
zyre_amqp_join_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <zyre_amqp_join file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_destroy

    Type: Component method
    Destroys a zyre_amqp_join_t object. Takes the address of a
    zyre_amqp_join_t reference (a pointer to a pointer) and nullifies the
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
    zyre_amqp_join_destroy_ (
    zyre_amqp_join_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    zyre_amqp_join_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    zyre_amqp_join_annihilate (self_p);
    zyre_amqp_join_free ((zyre_amqp_join_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_amqp_join_annihilate (
    zyre_amqp_join_t * ( * self_p )     //  Reference to object reference
)
{

    zyre_amqp_join_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

ZYRE_AMQP_JOIN_ASSERT_SANE (self);


}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static zyre_amqp_join_t *
    zyre_amqp_join_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    zyre_amqp_join_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    zyre_amqp_join_cache_initialise ();

self = (zyre_amqp_join_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (zyre_amqp_join_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_free

    Type: Component method
    Freess a zyre_amqp_join_t object.
    -------------------------------------------------------------------------
 */

static void
    zyre_amqp_join_free (
    zyre_amqp_join_t * self             //  Object reference
)
{


if (self) {

        memset (&self->object_tag, 0, sizeof (zyre_amqp_join_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (zyre_amqp_join_t));
        self->object_tag = ZYRE_AMQP_JOIN_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    zyre_amqp_join_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (zyre_amqp_join_t));
icl_system_register (zyre_amqp_join_cache_purge, zyre_amqp_join_cache_terminate);
}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_amqp_join_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_amqp_join_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    zyre_amqp_join_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

zyre_amqp_join_animating = enabled;
}
/*  -------------------------------------------------------------------------
    zyre_amqp_join_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_amqp_join_new_in_scope_ (
    zyre_amqp_join_t * * self_p,        //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * pipe_name,                   //  Pipe name
    char * feed_name,                   //  Feed name
    char * address                      //  Join address
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = zyre_amqp_join_new_ (file,line,pipe_name,feed_name,address);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) zyre_amqp_join_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__zyre_amqp_join_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__zyre_amqp_join_component     = "zyre_amqp_join ";
char *EMBED__zyre_amqp_join_version       = "1.0 ";
char *EMBED__zyre_amqp_join_copyright     = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__zyre_amqp_join_filename      = "zyre_amqp_join.icl ";
char *EMBED__zyre_amqp_join_builddate     = "2010/10/06 ";
char *EMBED__zyre_amqp_join_version_end   = "VeRsIoNeNd:ipc";

