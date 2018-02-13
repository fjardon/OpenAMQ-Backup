/*---------------------------------------------------------------------------
    zyre_digest_amqp.c - zyre_digest_amqp component

    Refreshes expired or missing passwords using the protocol specified by
    the 8-Digest-AMQP@wiki.amqp.org specification.
    Generated from zyre_digest_amqp.icl by smt_object_gen using GSL/4.
    
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
#include "zyre_digest_amqp.h"           //  Definitions for our class

//  Shorthand for class type

#define self_t              zyre_digest_amqp_t

//  Shorthands for class methods

#define self_new            zyre_digest_amqp_new
#define self_annihilate     zyre_digest_amqp_annihilate
#define self_announce       zyre_digest_amqp_announce
#define self_before         zyre_digest_amqp_before
#define self_send_request   zyre_digest_amqp_send_request
#define self_online         zyre_digest_amqp_online
#define self_offline        zyre_digest_amqp_offline
#define self_arrived        zyre_digest_amqp_arrived
#define self_returned       zyre_digest_amqp_returned
#define self__zyre_backend_bind  zyre_digest_amqp__zyre_backend_bind
#define self__zyre_backend_unbind_shim  zyre_digest_amqp__zyre_backend_unbind_shim
#define self__zyre_backend_unbind  zyre_digest_amqp__zyre_backend_unbind
#define self_online_shim    zyre_digest_amqp_online_shim
#define self_offline_shim   zyre_digest_amqp_offline_shim
#define self_arrived_shim   zyre_digest_amqp_arrived_shim
#define self_returned_shim  zyre_digest_amqp_returned_shim
#define self_selftest       zyre_digest_amqp_selftest
#define self_initialise     zyre_digest_amqp_initialise
#define self_terminate      zyre_digest_amqp_terminate
#define self__http_access_module_new  zyre_digest_amqp__http_access_module_new
#define self__http_access_module_factory  zyre_digest_amqp__http_access_module_factory
#define self__http_access_module_unbind_shim  zyre_digest_amqp__http_access_module_unbind_shim
#define self__http_access_module_unbind  zyre_digest_amqp__http_access_module_unbind
#define self_announce_shim  zyre_digest_amqp_announce_shim
#define self_open_shim      zyre_digest_amqp_open_shim
#define self_open           zyre_digest_amqp_open
#define self_before_shim    zyre_digest_amqp_before_shim
#define self_after_shim     zyre_digest_amqp_after_shim
#define self_after          zyre_digest_amqp_after
#define self_close_shim     zyre_digest_amqp_close_shim
#define self_close          zyre_digest_amqp_close
#define self__http_access_module_link  zyre_digest_amqp__http_access_module_link
#define self__http_access_module_unlink  zyre_digest_amqp__http_access_module_unlink
#define self_destroy        zyre_digest_amqp_destroy
#define self_unlink         zyre_digest_amqp_unlink
#define self_show_animation  zyre_digest_amqp_show_animation
#define self_free           zyre_digest_amqp_free
#define self_show           zyre_digest_amqp_show
#define self_alloc          zyre_digest_amqp_alloc
#define self_link           zyre_digest_amqp_link
#define self_cache_initialise  zyre_digest_amqp_cache_initialise
#define self_cache_purge    zyre_digest_amqp_cache_purge
#define self_cache_terminate  zyre_digest_amqp_cache_terminate
#define self_new_in_scope   zyre_digest_amqp_new_in_scope

#define zyre_digest_amqp_annihilate(self)  zyre_digest_amqp_annihilate_ (self, __FILE__, __LINE__)
static int
    zyre_digest_amqp_annihilate_ (
zyre_digest_amqp_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    zyre_digest_amqp__zyre_backend_unbind_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal                 //  Portal reference
);

static int
    zyre_digest_amqp_online_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
char * reply_queue                      //  Not documented
);

static int
    zyre_digest_amqp_offline_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal                 //  Portal back to server
);

static int
    zyre_digest_amqp_arrived_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
zyre_peer_method_t * method             //  Not documented
);

static int
    zyre_digest_amqp_returned_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
zyre_peer_method_t * method             //  Not documented
);

static void
    zyre_digest_amqp_initialise (
void);

static void
    zyre_digest_amqp__http_access_module_unbind_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal           //  Portal reference
);

static int
    zyre_digest_amqp_announce_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
smt_log_t * log                         //  Not documented
);

static int
    zyre_digest_amqp_open_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static int
    zyre_digest_amqp_before_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static int
    zyre_digest_amqp_after_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static int
    zyre_digest_amqp_close_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static void *
    zyre_digest_amqp__http_access_module_link (
void * object                           //  Reference cast as a void *
);

static void
    zyre_digest_amqp__http_access_module_unlink (
void * object_p                         //  Reference pointer cast as a void *
);

#define zyre_digest_amqp_alloc()        zyre_digest_amqp_alloc_ (__FILE__, __LINE__)
static zyre_digest_amqp_t *
    zyre_digest_amqp_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    zyre_digest_amqp_cache_initialise (
void);

static void
    zyre_digest_amqp_cache_purge (
void);

static void
    zyre_digest_amqp_cache_terminate (
void);

Bool
    zyre_digest_amqp_animating = TRUE;  //  Animation enabled by default
static Bool
    s_zyre_digest_amqp_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_zyre_digest_amqp_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static ipr_looseref_list_t
    *s_http_access_module_list;         //  List of portal factories
static Bool
    s_http_access_module_stopped;       //  Is this portal factory stopped?
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_new

    Type: Component method
    Creates and initialises a new zyre_digest_amqp_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

zyre_digest_amqp_t *
    zyre_digest_amqp_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    zyre_digest_amqp_t *
        self = NULL;                    //  Object reference

if (!s_zyre_digest_amqp_active)
    self_initialise ();
    self = zyre_digest_amqp_alloc_ (file, line);
    if (self) {
        self->object_tag   = ZYRE_DIGEST_AMQP_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, zyre_digest_amqp_show_);
#endif

self->thread = zyre_digest_amqp_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->http_access_module_list = ipr_looseref_list_new ();

self->zyre_backend_list = ipr_looseref_list_new ();
self->zyre_backend_factory_list = ipr_looseref_list_new ();

self->backend = zyre_backend_amqp__zyre_backend_new (NULL);
zyre_digest_amqp__zyre_backend_bind (self, self->backend);
zyre_backend_request_start (self->backend);
}

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_digest_amqp_annihilate_ (
    zyre_digest_amqp_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
    int
        history_last;
#endif

    zyre_digest_amqp_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to zyre_digest_amqp agent");
        rc = -1;
    }
}
else
    rc = -1;

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_announce

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the announce incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp_announce (
    zyre_digest_amqp_t * self,          //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent_announce (self->thread,portal,log)) {
        //icl_console_print ("Error sending 'announce' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp_before

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the before incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp_before (
    zyre_digest_amqp_t * self,          //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

    if ((context->fail_code == IPR_PASSWORD_NOTFOUND
    ||   context->fail_code == IPR_PASSWORD_EXPIRED)
    &&  (context->digest && context->retries == 0)) {
        context->retries++;             //  Do exactly one retry, no more
        zyre_digest_amqp_send_request (self, context->fail_user, context->fail_realm);
        rc = HTTP_ACCESS_RETRY;         //  Server will retry afer 1 second
    }

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent_before (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'before' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp_send_request

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Sends a Digest-AMQP request to the backend.  The response is handled
    asynchronously by the arrived / returned methods.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp_send_request (
    zyre_digest_amqp_t * self,          //  Reference to object
    char *  user,                       //  Not documented
    char *  realm                       //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent_send_request (self->thread,user,realm)) {
        //icl_console_print ("Error sending 'send request' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp_online

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the online incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp_online (
    zyre_digest_amqp_t * self,          //  Reference to object
    zyre_backend_t * portal,            //  Portal back to server
    char * reply_queue                  //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent_online (self->thread,portal,reply_queue)) {
        //icl_console_print ("Error sending 'online' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp_offline

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the offline incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp_offline (
    zyre_digest_amqp_t * self,          //  Reference to object
    zyre_backend_t * portal             //  Portal back to server
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent_offline (self->thread,portal)) {
        //icl_console_print ("Error sending 'offline' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp_arrived

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the arrived incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp_arrived (
    zyre_digest_amqp_t * self,          //  Reference to object
    zyre_backend_t * portal,            //  Portal back to server
    zyre_peer_method_t * method         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent_arrived (self->thread,portal,method)) {
        //icl_console_print ("Error sending 'arrived' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp_returned

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the returned incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp_returned (
    zyre_digest_amqp_t * self,          //  Reference to object
    zyre_backend_t * portal,            //  Portal back to server
    zyre_peer_method_t * method         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent_returned (self->thread,portal,method)) {
        //icl_console_print ("Error sending 'returned' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp__zyre_backend_bind

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    Binds a zyre_backend portal, ready for use.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp__zyre_backend_bind (
    zyre_digest_amqp_t * self,          //  Reference to object
    zyre_backend_t * zyre_backend       //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
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
    zyre_digest_amqp__zyre_backend_unbind_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_digest_amqp__zyre_backend_unbind_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal             //  Portal reference
)
{

self__zyre_backend_unbind ((zyre_digest_amqp_t *) self_v, portal);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp__zyre_backend_unbind

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Client-to-portal unbind.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp__zyre_backend_unbind (
    zyre_digest_amqp_t * self,          //  Reference to object
    zyre_backend_t * portal             //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent__zyre_backend_unbind (self->thread,portal)) {
        //icl_console_print ("Error sending '_zyre_backend unbind' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp_online_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_digest_amqp_online_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    char * reply_queue                  //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_online ((zyre_digest_amqp_t *) self_v, portal, reply_queue);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_offline_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_digest_amqp_offline_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal             //  Portal back to server
)
{
    int
        rc = 0;                         //  Return code

rc = self_offline ((zyre_digest_amqp_t *) self_v, portal);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_arrived_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_digest_amqp_arrived_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    zyre_peer_method_t * method         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_arrived ((zyre_digest_amqp_t *) self_v, portal, method);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_returned_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_digest_amqp_returned_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    zyre_peer_method_t * method         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_returned ((zyre_digest_amqp_t *) self_v, portal, method);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_digest_amqp_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_digest_amqp_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_zyre_digest_amqp_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_zyre_digest_amqp_mutex)
            s_zyre_digest_amqp_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_zyre_digest_amqp_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_zyre_digest_amqp_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

zyre_digest_amqp_agent_init ();

s_http_access_module_list = ipr_looseref_list_new ();
            s_zyre_digest_amqp_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_zyre_digest_amqp_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_digest_amqp_terminate (
void)
{
http_access_module_t
    *http_access_module;            //  Portal factory object

if (s_zyre_digest_amqp_active) {

//
if (icl_atomic_cas32 ((volatile qbyte *) &s_http_access_module_stopped, TRUE, FALSE) == FALSE) {
    while ((http_access_module = (http_access_module_t *) ipr_looseref_pop (s_http_access_module_list))) {
        http_access_module->server_looseref = NULL;
        http_access_module_destroy (&http_access_module);
    }
}
ipr_looseref_list_destroy (&s_http_access_module_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_zyre_digest_amqp_mutex);
#endif
        s_zyre_digest_amqp_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp__http_access_module_new

    Type: Component method
    Creates and initialises a new portal instance.  If the server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    -------------------------------------------------------------------------
 */

http_access_module_t *
    zyre_digest_amqp__http_access_module_new (
    void * self_v                       //  Untyped server reference
)
{
zyre_digest_amqp_t
    *self;
    http_access_module_t *
        http_access_module;             //  Not documented

//
//  Grab a link to a new or the provided server object
if (self_v)
    self = self_link ((zyre_digest_amqp_t *) self_v);
else
    self = self_new ();

http_access_module = http_access_module_new (self, self__http_access_module_link, self__http_access_module_unlink);
http_access_module->server_looseref = ipr_looseref_queue (
    self->http_access_module_list, http_access_module_link (http_access_module));

//  Build virtual methods for server-side methods
http_access_module->server_unbind = self__http_access_module_unbind_shim;
http_access_module->request_announce = self_announce_shim;
http_access_module->request_open = self_open_shim;
http_access_module->request_before = self_before_shim;
http_access_module->request_after = self_after_shim;
http_access_module->request_close = self_close_shim;

//  Drop link to server object
self_unlink (&self);

    return (http_access_module);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp__http_access_module_factory

    Type: Component method
    Creates and initialises a new portal factory instance.
    -------------------------------------------------------------------------
 */

http_access_module_t *
    zyre_digest_amqp__http_access_module_factory (
void)
{
    http_access_module_t *
        http_access_module;             //  Not documented

//
if (!s_zyre_digest_amqp_active)
    self_initialise ();             //  Since we don't call zyre_digest_amqp_new
http_access_module = http_access_module_new (NULL, self__http_access_module_link, self__http_access_module_unlink);
http_access_module->server_looseref = ipr_looseref_queue (
    s_http_access_module_list, http_access_module_link (http_access_module));

//  Build virtual methods for server-side methods
http_access_module->server_new = self__http_access_module_new;

    return (http_access_module);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp__http_access_module_unbind_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_digest_amqp__http_access_module_unbind_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal       //  Portal reference
)
{

self__http_access_module_unbind ((zyre_digest_amqp_t *) self_v, portal);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp__http_access_module_unbind

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Server-to-portal unbind.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp__http_access_module_unbind (
    zyre_digest_amqp_t * self,          //  Reference to object
    http_access_module_t * portal       //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent__http_access_module_unbind (self->thread,portal)) {
        //icl_console_print ("Error sending '_http_access_module unbind' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp_announce_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_digest_amqp_announce_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_announce ((zyre_digest_amqp_t *) self_v, portal, log);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_open_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_digest_amqp_open_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_open ((zyre_digest_amqp_t *) self_v, portal, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_open

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the open incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp_open (
    zyre_digest_amqp_t * self,          //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent_open (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'open' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp_before_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_digest_amqp_before_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_before ((zyre_digest_amqp_t *) self_v, portal, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_after_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_digest_amqp_after_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_after ((zyre_digest_amqp_t *) self_v, portal, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_after

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the after incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp_after (
    zyre_digest_amqp_t * self,          //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent_after (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'after' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp_close_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_digest_amqp_close_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_close ((zyre_digest_amqp_t *) self_v, portal, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_close

    Type: Component method
    Accepts a zyre_digest_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the close incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp_close (
    zyre_digest_amqp_t * self,          //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_digest_amqp_agent_close (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'close' method to zyre_digest_amqp agent");
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
    zyre_digest_amqp__http_access_module_link

    Type: Component method
    -------------------------------------------------------------------------
 */

static void *
    zyre_digest_amqp__http_access_module_link (
    void * object                       //  Reference cast as a void *
)
{

//
object = (void *) zyre_digest_amqp_link (((zyre_digest_amqp_t *) object));

    return (object);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp__http_access_module_unlink

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_digest_amqp__http_access_module_unlink (
    void * object_p                     //  Reference pointer cast as a void *
)
{

//
zyre_digest_amqp_unlink (((zyre_digest_amqp_t **) object_p));
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_digest_amqp_destroy_ (
    zyre_digest_amqp_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    zyre_digest_amqp_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = zyre_digest_amqp_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        zyre_digest_amqp_free (self);
    *self_p = NULL;
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    zyre_digest_amqp_unlink_ (
    zyre_digest_amqp_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
    int
        history_last;
#endif
    zyre_digest_amqp_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on zyre_digest_amqp object");
            zyre_digest_amqp_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                zyre_digest_amqp_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                zyre_digest_amqp_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    zyre_digest_amqp_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

zyre_digest_amqp_animating = enabled;

zyre_digest_amqp_agent_animate (enabled);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_free

    Type: Component method
    Freess a zyre_digest_amqp_t object.
    -------------------------------------------------------------------------
 */

void
    zyre_digest_amqp_free_ (
    zyre_digest_amqp_t * self,          //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (zyre_digest_amqp_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (zyre_digest_amqp_t));
        self->object_tag = ZYRE_DIGEST_AMQP_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_digest_amqp_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    zyre_digest_amqp_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <zyre_digest_amqp zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
    if (self->history_last > ZYRE_DIGEST_AMQP_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ZYRE_DIGEST_AMQP_HISTORY_LENGTH;
        self->history_last %= ZYRE_DIGEST_AMQP_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ZYRE_DIGEST_AMQP_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </zyre_digest_amqp>\n");
#endif

}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static zyre_digest_amqp_t *
    zyre_digest_amqp_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    zyre_digest_amqp_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    zyre_digest_amqp_cache_initialise ();

self = (zyre_digest_amqp_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (zyre_digest_amqp_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

zyre_digest_amqp_t *
    zyre_digest_amqp_link_ (
    zyre_digest_amqp_t * self,          //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
    int
        history_last;
#endif

    if (self) {
        ZYRE_DIGEST_AMQP_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_DIGEST_AMQP)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ZYRE_DIGEST_AMQP_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    zyre_digest_amqp_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (zyre_digest_amqp_t));
icl_system_register (zyre_digest_amqp_cache_purge, zyre_digest_amqp_cache_terminate);
}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_digest_amqp_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_digest_amqp_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    zyre_digest_amqp_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_digest_amqp_new_in_scope_ (
    zyre_digest_amqp_t * * self_p,      //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = zyre_digest_amqp_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) zyre_digest_amqp_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__zyre_digest_amqp_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__zyre_digest_amqp_component   = "zyre_digest_amqp ";
char *EMBED__zyre_digest_amqp_version     = "0.0 ";
char *EMBED__zyre_digest_amqp_copyright   = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__zyre_digest_amqp_filename    = "zyre_digest_amqp.icl ";
char *EMBED__zyre_digest_amqp_builddate   = "2010/10/06 ";
char *EMBED__zyre_digest_amqp_version_end  = "VeRsIoNeNd:ipc";

