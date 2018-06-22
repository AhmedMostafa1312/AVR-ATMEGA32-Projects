/*
 * UART_Interface.h
 *
 *  Created on: Apr 27, 2018
 *      Author: ahmed
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_vidInitialization(void);
void UART_vidTransmit(u16 Copy_u16Data);
u16 UART_vidReceive(void);

void UART_vidSetCallBack1(void (*PtrToFunction1)(u8 Copy_u8Parameter));
void UART_vidSetCallBack2(void (*PtrToFunction2)(u8 Copy_u8Parameter));
void UART_vidSetCallBack3(void (*PtrToFunction3)(u8 Copy_u8Parameter));

#define INTERRUPT_MODE DISABLE

#endif /* UART_INTERFACE_H_ */
