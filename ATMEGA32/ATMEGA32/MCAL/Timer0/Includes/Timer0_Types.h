#ifndef TIMER0_TYPES_H_
#define TIMER0_TYPES_H_

//(TIMER0_TCCR0_Register)
typedef struct
{
	U8 CS00_Bit	:1;
	U8 CS01_Bit	:1;
	U8 CS02_Bit	:1;
	U8 WGM01_Bit:1;
	U8 COM00_Bit:1;
	U8 COM01_Bit:1;
	U8 WGM00_Bit:1;
	U8 FOC0_Bit	:1;
}TIMER0_TCCR0_Bits;

typedef union
{
	U8 AllRegister;
	TIMER0_TCCR0_Bits Bits;	
}TIMER0_TCCR0_Types;

//													WGM01	WGM00
typedef enum
{
	TIMER0_Normal = 0,									//0		0
	TIMER0_PWM_PC,										//0		1
	TIMER0_CTC,											//1		0
	TIMER0_PWM_Fast										//1		1
}TIMER0_Mode_Select;

//													CS02	CS01	CS00 
typedef enum
{
	TIMER0_No_Clock=0,								//0		0		0
	TIMER0_No_Prescaling,							//0		0		1
	TIMER0_Clk_8,									//0		1		0
	TIMER0_Clk_64,									//0		1		1
	TIMER0_Clk_256,									//1		0		0
	TIMER0_Clk_1024,								//1		0		1
	TIMER0_Clk_External_T1Pin_FallingEdge,			//1		1		0
	TIMER0_Clk_External_T1Pin_RisingEdge			//1		1		1
}TIMER0_Prescaling_Select;


//(Compare Match Output Mode)
//													COM01	COM00
typedef enum
{
	TIMER0_NON_PWM_Normal_OC0Disconnected=0,				//0		0
	TIMER0_NON_PWM_TOGGLE_OCR_OnCompareMatch,				//0		1
	TIMER0_NON_PWM_CLEAR_OCR_OnCompareMatch,				//1		0
	TIMER0_NON_PWM_SET_OCR_OnCompareMatch					//1		1
	
}TIMER0_OUTPUT_COMPARE_NON_PWM_Mode;
typedef enum
{
	TIMER0_PWM_Normal_Port_Operation_OC0Disconnected=0,	//0		0
	TIMER0_PWM_Non_Inverting=2,							//1		0
	TIMER0_PWM_Inverting									//1		1	
}TIMER0_OUTPUT_COMPARE_PWM_Mode;

typedef enum
{
	TIMER0_NON_PWM_Mode=0,
	TIMER0_PWM_Mode
}TIMER0_COM0_Mode;

typedef enum
{
	TIMER0_Interrupt_Disable=0,
	TIMER0_Interrupt_Enable
}TIMER0_Interrupt_State_Types;

typedef enum
{
	TIMER0_Interrupt_Flag_LOW=0,
	TIMER0_Interrupt_Flag_HIGh
}TIMER0_Interrupt_Flag_Value;

typedef struct
{
	TIMER0_Mode_Select MODE;
	TIMER0_Prescaling_Select PRESCALIG;
	TIMER0_COM0_Mode COM0_Mode;
	TIMER0_OUTPUT_COMPARE_NON_PWM_Mode PWM_Mode;
	TIMER0_OUTPUT_COMPARE_PWM_Mode NON_PWM_Mode;
}TIMER0_InitTypes;
#endif /* TIMER0_TYPES_H_ */