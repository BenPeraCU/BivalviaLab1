#include "msp.h"
#include <stdio.h>

/**
 * main.c
**/

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    uint32_t count1 = 0;
    uint32_t count2 = 0;

    void * i = (void *)0x2001000A;
    for(i; i < 0x2001000D; i++){
        printf(i);
    }
    /*
    for(i; *i < 0x200103CD; i++){
        if(&i == 0xACCA){
            count1++;
        }
        if(&i == 0xABBAAFFA){
            count2++;
        }
    }
    */

}
