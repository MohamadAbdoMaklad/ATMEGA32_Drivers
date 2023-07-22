#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
#include "BitMath.h"
#include "STD_Types.h"
#include "DIO_Registers.h"
#include "DIO_Types.h"
typedef struct{
	DIO_DirectionTypes Direction;
	STD_LevelTypes Level;
	}DIO_PinConfig;

#define PINCOUNT 32
void DIO_Init (void);

#endif /* DIO_CONFIG_H_ */