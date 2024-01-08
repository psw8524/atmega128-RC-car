/*
 * motor.h
 *
 * Created: 2023-11-23 오후 11:08:23
 *  Author: USER
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\timer\timer.h"

#define FORWARD 0x05
#define BACK 0x0a

void motor_init();
void motorRight(uint16_t rightspeed);
void motorLeft(uint16_t leftspeed);
void motorControl(char control);
void AutoMotorControl(char control);

#endif /* MOTOR_H_ */