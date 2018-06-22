/*
 * DIO_Cfg.h
 *
 *  Created on: Apr 6, 2018
 *      Author: ahmed
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/*-----addresses of registers-----*/

/*-----for port A-----*/
#define DDRA *((volatile u8*) 0x3a)
#define PINA *((volatile u8*) 0x39)
#define PORTA *((volatile u8*) 0x3b)

/*-----for port B-----*/
#define DDRB *((volatile u8*) 0x37)
#define PINB *((volatile u8*) 0x36)
#define PORTB *((volatile u8*) 0x38)

/*-----for port C-----*/
#define DDRC *((volatile u8*) 0x34)
#define PINC *((volatile u8*) 0x33)
#define PORTC *((volatile u8*) 0x35)

/*-----for port D-----*/
#define DDRD *((volatile u8*) 0x31)
#define PIND *((volatile u8*) 0x30)
#define PORTD *((volatile u8*) 0x32)


/*----- macros for simplifying-----*/
#define DDR (*Global_pu8DIODDR)
#define PIN (*Global_pu8DIOPIN)
#define PORT (*Global_pu8DIOPORT)

#endif /* DIO_CFG_H_ */

