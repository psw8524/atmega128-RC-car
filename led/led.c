/*
 * led.c
 *
 * Created: 2023-11-30 오후 3:52:53
 *  Author: USER
 */ 

#include "led.h"

void led_init(){
	DDRA |= (1 << DDRA2) | (1 << DDRA3) | (1 << DDRA4) | (1 << DDRA5) | (1 << DDRA6) | (1 << DDRA7); // [2:3] : headlight, [4:5] : taillight, [6:7] : brake
}

void LedLightUp(){
	PORTA |= (1 << PORTA2) | (1 << PORTA3) | (1 << PORTA4) | (1 << PORTA5);
}

void LedBrakeLightUp(){
	if((OCR3A == 0) && (OCR3B == 0)){					//속도가 0이면 
		PORTA |= (1 << PORTA6) | (1 << PORTA7);
	}else{
		PORTA &= ~((1 << PORTA6) | (1 << PORTA7));
	}
}

void LedLightOff(){
	PORTA &= ~((1 << PORTA2) | (1 << PORTA3) | (1 << PORTA4) | (1 << PORTA5));
}