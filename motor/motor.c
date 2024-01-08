/*
 * motor.c
 *
 * Created: 2023-11-23 오후 11:08:11
 *  Author: USER
 */ 

#include "motor.h"

void motor_init(){
	DDRC |= (1 << DDRC3) | (1 << DDRC2) | (1 << DDRC1) | (1 << DDRC0);
	DDRE |= (1 << DDRE3) | (1 << DDRE4);
	
	TIM3_init();
}

void motorRight(uint16_t rightspeed){
	OCR3B = rightspeed; 
}

void motorLeft(uint16_t leftspeed){
	OCR3A = leftspeed;
}

void motorControl(char control){
	switch(control){
		case '0' :
		PORTC = FORWARD;
		
		motorRight(0);
		motorLeft(0);
		break;
		
		case '1' :
		PORTC = FORWARD;
		
		motorRight(2499);
		motorLeft(2499);
		break;
		
		case '2' :
		PORTC = FORWARD;
		
		motorRight(1000);
		motorLeft(2499);
		break;
		
		case '3' :
		PORTC = FORWARD;
		
		motorRight(0);
		motorLeft(2499);
		break;
		
		case '4' :
		PORTC = BACK;
		
		motorRight(1000);
		motorLeft(2499);
		break;
		
		case '5' :
		PORTC = BACK;
		
		motorRight(2499);
		motorLeft(2499);
		break;
		
		case '6' :
		PORTC = BACK;
		
		motorRight(2499);
		motorLeft(1000);
		break;
		
		case '7' :
		PORTC = FORWARD;
		
		motorRight(2499);
		motorLeft(0);
		break;
		
		case '8' :
		PORTC = FORWARD;
		
		motorRight(2499);
		motorLeft(1000);
		break;
	}
}

void AutoMotorControl(char control){
	switch(control){
		case '0' :
		PORTC = FORWARD;
		
		motorRight(0);
		motorLeft(0);
		break;
		
		case '1' :
		PORTC = FORWARD;
		
		motorRight(1000);
		motorLeft(1000);
		break;
		
		case '2' :
		PORTC = FORWARD;
		
		motorRight(1000);
		motorLeft(2499);
		break;
		
		case '3' :
		PORTC = FORWARD;
		
		motorRight(0);
		motorLeft(2499);
		break;
		
		case '4' :
		PORTC = BACK;
		
		motorRight(1000);
		motorLeft(2499);
		break;
		
		case '5' :
		PORTC = BACK;
		
		motorRight(2499);
		motorLeft(2499);
		break;
		
		case '6' :
		PORTC = BACK;
		
		motorRight(2499);
		motorLeft(1000);
		break;
		
		case '7' :
		PORTC = FORWARD;
		
		motorRight(2499);
		motorLeft(0);
		break;
		
		case '8' :
		PORTC = FORWARD;
		
		motorRight(2499);
		motorLeft(1000);
		break;
	}
}