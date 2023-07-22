#ifndef ADC_H_
#define ADC_H_
#include "ADC_Registers.h"
#include "ADC_Types.h"
#include "BitMath.h"
#include "DIO.h"
#include "Clock.h"
void ADC_Init (ADC_InitTypes * OPTIONS);
U16 ADC_READ (ADC_ChannelTypes CHANNEL_NO);

#endif