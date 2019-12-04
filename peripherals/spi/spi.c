/** @file 
 * $Rev:: 240                        $:  Revision of last commit
 * $Author:: Sebastian Peter         $:  Author of last commit
 * $Date:: 2011-12-10 00:56:51 +0100#$:  Date of last commit
 */
 
#include "spi.h"

void SPI1Init(void)
{
	PMD1bits.SPI1MD = 0;

	SPI1STATbits.SPIEN = 0;

	SPI1CON1bits.CKE = 0;
	SPI1CON1bits.CKP = 1;
	SPI1CON1bits.SPRE = 7;														// sec. prescaler 1
	SPI1CON1bits.PPRE = 2;														// pri. prescaler 4
	SPI1CON1bits.MSTEN = 1;														// enable master mode
	SPI1CON2bits.SPIBEN = 0;													// Enhanced Buffer disabled

	SPI1STATbits.SPIEN = 1;
}

unsigned char SPI1Read(unsigned char data)
{
	/** read/writes byte from/to SPI1 hardware
	* @param [in] data data to be send
	* @return received value
	*/
	
    SPI1STATbits.SPIROV = 0;
    SPI1BUF = data;
    while (!SPI1STATbits.SPIRBF);
    data = SPI1BUF;
    return data;
}