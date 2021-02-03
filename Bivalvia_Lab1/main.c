#include "msp.h"


/**
 * main.c
**/

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    P1->DIR |= BIT0; //sets p1.0 as output
    P1->OUT &= ~BIT0; // sets bit0 to 0

    while(1){
        int i;
        P1->OUT |= BIT0; //Sets LED to HIGH (pin1.out = 1b)
        for(i = 0; i < 200000; i++); //Delays code
        P1->OUT &= ~BIT0; //Sets LED to LOW (pin1.out = 0b)
        for(i = 0; i < 200000; i++); //Delays code
        P1->OUT |= BIT0; //Sets LED to HIGH (pin1.out = 1b)
        for(i = 0; i < 200000; i++); //Delays code
        P1->OUT &= ~BIT0; //Sets LED to LOW (pin1.out = 0b)
        for(i = 0; i < 200000; i++); //Delays code
    }

}
