#include "KeyPad_Config.h"
#include "KeyPad.h"
void KeyPad_Init(void)
{
	U8 i,j;
	for (i=0;i<ColomsNo;i++)
	{
		DIO_ConfigChannel(KeyPadColoms[i],INPUT);
		DIO_WriteChannel(KeyPadColoms[i],STD_High);
	}
	for (j=0;j<RowsNo;j++)
	{
		DIO_ConfigChannel(KeyPadRows[i],OUTPUT);
		DIO_WriteChannel(KeyPadRows[i],STD_High);
	}
}
U8 GetKey(void)
{
	U8 i,j;
	for(i=0;i<RowsNo;i++)
	{
		DIO_WriteChannel(KeyPadRows[i],STD_Low);
		for(j=0;j<ColomsNo;j++)
		{
			if(DIO_ReadChannel(KeyPadColoms[j]) == STD_Low)
			{
				while(DIO_ReadChannel(KeyPadColoms[j]) == STD_Low);
				return KeyPad[i][j];
			}
		}
		DIO_WriteChannel(KeyPadRows[i],STD_High);
	}
	return STD_Low;
}