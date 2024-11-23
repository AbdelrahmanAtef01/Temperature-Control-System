/*
 * LED0_Configuration.h
 *
 * Created: 1/13/2024 5:45:23 PM
 *  Author: karim
 */ 


#ifndef LED0_CONFIGURATION_H_
#define LED0_CONFIGURATION_H_

#include "../../../MCAL/CONFIG/CPU_Configuration.h"
#include "../../../MCAL/DIO/DIO_Interface.h"

//Renaming Port
#define LED0_PORT   DIO_PORTC
//Renaming Pin
#define LED0_PIN    DIO_PIN2
//Renaming State
#define LED0_OUTPUT DIO_OUTPUT
//Renaming Status
#define LED0_LOW    DIO_LOW
#define LED0_HIGH   DIO_HIGH




#endif /* LED0_CONFIGURATION_H_ */
