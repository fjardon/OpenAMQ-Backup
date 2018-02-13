/*---------------------------------------------------------------------------
    icl_info.hpp - iMatix base header file

    Template for C++ info class.
    Class is specialised for every generated iCL C++ object.

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
 *---------------------------------------------------------------------------*/

#ifndef ICL_INFO_INCLUDED
#define ICL_INFO_INCLUDED

template <typename T> struct icl_info
{
    typedef T c_type;
    typedef T cpp_type;
    typedef T cpp_type_ref; 
    typedef T cpp_const_type;
    typedef T cpp_const_type_ref;
    static inline c_type underlying (cpp_type_ref t) {return t;}
};

#endif
