/*
 * distance.c
 *
 * Created: 2023-11-28 오전 4:14:57
 *  Author: USER
 */ 

#include "distance.h"

void ultrasonic_numDisplay(uint16_t value, char *str){
	str[0] = (value / 1000) + '0';
	str[1] = (value / 100) % 10 + '0';
	str[2] = (value / 10) % 10 + '0';
	str[3] = (value / 1) % 10 + '0';
	str[4] = '\0';
}

void LeftDistanceLcd(char *str){
	LCD_writeStringXY(0, 0, "L :");
	LCD_writeString(str);
}

void ForwardDistanceLcd(char *str){
	LCD_writeStringXY(1, 0, "F :");
	LCD_writeString(str);
}

void RightDistanceLcd(char *str){
	LCD_writeStringXY(1, 8, "R :");
	LCD_writeString(str);
}

void directionCheck(uint8_t direction, char *str){
	switch(direction){
		case 2 :
		LeftDistanceLcd(str);
		break;
		
		case 4 :
		ForwardDistanceLcd(str);
		break;
		
		case 6 :
		RightDistanceLcd(str);
		break;
	}
}

void AllDistanceLcd(uint16_t *cm, char *str, uint8_t direction){
	for(int i=0;i<3;i++){
		distanceCheck(cm + i, direction);
		ultrasonic_numDisplay(cm[i], str);
		directionCheck(direction, str);
		
		direction += 2;
	}
}
