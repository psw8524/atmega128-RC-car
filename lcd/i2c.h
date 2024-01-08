/*
 * i2c.h
 *
 * Created: 2023-11-24 오전 2:09:23
 *  Author: USER
 */ 

#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>

#define I2C_DDR	DDRD
#define I2C_SCL 0
#define I2C_SDA 1

void I2C_init();
void I2C_txByte(uint8_t SLA_W, uint8_t data);
void I2C_start();
void I2C_txDevAddr(uint8_t SLA_W);
void I2C_txData(uint8_t data);
void I2C_stop();

#endif /* I2C_H_ */