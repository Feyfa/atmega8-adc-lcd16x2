/*
 * adc.h
 *
 * Created: 08/02/2024 20:26:47
 *  Author: fisik
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void adcInit();
int adcRead(unsigned char pin);

#endif /* ADC_H_ */