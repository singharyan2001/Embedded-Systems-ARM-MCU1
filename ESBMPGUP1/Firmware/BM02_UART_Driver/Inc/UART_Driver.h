/*
 * UART_Driver.h
 *
 *  Created on: Apr 18, 2024
 *      Author: singh
 */

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include "stm32f4xx.h"
#include <stdint.h>


//void usart2_tx_init(void);
void usart2_init(void);
void uart2_write(int ch);
void uart_Wstring(char *message);
char uart2_read(void);
void uart2_Rstring(char *buffer);


#endif /* UART_DRIVER_H_ */
