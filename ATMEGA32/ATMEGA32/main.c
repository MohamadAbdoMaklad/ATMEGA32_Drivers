//#include "Application.h"
#include "Modules_Includes.h"
#include "DIO.h"
#include "TIMER1_PWM.h"
#include "ADC.h"
#include "LCD.h"
#include "Timer0.h"
#include "Timer2.h"
#include "UART.h"
#include "Bluetooth_UART.h"
#include "SPI.h"
#include "TWI.h"
int main (void)
{
	//TWI_Init(,400000,TWI_Prescaler_1);
	
	
	/*//
	SPI_Init_Types SPI_Options = {	SPI_Master,
									SPI_Clock_128,
									SPI_DoubleSpeed_Enable,
									SPI_MSB,
									SPI_Interrupt_Disable,
									SPI_Mode0};
	SPI_Init(&SPI_Options);
	SPI_Cannel_State(SPI_SS_Pin,SPI_Enable);
	while (1)
	{
		SPI_TX_RX_String("Mohamed Abdo Maklad");
	}
	*/
	/* //Bluetooth to control LEDs and relay and buzzer
	DIO_ConfigChannel(DIO_ChannelD0,INPUT);
	DIO_ConfigChannel(DIO_ChannelD1,INPUT);
	DIO_ConfigChannel(DIO_ChannelD3,OUTPUT);
	DIO_ConfigChannel(DIO_ChannelC2,OUTPUT);
	DIO_ConfigChannel(DIO_ChannelC7,OUTPUT);
	DIO_ConfigChannel(DIO_ChannelA2,OUTPUT);
	DIO_ConfigChannel(DIO_ChannelA3,OUTPUT);
	UART_Init_Types UART_Options = {UART_Asynchronous_Operration,
									UART_Parit_Disable,
									UART_1_StopBit,
									UART_CharSize_8Bit,
									UART_TX_Enable,
									UART_RX_Enable,
									UART_DoubleSpeed_Enable,
									UART_BaudRate_9600};
	Bluetooth_Init(&UART_Options);
	UART_Options.BaudRate_Value=UART_BaudRate_38_4K;
	Bluetooth_Transmit_AT_Command("AT+ROLE=Param1");
	UART_Options.BaudRate_Value=UART_BaudRate_9600;
	while(1)
	{
		Bluetooth_TransmitString("Mohamed");
		//Bluetooth_TransmitString("Mohamed");
		U8 Action = Bluetooth_Receive();
		if (Action=='0')
		DIO_ToggleChannel(DIO_ChannelD3);
		if (Action=='1')
		DIO_ToggleChannel(DIO_ChannelC2);
		if (Action=='2')
		DIO_ToggleChannel(DIO_ChannelC7);
		if (Action=='3')
		DIO_ToggleChannel(DIO_ChannelA2);
		if (Action=='4')
		DIO_ToggleChannel(DIO_ChannelA3);
		if (Action=='5')
		Bluetooth_TransmitString("Mohamed");
	}
	*/
//=================================================================================//
	//Bluetooth_TransmitString("Mohamed Abdo Maklad: ");
	//S8 RR = UART_Receive();
	//UART_Transmet(RR);
	/*
	S8 String[10];
	UART_ReceiveString(String,10);
	UART_TransmetString("You Emtered : ");
	UART_TransmetString(String);
	*/
	
	/* // Delay Function
	DIO_ConfigChannel(DIO_ChannelA0,OUTPUT);
	while(1)
	{
		DIO_WriteChannel(DIO_ChannelA0,STD_High);
		DELAY_MS(10);
		DIO_WriteChannel(DIO_ChannelA0,STD_Low);
		DELAY_MS(5);
	}
	*/
//==========================================================================//
	/* //ADC With LCD
	DIO_Init();
	ADC_InitTypes ADC_Options = {ADC_Prescaler128,ADC_Vref_Aref};
	ADC_Init(&ADC_Options);
	LCD_Init();
	while(1)
	{
		DIO_WriteChannel(DIO_ChannelC3,STD_High);
		DIO_WriteChannel(DIO_ChannelC4,STD_Low);
		S8 ADC_READ_VALUE_STRING[10];
		U16 ADC_READING_Value = 0;		
		ADC_READING_Value = (ADC_READ(ADC_Channel0)*(float)100/1023);
		PWM_T2_Generate_COM1B(ADC_READING_Value);
		itoa(ADC_READING_Value,ADC_READ_VALUE_STRING,10);
		LCD_String(ADC_READ_VALUE_STRING);
		//PORTC = ADC_ADCL_Register;
		//PORTD = ADC_ADCH_Register;
		_delay_ms(100);
		LCD_Clear();
	}*/
return 0;
}
