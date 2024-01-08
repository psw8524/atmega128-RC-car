/*
 * ultrasonic.c
 *
 * Created: 2023-11-28 오전 3:22:36
 *  Author: USER
 */ 

#include "ultrasonic.h"

void ultrasonic_init(){
	DDRF |= ((1 << TRIG_1) | (1 << TRIG_2) | (1 << TRIG_3)) & ~((1 << ECHO_1) | (1 << ECHO_2) | (1 << ECHO_3));
	
}

void distanceCheck(uint16_t *cm, uint8_t direction){
	TIM1_init();
	PORTF &= ~(1 << direction); // Trig low
	_delay_us(10);
	PORTF |= (1 << direction);  // 거리 측정 시작
	_delay_us(10);
	PORTF &= ~(1 << direction); // 거리 측정 끝
	
	while(!((PINF) & (1 << (direction + 1))));// echo가 high가 될때까지 대기
	
	TCNT1 = 0x00; // 타이머값 초기화
	
	while((PINF) & (1 << (direction + 1))); // echo가 low가 될때까지 대기
	
	TCCR1B = 0x00; // 타이머 클럭 정지
	*cm = (unsigned int)(SOUND_VELOCITY * (TCNT1 * 4 / 2) / 10000); // 거리(cm)
}