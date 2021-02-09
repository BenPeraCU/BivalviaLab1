#include "msp.h"

/**
 * main.c
**/

uint16_t *ptr;

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    ptr = (uint16_t *)0x20001000U;

    *(ptr + 0x10) = 0xACCA;
    *(ptr + 0x11) = 0xACCA;
    *(ptr + 0x12) = 0xADDA;

    uint32_t count1 = 0;
    uint32_t count2 = 0;

    for(ptr; ptr < (uint32_t *)0x200103CD; ptr++){
        if(*ptr == 0x0000ACCA){
            count1++;
        }
        if(*ptr == 0xABBAAFFA){
            count2++;
        }
    }
}
