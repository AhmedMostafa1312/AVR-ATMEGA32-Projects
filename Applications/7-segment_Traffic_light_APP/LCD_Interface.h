/*
 * LCD_Interface.h
 *
 *  Created on: Apr 7, 2018
 *      Author: ahmed
 */


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_vidInitialization(void);
void LCD_vidWriteCommand(u8 Copy_u8Command);
void LCD_vidWriteData(u8 Copy_u8Data);

#define BIT_MODE 4

/*
*Notes:
*command 0x80 for line 0 and command 0xc0 for line 1
*command 0x01 for clearing LCD
*/


#endif /* LCD_INTERFACE_H_ */
