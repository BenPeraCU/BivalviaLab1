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
    *(ptr + 0x12) = 0xABBA;
    *(ptr + 0x13) = 0xAFFA;

    uint32_t count1 = 0;
    uint32_t count2 = 0;

    for(ptr; ptr < (uint32_t *)0x200103CD; ptr++){
        if(*ptr == 0xACCAu){
            count1++;
        }
        if(*ptr == 0xABBAu && *(ptr + 1) == 0xAFFAu){
            count2++;
        }
    }
}
