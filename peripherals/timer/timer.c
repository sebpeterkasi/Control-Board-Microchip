#include "timer.h"

#include "../../com_pc.h"
#include "../../device.h"
#include "../../dummy.h"

#include "../adxl345/adxl345.h"
#include "../led/led.h"

#include <string.h>
#include <stdio.h>

void __attribute__((__interrupt__, no_auto_psv)) _T1Interrupt(void)
{
	static unsigned short div10 = 0;
	static unsigned short div100 = 0;
	
    char buffer[64];
    
    IFS0bits.T1IF = 0;
    
	device.timer.rel.digits.milli++;
	device.timer.rel.milli++;
    
	div10++;
    
	adxl345Read();
	
	if(div10 >= 10)
	{
	sprintf(buffer, "%03x%d%03x%d\n", ((unsigned short)acc.x & 0xFFF), (short)(device.timer.rel.sec%2), device.timer.rel.digits.milli, (short)(1^(device.timer.rel.sec%2)));
	//comPcTransmitString(buffer, COM_DEST_ALL);
	ledModulate();
        
		div10 = 0;
		div100 += 10;
				
		if(div100 >= 100)
		{
			device.flags.ms100 = 1;
			div100 = 0;
		}
	}

	if(device.timer.rel.digits.milli >= 1000)
	{
		device.timer.rel.sec++;
		device.timer.rel.digits.milli = 0;
	}
}

void timer1Init(void)
{
	T1CON = 0x00;																// Stops the Timer2 and reset control reg.
	TMR1 = 0x00;																// Clear contents of the timer register
	PR1 = 15999;                                                                // Load the Period register

    IEC0bits.T1IE = 1;                                                          //
    
	T1CONbits.TCKPS = 0;                                                        // prescaler settings at 1:1
	T1CONbits.TON = 1;                                                          // Start Timer1 clock source set to the internal instruction cycle
}