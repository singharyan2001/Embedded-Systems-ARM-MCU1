/*
    Author: Aryan Singh
    Topic: Arrays
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>

uint32_t Swap_arrays(uint32_t *pArray1, uint32_t *pArray2, uint32_t items1, uint32_t items2);
void Display_array(uint32_t *pArray, uint32_t items, uint32_t no);

int main()
{
    uint32_t items1, items2;
    printf("Array Swapping Program!!\n");

    printf("Enter length of array 1 and array 2: ");
    scanf("%d %d", &items1, &items2);

    if ((items1 < 0) || (items2 < 0)){
        printf("Item size is less than 0 i.e. negative. Not possible!\n");
        return 0;
    }

    uint32_t Arr1[items1];
    uint32_t Arr2[items2];

    for(uint32_t i = 0; i < items1; i++){
        printf("Enter array1 Element %d : \n", i);
        scanf("%d", &Arr1[i]);
    }

    for(uint32_t j = 0; j < items2; j++){
        printf("Input array2 Element %d : \n", j);
        scanf("%d", &Arr2[j]);  
    }

    printf("Printing Contents of array1 and array2 before swap\n");
    Display_array(Arr1, items1, 1);
    Display_array(Arr2, items2, 2);
    printf("\n");
    
    Swap_arrays(Arr1, Arr2, items1, items2);
    printf("Printing Contents of array1 and array2 after swap\n");
    Display_array(Arr1, items1, 1);
    Display_array(Arr2, items2, 2);

    return 0;
}

void Display_array(uint32_t *pArray, uint32_t items, uint32_t no){
    for(uint32_t i = 0; i < items; i++){
        printf("Array%d Element %d: %d\n", no, i, pArray[i]);
    }
}

uint32_t Swap_arrays(uint32_t *pArray1, uint32_t *pArray2, uint32_t items1, uint32_t items2){
    uint32_t temp1, temp2, xitems;
    if (items1 > items2){
        xitems = items1;
    }
    else{
        xitems = items2;
    }
    for(uint32_t i = 0; i < xitems; i++){
        temp1 = pArray1[i];
        temp2 = pArray2[i];
        pArray1[i] = temp2;
        pArray2[i] = temp1;
    }
}

