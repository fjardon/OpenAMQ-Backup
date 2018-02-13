/*---------------------------------------------------------------------------
    amq_console.c - amq_console component

This implements the AMQ Console object, which is a system-wide object
responsible for implementing the AMQ Console service.

The console works as follows:

 - AMQ Console is instantiated as a global object of this class, which
   has its own context.

 - All operable objects register with the console class, using a console
   class object as a holder for the methods the object class implements.

 - The amq.system exchange sends it messages using the publish method.
   For now, it is hard-coded in amq.system that any messages with the
   "amq.console" will get sent to amq_console.

 - The amq_console decodes the messages and routes it to an object (if
   found), via the amq_console_class definition for that object.

 - The operable objects implement a register, cancel, inspect, and modify
   methods, and return their replies to amq_console asynchrously via
   inspect_ok, modify_ok.

 - All interfaces between amq_console and operable classes is done using
   asl_field lists.
    Generated from amq_console.icl by smt_object_gen using GSL/4.
    
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
#include "amq_console.h"                //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_console_t

//  Shorthands for class methods

#define self_new            amq_console_new
#define self_annihilate     amq_console_annihilate
#define self_register       amq_console_register
#define self_cancel         amq_console_cancel
#define self_accept         amq_console_accept
#define self_reply_ok       amq_console_reply_ok
#define self_reply_error    amq_console_reply_error
#define self_selftest       amq_console_selftest
#define self_destroy        amq_console_destroy
#define self_unlink         amq_console_unlink
#define self_show_animation  amq_console_show_animation
#define self_free           amq_console_free
#define self_initialise     amq_console_initialise
#define self_terminate      amq_console_terminate
#define self_show           amq_console_show
#define self_alloc          amq_console_alloc
#define self_link           amq_console_link
#define self_cache_initialise  amq_console_cache_initialise
#define self_cache_purge    amq_console_cache_purge
#define self_cache_terminate  amq_console_cache_terminate
#define self_new_in_scope   amq_console_new_in_scope

#define amq_console_annihilate(self)    amq_console_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_console_annihilate_ (
amq_console_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_console_initialise (
void);

#define amq_console_alloc()             amq_console_alloc_ (__FILE__, __LINE__)
static amq_console_t *
    amq_console_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_console_cache_initialise (
void);

static void
    amq_console_cache_purge (
void);

static void
    amq_console_cache_terminate (
void);

Bool
    amq_console_animating = TRUE;       //  Animation enabled by default
static Bool
    s_amq_console_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_console_mutex      = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


qbyte
    amq_object_id = 0;
amq_console_t
    *amq_console = NULL;
/*  -------------------------------------------------------------------------
    amq_console_new

    Type: Component method
    Creates and initialises a new amq_console_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_console_t *
    amq_console_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_console_t *
        self = NULL;                    //  Object reference

if (!s_amq_console_active)
    self_initialise ();
    self = amq_console_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CONSOLE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_console_show_);
#endif

self->thread = amq_console_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->object_store = ipr_hash_table_new ();
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_console_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_console_annihilate_ (
    amq_console_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
    int
        history_last;
#endif

    amq_console_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (amq_console_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_console agent");
        rc = -1;
    }
}
else
    rc = -1;

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_console_register

    Type: Component method
    Accepts a amq_console_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Accepts an object registration request.
    -------------------------------------------------------------------------
 */

int
    amq_console_register (
    amq_console_t * self,               //  Reference to object
    qbyte object_id,                    //  Object id
    void * object_ref,                  //  Object reference
    amq_console_class_t * class_ref,    //  Not documented
    qbyte parent_id                     //  Parent object id
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONSOLE_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_console_agent_register (self->thread,object_id,object_ref,class_ref,parent_id)) {
        //icl_console_print ("Error sending 'register' method to amq_console agent");
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
    amq_console_cancel

    Type: Component method
    Accepts a amq_console_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Accepts an object cancellation request.
    -------------------------------------------------------------------------
 */

int
    amq_console_cancel (
    amq_console_t * self,               //  Reference to object
    qbyte object_id                     //  Object ID
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONSOLE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_console_agent_cancel (self->thread,object_id)) {
        //icl_console_print ("Error sending 'cancel' method to amq_console agent");
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
    amq_console_accept

    Type: Component method
    Accepts a amq_console_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Accepts an AMQ Console message, which must be formatted in CML according
    to the AMQ Console specifications.
    -------------------------------------------------------------------------
 */

int
    amq_console_accept (
    amq_console_t * self,               //  Reference to object
    amq_content_basic_t * content,      //  The message content
    int group                           //  User group
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONSOLE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_console_agent_accept (self->thread,content,group)) {
        //icl_console_print ("Error sending 'accept' method to amq_console agent");
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
    amq_console_reply_ok

    Type: Component method
    Accepts a amq_console_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Generic reply to a request.  If the fields argument is not
    null, the fields are returned to the client.
    -------------------------------------------------------------------------
 */

int
    amq_console_reply_ok (
    amq_console_t * self,               //  Reference to object
    char * name,                        //  Reply name
    amq_content_basic_t * request,      //  Original request
    qbyte object_id,                    //  Object id
    asl_field_list_t * fields,          //  Object fields
    char * notice                       //  Reply notice, if any
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONSOLE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_console_agent_reply_ok (self->thread,name,request,object_id,fields,notice)) {
        //icl_console_print ("Error sending 'reply ok' method to amq_console agent");
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
    amq_console_reply_error

    Type: Component method
    Accepts a amq_console_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Generic error reply to a request.
    -------------------------------------------------------------------------
 */

int
    amq_console_reply_error (
    amq_console_t * self,               //  Reference to object
    char * name,                        //  Reply name
    char * status,                      //  Object id
    amq_content_basic_t * request,      //  Original request
    qbyte object_id                     //  Object id
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONSOLE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_console_agent_reply_error (self->thread,name,status,request,object_id)) {
        //icl_console_print ("Error sending 'reply error' method to amq_console agent");
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
    amq_console_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_console_selftest (
void)
{

smt_initialise ();
amq_console = amq_console_new ();
amq_console_destroy (&amq_console);
smt_wait (0);
}
/*  -------------------------------------------------------------------------
    amq_console_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_console_destroy_ (
    amq_console_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_console_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = amq_console_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_console_free (self);
    *self_p = NULL;
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_console_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_console_unlink_ (
    amq_console_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
    int
        history_last;
#endif
    amq_console_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_console object");
            amq_console_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_console_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_console_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
}
/*  -------------------------------------------------------------------------
    amq_console_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_console_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_console_animating = enabled;

amq_console_agent_animate (enabled);
}
/*  -------------------------------------------------------------------------
    amq_console_free

    Type: Component method
    Freess a amq_console_t object.
    -------------------------------------------------------------------------
 */

void
    amq_console_free_ (
    amq_console_t * self,               //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (amq_console_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_console_t));
        self->object_tag = AMQ_CONSOLE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_console_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_console_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_console_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_console_mutex)
            s_amq_console_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_console_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_console_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_console_agent_init ();
            s_amq_console_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_console_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    amq_console_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_console_terminate (
void)
{

if (s_amq_console_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_console_mutex);
#endif
        s_amq_console_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    amq_console_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_console_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_console_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_console zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
    if (self->history_last > AMQ_CONSOLE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_CONSOLE_HISTORY_LENGTH;
        self->history_last %= AMQ_CONSOLE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_CONSOLE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_console>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_console_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_console_t *
    amq_console_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_console_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_console_cache_initialise ();

self = (amq_console_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_console_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_console_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_console_t *
    amq_console_link_ (
    amq_console_t * self,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
    int
        history_last;
#endif

    if (self) {
        AMQ_CONSOLE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONSOLE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_CONSOLE_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_console_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_console_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_console_t));
icl_system_register (amq_console_cache_purge, amq_console_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_console_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_console_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_console_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_console_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_console_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_console_new_in_scope_ (
    amq_console_t * * self_p,           //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_console_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_console_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_console_version_start    = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_console_component        = "amq_console ";
char *EMBED__amq_console_version          = "1.0 ";
char *EMBED__amq_console_copyright        = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_console_filename         = "amq_console.icl ";
char *EMBED__amq_console_builddate        = "2010/10/06 ";
char *EMBED__amq_console_version_end      = "VeRsIoNeNd:ipc";

