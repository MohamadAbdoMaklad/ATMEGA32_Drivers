#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_
/*=====(Change DIO_Channel in Easy Way)=====*/
#define A0 DIO_ChannelA0
#define A1 DIO_ChannelA1
#define A2 DIO_ChannelA2
#define A3 DIO_ChannelA3
#define A4 DIO_ChannelA4
#define A5 DIO_ChannelA5
#define A6 DIO_ChannelA6
#define A7 DIO_ChannelA7
/*-------------------------*/
#define B0 DIO_ChannelB0
#define B1 DIO_ChannelB1
#define B2 DIO_ChannelB2
#define B3 DIO_ChannelB3
#define B4 DIO_ChannelB4
#define B5 DIO_ChannelB5
#define B6 DIO_ChannelB6
#define B7 DIO_ChannelB7
/*-------------------------*/
#define C0 DIO_ChannelC0
#define C1 DIO_ChannelC1
#define C2 DIO_ChannelC2
#define C3 DIO_ChannelC3
#define C4 DIO_ChannelC4
#define C5 DIO_ChannelC5
#define C6 DIO_ChannelC6
#define C7 DIO_ChannelC7
/*-------------------------*/
#define D0 DIO_ChannelD0
#define D1 DIO_ChannelD1
#define D2 DIO_ChannelD2
#define D3 DIO_ChannelD3
#define D4 DIO_ChannelD4
#define D5 DIO_ChannelD5
#define D6 DIO_ChannelD6
#define D7 DIO_ChannelD7
/*-------------------------*/
/*-------------------------
#define PINA0 DIO_ChannelA0
#define PINA1 DIO_ChannelA1
#define PINA2 DIO_ChannelA2
#define PINA3 DIO_ChannelA3
#define PINA4 DIO_ChannelA4
#define PINA5 DIO_ChannelA5
#define PINA6 DIO_ChannelA6
#define PINA7 DIO_ChannelA7

#define PINB0 DIO_ChannelB0
#define PINB1 DIO_ChannelB1
#define PINB2 DIO_ChannelB2
#define PINB3 DIO_ChannelB3
#define PINB4 DIO_ChannelB4
#define PINB5 DIO_ChannelB5
#define PINB6 DIO_ChannelB6
#define PINB7 DIO_ChannelB7

#define PINC0 DIO_ChannelC0
#define PINC1 DIO_ChannelC1
#define PINC2 DIO_ChannelC2
#define PINC3 DIO_ChannelC3
#define PINC4 DIO_ChannelC4
#define PINC5 DIO_ChannelC5
#define PINC6 DIO_ChannelC6
#define PINC7 DIO_ChannelC7

#define PIND0 DIO_ChannelD0
#define PIND1 DIO_ChannelD1
#define PIND2 DIO_ChannelD2
#define PIND3 DIO_ChannelD3
#define PIND4 DIO_ChannelD4
#define PIND5 DIO_ChannelD5
#define PIND6 DIO_ChannelD6
#define PIND7 DIO_ChannelD7
-------------------------*/
/*=====(Change DIO_PORT in Easy Way)=====
#define PORTA DIO_PortA
#define PORTB DIO_PortB
#define PORTC DIO_PortC
#define PORTD DIO_PortD
-------------------------*/
typedef enum{
	DIO_ChannelA0 = 0,
	DIO_ChannelA1,
	DIO_ChannelA2,
	DIO_ChannelA3,
	DIO_ChannelA4,
	DIO_ChannelA5,
	DIO_ChannelA6,
	DIO_ChannelA7,
			 
	DIO_ChannelB0,
	DIO_ChannelB1,
	DIO_ChannelB2,
	DIO_ChannelB3,
	DIO_ChannelB4,
	DIO_ChannelB5,
	DIO_ChannelB6,
	DIO_ChannelB7,
			 
	DIO_ChannelC0,
	DIO_ChannelC1,
	DIO_ChannelC2,
	DIO_ChannelC3,
	DIO_ChannelC4,
	DIO_ChannelC5,
	DIO_ChannelC6,
	DIO_ChannelC7,
			 
	DIO_ChannelD0,
	DIO_ChannelD1,
	DIO_ChannelD2,
	DIO_ChannelD3,
	DIO_ChannelD4,
	DIO_ChannelD5,
	DIO_ChannelD6,
	DIO_ChannelD7,
	}DIO_ChannelTypes;

typedef enum{
	DIO_PortA = 0,
	DIO_PortB,
	DIO_PortC,
	DIO_PortD,
	}DIO_PortTypes;

typedef enum{
	INPUT = 0,
	OUTPUT = 1,
	}DIO_DirectionTypes;


#endif /* DIO_TYPES_H_ */