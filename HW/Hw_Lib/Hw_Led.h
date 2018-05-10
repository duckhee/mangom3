#ifndef __HW_LED_H__
#define __HW_LED_H__

#include "Hw.h"

#define HW_LED_PORT               GPIOB

#define HW_LED_RED               GPIO_Pin_9
#define HW_LED_YELLOW            GPIO_Pin_5
#define HW_LED_BLUE              GPIO_Pin_8



#ifdef HW_LED_LOCAL
#define HW_LED_DEF
#else
#define HW_LED_DEF                 extern
#endif

HW_LED_DEF void Led_Init(void);
HW_LED_DEF void Led_AllOn(void);
HW_LED_DEF void Led_AllOff(void);
HW_LED_DEF void Red_On(void);
HW_LED_DEF void Red_Off(void);
HW_LED_DEF void Yellow_On(void);
HW_LED_DEF void Yellow_Off(void);
HW_LED_DEF void Blue_On(void);
HW_LED_DEF void Blue_Off(void);
HW_LED_DEF void Test_LED(void);
HW_LED_DEF void TEST_Check(void);
HW_LED_DEF void LED_MULT(uint32_t count);

#endif
