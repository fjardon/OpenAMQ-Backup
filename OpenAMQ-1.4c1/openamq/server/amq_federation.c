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
#define self_show_animation  amq_federation_show_animation
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

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = amq_federation_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_federation_free (self);
    *self_p = NULL;
}

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
}
/*  -------------------------------------------------------------------------
    amq_federation_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_federation_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_federation_animating = enabled;

amq_federation_agent_animate (enabled);
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

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_federation_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
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

if (s_amq_federation_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_federation_mutex);
#endif
        s_amq_federation_active = FALSE;
    }
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

//  Initialise cache if necessary
if (!s_cache)
    amq_federation_cache_initialise ();

self = (amq_federation_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_federation_t));



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

s_cache = icl_cache_get (sizeof (amq_federation_t));
icl_system_register (amq_federation_cache_purge, amq_federation_cache_terminate);
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

icl_mem_cache_purge (s_cache);

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

s_cache = NULL;

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

*self_p = amq_federation_new_ (file,line,exchange,type,host,vhost,login);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_federation_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
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

char *EMBED__amq_federation_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_federation_component     = "amq_federation ";
char *EMBED__amq_federation_version       = "1.0 ";
char *EMBED__amq_federation_copyright     = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_federation_filename      = "amq_federation.icl ";
char *EMBED__amq_federation_builddate     = "2010/10/06 ";
char *EMBED__amq_federation_version_end   = "VeRsIoNeNd:ipc";

