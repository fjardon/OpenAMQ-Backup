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
    name     = "zyre_backend_front"
    comment  = "Portal front-end - async client wrapper"
    script   = "smt_object_gen"
    target   = "smt"
    abstract = "1"
    >

<inherit class = "smt_object" />

<import class = "zyre_backend" />
<import class = "ipr_looseref" />
<import class = "zyre_classes" />

<context>
    ipr_looseref_list_t
        *zyre_backend_list,             //  List of all own portals
        *zyre_backend_factory_list;     //  List of all own portal factories
    Bool
        zyre_backend_stopped;           //  Is this portal stopped?
</context>

<method name = "new">
    self->zyre_backend_list = ipr_looseref_list_new ();
    self->zyre_backend_factory_list = ipr_looseref_list_new ();
</method>

<method name = "destroy">
    <action>
    {
    zyre_backend_t
        *zyre_backend;                  //  Portal object

    if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_backend_stopped, TRUE, FALSE) == FALSE) {
        //  Destroy own portals
        while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_list))) {
            zyre_backend->client_looseref = NULL;
            zyre_backend_destroy (&zyre_backend);
        }
        ipr_looseref_list_destroy (&self->zyre_backend_list);
        //  Destroy own portal factories
        while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_factory_list))) {
            zyre_backend->client_looseref = NULL;
            zyre_backend_destroy (&zyre_backend);
        }
        ipr_looseref_list_destroy (&self->zyre_backend_factory_list);
    }
    }
    </action>
</method>

<method name = "_zyre_backend bind" template = "function">
    <doc>
    Binds a zyre_backend portal, ready for use.
    </doc>
    <argument name = "zyre_backend" type = "zyre_backend_t *">Portal reference</argument>
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
</method>

<!--
    The shims provide a way for us to cast void * into a correctly-typed
    reference that works for passing to async methods, since we cannot make
    async methods that accept a void pointer.
 -->
<method name = "_zyre_backend unbind shim" private = "1">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal reference</argument>
    self__zyre_backend_unbind (($(selftype) *) self_v, portal);
</method>
<method name = "_zyre_backend unbind" template = "async function">
    <doc>
    Client-to-portal unbind.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal reference</argument>
    <action>
    if (portal->client_looseref) {
        ipr_looseref_destroy (&portal->client_looseref);
        zyre_backend_unlink (&portal);
    }
    </action>
</method>

<method name = "online shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "reply_queue" type = "char *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_online (($(selftype) *) self_v, portal, reply_queue);
</method>
<method name = "online" async = "1" template = "function">
    <doc>
    This is the online incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "reply_queue" type = "char *" />
    <possess>
    
        reply_queue = icl_mem_strdup (reply_queue);
      
    </possess>
    <release>
    
        icl_mem_strfree (&reply_queue);
      
    </release>
    <action></action>
</method>

<method name = "offline shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_offline (($(selftype) *) self_v, portal);
</method>
<method name = "offline" async = "1" template = "function">
    <doc>
    This is the offline incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <action></action>
</method>

<method name = "arrived shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "method" type = "zyre_peer_method_t *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_arrived (($(selftype) *) self_v, portal, method);
</method>
<method name = "arrived" async = "1" template = "function">
    <doc>
    This is the arrived incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "method" type = "zyre_peer_method_t *" />
    <possess>
    
        method = zyre_peer_method_link (method);
      
    </possess>
    <release>
    
        zyre_peer_method_unlink (&method);
      
    </release>
    <action></action>
</method>

<method name = "returned shim" private = "1" return = "rc">
    <argument name = "self_v" type = "void *">Self as void pointer</argument>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "method" type = "zyre_peer_method_t *" />
    <declare name = "rc" type = "int" default = "0">Return code</declare>
    rc = self_returned (($(selftype) *) self_v, portal, method);
</method>
<method name = "returned" async = "1" template = "function">
    <doc>
    This is the returned incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    </doc>
    <argument name = "portal" type = "zyre_backend_t *">Portal back to server</argument>
    <argument name = "method" type = "zyre_peer_method_t *" />
    <possess>
    
        method = zyre_peer_method_link (method);
      
    </possess>
    <release>
    
        zyre_peer_method_unlink (&method);
      
    </release>
    <action></action>
</method>


<method name = "selftest" />

</class>
