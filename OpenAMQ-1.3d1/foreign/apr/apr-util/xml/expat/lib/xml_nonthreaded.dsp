# Microsoft Developer Studio Project File - Name="xml_nonthreaded" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=xml_nonthreaded - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "xml_nonthreaded.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "xml_nonthreaded.mak" CFG="xml_nonthreaded - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "xml_nonthreaded - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "xml_nonthreaded - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "xml_nonthreaded - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "LibR"
# PROP BASE Intermediate_Dir "LibR"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "LibR"
# PROP Intermediate_Dir "LibR"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FD /c
# ADD CPP /nologo /MD /W3 /O2 /Oy- /Zi /I "." /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D VERSION=\"expat_1.95.1\" /D XML_MAJOR_VERSION=1 /D XML_MINOR_VERSION=95 /D XML_MICRO_VERSION=1 /Fd"LibR\xml_src" /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "xml_nonthreaded - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "LibD"
# PROP BASE Intermediate_Dir "LibD"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "LibD"
# PROP Intermediate_Dir "LibD"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FD /c
# ADD CPP /nologo /MDd /W3 /GX /Zi /Od /I "." /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D VERSION=\"expat_1.95.1\" /D XML_MAJOR_VERSION=1 /D XML_MINOR_VERSION=95 /D XML_MICRO_VERSION=1 /Fd"LibD\xml_src" /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "xml_nonthreaded - Win32 Release"
# Name "xml_nonthreaded - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\xmlparse.c
# End Source File
# Begin Source File

SOURCE=.\xmlrole.c
# End Source File
# Begin Source File

SOURCE=.\xmltok.c
# End Source File
# Begin Source File

SOURCE=xmltok_impl.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=xmltok_ns.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ascii.h
# End Source File
# Begin Source File

SOURCE=.\asciitab.h
# End Source File
# Begin Source File

SOURCE=.\config.h
# End Source File
# Begin Source File

SOURCE=.\expat.h
# End Source File
# Begin Source File

SOURCE=.\iasciitab.h
# End Source File
# Begin Source File

SOURCE=.\latin1tab.h
# End Source File
# Begin Source File

SOURCE=.\nametab.h
# End Source File
# Begin Source File

SOURCE=.\utf8tab.h
# End Source File
# Begin Source File

SOURCE=.\xmlrole.h
# End Source File
# Begin Source File

SOURCE=.\xmltok.h
# End Source File
# Begin Source File

SOURCE=.\xmltok_impl.h
# End Source File
# End Group
# Begin Group "Generated Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\expat.h.in

!IF  "$(CFG)" == "xml_nonthreaded - Win32 Release"

# Begin Custom Build - Creating expat.h from expat.h.in 
InputPath=.\expat.h.in

".\expat.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	type .\expat.h.in > .\expat.h
	
# End Custom Build

!ELSEIF  "$(CFG)" == "xml_nonthreaded - Win32 Debug"

# Begin Custom Build - Creating expat.h from expat.h.in 
InputPath=.\expat.h.in

".\expat.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	type .\expat.h.in > .\expat.h
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\winconfig.h

!IF  "$(CFG)" == "xml_nonthreaded - Win32 Release"

# Begin Custom Build - Creating config.h from winconfig.h 
InputPath=.\winconfig.h

".\config.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	type .\winconfig.h > .\config.h
	
# End Custom Build

!ELSEIF  "$(CFG)" == "xml_nonthreaded - Win32 Debug"

# Begin Custom Build - Creating config.h from winconfig.h 
InputPath=.\winconfig.h

".\config.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	type .\winconfig.h > .\config.h
	
# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
