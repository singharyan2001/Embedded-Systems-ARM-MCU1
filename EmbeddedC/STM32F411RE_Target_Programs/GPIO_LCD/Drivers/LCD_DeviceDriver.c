/*
 * LCD_DeviceDriver.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Aryan singh
 */

//This file will contain all the functions for LCD Device Driver

#include <stdint.h>
#include "Inc/STM32F411RE.h"
#include "Inc/LCD_DeviceDriver.h"

void LCD_Init(){
	//code here
}

void LCD_Command(unsigned char Command){
	unsigned char buffer;
	buffer = (Command>>4) & 0x0F;	//Command is of 8 bits and LCD is operating in 4 bit mode, so first send 1st 4 bits.
}

//Mode - Read, Write
void LCD_WriteChar(unsigned char Data, unsigned char Mode){
	//code here
}

void LCD_WriteString(const unsigned char *String){
	//code here
}

void msdelay(uint32_t time){
	for(uint32_t i; i < time; i++);
}
