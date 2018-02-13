/*---------------------------------------------------------------------------
    zyre_message.c - zyre_message component

This class implements the RestMS message object.
    Generated from zyre_message.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "zyre_message.h"               //  Definitions for our class

//  Shorthand for class type

#define self_t              zyre_message_t

//  Shorthands for class methods

#define self_new            zyre_message_new
#define self_configure      zyre_message_configure
#define self_annihilate     zyre_message_annihilate
#define self_get            zyre_message_get
#define self_put            zyre_message_put
#define self_delete         zyre_message_delete
#define self_post           zyre_message_post
#define self_report         zyre_message_report
#define self_attach         zyre_message_attach
#define self_selftest       zyre_message_selftest
#define self_initialise     zyre_message_initialise
#define self_terminate      zyre_message_terminate
#define self__zyre_resource_new  zyre_message__zyre_resource_new
#define self__zyre_resource_factory  zyre_message__zyre_resource_factory
#define self__zyre_resource_unbind  zyre_message__zyre_resource_unbind
#define self_detach         zyre_message_detach
#define self__zyre_resource_link  zyre_message__zyre_resource_link
#define self__zyre_resource_unlink  zyre_message__zyre_resource_unlink
#define self_show           zyre_message_show
#define self_destroy        zyre_message_destroy
#define self_alloc          zyre_message_alloc
#define self_free           zyre_message_free
#define self_link           zyre_message_link
#define self_unlink         zyre_message_unlink
#define self_show_animation  zyre_message_show_animation
#define self_new_in_scope   zyre_message_new_in_scope

static int
    zyre_message_configure (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context,        //  Not documented
ipr_hash_table_t * table,               //  Not documented
zyre_backend_t * backend                //  Not documented
);

#define zyre_message_annihilate(self)   zyre_message_annihilate_ (self, __FILE__, __LINE__)
static void
    zyre_message_annihilate_ (
zyre_message_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static int
    zyre_message_get (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context         //  Not documented
);

static int
    zyre_message_put (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context         //  Not documented
);

static int
    zyre_message_delete (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context         //  Not documented
);

static int
    zyre_message_post (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context,        //  Not documented
ipr_hash_table_t * table,               //  Not documented
zyre_backend_t * backend                //  Not documented
);

static int
    zyre_message_report (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context,        //  Not documented
ipr_tree_t * tree                       //  Not documented
);

static int
    zyre_message_attach (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
zyre_resource_t * resource,             //  Not documented
void * argument                         //  Not documented
);

static void
    zyre_message_initialise (
void);

static void
    zyre_message_terminate (
void);

static void
    zyre_message__zyre_resource_unbind (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal                //  Portal reference
);

static int
    zyre_message_detach (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
zyre_resource_t * resource,             //  Not documented
void * argument                         //  Not documented
);

static void *
    zyre_message__zyre_resource_link (
void * object                           //  Reference cast as a void *
);

static void
    zyre_message__zyre_resource_unlink (
void * object_p                         //  Reference pointer cast as a void *
);

#define zyre_message_alloc()            zyre_message_alloc_ (__FILE__, __LINE__)
static zyre_message_t *
    zyre_message_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_message_free(self)         zyre_message_free_ (self, __FILE__, __LINE__)
static void
    zyre_message_free_ (
zyre_message_t * self,                  //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

Bool
    zyre_message_animating = TRUE;      //  Animation enabled by default
static Bool
    s_zyre_message_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_zyre_message_mutex     = NULL;
#endif

static ipr_looseref_list_t
    *s_zyre_resource_list;              //  List of portal factories
static Bool
    s_zyre_resource_stopped;            //  Is this portal factory stopped?
/*  -------------------------------------------------------------------------
    zyre_message_new

    Type: Component method
    Creates and initialises a new zyre_message_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

zyre_message_t *
    zyre_message_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    zyre_message_t *
        self = NULL;                    //  Object reference

if (!s_zyre_message_active)
    self_initialise ();
    self = zyre_message_alloc_ (file, line);
    if (self) {
        self->object_tag   = ZYRE_MESSAGE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_MESSAGE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, zyre_message_show_);
#endif

self->zyre_resource_list = ipr_looseref_list_new ();

self->pending = TRUE;               //  No content yet
}

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_message_configure

    Type: Component method
    This is the configure incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_message_configure (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context,    //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    zyre_backend_t * backend            //  Not documented
)
{
zyre_message_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_message_t *) self_v;
portal->private = FALSE;            //  Discoverable via pipe

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_message_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_message_annihilate_ (
    zyre_message_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_MESSAGE)
    int
        history_last;
#endif

zyre_resource_t
    *zyre_resource;                 //  Portal object
    zyre_message_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_MESSAGE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = self->links;
#endif

    ZYRE_MESSAGE_ASSERT_SANE (self);

//
if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_resource_stopped, TRUE, FALSE) == FALSE) {
    while ((zyre_resource = (zyre_resource_t *) ipr_looseref_pop (self->zyre_resource_list))) {
        zyre_resource->server_looseref = NULL;
        zyre_resource_destroy (&zyre_resource);
    }
}
ipr_looseref_list_destroy (&self->zyre_resource_list);

asl_field_list_unlink (&self->headers);
http_driver_context_unlink (&self->context);

}
/*  -------------------------------------------------------------------------
    zyre_message_get

    Type: Component method
    This is the get incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_message_get (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
zyre_message_t
    *self;
ipr_tree_t
    *tree;
asl_field_t
    *field;                     //  One field from headers list
    int
        rc = 0;                         //  Return code

self = (zyre_message_t *) self_v;
//
//  We either have a front-end context to talk to, or a saved context from
//  the last GET method and we were still pending... Either will do.
if (context == NULL) {
    context = self->context;
    if (context) {
        //  We previously did a void reply, so allow a real reply now
        context->replied = FALSE;
        //  If context has been shut (client timeout) then don't use it
        if (context->response == NULL)
            context = NULL;     //  Message will stay on pipe...
    }
}
if (self->pending) {
    //  Save the context for a backend arrival call
    http_driver_context_reply_void (context);
    http_driver_context_unlink (&self->context);
    self->context = http_driver_context_link (context);
    if (zyre_config_restms_debug (zyre_config))
        icl_console_print ("R: - starting long poll on asynclet message");
}
else
//  Only respond if we have a valid context
if (context) {
    tree = ipr_tree_new (RESTMS_ROOT);
    ipr_tree_open (tree, "message");
    ipr_tree_leaf (tree, "feed", self->feed);
    if (*self->address)
        ipr_tree_leaf (tree, "address", self->address);
    if (*self->reply_to)
        ipr_tree_leaf (tree, "reply_to", self->reply_to);
    if (self->delivery_mode)
        ipr_tree_leaf (tree, "delivery_mode", "%d", self->delivery_mode);
    if (self->priority)
        ipr_tree_leaf (tree, "priority", "%d", self->priority);
    if (*self->correlation_id)
        ipr_tree_leaf (tree, "correlation_id", self->correlation_id);
    if (*self->expiration)
        ipr_tree_leaf (tree, "expiration", self->expiration);
    if (*self->message_id)
        ipr_tree_leaf (tree, "message_id", self->message_id);
    if (*self->type)
        ipr_tree_leaf (tree, "type", self->type);
    if (*self->user_id)
        ipr_tree_leaf (tree, "user_id", self->user_id);
    if (*self->app_id)
        ipr_tree_leaf (tree, "app_id", self->app_id);
    if (*self->sender_id)
        ipr_tree_leaf (tree, "sender_id", self->sender_id);
    if (*self->timestamp)
        ipr_tree_leaf (tree, "timestamp", self->timestamp);

    field = asl_field_list_first (self->headers);
    while (field) {
        ipr_tree_open (tree, "header");
        ipr_tree_leaf (tree, "name", field->name);
        ipr_tree_leaf (tree, "value", asl_field_string (field));
        ipr_tree_shut (tree);
        field = asl_field_list_next (&field);
    }
    zyre_resource_to_document (portal, context, &tree);
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_message_put

    Type: Component method
    This is the put incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_message_put (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
zyre_message_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_message_t *) self_v;
http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
    "may not modify messages");

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_message_delete

    Type: Component method
    This is the delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_message_delete (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
zyre_message_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_message_t *) self_v;
//  OK, allowed to delete messages

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_message_post

    Type: Component method
    This is the post incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_message_post (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context,    //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    zyre_backend_t * backend            //  Not documented
)
{
zyre_message_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_message_t *) self_v;
http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
    "POST method is not allowed on messages");

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_message_report

    Type: Component method
    This is the report incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_message_report (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context,    //  Not documented
    ipr_tree_t * tree                   //  Not documented
)
{
zyre_message_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_message_t *) self_v;
ipr_tree_open (tree, "message");
ipr_tree_leaf (tree, "href", "%s%s%s",
    context->response->root_uri, RESTMS_ROOT, portal->path);
if (self->pending)
    ipr_tree_leaf (tree, "async", "1");
if (*self->message_id)
    ipr_tree_leaf (tree, "message_id", self->message_id);
ipr_tree_shut (tree);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_message_attach

    Type: Component method
    This is the attach incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    We process an AMQP content coming in via the back-end.
    -------------------------------------------------------------------------
 */

static int
    zyre_message_attach (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    zyre_resource_t * resource,         //  Not documented
    void * argument                     //  Not documented
)
{
zyre_message_t
    *self;
zyre_peer_method_t
    *method;                        //  Peer method object
amq_content_basic_t
    *content;                       //  Content object
    int
        rc = 0;                         //  Return code

self = (zyre_message_t *) self_v;
//
method  = (zyre_peer_method_t *) argument;
content = (amq_content_basic_t *) method->content;
//
//  feed = exchange, address = routing-key
icl_shortstr_cpy (self->address,        method->payload.basic_deliver.routing_key);
icl_shortstr_cpy (self->feed,           method->payload.basic_deliver.exchange);
icl_shortstr_cpy (self->reply_to,       content->reply_to);
icl_shortstr_cpy (self->correlation_id, content->correlation_id);
icl_shortstr_cpy (self->expiration,     content->expiration);
icl_shortstr_cpy (self->message_id,     content->message_id);
icl_shortstr_cpy (self->type,           content->type);
icl_shortstr_cpy (self->user_id,        content->user_id);
icl_shortstr_cpy (self->app_id,         content->app_id);
icl_shortstr_cpy (self->sender_id,      content->sender_id);
if (content->timestamp)
    ipr_time_mime ((apr_time_t) content->timestamp, self->timestamp);
self->priority = content->priority;
self->delivery_mode = content->delivery_mode;
self->headers = asl_field_list_new (content->headers);
self->pending = FALSE;              //  Now we have something

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_message_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_message_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    zyre_message_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_message_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_zyre_message_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_zyre_message_mutex)
            s_zyre_message_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_zyre_message_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_zyre_message_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

s_zyre_resource_list = ipr_looseref_list_new ();
            s_zyre_message_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_zyre_message_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    zyre_message_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_message_terminate (
void)
{
zyre_resource_t
    *zyre_resource;                 //  Portal factory object

if (s_zyre_message_active) {

//
if (icl_atomic_cas32 ((volatile qbyte *) &s_zyre_resource_stopped, TRUE, FALSE) == FALSE) {
    while ((zyre_resource = (zyre_resource_t *) ipr_looseref_pop (s_zyre_resource_list))) {
        zyre_resource->server_looseref = NULL;
        zyre_resource_destroy (&zyre_resource);
    }
}
ipr_looseref_list_destroy (&s_zyre_resource_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_zyre_message_mutex);
#endif
        s_zyre_message_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    zyre_message__zyre_resource_new

    Type: Component method
    Creates and initialises a new portal instance.  If the _server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    -------------------------------------------------------------------------
 */

zyre_resource_t *
    zyre_message__zyre_resource_new (
    void * self_v,                      //  Untyped server reference
    zyre_resource_t * parent,           //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    char * type,                        //  Not documented
    char * name                         //  Not documented
)
{
zyre_message_t
    *self;
    zyre_resource_t *
        zyre_resource;                  //  Not documented

//
//  Grab a link to a new or the provided server object
if (self_v)
    self = self_link ((zyre_message_t *) self_v);
else
    self = self_new ();

zyre_resource = zyre_resource_new (self, self__zyre_resource_link, self__zyre_resource_unlink, parent, table, type, name);
zyre_resource->server_looseref = ipr_looseref_queue (
    self->zyre_resource_list, zyre_resource_link (zyre_resource));

//  Build virtual methods for server-side methods
zyre_resource->server_unbind = self__zyre_resource_unbind;
zyre_resource->request_configure = self_configure;
zyre_resource->request_get = self_get;
zyre_resource->request_put = self_put;
zyre_resource->request_delete = self_delete;
zyre_resource->request_post = self_post;
zyre_resource->request_report = self_report;
zyre_resource->request_attach = self_attach;
zyre_resource->request_detach = self_detach;
//  Drop link to server object
self_unlink (&self);

    return (zyre_resource);
}
/*  -------------------------------------------------------------------------
    zyre_message__zyre_resource_factory

    Type: Component method
    Creates and initialises a new portal factory instance.
    -------------------------------------------------------------------------
 */

zyre_resource_t *
    zyre_message__zyre_resource_factory (
    zyre_resource_t * parent,           //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    char * type,                        //  Not documented
    char * name                         //  Not documented
)
{
    zyre_resource_t *
        zyre_resource;                  //  Not documented

//
if (!s_zyre_message_active)
    self_initialise ();             //  Since we don't call zyre_message_new
zyre_resource = zyre_resource_new (NULL, self__zyre_resource_link, self__zyre_resource_unlink, parent, table, type, name);
zyre_resource->server_looseref = ipr_looseref_queue (
    s_zyre_resource_list, zyre_resource_link (zyre_resource));

//  Build virtual methods for server-side methods
zyre_resource->server_new = self__zyre_resource_new;

    return (zyre_resource);
}
/*  -------------------------------------------------------------------------
    zyre_message__zyre_resource_unbind

    Type: Component method
    Server-to-portal unbind.
    -------------------------------------------------------------------------
 */

static void
    zyre_message__zyre_resource_unbind (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal            //  Portal reference
)
{

//
//  Drop link to portal and remove portal from our list of active portals
if (portal->server_looseref) {
    ipr_looseref_destroy (&portal->server_looseref);
    zyre_resource_unlink (&portal);
}
}
/*  -------------------------------------------------------------------------
    zyre_message_detach

    Type: Component method
    This is the detach incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_message_detach (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    zyre_resource_t * resource,         //  Not documented
    void * argument                     //  Not documented
)
{
zyre_message_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_message_t *) self_v;

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_message__zyre_resource_link

    Type: Component method
    -------------------------------------------------------------------------
 */

static void *
    zyre_message__zyre_resource_link (
    void * object                       //  Reference cast as a void *
)
{

//
object = (void *) zyre_message_link (((zyre_message_t *) object));

    return (object);
}
/*  -------------------------------------------------------------------------
    zyre_message__zyre_resource_unlink

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_message__zyre_resource_unlink (
    void * object_p                     //  Reference pointer cast as a void *
)
{

//
zyre_message_unlink (((zyre_message_t **) object_p));
}
/*  -------------------------------------------------------------------------
    zyre_message_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_message_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    zyre_message_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_MESSAGE)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <zyre_message zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_MESSAGE)
    if (self->history_last > ZYRE_MESSAGE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ZYRE_MESSAGE_HISTORY_LENGTH;
        self->history_last %= ZYRE_MESSAGE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ZYRE_MESSAGE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </zyre_message>\n");
#endif

}
/*  -------------------------------------------------------------------------
    zyre_message_destroy

    Type: Component method
    Destroys a zyre_message_t object. Takes the address of a
    zyre_message_t reference (a pointer to a pointer) and nullifies the
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
    zyre_message_destroy_ (
    zyre_message_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    zyre_message_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        zyre_message_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("zyre_message", "E: missing link on zyre_message object");
        zyre_message_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        zyre_message_free_ ((zyre_message_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    zyre_message_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static zyre_message_t *
    zyre_message_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    zyre_message_t *
        self = NULL;                    //  Object reference

self = (zyre_message_t *) icl_mem_alloc_ (sizeof (zyre_message_t), file, line);
if (self)
    memset (self, 0, sizeof (zyre_message_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_message_free

    Type: Component method
    Freess a zyre_message_t object.
    -------------------------------------------------------------------------
 */

static void
    zyre_message_free_ (
    zyre_message_t * self,              //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_MESSAGE)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_MESSAGE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (zyre_message_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (zyre_message_t));
        self->object_tag = ZYRE_MESSAGE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    zyre_message_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

zyre_message_t *
    zyre_message_link_ (
    zyre_message_t * self,              //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_MESSAGE)
    int
        history_last;
#endif

    if (self) {
        ZYRE_MESSAGE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_MESSAGE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_message_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    zyre_message_unlink_ (
    zyre_message_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_MESSAGE)
    int
        history_last;
#endif

    zyre_message_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        ZYRE_MESSAGE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("zyre_message", "E: missing link on zyre_message object");
            zyre_message_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_MESSAGE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ZYRE_MESSAGE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            zyre_message_annihilate_ (self_p, file, line);
        zyre_message_free_ ((zyre_message_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    zyre_message_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    zyre_message_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

zyre_message_animating = enabled;
}
/*  -------------------------------------------------------------------------
    zyre_message_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_message_new_in_scope_ (
    zyre_message_t * * self_p,          //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = zyre_message_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) zyre_message_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__zyre_message_version_start   = "VeRsIoNsTaRt:ipc";
char *EMBED__zyre_message_component       = "zyre_message ";
char *EMBED__zyre_message_version         = "1.0 ";
char *EMBED__zyre_message_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__zyre_message_filename        = "zyre_message.icl ";
char *EMBED__zyre_message_builddate       = "2010/10/06 ";
char *EMBED__zyre_message_version_end     = "VeRsIoNeNd:ipc";

