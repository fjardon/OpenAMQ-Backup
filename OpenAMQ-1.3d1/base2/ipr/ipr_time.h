/*---------------------------------------------------------------------------
    ipr_time.h - ipr_time component

    Provides various date & time manipulation functions.
    Generated from ipr_time.icl by icl_gen using GSL/4.
    
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

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_IPR_TIME_SAFE
#   define INCLUDE_IPR_TIME_SAFE
#   define INCLUDE_IPR_TIME_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_IPR_TIME_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_TIME_ACTIVE
#   if defined (ICL_IMPORT_IPR_TIME_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_IPR_TIME_UNSAFE
#   define INCLUDE_IPR_TIME_UNSAFE
#   define INCLUDE_IPR_TIME_ACTIVE


#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    ipr_time_animating;
typedef enum
{
    // YYYY                     (will render to 4 characters)
    ipr_date_format_year,
    // YYYY-MM                  (will render to 7 characters)
    ipr_date_format_month,
    // YYYY-MM-DD               (will render to 10 characters)
    ipr_date_format_day,
    // YYYY-MM-DDThh:mmTZD      (will render to 22 characters)
    ipr_date_format_minute,
    // YYYY-MM-DDThh:mm:ssTZD   (will render to 25 characters)
    ipr_date_format_second,
    // YYYY-MM-DDThh:mm:ss.sTZD (will render to 26 + precision characters)
    ipr_date_format_fraction
} ipr_date_format_t;

typedef apr_time_t ipr_time_t;
#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
void
    ipr_time_iso8601 (
ipr_time_t time,                        //  Time to render
ipr_date_format_t format,               //  Format to use for rendering
byte precision,                         //  Number of decimal places for fractions of second. Only with format = ipr_date_format_fraction
Bool utc,                               //  Format time as UTC if TRUE, local time if FALSE
char* buffer                            //  Buffer to store the rendered time, must be long enough to hold it
);

long
    ipr_time_now (
void);

void
    ipr_time_selftest (
void);

void
    ipr_time_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_TIME_ACTIVE
#   if defined (ICL_IMPORT_IPR_TIME_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_IPR_TIME_INLINE)
#   define INCLUDE_IPR_TIME_INLINE
#   define INCLUDE_IPR_TIME_ACTIVE


#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TIME)   || defined (BASE_TRACE_IPR_TIME_ISO8601)   || defined (BASE_TRACE_IPR_TIME_NOW)   || defined (BASE_TRACE_IPR_TIME_SELFTEST)   || defined (BASE_TRACE_IPR_TIME_ANIMATE) )
void
    ipr_time_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_TIME_ACTIVE
#   if defined (ICL_IMPORT_IPR_TIME_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_IPR_TIME_ROOT
#   endif
# endif
#endif
