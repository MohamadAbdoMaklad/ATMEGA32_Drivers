#include "ADC.h"
void ADC_Init (ADC_InitTypes * OPTIONS)
{
	ADC_ADMUX_Register = ((OPTIONS->adcVref)<<6);//set Vref
	ClearBit(ADC_ADMUX_Register,5);
	ADC_ADCSRA_Register = (1<<ADC_ADCSRA_ADEN_Bit)|(OPTIONS->adcClock);//Enable ADC & Prescaler
}
U16 ADC_READ (ADC_ChannelTypes CHANNEL_NO)
{
	switch (CHANNEL_NO){
	case ADC_Channel0:DIO_ConfigChannel(DIO_ChannelA0,INPUT);break;
	case ADC_Channel1:DIO_ConfigChannel(DIO_ChannelA1,INPUT);break;
	case ADC_Channel2:DIO_ConfigChannel(DIO_ChannelA2,INPUT);break;
	case ADC_Channel3:DIO_ConfigChannel(DIO_ChannelA3,INPUT);break;
	case ADC_Channel4:DIO_ConfigChannel(DIO_ChannelA4,INPUT);break;
	case ADC_Channel5:DIO_ConfigChannel(DIO_ChannelA5,INPUT);break;
	case ADC_Channel6:DIO_ConfigChannel(DIO_ChannelA6,INPUT);break;
	case ADC_Channel7:DIO_ConfigChannel(DIO_ChannelA7,INPUT);break;
	}
	U16 ReadValue = 0;
	ADC_ADMUX_Register = (ADC_ADMUX_Register & 0b11100000)|(CHANNEL_NO & 0b00011111);
	SetBit(ADC_ADCSRA_Register,ADC_ADCSRA_ADSC_Bit);//start Conv.
	while(GetBit(ADC_ADCSRA_Register,ADC_ADCSRA_ADIF_Bit) == 0);//Waiting to finish the Conv.
	SetBit(ADC_ADCSRA_Register,ADC_ADCSRA_ADIF_Bit);//Clear the Flag
	ReadValue = (ADC_ADCL_Register)|(ADC_ADCH_Register<<8);
	//_delay_ms(1); 
	return ReadValue;
}
