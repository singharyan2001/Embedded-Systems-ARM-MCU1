/*
    Author: Aryan Singh
    Topic: Union
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>

union address
{
    uint16_t shortAddr;
    uint32_t longAddr;
};

int main()
{
    union address addr;

    addr.shortAddr = 0xABCD;
    addr.longAddr = 0xEEEEFFFF;

    printf("Short Address = %#X\n", addr.shortAddr);
    printf("Long Address = %#X\n", addr.longAddr);

    getchar();  //C getchar is a standard library function that takes a single input character from standard input. The major difference between getchar and getc is that getc can take input from any no of input streams but getchar can take input from a single standard input stream.
    

    return 0;
}

/*
-------------------------------
0xE00   0XE01   0XE02   0XE03
  CD      AB                     ---> First Initialization --> Later this Initilization gets overwritten in Memory.
  FF      FF     EE      EE      ---> Second Initilization --> This is how Memory looks now.
*/
