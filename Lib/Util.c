#define UTIL_LOCAL

#include "Util.h"



UTIL_DEF void Hw_second(volatile unsigned int time)
{
    for(;time >0;time--);
}

UTIL_DEF void Hw_1_second()
{
    Hw_second(8065960);
}

UTIL_DEF void Delay(__IO uint32_t nTime)
{
    TimingDelay = nTime;
    while(TimingDelay != 0)
    {
        TimingDelay--;
    }
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}