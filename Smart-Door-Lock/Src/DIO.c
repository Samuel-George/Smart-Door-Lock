/*
 * DIO.c
 *
 *  Created on: Sep 4, 2019
 *      Author: Manal
 */

#include "std_types.h"
#include "utils.h"
#include "register.h"
#include  "DIO.h"


void DIO_vidSetPinDirection(u8 port, u8 pin, u8 dir)
{
	switch (port)
	{
	case 0: {
		if (dir==0)
			clr_bit(DDRA, pin);
		else if (dir==1)
			set_bit(DDRA, pin);
		break;
	}
	case 1: {
		if (dir==0)
			clr_bit(DDRB, pin);
		else if (dir==1)
			set_bit(DDRB, pin);
		break;
	}
	case 2: {
		if (dir==0)
			clr_bit(DDRC, pin);
		else if (dir==1)
			set_bit(DDRC, pin);
		break;
	}
	case 3: {
		if (dir==0)
			clr_bit(DDRD, pin);
		else if (dir==1)
			set_bit(DDRD, pin);
			break;
	}
	}
}

void DIO_vidWritePinValue(u8 port, u8 pin, u8 value)
{
	switch (port)
	{
	case 0: {
		if (value==0)
			clr_bit(PORTA, pin);
		else if (value==1)
			set_bit(PORTA, pin);
		break;
	}
	case 1: {
		if (value==0)
			clr_bit(PORTB, pin);
		else if (value==1)
			set_bit(PORTB, pin);
		break;
	}
	case 2: {
		if (value==0)
			clr_bit(PORTC, pin);
		else if (value==1)
			set_bit(PORTC, pin);
		break;
	}
	case 3: {
		if (value==0)
			clr_bit(PORTD, pin);
		else if (value==1)
			set_bit(PORTD, pin);
		break;
	}
	}
}

u8 DIO_u8ReadPinValue(u8 port, u8 pin)
{
	switch (port)
	{
	case 0:
	return get_bit(PINA, pin);
	break;

	case 1:
		return get_bit(PINB, pin);
		break;

	case 2:
		return get_bit(PINC, pin);
		break;

	case 3:
		return get_bit(PIND, pin);
		break;
	}
}

void DIO_vidWritePortValue(u8 port, u8 value)
{
	switch (port)
	{
	case DIO_PORT_A:
		PORTA= value;
		break;

	case DIO_PORT_B:
		PORTB= value;
		break;

	case DIO_PORT_C:
		PORTC= value;
		break;

	case DIO_PORT_D:
		PORTD= value;
		break;
	}
}

void DIO_vidSetPortDirection(u8 port, u8 dir)
{
	switch (port)
	{
	case 0:
			DDRA=dir;
			break;
	case 1:
			DDRB=dir;
			break;
	case 2:
			DDRC=dir;
			break;
	case 3:
			DDRD=dir;
			break;
	}
}
