/*---------------------------------------------------------------------------*
 *  ggsock.d - LIBERO dialog data definitions for ggsock.c.                  *
 *  Generated by LIBERO 2.4 on  6 Oct, 2010, 19:32.                          *
 *  Schema file used: smtschm.c.                                             *
 *---------------------------------------------------------------------------*/

/*- Symbolic constants and event numbers ------------------------------------*/

#define _LR_STOP                        0xFFFFL
#define _LR_NULL_EVENT                  -2
#define _LR_NULL_STATE                  -1
#define terminate_event                 -1
#define closed_event                    0
#define connect_ok_event                1
#define error_event                     2
#define ok_event                        3
#define readh_closed_event              4
#define readh_ok_event                  5
#define readh_timeout_event             6
#define shutdown_event                  7
#define timeout_event                   8
#define _LR_STATE_after_init            0
#define _LR_STATE_waiting               1


/*- Function prototypes and macros ------------------------------------------*/

#ifndef MODULE
#define MODULE  static void             /*  Libero dialog modules            */
#endif

MODULE initialise_the_thread        (THREAD *thread);
MODULE reply_ok_result              (THREAD *thread);
MODULE terminate_the_thread         (THREAD *thread);
MODULE reply_error_result           (THREAD *thread);
MODULE reply_closed_result          (THREAD *thread);
MODULE reply_timeout_result         (THREAD *thread);
MODULE reply_connect_ok_result      (THREAD *thread);
MODULE reply_readh_ok_result        (THREAD *thread);
MODULE reply_readh_closed_result    (THREAD *thread);
MODULE reply_readh_timeout_result   (THREAD *thread);

#define the_next_event              _the_next_event
#define the_exception_event         _the_exception_event
#define the_external_event          _the_external_event
#define exception_raised            _exception_raised
#define io_completed                _io_completed


/*- Static areas shared by all threads --------------------------------------*/

static word _LR_nextst [2][9] =
{
    { 0,0,0,1,0,0,0,0,0 },
    { 1,1,1,1,1,1,1,1,1 }
};

static word _LR_action [2][9] =
{
    { 0,0,0,1,0,0,0,0,0 },
    { 4,6,3,2,8,7,9,10,5 }
};

#if (defined (SMT_PROFILE))
static word _LR_count [9];
static long _LR_time  [9];
static word _LR_flow  [2][9];
#endif

static word _LR_offset [] =
{
    0,
    0,
    1,
    4,
    7,
    10,
    13,
    16,
    19,
    22,
    25
};

static word _LR_vector [] =
{
    _LR_STOP,
    0,1,_LR_STOP,
    2,1,_LR_STOP,
    3,1,_LR_STOP,
    4,1,_LR_STOP,
    5,1,_LR_STOP,
    6,1,_LR_STOP,
    7,1,_LR_STOP,
    8,1,_LR_STOP,
    1,_LR_STOP
};

static HOOK *_LR_module [9] = {
    reply_ok_result,
    terminate_the_thread,
    reply_error_result,
    reply_closed_result,
    reply_timeout_result,
    reply_connect_ok_result,
    reply_readh_ok_result,
    reply_readh_closed_result,
    reply_readh_timeout_result
};

#if (defined (DEBUG))
static char *_LR_mname [9] =
{
     "Reply-Ok-Result",
     "Terminate-The-Thread",
     "Reply-Error-Result",
     "Reply-Closed-Result",
     "Reply-Timeout-Result",
     "Reply-Connect-Ok-Result",
     "Reply-Readh-Ok-Result",
     "Reply-Readh-Closed-Result",
     "Reply-Readh-Timeout-Result"
};

static char *_LR_sname [2] =
{
     "After-Init",
     "Waiting"
};

static char *_LR_ename [9] =
{
     "Closed-Event",
     "Connect-Ok-Event",
     "Error-Event",
     "Ok-Event",
     "Readh-Closed-Event",
     "Readh-Ok-Event",
     "Readh-Timeout-Event",
     "Shutdown-Event",
     "Timeout-Event"
};
#else
static char *_LR_mname [9] =
{
     "0",
     "1",
     "2",
     "3",
     "4",
     "5",
     "6",
     "7",
     "8"
};

static char *_LR_sname [2] =
{
     "0",
     "1"
};

static char *_LR_ename [9] =
{
     "0",
     "1",
     "2",
     "3",
     "4",
     "5",
     "6",
     "7",
     "8"
};
#endif
