#include <avr/io.h>
#include "../MCAL/CONFIG/CPU_Configuration.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LM35/LM35_Interface.h"
#include "../HAL/KEYPAD/KEYPAD_Interface.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/TIMERS/TIMER0/TMR0_Interface.h"

uint8_t switch_state = 0;
uint8_t threshold = 28;
uint8_t lm_read = 0;

void send()
{
		switch_state = SPI_Transceive(lm_read);
		_delay_ms(100);
		SPI_Transmit(threshold);
}

int main(void)
{
	SPI_InitMaster(SPI_MODE_1, SPI_MSB_FIRST, SPI_CLOCK_DIV128);
	TMR0_Init();
	TMR0_Start(1000);
	TMR0_SetCallback(&send);
    LCD_Initialize();
	LM35_Init();
	Keypad_Initialize();
	uint8_t key_pad_read = 0;
	
    while (1) 
    {
		key_pad_read = Keypad_Read();
		if (key_pad_read == 'C')
		{
			threshold = 0;
			while(1)
			{
				key_pad_read = Keypad_Read();
				if (key_pad_read != 0)
				{
					if(key_pad_read == '=')break;
					threshold = threshold*10 + (key_pad_read-'0');
				}
			}
		}
		LCD_Write_Location(ROW0, COL0);
		LCD_Write_String((uint8_t *)"Current temperature:");
		lm_read = LM35_ReadTemperature();
		LCD_Write_Location(ROW1, COL0);
		LCD_Write_IntegerNumber((uint32_t)lm_read);
		LCD_Write_Location(ROW2, COL0);
		LCD_Write_String((uint8_t *)"Threshold: ");
		LCD_Write_Location(ROW2, COL13);
		LCD_Write_IntegerNumber(threshold);
		LCD_Write_Location(ROW3, COL0);
		LCD_Write_String((uint8_t *)"switch for ");
		LCD_Write_Location(ROW3, COL12);
		if(switch_state)LCD_Write_String((uint8_t *)"Auto  ");
		else LCD_Write_String((uint8_t *)"Manual");
    }
}


