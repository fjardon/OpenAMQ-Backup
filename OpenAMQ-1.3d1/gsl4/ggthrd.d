/*---------------------------------------------------------------------------*
 *  ggthrd.d - LIBERO dialog data definitions for ggthrd.c.                  *
 *  Generated by LIBERO 2.4 on  6 Oct, 2010, 19:30.                          *
 *  Schema file used: smtschm.c.                                             *
 *---------------------------------------------------------------------------*/

/*- Symbolic constants and event numbers ------------------------------------*/

#define _LR_STOP                        0xFFFFL
#define _LR_NULL_EVENT                  -2
#define _LR_NULL_STATE                  -1
#define terminate_event                 -1
#define error_event                     0
#define interrupt_event                 1
#define message_event                   2
#define ok_event                        3
#define parse_event                     4
#define parse_and_run_event             5
#define run_event                       6
#define shutdown_event                  7
#define _LR_STATE_after_init            0
#define _LR_STATE_parsing               1
#define _LR_STATE_running               2
#define _LR_STATE_parsing_before_run    3
#define _LR_STATE_defaults              4
#define _LR_defaults_state              4


/*- Function prototypes and macros ------------------------------------------*/

#ifndef MODULE
#define MODULE  static void             /*  Libero dialog modules            */
#endif

MODULE initialise_the_thread        (THREAD *thread);
MODULE spawn_gsl_thread             (THREAD *thread);
MODULE log_message                  (THREAD *thread);
MODULE reply_parsed_ok_result       (THREAD *thread);
MODULE terminate_the_thread         (THREAD *thread);
MODULE reply_parse_error_result     (THREAD *thread);
MODULE destroy_the_thread           (THREAD *thread);
MODULE set_thread_finished_status   (THREAD *thread);
MODULE set_thread_error_status      (THREAD *thread);
MODULE reply_running_ok_result      (THREAD *thread);
MODULE shutdown_running_gsl_thread  (THREAD *thread);

#define the_next_event              _the_next_event
#define the_exception_event         _the_exception_event
#define the_external_event          _the_external_event
#define exception_raised            _exception_raised
#define io_completed                _io_completed


/*- Static areas shared by all threads --------------------------------------*/

static word _LR_nextst [5][8] =
{
    { 0,0,0,0,1,3,2,0 },
    { 1,0,1,1,0,0,0,1 },
    { 2,0,0,2,0,0,0,2 },
    { 3,0,3,2,0,0,0,3 },
    { 0,4,0,0,0,0,0,0 }
};

static word _LR_action [5][8] =
{
    { 0,0,0,0,1,1,2,0 },
    { 5,0,3,4,0,0,0,6 },
    { 8,0,0,7,0,0,0,6 },
    { 5,0,3,9,0,0,0,6 },
    { 0,10,0,0,0,0,0,0 }
};

#if (defined (SMT_PROFILE))
static word _LR_count [10];
static long _LR_time  [10];
static word _LR_flow  [5][8];
#endif

static word _LR_offset [] =
{
    0,
    0,
    1,
    3,
    5,
    8,
    12,
    14,
    17,
    20,
    23
};

static word _LR_vector [] =
{
    _LR_STOP,
    0,_LR_STOP,
    1,_LR_STOP,
    2,3,_LR_STOP,
    4,5,3,_LR_STOP,
    3,_LR_STOP,
    6,3,_LR_STOP,
    7,3,_LR_STOP,
    8,0,_LR_STOP,
    9,3,_LR_STOP
};

static HOOK *_LR_module [10] = {
    spawn_gsl_thread,
    log_message,
    reply_parsed_ok_result,
    terminate_the_thread,
    reply_parse_error_result,
    destroy_the_thread,
    set_thread_finished_status,
    set_thread_error_status,
    reply_running_ok_result,
    shutdown_running_gsl_thread
};

#if (defined (DEBUG))
static char *_LR_mname [10] =
{
     "Spawn-Gsl-Thread",
     "Log-Message",
     "Reply-Parsed-Ok-Result",
     "Terminate-The-Thread",
     "Reply-Parse-Error-Result",
     "Destroy-The-Thread",
     "Set-Thread-Finished-Status",
     "Set-Thread-Error-Status",
     "Reply-Running-Ok-Result",
     "Shutdown-Running-Gsl-Thread"
};

static char *_LR_sname [5] =
{
     "After-Init",
     "Parsing",
     "Running",
     "Parsing-Before-Run",
     "Defaults"
};

static char *_LR_ename [8] =
{
     "Error-Event",
     "Interrupt-Event",
     "Message-Event",
     "Ok-Event",
     "Parse-Event",
     "Parse-And-Run-Event",
     "Run-Event",
     "Shutdown-Event"
};
#else
static char *_LR_mname [10] =
{
     "0",
     "1",
     "2",
     "3",
     "4",
     "5",
     "6",
     "7",
     "8",
     "9"
};

static char *_LR_sname [5] =
{
     "0",
     "1",
     "2",
     "3",
     "4"
};

static char *_LR_ename [8] =
{
     "0",
     "1",
     "2",
     "3",
     "4",
     "5",
     "6",
     "7"
};
#endif
