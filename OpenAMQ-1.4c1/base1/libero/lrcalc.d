/*---------------------------------------------------------------------------*
 *  lrcalc.d - LIBERO dialog data definitions for lrcalc.c.                  *
 *  Generated by LIBERO 2.4 on  6 Oct, 2010, 19:32.                          *
 *  Schema file used: lrschema.c.                                            *
 *---------------------------------------------------------------------------*/

/*- Symbolic constants and event numbers ------------------------------------*/

#define _LR_STOP                        0xFFFFL
#define _LR_NULL_EVENT                  -2
enum {
    terminate_event = -1,
    end_mark_event = 0,
    error_event = 1,
    exception_event = 2,
    factor_op_event = 3,
    left_par_event = 4,
    number_event = 5,
    ok_event = 6,
    right_par_event = 7,
    term_op_event = 8
};

enum {
    _LR_defaults_state = 4,
    _LR_STATE_after_init = 0,
    _LR_STATE_expecting_initial = 1,
    _LR_STATE_expecting_operand = 2,
    _LR_STATE_expecting_operator = 3,
    _LR_STATE_defaults = 4
};


/*- Variables used by dialog interpreter ------------------------------------*/

typedef int event_t;                    /*  Type for dialog entity           */
typedef int state_t;                    /*  Type for dialog entity           */
typedef void (fsmfunct) (void);         /*  Address of FSM function          */

static event_t
    _LR_event,                          /*  Event for state transition       */
    the_next_event,                     /*  Next event from module           */
    the_exception_event;                /*  Exception event from module      */

static state_t
    _LR_state,                          /*  Current dialog state             */
    _LR_savest;                         /*  Saved dialog state               */

static int
    _LR_index,                          /*  Index into vector table          */
    _LR_number;                         /*  Number of next module            */

static Bool
    exception_raised;                   /*  TRUE if exception raised         */

/*- Function prototypes -----------------------------------------------------*/

#ifndef MODULE
#define MODULE  static void             /*  Libero dialog modules            */
#endif

static void raise_exception             (event_t event);
MODULE initialise_the_program           (void);
MODULE get_external_event               (void);
MODULE get_next_token                   (void);
MODULE terminate_the_program            (void);
MODULE allow_signed_number              (void);
MODULE signal_invalid_token             (void);
MODULE stack_the_number                 (void);
MODULE stack_the_operator               (void);
MODULE unstack_ge_operators             (void);
MODULE unstack_all_operators            (void);
MODULE unstack_if_end_mark              (void);
MODULE unstack_if_left_par              (void);
MODULE signal_token_missing             (void);

/*- Static areas ------------------------------------------------------------*/

static dbyte _LR_nextst [][9] =
{
    { 0,0,0,0,0,0,1,0,0 },
    { 1,0,0,0,2,3,0,0,1 },
    { 0,0,0,0,2,3,0,0,2 },
    { 3,0,0,2,0,0,0,3,2 },
    { 4,0,4,4,4,4,0,4,4 }
};

static dbyte _LR_action [][9] =
{
    { 0,2,0,0,0,0,1,0,0 },
    { 2,0,0,0,5,4,0,0,3 },
    { 0,0,0,0,5,4,0,0,3 },
    { 7,0,0,6,0,0,0,8,6 },
    { 10,0,2,9,9,9,0,9,9 }
};

static dbyte _LR_vector [][3+1] =
{
    {0},
    {0,_LR_STOP},
    {1,_LR_STOP},
    {2,3,1,_LR_STOP},
    {4,0,_LR_STOP},
    {5,0,_LR_STOP},
    {6,5,0,_LR_STOP},
    {7,8,1,_LR_STOP},
    {7,9,0,_LR_STOP},
    {3,1,_LR_STOP},
    {10,1,_LR_STOP}
};

static fsmfunct *_LR_module [] =
{
    get_next_token,
    terminate_the_program,
    allow_signed_number,
    signal_invalid_token,
    stack_the_number,
    stack_the_operator,
    unstack_ge_operators,
    unstack_all_operators,
    unstack_if_end_mark,
    unstack_if_left_par,
    signal_token_missing
};

