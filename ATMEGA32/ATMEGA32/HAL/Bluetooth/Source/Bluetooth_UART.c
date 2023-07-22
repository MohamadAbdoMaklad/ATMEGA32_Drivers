#include "Bluetooth_UART.h"
void Bluetooth_Init(UART_Init_Types * Options)
{
	UART_Init(Options);
}
void Bluetooth_Transmit(U8 Data)
{
	UART_Transmet(Data);
}
void Bluetooth_TransmitString(S8 *String)
{
	UART_TransmetString(String);
}
U8 Bluetooth_Receive(void)
{
	return UART_Receive();
}

void Bluetooth_Transmit_AT_Command(S8 *String)
{
	DIO_ConfigChannel(BLUETOOTH_AT_ENABLE,OUTPUT);
	DIO_WriteChannel(BLUETOOTH_AT_ENABLE,STD_High);
	UART_TransmetString(String);
	DIO_WriteChannel(BLUETOOTH_AT_ENABLE,STD_Low);
}