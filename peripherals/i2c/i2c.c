/** @file 
 *  @author Sebastian Peter
 * 
 *  @version 0.1 
 *  doxygen comments added
 */

#include "i2c.h"

#include "../../device.h"

volatile struct sI2C_bus_queue i2c2_bus_queue;
volatile struct sI2C_func_queue i2c_func_queue;

void __attribute__((__interrupt__, no_auto_psv)) _MI2C2Interrupt(void)
{
	static unsigned char bus = 0;
	static unsigned short pos = 0;

	_MI2C2IF = 0;																// clear IF

//	device.timer.timeout.milli.i2c = 0;											// workaround for stalling i2c bus issue

	if(i2c2_bus_queue.items != 0)
	{
		i2c2_bus_queue.bus = 1;													// bus-flag -> busy
	
		if(i2c2_bus_queue.element[i2c2_bus_queue.current].op == 0)				// write
		{
			switch(bus)
			{
				case 0:															// bus idle, create start condition
					I2C2CONbits.SEN = 1;
					bus++;
				break;
				
				case 1:															// send bus address
					I2C2TRN = i2c2_bus_queue.element[i2c2_bus_queue.current].adr_bus;
					if(i2c2_bus_queue.element[i2c2_bus_queue.current].hd == 1)
						bus++;
					else
						bus += 2;
				break;
				
				case 2:					// send higher byte of internal address
					I2C2TRN = i2c2_bus_queue.element[i2c2_bus_queue.current].adr_int >> 8;
					bus++;
				break;
				
				case 3:				// send lower byte of internal address
					I2C2TRN = i2c2_bus_queue.element[i2c2_bus_queue.current].adr_int;
					bus++;
				break;
				
				case 4:				// transmit data
					I2C2TRN = i2c2_bus_queue.element[i2c2_bus_queue.current].data[pos++];
					
					if(pos >= i2c2_bus_queue.element[i2c2_bus_queue.current].len)
					{
						bus++;
						pos = 0;
					
						if(i2c2_bus_queue.element[i2c2_bus_queue.current].func != 0)
						{
							if(i2c2_bus_queue.element[i2c2_bus_queue.current].priority == 1)
								i2c2_bus_queue.element[i2c2_bus_queue.current].func();
							else
								i2cQueuePutFunc(i2c2_bus_queue.element[i2c2_bus_queue.current].func);
						}
					}
				break;
				
				case 5:					// create stop condition
					I2C2CONbits.PEN = 1;
					bus = 0;
					i2c2_bus_queue.current = (i2c2_bus_queue.current+1)&(I2C_BUS_QUEUE_SIZE-1);
					i2c2_bus_queue.items--;
				break;
			}
		}
		else		// read
		{
			i2c2_bus_queue.bus = 1;		// bus-flag -> busy
		
			switch(bus)
			{
				case 0:					// bus idle, create start condition
					I2C2CONbits.SEN = 1;
					bus++;
				break;
				
				case 1:					// send bus address
					I2C2TRN = i2c2_bus_queue.element[i2c2_bus_queue.current].adr_bus;
					if(i2c2_bus_queue.element[i2c2_bus_queue.current].hd == 1)
						bus++;
					else
						bus += 2;
				break;
				
				case 2:					// send higher byte of internal address
					I2C2TRN = i2c2_bus_queue.element[i2c2_bus_queue.current].adr_int >> 8;
					bus++;
				break;
				
				case 3:					// send lower byte of internal address
					I2C2TRN = i2c2_bus_queue.element[i2c2_bus_queue.current].adr_int;
					bus++;
				break;
				
				case 4:					// create repeated start condition
					I2C2CONbits.RSEN = 1;
					bus++;
				break;
				
				case 5:					// send bus address
					I2C2TRN = i2c2_bus_queue.element[i2c2_bus_queue.current].adr_bus | 0x01;
					bus++;
				break;
				
				case 6:					// enable receive
					I2C2CONbits.RCEN = 1;
					bus++;
				break;
				
				case 7:					// store last received byte
					i2c2_bus_queue.element[i2c2_bus_queue.current].data[pos++] = I2C2RCV;
					
					if(pos >= i2c2_bus_queue.element[i2c2_bus_queue.current].len)
					{
						I2C2CONbits.ACKDT = 1;
						bus++;
						I2C2CONbits.RCEN = 0;
						pos = 0;
						
						if(i2c2_bus_queue.element[i2c2_bus_queue.current].func != 0)
						{
							if(i2c2_bus_queue.element[i2c2_bus_queue.current].priority == 1)
								i2c2_bus_queue.element[i2c2_bus_queue.current].func();
							else
								i2cQueuePutFunc(i2c2_bus_queue.element[i2c2_bus_queue.current].func);
						}								
					}
					else
					{
						I2C2CONbits.ACKDT = 0;
						bus--;	
					}
					
					I2C2CONbits.ACKEN = 1;
				break;
				
				case 8:					// create stop condition
					I2C2CONbits.PEN = 1;
					bus = 0;
					i2c2_bus_queue.current = (i2c2_bus_queue.current+1)&(I2C_BUS_QUEUE_SIZE-1);
					i2c2_bus_queue.items--;
				break;
			}
		}
	}
	else
	{
		i2c2_bus_queue.bus = 0;		// bus flag -> idle
	}	
}

void i2c2Init(void)
{
	/** init i2c2 module and queues
	*/

	I2C2CONbits.I2CEN = 0;														// disable I2C module
	I2C2CONbits.I2CSIDL = 0;													// Continue module operation in Idle mode
	I2C2CONbits.IPMIEN = 0;														// IPMI Support mode disabled
	I2C2CONbits.DISSLW = 1;														// Slew rate control disabled
	I2C2CONbits.SMEN = 0;														// Disable SMBus input thresholds
	I2C2CONbits.GCEN = 0;														// General call address disabled
	
	I2C2BRG = 0x0025;															// 400kHz @ 16MHz

    I2C2RCV = 0x0000;
    I2C2TRN = 0x0000;
	
	_MI2C2IP = 1;																// assign low priority
	_MI2C2IF = 0;																// clear IF
	_MI2C2IE = 1;																// enable interrupt
	
	i2c2_bus_queue.items = 0;
	i2c2_bus_queue.current = 0;
	i2c2_bus_queue.next = 0;

	i2c2_bus_queue.bus = 0;														// bus flag -> idle
	
    I2C2CONbits.I2CEN = 1;														// I2C2 Enable bit
}
	
char i2c2QueueTransmitLD(unsigned char adr_bus, unsigned char adr_int, unsigned char * data, unsigned short len, i2cCallbackFunc func)
{
	/** puts one transmit packet for low density device into queue
	* @param [in] adr_bus i2c device bus address
	* @param [in] adr_int i2c device internal address
	* @param [in,out] data pointer to data array
	* @param [in] len length of transmission
	* @param [in] func pointer to callback function, set parameter value to zero if you don't want to provide a callback function
	*/
	
	__builtin_disi(0x3FFF);				// disable all interrupts
	if(i2c2_bus_queue.items < I2C_BUS_QUEUE_SIZE)
	{
		i2c2_bus_queue.element[i2c2_bus_queue.next].op = 0;					// write
		i2c2_bus_queue.element[i2c2_bus_queue.next].hd = 0;					// low density device
		i2c2_bus_queue.element[i2c2_bus_queue.next].adr_bus = adr_bus & 0xFE;	// mask r/w bit
		i2c2_bus_queue.element[i2c2_bus_queue.next].adr_int = adr_int;
		i2c2_bus_queue.element[i2c2_bus_queue.next].data = data;
		i2c2_bus_queue.element[i2c2_bus_queue.next].len = len;
		i2c2_bus_queue.element[i2c2_bus_queue.next].func = func;
		
		i2c2_bus_queue.next = (i2c2_bus_queue.next+1)&(I2C_BUS_QUEUE_SIZE-1);
		
		i2c2_bus_queue.items++;
		
		if(i2c2_bus_queue.bus == 0)
			_MI2C2IF = 1;
		
		__builtin_disi(0);				// reenable all interrupts
		
		return 1;
	}
	else
	{
		__builtin_disi(0);				// reenable all interrupts
		
		return -1;
	}
}

char i2c2QueueReceiveLD(unsigned char adr_bus, unsigned char adr_int, unsigned char * data, unsigned short len, i2cCallbackFunc func)
{
	/** puts one receive packet for low density device into queue
	* @param [in] adr_bus i2c device bus address
	* @param [in] adr_int i2c device internal address
	* @param [out] data pointer to data array
	* @param [in] len length of transmission
	* @param [in] func pointer to callback function, set parameter value to zero if you don't want to provide a callback function
	*/
	
	__builtin_disi(0x3FFF);				// disable all interrupts
	if(i2c2_bus_queue.items < I2C_BUS_QUEUE_SIZE)
	{
		i2c2_bus_queue.element[i2c2_bus_queue.next].op = 1;					// read
		i2c2_bus_queue.element[i2c2_bus_queue.next].hd = 0;					// low density device
		i2c2_bus_queue.element[i2c2_bus_queue.next].adr_bus = adr_bus & 0xFE;	// mask r/w bit
		i2c2_bus_queue.element[i2c2_bus_queue.next].adr_int = adr_int;
		i2c2_bus_queue.element[i2c2_bus_queue.next].data = data;
		i2c2_bus_queue.element[i2c2_bus_queue.next].len = len;
		i2c2_bus_queue.element[i2c2_bus_queue.next].func = func;
		
		i2c2_bus_queue.next = (i2c2_bus_queue.next+1)&(I2C_BUS_QUEUE_SIZE-1);
		
		i2c2_bus_queue.items++;
		
		if(i2c2_bus_queue.bus == 0)
			_MI2C2IF = 1;
			
		__builtin_disi(0);				// reenable all interrupts
		
		return 1;
	}
	else
	{
		__builtin_disi(0);				// reenable all interrupts
		
		return -1;
	}
}

	
char i2c2QueueTransmitHD(unsigned char adr_bus, unsigned short adr_int, unsigned char * data, unsigned short len, i2cCallbackFunc func)
{
	/** puts one transfer packet for high density device into queue
	* @param [in] adr_bus i2c device bus address
	* @param [in] adr_int i2c device internal address
	* @param [in] data pointer to data array
	* @param [in] len length of transmission
	* @param [in] func pointer to callback function, set parameter value to zero if you don't want to provide a callback function
	*/

	__builtin_disi(0x3FFF);				// disable all interrupts
	if(i2c2_bus_queue.items < I2C_BUS_QUEUE_SIZE)
	{
		i2c2_bus_queue.element[i2c2_bus_queue.next].op = 0;					// write
		i2c2_bus_queue.element[i2c2_bus_queue.next].hd = 1;					// high density device
		i2c2_bus_queue.element[i2c2_bus_queue.next].adr_bus = adr_bus & 0xFE;	// mask r/w bit
		i2c2_bus_queue.element[i2c2_bus_queue.next].adr_int = adr_int;
		i2c2_bus_queue.element[i2c2_bus_queue.next].data = data;
		i2c2_bus_queue.element[i2c2_bus_queue.next].len = len;
		i2c2_bus_queue.element[i2c2_bus_queue.next].func = func;
		
		i2c2_bus_queue.next = (i2c2_bus_queue.next+1)&(I2C_BUS_QUEUE_SIZE-1);
		
		i2c2_bus_queue.items++;
		
		if(i2c2_bus_queue.bus == 0)
			_MI2C2IF = 1;
		
		__builtin_disi(0);				// reenable all interrupts
		
		return 1;
	}
	else
	{
		__builtin_disi(0);				// reenable all interrupts
		
		return -1;
	}
}

char i2c2QueueReceiveHD(unsigned char adr_bus, unsigned short adr_int, unsigned char * data, unsigned short len, i2cCallbackFunc func)
{
	/** puts one transfer packet for high density device into queue
	* @param [in] adr_bus i2c device bus address
	* @param [in] adr_int i2c device internal address
	* @param [in,out] data pointer to data array
	* @param [in] len length of transmission
	* @param [in] func pointer to callback function, set parameter value to zero if you don't want to provide a callback function
	*/

	__builtin_disi(0x3FFF);				// disable all interrupts
	if(i2c2_bus_queue.items < I2C_BUS_QUEUE_SIZE)
	{
		i2c2_bus_queue.element[i2c2_bus_queue.next].op = 1;					// read
		i2c2_bus_queue.element[i2c2_bus_queue.next].hd = 1;					// high density device
		i2c2_bus_queue.element[i2c2_bus_queue.next].adr_bus = adr_bus & 0xFE;	// mask r/w bit
		i2c2_bus_queue.element[i2c2_bus_queue.next].adr_int = adr_int;
		i2c2_bus_queue.element[i2c2_bus_queue.next].data = data;
		i2c2_bus_queue.element[i2c2_bus_queue.next].len = len;
		i2c2_bus_queue.element[i2c2_bus_queue.next].func = func;
		
		i2c2_bus_queue.next = (i2c2_bus_queue.next+1)&(I2C_BUS_QUEUE_SIZE-1);
		
		i2c2_bus_queue.items++;
		
		if(i2c2_bus_queue.bus == 0)
			_MI2C2IF = 1;
			
		__builtin_disi(0);				// reenable all interrupts
		
		return 1;
	}
	else
	{
		__builtin_disi(0);				// reenable all interrupts
		
		return -1;
	}
}

char i2cQueuePutFunc(i2cCallbackFunc func)
{
	__builtin_disi(0x3FFF);				// disable all interrupts
	if(i2c_func_queue.items < I2C_FUNC_QUEUE_SIZE)
	{
		i2c_func_queue.func[i2c_func_queue.next] = func;
		
		i2c_func_queue.items++;
		i2c_func_queue.next = (i2c_func_queue.next+1)&(I2C_FUNC_QUEUE_SIZE-1);
		
		__builtin_disi(0);				// reenable all interrupts

		return 1;
	}
	else
	{
		__builtin_disi(0);				// reenable all interrupts
		
		return -1;
	}	
}

char i2cQueueRunNextFunc(void)
{
	if(i2c_func_queue.items > 0)
	{
		i2c_func_queue.func[i2c_func_queue.current]();
		
		i2c_func_queue.items--;
		i2c_func_queue.current = (i2c_func_queue.current+1)&(I2C_FUNC_QUEUE_SIZE-1);

		return 1;
	}
	else
	{
		return -1;
	}	
}

void I2C2Idle(void)
{
	ClrWdt();

    while(I2C2CONbits.SEN || I2C2CONbits.PEN || I2C2CONbits.RCEN || I2C2CONbits.ACKEN || I2C2STATbits.TRSTAT || i2c2_bus_queue.items != 0 || i2c2_bus_queue.bus != 0);
}
