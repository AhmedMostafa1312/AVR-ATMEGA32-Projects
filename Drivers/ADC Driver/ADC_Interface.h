/*
 * ADC_Interface.h
 *
 *  Created on: Apr 20, 2018
 *      Author: ahmed
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_vidInitialization(void);
u16 ADC_u16GetDigitalValue(void);

#define ADC0 ENABLE
#define ADC1 DISABLE

#define AUTO_TRIGGER_MODE DISABLE

#endif /* ADC_INTERFACE_H_ */
