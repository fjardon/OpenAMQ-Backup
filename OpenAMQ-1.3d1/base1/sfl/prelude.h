/*===========================================================================*
 *                                                                           *
 *  prelude.h - Portability abstraction header file                          *
 *                                                                           *
 *  Copyright (c) 1991-2009 iMatix Corporation                               *
 *                                                                           *
 *  ------------------ GPL Licensed Source Code ------------------           *
 *  iMatix makes this software available under the GNU General               *
 *  Public License (GPL) license for open source projects.  For              *
 *  details of the GPL license please see www.gnu.org or read the            *
 *  file license.gpl provided in this package.                               *
 *                                                                           *
 *  This program is free software; you can redistribute it and/or            *
 *  modify it under the terms of the GNU General Public License as           *
 *  published by the Free Software Foundation; either version 2 of           *
 *  the License, or (at your option) any later version.                      *
 *                                                                           *
 *  This program is distributed in the hope that it will be useful,          *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU General Public License for more details.                             *
 *                                                                           *
 *  You should have received a copy of the GNU General Public                *
 *  License along with this program in the file 'license.gpl'; if            *
 *  not, write to the Free Software Foundation, Inc., 59 Temple              *
 *  Place - Suite 330, Boston, MA 02111-1307, USA.                           *
 *                                                                           *
 *  You can also license this software under iMatix's General Terms          *
 *  of Business (GTB) for commercial projects.  If you have not              *
 *  explicitly licensed this software under the iMatix GTB you may           *
 *  only use it under the terms of the GNU General Public License.           *
 *                                                                           *
 *  For more information, send an email to info@imatix.com.                  *
 *  --------------------------------------------------------------           *
 *===========================================================================*/

/*  ----------------------------------------------------------------<Prolog>-
    Synopsis:   This header file encapsulates many generally-useful include
                files and defines lots of good stuff.  The intention of this
                header file is to hide the messy #ifdef's that you typically
                need to make real programs compile & run.  To use, specify
                as the first include file in your program.
 ------------------------------------------------------------------</Prolog>-*/

#ifndef PRELUDE_INCLUDED               /*  Allow multiple inclusions        */
#define PRELUDE_INCLUDED


/*- Establish the compiler and computer system ------------------------------*/
/*
 *  Defines zero or more of these symbols, for use in any non-portable
 *  code:
 *
 *  __WINDOWS__         Microsoft C/C++ with Windows calls
 *  __MSDOS__           System is MS-DOS (set if __WINDOWS__ set)
 *  __VMS__             System is VAX/VMS or Alpha/OpenVMS
 *  __UNIX__            System is UNIX
 *  __OS2__             System is OS/2
 *
 *  __IS_32BIT__        OS/compiler is 32 bits
 *  __IS_64BIT__        OS/compiler is 64 bits
 *
 *  When __UNIX__ is defined, we also define exactly one of these:
 *
 *  __UTYPE_AUX         Apple AUX
 *  __UTYPE_BEOS        BeOS
 *  __UTYPE_BSDOS       BSD/OS
 *  __UTYPE_DECALPHA    Digital UNIX (Alpha)
 *  __UTYPE_IBMAIX      IBM RS/6000 AIX
 *  __UTYPE_FREEBSD     FreeBSD
 *  __UTYPE_HPUX        HP/UX
 *  __UTYPE_LINUX       Linux
 *  __UTYPE_MIPS        MIPS (BSD 4.3/System V mixture)
 *  __UTYPE_NETBSD      NetBSD
 *  __UTYPE_NEXT        NeXT
 *  __UTYPE_OPENBSD     OpenBSD
 *  __UTYPE_OSX         Apple Macintosh OS X
 *  __UTYPE_QNX         QNX
 *  __UTYPE_SCO         SCO Unix
 *  __UTYPE_IRIX        Silicon Graphics IRIX
 *  __UTYPE_SINIX       SINIX-N (Siemens-Nixdorf Unix)
 *  __UTYPE_SUNOS       SunOS
 *  __UTYPE_SUNSOLARIS  Sun Solaris
 *  __UTYPE_UNIXWARE    SCO UnixWare
 *                      ... these are the ones I know about so far.
 *  __UTYPE_GENERIC     Any other UNIX
 *
 *  When __VMS__ is defined, we may define one or more of these:
 *
 *  __VMS_XOPEN         Supports XOPEN functions
 */

#if (defined (__64BIT__) || defined (__x86_64__))
#    define __IS_64BIT__                /*  May have 64-bit OS/compiler      */
#else
#    define __IS_32BIT__                /*  Else assume 32-bit OS/compiler   */
#endif

#if (defined WIN32 || defined _WIN32)
#   undef __WINDOWS__
#   define __WINDOWS__
#   undef __MSDOS__
#   define __MSDOS__
#endif

#if (defined WINDOWS || defined _WINDOWS || defined __WINDOWS__)
#   undef __WINDOWS__
#   define __WINDOWS__
#   undef __MSDOS__
#   define __MSDOS__
#endif

/*  MSDOS               Microsoft C                                          */
/*  _MSC_VER            Microsoft C                                          */
/*  __TURBOC__          Borland Turbo C                                      */
#if (defined (MSDOS) || defined (_MSC_VER) || defined (__TURBOC__))
#   undef __MSDOS__
#   define __MSDOS__
#   if (defined (_DEBUG) && !defined (DEBUG))
#       define DEBUG
#   endif
#endif

#if (defined (__EMX__) && defined (__i386__))
#   undef __OS2__
#   define __OS2__
#endif

/*  VMS                 VAX C (VAX/VMS)                                      */
/*  __VMS               Dec C (Alpha/OpenVMS)                                */
/*  __vax__             gcc                                                  */
#if (defined (VMS) || defined (__VMS) || defined (__vax__))
#   undef __VMS__
#   define __VMS__
#   if (__VMS_VER >= 70000000)
#       define __VMS_XOPEN
#   endif
#endif

/*  Try to define a __UTYPE_xxx symbol...                                    */
/*  unix                SunOS at least                                       */
/*  __unix__            gcc                                                  */
/*  _POSIX_SOURCE is various UNIX systems, maybe also VAX/VMS                */
#if (defined (unix) || defined (__unix__) || defined (_POSIX_SOURCE))
#   if (!defined (__VMS__))
#       undef __UNIX__
#       define __UNIX__
#       if (defined (__alpha))          /*  Digital UNIX is 64-bit           */
#           undef  __IS_32BIT__
#           define __IS_64BIT__
#           define __UTYPE_DECALPHA
#       endif
#   endif
#endif

#if (defined (_AUX))
#   define __UTYPE_AUX
#   define __UNIX__
#elif (defined (__BEOS__))
#   define __UTYPE_BEOS
#   define __UNIX__
#elif (defined (__hpux))
#   define __UTYPE_HPUX
#   define __UNIX__
#   define _INCLUDE_HPUX_SOURCE
#   define _INCLUDE_XOPEN_SOURCE
#   define _INCLUDE_POSIX_SOURCE
#elif (defined (_AIX) || defined (AIX))
#   define __UTYPE_IBMAIX
#   define __UNIX__
#elif (defined (BSD) || defined (bsd))
#   define __UTYPE_BSDOS
#   define __UNIX__
#elif (defined (linux))
#   define __UTYPE_LINUX
#   define __UNIX__
#   define __NO_CTYPE                   /*  Suppress warnings on tolower()   */
#elif (defined (Mips))
#   define __UTYPE_MIPS
#   define __UNIX__
#elif (defined (FreeBSD) || defined (__FreeBSD__))
#   define __UTYPE_FREEBSD
#   define __UNIX__
#elif (defined (NetBSD) || defined (__NetBSD__))
#   define __UTYPE_NETBSD
#   define __UNIX__
#elif (defined (OpenBSD) || defined (__OpenBSD__))
#   define __UTYPE_OPENBSD
#   define __UNIX__
#elif (defined (__APPLE__))
#   define __UTYPE_OSX
#   define __UNIX__
#elif (defined (NeXT))
#   define __UTYPE_NEXT
#   define __UNIX__
#elif (defined (__QNX__))
#   define __UTYPE_QNX
#   define __UNIX__
#elif (defined (sco))
#   define __UTYPE_SCO
#   define __UNIX__
#elif (defined (sgi))
#   define __UTYPE_IRIX
#   define __UNIX__
#elif (defined (sinix))
#   define __UTYPE_SINIX
#   define __UNIX__
#elif (defined (SOLARIS) || defined (__SRV4))
#   define __UTYPE_SUNSOLARIS
#   define __UNIX__
#elif (defined (SUNOS) || defined (SUN) || defined (sun))
#   define __UTYPE_SUNOS
#   define __UNIX__
#elif (defined (__USLC__) || defined (UnixWare))
#   define __UTYPE_UNIXWARE
#   define __UNIX__
#elif (defined (__CYGWIN__))
#   define __UTYPE_CYGWIN
#   define __UNIX__
#elif (defined (__UNIX__))
#   define __UTYPE_GENERIC
#endif

/*- Standard ANSI include files ---------------------------------------------*/

#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <float.h>
#include <math.h>
#include <signal.h>
#include <setjmp.h>


/*- System-specific include files -------------------------------------------*/

#if (defined (__MSDOS__))
#   if (defined (__WINDOWS__))          /*  When __WINDOWS__ is defined,     */
#       define FD_SETSIZE     1024      /*  Max. filehandles/sockets         */
#       include <direct.h>
#       include <windows.h>  
#       include <winsock.h>             /*  May cause trouble on VC 1.x      */
#       include <process.h>   
#   endif
#   if (defined (__TURBOC__))
#       include <dir.h>
#       include <alloc.h>               /*  Okay for Turbo C                 */
#   else
#       include <malloc.h>              /*  But will it work for others?     */
#   endif
#   include <dos.h>
#   include <io.h>
#   include <fcntl.h>
#   include <sys\types.h>
#   include <sys\stat.h>
#   include <sys\utime.h>
#   include <share.h>
#endif

#if (defined (__UNIX__))
#   if defined (__GNUC__) && (__GNUC__ >= 2)
#       define __STRICT_ANSI__
#   endif
#   include <fcntl.h>
#   include <netdb.h>
#   include <unistd.h>
#   include <dirent.h>
#   include <pwd.h>
#   include <grp.h>
#   include <utime.h>
#   include <sys/types.h>
#   include <sys/param.h>
#   include <sys/socket.h>
#   include <sys/time.h>
#   include <sys/stat.h>
#   include <sys/ioctl.h>
#   include <sys/file.h>
#   include <sys/wait.h>
#   include <netinet/in.h>              /*  Must come before arpa/inet.h     */
#   if (!defined (__UTYPE_BEOS))
#       include <arpa/inet.h>
#       if (!defined (TCP_NODELAY))
#           include <netinet/tcp.h>
#       endif
#   endif
#   if (defined (__UTYPE_IBMAIX) || defined(__UTYPE_QNX))
#       include <sys/select.h>
#   endif
#   if (defined (__UTYPE_BEOS))
#       include <NetKit.h>
#   endif
#   if ((defined (_XOPEN_REALTIME) && (_XOPEN_REALTIME >= 1)) || \
        (defined (_POSIX_VERSION)  && (_POSIX_VERSION  >= 199309L)))
#       include <sched.h>
#   endif
#   if (defined (__UTYPE_OSX))
#       include <crt_externs.h>         /* For _NSGetEnviron()               */
#   endif
#endif

#if (defined (__VMS__))
#   if (!defined (vaxc))
#       include <fcntl.h>               /*  Not provided by Vax C            */
#   endif
#   include <netdb.h>
#   include <unistd.h>
#   include <unixio.h>
#   include <unixlib.h>
#   include <types.h>
#   include <file.h>
#   include <socket.h>
#   include <dirent.h>
#   include <time.h>
#   include <pwd.h>
#   include <stat.h>
#   include <in.h>
#   include <inet.h>
#endif

#if (defined (__OS2__))
#   include <sys/types.h>               /*  Required near top                    */
#   include <fcntl.h>
#   include <malloc.h>
#   include <netdb.h>
#   include <unistd.h>
#   include <dirent.h>
#   include <pwd.h>
#   include <grp.h>
#   include <io.h>
#   include <process.h>
#   include <sys/param.h>
#   include <sys/socket.h>
#   include <sys/select.h>
#   include <sys/time.h>
#   include <sys/stat.h>
#   include <sys/ioctl.h>
#   include <sys/file.h>
#   include <sys/wait.h>
#   include <netinet/in.h>              /*  Must come before arpa/inet.h     */
#   include <arpa/inet.h>
#   include <utime.h>
#   if (!defined (TCP_NODELAY))
#       include <netinet/tcp.h>
#   endif
#endif


/*- Data types --------------------------------------------------------------*/

typedef unsigned short  Bool;           /*  Boolean TRUE/FALSE value         */
typedef unsigned char   byte;           /*  Single unsigned byte = 8 bits    */
typedef unsigned short  dbyte;          /*  Double byte = 16 bits            */
typedef unsigned short  word;           /*  Alternative for double-byte      */
typedef unsigned long   dword;          /*  Double word >= 32 bits           */
#if (defined (__IS_32BIT__))
typedef unsigned long   qbyte;          /*  Quad byte = 32 bits              */
#else
typedef unsigned int    qbyte;          /*  Quad byte = 32 bits              */
#endif
typedef void (*function) (void);        /*  Address of simple function       */
#define local static void               /*  Shorthand for local functions    */

typedef struct {                        /*  Memory descriptor                */
    size_t size;                        /*    Size of data part              */
    byte  *data;                        /*    Data part follows here         */
} DESCR;

typedef struct {                        /*  Variable-size descriptor         */
    size_t max_size;                    /*    Maximum size of data part      */
    size_t cur_size;                    /*    Current size of data part      */
    byte  *data;                        /*    Data part follows here         */
} VDESCR;

/*  ATTENTION: a VDESCR is always a DESCR plus max_size in front!
    All functions that accept a DESCR can also be passed a VDESCR using
    this macro                                                               */
#define UNVDESCR(v)     (DESCR *)((size_t *)(v) + 1)


/*- Check compiler data type sizes ------------------------------------------*/

#if (UCHAR_MAX != 0xFF)
#   error "Cannot compile: must change definition of 'byte'."
#endif
#if (USHRT_MAX != 0xFFFFU)
#    error "Cannot compile: must change definition of 'dbyte'."
#endif
#if (defined (__IS_32BIT__))
#   if (ULONG_MAX != 0xFFFFFFFFUL)
#       error "Cannot compile: must change definition of 'qbyte'."
#   endif
#else
#   if (UINT_MAX != 0xFFFFFFFFU)
#       error "Cannot compile: must change definition of 'qbyte'."
#   endif
#endif


/*- Pseudo-functions --------------------------------------------------------*/

#define FOREVER         for (;;)            /*  FOREVER { ... }              */
#define until(expr)     while (!(expr))     /*  do { ... } until (expr)      */
#define streq(s1,s2)    (!strcmp ((s1), (s2)))
#define strneq(s1,s2)   (strcmp ((s1), (s2)))
#define strused(s)      (*(s) != 0)
#define strnull(s)      (*(s) == 0)
#define strclr(s)       (*(s) = 0)
#define strlast(s)      ((s) [strlen (s) - 1])
#define strterm(s)      ((s) [strlen (s)])

#define bit_msk(bit)    (1 << (bit))
#define bit_set(x,bit)  ((x) |=  bit_msk (bit))
#define bit_clr(x,bit)  ((x) &= ~bit_msk (bit))
#define bit_tst(x,bit)  ((x) &   bit_msk (bit))

#define tblsize(x)      (sizeof (x) / sizeof ((x) [0]))
#define tbllast(x)      (x [tblsize (x) - 1])

#if (!defined (random))
#   define random(num)     (int) ((float) num * rand () / (RAND_MAX + 1.0))
#   define randomize()     srand ((unsigned) time (NULL))
#endif
#if (!defined (min))
#   define min(a,b)        (((a) < (b))? (a): (b))
#   define max(a,b)        (((a) > (b))? (a): (b))
#endif


/*- ASSERT ------------------------------------------------------------------*/
/*  If DEBUG is defined, the ASSERT macro aborts if the specified condition
 *  is false.  Note that you must include sflsyst.c in your application, for
 *  the sys_assert() function.
 */
#if (defined (DEBUG))
#   ifdef __cplusplus
extern "C" {
#   endif
void  sys_assert  (const char *filename, unsigned line_number);
#   undef  ASSERT
#   define ASSERT(f)    \
        if (f)          \
            ;           \
        else            \
            sys_assert (__FILE__, __LINE__)
#   ifdef __cplusplus
};
#   endif
#else
#   define ASSERT(f)
#endif


/*- Boolean operators and constants -----------------------------------------*/

#if (!defined (TRUE))
#    define TRUE        1               /*  ANSI standard                    */
#    define FALSE       0
#endif


/*- Symbolic constants ------------------------------------------------------*/

#define FORK_ERROR      -1              /*  Return codes from fork()         */
#define FORK_CHILD      0

#undef  LINE_MAX
#define LINE_MAX        1024            /*  Length of line from text file    */

#if (!defined (PATH_MAX))               /*  Length of path variable          */
#   define PATH_MAX     2048            /*    if not previously #define'd    */
#endif                                  /*  EDM 96/05/28                     */

#if (!defined (EXIT_SUCCESS))           /*  ANSI, and should be in stdlib.h  */
#   define EXIT_SUCCESS 0               /*    but not defined on SunOs with  */
#   define EXIT_FAILURE 1               /*    GCC, sometimes.                */
#endif


/*- System-specific definitions ---------------------------------------------*/
/*  Most of these are to bring older systems up to an acceptable POSIX or
    C99 standard.
 */

/*  A number of C99 keywords and data types                                  */
#if (defined (__WINDOWS__))
#   define inline __inline
    typedef unsigned int uint;
    typedef __int64 int64_t;
#elif (defined (__VMS__))
    typedef __int64 int64_t;
#endif

/*  On most systems, 'timezone' is an external long variable.  On a few, it
 *  is a function that returns a string.  We define TIMEZONE to be the long
 *  value.                                                                   */

#undef  TIMEZONE
#if (defined (__WINDOWS__) || defined (__CYGWIN__))
#   define TIMEZONE   _timezone
#else
#   define TIMEZONE    timezone         /*  Unless redefined later           */
#endif

/*  UNIX defines sleep() in terms of second; Win32 defines Sleep() in
 *  terms of milliseconds.  We want to be able to use sleep() anywhere.      */

#if (defined (__WINDOWS__))
#   undef sleep
#   if (defined (WIN32))
#       define sleep(a) Sleep(a*1000)   /*  UNIX sleep() is seconds          */
#   else
#       define sleep(a)                 /*  Do nothing?                      */
#   endif
    /*  MSVC 1.x does not define standard signals if in Windows              */
#   if (!defined (SIGINT))
#   define SIGINT       2               /*  Ctrl-C sequence                  */
#   define SIGILL       4               /*  Illegal instruction              */
#   define SIGSEGV      11              /*  Segment violation                */
#   define SIGTERM      15              /*  Kill signal                      */
#   define SIGABRT      22              /*  Termination by abort()           */
#   endif
    /*  MSVC 4.x does not define SIGALRM, so we pinch SIGFPE                 */
#   if (!defined (SIGALRM))
#   define SIGALRM      SIGFPE          /*  Must be a known signal           */
#   endif
#   if (defined __TURBOC__)
        extern char   **environ;        /*  Not defined in include files     */
#   endif

/*  On SunOs, the ANSI C compiler costs extra, so many people install gcc
 *  but using the standard non-ANSI C library.  We have to make a few extra
 *  definitions for this case.  (Here we defined just what we needed for
 *  Libero and SMT -- we'll add more code as required.)                      */

#elif (defined (__UTYPE_SUNOS) || defined (__UTYPE_SUNSOLARIS))
#   if (!defined (_SIZE_T))             /*  Non-ANSI headers/libraries       */
#       define strerror(n)      sys_errlist [n]
#       define memmove(d,s,l)   bcopy (s,d,l)
        extern char *sys_errlist [];
#   endif

#elif (defined (__UTYPE_BSDOS) || defined (__UTYPE_FREEBSD) \
    || defined (__UTYPE_NETBSD) || defined (__UTYPE_OPENBSD) \
    || defined (__UTYPE_OSX))
#   undef  TIMEZONE

#elif (defined (__VMS__))
    /*  This data structure is often used in OpenVMS library functions       */
    typedef struct {                    /*  Fixed-string descriptor:         */
        word  length;                   /*    Length of string in bytes      */
        byte  dtype;                    /*    Must be DSC$K_DTYPE_T = 14     */
        byte  class;                    /*    Must be DSC$K_CLASS_S = 1      */
        char *value;                    /*    Address of start of string     */
    } STRING_DESC;
    #define VMS_STRING(name,value) STRING_DESC name = \
                                        { sizeof (value) - 1, 14, 1, value }
#endif

#if (defined (__UNIX__) || defined (__VMS__))
#   if (defined (__UTYPE_OSX))
#       define environ (* _NSGetEnviron())
#   else
        extern char **environ;          /*  Not defined in include files     */
#   endif
#endif

#if (!defined (SFL_STDIN_FILENO))
#   if (defined (__WINDOWS__))
#       define SFL_STDIN_FILENO   _fileno (stdin)
#       define SFL_STDOUT_FILENO  _fileno (stdout)
#       define SFL_STDERR_FILENO  _fileno (stderr)
#   else
#       define SFL_STDIN_FILENO   STDIN_FILENO
#       define SFL_STDOUT_FILENO  STDOUT_FILENO
#       define SFL_STDERR_FILENO  STDERR_FILENO
#   endif
#endif

/*  On some systems (older Vaxen and Unixes) O_BINARY is not defined.        */

#if (!defined (O_BINARY))
#   define O_BINARY     0
#endif

/*  On some systems SIGALRM is not defined; we allow it in code anyhow       */

#if (!defined (SIGALRM))
#   define SIGALRM      1
#endif

/*  On some systems O_NDELAY is used instead of O_NONBLOCK                   */

#if (!defined (O_NONBLOCK))
#   if (!defined (O_NDELAY))
#       define O_NDELAY 0
#   endif
#   if (defined (__VMS__))
#       define O_NONBLOCK 0             /*  Can't use O_NONBLOCK on files    */
#   else
#       define O_NONBLOCK O_NDELAY
#   endif
#endif

/*  We define constants for the way the current system formats filenames;
 *  we assume that the system has some type of path concept.                 */

#if (defined (WIN32))                   /*  Windows 95/NT                    */
#   define PATHSEP      ";"             /*  Separates path components        */
#   define PATHEND      '\\'            /*  Delimits directory and filename  */
#   define PATHFOLD     FALSE           /*  Convert pathvalue to uppercase?  */
#   define NAMEFOLD     FALSE           /*  Convert filenames to uppercase?  */
#   define GATES_FILESYSTEM             /*  MS-DOS derivative                */
#elif (defined (__MSDOS__))             /*  16-bit Windows, MS-DOS           */
#   define PATHSEP      ";"
#   define PATHEND      '\\'
#   if defined LFN                      /*  Support DRDOS long file names    */
#       define PATHFOLD FALSE
#       define NAMEFOLD FALSE
#   else
#       define PATHFOLD TRUE
#       define NAMEFOLD TRUE
#   endif
#   define GATES_FILESYSTEM             /*  MS-DOS derivative                */
#elif (defined (__VMS__))               /*  Digital OpenVMS                  */
#   define PATHSEP      ","             /*    We work with POSIX filenames   */
#   define PATHEND      '/'
#   define PATHFOLD     TRUE
#   define NAMEFOLD     TRUE
#elif (defined (__UNIX__))              /*  All UNIXes                       */
#   define PATHSEP      ":"
#   define PATHEND      '/'
#   define PATHFOLD     FALSE
#   define NAMEFOLD     FALSE
#elif (defined (__OS2__))               /*  OS/2 using EMX/GCC               */
#   define PATHSEP      ";"             /*  EDM 96/05/28                     */
#   define PATHEND      '\\'
#   define PATHFOLD     TRUE
#   define NAMEFOLD     FALSE
#   define GATES_FILESYSTEM             /*  MS-DOS derivative                */
#else
#   error "No definitions for PATH constants"
#endif


/*- Capability definitions --------------------------------------------------*/
/*
 *  Defines zero or more of these symbols, for use in any non-portable
 *  code:
 *
 *  DOES_SOCKETS         We can use (at least some) BSD socket functions
 *  DOES_UID             We can use (at least some) uid access functions
 *  DOES_SNPRINTF        Supports snprintf and vsnprintf functions
 *  DOES_BSDSIGNALS      Supports BSD signal model (e.g. siginterrupt)
 *  DOES_SETENV          Supports setenv/unsetenv (else we provide our own)
 */

#if (defined (AF_INET))
#   define DOES_SOCKETS                 /*  System supports BSD sockets      */
#else
#   undef  DOES_SOCKETS
#endif

#if (defined (__UNIX__) || defined (__VMS__) || defined (__OS2__))
#   define DOES_UID                     /*  System supports uid functions    */
#else
#   undef  DOES_UID
    typedef int gid_t;                  /*  Group id type                    */
    typedef int uid_t;                  /*  User id type                     */
#endif

#if (defined (__OS2__) || defined (__UTYPE_SCO) || defined (__UTYPE_LINUX) \
 || defined(__UTYPE_OSX) ||  defined (__CYGWIN__))
#   define DOES_SNPRINTF
#elif (defined (__WINDOWS__))
#   define DOES_SNPRINTF
#   define snprintf  _snprintf
#   define vsnprintf _vsnprintf
#else
#   undef DOES_SNPRINTF
#endif

/*  SunOS 5 (Solaris) does not support BSD-style signal handling             */
#if (!defined (__UTYPE_SUNSOLARIS))
#   define DOES_BSDSIGNALS
#else
#   undef  DOES_BSDSIGNALS
#endif

#endif                                  /*  Include PRELUDE.H                */
