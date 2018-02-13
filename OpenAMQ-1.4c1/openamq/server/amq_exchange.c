/*---------------------------------------------------------------------------
    amq_exchange.c - amq_exchange component

This class implements the server exchange, an asynchronous
object that acts as a envelope for the separate exchange managers
for each type of exchange. This is a lock-free asynchronous class.
    Generated from amq_exchange.icl by smt_object_gen using GSL/4.
    
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
#include "amq_exchange.h"               //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_exchange_t

//  Shorthands for class methods

#define self_new            amq_exchange_new
#define self_annihilate     amq_exchange_annihilate
#define self_type_lookup    amq_exchange_type_lookup
#define self_type_name      amq_exchange_type_name
#define self_bind_queue     amq_exchange_bind_queue
#define self_unbind_queue   amq_exchange_unbind_queue
#define self_publish        amq_exchange_publish
#define self_broker_unbind_queue  amq_exchange_broker_unbind_queue
#define self_selftest       amq_exchange_selftest
#define self_count          amq_exchange_count
#define self_inspect_shim   amq_exchange_inspect_shim
#define self_inspect        amq_exchange_inspect
#define self_modify_shim    amq_exchange_modify_shim
#define self_modify         amq_exchange_modify
#define self_method_shim    amq_exchange_method_shim
#define self_method         amq_exchange_method
#define self_unlink_shim    amq_exchange_unlink_shim
#define self_initialise     amq_exchange_initialise
#define self_terminate      amq_exchange_terminate
#define self_remove_from_all_containers  amq_exchange_remove_from_all_containers
#define self_show           amq_exchange_show
#define self_destroy        amq_exchange_destroy
#define self_unlink         amq_exchange_unlink
#define self_show_animation  amq_exchange_show_animation
#define self_free           amq_exchange_free
#define self_alloc          amq_exchange_alloc
#define self_link           amq_exchange_link
#define self_cache_initialise  amq_exchange_cache_initialise
#define self_cache_purge    amq_exchange_cache_purge
#define self_cache_terminate  amq_exchange_cache_terminate
#define self_new_in_scope   amq_exchange_new_in_scope

#define amq_exchange_annihilate(self)   amq_exchange_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_exchange_annihilate_ (
amq_exchange_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_exchange_initialise (
void);

#define amq_exchange_alloc()            amq_exchange_alloc_ (__FILE__, __LINE__)
static amq_exchange_t *
    amq_exchange_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_exchange_cache_initialise (
void);

static void
    amq_exchange_cache_purge (
void);

static void
    amq_exchange_cache_terminate (
void);

Bool
    amq_exchange_animating = TRUE;      //  Animation enabled by default
static Bool
    s_amq_exchange_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_exchange_mutex     = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static amq_console_class_t
    *s_class;                           //  Class descriptor
qbyte
    gbl_amq_exchange_count = 0;
/*  -------------------------------------------------------------------------
    amq_exchange_new

    Type: Component method
    Creates and initialises a new amq_exchange_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

amq_exchange_t *
    amq_exchange_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    int type,                           //  Exchange type
    char * name,                        //  Exchange name
    Bool internal,                      //  Internal exchange?
    Bool auto_federate                  //  Auto-federate exchange?
)
{
#define table amq_broker->exchange_table
#define key name
ipr_config_t
    *config;
char
    *federation_attach,             //  Host to attach to
    *federation_vhost,              //  Virtual host
    *federation_login;              //  Login name
int
    federation_type;                //  Federation type
char
    *type_name;                     //  Federation type text
Bool
    federation_valid;               //  Is federation configured?
    amq_exchange_t *
        self = NULL;                    //  Object reference

if (!s_amq_exchange_active)
    self_initialise ();
    self = amq_exchange_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_EXCHANGE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_exchange_show_);
#endif

self->console = amq_console_link (amq_console);
self->object_id = icl_atomic_inc32 ((volatile qbyte *) &amq_object_id);
amq_console_register (self->console, self->object_id, self_link (self), s_class, amq_broker->object_id);
self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->thread = amq_exchange_agent_class_thread_new (self);
self->thread->animate = TRUE;

icl_atomic_inc32 ((volatile qbyte *) &gbl_amq_exchange_count);

//
self->type           = type;
self->internal       = internal;
self->binding_list   = amq_binding_list_new ();
self->binding_hash   = ipr_hash_table_new ();
self->binding_index  = ipr_index_new ();
self->queue_bindings = amq_queue_bindings_list_table_new ();
self->queue_set      = icl_mem_alloc (AMQ_QUEUE_SET_MAX * sizeof (amq_queue_t *));
icl_shortstr_cpy (self->name, name);

if (!self->internal && amq_server_config_debug_route (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "X: create   exchange=%s type=%s", self->name, amq_exchange_type_name (self->type));

if (self->type == AMQ_EXCHANGE_SYSTEM) {
    self->object  = amq_exchange_system_new (self);
    self->publish = amq_exchange_system_publish;
    self->compile = amq_exchange_system_compile;
    self->unbind  = amq_exchange_system_unbind;
}
else
if (self->type == AMQ_EXCHANGE_FANOUT) {
    self->object  = amq_exchange_fanout_new (self);
    self->publish = amq_exchange_fanout_publish;
    self->compile = amq_exchange_fanout_compile;
    self->unbind  = amq_exchange_fanout_unbind;
}
else
if (self->type == AMQ_EXCHANGE_DIRECT) {
    self->object  = amq_exchange_direct_new (self);
    self->publish = amq_exchange_direct_publish;
    self->compile = amq_exchange_direct_compile;
    self->unbind  = amq_exchange_direct_unbind;
}
else
if (self->type == AMQ_EXCHANGE_TOPIC) {
    self->object  = amq_exchange_topic_new (self);
    self->publish = amq_exchange_topic_publish;
    self->compile = amq_exchange_topic_compile;
    self->unbind  = amq_exchange_topic_unbind;
}
else
if (self->type == AMQ_EXCHANGE_HEADERS) {
    self->object  = amq_exchange_headers_new (self);
    self->publish = amq_exchange_headers_publish;
    self->compile = amq_exchange_headers_compile;
    self->unbind  = amq_exchange_headers_unbind;
}
else
if (self->type == AMQ_EXCHANGE_REGEXP) {
    self->object  = amq_exchange_regexp_new (self);
    self->publish = amq_exchange_regexp_publish;
    self->compile = amq_exchange_regexp_compile;
    self->unbind  = amq_exchange_regexp_unbind;
}
else
    smt_log_print (amq_broker->alert_log,
        "E: invalid type '%d' in exchange_new", self->type);

amq_exchange_list_queue (amq_broker->exchange_list, self);

//  EXCHANGE FEDERATION ===================================================
//
//  Option 1: auto-federation using --attach, federates ESB exchanges
//  (amq.service, amq.data, amq.dataex).  Fine tune using --attach-vhost
//  and --attach-login.  Expand to more exchanges using --attach-all.
//
//  Option 2: manual federation using federate profiles. Command
//  line values act as defaults for these profiles.
//
//  federate
//      exchange = "pattern"    Name or wildcard using *
//      attach = "hostname"     Default is --attach if specified
//    [ vhost = "path" ]        Default is --attach-path ("/")
//    [ login = "userid" ]      Default is --attach-login ("peering")
//    [ type = "service | data | subscriber | publisher | locator" ]
//                              Default is 'service' for direct exchanges
//                              and 'fanout' for all others.
//
//  Internal, default, and system exchanges cannot be federated.
//  =======================================================================

//  Take default settings from federation section (or command line)
federation_valid  = FALSE;
federation_attach = amq_server_config_attach       (amq_server_config);
federation_vhost  = amq_server_config_attach_vhost (amq_server_config);
federation_login  = amq_server_config_attach_login (amq_server_config);
federation_type   = (self->type == AMQ_EXCHANGE_HEADERS)?
                    AMQ_FEDERATION_SERVICE: AMQ_FEDERATION_FANOUT;

//  First take settings from configuration file if possible
config = ipr_config_dup (amq_server_config_table (amq_server_config));
ipr_config_locate (config, "/config/federate", "");
while (config->located) {
    char
        *pattern = ipr_config_get (config, "exchange", NULL);
        if (pattern) {
            if (ipr_str_matches (name, pattern))
                break;          //  We have a match
        }
        else
            icl_console_print ("E: missing 'exchange' name in <federate>");
    ipr_config_next (config);
}
if (config->located) {
    //  We take the attach host, vhost, and login from the specific
    //  federate entry.  If not set there, we default to whatever
    //  was used on the command line, which can override the values
    //  set in the federation section.  This lets users work with
    //  only the command line, or only the configured entries, or a
    //  mix of the two.
    //
    federation_attach = ipr_config_get (config, "attach", federation_attach);
    federation_vhost  = ipr_config_get (config, "vhost",  federation_vhost);
    federation_login  = ipr_config_get (config, "login",  federation_login);

    //  Override default type if explicit federation type set
    type_name = ipr_config_get (config, "type", NULL);
    if (type_name) {
        federation_type = amq_federation_type_lookup (type_name);
        if (federation_type > 0)
            federation_valid = TRUE;
        else
        if (federation_type < 0)
            icl_console_print ("E: invalid type '%s' in <federate>", type_name);
    }
    else
    if (*federation_attach)
        federation_valid = TRUE;    //  Using default federation type
}
else
if (*federation_attach) {
    //  Federate if exchange created with auto-federation
    //  or if the name matches the --attach-all pattern
    if (auto_federate
    ||  ipr_str_matches (name, amq_server_config_attach_all (amq_server_config)))
        federation_valid = TRUE;
}
//  We don't federate system, internal, or the default exchange
if (self->type == AMQ_EXCHANGE_SYSTEM || internal || streq (name, "$default$"))
    federation_valid = FALSE;

if (federation_valid) {
    self->federation = amq_federation_new (
        self,
        federation_type,
        federation_attach,
        federation_vhost,
        federation_login);
    self->federation_type = federation_type;
}
ipr_config_destroy (&config);
if (table && self && amq_exchange_table_insert (table, key, self))
    amq_exchange_destroy (&self);
}

    return (self);
}
#undef table
#undef key
/*  -------------------------------------------------------------------------
    amq_exchange_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_exchange_annihilate_ (
    amq_exchange_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
    int
        history_last;
#endif

    amq_exchange_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (amq_exchange_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_exchange agent");
        rc = -1;
    }
}
else
    rc = -1;

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_type_lookup

    Type: Component method
    Translates an exchange type name into an internal type number.  If
    the type name is not valid, returns -1, else returns one of the
    type numbers supported by this implementation.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_type_lookup (
    char * type_name                    //  Type name to lookup
)
{
    int
        rc;                             //  Type number

//
if (streq (type_name, "system"))
    rc = AMQ_EXCHANGE_SYSTEM;
else
if (streq (type_name, "fanout"))
    rc = AMQ_EXCHANGE_FANOUT;
else
if (streq (type_name, "direct"))
    rc = AMQ_EXCHANGE_DIRECT;
else
if (streq (type_name, "topic"))
    rc = AMQ_EXCHANGE_TOPIC;
else
if (streq (type_name, "headers"))
    rc = AMQ_EXCHANGE_HEADERS;
else
if (streq (type_name, "regexp"))
    rc = AMQ_EXCHANGE_REGEXP;
else
    rc = -1;

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_type_name

    Type: Component method
    Translates an exchange type index into an external name.
    -------------------------------------------------------------------------
 */

char *
    amq_exchange_type_name (
    int type                            //  Type index to translate
)
{
    char *
        name;                           //  Type name

//
if (type == AMQ_EXCHANGE_SYSTEM)
    name = "system";
else
if (type == AMQ_EXCHANGE_FANOUT)
    name = "fanout";
else
if (type == AMQ_EXCHANGE_DIRECT)
    name = "direct";
else
if (type == AMQ_EXCHANGE_TOPIC)
    name = "topic";
else
if (type == AMQ_EXCHANGE_HEADERS)
    name = "headers";
else
if (type == AMQ_EXCHANGE_REGEXP)
    name = "regexp";
else
    name = "(unknown)";

    return (name);
}
/*  -------------------------------------------------------------------------
    amq_exchange_bind_queue

    Type: Component method
    Accepts a amq_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Bind a queue to the exchange.  The logic is the same for all exchange
    types - we compare all existing bindings and if we find one that
    matches our arguments (has identical arguments) we attach the queue
    to the binding.  Otherwise we create a new binding and compile it
    into the exchange, this operation being exchange type-specific.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_bind_queue (
    amq_exchange_t * self,              //  Reference to object
    amq_server_channel_t * channel,     //  Channel for reply
    amq_queue_t * queue,                //  The queue to bind
    char * routing_key,                 //  Bind to routing key
    icl_longstr_t * arguments           //  Bind arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_EXCHANGE_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_exchange_agent_bind_queue (self->thread,channel,queue,routing_key,arguments)) {
        //icl_console_print ("Error sending 'bind queue' method to amq_exchange agent");
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
    amq_exchange_unbind_queue

    Type: Component method
    Accepts a amq_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Unbind a queue from the exchange.  This method implements the queue.unbind
    protocol command.  We search for the specific binding to unbind, as opposed
    to the "broker unbind queue" method which destroys all the bindings from a
    specified queue.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_unbind_queue (
    amq_exchange_t * self,              //  Reference to object
    amq_server_channel_t * channel,     //  Channel for reply
    amq_queue_t * queue,                //  The queue to bind
    char * routing_key,                 //  Bind to routing key
    icl_longstr_t * arguments           //  Bind arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_EXCHANGE_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_exchange_agent_unbind_queue (self->thread,channel,queue,routing_key,arguments)) {
        //icl_console_print ("Error sending 'unbind queue' method to amq_exchange agent");
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
    amq_exchange_publish

    Type: Component method
    Accepts a amq_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Publishes the message to the exchange.  The actual routing mechanism
    is defined in the exchange implementations.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_publish (
    amq_exchange_t * self,              //  Reference to object
    amq_server_channel_t * channel,     //  Channel for reply
    amq_content_basic_t * content,      //  Content to publish
    Bool mandatory,                     //  Route to queue or return?
    Bool immediate,                     //  Send immediately or return?
    int group                           //  User group, from connection
)
{
    int
        rc = 0;                         //  Return code

AMQ_EXCHANGE_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_exchange_agent_publish (self->thread,channel,content,mandatory,immediate,group)) {
        //icl_console_print ("Error sending 'publish' method to amq_exchange agent");
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
    amq_exchange_broker_unbind_queue

    Type: Component method
    Accepts a amq_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Unbind a queue from the exchange. Called when queue is being destroyed.
    All the bindings to specific queue are destroyed.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_broker_unbind_queue (
    amq_exchange_t * self,              //  Reference to object
    amq_queue_t * queue                 //  The queue to unbind
)
{
    int
        rc = 0;                         //  Return code

AMQ_EXCHANGE_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_exchange_agent_broker_unbind_queue (self->thread,queue)) {
        //icl_console_print ("Error sending 'broker unbind queue' method to amq_exchange agent");
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
    amq_exchange_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_exchange_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_exchange_count (
void)
{
    qbyte
        count;                          //  Number of instances

count = (int) gbl_amq_exchange_count;

    return (count);
}
/*  -------------------------------------------------------------------------
    amq_exchange_inspect_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_exchange_inspect_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Not documented

self_inspect ((amq_exchange_t *) (self_v), request);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_inspect

    Type: Component method
    Accepts a amq_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_inspect (
    amq_exchange_t * self,              //  Reference to object
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Return code

AMQ_EXCHANGE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_exchange_agent_inspect (self->thread,request)) {
        //icl_console_print ("Error sending 'inspect' method to amq_exchange agent");
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
    amq_exchange_modify_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_exchange_modify_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

self_modify ((amq_exchange_t *) (self_v), request, fields);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_modify

    Type: Component method
    Accepts a amq_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_modify (
    amq_exchange_t * self,              //  Reference to object
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Return code

AMQ_EXCHANGE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_exchange_agent_modify (self->thread,request,fields)) {
        //icl_console_print ("Error sending 'modify' method to amq_exchange agent");
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
    amq_exchange_method_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_exchange_method_shim (
    void * self_v,                      //  Object cast as a void *
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

self_method ((amq_exchange_t *) (self_v), method_name, request, fields);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_method

    Type: Component method
    Accepts a amq_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_method (
    amq_exchange_t * self,              //  Reference to object
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Argument fields
)
{
    int
        rc = 0;                         //  Return code

AMQ_EXCHANGE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_exchange_agent_method (self->thread,method_name,request,fields)) {
        //icl_console_print ("Error sending 'method' method to amq_exchange agent");
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
    amq_exchange_unlink_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_unlink_shim (
    void * object_p                     //  Reference pointer cast as a void *
)
{

//
amq_exchange_unlink (((amq_exchange_t **) object_p));
}
/*  -------------------------------------------------------------------------
    amq_exchange_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_exchange_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_exchange_mutex)
            s_amq_exchange_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_exchange_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_exchange_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_exchange_agent_init ();

s_class = amq_console_class_new ();
s_class->name    = "exchange";
s_class->inspect = amq_exchange_inspect_shim;
s_class->modify  = amq_exchange_modify_shim;
s_class->method  = amq_exchange_method_shim;
s_class->unlink  = amq_exchange_unlink_shim;
            s_amq_exchange_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_exchange_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    amq_exchange_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_terminate (
void)
{

if (s_amq_exchange_active) {

amq_console_class_destroy (&s_class);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_exchange_mutex);
#endif
        s_amq_exchange_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    amq_exchange_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_exchange_remove_from_all_containers (
    amq_exchange_t * self               //  The itemThe item
)
{

AMQ_EXCHANGE_ASSERT_SANE (self);
amq_exchange_table_remove (self);
amq_exchange_list_remove (self);
}
/*  -------------------------------------------------------------------------
    amq_exchange_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_exchange_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
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

    fprintf (trace_file, "    <amq_exchange zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
    if (self->history_last > AMQ_EXCHANGE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_EXCHANGE_HISTORY_LENGTH;
        self->history_last %= AMQ_EXCHANGE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_EXCHANGE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_exchange>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_exchange_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_exchange_destroy_ (
    amq_exchange_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_exchange_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

    if (self) {
amq_exchange_remove_from_all_containers (self);
        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            rc = amq_exchange_annihilate_ (self_p, file, line);
        else
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
            amq_exchange_free (self);
        *self_p = NULL;
    }

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_exchange_unlink_ (
    amq_exchange_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
    int
        history_last;
#endif
    amq_exchange_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_exchange object");
            amq_exchange_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_exchange_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_exchange_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
}
/*  -------------------------------------------------------------------------
    amq_exchange_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_exchange_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_exchange_animating = enabled;

amq_exchange_agent_animate (enabled);
}
/*  -------------------------------------------------------------------------
    amq_exchange_free

    Type: Component method
    Freess a amq_exchange_t object.
    -------------------------------------------------------------------------
 */

void
    amq_exchange_free_ (
    amq_exchange_t * self,              //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (amq_exchange_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_exchange_t));
        self->object_tag = AMQ_EXCHANGE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_exchange_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_exchange_t *
    amq_exchange_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_exchange_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_exchange_cache_initialise ();

self = (amq_exchange_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_exchange_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_exchange_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_exchange_t *
    amq_exchange_link_ (
    amq_exchange_t * self,              //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
    int
        history_last;
#endif

    if (self) {
        AMQ_EXCHANGE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_EXCHANGE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_EXCHANGE_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_exchange_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_exchange_t));
icl_system_register (amq_exchange_cache_purge, amq_exchange_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_exchange_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_exchange_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_exchange_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_new_in_scope_ (
    amq_exchange_t * * self_p,          //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    int type,                           //  Exchange type
    char * name,                        //  Exchange name
    Bool internal,                      //  Internal exchange?
    Bool auto_federate                  //  Auto-federate exchange?
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_exchange_new_ (file,line,type,name,internal,auto_federate);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_exchange_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_exchange_version_start   = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_exchange_component       = "amq_exchange ";
char *EMBED__amq_exchange_version         = "1.0 ";
char *EMBED__amq_exchange_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_exchange_filename        = "amq_exchange.icl ";
char *EMBED__amq_exchange_builddate       = "2010/10/06 ";
char *EMBED__amq_exchange_version_end     = "VeRsIoNeNd:ipc";

