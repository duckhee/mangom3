#ifndef __BMA150_H__

#include "Ap.h"

#define GPIO_SW_SPI                   GPIOA
#define GPIO_SW_SPI_NCS_PIN           GPIO_Pin_4
#define GPIO_SW_SPI_CLK_PIN           GPIO_Pin_5
#define GPIO_SW_SPI_MISO_PIN          GPIO_Pin_6
#define GPIO_SW_SPI_MOSI_PIN          GPIO_Pin_7

#define BufferSize                    2

uint8_t SPI_Buffer_Tx[BufferSize];
uint8_t SPI_Buffer_Rx[BufferSize];


#endif