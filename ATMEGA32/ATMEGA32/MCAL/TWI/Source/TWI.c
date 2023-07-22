#include "TWI.h"

void TWI_Init(U8 Address,unsigned long F_TWI, TWI_Prescaler_Value Prescaler)
{
	U8 Prescaler_value =0;
	TWI->TWAR_Register = Address;
	TWI->TWSR_Register.AllRegister |= (Prescaler<<0);
	switch(Prescaler)
	{
		case TWI_Prescaler_1: Prescaler_value = 1;break;
		case TWI_Prescaler_4: Prescaler_value = 4 ;break;
		case TWI_Prescaler_16: Prescaler_value = 16;break;
		case TWI_Prescaler_64:Prescaler_value = 64;break;
	};
	TWI->TWBR_Register = (((F_CPU/F_TWI)-16)/(2*(4^Prescaler_value)));
}

U8 TWI_Status(void)
{
	return TWI->TWSR_Register.Bits.TWS_Bit;
}

U8 TWI_Start(void)
{
	TWI->TWCR_Register.Bits.TWSTA_Bit = 1;
	TWI->TWCR_Register.Bits.TWSTO_Bit = 0;
	TWI->TWCR_Register.Bits.TWEA_Bit = 0;
	TWI->TWCR_Register.Bits.TWEN_Bit = 1;
	TWI->TWCR_Register.Bits.TWINT_Bit = 1;
	while (TWI->TWCR_Register.Bits.TWINT_Bit ==0);
	return TWI_Status();
}

U8 TWI_Send(U8 data)
{
	TWI->TWCR_Register.Bits.TWSTA_Bit = 0;
	TWI->TWCR_Register.Bits.TWSTO_Bit = 0;
	TWI->TWCR_Register.Bits.TWEA_Bit = 0;
	TWI->TWCR_Register.Bits.TWEN_Bit = 1;
	TWI->TWCR_Register.Bits.TWINT_Bit = 1;
	while (TWI->TWCR_Register.Bits.TWINT_Bit ==0);
	return TWI_Status();
}

U8 TWI_Read_Ack(U8 * Data)
{
	TWI->TWCR_Register.Bits.TWSTA_Bit = 0;
	TWI->TWCR_Register.Bits.TWSTO_Bit = 0;
	TWI->TWCR_Register.Bits.TWEA_Bit = 1;
	TWI->TWCR_Register.Bits.TWEN_Bit = 1;
	TWI->TWCR_Register.Bits.TWINT_Bit = 1;
	while (TWI->TWCR_Register.Bits.TWINT_Bit ==0);
	*Data = TWI->TWDR_Register;
	return TWI_Status();
}

U8 TWI_Read_NAck(U8 * Data)
{
	TWI->TWCR_Register.Bits.TWSTA_Bit = 0;
	TWI->TWCR_Register.Bits.TWSTO_Bit = 0;
	TWI->TWCR_Register.Bits.TWEA_Bit = 0;
	TWI->TWCR_Register.Bits.TWEN_Bit = 1;
	TWI->TWCR_Register.Bits.TWINT_Bit = 1;
	while (TWI->TWCR_Register.Bits.TWINT_Bit ==0);
	*Data = TWI->TWDR_Register;
	return TWI_Status();
}

void TWI_Stop(void)
{
	TWI->TWCR_Register.Bits.TWSTA_Bit = 0;
	TWI->TWCR_Register.Bits.TWSTO_Bit = 1;
	TWI->TWCR_Register.Bits.TWEA_Bit = 0;
	TWI->TWCR_Register.Bits.TWEN_Bit = 1;
	TWI->TWCR_Register.Bits.TWINT_Bit = 1;
}