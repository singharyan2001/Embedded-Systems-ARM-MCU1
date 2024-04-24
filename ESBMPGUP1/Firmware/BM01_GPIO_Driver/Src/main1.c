
/*
 * Developing The GPIO Driver using BSSR
 * Using the BSRR register to develop the GPIO Driver
 * BSRR -> Bit Set Reset Register
 */

#include "stm32f4xx.h"
#include <stdint.h>

#define GPIOAEN			(1U<<0)
#define PIN5			(1U<<5)

#define SET_LEDPIN		PIN5
#define RESET_LEDPIN	(1U<<21)

int main(){
	//code here
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	while(1){
		GPIOA->BSRR |= SET_LEDPIN;		//Setting BS5 [Bit set 5] (1U<<5) which sets the pin
		for(int i=0; i<1000000;i++){}	//delay

		GPIOA->BSRR |= RESET_LEDPIN;	//delay
		for(int i=0; i<1000000;i++){}	//Setting BR5 [Bit Reset 5] (1U<<21) which Resets the pin
	}
}


