 /*
 * RC_car.c
 *
 * Created: 2023-11-16 오후 8:52:14
 * Author : Seung Won Park
 */
 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "motor/motor.h"
#include "lcd/i2c.h"
#include "lcd/lcd.h"
#include "bluetooth/bluetooth.h"
#include "adc/adc.h"
#include "display/request/request.h"
#include "display/response/response.h"
#include "display/distance/distance.h"
#include "timer/timer.h"
#include "timetick/timetick.h"
#include "ultrasonic/ultrasonic.h"
#include "led/led.h"
#include "autoDrive/autoDrive.h"
#include "buzzer/buzzer.h"

#define PASS 1
#define FAIL 0

volatile uint8_t runningMode;
volatile uint16_t Tim2_counter;
char AlcoholStringValue[5] = "";
uint8_t adcInitState = 0;           // enable == 1, disable == 0
uint8_t AlcoholFlag;
uint16_t AlcoholValue;
uint8_t RfidFlag;
extern uint8_t rfidState;
extern uint8_t ControlCarState;
uint8_t AutoDrivingMode;

ISR(TIMER0_COMP_vect)
{
	incTick();
}

ISR(USART1_RX_vect){
	if(ControlCarState == DRIVING){
		if(AutoDrivingMode == FAIL){
			runningMode = UARTgetchar();
			motorControl(runningMode);
			UARTputchar(runningMode);
		}else{
			runningMode = UARTgetchar();
			UARTputchar(runningMode);
			if(runningMode == '0'){
				motorControl(runningMode);
				AutoDrivingMode = FAIL;
			}
		}
	}
}

ISR(TIMER2_OVF_vect){
	Tim2_counter++;
	TCNT2 = 7;
}

ISR(INT5_vect){
	if(ControlCarState == DRIVING){
		AutoDrivingMode = PASS;
		LCD_displayClear();
	}
}

int main(void){
	uint16_t CdsValue;
	
	Request_init();
	TIM0_init();
	ExiButton_init();
	Response_init();
	Bluetooth_init();
	motor_init();	
	led_init();
	buzzer_init();
	
	
	sei();
	
	while(1){
		// rfid 인식 단계
		if(RfidFlag == FAIL){
			Response_checkEvent();
			Request_excute();
			
			if(rfidState){
				RfidFlag = PASS;
				LCD_displayClear();
				
				BuzzerOn();
				_delay_ms(500);
				BuzzerOff();
			}
		}
		
		// 알콜센서 인식 단계
		if((RfidFlag == PASS) && (AlcoholFlag == FAIL)){
			while(ControlCarState == NONE){
				Control_checkButtonEvent();
			}
			
			if(adcInitState == FAIL){
				adc_init(CHANNEL_2);
				adcInitState = PASS;
				TIM2_init();
			}
			
			AlcoholValue = read_adc();
			Adc_numDisplay(AlcoholValue, AlcoholStringValue);
			LCD_writeStringXY(0, 0, "Value :");
			LCD_writeString(AlcoholStringValue);
			
			if(Tim2_counter > 5000){
				Tim2_counter = 0;
				TCNT2 = 7;
				
				if(AlcoholValue <= DRIVE_DRUNK){
					LCD_writeStringXY(1, 0, "Pass");
					AlcoholFlag = PASS;
					adcInitState = FAIL;
					
					TIM2_Disable();
				}else{
					LCD_writeStringXY(1, 0, "Fail");
				}
				
				BuzzerOn();
				_delay_ms(1500);
				BuzzerOff();
				LCD_displayClear();
			}
		}
		
		// 수동 주행 모드(UART1) + 자율 주행 모드
		if((RfidFlag == PASS) && (AlcoholFlag == PASS)){
			while(ControlCarState == ALCOHOL){
				Control_checkButtonEvent();
			}
			
			if(adcInitState == FAIL){
				adc_init(CHANNEL_1);
				adcInitState = PASS;
				LCD_writeStringXY(0, 0, "Driving Mode");
			}
			
			CdsValue = read_adc();
			_delay_ms(1);
			
			LedBrakeLightUp();
			
			if(CdsValue < LIGHTCONTROL){
				LedLightUp();
				}else{
				LedLightOff();
			}
			
			if(AutoDrivingMode == PASS){
				AutoDriving();
			}
		}
	}
}