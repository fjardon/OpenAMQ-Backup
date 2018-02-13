/*---------------------------------------------------------------------------
    amq_mgt_queue_binding.c - amq_mgt_queue_binding component

Implements the management console queue_binding object, used by applications
to manage OpenAMQ servers. Use in conjunction with the amq_mgt_console
class.
    Generated from amq_mgt_queue_binding.icl by icl_gen using GSL/4.
    
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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "amq_mgt_queue_binding.h"      //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_mgt_queue_binding_t

//  Shorthands for class methods

#define self_new            amq_mgt_queue_binding_new
#define self_annihilate     amq_mgt_queue_binding_annihilate
#define self_load           amq_mgt_queue_binding_load
#define self_print_children  amq_mgt_queue_binding_print_children
#define self_print_properties  amq_mgt_queue_binding_print_properties
#define self_print_summary  amq_mgt_queue_binding_print_summary
#define self_cmdline        amq_mgt_queue_binding_cmdline
#define self_selftest       amq_mgt_queue_binding_selftest
#define self_terminate      amq_mgt_queue_binding_terminate
#define self_show           amq_mgt_queue_binding_show
#define self_destroy        amq_mgt_queue_binding_destroy
#define self_alloc          amq_mgt_queue_binding_alloc
#define self_free           amq_mgt_queue_binding_free
#define self_cache_initialise  amq_mgt_queue_binding_cache_initialise
#define self_cache_purge    amq_mgt_queue_binding_cache_purge
#define self_cache_terminate  amq_mgt_queue_binding_cache_terminate
#define self_show_animation  amq_mgt_queue_binding_show_animation
#define self_new_in_scope   amq_mgt_queue_binding_new_in_scope

static void
    amq_mgt_queue_binding_annihilate (
amq_mgt_queue_binding_t * ( * self_p )  //  Reference to object reference
);

#define amq_mgt_queue_binding_alloc()   amq_mgt_queue_binding_alloc_ (__FILE__, __LINE__)
static amq_mgt_queue_binding_t *
    amq_mgt_queue_binding_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_mgt_queue_binding_free (
amq_mgt_queue_binding_t * self          //  Object reference
);

static void
    amq_mgt_queue_binding_cache_initialise (
void);

static void
    amq_mgt_queue_binding_cache_purge (
void);

static void
    amq_mgt_queue_binding_cache_terminate (
void);

Bool
    amq_mgt_queue_binding_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static void
    s_destroy_children (amq_mgt_queue_binding_t *self);
static ipr_xml_t *
    s_request_response (amq_mgt_queue_binding_t *self, char *request, qbyte object_id,
        char *method, asl_field_list_t *fields);
static void
    s_print_property (char *label, char *value, char *name, char *command);
static int
    s_change_level (amq_mgt_queue_binding_t *self, char *command, char *path,
        int depth, ipr_token_list_t *tokens, FILE *xml_data);
static void
    s_list_children (amq_mgt_queue_binding_t *self, char *command, FILE *xml_data);
static void
    s_top_children (amq_mgt_queue_binding_t *self, char *command, FILE *xml_data);
static void
    s_show_help (void);
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_new

    Type: Component method
    Creates and initialises a new amq_mgt_queue_binding_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_mgt_queue_binding_t *
    amq_mgt_queue_binding_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_session_t * session,     //  AMQP session
    int id                              //  Object ID
)
{
    amq_mgt_queue_binding_t *
        self = NULL;                    //  Object reference

    self = amq_mgt_queue_binding_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_MGT_QUEUE_BINDING_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_mgt_queue_binding_show_);
#endif

self->session = session;
self->id = id;
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_queue_binding_annihilate (
    amq_mgt_queue_binding_t * ( * self_p )  //  Reference to object reference
)
{

    amq_mgt_queue_binding_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

AMQ_MGT_QUEUE_BINDING_ASSERT_SANE (self);

s_destroy_children (self);

}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_load

    Type: Component method
    Accepts a amq_mgt_queue_binding_t reference and returns zero in case of success,
    1 in case of errors.
    Loads or refreshes the object from the server console. Returns 0
    if the object was refreshed, -1 if there was an error talking to
    the server.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_queue_binding_load (
    amq_mgt_queue_binding_t * self      //  Reference to object
)
{
ipr_xml_t
    *xml_root,                      //  Returned response tree
    *xml_cml,                       //  CML item
    *xml_command,                   //  CML command
    *xml_field;                     //  Field item in reply
char
    *field_name,                    //  Name of returned field
    *field_value;                   //  Value of returned field
    int
        rc = 0;                         //  Return code

AMQ_MGT_QUEUE_BINDING_ASSERT_SANE (self);

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
            if (streq (field_name, "exchange_name")) {
                icl_shortstr_cpy (self->exchange_name, field_value);
            }
            else
            if (streq (field_name, "exchange_type")) {
                icl_shortstr_cpy (self->exchange_type, field_value);
            }
            else
            if (streq (field_name, "binding_args")) {
                icl_shortstr_cpy (self->binding_args, field_value);
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_print_children

    Type: Component method
    Accepts a amq_mgt_queue_binding_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the queue_binding's contents to the console.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_queue_binding_print_children (
    amq_mgt_queue_binding_t * self,     //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
char
    command [] = "";
    int
        rc = 0;                         //  Return code

AMQ_MGT_QUEUE_BINDING_ASSERT_SANE (self);

//
if (self_load (self))
    return (0);
s_list_children (self, command, xml_data);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_print_properties

    Type: Component method
    Accepts a amq_mgt_queue_binding_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the queue_binding's values to the console in a two-column list.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_queue_binding_print_properties (
    amq_mgt_queue_binding_t * self,     //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
icl_shortstr_t
    field_value;
    int
        rc = 0;                         //  Return code

AMQ_MGT_QUEUE_BINDING_ASSERT_SANE (self);

//
if (self_load (self))
    return (0);

icl_console_out (" queue_binding = \"%s\" ", self->name);
s_print_property ("Exchange name", *self->exchange_name? self->exchange_name: "(empty)", NULL, NULL);
s_print_property ("Exchange type", *self->exchange_type? self->exchange_type: "(empty)", NULL, NULL);
s_print_property ("Binding arguments", *self->binding_args? self->binding_args: "(empty)", NULL, NULL);
s_print_property ("Exclusive binding?", self->exclusive? "yes": "no", NULL, NULL);
//  Record data in XML form if wanted
if (xml_data) {
    fprintf (xml_data, "<queue_binding id = \"%d\""
        " name = \"%s\""
        " exchange_name = \"%s\""
        " exchange_type = \"%s\""
        " binding_args = \"%s\""
        " exclusive = \"%d\""
        "/>\n", self->id
        , self->name
        , self->exchange_name
        , self->exchange_type
        , self->binding_args
        , self->exclusive
    );
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_print_summary

    Type: Component method
    Accepts a amq_mgt_queue_binding_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the queue_binding to the console in a single row.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_queue_binding_print_summary (
    amq_mgt_queue_binding_t * self,     //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
    int
        rc = 0;                         //  Return code

AMQ_MGT_QUEUE_BINDING_ASSERT_SANE (self);

//
icl_console_out (" %d) queue_binding = \"%s\" exchange_name=\"%s\" exchange_type=\"%s\"        ", self->id, self->name, *self->exchange_name? self->exchange_name: "(empty)", *self->exchange_type? self->exchange_type: "(empty)");
//  Record data in XML form if wanted
if (xml_data) {
    fprintf (xml_data, "<queue_binding id = \"%d\""
        " name = \"%s\""
        " exchange_name = \"%s\""
        " exchange_type = \"%s\""
        " binding_args = \"%s\""
        " exclusive = \"%d\""
        "/>\n", self->id
        , self->name
        , self->exchange_name
        , self->exchange_type
        , self->binding_args
        , self->exclusive
    );
}


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_cmdline

    Type: Component method
    Accepts a amq_mgt_queue_binding_t reference and returns zero in case of success,
    1 in case of errors.
    Implements a command-line interface for the queue_binding object.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_queue_binding_cmdline (
    amq_mgt_queue_binding_t * self,     //  Reference to object
    char * path,                        //  Current path
    int depth,                          //  Current depth
    ipr_token_list_t * tokens,          //  Automation, if any
    FILE * xml_data                     //  XML data capture
)
{
icl_shortstr_t
    command;
    int
        rc = 0;                         //  Return code

AMQ_MGT_QUEUE_BINDING_ASSERT_SANE (self);

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


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_queue_binding_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_queue_binding_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_queue_binding_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_mgt_queue_binding_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_mgt_queue_binding file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_destroy

    Type: Component method
    Destroys a amq_mgt_queue_binding_t object. Takes the address of a
    amq_mgt_queue_binding_t reference (a pointer to a pointer) and nullifies the
    reference after use.  Does nothing if the reference is already
    null.
    Performs an agressive destroy of an object.  This involves:
    1. Removing the object from any containers it is in.
    2. Making the object an zombie
    3. Decrementing the object's link count
    4. If the link count is zero then freeing the object.
    -------------------------------------------------------------------------
 */

void
    amq_mgt_queue_binding_destroy_ (
    amq_mgt_queue_binding_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_mgt_queue_binding_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_mgt_queue_binding_annihilate (self_p);
    amq_mgt_queue_binding_free ((amq_mgt_queue_binding_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_mgt_queue_binding_t *
    amq_mgt_queue_binding_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_mgt_queue_binding_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_mgt_queue_binding_cache_initialise ();

self = (amq_mgt_queue_binding_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_mgt_queue_binding_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_free

    Type: Component method
    Freess a amq_mgt_queue_binding_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_queue_binding_free (
    amq_mgt_queue_binding_t * self      //  Object reference
)
{


if (self) {

        memset (&self->object_tag, 0, sizeof (amq_mgt_queue_binding_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_mgt_queue_binding_t));
        self->object_tag = AMQ_MGT_QUEUE_BINDING_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_queue_binding_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_mgt_queue_binding_t));
icl_system_register (amq_mgt_queue_binding_cache_purge, amq_mgt_queue_binding_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_queue_binding_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_queue_binding_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_mgt_queue_binding_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_mgt_queue_binding_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_binding_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_queue_binding_new_in_scope_ (
    amq_mgt_queue_binding_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_session_t * session,     //  AMQP session
    int id                              //  Object ID
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_mgt_queue_binding_new_ (file,line,session,id);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_mgt_queue_binding_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Resets / destroys child objects
static void
s_destroy_children (amq_mgt_queue_binding_t *self)
{
}

//  Sends a request, returns a response content
static ipr_xml_t *
s_request_response (
    amq_mgt_queue_binding_t *self,
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
    content = amq_cml_encode (command, "queue_binding", object_id, NULL, method, fields);
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
                if (strneq (reply_class, "queue_binding"))
                    icl_console_print ("E: received OK for '%s', expected 'queue_binding'", reply_class);
                assert (streq (reply_class, "queue_binding"));
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
    amq_mgt_queue_binding_t *self,
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
s_list_children (amq_mgt_queue_binding_t *self, char *command, FILE *xml_data)
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
s_top_children (amq_mgt_queue_binding_t *self, char *command, FILE *xml_data)
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

//  Embed the version information in the resulting binary

char *EMBED__amq_mgt_queue_binding_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_mgt_queue_binding_component  = "amq_mgt_queue_binding ";
char *EMBED__amq_mgt_queue_binding_version  = "1.0 ";
char *EMBED__amq_mgt_queue_binding_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_mgt_queue_binding_filename  = "amq_mgt_queue_binding.icl ";
char *EMBED__amq_mgt_queue_binding_builddate  = "2010/10/06 ";
char *EMBED__amq_mgt_queue_binding_version_end  = "VeRsIoNeNd:ipc";

