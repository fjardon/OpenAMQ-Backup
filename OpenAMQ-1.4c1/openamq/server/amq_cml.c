/*---------------------------------------------------------------------------
    amq_cml.c - amq_cml component

    The CML module provides functions to read and write CML commands.
    Generated from amq_cml.icl by icl_gen using GSL/4.
    
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
#include "amq_cml.h"                    //  Definitions for our class

//  Shorthands for class methods

#define self_encode         amq_cml_encode
#define self_selftest       amq_cml_selftest
#define self_show_animation  amq_cml_show_animation

Bool
    amq_cml_animating = TRUE;           //  Animation enabled by default
/*  -------------------------------------------------------------------------
    amq_cml_encode

    Type: Component method
    Formats a CML command using the specified information, returns a
    basic content containing the command.  If the fields argument is
    not null, the fields are included in the command.
    -------------------------------------------------------------------------
 */

amq_content_basic_t *
    amq_cml_encode (
    char * name,                        //  Command name
    char * object_class,                //  Object class name
    qbyte object_id,                    //  Object id
    char * status,                      //  Status, or null
    char * method,                      //  Method name, or null
    asl_field_list_t * fields           //  Object fields
)
{
asl_field_t
    *field;
ipr_xml_t
    *cml_item,                      //  CML item
    *cur_item,                      //  Top level object
    *sub_item,                      //  Field or class within object
    *val_item;                      //  Value of field
icl_shortstr_t
    strvalue;                       //  Stringified numeric value
char
    *xml_text;                      //  Serialised XML text
ipr_bucket_t
    *bucket;
    amq_content_basic_t *
        content;                        //  Content

//
cml_item = ipr_xml_new (NULL, "cml", NULL);
ipr_xml_attr_set (cml_item, "version", "1.0");
ipr_xml_attr_set (cml_item, "xmlns", "http://www.openamq.org/schema/cml");

cur_item = ipr_xml_new (cml_item, name, NULL);
ipr_xml_attr_set (cur_item, "class",  object_class);
ipr_xml_attr_set (cur_item, "object", icl_shortstr_fmt (strvalue, "%d", object_id));

if (status)
    ipr_xml_attr_set (cur_item, "status", status);
if (method)
    ipr_xml_attr_set (cur_item, "name", method);

if (fields) {
    field = asl_field_list_first (fields);
    while (field) {
        sub_item = ipr_xml_new (cur_item, "field", NULL);
        ipr_xml_attr_set (sub_item, "name", field->name);
        val_item = ipr_xml_new (sub_item, NULL, asl_field_string (field));
        ipr_xml_unlink (&val_item);
        ipr_xml_unlink (&sub_item);
        field = asl_field_list_next (&field);
    }
}
xml_text = ipr_xml_save_string (cml_item);
bucket = ipr_bucket_new (strlen (xml_text) + 1);
ipr_bucket_fill (bucket, xml_text, strlen (xml_text) + 1);
icl_mem_free (xml_text);

//  Create a content with our desired reply data
content = amq_content_basic_new ();
amq_content_basic_set_content_type (content, "text/xml");
amq_content_basic_record_body      (content, bucket);

ipr_bucket_unlink (&bucket);
ipr_xml_unlink  (&cur_item);
ipr_xml_destroy (&cml_item);

    return (content);
}
/*  -------------------------------------------------------------------------
    amq_cml_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_cml_selftest (
void)
{
amq_content_basic_t
    *content;

//
content = amq_cml_encode ("test-method", "myobject", 123, "ok", NULL, NULL);
amq_content_basic_unlink (&content);
}
/*  -------------------------------------------------------------------------
    amq_cml_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_cml_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_cml_animating = enabled;
}
//  Embed the version information in the resulting binary

char *EMBED__amq_cml_version_start        = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_cml_component            = "amq_cml ";
char *EMBED__amq_cml_version              = "1.0 ";
char *EMBED__amq_cml_copyright            = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_cml_filename             = "amq_cml.icl ";
char *EMBED__amq_cml_builddate            = "2010/10/06 ";
char *EMBED__amq_cml_version_end          = "VeRsIoNeNd:ipc";

