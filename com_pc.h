#include "com.h"

typedef struct sPCPacket tPCPacket;

void comPcEventRegisterCB(eventCallbackFunc, unsigned char);

char comPcTransmitString(char *, eComDestination);

void comPcReset(void *);

struct sPCPacket
{
	unsigned char type;
	unsigned char payload[32];
} __attribute__ ((packed));

struct sComPcEvents
{
	eventCallbackFunc cb[256];
};
typedef struct sComPcEvents tComPcEvents;