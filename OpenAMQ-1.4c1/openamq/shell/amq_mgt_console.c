/*---------------------------------------------------------------------------
    amq_mgt_console.c - amq_mgt_console component

Implements the management console object, used by applications to
manage OpenAMQ servers.
    Generated from amq_mgt_console.icl by icl_gen using GSL/4.
    
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
#include "amq_mgt_console.h"            //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_mgt_console_t

//  Shorthands for class methods

#define self_new            amq_mgt_console_new
#define self_annihilate     amq_mgt_console_annihilate
#define self_selftest       amq_mgt_console_selftest
#define self_terminate      amq_mgt_console_terminate
#define self_show           amq_mgt_console_show
#define self_destroy        amq_mgt_console_destroy
#define self_alloc          amq_mgt_console_alloc
#define self_free           amq_mgt_console_free
#define self_cache_initialise  amq_mgt_console_cache_initialise
#define self_cache_purge    amq_mgt_console_cache_purge
#define self_cache_terminate  amq_mgt_console_cache_terminate
#define self_show_animation  amq_mgt_console_show_animation
#define self_new_in_scope   amq_mgt_console_new_in_scope

static void
    amq_mgt_console_annihilate (
amq_mgt_console_t * ( * self_p )        //  Reference to object reference
);

#define amq_mgt_console_alloc()         amq_mgt_console_alloc_ (__FILE__, __LINE__)
static amq_mgt_console_t *
    amq_mgt_console_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_mgt_console_free (
amq_mgt_console_t * self                //  Object reference
);

static void
    amq_mgt_console_cache_initialise (
void);

static void
    amq_mgt_console_cache_purge (
void);

static void
    amq_mgt_console_cache_terminate (
void);

Bool
    amq_mgt_console_animating = TRUE;   //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


int
    g_opt_trace = 0;                    //  Trace option
Bool
    g_opt_addr = FALSE;                 //  Don't do RDNS lookups
/*  -------------------------------------------------------------------------
    amq_mgt_console_new

    Type: Component method
    Creates and initialises a new amq_mgt_console_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_mgt_console_t *
    amq_mgt_console_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * host,                        //  Server host name
    char * vhost,                       //  Virtual host name
    char * user,                        //  Login user name
    char * password                     //  Login password
)
{
icl_longstr_t
    *auth_data;                     //  Authorisation data
int
    rc;
    amq_mgt_console_t *
        self = NULL;                    //  Object reference

    self = amq_mgt_console_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_MGT_CONSOLE_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_mgt_console_show_);
#endif

//
icl_system_initialise (0, NULL);

auth_data = amq_client_connection_auth_plain (user, password);
self->connection = amq_client_connection_new (host, vhost, auth_data, "amq_shell", g_opt_trace, 5000);
icl_longstr_destroy (&auth_data);

if (self->connection) {
    self->session = amq_client_session_new (self->connection);
    assert (self->session);

    //  Create a private queue for replies from console
    rc = amq_client_session_queue_declare (self->session,
        0, NULL, FALSE, FALSE, TRUE, TRUE, NULL);

    if (!rc)
        rc = amq_client_session_basic_consume (self->session,
            0, self->session->queue, NULL, FALSE, TRUE, TRUE, NULL);

    if (!rc)
        rc = amq_client_session_queue_bind (self->session,
            0, self->session->queue, "amq.direct", self->session->queue, NULL);

    if (!rc)
        self->broker = amq_mgt_broker_new (self->session, 0);
    else {
        icl_console_print ("E: could not initialise console reply queue");
        self_destroy (&self);
    }
}
else {
    icl_console_print ("E: could not connect to '%s'", host);
    self_destroy (&self);
}
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_mgt_console_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_console_annihilate (
    amq_mgt_console_t * ( * self_p )    //  Reference to object reference
)
{

    amq_mgt_console_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

AMQ_MGT_CONSOLE_ASSERT_SANE (self);

amq_mgt_broker_destroy (&self->broker);
amq_client_session_destroy (&self->session);
amq_client_connection_destroy (&self->connection);

}
/*  -------------------------------------------------------------------------
    amq_mgt_console_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_console_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_mgt_console_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_console_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_mgt_console_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_console_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_mgt_console_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_mgt_console file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_mgt_console_destroy

    Type: Component method
    Destroys a amq_mgt_console_t object. Takes the address of a
    amq_mgt_console_t reference (a pointer to a pointer) and nullifies the
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
    amq_mgt_console_destroy_ (
    amq_mgt_console_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_mgt_console_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_mgt_console_annihilate (self_p);
    amq_mgt_console_free ((amq_mgt_console_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_mgt_console_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_mgt_console_t *
    amq_mgt_console_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_mgt_console_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_mgt_console_cache_initialise ();

self = (amq_mgt_console_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_mgt_console_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_mgt_console_free

    Type: Component method
    Freess a amq_mgt_console_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_console_free (
    amq_mgt_console_t * self            //  Object reference
)
{


if (self) {

        memset (&self->object_tag, 0, sizeof (amq_mgt_console_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_mgt_console_t));
        self->object_tag = AMQ_MGT_CONSOLE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_mgt_console_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_console_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_mgt_console_t));
icl_system_register (amq_mgt_console_cache_purge, amq_mgt_console_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_mgt_console_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_console_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_mgt_console_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_console_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_mgt_console_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_mgt_console_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_mgt_console_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_mgt_console_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_console_new_in_scope_ (
    amq_mgt_console_t * * self_p,       //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * host,                        //  Server host name
    char * vhost,                       //  Virtual host name
    char * user,                        //  Login user name
    char * password                     //  Login password
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_mgt_console_new_ (file,line,host,vhost,user,password);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_mgt_console_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_mgt_console_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_mgt_console_component    = "amq_mgt_console ";
char *EMBED__amq_mgt_console_version      = "1.0 ";
char *EMBED__amq_mgt_console_copyright    = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_mgt_console_filename     = "amq_mgt_console.icl ";
char *EMBED__amq_mgt_console_builddate    = "2010/10/06 ";
char *EMBED__amq_mgt_console_version_end  = "VeRsIoNeNd:ipc";

