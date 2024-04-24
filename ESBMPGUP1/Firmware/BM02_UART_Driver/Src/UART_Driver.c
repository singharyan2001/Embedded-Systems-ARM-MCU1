
#include "UART_Driver.h"


/*
 * Under AF07
 * USART Tx - PA2
 * USART Rx - PA3
 */
//USART Clock
#define SYS_FREQ		16000000		//Default system frequency
//In clock tree, the system clock is taken and then it is divided by a value
#define APB1CLK			SYS_FREQ

#define UART_BAUDRATE	115200
#define CR1_TE			(1U<<3)
#define CR1_RE			(1U<<2)
#define CR1_UE			(1<<13)

#define SR_TXE			(1U<<7)
#define SR_RXNE			(1U<<5)

#define GPIOAEN			(1U<<0)
#define USART2EN		(1U<<17)

#define MAX_STRING_LENGTH 100


void usart2_init(void);
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphCLK, uint32_t BaudRate);
static uint16_t Compute_UART_div_bd(uint32_t PeriphCLK, uint32_t BaudRate);

void usart2_init(void)
{
	/***********Configure UART Tx GPIO Pin***********/	//PA2 -> UART_Tx pin
	/*Enable Clock access to UART Tx GPIO Pin*/
	RCC->AHB1ENR |= GPIOAEN;

	/*Set the UART GPIO Pin to Alternate function mode*/
	//PA2 -Tx //5,4 - 10 ;
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	//PA3 Rx - (7,6) - (10)
	GPIOA->MODER &= ~(1U<<6);
	GPIOA->MODER |= (1U<<7);

	/*Set the UART GPIO Pin to alternate function type to UART_Tx (AF07)*/
	/*PA2*/ //AFRL [PA2] -> 11,10,9,8 -- 0111 //AFR[0] - L ; [1] - h
	GPIOA->AFR[0] &= ~(1U<<11);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<8);

	/*PA3*/ //15,14,13,12 - 0111
	GPIOA->AFR[0] &= ~(1U<<15);
	GPIOA->AFR[0] |= (1U<<14);
	GPIOA->AFR[0] |= (1U<<13);
	GPIOA->AFR[0] |= (1U<<12);

	/***********Configure the USART Module***********/
	/*Enable Clock access to UART 2*/ //APB1
	RCC->APB1ENR |= USART2EN;

	/*Configure Baud rate*/
	uart_set_baudrate(USART2, APB1CLK, UART_BAUDRATE);

	/*Configure the transfer direction*/

	//1. Enable the TX and RX pin
	USART2->CR1 = (CR1_TE | CR1_RE);
/*
 * by not using OR(|), we set all bits 0 except bit 3. hence we get the default settings.
 * Therefore 1 start bit, 8 data bits and 2 stop bits. hardware flow control etc are all disabled.
*/

	/*Enable the USART Module*/
	USART2->CR1 |= CR1_UE;	//We used OR Operator (|) To make sure not to set all the other bits to 0.
}

void uart2_write(int ch){
	/*Make sure the transmit data register is empty*/
	while(!(USART2->SR & SR_TXE)){};

	/*Write the Data transmit register //Data register*/
	USART2->DR = (ch & 0xff);
}

void uart_Wstring(char *message){
	for(int i = 0; message[i] != '\0'; i++){
		uart2_write(message[i]);
	}
}

char uart2_read(void){
	//Make sure the receive data register is not empty
	while(!(USART2->SR & SR_RXNE)){};

	//Return data
	return USART2->DR;
}

char uart2_Rstring(char *buffer){
	int i = 0;
	char received_char;

	do{
		received_char = uart2_read();
		buffer[i++] = received_char;
	} while(received_char != '\n' && i < MAX_STRING_LENGTH - 1);

	buffer[i] = '\0';
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphCLK, uint32_t BaudRate){
	USARTx->BRR = Compute_UART_div_bd(PeriphCLK, BaudRate);
}

static uint16_t Compute_UART_div_bd(uint32_t PeriphCLK, uint32_t BaudRate){
	return ((PeriphCLK + (BaudRate/2U))/BaudRate);
}

