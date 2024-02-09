#include "adc.h"

void adcInit()
{
	// (1 << ADEN) enable adc
	// (1 << ADPS2) | (1 << ADPS1) prescaler f_cpu/64
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
}

int adcRead(unsigned char pin)
{
	// (1 << REFS0) Voltage Reference Selection use AVCC with external capacitor at AREF pin
	// (pin & 0xF0) Select pin adc
	// if you use pin 3
	// (3 & 0x0F)
	// (00000011 & 00001111)
	// (00000011)
	ADMUX = (1 << REFS0) | (pin & 0x0F);
	
	// start conversion adc
	ADCSRA |= (1 << ADSC);
	
	// Wait for the ADC conversion to complete
	// There is no exact time to determine how long the ADC conversion takes to complete
	// for that we use the ADIF bit in ADCSRA, if the conversion is not finished then the ADIF value = 0, if the conversion is finished then the ADIF value = 1
	
	// if the conversion has not been completed, ADIF=Bit4
	// (!(ADCSRA & (1 << ADIF)))
	// (!(11000110 & 00010000))
	// (!00000000)
	// (1) -> while keeps running
	
	// if the conversion is complete, ADIF=Bit4
	// (!(ADCSRA & (1 << ADIF)))
	// (!(11010110 & 00010000))
	// (!00000000)
	// (!16)
	// (0) -> while stops running
	while(!(ADCSRA & (1 << ADIF)));
	
	
	return ADC;	
}
