/*
 * main.c
 *
 *  Created on: Apr 21, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Timer_Interface.h"
#include "LED_Interface.h"
#include "util/delay.h"

#define delay 260

int main (void)
{
	/*for OC0 pin*/
	DIO_vidTimer0PinConfigurations();

	/*
	LED_vidInitialization();

	TIMER0_vidOverFlowModeInitialization(1);
	TIMER0_vidCTCModeInitialization(1,100);
	TIMER0_vidFastPWMModeInitialization(80);
	TIMER0_vidPhaseCorrectPWMModeInitialization(80);

	while(1)
	{

	}
	*/

	volatile static u8 value=0;

	while(1)
	{
		TIMER0_vidFastPWMModeInitialization(value);
		_delay_ms(delay);
		value++;

		if(value==100)
		{
			_delay_ms(delay);

			for(u8 i=100;i>=1;i--)
			{
				TIMER0_vidFastPWMModeInitialization(value);
				_delay_ms(delay);
				value--;
			}

			_delay_ms(delay);
		}
	}
}

