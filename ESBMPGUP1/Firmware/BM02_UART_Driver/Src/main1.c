/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "UART_Driver.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define GPIOAEN		(1U<<0)
#define PIN5		(1U<<5)
#define LED_PIN		PIN5

void GPIOA5_init(void);
void GPIOA5_Toggle(void);

char key;

int main(void)
{
	GPIOA5_init();

	usart2_init();

    while(1){
    	//Send message
    	//uart2_write('Y'); //uart_Wstring("[Hello, World!]\n\r");
    	key = uart2_read();

    	if(key == '1'){
    		GPIOA5_Toggle();
    	}
    	else{
    		uart_Wstring("[Hello, World!]\n\r");
    	}

    }
}

void GPIOA5_init(void){
	RCC->AHB1ENR |= GPIOAEN;
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);
}

void GPIOA5_Toggle(void){
	GPIOA->ODR ^= LED_PIN;
	for(int i = 0; i < 1000000; i++){}
}


