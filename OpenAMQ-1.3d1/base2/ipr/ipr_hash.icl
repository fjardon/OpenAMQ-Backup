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
    name      = "ipr_hash"
    comment   = "A loose reference hash"
    version   = "1.0"
    script    = "icl_gen"
    >
<doc>
Implements a loose-reference hash with no locking, for use in
lock-free agents.
</doc>

<inherit class = "icl_object">
    <option name = "alloc"  value = "cache" />
    <option name = "rwlock" value = "0" />
</inherit>
<inherit class = "icl_hash_item">
    <option name = "hash_type" value = "str" />
    <option name = "rwlock"    value = "0" />
</inherit>

<context>
    void *data;
</context>

<method name = "new" >
    <argument name = "data" type = "void *" />
    //
    self->data = data;
</method>

<method name = "selftest">
    ipr_hash_table_t
        *table;
    ipr_hash_t
        *hash;
        
    table = ipr_hash_table_new ();
    hash = ipr_hash_new (table, "tmp_000000", NULL);
    ipr_hash_unlink (&hash);

    hash = ipr_hash_table_search (table, "tmp_000000");
    assert (hash);
    ipr_hash_destroy (&hash);
    ipr_hash_table_destroy (&table);
</method>

</class>
