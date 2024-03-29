/*==========================================================
 *
 *  version.h - version information for OpenAMQ Operate
 *
 *  Should be the last file included in parent source program.
 *  Generated by iMatix Boom
 *  
 *  Copyright (c) 1996-2009 iMatix Corporation
 *  All rights reserved.
 *  
 *  This file is licensed under the BSD license as follows:
 *  
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of iMatix Corporation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
 *  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *==========================================================*/

#undef  VERSION         /*  Scrap any previous definitions  */
#undef  PRODUCT
#undef  COPYRIGHT
#undef  BUILDDATE
#undef  BUILDMODEL
#define VERSION         "1.3d1"
#define PRODUCT         "OpenAMQ Operate/1.3d1"
#define COPYRIGHT       "Copyright (c) 2007-2009 iMatix Corporation"
#define BUILDDATE       ""
#ifndef SVN_REVISION
#define SVN_REVISION    "12075"
#endif
#if DEBUG == 1
#   define BUILDMODEL   "Debug release for internal use only"
#else
#   define BUILDMODEL   "Production release"
#endif
#if VERSION_EMBED
/*  Embed the version information in the resulting binary   */
char *openamq_operate_version_start = "VeRsIoNsTaRt:openamq_operate";
char *openamq_operate_version = VERSION;
char *openamq_operate_product = PRODUCT;
char *openamq_operate_copyright = COPYRIGHT;
char *openamq_operate_buildmodel = BUILDMODEL;
char *openamq_operate_svn_revision = SVN_REVISION;
char *openamq_operate_version_end = "VeRsIoNeNd:openamq_operate";
#endif
