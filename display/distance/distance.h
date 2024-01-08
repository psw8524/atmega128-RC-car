/*
 * distance.h
 *
 * Created: 2023-11-28 오전 4:15:12
 *  Author: USER
 */ 


#ifndef DISTANCE_H_
#define DISTANCE_H_

#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\ultrasonic\ultrasonic.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\lcd\lcd.h"


void ultrasonic_numDisplay(uint16_t value, char *str);
void LeftDistanceLcd(char *str);
void ForwardDistanceLcd(char *str);
void RightDistanceLcd(char *str);
void directionCheck(uint8_t direction, char *str);
void AllDistanceLcd(uint16_t *cm, char *str, uint8_t direction);


#endif /* DISTANCE_H_ */