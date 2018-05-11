#define BH1600_LOCAL

#include "BH1600.h"


BH1600_DEF void BH1600_Init(void);
BH1600_DEF void BH1600_Set_Mode_Shutdown(void);
BH1600_DEF void BH1600_Set_Mode_H_Gain(void);
BH1600_DEF void BH1600_Set_Mode_L_Gain(void);
BH1600_DEF void BH1600_Set_Mode_Test(void);


BH1600_DEF void BH1600_Init(void)
{
    DMA_InitTypeDef DMA_InitStructure;
    /* DMA1 channel1 configuration */
    DMA_DeInit(DMA1_Channel1);
    DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;
    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&ADCConvertedValue;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    DMA_InitStructure.DMA_BufferSize = 1;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
    DMA_Init(DMA1_Channel1, %DMA_InitStructure);
    /* Enable DMA1 Channel1 */
    DMA_Cmd(DMA1_Channel1, ENABLE);

    ADC_InitTypeDef ADC_InitStructure;
    /* ADC1 Configuration */
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 1;
    ADC_Init(ADC1, &ADC_InitStructure);
    /* ADC1 regular channel14 configuration */ 
    ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 1, ADC_SampleTime_55Cycles5);
    /* Enable ADC1 DMA */
    ADC_DMACmd(ADC1, ENABLE);
    /* Enable ADC1 */
    ADC_Cmd(ADC1, ENABLE);
    /* Enable ADC1 reset calibaration register */   
    ADC_ResetCalibration(ADC1);
    /* Check the end of ADC1 reset calibration register */
    while(ADC_GetCalibrationStatus(ADC1));
    /* Start ADC1 calibaration */
    ADC_StartCalibration(ADC1);
    /* Check the end of ADC1 calibration */
    while(ADC_GetCalibrationStatus(ADC1));
    /* Start ADC1 Software Conversion */ 
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

BH1600_DEF void BH1600_Set_Mode_Shutdown(void)
{
    GPIO_ResetBits(GPIO_BH1600_MODE, GPIO_BH1600_MODE_GC1_PIN);
    GPIO_ResetBits(GPIO_BH1600_MODE, GPIO_BH1600_MODE_GC2_PIN);
}

BH1600_DEF void BH1600_Set_Mode_H_Gain(void)
{
    GPIO_SetBits(GPIO_BH1600_MODE, GPIO_BH1600_MODE_GC1_PIN);
    GPIO_ResetBits(GPIO_BH1600_MODE, GPIO_BH1600_MODE_GC2_PIN);
}

BH1600_DEF void BH1600_Set_Mode_L_Gain(void)
{
    GPIO_ResetBits(GPIO_BH1600_MODE, GPIO_BH1600_MODE_GC1_PIN);
    GPIO_SetBits(GPIO_BH1600_MODE, GPIO_BH1600_MODE_GC2_PIN);
}

BH1600_DEF void BH1600_Set_Mode_Test(void)
{
    GPIO_SetBits(GPIO_BH1600_MODE, GPIO_BH1600_MODE_GC1_PIN);
    GPIO_SetBits(GPIO_BH1600_MODE, GPIO_BH1600_MODE_GC2_PIN);
}

