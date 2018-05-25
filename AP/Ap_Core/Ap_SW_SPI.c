#define SW_SPI_LOCAL

#include "Ap_SW_SPI.h"

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


SW_SPI_DEF void TIMER_Wait_us(__IO uint32_t nCount)
{
    for(; nCount != 0; nCount--);
}

SW_SPI_DEF uint8_t SW_SPI_ReadVal_MISO(void)
{
    return GPIO_ReadInputDataBit(GPI_RF_SPI, GPIO_RF_SPI_MISO_PIN);
}
//set MOSI High
SW_SPI_DEF void SW_SPI_MOSI_H(void)
{
    GPIO_SetBits(GPIO_SW_SPI, GPIO_SW_SPI_MOSI_PIN);
}
//set MOSI Low
SW_SPI_DEF void SW_SPI_MOSI_L(void)
{
    GPIO_ResetBits(GPIO_SW_SPI, GPIO_SW_SPI_MOSI_PIN);
}
//set CLOCK High
SW_SPI_DEF void SW_SPI_CLK_H(void)
{
    GPIO_SetBits(GPIO_SW_SPI, GPIO_SW_SPI_CLK_PIN);
}
//set CLOCK Low
SW_SPI_DEF void SW_SPI_CLK_L(void)
{
    GPIO_ResetBits(GPIO_SW_SPI, GPIO_SW_SPI_CLK_PIN);
}

SW_SPI_DEF void SW_SPI_MOSI_OUT(uint8_t out)
{
    if(out)
    {
        SW_SPI_MOSI_H();
    }else{
        SW_SPI_MOSI_L();
    }
    TIMER_wait_us(SW_SPI_WAIT_TIME);
}

SW_SPI_DEF void SW_SPI_CLK_Init(void)
{
    if(0 == SW_SPI_CPOL_val)
    {
        SW_SPI_CLK_L();
    }
    else
    {
        SW_SPI_CLK_H();
    }
    TIMER_Wait_us(SW_SPI_WAIT_TIME);
}

SW_SPI_DEF void SW_SPI_CLK_Toggle(void)
{
    GPIO_WriteBit(GPIO_SW_SPI, GPIO_SW_SPI_CLK_PIN, (BitAction)(1-GPIO_ReadOutputDataBit(GPIO_RF_SPI, GPIO_RF_SPI_CLK_PIN)));
    TIMER_Wait_us(SW_SPI_WAIT_TIME);
}

SW_SPI_DEF unsigned char SW_SPI_TXRX(unsigned char tx_data)
{
    unsigned char rx_data = 0;
    unsigned long i;
    unsigned char bitCheckVal = 0x80;

    if(1 == SW_SPI_CPHA_val)
    {
        SW_SPI_CLK_Toggle();
    }

    for(i = 0; i < 8; i++)
    {
        SW_SPIO_MOSI_OUT(tx_data & bitCheckVal);
        bitCheckVal >>= 1;
        if(SW_SPI_ReadVal_MISO() == Bit_SET)
        {
            rx_data |= 0x1;
        }

        if((7 == i) && (1 == SW_SPI_CPHA_val))
        {
            break;
        }
        SW_SPI_CLK_Toggle();
    }

    TIMER_Wait_us(SW_SPI_WAIT_TIME);
    return rx_data;
}