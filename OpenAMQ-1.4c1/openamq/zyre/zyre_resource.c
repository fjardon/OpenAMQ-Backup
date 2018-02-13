/*---------------------------------------------------------------------------
    zyre_resource.c - zyre_resource component

This class holds all RestMS resources in a generic form, with a pointer to
the real resource object.  Resources are stored in a hash table where the
key is the resource path.  Resources have a looseref list of all children.
This class is not threadsafe and may be used from one threadlet only.
    Generated from zyre_resource.icl by icl_gen using GSL/4.
    
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
#include "zyre_resource.h"              //  Definitions for our class

//  Shorthand for class type

#define self_t              zyre_resource_t

//  Shorthands for class methods

#define self_new            zyre_resource_new
#define self_annihilate     zyre_resource_annihilate
#define self_attach_to_parent  zyre_resource_attach_to_parent
#define self_detach_from_parent  zyre_resource_detach_from_parent
#define self_etag           zyre_resource_etag
#define self_modified       zyre_resource_modified
#define self_unmodified     zyre_resource_unmodified
#define self_type_name      zyre_resource_type_name
#define self_type_value     zyre_resource_type_value
#define self_to_document    zyre_resource_to_document
#define self_parse_uri      zyre_resource_parse_uri
#define self_initialise     zyre_resource_initialise
#define self_selftest       zyre_resource_selftest
#define self_factory        zyre_resource_factory
#define self_request_configure  zyre_resource_request_configure
#define self_request_get    zyre_resource_request_get
#define self_request_put    zyre_resource_request_put
#define self_request_delete  zyre_resource_request_delete
#define self_request_post   zyre_resource_request_post
#define self_request_report  zyre_resource_request_report
#define self_request_attach  zyre_resource_request_attach
#define self_request_detach  zyre_resource_request_detach
#define self_response_child_add  zyre_resource_response_child_add
#define self_ready          zyre_resource_ready
#define self_terminate      zyre_resource_terminate
#define self_show           zyre_resource_show
#define self_destroy        zyre_resource_destroy
#define self_alloc          zyre_resource_alloc
#define self_free           zyre_resource_free
#define self_read_lock      zyre_resource_read_lock
#define self_write_lock     zyre_resource_write_lock
#define self_unlock         zyre_resource_unlock
#define self_link           zyre_resource_link
#define self_unlink         zyre_resource_unlink
#define self_cache_initialise  zyre_resource_cache_initialise
#define self_cache_purge    zyre_resource_cache_purge
#define self_cache_terminate  zyre_resource_cache_terminate
#define self_show_animation  zyre_resource_show_animation
#define self_new_in_scope   zyre_resource_new_in_scope

#define zyre_resource_annihilate(self)  zyre_resource_annihilate_ (self, __FILE__, __LINE__)
static void
    zyre_resource_annihilate_ (
zyre_resource_t * ( * self_p ),         //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    zyre_resource_initialise (
void);

static void
    zyre_resource_terminate (
void);

#define zyre_resource_alloc()           zyre_resource_alloc_ (__FILE__, __LINE__)
static zyre_resource_t *
    zyre_resource_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define zyre_resource_free(self)        zyre_resource_free_ (self, __FILE__, __LINE__)
static void
    zyre_resource_free_ (
zyre_resource_t * self,                 //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    zyre_resource_cache_initialise (
void);

static void
    zyre_resource_cache_purge (
void);

static void
    zyre_resource_cache_terminate (
void);

Bool
    zyre_resource_animating = TRUE;     //  Animation enabled by default
static Bool
    s_zyre_resource_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_zyre_resource_mutex    = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


#define S_CONFIG_FILE       "zyre_restms.cfg"
//  This counter lets us generate unique resource hashes - we bump it each time
//  we initialise the class, and save the new value in S_CONFIG_FILE
static long int
    s_instance,                         //  Execution instance
    s_current;                          //  Resources created so far
/*  -------------------------------------------------------------------------
    zyre_resource_new

    Type: Component method
    Creates and initialises a new zyre_resource_t object, returns a
    reference to the created object.
    Create new resource.  If the resource already exists (path already defined)
    the resource->hash will be null, and the resource should be destroyed by
    the caller.
    -------------------------------------------------------------------------
 */

zyre_resource_t *
    zyre_resource_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    void * server_object,               //  Not documented
    untyped_link_fn * server_link,      //  Not documented
    untyped_unlink_fn * server_unlink,   //  Not documented
    zyre_resource_t * parent,           //  Parent resource, or NULL
    ipr_hash_table_t * table,           //  Hash by path
    char * type,                        //  Resource type name
    char * name                         //  Resource name, or empty
)
{
    zyre_resource_t *
        self = NULL;                    //  Object reference

if (!s_zyre_resource_active)
    self_initialise ();
    self = zyre_resource_alloc_ (file, line);
    if (self) {
        self->object_tag   = ZYRE_RESOURCE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
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
        icl_mem_set_callback (self, zyre_resource_show_);
#endif

//
self->server_object = (server_link) (server_object);
self->server_unlink = server_unlink;

//
if (*name) {
    //  If we have a name, clean it up
    char
        *name_ptr;
    icl_shortstr_cpy (self->name, name);
    for (name_ptr = self->name; *name_ptr; name_ptr++)
        if (!isalnum (*name_ptr) && *name_ptr != '.')
            *name_ptr = '-';
    icl_shortstr_fmt (self->path, "/%s/%s", type, self->name);
    self->private = FALSE;          //  Discoverable resource
}
else {
    //  Else generate a new unique hash as name
    ipr_str_random (self->name, "ZYRE-AAAAAAAA");
    icl_shortstr_fmt (self->name + strlen (self->name), "-%d%d", s_instance, ++s_current);
    icl_shortstr_fmt (self->path, "/resource/%s", self->name);
    self->private = TRUE;           //  Not discoverable resource
}
self->hash = ipr_hash_new (table, self->path, self);
if (self->hash) {
    self->type      = self_type_value (type);
    self->parent    = parent;
    self->children  = ipr_looseref_list_new ();
    self->modified  = apr_time_now ();
    self_attach_to_parent (self, parent);
}
if (zyre_config_restms_debug (zyre_config))
    icl_console_print ("R: - create %s called '%s'", type, self->name);
}

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_resource_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_resource_annihilate_ (
    zyre_resource_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
    int
        history_last;
#endif

    zyre_resource_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = self->links;
#endif

    ZYRE_RESOURCE_ASSERT_SANE (self);
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

ipr_hash_destroy (&self->hash);
if (self->children)
    ipr_looseref_list_destroy (&self->children);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

}
/*  -------------------------------------------------------------------------
    zyre_resource_attach_to_parent

    Type: Component method
    Attaches the resource to its parent, if any, and returns the resulting
    looseref object.
    -------------------------------------------------------------------------
 */

ipr_looseref_t *
    zyre_resource_attach_to_parent (
    zyre_resource_t * self,             //  Not documented
    zyre_resource_t * parent            //  Not documented
)
{
    ipr_looseref_t *
        looseref = NULL;                //  Not documented

//
if (parent)
    self->in_parent = ipr_looseref_queue (parent->children, self);

    return (looseref);
}
/*  -------------------------------------------------------------------------
    zyre_resource_detach_from_parent

    Type: Component method
    Accepts a zyre_resource_t reference and returns zero in case of success,
    1 in case of errors.
    Removes the resource from the parent list if any.  We can't do this in
    the destroy method because that is also called at shutdown, and the
    parent list can already be destroyed then.
    -------------------------------------------------------------------------
 */

int
    zyre_resource_detach_from_parent (
    zyre_resource_t * self              //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESOURCE_ASSERT_SANE (self);
if (!self->zombie) {

//
ipr_looseref_destroy (&self->in_parent);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_etag

    Type: Component method
    Calculates an ETag for the resource and returns this as a fresh
    string, that the caller should free when finished.  The ETag will be
    different for each version of the resource, i.e. it includes the
    resource's modified time and MIME type and the content type.
    -------------------------------------------------------------------------
 */

char *
    zyre_resource_etag (
    zyre_resource_t * self,             //  Not documented
    char * type                         //  Not documented
)
{
int
    mime_type;                      //  Encode content type into ETag
    char *
        etag = NULL;                    //  ETag to generate

//
if (ipr_str_prefixed (type, "application/restms+json"))
    mime_type = 1;
else
if (ipr_str_prefixed (type, "application/restms+xml"))
    mime_type = 2;
else
    mime_type = 3;

etag = ipr_str_format ("%llx-%llx-%d",
    (long long unsigned int) self->modified,
    (long long unsigned int) self->hash->table_index,
    mime_type);

    return (etag);
}
/*  -------------------------------------------------------------------------
    zyre_resource_modified

    Type: Component method
    Accepts a zyre_resource_t reference and returns zero in case of success,
    1 in case of errors.
    Returns TRUE if the resource has been modified, based on the If-None-Match
    and If-Modified-Since headers specified in the supplied HTTP request.  If
    the request does not provide either of these headers, returns TRUE.  This
    method is for use in GET methods: 'if modified, 200, else 304'.
    -------------------------------------------------------------------------
 */

int
    zyre_resource_modified (
    zyre_resource_t * self,             //  Reference to object
    http_request_t * request            //  Incoming HTTP request
)
{
char
    *etag = NULL;
//  ISO times have a resolution of 1 second
time_t
    if_modified;
    int
        rc = 0;                         //  Return code

ZYRE_RESOURCE_ASSERT_SANE (self);
if (!self->zombie) {

//
assert (request);
if_modified = ipr_time_mime_decode (
    http_request_get_header (request, "if-modified-since")) / 1000000;

etag = self_etag (self, http_request_get_header (request, "accept"));
if (streq (etag, http_request_get_header (request, "if-none-match"))
|| (if_modified && (self->modified / 1000000) == if_modified))
    rc = FALSE;                     //  Not modified
else
    rc = TRUE;
icl_mem_free (etag);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_unmodified

    Type: Component method
    Accepts a zyre_resource_t reference and returns zero in case of success,
    1 in case of errors.
    Returns TRUE if the resource has not been modified, based on the If-Match
    and If-Unmodified-Since headers specified in the supplied HTTP request.
    If the request does not provide either of these headers, returns TRUE.
    This method is for use in PUT methods: 'if unmodified, 200, else 412'.
    -------------------------------------------------------------------------
 */

int
    zyre_resource_unmodified (
    zyre_resource_t * self,             //  Reference to object
    http_request_t * request            //  Incoming HTTP request
)
{
char
    *etag = NULL;
time_t
    if_unmodified;
    int
        rc = 0;                         //  Return code

ZYRE_RESOURCE_ASSERT_SANE (self);
if (!self->zombie) {

//
assert (request);
if_unmodified = ipr_time_mime_decode (
    http_request_get_header (request, "if-unmodified-since")) / 1000000;

etag = self_etag (self, http_request_get_header (request, "accept"));
if (streq (etag, http_request_get_header (request, "if-match"))
|| (if_unmodified && (self->modified / 1000000) == if_unmodified))
    rc = TRUE;                      //  Not modified
else
    rc = FALSE;
icl_mem_free (etag);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_type_name

    Type: Component method
    Accepts a resource type and returns the external resource name.
    -------------------------------------------------------------------------
 */

char *
    zyre_resource_type_name (
    int type                            //  Not documented
)
{
    char *
        name;                           //  Not documented

assert (RESTMS_RESOURCE_VALID (type));
if (type == RESTMS_RESOURCE_DOMAIN)
    name = "domain";
else
if (type == RESTMS_RESOURCE_FEED)
    name = "feed";
else
if (type == RESTMS_RESOURCE_PIPE)
    name = "pipe";
else
if (type == RESTMS_RESOURCE_JOIN)
    name = "join";
else
if (type == RESTMS_RESOURCE_MESSAGE)
    name = "message";
else
if (type == RESTMS_RESOURCE_CONTENT)
    name = "content";
else
    name = "(?)";

    return (name);
}
/*  -------------------------------------------------------------------------
    zyre_resource_type_value

    Type: Component method
    Accepts a resource name and returns the integer resource type.  If the
    name was not valid, returns RESTMS_RESOURCE_INVALID.
    -------------------------------------------------------------------------
 */

int
    zyre_resource_type_value (
    char * name                         //  Not documented
)
{
    int
        type;                           //  Not documented

//
if (streq (name, "domain"))
    type = RESTMS_RESOURCE_DOMAIN;
else
if (streq (name, "feed"))
    type = RESTMS_RESOURCE_FEED;
else
if (streq (name, "pipe"))
    type = RESTMS_RESOURCE_PIPE;
else
if (streq (name, "join"))
    type = RESTMS_RESOURCE_JOIN;
else
if (streq (name, "message"))
    type = RESTMS_RESOURCE_MESSAGE;
else
if (streq (name, "content"))
    type = RESTMS_RESOURCE_CONTENT;
else
    type = RESTMS_RESOURCE_INVALID;

    return (type);
}
/*  -------------------------------------------------------------------------
    zyre_resource_to_document

    Type: Component method
    Accepts a zyre_resource_t reference and returns zero in case of success,
    1 in case of errors.
    Accepts a resource object tree, reports all children, formats tree as a
    structured document and returns it to the browser client.  Destroys the
    tree afterwards.
    -------------------------------------------------------------------------
 */

int
    zyre_resource_to_document (
    zyre_resource_t * self,             //  Reference to object
    http_driver_context_t * context,    //  Not documented
    ipr_tree_t ** p_tree                //  Not documented
)
{
ipr_looseref_t
    *looseref;
icl_longstr_t
    *longstr;                       //  Serialized data as string
ipr_bucket_t
    *bucket;                        //  Serialized data as bucket
icl_shortstr_t
    mime_date;
char
    *etag;
    int
        rc = 0;                         //  Return code

ZYRE_RESOURCE_ASSERT_SANE (self);
if (!self->zombie) {

//
looseref = ipr_looseref_list_first (self->children);
while (looseref) {
    zyre_resource_t
        *resource = (zyre_resource_t *) looseref->object;
    if (!resource->private)
        self_request_report (resource, context, *p_tree);
    looseref = ipr_looseref_list_next (&looseref);
}
ipr_tree_shut (*p_tree);
ipr_tree_leaf (*p_tree, "xmlns", "http://www.restms.org/schema/restms");

if (ipr_str_prefixed (context->response->content_type, "application/restms+json"))
    longstr = ipr_tree_save_json (*p_tree);
else
if (ipr_str_prefixed (context->response->content_type, "application/restms+xml"))
    longstr = ipr_tree_save_xml (*p_tree);
else {
    icl_shortstr_cpy (context->response->content_type, "text/xml");
    longstr = ipr_tree_save_xml (*p_tree);
}
ipr_tree_destroy (p_tree);

//  Save string in bucket and pass as response bucket
bucket = ipr_bucket_new (longstr->cur_size);
ipr_bucket_fill (bucket, longstr->data, longstr->cur_size);
http_response_set_from_bucket (context->response, bucket, NULL);
ipr_bucket_unlink (&bucket);
icl_longstr_destroy (&longstr);

//  Set Last-Modified and ETag
ipr_time_mime (self->modified, mime_date);
etag = self_etag (self, context->response->content_type);
http_response_set_header (context->response, "last-modified", mime_date);
http_response_set_header (context->response, "etag", etag);
icl_mem_free (etag);

http_driver_context_reply (context);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_parse_uri

    Type: Component method
    Given a resource URI, returns the resource if it exists.  If the URI is
    invalid or the resource does not exist, returns NULL. Resource URIs take
    this form: http://hostname[:port]/restms/{path-info}
    -------------------------------------------------------------------------
 */

zyre_resource_t *
    zyre_resource_parse_uri (
    http_driver_context_t * context,    //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    char * uri                          //  Not documented
)
{
char
    *path;
    zyre_resource_t *
        resource = NULL;                //  Not documented

//
path = ipr_str_defix (uri, context->response->root_uri);
if (path) {
    path = ipr_str_defix (path, RESTMS_ROOT);
    if (path)
        resource = ipr_hash_lookup (table, path);
}

    return (resource);
}
/*  -------------------------------------------------------------------------
    zyre_resource_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_resource_initialise (
void)
{
ipr_xml_t
    *xml_root = NULL,
    *xml_item = NULL;
icl_shortstr_t
    instance_str;

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_zyre_resource_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_zyre_resource_mutex)
            s_zyre_resource_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_zyre_resource_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_zyre_resource_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

//
ipr_xml_load_file (&xml_root, ".", S_CONFIG_FILE, FALSE);
if (xml_root) {
    xml_item = ipr_xml_first_child (xml_root);
    if (!xml_item)
        xml_item = ipr_xml_new (xml_root, "config", NULL);
}
else {
    xml_item = ipr_xml_new (xml_root, "config", NULL);
}
s_instance = atoi (ipr_xml_attr_get (xml_item, "instance", "0"));
s_instance++;
s_current = 0;
icl_shortstr_fmt (instance_str, "%d", s_instance);
ipr_xml_attr_set (xml_item, "instance", instance_str);
ipr_xml_save_file (xml_item, S_CONFIG_FILE);
ipr_xml_unlink (&xml_item);
ipr_xml_destroy (&xml_root);
            s_zyre_resource_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_zyre_resource_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    zyre_resource_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_resource_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    zyre_resource_factory

    Type: Component method
    Asks portal factory to create new portal with implicit server object. The
    server object is owned only by its portal; when you stop the owning portal
    the implicit server object is also stopped.
    -------------------------------------------------------------------------
 */

zyre_resource_t *
    zyre_resource_factory (
    zyre_resource_t * self,             //  Portal factory
    zyre_resource_t * parent,           //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    char * type,                        //  Not documented
    char * name                         //  Not documented
)
{
    zyre_resource_t *
        portal;                         //  New portal object

//
//  Check this is a valid factory
if (self->server_object)
    icl_console_print ("E: factory method is only allowed on portal factories");
assert (!self->server_object);
assert (self->server_new);
//
portal = (self->server_new) (NULL, parent, table, type, name);

    return (portal);
}
/*  -------------------------------------------------------------------------
    zyre_resource_request_configure

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_resource_request_configure (
    zyre_resource_t * self,             //  Not documented
    http_driver_context_t * context,    //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    zyre_backend_t * backend            //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_configure) (self->server_object, self, context, table, backend);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_request_get

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_resource_request_get (
    zyre_resource_t * self,             //  Not documented
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_get) (self->server_object, self, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_request_put

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_resource_request_put (
    zyre_resource_t * self,             //  Not documented
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_put) (self->server_object, self, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_request_delete

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_resource_request_delete (
    zyre_resource_t * self,             //  Not documented
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_delete) (self->server_object, self, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_request_post

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_resource_request_post (
    zyre_resource_t * self,             //  Not documented
    http_driver_context_t * context,    //  Not documented
    ipr_hash_table_t * table,           //  Not documented
    zyre_backend_t * backend            //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_post) (self->server_object, self, context, table, backend);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_request_report

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_resource_request_report (
    zyre_resource_t * self,             //  Not documented
    http_driver_context_t * context,    //  Not documented
    ipr_tree_t * tree                   //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_report) (self->server_object, self, context, tree);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_request_attach

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_resource_request_attach (
    zyre_resource_t * self,             //  Not documented
    zyre_resource_t * resource,         //  Not documented
    void * argument                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_attach) (self->server_object, self, resource, argument);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_request_detach

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_resource_request_detach (
    zyre_resource_t * self,             //  Not documented
    zyre_resource_t * resource,         //  Not documented
    void * argument                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_detach) (self->server_object, self, resource, argument);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_response_child_add

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    zyre_resource_response_child_add (
    zyre_resource_t * self,             //  Not documented
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->response_child_add) (self->client_object, self, context);

    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_ready

    Type: Component method
    Accepts a zyre_resource_t reference and returns zero in case of success,
    1 in case of errors.
    Signals to the server that the portal has been bound by the client and
    is now ready for use.
    -------------------------------------------------------------------------
 */

int
    zyre_resource_ready (
    zyre_resource_t * self              //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESOURCE_ASSERT_SANE (self);
if (!self->zombie) {

//
self->bound = TRUE;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    zyre_resource_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_resource_terminate (
void)
{

if (s_zyre_resource_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_zyre_resource_mutex);
#endif
        s_zyre_resource_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    zyre_resource_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_resource_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    zyre_resource_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <zyre_resource zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
    if (self->history_last > ZYRE_RESOURCE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ZYRE_RESOURCE_HISTORY_LENGTH;
        self->history_last %= ZYRE_RESOURCE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ZYRE_RESOURCE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </zyre_resource>\n");
#endif

}
/*  -------------------------------------------------------------------------
    zyre_resource_destroy

    Type: Component method
    Destroys a zyre_resource_t object. Takes the address of a
    zyre_resource_t reference (a pointer to a pointer) and nullifies the
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
    zyre_resource_destroy_ (
    zyre_resource_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    zyre_resource_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        zyre_resource_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("zyre_resource", "E: missing link on zyre_resource object");
        zyre_resource_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        zyre_resource_free_ ((zyre_resource_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    zyre_resource_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static zyre_resource_t *
    zyre_resource_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    zyre_resource_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    zyre_resource_cache_initialise ();

self = (zyre_resource_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (zyre_resource_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_resource_free

    Type: Component method
    Freess a zyre_resource_t object.
    -------------------------------------------------------------------------
 */

static void
    zyre_resource_free_ (
    zyre_resource_t * self,             //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (zyre_resource_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (zyre_resource_t));
        self->object_tag = ZYRE_RESOURCE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    zyre_resource_read_lock

    Type: Component method
    Accepts a zyre_resource_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    zyre_resource_read_lock (
    zyre_resource_t * self              //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESOURCE_ASSERT_SANE (self);
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
    zyre_resource_write_lock

    Type: Component method
    Accepts a zyre_resource_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    zyre_resource_write_lock (
    zyre_resource_t * self              //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESOURCE_ASSERT_SANE (self);
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
    zyre_resource_unlock

    Type: Component method
    Accepts a zyre_resource_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    zyre_resource_unlock (
    zyre_resource_t * self              //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

ZYRE_RESOURCE_ASSERT_SANE (self);
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
    zyre_resource_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

zyre_resource_t *
    zyre_resource_link_ (
    zyre_resource_t * self,             //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
    int
        history_last;
#endif

    if (self) {
        ZYRE_RESOURCE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    zyre_resource_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    zyre_resource_unlink_ (
    zyre_resource_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
    int
        history_last;
#endif

    zyre_resource_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        ZYRE_RESOURCE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("zyre_resource", "E: missing link on zyre_resource object");
            zyre_resource_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ZYRE_RESOURCE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ZYRE_RESOURCE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            zyre_resource_annihilate_ (self_p, file, line);
        zyre_resource_free_ ((zyre_resource_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    zyre_resource_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    zyre_resource_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (zyre_resource_t));
icl_system_register (zyre_resource_cache_purge, zyre_resource_cache_terminate);
}
/*  -------------------------------------------------------------------------
    zyre_resource_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_resource_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    zyre_resource_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    zyre_resource_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    zyre_resource_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    zyre_resource_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

zyre_resource_animating = enabled;
}
/*  -------------------------------------------------------------------------
    zyre_resource_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_resource_new_in_scope_ (
    zyre_resource_t * * self_p,         //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    void * server_object,               //  Not documented
    untyped_link_fn * server_link,      //  Not documented
    untyped_unlink_fn * server_unlink,   //  Not documented
    zyre_resource_t * parent,           //  Parent resource, or NULL
    ipr_hash_table_t * table,           //  Hash by path
    char * type,                        //  Resource type name
    char * name                         //  Resource name, or empty
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = zyre_resource_new_ (file,line,server_object,server_link,server_unlink,parent,table,type,name);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) zyre_resource_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__zyre_resource_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__zyre_resource_component      = "zyre_resource ";
char *EMBED__zyre_resource_version        = "1.0 ";
char *EMBED__zyre_resource_copyright      = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__zyre_resource_filename       = "zyre_resource.icl ";
char *EMBED__zyre_resource_builddate      = "2010/10/06 ";
char *EMBED__zyre_resource_version_end    = "VeRsIoNeNd:ipc";

