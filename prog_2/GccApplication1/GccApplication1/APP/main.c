#include "../RTOS/API/API_Task.h"
#include "../LIBS/STD_TYPES.h"

extern xInitTaskHandle;
extern xRecieveTaskHandle;

int main(void)
{
	// Create Initialization Task with lower priority
	xTaskCreate(vInitTask, "Init Task", 100, NULL, 2, &xInitTaskHandle);

	// Create Recieve Task with highest priority
	xTaskCreate(vRecieveTask, "Recieve Task", 100, NULL, 1, &xRecieveTaskHandle);

	// Start the scheduler
	vTaskStartScheduler();

	// In case the scheduler exits for some reason (it shouldn't)
	while (1);

	return 0;
}
