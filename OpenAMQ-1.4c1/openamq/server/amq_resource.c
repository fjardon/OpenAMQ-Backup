/*---------------------------------------------------------------------------
    amq_resource.c - amq_resource component

    This module provides functions to work with RestMS resources.
    Generated from amq_resource.icl by icl_gen using GSL/4.
    
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
#include "amq_resource.h"               //  Definitions for our class

//  Shorthands for class methods

#define self_pipe_create    amq_resource_pipe_create
#define self_pipe_delete    amq_resource_pipe_delete
#define self_feed_create    amq_resource_feed_create
#define self_feed_delete    amq_resource_feed_delete
#define self_join_create    amq_resource_join_create
#define self_join_delete    amq_resource_join_delete
#define self_selftest       amq_resource_selftest
#define self_show_animation  amq_resource_show_animation

Bool
    amq_resource_animating = TRUE;      //  Animation enabled by default
/*  -------------------------------------------------------------------------
    amq_resource_pipe_create

    Type: Component method
    Creates the pipe, or asserts it exists as specified. Errors are logged.
    Pipes are implemented in the simplest fashion: each pipe has an exclusive
    queue with the same name, with a consumer with tag x:{pipe-name}.  When
    the front-end creates joins on the pipe, these are implemented as bindings
    that bring messages into the private queue.  This is for exchange-based
    feeds.  For queue-based feeds, the pipe is implemented as a consumer on
    the shared queue, with tag q:{pipe-name}.  These distinct tags are used by
    the front-end to route messages coming from the AMQP server into separate
    pipe queues for end-application delivery.
    -------------------------------------------------------------------------
 */

void
    amq_resource_pipe_create (
    char * pipe_type,                   //  Not documented
    char * pipe_name,                   //  Not documented
    amq_server_channel_t * channel      //  Not documented
)
{
amq_queue_t
    *queue = NULL;
amq_client_method_t
    *method;                        //  Consume method
amq_server_connection_t
    *connection;
icl_shortstr_t
    tag;                            //  Consumer tag x:{pipe-name}
char
    *error_text = NULL;             //  Error text, if any

//
if (strnull (pipe_name))
    error_text = "pipe_create: pipe name may not be empty";
else
if (strneq (pipe_type, "fifo"))
    error_text = "pipe_create: invalid pipe type";
else {
    queue = amq_queue_table_search (amq_broker->queue_table, pipe_name);
    if (queue && !queue->exclusive)
        error_text = "pipe_create: pipe queue exists but is not exclusive";
    else
    if (queue == NULL) {
        if (ipr_str_prefixed (pipe_name, "amq."))
            error_text = "pipe_create: new pipe name may not start with amq.";
        else {
            connection = amq_server_connection_link (channel->connection);
            if (connection) {
                //  Create private queue for pipe, and prepare queue for use
                queue = amq_queue_new (
                    connection,     //  Server connection
                    pipe_name,      //  Queue name
                    TRUE,           //  Exclusive queue?
                    TRUE,           //  Auto-delete?
                    NULL);          //  Arguments to declaration
                if (queue) {
                    //  Make automatic binding to default exchange
                    amq_exchange_bind_queue (
                        amq_broker->default_exchange, NULL, queue, pipe_name, NULL);

                    //  Add to connection's exclusive queue list
                    amq_server_connection_own_queue (connection, queue);

                    //  Consume from queue, using pipe name as consumer tag
                    icl_shortstr_fmt (tag, "x:%s", pipe_name);
                    method = amq_client_method_new_basic_consume (
                        0, pipe_name, tag, FALSE, FALSE, FALSE, TRUE, NULL);
                    amq_server_channel_consume (
                        channel, queue, (amq_server_method_t *) method);

                    amq_client_method_unlink (&method);
                }
                else
                    error_text = "pipe_create: ERROR: could not create queue";
            }
            amq_server_connection_unlink (&connection);
        }
    }
    amq_queue_unlink (&queue);
}

if (error_text)
    smt_log_print (amq_broker->alert_log, "W: %s", error_text);
}
/*  -------------------------------------------------------------------------
    amq_resource_pipe_delete

    Type: Component method
    Deletes a specified pipe.
    -------------------------------------------------------------------------
 */

void
    amq_resource_pipe_delete (
    char * pipe_name                    //  Not documented
)
{
amq_queue_t
    *queue = NULL;
char
    *error_text = NULL;             //  Error text, if any

//
if (strnull (pipe_name))
    error_text = "pipe_delete: pipe name may not be empty";
else
if (ipr_str_prefixed (pipe_name, "amq."))
    error_text = "pipe_delete: tried to delete a standard queue";
else {
    queue = amq_queue_table_search (amq_broker->queue_table, pipe_name);
    if (queue) {
        if (!queue->exclusive)
            error_text = "pipe_delete: tried to delete a shared queue";
        else
            amq_queue_self_destruct (queue);
        amq_queue_unlink (&queue);
    }
}
if (error_text)
    smt_log_print (amq_broker->alert_log, "W: %s", error_text);
}
/*  -------------------------------------------------------------------------
    amq_resource_feed_create

    Type: Component method
    Creates the feed, or asserts it exists as specified. Errors are
    logged.
    -------------------------------------------------------------------------
 */

void
    amq_resource_feed_create (
    char * feed_type,                   //  Not documented
    char * feed_name                    //  Not documented
)
{
amq_queue_t
    *queue = NULL;
amq_exchange_t
    *exchange = NULL;
Bool
    auto_delete;
int
    exchange_type;
char
    *error_text = NULL;             //  Error text, if any

//
queue = amq_queue_table_search (amq_broker->queue_table, feed_name);
auto_delete = streq (feed_type, "service");
exchange = amq_exchange_table_search (amq_broker->exchange_table, feed_name);
exchange_type = amq_exchange_type_lookup (feed_type);

if (strnull (feed_name))
    error_text = "feed_create: feed name may not be empty";
else
if (streq (feed_type, "service") || streq (feed_type, "rotator")) {
    if (exchange
    || (queue && queue->auto_delete != auto_delete))
        error_text = "feed_create: feed type does not match existing feed";
    else
    if (queue == NULL) {
        if (ipr_str_prefixed (feed_name, "amq."))
            error_text = "feed_create: new feed name may not start with amq.";
        else {
            queue = amq_queue_new (
                NULL,           //  Server connection
                feed_name,      //  Queue name
                FALSE,          //  Exclusive queue?
                auto_delete,    //  Auto-delete?
                NULL);          //  Arguments to declaration
            if (queue) {
                //  Bind to amq.direct
                amq_exchange_t
                    *exchange;
                exchange = amq_exchange_table_search (
                    amq_broker->exchange_table, "amq.direct");
                if (exchange) {
                    amq_exchange_bind_queue (
                        exchange, NULL, queue, queue->name, NULL);
                    amq_exchange_unlink (&exchange);
                }
                //  Now bind to default exchange
                amq_exchange_bind_queue (amq_broker->default_exchange,
                    NULL, queue, queue->name, NULL);
            }
            else
                error_text = "feed_create: ERROR: could not create queue";
        }
    }
}
else
if (exchange_type >= 0) {
    if (queue
    || (exchange && exchange->type != exchange_type))
        error_text = "feed_create: feed type does not match existing feed";
    else
    if (exchange == NULL) {
        if (ipr_str_prefixed (feed_name, "amq."))
            error_text = "feed_create: new feed name may not start with amq.";
        else {
            //  Create exchange as specified
            exchange = amq_exchange_new (exchange_type, feed_name, FALSE, FALSE);
            if (!exchange)
                error_text = "feed_create: ERROR: could not create exchange";
        }
    }
}
else
    error_text = "feed_create: invalid feed type";

amq_queue_unlink (&queue);
amq_exchange_unlink (&exchange);
if (error_text)
    smt_log_print (amq_broker->alert_log, "W: %s", error_text);
}
/*  -------------------------------------------------------------------------
    amq_resource_feed_delete

    Type: Component method
    Deletes a specified feed.
    -------------------------------------------------------------------------
 */

void
    amq_resource_feed_delete (
    char * feed_name                    //  Not documented
)
{
amq_exchange_t
    *exchange = NULL;
amq_queue_t
    *queue = NULL;
char
    *error_text = NULL;             //  Error text, if any

//
if (strnull (feed_name))
    error_text = "feed_delete: feed name may not be empty";
else
if (ipr_str_prefixed (feed_name, "amq."))
    error_text = "feed_delete: tried to delete a standard feed";
else {
    queue = amq_queue_table_search (amq_broker->queue_table, feed_name);
    if (queue) {
        if (queue->exclusive)
            error_text = "feed_delete: tried to delete a private queue";
        else
            amq_queue_self_destruct (queue);
        amq_queue_unlink (&queue);
    }
    else {
        exchange = amq_exchange_table_search (
            amq_broker->exchange_table, feed_name);
        if (exchange) {
            if (exchange->internal) {
                error_text = "feed_delete: tried to delete an internal exchange";
                amq_exchange_unlink (&exchange);
            }
            else
                amq_exchange_destroy (&exchange);
        }
    }
}
if (error_text)
    smt_log_print (amq_broker->alert_log, "W: %s", error_text);
}
/*  -------------------------------------------------------------------------
    amq_resource_join_create

    Type: Component method
    Creates the join, or asserts it exists as specified. Errors are logged.
    -------------------------------------------------------------------------
 */

void
    amq_resource_join_create (
    char * pipe_name,                   //  Not documented
    char * feed_name,                   //  Not documented
    char * address,                     //  Not documented
    amq_server_channel_t * channel      //  Not documented
)
{
amq_queue_t
    *queue = NULL;
amq_exchange_t
    *exchange = NULL;
char
    *error_text = NULL;             //  Error text, if any

//
if (strnull (feed_name))
    error_text = "join_create: feed name may not be empty";
else {
    queue = amq_queue_table_search (amq_broker->queue_table, feed_name);
    if (queue) {
        if (queue->exclusive)
            error_text = "join_delete: feed queue exists but is exclusive";
        else {
            icl_shortstr_t
                tag;                //  Consumer tag, q:{pipe-name}
            amq_client_method_t
                *method;            //  Consume method
            //  Create consumer, with pipe name as tag, on queue
            //  On shared queues, we do not implement the address string
            icl_shortstr_fmt (tag, "q:%s", pipe_name);
            method = amq_client_method_new_basic_consume (
                0, feed_name, tag, FALSE, FALSE, FALSE, TRUE, NULL);
            amq_server_channel_consume (
                channel, queue, (amq_server_method_t *) method);
            amq_client_method_unlink (&method);
        }
        amq_queue_unlink (&queue);
    }
    else {
        exchange = amq_exchange_table_search (amq_broker->exchange_table, feed_name);
        queue = amq_queue_table_search (amq_broker->queue_table, pipe_name);
        if (queue) {
            if (!queue->exclusive)
                error_text = "join_create: pipe queue exists but is not exclusive";
            else
            if (exchange)
                //  On exchanges, the address string is the routing key
                amq_exchange_bind_queue (exchange, channel, queue, address, NULL);
            else
                error_text = "join_create: feed exchange does not exist";
        }
        else
            error_text = "join_create: pipe queue does not exist";

        amq_queue_unlink (&queue);
        amq_exchange_unlink (&exchange);
    }
}
if (error_text)
    smt_log_print (amq_broker->alert_log, "W: %s", error_text);
}
/*  -------------------------------------------------------------------------
    amq_resource_join_delete

    Type: Component method
    Deletes a specified join.
    -------------------------------------------------------------------------
 */

void
    amq_resource_join_delete (
    char * pipe_name,                   //  Not documented
    char * feed_name,                   //  Not documented
    char * address,                     //  Not documented
    amq_server_channel_t * channel      //  Not documented
)
{
amq_queue_t
    *queue = NULL;
amq_exchange_t
    *exchange = NULL;
char
    *error_text = NULL;             //  Error text, if any

//
if (strnull (feed_name))
    error_text = "join_delete: feed name may not be empty";
else {
    queue = amq_queue_table_search (amq_broker->queue_table, feed_name);
    if (queue) {
        if (queue->exclusive)
            error_text = "join_delete: feed queue exists but is exclusive";
        else {
            icl_shortstr_t
                tag;                //  Consumer tag, q:{pipe-name}
            //  Cancel consumer, with pipe name as tag, on queue
            icl_shortstr_fmt (tag, "q:%s", pipe_name);
            amq_server_channel_cancel (channel, tag, TRUE, TRUE);
        }
        amq_queue_unlink (&queue);
    }
    else {
        exchange = amq_exchange_table_search (amq_broker->exchange_table, feed_name);
        queue = amq_queue_table_search (amq_broker->queue_table, pipe_name);
        if (exchange && queue) {
            if (!queue->exclusive)
                error_text = "join_delete: pipe queue exists but is not exclusive";
            else
                //  On exchanges, the address string is the routing key
                amq_exchange_unbind_queue (exchange, channel, queue, address, NULL);
        }
        amq_queue_unlink (&queue);
        amq_exchange_unlink (&exchange);
    }
}
if (error_text)
    smt_log_print (amq_broker->alert_log, "W: %s", error_text);
}
/*  -------------------------------------------------------------------------
    amq_resource_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_resource_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_resource_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_resource_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_resource_animating = enabled;
}
//  Embed the version information in the resulting binary

char *EMBED__amq_resource_version_start   = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_resource_component       = "amq_resource ";
char *EMBED__amq_resource_version         = "1.0 ";
char *EMBED__amq_resource_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_resource_filename        = "amq_resource.icl ";
char *EMBED__amq_resource_builddate       = "2010/10/06 ";
char *EMBED__amq_resource_version_end     = "VeRsIoNeNd:ipc";

