/*
 * RTOS_LAB1_ATMEGA32.c
 *
 * Created: 1/27/2014 12:22:11 AM
 *  Author: Islam
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "Utils.h"

#include <util/delay.h>

/* Define Tasks Priorities */
#define  TASK1_PRIORITY (0)
#define  TASK2_PRIORITY (1)

/*tasks codes prototypes */
 void task1_code(void*pvParamter);
 void task2_code(void*pvParamter);

int main(void)
{
	/*Creat tasks*/
	xTaskCreate(task1_code,"Task1",80,NULL,TASK1_PRIORITY,NULL);
	xTaskCreate(task2_code,"Task2",80,NULL,TASK2_PRIORITY,NULL);
	/*start Scheduler */
	vTaskStartScheduler();
	
	return 0;
    
}

/*Task1 Code */
 void task1_code(void*pvParamter)
{
	 SET_BIT(DDRD,7);

	 portTickType x;
	 x=xTaskGetTickCount();

	while(1)
	{
		TOGGLE_BIT(PORTD,7);
		vTaskDelayUntil(&x,200);
	}
		
}

/*Task 2 Code*/
 void task2_code(void*pvParamter)
{
	 SET_BIT(DDRD,6);

	 portTickType x;
	 x=xTaskGetTickCount();

	while(1)
	{
		TOGGLE_BIT(PORTD,6);
		vTaskDelayUntil(&x,1000);
	}
}
