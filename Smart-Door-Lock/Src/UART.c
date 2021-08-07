/*
 * UART.c
 *
 *  Created on: Nov 4, 2019
 *      Author: GO
 */

#include"utils.h"
#include "register.h"
#include "std_types.h"
#include "DIO.h"
#include "UART.h"
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void USART_voidInit(void)
{
	u8 UCSRC_Value=0;

	// Transmission,receiver enable
	set_bit(UCSRB,3);
	set_bit(UCSRB,4);

	// Acces UCSRC
	set_bit(UCSRC_Value,7);

	// charactersize 8 bits

	set_bit(UCSRC_Value,2);
	set_bit(UCSRC_Value,1);

	//set the value to the register
	UCSRC=UCSRC_Value;

	//set 9600 bps
	UBRRL=51;

}

void USART_voidTransmit(u8 Data)
{
	// Polling with blocking (busy waiting) on UDRE
	while((get_bit(UCSRA,5))==0);
	//transmit the data
	UDR=Data;
}

u8 USART_u8Receive(void)
{
	// Polling with blocking on RXC flag
	while((get_bit(UCSRA,7))==0);
	//get the data
	return UDR;

}

void USART_voidSendString(char*str)
{
	while(*str!='\0')
	{
		USART_voidTransmit(*str);
		str++;
	}
}


void Display(char*str)
{
	while(*str!='\0')
	{
		if(*str == '\n')
		{
			str++;
			continue;
		}
		else
		{
		USART_voidTransmit(*str);
		str++;
		}
	}
}
u8 *USART_voidRecieveString(void)
{
	u8 *p;
	u8 *p1;
	p1=p;
	while(1)
	{
	*p=USART_u8Receive();
	if(*p=='\r') break;
	p++;
	}
	return p1;
}



void USART_voidSendAsciiNumber(u8 Number)
{
	u8 y=1;
	if (Number==0)
	{
		USART_voidTransmit('0');
	}
	while(Number!=0)
	{
		y=(y*10)+(Number%10);
		Number=(Number/10);
	}
	while(y!=1)
	{
		USART_voidTransmit((y%10)+48);
		y=y/10;
	}
}

bool USART_u8CompareArray(char arr1[],char arr2[])
{
	u8 i=0;
	u8 i2=0;
	while(arr1[i]!='\0' || arr2[i2]!='\0')
	{
		if(arr1[i] == '\n')
		{
			i++;
			continue;
		}
		else
		{
			if( arr1[i] != arr2[i2]) return false;
			i++;
			i2++;
		}
	}
	return true;
}


