#include "../../hardware.h"

#define I2C_BUS_QUEUE_SIZE	8													// must be on the base of 2 => 2^x
#define I2C_FUNC_QUEUE_SIZE	8													// must be on the base of 2 => 2^x

typedef void (*i2cCallbackFunc)();

void i2c2Init(void);
char i2c2QueueReceiveLD(unsigned char, unsigned char, unsigned char *, unsigned short, i2cCallbackFunc);
char i2c2QueueTransmitLD(unsigned char, unsigned char, unsigned char *, unsigned short, i2cCallbackFunc);
char i2c2QueueReceiveHD(unsigned char, unsigned short, unsigned char *, unsigned short, i2cCallbackFunc);
char i2c2QueueTransmitHD(unsigned char, unsigned short, unsigned char *, unsigned short, i2cCallbackFunc);

char i2cQueuePutFunc(i2cCallbackFunc);
char i2cQueueRunNextFunc(void);

void I2C2Idle(void);

struct sI2C_com
{
	i2cCallbackFunc func;
	unsigned char adr_bus;
	unsigned short adr_int;
	unsigned char * data;
	unsigned short len;
	
	unsigned char priority;
	unsigned char op;
	unsigned char hd;
};	

struct sI2C_bus_queue
{
	struct sI2C_com element[I2C_BUS_QUEUE_SIZE];
	unsigned char next;
	unsigned char current;
	unsigned char items;
	
	unsigned char bus;
};	

struct sI2C_func_queue
{
	i2cCallbackFunc func[I2C_FUNC_QUEUE_SIZE];
	
	unsigned char next;
	unsigned char current;
	unsigned char items;
};
