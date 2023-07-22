#ifndef SPI_H_
#define SPI_H_
#include "SPI_Registers.h"
#include "DIO.h"
void SPI_Init(SPI_Init_Types * Options);
U8 SPI_TX_RX(U8 Data);
void SPI_TX_RX_String(S8 *String);
void SPI_Cannel_State(DIO_ChannelTypes ChannelID,SPI_State State);

#endif /* SPI_H_ */