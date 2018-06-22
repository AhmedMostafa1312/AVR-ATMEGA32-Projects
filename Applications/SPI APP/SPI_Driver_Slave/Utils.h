/*
 * Utils.h
 *
 *  Created on: Apr 6, 2018
 *      Author: ahmed
 */

#ifndef UTILS_H_
#define UTILS_H_

/*----------8-bit registers----------*/

/*-----for single bit-----*/
#define GET_BIT(reg,bit_number) ((reg&(1<<bit_number))>>bit_number)
#define SET_BIT(reg,bit_number) (reg|=(1<<bit_number))
#define CLEAR_BIT(reg,bit_number) (reg&=~(1<<bit_number))
#define TOGGLE_BIT(reg,bit_number) (reg^=(1<<bit_number))
#define ASSIGN_BIT(reg,bit_number,value) do{if(value==0)\
										    {reg&=~(1<<bit_number);}\
										    else\
										    {reg|=(1<<bit_number);}}while(0); /*value can be 0 or 1*/

/*-----for low nibble-----*/
#define GET_LOW_NIBBLE(reg) (reg&(0xf))
#define SET_LOW_NIBBLE(reg) (reg|=(0xf))
#define CLEAR_LOW_NIBBLE(reg) (reg&=~(0xf))
#define TOGGLE_LOW_NIBBLE(reg) (reg^=(0xf))
#define ASSIGN_LOW_NIBBLE(reg,value) do{reg&=~(0xf);\
									    reg|=value;}while(0); /*value can be 0:15*/

/*-----for high nibble-----*/
#define GET_HIGH_NIBBLE(reg) ((reg&(0xf0))>>4)
#define SET_HIGH_NIBBLE(reg) (reg|=(0xf0))
#define CLEAR_HIGH_NIBBLE(reg) (reg&=~(0xf0))
#define TOGGLE_HIGH_NIBBLE(reg) (reg^=(0xf0))
#define ASSIGN_HIGH_NIBBLE(reg,value) do{reg&=~(0xf0);\
									     reg|=(value<<4);}while(0); /*value can be 0:15*/

/*-----for port-----*/
#define GET_PORT(reg) (reg)
#define SET_PORT(reg) (reg|=(0xff))
#define CLEAR_PORT(reg) (reg&=~(0xff))
#define TOGGLE_PORT(reg) (reg^=(0xff))
#define ASSIGN_PORT(reg,value) do{reg&=~(0xff);\
								  reg|=(value);}while(0); /*value can be 0:15*/

/*-----for right rotation-----*/
#define ROTATE_RIGHT(reg,value) reg=(reg>>value)|(reg<<(8-value)) /*value can be 1:7 , if value is 0 or 8 this makes no change in reg*/

/*-----for left rotation-----*/
#define ROTATE_LEFT(reg,value) reg=(reg<<value)|(reg>>(8-value)) /*value can be 1:7 , if value is 0 or 8 this makes no change in reg*/

#endif /* UTILS_H_ */
