#ifndef TIMER1_H_
#define TIMER1_H_

#include "Timer1_registers.h"
#include "Timer1_Types.h"

void TIMER1_Init(TIMER1_InitTypet * OPTIONS);
void TIMER1_OCR1A_SetValue(U16 VALUE);
void TIMER1_OCR1B_SetValue(U16 VALUE);
void TIMER1_ICR1_SetValue(U16 VALUE);
void TIMER1_TCNT1_SetValue(U16 value);


#endif /* TIMER1_H_ */