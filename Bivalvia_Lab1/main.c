#include "msp.h"

/**
 * main.c
**/

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    uint32_t count1 = 0;
    uint32_t count2 = 0;

    int *i = (int *)0x2001000A;
    for(i; i < (int *)0x200103CD; i++){
        if(*i == 0x0000ACCA){
            count1++;
        }
        if(*i == 0xABBAAFFA){
            count2++;
        }
    }

}
