/*
 * ADC_Cfg.h
 *
 *  Created on: Apr 20, 2018
 *      Author: ahmed
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#define ADMUX  *((volatile u8*) 0x27)
#define ADCL   *((volatile u8*) 0x24)
#define ADCH   *((volatile u8*) 0x25)
#define ADCSRA *((volatile u8*) 0x26)
#define SFIOR  *((volatile u8*) 0x50)

#define ENABLE 1
#define DISABLE 0

#endif /* ADC_CFG_H_ */
