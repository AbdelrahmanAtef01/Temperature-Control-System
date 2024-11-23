#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_Configuration.h"

// Function Prototypes

// Initializes the ADC peripheral
void ADC_Init(void);

// Reads the ADC value from the specified channel (using ADC_Channel_t enum)
uint16_t ADC_Read(ADC_Channel_t channel);

#endif /* ADC_INTERFACE_H_ */
