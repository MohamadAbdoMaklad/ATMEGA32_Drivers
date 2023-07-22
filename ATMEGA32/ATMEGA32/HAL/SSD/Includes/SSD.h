#ifndef SSD_H_
#define SSD_H_
#include "DIO.h"
#include "Clock.h"
#include "SSD_Config.h"
void SSD_Init(void);
void SSD_Display(float Num);
void SSD_Display_With_Delay(float Num , U32 Delay);
#endif