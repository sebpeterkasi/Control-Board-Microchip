#include "../../hardware.h"

void uart1Init(unsigned long, unsigned long, unsigned char, unsigned char);
void uart2Init(unsigned long, unsigned long, unsigned char, unsigned char);
char uartCalcBRG(unsigned long, unsigned long, unsigned long *, unsigned long *);

char uart1PutTx(unsigned char);
void uart1Suspend(void);
void uart1Resume(void);
inline char uart1TransmitByte(unsigned char);
char uart1TransmitString(char *);

typedef struct sBTBufferTX
{
	unsigned char data[CONF_UART_TX_BUFFER];

	unsigned short ptr_wr;
	unsigned short ptr_rd;
	unsigned short size;
} tUARTBufferTX;
