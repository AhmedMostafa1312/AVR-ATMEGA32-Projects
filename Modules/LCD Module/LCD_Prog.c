/*
 * LCD_Prog.c
 *
 *  Created on: Apr 7, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Delay.h"
#include "LCD_Interface.h"
#include "LCD_Cfg.h"

#if(BIT_MODE==4) /*switch between two modes 4 and 8 bit*/

/*--------------------------------------------------*
 *****                4 Bit Mode                *****
 *--------------------------------------------------*/

/*LCD initialization function*/
void LCD_vidInitialization(void)
{
	/*delay > 30ms*/
	Delay(50);
	/*send command 0x02 then 0x08 for N=1 and F=0
	N = 0 : 1 - line display
	F = 0 : 5 x 7 dot character font*/
	LCD_vidWriteCommand(0x02);
	LCD_vidWriteCommand(0x28);
	/*delay > 39us*/
	Delay(10);
	/*send command 0x0c for D=1 , C=0 and B=0
	D = 0 : Display OFF
	C = 0 : Cursor OFF
	B = 0 : Blink OFF*/
	LCD_vidWriteCommand(0x0c);
	/*delay > 39us*/
	Delay(10);
	/*send command 0x01 for clearing LCD*/
	LCD_vidWriteCommand(0x01);
	/*delay > 1.53ms*/
	Delay(5);
}

/*LCD Write command function*/
void LCD_vidWriteCommand(u8 Copy_u8Command)
{
	/*set pins 1,2 and 3 in PORTB as output for RS , R/W and E*/
	DIO_vidSetPinDirection(PIN9,OUTPUT);
	DIO_vidSetPinDirection(PIN10,OUTPUT);
	DIO_vidSetPinDirection(PIN11,OUTPUT);
	/*set last 4 bits in PORTA as output for command*/
	DIO_vidSetHighNibbleDirection(HIGH_NIBBLE_0,OUTPUT);
	/*RS=0 for command mode , RS=1 for data mode*/
	DIO_vidSetPinValue(PIN9,LOW);
	/*R/W=0 for write , R/W=1 for read*/
	DIO_vidSetPinValue(PIN10,LOW);
	/*assign high nibble of command to high nibble of PORTA*/
	DIO_vidAssignHighNibbleValue(HIGH_NIBBLE_0,GET_HIGH_NIBBLE(Copy_u8Command));
	/*E=1 to enable*/
	DIO_vidSetPinValue(PIN11,HIGH);
	/*delay*/
	Delay(50);
	/*E=0 to disable*/
	DIO_vidSetPinValue(PIN11,LOW);
	/*assign low nibble of command to high nibble of PORTA*/
	DIO_vidAssignHighNibbleValue(HIGH_NIBBLE_0,GET_LOW_NIBBLE(Copy_u8Command));
	/*E=1 to enable*/
	DIO_vidSetPinValue(PIN11,HIGH);
	/*delay*/
	Delay(50);
	/*E=0 to disable*/
	DIO_vidSetPinValue(PIN11,LOW);
	/*delay*/
	Delay(50);
}

/*LCD Write data function*/
void LCD_vidWriteData(u8 Copy_u8Data)
{
	/*set pins 1,2 and 3 in PORTB as output for RS , R/W and E*/
	DIO_vidSetPinDirection(PIN9,OUTPUT);
	DIO_vidSetPinDirection(PIN10,OUTPUT);
	DIO_vidSetPinDirection(PIN11,OUTPUT);
	/*set last 4 bits in PORTA as output for data*/
	DIO_vidSetHighNibbleDirection(HIGH_NIBBLE_0,OUTPUT);
	/*RS=1 for data mode , RS=0 for command mode*/
	DIO_vidSetPinValue(PIN9,HIGH);
	/*R/W=0 for write , R/W=1 for read*/
	DIO_vidSetPinValue(PIN10,LOW);
	/*assign high nibble of data to high nibble of PORTA*/
	DIO_vidAssignHighNibbleValue(HIGH_NIBBLE_0,GET_HIGH_NIBBLE(Copy_u8Data));
	/*E=1 to enable*/
	DIO_vidSetPinValue(PIN11,HIGH);
	/*delay*/
	Delay(50);
	/*E=0 to disable*/
	DIO_vidSetPinValue(PIN11,LOW);
	/*assign high nibble of data to high nibble of PORTA*/
	DIO_vidAssignHighNibbleValue(HIGH_NIBBLE_0,GET_LOW_NIBBLE(Copy_u8Data));
	/*E=1 to enable*/
	DIO_vidSetPinValue(PIN11,HIGH);
	/*delay*/
	Delay(50);
	/*E=0 to disable*/
	DIO_vidSetPinValue(PIN11,LOW);
	/*delay*/
	Delay(50);
}

#elif (BIT_MODE==8) /*switch between two modes 4 and 8 bit*/

/*--------------------------------------------------*
 *****                8 Bit Mode                *****
 *--------------------------------------------------*/

/*LCD initialization function*/
void LCD_vidInitialization(void)
{
	/*delay > 30ms*/
	Delay(50);
	/*send command 0x38 for N=1 and F=0
	N = 0 : 1 - line display
	F = 0 : 5 x 7 dot character font*/
	LCD_vidWriteCommand(0x38);
	/*delay > 39us*/
	Delay(10);
	/*send command 0x0c for D=1 , C=0 and B=0
	D = 0 : Display OFF
	C = 0 : Cursor OFF
	B = 0 : Blink OFF*/
	LCD_vidWriteCommand(0x0c);
	/*delay > 39us*/
	Delay(10);
	/*send command 0x01 for clearing LCD*/
	LCD_vidWriteCommand(0x01);
	/*delay > 1.53ms*/
	Delay(5);
}

/*LCD Write command function*/
void LCD_vidWriteCommand(u8 Copy_u8Command)
{
	/*set pins 1,2 and 3 in PORTB as output for RS , R/W and E*/
	DIO_vidSetPinDirection(PIN9,OUTPUT);
	DIO_vidSetPinDirection(PIN10,OUTPUT);
	DIO_vidSetPinDirection(PIN11,OUTPUT);
	/*set PORTA as output*/
	DIO_vidSetPortDirection(PORT_A,OUTPUT);
	/*RS=0 for command mode , RS=1 for data mode*/
	DIO_vidSetPinValue(PIN9,LOW);
	/*R/W=0 for write , R/W=1 for read*/
	DIO_vidSetPinValue(PIN10,LOW);
	/*assign command to PORTA*/
	DIO_vidAssignPortValue(PORT_A,Copy_u8Command);
	/*E=1 to enable*/
	DIO_vidSetPinValue(PIN11,HIGH);
	/*delay*/
	Delay(50);
	/*E=0 to disable*/
	DIO_vidSetPinValue(PIN11,LOW);
	/*delay*/
	Delay(50);
}

/*LCD Write data function*/
void LCD_vidWriteData(u8 Copy_u8Data)
{
	/*set pins 1,2 and 3 in PORTB as output for RS , R/W and E*/
	DIO_vidSetPinDirection(PIN9,OUTPUT);
	DIO_vidSetPinDirection(PIN10,OUTPUT);
	DIO_vidSetPinDirection(PIN11,OUTPUT);
	/*set PORTA as output*/
	DIO_vidSetPortDirection(PORT_A,OUTPUT);
	/*RS=1 for data mode , RS=0 for command mode*/
	DIO_vidSetPinValue(PIN9,HIGH);
	/*R/W=0 for write , R/W=1 for read*/
	DIO_vidSetPinValue(PIN10,LOW);
	/*assign data to PORTA*/
	DIO_vidAssignPortValue(PORT_A,Copy_u8Data);
	/*E=1 to enable*/
	DIO_vidSetPinValue(PIN11,HIGH);
	/*delay*/
	Delay(50);
	/*E=0 to disable*/
	DIO_vidSetPinValue(PIN11,LOW);
	/*delay*/
	Delay(50);
}

#endif
