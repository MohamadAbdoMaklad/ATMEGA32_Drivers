#ifndef CLOCK_H_
#define CLOCK_H_
// 16MH Frequency for 16MH Oscillatory
/*
defined before include the delay.h
as it is internally defined 
so we need to re define before
include to avoid the predefined 10MH value
*/
#define F_CPU 16000000UL
#include <util/delay.h>
#endif /* CLOCK_H_ */