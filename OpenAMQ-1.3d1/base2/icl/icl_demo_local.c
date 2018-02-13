/*---------------------------------------------------------------------------
    icl_demo_local.c - icl_demo_local component

    Generated from icl_demo_local.icl by icl_gen using GSL/4.
    
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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "icl_demo_local.h"             //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_demo_local_t

//  Shorthands for class methods                                               

#define self_new            icl_demo_local_new
#define self_annihilate     icl_demo_local_annihilate
#define self_selftest       icl_demo_local_selftest
#define self_initialise     icl_demo_local_initialise
#define self_terminate      icl_demo_local_terminate
#define self_show           icl_demo_local_show
#define self_destroy        icl_demo_local_destroy
#define self_alloc          icl_demo_local_alloc
#define self_free           icl_demo_local_free
#define self_animate        icl_demo_local_animate
#define self_new_in_scope   icl_demo_local_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_NEW))
static icl_stats_t *s_icl_demo_local_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_DESTROY))
static icl_stats_t *s_icl_demo_local_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_SELFTEST))
static icl_stats_t *s_icl_demo_local_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_INITIALISE))
static icl_stats_t *s_icl_demo_local_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_TERMINATE))
static icl_stats_t *s_icl_demo_local_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_SHOW))
static icl_stats_t *s_icl_demo_local_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_DESTROY_PUBLIC))
static icl_stats_t *s_icl_demo_local_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_ALLOC))
static icl_stats_t *s_icl_demo_local_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_FREE))
static icl_stats_t *s_icl_demo_local_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_ANIMATE))
static icl_stats_t *s_icl_demo_local_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_NEW_IN_SCOPE))
static icl_stats_t *s_icl_demo_local_new_in_scope_stats = NULL;
#endif
static void
    icl_demo_local_annihilate (
icl_demo_local_t * ( * self_p )         //  Reference to object reference
);

static void
    icl_demo_local_initialise (
void);

static void
    icl_demo_local_terminate (
void);

#define icl_demo_local_alloc()          icl_demo_local_alloc_ (__FILE__, __LINE__)
static icl_demo_local_t *
    icl_demo_local_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    icl_demo_local_free (
icl_demo_local_t * self                 //  Object reference
);

Bool
    icl_demo_local_animating = TRUE;    //  Animation enabled by default
static Bool
    s_icl_demo_local_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_icl_demo_local_mutex   = NULL;
#endif
#if (defined (BASE_THREADSAFE))
static apr_threadkey_t
    *threadkey;                         //  To hold thread-local cache header
#else
static icl_demo_local_t
        *s_cache = NULL;
#endif

/*  -------------------------------------------------------------------------
    icl_demo_local_new

    Type: Component method
    Creates and initialises a new icl_demo_local_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

icl_demo_local_t *
    icl_demo_local_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * name,                        //  Not documented
    char * address                      //  Not documented
)
{
    icl_demo_local_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL_NEW))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" name=\"%s\""
" address=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, name, address);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_NEW))
    icl_trace_record (NULL, icl_demo_local_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_NEW))
    icl_stats_inc ("icl_demo_local_new", &s_icl_demo_local_new_stats);
#endif

if (!s_icl_demo_local_active)
    self_initialise ();
self = icl_demo_local_alloc_ (file, line);
if (self) {
    self->object_tag   = ICL_DEMO_LOCAL_ALIVE;

self->name    = icl_mem_strdup (name);
self->address = icl_mem_strdup (address);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_NEW))
    icl_trace_record (NULL, icl_demo_local_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL_NEW))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" name=\"%s\""
" address=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, name, address, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_demo_local_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_local_annihilate (
    icl_demo_local_t * ( * self_p )     //  Reference to object reference
)
{

    icl_demo_local_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL_DESTROY))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_DESTROY))
    icl_trace_record (NULL, icl_demo_local_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_DESTROY))
    icl_stats_inc ("icl_demo_local_annihilate", &s_icl_demo_local_annihilate_stats);
#endif

ICL_DEMO_LOCAL_ASSERT_SANE (self);

icl_mem_free (self->name);
icl_mem_free (self->address);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_DESTROY))
    icl_trace_record (NULL, icl_demo_local_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL_DESTROY))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

}
/*  -------------------------------------------------------------------------
    icl_demo_local_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_local_selftest (
void)
{
icl_demo_local_t *
    item;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL_SELFTEST))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_SELFTEST))
    icl_trace_record (NULL, icl_demo_local_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_SELFTEST))
    icl_stats_inc ("icl_demo_local_selftest", &s_icl_demo_local_selftest_stats);
#endif

self_initialise ();
item = icl_demo_local_new ("John", "Main street");
icl_demo_local_destroy (&item);
item = icl_demo_local_new ("Janet", "Side avenue");
icl_demo_local_destroy (&item);
icl_demo_local_destroy (&item);
self_terminate ();
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_SELFTEST))
    icl_trace_record (NULL, icl_demo_local_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL_SELFTEST))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_selftest_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    icl_demo_local_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_local_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL_INITIALISE))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_INITIALISE))
    icl_trace_record (NULL, icl_demo_local_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_INITIALISE))
    icl_stats_inc ("icl_demo_local_initialise", &s_icl_demo_local_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_icl_demo_local_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_icl_demo_local_mutex)
            s_icl_demo_local_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_icl_demo_local_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_icl_demo_local_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);
#if (defined (BASE_THREADSAFE))
    icl_apr_assert (apr_threadkey_private_create (&threadkey, NULL, icl_global_pool));
#endif

            s_icl_demo_local_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_icl_demo_local_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_INITIALISE))
    icl_trace_record (NULL, icl_demo_local_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL_INITIALISE))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_initialise_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    icl_demo_local_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_local_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL_TERMINATE))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_TERMINATE))
    icl_trace_record (NULL, icl_demo_local_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_TERMINATE))
    icl_stats_inc ("icl_demo_local_terminate", &s_icl_demo_local_terminate_stats);
#endif

if (s_icl_demo_local_active) {
#if (defined (BASE_THREADSAFE))
    icl_apr_assert (apr_threadkey_private_delete (threadkey));
#endif

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_icl_demo_local_mutex);
#endif
        s_icl_demo_local_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_TERMINATE))
    icl_trace_record (NULL, icl_demo_local_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL_TERMINATE))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    icl_demo_local_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_local_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
icl_demo_local_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL_SHOW))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_show_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_SHOW))
    icl_trace_record (NULL, icl_demo_local_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_SHOW))
    icl_stats_inc ("icl_demo_local_show", &s_icl_demo_local_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <icl_demo_local file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_SHOW))
    icl_trace_record (NULL, icl_demo_local_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL_SHOW))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_show_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    icl_demo_local_destroy

    Type: Component method
    Destroys a icl_demo_local_t object. Takes the address of a
    icl_demo_local_t reference (a pointer to a pointer) and nullifies the
    reference after use.  Does nothing if the reference is already
    null.
    Performs an agressive destroy of an object.  This involves:
    1. Removing the object from any containers it is in.
    2. Making the object an zombie
    3. Decrementing the object's link count
    4. If the link count is zero then freeing the object.
    -------------------------------------------------------------------------
 */

void
    icl_demo_local_destroy_ (
    icl_demo_local_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_demo_local_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL_DESTROY_PUBLIC))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_demo_local_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_DESTROY_PUBLIC))
    icl_stats_inc ("icl_demo_local_destroy", &s_icl_demo_local_destroy_stats);
#endif

if (self) {
    icl_demo_local_annihilate (self_p);
    icl_demo_local_free ((icl_demo_local_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_demo_local_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL_DESTROY_PUBLIC))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    icl_demo_local_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_demo_local_t *
    icl_demo_local_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if (defined (BASE_THREADSAFE))
    icl_demo_local_t
        **s_cache;
    void
        *s_cache_p;
#endif

    icl_demo_local_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL_ALLOC))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_ALLOC))
    icl_trace_record (NULL, icl_demo_local_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_ALLOC))
    icl_stats_inc ("icl_demo_local_alloc", &s_icl_demo_local_alloc_stats);
#endif

#if (defined (BASE_THREADSAFE))
    icl_apr_assert (apr_threadkey_private_get (&s_cache_p, threadkey));
    s_cache = s_cache_p;
    if (!s_cache) {
        s_cache = malloc (sizeof (icl_demo_local_t **));
        *s_cache = NULL;
        icl_apr_assert (apr_threadkey_private_set (s_cache, threadkey));
    }
    else
        self = *s_cache;

    if (self) {
        *s_cache = self->local_next;
        self->local_next = NULL;
    }
    else
        self = (icl_demo_local_t *) malloc (sizeof (icl_demo_local_t));
#else
    if (s_cache) {
        self = s_cache;
        s_cache = self->local_next;
        self->local_next = NULL;
    }
    else
        self = (icl_demo_local_t *) malloc (sizeof (icl_demo_local_t));
#endif
    if (self)
        memset (self, 0, sizeof (icl_demo_local_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_ALLOC))
    icl_trace_record (NULL, icl_demo_local_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL_ALLOC))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_demo_local_free

    Type: Component method
    Freess a icl_demo_local_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_local_free (
    icl_demo_local_t * self             //  Object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_demo_local_t
        **s_cache;
    void
        *s_cache_p;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL_FREE))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_FREE))
    icl_trace_record (NULL, icl_demo_local_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_FREE))
    icl_stats_inc ("icl_demo_local_free", &s_icl_demo_local_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (icl_demo_local_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (icl_demo_local_t));
        self->object_tag = ICL_DEMO_LOCAL_DEAD;
#if (defined (BASE_THREADSAFE))
        icl_apr_assert (apr_threadkey_private_get (&s_cache_p, threadkey));
        s_cache = s_cache_p;
        self->local_next = *s_cache;
        *s_cache = self;
#else
        self->local_next = s_cache;
        s_cache = self;
#endif
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_FREE))
    icl_trace_record (NULL, icl_demo_local_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL_FREE))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

}
/*  -------------------------------------------------------------------------
    icl_demo_local_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_demo_local_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL_ANIMATE))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_animate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_ANIMATE))
    icl_trace_record (NULL, icl_demo_local_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_ANIMATE))
    icl_stats_inc ("icl_demo_local_animate", &s_icl_demo_local_animate_stats);
#endif

icl_demo_local_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_ANIMATE))
    icl_trace_record (NULL, icl_demo_local_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL_ANIMATE))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_animate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

}
/*  -------------------------------------------------------------------------
    icl_demo_local_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_local_new_in_scope_ (
    icl_demo_local_t * * self_p,        //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * name,                        //  Not documented
    char * address                      //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_LOCAL_NEW_IN_SCOPE))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" name=\"%s\""
" address=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, name, address);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_demo_local_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL)  ||  defined (BASE_STATS_ICL_DEMO_LOCAL_NEW_IN_SCOPE))
    icl_stats_inc ("icl_demo_local_new_in_scope", &s_icl_demo_local_new_in_scope_stats);
#endif

*self_p = icl_demo_local_new_ (file,line,name,address);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_demo_local_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_demo_local_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL)   || defined (BASE_ANIMATE_ICL_DEMO_LOCAL_NEW_IN_SCOPE))
    if (icl_demo_local_animating)
        icl_console_print ("<icl_demo_local_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" name=\"%s\""
" address=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, name, address, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_NEW)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_DESTROY)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_SELFTEST)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_INITIALISE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_SHOW)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_DESTROY_PUBLIC)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_ALLOC)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_FREE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_ANIMATE)   || defined (BASE_TRACE_ICL_DEMO_LOCAL_NEW_IN_SCOPE) )
void
icl_demo_local_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "initialise"; break;
        case 5: method_name = "terminate"; break;
        case 6: method_name = "show"; break;
        case 7: method_name = "destroy public"; break;
        case 8: method_name = "alloc"; break;
        case 9: method_name = "free"; break;
        case 10: method_name = "animate"; break;
        case 11: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "icl_demo_local %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *icl_demo_local_version_start  = "VeRsIoNsTaRt:ipc";
char *icl_demo_local_component     = "icl_demo_local ";
char *icl_demo_local_version       = "1.0 ";
char *icl_demo_local_copyright     = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_demo_local_filename      = "icl_demo_local.icl ";
char *icl_demo_local_builddate     = "2010/10/06 ";
char *icl_demo_local_version_end   = "VeRsIoNeNd:ipc";

