#include "SPI.h"
void SPI_Init(SPI_Init_Types * Options)
{
	switch(Options->StateMode)
	{
		case SPI_Master:
		DIO_ConfigChannel(SPI_SS_Pin,OUTPUT);
		DIO_ConfigChannel(SPI_MOSI_Pin,OUTPUT);
		DIO_ConfigChannel(SPI_MISO_Pin,INPUT);
		DIO_ConfigChannel(SPI_SCK_Pin,OUTPUT);
		SPI->SPCR_Register.Bits.MSTR_Bit = 1;
		SPI->SPCR_Register.Bits.SPE_Bit = 1;
		break;
		case  SPI_Slave:
		DIO_ConfigChannel(SPI_SS_Pin,INPUT);
		DIO_ConfigChannel(SPI_MOSI_Pin,INPUT);
		DIO_ConfigChannel(SPI_MISO_Pin,OUTPUT);
		DIO_ConfigChannel(SPI_SCK_Pin,INPUT);
		SPI->SPCR_Register.Bits.MSTR_Bit = 0;
		SPI->SPCR_Register.Bits.SPE_Bit = 1;
		break;
	}
	switch(Options->DoubleSpeedMode)
	{
		case SPI_DoubleSpeed_Enable:SPI->SPSR_Register.Bits.SPI2X_Bit = 1;break;
		case SPI_DoubleSpeed_Disable:SPI->SPSR_Register.Bits.SPI2X_Bit = 0;break;
	}
	SPI->SPCR_Register.AllRegister |= (Options->ClockMode<<0);
	SPI->SPCR_Register.AllRegister |= (Options->MODE<<2);
	SPI->SPCR_Register.AllRegister |= (Options->DataOrderMode<<5);
	SPI->SPCR_Register.AllRegister |= (Options->InterruptState<<7);
}
U8 SPI_TX_RX(U8 Data)
{
	SPI->SPDR_Register = Data;
	while (SPI->SPSR_Register.Bits.SPIF_Bit == 0);
	return SPI->SPDR_Register;
}
void SPI_TX_RX_String(S8 *String)
{
	U8 i;
	for(i=0; String[i]!='\0';i++)
	{
		SPI_TX_RX(String[i]);
	}
}

void SPI_Cannel_State(DIO_ChannelTypes ChannelID,SPI_State State)
{
	DIO_ConfigChannel(ChannelID,OUTPUT);
	switch (State)
	{
		case SPI_Disable:DIO_WriteChannel(ChannelID,STD_High);break;
		case SPI_Enable:DIO_WriteChannel(ChannelID,STD_Low);break;
	}
}
