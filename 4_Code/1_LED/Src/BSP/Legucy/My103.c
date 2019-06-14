#include "My103.h"
#include "stm32f103xb.h"


void Delay_us(unsigned int time_us)		/* time delay for us in 8MHz */
{
  register unsigned int i;

  for(i = 0; i < time_us; i++)			// 3 cycle
    { asm volatile("NOP");
      asm volatile("NOP");
      asm volatile("NOP");
      asm volatile("NOP");
      asm volatile("NOP");			// 5 cycle
    }
}

void Delay_ms(unsigned int time_ms)		/* time delay for ms in 8MHz */
{
  register unsigned int i;

  for(i = 0; i < time_ms; i++)
    Delay_us(1000);
}

void SerialPutChar(char c)
{

    while((USART1->SR & 0x80) == 0);    // 데이터가 TDR에서 Shift Register로 옮겨지기 전까지 기다림.
    USART1->DR = c;    // 데이터를 USART1_DR 레지스터에 씀

}

void Serial_PutString(char* s)
{    // 문자열 출력

    while(*s != '\0'){
        SerialPutChar(*s);
        s++;
    }
}

void EXTI_Config(void)
{
	AFIO->EXTICR[4] = 0x0020;
	EXTI->IMR 		= 0x01<<13;//
	EXTI->EMR 		= 0x01<<13;
    EXTI->RTSR 		= 0x01<<13;
}

void RCC_Config(void)
{

	RCC->CFGR	= 0x001F8402;
	RCC->CR    	= 0x01010082;
	RCC->APB2ENR |= 0x14;		// PA,PC 활성화
	GPIOA->CRL = 0x33333333;	// PortA 10MHz, General push-pull Output
	GPIOC->CRL = 0x33333333;	// PortC 10MHz, General push-pull Output


}
