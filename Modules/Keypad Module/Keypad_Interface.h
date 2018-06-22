/*
 * Keypad_Interface.h
 *
 *  Created on: Apr 14, 2018
 *      Author: ahmed
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

void Keypad_vidInitializeKeys(void);
u8 Keypad_u8GetKey(u8* Copy_pu8KeyValue);

/*-----for keys pressed or not pressed*/
#define NOT_PRESSED 0
#define PRESSED 1


#endif /* KEYPAD_INTERFACE_H_ */
