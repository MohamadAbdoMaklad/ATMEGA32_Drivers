#include "Timer1.h"
void TIMER1_Init(TIMER1_InitTypet * OPTIONS)
{
	switch(OPTIONS -> MODE)
	{
		case Normal:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 0;
		break;
		case PWM_PC_8Bit:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 1;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 0;
		break;
		case PWM_PC_9Bit:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 0;
		break;
		case PWM_PC_10Bit:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 1;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 0;
		break;
		case CTC_OCR1A_TopRegister:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 0;
		break;
		case PWM_Fast_8Bit:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 1;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 0;
		break;
		case PWM_Fast_9Bit:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 0;
		break;
		case PWM_Fast_10Bit:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 1;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 0;
		break;
		case PWM_PC_FC_ICR1_TopRegister:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 1;
		break;
		case PWM_PC_FC_OCR1A_TopRegister:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 1;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 1;
		break;
		case PWM_PC_ICR1_TopRegister:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 1;
		break;
		case PWM_PC_OCR1A_TopRegister:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 1;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 1;
		break;
		case CTC_ICR1_TopRegister:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 0;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 1;
		break;
		case RESERVED:
		break;
		case PWM_Fast_ICR1_TopRegister:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 0;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 1;
		break;
		case PWM_Fast_OCR1A_TopRegister:
		TIMER1_TCCR1A_Registers.Bits.WGM10_Bit = 1;
		TIMER1_TCCR1A_Registers.Bits.WGM11_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM12_Bit = 1;
		TIMER1_TCCR1B_Registers.Bits.WGM13_Bit = 1;
		break;
	};
	TIMER1_TCCR1B_Registers.AllRegister |= ((OPTIONS -> PRESCALING)<<0);
	TIMER1_TCCR1A_Registers.AllRegister |= ((OPTIONS -> COM1A_Mode)<<6);
	TIMER1_TCCR1A_Registers.AllRegister |= ((OPTIONS -> COM1B_Mode)<<4);
}
void TIMER1_OCR1A_SetValue(U16 VALUE)
{
	TIMER1_OCR1A_Registers = VALUE;
}
void TIMER1_OCR1B_SetValue(U16 VALUE)
{
	TIMER1_OCR1B_Registers = VALUE;
}
void TIMER1_ICR1_SetValue(U16 VALUE)
{
	TIMER1_ICR1_Registers = VALUE;
}
void TIMER1_TCNT1_SetValue(U16 value){
	TIMER1_TCNT1_Registers = value;
}