#include "ADC_Address.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "ADC_Configuration.h"

void ADC_Init(void) {
	// Set the reference voltage based on the configuration in ADC_Configuration.h
	ADC_ADMUX = (ADC_DEFAULT_VREF << 6);  // Set the voltage reference (AREF, AVCC, or INTERNAL)
	
	// Enable ADC and set the prescaler
	ADC_ADCSRA = (1 << 7) | ADC_DEFAULT_PRESCALER;  // Enable ADC and set prescaler
}

uint16_t ADC_Read(ADC_Channel_t channel) {
	// Select the channel, clear the MUX bits and set the channel
	ADC_ADMUX = (ADC_ADMUX & 0xF8) | (channel & 0x07);
	
	// Start conversion
	ADC_ADCSRA |= (1 << 6);  // Set ADSC bit to start conversion
	
	// Wait for conversion to complete
	while (ADC_ADCSRA & (1 << 4));  // Wait until ADIF is set
	
	// Clear ADIF by writing 1 to it
	ADC_ADCSRA |= (1 << 4);
	
	// Return the ADC result
	return (ADC_ADCL | (ADC_ADCH << 8));  // Read the result (ADCL first, then ADCH)
}


