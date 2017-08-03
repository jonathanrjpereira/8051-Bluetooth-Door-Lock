//Created by Jonathan Pereira on 20th April 2017

#include "delay.h"

/* Note: Replace 'LCD-CmdWrite with LCD */


sbit rs  = P0^3;     //RS pin for LCD
sbit rw  = P0^4;     //RW pin for LCD
sbit en  = P0^5;     //EN pin for LCD

#define databus P1

/* 16x2 LCD Specification */
#define LCDMaxLines 2
#define LCDMaxChars 16
#define LineOne 0x80
#define LineTwo 0xc0
#define BlankSpace ' '

void LCD(char a)
{
	databus=a;
	rw=0;
	rs=0;
	en=1;
	delay_ms(20);
	en=0;
}


void LCD_Clear()
{
   LCD(0x01);  // Clear the LCD and go to First line First Position
   LCD(LineOne);
}

void LCD_Init(void)
{
	rs=0;
  rw=0;
  en=0;
	LCD(0x30);
	delay_ms(10);
  LCD(0x30);
	delay_ms(10);
	LCD(0x30);
	delay_ms(10);
	LCD(0x38);
	delay_ms(10);
	LCD(0x38);
	delay_ms(10);
	LCD(0x38);
	LCD(0x0C);
	LCD(0x01);
	LCD(0x0C);
}

void LCD_DataWrite( char dat)
{
	databus=dat;     // Send the data to LCD
	rs=1;          // Select the Data Register by pulling RS HIGH
	rw=0;          // Select the Write Operation  by pulling RW LOW
	en=1;          // Send a High-to-Low Pusle at Enable Pin
	delay_ms(10);
	en=0;
	delay_ms(10);
 
}

void LCD_DisplayString(char *string_ptr)
{
	while(*string_ptr)
	LCD_DataWrite(*string_ptr++);
}

void LCD_DisplayNumber(unsigned int num)
{
	LCD_DataWrite((num/10000)+0x30);
	num=num%10000;
 
	LCD_DataWrite((num/1000)+0x30);
	num=num%1000;
 
	LCD_DataWrite((num/100)+0x30);
	num=num%100;
 
	LCD_DataWrite((num/10)+0x30);
 
	LCD_DataWrite((num%10)+0x30);
 
 }
 
		
void LCD_GoToLineOne()
{
	LCD(LineOne);   // Move the Cursor to First line First Position
}

void LCD_GoToLineTwo()
{
	LCD(LineTwo);   // Move the Cursor to Second line First Position
}