/*
 * bluetooth.c
 *
 * Created: 2023-11-24 오전 9:32:37
 *  Author: USER
 */ 

#include "bluetooth.h"

void Bluetooth_init(){
	// UART 통신 초기화
	UCSR1A = 0x00;
	UCSR1B |= (1 << RXCIE1) | (1 << RXEN1) | (1 << TXEN1);
	UCSR1C |= (1 << UCSZ11) | (1 << UCSZ10);
	
	UBRR1H = 0;
	UBRR1L = 103;
}

void UARTputchar(char c){
	while(!(UCSR1A & (1 << UDRE1)));
	UDR1 = c;
}

char UARTgetchar(){
	while(!(UCSR1A & (1 << RXC1)));
	
	return UDR1;
}

void UARTputs(char *ptr){
	while(*ptr){
		UARTputchar(*ptr);
		ptr++;
	}
}