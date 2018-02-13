<?xml?>
<class
    name      = "amq_connection_by_broker"
    comment   = "Implements the list container for amq_connection"
    version   = "1.0"
    script    = "icl_gen"
    >
<doc>
    This class implements the list container for amq_connection
</doc>

<option name = "links"      value = "1" />

<inherit class = "icl_list_head" >
    <option name = "prefix"     value = "by_broker"/>
    <option name = "childname"  value = "amq_connection" />
    <option name = "childtype"  value = "amq_connection_t" />
    <option name = "count"      value = "0" />
</inherit>
<option name = "rwlock"    value = "1" />
<option name = "mutex"     value = "0" />
<option name = "alloc"     value = "cache" />
<option name = "stats"     value = "1" />
<option name = "trace"     value = "1" />
<option name = "animate"   value = "1" />

<import class = "amq_connection" />

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
