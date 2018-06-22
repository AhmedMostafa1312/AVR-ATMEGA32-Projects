/*
 * I2C_Cfg.h
 *
 *  Created on: Apr 29, 2018
 *      Author: ahmed
 */

#ifndef I2C_CFG_H_
#define I2C_CFG_H_

#define TWBR   *((volatile u8*) 0x20)
#define TWCR   *((volatile u8*) 0x56)
#define TWSR   *((volatile u8*) 0x21)
#define TWDR   *((volatile u8*) 0x23)
#define TWAR   *((volatile u8*) 0x22)
#define SREG   *((volatile u8*) 0x5f)

#endif /* I2C_CFG_H_ */
