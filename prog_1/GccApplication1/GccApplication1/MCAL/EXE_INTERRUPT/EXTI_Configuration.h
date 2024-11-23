#ifndef EXTI_CONFIGURATION_H_
#define EXTI_CONFIGURATION_H_

#include "../CONFIG/CPU_Configuration.h"

// Interrupt sense control options
// For INT0 and INT1
#define EXTI_LOW_LEVEL           0b00  // Trigger on low level
#define EXTI_ANY_CHANGE          0b01  // Trigger on any logical change
#define EXTI_FALLING_EDGE        0b10  // Trigger on falling edge
#define EXTI_RISING_EDGE         0b11  // Trigger on rising edge

// For INT2 (only falling or rising edge)
#define EXTI_INT2_FALLING_EDGE   0
#define EXTI_INT2_RISING_EDGE    1

#endif /* EXTI_CONFIGURATION_H_ */
