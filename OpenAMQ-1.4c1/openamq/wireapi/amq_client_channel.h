/*---------------------------------------------------------------------------
    amq_client_channel.h - amq_client_channel component

This class implements the channel class for the AMQ client.
    Generated from amq_client_channel.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_CLIENT_CHANNEL_SAFE
#   define INCLUDE_AMQ_CLIENT_CHANNEL_SAFE
#   define INCLUDE_AMQ_CLIENT_CHANNEL_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_CLIENT_CHANNEL_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_client_channel_t amq_client_channel_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
#    define AMQ_CLIENT_CHANNEL_HISTORY_LENGTH 32
#endif

#define AMQ_CLIENT_CHANNEL_ALIVE        0xFABB
#define AMQ_CLIENT_CHANNEL_DEAD         0xDEAD

#define AMQ_CLIENT_CHANNEL_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_client_channel\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_CLIENT_CHANNEL_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_client_channel at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_CLIENT_CHANNEL_ALIVE, self->object_tag);\
        amq_client_channel_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_client_channel_table.h"
#   include "asl.h"
#   include "amq_client_method.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CLIENT_CHANNEL_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CLIENT_CHANNEL_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_CLIENT_CHANNEL_UNSAFE
#   define INCLUDE_AMQ_CLIENT_CHANNEL_UNSAFE
#   define INCLUDE_AMQ_CLIENT_CHANNEL_ACTIVE

#   include "amq_client_channel_table.h"
#   include "asl.h"
#   include "amq_client_method.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_client_channel_animating;

//  Structure of the amq_client_channel object

struct _amq_client_channel_t {
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_CLIENT_CHANNEL_HISTORY_LENGTH];
    int
        history_line  [AMQ_CLIENT_CHANNEL_HISTORY_LENGTH];
    char
        *history_type [AMQ_CLIENT_CHANNEL_HISTORY_LENGTH];
    int
        history_links [AMQ_CLIENT_CHANNEL_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
amq_client_channel_table_t
    *table_head;                    //  Hash table container
amq_client_channel_t
    *table_next;                    //  Next item in the hash slot
qbyte
    table_index;                    //  Index of item in table
int
    key;                            //  Item's original key
Bool
    active;                         //  If TRUE, channel is active
smt_method_queue_t
    *method_queue;                  //  Reply queue for client api
Bool
    *alive;                         //  Where to push alive status
dbyte
    *reply_code;                    //  Where to push reply_code
char
    *reply_text;                    //  Where to push reply_text
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_client_channel_new(table,key,method_queue,alive,reply_code,reply_text)  amq_client_channel_new_ (__FILE__, __LINE__, table, key, method_queue, alive, reply_code, reply_text)
amq_client_channel_t *
    amq_client_channel_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_client_channel_table_t * table,     //  Table to insert into
int key,                                //  Hash key
smt_method_queue_t * method_queue,      //  Reply queue
Bool * alive,                           //  Where to push alive status
dbyte * reply_code,                     //  Where to push reply code
char * reply_text                       //  Where to push reply text
);

void
    amq_client_channel_selftest (
void);

void
    amq_client_channel_remove_from_all_containers (
amq_client_channel_t * self             //  The item
);

#define amq_client_channel_show(item,opcode,trace_file)  amq_client_channel_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_client_channel_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    amq_client_channel_terminate (
void);

#define amq_client_channel_destroy(self)  amq_client_channel_destroy_ (self, __FILE__, __LINE__)
void
    amq_client_channel_destroy_ (
amq_client_channel_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define amq_client_channel_link(self)   amq_client_channel_link_ (self, __FILE__, __LINE__)
amq_client_channel_t *
    amq_client_channel_link_ (
amq_client_channel_t * self,            //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_client_channel_unlink(self)  amq_client_channel_unlink_ (self, __FILE__, __LINE__)
void
    amq_client_channel_unlink_ (
amq_client_channel_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_client_channel_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_client_channel_new_in_scope(self_p,_scope,table,key,method_queue,alive,reply_code,reply_text)  amq_client_channel_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, table, key, method_queue, alive, reply_code, reply_text)
void
    amq_client_channel_new_in_scope_ (
amq_client_channel_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_client_channel_table_t * table,     //  Table to insert into
int key,                                //  Hash key
smt_method_queue_t * method_queue,      //  Reply queue
Bool * alive,                           //  Where to push alive status
dbyte * reply_code,                     //  Where to push reply code
char * reply_text                       //  Where to push reply text
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CLIENT_CHANNEL_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CLIENT_CHANNEL_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_CLIENT_CHANNEL_INLINE)
#   define INCLUDE_AMQ_CLIENT_CHANNEL_INLINE
#   define INCLUDE_AMQ_CLIENT_CHANNEL_ACTIVE

#   include "amq_client_channel_table.h"
#   include "asl.h"
#   include "amq_client_method.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_CLIENT_CHANNEL_ACTIVE
#   if defined (ICL_IMPORT_AMQ_CLIENT_CHANNEL_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_CLIENT_CHANNEL_ROOT
#   endif
# endif
#endif
