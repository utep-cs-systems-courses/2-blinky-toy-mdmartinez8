#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;         /* variable does not reset due to being declared static*/
  if (++blink_count == 75) {
    state_advance();
    blink_count = 0;
  }
}
