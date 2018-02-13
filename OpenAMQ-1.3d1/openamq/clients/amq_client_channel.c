/*---------------------------------------------------------------------------
    amq_client_channel.c - amq_client_channel component

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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "amq_client_channel.h"         //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              amq_client_channel_t

//  Shorthands for class methods                                               

#define self_new            amq_client_channel_new
#define self_annihilate     amq_client_channel_annihilate
#define self_selftest       amq_client_channel_selftest
#define self_remove_from_all_containers  amq_client_channel_remove_from_all_containers
#define self_show           amq_client_channel_show
#define self_terminate      amq_client_channel_terminate
#define self_destroy        amq_client_channel_destroy
#define self_alloc          amq_client_channel_alloc
#define self_free           amq_client_channel_free
#define self_link           amq_client_channel_link
#define self_unlink         amq_client_channel_unlink
#define self_cache_initialise  amq_client_channel_cache_initialise
#define self_cache_purge    amq_client_channel_cache_purge
#define self_cache_terminate  amq_client_channel_cache_terminate
#define self_animate        amq_client_channel_animate
#define self_new_in_scope   amq_client_channel_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_NEW))
static icl_stats_t *s_amq_client_channel_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_DESTROY))
static icl_stats_t *s_amq_client_channel_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_SELFTEST))
static icl_stats_t *s_amq_client_channel_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_amq_client_channel_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_SHOW))
static icl_stats_t *s_amq_client_channel_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_TERMINATE))
static icl_stats_t *s_amq_client_channel_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_DESTROY_PUBLIC))
static icl_stats_t *s_amq_client_channel_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_ALLOC))
static icl_stats_t *s_amq_client_channel_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_FREE))
static icl_stats_t *s_amq_client_channel_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_LINK))
static icl_stats_t *s_amq_client_channel_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_UNLINK))
static icl_stats_t *s_amq_client_channel_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_CACHE_INITIALISE))
static icl_stats_t *s_amq_client_channel_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_CACHE_PURGE))
static icl_stats_t *s_amq_client_channel_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_CACHE_TERMINATE))
static icl_stats_t *s_amq_client_channel_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_ANIMATE))
static icl_stats_t *s_amq_client_channel_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_NEW_IN_SCOPE))
static icl_stats_t *s_amq_client_channel_new_in_scope_stats = NULL;
#endif
#define amq_client_channel_annihilate(self)  amq_client_channel_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_client_channel_annihilate_ (
amq_client_channel_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_client_channel_alloc()      amq_client_channel_alloc_ (__FILE__, __LINE__)
static amq_client_channel_t *
    amq_client_channel_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_client_channel_free(self)   amq_client_channel_free_ (self, __FILE__, __LINE__)
static void
    amq_client_channel_free_ (
amq_client_channel_t * self,            //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_client_channel_cache_initialise (
void);

static void
    amq_client_channel_cache_purge (
void);

static void
    amq_client_channel_cache_terminate (
void);

Bool
    amq_client_channel_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    amq_client_channel_new

    Type: Component method
    Creates and initialises a new amq_client_channel_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

amq_client_channel_t *
    amq_client_channel_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_channel_table_t * table,   //  Table to insert into
    int key,                            //  Hash key
    smt_method_queue_t * method_queue,   //  Reply queue
    Bool * alive,                       //  Where to push alive status
    dbyte * reply_code,                 //  Where to push reply code
    char * reply_text                   //  Where to push reply text
)
{
    amq_client_channel_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_NEW))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" method_queue=\"%pp\""
" alive=\"%pp\""
" reply_code=\"%pp\""
" reply_text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, method_queue, alive, reply_code, reply_text);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_NEW))
    icl_trace_record (NULL, amq_client_channel_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_NEW))
    icl_stats_inc ("amq_client_channel_new", &s_amq_client_channel_new_stats);
#endif

    self = amq_client_channel_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CLIENT_CHANNEL_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_client_channel_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->active = TRUE;

//
self->method_queue = smt_method_queue_link (method_queue);
self->alive        = alive;
self->reply_code   = reply_code;
self->reply_text   = reply_text;
if (table && self && amq_client_channel_table_insert (table, key, self))
    amq_client_channel_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_NEW))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_NEW))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" method_queue=\"%pp\""
" alive=\"%pp\""
" reply_code=\"%pp\""
" reply_text=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, method_queue, alive, reply_code, reply_text, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_channel_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_channel_annihilate_ (
    amq_client_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
    int
        history_last;
#endif

    amq_client_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_DESTROY))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_DESTROY))
    icl_trace_record (NULL, amq_client_channel_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_DESTROY))
    icl_stats_inc ("amq_client_channel_annihilate", &s_amq_client_channel_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = self->links;
#endif

    AMQ_CLIENT_CHANNEL_ASSERT_SANE (self);
    amq_client_channel_remove_from_all_containers (self);

smt_method_queue_unlink (&self->method_queue);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_DESTROY))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_DESTROY))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_channel_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_channel_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_SELFTEST))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_SELFTEST))
    icl_trace_record (NULL, amq_client_channel_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_SELFTEST))
    icl_stats_inc ("amq_client_channel_selftest", &s_amq_client_channel_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_SELFTEST))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_SELFTEST))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_selftest_finish"
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
    amq_client_channel_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    amq_client_channel_remove_from_all_containers (
    amq_client_channel_t * self         //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_client_channel_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("amq_client_channel_remove_from_all_containers", &s_amq_client_channel_remove_from_all_containers_stats);
#endif

AMQ_CLIENT_CHANNEL_ASSERT_SANE (self);
amq_client_channel_table_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_remove_from_all_containers_finish"
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
    amq_client_channel_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_channel_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_client_channel_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_SHOW))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_SHOW))
    icl_trace_record (NULL, amq_client_channel_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_SHOW))
    icl_stats_inc ("amq_client_channel_show", &s_amq_client_channel_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_client_channel zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
    if (self->history_last > AMQ_CLIENT_CHANNEL_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH;
        self->history_last %= AMQ_CLIENT_CHANNEL_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_client_channel>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_SHOW))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_SHOW))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_show_finish"
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
    amq_client_channel_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_channel_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_TERMINATE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_TERMINATE))
    icl_trace_record (NULL, amq_client_channel_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_TERMINATE))
    icl_stats_inc ("amq_client_channel_terminate", &s_amq_client_channel_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_TERMINATE))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_TERMINATE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_terminate_finish"
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
    amq_client_channel_destroy

    Type: Component method
    Destroys a amq_client_channel_t object. Takes the address of a
    amq_client_channel_t reference (a pointer to a pointer) and nullifies the
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
    amq_client_channel_destroy_ (
    amq_client_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_client_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_DESTROY_PUBLIC))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_client_channel_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_DESTROY_PUBLIC))
    icl_stats_inc ("amq_client_channel_destroy", &s_amq_client_channel_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_client_channel_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on amq_client_channel object");
        amq_client_channel_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_client_channel_free_ ((amq_client_channel_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_DESTROY_PUBLIC))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_DESTROY_PUBLIC))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_channel_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_client_channel_t *
    amq_client_channel_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_client_channel_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_ALLOC))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_ALLOC))
    icl_trace_record (NULL, amq_client_channel_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_ALLOC))
    icl_stats_inc ("amq_client_channel_alloc", &s_amq_client_channel_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    amq_client_channel_cache_initialise ();

self = (amq_client_channel_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_client_channel_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_ALLOC))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_ALLOC))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_alloc_finish"
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
    amq_client_channel_free

    Type: Component method
    Freess a amq_client_channel_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_client_channel_free_ (
    amq_client_channel_t * self,        //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_FREE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_FREE))
    icl_trace_record (NULL, amq_client_channel_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_FREE))
    icl_stats_inc ("amq_client_channel_free", &s_amq_client_channel_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (amq_client_channel_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_client_channel_t));
        self->object_tag = AMQ_CLIENT_CHANNEL_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_FREE))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_FREE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_channel_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_client_channel_t *
    amq_client_channel_link_ (
    amq_client_channel_t * self,        //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_LINK))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_link_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_LINK))
    icl_trace_record (NULL, amq_client_channel_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_LINK))
    icl_stats_inc ("amq_client_channel_link", &s_amq_client_channel_link_stats);
#endif

    if (self) {
        AMQ_CLIENT_CHANNEL_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_LINK))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_LINK))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_link_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    amq_client_channel_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_client_channel_unlink_ (
    amq_client_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
    int
        history_last;
#endif

    amq_client_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_UNLINK))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_unlink_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_UNLINK))
    icl_trace_record (NULL, amq_client_channel_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_UNLINK))
    icl_stats_inc ("amq_client_channel_unlink", &s_amq_client_channel_unlink_stats);
#endif

    if (self) {
        AMQ_CLIENT_CHANNEL_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_client_channel object");
            amq_client_channel_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CLIENT_CHANNEL)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_CLIENT_CHANNEL_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_client_channel_annihilate_ (self_p, file, line);
        amq_client_channel_free_ ((amq_client_channel_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_UNLINK))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_UNLINK))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_unlink_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    amq_client_channel_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_client_channel_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_CACHE_INITIALISE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_client_channel_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_CACHE_INITIALISE))
    icl_stats_inc ("amq_client_channel_cache_initialise", &s_amq_client_channel_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (amq_client_channel_t));
icl_system_register (amq_client_channel_cache_purge, amq_client_channel_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_CACHE_INITIALISE))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_CACHE_INITIALISE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_cache_initialise_finish"
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
    amq_client_channel_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_channel_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_CACHE_PURGE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_CACHE_PURGE))
    icl_trace_record (NULL, amq_client_channel_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_CACHE_PURGE))
    icl_stats_inc ("amq_client_channel_cache_purge", &s_amq_client_channel_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_CACHE_PURGE))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_CACHE_PURGE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_cache_purge_finish"
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
    amq_client_channel_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_client_channel_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_CACHE_TERMINATE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_client_channel_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_CACHE_TERMINATE))
    icl_stats_inc ("amq_client_channel_cache_terminate", &s_amq_client_channel_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_CACHE_TERMINATE))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_CACHE_TERMINATE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_cache_terminate_finish"
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
    amq_client_channel_animate

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_client_channel_animate (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_ANIMATE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_ANIMATE))
    icl_trace_record (NULL, amq_client_channel_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_ANIMATE))
    icl_stats_inc ("amq_client_channel_animate", &s_amq_client_channel_animate_stats);
#endif

amq_client_channel_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_ANIMATE))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_ANIMATE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_animate_finish"
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
    amq_client_channel_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_client_channel_new_in_scope_ (
    amq_client_channel_t * * self_p,    //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    amq_client_channel_table_t * table,   //  Table to insert into
    int key,                            //  Hash key
    smt_method_queue_t * method_queue,   //  Reply queue
    Bool * alive,                       //  Where to push alive status
    dbyte * reply_code,                 //  Where to push reply code
    char * reply_text                   //  Where to push reply text
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_NEW_IN_SCOPE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" method_queue=\"%pp\""
" alive=\"%pp\""
" reply_code=\"%pp\""
" reply_text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, method_queue, alive, reply_code, reply_text);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_client_channel_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL)  ||  defined (BASE_STATS_AMQ_CLIENT_CHANNEL_NEW_IN_SCOPE))
    icl_stats_inc ("amq_client_channel_new_in_scope", &s_amq_client_channel_new_in_scope_stats);
#endif

*self_p = amq_client_channel_new_ (file,line,table,key,method_queue,alive,reply_code,reply_text);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_client_channel_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_NEW_IN_SCOPE))
    icl_trace_record (NULL, amq_client_channel_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL)   || defined (BASE_ANIMATE_AMQ_CLIENT_CHANNEL_NEW_IN_SCOPE))
    if (amq_client_channel_animating)
        icl_console_print ("<amq_client_channel_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" method_queue=\"%pp\""
" alive=\"%pp\""
" reply_code=\"%pp\""
" reply_text=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, method_queue, alive, reply_code, reply_text, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_NEW)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_DESTROY)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_SELFTEST)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_SHOW)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_TERMINATE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_DESTROY_PUBLIC)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_ALLOC)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_FREE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_LINK)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_UNLINK)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_CACHE_INITIALISE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_CACHE_PURGE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_CACHE_TERMINATE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_ANIMATE)   || defined (BASE_TRACE_AMQ_CLIENT_CHANNEL_NEW_IN_SCOPE) )
void
amq_client_channel_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "remove from all containers"; break;
        case 5: method_name = "show"; break;
        case 6: method_name = "terminate"; break;
        case 7: method_name = "destroy public"; break;
        case 8: method_name = "alloc"; break;
        case 9: method_name = "free"; break;
        case 10: method_name = "link"; break;
        case 11: method_name = "unlink"; break;
        case 12: method_name = "cache initialise"; break;
        case 13: method_name = "cache purge"; break;
        case 14: method_name = "cache terminate"; break;
        case 15: method_name = "animate"; break;
        case 16: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "amq_client_channel %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *amq_client_channel_version_start  = "VeRsIoNsTaRt:ipc";
char *amq_client_channel_component  = "amq_client_channel ";
char *amq_client_channel_version   = "1.0 ";
char *amq_client_channel_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *amq_client_channel_filename  = "amq_client_channel.icl ";
char *amq_client_channel_builddate  = "2010/10/06 ";
char *amq_client_channel_version_end  = "VeRsIoNeNd:ipc";

