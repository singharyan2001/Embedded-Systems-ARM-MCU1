/*
    Author: Aryan Singh
    Topic: Strings in C
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>

int main()
{
    //Storing Characters data
    char Msg1[] = "Aryan";                      //Method 1
    char Msg2[] = {'a','r','y','a','n','\0'};   //Method 2
    char Msg3[10] = "Aryan";

    printf("Msg1: %d bytes\n", sizeof(Msg1));
    printf("Msg2: %d bytes\n", sizeof(Msg2));
    printf("Msg3: %d bytes\n", sizeof(Msg3));

    char Msg4[] = "A";  //String Definition, there is NULL Character.  
    char Msg5 = 'A';    //Character Definition, there is no NULL character.

    char const *MsgX1 = "Aryan";  //This is stored in ROM     //String Literal/constant
    // so write like this: char const *MsgX1 = "Aryan"; //best way to write string definition for string literal/constant
    char MsgX[] = "Aryan";  //This is stored in RAM
    printf("Message is: %s\n", MsgX1);
    printf("Address of MsgX1 variable: %p\n", &MsgX1);  //We will get the RAM Address        //This variable living in RAM i.e. created in stack but pointing to flash.
    printf("Value of MsgX1 variable: %p\n", MsgX1);     //We will get the (ROM)Flash Address //This variable is the data address in flash.

    MsgX[0] = 'X';
    //MsgX1[0] = 'X';   //this will cause an Exception.

    printf("Message is: %s\n", MsgX1);
    printf("Message is: %s\n", MsgX);

    char MsgXX1[] = "Hello How are you?";
    printf("Message is: %s\n", MsgXX1);

    //Inputing a String
    char name[100];
    printf("Enter your name: ");
    scanf("%[^\n]s", &name);    //using Scanset
    printf("Name entered: %s\n", name);

    //Inputing a string and also reading strings with whitespace characters
    char fname[10], lname[10];
    printf("Enter your name: ");
    scanf("%s%s", &fname, &lname);
    printf("Name entered: %s %s\n", fname, lname);

    return 0;
}
