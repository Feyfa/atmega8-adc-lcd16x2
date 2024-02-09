#include <avr/io.h>
#include "adc/adc.h"
#include "toString/toString.h"
#include "lcd16x2_PD/lcd16x2_PD.h"

int main(void)
{
	// Create variables to hold adc0 and adc1
	uint16_t adc0 = 0 , adc1 = 0;
	
	// PC0 and PC1 are used as input
	DDRC &= ~(1 << 0 | 1 << 1);
	
	// Init for adc
	adcInit();
	
	// Init for lcd uses PD region
	lcdInit_PD();
	
	while (1)	
	{
		// Read adc on pin PC0
		adc0 = adcRead(0);
		// Read adc on pin PC1
		adc1 = adcRead(1);
		
		// print "adc0 = " in x = 0 , y = 0
		lcdPrintWithCursor_PD(0, 0, "adc0 = ");
		// print value adc0 use IntegerToString, this parameter can only accept strings
		lcdPrint_PD(IntegerToString(adc0));
		lcdPrint_PD("   ");
		
		// print "adc1 = " in x = 0 , y = 1
		lcdPrintWithCursor_PD(0, 1, "adc1 = ");
		// print value adc1 use IntegerToString, this parameter can only accept strings
		lcdPrint_PD(IntegerToString(adc1));
		lcdPrint_PD("   ");
	}
	
}

