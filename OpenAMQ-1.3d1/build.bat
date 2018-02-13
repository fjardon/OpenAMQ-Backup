@echo off
:-  Build and install OpenAMQ 1.3d1 and dependent products

:-  Set the IBASE variable to the installation directory
if "%IBASE%"=="" (
    echo The IBASE environment variable is not defined.
    echo Set this to desired installation directory, e.g. c:ibase.
    echo Then, add ^%IBASE^%/bin to your PATH for best results.
    exit /b 1
)

:-  Build foreign
cd foreign
call boomake build test install
if errorlevel 1 (
    echo E: Build of foreign failed
    exit /b 1
)
cd ..

:-  Build base1
cd base1
call boomake build test install
if errorlevel 1 (
    echo E: Build of base1 failed
    exit /b 1
)
cd ..

:-  Build gsl4
cd gsl4
call boomake build test install
if errorlevel 1 (
    echo E: Build of gsl4 failed
    exit /b 1
)
cd ..

:-  Build base2
cd base2
call boomake build test install
if errorlevel 1 (
    echo E: Build of base2 failed
    exit /b 1
)
cd ..

:-  Build openamq
cd openamq
call boomake build test install
if errorlevel 1 (
    echo E: Build of openamq failed
    exit /b 1
)
cd ..

:-  Done successfully
echo Finished building and installing OpenAMQ 1.3d1.

