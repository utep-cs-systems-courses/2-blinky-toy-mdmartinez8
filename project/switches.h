#ifndef switches_included
#define switches_included

#define SW1 BIT0		    /* switch 1 is p2.0 */
#define SW2 BIT1                    /* switch 2 is p2.1*/
#define SW3 BIT2                    /* switch 3 is p2.2*/
#define SW4 BIT3                    /* switch 4 is p2.3*/
#define SWITCHES 15     /* 4 switches on this board */

void switch_init();
void switch_interrupt_handler();
void __interrupt_vec(PORT2_VECTOR) Port_2();

extern char switch_state_down, switch_state_changed; /* effectively boolean for variables and switch statements*/

/*These variables represent different states*/
extern int switch_state_selector;
/*extern int no_led = 1;
extern int red_led = 2;
extern int green_led = 3;
extern int both_led = 4;*/
#endif // included
