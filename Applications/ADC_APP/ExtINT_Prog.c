/*
 * ExternalInterrupt_Prog.c
 *
 *  Created on: Apr 14, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "ExtINT_Interface.h"
#include "ExtINT_Cfg.h"

/*initialization function for external interrupt*/
void ExtINT_vidInitialization(void)
{
#if(INT0) /*PD2*/

	/*set global interrupt bit(7)*/
	SET_BIT(SREG,7);
	/*set the way to sense interrupt bits(0&1) in MCUCR register
	 (1-1)for rising edge (1-0)for falling edge (0-1)for any logical change (0-0)for low level*/
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	/*set interrupt 0 enable bit(6)*/
	SET_BIT(GICR,6);

#endif

#if(INT1) /*PD3*/

	/*set global interrupt bit(7)*/
	SET_BIT(SREG,7);
	/*set the way to sense interrupt bits(2&3) in MCUCR register
	 (1-1)for rising edge (1-0)for falling edge (0-1)for any logical change (0-0)for low level*/
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	/*set interrupt 1 enable bit(7)*/
	SET_BIT(GICR,7);

#endif

#if(INT2) /*PB2*/

	/*set global interrupt bit(7)*/
	SET_BIT(SREG,7);
	/*set the way to sense interrupt bit(6) (1)for rising edge (0)for falling edge*/
	SET_BIT(MCUCSR,6);
	/*set interrupt 2 enable bit(5)*/
	SET_BIT(GICR,5);

#endif
}

/*vector number 1 for interrupt 0*/
#if(INT0)

/*tell compiler that it is an interrupt function*/
void __vector_1(void) __attribute__((signal,__INTR_ATTRS));

/*interrupt service routine for interrupt 0*/
void __vector_1(void)
{
	//DIO_vidSetPinDirection(PIN29,OUTPUT);
	//DIO_vidSetPinValue(PIN29,HIGH);
}

#endif

/*vector number 2 for interrupt 1*/
#if(INT1)

/*tell compiler that it is an interrupt function*/
void __vector_2(void) __attribute__((signal,__INTR_ATTRS));

/*interrupt service routine for interrupt 1*/
void __vector_2(void)
{
	DIO_vidSetPinDirection(PIN30,OUTPUT);
	DIO_vidSetPinValue(PIN30,HIGH);
}

#endif

/*vector number 3 for interrupt 2*/
#if(INT2)

/*tell compiler that it is an interrupt function*/
void __vector_3(void) __attribute__((signal,__INTR_ATTRS));

/*interrupt service routine for interrupt 2*/
void __vector_3(void)
{
	DIO_vidSetPinDirection(PIN31,OUTPUT);
	DIO_vidSetPinValue(PIN31,HIGH);
}

#endif



