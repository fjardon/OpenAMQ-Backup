/*---------------------------------------------------------------------------
    zyre_static.c - zyre_static component

    Provides compiled resources, i.e. external files that are shipped with
    the application.
    Generated from zyre_static.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "zyre_static.h"                //  Definitions for our class

//  Shorthands for class methods

#define self_get            zyre_static_get
#define self_selftest       zyre_static_selftest
#define self_show_animation  zyre_static_show_animation

Bool
    zyre_static_animating = TRUE;       //  Animation enabled by default
typedef struct {
    qbyte size;
    byte  data [1];
} zyre_static_resource_t;
static struct {
    qbyte size;
    byte  data [648];
} res_zyre_base_cfg = {
    648,
    {
      0x3c, 0x3f, 0x78, 0x6d, 0x6c, 0x3f, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20, 
      0x3c, 0x21, 0x2d, 0x2d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
      0x20, 0x5a, 0x79, 0x72, 0x65, 0x20, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 
      0x20, 0x70, 0x72, 0x69, 0x6d, 0x61, 0x72, 0x79, 0x20, 0x63, 0x6f, 0x6e, 
      0x66, 0x69, 0x67, 0x75, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x66, 
      0x69, 0x6c, 0x65, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
      0x20, 0x2a, 0x2a, 0x20, 0x44, 0x4f, 0x20, 0x4e, 0x4f, 0x54, 0x20, 0x45, 
      0x44, 0x49, 0x54, 0x20, 0x54, 0x48, 0x49, 0x53, 0x20, 0x46, 0x49, 0x4c, 
      0x45, 0x20, 0x2a, 0x2a, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
      0x20, 0x20, 0x54, 0x6f, 0x20, 0x64, 0x65, 0x66, 0x69, 0x6e, 0x65, 0x20, 
      0x61, 0x20, 0x63, 0x75, 0x73, 0x74, 0x6f, 0x6d, 0x20, 0x63, 0x6f, 0x6e, 
      0x66, 0x69, 0x67, 0x75, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x2c, 0x20, 
      0x65, 0x73, 0x70, 0x65, 0x63, 0x69, 0x61, 0x6c, 0x6c, 0x79, 0x20, 0x66, 
      0x6f, 0x72, 0x20, 0x73, 0x65, 0x63, 0x75, 0x72, 0x69, 0x74, 0x79, 0x20, 
      0x64, 0x61, 0x74, 0x61, 0x20, 0x61, 0x6e, 0x64, 0x0a, 0x20, 0x20, 0x20, 
      0x20, 0x20, 0x20, 0x20, 0x20, 0x63, 0x6c, 0x75, 0x73, 0x74, 0x65, 0x72, 
      0x20, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x75, 0x72, 0x61, 0x74, 0x69, 
      0x6f, 0x6e, 0x2c, 0x20, 0x65, 0x64, 0x69, 0x74, 0x20, 0x22, 0x7a, 0x79, 
      0x72, 0x65, 0x2e, 0x63, 0x66, 0x67, 0x22, 0x2c, 0x20, 0x6f, 0x72, 0x20, 
      0x70, 0x61, 0x73, 0x73, 0x20, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x75, 
      0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x6f, 0x70, 0x74, 0x69, 0x6f, 
      0x6e, 0x73, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x6f, 
      0x6e, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x6f, 0x6d, 0x6d, 0x61, 0x6e, 
      0x64, 0x20, 0x6c, 0x69, 0x6e, 0x65, 0x2e, 0x0a, 0x20, 0x20, 0x20, 0x20, 
      0x2d, 0x2d, 0x3e, 0x0a, 0x3c, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x3e, 
      0x0a, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x21, 0x2d, 0x2d, 0x20, 0x54, 0x68, 
      0x65, 0x73, 0x65, 0x20, 0x61, 0x72, 0x65, 0x20, 0x74, 0x68, 0x65, 0x20, 
      0x64, 0x65, 0x66, 0x61, 0x75, 0x6c, 0x74, 0x20, 0x70, 0x61, 0x73, 0x73, 
      0x77, 0x6f, 0x72, 0x64, 0x73, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x62, 0x61, 
      0x63, 0x6b, 0x2d, 0x65, 0x6e, 0x64, 0x20, 0x41, 0x4d, 0x51, 0x50, 0x20, 
      0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x20, 
      0x2d, 0x2d, 0x3e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x73, 0x65, 0x63, 
      0x75, 0x72, 0x69, 0x74, 0x79, 0x20, 0x6e, 0x61, 0x6d, 0x65, 0x20, 0x3d, 
      0x20, 0x22, 0x70, 0x6c, 0x61, 0x69, 0x6e, 0x22, 0x3e, 0x0a, 0x20, 0x20, 
      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x75, 0x73, 0x65, 0x72, 0x20, 
      0x6e, 0x61, 0x6d, 0x65, 0x20, 0x3d, 0x20, 0x22, 0x67, 0x75, 0x65, 0x73, 
      0x74, 0x22, 0x20, 0x20, 0x20, 0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 
      0x64, 0x20, 0x3d, 0x20, 0x22, 0x67, 0x75, 0x65, 0x73, 0x74, 0x22, 0x20, 
      0x20, 0x20, 0x67, 0x72, 0x6f, 0x75, 0x70, 0x20, 0x3d, 0x20, 0x22, 0x6e, 
      0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x22, 0x20, 0x2f, 0x3e, 0x0a, 0x20, 0x20, 
      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x75, 0x73, 0x65, 0x72, 0x20, 
      0x6e, 0x61, 0x6d, 0x65, 0x20, 0x3d, 0x20, 0x22, 0x73, 0x75, 0x70, 0x65, 
      0x72, 0x22, 0x20, 0x20, 0x20, 0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 
      0x64, 0x20, 0x3d, 0x20, 0x22, 0x73, 0x75, 0x70, 0x65, 0x72, 0x22, 0x20, 
      0x20, 0x20, 0x67, 0x72, 0x6f, 0x75, 0x70, 0x20, 0x3d, 0x20, 0x22, 0x73, 
      0x75, 0x70, 0x65, 0x72, 0x22, 0x20, 0x20, 0x2f, 0x3e, 0x0a, 0x20, 0x20, 
      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x75, 0x73, 0x65, 0x72, 0x20, 
      0x6e, 0x61, 0x6d, 0x65, 0x20, 0x3d, 0x20, 0x22, 0x70, 0x65, 0x65, 0x72, 
      0x69, 0x6e, 0x67, 0x22, 0x20, 0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 
      0x64, 0x20, 0x3d, 0x20, 0x22, 0x70, 0x65, 0x65, 0x72, 0x69, 0x6e, 0x67, 
      0x22, 0x20, 0x67, 0x72, 0x6f, 0x75, 0x70, 0x20, 0x3d, 0x20, 0x22, 0x73, 
      0x75, 0x70, 0x65, 0x72, 0x22, 0x20, 0x20, 0x2f, 0x3e, 0x0a, 0x20, 0x20, 
      0x20, 0x20, 0x3c, 0x2f, 0x73, 0x65, 0x63, 0x75, 0x72, 0x69, 0x74, 0x79, 
      0x3e, 0x0a, 0x3c, 0x2f, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x3e, 0x0a
    }
};
static struct {
    char *filename;
    void *resource;
} zyre_static_table [1] = {
    { "zyre_base.cfg", &res_zyre_base_cfg }
};
/*  -------------------------------------------------------------------------
    zyre_static_get

    Type: Component method
    Returns specified resource file as a bucket of data or NULL if the
    resource file is not known.  Note that resources are limited in size
    to the maximum size of a bucket (IPR_BUCKET_MAX).
    -------------------------------------------------------------------------
 */

ipr_bucket_t *
    zyre_static_get (
    char * filename                     //  Name of resource to find
)
{
zyre_static_resource_t
    *resource;                      //  Found resource
uint
    index;                          //  Index into resource table
    ipr_bucket_t *
        bucket;                         //  Returned bucket

//
resource = NULL;
for (index = 0; index < tblsize (zyre_static_table); index++) {
    if (streq (zyre_static_table [index].filename, filename)) {
        resource = zyre_static_table [index].resource;
        break;
    }
}
if (resource) {
    bucket = ipr_bucket_new (0);
    bucket->data = resource->data;
    bucket->cur_size = resource->size;
}
else
    bucket = NULL;

    return (bucket);
}
/*  -------------------------------------------------------------------------
    zyre_static_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    zyre_static_selftest (
void)
{
ipr_bucket_t
    *bucket;

//  Check we can find zyre_base.cfg
bucket = zyre_static_get ("zyre_base.cfg");
assert (bucket);
ipr_bucket_destroy (&bucket);
}
/*  -------------------------------------------------------------------------
    zyre_static_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    zyre_static_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

zyre_static_animating = enabled;
}
//  Embed the version information in the resulting binary

char *EMBED__zyre_static_version_start    = "VeRsIoNsTaRt:ipc";
char *EMBED__zyre_static_component        = "zyre_static ";
char *EMBED__zyre_static_version          = "1.0 ";
char *EMBED__zyre_static_copyright        = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__zyre_static_filename         = "zyre_static.icl ";
char *EMBED__zyre_static_builddate        = "2010/10/06 ";
char *EMBED__zyre_static_version_end      = "VeRsIoNeNd:ipc";

