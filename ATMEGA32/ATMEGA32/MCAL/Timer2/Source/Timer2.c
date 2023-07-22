#include "Timer2.h"
void TIMER2_Init(TIMER2_InitTypes * OPTIONS)
{
	//DIO_ConfigChannel(TIMER2_DIO_Channel,OUTPUT);
	switch(OPTIONS -> MODE)
	{
		case TIMER2_Normal:
		TIMER2_TCCR2_Register.Bits.WGM20_Bit =0;
		TIMER2_TCCR2_Register.Bits.WGM21_Bit =0;
		break;
		case TIMER2_PWM_PC:
		TIMER2_TCCR2_Register.Bits.WGM20_Bit =1;
		TIMER2_TCCR2_Register.Bits.WGM21_Bit =0;
		break;
		case TIMER2_CTC:
		TIMER2_TCCR2_Register.Bits.WGM20_Bit =0;
		TIMER2_TCCR2_Register.Bits.WGM21_Bit =1;
		break;
		case TIMER2_PWM_Fast:
		TIMER2_TCCR2_Register.Bits.WGM20_Bit =1;
		TIMER2_TCCR2_Register.Bits.WGM21_Bit =1;
		break;
	};
	switch(OPTIONS -> COM0_Mode)
	{
		case TIMER2_NON_PWM_Mode:
		TIMER2_TCCR2_Register.AllRegister |= ((OPTIONS -> NON_PWM_Mode)<<4); break;
		case TIMER2_PWM_Mode:
		TIMER2_TCCR2_Register.AllRegister |= ((OPTIONS -> PWM_Mode)<<4); break;
	};
	TIMER2_TCCR2_Register.AllRegister |= ((OPTIONS -> PRESCALIG)<<0);
	switch(OPTIONS -> Clock_Source)
	{
		case IO_Clock: ClearBit(TIMER2_ASSR_Register,AS2_Bit);break;
		default:SetBit(TIMER2_ASSR_Register,AS2_Bit);
	};
	
}
void TIMER2_OFF(void)
{
	TIMER2_TCCR2_Register.Bits.CS20_Bit = 0;
	TIMER2_TCCR2_Register.Bits.CS21_Bit = 0;
	TIMER2_TCCR2_Register.Bits.CS22_Bit = 0;
}
void TIMER2_OCR2_SetValue(U8 OCR_Value)
{
	TIMER2_OCR2_Register = OCR_Value;
}
void TIMER2_TCNT2_SetValue(U8 TCNT_Value)
{
	TIMER2_TCNT2_Register = TCNT_Value;
}
void TIMER2_OverFlow_Interrupt_State(TIMER2_Interrupt_State_Types State)
{
	switch(State)
	{
		case TIMER2_Interrupt_Enable:
		SetBit(TIMER2_TIMSK_Register,TOIE2_Bit);
		break;
		case TIMER2_Interrupt_Disable:
		ClearBit(TIMER2_TIMSK_Register,TOIE2_Bit);
		break;
	};
}
void TIMER2_OutputCompareMatch_Interrupt_State(TIMER2_Interrupt_State_Types State)
{
	switch(State)
	{
		case TIMER2_Interrupt_Enable:
		SetBit(TIMER2_TIMSK_Register,OCIE2_Bit);
		break;
		case TIMER2_Interrupt_Disable:
		ClearBit(TIMER2_TIMSK_Register,OCIE2_Bit);
		break;
	};
}

TIMER2_Interrupt_Flag_Value TIMER2_OverFlow_Flag_State(void)
{
	switch (GetBit(TIMER2_TIFR_Register,TOV2_Bit))
	{
		case 0: return TIMER2_Interrupt_Flag_LOW; break;
		case 1: return TIMER2_Interrupt_Flag_HIGh; break;
		default: return TIMER2_Interrupt_Flag_LOW;
	};
}

TIMER2_Interrupt_Flag_Value TIMER2_OutputCompareMatch_Flag_State(void)
{
	switch (GetBit(TIMER2_TIFR_Register,OCF2_Bit))
	{
		case 0: return TIMER2_Interrupt_Flag_LOW; break;
		case 1: return TIMER2_Interrupt_Flag_HIGh; break;
		default: return TIMER2_Interrupt_Flag_LOW;
	};
}

void TIMER2_Clear_OverFlow_Flag(void)
{
	SetBit(TIMER2_TIFR_Register,TOV2_Bit);
}

void TIMER2_Clear_OutputCompareMatch_Flag(void)
{
	SetBit(TIMER2_TIFR_Register,OCF2_Bit);
}
void TIMER2_Prescaller_Reset(void)
{
	SetBit(TIMER2_SFIOR_Register,PSR2_Bit);
}
TIMER2_ASYNCHRONOUS_UPDATE_STATE TIMER2_GET_TCNT0_UPDATE_State(void)
{
	return GetBit(TIMER2_ASSR_Register,TCN2UB_Bit);
}
TIMER2_ASYNCHRONOUS_UPDATE_STATE TIMER2_GET_TCCR0_UPDATE_State(void)
{
	return GetBit(TIMER2_ASSR_Register,TCR2UB_Bit);
}
TIMER2_ASYNCHRONOUS_UPDATE_STATE TIMER2_GET_OCR0_UPDATE_State(void)
{
	return GetBit(TIMER2_ASSR_Register,OCR2UB_Bit);
}