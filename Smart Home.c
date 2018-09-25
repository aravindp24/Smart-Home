/*
 * Program to implement miniature Smart Home Software in ATmega64A
 * Created: 17-09-2018 10:08:24 in Atmel Studio 6.2
 *  Author: Aravind P
 */ 
#include "header.h"
/*--------Main Function------*/
int main(void)
{  
	uart_init();
	led_init();
	DDRA=0xff;
    
	char user_name[15],user_pwd[15],light[15];          /*Declaration of commands and uart display */
	char username[]="abc",password[]="password";
	char welcome[]="\r\nWelcome to Smart Home\r\n";
	char usrdisp[]="Enter your username\r\n";
    char pwddisp[]="\r\nEnter your password\r\n";
    char success[]="\r\nLogin Successful\r\n";
	char fail[]="Login failed\r\n";
	char led[]="LIGHTS ON";
	char cmd[]="Enter command:\r\n";
	
	_delay_ms(1000);        
	uart_input_write(welcome);                             /*User Read data */
	_delay_ms(1000);                              
	uart_input_write(usrdisp);
	uart_input_read(user_name);
    uart_input_write(pwddisp);
    uart_input_read(user_pwd);
	
    if(!(strcmp(username,user_name) || strcmp(password,user_pwd)))            //Authentication
	{uart_input_write(success);
   
   uart_input_write(cmd);
	uart_input_read(light);
	
	if((strcmp(light,led)==0))                                    //Light command authentication
	PORTC=0x00;
	PORTA=1<<PA3;
	_delay_ms(1000);
	PORTA=0<<PA3;
	}
	else
	uart_input_write(fail);

}

