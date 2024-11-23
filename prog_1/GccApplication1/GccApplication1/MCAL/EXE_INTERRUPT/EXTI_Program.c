#include "EXTI_Address.h"
#include <avr/interrupt.h>
#include "EXTI_Interface.h"

// Define static variables to hold callback functions
static EXTI_Callback_t EXTI_INT0_Callback = 0;
static EXTI_Callback_t EXTI_INT1_Callback = 0;
static EXTI_Callback_t EXTI_INT2_Callback = 0;

// External Interrupt 0 Initialization with sense control
void EXTI_INT0_Init(uint8_t senseControl) {
	// Configure the interrupt sense control for INT0
	MCUCR = (MCUCR & 0xFC) | (senseControl & 0x03);  // Mask and set ISC01, ISC00

	// Enable INT0 interrupt
	GICR |= (1 << INT0);
	
	// Enable global interrupts
	SREG |= (1 << 7);
}

// External Interrupt 1 Initialization with sense control
void EXTI_INT1_Init(uint8_t senseControl) {
	// Configure the interrupt sense control for INT1
	MCUCR = (MCUCR & 0xF3) | ((senseControl & 0x03) << 2);  // Mask and set ISC11, ISC10

	// Enable INT1 interrupt
	GICR |= (1 << INT1);
	
	// Enable global interrupts
	SREG |= (1 << 7);
}

// External Interrupt 2 Initialization with sense control
void EXTI_INT2_Init(uint8_t senseControl) {
	// Configure the interrupt sense control for INT2 (only falling/rising edge)
	if (senseControl == EXTI_INT2_RISING_EDGE) {
		MCUCSR |= (1 << ISC2);  // Set ISC2 for rising edge
		} else {
		MCUCSR &= ~(1 << ISC2); // Clear ISC2 for falling edge
	}

	// Enable INT2 interrupt
	GICR |= (1 << INT2);
	
	// Enable global interrupts
	SREG |= (1 << 7);
}

// Set the callback function for INT0
void EXTI_INT0_SetCallback(EXTI_Callback_t callback) {
	EXTI_INT0_Callback = callback;
}

// Set the callback function for INT1
void EXTI_INT1_SetCallback(EXTI_Callback_t callback) {
	EXTI_INT1_Callback = callback;
}

// Set the callback function for INT2
void EXTI_INT2_SetCallback(EXTI_Callback_t callback) {
	EXTI_INT2_Callback = callback;
}

// Interrupt Service Routine (ISR) for INT0
ISR(INT0_vect) {
	if (EXTI_INT0_Callback != 0) {
		EXTI_INT0_Callback();  // Call the registered callback
	}
}

// Interrupt Service Routine (ISR) for INT1
ISR(INT1_vect) {
	if (EXTI_INT1_Callback != 0) {
		EXTI_INT1_Callback();  // Call the registered callback
	}
}

// Interrupt Service Routine (ISR) for INT2
ISR(INT2_vect) {
	if (EXTI_INT2_Callback != 0) {
		EXTI_INT2_Callback();  // Call the registered callback
	}
}

