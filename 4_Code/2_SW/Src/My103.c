#include "My103.h"
#include "stm32f103xb.h"


void RCC_Config(void)
{
	RCC->CR |= 0x1;
	while(!(RCC->CR&0x2));
	RCC->CFGR= 0x0;
//
//		RCC->CFGR	= 0x001F8402;
//		RCC->CR    	= 0x01010082;
//		RCC->APB2ENR |= 0x14;
}

void ledInit(void)
{
  RCC->APB2ENR |= 0x14;
	//GPIOA->CRL = GPIOA->CRL | (0x3<<0) | (0x3<<4) | (0x3<<8) | (0x3<<12);
	GPIOA->CRL |= 0x2222;	// PortA 10MHz, General push-pull Output
	GPIOA->CRL &= ~0xdddd;
}

void ledOn(uint8_t ch)
{
  if(ch) {
    GPIOA->ODR |= (0x1<<(ch-1));
  }
}

void ledOff(uint8_t ch)
{
  if(ch) {
	GPIOA->ODR &= (~(0x1<<(ch-1)));
  }
}

void ledOffall(void)
{
  GPIOA->ODR &= (~(0xf));

}

void ledToggle(uint8_t ch)
{

  if( GPIOA->ODR & (0x1<<(ch)) ) {
    GPIOA->BSRR = ( 0x01<<(ch+16) );
  }
  else {
    GPIOA->BSRR = 0x01<<ch;
  }

}



void btn_Init(void)
{
  GPIOA->CRL |= (0x8888<<16);
  GPIOA->CRL &= ~(0x7777<<16);
}
int btn_pol(void)
{
//
  uint16_t btnbuf=0;
  //uint16_t table[4];
  btnbuf = GPIOA->IDR & (uint16_t)(0xf<<4);
  btnbuf = (btnbuf>>4);
  if(btnbuf) {
    if(btnbuf&0xc) {
      if(btnbuf&0x8) {
        return 4;
      }
      else {
        return 3;
      }
    }
    else {
      if(btnbuf&0x2) {
        return 2;
      }
      else {
        return 1;
      }
    }
  }
  else {
    return 0;
  }


  return btnbuf;
}


void Delay_us(unsigned int time_us)		/* time delay for us in 8MHz */
{
  volatile unsigned int i;

  for(i = 0; i < time_us; i++)			// 3 cycle
    {
	  asm volatile("NOP");
      asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");
      //asm volatile("NOP");



    }
}

void Delay_ms(unsigned int time_ms)		/* time delay for ms in 8MHz */
{
	volatile unsigned int i;

	for(i = 0; i < time_ms; i++)
    Delay_us(1000);
}

void SerialPutChar(char c)
{

    while((USART1->SR & 0x80) == 0);    // �����Ͱ� TDR���� Shift Register�� �Ű����� ������ ��ٸ�.
    USART1->DR = c;    // �����͸� USART1_DR �������Ϳ� ��

}

void Serial_PutString(char* s)
{    // ���ڿ� ���

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


void EXTI0_IRQHandler(void)
{
	printf(" 0�� \r\n");
}

void EXTI1_IRQHandler(void)
{
	printf(" 1�� \r\n");
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

    if((GPIOC->IDR & 0x2000) == 0){    // PC13 �� ���°� LOW �̸�
        GPIOA->BSRR |= 0x20;            // LED ON
    }
    else{
        GPIOA->BRR |= 0x20;            // LED OFF
    }

 */

