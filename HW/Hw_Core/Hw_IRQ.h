#ifndef __HW_IRQ_H__
#define __HW_IRQ_H__

#include "Hw.h"

#ifdef HW_IRQ_LOCAL
#define HW_IRQ_DEF
#else
#define HW_IRQ_DEF                   extern
#endif

HW_IRQ_DEF void EXTI0_IRQHandler(void);
HW_IRQ_DEF void EXTI1_IRQHandler(void);
HW_IRQ_DEF void EXTI2_IRQHandler(void);
HW_IRQ_DEF void EXTI3_IRQHandler(void);
HW_IRQ_DEF void EXTI4_IRQHandler(void);
HW_IRQ_DEF void TIM2_IRQHandler(void);
HW_IRQ_DEF void TIM3_IRQHandler(void);
HW_IRQ_DEF void TIM4_IRQHandler(void);
HW_IRQ_DEF void PVD_IRQHandler(void);

#endif