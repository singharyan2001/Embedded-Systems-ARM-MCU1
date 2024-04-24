/*
 * Developing The GPIO Input Driver using IDR
 * IDR -> Input Data Register
 * Using the Push button on the Dev board i.e. PC13
*/

#include "stm32f4xx.h"
#include <stdint.h>

#define GPIOAEN			(1U<<0)
#define GPIOCEN			(1U<<2)

#define PIN5			(1U<<5)
#define PIN13			(1U<<13)

#define SET_LEDPIN		PIN5
#define RESET_LEDPIN	(1U<<21)
#define BUTTON_PIN		PIN13

int main(){
	//Enable the clock access to GPIO A & C
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;

	//Set the GPIO Pins Direction
	//Set PA5 as Output pin
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	//Set PC13 as Input pin
	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);

	GPIOC->PUPDR |= (1U<<26);
	GPIOC->PUPDR &= ~(1U<<27);

	//Implementing the Condition
	while(1){
		if((GPIOC->IDR &= PIN13) == 0){
			//Set LED On
			GPIOA->BSRR |= SET_LEDPIN;		//Setting BS5 [Bit set 5] (1U<<5) which sets the pin
			//for(int i=0; i<1000000;i++){}	//delay
		}
		else{
			//Set LED Off
			GPIOA->BSRR |= RESET_LEDPIN;	//delay
			//for(int i=0; i<1000000;i++){}	//Setting BR5 [Bit Reset 5] (1U<<21) which Resets the pin
		}
	}
}

