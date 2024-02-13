/*
    Author: Aryan Singh
    Topic: Passing Arrays to a function
*/
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void array_display(uint8_t const *const Arraydata, uint32_t len);

int main()
{
    uint8_t data[10] = {0xff ,0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
    uint8_t len = sizeof(data)/sizeof(uint8_t);
    array_display(data, len);

    printf("\n");

    array_display((data+3), (len-3));   //Accessing elements for certain requirements using pointer manipulation
    
    printf("\n");

    array_display((&data[3]), (len-3));   //Accing elements for certain requirements using short hand method
    return 0;
}

void array_display(uint8_t const *const Arraydata, uint32_t len){
    printf("The Length of the array is %d\n", len);
    for(int i = 0; i < len; i++){
        printf("Data element %d value: %x\n", i, Arraydata[i]);
    }
}
