/*
 * main.c
 *
 *  Created on: Apr 22, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"


int main(void)
{
	DIO_vidSetPortDirection(PORT_D,OUTPUT);
	//DIO_vidSetLowNibbleDirection(LOW_NIBBLE_3,OUTPUT);
	/*DIO_vidSetPinDirection(PIN24,OUTPUT);
		DIO_vidSetPinDirection(PIN25,OUTPUT);
	DIO_vidSetPinDirection(PIN26,OUTPUT);*/

	while(1)
	{
		DIO_vidAssignPortValue(PORT_D,0);
		//DIO_vidAssignPortValue(PORT_D,1);
		//DIO_vidAssignPortValue(PORT_D,3);

		//DIO_vidAssignPortValue(PORT_D,5);


		//DIO_vidAssignPortValue(PORT_D,7);

		//DIO_vidAssignPortValue(PORT_D,10);
		//DIO_vidAssignPortValue(PORT_D,13);

		DIO_vidAssignPortValue(PORT_D,15);


		//DIO_vidAssignPortValue(LOW_NIBBLE_3,13);
		//DIO_vidAssignPortValue(LOW_NIBBLE_3,10);

		//DIO_vidAssignPortValue(LOW_NIBBLE_3,7);
		//DIO_vidAssignPortValue(LOW_NIBBLE_3,5);
		//DIO_vidAssignPortValue(LOW_NIBBLE_3,3);
		//DIO_vidAssignPortValue(LOW_NIBBLE_3,1);


		DIO_vidAssignLowNibbleValue(LOW_NIBBLE_3,0);


	}
}
