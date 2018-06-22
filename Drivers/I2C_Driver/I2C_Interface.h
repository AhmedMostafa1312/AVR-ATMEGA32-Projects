/*
 * I2C_Interface.h
 *
 *  Created on: Apr 29, 2018
 *      Author: ahmed
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void I2C_vidInitialization(void);

void I2C_vidMasterStartCondition(void);
void I2C_vidMasterStopCondition(void);
void I2C_vidWrite(u8 Copy_u8Data);
u8 I2C_vidGetStatus(void);
u8 I2C_vidReadACK(void);
u8 I2C_vidReadNACK(void);

#endif /* I2C_INTERFACE_H_ */
