<?xml?>
<class
    name      = "amq_mgt_broker"
    comment   = "Management console broker class"
    version   = "1.0"
    script    = "icl_gen"
    >
<doc>
Implements the management console broker object, used by applications
to manage OpenAMQ servers. Use in conjunction with the amq_mgt_console
class.
</doc>

<inherit class = "icl_object">
    <option name = "alloc" value = "cache" />
</inherit>

<import class = "amq_mgt_console" />
<import class = "amq_mgt_exchange" />
<import class = "amq_mgt_queue" />
<import class = "amq_mgt_connection" />
<import class = "amq_mgt_config" />

<context>
    amq_client_session_t
        *session;                       //  AMQP session
    int
        id;                             //  Object ID
    icl_shortstr_t
        notice;                         //  Message from server
    icl_shortstr_t
        name;                           //  Broker name
    icl_shortstr_t
        started;                        //  Date, time broker started
    Bool
        locked;                         //  Broker is locked?
    icl_shortstr_t
        datamem;                        //  Memory used for all data
    icl_shortstr_t
        bucketmem;                      //  Memory used for messages
    qbyte
        messages;                       //  Number of queued messages
    qbyte
        consumers;                      //  Number of queue consumers
    qbyte
        bindings;                       //  Number of queue bindings
    ipr_looseref_list_t
        *exchange_list;                 //  List of exchange objects
    ipr_looseref_t
        *exchange_ref;                  //  Current exchange position
    ipr_looseref_list_t
        *queue_list;                    //  List of queue objects
    ipr_looseref_t
        *queue_ref;                     //  Current queue position
    ipr_looseref_list_t
        *connection_list;               //  List of connection objects
    ipr_looseref_t
        *connection_ref;                //  Current connection position
    amq_mgt_config_t
        *config;                        //  Configuration
</context>

<method name = "new">
    <argument name = "session" type = "amq_client_session_t *">AMQP session</argument>
    <argument name = "id" type = "int">Object ID</argument>
    self->session = session;
    self->id = id;
    self->exchange_list = ipr_looseref_list_new ();
    self->queue_list = ipr_looseref_list_new ();
    self->connection_list = ipr_looseref_list_new ();
</method>

<method name = "destroy">
    s_destroy_children (self);
    ipr_looseref_list_destroy (&self->exchange_list);
    ipr_looseref_list_destroy (&self->queue_list);
    ipr_looseref_list_destroy (&self->connection_list);
</method>

<method name = "load" template = "function">
    <doc>
    Loads or refreshes the object from the server console. Returns 0
    if the object was refreshed, -1 if there was an error talking to
    the server.
    </doc>
    <local>
    ipr_xml_t
        *xml_root,                      //  Returned response tree
        *xml_cml,                       //  CML item
        *xml_command,                   //  CML command
        *xml_field;                     //  Field item in reply
    char
        *field_name,                    //  Name of returned field
        *field_value;                   //  Value of returned field
    amq_mgt_exchange_t
        *exchange;                      //  New exchange instance
    amq_mgt_queue_t
        *queue;                         //  New queue instance
    amq_mgt_connection_t
        *connection;                    //  New connection instance
    </local>
    //
    //  Send inspect request to console
    xml_root = s_request_response (self, "inspect", self->id, NULL, NULL);
    if (xml_root) {
        s_destroy_children (self);
        xml_cml     = ipr_xml_first_child (xml_root);
        xml_command = ipr_xml_first_child (xml_cml);
        xml_field   = ipr_xml_first_child (xml_command);
        ipr_xml_unlink (&xml_cml);
        ipr_xml_unlink (&xml_command);

        while (xml_field) {
            field_name  = ipr_xml_attr_get (xml_field, "name", "");
            field_value = ipr_xml_text (xml_field);
            if (field_value) {
                if (streq (field_name, "name")) {
                    icl_shortstr_cpy (self->name, field_value);
                }
                else
                if (streq (field_name, "started")) {
                    icl_shortstr_cpy (self->started, field_value);
                }
                else
                if (streq (field_name, "locked")) {
                    self->locked = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "datamem")) {
                    icl_shortstr_cpy (self->datamem, field_value);
                }
                else
                if (streq (field_name, "bucketmem")) {
                    icl_shortstr_cpy (self->bucketmem, field_value);
                }
                else
                if (streq (field_name, "messages")) {
                    self->messages = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "consumers")) {
                    self->consumers = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "bindings")) {
                    self->bindings = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "exchange")) {
                    exchange = amq_mgt_exchange_new (self->session, atoi (field_value));
                    ipr_looseref_queue (self->exchange_list, exchange);
                }
                else
                if (streq (field_name, "queue")) {
                    queue = amq_mgt_queue_new (self->session, atoi (field_value));
                    ipr_looseref_queue (self->queue_list, queue);
                }
                else
                if (streq (field_name, "connection")) {
                    connection = amq_mgt_connection_new (self->session, atoi (field_value));
                    ipr_looseref_queue (self->connection_list, connection);
                }
                else
                if (streq (field_name, "config")) {
                    self->config = amq_mgt_config_new (self->session, atoi (field_value));
                }
                icl_mem_free (field_value);
            }
            xml_field = ipr_xml_next_sibling (&xml_field);
        }
        ipr_xml_destroy (&xml_root);
    }
    else
        rc = -1;                        //  Object no longer available
</method>

<method name = "print children" template = "function">
    <doc>
    Prints the broker's contents to the console.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    char
        command [] = "";
    </local>
    //
    if (self_load (self))
        return (0);
    s_list_children (self, command, xml_data);
</method>

<method name = "print properties" template = "function">
    <doc>
    Prints the broker's values to the console in a two-column list.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    icl_shortstr_t
        field_value;
    </local>
    //
    if (self_load (self))
        return (0);

    icl_console_out (" broker = \\"%s\\" ", self->name);
    s_print_property ("Date, time broker started", *self->started? self->started: "(empty)", NULL, NULL);
    s_print_property ("Broker is locked?", self->locked? "yes": "no", NULL, NULL);
    s_print_property ("Memory used for all data", *self->datamem? self->datamem: "(empty)", NULL, NULL);
    s_print_property ("Memory used for messages", *self->bucketmem? self->bucketmem: "(empty)", NULL, NULL);
    sprintf (field_value, "%d", self->messages);
    s_print_property ("Number of queued messages", field_value, NULL, NULL);
    sprintf (field_value, "%d", self->consumers);
    s_print_property ("Number of queue consumers", field_value, NULL, NULL);
    sprintf (field_value, "%d", self->bindings);
    s_print_property ("Number of queue bindings", field_value, NULL, NULL);
    sprintf (field_value, "%d", ipr_looseref_list_count (self->exchange_list));
    s_print_property ("Number of message exchanges", field_value, NULL, "[ls exchange]");
    sprintf (field_value, "%d", ipr_looseref_list_count (self->queue_list));
    s_print_property ("Number of shared queues", field_value, NULL, "[ls queue]");
    sprintf (field_value, "%d", ipr_looseref_list_count (self->connection_list));
    s_print_property ("Number of connections", field_value, NULL, "[ls connection]");
    icl_console_out (" [shutdown] [lock]");
    //  Record data in XML form if wanted
    if (xml_data) {
        fprintf (xml_data, "&lt;broker id = \\"%d\\""
            " name = \\"%s\\""
            " started = \\"%s\\""
            " locked = \\"%d\\""
            " datamem = \\"%s\\""
            " bucketmem = \\"%s\\""
            " messages = \\"%d\\""
            " consumers = \\"%d\\""
            " bindings = \\"%d\\""
            "/&gt;\\n", self->id
            , self->name
            , self->started
            , self->locked
            , self->datamem
            , self->bucketmem
            , self->messages
            , self->consumers
            , self->bindings
        );
    }
</method>

<method name = "print summary" template = "function">
    <doc>
    Prints the broker to the console in a single row.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    </local>
    //
    icl_console_out (" %d) broker = \\"%s\\"  ", self->id, self->name);
    //  Record data in XML form if wanted
    if (xml_data) {
        fprintf (xml_data, "&lt;broker id = \\"%d\\""
            " name = \\"%s\\""
            " started = \\"%s\\""
            " locked = \\"%d\\""
            " datamem = \\"%s\\""
            " bucketmem = \\"%s\\""
            " messages = \\"%d\\""
            " consumers = \\"%d\\""
            " bindings = \\"%d\\""
            "/&gt;\\n", self->id
            , self->name
            , self->started
            , self->locked
            , self->datamem
            , self->bucketmem
            , self->messages
            , self->consumers
            , self->bindings
        );
    }
</method>

<method name = "exchange first" return = "exchange">
    <doc>
    Locate first exchange child of exchange, returns object reference
    or null.
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "exchange" type = "amq_mgt_exchange_t *">Returned exchange</declare>
    //
    self->exchange_ref = ipr_looseref_list_first (self->exchange_list);
    if (self->exchange_ref)
        exchange = self->exchange_ref->object;
    else
        exchange = NULL;
</method>

<method name = "exchange next" return = "exchange">
    <doc>
    Locate next exchange child of exchange, returns object reference
    or null.  If done after loading object, or after reaching end of list,
    returns first child exchange (again).
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "exchange" type = "amq_mgt_exchange_t *">Returned exchange</declare>
    //
    if (self->exchange_ref)
        self->exchange_ref = ipr_looseref_list_next (&self->exchange_ref);
    else
        self->exchange_ref = ipr_looseref_list_first (self->exchange_list);

    if (self->exchange_ref)
        exchange = self->exchange_ref->object;
    else
        exchange = NULL;
</method>

<method name = "queue first" return = "queue">
    <doc>
    Locate first queue child of queue, returns object reference
    or null.
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "queue" type = "amq_mgt_queue_t *">Returned queue</declare>
    //
    self->queue_ref = ipr_looseref_list_first (self->queue_list);
    if (self->queue_ref)
        queue = self->queue_ref->object;
    else
        queue = NULL;
</method>

<method name = "queue next" return = "queue">
    <doc>
    Locate next queue child of queue, returns object reference
    or null.  If done after loading object, or after reaching end of list,
    returns first child queue (again).
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "queue" type = "amq_mgt_queue_t *">Returned queue</declare>
    //
    if (self->queue_ref)
        self->queue_ref = ipr_looseref_list_next (&self->queue_ref);
    else
        self->queue_ref = ipr_looseref_list_first (self->queue_list);

    if (self->queue_ref)
        queue = self->queue_ref->object;
    else
        queue = NULL;
</method>

<method name = "connection first" return = "connection">
    <doc>
    Locate first connection child of connection, returns object reference
    or null.
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "connection" type = "amq_mgt_connection_t *">Returned connection</declare>
    //
    self->connection_ref = ipr_looseref_list_first (self->connection_list);
    if (self->connection_ref)
        connection = self->connection_ref->object;
    else
        connection = NULL;
</method>

<method name = "connection next" return = "connection">
    <doc>
    Locate next connection child of connection, returns object reference
    or null.  If done after loading object, or after reaching end of list,
    returns first child connection (again).
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "connection" type = "amq_mgt_connection_t *">Returned connection</declare>
    //
    if (self->connection_ref)
        self->connection_ref = ipr_looseref_list_next (&self->connection_ref);
    else
        self->connection_ref = ipr_looseref_list_first (self->connection_list);

    if (self->connection_ref)
        connection = self->connection_ref->object;
    else
        connection = NULL;
</method>

<method name = "cmdline" template = "function">
    <doc>
    Implements a command-line interface for the broker object.
    </doc>
    <argument name = "path" type = "char *">Current path</argument>
    <argument name = "depth" type = "int">Current depth</argument>
    <argument name = "tokens" type = "ipr_token_list_t *">Automation, if any</argument>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    icl_shortstr_t
        command;
    </local>
    //
#   define CD_UP    1                   //  Child cmdline asks to move up
#   define CD_TOP   2                   //  Child cmdline asks to move to top
#   define CD_EXIT  3                   //  Child cmdline asks to exit

    if (self_load (self))
        return (CD_UP);
    self_print_properties (self, xml_data);
    
    while (TRUE) {
        amq_client_session_wait (self->session, 1);
        if (!self->session->alive) {
            icl_console_print ("E: Server disconnected - %s", self->session->error_text);
            exit (EXIT_FAILURE);
        }
        //  If we're in autopilot mode, take next command else wait for user
        if (tokens) {
            ipr_token_t
                *token = ipr_token_list_first (tokens);
            if (token) {
                icl_shortstr_cpy (command, token->value);
                ipr_token_destroy (&token);
            }
            else {
                rc = CD_EXIT;
                break;
            }
        }
        else {
            //  Read command from stdin
            printf ("/%s>", path);
            strclr (command);
            if (fgets (command, 255, stdin))
                command [strlen (command) - 1] = 0;
        }
        ipr_str_lower (command);
        ipr_str_crop  (command);

        if (streq (command, ""))
            ;   //  Do nothing
        else
        if (streq (command, ".")) {
            if (self_load (self))
                return (CD_UP);
            self_print_properties (self, xml_data);
        }
        else
        if (ipr_str_prefixed (command, "ls")) {
            if (self_load (self))
                return (CD_UP);
            s_list_children (self, command + 2, xml_data);
        }
        else
        if (ipr_str_prefixed (command, "top")) {
            if (self_load (self))
                return (CD_UP);
            s_top_children (self, command + 3, xml_data);
        }
        else
        if (ipr_str_prefixed (command, "cd ")) {
            if (self_load (self))
                return (CD_UP);
            rc = s_change_level (self, command + 3, path, depth, tokens, xml_data);
            if (rc == CD_UP && depth) {
                rc = 0;
                break;
            }
            else
            if ((rc == CD_TOP && depth) || rc == CD_EXIT)
                break;
        }
        else
        if (atoi (command)) {
            if (self_load (self))
                return (CD_UP);
            rc = s_change_level (self, command, path, depth, tokens, xml_data);
            if (rc == CD_UP && depth) {
                rc = 0;
                break;
            }
            else
            if ((rc == CD_TOP && depth) || rc == CD_EXIT)
                break;
        }
        else
        if (streq (command, "..")) {
            if (depth)
                break;
        }
        else
        if (streq (command, "/")) {
            if (depth) {
                rc = CD_TOP;
                break;
            }
        }
        else
        if (ipr_str_prefixed (command, "set"))
            icl_console_out (" This object has no modifiable properties");
        else
        if (ipr_str_prefixed (command, "shutdown"))
            s_execute_shutdown (self, command);
        else
        if (ipr_str_prefixed (command, "lock"))
            s_execute_lock (self, command);
        else
        if (streq (command, "exit") || streq (command, "quit")) {
            rc = CD_EXIT;
            break;
        }
        else
        if (streq (command, "help"))
            s_show_help ();

        else {
            icl_console_out (" Not a valid command");
            s_show_help ();
        }
    }
</method>

<private name = "header">
static void
    s_destroy_children ($(selftype) *self);
static ipr_xml_t *
    s_request_response ($(selftype) *self, char *request, qbyte object_id,
        char *method, asl_field_list_t *fields);
static void
    s_print_property (char *label, char *value, char *name, char *command);
static int
    s_change_level ($(selftype) *self, char *command, char *path,
        int depth, ipr_token_list_t *tokens, FILE *xml_data);
static void
    s_list_children ($(selftype) *self, char *command, FILE *xml_data);
static void
    s_top_children ($(selftype) *self, char *command, FILE *xml_data);
static void
    s_execute_shutdown ($(selftype) *self, char *command);
static void
    s_execute_lock ($(selftype) *self, char *command);
static void
    s_show_help (void);
</private>

<private name = "footer">
//  Resets / destroys child objects
static void
s_destroy_children ($(selftype) *self)
{
    amq_mgt_exchange_t
        *exchange;                      //  Old exchange instance
    amq_mgt_queue_t
        *queue;                         //  Old queue instance
    amq_mgt_connection_t
        *connection;                    //  Old connection instance

    while ((exchange = (amq_mgt_exchange_t *) ipr_looseref_pop (self->exchange_list)))
        amq_mgt_exchange_destroy (&exchange);
    while ((queue = (amq_mgt_queue_t *) ipr_looseref_pop (self->queue_list)))
        amq_mgt_queue_destroy (&queue);
    while ((connection = (amq_mgt_connection_t *) ipr_looseref_pop (self->connection_list)))
        amq_mgt_connection_destroy (&connection);
    amq_mgt_config_destroy (&self->config);
}

//  Sends a request, returns a response content
static ipr_xml_t *
s_request_response (
    $(selftype) *self,
    char *request,
    qbyte object_id,
    char *method,
    asl_field_list_t *fields)
{
    amq_content_basic_t
        *content;                       //  Last content sent/recieved
    ipr_bucket_t
        *bucket = NULL;                 //  Message comes here
    icl_shortstr_t
        command;                        //  CML request or reply name
    ipr_xml_t
        *xml_root = NULL,               //  Tree of file we've loaded
        *xml_cml,                       //  Top level cml item
        *xml_command;                   //  CML command
    char
        *reply_class,                   //  Returned class string
        *reply_status;                  //  Returned status value
    long
        reply_object;                   //  Returned object id

    icl_shortstr_fmt (command, "%s-request", request);
    content = amq_cml_encode (command, "broker", object_id, NULL, method, fields);
    amq_content_basic_set_reply_to (content, self->session->queue);
    amq_client_session_basic_publish (
        self->session, content, 0, "amq.system", "amq.console", FALSE, FALSE);
    amq_content_basic_unlink (&content);

    //  Wait for response on our queue
    if (amq_client_session_wait (self->session, 10000) == 0)
        content = amq_client_session_basic_arrived (self->session);

    //  Process response, if any
    if (content) {
        //  TODO: amq_cml_decode
        //  Get content body into a bucket
        bucket = ipr_bucket_new (IPR_BUCKET_MAX_SIZE);
        bucket->cur_size = amq_content_basic_get_body (content, bucket->data, bucket->max_size);
        assert (bucket->cur_size < IPR_BUCKET_MAX_SIZE);
        bucket->data [bucket->cur_size] = 0;

        //  Parse as XML message
        ipr_xml_load_string (&xml_root, (char *) bucket->data, FALSE);
        ipr_bucket_unlink (&bucket);
        assert (xml_root);

        //  Check that the result is valid CML
        xml_cml = ipr_xml_first_child (xml_root);
        assert (xml_cml);
        assert (ipr_xml_name (xml_cml));
        assert (streq (ipr_xml_name (xml_cml), "cml"));
        
        //  Check that the response matches our request
        xml_command = ipr_xml_first_child (xml_cml);
        assert (xml_command);
        assert (ipr_xml_name (xml_command));

        reply_class  = ipr_xml_attr_get (xml_command, "class",  "");
        reply_status = ipr_xml_attr_get (xml_command, "status", "");
        reply_object = atol (ipr_xml_attr_get (xml_command, "object", ""));
        icl_shortstr_cpy (self->notice, ipr_xml_attr_get (xml_command, "notice", ""));

        if (streq (ipr_xml_name (xml_command), "invalid")) {
            icl_console_print ("E: invalid request sent to console");
            exit (EXIT_FAILURE);
        }
        else
        if (streq (ipr_xml_name (xml_command), "notify"))
            ;   //  Handle notification and loop for next content
        else {
            //  Check that the response is the reply for our object
            icl_shortstr_fmt (command, "%s-reply", request);
            assert (streq (ipr_xml_name (xml_command), command));
            if (streq (reply_status, "ok")) {
                if (strneq (reply_class, "broker"))
                    icl_console_print ("E: received OK for '%s', expected 'broker'", reply_class);
                assert (streq (reply_class, "broker"));
                assert (reply_object == self->id);
            }
            else
            if (streq (reply_status, "notfound")) {
                icl_console_print ("E: object was not found");
                //  If command not valid, return NULL
                ipr_xml_destroy (&xml_root);
            }
            else
            if (streq (reply_status, "noaccess")) {
                icl_console_out (" Not allowed to execute requested operation");
                //  If command not valid, return NULL
                ipr_xml_destroy (&xml_root);
            }
            else
            if (streq (reply_status, "invalid")) {
                icl_console_print ("E: internal error in CML formatting");
                //  If command not valid, return NULL
                ipr_xml_destroy (&xml_root);
            }
        }
        amq_content_basic_unlink (&content);
        ipr_xml_unlink (&xml_command);
        ipr_xml_unlink (&xml_cml);
        return (xml_root);
    }
    else {
        icl_console_out (" No reply from server - %s", self->session->error_text);
        exit (EXIT_FAILURE);
    }
}

static void
s_print_property (char *label, char *value, char *name, char *command)
{
    icl_shortstr_t
        property;

    icl_shortstr_fmt (property, " %s ...", label);
    while (strlen (property) < 40)
        strcat (property, ".");
    strcat (property, " ");
    strcat (property, value);
    if (name) {
        while (strlen (property) < 60)
            strcat (property, " ");
        icl_shortstr_cat (property, "(set ");
        icl_shortstr_cat (property, name);
        icl_shortstr_cat (property, ")");
    }
    if (command) {
        icl_shortstr_cat (property, " ");
        icl_shortstr_cat (property, command);
    }
    icl_console_out (property);
}


static int
s_change_level (
    $(selftype) *self,
    char *command,
    char *path,
    int depth,
    ipr_token_list_t *tokens,
    FILE *xml_data)
{
    int
        rc = 0,
        child_id;
    Bool
        id_found = FALSE;
    icl_shortstr_t
        child_path;
    amq_mgt_exchange_t
        *exchange;                      //  Child exchange
    amq_mgt_queue_t
        *queue;                         //  Child queue
    amq_mgt_connection_t
        *connection;                    //  Child connection

    ipr_str_crop (ipr_str_skip (command));
    if (streq (command, ".."))
        rc = CD_UP;
    else
    if (streq (command, "/"))
        rc = CD_TOP;
    else
    if ((child_id = atoi (command))) {
        exchange = self_exchange_first (self);
        while (exchange) {
            if (exchange->id == child_id) {
                icl_shortstr_fmt (child_path, "%s/exchange", path);
                rc = amq_mgt_exchange_cmdline (exchange, child_path, depth + 1, tokens, xml_data);
                id_found = TRUE;
            }
            exchange = self_exchange_next (self);
        }
        queue = self_queue_first (self);
        while (queue) {
            if (queue->id == child_id) {
                icl_shortstr_fmt (child_path, "%s/queue", path);
                rc = amq_mgt_queue_cmdline (queue, child_path, depth + 1, tokens, xml_data);
                id_found = TRUE;
            }
            queue = self_queue_next (self);
        }
        connection = self_connection_first (self);
        while (connection) {
            if (connection->id == child_id) {
                icl_shortstr_fmt (child_path, "%s/connection", path);
                rc = amq_mgt_connection_cmdline (connection, child_path, depth + 1, tokens, xml_data);
                id_found = TRUE;
            }
            connection = self_connection_next (self);
        }
        if (self->config->id == child_id) {
            icl_shortstr_fmt (child_path, "%s/config", path);
            rc = amq_mgt_config_cmdline (self->config, child_path, depth + 1, tokens, xml_data);
            id_found = TRUE;
        }
        if (!id_found)
            icl_console_out (" No item number %d in scope", child_id);
    }
    else
        icl_console_out (" Invalid command, use 'cd [number]'");

    return (rc);
}

static void
s_list_children ($(selftype) *self, char *command, FILE *xml_data)
{
    ipr_token_list_t
        *tokens;
    ipr_token_t
        *token;
    char
        *childname = NULL,
        *pattern = NULL;
    amq_mgt_exchange_t
        *exchange;                      //  Child exchange
    amq_mgt_queue_t
        *queue;                         //  Child queue
    amq_mgt_connection_t
        *connection;                    //  Child connection

    //  Get child name if any
    tokens = ipr_token_split (command);
    token = ipr_token_list_first (tokens);
    if (token) {
        if (strchr (token->value, '?') || strchr (token->value, '*'))
            pattern = token->value;
        else {
            childname = token->value;
            token = ipr_token_list_next (&token);
            if (token)
                pattern = token->value;
        }
        ipr_token_unlink (&token);
    }
    if (!childname || ipr_str_prefixed ("exchange", childname)) {
        exchange = self_exchange_first (self);
        while (exchange) {
            amq_mgt_exchange_load (exchange);
            if (!pattern
            || ipr_str_matches (exchange->name, pattern)
            || ipr_str_matches (exchange->type, pattern)
            )
                amq_mgt_exchange_print_summary (exchange, xml_data);
            exchange = self_exchange_next (self);
        }
    }
    if (!childname || ipr_str_prefixed ("queue", childname)) {
        icl_shortstr_t
            client_fmt;
        queue = self_queue_first (self);
        while (queue) {
            amq_mgt_queue_load (queue);
            ipr_net_fmt_display (client_fmt, queue->client, g_opt_addr);
            if (!pattern
            || ipr_str_matches (queue->name, pattern)
            || ipr_str_matches (client_fmt, pattern)
            || ipr_str_matches (queue->exchange_type, pattern)
            || ipr_str_matches (queue->routing_key, pattern)
            || ipr_str_matches (queue->binding_args, pattern)
            )
                amq_mgt_queue_print_summary (queue, xml_data);
            queue = self_queue_next (self);
        }
    }
    if (!childname || ipr_str_prefixed ("connection", childname)) {
        icl_shortstr_t
            address_fmt;
        connection = self_connection_first (self);
        while (connection) {
            amq_mgt_connection_load (connection);
            ipr_net_fmt_display (address_fmt, connection->address, g_opt_addr);
            if (!pattern
            || ipr_str_matches (connection->name, pattern)
            || ipr_str_matches (address_fmt, pattern)
            || ipr_str_matches (connection->user_name, pattern)
            || ipr_str_matches (connection->instance, pattern)
            || ipr_str_matches (connection->started, pattern)
            || ipr_str_matches (connection->product, pattern)
            || ipr_str_matches (connection->version, pattern)
            || ipr_str_matches (connection->platform, pattern)
            || ipr_str_matches (connection->information, pattern)
            )
                amq_mgt_connection_print_summary (connection, xml_data);
            connection = self_connection_next (self);
        }
    }
    if (!childname || ipr_str_prefixed ("config", childname)) {
        if (self->config) {
            amq_mgt_config_load (self->config);
            if (!pattern
            || ipr_str_matches (self->config->name, pattern)
            || ipr_str_matches (self->config->port, pattern)
            || ipr_str_matches (self->config->listen, pattern)
            || ipr_str_matches (self->config->vhost, pattern)
            || ipr_str_matches (self->config->user, pattern)
            || ipr_str_matches (self->config->group, pattern)
            || ipr_str_matches (self->config->log_path, pattern)
            || ipr_str_matches (self->config->archive_path, pattern)
            || ipr_str_matches (self->config->archive_cmd, pattern)
            || ipr_str_matches (self->config->alert_log, pattern)
            || ipr_str_matches (self->config->daily_log, pattern)
            || ipr_str_matches (self->config->debug_log, pattern)
            || ipr_str_matches (self->config->backup, pattern)
            || ipr_str_matches (self->config->primary, pattern)
            || ipr_str_matches (self->config->attach, pattern)
            || ipr_str_matches (self->config->attach_vhost, pattern)
            || ipr_str_matches (self->config->attach_login, pattern)
            || ipr_str_matches (self->config->attach_all, pattern)
            )
                amq_mgt_config_print_summary (self->config, xml_data);
        }
    }
    ipr_token_list_destroy (&tokens);
}

static void
s_top_children ($(selftype) *self, char *command, FILE *xml_data)
{
    ipr_token_list_t
        *tokens;
    ipr_token_t
        *token;
    icl_shortstr_t
        childname,
        criterion;
    uint
        top_count;                      //  Number of tops requested by user
    size_t
        *top_value;                     //  Key values for top items
    int
        *top_id;                        //  IDs of top items
    uint
        item_nbr,                       //  Where we intend to insert
        item_move,                      //  Use when moving items up
        nbr_tops;                       //  How many top items we have so far
    amq_mgt_exchange_t
        *exchange;                      //  Child exchange
    amq_mgt_queue_t
        *queue;                         //  Child queue
    amq_mgt_connection_t
        *connection;                    //  Child connection

    //  Get child name if any
    tokens = ipr_token_split (command);
    if (ipr_token_list_count (tokens) != 3) {
        icl_console_out ("Syntax error (top object-type sort-criterion number-of-items)");
        ipr_token_list_destroy (&tokens);
        return;
    }

    token = ipr_token_list_first (tokens);
    icl_shortstr_cpy (childname, token->value);
    token = ipr_token_list_next (&token);
    icl_shortstr_cpy (criterion, token->value);
    token = ipr_token_list_next (&token);
    top_count = atoi (token->value);
    if (top_count < 1) {
        icl_console_out ("Syntax error (number of items in top list must be grater than zero)");
        ipr_token_list_destroy (&tokens);
        return;
    }
    ipr_token_unlink (&token);

    if (0) {}
    else if (strcmp (childname, "exchange") == 0) {
        if (0) {}
        else if (strcmp (criterion, "bindings") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            exchange = self_exchange_first (self);
            nbr_tops = 0;
            while (exchange) {
                amq_mgt_exchange_load (exchange);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (exchange->bindings > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = exchange->bindings;
                    top_id    [item_nbr] = exchange->id;
                }
                exchange = self_exchange_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                exchange = amq_mgt_exchange_new (self->session, top_id [item_nbr]);
                amq_mgt_exchange_load (exchange);
                amq_mgt_exchange_print_summary (exchange, xml_data);
                amq_mgt_exchange_destroy (&exchange);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "messages_in") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            exchange = self_exchange_first (self);
            nbr_tops = 0;
            while (exchange) {
                amq_mgt_exchange_load (exchange);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (exchange->messages_in > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = exchange->messages_in;
                    top_id    [item_nbr] = exchange->id;
                }
                exchange = self_exchange_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                exchange = amq_mgt_exchange_new (self->session, top_id [item_nbr]);
                amq_mgt_exchange_load (exchange);
                amq_mgt_exchange_print_summary (exchange, xml_data);
                amq_mgt_exchange_destroy (&exchange);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "messages_out") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            exchange = self_exchange_first (self);
            nbr_tops = 0;
            while (exchange) {
                amq_mgt_exchange_load (exchange);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (exchange->messages_out > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = exchange->messages_out;
                    top_id    [item_nbr] = exchange->id;
                }
                exchange = self_exchange_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                exchange = amq_mgt_exchange_new (self->session, top_id [item_nbr]);
                amq_mgt_exchange_load (exchange);
                amq_mgt_exchange_print_summary (exchange, xml_data);
                amq_mgt_exchange_destroy (&exchange);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "megabytes_in") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            exchange = self_exchange_first (self);
            nbr_tops = 0;
            while (exchange) {
                amq_mgt_exchange_load (exchange);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (exchange->megabytes_in > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = exchange->megabytes_in;
                    top_id    [item_nbr] = exchange->id;
                }
                exchange = self_exchange_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                exchange = amq_mgt_exchange_new (self->session, top_id [item_nbr]);
                amq_mgt_exchange_load (exchange);
                amq_mgt_exchange_print_summary (exchange, xml_data);
                amq_mgt_exchange_destroy (&exchange);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "megabytes_out") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            exchange = self_exchange_first (self);
            nbr_tops = 0;
            while (exchange) {
                amq_mgt_exchange_load (exchange);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (exchange->megabytes_out > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = exchange->megabytes_out;
                    top_id    [item_nbr] = exchange->id;
                }
                exchange = self_exchange_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                exchange = amq_mgt_exchange_new (self->session, top_id [item_nbr]);
                amq_mgt_exchange_load (exchange);
                amq_mgt_exchange_print_summary (exchange, xml_data);
                amq_mgt_exchange_destroy (&exchange);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else {
            icl_console_out ("'%s' objects cannot be sorted by '%s' criterion",
                childname, criterion);
            ipr_token_list_destroy (&tokens);
            return;
        }
    }
    else if (strcmp (childname, "queue") == 0) {
        if (0) {}
        else if (strcmp (criterion, "pending") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue = self_queue_first (self);
            nbr_tops = 0;
            while (queue) {
                amq_mgt_queue_load (queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue->pending > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = queue->pending;
                    top_id    [item_nbr] = queue->id;
                }
                queue = self_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue = amq_mgt_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_load (queue);
                amq_mgt_queue_print_summary (queue, xml_data);
                amq_mgt_queue_destroy (&queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "consumers") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue = self_queue_first (self);
            nbr_tops = 0;
            while (queue) {
                amq_mgt_queue_load (queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue->consumers > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = queue->consumers;
                    top_id    [item_nbr] = queue->id;
                }
                queue = self_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue = amq_mgt_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_load (queue);
                amq_mgt_queue_print_summary (queue, xml_data);
                amq_mgt_queue_destroy (&queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "messages_in") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue = self_queue_first (self);
            nbr_tops = 0;
            while (queue) {
                amq_mgt_queue_load (queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue->messages_in > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = queue->messages_in;
                    top_id    [item_nbr] = queue->id;
                }
                queue = self_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue = amq_mgt_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_load (queue);
                amq_mgt_queue_print_summary (queue, xml_data);
                amq_mgt_queue_destroy (&queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "messages_out") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue = self_queue_first (self);
            nbr_tops = 0;
            while (queue) {
                amq_mgt_queue_load (queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue->messages_out > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = queue->messages_out;
                    top_id    [item_nbr] = queue->id;
                }
                queue = self_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue = amq_mgt_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_load (queue);
                amq_mgt_queue_print_summary (queue, xml_data);
                amq_mgt_queue_destroy (&queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "megabytes_in") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue = self_queue_first (self);
            nbr_tops = 0;
            while (queue) {
                amq_mgt_queue_load (queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue->megabytes_in > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = queue->megabytes_in;
                    top_id    [item_nbr] = queue->id;
                }
                queue = self_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue = amq_mgt_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_load (queue);
                amq_mgt_queue_print_summary (queue, xml_data);
                amq_mgt_queue_destroy (&queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "megabytes_out") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue = self_queue_first (self);
            nbr_tops = 0;
            while (queue) {
                amq_mgt_queue_load (queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue->megabytes_out > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = queue->megabytes_out;
                    top_id    [item_nbr] = queue->id;
                }
                queue = self_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue = amq_mgt_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_load (queue);
                amq_mgt_queue_print_summary (queue, xml_data);
                amq_mgt_queue_destroy (&queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "drop_count") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue = self_queue_first (self);
            nbr_tops = 0;
            while (queue) {
                amq_mgt_queue_load (queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue->drop_count > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = queue->drop_count;
                    top_id    [item_nbr] = queue->id;
                }
                queue = self_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue = amq_mgt_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_load (queue);
                amq_mgt_queue_print_summary (queue, xml_data);
                amq_mgt_queue_destroy (&queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else {
            icl_console_out ("'%s' objects cannot be sorted by '%s' criterion",
                childname, criterion);
            ipr_token_list_destroy (&tokens);
            return;
        }
    }
    else if (strcmp (childname, "connection") == 0) {
        if (0) {}
        else if (strcmp (criterion, "pending") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection = self_connection_first (self);
            nbr_tops = 0;
            while (connection) {
                amq_mgt_connection_load (connection);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection->pending > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = connection->pending;
                    top_id    [item_nbr] = connection->id;
                }
                connection = self_connection_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection = amq_mgt_connection_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_load (connection);
                amq_mgt_connection_print_summary (connection, xml_data);
                amq_mgt_connection_destroy (&connection);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "messages_in") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection = self_connection_first (self);
            nbr_tops = 0;
            while (connection) {
                amq_mgt_connection_load (connection);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection->messages_in > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = connection->messages_in;
                    top_id    [item_nbr] = connection->id;
                }
                connection = self_connection_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection = amq_mgt_connection_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_load (connection);
                amq_mgt_connection_print_summary (connection, xml_data);
                amq_mgt_connection_destroy (&connection);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "messages_out") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection = self_connection_first (self);
            nbr_tops = 0;
            while (connection) {
                amq_mgt_connection_load (connection);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection->messages_out > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = connection->messages_out;
                    top_id    [item_nbr] = connection->id;
                }
                connection = self_connection_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection = amq_mgt_connection_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_load (connection);
                amq_mgt_connection_print_summary (connection, xml_data);
                amq_mgt_connection_destroy (&connection);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "megabytes_in") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection = self_connection_first (self);
            nbr_tops = 0;
            while (connection) {
                amq_mgt_connection_load (connection);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection->megabytes_in > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = connection->megabytes_in;
                    top_id    [item_nbr] = connection->id;
                }
                connection = self_connection_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection = amq_mgt_connection_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_load (connection);
                amq_mgt_connection_print_summary (connection, xml_data);
                amq_mgt_connection_destroy (&connection);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "megabytes_out") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection = self_connection_first (self);
            nbr_tops = 0;
            while (connection) {
                amq_mgt_connection_load (connection);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection->megabytes_out > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = connection->megabytes_out;
                    top_id    [item_nbr] = connection->id;
                }
                connection = self_connection_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection = amq_mgt_connection_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_load (connection);
                amq_mgt_connection_print_summary (connection, xml_data);
                amq_mgt_connection_destroy (&connection);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "trace") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection = self_connection_first (self);
            nbr_tops = 0;
            while (connection) {
                amq_mgt_connection_load (connection);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection->trace > top_value [item_nbr])
                        break;
                //  Move items up to make space for new item
                item_move = top_count - 1;
                while (item_move > item_nbr) {
                    top_value [item_move] = top_value [item_move - 1];
                    top_id    [item_move] = top_id    [item_move - 1];
                    item_move--;
                }
                if (nbr_tops < top_count)
                    nbr_tops++;
                if (item_nbr < top_count) {
                    top_value [item_nbr] = connection->trace;
                    top_id    [item_nbr] = connection->id;
                }
                connection = self_connection_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection = amq_mgt_connection_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_load (connection);
                amq_mgt_connection_print_summary (connection, xml_data);
                amq_mgt_connection_destroy (&connection);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else {
            icl_console_out ("'%s' objects cannot be sorted by '%s' criterion",
                childname, criterion);
            ipr_token_list_destroy (&tokens);
            return;
        }
    }
    else {
        icl_console_out ("Top list of '%s' objects not supported", childname);
        ipr_token_list_destroy (&tokens);
        return;
    }
    ipr_token_list_destroy (&tokens);
}

//  Execute shutdown method
//
static void
s_execute_shutdown ($(selftype) *self, char *command)
{
    ipr_token_list_t
        *tokens;
    ipr_token_t
        *token;
    ipr_xml_t
        *xml_root;                      //  Returned response tree
    asl_field_list_t
        *fields;                        //  Properties of object
    Bool
        is_valid = TRUE;                //  Valid method syntax?

    tokens = ipr_token_split (command);
    fields = asl_field_list_new (NULL);

    //  Skip method name, first token in string
    token = ipr_token_list_first (tokens);
    assert (token);

    ipr_token_unlink (&token);
    if (is_valid) {
        xml_root = s_request_response (self, "method", self->id, "shutdown", fields);
        if (xml_root) {
            icl_console_out (" OK");
            ipr_xml_destroy (&xml_root);
            if (self_load (self))
                return;
        }
        else
            icl_console_out (" ERROR");
    }
    else
        icl_console_out (" Usage: shutdown arguments, use 'help shutdown' for details");

    asl_field_list_destroy (&fields);
    ipr_token_list_destroy (&tokens);
}

//  Execute lock method
//
static void
s_execute_lock ($(selftype) *self, char *command)
{
    ipr_token_list_t
        *tokens;
    ipr_token_t
        *token;
    ipr_xml_t
        *xml_root;                      //  Returned response tree
    asl_field_list_t
        *fields;                        //  Properties of object
    Bool
        is_valid = TRUE;                //  Valid method syntax?

    tokens = ipr_token_split (command);
    fields = asl_field_list_new (NULL);

    //  Skip method name, first token in string
    token = ipr_token_list_first (tokens);
    assert (token);

    //  Collect setting value
    token = ipr_token_list_next (&token);
    if (token)
        asl_field_new_string (fields, "setting", token->value);
    else
        is_valid = FALSE;
    ipr_token_unlink (&token);
    if (is_valid) {
        xml_root = s_request_response (self, "method", self->id, "lock", fields);
        if (xml_root) {
            icl_console_out (" OK");
            ipr_xml_destroy (&xml_root);
            if (self_load (self))
                return;
        }
        else
            icl_console_out (" ERROR");
    }
    else
        icl_console_out (" Usage: lock arguments, use 'help lock' for details");

    asl_field_list_destroy (&fields);
    ipr_token_list_destroy (&tokens);
}

static void
s_show_help (void)
{
    icl_console_out ("");
    icl_console_out (" Command               Has this effect");
    icl_console_out (" -------               -------------------");
    icl_console_out (" ls [child] [pattern]  Show matching children");
    icl_console_out (" top [child]           Show most important children");
    icl_console_out (" cd [nnn]              Look at item [number nnn]");
    icl_console_out (" nnn                   Look at item number nnn");
    icl_console_out (" /                     Return to broker item");
    icl_console_out (" .                     Show current item");
    icl_console_out (" ..                    Move back to previous item");
    icl_console_out (" set name value        Set object property");
    icl_console_out (" help                  Show this text");
    icl_console_out (" exit | quit           Leave the OpenAMQ shell");
    icl_console_out ("");
    icl_console_out ("");
    icl_console_out (" shutdown");
    icl_console_out ("     Shuts-down the broker. All client connections are broken, and");
    icl_console_out ("     the broker process will exit.                                ");
    icl_console_out ("");
    icl_console_out (" lock 1|0");
    icl_console_out ("     Locks or unlocks the broker. When the broker is locked it will");
    icl_console_out ("     refuse new client connections, though you can still connect   ");
    icl_console_out ("     using the shell.                                              ");
}
</private>

<method name = "selftest">
</method>

</class>
