/*
 * cardDB.h
 *
 * Created: 2023-11-25 오전 5:00:59
 *  Author: USER
 */ 


#ifndef CARDDB_H_
#define CARDDB_H_

#include <avr/io.h>
#include <string.h>

#define CARD_MAX	20
#define TRUE		1
#define FALSE		0

typedef struct _cardDB
{
	uint8_t cardCounter;
	uint8_t regCard[CARD_MAX][5];
}cardDB;

uint8_t CardDB_addCard(uint8_t *cardNum);
uint8_t CardDB_checkCardNumber(uint8_t *cardNum);
uint8_t CardDB_deleteCard(uint8_t *cardNum);


#endif /* CARDDB_H_ */