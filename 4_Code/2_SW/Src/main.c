#include "My103.h"
#include "stm32f103xb.h"


int main(void){
	RCC_Config();
	ledInit();
	uint32_t i=0;
	while(1){

	  if(btn_pol()) {
	    ledOn(btn_pol());
	  }
	  else {
	    ledOffall();
	  }
    Delay_ms(1);

	}
}
