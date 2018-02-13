/*---------------------------------------------------------------------------
    amq_server_channel_table.h - amq_server_channel_table component

    This class implements the hash table container for amq_server_channel
    Generated from amq_server_channel_table.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    
    This file is licensed under the GPL as follows:
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at
    your option) any later version.
    
    This program is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.
    
    For information on alternative licensing for OEMs, please contact
    iMatix Corporation.

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_AMQ_SERVER_CHANNEL_TABLE_SAFE
#   define INCLUDE_AMQ_SERVER_CHANNEL_TABLE_SAFE
#   define INCLUDE_AMQ_SERVER_CHANNEL_TABLE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_AMQ_SERVER_CHANNEL_TABLE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _amq_server_channel_table_t amq_server_channel_table_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
#    define AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH 32
#endif

#define AMQ_SERVER_CHANNEL_TABLE_ALIVE  0xFABB
#define AMQ_SERVER_CHANNEL_TABLE_DEAD   0xDEAD

#define AMQ_SERVER_CHANNEL_TABLE_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL amq_server_channel_table\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != AMQ_SERVER_CHANNEL_TABLE_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "amq_server_channel_table at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, AMQ_SERVER_CHANNEL_TABLE_ALIVE, self->object_tag);\
        amq_server_channel_table_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "amq_server_channel.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CHANNEL_TABLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CHANNEL_TABLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_AMQ_SERVER_CHANNEL_TABLE_UNSAFE
#   define INCLUDE_AMQ_SERVER_CHANNEL_TABLE_UNSAFE
#   define INCLUDE_AMQ_SERVER_CHANNEL_TABLE_ACTIVE

#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    amq_server_channel_table_animating;
#define AMQ_SERVER_CHANNEL_TABLE_INITIAL_SIZE  255
#define AMQ_SERVER_CHANNEL_TABLE_LOAD_FACTOR  75
#define AMQ_SERVER_CHANNEL_TABLE_GROWTH_FACTOR 200

typedef void (amq_server_channel_table_callback_fn) (amq_server_channel_t *item, void *argument);

//  Structure of the amq_server_channel_table object

struct _amq_server_channel_table_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_SERVER_CHANNEL_TABLE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH];
    int
        history_line  [AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH];
    char
        *history_type [AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH];
    int
        history_links [AMQ_SERVER_CHANNEL_TABLE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
size_t
    nbr_items;
size_t
    max_items;
amq_server_channel_t
    **table_items;
};

#   ifdef __cplusplus
}
#   endif
#   include "amq_server_channel.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define amq_server_channel_table_new()  amq_server_channel_table_new_ (__FILE__, __LINE__)
amq_server_channel_table_t *
    amq_server_channel_table_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_server_channel_table_selftest (
void);

int
    amq_server_channel_table_insert (
amq_server_channel_table_t * self,      //  Reference to object
int key,                                //  Hash key
amq_server_channel_t * item             //  Item to insert
);

int
    amq_server_channel_table_remove (
amq_server_channel_t * item             //  Item to remove
);

amq_server_channel_t *
    amq_server_channel_table_search (
amq_server_channel_table_t * self,      //  Table to search
int key                                 //  Hash key
);

void
    amq_server_channel_table_apply (
amq_server_channel_table_t * self,      //  Table to iterate
amq_server_channel_table_callback_fn * callback,   //  Not documented
void * argument                         //  Arbitrary argument pointer
);

void
    amq_server_channel_table_terminate (
void);

#define amq_server_channel_table_show(item,opcode,trace_file)  amq_server_channel_table_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    amq_server_channel_table_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_server_channel_table_destroy(self)  amq_server_channel_table_destroy_ (self, __FILE__, __LINE__)
void
    amq_server_channel_table_destroy_ (
amq_server_channel_table_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    amq_server_channel_table_read_lock (
amq_server_channel_table_t * self       //  Reference to object
);

int
    amq_server_channel_table_write_lock (
amq_server_channel_table_t * self       //  Reference to object
);

int
    amq_server_channel_table_unlock (
amq_server_channel_table_t * self       //  Reference to object
);

#define amq_server_channel_table_link(self)  amq_server_channel_table_link_ (self, __FILE__, __LINE__)
amq_server_channel_table_t *
    amq_server_channel_table_link_ (
amq_server_channel_table_t * self,      //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_server_channel_table_unlink(self)  amq_server_channel_table_unlink_ (self, __FILE__, __LINE__)
void
    amq_server_channel_table_unlink_ (
amq_server_channel_table_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    amq_server_channel_table_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define amq_server_channel_table_new_in_scope(self_p,_scope)  amq_server_channel_table_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    amq_server_channel_table_new_in_scope_ (
amq_server_channel_table_t * * self_p,   //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CHANNEL_TABLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CHANNEL_TABLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_AMQ_SERVER_CHANNEL_TABLE_INLINE)
#   define INCLUDE_AMQ_SERVER_CHANNEL_TABLE_INLINE
#   define INCLUDE_AMQ_SERVER_CHANNEL_TABLE_ACTIVE

#   include "amq_server_channel.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_AMQ_SERVER_CHANNEL_TABLE_ACTIVE
#   if defined (ICL_IMPORT_AMQ_SERVER_CHANNEL_TABLE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_AMQ_SERVER_CHANNEL_TABLE_ROOT
#   endif
# endif
#endif
