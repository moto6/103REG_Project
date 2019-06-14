/*
 * hw.c
 *
 *  Created on: 2018. 5. 12.
 *      Author: Baram
 */


//#include "bsp/hw.h"





void hwInit(void)
{
  swtimerInit();
  ledInit();
  buttonInit();
  uartInit();
  timerInit();
  flashInit();
  eepromInit();
}

