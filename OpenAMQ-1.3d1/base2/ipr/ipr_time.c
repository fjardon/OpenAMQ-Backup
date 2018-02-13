/*---------------------------------------------------------------------------
    ipr_time.c - ipr_time component

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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "ipr_time.h"                   //  Definitions for our class

//  Shorthands for class methods                                               

#define self_iso8601        ipr_time_iso8601
#define self_now            ipr_time_now
#define self_selftest       ipr_time_selftest
#define self_animate        ipr_time_animate

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TIME)  ||  defined (BASE_STATS_IPR_TIME_ISO8601))
static icl_stats_t *s_ipr_time_iso8601_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TIME)  ||  defined (BASE_STATS_IPR_TIME_NOW))
static icl_stats_t *s_ipr_time_now_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TIME)  ||  defined (BASE_STATS_IPR_TIME_SELFTEST))
static icl_stats_t *s_ipr_time_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TIME)  ||  defined (BASE_STATS_IPR_TIME_ANIMATE))
static icl_stats_t *s_ipr_time_animate_stats = NULL;
#endif
Bool
    ipr_time_animating = TRUE;          //  Animation enabled by default
/*  -------------------------------------------------------------------------
    ipr_time_iso8601

    Type: Component method
    Converts a time value into an ISO8601 formatted date.
    -------------------------------------------------------------------------
 */

void
    ipr_time_iso8601 (
    ipr_time_t time,                    //  Time to render
    ipr_date_format_t format,           //  Format to use for rendering
    byte precision,                     //  Number of decimal places for fractions of second. Only with format = ipr_date_format_fraction
    Bool utc,                           //  Format time as UTC if TRUE, local time if FALSE
    char* buffer                        //  Buffer to store the rendered time, must be long enough to hold it
)
{
apr_time_exp_t
    exp;
char
    fraction [8];
char
    time_zone [8];

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TIME)  ||  defined (BASE_ANIMATE_IPR_TIME_ISO8601))
    if (ipr_time_animating)
        icl_console_print ("<ipr_time_iso8601_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" utc=\"%i\""
" buffer=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, utc, buffer);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TIME)   || defined (BASE_TRACE_IPR_TIME_ISO8601))
    icl_trace_record (NULL, ipr_time_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TIME)  ||  defined (BASE_STATS_IPR_TIME_ISO8601))
    icl_stats_inc ("ipr_time_iso8601", &s_ipr_time_iso8601_stats);
#endif

//
if (utc) {
    icl_apr_assert (apr_time_exp_gmt (&exp, time));
    sprintf (time_zone, "Z");
}
else {
    icl_apr_assert (apr_time_exp_lt (&exp, time));
    sprintf (time_zone, "%+03d:%02d",
        (int) (exp.tm_gmtoff / 3600), 
        (int) (exp.tm_gmtoff % 3600));
}

switch (format) {
    case ipr_date_format_year:
        sprintf (buffer, "%04d", (int) exp.tm_year + 1900);
        break;

    case ipr_date_format_month:
        sprintf (buffer, "%04d-%02d", (int) exp.tm_year + 1900, 
            (int) exp.tm_mon + 1);
        break;

    case ipr_date_format_day:
        sprintf (buffer, "%04d-%02d-%02d", (int) exp.tm_year + 1900,
            (int) exp.tm_mon + 1, (int) exp.tm_mday);
        break;

    case ipr_date_format_minute:
        sprintf (buffer, "%04d-%02d-%02dT%02d:%02d%s",
            (int) exp.tm_year + 1900, (int) exp.tm_mon + 1, (int) exp.tm_mday,
            (int) exp.tm_hour, (int) exp.tm_min, time_zone);
        break;

    case ipr_date_format_second:
        sprintf (buffer, "%04d-%02d-%02dT%02d:%02d:%02d%s",
            (int) exp.tm_year + 1900, (int) exp.tm_mon + 1, (int) exp.tm_mday,
            (int) exp.tm_hour, (int) exp.tm_min, (int) exp.tm_sec,
            time_zone);
        break;

    case ipr_date_format_fraction:
        sprintf (fraction, "%06d", (int) exp.tm_usec);
        fraction [precision <= 6 ? precision : 6] = 0;
        sprintf (buffer, "%04d-%02d-%02dT%02d:%02d:%02d.%s%s",
            (int) exp.tm_year + 1900, (int) exp.tm_mon + 1, (int) exp.tm_mday,
            (int) exp.tm_hour, (int) exp.tm_min, (int) exp.tm_sec,
            fraction, time_zone);
        break;

    default:
        assert (0);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TIME)   || defined (BASE_TRACE_IPR_TIME_ISO8601))
    icl_trace_record (NULL, ipr_time_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TIME)   || defined (BASE_ANIMATE_IPR_TIME_ISO8601))
    if (ipr_time_animating)
        icl_console_print ("<ipr_time_iso8601_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" utc=\"%i\""
" buffer=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, utc, buffer);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_time_now

    Type: Component method
    Returns the current local time as a HHMMSS value from 0 to 235959.
    -------------------------------------------------------------------------
 */

long
    ipr_time_now (
void)
{
apr_time_t
    apr_time;
apr_time_exp_t
    time_exp;
    long
        time_now;                       //  Time to return

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TIME)  ||  defined (BASE_ANIMATE_IPR_TIME_NOW))
    if (ipr_time_animating)
        icl_console_print ("<ipr_time_now_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TIME)   || defined (BASE_TRACE_IPR_TIME_NOW))
    icl_trace_record (NULL, ipr_time_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TIME)  ||  defined (BASE_STATS_IPR_TIME_NOW))
    icl_stats_inc ("ipr_time_now", &s_ipr_time_now_stats);
#endif

//
apr_time = apr_time_now ();
apr_time_exp_lt (&time_exp, apr_time);
time_now = time_exp.tm_hour * 10000 + time_exp.tm_min * 100 + time_exp.tm_sec;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TIME)   || defined (BASE_TRACE_IPR_TIME_NOW))
    icl_trace_record (NULL, ipr_time_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TIME)   || defined (BASE_ANIMATE_IPR_TIME_NOW))
    if (ipr_time_animating)
        icl_console_print ("<ipr_time_now_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" time_now=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, time_now);
#endif


    return (time_now);
}
/*  -------------------------------------------------------------------------
    ipr_time_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_time_selftest (
void)
{
char
    buffer [100];
apr_time_exp_t
    exp = {123456, 6, 5, 4, 3, 2, 99, 0, 0, 0, -5401};
apr_time_t
    tm;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TIME)  ||  defined (BASE_ANIMATE_IPR_TIME_SELFTEST))
    if (ipr_time_animating)
        icl_console_print ("<ipr_time_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TIME)   || defined (BASE_TRACE_IPR_TIME_SELFTEST))
    icl_trace_record (NULL, ipr_time_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TIME)  ||  defined (BASE_STATS_IPR_TIME_SELFTEST))
    icl_stats_inc ("ipr_time_selftest", &s_ipr_time_selftest_stats);
#endif

//
apr_time_exp_get (&tm, &exp);
ipr_time_iso8601 (tm, ipr_date_format_year, 0, 0, buffer);
icl_console_print ("%s", buffer);
ipr_time_iso8601 (tm, ipr_date_format_month, 0, 0, buffer);
icl_console_print ("%s", buffer);
ipr_time_iso8601 (tm, ipr_date_format_day, 0, 0, buffer);
icl_console_print ("%s", buffer);
ipr_time_iso8601 (tm, ipr_date_format_minute, 0, TRUE, buffer);
icl_console_print ("%s", buffer);
ipr_time_iso8601 (tm, ipr_date_format_minute, 0, FALSE, buffer);
icl_console_print ("%s", buffer);
ipr_time_iso8601 (tm, ipr_date_format_second, 0, TRUE, buffer);
icl_console_print ("%s", buffer);
ipr_time_iso8601 (tm, ipr_date_format_second, 0, FALSE, buffer);
icl_console_print ("%s", buffer);
ipr_time_iso8601 (tm, ipr_date_format_fraction, 2, TRUE, buffer);
icl_console_print ("%s", buffer);
ipr_time_iso8601 (tm, ipr_date_format_fraction, 2, FALSE, buffer);
icl_console_print ("%s", buffer);
ipr_time_iso8601 (tm, ipr_date_format_fraction, 6, TRUE, buffer);
icl_console_print ("%s", buffer);
ipr_time_iso8601 (tm, ipr_date_format_fraction, 6, FALSE, buffer);
icl_console_print ("%s", buffer);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TIME)   || defined (BASE_TRACE_IPR_TIME_SELFTEST))
    icl_trace_record (NULL, ipr_time_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TIME)   || defined (BASE_ANIMATE_IPR_TIME_SELFTEST))
    if (ipr_time_animating)
        icl_console_print ("<ipr_time_selftest_finish"
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
    ipr_time_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_time_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TIME)  ||  defined (BASE_ANIMATE_IPR_TIME_ANIMATE))
    if (ipr_time_animating)
        icl_console_print ("<ipr_time_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TIME)   || defined (BASE_TRACE_IPR_TIME_ANIMATE))
    icl_trace_record (NULL, ipr_time_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TIME)  ||  defined (BASE_STATS_IPR_TIME_ANIMATE))
    icl_stats_inc ("ipr_time_animate", &s_ipr_time_animate_stats);
#endif

ipr_time_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TIME)   || defined (BASE_TRACE_IPR_TIME_ANIMATE))
    icl_trace_record (NULL, ipr_time_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TIME)   || defined (BASE_ANIMATE_IPR_TIME_ANIMATE))
    if (ipr_time_animating)
        icl_console_print ("<ipr_time_animate_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TIME)   || defined (BASE_TRACE_IPR_TIME_ISO8601)   || defined (BASE_TRACE_IPR_TIME_NOW)   || defined (BASE_TRACE_IPR_TIME_SELFTEST)   || defined (BASE_TRACE_IPR_TIME_ANIMATE) )
void
ipr_time_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "iso8601"; break;
        case 2: method_name = "now"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "animate"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_time %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_time_version_start       = "VeRsIoNsTaRt:ipc";
char *ipr_time_component           = "ipr_time ";
char *ipr_time_version             = "1.0 ";
char *ipr_time_copyright           = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_time_filename            = "ipr_time.icl ";
char *ipr_time_builddate           = "2010/10/06 ";
char *ipr_time_version_end         = "VeRsIoNeNd:ipc";

