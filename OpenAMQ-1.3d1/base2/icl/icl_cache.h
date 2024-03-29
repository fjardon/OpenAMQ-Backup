/*---------------------------------------------------------------------------
    icl_cache.h - icl_cache component

    Generated from icl_cache.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_ICL_CACHE_SAFE
#   define INCLUDE_ICL_CACHE_SAFE
#   define INCLUDE_ICL_CACHE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ICL_CACHE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _icl_cache_t icl_cache_t;

#define ICL_CACHE_ALIVE                 0xFABB
#define ICL_CACHE_DEAD                  0xDEAD

#define ICL_CACHE_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL icl_cache\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != ICL_CACHE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "icl_cache at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ICL_CACHE_ALIVE, self->object_tag);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
//  Macros                                                                     

#define ICL_CALLBACK_DUMP 0

#define ICL_CACHE_HEADER 0xEdeaU        //      if block is a cache header.    

//  Types

typedef void (icl_callback_fn) (void *item, int opcode, FILE *trace_file, char *file, size_t line);
typedef void (icl_mem_thin_free_fn) (void *data);

//  Global variables                                                           

extern icl_cache_t
    *s_direct_cache;                    //  Pseudo-cache for direct alloc'ns
#   ifdef __cplusplus
}
#   endif

#   include "icl_mem_fat.h"
#   include "icl_mem_thin.h"
#   include "icl_cache_list.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_CACHE_ACTIVE
#   if defined (ICL_IMPORT_ICL_CACHE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ICL_CACHE_UNSAFE
#   define INCLUDE_ICL_CACHE_UNSAFE
#   define INCLUDE_ICL_CACHE_ACTIVE

#   include "icl_mem_fat.h"
#   include "icl_mem_thin.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    icl_cache_animating;

//  Structure of the icl_cache object

struct _icl_cache_t {
#if (defined (BASE_THREADSAFE))
    icl_mutex_t *
        mutex;
#endif
    dbyte
        object_tag;                     //  Object validity marker
volatile icl_cache_list_t *list_head;
volatile icl_cache_t *list_prev;
volatile icl_cache_t *list_next;
    icl_mem_fat_list_t
        *fat_used_list,                 //  List of used objects               
        *fat_unused_list;               //  List of unused objects
    icl_mem_thin_list_t
        *thin_unused_list;              //  List of unused objects
#if defined (BASE_LOCKFREE)
    icl_mem_lockfree_list_t
        *lockfree_unused_list;          //  List of unused objects
#endif
    qbyte
        thin_used_count;                //  Number of used objects
#if defined (BASE_LOCKFREE)
    qbyte
        lockfree_used_count,            //  Number of used objects
        lockfree_unused_count;          //  Number of unused objects
#endif
    size_t
        size;                           //  Size of objects in this cache
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_CACHE))
    icl_stats_t
        *used_stat,
        *unused_stat,
        *allocs_stat,
        *frees_stat;
#endif
};

#   ifdef __cplusplus
}
#   endif
#   include "icl_cache_list.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define icl_cache_new()                 icl_cache_new_ (__FILE__, __LINE__)
icl_cache_t *
    icl_cache_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

icl_cache_t *
    icl_cache_create (
qbyte size                              //  Not documented
);

icl_cache_t *
    icl_cache_get (
qbyte size                              //  Not documented
);

#define icl_cache_assert()              icl_cache_assert_ (__FILE__, __LINE__)
int
    icl_cache_assert_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    icl_cache_initialise (
void);

void
    icl_cache_selftest (
void);

void
    icl_cache_remove_from_all_containers (
icl_cache_t * self                      //  The item
);

#define icl_cache_destroy(self)         icl_cache_destroy_ (self, __FILE__, __LINE__)
void
    icl_cache_destroy_ (
icl_cache_t * ( * self_p ),             //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    icl_cache_lock (
icl_cache_t * self                      //  Reference to object
);

int
    icl_cache_unlock (
icl_cache_t * self                      //  Reference to object
);

void
    icl_cache_animate (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define icl_cache_new_in_scope(self_p,_scope)  icl_cache_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    icl_cache_new_in_scope_ (
icl_cache_t * * self_p,                 //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_CACHE_ACTIVE
#   if defined (ICL_IMPORT_ICL_CACHE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ICL_CACHE_INLINE)
#   define INCLUDE_ICL_CACHE_INLINE
#   define INCLUDE_ICL_CACHE_ACTIVE

#   include "icl_mem_fat.h"
#   include "icl_mem_thin.h"
#   include "icl_cache_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_CACHE_ACTIVE
#   if defined (ICL_IMPORT_ICL_CACHE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ICL_CACHE_ROOT
#   endif
# endif
#endif
