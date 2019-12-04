/** @file
 * $Rev:: 240                        $:  Revision of last commit
 * $Author:: Sebastian Peter         $:  Author of last commit
 * $Date:: 2011-12-10 00:56:51 +0100#$:  Date of last commit
 */

#include "led.h"

#include "../oc/oc.h"

tLed led_current;

void ledInit(void)
{
	oc1Init();
	oc2Init();
	oc3Init();
}

void ledSetColor(unsigned long color)
{
	led_current.red = (color >> 16) & 0xFF;
	led_current.green = (color >> 8) & 0xFF;
	led_current.blue = color & 0xFF;
	
	ledTransfer();
}

void ledSetGamma(unsigned short gamma)
{
	led_current.gamma = gamma;
	
	ledTransfer();
}

void ledSet(unsigned long color, unsigned short gamma)
{	
	led_current.red = (color >> 16) & 0xFF;
	led_current.green = (color >> 8) & 0xFF;
	led_current.blue = color & 0xFF;
	led_current.gamma = gamma;
	
	ledTransfer();
}

void ledModulate(void)
{
	static unsigned short gamma = 155;
	static unsigned char direction;
	
	ledSetGamma(gamma);
	
	if(gamma >= 255)
		direction = 1;
	else if(gamma <= 50)
		direction = 0;
	
	if(direction == 0)
		gamma+=3;
	else
		gamma-=3;
}

void ledTransfer(void)
{
	OC1R = OC1RS - led_current.red * led_current.gamma;
	OC2R = OC2RS - led_current.green * led_current.gamma;
	OC3R = OC3RS - led_current.blue * led_current.gamma;	
}