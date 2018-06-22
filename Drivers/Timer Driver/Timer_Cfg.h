/*
 * Timer_Cfg.h
 *
 *  Created on: Apr 21, 2018
 *      Author: ahmed
 */

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

#define TCCR0   *((volatile u8*) 0x53)
#define TCNT0   *((volatile u8*) 0x52)
#define TIMSK   *((volatile u8*) 0x59)
#define OCR0    *((volatile u8*) 0x5c)
#define TIFR    *((volatile u8*) 0x58)
#define SREG    *((volatile u8*) 0x5f)

#define ENABLE 1
#define DISABLE 0

#endif /* TIMER_CFG_H_ */
