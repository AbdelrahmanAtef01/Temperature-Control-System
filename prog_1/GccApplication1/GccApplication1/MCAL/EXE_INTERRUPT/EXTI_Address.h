#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_


// Define volatile pointers to memory-mapped I/O registers

// MCU Control Register (used for INT0 and INT1 sense control)
#define MCUCR   (*(volatile uint8_t*)0x55)

// MCU Control and Status Register (used for INT2 sense control)
#define MCUCSR  (*(volatile uint8_t*)0x54)

// General Interrupt Control Register (used to enable/disable INT0, INT1, INT2)
#define GICR    (*(volatile uint8_t*)0x5B)

// General Interrupt Flag Register (used to check interrupt flags)
#define GIFR    (*(volatile uint8_t*)0x5A)

// Status Register (used for global interrupt enable)
#define SREG    (*(volatile uint8_t*)0x5F)

// Define the bit positions for each interrupt control
// INT0 and INT1 sense control (MCUCR)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

// INT2 sense control (MCUCSR)
#define ISC2    6

// Interrupt Enable Bits (GICR)
#define INT2    5
#define INT0    6
#define INT1    7

// Interrupt Flag Bits (GIFR)
#define INTF0   6
#define INTF1   7
#define INTF2   5

#endif /* EXTI_REGISTER_H_ */
