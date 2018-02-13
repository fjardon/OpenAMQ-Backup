/*---------------------------------------------------------------------------*
 *  lreval.d - LIBERO dialog data definitions for lreval.c.                  *
 *  Generated by LIBERO 2.4 on  6 Oct, 2010, 19:32.                          *
 *  Schema file used: lrschema.c.                                            *
 *---------------------------------------------------------------------------*/

/*- Symbolic constants and event numbers ------------------------------------*/

#define _LR_STOP                        0xFFFFL
#define _LR_NULL_EVENT                  -2
enum {
    terminate_event = -1,
    animate_event = 0,
    caps_event = 1,
    check_event = 2,
    cobol_event = 3,
    defaults_event = 4,
    error_event = 5,
    event_event = 6,
    exception_event = 7,
    exist_event = 8,
    finished_event = 9,
    headline_event = 10,
    module_event = 11,
    normal_event = 12,
    not_event = 13,
    ok_event = 14,
    other_event = 15,
    plain_event = 16,
    relator_event = 17,
    state_event = 18,
    string_event = 19,
    test_event = 20,
    title_event = 21
};

enum {
    _LR_defaults_state = 10,
    _LR_STATE_after_init = 0,
    _LR_STATE_expect_action = 1,
    _LR_STATE_have_action = 2,
    _LR_STATE_left_expr_first = 3,
    _LR_STATE_left_expr_next = 4,
    _LR_STATE_right_expr_first = 5,
    _LR_STATE_right_expr_next = 6,
    _LR_STATE_left_string_next = 7,
    _LR_STATE_right_string_first = 8,
    _LR_STATE_right_string_next = 9,
    _LR_STATE_defaults = 10
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
MODULE classify_token_as_action         (void);
MODULE init_left_and_right_expr         (void);
MODULE save_left_expr_position          (void);
MODULE concat_token_to_left_expr        (void);
MODULE signal_action_expected           (void);
MODULE invert_condition_result          (void);
MODULE evaluate_animation_enabled       (void);
MODULE evaluate_style_is_caps           (void);
MODULE evaluate_style_is_cobol          (void);
MODULE evaluate_check_enabled           (void);
MODULE evaluate_defaults_defined        (void);
MODULE evaluate_file_exists             (void);
MODULE evaluate_style_is_headline       (void);
MODULE evaluate_style_is_plain          (void);
MODULE evaluate_style_is_normal         (void);
MODULE evaluate_style_is_title          (void);
MODULE evaluate_state_exists            (void);
MODULE evaluate_event_exists            (void);
MODULE evaluate_module_exists           (void);
MODULE signal_expr_or_string_expected   (void);
MODULE signal_relator_expected          (void);
MODULE save_right_expr_position         (void);
MODULE concat_token_to_right_expr       (void);
MODULE signal_expression_expected       (void);
MODULE signal_relator_ignored           (void);
MODULE evaluate_numeric_comparison      (void);
MODULE signal_string_expected           (void);
MODULE evaluate_string_comparison       (void);
MODULE signal_token_missing             (void);

/*- Static areas ------------------------------------------------------------*/

static dbyte _LR_nextst [][22] =
{
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,0,1,0,7,0,0 },
    { 2,2,2,2,2,0,2,0,2,0,2,2,2,1,0,4,2,0,2,0,3,2 },
    { 0,0,0,0,0,0,0,0,0,3,0,0,4,0,0,0,0,3,0,7,0,0 },
    { 0,0,0,0,0,0,0,0,0,4,0,0,4,0,0,0,0,5,0,4,0,0 },
    { 0,0,0,0,0,0,0,0,0,5,0,0,6,0,0,0,0,5,0,5,0,0 },
    { 0,0,0,0,0,0,0,0,0,6,0,0,6,0,0,0,0,6,0,6,0,0 },
    { 0,0,0,0,0,0,0,0,0,7,0,0,7,0,0,0,0,8,0,7,0,0 },
    { 0,0,0,0,0,0,0,0,0,8,0,0,8,0,0,0,0,8,0,9,0,0 },
    { 0,0,0,0,0,0,0,0,0,9,0,0,9,0,0,0,0,9,0,9,0,0 },
    { 0,0,0,0,0,0,0,10,0,10,0,0,0,0,0,0,0,0,0,0,0,0 }
};

static dbyte _LR_action [][22] =
{
    { 0,0,0,0,0,2,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 },
    { 0,0,0,0,0,0,0,0,0,5,0,0,3,0,0,0,0,5,0,4,0,0 },
    { 7,8,10,9,11,0,18,0,12,0,13,19,15,6,0,4,14,0,17,0,20,16 },
    { 0,0,0,0,0,0,0,0,0,22,0,0,21,0,0,0,0,22,0,21,0,0 },
    { 0,0,0,0,0,0,0,0,0,24,0,0,23,0,0,0,0,1,0,24,0,0 },
    { 0,0,0,0,0,0,0,0,0,26,0,0,25,0,0,0,0,27,0,26,0,0 },
    { 0,0,0,0,0,0,0,0,0,29,0,0,28,0,0,0,0,27,0,26,0,0 },
    { 0,0,0,0,0,0,0,0,0,24,0,0,30,0,0,0,0,1,0,23,0,0 },
    { 0,0,0,0,0,0,0,0,0,30,0,0,30,0,0,0,0,27,0,25,0,0 },
    { 0,0,0,0,0,0,0,0,0,31,0,0,30,0,0,0,0,27,0,28,0,0 },
    { 0,0,0,0,0,0,0,2,0,32,0,0,0,0,0,0,0,0,0,0,0,0 }
};

static dbyte _LR_vector [][4+1] =
{
    {0},
    {0,_LR_STOP},
    {1,_LR_STOP},
    {2,_LR_STOP},
    {3,4,5,0,_LR_STOP},
    {6,1,_LR_STOP},
    {7,0,_LR_STOP},
    {8,1,_LR_STOP},
    {9,1,_LR_STOP},
    {10,1,_LR_STOP},
    {11,1,_LR_STOP},
    {12,1,_LR_STOP},
    {0,13,1,_LR_STOP},
    {14,1,_LR_STOP},
    {15,1,_LR_STOP},
    {16,1,_LR_STOP},
    {17,1,_LR_STOP},
    {0,18,1,_LR_STOP},
    {0,19,1,_LR_STOP},
    {0,20,1,_LR_STOP},
    {3,0,_LR_STOP},
    {4,5,0,_LR_STOP},
    {21,1,_LR_STOP},
    {5,0,_LR_STOP},
    {22,1,_LR_STOP},
    {23,24,0,_LR_STOP},
    {25,1,_LR_STOP},
    {26,1,_LR_STOP},
    {24,0,_LR_STOP},
    {27,1,_LR_STOP},
    {28,1,_LR_STOP},
    {29,1,_LR_STOP},
    {30,1,_LR_STOP}
};

static fsmfunct *_LR_module [] =
{
    get_next_token,
    terminate_the_program,
    classify_token_as_action,
    init_left_and_right_expr,
    save_left_expr_position,
    concat_token_to_left_expr,
    signal_action_expected,
    invert_condition_result,
    evaluate_animation_enabled,
    evaluate_style_is_caps,
    evaluate_style_is_cobol,
    evaluate_check_enabled,
    evaluate_defaults_defined,
    evaluate_file_exists,
    evaluate_style_is_headline,
    evaluate_style_is_plain,
    evaluate_style_is_normal,
    evaluate_style_is_title,
    evaluate_state_exists,
    evaluate_event_exists,
    evaluate_module_exists,
    signal_expr_or_string_expected,
    signal_relator_expected,
    save_right_expr_position,
    concat_token_to_right_expr,
    signal_expression_expected,
    signal_relator_ignored,
    evaluate_numeric_comparison,
    signal_string_expected,
    evaluate_string_comparison,
    signal_token_missing
};

