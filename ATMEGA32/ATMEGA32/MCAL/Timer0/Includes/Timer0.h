#include "Timer0_registers.h"
#include "Timer0_Types.h"
#include "BitMath.h"
#include "Clock.h"
#ifndef TIMER0_H_
#define TIMER0_H_

void TIMER0_Init(TIMER0_InitTypes * OPTIONS);

void TIMER0_OFF(void);

void TIMER0_OCR0_SetValue(U8 OCR_Value);
void TIMER0_TCNT0_SetValue(U8 TCNT_Value);

void TIMER0_OverFlow_Interrupt_State(TIMER0_Interrupt_State_Types State);
void TIMER0_OutputCompareMatch_Interrupt_State(TIMER0_Interrupt_State_Types State);

TIMER0_Interrupt_Flag_Value TIMER0_OverFlow_Flag_State(void);
TIMER0_Interrupt_Flag_Value TIMER0_OutputCompareMatch_Flag_State(void);

void TIMER0_Clear_OverFlow_Flag(void);
void TIMER0_Clear_OutputCompareMatch_Flag(void);

void TIMER0_Prescaller_Reset(void);

void DELAY_MS(U32 TimeMS);

#endif /* TIMER0_H_ */