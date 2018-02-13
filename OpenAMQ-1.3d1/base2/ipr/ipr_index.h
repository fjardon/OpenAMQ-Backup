/*---------------------------------------------------------------------------
    ipr_index.h - ipr_index component

This class provides a mechanism for indexing objects.  An index is a number
from 0 to IPR_INDEX_MAX - 1. The class keeps indexes low by hashing across
a variable part of the index rather than across its full size.  Does not
support the retrieval of objects by their reference, only by index.
    Generated from ipr_index.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_IPR_INDEX_SAFE
#   define INCLUDE_IPR_INDEX_SAFE
#   define INCLUDE_IPR_INDEX_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_IPR_INDEX_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _ipr_index_t ipr_index_t;

#define IPR_INDEX_ALIVE                 0xFABB
#define IPR_INDEX_DEAD                  0xDEAD

#define IPR_INDEX_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL ipr_index\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != IPR_INDEX_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "ipr_index at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, IPR_INDEX_ALIVE, self->object_tag);\
        ipr_index_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "ipr_bits.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_INDEX_ACTIVE
#   if defined (ICL_IMPORT_IPR_INDEX_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_IPR_INDEX_UNSAFE
#   define INCLUDE_IPR_INDEX_UNSAFE
#   define INCLUDE_IPR_INDEX_ACTIVE

#   include "ipr_bits.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    ipr_index_animating;
#define IPR_INDEX_MAX   IPR_BITS_SIZE_BITS

//  Structure of the ipr_index object

struct _ipr_index_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    dbyte
        object_tag;                     //  Object validity marker
int   size;                         //  Number of index entries
void *data [IPR_INDEX_MAX];
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
int
    ipr_index_insert (
ipr_index_t * self,                     //  Reference to object
void * object                           //  Object to index
);

int
    ipr_index_delete (
ipr_index_t * self,                     //  Reference to object
int index                               //  Index entry to delete
);

void
    ipr_index_selftest (
void);

#define ipr_index_new()                 ipr_index_new_ (__FILE__, __LINE__)
ipr_index_t *
    ipr_index_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

qbyte
    ipr_index_count (
void);

void
    ipr_index_terminate (
void);

#define ipr_index_show(item,opcode,trace_file)  ipr_index_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    ipr_index_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define ipr_index_destroy(self)         ipr_index_destroy_ (self, __FILE__, __LINE__)
void
    ipr_index_destroy_ (
ipr_index_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    ipr_index_read_lock (
ipr_index_t * self                      //  Reference to object
);

int
    ipr_index_write_lock (
ipr_index_t * self                      //  Reference to object
);

int
    ipr_index_unlock (
ipr_index_t * self                      //  Reference to object
);

void
    ipr_index_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define ipr_index_new_in_scope(self_p,_scope)  ipr_index_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    ipr_index_new_in_scope_ (
ipr_index_t * * self_p,                 //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_INDEX_ACTIVE
#   if defined (ICL_IMPORT_IPR_INDEX_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_IPR_INDEX_INLINE)
#   define INCLUDE_IPR_INDEX_INLINE
#   define INCLUDE_IPR_INDEX_ACTIVE

#   include "ipr_bits.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_INSERT)   || defined (BASE_TRACE_IPR_INDEX_DELETE)   || defined (BASE_TRACE_IPR_INDEX_SELFTEST)   || defined (BASE_TRACE_IPR_INDEX_NEW)   || defined (BASE_TRACE_IPR_INDEX_DESTROY)   || defined (BASE_TRACE_IPR_INDEX_COUNT)   || defined (BASE_TRACE_IPR_INDEX_TERMINATE)   || defined (BASE_TRACE_IPR_INDEX_SHOW)   || defined (BASE_TRACE_IPR_INDEX_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_INDEX_ALLOC)   || defined (BASE_TRACE_IPR_INDEX_FREE)   || defined (BASE_TRACE_IPR_INDEX_READ_LOCK)   || defined (BASE_TRACE_IPR_INDEX_WRITE_LOCK)   || defined (BASE_TRACE_IPR_INDEX_UNLOCK)   || defined (BASE_TRACE_IPR_INDEX_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_INDEX_CACHE_PURGE)   || defined (BASE_TRACE_IPR_INDEX_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_INDEX_ANIMATE)   || defined (BASE_TRACE_IPR_INDEX_NEW_IN_SCOPE) )
void
    ipr_index_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_INDEX_ACTIVE
#   if defined (ICL_IMPORT_IPR_INDEX_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_IPR_INDEX_ROOT
#   endif
# endif
#endif
