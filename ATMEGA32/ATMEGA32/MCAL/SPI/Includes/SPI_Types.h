#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_
#include "STD_Types.h"

typedef struct
{
	U8 SPR0_Bit:1;
	U8 SPR1_Bit:1;
	U8 CHPA_Bit:1;
	U8 CPLO_Bit:1;
	U8 MSTR_Bit:1;
	U8 DORD_Bit:1;
	U8 SPE_Bit:1;
	U8 SPIE_Bit:1;
}SPI_SPCR_Register;

typedef union
{
	U8 AllRegister;
	SPI_SPCR_Register Bits;
}SPI_SPCR_Types;

typedef struct
{
	U8 SPI2X_Bit:1;
	U8 Reserved:5;
	U8 WCOL_Bit:1;
	U8 SPIF_Bit:1;
}SPI_SPSR_Register;

typedef union
{
	U8 AllRegister;
	SPI_SPSR_Register Bits;
}SPI_SPSR_Types;

typedef struct
{
	SPI_SPCR_Types SPCR_Register;
	SPI_SPSR_Types SPSR_Register;
	U8 SPDR_Register;
}SPI_Registers;


typedef enum{
	SPI_Slave=0,
	SPI_Master
}SPI_State_Types;

typedef enum{
	SPI_Clock_4=0,
	SPI_Clock_16,
	SPI_Clock_64,
	SPI_Clock_128
}SPI_Clock_Types;

typedef enum{
	SPI_DoubleSpeed_Disable=0,
	SPI_DoubleSpeed_Enable
}SPI_DoubleSpeed_Types;

typedef enum{
	SPI_MSB=0,
	SPI_LSB
}SPI_DataOrder_Types;

typedef enum
{
	SPI_Interrupt_Disable=0,
	SPI_Interrupt_Enable
}SPI_Interrupt_State;

typedef enum
{
	SPI_Disable=0,
	SPI_Enable	
}SPI_State;

typedef enum
{
	SPI_Mode0=0,
	SPI_Mode1,
	SPI_Mode2,
	SPI_Mode3,
}SPI_Mode;

typedef struct
{
	SPI_State_Types StateMode;
	SPI_Clock_Types ClockMode;
	SPI_DoubleSpeed_Types DoubleSpeedMode;
	SPI_DataOrder_Types DataOrderMode;
	SPI_Interrupt_State InterruptState;
	SPI_Mode MODE;
}SPI_Init_Types;
#endif /* SPI_TYPES_H_ */