 /* 
 * File:   main.c
 * Author: Sebastian Peter
 *
 * Created on 17. December 2018, 03:48
 */

#include <stdio.h>
#include <stdlib.h>

#include "hardware.h"

#include "com.h"
#include "com_pc.h"

//#include "usb stack/usb.h"
//#include "usb stack/usb_function_cdc.h"

#include "peripherals/adxl345/adxl345.h"
#include "peripherals/i2c/i2c.h"
#include "peripherals/led/led.h"
#include "peripherals/ltc2942/ltc2942.h"
#include "peripherals/pps/pps.h"
#include "peripherals/spi/spi.h"
#include "peripherals/timer/timer.h"
#include "peripherals/uart/uart.h"
#include "device.h"

// CONFIG4
#pragma config DSWDTPS = DSWDTPSF       // DSWDT Postscale Select (1:2,147,483,648 (25.7 days))
#pragma config DSWDTOSC = LPRC          // Deep Sleep Watchdog Timer Oscillator Select (DSWDT uses Low Power RC Oscillator (LPRC))
#pragma config RTCOSC = SOSC            // RTCC Reference Oscillator Select (RTCC uses Secondary Oscillator (SOSC))
#pragma config DSBOREN = ON             // Deep Sleep BOR Enable bit (BOR enabled in Deep Sleep)
#pragma config DSWDTEN = OFF            // Deep Sleep Watchdog Timer (DSWDT disabled)

// CONFIG3
#pragma config WPFP = WPFP63            // Write Protection Flash Page Segment Boundary (Highest Page (same as page 42))
#pragma config SOSCSEL = IO             // Secondary Oscillator Pin Mode Select (SOSC pins have digital I/O functions (RA4, RB4))
#pragma config WUTSEL = FST             // Voltage Regulator Wake-up Time Select (Fast regulator start-up time used)
#pragma config WPDIS = WPDIS            // Segment Write Protection Disable (Segmented code protection disabled)
#pragma config WPCFG = WPCFGDIS         // Write Protect Configuration Page Select (Last page and Flash Configuration words are unprotected)
#pragma config WPEND = WPENDMEM         // Segment Write Protection End Page Select (Write Protect from WPFP to the last page of memory)

// CONFIG2
#pragma config POSCMOD = HS             // Primary Oscillator Select (HS Oscillator mode selected)
#pragma config I2C1SEL = PRI            // I2C1 Pin Select bit (Use default SCL1/SDA1 pins for I2C1 )
#pragma config IOL1WAY = ON             // IOLOCK One-Way Set Enable (Once set, the IOLOCK bit cannot be cleared)
#pragma config OSCIOFNC = OFF           // OSCO Pin Configuration (OSCO pin functions as clock output (CLKO))
#pragma config FCKSM = CSDCMD           // Clock Switching and Fail-Safe Clock Monitor (Sw Disabled, Mon Disabled)
#pragma config FNOSC = PRIPLL           // Initial Oscillator Select (Primary Oscillator with PLL module (XTPLL, HSPLL, ECPLL))
#pragma config PLL96MHZ = ON            // 96MHz PLL Startup Select (96 MHz PLL Startup is enabled automatically on start-up)
#pragma config PLLDIV = DIV4            // USB 96 MHz PLL Prescaler Select (Oscillator input divided by 12 (48 MHz input))
#pragma config IESO = ON                // Internal External Switchover (IESO mode (Two-Speed Start-up) enabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler (Prescaler ratio of 1:128)
#pragma config WINDIS = OFF             // Windowed WDT (Standard Watchdog Timer enabled,(Windowed-mode is disabled))
#pragma config FWDTEN = OFF             // Watchdog Timer (Watchdog Timer is disabled)
#pragma config ICS = PGx1               // Emulator Pin Placement Select bits (Emulator functions are shared with PGEC1/PGED1)
#pragma config GWRP = OFF               // General Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF                // General Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG port is disabled)

int main(int argc, char** argv)
{	
//	unsigned char usbBytesToRead = 0;
//	unsigned char usb_buffer[64];
	
	_LATINIT;
	_TRISINIT;
	_ANSINIT;
	
	_PMPEN = 0;
	_CPDIV = 0;
    
    timer1Init();                                                               // init timer 1 as system time base
    ppsInit();                                                                  // init peripheral pin select matrix
	ledInit();
	ledSetColor(RED);															// set led color red during boot process
    comInit();                                                                  // init communication protocol
    uart1Init(FCYC, 115200, 1, 1);                                              // init uart hardware
	i2c2Init();																	// init i2c hardware
	ltc2942Init();																// init batter gauge

	SPI1Init();																	// init SPI hardware
	adxl345Init();																// init accelerometer
	
	ltc2942Read(null);															// read battery state

	while(device.timer.rel.milli < 500)											// wait for 500ms
		ClrWdt();
	
	//USBDeviceInit();                                                          // init USB hardware
	//USBDeviceAttach();                                                        // attach USB device
    
	BT_RESET = 1;
	
	ledSetColor(BLUE);
	
    while(1)
    {
        if((USBDeviceState < ADR_PENDING_STATE))// || (USBSuspendControl==1) || U1OTGSTATbits.VBUSVD == 0)		// no USB link active == normal mode
		{
			if(U1OTGSTATbits.VBUSVD == 0)											// not connected, no voltage on usb line
			{
                
			}
			else
			{
                
			}
		}
		else if (USBDeviceState < CONFIGURED_STATE || (USBSuspendControl==1))	// USB enumeration in progress
		{
			
		}
		else																	// USB connected and enumerated
		{
			if(mUSBUSARTIsTxTrfReady())											// ready to transmit data?
				usbTransmitBufferContent();										// transmit if data is available

//			usbBytesToRead = getsUSBUSART(usb_buffer, 64);						// try to get next command
//
//			if(usbBytesToRead != 0)												// data received?
//				comReceiveArray(usb_buffer, usbBytesToRead, COM_SRC_USB);		// parse received commands
			
			CDCTxService();
        }
		
		//i2cQueueRunNextFunc();												// service i2c events
		//eventQueueService();													// service message queue
      
    }

    
    return (EXIT_SUCCESS);
}

