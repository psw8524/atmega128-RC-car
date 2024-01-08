/*
 * buzzer.c
 *
 * Created: 2023-12-04 오전 1:42:16
 *  Author: USER
 */ 

#include "buzzer.h"

void buzzer_init(){
	DDRC |= (1 << DDRC7);
}

void BuzzerOn(){
	PORTC |= (1 << PORTC7);
}

void BuzzerOff(){
	PORTC &= ~(1 << PORTC7);
}
