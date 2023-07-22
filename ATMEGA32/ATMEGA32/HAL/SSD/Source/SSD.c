#include "SSD.h"
void SSD_Init(void)
{
	//SSD Enable Lines
	DIO_ConfigChannel(SSD1_Enable,OUTPUT);
	DIO_ConfigChannel(SSD2_Enable,OUTPUT);
	//Dot Point
	DIO_ConfigChannel(SSD_DP,OUTPUT);
	//SSD Data Lines
	DIO_ConfigChannel(SSD_Data1,OUTPUT);
	DIO_ConfigChannel(SSD_Data2,OUTPUT);
	DIO_ConfigChannel(SSD_Data3,OUTPUT);
	DIO_ConfigChannel(SSD_Data4,OUTPUT);
	//SSD Turn OFF
	DIO_WriteChannel(SSD1_Enable,STD_Low);
	DIO_WriteChannel(SSD2_Enable,STD_Low);
}
void SSD_Display(float Num)
{
	if(Num<=10)
	{
		Num*=10;
		DIO_WriteChannel(SSD_DP,STD_High);
	}
	U8 SSD_First_Digit = ((U8)Num%10)<<4;
	U8 SSD_Second_Digit = ((U8)Num/10)<<4;
	if(Num>10&&Num<100)
	{
		
		//Enable SSD1 & Disable SSD2
		DIO_WriteChannel(SSD1_Enable,STD_High);
		DIO_WriteChannel(SSD2_Enable,STD_Low);
		//Write First Digit
		DIO_WriteChannelGroup(SSD_Data_PORT,Write_LSP,SSD_First_Digit);
		_delay_ms(1);
		
		//Disable SSD1 & Enable SSD2
		DIO_WriteChannel(SSD1_Enable,STD_Low);
		DIO_WriteChannel(SSD2_Enable,STD_High);
		//Write First Digit
		DIO_WriteChannelGroup(SSD_Data_PORT,Write_LSP,SSD_Second_Digit);
		_delay_ms(1);
	}
	else
	{
		DIO_WriteChannel(SSD1_Enable,STD_Low);
		DIO_WriteChannel(SSD2_Enable,STD_Low);
	}
		
}
void SSD_Display_With_Delay(float Num , U32 Delay)
{
	U32 Count=0;
	for(Count=0;Count<Delay;Count+=3)
	{
		SSD_Display(Num);
		_delay_ms(1);
	}
}
