#include "msp.h"


/**
 * main.c
**/

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    P1->DIR |= BIT0;
    P1->OUT &= ~BIT1;
    //Ben looked at this
}
