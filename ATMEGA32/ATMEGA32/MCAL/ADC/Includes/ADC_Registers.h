#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_
#include "STD_Types.h"

#define ADC_ADMUX_Register (*((volatile U8*)0x27))
#define ADC_ADCSRA_Register (*((volatile U8*)0x26))
#define ADC_ADCL_Register (*((volatile U8*)0x24))
#define ADC_ADCH_Register (*((volatile U8*)0x25))

#define ADC_ADCSRA_ADEN_Bit 7
#define ADC_ADCSRA_ADSC_Bit 6
#define ADC_ADCSRA_ADIF_Bit 4

#endif