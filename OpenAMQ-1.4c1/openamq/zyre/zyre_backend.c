/*---------------------------------------------------------------------------
    zyre_backend.c - zyre_backend component

    This class enables the creation of backend modules that implement RestMS
    on a messaging server.  Modules are portal servers that inherit the
    zyre_backend_back class and implement the requests defined here.
    The client for a backend module implements the response methods, and must
    be an async class.
    Generated from zyre_backend.icl by icl_gen using GSL/4.
    
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
#include "zyre_backend.h"               //  Definitions for our class

//  Shorthand for class type

#define self_t              zyre_backend_t

//  Shorthands for class methods

#define self_factory        zyre_backend_factory
#define self_request_start  zyre_backend_request_start
#define self_request_stop   zyre_backend_request_stop
#define self_request_pipe_create  zyre_backend_request_pipe_create
#define self_request_pipe_delete  zyre_backend_request_pipe_delete
#define self_request_feed_create  zyre_backend_request_feed_create
#define self_request_feed_delete  zyre_backend_request_feed_delete
#define self_request_join_create  zyre_backend_request_join_create
#define self_request_join_delete  zyre_backend_request_join_delete
#define self_request_address_post  zyre_backend_request_address_post
#define self_request_forward  zyre_backend_request_forward
#define self_request_online_partial  zyre_backend_request_online_partial
#define self_request_online_final  zyre_backend_request_online_final
#define self_response_online  zyre_backend_response_online
#define self_response_offline  zyre_backend_response_offline
#define self_response_arrived  zyre_backend_response_arrived
#define self_response_returned  zyre_backend_response_returned
#define self_new            zyre_backend_new
#define self_annihilate     zyre_backend_annihilate
#define self_ready          zyre_backend_ready
#define self_selftest       zyre_backend_selftest
#define self_terminate      zyre_backend_terminate
#define self_show           zyre_backend_show
#define self_destroy        zyre_backend_destroy
#define self_alloc          zyre_backend_alloc
#define self_free           zyre_backend_free
#define self_read_lock      zyre_backend_read_lock
#define self_write_lock     zyre_backend_write_lock
#define self_unlock         zyre_backend_unlock
#define self_link           zyre_backend_link
#define self_unlink         zyre_backend_unlink
#define self_cache_initialise  zyre_backend_cache_initialise
#define self_cache_purge    zyre_backend_cache_purge
#define self_cache_terminate  zyre_backend_cache_terminate
#define self_show_animation  zyre_backend_show_animation
#define self_new_in_scope   zyre_backend_new_in_scope

#define zyre_backend_annihilate(self)   zyre_backend_annihilate_ (self, __FILE__, __LINE__)
static void
    zyre_backend_annihilate_ (
zyre_backend_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_backend_alloc()            zyre_backend_alloc_ (__FILE__, __LINE__)
static zyre_backend_t *
    zyre_backend_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_backend_free(self)         zyre_backend_free_ (self, __FILE__, __LINE__)
static void
    zyre_backend_free_ (
zyre_backend_t * self,                  //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    zyre_backend_cache_initialise (
void);

static void
    zyre_backend_cache_purge (
void);

static void
    zyre_backend_cache_terminate (
void);

Bool
    zyre_backend_animating = TRUE;      //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    zyre_backend_factory

    Type: Component method
    Asks portal factory to create new portal with implicit server object. The
    server object is owned only by its portal; when you stop the owning portal
    the implicit server object is also stopped.
    -------------------------------------------------------------------------
 */

zyre_backend_t *
    zyre_backend_factory (
    zyre_backend_t * self               //  Portal factory
)
{
    zyre_backend_t *
        portal;                         //  New portal object

//
//  Check this is a valid factory
if (self->server_object)
    icl_console_print ("E: factory method is only allowed on portal factories");
assert (!self->server_object);
assert (self->server_new);
//
portal = (self->server_new) (NULL);

    return (portal);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_start

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_start (
    zyre_backend_t * self               //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_start) (self->server_object, self);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_stop

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_stop (
    zyre_backend_t * self               //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_stop) (self->server_object, self);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_pipe_create

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_pipe_create (
    zyre_backend_t * self,              //  Not documented
    char * pipe_type,                   //  Not documented
    char * pipe_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_pipe_create) (self->server_object, self, pipe_type, pipe_name);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_pipe_delete

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_pipe_delete (
    zyre_backend_t * self,              //  Not documented
    char * pipe_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_pipe_delete) (self->server_object, self, pipe_name);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_feed_create

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_feed_create (
    zyre_backend_t * self,              //  Not documented
    char * feed_type,                   //  Not documented
    char * feed_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_feed_create) (self->server_object, self, feed_type, feed_name);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_feed_delete

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_feed_delete (
    zyre_backend_t * self,              //  Not documented
    char * feed_name                    //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_feed_delete) (self->server_object, self, feed_name);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_join_create

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_join_create (
    zyre_backend_t * self,              //  Not documented
    char * pipe_name,                   //  Not documented
    char * feed_name,                   //  Not documented
    char * address                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_join_create) (self->server_object, self, pipe_name, feed_name, address);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_join_delete

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_join_delete (
    zyre_backend_t * self,              //  Not documented
    char * pipe_name,                   //  Not documented
    char * feed_name,                   //  Not documented
    char * address                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_join_delete) (self->server_object, self, pipe_name, feed_name, address);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_address_post

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_address_post (
    zyre_backend_t * self,              //  Not documented
    char * address,                     //  Not documented
    char * feed_name,                   //  Not documented
    amq_content_basic_t * content       //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_address_post) (self->server_object, self, address, feed_name, content);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_forward

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_forward (
    zyre_backend_t * self,              //  Not documented
    char * exchange,                    //  Not documented
    char * routing_key,                 //  Not documented
    amq_content_basic_t * content,      //  Not documented
    Bool mandatory,                     //  Not documented
    Bool immediate                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_forward) (self->server_object, self, exchange, routing_key, content, mandatory, immediate);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_online_partial

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_online_partial (
    zyre_backend_t * self               //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_online_partial) (self->server_object, self);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_request_online_final

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_request_online_final (
    zyre_backend_t * self               //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_online_final) (self->server_object, self);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_response_online

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_response_online (
    zyre_backend_t * self,              //  Not documented
    char * reply_queue                  //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->response_online) (self->client_object, self, reply_queue);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_response_offline

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_response_offline (
    zyre_backend_t * self               //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->response_offline) (self->client_object, self);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_response_arrived

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_response_arrived (
    zyre_backend_t * self,              //  Not documented
    zyre_peer_method_t * method         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->response_arrived) (self->client_object, self, method);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_response_returned

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_backend_response_returned (
    zyre_backend_t * self,              //  Not documented
    zyre_peer_method_t * method         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->response_returned) (self->client_object, self, method);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_new

    Type: Component method
    Creates and initialises a new zyre_backend_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

zyre_backend_t *
    zyre_backend_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    void * server_object,               //  Not documented
    untyped_link_fn * server_link,      //  Not documented
    untyped_unlink_fn * server_unlink   //  Not documented
)
{
    zyre_backend_t *
        self = NULL;                    //  Object reference

    self = zyre_backend_alloc_ (file, line);
    if (self) {
        self->object_tag   = ZYRE_BACKEND_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, zyre_backend_show_);
#endif

//
self->server_object = (server_link) (server_object);
self->server_unlink = server_unlink;
}

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_backend_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_backend_annihilate_ (
    zyre_backend_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
    int
        history_last;
#endif

    zyre_backend_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = self->links;
#endif

    ZYRE_BACKEND_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

if (icl_atomic_cas32 ((volatile qbyte *) &self->stopped, TRUE, FALSE) == FALSE) {
    self->bound = FALSE;
    (self->client_unbind) (self->client_object, self);
    if (self->server_object) {
        (self->server_unbind) (self->server_object, self);
        (self->server_unlink) (&self->server_object);
    }
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

}
/*  -------------------------------------------------------------------------
    zyre_backend_ready

    Type: Component method
    Accepts a zyre_backend_t reference and returns zero in case of success,
    1 in case of errors.
    Signals to the server that the portal has been bound by the client and
    is now ready for use.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_ready (
    zyre_backend_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_ASSERT_SANE (self);
if (!self->zombie) {

//
self->bound = TRUE;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_backend_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    zyre_backend_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_backend_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    zyre_backend_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_backend_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    zyre_backend_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <zyre_backend zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
    if (self->history_last > ZYRE_BACKEND_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ZYRE_BACKEND_HISTORY_LENGTH;
        self->history_last %= ZYRE_BACKEND_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ZYRE_BACKEND_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </zyre_backend>\n");
#endif

}
/*  -------------------------------------------------------------------------
    zyre_backend_destroy

    Type: Component method
    Destroys a zyre_backend_t object. Takes the address of a
    zyre_backend_t reference (a pointer to a pointer) and nullifies the
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
    zyre_backend_destroy_ (
    zyre_backend_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    zyre_backend_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        zyre_backend_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("zyre_backend", "E: missing link on zyre_backend object");
        zyre_backend_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        zyre_backend_free_ ((zyre_backend_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    zyre_backend_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static zyre_backend_t *
    zyre_backend_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    zyre_backend_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    zyre_backend_cache_initialise ();

self = (zyre_backend_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (zyre_backend_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_backend_free

    Type: Component method
    Freess a zyre_backend_t object.
    -------------------------------------------------------------------------
 */

static void
    zyre_backend_free_ (
    zyre_backend_t * self,              //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (zyre_backend_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (zyre_backend_t));
        self->object_tag = ZYRE_BACKEND_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    zyre_backend_read_lock

    Type: Component method
    Accepts a zyre_backend_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_read_lock (
    zyre_backend_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_write_lock

    Type: Component method
    Accepts a zyre_backend_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_write_lock (
    zyre_backend_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_unlock

    Type: Component method
    Accepts a zyre_backend_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    zyre_backend_unlock (
    zyre_backend_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ZYRE_BACKEND_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_backend_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

zyre_backend_t *
    zyre_backend_link_ (
    zyre_backend_t * self,              //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
    int
        history_last;
#endif

    if (self) {
        ZYRE_BACKEND_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_backend_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    zyre_backend_unlink_ (
    zyre_backend_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
    int
        history_last;
#endif

    zyre_backend_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        ZYRE_BACKEND_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("zyre_backend", "E: missing link on zyre_backend object");
            zyre_backend_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_BACKEND)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ZYRE_BACKEND_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            zyre_backend_annihilate_ (self_p, file, line);
        zyre_backend_free_ ((zyre_backend_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    zyre_backend_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    zyre_backend_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (zyre_backend_t));
icl_system_register (zyre_backend_cache_purge, zyre_backend_cache_terminate);
}
/*  -------------------------------------------------------------------------
    zyre_backend_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_backend_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    zyre_backend_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_backend_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    zyre_backend_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    zyre_backend_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

zyre_backend_animating = enabled;
}
/*  -------------------------------------------------------------------------
    zyre_backend_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_backend_new_in_scope_ (
    zyre_backend_t * * self_p,          //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    void * server_object,               //  Not documented
    untyped_link_fn * server_link,      //  Not documented
    untyped_unlink_fn * server_unlink   //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = zyre_backend_new_ (file,line,server_object,server_link,server_unlink);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) zyre_backend_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__zyre_backend_version_start   = "VeRsIoNsTaRt:ipc";
char *EMBED__zyre_backend_component       = "zyre_backend ";
char *EMBED__zyre_backend_version         = "1.1 ";
char *EMBED__zyre_backend_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__zyre_backend_filename        = "zyre_backend.icl ";
char *EMBED__zyre_backend_builddate       = "2010/10/06 ";
char *EMBED__zyre_backend_version_end     = "VeRsIoNeNd:ipc";

