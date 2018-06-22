/*
 * Timer_Prog.c
 *
 *  Created on: Apr 21, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "Timer_Interface.h"
#include "Timer_Cfg.h"

u32 Global_u32NumberOfOverFlows;
/*volatile to avoid optimization because it will be used many times(to avoid placing it in a register)*/
volatile static u8 Global_u8ISRFlag=0;
void (*Global_vidPointerToFunction)(void);

/*-------------------------------------------------------------*
 *****                timer 0 overflow mode                *****
 *------------------------------------------------------------*/

/*timer 0 overflow mode initialization*/
void TIMER0_vidOverFlowModeInitialization(u8 Copy_u8EventTime)
{
	/*Calculations:
	 *clock select prescaler with division factor 1024
	 *by assigning 101 to first 3 bits in TCCR0 register
	 *clock cycle time=12MHz/1024=11718Hz
	 *clock cycle time=85us
	 *overflow time=85us*256=0.02176 sec
	 *event time(Copy_u8EventTime)=1 sec
	 *# of overflows=event time/overflow time=1/0.02176=45 overflows
	 *so every 45 overflows ; event(ex. Toggling a LED) will take place*/
	Global_u32NumberOfOverFlows=((Copy_u8EventTime*12000000)/(1024*256.0));

	 /*clock select prescaler with division factor 1024
	  *by assigning 101 to first 3 bits in TCCR0 register*/
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);

	/*for Overflow Interrupt Enable bit 0 (TOIE0) in TIMSK register*/
	SET_BIT(TIMSK,0);

	/*for counter Initialization by zero*/
	ASSIGN_PORT(TCNT0,0x00);

	/*enable global interrupt*/
	SET_BIT(SREG,7);
}

/*Timer/Counter0 Overflow interrupt vector table number 12-1=11*/
void __vector_11(void) __attribute__((signal,__INTR_ATTRS));

/*Timer/Counter0 Overflow ISR*/
void __vector_11(void)
{
	Global_u8ISRFlag++;

	/*for checking # of overflows*/
	if(Global_u8ISRFlag==(Global_u32NumberOfOverFlows-1))
	{
		Global_vidPointerToFunction();
		Global_u8ISRFlag=0;
	}
	/*useless*/
	else
	{

	}
}

/*---------------------------------------------------------------------------------------*
 *****                timer 0 Clear Timer on Compare Match (CTC) mode                *****
 *--------------------------------------------------------------------------------------*/

/*timer 0 Clear Timer on Compare Match (CTC) mode initialization*/
void TIMER0_vidCTCModeInitialization(u8 Copy_u8EventTime,u8 Copy_u8OutputComparevalue)
{
	/*Calculations:
	 *clock select prescaler with division factor 1024
	 *by assigning 101 to first 3 bits in TCCR0 register
	 *clock cycle time=12MHz/1024=11718Hz
	 *clock cycle time=85us
	 *overflow time=85us*(128 for example)Copy_u8OutputComparevalue=0.01088 sec
	 *event time=1 sec
	 *# of overflows=event time/overflow time=1/0.01088=91 overflows
	 *so every 91 overflows ; event(ex. Toggling a LED) will take place*/
	Global_u32NumberOfOverFlows=((Copy_u8EventTime*12000000)/(1024.0*Copy_u8OutputComparevalue));

	 /*clock select prescaler with division factor 1024
	  *by assigning 101 to first 3 bits in TCCR0 register*/
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);

	/*for Output Compare Match Interrupt Enable bit 1 (OCIE0) in TIMSK register*/
	SET_BIT(TIMSK,1);

	/*for counter Initialization by zero*/
	ASSIGN_PORT(TCNT0,0x00);

	/*for Waveform Generation Mode (CTC mode)
	 *set bit 3 (WGM01) and clear bit 6 (WGM00) in TCCR0 register*/
	SET_BIT(TCCR0,3);
	CLEAR_BIT(TCCR0,6);

	/*for Compare Output Mode (CTC) bits 4&5 for toggling OC0 on Compare Match*/
	SET_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);

	/*for setting OC0(pin3 in PORT B) as output
	 *to generate a waveform output on the OC0 pin*/
	DIO_vidSetPinDirection(PIN11,OUTPUT);

	/*setting value of Output Compare Register OCR0 (value to be compared to TCNT0 counter register)*/
	ASSIGN_PORT(OCR0,Copy_u8OutputComparevalue);

	/*enable global interrupt*/
	SET_BIT(SREG,7);
}

/*Timer/Counter0 Compare Match (CTC) interrupt vector table number 11-1=10*/
void __vector_10(void) __attribute__((signal,__INTR_ATTRS));

/*Timer/Counter0 Compare Match (CTC) ISR*/
void __vector_10(void)
{
	Global_u8ISRFlag++;

	/*for checking # of overflows*/
	if(Global_u8ISRFlag==(Global_u32NumberOfOverFlows-1))
	{
		Global_vidPointerToFunction();
		Global_u8ISRFlag=0;
	}
	/*useless*/
	else
	{

	}
}

/*-------------------------------------------------------------------*
 *****                timer 0 Fast PWM Mode                      *****
 *------------------------------------------------------------------*/

/*timer 0 Fast PWM mode initialization*/
void TIMER0_vidFastPWMModeInitialization(u8 Copy_u8OutputCompareDutyCycle)
{
	u8 Local_u8OutputComparevalue;
	/*for getting the corresponding value to the duty cycle*/
	Local_u8OutputComparevalue=(Copy_u8OutputCompareDutyCycle*255.0)/100.0;

	 /*clock select prescaler with division factor 1024
	  *by assigning 101 to first 3 bits in TCCR0 register*/
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);

	/*for counter Initialization by zero*/
	ASSIGN_PORT(TCNT0,0x00);

	/*setting value of Output Compare Register OCR0 (value to be compared to TCNT0 counter register)
	 *128 for 50% duty cycle */
	ASSIGN_PORT(OCR0,Local_u8OutputComparevalue);

	/*for Waveform Generation Mode (Fast PWM mode)
	 *set bit 3 (WGM01) and set bit 6 (WGM00) in TCCR0 register*/
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

	/*for setting OC0(pin3 in PORT B) as output
	 *to generate a waveform output on the OC0 pin*/
	DIO_vidSetPinDirection(PIN11,OUTPUT);

	/*for Compare Output Mode (Fast PWM Mode) bits 4&5 for clearing OC0 on Compare Match
	 *Setting OC0 at BOTTOM (inverting mode)*/
	CLEAR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
}

/*--------------------------------------------------------------------------------*
 *****                timer 0 Phase Correct PWM Mode                          *****
 *--------------------------------------------------------------------------------*/

/*timer 0 Phase Correct PWM mode initialization*/
void TIMER0_vidPhaseCorrectPWMModeInitialization(u8 Copy_u8OutputCompareDutyCycle)
{
	u8 Local_u8OutputComparevalue;
	/*for getting the corresponding value to the duty cycle*/
	Local_u8OutputComparevalue=((100-Copy_u8OutputCompareDutyCycle)*255.0)/100.0;

	 /*clock select prescaler with division factor 1024
	  *by assigning 101 to first 3 bits in TCCR0 register*/
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);

	/*for counter Initialization by zero*/
	ASSIGN_PORT(TCNT0,0x00);

	/*setting value of Output Compare Register OCR0 (value to be compared to TCNT0 counter register)
	 *128 for 50% duty cycle */
	ASSIGN_PORT(OCR0,Local_u8OutputComparevalue);

	/*for Waveform Generation Mode (Phase Correct PWM mode)
	 *clear bit 3 (WGM01) and set bit 6 (WGM00) in TCCR0 register*/
	CLEAR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

	/*for setting OC0(pin3 in PORT B) as output
	 *to generate a waveform output on the OC0 pin*/
	DIO_vidSetPinDirection(PIN11,OUTPUT);

	/*for Compare Output Mode (Phase Correct PWM mode) bits 4&5 for Settting OC0 on Compare Match
	 *when up-counting Clearing OC0 on Compare Match when downcounting*/
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
}

/*timer 0 Set Call Back
 *for getting the address of an upper layer(HAL)'s function
 *for calling it or modify it*/
void TIMER0_vidSetCallBack(void (*Local_vidPointerToFunction) (void))
{
	Global_vidPointerToFunction=Local_vidPointerToFunction;
}




