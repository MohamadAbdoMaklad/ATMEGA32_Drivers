#ifndef DIO_H_
#define DIO_H_
#include "BitMath.h"
#include "STD_Types.h"
#include "DIO_Registers.h"
#include "DIO_Types.h"
#include "DIO_Config.h"

#define Write_MSP 0x0F
#define Write_LSP 0xF0

/*====================(DIO Functions Prototype)====================*/
void DIO_WriteChannel(DIO_ChannelTypes ChannelID , STD_LevelTypes Level);
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelID);
void DIO_ConfigChannel(DIO_ChannelTypes ChannelID , DIO_DirectionTypes Direction);
void DIO_ToggleChannel(DIO_ChannelTypes ChannelID);

// PortValue written in binary form  0B00000000
void DIO_WritePort(DIO_PortTypes PortID,U8 PortValue);
U8 DIO_ReadPort(DIO_PortTypes PortID);

// Directions written in binary form  0B00000000
void DIO_ConfigPort(DIO_PortTypes PortID , U8 Direction);
void DIO_WriteChannelGroup(DIO_PortTypes PortID, U8 MASK , U8 DATA);
#endif