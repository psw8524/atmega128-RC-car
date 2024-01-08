/*
 * adc.h
 *
 * Created: 2023-11-24 오전 9:43:34
 *  Author: USER
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

#define CHANNEL_1		PORTF0
#define CHANNEL_2		PORTF1
#define ALCOHOLPASS		0x01
#define ALCOHOLFAIL     0x00
#define DRIVE_DRUNK		300			// 음주 측정 기준치
#define LIGHTCONTROL	200			// 전조등, 후미등 온오프 기준

void adc_init(uint8_t channel);
uint16_t read_adc();
void Adc_numDisplay(uint16_t value, char *str);


#endif /* ADC_H_ */