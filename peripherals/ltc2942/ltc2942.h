#ifndef __HRDW_H
#include "../../hardware.h"
#endif

extern volatile struct sBat bat;

void ltc2942Init(void);
void ltc2942Sleep(void);
void ltc2942Read(void *);
void ltc2942Calc(void *);
inline void ltc2942SetFull(void);
inline void ltc2942NotFull(void);

void ltc2942ReadAll(void *);
void ltc2942CalcAll(void *);

struct sBat
{
	unsigned short voltage;
	unsigned short charge;
	unsigned short charge_start;
	unsigned short temperature;
	
	struct
	{
		float voltage;
		float voltage_min;
		struct
		{
			float now;
			float start;
		} charge;
		float temperature;
	}f;
	
	struct
	{
		enum
		{
			BAT_FULL,
			BAT_OK,
			BAT_LOW
		} simple;
		
		enum
		{
			CHARGING = 0x00,
			DISCHARGING
		} charging;	
		
		char valid;
		char changed;
	} state;	
};

typedef struct sBat tBat;

// ###### register map
#define LTC2942_REG_STATUS					0x00
#define LTC2942_REG_CONTROL					0x01
#define LTC2942_REG_ACC_CHARGE_MSB			0x02
#define LTC2942_REG_ACC_CHARGE_LSB			0x03
#define LTC2942_REG_CHARGE_THRE_HIGH_MSB	0x04	
#define LTC2942_REG_CHARGE_THRE_HIGH_LSB	0x05
#define LTC2942_REG_CHARGE_THRE_LOW_MSB		0x06
#define LTC2942_REG_CHARGE_THRE_LOW_LSB		0x07
#define LTC2942_REG_VOLT_MSB				0x08
#define LTC2942_REG_VOLT_LSB				0x09
#define LTC2942_REG_VOLT_THRE_HIGH			0x0A
#define LTC2942_REG_VOLT_THRE_LOW			0x0B
#define LTC2942_REG_TEMP_MSB				0x0C
#define LTC2942_REG_TEMP_LSB				0x0D
#define LTC2942_REG_TEMP_THRE_HIGH			0x0E
#define LTC2942_REG_TEMP_THRE_LOW			0x0F
