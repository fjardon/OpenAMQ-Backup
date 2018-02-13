/*===========================================================================

    HTTP processing functions
    Quick port of sflhttp functions required for loading/saving XML files.

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

 *===========================================================================*/

#ifndef IPR_HTTP_INCLUDED               //  Allow multiple inclusions
#define IPR_HTTP_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

size_t
    ipr_http_encode_meta  (char  *output, char **input, size_t outmax, Bool html);
size_t
    ipr_http_decode_meta (char *output, char **input, size_t outmax);
char
    ipr_http_decode_meta_charn (const char *meta_char, size_t length);

#ifdef __cplusplus
}
#endif

#endif
