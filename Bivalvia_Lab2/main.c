/**
 * main.c - Runs blink.c and scan.c
**/
#include "msp.h"
#include <stdio.h>

void blink()
{
    P1->DIR |= BIT0; //sets p1.0 as output
    P1->OUT &= ~BIT0; // sets bit0 to 0

    while(1){
        int i;
        P1->OUT |= BIT0; //Sets LED to HIGH (pin1.out = 1b)
        for(i = 0; i < 200000; i++); //Delays code
        P1->OUT &= ~BIT0; //Sets LED to LOW (pin1.out = 0b)
        for(i = 0; i < 200000; i++); //Delays code
    }

}


int scan() {

    int a = 0, b = 0;
    short int *start = (short int*)0x2001000A, *end = (short int *)0x200103CC;

    while(start < end) {
        if( (*start) == 0xACCA) { a++; }
        if( ((*start) == 0xABBA) && (*start + 1) == 0xAFFA) { b++; }
        start++;
    }

    printf("Value of a is: %d\nValue of b is: %d\n", a, b);
    
    return 0;

}


int main(int argsc, char *argsv[]) {
    
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
    
    scan(); //scans subsapce of SRAM looking for values
    
    blink(); //blinks an LED forever
    
    return 0;
}
