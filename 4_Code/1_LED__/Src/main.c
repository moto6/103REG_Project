#include "BSP\bsp.h"
#include "common.h"
#include "stm32f103xb.h"
//ledInit();


GPIOA-> &= ~(0x2<<0|0x2<<4|0x2<<8|0x2<<12);

int main(void){
	while(1){
		ledOn(0);
		ledOff(0);

    }
}

