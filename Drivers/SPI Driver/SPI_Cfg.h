/*
 * SPI_Cfg.h
 *
 *  Created on: Apr 28, 2018
 *      Author: ahmed
 */

#ifndef SPI_CFG_H_
#define SPI_CFG_H_

#define SPCR   *((volatile u8*) 0x2d)
#define SPSR   *((volatile u8*) 0x2e)
#define SPDR   *((volatile u8*) 0x2f)
#define SREG    *((volatile u8*) 0x5f)

#define ENABLE 1
#define DISABLE 0

#endif /* SPI_CFG_H_ */
