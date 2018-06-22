/*
 * ExtINT_Cfg.h
 *
 *  Created on: Apr 14, 2018
 *      Author: ahmed
 */

#ifndef EXTINT_CFG_H_
#define EXTINT_CFG_H_

/*-----external interrupt registers-----*/
#define SREG   *((volatile u8*) 0x5f)
#define MCUCR  *((volatile u8*) 0x55)
#define MCUCSR *((volatile u8*) 0x54)
#define GICR   *((volatile u8*) 0x5b)
#define GIFR   *((volatile u8*) 0x5a)

/*-----external interrupt enable-----*/
#define ENABLE 1
#define DISABLE 0


#endif /* EXTINT_CFG_H_ */
