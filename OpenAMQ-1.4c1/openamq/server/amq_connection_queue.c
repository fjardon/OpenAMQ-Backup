/*---------------------------------------------------------------------------
    amq_connection_queue.c - amq_connection_queue component

This class shows the relationship from connection to queue, via the
consumer object.
    Generated from amq_connection_queue.icl by smt_object_gen using GSL/4.
    
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
#include "amq_connection_queue.h"       //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_connection_queue_t

//  Shorthands for class methods

#define self_new            amq_connection_queue_new
#define self_annihilate     amq_connection_queue_annihilate
#define self_selftest       amq_connection_queue_selftest
#define self_count          amq_connection_queue_count
#define self_inspect_shim   amq_connection_queue_inspect_shim
#define self_inspect        amq_connection_queue_inspect
#define self_modify_shim    amq_connection_queue_modify_shim
#define self_modify         amq_connection_queue_modify
#define self_method_shim    amq_connection_queue_method_shim
#define self_method         amq_connection_queue_method
#define self_unlink_shim    amq_connection_queue_unlink_shim
#define self_initialise     amq_connection_queue_initialise
#define self_terminate      amq_connection_queue_terminate
#define self_destroy        amq_connection_queue_destroy
#define self_unlink         amq_connection_queue_unlink
#define self_show_animation  amq_connection_queue_show_animation
#define self_free           amq_connection_queue_free
#define self_show           amq_connection_queue_show
#define self_alloc          amq_connection_queue_alloc
#define self_link           amq_connection_queue_link
#define self_cache_initialise  amq_connection_queue_cache_initialise
#define self_cache_purge    amq_connection_queue_cache_purge
#define self_cache_terminate  amq_connection_queue_cache_terminate
#define self_new_in_scope   amq_connection_queue_new_in_scope

#define amq_connection_queue_annihilate(self)  amq_connection_queue_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_connection_queue_annihilate_ (
amq_connection_queue_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_connection_queue_initialise (
void);

#define amq_connection_queue_alloc()    amq_connection_queue_alloc_ (__FILE__, __LINE__)
static amq_connection_queue_t *
    amq_connection_queue_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_connection_queue_cache_initialise (
void);

static void
    amq_connection_queue_cache_purge (
void);

static void
    amq_connection_queue_cache_terminate (
void);

Bool
    amq_connection_queue_animating = TRUE;  //  Animation enabled by default
static Bool
    s_amq_connection_queue_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_connection_queue_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static amq_console_class_t
    *s_class;                           //  Class descriptor
qbyte
    gbl_amq_connection_queue_count = 0;
/*  -------------------------------------------------------------------------
    amq_connection_queue_new

    Type: Component method
    Creates and initialises a new amq_connection_queue_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_connection_queue_t *
    amq_connection_queue_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_connection_t * connection,      //  Parent connection
    amq_consumer_t * consumer           //  Consumer
)
{
    amq_connection_queue_t *
        self = NULL;                    //  Object reference

if (!s_amq_connection_queue_active)
    self_initialise ();
    self = amq_connection_queue_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CONNECTION_QUEUE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_connection_queue_show_);
#endif

self->console = amq_console_link (amq_console);
self->object_id = icl_atomic_inc32 ((volatile qbyte *) &amq_object_id);
amq_console_register (self->console, self->object_id, self_link (self), s_class, connection->object_id);
self->thread = amq_connection_queue_agent_class_thread_new (self);
self->thread->animate = TRUE;

icl_atomic_inc32 ((volatile qbyte *) &gbl_amq_connection_queue_count);

//
self->consumer = amq_consumer_link (consumer);
if (self->consumer)
    self->queue = amq_queue_link (consumer->queue);
if (!self->queue)
    self_destroy (&self);
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_connection_queue_annihilate_ (
    amq_connection_queue_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
    int
        history_last;
#endif

    amq_connection_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (amq_connection_queue_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_connection_queue agent");
        rc = -1;
    }
}
else
    rc = -1;

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_connection_queue_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_connection_queue_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_connection_queue_count (
void)
{
    qbyte
        count;                          //  Number of instances

count = (int) gbl_amq_connection_queue_count;

    return (count);
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_inspect_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_connection_queue_inspect_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Not documented

self_inspect ((amq_connection_queue_t *) (self_v), request);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_inspect

    Type: Component method
    Accepts a amq_connection_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_connection_queue_inspect (
    amq_connection_queue_t * self,      //  Reference to object
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONNECTION_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_connection_queue_agent_inspect (self->thread,request)) {
        //icl_console_print ("Error sending 'inspect' method to amq_connection_queue agent");
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
    amq_connection_queue_modify_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_connection_queue_modify_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

self_modify ((amq_connection_queue_t *) (self_v), request, fields);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_modify

    Type: Component method
    Accepts a amq_connection_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_connection_queue_modify (
    amq_connection_queue_t * self,      //  Reference to object
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONNECTION_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_connection_queue_agent_modify (self->thread,request,fields)) {
        //icl_console_print ("Error sending 'modify' method to amq_connection_queue agent");
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
    amq_connection_queue_method_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_connection_queue_method_shim (
    void * self_v,                      //  Object cast as a void *
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

self_method ((amq_connection_queue_t *) (self_v), method_name, request, fields);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_method

    Type: Component method
    Accepts a amq_connection_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_connection_queue_method (
    amq_connection_queue_t * self,      //  Reference to object
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Argument fields
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONNECTION_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_connection_queue_agent_method (self->thread,method_name,request,fields)) {
        //icl_console_print ("Error sending 'method' method to amq_connection_queue agent");
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
    amq_connection_queue_unlink_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_connection_queue_unlink_shim (
    void * object_p                     //  Reference pointer cast as a void *
)
{

//
amq_connection_queue_unlink (((amq_connection_queue_t **) object_p));
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_connection_queue_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_connection_queue_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_connection_queue_mutex)
            s_amq_connection_queue_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_connection_queue_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_connection_queue_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_connection_queue_agent_init ();

s_class = amq_console_class_new ();
s_class->name    = "connection_queue";
s_class->inspect = amq_connection_queue_inspect_shim;
s_class->modify  = amq_connection_queue_modify_shim;
s_class->method  = amq_connection_queue_method_shim;
s_class->unlink  = amq_connection_queue_unlink_shim;
            s_amq_connection_queue_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_connection_queue_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_connection_queue_terminate (
void)
{

if (s_amq_connection_queue_active) {

amq_console_class_destroy (&s_class);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_connection_queue_mutex);
#endif
        s_amq_connection_queue_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_connection_queue_destroy_ (
    amq_connection_queue_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_connection_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = amq_connection_queue_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_connection_queue_free (self);
    *self_p = NULL;
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_connection_queue_unlink_ (
    amq_connection_queue_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
    int
        history_last;
#endif
    amq_connection_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_connection_queue object");
            amq_connection_queue_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_connection_queue_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_connection_queue_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_connection_queue_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_connection_queue_animating = enabled;

amq_connection_queue_agent_animate (enabled);
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_free

    Type: Component method
    Freess a amq_connection_queue_t object.
    -------------------------------------------------------------------------
 */

void
    amq_connection_queue_free_ (
    amq_connection_queue_t * self,      //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (amq_connection_queue_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_connection_queue_t));
        self->object_tag = AMQ_CONNECTION_QUEUE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_connection_queue_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_connection_queue_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_connection_queue zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
    if (self->history_last > AMQ_CONNECTION_QUEUE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH;
        self->history_last %= AMQ_CONNECTION_QUEUE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_connection_queue>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_connection_queue_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_connection_queue_t *
    amq_connection_queue_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_connection_queue_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_connection_queue_cache_initialise ();

self = (amq_connection_queue_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_connection_queue_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_connection_queue_t *
    amq_connection_queue_link_ (
    amq_connection_queue_t * self,      //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
    int
        history_last;
#endif

    if (self) {
        AMQ_CONNECTION_QUEUE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONNECTION_QUEUE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_CONNECTION_QUEUE_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_connection_queue_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_connection_queue_t));
icl_system_register (amq_connection_queue_cache_purge, amq_connection_queue_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_connection_queue_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_connection_queue_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_connection_queue_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_connection_queue_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_connection_queue_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_connection_queue_new_in_scope_ (
    amq_connection_queue_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_connection_t * connection,      //  Parent connection
    amq_consumer_t * consumer           //  Consumer
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_connection_queue_new_ (file,line,connection,consumer);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_connection_queue_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_connection_queue_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_connection_queue_component  = "amq_connection_queue ";
char *EMBED__amq_connection_queue_version  = "1.0 ";
char *EMBED__amq_connection_queue_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_connection_queue_filename  = "amq_connection_queue.icl ";
char *EMBED__amq_connection_queue_builddate  = "2010/10/06 ";
char *EMBED__amq_connection_queue_version_end  = "VeRsIoNeNd:ipc";

