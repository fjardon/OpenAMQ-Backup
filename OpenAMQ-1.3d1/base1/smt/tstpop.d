/*---------------------------------------------------------------------------*
 *  tstpop.d - LIBERO dialog data definitions for tstpop.c.                  *
 *  Generated by LIBERO 2.4 on  6 Oct, 2010, 19:29.                          *
 *  Schema file used: smtschm.c.                                             *
 *---------------------------------------------------------------------------*/

/*- Symbolic constants and event numbers ------------------------------------*/

#define _LR_STOP                        0xFFFFL
#define _LR_NULL_EVENT                  -2
#define _LR_NULL_STATE                  -1
#define terminate_event                 -1
#define bad_id_error_event              0
#define bin_attach_event                1
#define bin_attach_info_event           2
#define connect_error_event             3
#define connect_ok_event                4
#define del_ok_event                    5
#define end_event                       6
#define hdr_event                       7
#define help_event                      8
#define info_response_event             9
#define msg_event                       10
#define msg_info_request_event          11
#define ok_event                        12
#define pop_error_event                 13
#define server_error_event              14
#define session_info_event              15
#define shutdown_event                  16
#define txt_attach_event                17
#define txt_attach_info_event           18
#define _LR_STATE_after_init            0
#define _LR_STATE_connected             1
#define _LR_STATE_sleep                 2
#define _LR_STATE_defaults              3
#define _LR_defaults_state              3


/*- Function prototypes and macros ------------------------------------------*/

#ifndef MODULE
#define MODULE  static void             /*  Libero dialog modules            */
#endif

MODULE initialise_the_thread        (THREAD *thread);
MODULE do_connect                   (THREAD *thread);
MODULE get_handle                   (THREAD *thread);
MODULE display_msg_count_and_size   (THREAD *thread);
MODULE get_and_send_user_request    (THREAD *thread);
MODULE display_info                 (THREAD *thread);
MODULE display_message_info         (THREAD *thread);
MODULE display_bad_id               (THREAD *thread);
MODULE display_message              (THREAD *thread);
MODULE display_header               (THREAD *thread);
MODULE display_del_ok               (THREAD *thread);
MODULE display_error                (THREAD *thread);
MODULE kill_pop3                    (THREAD *thread);
MODULE terminate_the_thread         (THREAD *thread);
MODULE display_usage                (THREAD *thread);

#define the_next_event              _the_next_event
#define the_exception_event         _the_exception_event
#define the_external_event          _the_external_event
#define exception_raised            _exception_raised
#define io_completed                _io_completed


/*- Static areas shared by all threads --------------------------------------*/

static word _LR_nextst [4][19] =
{
    { 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
    { 0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 2,0,0,0,0,2,2,2,0,2,2,2,0,0,2,0,0,0,0 },
    { 0,3,3,3,3,0,0,0,2,0,3,0,0,3,0,3,3,3,3 }
};

static word _LR_action [4][19] =
{
    { 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
    { 0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 5,0,0,0,0,8,10,7,0,3,6,4,0,0,9,0,0,0,0 },
    { 0,12,12,12,12,0,0,0,13,0,12,0,0,9,0,12,11,12,12 }
};

#if (defined (SMT_PROFILE))
static word _LR_count [14];
static long _LR_time  [14];
static word _LR_flow  [4][19];
#endif

static word _LR_offset [] =
{
    0,
    0,
    2,
    6,
    9,
    12,
    15,
    18,
    21,
    24,
    27,
    30,
    32,
    33
};

static word _LR_vector [] =
{
    0,_LR_STOP,
    1,2,3,_LR_STOP,
    4,3,_LR_STOP,
    5,3,_LR_STOP,
    6,3,_LR_STOP,
    7,3,_LR_STOP,
    8,3,_LR_STOP,
    9,3,_LR_STOP,
    10,3,_LR_STOP,
    11,12,_LR_STOP,
    12,_LR_STOP,
    _LR_STOP,
    13,3,_LR_STOP
};

static HOOK *_LR_module [14] = {
    do_connect,
    get_handle,
    display_msg_count_and_size,
    get_and_send_user_request,
    display_info,
    display_message_info,
    display_bad_id,
    display_message,
    display_header,
    display_del_ok,
    display_error,
    kill_pop3,
    terminate_the_thread,
    display_usage
};

#if (defined (DEBUG))
static char *_LR_mname [14] =
{
     "Do-Connect",
     "Get-Handle",
     "Display-Msg-Count-And-Size",
     "Get-And-Send-User-Request",
     "Display-Info",
     "Display-Message-Info",
     "Display-Bad-Id",
     "Display-Message",
     "Display-Header",
     "Display-Del-Ok",
     "Display-Error",
     "Kill-Pop3",
     "Terminate-The-Thread",
     "Display-Usage"
};

static char *_LR_sname [4] =
{
     "After-Init",
     "Connected",
     "Sleep",
     "Defaults"
};

static char *_LR_ename [19] =
{
     "Bad-Id-Error-Event",
     "Bin-Attach-Event",
     "Bin-Attach-Info-Event",
     "Connect-Error-Event",
     "Connect-Ok-Event",
     "Del-Ok-Event",
     "End-Event",
     "Hdr-Event",
     "Help-Event",
     "Info-Response-Event",
     "Msg-Event",
     "Msg-Info-Request-Event",
     "Ok-Event",
     "Pop-Error-Event",
     "Server-Error-Event",
     "Session-Info-Event",
     "Shutdown-Event",
     "Txt-Attach-Event",
     "Txt-Attach-Info-Event"
};
#else
static char *_LR_mname [14] =
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
     "9",
     "10",
     "11",
     "12",
     "13"
};

static char *_LR_sname [4] =
{
     "0",
     "1",
     "2",
     "3"
};

static char *_LR_ename [19] =
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
     "9",
     "10",
     "11",
     "12",
     "13",
     "14",
     "15",
     "16",
     "17",
     "18"
};
#endif
