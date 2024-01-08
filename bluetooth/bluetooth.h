/*
 * bluetooth.h
 *
 * Created: 2023-11-24 오전 9:33:24
 *  Author: USER
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include <avr/io.h>

void Bluetooth_init();
void UARTputchar(char c);
char UARTgetchar();
void UARTputs(char *ptr);

#endif /* BLUETOOTH_H_ */