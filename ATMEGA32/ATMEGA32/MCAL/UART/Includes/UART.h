#ifndef UART_H_
#define UART_H_

#include "UART_Types.h"
#include "UART_Registers.h"
#include "Clock.h"
void UART_Init(UART_Init_Types * Options);
void UART_Transmet(U8 Data);
void UART_TransmetString(S8 * String);
U8 UART_Receive(void);
S8 UART_ReceiveString(S8 * String,U8 Size);
#endif /* UART_H_ */