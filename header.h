/*
 * header.h
 *
 * Created: 25-09-2018 10:51:17
 *  Author: DESD
 */ 


#ifndef HEADER_H_
#define HEADER_H_

/*---------Preamble------------*/

#include <avr/io.h>
#include <string.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define BAUDRATE 9600
#define BAUD (F_CPU/(16UL*BAUDRATE))-1

void uart_init();
void uart_input_read(char []);
void uart_input_write(char []);
void uart_tx(char);
void led_init();
unsigned char uart_rx();



#endif /* HEADER_H_ */