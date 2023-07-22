#include "TIMER1_PWM.h"
void PWM_T1_Generate_COM1A(U16 DutyCycle)
{
	DIO_ConfigChannel(DIO_ChannelD5,OUTPUT);
	U16 ICR_Value = 0xFFFF;
	U16 OCR1A_Value = (U16)((((float)DutyCycle/100)*((U32)ICR_Value+1))-1);
	TIMER1_OCR1A_SetValue(OCR1A_Value);
	TIMER1_ICR1_SetValue(ICR_Value);
	TIMER1_InitTypet TIMER1_PWM_OPTIONS = {PWM_Fast_ICR1_TopRegister,Clk_64,COM1A_Non_Inverting,COM1B_Disable};
	TIMER1_Init(&TIMER1_PWM_OPTIONS);
	
	
}
void PWM_T2_Generate_COM1B(U16 DutyCycle)
{
	DIO_ConfigChannel(DIO_ChannelD4,OUTPUT);
	U16 ICR_Value = 0xFFFF;
	U16 OCR1B_Value = (U16)((((float)DutyCycle/100)*((U32)ICR_Value+1))-1);
	TIMER1_OCR1B_SetValue(OCR1B_Value);
	TIMER1_ICR1_SetValue(ICR_Value);
	TIMER1_InitTypet TIMER1_PWM_OPTIONS = {PWM_Fast_ICR1_TopRegister,Clk_64,COM1A_Disable,COM1B_Inverting};
	TIMER1_Init(&TIMER1_PWM_OPTIONS);
}