#include "hardware.h"

#include "libs/condition.h"

typedef struct sDevice tDevice;
typedef struct sDeviceState tDeviceState;
extern volatile tDevice device;

void deviceMaintenance(void);
void devicePowerOff(void *);
void deviceDelay(long);
void deviceReset(void);

// Events
void deviceBTStatusChangeEvent(void *);
void deviceSDCardStatusChangeEvent(void *);
void deviceUsbStatusChangeEvent(void *);
void deviceSecondEvent(void *);
void deviceMs100Event(void *);

// query values
inline unsigned long deviceGetMilliSec(void);

enum eUSBConnected
{
	USB_DISCONNECTED = 0x00,
	USB_CONNECTED,
	USB_ENUMERATED,
	USB_CDC_OPEN,
	USB_UNDEFINED,
};

enum eDevState
{
	DEV_BOOTING = 0,
	DEV_READY = 1,
	DEV_SHUTTING_DOWN = 2
};

enum eDevError
{
	DEV_ERROR_NONE = 0x00,
	DEV_ERROR_BAT_LOW
};

struct sDevice
{	
	struct
	{
		tCondition freq;
	} clock;

	struct
	{
		unsigned char ms100;
		unsigned char second;
		unsigned char debug;
		unsigned char log;
	} flags;
		
	struct
	{
		struct
		{
			unsigned long milli;
			unsigned long sec;

			struct
			{
				unsigned short milli;
			} digits;
		} rel;
		
		struct
		{
			
		} abs;

		struct
		{
			tEvent second;
			tEvent ms100;
			tEvent ms10;
		} event;
	} timer;	

	struct
	{
		tCondition status;
	} usb;

	struct
	{
		tCondition status;
	} bt;

	tCondition error;

	tCondition state;
};

