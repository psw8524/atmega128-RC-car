/*
 * button.c
 *
 * Created: 2023-11-25 오전 3:28:43
 *  Author: USER
 */ 

#include "button.h"

 // 1번 스위치
void Button_init(Button *button, volatile uint8_t *ddr, volatile uint8_t *pin,  uint8_t pinNum) 
{
	button->ddr = ddr;
	button->pin = pin;
	button->btnPin = pinNum;
	button->prevState = RELEASED;
	*button->ddr &= ~(1<<button->btnPin);
}

uint8_t Button_getState(Button *button)
{
	//static uint8_t prevState = RELEASED;
	uint8_t curState = *button->pin & (1<<button->btnPin);
	
	if ((curState == PUSHED) && (button->prevState == RELEASED)) {
		_delay_ms(50); // debounce
		button->prevState = PUSHED;
		return ACT_PUSH;
	}
	else if ((curState != PUSHED) && (button->prevState == PUSHED)) {
		_delay_ms(50); // debounce
		button->prevState = RELEASED;
		return ACT_RELEASE;
	}
	return NO_ACT;
}

//2번 스위치
void ExiButton_init(){
	DDRE |= (0 << DDRE5);
	PORTE |= (1 << PORTE5);					    // 내부 풀업
	
	EICRB |= (1 << ISC51) | (1 << ISC50);		// falling edge
	EIMSK |= (1 << INT5);
}