/*
    Author: Aryan Singh
    Topic: Storage Class Specifiers - Static, Extern   
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "A02_SCS_Extern.h"

int mainprivatedata; //Global for the entire project

void my_func1(void);
void my_func2(void);

int main()
{
    my_func1();
    my_func1();
    my_func1();
    my_func1();
    
    printf("\n");
    
    my_func2();
    my_func2();
    my_func2();
    my_func2();
    
    printf("\n");
    
    mainprivatedata = 100;
    printf("mainprivatedata = %d\n", mainprivatedata);
    file1_myfunc3();
    printf("mainprivatedata = %d\n", mainprivatedata);
    
    return 0;
}

void my_func1(void){
    int count = 0;  //Local Variable
    count += 1;
    printf("This function executed %d time(s)\n", count);
}

void my_func2(void){
    static int count = 0;  //Private Global Variable
    count += 1;
    printf("This function executed %d time(s)\n", count);
}

//This function cannot be accessed by other files.
//Private Function 
static void change_system_clock(int sc){
    printf("System clock changed to %d time(s)\n", sc);
}
