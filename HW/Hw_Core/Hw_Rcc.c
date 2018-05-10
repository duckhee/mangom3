#define HW_RCC_LOCAL

#include "Hw_Rcc.h"

#define HSI_Value                 ((uint32_t)8000000)
#define HSEStartUp_TimeOut        ((uint16_t)0x0500)
#define HSE_Value    ((uint32_t)12000000) /*!< Value of the External oscillator in Hz*/
/* RCC Flag Mask */
#define RCC_FLAG_Mask                 ((uint8_t)0x1F)
/* ------------ RCC registers bit address in the alias region ----------- */
#define RCC_OFFSET                (RCC_BASE - PERIPH_BASE)
/* CSR register bit mask */
#define RCC_CSR_RMVF_Set              ((uint32_t)0x01000000)
/* CIR register byte 2 (Bits[15:8]) base address */
#define RCC_CIR_BYTE2_ADDRESS         ((uint32_t)0x40021009)
/* --- CR Register ---*/

/* Alias word address of HSION bit */
#define RCC_CR_OFFSET                 (RCC_OFFSET + 0x00)
#define RCC_HSION_BitNumber           0x00
#define RCC_CR_HSION_BB               (PERIPH_BB_BASE + (RCC_CR_OFFSET * 32) + (RCC_HSION_BitNumber * 4))
/* --- CFGR Register ---*/

/* Alias word address of USBPRE bit */
#define RCC_CFGR_OFFSET               (RCC_OFFSET + 0x04)
#define RCC_USBPRE_BitNumber          0x16
#define RCC_CFGR_USBPRE_BB            (PERIPH_BB_BASE + (RCC_CFGR_OFFSET * 32) + (RCC_USBPRE_BitNumber * 4))

/* CFGR register bit mask */
#define RCC_CFGR_PLL_Mask            ((uint32_t)0xFFC0FFFF)

#define RCC_CFGR_PLLMull_Mask         ((uint32_t)0x003C0000)
#define RCC_CFGR_PLLSRC_Mask          ((uint32_t)0x00010000)
#define RCC_CFGR_PLLXTPRE_Mask        ((uint32_t)0x00020000)
#define RCC_CFGR_SWS_Mask             ((uint32_t)0x0000000C)
#define RCC_CFGR_SW_Mask              ((uint32_t)0xFFFFFFFC)
#define RCC_CFGR_HPRE_Reset_Mask      ((uint32_t)0xFFFFFF0F)
#define RCC_CFGR_HPRE_Set_Mask        ((uint32_t)0x000000F0)
#define RCC_CFGR_PPRE1_Reset_Mask     ((uint32_t)0xFFFFF8FF)
#define RCC_CFGR_PPRE1_Set_Mask       ((uint32_t)0x00000700)
#define RCC_CFGR_PPRE2_Reset_Mask     ((uint32_t)0xFFFFC7FF)
#define RCC_CFGR_PPRE2_Set_Mask       ((uint32_t)0x00003800)
#define RCC_CFGR_ADCPRE_Reset_Mask    ((uint32_t)0xFFFF3FFF)
#define RCC_CFGR_ADCPRE_Set_Mask      ((uint32_t)0x0000C000)

/* Alias word address of PLLON bit */
#define RCC_PLLON_BitNumber           0x18
#define RCC_CR_PLLON_BB               (PERIPH_BB_BASE + (RCC_CR_OFFSET * 32) + (RCC_PLLON_BitNumber * 4))

/* --- BDCR Register ---*/

/* Alias word address of RTCEN bit */
#define RCC_BDCR_OFFSET               (RCC_OFFSET + 0x20)
#define RCC_RTCEN_BitNumber           0x0F
#define RCC_BDCR_RTCEN_BB             (PERIPH_BB_BASE + (RCC_BDCR_OFFSET * 32) + (RCC_RTCEN_BitNumber * 4))

/* Alias word address of BDRST bit */
#define RCC_BDRST_BitNumber           0x10
#define RCC_BDCR_BDRST_BB             (PERIPH_BB_BASE + (RCC_BDCR_OFFSET * 32) + (RCC_BDRST_BitNumber * 4))

/* BDCR register base address */
#define RCC_BDCR_ADDRESS              (PERIPH_BASE + RCC_BDCR_OFFSET)

/* --- CSR Register ---*/

/* Alias word address of LSION bit */
#define RCC_CSR_OFFSET                (RCC_OFFSET + 0x24)
#define RCC_LSION_BitNumber           0x00
#define RCC_CSR_LSION_BB              (PERIPH_BB_BASE + (RCC_CSR_OFFSET * 32) + (RCC_LSION_BitNumber * 4))

/* Alias word address of CSSON bit */
#define RCC_CSSON_BitNumber           0x13
#define RCC_CR_CSSON_BB               (PERIPH_BB_BASE + (RCC_CR_OFFSET * 32) + (RCC_CSSON_BitNumber * 4))

/* ---------------------- RCC registers bit mask ------------------------ */

/* CR register bit mask */
#define RCC_CR_HSEBYP_Reset           ((uint32_t)0xFFFBFFFF)
#define RCC_CR_HSEBYP_Set             ((uint32_t)0x00040000)
#define RCC_CR_HSEON_Reset            ((uint32_t)0xFFFEFFFF)
#define RCC_CR_HSEON_Set              ((uint32_t)0x00010000)
#define RCC_CR_HSITRIM_Mask           ((uint32_t)0xFFFFFF07)
/* CIR register byte 2 (Bits[15:8]) base address */
#define RCC_CIR_BYTE2_ADDRESS         ((uint32_t)0x40021009)

/* CIR register byte 3 (Bits[23:16]) base address */
#define RCC_CIR_BYTE3_ADDRESS         ((uint32_t)0x4002100A)
/* CFGR register byte 4 (Bits[31:24]) base address */
#define RCC_CFGR_BYTE4_ADDRESS        ((uint32_t)0x40021007)
/*******************  Bit definition for RCC_CFGR register  *******************/
/*!< SW configuration */
#define  RCC_CFGR_SW                         ((uint32_t)0x00000003)        /*!< SW[1:0] bits (System clock Switch) */
#define  RCC_CFGR_SW_0                       ((uint32_t)0x00000001)        /*!< Bit 0 */
#define  RCC_CFGR_SW_1                       ((uint32_t)0x00000002)        /*!< Bit 1 */


/********************  Bit definition for RCC_CR register  ********************/
#define  RCC_CR_HSION                        ((uint32_t)0x00000001)        /*!< Internal High Speed clock enable */
#define  RCC_CR_HSIRDY                       ((uint32_t)0x00000002)        /*!< Internal High Speed clock ready flag */
#define  RCC_CR_HSITRIM                      ((uint32_t)0x000000F8)        /*!< Internal High Speed clock trimming */
#define  RCC_CR_HSICAL                       ((uint32_t)0x0000FF00)        /*!< Internal High Speed clock Calibration */
#define  RCC_CR_HSEON                        ((uint32_t)0x00010000)        /*!< External High Speed clock enable */
#define  RCC_CR_HSERDY                       ((uint32_t)0x00020000)        /*!< External High Speed clock ready flag */
#define  RCC_CR_HSEBYP                       ((uint32_t)0x00040000)        /*!< External High Speed clock Bypass */
#define  RCC_CR_CSSON                        ((uint32_t)0x00080000)        /*!< Clock Security System enable */
#define  RCC_CR_PLLON                        ((uint32_t)0x01000000)        /*!< PLL enable */
#define  RCC_CR_PLLRDY                       ((uint32_t)0x02000000)        /*!< PLL clock ready flag */

//System clock switch
#define SW_HSI_SYSCLOCK                      ((uint32_t)0x00000000)
#define SW_HSE_SYSCLOCK                      ((uint32_t)0x00000001)
#define SW_PLL_SYSCLOCK                      ((uint32_t)0x00000002)
#define SW_NOT_ALLOWED                       ((uint32_t)0x00000003)
//System clock mask
#define RCC_SWS_MASK                         ((uint32_t)0x0000000C)
//ADC PREscaler
#define ADCPRE_PLCK2_DIVIDED2                ((uint32_t)0x00000000)
#define ADCPRE_PLCK2_DIVIDED4                ((uint32_t)0x00004000)
#define ADCPRE_PLCK2_DIVIDED6                ((uint32_t)0x00008000)
#define ADCPRE_PLCK2_DIVIDED8                ((uint32_t)0x0000C000)
//APB2 PREscaler
#define APB2_PCLK2_NOT_DIVIDED               ((uint32_t)0x00000000)
#define APB2_PCLK2_DIVIDED2                  ((uint32_t)0x00002000)
#define APB2_PCLK2_DIVIDED4                  ((uint32_t)0x00002800)
#define APB2_PCLK2_DIVIDED8                  ((uint32_t)0x00003000)
#define APB2_PCLK2_DIVIDED16                 ((uint32_t)0x00003800)
//APB1 PREscaler
#define APB1_PCLK1_NOT_DIVIDED               ((uint32_t)0x00000000)
#define APB1_PCLK1_DIVIDED2                  ((uint32_t)0x00000400)
#define APB1_PCLK1_DIVIDED4                  ((uint32_t)0x00000500)
#define APB1_PCLK1_DIVIDED8                  ((uint32_t)0x00000600)
#define APB1_PCLK1_DIVIDED16                 ((uint32_t)0x00000700)
//AHB PREsacler
#define SYSCLK_NOT_DIVIDED                   ((uint32_t)0x00000000)
#define SYSCLK_DIVIDED2                      ((uint32_t)0x00000080)
#define SYSCLK_DIVIDED4                      ((uint32_t)0x00000090)
#define SYSCLK_DIVIDED8                      ((uint32_t)0x000000A0)
#define SYSCLK_DIVIDED16                     ((uint32_t)0x000000B0)
#define SYSCLK_DIVIDED64                     ((uint32_t)0x000000C0)
#define SYSCLK_DIVIDED128                    ((uint32_t)0x000000D0)
#define SYSCLK_DIVIDED256                    ((uint32_t)0x000000E0)
#define SYSCLK_DIVIDED512                    ((uint32_t)0x000000F0)


__IO uint32_t StartUpCounter = 0;


RCC_DEF void RCC_DeInit(void);
RCC_DEF void RCC_HSEConfig(uint32_t RCC_HSE);
//RCC_DEF ErrorStatus RCC_WaitForHSEStartUp(void);
RCC_DEF void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue);
RCC_DEF void RCC_HSICmd(FunctionalState NewState);
RCC_DEF void RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul);
RCC_DEF void RCC_PLLCmd(FunctionalState NewState);
RCC_DEF void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
RCC_DEF uint8_t RCC_GetSYSCLKSource(void);
RCC_DEF void RCC_HCLKConfig(uint32_t RCC_SYSCLK);
RCC_DEF void RCC_PCLK1Config(uint32_t RCC_HCLK);
RCC_DEF void RCC_PCLK2Config(uint32_t RCC_HCLK);
RCC_DEF void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState);
RCC_DEF void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource);
RCC_DEF void RCC_ADCCLKConfig(uint32_t RCC_PCLK2);
RCC_DEF void RCC_LSEConfig(uint8_t RCC_LSE);
RCC_DEF void RCC_LSICmd(FunctionalState NewState);
RCC_DEF void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource);
RCC_DEF void RCC_RTCCLKCmd(FunctionalState NewState);
RCC_DEF void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);
RCC_DEF void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
RCC_DEF void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
RCC_DEF void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
RCC_DEF void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
RCC_DEF void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
RCC_DEF void RCC_BackupResetCmd(FunctionalState NewState);
RCC_DEF void RCC_ClockSecuritySystemCmd(FunctionalState NewState);
RCC_DEF void RCC_MCOConfig(uint8_t RCC_MCO);
RCC_DEF FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);
RCC_DEF void RCC_ClearFlag(void);
RCC_DEF ITStatus RCC_GetITStatus(uint8_t RCC_IT);
RCC_DEF void RCC_ClearITPendingBit(uint8_t RCC_IT);
RCC_DEF void HSE_Init(void);
RCC_DEF void HSI_Init(void);


/**
  * @}
  */

/** @defgroup RCC_Private_Functions
  * @{
  */

/**
  * @brief  Resets the RCC clock configuration to the default reset state.
  * @param  None
  * @retval None
  */
RCC_DEF void RCC_DeInit(void)
{
    /* Set HSION bit */    
    RCC->CR |= (uint32_t)0x00000001;
    /* Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits */
    RCC->CFGR &= (uint32_t)0xF8FF0000;
    /* Reset HSEON, CSSON and PLLON bits */
    RCC->CR &= (uint32_t)0xFEF6FFFF;
    /* Reset HSEBYP bit */
    RCC->CR &= (uint32_t)0xFFFBFFFF;
    /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */
    RCC->CFGR &= 0xFF80FFFF;
    /* Disable all interrupts and clear pending bits  */
    RCC->CIR = 0x009F0000;
}

/**
  * @brief  Configures the External High Speed oscillator (HSE).
  * @note   HSE can not be stopped if it is used directly or through the PLL as system clock.
  * @param  RCC_HSE: specifies the new state of the HSE.
  *   This parameter can be one of the following values:
  *     @arg RCC_HSE_OFF: HSE oscillator OFF
  *     @arg RCC_HSE_ON: HSE oscillator ON
  *     @arg RCC_HSE_Bypass: HSE oscillator bypassed with external clock
  * @retval None
  */
RCC_DEF void RCC_HSEConfig(uint32_t RCC_HSE)
{
    /* Reset HSEON and HSEBYP bits before configuring the HSE ------------------*/
    /* Reset HSEON bit */
    RCC->CR &= RCC_CR_HSEON_Reset;
    /* Reset HSEBYP bit */
    RCC->CR &= RCC_CR_HSEBYP_Reset;
    /* Configure HSE (RCC_HSE_OFF is already covered by the code section above) */
    switch(RCC_HSE)
    {
        case RCC_HSE_ON:
            /* Set HSEON bit */
            RCC->CR |= RCC_CR_HSEON_Set;
        break;
        
        case RCC_HSE_Bypass:
        /* Set HSEBYP and HSEON bits */
        RCC->CR |= RCC_CR_HSEBYP_Set | RCC_CR_HSEON_Set;
        break;

        default:
        break;
    }
}
//RCC_DEF ErrorStatus RCC_WaitForHSEStartUp(void);

/**
  * @brief  Adjusts the Internal High Speed oscillator (HSI) calibration value.
  * @param  HSICalibrationValue: specifies the calibration trimming value.
  *   This parameter must be a number between 0 and 0x1F.
  * @retval None
  */
RCC_DEF void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue)
{
    uint32_t tmpreg = 0;
    tmpreg = RCC->CR;
    /* Clear HSITRIM[4:0] bits */
    tmpreg &= RCC_CR_HSITRIM_Mask;
    /* Set the HSITRIM[4:0] bits according to HSICalibrationValue value */
    tmpreg |= (uint32_t)HSICalibrationValue << 3;
    /* Store the new value */
    RCC->CR = tmpreg;
}

/**
  * @brief  Enables or disables the Internal High Speed oscillator (HSI).
  * @note   HSI can not be stopped if it is used directly or through the PLL as system clock.
  * @param  NewState: new state of the HSI. This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_HSICmd(FunctionalState NewState)
{
    *(__IO uint32_t *)RCC_CR_HSION_BB = (uint32_t)NewState;
}

/**
  * @brief  Configures the PLL clock source and multiplication factor.
  * @note   This function must be used only when the PLL is disabled.
  * @param  RCC_PLLSource: specifies the PLL entry clock source.
  *   For @b STM32_Connectivity_line_devices, this parameter can be one of the
  *   following values:
  *     @arg RCC_PLLSource_HSI_Div2: HSI oscillator clock divided by 2 selected as PLL clock entry
  *     @arg RCC_PLLSource_PREDIV1: PREDIV1 clock selected as PLL clock entry
  *   For @b other_STM32_devices, this parameter can be one of the following values:
  *     @arg RCC_PLLSource_HSI_Div2: HSI oscillator clock divided by 2 selected as PLL clock entry
  *     @arg RCC_PLLSource_HSE_Div1: HSE oscillator clock selected as PLL clock entry
  *     @arg RCC_PLLSource_HSE_Div2: HSE oscillator clock divided by 2 selected as PLL clock entry 
  * @param  RCC_PLLMul: specifies the PLL multiplication factor.
  *   For @b STM32_Connectivity_line_devices, this parameter can be RCC_PLLMul_x where x:{[4,9], 6_5}
  *   For @b other_STM32_devices, this parameter can be RCC_PLLMul_x where x:[2,16]  
  * @retval None
  */
RCC_DEF void RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul)
{
    uint32_t tmpreg = 0;
    tmpreg = RCC->CFGR;
    /* Clear PLLSRC, PLLXTPRE and PLLMUL[3:0] bits */
    tmpreg &= RCC_CFGR_PLL_Mask;
    /* Set the PLL configuration bits */
    tmpreg |= RCC_PLLSource | RCC_PLLMul;
    /* Store the new value */
    RCC->CFGR = tmpreg;
}

/**
  * @brief  Enables or disables the PLL.
  * @note   The PLL can not be disabled if it is used as system clock.
  * @param  NewState: new state of the PLL. This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_PLLCmd(FunctionalState NewState)
{
    *(__IO uint32_t *) RCC_CR_PLLON_BB = (uint32_t)NewState;
}

/**
  * @brief  Configures the system clock (SYSCLK).
  * @param  RCC_SYSCLKSource: specifies the clock source used as system clock.
  *   This parameter can be one of the following values:
  *     @arg RCC_SYSCLKSource_HSI: HSI selected as system clock
  *     @arg RCC_SYSCLKSource_HSE: HSE selected as system clock
  *     @arg RCC_SYSCLKSource_PLLCLK: PLL selected as system clock
  * @retval None
  */

RCC_DEF void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource)
{
    uint32_t tmpreg = 0;
    tmpreg = RCC->CFGR;
    /* Clear SW[1:0] bits */
    tmpreg &= RCC_CFGR_SW_Mask;
    /* Set SW[1:0] bits according to RCC_SYSCLKSource value */
    tmpreg |= RCC_SYSCLKSource;
    /* Store the new value */
    RCC->CFGR = tmpreg;
}

/**
  * @brief  Returns the clock source used as system clock.
  * @param  None
  * @retval The clock source used as system clock. The returned value can
  *   be one of the following:
  *     - 0x00: HSI used as system clock
  *     - 0x04: HSE used as system clock
  *     - 0x08: PLL used as system clock
  */
RCC_DEF uint8_t RCC_GetSYSCLKSource(void)
{
    return ((uint8_t)RCC->CFGR & RCC_CFGR_SWS_Mask);
}

/**
  * @brief  Configures the AHB clock (HCLK).
  * @param  RCC_SYSCLK: defines the AHB clock divider. This clock is derived from 
  *   the system clock (SYSCLK).
  *   This parameter can be one of the following values:
  *     @arg RCC_SYSCLK_Div1: AHB clock = SYSCLK
  *     @arg RCC_SYSCLK_Div2: AHB clock = SYSCLK/2
  *     @arg RCC_SYSCLK_Div4: AHB clock = SYSCLK/4
  *     @arg RCC_SYSCLK_Div8: AHB clock = SYSCLK/8
  *     @arg RCC_SYSCLK_Div16: AHB clock = SYSCLK/16
  *     @arg RCC_SYSCLK_Div64: AHB clock = SYSCLK/64
  *     @arg RCC_SYSCLK_Div128: AHB clock = SYSCLK/128
  *     @arg RCC_SYSCLK_Div256: AHB clock = SYSCLK/256
  *     @arg RCC_SYSCLK_Div512: AHB clock = SYSCLK/512
  * @retval None
  */
RCC_DEF void RCC_HCLKConfig(uint32_t RCC_SYSCLK)
{
    uint32_t tmpreg = 0;
    tmpreg = RCC->CFGR;
    /* Clear HPRE[3:0] bits */
    tmpreg &= RCC_CFGR_HPRE_Reset_Mask;
    /* Set HPRE[3:0] bits according to RCC_SYSCLK value */
    tmpreg |= RCC_SYSCLK;
    /* Store the new value */
    RCC->CFGR = tmpreg;
}

/**
  * @brief  Configures the Low Speed APB clock (PCLK1).
  * @param  RCC_HCLK: defines the APB1 clock divider. This clock is derived from 
  *   the AHB clock (HCLK).
  *   This parameter can be one of the following values:
  *     @arg RCC_HCLK_Div1: APB1 clock = HCLK
  *     @arg RCC_HCLK_Div2: APB1 clock = HCLK/2
  *     @arg RCC_HCLK_Div4: APB1 clock = HCLK/4
  *     @arg RCC_HCLK_Div8: APB1 clock = HCLK/8
  *     @arg RCC_HCLK_Div16: APB1 clock = HCLK/16
  * @retval None
  */
RCC_DEF void RCC_PCLK1Config(uint32_t RCC_HCLK)
{
    uint32_t tmpreg = 0;
    tmpreg = RCC->CFGR;
    /* Clear PPRE1[2:0] bits */
    tmpreg &= RCC_CFGR_PPRE1_Reset_Mask;
    /* Set PPRE1[2:0] bits according to RCC_HCLK value */
    tmpreg |= RCC_HCLK;
    /* Store the new value */
    RCC->CFGR = tmpreg;
}

/**
  * @brief  Configures the High Speed APB clock (PCLK2).
  * @param  RCC_HCLK: defines the APB2 clock divider. This clock is derived from 
  *   the AHB clock (HCLK).
  *   This parameter can be one of the following values:
  *     @arg RCC_HCLK_Div1: APB2 clock = HCLK
  *     @arg RCC_HCLK_Div2: APB2 clock = HCLK/2
  *     @arg RCC_HCLK_Div4: APB2 clock = HCLK/4
  *     @arg RCC_HCLK_Div8: APB2 clock = HCLK/8
  *     @arg RCC_HCLK_Div16: APB2 clock = HCLK/16
  * @retval None
  */
RCC_DEF void RCC_PCLK2Config(uint32_t RCC_HCLK)
{
    uint32_t tmpreg = 0;
    tmpreg = RCC->CFGR;
    /* Clear PPRE2[2:0] bits */
    tmpreg &= RCC_CFGR_PPRE2_Reset_Mask;
    /* Set PPRE2[2:0] bits according to RCC_HCLK value */
    tmpreg |= RCC_HCLK << 3;
    /* Store the new value */
    RCC->CFGR = tmpreg;
}

/**
  * @brief  Enables or disables the specified RCC interrupts.
  * @param  RCC_IT: specifies the RCC interrupt sources to be enabled or disabled.
  * 
  *   For @b STM32_Connectivity_line_devices, this parameter can be any combination
  *   of the following values        
  *     @arg RCC_IT_LSIRDY: LSI ready interrupt
  *     @arg RCC_IT_LSERDY: LSE ready interrupt
  *     @arg RCC_IT_HSIRDY: HSI ready interrupt
  *     @arg RCC_IT_HSERDY: HSE ready interrupt
  *     @arg RCC_IT_PLLRDY: PLL ready interrupt
  *     @arg RCC_IT_PLL2RDY: PLL2 ready interrupt
  *     @arg RCC_IT_PLL3RDY: PLL3 ready interrupt
  * 
  *   For @b other_STM32_devices, this parameter can be any combination of the 
  *   following values        
  *     @arg RCC_IT_LSIRDY: LSI ready interrupt
  *     @arg RCC_IT_LSERDY: LSE ready interrupt
  *     @arg RCC_IT_HSIRDY: HSI ready interrupt
  *     @arg RCC_IT_HSERDY: HSE ready interrupt
  *     @arg RCC_IT_PLLRDY: PLL ready interrupt
  *       
  * @param  NewState: new state of the specified RCC interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        /* Perform Byte access to RCC_CIR bits to enable the selected interrupts */
        *(__IO uint32_t *)RCC_CIR_BYTE2_ADDRESS |= RCC_IT;
    }
    else
    {
        /* Perform Byte access to RCC_CIR bits to disable the selected interrupts */
        *(__IO uint32_t *)RCC_CIR_BYTE2_ADDRESS &= (uint32_t)~RCC_IT;
    }
}

/**
  * @brief  Configures the USB clock (USBCLK).
  * @param  RCC_USBCLKSource: specifies the USB clock source. This clock is 
  *   derived from the PLL output.
  *   This parameter can be one of the following values:
  *     @arg RCC_USBCLKSource_PLLCLK_1Div5: PLL clock divided by 1,5 selected as USB 
  *                                     clock source
  *     @arg RCC_USBCLKSource_PLLCLK_Div1: PLL clock selected as USB clock source
  * @retval None
  */
RCC_DEF void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource)
{
    *(__IO uint32_t *)RCC_CFGR_USBPRE_BB = RCC_USBCLKSource;
}

/**
  * @brief  Configures the ADC clock (ADCCLK).
  * @param  RCC_PCLK2: defines the ADC clock divider. This clock is derived from 
  *   the APB2 clock (PCLK2).
  *   This parameter can be one of the following values:
  *     @arg RCC_PCLK2_Div2: ADC clock = PCLK2/2
  *     @arg RCC_PCLK2_Div4: ADC clock = PCLK2/4
  *     @arg RCC_PCLK2_Div6: ADC clock = PCLK2/6
  *     @arg RCC_PCLK2_Div8: ADC clock = PCLK2/8
  * @retval None
  */
RCC_DEF void RCC_ADCCLKConfig(uint32_t RCC_PCLK2)
{
    uint32_t tmpreg = 0;
    tmpreg = RCC->CFGR;
    /* Clear ADCPRE[1:0] bits */
    tmpreg &= RCC_CFGR_ADCPRE_Reset_Mask;
    /* Set ADCPRE[1:0] bits according to RCC_PCLK2 value */
    tmpreg |= RCC_PCLK2;
    /* Store the new value */
    RCC->CFGR = tmpreg;
}

/**
  * @brief  Configures the External Low Speed oscillator (LSE).
  * @param  RCC_LSE: specifies the new state of the LSE.
  *   This parameter can be one of the following values:
  *     @arg RCC_LSE_OFF: LSE oscillator OFF
  *     @arg RCC_LSE_ON: LSE oscillator ON
  *     @arg RCC_LSE_Bypass: LSE oscillator bypassed with external clock
  * @retval None
  */
RCC_DEF void RCC_LSEConfig(uint8_t RCC_LSE)
{
    /* Reset LSEON and LSEBYP bits before configuring the LSE ------------------*/
    /* Reset LSEON bit */
    *(__IO uint8_t *)RCC_BDCR_ADDRESS = RCC_LSE_OFF;
    /* Reset LSEBYP bit */
    *(__IO uint8_t *)RCC_BDCR_ADDRESS = RCC_LSE_OFF;
    switch(RCC_LSE)
    {
        case RCC_LSE_ON:
            /* Set LSEON bit */
            *(__IO uint8_t *)RCC_BDCR_ADDRESS = RCC_LSE_ON;
        break;
        
        case RCC_LSE_Bypass:
            /* Set LSEBYP and LSEON bits */
            *(__IO uint8_t *)RCC_BDCR_ADDRESS = RCC_LSE_Bypass | RCC_LSE_ON;
        break;

        default:
        break;
    }
}

/**
  * @brief  Enables or disables the Internal Low Speed oscillator (LSI).
  * @note   LSI can not be disabled if the IWDG is running.
  * @param  NewState: new state of the LSI. This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_LSICmd(FunctionalState NewState)
{
    *(__IO uint8_t *)RCC_CSR_LSION_BB = (uint32_t)NewState;
}

/**
  * @brief  Configures the RTC clock (RTCCLK).
  * @note   Once the RTC clock is selected it can�t be changed unless the Backup domain is reset.
  * @param  RCC_RTCCLKSource: specifies the RTC clock source.
  *   This parameter can be one of the following values:
  *     @arg RCC_RTCCLKSource_LSE: LSE selected as RTC clock
  *     @arg RCC_RTCCLKSource_LSI: LSI selected as RTC clock
  *     @arg RCC_RTCCLKSource_HSE_Div128: HSE clock divided by 128 selected as RTC clock
  * @retval None
  */
RCC_DEF void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource)
{
    /* Select the RTC clock source */
    RCC->BDCR |= RCC_RTCCLKSource;
}

/**
  * @brief  Enables or disables the RTC clock.
  * @note   This function must be used only after the RTC clock was selected using the RCC_RTCCLKConfig function.
  * @param  NewState: new state of the RTC clock. This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_RTCCLKCmd(FunctionalState NewState)
{
    *(__IO uint32_t *)RCC_BDCR_RTCEN_BB = (uint32_t)NewState;
}

/**
  * @brief  Returns the frequencies of different on chip clocks.
  * @param  RCC_Clocks: pointer to a RCC_ClocksTypeDef structure which will hold
  *   the clocks frequencies.
  * @retval None
  */
RCC_DEF void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks)
{
    uint32_t tmp = 0, pllmull = 0, pllsource = 0, presc = 0;
    /* Get SYSCLK source -------------------------------------------------------*/
    tmp = RCC->CFGR & RCC_CFGR_SWS_Mask;
    
    switch(tmp)
    {
        case 0x00: /* HSI used as system clock */
            RCC_Clocks->SYSCLK_Frequency = HSI_Value;
        break;

        case 0x04:  /* HSE used as system clock */
            RCC_Clocks->SYSCLK_Frequency = HSE_Value;
        break;

        case 0x08:  /* PLL used as system clock */
            /* Get PLL clock source and multiplication factor ----------------------*/
            pllmull = RCC->CFGR & RCC_CFGR_PLLMull_Mask;
            pllsource = RCC->CFGR & RCC_CFGR_PLLSRC_Mask;
            pllmull = (pllmull >> 18)+2;

            if(pllsource == 0x00)
            {
                /* HSI oscillator clock divided by 2 selected as PLL clock entry */
                RCC_Clocks->SYSCLK_Frequency = (HSI_Value >> 1) * pllmull;
            }
            else
            {
                /* HSE selected as PLL clock entry */
                if((RCC->CFGR * RCC_CFGR_PLLXTPRE_Mask) != (uint32_t)RESET)
                {
                    /* HSE oscillator clock divided by   2 */
                    RCC_Clocks->SYSCLK_Frequency = (HSE_Value >> 1) * pllmull;
                }
                else
                {
                    RCC_Clocks->SYSCLK_Frequency = HSE_Value * pllmull;
                }
            }
        break;
        
        default:
            RCC_Clocks->SYSCLK_Frequency = HSI_Value;
        break;
    }
    /* Compute HCLK, PCLK1, PCLK2 and ADCCLK clocks frequencies ----------------*/
    /* Get HCLK prescaler */
    tmp = RCC->CFGR & RCC_CFGR_HPRE_Set_Mask;
    tmp = tmp >> 4;
    presc = APBAHBPrescTable[tmp];
    /* HCLK clock frequency */
    RCC_Clocks->PCLK1_Frequency = RCC_Clocks->SYSCLK_Frequency >> presc;
    /* Get PCLK1 prescaler */
    tmp = RCC->CFGR & RCC_CFGR_PPRE1_Set_Mask;
    tmp = tmp >> 8;
    presc = APBAHBPrescTable[tmp];
    /* PCLK1 clock frequency */
    RCC_Clocks->PCLK1_Frequency = RCC_Clocks->HCLK_Frequency >> presc;
    /* Get PCLK2 prescaler */
    tmp  = RCC->CFGR & RCC_CFGR_PPRE2_Set_Mask;
    tmp = tmp >> 11;
    presc = APBAHBPrescTable[tmp];
    /* PCLK2 clock frequency */
    RCC_Clocks->PCLK2_Frequency = RCC_Clocks->HCLK_Frequency >> presc;
    /* Get ADCCLK prescaler */
    tmp = RCC->CFGR & RCC_CFGR_ADCPRE_Set_Mask;
    tmp = tmp >> 14;
    presc = APBAHBPrescTable[tmp];
    /* ADCCLK clock frequency */
    RCC_Clocks->ADCCLK_Frequency = RCC_Clocks->PCLK2_Frequency / presc;
}

/**
  * @brief  Enables or disables the AHB peripheral clock.
  * @param  RCC_AHBPeriph: specifies the AHB peripheral to gates its clock.
  *   
  *   For @b STM32_Connectivity_line_devices, this parameter can be any combination
  *   of the following values:        
  *     @arg RCC_AHBPeriph_DMA1
  *     @arg RCC_AHBPeriph_DMA2
  *     @arg RCC_AHBPeriph_SRAM
  *     @arg RCC_AHBPeriph_FLITF
  *     @arg RCC_AHBPeriph_CRC
  *     @arg RCC_AHBPeriph_OTG_FS    
  *     @arg RCC_AHBPeriph_ETH_MAC   
  *     @arg RCC_AHBPeriph_ETH_MAC_Tx
  *     @arg RCC_AHBPeriph_ETH_MAC_Rx
  * 
  *   For @b other_STM32_devices, this parameter can be any combination of the 
  *   following values:        
  *     @arg RCC_AHBPeriph_DMA1
  *     @arg RCC_AHBPeriph_DMA2
  *     @arg RCC_AHBPeriph_SRAM
  *     @arg RCC_AHBPeriph_FLITF
  *     @arg RCC_AHBPeriph_CRC
  *     @arg RCC_AHBPeriph_FSMC
  *     @arg RCC_AHBPeriph_SDIO
  *   
  * @note SRAM and FLITF clock can be disabled only during sleep mode.
  * @param  NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        RCC->APBENR |= RCC_AHBPeriph;
    }
    else
    {
        RCC->APBENR &= ~RCC_AHBPeriph;
    }
}

/**
  * @brief  Enables or disables the High Speed APB (APB2) peripheral clock.
  * @param  RCC_APB2Periph: specifies the APB2 peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *     @arg RCC_APB2Periph_AFIO, RCC_APB2Periph_GPIOA, RCC_APB2Periph_GPIOB,
  *          RCC_APB2Periph_GPIOC, RCC_APB2Periph_GPIOD, RCC_APB2Periph_GPIOE,
  *          RCC_APB2Periph_GPIOF, RCC_APB2Periph_GPIOG, RCC_APB2Periph_ADC1,
  *          RCC_APB2Periph_ADC2, RCC_APB2Periph_TIM1, RCC_APB2Periph_SPI1,
  *          RCC_APB2Periph_TIM8, RCC_APB2Periph_USART1, RCC_APB2Periph_ADC3
  * @param  NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        RCC->APB2ENR |= RCC_APB2Periph;
    }
    else
    {
        RCC->APB2ENR &= ~RCC_APB2Periph;
    }
}

/**
  * @brief  Enables or disables the Low Speed APB (APB1) peripheral clock.
  * @param  RCC_APB1Periph: specifies the APB1 peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *     @arg RCC_APB1Periph_TIM2, RCC_APB1Periph_TIM3, RCC_APB1Periph_TIM4,
  *          RCC_APB1Periph_TIM5, RCC_APB1Periph_TIM6, RCC_APB1Periph_TIM7,
  *          RCC_APB1Periph_WWDG, RCC_APB1Periph_SPI2, RCC_APB1Periph_SPI3,
  *          RCC_APB1Periph_USART2, RCC_APB1Periph_USART3, RCC_APB1Periph_USART4, 
  *          RCC_APB1Periph_USART5, RCC_APB1Periph_I2C1, RCC_APB1Periph_I2C2,
  *          RCC_APB1Periph_USB, RCC_APB1Periph_CAN1, RCC_APB1Periph_BKP,
  *          RCC_APB1Periph_PWR, RCC_APB1Periph_DAC
  * @param  NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        RCC->APB1ENR |= RCC_APB1Periph;
    }
    else
    {
        RCC->APB1ENR &= ~RCC_APB1Periph;
    }
}

/**
  * @brief  Forces or releases High Speed APB (APB2) peripheral reset.
  * @param  RCC_APB2Periph: specifies the APB2 peripheral to reset.
  *   This parameter can be any combination of the following values:
  *     @arg RCC_APB2Periph_AFIO, RCC_APB2Periph_GPIOA, RCC_APB2Periph_GPIOB,
  *          RCC_APB2Periph_GPIOC, RCC_APB2Periph_GPIOD, RCC_APB2Periph_GPIOE,
  *          RCC_APB2Periph_GPIOF, RCC_APB2Periph_GPIOG, RCC_APB2Periph_ADC1,
  *          RCC_APB2Periph_ADC2, RCC_APB2Periph_TIM1, RCC_APB2Periph_SPI1,
  *          RCC_APB2Periph_TIM8, RCC_APB2Periph_USART1, RCC_APB2Periph_ADC3
  * @param  NewState: new state of the specified peripheral reset.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        RCC->APB2RSTR |= RCC_APB2Periph;
    }
    else
    {
        RCC->APB2RSTR &= ~RCC_APB2Periph;
    }
}

/**
  * @brief  Forces or releases Low Speed APB (APB1) peripheral reset.
  * @param  RCC_APB1Periph: specifies the APB1 peripheral to reset.
  *   This parameter can be any combination of the following values:
  *     @arg RCC_APB1Periph_TIM2, RCC_APB1Periph_TIM3, RCC_APB1Periph_TIM4,
  *          RCC_APB1Periph_TIM5, RCC_APB1Periph_TIM6, RCC_APB1Periph_TIM7,
  *          RCC_APB1Periph_WWDG, RCC_APB1Periph_SPI2, RCC_APB1Periph_SPI3,
  *          RCC_APB1Periph_USART2, RCC_APB1Periph_USART3, RCC_APB1Periph_USART4, 
  *          RCC_APB1Periph_USART5, RCC_APB1Periph_I2C1, RCC_APB1Periph_I2C2,
  *          RCC_APB1Periph_USB, RCC_APB1Periph_CAN1, RCC_APB1Periph_BKP,
  *          RCC_APB1Periph_PWR, RCC_APB1Periph_DAC
  * @param  NewState: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState)
{
    if(NewState != DISABLE)
    {
        RCC->APB1RSTR |= RCC_APB1Periph;
    }
    else
    {
        RCC->APB1RSTR &= ~RCC_APB1Periph;
    }
}

/**
  * @brief  Forces or releases the Backup domain reset.
  * @param  NewState: new state of the Backup domain reset.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_BackupResetCmd(FunctionalState NewState)
{
    *(__IO uint32_t *)RCC_BDCR_BDRST_BB = (uint32_t)NewState;
}

/**
  * @brief  Enables or disables the Clock Security System.
  * @param  NewState: new state of the Clock Security System..
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
RCC_DEF void RCC_ClockSecuritySystemCmd(FunctionalState NewState)
{
    *(__IO uint32_t *)RCC_CR_CSSON_BB = (uint32_t)NewState;
}

/**
  * @brief  Selects the clock source to output on MCO pin.
  * @param  RCC_MCO: specifies the clock source to output.
  *   
  *   For @b STM32_Connectivity_line_devices, this parameter can be one of the
  *   following values:       
  *     @arg RCC_MCO_NoClock: No clock selected
  *     @arg RCC_MCO_SYSCLK: System clock selected
  *     @arg RCC_MCO_HSI: HSI oscillator clock selected
  *     @arg RCC_MCO_HSE: HSE oscillator clock selected
  *     @arg RCC_MCO_PLLCLK_Div2: PLL clock divided by 2 selected
  *     @arg RCC_MCO_PLL2CLK: PLL2 clock selected                     
  *     @arg RCC_MCO_PLL3CLK_Div2: PLL3 clock divided by 2 selected   
  *     @arg RCC_MCO_XT1: External 3-25 MHz oscillator clock selected  
  *     @arg RCC_MCO_PLL3CLK: PLL3 clock selected 
  * 
  *   For  @b other_STM32_devices, this parameter can be one of the following values:        
  *     @arg RCC_MCO_NoClock: No clock selected
  *     @arg RCC_MCO_SYSCLK: System clock selected
  *     @arg RCC_MCO_HSI: HSI oscillator clock selected
  *     @arg RCC_MCO_HSE: HSE oscillator clock selected
  *     @arg RCC_MCO_PLLCLK_Div2: PLL clock divided by 2 selected
  *   
  * @retval None
  */
RCC_DEF void RCC_MCOConfig(uint8_t RCC_MCO)
{
    /* Perform Byte access to MCO bits to select the MCO source */
    *(__IO uint8_t *)RCC_CFGR_BYTE4_ADDRESS = RCC_MCO;
}

/**
  * @brief  Checks whether the specified RCC flag is set or not.
  * @param  RCC_FLAG: specifies the flag to check.
  *   
  *   For @b STM32_Connectivity_line_devices, this parameter can be one of the
  *   following values:
  *     @arg RCC_FLAG_HSIRDY: HSI oscillator clock ready
  *     @arg RCC_FLAG_HSERDY: HSE oscillator clock ready
  *     @arg RCC_FLAG_PLLRDY: PLL clock ready
  *     @arg RCC_FLAG_PLL2RDY: PLL2 clock ready      
  *     @arg RCC_FLAG_PLL3RDY: PLL3 clock ready                           
  *     @arg RCC_FLAG_LSERDY: LSE oscillator clock ready
  *     @arg RCC_FLAG_LSIRDY: LSI oscillator clock ready
  *     @arg RCC_FLAG_PINRST: Pin reset
  *     @arg RCC_FLAG_PORRST: POR/PDR reset
  *     @arg RCC_FLAG_SFTRST: Software reset
  *     @arg RCC_FLAG_IWDGRST: Independent Watchdog reset
  *     @arg RCC_FLAG_WWDGRST: Window Watchdog reset
  *     @arg RCC_FLAG_LPWRRST: Low Power reset
  * 
  *   For @b other_STM32_devices, this parameter can be one of the following values:        
  *     @arg RCC_FLAG_HSIRDY: HSI oscillator clock ready
  *     @arg RCC_FLAG_HSERDY: HSE oscillator clock ready
  *     @arg RCC_FLAG_PLLRDY: PLL clock ready
  *     @arg RCC_FLAG_LSERDY: LSE oscillator clock ready
  *     @arg RCC_FLAG_LSIRDY: LSI oscillator clock ready
  *     @arg RCC_FLAG_PINRST: Pin reset
  *     @arg RCC_FLAG_PORRST: POR/PDR reset
  *     @arg RCC_FLAG_SFTRST: Software reset
  *     @arg RCC_FLAG_IWDGRST: Independent Watchdog reset
  *     @arg RCC_FLAG_WWDGRST: Window Watchdog reset
  *     @arg RCC_FLAG_LPWRRST: Low Power reset
  *   
  * @retval The new state of RCC_FLAG (SET or RESET).
  */
RCC_DEF FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG)
{
    uint32_t tmp = 0;
    uint32_t statusreg = 0;
    FlagStatus bitstatus = RESET;
    /* Get the RCC register index */
    tmp = RCC_FLAG >> 5;
    if(tmp == 1)
    {
        /* The flag to check is in CR register */
        statusreg = RCC->CR;
    }
    else if(tmp == 2)
    {
        /* The flag to check is in BDCR register */
        statusreg = RCC->BDCR;
    }
    else
    {
        /* The flag to check is in CSR register */
        statusreg = RCC->CSR;
    }
    /* Get the flag position */
    tmp = RCC_FLAG & RCC_FLAG_Mask;
    if(((statusreg& (uint32_t)1 << tmp)) != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    /* Return the flag status */
    return bitstatus;
}

/**
  * @brief  Clears the RCC reset flags.
  * @note   The reset flags are: RCC_FLAG_PINRST, RCC_FLAG_PORRST, RCC_FLAG_SFTRST,
  *   RCC_FLAG_IWDGRST, RCC_FLAG_WWDGRST, RCC_FLAG_LPWRRST
  * @param  None
  * @retval None
  */
RCC_DEF void RCC_ClearFlag(void)
{
    /* Set RMVF bit to clear the reset flags */
    RCC->CSR |= RCC_CSR_RMVF_Set;
}

/**
  * @brief  Checks whether the specified RCC interrupt has occurred or not.
  * @param  RCC_IT: specifies the RCC interrupt source to check.
  *   
  *   For @b STM32_Connectivity_line_devices, this parameter can be one of the
  *   following values:
  *     @arg RCC_IT_LSIRDY: LSI ready interrupt
  *     @arg RCC_IT_LSERDY: LSE ready interrupt
  *     @arg RCC_IT_HSIRDY: HSI ready interrupt
  *     @arg RCC_IT_HSERDY: HSE ready interrupt
  *     @arg RCC_IT_PLLRDY: PLL ready interrupt
  *     @arg RCC_IT_PLL2RDY: PLL2 ready interrupt 
  *     @arg RCC_IT_PLL3RDY: PLL3 ready interrupt                      
  *     @arg RCC_IT_CSS: Clock Security System interrupt
  * 
  *   For @b other_STM32_devices, this parameter can be one of the following values:        
  *     @arg RCC_IT_LSIRDY: LSI ready interrupt
  *     @arg RCC_IT_LSERDY: LSE ready interrupt
  *     @arg RCC_IT_HSIRDY: HSI ready interrupt
  *     @arg RCC_IT_HSERDY: HSE ready interrupt
  *     @arg RCC_IT_PLLRDY: PLL ready interrupt
  *     @arg RCC_IT_CSS: Clock Security System interrupt
  *   
  * @retval The new state of RCC_IT (SET or RESET).
  */
RCC_DEF ITStatus RCC_GetITStatus(uint8_t RCC_IT)
{
    ITStatus bitstatus = RESET;
    /* Check the status of the specified RCC interrupt */
    if((RCC->CIR & RCC_IT) != (uint32_t)RESET)
    {
        bitstatus = SET;
    }
    else
    {
        bitstatus = RESET;
    }
    /* Return the RCC_IT status */
    return bitstatus;
}

/**
  * @brief  Clears the RCC�s interrupt pending bits.
  * @param  RCC_IT: specifies the interrupt pending bit to clear.
  *   
  *   For @b STM32_Connectivity_line_devices, this parameter can be any combination
  *   of the following values:
  *     @arg RCC_IT_LSIRDY: LSI ready interrupt
  *     @arg RCC_IT_LSERDY: LSE ready interrupt
  *     @arg RCC_IT_HSIRDY: HSI ready interrupt
  *     @arg RCC_IT_HSERDY: HSE ready interrupt
  *     @arg RCC_IT_PLLRDY: PLL ready interrupt
  *     @arg RCC_IT_PLL2RDY: PLL2 ready interrupt 
  *     @arg RCC_IT_PLL3RDY: PLL3 ready interrupt                      
  *     @arg RCC_IT_CSS: Clock Security System interrupt
  * 
  *   For @b other_STM32_devices, this parameter can be any combination of the
  *   following values:        
  *     @arg RCC_IT_LSIRDY: LSI ready interrupt
  *     @arg RCC_IT_LSERDY: LSE ready interrupt
  *     @arg RCC_IT_HSIRDY: HSI ready interrupt
  *     @arg RCC_IT_HSERDY: HSE ready interrupt
  *     @arg RCC_IT_PLLRDY: PLL ready interrupt
  *   
  *     @arg RCC_IT_CSS: Clock Security System interrupt
  * @retval None
  */
RCC_DEF void RCC_ClearITPendingBit(uint8_t RCC_IT)
{
    /* Perform Byte access to RCC_CIR[23:16] bits to clear the selected interrupt
     pending bits */
     *(__IO uint8_t *)RCC_CIR_BYTE3_ADDRESS = RCC_IT;
}

RCC_DEF void HSI_Init(void)
{   
    __IO uint32_t HSIStatus = 0;
    RCC->CR |= ((uint32_t)RCC_CR_HSION);
    do
    {
        HSIStatus = RCC->CR & RCC_CR_HSIRDY;
        StartUpCounter++;
    }while((HSIStatus == 0) && (StartUpCounter != HSEStartUp_TimeOut));
    //flash access delay 48MHz < SYSCLOCK <=72MHz
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;
     //PLL setting
    /* HCLK = SYSTICK */
    RCC->CFGR |= (uint32_t)SYSCLK_NOT_DIVIDED;
    /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)APB2_PCLK2_NOT_DIVIDED;
    /* PCLK1 = HCLK */
    RCC->CFGR |= (uint32_t)APB1_PCLK1_DIVIDED2;
    /* ADC = set div 4 */
    RCC->CFGR |= ADCPRE_PLCK2_DIVIDED4;
    /* PLL ON */
    RCC->CR |= RCC_CR_PLLON;
    /* Wait till PLL is ready */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
        ;
    }
    /* select PLL as system clock source */
    RCC->CFGR |= (uint32_t)SW_PLL_SYSCLOCK;
    /* Wailt til PLL is used as system clock source */
    while((RCC->CFGR & (uint32_t)RCC_SWS_MASK) != ((uint32_t)0x08))
    {
        ;
    }
}

RCC_DEF void HSE_Init(void)
{
    __IO uint32_t HSEStatus = 0;
    RCC->CR |= ((uint32_t)RCC_CR_HSEON);
    do
    {
        HSEStatus = RCC->CR & RCC_CR_HSERDY;
        StartUpCounter++;
    }while((HSEStatus == 0) && (StartUpCounter != HSEStartUp_TimeOut));
    //flash access delay 48MHz < SYSCLOCK <=72MHz
    FLASH->ACR |= FLASH_ACR_LATENCY_2;
     //PLL setting
    /* HCLK = SYSTICK */
    RCC->CFGR |= (uint32_t)SYSCLK_NOT_DIVIDED;
    /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)APB2_PCLK2_NOT_DIVIDED;
    /* PCLK1 = HCLK */
    RCC->CFGR |= (uint32_t)APB1_PCLK1_DIVIDED2;
    /* ADC = set div 6 */
    RCC->CFGR |= (uint32_t)ADCPRE_PLCK2_DIVIDED6;
    /* PLL configuration : PLLCLK = HSE * 6 = 72MHz */
    RCC->CFGR |= (uint32_t)(RCC_PLLSource_HSE_Div1 | RCC_PLLMul_6);
    /* PLL ON */
    RCC->CR |= RCC_CR_PLLON;
    /* Wait till PLL is ready */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
        ;
    }
    /* select PLL as system clock source */
    RCC->CFGR &= ((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)SW_PLL_SYSCLOCK;
    /* Wailt til PLL is used as system clock source */
    while((RCC->CFGR & (uint32_t)RCC_SWS_MASK) != ((uint32_t)0x08))
    {
        ;
    }
}