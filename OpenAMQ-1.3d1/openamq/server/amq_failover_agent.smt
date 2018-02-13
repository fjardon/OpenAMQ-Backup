<?xml?>
<!---------------------------------------------------------------------------
    amq_failover_agent.smt - amq_failover component

    Generated from amq_failover.icl by smt_object_gen using GSL/4.

    
    Copyright (c) 1996-2009 iMatix Corporation
    
    This file is licensed under the GPL as follows:
    
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
 ----------------------------------------------------------------------------->

<agent
    name = "amq_failover_agent"
    script = "smt_gen.gsl"
    animate = "1"
    >
<import class = "amq_failover" />

<method name = "start_monitoring">
</method>

<method name = "destroy">
    <argument name = "file" type = "char *" />
    <argument name = "line" type = "size_t" />
</method>

<thread name = "class">
    <context>
        amq_failover_t
            *amq_failover;
    </context>
    
    <handler name = "thread new">
        <argument name = "self" type = "amq_failover_t *">The iCL object</argument>
        tcb->amq_failover = self;
    </handler>
        
    <state name = "main">

        <method name = "start_monitoring"  >
            <action name = "start_monitoring">

#define self tcb->amq_failover

        {
smt_timer_request_delay (self->thread, self->timeout / 2, monitor_event);
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>


        <method name = "destroy"  nextstate = ""  >
            <action name = "free">

#define self tcb->amq_failover
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_failover object");
    amq_failover_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_failover_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <event name = "monitor"  >
            <action name = "monitor">
            
#define self tcb->amq_failover

        {
//  Send state notification to failover peer
//  We do this unconditionally; if the failover peer is not present the
//  message will be discarded (it's sent to the status exchange).
amq_failover_send_state (self);

//  Schedule new monitoring event
smt_timer_request_delay (self->thread, self->timeout / 2, monitor_event);
        }
        
#undef self
            </action>
        </event>
        <event name = "shutdown" nextstate = "shutting down" />
    </state>
    
    <state name = "shutting down">

        <method name = "destroy"  nextstate = ""  >
            <action name = "free">

#define self tcb->amq_failover
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("Missing link on amq_failover object");
    amq_failover_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}

if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    amq_failover_free (self);
    self = NULL;
}
        }
#undef self
            </action>
            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        </method>

        <method name = "start_monitoring" />
        <event name = "monitor" />
    </state>
</thread>

</agent>
