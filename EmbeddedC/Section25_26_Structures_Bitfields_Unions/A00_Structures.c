/*
    Author: Aryan Singh
    Topic: Structures
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>

//Structure Definition
struct CarModel{
    unsigned int carNumber;
    uint32_t CarPrice;
    uint16_t CarMaxSpeed;
    float CarWeight;
};

struct Dataset{
    char data1;
    int data2;
    char data3;
    short data4;
};

/*
struct DataAA{
    char data1;
    int data2;
    char data3;
    short data4;
}_attribute_((packed));
*/

//Typedef
typedef struct{
    char data1;
    int data2;
    char data3;
    short data4;
}Data_t;            //_t -> Typedef Definition ; _e -> Enum Definition

//Nested Structure
struct NewData{
    char data1;
    int data2;
    char data3;
    short data4;
    struct{
        int data5;
        short data6;
    }New;
};

//Structure with structure pointer as a member element
struct PDataset{
    char data1;
    int data2;
    char data3;
    short data4;
    //struct *pCarBMW;
};

//Passing the address of a structure in a Function
void displayMemberElements(struct Dataset *pData);
//by value
void displayMemberElements1(struct Dataset Data);

//Main function
int main()
{
    //struct CarModel CarBMW, CarFord, CarHonda;  //<User_defined_data_type> <Structure_Variable>

    //struct CarModel CarBMW = {.carNumber = 7, .CarPrice = 10000000, .CarMaxSpeed = 255, .CarWeight = 1750}; //C99 Method
    //printf("CarBMW -- Car Number: %u, Car Price: %u, Car Max Speed: %u, Car Weight: %f\n", CarBMW.carNumber, CarBMW.CarPrice, CarBMW.CarMaxSpeed, CarBMW.CarWeight);

    struct CarModel CarFord = {9, 850000, 200, 1550}; //C89 Method
    printf("CarBMW -- Car Number: %u, Car Price: %u, Car Max Speed: %u, Car Weight: %f\n", CarFord.carNumber, CarFord.CarPrice, CarFord.CarMaxSpeed, CarFord.CarWeight);

    //How is data stored in a structure and Size of a structure
    struct Dataset Data;
    Data.data1 = 0x11;
    Data.data2 = 0xFFFFEEEE;
    Data.data3 = 0x22;
    Data.data4 = 0xABCD;
    uint8_t Struct_Size = sizeof(Data);
    uint8_t *ptr;
    ptr = (uint8_t *)&Data;

    printf("Address                     Data  \n");
    printf("==================================\n");
    printf("%p              %x\n", ptr, *ptr);
    ptr++;
    printf("%p              %x\n", ptr, *ptr);
    ptr++;
    printf("%p              %x\n", ptr, *ptr);
    ptr++;
    printf("%p              %x\n", ptr, *ptr);
    ptr++;
    printf("%p              %x\n", ptr, *ptr);
    ptr++;
    printf("%p              %x\n", ptr, *ptr);
    ptr++;
    printf("%p              %x\n", ptr, *ptr);
    ptr++;
    printf("%p              %x\n", ptr, *ptr);
    ptr++;
    printf("%p              %x\n", ptr, *ptr);
    ptr++;
    printf("%p              %x\n", ptr, *ptr);
    ptr++;
    printf("%p              %x\n", ptr, *ptr);
    ptr++;
    printf("%p              %x\n", ptr, *ptr);

    printf("Total Size of the Structure is: %d\n", Struct_Size);

    //Structure Padding
    //Above example is of Structure Padding

    /*
    //Without Structure Padding - Packed Structure
    struct DataAA AAA;
    uint8_t Struct_Size_2 = sizeof(AAA);
    printf("Total Size of the Structure is: %d\n", Struct_Size_2);
    */
    
    //Structure Pointer
    printf("Before: Data.data1 = %x\n", Data.data1);
    struct Dataset *pData;
    pData = &Data;
    pData -> data1 = 0x55;
    printf("After: Data.data1 = %x\n", Data.data1);

    //Passing the address of a structure in a Function
    displayMemberElements(pData);
    printf("\n");
    //By value
    displayMemberElements1(Data);

    return 0;
}

void displayMemberElements(struct Dataset *pData)
{
    printf("Data1: %x\n", pData->data1);
    printf("Data2: %x\n", pData->data2);
    printf("Data3: %x\n", pData->data3);
    printf("Data4: %x\n", pData->data4);
}

void displayMemberElements1(struct Dataset Data)
{
    printf("Data1: %x\n", Data.data1);
    printf("Data2: %x\n", Data.data2);
    printf("Data3: %x\n", Data.data3);
    printf("Data4: %x\n", Data.data4);
}


