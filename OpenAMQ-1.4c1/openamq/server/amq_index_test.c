/*---------------------------------------------------------------------------
    amq_index_test.c - amq_index component tester

    Generated from amq_index.icl by icl_gen using GSL/4.
    
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
#include "amq_index.h"                  //  Definitions for our class
#include "version.h"

int main (int argc, char *argv[])
{
    int
        argn;                           //  Argument number
    Bool
        args_ok = TRUE,                 //  Were the arguments okay?
        quiet_mode = FALSE;             //  -q means suppress messages
    char
        **argparm;                      //  Argument parameter to pick-up

    argparm = NULL;                     //  Argument parameter to pick-up
    for (argn = 1; argn < argc; argn++) {
        //  If argparm is set, we have to collect an argument parameter
        if (argparm) {
            if (*argv [argn] != '-') {  //  Parameter can't start with '-'
                *argparm = argv [argn];
                argparm = NULL;
            }
            else {
                args_ok = FALSE;
                break;
            }
        }
        else
        if (*argv [argn] == '-') {
            switch (argv [argn][1]) {
                case 'q':
                    quiet_mode = TRUE;
                    break;
                case 'v':
                    printf (PRODUCT "\n");
                    printf (COPYRIGHT "\n");
                    printf (BUILDMODEL "\n");
                    printf ("Built on: " BUILDDATE "\n");
                    printf ("Compiler: " CCOPTS "\n");
                    exit (EXIT_SUCCESS);
                case 'h':
                    printf (PRODUCT "\n");
                    printf (COPYRIGHT "\n");
                    printf ("Options:\n");
                    printf ("  -q  - Quiet mode: no messages\n");
                    printf ("  -v  - Show version information\n");
                    printf ("  -h  - Show summary of command-line options\n");
                    exit (EXIT_SUCCESS);
                //  Anything else is an error
                default:
                    args_ok = FALSE;
            }
        }
        else {
            args_ok = FALSE;
            break;
        }
    }

    //  Set quiet console mode before initialise so we don't get memory
    //  allocator message in quiet mode.
    if (quiet_mode)
        icl_console_mode (ICL_CONSOLE_QUIET, TRUE);

    //  Initialise global class so we can use the console
    icl_system_initialise (argc, argv);

    //  If there was a missing parameter or an argument error, quit
    if (argparm) {
        icl_console_print ("E: argument missing - use '-h' option for help");
        exit (EXIT_FAILURE);
    }
    else
    if (!args_ok) {
        icl_console_print ("E: invalid arguments - use '-h' option for help");
        exit (EXIT_FAILURE);
    }

    amq_index_selftest ();

    icl_console_print ("I: amq_index OK");
    icl_system_terminate ();            //  Terminate all classes

    return (EXIT_SUCCESS);
}
