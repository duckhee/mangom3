#ifndef __HW_H__
#define __HW_H__

//uint8_t library add
#include <stdint.h>

//hardware define
#include "Hw_Reg.h"
#include "Hw_Rcc.h"
#include "Hw_Gpio.h"
#include "Hw_Usart.h"
#include "Hw_TIM.h"
#include "Hw_Flash.h"
#include "Hw_ADC.h"
#include "Hw_DMA.h"
//hardware driver add
#include "Hw_Led.h"

//print library
#include "Ld_printf.h"

#ifdef HW_INIT_LOCAL
#define HW_INIT_DEF
#else
#define HW_INIT_DEF            extern
#endif

HW_INIT_DEF void HW_Init(void);


#endif