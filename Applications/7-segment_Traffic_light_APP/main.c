/*
 * main.c
 *
 *  Created on: Apr 13, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
//#include "Delay.h"
#include <util/delay.h>

//#define delay 800


int main(void)
{
	LCD_vidInitialization();

	DIO_vidSetHighNibbleDirection(HIGH_NIBBLE_3,OUTPUT);

	/*set high nibble of port C as output for BCD data*/
	DIO_vidSetHighNibbleDirection(HIGH_NIBBLE_2,OUTPUT);
	/*set pin 18 in port C as output to enable 7-segment 1*/
	DIO_vidSetPinDirection(PIN18,OUTPUT);
	/*set pin 19 in port C as output to enable 7-segment 2*/
	DIO_vidSetPinDirection(PIN19,OUTPUT);


	while(1)
	{

		DIO_vidSetPinValue(PIN29,HIGH);
		LCD_vidWriteData('G');
		LCD_vidWriteData('R');
		LCD_vidWriteData('E');
		LCD_vidWriteData('E');
		LCD_vidWriteData('N');
		DIO_vidSetPinValue(PIN28,HIGH);
		_delay_ms(1000);
		//Delay(delay);
		DIO_vidSetPinValue(PIN28,LOW);

		for(s8 i=60;i>=0;i--)
		{
			for(u8 j=0;j<70;j++)
			{
			_delay_ms(1);
			DIO_vidSetPinValue(PIN18,LOW);
			DIO_vidSetPinValue(PIN19,HIGH);
			DIO_vidAssignHighNibbleValue(HIGH_NIBBLE_2,(i/10));
			_delay_ms(1);
			DIO_vidSetPinValue(PIN19,LOW);
			DIO_vidSetPinValue(PIN18,HIGH);
			DIO_vidAssignHighNibbleValue(HIGH_NIBBLE_2,(i%10));
			_delay_ms(1);
			}
		}
		DIO_vidSetPinValue(PIN18,LOW);
		DIO_vidSetPinValue(PIN19,LOW);

		DIO_vidSetPinValue(PIN29,LOW);
		LCD_vidWriteCommand(0x01);
		_delay_ms(2000);

	}
}
