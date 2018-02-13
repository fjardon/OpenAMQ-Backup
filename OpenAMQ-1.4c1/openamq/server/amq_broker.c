/*---------------------------------------------------------------------------
    amq_broker.c - amq_broker component

    Generated from amq_broker.icl by smt_object_gen using GSL/4.
    
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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "amq_broker.h"                 //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_broker_t

//  Shorthands for class methods

#define self_new            amq_broker_new
#define self_annihilate     amq_broker_annihilate
#define self_unbind_queue   amq_broker_unbind_queue
#define self_delete_queue   amq_broker_delete_queue
#define self_selftest       amq_broker_selftest
#define self_inspect_shim   amq_broker_inspect_shim
#define self_inspect        amq_broker_inspect
#define self_modify_shim    amq_broker_modify_shim
#define self_modify         amq_broker_modify
#define self_method_shim    amq_broker_method_shim
#define self_method         amq_broker_method
#define self_unlink_shim    amq_broker_unlink_shim
#define self_initialise     amq_broker_initialise
#define self_terminate      amq_broker_terminate
#define self_free           amq_broker_free
#define self_start          amq_broker_start
#define self_shutdown       amq_broker_shutdown
#define self_destroy        amq_broker_destroy
#define self_unlink         amq_broker_unlink
#define self_show_animation  amq_broker_show_animation
#define self_show           amq_broker_show
#define self_alloc          amq_broker_alloc
#define self_link           amq_broker_link
#define self_cache_initialise  amq_broker_cache_initialise
#define self_cache_purge    amq_broker_cache_purge
#define self_cache_terminate  amq_broker_cache_terminate
#define self_new_in_scope   amq_broker_new_in_scope

#define amq_broker_annihilate(self)     amq_broker_annihilate_ (self, __FILE__, __LINE__)
static int
    amq_broker_annihilate_ (
amq_broker_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_broker_initialise (
void);

#define amq_broker_alloc()              amq_broker_alloc_ (__FILE__, __LINE__)
static amq_broker_t *
    amq_broker_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    amq_broker_cache_initialise (
void);

static void
    amq_broker_cache_purge (
void);

static void
    amq_broker_cache_terminate (
void);

Bool
    amq_broker_animating = TRUE;        //  Animation enabled by default
static Bool
    s_amq_broker_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_amq_broker_mutex       = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static void
    s_format_logfile (char *logfile, char *configured);
static amq_console_class_t
    *s_class;                           //  Class descriptor
//  Prototypes for local functions
static void
s_exchange_declare (
    amq_broker_t *self, char *name, int type, Bool default_exchange, Bool auto_federate);
amq_broker_t
    *amq_broker = NULL;
/*  -------------------------------------------------------------------------
    amq_broker_new

    Type: Component method
    Creates and initialises a new amq_broker_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_broker_t *
    amq_broker_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
char
    *log_path,                      //  Log directory
    *archive_cmd;                   //  Archive command
icl_shortstr_t
    log_name,                       //  Full logfile name
    stats_file;                     //  Statistics file name
smt_thread_t
    *thread_p;                      //  Thread from amq_server_server_agent
    amq_broker_t *
        self = NULL;                    //  Object reference

if (!s_amq_broker_active)
    self_initialise ();
    self = amq_broker_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_BROKER_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_broker_show_);
#endif

self->console = amq_console_link (amq_console);
self->object_id = icl_atomic_inc32 ((volatile qbyte *) &amq_object_id);
amq_console_register (self->console, self->object_id, self_link (self), s_class, 0);
self->thread = amq_broker_agent_class_thread_new (self);
self->thread->animate = TRUE;

//
//  Set self so that we're immediately addressable in other threads
amq_broker = self;

self->started         = smt_time_now ();
self->connections     = amq_server_connection_table_new ();
self->connection_list = amq_server_connection_list_new ();
self->monitor_timer   = amq_server_config_monitor (amq_server_config);
self->imeter          = ipr_meter_new ();
self->ometer          = ipr_meter_new ();
ipr_str_random (self->identifier, "AAAAAAAA-AAAAAAAA-AAAAAAAA");

//  Set up log files and log forwarding:
log_path     = amq_server_config_log_path      (amq_server_config);
archive_cmd  = amq_server_config_archive_cmd   (amq_server_config);

self->debug_log = smt_log_new ();   //  Debug log for low-level trace
self->daily_log = smt_log_new ();   //  Daily log for normal activity
self->alert_log = smt_log_new ();   //  Alert log for exceptions

if (amq_server_config_syslog (amq_server_config)) {
    if (ipr_log_sysopen ("amq_server"))
        icl_console_print (
            "W: syslog not available, using direct-to-file logging");
    smt_log_set_syslog (self->debug_log, IPR_LOG_SYSDEBUG);
    smt_log_set_syslog (self->daily_log, IPR_LOG_SYSINFO);
    smt_log_set_syslog (self->alert_log, IPR_LOG_SYSWARNING);
}
else
if (amq_server_config_keep_logs (amq_server_config)) {
    s_format_logfile (log_name, amq_server_config_debug_log (amq_server_config));
    smt_log_open (self->debug_log, log_name, log_path, archive_cmd);
    s_format_logfile (log_name, amq_server_config_daily_log (amq_server_config));
    smt_log_open (self->daily_log, log_name, log_path, archive_cmd);
    s_format_logfile (log_name, amq_server_config_alert_log (amq_server_config));
    smt_log_open (self->alert_log, log_name, log_path, archive_cmd);
}
//  Dump environment and configuration to debug log, silently
smt_log_dump_env (self->debug_log);
amq_server_config_dump_log (amq_server_config, self->debug_log);

//  Set up log file associations and configuration
smt_log_set_stderr (self->debug_log, TRUE);
smt_log_set_copyto (self->daily_log, self->debug_log);
smt_log_set_stderr (self->alert_log, TRUE);
smt_log_set_copyto (self->alert_log, self->daily_log);

if (amq_server_config_record_stats (amq_server_config)) {
    icl_shortstr_fmt (stats_file, "amq_server_stats_%s.del",
        amq_server_config_port (amq_server_config));
    self->stats = fopen (stats_file, "w");
    //  We use a tab-delimited form that pastes easily into spreadsheets
    fprintf (self->stats, "Clients\tMsgMemK\tCurIn\tCurOut\tAvgIn\tAvgOut\n");
}
//  Start server agent and own async thread
if (amq_server_agent_init (&thread_p) == SMT_OK) {
    self->agent_thread = smt_thread_link (thread_p);
    self_start (self);
}

self->dump_state_timer = amq_server_config_dump_state (amq_server_config);
self->auto_crash_timer = amq_server_config_auto_crash (amq_server_config);
self->auto_block_timer = amq_server_config_auto_block (amq_server_config);
self->mgt_connection_list = amq_connection_by_broker_new ();
amq_console_config = amq_console_config_new (self);

self->exchange_table = amq_exchange_table_new ();
self->exchange_list  = amq_exchange_list_new ();
self->queue_table    = amq_queue_table_new ();
self->queue_list     = amq_queue_list_new ();
self->shared_queues  = ipr_symbol_table_new ();

//  Automatic wiring schemes
//  If you change these, please maintain zyre/zyre_restms.icl
s_exchange_declare (self, "$default$",   AMQ_EXCHANGE_DIRECT,  TRUE,  FALSE);
s_exchange_declare (self, "amq.fanout",  AMQ_EXCHANGE_FANOUT,  FALSE, FALSE);
s_exchange_declare (self, "amq.direct",  AMQ_EXCHANGE_DIRECT,  FALSE, FALSE);
s_exchange_declare (self, "amq.topic",   AMQ_EXCHANGE_TOPIC,   FALSE, FALSE);
s_exchange_declare (self, "amq.headers", AMQ_EXCHANGE_HEADERS, FALSE, FALSE);
s_exchange_declare (self, "amq.regexp",  AMQ_EXCHANGE_REGEXP,  FALSE, FALSE);
s_exchange_declare (self, "amq.system",  AMQ_EXCHANGE_SYSTEM,  FALSE, FALSE);
s_exchange_declare (self, "amq.status",  AMQ_EXCHANGE_DIRECT,  FALSE, FALSE);
s_exchange_declare (self, "amq.notify",  AMQ_EXCHANGE_TOPIC,   FALSE, FALSE);

//  These exchanges are automatically federated if --attach is specified
s_exchange_declare (self, "amq.service", AMQ_EXCHANGE_DIRECT,  FALSE, TRUE);
s_exchange_declare (self, "amq.data",    AMQ_EXCHANGE_TOPIC,   FALSE, TRUE);
s_exchange_declare (self, "amq.dataex",  AMQ_EXCHANGE_HEADERS, FALSE, TRUE);

randomize ();
if (self->auto_crash_timer)
    self->auto_crash_timer = randomof (self->auto_crash_timer) + 1;
if (self->auto_block_timer)
    self->auto_block_timer = randomof (self->auto_block_timer) + 1;

//  Initialise failover agent
self->failover = amq_failover_new ();

//  Calculate server performance
smt_coremark_calculate (self->daily_log, amq_server_config_coremark_cycles (amq_server_config));
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_broker_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    amq_broker_annihilate_ (
    amq_broker_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    int
        history_last;
#endif

    amq_broker_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_BROKER_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_BROKER_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_BROKER_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_BROKER_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (amq_broker_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_unbind_queue

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Unbind a queue from the broker.
    -------------------------------------------------------------------------
 */

int
    amq_broker_unbind_queue (
    amq_broker_t * self,                //  Reference to object
    amq_queue_t * queue                 //  The queue to unbind
)
{
    int
        rc = 0;                         //  Return code

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_broker_agent_unbind_queue (self->thread,queue)) {
        //icl_console_print ("Error sending 'unbind queue' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_delete_queue

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Unbind and delete a queue from the broker.
    -------------------------------------------------------------------------
 */

int
    amq_broker_delete_queue (
    amq_broker_t * self,                //  Reference to object
    amq_queue_t * queue                 //  The queue to unbind
)
{
    int
        rc = 0;                         //  Return code

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (amq_broker_agent_delete_queue (self->thread,queue)) {
        //icl_console_print ("Error sending 'delete queue' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_broker_selftest (
void)
{

}
/*  -------------------------------------------------------------------------
    amq_broker_inspect_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_broker_inspect_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Not documented

self_inspect ((amq_broker_t *) (self_v), request);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_inspect

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_broker_inspect (
    amq_broker_t * self,                //  Reference to object
    amq_content_basic_t * request       //  The original request
)
{
    int
        rc = 0;                         //  Return code

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_broker_agent_inspect (self->thread,request)) {
        //icl_console_print ("Error sending 'inspect' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_modify_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_broker_modify_shim (
    void * self_v,                      //  Object cast as a void *
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

self_modify ((amq_broker_t *) (self_v), request, fields);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_modify

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_broker_modify (
    amq_broker_t * self,                //  Reference to object
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Return code

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_broker_agent_modify (self->thread,request,fields)) {
        //icl_console_print ("Error sending 'modify' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_method_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_broker_method_shim (
    void * self_v,                      //  Object cast as a void *
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Fields to modify
)
{
    int
        rc = 0;                         //  Not documented

self_method ((amq_broker_t *) (self_v), method_name, request, fields);

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_method

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_broker_method (
    amq_broker_t * self,                //  Reference to object
    char * method_name,                 //  Method name
    amq_content_basic_t * request,      //  The original request
    asl_field_list_t * fields           //  Argument fields
)
{
    int
        rc = 0;                         //  Return code

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_broker_agent_method (self->thread,method_name,request,fields)) {
        //icl_console_print ("Error sending 'method' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_unlink_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_broker_unlink_shim (
    void * object_p                     //  Reference pointer cast as a void *
)
{

//
amq_broker_unlink (((amq_broker_t **) object_p));
}
/*  -------------------------------------------------------------------------
    amq_broker_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_broker_initialise (
void)
{

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_amq_broker_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        if (!icl_global_mutex) {
            icl_system_panic ("icl_init", "iCL not initialised - call icl_system_initialise()\n");
            abort ();
        }
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_amq_broker_mutex)
            s_amq_broker_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_amq_broker_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_amq_broker_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

amq_broker_agent_init ();

s_class = amq_console_class_new ();
s_class->name    = "broker";
s_class->inspect = amq_broker_inspect_shim;
s_class->modify  = amq_broker_modify_shim;
s_class->method  = amq_broker_method_shim;
s_class->unlink  = amq_broker_unlink_shim;
            s_amq_broker_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_amq_broker_mutex);
#endif

    }
}
/*  -------------------------------------------------------------------------
    amq_broker_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_broker_terminate (
void)
{

if (s_amq_broker_active) {

amq_console_class_destroy (&s_class);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_amq_broker_mutex);
#endif
        s_amq_broker_active = FALSE;
    }
}
/*  -------------------------------------------------------------------------
    amq_broker_free

    Type: Component method
    Freess a amq_broker_t object.
    -------------------------------------------------------------------------
 */

void
    amq_broker_free_ (
    amq_broker_t * self,                //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BROKER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BROKER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BROKER_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_BROKER_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);

smt_log_destroy (&self->alert_log);
smt_log_destroy (&self->daily_log);
smt_log_destroy (&self->debug_log);
        memset (&self->object_tag, 0, sizeof (amq_broker_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (amq_broker_t));
        self->object_tag = AMQ_BROKER_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_broker_start

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_broker_start (
    amq_broker_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_broker_agent_start (self->thread)) {
        //icl_console_print ("Error sending 'start' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_shutdown

    Type: Component method
    Accepts a amq_broker_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    amq_broker_shutdown (
    amq_broker_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_BROKER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (amq_broker_agent_shutdown (self->thread)) {
        //icl_console_print ("Error sending 'shutdown' method to amq_broker agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_broker_destroy_ (
    amq_broker_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_broker_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = amq_broker_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_broker_free (self);
    *self_p = NULL;
}

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_broker_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_broker_unlink_ (
    amq_broker_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    int
        history_last;
#endif
    amq_broker_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on amq_broker object");
            amq_broker_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BROKER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BROKER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BROKER_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_BROKER_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                amq_broker_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                amq_broker_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
}
/*  -------------------------------------------------------------------------
    amq_broker_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_broker_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_broker_animating = enabled;

amq_broker_agent_animate (enabled);
}
/*  -------------------------------------------------------------------------
    amq_broker_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_broker_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_broker_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_broker zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    if (self->history_last > AMQ_BROKER_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_BROKER_HISTORY_LENGTH;
        self->history_last %= AMQ_BROKER_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_BROKER_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_broker>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_broker_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_broker_t *
    amq_broker_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_broker_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_broker_cache_initialise ();

self = (amq_broker_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (amq_broker_t));



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_broker_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_broker_t *
    amq_broker_link_ (
    amq_broker_t * self,                //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
    int
        history_last;
#endif

    if (self) {
        AMQ_BROKER_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_BROKER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_BROKER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_BROKER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_BROKER_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_BROKER_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_broker_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_broker_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_broker_t));
icl_system_register (amq_broker_cache_purge, amq_broker_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_broker_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_broker_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_broker_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_broker_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_broker_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_broker_new_in_scope_ (
    amq_broker_t * * self_p,            //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_broker_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_broker_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Format a logfile name including the port.
static void
s_format_logfile (char *log_name, char *configured)
{
    char
        *point;

    point = strchr (configured, '.');
    if (point) {
        //  Insert port number before extension
        icl_shortstr_ncpy (log_name, configured, point - configured);
        icl_shortstr_cat  (log_name, "_");
        icl_shortstr_cat  (log_name, amq_server_config_port (amq_server_config));
        icl_shortstr_cat  (log_name, point);
    }
    else {
        //  Add port number at end
        icl_shortstr_cpy  (log_name, configured);
        icl_shortstr_cat  (log_name, "_");
        icl_shortstr_cat  (log_name, amq_server_config_port (amq_server_config));
        icl_shortstr_cat  (log_name, ".log");
    }
}

static void
s_exchange_declare (
    amq_broker_t *self,
    char *name,
    int   type,
    Bool  default_exchange,
    Bool  auto_federate)
{
    amq_exchange_t
        *exchange;                      //  Predeclared exchange
    exchange = amq_exchange_new (
        type,                           //  Exchange type
        name,                           //  Exchange name
        default_exchange,               //  Internal?
        auto_federate);                 //  Federate automatically?
    assert (exchange);

    //  If this is the default exchange grab hold of it in self
    if (default_exchange)
        self->default_exchange = exchange;
    else
        amq_exchange_unlink (&exchange);
}

//  Embed the version information in the resulting binary

char *EMBED__amq_broker_version_start     = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_broker_component         = "amq_broker ";
char *EMBED__amq_broker_version           = "1.0 ";
char *EMBED__amq_broker_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_broker_filename          = "amq_broker.icl ";
char *EMBED__amq_broker_builddate         = "2010/10/06 ";
char *EMBED__amq_broker_version_end       = "VeRsIoNeNd:ipc";

