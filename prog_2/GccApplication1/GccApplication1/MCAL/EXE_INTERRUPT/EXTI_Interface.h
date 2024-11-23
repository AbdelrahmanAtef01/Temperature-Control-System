#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
#include "EXTI_Configuration.h"

// Define function pointer type for callbacks
typedef void (*EXTI_Callback_t)(void);

// External Interrupts initialization with sense control
void EXTI_INT0_Init(uint8_t senseControl);
void EXTI_INT1_Init(uint8_t senseControl);
void EXTI_INT2_Init(uint8_t senseControl);

// Set callback functions
void EXTI_INT0_SetCallback(EXTI_Callback_t callback);
void EXTI_INT1_SetCallback(EXTI_Callback_t callback);
void EXTI_INT2_SetCallback(EXTI_Callback_t callback);

#endif /* EXTI_INTERFACE_H_ */
