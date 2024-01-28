/*
    Author:
    Topic:
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>

int main()
{
    uint8_t const data0 = 10;
    printf("Data0 is: %d\n", data0);

    // data0 = 50;
    // printf("New Data0 is: %d\n", data0);

    //using pointers
    uint8_t *ptr = (uint8_t*) &data0;
    *ptr = 50;
    printf("Data0 is: %d\n", data0);
    /*Const doesn't mean that the value never changes, its only programming safety feature, so that the programmer shouldn't try to modify the value. */

    //Use cases of const

    //1) Const data

    uint8_t const pi = 3.14;

    //2) Pointer to const

    uint8_t const *Pdata0 = &pi;  //Address is Modifiable/changeable but Data is Constant
    //*Pdata0 = 50; //Warning: Expression should be of a modifiable Lvalue

    //3) Const pointer
    uint8_t newdata0 = 12;
    uint8_t *const Pdata1 = &newdata0; //Data can be modified, but the address cannot be modified.
    printf("newdata0 is: %d\n", *Pdata1);
    newdata0 = 14;
    printf("newdata0 is: %d\n", *Pdata1);
    //Pdata1 = (uint8_t *) &pi; ////Warning: Expression should be of a modifiable Lvalue

    //4) Const data and Const Pointer

    uint8_t dataX = 1123;
    uint8_t const *const pData2 = (uint8_t*) &dataX;  //Const data & const pointer 
    printf("newdataX is: %d\n", *pData2);

    return 0;
}