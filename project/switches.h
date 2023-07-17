#ifndef switches_included
#define switches_included

#define SW1 BIT0		    /* switch 1 is p2.0 */
#define SW2 BIT1                    /* switch 2 is p2.1*/
#define SW3 BIT2                    /* switch 3 is p2.2*/
#define SW4 BIT3                    /* switch 4 is p2.3*/
#define SWITCHES SW1 SW2 SW3 SW4     /* 4 switches on this board */

void switch_init();
void switch_interrupt_handler();
//void _interrupt_vec(PORT1_VECTOR) Port_1();

extern char switch_state_down, switch_state_changed, switch_state_selector, no_led, red_led, green_led, both_led; /* effectively boolean for variables and switch statements*/

#endif // included
