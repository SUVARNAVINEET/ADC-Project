#include <reg52.h>
#include "delay.h"

void delay(unsigned char Delval)
{
	for(;Delval!=0;Delval--);
}

void delay_Ms(unsigned int Delval_ms)
{
	for(;Delval_ms!=0;Delval_ms--)
	{
		delay(100);
		delay(100);
		
	}
}

