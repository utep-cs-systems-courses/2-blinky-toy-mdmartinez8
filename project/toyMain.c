#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void main(void)
{
  configureClocks();
  enableWDTInterrupts();
  led_init();
  switch_init();
  buzzer_init();
  P1OUT |= LED_GREEN;      //Alternating pattern starts with green led on and red led off
  P1OUT &= ~LED_RED;

  or_sr(0x18); // Turn off CPU and enable interrupts


}

static int blink_count = 0;
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  
  switch (blink_count)
  {
    case 125:
      blink_count = 0;
      P1OUT ^= LEDS;
      if (P1OUT & LED_RED) {
	P1OUT |= LED_RED;
	P1OUT &= ~LED_GREEN;
	buzzer_set_period(5000);
      }else{
	P1OUT |= LED_GREEN;
	P1OUT &= ~LED_RED;
	buzzer_set_period(4000);
      }

      break;

    default:
      if (!switch_state_down) blink_count++;
  }

}
