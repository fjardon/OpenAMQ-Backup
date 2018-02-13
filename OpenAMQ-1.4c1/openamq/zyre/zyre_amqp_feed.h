/*---------------------------------------------------------------------------
    zyre_amqp_feed.h - zyre_amqp_feed component

  Implements the bare feed object for use in the AMQP backend cache.
    Generated from zyre_amqp_feed.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_ZYRE_AMQP_FEED_SAFE
#   define INCLUDE_ZYRE_AMQP_FEED_SAFE
#   define INCLUDE_ZYRE_AMQP_FEED_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ZYRE_AMQP_FEED_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _zyre_amqp_feed_t zyre_amqp_feed_t;

#define ZYRE_AMQP_FEED_ALIVE            0xFABB
#define ZYRE_AMQP_FEED_DEAD             0xDEAD

#define ZYRE_AMQP_FEED_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL zyre_amqp_feed\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != ZYRE_AMQP_FEED_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "zyre_amqp_feed at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ZYRE_AMQP_FEED_ALIVE, self->object_tag);\
        zyre_amqp_feed_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_AMQP_FEED_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_AMQP_FEED_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ZYRE_AMQP_FEED_UNSAFE
#   define INCLUDE_ZYRE_AMQP_FEED_UNSAFE
#   define INCLUDE_ZYRE_AMQP_FEED_ACTIVE

#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    zyre_amqp_feed_animating;

//  Structure of the zyre_amqp_feed object

struct _zyre_amqp_feed_t {
dbyte
    object_tag;                     //  Object validity marker
icl_shortstr_t
    type,                           //  Feed type
    name;                           //  Feed name
Bool
    as_queue;                       //  Implemented as AMQP queue?
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define zyre_amqp_feed_new(type,name)   zyre_amqp_feed_new_ (__FILE__, __LINE__, type, name)
zyre_amqp_feed_t *
    zyre_amqp_feed_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
char * type,                            //  Feed type
char * name                             //  Feed name
);

void
    zyre_amqp_feed_selftest (
void);

void
    zyre_amqp_feed_terminate (
void);

#define zyre_amqp_feed_show(item,opcode,trace_file)  zyre_amqp_feed_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    zyre_amqp_feed_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define zyre_amqp_feed_destroy(self)    zyre_amqp_feed_destroy_ (self, __FILE__, __LINE__)
void
    zyre_amqp_feed_destroy_ (
zyre_amqp_feed_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    zyre_amqp_feed_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define zyre_amqp_feed_new_in_scope(self_p,_scope,type,name)  zyre_amqp_feed_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, type, name)
void
    zyre_amqp_feed_new_in_scope_ (
zyre_amqp_feed_t * * self_p,            //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
char * type,                            //  Feed type
char * name                             //  Feed name
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_AMQP_FEED_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_AMQP_FEED_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ZYRE_AMQP_FEED_INLINE)
#   define INCLUDE_ZYRE_AMQP_FEED_INLINE
#   define INCLUDE_ZYRE_AMQP_FEED_ACTIVE

#   include "zyre_classes.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ZYRE_AMQP_FEED_ACTIVE
#   if defined (ICL_IMPORT_ZYRE_AMQP_FEED_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ZYRE_AMQP_FEED_ROOT
#   endif
# endif
#endif
