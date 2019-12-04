 /* 
 * File:   main.c
 * Author: sebastian peter
 *
 * Created on 17. December 2018, 03:48
 */

#ifndef HARDWARE_H
#define	HARDWARE_H

#include <xc.h>

#include "config.h"

#define FOSC		32000000

#define ACC_CS		IO3OUT

// bluetooth
#define BT_RESET	LATAbits.LATA8
#define BT_STAT0	PORTAbits.RA4
#define BT_STAT1	PORTAbits.RA7

// battery
#define LTC2942_ADR				0xC8

// gpio
#define IO1OUT		LATCbits.LATC0
#define IO2OUT		LATCbits.LATC1
#define IO3OUT		LATCbits.LATC2
#define IO4OUT		LATCbits.LATC3
#define IO5OUT		LATCbits.LATC0
#define IO6OUT		LATCbits.LATC0
#define IO7OUT		LATCbits.LATC0
#define IO8OUT		LATCbits.LATC0
#define IO9OUT		LATCbits.LATC0
#define IO10OUT		LATCbits.LATC0

// power management
#define PMIC_PWRON	LATCbits.LATC6
#define PMIC_PBSTAT	PORTBbits.RB14
#define PMIC_CHRG	PORTBbits.RB5

//							  5432109876543210
#define TRISADATA			0b1111111011111111
#define TRISBDATA			0b1111111111111111
//							  5432109876543210
#define TRISCDATA           0b1111111110111011

//							  5432109876543210
#define LATADATA			0b0000000000000000
#define LATBDATA			0b0000000000000000
//					 		  5432109876543210
#define LATCDATA            0b0000000001000100

//			  		 		  5432109876543210
#define AD1PCFGDATA			0b1111111111111111

// ########################## dont change anything below that line
#define FCYC				(FOSC/2)
#define _TRISINIT			TRISA = TRISADATA; TRISB = TRISBDATA; TRISC = TRISCDATA
#define _ANSINIT			AD1PCFG = AD1PCFGDATA;
#define _LATINIT			LATA = LATADATA; LATB = LATBDATA; LATC = LATCDATA

#endif	/* HARDWARE_H */

