<?xml?>
<class
    name      = "amq_binding_list"
    comment   = "Implements the list container for amq_binding"
    version   = "1.0"
    script    = "icl_gen"
    >
<doc>
    This class implements the list container for amq_binding
</doc>

<option name = "links"      value = "1" />

<inherit class = "icl_list_head" >
    <option name = "prefix"     value = "list"/>
    <option name = "childname"  value = "amq_binding" />
    <option name = "childtype"  value = "amq_binding_t" />
    <option name = "count"      value = "1" />
</inherit>
<option name = "rwlock" value = "0" />
<option name = "mutex"  value = "0" />
<option name = "alloc"  value = "cache" />

<import class = "amq_binding" />

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
