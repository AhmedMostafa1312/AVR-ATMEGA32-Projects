/*
 * I2C_Prog.c
 *
 *  Created on: Apr 29, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "I2C_Interface.h"
#include "I2C_Cfg.h"

/*for I2C Initialization*/
void I2C_vidInitialization(void)
{
	/*for TWI Enable*/
	SET_BIT(TWCR,2);

	/*for setting SCL = 400KHz*/
	/*F_CPU=12MHz*/
	/*No prescaler*/
	ASSIGN_PORT(TWBR,0x07);
	//SET_BIT(SREG,7);
}

/*for Starting Condition by Master*/
void I2C_vidMasterStartCondition(void)
{
	/*for starting condition*/
	/*TWCR=1x10x10x*/

	/*for TWI Enable*/
	SET_BIT(TWCR,2);

	/*for TWI START Condition*/
	SET_BIT(TWCR,5);

	/*for clearing TWI Interrupt Flag*/
	SET_BIT(TWCR,7);

	/*INT falg will be set and status =0x08
	 *means A START condition has been transmitted*/

	/*for polling until TWINT falg is set*/
	while(GET_BIT(TWCR,7)==0);
}

/*for Stopping Condition by Master*/
void I2C_vidMasterStopCondition(void)
{
	/*for stopping condition*/
	/*TWCR=1x01x10x*/

	/*for TWI Enable*/
	SET_BIT(TWCR,2);

	/*for TWI STOP Condition*/
	SET_BIT(TWCR,4);

	/*for clearing TWI Interrupt Flag*/
	SET_BIT(TWCR,7);
}

void I2C_vidWrite(u8 Copy_u8Data)
{
	/*for assigning SLA+W or DATA to TWDR data register*/
	ASSIGN_PORT(TWDR,Copy_u8Data);

	/*TWCR=1x00x10x*/

	/*for TWI Enable*/
	SET_BIT(TWCR,2);

	/*for clearing TWI Interrupt Flag*/
	SET_BIT(TWCR,7);

	/*after ACK ; INT falg is set and status=0x18
	 *means SLA+W has been transmitted; ACK has been received
	 *or status=0x20
	 *means SLA+W has been transmitted; NOT ACK has been received
	 *or status=0x38
	 *means Arbitration lost in SLA+W or data bytes*/

	/*for polling until TWINT falg is set*/
	while(GET_BIT(TWCR,7)==0);
}

u8 I2C_vidGetStatus(void)
{
	u8 Local_u8I2CStatus;

	/*for masking status*/
	Local_u8I2CStatus=GET_PORT((TWSR&0xf8));

	return Local_u8I2CStatus;
}

/*for reading DATA with ACK*/
u8 I2C_vidReadACK(void)
{
	/*TWCR=1100x10x*/

	/*for TWI Enable*/
	SET_BIT(TWCR,2);

	/*for TWI Enable ACK*/
	SET_BIT(TWCR,6);

	/*for clearing TWI Interrupt Flag*/
	SET_BIT(TWCR,7);

	/*for polling until TWINT falg is set*/
	while(GET_BIT(TWCR,7)==0);

	return TWDR;
}

/*for reading DATA with NACK*/
u8 I2C_vidReadNACK(void)
{
	/*TWCR=1x00x10x*/

	/*for TWI Enable*/
	SET_BIT(TWCR,2);

	/*for clearing TWI Interrupt Flag*/
	SET_BIT(TWCR,7);

	/*for polling until TWINT falg is set*/
	while(GET_BIT(TWCR,7)==0);

	return TWDR;
}
