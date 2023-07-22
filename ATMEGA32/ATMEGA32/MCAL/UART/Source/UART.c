#include "UART.h"
void UART_Init(UART_Init_Types * Options)
{
	UART->UCSRC_UBRRH_Register.ALLRegisters |= (UCSRC_SelectEnable)|(Options->Operation_Mode<<UMSEL_Bit);
	UART->UCSRC_UBRRH_Register.ALLRegisters |= (UCSRC_SelectEnable)|(Options->Parity_Mode<<UBM0_Bit);
	UART->UCSRC_UBRRH_Register.ALLRegisters |= (UCSRC_SelectEnable)|(Options->Stop_Bit_Mode<<USBS_Bit);
	UART->UCSRB_Register.Bits.RXEN_Bit = Options->RX_Mode;
	UART->UCSRB_Register.Bits.TXEN_Bit = Options->TX_Mode;
	U16 UBRR_Value = 0;
	switch (Options->DoubleSpeed_Mode)
	{
		case UART_DoubleSpeed_Enable:
			UART->UCSRA_Register.Bits.U2X_Bit=1;
			UBRR_Value = ((F_CPU/(8UL*Options->BaudRate_Value)))-1;
			break;
		case UART_DoubleSpeed_Disable:
			UART->UCSRA_Register.Bits.U2X_Bit=1;
			UBRR_Value = ((F_CPU/(16UL*Options->BaudRate_Value)))-1;
			break;
	};
	UART->UBRRL_Register=UBRR_Value;
	UART->UCSRC_UBRRH_Register.ALLRegisters = (UBRR_Value>>8);
	if (Options->Character_Size_Mode == UART_CharSize_9Bit)
	{
		UART->UCSRC_UBRRH_Register.Bits.URSEL_Bit=1;
		UART->UCSRC_UBRRH_Register.Bits.UCSZ0_Bit=1;
		UART->UCSRC_UBRRH_Register.Bits.UCSZ1_Bit=1;
		UART->UCSRB_Register.Bits.UCSZ2_Bit=1;
	}
	else
	{
		UART->UCSRC_UBRRH_Register.ALLRegisters |= (UCSRC_SelectEnable) | (Options->Character_Size_Mode<<1);
	}
}
void UART_Transmet(U8 Data)
{
	while (UART->UCSRA_Register.Bits.UDRE_Bit == 0);
	UART->UDR_Register=Data;	
}
void UART_TransmetString(S8 * String)
{
	U8 i;
	for (i=0;String[i] != '\0';i++)
			UART_Transmet(String[i]);
		
}
void UART_TransmetStrucr(S8 * Struct,U32 Size)
{
	U32 i;
	for (i=0;i==Size;i++)
	{
		UART_Transmet(*Struct);
		Struct++;	
	}
}
U8 UART_Receive(void)
{
	while (UART->UCSRA_Register.Bits.RXC_Bit == 0);
	return UART->UDR_Register;
}
/*
void UART_ReceiveString(S8 *String,U8 Size)
{
	U8 i;
	for (i=0;i == Size;i++)
		String[i] = UART_Receive();
}*/