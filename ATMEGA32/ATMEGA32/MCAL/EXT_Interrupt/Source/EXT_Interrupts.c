#include "EXT_Interrupts.h"

void (*EXT_INTERRUPT0_FUNCTION_PTR)(void) = 0;
void (*EXT_INTERRUPT1_FUNCTION_PTR)(void) = 0;
void (*EXT_INTERRUPT2_FUNCTION_PTR)(void) = 0;


void EXT_INTERRUPTS_STATE(EXT_INTERRUPT_Types INTERRUPT_NO,EXT_INTERRUPT_STATE_Types STATE)
{
	switch(STATE)
	{
		case EXT_INTERRUPT_ENABLE:
		switch (INTERRUPT_NO)
		{
			case EXT_INTERRUPT0:SetBit(EXT_INTERRUPTS_GICR_Register,EXT_INTERRUPT0_GICR_BIT);break;
			case EXT_INTERRUPT1:SetBit(EXT_INTERRUPTS_GICR_Register,EXT_INTERRUPT1_GICR_BIT);break;
			case EXT_INTERRUPT2:SetBit(EXT_INTERRUPTS_GICR_Register,EXT_INTERRUPT2_GICR_BIT);break;
		}break;
		case EXT_INTERRUPT_DISABLE:
		switch (INTERRUPT_NO)
		{
			case EXT_INTERRUPT0:SetBit(EXT_INTERRUPTS_GICR_Register,EXT_INTERRUPT0_GICR_BIT);break;
			case EXT_INTERRUPT1:SetBit(EXT_INTERRUPTS_GICR_Register,EXT_INTERRUPT1_GICR_BIT);break;
			case EXT_INTERRUPT2:SetBit(EXT_INTERRUPTS_GICR_Register,EXT_INTERRUPT2_GICR_BIT);break;
		}break;
	}
}
void EXT_INTERRUPTS_SNCONTROLE_MODE(EXT_INTERRUPT_Types INTERRUPT_NO,SNC_MODE_Types MODE)
{
	switch(INTERRUPT_NO)
	{
		case EXT_INTERRUPT0: EXT_INTERRUPTS_MCUCR_Register |= (MODE<<0);break;
		case EXT_INTERRUPT1: EXT_INTERRUPTS_MCUCR_Register |= (MODE<<2);break;
		case EXT_INTERRUPT2:
		if (MODE == FALLING_EDGE)
			ClearBit(EXT_INTERRUPTS_MCUCSR_Register,EXT_INTERRUPT2_MCUCSR_BIT);
		else if(MODE == RISING_EDGE)
			SetBit(EXT_INTERRUPTS_MCUCSR_Register,EXT_INTERRUPT2_MCUCSR_BIT);
		else{/*Do Nothing*/}
			break;
	}
}
void EXT_INTERRUPTS_SetCallBack(EXT_INTERRUPT_Types INTERRUPT_NO,void (*EXT_INTERRUPT_FUNCTION_COPY_PTR)(void))
{
	switch(INTERRUPT_NO)
	{
		case EXT_INTERRUPT0:EXT_INTERRUPT0_FUNCTION_PTR = EXT_INTERRUPT_FUNCTION_COPY_PTR;break;
		case EXT_INTERRUPT1:EXT_INTERRUPT1_FUNCTION_PTR = EXT_INTERRUPT_FUNCTION_COPY_PTR;break;
		case EXT_INTERRUPT2:EXT_INTERRUPT2_FUNCTION_PTR = EXT_INTERRUPT_FUNCTION_COPY_PTR;break;
	}
}


ISR (INT0_vect)
{
	EXT_INTERRUPT0_FUNCTION_PTR();
}
ISR (INT1_vect)
{
	EXT_INTERRUPT1_FUNCTION_PTR();
}
ISR (INT2_vect)
{
	EXT_INTERRUPT2_FUNCTION_PTR();
}
