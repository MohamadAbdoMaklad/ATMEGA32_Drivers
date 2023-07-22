#ifndef TWI_H_
#define TWI_H_

#include "TWI_Registers.h"
#include "TWI_Types.h"
#include "STD_Types.h"
void TWI_Init(U8 Address,unsigned long F_TWI, TWI_Prescaler_Value Prescaler);
U8 TWI_Status(void);
U8 TWI_Start(void);
U8 TWI_Send(U8 data);
U8 TWI_Read_Ack(U8 * Data);
U8 TWI_Read_NAck(U8 * Data);
void TWI_Stop(void);

#endif /* TWI_H_ */