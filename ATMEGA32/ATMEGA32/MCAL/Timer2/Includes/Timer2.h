#include "Timer2_registers.h"
#include "Timer2_Types.h"
#include "BitMath.h"
#include "Clock.h"
#ifndef TIMER2_H_
#define TIMER2_H_

void TIMER2_Init(TIMER2_InitTypes * OPTIONS);

void TIMER2_OFF(void);

void TIMER2_OCR2_SetValue(U8 OCR_Value);
void TIMER2_TCNT2_SetValue(U8 TCNT_Value);

void TIMER2_OverFlow_Interrupt_State(TIMER2_Interrupt_State_Types State);
void TIMER2_OutputCompareMatch_Interrupt_State(TIMER2_Interrupt_State_Types State);

TIMER2_Interrupt_Flag_Value TIMER2_OverFlow_Flag_State(void);
TIMER2_Interrupt_Flag_Value TIMER2_OutputCompareMatch_Flag_State(void);

void TIMER2_Clear_OverFlow_Flag(void);
void TIMER2_Clear_OutputCompareMatch_Flag(void);

void TIMER2_Prescaller_Reset(void);

TIMER2_ASYNCHRONOUS_UPDATE_STATE TIMER2_GET_TCNT0_UPDATE_State(void);
TIMER2_ASYNCHRONOUS_UPDATE_STATE TIMER2_GET_TCCR0_UPDATE_State(void);
TIMER2_ASYNCHRONOUS_UPDATE_STATE TIMER2_GET_OCR0_UPDATE_State(void);

#endif /* TIMER2_H_ */