/*
 * UART_Prog.c
 *
 *  Created on: Apr 27, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "UART_Interface.h"
#include "UART_Cfg.h"

void (*PtrLCDInitialization)(void);
void (*PtrLCDWriteCommand)(u8 Copy_u8Command);
void (*PtrLCDWriteData)(u8 Copy_u8Data);

u8 Global_u8Data;

void UART_vidInitialization(void)
{
	/*for setting Baud Rate=9600 we can get UBRR from the following equation
	 *Baud Rate=(F osc.)/(16(UBRR+1)) so UBBR=77
	 *UBRRL=77=0x4d & UBRRH=0x00*/
	ASSIGN_PORT(UBRRL,0x4d);
	ASSIGN_PORT(UBRRH,0x00);

	/*for Tx Enable*/
	SET_BIT(UCSRB,3);

	/*for Rx Enable*/
	SET_BIT(UCSRB,4);

#if(INTERRUPT_MODE)
	/*for Tx Complete Interrupt Enable*/
	SET_BIT(UCSRB,6);

	/*for Rx Complete Interrupt Enable*/
	SET_BIT(UCSRB,7);

	/*for global interrupt enable*/
	SET_BIT(SREG,7);
#endif

	/*for Character Size*/
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	CLEAR_BIT(UCSRB,2);

	/*for Disable Parity Mode*/
	CLEAR_BIT(UCSRC,4);
	CLEAR_BIT(UCSRC,5);

	/*for setting one stop bit*/
	CLEAR_BIT(UCSRC,3);
}

void UART_vidTransmit(u16 Copy_u16Data)
{
	/*for assigning data to UDR register*/
	UDR=Copy_u16Data;

#if(!INTERRUPT_MODE)
	/*for polling until UART Transmit Complete flag is set*/
	while(GET_BIT(UCSRA,6)==0);

	/*for clearing UART Transmit Complete flag*/
	SET_BIT(UCSRA,6);
#endif
}

u16 UART_vidReceive(void)
{
	u16 Local_u16Data;

#if(!INTERRUPT_MODE)
	/*for polling until UART Receive Complete flag is set*/
	while(GET_BIT(UCSRA,7)==0);
#endif

	/*for reading the received data from the UDR register
	 *and there is no need for clearing Receive Complete flag because it is cleared automatically
	 *when we read data from UDR register*/
	//Local_u16Data=UDR;

	return Local_u16Data;
}

#if(INTERRUPT_MODE)
/*vector number 15 for UART Tx Complete*/
void __vector_15(void) __attribute__((signal,__INTR_ATTRS));

void __vector_15(void)
{
	PtrLCDInitialization();

	PtrLCDWriteCommand(0x80);

	PtrLCDWriteData('T');
	PtrLCDWriteData('r');
	PtrLCDWriteData('a');
	PtrLCDWriteData('n');
	PtrLCDWriteData('s');
	PtrLCDWriteData('m');
	PtrLCDWriteData('i');
	PtrLCDWriteData('s');
	PtrLCDWriteData('s');
	PtrLCDWriteData('i');
	PtrLCDWriteData('o');
	PtrLCDWriteData('n');

	PtrLCDWriteCommand(0xc0);

	PtrLCDWriteData('D');
	PtrLCDWriteData('o');
	PtrLCDWriteData('n');
	PtrLCDWriteData('e');

}

/*vector number 13 for UART Rx Complete*/
void __vector_13(void) __attribute__((signal,__INTR_ATTRS));

void __vector_13(void)
{
	PtrLCDInitialization();

	Global_u8Data=UDR;

	PtrLCDWriteCommand(0x80);

	PtrLCDWriteData('R');
	PtrLCDWriteData('e');
	PtrLCDWriteData('c');
	PtrLCDWriteData('e');
	PtrLCDWriteData('i');
	PtrLCDWriteData('v');
	PtrLCDWriteData('e');
	PtrLCDWriteData('d');
	PtrLCDWriteData(' ');
	PtrLCDWriteData('D');
	PtrLCDWriteData('a');
	PtrLCDWriteData('t');
	PtrLCDWriteData('a');
	PtrLCDWriteData(61);

	PtrLCDWriteCommand(0xc0);

	PtrLCDWriteData((Global_u8Data/100)+48);
	PtrLCDWriteData(((Global_u8Data%100)/10)+48);
	PtrLCDWriteData(((Global_u8Data%100)/10)+48);
}
#endif

void UART_vidSetCallBack1(void (*PtrToFunction1)(void))
{
	PtrLCDInitialization=PtrToFunction1;
}

void UART_vidSetCallBack2(void (*PtrToFunction2)(u8 Copy_u8Command))
{
	PtrLCDWriteCommand=PtrToFunction2;
}

void UART_vidSetCallBack3(void (*PtrToFunction3)(u8 Copy_u8Data))
{
	PtrLCDWriteData=PtrToFunction3;
}
