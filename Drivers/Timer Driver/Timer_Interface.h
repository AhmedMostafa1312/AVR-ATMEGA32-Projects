/*
 * Timer_Interface.h
 *
 *  Created on: Apr 21, 2018
 *      Author: ahmed
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_vidOverFlowModeInitialization(u8 Copy_u8EventTime);
void TIMER0_vidCTCModeInitialization(u8 Copy_u8EventTime,u8 Copy_u8OutputComparevalue);
void TIMER0_vidFastPWMModeInitialization(u8 Copy_u8OutputCompareDutyCycle);
void TIMER0_vidPhaseCorrectPWMModeInitialization(u8 Copy_u8OutputCompareDutyCycle);

void TIMER0_vidSetCallBack(void (*Local_vidPointerToFunction) (void));

#endif /* TIMER_INTERFACE_H_ */
