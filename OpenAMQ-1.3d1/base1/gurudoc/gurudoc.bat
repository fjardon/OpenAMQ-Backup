@echo off
:-
:-  Copyright (c) 1996-2007 iMatix Corporation
:-
:-  This program is free software; you can redistribute it and/or modify
:-  it under the terms of the GNU General Public License as published by
:-  the Free Software Foundation; either version 2 of the License, or (at
:-  your option) any later version.
:-
:-  This program is distributed in the hope that it will be useful, but
:-  WITHOUT ANY WARRANTY; without even the implied warranty of
:-  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
:-  General Public License for more details.
:-
:-  For information on alternative licensing for OEMs, please contact
:-  iMatix Corporation.
:-

:-
:-  Default gurudoc script
:-
:-  Converts a gurudoc text file into web pages using the HTML frameset
:-  template.  Creates:
:-
:-      filename.html       - main index into frameset documentation
:-      filename_flat.html  - single HTML file with all content
:-
:-  If the current directory contains a script called "guruext" it will
:-  execute this script and pass it the filename as argument.
:-

call mkgdl %1
gsl3 -quiet -page:4 -gdl:%1 -tpl:html_frameset gurudoc
gsl3 -quiet -page:4 -gdl:%1 -tpl:html_simple -base:%1_flat gurudoc
if exist guruext.bat call guruext %1

