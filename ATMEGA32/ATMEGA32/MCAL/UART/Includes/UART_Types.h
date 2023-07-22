#ifndef UART_TYPES_H_
#define UART_TYPES_H_
#include "STD_Types.h"
typedef struct{
	U8 MPCM_Bit:1;
	U8 U2X_Bit:1;
	U8 PE_Bit:1;
	U8 DOR_Bit:1;
	U8 FE_Bit:1;
	U8 UDRE_Bit:1;
	U8 TXC_Bit:1;
	U8 RXC_Bit:1;
}UART_UCSRA_Bits;

typedef union{
	U8 ALLRegisters;
	UART_UCSRA_Bits Bits;
}UART_UCSRA_Types;


typedef struct{
	U8 TXB8_Bit:1;
	U8 RXB8_Bit:1;
	U8 UCSZ2_Bit:1;
	U8 TXEN_Bit:1;
	U8 RXEN_Bit:1;
	U8 UDRIE_Bit:1;
	U8 TXCIE_Bit:1;
	U8 RXCIE_Bit:1;
}UART_UCSRB_Bits;

typedef union{
	U8 ALLRegisters;
	UART_UCSRB_Bits Bits;
}UART_UCSRB_Types;


typedef struct{
	U8 UCPOL_Bit:1;
	U8 UCSZ0_Bit:1;
	U8 UCSZ1_Bit:1;
	U8 USBS_Bit:1;
	U8 UPM0_Bit:1;
	U8 UPM1_Bit:1;
	U8 UMSEL_Bit:1;
	U8 URSEL_Bit:1;
}UART_UCSRC_Bits;

typedef union{
	U8 ALLRegisters;
	UART_UCSRC_Bits Bits;
}UART_UCSRC_Types;


typedef struct
{
	U8 UBRRL_Register;
	UART_UCSRB_Types UCSRB_Register;
	UART_UCSRA_Types UCSRA_Register;
	U8 UDR_Register;
	U8 Reserved[19];
	UART_UCSRC_Types UCSRC_UBRRH_Register;
}UART_Registers;

typedef enum
{
	UART_Asynchronous_Operration=0,
	UART_Synchronous_Operration
}UART_Operation_Mode_Types; // UMSEL 6-Bit >>UCSRC_Register 

typedef enum
{
	UART_Parit_Disable,
	UART_Parity_Even=2,
	UART_Parity_Odd=3
}UART_Parity_Mode_Types; // UPM1 UPM0 >> UCSRA

typedef enum
{
	UART_1_StopBit=0,
	UART_2_StopBit
}UART_Stop_Bit_Mode_Types; // USBS >> UCSRC

typedef enum
{
	UART_CharSize_5Bit=0,
	UART_CharSize_6Bit,
	UART_CharSize_7Bit,
	UART_CharSize_8Bit,
	UART_CharSize_9Bit
}UART_Character_Size_Mode_Types; // UCSZ0 UCSZ1 >> UCSRC ,UCSZ2 >> UCSRB

typedef enum
{
	UART_TX_Disable=0,
	UART_TX_Enable
}UART_TX_Mode;

typedef enum
{
	UART_RX_Disable=0,
	UART_RX_Enable
}UART_RX_Mode;

typedef enum
{
	UART_DoubleSpeed_Disable=0,
	UART_DoubleSpeed_Enable
}UART_DoubleSpeed_Mode;

typedef enum
{
	UART_BaudRate_2400=2400,
	UART_BaudRate_4800=4800,
	UART_BaudRate_9600=9600,
	UART_BaudRate_14_4K=14400,
	UART_BaudRate_19_2K=19200,
	UART_BaudRate_28_8K=28800,
	UART_BaudRate_38_4K=38400,
	UART_BaudRate_57_6K=57600,
	UART_BaudRate_76_8K=76800,
	UART_BaudRate_115_2K=115200,
	UART_BaudRate_230_4K=230400,
	UART_BaudRate_250K=250000
}UART_BaudRate_Types;
	
typedef struct
{
	UART_Operation_Mode_Types Operation_Mode;
	UART_Parity_Mode_Types Parity_Mode;
	UART_Stop_Bit_Mode_Types Stop_Bit_Mode;
	UART_Character_Size_Mode_Types Character_Size_Mode;
	UART_TX_Mode TX_Mode;
	UART_RX_Mode RX_Mode;
	UART_DoubleSpeed_Mode DoubleSpeed_Mode;
	UART_BaudRate_Types BaudRate_Value;
}UART_Init_Types; 
#endif /* UART_TYPES_H_ */