/*---------------------------------------------------------------------------
    amq_exchange_topic.c - amq_exchange_topic component

This class implements the topic exchange, which routes messages
based on the routing_key matched against a wild-card topic tree
specification.  Max. topics per exchange is limited by size of
amq_index_hash table.
    Generated from amq_exchange_topic.icl by icl_gen using GSL/4.
    
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
#include "amq_exchange_topic.h"         //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_exchange_topic_t

//  Shorthands for class methods                                               

#define self_new            amq_exchange_topic_new
#define self_annihilate     amq_exchange_topic_annihilate
#define self_compile        amq_exchange_topic_compile
#define self_publish        amq_exchange_topic_publish
#define self_unbind         amq_exchange_topic_unbind
#define self_selftest       amq_exchange_topic_selftest
#define self_terminate      amq_exchange_topic_terminate
#define self_show           amq_exchange_topic_show
#define self_destroy        amq_exchange_topic_destroy
#define self_alloc          amq_exchange_topic_alloc
#define self_free           amq_exchange_topic_free
#define self_cache_initialise  amq_exchange_topic_cache_initialise
#define self_cache_purge    amq_exchange_topic_cache_purge
#define self_cache_terminate  amq_exchange_topic_cache_terminate
#define self_animate        amq_exchange_topic_animate
#define self_new_in_scope   amq_exchange_topic_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_NEW))
static icl_stats_t *s_amq_exchange_topic_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_DESTROY))
static icl_stats_t *s_amq_exchange_topic_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_COMPILE))
static icl_stats_t *s_amq_exchange_topic_compile_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_PUBLISH))
static icl_stats_t *s_amq_exchange_topic_publish_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_UNBIND))
static icl_stats_t *s_amq_exchange_topic_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_SELFTEST))
static icl_stats_t *s_amq_exchange_topic_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_TERMINATE))
static icl_stats_t *s_amq_exchange_topic_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_SHOW))
static icl_stats_t *s_amq_exchange_topic_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_DESTROY_PUBLIC))
static icl_stats_t *s_amq_exchange_topic_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_ALLOC))
static icl_stats_t *s_amq_exchange_topic_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_FREE))
static icl_stats_t *s_amq_exchange_topic_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_CACHE_INITIALISE))
static icl_stats_t *s_amq_exchange_topic_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_CACHE_PURGE))
static icl_stats_t *s_amq_exchange_topic_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_CACHE_TERMINATE))
static icl_stats_t *s_amq_exchange_topic_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_ANIMATE))
static icl_stats_t *s_amq_exchange_topic_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_NEW_IN_SCOPE))
static icl_stats_t *s_amq_exchange_topic_new_in_scope_stats = NULL;
#endif
static void
    amq_exchange_topic_annihilate (
amq_exchange_topic_t * ( * self_p )     //  Reference to object reference
);

#define amq_exchange_topic_alloc()      amq_exchange_topic_alloc_ (__FILE__, __LINE__)
static amq_exchange_topic_t *
    amq_exchange_topic_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_exchange_topic_free (
amq_exchange_topic_t * self             //  Object reference
);

static void
    amq_exchange_topic_cache_initialise (
void);

static void
    amq_exchange_topic_cache_purge (
void);

static void
    amq_exchange_topic_cache_terminate (
void);

Bool
    amq_exchange_topic_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static int
    s_compare_queue (const void *queue1, const void *queue2);
static void
    s_direct_deliver (amq_queue_t *queue, amq_content_basic_t *content);
//  Topic names observe the Perl "word" syntax, i.e. letters,
//  digits, and underscores.  The MULTIPLE wildcard matches an
//  empty topic, expressed as " ".
#define S_WILDCARD_SINGLE     "`w+"                     //  *
#define S_WILDCARD_MULTIPLE   "( |(?:`w+(?:`.`w+)*))"   //  #
static Bool
    s_topic_to_regexp (char *index_regexp, char *regexp);
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
s_direct_deliver (amq_queue_t *queue, amq_content_basic_t *content)
{
    qbyte
        queue_size = 0;

    queue->contents_in++;
    queue->traffic_in += content->body_size;
    queue_size = icl_atomic_inc32 ((volatile qbyte *) &(queue->lease->pending));
    //  Track highest known direct queue size for monitoring
    if (amq_broker->direct_high < queue_size)
        amq_broker->direct_high = queue_size;

    //  This code mirrors code in amq_queue_basic.icl
    //  Check warning limit
    if (queue->warn_limit && queue_size >= queue->warn_limit && !queue->warned) {
        smt_log_print (amq_broker->alert_log,
            "I: queue=%s hit %d messages: no action (%s, %s, %s, %s)", 
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
        icl_atomic_dec32 ((volatile qbyte *) &(queue->lease->pending));
        queue->drop_count++;
        content = NULL;
    }
    else
    if (queue_size == 0) {
        //  Reset warning flags if queue becomes empty
        queue->warned  = FALSE;
        queue->dropped = FALSE;
    }
    if (content) {
        //  Update queue statistics
        queue->contents_out++;
        queue->traffic_out += content->body_size;

        amq_server_agent_direct_out (queue->lease->thread, content, 0);
        icl_atomic_inc32 ((volatile qbyte *) &(amq_broker->direct_fed));
        if (amq_server_config_debug_route (amq_server_config))
            smt_log_print (amq_broker->debug_log,
                "X: deliver  queue=%s (direct)",  queue->key);
    }
}
/*    Converts a index routing_key name into a regular expression. The index
      name can contain wildcards that index part or all of a index name tree.
      '*' in the routing_key name means wildcard a single level of indexes.
      '#' in the routing_key name means wildcard zero or more levels.
      index levels are separated by '.'.  regexp must be an icl_shortstr_t.
      Returns true if topic is a wildcard, false if it's a simple topic name.
 */
static Bool
s_topic_to_regexp (char *topic, char *regexp)
{
    char
        *from_ptr,
        *to_ptr;
    Bool
        is_wildcard = FALSE;

    /*  We want a regexp starting with ^, ending with $, and with the
        * and # index wildcards replaced by appropriate regexp chars.
        We may allow full RE indexing on index names at a later stage.
     */
    to_ptr = regexp;
    *to_ptr++ = '^';                    //  index start of index name
    for (from_ptr = topic; *from_ptr; from_ptr++) {
        if (*from_ptr == '.') {
            *to_ptr++ = '`';
            *to_ptr++ = '.';
        }
        else
        if (*from_ptr == '*') {
            is_wildcard = TRUE;
            strcpy (to_ptr, S_WILDCARD_SINGLE);
            to_ptr += strlen (S_WILDCARD_SINGLE);
        }
        else
        if (*from_ptr == '#') {
            is_wildcard = TRUE;
            strcpy (to_ptr, S_WILDCARD_MULTIPLE);
            to_ptr += strlen (S_WILDCARD_MULTIPLE);
        }
        else
        if (isprint (*from_ptr))
            *to_ptr++ = *from_ptr;
    }
    *to_ptr++ = '$';                    //  index end of index name
    *to_ptr++ = 0;
    return (is_wildcard);
}
/*  -------------------------------------------------------------------------
    amq_exchange_topic_new

    Type: Component method
    Creates and initialises a new amq_exchange_topic_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_exchange_topic_t *
    amq_exchange_topic_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_exchange_t * exchange           //  Parent exchange
)
{
    amq_exchange_topic_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_NEW))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, exchange);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_NEW))
    icl_trace_record (NULL, amq_exchange_topic_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_NEW))
    icl_stats_inc ("amq_exchange_topic_new", &s_amq_exchange_topic_new_stats);
#endif

    self = amq_exchange_topic_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_EXCHANGE_TOPIC_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_exchange_topic_show_);
#endif

//
self->exchange = exchange;

self->index_hash  = amq_index_hash_new  ();
self->index_array = amq_index_array_new ();
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_NEW))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_NEW))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, exchange, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_exchange_topic_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_topic_annihilate (
    amq_exchange_topic_t * ( * self_p )  //  Reference to object reference
)
{

    amq_exchange_topic_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_DESTROY))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_DESTROY))
    icl_trace_record (NULL, amq_exchange_topic_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_DESTROY))
    icl_stats_inc ("amq_exchange_topic_annihilate", &s_amq_exchange_topic_annihilate_stats);
#endif

AMQ_EXCHANGE_TOPIC_ASSERT_SANE (self);

amq_index_hash_destroy  (&self->index_hash);
amq_index_array_destroy (&self->index_array);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_DESTROY))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_DESTROY))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_destroy_finish"
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
    amq_exchange_topic_compile

    Type: Component method
    Compiles the binding for the exchange, returns 1 if the binding was
    invalid.  Note that if an exchange uses a routing key at all, it must be
    mandatory in all binds.
    Compiles a topic binding, based on the routing key, which is a
    wildcard pattern that conforms to the AMQP specifications for topic
    matching.  This means:

      - multiple levels separated by '.', e.g. "nasdaq.ibm.usd"
      - single level wildcard represented by '*', e.g. "nasdaq.*.usd"
      - multiple level wildcard represented by '#', e.g. "#.usd"

    An empty routing key is valid, and is treated as matching nothing.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_topic_compile (
    void * self_v,                      //  The exchange cast as a void *
    amq_binding_t * binding,            //  Binding to compile
    amq_server_channel_t * channel      //  Channel for errors
)
{
amq_exchange_topic_t
    *self = self_v;
ipr_regexp_t
    *regexp;                        //  Regular expression object
uint
    index_nbr;                      //  Index number in self->index_array
amq_index_t
    *index;                         //  Index reference from index_array
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_COMPILE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_compile_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" binding=\"%pp\""
" channel=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, binding, channel);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_COMPILE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_COMPILE))
    icl_stats_inc ("amq_exchange_topic_compile", &s_amq_exchange_topic_compile_stats);
#endif

AMQ_EXCHANGE_TOPIC_ASSERT_SANE (self);
//
//  Turn the routing_key string into a nice regexp
binding->is_wildcard = s_topic_to_regexp (binding->routing_key, binding->regexp);

if (binding->is_wildcard) {
    if (amq_server_config_debug_route (amq_server_config))
        smt_log_print (amq_broker->debug_log,
            "X: compile  %s: wildcard=%s", self->exchange->name, binding->routing_key);

    //  We scan all indices to see which ones match our regexp
    regexp = ipr_regexp_new (binding->regexp);
    for (index_nbr = 0; index_nbr < self->index_array->bound; index_nbr++) {
        index = amq_index_array_fetch (self->index_array, index_nbr);
        if (index) {
            if (ipr_regexp_match (regexp, index->key, NULL)) {
                if (amq_server_config_debug_route (amq_server_config))
                    smt_log_print (amq_broker->debug_log,
                        "X: index    %s: wildcard=%s routing_key=%s",
                        self->exchange->name, binding->routing_key, index->key);

                //  Cross-reference binding and index
                ipr_bits_set (index->bindset, binding->index);
                ipr_looseref_queue (binding->index_list, index);
            }
            amq_index_unlink (&index);
        }
    }
    ipr_regexp_destroy (&regexp);
}
else {
    if (amq_server_config_debug_route (amq_server_config))
        smt_log_print (amq_broker->debug_log,
            "X: compile  %s: topic=%s", self->exchange->name, binding->routing_key);

    //  Find index that matches our topic name as-is
    index = amq_index_hash_search (self->index_hash, binding->routing_key);
    if (index == NULL) {
        if (amq_server_config_debug_route (amq_server_config))
            smt_log_print (amq_broker->debug_log,
                "X: newtopic %s: topic=%s", self->exchange->name, binding->routing_key);

        index = amq_index_new (self->index_hash, binding->routing_key, self->index_array);
    }
    //  Cross-reference binding and index
    ipr_bits_set (index->bindset, binding->index);
    ipr_looseref_queue (binding->index_list, index);
    amq_index_unlink (&index);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_COMPILE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_COMPILE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_compile_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" binding=\"%pp\""
" channel=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, binding, channel, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_topic_publish

    Type: Component method
    Routes one message through the exchange.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_topic_publish (
    void * self_v,                      //  The exchange cast as a void *
    amq_server_channel_t * channel,     //  Channel for reply
    amq_content_basic_t * content,      //  Content to publish
    int group,                          //  User group, from connection
    Bool immediate                      //  Send immediately or return?
)
{
amq_exchange_topic_t
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
amq_index_t
    *index;                         //  Index object
amq_binding_t
    *binding;                       //  Auxiliary variable
ipr_regexp_t
    *regexp;                        //  Regular expression object
int
    binding_nbr;                    //  Binding number, 1..n from bindset
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_PUBLISH))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_publish_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" channel=\"%pp\""
" content=\"%pp\""
" group=\"%i\""
" immediate=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, channel, content, group, immediate);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_PUBLISH))
    icl_trace_record (NULL, amq_exchange_topic_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_PUBLISH))
    icl_stats_inc ("amq_exchange_topic_publish", &s_amq_exchange_topic_publish_stats);
#endif

AMQ_EXCHANGE_TOPIC_ASSERT_SANE (self);

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
//  Check if routing_key is already indexed, else reindex bindings on it
//  If the routing key is null, use a single space " " instead so that we
//  can match empty routing keys with wildcards.
if (strnull (routing_key))
    routing_key = " ";              //  Not a shortstr but a char *...

index = amq_index_hash_search (self->index_hash, routing_key);
if (index == NULL) {
    if (amq_server_config_debug_route (amq_server_config))
        smt_log_print (amq_broker->debug_log,
            "X: newtopic %s: topic=%s", self->exchange->name, routing_key);

    //  Create new index and recompile all bindings for it
    index = amq_index_new (self->index_hash, routing_key, self->index_array);
    binding = amq_binding_list_first (self->exchange->binding_list);

    while (binding && binding->is_wildcard) {
        regexp = ipr_regexp_new (binding->regexp);
        if (ipr_regexp_match (regexp, routing_key, NULL)) {
            if (amq_server_config_debug_route (amq_server_config))
                smt_log_print (amq_broker->debug_log,
                    "X: index    %s: routing_key=%s wildcard=%s",
                    self->exchange->name, routing_key, binding->routing_key);

            //  Cross-reference binding and index
            ipr_bits_set (index->bindset, binding->index);
            ipr_looseref_queue (binding->index_list, index);
        }
        ipr_regexp_destroy (&regexp);
        binding = amq_binding_list_next (&binding);
    }
    if (binding)                    //  If we stopped before the end of the list
        amq_binding_unlink (&binding);
}
if (amq_server_config_debug_route (amq_server_config))
    smt_log_print (amq_broker->debug_log,
        "X: route    %s: routing_key=%s", self->exchange->name, routing_key);

assert (index);

//  Collect all queues to publish to
binding_nbr = ipr_bits_first (index->bindset);
while (binding_nbr >= 0) {
    binding = self->exchange->binding_index->data [binding_nbr];
    assert (binding);
    if (amq_server_config_debug_route (amq_server_config))
        smt_log_print (amq_broker->debug_log,
            "X: hit      %s: wildcard=%s", self->exchange->name, binding->routing_key);
    set_size = amq_binding_collect (binding, self->exchange->queue_set, set_size);
    binding_nbr = ipr_bits_next (index->bindset, binding_nbr);
}
amq_index_unlink (&index);
//  The queue_set is processed in the footer of this function in 
//  amq_exchange_base.icl, the same way for all exchanges
//  Sort the queue set and then publish to all unique queues
if (set_size > 1)
    qsort (self->exchange->queue_set, set_size, sizeof (void *), s_compare_queue);

for (set_index = 0; set_index < set_size; set_index++) {
    if (self->exchange->queue_set [set_index] != last_queue) {
        last_queue = self->exchange->queue_set [set_index];
        if (last_queue->lease && last_queue->feed_on && last_queue->lease->thread) {
            if (last_queue->feed_no_local
            && streq (content->producer_id, last_queue->lease->connection_id)) {
                if (amq_server_config_debug_route (amq_server_config))
                    smt_log_print (amq_broker->debug_log, "X: discard  queue=%s (direct, no-local, undeliverable)",
                        last_queue->key);
            }
            else
                s_direct_deliver (last_queue, content);
        }
        else {
            amq_queue_publish (last_queue, channel, content, immediate);
            if (amq_server_config_debug_route (amq_server_config))
                smt_log_print (amq_broker->debug_log, "X: deliver  queue=%s",
                    last_queue->key);
        }
        delivered++;
    }
}
amq_server_connection_unlink (&connection);
rc = delivered;                     //  Return number of deliveries
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_PUBLISH))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_PUBLISH))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_publish_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" channel=\"%pp\""
" content=\"%pp\""
" group=\"%i\""
" immediate=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, channel, content, group, immediate, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_topic_unbind

    Type: Component method
    Unbinds the binding for the exchange.
    -------------------------------------------------------------------------
 */

int
    amq_exchange_topic_unbind (
    void * self_v,                      //  The exchange cast as a void *
    amq_binding_t * binding             //  Binding to unbind
)
{
amq_exchange_topic_t
    *self = self_v;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_UNBIND))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_unbind_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" binding=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, binding);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_UNBIND))
    icl_trace_record (NULL, amq_exchange_topic_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_UNBIND))
    icl_stats_inc ("amq_exchange_topic_unbind", &s_amq_exchange_topic_unbind_stats);
#endif

AMQ_EXCHANGE_TOPIC_ASSERT_SANE (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_UNBIND))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_UNBIND))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_unbind_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" binding=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, binding, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_exchange_topic_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_topic_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_SELFTEST))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_SELFTEST))
    icl_trace_record (NULL, amq_exchange_topic_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_SELFTEST))
    icl_stats_inc ("amq_exchange_topic_selftest", &s_amq_exchange_topic_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_SELFTEST))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_SELFTEST))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_selftest_finish"
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
    amq_exchange_topic_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_topic_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_TERMINATE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_TERMINATE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_TERMINATE))
    icl_stats_inc ("amq_exchange_topic_terminate", &s_amq_exchange_topic_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_TERMINATE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_TERMINATE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_terminate_finish"
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
    amq_exchange_topic_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_topic_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_exchange_topic_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_SHOW))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_SHOW))
    icl_trace_record (NULL, amq_exchange_topic_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_SHOW))
    icl_stats_inc ("amq_exchange_topic_show", &s_amq_exchange_topic_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_exchange_topic file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_SHOW))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_SHOW))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_show_finish"
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
    amq_exchange_topic_destroy

    Type: Component method
    Destroys a amq_exchange_topic_t object. Takes the address of a
    amq_exchange_topic_t reference (a pointer to a pointer) and nullifies the
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
    amq_exchange_topic_destroy_ (
    amq_exchange_topic_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_exchange_topic_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_DESTROY_PUBLIC))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_exchange_topic_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_DESTROY_PUBLIC))
    icl_stats_inc ("amq_exchange_topic_destroy", &s_amq_exchange_topic_destroy_stats);
#endif

if (self) {
    amq_exchange_topic_annihilate (self_p);
    amq_exchange_topic_free ((amq_exchange_topic_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_DESTROY_PUBLIC))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_destroy_public_finish"
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
    amq_exchange_topic_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_exchange_topic_t *
    amq_exchange_topic_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_exchange_topic_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_ALLOC))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_ALLOC))
    icl_trace_record (NULL, amq_exchange_topic_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_ALLOC))
    icl_stats_inc ("amq_exchange_topic_alloc", &s_amq_exchange_topic_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_exchange_topic_cache_initialise ();

self = (amq_exchange_topic_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_exchange_topic_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_ALLOC))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_ALLOC))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_alloc_finish"
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
    amq_exchange_topic_free

    Type: Component method
    Freess a amq_exchange_topic_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_topic_free (
    amq_exchange_topic_t * self         //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_FREE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_FREE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_FREE))
    icl_stats_inc ("amq_exchange_topic_free", &s_amq_exchange_topic_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (amq_exchange_topic_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_exchange_topic_t));
        self->object_tag = AMQ_EXCHANGE_TOPIC_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_FREE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_FREE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_free_finish"
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
    amq_exchange_topic_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_topic_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_CACHE_INITIALISE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_CACHE_INITIALISE))
    icl_stats_inc ("amq_exchange_topic_cache_initialise", &s_amq_exchange_topic_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_exchange_topic_t));
icl_system_register (amq_exchange_topic_cache_purge, amq_exchange_topic_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_CACHE_INITIALISE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_cache_initialise_finish"
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
    amq_exchange_topic_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_topic_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_CACHE_PURGE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_CACHE_PURGE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_CACHE_PURGE))
    icl_stats_inc ("amq_exchange_topic_cache_purge", &s_amq_exchange_topic_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_CACHE_PURGE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_CACHE_PURGE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_cache_purge_finish"
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
    amq_exchange_topic_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_exchange_topic_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_CACHE_TERMINATE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_CACHE_TERMINATE))
    icl_stats_inc ("amq_exchange_topic_cache_terminate", &s_amq_exchange_topic_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_CACHE_TERMINATE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_cache_terminate_finish"
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
    amq_exchange_topic_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_exchange_topic_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_ANIMATE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_ANIMATE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_ANIMATE))
    icl_stats_inc ("amq_exchange_topic_animate", &s_amq_exchange_topic_animate_stats);
#endif

amq_exchange_topic_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_ANIMATE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_ANIMATE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_animate_finish"
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
    amq_exchange_topic_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_exchange_topic_new_in_scope_ (
    amq_exchange_topic_t * * self_p,    //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_exchange_t * exchange           //  Parent exchange
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_NEW_IN_SCOPE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, exchange);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC)  ||  defined (BASE_STATS_AMQ_EXCHANGE_TOPIC_NEW_IN_SCOPE))
    icl_stats_inc ("amq_exchange_topic_new_in_scope", &s_amq_exchange_topic_new_in_scope_stats);
#endif

*self_p = amq_exchange_topic_new_ (file,line,exchange);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_exchange_topic_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_exchange_topic_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_ANIMATE_AMQ_EXCHANGE_TOPIC_NEW_IN_SCOPE))
    if (amq_exchange_topic_animating)
        icl_console_print ("<amq_exchange_topic_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" exchange=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, exchange, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_NEW)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_DESTROY)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_COMPILE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_PUBLISH)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_UNBIND)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_SELFTEST)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_TERMINATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_SHOW)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_ALLOC)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_FREE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_ANIMATE)   || defined (BASE_TRACE_AMQ_EXCHANGE_TOPIC_NEW_IN_SCOPE) )
void
amq_exchange_topic_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "compile"; break;
        case 4: method_name = "publish"; break;
        case 5: method_name = "unbind"; break;
        case 6: method_name = "selftest"; break;
        case 7: method_name = "terminate"; break;
        case 8: method_name = "show"; break;
        case 9: method_name = "destroy public"; break;
        case 10: method_name = "alloc"; break;
        case 11: method_name = "free"; break;
        case 12: method_name = "cache initialise"; break;
        case 13: method_name = "cache purge"; break;
        case 14: method_name = "cache terminate"; break;
        case 15: method_name = "animate"; break;
        case 16: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_exchange_topic %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_exchange_topic_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_exchange_topic_component  = "amq_exchange_topic ";
char *amq_exchange_topic_version   = "1.0 ";
char *amq_exchange_topic_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_exchange_topic_filename  = "amq_exchange_topic.icl ";
char *amq_exchange_topic_builddate  = "2010/10/06 ";
char *amq_exchange_topic_version_end  = "VeRsIoNeNd:ipc";

