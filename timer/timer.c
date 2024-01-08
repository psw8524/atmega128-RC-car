/*
 * timer.c
 *
 * Created: 2023-11-25 오전 3:11:35
 *  Author: USER
 */ 

#include "timer.h"

void TIM0_init(){ 
	TCCR0 |= (1 << CS02) | (0 << CS01) | (0 << CS00); // 1/64 분주
	TCCR0 |= (1 << WGM01) | (0 << WGM00); // CTC Mode
	TIMSK |= (1 << OCIE0);
	OCR0 = 249; // 1ms 간격으로 인터럽트 발생
}

void TIM1_init(){
	TCCR1B = (1 << CS11) | (1 << CS10); // 64분주 (4us);
}

void TIM2_init(){
	TCCR2 |= (0 << CS22) | (1 << CS21) | (1 << CS20); // 64분주
	TCNT2 = 7; // 1ms 간격으로 인터럽트 발생
	TIMSK |= (1 << TOIE2);
}

void TIM2_Disable(){
	TCCR2 = 0x00;
	TCNT2 = 0x00;
	TIMSK &= ~(1 << TOIE2);
}

void TIM3_init(){
	TCCR3A = (1 << COM3A1) | (1 << COM3B1) | (1 << WGM31);
	TCCR3B = (1 << WGM33) | (1 << WGM32) | (1 << CS31) | (1 << CS30);
	ICR3 = 2499;
}

