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
    name     = "zyre_resource_front"
    comment  = "Portal front-end - sync client wrapper"
    script   = "icl_gen"
    abstract = "1"
    >

<!-- Force use of links in any case -->
<inherit class = "icl_object">
    <option name = "links" value = "1" />
</inherit>

<import class = "zyre_resource" />
<import class = "ipr_looseref" />
<import class = "zyre_classes" />

<context>
    ipr_looseref_list_t
        *zyre_resource_list,            //  List of all own portals
        *zyre_resource_factory_list;    //  List of all own portal factories
    Bool
        zyre_resource_stopped;          //  Is this portal stopped?
</context>

<method name = "new">
    self->zyre_resource_list = ipr_looseref_list_new ();
    self->zyre_resource_factory_list = ipr_looseref_list_new ();
</method>

<method name = "destroy">
    <local>
    zyre_resource_t
        *zyre_resource;                 //  Portal object
    </local>
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
</method>

<method name = "_zyre_resource bind" template = "function">
    <doc>
    Binds a zyre_resource portal, ready for use. This method is for use
    outside the zyre_resource class.
    </doc>
    <argument name = "zyre_resource" type = "zyre_resource_t *">Portal reference</argument>
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
</method>

<method name = "_zyre_resource unbind" private = "1">
    <doc>
    Client-to-portal unbind.
    </doc>
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_resource_t *">Portal reference</argument>
    //
    //  Drop link to portal and remove portal from our list of active portals
    if (portal->client_looseref) {
        ipr_looseref_destroy (&portal->client_looseref);
        zyre_resource_unlink (&portal);
    }
</method>

<method name = "child add" private = "1" return = "rc">
    <doc>
    This is the child add incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_resource_t *">Portal back to server</argument>
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


<method name = "selftest" />

</class>
