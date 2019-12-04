#include "pps.h"

#include <pps.h>

void ppsInit(void)
{
	asm volatile ( "MOV #OSCCON, w1 \n"
	"MOV #0x46, w2 \n"
	"MOV #0x57, w3 \n"
	"MOV.b w2, [w1] \n"
	"MOV.b w3, [w1] \n"
	"BCLR OSCCON,#6");
		// unlock sequence	
	
	OUT_PIN_PPS_RP7 = OUT_FN_PPS_U1TX;                                          // U1TX @ RP7
    IN_FN_PPS_U1RX = IN_PIN_PPS_RP4;                                            // U1RX @ RP4
	OUT_PIN_PPS_RP21 = OUT_FN_PPS_U1RTS;										// U1RTS @ RP21
	IN_FN_PPS_U1CTS = IN_PIN_PPS_RP20;											// U1CTS @ RP20
	
    IN_FN_PPS_SDI1 = IN_PIN_PPS_RP5;                                            // SDI @ RP4
	OUT_PIN_PPS_RP14 = OUT_FN_PPS_SDO1;											// SDO1 @ RP14
	OUT_PIN_PPS_RP8 = OUT_FN_PPS_SCK1OUT;										// SCK1 @ RP8
	
	_RP23R = OUT_FN_PPS_OC1;													// LED_R @ RP23
	_RP24R = OUT_FN_PPS_OC2;													// LED_G @ RP24
	_RP25R = OUT_FN_PPS_OC3;													// LED_B @ RP25
	
	asm volatile ( "MOV #OSCCON, w1 \n"
	"MOV #0x46, w2 \n"
	"MOV #0x57, w3 \n"
	"MOV.b w2, [w1] \n"
	"MOV.b w3, [w1] \n"
	"BSET OSCCON,#6");
		// lock sequence
}
