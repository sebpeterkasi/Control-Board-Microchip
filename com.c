#include "com.h"

#include "device.h"

#include "libs/crc8.h"

#include "USB Stack/usb.h"
#include "peripherals/uart/uart.h"

volatile tCom com;
volatile tComEvents com_events;

void comInit(void)
{
	com.src[COM_SRC_USB].current = &com.src[COM_SRC_USB].packets[0];			// init com pointers, if not done prior first commuication
	com.src[COM_SRC_BT].current = &com.src[COM_SRC_BT].packets[0];              // program will cause exception
	com.src[COM_SRC_USB].next = &com.src[COM_SRC_USB].packets[0];				//
	com.src[COM_SRC_BT].next = &com.src[COM_SRC_BT].packets[0];                 //
}

void comEventRegisterCB(eventCallbackFunc func, unsigned char type)
{
	com_events.cb[type] = func;
}

void comEventQueuePacket(volatile tComPacket * packet)
{
	eventQueueEnqueueCB(com_events.cb[packet->type], (void *)packet);
}

void comTransmitPacketAll(unsigned char type, unsigned char len, unsigned char * data)
{
//	asm("di");
		comTransmitPacket(type, len, data, COM_DEST_USB | COM_DEST_BT);
//	asm("ei");
}	

void comTransmitPacket(unsigned char type, unsigned char len, unsigned char * data, eComDestination dest)
{
	unsigned long i;
	unsigned char crc;
	
	comTransmitByte(0x55, dest);												// transmit start byte
	crc = crc8calcByte(0x55, 0);
	
	comTransmitByte(type, dest);												// transmit type
	crc = crc8calcByte(type, crc);
	
	comTransmitByte(len, dest);													// transmit len
	crc = crc8calcByte(len, crc);
	
	for(i = 0; i < len; i++)
	{
		comTransmitByte(data[i], dest);											// transmit payload
		crc = crc8calcByte(data[i], crc);	
	}
	
	comTransmitByte(crc, dest);													// transmit crc
}	

void comTransmitByte(unsigned char data, eComDestination dest)
{
	if((dest & COM_DEST_USB) != 0 && USBDeviceState > CONFIGURED_STATE)
		usbTransmitByte(data);
	
	if((dest & COM_DEST_BT) != 0)
		uart1TransmitByte(data);
}

void comReceiveArray(unsigned char * data, unsigned char len, unsigned char src)
{
	unsigned char i;
	
	for(i = 0; i < len; i++)
	{
		comReceiveByte(data[i], src);											// parse received data byte per byte
	}
}

void comReceiveByte(unsigned char data, unsigned char src)
{
	volatile tComPacket * packet = com.src[src].next;							// select src & packet
	
	if(packet->start + CONF_COM_PACKET_TIMEOUT < deviceGetMilliSec())			// packet timeout
	{
		packet->raw[0] = 0;
		packet->pos = 0;
		packet->len = 0;
		packet->crc_cache = 0;
	}	
	
	packet->raw[packet->pos] = data;											// store data
	
	if(packet->stx == 0x55)														// packet start received
	{
		if(packet->pos == 0)													// this was the first byte we received?
		{
			packet->start = deviceGetMilliSec();								// store packet timestamp
			packet->src = src;													// assign source
		}
		
		if(packet->pos >= packet->len + 3)										// check if we received the last byte of the packet
		{
			if(packet->crc_cache == data)										// test if checksum matches
			{
				packet->crc = &packet->raw[packet->pos];						// store crc address
				packet->process = 1;											// mark packet ready for processing
				
				comEventQueuePacket(packet);									// queue packet
				
				__builtin_disi(0x3FFF);                                         // disable interrupts
					com.src[src].wr++;
					com.src[src].wr &= CONF_COM_BUFFER - 1;
					com.src[src].size;
				__builtin_disi(0);                                              // enable interrupts
			
				com.src[src].next = &com.src[src].packets[com.src[src].wr];		// assign next free slot
				
				// packet loopback for testing
				//comTransmitPacket(packet->type, packet->len, 0, packet->src);	// DEBUG
			}
			else																// crc error
			{
				packet->raw[0] = 0;
				packet->pos = 0;
				packet->len = 0;
				packet->crc_cache = 0;
			}
		}
		else
		{
			packet->crc_cache = crc8calcByte(data, packet->crc_cache);			// calculate checksum
		}
					
		packet->pos++;															// increment position flag
	}
}
