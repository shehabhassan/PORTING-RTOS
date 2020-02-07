/*
 * Toggle.c
 *
 * Created: 06/02/2020 07:49:34 م
 *  Author: sheha
 */ 

/*
 * Toggle_led.c
 *
 * Created: 06/02/2020 07:11:45 م
 *  Author: sheha
 */ 

#define F_CPU	16000000
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"

void task(void *p){
	
	 DDRC |= (1<<7);

	while (1)
	{
		PORTC ^= (1<<7);
		vTaskDelay (1000/portTICK_PERIOD_MS);
	}
}
int main(void)
{
             xTaskCreate(task,"led",200,NULL,1,NULL);
 //  xTaskCreate(task,"firsttask",250,NULL,1,NULL);
           vTaskStartScheduler();
		  return 0;
}