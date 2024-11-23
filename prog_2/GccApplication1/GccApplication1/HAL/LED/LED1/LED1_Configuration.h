/*
 * LED1_Configuration.h
 *
 * Created: 1/13/2024 5:45:23 PM
 *  Author: karim
 */ 


#ifndef LED1_CONFIGURATION_H_
#define LED1_CONFIGURATION_H_

#include "../../../MCAL/CONFIG/CPU_Configuration.h"
#include "../../../MCAL/DIO/DIO_Interface.h"

//Renaming Port
#define LED1_PORT   DIO_PORTC
//Renaming Pin
#define LED1_PIN    DIO_PIN3
//Renaming State
#define LED1_OUTPUT DIO_OUTPUT
//Renaming Status
#define LED1_LOW    DIO_LOW
#define LED1_HIGH   DIO_HIGH




#endif /* LED1_CONFIGURATION_H_ */
