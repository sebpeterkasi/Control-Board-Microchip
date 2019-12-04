#ifndef __HRDW_H
#include "../../hardware.h"
#endif

#define ACC_ADDRESS		0xA6
#define ACC_LOW_POWER	0x01													// set to 1 for low power, to zero for normal operation

typedef struct sAccelerometer tAccelerometer;

void adxl345Init(void);
void adxl345Ready(void);
void adxl345Read(void);
void adxl345Calc(void);
void adxl345Calibrate(void);
void adxl345Sleep(void);

void adxl345WriteSingleRegister(unsigned char, unsigned char);
void adxl345WriteRegisters(unsigned char, unsigned char *, unsigned char);

unsigned char adxl345ReadSingleRegister(unsigned char);
void adxl345ReadRegisters(unsigned char, unsigned char *, unsigned char);

struct sAccelerometer
{
	int x;
	int y;
	int z;

	char x_offset;
	char y_offset;
	char z_offset;

	double x_g;
	double y_g;
	double z_g;

	struct
	{
		char str[64];
		char len;
	} result;
};

#define ACC_ID				0x00
#define ACC_TAP_THRES		0x1D
#define ACC_OFSX			0x1E
#define ACC_OFSY			0x1F
#define ACC_OFSZ			0x20
#define ACC_DUR				0x21
#define ACC_LATENT			0x22
#define ACC_WINDOW			0x23
#define ACC_THRESH_ACT		0x24
#define ACC_THRESH_INACT	0x25
#define ACC_TIME_INACT		0x26
#define ACC_ACT_INACT_CTL	0x27
#define ACC_THRESH_FF		0x28
#define ACC_TIME_FF			0x29
#define ACC_TAP_AXES		0x2A
#define ACC_ACT_TAP_STATUS	0x2B
#define ACC_BW_RATE			0x2C
#define ACC_POWER_CTL		0x2D
#define ACC_INT_ENABLE		0x2E
#define ACC_INT_MAP			0x2F
#define ACC_INT_SOURCE		0x30
#define ACC_DATA_FORMAT		0x31
#define ACC_DATAX0			0x32
#define ACC_DATAX1			0x33
#define ACC_DATAY0			0x34
#define ACC_DATAY1			0x35
#define ACC_DATAZ0			0x36
#define ACC_DATAZ1			0x37
#define ACC_FIFO_CTL		0x38
#define ACC_FIFO_STATUS		0x39

#define ACC_DR6				0x06
#define ACC_DR12			0x07
#define ACC_DR25			0x08
#define ACC_DR50			0x09
#define ACC_DR100			0x0A
#define ACC_DR200			0x0B
#define ACC_DR400			0x0C
#define ACC_DR800			0x0D
#define ACC_DR1600			0x0E
#define ACC_DR3200			0x0F

#define ACC_RANGE2G			0x00
#define ACC_RANGE4G			0x01
#define ACC_RANGE8G			0x02
#define ACC_RANGE16G		0x03

extern tAccelerometer acc;