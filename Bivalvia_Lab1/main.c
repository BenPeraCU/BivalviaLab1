#include "msp.h"


/**
 * main.c
**/

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    P1->DIR |= BIT0; //sets p1.0 as output
    P1->OUT &= ~BIT1; // sets bit1 to 0

    while(1){
        P1->OUT |= BIT0;
        for(int i = 0; i < 30000; i++);
        P1->OUT &= ~BIT0;
        for(int i = 0; i < 30000; i++);
    }

}
