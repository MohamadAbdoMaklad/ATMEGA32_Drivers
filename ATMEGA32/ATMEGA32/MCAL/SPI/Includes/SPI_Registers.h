#ifndef SPI_REGISTERS_H_
#define SPI_REGISTERS_H_
#include "SPI_Types.h"
#define SPI ((volatile SPI_Registers*)0x2D)
#define SPI_SS_Pin DIO_ChannelB4
#define SPI_MOSI_Pin DIO_ChannelB5
#define SPI_MISO_Pin DIO_ChannelB6
#define SPI_SCK_Pin DIO_ChannelB7
#endif /* SPI_REGISTERS_H_ */