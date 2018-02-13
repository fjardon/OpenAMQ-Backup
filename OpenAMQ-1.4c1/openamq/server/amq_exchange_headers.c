/*---------------------------------------------------------------------------
    amq_exchange_headers.c - amq_exchange_headers component

This class implements the headers exchange, which routes messages
based on the message header fields (the field table called "headers"
that is in every content header).  Max. unique fields exchange is
limited by size of amq_index_hash table.
    Generated from amq_exchange_headers.icl by icl_gen using GSL/4.
    
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
#include "amq_exchange_headers.h"       //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_exchange_headers_t

//  Shorthands for class methods

#define self_new            amq_exchange_headers_new
#define self_annihilate     amq_exchange_headers_annihilate
#define self_compile        amq_exchange_headers_compile
#define self_publish        amq_exchange_headers_publish
#define self_unbind         amq_exchange_headers_unbind
#define self_selftest       amq_exchange_headers_selftest
#define self_terminate      amq_exchange_headers_terminate
#define self_show           amq_exchange_headers_show
#define self_destroy        amq_exchange_headers_destroy
#define self_alloc          amq_exchange_headers_alloc
#define self_free           amq_exchange_headers_free
#define self_cache_initialise  amq_exchange_headers_cache_initialise
#define self_cache_purge    amq_exchange_headers_cache_purge
#define self_cache_terminate  amq_exchange_headers_cache_terminate
#define self_show_animation  amq_exchange_headers_show_animation
#define self_new_in_scope   amq_exchange_headers_new_in_scope

static void
    amq_exchange_headers_annihilate (
amq_exchange_headers_t * ( * self_p )   //  Reference to object reference
);

#define amq_exchange_headers_alloc()    amq_exchange_headers_alloc_ (__FILE__, __LINE__)
static amq_exchange_headers_t *
    amq_exchange_headers_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_exchange_headers_free (
amq_exchange_headers_t * self           //  Object reference
);

static void
    amq_exchange_headers_cache_initialise (
void);

static void
    amq_exchange_headers_cache_purge (
void);

static void
    amq_exchange_headers_cache_terminate (
void);

Bool
    amq_exchange_headers_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static int
    s_compare_queue (const void *queue1, const void *queue2);
static void
    s_direct_deliver (amq_queue_t *queue, amq_content_basic_t *content, amq_lease_t *lease);
static int
    s_compile_binding (amq_exchange_headers_t *self, amq_binding_t *binding, char *index_key);
static int
s_compare_queue (const void *queue1, const void *queue2)
{
    if (*(void **) queue1 < *(void **) queue2)
        return (-1);
    else
    if (*(void **) queue1 > *(void **) queue2)
        return (1);
    else
        return (0);
}

void
s_direct_deliver (amq_queue_t *queue, amq_content_basic_t *content, amq_lease_t *lease)
{
    qbyte
        queue_size = 0;

    queue->contents_in++;
    queue->traffic_in += content->body_size;
    queue_size = icl_atomic_inc32 ((volatile qbyte *) &(lease->pending));
    //  Track highest known direct queue size for monitoring
    if (amq_broker->direct_high < queue_size)
        amq_broker->direct_high = queue_size;

    //  This code mirrors code in amq_queue_basic.icl
    //  Check warning limit
    if (queue->warn_limit && queue_size >= queue->warn_limit && !queue->warned) {
        smt_log_print (amq_broker->alert_log,
            "W: queue=%s hit %d messages: no action (%s, %s, %s %s)",
            queue->name, queue_size,
            queue->connection->client_address,
            queue->connection->client_product,
            queue->connection->client_version,
            queue->connection->client_instance);
        queue->warned = TRUE;
    }
    //  Check just one of drop/trim (trim processed like drop, kill ignored)
    if ((queue->drop_limit && queue_size >= queue->drop_limit)
    ||  (queue->trim_limit && queue_size >= queue->trim_limit)) {
        if (!queue->dropped) {
            smt_log_print (amq_broker->alert_log,
                "W: queue=%s hit %d messages: dropping messages (%s, %s, %s, %s)",
                queue->name, queue_size,
                queue->connection->client_address,
                queue->connection->client_product,
                queue->connection->client_version,
                queue->connection->client_instance);
            queue->dropped = TRUE;
        }
        icl_atomic_dec32 ((volatile qbyte *) &(lease->pending));
        queue->drop_count++;
        content = NULL;
    }
    if (content) {
        //  Update queue statistics
        queue->contents_out++;
        queue->traffic_out += content->body_size;

        amq_server_agent_direct_out (lease->thread, content, 0);
        icl_atomic_inc32 ((volatile qbyte *) &(amq_broker->direct_fed));
        if (amq_server_config_debug_route (amq_server_config))
            smt_log_print (amq_broker->debug_log,
                "X: deliver  queue=%s (direct)",  queue->key);
    }
}
static int
s_compile_binding (
    amq_exchange_headers_t  *self,
    amq_binding_t *binding,
    char          *index_key)
{
    int
        rc = 0;                         //  Return code
    amq_index_t
        *index;                         //  Index reference from index_hash

    if (amq_server_config_debug_route (amq_server_config))
        smt_log_print (amq_broker->debug_log,
            "X: index    %s: request=%s binding=%d",
                self->exchange->name, index_key, binding->index);

    if (binding->index < IPR_BITS_SIZE_BITS) {
        index = amq_index_hash_search (self->index_hash, index_key);
        if (index == NULL)
            index = amq_index_new (self->index_hash, index_key, self->index_array);

        //  Cross-reference binding and index
        ipr_bits_set (index->bindset, binding->index);
        ipr_looseref_queue (binding->index_list, index);

        //  We count the number of fields to allow AND matching
        binding->field_count++;
        amq_index_unlink (&index);
    }
    else {
        smt_log_print (amq_broker->alert_log,
            "E: too many bindings, limit is %d", IPR_BITS_SIZE_BITS);
        rc = 1;
    }
    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_new

    Type: Component method
    Creates and initialises a new amq_exchange_headers_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_exchange_headers_t *
    amq_exchange_headers_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_exchange_t * exchange           //  Parent exchange
)
{
    amq_exchange_headers_t *
        self = NULL;                    //  Object reference

    self = amq_exchange_headers_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_EXCHANGE_HEADERS_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_exchange_headers_show_);
#endif

//
self->exchange = exchange;

self->index_hash  = amq_index_hash_new  ();
self->index_array = amq_index_array_new ();
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_headers_annihilate (
    amq_exchange_headers_t * ( * self_p )  //  Reference to object reference
)
{

    amq_exchange_headers_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

AMQ_EXCHANGE_HEADERS_ASSERT_SANE (self);

amq_index_hash_destroy  (&self->index_hash);
amq_index_array_destroy (&self->index_array);

}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_compile

    Type: Component method
    Compiles the binding for the exchange, returns 1 if the binding was
    invalid.  Note that if an exchange uses a routing key at all, it must be
    mandatory in all binds.
    Compiles a headers binding. The arguments hold a set of fields
    to match on.  Each field with a non-empty value is matched for
    that field/value pair.  Each field with an empty value is matched
    for presence only (matching any value in the message).  Fields
    prefixed by x- are not matched on.  The field called "x-match"
    can have the value "all" or "any", meaning logical AND or OR of
    all matches.  It defaults to "all".
    -------------------------------------------------------------------------
 */

int
    amq_exchange_headers_compile (
    void * self_v,                      //  The exchange cast as a void *
    amq_binding_t * binding,            //  Binding to compile
    amq_server_channel_t * channel      //  Channel for errors
)
{
amq_exchange_headers_t
    *self = self_v;
asl_field_list_t
    *fields;                        //  Decoded arguments
asl_field_t
    *field;                         //  Field on which to match
icl_shortstr_t
    index_key;                      //  Index key to match on
    int
        rc = 0;                         //  Return code

AMQ_EXCHANGE_HEADERS_ASSERT_SANE (self);
    //
#   define FIELD_NAME_MAX   30          //  Arbitrary limit to get
#   define FIELD_VALUE_MAX  30          //    name=value into shortstr
#   define MATCH_ALL_KEY    "*"         //  Match all messages

    fields = asl_field_list_new (binding->arguments);
    if (fields) {
        binding->match_all = TRUE;      //  By default, want full match
        field = asl_field_list_first (fields);
        while (field) {
            if ((field->name [0] == 'X' 
              || field->name [0] == 'x') && field->name [1] == '-') {
                if (streq (field->name, "x-match") 
                 || streq (field->name, "X-match")) {
                    if (streq (asl_field_string (field), "any")) {
                        if (amq_server_config_debug_route (amq_server_config))
                            smt_log_print (amq_broker->debug_log,
                                "X: select   %s: match=any", self->exchange->name, index_key);
                        binding->match_all = FALSE;
                    }
                }
                else
                    smt_log_print (amq_broker->alert_log,
                        "W: unknown field '%s' in bind arguments", field->name);
            }
            else {
                //  Index key is field name, or field name and value
                //  We truncate name and value to sensible limits

                icl_shortstr_ncpy (index_key, field->name, FIELD_NAME_MAX);
                if (field->type != 'V') {
                    icl_shortstr_cat  (index_key, "=");
                    icl_shortstr_ncat (index_key,
                        asl_field_string (field), FIELD_VALUE_MAX);
                }
                rc = s_compile_binding (self, binding, index_key);
            }
            field = asl_field_list_next (&field);
        }
        asl_field_list_destroy (&fields);

        //  If zero fields specified, match on all messages
        if (binding->field_count == 0)
            rc = s_compile_binding (self, binding, MATCH_ALL_KEY);

        if (rc)
            amq_server_connection_error (
                channel? channel->connection: NULL,
                ASL_COMMAND_INVALID,
                "Queue binding failed, too many bindings",
                AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_BIND);
    }
    else {
        rc = 1;
        amq_server_connection_error (
            channel? channel->connection: NULL,
            ASL_COMMAND_INVALID,
            "Invalid binding arguments",
            AMQ_SERVER_QUEUE, AMQ_SERVER_QUEUE_BIND);
    }

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_publish

    Type: Component method
    Routes one message through the exchange.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_headers_publish (
    void * self_v,                      //  The exchange cast as a void *
    amq_server_channel_t * channel,     //  Channel for reply
    amq_content_basic_t * content,      //  Content to publish
    int group,                          //  User group, from connection
    Bool immediate                      //  Send immediately or return?
)
{
amq_exchange_headers_t
    *self = self_v;
char
    *routing_key,
    *message_id,
    *sender_id;
int
    delivered = 0;                  //  Number of message deliveries
amq_server_connection_t
    *connection;
size_t
    set_size,                       //  Size of queue publish set
    set_index;                      //  Index into queue publish set
amq_queue_t
    *last_queue = NULL;             //  Last queue we published to
amq_lease_t
    *lease;                         //  Queue lease, if any
asl_field_list_t
    *headers = NULL;                //  Decoded header fields
icl_shortstr_t
    index_key;                      //  Index key to match on
amq_hitset_t
    *hitset;                        //  Match hitset
asl_field_t
    *field;                         //  Field on which to match
amq_binding_t
    *binding;                       //  Binding object
int
    binding_nbr;                    //  Binding number, 1..n from bindset
    int
        rc = 0;                         //  Return code

AMQ_EXCHANGE_HEADERS_ASSERT_SANE (self);

routing_key = content->routing_key;
message_id  = content->message_id;
sender_id   = content->sender_id;
if (amq_server_config_debug_route (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "X: publish  %s: routing_key=%s", self->exchange->name, routing_key);

//  Grab reference to connection
connection = channel?
    amq_server_connection_link (channel->connection): NULL;

//  Collect all queues to publish to into queue_set, initially empty
set_size = 0;
//

//
headers = asl_field_list_new (content->headers);
if (headers) {
    hitset = amq_hitset_new ();
    field = asl_field_list_first (headers);
    while (field) {
        //  Match on field presence
        icl_shortstr_ncpy (index_key, field->name, FIELD_NAME_MAX);
        amq_hitset_collect (hitset, self->index_hash, index_key);

        //  Match on field value
        icl_shortstr_cat  (index_key, "=");
        icl_shortstr_ncat (index_key, asl_field_string (field), FIELD_VALUE_MAX);
        amq_hitset_collect (hitset, self->index_hash, index_key);

        field = asl_field_list_next (&field);
    }
    //  Add "match all" bindings
    amq_hitset_collect (hitset, self->index_hash, MATCH_ALL_KEY);

    //  The hitset now represents all matching bindings
    for (binding_nbr = hitset->lowest; binding_nbr <= hitset->highest; binding_nbr++) {
        binding = self->exchange->binding_index->data [binding_nbr];
        if (binding) {
            if ((binding->match_all && hitset->hit_count [binding_nbr] == binding->field_count)
            || (!binding->match_all && hitset->hit_count [binding_nbr] > 0)) {
                set_size = amq_binding_collect (binding, self->exchange->queue_set, set_size);
                if (amq_server_config_debug_route (amq_server_config))
                    smt_log_print (amq_broker->debug_log,
                        "X: have_hit %s: match=%s hits=%d binding=%d",
                        self->exchange->name,
                        binding->match_all? "all": "any",
                        hitset->hit_count [binding_nbr], binding_nbr);
            }
        }
    }
    amq_hitset_destroy (&hitset);
    asl_field_list_destroy (&headers);
}
//  The queue_set is processed in the footer of this function in 
//  amq_exchange_base.icl, the same way for all exchanges
//  Sort the queue set and then publish to all unique queues
if (set_size > 1)
    qsort (self->exchange->queue_set, set_size, sizeof (void *), s_compare_queue);

for (set_index = 0; set_index < set_size; set_index++) {
    if (self->exchange->queue_set [set_index] != last_queue) {
        last_queue = self->exchange->queue_set [set_index];
        lease = amq_lease_link (last_queue->lease);
        if (lease && lease->thread && last_queue->feed_on) {
            if (last_queue->feed_no_local
            && streq (content->producer_id, lease->connection_id)) {
                if (amq_server_config_debug_route (amq_server_config))
                    smt_log_print (amq_broker->debug_log, "X: discard  queue=%s (direct, no-local, undeliverable)",
                        last_queue->key);
            }
            else
                s_direct_deliver (last_queue, content, lease);
        }
        else {
            amq_queue_publish (last_queue, channel, content, immediate);
            if (amq_server_config_debug_route (amq_server_config))
                smt_log_print (amq_broker->debug_log, "X: deliver  queue=%s",
                    last_queue->key);
        }
        amq_lease_unlink (&lease);
        delivered++;
    }
}
amq_server_connection_unlink (&connection);
rc = delivered;                     //  Return number of deliveries

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_unbind

    Type: Component method
    Unbinds the binding for the exchange.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_headers_unbind (
    void * self_v,                      //  The exchange cast as a void *
    amq_binding_t * binding             //  Binding to unbind
)
{
amq_exchange_headers_t
    *self = self_v;
    int
        rc = 0;                         //  Return code

AMQ_EXCHANGE_HEADERS_ASSERT_SANE (self);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_headers_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_headers_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_headers_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_exchange_headers_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_exchange_headers file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_destroy

    Type: Component method
    Destroys a amq_exchange_headers_t object. Takes the address of a
    amq_exchange_headers_t reference (a pointer to a pointer) and nullifies the
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
    amq_exchange_headers_destroy_ (
    amq_exchange_headers_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_exchange_headers_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_exchange_headers_annihilate (self_p);
    amq_exchange_headers_free ((amq_exchange_headers_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_exchange_headers_t *
    amq_exchange_headers_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_exchange_headers_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_exchange_headers_cache_initialise ();

self = (amq_exchange_headers_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_exchange_headers_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_free

    Type: Component method
    Freess a amq_exchange_headers_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_headers_free (
    amq_exchange_headers_t * self       //  Object reference
)
{


if (self) {

        memset (&self->object_tag, 0, sizeof (amq_exchange_headers_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_exchange_headers_t));
        self->object_tag = AMQ_EXCHANGE_HEADERS_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_headers_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_exchange_headers_t));
icl_system_register (amq_exchange_headers_cache_purge, amq_exchange_headers_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_headers_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_headers_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_exchange_headers_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_exchange_headers_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_exchange_headers_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_headers_new_in_scope_ (
    amq_exchange_headers_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_exchange_t * exchange           //  Parent exchange
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_exchange_headers_new_ (file,line,exchange);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_exchange_headers_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_exchange_headers_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_exchange_headers_component  = "amq_exchange_headers ";
char *EMBED__amq_exchange_headers_version  = "1.0 ";
char *EMBED__amq_exchange_headers_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_exchange_headers_filename  = "amq_exchange_headers.icl ";
char *EMBED__amq_exchange_headers_builddate  = "2010/10/06 ";
char *EMBED__amq_exchange_headers_version_end  = "VeRsIoNeNd:ipc";

