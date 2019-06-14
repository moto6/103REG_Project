
void Delay_ms(unsigned int time_ms)	;
void Delay_us(unsigned int time_us)	;

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
