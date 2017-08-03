//Created by Jonathan Pereira on 20th April 2017

#include<reg51.h>

void delay_us(unsigned int us_count)
{  
	while(us_count!=0)
	{
		us_count--;
	}
}
 
 
 
void delay_ms(unsigned int ms_count)
{
	while(ms_count!=0)
	{
		delay_us(112);   //delay_us is called to generate 1ms delay
		ms_count--;
	}
}
 
 
 
