#ifndef ADC_ADDRESS_H_
#define ADC_ADDRESS_H_

// ADC Registers for Atmega32
#define ADC_ADMUX   (*(volatile uint8_t*)0x27)   // ADC Multiplexer Selection Register
#define ADC_ADCSRA  (*(volatile uint8_t*)0x26)   // ADC Control and Status Register A
#define ADC_ADCH    (*(volatile uint8_t*)0x25)   // ADC Data Register High Byte
#define ADC_ADCL    (*(volatile uint8_t*)0x24)   // ADC Data Register Low Byte
#define ADC_SFIOR   (*(volatile uint8_t*)0x50)   // Special Function IO Register

#endif /* ADC_ADDRESS_H_ */
