/*---------------------------------------------------------------------------
    amq_sequence.h - amq_sequence component

Tracks the timestamp for each of a set of senders.  Given a new timestamp and
a sender, verifies that the timestamp is equal to or more recent than the last
known timestamp for the sender.
    Generated from amq_sequence.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_AMQ_SEQUENCE_SAFE
#   define INCLUDE_AMQ_SEQUENCE_SAFE
#   define INCLUDE_AMQ_SEQUENCE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_SEQUENCE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_sequence_t amq_sequence_t;

#define AMQ_SEQUENCE_ALIVE              0xFABB
#define AMQ_SEQUENCE_DEAD               0xDEAD

#define AMQ_SEQUENCE_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL amq_sequence\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != AMQ_SEQUENCE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "amq_sequence at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_SEQUENCE_ALIVE, self->object_tag);\
        amq_sequence_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_sequence_table.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SEQUENCE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SEQUENCE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_SEQUENCE_UNSAFE
#   define INCLUDE_AMQ_SEQUENCE_UNSAFE
#   define INCLUDE_AMQ_SEQUENCE_ACTIVE

#   include "amq_sequence_table.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_sequence_animating;

//  Structure of the amq_sequence object

struct _amq_sequence_t {
dbyte
    object_tag;                     //  Object validity marker
amq_sequence_table_t
    *table_head;                    //  Hash table container
amq_sequence_t
    *table_next;                    //  Next item in the hash slot
qbyte
    table_index;                    //  Index of item in table
icl_shortstr_t
    key;                            //  Item's original key
apr_time_t
    timestamp;                      //  Last known time for sender
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_sequence_new(table,key,timestamp)  amq_sequence_new_ (__FILE__, __LINE__, table, key, timestamp)
amq_sequence_t *
    amq_sequence_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_sequence_table_t * table,           //  Table to insert into
char * key,                             //  Hash key
apr_time_t timestamp                    //  Not documented
);

int
    amq_sequence_check (
amq_sequence_table_t * table,           //  Not documented
char * sender_id,                       //  Not documented
apr_time_t timestamp                    //  Not documented
);

void
    amq_sequence_selftest (
void);

void
    amq_sequence_remove_from_all_containers (
amq_sequence_t * self                   //  The item
);

#define amq_sequence_show(item,opcode,trace_file)  amq_sequence_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_sequence_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

void
    amq_sequence_terminate (
void);

#define amq_sequence_destroy(self)      amq_sequence_destroy_ (self, __FILE__, __LINE__)
void
    amq_sequence_destroy_ (
amq_sequence_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    amq_sequence_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_sequence_new_in_scope(self_p,_scope,table,key,timestamp)  amq_sequence_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, table, key, timestamp)
void
    amq_sequence_new_in_scope_ (
amq_sequence_t * * self_p,              //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
amq_sequence_table_t * table,           //  Table to insert into
char * key,                             //  Hash key
apr_time_t timestamp                    //  Not documented
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SEQUENCE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SEQUENCE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_SEQUENCE_INLINE)
#   define INCLUDE_AMQ_SEQUENCE_INLINE
#   define INCLUDE_AMQ_SEQUENCE_ACTIVE

#   include "amq_sequence_table.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_SEQUENCE)   || defined (BASE_TRACE_AMQ_SEQUENCE_NEW)   || defined (BASE_TRACE_AMQ_SEQUENCE_CHECK)   || defined (BASE_TRACE_AMQ_SEQUENCE_SELFTEST)   || defined (BASE_TRACE_AMQ_SEQUENCE_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_SEQUENCE_SHOW)   || defined (BASE_TRACE_AMQ_SEQUENCE_TERMINATE)   || defined (BASE_TRACE_AMQ_SEQUENCE_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_SEQUENCE_DESTROY)   || defined (BASE_TRACE_AMQ_SEQUENCE_ALLOC)   || defined (BASE_TRACE_AMQ_SEQUENCE_FREE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_SEQUENCE_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_SEQUENCE_ANIMATE)   || defined (BASE_TRACE_AMQ_SEQUENCE_NEW_IN_SCOPE) )
void
    amq_sequence_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SEQUENCE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SEQUENCE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_SEQUENCE_ROOT
#   endif
# endif
#endif
