#ifndef TIMER2_REGISTERS_H_
#define TIMER2_REGISTERS_H_
#include "STD_Types.h"
#include "DIO.h"
//========================(Control Registers)=================================
#define TIMER2_TCCR2_Register (*(volatile TIMER2_TCCR2_Types*)0x45)
//========================(	Data Registers)===================================
#define TIMER2_TCNT2_Register (*(volatile U8*)0x44)
#define TIMER2_OCR2_Register (*(volatile U8*)0x43)
//========================(Asynchronous State)=================================
#define TIMER2_ASSR_Register (*(volatile U8*)0x42)
#define AS2_Bit 3
#define TCN2UB_Bit 2
#define OCR2UB_Bit 1
#define TCR2UB_Bit 0
//========================(Interrupt Registers)================================
#define TIMER2_TIMSK_Register (*(volatile U8*)0x59)
#define TOIE2_Bit 6
#define OCIE2_Bit 7
#define TIMER2_TIFR_Register (*(volatile U8*)0x58)
#define TOV2_Bit 6
#define OCF2_Bit 7
//========================(Special FunctionIO Registers)========================
#define TIMER2_SFIOR_Register (*(volatile U8*)0x50)
#define PSR2_Bit 1
//========================(DIO Channal For Timer0)==============================
#define TIMER2_DIO_Channel DIO_ChannelB3
#endif /* TIMER2_REGISTERS_H_ */