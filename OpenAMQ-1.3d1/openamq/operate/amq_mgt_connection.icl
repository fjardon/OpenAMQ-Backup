<?xml?>
<class
    name      = "amq_mgt_connection"
    comment   = "Management console connection class"
    version   = "1.0"
    script    = "icl_gen"
    >
<doc>
Implements the management console connection object, used by applications
to manage OpenAMQ servers. Use in conjunction with the amq_mgt_console
class.
</doc>

<inherit class = "icl_object">
    <option name = "alloc" value = "cache" />
</inherit>

<import class = "amq_mgt_console" />
<import class = "amq_mgt_connection_queue" />

<context>
    amq_client_session_t
        *session;                       //  AMQP session
    int
        id;                             //  Object ID
    icl_shortstr_t
        notice;                         //  Message from server
    icl_shortstr_t
        name;                           //  Connection name
    qbyte
        pending;                        //  Messages pending
    icl_shortstr_t
        address;                        //  Client IP address:port
    icl_shortstr_t
        user_name;                      //  User login name
    icl_shortstr_t
        instance;                       //  Client instance name
    icl_shortstr_t
        started;                        //  Date, time connection started
    qbyte
        messages_in;                    //  Messages published
    qbyte
        messages_out;                   //  Messages consumed
    qbyte
        megabytes_in;                   //  Megabytes published
    qbyte
        megabytes_out;                  //  Megabytes consumed
    icl_shortstr_t
        product;                        //  Reported client product name
    icl_shortstr_t
        version;                        //  Reported client version
    icl_shortstr_t
        platform;                       //  Reported client platform
    icl_shortstr_t
        information;                    //  Other client information
    qbyte
        trace;                          //  Trace level, 0-3
    ipr_looseref_list_t
        *connection_queue_list;         //  List of connection_queue objects
    ipr_looseref_t
        *connection_queue_ref;          //  Current connection_queue position
</context>

<method name = "new">
    <argument name = "session" type = "amq_client_session_t *">AMQP session</argument>
    <argument name = "id" type = "int">Object ID</argument>
    self->session = session;
    self->id = id;
    self->connection_queue_list = ipr_looseref_list_new ();
</method>

<method name = "destroy">
    s_destroy_children (self);
    ipr_looseref_list_destroy (&self->connection_queue_list);
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
    amq_mgt_connection_queue_t
        *connection_queue;              //  New connection_queue instance
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
                if (streq (field_name, "address")) {
                    icl_shortstr_cpy (self->address, field_value);
                }
                else
                if (streq (field_name, "user_name")) {
                    icl_shortstr_cpy (self->user_name, field_value);
                }
                else
                if (streq (field_name, "instance")) {
                    icl_shortstr_cpy (self->instance, field_value);
                }
                else
                if (streq (field_name, "started")) {
                    icl_shortstr_cpy (self->started, field_value);
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
                if (streq (field_name, "product")) {
                    icl_shortstr_cpy (self->product, field_value);
                }
                else
                if (streq (field_name, "version")) {
                    icl_shortstr_cpy (self->version, field_value);
                }
                else
                if (streq (field_name, "platform")) {
                    icl_shortstr_cpy (self->platform, field_value);
                }
                else
                if (streq (field_name, "information")) {
                    icl_shortstr_cpy (self->information, field_value);
                }
                else
                if (streq (field_name, "trace")) {
                    self->trace = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "connection_queue")) {
                    connection_queue = amq_mgt_connection_queue_new (self->session, atoi (field_value));
                    ipr_looseref_queue (self->connection_queue_list, connection_queue);
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
    Prints the connection's contents to the console.
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
    Prints the connection's values to the console in a two-column list.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    icl_shortstr_t
        field_value;
    icl_shortstr_t
        address_fmt;
    </local>
    //
    if (self_load (self))
        return (0);

    icl_console_out (" connection = \\"%s\\" ", self->name);
    sprintf (field_value, "%d", self->pending);
    s_print_property ("Messages pending", field_value, NULL, NULL);
    ipr_net_fmt_display (address_fmt, self->address, g_opt_addr);
    s_print_property ("Client IP address:port", address_fmt, NULL, NULL);
    s_print_property ("User login name", *self->user_name? self->user_name: "(empty)", NULL, NULL);
    s_print_property ("Client instance name", *self->instance? self->instance: "(empty)", NULL, NULL);
    s_print_property ("Date, time connection started", *self->started? self->started: "(empty)", NULL, NULL);
    sprintf (field_value, "%d", self->messages_in);
    s_print_property ("Messages published", field_value, NULL, NULL);
    sprintf (field_value, "%d", self->messages_out);
    s_print_property ("Messages consumed", field_value, NULL, NULL);
    sprintf (field_value, "%d", self->megabytes_in);
    s_print_property ("Megabytes published", field_value, NULL, NULL);
    sprintf (field_value, "%d", self->megabytes_out);
    s_print_property ("Megabytes consumed", field_value, NULL, NULL);
    s_print_property ("Reported client product name", *self->product? self->product: "(empty)", NULL, NULL);
    s_print_property ("Reported client version", *self->version? self->version: "(empty)", NULL, NULL);
    s_print_property ("Reported client platform", *self->platform? self->platform: "(empty)", NULL, NULL);
    s_print_property ("Other client information", *self->information? self->information: "(empty)", NULL, NULL);
    sprintf (field_value, "%d", self->trace);
    s_print_property ("Trace level, 0-3", field_value, "trace", NULL);
    sprintf (field_value, "%d", ipr_looseref_list_count (self->connection_queue_list));
    s_print_property ("Number of connection queues", field_value, NULL, "[ls connection_queue]");
    icl_console_out (" [kill]");
    //  Record data in XML form if wanted
    if (xml_data) {
        fprintf (xml_data, "&lt;connection id = \\"%d\\""
            " name = \\"%s\\""
            " pending = \\"%d\\""
            " address = \\"%s\\""
            " user_name = \\"%s\\""
            " instance = \\"%s\\""
            " started = \\"%s\\""
            " messages_in = \\"%d\\""
            " messages_out = \\"%d\\""
            " megabytes_in = \\"%d\\""
            " megabytes_out = \\"%d\\""
            " product = \\"%s\\""
            " version = \\"%s\\""
            " platform = \\"%s\\""
            " information = \\"%s\\""
            " trace = \\"%d\\""
            "/&gt;\\n", self->id
            , self->name
            , self->pending
            , self->address
            , self->user_name
            , self->instance
            , self->started
            , self->messages_in
            , self->messages_out
            , self->megabytes_in
            , self->megabytes_out
            , self->product
            , self->version
            , self->platform
            , self->information
            , self->trace
        );
    }
</method>

<method name = "print summary" template = "function">
    <doc>
    Prints the connection to the console in a single row.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    icl_shortstr_t
        address_fmt;
    </local>
    //
    ipr_net_fmt_display (address_fmt, self->address, g_opt_addr);
    icl_console_out (" %d) connection = \\"%s\\" pending=%d address=\\"%s\\" instance=\\"%s\\" megabytes_in=%d megabytes_out=%d  ", self->id, self->name, self->pending, address_fmt, *self->instance? self->instance: "(empty)", self->megabytes_in, self->megabytes_out);
    //  Record data in XML form if wanted
    if (xml_data) {
        fprintf (xml_data, "&lt;connection id = \\"%d\\""
            " name = \\"%s\\""
            " pending = \\"%d\\""
            " address = \\"%s\\""
            " user_name = \\"%s\\""
            " instance = \\"%s\\""
            " started = \\"%s\\""
            " messages_in = \\"%d\\""
            " messages_out = \\"%d\\""
            " megabytes_in = \\"%d\\""
            " megabytes_out = \\"%d\\""
            " product = \\"%s\\""
            " version = \\"%s\\""
            " platform = \\"%s\\""
            " information = \\"%s\\""
            " trace = \\"%d\\""
            "/&gt;\\n", self->id
            , self->name
            , self->pending
            , self->address
            , self->user_name
            , self->instance
            , self->started
            , self->messages_in
            , self->messages_out
            , self->megabytes_in
            , self->megabytes_out
            , self->product
            , self->version
            , self->platform
            , self->information
            , self->trace
        );
    }
</method>

<method name = "connection_queue first" return = "connection_queue">
    <doc>
    Locate first connection_queue child of connection_queue, returns object reference
    or null.
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "connection_queue" type = "amq_mgt_connection_queue_t *">Returned connection_queue</declare>
    //
    self->connection_queue_ref = ipr_looseref_list_first (self->connection_queue_list);
    if (self->connection_queue_ref)
        connection_queue = self->connection_queue_ref->object;
    else
        connection_queue = NULL;
</method>

<method name = "connection_queue next" return = "connection_queue">
    <doc>
    Locate next connection_queue child of connection_queue, returns object reference
    or null.  If done after loading object, or after reaching end of list,
    returns first child connection_queue (again).
    </doc>
    <argument name = "self" type = "$(selftype) *">Current object</argument>
    <declare name = "connection_queue" type = "amq_mgt_connection_queue_t *">Returned connection_queue</declare>
    //
    if (self->connection_queue_ref)
        self->connection_queue_ref = ipr_looseref_list_next (&self->connection_queue_ref);
    else
        self->connection_queue_ref = ipr_looseref_list_first (self->connection_queue_list);

    if (self->connection_queue_ref)
        connection_queue = self->connection_queue_ref->object;
    else
        connection_queue = NULL;
</method>

<method name = "cmdline" template = "function">
    <doc>
    Implements a command-line interface for the connection object.
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
            s_set_property (self, command);
        else
        if (ipr_str_prefixed (command, "kill"))
            s_execute_kill (self, command);
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
static void
    s_set_property ($(selftype) *self, char *command);
static int
    s_change_level ($(selftype) *self, char *command, char *path,
        int depth, ipr_token_list_t *tokens, FILE *xml_data);
static void
    s_list_children ($(selftype) *self, char *command, FILE *xml_data);
static void
    s_top_children ($(selftype) *self, char *command, FILE *xml_data);
static void
    s_execute_kill ($(selftype) *self, char *command);
static void
    s_show_help (void);
</private>

<private name = "footer">
//  Resets / destroys child objects
static void
s_destroy_children ($(selftype) *self)
{
    amq_mgt_connection_queue_t
        *connection_queue;              //  Old connection_queue instance

    while ((connection_queue = (amq_mgt_connection_queue_t *) ipr_looseref_pop (self->connection_queue_list)))
        amq_mgt_connection_queue_destroy (&connection_queue);
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
    content = amq_cml_encode (command, "connection", object_id, NULL, method, fields);
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
                if (strneq (reply_class, "connection"))
                    icl_console_print ("E: received OK for '%s', expected 'connection'", reply_class);
                assert (streq (reply_class, "connection"));
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

static void
s_set_property ($(selftype) *self, char *command)
{
    ipr_token_list_t
        *tokens;
    ipr_token_t
        *token;
    char
        *name  = NULL,
        *value = NULL;
    ipr_xml_t
        *xml_root;                      //  Returned response tree
    asl_field_list_t
        *fields;                        //  Properties of object

    tokens = ipr_token_split (command);
    token = ipr_token_list_first (tokens);
    assert (token);
    if (streq (token->value, "set")) {
        token = ipr_token_list_next (&token);
        if (token) {
            name = token->value;
            token = ipr_token_list_next (&token);
            if (token) {
                value = token->value;
                token = ipr_token_list_next (&token);
                if (token) {
                    icl_console_out (" Data from %s onwards was ignored", token->value);
                    ipr_token_unlink (&token);
                }
            }
        }
    }
    if (name
    &&  strneq (name, "trace"))
        icl_console_out (" Not a valid property name, please check");
    else
    if (name && value) {
        fields = asl_field_list_new (NULL);
        asl_field_new_string (fields, name, value);
        xml_root = s_request_response (self, "modify", self->id, NULL, fields);
        if (xml_root) {
            icl_console_out (" OK - %s", *self->notice? self->notice: "done");
            ipr_xml_destroy (&xml_root);
        }
        asl_field_list_destroy (&fields);
    }
    else
        icl_console_out (" Usage: set propertyname newvalue");

    ipr_token_list_destroy (&tokens);
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
    amq_mgt_connection_queue_t
        *connection_queue;              //  Child connection_queue

    ipr_str_crop (ipr_str_skip (command));
    if (streq (command, ".."))
        rc = CD_UP;
    else
    if (streq (command, "/"))
        rc = CD_TOP;
    else
    if ((child_id = atoi (command))) {
        connection_queue = self_connection_queue_first (self);
        while (connection_queue) {
            if (connection_queue->id == child_id) {
                icl_shortstr_fmt (child_path, "%s/connection_queue", path);
                rc = amq_mgt_connection_queue_cmdline (connection_queue, child_path, depth + 1, tokens, xml_data);
                id_found = TRUE;
            }
            connection_queue = self_connection_queue_next (self);
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
    amq_mgt_connection_queue_t
        *connection_queue;              //  Child connection_queue

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
    if (!childname || ipr_str_prefixed ("connection_queue", childname)) {
        connection_queue = self_connection_queue_first (self);
        while (connection_queue) {
            amq_mgt_connection_queue_load (connection_queue);
            if (!pattern
            || ipr_str_matches (connection_queue->name, pattern)
            || ipr_str_matches (connection_queue->enabled, pattern)
            || ipr_str_matches (connection_queue->exchange_type, pattern)
            || ipr_str_matches (connection_queue->routing_key, pattern)
            || ipr_str_matches (connection_queue->binding_args, pattern)
            )
                amq_mgt_connection_queue_print_summary (connection_queue, xml_data);
            connection_queue = self_connection_queue_next (self);
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
    amq_mgt_connection_queue_t
        *connection_queue;              //  Child connection_queue

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
    else if (strcmp (childname, "connection_queue") == 0) {
        if (0) {}
        else if (strcmp (criterion, "consumers") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection_queue = self_connection_queue_first (self);
            nbr_tops = 0;
            while (connection_queue) {
                amq_mgt_connection_queue_load (connection_queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection_queue->consumers > top_value [item_nbr])
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
                    top_value [item_nbr] = connection_queue->consumers;
                    top_id    [item_nbr] = connection_queue->id;
                }
                connection_queue = self_connection_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection_queue = amq_mgt_connection_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_queue_load (connection_queue);
                amq_mgt_connection_queue_print_summary (connection_queue, xml_data);
                amq_mgt_connection_queue_destroy (&connection_queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "pending") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection_queue = self_connection_queue_first (self);
            nbr_tops = 0;
            while (connection_queue) {
                amq_mgt_connection_queue_load (connection_queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection_queue->pending > top_value [item_nbr])
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
                    top_value [item_nbr] = connection_queue->pending;
                    top_id    [item_nbr] = connection_queue->id;
                }
                connection_queue = self_connection_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection_queue = amq_mgt_connection_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_queue_load (connection_queue);
                amq_mgt_connection_queue_print_summary (connection_queue, xml_data);
                amq_mgt_connection_queue_destroy (&connection_queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "messages_in") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection_queue = self_connection_queue_first (self);
            nbr_tops = 0;
            while (connection_queue) {
                amq_mgt_connection_queue_load (connection_queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection_queue->messages_in > top_value [item_nbr])
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
                    top_value [item_nbr] = connection_queue->messages_in;
                    top_id    [item_nbr] = connection_queue->id;
                }
                connection_queue = self_connection_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection_queue = amq_mgt_connection_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_queue_load (connection_queue);
                amq_mgt_connection_queue_print_summary (connection_queue, xml_data);
                amq_mgt_connection_queue_destroy (&connection_queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "messages_out") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection_queue = self_connection_queue_first (self);
            nbr_tops = 0;
            while (connection_queue) {
                amq_mgt_connection_queue_load (connection_queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection_queue->messages_out > top_value [item_nbr])
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
                    top_value [item_nbr] = connection_queue->messages_out;
                    top_id    [item_nbr] = connection_queue->id;
                }
                connection_queue = self_connection_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection_queue = amq_mgt_connection_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_queue_load (connection_queue);
                amq_mgt_connection_queue_print_summary (connection_queue, xml_data);
                amq_mgt_connection_queue_destroy (&connection_queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "megabytes_in") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection_queue = self_connection_queue_first (self);
            nbr_tops = 0;
            while (connection_queue) {
                amq_mgt_connection_queue_load (connection_queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection_queue->megabytes_in > top_value [item_nbr])
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
                    top_value [item_nbr] = connection_queue->megabytes_in;
                    top_id    [item_nbr] = connection_queue->id;
                }
                connection_queue = self_connection_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection_queue = amq_mgt_connection_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_queue_load (connection_queue);
                amq_mgt_connection_queue_print_summary (connection_queue, xml_data);
                amq_mgt_connection_queue_destroy (&connection_queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "megabytes_out") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection_queue = self_connection_queue_first (self);
            nbr_tops = 0;
            while (connection_queue) {
                amq_mgt_connection_queue_load (connection_queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection_queue->megabytes_out > top_value [item_nbr])
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
                    top_value [item_nbr] = connection_queue->megabytes_out;
                    top_id    [item_nbr] = connection_queue->id;
                }
                connection_queue = self_connection_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection_queue = amq_mgt_connection_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_queue_load (connection_queue);
                amq_mgt_connection_queue_print_summary (connection_queue, xml_data);
                amq_mgt_connection_queue_destroy (&connection_queue);
            }

            icl_mem_free (top_id);
            icl_mem_free (top_value);
        }
        else if (strcmp (criterion, "dropped") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            connection_queue = self_connection_queue_first (self);
            nbr_tops = 0;
            while (connection_queue) {
                amq_mgt_connection_queue_load (connection_queue);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (connection_queue->dropped > top_value [item_nbr])
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
                    top_value [item_nbr] = connection_queue->dropped;
                    top_id    [item_nbr] = connection_queue->id;
                }
                connection_queue = self_connection_queue_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                connection_queue = amq_mgt_connection_queue_new (self->session, top_id [item_nbr]);
                amq_mgt_connection_queue_load (connection_queue);
                amq_mgt_connection_queue_print_summary (connection_queue, xml_data);
                amq_mgt_connection_queue_destroy (&connection_queue);
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

//  Execute kill method
//
static void
s_execute_kill ($(selftype) *self, char *command)
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
        xml_root = s_request_response (self, "method", self->id, "kill", fields);
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
        icl_console_out (" Usage: kill arguments, use 'help kill' for details");

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
    icl_console_out (" kill");
    icl_console_out ("     Disconnects the client application.");
}
</private>

<method name = "selftest">
</method>

</class>
