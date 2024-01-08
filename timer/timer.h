/*
 * timer.h
 *
 * Created: 2023-11-25 오전 3:11:24
 *  Author: USER
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>

void TIM0_init();
void TIM1_init();
void TIM2_init();
void TIM2_Disable();
void TIM3_init();

#endif /* TIMER_H_ */