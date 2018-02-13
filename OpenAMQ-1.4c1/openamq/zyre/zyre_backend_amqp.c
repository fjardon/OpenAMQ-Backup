/*---------------------------------------------------------------------------
    zyre_backend_amqp.c - zyre_backend_amqp component

Backend module that talks to an OpenAMQ server, originally based on
the amq_peering class, but modified to work with IPR portals and to
implement the RestMS data model.

This module implementation replicates the state used by the Zyre RestMS
server.  Namely:

  * A set of feeds, pipes, and joins, implemented on the AMQP server as
    exchanges, queues, bindings, and consumers.  This peering class is the
    place where the mapping from RestMS to AMQP is defined in detail.

  * A queue of messages waiting to be published to the AMQP server.

The peering isolates the application from the AMQP server, allowing the
state to be updated asynchronously from any connection.  That is, before
a connection is made, while a connection is active, or when a connection
has died and is being brought back.

Lastly, the peering will invoke callback methods to tell you when the peer
link becomes active, and when a message content arrives.
    Generated from zyre_backend_amqp.icl by smt_object_gen using GSL/4.
    
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
#include "zyre_backend_amqp.h"          //  Definitions for our class

//  Shorthand for class type

#define self_t              zyre_backend_amqp_t

//  Shorthands for class methods

#define self_new            zyre_backend_amqp_new
#define self_annihilate     zyre_backend_amqp_annihilate
#define self_start          zyre_backend_amqp_start
#define self_stop           zyre_backend_amqp_stop
#define self_pipe_create    zyre_backend_amqp_pipe_create
#define self_pipe_delete    zyre_backend_amqp_pipe_delete
#define self_feed_create    zyre_backend_amqp_feed_create
#define self_feed_delete    zyre_backend_amqp_feed_delete
#define self_join_create    zyre_backend_amqp_join_create
#define self_join_delete    zyre_backend_amqp_join_delete
#define self_address_post   zyre_backend_amqp_address_post
#define self_forward        zyre_backend_amqp_forward
#define self_online_partial  zyre_backend_amqp_online_partial
#define self_online_final   zyre_backend_amqp_online_final
#define self_initialise     zyre_backend_amqp_initialise
#define self_terminate      zyre_backend_amqp_terminate
#define self_selftest       zyre_backend_amqp_selftest
#define self__zyre_backend_new  zyre_backend_amqp__zyre_backend_new
#define self__zyre_backend_factory  zyre_backend_amqp__zyre_backend_factory
#define self__zyre_backend_unbind_shim  zyre_backend_amqp__zyre_backend_unbind_shim
#define self__zyre_backend_unbind  zyre_backend_amqp__zyre_backend_unbind
#define self_start_shim     zyre_backend_amqp_start_shim
#define self_stop_shim      zyre_backend_amqp_stop_shim
#define self_pipe_create_shim  zyre_backend_amqp_pipe_create_shim
#define self_pipe_delete_shim  zyre_backend_amqp_pipe_delete_shim
#define self_feed_create_shim  zyre_backend_amqp_feed_create_shim
#define self_feed_delete_shim  zyre_backend_amqp_feed_delete_shim
#define self_join_create_shim  zyre_backend_amqp_join_create_shim
#define self_join_delete_shim  zyre_backend_amqp_join_delete_shim
#define self_address_post_shim  zyre_backend_amqp_address_post_shim
#define self_forward_shim   zyre_backend_amqp_forward_shim
#define self_online_partial_shim  zyre_backend_amqp_online_partial_shim
#define self_online_final_shim  zyre_backend_amqp_online_final_shim
#define self__zyre_backend_link  zyre_backend_amqp__zyre_backend_link
#define self__zyre_backend_unlink  zyre_backend_amqp__zyre_backend_unlink
#define self_destroy        zyre_backend_amqp_destroy
#define self_unlink         zyre_backend_amqp_unlink
#define self_show_animation  zyre_backend_amqp_show_animation
#define self_free           zyre_backend_amqp_free
#define self_show           zyre_backend_amqp_show
#define self_alloc          zyre_backend_amqp_alloc
#define self_link           zyre_backend_amqp_link
#define self_cache_initialise  zyre_backend_amqp_cache_initialise
#define self_cache_purge    zyre_backend_amqp_cache_purge
#define self_cache_terminate  zyre_backend_amqp_cache_terminate
#define self_new_in_scope   zyre_backend_amqp_new_in_scope

#define zyre_backend_amqp_annihilate(self)  zyre_backend_amqp_annihilate_ (self, __FILE__, __LINE__)
static int
    zyre_backend_amqp_annihilate_ (
zyre_backend_amqp_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    zyre_backend_amqp_initialise (
void);

static void
    zyre_backend_amqp__zyre_backend_unbind_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal                 //  Portal reference
);

static int
    zyre_backend_amqp_start_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal                 //  Portal back to server
);

static int
    zyre_backend_amqp_stop_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal                 //  Portal back to server
);

static int
    zyre_backend_amqp_pipe_create_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
char * pipe_type,                       //  Not documented
char * pipe_name                        //  Not documented
);

static int
    zyre_backend_amqp_pipe_delete_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
char * pipe_name                        //  Not documented
);

static int
    zyre_backend_amqp_feed_create_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
char * feed_type,                       //  Not documented
char * feed_name                        //  Not documented
);

static int
    zyre_backend_amqp_feed_delete_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
char * feed_name                        //  Not documented
);

static int
    zyre_backend_amqp_join_create_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
char * pipe_name,                       //  Not documented
char * feed_name,                       //  Not documented
char * address                          //  Not documented
);

static int
    zyre_backend_amqp_join_delete_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
char * pipe_name,                       //  Not documented
char * feed_name,                       //  Not documented
char * address                          //  Not documented
);

static int
    zyre_backend_amqp_address_post_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
char * address,                         //  Not documented
char * feed_name,                       //  Not documented
amq_content_basic_t * content           //  Not documented
);

static int
    zyre_backend_amqp_forward_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal,                //  Portal back to server
char * exchange,                        //  Not documented
char * routing_key,                     //  Not documented
amq_content_basic_t * content,          //  Not documented
Bool mandatory,                         //  Not documented
Bool immediate                          //  Not documented
);

static int
    zyre_backend_amqp_online_partial_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal                 //  Portal back to server
);

static int
    zyre_backend_amqp_online_final_shim (
void * self_v,                          //  Self as void pointer
zyre_backend_t * portal                 //  Portal back to server
);

static void *
    zyre_backend_amqp__zyre_backend_link (
void * object                           //  Reference cast as a void *
);

static void
    zyre_backend_amqp__zyre_backend_unlink (
void * object_p                         //  Reference pointer cast as a void *
);

#define zyre_backend_amqp_alloc()       zyre_backend_amqp_alloc_ (__FILE__, __LINE__)
static zyre_backend_amqp_t *
    zyre_backend_amqp_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    zyre_backend_amqp_cache_initialise (
void);

static void
    zyre_backend_amqp_cache_purge (
void);

static void
    zyre_backend_amqp_cache_terminate (
void);

Bool
    zyre_backend_amqp_animating = TRUE;  //  Animation enabled by default
static Bool
    s_zyre_backend_amqp_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_zyre_backend_amqp_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static ipr_looseref_list_t
    *s_zyre_backend_list;               //  List of portal factories
static Bool
    s_zyre_backend_stopped;             //  Is this portal factory stopped?
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_new

    Type: Component method
    Creates and initialises a new zyre_backend_amqp_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

zyre_backend_amqp_t *
    zyre_backend_amqp_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    zyre_backend_amqp_t *
        self = NULL;                    //  Object reference

if (!s_zyre_backend_amqp_active)
    self_initialise ();
    self = zyre_backend_amqp_alloc_ (file, line);
    if (self) {
        self->object_tag   = ZYRE_BACKEND_AMQP_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, zyre_backend_amqp_show_);
#endif

self->thread = zyre_backend_amqp_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->zyre_backend_list = ipr_looseref_list_new ();

self->messages = ipr_looseref_list_new ();
self->pipe_table = ipr_hash_table_new ();
self->feed_table = ipr_hash_table_new ();
ipr_str_random (self->queue, "ZYRE-AAAAAAAA");
}

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_annihilate_ (
    zyre_backend_amqp_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
    int
        history_last;
#endif

    zyre_backend_amqp_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to zyre_backend_amqp agent");
        rc = -1;
    }
}
else
    rc = -1;

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_start

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the start incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_start (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal             //  Portal back to client
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_start (self->thread,portal)) {
        //icl_console_print ("Error sending 'start' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_stop

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the stop incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_stop (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal             //  Portal back to client
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_stop (self->thread,portal)) {
        //icl_console_print ("Error sending 'stop' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_pipe_create

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the pipe create incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_pipe_create (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal,            //  Portal back to client
    char * pipe_type,                   //  Not documented
    char * pipe_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_pipe_create (self->thread,portal,pipe_type,pipe_name)) {
        //icl_console_print ("Error sending 'pipe create' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_pipe_delete

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the pipe delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_pipe_delete (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal,            //  Portal back to client
    char * pipe_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_pipe_delete (self->thread,portal,pipe_name)) {
        //icl_console_print ("Error sending 'pipe delete' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_feed_create

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the feed create incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_feed_create (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal,            //  Portal back to client
    char * feed_type,                   //  Not documented
    char * feed_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_feed_create (self->thread,portal,feed_type,feed_name)) {
        //icl_console_print ("Error sending 'feed create' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_feed_delete

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the feed delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_feed_delete (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal,            //  Portal back to client
    char * feed_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_feed_delete (self->thread,portal,feed_name)) {
        //icl_console_print ("Error sending 'feed delete' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_join_create

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the join create incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_join_create (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal,            //  Portal back to client
    char * pipe_name,                   //  Not documented
    char * feed_name,                   //  Not documented
    char * address                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_join_create (self->thread,portal,pipe_name,feed_name,address)) {
        //icl_console_print ("Error sending 'join create' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_join_delete

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the join delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_join_delete (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal,            //  Portal back to client
    char * pipe_name,                   //  Not documented
    char * feed_name,                   //  Not documented
    char * address                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_join_delete (self->thread,portal,pipe_name,feed_name,address)) {
        //icl_console_print ("Error sending 'join delete' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_address_post

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the address post incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_address_post (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal,            //  Portal back to client
    char * address,                     //  Not documented
    char * feed_name,                   //  Not documented
    amq_content_basic_t * content       //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_address_post (self->thread,portal,address,feed_name,content)) {
        //icl_console_print ("Error sending 'address post' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_forward

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the forward incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_forward (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal,            //  Portal back to client
    char * exchange,                    //  Not documented
    char * routing_key,                 //  Not documented
    amq_content_basic_t * content,      //  Not documented
    Bool mandatory,                     //  Not documented
    Bool immediate                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_forward (self->thread,portal,exchange,routing_key,content,mandatory,immediate)) {
        //icl_console_print ("Error sending 'forward' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_online_partial

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the online partial incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_online_partial (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal             //  Portal back to client
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_online_partial (self->thread,portal)) {
        //icl_console_print ("Error sending 'online partial' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_online_final

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    This is the online final incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_online_final (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal             //  Portal back to client
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent_online_final (self->thread,portal)) {
        //icl_console_print ("Error sending 'online final' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_initialise

    Type: Component method
    Shadow the main config, generated peer agent uses 'zyre_peer_config'
    Then start asynchronous client connection (zyre_peer_agent)
    -------------------------------------------------------------------------
 */

static void
    zyre_backend_amqp_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_zyre_backend_amqp_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_zyre_backend_amqp_mutex)
            s_zyre_backend_amqp_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_zyre_backend_amqp_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_zyre_backend_amqp_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

zyre_backend_amqp_agent_init ();

s_zyre_backend_list = ipr_looseref_list_new ();

zyre_peer_config = zyre_peer_config_new ();
zyre_peer_config_shadow (zyre_peer_config, zyre_config_table (zyre_config));
zyre_peer_agent_init ();
            s_zyre_backend_amqp_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_zyre_backend_amqp_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_backend_amqp_terminate (
void)
{
zyre_backend_t
    *zyre_backend;                  //  Portal factory object

if (s_zyre_backend_amqp_active) {

//
if (icl_atomic_cas32 ((volatile qbyte *) &s_zyre_backend_stopped, TRUE, FALSE) == FALSE) {
    while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (s_zyre_backend_list))) {
        zyre_backend->server_looseref = NULL;
        zyre_backend_destroy (&zyre_backend);
    }
}
ipr_looseref_list_destroy (&s_zyre_backend_list);

zyre_peer_agent_term ();
zyre_peer_config_destroy (&zyre_peer_config);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_zyre_backend_amqp_mutex);
#endif
        s_zyre_backend_amqp_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_backend_amqp_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp__zyre_backend_new

    Type: Component method
    Creates and initialises a new portal instance.  If the server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    -------------------------------------------------------------------------
 */

zyre_backend_t *
    zyre_backend_amqp__zyre_backend_new (
    void * self_v                       //  Untyped server reference
)
{
zyre_backend_amqp_t
    *self;
    zyre_backend_t *
        zyre_backend;                   //  Not documented

//
//  Grab a link to a new or the provided server object
if (self_v)
    self = self_link ((zyre_backend_amqp_t *) self_v);
else
    self = self_new ();

zyre_backend = zyre_backend_new (self, self__zyre_backend_link, self__zyre_backend_unlink);
zyre_backend->server_looseref = ipr_looseref_queue (
    self->zyre_backend_list, zyre_backend_link (zyre_backend));

//  Build virtual methods for server-side methods
zyre_backend->server_unbind = self__zyre_backend_unbind_shim;
zyre_backend->request_start = self_start_shim;
zyre_backend->request_stop = self_stop_shim;
zyre_backend->request_pipe_create = self_pipe_create_shim;
zyre_backend->request_pipe_delete = self_pipe_delete_shim;
zyre_backend->request_feed_create = self_feed_create_shim;
zyre_backend->request_feed_delete = self_feed_delete_shim;
zyre_backend->request_join_create = self_join_create_shim;
zyre_backend->request_join_delete = self_join_delete_shim;
zyre_backend->request_address_post = self_address_post_shim;
zyre_backend->request_forward = self_forward_shim;
zyre_backend->request_online_partial = self_online_partial_shim;
zyre_backend->request_online_final = self_online_final_shim;

//  Drop link to server object
self_unlink (&self);

    return (zyre_backend);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp__zyre_backend_factory

    Type: Component method
    Creates and initialises a new portal factory instance.
    -------------------------------------------------------------------------
 */

zyre_backend_t *
    zyre_backend_amqp__zyre_backend_factory (
void)
{
    zyre_backend_t *
        zyre_backend;                   //  Not documented

//
if (!s_zyre_backend_amqp_active)
    self_initialise ();             //  Since we don't call zyre_backend_amqp_new
zyre_backend = zyre_backend_new (NULL, self__zyre_backend_link, self__zyre_backend_unlink);
zyre_backend->server_looseref = ipr_looseref_queue (
    s_zyre_backend_list, zyre_backend_link (zyre_backend));

//  Build virtual methods for server-side methods
zyre_backend->server_new = self__zyre_backend_new;

    return (zyre_backend);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp__zyre_backend_unbind_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_backend_amqp__zyre_backend_unbind_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal             //  Portal reference
)
{

self__zyre_backend_unbind ((zyre_backend_amqp_t *) self_v, portal);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp__zyre_backend_unbind

    Type: Component method
    Accepts a zyre_backend_amqp_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Server-to-portal unbind.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp__zyre_backend_unbind (
    zyre_backend_amqp_t * self,         //  Reference to object
    zyre_backend_t * portal             //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (zyre_backend_amqp_agent__zyre_backend_unbind (self->thread,portal)) {
        //icl_console_print ("Error sending '_zyre_backend unbind' method to zyre_backend_amqp agent");
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
    zyre_backend_amqp_start_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_start_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal             //  Portal back to server
)
{
    int
        rc = 0;                         //  Return code

rc = self_start ((zyre_backend_amqp_t *) self_v, portal);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_stop_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_stop_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal             //  Portal back to server
)
{
    int
        rc = 0;                         //  Return code

rc = self_stop ((zyre_backend_amqp_t *) self_v, portal);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_pipe_create_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_pipe_create_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    char * pipe_type,                   //  Not documented
    char * pipe_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_pipe_create ((zyre_backend_amqp_t *) self_v, portal, pipe_type, pipe_name);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_pipe_delete_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_pipe_delete_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    char * pipe_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_pipe_delete ((zyre_backend_amqp_t *) self_v, portal, pipe_name);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_feed_create_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_feed_create_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    char * feed_type,                   //  Not documented
    char * feed_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_feed_create ((zyre_backend_amqp_t *) self_v, portal, feed_type, feed_name);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_feed_delete_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_feed_delete_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    char * feed_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_feed_delete ((zyre_backend_amqp_t *) self_v, portal, feed_name);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_join_create_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_join_create_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    char * pipe_name,                   //  Not documented
    char * feed_name,                   //  Not documented
    char * address                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_join_create ((zyre_backend_amqp_t *) self_v, portal, pipe_name, feed_name, address);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_join_delete_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_join_delete_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    char * pipe_name,                   //  Not documented
    char * feed_name,                   //  Not documented
    char * address                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_join_delete ((zyre_backend_amqp_t *) self_v, portal, pipe_name, feed_name, address);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_address_post_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_address_post_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    char * address,                     //  Not documented
    char * feed_name,                   //  Not documented
    amq_content_basic_t * content       //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_address_post ((zyre_backend_amqp_t *) self_v, portal, address, feed_name, content);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_forward_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_forward_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal,            //  Portal back to server
    char * exchange,                    //  Not documented
    char * routing_key,                 //  Not documented
    amq_content_basic_t * content,      //  Not documented
    Bool mandatory,                     //  Not documented
    Bool immediate                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

rc = self_forward ((zyre_backend_amqp_t *) self_v, portal, exchange, routing_key, content, mandatory, immediate);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_online_partial_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_online_partial_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal             //  Portal back to server
)
{
    int
        rc = 0;                         //  Return code

rc = self_online_partial ((zyre_backend_amqp_t *) self_v, portal);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_online_final_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    zyre_backend_amqp_online_final_shim (
    void * self_v,                      //  Self as void pointer
    zyre_backend_t * portal             //  Portal back to server
)
{
    int
        rc = 0;                         //  Return code

rc = self_online_final ((zyre_backend_amqp_t *) self_v, portal);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp__zyre_backend_link

    Type: Component method
    -------------------------------------------------------------------------
 */

static void *
    zyre_backend_amqp__zyre_backend_link (
    void * object                       //  Reference cast as a void *
)
{

//
object = (void *) zyre_backend_amqp_link (((zyre_backend_amqp_t *) object));

    return (object);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp__zyre_backend_unlink

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_backend_amqp__zyre_backend_unlink (
    void * object_p                     //  Reference pointer cast as a void *
)
{

//
zyre_backend_amqp_unlink (((zyre_backend_amqp_t **) object_p));
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_amqp_destroy_ (
    zyre_backend_amqp_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    zyre_backend_amqp_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = zyre_backend_amqp_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        zyre_backend_amqp_free (self);
    *self_p = NULL;
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    zyre_backend_amqp_unlink_ (
    zyre_backend_amqp_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
    int
        history_last;
#endif
    zyre_backend_amqp_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on zyre_backend_amqp object");
            zyre_backend_amqp_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                zyre_backend_amqp_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                zyre_backend_amqp_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    zyre_backend_amqp_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

zyre_backend_amqp_animating = enabled;

zyre_backend_amqp_agent_animate (enabled);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_free

    Type: Component method
    Freess a zyre_backend_amqp_t object.
    -------------------------------------------------------------------------
 */

void
    zyre_backend_amqp_free_ (
    zyre_backend_amqp_t * self,         //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (zyre_backend_amqp_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (zyre_backend_amqp_t));
        self->object_tag = ZYRE_BACKEND_AMQP_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_backend_amqp_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    zyre_backend_amqp_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <zyre_backend_amqp zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
    if (self->history_last > ZYRE_BACKEND_AMQP_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ZYRE_BACKEND_AMQP_HISTORY_LENGTH;
        self->history_last %= ZYRE_BACKEND_AMQP_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ZYRE_BACKEND_AMQP_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </zyre_backend_amqp>\n");
#endif

}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static zyre_backend_amqp_t *
    zyre_backend_amqp_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    zyre_backend_amqp_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    zyre_backend_amqp_cache_initialise ();

self = (zyre_backend_amqp_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (zyre_backend_amqp_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

zyre_backend_amqp_t *
    zyre_backend_amqp_link_ (
    zyre_backend_amqp_t * self,         //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
    int
        history_last;
#endif

    if (self) {
        ZYRE_BACKEND_AMQP_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND_AMQP)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ZYRE_BACKEND_AMQP_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    zyre_backend_amqp_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (zyre_backend_amqp_t));
icl_system_register (zyre_backend_amqp_cache_purge, zyre_backend_amqp_cache_terminate);
}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_backend_amqp_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_backend_amqp_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    zyre_backend_amqp_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_backend_amqp_new_in_scope_ (
    zyre_backend_amqp_t * * self_p,     //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = zyre_backend_amqp_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) zyre_backend_amqp_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__zyre_backend_amqp_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__zyre_backend_amqp_component  = "zyre_backend_amqp ";
char *EMBED__zyre_backend_amqp_version    = "1.0 ";
char *EMBED__zyre_backend_amqp_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__zyre_backend_amqp_filename   = "zyre_backend_amqp.icl ";
char *EMBED__zyre_backend_amqp_builddate  = "2010/10/06 ";
char *EMBED__zyre_backend_amqp_version_end  = "VeRsIoNeNd:ipc";

