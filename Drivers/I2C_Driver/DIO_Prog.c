/*
 * DIO_Prog.c
 *
 *  Created on: Apr 13, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Cfg.h"
#include "DIO_Interface.h"

/*global pointers for the registers*/
u8* Global_pu8DIODDR=0;
u8* Global_pu8DIOPIN=0;
u8* Global_pu8DIOPORT=0;

/*Port Identification from pin number or nibbles number or ports ids*/
void DIO_vidPortIdentification(u8 Copy_u8PinNibblePortNumber)
{
	u8 Local_u8DIOPortId;
	Local_u8DIOPortId=Copy_u8PinNibblePortNumber/8;

	switch(Local_u8DIOPortId)
	{
		/*port A*/
		case 0 : 
		{
			Global_pu8DIODDR=(u8*)&DDRA;
			Global_pu8DIOPIN=(u8*)&PINA;
			Global_pu8DIOPORT=(u8*)&PORTA;
			break;

		}
		/*port B*/
		case 1 : 
		{
			Global_pu8DIODDR=(u8*)&DDRB;
			Global_pu8DIOPIN=(u8*)&PINB;
			Global_pu8DIOPORT=(u8*)&PORTB;
			break;

		}
		/*port C*/
		case 2 : 
		{
			Global_pu8DIODDR=(u8*)&DDRC;
			Global_pu8DIOPIN=(u8*)&PINC;
			Global_pu8DIOPORT=(u8*)&PORTC;
			break;

		}
		/*port D*/
		case 3 : 
		{
			Global_pu8DIODDR=(u8*)&DDRD;
			Global_pu8DIOPIN=(u8*)&PIND;
			Global_pu8DIOPORT=(u8*)&PORTD;
			break;

		}
		/*useless*/
		default : 
		{}
	}
}

/*Set Pin Direction*/
void DIO_vidSetPinDirection(u8 Copy_u8PinNumber,u8 copy_u8PinDirection)
{
	u8 Local_u8DIOPinNumber;
	Local_u8DIOPinNumber=Copy_u8PinNumber%8;

	/*Port Identification from pin number*/
	DIO_vidPortIdentification(Copy_u8PinNumber);

	switch(copy_u8PinDirection)
	{
		/*output*/
		case OUTPUT :
		{
			SET_BIT(DDR,Local_u8DIOPinNumber);
			break;
		}
		/*input with pull up*/
		case INPUT_PULL_UP :
		{
			CLEAR_BIT(DDR,Local_u8DIOPinNumber);
			SET_BIT(PORT,Local_u8DIOPinNumber);
			break;
		}
		/*input with high impedance*/
		case INPUT_HIGH_Z :
		{
			CLEAR_BIT(DDR,Local_u8DIOPinNumber);
			CLEAR_BIT(PORT,Local_u8DIOPinNumber);
			break;
		}
		/*useless*/
		default : 
		{}
	}
}

/*Set Low Nibble Direction*/
void DIO_vidSetLowNibbleDirection(u8 Copy_u8LowNibbleNumber,u8 copy_u8LowNibbleDirection)
{
	/*Port Identification from Low Nibble Number*/
	DIO_vidPortIdentification(Copy_u8LowNibbleNumber);

	switch(copy_u8LowNibbleDirection)
	{
		/*output*/
		case OUTPUT :
		{
			SET_LOW_NIBBLE(DDR);
			break;
		}
		/*input with pull up*/
		case INPUT_PULL_UP :
		{
			CLEAR_LOW_NIBBLE(DDR);
			SET_LOW_NIBBLE(PORT);
			break;
		}
		/*input with high impedance*/
		case INPUT_HIGH_Z :
		{
			CLEAR_LOW_NIBBLE(DDR);
			CLEAR_LOW_NIBBLE(PORT);
			break;
		}
		/*useless*/
		default : 
		{}
	}
}

/*Set High Nibble Direction*/
void DIO_vidSetHighNibbleDirection(u8 Copy_u8HighNibbleNumber,u8 copy_u8HighNibbleDirection)
{
	/*Port Identification from High Nibble Number*/
	DIO_vidPortIdentification(Copy_u8HighNibbleNumber);

	switch(copy_u8HighNibbleDirection)
	{
		/*output*/
		case OUTPUT :
		{
			SET_HIGH_NIBBLE(DDR);
			break;
		}
		/*input with pull up*/
		case INPUT_PULL_UP :
		{
			CLEAR_HIGH_NIBBLE(DDR);
			SET_HIGH_NIBBLE(PORT);
			break;
		}
		/*input with high impedance*/
		case INPUT_HIGH_Z :
		{
			CLEAR_HIGH_NIBBLE(DDR);
			CLEAR_HIGH_NIBBLE(PORT);
			break;
		}
		/*useless*/
		default : 
		{}
	}
}

/*Set Port Direction*/
void DIO_vidSetPortDirection(u8 Copy_u8PortId,u8 copy_u8PortDirection)
{
	/*Port Identification from Port Id*/
	DIO_vidPortIdentification(Copy_u8PortId);

	switch(copy_u8PortDirection)
	{
		/*output*/
		case OUTPUT :
		{
			SET_PORT(DDR);
			break;
		}
		/*input with pull up*/
		case INPUT_PULL_UP :
		{
			CLEAR_PORT(DDR);
			SET_PORT(PORT);
			break;
		}
		/*input with high impedance*/
		case INPUT_HIGH_Z :
		{
			CLEAR_PORT(DDR);
			CLEAR_PORT(PORT);
			break;
		}
		/*useless*/
		default : 
		{}
	}
}

/*Set Pin Value in case of output*/
void DIO_vidSetPinValue(u8 Copy_u8PinNumber,u8 copy_u8PinValue)
{
	u8 Local_u8DIOPinNumber;
	Local_u8DIOPinNumber=Copy_u8PinNumber%8;

	/*Port Identification from pin number*/
	DIO_vidPortIdentification(Copy_u8PinNumber);

	/*low - 0v*/
	if(copy_u8PinValue==LOW)
	{
		CLEAR_BIT(PORT,Local_u8DIOPinNumber);
	}
	/*high - 5v*/
	else if(copy_u8PinValue==HIGH)
	{
		SET_BIT(PORT,Local_u8DIOPinNumber);
	}
	/*useless*/
	else
	{}
}

/*Toggle Pin Value in case of output*/
void DIO_vidTogglePinValue(u8 Copy_u8PinNumber)
{
	u8 Local_u8DIOPinNumber;
	Local_u8DIOPinNumber=Copy_u8PinNumber%8;

	/*Port Identification from pin number*/
	DIO_vidPortIdentification(Copy_u8PinNumber);

	/*Toggle Pin Value*/
	TOGGLE_BIT(PORT,Local_u8DIOPinNumber);
}

/*Set Low Nibble Value in case of output*/
void DIO_vidSetLowNibbleValue(u8 Copy_u8LowNibbleNumber,u8 copy_u8LowNibblevalue)
{
	/*Port Identification from Low Nibble Number*/
	DIO_vidPortIdentification(Copy_u8LowNibbleNumber);

	/*low - 0v*/
	if(copy_u8LowNibblevalue==LOW)
	{
		CLEAR_LOW_NIBBLE(PORT);
	}
	/*high - 5v*/
	else if(copy_u8LowNibblevalue==HIGH)
	{
		SET_LOW_NIBBLE(PORT);
	}
	/*useless*/
	else
	{}
}

/*Toggle Low Nibble Value in case of output*/
void DIO_vidToggleLowNibbleValue(u8 Copy_u8LowNibbleNumber)
{
	/*Port Identification from Low Nibble Number*/
	DIO_vidPortIdentification(Copy_u8LowNibbleNumber);

	/*Toggle Low Nibble Value*/
	TOGGLE_LOW_NIBBLE(PORT);
}

/*Assign Low Nibble Value in case of output*/
void DIO_vidAssignLowNibbleValue(u8 Copy_u8LowNibbleNumber,u8 Copy_u8LowNibbleValue)
{
	/*Port Identification from Low Nibble Number*/
	DIO_vidPortIdentification(Copy_u8LowNibbleNumber);

	/*Assign Low Nibble Value*/
	ASSIGN_LOW_NIBBLE(PORT,Copy_u8LowNibbleValue);
}

/*Set High Nibble Value in case of output*/
void DIO_vidSetHighNibbleValue(u8 Copy_u8HighNibbleNumber,u8 copy_u8HighNibblevalue)
{
	/*Port Identification from High Nibble Number*/
	DIO_vidPortIdentification(Copy_u8HighNibbleNumber);

	/*low - 0v*/
	if(copy_u8HighNibblevalue==LOW)
	{
		CLEAR_HIGH_NIBBLE(PORT);
	}
	/*high - 5v*/
	else if(copy_u8HighNibblevalue==HIGH)
	{
		SET_HIGH_NIBBLE(PORT);
	}
	/*useless*/
	else
	{}
}

/*Toggle High Nibble Value in case of output*/
void DIO_vidToggleHighNibbleValue(u8 Copy_u8HighNibbleNumber)
{
	/*Port Identification from High Nibble Number*/
	DIO_vidPortIdentification(Copy_u8HighNibbleNumber);

	/*Toggle High Nibble Value*/
	TOGGLE_HIGH_NIBBLE(PORT);
}

/*Assign High Nibble Value in case of output*/
void DIO_vidAssignHighNibbleValue(u8 Copy_u8HighNibbleNumber,u8 Copy_u8HighNibbleValue)
{
	/*Port Identification from High Nibble Number*/
	DIO_vidPortIdentification(Copy_u8HighNibbleNumber);

	/*Assign High Nibble Value*/
	ASSIGN_HIGH_NIBBLE(PORT,Copy_u8HighNibbleValue);
}

/*Set Port Value in case of output*/
void DIO_vidSetPortValue(u8 Copy_u8PortId,u8 copy_u8Portvalue)
{
	/*Port Identification from Port Id*/
	DIO_vidPortIdentification(Copy_u8PortId);

	/*low - 0v*/
	if(copy_u8Portvalue==LOW)
	{
		CLEAR_PORT(PORT);
	}
	/*high - 5v*/
	else if(copy_u8Portvalue==HIGH)
	{
		SET_PORT(PORT);
	}
	/*useless*/
	else
	{}
}

/*Toggle Port Value in case of output*/
void DIO_vidTogglePortValue(u8 Copy_u8PortId)
{
	/*Port Identification from Port Id*/
	DIO_vidPortIdentification(Copy_u8PortId);

	/*Toggle Port Value*/
	TOGGLE_PORT(PORT);
}

/*Assign Port Value in case of output*/
void DIO_vidAssignPortValue(u8 Copy_u8PortId,u8 Copy_u8PortValue)
{
	/*Port Identification from Port Id*/
	DIO_vidPortIdentification(Copy_u8PortId);

	/*Assign Port Value*/
	ASSIGN_PORT(PORT,Copy_u8PortValue);
}

/*Get Pin Value in case of input*/
u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber)
{
	u8 Local_u8DIOPinNumber,Local_u8DIOGetPinValue;
	Local_u8DIOPinNumber=Copy_u8PinNumber%8;

	/*Port Identification from pin number*/
	DIO_vidPortIdentification(Copy_u8PinNumber);

	/*Get Pin Value 0(0v) or 1(5v)*/
	Local_u8DIOGetPinValue=GET_BIT(PIN,Local_u8DIOPinNumber);
	return Local_u8DIOGetPinValue;
}

/*Get Low Nibble Value in case of input*/
u8 DIO_u8GetLowNibbleValue(u8 Copy_u8LowNibbleNumber)
{
	u8 Local_u8DIOGetLowNibbleValue;

	/*Port Identification from Low Nibble Number*/
	DIO_vidPortIdentification(Copy_u8LowNibbleNumber);

	/*Get Low Nibble Value*/
	Local_u8DIOGetLowNibbleValue=GET_LOW_NIBBLE(PIN);
	return Local_u8DIOGetLowNibbleValue;
}

/*Get High Nibble Value in case of input*/
u8 DIO_u8GetHighNibbleValue(u8 Copy_u8HighNibbleNumber)
{
	u8 Local_u8DIOGetHighNibbleValue;

	/*Port Identification from High Nibble Number*/
	DIO_vidPortIdentification(Copy_u8HighNibbleNumber);

	/*Get High Nibble Value*/
	Local_u8DIOGetHighNibbleValue=GET_HIGH_NIBBLE(PIN);
	return Local_u8DIOGetHighNibbleValue;
}

/*Get Port Value in case of input*/
u8 DIO_u8GetPortValue(u8 Copy_u8PortId)
{
	u8 Local_u8DIOGetPortValue;

	/*Port Identification from Port Id*/
	DIO_vidPortIdentification(Copy_u8PortId);

	/*Get Port Value*/
	Local_u8DIOGetPortValue=GET_PORT(PIN);
	return Local_u8DIOGetPortValue;
}

/***************************** SPI Master DIO Configurations ******************************/
void DIO_vidSPIMasterPinConfigurations(void)
{
	/*set MOSI as output*/
	DIO_vidSetPinDirection(PIN13,OUTPUT);

	/*set MISO as input high impedence*/
	DIO_vidSetPinDirection(PIN14,INPUT_HIGH_Z);

	/*set SCK as output*/
	DIO_vidSetPinDirection(PIN15,OUTPUT);
}

/***************************** SPI Slave DIO Configurations ******************************/
void DIO_vidSPISlavePinConfigurations(void)
{
	/*set slave select SS' as input high impedence*/
	DIO_vidSetPinDirection(PIN12,INPUT_HIGH_Z);

	/*set MOSI as output*/
	DIO_vidSetPinDirection(PIN13,INPUT_HIGH_Z);

	/*set MISO as input high impedence*/
	DIO_vidSetPinDirection(PIN14,OUTPUT);

	/*set SCK as output*/
	DIO_vidSetPinDirection(PIN15,INPUT_HIGH_Z);
}


