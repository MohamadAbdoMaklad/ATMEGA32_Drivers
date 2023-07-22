#ifndef BLUETOOTH_UART_H_
#define BLUETOOTH_UART_H_
#include "UART.h"
#include "STD_Types.h"
#include "DIO.h"
void Bluetooth_Init(UART_Init_Types * Options);
void Bluetooth_Transmit(U8 Data);
void Bluetooth_TransmitString(S8 *String);
U8 Bluetooth_Receive(void);
void Bluetooth_Transmit_AT_Command(S8 *String);
#define BLUETOOTH_AT_ENABLE DIO_ChannelD4
#endif /* BLUETOOTH_UART_H_ */