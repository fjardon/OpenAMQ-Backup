!============================================================================*
!                                                                            *
!   lrschema.sql - Schema for PL/SQL programming                             *
!                                                                            *
!   Copyright (c) 1991-2009 iMatix Corporation                               *
!                                                                            *
!   Generates a program that runs under PL/SQL.                              *
!                                                                            *
!   Usage:      Add this line to the start of your dialog file:              *
!               -schema=lrschema.sql                                         *
!                                                                            *
!               Accepts these options:                                       *
!               -opt:stack_max=nnn - size of subdialog stack (20)            *
!               -opt:template=xxxx - template file (template.sql)            *
!               -opt:model=xxxx    - for the generation of procedures        *
!                                    or functions                            *
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

:declare string $template = "template.sql"
:declare string $model
:if "$model" = "procedure"
:else
:if "$model" = "function"
:else
:   echo "lr E: invalid model '$model'; use -opt:model=[procedure|function]"
:   exit 1
:endif
:endif

:if exist $source
:    declare string $ext = ""
:else
:    declare string $ext = ".mod"
:endif
:if not exist $source$ext
:output $source$ext
:echo "lr I: creating skeleton for $source$ext..."
/*=============================================================================

   $source.sql - description of PL/SQL program

   Written:    $date     $author
   Revised:    $date

:include optional $template "<HEADER>" "<END>"
   Skeleton generated by LIBERO $version on $fulldate, $time.
============================================================================*/


CREATE OR REPLACE $Model $Dialog
    (param_in   varchar2   default 'NOTHING')
:if "$model" ="function"
     RETURN     varchar2
:endif
IS

/*- Global variables and cursors -------------------------------------------*/

:include optional $template "<DATA>" "<END>"
:if "$model" ="function"

param_out					varchar2(1);
:endif

<STUB START>

/************************  INITIALISE THE PROGRAM  **************************/

PROCEDURE $"initialise_the_program" IS
BEGIN

    $"the_next_event" := $"ok_event";
:include optional $template "<Initialise-The-Program>" "<END>"

END $"initialise_the_program";


/***************************   GET EXTERNAL EVENT   **************************/

PROCEDURE $"get_external_event" IS
BEGIN
NULL;
:include optional $template "<Get-External-Event>" "<END>"

END $"get_external_event";


/*************************-   TERMINATE THE PROGRAM    ************************/

PROCEDURE $"terminate_the_program" IS
BEGIN

    $"the_next_event" := $"terminate_event";
:include optional $template "<Terminate-The-Program>" "<END>"

END $"terminate_the_program";

:close
:endif

!   Generate interpreter include file

:output $source\.sql
:echo "lr I: generating code for $dialog..."
/*---------------------------------------------------------------------------
    Dialog data and code block - do not modify this code by hand
    Generated by LIBERO $version on $fulldate, $time.
    Schema file used: $schema
----------------------------------------------------------------------------*/

:if exist $source$ext
CREATE OR REPLACE $Model $Dialog
:include $source$ext "CREATE OR REPLACE $Model $Dialog" "<STUB START>"
:endif

/*- Symbolic constants and event numbers -----------------------------------*/

LR_number					number; 	-- Type number

type  LR_table_type is table of varchar2(255)
         	index by binary_integer;

type  LR_stack_type is table of LR_number%type
         	index by binary_integer;

LR_abort_dialog					EXCEPTION;

$"the_exception_event"				LR_number%type := 0;
$"the_next_event"				LR_number%type := 0;
LR_state					LR_number%type := 0;
LR_event					LR_number%type := 0;
LR_index					LR_number%type := 0;
LR_savest					LR_number%type := 0;
LR_modnbr					LR_number%type := 0;
LR_vecptr					LR_number%type := 0;
exception_raised				LR_number%type := 0;

LR_stack_size					LR_number%type := 0;
LR_stack					LR_stack_type;
 	
:if defaults
LR_defaults_state			constant LR_number%type := $defaults + 1;
:endif
:set array_base = 1
:do state
-- LR_STATE_$name			constant LR_number%type := $number;
:enddo
:set array_base = 0

$"terminate_event"			constant LR_number%type	:= -1; -- Halts the dialog
LR_NULL_EVENT				constant LR_number%type	:= -2;
:set array_base = 1
:do event
$name					constant LR_number%type	:= $number;
:enddo
:set array_base = 0

LR_nextst					LR_table_type;
LR_action					LR_table_type;
LR_vector					LR_table_type;

:if animate	
LR_sname					LR_table_type;
LR_ename					LR_table_type;
LR_mname					LR_table_type;
:endif

PROCEDURE $"raise_exception" ( event In LR_number%type );
PROCEDURE $"initialise_the_program";
PROCEDURE $"get_external_event";
PROCEDURE LR_initialise;
PROCEDURE $dialog\_dialog;
:do module
PROCEDURE $name;
:enddo


/*- Standard subroutines used by dialog interpreter -----------------------*/

PROCEDURE $"raise_exception" ( event IN LR_number%type ) IS
BEGIN
    if ( event > 0 ) then	
	$"the_exception_event" := event;
    end if;
    $"exception_raised" := 1;
END $"raise_exception";

PROCEDURE LR_initialise is
BEGIN
:if $states < 10
:   declare int nswid = 1               # Size of item in LR_nextst table
:else
:if $states < 100
:   declare int nswid = 2
:else
:   declare int nswid = 3
:endif
:endif
:
:if $vectors < 10
:   declare int acwid = 1               # Size of item in LR_action table
:else
:if $vectors < 100
:   declare int acwid = 2
:else
:   declare int acwid = 3
:endif
:endif
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
:endif
:endif
:
:set row_width  = 42                    # If $row is longer, do overflow
:set number_fmt = "%ld"
:set row_first  = "%0$nswid\ld"
:set row_after  = "%0$nswid\ld"
:set number_fmt = "%ld"
:set array_base = 1
:declare int nextstidx = 1
:do nextst
    LR_nextst($nextstidx) := '$row';
:   do overflow
    LR_nextst($nextstidx) := LR_nextst($nextstidx) || '$row';
:   enddo
:   set $nextstidx = $nextstidx + 1
:enddo
:
:set number_fmt = "%ld"
:set row_first  = "%0$acwid\ld"
:set row_after  = "%0$acwid\ld"
:set number_fmt = "%ld"
:set array_base = 1
:set nextstidx = 1
:do action
    LR_action($nextstidx) := '$row';
:   do overflow
    LR_action($nextstidx) := LR_action($nextstidx) || '$row';
:   enddo
:   set $nextstidx = $nextstidx + 1
:enddo
:
:set number_fmt = "%ld"
:set row_first  = "%0$mowid\ld"
:set row_after  = "%0$mowid\ld"
:set number_fmt = "%ld"
:declare int vectoridx = 1
:do vector
:  if "$row" = ""
    LR_vector($vectoridx) := '$null';
:  else
    LR_vector($vectoridx) := '$row';
:   do overflow
    LR_vector($vectoridx) := LR_vector($vectoridx) || '$row';
:   enddo
:  endif
    LR_vector($vectoridx) := LR_vector($vectoridx) || '$null';
:  set $vectoridx = $vectoridx + 1
:enddo

:set array_base = 0

:if animate
:set array_base = 1
:push $style
:option -style=normal
:do state
    LR_sname ($number) := '$name';
:enddo

:do event
    LR_ename ($number) := '$name';
:enddo

:do module
    LR_mname ($number) := '$name';
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
END LR_initialise;

:if module "Dialog-Call"
PROCEDURE $"dialog_call" IS
BEGIN

   if (LR_stack_size < $stack_max) then
       LR_stack_size := LR_stack_size + 1;
       LR_stack (LR_stack_size) := LR_state;
       raise LR_abort_dialog;				-- exit
   else
       dbms_output.enable;      
       dbms_output.put_line('State ' || to_char(LR_state) || ' -  Dialog-Call overflow');
   end if;

END $"dialog_call";

PROCEDURE $"dialog_return" IS
BEGIN

   if (LR_stack_size > 0) then
       LR_stack_size := LR_stack_size - 1;
       LR_state := LR_stack (LR_stack_size);
       $"raise_exception" ($"return_event");
   else
       dbms_output.enable;      
       dbms_output.put_line('State ' || to_char(LR_state) || ' -  Dialog-Return overflow');
       raise LR_abort_dialog;				-- exit
   end if;

END dialog_return;

:endif
/*- Dialog interpreter starts here -----------------------------------------*/

PROCEDURE $dialog\_dialog is

BEGIN

LR_state := 1;				--  First state 

:if module "Dialog-Call"
LR_stack_size := 0;			--  Clear subdialog stack
:endif
LR_initialise;				--  Initialise static strings
$"initialise_the_program";

while ($"the_next_event" != $"terminate_event") loop

    LR_event := $"the_next_event";
:if check
    if (LR_event > $events OR LR_event < 1 ) then
       dbms_output.enable;      
       dbms_output.put_line('State ' || to_char(LR_state) ||
                           ' - event ' || to_char(LR_event) || ' is out of range');
    end if;
:endif
    LR_savest := LR_state; 
    LR_index  := to_number(substr(LR_action (LR_state), (LR_event * $acwid )- $acwid + 1,$acwid));

:if defaults
    --  If no action for this event, try the defaults state

    if (LR_index = 0) then
        LR_state := LR_defaults_state;
	LR_index := to_number(substr(LR_action (LR_state),(LR_event * $acwid )- $acwid + 1,$acwid));
:endif
:if check
        if (LR_index = 0) then
          dbms_output.enable;      
          dbms_output.put_line('State ' || to_char(LR_state) ||
                           ' - event ' || to_char(LR_event) || ' is not accepted');
          exit;
        end if;	
:endif
:if defaults
    end if;      
:endif
:if animate

    dbms_output.enable;      
    dbms_output.put_line(LR_sname (LR_state));
    dbms_output.put_line('.   (--) ' || LR_ename (LR_event));  

:endif
:if check
    $"the_next_event" := LR_NULL_EVENT;
:endif
    $"the_exception_event" := LR_NULL_EVENT;
    $"exception_raised" := 0;

    --   Execute module list for state transition, 0 indicates end of list

    LR_vecptr := 1;
    LR_modnbr := to_number(substr (LR_vector (LR_index),(LR_vecptr * $mowid) - $mowid + 1, $mowid));

    while ((LR_modnbr > 0 ) and ( $"exception_raised" != 1 )) loop
      
:if animate 
       dbms_output.enable;      
       dbms_output.put_line('.         + ' || LR_mname (LR_modnbr));

:endif
       						--  Execute the module
:set array_base = 1
:do module
:if $number == 1
       if    ( LR_modnbr = $number ) then	$name;
:endif
:if $number > 1
       elsif ( LR_modnbr = $number ) then	$name;	    	
:endif
:enddo
       end if;

:set array_base = 0
       LR_vecptr := LR_vecptr + 1;
       LR_modnbr := to_number(substr(LR_vector(LR_index),(LR_vecptr * $mowid) - $mowid + 1,$mowid));

    end loop;

    --  Handle exception if any was raised

    if ( $"exception_raised" = 1 ) then
       if ($"the_exception_event" != LR_NULL_EVENT ) then
            LR_event := $"the_exception_event";
       end if;
       $"the_next_event" := LR_event;
:if animate

       dbms_output.enable;      
       dbms_output.put_line('.    (=>) ' || LR_ename (LR_event));

:endif
    else
       LR_state := to_number(substr(LR_nextst(LR_state),(LR_event * $nswid) - $nswid + 1, $nswid));
    end if;

:if defaults
    if ( LR_state = LR_defaults_state ) then
       LR_state := LR_savest;
    end if;	

:endif
    if ( $"the_next_event" = LR_NULL_EVENT ) then
       $"get_external_event";
:if check
       if ( $"the_next_event" = LR_NULL_EVENT ) then
          dbms_output.enable;      
          dbms_output.put_line('No event set after event '|| 
				LR_event || ' in state ' || LR_state );
          exit;
       end if; 
:endif
    end if;

end loop;

end $dialog\_dialog;                            --   Return true value

:close

!   Generate stubs for all modules not yet defined in source file

:set stub_first="/"
:set stub_between="*"
:set stub_last="/"
:set module_line="PROCEDURE %s IS"
:internal initialise_the_program
:internal get_external_event
:do stubs $source$ext $dialog\.sql

PROCEDURE $name IS
BEGIN
NULL;
:include optional $template "<$module_name>" "<END>"

END $name;

:enddo stubs

:extend $source\.sql
:include $source$ext "<STUB START>" 

/***************************   Call Dialog ************************************/

BEGIN 
$dialog\_dialog;

:if "$model" = "function"
return param_out;
:endif

EXCEPTION
	when LR_abort_dialog then raise;
END;

:close

