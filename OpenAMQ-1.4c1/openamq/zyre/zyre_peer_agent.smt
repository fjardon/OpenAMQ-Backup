<?xml?>
<!--
    *** GENERATED FROM zyre_peer.asl BY ASL_GEN USING GSL/4 ***

    
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
 -->
<agent
    name      = "zyre_peer_agent"
    script    = "smt_gen.gsl"
    animate   = "1"
    license   = "gpl"
    >

<!--  Theory of operation

      See amq_server_agent.smt.
-->

<import class = "asl"/>
<import class = "asl_field"/>
<import class = "amq_constants"/>
<import class = "zyre_peer_method"/>
<import class = "amq_content_basic"/>

<private name = "types">
#define BASE_ANIMATE            1
#define FULL_LIVENESS           4       //  Four missing heartbeats -> dead

//  Channel states
#define ASL_CHANNEL_CLOSED      0
#define ASL_CHANNEL_OPEN        1
#define ASL_CHANNEL_CLOSING     2
#define ASL_CHANNEL_OPENING     3

#include "version.h"
</private>

<!--  Catch SMT error codes                                                 -->

<catch error = "SMT_SOCKET_ERROR"   event = "socket error" />
<catch error = "SMT_SOCKET_CLOSING" event = "socket closing" />
<catch error = "SMT_TIMEOUT"        event = "socket timeout" />
<catch                              event = "smt error" />

<!---------------------------------------------------------------------------->
<!--  Application methods that the agent accepts                            -->

<!-- Open a Channel For Use                                                 -->
<method name = "channel open">
    <argument name = "channel nbr"  type = "dbyte" />
</method>

<!-- Request a Channel Close                                                -->
<method name = "channel close">
    <argument name = "channel nbr"  type = "dbyte" />
</method>

<!-- Request a Connection Close                                             -->
<method name = "connection close">
</method>

<!--  Called by input thread when a connection tune is received -->
<method name = "connection tune" priority = "high">
</method>

<!--  Called by input thread when a connection open ok is received -->
<method name = "connection open ok" priority = "high">
</method>

<!--  Called by input thread when a channel close is received -->
<method name = "send channel close ok" priority = "high">
</method>

<!--  Called by input thread when a connection close ok is received -->
<method name = "connection close ok" priority = "high">
</method>


<!--  Outgoing protocol methods                                             -->

<!-- Enable/Disable Flow From Peer -->
<method name = "channel flow">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "active"       type = "Bool" />
    <possess>
    </possess>
    <release>
    </release>
</method>

<!-- Confirm A Flow Method -->
<method name = "channel flow-ok">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "active"       type = "Bool" />
    <possess>
    </possess>
    <release>
    </release>
</method>

<!-- Declare Exchange, Create If Needed -->
<method name = "exchange declare">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "ticket"       type = "int" />
    <argument name = "exchange"     type = "char *" />
    <argument name = "type"         type = "char *" />
    <argument name = "passive"      type = "Bool" />
    <argument name = "durable"      type = "Bool" />
    <argument name = "auto_delete"  type = "Bool" />
    <argument name = "internal"     type = "Bool" />
    <argument name = "nowait"       type = "Bool" />
    <argument name = "arguments"    type = "icl_longstr_t *" />
    <possess>
        exchange = icl_mem_strdup (exchange);
        type = icl_mem_strdup (type);
        arguments = icl_longstr_dup (arguments);
    </possess>
    <release>
        icl_mem_free (exchange);
        icl_mem_free (type);
        icl_longstr_destroy (&arguments);
    </release>
</method>

<!-- Delete An Exchange -->
<method name = "exchange delete">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "ticket"       type = "int" />
    <argument name = "exchange"     type = "char *" />
    <argument name = "if_unused"    type = "Bool" />
    <argument name = "nowait"       type = "Bool" />
    <possess>
        exchange = icl_mem_strdup (exchange);
    </possess>
    <release>
        icl_mem_free (exchange);
    </release>
</method>

<!-- Declare Queue, Create If Needed -->
<method name = "queue declare">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "ticket"       type = "int" />
    <argument name = "queue"        type = "char *" />
    <argument name = "passive"      type = "Bool" />
    <argument name = "durable"      type = "Bool" />
    <argument name = "exclusive"    type = "Bool" />
    <argument name = "auto_delete"  type = "Bool" />
    <argument name = "nowait"       type = "Bool" />
    <argument name = "arguments"    type = "icl_longstr_t *" />
    <possess>
        queue = icl_mem_strdup (queue);
        arguments = icl_longstr_dup (arguments);
    </possess>
    <release>
        icl_mem_free (queue);
        icl_longstr_destroy (&arguments);
    </release>
</method>

<!-- Bind Queue To An Exchange -->
<method name = "queue bind">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "ticket"       type = "int" />
    <argument name = "queue"        type = "char *" />
    <argument name = "exchange"     type = "char *" />
    <argument name = "routing_key"  type = "char *" />
    <argument name = "nowait"       type = "Bool" />
    <argument name = "arguments"    type = "icl_longstr_t *" />
    <possess>
        queue = icl_mem_strdup (queue);
        exchange = icl_mem_strdup (exchange);
        routing_key = icl_mem_strdup (routing_key);
        arguments = icl_longstr_dup (arguments);
    </possess>
    <release>
        icl_mem_free (queue);
        icl_mem_free (exchange);
        icl_mem_free (routing_key);
        icl_longstr_destroy (&arguments);
    </release>
</method>

<!-- Purge A Queue -->
<method name = "queue purge">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "ticket"       type = "int" />
    <argument name = "queue"        type = "char *" />
    <argument name = "nowait"       type = "Bool" />
    <possess>
        queue = icl_mem_strdup (queue);
    </possess>
    <release>
        icl_mem_free (queue);
    </release>
</method>

<!-- Delete A Queue -->
<method name = "queue delete">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "ticket"       type = "int" />
    <argument name = "queue"        type = "char *" />
    <argument name = "if_unused"    type = "Bool" />
    <argument name = "if_empty"     type = "Bool" />
    <argument name = "nowait"       type = "Bool" />
    <possess>
        queue = icl_mem_strdup (queue);
    </possess>
    <release>
        icl_mem_free (queue);
    </release>
</method>

<!-- Unbind Queue From An Exchange -->
<method name = "queue unbind">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "ticket"       type = "int" />
    <argument name = "queue"        type = "char *" />
    <argument name = "exchange"     type = "char *" />
    <argument name = "routing_key"  type = "char *" />
    <argument name = "nowait"       type = "Bool" />
    <argument name = "arguments"    type = "icl_longstr_t *" />
    <possess>
        queue = icl_mem_strdup (queue);
        exchange = icl_mem_strdup (exchange);
        routing_key = icl_mem_strdup (routing_key);
        arguments = icl_longstr_dup (arguments);
    </possess>
    <release>
        icl_mem_free (queue);
        icl_mem_free (exchange);
        icl_mem_free (routing_key);
        icl_longstr_destroy (&arguments);
    </release>
</method>

<!-- Specify Quality Of Service -->
<method name = "basic qos">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "prefetch_size"  type = "qbyte" />
    <argument name = "prefetch_count"  type = "int" />
    <argument name = "global"       type = "Bool" />
    <possess>
    </possess>
    <release>
    </release>
</method>

<!-- Start A Queue Consumer -->
<method name = "basic consume">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "ticket"       type = "int" />
    <argument name = "queue"        type = "char *" />
    <argument name = "consumer_tag"  type = "char *" />
    <argument name = "no_local"     type = "Bool" />
    <argument name = "no_ack"       type = "Bool" />
    <argument name = "exclusive"    type = "Bool" />
    <argument name = "nowait"       type = "Bool" />
    <argument name = "arguments"    type = "icl_longstr_t *" />
    <possess>
        queue = icl_mem_strdup (queue);
        consumer_tag = icl_mem_strdup (consumer_tag);
        arguments = icl_longstr_dup (arguments);
    </possess>
    <release>
        icl_mem_free (queue);
        icl_mem_free (consumer_tag);
        icl_longstr_destroy (&arguments);
    </release>
</method>

<!-- End A Queue Consumer -->
<method name = "basic cancel">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "consumer_tag"  type = "char *" />
    <argument name = "nowait"       type = "Bool" />
    <possess>
        consumer_tag = icl_mem_strdup (consumer_tag);
    </possess>
    <release>
        icl_mem_free (consumer_tag);
    </release>
</method>

<!-- Publish A Message -->
<method name = "basic publish">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "content"      type = "amq_content_basic_t *" />
    <argument name = "ticket"       type = "int" />
    <argument name = "exchange"     type = "char *" />
    <argument name = "routing_key"  type = "char *" />
    <argument name = "mandatory"    type = "Bool" />
    <argument name = "immediate"    type = "Bool" />
    <possess>
        assert (content);
        content = amq_content_basic_link (content);
        exchange = icl_mem_strdup (exchange);
        routing_key = icl_mem_strdup (routing_key);
    </possess>
    <release>
        amq_content_basic_unlink (&content);
        icl_mem_free (exchange);
        icl_mem_free (routing_key);
    </release>
</method>

<!-- Direct Access To A Queue -->
<method name = "basic get">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "ticket"       type = "int" />
    <argument name = "queue"        type = "char *" />
    <argument name = "no_ack"       type = "Bool" />
    <possess>
        queue = icl_mem_strdup (queue);
    </possess>
    <release>
        icl_mem_free (queue);
    </release>
</method>

<!-- Acknowledge One Or More Messages -->
<method name = "basic ack">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "delivery_tag"  type = "int64_t" />
    <argument name = "multiple"     type = "Bool" />
    <possess>
    </possess>
    <release>
    </release>
</method>

<!-- Reject An Incoming Message -->
<method name = "basic reject">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "delivery_tag"  type = "int64_t" />
    <argument name = "requeue"      type = "Bool" />
    <possess>
    </possess>
    <release>
    </release>
</method>

<!-- Request A Connection To A Sink -->
<method name = "direct put">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "sink"         type = "char *" />
    <possess>
        sink = icl_mem_strdup (sink);
    </possess>
    <release>
        icl_mem_free (sink);
    </release>
</method>

<!-- Request A Connection To A Feed -->
<method name = "direct get">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "feed"         type = "char *" />
    <possess>
        feed = icl_mem_strdup (feed);
    </possess>
    <release>
        icl_mem_free (feed);
    </release>
</method>

<!-- Create A Pipe -->
<method name = "restms pipe-create">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "pipe_type"    type = "char *" />
    <argument name = "pipe_name"    type = "char *" />
    <possess>
        pipe_type = icl_mem_strdup (pipe_type);
        pipe_name = icl_mem_strdup (pipe_name);
    </possess>
    <release>
        icl_mem_free (pipe_type);
        icl_mem_free (pipe_name);
    </release>
</method>

<!-- Delete A Pipe -->
<method name = "restms pipe-delete">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "pipe_name"    type = "char *" />
    <possess>
        pipe_name = icl_mem_strdup (pipe_name);
    </possess>
    <release>
        icl_mem_free (pipe_name);
    </release>
</method>

<!-- Create A Feed -->
<method name = "restms feed-create">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "feed_type"    type = "char *" />
    <argument name = "feed_name"    type = "char *" />
    <possess>
        feed_type = icl_mem_strdup (feed_type);
        feed_name = icl_mem_strdup (feed_name);
    </possess>
    <release>
        icl_mem_free (feed_type);
        icl_mem_free (feed_name);
    </release>
</method>

<!-- Delete A Feed -->
<method name = "restms feed-delete">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "feed_name"    type = "char *" />
    <possess>
        feed_name = icl_mem_strdup (feed_name);
    </possess>
    <release>
        icl_mem_free (feed_name);
    </release>
</method>

<!-- Create A Join -->
<method name = "restms join-create">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "pipe_name"    type = "char *" />
    <argument name = "feed_name"    type = "char *" />
    <argument name = "address"      type = "char *" />
    <possess>
        pipe_name = icl_mem_strdup (pipe_name);
        feed_name = icl_mem_strdup (feed_name);
        address = icl_mem_strdup (address);
    </possess>
    <release>
        icl_mem_free (pipe_name);
        icl_mem_free (feed_name);
        icl_mem_free (address);
    </release>
</method>

<!-- Delete A Join -->
<method name = "restms join-delete">
    <argument name = "channel nbr"  type = "dbyte" />
    <argument name = "pipe_name"    type = "char *" />
    <argument name = "feed_name"    type = "char *" />
    <argument name = "address"      type = "char *" />
    <possess>
        pipe_name = icl_mem_strdup (pipe_name);
        feed_name = icl_mem_strdup (feed_name);
        address = icl_mem_strdup (address);
    </possess>
    <release>
        icl_mem_free (pipe_name);
        icl_mem_free (feed_name);
        icl_mem_free (address);
    </release>
</method>

<!-- Pass an already-prepared method to the server                          -->
<method name = "push">
    <argument name = "channel nbr" type = "dbyte" />
    <argument name = "method" type = "zyre_peer_method_t *" />
    <possess>
        method = zyre_peer_method_link (method);
    </possess>
    <release>
        zyre_peer_method_unlink (&method);
    </release>
</method>

<public name = "types">
//  See session layer for what these mean
#define ZYRE_PEER_REPLY_ALMOST       1
#define ZYRE_PEER_REPLY_INTERN       2
#define ZYRE_PEER_REPLY_METHOD       3
#define ZYRE_PEER_REPLY_CLOSED       4
#define ZYRE_PEER_REPLY_DIRECT_OK    5
#define ZYRE_PEER_REPLY_DIRECT_NG    6
#define ZYRE_PEER_REPLY_DIRECT_MSG 7
</public>

<!---------------------------------------------------------------------------->
<!--  Initialise agent                                                      -->

<handler name = "agent init">
</handler>

<!---------------------------------------------------------------------------->
<!--  Connection context                                                    -->

<context name = "connection">
    smt_thread_t
        *connection_thread,             //  Master thread
        *input_thread,                  //  Socket input thread
        *heartbeat_thread;              //  Heartbeat monitor thread
    smt_socket_t
        *socket;                        //  Socket for i/o
    int
        channel_state;                  //  Internal channel state
    zyre_peer_method_t
        *method_in,                     //  Last received method
        *method_out;                    //  Method currently being sent
    asl_reader_t
        reader;                         //  Body reader
    ipr_bucket_t
        *bucket_in;                     //  Last received bucket
    byte
        protocol_header [8];            //  Used to initiate connection
    asl_frame_header_t
        frame_header;                   //  Header for frame i/o
    dbyte
        reply_code;                     //  Exception error code
    icl_shortstr_t
        reply_text;                     //  Exception error text
    icl_shortstr_t
        strerror;                       //  Reply text for method errors
    dbyte
        out_class_id,                   //  Last class we sent
        out_method_id;                  //  Last method we sent
    qbyte
        frame_max,                      //  Negotiated maximum frame size
        heartbeat;                      //  Connection heartbeat
    int
        liveness,                       //  If this reaches zero, peer is dead
        trace;                          //  Trace level

    //  Information used for client connection
    icl_shortstr_t
        host;                           //  Server host:port to connect to
    icl_shortstr_t
        virtual_host;                   //  Virtual host to work with
    icl_longstr_t
        *auth_data;                     //  Authentication data
    icl_shortstr_t
        instance;                       //  Name of client instance
    int
        timeout;                        //  Connection setup/close timeout
    smt_timer_request_t
        *setup_timer;                   //  Connection setup timer
    Bool
        verbose,                        //  Verbose error reporting?
        fakeslow;                       //  Simulate a slow network?
    zyre_backend_t
        *caller;                        //  Caller object
</context>

<!---------------------------------------------------------------------------->
<!--  Connection thread                                                     -->

<thread
    name = "connection"
    schedule = "poll"
    context = "connection"
    >

    <handler name = "thread new">
        <argument name = "caller"       type = "zyre_backend_t *">Caller object</argument>
        <argument name = "host"         type = "char *">Server to connect to</argument>
        <argument name = "virtual host" type = "char *">Virtual host</argument>
        <argument name = "auth data"    type = "icl_longstr_t *">Authentication data</argument>
        <argument name = "instance"     type = "char *">Client instance name</argument>
        <argument name = "trace"        type = "int">Trace level, 0 - 3</argument>
        <argument name = "timeout"      type = "int">Connection setup/close timeout, msecs</argument>
        <argument name = "verbose"      type = "Bool">Verbose error reporting?</argument>
        tcb->caller  = zyre_backend_link (caller);
        tcb->verbose = verbose;
        icl_shortstr_cpy (tcb->host, host);
        icl_shortstr_cpy (tcb->virtual_host, virtual_host);
        tcb->auth_data  = icl_longstr_dup (auth_data);
        icl_shortstr_cpy (tcb->instance, instance);
        tcb->trace = trace;
        //  SMT timeouts are in usecs, WireAPI uses msecs
        tcb->timeout = timeout * 1000;

        smt_thread_wake (thread);
    </handler>

    <handler name = "thread init">
        tcb->connection_thread = thread;
        tcb->input_thread      = NULL;
        tcb->heartbeat_thread  = NULL;
        tcb->frame_max         = ASL_FRAME_MIN_SIZE;
        tcb->liveness          = FULL_LIVENESS;

        if (tcb->trace)
            tcb->verbose = TRUE;
        if (tcb->trace >= ASL_TRACE_HIGH)
            smt_socket_request_trace (TRUE);

        thread->animate = (tcb->trace >= ASL_TRACE_MED);
        smt_thread_set_next_event (thread, connect_event);
    </handler>

    <handler name = "thread destroy">
        tcb->connection_thread = NULL;

        //  Free resources
        zyre_peer_method_unlink (&tcb->method_in);
        zyre_peer_method_unlink (&tcb->method_out);
        ipr_bucket_unlink       (&tcb->bucket_in);
        icl_longstr_destroy     (&tcb->auth_data);
        smt_socket_destroy      (&tcb->socket);
        zyre_backend_unlink (&tcb->caller);
    </handler>

    <!--  Initialise Connection                                             -->

    <state name = "initialise connection">
        <event name = "connect" nextstate = "negotiate connection">
            <action name = "set no connection error" />
            <action name = "start setup timer" />
            <action name = "connect to server" />
        </event>
        <!--  Handled here so that the error makes more sense -->
        <event name = "socket error" nextstate = "">
            <action name = "report connect error" />
        </event>
        <event name = "socket timeout" nextstate = "">
            <action name = "report connect timeout" />
        </event>
        <event name = "setup timeout" nextstate = "">
            <action name = "report connect timeout" />
        </event>
    </state>

    <state name = "negotiate connection">
        <event name = "ok">
            <action name = "send protocol header" />

            <action name = "read frame header" />
            <!--  See comments below -->
            <action name = "check protocol header" />
            <action name = "read frame payload" />
            <action name = "check frame format" />
            <action name = "decode method" />
            <action name = "execute connection start" />
            <action name = "start input thread" />
            <action name = "send connection start ok" />
        </event>
        <method name = "connection tune">
            <action name = "send connection tune ok" />
            <action name = "start heartbeat thread" />
            <action name = "start heartbeat timer" />
            <action name = "send connection open" />
        </method>
        <method name = "connection open ok" nextstate = "connection active">
            <action name = "cancel setup timer" />
        </method>
        <event name = "version mismatch" nextstate = "">
            <action name = "read protocol version" />
            <action name = "report version mismatch" />
        </event>
        <event name = "bad protocol" nextstate = "">
            <action name = "report bad protocol" />
        </event>
        <method name = "connection close" nextstate = "">
            <call state = "close the connection" event = "active close" />
        </method>
        <event name = "setup timeout" nextstate = "">
            <action name = "shut down slave threads" />
            <action name = "report connect timeout" />
        </event>
    </state>

    <action name = "set no connection error">
        tcb->reply_code = 100;          //  No error
        icl_shortstr_cpy (tcb->reply_text, "No error");
    </action>

    <action name = "start setup timer">
        ;
    </action>

    <action name = "connect to server">
        icl_shortstr_t
            host;                       //  Copy of server address
        char
            *port;                      //  Port to connect to
        int
            rc = SMT_OK,
            new_size;                   //  New buffer size

        //  We extract the port number from the host name if specified
        icl_shortstr_cpy (host, tcb->host);
        port = strchr (host, ':');
        if (port)
            *port++ = 0;                //  Split the string
        else {
            port = "5672";
            //  Save port in tcb->host for reporting
            icl_shortstr_cat (tcb->host, ":");
            icl_shortstr_cat (tcb->host, port);
        }
        tcb->socket = smt_socket_new ();
        if (tcb->socket) {
            //  Set Nagle's algorithm on or off
            rc = smt_socket_set_nodelay (tcb->socket,
                zyre_peer_config_tcp_nodelay (zyre_peer_config));
            if (rc && tcb->verbose)
                smt_log_print (http_server->alert_log,
                    "W: could not set TCP_NODELAY on socket");

            //  Set socket buffers if wanted
            new_size = zyre_peer_config_tcp_rcvbuf (zyre_peer_config);
            if (new_size)
                rc = smt_socket_set_rcvbuf (tcb->socket, new_size, NULL);
            if (rc && tcb->verbose)
                smt_log_print (http_server->alert_log,
                    "W: could not set TCB_RCVBUF on socket");

            new_size = zyre_peer_config_tcp_sndbuf (zyre_peer_config);
            if (new_size)
                rc = smt_socket_set_sndbuf (tcb->socket, new_size, NULL);
            if (rc && tcb->verbose)
                smt_log_print (http_server->alert_log,
                    "W: could not set TCP_SNDBUF on socket");

            //  Connect to server
            //  Error return will be caught as an exception event
            rc = smt_socket_connect (tcb->socket, thread, 0, host, port,
                ok_event);
        }
    </action>

    <action name = "send protocol header">
        memcpy (tcb->protocol_header, "AMQP\x00\x00\x09\x01", 8);
        smt_socket_request_write (
            thread, tcb->socket, 0, 8, tcb->protocol_header, SMT_NULL_EVENT);
    </action>

    <action name = "read frame header">
        ipr_bucket_unlink (&tcb->bucket_in);
        s_socket_read_bucket (thread, &tcb->bucket_in, ASL_HEADER_SIZE);
        //  If needed, fake a slow network by pausing whole thread for 1msec
        if (tcb->fakeslow)
            apr_sleep (1000);
    </action>

    <!--  The intent of this code is to produce a user friendly error if the
          server we are connecting to supports our protocol, but the server's
          protocol version does not match ours.  Due to the way the intial
          protocol negotiation is designed, we have to use some heuristics to
          make this work.                                                   -->

    <action name = "check protocol header">
        //  The "read frame header" action will have read the 7 byte frame
        //  header.  Inspect this to see if it looks like a valid frame header
        if (memcmp (tcb->bucket_in->data, "\001\000\000\000", 4) != 0) {
            //  If not, look at the first four bytes and see if they match
            //  our protocol
            memcpy (tcb->protocol_header, tcb->bucket_in->data, 7);
            if (memcmp (tcb->protocol_header, "AMQP", 4) == 0)
                //  Protocol does match, server rejected our version
                smt_thread_raise_exception (thread, version_mismatch_event);
            else
                //  Protocol does not match
                smt_thread_raise_exception (thread, bad_protocol_event);
        }
        //  If we get here, then we have what should be a valid frame header,
        //  so we can proceed with decoding it as normal
    </action>

    <action name = "read protocol version">
        //  We need to read the extra byte that the server has sent, since
        //  "read frame header" did not read it for us
        smt_socket_request_read (thread, tcb->socket, 0, 1, 1,
            &tcb->protocol_header[7], SMT_NULL_EVENT);
    </action>

    <action name = "report version mismatch">
        if (tcb->verbose)
            smt_log_print (http_server->alert_log,
                "E: version mismatch: peer at '%s' sent (%u, %u, %u, %u)",
                tcb->host,
                tcb->protocol_header [4],
                tcb->protocol_header [5],
                tcb->protocol_header [6],
                tcb->protocol_header [7]);
    </action>

    <action name = "report bad protocol">
        if (tcb->verbose)
            smt_log_print (http_server->alert_log,
                "E: peer at '%s' sent invalid protocol header", tcb->host);
    </action>

    <action name = "execute connection start">
        s_execute_method (thread, FALSE,
            ZYRE_PEER_CONNECTION, ZYRE_PEER_CONNECTION_START);
    </action>

    <action name = "start input thread">
        smt_thread_t
            *input_thread;

        //  Start input thread
        input_thread = zyre_peer_agent_input_thread_new (thread);

        tcb->input_thread = input_thread;

        //  This thread needs to watch the input thread so that it
        //  doesn't get swamped by incoming methods between socket polls.
        smt_thread_watch (thread, input_thread);

        smt_thread_wake   ( input_thread);
        smt_thread_unlink (&input_thread);
    </action>

    <action name = "send connection start ok">
        icl_longstr_t
            *properties;                //  Connection properties
        asl_field_list_t
            *field_list;                //  List for connection properties
        icl_shortstr_t
            system;                     //  System (platform) name

        field_list = asl_field_list_new (NULL);
        asl_field_new_string (field_list, "product", "Zyre peering client");
        asl_field_new_string (field_list, "version", VERSION);
        asl_field_new_string (field_list, "copyright", COPYRIGHT);
        asl_field_new_string (field_list, "platform", icl_system_name (system));
        asl_field_new_string (field_list, "information", BUILDMODEL);
        asl_field_new_string (field_list, "instance", tcb->instance);
        properties = asl_field_list_flatten (field_list);
        asl_field_list_destroy (&field_list);

        zyre_peer_method_unlink (&tcb->method_out);
        tcb->method_out = zyre_peer_method_new_connection_start_ok (
            properties, "PLAIN", tcb->auth_data, "en_US");
        s_send_method_out (thread, 0, NULL);

        icl_longstr_destroy (&properties);
    </action>

    <action name = "send connection tune ok">
        zyre_peer_method_unlink (&tcb->method_out);
        tcb->method_out = zyre_peer_method_new_connection_tune_ok (
            1,                          //  We only support a single channel
            tcb->frame_max,
            tcb->heartbeat);
        s_send_method_out (thread, 0, NULL);
    </action>

    <action name = "start heartbeat thread">
        smt_thread_t
            *heartbeat_thread;

        //  If client is heartbeat enabled, start heartbeat thread
        if (tcb->heartbeat) {
            heartbeat_thread = zyre_peer_agent_heartbeat_thread_new (thread);

            tcb->heartbeat_thread = heartbeat_thread;

            smt_thread_wake   ( heartbeat_thread);
            smt_thread_unlink (&heartbeat_thread);
        }
    </action>

    <action name = "start heartbeat timer">
        //  If client is heartbeat enabled, (re)start outgoing heartbeat timer
        if (tcb->heartbeat)
            smt_timer_request_delay (thread, tcb->heartbeat * 1000 * 1000,
                heartbeat_event);
    </action>

    <action name = "cancel setup timer">
        smt_timer_request_destroy (&tcb->setup_timer);
    </action>

    <action name = "send connection open">
        zyre_peer_method_unlink (&tcb->method_out);
        tcb->method_out = zyre_peer_method_new_connection_open (
            tcb->virtual_host, NULL, FALSE);
        s_send_method_out (thread, 0, NULL);
    </action>

    <!--  Connection Active                                                 -->
    <!--  Process any outgoing protocol methods.                            -->

    <state name = "connection active">
        <method name = "channel flow">
            <action name = "send channel flow" />
        </method>
        <method name = "channel flow-ok">
            <action name = "send channel flow-ok" />
        </method>
        <method name = "exchange declare">
            <action name = "send exchange declare" />
        </method>
        <method name = "exchange delete">
            <action name = "send exchange delete" />
        </method>
        <method name = "queue declare">
            <action name = "send queue declare" />
        </method>
        <method name = "queue bind">
            <action name = "send queue bind" />
        </method>
        <method name = "queue purge">
            <action name = "send queue purge" />
        </method>
        <method name = "queue delete">
            <action name = "send queue delete" />
        </method>
        <method name = "queue unbind">
            <action name = "send queue unbind" />
        </method>
        <method name = "basic qos">
            <action name = "send basic qos" />
        </method>
        <method name = "basic consume">
            <action name = "send basic consume" />
        </method>
        <method name = "basic cancel">
            <action name = "send basic cancel" />
        </method>
        <method name = "basic publish">
            <action name = "send basic publish" />
            <call state = "send content body if any" event = "start" />
        </method>
        <method name = "basic get">
            <action name = "send basic get" />
        </method>
        <method name = "basic ack">
            <action name = "send basic ack" />
        </method>
        <method name = "basic reject">
            <action name = "send basic reject" />
        </method>
        <method name = "direct put">
            <action name = "send direct put" />
        </method>
        <method name = "direct get">
            <action name = "send direct get" />
        </method>
        <method name = "restms pipe-create">
            <action name = "send restms pipe-create" />
        </method>
        <method name = "restms pipe-delete">
            <action name = "send restms pipe-delete" />
        </method>
        <method name = "restms feed-create">
            <action name = "send restms feed-create" />
        </method>
        <method name = "restms feed-delete">
            <action name = "send restms feed-delete" />
        </method>
        <method name = "restms join-create">
            <action name = "send restms join-create" />
        </method>
        <method name = "restms join-delete">
            <action name = "send restms join-delete" />
        </method>
        <!--  Connection close initiated by us -->
        <method name = "connection close" nextstate = "">
            <action name = "set no connection error" />
            <call state = "close the connection" event = "active close" />
        </method>
        <!--  Channel open initiated by us -->
        <method name = "channel open">
            <action name = "send channel open" />
        </method>
        <!--  Channel close initiated by us -->
        <method name = "channel close">
            <action name = "set no connection error" />
            <action name = "send channel close" />
        </method>
        <!--  Peer initiated channel close -->
        <method name = "send channel close ok">
            <action name = "send channel close ok" />
        </method>

        <!--  Send preformatted method -->
        <method name = "push">
            <action name = "push method to server" />
            <call state = "send content body if any" event = "start" />
        </method>
        <!--  Triggered when an attempt to send a method
              on a OPENING/CLOSED/CLOSING channel is made. -->
        <event name = "discard method" nextstate = "connection active">
        </event>
    </state>

    <action name = "send channel flow">
        //  Check channel is OPEN
        assert (channel_flow_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_channel_flow (
                    channel_flow_m->active);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send channel flow-ok">
        //  Check channel is OPEN
        assert (channel_flow_ok_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_channel_flow_ok (
                    channel_flow_ok_m->active);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send exchange declare">
        //  Check channel is OPEN
        assert (exchange_declare_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_exchange_declare (
                    exchange_declare_m->ticket,
                    exchange_declare_m->exchange,
                    exchange_declare_m->type,
                    exchange_declare_m->passive,
                    exchange_declare_m->durable,
                    exchange_declare_m->auto_delete,
                    exchange_declare_m->internal,
                    exchange_declare_m->nowait,
                    exchange_declare_m->arguments);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send exchange delete">
        //  Check channel is OPEN
        assert (exchange_delete_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_exchange_delete (
                    exchange_delete_m->ticket,
                    exchange_delete_m->exchange,
                    exchange_delete_m->if_unused,
                    exchange_delete_m->nowait);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send queue declare">
        //  Check channel is OPEN
        assert (queue_declare_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_queue_declare (
                    queue_declare_m->ticket,
                    queue_declare_m->queue,
                    queue_declare_m->passive,
                    queue_declare_m->durable,
                    queue_declare_m->exclusive,
                    queue_declare_m->auto_delete,
                    queue_declare_m->nowait,
                    queue_declare_m->arguments);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send queue bind">
        //  Check channel is OPEN
        assert (queue_bind_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_queue_bind (
                    queue_bind_m->ticket,
                    queue_bind_m->queue,
                    queue_bind_m->exchange,
                    queue_bind_m->routing_key,
                    queue_bind_m->nowait,
                    queue_bind_m->arguments);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send queue purge">
        //  Check channel is OPEN
        assert (queue_purge_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_queue_purge (
                    queue_purge_m->ticket,
                    queue_purge_m->queue,
                    queue_purge_m->nowait);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send queue delete">
        //  Check channel is OPEN
        assert (queue_delete_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_queue_delete (
                    queue_delete_m->ticket,
                    queue_delete_m->queue,
                    queue_delete_m->if_unused,
                    queue_delete_m->if_empty,
                    queue_delete_m->nowait);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send queue unbind">
        //  Check channel is OPEN
        assert (queue_unbind_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_queue_unbind (
                    queue_unbind_m->ticket,
                    queue_unbind_m->queue,
                    queue_unbind_m->exchange,
                    queue_unbind_m->routing_key,
                    queue_unbind_m->nowait,
                    queue_unbind_m->arguments);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send basic qos">
        //  Check channel is OPEN
        assert (basic_qos_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_basic_qos (
                    basic_qos_m->prefetch_size,
                    basic_qos_m->prefetch_count,
                    basic_qos_m->global);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send basic consume">
        //  Check channel is OPEN
        assert (basic_consume_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_basic_consume (
                    basic_consume_m->ticket,
                    basic_consume_m->queue,
                    basic_consume_m->consumer_tag,
                    basic_consume_m->no_local,
                    basic_consume_m->no_ack,
                    basic_consume_m->exclusive,
                    basic_consume_m->nowait,
                    basic_consume_m->arguments);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send basic cancel">
        //  Check channel is OPEN
        assert (basic_cancel_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_basic_cancel (
                    basic_cancel_m->consumer_tag,
                    basic_cancel_m->nowait);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send basic publish">
        //  Check channel is OPEN
        assert (basic_publish_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_basic_publish (
                    basic_publish_m->ticket,
                    basic_publish_m->exchange,
                    basic_publish_m->routing_key,
                    basic_publish_m->mandatory,
                    basic_publish_m->immediate);
            tcb->method_out->content =
                amq_content_basic_link (
                    basic_publish_m->content
                );
            assert (tcb->method_out->content);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send basic get">
        //  Check channel is OPEN
        assert (basic_get_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_basic_get (
                    basic_get_m->ticket,
                    basic_get_m->queue,
                    basic_get_m->no_ack);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send basic ack">
        //  Check channel is OPEN
        assert (basic_ack_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_basic_ack (
                    basic_ack_m->delivery_tag,
                    basic_ack_m->multiple);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send basic reject">
        //  Check channel is OPEN
        assert (basic_reject_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_basic_reject (
                    basic_reject_m->delivery_tag,
                    basic_reject_m->requeue);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send direct put">
        //  Check channel is OPEN
        assert (direct_put_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_direct_put (
                    direct_put_m->sink);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send direct get">
        //  Check channel is OPEN
        assert (direct_get_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_direct_get (
                    direct_get_m->feed);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send restms pipe-create">
        //  Check channel is OPEN
        assert (restms_pipe_create_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_restms_pipe_create (
                    restms_pipe_create_m->pipe_type,
                    restms_pipe_create_m->pipe_name);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send restms pipe-delete">
        //  Check channel is OPEN
        assert (restms_pipe_delete_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_restms_pipe_delete (
                    restms_pipe_delete_m->pipe_name);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send restms feed-create">
        //  Check channel is OPEN
        assert (restms_feed_create_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_restms_feed_create (
                    restms_feed_create_m->feed_type,
                    restms_feed_create_m->feed_name);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send restms feed-delete">
        //  Check channel is OPEN
        assert (restms_feed_delete_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_restms_feed_delete (
                    restms_feed_delete_m->feed_name);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send restms join-create">
        //  Check channel is OPEN
        assert (restms_join_create_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_restms_join_create (
                    restms_join_create_m->pipe_name,
                    restms_join_create_m->feed_name,
                    restms_join_create_m->address);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send restms join-delete">
        //  Check channel is OPEN
        assert (restms_join_delete_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out =
                zyre_peer_method_new_restms_join_delete (
                    restms_join_delete_m->pipe_name,
                    restms_join_delete_m->feed_name,
                    restms_join_delete_m->address);
            s_send_method_out (thread, 1, NULL);

        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <action name = "send channel open">
        //  Check channel is CLOSED
        assert (channel_open_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_CLOSED) {
            //  Create the channel
            //  Channel is now OPENING
            tcb->channel_state = ASL_CHANNEL_OPENING;
            //  Send the channel open
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out = zyre_peer_method_new_channel_open (NULL);
            s_send_method_out (thread, 1, NULL);
        }
        else
            //  Channel is not CLOSED
            s_connection_exception (thread,
                ASL_CHANNEL_ERROR, "Channel is already open",
                ZYRE_PEER_CHANNEL, ZYRE_PEER_CHANNEL_OPEN);
    </action>

    <action name = "send channel close">
        //  Assert channel is OPEN
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            //  Send the method
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out = zyre_peer_method_new_channel_close (
                tcb->reply_code, tcb->reply_text, 0, 0);
            s_send_method_out (thread, 1, NULL);
            //  Channel is now CLOSING
            tcb->channel_state = ASL_CHANNEL_CLOSING;
        }
        else
            //  Channel is not OPEN
            s_connection_exception (thread,
                ASL_CHANNEL_ERROR, "Channel is not open",
                ZYRE_PEER_CHANNEL, ZYRE_PEER_CHANNEL_CLOSE);
    </action>

    <!--  Response to peer initiated channel close -->

    <action name = "send channel close ok">
        //  Assert channel is CLOSING
        assert (tcb->channel_state == ASL_CHANNEL_CLOSING);
        //  Send the channel close ok
        zyre_peer_method_unlink (&tcb->method_out);
        tcb->method_out = zyre_peer_method_new_channel_close_ok ();
        s_send_method_out (thread, 1, NULL);
        //  Channel is now CLOSED
        tcb->channel_state = ASL_CHANNEL_CLOSED;
    </action>

    <action name = "push method to server">
        //  Check channel is OPEN
        assert (push_m->channel_nbr == 1);
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            //  Send method as-is, with no reconstruction
            zyre_peer_method_unlink (&tcb->method_out);
            tcb->method_out = zyre_peer_method_link (push_m->method);
            s_send_method_out (thread, 1, NULL);
        }
        else
            //  Channel is not OPEN, discard method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <!--  Send Content Body If Any                                          -->
    <!--  Sends a content header, followed by a number of body frames       -->

    <state name = "send content body if any">
        <event name = "start">
            <action name = "send content header" />
            <action name = "send content body frame" />
        </event>
        <event name = "continue">
            <action name = "send content body frame" />
        </event>
        <event name = "finished">
            <return />
        </event>
    </state>

    <action name = "send content header">
        ipr_bucket_t
            *payload = NULL;            //  Bucket ready to send

        if (tcb->method_out->content) {
            //  Chronometer on content sent to wire
            amq_content_basic_chrono_add (tcb->method_out->content);
            if (tcb->method_out->class_id == ZYRE_PEER_BASIC) {
                payload = amq_content_basic_replay_header (
                    tcb->method_out->content);
                s_write_payload (thread, 1, ASL_FRAME_HEADER, &payload);
                amq_content_basic_set_reader (
                    tcb->method_out->content, &tcb->reader, tcb->frame_max);
            }
        }
        else
            smt_thread_raise_exception (thread, finished_event);
    </action>

    <action name = "send content body frame">
        ipr_bucket_t
            *payload = NULL;            //  Bucket ready to send

        if (tcb->method_out->class_id == ZYRE_PEER_BASIC)
            payload = amq_content_basic_replay_body (
                tcb->method_out->content, &tcb->reader);
        if (payload) {
            s_write_payload (thread, 1, ASL_FRAME_BODY, &payload);
            smt_thread_set_next_event (thread, continue_event);
        }
        else
            smt_thread_set_next_event (thread, finished_event);
    </action>

    <!--  Defaults for connection thread                                    -->

    <state name = "defaults">
        <!-- Exception events -->
        <event name = "socket error" nextstate = "">
            <action name = "shut down slave threads" />
            <action name = "report socket error" />
        </event>
        <event name = "socket timeout" nextstate = "">
            <action name = "shut down slave threads" />
            <action name = "report socket timeout" />
        </event>
        <event name = "socket closing" nextstate = "">
            <action name = "shut down slave threads" />
            <action name = "report socket error" />
        </event>
        <event name = "smt error" nextstate = "">
            <action name = "shut down slave threads" />
            <action name = "report smt error" />
        </event>
        <!--  Passive close on input -->
        <event name = "connection close" nextstate = "">
            <call state = "close the connection" event = "passive close" />
        </event>
        <!--  Recoverable protocol/internal error on the connection -->
        <event name = "connection error" nextstate = "">
            <call state = "close the connection" event = "active close" />
        </event>
        <!--  Unrecoverable error on the connection -->
        <event name = "connection abort" nextstate = "">
            <action name = "shut down slave threads" />
        </event>
        <!--  Notification of exception from input or heartbeat thread -->
        <event name = "external exception" nextstate = "">
            <action name = "shut down slave threads" />
        </event>
        <!--  Event from heartbeat timer -->
        <event name = "heartbeat">
            <action name = "send heartbeat frame" />
            <action name = "start heartbeat timer" />
        </event>
    </state>

    <action name = "shut down slave threads">
        //  Shut down other two threads if they are still active.
        if (tcb->input_thread)
            smt_thread_shut_down (tcb->input_thread);
        if (tcb->heartbeat_thread)
            smt_thread_shut_down (tcb->heartbeat_thread);
    </action>

    <action name = "report smt error">
        if (tcb->verbose)
            smt_log_print (http_server->alert_log,
                "E: SMT error: %s", smt_thread_error (thread));
    </action>

    <!--  Close The Connection                                              -->
    <!--  Called when closing the connection.
          For an active close we send a connection close and then discard
          anything until we get a corresponding connection close.ok.  For a
          passive close (initated by peer), we process the close, send a
          connection close.ok and shut down.                                -->

    <state name = "close the connection">
        <event name = "active close">
            <action name = "send connection close" />
        </event>
        <method name = "connection close ok">
            <action name = "shut down slave threads" />
            <action name = "flush the connection" />
            <return />
        </method>
        <event name = "passive close">
            <action name = "shut down slave threads" />
            <action name = "execute connection close" />
            <action name = "send connection close ok" />
            <action name = "flush the connection" />
            <return />
        </event>
        <event name = "close timeout">
            <action name = "shut down slave threads" />
            if (tcb->verbose)
                smt_log_print (http_server->alert_log,
                    "E: timed out waiting for connection.close-ok from peer"   " (%s)",
                    tcb->host);
            <return />
        </event>
        <!--  Neither of the following two exceptions should occur under normal
              conditions in this state, but if we do get them then report
              and shut down immediately.                                    -->
        <event name = "connection error">
            <action name = "shut down slave threads" />
            if (tcb->verbose)
                smt_log_print (http_server->alert_log,
                    "E: connection error while "   "waiting for connection.close-ok from peer (%s)",
                    tcb->host);
            <return />
        </event>
        <event name = "connection close">
            <action name = "shut down slave threads" />
            if (tcb->verbose)
                smt_log_print (http_server->alert_log,
                    "E: received connection close while "   "waiting for connection.close-ok from peer (%s)",
                    tcb->host);
            <return />
        </event>
        <!--  Ignore any unhandled methods or events -->
        <default>
        </default>
    </state>

    <action name = "send connection close">
        //  Schedule a timeout to protect against misbehaving servers
        smt_timer_request_delay (thread, tcb->timeout, close_timeout_event);
        //  Send connection close
        zyre_peer_method_unlink (&tcb->method_out);
        tcb->method_out = zyre_peer_method_new_connection_close (
            tcb->reply_code, tcb->reply_text, 0, 0);
        s_send_method_out (thread, 0, NULL);
    </action>

    <!--  Don't use s_execute_method here, since we already know it's a
          connection close -->
    <action name = "execute connection close">
        zyre_peer_method_execute (tcb->method_in, tcb->caller, thread);
    </action>

    <action name = "send connection close ok">
        zyre_peer_method_unlink (&tcb->method_out);
        tcb->method_out = zyre_peer_method_new_connection_close_ok ();
        s_send_method_out (thread, 0, NULL);
    </action>

    <action name = "flush the connection">
        if (tcb->socket)
            smt_socket_request_close (thread, &tcb->socket, 0, SMT_NULL_EVENT);
    </action>

    <action name = "report socket error">
        if (tcb->verbose)
            smt_log_print (http_server->alert_log,
                "E: %s, connection to peer lost (%s)",
                smt_thread_error (thread), tcb->host);
    </action>

    <action name = "report connect error">
        if (tcb->verbose)
            smt_log_print (http_server->alert_log,
                "E: connection to peer failed: %s (%s)",
                smt_thread_error (thread), tcb->host);
    </action>

    <action name = "report socket timeout">
        if (tcb->verbose)
            smt_log_print (http_server->alert_log,
                "E: socket timeout, connection to peer lost (%s)",
                tcb->host);
    </action>

    <action name = "report connect timeout">
        if (tcb->verbose)
            smt_log_print (http_server->alert_log,
                "E: connection to peer timed out (%s)", tcb->host);
    </action>

    <action name = "send heartbeat frame">
        ipr_bucket_t
           *bucket;                     //  Header bucket
        byte
            *bucket_ptr;

        bucket = ipr_bucket_new (ASL_HEADER_SIZE + 1);
        bucket_ptr = bucket->data;
        PUT_OCTET (bucket_ptr, ASL_FRAME_HEARTBEAT);
        PUT_SHORT (bucket_ptr, 0);
        PUT_LONG  (bucket_ptr, 0);
        PUT_OCTET (bucket_ptr, ASL_FRAME_END);
        bucket->cur_size = bucket_ptr - bucket->data;
        s_socket_write_bucket (thread, bucket);
        ipr_bucket_unlink (&bucket);
    </action>

</thread>

<!---------------------------------------------------------------------------->
<!--  Input thread                                                          -->

<thread name = "input"
    schedule = "poll"
    context = "connection"
    share = "1"
    >

    <handler name = "thread init">
        thread->animate = (tcb->trace >= ASL_TRACE_MED);
        smt_thread_set_next_event (thread, ok_event);
    </handler>

    <handler name = "thread destroy">
        tcb->input_thread = NULL;
    </handler>

    <state name = "start">
        <event name = "ok" nextstate = "have incoming method">
            <call state = "read method" event = "read method" />
            <action name = "check method class" />
        </event>
    </state>

    <!--  Read Method                                                       -->
    <!--  Reads a single method frame from the socket, looping on heartbeat
          frames.  Raises an exception for any other frames.                -->

    <state name = "read method">
        <event name = "read method">
            <action name = "read frame header" />
            <action name = "read frame payload" />
            <action name = "check frame format" />
            <action name = "decode method" />
            <return />
        </event>
    </state>

    <action name = "read frame payload">
        byte
            *bucket_ptr;
        icl_shortstr_t
            reply_text;

        bucket_ptr = tcb->bucket_in->data;
        tcb->frame_header.type    =  bucket_ptr [0];
        tcb->frame_header.channel = (bucket_ptr [1] << 8)  +  bucket_ptr [2];
        tcb->frame_header.size    = (bucket_ptr [3] << 24) + (bucket_ptr [4] << 16)
                                  + (bucket_ptr [5] << 8)  +  bucket_ptr [6];

        if (tcb->frame_header.size > tcb->frame_max) {
            icl_shortstr_fmt (reply_text, "Peer sent oversized frame (%d > %d)",
                tcb->frame_header.size, tcb->frame_max);
            s_connection_abort (thread, ASL_FRAME_ERROR, reply_text, 0, 0);
        }
        else {
            //  Read method payload plus frame-end
            ipr_bucket_unlink (&tcb->bucket_in);
            s_socket_read_bucket (thread, &tcb->bucket_in,
                tcb->frame_header.size + 1);
        }
        //  We have successfully read a frame header, reset peer liveness
        tcb->liveness = FULL_LIVENESS;
    </action>

    <action name = "check frame format">
        //  The bucket must be at least 1 octet long, and end with a frame-end
        tcb->bucket_in->cur_size = tcb->socket->io_size;
        if (tcb->bucket_in->cur_size > 0
        &&  tcb->bucket_in->data [tcb->bucket_in->cur_size - 1] == ASL_FRAME_END) {
            //  Strip off frame-end octet
            tcb->bucket_in->cur_size--;
        }
        else
            s_connection_abort (thread, ASL_SYNTAX_ERROR,
                tcb->bucket_in->cur_size?
                "Badly-formatted method frame - missing frame-end octet":
                "Badly-formatted method frame - zero-sized frame",
                0, 0);
    </action>

    <action name = "decode method">
        //  Loop if we received a heartbeat frame
        if (tcb->frame_header.type == ASL_FRAME_HEARTBEAT)
            smt_thread_raise_exception (thread, read_method_event);
        else
        //  Decode method
        if (tcb->frame_header.type == ASL_FRAME_METHOD) {
            zyre_peer_method_unlink (&tcb->method_in);
            tcb->method_in = zyre_peer_method_decode (tcb->bucket_in,
                tcb->strerror);
            if (tcb->method_in) {
                if (tcb->trace >= ASL_TRACE_LOW)
                    zyre_peer_method_dump (tcb->method_in, NULL, "I: recv ");
            }
            else
                s_connection_abort (thread,
                    ASL_SYNTAX_ERROR, tcb->strerror, 0, 0);
        }
        else
            s_connection_exception (thread,
                ASL_SYNTAX_ERROR, "Expected a method frame", 0, 0);
    </action>

    <!--  Have Incoming Method                                              -->
    <!--  Process an incoming method or content.                            -->

    <state name = "have incoming method">
        <event name = "connection class" nextstate = "have connection method">
            <action name = "check connection method" />
        </event>
        <event name = "channel class" nextstate = "have channel method">
            <action name = "check channel method" />
        </event>
        <event name = "basic content" nextstate = "have incoming method">
            <call state = "read basic content" event = "header" />
            <action name = "execute functional method" />
            <call state = "read method" event = "read method" />
            <action name = "check method class" />
        </event>
        <event name = "other method" nextstate = "have incoming method">
            <action name = "execute functional method" />
            <call state = "read method" event = "read method" />
            <action name = "check method class" />
        </event>
        <!--  Triggered if we receive a method on
              a channel which is not OPEN. -->
        <event name = "discard method" nextstate = "have incoming method">
            <call state = "read method" event = "read method" />
            <action name = "check method class" />
        </event>
    </state>

    <action name = "check method class">
        if (tcb->method_in->class_id == ZYRE_PEER_CONNECTION)
            smt_thread_set_next_event (thread, connection_class_event);
        else
        if (tcb->method_in->class_id == ZYRE_PEER_CHANNEL)
            smt_thread_set_next_event (thread, channel_class_event);
        else
        if (tcb->method_in->class_id  == ZYRE_PEER_BASIC
        &&  tcb->method_in->method_id == ZYRE_PEER_BASIC_RETURN)
            smt_thread_set_next_event (thread, basic_content_event);
        else
        if (tcb->method_in->class_id  == ZYRE_PEER_BASIC
        &&  tcb->method_in->method_id == ZYRE_PEER_BASIC_DELIVER)
            smt_thread_set_next_event (thread, basic_content_event);
        else
        if (tcb->method_in->class_id  == ZYRE_PEER_BASIC
        &&  tcb->method_in->method_id == ZYRE_PEER_BASIC_GET_OK)
            smt_thread_set_next_event (thread, basic_content_event);
        else
            smt_thread_set_next_event (thread, other_method_event);
    </action>

    <action name = "check connection method">
        //  Check channel is valid
        if (tcb->frame_header.channel != 0)
            s_connection_exception (thread, ASL_CHANNEL_ERROR,
            "Invalid channel",
            tcb->method_in->class_id,
            tcb->method_in->method_id);
        else
        if (tcb->method_in->method_id == ZYRE_PEER_CONNECTION_TUNE)
            smt_thread_set_next_event (thread, connection_tune_event);
        else
        if (tcb->method_in->method_id == ZYRE_PEER_CONNECTION_OPEN_OK)
            smt_thread_set_next_event (thread, connection_open_ok_event);
        else
        if (tcb->method_in->method_id == ZYRE_PEER_CONNECTION_CLOSE)
            smt_thread_set_next_event (thread, connection_close_event);
        else
        if (tcb->method_in->method_id == ZYRE_PEER_CONNECTION_CLOSE_OK)
            smt_thread_set_next_event (thread, connection_close_ok_event);
        else
            s_connection_exception (thread, ASL_SYNTAX_ERROR,
                "Method not allowed",
                tcb->method_in->class_id,
                tcb->method_in->method_id);
    </action>

    <action name = "check channel method">
        //  Check channel is valid
        if (tcb->frame_header.channel != 1)
            s_connection_exception (thread, ASL_CHANNEL_ERROR,
            "Invalid channel",
            tcb->method_in->class_id,
            tcb->method_in->method_id);
        else
        if (tcb->method_in->method_id == ZYRE_PEER_CHANNEL_OPEN_OK)
            smt_thread_set_next_event (thread, channel_open_ok_event);
        else
        if (tcb->method_in->method_id == ZYRE_PEER_CHANNEL_CLOSE)
            smt_thread_set_next_event (thread, channel_close_event);
        else
        if (tcb->method_in->method_id == ZYRE_PEER_CHANNEL_CLOSE_OK)
            smt_thread_set_next_event (thread, channel_close_ok_event);
        else
        if (tcb->method_in->method_id == ZYRE_PEER_CHANNEL_FLOW)
            smt_thread_set_next_event (thread, channel_flow_event);
        else
        if (tcb->method_in->method_id == ZYRE_PEER_CHANNEL_FLOW_OK)
            smt_thread_set_next_event (thread, channel_flow_ok_event);
        else
            s_connection_exception (thread, ASL_SYNTAX_ERROR,
                "Method not allowed",
                tcb->method_in->class_id,
                tcb->method_in->method_id);
    </action>

    <action name = "execute functional method">
        //  Check channel is valid
        if (tcb->frame_header.channel != 1)
            s_connection_exception (thread, ASL_CHANNEL_ERROR,
            "Invalid channel",
            tcb->method_in->class_id,
            tcb->method_in->method_id);
        else
        //  Check channel is OPEN
        if (tcb->channel_state == ASL_CHANNEL_OPEN)
            s_execute_functional_method (thread,
                tcb->method_in->class_id, tcb->method_in->method_id,
                tcb->out_class_id, tcb->out_method_id);
        else
            //  Channel is not OPEN, discard the method
            smt_thread_raise_exception (thread, discard_method_event);
    </action>

    <!--  Have Connection Method                                            -->
    <!--  The only connection method we can receive on input is a connection
          close.  In this case, we notify the connection thread and let it
          deal with it.                                                     -->

    <state name = "have connection method">
        <event name = "connection tune" nextstate = "have incoming method">
            <action name = "execute connection tune" />
            <action name = "notify connection of tune" />
            <call state = "read method" event = "read method" />
            <action name = "check method class" />
        </event>
        <event name = "connection open ok" nextstate = "have incoming method">
            <action name = "execute connection open ok" />
            <action name = "notify connection of open ok" />
            <call state = "read method" event = "read method" />
            <action name = "check method class" />
        </event>
        <event name = "connection close" nextstate = "">
            <action name = "notify connection of passive close" />
        </event>
        <event name = "connection close ok" nextstate = "">
            <action name = "notify connection of close ok" />
        </event>
    </state>

    <action name = "execute connection tune">
        s_execute_method (thread, FALSE,
            ZYRE_PEER_CONNECTION, ZYRE_PEER_CONNECTION_TUNE);
        if (!smt_thread_exception_raised (thread)) {
            tcb->frame_max   =
                tcb->method_in->payload.connection_tune.frame_max;
#if defined (BASE_THREADSAFE)
            tcb->heartbeat =
                tcb->method_in->payload.connection_tune.heartbeat;
#else
            //  In single-threaded builds we disable heartbeating because
            //  the application can block, and thus kill the connection
            tcb->heartbeat = 0;
#endif
            if (tcb->frame_max < ASL_FRAME_MIN_SIZE
            &&  tcb->frame_max > 0)
                tcb->frame_max = ASL_FRAME_MIN_SIZE;
        }
    </action>

    <action name = "notify connection of tune">
        zyre_peer_agent_connection_tune (tcb->connection_thread);
    </action>

    <action name = "execute connection open ok">
        s_execute_method (thread, FALSE,
            ZYRE_PEER_CONNECTION, ZYRE_PEER_CONNECTION_OPEN_OK);
    </action>

    <action name = "notify connection of open ok">
        zyre_peer_agent_connection_open_ok (tcb->connection_thread);
    </action>

    <action name = "notify connection of passive close">
        //  Report error if any
        s_report_error (thread, "Connection", "closing connection",
            tcb->method_in->payload.connection_close.reply_code,
            tcb->method_in->payload.connection_close.reply_text,
            tcb->method_in->payload.connection_close.class_id,
            tcb->method_in->payload.connection_close.method_id);
        //  Save reply code for zyre_peer_connection
        tcb->reply_code = tcb->method_in->payload.connection_close.reply_code;
        icl_shortstr_cpy (tcb->reply_text,
            tcb->method_in->payload.connection_close.reply_text);
        //  Notify connection thread
        smt_thread_raise_exception (tcb->connection_thread,
            connection_close_event);
        smt_thread_wake (tcb->connection_thread);
    </action>

    <action name = "notify connection of close ok">
        zyre_peer_agent_connection_close_ok (tcb->connection_thread);
    </action>

    <!--  Have Channel Method                                               -->

    <state name = "have channel method">
        <!--  Response to channel open initiated by us -->
        <event name = "channel open ok" nextstate = "have incoming method">
            <action name = "execute channel open ok" />
            <call state = "read method" event = "read method" />
            <action name = "check method class" />
        </event>
        <!--  Peer initiated channel close -->
        <event name = "channel close" nextstate = "have incoming method">
            <action name = "execute channel close" />
            <call state = "read method" event = "read method" />
            <action name = "check method class" />
        </event>
        <!--  Response to channel close initiated by us -->
        <event name = "channel close ok" nextstate = "have incoming method">
            <action name = "execute channel close ok" />
            <call state = "read method" event = "read method" />
            <action name = "check method class" />
        </event>
        <!--  Peer initiated channel flow -->
        <event name = "channel flow" nextstate = "have incoming method">
            <action name = "execute channel flow" />
            <call state = "read method" event = "read method" />
            <action name = "check method class" />
        </event>
        <!--  Response to channel flow initated by us -->
        <event name = "channel flow ok" nextstate = "have incoming method">
            <action name = "execute channel flow ok" />
            <call state = "read method" event = "read method" />
            <action name = "check method class" />
        </event>
    </state>

    <!--  Response to channel open initiated by us                          -->

    <action name = "execute channel open ok">
        //  Check channel is OPENING
        if (tcb->channel_state == ASL_CHANNEL_OPENING) {
            //  Channel is now OPEN
            tcb->channel_state = ASL_CHANNEL_OPEN;
            //  Signal caller that the channel is ready for use
            zyre_peer_method_execute (tcb->method_in, tcb->caller, thread);
        }
        else
            //  Channel is not OPENING
            s_connection_exception (thread,
                ASL_CHANNEL_ERROR, "Channel is not opening",
                ZYRE_PEER_CHANNEL, ZYRE_PEER_CHANNEL_OPEN_OK);
    </action>

    <!--  Peer initated channel close                                       -->

    <action name = "execute channel close">
        //  Check channel is OPEN
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            //  Report error if any
            s_report_error (thread, "Channel", "closing channel",
                tcb->method_in->payload.channel_close.reply_code,
                tcb->method_in->payload.channel_close.reply_text,
                tcb->method_in->payload.channel_close.class_id,
                tcb->method_in->payload.channel_close.method_id);
            //  Channel is now CLOSING
            tcb->channel_state = ASL_CHANNEL_CLOSING;
            //  Save reply code for zyre_peer_session
            tcb->reply_code = tcb->method_in->payload.channel_close.reply_code;
            strcpy (tcb->reply_text, tcb->method_in->payload.channel_close.reply_text);
            //  Queue the channel close ok
            zyre_peer_agent_send_channel_close_ok (tcb->connection_thread);
        }
        else
            //  Channel is not OPEN
            s_connection_exception (thread,
                ASL_CHANNEL_ERROR, "Channel is not open",
                ZYRE_PEER_CHANNEL, ZYRE_PEER_CHANNEL_CLOSE);
    </action>

    <!--  Response to channel close initiated by us                         -->

    <action name = "execute channel close ok">
        //  Check channel is CLOSING
        if (tcb->channel_state == ASL_CHANNEL_CLOSING) {
            //  Channel is now CLOSED
            tcb->channel_state = ASL_CHANNEL_CLOSED;
        }
        else
            //  Channel is not CLOSING
            s_connection_exception (thread,
                ASL_CHANNEL_ERROR, "Channel is not closing",
                ZYRE_PEER_CHANNEL, ZYRE_PEER_CHANNEL_CLOSE_OK);
    </action>

    <action name = "execute channel flow">
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            s_execute_method (thread, TRUE,
                ZYRE_PEER_CHANNEL, ZYRE_PEER_CHANNEL_FLOW);
        }
        else
            s_connection_exception (thread,
                ASL_CHANNEL_ERROR, "Channel is not open",
                ZYRE_PEER_CHANNEL, ZYRE_PEER_CHANNEL_FLOW);
    </action>

    <action name = "execute channel flow ok">
        if (tcb->channel_state == ASL_CHANNEL_OPEN) {
            s_execute_method (thread, TRUE,
                ZYRE_PEER_CHANNEL, ZYRE_PEER_CHANNEL_FLOW_OK);
        }
        else
            s_connection_exception (thread,
                ASL_CHANNEL_ERROR, "Channel is not open",
                ZYRE_PEER_CHANNEL, ZYRE_PEER_CHANNEL_FLOW_OK);
    </action>

    <!--  Read Basic Content                                                -->
    <!--  Called when reading basic content.          Read a header frame,
          followed by multiple body frames.  Loops on heartbeat frames,
          accepts only exception methods (see comments below).              -->

    <state name = "read basic content">
        <event name = "header">
            <action name = "read frame header" />
            <action name = "read frame payload" />
            <action name = "check frame format" />
            <action name = "expect content basic header" />
            <action name = "check if basic body complete" />
            <return />
        </event>
        <event name = "expect body">
            <action name = "read frame header" />
            <action name = "read frame payload" />
            <action name = "check frame format" />
            <action name = "expect content basic body" />
            <action name = "check if basic body complete" />
            <return />
        </event>
        <!--  Exception method received -->
        <event name = "method" nextstate = "have incoming method">
            <action name = "decode method" />
            <action name = "expect exception method" />
        </event>
    </state>

    <action name = "expect content basic header">
        if (tcb->frame_header.type == ASL_FRAME_HEARTBEAT)
            smt_thread_raise_exception (thread, header_event);
        else
        if (tcb->frame_header.type == ASL_FRAME_METHOD)
            smt_thread_raise_exception (thread, method_event);
        else
        //  Check channel is valid
        if (tcb->frame_header.channel != 1)
            s_connection_exception (thread, ASL_CHANNEL_ERROR,
            "Invalid channel",
            tcb->method_in->class_id,
            tcb->method_in->method_id);
        else
        if (tcb->frame_header.type == ASL_FRAME_HEADER) {
            tcb->method_in->content =
                amq_content_basic_new ();
            if (amq_content_basic_record_header (
                (amq_content_basic_t *)
                tcb->method_in->content,
                tcb->bucket_in))
                s_connection_exception (thread, ASL_SYNTAX_ERROR,
                    "Invalid content header frame",
                    tcb->method_in->class_id,
                    tcb->method_in->method_id);
            else
            if (((amq_content_basic_t *)
                tcb->method_in->content)->class_id != ZYRE_PEER_BASIC)
                s_connection_exception (thread, ASL_SYNTAX_ERROR,
                    "Content class does not match method class",
                    tcb->method_in->class_id,
                    tcb->method_in->method_id);

            //  Chronometer on content received from wire
            amq_content_basic_chrono_add (tcb->method_in->content);
        }
        else
            s_connection_exception (thread, ASL_SYNTAX_ERROR,
                "Expected a content header frame",
                tcb->method_in->class_id,
                tcb->method_in->method_id);
    </action>

    <action name = "check if basic body complete">
        assert ((amq_content_basic_t *) tcb->method_in);
        assert ((amq_content_basic_t *) tcb->method_in->content);

        if (((amq_content_basic_t *)
            tcb->method_in->content)->body_size
        <   ((amq_content_basic_t *)
            tcb->method_in->content)->body_expect)
            smt_thread_raise_exception (thread, expect_body_event);
    </action>

    <action name = "expect content basic body">
        if (tcb->frame_header.type == ASL_FRAME_HEARTBEAT)
            smt_thread_raise_exception (thread, expect_body_event);
        else
        if (tcb->frame_header.type == ASL_FRAME_METHOD)
            smt_thread_raise_exception (thread, method_event);
        else
        //  Check channel is valid
        if (tcb->frame_header.channel != 1)
            s_connection_exception (thread, ASL_CHANNEL_ERROR,
            "Invalid channel",
            tcb->method_in->class_id,
            tcb->method_in->method_id);
        else
        if (tcb->frame_header.type == ASL_FRAME_BODY)
            amq_content_basic_record_body (
                (amq_content_basic_t *)
                tcb->method_in->content, tcb->bucket_in);
        else
            s_connection_exception (thread, ASL_SYNTAX_ERROR,
                "Expected a content body frame",
                tcb->method_in->class_id,
                tcb->method_in->method_id);
    </action>

    <!--  If we receive a method while reading content, verify that it is a
          legitimate exception and process it immediately.                  -->

    <action name = "expect exception method">
        if (tcb->method_in->class_id  == ZYRE_PEER_CONNECTION &&
            tcb->method_in->method_id == ZYRE_PEER_CONNECTION_CLOSE)
            smt_thread_set_next_event (thread, connection_class_event);
        else
        if (tcb->method_in->class_id  == ZYRE_PEER_CONNECTION &&
            tcb->method_in->method_id == ZYRE_PEER_CONNECTION_CLOSE_OK)
            smt_thread_set_next_event (thread, connection_class_event);
        else
        if (tcb->method_in->class_id  == ZYRE_PEER_CHANNEL &&
            tcb->method_in->method_id == ZYRE_PEER_CHANNEL_CLOSE)
            smt_thread_set_next_event (thread, channel_class_event);
        else
            s_connection_exception (thread, ASL_SYNTAX_ERROR,
                "Method not allowed",
                tcb->method_in->class_id,
                tcb->method_in->method_id);
    </action>

    <!--  Defaults for input thread                                         -->
    <!--  Don't handle any exceptions ourselves, just pass them on to the
          connection thread.                                                -->

    <state name = "defaults">
        <!-- Exception events -->
        <event name = "socket error" nextstate = "">
            <action name = "notify connection of exception" />
            <action name = "report socket error" />
        </event>
        <event name = "socket timeout" nextstate = "">
            <action name = "notify connection of exception" />
            <action name = "report socket timeout" />
        </event>
        <event name = "socket closing" nextstate = "">
            <action name = "notify connection of exception" />
            <action name = "report socket error" />
        </event>
        <event name = "smt error" nextstate = "">
            <action name = "notify connection of exception" />
            <action name = "report smt error" />
        </event>
        <event name = "connection abort" nextstate = "">
            <action name = "notify connection of exception" />
        </event>
        <event name = "connection error" nextstate = "">
            <action name = "notify connection of error" />
            <call state = "connection closing" event = "closing" />
        </event>
    </state>

    <action name = "notify connection of exception">
        smt_thread_raise_exception (tcb->connection_thread,
            external_exception_event);
        smt_thread_wake (tcb->connection_thread);
    </action>

    <action name = "notify connection of error">
        smt_thread_raise_exception (tcb->connection_thread,
            connection_error_event);
        smt_thread_wake (tcb->connection_thread);
    </action>

    <!--  Connection Closing                                                -->
    <!--  Called when a connection exception is raised in the input thread.
          The connection thread will initiate an active close, so we can
          discard anything else received in the mean time.                  -->

    <state name = "connection closing">
        <event name = "closing">
            <action name = "read frame header" />
            <action name = "read frame payload" />
            <action name = "check frame format" />
            <action name = "expect method frame" />
        </event>
        <event name = "method">
            <action name = "decode method" />
            <action name = "expect connection close ok" />
        </event>
        <event name = "discard frame">
            <action name = "read frame header" />
            <action name = "read frame payload" />
            <action name = "check frame format" />
            <action name = "expect method frame" />
        </event>
        <event name = "connection close ok" nextstate = "">
            <action name = "notify connection of close ok" />
        </event>
        <!--  Override to prevent looping -->
        <event name = "connection error" nextstate = "">
            <action name = "notify connection of exception" />
        </event>
    </state>

    <action name = "expect method frame">
        if (tcb->frame_header.type != ASL_FRAME_METHOD)
            smt_thread_set_next_event (thread, discard_frame_event);
        else
            smt_thread_set_next_event (thread, method_event);
    </action>

    <action name = "expect connection close ok">
        if (tcb->method_in->class_id  == ZYRE_PEER_CONNECTION &&
            tcb->method_in->method_id == ZYRE_PEER_CONNECTION_CLOSE_OK)
            smt_thread_set_next_event (thread, connection_close_ok_event);
        else
            smt_thread_set_next_event (thread, discard_frame_event);
    </action>

</thread>


<!---------------------------------------------------------------------------->
<!--  Heartbeat thread  ------------------------------------------------------>

<thread
    name = "heartbeat"
    schedule = "poll"
    context = "connection"
    share = "1"
    >

    <handler name = "thread init">
        thread->animate = (tcb->trace >= ASL_TRACE_MED);
        smt_thread_set_next_event (thread, peer_alive_event);
    </handler>

    <handler name = "thread destroy">
        tcb->heartbeat_thread = NULL;

    </handler>

    <state name = "monitor heartbeat">
        <event name = "peer alive" nextstate = "monitor heartbeat">
            <action name = "wait for heartbeat interval" />
            <action name = "check peer liveness" />
        </event>
        <event name = "peer slowing" nextstate = "monitor heartbeat">
            <action name = "report peer slowing" />
            <action name = "wait for heartbeat interval" />
            <action name = "check peer liveness" />
        </event>
        <event name = "peer stopped" nextstate = "">
            <action name = "shut down agent" />
            <action name = "report peer stopped" />
        </event>
    </state>

    <action name = "wait for heartbeat interval">
        smt_timer_request_delay (thread, tcb->heartbeat * 1000 * 1000, SMT_NULL_EVENT);
    </action>

    <action name = "check peer liveness">
        //  Decrease peer liveness.  If liveness reaches 1 log a warning, if
        //  liveness reaches zero, pronounce the peer dead
        tcb->liveness--;
        if (tcb->liveness) {
            if (tcb->liveness == 1)
                smt_thread_set_next_event (thread, peer_slowing_event);
            else
                smt_thread_set_next_event (thread, peer_alive_event);
        }
        else
            smt_thread_set_next_event (thread, peer_stopped_event);
    </action>

    <action name = "report peer slowing">
        smt_log_print (http_server->alert_log,
            "W: peer heartbeat slowing (%s)", tcb->host);
    </action>

    <!--  If heartbeats stop we can't use an exception to notify the agent
          since it is likely to be blocked waiting for socket requests to
          complete.                                                         -->

    <action name = "shut down agent">
        if (tcb->input_thread)
            smt_thread_shut_down (tcb->input_thread);
        if (tcb->connection_thread)
            smt_thread_shut_down (tcb->connection_thread);
    </action>

    <action name = "report peer stopped">
        smt_log_print (http_server->alert_log,
            "W: peer heartbeat stopped, closing connection (%s)", tcb->host);
    </action>

    <!--  Defaults for heartbeat thread                                     -->

    <state name = "defaults">
        <!-- Exception events -->
        <event name = "smt error" nextstate = "">
            <action name = "notify connection of exception" />
        </event>

    </state>

</thread>

<!---------------------------------------------------------------------------->
<!--  Helper code shared between agents  ------------------------------------->

<private name = "types">
//  Function prototypes

//  Raises a connection exception
static void
s_connection_exception (
    smt_thread_t *thread,
    dbyte reply_code,
    char *reply_text,
    dbyte faulting_class_id,
    dbyte faulting_method_id);

//  Aborts the connection immediately
static void
s_connection_abort (
    smt_thread_t *thread,
    dbyte reply_code,
    char *reply_text,
    dbyte faulting_class_id,
    dbyte faulting_method_id);

//  Helper function for reporting errors
static void
s_report_error (
    smt_thread_t *thread,
    char *context,
    char *action_taken,
    dbyte reply_code,
    char *reply_text,
    dbyte faulting_class_id,
    dbyte faulting_method_id);

//  Executes an incoming method
static inline void
s_execute_method (
    smt_thread_t *thread,
    Bool channel_method,
    int class_id,
    int method_id);

//  Executes an incoming functional method
static void
s_execute_functional_method (
    smt_thread_t *thread,
    dbyte class_id,
    dbyte method_id,
    dbyte out_class_id,
    dbyte out_method_id);

//  Writes a non-null payload to the socket
static void
s_write_payload (
    smt_thread_t *thread,
    dbyte channel,
    byte type,
    ipr_bucket_t **bucket_p);

//  Writes an outgoing method to the socket
static void
s_send_method_out (
    smt_thread_t *thread,
    dbyte channel,
    smt_log_t *log);

//  Helper functions for socket input/output
static inline void
s_socket_write (
    smt_thread_t *thread,
    byte *buffer,
    size_t size);

static inline void
s_socket_write_bucket (
    smt_thread_t *thread,
    ipr_bucket_t *bucket);

static void inline
s_socket_write_shortstr (
    smt_thread_t *thread,
    char *string);

static inline void
s_socket_read (
    smt_thread_t *thread,
    byte *buffer,
    size_t size);

static inline void
s_socket_read_bucket (
    smt_thread_t *thread,
    ipr_bucket_t **bucket_p,
    size_t size);

//  Table of predecessor methods for each method.  If >0, then when we get a
//  specific method we can assert that we previously sent the predecessor on
//  the same channel.
static dbyte s_class_index [7 + 1] = {
    10, 20, 40, 50, 60, 61500, 61501, 0
};
static dbyte s_method_index [7][15] = {
    {  10, 11, 20, 21, 30, 31, 40, 41, 50, 51,  0,  0,  0,  0,  0 },
    {  10, 11, 20, 21, 40, 41,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {  10, 11, 20, 21,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {  10, 11, 20, 21, 30, 31, 40, 41, 50, 51,  0,  0,  0,  0,  0 },
    {  10, 11, 20, 21, 30, 31, 40, 50, 60, 70, 71, 72, 80, 90,  0 },
    {  10, 11, 20, 21,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {  10, 20, 30, 40, 50, 60,  0,  0,  0,  0,  0,  0,  0,  0,  0 }
};
static dbyte s_predecessor [7][15] = {
    {   0, 10,  0, 20,  0, 30,  0, 40,  0, 50,  0,  0,  0,  0,  0 },
    {   0, 10,  0, 20,  0, 40,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {   0, 10,  0, 20,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {   0, 10,  0, 20,  0, 30,  0, 40,  0, 50,  0,  0,  0,  0,  0 },
    {   0, 10,  0, 20,  0, 30,  0,  0,  0,  0, 70, 70,  0,  0,  0 },
    {   0, 10,  0, 20,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 },
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 }
};
</private>

<private name = "functions">
#define tcb ((zyre_peer_agent_connection_context_t *) thread->context)

//  Raises a connection exception
//  Called internally by the agent when a protocol error is detected
static void
s_connection_exception (
    smt_thread_t *thread,               //  Calling thread
    dbyte reply_code,                   //  Error code
    char *reply_text,                   //  Error text
    dbyte faulting_class_id,            //  Faulting class id, if any
    dbyte faulting_method_id)           //  Faulting method id, if any
{
    s_report_error (thread, "Connection", "closing connection",
        reply_code, reply_text, faulting_class_id, faulting_method_id);

    //  Save reply code for zyre_peer_connection
    tcb->reply_code = reply_code;
    icl_shortstr_cpy (tcb->reply_text, reply_text);
    smt_thread_raise_exception (thread, connection_error_event);
}

//  Aborts the connection immediately
//  Called internally by the agent if we detect an unrecoverable error
//  (e.g. malformed frame)
static void
s_connection_abort (
    smt_thread_t *thread,               //  Calling thread
    dbyte reply_code,                   //  Error code
    char *reply_text,                   //  Error text
    dbyte faulting_class_id,            //  Faulting class id, if any
    dbyte faulting_method_id)           //  Faulting method id, if any
{
    s_report_error (thread, "Connection", "aborting connection",
        reply_code, reply_text, faulting_class_id, faulting_method_id);

    //  Save reply code for zyre_peer_connection
    tcb->reply_code = reply_code;
    icl_shortstr_cpy (tcb->reply_text, reply_text);
    smt_thread_raise_exception (thread, connection_abort_event);
}

//  Helper function to report connection and channel errors
static void
s_report_error (
    smt_thread_t *thread,               //  Calling thread
    char *context,                      //  Error context
    char *action_taken,                 //  Action taken
    dbyte reply_code,                   //  Error code
    char *reply_text,                   //  Error text
    dbyte faulting_class_id,            //  Faulting class id, if any
    dbyte faulting_method_id)           //  Faulting method id, if any
{
    if (reply_code == 100)
        return;
    if ((tcb->trace >= ASL_TRACE_MED || reply_code >= 500) &&
        faulting_class_id && faulting_method_id)
        smt_log_print (http_server->alert_log,
            "E: %s error: %d %s "
            "(faulting method %u, %u), %s "  "(%s)",
            context, reply_code, reply_text,
            faulting_class_id, faulting_method_id, action_taken,
            tcb->host);
    else
        smt_log_print (http_server->alert_log,
            "E: %s error: %d %s, %s "  "(%s)",
            context, reply_code, reply_text, action_taken,
            tcb->host);
}

//  Executes an incoming method if it matches the requested method,
//  raises a connection exception if not.
static inline void
s_execute_method (
    smt_thread_t *thread,               //  Thread executing the method
    Bool channel_method,                //  FALSE == connection method
    int class_id,                       //  Expected class id
    int method_id                       //  Expected method id
    )
{
    if (tcb->method_in->class_id  == class_id
    &&  tcb->method_in->method_id == method_id) {
        zyre_peer_method_execute (tcb->method_in, tcb->caller, thread);
    }
    else
        s_connection_exception (thread, ASL_SYNTAX_ERROR,
            "Method not valid here",
            tcb->method_in->class_id,
            tcb->method_in->method_id);
}

//  Executes an incoming functional method.  Checks if we sent the predecessor
//  method (if any) and raises a connection exception if not.
static void
s_execute_functional_method (
    smt_thread_t *thread,               //  Thread executing the method
    dbyte class_id,                     //  Incoming class id
    dbyte method_id,                    //  Incoming method id
    dbyte out_class_id,                 //  Last sent class id
    dbyte out_method_id)                //  Last sent method id
{
    dbyte
        pred_method_id;                 //  Predecessor method id, if any
    uint
        class_index,
        method_index;

    //  Convert input class index (20, 30, 41,...) into lookup index
    for (class_index = 0; s_class_index [class_index]; class_index++)
        if (class_id == s_class_index [class_index])
            break;

    //  Convert input method index (20, 30, 41,...) into lookup index
    for (method_index = 0; s_method_index [class_index][method_index]; method_index++)
        if (method_id == s_method_index [class_index][method_index])
            break;

    //  If we got a method that requires a predecessor, check we sent that
    if (s_method_index [class_index][method_index]) {
        pred_method_id = s_predecessor [class_index][method_index];
        if (pred_method_id > 0
        && (pred_method_id != out_method_id
        &&  out_class_id == class_id))
            s_connection_exception (thread,
                ASL_SYNTAX_ERROR, "Method not allowed at this stage",
                method_id, class_id);
        else
            zyre_peer_method_execute (tcb->method_in, tcb->caller, thread);
    }
    else
        s_connection_exception (thread,
            ASL_SYNTAX_ERROR, "Method invalid - unknown method id",
            method_id, class_id);
}

//  Sends an outgoing method to the socket
static void
s_send_method_out (
    smt_thread_t *thread,
    dbyte channel,
    smt_log_t *log)
{
    ipr_bucket_t
        *payload;

    if (tcb->trace >= ASL_TRACE_LOW)
        zyre_peer_method_dump (tcb->method_out, log, "I: send ");

    //  Send the method
    payload = zyre_peer_method_encode (tcb->method_out);
    s_write_payload (thread, channel, ASL_FRAME_METHOD, &payload);

    tcb->out_class_id  = tcb->method_out->class_id;
    tcb->out_method_id = tcb->method_out->method_id;

}

//  Writes a non-null payload to the socket
static void
s_write_payload (
    smt_thread_t *thread,
    dbyte channel,
    byte type,                          //  Frame type indicator
    ipr_bucket_t **payload_p)
{
    ipr_bucket_t
        *payload = NULL,
        *bucket;                        //  Header bucket
    byte
        *bucket_ptr;
    static byte
        frame_end = ASL_FRAME_END;

    if (payload_p) {
        payload = *payload_p;
        if (!payload)
            return;                     //  Ignore empty payloads
    }
    if (payload->cur_size > tcb->frame_max) {
        icl_console_print ("E: frame type=%d is too large, discarded (size=%d, max=%d)",
            type, payload->cur_size, tcb->frame_max);
        return;
    }
    //  Write ASL frame header to normal bucket
    bucket = ipr_bucket_new (ASL_HEADER_SIZE);
    bucket_ptr = bucket->data;
    PUT_OCTET (bucket_ptr, type);
    PUT_SHORT (bucket_ptr, channel);
    PUT_LONG  (bucket_ptr, payload->cur_size);
    bucket->cur_size = bucket_ptr - bucket->data;

    s_socket_write_bucket (thread, bucket);
    s_socket_write_bucket (thread, payload);
    s_socket_write        (thread, &frame_end, 1);
    ipr_bucket_unlink (&bucket);
    ipr_bucket_unlink (payload_p);
}

//  Helper functions for socket input/output
static void inline
s_socket_write (
    smt_thread_t *thread,
    byte *buffer,
    size_t size)
{
    smt_socket_request_write (
        thread,
        tcb->socket,
        0,
        size,
        buffer,
        SMT_NULL_EVENT);
}

static void inline
s_socket_write_bucket (
    smt_thread_t *thread,
    ipr_bucket_t *bucket)
{
    smt_socket_request_write_bucket (
        thread,
        tcb->socket,
        0,
        bucket,
        SMT_NULL_EVENT);
}

static void inline
s_socket_write_shortstr (
    smt_thread_t *thread,
    char *string)
{
    ipr_bucket_t
        *bucket;                        //  Formatted output

    assert (strlen (string) < 256);
    bucket = ipr_bucket_new (256);
    bucket->data [0] = (byte) strlen (string);
    memcpy (bucket->data + 1, string, strlen (string));
    bucket->cur_size = 1 + strlen (string);
    s_socket_write_bucket (thread, bucket);
    ipr_bucket_unlink (&bucket);
}

static void inline
s_socket_read (
    smt_thread_t *thread,
    byte *buffer,
    size_t size)
{
    if (size <= IPR_BUCKET_MAX_SIZE) {
        smt_socket_request_read (
            thread,
            tcb->socket,
            0,
            size,
            size,
            buffer,
            SMT_NULL_EVENT);
    }
    else
        s_connection_abort (thread,
            ASL_FRAME_ERROR, "Illegal frame size specified", 0, 0);
}

static void inline
s_socket_read_bucket (
    smt_thread_t *thread,
    ipr_bucket_t **bucket_p,
    size_t size)
{
    if (size <= IPR_BUCKET_MAX_SIZE) {
        smt_socket_request_read_bucket (
            thread,
            tcb->socket,
            0,
            size,
            size,
            bucket_p,
            SMT_NULL_EVENT);
    }
    else
        s_connection_abort (thread,
            ASL_FRAME_ERROR, "Illegal frame size specified", 0, 0);
}

#undef tcb
</private>

</agent>
