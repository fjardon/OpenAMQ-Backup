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
    name      = "ipr_bucket_list"
    comment   = "list of ipr_buckets"
    version   = "1.0"
    script    = "icl_gen"
    >

<inherit class = "icl_iter_list_head" >
    <option name = "prefix"     value = "list"/>
    <option name = "childname"  value = "ipr_bucket" />
    <option name = "childtype"  value = "ipr_bucket_t" />
</inherit>
<option name = "alloc"     value = "cache" />

<import class = "ipr_bucket" />

<method name = "clear" template = "function">
    <doc>
    Removes all the buckets from the list.
    </doc>
    <local>
    $(selfname)_iter_t
        *item;
    </local>
    item = ($(selfname)_iter_t *) self->$(selfname)_iter.next;
    while (item != &self->$(selfname)_iter) {
        $(selfname)_unhook (item);
        
        $(selfname)_iter_destroy (&item);
        item = ($(selfname)_iter_t *) self->$(selfname)_iter.next;
    }
</method>

<method name = "selftest">
</method>

</class>
