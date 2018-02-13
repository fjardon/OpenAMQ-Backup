<?xml?>
<class
    name      = "icl_cache_list"
    comment   = "Implements the list container for icl_cache"
    version   = "1.0"
    script    = "icl_gen"
    >
<doc>
    This class implements the list container for icl_cache
</doc>

<option name = "links"      value = "0" />

<inherit class = "icl_list_head" >
    <option name = "prefix"     value = "list"/>
    <option name = "childname"  value = "icl_cache" />
    <option name = "childtype"  value = "icl_cache_t" />
    <option name = "count"      value = "0" />
    <option name = "child_has_links"    value = "0"/>
    <option name = "link_to_child"      value = "0"/>
</inherit>
<option name = "rwlock"    value = "0" />
<option name = "mutex"     value = "1" />
<option name = "alloc"     value = "direct" />
<option name = "stats"     value = "1" />
<option name = "trace"     value = "0" />
<option name = "animate"   value = "1" />

<import class = "icl_cache" />

<context>
    <!-- add properties for the container -->
</context>

<method name = "new">
    <!-- any initialisation code you need -->
</method>

<method name = "destroy">
    <!-- any destruction code you need, note that the list is
         automatically destroyed, you don't need to do this.
      -->
</method>

<method name = "selftest">
    <!-- Add your selftest code -->
    <local>
    </local>
</method>
</class>
