/*---------------------------------------------------------------------------
    amq_mgt_queue.c - amq_mgt_queue component

Implements the management console queue object, used by applications
to manage OpenAMQ servers. Use in conjunction with the amq_mgt_console
class.
    Generated from amq_mgt_queue.icl by icl_gen using GSL/4.
    
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
#include "amq_mgt_queue.h"              //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_mgt_queue_t

//  Shorthands for class methods

#define self_new            amq_mgt_queue_new
#define self_annihilate     amq_mgt_queue_annihilate
#define self_load           amq_mgt_queue_load
#define self_print_children  amq_mgt_queue_print_children
#define self_print_properties  amq_mgt_queue_print_properties
#define self_print_summary  amq_mgt_queue_print_summary
#define self_queue_connection_first  amq_mgt_queue_queue_connection_first
#define self_queue_connection_next  amq_mgt_queue_queue_connection_next
#define self_queue_binding_first  amq_mgt_queue_queue_binding_first
#define self_queue_binding_next  amq_mgt_queue_queue_binding_next
#define self_cmdline        amq_mgt_queue_cmdline
#define self_selftest       amq_mgt_queue_selftest
#define self_terminate      amq_mgt_queue_terminate
#define self_show           amq_mgt_queue_show
#define self_destroy        amq_mgt_queue_destroy
#define self_alloc          amq_mgt_queue_alloc
#define self_free           amq_mgt_queue_free
#define self_cache_initialise  amq_mgt_queue_cache_initialise
#define self_cache_purge    amq_mgt_queue_cache_purge
#define self_cache_terminate  amq_mgt_queue_cache_terminate
#define self_show_animation  amq_mgt_queue_show_animation
#define self_new_in_scope   amq_mgt_queue_new_in_scope

static void
    amq_mgt_queue_annihilate (
amq_mgt_queue_t * ( * self_p )          //  Reference to object reference
);

#define amq_mgt_queue_alloc()           amq_mgt_queue_alloc_ (__FILE__, __LINE__)
static amq_mgt_queue_t *
    amq_mgt_queue_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_mgt_queue_free (
amq_mgt_queue_t * self                  //  Object reference
);

static void
    amq_mgt_queue_cache_initialise (
void);

static void
    amq_mgt_queue_cache_purge (
void);

static void
    amq_mgt_queue_cache_terminate (
void);

Bool
    amq_mgt_queue_animating = TRUE;     //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static void
    s_destroy_children (amq_mgt_queue_t *self);
static ipr_xml_t *
    s_request_response (amq_mgt_queue_t *self, char *request, qbyte object_id,
        char *method, asl_field_list_t *fields);
static void
    s_print_property (char *label, char *value, char *name, char *command);
static int
    s_change_level (amq_mgt_queue_t *self, char *command, char *path,
        int depth, ipr_token_list_t *tokens, FILE *xml_data);
static void
    s_list_children (amq_mgt_queue_t *self, char *command, FILE *xml_data);
static void
    s_top_children (amq_mgt_queue_t *self, char *command, FILE *xml_data);
static void
    s_execute_purge (amq_mgt_queue_t *self, char *command);
static void
    s_show_help (void);
/*  -------------------------------------------------------------------------
    amq_mgt_queue_new

    Type: Component method
    Creates and initialises a new amq_mgt_queue_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_mgt_queue_t *
    amq_mgt_queue_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_session_t * session,     //  AMQP session
    int id                              //  Object ID
)
{
    amq_mgt_queue_t *
        self = NULL;                    //  Object reference

    self = amq_mgt_queue_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_MGT_QUEUE_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_mgt_queue_show_);
#endif

self->session = session;
self->id = id;
self->queue_connection_list = ipr_looseref_list_new ();
self->queue_binding_list = ipr_looseref_list_new ();
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_queue_annihilate (
    amq_mgt_queue_t * ( * self_p )      //  Reference to object reference
)
{

    amq_mgt_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

AMQ_MGT_QUEUE_ASSERT_SANE (self);

s_destroy_children (self);
ipr_looseref_list_destroy (&self->queue_connection_list);
ipr_looseref_list_destroy (&self->queue_binding_list);

}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_load

    Type: Component method
    Accepts a amq_mgt_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Loads or refreshes the object from the server console. Returns 0
    if the object was refreshed, -1 if there was an error talking to
    the server.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_queue_load (
    amq_mgt_queue_t * self              //  Reference to object
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
amq_mgt_queue_connection_t
    *queue_connection;              //  New queue_connection instance
amq_mgt_queue_binding_t
    *queue_binding;                 //  New queue_binding instance
    int
        rc = 0;                         //  Return code

AMQ_MGT_QUEUE_ASSERT_SANE (self);

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


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_print_children

    Type: Component method
    Accepts a amq_mgt_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the queue's contents to the console.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_queue_print_children (
    amq_mgt_queue_t * self,             //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
char
    command [] = "";
    int
        rc = 0;                         //  Return code

AMQ_MGT_QUEUE_ASSERT_SANE (self);

//
if (self_load (self))
    return (0);
s_list_children (self, command, xml_data);


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_print_properties

    Type: Component method
    Accepts a amq_mgt_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the queue's values to the console in a two-column list.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_queue_print_properties (
    amq_mgt_queue_t * self,             //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
icl_shortstr_t
    field_value;
icl_shortstr_t
    client_fmt;
    int
        rc = 0;                         //  Return code

AMQ_MGT_QUEUE_ASSERT_SANE (self);

//
if (self_load (self))
    return (0);

icl_console_out (" queue = \"%s\" ", self->name);
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
    fprintf (xml_data, "<queue id = \"%d\""
        " name = \"%s\""
        " pending = \"%d\""
        " exclusive = \"%d\""
        " client = \"%s\""
        " exchange_name = \"%s\""
        " exchange_type = \"%s\""
        " routing_key = \"%s\""
        " binding_args = \"%s\""
        " auto_delete = \"%d\""
        " consumers = \"%d\""
        " messages_in = \"%d\""
        " messages_out = \"%d\""
        " megabytes_in = \"%d\""
        " megabytes_out = \"%d\""
        " drop_count = \"%d\""
        "/>\n", self->id
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_print_summary

    Type: Component method
    Accepts a amq_mgt_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the queue to the console in a single row.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_queue_print_summary (
    amq_mgt_queue_t * self,             //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
icl_shortstr_t
    client_fmt;
    int
        rc = 0;                         //  Return code

AMQ_MGT_QUEUE_ASSERT_SANE (self);

//
ipr_net_fmt_display (client_fmt, self->client, g_opt_addr);
icl_console_out (" %d) queue = \"%s\" pending=%d exclusive=%s client=\"%s\" exchange_name=\"%s\" exchange_type=\"%s\" routing_key=\"%s\" binding_args=\"%s\" auto_delete=%s consumers=%d messages_in=%d messages_out=%d megabytes_in=%d megabytes_out=%d              ", self->id, self->name, self->pending, self->exclusive? "yes": "no", client_fmt, *self->exchange_name? self->exchange_name: "(empty)", *self->exchange_type? self->exchange_type: "(empty)", *self->routing_key? self->routing_key: "(empty)", *self->binding_args? self->binding_args: "(empty)", self->auto_delete? "yes": "no", self->consumers, self->messages_in, self->messages_out, self->megabytes_in, self->megabytes_out);
//  Record data in XML form if wanted
if (xml_data) {
    fprintf (xml_data, "<queue id = \"%d\""
        " name = \"%s\""
        " pending = \"%d\""
        " exclusive = \"%d\""
        " client = \"%s\""
        " exchange_name = \"%s\""
        " exchange_type = \"%s\""
        " routing_key = \"%s\""
        " binding_args = \"%s\""
        " auto_delete = \"%d\""
        " consumers = \"%d\""
        " messages_in = \"%d\""
        " messages_out = \"%d\""
        " megabytes_in = \"%d\""
        " megabytes_out = \"%d\""
        " drop_count = \"%d\""
        "/>\n", self->id
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_queue_connection_first

    Type: Component method
    Locate first queue_connection child of queue_connection, returns object reference
    or null.
    -------------------------------------------------------------------------
 */

amq_mgt_queue_connection_t *
    amq_mgt_queue_queue_connection_first (
    amq_mgt_queue_t * self              //  Current object
)
{
    amq_mgt_queue_connection_t *
        queue_connection;               //  Returned queue_connection

//
self->queue_connection_ref = ipr_looseref_list_first (self->queue_connection_list);
if (self->queue_connection_ref)
    queue_connection = self->queue_connection_ref->object;
else
    queue_connection = NULL;

    return (queue_connection);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_queue_connection_next

    Type: Component method
    Locate next queue_connection child of queue_connection, returns object reference
    or null.  If done after loading object, or after reaching end of list,
    returns first child queue_connection (again).
    -------------------------------------------------------------------------
 */

amq_mgt_queue_connection_t *
    amq_mgt_queue_queue_connection_next (
    amq_mgt_queue_t * self              //  Current object
)
{
    amq_mgt_queue_connection_t *
        queue_connection;               //  Returned queue_connection

//
if (self->queue_connection_ref)
    self->queue_connection_ref = ipr_looseref_list_next (&self->queue_connection_ref);
else
    self->queue_connection_ref = ipr_looseref_list_first (self->queue_connection_list);

if (self->queue_connection_ref)
    queue_connection = self->queue_connection_ref->object;
else
    queue_connection = NULL;

    return (queue_connection);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_queue_binding_first

    Type: Component method
    Locate first queue_binding child of queue_binding, returns object reference
    or null.
    -------------------------------------------------------------------------
 */

amq_mgt_queue_binding_t *
    amq_mgt_queue_queue_binding_first (
    amq_mgt_queue_t * self              //  Current object
)
{
    amq_mgt_queue_binding_t *
        queue_binding;                  //  Returned queue_binding

//
self->queue_binding_ref = ipr_looseref_list_first (self->queue_binding_list);
if (self->queue_binding_ref)
    queue_binding = self->queue_binding_ref->object;
else
    queue_binding = NULL;

    return (queue_binding);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_queue_binding_next

    Type: Component method
    Locate next queue_binding child of queue_binding, returns object reference
    or null.  If done after loading object, or after reaching end of list,
    returns first child queue_binding (again).
    -------------------------------------------------------------------------
 */

amq_mgt_queue_binding_t *
    amq_mgt_queue_queue_binding_next (
    amq_mgt_queue_t * self              //  Current object
)
{
    amq_mgt_queue_binding_t *
        queue_binding;                  //  Returned queue_binding

//
if (self->queue_binding_ref)
    self->queue_binding_ref = ipr_looseref_list_next (&self->queue_binding_ref);
else
    self->queue_binding_ref = ipr_looseref_list_first (self->queue_binding_list);

if (self->queue_binding_ref)
    queue_binding = self->queue_binding_ref->object;
else
    queue_binding = NULL;

    return (queue_binding);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_cmdline

    Type: Component method
    Accepts a amq_mgt_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Implements a command-line interface for the queue object.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_queue_cmdline (
    amq_mgt_queue_t * self,             //  Reference to object
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

AMQ_MGT_QUEUE_ASSERT_SANE (self);

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


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_queue_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_queue_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_queue_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_mgt_queue_t
    *self;
int
    container_links;


self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_mgt_queue file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_destroy

    Type: Component method
    Destroys a amq_mgt_queue_t object. Takes the address of a
    amq_mgt_queue_t reference (a pointer to a pointer) and nullifies the
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
    amq_mgt_queue_destroy_ (
    amq_mgt_queue_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_mgt_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    amq_mgt_queue_annihilate (self_p);
    amq_mgt_queue_free ((amq_mgt_queue_t *) self);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_mgt_queue_t *
    amq_mgt_queue_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_mgt_queue_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_mgt_queue_cache_initialise ();

self = (amq_mgt_queue_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_mgt_queue_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_free

    Type: Component method
    Freess a amq_mgt_queue_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_queue_free (
    amq_mgt_queue_t * self              //  Object reference
)
{


if (self) {

        memset (&self->object_tag, 0, sizeof (amq_mgt_queue_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_mgt_queue_t));
        self->object_tag = AMQ_MGT_QUEUE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_queue_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_mgt_queue_t));
icl_system_register (amq_mgt_queue_cache_purge, amq_mgt_queue_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_queue_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_queue_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_mgt_queue_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_mgt_queue_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_mgt_queue_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_queue_new_in_scope_ (
    amq_mgt_queue_t * * self_p,         //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_session_t * session,     //  AMQP session
    int id                              //  Object ID
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_mgt_queue_new_ (file,line,session,id);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_mgt_queue_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Resets / destroys child objects
static void
s_destroy_children (amq_mgt_queue_t *self)
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
    amq_mgt_queue_t *self,
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
    amq_mgt_queue_t *self,
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
s_list_children (amq_mgt_queue_t *self, char *command, FILE *xml_data)
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
s_top_children (amq_mgt_queue_t *self, char *command, FILE *xml_data)
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
s_execute_purge (amq_mgt_queue_t *self, char *command)
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

//  Embed the version information in the resulting binary

char *EMBED__amq_mgt_queue_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_mgt_queue_component      = "amq_mgt_queue ";
char *EMBED__amq_mgt_queue_version        = "1.0 ";
char *EMBED__amq_mgt_queue_copyright      = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_mgt_queue_filename       = "amq_mgt_queue.icl ";
char *EMBED__amq_mgt_queue_builddate      = "2010/10/06 ";
char *EMBED__amq_mgt_queue_version_end    = "VeRsIoNeNd:ipc";

