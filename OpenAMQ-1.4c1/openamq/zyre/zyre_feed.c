/*---------------------------------------------------------------------------
    zyre_feed.c - zyre_feed component

This class implements the RestMS feed object.
    Generated from zyre_feed.icl by icl_gen using GSL/4.
    
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
#include "zyre_feed.h"                  //  Definitions for our class

//  Shorthand for class type

#define self_t              zyre_feed_t

//  Shorthands for class methods

#define self_new            zyre_feed_new
#define self_annihilate     zyre_feed_annihilate
#define self_configure      zyre_feed_configure
#define self_get            zyre_feed_get
#define self_put            zyre_feed_put
#define self_delete         zyre_feed_delete
#define self_post           zyre_feed_post
#define self_report         zyre_feed_report
#define self_attach         zyre_feed_attach
#define self_detach         zyre_feed_detach
#define self_spec_valid     zyre_feed_spec_valid
#define self_selftest       zyre_feed_selftest
#define self_initialise     zyre_feed_initialise
#define self_terminate      zyre_feed_terminate
#define self__zyre_resource_new  zyre_feed__zyre_resource_new
#define self__zyre_resource_factory  zyre_feed__zyre_resource_factory
#define self__zyre_resource_unbind  zyre_feed__zyre_resource_unbind
#define self__zyre_resource_link  zyre_feed__zyre_resource_link
#define self__zyre_resource_unlink  zyre_feed__zyre_resource_unlink
#define self_show           zyre_feed_show
#define self_destroy        zyre_feed_destroy
#define self_alloc          zyre_feed_alloc
#define self_free           zyre_feed_free
#define self_link           zyre_feed_link
#define self_unlink         zyre_feed_unlink
#define self_show_animation  zyre_feed_show_animation
#define self_new_in_scope   zyre_feed_new_in_scope

#define zyre_feed_annihilate(self)      zyre_feed_annihilate_ (self, __FILE__, __LINE__)
static void
    zyre_feed_annihilate_ (
zyre_feed_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static int
    zyre_feed_configure (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context,        //  Not documented
ipr_hash_table_t * table,               //  Not documented
zyre_backend_t * backend                //  Not documented
);

static int
    zyre_feed_get (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context         //  Not documented
);

static int
    zyre_feed_put (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context         //  Not documented
);

static int
    zyre_feed_delete (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context         //  Not documented
);

static int
    zyre_feed_post (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context,        //  Not documented
ipr_hash_table_t * table,               //  Not documented
zyre_backend_t * backend                //  Not documented
);

static int
    zyre_feed_report (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context,        //  Not documented
ipr_tree_t * tree                       //  Not documented
);

static int
    zyre_feed_attach (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
zyre_resource_t * resource,             //  Not documented
void * argument                         //  Not documented
);

static int
    zyre_feed_detach (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
zyre_resource_t * resource,             //  Not documented
void * argument                         //  Not documented
);

static void
    zyre_feed_initialise (
void);

static void
    zyre_feed_terminate (
void);

static void
    zyre_feed__zyre_resource_unbind (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal                //  Portal reference
);

static void *
    zyre_feed__zyre_resource_link (
void * object                           //  Reference cast as a void *
);

static void
    zyre_feed__zyre_resource_unlink (
void * object_p                         //  Reference pointer cast as a void *
);

#define zyre_feed_alloc()               zyre_feed_alloc_ (__FILE__, __LINE__)
static zyre_feed_t *
    zyre_feed_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_feed_free(self)            zyre_feed_free_ (self, __FILE__, __LINE__)
static void
    zyre_feed_free_ (
zyre_feed_t * self,                     //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

Bool
    zyre_feed_animating = TRUE;         //  Animation enabled by default
static Bool
    s_zyre_feed_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_zyre_feed_mutex        = NULL;
#endif

static ipr_looseref_list_t
    *s_zyre_resource_list;              //  List of portal factories
static Bool
    s_zyre_resource_stopped;            //  Is this portal factory stopped?
static void
s_send_message (ipr_xml_t *message, http_driver_context_t *context,
    ipr_hash_table_t *table, char *feed_name, zyre_backend_t *backend);
/*  -------------------------------------------------------------------------
    zyre_feed_new

    Type: Component method
    Creates and initialises a new zyre_feed_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

zyre_feed_t *
    zyre_feed_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    zyre_feed_t *
        self = NULL;                    //  Object reference

if (!s_zyre_feed_active)
    self_initialise ();
    self = zyre_feed_alloc_ (file, line);
    if (self) {
        self->object_tag   = ZYRE_FEED_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_FEED)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, zyre_feed_show_);
#endif

self->zyre_resource_list = ipr_looseref_list_new ();

self->joins = ipr_looseref_list_new ();
}

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_feed_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_feed_annihilate_ (
    zyre_feed_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_FEED)
    int
        history_last;
#endif

zyre_resource_t
    *zyre_resource;                 //  Portal object
ipr_looseref_t
    *looseref;
    zyre_feed_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_FEED)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ZYRE_FEED_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ZYRE_FEED_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ZYRE_FEED_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ZYRE_FEED_HISTORY_LENGTH] = self->links;
#endif

    ZYRE_FEED_ASSERT_SANE (self);

//
if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_resource_stopped, TRUE, FALSE) == FALSE) {
    while ((zyre_resource = (zyre_resource_t *) ipr_looseref_pop (self->zyre_resource_list))) {
        zyre_resource->server_looseref = NULL;
        zyre_resource_destroy (&zyre_resource);
    }
}
ipr_looseref_list_destroy (&self->zyre_resource_list);

//
//  Free any references to joins that we still hold (no links)
while ((looseref = ipr_looseref_list_pop (self->joins))) {
    icl_mem_free (looseref->argument);
    ipr_looseref_destroy (&looseref);
}
ipr_looseref_list_destroy (&self->joins);
zyre_backend_unlink (&self->backend);

}
/*  -------------------------------------------------------------------------
    zyre_feed_configure

    Type: Component method
    This is the configure incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_feed_configure (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context,    //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    zyre_backend_t * backend            //  Not documented
)
{
zyre_feed_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_feed_t *) self_v;
//  If the context is null, configure a default feed
assert (backend);
if (context) {
    self->dynamic = TRUE;
    self->backend = zyre_backend_link (backend);
    icl_shortstr_cpy (self->type, ipr_xml_attr_get (context->xml_item, "type", "topic"));
    icl_shortstr_cpy (self->title, ipr_xml_attr_get (context->xml_item, "title", ""));
    icl_shortstr_cpy (self->license, ipr_xml_attr_get (context->xml_item, "license", ""));
    zyre_backend_request_feed_create (self->backend, self->type, portal->name);
}
else {
    //  Default feed is not visible to backend
    self->dynamic = FALSE;
    icl_shortstr_cpy (self->type, "direct");
    icl_shortstr_cpy (self->title, "Default feed");
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_feed_get

    Type: Component method
    This is the get incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_feed_get (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
zyre_feed_t
    *self;
ipr_tree_t
    *tree;
    int
        rc = 0;                         //  Return code

self = (zyre_feed_t *) self_v;
//
tree = ipr_tree_new (RESTMS_ROOT);
ipr_tree_open (tree, "feed");
ipr_tree_leaf (tree, "type", self->type);
ipr_tree_leaf (tree, "name", portal->name);
if (*self->title)
    ipr_tree_leaf (tree, "title", self->title);
if (*self->license)
    ipr_tree_leaf (tree, "license", self->license);
zyre_resource_to_document (portal, context, &tree);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_feed_put

    Type: Component method
    This is the put incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_feed_put (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
zyre_feed_t
    *self;
char
    *value;
    int
        rc = 0;                         //  Return code

self = (zyre_feed_t *) self_v;
//
if (!self->dynamic)
    http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
        "may not modify this feed");
else
if (context->request->content_length == 0)
    http_driver_context_reply_success (context, HTTP_REPLY_NOCONTENT);
else
if (zyre_restms_parse_document (context, "feed") == 0) {
    value = ipr_xml_attr_get (context->xml_item, "title", NULL);
    if (value)
        icl_shortstr_cpy (self->title, value);
    value = ipr_xml_attr_get (context->xml_item, "license", NULL);
    if (value)
        icl_shortstr_cpy (self->license, value);
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_feed_delete

    Type: Component method
    This is the delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_feed_delete (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
zyre_feed_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_feed_t *) self_v;
//  We can delete configured resources internally, context will be null
if (self->dynamic || context == NULL) {
    zyre_resource_t
        *resource;
    ipr_looseref_t
        *looseref;

    while ((looseref = ipr_looseref_list_first (self->joins))) {
        //  Since we don't have a link to the resource, grab one
        resource = zyre_resource_link ((zyre_resource_t *) looseref->object);
        zyre_resource_request_delete (resource, context);
        zyre_resource_destroy (&resource);
    }
    if (self->backend)
        zyre_backend_request_feed_delete (self->backend, portal->name);
}
else
    http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
        "may not delete this feed");

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_feed_post

    Type: Component method
    This is the post incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_feed_post (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context,    //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    zyre_backend_t * backend            //  Not documented
)
{
zyre_feed_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_feed_t *) self_v;
if (streq (context->request->content_type, "application/restms+xml")) {
    //  If we got a RestMS document, it must contain message elements
    if (http_driver_context_xml_parse (context, RESTMS_ROOT, "message") == 0) {
        //  Send a message for each XML item
        ipr_xml_t
            *message = ipr_xml_link (context->xml_item);
        while (message) {
            s_send_message (message, context, table, portal->name, backend);
            message = ipr_xml_next_sibling (&message);
        }
    }
}
else {
    //  Create a content and attach to feed
    zyre_resource_t
        *content;

    //  Create a new content resource and attach to the feed resource
    content = zyre_content__zyre_resource_new (NULL, portal, table, "content", "");
    zyre_restms__zyre_resource_bind ((zyre_restms_t *) (portal->client_object), content);
    //  Allow the content resource to configure itself from the HTTP context
    zyre_resource_request_configure (content, context, table, backend);
    //  Set Location: header to location of content
    http_response_set_header (context->response, "location",
        "%s%s%s", context->response->root_uri, RESTMS_ROOT, content->path);
    //  Drop our link to it, it's now a child of the feed
    zyre_resource_unlink (&content);
    //  Reply with 201 Created, and no content body
    http_driver_context_reply_success (context, HTTP_REPLY_CREATED);
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_feed_report

    Type: Component method
    This is the report incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_feed_report (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context,    //  Not documented
    ipr_tree_t * tree                   //  Not documented
)
{
zyre_feed_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_feed_t *) self_v;
ipr_tree_open (tree, "feed");
ipr_tree_leaf (tree, "type", self->type);
ipr_tree_leaf (tree, "name", portal->name);
if (*self->title)
    ipr_tree_leaf (tree, "title", self->title);
if (*self->license)
    ipr_tree_leaf (tree, "license", self->license);
ipr_tree_leaf (tree, "href", "%s%s%s",
    context->response->root_uri, RESTMS_ROOT, portal->path);
ipr_tree_shut (tree);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_feed_attach

    Type: Component method
    This is the attach incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_feed_attach (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    zyre_resource_t * resource,         //  Not documented
    void * argument                     //  Not documented
)
{
zyre_feed_t
    *self;
ipr_looseref_t
    *looseref;
    int
        rc = 0;                         //  Return code

self = (zyre_feed_t *) self_v;
//
looseref = ipr_looseref_queue (self->joins, resource);
looseref->argument = icl_mem_strdup ((char *) argument);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_feed_detach

    Type: Component method
    This is the detach incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_feed_detach (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    zyre_resource_t * resource,         //  Not documented
    void * argument                     //  Not documented
)
{
zyre_feed_t
    *self;
ipr_looseref_t
    *looseref;
    int
        rc = 0;                         //  Return code

self = (zyre_feed_t *) self_v;
//
looseref = ipr_looseref_list_first (self->joins);
while (looseref) {
    if (streq ((char *) looseref->argument, argument)) {
        icl_mem_free (looseref->argument);
        ipr_looseref_destroy (&looseref);
        break;
    }
    looseref = ipr_looseref_list_next (&looseref);
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_feed_spec_valid

    Type: Component method
    Returns TRUE if the specified feed specification is valid, else
    sends an error reply and returns FALSE.
    -------------------------------------------------------------------------
 */

int
    zyre_feed_spec_valid (
    http_driver_context_t * context     //  Not documented
)
{
char
    *type;
    int
        rc = FALSE;                     //  Not documented

//
type = ipr_xml_attr_get (context->xml_item, "type", "");
if (strnull (type)
||  streq (type, "fanout")
||  streq (type, "direct")
||  streq (type, "topic")
||  streq (type, "headers")
||  streq (type, "service")
||  streq (type, "rotator")
||  streq (type, "system"))
    rc = TRUE;
else
    http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
        "unknown feed type '%s' specified", type);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_feed_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_feed_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    zyre_feed_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_feed_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_zyre_feed_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_zyre_feed_mutex)
            s_zyre_feed_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_zyre_feed_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_zyre_feed_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

s_zyre_resource_list = ipr_looseref_list_new ();
            s_zyre_feed_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_zyre_feed_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    zyre_feed_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_feed_terminate (
void)
{
zyre_resource_t
    *zyre_resource;                 //  Portal factory object

if (s_zyre_feed_active) {

//
if (icl_atomic_cas32 ((volatile qbyte *) &s_zyre_resource_stopped, TRUE, FALSE) == FALSE) {
    while ((zyre_resource = (zyre_resource_t *) ipr_looseref_pop (s_zyre_resource_list))) {
        zyre_resource->server_looseref = NULL;
        zyre_resource_destroy (&zyre_resource);
    }
}
ipr_looseref_list_destroy (&s_zyre_resource_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_zyre_feed_mutex);
#endif
        s_zyre_feed_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    zyre_feed__zyre_resource_new

    Type: Component method
    Creates and initialises a new portal instance.  If the _server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    -------------------------------------------------------------------------
 */

zyre_resource_t *
    zyre_feed__zyre_resource_new (
    void * self_v,                      //  Untyped server reference
    zyre_resource_t * parent,           //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    char * type,                        //  Not documented
    char * name                         //  Not documented
)
{
zyre_feed_t
    *self;
    zyre_resource_t *
        zyre_resource;                  //  Not documented

//
//  Grab a link to a new or the provided server object
if (self_v)
    self = self_link ((zyre_feed_t *) self_v);
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
    zyre_feed__zyre_resource_factory

    Type: Component method
    Creates and initialises a new portal factory instance.
    -------------------------------------------------------------------------
 */

zyre_resource_t *
    zyre_feed__zyre_resource_factory (
    zyre_resource_t * parent,           //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    char * type,                        //  Not documented
    char * name                         //  Not documented
)
{
    zyre_resource_t *
        zyre_resource;                  //  Not documented

//
if (!s_zyre_feed_active)
    self_initialise ();             //  Since we don't call zyre_feed_new
zyre_resource = zyre_resource_new (NULL, self__zyre_resource_link, self__zyre_resource_unlink, parent, table, type, name);
zyre_resource->server_looseref = ipr_looseref_queue (
    s_zyre_resource_list, zyre_resource_link (zyre_resource));

//  Build virtual methods for server-side methods
zyre_resource->server_new = self__zyre_resource_new;

    return (zyre_resource);
}
/*  -------------------------------------------------------------------------
    zyre_feed__zyre_resource_unbind

    Type: Component method
    Server-to-portal unbind.
    -------------------------------------------------------------------------
 */

static void
    zyre_feed__zyre_resource_unbind (
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
    zyre_feed__zyre_resource_link

    Type: Component method
    -------------------------------------------------------------------------
 */

static void *
    zyre_feed__zyre_resource_link (
    void * object                       //  Reference cast as a void *
)
{

//
object = (void *) zyre_feed_link (((zyre_feed_t *) object));

    return (object);
}
/*  -------------------------------------------------------------------------
    zyre_feed__zyre_resource_unlink

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_feed__zyre_resource_unlink (
    void * object_p                     //  Reference pointer cast as a void *
)
{

//
zyre_feed_unlink (((zyre_feed_t **) object_p));
}
/*  -------------------------------------------------------------------------
    zyre_feed_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_feed_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    zyre_feed_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_FEED)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <zyre_feed zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_FEED)
    if (self->history_last > ZYRE_FEED_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ZYRE_FEED_HISTORY_LENGTH;
        self->history_last %= ZYRE_FEED_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ZYRE_FEED_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </zyre_feed>\n");
#endif

}
/*  -------------------------------------------------------------------------
    zyre_feed_destroy

    Type: Component method
    Destroys a zyre_feed_t object. Takes the address of a
    zyre_feed_t reference (a pointer to a pointer) and nullifies the
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
    zyre_feed_destroy_ (
    zyre_feed_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    zyre_feed_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        zyre_feed_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("zyre_feed", "E: missing link on zyre_feed object");
        zyre_feed_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        zyre_feed_free_ ((zyre_feed_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    zyre_feed_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static zyre_feed_t *
    zyre_feed_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    zyre_feed_t *
        self = NULL;                    //  Object reference

self = (zyre_feed_t *) icl_mem_alloc_ (sizeof (zyre_feed_t), file, line);
if (self)
    memset (self, 0, sizeof (zyre_feed_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_feed_free

    Type: Component method
    Freess a zyre_feed_t object.
    -------------------------------------------------------------------------
 */

static void
    zyre_feed_free_ (
    zyre_feed_t * self,                 //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_FEED)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_FEED)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_FEED_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_FEED_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_FEED_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ZYRE_FEED_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (zyre_feed_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (zyre_feed_t));
        self->object_tag = ZYRE_FEED_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    zyre_feed_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

zyre_feed_t *
    zyre_feed_link_ (
    zyre_feed_t * self,                 //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_FEED)
    int
        history_last;
#endif

    if (self) {
        ZYRE_FEED_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_FEED)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_FEED_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_FEED_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_FEED_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ZYRE_FEED_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_feed_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    zyre_feed_unlink_ (
    zyre_feed_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_FEED)
    int
        history_last;
#endif

    zyre_feed_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        ZYRE_FEED_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("zyre_feed", "E: missing link on zyre_feed object");
            zyre_feed_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_FEED)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_FEED_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_FEED_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_FEED_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ZYRE_FEED_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            zyre_feed_annihilate_ (self_p, file, line);
        zyre_feed_free_ ((zyre_feed_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    zyre_feed_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    zyre_feed_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

zyre_feed_animating = enabled;
}
/*  -------------------------------------------------------------------------
    zyre_feed_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_feed_new_in_scope_ (
    zyre_feed_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = zyre_feed_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) zyre_feed_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  XML item is message
//  Table lets us find the content resource by href
//  Backend is where we send the message to
static void
s_send_message (
    ipr_xml_t *message,
    http_driver_context_t *context,
    ipr_hash_table_t *table,
    char *feed_name,
    zyre_backend_t *backend)
{
    amq_content_basic_t
        *content;                       //  Content to post
    ipr_xml_t
        *element;                       //  content element of message
    char
        *address;                       //  Address to use for routing
    asl_field_list_t
        *headers_list;                  //  Message headers as list
    icl_longstr_t
        *headers_table;                 //  Message headers as table

    //  Grab a new content to work with
    content = amq_content_basic_new ();

    //  Parse content element if any
    element = ipr_xml_find_item (message, "content");
    if (element) {
        char
            *uri = ipr_xml_attr_get (element, "href", NULL);
        if (uri) {
            //  Set content from staged content resource
            zyre_resource_t
                *resource;              //  Resource portal for content
            resource = zyre_resource_parse_uri (context, table, uri);
            if (resource) {
                //  Reach through the portal to grab the content properties
                //  Kind of ugly but it's the simplest way to get these
                amq_content_basic_record_body (content,
                    ((zyre_content_t *) (resource->server_object))->bucket);
                amq_content_basic_set_content_type (content,
                    ((zyre_content_t *) (resource->server_object))->type);

                //  Destroy the content resource now
                resource = zyre_resource_link (resource);
                zyre_resource_detach_from_parent (resource);
                zyre_resource_destroy (&resource);
            }
            else
                http_driver_context_reply_error (context, HTTP_REPLY_NOTFOUND,
                    "content resource does not exist");
        }
        else {
            //  Set content from embedded element value
            char
                *value = ipr_xml_text (element),
                *type = ipr_xml_attr_get (element, "type", NULL),
                *encoding = ipr_xml_attr_get (element, "encoding", NULL);
            size_t
                value_len = strlen (value);

            if (encoding) {
                if (streq (encoding, "base64")) {
                    char
                        *encoded,
                        *decoded;

                    //  Trim white space before and after encoded
                    encoded = ipr_str_crop (ipr_str_skip (value));
                    //  Decode the base64 value and switch to binary version
                    value_len = apr_base64_decode_len (encoded);
                    decoded = icl_mem_alloc (value_len);
                    apr_base64_decode (decoded, encoded);
                    icl_mem_free (value);
                    value = decoded;
                    value_len--;        //  APR counts size + 1
                }
                else
                    amq_content_basic_set_content_encoding (content, encoding);
            }
            amq_content_basic_set_body (content, value, value_len, icl_mem_free);
            if (type)
                amq_content_basic_set_content_type (content, type);
        }
        ipr_xml_unlink (&element);
    }
    //  Set AMQP properties on the message
    amq_content_basic_set_delivery_mode  (content, atoi (
        ipr_xml_attr_get (message, "delivery_mode", "0")));
    amq_content_basic_set_priority       (content, atoi (
        ipr_xml_attr_get (message, "priority", "")));
    amq_content_basic_set_correlation_id (content,
        ipr_xml_attr_get (message, "correlation_id", ""));
    amq_content_basic_set_reply_to       (content,
        ipr_xml_attr_get (message, "reply_to", ""));
    amq_content_basic_set_expiration     (content,
        ipr_xml_attr_get (message, "expiration", ""));
    amq_content_basic_set_message_id     (content,
        ipr_xml_attr_get (message, "message_id", ""));
    amq_content_basic_set_timestamp      (content, (int64_t) ipr_time_mime_decode (
        ipr_xml_attr_get (message, "timestamp", "")));
    amq_content_basic_set_type           (content,
        ipr_xml_attr_get (message, "type", ""));
    amq_content_basic_set_user_id        (content,
        ipr_xml_attr_get (message, "user_id", ""));
    amq_content_basic_set_app_id         (content,
        ipr_xml_attr_get (message, "app_id", ""));
    amq_content_basic_set_sender_id      (content,
        ipr_xml_attr_get (message, "sender_id", ""));

    //  Process message headers
    headers_list = asl_field_list_new (NULL);
    element = ipr_xml_find_item (message, "header");
    while (element) {
        char *name = ipr_xml_attr_get (element, "name", NULL);
        char *value = ipr_xml_attr_get (element, "value", NULL);
        if (name && value)
            asl_field_new_string (headers_list, name, value);
        element = ipr_xml_next_item (&element);
    }
    //  Save headers field table into content
    headers_table = asl_field_list_flatten (headers_list);
    amq_content_basic_set_headers (content, headers_table);
    asl_field_list_unlink (&headers_list);
    icl_longstr_destroy (&headers_table);

    address = ipr_xml_attr_get (message, "address", "");
    if (zyre_config_restms_debug (zyre_config))
        icl_console_print ("R: - publish message to feed '%s@%s' (%d bytes)",
            address, feed_name, (int) content->body_size);

    //  Send it off to the backend
    zyre_backend_request_address_post (
        backend,
        address,
        //  Map the default feed to AMQP's "" exchange
        streq (feed_name, "default")? "": feed_name,
        content);

    //  And drop our reference, we're done here
    amq_content_basic_unlink (&content);
}

//  Embed the version information in the resulting binary

char *EMBED__zyre_feed_version_start      = "VeRsIoNsTaRt:ipc";
char *EMBED__zyre_feed_component          = "zyre_feed ";
char *EMBED__zyre_feed_version            = "1.0 ";
char *EMBED__zyre_feed_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__zyre_feed_filename           = "zyre_feed.icl ";
char *EMBED__zyre_feed_builddate          = "2010/10/06 ";
char *EMBED__zyre_feed_version_end        = "VeRsIoNeNd:ipc";

