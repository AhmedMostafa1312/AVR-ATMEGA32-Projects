/*
 * ADC_Prog.c
 *
 *  Created on: Apr 20, 2018
 *      Author: ahmed
 */

#include "Std_Types.h"
#include "Utils.h"
#include "ADC_Interface.h"
#include "ADC_Cfg.h"

/*for ADC Initialization*/
void ADC_vidInitialization(void)
{
/*ADC0*/
#if(ADC0)
	/*00000 for ADC0 , ADLAR=1 for left adjust result , 01 for AVCC. so ADMUX=0110 0000=0x60*/
	ASSIGN_PORT(ADMUX,0x60);
#endif

/*ADC1*/
#if(ADC1)
	/*00001 for ADC1 , ADLAR=1 for left adjust result , 01 for AVCC. so ADMUX=0110 0001=0x61*/
	ASSIGN_PORT(ADMUX,0x61);
#endif

	/*ADEN=1 for ADC enable */
	SET_BIT(ADCSRA,7);

	/*ADPS = 111 for ADC Prescaler Selections with division factor 128*/
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

/*ADC Auto Trigger Configuration*/
#if(AUTO_TRIGGER_MODE==ENABLE)
	/*for ADC Auto Trigger Enable ADATE=1*/
	SET_BIT(ADCSRA,5);

	/*for External Interrupt Request 0 last 3 bits in SFIOR register = 010*/
	CLEAR_BIT(SFIOR,5);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,7);

	/*for ADC Interrupt Enable ADIE=1*/
	SET_BIT(ADCSRA,4);
#endif
}

/*for Getting digital value (10 bits) from ADCH and ADCL registers , assume left adjust result*/
u16 ADC_u16GetDigitalValue(void)
{
	u16 Local_u16DigitalValue;
#if(AUTO_TRIGGER_MODE==DISABLE)
	/*for starting conversion ADSC=1*/
	SET_BIT(ADCSRA,6);

	/*polling until conversion complete and ADC interrupt flag is set ADIF=1*/
	while(GET_BIT(ADCSRA,4)==0);

	/*for clearing ADC interrupt flag ADIF =1*/
	SET_BIT(ADCSRA,4);
#elif(AUTO_TRIGGER_MODE==ENABLE)
	/*polling until conversion complete and ADC interrupt flag is set ADIF=1*/
	while(GET_BIT(ADCSRA,4)==0);
#endif

	/*for getting value (10 bits) from ADCH and ADCL registers by concatenating them in u16 variable*/
	Local_u16DigitalValue=(ADCL>>6);
	Local_u16DigitalValue|=((u16)(ADCH)<<2);

	return Local_u16DigitalValue;
}
