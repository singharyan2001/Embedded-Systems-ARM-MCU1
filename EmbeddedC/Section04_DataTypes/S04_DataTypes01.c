/*
    Author: Aryan Singh
    Topic: Data Types

    C data Types - 
        Integer data types - used to represent whole numbers; ex - 10,20,30
        Float Data Types - used to represent real numbers; ex - 10.0, 24.05, 33.45, 60.00000023

    Integer data types for signed data
    ex temp value - can be positive or negative value, therefore signed data
    ex Distance Value - wull always be in positive value, therefore unsigned data
    
    signed data - memory sizes
    1. char - 1 byte
    2. short int (or short) - 2 bytes
    3. int - 4 bytes
    4. long int (or long) - 8 bytes
    5. long long int (or long long) - 8 bytes

    unsigned data - memory sizes
    1. unsigned char - 1 byte
    2. unsigned short int - 2 byte
    3. unsigned int - 4 byte
    4. unsigned long int - 8 bytes
    5. unsigned long long int - 8 bytes

    Memory sizes are fixed by the compilers

    Thes data types will always be fixed size irrespective of Compilers:
    Short (signed or unsigned) - always 2 bytes
    char (signed or unsigned) - always 1 byte
    long long (signed or unsigned) - always 8 bytes

    Format Specifiers
    1. int - %d
    2. float - %f
    3. char - %c
    4. string of characters - %s
    5. Unsigned integer format specifiers - %u
    6. Long int - %ld
    7. Hex format - %x or %X
    8. Octal format - %o
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
int main()
{
    //basic Data types
    int a = 10;
    float b = 20;
    char c = 'X';

    printf("int a is %d and Size of Integer a is %d \n", a, sizeof(a));
    printf("float b is %f and Size of Float b is %d\n", b, sizeof(b));
    printf("char c is %c and Size of Char c is %d\n", c, sizeof(c));

    //example
    /*
    unsigned char/int cityXTemperature;
    cityXTemperature = 25;
    printf("city temperature: %c ->>> %d ; size ->>> %d\n", cityXTemperature, sizeof(cityXTemperature));
    */
    return 0;
}

