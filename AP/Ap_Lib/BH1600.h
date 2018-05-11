#ifndef __BH1600_H__
#define __BH1600_H__

#include "Ap.h"



#define GPIO_BH1600_MODE           GPIOC
#define GPIO_BH1600_MODE_GC1_PIN   GPIO_Pin_0
#define GPIO_BH1600_MODE_GC2_PIN   GPIO_Pin_1

#define ADC1_DR_Address    ((uint32_t)0x4001244C)
__IO uint16_t ADCConvertedValue;


#ifdef BH1600_LOCAL
#define BH1600_DEF
#else
#define BH1600_DEF                extern
#endif


BH1600_DEF void BH1600_Init(void);
BH1600_DEF void BH1600_Set_Mode_Shutdown(void);
BH1600_DEF void BH1600_Set_Mode_H_Gain(void);
BH1600_DEF void BH1600_Set_Mode_L_Gain(void);
BH1600_DEF void BH1600_Set_Mode_Test(void);



#endif