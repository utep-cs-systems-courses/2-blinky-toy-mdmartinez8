#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;// bits attached to leds are output
  switch_state_changed = 0;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */
    //ledFlags |= switch_state_down ? LED_GREEN : 0;
    //ledFlags |= switch_state_down ? 0 : LED_RED;
    switch(switch_state_selector) {
       case 1:
	 ledFlags &= ~LEDS;
	 break;

       case 2:
	 ledFlags |= LED_RED;
	 ledFlags &= ~LED_GREEN;
	 break;

       case 3:
	 ledFlags |= LED_GREEN;
	 ledFlags &= ~LED_RED;
	 break;

       case 4:
	 ledFlags |= LEDS;
	 break;
      
    }
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}

