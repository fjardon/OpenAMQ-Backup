/*---------------------------------------------------------------------------
    amq_resource.h - amq_resource component

    This module provides functions to work with RestMS resources.
    Generated from amq_resource.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_RESOURCE_SAFE
#   define INCLUDE_AMQ_RESOURCE_SAFE
#   define INCLUDE_AMQ_RESOURCE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_RESOURCE_ROOT
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
#   undef INCLUDE_AMQ_RESOURCE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_RESOURCE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_RESOURCE_UNSAFE
#   define INCLUDE_AMQ_RESOURCE_UNSAFE
#   define INCLUDE_AMQ_RESOURCE_ACTIVE

#   include "amq_server_classes.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_resource_animating;
#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
void
    amq_resource_pipe_create (
char * pipe_type,                       //  Not documented
char * pipe_name,                       //  Not documented
amq_server_channel_t * channel          //  Not documented
);

void
    amq_resource_pipe_delete (
char * pipe_name                        //  Not documented
);

void
    amq_resource_feed_create (
char * feed_type,                       //  Not documented
char * feed_name                        //  Not documented
);

void
    amq_resource_feed_delete (
char * feed_name                        //  Not documented
);

void
    amq_resource_join_create (
char * pipe_name,                       //  Not documented
char * feed_name,                       //  Not documented
char * address,                         //  Not documented
amq_server_channel_t * channel          //  Not documented
);

void
    amq_resource_join_delete (
char * pipe_name,                       //  Not documented
char * feed_name,                       //  Not documented
char * address,                         //  Not documented
amq_server_channel_t * channel          //  Not documented
);

void
    amq_resource_selftest (
void);

void
    amq_resource_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_RESOURCE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_RESOURCE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_RESOURCE_INLINE)
#   define INCLUDE_AMQ_RESOURCE_INLINE
#   define INCLUDE_AMQ_RESOURCE_ACTIVE

#   include "amq_server_classes.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_RESOURCE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_RESOURCE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_RESOURCE_ROOT
#   endif
# endif
#endif
