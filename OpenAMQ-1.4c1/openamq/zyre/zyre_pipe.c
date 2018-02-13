/*---------------------------------------------------------------------------
    zyre_pipe.c - zyre_pipe component

This class implements the RestMS pipe object.
    Generated from zyre_pipe.icl by icl_gen using GSL/4.
    
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
#include "zyre_pipe.h"                  //  Definitions for our class

//  Shorthand for class type

#define self_t              zyre_pipe_t

//  Shorthands for class methods

#define self_new            zyre_pipe_new
#define self_annihilate     zyre_pipe_annihilate
#define self_configure      zyre_pipe_configure
#define self_get            zyre_pipe_get
#define self_put            zyre_pipe_put
#define self_delete         zyre_pipe_delete
#define self_post           zyre_pipe_post
#define self_report         zyre_pipe_report
#define self_attach         zyre_pipe_attach
#define self_detach         zyre_pipe_detach
#define self_spec_valid     zyre_pipe_spec_valid
#define self_selftest       zyre_pipe_selftest
#define self_initialise     zyre_pipe_initialise
#define self_terminate      zyre_pipe_terminate
#define self__zyre_resource_new  zyre_pipe__zyre_resource_new
#define self__zyre_resource_factory  zyre_pipe__zyre_resource_factory
#define self__zyre_resource_unbind  zyre_pipe__zyre_resource_unbind
#define self__zyre_resource_link  zyre_pipe__zyre_resource_link
#define self__zyre_resource_unlink  zyre_pipe__zyre_resource_unlink
#define self_show           zyre_pipe_show
#define self_destroy        zyre_pipe_destroy
#define self_alloc          zyre_pipe_alloc
#define self_free           zyre_pipe_free
#define self_link           zyre_pipe_link
#define self_unlink         zyre_pipe_unlink
#define self_show_animation  zyre_pipe_show_animation
#define self_new_in_scope   zyre_pipe_new_in_scope

#define zyre_pipe_annihilate(self)      zyre_pipe_annihilate_ (self, __FILE__, __LINE__)
static void
    zyre_pipe_annihilate_ (
zyre_pipe_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static int
    zyre_pipe_configure (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context,        //  Not documented
ipr_hash_table_t * table,               //  Not documented
zyre_backend_t * backend                //  Not documented
);

static int
    zyre_pipe_get (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context         //  Not documented
);

static int
    zyre_pipe_put (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context         //  Not documented
);

static int
    zyre_pipe_delete (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context         //  Not documented
);

static int
    zyre_pipe_post (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context,        //  Not documented
ipr_hash_table_t * table,               //  Not documented
zyre_backend_t * backend                //  Not documented
);

static int
    zyre_pipe_report (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
http_driver_context_t * context,        //  Not documented
ipr_tree_t * tree                       //  Not documented
);

static int
    zyre_pipe_attach (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
zyre_resource_t * resource,             //  Not documented
void * argument                         //  Not documented
);

static int
    zyre_pipe_detach (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to client
zyre_resource_t * resource,             //  Not documented
void * argument                         //  Not documented
);

static void
    zyre_pipe_initialise (
void);

static void
    zyre_pipe_terminate (
void);

static void
    zyre_pipe__zyre_resource_unbind (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal                //  Portal reference
);

static void *
    zyre_pipe__zyre_resource_link (
void * object                           //  Reference cast as a void *
);

static void
    zyre_pipe__zyre_resource_unlink (
void * object_p                         //  Reference pointer cast as a void *
);

#define zyre_pipe_alloc()               zyre_pipe_alloc_ (__FILE__, __LINE__)
static zyre_pipe_t *
    zyre_pipe_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_pipe_free(self)            zyre_pipe_free_ (self, __FILE__, __LINE__)
static void
    zyre_pipe_free_ (
zyre_pipe_t * self,                     //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

Bool
    zyre_pipe_animating = TRUE;         //  Animation enabled by default
static Bool
    s_zyre_pipe_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_zyre_pipe_mutex        = NULL;
#endif

static ipr_looseref_list_t
    *s_zyre_resource_list;              //  List of portal factories
static Bool
    s_zyre_resource_stopped;            //  Is this portal factory stopped?
/*  -------------------------------------------------------------------------
    zyre_pipe_new

    Type: Component method
    Creates and initialises a new zyre_pipe_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

zyre_pipe_t *
    zyre_pipe_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    zyre_pipe_t *
        self = NULL;                    //  Object reference

if (!s_zyre_pipe_active)
    self_initialise ();
    self = zyre_pipe_alloc_ (file, line);
    if (self) {
        self->object_tag   = ZYRE_PIPE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, zyre_pipe_show_);
#endif

self->zyre_resource_list = ipr_looseref_list_new ();

self->joins = ipr_looseref_list_new ();
}

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_pipe_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_pipe_annihilate_ (
    zyre_pipe_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
    int
        history_last;
#endif

zyre_resource_t
    *zyre_resource;                 //  Portal object
ipr_looseref_t
    *looseref;
    zyre_pipe_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ZYRE_PIPE_HISTORY_LENGTH] = self->links;
#endif

    ZYRE_PIPE_ASSERT_SANE (self);

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
    zyre_pipe_configure

    Type: Component method
    This is the configure incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_pipe_configure (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context,    //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    zyre_backend_t * backend            //  Not documented
)
{
zyre_pipe_t
    *self;
zyre_resource_t
    *join,
    *message;
    int
        rc = 0;                         //  Return code

self = (zyre_pipe_t *) self_v;
//
//  If the context is null, only configure an asynclet
if (context) {
    icl_shortstr_cpy (self->type, ipr_xml_attr_get (context->xml_item, "type", "topic"));
    icl_shortstr_cpy (self->title, ipr_xml_attr_get (context->xml_item, "title", ""));
    self->backend = zyre_backend_link (backend);
    zyre_backend_request_pipe_create (self->backend, self->type, portal->name);

    //  Create join from pipe to default feed
    join = zyre_join__zyre_resource_new (NULL, portal, table, "join", "");
    zyre_restms__zyre_resource_bind ((zyre_restms_t *) (portal->client_object), join);
    zyre_resource_request_configure (join, NULL, table, self->backend);
    zyre_resource_unlink (&join);
}
//  Create message asynclet
message = zyre_message__zyre_resource_new (NULL, portal, table, "message", "");
zyre_restms__zyre_resource_bind ((zyre_restms_t *) (portal->client_object), message);
zyre_resource_request_configure (message, context, table, self->backend);
self->asynclet = message;
zyre_resource_unlink (&message);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_pipe_get

    Type: Component method
    This is the get incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_pipe_get (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
zyre_pipe_t
    *self;
ipr_tree_t
    *tree;
    int
        rc = 0;                         //  Return code

self = (zyre_pipe_t *) self_v;
//
tree = ipr_tree_new (RESTMS_ROOT);
ipr_tree_open (tree, "pipe");
ipr_tree_leaf (tree, "type", self->type);
ipr_tree_leaf (tree, "name", portal->name);
if (*self->title)
    ipr_tree_leaf (tree, "title", self->title);
zyre_resource_to_document (portal, context, &tree);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_pipe_put

    Type: Component method
    This is the put incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_pipe_put (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
zyre_pipe_t
    *self;
char
    *value;
    int
        rc = 0;                         //  Return code

self = (zyre_pipe_t *) self_v;
//
if (context->request->content_length == 0)
    http_driver_context_reply_success (context, HTTP_REPLY_NOCONTENT);
else
if (zyre_restms_parse_document (context, "pipe") == 0) {
    value = ipr_xml_attr_get (context->xml_item, "title", NULL);
    if (value)
        icl_shortstr_cpy (self->title, value);
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_pipe_delete

    Type: Component method
    This is the delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_pipe_delete (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
zyre_pipe_t
    *self;
zyre_resource_t
    *resource;
ipr_looseref_t
    *looseref;
    int
        rc = 0;                         //  Return code

self = (zyre_pipe_t *) self_v;
//
while ((looseref = ipr_looseref_list_first (self->joins))) {
    //  Since we don't have a link to the resource, grab one
    resource = zyre_resource_link ((zyre_resource_t *) looseref->object);
    zyre_resource_request_delete (resource, NULL);
    zyre_resource_destroy (&resource);
}
zyre_backend_request_pipe_delete (self->backend, portal->name);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_pipe_post

    Type: Component method
    This is the post incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_pipe_post (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context,    //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    zyre_backend_t * backend            //  Not documented
)
{
zyre_pipe_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_pipe_t *) self_v;
if (zyre_restms_parse_document (context, NULL) == 0) {
    if (streq (ipr_xml_name (context->xml_item), "join")) {
        //  We validate the join here so that we can return the existing
        //  join, or complain about an error, or go ahead and create the
        //  join properly.  It's not sensible to do the validation after
        //  we created the join resource (at configure time).
        char
            *feed_uri = ipr_xml_attr_get (context->xml_item, "feed", ""),
            *address = ipr_xml_attr_get (context->xml_item, "address", "*");
        zyre_resource_t
            *resource;
        icl_shortstr_t
            join_key;

        resource = zyre_resource_parse_uri (context, table, feed_uri);
        if (resource && resource->type == RESTMS_RESOURCE_FEED) {
            //  Check if we already have same join, key is address@feed
            ipr_looseref_t
                *looseref;

            icl_shortstr_fmt (join_key, "%s@%s", address, resource->path);
            looseref = ipr_looseref_list_first (self->joins);
            while (looseref) {
                if (streq ((char *) looseref->argument, join_key))
                    break;
                looseref = ipr_looseref_list_next (&looseref);
            }
            if (looseref) {
                //  We have an existing join that matches so report that
                resource = (zyre_resource_t *) looseref->object;
                http_response_set_header (context->response, "location",
                    "%s%s%s", context->response->root_uri, RESTMS_ROOT, resource->path);
                zyre_resource_request_get (resource, context);
            }
            else
            if (streq (resource->name, "default"))
                http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
                    "may not create joins on default feed");
            else
                //  Ok, join is valid and new, so create it
                zyre_resource_response_child_add (portal, context);
        }
        else
            http_driver_context_reply_error (context, HTTP_REPLY_NOTFOUND,
                "feed '%s' does not exist", feed_uri);
    }
    else
        http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
            "may only create new join resources here");
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_pipe_report

    Type: Component method
    This is the report incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_pipe_report (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    http_driver_context_t * context,    //  Not documented
    ipr_tree_t * tree                   //  Not documented
)
{
zyre_pipe_t
    *self;
    int
        rc = 0;                         //  Return code

self = (zyre_pipe_t *) self_v;
ipr_tree_open (tree, "pipe");
ipr_tree_leaf (tree, "type", self->type);
ipr_tree_leaf (tree, "name", portal->name);
if (*self->title)
    ipr_tree_leaf (tree, "title", self->title);
ipr_tree_leaf (tree, "href", "%s%s%s",
    context->response->root_uri, RESTMS_ROOT, portal->path);
ipr_tree_shut (tree);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_pipe_attach

    Type: Component method
    This is the attach incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_pipe_attach (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    zyre_resource_t * resource,         //  Not documented
    void * argument                     //  Not documented
)
{
zyre_pipe_t
    *self;
ipr_looseref_t
    *looseref;
    int
        rc = 0;                         //  Return code

self = (zyre_pipe_t *) self_v;
//
looseref = ipr_looseref_queue (self->joins, resource);
looseref->argument = icl_mem_strdup ((char *) argument);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_pipe_detach

    Type: Component method
    This is the detach incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    zyre_pipe_detach (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to client
    zyre_resource_t * resource,         //  Not documented
    void * argument                     //  Not documented
)
{
zyre_pipe_t
    *self;
ipr_looseref_t
    *looseref;
    int
        rc = 0;                         //  Return code

self = (zyre_pipe_t *) self_v;
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
    zyre_pipe_spec_valid

    Type: Component method
    Returns TRUE if the specified pipe specification is valid, else
    sends an error reply and returns FALSE.
    -------------------------------------------------------------------------
 */

int
    zyre_pipe_spec_valid (
    http_driver_context_t * context     //  Not documented
)
{
char
    *type;
    int
        rc = FALSE;                     //  Not documented

//
type = ipr_xml_attr_get (context->xml_item, "type", "");
if (strnull (type) || streq (type, "fifo"))
    rc = TRUE;
else
    http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
        "unknown pipe type '%s' specified", type);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_pipe_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_pipe_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    zyre_pipe_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_pipe_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_zyre_pipe_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_zyre_pipe_mutex)
            s_zyre_pipe_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_zyre_pipe_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_zyre_pipe_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

s_zyre_resource_list = ipr_looseref_list_new ();
            s_zyre_pipe_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_zyre_pipe_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    zyre_pipe_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_pipe_terminate (
void)
{
zyre_resource_t
    *zyre_resource;                 //  Portal factory object

if (s_zyre_pipe_active) {

//
if (icl_atomic_cas32 ((volatile qbyte *) &s_zyre_resource_stopped, TRUE, FALSE) == FALSE) {
    while ((zyre_resource = (zyre_resource_t *) ipr_looseref_pop (s_zyre_resource_list))) {
        zyre_resource->server_looseref = NULL;
        zyre_resource_destroy (&zyre_resource);
    }
}
ipr_looseref_list_destroy (&s_zyre_resource_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_zyre_pipe_mutex);
#endif
        s_zyre_pipe_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    zyre_pipe__zyre_resource_new

    Type: Component method
    Creates and initialises a new portal instance.  If the _server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    -------------------------------------------------------------------------
 */

zyre_resource_t *
    zyre_pipe__zyre_resource_new (
    void * self_v,                      //  Untyped server reference
    zyre_resource_t * parent,           //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    char * type,                        //  Not documented
    char * name                         //  Not documented
)
{
zyre_pipe_t
    *self;
    zyre_resource_t *
        zyre_resource;                  //  Not documented

//
//  Grab a link to a new or the provided server object
if (self_v)
    self = self_link ((zyre_pipe_t *) self_v);
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
    zyre_pipe__zyre_resource_factory

    Type: Component method
    Creates and initialises a new portal factory instance.
    -------------------------------------------------------------------------
 */

zyre_resource_t *
    zyre_pipe__zyre_resource_factory (
    zyre_resource_t * parent,           //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    char * type,                        //  Not documented
    char * name                         //  Not documented
)
{
    zyre_resource_t *
        zyre_resource;                  //  Not documented

//
if (!s_zyre_pipe_active)
    self_initialise ();             //  Since we don't call zyre_pipe_new
zyre_resource = zyre_resource_new (NULL, self__zyre_resource_link, self__zyre_resource_unlink, parent, table, type, name);
zyre_resource->server_looseref = ipr_looseref_queue (
    s_zyre_resource_list, zyre_resource_link (zyre_resource));

//  Build virtual methods for server-side methods
zyre_resource->server_new = self__zyre_resource_new;

    return (zyre_resource);
}
/*  -------------------------------------------------------------------------
    zyre_pipe__zyre_resource_unbind

    Type: Component method
    Server-to-portal unbind.
    -------------------------------------------------------------------------
 */

static void
    zyre_pipe__zyre_resource_unbind (
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
    zyre_pipe__zyre_resource_link

    Type: Component method
    -------------------------------------------------------------------------
 */

static void *
    zyre_pipe__zyre_resource_link (
    void * object                       //  Reference cast as a void *
)
{

//
object = (void *) zyre_pipe_link (((zyre_pipe_t *) object));

    return (object);
}
/*  -------------------------------------------------------------------------
    zyre_pipe__zyre_resource_unlink

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_pipe__zyre_resource_unlink (
    void * object_p                     //  Reference pointer cast as a void *
)
{

//
zyre_pipe_unlink (((zyre_pipe_t **) object_p));
}
/*  -------------------------------------------------------------------------
    zyre_pipe_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_pipe_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    zyre_pipe_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <zyre_pipe zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
    if (self->history_last > ZYRE_PIPE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ZYRE_PIPE_HISTORY_LENGTH;
        self->history_last %= ZYRE_PIPE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ZYRE_PIPE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </zyre_pipe>\n");
#endif

}
/*  -------------------------------------------------------------------------
    zyre_pipe_destroy

    Type: Component method
    Destroys a zyre_pipe_t object. Takes the address of a
    zyre_pipe_t reference (a pointer to a pointer) and nullifies the
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
    zyre_pipe_destroy_ (
    zyre_pipe_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    zyre_pipe_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        zyre_pipe_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("zyre_pipe", "E: missing link on zyre_pipe object");
        zyre_pipe_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        zyre_pipe_free_ ((zyre_pipe_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    zyre_pipe_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static zyre_pipe_t *
    zyre_pipe_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    zyre_pipe_t *
        self = NULL;                    //  Object reference

self = (zyre_pipe_t *) icl_mem_alloc_ (sizeof (zyre_pipe_t), file, line);
if (self)
    memset (self, 0, sizeof (zyre_pipe_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_pipe_free

    Type: Component method
    Freess a zyre_pipe_t object.
    -------------------------------------------------------------------------
 */

static void
    zyre_pipe_free_ (
    zyre_pipe_t * self,                 //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ZYRE_PIPE_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (zyre_pipe_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (zyre_pipe_t));
        self->object_tag = ZYRE_PIPE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    zyre_pipe_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

zyre_pipe_t *
    zyre_pipe_link_ (
    zyre_pipe_t * self,                 //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
    int
        history_last;
#endif

    if (self) {
        ZYRE_PIPE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ZYRE_PIPE_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_pipe_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    zyre_pipe_unlink_ (
    zyre_pipe_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
    int
        history_last;
#endif

    zyre_pipe_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        ZYRE_PIPE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("zyre_pipe", "E: missing link on zyre_pipe object");
            zyre_pipe_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_PIPE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_PIPE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ZYRE_PIPE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            zyre_pipe_annihilate_ (self_p, file, line);
        zyre_pipe_free_ ((zyre_pipe_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    zyre_pipe_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    zyre_pipe_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

zyre_pipe_animating = enabled;
}
/*  -------------------------------------------------------------------------
    zyre_pipe_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_pipe_new_in_scope_ (
    zyre_pipe_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = zyre_pipe_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) zyre_pipe_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__zyre_pipe_version_start      = "VeRsIoNsTaRt:ipc";
char *EMBED__zyre_pipe_component          = "zyre_pipe ";
char *EMBED__zyre_pipe_version            = "1.0 ";
char *EMBED__zyre_pipe_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__zyre_pipe_filename           = "zyre_pipe.icl ";
char *EMBED__zyre_pipe_builddate          = "2010/10/06 ";
char *EMBED__zyre_pipe_version_end        = "VeRsIoNeNd:ipc";

