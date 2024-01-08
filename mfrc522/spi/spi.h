/*
 * spi.h
 *
 * Created: 2023-11-25 오전 3:09:05
 *  Author: USER
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>


#define SPI_DDR		DDRB
#define SPI_PORT	PORTB
#define SPI_PIN		PINB
#define SPI_SS_MFRC522		PB0
#define SPI_SCK		PB1
#define SPI_MOSI	PB2
#define SPI_MISO	PB3

void spi_init();
uint8_t spi_transmit(uint8_t data);
void spi_selectSlave(uint8_t ssPin);
void spi_deselectSlave(uint8_t ssPin);



#endif /* SPI_H_ */