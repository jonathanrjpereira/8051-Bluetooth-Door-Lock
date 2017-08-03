//Created by Jonathan Pereira on 20th April 2017

#include<lcd.h>
#include<keypad.h>
#include<uart.h>

char curr_pass[4] = {'7','3','3','7'};  //Default 4 pin Password
char temp_pass[4];
char key_press;
int input;
sbit motor_pin = P0^0;  //Servo Motor Pin
sbit led = P0^2;  //LED pin


void Enter_Pass(void);
void Check_Password(int ip);
void Unlocked(int inp);
void Locked(void);
void Change_Password(int ip);
void Servo(int angle);

void main(void)
	
	{
		Keypad_Init();	// Make input and output pins as required
		LCD_Init();			// Initilize LCD
		UART_Init();		// Intialize UART
		
		Servo(50);  //Servo is at 0 Degrees
		led = 1;		//LED ON
		
		LCD_DisplayString("Door Locked");
		UART_TxString("Door Locked");
		if(get_key() == '+')      //Check Keypad Polling
		{
			input = 1;							//Input is keypad/HC-05 Flag
			Check_Password(input);
		}
		if(UART_RxChar()=='+')   //Check HC-05 Polling
		{
			input = 0;
			Check_Password(input);
		}
	}


	

void Enter_Pass(void)
{
		LCD_Clear();        
		LCD_DisplayString("Enter the");
		LCD_GoToLineTwo();
		LCD_DisplayString("Password: ");
		UART_TxString("Enter the Password");
}

void Check_Password(int ip)
{
	int i=0;
	Enter_Pass();
	while(i<4)      //Password Length is 4
	{
			if(ip == 1)
			{
				if(get_key!='n')
				{
					temp_pass[i]=get_key();
					LCD_DisplayString("*");
					i++;
				}
			}
			if(ip == 0)
			{
				temp_pass[i]=UART_RxChar();
				UART_TxString("*");
				LCD_DisplayString("*");
				i++;
			}
		}
	if(curr_pass[0]==temp_pass[0] &&
		 curr_pass[1]==temp_pass[1] &&
		 curr_pass[2]==temp_pass[2] &&
		 curr_pass[3]==temp_pass[3]
		)
	{
		Unlocked(ip);
	}
	else
		Locked();
}

void Unlocked(int inp)
{
	Servo(50);
	led = 0;
	LCD_Clear();
	LCD_DisplayString("Door Unlocked");
	UART_TxString("Door Unlocked");
	if(get_key()=='-' || UART_RxChar()== '-')
	{
		Locked();	
	}
	if(get_key()=='x' || UART_RxChar()== 'x')
	{
		Change_Password(inp);
	}
}

void Locked(void)
{
	Servo(110);
	led = 1;
	LCD_Clear();
	LCD_DisplayString("Door Locked");
	UART_TxString("Door Locked");
	main();
}

void Change_Password(int ip)
{
	int j=0;
	LCD_Clear();
	LCD_GoToLineOne();
	LCD_DisplayString("Enter New");
	LCD_GoToLineTwo();
	LCD_DisplayString("Password");
	UART_TxString("Enter New Password");
	delay_ms(2000);
	LCD_Clear();

	while(j<4)
	{
			if(ip == 1)
			{
				if(get_key!='n')
				{
					temp_pass[j]=get_key();
					LCD_DisplayString("*");
					j++;
				}
			}
			if(ip == 0)
			{
				temp_pass[j]=UART_RxChar();
				
				LCD_DisplayString("*");
				UART_TxString("*");
				j++;
			}
	}
	
	LCD_Clear();
	for(j=0;j<4;j++)
	{
		LCD_DataWrite(temp_pass[j]);
		
	}
	delay_ms(2000);
	
	
	curr_pass[0]=temp_pass[0];
	curr_pass[1]=temp_pass[1];
	curr_pass[2]=temp_pass[2];
	curr_pass[3]=temp_pass[3];
	
	/*
	LCD_Clear();
	LCD_DisplayString("Current Password");
	delay_ms(500);
	LCD_Clear();
	for(j=0;j<4;j++)
	{
		LCD_DataWrite(curr_pass[j]);
		
	}
	delay_ms(2000);
	*/
	
	LCD_Clear();
	LCD_DisplayString("Password Changed");
	UART_TxString("Password Changed");
	if(get_key()=='-' || UART_RxChar()== '-')
	{
		Locked();	
	}
}

void Servo(int angle)
{
	int i;
	motor_pin = 0;
	for(i=0;i<500;i++)
	{
		motor_pin = 1;
		delay_ms(angle);
		motor_pin=0;
		delay_ms(100);
	}
}