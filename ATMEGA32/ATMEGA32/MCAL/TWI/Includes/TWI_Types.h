#ifndef TWI_TYPES_H_
#define TWI_TYPES_H_
#include "STD_Types.h"
typedef struct
{
	U8 TWIE_Bit:1;
	U8 Reserved:1;
	U8 TWEN_Bit:1;
	U8 TWWC_Bit:1;
	U8 TWSTO_Bit:1;
	U8 TWSTA_Bit:1;
	U8 TWEA_Bit:1;
	U8 TWINT_Bit:1; 
}TWI_TWCR_Register;

typedef union
{
	U8 AllRegister;
	TWI_TWCR_Register Bits;
}TWI_TWCR_Types;

typedef struct
{
	U8 TWPS0_Bit:1;
	U8 TWPS1_Bit:1;
	U8 Reserved:1;
	U8 TWS_Bit:5;
}TWI_TWSR_Register;

typedef union
{
	U8 AllRegister;
	TWI_TWSR_Register Bits;
}TWI_TWSR_Types;

typedef struct
{
	U8 TWBR_Register;
	TWI_TWSR_Types TWSR_Register;
	U8 TWAR_Register;
	U8 TWDR_Register;
	U8 Reserved[50];
	TWI_TWCR_Types TWCR_Register;
}TWI_Registers;

typedef enum
{
	TWI_Prescaler_1=0,
	TWI_Prescaler_4,
	TWI_Prescaler_16,
	TWI_Prescaler_64	
}TWI_Prescaler_Value;
#endif /* TWI_TYPES_H_ */