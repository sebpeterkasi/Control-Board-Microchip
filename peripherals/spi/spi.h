/** @file 
 * $Rev:: 471                        $:  Revision of last commit
 * $Author:: Sebastian Peter         $:  Author of last commit
 * $Date:: 2013-03-30 15:18:52 +0100#$:  Date of last commit
 */

#ifndef __HRDW_H
#include "../../hardware.h"
#endif

#define SPI1Write	SPI1Read

void SPI1Init(void);
void SPI1Init16(void);
unsigned char SPI1Read(unsigned char data);
unsigned char SPI1Write(unsigned char data);
