#include "My103.h"
#include "stm32f103xb.h"


int main(void){

	RCC_Config();
	EXTI_Config();
	int i = 0;


	while(1){

		for(i=0;i<=7;i++)
		{
			GPIOC->BSRR = 0x1<<i;
			GPIOC->BSRR = 0x1<<(i+15);
    		Delay_ms(100);
        }

	    for(i=0;i<=7;i++)
        {
			GPIOC->BSRR = 0x1<<(7-i);
			GPIOC->BRR = 0X1<<(8-i);
    		Delay_ms(100);
        }
	    GPIOC->BRR = 0X1<<(1);

    }
}


void EXTI0_IRQHandler(void)
{
	printf(" 0번 \r\n");
}

void EXTI1_IRQHandler(void)
{
	printf(" 1번 \r\n");
}

void EXTI15_10_IRQHandler(void)
{
	GPIOA->BSRR |= 0x20;
	Delay_ms(100);
	GPIOA->BRR |= 0x20;
	Delay_ms(100);
	GPIOA->BSRR |= 0x20;
	Delay_ms(100);
	GPIOA->BRR |= 0x20;
	Delay_ms(100);

}

void USART3_IRQHandler(void)
{

}


//      GPIOC->BSRR = 0x0000ffff;
//      Delay_ms(500);
//      GPIOC->BSRR = 0xffff0000;
//      Delay_ms(500);
//      GPIOC->BSRR = 0x0000ffff;
//      Delay_ms(500);
//      GPIOC->BSRR = 0xffff0000;
//      Delay_ms(500);
//      GPIOC->BSRR = 0x0000ffff;
//		Delay_ms(1000);
//		GPIOC->BSRR = 0xFFFF0000;
//		Delay_ms(100);
//		GPIOC->BSRR = 0x0000FFFF;
//		Delay_ms(100);
//		GPIOC->BSRR = 0xFFFF0000;
//		Delay_ms(100);
//		GPIOC->BSRR = 0x0000FFFF;
//		Delay_ms(100);
//		GPIOC->BSRR = 0xFFFF0000;
//		Delay_ms(100);
//		GPIOC->BSRR = 0x0000FFFF;
//		Delay_ms(100);

//		PC13 Floating Input
//		GPIOC->CRH = (GPIOC->CRH & 0xFF0FFFFF)|(0x00400000);



/* switch input code

    if((GPIOC->IDR & 0x2000) == 0){    // PC13 핀 상태가 LOW 이면
        GPIOA->BSRR |= 0x20;            // LED ON
    }
    else{
        GPIOA->BRR |= 0x20;            // LED OFF
    }

 */
