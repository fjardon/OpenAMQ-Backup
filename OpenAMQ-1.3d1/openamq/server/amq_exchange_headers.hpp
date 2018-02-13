/*---------------------------------------------------------------------------
    amq_exchange_headers.hpp - amq_exchange_headers component wrapper in C++

This class implements the headers exchange, which routes messages
based on the message header fields (the field table called "headers"
that is in every content header).  Max. unique fields exchange is
limited by size of amq_index_hash table.
    Generated from amq_exchange_headers.icl by icl_gen using GSL/4.
    
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

