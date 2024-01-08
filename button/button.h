/*
 * button.h
 *
 * Created: 2023-11-25 오전 3:28:31
 *  Author: USER
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR			DDRD
#define LED_PORT		PORTD
#define BUTTON_DDR		DDRA
#define BUTTON_PIN		PINA
#define BUTTON_ON		0
#define BUTTON_OFF		1
#define BUTTON_TOGGLE	2

enum {PUSHED=0, RELEASED};
enum {NO_ACT=10, ACT_PUSH, ACT_RELEASE};

typedef struct _button{
	volatile uint8_t *ddr;
	volatile uint8_t *pin;
	uint8_t btnPin;
	uint8_t prevState;
}Button;

void Button_init(Button *button, volatile uint8_t *ddr, volatile uint8_t *pin,  uint8_t pinNum);
uint8_t Button_getState(Button *button);
void ExiButton_init();


#endif /* BUTTON_H_ */