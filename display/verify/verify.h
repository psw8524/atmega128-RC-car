/*
 * verify.h
 *
 * Created: 2023-11-25 오전 4:39:53
 *  Author: USER
 */ 


#ifndef VERIFY_H_
#define VERIFY_H_

#include <avr/io.h>
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\display\cardDB\cardDB.h"
#include "C:\Users\USER\Documents\Atmel Studio\7.0\first\first\display\request\request.h"

void ResponseVerify_checkCardNumber(uint8_t *data);

#endif /* VERIFY_H_ */