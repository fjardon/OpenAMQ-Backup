/*---------------------------------------------------------------------------
    amq_server_resource.h - amq_server_resource component

    Provides compiled resources, i.e. external files that are shipped with
    the application.
    Generated from amq_server_resource.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_SERVER_RESOURCE_SAFE
#   define INCLUDE_AMQ_SERVER_RESOURCE_SAFE
#   define INCLUDE_AMQ_SERVER_RESOURCE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_SERVER_RESOURCE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif

#   include "ipr_bucket.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_RESOURCE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_RESOURCE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_SERVER_RESOURCE_UNSAFE
#   define INCLUDE_AMQ_SERVER_RESOURCE_UNSAFE
#   define INCLUDE_AMQ_SERVER_RESOURCE_ACTIVE

#   include "ipr_bucket.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_server_resource_animating;
#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
ipr_bucket_t *
    amq_server_resource_get (
char * filename                         //  Name of resource to find
);

void
    amq_server_resource_selftest (
void);

void
    amq_server_resource_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_RESOURCE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_RESOURCE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_SERVER_RESOURCE_INLINE)
#   define INCLUDE_AMQ_SERVER_RESOURCE_INLINE
#   define INCLUDE_AMQ_SERVER_RESOURCE_ACTIVE

#   include "ipr_bucket.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_RESOURCE)   || defined (BASE_TRACE_AMQ_SERVER_RESOURCE_GET)   || defined (BASE_TRACE_AMQ_SERVER_RESOURCE_SELFTEST)   || defined (BASE_TRACE_AMQ_SERVER_RESOURCE_ANIMATE) )
void
    amq_server_resource_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_RESOURCE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_RESOURCE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_SERVER_RESOURCE_ROOT
#   endif
# endif
#endif
