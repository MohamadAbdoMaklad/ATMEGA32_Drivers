#ifndef LCD_H_
#define LCD_H_
#include "LCD_Config.h"
#include "DIO.h"
#include "Clock.h"

typedef enum{
	Smile_face =0,
	Hard_f,
	mem,
	haa,
	mem2,
	daal,
}Custom_Charactars;

void LCD_Init(void);
void Enable (void);
void LCD_Cmd(U8 Cmd);
void LCD_Char(S8 Data);
void LCD_String(S8 * String);
void LCD_SetPosition(U8 LineNo, U8 Position);
void LCD_Clear(void);
void LCD_Custom_Char(Custom_Charactars Location,U8 * msg);


	 
#endif