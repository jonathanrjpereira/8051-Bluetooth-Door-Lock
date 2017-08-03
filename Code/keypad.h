//Created by Jonathan Pereira on 20th April 2017

#include<reg51.h>

// Define Pins
sbit RowA = P2^0;     //RowA
sbit RowB = P2^1;     //RowB
sbit RowC = P2^2;     //RowC
sbit RowD = P2^3;     //RowD

sbit C1   = P2^4;     //Column1
sbit C2   = P2^5;     //Column2
sbit C3   = P2^6;     //Column3
sbit C4   = P2^7;     //Column4


#define keypadbus P2

// Main program

void Keypad_Init(void)
{
	keypadbus = 0xF0;    //used for generating outputs and taking inputs from Keypad  
}


void delay(int d)
{
	unsigned int x,y;
	for(x=0;x<d;x++);
	for(y=0;y<=1275;y++);
}


char READ_SWITCHES(void)	
{	
	RowA = 0; RowB = 1; RowC = 1; RowD = 1; 	//Test Row A

	if (C1 == 0) { delay(1000); while (C1==0); return '7'; }
	if (C2 == 0) { delay(1000); while (C2==0); return '8'; }
	if (C3 == 0) { delay(1000); while (C3==0); return '9'; }
	if (C4 == 0) { delay(1000); while (C4==0); return '/'; }

	RowA = 1; RowB = 0; RowC = 1; RowD = 1; 	//Test Row B

	if (C1 == 0) { delay(1000); while (C1==0); return '4'; }
	if (C2 == 0) { delay(1000); while (C2==0); return '5'; }
	if (C3 == 0) { delay(1000); while (C3==0); return '6'; }
	if (C4 == 0) { delay(1000); while (C4==0); return 'x'; }
	
	RowA = 1; RowB = 1; RowC = 0; RowD = 1; 	//Test Row C

	if (C1 == 0) { delay(1000); while (C1==0); return '1'; }
	if (C2 == 0) { delay(1000); while (C2==0); return '2'; }
	if (C3 == 0) { delay(1000); while (C3==0); return '3'; }
	if (C4 == 0) { delay(1000); while (C4==0); return '-'; }
	
	RowA = 1; RowB = 1; RowC = 1; RowD = 0; 	//Test Row D

	if (C1 == 0) { delay(1000); while (C1==0); return 'C'; }
	if (C2 == 0) { delay(1000); while (C2==0); return '0'; }
	if (C3 == 0) { delay(1000); while (C3==0); return '='; }
	if (C4 == 0) { delay(1000); while (C4==0); return '+'; }

	return 'n';           	// Means no key has been pressed
}

char get_key(void)				//get key from user
{
	char key = 'n';      		//assume no key pressed

	while(key=='n')
	{												//wait untill a key is pressed
		key = READ_SWITCHES(); 	//scan the keys again and again
		if(RI==1)								//Check HC-05
		break;
	}
	return key;           	//when key pressed then return its value
}
