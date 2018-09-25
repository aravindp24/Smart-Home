/*
 * definitions.c
 *
 * Created: 25-09-2018 10:54:54
 *  Author: DESD
 */ 

/*-------Function Definitions---------*/
#include  "header.h"
void uart_init()
{
	UBRR1H=(BAUD)>>8;
	UBRR1L=BAUD;
	UCSR1B=(1<<TXEN1) | (1<<RXEN1);
	UCSR1C=(1<<UCSZ10) | (1<<UCSZ11);
	
}
void uart_input_read(char input[])          //Function to read input
{
	unsigned int i=0;
	do{
		input[i]=uart_rx();
		uart_tx(input[i]);
		i++;
	}while(input[i-1]!='\r');
	input[i-1]='\0';
	
}

void uart_input_write(char input[])         //Function tow write
{
	unsigned int i=0;
	while(input[i]!='\0')
	{
		uart_tx(input[i]);
		i++;
	}
	
}

unsigned char uart_rx()
{
	char character;
	while(!(UCSR1A & (1<<RXC1)));
	character=UDR1;
	return character;
}

void uart_tx(char character)
{
	
	while(!(UCSR1A & (1<<UDRE1)));
	UDR1=character;
}

void led_init()
{
	DDRC=0xff;
	PORTC=0xff;
}