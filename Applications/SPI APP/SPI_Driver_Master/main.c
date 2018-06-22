/*
 * main.c
 *
 *  Created on: Apr 27, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"

int main(void)
{
	DIO_vidSPIMasterPinConfigurations();
	DIO_vidSetPinDirection(PIN29,OUTPUT);

	SPI_vidInitialization();

	while(1)
	{
		if(SPI_u8TransmitReceive(0x55)==0x55)
		{
			DIO_vidSetPinValue(PIN29,HIGH);
		}
		else
		{

		}
	}
}

