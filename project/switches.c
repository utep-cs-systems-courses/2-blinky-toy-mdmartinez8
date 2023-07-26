#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "states.h"

char switch_state_down, switch_state_changed;
int switch_state_selector;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;/* update switch interrupt to detect changes from current P2IN buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;	       
  P2IE |= SWITCHES;	       
  P2OUT |= SWITCHES;	   
  P2DIR &= ~SWITCHES;	       
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down = ((p2val & SW1)&&(p2val & SW2)&&(p2val & SW3)&&(p2val & SW4)) ? 0 : 1; /* 0 when there are no switches being pressed */
  if (~p2val & SW1) {
    switch_state_selector = 1;     //no_led state
  }else if (~p2val & SW2) {
    switch_state_selector = 2;     //red_led state
  }else if (~p2val & SW3) {
    switch_state_selector = 3;     //green_led state
  }else {
    switch_state_selector = 4;     //both_led state
  }
  switch_state_changed = 1;
  led_update();
}

void
__interrupt_vec(PORT2_VECTOR) Port_2(){

  if (P2IFG & SWITCHES) { /*If one of the buttons caused interrupt, clear pending interrupts and call switch_interrupt_handler()*/
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
  
}
