#include "msp.h"

/**
 * main.c
**/

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    uint32_t count1 = 0;
    uint32_t count2 = 0;

    int *ptr = (int *)0x2001000A;
    for(ptr; ptr < (int *)0x200103CD; ptr++){
        if(*ptr == 0x0000ACCA){
            count1++;
        }
        if(*ptr == 0xABBAAFFA){
            count2++;
        }
    }

}
