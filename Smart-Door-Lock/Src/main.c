/*
 * main.c
 *
 *  Created on: Oct 21, 2019
 *      Author: Samuel George
 */
#include "utils.h"
#include "register.h"
#include "std_types.h"
#include "DIO.h"
#include "UART.h"
#include <avr/delay.h>


void main (void)


{


	DIO_vidSetPortDirection(DIO_PORT_D,DIO_PORT_OUTPUT);
	USART_voidInit();

	u8 UserName_location;
	char Receiving_Username[100];
	char Receiving_Password[100];
	char Receiving_Exit[100];

	char UserName[10][6]={"imt1","imt2","imt3","imt4","imt5","imt6","imt7","imt8","imt9","imt10"};
	char Password[10][4]={"01","02","03","04","05","06","07","08","09","010"};

	while(1)
	{
	u8 Found_flag=0;

	USART_voidSendString("\n\n Welcome \n");
	USART_voidSendString("\n Please Enter  ");


	for(u8 y=0;y<=2;y++)
	{

		USART_voidSendString("\n Username : ");
		
		///---------- Receiving Username ---------///

    	u8 *p;
		p=USART_voidRecieveString();
		u8 k;
		for( k=0; (*p!='\r') ;k++)
		{
			Receiving_Username[k]=*p;
			p++;
		}
		Receiving_Username[k]='\0';

		Display(Receiving_Username);

		///---------- Check the Username ---------///

		for (u8 i=0;i<=9;i++)
		{
			if( USART_u8CompareArray(Receiving_Username,UserName[i]))
			{
				Found_flag=1;
				UserName_location=i;
				break;
			}
		}

		if ( Found_flag == 0 )
		{
			if(y<2) USART_voidSendString("\n Invalid Username Please Try again ");
			continue;
		}
		else break;

	}



	if( Found_flag == 1)
	{

		USART_voidSendString("\n\n Please Enter ");

		///---------- Receiving Password ---------///
		for(u8 y=0;y<=2;y++)
		{
			USART_voidSendString("\n Password : ");

			u8 *p;
			p=USART_voidRecieveString();
			u8 k;
			for(k=0; (*p!='\r') ;k++)
			{
				Receiving_Password[k]=*p;
				p++;
			}
			Receiving_Password[k]='\0';

			Display(Receiving_Password);

			///---------- Check the Password ---------///

			if( USART_u8CompareArray(Receiving_Password,Password[UserName_location]))
			{
				//----------- Open the Door------//
				DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_7,DIO_PIN_HIGH);
				USART_voidSendString("\n\n Welcome at IMT Home :) ");

				while(1)
				{
					USART_voidSendString("\n\n To Lock the Door enter ( 0 ) : ");
					u8 *r;
					r=USART_voidRecieveString();
					u8 k;
					for( k=0; (*r!='\r') ;k++)
					{
						Receiving_Exit[k]=*r;
						r++;
					}
					Receiving_Exit[k]='\0';
					Display(Receiving_Exit);
					if(Receiving_Exit[1]=='0' && Receiving_Exit[2]=='\0') break;
					else USART_voidSendString("\n Incorrect try again ");
				}
				DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_7,DIO_PIN_LOW);
				break;
			}
			else
			{
				if(y<2)
				{
					USART_voidSendString("\n Invalid Password Please try again : ");
					continue;
				}

				//--------------Wrong Password 3 time -----------//

				else
				{
					USART_voidSendString("\n\n !!!! Wrong Entry !!!! \n ");
					for(u8 a=0;a<=7;a++)
					{
						DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_6,DIO_PIN_HIGH);
						DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_5,DIO_PIN_HIGH);
						DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_4,DIO_PIN_HIGH);
						_delay_ms(300);
						DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_6,DIO_PIN_LOW);
						DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_5,DIO_PIN_LOW);
						DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_4,DIO_PIN_LOW);
						_delay_ms(300);
					}

				}
			}

		}

	}

	//---------------Wrong Username 3 times----------///

	else
	{
		USART_voidSendString("\n\n !!!! Wrong Entry !!!! \n ");
		for(u8 a=0;a<=7;a++)
		{
			DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_6,DIO_PIN_HIGH);
			DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_5,DIO_PIN_HIGH);
			DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_4,DIO_PIN_HIGH);
			_delay_ms(300);
			DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_6,DIO_PIN_LOW);
			DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_5,DIO_PIN_LOW);
			DIO_vidWritePinValue(DIO_PORT_D,DIO_PIN_4,DIO_PIN_LOW);
			_delay_ms(300);
		}
	}

	}
}


