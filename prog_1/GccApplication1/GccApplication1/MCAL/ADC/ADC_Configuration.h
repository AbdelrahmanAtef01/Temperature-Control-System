#ifndef ADC_CONFIGURATION_H_
#define ADC_CONFIGURATION_H_

#include "../CONFIG/CPU_Configuration.h"

// ADC Configuration Options

// Voltage Reference Selection
#define ADC_VREF_AREF            0    // AREF, Internal Vref turned off
#define ADC_VREF_AVCC            1    // AVCC with external capacitor at AREF pin
#define ADC_VREF_INTERNAL        3    // Internal 2.56V Reference with external capacitor at AREF pin

// ADC Prescaler Options
#define ADC_PRESCALER_2          1
#define ADC_PRESCALER_4          2
#define ADC_PRESCALER_8          3
#define ADC_PRESCALER_16         4
#define ADC_PRESCALER_32         5
#define ADC_PRESCALER_64         6
#define ADC_PRESCALER_128        7

// ADC Channels Enumeration
typedef enum {
	ADC_CHANNEL_0 = 0,    // ADC0
	ADC_CHANNEL_1,        // ADC1
	ADC_CHANNEL_2,        // ADC2
	ADC_CHANNEL_3,        // ADC3
	ADC_CHANNEL_4,        // ADC4
	ADC_CHANNEL_5,        // ADC5
	ADC_CHANNEL_6,        // ADC6
	ADC_CHANNEL_7         // ADC7
} ADC_Channel_t;

// Default Configuration
#define ADC_DEFAULT_VREF         ADC_VREF_AVCC     // Can be set to AREF, AVCC, or INTERNAL
#define ADC_DEFAULT_PRESCALER    ADC_PRESCALER_128

#endif /* ADC_CONFIGURATION_H_ */


