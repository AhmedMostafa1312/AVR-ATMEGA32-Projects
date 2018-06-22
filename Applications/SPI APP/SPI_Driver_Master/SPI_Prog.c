/*
 * SPI_Prog.c
 *
 *  Created on: Apr 28, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "SPI_Interface.h"
#include "SPI_Cfg.h"

void SPI_vidInitialization(void)
{
	/*for SPI Clock Rate Select /8 */
	SET_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);
	SET_BIT(SPSR,0);

	/*for SPI Enable*/
	SET_BIT(SPCR,6);

#if(INTERRUPT_MODE)
	/*for SPI interrupt Enable*/
	SET_BIT(SPCR,7);

	/*for global interrupt enable*/
	SET_BIT(SREG,7);
#endif
	/*for Clock Polarity falling on leading edge and rising on trailing edge*/
	SET_BIT(SPCR,3);

	/*for Clock Phase setup on leading edge and sample on trailing edge*/
	SET_BIT(SPCR,2);

	/*for Master Select*/
	SET_BIT(SPCR,4);

	/*for Data Order
	 *When the DORD bit is written to one, the LSB of the data word is transmitted first*/
	SET_BIT(SPCR,5);
}

u8 SPI_u8TransmitReceive(u8 Copy_u8Data)
{
	/*for assigning data to SPDR register*/
	SPDR=Copy_u8Data;

#if(!INTERRUPT_MODE)
	/*for polling until SPI interrupt flag is set*/
	while(GET_BIT(SPSR,7)==0);
#endif
	/*there is no need for clearing interrupt flag because it is cleared automatically
	 *by first reading the SPI Status Register (SPSR) with SPIF set
	 *then accessing the SPI Data Register (SPDR)*/
	return SPDR;
}

#if(INTERRUPT_MODE)
/*vector number 12 for SPI Serial Transfer Complete*/
void __vector_12(void) __attribute__((signal,__INTR_ATTRS));

void __vector_12(void)
{
	DIO_vidSetPinDirection(PIN31,OUTPUT);
	DIO_vidSetPinValue(PIN31,HIGH);
}
#endif
