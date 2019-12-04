/** @file 
 *  @author Sebastian Peter
 * 
 *  @version 0.1 
 *  comments added
 */

#include "adxl345.h"

#include "../spi/spi.h"

#include <stdio.h>
#include <string.h>

unsigned char adxl345_offs[] = { 0x00, 0x00, 0x00 };
unsigned char adxl345_config[] = { 0x08, 0x08 | ACC_RANGE16G, ACC_DR1600, 0x00, 0x04 };
unsigned char adxl345_data[6];

tAccelerometer acc;

volatile char adxl345_ready = 0;

void adxl345Init(void)
{
	/** initialize accelerometer
	*/
	adxl345WriteSingleRegister(ACC_DATA_FORMAT, adxl345_config[1]);				// enable 4 wire mode
	adxl345WriteRegisters(ACC_OFSX, &adxl345_offs[0], 3);						// reset all offsets to zero
	adxl345WriteSingleRegister(ACC_POWER_CTL, adxl345_config[0]);				// 
	adxl345WriteSingleRegister(ACC_BW_RATE, adxl345_config[2]);					// set bandwidth
	adxl345WriteSingleRegister(ACC_INT_ENABLE, adxl345_config[3]);				// disable all interrupts

	adxl345Ready();
}

void adxl345Ready(void)
{
	adxl345_ready = 1;
	adxl345Read();
}

void adxl345Sleep(void)
{
	/** put accelerometer to sleep
	*/

	adxl345WriteSingleRegister(ACC_POWER_CTL, adxl345_config[4]);				// put device into sleep mode
}	

void adxl345Read(void)
{
	/** reads accelerometer values to struct acc
	*/
	
	if(adxl345_ready == 1)
	{
		adxl345ReadRegisters(ACC_DATAX0, adxl345_data, 6);
		adxl345Calc();
	}
}

void adxl345WriteSingleRegister(unsigned char reg, unsigned char data)
{
	ACC_CS = 0;

	SPI1Write(reg & 0x3F);														// write access, single byte
	SPI1Write(data);

	ACC_CS = 1;
}

void adxl345WriteRegisters(unsigned char reg, unsigned char * data, unsigned char len)
{
	unsigned char i;

	ACC_CS = 0;

	SPI1Write((reg & 0x3F) | 0x40);												// write access, multiple bytes

	for(i = 0; i < len; i++)
	{
		SPI1Write(data[i]);
	}

	ACC_CS = 1;
}

unsigned char adxl345ReadSingleRegister(unsigned char reg)
{
	unsigned char data;

	ACC_CS = 0;

	SPI1Write(reg | 0x80);														// read access, single byte

	data = SPI1Read(0xFF);

	ACC_CS = 1;

	return data;
}

void adxl345ReadRegisters(unsigned char reg, unsigned char * data, unsigned char len)
{
	unsigned char i;

	ACC_CS = 0;

	SPI1Write(reg | 0xC0);														// read access, multiple bytes

	for(i = 0; i < len; i++)
	{
		data[i] = SPI1Read(0);
	}

	ACC_CS = 1;
}

void adxl345Calc(void)
{	
	acc.x = (short)adxl345_data[1]<<8 | adxl345_data[0];
	acc.y = (short)adxl345_data[3]<<8 | adxl345_data[2];
	acc.z = (short)adxl345_data[5]<<8 | adxl345_data[4];

	acc.x_g = (float)acc.x / 250.0;
	acc.y_g = (float)acc.y / 250.0;
	acc.z_g = (float)acc.z / 250.0;
}

void adxl345Calibrate(void)
{
	/** calibrates accelerometer to the first measured value after power up
	* (hoping that the device is in horizontal position)
	*/
	adxl345Read();
	
	acc.x_offset = - acc.x / 4;
	acc.y_offset = - acc.y / 4;
	acc.z_offset = (250 - acc.z)/4;
}
