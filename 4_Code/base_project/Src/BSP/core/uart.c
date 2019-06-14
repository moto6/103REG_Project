/*
 * uart.c
 *
 *  Created on: 2018. 5. 19.
 *      Author: Baram
 */

/*
 *  _DEF_UART1  : UART2
 *  _DEF_UART2  : LOOPBACK
 *
 */


#include <stdarg.h>

#include "uart.h"
#include "core/qbuffer.h"


#define UART_MODE_POLLING       0
#define UART_MODE_INTERRUPT     1
#define UART_MODE_DMA           2
#define UART_MODE_LOOPBACK      4


#define UART_RX_BUF_LENGTH      256


