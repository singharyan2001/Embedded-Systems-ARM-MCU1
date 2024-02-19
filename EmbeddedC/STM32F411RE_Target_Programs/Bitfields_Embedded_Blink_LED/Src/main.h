/*
 * main.h
 *
 *  Created on: Feb 8, 2024
 *      Author: singh
 */

#ifndef MAIN_H_
#define MAIN_H_

typedef struct{
	uint32_t GPIOA_EN	:1;
	uint32_t GPIOB_EN	:1;
	uint32_t GPIOC_EN	:1;
	uint32_t GPIOD_EN	:1;
	uint32_t GPIOE_EN	:1;
	uint32_t RESERVED_1	:2;
	uint32_t GPIOH_EN	:1;
	uint32_t RESERVED_2	:4;
	uint32_t CRC_EN		:1;
	uint32_t RESERVED_3	:8;
	uint32_t DMA1_EN	:1;
	uint32_t DMA2_EN	:1;
	uint32_t RESERVED_4	:9;
}RCC_AHB1ENR_t;

typedef struct{
	uint32_t MODER0		:2;		//Mode Register of Pin 0
	uint32_t MODER1		:2;
	uint32_t MODER2		:2;
	uint32_t MODER3		:2;
	uint32_t MODER4		:2;
	uint32_t MODER5		:2;
	uint32_t MODER6		:2;
	uint32_t MODER7		:2;
	uint32_t MODER8		:2;
	uint32_t MODER9		:2;
	uint32_t MODER10	:2;
	uint32_t MODER11	:2;
	uint32_t MODER12	:2;
	uint32_t MODER13	:2;
	uint32_t MODER14	:2;
	uint32_t MODER15	:2;
}GPIOx_MODER_t;

typedef struct{
	uint32_t ODR0		:1;		//Output Data Register of Pin 0
	uint32_t ODR1		:1;
	uint32_t ODR2		:1;
	uint32_t ODR3		:1;
	uint32_t ODR4		:1;
	uint32_t ODR5		:1;
	uint32_t ODR6		:1;
	uint32_t ODR7		:1;
	uint32_t ODR8		:1;
	uint32_t ODR9		:1;
	uint32_t ODR10		:1;
	uint32_t ODR11		:1;
	uint32_t ODR12		:1;
	uint32_t ODR13		:1;
	uint32_t ODR14		:1;
	uint32_t ODR15		:1;
	uint32_t RESERVED	:16;
}GPIOx_ODR_t;


#endif /* MAIN_H_ */
