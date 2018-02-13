/*---------------------------------------------------------------------------
    amq_vhost.c - amq_vhost component

Defines a virtual host. This is a lock-free asynchronous class.
    Generated from amq_vhost.icl by smt_object_gen using GSL/4.
    
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
#include "amq_vhost.h"                  //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_vhost_t

//  Shorthands for class methods                                               

#define self_new            amq_vhost_new
#define self_annihilate     amq_vhost_annihilate
#define self_unbind_queue   amq_vhost_unbind_queue
#define self_selftest       amq_vhost_selftest
#define self_destroy        amq_vhost_destroy
#define self_unlink         amq_vhost_unlink
#define self_animate        amq_vhost_animate
#define self_free           amq_vhost_free
#define self_initialise     amq_vhost_initialise
#define self_terminate      amq_vhost_terminate
#define self_show           amq_vhost_show
#define self_alloc          amq_vhost_alloc
#define self_link           amq_vhost_link
#define self_cache_initialise  amq_vhost_cache_initialise
#define self_cache_purge    amq_vhost_cache_purge
#define self_cache_terminate  amq_vhost_cache_terminate
#define self_new_in_scope   amq_vhost_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_NEW))
static icl_stats_t *s_amq_vhost_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_DESTROY))
static icl_stats_t *s_amq_vhost_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_UNBIND_QUEUE))
static icl_stats_t *s_amq_vhost_unbind_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_SELFTEST))
static icl_stats_t *s_amq_vhost_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_DESTROY_PUBLIC))
static icl_stats_t *s_amq_vhost_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_UNLINK))
static icl_stats_t *s_amq_vhost_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_ANIMATE))
static icl_stats_t *s_amq_vhost_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_FREE))
static icl_stats_t *s_amq_vhost_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_INITIALISE))
static icl_stats_t *s_amq_vhost_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_TERMINATE))
static icl_stats_t *s_amq_vhost_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_SHOW))
static icl_stats_t *s_amq_vhost_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_ALLOC))
static icl_stats_t *s_amq_vhost_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_LINK))
static icl_stats_t *s_amq_vhost_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_CACHE_INITIALISE))
static icl_stats_t *s_amq_vhost_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_CACHE_PURGE))
static icl_stats_t *s_amq_vhost_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_CACHE_TERMINATE))
static icl_stats_t *s_amq_vhost_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_NEW_IN_SCOPE))
static icl_stats_t *s_amq_vhost_new_in_scope_stats = NULL;
#endif
#define amq_vhost_annihilate(self)      amq_vhost_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_vhost_annihilate_ (
amq_vhost_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_vhost_initialise (
void);

#define amq_vhost_alloc()               amq_vhost_alloc_ (__FILE__, __LINE__)
static amq_vhost_t *
    amq_vhost_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_vhost_cache_initialise (
void);

static void
    amq_vhost_cache_purge (
void);

static void
    amq_vhost_cache_terminate (
void);

Bool
    amq_vhost_animating = TRUE;         //  Animation enabled by default
static Bool
    s_amq_vhost_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_vhost_mutex        = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


//  Prototypes for local functions
static void
    s_exchange_declare (
        amq_vhost_t *self, char *name, int type, 
        Bool default_exchange, Bool auto_federate);
/*  -------------------------------------------------------------------------
    amq_vhost_new

    Type: Component method
    Creates and initialises a new amq_vhost_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_vhost_t *
    amq_vhost_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_broker_t * broker,              //  Parent broker
    char * name                         //  Virtual host name
)
{
    amq_vhost_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_NEW))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" broker=\"%pp\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, broker, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_NEW))
    icl_trace_record (NULL, amq_vhost_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_NEW))
    icl_stats_inc ("amq_vhost_new", &s_amq_vhost_new_stats);
#endif

if (!s_amq_vhost_active)
    self_initialise ();
    self = amq_vhost_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_VHOST_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_vhost_show_);
#endif

self->thread = amq_vhost_agent_class_thread_new (self);
self->thread->animate = TRUE;

icl_shortstr_cpy (self->name, name);
smt_log_print (amq_broker->daily_log, "I: starting virtual host '%s'", self->name);

self->broker = broker;
self->config = amq_vhost_config_new ();

self->exchange_table = amq_exchange_table_new ();
self->exchange_list  = amq_exchange_by_vhost_new ();
self->queue_table    = amq_queue_table_new ();
self->queue_list     = amq_queue_by_vhost_new ();
self->shared_queues  = ipr_symbol_table_new ();

//  Automatic wiring schemes
s_exchange_declare (self, "$default$",   AMQ_EXCHANGE_DIRECT,  TRUE,  FALSE);
s_exchange_declare (self, "amq.fanout",  AMQ_EXCHANGE_FANOUT,  FALSE, FALSE);
s_exchange_declare (self, "amq.direct",  AMQ_EXCHANGE_DIRECT,  FALSE, FALSE);
s_exchange_declare (self, "amq.topic",   AMQ_EXCHANGE_TOPIC,   FALSE, FALSE);
s_exchange_declare (self, "amq.headers", AMQ_EXCHANGE_HEADERS, FALSE, FALSE);
s_exchange_declare (self, "amq.system",  AMQ_EXCHANGE_SYSTEM,  FALSE, FALSE);
s_exchange_declare (self, "amq.status",  AMQ_EXCHANGE_DIRECT,  FALSE, FALSE);

//  These exchanges are deprecated
s_exchange_declare (self, "amq.notify",  AMQ_EXCHANGE_TOPIC,   FALSE, FALSE);

//  These exchanges are automatically federated if --attach is specified
s_exchange_declare (self, "amq.service", AMQ_EXCHANGE_DIRECT,  FALSE, TRUE);
s_exchange_declare (self, "amq.data",    AMQ_EXCHANGE_TOPIC,   FALSE, TRUE);
s_exchange_declare (self, "amq.dataex",  AMQ_EXCHANGE_HEADERS, FALSE, TRUE);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_NEW))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_NEW))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" broker=\"%pp\""
" name=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, broker, name, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_vhost_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_vhost_annihilate_ (
    amq_vhost_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
    int
        history_last;
#endif

    amq_vhost_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_DESTROY))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_DESTROY))
    icl_trace_record (NULL, amq_vhost_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_DESTROY))
    icl_stats_inc ("amq_vhost_annihilate", &s_amq_vhost_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_VHOST_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_VHOST_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_VHOST_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_VHOST_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (amq_vhost_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_vhost agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_DESTROY))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_DESTROY))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_destroy_finish"
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
    amq_vhost_unbind_queue

    Type: Component method
    Accepts a amq_vhost_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Unbind a queue from the vhost.
    -------------------------------------------------------------------------
 */

int
    amq_vhost_unbind_queue (
    amq_vhost_t * self,                 //  Reference to object
    amq_queue_t * queue                 //  The queue to unbind
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_UNBIND_QUEUE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_unbind_queue_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_UNBIND_QUEUE))
    icl_trace_record (NULL, amq_vhost_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_UNBIND_QUEUE))
    icl_stats_inc ("amq_vhost_unbind_queue", &s_amq_vhost_unbind_queue_stats);
#endif

AMQ_VHOST_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_vhost_agent_unbind_queue (self->thread,queue)) {
        //icl_console_print ("Error sending 'unbind queue' method to amq_vhost agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_UNBIND_QUEUE))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_UNBIND_QUEUE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_unbind_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_vhost_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_vhost_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_SELFTEST))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_SELFTEST))
    icl_trace_record (NULL, amq_vhost_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_SELFTEST))
    icl_stats_inc ("amq_vhost_selftest", &s_amq_vhost_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_SELFTEST))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_SELFTEST))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_selftest_finish"
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
    amq_vhost_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_vhost_destroy_ (
    amq_vhost_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_vhost_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_DESTROY_PUBLIC))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_vhost_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_DESTROY_PUBLIC))
    icl_stats_inc ("amq_vhost_destroy", &s_amq_vhost_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = amq_vhost_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_vhost_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_DESTROY_PUBLIC))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_destroy_public_finish"
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
    amq_vhost_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_vhost_unlink_ (
    amq_vhost_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
    int
        history_last;
#endif
    amq_vhost_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_UNLINK))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_UNLINK))
    icl_trace_record (NULL, amq_vhost_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_UNLINK))
    icl_stats_inc ("amq_vhost_unlink", &s_amq_vhost_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_vhost object");
            amq_vhost_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_VHOST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_VHOST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_VHOST_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_VHOST_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_vhost_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_vhost_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_UNLINK))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_UNLINK))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_unlink_finish"
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
    amq_vhost_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_vhost_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_ANIMATE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_ANIMATE))
    icl_trace_record (NULL, amq_vhost_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_ANIMATE))
    icl_stats_inc ("amq_vhost_animate", &s_amq_vhost_animate_stats);
#endif

amq_vhost_animating = enabled;

amq_vhost_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_ANIMATE))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_ANIMATE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_animate_finish"
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
    amq_vhost_free

    Type: Component method
    Freess a amq_vhost_t object.
    -------------------------------------------------------------------------
 */

void
    amq_vhost_free_ (
    amq_vhost_t * self,                 //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_FREE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_FREE))
    icl_trace_record (NULL, amq_vhost_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_FREE))
    icl_stats_inc ("amq_vhost_free", &s_amq_vhost_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_VHOST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_VHOST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_VHOST_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_VHOST_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (amq_vhost_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_vhost_t));
        self->object_tag = AMQ_VHOST_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_FREE))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_FREE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_free_finish"
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
    amq_vhost_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_vhost_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_INITIALISE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_INITIALISE))
    icl_trace_record (NULL, amq_vhost_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_INITIALISE))
    icl_stats_inc ("amq_vhost_initialise", &s_amq_vhost_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_vhost_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_vhost_mutex)
            s_amq_vhost_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_vhost_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_vhost_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_vhost_agent_init ();
            s_amq_vhost_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_vhost_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_INITIALISE))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_INITIALISE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_initialise_finish"
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
    amq_vhost_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_vhost_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_TERMINATE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_TERMINATE))
    icl_trace_record (NULL, amq_vhost_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_TERMINATE))
    icl_stats_inc ("amq_vhost_terminate", &s_amq_vhost_terminate_stats);
#endif

if (s_amq_vhost_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_vhost_mutex);
#endif
        s_amq_vhost_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_TERMINATE))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_TERMINATE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_terminate_finish"
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
    amq_vhost_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_vhost_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_vhost_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_SHOW))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_SHOW))
    icl_trace_record (NULL, amq_vhost_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_SHOW))
    icl_stats_inc ("amq_vhost_show", &s_amq_vhost_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_vhost zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
    if (self->history_last > AMQ_VHOST_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_VHOST_HISTORY_LENGTH;
        self->history_last %= AMQ_VHOST_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_VHOST_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_vhost>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_SHOW))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_SHOW))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_show_finish"
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
    amq_vhost_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_vhost_t *
    amq_vhost_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_vhost_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_ALLOC))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_ALLOC))
    icl_trace_record (NULL, amq_vhost_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_ALLOC))
    icl_stats_inc ("amq_vhost_alloc", &s_amq_vhost_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_vhost_cache_initialise ();

self = (amq_vhost_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_vhost_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_ALLOC))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_ALLOC))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_alloc_finish"
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
    amq_vhost_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_vhost_t *
    amq_vhost_link_ (
    amq_vhost_t * self,                 //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_LINK))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_LINK))
    icl_trace_record (NULL, amq_vhost_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_LINK))
    icl_stats_inc ("amq_vhost_link", &s_amq_vhost_link_stats);
#endif

    if (self) {
        AMQ_VHOST_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_VHOST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_VHOST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_VHOST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_VHOST_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_VHOST_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_LINK))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_LINK))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_link_finish"
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
    amq_vhost_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_vhost_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_CACHE_INITIALISE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_vhost_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_CACHE_INITIALISE))
    icl_stats_inc ("amq_vhost_cache_initialise", &s_amq_vhost_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_vhost_t));
icl_system_register (amq_vhost_cache_purge, amq_vhost_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_CACHE_INITIALISE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_cache_initialise_finish"
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
    amq_vhost_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_vhost_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_CACHE_PURGE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_PURGE))
    icl_trace_record (NULL, amq_vhost_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_CACHE_PURGE))
    icl_stats_inc ("amq_vhost_cache_purge", &s_amq_vhost_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_PURGE))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_CACHE_PURGE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_cache_purge_finish"
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
    amq_vhost_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_vhost_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_CACHE_TERMINATE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_vhost_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_CACHE_TERMINATE))
    icl_stats_inc ("amq_vhost_cache_terminate", &s_amq_vhost_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_CACHE_TERMINATE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_cache_terminate_finish"
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
    amq_vhost_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_vhost_new_in_scope_ (
    amq_vhost_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_broker_t * broker,              //  Parent broker
    char * name                         //  Virtual host name
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_VHOST)  ||  defined (BASE_ANIMATE_AMQ_VHOST_NEW_IN_SCOPE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" broker=\"%pp\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, broker, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_vhost_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_VHOST)  ||  defined (BASE_STATS_AMQ_VHOST_NEW_IN_SCOPE))
    icl_stats_inc ("amq_vhost_new_in_scope", &s_amq_vhost_new_in_scope_stats);
#endif

*self_p = amq_vhost_new_ (file,line,broker,name);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_vhost_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_vhost_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_VHOST)   || defined (BASE_ANIMATE_AMQ_VHOST_NEW_IN_SCOPE))
    if (amq_vhost_animating)
        icl_console_print ("<amq_vhost_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" broker=\"%pp\""
" name=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, broker, name, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_VHOST)   || defined (BASE_TRACE_AMQ_VHOST_NEW)   || defined (BASE_TRACE_AMQ_VHOST_DESTROY)   || defined (BASE_TRACE_AMQ_VHOST_UNBIND_QUEUE)   || defined (BASE_TRACE_AMQ_VHOST_SELFTEST)   || defined (BASE_TRACE_AMQ_VHOST_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_VHOST_UNLINK)   || defined (BASE_TRACE_AMQ_VHOST_ANIMATE)   || defined (BASE_TRACE_AMQ_VHOST_FREE)   || defined (BASE_TRACE_AMQ_VHOST_INITIALISE)   || defined (BASE_TRACE_AMQ_VHOST_TERMINATE)   || defined (BASE_TRACE_AMQ_VHOST_SHOW)   || defined (BASE_TRACE_AMQ_VHOST_ALLOC)   || defined (BASE_TRACE_AMQ_VHOST_LINK)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_VHOST_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_VHOST_NEW_IN_SCOPE) )
void
amq_vhost_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "unbind queue"; break;
        case 4: method_name = "selftest"; break;
        case 5: method_name = "destroy public"; break;
        case 6: method_name = "unlink"; break;
        case 7: method_name = "animate"; break;
        case 8: method_name = "free"; break;
        case 9: method_name = "initialise"; break;
        case 10: method_name = "terminate"; break;
        case 11: method_name = "show"; break;
        case 12: method_name = "alloc"; break;
        case 13: method_name = "link"; break;
        case 14: method_name = "cache initialise"; break;
        case 15: method_name = "cache purge"; break;
        case 16: method_name = "cache terminate"; break;
        case 17: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_vhost %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

static void
s_exchange_declare (
    amq_vhost_t *self, 
    char *name, 
    int   type, 
    Bool  default_exchange, 
    Bool  auto_federate)
{
    amq_exchange_t
        *exchange;                      //  Predeclared exchange
    exchange = amq_exchange_new (
        self->exchange_table,
        self,                           //  Parent vhost
        type,                           //  Exchange type
        name,                           //  Exchange name
        default_exchange,               //  Internal?
        auto_federate);                 //  Federate automatically?
    assert (exchange);

    //  If this is the default exchange grab hold of it in our vhost
    if (default_exchange)
        self->default_exchange = exchange;
    else
        amq_exchange_unlink (&exchange);
}

//  Embed the version information in the resulting binary                      

char *amq_vhost_version_start      = "VeRsIoNsTaRt:ipc";
char *amq_vhost_component          = "amq_vhost ";
char *amq_vhost_version            = "1.0 ";
char *amq_vhost_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_vhost_filename           = "amq_vhost.icl ";
char *amq_vhost_builddate          = "2010/10/06 ";
char *amq_vhost_version_end        = "VeRsIoNeNd:ipc";

