#include "uart.h"

#include "../led/led.h"
#include "../../com.h"
#include <stdio.h>
#include <math.h>

volatile tUARTBufferTX uart_tx;

void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void)
{
	unsigned short cache;
    char light='R';
    while(U1STAbits.URXDA == 1)
    {
        cache = U1RXREG;
        //comReceiveByte(cache, COM_SRC_BT);
        uart1TransmitByte(cache);
//        uartReceiveCommand(cache);
        if(light==cache)
        {
        ledSetColor(RED);
        }
    }   
    
    IFS0bits.U1RXIF = 0;
}

void __attribute__((__interrupt__, no_auto_psv)) _U1TXInterrupt(void)
{    
    while(uart_tx.size > 0 && U1STAbits.UTXBF == 0)
    {
        U1TXREG = uart_tx.data[uart_tx.ptr_rd];

		__builtin_disi(0x3FFF);                                                 // disable interrupts
            uart_tx.ptr_rd++;
            uart_tx.ptr_rd &= (CONF_UART_TX_BUFFER - 1);
            uart_tx.size--;
		__builtin_disi(0);                                                      // enable interrupts
	}
    
    IFS0bits.U1TXIF = 0;
}

void uart1Init(unsigned long per_clock, unsigned long baud, unsigned char rx_ie, unsigned char tx_ie)
{
	unsigned long brg;
	unsigned long brgh;

	uartCalcBRG(per_clock, baud, &brg, &brgh);
    
    U1MODE = 0;
    U1STA = 0;
    
    U1MODEbits.UEN = 0b10;                                                      // UxTX, UxRX, UxCTS and UxRTS pins are enabled and used
    U1MODEbits.BRGH = brgh;                                                     // High speed
    
    U1STAbits.UTXISEL0 = 1;                                                     // Interrupt generated when the last transmission is over (last character shifted out of the Transmit
                                                                                // Shift Register) and all the transmit operations are completed
    
    U1BRG = brg;                                                                // 115200 @ 16MHz    
        
    U1MODEbits.UARTEN = 1;                                                      // UARTx is enabled; UARTx pins are controlled by UARTx as defined by UEN<1:0> and UTXEN control bits
    U1STAbits.UTXEN = 1;                                                        // enable transmission
    
    IFS0bits.U1TXIF = 0;
    IEC0bits.U1TXIE = tx_ie;
    
    IFS0bits.U1RXIF = 0;
    IEC0bits.U1RXIE = rx_ie;                                                    // enable interrupt
}

inline char uart1TransmitByte(unsigned char data)
{
    char state = -1;

	__builtin_disi(0x3FFF);                                                     // disable interrupts
	    if(uart_tx.size < CONF_UART_TX_BUFFER)
	    {
			uart_tx.data[uart_tx.ptr_wr] = data;
	        uart_tx.size++;
	        uart_tx.ptr_wr++;
	        uart_tx.ptr_wr &= CONF_UART_TX_BUFFER - 1;

	        state = 1;
	    }
	__builtin_disi(0);                                                          // enable interrupts

	IFS0bits.U1TXIF = 1;

    return state;
}

char uart1TransmitString(char * data)
{
    while(*data != '\0')
    {
        uart1TransmitByte(*data);
        data++;
    }
    
    return 1;
}

char uartCalcBRG(unsigned long per_clock, unsigned long baud, unsigned long * brg, unsigned long * brgh)
{
	unsigned long brg_high, brg_low;
	float err_high, err_low;

	brg_high = (per_clock / (4 * baud)) - 1;
	brg_low = (per_clock / (16 * baud)) - 1;

	err_high = (((float)per_clock/(4.0*((float)brg_high+1.0))) - baud) / baud;
	err_low = (((float)per_clock/(16.0*((float)brg_low+1.0))) - baud) / baud;

	if(fabs(err_high) < fabs(err_low))
	{
		*brg = brg_high;
		*brgh = 1;
	}
	else
	{
		*brg = brg_low;
		*brgh = 0;
	}

	return 1;
}



//void uartReceiveCommand(char data)
//{
//// static char data_cache[128]; // buffer for 128 characters
// //static char data_position; // pointer to last value
//  int result=0;
// //data_cache[data_position] = data;
// //data_position++;
// 
// //ledSetColor(GREEN);
// //if(data == '\n') // we received a newline-character (usually end of line)
// //{
//  // do whatever you want
//   char convertedCode = 'R';
//
//   if(data==convertedCode){
//       ledSetColor(GREEN);
//   }else{
//       ledSetColor(RED);
//   }
//   printf("data is %c\n",data);
//  printf("This is the result %d of comparing %c & %c\n",result,data,convertedCode);
// 
////  data_position = 0; // reset last character pointer to zero to start new reception
//// }
//}