/*---------------------------------------------------------------------------
    amq_federation.c - amq_federation component

This agent implements a single federation, which is a relationship between
an exchange on this server and the same-named exchange on a parent server.
There are two families of federation, primitives that do one thing and 
compounds which combine the effects of multiple primitives.

The primitives are:

 - Subscriber federation: replicate bindings to the parent server, so that 
   messages are pulled down from it.  The subscriber federation does three
   things: send queue.bind and and queue.unbind commands to the parent 
   server (via a peering), and process messages delivered from the parent.
   Typically used on topic or header exchanges.
   
 - Publisher federation (aka 'forward all'): replicate published messages to
   the parent server.  The publisher federation does two things: forward all
   basic.publish commands to the parent server, and process undeliverable
   messages returned by the parent server. Typically used for topic or header 
   exchanges.
   
 - Locator federation (aka 'forward else'): replicate published messages to
   the parent server if they could not be delivered locally.  The locator
   federation does two things: forward basic.publish messages to the parent
   server if they could not be delivered locally, and process undeliverable
   messages returned by the parent server.  Typically used for direct 
   exchanges.
   
The compound federations are:

 - Fanout federation: combines subscriber and publisher.  Fanout federation
   does this: send queue.bind and unbind to parent server; when a local app
   publishes message, forward that to parent (and do not publish to local
   exchange); process messages delivered from the parent; process returns
   from the parent.  The result is that messages published to any server will
   be pushed up to the highest parent, and then propagated back down through
   all servers and out to applications.  This is the default federation for 
   topic and header exchanges.  The current implementation creates extra
   latency. 
 
 - Service federation: combines subscriber and locator.  Service federation
   does this: send queue.bind and unbind to parent server; when local app
   publishes message, try to deliver locally and if that fails, forward to
   parent server; process messages delivered from parent; process returns
   from the parent.  The result is that requests will go to the nearest
   consumer, and responses will come back down from parents.  This is the
   default federation for direct exchanges.
    Generated from amq_federation.icl by smt_object_gen using GSL/4.
    
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
#include "amq_federation.h"             //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_federation_t

//  Shorthands for class methods                                               

#define self_new            amq_federation_new
#define self_annihilate     amq_federation_annihilate
#define self_binding_created  amq_federation_binding_created
#define self_binding_destroyed  amq_federation_binding_destroyed
#define self_message_published  amq_federation_message_published
#define self_type_lookup    amq_federation_type_lookup
#define self_type_name      amq_federation_type_name
#define self_selftest       amq_federation_selftest
#define self_destroy        amq_federation_destroy
#define self_unlink         amq_federation_unlink
#define self_animate        amq_federation_animate
#define self_free           amq_federation_free
#define self_initialise     amq_federation_initialise
#define self_terminate      amq_federation_terminate
#define self_show           amq_federation_show
#define self_alloc          amq_federation_alloc
#define self_link           amq_federation_link
#define self_cache_initialise  amq_federation_cache_initialise
#define self_cache_purge    amq_federation_cache_purge
#define self_cache_terminate  amq_federation_cache_terminate
#define self_new_in_scope   amq_federation_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_NEW))
static icl_stats_t *s_amq_federation_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_DESTROY))
static icl_stats_t *s_amq_federation_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_BINDING_CREATED))
static icl_stats_t *s_amq_federation_binding_created_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_BINDING_DESTROYED))
static icl_stats_t *s_amq_federation_binding_destroyed_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_MESSAGE_PUBLISHED))
static icl_stats_t *s_amq_federation_message_published_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_TYPE_LOOKUP))
static icl_stats_t *s_amq_federation_type_lookup_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_TYPE_NAME))
static icl_stats_t *s_amq_federation_type_name_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_SELFTEST))
static icl_stats_t *s_amq_federation_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_DESTROY_PUBLIC))
static icl_stats_t *s_amq_federation_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_UNLINK))
static icl_stats_t *s_amq_federation_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_ANIMATE))
static icl_stats_t *s_amq_federation_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_FREE))
static icl_stats_t *s_amq_federation_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_INITIALISE))
static icl_stats_t *s_amq_federation_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_TERMINATE))
static icl_stats_t *s_amq_federation_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_SHOW))
static icl_stats_t *s_amq_federation_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_ALLOC))
static icl_stats_t *s_amq_federation_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_LINK))
static icl_stats_t *s_amq_federation_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_CACHE_INITIALISE))
static icl_stats_t *s_amq_federation_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_CACHE_PURGE))
static icl_stats_t *s_amq_federation_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_CACHE_TERMINATE))
static icl_stats_t *s_amq_federation_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_NEW_IN_SCOPE))
static icl_stats_t *s_amq_federation_new_in_scope_stats = NULL;
#endif
#define amq_federation_annihilate(self)  amq_federation_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_federation_annihilate_ (
amq_federation_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_federation_initialise (
void);

#define amq_federation_alloc()          amq_federation_alloc_ (__FILE__, __LINE__)
static amq_federation_t *
    amq_federation_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_federation_cache_initialise (
void);

static void
    amq_federation_cache_purge (
void);

static void
    amq_federation_cache_terminate (
void);

Bool
    amq_federation_animating = TRUE;    //  Animation enabled by default
static Bool
    s_amq_federation_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_federation_mutex   = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static int
    s_content_handler (void *vself, amq_peering_t *peering, amq_peer_method_t *peer_method);
static int
    s_return_handler (void *vself, amq_peering_t *peering, amq_peer_method_t *peer_method);
/*  -------------------------------------------------------------------------
    amq_federation_new

    Type: Component method
    Creates and initialises a new amq_federation_t object, returns a
    reference to the created object.
    Creates a new federation instance connected to the specified remote 
    server and exchange.
    -------------------------------------------------------------------------
 */

amq_federation_t *
    amq_federation_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_exchange_t * exchange,          //  Parent exchange
    unsigned int type,                  //  Federation type
    char * host,                        //  Host to connect to
    char * vhost,                       //  Virtual host identifier
    char * login                        //  Peering login to use
)
{
    amq_federation_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_NEW))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" host=\"%s\""
" vhost=\"%s\""
" login=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, exchange, host, vhost, login);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_NEW))
    icl_trace_record (NULL, amq_federation_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_NEW))
    icl_stats_inc ("amq_federation_new", &s_amq_federation_new_stats);
#endif

if (!s_amq_federation_active)
    self_initialise ();
    self = amq_federation_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_FEDERATION_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_federation_show_);
#endif

self->thread = amq_federation_agent_class_thread_new (self);
self->thread->animate = TRUE;

//
assert (AMQ_FEDERATION_VALID (type));

self->exchange = amq_exchange_link (exchange);
self->type     = type;
self->peering  = amq_peering_new (host, vhost,
    amq_server_config_trace (amq_server_config),
    self->exchange->name,
    amq_exchange_type_name (self->exchange->type));

amq_peering_set_login           (self->peering, login);
amq_peering_set_content_handler (self->peering, s_content_handler, self);
amq_peering_set_return_handler  (self->peering, s_return_handler, self);
smt_log_print (amq_broker->debug_log,
    "I: federating %s to %s (%s)", 
    self->exchange->name, host, amq_federation_type_name (self->type));

amq_peering_start (self->peering);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_NEW))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_NEW))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" host=\"%s\""
" vhost=\"%s\""
" login=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, exchange, host, vhost, login, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_federation_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_federation_annihilate_ (
    amq_federation_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
    int
        history_last;
#endif

    amq_federation_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_DESTROY))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_DESTROY))
    icl_trace_record (NULL, amq_federation_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_DESTROY))
    icl_stats_inc ("amq_federation_annihilate", &s_amq_federation_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = self->links;
#endif


    amq_peering_stop (self->peering);
    amq_exchange_unlink (&self->exchange);
    amq_peering_unlink (&self->peering);

if (self) {
    assert (self->thread);
    if (amq_federation_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_federation agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_DESTROY))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_DESTROY))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_destroy_finish"
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
    amq_federation_binding_created

    Type: Component method
    Accepts a amq_federation_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Called from amq_binding constructor to notify federation of binding 
    creation.
    -------------------------------------------------------------------------
 */

int
    amq_federation_binding_created (
    amq_federation_t * self,            //  Reference to object
    char * routing_key,                 //  Not documented
    icl_longstr_t * arguments,          //  Not documented
    Bool exclusive                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_BINDING_CREATED))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_binding_created_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" routing_key=\"%s\""
" arguments=\"%pp\""
" exclusive=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, routing_key, arguments, exclusive);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_BINDING_CREATED))
    icl_trace_record (NULL, amq_federation_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_BINDING_CREATED))
    icl_stats_inc ("amq_federation_binding_created", &s_amq_federation_binding_created_stats);
#endif

AMQ_FEDERATION_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_federation_agent_binding_created (self->thread,routing_key,arguments,exclusive)) {
        //icl_console_print ("Error sending 'binding created' method to amq_federation agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_BINDING_CREATED))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_BINDING_CREATED))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_binding_created_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" routing_key=\"%s\""
" arguments=\"%pp\""
" exclusive=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, routing_key, arguments, exclusive, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_federation_binding_destroyed

    Type: Component method
    Accepts a amq_federation_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Called from amq_binding destructor to notify federation of binding 
    destruction.
    -------------------------------------------------------------------------
 */

int
    amq_federation_binding_destroyed (
    amq_federation_t * self,            //  Reference to object
    char * routing_key,                 //  Not documented
    icl_longstr_t * arguments           //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_BINDING_DESTROYED))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_binding_destroyed_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" routing_key=\"%s\""
" arguments=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, routing_key, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_BINDING_DESTROYED))
    icl_trace_record (NULL, amq_federation_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_BINDING_DESTROYED))
    icl_stats_inc ("amq_federation_binding_destroyed", &s_amq_federation_binding_destroyed_stats);
#endif

AMQ_FEDERATION_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_federation_agent_binding_destroyed (self->thread,routing_key,arguments)) {
        //icl_console_print ("Error sending 'binding destroyed' method to amq_federation agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_BINDING_DESTROYED))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_BINDING_DESTROYED))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_binding_destroyed_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" routing_key=\"%s\""
" arguments=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, routing_key, arguments, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_federation_message_published

    Type: Component method
    Accepts a amq_federation_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Called from parent exchange publish method, publishes a message to
    the remote exchange.
    -------------------------------------------------------------------------
 */

int
    amq_federation_message_published (
    amq_federation_t * self,            //  Reference to object
    amq_content_basic_t * content,      //  Not documented
    Bool mandatory,                     //  Not documented
    Bool immediate                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_MESSAGE_PUBLISHED))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_message_published_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
" mandatory=\"%i\""
" immediate=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content, mandatory, immediate);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_MESSAGE_PUBLISHED))
    icl_trace_record (NULL, amq_federation_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_MESSAGE_PUBLISHED))
    icl_stats_inc ("amq_federation_message_published", &s_amq_federation_message_published_stats);
#endif

AMQ_FEDERATION_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_federation_agent_message_published (self->thread,content,mandatory,immediate)) {
        //icl_console_print ("Error sending 'message published' method to amq_federation agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_MESSAGE_PUBLISHED))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_MESSAGE_PUBLISHED))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_message_published_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
" mandatory=\"%i\""
" immediate=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content, mandatory, immediate, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_federation_type_lookup

    Type: Component method
    Translates a federation type name into an internal type number.  If
    the type name is not valid, returns -1, else returns one of the
    type numbers supported by this implementation.
    -------------------------------------------------------------------------
 */

int
    amq_federation_type_lookup (
    char * type_name                    //  Type name to lookup
)
{
    int
        rc;                             //  Type number

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_TYPE_LOOKUP))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_type_lookup_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" type_name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, type_name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_TYPE_LOOKUP))
    icl_trace_record (NULL, amq_federation_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_TYPE_LOOKUP))
    icl_stats_inc ("amq_federation_type_lookup", &s_amq_federation_type_lookup_stats);
#endif

//
if (streq (type_name, "none"))
    rc = AMQ_FEDERATION_NONE;
else
if (streq (type_name, "subscriber"))
    rc = AMQ_FEDERATION_SUBSCRIBER;
else
if (streq (type_name, "publisher"))
    rc = AMQ_FEDERATION_PUBLISHER;
else
if (streq (type_name, "locator"))
    rc = AMQ_FEDERATION_LOCATOR;
else
if (streq (type_name, "fanout"))
    rc = AMQ_FEDERATION_FANOUT;
else
if (streq (type_name, "service"))
    rc = AMQ_FEDERATION_SERVICE;
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_TYPE_LOOKUP))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_TYPE_LOOKUP))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_type_lookup_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" type_name=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, type_name, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_federation_type_name

    Type: Component method
    Translates an exchange type index into an external name.
    -------------------------------------------------------------------------
 */

char *
    amq_federation_type_name (
    int type                            //  Type index to translate
)
{
    char *
        name;                           //  Type name

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_TYPE_NAME))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_type_name_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" type=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, type);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_TYPE_NAME))
    icl_trace_record (NULL, amq_federation_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_TYPE_NAME))
    icl_stats_inc ("amq_federation_type_name", &s_amq_federation_type_name_stats);
#endif

//
if (type == AMQ_FEDERATION_NONE)
    name = "none";
else
if (type == AMQ_FEDERATION_SUBSCRIBER)
    name = "subscriber";
else
if (type == AMQ_FEDERATION_PUBLISHER)
    name = "publisher";
else
if (type == AMQ_FEDERATION_LOCATOR)
    name = "locator";
else
if (type == AMQ_FEDERATION_FANOUT)
    name = "fanout";
else
if (type == AMQ_FEDERATION_SERVICE)
    name = "service";
else
    name = "(unknown)";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_TYPE_NAME))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_TYPE_NAME))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_type_name_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" type=\"%i\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, type, name);
#endif


    return (name);
}
/*  -------------------------------------------------------------------------
    amq_federation_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_federation_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_SELFTEST))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_SELFTEST))
    icl_trace_record (NULL, amq_federation_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_SELFTEST))
    icl_stats_inc ("amq_federation_selftest", &s_amq_federation_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_SELFTEST))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_SELFTEST))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_selftest_finish"
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
    amq_federation_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_federation_destroy_ (
    amq_federation_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_federation_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_DESTROY_PUBLIC))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_federation_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_DESTROY_PUBLIC))
    icl_stats_inc ("amq_federation_destroy", &s_amq_federation_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = amq_federation_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_federation_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_DESTROY_PUBLIC))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_destroy_public_finish"
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
    amq_federation_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_federation_unlink_ (
    amq_federation_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
    int
        history_last;
#endif
    amq_federation_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_UNLINK))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_UNLINK))
    icl_trace_record (NULL, amq_federation_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_UNLINK))
    icl_stats_inc ("amq_federation_unlink", &s_amq_federation_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_federation object");
            amq_federation_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_federation_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_federation_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_UNLINK))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_UNLINK))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_unlink_finish"
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
    amq_federation_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_federation_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_ANIMATE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_ANIMATE))
    icl_trace_record (NULL, amq_federation_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_ANIMATE))
    icl_stats_inc ("amq_federation_animate", &s_amq_federation_animate_stats);
#endif

amq_federation_animating = enabled;

amq_federation_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_ANIMATE))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_ANIMATE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_animate_finish"
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
    amq_federation_free

    Type: Component method
    Freess a amq_federation_t object.
    -------------------------------------------------------------------------
 */

void
    amq_federation_free_ (
    amq_federation_t * self,            //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_FREE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_FREE))
    icl_trace_record (NULL, amq_federation_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_FREE))
    icl_stats_inc ("amq_federation_free", &s_amq_federation_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (amq_federation_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_federation_t));
        self->object_tag = AMQ_FEDERATION_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_FREE))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_FREE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_free_finish"
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
    amq_federation_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_federation_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_INITIALISE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_INITIALISE))
    icl_trace_record (NULL, amq_federation_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_INITIALISE))
    icl_stats_inc ("amq_federation_initialise", &s_amq_federation_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_federation_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_federation_mutex)
            s_amq_federation_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_federation_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_federation_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_federation_agent_init ();
            s_amq_federation_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_federation_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_INITIALISE))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_INITIALISE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_initialise_finish"
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
    amq_federation_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_federation_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_TERMINATE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_TERMINATE))
    icl_trace_record (NULL, amq_federation_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_TERMINATE))
    icl_stats_inc ("amq_federation_terminate", &s_amq_federation_terminate_stats);
#endif

if (s_amq_federation_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_federation_mutex);
#endif
        s_amq_federation_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_TERMINATE))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_TERMINATE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_terminate_finish"
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
    amq_federation_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_federation_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_federation_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_SHOW))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_SHOW))
    icl_trace_record (NULL, amq_federation_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_SHOW))
    icl_stats_inc ("amq_federation_show", &s_amq_federation_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_federation zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
    if (self->history_last > AMQ_FEDERATION_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_FEDERATION_HISTORY_LENGTH;
        self->history_last %= AMQ_FEDERATION_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_FEDERATION_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_federation>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_SHOW))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_SHOW))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_show_finish"
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
    amq_federation_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_federation_t *
    amq_federation_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_federation_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_ALLOC))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_ALLOC))
    icl_trace_record (NULL, amq_federation_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_ALLOC))
    icl_stats_inc ("amq_federation_alloc", &s_amq_federation_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_federation_cache_initialise ();

self = (amq_federation_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_federation_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_ALLOC))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_ALLOC))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_alloc_finish"
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
    amq_federation_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_federation_t *
    amq_federation_link_ (
    amq_federation_t * self,            //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_LINK))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_LINK))
    icl_trace_record (NULL, amq_federation_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_LINK))
    icl_stats_inc ("amq_federation_link", &s_amq_federation_link_stats);
#endif

    if (self) {
        AMQ_FEDERATION_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_FEDERATION)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_FEDERATION_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_LINK))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_LINK))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_link_finish"
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
    amq_federation_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_federation_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_CACHE_INITIALISE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_federation_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_CACHE_INITIALISE))
    icl_stats_inc ("amq_federation_cache_initialise", &s_amq_federation_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_federation_t));
icl_system_register (amq_federation_cache_purge, amq_federation_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_CACHE_INITIALISE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_cache_initialise_finish"
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
    amq_federation_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_federation_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_CACHE_PURGE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_PURGE))
    icl_trace_record (NULL, amq_federation_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_CACHE_PURGE))
    icl_stats_inc ("amq_federation_cache_purge", &s_amq_federation_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_PURGE))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_CACHE_PURGE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_cache_purge_finish"
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
    amq_federation_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_federation_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_CACHE_TERMINATE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_federation_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_CACHE_TERMINATE))
    icl_stats_inc ("amq_federation_cache_terminate", &s_amq_federation_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_CACHE_TERMINATE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_cache_terminate_finish"
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
    amq_federation_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_federation_new_in_scope_ (
    amq_federation_t * * self_p,        //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_exchange_t * exchange,          //  Parent exchange
    unsigned int type,                  //  Federation type
    char * host,                        //  Host to connect to
    char * vhost,                       //  Virtual host identifier
    char * login                        //  Peering login to use
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION)  ||  defined (BASE_ANIMATE_AMQ_FEDERATION_NEW_IN_SCOPE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" host=\"%s\""
" vhost=\"%s\""
" login=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, exchange, host, vhost, login);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_federation_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_FEDERATION)  ||  defined (BASE_STATS_AMQ_FEDERATION_NEW_IN_SCOPE))
    icl_stats_inc ("amq_federation_new_in_scope", &s_amq_federation_new_in_scope_stats);
#endif

*self_p = amq_federation_new_ (file,line,exchange,type,host,vhost,login);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_federation_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_federation_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_FEDERATION)   || defined (BASE_ANIMATE_AMQ_FEDERATION_NEW_IN_SCOPE))
    if (amq_federation_animating)
        icl_console_print ("<amq_federation_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" host=\"%s\""
" vhost=\"%s\""
" login=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, exchange, host, vhost, login, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_FEDERATION)   || defined (BASE_TRACE_AMQ_FEDERATION_NEW)   || defined (BASE_TRACE_AMQ_FEDERATION_DESTROY)   || defined (BASE_TRACE_AMQ_FEDERATION_BINDING_CREATED)   || defined (BASE_TRACE_AMQ_FEDERATION_BINDING_DESTROYED)   || defined (BASE_TRACE_AMQ_FEDERATION_MESSAGE_PUBLISHED)   || defined (BASE_TRACE_AMQ_FEDERATION_TYPE_LOOKUP)   || defined (BASE_TRACE_AMQ_FEDERATION_TYPE_NAME)   || defined (BASE_TRACE_AMQ_FEDERATION_SELFTEST)   || defined (BASE_TRACE_AMQ_FEDERATION_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_FEDERATION_UNLINK)   || defined (BASE_TRACE_AMQ_FEDERATION_ANIMATE)   || defined (BASE_TRACE_AMQ_FEDERATION_FREE)   || defined (BASE_TRACE_AMQ_FEDERATION_INITIALISE)   || defined (BASE_TRACE_AMQ_FEDERATION_TERMINATE)   || defined (BASE_TRACE_AMQ_FEDERATION_SHOW)   || defined (BASE_TRACE_AMQ_FEDERATION_ALLOC)   || defined (BASE_TRACE_AMQ_FEDERATION_LINK)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_FEDERATION_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_FEDERATION_NEW_IN_SCOPE) )
void
amq_federation_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "binding created"; break;
        case 4: method_name = "binding destroyed"; break;
        case 5: method_name = "message published"; break;
        case 6: method_name = "type lookup"; break;
        case 7: method_name = "type name"; break;
        case 8: method_name = "selftest"; break;
        case 9: method_name = "destroy public"; break;
        case 10: method_name = "unlink"; break;
        case 11: method_name = "animate"; break;
        case 12: method_name = "free"; break;
        case 13: method_name = "initialise"; break;
        case 14: method_name = "terminate"; break;
        case 15: method_name = "show"; break;
        case 16: method_name = "alloc"; break;
        case 17: method_name = "link"; break;
        case 18: method_name = "cache initialise"; break;
        case 19: method_name = "cache purge"; break;
        case 20: method_name = "cache terminate"; break;
        case 21: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_federation %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Callback handler called by our amq_peering instance when a basic.deliver 
//  is received from the peering connection.  We deliver the message to local
//  consumers, by publishing it on the exchange.
//  
static int
s_content_handler (
    void *vself,
    amq_peering_t *peering,
    amq_peer_method_t *peer_method)
{
    amq_federation_t
        *self = (amq_federation_t *) vself;
    amq_content_basic_t
        *content;

    assert (peer_method->class_id == AMQ_PEER_BASIC);
    assert (peer_method->method_id == AMQ_PEER_BASIC_DELIVER);
    assert (self->type == AMQ_FEDERATION_SUBSCRIBER 
         || self->type == AMQ_FEDERATION_FANOUT
         || self->type == AMQ_FEDERATION_SERVICE);

    if (amq_server_config_debug_peering (amq_server_config))
        smt_log_print (amq_broker->debug_log,
            "P: publish  peer exchange=%s routing_key=%s", 
            peer_method->payload.basic_deliver.exchange,
            peer_method->payload.basic_deliver.routing_key);

    content = peer_method->content;
    peer_method->content = NULL;
    amq_content_basic_set_routing_key (
        content,
        peer_method->payload.basic_deliver.exchange,
        peer_method->payload.basic_deliver.routing_key,
        0);

    amq_exchange_publish (self->exchange, NULL, content, FALSE, FALSE, AMQ_CONNECTION_GROUP_SUPER);
    amq_content_basic_unlink (&content);
    return (0);
}


//  Callback handler called by our amq_peering instance when a basic.return is
//  received from the peering connection.  This happens when the parent broker
//  fails to deliver a mandatory/immediate message.  We look for the connection
//  that originally published the message, and return the message there.
//  
static int
s_return_handler (
    void *vself,
    amq_peering_t *peering,
    amq_peer_method_t *peer_method)
{
    amq_federation_t
        *self = (amq_federation_t *) vself;
    char
        *separator;
    icl_shortstr_t
        sender_id;
    dbyte
        channel_nbr;
    amq_server_connection_t
        *connection;

    //  TODO: these assertions make it possible to crash the broker by
    //  sending it malformed data, however this would require that the
    //  parent broker is evil, we're not speaking to a client app here.
    //  
    assert (peer_method->class_id == AMQ_PEER_BASIC);
    assert (peer_method->method_id == AMQ_PEER_BASIC_RETURN);
    assert (peer_method->content);
    assert (self->type == AMQ_FEDERATION_PUBLISHER
         || self->type == AMQ_FEDERATION_LOCATOR
         || self->type == AMQ_FEDERATION_FANOUT
         || self->type == AMQ_FEDERATION_SERVICE);

    //  Split sender-id "connection-key|channel-nbr" into fields
    icl_shortstr_cpy (sender_id, 
        amq_content_basic_get_sender_id ((amq_content_basic_t *) peer_method->content));
    separator = strchr (sender_id, '|');

    if (separator) {
        *separator++ = 0;               //  Split sender-id into fields
        channel_nbr = atoi (separator);

        //  Find the connection that sent the message
        connection = amq_server_connection_table_search (amq_broker->connections, sender_id);
        if (connection && channel_nbr)
            amq_server_agent_basic_return (
                connection->thread,
                channel_nbr,
                peer_method->content,
                peer_method->payload.basic_return.reply_code,
                peer_method->payload.basic_return.reply_text,
                peer_method->payload.basic_return.exchange,
                peer_method->payload.basic_return.routing_key,
                NULL);

        amq_server_connection_unlink (&connection);
    }
    return (0);
}

//  Embed the version information in the resulting binary                      

char *amq_federation_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_federation_component     = "amq_federation ";
char *amq_federation_version       = "1.0 ";
char *amq_federation_copyright     = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_federation_filename      = "amq_federation.icl ";
char *amq_federation_builddate     = "2010/10/06 ";
char *amq_federation_version_end   = "VeRsIoNeNd:ipc";

