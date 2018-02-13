/*---------------------------------------------------------------------------
    zyre_restms.c - zyre_restms component

    This class implements a HTTP plugin that maps RestMS requests to AMQP.
    The plugin acts as a portal backend for the Base2/HTTP server.  This
    is an async class that manages a data tree of feeds, pipes, and joins.
    It communicates changes to this tree to the AMQP backend agent, which
    handles all communications with the AMQP server.  Incoming AMQP messages
    arrive via the backend portal.  All RestMS work is done by a single
    object in this class, so a single thread.  This limits the workload to
    around 300,000 transactions per second, which is the speedlimit of one
    threadlet (SMT thread queue limitation).
    Generated from zyre_restms.icl by smt_object_gen using GSL/4.
    
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
#include "zyre_restms.h"                //  Definitions for our class

//  Shorthand for class type

#define self_t              zyre_restms_t

//  Shorthands for class methods

#define self_new            zyre_restms_new
#define self_annihilate     zyre_restms_annihilate
#define self_announce       zyre_restms_announce
#define self_get            zyre_restms_get
#define self_put            zyre_restms_put
#define self_delete         zyre_restms_delete
#define self_post           zyre_restms_post
#define self_head           zyre_restms_head
#define self_move           zyre_restms_move
#define self_copy           zyre_restms_copy
#define self_online         zyre_restms_online
#define self_offline        zyre_restms_offline
#define self_arrived        zyre_restms_arrived
#define self_returned       zyre_restms_returned
#define self_child_add      zyre_restms_child_add
#define self_check_path     zyre_restms_check_path
#define self_parse_document  zyre_restms_parse_document
#define self_selftest       zyre_restms_selftest
#define self__zyre_resource_bind  zyre_restms__zyre_resource_bind
#define self__zyre_resource_unbind  zyre_restms__zyre_resource_unbind
#define self__zyre_backend_bind  zyre_restms__zyre_backend_bind
#define self__zyre_backend_unbind_shim  zyre_restms__zyre_backend_unbind_shim
#define self__zyre_backend_unbind  zyre_restms__zyre_backend_unbind
#define self_online_shim    zyre_restms_online_shim
#define self_offline_shim   zyre_restms_offline_shim
#define self_arrived_shim   zyre_restms_arrived_shim
#define self_returned_shim  zyre_restms_returned_shim
#define self_initialise     zyre_restms_initialise
#define self_terminate      zyre_restms_terminate
#define self__http_driver_module_new  zyre_restms__http_driver_module_new
#define self__http_driver_module_factory  zyre_restms__http_driver_module_factory
#define self__http_driver_module_unbind_shim  zyre_restms__http_driver_module_unbind_shim
#define self__http_driver_module_unbind  zyre_restms__http_driver_module_unbind
#define self_announce_shim  zyre_restms_announce_shim
#define self_get_shim       zyre_restms_get_shim
#define self_head_shim      zyre_restms_head_shim
#define self_post_shim      zyre_restms_post_shim
#define self_put_shim       zyre_restms_put_shim
#define self_delete_shim    zyre_restms_delete_shim
#define self_move_shim      zyre_restms_move_shim
#define self_copy_shim      zyre_restms_copy_shim
#define self__http_driver_module_link  zyre_restms__http_driver_module_link
#define self__http_driver_module_unlink  zyre_restms__http_driver_module_unlink
#define self_destroy        zyre_restms_destroy
#define self_unlink         zyre_restms_unlink
#define self_show_animation  zyre_restms_show_animation
#define self_free           zyre_restms_free
#define self_show           zyre_restms_show
#define self_alloc          zyre_restms_alloc
#define self_link           zyre_restms_link
#define self_cache_initialise  zyre_restms_cache_initialise
#define self_cache_purge    zyre_restms_cache_purge
#define self_cache_terminate  zyre_restms_cache_terminate
#define self_new_in_scope   zyre_restms_new_in_scope

#define zyre_restms_annihilate(self)    zyre_restms_annihilate_ (self, __FILE__, __LINE__)
static int
    zyre_restms_annihilate_ (
zyre_restms_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static int
    zyre_restms_child_add (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal,               //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static void
    zyre_restms__zyre_resource_unbind (
void * self_v,                          //  Self as void pointer
zyre_resource_t * portal                //  Portal reference
);

static void
    zyre_restms__zyre_backend_unbind_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal                 //  Portal reference
);

static int
    zyre_restms_online_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
char * reply_queue                      //  Not documented
);

static int
    zyre_restms_offline_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal                 //  Portal back to server
);

static int
    zyre_restms_arrived_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
zyre_peer_method_t * method             //  Not documented
);

static int
    zyre_restms_returned_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
zyre_peer_method_t * method             //  Not documented
);

static void
    zyre_restms_initialise (
void);

static void
    zyre_restms__http_driver_module_unbind_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal           //  Portal reference
);

static int
    zyre_restms_announce_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
smt_log_t * log                         //  Not documented
);

static int
    zyre_restms_get_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    zyre_restms_head_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    zyre_restms_post_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    zyre_restms_put_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    zyre_restms_delete_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    zyre_restms_move_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    zyre_restms_copy_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static void *
    zyre_restms__http_driver_module_link (
void * object                           //  Reference cast as a void *
);

static void
    zyre_restms__http_driver_module_unlink (
void * object_p                         //  Reference pointer cast as a void *
);

#define zyre_restms_alloc()             zyre_restms_alloc_ (__FILE__, __LINE__)
static zyre_restms_t *
    zyre_restms_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    zyre_restms_cache_initialise (
void);

static void
    zyre_restms_cache_purge (
void);

static void
    zyre_restms_cache_terminate (
void);

Bool
    zyre_restms_animating = TRUE;       //  Animation enabled by default
static Bool
    s_zyre_restms_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_zyre_restms_mutex      = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static ipr_looseref_list_t
    *s_http_driver_module_list;         //  List of portal factories
static Bool
    s_http_driver_module_stopped;       //  Is this portal factory stopped?
/*  -------------------------------------------------------------------------
    zyre_restms_new

    Type: Component method
    Creates and initialises a new zyre_restms_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

zyre_restms_t *
    zyre_restms_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
zyre_resource_t
    *domain,
    *feed;
    zyre_restms_t *
        self = NULL;                    //  Object reference

if (!s_zyre_restms_active)
    self_initialise ();
    self = zyre_restms_alloc_ (file, line);
    if (self) {
        self->object_tag   = ZYRE_RESTMS_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, zyre_restms_show_);
#endif

self->thread = zyre_restms_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->http_driver_module_list = ipr_looseref_list_new ();

self->zyre_backend_list = ipr_looseref_list_new ();
self->zyre_backend_factory_list = ipr_looseref_list_new ();

self->zyre_resource_list = ipr_looseref_list_new ();
self->zyre_resource_factory_list = ipr_looseref_list_new ();

//
self->resources = ipr_hash_table_new ();
self->backend = zyre_backend_amqp__zyre_backend_new (NULL);
zyre_restms__zyre_backend_bind (self, self->backend);
zyre_backend_request_start (self->backend);

//  Create domain resource
domain = zyre_domain__zyre_resource_new (NULL,
    NULL, self->resources, "domain", "default");
zyre_restms__zyre_resource_bind (self, domain);

//  Create default feed
feed = zyre_feed__zyre_resource_new (NULL,
    domain, self->resources, "feed", "default");
zyre_restms__zyre_resource_bind (self, feed);
zyre_resource_request_configure (feed, NULL, self->resources, self->backend);

zyre_resource_unlink (&feed);
zyre_resource_unlink (&domain);
}

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_restms_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_annihilate_ (
    zyre_restms_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
    int
        history_last;
#endif

zyre_resource_t
    *zyre_resource;                 //  Portal object
    zyre_restms_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = self->links;
#endif


    //
    if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_resource_stopped, TRUE, FALSE) == FALSE) {
        //  Destroy own portals
        while ((zyre_resource = (zyre_resource_t *) ipr_looseref_pop (self->zyre_resource_list))) {
            zyre_resource->client_looseref = NULL;
            zyre_resource_destroy (&zyre_resource);
        }
        ipr_looseref_list_destroy (&self->zyre_resource_list);
        //  Destroy own portal factories
        while ((zyre_resource = (zyre_resource_t *) ipr_looseref_pop (self->zyre_resource_factory_list))) {
            zyre_resource->client_looseref = NULL;
            zyre_resource_destroy (&zyre_resource);
        }
        ipr_looseref_list_destroy (&self->zyre_resource_factory_list);
    }

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to zyre_restms agent");
        rc = -1;
    }
}
else
    rc = -1;

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_announce

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the announce incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_announce (
    zyre_restms_t * self,               //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_announce (self->thread,portal,log)) {
        //icl_console_print ("Error sending 'announce' method to zyre_restms agent");
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
    zyre_restms_get

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the get incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_get (
    zyre_restms_t * self,               //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_get (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'get' method to zyre_restms agent");
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
    zyre_restms_put

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the put incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_put (
    zyre_restms_t * self,               //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_put (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'put' method to zyre_restms agent");
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
    zyre_restms_delete

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_delete (
    zyre_restms_t * self,               //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_delete (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'delete' method to zyre_restms agent");
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
    zyre_restms_post

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the post incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_post (
    zyre_restms_t * self,               //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_post (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'post' method to zyre_restms agent");
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
    zyre_restms_head

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the head incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_head (
    zyre_restms_t * self,               //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_head (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'head' method to zyre_restms agent");
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
    zyre_restms_move

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the move incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_move (
    zyre_restms_t * self,               //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_move (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'move' method to zyre_restms agent");
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
    zyre_restms_copy

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the copy incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_copy (
    zyre_restms_t * self,               //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_copy (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'copy' method to zyre_restms agent");
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
    zyre_restms_online

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the online incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_online (
    zyre_restms_t * self,               //  Reference to object
    zyre_backend_t * portal,            //  Portal back to server
    char * reply_queue                  //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_online (self->thread,portal,reply_queue)) {
        //icl_console_print ("Error sending 'online' method to zyre_restms agent");
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
    zyre_restms_offline

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the offline incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_offline (
    zyre_restms_t * self,               //  Reference to object
    zyre_backend_t * portal             //  Portal back to server
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_offline (self->thread,portal)) {
        //icl_console_print ("Error sending 'offline' method to zyre_restms agent");
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
    zyre_restms_arrived

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the arrived incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_arrived (
    zyre_restms_t * self,               //  Reference to object
    zyre_backend_t * portal,            //  Portal back to server
    zyre_peer_method_t * method         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_arrived (self->thread,portal,method)) {
        //icl_console_print ("Error sending 'arrived' method to zyre_restms agent");
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
    zyre_restms_returned

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    This is the returned incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_returned (
    zyre_restms_t * self,               //  Reference to object
    zyre_backend_t * portal,            //  Portal back to server
    zyre_peer_method_t * method         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent_returned (self->thread,portal,method)) {
        //icl_console_print ("Error sending 'returned' method to zyre_restms agent");
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
    zyre_restms_child_add

    Type: Component method
    This is the child add incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    Creates a resource from an XML document.  Classes that create resources
    in other ways have to do the hard work themselves.
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_child_add (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal,           //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
zyre_restms_t
    *self;
char
    *type;                          //  Resource type from XML
zyre_resource_t
    *resource = NULL;
    int
        rc = 0;                         //  Return code

self = (zyre_restms_t *) self_v;
//
//  Clean up the name and build resource path
type = ipr_xml_name (context->xml_item);

//  We create the resource and the server object instance
//  The portal that called us is the parent of this new resource
if (streq (type, "feed"))
    resource = zyre_feed__zyre_resource_new (NULL, portal, self->resources, type,
        ipr_xml_attr_get (context->xml_item, "name", ""));
else
if (streq (type, "pipe"))
    //  For pipes we ignore the name attribute
    resource = zyre_pipe__zyre_resource_new (NULL, portal, self->resources, type, "");
else
if (streq (type, "join"))
    //  For joins we ignore the name attribute
    resource = zyre_join__zyre_resource_new (NULL, portal, self->resources, type, "");
else {
    icl_console_print ("E: not implemented: %s", type);
    assert (FALSE);
}
zyre_restms__zyre_resource_bind (self, resource);

//  resource->hash is null if resource already existed with same path
if (resource->hash) {
    //  Configure action must be safe, all checking has already been done
    zyre_resource_request_configure (resource, context, self->resources, self->backend);
    if (context->failed) {
        icl_console_print ("Configure action may not raise an error");
        assert (FALSE);
    }
    context->response->reply_code = HTTP_REPLY_CREATED;
}
else {
    //  Destroy the duplicate resource and grab the real one so we can
    //  report it back to the client application
    zyre_resource_t
        *actual;
    actual = ipr_hash_lookup (self->resources, resource->path);
    assert (actual);
    zyre_resource_destroy (&resource);
    resource = zyre_resource_link (actual);
}
if (!context->failed) {
    //  Set Location: header to new or existing resource
    http_response_set_header (context->response, "location",
        "%s%s%s", context->response->root_uri, RESTMS_ROOT, resource->path);

    //  Use the Content-Type of the posted document for our response
    http_response_set_content_type (context->response,
        http_request_get_header (context->request, "content-type"));

    //  Get resource description for client
    zyre_resource_request_get (resource, context);
}
//  We drop our link to the resource so that it is automatically
//  destroyed when this object is destroyed, and we don't need to
//  do anything further.  If we want to prematurely destroy the
//  resource we'll need to grab a link back.
zyre_resource_unlink (&resource);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_check_path

    Type: Component method
    From the current HTTP context, parses the pathinfo and returns an HTTP
    error reply if the pathinfo is not valid.  In that case, returns -1.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_check_path (
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Not documented

//
//  path must be start with /{resource-type}/ or /resource/
if (!ipr_str_prefixed (context->request->pathinfo, "/domain/")
&&  !ipr_str_prefixed (context->request->pathinfo, "/feed/")
&&  !ipr_str_prefixed (context->request->pathinfo, "/pipe/")
&&  !ipr_str_prefixed (context->request->pathinfo, "/resource/")) {
    http_driver_context_reply_error (context, HTTP_REPLY_BADREQUEST,
        "URI path does not refer to a RestMS resource");
    rc = -1;
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_parse_document

    Type: Component method
    From the current HTTP context, parses the document and sets the context
    xml_root and xml_item properties.  If the required_type is specified, the
    document must have this type.
    -------------------------------------------------------------------------
 */

int
    zyre_restms_parse_document (
    http_driver_context_t * context,    //  Not documented
    char * required                     //  Required resource type
)
{
    int
        rc = 0;                         //  Not documented

//
//  We accept only "application/restms+xml"
//  JSON support will come later
if (streq (context->request->content_type, "application/restms+xml"))
    rc = http_driver_context_xml_parse (context, RESTMS_ROOT, required);
else {
    http_driver_context_reply_error (context, HTTP_REPLY_BADREQUEST,
        "Content-Type must be 'application/restms+xml'");
    rc = -1;
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_restms_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    zyre_restms__zyre_resource_bind

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    Binds a zyre_resource portal, ready for use. This method is for use
    outside the zyre_resource class.
    -------------------------------------------------------------------------
 */

int
    zyre_restms__zyre_resource_bind (
    zyre_restms_t * self,               //  Reference to object
    zyre_resource_t * zyre_resource     //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

//
zyre_resource->client_object = self;
if (zyre_resource->server_object)
    zyre_resource->client_looseref = ipr_looseref_queue (
        self->zyre_resource_list, zyre_resource_link (zyre_resource));
else                                //  server_object is null for factories
    zyre_resource->client_looseref = ipr_looseref_queue (
        self->zyre_resource_factory_list, zyre_resource_link (zyre_resource));

//  Build virtual function table for client-side methods
zyre_resource->client_unbind = self__zyre_resource_unbind;
zyre_resource->response_child_add = self_child_add;

//  Signal that portal is ready for use
zyre_resource_ready (zyre_resource);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms__zyre_resource_unbind

    Type: Component method
    Client-to-portal unbind.
    -------------------------------------------------------------------------
 */

static void
    zyre_restms__zyre_resource_unbind (
    void * self_v,                      //  Self as void pointer
    zyre_resource_t * portal            //  Portal reference
)
{

//
//  Drop link to portal and remove portal from our list of active portals
if (portal->client_looseref) {
    ipr_looseref_destroy (&portal->client_looseref);
    zyre_resource_unlink (&portal);
}
}
/*  -------------------------------------------------------------------------
    zyre_restms__zyre_backend_bind

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    Binds a zyre_backend portal, ready for use.
    -------------------------------------------------------------------------
 */

int
    zyre_restms__zyre_backend_bind (
    zyre_restms_t * self,               //  Reference to object
    zyre_backend_t * zyre_backend       //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

//
zyre_backend->client_object = self;
if (zyre_backend->server_object)
    zyre_backend->client_looseref = ipr_looseref_queue (
        self->zyre_backend_list, zyre_backend_link (zyre_backend));
else                                //  server_object is null for factories
    zyre_backend->client_looseref = ipr_looseref_queue (
        self->zyre_backend_factory_list, zyre_backend_link (zyre_backend));

//  Build virtual function table for client-side methods
zyre_backend->client_unbind = self__zyre_backend_unbind_shim;
zyre_backend->response_online = self_online_shim;
zyre_backend->response_offline = self_offline_shim;
zyre_backend->response_arrived = self_arrived_shim;
zyre_backend->response_returned = self_returned_shim;

//  Signal that portal is ready for use
zyre_backend_ready (zyre_backend);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms__zyre_backend_unbind_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_restms__zyre_backend_unbind_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal             //  Portal reference
)
{

self__zyre_backend_unbind ((zyre_restms_t *) self_v, portal);
}
/*  -------------------------------------------------------------------------
    zyre_restms__zyre_backend_unbind

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Client-to-portal unbind.
    -------------------------------------------------------------------------
 */

int
    zyre_restms__zyre_backend_unbind (
    zyre_restms_t * self,               //  Reference to object
    zyre_backend_t * portal             //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_restms_agent__zyre_backend_unbind (self->thread,portal)) {
        //icl_console_print ("Error sending '_zyre_backend unbind' method to zyre_restms agent");
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
    zyre_restms_online_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_online_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    char * reply_queue                  //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_online ((zyre_restms_t *) self_v, portal, reply_queue);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_offline_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_offline_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal             //  Portal back to server
)
{
    int
        rc = 0;                         //  Return code

rc = self_offline ((zyre_restms_t *) self_v, portal);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_arrived_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_arrived_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    zyre_peer_method_t * method         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_arrived ((zyre_restms_t *) self_v, portal, method);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_returned_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_returned_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    zyre_peer_method_t * method         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_returned ((zyre_restms_t *) self_v, portal, method);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_restms_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_zyre_restms_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_zyre_restms_mutex)
            s_zyre_restms_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_zyre_restms_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_zyre_restms_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

zyre_restms_agent_init ();

s_http_driver_module_list = ipr_looseref_list_new ();
            s_zyre_restms_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_zyre_restms_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    zyre_restms_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_restms_terminate (
void)
{
http_driver_module_t
    *http_driver_module;            //  Portal factory object

if (s_zyre_restms_active) {

//
if (icl_atomic_cas32 ((volatile qbyte *) &s_http_driver_module_stopped, TRUE, FALSE) == FALSE) {
    while ((http_driver_module = (http_driver_module_t *) ipr_looseref_pop (s_http_driver_module_list))) {
        http_driver_module->server_looseref = NULL;
        http_driver_module_destroy (&http_driver_module);
    }
}
ipr_looseref_list_destroy (&s_http_driver_module_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_zyre_restms_mutex);
#endif
        s_zyre_restms_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    zyre_restms__http_driver_module_new

    Type: Component method
    Creates and initialises a new portal instance.  If the server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    -------------------------------------------------------------------------
 */

http_driver_module_t *
    zyre_restms__http_driver_module_new (
    void * self_v,                      //  Untyped server reference
    char * path                         //  Not documented
)
{
zyre_restms_t
    *self;
    http_driver_module_t *
        http_driver_module;             //  Not documented

//
//  Grab a link to a new or the provided server object
if (self_v)
    self = self_link ((zyre_restms_t *) self_v);
else
    self = self_new ();

http_driver_module = http_driver_module_new (self, self__http_driver_module_link, self__http_driver_module_unlink, path);
http_driver_module->server_looseref = ipr_looseref_queue (
    self->http_driver_module_list, http_driver_module_link (http_driver_module));

//  Build virtual methods for server-side methods
http_driver_module->server_unbind = self__http_driver_module_unbind_shim;
http_driver_module->request_announce = self_announce_shim;
http_driver_module->request_get = self_get_shim;
http_driver_module->request_head = self_head_shim;
http_driver_module->request_post = self_post_shim;
http_driver_module->request_put = self_put_shim;
http_driver_module->request_delete = self_delete_shim;
http_driver_module->request_move = self_move_shim;
http_driver_module->request_copy = self_copy_shim;

//  Drop link to server object
self_unlink (&self);

    return (http_driver_module);
}
/*  -------------------------------------------------------------------------
    zyre_restms__http_driver_module_factory

    Type: Component method
    Creates and initialises a new portal factory instance.
    -------------------------------------------------------------------------
 */

http_driver_module_t *
    zyre_restms__http_driver_module_factory (
    char * path                         //  Not documented
)
{
    http_driver_module_t *
        http_driver_module;             //  Not documented

//
if (!s_zyre_restms_active)
    self_initialise ();             //  Since we don't call zyre_restms_new
http_driver_module = http_driver_module_new (NULL, self__http_driver_module_link, self__http_driver_module_unlink, path);
http_driver_module->server_looseref = ipr_looseref_queue (
    s_http_driver_module_list, http_driver_module_link (http_driver_module));

//  Build virtual methods for server-side methods
http_driver_module->server_new = self__http_driver_module_new;

    return (http_driver_module);
}
/*  -------------------------------------------------------------------------
    zyre_restms__http_driver_module_unbind_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_restms__http_driver_module_unbind_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal       //  Portal reference
)
{

self__http_driver_module_unbind ((zyre_restms_t *) self_v, portal);
}
/*  -------------------------------------------------------------------------
    zyre_restms__http_driver_module_unbind

    Type: Component method
    Accepts a zyre_restms_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Server-to-portal unbind.
    -------------------------------------------------------------------------
 */

int
    zyre_restms__http_driver_module_unbind (
    zyre_restms_t * self,               //  Reference to object
    http_driver_module_t * portal       //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESTMS_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (zyre_restms_agent__http_driver_module_unbind (self->thread,portal)) {
        //icl_console_print ("Error sending '_http_driver_module unbind' method to zyre_restms agent");
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
    zyre_restms_announce_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_announce_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_announce ((zyre_restms_t *) self_v, portal, log);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_get_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_get_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_get ((zyre_restms_t *) self_v, portal, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_head_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_head_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_head ((zyre_restms_t *) self_v, portal, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_post_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_post_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_post ((zyre_restms_t *) self_v, portal, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_put_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_put_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_put ((zyre_restms_t *) self_v, portal, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_delete_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_delete_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_delete ((zyre_restms_t *) self_v, portal, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_move_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_move_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_move ((zyre_restms_t *) self_v, portal, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_copy_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_restms_copy_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_copy ((zyre_restms_t *) self_v, portal, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms__http_driver_module_link

    Type: Component method
    -------------------------------------------------------------------------
 */

static void *
    zyre_restms__http_driver_module_link (
    void * object                       //  Reference cast as a void *
)
{

//
object = (void *) zyre_restms_link (((zyre_restms_t *) object));

    return (object);
}
/*  -------------------------------------------------------------------------
    zyre_restms__http_driver_module_unlink

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_restms__http_driver_module_unlink (
    void * object_p                     //  Reference pointer cast as a void *
)
{

//
zyre_restms_unlink (((zyre_restms_t **) object_p));
}
/*  -------------------------------------------------------------------------
    zyre_restms_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_restms_destroy_ (
    zyre_restms_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    zyre_restms_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = zyre_restms_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        zyre_restms_free (self);
    *self_p = NULL;
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_restms_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    zyre_restms_unlink_ (
    zyre_restms_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
    int
        history_last;
#endif
    zyre_restms_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on zyre_restms object");
            zyre_restms_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                zyre_restms_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                zyre_restms_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
}
/*  -------------------------------------------------------------------------
    zyre_restms_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    zyre_restms_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

zyre_restms_animating = enabled;

zyre_restms_agent_animate (enabled);
}
/*  -------------------------------------------------------------------------
    zyre_restms_free

    Type: Component method
    Freess a zyre_restms_t object.
    -------------------------------------------------------------------------
 */

void
    zyre_restms_free_ (
    zyre_restms_t * self,               //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (zyre_restms_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (zyre_restms_t));
        self->object_tag = ZYRE_RESTMS_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    zyre_restms_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_restms_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    zyre_restms_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <zyre_restms zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
    if (self->history_last > ZYRE_RESTMS_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ZYRE_RESTMS_HISTORY_LENGTH;
        self->history_last %= ZYRE_RESTMS_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ZYRE_RESTMS_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </zyre_restms>\n");
#endif

}
/*  -------------------------------------------------------------------------
    zyre_restms_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static zyre_restms_t *
    zyre_restms_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    zyre_restms_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    zyre_restms_cache_initialise ();

self = (zyre_restms_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (zyre_restms_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_restms_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

zyre_restms_t *
    zyre_restms_link_ (
    zyre_restms_t * self,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
    int
        history_last;
#endif

    if (self) {
        ZYRE_RESTMS_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESTMS)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ZYRE_RESTMS_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_restms_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    zyre_restms_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (zyre_restms_t));
icl_system_register (zyre_restms_cache_purge, zyre_restms_cache_terminate);
}
/*  -------------------------------------------------------------------------
    zyre_restms_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_restms_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    zyre_restms_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_restms_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    zyre_restms_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_restms_new_in_scope_ (
    zyre_restms_t * * self_p,           //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = zyre_restms_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) zyre_restms_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__zyre_restms_version_start    = "VeRsIoNsTaRt:ipc";
char *EMBED__zyre_restms_component        = "zyre_restms ";
char *EMBED__zyre_restms_version          = "1.0 ";
char *EMBED__zyre_restms_copyright        = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__zyre_restms_filename         = "zyre_restms.icl ";
char *EMBED__zyre_restms_builddate        = "2010/10/06 ";
char *EMBED__zyre_restms_version_end      = "VeRsIoNeNd:ipc";

