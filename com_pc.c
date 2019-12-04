#include "com_pc.h"

#include "device.h"

#include <string.h>
#include <time.h>

tComPcEvents com_pc_events;

void comPcEventRegisterCB(eventCallbackFunc func, unsigned char type)
{
	com_pc_events.cb[type] = func;
}

void comPcReset(void * _data)
{
	deviceReset();
}

char comPcTransmitString(char * data, eComDestination dest)
{
    while(*data != '\0')
    {
        comTransmitByte(*data, dest);
        data++;
    }
    
    return 1;
}