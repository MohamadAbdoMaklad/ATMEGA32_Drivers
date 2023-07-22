#ifndef TIMER0_REGISTERS_H_
#define TIMER0_REGISTERS_H_

#include "STD_Types.h"
#include "DIO.h"
//========================(Control Registers)=================================
#define TIMER0_TCCR0_Register (*(volatile TIMER0_TCCR0_Types*)0x53)
//========================(	Data Registers)===================================
#define TIMER0_TCNT0_Register (*(volatile U8*)0x52)
#define TIMER0_OCR0_Register (*(volatile U8*)0x5C)
//========================(Interrupt Registers)================================
#define TIMER0_TIMSK_Register (*(volatile U8*)0x59)
#define TOIE0_Bit 0
#define OCIE0_Bit 1
#define TIMER0_TIFR_Register (*(volatile U8*)0x58)
#define TOV0_Bit 0
#define OCF0_Bit 1
//========================(Special FunctionIO Registers)========================
#define TIMER0_SFIOR_Register (*(volatile U8*)0x50)
#define PSR10_Bit 0
//========================(DIO Channal For Timer0)==============================
#define TIMER0_DIO_Channel DIO_ChannelB3
#endif /* TIMER0_REGISTERS_H_ */