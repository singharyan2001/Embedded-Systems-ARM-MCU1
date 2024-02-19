/*
    Author:
    Topic:
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
	unsigned char data = (unsigned char) 0x87 + 0xff00;

	float result = (float)80/3;

	printf("Data : %u  result: %f\n", data, result);

    unsigned char data1 = 0x1FFFFFFFFA0B0 + 0x1245;

    printf("Data : %u  result: %f\n", data1, result);
}
