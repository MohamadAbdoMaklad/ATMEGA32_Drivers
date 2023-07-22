#ifndef TIMER1_REGISTERS_H_
#define TIMER1_REGISTERS_H_

#include "STD_Types.h"
#define TIMER1_TCCR1A_Registers (*(volatile TIMER1_TCCR1A_Types*)0x4F)
#define TIMER1_TCCR1B_Registers (*(volatile TIMER1_TCCR1B_Types*)0x4E)
#define TIMER1_OCR1A_Registers (*(volatile U8*)0x4A)
#define TIMER1_TCNT1_Registers (*(volatile U16*)0x4C)
#define TIMER1_OCR1B_Registers (*(volatile U8*)0x48)
#define TIMER1_ICR1_Registers (*(volatile U8*)0x46)
#define TIMER1_TIMSK_Registers (*(volatile U8*)0x59)
#define TIMER1_TIFR_Registers (*(volatile u16*)0x58)

#endif /* TIMER1_REGISTERS_H_ */