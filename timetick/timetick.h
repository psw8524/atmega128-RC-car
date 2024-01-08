/*
 * timetick.h
 *
 * Created: 2023-11-25 오전 3:32:29
 *  Author: USER
 */ 


#ifndef TIMETICK_H_
#define TIMETICK_H_

#include <avr/io.h>

void incTick();
uint32_t getTick();
void clearTick();


#endif /* TIMETICK_H_ */