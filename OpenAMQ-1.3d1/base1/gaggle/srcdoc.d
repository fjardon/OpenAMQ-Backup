#----------------------------------------------------------------------------
#   Dialog data and code block - do not modify this code by hand
#   Generated by LIBERO 2.4 on  6 Oct, 2010, 19:29.
#   Schema file used: lrschema.pl
#----------------------------------------------------------------------------

#-- Symbolic constants and event numbers ------------------------------------

$LR_defaults_state = 4;
$LR_STATE_after_init = 0;
$LR_STATE_have_source_file = 1;
$LR_STATE_parsing_include = 2;
$LR_STATE_parsing_code = 3;
$LR_STATE_defaults = 4;

$terminate_event = -1;                  # Halts the dialog
$LR_NULL_EVENT = -2;
$code_event = 0;
$define_event = 1;
$empty_event = 2;
$error_event = 3;
$exception_event = 4;
$header_event = 5;
$include_event = 6;
$no_more_event = 7;
$ok_event = 8;
$prolog_event = 9;
$proto_event = 10;
$typedef_event = 11;

#-- Standard subroutines used by dialog interpreter -------------------------

sub raise_exception {
    local ($event) = @_;
    $the_exception_event = $event;
    $exception_raised = 1;
}

sub LR_initialise {
    $LR_nextst = "";
    $LR_nextst .= "000000001000";
    $LR_nextst .= "301000210000";
    $LR_nextst .= "020002010222";
    $LR_nextst .= "030003010333";
    $LR_nextst .= "000040000000";

    $LR_action = "";
    $LR_action .= "000000020000000001000000";
    $LR_action .= "040005000000030200000000";
    $LR_action .= "000700000010001100060908";
    $LR_action .= "001200000013000500121212";
    $LR_action .= "000000000200000000000000";

    $LR_module = "";
    $LR_module .= "01020304" . "00";
    $LR_module .= "05" . "00";
    $LR_module .= "060708" . "00";
    $LR_module .= "090708" . "00";
    $LR_module .= "04" . "00";
    $LR_module .= "101108" . "00";
    $LR_module .= "1208" . "00";
    $LR_module .= "1308" . "00";
    $LR_module .= "1408" . "00";
    $LR_module .= "1508" . "00";
    $LR_module .= "1004" . "00";
    $LR_module .= "08" . "00";
    $LR_module .= "16171808" . "00";

    $LR_offset [1] = 0;
    $LR_offset [2] = 5;
    $LR_offset [3] = 7;
    $LR_offset [4] = 11;
    $LR_offset [5] = 15;
    $LR_offset [6] = 17;
    $LR_offset [7] = 21;
    $LR_offset [8] = 24;
    $LR_offset [9] = 27;
    $LR_offset [10] = 30;
    $LR_offset [11] = 33;
    $LR_offset [12] = 36;
    $LR_offset [13] = 38;
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
            $LR_modnbr == 1 && do { &initialise_program_data; last; };
            $LR_modnbr == 2 && do { &load_anchor_definitions; last; };
            $LR_modnbr == 3 && do { &parse_coverpage_file; last; };
            $LR_modnbr == 4 && do { &get_next_source_file; last; };
            $LR_modnbr == 5 && do { &terminate_the_program; last; };
            $LR_modnbr == 6 && do { &may_have_first_include_file; last; };
            $LR_modnbr == 7 && do { &prepare_to_parse_file; last; };
            $LR_modnbr == 8 && do { &look_for_interesting_line; last; };
            $LR_modnbr == 9 && do { &may_have_first_code_file; last; };
            $LR_modnbr == 10 && do { &build_tables_of_definitions; last; };
            $LR_modnbr == 11 && do { &parse_prolog_block; last; };
            $LR_modnbr == 12 && do { &parse_define_command; last; };
            $LR_modnbr == 13 && do { &parse_typedef_command; last; };
            $LR_modnbr == 14 && do { &parse_function_prototype; last; };
            $LR_modnbr == 15 && do { &ignore_function_header; last; };
            $LR_modnbr == 16 && do { &parse_function_header; last; };
            $LR_modnbr == 17 && do { &parse_function_body; last; };
            $LR_modnbr == 18 && do { &build_function_definition; last; };
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
        $LR_index = ($LR_state * 12 + $LR_event) * 1;
        $LR_state = substr ($LR_nextst, $LR_index, 1);
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
