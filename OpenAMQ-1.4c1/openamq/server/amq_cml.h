/*---------------------------------------------------------------------------
    amq_cml.h - amq_cml component

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

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_AMQ_CML_SAFE
#   define INCLUDE_AMQ_CML_SAFE
#   define INCLUDE_AMQ_CML_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CML_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif

#   include "amq_server_classes.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CML_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CML_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CML_UNSAFE
#   define INCLUDE_AMQ_CML_UNSAFE
#   define INCLUDE_AMQ_CML_ACTIVE

#   include "amq_server_classes.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_cml_animating;
#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
amq_content_basic_t *
    amq_cml_encode (
char * name,                            //  Command name
char * object_class,                    //  Object class name
qbyte object_id,                        //  Object id
char * status,                          //  Status, or null
char * method,                          //  Method name, or null
asl_field_list_t * fields               //  Object fields
);

void
    amq_cml_selftest (
void);

void
    amq_cml_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CML_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CML_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CML_INLINE)
#   define INCLUDE_AMQ_CML_INLINE
#   define INCLUDE_AMQ_CML_ACTIVE

#   include "amq_server_classes.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CML_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CML_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CML_ROOT
#   endif
# endif
#endif
