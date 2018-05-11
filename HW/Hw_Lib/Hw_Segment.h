#ifndef __HW_SEGMENT_H__
#define __HW_SEGMENT_H__

#include "Hw.h"


#define GPIO_7_SEG              GPIOC

#define GPIO_7_SEG_POWER_PIN    GPIO_Pin_8
#define GPIO_7_SEG_A_PIN        GPIO_Pin_0
#define GPIO_7_SEG_B_PIN        GPIO_Pin_1
#define GPIO_7_SEG_C_PIN        GPIO_Pin_2
#define GPIO_7_SEG_D_PIN        GPIO_Pin_3
#define GPIO_7_SEG_E_PIN        GPIO_Pin_4
#define GPIO_7_SEG_F_PIN        GPIO_Pin_5
#define GPIO_7_SEG_G_PIN        GPIO_Pin_7
#define GPIO_7_SEG_DP_PIN       GPIO_Pin_6



#ifdef HW_SEGMENT_LOCAL
#define SEG_DEF
#else
#define SEG_DEF                   extern
#endif


SEG_DEF void Power_SEG_On(void);
SEG_DEF void Power_SEG_Off(void);
SEG_DEF void On_7SEG_OnePin(uint16_t PinNum);
SEG_DEF void Off_7SEG_OnePin(uint16_t PinNum);
SEG_DEF void All_7SEG_On(void);
SEG_DEF void All_7SEG_Off(void);
SEG_DEF void Output_7SEG_Number(unsigned int Num);
SEG_DEF void Seven_SEG_TEST(void);



#endif