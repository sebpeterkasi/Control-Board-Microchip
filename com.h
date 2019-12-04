#ifndef __COM_H

#include "config.h"

#include "libs/event.h"

void comInit(void);
void comReceiveByte(unsigned char, unsigned char);
void comReceiveArray(unsigned char *, unsigned char, unsigned char);

enum eeComDestination
{
	COM_DEST_USB = 0x01,
	COM_DEST_BT = 0x02,
	COM_DEST_ALL = 0x03
};

enum eeComSource
{
	COM_SRC_USB = 0,
	COM_SRC_BT
};

typedef enum eeComSource eComSource;
typedef enum eeComDestination eComDestination;

union uComPacket
{
	struct
	{
		unsigned char stx;
		unsigned char type;
		unsigned char len;
		unsigned char payload[128];
		unsigned char crc_val;
		
		volatile unsigned char * crc;
		unsigned char crc_cache;
		
		unsigned char src;														// packet source
		unsigned char pos;														// receive position
		unsigned char process;													// process flag
		unsigned long start;													// start timestamp
	} __attribute__ ((packed));
	
	unsigned char raw[128 + 3 + 1];												// 64 byte payload, 3 byte header + crc
};
typedef union uComPacket tComPacket;	

struct sComDestination
{
	
};
typedef struct sComDestination tComDestination;	

struct sComSource
{
	tComPacket packets[CONF_COM_BUFFER];
	
	volatile tComPacket * current;
	volatile tComPacket * next;
	
	unsigned char rd;
	unsigned char wr;
	unsigned char size;
	
	long receive_state;
};
typedef struct sComSource tComSource;

struct sCom
{
	tComSource src[2];															// two sources: bt or usb
	tComDestination dest[2];													// two destinations: ble, usb
};
typedef struct sCom tCom;	

struct sComEvents
{
	eventCallbackFunc cb[256];
};
typedef struct sComEvents tComEvents;

void comTransmitPacket(unsigned char, unsigned char, unsigned char *, eComDestination);
void comTransmitPacketAll(unsigned char, unsigned char, unsigned char *);
void comTransmitByte(unsigned char, eComDestination);

void comEventQueuePacket(volatile tComPacket *);
void comEventRegisterCB(eventCallbackFunc, unsigned char);


#define __COM_H
#endif