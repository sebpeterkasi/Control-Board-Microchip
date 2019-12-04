#include "device.h"
#include "com.h"

volatile tDevice device;

inline unsigned long deviceGetMilliSec(void)
{
	return device.timer.rel.milli;
}

void deviceDelay(long time)
{
	/** creates a short stop with unprecise length
	* @param [in] time delay cycles
	*/
	while(time>0)
		time--;
}

void deviceUsbStatusChangeEvent(void * _data)
{
	if(device.usb.status.value == USB_DISCONNECTED)								// previously connected -> now disconnected
	{
		
	}
}

void deviceMaintenance(void)
{

}

void devicePowerOff(void * _data)
{

}

void deviceReset(void)
{
    
}
