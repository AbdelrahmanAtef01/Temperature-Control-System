#include "API_Task.h"

// Global Variables
uint8_t switch_state = 0;
uint8_t threshold = 28;
uint8_t lm_read = 0;

// Task Handles (for managing tasks)
TaskHandle_t xInitTaskHandle;
TaskHandle_t xRecieveTaskHandle;

// Interrupt Service Routines (ISR)
void switch_pressed()
{
	if (switch_state == 0)
	switch_state = 1;
	else
	switch_state = 0;
}

void fan_pressed()
{
	if (switch_state)
	{
		RELAY0_ON();
		RELAY1_OFF();
	}
}

void heater_pressed()
{
	if (switch_state)
	{
		RELAY1_ON();
		RELAY0_OFF();
	}
}

// Task: Recieve Task (High Priority)
void vRecieveTask(void *pvParameters)
{
	for (;;)
	{
		// Send and receive data using SPI
		SPDR = switch_state;
		lm_read = SPI_Receive();
		vTaskDelay(100);  // Delay for 100ms
		
		threshold = SPI_Receive();

		// Set PWM Duty Cycle based on lm_read value
		TMR1_PWM_SetDutyCycleA((uint32_t)lm_read * 255 / 50);

		// Check if the switch is OFF, control relay based on temperature
		if (!switch_state)
		{
			if (lm_read >= threshold)
			{
				RELAY0_ON();
				RELAY1_OFF();
			}
			else
			{
				RELAY1_ON();
				RELAY0_OFF();
			}
		}
		vTaskDelay(1000);
	}
}

// Task: Initialization Task (Runs only once)
void vInitTask(void *pvParameters)
{
	// Initialization code
	SPI_InitSlave(SPI_MODE_1, SPI_MSB_FIRST);
	TMR0_Init();
	TMR0_Start(1000);
	RELAY0_Initialization();
	RELAY1_Initialization();
	EXTI_INT0_Init(EXTI_ANY_CHANGE);
	DIO_SetPinPullUp(DIO_PORTD, DIO_PIN3);
	DIO_SetPinPullUp(DIO_PORTB, DIO_PIN2);
	EXTI_INT1_Init(EXTI_FALLING_EDGE);
	EXTI_INT2_Init(EXTI_INT2_FALLING_EDGE);
	EXTI_INT0_SetCallback(&switch_pressed);
	EXTI_INT1_SetCallback(&fan_pressed);
	EXTI_INT2_SetCallback(&heater_pressed);
	TMR1_Init();
	TMR1_PWM_SetFrequency(500);
	TMR1_PWM_SetDutyCycleA(100);
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);
	TMR1_PWM_SetDutyCycleA((uint32_t)lm_read * 255 / 50);

	// Delete this task after running once
	vTaskSuspend(0);
}
