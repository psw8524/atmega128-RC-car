/*
 * verifyState.c
 *
 * Created: 2023-11-25 오전 5:05:28
 *  Author: USER
 */ 

#include "verifyState.h"

uint8_t VerifyStateData = VERIFY;

void VerifyStateModel_setState(uint8_t state)
{
	VerifyStateData = state;
}

uint8_t VerifyStateModel_getState()
{
	return VerifyStateData;
}