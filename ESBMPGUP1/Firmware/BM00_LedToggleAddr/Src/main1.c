/*
 * main1.c
 *
 *  Created on: Apr 15, 2024
 *      Author: singh
 */


#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//UL - Unsigned long
// Typecast it to a volatile int pointer and then dereference the pointer

#define PERIPH_BASE			(0x40000000UL)
#define AHB1PERIPH_OFFSET	(0x20000000UL)
#define AHB1PERIPH_BASE		PERIPH_BASE + AHB1PERIPH_OFFSET

#define GPIOA_OFFSET		(0x0000U)
#define GPIOA_BASE			(AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET			(0x3800)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)

//We don't need these now since we are accessing them using structures
/*
#define RCC_AHB1ENR_OFFSET	(0x30UL)
#define RCC_AHB1ENR			(*(volatile unsigned int *)(RCC_BASE + RCC_AHB1ENR_OFFSET))
*/

#define GPIOAEN				(1U<<0)	//0b 0000 0000 0000 0000 0000 0000 0000 0001

//We don't need these now since we are accessing them using structures
/*
#define GPIOA_MODER_OFFSET	(0x00UL)
#define GPIOA_MODER			(*(volatile unsigned int *)(GPIOA_BASE + GPIOA_MODER_OFFSET))

#define GPIOA_ODR_OFFSET	(0x14UL)
#define GPIOA_ODR			(*(volatile unsigned int *)(GPIOA_BASE + GPIOA_ODR_OFFSET))
*/

#define PIN5				(1U<<5)
#define LED_PIN				PIN5

#define __IO				volatile

typedef struct{
	__IO uint32_t GPIOx_MODER;		/*!< GPIO Port mode register >!*/
	__IO uint32_t GPIOx_OTYPER;		/*!< GPIO port output type register >!*/
	__IO uint32_t GPIOx_OSPEEDR;	/*!< GPIO port output speed register >!*/
	__IO uint32_t GPIOx_PUPDR;		/*!< GPIO port pull-up/pull-down register  >!*/
	__IO uint32_t GPIOx_IDR;		/*!< GPIO port input data register >!*/
	__IO uint32_t GPIOx_ODR;		/*!< GPIO Port output data register >!*/
	__IO uint32_t GPIOx_BSRR;		/*!< GPIO Port bit set/reset register  >!*/
	__IO uint32_t GPIOx_LCKR;		/*!< GPIO Port configuration lock register  >!*/
	__IO uint32_t GPIOx_AFR[2];		/*!< GPIO alternate function low register >!*/
}GPIO_t1;
//or
typedef struct{
	__IO uint32_t GPIOx_MODER;		/*!< GPIO Port mode register >!*/
	__IO uint32_t DUMMY_R[4];
	__IO uint32_t GPIOx_ODR;		/*!< GPIO Port output data register >!*/
}GPIO_t2;

typedef struct{
	__IO uint32_t DUMMY_R[8];
	__IO uint32_t RCC_AHB1ENR_RE;		/*!< RCC AHB1 peripheral clock enable register  >!*/
}RCC_t1;

#define RCC		((RCC_t1*) RCC_BASE)
#define GPIOA	((GPIO_t1*)GPIOA_BASE)


int main(void)
{
	/* 1. Enable clock access to GPIOA */
	RCC->RCC_AHB1ENR_RE |= GPIOAEN;

	/* 2. SET PA5 as Output pin */
	GPIOA->GPIOx_MODER |= (1U<<10);
	GPIOA->GPIOx_MODER &= ~(1U<<11);

	while(1){
		/*3. SET PA5 High*/
		//GPIOA->GPIOx_ODR |= LED_PIN;

		/*4. EXP2: Toggle PA5*/
		GPIOA->GPIOx_ODR ^= LED_PIN;

		for(int i=0; i<1000000; i++){}
	}
}

