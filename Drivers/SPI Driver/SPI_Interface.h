/*
 * SPI_Interface.h
 *
 *  Created on: Apr 28, 2018
 *      Author: ahmed
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_vidInitialization(void);
u8 SPI_u8TransmitReceive(u8 Copy_u8Data);

#define INTERRUPT_MODE DISABLE

#endif /* SPI_INTERFACE_H_ */
