/*
 * autoDrive.h
 *
 * Created: 2023-12-02 오전 2:02:53
 *  Author: USER
 */ 


#ifndef AUTODRIVE_H_
#define AUTODRIVE_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define STOP		0
#define NONSTOP		1

#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\lcd\lcd.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\motor\motor.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\ultrasonic\ultrasonic.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\display\distance\distance.h"

void AutoDriving();

#endif /* AUTODRIVE_H_ */