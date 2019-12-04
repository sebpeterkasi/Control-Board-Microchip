#include "oc.h"

void oc1Init(void)
{
	PMD2bits.OC1MD = 0;

	OC1R = 0xFFFF;																// 0% duty cycle
	OC1RS = 0xFFFF;
	
	OC1CON1bits.OCM = 6;														// PWM mode
	OC1CON2bits.SYNCSEL = 0x1F;
	OC1CON2bits.OCTRIG = 0;
	OC1CON1bits.OCTSEL = 7;														// use system clock
}

void oc2Init(void)
{
	PMD2bits.OC2MD = 0;

	OC2R = 0xFFFF;																// 0% duty cycle
	OC2RS = 0xFFFF;
	
	OC2CON1bits.OCM = 6;														// PWM mode
	OC2CON2bits.SYNCSEL = 0x1F;
	OC2CON2bits.OCTRIG = 0;
	OC2CON1bits.OCTSEL = 7;														// use system clock
}

void oc3Init(void)
{
	PMD2bits.OC3MD = 0;

	OC3R = 0xFFFF;																// 0% duty cycle
	OC3RS = 0xFFFF;
	
	OC3CON1bits.OCM = 6;														// PWM mode
	OC3CON2bits.SYNCSEL = 0x1F;
	OC3CON2bits.OCTRIG = 0;
	OC3CON1bits.OCTSEL = 7;														// use system clock
}
