/**
 * scan.c
 * Scans through memory addresses looking for some patterns.
**/

int scan() {

    int a = 0, b = 0;
    short int *start = (short int*)0x2001000A, *end = (short int *)0x200103CC;

    while(start < end) {
        if((*start) == 0xACCA) { a++; }
        if((*start) == 0xABBA) && (*start + 1) == 0xAFFA) { b++; }
        start++;
    }

    return 0;

}
