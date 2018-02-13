<?xml?>
<class
    name      = "amq_mgt_queue"
    comment   = "Management console queue class"
    version   = "1.0"
    script    = "icl_gen"
    >
<doc>
Implements the management console queue object, used by applications
to manage OpenAMQ servers. Use in conjunction with the amq_mgt_console
class.
</doc>

<inherit class = "icl_object">
    <option name = "alloc" value = "cache" />
</inherit>

<import class = "amq_mgt_console" />
<import class = "amq_mgt_queue_connection" />
<import class = "amq_mgt_queue_binding" />

<context>
    amq_client_session_t
        *session;                       //  AMQP session
    int
        id;                             //  Object ID
    icl_shortstr_t
        notice;                         //  Message from server
    icl_shortstr_t
        name;                           //  Message Queue
    qbyte
        pending;                        //  Messages pending
    Bool
        exclusive;                      //  Exclusive queue?
    icl_shortstr_t
        client;                         //  Client host name
    icl_shortstr_t
        exchange_name;                  //  Exchange name
    icl_shortstr_t
        exchange_type;                  //  Exchange type
    icl_shortstr_t
        routing_key;                    //  Routing key
    icl_shortstr_t
        binding_args;                   //  Binding arguments
    Bool
        auto_delete;                    //  Auto-deleted?
    qbyte
        consumers;                      //  Number of consumers
    qbyte
        messages_in;                    //  Messages published
    qbyte
        messages_out;                   //  Messages consumed
    qbyte
        megabytes_in;                   //  Megabytes published
    qbyte
        megabytes_out;                  //  Megabytes consumed
    qbyte
        drop_count;                     //  Messages dropped
    ipr_looseref_list_t
        *queue_connection_list;         //  List of queue_connection objects
    ipr_looseref_t
        *queue_connection_ref;          //  Current queue_connection position
    ipr_looseref_list_t
        *queue_binding_list;            //  List of queue_binding objects
    ipr_looseref_t
        *queue_binding_ref;             //  Current queue_binding position
</context>

<method name = "new">
    <argument name = "session" type = "amq_client_session_t *">AMQP session</argument>
    <argument name = "id" type = "int">Object ID</argument>
    self->session = session;
    self->id = id;
    self->queue_connection_list = ipr_looseref_list_new ();
    self->queue_binding_list = ipr_looseref_list_new ();
</method>

<method name = "destroy">
    s_destroy_children (self);
    ipr_looseref_list_destroy (&self->queue_connection_list);
    ipr_looseref_list_destroy (&self->queue_binding_list);
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
    amq_mgt_queue_connection_t
        *queue_connection;              //  New queue_connection instance
    amq_mgt_queue_binding_t
        *queue_binding;                 //  New queue_binding instance
    </local>
    //
    //  Send inspect request to console
    assert (self->id);
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
                if (streq (field_name, "pending")) {
                    self->pending = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "exclusive")) {
                    self->exclusive = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "client")) {
                    icl_shortstr_cpy (self->client, field_value);
                }
                else
                if (streq (field_name, "exchange_name")) {
                    icl_shortstr_cpy (self->exchange_name, field_value);
                }
                else
                if (streq (field_name, "exchange_type")) {
                    icl_shortstr_cpy (self->exchange_type, field_value);
                }
                else
                if (streq (field_name, "routing_key")) {
                    icl_shortstr_cpy (self->routing_key, field_value);
                }
                else
                if (streq (field_name, "binding_args")) {
                    icl_shortstr_cpy (self->binding_args, field_value);
                }
                else
                if (streq (field_name, "auto_delete")) {
                    self->auto_delete = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "consumers")) {
                    self->consumers = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "messages_in")) {
                    self->messages_in = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "messages_out")) {
                    self->messages_out = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "megabytes_in")) {
                    self->megabytes_in = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "megabytes_out")) {
                    self->megabytes_out = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "drop_count")) {
                    self->drop_count = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "queue_connection")) {
                    queue_connection = amq_mgt_queue_connection_new (self->session, atoi (field_value));
                    ipr_looseref_queue (self->queue_connection_list, queue_connection);
                }
                else
                if (streq (field_name, "queue_binding")) {
                    queue_binding = amq_mgt_queue_binding_new (self->session, atoi (field_value));
                    ipr_looseref_queue (self->queue_binding_list, queue_binding);
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
    Prints the queue's contents to the console.
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
    Prints the queue's values to the console in a two-column list.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    icl_shortstr_t
        field_value;
    icl_shortstr_t
        client_fmt;
    </local>
    //
    if (self_load (self))
        return (0);

    icl_console_out (" queue = \\"%s\\" ", self->name);
    sprintf (field_value, "%d", self->pending);
    s_print_property ("Messages pending", field_value, NULL, NULL);
    s_print_property ("Exclusive queue?", self->exclusive? "yes": "no", NULL, NULL);
    ipr_net_fmt_display (client_fmt, self->client, g_opt_addr);
    s_print_property ("Client host name", client_fmt, NULL, NULL);
    s_print_property ("Exchange name", *self->exchange_name? self->exchange_name: "(empty)", NULL, NULL);
    s_print_property ("Exchange type", *self->exchange_type? self->exchange_type: "(empty)", NULL, NULL);
    s_print_property ("Routing key", *self->routing_key? self->routing_key: "(empty)", NULL, NULL);
    s_print_property ("Binding arguments", *self->binding_args? self->binding_args: "(empty)", NULL, NULL);
    s_print_property ("Auto-deleted?", self->auto_delete? "yes": "no", NULL, NULL);
    sprintf (field_value, "%d", self->consumers);
    s_print_property ("Number of consumers", field_value, NULL, NULL);
    sprintf (field_value, "%d", self->messages_in);
    s_print_property ("Messages published", field_value, NULL, NULL);
    sprintf (field_value, "%d", self->messages_out);
    s_print_property ("Messages consumed", field_value, NULL, NULL);
    sprintf (field_value, "%d", self->megabytes_in);
    s_print_property ("Megabytes published", field_value, NULL, NULL);
    sprintf (field_value, "%d", self->megabytes_out);
    s_print_property ("Megabytes consumed", field_value, NULL, NULL);
    sprintf (field_value, "%d", self->drop_count);
    s_print_property ("Messages dropped", field_value, NULL, NULL);
    sprintf (field_value, "%d", ipr_looseref_list_count (self->queue_connection_list));
    s_print_property ("Number of queue connections", field_value, NULL, "[ls queue_connection]");
    sprintf (field_value, "%d", ipr_looseref_list_count (self->queue_binding_list));
    s_print_property ("Number of queue bindings", field_value, NULL, "[ls queue_binding]");
    icl_console_out (" [purge]");
    //  Record data in XML form if wanted
    if (xml_data) {
        fprintf (xml_data, "&lt;queue id = \\"%d\\""
            " name = \\"%s\\""
            " pending = \\"%d\\""
            " exclusive = \\"%d\\""
            " client = \\"%s\\""
            " exchange_name = \\"%s\\""
            " exchange_type = \\"%s\\""
            " routing_key = \\"%s\\""
            " binding_args = \\"%s\\""
            " auto_delete = \\"%d\\""
            " consumers = \\"%d\\""
            " messages_in = \\"%d\\""
            " messages_out = \\"%d\\""
            " megabytes_in = \\"%d\\""
            " megabytes_out = \\"%d\\""
            " drop_count = \\"%d\\""
            "/&gt;\\n", self->id
            , self->name
            , self->pending
            , self->exclusive
            , self->client
            , self->exchange_name
            , self->exchange_type
            , self->routing_key
            , self->binding_args
            , self->auto_delete
            , self->consumers
            , self->messages_in
            , self->messages_out
            , self->megabytes_in
            , self->megabytes_out
            , self->drop_count
        );
    }
</method>

<method name = "print summary" template = "function">
    <doc>
    Prints the queue to the console in a single row.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    icl_shortstr_t
        client_fmt;
    </local>
    //
    ipr_net_fmt_display (client_fmt, self->client, g_opt_addr);
    icl_console_out (" %d) queue = \\"%s\\" pending=%d exclusive=%s client=\\"%s\\" exchange_name=\\"%s\\" exchange_type=\\"%s\\" routing_key=\\"%s\\" binding_args=\\"%s\\" auto_delete=%s consumers=%d messages_in=%d messages_out=%d megabytes_in=%d megabytes_out=%d  ", self->id, self->name, self->pending, self->exclusive? "yes": "no", client_fmt, *self->exchange_name? self->exchange_name: "(empty)", *self->exchange_type? self->exchange_type: "(empty)", *self->routing_key? self->routing_key: "(empty)", *self->binding_args? self->binding_args: "(empty)", self->auto_delete? "yes": "no", self->consumers, self->messages_in, self->messages_out, self->megabytes_in, self->megabytes_out);
    //  Record data in XML form if wanted
    if (xml_data) {
        fprintf (xml_data, "&lt;queue id = \\"%d\\""
            " name = \\"%s\\""
            " pending = \\"%d\\""
            " exclusive = \\"%d\\""
            " client = \\"%s\\""
            " exchange_name = \\"%s\\""
            " exchange_type = \\"%s\\""
            " routing_key = \\"%s\\""
            " binding_args = \\"%s\\""
            " auto_delete = \\"%d\\""
            " consumers = \\"%d\\""
            " messages_in = \\"%d\\""
            " messages_out = \\"%d\\""
            " megabytes_in = \\"%d\\""
            " megabytes_out = \\"%d\\""
            " drop_count = \\"%d\\""
            "/&gt;\\n", self->id
            , self->name
            , self->pending
            , self->exclusive
            , self->client
            , self->exchange_name
            , self->exchange_type
            , self->routing_key
            , self->binding_args
            , self->auto_delete
            , self->consumers
            , self->messages_in
            , self->messages_out
            , self->megabytes_in
            , self->megabytes_out
            , self->drop_count
        );
    }
</method>

<method name = "queue_connection first" return = "queue_connection">
    <doc>
    Locate first queue_connection child of queue_connection, returns object reference
    or null.
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "queue_connection" type = "amq_mgt_queue_connection_t *">Returned queue_connection</declare>
    //
    self->queue_connection_ref = ipr_looseref_list_first (self->queue_connection_list);
    if (self->queue_connection_ref)
        queue_connection = self->queue_connection_ref->object;
    else
        queue_connection = NULL;
</method>

<method name = "queue_connection next" return = "queue_connection">
    <doc>
    Locate next queue_connection child of queue_connection, returns object reference
    or null.  If done after loading object, or after reaching end of list,
    returns first child queue_connection (again).
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "queue_connection" type = "amq_mgt_queue_connection_t *">Returned queue_connection</declare>
    //
    if (self->queue_connection_ref)
        self->queue_connection_ref = ipr_looseref_list_next (&self->queue_connection_ref);
    else
        self->queue_connection_ref = ipr_looseref_list_first (self->queue_connection_list);

    if (self->queue_connection_ref)
        queue_connection = self->queue_connection_ref->object;
    else
        queue_connection = NULL;
</method>

<method name = "queue_binding first" return = "queue_binding">
    <doc>
    Locate first queue_binding child of queue_binding, returns object reference
    or null.
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "queue_binding" type = "amq_mgt_queue_binding_t *">Returned queue_binding</declare>
    //
    self->queue_binding_ref = ipr_looseref_list_first (self->queue_binding_list);
    if (self->queue_binding_ref)
        queue_binding = self->queue_binding_ref->object;
    else
        queue_binding = NULL;
</method>

<method name = "queue_binding next" return = "queue_binding">
    <doc>
    Locate next queue_binding child of queue_binding, returns object reference
    or null.  If done after loading object, or after reaching end of list,
    returns first child queue_binding (again).
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "queue_binding" type = "amq_mgt_queue_binding_t *">Returned queue_binding</declare>
    //
    if (self->queue_binding_ref)
        self->queue_binding_ref = ipr_looseref_list_next (&self->queue_binding_ref);
    else
        self->queue_binding_ref = ipr_looseref_list_first (self->queue_binding_list);

    if (self->queue_binding_ref)
        queue_binding = self->queue_binding_ref->object;
    else
        queue_binding = NULL;
</method>

<method name = "cmdline" template = "function">
    <doc>
    Implements a command-line interface for the queue object.
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
        if (ipr_str_prefixed (command, "purge"))
            s_execute_purge (self, command);
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
    s_execute_purge ($(selftype) *self, char *command);
static void
    s_show_help (void);
</private>

<private name = "footer">
//  Resets / destroys child objects
static void
s_destroy_children ($(selftype) *self)
{
    amq_mgt_queue_connection_t
        *queue_connection;              //  Old queue_connection instance
    amq_mgt_queue_binding_t
        *queue_binding;                 //  Old queue_binding instance

    while ((queue_connection = (amq_mgt_queue_connection_t *) ipr_looseref_pop (self->queue_connection_list)))
        amq_mgt_queue_connection_destroy (&queue_connection);
    while ((queue_binding = (amq_mgt_queue_binding_t *) ipr_looseref_pop (self->queue_binding_list)))
        amq_mgt_queue_binding_destroy (&queue_binding);
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
    content = amq_cml_encode (command, "queue", object_id, NULL, method, fields);
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
                if (strneq (reply_class, "queue"))
                    icl_console_print ("E: received OK for '%s', expected 'queue'", reply_class);
                assert (streq (reply_class, "queue"));
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
    amq_mgt_queue_connection_t
        *queue_connection;              //  Child queue_connection
    amq_mgt_queue_binding_t
        *queue_binding;                 //  Child queue_binding

    ipr_str_crop (ipr_str_skip (command));
    if (streq (command, ".."))
        rc = CD_UP;
    else
    if (streq (command, "/"))
        rc = CD_TOP;
    else
    if ((child_id = atoi (command))) {
        queue_connection = self_queue_connection_first (self);
        while (queue_connection) {
            if (queue_connection->id == child_id) {
                icl_shortstr_fmt (child_path, "%s/queue_connection", path);
                rc = amq_mgt_queue_connection_cmdline (queue_connection, child_path, depth + 1, tokens, xml_data);
                id_found = TRUE;
            }
            queue_connection = self_queue_connection_next (self);
        }
        queue_binding = self_queue_binding_first (self);
        while (queue_binding) {
            if (queue_binding->id == child_id) {
                icl_shortstr_fmt (child_path, "%s/queue_binding", path);
                rc = amq_mgt_queue_binding_cmdline (queue_binding, child_path, depth + 1, tokens, xml_data);
                id_found = TRUE;
            }
            queue_binding = self_queue_binding_next (self);
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
    amq_mgt_queue_connection_t
        *queue_connection;              //  Child queue_connection
    amq_mgt_queue_binding_t
        *queue_binding;                 //  Child queue_binding

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
    if (!childname || ipr_str_prefixed ("queue_connection", childname)) {
        icl_shortstr_t
            address_fmt;
        queue_connection = self_queue_connection_first (self);
        while (queue_connection) {
            amq_mgt_queue_connection_load (queue_connection);
            ipr_net_fmt_display (address_fmt, queue_connection->address, g_opt_addr);
            if (!pattern
            || ipr_str_matches (queue_connection->name, pattern)
            || ipr_str_matches (address_fmt, pattern)
            || ipr_str_matches (queue_connection->user_name, pattern)
            || ipr_str_matches (queue_connection->instance, pattern)
            || ipr_str_matches (queue_connection->started, pattern)
            || ipr_str_matches (queue_connection->product, pattern)
            || ipr_str_matches (queue_connection->version, pattern)
            || ipr_str_matches (queue_connection->platform, pattern)
            || ipr_str_matches (queue_connection->information, pattern)
            )
                amq_mgt_queue_connection_print_summary (queue_connection, xml_data);
            queue_connection = self_queue_connection_next (self);
        }
    }
    if (!childname || ipr_str_prefixed ("queue_binding", childname)) {
        queue_binding = self_queue_binding_first (self);
        while (queue_binding) {
            amq_mgt_queue_binding_load (queue_binding);
            if (!pattern
            || ipr_str_matches (queue_binding->name, pattern)
            || ipr_str_matches (queue_binding->exchange_name, pattern)
            || ipr_str_matches (queue_binding->exchange_type, pattern)
            || ipr_str_matches (queue_binding->binding_args, pattern)
            )
                amq_mgt_queue_binding_print_summary (queue_binding, xml_data);
            queue_binding = self_queue_binding_next (self);
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
    amq_mgt_queue_connection_t
        *queue_connection;              //  Child queue_connection
    amq_mgt_queue_binding_t
        *queue_binding;                 //  Child queue_binding

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
    else if (strcmp (childname, "queue_connection") == 0) {
        if (0) {}
        else if (strcmp (criterion, "messages_in") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue_connection = self_queue_connection_first (self);
            nbr_tops = 0;
            while (queue_connection) {
                amq_mgt_queue_connection_load (queue_connection);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue_connection->messages_in > top_value [item_nbr])
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
                    top_value [item_nbr] = queue_connection->messages_in;
                    top_id    [item_nbr] = queue_connection->id;
                }
                queue_connection = self_queue_connection_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue_connection = amq_mgt_queue_connection_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_connection_load (queue_connection);
                amq_mgt_queue_connection_print_summary (queue_connection, xml_data);
                amq_mgt_queue_connection_destroy (&queue_connection);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "messages_out") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue_connection = self_queue_connection_first (self);
            nbr_tops = 0;
            while (queue_connection) {
                amq_mgt_queue_connection_load (queue_connection);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue_connection->messages_out > top_value [item_nbr])
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
                    top_value [item_nbr] = queue_connection->messages_out;
                    top_id    [item_nbr] = queue_connection->id;
                }
                queue_connection = self_queue_connection_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue_connection = amq_mgt_queue_connection_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_connection_load (queue_connection);
                amq_mgt_queue_connection_print_summary (queue_connection, xml_data);
                amq_mgt_queue_connection_destroy (&queue_connection);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "megabytes_in") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue_connection = self_queue_connection_first (self);
            nbr_tops = 0;
            while (queue_connection) {
                amq_mgt_queue_connection_load (queue_connection);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue_connection->megabytes_in > top_value [item_nbr])
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
                    top_value [item_nbr] = queue_connection->megabytes_in;
                    top_id    [item_nbr] = queue_connection->id;
                }
                queue_connection = self_queue_connection_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue_connection = amq_mgt_queue_connection_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_connection_load (queue_connection);
                amq_mgt_queue_connection_print_summary (queue_connection, xml_data);
                amq_mgt_queue_connection_destroy (&queue_connection);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "megabytes_out") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue_connection = self_queue_connection_first (self);
            nbr_tops = 0;
            while (queue_connection) {
                amq_mgt_queue_connection_load (queue_connection);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue_connection->megabytes_out > top_value [item_nbr])
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
                    top_value [item_nbr] = queue_connection->megabytes_out;
                    top_id    [item_nbr] = queue_connection->id;
                }
                queue_connection = self_queue_connection_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue_connection = amq_mgt_queue_connection_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_connection_load (queue_connection);
                amq_mgt_queue_connection_print_summary (queue_connection, xml_data);
                amq_mgt_queue_connection_destroy (&queue_connection);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "trace") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            queue_connection = self_queue_connection_first (self);
            nbr_tops = 0;
            while (queue_connection) {
                amq_mgt_queue_connection_load (queue_connection);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (queue_connection->trace > top_value [item_nbr])
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
                    top_value [item_nbr] = queue_connection->trace;
                    top_id    [item_nbr] = queue_connection->id;
                }
                queue_connection = self_queue_connection_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                queue_connection = amq_mgt_queue_connection_new (self->session, top_id [item_nbr]);
                amq_mgt_queue_connection_load (queue_connection);
                amq_mgt_queue_connection_print_summary (queue_connection, xml_data);
                amq_mgt_queue_connection_destroy (&queue_connection);
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
    else if (strcmp (childname, "queue_binding") == 0) {
        if (0) {}
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

//  Execute purge method
//
static void
s_execute_purge ($(selftype) *self, char *command)
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
        xml_root = s_request_response (self, "method", self->id, "purge", fields);
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
        icl_console_out (" Usage: purge arguments, use 'help purge' for details");

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
    icl_console_out (" purge");
}
</private>

<method name = "selftest">
</method>

</class>
