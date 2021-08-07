/*
 * UART.h
 *
 *  Created on: Nov 4, 2019
 *      Author: GO
 */

#ifndef UART_H_
#define UART_H_

#include"stdbool.h"

void USART_voidInit(void);
void USART_voidTransmit(u8 Data);
u8 USART_u8Receive(void);
void USART_voidSendString(char*str);
void Display(char*str);
u8 *USART_voidRecieveString(void);
void USART_voidSendAsciiNumber(u8 Number);
bool USART_u8CompareArray(char arr1[],char arr2[]);

#endif /* UART_H_ */
