/*
    Author:
    Topic: Ponters

    1) Create a char type variable and initialize it to value 100
    2) Print the address of the above variable.
    3) Create a pointer variable and store the address tyhe above variable.
    4) perform read operation on the pointer variable to fetch 1 byte of data from the pointer.
    5) print the data obtained from the read operation on the pointer.
    6) perform write operation on the pointer to store the value 65.
    print the value of the variable defined in step 1.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
int main()
{
    //step 1
    char data = 100;
    //step 2
    printf("Address of data variable is: %p\n", &data);
    //step 3
    char* ptr = &data;
    //step 4
    char read = *ptr;
    //step 5
    printf("Read operation results: %d\n", read);
    //step 6
    *ptr = 65;
    //step 7
    printf("The value at data is: %d\n", data); 

    return 0;
}