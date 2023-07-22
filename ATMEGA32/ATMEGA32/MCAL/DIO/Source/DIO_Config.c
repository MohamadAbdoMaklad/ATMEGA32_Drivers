#include "DIO_Config.h"
#include "DIO.h"
DIO_PinConfig PinConfig[PINCOUNT]=
{
	//Port ===(A)===
	{OUTPUT,STD_High},	//PORTA0
	{OUTPUT,STD_High},	//PORTA1
	{OUTPUT,STD_High},	//PORTA2
	{OUTPUT,STD_High},	//PORTA3
	{OUTPUT,STD_High},	//PORTA4
	{OUTPUT,STD_High},	//PORTA5
	{OUTPUT,STD_High},	//PORTA6
	{OUTPUT,STD_High},	//PORTA7
	//Port ===(B)===
	{OUTPUT,STD_High},	//PORTB0
	{OUTPUT,STD_High},	//PORTB1
	{OUTPUT,STD_High},	//PORTB2
	{OUTPUT,STD_High},	//PORTB3
	{OUTPUT,STD_High},	//PORTB4
	{OUTPUT,STD_High},	//PORTB5
	{OUTPUT,STD_High},	//PORTB6
	{OUTPUT,STD_High},	//PORTB7
	//Port ===(C)===
	{OUTPUT,STD_High},	//PORTC0
	{OUTPUT,STD_High},	//PORTC1
	{OUTPUT,STD_High},	//PORTC2
	{OUTPUT,STD_High},	//PORTC3
	{OUTPUT,STD_High},	//PORTC4
	{OUTPUT,STD_High},	//PORTC5
	{OUTPUT,STD_High},	//PORTC6
	{OUTPUT,STD_High},	//PORTC7
	//Port ===(D)===
	{OUTPUT,STD_High},	//PORTD0
	{OUTPUT,STD_High},	//PORTD1
	{OUTPUT,STD_High},	//PORTD2
	{OUTPUT,STD_High},	//PORTD3
	{OUTPUT,STD_High},	//PORTD4
	{OUTPUT,STD_High},	//PORTD5
	{OUTPUT,STD_High},	//PORTD6
	{OUTPUT,STD_High},	//PORTD7
};

void DIO_Init(void)
{
	DIO_ChannelTypes Count = DIO_ChannelA0;
	DIO_ChannelTypes PortX;
	DIO_ChannelTypes BitNo;
	
	for (Count = DIO_ChannelA0; Count < PINCOUNT; Count++)
	{
		PortX = Count/8;
		BitNo = Count%8;
		switch(PinConfig[Count].Direction)
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
}
