/*
 * RTOS_Ex3.c
 *
 *  Created on: Jun 18, 2018
 *      Author: ahmed
 */

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "semphr.h"
#include "Utils.h"

xSemaphoreHandle xSemaphore;

/* Define Tasks Priorities */
#define  TASK1_PRIORITY (0)
#define  TASK2_PRIORITY (1)

/*tasks codes prototypes */
 void task1_code(void*pvParamter);
 void task2_code(void*pvParamter);

int main(void)
{
	vSemaphoreCreateBinary(xSemaphore);

	/*Creat tasks*/
	xTaskCreate(task1_code,"Task1",80,NULL,TASK1_PRIORITY,NULL);
	xTaskCreate(task2_code,"Task2",80,NULL,TASK2_PRIORITY,NULL);

	/*start Scheduler */
	vTaskStartScheduler();

	return 0;

}

/*Task1 Code SW*/
 void task1_code(void*pvParamter)
{
	xSemaphoreTake(xSemaphore,1000);

	CLEAR_BIT(DDRD,0);

	 portTickType x;
	 x=xTaskGetTickCount();

	while(1)
	{
		if(GET_BIT(PIND,0)==1)
		{
			xSemaphoreGive(xSemaphore);
		}
		vTaskDelayUntil(&x,200);
	}

}

/*Task2 Code LED*/
 void task2_code(void*pvParamter)
{
	 SET_BIT(DDRD,5);

	 portTickType x;
	 x=xTaskGetTickCount();

	while(1)
	{
		if(xSemaphoreTake(xSemaphore,1000)==1)
		{
			TOGGLE_BIT(PORTD,5);
		}

		vTaskDelayUntil(&x,150);
	}
}
