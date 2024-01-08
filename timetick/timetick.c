/*
 * timetick.c
 *
 * Created: 2023-11-25 오전 3:32:20
 *  Author: USER
 */ 

#include "timetick.h"

uint32_t timeTick = 0;

void incTick()
{
	timeTick++;
}

uint32_t getTick()
{
	return timeTick;
}

void clearTick()
{
	timeTick = 0;
}