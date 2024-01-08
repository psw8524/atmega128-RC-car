/*
 * autoDrive.c
 *
 * Created: 2023-12-02 오전 2:02:40
 *  Author: USER
 */ 

#include "autoDrive.h"

uint16_t cm[3];						// cm[0] == Left value, cm[1] == Forward value, cm[2] == Right value
char distanceStringValue[5] = "";
uint8_t stopFlag = STOP;

void AutoDriving(){
	ultrasonic_init();
	AllDistanceLcd(cm, distanceStringValue, TRIG_1);
	
	_delay_ms(1);
	
	if(cm[1] < 30){
		if(stopFlag == STOP){
			AutoMotorControl('0');			// stop
			_delay_ms(100);
			
			stopFlag = NONSTOP;
		}
		
		if(cm[0] > cm[2]){
			AutoMotorControl('7');		// left turn
			//_delay_ms(300);
		}else{
			AutoMotorControl('3');      // right turn
			//_delay_ms(300);
		}
	}else{
		AutoMotorControl('1');			// go straight
		stopFlag = STOP;
	}
}