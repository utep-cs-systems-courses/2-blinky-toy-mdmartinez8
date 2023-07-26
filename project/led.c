#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "states.h"

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
	 ledFlags = no_led();     //no_led state, no buzz
	 buzzer_set_period(0);
	 break;

       case 2:
	 ledFlags = red_led();     //red_led state, red buzz
	 buzzer_set_period(5000);
	 break;

       case 3:
	 ledFlags = green_led();     //green_led state, green buzz
	 buzzer_set_period(4000);
	 break;

       case 4:
	 ledFlags = both_led();        //both_led state, combined buzz
	 buzzer_set_period(2000);
	 break;
      
    }
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}

