/*
 * main.c
 *
 *  Created on: Apr 29, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "I2C_Interface.h"
#include "DIO_Interface.h"

int main(void)
{
	I2C_vidInitialization();

	while(1)
	{
		I2C_vidMasterStartCondition();

		I2C_vidWrite(0xA0);

		I2C_vidWrite(0xD0);

		I2C_vidMasterStopCondition();

	}
	return 0;
}
