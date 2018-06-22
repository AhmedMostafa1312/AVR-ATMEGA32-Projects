/*
 * main.c
 *
 *  Created on: Apr 14, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Keypad_Interface.h"
#include "LCD_Interface.h"

int main(void)
{
	u8 Local_u8KeyValue,temp1,temp2;

	LCD_vidInitialization();
	Keypad_vidInitializeKeys();

	while(1)
	{
		if(Keypad_u8GetKey(&Local_u8KeyValue) == PRESSED)
		{
			LCD_vidWriteCommand(0x01);

			if(Local_u8KeyValue<10)
			{
				LCD_vidWriteData(Local_u8KeyValue+48);
			}
			else if(Local_u8KeyValue>=10)
			{
				temp1=Local_u8KeyValue/10;
				LCD_vidWriteData(temp1+48);
				temp2=Local_u8KeyValue%10;
				LCD_vidWriteData(temp2+48);
			}
			else
			{}

		}
	}
}
