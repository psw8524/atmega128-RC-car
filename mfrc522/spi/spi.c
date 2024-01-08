/*
 * spi.c
 *
 * Created: 2023-11-25 오전 3:08:50
 *  Author: USER
 */ 

#include "spi.h"

void spi_init()
{
	SPI_DDR |= (1<<SPI_SS_MFRC522) | (1<<SPI_SCK) | (1<<SPI_MOSI);
	SPI_DDR &= ~(1<<SPI_MISO);
	SPCR |= (1<<SPE) | (1<<MSTR); // Master Mode
	SPCR |= (1<<SPR0); // 1Mbps
}

uint8_t spi_transmit(uint8_t data)
{
	SPDR = data;
	while (!(SPSR & (1<<SPIF)));
	
	return SPDR;
}

void spi_selectSlave(uint8_t ssPin)
{
	SPI_PORT &= ~(1<<ssPin);
}

void spi_deselectSlave(uint8_t ssPin)
{
	SPI_PORT |= (1<<ssPin);
}