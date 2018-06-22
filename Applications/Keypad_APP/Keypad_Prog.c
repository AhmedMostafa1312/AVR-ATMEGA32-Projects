/*
 * Keypad_Prog.c
 *
 *  Created on: Apr 14, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Keypad_Cfg.h"
#include "Keypad_Interface.h"

void Keypad_vidInitializeKeys(void)
{
	/*set rows(R1,R2,R3,R4) in port D as output*/
	DIO_vidSetLowNibbleDirection(LOW_NIBBLE_3,OUTPUT);

	/*set columns(C1,C2,C3,C4) in port D as input pull up*/
	DIO_vidSetHighNibbleDirection(HIGH_NIBBLE_3,INPUT_PULL_UP);
}

u8 Keypad_u8GetKey(u8* Copy_pu8KeyValue)
{
	u8 Local_u8KeypadStatus;
	/*Initialize status as not pressed*/
	Local_u8KeypadStatus=NOT_PRESSED;
	/*set R1,R2,R3,R4=1*/
	DIO_vidSetLowNibbleValue(LOW_NIBBLE_3,HIGH);

	/*set R1=0 and R2,R3,R4=1*/
	DIO_vidSetLowNibbleValue(LOW_NIBBLE_3,HIGH);
	DIO_vidSetPinValue(R1,LOW);
	/*check if any change in columns(key is pressed)*/
	if(DIO_u8GetPinValue(C1)==0)
	{
		/*key 1*/
		*Copy_pu8KeyValue=1;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C2)==0)
	{
		/*key 2*/
		*Copy_pu8KeyValue=2;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C3)==0)
	{
		/*key 3*/
		*Copy_pu8KeyValue=3;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C4)==0)
	{
		/*key 4*/
		*Copy_pu8KeyValue=4;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	/*useless*/
	else
	{}

	/*set R2=0 and R1,R3,R4=1*/
	DIO_vidSetLowNibbleValue(LOW_NIBBLE_3,HIGH);
	DIO_vidSetPinValue(R2,LOW);
	/*check if any change in columns(key is pressed)*/
	if(DIO_u8GetPinValue(C1)==0)
	{
		/*key 5*/
		*Copy_pu8KeyValue=5;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C2)==0)
	{
		/*key 6*/
		*Copy_pu8KeyValue=6;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C3)==0)
	{
		/*key 7*/
		*Copy_pu8KeyValue=7;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C4)==0)
	{
		/*key 8*/
		*Copy_pu8KeyValue=8;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	/*useless*/
	else
	{}

	/*set R3=0 and R1,R2,R4=1*/
	DIO_vidSetLowNibbleValue(LOW_NIBBLE_3,HIGH);
	DIO_vidSetPinValue(R3,LOW);
	/*check if any change in columns(key is pressed)*/
	if(DIO_u8GetPinValue(C1)==0)
	{
		/*key 9*/
		*Copy_pu8KeyValue=9;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C2)==0)
	{
		/*key 10*/
		*Copy_pu8KeyValue=10;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C3)==0)
	{
		/*key 11*/
		*Copy_pu8KeyValue=11;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C4)==0)
	{
		/*key 12*/
		*Copy_pu8KeyValue=12;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	/*useless*/
	else
	{}

	/*set R4=0 and R1,R2,R3=1*/
	DIO_vidSetLowNibbleValue(LOW_NIBBLE_3,HIGH);
	DIO_vidSetPinValue(R4,LOW);
	/*check if any change in columns(key is pressed)*/
	if(DIO_u8GetPinValue(C1)==0)
	{
		/*key 13*/
		*Copy_pu8KeyValue=13;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C2)==0)
	{
		/*key 14*/
		*Copy_pu8KeyValue=14;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C3)==0)
	{
		/*key 15*/
		*Copy_pu8KeyValue=15;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	else if(DIO_u8GetPinValue(C4)==0)
	{
		/*key 16*/
		*Copy_pu8KeyValue=16;
		/*status pressed*/
		Local_u8KeypadStatus=PRESSED;
	}
	/*useless*/
	else
	{}

	/*return status*/
	return Local_u8KeypadStatus;

}

