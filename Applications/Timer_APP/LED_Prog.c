/*
 * LED_Prog.c
 *
 *  Created on: Apr 21, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Timer_Interface.h"
#include "LED_Interface.h"

/*LED Initialization*/
void LED_vidInitialization(void)
{
	DIO_vidSetPinDirection(PIN29,OUTPUT);
	/*for getting the address of an upper layer(HAL)'s function(toggle LED)
	 *for calling it or modify it in lower layer*/
	TIMER0_vidSetCallBack(LED_vidToggleLED);
}

/*toggle LED function*/
void LED_vidToggleLED(void)
{
	DIO_vidTogglePinValue(PIN29);
}
