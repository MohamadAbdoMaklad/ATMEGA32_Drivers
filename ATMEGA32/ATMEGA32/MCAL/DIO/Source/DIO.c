#include "DIO.h"
void DIO_WriteChannel(DIO_ChannelTypes ChannelID , STD_LevelTypes Level)
{
	DIO_PortTypes PortX = ChannelID/8;
	DIO_ChannelTypes BitNo = ChannelID%8;
	switch(Level){
		case STD_High:
		switch(PortX){
			case DIO_PortA:SetBit(PORTA_Register,BitNo);break;
			case DIO_PortB:SetBit(PORTB_Register,BitNo);break;
			case DIO_PortC:SetBit(PORTC_Register,BitNo);break;
			case DIO_PortD:SetBit(PORTD_Register,BitNo);break;
		}break;
		case STD_Low:
		switch(PortX){
			case DIO_PortA:ClearBit(PORTA_Register,BitNo);break;
			case DIO_PortB:ClearBit(PORTB_Register,BitNo);break;
			case DIO_PortC:ClearBit(PORTC_Register,BitNo);break;
			case DIO_PortD:ClearBit(PORTD_Register,BitNo);break;
		}break;
	}
}

STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelID)
{
	DIO_PortTypes PortX = ChannelID/8;
	DIO_ChannelTypes BitNo = ChannelID%8;
	STD_LevelTypes BitValue = STD_Low;
	switch(PortX){
		case DIO_PortA:BitValue = GetBit(PINA_Register,BitNo);break;
		case DIO_PortB:BitValue = GetBit(PINB_Register,BitNo);break;
		case DIO_PortC:BitValue = GetBit(PINC_Register,BitNo);break;
		case DIO_PortD:BitValue = GetBit(PIND_Register,BitNo);break;
	};
	return BitValue;
}

void DIO_ConfigChannel(DIO_ChannelTypes ChannelID , DIO_DirectionTypes Direction)
{
	DIO_PortTypes PortX = ChannelID/8;
	DIO_ChannelTypes BitNo = ChannelID%8;
	switch(Direction)
	{
		case INPUT:
		switch(PortX){
			case DIO_PortA:ClearBit(DDRA_Register,BitNo);break;
			case DIO_PortB:ClearBit(DDRB_Register,BitNo);break;
			case DIO_PortC:ClearBit(DDRC_Register,BitNo);break;
			case DIO_PortD:ClearBit(DDRD_Register,BitNo);break;
		}break;
		case OUTPUT:
		switch(PortX){
			case DIO_PortA:SetBit(DDRA_Register,BitNo);break;
			case DIO_PortB:SetBit(DDRB_Register,BitNo);break;
			case DIO_PortC:SetBit(DDRC_Register,BitNo);break;
			case DIO_PortD:SetBit(DDRD_Register,BitNo);break;
		}break;
	}
}


void DIO_ToggleChannel(DIO_ChannelTypes ChannelID)
{
	DIO_PortTypes PortX = ChannelID/8;
	DIO_ChannelTypes BitNo = ChannelID%8;
	switch(PortX){
		case DIO_PortA:ToggleBit(PORTA_Register,BitNo);break;
		case DIO_PortB:ToggleBit(PORTB_Register,BitNo);break;
		case DIO_PortC:ToggleBit(PORTC_Register,BitNo);break;
		case DIO_PortD:ToggleBit(PORTD_Register,BitNo);break;
	};
}

void DIO_WritePort(DIO_PortTypes PortID,U8 PortValue)
{
	switch (PortID){
	case DIO_PortA:PORTA_Register = PortValue;break;
	case DIO_PortB:PORTB_Register = PortValue;break;
	case DIO_PortC:PORTC_Register = PortValue;break;
	case DIO_PortD:PORTD_Register = PortValue;break;
	}
}

U8 DIO_ReadPort(DIO_PortTypes PortID)
{
	U8 PortValue;
	switch (PortID){
	case DIO_PortA: return PortValue = PORTA_Register;break;
	case DIO_PortB: return PortValue = PORTB_Register;break;
	case DIO_PortC: return PortValue = PORTC_Register;break;
	case DIO_PortD: return PortValue = PORTD_Register;break;
	}
}

void DIO_ConfigPort(DIO_PortTypes PortID , U8 Direction)
{
	switch (PortID){
		case DIO_PortA:DDRA_Register = Direction;break;
		case DIO_PortB:DDRB_Register = Direction;break;
		case DIO_PortC:DDRC_Register = Direction;break;
		case DIO_PortD:DDRD_Register = Direction;break;
	}
}

void DIO_WriteChannelGroup(DIO_PortTypes PortID, U8 MASK , U8 DATA)
{
	
	switch(PortID)
	{
		case DIO_PortA:PORTA_Register = (PORTA_Register & ~MASK)|(DATA & MASK);break;
		case DIO_PortB:PORTB_Register = (PORTB_Register & ~MASK)|(DATA & MASK);break;
		case DIO_PortC:PORTC_Register = (PORTC_Register & ~MASK)|(DATA & MASK);break;
		case DIO_PortD:PORTD_Register = (PORTD_Register & ~MASK)|(DATA & MASK);break;
	}
}