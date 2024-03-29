/*---------------------------------------------------------------------------*
 *  smtsmtp.d - LIBERO dialog data definitions for smtsmtp.c.                *
 *  Generated by LIBERO 2.4 on  6 Oct, 2010, 19:29.                          *
 *  Schema file used: smtschm.c.                                             *
 *---------------------------------------------------------------------------*/

/*- Symbolic constants and event numbers ------------------------------------*/

#define _LR_STOP                        0xFFFFL
#define _LR_NULL_EVENT                  -2
#define _LR_NULL_STATE                  -1
#define terminate_event                 -1
#define bad_attachment_event            0
#define cache_creation_error_event      1
#define close_mail_event                2
#define io_error_event                  3
#define mail_chunk_event                4
#define master_event                    5
#define memory_error_event              6
#define no_event                        7
#define open_mail_event                 8
#define send_mail_event                 9
#define server_response_error_event     10
#define server_response_ok_event        11
#define shutdown_event                  12
#define snprintf_error_event            13
#define sock_closed_event               14
#define sock_connect_ok_event           15
#define sock_error_event                16
#define sock_ok_event                   17
#define sock_read_closed_event          18
#define sock_read_ok_event              19
#define sock_timeout_event              20
#define undefined_event                 21
#define yes_event                       22
#define _LR_STATE_after_init            0
#define _LR_STATE_waiting_master_input  1
#define _LR_STATE_has_connection        2
#define _LR_STATE_has_response          3
#define _LR_STATE_has_helo_response     4
#define _LR_STATE_has_from_mailer_response 5
#define _LR_STATE_has_recipient         6
#define _LR_STATE_has_recipient_response 7
#define _LR_STATE_has_data_header_response 8
#define _LR_STATE_sending_text_body     9
#define _LR_STATE_after_sending_chunk   10
#define _LR_STATE_has_body_response     11
#define _LR_STATE_has_quit_response     12
#define _LR_STATE_defaults              13
#define _LR_defaults_state              13


/*- Function prototypes and macros ------------------------------------------*/

#ifndef MODULE
#define MODULE  static void             /*  Libero dialog modules            */
#endif

MODULE initialise_the_thread        (THREAD *thread);
MODULE connect_smtp_server          (THREAD *thread);
MODULE create_child_thread          (THREAD *thread);
MODULE store_socket_handle          (THREAD *thread);
MODULE write_helo                   (THREAD *thread);
MODULE read_server_response         (THREAD *thread);
MODULE check_server_response        (THREAD *thread);
MODULE close_connection             (THREAD *thread);
MODULE send_error_to_client         (THREAD *thread);
MODULE terminate_the_thread         (THREAD *thread);
MODULE build_timeout_error          (THREAD *thread);
MODULE write_from_mailer            (THREAD *thread);
MODULE build_recipients             (THREAD *thread);
MODULE check_recipient_left         (THREAD *thread);
MODULE write_next_recipient         (THREAD *thread);
MODULE write_data_header            (THREAD *thread);
MODULE write_body_header            (THREAD *thread);
MODULE generate_thread_type_event   (THREAD *thread);
MODULE write_text_body              (THREAD *thread);
MODULE write_end                    (THREAD *thread);
MODULE wait_socket_ready_for_output (THREAD *thread);
MODULE write_text_chunk             (THREAD *thread);
MODULE send_ok_to_client            (THREAD *thread);
MODULE write_quit                   (THREAD *thread);
MODULE build_socket_closed_error    (THREAD *thread);
MODULE build_socket_read_closed_error (THREAD *thread);
MODULE build_socket_timeout_error   (THREAD *thread);
MODULE build_socket_error           (THREAD *thread);

#define the_next_event              _the_next_event
#define the_exception_event         _the_exception_event
#define the_external_event          _the_external_event
#define exception_raised            _exception_raised
#define io_completed                _io_completed


/*- Static areas shared by all threads --------------------------------------*/

static word _LR_nextst [14][23] =
{
    { 0,0,0,0,0,1,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,3,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,4,5,0,0,0,0,0,0,0,4,4,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,5,6,0,0,0,0,0,0,0,5,5,0,0 },
    { 0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7 },
    { 0,0,0,0,0,0,0,0,0,0,7,6,0,0,0,0,0,0,0,7,7,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,8,9,0,0,0,0,0,0,0,8,8,0,0 },
    { 0,0,11,0,10,0,0,0,10,11,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,11,12,0,0,0,0,0,0,0,11,11,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,12,12,0,0,0,0,0,0,0,12,12,0,0 },
    { 13,13,0,13,0,0,13,0,0,0,0,0,13,13,13,0,13,0,13,0,13,13,0 }
};

static word _LR_action [14][23] =
{
    { 0,0,0,0,0,1,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,5,7,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,6,8,0,0,0,0,0,0,0,5,7,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,6,9,0,0,0,0,0,0,0,5,7,0,0 },
    { 0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10 },
    { 0,0,0,0,0,0,0,0,0,0,6,12,0,0,0,0,0,0,0,5,7,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,6,13,0,0,0,0,0,0,0,5,7,0,0 },
    { 0,0,17,0,16,0,0,0,15,14,0,0,0,0,0,0,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,6,19,0,0,0,0,0,0,0,5,7,0,0 },
    { 0,0,0,0,0,0,0,0,0,0,6,20,0,0,0,0,0,0,0,5,7,0,0 },
    { 22,21,0,21,0,0,22,0,0,0,0,0,21,21,23,0,26,0,24,0,25,21,0 }
};

#if (defined (SMT_PROFILE))
static word _LR_count [27];
static long _LR_time  [27];
static word _LR_flow  [14][23];
#endif

static word _LR_offset [] =
{
    0,
    0,
    1,
    3,
    5,
    9,
    11,
    15,
    19,
    22,
    25,
    28,
    31,
    33,
    36,
    40,
    43,
    46,
    49,
    51,
    54,
    58,
    60,
    63,
    67,
    71,
    75
};

static word _LR_vector [] =
{
    _LR_STOP,
    0,_LR_STOP,
    1,_LR_STOP,
    2,3,4,_LR_STOP,
    5,_LR_STOP,
    6,7,8,_LR_STOP,
    9,7,8,_LR_STOP,
    10,4,_LR_STOP,
    11,12,_LR_STOP,
    13,4,_LR_STOP,
    14,4,_LR_STOP,
    12,_LR_STOP,
    15,16,_LR_STOP,
    17,18,4,_LR_STOP,
    17,19,_LR_STOP,
    20,19,_LR_STOP,
    18,4,_LR_STOP,
    21,_LR_STOP,
    22,4,_LR_STOP,
    6,21,8,_LR_STOP,
    8,_LR_STOP,
    7,8,_LR_STOP,
    23,7,8,_LR_STOP,
    24,7,8,_LR_STOP,
    25,7,8,_LR_STOP,
    26,7,8,_LR_STOP
};

static HOOK *_LR_module [27] = {
    connect_smtp_server,
    create_child_thread,
    store_socket_handle,
    write_helo,
    read_server_response,
    check_server_response,
    close_connection,
    send_error_to_client,
    terminate_the_thread,
    build_timeout_error,
    write_from_mailer,
    build_recipients,
    check_recipient_left,
    write_next_recipient,
    write_data_header,
    write_body_header,
    generate_thread_type_event,
    write_text_body,
    write_end,
    wait_socket_ready_for_output,
    write_text_chunk,
    send_ok_to_client,
    write_quit,
    build_socket_closed_error,
    build_socket_read_closed_error,
    build_socket_timeout_error,
    build_socket_error
};

#if (defined (DEBUG))
static char *_LR_mname [27] =
{
     "Connect-Smtp-Server",
     "Create-Child-Thread",
     "Store-Socket-Handle",
     "Write-Helo",
     "Read-Server-Response",
     "Check-Server-Response",
     "Close-Connection",
     "Send-Error-To-Client",
     "Terminate-The-Thread",
     "Build-Timeout-Error",
     "Write-From-Mailer",
     "Build-Recipients",
     "Check-Recipient-Left",
     "Write-Next-Recipient",
     "Write-Data-Header",
     "Write-Body-Header",
     "Generate-Thread-Type-Event",
     "Write-Text-Body",
     "Write-End",
     "Wait-Socket-Ready-For-Output",
     "Write-Text-Chunk",
     "Send-Ok-To-Client",
     "Write-Quit",
     "Build-Socket-Closed-Error",
     "Build-Socket-Read-Closed-Error",
     "Build-Socket-Timeout-Error",
     "Build-Socket-Error"
};

static char *_LR_sname [14] =
{
     "After-Init",
     "Waiting-Master-Input",
     "Has-Connection",
     "Has-Response",
     "Has-Helo-Response",
     "Has-From-Mailer-Response",
     "Has-Recipient",
     "Has-Recipient-Response",
     "Has-Data-Header-Response",
     "Sending-Text-Body",
     "After-Sending-Chunk",
     "Has-Body-Response",
     "Has-Quit-Response",
     "Defaults"
};

static char *_LR_ename [23] =
{
     "Bad-Attachment-Event",
     "Cache-Creation-Error-Event",
     "Close-Mail-Event",
     "Io-Error-Event",
     "Mail-Chunk-Event",
     "Master-Event",
     "Memory-Error-Event",
     "No-Event",
     "Open-Mail-Event",
     "Send-Mail-Event",
     "Server-Response-Error-Event",
     "Server-Response-Ok-Event",
     "Shutdown-Event",
     "Snprintf-Error-Event",
     "Sock-Closed-Event",
     "Sock-Connect-Ok-Event",
     "Sock-Error-Event",
     "Sock-Ok-Event",
     "Sock-Read-Closed-Event",
     "Sock-Read-Ok-Event",
     "Sock-Timeout-Event",
     "Undefined-Event",
     "Yes-Event"
};
#else
static char *_LR_mname [27] =
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
     "18",
     "19",
     "20",
     "21",
     "22",
     "23",
     "24",
     "25",
     "26"
};

static char *_LR_sname [14] =
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

static char *_LR_ename [23] =
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
     "18",
     "19",
     "20",
     "21",
     "22"
};
#endif
