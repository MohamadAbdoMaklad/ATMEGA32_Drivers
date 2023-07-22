#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_
#include "ADC.h"

void Potentiometer_Init(ADC_InitTypes * OPTIONS);
U16 Potentiometer_Read(ADC_ChannelTypes Channel_NO);



#endif /* POTENTIOMETER_H_ */