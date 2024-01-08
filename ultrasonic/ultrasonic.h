/*
 * ultrasonic.h
 *
 * Created: 2023-11-28 오전 3:22:51
 *  Author: USER
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\timer\timer.h"

#define TRIG_1 PORTF2
#define ECHO_1 PORTF3
#define TRIG_2 PORTF4
#define ECHO_2 PORTF5
#define TRIG_3 PORTF6
#define ECHO_3 PORTF7
#define SOUND_VELOCITY 340UL

void ultrasonic_init();
void distanceCheck(uint16_t *cm, uint8_t direction);

#endif /* ULTRASONIC_H_ */