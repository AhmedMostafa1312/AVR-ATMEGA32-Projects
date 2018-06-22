/*
 * main.c
 *
 *  Created on: Apr 27, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "LCD_Interface.h"

int main(void)
{

	LCD_vidUARTInitialization();

	UART_vidInitialization();

	while(1)
	{

	}
}

