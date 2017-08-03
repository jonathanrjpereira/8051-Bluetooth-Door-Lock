//Created by Jonathan Pereira on 20th April 2017

#include<reg51.h>
 
void UART_Init()
{
      TMOD |=0x20; //Timer1 in Mode2.
      TH1=-3;    // 9600 Baud rate at 11.0592MHz
      SCON=0x50; // Asynchronous mode 8-bit data and 1-stop bit
      TR1=1;     //Turn ON the timer.
  }
 
char UART_RxChar()
{
  while(RI==0) 		// Wait till the data is received
	{
		if(get_key()=='+')  //Check Keypad
			break;
	}
		
	RI=0;        // Clear Receive Interrupt Flag for next cycle
	return(SBUF);
}
 

 void UART_TxChar(char ch)
{
    SBUF=ch;       // Load the data to be transmitted
  while(TI==0);    // Wait till the data is trasmitted
     TI=0;         //Clear the flag for next cycle.
}
 
 
  
void UART_TxString(char *string_ptr)
 {
		while(*string_ptr)
		UART_TxChar(*string_ptr++);
 }
 
----------------------------------------------------------------------------------_*/
void UART_RxString(char *string_ptr)
 {
     char ch;
     while(1)
       {
          ch=UART_RxChar();    //Reaceive a char
          UART_TxChar(ch);     //Echo back the received char
 
         if((ch=='\r') || (ch=='\n')) //read till enter key is pressed
           {                          //once enter key is pressed
              *string_ptr=0;          //null terminate the string
                break;                //and break the loop
             }
         *string_ptr=ch;              //copy the char into string.
         string_ptr++;                //and increment the pointer
      }
 }
 
 
void UART_TxNumber(unsigned int num)
{
 
       UART_TxChar((num/10000)+0x30);
       num=num%10000;
 
       UART_TxChar((num/1000)+0x30);
       num=num%1000;
 
       UART_TxChar((num/100)+0x30);
       num=num%100;
 
       UART_TxChar((num/10)+0x30);
 
       UART_TxChar((num%10)+0x30);
}