/*---------------------------------------------------------------------------
    amq_peering.c - amq_peering component

This class defines a smart link to a remote server.  You tell the peering
what server to talk to and it will monitor the server and connect
automatically when the server comes online, and reconnect if the server
goes offline for a period.

A peering has two functions:

1. Binding propagation, in which messages published to an exchange on the
   remote server can be "pulled" to this server.  You tell the peering what
   bindings you are interested in, and it will deliver you all matching
   messages.

2. Message forwarding, in which messages originating locally are carried to
   the remote peer.  This class does not specify where those local messages
   come from.

The peer link may be arbitrarily active or inactive depending on the state
of the network and the remote server.

The peering will replay all bindings if when the peer link becomes active.
It will queue messages that are forwarded when the peer link is not active.

Lastly, the peering will invoke callback methods to tell you when the peer
link becomes active, and when a content arrives.  Currently this class
works only with Basic contents.

The selftest method demonstrates fairly sophisticated peering use.  To test
this, set the environment variable AMQ_PEERING_TEST=1 and run an amq_server.

Note that the current amq_peering implementation is limited to a signle
exchange per amq_peering instance.

This is a summary of the amq_peering API:

    peering = amq_peering_new (
        remote-host-name, virtual-host, trace-level, exchange-name)
        Create a new peering to the specified host, virtual host and
        remote exchange.

    amq_peering_set_login (peering, login-name)
        Tell the peering to login using the specified login-name, which
        must be defined in the local amq_server_base.cfg or amq_server.cfg.

    amq_peering_set_status_handler (peering, handler, calling-object)
        Set the callback handler for status updates.

    amq_peering_set_content_handler (peering, handler, calling-object)
        Set the callback handler for incoming messages.

    amq_peering_start (peering)
        Enable the peering, connect to remote server when possible.

    amq_peering_stop (peering)
        Disable the peering, disconnect from remote server if necessary.

    amq_peering_bind (peering, routing-key, arguments)
        Replicate a binding to the remote server.

    amq_peering_unbind (peering, routing-key, arguments)
        Replicate a queue.unbind to the remote server.  Also removes the
        binding from the list of bindings to replay.

    amq_peering_forward (peering, routing-key, content, madatory, immediate)
        Publish a message to the remote server.

    amq_peering_destroy (&peering)
        Destroy the peering.
    Generated from amq_peering.icl by smt_object_gen using GSL/4.
    
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
#include "amq_peering.h"                //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_peering_t

//  Shorthands for class methods

#define self_new            amq_peering_new
#define self_annihilate     amq_peering_annihilate
#define self_set_login      amq_peering_set_login
#define self_set_status_handler  amq_peering_set_status_handler
#define self_cancel_status_handler  amq_peering_cancel_status_handler
#define self_set_content_handler  amq_peering_set_content_handler
#define self_cancel_content_handler  amq_peering_cancel_content_handler
#define self_set_return_handler  amq_peering_set_return_handler
#define self_cancel_return_handler  amq_peering_cancel_return_handler
#define self_start          amq_peering_start
#define self_stop           amq_peering_stop
#define self_bind           amq_peering_bind
#define self_unbind         amq_peering_unbind
#define self_forward        amq_peering_forward
#define self_peer_connection_start  amq_peering_peer_connection_start
#define self_peer_connection_open_ok  amq_peering_peer_connection_open_ok
#define self_peer_connection_close  amq_peering_peer_connection_close
#define self_peer_channel_open_ok  amq_peering_peer_channel_open_ok
#define self_peer_basic_deliver  amq_peering_peer_basic_deliver
#define self_peer_basic_return  amq_peering_peer_basic_return
#define self_initialise     amq_peering_initialise
#define self_terminate      amq_peering_terminate
#define self_selftest       amq_peering_selftest
#define self_destroy        amq_peering_destroy
#define self_unlink         amq_peering_unlink
#define self_show_animation  amq_peering_show_animation
#define self_free           amq_peering_free
#define self_show           amq_peering_show
#define self_alloc          amq_peering_alloc
#define self_link           amq_peering_link
#define self_cache_initialise  amq_peering_cache_initialise
#define self_cache_purge    amq_peering_cache_purge
#define self_cache_terminate  amq_peering_cache_terminate
#define self_new_in_scope   amq_peering_new_in_scope

#define amq_peering_annihilate(self)    amq_peering_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_peering_annihilate_ (
amq_peering_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_peering_initialise (
void);

#define amq_peering_alloc()             amq_peering_alloc_ (__FILE__, __LINE__)
static amq_peering_t *
    amq_peering_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_peering_cache_initialise (
void);

static void
    amq_peering_cache_purge (
void);

static void
    amq_peering_cache_terminate (
void);

Bool
    amq_peering_animating = TRUE;       //  Animation enabled by default
static Bool
    s_amq_peering_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_peering_mutex      = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


//  These functions are examples of callbacks used in the peering API

static int  s_test_status_handler  (
    void *caller, amq_peering_t *peering, Bool status);
static int  s_test_content_handler (
    void *caller, amq_peering_t *peering, amq_peer_method_t *method);
/*  -------------------------------------------------------------------------
    amq_peering_new

    Type: Component method
    Creates and initialises a new amq_peering_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_peering_t *
    amq_peering_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * host,                        //  Host to connect to
    char * virtual_host,                //  Virtual host
    int trace,                          //  Trace level, 0 - 3
    char * exchange,                    //  Remote exchange name
    char* exchange_type                 //  Remote exchange type
)
{
    amq_peering_t *
        self = NULL;                    //  Object reference

if (!s_amq_peering_active)
    self_initialise ();
    self = amq_peering_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_PEERING_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_peering_show_);
#endif

self->thread = amq_peering_agent_class_thread_new (self);
self->thread->animate = TRUE;

//
icl_shortstr_cpy (self->host,          host);
icl_shortstr_cpy (self->virtual_host,  virtual_host);
icl_shortstr_cpy (self->exchange,      exchange);
icl_shortstr_cpy (self->exchange_type, exchange_type);
self->trace = trace;

//  Create binding state lists
self->bindings = ipr_looseref_list_new ();
self->messages = ipr_looseref_list_new ();
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_peering_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_peering_annihilate_ (
    amq_peering_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
    int
        history_last;
#endif

    amq_peering_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_PEERING_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_PEERING_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_PEERING_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_PEERING_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (amq_peering_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_peering agent");
        rc = -1;
    }
}
else
    rc = -1;

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peering_set_login

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the login credentials using the specified login name; the password
    is taken from the peering configuration file.
    -------------------------------------------------------------------------
 */

int
    amq_peering_set_login (
    amq_peering_t * self,               //  Reference to object
    char * login                        //  Login name to use
)
{
ipr_config_t
    *config;                        //  Current server config file
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

//
config = ipr_config_dup (amq_server_config_table (amq_server_config));
ipr_config_locate (config, "/config/security", "plain");
if (config->located)
    ipr_config_locate (config, "user", login);

if (config->located) {
    icl_longstr_destroy (&self->auth_data);
    self->auth_data = ipr_sasl_plain_encode (login, ipr_config_get (config, "password", ""));
}
else {
    smt_log_print (amq_broker->alert_log,
        "E: login credentials for '%s' not defined - cannot connect", login);
    smt_log_print (amq_broker->alert_log,
        "E: please check security section in configuration, and restart");
    exit (EXIT_FAILURE);
}
ipr_config_destroy (&config);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peering_set_status_handler

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Register a status callback handler. The callback is invoked when
    the peering connection changes status (connected or disconnected).
    If the callback function is NULL, no status callbacks will be made.
    The caller object MUST cancel its registration when stopping.
    -------------------------------------------------------------------------
 */

int
    amq_peering_set_status_handler (
    amq_peering_t * self,               //  Reference to object
    amq_peering_status_fn * status_fn,   //  Callback
    void * caller                       //  Reference of caller object
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

//
self->status_fn = status_fn;
self->status_caller = caller;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peering_cancel_status_handler

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Cancel a status callback handler.
    -------------------------------------------------------------------------
 */

int
    amq_peering_cancel_status_handler (
    amq_peering_t * self,               //  Reference to object
    void * caller                       //  Reference of caller object
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

//
self->status_fn = NULL;
self->status_caller = NULL;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peering_set_content_handler

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Register a basic_deliver callback handler.  The callback in invoked
    when a basic message arrives from the remote peered server. If the
    callback function is NULL, no basic delivery callbacks will be made.
    The caller object MUST cancel its registration when stopping.
    -------------------------------------------------------------------------
 */

int
    amq_peering_set_content_handler (
    amq_peering_t * self,               //  Reference to object
    amq_peering_content_fn * content_fn,   //  Callback
    void * caller                       //  Reference of caller object
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

//
self->content_fn = content_fn;
self->content_caller = caller;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peering_cancel_content_handler

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Cancel a basic_deliver callback handler.
    -------------------------------------------------------------------------
 */

int
    amq_peering_cancel_content_handler (
    amq_peering_t * self,               //  Reference to object
    void * caller                       //  Reference of caller object
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

//
self->content_fn = NULL;
self->content_caller = NULL;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peering_set_return_handler

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Register a basic_return callback handler.  The callback in invoked
    when a returned basic message arrives from the remote peered server. If the
    callback function is NULL, no basic return callbacks will be made.
    The caller object MUST cancel its registration when stopping.
    -------------------------------------------------------------------------
 */

int
    amq_peering_set_return_handler (
    amq_peering_t * self,               //  Reference to object
    amq_peering_return_fn * return_fn,   //  Callback
    void * caller                       //  Reference of caller object
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

//
self->return_fn = return_fn;
self->return_caller = caller;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peering_cancel_return_handler

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Cancel a basic_return callback handler.
    -------------------------------------------------------------------------
 */

int
    amq_peering_cancel_return_handler (
    amq_peering_t * self,               //  Reference to object
    void * caller                       //  Reference of caller object
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

//
self->return_fn = NULL;
self->return_caller = NULL;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peering_start

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Start the peering. You must call this method to start the peering.
    You can send bind methods before or after calling start; the bindings
    are queued and sent to the peer only when the connection succeeds.
    -------------------------------------------------------------------------
 */

int
    amq_peering_start (
    amq_peering_t * self                //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_peering_agent_start (self->thread)) {
        //icl_console_print ("Error sending 'start' method to amq_peering agent");
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
    amq_peering_stop

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Stop the peering. If you want to restart the peering, use the start
    method.
    -------------------------------------------------------------------------
 */

int
    amq_peering_stop (
    amq_peering_t * self                //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_peering_agent_stop (self->thread)) {
        //icl_console_print ("Error sending 'stop' method to amq_peering agent");
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
    amq_peering_bind

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Sets up a queue binding using the specified queue.bind method. This method
    sends the queue.bind method to the remote server and exchange so that all
    messages which match will be delivered to the peering's private queue.
    -------------------------------------------------------------------------
 */

int
    amq_peering_bind (
    amq_peering_t * self,               //  Reference to object
    char * routing_key,                 //  Bind to routing key
    icl_longstr_t * arguments           //  Bind arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_peering_agent_bind (self->thread,routing_key,arguments)) {
        //icl_console_print ("Error sending 'bind' method to amq_peering agent");
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
    amq_peering_unbind

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Removes a queue binding using the specified queue.unbind method. This method
    sends the queue.unbind method to the remote server.  It also removes the
    matching queue.bind method from the list of bindings to replay.
    -------------------------------------------------------------------------
 */

int
    amq_peering_unbind (
    amq_peering_t * self,               //  Reference to object
    char * routing_key,                 //  Bind to routing key
    icl_longstr_t * arguments           //  Bind arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_peering_agent_unbind (self->thread,routing_key,arguments)) {
        //icl_console_print ("Error sending 'unbind' method to amq_peering agent");
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
    amq_peering_forward

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    messages a basic content to the remote peer.
    -------------------------------------------------------------------------
 */

int
    amq_peering_forward (
    amq_peering_t * self,               //  Reference to object
    char * routing_key,                 //  Routing key for publish
    amq_content_basic_t * content,      //  Content to publish
    Bool mandatory,                     //  Mandatory routing
    Bool immediate                      //  Immediate delivery
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_peering_agent_forward (self->thread,routing_key,content,mandatory,immediate)) {
        //icl_console_print ("Error sending 'forward' method to amq_peering agent");
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
    amq_peering_peer_connection_start

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Handles a Connection.Start method coming from the peered server.
    -------------------------------------------------------------------------
 */

int
    amq_peering_peer_connection_start (
    amq_peering_t * self,               //  Reference to object
    amq_peer_method_t * method          //  Not documented
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_peering_agent_peer_connection_start (self->thread,method)) {
        //icl_console_print ("Error sending 'peer connection start' method to amq_peering agent");
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
    amq_peering_peer_connection_open_ok

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Handles a Connection.Open-Ok method coming from the peered server.
    -------------------------------------------------------------------------
 */

int
    amq_peering_peer_connection_open_ok (
    amq_peering_t * self,               //  Reference to object
    amq_peer_method_t * method          //  Not documented
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_peering_agent_peer_connection_open_ok (self->thread,method)) {
        //icl_console_print ("Error sending 'peer connection open ok' method to amq_peering agent");
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
    amq_peering_peer_connection_close

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Handles a Connection.Close method coming from the peered server.
    -------------------------------------------------------------------------
 */

int
    amq_peering_peer_connection_close (
    amq_peering_t * self,               //  Reference to object
    amq_peer_method_t * method          //  Not documented
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_peering_agent_peer_connection_close (self->thread,method)) {
        //icl_console_print ("Error sending 'peer connection close' method to amq_peering agent");
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
    amq_peering_peer_channel_open_ok

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Handles a Channel.Open-Ok method coming from the peered server.
    -------------------------------------------------------------------------
 */

int
    amq_peering_peer_channel_open_ok (
    amq_peering_t * self,               //  Reference to object
    amq_peer_method_t * method          //  Not documented
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_peering_agent_peer_channel_open_ok (self->thread,method)) {
        //icl_console_print ("Error sending 'peer channel open ok' method to amq_peering agent");
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
    amq_peering_peer_basic_deliver

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Handles a Basic.Deliver method coming from the peered server.
    -------------------------------------------------------------------------
 */

int
    amq_peering_peer_basic_deliver (
    amq_peering_t * self,               //  Reference to object
    amq_peer_method_t * method          //  Not documented
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_peering_agent_peer_basic_deliver (self->thread,method)) {
        //icl_console_print ("Error sending 'peer basic deliver' method to amq_peering agent");
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
    amq_peering_peer_basic_return

    Type: Component method
    Accepts a amq_peering_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Handles a Basic.Return method coming from the peered server.
    -------------------------------------------------------------------------
 */

int
    amq_peering_peer_basic_return (
    amq_peering_t * self,               //  Reference to object
    amq_peer_method_t * method          //  Not documented
)
{
    int
        rc = 0;                         //  Return code

AMQ_PEERING_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_peering_agent_peer_basic_return (self->thread,method)) {
        //icl_console_print ("Error sending 'peer basic return' method to amq_peering agent");
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
    amq_peering_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_peering_initialise (
void)
{
ipr_bucket_t
    *bucket;

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_peering_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_peering_mutex)
            s_amq_peering_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_peering_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_peering_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_peering_agent_init ();

//
//  Load configuration data, if any, into the config_table
bucket = amq_server_resource_get ("amq_server_base.cfg");
amq_peer_config = amq_peer_config_new ();
amq_peer_config_load_bucket  (amq_peer_config, bucket);
amq_peer_config_load_xmlfile (amq_peer_config, "amq_peering.cfg", FALSE);
ipr_bucket_destroy (&bucket);

amq_peer_agent_init ();
            s_amq_peering_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_peering_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    amq_peering_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_peering_terminate (
void)
{

if (s_amq_peering_active) {

amq_peer_agent_term ();
amq_peer_config_destroy (&amq_peer_config);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_peering_mutex);
#endif
        s_amq_peering_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    amq_peering_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_peering_selftest (
void)
{

char
    *test_flag;
amq_peering_t
    *peering;                       //  Peering to remote server
amq_content_basic_t
    *content;                       //  Content for testing the peering
int
    seconds = 1000000;              //  Microseconds per second for sleep
amq_broker_t
    *broker_ref;

//  This selftest is NOT run during normal builds
//  To enable it, set the environment variable AMQ_PEERING_TEST=1
//
test_flag = getenv ("AMQ_PEERING_TEST");
if (test_flag && *test_flag == '1') {
    icl_console_mode (ICL_CONSOLE_DATE, TRUE);
    amq_server_config = amq_server_config_new ();

    //  Move to some unused port so we can talk to another server
    //  on the real AMQP port (5672)
    amq_server_config_set_port (amq_server_config, "15000");

    //  These objects are needed for our test framework
    amq_console = amq_console_new ();
    amq_broker = amq_broker_new ();

    //  **************   Peering example starts here   *******************
    //  Create a new peering to local AMQP server
    peering = amq_peering_new ("localhost", "/", 1, "amq.direct", "direct");

    //  Set login credentials
    amq_peering_set_login (peering, "peering");

    //  Register handlers, with no object reference, for this test
    amq_peering_set_status_handler  (peering, s_test_status_handler, NULL);
    amq_peering_set_content_handler (peering, s_test_content_handler, NULL);

    //  Start the peering - connects to the AMQP server
    amq_peering_start (peering);

    //  Make some peering bindings, with pauses so we can see how the
    //  peering handles if we stop/restart the other server
    apr_sleep (1 * seconds);
    icl_console_print ("I: (TEST) Making binding rk-aaaaaa");
    amq_peering_bind (peering, "rk-aaaaaa", NULL);

    apr_sleep (1 * seconds);
    icl_console_print ("I: (TEST) Stopping the peering...");
    amq_peering_stop (peering);

    apr_sleep (1 * seconds);
    icl_console_print ("I: (TEST) Making binding rk-bbbbbb");
    amq_peering_bind (peering, "rk-bbbbbb", NULL);

    apr_sleep (1 * seconds);
    icl_console_print ("I: (TEST) Restarting the peering...");
    amq_peering_start (peering);

    apr_sleep (1 * seconds);
    icl_console_print ("I: (TEST) Making binding rk-cccccc");
    amq_peering_bind (peering, "rk-cccccc", NULL);

    //  Publish a message to each binding, check that it arrives
    content = amq_content_basic_new ();
    amq_peering_forward (peering, "rk-aaaaaa", content, FALSE, FALSE);
    amq_peering_forward (peering, "rk-bbbbbb", content, FALSE, FALSE);
    amq_peering_forward (peering, "rk-cccccc", content, FALSE, FALSE);
    amq_content_basic_unlink (&content);

    icl_console_print ("I: (TEST) Finished - press Ctrl-C when done");
    smt_wait (0);                   //  Execute SMT engine

    amq_peering_destroy (&peering);
    broker_ref = amq_broker_link (amq_broker);
    amq_broker_destroy  (&broker_ref);
    amq_console_destroy (&amq_console);
    smt_wait (0);

    amq_broker_unlink (&amq_broker);
    smt_wait (0);

    amq_server_config_destroy (&amq_server_config);
}
}
/*  -------------------------------------------------------------------------
    amq_peering_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_peering_destroy_ (
    amq_peering_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_peering_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = amq_peering_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_peering_free (self);
    *self_p = NULL;
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_peering_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_peering_unlink_ (
    amq_peering_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
    int
        history_last;
#endif
    amq_peering_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_peering object");
            amq_peering_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_PEERING_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_PEERING_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_PEERING_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_PEERING_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_peering_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_peering_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
}
/*  -------------------------------------------------------------------------
    amq_peering_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_peering_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_peering_animating = enabled;

amq_peering_agent_animate (enabled);
}
/*  -------------------------------------------------------------------------
    amq_peering_free

    Type: Component method
    Freess a amq_peering_t object.
    -------------------------------------------------------------------------
 */

void
    amq_peering_free_ (
    amq_peering_t * self,               //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_PEERING_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_PEERING_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_PEERING_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_PEERING_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (amq_peering_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_peering_t));
        self->object_tag = AMQ_PEERING_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_peering_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_peering_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_peering_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_peering zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
    if (self->history_last > AMQ_PEERING_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_PEERING_HISTORY_LENGTH;
        self->history_last %= AMQ_PEERING_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_PEERING_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_peering>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_peering_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_peering_t *
    amq_peering_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_peering_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_peering_cache_initialise ();

self = (amq_peering_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_peering_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_peering_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_peering_t *
    amq_peering_link_ (
    amq_peering_t * self,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
    int
        history_last;
#endif

    if (self) {
        AMQ_PEERING_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_PEERING)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_PEERING_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_PEERING_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_PEERING_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_PEERING_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_peering_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_peering_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_peering_t));
icl_system_register (amq_peering_cache_purge, amq_peering_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_peering_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_peering_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_peering_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_peering_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_peering_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_peering_new_in_scope_ (
    amq_peering_t * * self_p,           //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * host,                        //  Host to connect to
    char * virtual_host,                //  Virtual host
    int trace,                          //  Trace level, 0 - 3
    char * exchange,                    //  Remote exchange name
    char* exchange_type                 //  Remote exchange type
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_peering_new_ (file,line,host,virtual_host,trace,exchange,exchange_type);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_peering_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
static int
s_test_status_handler (
    void *caller,
    amq_peering_t *peering,
    Bool status)
{
    if (status)
        icl_console_print ("I: (TEST) peering now connected to %s", peering->host);
    else
        icl_console_print ("W: (TEST) peering disconnected from %s", peering->host);

    return (0);
}

static int
s_test_content_handler (
    void *caller,
    amq_peering_t *peering,
    amq_peer_method_t *method)
{
    icl_console_print ("I: (TEST) received message from peering");
    return (0);
}

//  Embed the version information in the resulting binary

char *EMBED__amq_peering_version_start    = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_peering_component        = "amq_peering ";
char *EMBED__amq_peering_version          = "1.0 ";
char *EMBED__amq_peering_copyright        = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_peering_filename         = "amq_peering.icl ";
char *EMBED__amq_peering_builddate        = "2010/10/06 ";
char *EMBED__amq_peering_version_end      = "VeRsIoNeNd:ipc";

