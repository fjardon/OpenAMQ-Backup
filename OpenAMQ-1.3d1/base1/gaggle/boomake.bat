@echo off
:-
:-  Boom builder for Gaggle 1.0
:-  Generated by iMatix Boom from scripted.pwl
:-  
:-  Copyright (c) 1996-2009 iMatix Corporation
:-  All rights reserved.
:-  
:-  This file is licensed under the BSD license as follows:
:-  
:-  Redistribution and use in source and binary forms, with or without
:-  modification, are permitted provided that the following conditions
:-  are met:
:-  
:-  * Redistributions of source code must retain the above copyright
:-    notice, this list of conditions and the following disclaimer.
:-  * Redistributions in binary form must reproduce the above copyright
:-    notice, this list of conditions and the following disclaimer in
:-    the documentation and/or other materials provided with the
:-    distribution.
:-  * Neither the name of iMatix Corporation nor the names of its
:-    contributors may be used to endorse or promote products derived
:-    from this software without specific prior written permission.
:-  
:-  THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
:-  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
:-  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
:-  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
:-  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
:-  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
:-  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
:-  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
:-  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
:-  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
:-  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
:-
:-  Start CMD.EXE version detection
verify other 2>nul
setlocal enableextensions
if errorlevel 0 goto __cmd_ok
echo %0: This command requires command extensions version 2 in CMD.EXE.  
echo %0: Please use a supported system (Windows 2000 or newer).
exit
:__cmd_ok
setlocal enabledelayedexpansion
:-  End CMD.EXE version detection
goto :init
:-
:-  Subroutine: boom_model_init
:-  Initialises BOOM_MODEL to default if not set
:-  Expands BOOM_MODEL components into individual environment variables
:-
:boom_model_init
if "!BOOM_MODEL!"=="" (
    set BOOM_MODEL=release,st
)
set BOOM_MODEL__PLACEHOLDER=1
for /f "usebackq delims==" %%v in (`set BOOM_MODEL_`) do set %%v=
set BOOM_MODEL__PLACEHOLDER=
for %%m in (!BOOM_MODEL!) do set BOOM_MODEL_%%m=1
:-  If the user set BOOM_MODEL but did not include release/debug or st/mt
:-  set these to defaults.
if not "!BOOM_MODEL_RELEASE!"=="1" (
    if not "!BOOM_MODEL_DEBUG!"=="1" (
        set BOOM_MODEL_RELEASE=1
        set BOOM_MODEL=!BOOM_MODEL!,release
    )
)
if not "!BOOM_MODEL_ST!"=="1" (
    if not "!BOOM_MODEL_MT!"=="1" (
        set BOOM_MODEL_ST=1
        set BOOM_MODEL=!BOOM_MODEL!,st
    )
)
goto :eof
:init
setlocal
:-
:-  Set environment variables to point to install location
:-  Start by using final IBASE, then handle -install path
set self=%0
set MY_VERSION=1.0
set OLDPATH=!PATH!
set OLDPERLLIB=!PERLLIB!
if .!IBASE!==. (
    echo boom E: [gag]: The IBASE variable is not set.             Please set it to the location where Gaggle should be installed.
    exit /b 1
)
if .%1==.-v (
    set BOOM_TRACE=1
    shift
)
call :boom_model_init
if .%1==.-install goto tempinst
:-  Normal use, use IBASE
    set PATH=!IBASE!\bin;!PATH!
    set PERLLIB=!IBASE!\bin;!PERLLIB!
    set INCDIR_ALT=!IBASE!\include
    set _INSTALL_ROOT=!IBASE!
    goto process

:tempinst
:-  Building product, we use -install directory first, then IBASE
    if not exist %2 (
       echo "Invalid command syntax - please contact imatix-tech"
       exit /b 1
    )
    pushd %2
    set _LOCAL_BASE=!cd!
    popd
    set PATH=!_LOCAL_BASE!\bin;!IBASE!\bin;!PATH!
    set PERLLIB=!_LOCAL_BASE!\bin;!IBASE!\bin;!PERLLIB!
    set INCDIR_ALT=!_LOCAL_BASE!\include;!IBASE!\include
    set _INSTALL_ROOT=!_LOCAL_BASE!
    shift
    shift
    goto process

:batch
    shift

:process
    set state=initial
    set event=ok
    set debug=0
    goto s_!state!

:--------------------------   BUILD SOURCE PACKAGES   -------------------------

:a_build_source_packages
   if exist _package.lst del _package.lst
    if exist gaggle\framer echo gaggle\framer>>_package.lst
    if exist gaggle\framer.fmt echo gaggle\framer.fmt>>_package.lst
    if exist gaggle\srcdoc echo gaggle\srcdoc>>_package.lst
    if exist gaggle\srcdoc.fmt echo gaggle\srcdoc.fmt>>_package.lst
    if exist gaggle\srcdoc.man echo gaggle\srcdoc.man>>_package.lst
    if exist gaggle\objtype.gsl echo gaggle\objtype.gsl>>_package.lst
    if exist gaggle\framer.l echo gaggle\framer.l>>_package.lst
    if exist gaggle\framer.d echo gaggle\framer.d>>_package.lst
    if exist gaggle\framer.bat echo gaggle\framer.bat>>_package.lst
    if exist gaggle\srcdoc.l echo gaggle\srcdoc.l>>_package.lst
    if exist gaggle\srcdoc.d echo gaggle\srcdoc.d>>_package.lst
    if exist gaggle\srcdoc.bat echo gaggle\srcdoc.bat>>_package.lst
    if exist gaggle\stamp_generate echo gaggle\stamp_generate>>_package.lst
    if exist gaggle\configure echo gaggle\configure>>_package.lst
    if exist gaggle\Makefile.unix echo gaggle\Makefile.unix>>_package.lst
    if exist gaggle\boomake echo gaggle\boomake>>_package.lst
    if exist gaggle\configure.bat echo gaggle\configure.bat>>_package.lst
    if exist gaggle\Makefile.win32 echo gaggle\Makefile.win32>>_package.lst
    if exist gaggle\boomake.bat echo gaggle\boomake.bat>>_package.lst
    echo "Source package successfully generated">stamp_source
    echo "stamp_source">>_package.lst
    echo boom I: [gag]: Building gag-!MY_VERSION!-src.zip...
    zip  -rq _package -@<_package.lst
    unzip -q _package -d gag-!MY_VERSION!
    if exist  gag-!MY_VERSION!-src.zip del gag-!MY_VERSION!-src.zip
    zip -rmq gag-!MY_VERSION!-src.zip gag-!MY_VERSION!
    del _package.zip
    del _package.lst
    del stamp_source
    goto :eof

:----------------------   CHECK ALL SOURCE FILES EXIST   ----------------------

:a_check_all_source_files_exist
    if not exist framer (
        echo boom E: [gag]: framer is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist framer.fmt (
        echo boom E: [gag]: framer.fmt is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc (
        echo boom E: [gag]: srcdoc is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.fmt (
        echo boom E: [gag]: srcdoc.fmt is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.man (
        echo boom E: [gag]: srcdoc.man is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist objtype.gsl (
        echo boom E: [gag]: objtype.gsl is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist framer.l (
        echo boom E: [gag]: framer.l is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist framer.d (
        echo boom E: [gag]: framer.d is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist framer.bat (
        echo boom E: [gag]: framer.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.l (
        echo boom E: [gag]: srcdoc.l is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.d (
        echo boom E: [gag]: srcdoc.d is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.bat (
        echo boom E: [gag]: srcdoc.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist stamp_generate (
        echo boom E: [gag]: stamp_generate is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist configure (
        echo boom E: [gag]: configure is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist Makefile.unix (
        echo boom E: [gag]: Makefile.unix is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist boomake (
        echo boom E: [gag]: boomake is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist configure.bat (
        echo boom E: [gag]: configure.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist Makefile.win32 (
        echo boom E: [gag]: Makefile.win32 is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist boomake.bat (
        echo boom E: [gag]: boomake.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    goto :eof

:-------------------------   CHECK OPERATING CONTEXT   ------------------------

:a_check_operating_context
    set event=repository
    if exist stamp_source   set event=source
    if exist stamp_stripped set event=stripped
    goto :eof

:------------------------   CHECK PROJECT FILES EXIST   -----------------------

:a_check_project_files_exist
    if not exist framer (
        echo boom E: [gag]: framer is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist framer.fmt (
        echo boom E: [gag]: framer.fmt is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc (
        echo boom E: [gag]: srcdoc is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.fmt (
        echo boom E: [gag]: srcdoc.fmt is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.man (
        echo boom E: [gag]: srcdoc.man is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist objtype.gsl (
        echo boom E: [gag]: objtype.gsl is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist framer.l (
        echo boom E: [gag]: framer.l is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist framer.bat (
        echo boom E: [gag]: framer.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.l (
        echo boom E: [gag]: srcdoc.l is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.bat (
        echo boom E: [gag]: srcdoc.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist configure (
        echo boom E: [gag]: configure is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist Makefile.unix (
        echo boom E: [gag]: Makefile.unix is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist boomake (
        echo boom E: [gag]: boomake is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist configure.bat (
        echo boom E: [gag]: configure.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist Makefile.win32 (
        echo boom E: [gag]: Makefile.win32 is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist boomake.bat (
        echo boom E: [gag]: boomake.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    goto :eof

:------------------------   CHECK SOURCE FILES EXIST   ------------------------

:a_check_source_files_exist
    if not exist framer (
        echo boom E: [gag]: framer is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist framer.fmt (
        echo boom E: [gag]: framer.fmt is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc (
        echo boom E: [gag]: srcdoc is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.fmt (
        echo boom E: [gag]: srcdoc.fmt is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.man (
        echo boom E: [gag]: srcdoc.man is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist objtype.gsl (
        echo boom E: [gag]: objtype.gsl is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist framer.l (
        echo boom E: [gag]: framer.l is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist framer.d (
        echo boom E: [gag]: framer.d is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist framer.bat (
        echo boom E: [gag]: framer.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.l (
        echo boom E: [gag]: srcdoc.l is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.d (
        echo boom E: [gag]: srcdoc.d is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist srcdoc.bat (
        echo boom E: [gag]: srcdoc.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist stamp_generate (
        echo boom E: [gag]: stamp_generate is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist configure (
        echo boom E: [gag]: configure is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist Makefile.unix (
        echo boom E: [gag]: Makefile.unix is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist boomake (
        echo boom E: [gag]: boomake is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist configure.bat (
        echo boom E: [gag]: configure.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist Makefile.win32 (
        echo boom E: [gag]: Makefile.win32 is missing, cannot continue
        set _exception=1
        goto :eof
    )
    if not exist boomake.bat (
        echo boom E: [gag]: boomake.bat is missing, cannot continue
        set _exception=1
        goto :eof
    )
    goto :eof

:--------------------------   INSTALL DELIVERABLES   --------------------------

:a_install_deliverables
    echo boom I: [gag]: installing Gaggle into !_INSTALL_ROOT!...
    if not exist !_INSTALL_ROOT! mkdir !_INSTALL_ROOT!
    if not exist !_INSTALL_ROOT!\bin\nul mkdir !_INSTALL_ROOT!\bin\
    if "!BOOM_TRACE!"=="1" echo copy/y framer !_INSTALL_ROOT!\bin\>nul
    verify>nul
    call copy/y framer !_INSTALL_ROOT!\bin\>nul
    if errorlevel 1 (
        echo boom E: [gag]: 'copy/y framer !_INSTALL_ROOT!\bin\>nul' failed - stop.
        set _exception=1
        goto :eof
    )
    if "!BOOM_TRACE!"=="1" echo copy/y framer.fmt !_INSTALL_ROOT!\bin\>nul
    verify>nul
    call copy/y framer.fmt !_INSTALL_ROOT!\bin\>nul
    if errorlevel 1 (
        echo boom E: [gag]: 'copy/y framer.fmt !_INSTALL_ROOT!\bin\>nul' failed - stop.
        set _exception=1
        goto :eof
    )
    if "!BOOM_TRACE!"=="1" echo copy/y srcdoc !_INSTALL_ROOT!\bin\>nul
    verify>nul
    call copy/y srcdoc !_INSTALL_ROOT!\bin\>nul
    if errorlevel 1 (
        echo boom E: [gag]: 'copy/y srcdoc !_INSTALL_ROOT!\bin\>nul' failed - stop.
        set _exception=1
        goto :eof
    )
    if "!BOOM_TRACE!"=="1" echo copy/y srcdoc.fmt !_INSTALL_ROOT!\bin\>nul
    verify>nul
    call copy/y srcdoc.fmt !_INSTALL_ROOT!\bin\>nul
    if errorlevel 1 (
        echo boom E: [gag]: 'copy/y srcdoc.fmt !_INSTALL_ROOT!\bin\>nul' failed - stop.
        set _exception=1
        goto :eof
    )
    if not exist !_INSTALL_ROOT!\doc\Gaggle\nul mkdir !_INSTALL_ROOT!\doc\Gaggle\
    if "!BOOM_TRACE!"=="1" echo copy/y srcdoc.man !_INSTALL_ROOT!\doc\Gaggle\>nul
    verify>nul
    call copy/y srcdoc.man !_INSTALL_ROOT!\doc\Gaggle\>nul
    if errorlevel 1 (
        echo boom E: [gag]: 'copy/y srcdoc.man !_INSTALL_ROOT!\doc\Gaggle\>nul' failed - stop.
        set _exception=1
        goto :eof
    )
    if not exist !_INSTALL_ROOT!\bin\nul mkdir !_INSTALL_ROOT!\bin\
    if "!BOOM_TRACE!"=="1" echo copy/y objtype.gsl !_INSTALL_ROOT!\bin\>nul
    verify>nul
    call copy/y objtype.gsl !_INSTALL_ROOT!\bin\>nul
    if errorlevel 1 (
        echo boom E: [gag]: 'copy/y objtype.gsl !_INSTALL_ROOT!\bin\>nul' failed - stop.
        set _exception=1
        goto :eof
    )
    if "!BOOM_TRACE!"=="1" echo copy/y framer.d !_INSTALL_ROOT!\bin\>nul
    verify>nul
    call copy/y framer.d !_INSTALL_ROOT!\bin\>nul
    if errorlevel 1 (
        echo boom E: [gag]: 'copy/y framer.d !_INSTALL_ROOT!\bin\>nul' failed - stop.
        set _exception=1
        goto :eof
    )
    if "!BOOM_TRACE!"=="1" echo copy/y framer.bat !_INSTALL_ROOT!\bin\>nul
    verify>nul
    call copy/y framer.bat !_INSTALL_ROOT!\bin\>nul
    if errorlevel 1 (
        echo boom E: [gag]: 'copy/y framer.bat !_INSTALL_ROOT!\bin\>nul' failed - stop.
        set _exception=1
        goto :eof
    )
    if "!BOOM_TRACE!"=="1" echo copy/y srcdoc.d !_INSTALL_ROOT!\bin\>nul
    verify>nul
    call copy/y srcdoc.d !_INSTALL_ROOT!\bin\>nul
    if errorlevel 1 (
        echo boom E: [gag]: 'copy/y srcdoc.d !_INSTALL_ROOT!\bin\>nul' failed - stop.
        set _exception=1
        goto :eof
    )
    if "!BOOM_TRACE!"=="1" echo copy/y srcdoc.bat !_INSTALL_ROOT!\bin\>nul
    verify>nul
    call copy/y srcdoc.bat !_INSTALL_ROOT!\bin\>nul
    if errorlevel 1 (
        echo boom E: [gag]: 'copy/y srcdoc.bat !_INSTALL_ROOT!\bin\>nul' failed - stop.
        set _exception=1
        goto :eof
    )
    if exist installer.bat (
    if "!BOOM_TRACE!"=="1" echo installer
    verify>nul
    call installer
    if errorlevel 1 (
        echo boom E: [gag]: 'installer' failed - stop.
        set _exception=1
        goto :eof
    )
    )
    goto :eof

:-----------------------   PRODUCE ALL GENERATED FILES   ----------------------

:a_produce_all_generated_files
    echo boom I: [gag]: Generating files...
    if "!BOOM_TRACE!"=="1" echo lr -quiet framer.l
    verify>nul
    call lr -quiet framer.l
    if errorlevel 1 (
        echo boom E: [gag]: 'lr -quiet framer.l' failed - stop.
        set _exception=1
        goto :eof
    )
    if "!BOOM_TRACE!"=="1" echo lr -quiet srcdoc.l
    verify>nul
    call lr -quiet srcdoc.l
    if errorlevel 1 (
        echo boom E: [gag]: 'lr -quiet srcdoc.l' failed - stop.
        set _exception=1
        goto :eof
    )
    echo Source files successfully generated>stamp_generate
    goto :eof

:-------------------------   PRODUCE GENERATED FILES   ------------------------

:a_produce_generated_files
    echo boom I: [gag]: Generating files...
    if "!BOOM_TRACE!"=="1" echo lr -quiet framer.l
    verify>nul
    call lr -quiet framer.l
    if errorlevel 1 (
        echo boom E: [gag]: 'lr -quiet framer.l' failed - stop.
        set _exception=1
        goto :eof
    )
    if "!BOOM_TRACE!"=="1" echo lr -quiet srcdoc.l
    verify>nul
    call lr -quiet srcdoc.l
    if errorlevel 1 (
        echo boom E: [gag]: 'lr -quiet srcdoc.l' failed - stop.
        set _exception=1
        goto :eof
    )
    echo Source files successfully generated>stamp_generate
    goto :eof

:------------------------   REMOVE GENERATED SOURCES   ------------------------

:a_remove_generated_sources
    if exist framer.d del framer.d
    if exist srcdoc.d del srcdoc.d
    if exist stamp_generate del stamp_generate
    if exist gag_*.zip del gag_*.zip
    goto :eof

:-------------------------   REPORT HELP INFORMATION   ------------------------

:a_report_help_information
    echo The commands you can currently use on this project are:
    echo.
    goto r_!state!
    goto :eof

:-------------------------   REPORT PROJECT VERSION   -------------------------

:a_report_project_version
    echo gag-1.0
    goto :eof

:--------------------------   RUN REGRESSION TESTS   --------------------------

:a_run_regression_tests
    :-  Run local selftest script if present
    if exist selftest.bat (
    if "!BOOM_TRACE!"=="1" echo selftest
    verify>nul
    call selftest
    if errorlevel 1 (
        echo boom E: [gag]: 'selftest' failed - stop.
        set _exception=1
        goto :eof
    )
    )
    goto :eof

:-----------------------   USE SOURCE CONTROL REVISION   ----------------------

:a_use_source_control_revision
    set SVN_REVISION=svn
    if exist .svn
ul (
        for /f "usebackq tokens=1,2 delims=: " %%v in (`svn info`) do if "%%v"=="Revision" set SVN_REVISION=%%w
    )
    set MY_VERSION=!MY_VERSION!-!SVN_REVISION!
    goto :eof

:s_initial
    if "!debug!"=="1" echo State: initial
    if "!event!"=="" goto s_1_empty
    if "!event!"=="ok" goto s_1_1
    echo Unknown command - use one of:
    echo.
    goto r_!state!
:s_1_1
    if "!debug!"=="1" echo Event: ok
    set event=
    if "!debug!"=="1" echo Action: check operating context
    set _exception=
    call :a_check_operating_context
    if "!_exception!"=="1" exit /b 1
    set state=initial_check
    goto s_!state!
:s_1_empty
    if "!debug!"=="1" echo Get event from user
    set event=%1
    shift
    if "!event!"=="" set event=empty
    goto s_initial
:r_initial
    exit /b 0

:s_initial_check
    if "!debug!"=="1" echo State: initial check
    if "!event!"=="" goto s_2_empty
    if "!event!"=="repository" goto s_2_1
    if "!event!"=="source" goto s_2_2
    if "!event!"=="stripped" goto s_2_3
    echo Unknown command - use one of:
    echo.
    goto r_!state!
:s_2_1
    if "!debug!"=="1" echo Event: repository
    set event=
    set state=repository
    goto s_!state!
:s_2_2
    if "!debug!"=="1" echo Event: source
    set event=
    set state=source
    goto s_!state!
:s_2_3
    if "!debug!"=="1" echo Event: stripped
    set event=
    set state=stripped
    goto s_!state!
:s_2_empty
    if "!debug!"=="1" echo Get event from user
    set event=%1
    shift
    if "!event!"=="" set event=empty
    goto s_initial_check
:r_initial_check
    exit /b 0

:s_repository
    if "!debug!"=="1" echo State: repository
    if "!event!"=="" goto s_3_empty
    if "!event!"=="build" goto s_3_1
    if "!event!"=="compile" goto s_3_2
    if "!event!"=="clean" goto s_3_3
    if "!event!"=="regen" goto s_3_4
    if "!event!"=="allgen" goto s_3_5
    if "!event!"=="distrib" goto s_3_6
    if "!event!"=="distsrc" goto s_3_7
    if "!event!"=="distrev" goto s_3_8
    goto s_default
:s_3_1
    if "!debug!"=="1" echo Event: build
    set event=
    if "!debug!"=="1" echo Action: check project files exist
    set _exception=
    call :a_check_project_files_exist
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: produce generated files
    set _exception=
    call :a_produce_generated_files
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_3_2
    if "!debug!"=="1" echo Event: compile
    set event=
    if "!debug!"=="1" echo Action: check project files exist
    set _exception=
    call :a_check_project_files_exist
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_3_3
    if "!debug!"=="1" echo Event: clean
    set event=
    if "!debug!"=="1" echo Action: remove generated sources
    set _exception=
    call :a_remove_generated_sources
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_3_4
    if "!debug!"=="1" echo Event: regen
    set event=
    if "!debug!"=="1" echo Action: check project files exist
    set _exception=
    call :a_check_project_files_exist
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: produce generated files
    set _exception=
    call :a_produce_generated_files
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_3_5
    if "!debug!"=="1" echo Event: allgen
    set event=
    if "!debug!"=="1" echo Action: check project files exist
    set _exception=
    call :a_check_project_files_exist
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: produce all generated files
    set _exception=
    call :a_produce_all_generated_files
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_3_6
    if "!debug!"=="1" echo Event: distrib
    set event=
    if "!debug!"=="1" echo Action: produce all generated files
    set _exception=
    call :a_produce_all_generated_files
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: check all source files exist
    set _exception=
    call :a_check_all_source_files_exist
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: build source packages
    set _exception=
    call :a_build_source_packages
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_3_7
    if "!debug!"=="1" echo Event: distsrc
    set event=
    if "!debug!"=="1" echo Action: produce all generated files
    set _exception=
    call :a_produce_all_generated_files
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: check all source files exist
    set _exception=
    call :a_check_all_source_files_exist
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: build source packages
    set _exception=
    call :a_build_source_packages
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_3_8
    if "!debug!"=="1" echo Event: distrev
    set event=
    if "!debug!"=="1" echo Action: produce all generated files
    set _exception=
    call :a_produce_all_generated_files
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: check source files exist
    set _exception=
    call :a_check_source_files_exist
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: use source control revision
    set _exception=
    call :a_use_source_control_revision
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: build source packages
    set _exception=
    call :a_build_source_packages
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_3_empty
    if "!debug!"=="1" echo Get event from user
    set event=%1
    shift
    if "!event!"=="" set event=empty
    goto s_repository
:r_repository
echo build:
    echo   From the raw project sources, produces all generated files.
echo compile:
    echo   Has no effect, provided for consistency with other workflows.
echo clean:
    echo   Removes all generated source files from the project directory.
echo regen:
    echo   Produces generated files required for building using the
    echo     current model.
echo allgen:
    echo   Produces all generated files.
echo distrib:
    echo   Creates a source distribution for the project.
echo distsrc:
    echo   Equivalent to distrib, provided for compatibility.
echo distrev:
    echo   Creates a source distribution for the project.  Builds distribution
    echo     packages based on source control version number. Note that binary
    echo     distributions can only be created at the product level.
    goto r_default

:s_source
    if "!debug!"=="1" echo State: source
    if "!event!"=="" goto s_4_empty
    if "!event!"=="build" goto s_4_1
    if "!event!"=="clean" goto s_4_2
    if "!event!"=="regen" goto s_4_3
    if "!event!"=="allgen" goto s_4_4
    goto s_default
:s_4_1
    if "!debug!"=="1" echo Event: build
    set event=
    if "!debug!"=="1" echo Action: check project files exist
    set _exception=
    call :a_check_project_files_exist
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_4_2
    if "!debug!"=="1" echo Event: clean
    set event=
    if not "%1"=="" goto process
    exit /b 0
:s_4_3
    if "!debug!"=="1" echo Event: regen
    set event=
    if "!debug!"=="1" echo Action: check project files exist
    set _exception=
    call :a_check_project_files_exist
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: produce generated files
    set _exception=
    call :a_produce_generated_files
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_4_4
    if "!debug!"=="1" echo Event: allgen
    set event=
    if "!debug!"=="1" echo Action: check project files exist
    set _exception=
    call :a_check_project_files_exist
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: produce all generated files
    set _exception=
    call :a_produce_all_generated_files
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_4_empty
    if "!debug!"=="1" echo Get event from user
    set event=%1
    shift
    if "!event!"=="" set event=empty
    goto s_source
:r_source
echo build:
    echo   When working with the packaged sources, does nothing.
echo clean:
    echo   Has no effect, provided for consistency with other workflows.
echo regen:
    echo   Produces generated files required for building using the
    echo     current model.
echo allgen:
    echo   Produces all generated files.
    goto r_default

:s_stripped
    if "!debug!"=="1" echo State: stripped
    if "!event!"=="" goto s_5_empty
    if "!event!"=="build" goto s_5_1
    if "!event!"=="clean" goto s_5_2
    goto s_default
:s_5_1
    if "!debug!"=="1" echo Event: build
    set event=
    if "!debug!"=="1" echo Action: check project files exist
    set _exception=
    call :a_check_project_files_exist
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_5_2
    if "!debug!"=="1" echo Event: clean
    set event=
    if not "%1"=="" goto process
    exit /b 0
:s_5_empty
    if "!debug!"=="1" echo Get event from user
    set event=%1
    shift
    if "!event!"=="" set event=empty
    goto s_stripped
:r_stripped
echo build:
    echo   When working with the packaged sources, does nothing.
echo clean:
    echo   Has no effect, provided for consistency with other workflows.
    goto r_default

:s_default
    if "!debug!"=="1" echo State: default
    if "!event!"=="" goto s_6_empty
    if "!event!"=="install" goto s_6_1
    if "!event!"=="test" goto s_6_2
    if "!event!"=="help" goto s_6_3
    if "!event!"=="version" goto s_6_4
    if "!event!"=="empty" goto s_6_5
    echo Unknown command - use one of:
    echo.
    goto r_!state!
:s_6_1
    if "!debug!"=="1" echo Event: install
    set event=
    if "!debug!"=="1" echo Action: check source files exist
    set _exception=
    call :a_check_source_files_exist
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: install deliverables
    set _exception=
    call :a_install_deliverables
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_6_2
    if "!debug!"=="1" echo Event: test
    set event=
    if "!debug!"=="1" echo Action: check source files exist
    set _exception=
    call :a_check_source_files_exist
    if "!_exception!"=="1" exit /b 1
    if "!debug!"=="1" echo Action: run regression tests
    set _exception=
    call :a_run_regression_tests
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_6_3
    if "!debug!"=="1" echo Event: help
    set event=
    if "!debug!"=="1" echo Action: report help information
    set _exception=
    call :a_report_help_information
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_6_4
    if "!debug!"=="1" echo Event: version
    set event=
    if "!debug!"=="1" echo Action: report project version
    set _exception=
    call :a_report_project_version
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_6_5
    if "!debug!"=="1" echo Event: empty
    set event=
    if "!debug!"=="1" echo Action: report help information
    set _exception=
    call :a_report_help_information
    if "!_exception!"=="1" exit /b 1
    if not "%1"=="" goto process
    exit /b 0
:s_6_empty
    if "!debug!"=="1" echo Get event from user
    set event=%1
    shift
    if "!event!"=="" set event=empty
    goto s_default
:r_default
echo install:
    echo   Installs deliverables into the final or temporary install tree.
echo test:
    echo   Runs regression tests for the project.
echo help:
    echo   Shows a list of the commands allowed on the project.
echo version:
    echo   Show project version.
    exit /b 0


exit /b 0
