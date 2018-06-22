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
	u8 Local_u8Digitaltemp1,Local_u8Digitaltemp2,Local_u8Digitaltemp3,Local_u8Digitaltemp4=0;
	u8 Local_u8Analogtemp1,Local_u8Analogtemp2,Local_u8Analogtemp3,Local_u8Analogtemp4=0;

	LCD_vidInitialization();

	ExtINT_vidInitialization();

	ADC_vidInitialization();

	while(1)
	{
		/*get digital value*/
		Local_u16ADCDigitalvalue=ADC_u16GetDigitalValue();
		/*analog value = digital value x step*/
		/*multiply by 1000 for floating numbers , ex. ((1023*5)/1024)*1000=4995*/
		Local_u16ADCAnalogvalue=((Local_u16ADCDigitalvalue*5.0)/1024)*1000;

		/*write digital value in line 0 in LCD*/
		LCD_vidWriteCommand(0x80);

		LCD_vidWriteData('D');
		LCD_vidWriteData('i');
		LCD_vidWriteData('g');
		LCD_vidWriteData('i');
		LCD_vidWriteData('t');
		LCD_vidWriteData('a');
		LCD_vidWriteData('l');
		LCD_vidWriteData(61);

		Local_u8Digitaltemp1=Local_u16ADCDigitalvalue/1000;
		LCD_vidWriteData(Local_u8Digitaltemp1+48);
		Local_u8Digitaltemp2=(Local_u16ADCDigitalvalue%1000)/100;
		LCD_vidWriteData(Local_u8Digitaltemp2+48);
		Local_u8Digitaltemp3=((Local_u16ADCDigitalvalue%1000)%100)/10;
		LCD_vidWriteData(Local_u8Digitaltemp3+48);
		Local_u8Digitaltemp4=((Local_u16ADCDigitalvalue%1000)%100)%10;
		LCD_vidWriteData(Local_u8Digitaltemp4+48);

		/*write analog value in line 1 in LCD*/
		LCD_vidWriteCommand(0xc0);

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


