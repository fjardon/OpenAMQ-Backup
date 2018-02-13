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
#define self_animate        amq_mgt_console_animate
#define self_new_in_scope   amq_mgt_console_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_NEW))
static icl_stats_t *s_amq_mgt_console_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_DESTROY))
static icl_stats_t *s_amq_mgt_console_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_SELFTEST))
static icl_stats_t *s_amq_mgt_console_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_TERMINATE))
static icl_stats_t *s_amq_mgt_console_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_SHOW))
static icl_stats_t *s_amq_mgt_console_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_DESTROY_PUBLIC))
static icl_stats_t *s_amq_mgt_console_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_ALLOC))
static icl_stats_t *s_amq_mgt_console_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_FREE))
static icl_stats_t *s_amq_mgt_console_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_CACHE_INITIALISE))
static icl_stats_t *s_amq_mgt_console_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_CACHE_PURGE))
static icl_stats_t *s_amq_mgt_console_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_CACHE_TERMINATE))
static icl_stats_t *s_amq_mgt_console_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_ANIMATE))
static icl_stats_t *s_amq_mgt_console_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_NEW_IN_SCOPE))
static icl_stats_t *s_amq_mgt_console_new_in_scope_stats = NULL;
#endif
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_NEW))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" host=\"%s\""
" vhost=\"%s\""
" user=\"%s\""
" password=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, host, vhost, user, password);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_NEW))
    icl_trace_record (NULL, amq_mgt_console_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_NEW))
    icl_stats_inc ("amq_mgt_console_new", &s_amq_mgt_console_new_stats);
#endif

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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_NEW))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_NEW))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" host=\"%s\""
" vhost=\"%s\""
" user=\"%s\""
" password=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, host, vhost, user, password, self);
#endif


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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_DESTROY))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_DESTROY))
    icl_trace_record (NULL, amq_mgt_console_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_DESTROY))
    icl_stats_inc ("amq_mgt_console_annihilate", &s_amq_mgt_console_annihilate_stats);
#endif

AMQ_MGT_CONSOLE_ASSERT_SANE (self);

amq_mgt_broker_destroy (&self->broker);
amq_client_session_destroy (&self->session);
amq_client_connection_destroy (&self->connection);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_DESTROY))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_DESTROY))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_destroy_finish"
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
    amq_mgt_console_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_console_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_SELFTEST))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_SELFTEST))
    icl_trace_record (NULL, amq_mgt_console_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_SELFTEST))
    icl_stats_inc ("amq_mgt_console_selftest", &s_amq_mgt_console_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_SELFTEST))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_SELFTEST))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_selftest_finish"
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
    amq_mgt_console_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_console_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_TERMINATE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_TERMINATE))
    icl_trace_record (NULL, amq_mgt_console_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_TERMINATE))
    icl_stats_inc ("amq_mgt_console_terminate", &s_amq_mgt_console_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_TERMINATE))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_TERMINATE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_terminate_finish"
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


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_SHOW))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_SHOW))
    icl_trace_record (NULL, amq_mgt_console_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_SHOW))
    icl_stats_inc ("amq_mgt_console_show", &s_amq_mgt_console_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_mgt_console file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_SHOW))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_SHOW))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_show_finish"
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_DESTROY_PUBLIC))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_mgt_console_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_DESTROY_PUBLIC))
    icl_stats_inc ("amq_mgt_console_destroy", &s_amq_mgt_console_destroy_stats);
#endif

if (self) {
    amq_mgt_console_annihilate (self_p);
    amq_mgt_console_free ((amq_mgt_console_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_DESTROY_PUBLIC))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_destroy_public_finish"
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_ALLOC))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_ALLOC))
    icl_trace_record (NULL, amq_mgt_console_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_ALLOC))
    icl_stats_inc ("amq_mgt_console_alloc", &s_amq_mgt_console_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_mgt_console_cache_initialise ();

self = (amq_mgt_console_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_mgt_console_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_ALLOC))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_ALLOC))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_alloc_finish"
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


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_FREE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_FREE))
    icl_trace_record (NULL, amq_mgt_console_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_FREE))
    icl_stats_inc ("amq_mgt_console_free", &s_amq_mgt_console_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (amq_mgt_console_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_mgt_console_t));
        self->object_tag = AMQ_MGT_CONSOLE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_FREE))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_FREE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_free_finish"
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
    amq_mgt_console_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_console_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_CACHE_INITIALISE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_mgt_console_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_CACHE_INITIALISE))
    icl_stats_inc ("amq_mgt_console_cache_initialise", &s_amq_mgt_console_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_mgt_console_t));
icl_system_register (amq_mgt_console_cache_purge, amq_mgt_console_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_CACHE_INITIALISE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_cache_initialise_finish"
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
    amq_mgt_console_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_console_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_CACHE_PURGE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_PURGE))
    icl_trace_record (NULL, amq_mgt_console_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_CACHE_PURGE))
    icl_stats_inc ("amq_mgt_console_cache_purge", &s_amq_mgt_console_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_PURGE))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_CACHE_PURGE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_cache_purge_finish"
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
    amq_mgt_console_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_console_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_CACHE_TERMINATE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_mgt_console_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_CACHE_TERMINATE))
    icl_stats_inc ("amq_mgt_console_cache_terminate", &s_amq_mgt_console_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_CACHE_TERMINATE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_cache_terminate_finish"
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
    amq_mgt_console_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_mgt_console_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_ANIMATE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_ANIMATE))
    icl_trace_record (NULL, amq_mgt_console_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_ANIMATE))
    icl_stats_inc ("amq_mgt_console_animate", &s_amq_mgt_console_animate_stats);
#endif

amq_mgt_console_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_ANIMATE))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_ANIMATE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_animate_finish"
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)  ||  defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_NEW_IN_SCOPE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" host=\"%s\""
" vhost=\"%s\""
" user=\"%s\""
" password=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, host, vhost, user, password);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_mgt_console_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE)  ||  defined (BASE_STATS_AMQ_MGT_CONSOLE_NEW_IN_SCOPE))
    icl_stats_inc ("amq_mgt_console_new_in_scope", &s_amq_mgt_console_new_in_scope_stats);
#endif

*self_p = amq_mgt_console_new_ (file,line,host,vhost,user,password);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_mgt_console_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_mgt_console_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE)   || defined (BASE_ANIMATE_AMQ_MGT_CONSOLE_NEW_IN_SCOPE))
    if (amq_mgt_console_animating)
        icl_console_print ("<amq_mgt_console_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" host=\"%s\""
" vhost=\"%s\""
" user=\"%s\""
" password=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, host, vhost, user, password, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_NEW)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_DESTROY)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_SELFTEST)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_TERMINATE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_SHOW)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_ALLOC)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_FREE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_ANIMATE)   || defined (BASE_TRACE_AMQ_MGT_CONSOLE_NEW_IN_SCOPE) )
void
amq_mgt_console_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "terminate"; break;
        case 5: method_name = "show"; break;
        case 6: method_name = "destroy public"; break;
        case 7: method_name = "alloc"; break;
        case 8: method_name = "free"; break;
        case 9: method_name = "cache initialise"; break;
        case 10: method_name = "cache purge"; break;
        case 11: method_name = "cache terminate"; break;
        case 12: method_name = "animate"; break;
        case 13: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_mgt_console %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_mgt_console_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_mgt_console_component    = "amq_mgt_console ";
char *amq_mgt_console_version      = "1.0 ";
char *amq_mgt_console_copyright    = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_mgt_console_filename     = "amq_mgt_console.icl ";
char *amq_mgt_console_builddate    = "2010/10/06 ";
char *amq_mgt_console_version_end  = "VeRsIoNeNd:ipc";

