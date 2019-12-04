// ########################### debug macros

// battery
#define CONF_BAT_CHARGE_FULL			400										// [mAh]
#define CONF_BAT_FULL_THRESHOLD			4.05									// [V]
#define CONF_BAT_LOW_THRESHOLD			3.0										// [V]

// bluetooth
#define CONF_UART_TX_BUFFER				256 									// bytes

// com
#define CONF_COM_BUFFER					4										// Number of packets to buffer
#define CONF_COM_PACKET_TIMEOUT			300										// [ms] timeout for a single packet

// events
#define CONF_EVENT_QUEUE_SIZE			4										// maximum number of events buffered

// usb
#define CONF_USB_TX_BUFFER				256                             		//

/*
#ifndef __DEBUG
	#define __DEBUG
#endif*/

#ifndef NULL
	#define NULL							0
#endif

#ifndef null
	#define null							0
#endif

// here be dragons
