/*
 * UART_Cfg.h
 *
 *  Created on: Apr 27, 2018
 *      Author: ahmed
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_

#define UDR     *((volatile u8*) 0x2c)
#define UCSRA   *((volatile u8*) 0x2b)
#define UCSRB   *((volatile u8*) 0x2a)
#define UCSRC   *((volatile u8*) 0x40)
#define UBRRL   *((volatile u8*) 0x29)
#define UBRRH   *((volatile u8*) 0x40)
#define SREG    *((volatile u8*) 0x5f)

#define ENABLE 1
#define DISABLE 0

#endif /* UART_CFG_H_ */
