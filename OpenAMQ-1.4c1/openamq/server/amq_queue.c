/*---------------------------------------------------------------------------
    amq_queue.c - amq_queue component

This class implements the server queue class, an asynchronous object
that acts as a envelope for the separate queue managers for each
class.  This is a lock-free asynchronous class.
    Generated from amq_queue.icl by smt_object_gen using GSL/4.
    
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
#include "amq_queue.h"                  //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_queue_t

//  Shorthands for class methods

#define self_new            amq_queue_new
#define self_annihilate     amq_queue_annihilate
#define self_unbind_connection  amq_queue_unbind_connection
#define self_publish        amq_queue_publish
#define self_get            amq_queue_get
#define self_consume        amq_queue_consume
#define self_cancel         amq_queue_cancel
#define self_self_destruct  amq_queue_self_destruct
#define self_consumer_ack   amq_queue_consumer_ack
#define self_purge          amq_queue_purge
#define self_dispatch       amq_queue_dispatch
#define self_message_count  amq_queue_message_count
#define self_consumer_count  amq_queue_consumer_count
#define self_binding_register  amq_queue_binding_register
#define self_binding_cancel  amq_queue_binding_cancel
#define self_selftest       amq_queue_selftest
#define self_count          amq_queue_count
#define self_inspect_shim   amq_queue_inspect_shim
#define self_inspect        amq_queue_inspect
#define self_modify_shim    amq_queue_modify_shim
#define self_modify         amq_queue_modify
#define self_method_shim    amq_queue_method_shim
#define self_method         amq_queue_method
#define self_unlink_shim    amq_queue_unlink_shim
#define self_initialise     amq_queue_initialise
#define self_terminate      amq_queue_terminate
#define self_remove_from_all_containers  amq_queue_remove_from_all_containers
#define self_show           amq_queue_show
#define self_destroy        amq_queue_destroy
#define self_unlink         amq_queue_unlink
#define self_show_animation  amq_queue_show_animation
#define self_free           amq_queue_free
#define self_alloc          amq_queue_alloc
#define self_link           amq_queue_link
#define self_cache_initialise  amq_queue_cache_initialise
#define self_cache_purge    amq_queue_cache_purge
#define self_cache_terminate  amq_queue_cache_terminate
#define self_new_in_scope   amq_queue_new_in_scope

#define amq_queue_annihilate(self)      amq_queue_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_queue_annihilate_ (
amq_queue_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_queue_initialise (
void);

#define amq_queue_alloc()               amq_queue_alloc_ (__FILE__, __LINE__)
static amq_queue_t *
    amq_queue_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_queue_cache_initialise (
void);

static void
    amq_queue_cache_purge (
void);

static void
    amq_queue_cache_terminate (
void);

Bool
    amq_queue_animating = TRUE;         //  Animation enabled by default
static Bool
    s_amq_queue_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_queue_mutex        = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static amq_console_class_t
    *s_class;                           //  Class descriptor
qbyte
    gbl_amq_queue_count = 0;
static int
    s_set_queue_limits (amq_queue_t *self, char *profile);
/*  -------------------------------------------------------------------------
    amq_queue_new

    Type: Component method
    Creates and initialises a new amq_queue_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

amq_queue_t *
    amq_queue_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_server_connection_t * connection,   //  Owner connection
    char * name,                        //  Queue name
    Bool exclusive,                     //  Is queue exclusive?
    Bool auto_delete,                   //  Auto-delete unused queue?
    icl_longstr_t* arguments            //  Queue arguments
)
{
#define table amq_broker->queue_table
#define key name
asl_field_list_t
    *arg_list;
asl_field_t
    *profile_field;
char
    *profile;
    amq_queue_t *
        self = NULL;                    //  Object reference

if (!s_amq_queue_active)
    self_initialise ();
    self = amq_queue_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_QUEUE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_queue_show_);
#endif

self->console = amq_console_link (amq_console);
self->object_id = icl_atomic_inc32 ((volatile qbyte *) &amq_object_id);
amq_console_register (self->console, self->object_id, self_link (self), s_class, amq_broker->object_id);
self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->thread = amq_queue_agent_class_thread_new (self);
self->thread->animate = TRUE;

icl_atomic_inc32 ((volatile qbyte *) &gbl_amq_queue_count);

//
self->connection  = amq_server_connection_link (connection);
self->enabled     = TRUE;
self->exclusive   = exclusive;
self->auto_delete = auto_delete;
self->queue_basic = amq_queue_basic_new (self);
self->bindings    = ipr_looseref_list_new ();
icl_shortstr_cpy (self->name, name);
amq_queue_list_queue (amq_broker->queue_list, self);
if (amq_server_config_debug_queue (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "Q: create   queue=%s auto_delete=%d", self->name, self->auto_delete);
//  Process arguments
arg_list = asl_field_list_new (arguments);
if (!arg_list) {
    //  Catch case where field list is malformed
    amq_server_connection_error (NULL, ASL_SYNTAX_ERROR,
        "Malformed 'arguments' field in queue.declare",
        AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
    self_destroy (&self);
}
else {
    //  If unspecified, queue profile defaults to 'private' for exclusive
    //  queues, 'shared' for shared queues
    profile_field = asl_field_list_search (arg_list, "profile");
    if (!profile_field)
        profile = self->exclusive? "private": "shared";
    else
        profile = asl_field_string (profile_field);
    //  Reject unknown queue profiles
    if (s_set_queue_limits (self, profile)) {
        smt_log_print (amq_broker->alert_log,
            "E: client requested unknown queue profile '%s' (%s, %s, %s, %s)",
            profile,
            self->connection->client_address,
            self->connection->client_product,
            self->connection->client_version,
            self->connection->client_instance);
        amq_server_connection_error (connection, ASL_SYNTAX_ERROR,
            "Unknown queue profile requested",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
        if (profile_field)
            asl_field_destroy (&profile_field);
        asl_field_list_destroy (&arg_list);
        self_destroy (&self);
    }
    if (profile_field)
        asl_field_destroy (&profile_field);
    asl_field_list_destroy (&arg_list);
}
if (table && self && amq_queue_table_insert (table, key, self))
    amq_queue_destroy (&self);
}

    return (self);
}
#undef table
#undef key
/*  -------------------------------------------------------------------------
    amq_queue_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_queue_annihilate_ (
    amq_queue_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    int
        history_last;
#endif

    amq_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_QUEUE_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (amq_queue_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_queue agent");
        rc = -1;
    }
}
else
    rc = -1;

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_unbind_connection

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_queue_unbind_connection (
    amq_queue_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_queue_agent_unbind_connection (self->thread)) {
        //icl_console_print ("Error sending 'unbind connection' method to amq_queue agent");
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
    amq_queue_publish

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Publish message content onto queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_publish (
    amq_queue_t * self,                 //  Reference to object
    amq_server_channel_t * channel,     //  Channel for reply
    amq_content_basic_t * content,      //  Content to publish
    Bool immediate                      //  Send immediately or return?
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_publish (self->thread,channel,content,immediate)) {
        //icl_console_print ("Error sending 'publish' method to amq_queue agent");
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
    amq_queue_get

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Returns next message off queue, if any.
    -------------------------------------------------------------------------
 */

int
    amq_queue_get (
    amq_queue_t * self,                 //  Reference to object
    amq_server_channel_t * channel,     //  Channel for reply
    int class_id                        //  The content class
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_get (self->thread,channel,class_id)) {
        //icl_console_print ("Error sending 'get' method to amq_queue agent");
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
    amq_queue_consume

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Attach consumer to appropriate queue consumer list.
    -------------------------------------------------------------------------
 */

int
    amq_queue_consume (
    amq_queue_t * self,                 //  Reference to object
    amq_consumer_t * consumer,          //  Consumer reference
    Bool active,                        //  Create active consumer?
    Bool nowait                         //  No reply method wanted
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_consume (self->thread,consumer,active,nowait)) {
        //icl_console_print ("Error sending 'consume' method to amq_queue agent");
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
    amq_queue_cancel

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Cancel consumer, by reference, and alert client application if
    we're doing this in a synchronous exchange of methods.  If the
    cancel is being done at channel close, no notify will be sent
    back to the client.
    -------------------------------------------------------------------------
 */

int
    amq_queue_cancel (
    amq_queue_t * self,                 //  Reference to object
    amq_consumer_t * consumer,          //  Consumer reference
    Bool notify,                        //  Notify client application?
    Bool nowait                         //  No reply method wanted
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_cancel (self->thread,consumer,notify,nowait)) {
        //icl_console_print ("Error sending 'cancel' method to amq_queue agent");
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
    amq_queue_self_destruct

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Self-destruct the queue.  This is somewhat delicate because it's
    an async object, and because it's linked to by exchanges/bindings
    and by connections.
    -------------------------------------------------------------------------
 */

int
    amq_queue_self_destruct (
    amq_queue_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_self_destruct (self->thread)) {
        //icl_console_print ("Error sending 'self destruct' method to amq_queue agent");
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
    amq_queue_consumer_ack

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Acknowledge messages on consumer, if any.
    -------------------------------------------------------------------------
 */

int
    amq_queue_consumer_ack (
    amq_queue_t * self,                 //  Reference to object
    amq_consumer_t * consumer           //  Consumer to ack
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_consumer_ack (self->thread,consumer)) {
        //icl_console_print ("Error sending 'consumer ack' method to amq_queue agent");
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
    amq_queue_purge

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Purge all content on a queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_purge (
    amq_queue_t * self,                 //  Reference to object
    amq_server_channel_t * channel,     //  Channel for reply
    Bool nowait                         //  No reply method wanted
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_purge (self->thread,channel,nowait)) {
        //icl_console_print ("Error sending 'purge' method to amq_queue agent");
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
    amq_queue_dispatch

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Dispatches all pending messages waiting on the specified message queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_dispatch (
    amq_queue_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_dispatch (self->thread)) {
        //icl_console_print ("Error sending 'dispatch' method to amq_queue agent");
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
    amq_queue_message_count

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Return number of messages on queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_message_count (
    amq_queue_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

//
rc = amq_queue_basic_message_count (self->queue_basic);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_consumer_count

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Return number of consumers on queue.
    -------------------------------------------------------------------------
 */

int
    amq_queue_consumer_count (
    amq_queue_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

//
rc = amq_queue_basic_consumer_count (self->queue_basic);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_binding_register

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Register new binding for the queue.  The binding information is used
    by the console only.
    -------------------------------------------------------------------------
 */

int
    amq_queue_binding_register (
    amq_queue_t * self,                 //  Reference to object
    amq_exchange_t * exchange,          //  Not documented
    amq_binding_t * binding             //  Not documented
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_binding_register (self->thread,exchange,binding)) {
        //icl_console_print ("Error sending 'binding register' method to amq_queue agent");
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
    amq_queue_binding_cancel

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Cancel binding for the queue. The binding information is used
    by the console only.
    -------------------------------------------------------------------------
 */

int
    amq_queue_binding_cancel (
    amq_queue_t * self,                 //  Reference to object
    amq_exchange_t * exchange,          //  Not documented
    amq_binding_t * binding             //  Not documented
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (amq_queue_agent_binding_cancel (self->thread,exchange,binding)) {
        //icl_console_print ("Error sending 'binding cancel' method to amq_queue agent");
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
    amq_queue_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_queue_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_queue_count (
void)
{
    qbyte
        count;                          //  Number of instances

count = (int) gbl_amq_queue_count;

    return (count);
}
/*  -------------------------------------------------------------------------
    amq_queue_inspect_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_queue_inspect_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Not documented

self_inspect ((amq_queue_t *) (self_v), request);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_inspect

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_queue_inspect (
    amq_queue_t * self,                 //  Reference to object
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_queue_agent_inspect (self->thread,request)) {
        //icl_console_print ("Error sending 'inspect' method to amq_queue agent");
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
    amq_queue_modify_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_queue_modify_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

self_modify ((amq_queue_t *) (self_v), request, fields);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_modify

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_queue_modify (
    amq_queue_t * self,                 //  Reference to object
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_queue_agent_modify (self->thread,request,fields)) {
        //icl_console_print ("Error sending 'modify' method to amq_queue agent");
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
    amq_queue_method_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_queue_method_shim (
    void * self_v,                      //  Object cast as a void *
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

self_method ((amq_queue_t *) (self_v), method_name, request, fields);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_method

    Type: Component method
    Accepts a amq_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_queue_method (
    amq_queue_t * self,                 //  Reference to object
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Argument fields
)
{
    int
        rc = 0;                         //  Return code

AMQ_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_queue_agent_method (self->thread,method_name,request,fields)) {
        //icl_console_print ("Error sending 'method' method to amq_queue agent");
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
    amq_queue_unlink_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_unlink_shim (
    void * object_p                     //  Reference pointer cast as a void *
)
{

//
amq_queue_unlink (((amq_queue_t **) object_p));
}
/*  -------------------------------------------------------------------------
    amq_queue_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_queue_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_queue_mutex)
            s_amq_queue_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_queue_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_queue_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_queue_agent_init ();

s_class = amq_console_class_new ();
s_class->name    = "queue";
s_class->inspect = amq_queue_inspect_shim;
s_class->modify  = amq_queue_modify_shim;
s_class->method  = amq_queue_method_shim;
s_class->unlink  = amq_queue_unlink_shim;
            s_amq_queue_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_queue_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    amq_queue_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_terminate (
void)
{

if (s_amq_queue_active) {

amq_console_class_destroy (&s_class);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_queue_mutex);
#endif
        s_amq_queue_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    amq_queue_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_queue_remove_from_all_containers (
    amq_queue_t * self                  //  The itemThe item
)
{

AMQ_QUEUE_ASSERT_SANE (self);
amq_queue_table_remove (self);
amq_queue_list_remove (self);
}
/*  -------------------------------------------------------------------------
    amq_queue_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_queue_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
if (self->table_head)
   container_links++;
if (self->list_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_queue zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    if (self->history_last > AMQ_QUEUE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_QUEUE_HISTORY_LENGTH;
        self->history_last %= AMQ_QUEUE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_QUEUE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_queue>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_queue_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_queue_destroy_ (
    amq_queue_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

    if (self) {
amq_queue_remove_from_all_containers (self);
        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            rc = amq_queue_annihilate_ (self_p, file, line);
        else
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
            amq_queue_free (self);
        *self_p = NULL;
    }

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_queue_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_queue_unlink_ (
    amq_queue_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    int
        history_last;
#endif
    amq_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_queue object");
            amq_queue_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_QUEUE_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_queue_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_queue_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
}
/*  -------------------------------------------------------------------------
    amq_queue_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_queue_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_queue_animating = enabled;

amq_queue_agent_animate (enabled);
}
/*  -------------------------------------------------------------------------
    amq_queue_free

    Type: Component method
    Freess a amq_queue_t object.
    -------------------------------------------------------------------------
 */

void
    amq_queue_free_ (
    amq_queue_t * self,                 //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_QUEUE_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (amq_queue_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_queue_t));
        self->object_tag = AMQ_QUEUE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_queue_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_queue_t *
    amq_queue_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_queue_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_queue_cache_initialise ();

self = (amq_queue_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_queue_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_queue_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_queue_t *
    amq_queue_link_ (
    amq_queue_t * self,                 //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
    int
        history_last;
#endif

    if (self) {
        AMQ_QUEUE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_QUEUE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_QUEUE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_QUEUE_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_queue_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_queue_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_queue_t));
icl_system_register (amq_queue_cache_purge, amq_queue_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_queue_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_queue_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_queue_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_queue_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_queue_new_in_scope_ (
    amq_queue_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_server_connection_t * connection,   //  Owner connection
    char * name,                        //  Queue name
    Bool exclusive,                     //  Is queue exclusive?
    Bool auto_delete,                   //  Auto-delete unused queue?
    icl_longstr_t* arguments            //  Queue arguments
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_queue_new_ (file,line,connection,name,exclusive,auto_delete,arguments);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_queue_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
static int
s_set_queue_limits (amq_queue_t *self, char *profile)
{
    ipr_config_t
        *config;                        //  Current server config file
    qbyte
        limit_value;                    //  Specified limit value
    char
        *action_text;                   //  Limit action as string

    config = ipr_config_dup (amq_server_config_table (amq_server_config));
    ipr_config_locate (config, "/config/queue_profile", profile);

    if (!config->located) {
        ipr_config_destroy (&config);
        return 1;
    }
    if (config->located)
        ipr_config_locate (config, "limit", NULL);

    while (config->located) {
        action_text = ipr_config_get (config, "name", "(empty)");
        limit_value = atol (ipr_config_get (config, "value",  "0"));
        if (streq (action_text, "warn"))
            self->warn_limit = limit_value;
        else
        if (streq (action_text, "drop"))
            self->drop_limit = limit_value;
        else
        if (streq (action_text, "trim"))
            self->trim_limit = limit_value;
        else
        if (streq (action_text, "kill"))
            self->kill_limit = limit_value;
        else
            smt_log_print (amq_broker->alert_log,
                "E: invalid configured limit action '%s'", action_text);

        if (amq_server_config_debug_queue (amq_server_config))
            smt_log_print (amq_broker->debug_log,
                "Q: setlimit queue=%s limit=%d action=%s",
                self->name, limit_value, action_text);

        ipr_config_next (config);
    }
    ipr_config_destroy (&config);
    return (0);
}

//  Embed the version information in the resulting binary

char *EMBED__amq_queue_version_start      = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_queue_component          = "amq_queue ";
char *EMBED__amq_queue_version            = "1.0 ";
char *EMBED__amq_queue_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_queue_filename           = "amq_queue.icl ";
char *EMBED__amq_queue_builddate          = "2010/10/06 ";
char *EMBED__amq_queue_version_end        = "VeRsIoNeNd:ipc";

