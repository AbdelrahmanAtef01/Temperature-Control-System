#ifndef API_TASK_H_
#define API_TASK_H_

#include <avr/io.h>
/* --------------------------------->>CPU Libraries------------------------------------------ */
#include "../../MCAL/EXE_INTERRUPT/EXTI_Interface.h"
#include  "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/SPI/SPI_Interface.h"
#include "../../MCAL/TIMERS/TIMER0/TMR0_Interface.h"
#include "../../MCAL/TIMERS/TIMER1/TMR1_Interface.h"
/* --------------------------------->>HAL Libraries------------------------------------------ */
#include "../../HAL/RELAY/RELAY0/RELAY0_Interface.h"
#include "../../HAL/RELAY/RELAY1/RELAY1_Interface.h"
/* --------------------------------->>FreeRTOS Libraries------------------------------------- */
#include "../Header/FreeRTOS.h"
#include "../Header/task.h"
#include "../Header/semphr.h"
/* --------------------------------->>End of Libraries--------------------------------------- */

/* --------------------------------->>Main FreeRTOS Function--------------------------------- */
//---------------------------------->>Functions ProtoTypes.
void switch_pressed();
void fan_pressed();
void heater_pressed();
void vRecieveTask(void *pvParameters);
void vInitTask(void *pvParameters);

#endif /* API_TASK_H_ */