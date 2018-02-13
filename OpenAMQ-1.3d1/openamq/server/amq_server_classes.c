/*---------------------------------------------------------------------------
    amq_server_classes.c - amq_server_classes component

    Generated from amq_server_classes.icl by icl_gen using GSL/4.
    
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
#include "amq_server_classes.h"         //  Definitions for our class
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SERVER_CLASSES) )
void
amq_server_classes_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_server_classes %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_server_classes_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_server_classes_component  = "amq_server_classes ";
char *amq_server_classes_version   = "1.0 ";
char *amq_server_classes_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_server_classes_filename  = "amq_server_classes.icl ";
char *amq_server_classes_builddate  = "2010/10/06 ";
char *amq_server_classes_version_end  = "VeRsIoNeNd:ipc";

