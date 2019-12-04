#include "../hardware.h"

#define CRC_DYNAMIC		0

#if CRC_DYNAMIC == 1
	void crc8Init(unsigned char);
#else
	void crc8Init(void);
#endif

unsigned short crc8calc(unsigned char *, unsigned char, unsigned short);
unsigned short crc8calcByte(unsigned char, unsigned short);
