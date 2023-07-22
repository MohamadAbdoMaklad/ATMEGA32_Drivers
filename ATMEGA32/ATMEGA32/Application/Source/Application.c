#include "Modules_Includes.h"
#include "Application.h"

void Potentiometer_With_ADC (void)
{
	DIO_Init();
	LCD_Init();
	LCD_Clear();
	ADC_InitTypes POT_Options = {ADC_Prescaler128,ADC_Vref_Internal};
	Potentiometer_Init(&POT_Options);
	U16 ADC_Read_Value = 0;
	S8 ADC_Read_Value_String[10];
	while (1)
	{
		ADC_Read_Value = Potentiometer_Read(ADC_Channel1);
		itoa(ADC_Read_Value,ADC_Read_Value_String,10);
		LCD_SetPosition(1,0);
		LCD_String(ADC_Read_Value_String);
		_delay_ms(200);
		LCD_Clear();
		
	}
}