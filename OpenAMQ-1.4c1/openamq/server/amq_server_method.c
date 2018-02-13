/*---------------------------------------------------------------------------
    amq_server_method.c - amq_server_method component

This class holds a method.  All protocol methods are held in a single
union that can be processed as a single entity.
    Generated from amq_server_method.icl by icl_gen using GSL/4.
    
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
#include "amq_server_method.h"          //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_server_method_t

//  Shorthands for class methods

#define self_new            amq_server_method_new
#define self_annihilate     amq_server_method_annihilate
#define self_initialise     amq_server_method_initialise
#define self_terminate      amq_server_method_terminate
#define self_new_connection_start  amq_server_method_new_connection_start
#define self_new_connection_secure  amq_server_method_new_connection_secure
#define self_new_connection_tune  amq_server_method_new_connection_tune
#define self_new_connection_open_ok  amq_server_method_new_connection_open_ok
#define self_new_connection_close  amq_server_method_new_connection_close
#define self_new_connection_close_ok  amq_server_method_new_connection_close_ok
#define self_new_channel_open_ok  amq_server_method_new_channel_open_ok
#define self_new_channel_flow  amq_server_method_new_channel_flow
#define self_new_channel_flow_ok  amq_server_method_new_channel_flow_ok
#define self_new_channel_close  amq_server_method_new_channel_close
#define self_new_channel_close_ok  amq_server_method_new_channel_close_ok
#define self_new_exchange_declare_ok  amq_server_method_new_exchange_declare_ok
#define self_new_exchange_delete_ok  amq_server_method_new_exchange_delete_ok
#define self_new_queue_declare_ok  amq_server_method_new_queue_declare_ok
#define self_new_queue_bind_ok  amq_server_method_new_queue_bind_ok
#define self_new_queue_purge_ok  amq_server_method_new_queue_purge_ok
#define self_new_queue_delete_ok  amq_server_method_new_queue_delete_ok
#define self_new_queue_unbind_ok  amq_server_method_new_queue_unbind_ok
#define self_new_basic_qos_ok  amq_server_method_new_basic_qos_ok
#define self_new_basic_consume_ok  amq_server_method_new_basic_consume_ok
#define self_new_basic_cancel_ok  amq_server_method_new_basic_cancel_ok
#define self_new_basic_return  amq_server_method_new_basic_return
#define self_new_basic_deliver  amq_server_method_new_basic_deliver
#define self_new_basic_get_ok  amq_server_method_new_basic_get_ok
#define self_new_basic_get_empty  amq_server_method_new_basic_get_empty
#define self_new_direct_put_ok  amq_server_method_new_direct_put_ok
#define self_new_direct_get_ok  amq_server_method_new_direct_get_ok
#define self_encode         amq_server_method_encode
#define self_decode         amq_server_method_decode
#define self_dump           amq_server_method_dump
#define self_execute        amq_server_method_execute
#define self_selftest       amq_server_method_selftest
#define self_show           amq_server_method_show
#define self_destroy        amq_server_method_destroy
#define self_alloc          amq_server_method_alloc
#define self_free           amq_server_method_free
#define self_link           amq_server_method_link
#define self_unlink         amq_server_method_unlink
#define self_cache_initialise  amq_server_method_cache_initialise
#define self_cache_purge    amq_server_method_cache_purge
#define self_cache_terminate  amq_server_method_cache_terminate
#define self_show_animation  amq_server_method_show_animation
#define self_new_in_scope   amq_server_method_new_in_scope

#define amq_server_method_annihilate(self)  amq_server_method_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_server_method_annihilate_ (
amq_server_method_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_server_method_initialise (
void);

static void
    amq_server_method_terminate (
void);

#define amq_server_method_alloc()       amq_server_method_alloc_ (__FILE__, __LINE__)
static amq_server_method_t *
    amq_server_method_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_server_method_free(self)    amq_server_method_free_ (self, __FILE__, __LINE__)
static void
    amq_server_method_free_ (
amq_server_method_t * self,             //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_server_method_cache_initialise (
void);

static void
    amq_server_method_cache_purge (
void);

static void
    amq_server_method_cache_terminate (
void);

Bool
    amq_server_method_animating = TRUE;  //  Animation enabled by default
static Bool
    s_amq_server_method_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_server_method_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static ipr_regexp_t
    *s_regexp_connection_virtual_host = NULL;
static ipr_regexp_t
    *s_regexp_exchange_exchange = NULL;
static ipr_regexp_t
    *s_regexp_exchange_type = NULL;
static ipr_regexp_t
    *s_regexp_queue_queue = NULL;
/*  -------------------------------------------------------------------------
    amq_server_method_new

    Type: Component method
    Creates and initialises a new amq_server_method_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_server_method_t *
        self = NULL;                    //  Object reference

if (!s_amq_server_method_active)
    self_initialise ();
    self = amq_server_method_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_SERVER_METHOD_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_server_method_show_);
#endif

self->class_id  = 0;
self->method_id = 0;
self->name      = NULL;
self->sync      = FALSE;
self->content   = NULL;
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_method_annihilate_ (
    amq_server_method_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
    int
        history_last;
#endif

    amq_server_method_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = self->links;
#endif

    AMQ_SERVER_METHOD_ASSERT_SANE (self);

if (self->class_id == AMQ_SERVER_CONNECTION) {
    if (self->method_id == AMQ_SERVER_CONNECTION_START) {
        icl_longstr_destroy (&self->payload.connection_start.server_properties);
        icl_longstr_destroy (&self->payload.connection_start.mechanisms);
        icl_longstr_destroy (&self->payload.connection_start.locales);
    }
    else
    if (self->method_id == AMQ_SERVER_CONNECTION_START_OK) {
        icl_longstr_destroy (&self->payload.connection_start_ok.client_properties);
        icl_longstr_destroy (&self->payload.connection_start_ok.response);
    }
    else
    if (self->method_id == AMQ_SERVER_CONNECTION_SECURE) {
        icl_longstr_destroy (&self->payload.connection_secure.challenge);
    }
    else
    if (self->method_id == AMQ_SERVER_CONNECTION_SECURE_OK) {
        icl_longstr_destroy (&self->payload.connection_secure_ok.response);
    }
}
else
if (self->class_id == AMQ_SERVER_CHANNEL) {
    if (self->method_id == AMQ_SERVER_CHANNEL_OPEN_OK) {
        icl_longstr_destroy (&self->payload.channel_open_ok.channel_id);
    }
}
else
if (self->class_id == AMQ_SERVER_EXCHANGE) {
    if (self->method_id == AMQ_SERVER_EXCHANGE_DECLARE) {
        icl_longstr_destroy (&self->payload.exchange_declare.arguments);
    }
}
else
if (self->class_id == AMQ_SERVER_QUEUE) {
    if (self->method_id == AMQ_SERVER_QUEUE_DECLARE) {
        icl_longstr_destroy (&self->payload.queue_declare.arguments);
    }
    else
    if (self->method_id == AMQ_SERVER_QUEUE_BIND) {
        icl_longstr_destroy (&self->payload.queue_bind.arguments);
    }
    else
    if (self->method_id == AMQ_SERVER_QUEUE_UNBIND) {
        icl_longstr_destroy (&self->payload.queue_unbind.arguments);
    }
}
else
if (self->class_id == AMQ_SERVER_BASIC) {
    amq_content_basic_t
        *content = (amq_content_basic_t *) self->content;
    amq_content_basic_unlink (&content);
    if (self->method_id == AMQ_SERVER_BASIC_CONSUME) {
        icl_longstr_destroy (&self->payload.basic_consume.arguments);
    }
}
else
assert (!self->content);            //  Non-destroyed content = error

}
/*  -------------------------------------------------------------------------
    amq_server_method_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_method_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_server_method_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_server_method_mutex)
            s_amq_server_method_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_server_method_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_server_method_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

s_regexp_connection_virtual_host = ipr_regexp_new ("^[a-zA-Z0-9/-_]+$");
s_regexp_exchange_exchange = ipr_regexp_new ("^[a-zA-Z0-9-_.:/]+$");
s_regexp_exchange_type = ipr_regexp_new ("^[a-zA-Z0-9-_.:/]+$");
s_regexp_queue_queue = ipr_regexp_new ("^[a-zA-Z0-9-_.:/]*$");
            s_amq_server_method_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_server_method_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    amq_server_method_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_method_terminate (
void)
{

if (s_amq_server_method_active) {

ipr_regexp_destroy (&s_regexp_connection_virtual_host);
ipr_regexp_destroy (&s_regexp_exchange_exchange);
ipr_regexp_destroy (&s_regexp_exchange_type);
ipr_regexp_destroy (&s_regexp_queue_queue);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_server_method_mutex);
#endif
        s_amq_server_method_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_connection_start

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_connection_start (
    int version_major,                  //  protocol major version
    int version_minor,                  //  protocol major version
    icl_longstr_t * server_properties,   //  server properties
    icl_longstr_t * mechanisms,         //  available security mechanisms
    icl_longstr_t * locales             //  available message locales
)
{
amq_server_connection_start_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.connection_start;
self->class_id  = AMQ_SERVER_CONNECTION;
self->method_id = AMQ_SERVER_CONNECTION_START;
self->name      = "connection.start";

//  Copy supplied values to method object
method->version_major   = (byte) version_major;
method->version_minor   = (byte) version_minor;
if (server_properties)
    method->server_properties  = icl_longstr_dup (server_properties);
else
    method->server_properties  = NULL;
if (mechanisms)
    method->mechanisms  = icl_longstr_dup (mechanisms);
else
    method->mechanisms  = NULL;
if (locales)
    method->locales     = icl_longstr_dup (locales);
else
    method->locales     = NULL;

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_connection_secure

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_connection_secure (
    icl_longstr_t * challenge           //  security challenge data
)
{
amq_server_connection_secure_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.connection_secure;
self->class_id  = AMQ_SERVER_CONNECTION;
self->method_id = AMQ_SERVER_CONNECTION_SECURE;
self->name      = "connection.secure";

//  Copy supplied values to method object
if (challenge)
    method->challenge   = icl_longstr_dup (challenge);
else
    method->challenge   = NULL;

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_connection_tune

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_connection_tune (
    int channel_max,                    //  proposed maximum channels
    qbyte frame_max,                    //  proposed maximum frame size
    int heartbeat                       //  desired heartbeat delay
)
{
amq_server_connection_tune_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.connection_tune;
self->class_id  = AMQ_SERVER_CONNECTION;
self->method_id = AMQ_SERVER_CONNECTION_TUNE;
self->name      = "connection.tune";

//  Copy supplied values to method object
method->channel_max     = (dbyte) channel_max;
method->frame_max       = frame_max;
method->heartbeat       = (dbyte) heartbeat;

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_connection_open_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_connection_open_ok (
    char * known_hosts                  //  list of known hosts
)
{
amq_server_connection_open_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.connection_open_ok;
self->class_id  = AMQ_SERVER_CONNECTION;
self->method_id = AMQ_SERVER_CONNECTION_OPEN_OK;
self->name      = "connection.open_ok";

//  Copy supplied values to method object
icl_shortstr_cpy (method->known_hosts,   known_hosts);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_connection_close

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_connection_close (
    int reply_code,                     //  reply code from server
    char * reply_text,                  //  localised reply text
    int class_id,                       //  failing method class
    int method_id                       //  failing method ID
)
{
amq_server_connection_close_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.connection_close;
self->class_id  = AMQ_SERVER_CONNECTION;
self->method_id = AMQ_SERVER_CONNECTION_CLOSE;
self->name      = "connection.close";

//  Copy supplied values to method object
method->reply_code      = (dbyte) reply_code;
method->class_id        = (dbyte) class_id;
method->method_id       = (dbyte) method_id;
icl_shortstr_cpy (method->reply_text,    reply_text);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_connection_close_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_connection_close_ok (
void)
{
amq_server_connection_close_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.connection_close_ok;
self->class_id  = AMQ_SERVER_CONNECTION;
self->method_id = AMQ_SERVER_CONNECTION_CLOSE_OK;
self->name      = "connection.close_ok";

//  Copy supplied values to method object

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_channel_open_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_channel_open_ok (
    icl_longstr_t * channel_id          //  unique id of the channel
)
{
amq_server_channel_open_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.channel_open_ok;
self->class_id  = AMQ_SERVER_CHANNEL;
self->method_id = AMQ_SERVER_CHANNEL_OPEN_OK;
self->name      = "channel.open_ok";

//  Copy supplied values to method object
if (channel_id)
    method->channel_id  = icl_longstr_dup (channel_id);
else
    method->channel_id  = NULL;

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_channel_flow

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_channel_flow (
    Bool active                         //  start/stop content frames
)
{
amq_server_channel_flow_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.channel_flow;
self->class_id  = AMQ_SERVER_CHANNEL;
self->method_id = AMQ_SERVER_CHANNEL_FLOW;
self->name      = "channel.flow";

//  Copy supplied values to method object
method->active          = active;

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_channel_flow_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_channel_flow_ok (
    Bool active                         //  current flow setting
)
{
amq_server_channel_flow_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.channel_flow_ok;
self->class_id  = AMQ_SERVER_CHANNEL;
self->method_id = AMQ_SERVER_CHANNEL_FLOW_OK;
self->name      = "channel.flow_ok";

//  Copy supplied values to method object
method->active          = active;

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_channel_close

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_channel_close (
    int reply_code,                     //  reply code from server
    char * reply_text,                  //  localised reply text
    int class_id,                       //  failing method class
    int method_id                       //  failing method ID
)
{
amq_server_channel_close_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.channel_close;
self->class_id  = AMQ_SERVER_CHANNEL;
self->method_id = AMQ_SERVER_CHANNEL_CLOSE;
self->name      = "channel.close";

//  Copy supplied values to method object
method->reply_code      = (dbyte) reply_code;
method->class_id        = (dbyte) class_id;
method->method_id       = (dbyte) method_id;
icl_shortstr_cpy (method->reply_text,    reply_text);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_channel_close_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_channel_close_ok (
void)
{
amq_server_channel_close_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.channel_close_ok;
self->class_id  = AMQ_SERVER_CHANNEL;
self->method_id = AMQ_SERVER_CHANNEL_CLOSE_OK;
self->name      = "channel.close_ok";

//  Copy supplied values to method object

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_exchange_declare_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_exchange_declare_ok (
void)
{
amq_server_exchange_declare_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.exchange_declare_ok;
self->class_id  = AMQ_SERVER_EXCHANGE;
self->method_id = AMQ_SERVER_EXCHANGE_DECLARE_OK;
self->name      = "exchange.declare_ok";

//  Copy supplied values to method object

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_exchange_delete_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_exchange_delete_ok (
void)
{
amq_server_exchange_delete_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.exchange_delete_ok;
self->class_id  = AMQ_SERVER_EXCHANGE;
self->method_id = AMQ_SERVER_EXCHANGE_DELETE_OK;
self->name      = "exchange.delete_ok";

//  Copy supplied values to method object

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_queue_declare_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_queue_declare_ok (
    char * queue,                       //  queue name
    qbyte message_count,                //  number of messages in queue
    qbyte consumer_count                //  number of consumers
)
{
amq_server_queue_declare_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.queue_declare_ok;
self->class_id  = AMQ_SERVER_QUEUE;
self->method_id = AMQ_SERVER_QUEUE_DECLARE_OK;
self->name      = "queue.declare_ok";

//  Copy supplied values to method object
method->message_count   = message_count;
method->consumer_count  = consumer_count;
icl_shortstr_cpy (method->queue,         queue);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_queue_bind_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_queue_bind_ok (
void)
{
amq_server_queue_bind_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.queue_bind_ok;
self->class_id  = AMQ_SERVER_QUEUE;
self->method_id = AMQ_SERVER_QUEUE_BIND_OK;
self->name      = "queue.bind_ok";

//  Copy supplied values to method object

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_queue_purge_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_queue_purge_ok (
    qbyte message_count                 //  number of messages purged
)
{
amq_server_queue_purge_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.queue_purge_ok;
self->class_id  = AMQ_SERVER_QUEUE;
self->method_id = AMQ_SERVER_QUEUE_PURGE_OK;
self->name      = "queue.purge_ok";

//  Copy supplied values to method object
method->message_count   = message_count;

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_queue_delete_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_queue_delete_ok (
    qbyte message_count                 //  number of messages purged
)
{
amq_server_queue_delete_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.queue_delete_ok;
self->class_id  = AMQ_SERVER_QUEUE;
self->method_id = AMQ_SERVER_QUEUE_DELETE_OK;
self->name      = "queue.delete_ok";

//  Copy supplied values to method object
method->message_count   = message_count;

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_queue_unbind_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_queue_unbind_ok (
void)
{
amq_server_queue_unbind_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.queue_unbind_ok;
self->class_id  = AMQ_SERVER_QUEUE;
self->method_id = AMQ_SERVER_QUEUE_UNBIND_OK;
self->name      = "queue.unbind_ok";

//  Copy supplied values to method object

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_basic_qos_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_basic_qos_ok (
void)
{
amq_server_basic_qos_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.basic_qos_ok;
self->class_id  = AMQ_SERVER_BASIC;
self->method_id = AMQ_SERVER_BASIC_QOS_OK;
self->name      = "basic.qos_ok";

//  Copy supplied values to method object

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_basic_consume_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_basic_consume_ok (
    char * consumer_tag                 //  consumer tag
)
{
amq_server_basic_consume_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.basic_consume_ok;
self->class_id  = AMQ_SERVER_BASIC;
self->method_id = AMQ_SERVER_BASIC_CONSUME_OK;
self->name      = "basic.consume_ok";

//  Copy supplied values to method object
icl_shortstr_cpy (method->consumer_tag,  consumer_tag);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_basic_cancel_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_basic_cancel_ok (
    char * consumer_tag                 //  consumer tag
)
{
amq_server_basic_cancel_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.basic_cancel_ok;
self->class_id  = AMQ_SERVER_BASIC;
self->method_id = AMQ_SERVER_BASIC_CANCEL_OK;
self->name      = "basic.cancel_ok";

//  Copy supplied values to method object
icl_shortstr_cpy (method->consumer_tag,  consumer_tag);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_basic_return

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_basic_return (
    int reply_code,                     //  reply code from server
    char * reply_text,                  //  localised reply text
    char * exchange,                    //  exchange name
    char * routing_key                  //  Message routing key
)
{
amq_server_basic_return_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.basic_return;
self->class_id  = AMQ_SERVER_BASIC;
self->method_id = AMQ_SERVER_BASIC_RETURN;
self->name      = "basic.return";

//  Copy supplied values to method object
method->reply_code      = (dbyte) reply_code;
icl_shortstr_cpy (method->reply_text,    reply_text);
icl_shortstr_cpy (method->exchange,      exchange);
icl_shortstr_cpy (method->routing_key,   routing_key);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_basic_deliver

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_basic_deliver (
    char * consumer_tag,                //  consumer tag
    int64_t delivery_tag,               //  server-assigned delivery tag
    Bool redelivered,                   //  message is being redelivered
    char * exchange,                    //  exchange name
    char * routing_key                  //  Message routing key
)
{
amq_server_basic_deliver_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.basic_deliver;
self->class_id  = AMQ_SERVER_BASIC;
self->method_id = AMQ_SERVER_BASIC_DELIVER;
self->name      = "basic.deliver";

//  Copy supplied values to method object
method->delivery_tag    = delivery_tag;
method->redelivered     = redelivered;
icl_shortstr_cpy (method->consumer_tag,  consumer_tag);
icl_shortstr_cpy (method->exchange,      exchange);
icl_shortstr_cpy (method->routing_key,   routing_key);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_basic_get_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_basic_get_ok (
    int64_t delivery_tag,               //  server-assigned delivery tag
    Bool redelivered,                   //  message is being redelivered
    char * exchange,                    //  exchange name
    char * routing_key,                 //  Message routing key
    qbyte message_count                 //  number of messages pending
)
{
amq_server_basic_get_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.basic_get_ok;
self->class_id  = AMQ_SERVER_BASIC;
self->method_id = AMQ_SERVER_BASIC_GET_OK;
self->name      = "basic.get_ok";

//  Copy supplied values to method object
method->delivery_tag    = delivery_tag;
method->redelivered     = redelivered;
method->message_count   = message_count;
icl_shortstr_cpy (method->exchange,      exchange);
icl_shortstr_cpy (method->routing_key,   routing_key);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_basic_get_empty

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_basic_get_empty (
    char * sender_id                    //  Sender id
)
{
amq_server_basic_get_empty_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.basic_get_empty;
self->class_id  = AMQ_SERVER_BASIC;
self->method_id = AMQ_SERVER_BASIC_GET_EMPTY;
self->name      = "basic.get_empty";

//  Copy supplied values to method object
icl_shortstr_cpy (method->sender_id,     sender_id);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_direct_put_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_direct_put_ok (
    char * lease                        //  Lease for connection
)
{
amq_server_direct_put_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.direct_put_ok;
self->class_id  = AMQ_SERVER_DIRECT;
self->method_id = AMQ_SERVER_DIRECT_PUT_OK;
self->name      = "direct.put_ok";

//  Copy supplied values to method object
icl_shortstr_cpy (method->lease,         lease);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_direct_get_ok

    Type: Component method
    Creates a new amq_server_method_t object as specified.
    Returns a pointer to the new method object, or NULL if there was an
    error allocating memory or parsing the arguments.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_new_direct_get_ok (
    char * lease                        //  Lease for connection
)
{
amq_server_direct_get_ok_t
    *method;
    amq_server_method_t *
        self;                           //  New method

//
self   = self_new ();
method = &self->payload.direct_get_ok;
self->class_id  = AMQ_SERVER_DIRECT;
self->method_id = AMQ_SERVER_DIRECT_GET_OK;
self->name      = "direct.get_ok";

//  Copy supplied values to method object
icl_shortstr_cpy (method->lease,         lease);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_encode

    Type: Component method
    Encodes a amq_server_method_t object into a memory bucket.
    Allocates a fresh bucket and returns this.  Returns NULL if there
    was an error encoding the method object.  The supplied bucket ends
    in a frame-end octet, for symmetry with the decode method.
    -------------------------------------------------------------------------
 */

ipr_bucket_t *
    amq_server_method_encode (
    amq_server_method_t * self          //  Method reference
)
{
byte
    *data_target = NULL;
size_t
    string_size = 0;
byte
    bit_string = 0;
    ipr_bucket_t *
        bucket = NULL;                  //  New bucket

//
AMQ_SERVER_METHOD_ASSERT_SANE (self);
assert (self->class_id);
assert (self->method_id);

switch (self->class_id) {
    case AMQ_SERVER_CONNECTION:
        switch (self->method_id) {
            case AMQ_SERVER_CONNECTION_START:
                bucket = ipr_bucket_new (12
                            + (self->payload.connection_start.server_properties?
                               self->payload.connection_start.server_properties->cur_size: 0)
                            + (self->payload.connection_start.mechanisms?
                               self->payload.connection_start.mechanisms->cur_size: 0)
                            + (self->payload.connection_start.locales?
                               self->payload.connection_start.locales->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_OCTET (data_target, self->payload.connection_start.version_major);
                PUT_OCTET (data_target, self->payload.connection_start.version_minor);
                PUT_TABLE (data_target, self->payload.connection_start.server_properties);
                PUT_LSTR  (data_target, self->payload.connection_start.mechanisms);
                PUT_LSTR  (data_target, self->payload.connection_start.locales);
                break;
            case AMQ_SERVER_CONNECTION_START_OK:
                bucket = ipr_bucket_new (10
                            + (self->payload.connection_start_ok.client_properties?
                               self->payload.connection_start_ok.client_properties->cur_size: 0)
                            + strlen (self->payload.connection_start_ok.mechanism)
                            + (self->payload.connection_start_ok.response?
                               self->payload.connection_start_ok.response->cur_size: 0)
                            + strlen (self->payload.connection_start_ok.locale) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_TABLE (data_target, self->payload.connection_start_ok.client_properties);
                PUT_SSTR  (data_target, self->payload.connection_start_ok.mechanism);
                PUT_LSTR  (data_target, self->payload.connection_start_ok.response);
                PUT_SSTR  (data_target, self->payload.connection_start_ok.locale);
                break;
            case AMQ_SERVER_CONNECTION_SECURE:
                bucket = ipr_bucket_new (6
                            + (self->payload.connection_secure.challenge?
                               self->payload.connection_secure.challenge->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LSTR  (data_target, self->payload.connection_secure.challenge);
                break;
            case AMQ_SERVER_CONNECTION_SECURE_OK:
                bucket = ipr_bucket_new (6
                            + (self->payload.connection_secure_ok.response?
                               self->payload.connection_secure_ok.response->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LSTR  (data_target, self->payload.connection_secure_ok.response);
                break;
            case AMQ_SERVER_CONNECTION_TUNE:
                bucket = ipr_bucket_new (12 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.connection_tune.channel_max);
                PUT_LONG  (data_target, self->payload.connection_tune.frame_max);
                PUT_SHORT (data_target, self->payload.connection_tune.heartbeat);
                break;
            case AMQ_SERVER_CONNECTION_TUNE_OK:
                bucket = ipr_bucket_new (12 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.connection_tune_ok.channel_max);
                PUT_LONG  (data_target, self->payload.connection_tune_ok.frame_max);
                PUT_SHORT (data_target, self->payload.connection_tune_ok.heartbeat);
                break;
            case AMQ_SERVER_CONNECTION_OPEN:
                bucket = ipr_bucket_new (7
                            + strlen (self->payload.connection_open.virtual_host)
                            + strlen (self->payload.connection_open.capabilities) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.connection_open.virtual_host);
                PUT_SSTR  (data_target, self->payload.connection_open.capabilities);
                bit_string |= (self->payload.connection_open.insist & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_SERVER_CONNECTION_OPEN_OK:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.connection_open_ok.known_hosts) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.connection_open_ok.known_hosts);
                break;
            case AMQ_SERVER_CONNECTION_CLOSE:
                bucket = ipr_bucket_new (11
                            + strlen (self->payload.connection_close.reply_text) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.connection_close.reply_code);
                PUT_SSTR  (data_target, self->payload.connection_close.reply_text);
                PUT_SHORT (data_target, self->payload.connection_close.class_id);
                PUT_SHORT (data_target, self->payload.connection_close.method_id);
                break;
            case AMQ_SERVER_CONNECTION_CLOSE_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
        }
        break;
    case AMQ_SERVER_CHANNEL:
        switch (self->method_id) {
            case AMQ_SERVER_CHANNEL_OPEN:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.channel_open.out_of_band) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.channel_open.out_of_band);
                break;
            case AMQ_SERVER_CHANNEL_OPEN_OK:
                bucket = ipr_bucket_new (6
                            + (self->payload.channel_open_ok.channel_id?
                               self->payload.channel_open_ok.channel_id->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LSTR  (data_target, self->payload.channel_open_ok.channel_id);
                break;
            case AMQ_SERVER_CHANNEL_FLOW:
                bucket = ipr_bucket_new (5 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                bit_string |= (self->payload.channel_flow.active & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_SERVER_CHANNEL_FLOW_OK:
                bucket = ipr_bucket_new (5 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                bit_string |= (self->payload.channel_flow_ok.active & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_SERVER_CHANNEL_CLOSE:
                bucket = ipr_bucket_new (11
                            + strlen (self->payload.channel_close.reply_text) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.channel_close.reply_code);
                PUT_SSTR  (data_target, self->payload.channel_close.reply_text);
                PUT_SHORT (data_target, self->payload.channel_close.class_id);
                PUT_SHORT (data_target, self->payload.channel_close.method_id);
                break;
            case AMQ_SERVER_CHANNEL_CLOSE_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
        }
        break;
    case AMQ_SERVER_EXCHANGE:
        switch (self->method_id) {
            case AMQ_SERVER_EXCHANGE_DECLARE:
                bucket = ipr_bucket_new (11
                            + strlen (self->payload.exchange_declare.exchange)
                            + strlen (self->payload.exchange_declare.type)
                            + (self->payload.exchange_declare.arguments?
                               self->payload.exchange_declare.arguments->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.exchange_declare.ticket);
                PUT_SSTR  (data_target, self->payload.exchange_declare.exchange);
                PUT_SSTR  (data_target, self->payload.exchange_declare.type);
                bit_string |= (self->payload.exchange_declare.passive & 1) << 0;
                bit_string |= (self->payload.exchange_declare.durable & 1) << 1;
                bit_string |= (self->payload.exchange_declare.auto_delete & 1) << 2;
                bit_string |= (self->payload.exchange_declare.internal & 1) << 3;
                bit_string |= (self->payload.exchange_declare.nowait & 1) << 4;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_TABLE (data_target, self->payload.exchange_declare.arguments);
                break;
            case AMQ_SERVER_EXCHANGE_DECLARE_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
            case AMQ_SERVER_EXCHANGE_DELETE:
                bucket = ipr_bucket_new (8
                            + strlen (self->payload.exchange_delete.exchange) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.exchange_delete.ticket);
                PUT_SSTR  (data_target, self->payload.exchange_delete.exchange);
                bit_string |= (self->payload.exchange_delete.if_unused & 1) << 0;
                bit_string |= (self->payload.exchange_delete.nowait & 1) << 1;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_SERVER_EXCHANGE_DELETE_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
        }
        break;
    case AMQ_SERVER_QUEUE:
        switch (self->method_id) {
            case AMQ_SERVER_QUEUE_DECLARE:
                bucket = ipr_bucket_new (10
                            + strlen (self->payload.queue_declare.queue)
                            + (self->payload.queue_declare.arguments?
                               self->payload.queue_declare.arguments->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.queue_declare.ticket);
                PUT_SSTR  (data_target, self->payload.queue_declare.queue);
                bit_string |= (self->payload.queue_declare.passive & 1) << 0;
                bit_string |= (self->payload.queue_declare.durable & 1) << 1;
                bit_string |= (self->payload.queue_declare.exclusive & 1) << 2;
                bit_string |= (self->payload.queue_declare.auto_delete & 1) << 3;
                bit_string |= (self->payload.queue_declare.nowait & 1) << 4;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_TABLE (data_target, self->payload.queue_declare.arguments);
                break;
            case AMQ_SERVER_QUEUE_DECLARE_OK:
                bucket = ipr_bucket_new (13
                            + strlen (self->payload.queue_declare_ok.queue) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.queue_declare_ok.queue);
                PUT_LONG  (data_target, self->payload.queue_declare_ok.message_count);
                PUT_LONG  (data_target, self->payload.queue_declare_ok.consumer_count);
                break;
            case AMQ_SERVER_QUEUE_BIND:
                bucket = ipr_bucket_new (12
                            + strlen (self->payload.queue_bind.queue)
                            + strlen (self->payload.queue_bind.exchange)
                            + strlen (self->payload.queue_bind.routing_key)
                            + (self->payload.queue_bind.arguments?
                               self->payload.queue_bind.arguments->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.queue_bind.ticket);
                PUT_SSTR  (data_target, self->payload.queue_bind.queue);
                PUT_SSTR  (data_target, self->payload.queue_bind.exchange);
                PUT_SSTR  (data_target, self->payload.queue_bind.routing_key);
                bit_string |= (self->payload.queue_bind.nowait & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_TABLE (data_target, self->payload.queue_bind.arguments);
                break;
            case AMQ_SERVER_QUEUE_BIND_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
            case AMQ_SERVER_QUEUE_PURGE:
                bucket = ipr_bucket_new (8
                            + strlen (self->payload.queue_purge.queue) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.queue_purge.ticket);
                PUT_SSTR  (data_target, self->payload.queue_purge.queue);
                bit_string |= (self->payload.queue_purge.nowait & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_SERVER_QUEUE_PURGE_OK:
                bucket = ipr_bucket_new (8 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LONG  (data_target, self->payload.queue_purge_ok.message_count);
                break;
            case AMQ_SERVER_QUEUE_DELETE:
                bucket = ipr_bucket_new (8
                            + strlen (self->payload.queue_delete.queue) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.queue_delete.ticket);
                PUT_SSTR  (data_target, self->payload.queue_delete.queue);
                bit_string |= (self->payload.queue_delete.if_unused & 1) << 0;
                bit_string |= (self->payload.queue_delete.if_empty & 1) << 1;
                bit_string |= (self->payload.queue_delete.nowait & 1) << 2;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_SERVER_QUEUE_DELETE_OK:
                bucket = ipr_bucket_new (8 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LONG  (data_target, self->payload.queue_delete_ok.message_count);
                break;
            case AMQ_SERVER_QUEUE_UNBIND:
                bucket = ipr_bucket_new (12
                            + strlen (self->payload.queue_unbind.queue)
                            + strlen (self->payload.queue_unbind.exchange)
                            + strlen (self->payload.queue_unbind.routing_key)
                            + (self->payload.queue_unbind.arguments?
                               self->payload.queue_unbind.arguments->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.queue_unbind.ticket);
                PUT_SSTR  (data_target, self->payload.queue_unbind.queue);
                PUT_SSTR  (data_target, self->payload.queue_unbind.exchange);
                PUT_SSTR  (data_target, self->payload.queue_unbind.routing_key);
                bit_string |= (self->payload.queue_unbind.nowait & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_TABLE (data_target, self->payload.queue_unbind.arguments);
                break;
            case AMQ_SERVER_QUEUE_UNBIND_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
        }
        break;
    case AMQ_SERVER_BASIC:
        switch (self->method_id) {
            case AMQ_SERVER_BASIC_QOS:
                bucket = ipr_bucket_new (11 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LONG  (data_target, self->payload.basic_qos.prefetch_size);
                PUT_SHORT (data_target, self->payload.basic_qos.prefetch_count);
                bit_string |= (self->payload.basic_qos.global & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_SERVER_BASIC_QOS_OK:
                bucket = ipr_bucket_new (4 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                break;
            case AMQ_SERVER_BASIC_CONSUME:
                bucket = ipr_bucket_new (11
                            + strlen (self->payload.basic_consume.queue)
                            + strlen (self->payload.basic_consume.consumer_tag)
                            + (self->payload.basic_consume.arguments?
                               self->payload.basic_consume.arguments->cur_size: 0) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.basic_consume.ticket);
                PUT_SSTR  (data_target, self->payload.basic_consume.queue);
                PUT_SSTR  (data_target, self->payload.basic_consume.consumer_tag);
                bit_string |= (self->payload.basic_consume.no_local & 1) << 0;
                bit_string |= (self->payload.basic_consume.no_ack & 1) << 1;
                bit_string |= (self->payload.basic_consume.exclusive & 1) << 2;
                bit_string |= (self->payload.basic_consume.nowait & 1) << 3;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_TABLE (data_target, self->payload.basic_consume.arguments);
                break;
            case AMQ_SERVER_BASIC_CONSUME_OK:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.basic_consume_ok.consumer_tag) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.basic_consume_ok.consumer_tag);
                break;
            case AMQ_SERVER_BASIC_CANCEL:
                bucket = ipr_bucket_new (6
                            + strlen (self->payload.basic_cancel.consumer_tag) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.basic_cancel.consumer_tag);
                bit_string |= (self->payload.basic_cancel.nowait & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_SERVER_BASIC_CANCEL_OK:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.basic_cancel_ok.consumer_tag) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.basic_cancel_ok.consumer_tag);
                break;
            case AMQ_SERVER_BASIC_PUBLISH:
                bucket = ipr_bucket_new (9
                            + strlen (self->payload.basic_publish.exchange)
                            + strlen (self->payload.basic_publish.routing_key) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.basic_publish.ticket);
                PUT_SSTR  (data_target, self->payload.basic_publish.exchange);
                PUT_SSTR  (data_target, self->payload.basic_publish.routing_key);
                bit_string |= (self->payload.basic_publish.mandatory & 1) << 0;
                bit_string |= (self->payload.basic_publish.immediate & 1) << 1;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_SERVER_BASIC_RETURN:
                bucket = ipr_bucket_new (9
                            + strlen (self->payload.basic_return.reply_text)
                            + strlen (self->payload.basic_return.exchange)
                            + strlen (self->payload.basic_return.routing_key) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.basic_return.reply_code);
                PUT_SSTR  (data_target, self->payload.basic_return.reply_text);
                PUT_SSTR  (data_target, self->payload.basic_return.exchange);
                PUT_SSTR  (data_target, self->payload.basic_return.routing_key);
                break;
            case AMQ_SERVER_BASIC_DELIVER:
                bucket = ipr_bucket_new (16
                            + strlen (self->payload.basic_deliver.consumer_tag)
                            + strlen (self->payload.basic_deliver.exchange)
                            + strlen (self->payload.basic_deliver.routing_key) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.basic_deliver.consumer_tag);
                PUT_LLONG (data_target, self->payload.basic_deliver.delivery_tag);
                bit_string |= (self->payload.basic_deliver.redelivered & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_SSTR  (data_target, self->payload.basic_deliver.exchange);
                PUT_SSTR  (data_target, self->payload.basic_deliver.routing_key);
                break;
            case AMQ_SERVER_BASIC_GET:
                bucket = ipr_bucket_new (8
                            + strlen (self->payload.basic_get.queue) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SHORT (data_target, self->payload.basic_get.ticket);
                PUT_SSTR  (data_target, self->payload.basic_get.queue);
                bit_string |= (self->payload.basic_get.no_ack & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_SERVER_BASIC_GET_OK:
                bucket = ipr_bucket_new (19
                            + strlen (self->payload.basic_get_ok.exchange)
                            + strlen (self->payload.basic_get_ok.routing_key) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LLONG (data_target, self->payload.basic_get_ok.delivery_tag);
                bit_string |= (self->payload.basic_get_ok.redelivered & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                PUT_SSTR  (data_target, self->payload.basic_get_ok.exchange);
                PUT_SSTR  (data_target, self->payload.basic_get_ok.routing_key);
                PUT_LONG  (data_target, self->payload.basic_get_ok.message_count);
                break;
            case AMQ_SERVER_BASIC_GET_EMPTY:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.basic_get_empty.sender_id) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.basic_get_empty.sender_id);
                break;
            case AMQ_SERVER_BASIC_ACK:
                bucket = ipr_bucket_new (13 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LLONG (data_target, self->payload.basic_ack.delivery_tag);
                bit_string |= (self->payload.basic_ack.multiple & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
            case AMQ_SERVER_BASIC_REJECT:
                bucket = ipr_bucket_new (13 + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_LLONG (data_target, self->payload.basic_reject.delivery_tag);
                bit_string |= (self->payload.basic_reject.requeue & 1) << 0;
                PUT_OCTET (data_target, bit_string);
                bit_string = 0;
                break;
        }
        break;
    case AMQ_SERVER_DIRECT:
        switch (self->method_id) {
            case AMQ_SERVER_DIRECT_PUT:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.direct_put.sink) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.direct_put.sink);
                break;
            case AMQ_SERVER_DIRECT_PUT_OK:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.direct_put_ok.lease) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.direct_put_ok.lease);
                break;
            case AMQ_SERVER_DIRECT_GET:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.direct_get.feed) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.direct_get.feed);
                break;
            case AMQ_SERVER_DIRECT_GET_OK:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.direct_get_ok.lease) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.direct_get_ok.lease);
                break;
        }
        break;
    case AMQ_SERVER_RESTMS:
        switch (self->method_id) {
            case AMQ_SERVER_RESTMS_PIPE_CREATE:
                bucket = ipr_bucket_new (6
                            + strlen (self->payload.restms_pipe_create.pipe_type)
                            + strlen (self->payload.restms_pipe_create.pipe_name) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.restms_pipe_create.pipe_type);
                PUT_SSTR  (data_target, self->payload.restms_pipe_create.pipe_name);
                break;
            case AMQ_SERVER_RESTMS_PIPE_DELETE:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.restms_pipe_delete.pipe_name) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.restms_pipe_delete.pipe_name);
                break;
            case AMQ_SERVER_RESTMS_FEED_CREATE:
                bucket = ipr_bucket_new (6
                            + strlen (self->payload.restms_feed_create.feed_type)
                            + strlen (self->payload.restms_feed_create.feed_name) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.restms_feed_create.feed_type);
                PUT_SSTR  (data_target, self->payload.restms_feed_create.feed_name);
                break;
            case AMQ_SERVER_RESTMS_FEED_DELETE:
                bucket = ipr_bucket_new (5
                            + strlen (self->payload.restms_feed_delete.feed_name) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.restms_feed_delete.feed_name);
                break;
            case AMQ_SERVER_RESTMS_JOIN_CREATE:
                bucket = ipr_bucket_new (7
                            + strlen (self->payload.restms_join_create.pipe_name)
                            + strlen (self->payload.restms_join_create.feed_name)
                            + strlen (self->payload.restms_join_create.address) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.restms_join_create.pipe_name);
                PUT_SSTR  (data_target, self->payload.restms_join_create.feed_name);
                PUT_SSTR  (data_target, self->payload.restms_join_create.address);
                break;
            case AMQ_SERVER_RESTMS_JOIN_DELETE:
                bucket = ipr_bucket_new (7
                            + strlen (self->payload.restms_join_delete.pipe_name)
                            + strlen (self->payload.restms_join_delete.feed_name)
                            + strlen (self->payload.restms_join_delete.address) + 1);
                data_target = bucket->data;
                PUT_SHORT (data_target, self->class_id);
                PUT_SHORT (data_target, self->method_id);
                PUT_SSTR  (data_target, self->payload.restms_join_delete.pipe_name);
                PUT_SSTR  (data_target, self->payload.restms_join_delete.feed_name);
                PUT_SSTR  (data_target, self->payload.restms_join_delete.address);
                break;
        }
        break;
}
bucket->cur_size = data_target - bucket->data;

    return (bucket);
}
/*  -------------------------------------------------------------------------
    amq_server_method_decode

    Type: Component method
    Decodes a amq_server_method_t object from a memory bucket.
    Allocates a new amq_server_method_t structure and returns this. Returns
    NULL if there was an error decoding the method object.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_decode (
    ipr_bucket_t * bucket,              //  New bucket
    char * strerror                     //  Error text, if any
)
{
byte
    *data_source,                   //  Pointer into buffer data           
    *data_limit;                    //  Limit of buffer data               
size_t
    string_size;
byte
    bit_string = 0;
    amq_server_method_t *
        self;                           //  Method reference

//
//  Check that frame is correctly terminated before decoding it            
assert (bucket);
self = NULL;
data_source = bucket->data;
data_limit  = data_source + bucket->cur_size;

self = self_new ();
GET_SHORT (self->class_id,  data_source);
GET_SHORT (self->method_id, data_source);
switch (self->class_id) {
    case AMQ_SERVER_CONNECTION:
        switch (self->method_id) {
            case AMQ_SERVER_CONNECTION_START:
                self->name = "connection.start";
                self->sync = TRUE;
                GET_OCTET (self->payload.connection_start.version_major, data_source);
                GET_OCTET (self->payload.connection_start.version_minor, data_source);
                GET_LSTR (self->payload.connection_start.server_properties, data_source);
                GET_LSTR (self->payload.connection_start.mechanisms, data_source);
                GET_LSTR (self->payload.connection_start.locales, data_source);
                if (self->payload.connection_start.mechanisms == NULL || self->payload.connection_start.mechanisms->cur_size == 0) {
                    strcpy (strerror, "connection.start: mechanisms field is empty");
                    goto exception;
                }
                if (self->payload.connection_start.locales == NULL || self->payload.connection_start.locales->cur_size == 0) {
                    strcpy (strerror, "connection.start: locales field is empty");
                    goto exception;
                }
                break;
            case AMQ_SERVER_CONNECTION_START_OK:
                self->name = "connection.start_ok";
                self->sync = TRUE;
                GET_LSTR (self->payload.connection_start_ok.client_properties, data_source);
                GET_SSTR (self->payload.connection_start_ok.mechanism, data_source);
                GET_LSTR (self->payload.connection_start_ok.response, data_source);
                GET_SSTR (self->payload.connection_start_ok.locale, data_source);
                if (*self->payload.connection_start_ok.mechanism == 0) {
                    strcpy (strerror, "connection.start_ok: mechanism field is empty");
                    goto exception;
                }
                if (self->payload.connection_start_ok.response == NULL || self->payload.connection_start_ok.response->cur_size == 0) {
                    strcpy (strerror, "connection.start_ok: response field is empty");
                    goto exception;
                }
                if (*self->payload.connection_start_ok.locale == 0) {
                    strcpy (strerror, "connection.start_ok: locale field is empty");
                    goto exception;
                }
                break;
            case AMQ_SERVER_CONNECTION_SECURE:
                self->name = "connection.secure";
                self->sync = TRUE;
                GET_LSTR (self->payload.connection_secure.challenge, data_source);
                break;
            case AMQ_SERVER_CONNECTION_SECURE_OK:
                self->name = "connection.secure_ok";
                self->sync = TRUE;
                GET_LSTR (self->payload.connection_secure_ok.response, data_source);
                break;
            case AMQ_SERVER_CONNECTION_TUNE:
                self->name = "connection.tune";
                self->sync = TRUE;
                GET_SHORT (self->payload.connection_tune.channel_max, data_source);
                GET_LONG  (self->payload.connection_tune.frame_max, data_source);
                GET_SHORT (self->payload.connection_tune.heartbeat, data_source);
                break;
            case AMQ_SERVER_CONNECTION_TUNE_OK:
                self->name = "connection.tune_ok";
                self->sync = TRUE;
                GET_SHORT (self->payload.connection_tune_ok.channel_max, data_source);
                GET_LONG  (self->payload.connection_tune_ok.frame_max, data_source);
                GET_SHORT (self->payload.connection_tune_ok.heartbeat, data_source);
                if (self->payload.connection_tune_ok.channel_max == 0) {
                    strcpy (strerror, "connection.tune_ok: channel_max field is empty");
                    goto exception;
                }
                break;
            case AMQ_SERVER_CONNECTION_OPEN:
                self->name = "connection.open";
                self->sync = TRUE;
                GET_SSTR (self->payload.connection_open.virtual_host, data_source);
                GET_SSTR (self->payload.connection_open.capabilities, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.connection_open.insist = (bit_string >> 0) & 1;
                if (!ipr_regexp_match (s_regexp_connection_virtual_host, self->payload.connection_open.virtual_host)) {
                    strcpy (strerror, "connection.open: virtual_host field is invalid");
                    goto exception;
                }
                break;
            case AMQ_SERVER_CONNECTION_OPEN_OK:
                self->name = "connection.open_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.connection_open_ok.known_hosts, data_source);
                break;
            case AMQ_SERVER_CONNECTION_CLOSE:
                self->name = "connection.close";
                self->sync = TRUE;
                GET_SHORT (self->payload.connection_close.reply_code, data_source);
                GET_SSTR (self->payload.connection_close.reply_text, data_source);
                GET_SHORT (self->payload.connection_close.class_id, data_source);
                GET_SHORT (self->payload.connection_close.method_id, data_source);
                if (self->payload.connection_close.reply_code == 0) {
                    strcpy (strerror, "connection.close: reply_code field is empty");
                    goto exception;
                }
                if (*self->payload.connection_close.reply_text == 0) {
                    strcpy (strerror, "connection.close: reply_text field is empty");
                    goto exception;
                }
                break;
            case AMQ_SERVER_CONNECTION_CLOSE_OK:
                self->name = "connection.close_ok";
                self->sync = TRUE;
                break;
        }
        break;
    case AMQ_SERVER_CHANNEL:
        switch (self->method_id) {
            case AMQ_SERVER_CHANNEL_OPEN:
                self->name = "channel.open";
                self->sync = TRUE;
                GET_SSTR (self->payload.channel_open.out_of_band, data_source);
                break;
            case AMQ_SERVER_CHANNEL_OPEN_OK:
                self->name = "channel.open_ok";
                self->sync = TRUE;
                GET_LSTR (self->payload.channel_open_ok.channel_id, data_source);
                break;
            case AMQ_SERVER_CHANNEL_FLOW:
                self->name = "channel.flow";
                self->sync = TRUE;
                GET_OCTET (bit_string, data_source);
                self->payload.channel_flow.active = (bit_string >> 0) & 1;
                break;
            case AMQ_SERVER_CHANNEL_FLOW_OK:
                self->name = "channel.flow_ok";
                self->sync = FALSE;
                GET_OCTET (bit_string, data_source);
                self->payload.channel_flow_ok.active = (bit_string >> 0) & 1;
                break;
            case AMQ_SERVER_CHANNEL_CLOSE:
                self->name = "channel.close";
                self->sync = TRUE;
                GET_SHORT (self->payload.channel_close.reply_code, data_source);
                GET_SSTR (self->payload.channel_close.reply_text, data_source);
                GET_SHORT (self->payload.channel_close.class_id, data_source);
                GET_SHORT (self->payload.channel_close.method_id, data_source);
                if (self->payload.channel_close.reply_code == 0) {
                    strcpy (strerror, "channel.close: reply_code field is empty");
                    goto exception;
                }
                if (*self->payload.channel_close.reply_text == 0) {
                    strcpy (strerror, "channel.close: reply_text field is empty");
                    goto exception;
                }
                break;
            case AMQ_SERVER_CHANNEL_CLOSE_OK:
                self->name = "channel.close_ok";
                self->sync = TRUE;
                break;
        }
        break;
    case AMQ_SERVER_EXCHANGE:
        switch (self->method_id) {
            case AMQ_SERVER_EXCHANGE_DECLARE:
                self->name = "exchange.declare";
                self->sync = TRUE;
                GET_SHORT (self->payload.exchange_declare.ticket, data_source);
                GET_SSTR (self->payload.exchange_declare.exchange, data_source);
                GET_SSTR (self->payload.exchange_declare.type, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.exchange_declare.passive = (bit_string >> 0) & 1;
                self->payload.exchange_declare.durable = (bit_string >> 1) & 1;
                self->payload.exchange_declare.auto_delete = (bit_string >> 2) & 1;
                self->payload.exchange_declare.internal = (bit_string >> 3) & 1;
                self->payload.exchange_declare.nowait = (bit_string >> 4) & 1;
                GET_LSTR (self->payload.exchange_declare.arguments, data_source);
                if (!ipr_regexp_match (s_regexp_exchange_exchange, self->payload.exchange_declare.exchange)) {
                    strcpy (strerror, "exchange.declare: exchange field is invalid");
                    goto exception;
                }
                if (!ipr_regexp_match (s_regexp_exchange_type, self->payload.exchange_declare.type)) {
                    strcpy (strerror, "exchange.declare: type field is invalid");
                    goto exception;
                }
                break;
            case AMQ_SERVER_EXCHANGE_DECLARE_OK:
                self->name = "exchange.declare_ok";
                self->sync = TRUE;
                break;
            case AMQ_SERVER_EXCHANGE_DELETE:
                self->name = "exchange.delete";
                self->sync = TRUE;
                GET_SHORT (self->payload.exchange_delete.ticket, data_source);
                GET_SSTR (self->payload.exchange_delete.exchange, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.exchange_delete.if_unused = (bit_string >> 0) & 1;
                self->payload.exchange_delete.nowait = (bit_string >> 1) & 1;
                if (*self->payload.exchange_delete.exchange == 0) {
                    strcpy (strerror, "exchange.delete: exchange field is empty");
                    goto exception;
                }
                break;
            case AMQ_SERVER_EXCHANGE_DELETE_OK:
                self->name = "exchange.delete_ok";
                self->sync = TRUE;
                break;
        }
        break;
    case AMQ_SERVER_QUEUE:
        switch (self->method_id) {
            case AMQ_SERVER_QUEUE_DECLARE:
                self->name = "queue.declare";
                self->sync = TRUE;
                GET_SHORT (self->payload.queue_declare.ticket, data_source);
                GET_SSTR (self->payload.queue_declare.queue, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.queue_declare.passive = (bit_string >> 0) & 1;
                self->payload.queue_declare.durable = (bit_string >> 1) & 1;
                self->payload.queue_declare.exclusive = (bit_string >> 2) & 1;
                self->payload.queue_declare.auto_delete = (bit_string >> 3) & 1;
                self->payload.queue_declare.nowait = (bit_string >> 4) & 1;
                GET_LSTR (self->payload.queue_declare.arguments, data_source);
                if (!ipr_regexp_match (s_regexp_queue_queue, self->payload.queue_declare.queue)) {
                    strcpy (strerror, "queue.declare: queue field is invalid");
                    goto exception;
                }
                break;
            case AMQ_SERVER_QUEUE_DECLARE_OK:
                self->name = "queue.declare_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.queue_declare_ok.queue, data_source);
                GET_LONG  (self->payload.queue_declare_ok.message_count, data_source);
                GET_LONG  (self->payload.queue_declare_ok.consumer_count, data_source);
                if (*self->payload.queue_declare_ok.queue == 0) {
                    strcpy (strerror, "queue.declare_ok: queue field is empty");
                    goto exception;
                }
                break;
            case AMQ_SERVER_QUEUE_BIND:
                self->name = "queue.bind";
                self->sync = TRUE;
                GET_SHORT (self->payload.queue_bind.ticket, data_source);
                GET_SSTR (self->payload.queue_bind.queue, data_source);
                GET_SSTR (self->payload.queue_bind.exchange, data_source);
                GET_SSTR (self->payload.queue_bind.routing_key, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.queue_bind.nowait = (bit_string >> 0) & 1;
                GET_LSTR (self->payload.queue_bind.arguments, data_source);
                if (strlen (self->payload.queue_bind.queue) > 127) {
                    strcpy (strerror, "queue.bind: queue field exceeds >127 chars");
                    goto exception;
                }
                if (strlen (self->payload.queue_bind.exchange) > 127) {
                    strcpy (strerror, "queue.bind: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_SERVER_QUEUE_BIND_OK:
                self->name = "queue.bind_ok";
                self->sync = TRUE;
                break;
            case AMQ_SERVER_QUEUE_PURGE:
                self->name = "queue.purge";
                self->sync = TRUE;
                GET_SHORT (self->payload.queue_purge.ticket, data_source);
                GET_SSTR (self->payload.queue_purge.queue, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.queue_purge.nowait = (bit_string >> 0) & 1;
                if (strlen (self->payload.queue_purge.queue) > 127) {
                    strcpy (strerror, "queue.purge: queue field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_SERVER_QUEUE_PURGE_OK:
                self->name = "queue.purge_ok";
                self->sync = TRUE;
                GET_LONG  (self->payload.queue_purge_ok.message_count, data_source);
                break;
            case AMQ_SERVER_QUEUE_DELETE:
                self->name = "queue.delete";
                self->sync = TRUE;
                GET_SHORT (self->payload.queue_delete.ticket, data_source);
                GET_SSTR (self->payload.queue_delete.queue, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.queue_delete.if_unused = (bit_string >> 0) & 1;
                self->payload.queue_delete.if_empty = (bit_string >> 1) & 1;
                self->payload.queue_delete.nowait = (bit_string >> 2) & 1;
                if (strlen (self->payload.queue_delete.queue) > 127) {
                    strcpy (strerror, "queue.delete: queue field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_SERVER_QUEUE_DELETE_OK:
                self->name = "queue.delete_ok";
                self->sync = TRUE;
                GET_LONG  (self->payload.queue_delete_ok.message_count, data_source);
                break;
            case AMQ_SERVER_QUEUE_UNBIND:
                self->name = "queue.unbind";
                self->sync = TRUE;
                GET_SHORT (self->payload.queue_unbind.ticket, data_source);
                GET_SSTR (self->payload.queue_unbind.queue, data_source);
                GET_SSTR (self->payload.queue_unbind.exchange, data_source);
                GET_SSTR (self->payload.queue_unbind.routing_key, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.queue_unbind.nowait = (bit_string >> 0) & 1;
                GET_LSTR (self->payload.queue_unbind.arguments, data_source);
                if (strlen (self->payload.queue_unbind.queue) > 127) {
                    strcpy (strerror, "queue.unbind: queue field exceeds >127 chars");
                    goto exception;
                }
                if (strlen (self->payload.queue_unbind.exchange) > 127) {
                    strcpy (strerror, "queue.unbind: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_SERVER_QUEUE_UNBIND_OK:
                self->name = "queue.unbind_ok";
                self->sync = TRUE;
                break;
        }
        break;
    case AMQ_SERVER_BASIC:
        switch (self->method_id) {
            case AMQ_SERVER_BASIC_QOS:
                self->name = "basic.qos";
                self->sync = TRUE;
                GET_LONG  (self->payload.basic_qos.prefetch_size, data_source);
                GET_SHORT (self->payload.basic_qos.prefetch_count, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_qos.global = (bit_string >> 0) & 1;
                break;
            case AMQ_SERVER_BASIC_QOS_OK:
                self->name = "basic.qos_ok";
                self->sync = TRUE;
                break;
            case AMQ_SERVER_BASIC_CONSUME:
                self->name = "basic.consume";
                self->sync = TRUE;
                GET_SHORT (self->payload.basic_consume.ticket, data_source);
                GET_SSTR (self->payload.basic_consume.queue, data_source);
                GET_SSTR (self->payload.basic_consume.consumer_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_consume.no_local = (bit_string >> 0) & 1;
                self->payload.basic_consume.no_ack = (bit_string >> 1) & 1;
                self->payload.basic_consume.exclusive = (bit_string >> 2) & 1;
                self->payload.basic_consume.nowait = (bit_string >> 3) & 1;
                GET_LSTR (self->payload.basic_consume.arguments, data_source);
                if (strlen (self->payload.basic_consume.queue) > 127) {
                    strcpy (strerror, "basic.consume: queue field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_SERVER_BASIC_CONSUME_OK:
                self->name = "basic.consume_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.basic_consume_ok.consumer_tag, data_source);
                break;
            case AMQ_SERVER_BASIC_CANCEL:
                self->name = "basic.cancel";
                self->sync = TRUE;
                GET_SSTR (self->payload.basic_cancel.consumer_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_cancel.nowait = (bit_string >> 0) & 1;
                break;
            case AMQ_SERVER_BASIC_CANCEL_OK:
                self->name = "basic.cancel_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.basic_cancel_ok.consumer_tag, data_source);
                break;
            case AMQ_SERVER_BASIC_PUBLISH:
                self->name = "basic.publish";
                self->sync = FALSE;
                GET_SHORT (self->payload.basic_publish.ticket, data_source);
                GET_SSTR (self->payload.basic_publish.exchange, data_source);
                GET_SSTR (self->payload.basic_publish.routing_key, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_publish.mandatory = (bit_string >> 0) & 1;
                self->payload.basic_publish.immediate = (bit_string >> 1) & 1;
                if (strlen (self->payload.basic_publish.exchange) > 127) {
                    strcpy (strerror, "basic.publish: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_SERVER_BASIC_RETURN:
                self->name = "basic.return";
                self->sync = FALSE;
                GET_SHORT (self->payload.basic_return.reply_code, data_source);
                GET_SSTR (self->payload.basic_return.reply_text, data_source);
                GET_SSTR (self->payload.basic_return.exchange, data_source);
                GET_SSTR (self->payload.basic_return.routing_key, data_source);
                if (self->payload.basic_return.reply_code == 0) {
                    strcpy (strerror, "basic.return: reply_code field is empty");
                    goto exception;
                }
                if (*self->payload.basic_return.reply_text == 0) {
                    strcpy (strerror, "basic.return: reply_text field is empty");
                    goto exception;
                }
                if (strlen (self->payload.basic_return.exchange) > 127) {
                    strcpy (strerror, "basic.return: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_SERVER_BASIC_DELIVER:
                self->name = "basic.deliver";
                self->sync = FALSE;
                GET_SSTR (self->payload.basic_deliver.consumer_tag, data_source);
                GET_LLONG (self->payload.basic_deliver.delivery_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_deliver.redelivered = (bit_string >> 0) & 1;
                GET_SSTR (self->payload.basic_deliver.exchange, data_source);
                GET_SSTR (self->payload.basic_deliver.routing_key, data_source);
                if (strlen (self->payload.basic_deliver.exchange) > 127) {
                    strcpy (strerror, "basic.deliver: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_SERVER_BASIC_GET:
                self->name = "basic.get";
                self->sync = TRUE;
                GET_SHORT (self->payload.basic_get.ticket, data_source);
                GET_SSTR (self->payload.basic_get.queue, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_get.no_ack = (bit_string >> 0) & 1;
                if (strlen (self->payload.basic_get.queue) > 127) {
                    strcpy (strerror, "basic.get: queue field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_SERVER_BASIC_GET_OK:
                self->name = "basic.get_ok";
                self->sync = TRUE;
                GET_LLONG (self->payload.basic_get_ok.delivery_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_get_ok.redelivered = (bit_string >> 0) & 1;
                GET_SSTR (self->payload.basic_get_ok.exchange, data_source);
                GET_SSTR (self->payload.basic_get_ok.routing_key, data_source);
                GET_LONG  (self->payload.basic_get_ok.message_count, data_source);
                if (strlen (self->payload.basic_get_ok.exchange) > 127) {
                    strcpy (strerror, "basic.get_ok: exchange field exceeds >127 chars");
                    goto exception;
                }
                break;
            case AMQ_SERVER_BASIC_GET_EMPTY:
                self->name = "basic.get_empty";
                self->sync = TRUE;
                GET_SSTR (self->payload.basic_get_empty.sender_id, data_source);
                break;
            case AMQ_SERVER_BASIC_ACK:
                self->name = "basic.ack";
                self->sync = FALSE;
                GET_LLONG (self->payload.basic_ack.delivery_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_ack.multiple = (bit_string >> 0) & 1;
                break;
            case AMQ_SERVER_BASIC_REJECT:
                self->name = "basic.reject";
                self->sync = FALSE;
                GET_LLONG (self->payload.basic_reject.delivery_tag, data_source);
                GET_OCTET (bit_string, data_source);
                self->payload.basic_reject.requeue = (bit_string >> 0) & 1;
                break;
        }
        break;
    case AMQ_SERVER_DIRECT:
        switch (self->method_id) {
            case AMQ_SERVER_DIRECT_PUT:
                self->name = "direct.put";
                self->sync = TRUE;
                GET_SSTR (self->payload.direct_put.sink, data_source);
                break;
            case AMQ_SERVER_DIRECT_PUT_OK:
                self->name = "direct.put_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.direct_put_ok.lease, data_source);
                break;
            case AMQ_SERVER_DIRECT_GET:
                self->name = "direct.get";
                self->sync = TRUE;
                GET_SSTR (self->payload.direct_get.feed, data_source);
                if (*self->payload.direct_get.feed == 0) {
                    strcpy (strerror, "direct.get: feed field is empty");
                    goto exception;
                }
                break;
            case AMQ_SERVER_DIRECT_GET_OK:
                self->name = "direct.get_ok";
                self->sync = TRUE;
                GET_SSTR (self->payload.direct_get_ok.lease, data_source);
                break;
        }
        break;
    case AMQ_SERVER_RESTMS:
        switch (self->method_id) {
            case AMQ_SERVER_RESTMS_PIPE_CREATE:
                self->name = "restms.pipe_create";
                self->sync = FALSE;
                GET_SSTR (self->payload.restms_pipe_create.pipe_type, data_source);
                GET_SSTR (self->payload.restms_pipe_create.pipe_name, data_source);
                break;
            case AMQ_SERVER_RESTMS_PIPE_DELETE:
                self->name = "restms.pipe_delete";
                self->sync = FALSE;
                GET_SSTR (self->payload.restms_pipe_delete.pipe_name, data_source);
                break;
            case AMQ_SERVER_RESTMS_FEED_CREATE:
                self->name = "restms.feed_create";
                self->sync = FALSE;
                GET_SSTR (self->payload.restms_feed_create.feed_type, data_source);
                GET_SSTR (self->payload.restms_feed_create.feed_name, data_source);
                break;
            case AMQ_SERVER_RESTMS_FEED_DELETE:
                self->name = "restms.feed_delete";
                self->sync = FALSE;
                GET_SSTR (self->payload.restms_feed_delete.feed_name, data_source);
                break;
            case AMQ_SERVER_RESTMS_JOIN_CREATE:
                self->name = "restms.join_create";
                self->sync = FALSE;
                GET_SSTR (self->payload.restms_join_create.pipe_name, data_source);
                GET_SSTR (self->payload.restms_join_create.feed_name, data_source);
                GET_SSTR (self->payload.restms_join_create.address, data_source);
                break;
            case AMQ_SERVER_RESTMS_JOIN_DELETE:
                self->name = "restms.join_delete";
                self->sync = FALSE;
                GET_SSTR (self->payload.restms_join_delete.pipe_name, data_source);
                GET_SSTR (self->payload.restms_join_delete.feed_name, data_source);
                GET_SSTR (self->payload.restms_join_delete.address, data_source);
                break;
        }
        break;
}
goto finished;
underflow:
    icl_shortstr_fmt (strerror, "malformed frame for '%s' method", self->name);
exception:
    self_destroy (&self);
    return (NULL);
finished:
    //  Return via normal function exit

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_dump

    Type: Component method
    Accepts a amq_server_method_t reference and returns zero in case of success,
    1 in case of errors.
    Dumps contents of serialised method for tracing.
    -------------------------------------------------------------------------
 */

int
    amq_server_method_dump (
    amq_server_method_t * self,         //  Reference to object
    smt_log_t * log,                    //  Log file, if any
    char * prefix                       //  Prefix for line
)
{
    int
        rc = 0;                         //  Return code

AMQ_SERVER_METHOD_ASSERT_SANE (self);
if (!self->zombie) {

//
switch (self->class_id) {
    case AMQ_SERVER_CONNECTION:
        switch (self->method_id) {
            case AMQ_SERVER_CONNECTION_START:
                if (log) {
                    smt_log_print (log, "%sconnection.start:"\
                        " version_major=%d version_minor=%d server_properties=%uB mechanisms=%uB locales=%uB", prefix,
                        self->payload.connection_start.version_major,
                        self->payload.connection_start.version_minor,
                        self->payload.connection_start.server_properties?
                            self->payload.connection_start.server_properties->cur_size: 0,
                        self->payload.connection_start.mechanisms?
                            self->payload.connection_start.mechanisms->cur_size: 0,
                        self->payload.connection_start.locales?
                            self->payload.connection_start.locales->cur_size: 0);
                }
                else {
                    icl_console_print ("%sconnection.start:"\
                        " version_major=%d version_minor=%d server_properties=%uB mechanisms=%uB locales=%uB", prefix,
                        self->payload.connection_start.version_major,
                        self->payload.connection_start.version_minor,
                        self->payload.connection_start.server_properties?
                            self->payload.connection_start.server_properties->cur_size: 0,
                        self->payload.connection_start.mechanisms?
                            self->payload.connection_start.mechanisms->cur_size: 0,
                        self->payload.connection_start.locales?
                            self->payload.connection_start.locales->cur_size: 0);
                }
                break;
            case AMQ_SERVER_CONNECTION_START_OK:
                if (log) {
                    smt_log_print (log, "%sconnection.start-ok:"\
                        " client_properties=%uB mechanism=\"%s\" response=%uB locale=\"%s\"", prefix,
                        self->payload.connection_start_ok.client_properties?
                            self->payload.connection_start_ok.client_properties->cur_size: 0,
                        self->payload.connection_start_ok.mechanism,
                        self->payload.connection_start_ok.response?
                            self->payload.connection_start_ok.response->cur_size: 0,
                        self->payload.connection_start_ok.locale);
                }
                else {
                    icl_console_print ("%sconnection.start-ok:"\
                        " client_properties=%uB mechanism=\"%s\" response=%uB locale=\"%s\"", prefix,
                        self->payload.connection_start_ok.client_properties?
                            self->payload.connection_start_ok.client_properties->cur_size: 0,
                        self->payload.connection_start_ok.mechanism,
                        self->payload.connection_start_ok.response?
                            self->payload.connection_start_ok.response->cur_size: 0,
                        self->payload.connection_start_ok.locale);
                }
                break;
            case AMQ_SERVER_CONNECTION_SECURE:
                if (log) {
                    smt_log_print (log, "%sconnection.secure:"\
                        " challenge=%uB", prefix,
                        self->payload.connection_secure.challenge?
                            self->payload.connection_secure.challenge->cur_size: 0);
                }
                else {
                    icl_console_print ("%sconnection.secure:"\
                        " challenge=%uB", prefix,
                        self->payload.connection_secure.challenge?
                            self->payload.connection_secure.challenge->cur_size: 0);
                }
                break;
            case AMQ_SERVER_CONNECTION_SECURE_OK:
                if (log) {
                    smt_log_print (log, "%sconnection.secure-ok:"\
                        " response=%uB", prefix,
                        self->payload.connection_secure_ok.response?
                            self->payload.connection_secure_ok.response->cur_size: 0);
                }
                else {
                    icl_console_print ("%sconnection.secure-ok:"\
                        " response=%uB", prefix,
                        self->payload.connection_secure_ok.response?
                            self->payload.connection_secure_ok.response->cur_size: 0);
                }
                break;
            case AMQ_SERVER_CONNECTION_TUNE:
                if (log) {
                    smt_log_print (log, "%sconnection.tune:"\
                        " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                        self->payload.connection_tune.channel_max,
                        self->payload.connection_tune.frame_max,
                        self->payload.connection_tune.heartbeat);
                }
                else {
                    icl_console_print ("%sconnection.tune:"\
                        " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                        self->payload.connection_tune.channel_max,
                        self->payload.connection_tune.frame_max,
                        self->payload.connection_tune.heartbeat);
                }
                break;
            case AMQ_SERVER_CONNECTION_TUNE_OK:
                if (log) {
                    smt_log_print (log, "%sconnection.tune-ok:"\
                        " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                        self->payload.connection_tune_ok.channel_max,
                        self->payload.connection_tune_ok.frame_max,
                        self->payload.connection_tune_ok.heartbeat);
                }
                else {
                    icl_console_print ("%sconnection.tune-ok:"\
                        " channel_max=%d frame_max=%u heartbeat=%d", prefix,
                        self->payload.connection_tune_ok.channel_max,
                        self->payload.connection_tune_ok.frame_max,
                        self->payload.connection_tune_ok.heartbeat);
                }
                break;
            case AMQ_SERVER_CONNECTION_OPEN:
                if (log) {
                    smt_log_print (log, "%sconnection.open:"\
                        " virtual_host=\"%s\" capabilities=\"%s\" insist=%d", prefix,
                        self->payload.connection_open.virtual_host,
                        self->payload.connection_open.capabilities,
                        self->payload.connection_open.insist);
                }
                else {
                    icl_console_print ("%sconnection.open:"\
                        " virtual_host=\"%s\" capabilities=\"%s\" insist=%d", prefix,
                        self->payload.connection_open.virtual_host,
                        self->payload.connection_open.capabilities,
                        self->payload.connection_open.insist);
                }
                break;
            case AMQ_SERVER_CONNECTION_OPEN_OK:
                if (log) {
                    smt_log_print (log, "%sconnection.open-ok:"\
                        " known_hosts=\"%s\"", prefix,
                        self->payload.connection_open_ok.known_hosts);
                }
                else {
                    icl_console_print ("%sconnection.open-ok:"\
                        " known_hosts=\"%s\"", prefix,
                        self->payload.connection_open_ok.known_hosts);
                }
                break;
            case AMQ_SERVER_CONNECTION_CLOSE:
                if (log) {
                    smt_log_print (log, "%sconnection.close:"\
                        " reply_code=%d reply_text=\"%s\" class_id=%d method_id=%d", prefix,
                        self->payload.connection_close.reply_code,
                        self->payload.connection_close.reply_text,
                        self->payload.connection_close.class_id,
                        self->payload.connection_close.method_id);
                }
                else {
                    icl_console_print ("%sconnection.close:"\
                        " reply_code=%d reply_text=\"%s\" class_id=%d method_id=%d", prefix,
                        self->payload.connection_close.reply_code,
                        self->payload.connection_close.reply_text,
                        self->payload.connection_close.class_id,
                        self->payload.connection_close.method_id);
                }
                break;
            case AMQ_SERVER_CONNECTION_CLOSE_OK:
                if (log) {
                    smt_log_print (log, "%sconnection.close-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%sconnection.close-ok:"\
                        "", prefix);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    case AMQ_SERVER_CHANNEL:
        switch (self->method_id) {
            case AMQ_SERVER_CHANNEL_OPEN:
                if (log) {
                    smt_log_print (log, "%schannel.open:"\
                        " out_of_band=\"%s\"", prefix,
                        self->payload.channel_open.out_of_band);
                }
                else {
                    icl_console_print ("%schannel.open:"\
                        " out_of_band=\"%s\"", prefix,
                        self->payload.channel_open.out_of_band);
                }
                break;
            case AMQ_SERVER_CHANNEL_OPEN_OK:
                if (log) {
                    smt_log_print (log, "%schannel.open-ok:"\
                        " channel_id=%uB", prefix,
                        self->payload.channel_open_ok.channel_id?
                            self->payload.channel_open_ok.channel_id->cur_size: 0);
                }
                else {
                    icl_console_print ("%schannel.open-ok:"\
                        " channel_id=%uB", prefix,
                        self->payload.channel_open_ok.channel_id?
                            self->payload.channel_open_ok.channel_id->cur_size: 0);
                }
                break;
            case AMQ_SERVER_CHANNEL_FLOW:
                if (log) {
                    smt_log_print (log, "%schannel.flow:"\
                        " active=%d", prefix,
                        self->payload.channel_flow.active);
                }
                else {
                    icl_console_print ("%schannel.flow:"\
                        " active=%d", prefix,
                        self->payload.channel_flow.active);
                }
                break;
            case AMQ_SERVER_CHANNEL_FLOW_OK:
                if (log) {
                    smt_log_print (log, "%schannel.flow-ok:"\
                        " active=%d", prefix,
                        self->payload.channel_flow_ok.active);
                }
                else {
                    icl_console_print ("%schannel.flow-ok:"\
                        " active=%d", prefix,
                        self->payload.channel_flow_ok.active);
                }
                break;
            case AMQ_SERVER_CHANNEL_CLOSE:
                if (log) {
                    smt_log_print (log, "%schannel.close:"\
                        " reply_code=%d reply_text=\"%s\" class_id=%d method_id=%d", prefix,
                        self->payload.channel_close.reply_code,
                        self->payload.channel_close.reply_text,
                        self->payload.channel_close.class_id,
                        self->payload.channel_close.method_id);
                }
                else {
                    icl_console_print ("%schannel.close:"\
                        " reply_code=%d reply_text=\"%s\" class_id=%d method_id=%d", prefix,
                        self->payload.channel_close.reply_code,
                        self->payload.channel_close.reply_text,
                        self->payload.channel_close.class_id,
                        self->payload.channel_close.method_id);
                }
                break;
            case AMQ_SERVER_CHANNEL_CLOSE_OK:
                if (log) {
                    smt_log_print (log, "%schannel.close-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%schannel.close-ok:"\
                        "", prefix);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    case AMQ_SERVER_EXCHANGE:
        switch (self->method_id) {
            case AMQ_SERVER_EXCHANGE_DECLARE:
                if (log) {
                    smt_log_print (log, "%sexchange.declare:"\
                        " ticket=%d exchange=\"%s\" type=\"%s\" passive=%d durable=%d auto_delete=%d internal=%d nowait=%d arguments=%uB", prefix,
                        self->payload.exchange_declare.ticket,
                        self->payload.exchange_declare.exchange,
                        self->payload.exchange_declare.type,
                        self->payload.exchange_declare.passive,
                        self->payload.exchange_declare.durable,
                        self->payload.exchange_declare.auto_delete,
                        self->payload.exchange_declare.internal,
                        self->payload.exchange_declare.nowait,
                        self->payload.exchange_declare.arguments?
                            self->payload.exchange_declare.arguments->cur_size: 0);
                }
                else {
                    icl_console_print ("%sexchange.declare:"\
                        " ticket=%d exchange=\"%s\" type=\"%s\" passive=%d durable=%d auto_delete=%d internal=%d nowait=%d arguments=%uB", prefix,
                        self->payload.exchange_declare.ticket,
                        self->payload.exchange_declare.exchange,
                        self->payload.exchange_declare.type,
                        self->payload.exchange_declare.passive,
                        self->payload.exchange_declare.durable,
                        self->payload.exchange_declare.auto_delete,
                        self->payload.exchange_declare.internal,
                        self->payload.exchange_declare.nowait,
                        self->payload.exchange_declare.arguments?
                            self->payload.exchange_declare.arguments->cur_size: 0);
                }
                break;
            case AMQ_SERVER_EXCHANGE_DECLARE_OK:
                if (log) {
                    smt_log_print (log, "%sexchange.declare-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%sexchange.declare-ok:"\
                        "", prefix);
                }
                break;
            case AMQ_SERVER_EXCHANGE_DELETE:
                if (log) {
                    smt_log_print (log, "%sexchange.delete:"\
                        " ticket=%d exchange=\"%s\" if_unused=%d nowait=%d", prefix,
                        self->payload.exchange_delete.ticket,
                        self->payload.exchange_delete.exchange,
                        self->payload.exchange_delete.if_unused,
                        self->payload.exchange_delete.nowait);
                }
                else {
                    icl_console_print ("%sexchange.delete:"\
                        " ticket=%d exchange=\"%s\" if_unused=%d nowait=%d", prefix,
                        self->payload.exchange_delete.ticket,
                        self->payload.exchange_delete.exchange,
                        self->payload.exchange_delete.if_unused,
                        self->payload.exchange_delete.nowait);
                }
                break;
            case AMQ_SERVER_EXCHANGE_DELETE_OK:
                if (log) {
                    smt_log_print (log, "%sexchange.delete-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%sexchange.delete-ok:"\
                        "", prefix);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    case AMQ_SERVER_QUEUE:
        switch (self->method_id) {
            case AMQ_SERVER_QUEUE_DECLARE:
                if (log) {
                    smt_log_print (log, "%squeue.declare:"\
                        " ticket=%d queue=\"%s\" passive=%d durable=%d exclusive=%d auto_delete=%d nowait=%d arguments=%uB", prefix,
                        self->payload.queue_declare.ticket,
                        self->payload.queue_declare.queue,
                        self->payload.queue_declare.passive,
                        self->payload.queue_declare.durable,
                        self->payload.queue_declare.exclusive,
                        self->payload.queue_declare.auto_delete,
                        self->payload.queue_declare.nowait,
                        self->payload.queue_declare.arguments?
                            self->payload.queue_declare.arguments->cur_size: 0);
                }
                else {
                    icl_console_print ("%squeue.declare:"\
                        " ticket=%d queue=\"%s\" passive=%d durable=%d exclusive=%d auto_delete=%d nowait=%d arguments=%uB", prefix,
                        self->payload.queue_declare.ticket,
                        self->payload.queue_declare.queue,
                        self->payload.queue_declare.passive,
                        self->payload.queue_declare.durable,
                        self->payload.queue_declare.exclusive,
                        self->payload.queue_declare.auto_delete,
                        self->payload.queue_declare.nowait,
                        self->payload.queue_declare.arguments?
                            self->payload.queue_declare.arguments->cur_size: 0);
                }
                break;
            case AMQ_SERVER_QUEUE_DECLARE_OK:
                if (log) {
                    smt_log_print (log, "%squeue.declare-ok:"\
                        " queue=\"%s\" message_count=%u consumer_count=%u", prefix,
                        self->payload.queue_declare_ok.queue,
                        self->payload.queue_declare_ok.message_count,
                        self->payload.queue_declare_ok.consumer_count);
                }
                else {
                    icl_console_print ("%squeue.declare-ok:"\
                        " queue=\"%s\" message_count=%u consumer_count=%u", prefix,
                        self->payload.queue_declare_ok.queue,
                        self->payload.queue_declare_ok.message_count,
                        self->payload.queue_declare_ok.consumer_count);
                }
                break;
            case AMQ_SERVER_QUEUE_BIND:
                if (log) {
                    smt_log_print (log, "%squeue.bind:"\
                        " ticket=%d queue=\"%s\" exchange=\"%s\" routing_key=\"%s\" nowait=%d arguments=%uB", prefix,
                        self->payload.queue_bind.ticket,
                        self->payload.queue_bind.queue,
                        self->payload.queue_bind.exchange,
                        self->payload.queue_bind.routing_key,
                        self->payload.queue_bind.nowait,
                        self->payload.queue_bind.arguments?
                            self->payload.queue_bind.arguments->cur_size: 0);
                }
                else {
                    icl_console_print ("%squeue.bind:"\
                        " ticket=%d queue=\"%s\" exchange=\"%s\" routing_key=\"%s\" nowait=%d arguments=%uB", prefix,
                        self->payload.queue_bind.ticket,
                        self->payload.queue_bind.queue,
                        self->payload.queue_bind.exchange,
                        self->payload.queue_bind.routing_key,
                        self->payload.queue_bind.nowait,
                        self->payload.queue_bind.arguments?
                            self->payload.queue_bind.arguments->cur_size: 0);
                }
                break;
            case AMQ_SERVER_QUEUE_BIND_OK:
                if (log) {
                    smt_log_print (log, "%squeue.bind-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%squeue.bind-ok:"\
                        "", prefix);
                }
                break;
            case AMQ_SERVER_QUEUE_PURGE:
                if (log) {
                    smt_log_print (log, "%squeue.purge:"\
                        " ticket=%d queue=\"%s\" nowait=%d", prefix,
                        self->payload.queue_purge.ticket,
                        self->payload.queue_purge.queue,
                        self->payload.queue_purge.nowait);
                }
                else {
                    icl_console_print ("%squeue.purge:"\
                        " ticket=%d queue=\"%s\" nowait=%d", prefix,
                        self->payload.queue_purge.ticket,
                        self->payload.queue_purge.queue,
                        self->payload.queue_purge.nowait);
                }
                break;
            case AMQ_SERVER_QUEUE_PURGE_OK:
                if (log) {
                    smt_log_print (log, "%squeue.purge-ok:"\
                        " message_count=%u", prefix,
                        self->payload.queue_purge_ok.message_count);
                }
                else {
                    icl_console_print ("%squeue.purge-ok:"\
                        " message_count=%u", prefix,
                        self->payload.queue_purge_ok.message_count);
                }
                break;
            case AMQ_SERVER_QUEUE_DELETE:
                if (log) {
                    smt_log_print (log, "%squeue.delete:"\
                        " ticket=%d queue=\"%s\" if_unused=%d if_empty=%d nowait=%d", prefix,
                        self->payload.queue_delete.ticket,
                        self->payload.queue_delete.queue,
                        self->payload.queue_delete.if_unused,
                        self->payload.queue_delete.if_empty,
                        self->payload.queue_delete.nowait);
                }
                else {
                    icl_console_print ("%squeue.delete:"\
                        " ticket=%d queue=\"%s\" if_unused=%d if_empty=%d nowait=%d", prefix,
                        self->payload.queue_delete.ticket,
                        self->payload.queue_delete.queue,
                        self->payload.queue_delete.if_unused,
                        self->payload.queue_delete.if_empty,
                        self->payload.queue_delete.nowait);
                }
                break;
            case AMQ_SERVER_QUEUE_DELETE_OK:
                if (log) {
                    smt_log_print (log, "%squeue.delete-ok:"\
                        " message_count=%u", prefix,
                        self->payload.queue_delete_ok.message_count);
                }
                else {
                    icl_console_print ("%squeue.delete-ok:"\
                        " message_count=%u", prefix,
                        self->payload.queue_delete_ok.message_count);
                }
                break;
            case AMQ_SERVER_QUEUE_UNBIND:
                if (log) {
                    smt_log_print (log, "%squeue.unbind:"\
                        " ticket=%d queue=\"%s\" exchange=\"%s\" routing_key=\"%s\" nowait=%d arguments=%uB", prefix,
                        self->payload.queue_unbind.ticket,
                        self->payload.queue_unbind.queue,
                        self->payload.queue_unbind.exchange,
                        self->payload.queue_unbind.routing_key,
                        self->payload.queue_unbind.nowait,
                        self->payload.queue_unbind.arguments?
                            self->payload.queue_unbind.arguments->cur_size: 0);
                }
                else {
                    icl_console_print ("%squeue.unbind:"\
                        " ticket=%d queue=\"%s\" exchange=\"%s\" routing_key=\"%s\" nowait=%d arguments=%uB", prefix,
                        self->payload.queue_unbind.ticket,
                        self->payload.queue_unbind.queue,
                        self->payload.queue_unbind.exchange,
                        self->payload.queue_unbind.routing_key,
                        self->payload.queue_unbind.nowait,
                        self->payload.queue_unbind.arguments?
                            self->payload.queue_unbind.arguments->cur_size: 0);
                }
                break;
            case AMQ_SERVER_QUEUE_UNBIND_OK:
                if (log) {
                    smt_log_print (log, "%squeue.unbind-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%squeue.unbind-ok:"\
                        "", prefix);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    case AMQ_SERVER_BASIC:
        switch (self->method_id) {
            case AMQ_SERVER_BASIC_QOS:
                if (log) {
                    smt_log_print (log, "%sbasic.qos:"\
                        " prefetch_size=%u prefetch_count=%d global=%d", prefix,
                        self->payload.basic_qos.prefetch_size,
                        self->payload.basic_qos.prefetch_count,
                        self->payload.basic_qos.global);
                }
                else {
                    icl_console_print ("%sbasic.qos:"\
                        " prefetch_size=%u prefetch_count=%d global=%d", prefix,
                        self->payload.basic_qos.prefetch_size,
                        self->payload.basic_qos.prefetch_count,
                        self->payload.basic_qos.global);
                }
                break;
            case AMQ_SERVER_BASIC_QOS_OK:
                if (log) {
                    smt_log_print (log, "%sbasic.qos-ok:"\
                        "", prefix);
                }
                else {
                    icl_console_print ("%sbasic.qos-ok:"\
                        "", prefix);
                }
                break;
            case AMQ_SERVER_BASIC_CONSUME:
                if (log) {
                    smt_log_print (log, "%sbasic.consume:"\
                        " ticket=%d queue=\"%s\" consumer_tag=\"%s\" no_local=%d no_ack=%d exclusive=%d nowait=%d arguments=%uB", prefix,
                        self->payload.basic_consume.ticket,
                        self->payload.basic_consume.queue,
                        self->payload.basic_consume.consumer_tag,
                        self->payload.basic_consume.no_local,
                        self->payload.basic_consume.no_ack,
                        self->payload.basic_consume.exclusive,
                        self->payload.basic_consume.nowait,
                        self->payload.basic_consume.arguments?
                            self->payload.basic_consume.arguments->cur_size: 0);
                }
                else {
                    icl_console_print ("%sbasic.consume:"\
                        " ticket=%d queue=\"%s\" consumer_tag=\"%s\" no_local=%d no_ack=%d exclusive=%d nowait=%d arguments=%uB", prefix,
                        self->payload.basic_consume.ticket,
                        self->payload.basic_consume.queue,
                        self->payload.basic_consume.consumer_tag,
                        self->payload.basic_consume.no_local,
                        self->payload.basic_consume.no_ack,
                        self->payload.basic_consume.exclusive,
                        self->payload.basic_consume.nowait,
                        self->payload.basic_consume.arguments?
                            self->payload.basic_consume.arguments->cur_size: 0);
                }
                break;
            case AMQ_SERVER_BASIC_CONSUME_OK:
                if (log) {
                    smt_log_print (log, "%sbasic.consume-ok:"\
                        " consumer_tag=\"%s\"", prefix,
                        self->payload.basic_consume_ok.consumer_tag);
                }
                else {
                    icl_console_print ("%sbasic.consume-ok:"\
                        " consumer_tag=\"%s\"", prefix,
                        self->payload.basic_consume_ok.consumer_tag);
                }
                break;
            case AMQ_SERVER_BASIC_CANCEL:
                if (log) {
                    smt_log_print (log, "%sbasic.cancel:"\
                        " consumer_tag=\"%s\" nowait=%d", prefix,
                        self->payload.basic_cancel.consumer_tag,
                        self->payload.basic_cancel.nowait);
                }
                else {
                    icl_console_print ("%sbasic.cancel:"\
                        " consumer_tag=\"%s\" nowait=%d", prefix,
                        self->payload.basic_cancel.consumer_tag,
                        self->payload.basic_cancel.nowait);
                }
                break;
            case AMQ_SERVER_BASIC_CANCEL_OK:
                if (log) {
                    smt_log_print (log, "%sbasic.cancel-ok:"\
                        " consumer_tag=\"%s\"", prefix,
                        self->payload.basic_cancel_ok.consumer_tag);
                }
                else {
                    icl_console_print ("%sbasic.cancel-ok:"\
                        " consumer_tag=\"%s\"", prefix,
                        self->payload.basic_cancel_ok.consumer_tag);
                }
                break;
            case AMQ_SERVER_BASIC_PUBLISH:
                if (log) {
                    smt_log_print (log, "%sbasic.publish:"\
                        " ticket=%d exchange=\"%s\" routing_key=\"%s\" mandatory=%d immediate=%d", prefix,
                        self->payload.basic_publish.ticket,
                        self->payload.basic_publish.exchange,
                        self->payload.basic_publish.routing_key,
                        self->payload.basic_publish.mandatory,
                        self->payload.basic_publish.immediate);
                }
                else {
                    icl_console_print ("%sbasic.publish:"\
                        " ticket=%d exchange=\"%s\" routing_key=\"%s\" mandatory=%d immediate=%d", prefix,
                        self->payload.basic_publish.ticket,
                        self->payload.basic_publish.exchange,
                        self->payload.basic_publish.routing_key,
                        self->payload.basic_publish.mandatory,
                        self->payload.basic_publish.immediate);
                }
                break;
            case AMQ_SERVER_BASIC_RETURN:
                if (log) {
                    smt_log_print (log, "%sbasic.return:"\
                        " reply_code=%d reply_text=\"%s\" exchange=\"%s\" routing_key=\"%s\"", prefix,
                        self->payload.basic_return.reply_code,
                        self->payload.basic_return.reply_text,
                        self->payload.basic_return.exchange,
                        self->payload.basic_return.routing_key);
                }
                else {
                    icl_console_print ("%sbasic.return:"\
                        " reply_code=%d reply_text=\"%s\" exchange=\"%s\" routing_key=\"%s\"", prefix,
                        self->payload.basic_return.reply_code,
                        self->payload.basic_return.reply_text,
                        self->payload.basic_return.exchange,
                        self->payload.basic_return.routing_key);
                }
                break;
            case AMQ_SERVER_BASIC_DELIVER:
                if (log) {
                    smt_log_print (log, "%sbasic.deliver:"\
                        " consumer_tag=\"%s\" delivery_tag=%lu redelivered=%d exchange=\"%s\" routing_key=\"%s\"", prefix,
                        self->payload.basic_deliver.consumer_tag,
                        (long) self->payload.basic_deliver.delivery_tag,
                        self->payload.basic_deliver.redelivered,
                        self->payload.basic_deliver.exchange,
                        self->payload.basic_deliver.routing_key);
                }
                else {
                    icl_console_print ("%sbasic.deliver:"\
                        " consumer_tag=\"%s\" delivery_tag=%lu redelivered=%d exchange=\"%s\" routing_key=\"%s\"", prefix,
                        self->payload.basic_deliver.consumer_tag,
                        (long) self->payload.basic_deliver.delivery_tag,
                        self->payload.basic_deliver.redelivered,
                        self->payload.basic_deliver.exchange,
                        self->payload.basic_deliver.routing_key);
                }
                break;
            case AMQ_SERVER_BASIC_GET:
                if (log) {
                    smt_log_print (log, "%sbasic.get:"\
                        " ticket=%d queue=\"%s\" no_ack=%d", prefix,
                        self->payload.basic_get.ticket,
                        self->payload.basic_get.queue,
                        self->payload.basic_get.no_ack);
                }
                else {
                    icl_console_print ("%sbasic.get:"\
                        " ticket=%d queue=\"%s\" no_ack=%d", prefix,
                        self->payload.basic_get.ticket,
                        self->payload.basic_get.queue,
                        self->payload.basic_get.no_ack);
                }
                break;
            case AMQ_SERVER_BASIC_GET_OK:
                if (log) {
                    smt_log_print (log, "%sbasic.get-ok:"\
                        " delivery_tag=%lu redelivered=%d exchange=\"%s\" routing_key=\"%s\" message_count=%u", prefix,
                        (long) self->payload.basic_get_ok.delivery_tag,
                        self->payload.basic_get_ok.redelivered,
                        self->payload.basic_get_ok.exchange,
                        self->payload.basic_get_ok.routing_key,
                        self->payload.basic_get_ok.message_count);
                }
                else {
                    icl_console_print ("%sbasic.get-ok:"\
                        " delivery_tag=%lu redelivered=%d exchange=\"%s\" routing_key=\"%s\" message_count=%u", prefix,
                        (long) self->payload.basic_get_ok.delivery_tag,
                        self->payload.basic_get_ok.redelivered,
                        self->payload.basic_get_ok.exchange,
                        self->payload.basic_get_ok.routing_key,
                        self->payload.basic_get_ok.message_count);
                }
                break;
            case AMQ_SERVER_BASIC_GET_EMPTY:
                if (log) {
                    smt_log_print (log, "%sbasic.get-empty:"\
                        " sender_id=\"%s\"", prefix,
                        self->payload.basic_get_empty.sender_id);
                }
                else {
                    icl_console_print ("%sbasic.get-empty:"\
                        " sender_id=\"%s\"", prefix,
                        self->payload.basic_get_empty.sender_id);
                }
                break;
            case AMQ_SERVER_BASIC_ACK:
                if (log) {
                    smt_log_print (log, "%sbasic.ack:"\
                        " delivery_tag=%lu multiple=%d", prefix,
                        (long) self->payload.basic_ack.delivery_tag,
                        self->payload.basic_ack.multiple);
                }
                else {
                    icl_console_print ("%sbasic.ack:"\
                        " delivery_tag=%lu multiple=%d", prefix,
                        (long) self->payload.basic_ack.delivery_tag,
                        self->payload.basic_ack.multiple);
                }
                break;
            case AMQ_SERVER_BASIC_REJECT:
                if (log) {
                    smt_log_print (log, "%sbasic.reject:"\
                        " delivery_tag=%lu requeue=%d", prefix,
                        (long) self->payload.basic_reject.delivery_tag,
                        self->payload.basic_reject.requeue);
                }
                else {
                    icl_console_print ("%sbasic.reject:"\
                        " delivery_tag=%lu requeue=%d", prefix,
                        (long) self->payload.basic_reject.delivery_tag,
                        self->payload.basic_reject.requeue);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    case AMQ_SERVER_DIRECT:
        switch (self->method_id) {
            case AMQ_SERVER_DIRECT_PUT:
                if (log) {
                    smt_log_print (log, "%sdirect.put:"\
                        " sink=\"%s\"", prefix,
                        self->payload.direct_put.sink);
                }
                else {
                    icl_console_print ("%sdirect.put:"\
                        " sink=\"%s\"", prefix,
                        self->payload.direct_put.sink);
                }
                break;
            case AMQ_SERVER_DIRECT_PUT_OK:
                if (log) {
                    smt_log_print (log, "%sdirect.put-ok:"\
                        " lease=\"%s\"", prefix,
                        self->payload.direct_put_ok.lease);
                }
                else {
                    icl_console_print ("%sdirect.put-ok:"\
                        " lease=\"%s\"", prefix,
                        self->payload.direct_put_ok.lease);
                }
                break;
            case AMQ_SERVER_DIRECT_GET:
                if (log) {
                    smt_log_print (log, "%sdirect.get:"\
                        " feed=\"%s\"", prefix,
                        self->payload.direct_get.feed);
                }
                else {
                    icl_console_print ("%sdirect.get:"\
                        " feed=\"%s\"", prefix,
                        self->payload.direct_get.feed);
                }
                break;
            case AMQ_SERVER_DIRECT_GET_OK:
                if (log) {
                    smt_log_print (log, "%sdirect.get-ok:"\
                        " lease=\"%s\"", prefix,
                        self->payload.direct_get_ok.lease);
                }
                else {
                    icl_console_print ("%sdirect.get-ok:"\
                        " lease=\"%s\"", prefix,
                        self->payload.direct_get_ok.lease);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    case AMQ_SERVER_RESTMS:
        switch (self->method_id) {
            case AMQ_SERVER_RESTMS_PIPE_CREATE:
                if (log) {
                    smt_log_print (log, "%srestms.pipe-create:"\
                        " pipe_type=\"%s\" pipe_name=\"%s\"", prefix,
                        self->payload.restms_pipe_create.pipe_type,
                        self->payload.restms_pipe_create.pipe_name);
                }
                else {
                    icl_console_print ("%srestms.pipe-create:"\
                        " pipe_type=\"%s\" pipe_name=\"%s\"", prefix,
                        self->payload.restms_pipe_create.pipe_type,
                        self->payload.restms_pipe_create.pipe_name);
                }
                break;
            case AMQ_SERVER_RESTMS_PIPE_DELETE:
                if (log) {
                    smt_log_print (log, "%srestms.pipe-delete:"\
                        " pipe_name=\"%s\"", prefix,
                        self->payload.restms_pipe_delete.pipe_name);
                }
                else {
                    icl_console_print ("%srestms.pipe-delete:"\
                        " pipe_name=\"%s\"", prefix,
                        self->payload.restms_pipe_delete.pipe_name);
                }
                break;
            case AMQ_SERVER_RESTMS_FEED_CREATE:
                if (log) {
                    smt_log_print (log, "%srestms.feed-create:"\
                        " feed_type=\"%s\" feed_name=\"%s\"", prefix,
                        self->payload.restms_feed_create.feed_type,
                        self->payload.restms_feed_create.feed_name);
                }
                else {
                    icl_console_print ("%srestms.feed-create:"\
                        " feed_type=\"%s\" feed_name=\"%s\"", prefix,
                        self->payload.restms_feed_create.feed_type,
                        self->payload.restms_feed_create.feed_name);
                }
                break;
            case AMQ_SERVER_RESTMS_FEED_DELETE:
                if (log) {
                    smt_log_print (log, "%srestms.feed-delete:"\
                        " feed_name=\"%s\"", prefix,
                        self->payload.restms_feed_delete.feed_name);
                }
                else {
                    icl_console_print ("%srestms.feed-delete:"\
                        " feed_name=\"%s\"", prefix,
                        self->payload.restms_feed_delete.feed_name);
                }
                break;
            case AMQ_SERVER_RESTMS_JOIN_CREATE:
                if (log) {
                    smt_log_print (log, "%srestms.join-create:"\
                        " pipe_name=\"%s\" feed_name=\"%s\" address=\"%s\"", prefix,
                        self->payload.restms_join_create.pipe_name,
                        self->payload.restms_join_create.feed_name,
                        self->payload.restms_join_create.address);
                }
                else {
                    icl_console_print ("%srestms.join-create:"\
                        " pipe_name=\"%s\" feed_name=\"%s\" address=\"%s\"", prefix,
                        self->payload.restms_join_create.pipe_name,
                        self->payload.restms_join_create.feed_name,
                        self->payload.restms_join_create.address);
                }
                break;
            case AMQ_SERVER_RESTMS_JOIN_DELETE:
                if (log) {
                    smt_log_print (log, "%srestms.join-delete:"\
                        " pipe_name=\"%s\" feed_name=\"%s\" address=\"%s\"", prefix,
                        self->payload.restms_join_delete.pipe_name,
                        self->payload.restms_join_delete.feed_name,
                        self->payload.restms_join_delete.address);
                }
                else {
                    icl_console_print ("%srestms.join-delete:"\
                        " pipe_name=\"%s\" feed_name=\"%s\" address=\"%s\"", prefix,
                        self->payload.restms_join_delete.pipe_name,
                        self->payload.restms_join_delete.feed_name,
                        self->payload.restms_join_delete.address);
                }
                break;
            default:
                if (log)
                    smt_log_print (log, "E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
                else
                    icl_console_print ("E: illegal method (class=%d, method=%d)",
                        self->class_id, self->method_id);
        }
        break;
    default:
        if (log)
            smt_log_print (log, "E: illegal class=%d", self->class_id);
        else
            icl_console_print ("E: illegal class=%d", self->class_id);
}
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_method_execute

    Type: Component method
    Accepts a amq_server_method_t reference and returns zero in case of success,
    1 in case of errors.
    Accepts a amq_server_method_t object and executes the method.
    Returns 0 if the method was executed successfully, non-zero if there
    was an error - e.g. if the method is not allowed for this chassis.
    -------------------------------------------------------------------------
 */

int
    amq_server_method_execute (
    amq_server_method_t * self,         //  Reference to object
    amq_server_connection_t * connection,   //  Current connection object, or null (if internal execution)
    amq_server_channel_t * channel      //  Current channel object, or null (if no channel opened)
)
{
    int
        rc = 0;                         //  Return code

AMQ_SERVER_METHOD_ASSERT_SANE (self);
if (!self->zombie) {

//

if (self->class_id  == AMQ_SERVER_CONNECTION
&&  self->method_id == AMQ_SERVER_CONNECTION_START_OK) {
    amq_server_connection_start_ok_t
        *method;
    method = &self->payload.connection_start_ok;
    {
        amq_server_connection_start_ok (connection, method);
    }
}
else
if (self->class_id  == AMQ_SERVER_CONNECTION
&&  self->method_id == AMQ_SERVER_CONNECTION_TUNE_OK) {
    amq_server_connection_tune_ok_t
        *method;
    method = &self->payload.connection_tune_ok;
    {
        amq_server_connection_tune_ok (connection, method);
    }
}
else
if (self->class_id  == AMQ_SERVER_CONNECTION
&&  self->method_id == AMQ_SERVER_CONNECTION_OPEN) {
    amq_server_connection_open_t
        *method;
    method = &self->payload.connection_open;
    {
        amq_server_connection_open (connection, method);
    }
}
else
if (self->class_id  == AMQ_SERVER_CHANNEL
&&  self->method_id == AMQ_SERVER_CHANNEL_FLOW) {
    amq_server_channel_flow_t
        *method;
    method = &self->payload.channel_flow;
    {
        amq_server_channel_flow (channel, method->active);
    }
}
else
if (self->class_id  == AMQ_SERVER_EXCHANGE
&&  self->method_id == AMQ_SERVER_EXCHANGE_DECLARE) {
    amq_server_exchange_declare_t
        *method;
    method = &self->payload.exchange_declare;
    {
        amq_exchange_t
    *exchange;
int
    exchange_type;
//
exchange_type = amq_exchange_type_lookup (method->type);
if (exchange_type != -1) {
    //  Find exchange and create if necessary
    exchange = amq_exchange_table_search (amq_broker->exchange_table, method->exchange);
    if (!exchange) {
        if (method->passive)
            amq_server_channel_error (channel, ASL_NOT_FOUND, "No such exchange defined",
                AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DECLARE);
        else {
            if (ipr_str_prefixed (method->exchange, "amq."))
                amq_server_channel_error (channel,
                    ASL_ACCESS_REFUSED, "Exchange name not allowed",
                    AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DECLARE);
            else {
                exchange = amq_exchange_new (
                    exchange_type,
                    method->exchange,
                    method->internal,
                    FALSE);         //  Do not federate automatically

                //  This can fail if two threads create the same exchange at the
                //  same time... so let's go find the actual exchange object
                if (!exchange)
                    exchange = amq_exchange_table_search (
                        amq_broker->exchange_table, method->exchange);
            }
        }
    }
    if (exchange) {
        if (exchange->type == exchange_type) {
            icl_shortstr_cpy (channel->current_exchange, exchange->name);
            if (!method->nowait)
                amq_server_agent_exchange_declare_ok (connection->thread, channel->number);
        }
        else
            amq_server_connection_error (connection,
                ASL_NOT_ALLOWED, "Exchange exists with different type",
                AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DECLARE);

        amq_exchange_unlink (&exchange);
    }
}
else
    amq_server_connection_error (connection, ASL_COMMAND_INVALID, "Unknown exchange type",
        AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DECLARE);
    }
}
else
if (self->class_id  == AMQ_SERVER_EXCHANGE
&&  self->method_id == AMQ_SERVER_EXCHANGE_DELETE) {
    amq_server_exchange_delete_t
        *method;
    method = &self->payload.exchange_delete;
    {
        amq_exchange_t
    *exchange;
//
//  Use current channel exchange if method has a blank name
if (strnull (method->exchange))
    icl_shortstr_cpy (method->exchange, channel->current_exchange);

if (ipr_str_prefixed (method->exchange, "amq."))
   amq_server_channel_error (channel,
        ASL_ACCESS_REFUSED, "Exchange name not allowed",
        AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DECLARE);
else {
    exchange = amq_exchange_table_search (
        amq_broker->exchange_table, method->exchange);
    if (exchange) {
        //  Tell client delete was successful
        if (!method->nowait)
            amq_server_agent_exchange_delete_ok (connection->thread, channel->number);

        //  Destroy the exchange on this peer
        amq_exchange_destroy (&exchange);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND, "No such exchange defined",
            AMQ_SERVER_EXCHANGE, AMQ_SERVER_EXCHANGE_DELETE);
}
    }
}
else
if (self->class_id  == AMQ_SERVER_QUEUE
&&  self->method_id == AMQ_SERVER_QUEUE_DECLARE) {
    amq_server_queue_declare_t
        *method;
    method = &self->payload.queue_declare;
    {
        amq_queue_t
    *queue;
static qbyte
    queue_index = 0;
//
//  Find queue and create if necessary
if (strnull (method->queue))
    icl_shortstr_fmt (method->queue, "auto.%d", icl_atomic_inc32 (&queue_index));
queue = amq_queue_table_search (amq_broker->queue_table, method->queue);
if (!queue) {
    if (method->passive)
        amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
    else
    if (method->durable)
        amq_server_channel_error (channel, ASL_NOT_IMPLEMENTED, "Durable queues not supported",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
    else {
        //  The queue->connection specifies owner connection, for exclusive queues
        queue = amq_queue_new (
            method->exclusive? connection: NULL,
            method->queue,
            method->exclusive,
            //  Setting the 'exclusive' flag always implies 'auto-delete'
            method->exclusive? TRUE: method->auto_delete,
            method->arguments);

        //  This can fail if two threads create the same queue at the
        //  same time... so let's go find the actual queue object
        if (!queue)
            queue = amq_queue_table_search (
                amq_broker->queue_table, method->queue);

        if (queue) {
            //  Make automatic binding to default exchange
            amq_exchange_bind_queue (
                amq_broker->default_exchange, NULL, queue, queue->name, NULL);

            //  Add to connection's exclusive queue list
            if (method->exclusive)
                amq_server_connection_own_queue (connection, queue);
        }
        else
            amq_server_connection_error (connection,
                ASL_RESOURCE_ERROR, "Unable to declare queue",
                AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
    }
}
if (queue) {
    if (method->exclusive && queue->connection == NULL)
        icl_console_print ("W: queue.declare aborted by connection close");
    else
    if (method->exclusive && queue->connection != connection)
        amq_server_channel_error (
            channel,
            ASL_ACCESS_REFUSED,
            "Queue cannot be made exclusive to this connection",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DECLARE);
    else {
        //  AMQP requires us to hold a current queue per channel
        icl_shortstr_cpy (channel->current_queue, queue->name);
        if (!method->nowait)
            amq_server_agent_queue_declare_ok (
                connection->thread,
                channel->number,
                queue->name,
                amq_queue_message_count (queue),
                amq_queue_consumer_count (queue));
    }
    amq_queue_unlink (&queue);
}
    }
}
else
if (self->class_id  == AMQ_SERVER_QUEUE
&&  self->method_id == AMQ_SERVER_QUEUE_BIND) {
    amq_server_queue_bind_t
        *method;
    method = &self->payload.queue_bind;
    {
        amq_exchange_t
    *exchange;                      //  Exchange to bind to
amq_queue_t
    *queue;
//
//  Use current channel queue if method uses a blank queue
if (strnull (method->queue)) {
    icl_shortstr_cpy (method->queue, channel->current_queue);
    if (strnull (method->routing_key))
        icl_shortstr_cpy (method->routing_key, channel->current_queue);
}
exchange = amq_exchange_table_search (
    amq_broker->exchange_table, method->exchange);
if (exchange) {
    queue = amq_queue_table_search (amq_broker->queue_table, method->queue);
    if (queue) {
        amq_exchange_bind_queue (
            exchange, channel, queue, method->routing_key, method->arguments);
        if (!method->nowait)
            amq_server_agent_queue_bind_ok (connection->thread, channel->number);
        amq_queue_unlink (&queue);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_BIND);
    amq_exchange_unlink (&exchange);
}
else
    amq_server_channel_error (channel, ASL_NOT_FOUND, "No such exchange defined",
        AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_BIND);
    }
}
else
if (self->class_id  == AMQ_SERVER_QUEUE
&&  self->method_id == AMQ_SERVER_QUEUE_PURGE) {
    amq_server_queue_purge_t
        *method;
    method = &self->payload.queue_purge;
    {
        amq_queue_t
    *queue;
//
//  Use current channel queue if method uses a blank queue
if (strnull (method->queue))
    icl_shortstr_cpy (method->queue, channel->current_queue);

queue = amq_queue_table_search (amq_broker->queue_table, method->queue);
if (queue) {
    amq_queue_purge (queue, channel, method->nowait);
    amq_queue_unlink (&queue);
}
else
    amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
        AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_PURGE);
    }
}
else
if (self->class_id  == AMQ_SERVER_QUEUE
&&  self->method_id == AMQ_SERVER_QUEUE_DELETE) {
    amq_server_queue_delete_t
        *method;
    method = &self->payload.queue_delete;
    {
        amq_queue_t
    *queue;
//
//  Use current channel queue if method uses a blank queue
if (strnull (method->queue))
    icl_shortstr_cpy (method->queue, channel->current_queue);

queue = amq_queue_table_search (amq_broker->queue_table, method->queue);
if (queue) {
    //  Tell client we deleted the queue ok
    if (!method->nowait)
        amq_server_agent_queue_delete_ok (
            connection->thread, channel->number, amq_queue_message_count (queue));

    //  Destroy method does not properly release all links to queue
    amq_queue_self_destruct (queue);
    amq_queue_unlink (&queue);
}
else
    amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
        AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_DELETE);
    }
}
else
if (self->class_id  == AMQ_SERVER_QUEUE
&&  self->method_id == AMQ_SERVER_QUEUE_UNBIND) {
    amq_server_queue_unbind_t
        *method;
    method = &self->payload.queue_unbind;
    {
        amq_exchange_t
    *exchange;                      //  Exchange to unbind from
amq_queue_t
    *queue;
//
//  Use current channel queue if method uses a blank queue
if (strnull (method->queue)) {
    icl_shortstr_cpy (method->queue, channel->current_queue);
    if (strnull (method->routing_key))
        icl_shortstr_cpy (method->routing_key, channel->current_queue);
}
exchange = amq_exchange_table_search (amq_broker->exchange_table, method->exchange);
if (exchange) {
    queue = amq_queue_table_search (amq_broker->queue_table, method->queue);
    if (queue) {
        amq_exchange_unbind_queue (
            exchange, channel, queue, method->routing_key, method->arguments);
        if (!method->nowait)
            amq_server_agent_queue_unbind_ok (connection->thread, channel->number);
        amq_queue_unlink (&queue);
    }
    else
        amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_UNBIND);
    amq_exchange_unlink (&exchange);
}
else
    amq_server_channel_error (channel, ASL_NOT_FOUND, "No such exchange defined",
        AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_UNBIND);
    }
}
else
if (self->class_id  == AMQ_SERVER_BASIC
&&  self->method_id == AMQ_SERVER_BASIC_QOS) {
    amq_server_basic_qos_t
        *method;
    method = &self->payload.basic_qos;
    {
        //  Does not do anything except respond Qos-Ok
amq_server_agent_basic_qos_ok (connection->thread, channel->number);
    }
}
else
if (self->class_id  == AMQ_SERVER_BASIC
&&  self->method_id == AMQ_SERVER_BASIC_CONSUME) {
    amq_server_basic_consume_t
        *method;
    method = &self->payload.basic_consume;
    {
        amq_queue_t
    *queue;
//
//  Use current channel queue if method uses a blank queue
if (strnull (method->queue))
    icl_shortstr_cpy (method->queue, channel->current_queue);

queue = amq_queue_table_search (amq_broker->queue_table, method->queue);
if (queue) {
    //  The channel is responsible for creating/canceling consumers
    amq_server_channel_consume (channel, queue, self);
    amq_queue_unlink (&queue);
}
else
    amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
        AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_CONSUME);
    }
}
else
if (self->class_id  == AMQ_SERVER_BASIC
&&  self->method_id == AMQ_SERVER_BASIC_CANCEL) {
    amq_server_basic_cancel_t
        *method;
    method = &self->payload.basic_cancel;
    {
        amq_server_channel_cancel (channel, method->consumer_tag, TRUE, method->nowait);
    }
}
else
if (self->class_id  == AMQ_SERVER_BASIC
&&  self->method_id == AMQ_SERVER_BASIC_PUBLISH) {
    amq_server_basic_publish_t
        *method;
    amq_content_basic_t
        *content;
    method = &self->payload.basic_publish;
    content = (amq_content_basic_t *) self->content;
    {
        amq_exchange_t
    *exchange;
icl_shortstr_t
    sender_id;
//
if (*method->exchange)
    //  Lookup exchange specified in method
    exchange = amq_exchange_table_search (
        amq_broker->exchange_table, method->exchange);
else
    //  Get default exchange for virtual host
    exchange = amq_exchange_link (amq_broker->default_exchange);

if (exchange) {
    if (!exchange->internal || strnull (method->exchange)) {
        //  This method may only come from an external application
        assert (connection);
        amq_content_basic_set_routing_key (
            content,
            method->exchange,
            method->routing_key,
            connection->id);
        if (exchange->federation) {
            icl_shortstr_fmt (sender_id, "%s|%d", connection->key,
                channel->number);
            amq_content_basic_set_sender_id (content, sender_id);
        }
        amq_exchange_publish (
            exchange,
            channel,
            content,
            method->mandatory,
            method->immediate,
            connection->group);
    }
    else
        amq_server_channel_error (channel,
            ASL_ACCESS_REFUSED, "Exchange is for internal use only",
            AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_PUBLISH);

    amq_exchange_unlink (&exchange);
}
else
    amq_server_channel_error (channel, ASL_NOT_FOUND, "No such exchange defined",
        AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_PUBLISH);
    }
}
else
if (self->class_id  == AMQ_SERVER_BASIC
&&  self->method_id == AMQ_SERVER_BASIC_GET) {
    amq_server_basic_get_t
        *method;
    method = &self->payload.basic_get;
    {
        amq_queue_t
    *queue;
//
//  Use current channel queue if method uses a blank queue
if (strnull (method->queue))
    icl_shortstr_cpy (method->queue, channel->current_queue);

queue = amq_queue_table_search (amq_broker->queue_table, method->queue);
if (queue) {
    amq_queue_get (queue, channel, self->class_id);
    amq_queue_unlink (&queue);
}
else
    amq_server_channel_error (channel, ASL_NOT_FOUND, "No such queue defined",
        AMQ_SERVER_BASIC, AMQ_SERVER_BASIC_GET);
    }
}
else
if (self->class_id  == AMQ_SERVER_BASIC
&&  self->method_id == AMQ_SERVER_BASIC_ACK) {
    amq_server_basic_ack_t
        *method;
    method = &self->payload.basic_ack;
    {
        amq_server_channel_ack (channel, method->delivery_tag, method->multiple);
    }
}
else
if (self->class_id  == AMQ_SERVER_DIRECT
&&  self->method_id == AMQ_SERVER_DIRECT_PUT) {
    amq_server_direct_put_t
        *method;
    method = &self->payload.direct_put;
    {
        amq_lease_t
    *lease;
//
lease = amq_lease_new (method->sink, DP_SINK, channel);
if (lease) {
    amq_server_agent_direct_put_ok (connection->thread, channel->number, lease->name);
    amq_lease_unlink (&lease);
}
else
    amq_server_channel_error (channel, ASL_NOT_FOUND,
        "No such sink",
        AMQ_SERVER_DIRECT, AMQ_SERVER_DIRECT_PUT);
    }
}
else
if (self->class_id  == AMQ_SERVER_DIRECT
&&  self->method_id == AMQ_SERVER_DIRECT_GET) {
    amq_server_direct_get_t
        *method;
    method = &self->payload.direct_get;
    {
        amq_lease_t
    *lease;
//
lease = amq_lease_new (method->feed, DP_FEED, channel);
if (lease) {
    amq_server_agent_direct_get_ok (connection->thread, channel->number, lease->name);
    amq_lease_unlink (&lease);
}
else
    amq_server_channel_error (channel, ASL_NOT_FOUND,
        "No such feed",
        AMQ_SERVER_DIRECT, AMQ_SERVER_DIRECT_GET);
    }
}
else
if (self->class_id  == AMQ_SERVER_RESTMS
&&  self->method_id == AMQ_SERVER_RESTMS_PIPE_CREATE) {
    amq_server_restms_pipe_create_t
        *method;
    method = &self->payload.restms_pipe_create;
    {
        amq_resource_pipe_create (method->pipe_type, method->pipe_name, channel);
    }
}
else
if (self->class_id  == AMQ_SERVER_RESTMS
&&  self->method_id == AMQ_SERVER_RESTMS_PIPE_DELETE) {
    amq_server_restms_pipe_delete_t
        *method;
    method = &self->payload.restms_pipe_delete;
    {
        amq_resource_pipe_delete (method->pipe_name);
    }
}
else
if (self->class_id  == AMQ_SERVER_RESTMS
&&  self->method_id == AMQ_SERVER_RESTMS_FEED_CREATE) {
    amq_server_restms_feed_create_t
        *method;
    method = &self->payload.restms_feed_create;
    {
        amq_resource_feed_create (method->feed_type, method->feed_name);
    }
}
else
if (self->class_id  == AMQ_SERVER_RESTMS
&&  self->method_id == AMQ_SERVER_RESTMS_FEED_DELETE) {
    amq_server_restms_feed_delete_t
        *method;
    method = &self->payload.restms_feed_delete;
    {
        amq_resource_feed_delete (method->feed_name);
    }
}
else
if (self->class_id  == AMQ_SERVER_RESTMS
&&  self->method_id == AMQ_SERVER_RESTMS_JOIN_CREATE) {
    amq_server_restms_join_create_t
        *method;
    method = &self->payload.restms_join_create;
    {
        amq_resource_join_create (
    method->pipe_name, method->feed_name, method->address, channel);
    }
}
else
if (self->class_id  == AMQ_SERVER_RESTMS
&&  self->method_id == AMQ_SERVER_RESTMS_JOIN_DELETE) {
    amq_server_restms_join_delete_t
        *method;
    method = &self->payload.restms_join_delete;
    {
        amq_resource_join_delete (
    method->pipe_name, method->feed_name, method->address, channel);
    }
}
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_server_method_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_method_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_server_method_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_method_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_server_method_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_server_method zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
    if (self->history_last > AMQ_SERVER_METHOD_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_SERVER_METHOD_HISTORY_LENGTH;
        self->history_last %= AMQ_SERVER_METHOD_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_SERVER_METHOD_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_server_method>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_server_method_destroy

    Type: Component method
    Destroys a amq_server_method_t object. Takes the address of a
    amq_server_method_t reference (a pointer to a pointer) and nullifies the
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
    amq_server_method_destroy_ (
    amq_server_method_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_server_method_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_server_method_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("amq_server_method", "E: missing link on amq_server_method object");
        amq_server_method_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_server_method_free_ ((amq_server_method_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_server_method_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_server_method_t *
    amq_server_method_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_server_method_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_server_method_cache_initialise ();

self = (amq_server_method_t *) icl_mem_cache_alloc_ (s_cache, file, line);



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_free

    Type: Component method
    Freess a amq_server_method_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_server_method_free_ (
    amq_server_method_t * self,         //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = self->links;
#endif

    self->object_tag = AMQ_SERVER_METHOD_DEAD;
    icl_mem_free (self);
}
self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_server_method_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_server_method_t *
    amq_server_method_link_ (
    amq_server_method_t * self,         //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
    int
        history_last;
#endif

    if (self) {
        AMQ_SERVER_METHOD_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_server_method_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_server_method_unlink_ (
    amq_server_method_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
    int
        history_last;
#endif

    amq_server_method_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        AMQ_SERVER_METHOD_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("amq_server_method", "E: missing link on amq_server_method object");
            amq_server_method_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_METHOD)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_SERVER_METHOD_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_server_method_annihilate_ (self_p, file, line);
        amq_server_method_free_ ((amq_server_method_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_server_method_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_server_method_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_server_method_t));
icl_system_register (amq_server_method_cache_purge, amq_server_method_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_server_method_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_method_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_server_method_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_server_method_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_server_method_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_server_method_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_server_method_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_server_method_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_server_method_new_in_scope_ (
    amq_server_method_t * * self_p,     //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_server_method_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_server_method_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_server_method_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_server_method_component  = "amq_server_method ";
char *EMBED__amq_server_method_version    = "1.0 ";
char *EMBED__amq_server_method_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_server_method_filename   = "amq_server_method.icl ";
char *EMBED__amq_server_method_builddate  = "2010/10/06 ";
char *EMBED__amq_server_method_version_end  = "VeRsIoNeNd:ipc";

