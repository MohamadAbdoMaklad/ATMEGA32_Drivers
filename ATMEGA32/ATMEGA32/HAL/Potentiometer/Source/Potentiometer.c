#include "Potentiometer.h"
void Potentiometer_Init(ADC_InitTypes * OPTIONS)
{
	ADC_Init(OPTIONS);
}
U16 Potentiometer_Read(ADC_ChannelTypes Channel_NO)
{
	return ADC_READ(Channel_NO)/4;
}
