#ifndef TIMER2_TYPES_H_
#define TIMER2_TYPES_H_
//(TIMER2_TCCR2_Register)
typedef struct
{
	U8 CS20_Bit	:1;
	U8 CS21_Bit	:1;
	U8 CS22_Bit	:1;
	U8 WGM21_Bit:1;
	U8 COM20_Bit:1;
	U8 COM21_Bit:1;
	U8 WGM20_Bit:1;
	U8 FOC2_Bit	:1;
}TIMER2_TCCR2_Bits;

typedef union
{
	U8 AllRegister;
	TIMER2_TCCR2_Bits Bits;
}TIMER2_TCCR2_Types;

//													WGM21	WGM20
typedef enum
{
	TIMER2_Normal = 0,									//0		0
	TIMER2_PWM_PC,										//0		1
	TIMER2_CTC,											//1		0
	TIMER2_PWM_Fast										//1		1
}TIMER2_Mode_Select;

//													CS22	CS21	CS20
typedef enum
{
	TIMER2_No_Clock=0,								//0		0		0
	TIMER2_No_Prescaling,							//0		0		1
	TIMER2_Clk_8,									//0		1		0
	TIMER2_Clk_64,									//0		1		1
	TIMER2_Clk_256,									//1		0		0
	TIMER2_Clk_1024,								//1		0		1
	TIMER2_Clk_External_T1Pin_FallingEdge,			//1		1		0
	TIMER2_Clk_External_T1Pin_RisingEdge			//1		1		1
}TIMER2_Prescaling_Select;


//(Compare Match Output Mode)
//															COM21	COM20
typedef enum
{
	TIMER2_NON_PWM_Normal_OC0Disconnected=0,				//0		0
	TIMER2_NON_PWM_TOGGLE_OCR_OnCompareMatch,				//0		1
	TIMER2_NON_PWM_CLEAR_OCR_OnCompareMatch,				//1		0
	TIMER2_NON_PWM_SET_OCR_OnCompareMatch					//1		1
	
}TIMER2_OUTPUT_COMPARE_NON_PWM_Mode;
typedef enum
{
	TIMER2_PWM_Normal_Port_Operation_OC0Disconnected=0,		//0		0
	TIMER2_PWM_Non_Inverting=2,								//1		0
	TIMER2_PWM_Inverting									//1		1
}TIMER2_OUTPUT_COMPARE_PWM_Mode;

typedef enum
{
	TIMER2_NON_PWM_Mode=0,
	TIMER2_PWM_Mode
}TIMER2_COM2_Mode;

typedef enum
{
	TIMER2_Interrupt_Disable=0,
	TIMER2_Interrupt_Enable
}TIMER2_Interrupt_State_Types;

typedef enum
{
	TIMER2_Interrupt_Flag_LOW=0,
	TIMER2_Interrupt_Flag_HIGh
}TIMER2_Interrupt_Flag_Value;

typedef enum
{
	IO_Clock=0,
	Crystal_Osc_Connectes	
}TIMER2_ASYNCHRONOUS_CLOCK_SOURCE;

typedef enum
{
	UPDARE_DONE=0,
	UPDATE_NOT_DONE
}TIMER2_ASYNCHRONOUS_UPDATE_STATE;


typedef struct
{
	TIMER2_Mode_Select MODE;
	TIMER2_Prescaling_Select PRESCALIG;
	TIMER2_COM2_Mode COM0_Mode;
	TIMER2_OUTPUT_COMPARE_NON_PWM_Mode PWM_Mode;
	TIMER2_OUTPUT_COMPARE_PWM_Mode NON_PWM_Mode;
	TIMER2_ASYNCHRONOUS_CLOCK_SOURCE Clock_Source;
}TIMER2_InitTypes;

#endif /* TIMER2_TYPES_H_ */