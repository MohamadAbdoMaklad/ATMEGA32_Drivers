#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

typedef enum{
	ADC_Channel0=0,
	ADC_Channel1,
	ADC_Channel2,
	ADC_Channel3,
	ADC_Channel4,
	ADC_Channel5,
	ADC_Channel6,
	ADC_Channel7
}ADC_ChannelTypes;

typedef enum{
	ADC_Prescaler2=1,
	ADC_Prescaler4,
	ADC_Prescaler8,
	ADC_Prescaler16,
	ADC_Prescaler32,
	ADC_Prescaler64,
	ADC_Prescaler128
}ADC_PrescalerTypes;

typedef enum{
	ADC_Vref_Aref=0,
	ADC_Vref_Avcc,
	ADC_Vref_Reserved,
	ADC_Vref_Internal
}ADC_VrefTypes;

typedef struct{
	ADC_PrescalerTypes adcClock;
	ADC_VrefTypes adcVref;
}ADC_InitTypes;

#endif