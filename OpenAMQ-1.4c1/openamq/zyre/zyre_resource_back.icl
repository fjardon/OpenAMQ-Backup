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
    name     = "zyre_resource_back"
    comment  = "Portal back-end - sync server wrapper"
    script   = "icl_gen"
    abstract = "1"
    >

<!-- Force use of links in any case -->
<inherit class = "icl_object">
    <option name = "links" value = "1" />
</inherit>
<inherit class = "icl_init" />

<import class = "zyre_resource" />
<import class = "zyre_classes" />

<private name = "header">
static ipr_looseref_list_t
    *s_zyre_resource_list;              //  List of portal factories
static Bool
    s_zyre_resource_stopped;            //  Is this portal factory stopped?
</private>

<context>
    ipr_looseref_list_t
        *zyre_resource_list;            //  List of portals for object
    Bool
        zyre_resource_stopped;          //  Is this portal stopped?
</context>

<method name = "new">
    self->zyre_resource_list = ipr_looseref_list_new ();
</method>

<method name = "destroy">
    <local>
    zyre_resource_t
        *zyre_resource;                 //  Portal object
    </local>
    //
    if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_resource_stopped, TRUE, FALSE) == FALSE) {
        while ((zyre_resource = (zyre_resource_t *) ipr_looseref_pop (self->zyre_resource_list))) {
            zyre_resource->server_looseref = NULL;
            zyre_resource_destroy (&zyre_resource);
        }
    }
    ipr_looseref_list_destroy (&self->zyre_resource_list);
</method>

<method name = "initialise">
    s_zyre_resource_list = ipr_looseref_list_new ();
</method>

<method name = "terminate">
    <local>
    zyre_resource_t
        *zyre_resource;                 //  Portal factory object
    </local>
    //
    if (icl_atomic_cas32 ((volatile qbyte *) &s_zyre_resource_stopped, TRUE, FALSE) == FALSE) {
        while ((zyre_resource = (zyre_resource_t *) ipr_looseref_pop (s_zyre_resource_list))) {
            zyre_resource->server_looseref = NULL;
            zyre_resource_destroy (&zyre_resource);
        }
    }
    ipr_looseref_list_destroy (&s_zyre_resource_list);
</method>

<method name = "_zyre_resource new" return = "zyre_resource">
    <doc>
    Creates and initialises a new portal instance.  If the _server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    </doc>
    <argument name = "self_v" type = "void *">Untyped server reference</argument>
    <argument name = "parent" type = "zyre_resource_t *" />
    <argument name = "table" type = "ipr_hash_table_t *" />
    <argument name = "type" type = "char *" />
    <argument name = "name" type = "char *" />
    <declare name = "zyre_resource" type = "zyre_resource_t *" />
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
</method>

<method name = "_zyre_resource factory" return = "zyre_resource">
    <doc>
    Creates and initialises a new portal factory instance.
    </doc>
    <argument name = "parent" type = "zyre_resource_t *" />
    <argument name = "table" type = "ipr_hash_table_t *" />
    <argument name = "type" type = "char *" />
    <argument name = "name" type = "char *" />
    <declare name = "zyre_resource" type = "zyre_resource_t *" />
    //
    if (!s_$(selfname)_active)
        self_initialise ();             //  Since we don't call $(selfname)_new
    zyre_resource = zyre_resource_new (NULL, self__zyre_resource_link, self__zyre_resource_unlink, parent, table, type, name);
    zyre_resource->server_looseref = ipr_looseref_queue (
        s_zyre_resource_list, zyre_resource_link (zyre_resource));

    //  Build virtual methods for server-side methods
    zyre_resource->server_new = self__zyre_resource_new;
</method>

<method name = "_zyre_resource unbind" private = "1">
    <doc>
    Server-to-portal unbind.
    </doc>
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_resource_t *">Portal reference</argument>
    //
    //  Drop link to portal and remove portal from our list of active portals
    if (portal->server_looseref) {
        ipr_looseref_destroy (&portal->server_looseref);
        zyre_resource_unlink (&portal);
    }
</method>

<method name = "configure" private = "1" return = "rc">
    <doc>
    This is the configure incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_resource_t *">Portal back to client</argument>
    <argument name = "context" type = "http_driver_context_t *" />
    <argument name = "table" type = "ipr_hash_table_t *" />
    <argument name = "backend" type = "zyre_backend_t *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    <local>
    $(selftype)
        *self;
    </local>
    <header>
    self = ($(selftype) *) self_v;
    </header>
</method>

<method name = "get" private = "1" return = "rc">
    <doc>
    This is the get incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_resource_t *">Portal back to client</argument>
    <argument name = "context" type = "http_driver_context_t *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    <local>
    $(selftype)
        *self;
    </local>
    <header>
    self = ($(selftype) *) self_v;
    </header>
</method>

<method name = "put" private = "1" return = "rc">
    <doc>
    This is the put incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_resource_t *">Portal back to client</argument>
    <argument name = "context" type = "http_driver_context_t *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    <local>
    $(selftype)
        *self;
    </local>
    <header>
    self = ($(selftype) *) self_v;
    </header>
</method>

<method name = "delete" private = "1" return = "rc">
    <doc>
    This is the delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_resource_t *">Portal back to client</argument>
    <argument name = "context" type = "http_driver_context_t *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    <local>
    $(selftype)
        *self;
    </local>
    <header>
    self = ($(selftype) *) self_v;
    </header>
</method>

<method name = "post" private = "1" return = "rc">
    <doc>
    This is the post incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_resource_t *">Portal back to client</argument>
    <argument name = "context" type = "http_driver_context_t *" />
    <argument name = "table" type = "ipr_hash_table_t *" />
    <argument name = "backend" type = "zyre_backend_t *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    <local>
    $(selftype)
        *self;
    </local>
    <header>
    self = ($(selftype) *) self_v;
    </header>
</method>

<method name = "report" private = "1" return = "rc">
    <doc>
    This is the report incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_resource_t *">Portal back to client</argument>
    <argument name = "context" type = "http_driver_context_t *" />
    <argument name = "tree" type = "ipr_tree_t *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    <local>
    $(selftype)
        *self;
    </local>
    <header>
    self = ($(selftype) *) self_v;
    </header>
</method>

<method name = "attach" private = "1" return = "rc">
    <doc>
    This is the attach incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_resource_t *">Portal back to client</argument>
    <argument name = "resource" type = "zyre_resource_t *" />
    <argument name = "argument" type = "void *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    <local>
    $(selftype)
        *self;
    </local>
    <header>
    self = ($(selftype) *) self_v;
    </header>
</method>

<method name = "detach" private = "1" return = "rc">
    <doc>
    This is the detach incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_resource_t *">Portal back to client</argument>
    <argument name = "resource" type = "zyre_resource_t *" />
    <argument name = "argument" type = "void *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    <local>
    $(selftype)
        *self;
    </local>
    <header>
    self = ($(selftype) *) self_v;
    </header>
</method>

<!-- These two methods provide untyped link/unlink methods that can be
     called from the portal to work on the server object.
  -->
<method name = "_zyre_resource link" return = "object" private = "1">
    <argument name = "object" type = "void *">Reference cast as a void *</argument>
    //
    object = (void *) $(selfname)_link ((($(selftype) *) object));
</method>

<method name = "_zyre_resource unlink" private = "1">
    <argument name = "object_p" type = "void *">Reference pointer cast as a void *</argument>
    //
    $(selfname)_unlink ((($(selftype) **) object_p));
</method>

<method name = "selftest" />

</class>
