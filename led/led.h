/*
 * led.h
 *
 * Created: 2023-11-30 오후 3:53:04
 *  Author: USER
 */ 


#ifndef LED_H_
#define LED_H_

#include <avr/io.h>
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\motor\motor.h"

void led_init();
void LedLightUp();
void LedBrakeLightUp();
void LedLightOff();


#endif /* LED_H_ */