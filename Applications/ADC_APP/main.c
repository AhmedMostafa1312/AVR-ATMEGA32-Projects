/*
 * main.c
 *
 *  Created on: Apr 20, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "ADC_Interface.h"
#include "ExtINT_Interface.h"

int main(void)
{
	u16 Local_u16ADCDigitalvalue,Local_u16ADCAnalogvalue;
	u8 Local_u8Analogtemp1,Local_u8Analogtemp2,Local_u8Analogtemp3,Local_u8Analogtemp4=0;

	LCD_vidInitialization();

	ExtINT_vidInitialization();

	ADC_vidInitialization();

	DIO_vidSetPinDirection(PIN27,OUTPUT);
	DIO_vidSetHighNibbleDirection(HIGH_NIBBLE_3,OUTPUT);

	while(1)
	{
		/*get digital value*/
		Local_u16ADCDigitalvalue=ADC_u16GetDigitalValue();
		/*analog value = digital value x step*/
		/*multiply by 1000 for floating numbers , ex. ((1023*5)/1024)*1000=4995*/
		Local_u16ADCAnalogvalue=((Local_u16ADCDigitalvalue*5.0)/1024)*1000;

		/*0-2 LED1 on*/
		if(Local_u16ADCAnalogvalue>=0&&Local_u16ADCAnalogvalue<=2000)
		{
			/*0-2 LED1 on*/
			DIO_vidSetPinValue(PIN29,HIGH);

			DIO_vidSetPinValue(PIN30,LOW);
			DIO_vidSetPinValue(PIN31,LOW);
			DIO_vidSetPinValue(PIN28,LOW);
			DIO_vidSetPinValue(PIN27,LOW);

			/*write analog value in line 0 in LCD*/
			LCD_vidWriteCommand(0x80);

			LCD_vidWriteData('A');
			LCD_vidWriteData('n');
			LCD_vidWriteData('a');
			LCD_vidWriteData('l');
			LCD_vidWriteData('o');
			LCD_vidWriteData('g');
			LCD_vidWriteData(61);

			Local_u8Analogtemp1=Local_u16ADCAnalogvalue/1000;
			LCD_vidWriteData(Local_u8Analogtemp1+48);
			LCD_vidWriteData(46);
			Local_u8Analogtemp2=(Local_u16ADCAnalogvalue%1000)/100;
			LCD_vidWriteData(Local_u8Analogtemp2+48);
			Local_u8Analogtemp3=((Local_u16ADCAnalogvalue%1000)%100)/10;
			LCD_vidWriteData(Local_u8Analogtemp3+48);
			Local_u8Analogtemp4=((Local_u16ADCAnalogvalue%1000)%100)%10;
			LCD_vidWriteData(Local_u8Analogtemp4+48);

			LCD_vidWriteData(' ');
			LCD_vidWriteData('v');
		}

		/*2-3 LED2 on & relay on*/
		else if(Local_u16ADCAnalogvalue>2000&&Local_u16ADCAnalogvalue<=3000)
		{
			/*2-3 LED2 on*/
			DIO_vidSetPinValue(PIN30,HIGH);

			/*2-3 relay on*/
			DIO_vidTogglePinValue(PIN27);

			DIO_vidSetPinValue(PIN29,LOW);
			DIO_vidSetPinValue(PIN31,LOW);
			DIO_vidSetPinValue(PIN28,LOW);

			/*write analog value in line 0 in LCD*/
			LCD_vidWriteCommand(0x80);

			LCD_vidWriteData('A');
			LCD_vidWriteData('n');
			LCD_vidWriteData('a');
			LCD_vidWriteData('l');
			LCD_vidWriteData('o');
			LCD_vidWriteData('g');
			LCD_vidWriteData(61);

			Local_u8Analogtemp1=Local_u16ADCAnalogvalue/1000;
			LCD_vidWriteData(Local_u8Analogtemp1+48);
			LCD_vidWriteData(46);
			Local_u8Analogtemp2=(Local_u16ADCAnalogvalue%1000)/100;
			LCD_vidWriteData(Local_u8Analogtemp2+48);
			Local_u8Analogtemp3=((Local_u16ADCAnalogvalue%1000)%100)/10;
			LCD_vidWriteData(Local_u8Analogtemp3+48);
			Local_u8Analogtemp4=((Local_u16ADCAnalogvalue%1000)%100)%10;
			LCD_vidWriteData(Local_u8Analogtemp4+48);

			LCD_vidWriteData(' ');
			LCD_vidWriteData('v');
		}

		/*3-5 LED3 on & relay on & buzzer on*/
		else if(Local_u16ADCAnalogvalue>3000&&Local_u16ADCAnalogvalue<=5000)
		{
			/*3-5 LED3 on*/
			DIO_vidSetPinValue(PIN31,HIGH);

			/*3-5 relay on*/
			DIO_vidTogglePinValue(PIN27);

			/*3-5 buzzer on*/
			DIO_vidSetPinValue(PIN28,HIGH);

			DIO_vidSetPinValue(PIN29,LOW);
			DIO_vidSetPinValue(PIN30,LOW);

			/*write analog value in line 0 in LCD*/
			LCD_vidWriteCommand(0x80);

			LCD_vidWriteData('A');
			LCD_vidWriteData('n');
			LCD_vidWriteData('a');
			LCD_vidWriteData('l');
			LCD_vidWriteData('o');
			LCD_vidWriteData('g');
			LCD_vidWriteData(61);

			Local_u8Analogtemp1=Local_u16ADCAnalogvalue/1000;
			LCD_vidWriteData(Local_u8Analogtemp1+48);
			LCD_vidWriteData(46);
			Local_u8Analogtemp2=(Local_u16ADCAnalogvalue%1000)/100;
			LCD_vidWriteData(Local_u8Analogtemp2+48);
			Local_u8Analogtemp3=((Local_u16ADCAnalogvalue%1000)%100)/10;
			LCD_vidWriteData(Local_u8Analogtemp3+48);
			Local_u8Analogtemp4=((Local_u16ADCAnalogvalue%1000)%100)%10;
			LCD_vidWriteData(Local_u8Analogtemp4+48);

			LCD_vidWriteData(' ');
			LCD_vidWriteData('v');
		}
	}
}


