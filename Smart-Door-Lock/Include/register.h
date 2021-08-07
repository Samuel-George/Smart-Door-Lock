/*
 * register.h
 *
 *  Created on: Sep 4, 2019
 *      Author: Manal
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#define DDRA (*(volatile u8*)0x3A)
#define PINA (*(volatile u8*)0x39)
#define PORTA (*(volatile u8*)0x3B)

#define DDRB (*(volatile u8*)0x37)
#define PINB (*(volatile u8*)0x36)
#define PORTB (*(volatile u8*)0x38)

#define DDRC (*(volatile u8*)0x34)
#define PINC (*(volatile u8*)0x33)
#define PORTC (*(volatile u8*)0x35)

#define DDRD (*(volatile u8*)0x31)
#define PIND (*(volatile u8*)0x30)
#define PORTD (*(volatile u8*)0x32)

// Define registers for interrupt

#define MCUCR (*(volatile u8*)0x55)
#define SREG  (*(volatile u8*)0x5F)
#define GICR  (*(volatile u8*)0x5B)

// Define registers for ADC

#define ADMUX (*(volatile u8*)0x27)
#define ADCSRA (*(volatile u8*)0x26)
#define ADCH (*(volatile u8*)0x25)
#define ADCL (*(volatile u8*)0x24)
#define SFIOR (*(volatile u8*)0x50)
#define ADC (*(volatile u16*)0x24)

//Define registers for Timer

#define TCCR0 (*(volatile u8*)0x53)
#define TIMSK (*(volatile u8*)0x59)
#define OCR0 (*(volatile u8*)0x5C)


//Define registers for UART

#define UDR (*(volatile u8*)0x2C)
#define UCSRA (*(volatile u8*)0x2B)
#define UCSRB (*(volatile u8*)0x2A)
#define UCSRC (*(volatile u8*)0x40)
#define UBRRL (*(volatile u8*)0x29)


#endif /* REGISTER_H_ */
