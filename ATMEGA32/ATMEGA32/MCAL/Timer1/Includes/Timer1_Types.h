#ifndef TIMER1_TYPES_H_
#define TIMER1_TYPES_H_

typedef struct 
{
	U8 WGM10_Bit:1;
	U8 WGM11_Bit:1;
	U8 FOC1B_Bit:1;
	U8 FOC1A_Bit:1;
	U8 COM1B0_Bit:1;
	U8 COM1B1_Bit:1;
	U8 COM1A0_Bit:1;
	U8 COM1A1_Bit:1;
}TIMER1_TCCR1A_Bits;

typedef union{
	U8 AllRegister;
	TIMER1_TCCR1A_Bits Bits;
}TIMER1_TCCR1A_Types;


typedef struct
{
	U8 CS10_Bit:1;
	U8 CS11_Bit:1;
	U8 CS12_Bit:1;
	U8 WGM12_Bit:1;
	U8 WGM13_Bit:1;
	U8 RESERVED_Bit:1;
	U8 ICES1_Bit:1;
	U8 ICNC1_Bit:1;
}TIMER1_TCCR1B_Bits;

typedef union{
	U8 AllRegister;
	TIMER1_TCCR1B_Bits Bits;
}TIMER1_TCCR1B_Types;


typedef enum
{
	No_Clock=0,
	No_Prescaling,
	Clk_8,
	Clk_64,
	Clk_256,
	Clk_1024,
	Clk_External_T1Pin_FallingEdge,
	Clk_External_T1Pin_RisingEdge
}TIMER1_Prescaling_Select;

typedef enum 
{
	Normal=0,
	PWM_PC_8Bit,
	PWM_PC_9Bit,
	PWM_PC_10Bit,
	CTC_OCR1A_TopRegister,
	PWM_Fast_8Bit,
	PWM_Fast_9Bit,
	PWM_Fast_10Bit,
	PWM_PC_FC_ICR1_TopRegister,
	PWM_PC_FC_OCR1A_TopRegister,
	PWM_PC_ICR1_TopRegister,
	PWM_PC_OCR1A_TopRegister,
	CTC_ICR1_TopRegister,
	RESERVED,
	PWM_Fast_ICR1_TopRegister,
	PWM_Fast_OCR1A_TopRegister
}TIMER1_Mode_Select;

typedef enum
{
	COM1A_Disable=0,
	COM1A_Non_Inverting=2,
	COM1A_Inverting
}TIMER1_COM1A_Mode;

typedef enum
{
	COM1B_Disable=0,
	COM1B_Non_Inverting=2,
	COM1B_Inverting
}TIMER1_COM1B_Mode;

typedef struct
{
	TIMER1_Mode_Select MODE;
	TIMER1_Prescaling_Select PRESCALING;
	TIMER1_COM1A_Mode COM1A_Mode;
	TIMER1_COM1B_Mode COM1B_Mode;
}TIMER1_InitTypet;

#endif /* TIMER1_TYPES_H_ */