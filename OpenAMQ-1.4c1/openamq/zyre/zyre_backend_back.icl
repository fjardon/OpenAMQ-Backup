<?xml?>
<!--
    Copyright (c) 1996-2009 iMatix Corporation

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
 -->
<class
    name     = "zyre_backend_back"
    comment  = "Portal back-end - async server wrapper"
    script   = "smt_object_gen"
    target   = "smt"
    abstract = "1"
    >

<inherit class = "smt_object" />
<inherit class = "icl_init" />

<import class = "zyre_backend" />
<import class = "zyre_classes" />

<private name = "header">
static ipr_looseref_list_t
    *s_zyre_backend_list;               //  List of portal factories
static Bool
    s_zyre_backend_stopped;             //  Is this portal factory stopped?
</private>

<context>
    ipr_looseref_list_t
        *zyre_backend_list;             //  List of portals
    Bool
        zyre_backend_stopped;           //  Is this portal stopped?
</context>

<method name = "new">
    self->zyre_backend_list = ipr_looseref_list_new ();
</method>

<method name = "destroy">
    <action>
    {
    zyre_backend_t
        *zyre_backend;                  //  Portal object

    if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_backend_stopped, TRUE, FALSE) == FALSE) {
        while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_list))) {
            zyre_backend->server_looseref = NULL;
            zyre_backend_destroy (&zyre_backend);
        }
    }
    ipr_looseref_list_destroy (&self->zyre_backend_list);
    }
    </action>
</method>

<method name = "initialise">
    s_zyre_backend_list = ipr_looseref_list_new ();
</method>

<method name = "terminate">
    <local>
    zyre_backend_t
        *zyre_backend;                  //  Portal factory object
    </local>
    //
    if (icl_atomic_cas32 ((volatile qbyte *) &s_zyre_backend_stopped, TRUE, FALSE) == FALSE) {
        while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (s_zyre_backend_list))) {
            zyre_backend->server_looseref = NULL;
            zyre_backend_destroy (&zyre_backend);
        }
    }
    ipr_looseref_list_destroy (&s_zyre_backend_list);
</method>

<method name = "_zyre_backend new" return = "zyre_backend">
    <doc>
    Creates and initialises a new portal instance.  If the server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    </doc>
    <argument name = "self_v" type = "void *">Untyped server reference</argument>
    <declare name = "zyre_backend" type = "zyre_backend_t *" />
    <local>
    $(selftype)
        *self;
    </local>
    //
    //  Grab a link to a new or the provided server object
    if (self_v)
        self = self_link (($(selftype) *) self_v);
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
</method>

<method name = "_zyre_backend factory" return = "zyre_backend">
    <doc>
    Creates and initialises a new portal factory instance.
    </doc>
    <declare name = "zyre_backend" type = "zyre_backend_t *" />
    //
    if (!s_$(selfname)_active)
        self_initialise ();             //  Since we don't call $(selfname)_new
    zyre_backend = zyre_backend_new (NULL, self__zyre_backend_link, self__zyre_backend_unlink);
    zyre_backend->server_looseref = ipr_looseref_queue (
        s_zyre_backend_list, zyre_backend_link (zyre_backend));

    //  Build virtual methods for server-side methods
    zyre_backend->server_new = self__zyre_backend_new;
</method>

<method name = "_zyre_backend unbind shim" private = "1">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal reference</argument>
    self__zyre_backend_unbind (($(selftype) *) self_v, portal);
</method>
<method name = "_zyre_backend unbind" template = "async function">
    <doc>
    Server-to-portal unbind.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal reference</argument>
    //
    <action>
    if (portal->server_looseref) {
        ipr_looseref_destroy (&portal->server_looseref);
        zyre_backend_unlink (&portal);
    }
    </action>
</method>

<method name = "start shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_start (($(selftype) *) self_v, portal);
</method>
<method name = "start" async = "1" template = "function">
    <doc>
    This is the start incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <action></action>
</method>

<method name = "stop shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_stop (($(selftype) *) self_v, portal);
</method>
<method name = "stop" async = "1" template = "function">
    <doc>
    This is the stop incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <action></action>
</method>

<method name = "pipe create shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "pipe_type" type = "char *" />
    <argument name = "pipe_name" type = "char *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_pipe_create (($(selftype) *) self_v, portal, pipe_type, pipe_name);
</method>
<method name = "pipe create" async = "1" template = "function">
    <doc>
    This is the pipe create incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <argument name = "pipe_type" type = "char *" />
    <argument name = "pipe_name" type = "char *" />
    <possess>
    
        pipe_type = icl_mem_strdup (pipe_type);
        pipe_name = icl_mem_strdup (pipe_name);
      
    </possess>
    <release>
    
        icl_mem_free (pipe_type);
        icl_mem_free (pipe_name);
      
    </release>
    <action></action>
</method>

<method name = "pipe delete shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "pipe_name" type = "char *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_pipe_delete (($(selftype) *) self_v, portal, pipe_name);
</method>
<method name = "pipe delete" async = "1" template = "function">
    <doc>
    This is the pipe delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <argument name = "pipe_name" type = "char *" />
    <possess>
    
        pipe_name = icl_mem_strdup (pipe_name);
      
    </possess>
    <release>
    
        icl_mem_free (pipe_name);
      
    </release>
    <action></action>
</method>

<method name = "feed create shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "feed_type" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_feed_create (($(selftype) *) self_v, portal, feed_type, feed_name);
</method>
<method name = "feed create" async = "1" template = "function">
    <doc>
    This is the feed create incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <argument name = "feed_type" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <possess>
    
        feed_type = icl_mem_strdup (feed_type);
        feed_name = icl_mem_strdup (feed_name);
      
    </possess>
    <release>
    
        icl_mem_free (feed_type);
        icl_mem_free (feed_name);
      
    </release>
    <action></action>
</method>

<method name = "feed delete shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "feed_name" type = "char *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_feed_delete (($(selftype) *) self_v, portal, feed_name);
</method>
<method name = "feed delete" async = "1" template = "function">
    <doc>
    This is the feed delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <argument name = "feed_name" type = "char *" />
    <possess>
    
        feed_name = icl_mem_strdup (feed_name);
      
    </possess>
    <release>
    
        icl_mem_free (feed_name);
      
    </release>
    <action></action>
</method>

<method name = "join create shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "pipe_name" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <argument name = "address" type = "char *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_join_create (($(selftype) *) self_v, portal, pipe_name, feed_name, address);
</method>
<method name = "join create" async = "1" template = "function">
    <doc>
    This is the join create incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <argument name = "pipe_name" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <argument name = "address" type = "char *" />
    <possess>
    
        pipe_name = icl_mem_strdup (pipe_name);
        feed_name = icl_mem_strdup (feed_name);
        address = icl_mem_strdup (address);
      
    </possess>
    <release>
    
        icl_mem_free (pipe_name);
        icl_mem_free (feed_name);
        icl_mem_free (address);
      
    </release>
    <action></action>
</method>

<method name = "join delete shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "pipe_name" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <argument name = "address" type = "char *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_join_delete (($(selftype) *) self_v, portal, pipe_name, feed_name, address);
</method>
<method name = "join delete" async = "1" template = "function">
    <doc>
    This is the join delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <argument name = "pipe_name" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <argument name = "address" type = "char *" />
    <possess>
    
        pipe_name = icl_mem_strdup (pipe_name);
        feed_name = icl_mem_strdup (feed_name);
        address = icl_mem_strdup (address);
      
    </possess>
    <release>
    
        icl_mem_free (pipe_name);
        icl_mem_free (feed_name);
        icl_mem_free (address);
      
    </release>
    <action></action>
</method>

<method name = "address post shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "address" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <argument name = "content" type = "amq_content_basic_t *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_address_post (($(selftype) *) self_v, portal, address, feed_name, content);
</method>
<method name = "address post" async = "1" template = "function">
    <doc>
    This is the address post incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <argument name = "address" type = "char *" />
    <argument name = "feed_name" type = "char *" />
    <argument name = "content" type = "amq_content_basic_t *" />
    <possess>
    
        address = icl_mem_strdup (address);
        feed_name = icl_mem_strdup (feed_name);
        content = amq_content_basic_link (content);
      
    </possess>
    <release>
    
        icl_mem_free (address);
        icl_mem_free (feed_name);
        amq_content_basic_unlink (&content);
      
    </release>
    <action></action>
</method>

<method name = "forward shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "exchange" type = "char *" />
    <argument name = "routing_key" type = "char *" />
    <argument name = "content" type = "amq_content_basic_t *" />
    <argument name = "mandatory" type = "Bool" />
    <argument name = "immediate" type = "Bool" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_forward (($(selftype) *) self_v, portal, exchange, routing_key, content, mandatory, immediate);
</method>
<method name = "forward" async = "1" template = "function">
    <doc>
    This is the forward incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <argument name = "exchange" type = "char *" />
    <argument name = "routing_key" type = "char *" />
    <argument name = "content" type = "amq_content_basic_t *" />
    <argument name = "mandatory" type = "Bool" />
    <argument name = "immediate" type = "Bool" />
    <possess>
    
        exchange = icl_mem_strdup (exchange);
        routing_key = icl_mem_strdup (routing_key);
        content = amq_content_basic_link (content);
      
    </possess>
    <release>
    
        icl_mem_free (exchange);
        icl_mem_free (routing_key);
        amq_content_basic_unlink (&content);
      
    </release>
    <action></action>
</method>

<method name = "online partial shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_online_partial (($(selftype) *) self_v, portal);
</method>
<method name = "online partial" async = "1" template = "function">
    <doc>
    This is the online partial incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <action></action>
</method>

<method name = "online final shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_online_final (($(selftype) *) self_v, portal);
</method>
<method name = "online final" async = "1" template = "function">
    <doc>
    This is the online final incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to client</argument>
    <action></action>
</method>

<!-- These two methods provide untyped link/unlink methods that can be
     called from the portal to work on the server object.
  -->
<method name = "_zyre_backend link" return = "object" private = "1">
    <argument name = "object" type = "void *">Reference cast as a void *</argument>
    //
    object = (void *) $(selfname)_link ((($(selftype) *) object));
</method>

<method name = "_zyre_backend unlink" private = "1">
    <argument name = "object_p" type = "void *">Reference pointer cast as a void *</argument>
    //
    $(selfname)_unlink ((($(selftype) **) object_p));
</method>

<method name = "selftest" />

</class>
