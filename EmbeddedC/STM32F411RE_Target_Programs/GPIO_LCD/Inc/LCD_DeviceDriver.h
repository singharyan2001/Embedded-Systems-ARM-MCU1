/*
 * LCD_DeviceDriver.h
 *
 *  Created on: Feb 13, 2024
 *      Author: singh
 */

#ifndef LCD_DEVICEDRIVER_H_
#define LCD_DEVICEDRIVER_H_

/*
 * Pins selected on STM32F411RE *
 * RS	- PA13
 * R/W	- PA14
 * E	- PA15
 * D4	- PC0
 * D5	- PC01
 * D6	- PC02
 * D7	- PC03
 */

extern void LCD_Init();
extern void LCD_Command(unsigned char Command);
extern void LCD_WriteChar(unsigned char Data, unsigned char Mode); //Mode - Read, Write
extern void LCD_WriteString(const unsigned char *String);
extern void msdelay(uint32_t time);

#endif /* LCD_DEVICEDRIVER_H_ */
