!============================================================================*
!                                                                            *
!   lrschema.pl - Schema for Perl programming                                *
!                                                                            *
!   Copyright (c) 1991-2009 iMatix Corporation                               *
!                                                                            *
!   Generates a program that runs under Perl.  Generates a .pl file          *
!   (your program) and a .d file (generated code).  If you prefer a script   *
!   with no extension, rename the .pl file.                                  *
!                                                                            *
!   Usage:      Add this line to the start of your dialog file:              *
!               -schema=lrschema.pl                                          *
!                                                                            *
!               Accepts these options:                                       *
!               -opt:stack_max=nnn - size of subdialog stack (20)            *
!               -opt:template=xxxx - template file (template.pl)             *
!                                                                            *
!   ------------------ GPL Licensed Source Code ------------------           *
!   iMatix makes this software available under the GNU General               *
!   Public License (GPL) license for open source projects.  For              *
!   details of the GPL license please see www.gnu.org or read the            *
!   file license.gpl provided in this package.                               *
!                                                                            *
!   This program is free software; you can redistribute it and/or            *
!   modify it under the terms of the GNU General Public License as           *
!   published by the Free Software Foundation; either version 2 of           *
!   the License, or (at your option) any later version.                      *
!                                                                            *
!   This program is distributed in the hope that it will be useful,          *
!   but WITHOUT ANY WARRANTY; without even the implied warranty of           *
!   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
!   GNU General Public License for more details.                             *
!                                                                            *
!   You should have received a copy of the GNU General Public                *
!   License along with this program in the file 'license.gpl'; if            *
!   not, write to the Free Software Foundation, Inc., 59 Temple              *
!   Place - Suite 330, Boston, MA 02111-1307, USA.                           *
!                                                                            *
!   You can also license this software under iMatix's General Terms          *
!   of Business (GTB) for commercial projects.  If you have not              *
!   explicitly licensed this software under the iMatix GTB you may           *
!   only use it under the terms of the GNU General Public License.           *
!                                                                            *
!   For more information, send an email to info@imatix.com.                  *
!   --------------------------------------------------------------           *
!============================================================================*

!   You can use the template file to include project-specific code in the
!   generated code at various points.  This is a (better) alternative to
!   changing the schema in order to add your own project code.
!
!   The template file should contain these sections (each starts with a
!   keyword on a line, and ends with <END> on a line).  These sections may
!   be included in a newly-generated program (keywords are case-sensitive):
!
!   <HEADER>                    - program header comment
!   <DATA>                      - data definitions
!   <Initialise-The-Program>    - in Initialise-The-Program
!   <Get-External-Event>        - in Get-External-Event
!   <Terminate-The-Program>     - in Terminate-The-Program
!   <Any-Dialog-Module>         - any dialog module
!
:declare string $template = "template.pl"

:if exist $source
:    declare string $ext = ""
:else
:    declare string $ext = ".pl"
:endif
:if not exist $source$ext
:output $source$ext
:echo "lr I: creating skeleton for $source$ext..."
#! /usr/bin/perl
#=============================================================================
#
#   $source.pl - description of Perl program
#
#   Written:    $date     $author
#   Revised:    $date
#
:include optional $template "<HEADER>" "<END>"
#   Skeleton generated by LIBERO $version on $fulldate, $time.
#=============================================================================

:include optional $template "<DATA>" "<END>"

require '$dialog.d';                    #   Include dialog interpreter


##########################   INITIALISE THE PROGRAM   #########################

sub $"initialise_the_program"
{
    $$$"the_next_event" = $$$"ok_event";
:include optional $template "<Initialise-The-Program>" "<END>"
}


############################   GET EXTERNAL EVENT   ###########################

sub $"get_external_event"
{
:include optional $template "<Get-External-Event>" "<END>"
}


##########################   TERMINATE THE PROGRAM    #########################

sub $"terminate_the_program"
{
    $$$"the_next_event" = $$$"terminate_event";
:include optional $template "<Terminate-The-Program>" "<END>"
}

:close
:endif

!   Generate interpreter include file

:output $source.d
:echo "lr I: generating code for $dialog..."
#----------------------------------------------------------------------------
#   Dialog data and code block - do not modify this code by hand
#   Generated by LIBERO $version on $fulldate, $time.
#   Schema file used: $schema
#----------------------------------------------------------------------------

#-- Symbolic constants and event numbers ------------------------------------

:if defaults
$$LR_defaults_state = $defaults;
:endif
:do state
$$LR_STATE_$name = $number;
:enddo

$$$"terminate_event" = -1;              # Halts the dialog
$$LR_NULL_EVENT = -2;
:do event
$$$name = $number;
:enddo

#-- Standard subroutines used by dialog interpreter -------------------------

sub $"raise_exception" {
    local ($$event) = @_;
    $$$"the_exception_event" = $$event;
    $$$"exception_raised" = 1;
}

sub LR_initialise {
:if $states < 10
:   declare int nswid = 1               # Size of item in LR_nextst table
:else
:if $states < 100
:   declare int nswid = 2
:else
:   declare int nswid = 3
:endif all
:
:if $vectors < 10
:   declare int acwid = 1               # Size of item in LR_action table
:else
:if $vectors < 100
:   declare int acwid = 2
:else
:   declare int acwid = 3
:endif all
:
:if $modules < 10
:   declare int mowid = 1               # Size of item in LR_module table
:   declare string null = "0"
:else
:if $modules < 100
:   declare int mowid = 2
:   declare string null = "00"
:else
:   declare int mowid = 3
:   declare string null = "000"
:endif all
:
:set row_width  = 42                    # If $row is longer, do overflow
:set number_fmt = "%ld"
:set row_first  = "%0$nswid\ld"
:set row_after  = "%0$nswid\ld"
:set number_fmt = "%ld"
:
    $$LR_nextst = "";
:do nextst
    $$LR_nextst .= "$row";
:  do overflow
    $$LR_nextst .= "$row";
:  enddo
:enddo

:set number_fmt = "%ld"
:set row_first  = "%0$acwid\ld"
:set row_after  = "%0$acwid\ld"
:set number_fmt = "%ld"
:
:set array_base = 1
    $$LR_action = "";
:do action
    $$LR_action .= "$row";
:  do overflow
    $$LR_action .= "$row";
:  enddo
:enddo

:set number_fmt = "%ld"
:set row_first  = "%0$mowid\ld"
:set row_after  = "%0$mowid\ld"
:set number_fmt = "%ld"
:
    $$LR_module = "";
:do vector
    $$LR_module .= "$row" . "$null";
:enddo
:set array_base = 0

:declare int offsetidx
:do vector
:   set offsetidx = $number + 1
    $$LR_offset [$offsetidx] = $offset;
:enddo
:if animate

:push $style
:option -style=normal
:do state
    $$LR_sname [$number] = "$name";
:enddo
:do event
    $$LR_ename [$number] = "$name";
:enddo
:set array_base = 1
:do module
    $$LR_mname [$number] = "$name";
:enddo
:set array_base = 0
:pop $style
:option -style=$style
:endif
:if module "Dialog-Call"
:  if not event "Return"
:     echo "lr E: you must define the 'Return' event"
:     exit 1
:  endif
:  declare int $stack_max = 20
:endif
}

:if module "Dialog-Call"
sub $"dialog_call"
{
    $$LR_stack_size < $stack_max || die
        "State ", $$LR_state, " - Dialog-Call overflow\n";
    $$LR_stack [++$$LR_stack_size] = $$LR_state;
}

sub $"dialog_return"
{
    $$LR_stack_size > 0 || die
        "State ", $$LR_state, " - Dialog-Return underflow\n";
    $$LR_state = $$LR_stack [$$LR_stack_size--];
    &$"raise_exception" ($$$"return_event");
}

:endif
#-- Dialog interpreter starts here ------------------------------------------

$$feedback = 0;                         #   Main program feedback
$$LR_state = 0;                         #   First state is always 0
:if module "Dialog-Call"
$$LR_stack_size = 0;                    #   Clear subdialog stack
:endif
&LR_initialise;                         #   Initialise static strings
&$"initialise_the_program";
while ($$$"the_next_event" != $$$"terminate_event")
  {
    $$LR_event = $$$"the_next_event";
:if check
    $$LR_event < 0 || $$LR_event >= $events && die
        "State ", $$LR_state,
        " - event ", $$LR_event, " is out of range\n";
:endif
    $$LR_index = ($$LR_state * $events + $$LR_event) * $acwid;
    $$LR_index = substr ($$LR_action, $$LR_index, $acwid);
    $$LR_savest = $$LR_state;

:if defaults
    #   If no action for this event, try the defaults state
    if ($$LR_index == 0)
      {
        $$LR_state = $$LR_defaults_state;
        $$LR_index = ($$LR_state * $events + $$LR_event) * $acwid;
        $$LR_index = substr ($$LR_action, $$LR_index, $acwid);
:endif
:if check
        $$LR_index == 0 && die
            "State ", $$LR_state,
            " - event ", $$LR_event, " is not accepted\n";
:endif
:if defaults
      }
:endif
:if animate
    printf "\n%s:\n", $$LR_sname [$$LR_state];
    printf "    (--) %s\n", $$LR_ename [$$LR_event];
:endif
:if check
    $$$"the_next_event" = $$LR_NULL_EVENT;
:endif
    $$$"the_exception_event" = $$LR_NULL_EVENT;
    $$$"exception_raised" = 0;

    #   Execute module list for state transition, 0 indicates end of list
    $$LR_vecptr = $$LR_offset [$$LR_index];
    $$LR_modnbr = substr ($$LR_module, $$LR_vecptr * $mowid, $mowid);
    while ($$LR_modnbr > 0 && !$$$"exception_raised")
      {
:if animate
        printf "          + %s\n", $$LR_mname [$$LR_modnbr];
:endif
          {                             #   Execute the module
:set array_base = 1
:do module
            $$LR_modnbr == $number && do { &$name; last; };
:enddo
:set array_base = 0
          }
        $$LR_vecptr++;
        $$LR_modnbr = substr ($$LR_module, $$LR_vecptr * $mowid, $mowid);
      }

    #   Handle exception if any was raised
    if ($$$"exception_raised")
      {
        $$$"the_exception_event" == $$LR_NULL_EVENT ||
            ($$LR_event = $$$"the_exception_event");

        $$$"the_next_event" = $$LR_event;
:if animate
        printf "    (=>) %s\n", $$LR_ename [$$LR_event];
:endif
      }
    else
      {
        $$LR_index = ($$LR_state * $events + $$LR_event) * $nswid;
        $$LR_state = substr ($$LR_nextst, $$LR_index, $nswid);
      }
:if defaults
    $$LR_state = $$LR_savest if ($$LR_state == $$LR_defaults_state);
:endif
    if ($$$"the_next_event" == $$LR_NULL_EVENT)
      {
        &$"get_external_event";
:if check
        $$$"the_next_event" == $$LR_NULL_EVENT && die
            "No event set after event ", $$LR_event,
            " in state ", $$LR_state, "\n";
:endif
      }
  }
exit ($$feedback);
:close

!   Generate stubs for all modules not yet defined in source file

:set stub_first="#"
:set stub_between="#"
:set stub_last="#"
:set module_line="sub %s"
:internal initialise_the_program
:internal get_external_event
:do stubs $source$ext $dialog.d

sub $name
{
:include optional $template "<$module_name>" "<END>"
}

:enddo stubs