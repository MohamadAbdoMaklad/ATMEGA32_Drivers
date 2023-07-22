#include "Timer0.h"
void TIMER0_Init(TIMER0_InitTypes * OPTIONS)
{
	//DIO_ConfigChannel(TIMER0_DIO_Channel,OUTPUT);
	switch(OPTIONS -> MODE)
	{
		case TIMER0_Normal:
		TIMER0_TCCR0_Register.Bits.WGM00_Bit =0;
		TIMER0_TCCR0_Register.Bits.WGM01_Bit =0;
		break;
		case TIMER0_PWM_PC:
		TIMER0_TCCR0_Register.Bits.WGM00_Bit =1;
		TIMER0_TCCR0_Register.Bits.WGM01_Bit =0;
		break;
		case TIMER0_CTC:
		TIMER0_TCCR0_Register.Bits.WGM00_Bit =0;
		TIMER0_TCCR0_Register.Bits.WGM01_Bit =1;
		break;
		case TIMER0_PWM_Fast:
		TIMER0_TCCR0_Register.Bits.WGM00_Bit =1;
		TIMER0_TCCR0_Register.Bits.WGM01_Bit =1;
		break;
	};
	switch(OPTIONS -> COM0_Mode)
	{
		case TIMER0_NON_PWM_Mode:
		TIMER0_TCCR0_Register.AllRegister |= ((OPTIONS -> NON_PWM_Mode)<<4); break;
		case TIMER0_PWM_Mode:
		TIMER0_TCCR0_Register.AllRegister |= ((OPTIONS -> PWM_Mode)<<4); break;
	};
	TIMER0_TCCR0_Register.AllRegister |= ((OPTIONS -> PRESCALIG)<<0);
	
}
void TIMER0_OFF(void)
{
	TIMER0_TCCR0_Register.Bits.CS00_Bit = 0;
	TIMER0_TCCR0_Register.Bits.CS01_Bit = 0;
	TIMER0_TCCR0_Register.Bits.CS02_Bit = 0;
}
void TIMER0_OCR0_SetValue(U8 OCR_Value)
{
	TIMER0_OCR0_Register = OCR_Value;
}
void TIMER0_TCNT0_SetValue(U8 TCNT_Value)
{
	TIMER0_TCNT0_Register = TCNT_Value;
}
void TIMER0_OverFlow_Interrupt_State(TIMER0_Interrupt_State_Types State)
{
	switch(State)
	{
		case TIMER0_Interrupt_Enable:
		SetBit(TIMER0_TIMSK_Register,TOIE0_Bit);
		break;
		case TIMER0_Interrupt_Disable:
		ClearBit(TIMER0_TIMSK_Register,TOIE0_Bit);
		break;
	};
}
void TIMER0_OutputCompareMatch_Interrupt_State(TIMER0_Interrupt_State_Types State)
{
	switch(State)
	{
		case TIMER0_Interrupt_Enable:
		SetBit(TIMER0_TIMSK_Register,OCIE0_Bit);
		break;
		case TIMER0_Interrupt_Disable:
		ClearBit(TIMER0_TIMSK_Register,OCIE0_Bit);
		break;
	};
}

TIMER0_Interrupt_Flag_Value TIMER0_OverFlow_Flag_State(void)
{
	switch (GetBit(TIMER0_TIFR_Register,TOV0_Bit))
	{
		case 0: return TIMER0_Interrupt_Flag_LOW; break;
		case 1: return TIMER0_Interrupt_Flag_HIGh; break;
		default: return TIMER0_Interrupt_Flag_LOW;
	};
}

TIMER0_Interrupt_Flag_Value TIMER0_OutputCompareMatch_Flag_State(void)
{
	switch (GetBit(TIMER0_TIFR_Register,OCF0_Bit))
	{
		case 0: return TIMER0_Interrupt_Flag_LOW; break;
		case 1: return TIMER0_Interrupt_Flag_HIGh; break;
		default: return TIMER0_Interrupt_Flag_LOW;
	};
}

void TIMER0_Clear_OverFlow_Flag(void)
{
	SetBit(TIMER0_TIFR_Register,TOV0_Bit);
}

void TIMER0_Clear_OutputCompareMatch_Flag(void)
{
	SetBit(TIMER0_TIFR_Register,OCF0_Bit);
}
void TIMER0_Prescaller_Reset(void)
{
	SetBit(TIMER0_SFIOR_Register,PSR10_Bit);
}

void DELAY_MS(U32 TimeMS)
{
	TIMER0_InitTypes Options;
	Options.MODE=TIMER0_Normal;
	Options.COM0_Mode=TIMER0_NON_PWM_Mode;
	Options.NON_PWM_Mode=TIMER0_NON_PWM_Normal_OC0Disconnected;
	Options.PWM_Mode=TIMER0_PWM_Non_Inverting;
	Options.PRESCALIG=TIMER0_Clk_1024;
	TIMER0_Init(&Options);
	U32 i;
	for(i=0;i<TimeMS;i++)
	{
		TIMER0_TCNT0_SetValue(240);
		while(TIMER0_OverFlow_Flag_State()==TIMER0_Interrupt_Flag_LOW);
		//TIMER0_OFF();
		TIMER0_Clear_OutputCompareMatch_Flag();
	}
}