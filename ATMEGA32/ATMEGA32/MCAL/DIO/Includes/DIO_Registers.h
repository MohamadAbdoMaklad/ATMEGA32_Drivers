#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_
#include "STD_Types.h"
/*==========(PORTA Registers)==========*/
#define PORTA_Register (*(volatile U8*)0x3B)
#define DDRA_Register (*(volatile U8*)0x3A)
#define PINA_Register (*(volatile U8*)0x39)
/*==========(PORTB Registers)==========*/
#define PORTB_Register (*(volatile U8*)0x38)
#define DDRB_Register (*(volatile U8*)0x37)
#define PINB_Register (*(volatile U8*)0x36)
/*==========(PORTC Registers)==========*/
#define PORTC_Register (*(volatile U8*)0x35)
#define DDRC_Register (*(volatile U8*)0x34)
#define PINC_Register (*(volatile U8*)0x33)
/*==========(PORTD Registers)==========*/
#define PORTD_Register (*(volatile U8*)0x32)
#define DDRD_Register (*(volatile U8*)0x31)
#define PIND_Register (*(volatile U8*)0x30)
/*===============(END)===============*/
#endif /* DIO_REGISTERS_H_ */