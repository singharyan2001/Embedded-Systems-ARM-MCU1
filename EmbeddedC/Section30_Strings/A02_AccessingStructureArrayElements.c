/*
    Author: Aryan Singh
    Topic: Accessing Structure Array Elements using a structure pointer.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>

//Definition of a student Record
typedef struct {
    int rollNumber;
    char name[30];
    char branch[40];
    char DOB[15]; //dd/mm/yyyy
    int semister;
}STUDENT_INFO_t;

void display_all_records(STUDENT_INFO_t *pArray, int max_record);

int const max_record = 3;
STUDENT_INFO_t arr[3] = {
    {77, "Aryan Singh", "ENTC","14/03/2001", 7}, 
    {78, "John Doe", "Computerscience","1/04/2003", 7},
    {79, "Will smith", "Mechanical","21/07/2006", 7}
};

int main()
{
    display_all_records(arr, max_record);
    return 0;
}

//Method 1
/*
void display_all_records(STUDENT_INFO_t *pArray, int max_record)
{
    for (int i = 0; i < max_record; i++)
    {
        printf("Roll Number of %dth element: %d\n", i, pArray->rollNumber);
        printf("Name of %dnd element: %s\n", i, pArray->name);
        printf("Branch of %drd element: %s\n", i, pArray->branch);
        printf("DOB of %dth element: %s\n", i, pArray->DOB);
        printf("Semister of %dth element: %d\n", i, pArray->semister);
        pArray++;
        printf("------------------------------------------------------\n");
    }
}
*/
//Method 2
/*
void display_all_records(STUDENT_INFO_t *pArray, int max_record)
{
    for (int i = 0; i < max_record; i++)
    {
        printf("Roll Number of %dth element: %d\n", i, (pArray+i)->rollNumber);
        printf("Name of %dnd element: %s\n", i, (pArray+i)->name);
        printf("Branch of %drd element: %s\n", i, (pArray+i)->branch);
        printf("DOB of %dth element: %s\n", i, (pArray+i)->DOB);
        printf("Semister of %dth element: %d\n", i, (pArray+i)->semister);
        printf("------------------------------------------------------\n");
    }
}
*/

//Method 3
///*
void display_all_records(STUDENT_INFO_t *pArray, int max_record)
{
    for (int i = 0; i < max_record; i++)
    {
        printf("Roll Number of %dth element: %d\n", i, pArray[i].rollNumber);   //(*(pArray+i)).rollNumber
        printf("Name of %dnd element: %s\n", i, pArray[i].name);
        printf("Branch of %drd element: %s\n", i, pArray[i].branch);
        printf("DOB of %dth element: %s\n", i, pArray[i].DOB);
        printf("Semister of %dth element: %d\n", i, pArray[i].semister);
        printf("------------------------------------------------------\n");
    }
}
//*/
