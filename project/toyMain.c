#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void main(void)
{
  configureClocks();
  led_init();
  switch_init();
  buzzer_init();

  or_sr(0x18); // Turn off CPU and enable interrupts


}
