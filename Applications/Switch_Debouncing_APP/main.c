/*
 * main.c
 *
 *  Created on: Apr 13, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Delay.h"

int main(void)
{
	u8 Local_u8DIOGetPinValue=0;

	DIO_vidSetPinDirection(PIN29,OUTPUT);
	DIO_vidSetPinDirection(PIN30,OUTPUT);
	DIO_vidSetPinDirection(PIN31,OUTPUT);
	DIO_vidSetPinDirection(PIN24,INPUT_HIGH_Z);


	while(1)
	{
		/*extacting 5 slices must be all ones to avoid pouncing area*/
		for(u8 index=0;index<5;index++)
		{
			Local_u8DIOGetPinValue=DIO_u8GetPinValue(24);
			if(Local_u8DIOGetPinValue==0)
			{
				break;
			}
			/*useless*/
			else
			{}
			Delay(1);
		}
		if(Local_u8DIOGetPinValue==0)
		{
			/*do no thing*/
		}
		else if(Local_u8DIOGetPinValue==1)
		{
			/*toggle leds*/
			DIO_vidTogglePinValue(PIN29);
			DIO_vidTogglePinValue(PIN30);
			DIO_vidTogglePinValue(PIN31);
			Delay(100);
		}
		/*delay to avoid long press problem*/
		Delay(500);
	}
}
