#include "FreeRTOS.h"
#include "task.h"
#include "Board_LED.h"
#include "MKW41Z4.h"                    // Device header


void toggleLed3(void* arg)
{
	while(1)
	{
		vTaskDelay(400);
		LED_On(3);
		vTaskDelay(400);
		LED_Off(3);
	}
}

void toggleLed2(void* arg)
{
	while(1)
	{
		vTaskDelay(300);
		LED_On(2);
		vTaskDelay(300);
		LED_Off(2);
	}
}

void toggleLed1(void* argid)
{
	while(1)
	{
		vTaskDelay(200);
		LED_On(1);
		vTaskDelay(200);
		LED_Off(1);
	}
}

void toggleLed0(void* arg)
{
	while(1)
	{
		vTaskDelay(100);
		LED_On(0);
		vTaskDelay(100);
		LED_Off(0);
	}
}

int main(void)
{
	SystemCoreClockUpdate();
	LED_Initialize();
	
	__enable_irq();
	
	xTaskCreate(toggleLed0, "LED Task 0", 100, 0, 1, 0);
	xTaskCreate(toggleLed1, "LED Task 1", 100, 0, 1, 0);
	xTaskCreate(toggleLed2, "LED Task 2", 100, 0, 1, 0);
	xTaskCreate(toggleLed3, "LED Task 3", 100, 0, 1, 0);
	
	vTaskStartScheduler();
	while(1)
	{
		volatile int x;
	}
}
