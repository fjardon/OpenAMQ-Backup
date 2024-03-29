/*---------------------------------------------------------------------------*
 *  ggpars.i - LIBERO dialog interpreter for ggpars.c.                       *
 *  Generated by LIBERO 2.4 on  6 Oct, 2010, 19:29.                          *
 *---------------------------------------------------------------------------*/

    _LR_state = 0;                      /*  First state is always 0          */
    _LR_stack_size = 0;                 /*  Clear subdialog stack            */
    initialise_the_program ();
    while (the_next_event != terminate_event)
      {
        _LR_event = the_next_event;
        if (_LR_event >= 89 || _LR_event < 0)
          {
            printf ("State %d - event %d is out of range\n",
                     _LR_state, _LR_event);
            break;
          }
        _LR_savest = _LR_state;
        _LR_index  = _LR_action [_LR_state][_LR_event];
        /*  If no action for this event, try the defaults state              */
        if (_LR_index == 0)
          {
            _LR_state = _LR_defaults_state;
            _LR_index = _LR_action [_LR_state][_LR_event];
          }
        if (_LR_index == 0)
          {
            printf ("State %d - event %d is not accepted\n",
                     _LR_state, _LR_event);
            break;
          }
        the_next_event          = _LR_NULL_EVENT;
        the_exception_event     = _LR_NULL_EVENT;
        exception_raised        = FALSE;

        _LR_number = 0;
        while ((_LR_vector [_LR_index] [_LR_number] != _LR_STOP)
           && (! exception_raised))
          {
            (*_LR_module [_LR_vector [_LR_index] [_LR_number++]]) ();

            _LR_index  = _LR_action [_LR_state][_LR_event];
          }
        if (exception_raised)
          {
            if (the_exception_event != _LR_NULL_EVENT)
                _LR_event = the_exception_event;
            the_next_event = _LR_event;
          }
        else
            _LR_state = _LR_nextst [_LR_state][_LR_event];

        if (_LR_state == _LR_defaults_state)
            _LR_state = _LR_savest;
        if (the_next_event == _LR_NULL_EVENT)
          {
            get_external_event ();
            if (the_next_event == _LR_NULL_EVENT)
              {
                printf ("No event set after event %d in state %d\n",
                         _LR_event, _LR_state);
                break;
              }
          }
      }
    return (feedback);
}

MODULE dialog_call (void)
{
    if (_LR_stack_size < 256)
      {
        _LR_state_stack  [_LR_stack_size] = _LR_state;
        _LR_event_stack  [_LR_stack_size] = return_event;
        _LR_number_stack [_LR_stack_size] = 0;
        _LR_stack_size++;
      }
    else
      {
        printf ("State %d - Dialog-Call overflow\n", _LR_state);
        exit (1);
      }
}

MODULE dialog_return (void)
{
    if (_LR_stack_size > 0)
      {
        _LR_stack_size--;
        _LR_state  = _LR_state_stack [_LR_stack_size];
        _LR_event  = _LR_event_stack [_LR_stack_size];
        _LR_number = _LR_number_stack [_LR_stack_size];
      }
    else
      {
        printf ("State %d - Dialog-Return underflow\n", _LR_state);
        exit (1);
      }
}

/*- Standard dialog routines ------------------------------------------------*/

static void call_exception (event_t event)
{
    exception_raised = TRUE;
    if (_LR_stack_size < 256)
      {
        _LR_state_stack  [_LR_stack_size] = _LR_state;
        _LR_event_stack  [_LR_stack_size] = _LR_event;
        _LR_number_stack [_LR_stack_size] = _LR_number;
        _LR_stack_size++;
      }
    else
      {
        printf ("State %d - Dialog-Call overflow\n", _LR_state);
        exit (1);
      }
    if (event >= 0)
        the_exception_event = event;
}

static void raise_exception (event_t event)
{
    exception_raised = TRUE;
    if (event >= 0)
        the_exception_event = event;
