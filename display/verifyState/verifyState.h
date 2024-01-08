/*
 * verifyState.h
 *
 * Created: 2023-11-25 오전 5:05:19
 *  Author: USER
 */ 


#ifndef VERIFYSTATE_H_
#define VERIFYSTATE_H_

#include <avr/io.h>

enum {VERIFY, ADD, DELETE};

void VerifyStateModel_setState(uint8_t state);
uint8_t VerifyStateModel_getState();


#endif /* VERIFYSTATE_H_ */