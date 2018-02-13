<?xml?>
<!--
    Copyright (c) 1996-2009 iMatix Corporation

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
 -->
<class
    name      = "ipr_time"
    comment   = "Time manipulation"
    version   = "1.0"
    script    = "icl_gen"
    >
<doc>
    Provides various date & time manipulation functions.
</doc>

<inherit class = "icl_base" />

<public>
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
</public>

<method name = "iso8601">
    <doc>
    Converts a time value into an ISO8601 formatted date.
    </doc>
    <argument name = "time" type = "ipr_time_t" pass = "in">
    Time to render
    </argument>
    <argument name = "format" type = "ipr_date_format_t" pass = "in">
    Format to use for rendering
    </argument>
    <argument name = "precision" type = "byte" pass = "in">
    Number of decimal places for fractions of second. Only with format = ipr_date_format_fraction
    </argument>
    <argument name = "utc" type = "Bool" pass = "in">
    Format time as UTC if TRUE, local time if FALSE
    </argument>
    <argument name = "buffer" type = "char*" pass = "out">
    Buffer to store the rendered time, must be long enough to hold it
    </argument>
    <local>
    apr_time_exp_t
        exp;
    char
        fraction [8];
    char
        time_zone [8];
    </local>
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
</method>

<method name = "now" return = "time_now">
    <doc>
    Returns the current local time as a HHMMSS value from 0 to 235959.
    </doc>
    <declare name = "time_now" type = "long">Time to return</declare>
    <local>
    apr_time_t
        apr_time;
    apr_time_exp_t
        time_exp;
    </local>
    //
    apr_time = apr_time_now ();
    apr_time_exp_lt (&time_exp, apr_time);
    time_now = time_exp.tm_hour * 10000 + time_exp.tm_min * 100 + time_exp.tm_sec;
</method>

<method name = "selftest">
    <local>
    char
        buffer [100];
    apr_time_exp_t
        exp = {123456, 6, 5, 4, 3, 2, 99, 0, 0, 0, -5401};
    apr_time_t
        tm;
    </local>
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
</method>

</class>
