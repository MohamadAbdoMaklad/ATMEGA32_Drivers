#ifndef EXT_INTERRUPTS_REGISTERS_H_
#define EXT_INTERRUPTS_REGISTERS_H_
#include "STD_Types.h"
#define EXT_INTERRUPTS_MCUCR_Register (*(volatile U8*)0x55)
#define EXT_INTERRUPTS_MCUCSR_Register (*(volatile U8*)0x54)
#define EXT_INTERRUPTS_GICR_Register (*(volatile U8*)0x5B)
#define EXT_INTERRUPTS_GIFR_Register (*(volatile U8*)0x5A)

#define EXT_INTERRUPT0_GICR_BIT 6
#define EXT_INTERRUPT1_GICR_BIT 7
#define EXT_INTERRUPT2_GICR_BIT 5

#define EXT_INTERRUPT2_MCUCSR_BIT 6
#endif