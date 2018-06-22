/*
 * main.c
 *
 *  Created on: Apr 7, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Delay.h"
#include "LCD_Interface.h"



int main(void)
{	
	/*for LEDS*/
	DIO_vidSetHighNibbleDirection(HIGH_NIBBLE_3,OUTPUT);

    LCD_vidInitialization();
    /*Initialization done*/
    DIO_vidSetPinValue(PIN29,HIGH);
    /*0x80 for line 0 and 0xc0 for line 1*/
    LCD_vidWriteCommand(0x80);
    /*Commands done*/
    DIO_vidSetPinValue(PIN30,HIGH);

    LCD_vidWriteData('A');
    LCD_vidWriteData('H');
    LCD_vidWriteData('M');
    LCD_vidWriteData('E');
    LCD_vidWriteData('D');

    /*Data done*/
    DIO_vidSetPinValue(PIN31,HIGH);
    DIO_vidSetPinValue(PIN28,HIGH);
    Delay(1000);
    DIO_vidSetPinValue(PIN28,LOW);
    Delay(5000);
    LCD_vidWriteCommand(0x01);
	while(1)
	{

	}
}



