/*
 * STM32F411RE.h
 *
 *  Created on: Feb 13, 2024
 *      Author: singh
 */

#ifndef STM32F411RE_H_
#define STM32F411RE_H_

#include <stdint.h>

/* RCC Registers */
//AHBxENR Registers
#define ADDR_REG_AHB1ENR ( (RCC_AHB1ENR_t*)0x40023830 )

//RCC Enable Registers
#define RCC_ENABLE		(1)
#define RCC_DISABLE		(0)

/* GPIO Peripheral Register Addresses */
//GPIO Mode Registers
#define ADDR_REG_GPIOA_MODE	 ( (GPIOx_MODER_t*)0x40020000 )
#define ADDR_REG_GPIOB_MODE	 ( (GPIOx_MODER_t*)0x40020400 )
#define ADDR_REG_GPIOC_MODE	 ( (GPIOx_MODER_t*)0x40020800 )
#define ADDR_REG_GPIOD_MODE	 ( (GPIOx_MODER_t*)0x40020C00 )
#define ADDR_REG_GPIOE_MODE	 ( (GPIOx_MODER_t*)0x40021000 )
#define ADDR_REG_GPIOH_MODE	 ( (GPIOx_MODER_t*)0x40021C00 )
//GPIO Pull-up/down Registers
#define ADDR_REG_GPIOA_PUPDR ( (GPIOx_PUPDR_t*)0x4002000C )
#define ADDR_REG_GPIOB_PUPDR ( (GPIOx_PUPDR_t*)0x4002040C )
#define ADDR_REG_GPIOC_PUPDR ( (GPIOx_PUPDR_t*)0x4002080C )
#define ADDR_REG_GPIOD_PUPDR ( (GPIOx_PUPDR_t*)0x40020C0C )
#define ADDR_REG_GPIOE_PUPDR ( (GPIOx_PUPDR_t*)0x4002100C )
#define ADDR_REG_GPIOH_PUPDR ( (GPIOx_PUPDR_t*)0x40021C0C )
//GPIO Input Data Register
#define ADDR_REG_GPIOA_IDR 	 ( (GPIOx_IDR_t*)0x40020010 )
#define ADDR_REG_GPIOB_IDR	 ( (GPIOx_IDR_t*)0x40020410 )
#define ADDR_REG_GPIOC_IDR	 ( (GPIOx_IDR_t*)0x40020810 )
#define ADDR_REG_GPIOD_IDR	 ( (GPIOx_IDR_t*)0x40020C10 )
#define ADDR_REG_GPIOE_IDR	 ( (GPIOx_IDR_t*)0x40021010 )
#define ADDR_REG_GPIOH_IDR	 ( (GPIOx_IDR_t*)0x40021C10 )
//GPIO Output Data Register
#define ADDR_REG_GPIOA_ODR	 ( (GPIOx_ODR_t*)0x40020014 )
#define ADDR_REG_GPIOB_ODR	 ( (GPIOx_ODR_t*)0x40020414 )
#define ADDR_REG_GPIOC_ODR	 ( (GPIOx_ODR_t*)0x40020814 )
#define ADDR_REG_GPIOD_ODR	 ( (GPIOx_ODR_t*)0x40020C14 )
#define ADDR_REG_GPIOE_ODR	 ( (GPIOx_ODR_t*)0x40021014 )
#define ADDR_REG_GPIOH_ODR	 ( (GPIOx_ODR_t*)0x40021C14 )

//GPIO High/Low Registers
#define GPIO_HIGH		(1)
#define GPIO_LOW		(0)

//GOPIO Hex codes
#define GPIO_MODE_0		(0)
#define GPIO_MODE_1		(1)
#define GPIO_MODE_2		(2)
#define GPIO_MODE_3		(3)

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
	uint32_t PUPDR0		:2;		//Pull up/down setting for Pin 0
	uint32_t PUPDR1		:2;
	uint32_t PUPDR2		:2;
	uint32_t PUPDR3		:2;
	uint32_t PUPDR4		:2;
	uint32_t PUPDR5		:2;
	uint32_t PUPDR6		:2;
	uint32_t PUPDR7		:2;
	uint32_t PUPDR8		:2;
	uint32_t PUPDR9		:2;
	uint32_t PUPDR10	:2;
	uint32_t PUPDR11	:2;
	uint32_t PUPDR12	:2;
	uint32_t PUPDR13	:2;
	uint32_t PUPDR14	:2;
	uint32_t PUPDR15	:2;
}GPIOx_PUPDR_t;

typedef struct{
	uint32_t IDR0		:1;		//Input Data Register of Pin 0
	uint32_t IDR1		:1;
	uint32_t IDR2		:1;
	uint32_t IDR3		:1;
	uint32_t IDR4		:1;
	uint32_t IDR5		:1;
	uint32_t IDR6		:1;
	uint32_t IDR7		:1;
	uint32_t IDR8		:1;
	uint32_t IDR9		:1;
	uint32_t IDR10		:1;
	uint32_t IDR11		:1;
	uint32_t IDR12		:1;
	uint32_t IDR13		:1;
	uint32_t IDR14		:1;
	uint32_t IDR15		:1;
	uint32_t RESERVED	:16;
}GPIOx_IDR_t;

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

#endif /* STM32F411RE_H_ */
