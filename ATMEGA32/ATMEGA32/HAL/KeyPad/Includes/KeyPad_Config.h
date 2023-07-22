#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_
#include "DIO.h"
#define KP_R0 DIO_ChannelD0
#define KP_R1 DIO_ChannelD1
#define KP_R2 DIO_ChannelD4
#define KP_R3 DIO_ChannelD5
						 
#define KP_C0 DIO_ChannelD7
#define KP_C1 DIO_ChannelC0
#define KP_C2 DIO_ChannelC1
#define KP_C3 DIO_ChannelC4

#define RowsNo 4
#define  ColomsNo 4

U8 KeyPadRows[RowsNo] = {KP_R0,KP_R1,KP_R2,KP_R3};
U8 KeyPadColoms[ColomsNo] = {KP_C0,KP_C1,KP_C2,KP_C3};
/*U8 KeyPad[RowsNo][ColomsNo] = { {'7','8','9','/'},
								{'4','5','6','*'},
								{'1','2','3','-'},
								{'C','0','=','+'}};*/
U8 KeyPad[RowsNo][ColomsNo] = { {'1','2','3','A'},
								{'4','5','6','B'},
								{'7','8','9','C'},
								{'*','0','#','D'}};
#endif