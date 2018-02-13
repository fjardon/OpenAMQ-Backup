<?xml?>
<class
    name      = "amq_index_array"
    comment   = "Implements the array container for amq_index"
    version   = "1.0"
    script    = "icl_gen"
    >
<doc>
    This class implements the array container for amq_index
</doc>

<inherit class = "icl_array_head" >
    <option name = "links"      value = "1" />
    <option name = "prefix"     value = "array"/>
    <option name = "childname"  value = "amq_index" />
    <option name = "childtype"  value = "amq_index_t" />
    <option name = "count"      value = "1" />
    <option name = "link_to_child" value = "1"/>
</inherit>
<option name = "rwlock" value = "0" />
<option name = "alloc"  value = "cache" />

<import class = "amq_index" />

<context>
    <!-- add properties for the container -->
</context>

<method name = "new">
    <!-- any initialisation code you need -->
</method>

<method name = "destroy">
    <!-- any destruction code you need -->
</method>

<method name = "selftest">
    <!-- Add your selftest code -->
    <local>
    </local>
</method>
</class>
