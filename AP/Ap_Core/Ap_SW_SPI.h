#ifndef __AP_SW_SPI_H__
#define __AP_SW_SPI_H__

#include "Ap.h"


#define SW_SPI_WAIT_TIME          100


#define GPIO_SW_SPI               GPIOA
#define GPIO_SW_SPI_NCS_PIN       GPIO_Pin_4
#define GPIO_SW_SPI_CLK_PIN       GPIO_Pin_5
#define GPIO_SW_SPI_MISO_PIN      GPIO_Pin_6
#define GPIO_SW_SPI_MOSI_PIN      GPIO_Pin_7
#define GPIO_SW_SPI                GPIOB
#define GPIO_SW_SPI_NCS_PIN        GPIO_Pin_12
#define GPIO_SW_SPI_CLK_PIN        GPIO_Pin_13
#define GPIO_SW_SPI_MISO_PIN       GPIO_Pin_14
#define GPIO_SW_SPI_MOSI_PIN       GPIO_Pin_15
#define GPIO_RF_SPI                GPIOA
#define GPIO_RF_RESET              GPIOC
#define GPIO_RF_VREG_EN            GPIOC
#define GPIO_RF_GPIO0_4            GPIOC
#define GPIO_RF_GPIO5              GPIOD
#define GPIO_RF_SPI_NCS_PIN        GPIO_Pin_4
#define GPIO_RF_SPI_CLK_PIN        GPIO_Pin_5
#define GPIO_RF_SPI_MISO_PIN       GPIO_Pin_6
#define GPIO_RF_SPI_MOSI_PIN       GPIO_Pin_7

#ifdef M32
#define GPIO_SW_SPI               GPIOA
#define GPIO_SW_SPI_NCS_PIN       GPIO_Pin_4
#define GPIO_SW_SPI_CLK_PIN       GPIO_Pin_5
#define GPIO_SW_SPI_MISO_PIN      GPIO_Pin_6
#define GPIO_SW_SPI_MOSI_PIN      GPIO_Pin_7
#elif Z32
#define GPIO_SW_SPI                GPIOB
#define GPIO_SW_SPI_NCS_PIN        GPIO_Pin_12
#define GPIO_SW_SPI_CLK_PIN        GPIO_Pin_13
#define GPIO_SW_SPI_MISO_PIN       GPIO_Pin_14
#define GPIO_SW_SPI_MOSI_PIN       GPIO_Pin_15
#define GPIO_RF_SPI                GPIOA
#define GPIO_RF_RESET              GPIOC
#define GPIO_RF_VREG_EN            GPIOC
#define GPIO_RF_GPIO0_4            GPIOC
#define GPIO_RF_GPIO5              GPIOD
#define GPIO_RF_SPI_NCS_PIN        GPIO_Pin_4
#define GPIO_RF_SPI_CLK_PIN        GPIO_Pin_5
#define GPIO_RF_SPI_MISO_PIN       GPIO_Pin_6
#define GPIO_RF_SPI_MOSI_PIN       GPIO_Pin_7

#endif


static uint32_t SW_SPI_CPHA_val = 0;
static uint32_t SW_SPI_CPOL_val = 0;


#ifdef SW_SPI_LOCAL
#define SW_SPI_DEF
#else
#define SW_SPI_DEF                 extern
#endif

SW_SPI_DEF void TIMER_Wait_us(__IO uint32_t nCount);
SW_SPI_DEF uint8_t SW_SPI_ReadVal_MISO(void);
SW_SPI_DEF void SW_SPI_MOSI_H(void);
SW_SPI_DEF void SW_SPI_MOSI_L(void);
SW_SPI_DEF void SW_SPI_CLK_H(void);
SW_SPI_DEF void SW_SPI_CLK_L(void);
SW_SPI_DEF void SW_SPI_MOSI_OUT(uint8_t out);
SW_SPI_DEF void SW_SPI_CLK_Init(void);
SW_SPI_DEF void SW_SPI_CLK_Toggle(void);
SW_SPI_DEF unsigned char SW_SPI_TXRX(unsigned char tx_data);

#endif