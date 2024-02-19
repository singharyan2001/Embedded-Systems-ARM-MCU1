/*
    Author: Aryan singh
    Topic:  Read and Write Operations on arrays
*/
#include <stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
int main()
{
    int len = 10;
    uint8_t data[10] = {0xff ,0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

    printf("Before: 2nd data item = %x\n", *(data+1));  //Array Manipulation: Pointer Method

    *(data+1) = 0x09;  //Array Manipulation: Pointer Method

    printf("Before: 2nd data item = %x\n", *(data+1)); //Array Manipulation: Pointer Method

    for(int i = 0; i < len; i++){
        printf("Data element %d value = %x\n", i, data[i]); //Array Manipulation: Short Hand Method
    }

    return 0;
}