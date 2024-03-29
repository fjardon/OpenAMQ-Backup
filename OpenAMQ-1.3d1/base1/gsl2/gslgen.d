/*---------------------------------------------------------------------------*
 *  gslgen.d - LIBERO dialog data definitions for gslgen.c.                  *
 *  Generated by LIBERO 2.4 on  6 Oct, 2010, 19:29.                          *
 *  Schema file used: lrschema.c.                                            *
 *---------------------------------------------------------------------------*/

/*- Symbolic constants and event numbers ------------------------------------*/

#define _LR_STOP                        0xFFFFL
#define _LR_NULL_EVENT                  -2
enum {
    terminate_event = -1,
    anomaly_event = 0,
    finished_event = 1,
    ok_event = 2,
    switch_event = 3
};

enum {
    _LR_defaults_state = 3,
    _LR_STATE_after_init = 0,
    _LR_STATE_have_first_argument = 1,
    _LR_STATE_have_next_argument = 2,
    _LR_STATE_defaults = 3
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
MODULE initialise_program_data          (void);
MODULE define_standard_values           (void);
MODULE get_next_argument_value          (void);
MODULE display_welcome_if_not_quiet     (void);
MODULE display_command_line_syntax      (void);
MODULE terminate_the_program            (void);
MODULE read_xml_or_gsl_file             (void);
MODULE call_code_generator              (void);
MODULE free_xml_structures              (void);
MODULE process_the_switch               (void);
MODULE use_standard_input               (void);
MODULE free_switches_structure          (void);

/*- Static areas ------------------------------------------------------------*/

static dbyte _LR_nextst [][4] =
{
    { 0,0,1,0 },
    { 0,1,2,1 },
    { 0,2,2,2 },
    { 3,0,0,0 }
};

static dbyte _LR_action [][4] =
{
    { 2,0,1,0 },
    { 0,5,3,4 },
    { 0,7,6,4 },
    { 8,0,0,0 }
};

static dbyte _LR_vector [][5+1] =
{
    {0},
    {0,1,2,_LR_STOP},
    {3,4,5,_LR_STOP},
    {3,6,7,8,2,_LR_STOP},
    {9,2,_LR_STOP},
    {10,7,8,11,5,_LR_STOP},
    {6,7,8,2,_LR_STOP},
    {11,5,_LR_STOP},
    {8,11,5,_LR_STOP}
};

static fsmfunct *_LR_module [] =
{
    initialise_program_data,
    define_standard_values,
    get_next_argument_value,
    display_welcome_if_not_quiet,
    display_command_line_syntax,
    terminate_the_program,
    read_xml_or_gsl_file,
    call_code_generator,
    free_xml_structures,
    process_the_switch,
    use_standard_input,
    free_switches_structure
};

