/*
    Author:
    Topic:
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long int g_data = 0xFFFFABCD11112345;

int main()
{
    char *ptr1;
    ptr1 = (char*)&g_data;
    printf("Value at address %p is: %x\n", ptr1, *ptr1);

    int *ptr2;
    ptr2 = (int*)&g_data;
    printf("Value at address %p is: %x\n", ptr2, *ptr2);

    short *ptr3;
    ptr3 = (short*)&g_data;
    printf("Value at address %p is: %x\n", ptr3, *ptr3);

    long long *ptr4;
    ptr4 = (long long*)&g_data;
    printf("Value at address %p is: %x\n", ptr4, *ptr4); //Write operation, read operation

    printf("sizeof: %lu\n", sizeof(long long int));

    return 0;
}