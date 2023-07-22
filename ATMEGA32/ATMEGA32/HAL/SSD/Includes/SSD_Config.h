#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_
#include "DIO.h"
//SSD Enable Lines
#define SSD1_Enable DIO_ChannelB1
#define SSD2_Enable DIO_ChannelB2
//Dot Point
#define SSD_DP DIO_ChannelB3
//SSD Data Lines
#define SSD_Data_PORT DIO_PortA
#define SSD_Data1 DIO_ChannelA4
#define SSD_Data2 DIO_ChannelA5
#define SSD_Data3 DIO_ChannelA6
#define SSD_Data4 DIO_ChannelA7
#endif