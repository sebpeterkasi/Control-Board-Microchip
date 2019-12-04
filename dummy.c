#include "dummy.h"
#include "com.h"

short dummyCreate(void)
{
    static unsigned short last = 0;
    
    last++;
    
    return last;    
}

void dummySend(long data)
{    
    comTransmitPacket(1, sizeof(data), (unsigned char *)&data, COM_DEST_BT | COM_DEST_USB);
}