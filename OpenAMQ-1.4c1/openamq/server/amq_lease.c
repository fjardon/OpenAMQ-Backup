/*---------------------------------------------------------------------------
    amq_lease.c - amq_lease component

    Implements the Direct Protocol lease for the OpenAMQ server.
    Creates and resolves leases for sinks (exchanges) and feeds
    (queues).
    Generated from amq_lease.icl by icl_gen using GSL/4.
    
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
#include "amq_lease.h"                  //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_lease_t

//  Shorthands for class methods

#define self_new            amq_lease_new
#define self_annihilate     amq_lease_annihilate
#define self_search         amq_lease_search
#define self_acquire        amq_lease_acquire
#define self_sink           amq_lease_sink
#define self_initialise     amq_lease_initialise
#define self_terminate      amq_lease_terminate
#define self_selftest       amq_lease_selftest
#define self_remove_from_all_containers  amq_lease_remove_from_all_containers
#define self_show           amq_lease_show
#define self_destroy        amq_lease_destroy
#define self_alloc          amq_lease_alloc
#define self_free           amq_lease_free
#define self_link           amq_lease_link
#define self_unlink         amq_lease_unlink
#define self_cache_initialise  amq_lease_cache_initialise
#define self_cache_purge    amq_lease_cache_purge
#define self_cache_terminate  amq_lease_cache_terminate
#define self_show_animation  amq_lease_show_animation
#define self_new_in_scope   amq_lease_new_in_scope

#define amq_lease_annihilate(self)      amq_lease_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_lease_annihilate_ (
amq_lease_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_lease_initialise (
void);

static void
    amq_lease_terminate (
void);

#define amq_lease_alloc()               amq_lease_alloc_ (__FILE__, __LINE__)
static amq_lease_t *
    amq_lease_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_lease_free(self)            amq_lease_free_ (self, __FILE__, __LINE__)
static void
    amq_lease_free_ (
amq_lease_t * self,                     //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_lease_cache_initialise (
void);

static void
    amq_lease_cache_purge (
void);

static void
    amq_lease_cache_terminate (
void);

Bool
    amq_lease_animating = TRUE;         //  Animation enabled by default
static Bool
    s_amq_lease_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_lease_mutex        = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static amq_lease_table_t
    *s_amq_lease_table;                 //  The table of existing items
/*  -------------------------------------------------------------------------
    amq_lease_new

    Type: Component method
    Creates and initialises a new amq_lease_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

amq_lease_t *
    amq_lease_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * name,                        //  Sink or feed name
    int type,                           //  DP_SINK or DP_FEED
    amq_server_channel_t * channel      //  Parent channel
)
{
#define table s_amq_lease_table
#define key self->name
apr_time_t
    time_now;
    amq_lease_t *
        self = NULL;                    //  Object reference

if (!s_amq_lease_active)
    self_initialise ();
    self = amq_lease_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_LEASE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_lease_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
//
assert (type == DP_SINK || type == DP_FEED);
self->type = type;
self->channel = amq_server_channel_link (channel);
self->connection = amq_server_connection_link (channel->connection);
icl_shortstr_cpy (self->connection_id, self->connection->id);

time_now = apr_time_now ();
if (type == DP_SINK) {
    if (*name)
        self->sink = amq_exchange_table_search (amq_broker->exchange_table, name);
    else
        //  Get default exchange for virtual host
        self->sink = amq_exchange_link (amq_broker->default_exchange);

    if (self->sink)
        icl_shortstr_fmt (self->name, "S-%08X%08X-%s",
            (qbyte) (time_now >> 32), (qbyte) time_now & 0xFFFFFFFF, self->sink->name);
    else
        self_destroy (&self);
}
else
if (type == DP_FEED) {
    //  Only allow one lease per queue
    self->feed = amq_queue_table_search (amq_broker->queue_table, name);
    if (self->feed && !self->feed->lease) {
        //  Cannot link to lease since that forms circular reference
        self->feed->lease = self;
        icl_shortstr_fmt (self->name, "F-%08X%08X-%s",
            (qbyte) (time_now >> 32), (qbyte) time_now & 0xFFFFFFFF, self->feed->name);
    }
    else
        self_destroy (&self);
}
if (table && self && amq_lease_table_insert (table, key, self))
    amq_lease_destroy (&self);
}

    return (self);
}
#undef table
#undef key
/*  -------------------------------------------------------------------------
    amq_lease_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_lease_annihilate_ (
    amq_lease_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
    int
        history_last;
#endif

    amq_lease_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_LEASE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_LEASE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_LEASE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_LEASE_HISTORY_LENGTH] = self->links;
#endif

    AMQ_LEASE_ASSERT_SANE (self);
    amq_lease_remove_from_all_containers (self);

if (self->feed) {
    self->feed->lease = NULL;
    amq_queue_unlink (&self->feed);
}
amq_server_channel_unlink (&self->channel);
amq_server_connection_unlink (&self->connection);
amq_exchange_unlink (&self->sink);
smt_thread_unlink (&self->thread);

}
/*  -------------------------------------------------------------------------
    amq_lease_search

    Type: Component method
    -------------------------------------------------------------------------
 */

amq_lease_t *
    amq_lease_search (
    char * name                         //  Exchange name
)
{
    amq_lease_t *
        self;                           //  The found object

if (!s_amq_lease_active)
    amq_lease_initialise ();
self = amq_lease_table_search (s_amq_lease_table, name);

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_lease_acquire

    Type: Component method
    Accepts a amq_lease_t reference and returns zero in case of success,
    1 in case of errors.
    Acquires the lease; returns -1 if the lease was already acquired by
    another thread.  The acquiring thread will receive messages when the
    lease is for a feed.
    -------------------------------------------------------------------------
 */

int
    amq_lease_acquire (
    amq_lease_t * self,                 //  Reference to object
    smt_thread_t * thread,              //  Not documented
    smt_socket_t * socket               //  Not documented
)
{
    int
        rc = 0;                         //  Return code

AMQ_LEASE_ASSERT_SANE (self);
if (!self->zombie) {

if (self->thread)
    rc = -1;                        //  Already acquired
self->thread = smt_thread_link (thread);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_lease_sink

    Type: Component method
    Accepts a amq_lease_t reference and returns zero in case of success,
    1 in case of errors.
    Send a content to a sink.  This function does the application specific
    processing for a sink, which in this instance is an exchange.
    -------------------------------------------------------------------------
 */

int
    amq_lease_sink (
    amq_lease_t * self,                 //  Reference to object
    amq_content_basic_t * content,      //  Not documented
    byte options                        //  Publish options octet
)
{
    int
        rc = 0;                         //  Return code

AMQ_LEASE_ASSERT_SANE (self);
if (!self->zombie) {

//
icl_shortstr_cpy (content->producer_id, self->connection_id);
//  Options octet is [0][0][0][0][0][0][mandatory][immediate]
amq_exchange_publish (
    self->sink,
    self->channel,
    content,
    (options >> 1) & 1,             //  Mandatory bit
    options & 1,                    //  Immediate bit
    self->connection->group);
icl_atomic_inc32 ((volatile qbyte *) &(amq_broker->direct_sunk));
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_lease_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_lease_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_lease_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_lease_mutex)
            s_amq_lease_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_lease_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_lease_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

s_amq_lease_table = amq_lease_table_new ();
            s_amq_lease_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_lease_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    amq_lease_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_lease_terminate (
void)
{

if (s_amq_lease_active) {

amq_lease_table_destroy (&s_amq_lease_table);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_lease_mutex);
#endif
        s_amq_lease_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    amq_lease_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_lease_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_lease_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_lease_remove_from_all_containers (
    amq_lease_t * self                  //  The item
)
{

AMQ_LEASE_ASSERT_SANE (self);
amq_lease_table_remove (self);
}
/*  -------------------------------------------------------------------------
    amq_lease_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_lease_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_lease_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
if (self->table_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_lease zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
    if (self->history_last > AMQ_LEASE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_LEASE_HISTORY_LENGTH;
        self->history_last %= AMQ_LEASE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_LEASE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_lease>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_lease_destroy

    Type: Component method
    Destroys a amq_lease_t object. Takes the address of a
    amq_lease_t reference (a pointer to a pointer) and nullifies the
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
    amq_lease_destroy_ (
    amq_lease_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_lease_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_lease_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("amq_lease", "E: missing link on amq_lease object");
        amq_lease_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_lease_free_ ((amq_lease_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_lease_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_lease_t *
    amq_lease_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_lease_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_lease_cache_initialise ();

self = (amq_lease_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_lease_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_lease_free

    Type: Component method
    Freess a amq_lease_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_lease_free_ (
    amq_lease_t * self,                 //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_LEASE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_LEASE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_LEASE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_LEASE_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (amq_lease_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_lease_t));
        self->object_tag = AMQ_LEASE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_lease_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_lease_t *
    amq_lease_link_ (
    amq_lease_t * self,                 //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
    int
        history_last;
#endif

    if (self) {
        AMQ_LEASE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_LEASE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_LEASE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_LEASE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_LEASE_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_lease_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_lease_unlink_ (
    amq_lease_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
    int
        history_last;
#endif

    amq_lease_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        AMQ_LEASE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("amq_lease", "E: missing link on amq_lease object");
            amq_lease_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_LEASE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_LEASE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_LEASE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_LEASE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_LEASE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_lease_annihilate_ (self_p, file, line);
        amq_lease_free_ ((amq_lease_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_lease_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_lease_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_lease_t));
icl_system_register (amq_lease_cache_purge, amq_lease_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_lease_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_lease_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_lease_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_lease_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_lease_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_lease_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_lease_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_lease_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_lease_new_in_scope_ (
    amq_lease_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * name,                        //  Sink or feed name
    int type,                           //  DP_SINK or DP_FEED
    amq_server_channel_t * channel      //  Parent channel
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_lease_new_ (file,line,name,type,channel);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_lease_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_lease_version_start      = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_lease_component          = "amq_lease ";
char *EMBED__amq_lease_version            = "1.0 ";
char *EMBED__amq_lease_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_lease_filename           = "amq_lease.icl ";
char *EMBED__amq_lease_builddate          = "2010/10/06 ";
char *EMBED__amq_lease_version_end        = "VeRsIoNeNd:ipc";

