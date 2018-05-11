#define HW_SYSTICK_LOCAL

#include "Hw_Systick.h"


SYSTICK_DEF uint32_t SysTick_Config(uint32_t ticks);
SYSTICK_DEF void SysTick_Handler(void);


SYSTICK_DEF uint32_t SysTick_Config(uint32_t ticks)
{
    if(ticks > SYSTICK_MAXCOUNT)
    {
        return (1);
    }
    SysTick->LOAD = (ticks & SYSTICK_MAXCOUNT) - 1;
    NVIC_SetPriority(SysTick_IRQn, (1 << __NVIC_PRIO_BITS) -1);
    SysTick->VAL = (0x00);
    SysTick->CTRL = (1 << SYSTICK_CLKSOURCE) | (1 << SYSTICK_ENABLE) | (1 << SYSTICK_TICKINT);
    return (0);
}

SYSTICK_DEF void SysTick_Handler(void)
{
    count_sys++;
    if(count_sys == 100){
        count_sys = 0;
    }
}