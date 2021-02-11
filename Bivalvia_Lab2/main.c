/**
 * main.c - Runs blink and scan
 *
 *
 * Bivalvia - Adam, Andrew, Ben, and Delan
 * da boys
 * Code effectively reads through memory in the range N to end, if those address are valid
**/
#include "msp.h"
#include <stdio.h>
#include <stdint.h>

void blink() {

    P1->DIR |= BIT0; //sets p1.0 as output
    P1->OUT &= ~BIT0; //sets bit0 to 0

    while(1) {
        int i;
        P1->OUT |= BIT0; //Sets LED to HIGH (pin1.out = 1b)
        for(i = 0; i < 200000; i++); //Delays code
        P1->OUT &= ~BIT0; //Sets LED to LOW (pin1.out = 0b)
        for(i = 0; i < 200000; i++); //Delays code
    }

}

int scan() {

    int a = 0, b = 0;
    uint16_t *start = (uint16_t *)0x2000100AU, *end = (uint16_t *)0x2000200AU;

    //set some values we can find
    *(start + 0x1) = 0xACCAU;
    *(start + 0x2) = 0xACCAU;
    *(start + 0x3) = 0xABBAU;
    *(start + 0x4) = 0xAFFAU;
    *(start + 0x5) = 0xACCAU;
    *(start + 0x6) = 0xACCAU;

    //scan
    while(start < end) {
        if( (*start) == 0xACCAU) { a++; }
        if( (*start) == 0xABBAU && *(start + 1) == 0xAFFAU) { b++; }
        start++;
    }

    printf("Value of a is: %d, Value of b is: %d\n", a, b);
    
    return 0;

}


int main(int argsc, char *argsv[]) {
    
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
    
    scan(); //scans subspace of SRAM looking for values
    
    blink(); //blinks an LED forever
    
    return 0;

}
