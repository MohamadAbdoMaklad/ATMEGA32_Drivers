#include "LCD_Config.h"
#include "LCD.h"
void LCD_Init(void)
{
	DIO_WriteChannel(LCD_RW,STD_Low);
	DIO_WriteChannel(LCD_E,STD_High);
	_delay_ms(20);
	LCD_Cmd(0x33);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);		//Set Function 4Bit - 2Line - 5*8
	LCD_Cmd(0x06);		//Entry Mode Move Right
	LCD_Cmd(0x0C);		//Display ON & courser OFF & No Blinking
}
void Enable (void)
{
	DIO_WriteChannel(LCD_E,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_E,STD_High);
}
void LCD_Cmd(U8 Cmd)
{
	U8 PortValue = STD_Low;
	DIO_WriteChannel(LCD_RS,STD_Low);
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F)|(Cmd & 0xF0);
	DIO_WritePort(LCD_DataPort,PortValue);
	Enable();
	_delay_ms(5);
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F)|(Cmd << 4);
	DIO_WritePort(LCD_DataPort,PortValue);
	Enable();
	_delay_ms(2);
	
}
void LCD_Char(S8 Data)
{
	U8 PortValue = STD_Low;
	DIO_WriteChannel(LCD_RS,STD_High);
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F)|(Data & 0xF0);
	DIO_WritePort(LCD_DataPort,PortValue);
	Enable();
	_delay_ms(5);
	PortValue = DIO_ReadPort(LCD_DataPort);
	PortValue = (PortValue & 0x0F)|(Data << 4);
	DIO_WritePort(LCD_DataPort,PortValue);
	Enable();
	_delay_ms(2);
}
void LCD_String(S8 * String)
{
	U8 i;
	for (i=0;String[i] != '\0';i++)
	LCD_Char(String[i]);
}
void LCD_SetPosition(U8 LineNo, U8 Position)
{
	switch(LineNo)
	{
		case 1: LCD_Cmd((0x80 | (Position & 0x0F)));break;
		case 2: LCD_Cmd((0xC0 | (Position & 0x0F)));break;
	}
}
void LCD_Clear(void)
{
	LCD_Cmd(0x01);
}
void LCD_Custom_Char(Custom_Charactars Location,U8 * msg)
{
	if (Location<8)
	{
		LCD_Cmd((0x40 + (Location*8)));
		U8 i;
		for(i=0;i<8;i++)
		{
			LCD_Char(msg[i]);
		}
	}
}