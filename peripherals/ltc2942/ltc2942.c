#include "ltc2942.h"

#include "../i2c/i2c.h"

#include "../../device.h"

volatile tBat bat = { .state.simple = BAT_FULL };

unsigned char bat_i2c_cache[4] = {0b11111010, 0b00111010, (unsigned short)(CONF_BAT_CHARGE_FULL / 0.085) >> 8, (unsigned short)(CONF_BAT_CHARGE_FULL / 0.085) & 0xFF};
unsigned char bat_i2c_charge_cache[2];
unsigned char bat_i2c_voltage_cache[2];
unsigned char bat_i2c_temp_cache[2];

unsigned char bat_status_cache;

void ltc2942Init(void)
{
	bat.f.voltage = 4.15;
	bat.f.voltage_min = 4.15;
	
	i2c2QueueTransmitLD(LTC2942_ADR, LTC2942_REG_CONTROL, &bat_i2c_cache[0], 1, null);
}

void ltc2942Sleep(void)
{
	i2c2QueueTransmitLD(LTC2942_ADR, LTC2942_REG_CONTROL, &bat_i2c_cache[1], 1, null);
}

void ltc2942Read(void * data)
{
	i2c2QueueReceiveLD(LTC2942_ADR, LTC2942_REG_ACC_CHARGE_MSB, bat_i2c_charge_cache, 2, null);
	i2c2QueueReceiveLD(LTC2942_ADR, LTC2942_REG_VOLT_MSB, bat_i2c_voltage_cache, 2, ltc2942Calc);
}	

void ltc2942ReadAll(void * data)
{
	i2c2QueueReceiveLD(LTC2942_ADR, LTC2942_REG_ACC_CHARGE_MSB, bat_i2c_charge_cache, 2, null);
	i2c2QueueReceiveLD(LTC2942_ADR, LTC2942_REG_VOLT_MSB, bat_i2c_voltage_cache, 2, null);
	i2c2QueueReceiveLD(LTC2942_ADR, LTC2942_REG_TEMP_MSB, bat_i2c_temp_cache, 2, ltc2942CalcAll);
}	

void ltc2942Calc(void * data)
{
	static unsigned char start = 0;
	
	bat.charge = (unsigned short)((unsigned short)bat_i2c_charge_cache[0] << 8) | bat_i2c_charge_cache[1];
	bat.voltage = (unsigned short)((unsigned short)bat_i2c_voltage_cache[0] << 8) | bat_i2c_voltage_cache[1];

	bat.f.voltage = ((float)bat.voltage/65535.0)*6.0;							// calculate current voltage
	bat.f.charge.now = ((float)bat.charge*0.085);								// calculate current charge level
	
	if(start == 0)																// store start values
	{
		bat.f.charge.start = bat.f.charge.now;									// store start charge for later processing
		bat.charge_start = bat.charge;											// store start charge for later processing
		start = 1;
	}	

	bat.state.valid = 1;
}	

void ltc2942CalcAll(void * data)
{
	ltc2942Calc(data);																// calculate minimal parameters
	
	bat.temperature = (unsigned int)(bat_i2c_temp_cache[0] << 8) | bat_i2c_temp_cache[1];
	bat.f.temperature = (((float)bat.temperature/(float)0xFFFF)*600.0) - 273.16;
}	

inline void ltc2942SetFull(void)
{
	i2c2QueueTransmitLD(LTC2942_ADR, LTC2942_REG_ACC_CHARGE_MSB, &bat_i2c_cache[2], 2, null);
}	

inline void ltc2942NotFull(void)
{
//	BAT_ALARM = 0;	
}	