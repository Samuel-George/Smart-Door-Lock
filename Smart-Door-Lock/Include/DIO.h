/*
 * DIO.h
 *
 *  Created on: Sep 4, 2019
 *      Author: Manal
 */

#ifndef DIO_H_
#define DIO_H_

void DIO_vidSetPinDirection (u8 port, u8 pin, u8 dir);
void DIO_vidWritePinValue (u8 port, u8 pin, u8 value);
u8 DIO_u8ReadPinValue (u8 port, u8 pin);
void DIO_vidSetPortDirection(u8 port, u8 dir);
void DIO_vidWritePortValue(u8 port, u8 value);



#define DIO_PORT_A 0
#define DIO_PORT_B 1
#define DIO_PORT_C 2
#define DIO_PORT_D 3
#define DIO_PIN_0 0
#define DIO_PIN_1 1
#define DIO_PIN_2 2
#define DIO_PIN_3 3
#define DIO_PIN_4 4
#define DIO_PIN_5 5
#define DIO_PIN_6 6
#define DIO_PIN_7 7

#define DIO_PIN_HIGH 1
#define DIO_PORT_HIGH 0xFF
#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT 0
#define DIO_PORT_OUTPUT 0xFF
#define DIO_PORT_INPUT 0
#define DIO_PIN_LOW 0
#define DIO_PORT_LOW 0

#endif /* DIO_H_ */
