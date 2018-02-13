/*---------------------------------------------------------------------------
    amq_mgt_exchange.c - amq_mgt_exchange component

Implements the management console exchange object, used by applications
to manage OpenAMQ servers. Use in conjunction with the amq_mgt_console
class.
    Generated from amq_mgt_exchange.icl by icl_gen using GSL/4.
    
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
#include "amq_mgt_exchange.h"           //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_mgt_exchange_t

//  Shorthands for class methods                                               

#define self_new            amq_mgt_exchange_new
#define self_annihilate     amq_mgt_exchange_annihilate
#define self_load           amq_mgt_exchange_load
#define self_print_children  amq_mgt_exchange_print_children
#define self_print_properties  amq_mgt_exchange_print_properties
#define self_print_summary  amq_mgt_exchange_print_summary
#define self_binding_first  amq_mgt_exchange_binding_first
#define self_binding_next   amq_mgt_exchange_binding_next
#define self_cmdline        amq_mgt_exchange_cmdline
#define self_selftest       amq_mgt_exchange_selftest
#define self_terminate      amq_mgt_exchange_terminate
#define self_show           amq_mgt_exchange_show
#define self_destroy        amq_mgt_exchange_destroy
#define self_alloc          amq_mgt_exchange_alloc
#define self_free           amq_mgt_exchange_free
#define self_cache_initialise  amq_mgt_exchange_cache_initialise
#define self_cache_purge    amq_mgt_exchange_cache_purge
#define self_cache_terminate  amq_mgt_exchange_cache_terminate
#define self_animate        amq_mgt_exchange_animate
#define self_new_in_scope   amq_mgt_exchange_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_NEW))
static icl_stats_t *s_amq_mgt_exchange_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_DESTROY))
static icl_stats_t *s_amq_mgt_exchange_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_LOAD))
static icl_stats_t *s_amq_mgt_exchange_load_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_PRINT_CHILDREN))
static icl_stats_t *s_amq_mgt_exchange_print_children_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_PRINT_PROPERTIES))
static icl_stats_t *s_amq_mgt_exchange_print_properties_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_PRINT_SUMMARY))
static icl_stats_t *s_amq_mgt_exchange_print_summary_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_BINDING_FIRST))
static icl_stats_t *s_amq_mgt_exchange_binding_first_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_BINDING_NEXT))
static icl_stats_t *s_amq_mgt_exchange_binding_next_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_CMDLINE))
static icl_stats_t *s_amq_mgt_exchange_cmdline_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_SELFTEST))
static icl_stats_t *s_amq_mgt_exchange_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_TERMINATE))
static icl_stats_t *s_amq_mgt_exchange_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_SHOW))
static icl_stats_t *s_amq_mgt_exchange_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_DESTROY_PUBLIC))
static icl_stats_t *s_amq_mgt_exchange_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_ALLOC))
static icl_stats_t *s_amq_mgt_exchange_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_FREE))
static icl_stats_t *s_amq_mgt_exchange_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_CACHE_INITIALISE))
static icl_stats_t *s_amq_mgt_exchange_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_CACHE_PURGE))
static icl_stats_t *s_amq_mgt_exchange_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_CACHE_TERMINATE))
static icl_stats_t *s_amq_mgt_exchange_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_ANIMATE))
static icl_stats_t *s_amq_mgt_exchange_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_NEW_IN_SCOPE))
static icl_stats_t *s_amq_mgt_exchange_new_in_scope_stats = NULL;
#endif
static void
    amq_mgt_exchange_annihilate (
amq_mgt_exchange_t * ( * self_p )       //  Reference to object reference
);

#define amq_mgt_exchange_alloc()        amq_mgt_exchange_alloc_ (__FILE__, __LINE__)
static amq_mgt_exchange_t *
    amq_mgt_exchange_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_mgt_exchange_free (
amq_mgt_exchange_t * self               //  Object reference
);

static void
    amq_mgt_exchange_cache_initialise (
void);

static void
    amq_mgt_exchange_cache_purge (
void);

static void
    amq_mgt_exchange_cache_terminate (
void);

Bool
    amq_mgt_exchange_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static void
    s_destroy_children (amq_mgt_exchange_t *self);
static ipr_xml_t *
    s_request_response (amq_mgt_exchange_t *self, char *request, qbyte object_id,
        char *method, asl_field_list_t *fields);
static void
    s_print_property (char *label, char *value, char *name, char *command);
static int
    s_change_level (amq_mgt_exchange_t *self, char *command, char *path,
        int depth, ipr_token_list_t *tokens, FILE *xml_data);
static void
    s_list_children (amq_mgt_exchange_t *self, char *command, FILE *xml_data);
static void
    s_top_children (amq_mgt_exchange_t *self, char *command, FILE *xml_data);
static void
    s_show_help (void);
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_new

    Type: Component method
    Creates and initialises a new amq_mgt_exchange_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_mgt_exchange_t *
    amq_mgt_exchange_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_session_t * session,     //  AMQP session
    int id                              //  Object ID
)
{
    amq_mgt_exchange_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_NEW))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" session=\"%pp\""
" id=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, session, id);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_NEW))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_NEW))
    icl_stats_inc ("amq_mgt_exchange_new", &s_amq_mgt_exchange_new_stats);
#endif

    self = amq_mgt_exchange_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_MGT_EXCHANGE_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_mgt_exchange_show_);
#endif

self->session = session;
self->id = id;
self->binding_list = ipr_looseref_list_new ();
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_NEW))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_NEW))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" session=\"%pp\""
" id=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, session, id, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_exchange_annihilate (
    amq_mgt_exchange_t * ( * self_p )   //  Reference to object reference
)
{

    amq_mgt_exchange_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_DESTROY))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_DESTROY))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_DESTROY))
    icl_stats_inc ("amq_mgt_exchange_annihilate", &s_amq_mgt_exchange_annihilate_stats);
#endif

AMQ_MGT_EXCHANGE_ASSERT_SANE (self);

s_destroy_children (self);
ipr_looseref_list_destroy (&self->binding_list);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_DESTROY))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_DESTROY))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_load

    Type: Component method
    Accepts a amq_mgt_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Loads or refreshes the object from the server console. Returns 0
    if the object was refreshed, -1 if there was an error talking to
    the server.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_exchange_load (
    amq_mgt_exchange_t * self           //  Reference to object
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
amq_mgt_binding_t
    *binding;                       //  New binding instance
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_LOAD))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_load_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_LOAD))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_LOAD))
    icl_stats_inc ("amq_mgt_exchange_load", &s_amq_mgt_exchange_load_stats);
#endif

AMQ_MGT_EXCHANGE_ASSERT_SANE (self);

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
            if (streq (field_name, "type")) {
                icl_shortstr_cpy (self->type, field_value);
            }
            else
            if (streq (field_name, "bindings")) {
                self->bindings = (qbyte) atoi (field_value);
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
            if (streq (field_name, "binding")) {
                binding = amq_mgt_binding_new (self->session, atoi (field_value));
                ipr_looseref_queue (self->binding_list, binding);
            }
            icl_mem_free (field_value);
        }
        xml_field = ipr_xml_next_sibling (&xml_field);
    }
    ipr_xml_destroy (&xml_root);
}
else
    rc = -1;                        //  Object no longer available

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_LOAD))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_LOAD))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_load_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_print_children

    Type: Component method
    Accepts a amq_mgt_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the exchange's contents to the console.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_exchange_print_children (
    amq_mgt_exchange_t * self,          //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
char
    command [] = "";
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_PRINT_CHILDREN))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_print_children_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" xml_data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, xml_data);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_PRINT_CHILDREN))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_PRINT_CHILDREN))
    icl_stats_inc ("amq_mgt_exchange_print_children", &s_amq_mgt_exchange_print_children_stats);
#endif

AMQ_MGT_EXCHANGE_ASSERT_SANE (self);

//
if (self_load (self))
    return (0);
s_list_children (self, command, xml_data);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_PRINT_CHILDREN))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_PRINT_CHILDREN))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_print_children_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" xml_data=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, xml_data, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_print_properties

    Type: Component method
    Accepts a amq_mgt_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the exchange's values to the console in a two-column list.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_exchange_print_properties (
    amq_mgt_exchange_t * self,          //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
icl_shortstr_t
    field_value;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_PRINT_PROPERTIES))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_print_properties_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" xml_data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, xml_data);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_PRINT_PROPERTIES))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_PRINT_PROPERTIES))
    icl_stats_inc ("amq_mgt_exchange_print_properties", &s_amq_mgt_exchange_print_properties_stats);
#endif

AMQ_MGT_EXCHANGE_ASSERT_SANE (self);

//
if (self_load (self))
    return (0);

icl_console_out (" exchange = \"%s\" ", self->name);
s_print_property ("Exchange", *self->type? self->type: "(empty)", NULL, NULL);
sprintf (field_value, "%d", self->bindings);
s_print_property ("Number of bindings", field_value, NULL, NULL);
sprintf (field_value, "%d", self->messages_in);
s_print_property ("Messages published", field_value, NULL, NULL);
sprintf (field_value, "%d", self->messages_out);
s_print_property ("Messages routed", field_value, NULL, NULL);
sprintf (field_value, "%d", self->megabytes_in);
s_print_property ("Megabytes published", field_value, NULL, NULL);
sprintf (field_value, "%d", self->megabytes_out);
s_print_property ("Megabytes routed", field_value, NULL, NULL);
sprintf (field_value, "%d", ipr_looseref_list_count (self->binding_list));
s_print_property ("Number of bindings", field_value, NULL, "[ls binding]");
//  Record data in XML form if wanted
if (xml_data) {
    fprintf (xml_data, "<exchange id = \"%d\""
        " name = \"%s\""
        " type = \"%s\""
        " bindings = \"%d\""
        " messages_in = \"%d\""
        " messages_out = \"%d\""
        " megabytes_in = \"%d\""
        " megabytes_out = \"%d\""
        "/>\n", self->id
        , self->name
        , self->type
        , self->bindings
        , self->messages_in
        , self->messages_out
        , self->megabytes_in
        , self->megabytes_out
    );
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_PRINT_PROPERTIES))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_PRINT_PROPERTIES))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_print_properties_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" xml_data=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, xml_data, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_print_summary

    Type: Component method
    Accepts a amq_mgt_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the exchange to the console in a single row.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_exchange_print_summary (
    amq_mgt_exchange_t * self,          //  Reference to object
    FILE * xml_data                     //  XML data capture
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_PRINT_SUMMARY))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_print_summary_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" xml_data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, xml_data);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_PRINT_SUMMARY))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_PRINT_SUMMARY))
    icl_stats_inc ("amq_mgt_exchange_print_summary", &s_amq_mgt_exchange_print_summary_stats);
#endif

AMQ_MGT_EXCHANGE_ASSERT_SANE (self);

//
icl_console_out (" %d) exchange = \"%s\" bindings=%d megabytes_in=%d megabytes_out=%d    ", self->id, self->name, self->bindings, self->megabytes_in, self->megabytes_out);
//  Record data in XML form if wanted
if (xml_data) {
    fprintf (xml_data, "<exchange id = \"%d\""
        " name = \"%s\""
        " type = \"%s\""
        " bindings = \"%d\""
        " messages_in = \"%d\""
        " messages_out = \"%d\""
        " megabytes_in = \"%d\""
        " megabytes_out = \"%d\""
        "/>\n", self->id
        , self->name
        , self->type
        , self->bindings
        , self->messages_in
        , self->messages_out
        , self->megabytes_in
        , self->megabytes_out
    );
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_PRINT_SUMMARY))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_PRINT_SUMMARY))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_print_summary_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" xml_data=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, xml_data, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_binding_first

    Type: Component method
    Locate first binding child of binding, returns object reference
    or null.
    -------------------------------------------------------------------------
 */

amq_mgt_binding_t *
    amq_mgt_exchange_binding_first (
    amq_mgt_exchange_t * self           //  Current object
)
{
    amq_mgt_binding_t *
        binding;                        //  Returned binding

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_BINDING_FIRST))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_binding_first_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_BINDING_FIRST))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_BINDING_FIRST))
    icl_stats_inc ("amq_mgt_exchange_binding_first", &s_amq_mgt_exchange_binding_first_stats);
#endif

//
self->binding_ref = ipr_looseref_list_first (self->binding_list);
if (self->binding_ref)
    binding = self->binding_ref->object;
else
    binding = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_BINDING_FIRST))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_BINDING_FIRST))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_binding_first_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" binding=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, binding);
#endif


    return (binding);
}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_binding_next

    Type: Component method
    Locate next binding child of binding, returns object reference
    or null.  If done after loading object, or after reaching end of list,
    returns first child binding (again).
    -------------------------------------------------------------------------
 */

amq_mgt_binding_t *
    amq_mgt_exchange_binding_next (
    amq_mgt_exchange_t * self           //  Current object
)
{
    amq_mgt_binding_t *
        binding;                        //  Returned binding

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_BINDING_NEXT))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_binding_next_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_BINDING_NEXT))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_BINDING_NEXT))
    icl_stats_inc ("amq_mgt_exchange_binding_next", &s_amq_mgt_exchange_binding_next_stats);
#endif

//
if (self->binding_ref)
    self->binding_ref = ipr_looseref_list_next (&self->binding_ref);
else
    self->binding_ref = ipr_looseref_list_first (self->binding_list);

if (self->binding_ref)
    binding = self->binding_ref->object;
else
    binding = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_BINDING_NEXT))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_BINDING_NEXT))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_binding_next_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" binding=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, binding);
#endif


    return (binding);
}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_cmdline

    Type: Component method
    Accepts a amq_mgt_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Implements a command-line interface for the exchange object.
    -------------------------------------------------------------------------
 */

int
    amq_mgt_exchange_cmdline (
    amq_mgt_exchange_t * self,          //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_CMDLINE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_cmdline_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" path=\"%s\""
" depth=\"%i\""
" tokens=\"%pp\""
" xml_data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, path, depth, tokens, xml_data);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CMDLINE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_CMDLINE))
    icl_stats_inc ("amq_mgt_exchange_cmdline", &s_amq_mgt_exchange_cmdline_stats);
#endif

AMQ_MGT_EXCHANGE_ASSERT_SANE (self);

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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CMDLINE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_CMDLINE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_cmdline_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" path=\"%s\""
" depth=\"%i\""
" tokens=\"%pp\""
" xml_data=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, path, depth, tokens, xml_data, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_exchange_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_SELFTEST))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_SELFTEST))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_SELFTEST))
    icl_stats_inc ("amq_mgt_exchange_selftest", &s_amq_mgt_exchange_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_SELFTEST))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_SELFTEST))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_selftest_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_exchange_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_TERMINATE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_TERMINATE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_TERMINATE))
    icl_stats_inc ("amq_mgt_exchange_terminate", &s_amq_mgt_exchange_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_TERMINATE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_TERMINATE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_exchange_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
amq_mgt_exchange_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_SHOW))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_show_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_SHOW))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_SHOW))
    icl_stats_inc ("amq_mgt_exchange_show", &s_amq_mgt_exchange_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <amq_mgt_exchange file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_SHOW))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_SHOW))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_show_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_destroy

    Type: Component method
    Destroys a amq_mgt_exchange_t object. Takes the address of a
    amq_mgt_exchange_t reference (a pointer to a pointer) and nullifies the
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
    amq_mgt_exchange_destroy_ (
    amq_mgt_exchange_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_mgt_exchange_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_DESTROY_PUBLIC))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_DESTROY_PUBLIC))
    icl_stats_inc ("amq_mgt_exchange_destroy", &s_amq_mgt_exchange_destroy_stats);
#endif

if (self) {
    amq_mgt_exchange_annihilate (self_p);
    amq_mgt_exchange_free ((amq_mgt_exchange_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_DESTROY_PUBLIC))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_mgt_exchange_t *
    amq_mgt_exchange_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_mgt_exchange_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_ALLOC))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_ALLOC))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_ALLOC))
    icl_stats_inc ("amq_mgt_exchange_alloc", &s_amq_mgt_exchange_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_mgt_exchange_cache_initialise ();

self = (amq_mgt_exchange_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_mgt_exchange_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_ALLOC))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_ALLOC))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_free

    Type: Component method
    Freess a amq_mgt_exchange_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_exchange_free (
    amq_mgt_exchange_t * self           //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_FREE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_FREE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_FREE))
    icl_stats_inc ("amq_mgt_exchange_free", &s_amq_mgt_exchange_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (amq_mgt_exchange_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_mgt_exchange_t));
        self->object_tag = AMQ_MGT_EXCHANGE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_FREE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_FREE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_exchange_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_CACHE_INITIALISE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_CACHE_INITIALISE))
    icl_stats_inc ("amq_mgt_exchange_cache_initialise", &s_amq_mgt_exchange_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_mgt_exchange_t));
icl_system_register (amq_mgt_exchange_cache_purge, amq_mgt_exchange_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_CACHE_INITIALISE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_cache_initialise_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_exchange_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_CACHE_PURGE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CACHE_PURGE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_CACHE_PURGE))
    icl_stats_inc ("amq_mgt_exchange_cache_purge", &s_amq_mgt_exchange_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CACHE_PURGE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_CACHE_PURGE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_cache_purge_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_mgt_exchange_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_CACHE_TERMINATE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_CACHE_TERMINATE))
    icl_stats_inc ("amq_mgt_exchange_cache_terminate", &s_amq_mgt_exchange_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_CACHE_TERMINATE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_cache_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_mgt_exchange_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_ANIMATE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_animate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_ANIMATE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_ANIMATE))
    icl_stats_inc ("amq_mgt_exchange_animate", &s_amq_mgt_exchange_animate_stats);
#endif

amq_mgt_exchange_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_ANIMATE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_ANIMATE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_animate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

}
/*  -------------------------------------------------------------------------
    amq_mgt_exchange_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_mgt_exchange_new_in_scope_ (
    amq_mgt_exchange_t * * self_p,      //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_session_t * session,     //  AMQP session
    int id                              //  Object ID
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)  ||  defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_NEW_IN_SCOPE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" session=\"%pp\""
" id=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, session, id);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE)  ||  defined (BASE_STATS_AMQ_MGT_EXCHANGE_NEW_IN_SCOPE))
    icl_stats_inc ("amq_mgt_exchange_new_in_scope", &s_amq_mgt_exchange_new_in_scope_stats);
#endif

*self_p = amq_mgt_exchange_new_ (file,line,session,id);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_mgt_exchange_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_mgt_exchange_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE)   || defined (BASE_ANIMATE_AMQ_MGT_EXCHANGE_NEW_IN_SCOPE))
    if (amq_mgt_exchange_animating)
        icl_console_print ("<amq_mgt_exchange_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" session=\"%pp\""
" id=\"%i\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, session, id, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_NEW)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_DESTROY)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_LOAD)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_PRINT_CHILDREN)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_PRINT_PROPERTIES)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_PRINT_SUMMARY)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_BINDING_FIRST)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_BINDING_NEXT)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CMDLINE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_SELFTEST)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_TERMINATE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_SHOW)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_ALLOC)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_FREE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_ANIMATE)   || defined (BASE_TRACE_AMQ_MGT_EXCHANGE_NEW_IN_SCOPE) )
void
amq_mgt_exchange_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "load"; break;
        case 4: method_name = "print children"; break;
        case 5: method_name = "print properties"; break;
        case 6: method_name = "print summary"; break;
        case 7: method_name = "binding first"; break;
        case 8: method_name = "binding next"; break;
        case 9: method_name = "cmdline"; break;
        case 10: method_name = "selftest"; break;
        case 11: method_name = "terminate"; break;
        case 12: method_name = "show"; break;
        case 13: method_name = "destroy public"; break;
        case 14: method_name = "alloc"; break;
        case 15: method_name = "free"; break;
        case 16: method_name = "cache initialise"; break;
        case 17: method_name = "cache purge"; break;
        case 18: method_name = "cache terminate"; break;
        case 19: method_name = "animate"; break;
        case 20: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_mgt_exchange %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Resets / destroys child objects
static void
s_destroy_children (amq_mgt_exchange_t *self)
{
    amq_mgt_binding_t
        *binding;                       //  Old binding instance

    while ((binding = (amq_mgt_binding_t *) ipr_looseref_pop (self->binding_list)))
        amq_mgt_binding_destroy (&binding);
}

//  Sends a request, returns a response content
static ipr_xml_t *
s_request_response (
    amq_mgt_exchange_t *self,
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
    content = amq_cml_encode (command, "exchange", object_id, NULL, method, fields);
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
                if (strneq (reply_class, "exchange"))
                    icl_console_print ("E: received OK for '%s', expected 'exchange'", reply_class);
                assert (streq (reply_class, "exchange"));
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
    amq_mgt_exchange_t *self,
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
    amq_mgt_binding_t
        *binding;                       //  Child binding

    ipr_str_crop (ipr_str_skip (command));
    if (streq (command, ".."))
        rc = CD_UP;
    else
    if (streq (command, "/"))
        rc = CD_TOP;
    else
    if ((child_id = atoi (command))) {
        binding = self_binding_first (self);
        while (binding) {
            if (binding->id == child_id) {
                icl_shortstr_fmt (child_path, "%s/binding", path);
                rc = amq_mgt_binding_cmdline (binding, child_path, depth + 1, tokens, xml_data);
                id_found = TRUE;
            }
            binding = self_binding_next (self);
        }
        if (!id_found)
            icl_console_out (" No item number %d in scope", child_id);
    }
    else
        icl_console_out (" Invalid command, use 'cd [number]'");

    return (rc);
}

static void
s_list_children (amq_mgt_exchange_t *self, char *command, FILE *xml_data)
{
    ipr_token_list_t
        *tokens;
    ipr_token_t
        *token;
    char
        *childname = NULL,
        *pattern = NULL;
    amq_mgt_binding_t
        *binding;                       //  Child binding

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
    if (!childname || ipr_str_prefixed ("binding", childname)) {
        binding = self_binding_first (self);
        while (binding) {
            amq_mgt_binding_load (binding);
            if (!pattern
            || ipr_str_matches (binding->name, pattern)
            || ipr_str_matches (binding->arguments, pattern)
            )
                amq_mgt_binding_print_summary (binding, xml_data);
            binding = self_binding_next (self);
        }
    }
    ipr_token_list_destroy (&tokens);
}

static void
s_top_children (amq_mgt_exchange_t *self, char *command, FILE *xml_data)
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
    amq_mgt_binding_t
        *binding;                       //  Child binding

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
    else if (strcmp (childname, "binding") == 0) {
        if (0) {}
        else if (strcmp (criterion, "queues") == 0) {

            top_value = icl_mem_alloc (top_count * sizeof (size_t));
            assert (top_value);
            top_id = icl_mem_alloc (top_count * sizeof (int));
            assert (top_value);

            binding = self_binding_first (self);
            nbr_tops = 0;
            while (binding) {
                amq_mgt_binding_load (binding);
                //  Find slot for item, if any
                for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++)
                    if (binding->queues > top_value [item_nbr])
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
                    top_value [item_nbr] = binding->queues;
                    top_id    [item_nbr] = binding->id;
                }
                binding = self_binding_next (self);
            }
            for (item_nbr = 0; item_nbr < nbr_tops; item_nbr++) {
                binding = amq_mgt_binding_new (self->session, top_id [item_nbr]);
                amq_mgt_binding_load (binding);
                amq_mgt_binding_print_summary (binding, xml_data);
                amq_mgt_binding_destroy (&binding);
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

char *amq_mgt_exchange_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_mgt_exchange_component   = "amq_mgt_exchange ";
char *amq_mgt_exchange_version     = "1.0 ";
char *amq_mgt_exchange_copyright   = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_mgt_exchange_filename    = "amq_mgt_exchange.icl ";
char *amq_mgt_exchange_builddate   = "2010/10/06 ";
char *amq_mgt_exchange_version_end  = "VeRsIoNeNd:ipc";

