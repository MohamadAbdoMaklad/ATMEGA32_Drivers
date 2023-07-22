#include "G_Interrupts.h"
void G_INTERRUPTS_EnableAll(void)
{
	SetBit(G_INTERRUPTS_SREG,G_INTERRUPTS_SREG_IBIT);
}

void G_INTERRUPTS_DisableAll(void)
{
	ClearBit(G_INTERRUPTS_SREG,G_INTERRUPTS_SREG_IBIT);
}