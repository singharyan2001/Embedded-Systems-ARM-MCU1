/*
    Author:
    Topic:

    Segmentation fault: 
    Segmentation fault is a specific kind of error caused by accessing memory that “does not belong to you“: When a piece of code tries to do a read-and-write operation in a read-only location in memory or freed block of memory, it is known as a segmentation fault. It is an error indicating memory corruption.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
int main()
{
    //reading addresses
    char* address0 = (char*) 0x00007FFF8E3C3524;
    printf("Address stored in address 1 is: %p\n", address0);
    printf("Address of Address1 is: %p\n", &address0);

    //reading data
    //Read operation on address1 variable yields 1 byte of data
    char* address1 = (char*) 0x00007FFF8E3C3124;
    //*address1 = 0x89;
    //char data1 = *address1; //dereferencing a pointer to read data
    //printf("Data is: %c\n", data1);

    //Read operation on address1 variable yields 4 bytes of data
    int* address2 = (int*) 0x00007FFF8E3C3624;
    //char data2 = *address2; //dereferencing a pointer to read data
    //printf("Data is: %d\n", data2);

    //read operation on address1 variable yields 8 bytes of data
    long long int* address3 = (long long int*) 0x00007FFF8E3C3324;
    //char data3 = *address3; //dereferencing a pointer to read data
    //printf("Data is: %ld\n", data3);

    return 0;
}
