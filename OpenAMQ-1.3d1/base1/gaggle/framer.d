#----------------------------------------------------------------------------
#   Dialog data and code block - do not modify this code by hand
#   Generated by LIBERO 2.4 on  6 Oct, 2010, 19:29.
#   Schema file used: lrschema.pl
#----------------------------------------------------------------------------

#-- Symbolic constants and event numbers ------------------------------------

$LR_defaults_state = 9;
$LR_STATE_after_init = 0;
$LR_STATE_expect_state_name = 1;
$LR_STATE_after_state = 2;
$LR_STATE_expect_event_name = 3;
$LR_STATE_expect_next_pointer = 4;
$LR_STATE_after_next_pointer = 5;
$LR_STATE_after_event = 6;
$LR_STATE_after_module_flag = 7;
$LR_STATE_after_module = 8;
$LR_STATE_defaults = 9;

$terminate_event = -1;                  # Halts the dialog
$LR_NULL_EVENT = -2;
$comment_event = 0;
$error_event = 1;
$event_number_event = 2;
$item_name_event = 3;
$module_flag_event = 4;
$next_pointer_event = 5;
$no_more_event = 6;
$ok_event = 7;
$option_event = 8;
$state_name_event = 9;
$state_name_term_event = 10;
$superstate_ref_event = 11;

#-- Standard subroutines used by dialog interpreter -------------------------

sub raise_exception {
    local ($event) = @_;
    $the_exception_event = $event;
    $exception_raised = 1;
}

sub LR_initialise {
    $LR_nextst = "";
    $LR_nextst .= "000000000000000100000000";
    $LR_nextst .= "000000020000000000020000";
    $LR_nextst .= "000003020000000000020202";
    $LR_nextst .= "000000040000000000000000";
    $LR_nextst .= "000000000705000000000000";
    $LR_nextst .= "000003060700050000020000";
    $LR_nextst .= "000003020700000000020000";
    $LR_nextst .= "000003080000070000020000";
    $LR_nextst .= "000003020700000000020000";
    $LR_nextst .= "090909090909090009090909";

    $LR_action = "";
    $LR_action .= "000000000000000100000000";
    $LR_action .= "000000030000000000020000";
    $LR_action .= "000005030000000000020604";
    $LR_action .= "000000070000000000000000";
    $LR_action .= "000000000908000000000000";
    $LR_action .= "000012100900130000110000";
    $LR_action .= "000015171600000000140000";
    $LR_action .= "000015180000190000140000";
    $LR_action .= "000005031600000000020000";
    $LR_action .= "222320202020240021202020";

    $LR_module = "";
    $LR_module .= "010203" . "00";
    $LR_module .= "040503" . "00";
    $LR_module .= "06040503" . "00";
    $LR_module .= "070503" . "00";
    $LR_module .= "080903" . "00";
    $LR_module .= "03" . "00";
    $LR_module .= "101103" . "00";
    $LR_module .= "1203" . "00";
    $LR_module .= "131403" . "00";
    $LR_module .= "1503" . "00";
    $LR_module .= "1316040503" . "00";
    $LR_module .= "1316080903" . "00";
    $LR_module .= "131617181920" . "00";
    $LR_module .= "16040503" . "00";
    $LR_module .= "16080903" . "00";
    $LR_module .= "1403" . "00";
    $LR_module .= "1606040503" . "00";
    $LR_module .= "2103" . "00";
    $LR_module .= "1617181920" . "00";
    $LR_module .= "22192320" . "00";
    $LR_module .= "2403" . "00";
    $LR_module .= "2503" . "00";
    $LR_module .= "192320" . "00";
    $LR_module .= "17181920" . "00";

    $LR_offset [1] = 0;
    $LR_offset [2] = 4;
    $LR_offset [3] = 8;
    $LR_offset [4] = 13;
    $LR_offset [5] = 17;
    $LR_offset [6] = 21;
    $LR_offset [7] = 23;
    $LR_offset [8] = 27;
    $LR_offset [9] = 30;
    $LR_offset [10] = 34;
    $LR_offset [11] = 37;
    $LR_offset [12] = 43;
    $LR_offset [13] = 49;
    $LR_offset [14] = 56;
    $LR_offset [15] = 61;
    $LR_offset [16] = 66;
    $LR_offset [17] = 69;
    $LR_offset [18] = 75;
    $LR_offset [19] = 78;
    $LR_offset [20] = 84;
    $LR_offset [21] = 89;
    $LR_offset [22] = 92;
    $LR_offset [23] = 95;
    $LR_offset [24] = 99;
}

#-- Dialog interpreter starts here ------------------------------------------

$feedback = 0;                          #   Main program feedback
$LR_state = 0;                          #   First state is always 0
&LR_initialise;                         #   Initialise static strings
&initialise_the_program;
while ($the_next_event != $terminate_event)
  {
    $LR_event = $the_next_event;
    $LR_event < 0 || $LR_event >= 12 && die
        "State ", $LR_state,
        " - event ", $LR_event, " is out of range\n";
    $LR_index = ($LR_state * 12 + $LR_event) * 2;
    $LR_index = substr ($LR_action, $LR_index, 2);
    $LR_savest = $LR_state;

    #   If no action for this event, try the defaults state
    if ($LR_index == 0)
      {
        $LR_state = $LR_defaults_state;
        $LR_index = ($LR_state * 12 + $LR_event) * 2;
        $LR_index = substr ($LR_action, $LR_index, 2);
        $LR_index == 0 && die
            "State ", $LR_state,
            " - event ", $LR_event, " is not accepted\n";
      }
    $the_next_event = $LR_NULL_EVENT;
    $the_exception_event = $LR_NULL_EVENT;
    $exception_raised = 0;

    #   Execute module list for state transition, 0 indicates end of list
    $LR_vecptr = $LR_offset [$LR_index];
    $LR_modnbr = substr ($LR_module, $LR_vecptr * 2, 2);
    while ($LR_modnbr > 0 && !$exception_raised)
      {
          {                             #   Execute the module
            $LR_modnbr == 1 && do { &open_dialog_file; last; };
            $LR_modnbr == 2 && do { &expect_state_name; last; };
            $LR_modnbr == 3 && do { &get_next_token; last; };
            $LR_modnbr == 4 && do { &attach_new_state; last; };
            $LR_modnbr == 5 && do { &expect_state_definition; last; };
            $LR_modnbr == 6 && do { &warning_on_state_name; last; };
            $LR_modnbr == 7 && do { &attach_uses_superstate; last; };
            $LR_modnbr == 8 && do { &store_event_number; last; };
            $LR_modnbr == 9 && do { &expect_event_name; last; };
            $LR_modnbr == 10 && do { &attach_new_event; last; };
            $LR_modnbr == 11 && do { &expect_next_pointer; last; };
            $LR_modnbr == 12 && do { &expect_event_definition; last; };
            $LR_modnbr == 13 && do { &attach_same_next_state; last; };
            $LR_modnbr == 14 && do { &expect_module_name; last; };
            $LR_modnbr == 15 && do { &attach_next_state; last; };
            $LR_modnbr == 16 && do { &attach_empty_module; last; };
            $LR_modnbr == 17 && do { &expand_macro_constructs; last; };
            $LR_modnbr == 18 && do { &build_source_file_name; last; };
            $LR_modnbr == 19 && do { &close_dialog_file; last; };
            $LR_modnbr == 20 && do { &terminate_the_program; last; };
            $LR_modnbr == 21 && do { &attach_new_module; last; };
            $LR_modnbr == 22 && do { &display_unexpected_token; last; };
            $LR_modnbr == 23 && do { &return_error_feedback; last; };
            $LR_modnbr == 24 && do { &process_option_value; last; };
            $LR_modnbr == 25 && do { &process_comment_value; last; };
          }
        $LR_vecptr++;
        $LR_modnbr = substr ($LR_module, $LR_vecptr * 2, 2);
      }

    #   Handle exception if any was raised
    if ($exception_raised)
      {
        $the_exception_event == $LR_NULL_EVENT ||
            ($LR_event = $the_exception_event);

        $the_next_event = $LR_event;
      }
    else
      {
        $LR_index = ($LR_state * 12 + $LR_event) * 2;
        $LR_state = substr ($LR_nextst, $LR_index, 2);
      }
    $LR_state = $LR_savest if ($LR_state == $LR_defaults_state);
    if ($the_next_event == $LR_NULL_EVENT)
      {
        &get_external_event;
        $the_next_event == $LR_NULL_EVENT && die
            "No event set after event ", $LR_event,
            " in state ", $LR_state, "\n";
      }
  }
exit ($feedback);
