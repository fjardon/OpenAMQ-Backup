<?xml?>
<class
    name      = "amq_mgt_binding"
    comment   = "Management console binding class"
    version   = "1.0"
    script    = "icl_gen"
    >
<doc>
Implements the management console binding object, used by applications
to manage OpenAMQ servers. Use in conjunction with the amq_mgt_console
class.
</doc>

<inherit class = "icl_object">
    <option name = "alloc" value = "cache" />
</inherit>

<import class = "amq_mgt_console" />

<context>
    amq_client_session_t
        *session;                       //  AMQP session
    int
        id;                             //  Object ID
    icl_shortstr_t
        notice;                         //  Message from server
    icl_shortstr_t
        name;                           //  Routing key
    icl_shortstr_t
        arguments;                      //  Binding arguments
    qbyte
        queues;                         //  Number of queues
    Bool
        exclusive;                      //  Exclusive binding?
</context>

<method name = "new">
    <argument name = "session" type = "amq_client_session_t *">AMQP session</argument>
    <argument name = "id" type = "int">Object ID</argument>
    self->session = session;
    self->id = id;
</method>

<method name = "destroy">
    s_destroy_children (self);
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
                if (streq (field_name, "arguments")) {
                    icl_shortstr_cpy (self->arguments, field_value);
                }
                else
                if (streq (field_name, "queues")) {
                    self->queues = (qbyte) atoi (field_value);
                }
                else
                if (streq (field_name, "exclusive")) {
                    self->exclusive = (qbyte) atoi (field_value);
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
    Prints the binding's contents to the console.
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
    Prints the binding's values to the console in a two-column list.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    icl_shortstr_t
        field_value;
    </local>
    //
    if (self_load (self))
        return (0);

    icl_console_out (" binding = \\"%s\\" ", self->name);
    s_print_property ("Binding arguments", *self->arguments? self->arguments: "(empty)", NULL, NULL);
    sprintf (field_value, "%d", self->queues);
    s_print_property ("Number of queues", field_value, NULL, NULL);
    s_print_property ("Exclusive binding?", self->exclusive? "yes": "no", NULL, NULL);
    //  Record data in XML form if wanted
    if (xml_data) {
        fprintf (xml_data, "&lt;binding id = \\"%d\\""
            " name = \\"%s\\""
            " arguments = \\"%s\\""
            " queues = \\"%d\\""
            " exclusive = \\"%d\\""
            "/&gt;\\n", self->id
            , self->name
            , self->arguments
            , self->queues
            , self->exclusive
        );
    }
</method>

<method name = "print summary" template = "function">
    <doc>
    Prints the binding to the console in a single row.
    </doc>
    <argument name = "xml_data" type = "FILE *">XML data capture</argument>
    <local>
    </local>
    //
    icl_console_out (" %d) binding = \\"%s\\" arguments=\\"%s\\" queues=%d  ", self->id, self->name, *self->arguments? self->arguments: "(empty)", self->queues);
    //  Record data in XML form if wanted
    if (xml_data) {
        fprintf (xml_data, "&lt;binding id = \\"%d\\""
            " name = \\"%s\\""
            " arguments = \\"%s\\""
            " queues = \\"%d\\""
            " exclusive = \\"%d\\""
            "/&gt;\\n", self->id
            , self->name
            , self->arguments
            , self->queues
            , self->exclusive
        );
    }
</method>

<method name = "cmdline" template = "function">
    <doc>
    Implements a command-line interface for the binding object.
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
    s_show_help (void);
</private>

<private name = "footer">
//  Resets / destroys child objects
static void
s_destroy_children ($(selftype) *self)
{
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
    content = amq_cml_encode (command, "binding", object_id, NULL, method, fields);
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
                if (strneq (reply_class, "binding"))
                    icl_console_print ("E: received OK for '%s', expected 'binding'", reply_class);
                assert (streq (reply_class, "binding"));
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

    ipr_str_crop (ipr_str_skip (command));
    if (streq (command, ".."))
        rc = CD_UP;
    else
    if (streq (command, "/"))
        rc = CD_TOP;
    else
    if ((child_id = atoi (command))) {
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
    else {
        icl_console_out ("Top list of '%s' objects not supported", childname);
        ipr_token_list_destroy (&tokens);
        return;
    }
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
}
</private>

<method name = "selftest">
</method>

</class>
