#include <msp430.h>
#include "states.h"

char no_led()
{
  return 0;
}

char red_led()
{
  return 1;
}

char green_led()
{
  return 64;
}

char both_led()
{
  return 65;
}
