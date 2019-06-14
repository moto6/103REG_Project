#include "stm32f103xb.h"
#include "stdio.h"

//#define RESET	0
//#define SET 	1

void Delay_ms(unsigned int time_ms)	;
void Delay_us(unsigned int time_us)	;

void SerialPutChar(char c);
void Serial_PutString(char* s);    // 문자열 출력


//Interrput Service Rutine
void EXTI_Config(void);
void RCC_Config(void);

//pre Defined Register MAP
#define RCC_CR 		(*(volatile unsigned int*)0x40021000)
#define RCC_CFGR 	(*(volatile unsigned int*)0x40021004)
#define RCC_APB2ENR (*(volatile unsigned int*)0x40021018)

#define GPIOA_CRL	(*(volatile unsigned int*)0x40010800)
#define GPIOA_CRH	(*(volatile unsigned int*)0x40010804)
#define GPIOA_BSRR 	(*(volatile unsigned int*)0x40010810)
#define GPIOA_BRR 	(*(volatile unsigned int*)0x40010814)
#define GPIOC_CRH 	(*(volatile unsigned int*)0x40011004)
#define GPIOC_IDR 	(*(volatile unsigned int*)0x40011008)
#define GPIOE_CRH
#define GPIOE_CRL   (*(volatile unsigned int*)0x40011800)

#define FLASH_ACR 	(*(volatile unsigned int*)0x40022000)

#define SCB_VTOR	(*(volatile unsigned int*)0xE000ED08)
#define SCB_SHPR3 	(*(volatile unsigned int*)0xE000ED20)

#define STK_CTRL 	(*(volatile unsigned int*)0xE000E010)
#define STK_LOAD 	(*(volatile unsigned int*)0xE000E014)
#define STK_VAL 	(*(volatile unsigned int*)0xE000E018)

#define SCB_SHPR3 	(*(volatile unsigned int*)0xE000ED20)

#define USART1_BRR 	(*(volatile unsigned int*)0x40013808)
#define USART1_CR1 	(*(volatile unsigned int*)0x4001380C)
#define USART1_CR2 	(*(volatile unsigned int*)0x40013810)
#define USART1_CR3 	(*(volatile unsigned int*)0x40013814)
#define USART1_DR 	(*(volatile unsigned int*)0x40013804)
#define USART1_SR 	(*(volatile unsigned int*)0x40013800)

#define USART2_BRR 	(*(volatile unsigned int*)0x40004408)
#define USART2_CR1 	(*(volatile unsigned int*)0x4000440C)
#define USART2_CR2 	(*(volatile unsigned int*)0x40004410)
#define USART2_CR3 	(*(volatile unsigned int*)0x40004414)
#define USART2_DR 	(*(volatile unsigned int*)0x40004404)
#define USART2_SR 	(*(volatile unsigned int*)0x40004400)

#define USART3_BRR 	(*(volatile unsigned int*)0x40004808)
#define USART3_CR1 	(*(volatile unsigned int*)0x4000480C)
#define USART3_CR2 	(*(volatile unsigned int*)0x40004810)
#define USART3_CR3 	(*(volatile unsigned int*)0x40004814)
#define USART3_DR 	(*(volatile unsigned int*)0x40004804)
#define USART3_SR 	(*(volatile unsigned int*)0x40004800)


/*
 *
 *
 *
 *
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

#define AFIO_EXTICR1 (*(volatile unsigned int*)0x40010008)
#define EXTI_IMR 	(*(volatile unsigned int*)0x40010400)
#define EXTI_RTSR 	(*(volatile unsigned int*)0x40010408)
#define EXTI_FTSR 	(*(volatile unsigned int*)0x4001040C)
#define EXTI_PR 	(*(volatile unsigned int*)0x40010414)

#define NVIC_ISER0 	(*(volatile unsigned int*)0xE000E100)
#define NVIC_PR4_7 	(*(volatile unsigned int*)0xE000E404)

