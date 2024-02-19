/*
    Author:
    Topic: ASCII Codes
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
int main()
{
    /*
    char a1 = 65;
    char a2 = 112;
    char a3 = 112;
    char a4 = 108;
    char a5 = 101;
    char a6 = 58;
    char a7 = 41;*/
    //or
    /*
    char a1 = 'A';
    char a2 = 'p';
    char a3 = 'p';
    char a4 = 'l';
    char a5 = 'e';
    char a6 = ':';
    char a7 = ')';
    */
    //or
    char a[] = {'A','p','p','l','e',':',')'}; 
    char a1[] = "Apple:)";

    for(int i = 0; i<7; i++){
        printf("The string is: %c\n", a[i]);
    }
    printf("\n");

    for(int i = 0; i<7; i++){
        printf("The string is: %d\n", a[i]);
    }

    printf("\n");
    
    for(int i = 0; i<7; i++){
        printf("%c", a1[i]);
    }
    printf("\nIn decimal format: " );
    for(int i = 0; i<7; i++){
        printf("%d", a1[i]);
    }
    printf("\nIn Hex format: ");
    for(int i = 0; i<7; i++){
        printf("%x", a1[i]);
    }



    return 0;
}