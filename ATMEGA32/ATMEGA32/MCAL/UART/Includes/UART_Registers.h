#ifndef UART_REGISTERS_H_
#define UART_REGISTERS_H_

#include "UART_Types.h"

#define UCSRC_SelectEnable (1<<7)

#define UART ((volatile UART_Registers*)0x29)

#define UMSEL_Bit	6
#define UBM0_Bit	4
#define USBS_Bit	3
//#define UCSZ0_Bit	1

#endif /* UART_REGISTERS_H_ */